#include "api.h"
/*
void printCentered(int line, std::string str, int len = 41)
{
  char formattedStr[len];

  for (int i=0; i<str.length(); ++i)
  {
    formattedStr[i] = str.at(i);
  }
  pros::lcd::print(0, formattedStr);
}

void printCenteredButton(int line, std::string left, std::string middle, std::string right, int len = 41)
{
  char formattedStr[len];

  int totalLength = left.length() + middle.length() + right.length();
  if(totalLength >= len-6)
  {
    if(totalLength == len)
    {
      std::string comb = left + middle + right;
      for (int i=0; i<len; i++)
      {
        formattedStr[i] = comb.at(i);
      }
    }
    else
    {
      std::string comb = "[" + left + "][" + middle + "][" + right + "]";
      for (int i=0; i<len; i++)
      {
        formattedStr[i] = comb.at(i);
      }
    }
  }
  else
  {
    int spacesEach = (len - totalLength - 6) / 5;
    std::string comb = "[" + left + "][" + middle + "][" + right + "]";
    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += left;

    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += "]";

    for (int i=0; i<spacesEach; i++)
    {
      comb += " ";
    }

    comb += "[";

    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += middle;

    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += "]";

    for (int i=0; i<spacesEach; i++)
    {
      comb += " ";
    }

    comb += "[";

    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += right;

    for (int i=0; i<spacesEach/2; i++)
    {
      comb += " ";
    }

    comb += "]";

    for (int i=0; i<comb.length(); i++)
    {
      formattedStr[i] = comb.at(i);
    }
  }
  pros::lcd::print(0, formattedStr);
}
*/
