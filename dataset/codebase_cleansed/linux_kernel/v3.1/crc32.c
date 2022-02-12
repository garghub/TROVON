u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
int i;
while (len--) {
crc ^= *p++;
for (i = 0; i < 8; i++)
crc = (crc >> 1) ^ ((crc & 1) ? CRCPOLY_LE : 0);
}
return crc;
}
u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
# if CRC_LE_BITS == 8
const u32 (*tab)[] = crc32table_le;
crc = __cpu_to_le32(crc);
crc = crc32_body(crc, p, len, tab);
return __le32_to_cpu(crc);
# elif CRC_LE_BITS == 4
while (len--) {
crc ^= *p++;
crc = (crc >> 4) ^ crc32table_le[crc & 15];
crc = (crc >> 4) ^ crc32table_le[crc & 15];
}
return crc;
# elif CRC_LE_BITS == 2
while (len--) {
crc ^= *p++;
crc = (crc >> 2) ^ crc32table_le[crc & 3];
crc = (crc >> 2) ^ crc32table_le[crc & 3];
crc = (crc >> 2) ^ crc32table_le[crc & 3];
crc = (crc >> 2) ^ crc32table_le[crc & 3];
}
return crc;
# endif
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
int i;
while (len--) {
crc ^= *p++ << 24;
for (i = 0; i < 8; i++)
crc =
(crc << 1) ^ ((crc & 0x80000000) ? CRCPOLY_BE :
0);
}
return crc;
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
# if CRC_BE_BITS == 8
const u32 (*tab)[] = crc32table_be;
crc = __cpu_to_be32(crc);
crc = crc32_body(crc, p, len, tab);
return __be32_to_cpu(crc);
# elif CRC_BE_BITS == 4
while (len--) {
crc ^= *p++ << 24;
crc = (crc << 4) ^ crc32table_be[crc >> 28];
crc = (crc << 4) ^ crc32table_be[crc >> 28];
}
return crc;
# elif CRC_BE_BITS == 2
while (len--) {
crc ^= *p++ << 24;
crc = (crc << 2) ^ crc32table_be[crc >> 30];
crc = (crc << 2) ^ crc32table_be[crc >> 30];
crc = (crc << 2) ^ crc32table_be[crc >> 30];
crc = (crc << 2) ^ crc32table_be[crc >> 30];
}
return crc;
# endif
}
static void bytereverse(unsigned char *buf, size_t len)
{
while (len--) {
unsigned char x = bitrev8(*buf);
*buf++ = x;
}
}
static void random_garbage(unsigned char *buf, size_t len)
{
while (len--)
*buf++ = (unsigned char) random();
}
static void store_be(u32 x, unsigned char *buf)
{
buf[0] = (unsigned char) (x >> 24);
buf[1] = (unsigned char) (x >> 16);
buf[2] = (unsigned char) (x >> 8);
buf[3] = (unsigned char) x;
}
static u32 test_step(u32 init, unsigned char *buf, size_t len)
{
u32 crc1, crc2;
size_t i;
crc1 = crc32_be(init, buf, len);
store_be(crc1, buf + len);
crc2 = crc32_be(init, buf, len + 4);
if (crc2)
printf("\nCRC cancellation fail: 0x%08x should be 0\n",
crc2);
for (i = 0; i <= len + 4; i++) {
crc2 = crc32_be(init, buf, i);
crc2 = crc32_be(crc2, buf + i, len + 4 - i);
if (crc2)
printf("\nCRC split fail: 0x%08x\n", crc2);
}
bytereverse(buf, len + 4);
init = bitrev32(init);
crc2 = bitrev32(crc1);
if (crc1 != bitrev32(crc2))
printf("\nBit reversal fail: 0x%08x -> 0x%08x -> 0x%08x\n",
crc1, crc2, bitrev32(crc2));
crc1 = crc32_le(init, buf, len);
if (crc1 != crc2)
printf("\nCRC endianness fail: 0x%08x != 0x%08x\n", crc1,
crc2);
crc2 = crc32_le(init, buf, len + 4);
if (crc2)
printf("\nCRC cancellation fail: 0x%08x should be 0\n",
crc2);
for (i = 0; i <= len + 4; i++) {
crc2 = crc32_le(init, buf, i);
crc2 = crc32_le(crc2, buf + i, len + 4 - i);
if (crc2)
printf("\nCRC split fail: 0x%08x\n", crc2);
}
return crc1;
}
int main(void)
{
unsigned char buf1[SIZE + 4];
unsigned char buf2[SIZE + 4];
unsigned char buf3[SIZE + 4];
int i, j;
u32 crc1, crc2, crc3;
for (i = 0; i <= SIZE; i++) {
printf("\rTesting length %d...", i);
fflush(stdout);
random_garbage(buf1, i);
random_garbage(buf2, i);
for (j = 0; j < i; j++)
buf3[j] = buf1[j] ^ buf2[j];
crc1 = test_step(INIT1, buf1, i);
crc2 = test_step(INIT2, buf2, i);
crc3 = test_step(INIT1 ^ INIT2, buf3, i);
if (crc3 != (crc1 ^ crc2))
printf("CRC XOR fail: 0x%08x != 0x%08x ^ 0x%08x\n",
crc3, crc1, crc2);
}
printf("\nAll test complete. No failures expected.\n");
return 0;
}
