CCC = g++
PRJ = project1
OBJS = menu.o stubs.o
HEAD = record.h stubs.h

$(PRJ): $(OBJS)             ## next line must begin with a TAB
	$(CCC) $(OBJS) -o $(PRJ) 

$(OBJS):$(HEAD)             ## no executable, so use makes default rules

clean:                      ## next lines must begin with a TAB
	rm -f $(OBJS) $(PRJ)
	rm -f *~ *% *# .#* 

