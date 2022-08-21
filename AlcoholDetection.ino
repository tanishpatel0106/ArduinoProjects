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

void speedControl(){
    int a = analogRead(in1);
    for(int i=a; i>=0; i--){
        analogWrite(in1, i);
        analogWrite(in3, i);
        delay(10);
    }
}

void leftIndicator(){
    for(int i=0; i<5; i++){
        digitalWrite(ledPin1, HIGH);
        delay(100);
        digitalWrite(ledPin1, LOW);
        delay(100);
    }
}

void parkCar(){
    leftIndicator();
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    analogWrite(in1, 100);
    digitalWrite(in2, LOW);
    analogWrite(in3, 100);
    digitalWrite(in4, LOW);
    Serial.out.println("Parking");
    delay(1000);
    analogWrite(in1, 100);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.out.println("Left Turn");
    delay(1000);
    analogWrite(in1, 100);
    digitalWrite(in2, LOW);
    analogWrite(in3, 100);
    digitalWrite(in4, LOW);
    Serial.out.println("Moving Forward");
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(in3, 100);
    digitalWrite(in4, LOW);
    Serial.out.println("Right Turn");
    delay(1000);
    analogWrite(in1, 100);
    digitalWrite(in2, LOW);
    analogWrite(in3, 100);
    digitalWrite(in4, LOW);
    Serial.out.println("Moving Forward");
    delay(1000);
    speedControl();
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.out.println("Parked");
    digitalWrite(ledPin3, HIGH);
    delay(1000);
}

void loop(){
    int sensorValue = analogRead(AOUTPin);
    if(sensorValue>threshold_value){
        Serial.println("Alcohol detected - Car Stopping");
        park();
        digitalWrite(relay1, LOW);  
    }
    else{
        digitalWrite(relay1, HIGH);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    Serial.println(sensorValue);
    delay(1000);
}
