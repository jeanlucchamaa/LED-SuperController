const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
byte red; byte green; byte blue; // bytes are 8-bit values, 0-255 unsigned
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
	red=50; green=50; blue=50; // visual test of succesful program launch


}

void recieveCommand() {
	static byte ndx = 0;
	char endMarker = '\r'; //carriage return marks end of serial line
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
			if(receivedChars[3]!=0){ // check final byte about whether to accept or ignore incoming data
				red=receivedChars[0]; // if byte!=0, set values to recieved data
				green=receivedChars[1];
				blue=receivedChars[2];
			}
			else{
				red=analogRead(A4)/4; // if byte ==0, set tactile numbers
				green=analogRead(A1)/4;
				blue=analogRead(A0)/4; 
			}
		}
	}
	newData=false;
}


void loop(){
	while(!Serial.available()){ // Until something is sent from Serial
		red=analogRead(A4)/4; //  set tactile numbers
		green=analogRead(A1)/4;
		blue=analogRead(A0)/4; 
		apply(red, green,blue); // apply tactile numbers	
	}
	// A SERIAL COMMAND HAS BEEN RECIEVED!
	while(true){
		recieveCommand(); // recieve values and set numbers
		apply(red,green,blue); // apply the set numbers
	}

	
}
// TODO Create ISR's to handle changes in the pots