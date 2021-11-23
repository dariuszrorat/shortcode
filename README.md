# Arduino shortcode library

This library can be used in any applications with 4x4 keypad to control
any device by Arduino by shortcodes like

```
*00*#
*01*11#
*02*11*22#
*03*11*22*33#
```

Default MAX_CALLBACKS is 30. Change this value in shortcode.h
if you want in this file to suit your needs.

### Example

Serial print demo

```
#include "shortcode.h"

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
```