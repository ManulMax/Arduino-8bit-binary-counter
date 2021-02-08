int counterVal=0;
int x,y,i;
int pins[] = {2, 3, 4, 5, 6, 9, 10, 11};


void setup()
{
  pinMode(A1,INPUT);
  for(i=0;i<8;i++){
    pinMode(pins[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  x=analogRead(A1); //A1 resistor for counter value
  
  counterVal = x/4;
  Serial.print("Counter Value ");
  Serial.println(counterVal);
  
  dispBinary(counterVal);
  delay(500);
  
}

void dispBinary(byte n)
{
  for (byte i = 0; i < 8; i++) {
    digitalWrite(pins[i], n & 1);
    n /= 2;
  }
}
