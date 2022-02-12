DWORD CRCdwCrc32(PBYTE pbyData, unsigned int cbByte, DWORD dwCrcSeed)
{
DWORD dwCrc;
dwCrc = dwCrcSeed;
while (cbByte--) {
dwCrc = s_adwCrc32Table[(BYTE)((dwCrc ^ (*pbyData)) & 0xFF)] ^
(dwCrc >> 8);
pbyData++;
}
return dwCrc;
}
DWORD CRCdwGetCrc32(PBYTE pbyData, unsigned int cbByte)
{
return ~CRCdwCrc32(pbyData, cbByte, 0xFFFFFFFFL);
}
DWORD CRCdwGetCrc32Ex(PBYTE pbyData, unsigned int cbByte, DWORD dwPreCRC)
{
return CRCdwCrc32(pbyData, cbByte, dwPreCRC);
}
