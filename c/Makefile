###############
# Makefile for dmgr wrappers for java
# Author: catatonicprime
# Date: 7/15/2012
#
# Donations accepted in the form of beer.
# #############
CC=g++
OPTS=-fPIC -Wall -c -o $@
INCD=-I /opt/digilent.adept.sdk_2.1.1/inc/ -I /usr/lib/jvm/java-1.6.0-openjdk/include/ -I ../include/
LIBD=-L /usr/local/lib64/digilent/adept/
LIBS=-ldl

SOPTS=-shared -Wall,-soname,$@, -o $@ $^

../lib/libdmgrimp.so: dmgrimp.o
	$(CC) $(SOPTS)

dmgrimp.o: dmgrimp.cpp
	$(CC) $(OPTS) $(INCD) $(LIBD) $< $(LIBS)

clean:
	rm -f *.o
	rm -f *.so
	rm -f ../lib/*.so
