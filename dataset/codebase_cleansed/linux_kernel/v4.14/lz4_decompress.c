static FORCE_INLINE int LZ4_decompress_generic(
const char * const source,
char * const dest,
int inputSize,
int outputSize,
int endOnInput,
int partialDecoding,
int targetOutputSize,
int dict,
const BYTE * const lowPrefix,
const BYTE * const dictStart,
const size_t dictSize
)
{
const BYTE *ip = (const BYTE *) source;
const BYTE * const iend = ip + inputSize;
BYTE *op = (BYTE *) dest;
BYTE * const oend = op + outputSize;
BYTE *cpy;
BYTE *oexit = op + targetOutputSize;
const BYTE * const lowLimit = lowPrefix - dictSize;
const BYTE * const dictEnd = (const BYTE *)dictStart + dictSize;
static const unsigned int dec32table[] = { 0, 1, 2, 1, 4, 4, 4, 4 };
static const int dec64table[] = { 0, 0, 0, -1, 0, 1, 2, 3 };
const int safeDecode = (endOnInput == endOnInputSize);
const int checkOffset = ((safeDecode) && (dictSize < (int)(64 * KB)));
if ((partialDecoding) && (oexit > oend - MFLIMIT))
oexit = oend - MFLIMIT;
if ((endOnInput) && (unlikely(outputSize == 0)))
return ((inputSize == 1) && (*ip == 0)) ? 0 : -1;
if ((!endOnInput) && (unlikely(outputSize == 0)))
return (*ip == 0 ? 1 : -1);
while (1) {
size_t length;
const BYTE *match;
size_t offset;
unsigned int const token = *ip++;
length = token>>ML_BITS;
if (length == RUN_MASK) {
unsigned int s;
do {
s = *ip++;
length += s;
} while (likely(endOnInput
? ip < iend - RUN_MASK
: 1) & (s == 255));
if ((safeDecode)
&& unlikely(
(size_t)(op + length) < (size_t)(op))) {
goto _output_error;
}
if ((safeDecode)
&& unlikely(
(size_t)(ip + length) < (size_t)(ip))) {
goto _output_error;
}
}
cpy = op + length;
if (((endOnInput) && ((cpy > (partialDecoding ? oexit : oend - MFLIMIT))
|| (ip + length > iend - (2 + 1 + LASTLITERALS))))
|| ((!endOnInput) && (cpy > oend - WILDCOPYLENGTH))) {
if (partialDecoding) {
if (cpy > oend) {
goto _output_error;
}
if ((endOnInput)
&& (ip + length > iend)) {
goto _output_error;
}
} else {
if ((!endOnInput)
&& (cpy != oend)) {
goto _output_error;
}
if ((endOnInput)
&& ((ip + length != iend)
|| (cpy > oend))) {
goto _output_error;
}
}
memcpy(op, ip, length);
ip += length;
op += length;
break;
}
LZ4_wildCopy(op, ip, cpy);
ip += length;
op = cpy;
offset = LZ4_readLE16(ip);
ip += 2;
match = op - offset;
if ((checkOffset) && (unlikely(match < lowLimit))) {
goto _output_error;
}
LZ4_write32(op, (U32)offset);
length = token & ML_MASK;
if (length == ML_MASK) {
unsigned int s;
do {
s = *ip++;
if ((endOnInput) && (ip > iend - LASTLITERALS))
goto _output_error;
length += s;
} while (s == 255);
if ((safeDecode)
&& unlikely(
(size_t)(op + length) < (size_t)op)) {
goto _output_error;
}
}
length += MINMATCH;
if ((dict == usingExtDict) && (match < lowPrefix)) {
if (unlikely(op + length > oend - LASTLITERALS)) {
goto _output_error;
}
if (length <= (size_t)(lowPrefix - match)) {
memmove(op, dictEnd - (lowPrefix - match),
length);
op += length;
} else {
size_t const copySize = (size_t)(lowPrefix - match);
size_t const restSize = length - copySize;
memcpy(op, dictEnd - copySize, copySize);
op += copySize;
if (restSize > (size_t)(op - lowPrefix)) {
BYTE * const endOfMatch = op + restSize;
const BYTE *copyFrom = lowPrefix;
while (op < endOfMatch)
*op++ = *copyFrom++;
} else {
memcpy(op, lowPrefix, restSize);
op += restSize;
}
}
continue;
}
cpy = op + length;
if (unlikely(offset < 8)) {
const int dec64 = dec64table[offset];
op[0] = match[0];
op[1] = match[1];
op[2] = match[2];
op[3] = match[3];
match += dec32table[offset];
memcpy(op + 4, match, 4);
match -= dec64;
} else {
LZ4_copy8(op, match);
match += 8;
}
op += 8;
if (unlikely(cpy > oend - 12)) {
BYTE * const oCopyLimit = oend - (WILDCOPYLENGTH - 1);
if (cpy > oend - LASTLITERALS) {
goto _output_error;
}
if (op < oCopyLimit) {
LZ4_wildCopy(op, match, oCopyLimit);
match += oCopyLimit - op;
op = oCopyLimit;
}
while (op < cpy)
*op++ = *match++;
} else {
LZ4_copy8(op, match);
if (length > 16)
LZ4_wildCopy(op + 8, match + 8, cpy);
}
op = cpy;
}
if (endOnInput) {
return (int) (((char *)op) - dest);
} else {
return (int) (((const char *)ip) - source);
}
_output_error:
return -1;
}
int LZ4_decompress_safe(const char *source, char *dest,
int compressedSize, int maxDecompressedSize)
{
return LZ4_decompress_generic(source, dest, compressedSize,
maxDecompressedSize, endOnInputSize, full, 0,
noDict, (BYTE *)dest, NULL, 0);
}
int LZ4_decompress_safe_partial(const char *source, char *dest,
int compressedSize, int targetOutputSize, int maxDecompressedSize)
{
return LZ4_decompress_generic(source, dest, compressedSize,
maxDecompressedSize, endOnInputSize, partial,
targetOutputSize, noDict, (BYTE *)dest, NULL, 0);
}
int LZ4_decompress_fast(const char *source, char *dest, int originalSize)
{
return LZ4_decompress_generic(source, dest, 0, originalSize,
endOnOutputSize, full, 0, withPrefix64k,
(BYTE *)(dest - 64 * KB), NULL, 64 * KB);
}
int LZ4_setStreamDecode(LZ4_streamDecode_t *LZ4_streamDecode,
const char *dictionary, int dictSize)
{
LZ4_streamDecode_t_internal *lz4sd = (LZ4_streamDecode_t_internal *) LZ4_streamDecode;
lz4sd->prefixSize = (size_t) dictSize;
lz4sd->prefixEnd = (const BYTE *) dictionary + dictSize;
lz4sd->externalDict = NULL;
lz4sd->extDictSize = 0;
return 1;
}
int LZ4_decompress_safe_continue(LZ4_streamDecode_t *LZ4_streamDecode,
const char *source, char *dest, int compressedSize, int maxOutputSize)
{
LZ4_streamDecode_t_internal *lz4sd = &LZ4_streamDecode->internal_donotuse;
int result;
if (lz4sd->prefixEnd == (BYTE *)dest) {
result = LZ4_decompress_generic(source, dest,
compressedSize,
maxOutputSize,
endOnInputSize, full, 0,
usingExtDict, lz4sd->prefixEnd - lz4sd->prefixSize,
lz4sd->externalDict,
lz4sd->extDictSize);
if (result <= 0)
return result;
lz4sd->prefixSize += result;
lz4sd->prefixEnd += result;
} else {
lz4sd->extDictSize = lz4sd->prefixSize;
lz4sd->externalDict = lz4sd->prefixEnd - lz4sd->extDictSize;
result = LZ4_decompress_generic(source, dest,
compressedSize, maxOutputSize,
endOnInputSize, full, 0,
usingExtDict, (BYTE *)dest,
lz4sd->externalDict, lz4sd->extDictSize);
if (result <= 0)
return result;
lz4sd->prefixSize = result;
lz4sd->prefixEnd = (BYTE *)dest + result;
}
return result;
}
int LZ4_decompress_fast_continue(LZ4_streamDecode_t *LZ4_streamDecode,
const char *source, char *dest, int originalSize)
{
LZ4_streamDecode_t_internal *lz4sd = &LZ4_streamDecode->internal_donotuse;
int result;
if (lz4sd->prefixEnd == (BYTE *)dest) {
result = LZ4_decompress_generic(source, dest, 0, originalSize,
endOnOutputSize, full, 0,
usingExtDict,
lz4sd->prefixEnd - lz4sd->prefixSize,
lz4sd->externalDict, lz4sd->extDictSize);
if (result <= 0)
return result;
lz4sd->prefixSize += originalSize;
lz4sd->prefixEnd += originalSize;
} else {
lz4sd->extDictSize = lz4sd->prefixSize;
lz4sd->externalDict = lz4sd->prefixEnd - lz4sd->extDictSize;
result = LZ4_decompress_generic(source, dest, 0, originalSize,
endOnOutputSize, full, 0,
usingExtDict, (BYTE *)dest,
lz4sd->externalDict, lz4sd->extDictSize);
if (result <= 0)
return result;
lz4sd->prefixSize = originalSize;
lz4sd->prefixEnd = (BYTE *)dest + originalSize;
}
return result;
}
static FORCE_INLINE int LZ4_decompress_usingDict_generic(const char *source,
char *dest, int compressedSize, int maxOutputSize, int safe,
const char *dictStart, int dictSize)
{
if (dictSize == 0)
return LZ4_decompress_generic(source, dest,
compressedSize, maxOutputSize, safe, full, 0,
noDict, (BYTE *)dest, NULL, 0);
if (dictStart + dictSize == dest) {
if (dictSize >= (int)(64 * KB - 1))
return LZ4_decompress_generic(source, dest,
compressedSize, maxOutputSize, safe, full, 0,
withPrefix64k, (BYTE *)dest - 64 * KB, NULL, 0);
return LZ4_decompress_generic(source, dest, compressedSize,
maxOutputSize, safe, full, 0, noDict,
(BYTE *)dest - dictSize, NULL, 0);
}
return LZ4_decompress_generic(source, dest, compressedSize,
maxOutputSize, safe, full, 0, usingExtDict,
(BYTE *)dest, (const BYTE *)dictStart, dictSize);
}
int LZ4_decompress_safe_usingDict(const char *source, char *dest,
int compressedSize, int maxOutputSize,
const char *dictStart, int dictSize)
{
return LZ4_decompress_usingDict_generic(source, dest,
compressedSize, maxOutputSize, 1, dictStart, dictSize);
}
int LZ4_decompress_fast_usingDict(const char *source, char *dest,
int originalSize, const char *dictStart, int dictSize)
{
return LZ4_decompress_usingDict_generic(source, dest, 0,
originalSize, 0, dictStart, dictSize);
}
