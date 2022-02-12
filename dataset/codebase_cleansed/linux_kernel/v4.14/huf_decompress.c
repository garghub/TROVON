static DTableDesc HUF_getDTableDesc(const HUF_DTable *table)
{
DTableDesc dtd;
memcpy(&dtd, table, sizeof(dtd));
return dtd;
}
size_t HUF_readDTableX2_wksp(HUF_DTable *DTable, const void *src, size_t srcSize, void *workspace, size_t workspaceSize)
{
U32 tableLog = 0;
U32 nbSymbols = 0;
size_t iSize;
void *const dtPtr = DTable + 1;
HUF_DEltX2 *const dt = (HUF_DEltX2 *)dtPtr;
U32 *rankVal;
BYTE *huffWeight;
size_t spaceUsed32 = 0;
rankVal = (U32 *)workspace + spaceUsed32;
spaceUsed32 += HUF_TABLELOG_ABSOLUTEMAX + 1;
huffWeight = (BYTE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(HUF_SYMBOLVALUE_MAX + 1, sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
HUF_STATIC_ASSERT(sizeof(DTableDesc) == sizeof(HUF_DTable));
iSize = HUF_readStats_wksp(huffWeight, HUF_SYMBOLVALUE_MAX + 1, rankVal, &nbSymbols, &tableLog, src, srcSize, workspace, workspaceSize);
if (HUF_isError(iSize))
return iSize;
{
DTableDesc dtd = HUF_getDTableDesc(DTable);
if (tableLog > (U32)(dtd.maxTableLog + 1))
return ERROR(tableLog_tooLarge);
dtd.tableType = 0;
dtd.tableLog = (BYTE)tableLog;
memcpy(DTable, &dtd, sizeof(dtd));
}
{
U32 n, nextRankStart = 0;
for (n = 1; n < tableLog + 1; n++) {
U32 const curr = nextRankStart;
nextRankStart += (rankVal[n] << (n - 1));
rankVal[n] = curr;
}
}
{
U32 n;
for (n = 0; n < nbSymbols; n++) {
U32 const w = huffWeight[n];
U32 const length = (1 << w) >> 1;
U32 u;
HUF_DEltX2 D;
D.byte = (BYTE)n;
D.nbBits = (BYTE)(tableLog + 1 - w);
for (u = rankVal[w]; u < rankVal[w] + length; u++)
dt[u] = D;
rankVal[w] += length;
}
}
return iSize;
}
static BYTE HUF_decodeSymbolX2(BIT_DStream_t *Dstream, const HUF_DEltX2 *dt, const U32 dtLog)
{
size_t const val = BIT_lookBitsFast(Dstream, dtLog);
BYTE const c = dt[val].byte;
BIT_skipBits(Dstream, dt[val].nbBits);
return c;
}
FORCE_INLINE size_t HUF_decodeStreamX2(BYTE *p, BIT_DStream_t *const bitDPtr, BYTE *const pEnd, const HUF_DEltX2 *const dt, const U32 dtLog)
{
BYTE *const pStart = p;
while ((BIT_reloadDStream(bitDPtr) == BIT_DStream_unfinished) && (p <= pEnd - 4)) {
HUF_DECODE_SYMBOLX2_2(p, bitDPtr);
HUF_DECODE_SYMBOLX2_1(p, bitDPtr);
HUF_DECODE_SYMBOLX2_2(p, bitDPtr);
HUF_DECODE_SYMBOLX2_0(p, bitDPtr);
}
while ((BIT_reloadDStream(bitDPtr) == BIT_DStream_unfinished) && (p < pEnd))
HUF_DECODE_SYMBOLX2_0(p, bitDPtr);
while (p < pEnd)
HUF_DECODE_SYMBOLX2_0(p, bitDPtr);
return pEnd - pStart;
}
static size_t HUF_decompress1X2_usingDTable_internal(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
BYTE *op = (BYTE *)dst;
BYTE *const oend = op + dstSize;
const void *dtPtr = DTable + 1;
const HUF_DEltX2 *const dt = (const HUF_DEltX2 *)dtPtr;
BIT_DStream_t bitD;
DTableDesc const dtd = HUF_getDTableDesc(DTable);
U32 const dtLog = dtd.tableLog;
{
size_t const errorCode = BIT_initDStream(&bitD, cSrc, cSrcSize);
if (HUF_isError(errorCode))
return errorCode;
}
HUF_decodeStreamX2(op, &bitD, oend, dt, dtLog);
if (!BIT_endOfDStream(&bitD))
return ERROR(corruption_detected);
return dstSize;
}
size_t HUF_decompress1X2_usingDTable(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc dtd = HUF_getDTableDesc(DTable);
if (dtd.tableType != 0)
return ERROR(GENERIC);
return HUF_decompress1X2_usingDTable_internal(dst, dstSize, cSrc, cSrcSize, DTable);
}
size_t HUF_decompress1X2_DCtx_wksp(HUF_DTable *DCtx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
const BYTE *ip = (const BYTE *)cSrc;
size_t const hSize = HUF_readDTableX2_wksp(DCtx, cSrc, cSrcSize, workspace, workspaceSize);
if (HUF_isError(hSize))
return hSize;
if (hSize >= cSrcSize)
return ERROR(srcSize_wrong);
ip += hSize;
cSrcSize -= hSize;
return HUF_decompress1X2_usingDTable_internal(dst, dstSize, ip, cSrcSize, DCtx);
}
static size_t HUF_decompress4X2_usingDTable_internal(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
if (cSrcSize < 10)
return ERROR(corruption_detected);
{
const BYTE *const istart = (const BYTE *)cSrc;
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
const void *const dtPtr = DTable + 1;
const HUF_DEltX2 *const dt = (const HUF_DEltX2 *)dtPtr;
BIT_DStream_t bitD1;
BIT_DStream_t bitD2;
BIT_DStream_t bitD3;
BIT_DStream_t bitD4;
size_t const length1 = ZSTD_readLE16(istart);
size_t const length2 = ZSTD_readLE16(istart + 2);
size_t const length3 = ZSTD_readLE16(istart + 4);
size_t const length4 = cSrcSize - (length1 + length2 + length3 + 6);
const BYTE *const istart1 = istart + 6;
const BYTE *const istart2 = istart1 + length1;
const BYTE *const istart3 = istart2 + length2;
const BYTE *const istart4 = istart3 + length3;
const size_t segmentSize = (dstSize + 3) / 4;
BYTE *const opStart2 = ostart + segmentSize;
BYTE *const opStart3 = opStart2 + segmentSize;
BYTE *const opStart4 = opStart3 + segmentSize;
BYTE *op1 = ostart;
BYTE *op2 = opStart2;
BYTE *op3 = opStart3;
BYTE *op4 = opStart4;
U32 endSignal;
DTableDesc const dtd = HUF_getDTableDesc(DTable);
U32 const dtLog = dtd.tableLog;
if (length4 > cSrcSize)
return ERROR(corruption_detected);
{
size_t const errorCode = BIT_initDStream(&bitD1, istart1, length1);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD2, istart2, length2);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD3, istart3, length3);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD4, istart4, length4);
if (HUF_isError(errorCode))
return errorCode;
}
endSignal = BIT_reloadDStream(&bitD1) | BIT_reloadDStream(&bitD2) | BIT_reloadDStream(&bitD3) | BIT_reloadDStream(&bitD4);
for (; (endSignal == BIT_DStream_unfinished) && (op4 < (oend - 7));) {
HUF_DECODE_SYMBOLX2_2(op1, &bitD1);
HUF_DECODE_SYMBOLX2_2(op2, &bitD2);
HUF_DECODE_SYMBOLX2_2(op3, &bitD3);
HUF_DECODE_SYMBOLX2_2(op4, &bitD4);
HUF_DECODE_SYMBOLX2_1(op1, &bitD1);
HUF_DECODE_SYMBOLX2_1(op2, &bitD2);
HUF_DECODE_SYMBOLX2_1(op3, &bitD3);
HUF_DECODE_SYMBOLX2_1(op4, &bitD4);
HUF_DECODE_SYMBOLX2_2(op1, &bitD1);
HUF_DECODE_SYMBOLX2_2(op2, &bitD2);
HUF_DECODE_SYMBOLX2_2(op3, &bitD3);
HUF_DECODE_SYMBOLX2_2(op4, &bitD4);
HUF_DECODE_SYMBOLX2_0(op1, &bitD1);
HUF_DECODE_SYMBOLX2_0(op2, &bitD2);
HUF_DECODE_SYMBOLX2_0(op3, &bitD3);
HUF_DECODE_SYMBOLX2_0(op4, &bitD4);
endSignal = BIT_reloadDStream(&bitD1) | BIT_reloadDStream(&bitD2) | BIT_reloadDStream(&bitD3) | BIT_reloadDStream(&bitD4);
}
if (op1 > opStart2)
return ERROR(corruption_detected);
if (op2 > opStart3)
return ERROR(corruption_detected);
if (op3 > opStart4)
return ERROR(corruption_detected);
HUF_decodeStreamX2(op1, &bitD1, opStart2, dt, dtLog);
HUF_decodeStreamX2(op2, &bitD2, opStart3, dt, dtLog);
HUF_decodeStreamX2(op3, &bitD3, opStart4, dt, dtLog);
HUF_decodeStreamX2(op4, &bitD4, oend, dt, dtLog);
endSignal = BIT_endOfDStream(&bitD1) & BIT_endOfDStream(&bitD2) & BIT_endOfDStream(&bitD3) & BIT_endOfDStream(&bitD4);
if (!endSignal)
return ERROR(corruption_detected);
return dstSize;
}
}
size_t HUF_decompress4X2_usingDTable(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc dtd = HUF_getDTableDesc(DTable);
if (dtd.tableType != 0)
return ERROR(GENERIC);
return HUF_decompress4X2_usingDTable_internal(dst, dstSize, cSrc, cSrcSize, DTable);
}
size_t HUF_decompress4X2_DCtx_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
const BYTE *ip = (const BYTE *)cSrc;
size_t const hSize = HUF_readDTableX2_wksp(dctx, cSrc, cSrcSize, workspace, workspaceSize);
if (HUF_isError(hSize))
return hSize;
if (hSize >= cSrcSize)
return ERROR(srcSize_wrong);
ip += hSize;
cSrcSize -= hSize;
return HUF_decompress4X2_usingDTable_internal(dst, dstSize, ip, cSrcSize, dctx);
}
static void HUF_fillDTableX4Level2(HUF_DEltX4 *DTable, U32 sizeLog, const U32 consumed, const U32 *rankValOrigin, const int minWeight,
const sortedSymbol_t *sortedSymbols, const U32 sortedListSize, U32 nbBitsBaseline, U16 baseSeq)
{
HUF_DEltX4 DElt;
U32 rankVal[HUF_TABLELOG_MAX + 1];
memcpy(rankVal, rankValOrigin, sizeof(rankVal));
if (minWeight > 1) {
U32 i, skipSize = rankVal[minWeight];
ZSTD_writeLE16(&(DElt.sequence), baseSeq);
DElt.nbBits = (BYTE)(consumed);
DElt.length = 1;
for (i = 0; i < skipSize; i++)
DTable[i] = DElt;
}
{
U32 s;
for (s = 0; s < sortedListSize; s++) {
const U32 symbol = sortedSymbols[s].symbol;
const U32 weight = sortedSymbols[s].weight;
const U32 nbBits = nbBitsBaseline - weight;
const U32 length = 1 << (sizeLog - nbBits);
const U32 start = rankVal[weight];
U32 i = start;
const U32 end = start + length;
ZSTD_writeLE16(&(DElt.sequence), (U16)(baseSeq + (symbol << 8)));
DElt.nbBits = (BYTE)(nbBits + consumed);
DElt.length = 2;
do {
DTable[i++] = DElt;
} while (i < end);
rankVal[weight] += length;
}
}
}
static void HUF_fillDTableX4(HUF_DEltX4 *DTable, const U32 targetLog, const sortedSymbol_t *sortedList, const U32 sortedListSize, const U32 *rankStart,
rankVal_t rankValOrigin, const U32 maxWeight, const U32 nbBitsBaseline)
{
U32 rankVal[HUF_TABLELOG_MAX + 1];
const int scaleLog = nbBitsBaseline - targetLog;
const U32 minBits = nbBitsBaseline - maxWeight;
U32 s;
memcpy(rankVal, rankValOrigin, sizeof(rankVal));
for (s = 0; s < sortedListSize; s++) {
const U16 symbol = sortedList[s].symbol;
const U32 weight = sortedList[s].weight;
const U32 nbBits = nbBitsBaseline - weight;
const U32 start = rankVal[weight];
const U32 length = 1 << (targetLog - nbBits);
if (targetLog - nbBits >= minBits) {
U32 sortedRank;
int minWeight = nbBits + scaleLog;
if (minWeight < 1)
minWeight = 1;
sortedRank = rankStart[minWeight];
HUF_fillDTableX4Level2(DTable + start, targetLog - nbBits, nbBits, rankValOrigin[nbBits], minWeight, sortedList + sortedRank,
sortedListSize - sortedRank, nbBitsBaseline, symbol);
} else {
HUF_DEltX4 DElt;
ZSTD_writeLE16(&(DElt.sequence), symbol);
DElt.nbBits = (BYTE)(nbBits);
DElt.length = 1;
{
U32 const end = start + length;
U32 u;
for (u = start; u < end; u++)
DTable[u] = DElt;
}
}
rankVal[weight] += length;
}
}
size_t HUF_readDTableX4_wksp(HUF_DTable *DTable, const void *src, size_t srcSize, void *workspace, size_t workspaceSize)
{
U32 tableLog, maxW, sizeOfSort, nbSymbols;
DTableDesc dtd = HUF_getDTableDesc(DTable);
U32 const maxTableLog = dtd.maxTableLog;
size_t iSize;
void *dtPtr = DTable + 1;
HUF_DEltX4 *const dt = (HUF_DEltX4 *)dtPtr;
U32 *rankStart;
rankValCol_t *rankVal;
U32 *rankStats;
U32 *rankStart0;
sortedSymbol_t *sortedSymbol;
BYTE *weightList;
size_t spaceUsed32 = 0;
HUF_STATIC_ASSERT((sizeof(rankValCol_t) & 3) == 0);
rankVal = (rankValCol_t *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += (sizeof(rankValCol_t) * HUF_TABLELOG_MAX) >> 2;
rankStats = (U32 *)workspace + spaceUsed32;
spaceUsed32 += HUF_TABLELOG_MAX + 1;
rankStart0 = (U32 *)workspace + spaceUsed32;
spaceUsed32 += HUF_TABLELOG_MAX + 2;
sortedSymbol = (sortedSymbol_t *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(sizeof(sortedSymbol_t) * (HUF_SYMBOLVALUE_MAX + 1), sizeof(U32)) >> 2;
weightList = (BYTE *)((U32 *)workspace + spaceUsed32);
spaceUsed32 += ALIGN(HUF_SYMBOLVALUE_MAX + 1, sizeof(U32)) >> 2;
if ((spaceUsed32 << 2) > workspaceSize)
return ERROR(tableLog_tooLarge);
workspace = (U32 *)workspace + spaceUsed32;
workspaceSize -= (spaceUsed32 << 2);
rankStart = rankStart0 + 1;
memset(rankStats, 0, sizeof(U32) * (2 * HUF_TABLELOG_MAX + 2 + 1));
HUF_STATIC_ASSERT(sizeof(HUF_DEltX4) == sizeof(HUF_DTable));
if (maxTableLog > HUF_TABLELOG_MAX)
return ERROR(tableLog_tooLarge);
iSize = HUF_readStats_wksp(weightList, HUF_SYMBOLVALUE_MAX + 1, rankStats, &nbSymbols, &tableLog, src, srcSize, workspace, workspaceSize);
if (HUF_isError(iSize))
return iSize;
if (tableLog > maxTableLog)
return ERROR(tableLog_tooLarge);
for (maxW = tableLog; rankStats[maxW] == 0; maxW--) {
}
{
U32 w, nextRankStart = 0;
for (w = 1; w < maxW + 1; w++) {
U32 curr = nextRankStart;
nextRankStart += rankStats[w];
rankStart[w] = curr;
}
rankStart[0] = nextRankStart;
sizeOfSort = nextRankStart;
}
{
U32 s;
for (s = 0; s < nbSymbols; s++) {
U32 const w = weightList[s];
U32 const r = rankStart[w]++;
sortedSymbol[r].symbol = (BYTE)s;
sortedSymbol[r].weight = (BYTE)w;
}
rankStart[0] = 0;
}
{
U32 *const rankVal0 = rankVal[0];
{
int const rescale = (maxTableLog - tableLog) - 1;
U32 nextRankVal = 0;
U32 w;
for (w = 1; w < maxW + 1; w++) {
U32 curr = nextRankVal;
nextRankVal += rankStats[w] << (w + rescale);
rankVal0[w] = curr;
}
}
{
U32 const minBits = tableLog + 1 - maxW;
U32 consumed;
for (consumed = minBits; consumed < maxTableLog - minBits + 1; consumed++) {
U32 *const rankValPtr = rankVal[consumed];
U32 w;
for (w = 1; w < maxW + 1; w++) {
rankValPtr[w] = rankVal0[w] >> consumed;
}
}
}
}
HUF_fillDTableX4(dt, maxTableLog, sortedSymbol, sizeOfSort, rankStart0, rankVal, maxW, tableLog + 1);
dtd.tableLog = (BYTE)maxTableLog;
dtd.tableType = 1;
memcpy(DTable, &dtd, sizeof(dtd));
return iSize;
}
static U32 HUF_decodeSymbolX4(void *op, BIT_DStream_t *DStream, const HUF_DEltX4 *dt, const U32 dtLog)
{
size_t const val = BIT_lookBitsFast(DStream, dtLog);
memcpy(op, dt + val, 2);
BIT_skipBits(DStream, dt[val].nbBits);
return dt[val].length;
}
static U32 HUF_decodeLastSymbolX4(void *op, BIT_DStream_t *DStream, const HUF_DEltX4 *dt, const U32 dtLog)
{
size_t const val = BIT_lookBitsFast(DStream, dtLog);
memcpy(op, dt + val, 1);
if (dt[val].length == 1)
BIT_skipBits(DStream, dt[val].nbBits);
else {
if (DStream->bitsConsumed < (sizeof(DStream->bitContainer) * 8)) {
BIT_skipBits(DStream, dt[val].nbBits);
if (DStream->bitsConsumed > (sizeof(DStream->bitContainer) * 8))
DStream->bitsConsumed = (sizeof(DStream->bitContainer) * 8);
}
}
return 1;
}
FORCE_INLINE size_t HUF_decodeStreamX4(BYTE *p, BIT_DStream_t *bitDPtr, BYTE *const pEnd, const HUF_DEltX4 *const dt, const U32 dtLog)
{
BYTE *const pStart = p;
while ((BIT_reloadDStream(bitDPtr) == BIT_DStream_unfinished) & (p < pEnd - (sizeof(bitDPtr->bitContainer) - 1))) {
HUF_DECODE_SYMBOLX4_2(p, bitDPtr);
HUF_DECODE_SYMBOLX4_1(p, bitDPtr);
HUF_DECODE_SYMBOLX4_2(p, bitDPtr);
HUF_DECODE_SYMBOLX4_0(p, bitDPtr);
}
while ((BIT_reloadDStream(bitDPtr) == BIT_DStream_unfinished) & (p <= pEnd - 2))
HUF_DECODE_SYMBOLX4_0(p, bitDPtr);
while (p <= pEnd - 2)
HUF_DECODE_SYMBOLX4_0(p, bitDPtr);
if (p < pEnd)
p += HUF_decodeLastSymbolX4(p, bitDPtr, dt, dtLog);
return p - pStart;
}
static size_t HUF_decompress1X4_usingDTable_internal(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
BIT_DStream_t bitD;
{
size_t const errorCode = BIT_initDStream(&bitD, cSrc, cSrcSize);
if (HUF_isError(errorCode))
return errorCode;
}
{
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
const void *const dtPtr = DTable + 1;
const HUF_DEltX4 *const dt = (const HUF_DEltX4 *)dtPtr;
DTableDesc const dtd = HUF_getDTableDesc(DTable);
HUF_decodeStreamX4(ostart, &bitD, oend, dt, dtd.tableLog);
}
if (!BIT_endOfDStream(&bitD))
return ERROR(corruption_detected);
return dstSize;
}
size_t HUF_decompress1X4_usingDTable(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc dtd = HUF_getDTableDesc(DTable);
if (dtd.tableType != 1)
return ERROR(GENERIC);
return HUF_decompress1X4_usingDTable_internal(dst, dstSize, cSrc, cSrcSize, DTable);
}
size_t HUF_decompress1X4_DCtx_wksp(HUF_DTable *DCtx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
const BYTE *ip = (const BYTE *)cSrc;
size_t const hSize = HUF_readDTableX4_wksp(DCtx, cSrc, cSrcSize, workspace, workspaceSize);
if (HUF_isError(hSize))
return hSize;
if (hSize >= cSrcSize)
return ERROR(srcSize_wrong);
ip += hSize;
cSrcSize -= hSize;
return HUF_decompress1X4_usingDTable_internal(dst, dstSize, ip, cSrcSize, DCtx);
}
static size_t HUF_decompress4X4_usingDTable_internal(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
if (cSrcSize < 10)
return ERROR(corruption_detected);
{
const BYTE *const istart = (const BYTE *)cSrc;
BYTE *const ostart = (BYTE *)dst;
BYTE *const oend = ostart + dstSize;
const void *const dtPtr = DTable + 1;
const HUF_DEltX4 *const dt = (const HUF_DEltX4 *)dtPtr;
BIT_DStream_t bitD1;
BIT_DStream_t bitD2;
BIT_DStream_t bitD3;
BIT_DStream_t bitD4;
size_t const length1 = ZSTD_readLE16(istart);
size_t const length2 = ZSTD_readLE16(istart + 2);
size_t const length3 = ZSTD_readLE16(istart + 4);
size_t const length4 = cSrcSize - (length1 + length2 + length3 + 6);
const BYTE *const istart1 = istart + 6;
const BYTE *const istart2 = istart1 + length1;
const BYTE *const istart3 = istart2 + length2;
const BYTE *const istart4 = istart3 + length3;
size_t const segmentSize = (dstSize + 3) / 4;
BYTE *const opStart2 = ostart + segmentSize;
BYTE *const opStart3 = opStart2 + segmentSize;
BYTE *const opStart4 = opStart3 + segmentSize;
BYTE *op1 = ostart;
BYTE *op2 = opStart2;
BYTE *op3 = opStart3;
BYTE *op4 = opStart4;
U32 endSignal;
DTableDesc const dtd = HUF_getDTableDesc(DTable);
U32 const dtLog = dtd.tableLog;
if (length4 > cSrcSize)
return ERROR(corruption_detected);
{
size_t const errorCode = BIT_initDStream(&bitD1, istart1, length1);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD2, istart2, length2);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD3, istart3, length3);
if (HUF_isError(errorCode))
return errorCode;
}
{
size_t const errorCode = BIT_initDStream(&bitD4, istart4, length4);
if (HUF_isError(errorCode))
return errorCode;
}
endSignal = BIT_reloadDStream(&bitD1) | BIT_reloadDStream(&bitD2) | BIT_reloadDStream(&bitD3) | BIT_reloadDStream(&bitD4);
for (; (endSignal == BIT_DStream_unfinished) & (op4 < (oend - (sizeof(bitD4.bitContainer) - 1)));) {
HUF_DECODE_SYMBOLX4_2(op1, &bitD1);
HUF_DECODE_SYMBOLX4_2(op2, &bitD2);
HUF_DECODE_SYMBOLX4_2(op3, &bitD3);
HUF_DECODE_SYMBOLX4_2(op4, &bitD4);
HUF_DECODE_SYMBOLX4_1(op1, &bitD1);
HUF_DECODE_SYMBOLX4_1(op2, &bitD2);
HUF_DECODE_SYMBOLX4_1(op3, &bitD3);
HUF_DECODE_SYMBOLX4_1(op4, &bitD4);
HUF_DECODE_SYMBOLX4_2(op1, &bitD1);
HUF_DECODE_SYMBOLX4_2(op2, &bitD2);
HUF_DECODE_SYMBOLX4_2(op3, &bitD3);
HUF_DECODE_SYMBOLX4_2(op4, &bitD4);
HUF_DECODE_SYMBOLX4_0(op1, &bitD1);
HUF_DECODE_SYMBOLX4_0(op2, &bitD2);
HUF_DECODE_SYMBOLX4_0(op3, &bitD3);
HUF_DECODE_SYMBOLX4_0(op4, &bitD4);
endSignal = BIT_reloadDStream(&bitD1) | BIT_reloadDStream(&bitD2) | BIT_reloadDStream(&bitD3) | BIT_reloadDStream(&bitD4);
}
if (op1 > opStart2)
return ERROR(corruption_detected);
if (op2 > opStart3)
return ERROR(corruption_detected);
if (op3 > opStart4)
return ERROR(corruption_detected);
HUF_decodeStreamX4(op1, &bitD1, opStart2, dt, dtLog);
HUF_decodeStreamX4(op2, &bitD2, opStart3, dt, dtLog);
HUF_decodeStreamX4(op3, &bitD3, opStart4, dt, dtLog);
HUF_decodeStreamX4(op4, &bitD4, oend, dt, dtLog);
{
U32 const endCheck = BIT_endOfDStream(&bitD1) & BIT_endOfDStream(&bitD2) & BIT_endOfDStream(&bitD3) & BIT_endOfDStream(&bitD4);
if (!endCheck)
return ERROR(corruption_detected);
}
return dstSize;
}
}
size_t HUF_decompress4X4_usingDTable(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc dtd = HUF_getDTableDesc(DTable);
if (dtd.tableType != 1)
return ERROR(GENERIC);
return HUF_decompress4X4_usingDTable_internal(dst, dstSize, cSrc, cSrcSize, DTable);
}
size_t HUF_decompress4X4_DCtx_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
const BYTE *ip = (const BYTE *)cSrc;
size_t hSize = HUF_readDTableX4_wksp(dctx, cSrc, cSrcSize, workspace, workspaceSize);
if (HUF_isError(hSize))
return hSize;
if (hSize >= cSrcSize)
return ERROR(srcSize_wrong);
ip += hSize;
cSrcSize -= hSize;
return HUF_decompress4X4_usingDTable_internal(dst, dstSize, ip, cSrcSize, dctx);
}
size_t HUF_decompress1X_usingDTable(void *dst, size_t maxDstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc const dtd = HUF_getDTableDesc(DTable);
return dtd.tableType ? HUF_decompress1X4_usingDTable_internal(dst, maxDstSize, cSrc, cSrcSize, DTable)
: HUF_decompress1X2_usingDTable_internal(dst, maxDstSize, cSrc, cSrcSize, DTable);
}
size_t HUF_decompress4X_usingDTable(void *dst, size_t maxDstSize, const void *cSrc, size_t cSrcSize, const HUF_DTable *DTable)
{
DTableDesc const dtd = HUF_getDTableDesc(DTable);
return dtd.tableType ? HUF_decompress4X4_usingDTable_internal(dst, maxDstSize, cSrc, cSrcSize, DTable)
: HUF_decompress4X2_usingDTable_internal(dst, maxDstSize, cSrc, cSrcSize, DTable);
}
U32 HUF_selectDecoder(size_t dstSize, size_t cSrcSize)
{
U32 const Q = (U32)(cSrcSize * 16 / dstSize);
U32 const D256 = (U32)(dstSize >> 8);
U32 const DTime0 = algoTime[Q][0].tableTime + (algoTime[Q][0].decode256Time * D256);
U32 DTime1 = algoTime[Q][1].tableTime + (algoTime[Q][1].decode256Time * D256);
DTime1 += DTime1 >> 3;
return DTime1 < DTime0;
}
size_t HUF_decompress4X_DCtx_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
if (dstSize == 0)
return ERROR(dstSize_tooSmall);
if (cSrcSize > dstSize)
return ERROR(corruption_detected);
if (cSrcSize == dstSize) {
memcpy(dst, cSrc, dstSize);
return dstSize;
}
if (cSrcSize == 1) {
memset(dst, *(const BYTE *)cSrc, dstSize);
return dstSize;
}
{
U32 const algoNb = HUF_selectDecoder(dstSize, cSrcSize);
return algoNb ? HUF_decompress4X4_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize)
: HUF_decompress4X2_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize);
}
}
size_t HUF_decompress4X_hufOnly_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
if (dstSize == 0)
return ERROR(dstSize_tooSmall);
if ((cSrcSize >= dstSize) || (cSrcSize <= 1))
return ERROR(corruption_detected);
{
U32 const algoNb = HUF_selectDecoder(dstSize, cSrcSize);
return algoNb ? HUF_decompress4X4_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize)
: HUF_decompress4X2_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize);
}
}
size_t HUF_decompress1X_DCtx_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
if (dstSize == 0)
return ERROR(dstSize_tooSmall);
if (cSrcSize > dstSize)
return ERROR(corruption_detected);
if (cSrcSize == dstSize) {
memcpy(dst, cSrc, dstSize);
return dstSize;
}
if (cSrcSize == 1) {
memset(dst, *(const BYTE *)cSrc, dstSize);
return dstSize;
}
{
U32 const algoNb = HUF_selectDecoder(dstSize, cSrcSize);
return algoNb ? HUF_decompress1X4_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize)
: HUF_decompress1X2_DCtx_wksp(dctx, dst, dstSize, cSrc, cSrcSize, workspace, workspaceSize);
}
}
