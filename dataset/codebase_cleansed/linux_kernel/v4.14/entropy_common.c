unsigned FSE_versionNumber(void) { return FSE_VERSION_NUMBER; }
unsigned FSE_isError(size_t code) { return ERR_isError(code); }
unsigned HUF_isError(size_t code) { return ERR_isError(code); }
size_t FSE_readNCount(short *normalizedCounter, unsigned *maxSVPtr, unsigned *tableLogPtr, const void *headerBuffer, size_t hbSize)
{
const BYTE *const istart = (const BYTE *)headerBuffer;
const BYTE *const iend = istart + hbSize;
const BYTE *ip = istart;
int nbBits;
int remaining;
int threshold;
U32 bitStream;
int bitCount;
unsigned charnum = 0;
int previous0 = 0;
if (hbSize < 4)
return ERROR(srcSize_wrong);
bitStream = ZSTD_readLE32(ip);
nbBits = (bitStream & 0xF) + FSE_MIN_TABLELOG;
if (nbBits > FSE_TABLELOG_ABSOLUTE_MAX)
return ERROR(tableLog_tooLarge);
bitStream >>= 4;
bitCount = 4;
*tableLogPtr = nbBits;
remaining = (1 << nbBits) + 1;
threshold = 1 << nbBits;
nbBits++;
while ((remaining > 1) & (charnum <= *maxSVPtr)) {
if (previous0) {
unsigned n0 = charnum;
while ((bitStream & 0xFFFF) == 0xFFFF) {
n0 += 24;
if (ip < iend - 5) {
ip += 2;
bitStream = ZSTD_readLE32(ip) >> bitCount;
} else {
bitStream >>= 16;
bitCount += 16;
}
}
while ((bitStream & 3) == 3) {
n0 += 3;
bitStream >>= 2;
bitCount += 2;
}
n0 += bitStream & 3;
bitCount += 2;
if (n0 > *maxSVPtr)
return ERROR(maxSymbolValue_tooSmall);
while (charnum < n0)
normalizedCounter[charnum++] = 0;
if ((ip <= iend - 7) || (ip + (bitCount >> 3) <= iend - 4)) {
ip += bitCount >> 3;
bitCount &= 7;
bitStream = ZSTD_readLE32(ip) >> bitCount;
} else {
bitStream >>= 2;
}
}
{
int const max = (2 * threshold - 1) - remaining;
int count;
if ((bitStream & (threshold - 1)) < (U32)max) {
count = bitStream & (threshold - 1);
bitCount += nbBits - 1;
} else {
count = bitStream & (2 * threshold - 1);
if (count >= threshold)
count -= max;
bitCount += nbBits;
}
count--;
remaining -= count < 0 ? -count : count;
normalizedCounter[charnum++] = (short)count;
previous0 = !count;
while (remaining < threshold) {
nbBits--;
threshold >>= 1;
}
if ((ip <= iend - 7) || (ip + (bitCount >> 3) <= iend - 4)) {
ip += bitCount >> 3;
bitCount &= 7;
} else {
bitCount -= (int)(8 * (iend - 4 - ip));
ip = iend - 4;
}
bitStream = ZSTD_readLE32(ip) >> (bitCount & 31);
}
}
if (remaining != 1)
return ERROR(corruption_detected);
if (bitCount > 32)
return ERROR(corruption_detected);
*maxSVPtr = charnum - 1;
ip += (bitCount + 7) >> 3;
return ip - istart;
}
size_t HUF_readStats_wksp(BYTE *huffWeight, size_t hwSize, U32 *rankStats, U32 *nbSymbolsPtr, U32 *tableLogPtr, const void *src, size_t srcSize, void *workspace, size_t workspaceSize)
{
U32 weightTotal;
const BYTE *ip = (const BYTE *)src;
size_t iSize;
size_t oSize;
if (!srcSize)
return ERROR(srcSize_wrong);
iSize = ip[0];
if (iSize >= 128) {
oSize = iSize - 127;
iSize = ((oSize + 1) / 2);
if (iSize + 1 > srcSize)
return ERROR(srcSize_wrong);
if (oSize >= hwSize)
return ERROR(corruption_detected);
ip += 1;
{
U32 n;
for (n = 0; n < oSize; n += 2) {
huffWeight[n] = ip[n / 2] >> 4;
huffWeight[n + 1] = ip[n / 2] & 15;
}
}
} else {
if (iSize + 1 > srcSize)
return ERROR(srcSize_wrong);
oSize = FSE_decompress_wksp(huffWeight, hwSize - 1, ip + 1, iSize, 6, workspace, workspaceSize);
if (FSE_isError(oSize))
return oSize;
}
memset(rankStats, 0, (HUF_TABLELOG_MAX + 1) * sizeof(U32));
weightTotal = 0;
{
U32 n;
for (n = 0; n < oSize; n++) {
if (huffWeight[n] >= HUF_TABLELOG_MAX)
return ERROR(corruption_detected);
rankStats[huffWeight[n]]++;
weightTotal += (1 << huffWeight[n]) >> 1;
}
}
if (weightTotal == 0)
return ERROR(corruption_detected);
{
U32 const tableLog = BIT_highbit32(weightTotal) + 1;
if (tableLog > HUF_TABLELOG_MAX)
return ERROR(corruption_detected);
*tableLogPtr = tableLog;
{
U32 const total = 1 << tableLog;
U32 const rest = total - weightTotal;
U32 const verif = 1 << BIT_highbit32(rest);
U32 const lastWeight = BIT_highbit32(rest) + 1;
if (verif != rest)
return ERROR(corruption_detected);
huffWeight[oSize] = (BYTE)lastWeight;
rankStats[lastWeight]++;
}
}
if ((rankStats[1] < 2) || (rankStats[1] & 1))
return ERROR(corruption_detected);
*nbSymbolsPtr = (U32)(oSize + 1);
return iSize + 1;
}
