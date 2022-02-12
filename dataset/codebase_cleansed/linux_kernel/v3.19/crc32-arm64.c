static u32 crc32_arm64_le_hw(u32 crc, const u8 *p, unsigned int len)
{
s64 length = len;
while ((length -= sizeof(u64)) >= 0) {
CRC32X(crc, get_unaligned_le64(p));
p += sizeof(u64);
}
if (length & sizeof(u32)) {
CRC32W(crc, get_unaligned_le32(p));
p += sizeof(u32);
}
if (length & sizeof(u16)) {
CRC32H(crc, get_unaligned_le16(p));
p += sizeof(u16);
}
if (length & sizeof(u8))
CRC32B(crc, *p);
return crc;
}
static u32 crc32c_arm64_le_hw(u32 crc, const u8 *p, unsigned int len)
{
s64 length = len;
while ((length -= sizeof(u64)) >= 0) {
CRC32CX(crc, get_unaligned_le64(p));
p += sizeof(u64);
}
if (length & sizeof(u32)) {
CRC32CW(crc, get_unaligned_le32(p));
p += sizeof(u32);
}
if (length & sizeof(u16)) {
CRC32CH(crc, get_unaligned_le16(p));
p += sizeof(u16);
}
if (length & sizeof(u8))
CRC32CB(crc, *p);
return crc;
}
static int chksum_init(struct shash_desc *desc)
{
struct chksum_ctx *mctx = crypto_shash_ctx(desc->tfm);
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = mctx->key;
return 0;
}
static int chksum_setkey(struct crypto_shash *tfm, const u8 *key,
unsigned int keylen)
{
struct chksum_ctx *mctx = crypto_shash_ctx(tfm);
if (keylen != sizeof(mctx->key)) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
mctx->key = get_unaligned_le32(key);
return 0;
}
static int chksum_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = crc32_arm64_le_hw(ctx->crc, data, length);
return 0;
}
static int chksumc_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
ctx->crc = crc32c_arm64_le_hw(ctx->crc, data, length);
return 0;
}
static int chksum_final(struct shash_desc *desc, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
put_unaligned_le32(~ctx->crc, out);
return 0;
}
static int __chksum_finup(u32 crc, const u8 *data, unsigned int len, u8 *out)
{
put_unaligned_le32(~crc32_arm64_le_hw(crc, data, len), out);
return 0;
}
static int __chksumc_finup(u32 crc, const u8 *data, unsigned int len, u8 *out)
{
put_unaligned_le32(~crc32c_arm64_le_hw(crc, data, len), out);
return 0;
}
static int chksum_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
return __chksum_finup(ctx->crc, data, len, out);
}
static int chksumc_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
struct chksum_desc_ctx *ctx = shash_desc_ctx(desc);
return __chksumc_finup(ctx->crc, data, len, out);
}
static int chksum_digest(struct shash_desc *desc, const u8 *data,
unsigned int length, u8 *out)
{
struct chksum_ctx *mctx = crypto_shash_ctx(desc->tfm);
return __chksum_finup(mctx->key, data, length, out);
}
static int chksumc_digest(struct shash_desc *desc, const u8 *data,
unsigned int length, u8 *out)
{
struct chksum_ctx *mctx = crypto_shash_ctx(desc->tfm);
return __chksumc_finup(mctx->key, data, length, out);
}
static int crc32_cra_init(struct crypto_tfm *tfm)
{
struct chksum_ctx *mctx = crypto_tfm_ctx(tfm);
mctx->key = ~0;
return 0;
}
static int __init crc32_mod_init(void)
{
int err;
err = crypto_register_shash(&crc32_alg);
if (err)
return err;
err = crypto_register_shash(&crc32c_alg);
if (err) {
crypto_unregister_shash(&crc32_alg);
return err;
}
return 0;
}
static void __exit crc32_mod_exit(void)
{
crypto_unregister_shash(&crc32_alg);
crypto_unregister_shash(&crc32c_alg);
}
