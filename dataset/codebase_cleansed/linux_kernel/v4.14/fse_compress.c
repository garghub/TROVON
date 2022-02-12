size_t FSE_buildCTable_wksp(FSE_CTable *ct, const short *normalizedCounter, unsigned maxSymbolValue, unsigned tableLog, void *workspace, size_t workspaceSize)
{
U32 const tableSize = 1 << tableLog;
U32 const tableMask = tableSize - 1;
void *const ptr = ct;
U16 *const tableU16 = ((U16 *)ptr) + 2;
void *const FSCT = ((U32 *)ptr) + 1 + (tableLog ? tableSize >> 1 : 1);
FSE_symbolCompressionTransform *const symbolTT = (FSE_symbolCompressionTransform *)(FSCT);
U32 const step = FSE_TABLESTEP(tableSize);
U32 highThreshold = tableSize - 1;
U32 *cumul;
FSE_FUNCTION_TYPE *tableSymbol;
size_t spaceUsed32 = 0;
cumul = (U32 *)workspace + spaceUsed32;
spaceUsed32 += FSE_MAX_SYMBOL_VALUE + 2;
tableSymbol = (FSE_FUNCTION_TYPE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(sizeof(FSE_FUNCTION_TYPE) * ((size_t)1 << tableLog), sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
tableU16[-2] = (U16)tableLog;
tableU16[-1] = (U16)maxSymbolValue;
{
U32 u;
cumul[0] = 0;
for (u = 1; u <= maxSymbolValue + 1; u++) {
if (normalizedCounter[u - 1] == -1) {
cumul[u] = cumul[u - 1] + 1;
tableSymbol[highThreshold--] = (FSE_FUNCTION_TYPE)(u - 1);
} else {
cumul[u] = cumul[u - 1] + normalizedCounter[u - 1];
}
}
cumul[maxSymbolValue + 1] = tableSize + 1;
}
{
U32 position = 0;
U32 symbol;
for (symbol = 0; symbol <= maxSymbolValue; symbol++) {
int nbOccurences;
for (nbOccurences = 0; nbOccurences < normalizedCounter[symbol]; nbOccurences++) {
tableSymbol[position] = (FSE_FUNCTION_TYPE)symbol;
position = (position + step) & tableMask;
while (position > highThreshold)
position = (position + step) & tableMask;
}
}
if (position != 0)
return ERROR(GENERIC);
}
{
U32 u;
for (u = 0; u < tableSize; u++) {
FSE_FUNCTION_TYPE s = tableSymbol[u];
tableU16[cumul[s]++] = (U16)(tableSize + u);
}
}
{
unsigned total = 0;
unsigned s;
for (s = 0; s <= maxSymbolValue; s++) {
switch (normalizedCounter[s]) {
case 0: break;
case -1:
case 1:
symbolTT[s].deltaNbBits = (tableLog << 16) - (1 << tableLog);
symbolTT[s].deltaFindState = total - 1;
total++;
break;
default: {
U32 const maxBitsOut = tableLog - BIT_highbit32(normalizedCounter[s] - 1);
U32 const minStatePlus = normalizedCounter[s] << maxBitsOut;
symbolTT[s].deltaNbBits = (maxBitsOut << 16) - minStatePlus;
symbolTT[s].deltaFindState = total - normalizedCounter[s];
total += normalizedCounter[s];
}
}
}
}
return 0;
}
size_t FSE_NCountWriteBound(unsigned maxSymbolValue, unsigned tableLog)
{
size_t const maxHeaderSize = (((maxSymbolValue + 1) * tableLog) >> 3) + 3;
return maxSymbolValue ? maxHeaderSize : FSE_NCOUNTBOUND;
}
static size_t FSE_writeNCount_generic(void *header, size_t headerBufferSize, const short *normalizedCounter, unsigned maxSymbolValue, unsigned tableLog,
unsigned writeIsSafe)
{
BYTE *const ostart = (BYTE *)header;
BYTE *out = ostart;
BYTE *const oend = ostart + headerBufferSize;
int nbBits;
const int tableSize = 1 << tableLog;
int remaining;
int threshold;
U32 bitStream;
int bitCount;
unsigned charnum = 0;
int previous0 = 0;
bitStream = 0;
bitCount = 0;
bitStream += (tableLog - FSE_MIN_TABLELOG) << bitCount;
bitCount += 4;
remaining = tableSize + 1;
threshold = tableSize;
nbBits = tableLog + 1;
while (remaining > 1) {
if (previous0) {
unsigned start = charnum;
while (!normalizedCounter[charnum])
charnum++;
while (charnum >= start + 24) {
start += 24;
bitStream += 0xFFFFU << bitCount;
if ((!writeIsSafe) && (out > oend - 2))
return ERROR(dstSize_tooSmall);
out[0] = (BYTE)bitStream;
out[1] = (BYTE)(bitStream >> 8);
out += 2;
bitStream >>= 16;
}
while (charnum >= start + 3) {
start += 3;
bitStream += 3 << bitCount;
bitCount += 2;
}
bitStream += (charnum - start) << bitCount;
bitCount += 2;
if (bitCount > 16) {
if ((!writeIsSafe) && (out > oend - 2))
return ERROR(dstSize_tooSmall);
out[0] = (BYTE)bitStream;
out[1] = (BYTE)(bitStream >> 8);
out += 2;
bitStream >>= 16;
bitCount -= 16;
}
}
{
int count = normalizedCounter[charnum++];
int const max = (2 * threshold - 1) - remaining;
remaining -= count < 0 ? -count : count;
count++;
if (count >= threshold)
count += max;
bitStream += count << bitCount;
bitCount += nbBits;
bitCount -= (count < max);
previous0 = (count == 1);
if (remaining < 1)
return ERROR(GENERIC);
while (remaining < threshold)
nbBits--, threshold >>= 1;
}
if (bitCount > 16) {
if ((!writeIsSafe) && (out > oend - 2))
return ERROR(dstSize_tooSmall);
out[0] = (BYTE)bitStream;
out[1] = (BYTE)(bitStream >> 8);
out += 2;
bitStream >>= 16;
bitCount -= 16;
}
}
if ((!writeIsSafe) && (out > oend - 2))
return ERROR(dstSize_tooSmall);
out[0] = (BYTE)bitStream;
out[1] = (BYTE)(bitStream >> 8);
out += (bitCount + 7) / 8;
if (charnum > maxSymbolValue + 1)
return ERROR(GENERIC);
return (out - ostart);
}
size_t FSE_writeNCount(void *buffer, size_t bufferSize, const short *normalizedCounter, unsigned maxSymbolValue, unsigned tableLog)
{
if (tableLog > FSE_MAX_TABLELOG)
return ERROR(tableLog_tooLarge);
if (tableLog < FSE_MIN_TABLELOG)
return ERROR(GENERIC);
if (bufferSize < FSE_NCountWriteBound(maxSymbolValue, tableLog))
return FSE_writeNCount_generic(buffer, bufferSize, normalizedCounter, maxSymbolValue, tableLog, 0);
return FSE_writeNCount_generic(buffer, bufferSize, normalizedCounter, maxSymbolValue, tableLog, 1);
}
size_t FSE_count_simple(unsigned *count, unsigned *maxSymbolValuePtr, const void *src, size_t srcSize)
{
const BYTE *ip = (const BYTE *)src;
const BYTE *const end = ip + srcSize;
unsigned maxSymbolValue = *maxSymbolValuePtr;
unsigned max = 0;
memset(count, 0, (maxSymbolValue + 1) * sizeof(*count));
if (srcSize == 0) {
*maxSymbolValuePtr = 0;
return 0;
}
while (ip < end)
count[*ip++]++;
while (!count[maxSymbolValue])
maxSymbolValue--;
*maxSymbolValuePtr = maxSymbolValue;
{
U32 s;
for (s = 0; s <= maxSymbolValue; s++)
if (count[s] > max)
max = count[s];
}
return (size_t)max;
}
static size_t FSE_count_parallel_wksp(unsigned *count, unsigned *maxSymbolValuePtr, const void *source, size_t sourceSize, unsigned checkMax,
unsigned *const workSpace)
{
const BYTE *ip = (const BYTE *)source;
const BYTE *const iend = ip + sourceSize;
unsigned maxSymbolValue = *maxSymbolValuePtr;
unsigned max = 0;
U32 *const Counting1 = workSpace;
U32 *const Counting2 = Counting1 + 256;
U32 *const Counting3 = Counting2 + 256;
U32 *const Counting4 = Counting3 + 256;
memset(Counting1, 0, 4 * 256 * sizeof(unsigned));
if (!sourceSize) {
memset(count, 0, maxSymbolValue + 1);
*maxSymbolValuePtr = 0;
return 0;
}
if (!maxSymbolValue)
maxSymbolValue = 255;
{
U32 cached = ZSTD_read32(ip);
ip += 4;
while (ip < iend - 15) {
U32 c = cached;
cached = ZSTD_read32(ip);
ip += 4;
Counting1[(BYTE)c]++;
Counting2[(BYTE)(c >> 8)]++;
Counting3[(BYTE)(c >> 16)]++;
Counting4[c >> 24]++;
c = cached;
cached = ZSTD_read32(ip);
ip += 4;
Counting1[(BYTE)c]++;
Counting2[(BYTE)(c >> 8)]++;
Counting3[(BYTE)(c >> 16)]++;
Counting4[c >> 24]++;
c = cached;
cached = ZSTD_read32(ip);
ip += 4;
Counting1[(BYTE)c]++;
Counting2[(BYTE)(c >> 8)]++;
Counting3[(BYTE)(c >> 16)]++;
Counting4[c >> 24]++;
c = cached;
cached = ZSTD_read32(ip);
ip += 4;
Counting1[(BYTE)c]++;
Counting2[(BYTE)(c >> 8)]++;
Counting3[(BYTE)(c >> 16)]++;
Counting4[c >> 24]++;
}
ip -= 4;
}
while (ip < iend)
Counting1[*ip++]++;
if (checkMax) {
U32 s;
for (s = 255; s > maxSymbolValue; s--) {
Counting1[s] += Counting2[s] + Counting3[s] + Counting4[s];
if (Counting1[s])
return ERROR(maxSymbolValue_tooSmall);
}
}
{
U32 s;
for (s = 0; s <= maxSymbolValue; s++) {
count[s] = Counting1[s] + Counting2[s] + Counting3[s] + Counting4[s];
if (count[s] > max)
max = count[s];
}
}
while (!count[maxSymbolValue])
maxSymbolValue--;
*maxSymbolValuePtr = maxSymbolValue;
return (size_t)max;
}
size_t FSE_countFast_wksp(unsigned *count, unsigned *maxSymbolValuePtr, const void *source, size_t sourceSize, unsigned *workSpace)
{
if (sourceSize < 1500)
return FSE_count_simple(count, maxSymbolValuePtr, source, sourceSize);
return FSE_count_parallel_wksp(count, maxSymbolValuePtr, source, sourceSize, 0, workSpace);
}
size_t FSE_count_wksp(unsigned *count, unsigned *maxSymbolValuePtr, const void *source, size_t sourceSize, unsigned *workSpace)
{
if (*maxSymbolValuePtr < 255)
return FSE_count_parallel_wksp(count, maxSymbolValuePtr, source, sourceSize, 1, workSpace);
*maxSymbolValuePtr = 255;
return FSE_countFast_wksp(count, maxSymbolValuePtr, source, sourceSize, workSpace);
}
size_t FSE_sizeof_CTable(unsigned maxSymbolValue, unsigned tableLog)
{
if (tableLog > FSE_MAX_TABLELOG)
return ERROR(tableLog_tooLarge);
return FSE_CTABLE_SIZE_U32(tableLog, maxSymbolValue) * sizeof(U32);
}
static unsigned FSE_minTableLog(size_t srcSize, unsigned maxSymbolValue)
{
U32 minBitsSrc = BIT_highbit32((U32)(srcSize - 1)) + 1;
U32 minBitsSymbols = BIT_highbit32(maxSymbolValue) + 2;
U32 minBits = minBitsSrc < minBitsSymbols ? minBitsSrc : minBitsSymbols;
return minBits;
}
unsigned FSE_optimalTableLog_internal(unsigned maxTableLog, size_t srcSize, unsigned maxSymbolValue, unsigned minus)
{
U32 maxBitsSrc = BIT_highbit32((U32)(srcSize - 1)) - minus;
U32 tableLog = maxTableLog;
U32 minBits = FSE_minTableLog(srcSize, maxSymbolValue);
if (tableLog == 0)
tableLog = FSE_DEFAULT_TABLELOG;
if (maxBitsSrc < tableLog)
tableLog = maxBitsSrc;
if (minBits > tableLog)
tableLog = minBits;
if (tableLog < FSE_MIN_TABLELOG)
tableLog = FSE_MIN_TABLELOG;
if (tableLog > FSE_MAX_TABLELOG)
tableLog = FSE_MAX_TABLELOG;
return tableLog;
}
unsigned FSE_optimalTableLog(unsigned maxTableLog, size_t srcSize, unsigned maxSymbolValue)
{
return FSE_optimalTableLog_internal(maxTableLog, srcSize, maxSymbolValue, 2);
}
static size_t FSE_normalizeM2(short *norm, U32 tableLog, const unsigned *count, size_t total, U32 maxSymbolValue)
{
short const NOT_YET_ASSIGNED = -2;
U32 s;
U32 distributed = 0;
U32 ToDistribute;
U32 const lowThreshold = (U32)(total >> tableLog);
U32 lowOne = (U32)((total * 3) >> (tableLog + 1));
for (s = 0; s <= maxSymbolValue; s++) {
if (count[s] == 0) {
norm[s] = 0;
continue;
}
if (count[s] <= lowThreshold) {
norm[s] = -1;
distributed++;
total -= count[s];
continue;
}
if (count[s] <= lowOne) {
norm[s] = 1;
distributed++;
total -= count[s];
continue;
}
norm[s] = NOT_YET_ASSIGNED;
}
ToDistribute = (1 << tableLog) - distributed;
if ((total / ToDistribute) > lowOne) {
lowOne = (U32)((total * 3) / (ToDistribute * 2));
for (s = 0; s <= maxSymbolValue; s++) {
if ((norm[s] == NOT_YET_ASSIGNED) && (count[s] <= lowOne)) {
norm[s] = 1;
distributed++;
total -= count[s];
continue;
}
}
ToDistribute = (1 << tableLog) - distributed;
}
if (distributed == maxSymbolValue + 1) {
U32 maxV = 0, maxC = 0;
for (s = 0; s <= maxSymbolValue; s++)
if (count[s] > maxC)
maxV = s, maxC = count[s];
norm[maxV] += (short)ToDistribute;
return 0;
}
if (total == 0) {
for (s = 0; ToDistribute > 0; s = (s + 1) % (maxSymbolValue + 1))
if (norm[s] > 0)
ToDistribute--, norm[s]++;
return 0;
}
{
U64 const vStepLog = 62 - tableLog;
U64 const mid = (1ULL << (vStepLog - 1)) - 1;
U64 const rStep = div_u64((((U64)1 << vStepLog) * ToDistribute) + mid, (U32)total);
U64 tmpTotal = mid;
for (s = 0; s <= maxSymbolValue; s++) {
if (norm[s] == NOT_YET_ASSIGNED) {
U64 const end = tmpTotal + (count[s] * rStep);
U32 const sStart = (U32)(tmpTotal >> vStepLog);
U32 const sEnd = (U32)(end >> vStepLog);
U32 const weight = sEnd - sStart;
if (weight < 1)
return ERROR(GENERIC);
norm[s] = (short)weight;
tmpTotal = end;
}
}
}
return 0;
}
size_t FSE_normalizeCount(short *normalizedCounter, unsigned tableLog, const unsigned *count, size_t total, unsigned maxSymbolValue)
{
if (tableLog == 0)
tableLog = FSE_DEFAULT_TABLELOG;
if (tableLog < FSE_MIN_TABLELOG)
return ERROR(GENERIC);
if (tableLog > FSE_MAX_TABLELOG)
return ERROR(tableLog_tooLarge);
if (tableLog < FSE_minTableLog(total, maxSymbolValue))
return ERROR(GENERIC);
{
U32 const rtbTable[] = {0, 473195, 504333, 520860, 550000, 700000, 750000, 830000};
U64 const scale = 62 - tableLog;
U64 const step = div_u64((U64)1 << 62, (U32)total);
U64 const vStep = 1ULL << (scale - 20);
int stillToDistribute = 1 << tableLog;
unsigned s;
unsigned largest = 0;
short largestP = 0;
U32 lowThreshold = (U32)(total >> tableLog);
for (s = 0; s <= maxSymbolValue; s++) {
if (count[s] == total)
return 0;
if (count[s] == 0) {
normalizedCounter[s] = 0;
continue;
}
if (count[s] <= lowThreshold) {
normalizedCounter[s] = -1;
stillToDistribute--;
} else {
short proba = (short)((count[s] * step) >> scale);
if (proba < 8) {
U64 restToBeat = vStep * rtbTable[proba];
proba += (count[s] * step) - ((U64)proba << scale) > restToBeat;
}
if (proba > largestP)
largestP = proba, largest = s;
normalizedCounter[s] = proba;
stillToDistribute -= proba;
}
}
if (-stillToDistribute >= (normalizedCounter[largest] >> 1)) {
size_t const errorCode = FSE_normalizeM2(normalizedCounter, tableLog, count, total, maxSymbolValue);
if (FSE_isError(errorCode))
return errorCode;
} else
normalizedCounter[largest] += (short)stillToDistribute;
}
return tableLog;
}
size_t FSE_buildCTable_raw(FSE_CTable *ct, unsigned nbBits)
{
const unsigned tableSize = 1 << nbBits;
const unsigned tableMask = tableSize - 1;
const unsigned maxSymbolValue = tableMask;
void *const ptr = ct;
U16 *const tableU16 = ((U16 *)ptr) + 2;
void *const FSCT = ((U32 *)ptr) + 1 + (tableSize >> 1);
FSE_symbolCompressionTransform *const symbolTT = (FSE_symbolCompressionTransform *)(FSCT);
unsigned s;
if (nbBits < 1)
return ERROR(GENERIC);
tableU16[-2] = (U16)nbBits;
tableU16[-1] = (U16)maxSymbolValue;
for (s = 0; s < tableSize; s++)
tableU16[s] = (U16)(tableSize + s);
{
const U32 deltaNbBits = (nbBits << 16) - (1 << nbBits);
for (s = 0; s <= maxSymbolValue; s++) {
symbolTT[s].deltaNbBits = deltaNbBits;
symbolTT[s].deltaFindState = s - 1;
}
}
return 0;
}
size_t FSE_buildCTable_rle(FSE_CTable *ct, BYTE symbolValue)
{
void *ptr = ct;
U16 *tableU16 = ((U16 *)ptr) + 2;
void *FSCTptr = (U32 *)ptr + 2;
FSE_symbolCompressionTransform *symbolTT = (FSE_symbolCompressionTransform *)FSCTptr;
tableU16[-2] = (U16)0;
tableU16[-1] = (U16)symbolValue;
tableU16[0] = 0;
tableU16[1] = 0;
symbolTT[symbolValue].deltaNbBits = 0;
symbolTT[symbolValue].deltaFindState = 0;
return 0;
}
static size_t FSE_compress_usingCTable_generic(void *dst, size_t dstSize, const void *src, size_t srcSize, const FSE_CTable *ct, const unsigned fast)
{
const BYTE *const istart = (const BYTE *)src;
const BYTE *const iend = istart + srcSize;
const BYTE *ip = iend;
BIT_CStream_t bitC;
FSE_CState_t CState1, CState2;
if (srcSize <= 2)
return 0;
{
size_t const initError = BIT_initCStream(&bitC, dst, dstSize);
if (FSE_isError(initError))
return 0;
}
#define FSE_FLUSHBITS(s) (fast ? BIT_flushBitsFast(s) : BIT_flushBits(s))
if (srcSize & 1) {
FSE_initCState2(&CState1, ct, *--ip);
FSE_initCState2(&CState2, ct, *--ip);
FSE_encodeSymbol(&bitC, &CState1, *--ip);
FSE_FLUSHBITS(&bitC);
} else {
FSE_initCState2(&CState2, ct, *--ip);
FSE_initCState2(&CState1, ct, *--ip);
}
srcSize -= 2;
if ((sizeof(bitC.bitContainer) * 8 > FSE_MAX_TABLELOG * 4 + 7) && (srcSize & 2)) {
FSE_encodeSymbol(&bitC, &CState2, *--ip);
FSE_encodeSymbol(&bitC, &CState1, *--ip);
FSE_FLUSHBITS(&bitC);
}
while (ip > istart) {
FSE_encodeSymbol(&bitC, &CState2, *--ip);
if (sizeof(bitC.bitContainer) * 8 < FSE_MAX_TABLELOG * 2 + 7)
FSE_FLUSHBITS(&bitC);
FSE_encodeSymbol(&bitC, &CState1, *--ip);
if (sizeof(bitC.bitContainer) * 8 > FSE_MAX_TABLELOG * 4 + 7) {
FSE_encodeSymbol(&bitC, &CState2, *--ip);
FSE_encodeSymbol(&bitC, &CState1, *--ip);
}
FSE_FLUSHBITS(&bitC);
}
FSE_flushCState(&bitC, &CState2);
FSE_flushCState(&bitC, &CState1);
return BIT_closeCStream(&bitC);
}
size_t FSE_compress_usingCTable(void *dst, size_t dstSize, const void *src, size_t srcSize, const FSE_CTable *ct)
{
unsigned const fast = (dstSize >= FSE_BLOCKBOUND(srcSize));
if (fast)
return FSE_compress_usingCTable_generic(dst, dstSize, src, srcSize, ct, 1);
else
return FSE_compress_usingCTable_generic(dst, dstSize, src, srcSize, ct, 0);
}
size_t FSE_compressBound(size_t size) { return FSE_COMPRESSBOUND(size); }
