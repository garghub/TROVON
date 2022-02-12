u32 CRCdwCrc32(u8 * pbyData, unsigned int cbByte, u32 dwCrcSeed)
{
u32 dwCrc;
dwCrc = dwCrcSeed;
while (cbByte--) {
dwCrc = s_adwCrc32Table[(u8)((dwCrc ^ (*pbyData)) & 0xFF)] ^
(dwCrc >> 8);
pbyData++;
}
return dwCrc;
}
u32 CRCdwGetCrc32(u8 * pbyData, unsigned int cbByte)
{
return ~CRCdwCrc32(pbyData, cbByte, 0xFFFFFFFFL);
}
u32 CRCdwGetCrc32Ex(u8 * pbyData, unsigned int cbByte, u32 dwPreCRC)
{
return CRCdwCrc32(pbyData, cbByte, dwPreCRC);
}
