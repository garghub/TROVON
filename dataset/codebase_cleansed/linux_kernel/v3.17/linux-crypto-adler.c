static u32 __adler32(u32 cksum, unsigned char const *p, size_t len)
{
return zlib_adler32(cksum, p, len);
}
static int adler32_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = 1;
return 0;
}
static int adler32_setkey(struct crypto_shash *hash, const u8 *key,
unsigned int keylen)
{
u32 *mctx = crypto_shash_ctx(hash);
if (keylen != sizeof(u32)) {
crypto_shash_set_flags(hash, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
*mctx = *(u32 *)key;
return 0;
}
static int adler32_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *cksump = shash_desc_ctx(desc);
*cksump = *mctx;
return 0;
}
static int adler32_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *cksump = shash_desc_ctx(desc);
*cksump = __adler32(*cksump, data, len);
return 0;
}
static int __adler32_finup(u32 *cksump, const u8 *data, unsigned int len,
u8 *out)
{
*(u32 *)out = __adler32(*cksump, data, len);
return 0;
}
static int adler32_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __adler32_finup(shash_desc_ctx(desc), data, len, out);
}
static int adler32_final(struct shash_desc *desc, u8 *out)
{
u32 *cksump = shash_desc_ctx(desc);
*(u32 *)out = *cksump;
return 0;
}
static int adler32_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __adler32_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
int cfs_crypto_adler32_register(void)
{
return crypto_register_shash(&alg);
}
void cfs_crypto_adler32_unregister(void)
{
crypto_unregister_shash(&alg);
}
