h01883
s 00002/00005/00009
d D 1.4 19/04/14 20:42:05 nzenger 4 3
c no
e
s 00003/00003/00011
d D 1.3 19/04/14 20:30:31 nzenger 3 2
c no
e
s 00006/00006/00008
d D 1.2 19/04/14 20:22:50 nzenger 2 1
c no
e
s 00014/00000/00000
d D 1.1 19/03/10 20:08:36 nzenger 1 0
c date and time created 19/03/10 20:08:36 by nzenger
e
u
U
f e 0
t
T
I 1
CCC = g++
D 2
PRJ = project1
OBJS = menu.o stubs.o
HEAD = record.h stubs.h
E 2
I 2
PRJ = Project2
D 4
OBJS = interface.cpp llist.cpp
E 4
I 4
OBJS = interface.cpp llist.cpp 
E 4
HEAD = record.h llist.h
E 2
D 4

E 4
$(PRJ): $(OBJS)             ## next line must begin with a TAB
D 2
	$(CCC) $(OBJS) -o $(PRJ) 
E 2
I 2
D 3
        $(CCC) $(OBJS) -D_DEBUG -o $(PRJ)
E 2
E 3
I 3
D 4
	$(CCC) $(OBJS) -D_DEBUG -o $(PRJ)
E 3

E 4
I 4
	$(CCC) $(OBJS) -D_DEBUG -o $(PRJ) 
E 4
$(OBJS):$(HEAD)             ## no executable, so use makes default rules
D 4

E 4
clean:                      ## next lines must begin with a TAB
D 2
	rm -f $(OBJS) $(PRJ)
	rm -f *~ *% *# .#* 
E 2
I 2
D 3
        rm -f $(OBJS) $(PRJ)
        rm -f *~ *% *# .#* 
E 2
E 3
I 3
	rm -f $(OBJS) $(PRJ)
	rm -f *~ *% *# .#* 
E 3

E 1
