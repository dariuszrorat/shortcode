#include "shortcode.h"

bool execResult;

void setup() {
  Serial.begin(9600);

  Sc.init();
  Sc.add("*00*", printInfo0);
  Sc.add("*01*", printInfo1);
  Sc.add("*02*", printInfo2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Sc.exec("*00*1*2*3#");
  delay(500);
  Sc.exec("*01*5*6*7#");
  delay(500);
  Sc.exec("*02*8*9*10#");
  delay(500);

  execResult = Sc.exec("*03*01#");
  if (!execResult)
  {
    Serial.println("INVALID COMMAND");
  }
  delay(500);
  execResult = Sc.exec("*04*01");
  if (!execResult)
  {
    Serial.println("INVALID COMMAND");
  }
  delay(500);
  execResult = Sc.exec("");
  if (!execResult)
  {
    Serial.println("INVALID COMMAND");
  }
  delay(500);
}

void printInfo0(long par0, long par1, long par2)
{
  String s = String(par0) + " " + String(par1) + " " + String(par2);
  Serial.println(s);
}

void printInfo1(long par0, long par1, long par2)
{
  String s = String(par0) + "-" + String(par1) + "-" + String(par2);
  Serial.println(s);
}

void printInfo2(long par0, long par1, long par2)
{
  String s = String(par0) + "/" + String(par1) + "/" + String(par2);
  Serial.println(s);
}
