void setup()
{
	pinMode(13,OUTPUT);
	Serial.begin(9600);
}

void printval(){
	Serial.println(A0);
	delay(10);
}

void loop()
{
printval();	
}