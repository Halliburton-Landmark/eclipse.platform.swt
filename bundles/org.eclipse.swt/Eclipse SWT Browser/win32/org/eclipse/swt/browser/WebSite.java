/*******************************************************************************
 * Copyright (c) 2000, 2017 IBM Corporation and others.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.browser;

import java.util.*;

import org.eclipse.swt.*;
import org.eclipse.swt.internal.*;
import org.eclipse.swt.internal.ole.win32.*;
import org.eclipse.swt.internal.win32.*;
import org.eclipse.swt.ole.win32.*;
import org.eclipse.swt.widgets.*;

class WebSite extends OleControlSite {
	COMObject iDocHostUIHandler;
	COMObject iDocHostShowUI;
	COMObject iServiceProvider;
	COMObject iInternetSecurityManager;
	COMObject iOleCommandTarget;
	COMObject iAuthenticate;
	COMObject iDispatch;
	boolean ignoreNextMessage, ignoreAllMessages;
	Boolean canExecuteApplets;

	static final int OLECMDID_SHOWSCRIPTERROR = 40;
	static final short [] ACCENTS = new short [] {'~', '`', '\'', '^', '"'};
	static final String CONSUME_KEY = "org.eclipse.swt.OleFrame.ConsumeKey"; //$NON-NLS-1$

public WebSite(Composite parent, int style, String progId) {
	super(parent, style, progId);
}

@Override
protected void createCOMInterfaces () {
	super.createCOMInterfaces();
	iDocHostUIHandler = new COMObject(new int[]{2, 0, 0, 4, 1, 5, 0, 0, 1, 1, 1, 3, 3, 2, 2, 1, 3, 2}){
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return ShowContextMenu((int)/*64*/args[0], args[1], args[2], args[3]);}
		@Override
		public long /*int*/ method4(long /*int*/[] args) {return GetHostInfo(args[0]);}
		@Override
		public long /*int*/ method5(long /*int*/[] args) {return ShowUI((int)/*64*/args[0], args[1], args[2], args[3], args[4]);}
		@Override
		public long /*int*/ method6(long /*int*/[] args) {return HideUI();}
		@Override
		public long /*int*/ method7(long /*int*/[] args) {return UpdateUI();}
		@Override
		public long /*int*/ method8(long /*int*/[] args) {return EnableModeless((int)/*64*/args[0]);}
		@Override
		public long /*int*/ method9(long /*int*/[] args) {return OnDocWindowActivate((int)/*64*/args[0]);}
		@Override
		public long /*int*/ method10(long /*int*/[] args) {return OnFrameWindowActivate((int)/*64*/args[0]);}
		@Override
		public long /*int*/ method11(long /*int*/[] args) {return ResizeBorder(args[0], args[1], (int)/*64*/args[2]);}
		@Override
		public long /*int*/ method12(long /*int*/[] args) {return TranslateAccelerator(args[0], args[1], (int)/*64*/args[2]);}
		@Override
		public long /*int*/ method13(long /*int*/[] args) {return GetOptionKeyPath(args[0], (int)/*64*/args[1]);}
		@Override
		public long /*int*/ method14(long /*int*/[] args) {return GetDropTarget(args[0], args[1]);}
		@Override
		public long /*int*/ method15(long /*int*/[] args) {return GetExternal(args[0]);}
		@Override
		public long /*int*/ method16(long /*int*/[] args) {return TranslateUrl((int)/*64*/args[0], args[1], args[2]);}
		@Override
		public long /*int*/ method17(long /*int*/[] args) {return FilterDataObject(args[0], args[1]);}
	};
	iDocHostShowUI = new COMObject(new int[]{2, 0, 0, 7, C.PTR_SIZEOF == 4 ? 7 : 6}){
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return ShowMessage(args[0], args[1], args[2], (int)/*64*/args[3], args[4], (int)/*64*/args[5], args[6]);}
		@Override
		public long /*int*/ method4(long /*int*/[] args) {
			if (args.length == 7) {
				return ShowHelp(args[0], args[1], (int)/*64*/args[2], (int)/*64*/args[3], (int)/*64*/args[4], (int)/*64*/args[5], args[6]);
			} else {
				return ShowHelp_64(args[0], args[1], (int)/*64*/args[2], (int)/*64*/args[3], args[4], args[5]);
			}
		}
	};
	iServiceProvider = new COMObject(new int[]{2, 0, 0, 3}){
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return QueryService(args[0], args[1], args[2]);}
	};
	iInternetSecurityManager = new COMObject(new int[]{2, 0, 0, 1, 1, 3, 4, 8, 7, 3, 3}){
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return SetSecuritySite(args[0]);}
		@Override
		public long /*int*/ method4(long /*int*/[] args) {return GetSecuritySite(args[0]);}
		@Override
		public long /*int*/ method5(long /*int*/[] args) {return MapUrlToZone(args[0], args[1], (int)/*64*/args[2]);}
		@Override
		public long /*int*/ method6(long /*int*/[] args) {return GetSecurityId(args[0], args[1], args[2], args[3]);}
		@Override
		public long /*int*/ method7(long /*int*/[] args) {return ProcessUrlAction(args[0], (int)/*64*/args[1], args[2], (int)/*64*/args[3], args[4], (int)/*64*/args[5], (int)/*64*/args[6], (int)/*64*/args[7]);}
		@Override
		public long /*int*/ method8(long /*int*/[] args) {return QueryCustomPolicy(args[0], args[1], args[2], args[3], args[4], (int)/*64*/args[5], (int)/*64*/args[6]);}
		@Override
		public long /*int*/ method9(long /*int*/[] args) {return SetZoneMapping((int)/*64*/args[0], args[1], (int)/*64*/args[2]);}
		@Override
		public long /*int*/ method10(long /*int*/[] args) {return GetZoneMappings((int)/*64*/args[0], args[1], (int)/*64*/args[2]);}
	};
	iOleCommandTarget = new COMObject(new int[]{2, 0, 0, 4, 5}) {
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return QueryStatus(args[0], (int)/*64*/args[1], args[2], args[3]);}
		@Override
		public long /*int*/ method4(long /*int*/[] args) {return Exec(args[0], (int)/*64*/args[1], (int)/*64*/args[2], args[3], args[4]);}
	};
	iAuthenticate = new COMObject(new int[]{2, 0, 0, 3}){
		@Override
		public long /*int*/ method0(long /*int*/[] args) {return QueryInterface(args[0], args[1]);}
		@Override
		public long /*int*/ method1(long /*int*/[] args) {return AddRef();}
		@Override
		public long /*int*/ method2(long /*int*/[] args) {return Release();}
		@Override
		public long /*int*/ method3(long /*int*/[] args) {return Authenticate(args[0], args[1], args[2]);}
	};
	iDispatch = new COMObject (new int[] {2, 0, 0, 1, 3, 5, 8}) {
		@Override
		public long /*int*/ method0 (long /*int*/[] args) {
			/*
			 * IDispatch check must be done here instead of in the shared QueryInterface
			 * implementation, to avoid answering the superclass's IDispatch implementation
			 * instead of this one.
			 */
			GUID guid = new GUID ();
			COM.MoveMemory (guid, args[0], GUID.sizeof);
			if (COM.IsEqualGUID (guid, COM.IIDIDispatch)) {
				OS.MoveMemory (args[1], new long /*int*/[] {iDispatch.getAddress ()}, C.PTR_SIZEOF);
				AddRef ();
				return COM.S_OK;
			}
			return QueryInterface (args[0], args[1]);
		}
		@Override
		public long /*int*/ method1 (long /*int*/[] args) {return AddRef ();}
		@Override
		public long /*int*/ method2 (long /*int*/[] args) {return Release ();}
		@Override
		public long /*int*/ method3 (long /*int*/[] args) {return GetTypeInfoCount (args[0]);}
		@Override
		public long /*int*/ method4 (long /*int*/[] args) {return GetTypeInfo ((int)/*64*/args[0], (int)/*64*/args[1], args[2]);}
		@Override
		public long /*int*/ method5 (long /*int*/[] args) {return GetIDsOfNames ((int)/*64*/args[0], args[1], (int)/*64*/args[2], (int)/*64*/args[3], args[4]);}
		@Override
		public long /*int*/ method6 (long /*int*/[] args) {return Invoke ((int)/*64*/args[0], (int)/*64*/args[1], (int)/*64*/args[2], (int)/*64*/args[3], args[4], args[5], args[6], args[7]);}
	};
}

@Override
protected void disposeCOMInterfaces() {
	super.disposeCOMInterfaces();
	if (iDocHostUIHandler != null) {
		iDocHostUIHandler.dispose();
		iDocHostUIHandler = null;
	}
	if (iDocHostShowUI != null) {
		iDocHostShowUI.dispose();
		iDocHostShowUI = null;
	}
	if (iServiceProvider != null) {
		iServiceProvider.dispose();
		iServiceProvider = null;
	}
	if (iInternetSecurityManager != null) {
		iInternetSecurityManager.dispose();
		iInternetSecurityManager = null;
	}
	if (iOleCommandTarget != null) {
		iOleCommandTarget.dispose();
		iOleCommandTarget = null;
	}
	if (iAuthenticate != null) {
		iAuthenticate.dispose();
		iAuthenticate = null;
	}
	if (iDispatch != null) {
		iDispatch.dispose ();
		iDispatch = null;
	}
}

@Override
protected int AddRef() {
	/* Workaround for javac 1.1.8 bug */
	return super.AddRef();
}

@Override
protected int QueryInterface(long /*int*/ riid, long /*int*/ ppvObject) {
	int result = super.QueryInterface(riid, ppvObject);
	if (result == COM.S_OK) return result;
	if (riid == 0 || ppvObject == 0) return COM.E_INVALIDARG;
	GUID guid = new GUID();
	COM.MoveMemory(guid, riid, GUID.sizeof);
	if (COM.IsEqualGUID(guid, COM.IIDIDocHostUIHandler)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iDocHostUIHandler.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
	if (COM.IsEqualGUID(guid, COM.IIDIDocHostShowUI)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iDocHostShowUI.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
	if (COM.IsEqualGUID(guid, COM.IIDIServiceProvider)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iServiceProvider.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
    if (COM.IsEqualGUID(guid, COM.IIDIInternetSecurityManager)) {
        OS.MoveMemory(ppvObject, new long /*int*/[] {iInternetSecurityManager.getAddress()}, C.PTR_SIZEOF);
        AddRef();
        return COM.S_OK;
    }
	if (COM.IsEqualGUID(guid, COM.IIDIOleCommandTarget)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iOleCommandTarget.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
	OS.MoveMemory(ppvObject, new long /*int*/[] {0}, C.PTR_SIZEOF);
	return COM.E_NOINTERFACE;
}

/* IDocHostUIHandler */

int EnableModeless(int EnableModeless) {
	return COM.E_NOTIMPL;
}

int FilterDataObject(long /*int*/ pDO, long /*int*/ ppDORet) {
	return COM.E_NOTIMPL;
}

int GetDropTarget(long /*int*/ pDropTarget, long /*int*/ ppDropTarget) {
	return COM.E_NOTIMPL;
}

int GetExternal(long /*int*/ ppDispatch) {
	OS.MoveMemory (ppDispatch, new long /*int*/[] {iDispatch.getAddress()}, C.PTR_SIZEOF);
	AddRef ();
	return COM.S_OK;
}

int GetHostInfo(long /*int*/ pInfo) {
	int info = IE.DOCHOSTUIFLAG_THEME | IE.DOCHOSTUIFLAG_ENABLE_REDIRECT_NOTIFICATION | IE.DOCHOSTUIFLAG_DPI_AWARE;
	IE browser = (IE)((Browser)getParent().getParent()).webBrowser;
	if ((browser.style & SWT.BORDER) == 0) info |= IE.DOCHOSTUIFLAG_NO3DOUTERBORDER;
	DOCHOSTUIINFO uiInfo = new DOCHOSTUIINFO ();
	OS.MoveMemory(uiInfo, pInfo, DOCHOSTUIINFO.sizeof);
	uiInfo.dwFlags = info;
	OS.MoveMemory(pInfo, uiInfo, DOCHOSTUIINFO.sizeof);
	return COM.S_OK;
}

int GetOptionKeyPath(long /*int*/ pchKey, int dw) {
	return COM.E_NOTIMPL;
}

int HideUI() {
	return COM.E_NOTIMPL;
}

int OnDocWindowActivate(int fActivate) {
	return COM.E_NOTIMPL;
}

int OnFrameWindowActivate(int fActivate) {
	return COM.E_NOTIMPL;
}

@Override
protected int Release() {
	/* Workaround for javac 1.1.8 bug */
	return super.Release();
}

int ResizeBorder(long /*int*/ prcBorder, long /*int*/ pUIWindow, int fFrameWindow) {
	return COM.E_NOTIMPL;
}

int ShowContextMenu(int dwID, long /*int*/ ppt, long /*int*/ pcmdtReserved, long /*int*/ pdispReserved) {
	Browser browser = (Browser)getParent().getParent();
	Event event = new Event();
	POINT pt = new POINT();
	OS.MoveMemory(pt, ppt, POINT.sizeof);
	pt.x = DPIUtil.autoScaleDown(pt.x); // To Points
	pt.y = DPIUtil.autoScaleDown(pt.y); // To Points
	event.x = pt.x;
	event.y = pt.y;
	browser.notifyListeners(SWT.MenuDetect, event);
	if (!event.doit) return COM.S_OK;
	Menu menu = browser.getMenu();
	if (menu != null && !menu.isDisposed ()) {
		if (pt.x != event.x || pt.y != event.y) {
			menu.setLocation (event.x, event.y);
		}
		menu.setVisible (true);
		return COM.S_OK;
	}
	/* Show default IE popup menu */
	return COM.S_FALSE;
}

int ShowUI(int dwID, long /*int*/ pActiveObject, long /*int*/ pCommandTarget, long /*int*/ pFrame, long /*int*/ pDoc) {
	return COM.S_FALSE;
}

int TranslateAccelerator(long /*int*/ lpMsg, long /*int*/ pguidCmdGroup, int nCmdID) {
	/*
	* Feature in Internet Explorer.  By default the embedded Internet Explorer control runs
	* the Internet Explorer shortcuts (e.g. Ctrl+F for Find).  This overrides the shortcuts
	* defined by SWT.  The workaround is to forward the accelerator keys to the parent window
	* and have Internet Explorer ignore the ones handled by the parent window.
	*/
	Menu menubar = getShell().getMenuBar();
	if (menubar != null && !menubar.isDisposed() && menubar.isEnabled()) {
		Shell shell = menubar.getShell();
		long /*int*/ hwnd = shell.handle;
		long /*int*/ hAccel = OS.SendMessage(hwnd, OS.WM_APP+1, 0, 0);
		if (hAccel != 0) {
			MSG msg = new MSG();
			OS.MoveMemory(msg, lpMsg, MSG.sizeof);
			if (OS.TranslateAccelerator(hwnd, hAccel, msg) != 0) return COM.S_OK;
		}
	}
	/*
	* By default the IE shortcuts are run.  However, the shortcuts below should not run
	* in this context.  The workaround is to block IE from handling these shortcuts by
	* answering COM.S_OK.
	*
	* - F5 causes a refresh, which is not appropriate when rendering HTML from memory
	* - CTRL+L and CTRL+O show an Open Location dialog in IE8, which is undesirable and
	* can crash in some contexts
	* - CTRL+N opens a standalone IE, which is undesirable and can crash in some contexts
	*/
	int result = COM.S_FALSE;
	MSG msg = new MSG();
	OS.MoveMemory(msg, lpMsg, MSG.sizeof);
	if (msg.message == OS.WM_KEYDOWN) {
		switch ((int)/*64*/msg.wParam) {
			case OS.VK_F5:
				OleAutomation auto = new OleAutomation(this);
				int[] rgdispid = auto.getIDsOfNames(new String[] { "LocationURL" }); //$NON-NLS-1$
				Variant pVarResult = auto.getProperty(rgdispid[0]);
				auto.dispose();
				if (pVarResult != null) {
					if (pVarResult.getType() == OLE.VT_BSTR) {
						String url = pVarResult.getString();
						if (url.equals(IE.ABOUT_BLANK)) result = COM.S_OK;
					}
					pVarResult.dispose();
				}
				break;
			case OS.VK_TAB:
				/*
				 * Do not interfere with tab traversal since it's not known
				 * if it will be within IE or out to another Control.
				 */
				break;
			case OS.VK_UP:
			case OS.VK_DOWN:
			case OS.VK_LEFT:
			case OS.VK_RIGHT:
			case OS.VK_HOME:
			case OS.VK_END:
			case OS.VK_PRIOR:
			case OS.VK_NEXT:
				/* Do not translate/consume IE's keys for scrolling content. */
				break;
			case OS.VK_BACK:
			case OS.VK_RETURN:
				/*
				* Translating OS.VK_BACK or OS.VK_RETURN results in the native control
				* handling them twice (eg.- inserting two lines instead of one).  So
				* these keys are not translated here, and instead are explicitly handled
				* in the keypress handler.
				*/
				break;
			case OS.VK_L:
			case OS.VK_N:
			case OS.VK_O:
				if (OS.GetKeyState (OS.VK_CONTROL) < 0 && OS.GetKeyState (OS.VK_MENU) >= 0 && OS.GetKeyState (OS.VK_SHIFT) >= 0) {
					if (msg.wParam == OS.VK_N || IE.IEVersion >= 8) {
						frame.setData(CONSUME_KEY, "false"); //$NON-NLS-1$
						result = COM.S_OK;
						break;
					}
				}
				// FALL THROUGH
			default:
				OS.TranslateMessage(msg);
				frame.setData(CONSUME_KEY, "true"); //$NON-NLS-1$
				break;
		}
	}

	switch (msg.message) {
		case OS.WM_KEYDOWN:
		case OS.WM_KEYUP: {
			boolean isAccent = false;
			switch ((int)/*64*/msg.wParam) {
				case OS.VK_SHIFT:
				case OS.VK_MENU:
				case OS.VK_CONTROL:
				case OS.VK_CAPITAL:
				case OS.VK_NUMLOCK:
				case OS.VK_SCROLL:
					break;
				default: {
					int mapKey = OS.MapVirtualKey ((int)/*64*/msg.wParam, 2);
					if (mapKey != 0) {
						isAccent = (mapKey & 0x80000000) != 0;
						if (!isAccent) {
							for (int i=0; i<ACCENTS.length; i++) {
								int value = OS.VkKeyScan (ACCENTS [i]);
								if (value != -1 && (value & 0xFF) == msg.wParam) {
									int state = value >> 8;
									if ((OS.GetKeyState (OS.VK_SHIFT) < 0) == ((state & 0x1) != 0) &&
										(OS.GetKeyState (OS.VK_CONTROL) < 0) == ((state & 0x2) != 0) &&
										(OS.GetKeyState (OS.VK_MENU) < 0) == ((state & 0x4) != 0)) {
											if ((state & 0x7) != 0) isAccent = true;
											break;
									}
								}
							}
						}
					}
					break;
				}
			}
			if (isAccent) result = COM.S_OK;
		}
	}
	return result;
}

int TranslateUrl(int dwTranslate, long /*int*/ pchURLIn, long /*int*/ ppchURLOut) {
	return COM.E_NOTIMPL;
}

int UpdateUI() {
	return COM.E_NOTIMPL;
}

/* IDocHostShowUI */

int ShowMessage(long /*int*/ hwnd, long /*int*/ lpstrText, long /*int*/ lpstrCaption, int dwType, long /*int*/ lpstrHelpFile, int dwHelpContext, long /*int*/ plResult) {
	boolean ignore = ignoreNextMessage || ignoreAllMessages;
	ignoreNextMessage = false;
	return ignore ? COM.S_OK : COM.S_FALSE;
}

int ShowHelp_64(long /*int*/ hwnd, long /*int*/ pszHelpFile, int uCommand, int dwData, long pt, long /*int*/ pDispatchObjectHit) {
	POINT point = new POINT();
	OS.MoveMemory(point, new long[]{pt}, 8);
	return ShowHelp(hwnd, pszHelpFile, uCommand, dwData, point.x, point.y, pDispatchObjectHit);
}

/* Note.  One of the arguments of ShowHelp is a POINT struct and not a pointer to a POINT struct. Because
 * of the way Callback gets int parameters from a va_list of C arguments 2 integer arguments must be declared,
 * ptMouse_x and ptMouse_y. Otherwise the Browser crashes when the user presses F1 to invoke
 * the help.
 */
int ShowHelp(long /*int*/ hwnd, long /*int*/ pszHelpFile, int uCommand, int dwData, int ptMouse_x, int ptMouse_y, long /*int*/ pDispatchObjectHit) {
	Browser browser = (Browser)getParent().getParent();
	Event event = new Event();
	event.type = SWT.Help;
	event.display = getDisplay();
	event.widget = browser;
	Shell shell = browser.getShell();
	Control control = browser;
	do {
		if (control.isListening(SWT.Help)) {
			control.notifyListeners(SWT.Help, event);
			break;
		}
		if (control == shell) break;
		control = control.getParent();
	} while (true);
	return COM.S_OK;
}

/* IServiceProvider */

int QueryService(long /*int*/ guidService, long /*int*/ riid, long /*int*/ ppvObject) {
	if (riid == 0 || ppvObject == 0) return COM.E_INVALIDARG;
	GUID guid = new GUID();
	COM.MoveMemory(guid, riid, GUID.sizeof);
	if (COM.IsEqualGUID(guid, COM.IIDIInternetSecurityManager)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iInternetSecurityManager.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
	if (COM.IsEqualGUID(guid, COM.IIDIAuthenticate)) {
		OS.MoveMemory(ppvObject, new long /*int*/[] {iAuthenticate.getAddress()}, C.PTR_SIZEOF);
		AddRef();
		return COM.S_OK;
	}
	OS.MoveMemory(ppvObject, new long /*int*/[] {0}, C.PTR_SIZEOF);
	return COM.E_NOINTERFACE;
}

/* IInternetSecurityManager */

int SetSecuritySite(long /*int*/ pSite) {
	return IE.INET_E_DEFAULT_ACTION;
}

int GetSecuritySite(long /*int*/ ppSite) {
	return IE.INET_E_DEFAULT_ACTION;
}

int MapUrlToZone(long /*int*/ pwszUrl, long /*int*/ pdwZone, int dwFlags) {
	/*
	* Feature in IE.  HTML rendered in memory does not enable local links
	* but the same HTML document loaded through a local file is permitted
	* to follow local links.  The workaround is to return URLZONE_INTRANET
	* instead of the default value URLZONE_LOCAL_MACHINE.
	*/
	/*
	 * Landmark issue
	 * Bug 329228  - [Browser-IE] Callback happens on disposed control and generates an error
     * https://bugs.eclipse.org/bugs/show_bug.cgi?id=329228
	 */
	if (!isDisposed()) {
	    IE ie = (IE) ((Browser) getParent().getParent()).webBrowser;
	    /*
		* For some reason IE8 invokes this function after the Browser has
		* been disposed.  To detect this case check for ie.auto != null.
		*/
		if (ie.auto != null && ie.isAboutBlank && !ie.untrustedText) {
			COM.MoveMemory(pdwZone, new int[] { IE.URLZONE_INTRANET }, 4);
			return COM.S_OK;
		}
	}
	return IE.INET_E_DEFAULT_ACTION;
}

int GetSecurityId(long /*int*/ pwszUrl, long /*int*/ pbSecurityId, long /*int*/ pcbSecurityId, long /*int*/ dwReserved) {
	return IE.INET_E_DEFAULT_ACTION;
}

int ProcessUrlAction(long /*int*/ pwszUrl, int dwAction, long /*int*/ pPolicy, int cbPolicy, long /*int*/ pContext, int cbContext, int dwFlags, int dwReserved) {
	ignoreNextMessage = false;

	/*
	* If the current page is about:blank and is trusted then
	* override default zone elevation settings to allow the action.
	*/
	if (dwAction == IE.URLACTION_FEATURE_ZONE_ELEVATION) {
	    IE ie = (IE)((Browser)getParent().getParent()).webBrowser;
	    if (ie.auto != null && ie._getUrl().startsWith(IE.ABOUT_BLANK) && !ie.untrustedText) {
			if (cbPolicy >= 4) OS.MoveMemory(pPolicy, new int[] {IE.URLPOLICY_ALLOW}, 4);
			return COM.S_OK;
	    }
	}

	int policy = IE.INET_E_DEFAULT_ACTION;

	if (dwAction >= IE.URLACTION_JAVA_MIN && dwAction <= IE.URLACTION_JAVA_MAX) {
		if (canExecuteApplets ()) {
			policy = IE.URLPOLICY_JAVA_LOW;
		} else {
			policy = IE.URLPOLICY_JAVA_PROHIBIT;
			ignoreNextMessage = true;
		}
	}
	if (dwAction == IE.URLACTION_ACTIVEX_RUN && pContext != 0) {
		GUID guid = new GUID();
		COM.MoveMemory(guid, pContext, GUID.sizeof);
		if (COM.IsEqualGUID(guid, COM.IIDJavaBeansBridge) && !canExecuteApplets ()) {
			policy = IE.URLPOLICY_DISALLOW;
			ignoreNextMessage = true;
		}
		if (COM.IsEqualGUID(guid, COM.IIDShockwaveActiveXControl)) {
			policy = IE.URLPOLICY_DISALLOW;
			ignoreNextMessage = true;
		}
	}
	if (dwAction == IE.URLACTION_SCRIPT_RUN) {
		IE browser = (IE)((Browser)getParent ().getParent ()).webBrowser;
		policy = browser.jsEnabled ? IE.URLPOLICY_ALLOW : IE.URLPOLICY_DISALLOW;
	}

	if (policy == IE.INET_E_DEFAULT_ACTION) return IE.INET_E_DEFAULT_ACTION;
	if (cbPolicy >= 4) OS.MoveMemory(pPolicy, new int[] {policy}, 4);
	return policy == IE.URLPOLICY_ALLOW ? COM.S_OK : COM.S_FALSE;
}

boolean canExecuteApplets () {
	/*
	* Executing an applet in embedded IE will crash if IE's Java plug-in
	* launches its jre in IE's process, because this new jre conflicts
	* with the one running eclipse.  These cases need to be avoided by
	* vetoing the running of applets.
	*
	* However as of Sun jre 1.6u10, applets can be launched in a separate
	* process, which avoids the conflict with the jre running eclipse.
	* Therefore if this condition is detected, and if the required jar
	* libraries are available, then applets can be executed.
	*/

	/*
	* executing applets with IE6 embedded can crash, so do not
	* attempt this if the version is less than IE7
	*/
	if (IE.IEVersion < 7) return false;

	if (canExecuteApplets == null) {
		WebBrowser webBrowser = ((Browser)getParent ().getParent ()).webBrowser;
		String script = "try {var element = document.createElement('object');element.classid='clsid:CAFEEFAC-DEC7-0000-0000-ABCDEFFEDCBA';return element.object.isPlugin2();} catch (err) {};return false;"; //$NON-NLS-1$
		canExecuteApplets = ((Boolean)webBrowser.evaluate (script));
		if (canExecuteApplets.booleanValue ()) {
			try {
				Class.forName ("sun.plugin2.main.server.IExplorerPlugin"); /* plugin.jar */	//$NON-NLS-1$
				Class.forName ("com.sun.deploy.services.Service"); /* deploy.jar */	//$NON-NLS-1$
				Class.forName ("com.sun.javaws.Globals"); /* javaws.jar */	//$NON-NLS-1$
			} catch (ClassNotFoundException e) {
				/* one or more of the required jar libraries are not available */
				canExecuteApplets = Boolean.FALSE;
			}
		}
	}
	return canExecuteApplets.booleanValue ();
}

int QueryCustomPolicy(long /*int*/ pwszUrl, long /*int*/ guidKey, long /*int*/ ppPolicy, long /*int*/ pcbPolicy, long /*int*/ pContext, int cbContext, int dwReserved) {
	return IE.INET_E_DEFAULT_ACTION;
}

int SetZoneMapping(int dwZone, long /*int*/ lpszPattern, int dwFlags) {
	return IE.INET_E_DEFAULT_ACTION;
}

int GetZoneMappings(int dwZone, long /*int*/ ppenumString, int dwFlags) {
	return COM.E_NOTIMPL;
}

/* IOleCommandTarget */
int QueryStatus(long /*int*/ pguidCmdGroup, int cCmds, long /*int*/ prgCmds, long /*int*/ pCmdText) {
	return COM.E_NOTSUPPORTED;
}

int Exec(long /*int*/ pguidCmdGroup, int nCmdID, int nCmdExecOpt, long /*int*/ pvaIn, long /*int*/ pvaOut) {
	if (pguidCmdGroup != 0) {
		GUID guid = new GUID();
		COM.MoveMemory(guid, pguidCmdGroup, GUID.sizeof);

		/*
		* If a javascript error occurred then suppress IE's default script error dialog.
		*/
		if (COM.IsEqualGUID(guid, COM.CGID_DocHostCommandHandler)) {
			if (nCmdID == OLECMDID_SHOWSCRIPTERROR) return COM.S_OK;
		}

		/*
		* Bug in Internet Explorer.  OnToolBar TRUE is also fired when any of the
		* address bar or menu bar are requested but not the tool bar.  A workaround
		* has been posted by a Microsoft developer on the public webbrowser_ctl
		* newsgroup. The workaround is to implement the IOleCommandTarget interface
		* to test the argument of an undocumented command.
		*/
		if (nCmdID == 1 && COM.IsEqualGUID(guid, COM.CGID_Explorer) && ((nCmdExecOpt & 0xFFFF) == 0xA)) {
			IE browser = (IE)((Browser)getParent().getParent()).webBrowser;
			browser.toolBar = (nCmdExecOpt & 0xFFFF0000) != 0;
		}
	}
	return COM.E_NOTSUPPORTED;
}

/* IAuthenticate */

int Authenticate (long /*int*/ hwnd, long /*int*/ szUsername, long /*int*/ szPassword) {
	IE browser = (IE)((Browser)getParent ().getParent ()).webBrowser;
	for (int i = 0; i < browser.authenticationListeners.length; i++) {
		AuthenticationEvent event = new AuthenticationEvent (browser.browser);
		event.location = browser.lastNavigateURL;
		browser.authenticationListeners[i].authenticate (event);
		if (!event.doit) return COM.E_ACCESSDENIED;
		if (event.user != null && event.password != null) {
			TCHAR user = new TCHAR (0, event.user, true);
			int size = user.length () * TCHAR.sizeof;
			long /*int*/ userPtr = OS.CoTaskMemAlloc (size);
			OS.MoveMemory (userPtr, user, size);
			TCHAR password = new TCHAR (0, event.password, true);
			size = password.length () * TCHAR.sizeof;
			long /*int*/ passwordPtr = OS.CoTaskMemAlloc (size);
			OS.MoveMemory (passwordPtr, password, size);
			C.memmove (hwnd, new long /*int*/[] {0}, C.PTR_SIZEOF);
			C.memmove (szUsername, new long /*int*/[] {userPtr}, C.PTR_SIZEOF);
			C.memmove (szPassword, new long /*int*/[] {passwordPtr}, C.PTR_SIZEOF);
			return COM.S_OK;
		}
	}

	/* no listener handled the challenge, so defer to the native dialog */
	C.memmove (hwnd, new long /*int*/[] {getShell().handle}, C.PTR_SIZEOF);
	return COM.S_OK;
}

/* IDispatch */

int GetTypeInfoCount (long /*int*/ pctinfo) {
	C.memmove (pctinfo, new int[] {0}, 4);
	return COM.S_OK;
}

int GetTypeInfo (int iTInfo, int lcid, long /*int*/ ppTInfo) {
	return COM.S_OK;
}

int GetIDsOfNames (int riid, long /*int*/ rgszNames, int cNames, int lcid, long /*int*/ rgDispId) {
    long /*int*/[] ptr = new long /*int*/[1];
    OS.MoveMemory (ptr, rgszNames, C.PTR_SIZEOF);
    int length = OS.wcslen (ptr[0]);
    char[] buffer = new char[length];
    OS.MoveMemory (buffer, ptr[0], length * 2);
    String functionName = String.valueOf (buffer);
    int result = COM.S_OK;
    int[] ids = new int[cNames];	/* DISPIDs */
    if (functionName.equals ("callJava")) { //$NON-NLS-1$
	    for (int i = 0; i < cNames; i++) {
	        ids[i] = i + 1;
	    }
    } else {
    	result = COM.DISP_E_UNKNOWNNAME;
	    for (int i = 0; i < cNames; i++) {
	        ids[i] = COM.DISPID_UNKNOWN;
	    }
    }
    OS.MoveMemory (rgDispId, ids, cNames * 4);
	return result;
}

int Invoke (int dispIdMember, long /*int*/ riid, int lcid, int dwFlags, long /*int*/ pDispParams, long /*int*/ pVarResult, long /*int*/ pExcepInfo, long /*int*/ pArgErr) {
	IE ie = (IE)((Browser)getParent ().getParent ()).webBrowser;
	Map<Integer, BrowserFunction> functions = ie.functions;
	if (functions == null) {
		if (pVarResult != 0) {
			OS.MoveMemory (pVarResult, new long /*int*/[] {0}, C.PTR_SIZEOF);
		}
		return COM.S_OK;
	}

	DISPPARAMS dispParams = new DISPPARAMS ();
	COM.MoveMemory (dispParams, pDispParams, DISPPARAMS.sizeof);
	if (dispParams.cArgs != 3) {
		if (pVarResult != 0) {
			OS.MoveMemory (pVarResult, new long /*int*/[] {0}, C.PTR_SIZEOF);
		}
		return COM.S_OK;
	}

	long /*int*/ ptr = dispParams.rgvarg + 2 * Variant.sizeof;
	Variant variant = Variant.win32_new (ptr);
	if (variant.getType () != COM.VT_I4) {
		variant.dispose ();
		if (pVarResult != 0) {
			OS.MoveMemory (pVarResult, new long /*int*/[] {0}, C.PTR_SIZEOF);
		}
		return COM.S_OK;
	}
	int index = variant.getInt ();
	variant.dispose ();
	if (index <= 0) {
		if (pVarResult != 0) {
			OS.MoveMemory (pVarResult, new long /*int*/[] {0}, C.PTR_SIZEOF);
		}
		return COM.S_OK;
	}

	ptr = dispParams.rgvarg + Variant.sizeof;
	variant = Variant.win32_new (ptr);
	int type = variant.getType ();
	if (type != COM.VT_BSTR) {
		variant.dispose ();
		if (pVarResult != 0) {
			OS.MoveMemory (pVarResult, new long /*int*/[] {0}, C.PTR_SIZEOF);
		}
		return COM.S_OK;
	}
	String token = variant.getString ();
	variant.dispose ();

	variant = Variant.win32_new (dispParams.rgvarg);
	BrowserFunction function = functions.get (index);
	Object returnValue = null;
	if (function != null && token.equals (function.token)) {
		try {
			Object temp = convertToJava (variant);
			if (temp instanceof Object[]) {
				Object[] args = (Object[])temp;
				try {
					returnValue = function.function (args);
				} catch (Exception e) {
					/* exception during function invocation */
					returnValue = WebBrowser.CreateErrorString (e.getLocalizedMessage ());
				}
			}
		} catch (IllegalArgumentException e) {
			/* invalid argument value type */
			if (function.isEvaluate) {
				/* notify the function so that a java exception can be thrown */
				function.function (new String[] {WebBrowser.CreateErrorString (new SWTException (SWT.ERROR_INVALID_RETURN_VALUE).getLocalizedMessage ())});
			}
			returnValue = WebBrowser.CreateErrorString (e.getLocalizedMessage ());
		}
	}
	variant.dispose ();

	if (pVarResult != 0) {
		try {
			variant = convertToJS (returnValue);
		} catch (SWTException e) {
			/* invalid return value type */
			variant = convertToJS (WebBrowser.CreateErrorString (e.getLocalizedMessage ()));
		}
		Variant.win32_copy (pVarResult, variant);
		variant.dispose ();
	}
	return COM.S_OK;
}

Object convertToJava (Variant variant) {
	switch (variant.getType ()) {
		case OLE.VT_EMPTY:
		case OLE.VT_NULL: return null;
		case OLE.VT_BSTR: return variant.getString ();
		case OLE.VT_BOOL: return new Boolean (variant.getBoolean ());
		case OLE.VT_I2:
		case OLE.VT_I4:
		case OLE.VT_I8:
		case OLE.VT_R4:
		case OLE.VT_R8:
			return new Double (variant.getDouble ());
		case OLE.VT_DISPATCH: {
			Object[] args = null;
			OleAutomation auto = variant.getAutomation ();
			TYPEATTR typeattr = auto.getTypeInfoAttributes ();
			if (typeattr != null) {
				GUID guid = new GUID ();
				guid.Data1 = typeattr.guid_Data1;
				guid.Data2 = typeattr.guid_Data2;
				guid.Data3 = typeattr.guid_Data3;
				guid.Data4 = typeattr.guid_Data4;
				if (COM.IsEqualGUID (guid, COM.IIDIJScriptTypeInfo)) {
					int[] rgdispid = auto.getIDsOfNames (new String[] {"length"}); //$NON-NLS-1$
					if (rgdispid != null) {
						Variant varLength = auto.getProperty (rgdispid[0]);
						int length = varLength.getInt ();
						varLength.dispose ();
						args = new Object[length];
						for (int i = 0; i < length; i++) {
							rgdispid = auto.getIDsOfNames (new String[] {String.valueOf (i)});
							if (rgdispid != null) {
								Variant current = auto.getProperty (rgdispid[0]);
								try {
									args[i] = convertToJava (current);
									current.dispose ();
								} catch (IllegalArgumentException e) {
									/* invalid argument value type */
									current.dispose ();
									auto.dispose ();
									throw e;
								}
							}
						}
					}
				} else {
					auto.dispose ();
					SWT.error (SWT.ERROR_INVALID_ARGUMENT);
				}
			}
			auto.dispose ();
			return args;
		}
	}
	SWT.error (SWT.ERROR_INVALID_ARGUMENT);
	return null;
}

Variant convertToJS (Object value) {
	if (value == null) {
		return Variant.NULL;
	}
	if (value instanceof String) {
		return new Variant ((String)value);
	}
	if (value instanceof Boolean) {
		return new Variant (((Boolean)value).booleanValue ());
	}
	if (value instanceof Number) {
		return new Variant (((Number)value).doubleValue ());
	}
	if (value instanceof Object[]) {
		/* get IHTMLDocument2 */
		IE browser = (IE)((Browser)getParent ().getParent ()).webBrowser;
		OleAutomation auto = browser.auto;
		int[] rgdispid = auto.getIDsOfNames (new String[] {"Document"}); //$NON-NLS-1$
		if (rgdispid == null) return new Variant ();
		Variant pVarResult = auto.getProperty (rgdispid[0]);
		if (pVarResult == null) return new Variant ();
		if (pVarResult.getType () == COM.VT_EMPTY) {
			pVarResult.dispose ();
			return new Variant ();
		}
		OleAutomation document = pVarResult.getAutomation ();
		pVarResult.dispose ();

		/* get IHTMLWindow2 */
		rgdispid = document.getIDsOfNames (new String[] {"parentWindow"}); //$NON-NLS-1$
		if (rgdispid == null) {
			document.dispose ();
			return new Variant ();
		}
		pVarResult = document.getProperty (rgdispid[0]);
		if (pVarResult == null || pVarResult.getType () == COM.VT_EMPTY) {
			if (pVarResult != null) pVarResult.dispose ();
			document.dispose ();
			return new Variant ();
		}
		OleAutomation ihtmlWindow2 = pVarResult.getAutomation ();
		pVarResult.dispose ();
		document.dispose ();

		/* create a new JS array to be returned */
		rgdispid = ihtmlWindow2.getIDsOfNames (new String[] {"Array"}); //$NON-NLS-1$
		if (rgdispid == null) {
			ihtmlWindow2.dispose ();
			return new Variant ();
		}
		Variant arrayType = ihtmlWindow2.getProperty (rgdispid[0]);
		ihtmlWindow2.dispose ();
		IDispatch arrayTypeDispatch = arrayType.getDispatch ();
		long /*int*/[] result = new long /*int*/[1];
		int rc = arrayTypeDispatch.QueryInterface (COM.IIDIDispatchEx, result);
		arrayType.dispose ();
		if (rc != COM.S_OK) return new Variant ();

		IDispatchEx arrayTypeDispatchEx = new IDispatchEx (result[0]);
		result[0] = 0;
		long /*int*/ resultPtr = OS.GlobalAlloc (OS.GMEM_FIXED | OS.GMEM_ZEROINIT, VARIANT.sizeof);
		DISPPARAMS params = new DISPPARAMS ();
		rc = arrayTypeDispatchEx.InvokeEx (COM.DISPID_VALUE, COM.LOCALE_USER_DEFAULT, COM.DISPATCH_CONSTRUCT, params, resultPtr, null, 0);
		if (rc != COM.S_OK) {
			OS.GlobalFree (resultPtr);
			return new Variant ();
		}
		Variant array = Variant.win32_new (resultPtr);
		OS.GlobalFree (resultPtr);

		/* populate the array */
		Object[] arrayValue = (Object[])value;
		int length = arrayValue.length;
		auto = array.getAutomation ();
		int[] rgdispids = auto.getIDsOfNames (new String[] {"push"}); //$NON-NLS-1$
		if (rgdispids != null) {
			for (int i = 0; i < length; i++) {
				Object currentObject = arrayValue[i];
				try {
					Variant variant = convertToJS (currentObject);
					auto.invoke (rgdispids[0], new Variant[] {variant});
					variant.dispose ();
				} catch (SWTException e) {
					/* invalid return value type */
					auto.dispose ();
					array.dispose ();
					throw e;
				}
			}
		}
		auto.dispose ();
		return array;
	}
	SWT.error (SWT.ERROR_INVALID_RETURN_VALUE);
	return null;
}

}
