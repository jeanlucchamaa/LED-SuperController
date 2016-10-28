const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
byte red; byte green; byte blue; // bytes are 8-bit values, 0-255 unsigned
float fRed=90; float fGreen=90; float fBlue=90;
bool software=false;
boolean newData = false;

void apply(byte r, byte g, byte b){
    analogWrite(9, r);
    analogWrite(11,b);
    analogWrite(3,g);
}


void setup(){

	Serial.begin(38400); //start Serial comm
	pinMode(A0, INPUT); // potentiometer input pins
	pinMode(A1, INPUT);
	pinMode(A4, INPUT);
	pinMode(9, OUTPUT); // PWM output pins
	pinMode(11, OUTPUT);
	pinMode(3, OUTPUT);
	red=0; green=0; blue=0; // visual test of succesful program launch
}

void recieveCommand() {
	static byte ndx = 0;
	char endMarker = '\0'; //carriage return marks end of serial line
	char rc;
	while (Serial.available() > 0 && newData == false) {
		rc = Serial.read(); // reads in one byte from serial buffer
		if (rc != endMarker) { //continue to read in serial data
			receivedChars[ndx] = rc;
			ndx++;
			if (ndx >= numChars) {
				ndx = numChars - 1;
			}
		}
		else {
			receivedChars[ndx] = '\0'; // demarcate the end of OUR string.
			ndx = 0;
			newData = true;
			byte r0=receivedChars[0]-1;
			byte r1=receivedChars[1]-1;
			byte r2=receivedChars[2]-1;
			byte r3=receivedChars[3]-1;
			if(r3!=0){ // check final byte about whether to accept or ignore incoming data
				red=r0; // if byte!=0, set values to recieved data
				green=r1;
				blue=r2;
				software=true;
			}
			else{
				software=false; 
			}
		}
	}
	newData=false;
}

void loop(){
		if(!software){
			int noOfChanges=0;
			delay(2);
			fRed+=(analogRead(A4)/4 - fRed)/4;
			byte redcur=byte(fRed); //assign current Red to 'cur'
			if(redcur!=red){ // if red changed
				red=redcur;  // assign red
				noOfChanges++; // prep for serial change
			}
			delay(2);
			fGreen+=(analogRead(A1)/4 - fGreen)/4;
			byte greencur=byte(fGreen);  //assign current Green to 'cur'
			if(green!=greencur){
				green=greencur;
				noOfChanges++;
			}
			delay(2);
			fBlue+=(analogRead(A0)/4 - fBlue)/4;
			byte bluecur=byte(fBlue);  //assign current Blue to 'cur'
			if(blue!=bluecur){ // if blue changed
				blue=bluecur;  // assign blue
				noOfChanges++;
			}
			if(noOfChanges>0){
				Serial.print(min(red+1,255));
				Serial.print(',');
				Serial.print(min(green+1,255));
				Serial.print(',');
				Serial.print(min(blue+1,255));
				Serial.write('\0');
			}		
		}
		recieveCommand(); // recieve values and set numbers
		apply(red,green,blue); // apply the set numbers
}