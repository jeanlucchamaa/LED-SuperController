/*
fht_adc_serial.pde
guest openmusiclabs.com 7.7.14
example sketch for testing the fht library.
it takes in data on ADC0 (Analin0) and processes them
with the fht. the data is sent out over the serial
port at 115.2kb.
*/

#define LIN_OUT8 1 // use the lin output function
#define FHT_N 256 // set to 256 point fht
#define SCALE 256
  int total[100];
  int timeCounter=0;
#include <FHT.h> // include the library

void setup() {
  Serial.begin(115200); // use the serial port
  // TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0

}
void resetTotal(){
for(int i=0;i<100;i++){total[i]=0;}
  timeCounter=0;
}
void addition(int total[],uint8_t fht_lin_out8[]){
  for(int i=0;i<100;i++){
    int conv= (int) fht_lin_out8[i];
    total[i]+=conv;
  }
}

void loop() {
  resetTotal();
  while(timeCounter<=100) { // reduces jitter
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while(!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_lin8(); // take the output of the fht
    sei();
    addition(total,fht_lin_out8);
    timeCounter++;
  }
  for(int i=0;i<100;i++){
    Serial.print(total[i]/timeCounter);
    Serial.print("|");
  }
  Serial.println("Start sound in 5");
  delay(5000);
  resetTotal();

while(timeCounter<=100) { // reduces jitter
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while(!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_lin8(); // take the output of the fht
    sei();
    addition(total,fht_lin_out8);
    timeCounter++;
}    
for(int i=0;i<100;i++){
    Serial.print(total[i]/timeCounter);
    Serial.print("|");
  }

  Serial.print("\nEND EXPERIMENT\n");
  delay(15000);


    
}
