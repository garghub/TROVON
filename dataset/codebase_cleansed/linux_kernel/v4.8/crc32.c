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
return crc32_le_generic(crc, p, len,
(const u32 (*)[256])crc32table_le, CRCPOLY_LE);
}
u32 __pure __crc32c_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le_generic(crc, p, len,
(const u32 (*)[256])crc32ctable_le, CRC32C_POLY_LE);
}
static u32 __attribute_const__ gf2_multiply(u32 x, u32 y, u32 modulus)
{
u32 product = x & 1 ? y : 0;
int i;
for (i = 0; i < 31; i++) {
product = (product >> 1) ^ (product & 1 ? modulus : 0);
x >>= 1;
product ^= x & 1 ? y : 0;
}
return product;
}
static u32 __attribute_const__ crc32_generic_shift(u32 crc, size_t len,
u32 polynomial)
{
u32 power = polynomial;
int i;
for (i = 0; i < 8 * (int)(len & 3); i++)
crc = (crc >> 1) ^ (crc & 1 ? polynomial : 0);
len >>= 2;
if (!len)
return crc;
for (;;) {
if (len & 1)
crc = gf2_multiply(crc, power, polynomial);
len >>= 1;
if (!len)
break;
power = gf2_multiply(power, power, polynomial);
}
return crc;
}
u32 __attribute_const__ crc32_le_shift(u32 crc, size_t len)
{
return crc32_generic_shift(crc, len, CRCPOLY_LE);
}
u32 __attribute_const__ __crc32c_le_shift(u32 crc, size_t len)
{
return crc32_generic_shift(crc, len, CRC32C_POLY_LE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len, NULL, CRCPOLY_BE);
}
u32 __pure crc32_be(u32 crc, unsigned char const *p, size_t len)
{
return crc32_be_generic(crc, p, len,
(const u32 (*)[256])crc32table_be, CRCPOLY_BE);
}
static int __init crc32c_test(void)
{
int i;
int errors = 0;
int bytes = 0;
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
nsec = ktime_get_ns();
for (i = 0; i < 100; i++) {
if (test[i].crc32c_le != __crc32c_le(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
}
nsec = ktime_get_ns() - nsec;
local_irq_restore(flags);
local_irq_enable();
pr_info("crc32c: CRC_LE_BITS = %d\n", CRC_LE_BITS);
if (errors)
pr_warn("crc32c: %d self tests failed\n", errors);
else {
pr_info("crc32c: self tests passed, processed %d bytes in %lld nsec\n",
bytes, nsec);
}
return 0;
}
static int __init crc32c_combine_test(void)
{
int i, j;
int errors = 0, runs = 0;
for (i = 0; i < 10; i++) {
u32 crc_full;
crc_full = __crc32c_le(test[i].crc, test_buf + test[i].start,
test[i].length);
for (j = 0; j <= test[i].length; ++j) {
u32 crc1, crc2;
u32 len1 = j, len2 = test[i].length - j;
crc1 = __crc32c_le(test[i].crc, test_buf +
test[i].start, len1);
crc2 = __crc32c_le(0, test_buf + test[i].start +
len1, len2);
if (!(crc_full == __crc32c_le_combine(crc1, crc2, len2) &&
crc_full == test[i].crc32c_le))
errors++;
runs++;
cond_resched();
}
}
if (errors)
pr_warn("crc32c_combine: %d/%d self tests failed\n", errors, runs);
else
pr_info("crc32c_combine: %d self tests passed\n", runs);
return 0;
}
static int __init crc32_test(void)
{
int i;
int errors = 0;
int bytes = 0;
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
nsec = ktime_get_ns();
for (i = 0; i < 100; i++) {
if (test[i].crc_le != crc32_le(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
if (test[i].crc_be != crc32_be(test[i].crc, test_buf +
test[i].start, test[i].length))
errors++;
}
nsec = ktime_get_ns() - nsec;
local_irq_restore(flags);
local_irq_enable();
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
static int __init crc32_combine_test(void)
{
int i, j;
int errors = 0, runs = 0;
for (i = 0; i < 10; i++) {
u32 crc_full;
crc_full = crc32_le(test[i].crc, test_buf + test[i].start,
test[i].length);
for (j = 0; j <= test[i].length; ++j) {
u32 crc1, crc2;
u32 len1 = j, len2 = test[i].length - j;
crc1 = crc32_le(test[i].crc, test_buf +
test[i].start, len1);
crc2 = crc32_le(0, test_buf + test[i].start +
len1, len2);
if (!(crc_full == crc32_le_combine(crc1, crc2, len2) &&
crc_full == test[i].crc_le))
errors++;
runs++;
cond_resched();
}
}
if (errors)
pr_warn("crc32_combine: %d/%d self tests failed\n", errors, runs);
else
pr_info("crc32_combine: %d self tests passed\n", runs);
return 0;
}
static int __init crc32test_init(void)
{
crc32_test();
crc32c_test();
crc32_combine_test();
crc32c_combine_test();
return 0;
}
static void __exit crc32_exit(void)
{
}
