#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); //

#define Lamp1 2
#define Lamp2 3
#define Lamp3 4


#define ON 1
#define OFF 0
char val;
String statusLamp1,statusLamp2,statusLamp3;

void setup() {
  pinMode(Lamp1,OUTPUT);digitalWrite (Lamp1,OFF);
  pinMode(Lamp2,OUTPUT);digitalWrite (Lamp2,OFF);
  pinMode(Lamp3,OUTPUT);digitalWrite (Lamp3,OFF);

  mySerial.begin(9600);
  Serial.begin(9600);
}

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); //

#define Lamp1 2
#define Lamp2 3



#define ON 1
#define OFF 0
char val;
String statusLamp1,statusLamp2,statusLamp3;

void setup() {
  pinMode(Lamp1,OUTPUT);digitalWrite (Lamp1,OFF);
  pinMode(Lamp2,OUTPUT);digitalWrite (Lamp2,OFF);
  pinMode(Lamp3,OUTPUT);digitalWrite (Lamp3,OFF);

  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {

if( mySerial.available() >0 ) {
    val = mySerial.read();
    Serial.println(val); 
}

  if( val == '1' ) {
    digitalWrite(Lamp1,ON); statusLamp1="1"; }
  else if( val == '2' ) {
    digitalWrite(Lamp2,ON); statusLamp2="2"; }
  else if( val == '3' ) {
    digitalWrite(Lamp3,ON); statusLamp3="3"; }
 {
    digitalWrite(Lamp1,ON); statusLamp1="1"; 
    digitalWrite(Lamp2,ON); statusLamp2="2"; 
    digitalWrite(Lamp3,ON); statusLamp3="3"; 

 }
 
  else if( val == 'A' ) {
    digitalWrite(Lamp1,OFF); statusLamp1="A"; }
  else if( val == 'B' ) {
    digitalWrite(Lamp2,OFF); statusLamp2="B"; }
  else if( val == 'C' ) {
    digitalWrite(Lamp3,OFF); statusLamp3="C"; }
 {
    digitalWrite(Lamp1,OFF); statusLamp1="A";
    digitalWrite(Lamp2,OFF); statusLamp2="B";
    digitalWrite(Lamp3,OFF); statusLamp3="C";

 }
  
   else if( val == 'S' ){
    
    delay(500);    
    mySerial.println(statusLamp1+statusLamp2+statusLamp3+"J"); //delay(500);
    val=' ';
 }
}
