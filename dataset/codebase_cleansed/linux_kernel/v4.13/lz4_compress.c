static FORCE_INLINE U32 LZ4_hash4(
U32 sequence,
tableType_t const tableType)
{
if (tableType == byU16)
return ((sequence * 2654435761U)
>> ((MINMATCH * 8) - (LZ4_HASHLOG + 1)));
else
return ((sequence * 2654435761U)
>> ((MINMATCH * 8) - LZ4_HASHLOG));
}
static FORCE_INLINE U32 LZ4_hash5(
U64 sequence,
tableType_t const tableType)
{
const U32 hashLog = (tableType == byU16)
? LZ4_HASHLOG + 1
: LZ4_HASHLOG;
#if LZ4_LITTLE_ENDIAN
static const U64 prime5bytes = 889523592379ULL;
return (U32)(((sequence << 24) * prime5bytes) >> (64 - hashLog));
#else
static const U64 prime8bytes = 11400714785074694791ULL;
return (U32)(((sequence >> 24) * prime8bytes) >> (64 - hashLog));
#endif
}
static FORCE_INLINE U32 LZ4_hashPosition(
const void *p,
tableType_t const tableType)
{
#if LZ4_ARCH64
if (tableType == byU32)
return LZ4_hash5(LZ4_read_ARCH(p), tableType);
#endif
return LZ4_hash4(LZ4_read32(p), tableType);
}
static void LZ4_putPositionOnHash(
const BYTE *p,
U32 h,
void *tableBase,
tableType_t const tableType,
const BYTE *srcBase)
{
switch (tableType) {
case byPtr:
{
const BYTE **hashTable = (const BYTE **)tableBase;
hashTable[h] = p;
return;
}
case byU32:
{
U32 *hashTable = (U32 *) tableBase;
hashTable[h] = (U32)(p - srcBase);
return;
}
case byU16:
{
U16 *hashTable = (U16 *) tableBase;
hashTable[h] = (U16)(p - srcBase);
return;
}
}
}
static FORCE_INLINE void LZ4_putPosition(
const BYTE *p,
void *tableBase,
tableType_t tableType,
const BYTE *srcBase)
{
U32 const h = LZ4_hashPosition(p, tableType);
LZ4_putPositionOnHash(p, h, tableBase, tableType, srcBase);
}
static const BYTE *LZ4_getPositionOnHash(
U32 h,
void *tableBase,
tableType_t tableType,
const BYTE *srcBase)
{
if (tableType == byPtr) {
const BYTE **hashTable = (const BYTE **) tableBase;
return hashTable[h];
}
if (tableType == byU32) {
const U32 * const hashTable = (U32 *) tableBase;
return hashTable[h] + srcBase;
}
{
const U16 * const hashTable = (U16 *) tableBase;
return hashTable[h] + srcBase;
}
}
static FORCE_INLINE const BYTE *LZ4_getPosition(
const BYTE *p,
void *tableBase,
tableType_t tableType,
const BYTE *srcBase)
{
U32 const h = LZ4_hashPosition(p, tableType);
return LZ4_getPositionOnHash(h, tableBase, tableType, srcBase);
}
static FORCE_INLINE int LZ4_compress_generic(
LZ4_stream_t_internal * const dictPtr,
const char * const source,
char * const dest,
const int inputSize,
const int maxOutputSize,
const limitedOutput_directive outputLimited,
const tableType_t tableType,
const dict_directive dict,
const dictIssue_directive dictIssue,
const U32 acceleration)
{
const BYTE *ip = (const BYTE *) source;
const BYTE *base;
const BYTE *lowLimit;
const BYTE * const lowRefLimit = ip - dictPtr->dictSize;
const BYTE * const dictionary = dictPtr->dictionary;
const BYTE * const dictEnd = dictionary + dictPtr->dictSize;
const size_t dictDelta = dictEnd - (const BYTE *)source;
const BYTE *anchor = (const BYTE *) source;
const BYTE * const iend = ip + inputSize;
const BYTE * const mflimit = iend - MFLIMIT;
const BYTE * const matchlimit = iend - LASTLITERALS;
BYTE *op = (BYTE *) dest;
BYTE * const olimit = op + maxOutputSize;
U32 forwardH;
size_t refDelta = 0;
if ((U32)inputSize > (U32)LZ4_MAX_INPUT_SIZE) {
return 0;
}
switch (dict) {
case noDict:
default:
base = (const BYTE *)source;
lowLimit = (const BYTE *)source;
break;
case withPrefix64k:
base = (const BYTE *)source - dictPtr->currentOffset;
lowLimit = (const BYTE *)source - dictPtr->dictSize;
break;
case usingExtDict:
base = (const BYTE *)source - dictPtr->currentOffset;
lowLimit = (const BYTE *)source;
break;
}
if ((tableType == byU16)
&& (inputSize >= LZ4_64Klimit)) {
return 0;
}
if (inputSize < LZ4_minLength) {
goto _last_literals;
}
LZ4_putPosition(ip, dictPtr->hashTable, tableType, base);
ip++;
forwardH = LZ4_hashPosition(ip, tableType);
for ( ; ; ) {
const BYTE *match;
BYTE *token;
{
const BYTE *forwardIp = ip;
unsigned int step = 1;
unsigned int searchMatchNb = acceleration << LZ4_SKIPTRIGGER;
do {
U32 const h = forwardH;
ip = forwardIp;
forwardIp += step;
step = (searchMatchNb++ >> LZ4_SKIPTRIGGER);
if (unlikely(forwardIp > mflimit))
goto _last_literals;
match = LZ4_getPositionOnHash(h,
dictPtr->hashTable,
tableType, base);
if (dict == usingExtDict) {
if (match < (const BYTE *)source) {
refDelta = dictDelta;
lowLimit = dictionary;
} else {
refDelta = 0;
lowLimit = (const BYTE *)source;
} }
forwardH = LZ4_hashPosition(forwardIp,
tableType);
LZ4_putPositionOnHash(ip, h, dictPtr->hashTable,
tableType, base);
} while (((dictIssue == dictSmall)
? (match < lowRefLimit)
: 0)
|| ((tableType == byU16)
? 0
: (match + MAX_DISTANCE < ip))
|| (LZ4_read32(match + refDelta)
!= LZ4_read32(ip)));
}
while (((ip > anchor) & (match + refDelta > lowLimit))
&& (unlikely(ip[-1] == match[refDelta - 1]))) {
ip--;
match--;
}
{
unsigned const int litLength = (unsigned int)(ip - anchor);
token = op++;
if ((outputLimited) &&
(unlikely(op + litLength +
(2 + 1 + LASTLITERALS) +
(litLength / 255) > olimit)))
return 0;
if (litLength >= RUN_MASK) {
int len = (int)litLength - RUN_MASK;
*token = (RUN_MASK << ML_BITS);
for (; len >= 255; len -= 255)
*op++ = 255;
*op++ = (BYTE)len;
} else
*token = (BYTE)(litLength << ML_BITS);
LZ4_wildCopy(op, anchor, op + litLength);
op += litLength;
}
_next_match:
LZ4_writeLE16(op, (U16)(ip - match));
op += 2;
{
unsigned int matchCode;
if ((dict == usingExtDict)
&& (lowLimit == dictionary)) {
const BYTE *limit;
match += refDelta;
limit = ip + (dictEnd - match);
if (limit > matchlimit)
limit = matchlimit;
matchCode = LZ4_count(ip + MINMATCH,
match + MINMATCH, limit);
ip += MINMATCH + matchCode;
if (ip == limit) {
unsigned const int more = LZ4_count(ip,
(const BYTE *)source,
matchlimit);
matchCode += more;
ip += more;
}
} else {
matchCode = LZ4_count(ip + MINMATCH,
match + MINMATCH, matchlimit);
ip += MINMATCH + matchCode;
}
if (outputLimited &&
(unlikely(op +
(1 + LASTLITERALS) +
(matchCode >> 8) > olimit)))
return 0;
if (matchCode >= ML_MASK) {
*token += ML_MASK;
matchCode -= ML_MASK;
LZ4_write32(op, 0xFFFFFFFF);
while (matchCode >= 4 * 255) {
op += 4;
LZ4_write32(op, 0xFFFFFFFF);
matchCode -= 4 * 255;
}
op += matchCode / 255;
*op++ = (BYTE)(matchCode % 255);
} else
*token += (BYTE)(matchCode);
}
anchor = ip;
if (ip > mflimit)
break;
LZ4_putPosition(ip - 2, dictPtr->hashTable, tableType, base);
match = LZ4_getPosition(ip, dictPtr->hashTable,
tableType, base);
if (dict == usingExtDict) {
if (match < (const BYTE *)source) {
refDelta = dictDelta;
lowLimit = dictionary;
} else {
refDelta = 0;
lowLimit = (const BYTE *)source;
}
}
LZ4_putPosition(ip, dictPtr->hashTable, tableType, base);
if (((dictIssue == dictSmall) ? (match >= lowRefLimit) : 1)
&& (match + MAX_DISTANCE >= ip)
&& (LZ4_read32(match + refDelta) == LZ4_read32(ip))) {
token = op++;
*token = 0;
goto _next_match;
}
forwardH = LZ4_hashPosition(++ip, tableType);
}
_last_literals:
{
size_t const lastRun = (size_t)(iend - anchor);
if ((outputLimited) &&
((op - (BYTE *)dest) + lastRun + 1 +
((lastRun + 255 - RUN_MASK) / 255) > (U32)maxOutputSize))
return 0;
if (lastRun >= RUN_MASK) {
size_t accumulator = lastRun - RUN_MASK;
*op++ = RUN_MASK << ML_BITS;
for (; accumulator >= 255; accumulator -= 255)
*op++ = 255;
*op++ = (BYTE) accumulator;
} else {
*op++ = (BYTE)(lastRun << ML_BITS);
}
memcpy(op, anchor, lastRun);
op += lastRun;
}
return (int) (((char *)op) - dest);
}
static int LZ4_compress_fast_extState(
void *state,
const char *source,
char *dest,
int inputSize,
int maxOutputSize,
int acceleration)
{
LZ4_stream_t_internal *ctx = &((LZ4_stream_t *)state)->internal_donotuse;
#if LZ4_ARCH64
const tableType_t tableType = byU32;
#else
const tableType_t tableType = byPtr;
#endif
LZ4_resetStream((LZ4_stream_t *)state);
if (acceleration < 1)
acceleration = LZ4_ACCELERATION_DEFAULT;
if (maxOutputSize >= LZ4_COMPRESSBOUND(inputSize)) {
if (inputSize < LZ4_64Klimit)
return LZ4_compress_generic(ctx, source,
dest, inputSize, 0,
noLimit, byU16, noDict,
noDictIssue, acceleration);
else
return LZ4_compress_generic(ctx, source,
dest, inputSize, 0,
noLimit, tableType, noDict,
noDictIssue, acceleration);
} else {
if (inputSize < LZ4_64Klimit)
return LZ4_compress_generic(ctx, source,
dest, inputSize,
maxOutputSize, limitedOutput, byU16, noDict,
noDictIssue, acceleration);
else
return LZ4_compress_generic(ctx, source,
dest, inputSize,
maxOutputSize, limitedOutput, tableType, noDict,
noDictIssue, acceleration);
}
}
int LZ4_compress_fast(const char *source, char *dest, int inputSize,
int maxOutputSize, int acceleration, void *wrkmem)
{
return LZ4_compress_fast_extState(wrkmem, source, dest, inputSize,
maxOutputSize, acceleration);
}
int LZ4_compress_default(const char *source, char *dest, int inputSize,
int maxOutputSize, void *wrkmem)
{
return LZ4_compress_fast(source, dest, inputSize,
maxOutputSize, LZ4_ACCELERATION_DEFAULT, wrkmem);
}
static int LZ4_compress_destSize_generic(
LZ4_stream_t_internal * const ctx,
const char * const src,
char * const dst,
int * const srcSizePtr,
const int targetDstSize,
const tableType_t tableType)
{
const BYTE *ip = (const BYTE *) src;
const BYTE *base = (const BYTE *) src;
const BYTE *lowLimit = (const BYTE *) src;
const BYTE *anchor = ip;
const BYTE * const iend = ip + *srcSizePtr;
const BYTE * const mflimit = iend - MFLIMIT;
const BYTE * const matchlimit = iend - LASTLITERALS;
BYTE *op = (BYTE *) dst;
BYTE * const oend = op + targetDstSize;
BYTE * const oMaxLit = op + targetDstSize - 2
- 8 - 1 ;
BYTE * const oMaxMatch = op + targetDstSize
- (LASTLITERALS + 1 );
BYTE * const oMaxSeq = oMaxLit - 1 ;
U32 forwardH;
if (targetDstSize < 1)
return 0;
if ((U32)*srcSizePtr > (U32)LZ4_MAX_INPUT_SIZE)
return 0;
if ((tableType == byU16) && (*srcSizePtr >= LZ4_64Klimit))
return 0;
if (*srcSizePtr < LZ4_minLength)
goto _last_literals;
*srcSizePtr = 0;
LZ4_putPosition(ip, ctx->hashTable, tableType, base);
ip++; forwardH = LZ4_hashPosition(ip, tableType);
for ( ; ; ) {
const BYTE *match;
BYTE *token;
{
const BYTE *forwardIp = ip;
unsigned int step = 1;
unsigned int searchMatchNb = 1 << LZ4_SKIPTRIGGER;
do {
U32 h = forwardH;
ip = forwardIp;
forwardIp += step;
step = (searchMatchNb++ >> LZ4_SKIPTRIGGER);
if (unlikely(forwardIp > mflimit))
goto _last_literals;
match = LZ4_getPositionOnHash(h, ctx->hashTable,
tableType, base);
forwardH = LZ4_hashPosition(forwardIp,
tableType);
LZ4_putPositionOnHash(ip, h,
ctx->hashTable, tableType,
base);
} while (((tableType == byU16)
? 0
: (match + MAX_DISTANCE < ip))
|| (LZ4_read32(match) != LZ4_read32(ip)));
}
while ((ip > anchor)
&& (match > lowLimit)
&& (unlikely(ip[-1] == match[-1]))) {
ip--;
match--;
}
{
unsigned int litLength = (unsigned int)(ip - anchor);
token = op++;
if (op + ((litLength + 240) / 255)
+ litLength > oMaxLit) {
op--;
goto _last_literals;
}
if (litLength >= RUN_MASK) {
unsigned int len = litLength - RUN_MASK;
*token = (RUN_MASK<<ML_BITS);
for (; len >= 255; len -= 255)
*op++ = 255;
*op++ = (BYTE)len;
} else
*token = (BYTE)(litLength << ML_BITS);
LZ4_wildCopy(op, anchor, op + litLength);
op += litLength;
}
_next_match:
LZ4_writeLE16(op, (U16)(ip - match)); op += 2;
{
size_t matchLength = LZ4_count(ip + MINMATCH,
match + MINMATCH, matchlimit);
if (op + ((matchLength + 240)/255) > oMaxMatch) {
matchLength = (15 - 1) + (oMaxMatch - op) * 255;
}
ip += MINMATCH + matchLength;
if (matchLength >= ML_MASK) {
*token += ML_MASK;
matchLength -= ML_MASK;
while (matchLength >= 255) {
matchLength -= 255;
*op++ = 255;
}
*op++ = (BYTE)matchLength;
} else
*token += (BYTE)(matchLength);
}
anchor = ip;
if (ip > mflimit)
break;
if (op > oMaxSeq)
break;
LZ4_putPosition(ip - 2, ctx->hashTable, tableType, base);
match = LZ4_getPosition(ip, ctx->hashTable, tableType, base);
LZ4_putPosition(ip, ctx->hashTable, tableType, base);
if ((match + MAX_DISTANCE >= ip)
&& (LZ4_read32(match) == LZ4_read32(ip))) {
token = op++; *token = 0;
goto _next_match;
}
forwardH = LZ4_hashPosition(++ip, tableType);
}
_last_literals:
{
size_t lastRunSize = (size_t)(iend - anchor);
if (op + 1
+ ((lastRunSize + 240) / 255)
+ lastRunSize > oend) {
lastRunSize = (oend - op) - 1;
lastRunSize -= (lastRunSize + 240) / 255;
}
ip = anchor + lastRunSize;
if (lastRunSize >= RUN_MASK) {
size_t accumulator = lastRunSize - RUN_MASK;
*op++ = RUN_MASK << ML_BITS;
for (; accumulator >= 255; accumulator -= 255)
*op++ = 255;
*op++ = (BYTE) accumulator;
} else {
*op++ = (BYTE)(lastRunSize<<ML_BITS);
}
memcpy(op, anchor, lastRunSize);
op += lastRunSize;
}
*srcSizePtr = (int) (((const char *)ip) - src);
return (int) (((char *)op) - dst);
}
static int LZ4_compress_destSize_extState(
LZ4_stream_t *state,
const char *src,
char *dst,
int *srcSizePtr,
int targetDstSize)
{
#if LZ4_ARCH64
const tableType_t tableType = byU32;
#else
const tableType_t tableType = byPtr;
#endif
LZ4_resetStream(state);
if (targetDstSize >= LZ4_COMPRESSBOUND(*srcSizePtr)) {
return LZ4_compress_fast_extState(
state, src, dst, *srcSizePtr,
targetDstSize, 1);
} else {
if (*srcSizePtr < LZ4_64Klimit)
return LZ4_compress_destSize_generic(
&state->internal_donotuse,
src, dst, srcSizePtr,
targetDstSize, byU16);
else
return LZ4_compress_destSize_generic(
&state->internal_donotuse,
src, dst, srcSizePtr,
targetDstSize, tableType);
}
}
int LZ4_compress_destSize(
const char *src,
char *dst,
int *srcSizePtr,
int targetDstSize,
void *wrkmem)
{
return LZ4_compress_destSize_extState(wrkmem, src, dst, srcSizePtr,
targetDstSize);
}
void LZ4_resetStream(LZ4_stream_t *LZ4_stream)
{
memset(LZ4_stream, 0, sizeof(LZ4_stream_t));
}
int LZ4_loadDict(LZ4_stream_t *LZ4_dict,
const char *dictionary, int dictSize)
{
LZ4_stream_t_internal *dict = &LZ4_dict->internal_donotuse;
const BYTE *p = (const BYTE *)dictionary;
const BYTE * const dictEnd = p + dictSize;
const BYTE *base;
if ((dict->initCheck)
|| (dict->currentOffset > 1 * GB)) {
LZ4_resetStream(LZ4_dict);
}
if (dictSize < (int)HASH_UNIT) {
dict->dictionary = NULL;
dict->dictSize = 0;
return 0;
}
if ((dictEnd - p) > 64 * KB)
p = dictEnd - 64 * KB;
dict->currentOffset += 64 * KB;
base = p - dict->currentOffset;
dict->dictionary = p;
dict->dictSize = (U32)(dictEnd - p);
dict->currentOffset += dict->dictSize;
while (p <= dictEnd - HASH_UNIT) {
LZ4_putPosition(p, dict->hashTable, byU32, base);
p += 3;
}
return dict->dictSize;
}
static void LZ4_renormDictT(LZ4_stream_t_internal *LZ4_dict,
const BYTE *src)
{
if ((LZ4_dict->currentOffset > 0x80000000) ||
((uptrval)LZ4_dict->currentOffset > (uptrval)src)) {
U32 const delta = LZ4_dict->currentOffset - 64 * KB;
const BYTE *dictEnd = LZ4_dict->dictionary + LZ4_dict->dictSize;
int i;
for (i = 0; i < LZ4_HASH_SIZE_U32; i++) {
if (LZ4_dict->hashTable[i] < delta)
LZ4_dict->hashTable[i] = 0;
else
LZ4_dict->hashTable[i] -= delta;
}
LZ4_dict->currentOffset = 64 * KB;
if (LZ4_dict->dictSize > 64 * KB)
LZ4_dict->dictSize = 64 * KB;
LZ4_dict->dictionary = dictEnd - LZ4_dict->dictSize;
}
}
int LZ4_saveDict(LZ4_stream_t *LZ4_dict, char *safeBuffer, int dictSize)
{
LZ4_stream_t_internal * const dict = &LZ4_dict->internal_donotuse;
const BYTE * const previousDictEnd = dict->dictionary + dict->dictSize;
if ((U32)dictSize > 64 * KB) {
dictSize = 64 * KB;
}
if ((U32)dictSize > dict->dictSize)
dictSize = dict->dictSize;
memmove(safeBuffer, previousDictEnd - dictSize, dictSize);
dict->dictionary = (const BYTE *)safeBuffer;
dict->dictSize = (U32)dictSize;
return dictSize;
}
int LZ4_compress_fast_continue(LZ4_stream_t *LZ4_stream, const char *source,
char *dest, int inputSize, int maxOutputSize, int acceleration)
{
LZ4_stream_t_internal *streamPtr = &LZ4_stream->internal_donotuse;
const BYTE * const dictEnd = streamPtr->dictionary
+ streamPtr->dictSize;
const BYTE *smallest = (const BYTE *) source;
if (streamPtr->initCheck) {
return 0;
}
if ((streamPtr->dictSize > 0) && (smallest > dictEnd))
smallest = dictEnd;
LZ4_renormDictT(streamPtr, smallest);
if (acceleration < 1)
acceleration = LZ4_ACCELERATION_DEFAULT;
{
const BYTE *sourceEnd = (const BYTE *) source + inputSize;
if ((sourceEnd > streamPtr->dictionary)
&& (sourceEnd < dictEnd)) {
streamPtr->dictSize = (U32)(dictEnd - sourceEnd);
if (streamPtr->dictSize > 64 * KB)
streamPtr->dictSize = 64 * KB;
if (streamPtr->dictSize < 4)
streamPtr->dictSize = 0;
streamPtr->dictionary = dictEnd - streamPtr->dictSize;
}
}
if (dictEnd == (const BYTE *)source) {
int result;
if ((streamPtr->dictSize < 64 * KB) &&
(streamPtr->dictSize < streamPtr->currentOffset)) {
result = LZ4_compress_generic(
streamPtr, source, dest, inputSize,
maxOutputSize, limitedOutput, byU32,
withPrefix64k, dictSmall, acceleration);
} else {
result = LZ4_compress_generic(
streamPtr, source, dest, inputSize,
maxOutputSize, limitedOutput, byU32,
withPrefix64k, noDictIssue, acceleration);
}
streamPtr->dictSize += (U32)inputSize;
streamPtr->currentOffset += (U32)inputSize;
return result;
}
{
int result;
if ((streamPtr->dictSize < 64 * KB) &&
(streamPtr->dictSize < streamPtr->currentOffset)) {
result = LZ4_compress_generic(
streamPtr, source, dest, inputSize,
maxOutputSize, limitedOutput, byU32,
usingExtDict, dictSmall, acceleration);
} else {
result = LZ4_compress_generic(
streamPtr, source, dest, inputSize,
maxOutputSize, limitedOutput, byU32,
usingExtDict, noDictIssue, acceleration);
}
streamPtr->dictionary = (const BYTE *)source;
streamPtr->dictSize = (U32)inputSize;
streamPtr->currentOffset += (U32)inputSize;
return result;
}
}
