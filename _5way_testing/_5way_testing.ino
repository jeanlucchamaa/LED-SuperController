const int globaLast=0;
const int UP=1;
const int DOWN=2;
const int LEFT=3;
const int RIGHT=4;
const int CENTER=5;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
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

int int(){
  printdir x=consolidate();
  if(x!=0 && x!=1111){
  Serial.println(x); 
  return(x);
  }
}

void loop() {
printdir();

}
