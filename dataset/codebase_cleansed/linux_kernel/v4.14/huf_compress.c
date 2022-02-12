unsigned HUF_optimalTableLog(unsigned maxTableLog, size_t srcSize, unsigned maxSymbolValue)
{
return FSE_optimalTableLog_internal(maxTableLog, srcSize, maxSymbolValue, 1);
}
size_t HUF_compressWeights_wksp(void *dst, size_t dstSize, const void *weightTable, size_t wtSize, void *workspace, size_t workspaceSize)
{
BYTE *const ostart = (BYTE *)dst;
BYTE *op = ostart;
BYTE *const oend = ostart + dstSize;
U32 maxSymbolValue = HUF_TABLELOG_MAX;
U32 tableLog = MAX_FSE_TABLELOG_FOR_HUFF_HEADER;
FSE_CTable *CTable;
U32 *count;
S16 *norm;
size_t spaceUsed32 = 0;
HUF_STATIC_ASSERT(sizeof(FSE_CTable) == sizeof(U32));
CTable = (FSE_CTable *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += FSE_CTABLE_SIZE_U32(MAX_FSE_TABLELOG_FOR_HUFF_HEADER, HUF_TABLELOG_MAX);
count = (U32 *)workspace + spaceUsed32;
spaceUsed32 += HUF_TABLELOG_MAX + 1;
norm = (S16 *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(sizeof(S16) * (HUF_TABLELOG_MAX + 1), sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
if (wtSize <= 1)
return 0;
{
CHECK_V_F(maxCount, FSE_count_simple(count, &maxSymbolValue, weightTable, wtSize));
if (maxCount == wtSize)
return 1;
if (maxCount == 1)
return 0;
}
tableLog = FSE_optimalTableLog(tableLog, wtSize, maxSymbolValue);
CHECK_F(FSE_normalizeCount(norm, tableLog, count, wtSize, maxSymbolValue));
{
CHECK_V_F(hSize, FSE_writeNCount(op, oend - op, norm, maxSymbolValue, tableLog));
op += hSize;
}
CHECK_F(FSE_buildCTable_wksp(CTable, norm, maxSymbolValue, tableLog, workspace, workspaceSize));
{
CHECK_V_F(cSize, FSE_compress_usingCTable(op, oend - op, weightTable, wtSize, CTable));
if (cSize == 0)
return 0;
op += cSize;
}
return op - ostart;
}
size_t HUF_writeCTable_wksp(void *dst, size_t maxDstSize, const HUF_CElt *CTable, U32 maxSymbolValue, U32 huffLog, void *workspace, size_t workspaceSize)
{
BYTE *op = (BYTE *)dst;
U32 n;
BYTE *bitsToWeight;
BYTE *huffWeight;
size_t spaceUsed32 = 0;
bitsToWeight = (BYTE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(HUF_TABLELOG_MAX + 1, sizeof(U32)) >> 2;
huffWeight = (BYTE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(HUF_SYMBOLVALUE_MAX, sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
if (maxSymbolValue > HUF_SYMBOLVALUE_MAX)
return ERROR(maxSymbolValue_tooLarge);
bitsToWeight[0] = 0;
for (n = 1; n < huffLog + 1; n++)
bitsToWeight[n] = (BYTE)(huffLog + 1 - n);
for (n = 0; n < maxSymbolValue; n++)
huffWeight[n] = bitsToWeight[CTable[n].nbBits];
{
CHECK_V_F(hSize, HUF_compressWeights_wksp(op + 1, maxDstSize - 1, huffWeight, maxSymbolValue, workspace, workspaceSize));
if ((hSize > 1) & (hSize < maxSymbolValue / 2)) {
op[0] = (BYTE)hSize;
return hSize + 1;
}
}
if (maxSymbolValue > (256 - 128))
return ERROR(GENERIC);
if (((maxSymbolValue + 1) / 2) + 1 > maxDstSize)
return ERROR(dstSize_tooSmall);
op[0] = (BYTE)(128 + (maxSymbolValue - 1));
huffWeight[maxSymbolValue] = 0;
for (n = 0; n < maxSymbolValue; n += 2)
op[(n / 2) + 1] = (BYTE)((huffWeight[n] << 4) + huffWeight[n + 1]);
return ((maxSymbolValue + 1) / 2) + 1;
}
size_t HUF_readCTable_wksp(HUF_CElt *CTable, U32 maxSymbolValue, const void *src, size_t srcSize, void *workspace, size_t workspaceSize)
{
U32 *rankVal;
BYTE *huffWeight;
U32 tableLog = 0;
U32 nbSymbols = 0;
size_t readSize;
size_t spaceUsed32 = 0;
rankVal = (U32 *)workspace + spaceUsed32;
spaceUsed32 += HUF_TABLELOG_ABSOLUTEMAX + 1;
huffWeight = (BYTE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(HUF_SYMBOLVALUE_MAX + 1, sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
readSize = HUF_readStats_wksp(huffWeight, HUF_SYMBOLVALUE_MAX + 1, rankVal, &nbSymbols, &tableLog, src, srcSize, workspace, workspaceSize);
if (ERR_isError(readSize))
return readSize;
if (tableLog > HUF_TABLELOG_MAX)
return ERROR(tableLog_tooLarge);
if (nbSymbols > maxSymbolValue + 1)
return ERROR(maxSymbolValue_tooSmall);
{
U32 n, nextRankStart = 0;
for (n = 1; n <= tableLog; n++) {
U32 curr = nextRankStart;
nextRankStart += (rankVal[n] << (n - 1));
rankVal[n] = curr;
}
}
{
U32 n;
for (n = 0; n < nbSymbols; n++) {
const U32 w = huffWeight[n];
CTable[n].nbBits = (BYTE)(tableLog + 1 - w);
}
}
{
U16 nbPerRank[HUF_TABLELOG_MAX + 2] = {0};
U16 valPerRank[HUF_TABLELOG_MAX + 2] = {0};
{
U32 n;
for (n = 0; n < nbSymbols; n++)
nbPerRank[CTable[n].nbBits]++;
}
valPerRank[tableLog + 1] = 0;
{
U16 min = 0;
U32 n;
for (n = tableLog; n > 0; n--) {
valPerRank[n] = min;
min += nbPerRank[n];
min >>= 1;
}
}
{
U32 n;
for (n = 0; n <= maxSymbolValue; n++)
CTable[n].val = valPerRank[CTable[n].nbBits]++;
}
}
return readSize;
}
static U32 HUF_setMaxHeight(nodeElt *huffNode, U32 lastNonNull, U32 maxNbBits)
{
const U32 largestBits = huffNode[lastNonNull].nbBits;
if (largestBits <= maxNbBits)
return largestBits;
{
int totalCost = 0;
const U32 baseCost = 1 << (largestBits - maxNbBits);
U32 n = lastNonNull;
while (huffNode[n].nbBits > maxNbBits) {
totalCost += baseCost - (1 << (largestBits - huffNode[n].nbBits));
huffNode[n].nbBits = (BYTE)maxNbBits;
n--;
}
while (huffNode[n].nbBits == maxNbBits)
n--;
totalCost >>= (largestBits - maxNbBits);
{
U32 const noSymbol = 0xF0F0F0F0;
U32 rankLast[HUF_TABLELOG_MAX + 2];
int pos;
memset(rankLast, 0xF0, sizeof(rankLast));
{
U32 currNbBits = maxNbBits;
for (pos = n; pos >= 0; pos--) {
if (huffNode[pos].nbBits >= currNbBits)
continue;
currNbBits = huffNode[pos].nbBits;
rankLast[maxNbBits - currNbBits] = pos;
}
}
while (totalCost > 0) {
U32 nBitsToDecrease = BIT_highbit32(totalCost) + 1;
for (; nBitsToDecrease > 1; nBitsToDecrease--) {
U32 highPos = rankLast[nBitsToDecrease];
U32 lowPos = rankLast[nBitsToDecrease - 1];
if (highPos == noSymbol)
continue;
if (lowPos == noSymbol)
break;
{
U32 const highTotal = huffNode[highPos].count;
U32 const lowTotal = 2 * huffNode[lowPos].count;
if (highTotal <= lowTotal)
break;
}
}
while ((nBitsToDecrease <= HUF_TABLELOG_MAX) && (rankLast[nBitsToDecrease] == noSymbol))
nBitsToDecrease++;
totalCost -= 1 << (nBitsToDecrease - 1);
if (rankLast[nBitsToDecrease - 1] == noSymbol)
rankLast[nBitsToDecrease - 1] = rankLast[nBitsToDecrease];
huffNode[rankLast[nBitsToDecrease]].nbBits++;
if (rankLast[nBitsToDecrease] == 0)
rankLast[nBitsToDecrease] = noSymbol;
else {
rankLast[nBitsToDecrease]--;
if (huffNode[rankLast[nBitsToDecrease]].nbBits != maxNbBits - nBitsToDecrease)
rankLast[nBitsToDecrease] = noSymbol;
}
}
while (totalCost < 0) {
if (rankLast[1] == noSymbol) {
while (huffNode[n].nbBits == maxNbBits)
n--;
huffNode[n + 1].nbBits--;
rankLast[1] = n + 1;
totalCost++;
continue;
}
huffNode[rankLast[1] + 1].nbBits--;
rankLast[1]++;
totalCost++;
}
}
}
return maxNbBits;
}
static void HUF_sort(nodeElt *huffNode, const U32 *count, U32 maxSymbolValue)
{
rankPos rank[32];
U32 n;
memset(rank, 0, sizeof(rank));
for (n = 0; n <= maxSymbolValue; n++) {
U32 r = BIT_highbit32(count[n] + 1);
rank[r].base++;
}
for (n = 30; n > 0; n--)
rank[n - 1].base += rank[n].base;
for (n = 0; n < 32; n++)
rank[n].curr = rank[n].base;
for (n = 0; n <= maxSymbolValue; n++) {
U32 const c = count[n];
U32 const r = BIT_highbit32(c + 1) + 1;
U32 pos = rank[r].curr++;
while ((pos > rank[r].base) && (c > huffNode[pos - 1].count))
huffNode[pos] = huffNode[pos - 1], pos--;
huffNode[pos].count = c;
huffNode[pos].byte = (BYTE)n;
}
}
size_t HUF_buildCTable_wksp(HUF_CElt *tree, const U32 *count, U32 maxSymbolValue, U32 maxNbBits, void *workSpace, size_t wkspSize)
{
nodeElt *const huffNode0 = (nodeElt *)workSpace;
nodeElt *const huffNode = huffNode0 + 1;
U32 n, nonNullRank;
int lowS, lowN;
U16 nodeNb = STARTNODE;
U32 nodeRoot;
if (wkspSize < sizeof(huffNodeTable))
return ERROR(GENERIC);
if (maxNbBits == 0)
maxNbBits = HUF_TABLELOG_DEFAULT;
if (maxSymbolValue > HUF_SYMBOLVALUE_MAX)
return ERROR(GENERIC);
memset(huffNode0, 0, sizeof(huffNodeTable));
HUF_sort(huffNode, count, maxSymbolValue);
nonNullRank = maxSymbolValue;
while (huffNode[nonNullRank].count == 0)
nonNullRank--;
lowS = nonNullRank;
nodeRoot = nodeNb + lowS - 1;
lowN = nodeNb;
huffNode[nodeNb].count = huffNode[lowS].count + huffNode[lowS - 1].count;
huffNode[lowS].parent = huffNode[lowS - 1].parent = nodeNb;
nodeNb++;
lowS -= 2;
for (n = nodeNb; n <= nodeRoot; n++)
huffNode[n].count = (U32)(1U << 30);
huffNode0[0].count = (U32)(1U << 31);
while (nodeNb <= nodeRoot) {
U32 n1 = (huffNode[lowS].count < huffNode[lowN].count) ? lowS-- : lowN++;
U32 n2 = (huffNode[lowS].count < huffNode[lowN].count) ? lowS-- : lowN++;
huffNode[nodeNb].count = huffNode[n1].count + huffNode[n2].count;
huffNode[n1].parent = huffNode[n2].parent = nodeNb;
nodeNb++;
}
huffNode[nodeRoot].nbBits = 0;
for (n = nodeRoot - 1; n >= STARTNODE; n--)
huffNode[n].nbBits = huffNode[huffNode[n].parent].nbBits + 1;
for (n = 0; n <= nonNullRank; n++)
huffNode[n].nbBits = huffNode[huffNode[n].parent].nbBits + 1;
maxNbBits = HUF_setMaxHeight(huffNode, nonNullRank, maxNbBits);
{
U16 nbPerRank[HUF_TABLELOG_MAX + 1] = {0};
U16 valPerRank[HUF_TABLELOG_MAX + 1] = {0};
if (maxNbBits > HUF_TABLELOG_MAX)
return ERROR(GENERIC);
for (n = 0; n <= nonNullRank; n++)
nbPerRank[huffNode[n].nbBits]++;
{
U16 min = 0;
for (n = maxNbBits; n > 0; n--) {
valPerRank[n] = min;
min += nbPerRank[n];
min >>= 1;
}
}
for (n = 0; n <= maxSymbolValue; n++)
tree[huffNode[n].byte].nbBits = huffNode[n].nbBits;
for (n = 0; n <= maxSymbolValue; n++)
tree[n].val = valPerRank[tree[n].nbBits]++;
}
return maxNbBits;
}
static size_t HUF_estimateCompressedSize(HUF_CElt *CTable, const unsigned *count, unsigned maxSymbolValue)
{
size_t nbBits = 0;
int s;
for (s = 0; s <= (int)maxSymbolValue; ++s) {
nbBits += CTable[s].nbBits * count[s];
}
return nbBits >> 3;
}
static int HUF_validateCTable(const HUF_CElt *CTable, const unsigned *count, unsigned maxSymbolValue)
{
int bad = 0;
int s;
for (s = 0; s <= (int)maxSymbolValue; ++s) {
bad |= (count[s] != 0) & (CTable[s].nbBits == 0);
}
return !bad;
}
static void HUF_encodeSymbol(BIT_CStream_t *bitCPtr, U32 symbol, const HUF_CElt *CTable)
{
BIT_addBitsFast(bitCPtr, CTable[symbol].val, CTable[symbol].nbBits);
}
size_t HUF_compressBound(size_t size) { return HUF_COMPRESSBOUND(size); }
size_t HUF_compress1X_usingCTable(void *dst, size_t dstSize, const void *src, size_t srcSize, const HUF_CElt *CTable)
{
const BYTE *ip = (const BYTE *)src;
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
BYTE *op = ostart;
size_t n;
BIT_CStream_t bitC;
if (dstSize < 8)
return 0;
{
size_t const initErr = BIT_initCStream(&bitC, op, oend - op);
if (HUF_isError(initErr))
return 0;
}
n = srcSize & ~3;
switch (srcSize & 3) {
case 3: HUF_encodeSymbol(&bitC, ip[n + 2], CTable); HUF_FLUSHBITS_2(&bitC);
case 2: HUF_encodeSymbol(&bitC, ip[n + 1], CTable); HUF_FLUSHBITS_1(&bitC);
case 1: HUF_encodeSymbol(&bitC, ip[n + 0], CTable); HUF_FLUSHBITS(&bitC);
case 0:
default:;
}
for (; n > 0; n -= 4) {
HUF_encodeSymbol(&bitC, ip[n - 1], CTable);
HUF_FLUSHBITS_1(&bitC);
HUF_encodeSymbol(&bitC, ip[n - 2], CTable);
HUF_FLUSHBITS_2(&bitC);
HUF_encodeSymbol(&bitC, ip[n - 3], CTable);
HUF_FLUSHBITS_1(&bitC);
HUF_encodeSymbol(&bitC, ip[n - 4], CTable);
HUF_FLUSHBITS(&bitC);
}
return BIT_closeCStream(&bitC);
}
size_t HUF_compress4X_usingCTable(void *dst, size_t dstSize, const void *src, size_t srcSize, const HUF_CElt *CTable)
{
size_t const segmentSize = (srcSize + 3) / 4;
const BYTE *ip = (const BYTE *)src;
const BYTE *const iend = ip + srcSize;
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
BYTE *op = ostart;
if (dstSize < 6 + 1 + 1 + 1 + 8)
return 0;
if (srcSize < 12)
return 0;
op += 6;
{
CHECK_V_F(cSize, HUF_compress1X_usingCTable(op, oend - op, ip, segmentSize, CTable));
if (cSize == 0)
return 0;
ZSTD_writeLE16(ostart, (U16)cSize);
op += cSize;
}
ip += segmentSize;
{
CHECK_V_F(cSize, HUF_compress1X_usingCTable(op, oend - op, ip, segmentSize, CTable));
if (cSize == 0)
return 0;
ZSTD_writeLE16(ostart + 2, (U16)cSize);
op += cSize;
}
ip += segmentSize;
{
CHECK_V_F(cSize, HUF_compress1X_usingCTable(op, oend - op, ip, segmentSize, CTable));
if (cSize == 0)
return 0;
ZSTD_writeLE16(ostart + 4, (U16)cSize);
op += cSize;
}
ip += segmentSize;
{
CHECK_V_F(cSize, HUF_compress1X_usingCTable(op, oend - op, ip, iend - ip, CTable));
if (cSize == 0)
return 0;
op += cSize;
}
return op - ostart;
}
static size_t HUF_compressCTable_internal(BYTE *const ostart, BYTE *op, BYTE *const oend, const void *src, size_t srcSize, unsigned singleStream,
const HUF_CElt *CTable)
{
size_t const cSize =
singleStream ? HUF_compress1X_usingCTable(op, oend - op, src, srcSize, CTable) : HUF_compress4X_usingCTable(op, oend - op, src, srcSize, CTable);
if (HUF_isError(cSize)) {
return cSize;
}
if (cSize == 0) {
return 0;
}
op += cSize;
if ((size_t)(op - ostart) >= srcSize - 1) {
return 0;
}
return op - ostart;
}
static size_t HUF_compress_internal(void *dst, size_t dstSize, const void *src, size_t srcSize, unsigned maxSymbolValue, unsigned huffLog,
unsigned singleStream, void *workSpace, size_t wkspSize, HUF_CElt *oldHufTable, HUF_repeat *repeat, int preferRepeat)
{
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
BYTE *op = ostart;
U32 *count;
size_t const countSize = sizeof(U32) * (HUF_SYMBOLVALUE_MAX + 1);
HUF_CElt *CTable;
size_t const CTableSize = sizeof(HUF_CElt) * (HUF_SYMBOLVALUE_MAX + 1);
if (wkspSize < sizeof(huffNodeTable) + countSize + CTableSize)
return ERROR(GENERIC);
if (!srcSize)
return 0;
if (!dstSize)
return 0;
if (srcSize > HUF_BLOCKSIZE_MAX)
return ERROR(srcSize_wrong);
if (huffLog > HUF_TABLELOG_MAX)
return ERROR(tableLog_tooLarge);
if (!maxSymbolValue)
maxSymbolValue = HUF_SYMBOLVALUE_MAX;
if (!huffLog)
huffLog = HUF_TABLELOG_DEFAULT;
count = (U32 *)workSpace;
workSpace = (BYTE *)workSpace + countSize;
wkspSize -= countSize;
CTable = (HUF_CElt *)workSpace;
workSpace = (BYTE *)workSpace + CTableSize;
wkspSize -= CTableSize;
if (preferRepeat && repeat && *repeat == HUF_repeat_valid) {
return HUF_compressCTable_internal(ostart, op, oend, src, srcSize, singleStream, oldHufTable);
}
{
CHECK_V_F(largest, FSE_count_wksp(count, &maxSymbolValue, (const BYTE *)src, srcSize, (U32 *)workSpace));
if (largest == srcSize) {
*ostart = ((const BYTE *)src)[0];
return 1;
}
if (largest <= (srcSize >> 7) + 1)
return 0;
}
if (repeat && *repeat == HUF_repeat_check && !HUF_validateCTable(oldHufTable, count, maxSymbolValue)) {
*repeat = HUF_repeat_none;
}
if (preferRepeat && repeat && *repeat != HUF_repeat_none) {
return HUF_compressCTable_internal(ostart, op, oend, src, srcSize, singleStream, oldHufTable);
}
huffLog = HUF_optimalTableLog(huffLog, srcSize, maxSymbolValue);
{
CHECK_V_F(maxBits, HUF_buildCTable_wksp(CTable, count, maxSymbolValue, huffLog, workSpace, wkspSize));
huffLog = (U32)maxBits;
memset(CTable + maxSymbolValue + 1, 0, CTableSize - (maxSymbolValue + 1) * sizeof(HUF_CElt));
}
{
CHECK_V_F(hSize, HUF_writeCTable_wksp(op, dstSize, CTable, maxSymbolValue, huffLog, workSpace, wkspSize));
if (repeat && *repeat != HUF_repeat_none) {
size_t const oldSize = HUF_estimateCompressedSize(oldHufTable, count, maxSymbolValue);
size_t const newSize = HUF_estimateCompressedSize(CTable, count, maxSymbolValue);
if (oldSize <= hSize + newSize || hSize + 12 >= srcSize) {
return HUF_compressCTable_internal(ostart, op, oend, src, srcSize, singleStream, oldHufTable);
}
}
if (hSize + 12ul >= srcSize) {
return 0;
}
op += hSize;
if (repeat) {
*repeat = HUF_repeat_none;
}
if (oldHufTable) {
memcpy(oldHufTable, CTable, CTableSize);
}
}
return HUF_compressCTable_internal(ostart, op, oend, src, srcSize, singleStream, CTable);
}
size_t HUF_compress1X_wksp(void *dst, size_t dstSize, const void *src, size_t srcSize, unsigned maxSymbolValue, unsigned huffLog, void *workSpace,
size_t wkspSize)
{
return HUF_compress_internal(dst, dstSize, src, srcSize, maxSymbolValue, huffLog, 1 , workSpace, wkspSize, NULL, NULL, 0);
}
size_t HUF_compress1X_repeat(void *dst, size_t dstSize, const void *src, size_t srcSize, unsigned maxSymbolValue, unsigned huffLog, void *workSpace,
size_t wkspSize, HUF_CElt *hufTable, HUF_repeat *repeat, int preferRepeat)
{
return HUF_compress_internal(dst, dstSize, src, srcSize, maxSymbolValue, huffLog, 1 , workSpace, wkspSize, hufTable, repeat,
preferRepeat);
}
size_t HUF_compress4X_wksp(void *dst, size_t dstSize, const void *src, size_t srcSize, unsigned maxSymbolValue, unsigned huffLog, void *workSpace,
size_t wkspSize)
{
return HUF_compress_internal(dst, dstSize, src, srcSize, maxSymbolValue, huffLog, 0 , workSpace, wkspSize, NULL, NULL, 0);
}
size_t HUF_compress4X_repeat(void *dst, size_t dstSize, const void *src, size_t srcSize, unsigned maxSymbolValue, unsigned huffLog, void *workSpace,
size_t wkspSize, HUF_CElt *hufTable, HUF_repeat *repeat, int preferRepeat)
{
return HUF_compress_internal(dst, dstSize, src, srcSize, maxSymbolValue, huffLog, 0 , workSpace, wkspSize, hufTable, repeat,
preferRepeat);
}
