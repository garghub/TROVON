static int crc32_pmull_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = 0;
return 0;
}
static int crc32c_pmull_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = ~0;
return 0;
}
static int crc32_pmull_setkey(struct crypto_shash *hash, const u8 *key,
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
static int crc32_pmull_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *crc = shash_desc_ctx(desc);
*crc = *mctx;
return 0;
}
static int crc32_pmull_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
u32 *crc = shash_desc_ctx(desc);
unsigned int l;
if ((u64)data % SCALE_F) {
l = min_t(u32, length, SCALE_F - ((u64)data % SCALE_F));
*crc = fallback_crc32(*crc, data, l);
data += l;
length -= l;
}
if (length >= PMULL_MIN_LEN) {
l = round_down(length, SCALE_F);
kernel_neon_begin_partial(10);
*crc = crc32_pmull_le(data, l, *crc);
kernel_neon_end();
data += l;
length -= l;
}
if (length > 0)
*crc = fallback_crc32(*crc, data, length);
return 0;
}
static int crc32c_pmull_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
u32 *crc = shash_desc_ctx(desc);
unsigned int l;
if ((u64)data % SCALE_F) {
l = min_t(u32, length, SCALE_F - ((u64)data % SCALE_F));
*crc = fallback_crc32c(*crc, data, l);
data += l;
length -= l;
}
if (length >= PMULL_MIN_LEN) {
l = round_down(length, SCALE_F);
kernel_neon_begin_partial(10);
*crc = crc32c_pmull_le(data, l, *crc);
kernel_neon_end();
data += l;
length -= l;
}
if (length > 0) {
*crc = fallback_crc32c(*crc, data, length);
}
return 0;
}
static int crc32_pmull_final(struct shash_desc *desc, u8 *out)
{
u32 *crc = shash_desc_ctx(desc);
put_unaligned_le32(*crc, out);
return 0;
}
static int crc32c_pmull_final(struct shash_desc *desc, u8 *out)
{
u32 *crc = shash_desc_ctx(desc);
put_unaligned_le32(~*crc, out);
return 0;
}
static int __init crc32_pmull_mod_init(void)
{
if (elf_hwcap & HWCAP_CRC32) {
fallback_crc32 = crc32_armv8_le;
fallback_crc32c = crc32c_armv8_le;
} else {
fallback_crc32 = crc32_le;
fallback_crc32c = __crc32c_le;
}
return crypto_register_shashes(crc32_pmull_algs,
ARRAY_SIZE(crc32_pmull_algs));
}
static void __exit crc32_pmull_mod_exit(void)
{
crypto_unregister_shashes(crc32_pmull_algs,
ARRAY_SIZE(crc32_pmull_algs));
}
