/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/

const int sampleWindow = 20; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() 
{
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
   digitalWrite(11, HIGH);
   Serial.begin(9600);
}
double grabBit()
{
   long int startMillis=millis();
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak/10.24);  // convert to volts
   int timeSig=((startMillis/1000)%2);
   if(volts>50){
      digitalWrite(9,255-255*timeSig);//Display RED
      digitalWrite(10,255);
      digitalWrite(12,0+255*timeSig);
   }
   else{
      digitalWrite(9,255); // Display BLACK
      digitalWrite(10,255);
      digitalWrite(12, 255);
   }


   // Serial.println(volts);
   Serial.println(timeSig);
}

void loop() 
{
 grabBit();

}