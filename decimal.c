#include "decconst.h"
void sumdecimal (char *z, char *x, char *y)
{ char sum, carry = 0;
  unsigned int i;
  for (i = 0; i < decsize; ++i)
  { sum = x[i] + y[i] + carry;
    if (sum > 9)
    { sum -= 10;
      carry = 1;
    }
    else
      carry = 0;
    z[i] = sum;
  }
}
void negdecimal (char *x, char *y)
{ decimal unit = {1};
  unsigned int i;
  for (i = 0; i < decsize; ++i)
    x[i] = 9 - y[i];
  sumdecimal (x, x, unit);
}
int cmpdecimal (char *x, char *y)
{ unsigned int i;
  char xv, yv;
  for (i = decsize; i;)
  { xv = x[--i]; yv = y[i];
    if (xv > yv)
      return 1;
    if (xv < yv)
      return -1;
  }
  return 0;
}
int decimalnonz (char *x)
{ unsigned int i;
  for (i = 0; i < decsize;)
    if (x[i++]) return 1;
  return 0;
}
int decimalsign (char *x)
{ if (x[decsize - 1] < 5)
    return +1;
  else return -1;
}
int cmpsdecimal (char *x, char *y)
{ int xs, ys;
  xs = decimalsign (x);
  ys = decimalsign (y);
  if (xs < ys) return -1;
  if (xs > ys) return +1;
  return cmpdecimal (x, y);
}
void cpydecimal (char *x, char *y)
{ unsigned int i;
  for (i = 0; i < decsize; ++i)
    x[i] = y[i];
}
void todecimal (char *x, unsigned int val)
{ unsigned int i;
  for (i = 0; i < decsize; ++i)
  { x[i] = val % 10;
    val /= 10;
  }
}
void prdecimal (char *x, int lzero)
{ unsigned int i; char c;
  extern int putchar (int);
  for (i = decsize; i;)
  { c = x[--i];
    if (c > 0)
      lzero = 1;
    if (lzero || !i)
      putchar (c + 48);
  }
}