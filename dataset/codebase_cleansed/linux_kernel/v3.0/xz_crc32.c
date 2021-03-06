XZ_EXTERN void xz_crc32_init(void)
{
const uint32_t poly = 0xEDB88320;
uint32_t i;
uint32_t j;
uint32_t r;
for (i = 0; i < 256; ++i) {
r = i;
for (j = 0; j < 8; ++j)
r = (r >> 1) ^ (poly & ~((r & 1) - 1));
xz_crc32_table[i] = r;
}
return;
}
XZ_EXTERN uint32_t xz_crc32(const uint8_t *buf, size_t size, uint32_t crc)
{
crc = ~crc;
while (size != 0) {
crc = xz_crc32_table[*buf++ ^ (crc & 0xFF)] ^ (crc >> 8);
--size;
}
return ~crc;
}
