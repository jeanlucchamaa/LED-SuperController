/*
fht_adc_serial.pde
guest openmusiclabs.com 7.7.14
example sketch for testing the fht library.
it takes in data on ADC0 (Analog0) and processes them
with the fht. the data is sent out over the serial
port at 115.2kb.
*/

#define FHT_N 256 // set to 256 point fht
#define OCTAVE 1 // Setting octave Mode
#define OCT_NORM 1 //Octave Normalization Feature

#include <FHT.h> // include the library
double max=0.0;
double min=255.0;

void setup() {
  Serial.begin(115200); // use the serial port
  // TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(11,HIGH);
}

void loop() {
  while(1) { // reduces jitter
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
    fht_mag_octave(); // take the output of the fht
    sei();
    double reading_two=((fht_oct_out[2]+fht_oct_out[1])/2);
    if (reading_two>max){max=reading_two;}
    if (reading_two<min){min=reading_two;}
    double range=max-min;
    double ratio=((reading_two-min)/range);
    if(ratio>.85){analogWrite(9,0); delay(10);}
    else{analogWrite(9,255);}
    int x=analogRead(A1);
    Serial.println(x);
/*
    Serial.print("min: "); Serial.print(min);
    Serial.print("  max: "); Serial.print(max);
    Serial.print("  ratio: "); Serial.print(ratio);
    Serial.print("  Range:  "); Serial.println(range);
*/
}
}
