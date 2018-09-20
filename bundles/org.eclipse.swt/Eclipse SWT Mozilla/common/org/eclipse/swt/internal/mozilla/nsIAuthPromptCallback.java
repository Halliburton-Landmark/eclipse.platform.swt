package org.eclipse.swt.internal.mozilla;


public class nsIAuthPromptCallback extends nsISupports {

	static final int LAST_METHOD_ID = nsISupports.LAST_METHOD_ID + 2;

	static final String NS_IAUTHPROMPTCALLBACK_IID_STR = "bdc387d7-2d29-4cac-92f1-dd75d786631d";

	static {
		IIDStore.RegisterIID(nsIAuthPromptCallback.class, MozillaVersion.VERSION_BASE, new nsID(NS_IAUTHPROMPTCALLBACK_IID_STR));
	}

	public nsIAuthPromptCallback(long /*int*/ address) {
		super(address);
	}

	public int onAuthAvailable(long /*int*/ aContext, long aAuthInfo) {
		return XPCOM.VtblCall(nsISupports.LAST_METHOD_ID  + 1, getAddress(), aContext, aAuthInfo);
	}

	public int onAuthCancelled(long /*int*/ aContext, long userCancel) {
		return XPCOM.VtblCall(nsISupports.LAST_METHOD_ID  + 2, getAddress(), aContext, userCancel);
	}
}
