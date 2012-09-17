#include <jni.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include "DMGRJavaInterface.h"
#include "dpcdecl.h"
#include "dmgr.h"

JNIEXPORT jint JNICALL Java_DMGRJavaInterface_DmgrOpen  (JNIEnv *env, jclass cl, jint phif, jstring szSel)
{
	void* dHandle;
	char* lib = (char*)"/usr/local/lib64/digilent/adept/libdmgr.so";
	char* name = (char*)"DmgrOpen";
	char* error = NULL;
	int phifNew = -1;
	const char *szSelNative;
	char szSelNative2[128];
	int openSuccess;

	dHandle = dlopen(lib, RTLD_LAZY);
	if(!dHandle)
	{
		printf("Failed to load shared object: %s\nerror: %s\n", lib, dlerror());
		return 0;
	}
	//Get the function location.
	jboolean (*dmgrOpen)(HIF *, char *);
	dmgrOpen = (jboolean (*)(HIF*, char*))dlsym(dHandle, name);
	error = dlerror();
	if(error) //Check to see if error is non-NULL, that is a pointer to an error description.
	{
		printf("Failed to load symbol: %s\nerror: %s\n", name, error);
		return 0;
	}

	szSelNative = (*env).GetStringUTFChars(szSel, 0);
	strncpy(szSelNative2, szSelNative, 127);
	szSelNative2[127] = '\0';
	(*env).ReleaseStringUTFChars(szSel, szSelNative);
	openSuccess = dmgrOpen((HIF*)&phifNew, szSelNative2);
	dlclose(dHandle);
	if(!openSuccess)
	{
		printf("Failed to open device: %s\n", szSelNative2);
		return 0;
	}
	return phifNew;
/*
	printf("hello world!\n");
	return 0;
*/
}


