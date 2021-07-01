/*******************************************************************************
 * Copyright (c) 2000, 2019 IBM Corporation and others.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    IBM Corporation - initial API and implementation
 *******************************************************************************/

/* Note: This file was auto-generated by org.eclipse.swt.tools.internal.JNIGenerator */
/* DO NOT EDIT - your changes will be lost. */

#include "swt.h"
#include "com_structs.h"

#ifndef NO_CAUUID
typedef struct CAUUID_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cElems, pElems;
} CAUUID_FID_CACHE;

CAUUID_FID_CACHE CAUUIDFc;

void cacheCAUUIDFields(JNIEnv *env, jobject lpObject)
{
	if (CAUUIDFc.cached) return;
	CAUUIDFc.clazz = (*env)->GetObjectClass(env, lpObject);
	CAUUIDFc.cElems = (*env)->GetFieldID(env, CAUUIDFc.clazz, "cElems", "I");
	CAUUIDFc.pElems = (*env)->GetFieldID(env, CAUUIDFc.clazz, "pElems", "J");
	CAUUIDFc.cached = 1;
}

CAUUID *getCAUUIDFields(JNIEnv *env, jobject lpObject, CAUUID *lpStruct)
{
	if (!CAUUIDFc.cached) cacheCAUUIDFields(env, lpObject);
	lpStruct->cElems = (*env)->GetIntField(env, lpObject, CAUUIDFc.cElems);
	lpStruct->pElems = (GUID FAR *)(*env)->GetLongField(env, lpObject, CAUUIDFc.pElems);
	return lpStruct;
}

void setCAUUIDFields(JNIEnv *env, jobject lpObject, CAUUID *lpStruct)
{
	if (!CAUUIDFc.cached) cacheCAUUIDFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, CAUUIDFc.cElems, (jint)lpStruct->cElems);
	(*env)->SetLongField(env, lpObject, CAUUIDFc.pElems, (jlong)lpStruct->pElems);
}
#endif

#ifndef NO_CONTROLINFO
typedef struct CONTROLINFO_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cb, hAccel, cAccel, dwFlags;
} CONTROLINFO_FID_CACHE;

CONTROLINFO_FID_CACHE CONTROLINFOFc;

void cacheCONTROLINFOFields(JNIEnv *env, jobject lpObject)
{
	if (CONTROLINFOFc.cached) return;
	CONTROLINFOFc.clazz = (*env)->GetObjectClass(env, lpObject);
	CONTROLINFOFc.cb = (*env)->GetFieldID(env, CONTROLINFOFc.clazz, "cb", "I");
	CONTROLINFOFc.hAccel = (*env)->GetFieldID(env, CONTROLINFOFc.clazz, "hAccel", "J");
	CONTROLINFOFc.cAccel = (*env)->GetFieldID(env, CONTROLINFOFc.clazz, "cAccel", "S");
	CONTROLINFOFc.dwFlags = (*env)->GetFieldID(env, CONTROLINFOFc.clazz, "dwFlags", "I");
	CONTROLINFOFc.cached = 1;
}

CONTROLINFO *getCONTROLINFOFields(JNIEnv *env, jobject lpObject, CONTROLINFO *lpStruct)
{
	if (!CONTROLINFOFc.cached) cacheCONTROLINFOFields(env, lpObject);
	lpStruct->cb = (*env)->GetIntField(env, lpObject, CONTROLINFOFc.cb);
	lpStruct->hAccel = (HACCEL)(*env)->GetLongField(env, lpObject, CONTROLINFOFc.hAccel);
	lpStruct->cAccel = (*env)->GetShortField(env, lpObject, CONTROLINFOFc.cAccel);
	lpStruct->dwFlags = (*env)->GetIntField(env, lpObject, CONTROLINFOFc.dwFlags);
	return lpStruct;
}

void setCONTROLINFOFields(JNIEnv *env, jobject lpObject, CONTROLINFO *lpStruct)
{
	if (!CONTROLINFOFc.cached) cacheCONTROLINFOFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, CONTROLINFOFc.cb, (jint)lpStruct->cb);
	(*env)->SetLongField(env, lpObject, CONTROLINFOFc.hAccel, (jlong)lpStruct->hAccel);
	(*env)->SetShortField(env, lpObject, CONTROLINFOFc.cAccel, (jshort)lpStruct->cAccel);
	(*env)->SetIntField(env, lpObject, CONTROLINFOFc.dwFlags, (jint)lpStruct->dwFlags);
}
#endif

#ifndef NO_DISPPARAMS
typedef struct DISPPARAMS_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID rgvarg, rgdispidNamedArgs, cArgs, cNamedArgs;
} DISPPARAMS_FID_CACHE;

DISPPARAMS_FID_CACHE DISPPARAMSFc;

void cacheDISPPARAMSFields(JNIEnv *env, jobject lpObject)
{
	if (DISPPARAMSFc.cached) return;
	DISPPARAMSFc.clazz = (*env)->GetObjectClass(env, lpObject);
	DISPPARAMSFc.rgvarg = (*env)->GetFieldID(env, DISPPARAMSFc.clazz, "rgvarg", "J");
	DISPPARAMSFc.rgdispidNamedArgs = (*env)->GetFieldID(env, DISPPARAMSFc.clazz, "rgdispidNamedArgs", "J");
	DISPPARAMSFc.cArgs = (*env)->GetFieldID(env, DISPPARAMSFc.clazz, "cArgs", "I");
	DISPPARAMSFc.cNamedArgs = (*env)->GetFieldID(env, DISPPARAMSFc.clazz, "cNamedArgs", "I");
	DISPPARAMSFc.cached = 1;
}

DISPPARAMS *getDISPPARAMSFields(JNIEnv *env, jobject lpObject, DISPPARAMS *lpStruct)
{
	if (!DISPPARAMSFc.cached) cacheDISPPARAMSFields(env, lpObject);
	lpStruct->rgvarg = (VARIANTARG FAR *)(*env)->GetLongField(env, lpObject, DISPPARAMSFc.rgvarg);
	lpStruct->rgdispidNamedArgs = (DISPID FAR *)(*env)->GetLongField(env, lpObject, DISPPARAMSFc.rgdispidNamedArgs);
	lpStruct->cArgs = (*env)->GetIntField(env, lpObject, DISPPARAMSFc.cArgs);
	lpStruct->cNamedArgs = (*env)->GetIntField(env, lpObject, DISPPARAMSFc.cNamedArgs);
	return lpStruct;
}

void setDISPPARAMSFields(JNIEnv *env, jobject lpObject, DISPPARAMS *lpStruct)
{
	if (!DISPPARAMSFc.cached) cacheDISPPARAMSFields(env, lpObject);
	(*env)->SetLongField(env, lpObject, DISPPARAMSFc.rgvarg, (jlong)lpStruct->rgvarg);
	(*env)->SetLongField(env, lpObject, DISPPARAMSFc.rgdispidNamedArgs, (jlong)lpStruct->rgdispidNamedArgs);
	(*env)->SetIntField(env, lpObject, DISPPARAMSFc.cArgs, (jint)lpStruct->cArgs);
	(*env)->SetIntField(env, lpObject, DISPPARAMSFc.cNamedArgs, (jint)lpStruct->cNamedArgs);
}
#endif

#ifndef NO_EXCEPINFO
typedef struct EXCEPINFO_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID wCode, wReserved, bstrSource, bstrDescription, bstrHelpFile, dwHelpContext, pvReserved, pfnDeferredFillIn, scode;
} EXCEPINFO_FID_CACHE;

EXCEPINFO_FID_CACHE EXCEPINFOFc;

void cacheEXCEPINFOFields(JNIEnv *env, jobject lpObject)
{
	if (EXCEPINFOFc.cached) return;
	EXCEPINFOFc.clazz = (*env)->GetObjectClass(env, lpObject);
	EXCEPINFOFc.wCode = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "wCode", "S");
	EXCEPINFOFc.wReserved = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "wReserved", "S");
	EXCEPINFOFc.bstrSource = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "bstrSource", "J");
	EXCEPINFOFc.bstrDescription = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "bstrDescription", "J");
	EXCEPINFOFc.bstrHelpFile = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "bstrHelpFile", "J");
	EXCEPINFOFc.dwHelpContext = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "dwHelpContext", "I");
	EXCEPINFOFc.pvReserved = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "pvReserved", "J");
	EXCEPINFOFc.pfnDeferredFillIn = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "pfnDeferredFillIn", "J");
	EXCEPINFOFc.scode = (*env)->GetFieldID(env, EXCEPINFOFc.clazz, "scode", "I");
	EXCEPINFOFc.cached = 1;
}

EXCEPINFO *getEXCEPINFOFields(JNIEnv *env, jobject lpObject, EXCEPINFO *lpStruct)
{
	if (!EXCEPINFOFc.cached) cacheEXCEPINFOFields(env, lpObject);
	lpStruct->wCode = (*env)->GetShortField(env, lpObject, EXCEPINFOFc.wCode);
	lpStruct->wReserved = (*env)->GetShortField(env, lpObject, EXCEPINFOFc.wReserved);
	lpStruct->bstrSource = (BSTR)(*env)->GetLongField(env, lpObject, EXCEPINFOFc.bstrSource);
	lpStruct->bstrDescription = (BSTR)(*env)->GetLongField(env, lpObject, EXCEPINFOFc.bstrDescription);
	lpStruct->bstrHelpFile = (BSTR)(*env)->GetLongField(env, lpObject, EXCEPINFOFc.bstrHelpFile);
	lpStruct->dwHelpContext = (*env)->GetIntField(env, lpObject, EXCEPINFOFc.dwHelpContext);
	lpStruct->pvReserved = (void FAR *)(*env)->GetLongField(env, lpObject, EXCEPINFOFc.pvReserved);
	lpStruct->pfnDeferredFillIn = (HRESULT (STDAPICALLTYPE FAR* )(struct tagEXCEPINFO FAR*))(*env)->GetLongField(env, lpObject, EXCEPINFOFc.pfnDeferredFillIn);
	lpStruct->scode = (*env)->GetIntField(env, lpObject, EXCEPINFOFc.scode);
	return lpStruct;
}

void setEXCEPINFOFields(JNIEnv *env, jobject lpObject, EXCEPINFO *lpStruct)
{
	if (!EXCEPINFOFc.cached) cacheEXCEPINFOFields(env, lpObject);
	(*env)->SetShortField(env, lpObject, EXCEPINFOFc.wCode, (jshort)lpStruct->wCode);
	(*env)->SetShortField(env, lpObject, EXCEPINFOFc.wReserved, (jshort)lpStruct->wReserved);
	(*env)->SetLongField(env, lpObject, EXCEPINFOFc.bstrSource, (jlong)lpStruct->bstrSource);
	(*env)->SetLongField(env, lpObject, EXCEPINFOFc.bstrDescription, (jlong)lpStruct->bstrDescription);
	(*env)->SetLongField(env, lpObject, EXCEPINFOFc.bstrHelpFile, (jlong)lpStruct->bstrHelpFile);
	(*env)->SetIntField(env, lpObject, EXCEPINFOFc.dwHelpContext, (jint)lpStruct->dwHelpContext);
	(*env)->SetLongField(env, lpObject, EXCEPINFOFc.pvReserved, (jlong)lpStruct->pvReserved);
	(*env)->SetLongField(env, lpObject, EXCEPINFOFc.pfnDeferredFillIn, (jlong)lpStruct->pfnDeferredFillIn);
	(*env)->SetIntField(env, lpObject, EXCEPINFOFc.scode, (jint)lpStruct->scode);
}
#endif

#ifndef NO_FORMATETC
typedef struct FORMATETC_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cfFormat, ptd, dwAspect, lindex, tymed;
} FORMATETC_FID_CACHE;

FORMATETC_FID_CACHE FORMATETCFc;

void cacheFORMATETCFields(JNIEnv *env, jobject lpObject)
{
	if (FORMATETCFc.cached) return;
	FORMATETCFc.clazz = (*env)->GetObjectClass(env, lpObject);
	FORMATETCFc.cfFormat = (*env)->GetFieldID(env, FORMATETCFc.clazz, "cfFormat", "I");
	FORMATETCFc.ptd = (*env)->GetFieldID(env, FORMATETCFc.clazz, "ptd", "J");
	FORMATETCFc.dwAspect = (*env)->GetFieldID(env, FORMATETCFc.clazz, "dwAspect", "I");
	FORMATETCFc.lindex = (*env)->GetFieldID(env, FORMATETCFc.clazz, "lindex", "I");
	FORMATETCFc.tymed = (*env)->GetFieldID(env, FORMATETCFc.clazz, "tymed", "I");
	FORMATETCFc.cached = 1;
}

FORMATETC *getFORMATETCFields(JNIEnv *env, jobject lpObject, FORMATETC *lpStruct)
{
	if (!FORMATETCFc.cached) cacheFORMATETCFields(env, lpObject);
	lpStruct->cfFormat = (CLIPFORMAT)(*env)->GetIntField(env, lpObject, FORMATETCFc.cfFormat);
	lpStruct->ptd = (DVTARGETDEVICE *)(*env)->GetLongField(env, lpObject, FORMATETCFc.ptd);
	lpStruct->dwAspect = (*env)->GetIntField(env, lpObject, FORMATETCFc.dwAspect);
	lpStruct->lindex = (*env)->GetIntField(env, lpObject, FORMATETCFc.lindex);
	lpStruct->tymed = (*env)->GetIntField(env, lpObject, FORMATETCFc.tymed);
	return lpStruct;
}

void setFORMATETCFields(JNIEnv *env, jobject lpObject, FORMATETC *lpStruct)
{
	if (!FORMATETCFc.cached) cacheFORMATETCFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, FORMATETCFc.cfFormat, (jint)lpStruct->cfFormat);
	(*env)->SetLongField(env, lpObject, FORMATETCFc.ptd, (jlong)lpStruct->ptd);
	(*env)->SetIntField(env, lpObject, FORMATETCFc.dwAspect, (jint)lpStruct->dwAspect);
	(*env)->SetIntField(env, lpObject, FORMATETCFc.lindex, (jint)lpStruct->lindex);
	(*env)->SetIntField(env, lpObject, FORMATETCFc.tymed, (jint)lpStruct->tymed);
}
#endif

#ifndef NO_FUNCDESC
typedef struct FUNCDESC_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID memid, lprgscode, lprgelemdescParam, funckind, invkind, callconv, cParams, cParamsOpt, oVft, cScodes, elemdescFunc_tdesc_union, elemdescFunc_tdesc_vt, elemdescFunc_paramdesc_pparamdescex, elemdescFunc_paramdesc_wParamFlags, wFuncFlags;
} FUNCDESC_FID_CACHE;

FUNCDESC_FID_CACHE FUNCDESCFc;

void cacheFUNCDESCFields(JNIEnv *env, jobject lpObject)
{
	if (FUNCDESCFc.cached) return;
	FUNCDESCFc.clazz = (*env)->GetObjectClass(env, lpObject);
	FUNCDESCFc.memid = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "memid", "I");
	FUNCDESCFc.lprgscode = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "lprgscode", "J");
	FUNCDESCFc.lprgelemdescParam = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "lprgelemdescParam", "J");
	FUNCDESCFc.funckind = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "funckind", "I");
	FUNCDESCFc.invkind = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "invkind", "I");
	FUNCDESCFc.callconv = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "callconv", "I");
	FUNCDESCFc.cParams = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "cParams", "S");
	FUNCDESCFc.cParamsOpt = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "cParamsOpt", "S");
	FUNCDESCFc.oVft = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "oVft", "S");
	FUNCDESCFc.cScodes = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "cScodes", "S");
	FUNCDESCFc.elemdescFunc_tdesc_union = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "elemdescFunc_tdesc_union", "J");
	FUNCDESCFc.elemdescFunc_tdesc_vt = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "elemdescFunc_tdesc_vt", "S");
	FUNCDESCFc.elemdescFunc_paramdesc_pparamdescex = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "elemdescFunc_paramdesc_pparamdescex", "J");
	FUNCDESCFc.elemdescFunc_paramdesc_wParamFlags = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "elemdescFunc_paramdesc_wParamFlags", "S");
	FUNCDESCFc.wFuncFlags = (*env)->GetFieldID(env, FUNCDESCFc.clazz, "wFuncFlags", "S");
	FUNCDESCFc.cached = 1;
}

FUNCDESC *getFUNCDESCFields(JNIEnv *env, jobject lpObject, FUNCDESC *lpStruct)
{
	if (!FUNCDESCFc.cached) cacheFUNCDESCFields(env, lpObject);
	lpStruct->memid = (MEMBERID)(*env)->GetIntField(env, lpObject, FUNCDESCFc.memid);
	lpStruct->lprgscode = (SCODE FAR *)(*env)->GetLongField(env, lpObject, FUNCDESCFc.lprgscode);
	lpStruct->lprgelemdescParam = (ELEMDESC FAR *)(*env)->GetLongField(env, lpObject, FUNCDESCFc.lprgelemdescParam);
	lpStruct->funckind = (FUNCKIND)(*env)->GetIntField(env, lpObject, FUNCDESCFc.funckind);
	lpStruct->invkind = (INVOKEKIND)(*env)->GetIntField(env, lpObject, FUNCDESCFc.invkind);
	lpStruct->callconv = (CALLCONV)(*env)->GetIntField(env, lpObject, FUNCDESCFc.callconv);
	lpStruct->cParams = (*env)->GetShortField(env, lpObject, FUNCDESCFc.cParams);
	lpStruct->cParamsOpt = (*env)->GetShortField(env, lpObject, FUNCDESCFc.cParamsOpt);
	lpStruct->oVft = (*env)->GetShortField(env, lpObject, FUNCDESCFc.oVft);
	lpStruct->cScodes = (*env)->GetShortField(env, lpObject, FUNCDESCFc.cScodes);
	lpStruct->elemdescFunc.tdesc.lptdesc = (struct FARSTRUCT tagTYPEDESC FAR* )(*env)->GetLongField(env, lpObject, FUNCDESCFc.elemdescFunc_tdesc_union);
	lpStruct->elemdescFunc.tdesc.vt = (*env)->GetShortField(env, lpObject, FUNCDESCFc.elemdescFunc_tdesc_vt);
	lpStruct->elemdescFunc.paramdesc.pparamdescex = (LPPARAMDESCEX)(*env)->GetLongField(env, lpObject, FUNCDESCFc.elemdescFunc_paramdesc_pparamdescex);
	lpStruct->elemdescFunc.paramdesc.wParamFlags = (*env)->GetShortField(env, lpObject, FUNCDESCFc.elemdescFunc_paramdesc_wParamFlags);
	lpStruct->wFuncFlags = (*env)->GetShortField(env, lpObject, FUNCDESCFc.wFuncFlags);
	return lpStruct;
}

void setFUNCDESCFields(JNIEnv *env, jobject lpObject, FUNCDESC *lpStruct)
{
	if (!FUNCDESCFc.cached) cacheFUNCDESCFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, FUNCDESCFc.memid, (jint)lpStruct->memid);
	(*env)->SetLongField(env, lpObject, FUNCDESCFc.lprgscode, (jlong)lpStruct->lprgscode);
	(*env)->SetLongField(env, lpObject, FUNCDESCFc.lprgelemdescParam, (jlong)lpStruct->lprgelemdescParam);
	(*env)->SetIntField(env, lpObject, FUNCDESCFc.funckind, (jint)lpStruct->funckind);
	(*env)->SetIntField(env, lpObject, FUNCDESCFc.invkind, (jint)lpStruct->invkind);
	(*env)->SetIntField(env, lpObject, FUNCDESCFc.callconv, (jint)lpStruct->callconv);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.cParams, (jshort)lpStruct->cParams);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.cParamsOpt, (jshort)lpStruct->cParamsOpt);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.oVft, (jshort)lpStruct->oVft);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.cScodes, (jshort)lpStruct->cScodes);
	(*env)->SetLongField(env, lpObject, FUNCDESCFc.elemdescFunc_tdesc_union, (jlong)lpStruct->elemdescFunc.tdesc.lptdesc);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.elemdescFunc_tdesc_vt, (jshort)lpStruct->elemdescFunc.tdesc.vt);
	(*env)->SetLongField(env, lpObject, FUNCDESCFc.elemdescFunc_paramdesc_pparamdescex, (jlong)lpStruct->elemdescFunc.paramdesc.pparamdescex);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.elemdescFunc_paramdesc_wParamFlags, (jshort)lpStruct->elemdescFunc.paramdesc.wParamFlags);
	(*env)->SetShortField(env, lpObject, FUNCDESCFc.wFuncFlags, (jshort)lpStruct->wFuncFlags);
}
#endif

#ifndef NO_GUID
typedef struct GUID_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID Data1, Data2, Data3, Data4;
} GUID_FID_CACHE;

GUID_FID_CACHE GUIDFc;

void cacheGUIDFields(JNIEnv *env, jobject lpObject)
{
	if (GUIDFc.cached) return;
	GUIDFc.clazz = (*env)->GetObjectClass(env, lpObject);
	GUIDFc.Data1 = (*env)->GetFieldID(env, GUIDFc.clazz, "Data1", "I");
	GUIDFc.Data2 = (*env)->GetFieldID(env, GUIDFc.clazz, "Data2", "S");
	GUIDFc.Data3 = (*env)->GetFieldID(env, GUIDFc.clazz, "Data3", "S");
	GUIDFc.Data4 = (*env)->GetFieldID(env, GUIDFc.clazz, "Data4", "[B");
	GUIDFc.cached = 1;
}

GUID *getGUIDFields(JNIEnv *env, jobject lpObject, GUID *lpStruct)
{
	if (!GUIDFc.cached) cacheGUIDFields(env, lpObject);
	lpStruct->Data1 = (*env)->GetIntField(env, lpObject, GUIDFc.Data1);
	lpStruct->Data2 = (*env)->GetShortField(env, lpObject, GUIDFc.Data2);
	lpStruct->Data3 = (*env)->GetShortField(env, lpObject, GUIDFc.Data3);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, GUIDFc.Data4);
	(*env)->GetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->Data4), (jbyte *)lpStruct->Data4);
	}
	return lpStruct;
}

void setGUIDFields(JNIEnv *env, jobject lpObject, GUID *lpStruct)
{
	if (!GUIDFc.cached) cacheGUIDFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, GUIDFc.Data1, (jint)lpStruct->Data1);
	(*env)->SetShortField(env, lpObject, GUIDFc.Data2, (jshort)lpStruct->Data2);
	(*env)->SetShortField(env, lpObject, GUIDFc.Data3, (jshort)lpStruct->Data3);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, GUIDFc.Data4);
	(*env)->SetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->Data4), (jbyte *)lpStruct->Data4);
	}
}
#endif

#ifndef NO_LICINFO
typedef struct LICINFO_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cbLicInfo, fRuntimeKeyAvail, fLicVerified;
} LICINFO_FID_CACHE;

LICINFO_FID_CACHE LICINFOFc;

void cacheLICINFOFields(JNIEnv *env, jobject lpObject)
{
	if (LICINFOFc.cached) return;
	LICINFOFc.clazz = (*env)->GetObjectClass(env, lpObject);
	LICINFOFc.cbLicInfo = (*env)->GetFieldID(env, LICINFOFc.clazz, "cbLicInfo", "I");
	LICINFOFc.fRuntimeKeyAvail = (*env)->GetFieldID(env, LICINFOFc.clazz, "fRuntimeKeyAvail", "Z");
	LICINFOFc.fLicVerified = (*env)->GetFieldID(env, LICINFOFc.clazz, "fLicVerified", "Z");
	LICINFOFc.cached = 1;
}

LICINFO *getLICINFOFields(JNIEnv *env, jobject lpObject, LICINFO *lpStruct)
{
	if (!LICINFOFc.cached) cacheLICINFOFields(env, lpObject);
	lpStruct->cbLicInfo = (*env)->GetIntField(env, lpObject, LICINFOFc.cbLicInfo);
	lpStruct->fRuntimeKeyAvail = (*env)->GetBooleanField(env, lpObject, LICINFOFc.fRuntimeKeyAvail);
	lpStruct->fLicVerified = (*env)->GetBooleanField(env, lpObject, LICINFOFc.fLicVerified);
	return lpStruct;
}

void setLICINFOFields(JNIEnv *env, jobject lpObject, LICINFO *lpStruct)
{
	if (!LICINFOFc.cached) cacheLICINFOFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, LICINFOFc.cbLicInfo, (jint)lpStruct->cbLicInfo);
	(*env)->SetBooleanField(env, lpObject, LICINFOFc.fRuntimeKeyAvail, (jboolean)lpStruct->fRuntimeKeyAvail);
	(*env)->SetBooleanField(env, lpObject, LICINFOFc.fLicVerified, (jboolean)lpStruct->fLicVerified);
}
#endif

#ifndef NO_OLECMD
typedef struct OLECMD_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cmdID, cmdf;
} OLECMD_FID_CACHE;

OLECMD_FID_CACHE OLECMDFc;

void cacheOLECMDFields(JNIEnv *env, jobject lpObject)
{
	if (OLECMDFc.cached) return;
	OLECMDFc.clazz = (*env)->GetObjectClass(env, lpObject);
	OLECMDFc.cmdID = (*env)->GetFieldID(env, OLECMDFc.clazz, "cmdID", "I");
	OLECMDFc.cmdf = (*env)->GetFieldID(env, OLECMDFc.clazz, "cmdf", "I");
	OLECMDFc.cached = 1;
}

OLECMD *getOLECMDFields(JNIEnv *env, jobject lpObject, OLECMD *lpStruct)
{
	if (!OLECMDFc.cached) cacheOLECMDFields(env, lpObject);
	lpStruct->cmdID = (*env)->GetIntField(env, lpObject, OLECMDFc.cmdID);
	lpStruct->cmdf = (*env)->GetIntField(env, lpObject, OLECMDFc.cmdf);
	return lpStruct;
}

void setOLECMDFields(JNIEnv *env, jobject lpObject, OLECMD *lpStruct)
{
	if (!OLECMDFc.cached) cacheOLECMDFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, OLECMDFc.cmdID, (jint)lpStruct->cmdID);
	(*env)->SetIntField(env, lpObject, OLECMDFc.cmdf, (jint)lpStruct->cmdf);
}
#endif

#ifndef NO_OLEINPLACEFRAMEINFO
typedef struct OLEINPLACEFRAMEINFO_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cb, fMDIApp, hwndFrame, haccel, cAccelEntries;
} OLEINPLACEFRAMEINFO_FID_CACHE;

OLEINPLACEFRAMEINFO_FID_CACHE OLEINPLACEFRAMEINFOFc;

void cacheOLEINPLACEFRAMEINFOFields(JNIEnv *env, jobject lpObject)
{
	if (OLEINPLACEFRAMEINFOFc.cached) return;
	OLEINPLACEFRAMEINFOFc.clazz = (*env)->GetObjectClass(env, lpObject);
	OLEINPLACEFRAMEINFOFc.cb = (*env)->GetFieldID(env, OLEINPLACEFRAMEINFOFc.clazz, "cb", "I");
	OLEINPLACEFRAMEINFOFc.fMDIApp = (*env)->GetFieldID(env, OLEINPLACEFRAMEINFOFc.clazz, "fMDIApp", "I");
	OLEINPLACEFRAMEINFOFc.hwndFrame = (*env)->GetFieldID(env, OLEINPLACEFRAMEINFOFc.clazz, "hwndFrame", "J");
	OLEINPLACEFRAMEINFOFc.haccel = (*env)->GetFieldID(env, OLEINPLACEFRAMEINFOFc.clazz, "haccel", "J");
	OLEINPLACEFRAMEINFOFc.cAccelEntries = (*env)->GetFieldID(env, OLEINPLACEFRAMEINFOFc.clazz, "cAccelEntries", "I");
	OLEINPLACEFRAMEINFOFc.cached = 1;
}

OLEINPLACEFRAMEINFO *getOLEINPLACEFRAMEINFOFields(JNIEnv *env, jobject lpObject, OLEINPLACEFRAMEINFO *lpStruct)
{
	if (!OLEINPLACEFRAMEINFOFc.cached) cacheOLEINPLACEFRAMEINFOFields(env, lpObject);
	lpStruct->cb = (*env)->GetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.cb);
	lpStruct->fMDIApp = (*env)->GetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.fMDIApp);
	lpStruct->hwndFrame = (HWND)(*env)->GetLongField(env, lpObject, OLEINPLACEFRAMEINFOFc.hwndFrame);
	lpStruct->haccel = (HACCEL)(*env)->GetLongField(env, lpObject, OLEINPLACEFRAMEINFOFc.haccel);
	lpStruct->cAccelEntries = (*env)->GetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.cAccelEntries);
	return lpStruct;
}

void setOLEINPLACEFRAMEINFOFields(JNIEnv *env, jobject lpObject, OLEINPLACEFRAMEINFO *lpStruct)
{
	if (!OLEINPLACEFRAMEINFOFc.cached) cacheOLEINPLACEFRAMEINFOFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.cb, (jint)lpStruct->cb);
	(*env)->SetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.fMDIApp, (jint)lpStruct->fMDIApp);
	(*env)->SetLongField(env, lpObject, OLEINPLACEFRAMEINFOFc.hwndFrame, (jlong)lpStruct->hwndFrame);
	(*env)->SetLongField(env, lpObject, OLEINPLACEFRAMEINFOFc.haccel, (jlong)lpStruct->haccel);
	(*env)->SetIntField(env, lpObject, OLEINPLACEFRAMEINFOFc.cAccelEntries, (jint)lpStruct->cAccelEntries);
}
#endif

#ifndef NO_STGMEDIUM
typedef struct STGMEDIUM_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID tymed, unionField, pUnkForRelease;
} STGMEDIUM_FID_CACHE;

STGMEDIUM_FID_CACHE STGMEDIUMFc;

void cacheSTGMEDIUMFields(JNIEnv *env, jobject lpObject)
{
	if (STGMEDIUMFc.cached) return;
	STGMEDIUMFc.clazz = (*env)->GetObjectClass(env, lpObject);
	STGMEDIUMFc.tymed = (*env)->GetFieldID(env, STGMEDIUMFc.clazz, "tymed", "I");
	STGMEDIUMFc.unionField = (*env)->GetFieldID(env, STGMEDIUMFc.clazz, "unionField", "J");
	STGMEDIUMFc.pUnkForRelease = (*env)->GetFieldID(env, STGMEDIUMFc.clazz, "pUnkForRelease", "J");
	STGMEDIUMFc.cached = 1;
}

STGMEDIUM *getSTGMEDIUMFields(JNIEnv *env, jobject lpObject, STGMEDIUM *lpStruct)
{
	if (!STGMEDIUMFc.cached) cacheSTGMEDIUMFields(env, lpObject);
	lpStruct->tymed = (*env)->GetIntField(env, lpObject, STGMEDIUMFc.tymed);
	lpStruct->hGlobal = (HGLOBAL)(*env)->GetLongField(env, lpObject, STGMEDIUMFc.unionField);
	lpStruct->pUnkForRelease = (IUnknown *)(*env)->GetLongField(env, lpObject, STGMEDIUMFc.pUnkForRelease);
	return lpStruct;
}

void setSTGMEDIUMFields(JNIEnv *env, jobject lpObject, STGMEDIUM *lpStruct)
{
	if (!STGMEDIUMFc.cached) cacheSTGMEDIUMFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, STGMEDIUMFc.tymed, (jint)lpStruct->tymed);
	(*env)->SetLongField(env, lpObject, STGMEDIUMFc.unionField, (jlong)lpStruct->hGlobal);
	(*env)->SetLongField(env, lpObject, STGMEDIUMFc.pUnkForRelease, (jlong)lpStruct->pUnkForRelease);
}
#endif

#ifndef NO_TYPEATTR
typedef struct TYPEATTR_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID guid_Data1, guid_Data2, guid_Data3, guid_Data4, lcid, dwReserved, memidConstructor, memidDestructor, lpstrSchema, cbSizeInstance, typekind, cFuncs, cVars, cImplTypes, cbSizeVft, cbAlignment, wTypeFlags, wMajorVerNum, wMinorVerNum, tdescAlias_unionField, tdescAlias_vt, idldescType_dwReserved, idldescType_wIDLFlags;
} TYPEATTR_FID_CACHE;

TYPEATTR_FID_CACHE TYPEATTRFc;

void cacheTYPEATTRFields(JNIEnv *env, jobject lpObject)
{
	if (TYPEATTRFc.cached) return;
	TYPEATTRFc.clazz = (*env)->GetObjectClass(env, lpObject);
	TYPEATTRFc.guid_Data1 = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "guid_Data1", "I");
	TYPEATTRFc.guid_Data2 = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "guid_Data2", "S");
	TYPEATTRFc.guid_Data3 = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "guid_Data3", "S");
	TYPEATTRFc.guid_Data4 = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "guid_Data4", "[B");
	TYPEATTRFc.lcid = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "lcid", "I");
	TYPEATTRFc.dwReserved = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "dwReserved", "I");
	TYPEATTRFc.memidConstructor = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "memidConstructor", "I");
	TYPEATTRFc.memidDestructor = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "memidDestructor", "I");
	TYPEATTRFc.lpstrSchema = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "lpstrSchema", "J");
	TYPEATTRFc.cbSizeInstance = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cbSizeInstance", "I");
	TYPEATTRFc.typekind = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "typekind", "I");
	TYPEATTRFc.cFuncs = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cFuncs", "S");
	TYPEATTRFc.cVars = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cVars", "S");
	TYPEATTRFc.cImplTypes = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cImplTypes", "S");
	TYPEATTRFc.cbSizeVft = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cbSizeVft", "S");
	TYPEATTRFc.cbAlignment = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "cbAlignment", "S");
	TYPEATTRFc.wTypeFlags = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "wTypeFlags", "S");
	TYPEATTRFc.wMajorVerNum = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "wMajorVerNum", "S");
	TYPEATTRFc.wMinorVerNum = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "wMinorVerNum", "S");
	TYPEATTRFc.tdescAlias_unionField = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "tdescAlias_unionField", "J");
	TYPEATTRFc.tdescAlias_vt = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "tdescAlias_vt", "S");
	TYPEATTRFc.idldescType_dwReserved = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "idldescType_dwReserved", "I");
	TYPEATTRFc.idldescType_wIDLFlags = (*env)->GetFieldID(env, TYPEATTRFc.clazz, "idldescType_wIDLFlags", "S");
	TYPEATTRFc.cached = 1;
}

TYPEATTR *getTYPEATTRFields(JNIEnv *env, jobject lpObject, TYPEATTR *lpStruct)
{
	if (!TYPEATTRFc.cached) cacheTYPEATTRFields(env, lpObject);
	lpStruct->guid.Data1 = (*env)->GetIntField(env, lpObject, TYPEATTRFc.guid_Data1);
	lpStruct->guid.Data2 = (*env)->GetShortField(env, lpObject, TYPEATTRFc.guid_Data2);
	lpStruct->guid.Data3 = (*env)->GetShortField(env, lpObject, TYPEATTRFc.guid_Data3);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, TYPEATTRFc.guid_Data4);
	(*env)->GetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->guid.Data4), (jbyte *)lpStruct->guid.Data4);
	}
	lpStruct->lcid = (*env)->GetIntField(env, lpObject, TYPEATTRFc.lcid);
	lpStruct->dwReserved = (*env)->GetIntField(env, lpObject, TYPEATTRFc.dwReserved);
	lpStruct->memidConstructor = (*env)->GetIntField(env, lpObject, TYPEATTRFc.memidConstructor);
	lpStruct->memidDestructor = (*env)->GetIntField(env, lpObject, TYPEATTRFc.memidDestructor);
	lpStruct->lpstrSchema = (OLECHAR FAR *)(*env)->GetLongField(env, lpObject, TYPEATTRFc.lpstrSchema);
	lpStruct->cbSizeInstance = (*env)->GetIntField(env, lpObject, TYPEATTRFc.cbSizeInstance);
	lpStruct->typekind = (*env)->GetIntField(env, lpObject, TYPEATTRFc.typekind);
	lpStruct->cFuncs = (*env)->GetShortField(env, lpObject, TYPEATTRFc.cFuncs);
	lpStruct->cVars = (*env)->GetShortField(env, lpObject, TYPEATTRFc.cVars);
	lpStruct->cImplTypes = (*env)->GetShortField(env, lpObject, TYPEATTRFc.cImplTypes);
	lpStruct->cbSizeVft = (*env)->GetShortField(env, lpObject, TYPEATTRFc.cbSizeVft);
	lpStruct->cbAlignment = (*env)->GetShortField(env, lpObject, TYPEATTRFc.cbAlignment);
	lpStruct->wTypeFlags = (*env)->GetShortField(env, lpObject, TYPEATTRFc.wTypeFlags);
	lpStruct->wMajorVerNum = (*env)->GetShortField(env, lpObject, TYPEATTRFc.wMajorVerNum);
	lpStruct->wMinorVerNum = (*env)->GetShortField(env, lpObject, TYPEATTRFc.wMinorVerNum);
	lpStruct->tdescAlias.lptdesc = (struct FARSTRUCT tagTYPEDESC FAR *)(*env)->GetLongField(env, lpObject, TYPEATTRFc.tdescAlias_unionField);
	lpStruct->tdescAlias.vt = (*env)->GetShortField(env, lpObject, TYPEATTRFc.tdescAlias_vt);
	lpStruct->idldescType.dwReserved = (*env)->GetIntField(env, lpObject, TYPEATTRFc.idldescType_dwReserved);
	lpStruct->idldescType.wIDLFlags = (*env)->GetShortField(env, lpObject, TYPEATTRFc.idldescType_wIDLFlags);
	return lpStruct;
}

void setTYPEATTRFields(JNIEnv *env, jobject lpObject, TYPEATTR *lpStruct)
{
	if (!TYPEATTRFc.cached) cacheTYPEATTRFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.guid_Data1, (jint)lpStruct->guid.Data1);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.guid_Data2, (jshort)lpStruct->guid.Data2);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.guid_Data3, (jshort)lpStruct->guid.Data3);
	{
	jbyteArray lpObject1 = (jbyteArray)(*env)->GetObjectField(env, lpObject, TYPEATTRFc.guid_Data4);
	(*env)->SetByteArrayRegion(env, lpObject1, 0, sizeof(lpStruct->guid.Data4), (jbyte *)lpStruct->guid.Data4);
	}
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.lcid, (jint)lpStruct->lcid);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.dwReserved, (jint)lpStruct->dwReserved);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.memidConstructor, (jint)lpStruct->memidConstructor);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.memidDestructor, (jint)lpStruct->memidDestructor);
	(*env)->SetLongField(env, lpObject, TYPEATTRFc.lpstrSchema, (jlong)lpStruct->lpstrSchema);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.cbSizeInstance, (jint)lpStruct->cbSizeInstance);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.typekind, (jint)lpStruct->typekind);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.cFuncs, (jshort)lpStruct->cFuncs);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.cVars, (jshort)lpStruct->cVars);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.cImplTypes, (jshort)lpStruct->cImplTypes);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.cbSizeVft, (jshort)lpStruct->cbSizeVft);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.cbAlignment, (jshort)lpStruct->cbAlignment);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.wTypeFlags, (jshort)lpStruct->wTypeFlags);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.wMajorVerNum, (jshort)lpStruct->wMajorVerNum);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.wMinorVerNum, (jshort)lpStruct->wMinorVerNum);
	(*env)->SetLongField(env, lpObject, TYPEATTRFc.tdescAlias_unionField, (jlong)lpStruct->tdescAlias.lptdesc);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.tdescAlias_vt, (jshort)lpStruct->tdescAlias.vt);
	(*env)->SetIntField(env, lpObject, TYPEATTRFc.idldescType_dwReserved, (jint)lpStruct->idldescType.dwReserved);
	(*env)->SetShortField(env, lpObject, TYPEATTRFc.idldescType_wIDLFlags, (jshort)lpStruct->idldescType.wIDLFlags);
}
#endif

#ifndef NO_VARDESC
typedef struct VARDESC_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID memid, lpstrSchema, oInst, elemdescVar_tdesc_union, elemdescVar_tdesc_vt, elemdescVar_paramdesc_pparamdescex, elemdescVar_paramdesc_wParamFlags, wVarFlags, varkind;
} VARDESC_FID_CACHE;

VARDESC_FID_CACHE VARDESCFc;

void cacheVARDESCFields(JNIEnv *env, jobject lpObject)
{
	if (VARDESCFc.cached) return;
	VARDESCFc.clazz = (*env)->GetObjectClass(env, lpObject);
	VARDESCFc.memid = (*env)->GetFieldID(env, VARDESCFc.clazz, "memid", "I");
	VARDESCFc.lpstrSchema = (*env)->GetFieldID(env, VARDESCFc.clazz, "lpstrSchema", "J");
	VARDESCFc.oInst = (*env)->GetFieldID(env, VARDESCFc.clazz, "oInst", "I");
	VARDESCFc.elemdescVar_tdesc_union = (*env)->GetFieldID(env, VARDESCFc.clazz, "elemdescVar_tdesc_union", "J");
	VARDESCFc.elemdescVar_tdesc_vt = (*env)->GetFieldID(env, VARDESCFc.clazz, "elemdescVar_tdesc_vt", "S");
	VARDESCFc.elemdescVar_paramdesc_pparamdescex = (*env)->GetFieldID(env, VARDESCFc.clazz, "elemdescVar_paramdesc_pparamdescex", "J");
	VARDESCFc.elemdescVar_paramdesc_wParamFlags = (*env)->GetFieldID(env, VARDESCFc.clazz, "elemdescVar_paramdesc_wParamFlags", "S");
	VARDESCFc.wVarFlags = (*env)->GetFieldID(env, VARDESCFc.clazz, "wVarFlags", "S");
	VARDESCFc.varkind = (*env)->GetFieldID(env, VARDESCFc.clazz, "varkind", "I");
	VARDESCFc.cached = 1;
}

VARDESC *getVARDESCFields(JNIEnv *env, jobject lpObject, VARDESC *lpStruct)
{
	if (!VARDESCFc.cached) cacheVARDESCFields(env, lpObject);
	lpStruct->memid = (*env)->GetIntField(env, lpObject, VARDESCFc.memid);
	lpStruct->lpstrSchema = (OLECHAR FAR *)(*env)->GetLongField(env, lpObject, VARDESCFc.lpstrSchema);
	lpStruct->oInst = (*env)->GetIntField(env, lpObject, VARDESCFc.oInst);
	lpStruct->elemdescVar.tdesc.lptdesc = (struct FARSTRUCT tagTYPEDESC FAR *)(*env)->GetLongField(env, lpObject, VARDESCFc.elemdescVar_tdesc_union);
	lpStruct->elemdescVar.tdesc.vt = (*env)->GetShortField(env, lpObject, VARDESCFc.elemdescVar_tdesc_vt);
	lpStruct->elemdescVar.paramdesc.pparamdescex = (LPPARAMDESCEX)(*env)->GetLongField(env, lpObject, VARDESCFc.elemdescVar_paramdesc_pparamdescex);
	lpStruct->elemdescVar.paramdesc.wParamFlags = (*env)->GetShortField(env, lpObject, VARDESCFc.elemdescVar_paramdesc_wParamFlags);
	lpStruct->wVarFlags = (*env)->GetShortField(env, lpObject, VARDESCFc.wVarFlags);
	lpStruct->varkind = (*env)->GetIntField(env, lpObject, VARDESCFc.varkind);
	return lpStruct;
}

void setVARDESCFields(JNIEnv *env, jobject lpObject, VARDESC *lpStruct)
{
	if (!VARDESCFc.cached) cacheVARDESCFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, VARDESCFc.memid, (jint)lpStruct->memid);
	(*env)->SetLongField(env, lpObject, VARDESCFc.lpstrSchema, (jlong)lpStruct->lpstrSchema);
	(*env)->SetIntField(env, lpObject, VARDESCFc.oInst, (jint)lpStruct->oInst);
	(*env)->SetLongField(env, lpObject, VARDESCFc.elemdescVar_tdesc_union, (jlong)lpStruct->elemdescVar.tdesc.lptdesc);
	(*env)->SetShortField(env, lpObject, VARDESCFc.elemdescVar_tdesc_vt, (jshort)lpStruct->elemdescVar.tdesc.vt);
	(*env)->SetLongField(env, lpObject, VARDESCFc.elemdescVar_paramdesc_pparamdescex, (jlong)lpStruct->elemdescVar.paramdesc.pparamdescex);
	(*env)->SetShortField(env, lpObject, VARDESCFc.elemdescVar_paramdesc_wParamFlags, (jshort)lpStruct->elemdescVar.paramdesc.wParamFlags);
	(*env)->SetShortField(env, lpObject, VARDESCFc.wVarFlags, (jshort)lpStruct->wVarFlags);
	(*env)->SetIntField(env, lpObject, VARDESCFc.varkind, (jint)lpStruct->varkind);
}
#endif

#ifndef NO_VARIANT
typedef struct VARIANT_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID vt, wReserved1, wReserved2, wReserved3, lVal;
} VARIANT_FID_CACHE;

VARIANT_FID_CACHE VARIANTFc;

void cacheVARIANTFields(JNIEnv *env, jobject lpObject)
{
	if (VARIANTFc.cached) return;
	VARIANTFc.clazz = (*env)->GetObjectClass(env, lpObject);
	VARIANTFc.vt = (*env)->GetFieldID(env, VARIANTFc.clazz, "vt", "S");
	VARIANTFc.wReserved1 = (*env)->GetFieldID(env, VARIANTFc.clazz, "wReserved1", "S");
	VARIANTFc.wReserved2 = (*env)->GetFieldID(env, VARIANTFc.clazz, "wReserved2", "S");
	VARIANTFc.wReserved3 = (*env)->GetFieldID(env, VARIANTFc.clazz, "wReserved3", "S");
	VARIANTFc.lVal = (*env)->GetFieldID(env, VARIANTFc.clazz, "lVal", "I");
	VARIANTFc.cached = 1;
}

VARIANT *getVARIANTFields(JNIEnv *env, jobject lpObject, VARIANT *lpStruct)
{
	if (!VARIANTFc.cached) cacheVARIANTFields(env, lpObject);
	lpStruct->vt = (*env)->GetShortField(env, lpObject, VARIANTFc.vt);
	lpStruct->wReserved1 = (*env)->GetShortField(env, lpObject, VARIANTFc.wReserved1);
	lpStruct->wReserved2 = (*env)->GetShortField(env, lpObject, VARIANTFc.wReserved2);
	lpStruct->wReserved3 = (*env)->GetShortField(env, lpObject, VARIANTFc.wReserved3);
	lpStruct->lVal = (*env)->GetIntField(env, lpObject, VARIANTFc.lVal);
	return lpStruct;
}

void setVARIANTFields(JNIEnv *env, jobject lpObject, VARIANT *lpStruct)
{
	if (!VARIANTFc.cached) cacheVARIANTFields(env, lpObject);
	(*env)->SetShortField(env, lpObject, VARIANTFc.vt, (jshort)lpStruct->vt);
	(*env)->SetShortField(env, lpObject, VARIANTFc.wReserved1, (jshort)lpStruct->wReserved1);
	(*env)->SetShortField(env, lpObject, VARIANTFc.wReserved2, (jshort)lpStruct->wReserved2);
	(*env)->SetShortField(env, lpObject, VARIANTFc.wReserved3, (jshort)lpStruct->wReserved3);
	(*env)->SetIntField(env, lpObject, VARIANTFc.lVal, (jint)lpStruct->lVal);
}
#endif