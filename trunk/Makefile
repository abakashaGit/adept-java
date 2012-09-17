###############
# Makefile for java JNI interfaces
# Author: catatonicprime
# Date: 7/16/2012
#
# Donations accepted in the form of bitcoins
# #############

CC=javac

AdeptSdk.class: AdeptSdk.java java/DMGRJavaInterface.class 
	cd c; make
	cp java/*.class ./
	$(CC) $<

java/DMGRJavaInterface.class:
	cd java; make

clean:
	rm -f *.class
	cd c; make clean
	cd java; make clean
