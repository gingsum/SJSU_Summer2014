Steven Ou
7/23/2014
Summer CS 47
001876135
Project 3

I tested out with multiple batch files. They all passed with no errors or bugs.

Batch File List:
p3test: teacher's default batch file
p3test1: using p3.data1, I added various special case tokens that does not exist in the list to search
p31: this batch contains all the existing search names in p3.data1
p32: this batch contains all the existing search names in p3.data2

The following output is from the results of the batch files in the order listed:

=============================== p3test =======================================


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3test


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem --
 Make sure you comment out "#include "stdafx.h" if you run in command line

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem --
 To compile use "cl p3.cpp" or "cl p3.cpp /clr"

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>cl p3.
cpp /clr
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1
for Microsoft (R) .NET Framework version 4.00.30319.34014
Copyright (C) Microsoft Corporation.  All rights reserved.

p3.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:p3.exe
p3.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem --
 To test, try different values

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #1
 Test existing elements with exact match

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Jon

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Jon
Search token is in the number 5 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 shane

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = shane
Search token is in the number 7 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 TONY

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = TONY
Search token is in the number 10 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #2
 Test case insensitivity

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Chris

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Chris
Search token is in the number 3 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 BryAN

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = BryAN
Search token is in the number 2 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #3
 Test partial search & non-existent elements

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Art

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Art
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 garbage

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = garbage
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #4
 Test list with odd # of names

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 DAVe

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = DAVe
Search token is in the number 6 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Jona

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Jona
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>

=========================== p3test1 =================================


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3test
1

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>cl p3.
cpp /clr
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1
for Microsoft (R) .NET Framework version 4.00.30319.34014
Copyright (C) Microsoft Corporation.  All rights reserved.

p3.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:p3.exe
p3.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 aaa

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = aaa
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 arturo

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = arturo
Search token is in the number 1 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 aaa

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = aaa
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 bryan

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = bryan
Search token is in the number 2 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 bbb

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = bbb
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 chris

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = chris
Search token is in the number 3 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 ccc

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = ccc
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 david

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = david
Search token is in the number 4 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 eee

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = eee
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 jon

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = jon
Search token is in the number 5 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 kkk

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = kkk
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 mark

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = mark
Search token is in the number 6 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 nnn

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = nnn
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 shane

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = shane
Search token is in the number 7 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 sjan

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = sjan
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 simon

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = simon
Search token is in the number 8 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 ttt

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = ttt
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 thomas

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = thomas
Search token is in the number 9 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 tony

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = tony
Search token is in the number 10 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 zzz

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = zzz
Search token is not found.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>

========================= p31 =================================


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p31

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>del p3
.exe

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>del p3
.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>cl p3.
cpp /clr
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1
for Microsoft (R) .NET Framework version 4.00.30319.34014
Copyright (C) Microsoft Corporation.  All rights reserved.

p3.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:p3.exe
p3.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem --
 To test, try different values

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #1
 Test existing elements with exact match

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Arturo

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Arturo
Search token is in the number 1 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Bryan

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Bryan
Search token is in the number 2 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 chris

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = chris
Search token is in the number 3 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 David

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = David
Search token is in the number 4 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Jon

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Jon
Search token is in the number 5 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Mark

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Mark
Search token is in the number 6 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 shane

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = shane
Search token is in the number 7 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 SIMON

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = SIMON
Search token is in the number 8 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 Thomas

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = Thomas
Search token is in the number 9 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data1 TONY

Arturo Bryan chris David Jon Mark shane SIMON Thomas TONY

Number of names = 10
Search Token = TONY
Search token is in the number 10 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>

======================= p32 ====================================


C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p32

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>del p3
.exe

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>del p3
.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>cl p3.
cpp /clr
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1
for Microsoft (R) .NET Framework version 4.00.30319.34014
Copyright (C) Microsoft Corporation.  All rights reserved.

p3.cpp
Microsoft (R) Incremental Linker Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:p3.exe
p3.obj

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem --
 To test, try different values

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem #1
 Test existing elements with exact match

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>rem

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Brian

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Brian
Search token is in the number 1 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Bryan

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Bryan
Search token is in the number 2 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 chris

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = chris
Search token is in the number 3 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Christopher

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Christopher
Search token is in the number 4 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Christy

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Christy
Search token is in the number 5 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 DAVE

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = DAVE
Search token is in the number 6 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 David

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = David
Search token is in the number 7 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Jon

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Jon
Search token is in the number 9 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Johnny

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Johnny
Search token is in the number 8 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Jonathan

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Jonathan
Search token is in the number 10 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Tom

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Tom
Search token is in the number 11 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Tomas

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Tomas
Search token is in the number 12 position.

C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>p3 .\p
3.data2 Tommy

Brian Bryan chris Christopher Christy DAVE David Johnny Jon Jonathan Tom Tomas T
ommy

Number of names = 13
Search Token = Tommy
Search token is in the number 13 position.
C:\Users\Steven\Documents\Visual Studio 2013\Projects\CS47 Projects\p3\p3>