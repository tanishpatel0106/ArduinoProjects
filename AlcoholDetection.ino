const int AOUTPin = A0;
const int DOUTPin = 12;
const int relay1 = 7;
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 6;
int threshold_value = 100;
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 5;
  
void setup(){
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(relay1, OUTPUT);
    pinMode(AOUTPin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    Serial.begin(9600);
}

void leftIndicator(){
  for(int i=0; i<=10; i++){
    digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin1, LOW);
    delay(500);
  }
}

int count = 0;

void park(){
  if(count == 0){
        leftIndicator();
        int spd = analogRead(in1);
        digitalWrite(ledPin2, HIGH);
        analogWrite(in1, spd);
        digitalWrite(in2, LOW);
        analogWrite(in3, spd);
        digitalWrite(in4, LOW);
        delay(1000);
        analogWrite(in1, spd);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(400);
        analogWrite(in1, spd);
        digitalWrite(in2, LOW);
        analogWrite(in3, spd);
        digitalWrite(in4, LOW);
        delay(1000);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(in3, spd);
        digitalWrite(in4, LOW);
        delay(600);
        analogWrite(in1, spd);
        digitalWrite(in2, LOW);
        analogWrite(in3, spd);
        digitalWrite(in4, LOW);
        delay(1000);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(5000);
        digitalWrite(ledPin2, LOW);
        count = 1;
  }
  else{
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
}

void startCar(){
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  analogWrite(in1, 200);
  digitalWrite(in2, LOW);
  analogWrite(in3, 200);
  digitalWrite(in4, LOW);
  count = 0;
}

void loop(){
    int sensorValue = analogRead(AOUTPin);
    if(sensorValue<threshold_value){
        digitalWrite(relay1, HIGH);
        startCar();
        Serial.println("Moving Forward ");
    }
    else{
        park();
    }
    Serial.println(sensorValue);
    delay(10);
}
