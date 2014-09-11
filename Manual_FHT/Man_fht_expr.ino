#define LOG_OUT 1 // use the lin output function
#define FHT_N 256 // set to 256 point fht
#include <FHT.h> // include the library
void doAnFHT(){
	cli();
  	ADCSRA = 0xe5; // set the adc to free running mode
  	ADMUX = 0x40; // use adc0
  	DIDR0 = 0x01; // turn off the digital input for adc0
  	for (int i = 0 ; i < 2*FHT_N ; i++) { // save 256 samples
      while(!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      fht_input[i] = k;
      if(i%2==1){fht_input[i] = 0;}
	}
	fht_window();fht_reorder();fht_run();fht_mag_log();
	sei();
	for(int i=0;i<100;i++){
    Serial.print(fht_mag_log[i]);
    Serial.print("|");
	}
}



void setup()
{
	Serial.begin(115200);
}

void loop()
{
doAnFHT()	
}