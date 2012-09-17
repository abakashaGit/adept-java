class AdeptSdk {
	static {
		//Get the execution path of AdeptSdk, and append lib directory.
		String lib = System.getProperty("user.dir") + "/lib/libdmgrimp.so";
		try
		{
			System.load(lib);
		}
		catch(UnsatisfiedLinkError e)
		{
			System.out.println("Failed to load C++ Implementation for DMGR:" + lib + "\n" + e + "\n");
		}
	}
	public static void main(String[] args) {
		boolean passFail = false;
		DMGRJavaInterface dmgr = new DMGRJavaInterface();
		int handle = 0;
		handle = dmgr.DmgrOpen(handle, "Basys2");
		if(handle != 0)
		{
			System.out.println("Successfully loaded device, returned handle: " + handle);
		}
		else
		{
			System.out.println("Failed to load device, returned handle: " + handle);
		}
	}
}
