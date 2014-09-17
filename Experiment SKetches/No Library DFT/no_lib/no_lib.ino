double pi=3.14159265;
int index=1;
void setup(){
	Serial.begin(115200);
	ADCSRA = 0xe5; // set the adc to free running mode
  	ADMUX = 0x40; // use adc0
  	DIDR0 = 0x01; // turn off the digital input for adc0

}

void loop(){
		Serial.println("Start");
		delay(3000);
		Serial.println(index);
		cli();
  		int sample[1024]={0};
    	for (int i = 0 ; i < 1024 ; i++) { // save 256 samples
      		while(!(ADCSRA & 0x10)); // wait for adc to be ready
      		ADCSRA = 0xf5; // restart adc
      		byte m = ADCL; // fetch adc data
      		byte j = ADCH;
      		int k = (j << 8) | m; // form into an int
      		k -= 0x0200; // form into a signed int
      		k <<= 6; // form into a 16b signed int
      		sample[i] = k; // put real data into bins
    	}
    	sei();
		Serial.println("GO!");
		index+=1;
		/*if (index == 1){
			float odftReal[1024]= {0}; 
			float odftRealTemp;
			float odftImg [1024]= {0}; 
			float odftImgTemp; 
			float mag[1024]={0};
			int n,k;
			for (int m = 0; m <= 1024; m++){
				odftRealTemp = 0;
				odftImgTemp = 0;
				Serial.println(m);
				for ( n = 0; n <= 1024; n++){
					odftRealTemp = odftRealTemp+ sample[n]*cos(2*pi*m*n/1024);
					odftImgTemp = odftImgTemp+ sample[n]*sin(2*pi*m*n/1024);
 				}
				odftReal[m] = odftRealTemp;
				odftImg[m] = odftImgTemp;
				mag[m] = sqrt(odftReal[m]*odftReal[m]+odftImg[m]*odftImg[m]);
			}
			index = index +1;
		
			for(int i=0;i<1024;i++){
				Serial.print(mag[i]);
				Serial.print("|");

			}
		}*/
}

