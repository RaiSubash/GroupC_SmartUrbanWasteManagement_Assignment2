#define trigPin 9
#define echoPin 10
#define greenLED 8    
#define yellowLED 3   
#define redLED 2      
#define buzzerPin 5

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  
  if (distance > 20) {  
    digitalWrite(greenLED, HIGH);   
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzerPin, LOW);    
  }
  else if (distance <= 20 && distance > 10) {  
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);   
    digitalWrite(redLED, LOW);
    digitalWrite(buzzerPin, LOW);    
  }
  else if (distance <= 10) {  
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);      
    digitalWrite(buzzerPin, HIGH);     }

  delay(1000);  
}
