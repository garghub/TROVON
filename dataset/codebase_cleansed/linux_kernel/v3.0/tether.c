unsigned char ETHbyGetHashIndexByCrc32 (unsigned char *pbyMultiAddr)
{
int ii;
unsigned char byTmpHash;
unsigned char byHash = 0;
byTmpHash = (unsigned char)(CRCdwCrc32(pbyMultiAddr, ETH_ALEN,
0xFFFFFFFFL) & 0x3F);
for (ii = 0; ii < (sizeof(byTmpHash) * 8); ii++) {
byHash <<= 1;
if (byTmpHash & 0x01)
byHash |= 1;
byTmpHash >>= 1;
}
return (byHash >> 2);
}
bool ETHbIsBufferCrc32Ok (unsigned char *pbyBuffer, unsigned int cbFrameLength)
{
unsigned long dwCRC;
dwCRC = CRCdwGetCrc32(pbyBuffer, cbFrameLength - 4);
if (cpu_to_le32(*((unsigned long *)(pbyBuffer + cbFrameLength - 4))) != dwCRC) {
return false;
}
return true;
}
