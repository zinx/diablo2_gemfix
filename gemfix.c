#include "common.h"

#include "util.h"

#include "d2.h"
#include "gemfix.h"

#define MOD_NAME "gemfix"
#define AUTHOR "Zinx Verituse <zinx@zenthought.org>"
#define FULL_NAME MOD_NAME " by "AUTHOR" [built @ "__DATE__" "__TIME__"]"

WINAPI BOOL DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{
	int ret;
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		ret = patch_d2();
		if (!ret)
			LOG(FULL_NAME " loaded");
		else
			LOG(FULL_NAME " failed to load (%d)", ret);
		return !ret;
	case DLL_PROCESS_DETACH:
		unpatch_d2();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
