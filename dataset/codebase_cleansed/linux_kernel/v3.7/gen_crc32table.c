static void crc32init_le(void)
{
crc32init_le_generic(CRCPOLY_LE, crc32table_le);
}
static void crc32cinit_le(void)
{
crc32init_le_generic(CRC32C_POLY_LE, crc32ctable_le);
}
static void crc32init_be(void)
{
unsigned i, j;
uint32_t crc = 0x80000000;
crc32table_be[0][0] = 0;
for (i = 1; i < BE_TABLE_SIZE; i <<= 1) {
crc = (crc << 1) ^ ((crc & 0x80000000) ? CRCPOLY_BE : 0);
for (j = 0; j < i; j++)
crc32table_be[0][i + j] = crc ^ crc32table_be[0][j];
}
for (i = 0; i < BE_TABLE_SIZE; i++) {
crc = crc32table_be[0][i];
for (j = 1; j < BE_TABLE_ROWS; j++) {
crc = crc32table_be[0][(crc >> 24) & 0xff] ^ (crc << 8);
crc32table_be[j][i] = crc;
}
}
}
int main(int argc, char** argv)
{
printf("/* this file is generated - do not edit */\n\n");
if (CRC_LE_BITS > 1) {
crc32init_le();
printf("static u32 __cacheline_aligned "
"crc32table_le[%d][%d] = {",
LE_TABLE_ROWS, LE_TABLE_SIZE);
output_table(crc32table_le, LE_TABLE_ROWS,
LE_TABLE_SIZE, "tole");
printf("};\n");
}
if (CRC_BE_BITS > 1) {
crc32init_be();
printf("static u32 __cacheline_aligned "
"crc32table_be[%d][%d] = {",
BE_TABLE_ROWS, BE_TABLE_SIZE);
output_table(crc32table_be, LE_TABLE_ROWS,
BE_TABLE_SIZE, "tobe");
printf("};\n");
}
if (CRC_LE_BITS > 1) {
crc32cinit_le();
printf("static u32 __cacheline_aligned "
"crc32ctable_le[%d][%d] = {",
LE_TABLE_ROWS, LE_TABLE_SIZE);
output_table(crc32ctable_le, LE_TABLE_ROWS,
LE_TABLE_SIZE, "tole");
printf("};\n");
}
return 0;
}
