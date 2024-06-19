The is the decimal calculation library for the C programming language written
by Jan Mleczko. This package should contain these files:
- DECIMAL.C, original source code of the library;
- DECIMAL.H, library header file,
- DECCONST.H, definitions shared between DECIMAL.C & DECIMAL.H;
- DECIMAL.O, library ELF object code, compiled using the TinyCC compiler;
- LICENSE.TXT, the license of this library;
- README.TXT, the file you're reading right now.
To use this library in your program, insert such directive at begin of it:
  #include "decimal.h"
When compiling, link it with the object code file:
  tcc program.c decimal.o
Note that you may need to recompile the library into proper format, like COFF.
