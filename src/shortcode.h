#ifndef SHORTCODE_H
#define SHORTCODE_H

#include "Arduino.h"   

#define MAX_CALLBACKS (30)

typedef struct
{
  void (*pfn)(long, long, long);
  String command;
} Callback;

class Shortcode
{
  public:
    void init(void);
    unsigned int add(String, void ( *) (long, long, long));
    bool exec(String code);
};

String trim_all(String s);
String get_param(String data, char separator, int index);


static Shortcode Sc;

#endif
