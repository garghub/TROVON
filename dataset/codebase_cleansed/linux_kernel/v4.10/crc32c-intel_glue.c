static u32 crc32c_intel_le_hw_byte(u32 crc, unsigned char const *data, size_t length)
{
while (length--) {
__asm__ __volatile__(
".byte 0xf2, 0xf, 0x38, 0xf0, 0xf1"
:"=S"(crc)
:"0"(crc), "c"(*data)
);
data++;
}
return crc;
}
static u32 __pure crc32c_intel_le_hw(u32 crc, unsigned char const *p, size_t len)
{
unsigned int iquotient = len / SCALE_F;
unsigned int iremainder = len % SCALE_F;
unsigned long *ptmp = (unsigned long *)p;
while (iquotient--) {
__asm__ __volatile__(
".byte 0xf2, " REX_PRE "0xf, 0x38, 0xf1, 0xf1;"
:"=S"(crc)
:"0"(crc), "c"(*ptmp)
);
ptmp++;
}
if (iremainder)
crc = crc32c_intel_le_hw_byte(crc, (unsigned char *)ptmp,
iremainder);
return crc;
}
static int crc32c_intel_setkey(struct crypto_shash *hash, const u8 *key,
unsigned int keylen)
{
u32 *mctx = crypto_shash_ctx(hash);
if (keylen != sizeof(u32)) {
crypto_shash_set_flags(hash, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
*mctx = le32_to_cpup((__le32 *)key);
return 0;
}
static int crc32c_intel_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *crcp = shash_desc_ctx(desc);
*crcp = *mctx;
return 0;
}
static int crc32c_intel_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *crcp = shash_desc_ctx(desc);
*crcp = crc32c_intel_le_hw(*crcp, data, len);
return 0;
}
static int __crc32c_intel_finup(u32 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
*(__le32 *)out = ~cpu_to_le32(crc32c_intel_le_hw(*crcp, data, len));
return 0;
}
static int crc32c_intel_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_intel_finup(shash_desc_ctx(desc), data, len, out);
}
static int crc32c_intel_final(struct shash_desc *desc, u8 *out)
{
u32 *crcp = shash_desc_ctx(desc);
*(__le32 *)out = ~cpu_to_le32p(crcp);
return 0;
}
static int crc32c_intel_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_intel_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
static int crc32c_intel_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = ~0;
return 0;
}
static int crc32c_pcl_intel_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *crcp = shash_desc_ctx(desc);
if (len >= CRC32C_PCL_BREAKEVEN && irq_fpu_usable()) {
kernel_fpu_begin();
*crcp = crc_pcl(data, len, *crcp);
kernel_fpu_end();
} else
*crcp = crc32c_intel_le_hw(*crcp, data, len);
return 0;
}
static int __crc32c_pcl_intel_finup(u32 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
if (len >= CRC32C_PCL_BREAKEVEN && irq_fpu_usable()) {
kernel_fpu_begin();
*(__le32 *)out = ~cpu_to_le32(crc_pcl(data, len, *crcp));
kernel_fpu_end();
} else
*(__le32 *)out =
~cpu_to_le32(crc32c_intel_le_hw(*crcp, data, len));
return 0;
}
static int crc32c_pcl_intel_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_pcl_intel_finup(shash_desc_ctx(desc), data, len, out);
}
static int crc32c_pcl_intel_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_pcl_intel_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
static int __init crc32c_intel_mod_init(void)
{
if (!x86_match_cpu(crc32c_cpu_id))
return -ENODEV;
#ifdef CONFIG_X86_64
if (boot_cpu_has(X86_FEATURE_PCLMULQDQ)) {
alg.update = crc32c_pcl_intel_update;
alg.finup = crc32c_pcl_intel_finup;
alg.digest = crc32c_pcl_intel_digest;
}
#endif
return crypto_register_shash(&alg);
}
static void __exit crc32c_intel_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
