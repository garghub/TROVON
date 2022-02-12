void
ws_mempbrk_compile(ws_mempbrk_pattern* pattern, const gchar *needles)
{
const gchar *n = needles;
while (*n) {
pattern->patt[(int)*n] = 1;
n++;
}
#ifdef HAVE_SSE4_2
ws_mempbrk_sse42_compile(pattern, needles);
#endif
}
const guint8 *
ws_mempbrk_portable_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
const guint8 *haystack_end = haystack + haystacklen;
while (haystack < haystack_end) {
if (pattern->patt[*haystack]) {
if (found_needle)
*found_needle = *haystack;
return haystack;
}
haystack++;
}
return NULL;
}
WS_DLL_PUBLIC const guint8 *
ws_mempbrk_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
#ifdef HAVE_SSE4_2
if (haystacklen >= 16 && pattern->use_sse42)
return ws_mempbrk_sse42_exec(haystack, haystacklen, pattern, found_needle);
#endif
return ws_mempbrk_portable_exec(haystack, haystacklen, pattern, found_needle);
}
