#include <jni.h>
#include "DMGRJavaInterface.h"
#include "dpcdecl.h"
#include "dmgr.h"

JNIEXPORT jboolean JNICALL Java_DMGRJavaInterface_DmgrOpen  (JNIEnv *env, jclass cl, jint phif, jstring szSel)
{
	return DmgrOpen((HIF*)&phif, (char*)szSel);
}


