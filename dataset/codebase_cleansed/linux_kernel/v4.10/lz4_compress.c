static inline int lz4_compressctx(void *ctx,
const char *source,
char *dest,
int isize,
int maxoutputsize)
{
HTYPE *hashtable = (HTYPE *)ctx;
const u8 *ip = (u8 *)source;
#if LZ4_ARCH64
const BYTE * const base = ip;
#else
const int base = 0;
#endif
const u8 *anchor = ip;
const u8 *const iend = ip + isize;
const u8 *const mflimit = iend - MFLIMIT;
#define MATCHLIMIT (iend - LASTLITERALS)
u8 *op = (u8 *) dest;
u8 *const oend = op + maxoutputsize;
int length;
const int skipstrength = SKIPSTRENGTH;
u32 forwardh;
int lastrun;
if (isize < MINLENGTH)
goto _last_literals;
memset((void *)hashtable, 0, LZ4_MEM_COMPRESS);
hashtable[LZ4_HASH_VALUE(ip)] = ip - base;
ip++;
forwardh = LZ4_HASH_VALUE(ip);
for (;;) {
int findmatchattempts = (1U << skipstrength) + 3;
const u8 *forwardip = ip;
const u8 *ref;
u8 *token;
do {
u32 h = forwardh;
int step = findmatchattempts++ >> skipstrength;
ip = forwardip;
forwardip = ip + step;
if (unlikely(forwardip > mflimit))
goto _last_literals;
forwardh = LZ4_HASH_VALUE(forwardip);
ref = base + hashtable[h];
hashtable[h] = ip - base;
} while ((ref < ip - MAX_DISTANCE) || (A32(ref) != A32(ip)));
while ((ip > anchor) && (ref > (u8 *)source) &&
unlikely(ip[-1] == ref[-1])) {
ip--;
ref--;
}
length = (int)(ip - anchor);
token = op++;
if (unlikely(op + length + (2 + 1 + LASTLITERALS) +
(length >> 8) > oend))
return 0;
if (length >= (int)RUN_MASK) {
int len;
*token = (RUN_MASK << ML_BITS);
len = length - RUN_MASK;
for (; len > 254 ; len -= 255)
*op++ = 255;
*op++ = (u8)len;
} else
*token = (length << ML_BITS);
LZ4_BLINDCOPY(anchor, op, length);
_next_match:
LZ4_WRITE_LITTLEENDIAN_16(op, (u16)(ip - ref));
ip += MINMATCH;
ref += MINMATCH;
anchor = ip;
while (likely(ip < MATCHLIMIT - (STEPSIZE - 1))) {
#if LZ4_ARCH64
u64 diff = A64(ref) ^ A64(ip);
#else
u32 diff = A32(ref) ^ A32(ip);
#endif
if (!diff) {
ip += STEPSIZE;
ref += STEPSIZE;
continue;
}
ip += LZ4_NBCOMMONBYTES(diff);
goto _endcount;
}
#if LZ4_ARCH64
if ((ip < (MATCHLIMIT - 3)) && (A32(ref) == A32(ip))) {
ip += 4;
ref += 4;
}
#endif
if ((ip < (MATCHLIMIT - 1)) && (A16(ref) == A16(ip))) {
ip += 2;
ref += 2;
}
if ((ip < MATCHLIMIT) && (*ref == *ip))
ip++;
_endcount:
length = (int)(ip - anchor);
if (unlikely(op + (1 + LASTLITERALS) + (length >> 8) > oend))
return 0;
if (length >= (int)ML_MASK) {
*token += ML_MASK;
length -= ML_MASK;
for (; length > 509 ; length -= 510) {
*op++ = 255;
*op++ = 255;
}
if (length > 254) {
length -= 255;
*op++ = 255;
}
*op++ = (u8)length;
} else
*token += length;
if (ip > mflimit) {
anchor = ip;
break;
}
hashtable[LZ4_HASH_VALUE(ip-2)] = ip - 2 - base;
ref = base + hashtable[LZ4_HASH_VALUE(ip)];
hashtable[LZ4_HASH_VALUE(ip)] = ip - base;
if ((ref > ip - (MAX_DISTANCE + 1)) && (A32(ref) == A32(ip))) {
token = op++;
*token = 0;
goto _next_match;
}
anchor = ip++;
forwardh = LZ4_HASH_VALUE(ip);
}
_last_literals:
lastrun = (int)(iend - anchor);
if (((char *)op - dest) + lastrun + 1
+ ((lastrun + 255 - RUN_MASK) / 255) > (u32)maxoutputsize)
return 0;
if (lastrun >= (int)RUN_MASK) {
*op++ = (RUN_MASK << ML_BITS);
lastrun -= RUN_MASK;
for (; lastrun > 254 ; lastrun -= 255)
*op++ = 255;
*op++ = (u8)lastrun;
} else
*op++ = (lastrun << ML_BITS);
memcpy(op, anchor, iend - anchor);
op += iend - anchor;
return (int)(((char *)op) - dest);
}
static inline int lz4_compress64kctx(void *ctx,
const char *source,
char *dest,
int isize,
int maxoutputsize)
{
u16 *hashtable = (u16 *)ctx;
const u8 *ip = (u8 *) source;
const u8 *anchor = ip;
const u8 *const base = ip;
const u8 *const iend = ip + isize;
const u8 *const mflimit = iend - MFLIMIT;
#define MATCHLIMIT (iend - LASTLITERALS)
u8 *op = (u8 *) dest;
u8 *const oend = op + maxoutputsize;
int len, length;
const int skipstrength = SKIPSTRENGTH;
u32 forwardh;
int lastrun;
if (isize < MINLENGTH)
goto _last_literals;
memset((void *)hashtable, 0, LZ4_MEM_COMPRESS);
ip++;
forwardh = LZ4_HASH64K_VALUE(ip);
for (;;) {
int findmatchattempts = (1U << skipstrength) + 3;
const u8 *forwardip = ip;
const u8 *ref;
u8 *token;
do {
u32 h = forwardh;
int step = findmatchattempts++ >> skipstrength;
ip = forwardip;
forwardip = ip + step;
if (forwardip > mflimit)
goto _last_literals;
forwardh = LZ4_HASH64K_VALUE(forwardip);
ref = base + hashtable[h];
hashtable[h] = (u16)(ip - base);
} while (A32(ref) != A32(ip));
while ((ip > anchor) && (ref > (u8 *)source)
&& (ip[-1] == ref[-1])) {
ip--;
ref--;
}
length = (int)(ip - anchor);
token = op++;
if (unlikely(op + length + (2 + 1 + LASTLITERALS)
+ (length >> 8) > oend))
return 0;
if (length >= (int)RUN_MASK) {
*token = (RUN_MASK << ML_BITS);
len = length - RUN_MASK;
for (; len > 254 ; len -= 255)
*op++ = 255;
*op++ = (u8)len;
} else
*token = (length << ML_BITS);
LZ4_BLINDCOPY(anchor, op, length);
_next_match:
LZ4_WRITE_LITTLEENDIAN_16(op, (u16)(ip - ref));
ip += MINMATCH;
ref += MINMATCH;
anchor = ip;
while (ip < MATCHLIMIT - (STEPSIZE - 1)) {
#if LZ4_ARCH64
u64 diff = A64(ref) ^ A64(ip);
#else
u32 diff = A32(ref) ^ A32(ip);
#endif
if (!diff) {
ip += STEPSIZE;
ref += STEPSIZE;
continue;
}
ip += LZ4_NBCOMMONBYTES(diff);
goto _endcount;
}
#if LZ4_ARCH64
if ((ip < (MATCHLIMIT - 3)) && (A32(ref) == A32(ip))) {
ip += 4;
ref += 4;
}
#endif
if ((ip < (MATCHLIMIT - 1)) && (A16(ref) == A16(ip))) {
ip += 2;
ref += 2;
}
if ((ip < MATCHLIMIT) && (*ref == *ip))
ip++;
_endcount:
len = (int)(ip - anchor);
if (unlikely(op + (1 + LASTLITERALS) + (len >> 8) > oend))
return 0;
if (len >= (int)ML_MASK) {
*token += ML_MASK;
len -= ML_MASK;
for (; len > 509 ; len -= 510) {
*op++ = 255;
*op++ = 255;
}
if (len > 254) {
len -= 255;
*op++ = 255;
}
*op++ = (u8)len;
} else
*token += len;
if (ip > mflimit) {
anchor = ip;
break;
}
hashtable[LZ4_HASH64K_VALUE(ip-2)] = (u16)(ip - 2 - base);
ref = base + hashtable[LZ4_HASH64K_VALUE(ip)];
hashtable[LZ4_HASH64K_VALUE(ip)] = (u16)(ip - base);
if (A32(ref) == A32(ip)) {
token = op++;
*token = 0;
goto _next_match;
}
anchor = ip++;
forwardh = LZ4_HASH64K_VALUE(ip);
}
_last_literals:
lastrun = (int)(iend - anchor);
if (op + lastrun + 1 + (lastrun - RUN_MASK + 255) / 255 > oend)
return 0;
if (lastrun >= (int)RUN_MASK) {
*op++ = (RUN_MASK << ML_BITS);
lastrun -= RUN_MASK;
for (; lastrun > 254 ; lastrun -= 255)
*op++ = 255;
*op++ = (u8)lastrun;
} else
*op++ = (lastrun << ML_BITS);
memcpy(op, anchor, iend - anchor);
op += iend - anchor;
return (int)(((char *)op) - dest);
}
int lz4_compress(const unsigned char *src, size_t src_len,
unsigned char *dst, size_t *dst_len, void *wrkmem)
{
int ret = -1;
int out_len = 0;
if (src_len < LZ4_64KLIMIT)
out_len = lz4_compress64kctx(wrkmem, src, dst, src_len,
lz4_compressbound(src_len));
else
out_len = lz4_compressctx(wrkmem, src, dst, src_len,
lz4_compressbound(src_len));
if (out_len < 0)
goto exit;
*dst_len = out_len;
return 0;
exit:
return ret;
}
