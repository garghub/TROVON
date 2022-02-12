u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, NULL, CRCPOLY_LE);
}
u32 __pure __crc32c_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, NULL, CRC32C_POLY_LE);
}
u32 __pure crc32_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, crc32table_le, CRCPOLY_LE);
}
u32 __pure __crc32c_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len, crc32ctable_le, CRC32C_POLY_LE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len, NULL, CRCPOLY_BE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len, crc32table_be, CRCPOLY_BE);
}
static int __init crc32c_test(void)
{
int i;
int errors = 0;
int bytes = 0;
struct timespec start, stop;
u64 nsec;
unsigned long flags;
static u32 crc;
for (i = 0; i < 100; i++) {
bytes += 2*test[i].length;
crc ^= __crc32c_le(test[i].crc, test_buf +
test[i].start, test[i].length);
}
local_irq_save(flags);
local_irq_disable();
getnstimeofday(&start);
for (i = 0; i < 100; i++) {
if (test[i].crc32c_le != __crc32c_le(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
}
getnstimeofday(&stop);
local_irq_restore(flags);
local_irq_enable();
nsec = stop.tv_nsec - start.tv_nsec +
1000000000 * (stop.tv_sec - start.tv_sec);
pr_info("crc32c: CRC_LE_BITS = %d\n", CRC_LE_BITS);
if (errors)
pr_warn("crc32c: %d self tests failed\n", errors);
else {
pr_info("crc32c: self tests passed, processed %d bytes in %lld nsec\n",
bytes, nsec);
}
return 0;
}
static int __init crc32_test(void)
{
int i;
int errors = 0;
int bytes = 0;
struct timespec start, stop;
u64 nsec;
unsigned long flags;
static u32 crc;
for (i = 0; i < 100; i++) {
bytes += 2*test[i].length;
crc ^= crc32_le(test[i].crc, test_buf +
test[i].start, test[i].length);
crc ^= crc32_be(test[i].crc, test_buf +
test[i].start, test[i].length);
}
local_irq_save(flags);
local_irq_disable();
getnstimeofday(&start);
for (i = 0; i < 100; i++) {
if (test[i].crc_le != crc32_le(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
if (test[i].crc_be != crc32_be(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
}
getnstimeofday(&stop);
local_irq_restore(flags);
local_irq_enable();
nsec = stop.tv_nsec - start.tv_nsec +
1000000000 * (stop.tv_sec - start.tv_sec);
pr_info("crc32: CRC_LE_BITS = %d, CRC_BE BITS = %d\n",
CRC_LE_BITS, CRC_BE_BITS);
if (errors)
pr_warn("crc32: %d self tests failed\n", errors);
else {
pr_info("crc32: self tests passed, processed %d bytes in %lld nsec\n",
bytes, nsec);
}
return 0;
}
static int __init crc32test_init(void)
{
crc32_test();
crc32c_test();
return 0;
}
static void __exit crc32_exit(void)
{
}
