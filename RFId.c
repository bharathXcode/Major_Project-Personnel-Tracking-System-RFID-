#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int rs = 14, en = 15, d4 = 16, d5 = 17, d6 = 18, d7 = 19;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial Room_1Serial(2, 3);/* (Rx, Tx) */
SoftwareSerial Room_2Serial(4, 5);/* (Rx, Tx) */
SoftwareSerial Room_3Serial(6, 7);/* (Rx, Tx) */
SoftwareSerial Room_4Serial(8, 9);/* (Rx, Tx) */
char CARD_1[]="1500269E9835";
char CARD_2[]="1700A1F593D0"; // INSUFFICIENT BALANCE
char CARD_3[]="1700A204AF1E";
char CARD_4[]="1700A1830D38";
String message=""; 
char ch;
int a=0;
int b=0;
int c=0;
int d=0;
void RFID_CHECKING();
void setup()
{ 
 Serial.begin(9600);
 Room_1Serial.begin(9600);
 Room_2Serial.begin(9600);
 Room_3Serial.begin(9600);
 Room_4Serial.begin(9600);
 lcd.begin(16, 2);
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print("RFID TRACKING");
 lcd.setCursor(0,1);
 lcd.print(" SYSTEM ");
 Serial.println("RFID TRACKING SYSTEM...");
 delay(2000); 
}
void loop()
{
 MONITORING();
 
}
void MONITORING()
{
 ROOM1();
 ROOM2();
 ROOM3();
 ROOM4();
}
void ROOM1()
{
 Room_1Serial.begin(9600);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ROOM1 SCAN YOUR ");
 lcd.setCursor(0,1);
 lcd.print("CARD...... ");
 //Serial.println("ROOM1...");
 delay(10);
 if(Room_1Serial.available()>0)
 {
 message=Room_1Serial.readString();
 int str_len = message.length() + 1;
 char textmessage[12];
 message.toCharArray(textmessage,str_len);
 Serial.begin(9600);
 Serial.println(textmessage);
 textmessage[12]='\0';
 if((textmessage[11]=='5'))
 {
if(a==0)
{
 a=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room1...");
 Serial.println("$Person1 Entry In Room1...#");
 delay(2000); 
 }
 else if(a==1)
 {
 a=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room1...");
 Serial.println("$Person1 Exit From Room1...#");
 delay(2000); 
 } 
 }
 else if((textmessage[11]=='0'))
 { 
 if(b==0) 
 {
 b=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room1...");
 Serial.println("$Person2 Entry In Room1...#");
 delay(2000); 
 }
 else if(b==1)
 { 
 b=0;
 lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Person2 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room1...");
 Serial.println("$Person2 Exit From Room1...#");
 delay(2000);
 }
 }
 
 else if((textmessage[11]=='E'))
 { 
 if(c==0)
 {
 c=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room1...");
 Serial.println("$Person3 Entry In Room1...#");
 delay(2000); 
 }
 else if(c==1)
 {
 c=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room1...");
 Serial.println("$Person3 Exit From Room1...#");
 delay(2000);
 }
 else if((textmessage[11]=='8'))
 { 
 if(d==0)
 { 
 d=1;
 lcd.clear();
 lcd.setCursor(0,0);
lcd.print("Person4 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room1...");
 
 Serial.println("$Person4 Entry In Room1...#");
 delay(2000);
 }
 else if(d==1)
 {
 d=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room1...");
 Serial.println("$Person4 Exit From Room1...#");
 delay(2000);
 
 } 
 }
 
 }
}
void ROOM2()
{
 Room_2Serial.begin(9600);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ROOM2 SCAN YOUR ");
 lcd.setCursor(0,1);
 lcd.print("CARD...... ");
 // Serial.println("ROOM2...");
 delay(10);
 if(Room_2Serial.available()>0)
 {
 message=Room_2Serial.readString();
 int str_len = message.length() + 1;
 char textmessage[12];
 message.toCharArray(textmessage,str_len);
 Serial.println(textmessage);
 textmessage[12]='\0';
if((textmessage[11]=='5'))
 { 
 if(a==0)
 {
 
 a=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room2...");
 Serial.println("$Person1 Entry In Room2...#");
 delay(2000); 
 }
 else if(a==1)
 {
 a=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room2...");
 Serial.println("$Person1 Exit From Room2...#");
 delay(2000); 
 } 
 }
 else if((textmessage[11]=='0'))
 { 
 if(b==0) 
 {
 b=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room2...");
 Serial.println("$Person2 Entry In Room2...#");
 delay(2000); 
 }
 else if(b==1)
{ 
 b=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Exit");
 lcd.setCursor(0,1);
 
 lcd.print("From Room1...");
 Serial.println("$Person2 Exit From Room2...#");
 delay(2000);
 }
 }
 
 else if((textmessage[11]=='E'))
 { 
 if(c==0)
 {
 c=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room2...");
 Serial.println("$Person3 Entry In Room2...#");
 delay(2000); 
 }
 else if(c==1)
 {
 c=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room2...");
 Serial.println("$Person3 Exit From Room2...#");
 delay(2000);
 }
 }
 else if((textmessage[11]=='8'))
 { 
 if(d==0)
{ 
 d=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room2...");
 
 
 Serial.println("$Person4 Entry In Room2...#");
 delay(2000);
 }
 else if(d==1)
 {
 d=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room2...");
 Serial.println("$Person4 Exit From Room2...#");
 delay(2000);
 } 
 }
 }
}
void ROOM3()
{
 Room_3Serial.begin(9600);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ROOM3 SCAN YOUR ");
 lcd.setCursor(0,1);
 lcd.print("CARD...... ");
 // Serial.println("ROOM3...");
 delay(10);
 if(Room_3Serial.available()>0)
 {
 message=Room_3Serial.readString();
 int str_len = message.length() + 1;
 char textmessage[12];
message.toCharArray(textmessage,str_len);
 Serial.println(textmessage);
 textmessage[12]='\0';
 if((textmessage[11]=='5'))
 { 
 if(a==0)
 {
 a=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room3...");
 Serial.println("$Person1 Entry In Room3...#");
 delay(2000); 
 }
 else if(a==1)
 {
 a=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room3...");
 Serial.println("$Person1 Exit From Room3...#");
 delay(2000);
 } 
 }
 else if((textmessage[11]=='0'))
 { 
 if(b==0) 
 {
 b=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room3...");
 Serial.println("$Person2 Entry In Room3...#");
 delay(2000); 
}
 else if(b==1)
 { 
 b=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room3...");
 Serial.println("$Person2 Exit From Room3...#");
 delay(2000);
 }
 }
 else if((textmessage[11]=='E'))
 { 
 if(c==0)
 {
 c=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room3...");
 Serial.println("$Person3 Entry In Room3...#");
 delay(2000); 
 }
 else if(c==1)
 {
 c=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room3...");
 Serial.println("$Person3 Exit From Room3...#");
 delay(2000);
 
 }
 }
 else if((textmessage[11]=='8'))
{ 
 if(d==0)
 { 
 d=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room3...");
 Serial.println("$Person4 Entry In Room3...#");
 delay(2000);
 }
 else if(d==1)
 {
 d=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room3...");
 Serial.println("$Person4 Exit From Room3...#");
 delay(2000);
 
 } 
 }
 }
}
void ROOM4()
{
 Room_4Serial.begin(9600);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ROOM4 SCAN YOUR ");
 lcd.setCursor(0,1);
 lcd.print("CARD...... ");
 // Serial.println("ROOM4...");
 delay(10);
 
 if(Room_4Serial.available()>0)
 {
message=Room_4Serial.readString();
 int str_len = message.length() + 1;
 char textmessage[12];
 message.toCharArray(textmessage,str_len);
 Serial.println(textmessage);
 textmessage[12]='\0';
 if((textmessage[11]=='5'))
 { 
 if(a==0)
 {
 a=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room4...");
 Serial.println("$Person1 Entry In Room4...#");
 delay(2000); 
 }
 else if(a==1)
 {
 a=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person1 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room4...");
 Serial.println("$Person1 Exit From Room4...#");
 delay(2000); 
 } 
 }
 else if((textmessage[11]=='0'))
 { 
 if(b==0) 
 {
 b=1;
 lcd.clear();
 lcd.setCursor(0,0);
 
 lcd.print("Person2 Entry");
 lcd.setCursor(0,1);
lcd.print("In Room4...");
 Serial.println("$Person2 Entry In Room4...#");
 delay(2000); 
 }
 else if(b==1)
 { 
 b=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person2 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room4...");
 Serial.println("$Person2 Exit From Room4...#");
 delay(2000);
 }
 }
 else if((textmessage[11]=='E'))
 { 
 if(c==0)
 {
 c=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room4...");
 Serial.println("$Person3 Entry In Room4...#");
 delay(2000); 
 }
 else if(c==1)
 {
 c=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person3 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room4...");
 Serial.println("$Person3 Exit From Room4...#");
 delay(2000);
 }
}
 else if((textmessage[11]=='8'))
 { 
 if(d==0)
 { 
 d=1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Entry");
 lcd.setCursor(0,1);
 lcd.print("In Room4...");
 Serial.println("$Person4 Entry In Room4...#");
 delay(2000);
 }
 else if(d==1)
 {
 d=0;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Person4 Exit");
 lcd.setCursor(0,1);
 lcd.print("From Room4...");
 Serial.println("$Person4 Exit From Room4...#");
 delay(2000);
 } 
 }
 }
}