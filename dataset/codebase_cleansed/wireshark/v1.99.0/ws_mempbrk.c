const guint8 *
_ws_mempbrk(const guint8* haystack, size_t haystacklen, const guint8 *needles)
{
gchar tmp[256] = { 0 };
const guint8 *haystack_end;
while (*needles)
tmp[*needles++] = 1;
haystack_end = haystack + haystacklen;
while (haystack < haystack_end) {
if (tmp[*haystack])
return haystack;
haystack++;
}
return NULL;
}
WS_DLL_PUBLIC const guint8 *
ws_mempbrk(const guint8* haystack, size_t haystacklen, const guint8 *needles)
{
#ifdef HAVE_SSE4_2
static int have_sse42 = -1;
#endif
if (*needles == 0)
return NULL;
#ifdef HAVE_SSE4_2
if G_UNLIKELY(have_sse42 < 0)
have_sse42 = ws_cpuid_sse42();
if (haystacklen >= 16 && have_sse42)
return _ws_mempbrk_sse42(haystack, haystacklen, needles);
#endif
return _ws_mempbrk(haystack, haystacklen, needles);
}
