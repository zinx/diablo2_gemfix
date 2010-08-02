#include "common.h"
#include <patch.h>

#include "d2.h"
#include "gemfix.h"

FASTCALL void (*D2Lang_10005_112a)(int idx);

extern void GemFixSplitLines1_1_112a();
extern void GemFixSplitLines1_2_112a();
extern void GemFixSplitLines1_3_112a();
extern void GemFixSplitLines2_1_112a();
CDECL void GemFixSplitLines2_112a();

#define HEADER "d2_112a_client.h"
#define NAME d2client_112a
#include "declPatch.h"

FASTCALL void GemFixSplitLines1_112a(LPWSTR str)
{
	int i;
	if (!str) return;
	for (i = 0; str[i]; ++i)
		;
	while (--i >= 0 && str[i] == L'\n')
		;
	if (str[++i] == L'\n')
		str[++i] = L'\0';
}

CDECL void GemFixSplitLines2_112a(LPWSTR str)
{
	int i;
	if (!str) return;
	for (i = 0; str[i]; ++i)
		;
	while (--i >= 0 && str[i] == L'\n')
		;
	if (i >= 0)
		str[++i] = L'\n';
	str[++i] = L'\n';
	str[++i] = L'\0';
}

int patch_112a(void)
{
	return patch_d2client_112a();
}

void unpatch_112a(void)
{
	unpatch_d2client_112a();
}
