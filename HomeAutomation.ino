#include <IRremote.h>

int IRpin = 8;
IRrecv irrecv(IRpin);
decode_results results;

int Relay1 = 12;
int Relay2 = 11;
int Relay3 = 10;
int Relay4 = 9;
int R1Status = 1;
int R2Status = 1;
int R3Status = 1;
int R4Status = 1;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the receiver

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay1, HIGH); //Turn off Relay
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, HIGH);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value);
    delay(10);
    irrecv.resume(); //Receive the next value

    if (results.value == 33435855)
    {
      R1Status = digitalRead(Relay1);
      if (R1Status == 1)
        digitalWrite(Relay1, LOW); //Turn on Relay
      else if (R1Status == 0)
        digitalWrite(Relay1, HIGH); //Turn off Relay
      delay(100);
    }
    if (results.value == 33423615)
    {
      R2Status = digitalRead(Relay2);
      if (R2Status == 1)
        digitalWrite(Relay2, LOW);
      else if (R2Status == 0)
        digitalWrite(Relay2, HIGH);
      delay(100);
    }
    if (results.value == 33484815)
    {
      R3Status = digitalRead(Relay3);
      if (R3Status == 1)
        digitalWrite(Relay3, LOW);
      else if (R3Status == 0)
        digitalWrite(Relay3, HIGH);
      delay(100);
    }
    if (results.value == 33472575)
    {
      R4Status = digitalRead(Relay4);
      if (R4Status == 1)
        digitalWrite(Relay4, LOW);
      else if (R4Status == 0)
        digitalWrite(Relay4, HIGH);
      delay(100);
    }
  }
}
