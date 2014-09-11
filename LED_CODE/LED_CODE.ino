// Jean-Luc Chamaa - PreFab LED Strip Control via Ardunio
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 7, 13, 4, 12, 2);
 int globaLast=0;
 int lastDir=0;

void setup()
{
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("FINLAND!!!");
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    Serial.begin(9600);
    
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
  if(ar[0]==ar[1] && ar[1]==ar[2])
  {
    if (ar[1]==1023)
    {return(4);}
    if (ar[1]==513)
    {return(1);}
    if (ar[1]==256)
    {return(3);}
    if (ar[1]==768)
    {return(5);}
    if (ar[1]==0)
    {return(2);}
    else{
      return(-10);
    }
  } 
  else{
    return(1111);
  }
}

int consolidate()
{
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

int printdir(){
  int x=consolidate();
  if(x!=0 && x!=1111){
  Serial.print("Button Value: "); 
  Serial.println(x);
  lastDir=x;
    }
  else{return(115);}
  
}
  
void apply(int r, int g, int b)
{
    analogWrite(9,r); // red transistor base pin @ 9
    analogWrite(10,g); // green transistor base pin @ 10
    analogWrite(11,b); // blue transistor base pin @ 11
}


void fullfade(int wait)
{   // fade from red to green
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


void customCol()
{
    int rpot, gpot, bpot;
    rpot=analogRead(A0);
    gpot=analogRead(A1);
    bpot=analogRead(A2);
    apply(rpot/4,gpot/4,bpot/4);

}




void loop()
{
    printdir();
    switch (globaLast) {
    case 1:
        {apply(255,255,0);}
      break;
    case 2:
        {apply(255,0,255);}
        break;
    case 3:
       {apply(0,255,255);}
        break;
    case 4:
       {apply(0,0,255);}
       break;
    case 5:
       {apply(0,255,0);}
        break;
    default: 
    {apply(0,100,255);}
  };
lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 lcd.print(millis()/1000);

}
