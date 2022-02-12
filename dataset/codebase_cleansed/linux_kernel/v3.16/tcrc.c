unsigned long CRCdwCrc32(unsigned char *pbyData, unsigned int cbByte, unsigned long dwCrcSeed)
{
unsigned long dwCrc;
dwCrc = dwCrcSeed;
while (cbByte--) {
dwCrc = s_adwCrc32Table[(unsigned char)((dwCrc ^ (*pbyData)) & 0xFF)] ^ (dwCrc >> 8);
pbyData++;
}
return dwCrc;
}
unsigned long CRCdwGetCrc32(unsigned char *pbyData, unsigned int cbByte)
{
return ~CRCdwCrc32(pbyData, cbByte, 0xFFFFFFFFL);
}
unsigned long CRCdwGetCrc32Ex(unsigned char *pbyData, unsigned int cbByte, unsigned long dwPreCRC)
{
return CRCdwCrc32(pbyData, cbByte, dwPreCRC);
}
