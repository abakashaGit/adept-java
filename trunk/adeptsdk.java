class AdeptSdk {
	static {
		System.out.println("Loading libraries");
		try
		{
			System.load("c/dmgrImp.o");
		}
		catch(UnsatisfiedLinkError e)
		{
			System.out.println("Failed to load C++ Implementation for DMGR: c/dmgrImp.o");
		}
	}
	public static void main(String[] args) {
		
	}
}
