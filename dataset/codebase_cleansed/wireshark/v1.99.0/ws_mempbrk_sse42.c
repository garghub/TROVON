static inline __m128i
__m128i_shift_right (__m128i value, unsigned long int offset)
{
return _mm_shuffle_epi8 (value,
_mm_loadu_si128 (cast_128aligned__m128i(___m128i_shift_right + offset)));
}
const char *
_ws_mempbrk_sse42(const char *s, size_t slen, const char *a)
{
const char *aligned;
__m128i mask;
int offset;
#if __has_feature(address_sanitizer) || defined(__SANITIZE_ADDRESS__)
{
size_t length;
length = strlen(a);
if (length > 16)
return _ws_mempbrk(s, slen, a);
mask = _mm_setzero_si128();
memcpy(&mask, a, length);
}
#else
offset = (int) ((size_t) a & 15);
aligned = (const char *) ((size_t) a & -16L);
if (offset != 0)
{
int length;
mask = __m128i_shift_right(_mm_load_si128 (cast_128aligned__m128i(aligned)), offset);
length = _mm_cmpistri (mask, mask, 0x3a);
if (length == 16 - offset)
{
__m128i mask1 = _mm_load_si128 (cast_128aligned__m128i(aligned + 16));
int idx = _mm_cmpistri (mask1, mask1, 0x3a);
length += idx;
if (length > 16)
return _ws_mempbrk(s, slen, a);
if (idx != 0)
{
mask = _mm_loadu_si128 (cast_128aligned__m128i(a));
}
}
}
else
{
int length;
mask = _mm_load_si128 (cast_128aligned__m128i(a));
length = _mm_cmpistri (mask, mask, 0x3a);
if (length == 16)
{
if (a[16] != 0)
return _ws_mempbrk(s, slen, a);
}
}
#endif
offset = (int) ((size_t) s & 15);
aligned = (const char *) ((size_t) s & -16L);
if (offset != 0)
{
__m128i value = __m128i_shift_right (_mm_load_si128 (cast_128aligned__m128i(aligned)), offset);
int length = _mm_cmpistri (mask, value, 0x2);
int cflag = _mm_cmpistrc (mask, value, 0x2);
int idx = _mm_cmpistri (value, value, 0x3a);
if (cflag)
return s + length;
if (idx < 16 - offset)
{
return _ws_mempbrk(s + idx + 1, slen - idx - 1, a);
}
aligned += 16;
slen -= (16 - offset);
}
else
aligned = s;
while (slen >= 16)
{
__m128i value = _mm_load_si128 (cast_128aligned__m128i(aligned));
int idx = _mm_cmpistri (mask, value, 0x2);
int cflag = _mm_cmpistrc (mask, value, 0x2);
int zflag = _mm_cmpistrz (mask, value, 0x2);
if (cflag)
return aligned + idx;
if (zflag)
{
return _ws_mempbrk(aligned, slen, a);
}
aligned += 16;
slen -= 16;
}
return _ws_mempbrk(aligned, slen, a);
}
