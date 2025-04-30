// #include <Servo.h>
// #define Echo A0
// #define Trig A1
// #define motor 10
// #define spoint 103

// char value;
// int distance;
// int Left;
// int Right;
// int L = 0;
// int R = 0;
// int L1 = 0;
// int R1 = 0;

// Servo servo;
// String command;

// void setup() {
//   Serial.begin(9600);
//   pinMode(Trig, OUTPUT);
//   pinMode(Echo, INPUT);
//   servo.attach(motor);
// }
// void loop() {
//   Obstacle();
//   Bluetoothcontrol();
//   voicecontrol();
// }
// void Bluetoothcontrol() {
  
//  delay(10);
//  while(Serial.available()) {
//   command = "";  
//   command = Serial.readString();
  
//     Serial.print(command);
// }
//   if(command == "move forward"){
//     forward();
//   }else if(command == "move backward"){
//     backward();
//   }else if(command == "turn left"){
//     left();
//   }else if(command == "turn right"){
//     right();
//   }else if(command == "stop") {
//     Stop();
//  }
//   command = "";
// }

// void Obstacle() {
//   distance = ultrasonic();
//   if (distance <= 12) {
//     Stop();
//     backward();
//     delay(100);
//     Stop();
//     L = leftsee();
//     servo.write(spoint);
//     delay(800);
//     R = rightsee();
//     servo.write(spoint);
//     if (L < R) {
//       right();
//       delay(500);
//       Stop();
//       delay(200);
//     } else if (L > R) {
//       left();
//       delay(500);
//       Stop();
//       delay(200);
//     }
//   } else {
//     forward();
//   }
// }
// void voicecontrol() {
//   if (Serial.available() > 0) {
//     value = Serial.read();
//     Serial.println(value);
//     if (value == '^') {
//       forward();
//     } else if (value == '-') {
//       backward();
//     } else if (value == '<') {
//       L = leftsee();
//       servo.write(spoint);
//       if (L >= 10 ) {
//         left();
//         delay(500);
//         Stop();
//       } else if (L < 10) {
//         Stop();
//       }
//     } else if (value == '>') {
//       R = rightsee();
//       servo.write(spoint);
//       if (R >= 10 ) {
//         right();
//         delay(500);
//         Stop();
//       } else if (R < 10) {
//         Stop();
//       }
//     } else if (value == '*') {
//       Stop();
//     }
//   }
// }
// // Ultrasonic sensor distance reading function
// int ultrasonic() {
//   digitalWrite(Trig, LOW);
//   delayMicroseconds(4);
//   digitalWrite(Trig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(Trig, LOW);
//   long t = pulseIn(Echo, HIGH);
//   long cm = t / 29 / 2; 
//   return cm;
// }

// int rightsee() {
//   servo.write(20);
//   delay(800);
//   Left = ultrasonic();
//   return Left;
// }
// int leftsee() {
//   servo.write(180);
//   delay(800);
//   Right = ultrasonic();
//   return Right;
// }

// void forward() {

// digitalWrite(13,HIGH); 
// digitalWrite(12,LOW); 
// digitalWrite(11,HIGH); 
// digitalWrite(10,LOW); 
  
// }

// void backward() {
  
//  digitalWrite(13,LOW); 
// digitalWrite(12,HIGH); 
// digitalWrite(11,LOW); 
// digitalWrite(10,HIGH); 
// }

// void right() {

// digitalWrite(13,LOW); 
// digitalWrite(12,HIGH); 
// digitalWrite(11,HIGH); 
// digitalWrite(10,LOW); 
// }

// void left() {

// digitalWrite(13,HIGH);
// digitalWrite(12,LOW); 
// digitalWrite(11,LOW); 
// digitalWrite(10,HIGH);
// }

// void Stop() {
// digitalWrite(13,LOW); 
// digitalWrite(12,LOW); 
// digitalWrite(11,LOW); 
// digitalWrite(10,LOW); 

// }


#include <Servo.h>
#define Echo A0
#define Trig A1
#define motor 10
#define spoint 103

String value;
int distance;

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  servo.attach(motor);
  servo.write(spoint); 
}

void loop() {
  voicecontrol();
}

void voicecontrol() {
delay(10);
 while(Serial.available()) {
  value = "";  
  value = Serial.readString();
  Serial.print(value);
    switch (value) {
      case 'move forward': 
        if (isPathClear()) {
          forward();
        } else {
          Stop();
        }
        break;

      case 'move backward': 
        if (isPathClear()) {
          backward();
        } else {
          Stop();
        }
        break;

      case 'turn left': 
        if (isPathClear()) {
          left();
          delay(500); 
          Stop();
        } else {
          Stop();
        }
        break;

      case 'turn right':
        if (isPathClear()) {
          right();
          delay(500); 
          Stop();
        } else {
          Stop();
        }
        break;

      case '*': 
        Stop();
        break;

      default:
        Stop();
        break;
    }
  }
}


bool isPathClear() {
  distance = ultrasonic();
  return distance > 12; 

int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH, 30000); 
  if (t == 0) return 1000; 
  long cm = t / 29 / 2;
  return cm;
}

// Motor control functions
void forward() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void backward() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void right() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void left() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}

void Stop() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

