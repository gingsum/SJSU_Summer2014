Steven Ou
7/31/2014
Summer CS 47
001876135
Project 4

This program will encrpyt the regular text to encrypted format according to formats set by direction, 
shiftcount, and invertcase. It will also decrypt the encrypted format in reverse direction according
to the formats set by direction, shiftcount, and invertcase. 

I used p4test1 to debug since the original p4test creates too many lines of output. The easiest 
part in this program was to coming out with the algorithm and writing down the draft assembly
codes. Since p4 is very similar to p3 and p2, I was able to use many similar concepts to save time
on figuring out the correct syntaxes and algorithm formats. The hardest part was when the code works
for half of the word and starts outputting space for the rest after hitting the first space. After 
switching out the invertCase so that it doesn't apply to non alphabet chars, I was able to correctly
convert every letter. Another bug I encounter was that after converting all the letters, there will
sometimes be left overs coming out of the output that doesn't seem to be from my function. I reset
the rest of the dest string to 0 after the last last converted char and was able to output a clean
result. 

The following output is from the p4test.bat file:


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4test


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Make sure you remove stdafx.h if your p3.cpp contains "#include "stdafx.h"

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 To compile use "cl p4.cpp" or "cl p4.cpp /clr"

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>copy k
ey1.h key.h
        1 file(s) copied.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>cl /LD
 encrypt.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

encrypt.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:encrypt.dll
/dll
/implib:encrypt.lib
encrypt.obj
   Creating library encrypt.lib and object encrypt.exp

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>cl p4.
cpp encrypt.lib
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

p4.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:p4.exe
p4.obj
encrypt.lib

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 To test, try different values and combinations

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 test1

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem ke
y1.h values #1 direction = 0; shiftcount = 2; invertcase = 1;

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Simple string

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "He
llo World" 0
Source string = Hello World
Target string = jGNNQ yQTNF
Number of characters converted = 10

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "jG
NNQ yQTHF" 1
Source string = jGNNQ yQTHF
Target string = Hello Worfd
Number of characters converted = 10

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Boundary testing

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "Ab
c XYz" 0
Source string = Abc XYz
Target string = cDE zaB
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "cD
E zaB" 1
Source string = cDE zaB
Target string = Abc XYz
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Mix alpha and numeric

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "CS
47 Section 3" 0
Source string = CS47 Section 3
Target string = eu47 uGEVKQP 3
Number of characters converted = 9

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "eu
 157c 2 kpv fcvc du ocp uau 3 1730 1845 vt oj 422 dWVV" 1
Source string = eu 157c 2 kpv fcvc du ocp uau 3 1730 1845 vt oj 422 dWVV
Target string = CS 157A 2 INT DATA BS MAN SYS 3 1730 1845 TR MH 422 Butt
Number of characters converted = 26

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 End of test1

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Rebuild DLL only for different encryption properties

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>copy k
ey2.h key.h
        1 file(s) copied.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>cl /LD
 encrypt.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

encrypt.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:encrypt.dll
/dll
/implib:encrypt.lib
encrypt.obj
   Creating library encrypt.lib and object encrypt.exp

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem te
st2

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem ke
y2.h values #1 direction = 1; shiftcount = 5; invertcase = 0;

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Simple string

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "He
llo World" 0
Source string = Hello World
Target string = Czggj Rjmgy
Number of characters converted = 10

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "Cz
ggj Rjmgy" 1
Source string = Czggj Rjmgy
Target string = Hello World
Number of characters converted = 10

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Boundary testing

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "Ab
c XYz" 0
Source string = Abc XYz
Target string = Vwx STu
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "Vw
x STu" 1
Source string = Vwx STu
Target string = Abc XYz
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Mix alpha and numeric

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "XN
47 dn 1 ja ocz wzno xgvnn D zqzm ojjf" 1
Source string = XN47 dn 1 ja ocz wzno xgvnn D zqzm ojjf
Target string = CS47 is 1 of the best class I ever took
Number of characters converted = 27

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 End of test2

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 Rebuild DLL only for different encryption properties

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>copy k
ey3.h key.h
        1 file(s) copied.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>cl /LD
 encrypt.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

encrypt.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:encrypt.dll
/dll
/implib:encrypt.lib
encrypt.obj
   Creating library encrypt.lib and object encrypt.exp

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem te
st3

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem ke
y3.h values #1 direction = 0; shiftcount 29; invertcase = 1;

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "Ab
c XYz" 0
Source string = Abc XYz
Target string = dEF abC
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "dE
F abC" 1
Source string = dEF abC
Target string = Abc XYz
Number of characters converted = 6

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>p4 "wK
LV FODVV UHDOOB @#$&!" 1
Source string = wKLV FODVV UHDOOB @#$&!
Target string = This class really @#$&!
Number of characters converted = 15

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>rem --
 End of test3

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p4\p4>