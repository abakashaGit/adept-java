public class DMGRJavaInterface
{
	static {
		System.loadLibrary("dmgr");
	}
	private static native boolean DmgrOpen(int phif, String szSel);
}
