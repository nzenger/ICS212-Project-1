h18359
s 00001/00001/00019
d D 1.15 19/04/14 20:55:46 nzenger 15 14
e
s 00000/00000/00020
d D 1.14 19/04/14 20:47:01 nzenger 14 13
e
s 00001/00001/00019
d D 1.13 19/04/14 20:43:14 nzenger 13 12
e
s 00002/00002/00018
d D 1.12 19/04/14 20:34:11 nzenger 12 11
e
s 00001/00001/00019
d D 1.11 19/04/14 20:31:16 nzenger 11 10
e
s 00011/00011/00009
d D 1.10 19/04/14 20:26:39 nzenger 10 9
c no
e
s 00002/00010/00018
d D 1.9 19/04/14 20:15:31 nzenger 9 8
c no
e
s 00018/00018/00010
d D 1.8 19/04/14 20:08:32 nzenger 8 7
c no
e
s 00012/00001/00016
d D 1.7 19/04/14 20:04:16 nzenger 7 6
c final
e
s 00000/00000/00017
d D 1.6 19/04/14 19:55:55 nzenger 6 5
c no
e
s 00013/00000/00004
d D 1.5 19/04/14 19:46:31 nzenger 5 4
c 1.1
e
s 00000/00002/00004
d D 1.4 19/04/14 19:40:01 nzenger 4 3
c changes to ls
e
s 00000/00006/00006
d D 1.3 19/03/10 21:32:20 nzenger 3 2
e
s 00000/00000/00012
d D 1.2 19/03/10 21:31:05 nzenger 2 1
e
s 00012/00000/00000
d D 1.1 19/03/10 21:27:08 nzenger 1 0
c date and time created 19/03/10 21:27:08 by nzenger
e
u
U
f e 0
t
T
I 1
D 4
'#!/bin/bash
# getrelease script
E 4
D 7
ls
D 3
cd /home/n/nzenger/project1/sccs
ls
cd /home/n/nzenger/project1/
sccs get makefile
make
./project1
E 3
I 5
E 7
D 9
sccs get makefile
E 9
I 9
D 10
sccs get -r1.1 makefile
E 9
sccs get stubs.c
sccs get stubs.h
D 9
sccs get record.h
E 9
I 9
sccs get -r1.1 record.h
E 9
sccs get menu.c
E 10
I 10
D 11
sccs get -r1.2 makefile
E 11
I 11
D 13
sccs get -r1.3 makefile
E 11
E 13
I 13
sccs get -r1.4 makefile
E 13
D 15
sccs get llist.cpp
E 15
sccs get llist.h
sccs get -r1.2 record.h
sccs get interface.cpp
sccs get -r1.2 read.txt
E 10
I 15
sccs get llist.cpp
E 15
make
D 8
rm makefile
I 7
Y
E 7
rm stubs.c
I 7
Y
E 7
rm stubs.h
I 7
Y
E 7
rm record.h
I 7
Y
E 7
rm menu.c
I 7
Y
rm menu.o
Y
rm stubs.o
Y
rm project1
Y
E 7
rm getrelease.sh
I 7
Y
E 7
E 8
I 8
I 10
./Project2
E 10
rm -f -r makefile
D 9

E 9
D 10
rm -f -r stubs.c
D 9

E 9
rm -f -r stubs.h
D 9

E 9
E 10
I 10
rm -f -r llist.cpp
rm -f -r llist.h
E 10
rm -f -r record.h
D 9

E 9
D 10
rm -f -r menu.c
D 9

E 9
rm -f -r menu.o
D 9

E 9
rm -f -r stubs.o
D 9

E 9
rm -f -r project1
D 9

E 9
E 10
I 10
D 12
rm -f -r interface.c
E 12
I 12
rm -f -r interface.cpp
E 12
rm -f -r Project2
E 10
rm -f -r getrelease.sh
D 12

E 8
E 12
I 12
rm -f -r read.txt
E 12

E 5



E 1
