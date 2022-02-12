static u32 crc32c_vpmsum(u32 crc, unsigned char const *p, size_t len)
{
unsigned int prealign;
unsigned int tail;
if (len < (VECTOR_BREAKPOINT + VMX_ALIGN) || in_interrupt())
return __crc32c_le(crc, p, len);
if ((unsigned long)p & VMX_ALIGN_MASK) {
prealign = VMX_ALIGN - ((unsigned long)p & VMX_ALIGN_MASK);
crc = __crc32c_le(crc, p, prealign);
len -= prealign;
p += prealign;
}
if (len & ~VMX_ALIGN_MASK) {
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
crc = __crc32c_vpmsum(crc, p, len & ~VMX_ALIGN_MASK);
disable_kernel_altivec();
pagefault_enable();
preempt_enable();
}
tail = len & VMX_ALIGN_MASK;
if (tail) {
p += len & ~VMX_ALIGN_MASK;
crc = __crc32c_le(crc, p, tail);
}
return crc;
}
static int crc32c_vpmsum_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = ~0;
return 0;
}
static int crc32c_vpmsum_setkey(struct crypto_shash *hash, const u8 *key,
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
static int crc32c_vpmsum_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *crcp = shash_desc_ctx(desc);
*crcp = *mctx;
return 0;
}
static int crc32c_vpmsum_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *crcp = shash_desc_ctx(desc);
*crcp = crc32c_vpmsum(*crcp, data, len);
return 0;
}
static int __crc32c_vpmsum_finup(u32 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
*(__le32 *)out = ~cpu_to_le32(crc32c_vpmsum(*crcp, data, len));
return 0;
}
static int crc32c_vpmsum_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_vpmsum_finup(shash_desc_ctx(desc), data, len, out);
}
static int crc32c_vpmsum_final(struct shash_desc *desc, u8 *out)
{
u32 *crcp = shash_desc_ctx(desc);
*(__le32 *)out = ~cpu_to_le32p(crcp);
return 0;
}
static int crc32c_vpmsum_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_vpmsum_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
static int __init crc32c_vpmsum_mod_init(void)
{
if (!cpu_has_feature(CPU_FTR_ARCH_207S))
return -ENODEV;
return crypto_register_shash(&alg);
}
static void __exit crc32c_vpmsum_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
