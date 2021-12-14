#define FORCE_SENSOR_PIN1 A0
#define FORCE_SENSOR_PIN2 A1

#define LED 6
#define Buzzer 5

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(Buzzer,OUTPUT);
}

void loop() 
{
  int analogReading1 = analogRead(FORCE_SENSOR_PIN1);

  Serial.print("Force sensor 1 reading = ");
  Serial.print(analogReading1); // print the raw analog reading

  if (analogReading1 < 10)       // from 0 to 9
    Serial.println(" -> no pressure");
  else if (analogReading1 < 200) // from 10 to 199
    Serial.println(" -> light touch");
  else if (analogReading1 < 500) // from 200 to 499
    Serial.println(" -> light squeeze");
  else if (analogReading1 < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(500);

  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);

  Serial.print("Force sensor 2 reading = ");
  Serial.print(analogReading2); // print the raw analog reading

  if (analogReading2 < 10)       // from 0 to 9
    Serial.println(" -> no pressure");
  else if (analogReading2 < 200) // from 10 to 199
    Serial.println(" -> light touch");
  else if (analogReading2 < 500) // from 200 to 499
    Serial.println(" -> light squeeze");
  else if (analogReading2 < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(500);

  if(analogReading1 > 800)
  {
    Serial.print("Baby is on the Seat");
    if(analogReading2 > 800)
    {
      Serial.print("The Driver is on seat");
      digitalWrite(LED,HIGH);
      delay (1000);
      digitalWrite(LED,LOW);
    }
    else if(analogReading2 < 700)
    {
      Serial.print("The Driver is not on seat");
      digitalWrite(Buzzer,HIGH);
      digitalWrite(LED,HIGH);
      delay (10000);
      digitalWrite(Buzzer,LOW);
      digitalWrite(LED,LOW);
    }
  }

  else
  {
    Serial.print("Baby is not on seat");
    Serial.print("System is not activated");
  }
}