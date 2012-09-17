class AdeptSdk {
	static {
		//Get the execution path of AdeptSdk, add lib directory.
		String lib = System.getProperty("user.dir") + "/lib/libdmgrimp.so";
		try
		{
			System.load(lib);
		}
		catch(UnsatisfiedLinkError e)
		{
			System.out.println("Failed to load C++ Implementation for DMGR:" + lib);
		}
	}
	public static void main(String[] args) {
		boolean passFail = false;
		DMGRJavaInterface dmgr = new DMGRJavaInterface();
		int handle = 1234;
		if(dmgr.DmgrOpen(handle, "Basys2") == true)
		{
			System.out.println("success!" + handle);
		}
		else
		{
			System.out.println("fail!" + handle);
		}
	}
}
