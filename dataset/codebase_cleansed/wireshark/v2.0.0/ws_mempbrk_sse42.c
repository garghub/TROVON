static inline __m128i
__m128i_shift_right (__m128i value, unsigned long int offset)
{
return _mm_shuffle_epi8 (value,
_mm_loadu_si128 (cast_128aligned__m128i(___m128i_shift_right + offset)));
}
void
ws_mempbrk_sse42_compile(ws_mempbrk_pattern* pattern, const gchar *needles)
{
size_t length = strlen(needles);
pattern->use_sse42 = ws_cpuid_sse42() && (length <= 16);
if (pattern->use_sse42) {
pattern->mask = _mm_setzero_si128();
memcpy(&(pattern->mask), needles, length);
}
}
const char *
ws_mempbrk_sse42_exec(const char *s, size_t slen, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
const char *aligned;
int offset;
offset = (int) ((size_t) s & 15);
aligned = (const char *) ((size_t) s & -16L);
if (offset != 0)
{
__m128i value = __m128i_shift_right (_mm_load_si128 (cast_128aligned__m128i(aligned)), offset);
int length = _mm_cmpistri (pattern->mask, value, 0x2);
int cflag = _mm_cmpistrc (pattern->mask, value, 0x2);
int idx = _mm_cmpistri (value, value, 0x3a);
if (cflag) {
if (found_needle)
*found_needle = *(s + length);
return s + length;
}
if (idx < 16 - offset)
{
return ws_mempbrk_portable_exec(s + idx + 1, slen - idx - 1, pattern, found_needle);
}
aligned += 16;
slen -= (16 - offset);
}
else
aligned = s;
while (slen >= 16)
{
__m128i value = _mm_load_si128 (cast_128aligned__m128i(aligned));
int idx = _mm_cmpistri (pattern->mask, value, 0x2);
int cflag = _mm_cmpistrc (pattern->mask, value, 0x2);
int zflag = _mm_cmpistrz (pattern->mask, value, 0x2);
if (cflag) {
if (found_needle)
*found_needle = *(aligned + idx);
return aligned + idx;
}
if (zflag)
{
return ws_mempbrk_portable_exec(aligned, slen, pattern, found_needle);
}
aligned += 16;
slen -= 16;
}
return ws_mempbrk_portable_exec(aligned, slen, pattern, found_needle);
}
