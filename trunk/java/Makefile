###############
# Makefile for java JNI interfaces
# Author: catatonicprime
# Date: 7/16/2012
#
# Donations accepted in the form of bitcoins
# #############

CC=javac
JNI=javah -jni

DMGRJavaInterface.class: DMGRJavaInterface.java
	$(CC) $<
	$(JNI) DMGRJavaInterface
	mv *.h ../include/

clean:
	rm -f *.class
