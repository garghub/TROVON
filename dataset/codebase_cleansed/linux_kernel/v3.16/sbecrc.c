static void
genCrcTable(u_int32_t *CRCTable)
{
int ii, jj;
u_int32_t crc;
for (ii = 0; ii < CRC_TABLE_ENTRIES; ii++) {
crc = ii;
for (jj = 8; jj > 0; jj--) {
if (crc & 1)
crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
else
crc >>= 1;
}
CRCTable[ii] = crc;
}
crcTableInit++;
}
void
sbeCrc(u_int8_t *buffer,
u_int32_t count,
u_int32_t initialCrc,
u_int32_t *result)
{
u_int32_t *tbl = NULL;
u_int32_t temp1, temp2, crc;
if (!crcTableInit) {
#ifdef STATIC_CRC_TABLE
tbl = &CRCTable;
genCrcTable(tbl);
#else
tbl = kzalloc(CRC_TABLE_ENTRIES * sizeof(u_int32_t),
GFP_KERNEL);
if (!tbl) {
*result = 0;
return;
}
genCrcTable(tbl);
#endif
}
crc = initialCrc ^ 0xFFFFFFFFL;
while (count-- != 0) {
temp1 = (crc >> 8) & 0x00FFFFFFL;
temp2 = tbl[((int) crc ^ *buffer++) & 0xff];
crc = temp1 ^ temp2;
}
crc ^= 0xFFFFFFFFL;
*result = crc;
#ifndef STATIC_CRC_TABLE
crcTableInit = 0;
kfree(tbl);
#endif
}
