#include "shortcode.h"

unsigned int cindex;
unsigned int ccounter;

Callback callbacks[MAX_CALLBACKS];

void Shortcode::init(void)
{
  ccounter = 0;
  cindex = 0;
}

unsigned int Shortcode::add(String command, void (*fn)(long param1, long param2, long param3))
{
  if (cindex < MAX_CALLBACKS)
  {
    callbacks[cindex].pfn = fn;
    callbacks[cindex].command = command;
    cindex++;
  }

  return cindex;
}


bool Shortcode::exec(String code)
{
  int len = code.length();
  if (len == 0) return false;
  if ((len > 0) && (code[len - 1] != '#')) return false;
    
  String cmd = code.substring(0, 4);
  String params = code.substring(4, code.length() - 1);
  String param0 = trim_all(get_param(params, '*', 0));
  String param1 = trim_all(get_param(params, '*', 1));
  String param2 = trim_all(get_param(params, '*', 2));
  long par0 = param0.toInt();
  long par1 = param1.toInt();
  long par2 = param2.toInt();

  unsigned short i;
  for (i = 0; i < cindex; i++)
  {
    if (callbacks[i].command == cmd)
    {
      (*callbacks[i].pfn)(par0, par1, par2);
      return true;
    }
  }
  return false;
}

String trim_all(String s)
{
  String result = "";
  for (int i = 0; i < s.length(); i++)
  {
    if ((s[i] != ' ') && (s[i] != '#') && (s[i] != '*'))
    {
      result += s[i];
    }
  }
  return result;
}

String get_param(String data, char separator, int index)
{
  int maxIndex = data.length() - 1;
  int j = 0;
  String chunkVal = "";

  for (int i = 0; i <= maxIndex && j <= index; i++)
  {
    chunkVal.concat(data[i]);

    if (data[i] == separator)
    {
      j++;

      if (j > index)
      {
        chunkVal.trim();
        return chunkVal;
      }

      chunkVal = "";
    }
    else if ((i == maxIndex) && (j < index)) {
      chunkVal = "";
      return chunkVal;
    }
  }
}
