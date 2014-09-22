// Jean-Luc Chamaa - PreFab LED Strip Control via Ardunio
#include <LiquidCrystal.h>
#include <ffft.h>
#define ADC_CHANNEL 0

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,6,5,4,3,2);
// global Variables for testThree & consolidate
int globaLast=0;
int lastDir=0;
// global variables for the fft implementation
int16_t       capture[FFT_N];    // Audio capture buffer
complex_t     bfly_buff[FFT_N];  // FFT "butterfly" buffer
uint16_t      spectrum[FFT_N/2]; // Spectrum output buffer
volatile byte samplePos = 0;     // Buffer position counter
//global Variables for consolidate/testThree
int UP 		= 1;
int DOWN 	= 2;
int LEFT 	= 3;
int RIGHT 	= 4;
int THROUGH	= 5;
int NONE	= 0;
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
int currentMenu	=	2; // Which menu is the user currently in?
int inAMode		=	0; // Is the user in a mode? 0=No , 1=Yes

int menu0Pos	=	0;
char* menu0[]	={	" Custom Color          ",
					" Party Mode              ",
					" Fade Mode               ",
					" Strobe Mode             ",
					" Settings				  "};
int menu0Size	=	5;//The final index + 1 or the number of real items

int menu1Pos	=	0;
char* menu1[]	={	" Party Color      ",
					" Strobe Color     ",
					" Screen Color     "};
int menu1Size	=	3; 

int menu2Pos	=	0;
char* menu2[]	={	" Red",
					" Orange",
					" Yellow",
					" Green",
					" Blue",
					" Purple"};
int menu2Size	=	6;

char** menuMenu[]	= {menu0,menu1,menu2};
int upDown[]	={0,0,0}; //UpDown for menu 0, 1, and 2 respectively. 0=up, 1= Down


void setup(){
	// set up the LCD's number of columns and rows: 
	lcd.begin(16, 2);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
	Serial.begin(9600);
	analogReference(DEFAULT);
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
    // Init ADC free-run mode; f = ( 16MHz/prescaler ) / 13 cycles/conversion 
    ADMUX  = 0x0; // Channel sel, right-adj, use AREF pin
    //ADMUX = 0b00000000
    ADCSRA = 0xEF;
    // ADCSRA = 0b11101111 = 239 = 0xEF
    ADCSRB = 0;                // Free run mode, no high MUX bit
    DIDR0  = 1 << ADC_CHANNEL; // Turn off digital input for ADC pin
}

int testThree() {
 	// returns 1U 2D 3L 4R 5C 0mistake
 	int ar[3];
 	for(int i=0;i<3;i++)
  	{
		int sensorValue = analogRead(A1);
		ar[i] = sensorValue;
		delay(10);        // delay in between reads for stability  
  	}
  	if(ar[0]==ar[1] && ar[1]==ar[2]){

		if (ar[1]==1023)
			return(4);
		if (ar[1]==513)
			return(1);
		if (ar[1]==256)
			return(3);
		if (ar[1]==768)
			return(5);
		if (ar[1]==0)
			return(2);
		else 
			return(-10);
	} 
  	else
		return(1111);
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

void apply(int r, int g, int b){
	analogWrite(9,r); // red transistor base pin @ 9
	analogWrite(10,g); // green transistor base pin @ 10
	analogWrite(11,b); // blue transistor base pin @ 11
}

void fullfade(int wait){   // fade from red to green
	int r=255;int g=0;int b=0;
	for(int del=0;del<256;del++)
	{
		apply(r-del,g+del,b);
		delay(wait);
	}
	// fade from green to blue
	r=0;g=255;b=0;
	for(int del=0;del<256;del++)
	{
		apply(r,g-del,b+del);
		delay(wait);
	}
	// fade from blue to red
	r=0;g=0;b=255;
	for(int del=0;del<256;del++)
	{
		apply(r+del,g,b-del);
		delay(wait);
	}
}

void customCol(){
	int rpot, gpot, bpot;
	rpot=analogRead(A0);
	gpot=analogRead(A1);
	bpot=analogRead(A2);
	apply(rpot/4,gpot/4,bpot/4);
}

void loop(){ //Menu navigation - pushes to the functions.
	/*
	apply(0,0,255);
	int cons=consolidate();
	Switch(cons){ // Choose what to do with an input/ no input
		case 0: //No movement(Display the screen)
			lcd.setCursor(0,0);
			lcd.print((menuMenu[currentMenu])[menu0Pos-upDown[currentMenu]]);
			lcd.setCursor(0,1);
			lcd.print((menuMenu[currentMenu])[menu0Pos-upDown[currentMenu]+1]);
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
		  			lcd.print('error');
		  			break;
			}
		case 1:
	}
*/


int val=analogRead(A2);
Serial.println(val);
delay(40);
// TODO: AREF is making my value fluctuate and act wildly. Kill it by fixing ADMUX!
}




ISR(ADC_vect) { // Audio-sampling interrupt
    if(inAMode==1){
    static const int16_t noiseThreshold = 4;
    int16_t              sample         = ADC; // 0-1023
    capture[samplePos] =((sample > (512-noiseThreshold)) && (sample < (512+noiseThreshold))) ? 0 : sample - 512; // Sign-convert for FFT; -512 to +511 
  if(++samplePos >= FFT_N) ADCSRA &= ~_BV(ADIE); // Buffer full, interrupt off
}
}