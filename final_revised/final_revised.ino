// Jean-Luc Chamaa - PreFab LED Strip Control via Ardunio
#include <LiquidCrystal.h>
#include <ffft.h>
#include <stdio.h>
#define ADC_CHANNEL 0

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13,12,8,7,4,2);
// global Variables for testThree & consolidate
int globaLast=0;
int lastDir=0;
// global variables for the fft implementation
int16_t       capture[FFT_N];    // Audio capture buffer
complex_t     bfly_buff[FFT_N];  // FFT "butterfly" buffer
uint16_t      spectrum[FFT_N/2]; // Spectrum output buffer
volatile byte samplePos = 0;     // Buffer position counter
int party =0;


//global Variables for consolidate/testThree
const int UP 		= 1;
const int DOWN 		= 2;
const int LEFT 		= 3;
const int RIGHT 	= 4;
const int THROUGH	= 5;
const int NONE		= 0;
// global variables for menu orientiation
// Menus are Stacked as Such
/*
Menu 0
- Custom Color 
	- Execute CustomCol()
- Party Mode
	- Execute Party Mode
- Fade Mode
	- Execute Fade Mode
- Strobe Mode
	- Execute Strobe Mode
- Color Settings
	Menu 1
	- Party Mode Colors
		Menu 2
		- Color Scheme 1
		- Color Scheme 2.....
		- Color Scheme N
	- Strobe Colors
		Menu 3
		- Color Scheme 1
		- Color Scheme 2.....
		- Color Scheme N
	- Screen Colors
		Menu 4
		- Color Scheme 1
		- Color Scheme 2.....
		- Color Scheme N

*/
int currentMenu	=	0; // Which menu is the user currently in?

char* menu0[]	={	" Custom Color    ",
					" Party Mode      ",
					" Fade Mode       ",
					" Strobe Mode     ",
					" Settings        "};

char* menu1[]	={	" Party Color     ",
					" Strobe Color    ",
					" Screen Color    "};

char* menu2[]	={	" Lightning       ",
					" White           ",
					" Red             ",
					" Orange          ",
					" Yellow          ",
					" Green           ",
					" Turquoise       ",
					" Blue            ",
					" Purple          ",
					" Pink            "};

char** menuMenu[]	= {menu0,menu1,menu2};
int upDown[]	={0,0,0}; //UpDown for menu 0, 1, and 2 respectively. 0=up, 1= Down
int menuPos[]	={0,0,0};
int menuSize[]	={5,3,10};

int palette[10][3]={	{65 ,200,120},
						{255,255,255},
						{255,0  ,0  },
						{165,30 ,0  }
,						{255,64 ,0  },
						{0  ,255,0  },
						{0  ,255,255},
						{0  ,0  ,255},
						{255,0  ,255},
						{255,0  ,25 }};

int modeCols[3][3]={	{255,255,255}, // Party = White
						{255,255,255}, // Strobe = White
						{65 ,200,120}};// Screen = Lightning


void setup(){
	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
	analogReference(EXTERNAL);
	Serial.begin(9600);
}

void establishContact() {
    while (Serial.available() <= 0) {
        Serial.write('A');   // send a capital A
        delay(300);
    }
}

void sampleAndTransform(){
    while(ADCSRA & _BV(ADIE)); // CALLS ISR UNTIL ADIE IS 0
    fft_input(capture, bfly_buff);   // Samples -> complex #s
    samplePos = 0;                   // Reset sample counter
    fft_execute(bfly_buff);       // Process complex data
    fft_output(bfly_buff, spectrum); // Complex -> spectrum
    //ADCSRA |= _BV(ADIE);             // SETS ADIE TO 1 AND RESUMES ISR 
}

void startTheParty(){
	
}

int partyMode() {
    switch (ADMUX)
    {
        case 0x00:
            startTheParty();
            sampleAndTransform(); // Samples and performs an FFT
            ADMUX=0x01;
            break;
        case 0x01:
            if(analogRead(A1)==100) //TODO: Change this Number!
            return(0);
            ADMUX=0x00;
            break;
        default:
        	return(0);
        	break;
    }
}

int testThree() {
 	// returns 1U 2D 3L 4R 5C 0mistake
 	int ar[3];
 	for(int i=0;i<3;i++)
  	{
		int sensorValue = analogRead(A2);
		ar[i] = sensorValue;
		delay(10);        // delay in between reads for stability  
  	}
  	if(ar[0]==ar[1] && ar[1]==ar[2]){
		if (ar[1]>1020) //exact 1023
			return(4);
		if (ar[1]>509 && ar[1]< 515) //exact 512
			return(1);
		if (ar[1]>253 && ar[1]<259) //exact 256
			return(3);
		if (ar[1]>765 && ar[1]<771) //exact 768
			return(5);
		if (ar[1]<5) //exact 0 
			return(2);
		else 
			return(0);
	} 
  	else
		return(0);
}

int consolidate(){
  	int newval=testThree();
  	if(newval==globaLast){
		globaLast=newval;
		return(0);
  	}
  	else{
		globaLast=newval;
		return(newval);
  	}
}
  
void apply(int r, int g, int b){
	analogWrite(10,r); 
	analogWrite(11,g);
	analogWrite(9,b);
}
void screenApply(int r, int g, int b){
	analogWrite(3, 255-g);
	analogWrite(5, 255-b);
	analogWrite(6, 255-r);

}

void fullfade(){   // fade from red to green
	while(1){

		int r=255;int g=0;int b=0;
		for(int del=0;del<256;del++)
		{

			int wait= analogRead(A3)/20;
			apply(r-del,g+del,b);
			delay(wait);
			if(consolidate()==LEFT) return;
			lcd.setCursor(14,0);
			lcd.print(wait);
			lcd.print("  ");
		}
		// fade from green to blue
		r=0;g=255;b=0;
		for(int del=0;del<256;del++)
		{	
			int wait= analogRead(A3)/20;
			apply(r,g-del,b+del);
			delay(wait);
			if(consolidate()==LEFT) return;
			lcd.setCursor(14,0);
			lcd.print(wait);
			lcd.print("  ");
		}
		// fade from blue to red
		r=0;g=0;b=255;
		for(int del=0;del<256;del++)
		{
			int wait= analogRead(A3)/20;
			apply(r+del,g,b-del);
			delay(wait);
			if(consolidate()==LEFT) return;
			lcd.setCursor(14,0);
			lcd.print(wait);
			lcd.print("  ");
		}
	}
}

void customCol(){
	lcd.setCursor(0,0);
	lcd.print(" RED GREEN BLUE ");
	int rpot = 0;
	int gpot = 0;
	int bpot = 0;
	bool clapper=false;
	while(1){
		if(consolidate()==LEFT) return;
		if(consolidate()==DOWN) clapper=true; //enter clap mode by pressing down
		if(rpot!=analogRead(A3)){
			lcd.setCursor(1,1);
			lcd.print(rpot*10/102);
			lcd.print(" ");
			rpot=analogRead(A3);
		}
		if(gpot!=analogRead(A4)){
			gpot=analogRead(A4);
			lcd.setCursor(6,1);
			lcd.print(gpot*10/102);
			lcd.print(" ");
		}
		if(bpot!=analogRead(A5)){
			bpot=analogRead(A5);
			lcd.setCursor(12,1);
			lcd.print(bpot*10/102);
			lcd.print(" ");
		}
		apply(rpot/4,gpot/4,bpot/4);
		if(clapper){
			boolean lightState = false;
			int relay = 13;
			int claps = 0;
			long detectionSpanInitial = 0;
			long detectionSpan = 0;
			pinMode(A1, INPUT);
			pinMode(relay, OUTPUT);
			while(analogRead(A5)!=0){ //exit clap mode by turning red to 0
				int sensorState = digitalRead(A1);
				if (sensorState == 1){
					if (claps == 0){
						detectionSpanInitial = detectionSpan = millis();
						claps++;
					}
					else if (claps > 0 && millis()-detectionSpan >= 50)
					{
					  detectionSpan = millis();
					  claps++;
					}
				}
				if (millis()-detectionSpanInitial >= 400){
					if (claps == 2){
						if (!lightState){
							lightState = true;
							digitalWrite(relay, HIGH);
							apply(rpot/4,gpot/4,bpot/4);
						}
					    else if (lightState){
							lightState = false;
							digitalWrite(relay, LOW);
							apply(0,0,0);
					    }
					}
					claps = 0;
				}
			}
			clapper=false;
		}
	}
}

void strobeMode(){
        
	unsigned long previousMillis = millis();
        boolean paused=false;
	while(1){
		int delayTime=analogRead(A3);
		lcd.setCursor(6,0);
		lcd.print(60000/(delayTime+100));
		lcd.print("  ");
		if(consolidate()==LEFT) return;
		if(consolidate()==THROUGH) paused=!paused;
		unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= delayTime && !paused) {
                  // save the last time you blinked the LED
                  previousMillis = currentMillis;
		  apply(modeCols[1][0],modeCols[1][1],modeCols[1][2]);
                  delay(100);
                  apply(0,0,0);
                }


      }
}
void loop(){ //Menu navigation - pushes to the functions.
	if(millis()<100){delay(100);} // don't jump the gun!
	screenApply(modeCols[2][0],modeCols[2][1],modeCols[2][2]);
	int cons=consolidate();
	switch(cons){ // Choose what to do with an input/ no input
		case NONE: //No movement(Display the screen)
			lcd.setCursor(0,0);
			lcd.print((menuMenu[currentMenu])[menuPos[currentMenu]-upDown[currentMenu]]);
			lcd.setCursor(0,1);
			lcd.print((menuMenu[currentMenu])[menuPos[currentMenu]-upDown[currentMenu]+1]);
			switch (upDown[currentMenu]) {
				case 0:
					lcd.setCursor(0,0);
					lcd.print("-");
					lcd.setCursor(0,1);
					break;
				case 1:
					lcd.setCursor(0,1);
					lcd.print("-");
					break;
				default:
		  			break;
			}
			break;
			
		case UP:
			switch (upDown[currentMenu]) {
			    case 0://UP
			    	if(menuPos[currentMenu]==0){
			      		break;
			  		}
			      	else{
			      		menuPos[currentMenu]-=1;
			      		break;
			      	}
			    case 1://DOWN
			    	upDown[currentMenu]=0;
			    	menuPos[currentMenu]-=1;
			    	break;
			    default:
			    	break;
			}
			break;

		case DOWN:
			switch (upDown[currentMenu]) {
				    case 1: //DOWN
				    	if(menuPos[currentMenu]==(menuSize[currentMenu]-1)){
				      		break;
				  		}
				      	else{
				      		menuPos[currentMenu]+=1;
				      		break;
				      	}
				    case 0://UP
				    	upDown[currentMenu]=1;
				    	menuPos[currentMenu]+=1;
				    	break;
				    default:
				    	break;
			}
			break;

		case LEFT:
			if(currentMenu!=0){ //Unless in main menu, just go back
				currentMenu-=1; // to the previous menu
			}
			break;

		case RIGHT:
		case THROUGH: // When we select
			switch (currentMenu) {
				case 0: // Inside of Main Menu
			    	switch(menuPos[0]){ // Each of the Main Menu options
			    		case 0:  // Custom Color
		    				delay(500);
		    				lcd.setCursor(0,1);
		    				lcd.print("               ");
		    				customCol();
		    				break;
		    			case 1:
		    				startTheParty();
			    		case 2:  // Fade
		    				delay(500);
		    				lcd.setCursor(0,0);
		    				lcd.print("Speed (0-51):             ");
		    				lcd.setCursor(0,1);
		    				lcd.print("Turn Top Knob");
		    				fullfade();
		    				break;
			    		case 3: // strobe
			    			delay(500);
		    				lcd.setCursor(0,0);
		    				lcd.print("BPM:             ");
		    				lcd.setCursor(0,1);
		    				lcd.print("Turn Top Knob");
		    				strobeMode();
		    				break;
			    		case 4: // Settings option: push forward
			    			currentMenu=1;
			    			break;

			    		default:
			    			break;
			    	}
			    	break;
			    case 1: // Inside Menu 1
			    	currentMenu=2;
			      	break;

				case 2: // Color Options 	
					//the red value of the chosen in the related modeCols
					modeCols[menuPos[1]][0]=palette[menuPos[2]][0];
					modeCols[menuPos[1]][1]=palette[menuPos[2]][1];
					modeCols[menuPos[1]][2]=palette[menuPos[2]][2];
					break;


			    default:
			      break;
			}
			break;

		default:
			break;

}
}




ISR(ADC_vect) { // Audio-sampling interrupt
    if(party==1){
    static const int16_t noiseThreshold = 4;
    int16_t              sample         = ADC; // 0-1023
    capture[samplePos] =((sample > (512-noiseThreshold)) && (sample < (512+noiseThreshold))) ? 0 : sample - 512; // Sign-convert for FFT; -512 to +511 
  if(++samplePos >= FFT_N) ADCSRA &= ~_BV(ADIE); // Buffer full, interrupt off
}
}
