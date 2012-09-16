#include <jni.h>
#include <stdio.h>
#include <dlfcn.h>
#include "DMGRJavaInterface.h"
#include "dpcdecl.h"
#include "dmgr.h"

JNIEXPORT jboolean JNICALL Java_DMGRJavaInterface_DmgrOpen  (JNIEnv *env, jclass cl, jint phif, jstring szSel)
{
	void* dHandle;
	char* lib = (char*)"/usr/local/lib64/digilent/adept/libdmgr.so";
	char* name = (char*)"lol";
	char* error = NULL;

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
	if(!error)
	{
		printf("Failed to load symbol: %s\nerror: %s", name, error);
		return 0;
	}
	dlclose(dHandle);
	printf("Options: \n");
	return 0;
	//return dmgrOpen((HIF*)&phif, (char*)szSel);

	//return 0;
}


