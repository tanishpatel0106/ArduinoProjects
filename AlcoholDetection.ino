const int AOUTPin = A0;
const int DOUTPin = 12;
const int relay1 = 7;
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 6;
int threshold_value = 100;
const int front_left = 13;
const int front_brake = 12;
const int front_right = 5;
const int rear_left = 2;
const int rear_brake = 3;
const int rear_right = 4;

void setup(){
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(relay1, OUTPUT);
    pinMode(AOUTPin, INPUT);
    pinMode(front_left, OUTPUT);
    pinMode(front_right, OUTPUT);
    pinMode(front_brake, OUTPUT);
    pinMode(rear_left, OUTPUT);
    pinMode(rear_right, OUTPUT);
    pinMode(rear_brake, OUTPUT);
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
        digitalWrite(front_left, HIGH);
        digitalWrite(rear_left, HIGH);
        delay(100);
        digitalWrite(front_left, LOW);
        digitalWrite(rear_left, LOW);
        delay(100);
    }
}

void parkCar(){
    leftIndicator();
    digitalWrite(front_left, HIGH);
    digitalWrite(rear_left, HIGH);
    digitalWrite(front_brake, HIGH);
    digitalWrite(rear_brake, HIGH);
    digitalWrite(relay1, HIGH);
    analogWrite(in1, 85);
    digitalWrite(in2, LOW);
    analogWrite(in3, 90);
    digitalWrite(in4, LOW);
    delay(1000);
    analogWrite(in1, 85);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(300);
    analogWrite(in1, 85);
    digitalWrite(in2, LOW);
    analogWrite(in3, 90);
    digitalWrite(in4, LOW);
    delay(1000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(in3, 90);
    digitalWrite(in4, LOW);
    delay(300);
    analogWrite(in1, 85);
    digitalWrite(in2, LOW);
    analogWrite(in3, 90);
    digitalWrite(in4, LOW);
    delay(1000);
    speedControl();
    digitalWrite(rear_right, HIGH);
    digitalWrite(front_right, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(1000);
}

void loop(){
    int sensorValue = analogRead(AOUTPin);
    if(sensorValue>threshold_value){
        Serial.println("Alcohol detected - Car Stopping");
        parkCar();
        digitalWrite(relay1, LOW);
    }
    else{
        digitalWrite(relay1, HIGH);
        digitalWrite(front_left, LOW);
        digitalWrite(rear_left, LOW);
        digitalWrite(front_brake, LOW);
        digitalWrite(rear_brake, LOW);
        digitalWrite(rear_right, LOW);
        digitalWrite(front_right, LOW);
        analogWrite(in1, 85);
        digitalWrite(in2, LOW);
        analogWrite(in3, 90);
        digitalWrite(in4, LOW);
    }
    Serial.println(sensorValue);
    delay(1000);
}
