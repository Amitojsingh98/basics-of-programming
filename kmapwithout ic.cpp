#include <Arduino.h>
//Declaring all variables as integers
int Z=0,Y=0,X=0,W=0;
int A,B,C,D;
int a,b,c,d,e,f,g;
//Code released under GNU GPL.  Free to use for anything.

void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);
}
void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    

}
void loop()
{

A=(!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&!X&&!Y&&Z) || (!W&&X&&Y&&!Z);
B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
W=A;
X=B;
Y=C;
Z=D;
a = (!Z&&!Y&&!X&&W) || (!Z&&Y&&!X&&!W);
b = (!Z&&Y&&!X&&W) || (!Z&&Y&&X&&!W);
c = (!Z&&!Y&&X&&!W);
d = (!Z&&Y&&!X&&!W) || (!Z&&Y&&X&&W) || (!Y&&!X&&W);
e = (!Z&&W) || (!Y&&!X&&W) || (!Z&&Y&&!X);
f = (!Z&&X&&W) || (!Z&&!Y&&W) || (!Z&&!Y&&X);
g = (!Z&&!Y&&!X) || (!Z&&Y&&X&&W);
sevenseg(a,b,c,d,e,f,g);
delay(1000);


}
