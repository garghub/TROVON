static u32 __crc32_le(u32 crc, unsigned char const *p, size_t len)
{
return crc32_le(crc, p, len);
}
static int crc32_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = 0;
return 0;
}
static int crc32_setkey(struct crypto_shash *hash, const u8 *key,
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
static int crc32_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *crcp = shash_desc_ctx(desc);
*crcp = *mctx;
return 0;
}
static int crc32_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *crcp = shash_desc_ctx(desc);
*crcp = __crc32_le(*crcp, data, len);
return 0;
}
static int __crc32_finup(u32 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
*(__le32 *)out = cpu_to_le32(__crc32_le(*crcp, data, len));
return 0;
}
static int crc32_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32_finup(shash_desc_ctx(desc), data, len, out);
}
static int crc32_final(struct shash_desc *desc, u8 *out)
{
u32 *crcp = shash_desc_ctx(desc);
*(__le32 *)out = cpu_to_le32p(crcp);
return 0;
}
static int crc32_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
static int __init crc32_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit crc32_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
