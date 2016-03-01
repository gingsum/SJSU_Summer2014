rem
rem -- Make sure you remove stdafx.h if your p3.cpp contains "#include "stdafx.h"
rem -- To compile use "cl p4.cpp" or "cl p4.cpp /clr"
rem
copy key1.h key.h
cl /LD encrypt.cpp
cl p4.cpp encrypt.lib
rem
rem -- To test, try different values and combinations
rem -- test1
rem key1.h values #1 direction = 0; shiftcount = 2; invertcase = 1;
rem
rem -- Simple string
p4 "Hello World" 0
p4 "jGNNQ yQTHF" 1
rem -- Boundary testing
p4 "Abc XYz" 0
p4 "cDE zaB" 1
rem -- Mix alpha and numeric
p4 "CS47 Section 3" 0
p4 "eu 157c 2 kpv fcvc du ocp uau 3 1730 1845 vt oj 422 dWVV" 1
rem
rem -- End of test1
rem
rem -- Rebuild DLL only for different encryption properties
rem
copy key2.h key.h
cl /LD encrypt.cpp
rem
rem test2
rem key2.h values #1 direction = 1; shiftcount = 5; invertcase = 0;
rem
rem -- Simple string
p4 "Hello World" 0
p4 "Czggj Rjmgy" 1
rem -- Boundary testing
p4 "Abc XYz" 0
p4 "Vwx STu" 1
rem -- Mix alpha and numeric
p4 "XN47 dn 1 ja ocz wzno xgvnn D zqzm ojjf" 1
rem
rem -- End of test2
rem
rem -- Rebuild DLL only for different encryption properties
rem
copy key3.h key.h
cl /LD encrypt.cpp
rem
rem test3
rem key3.h values #1 direction = 0; shiftcount 29; invertcase = 1;
rem
p4 "Abc XYz" 0
p4 "dEF abC" 1
p4 "wKLV FODVV UHDOOB @#$%&!" 1
rem
rem -- End of test3