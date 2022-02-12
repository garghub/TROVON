static int nx842_init(struct crypto_tfm *tfm)
{
struct nx842_ctx *ctx = crypto_tfm_ctx(tfm);
int wmemsize;
wmemsize = max_t(int, nx842_get_workmem_size(), LZO1X_MEM_COMPRESS);
ctx->nx842_wmem = kmalloc(wmemsize, GFP_NOFS);
if (!ctx->nx842_wmem)
return -ENOMEM;
return 0;
}
static void nx842_exit(struct crypto_tfm *tfm)
{
struct nx842_ctx *ctx = crypto_tfm_ctx(tfm);
kfree(ctx->nx842_wmem);
}
static void nx842_reset_uselzo(unsigned long data)
{
nx842_uselzo = 0;
}
static int nx842_crypto_compress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
struct nx842_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_crypto_header *hdr;
unsigned int tmp_len = *dlen;
size_t lzodlen;
int err;
*dlen = 0;
hdr = (struct nx842_crypto_header *)dst;
hdr->sentinel = NX842_SENTINEL;
dst += sizeof(struct nx842_crypto_header);
tmp_len -= sizeof(struct nx842_crypto_header);
lzodlen = tmp_len;
if (likely(!nx842_uselzo)) {
err = nx842_compress(src, slen, dst, &tmp_len, ctx->nx842_wmem);
if (likely(!err)) {
hdr->type = NX842_CRYPTO_TYPE_842;
*dlen = tmp_len + sizeof(struct nx842_crypto_header);
return 0;
}
nx842_uselzo = 1;
mod_timer(&failover_timer, jiffies + msecs_to_jiffies(1000));
}
err = lzo1x_1_compress(src, slen, dst, &lzodlen, ctx->nx842_wmem);
if (err != LZO_E_OK)
return -EINVAL;
hdr->type = NX842_CRYPTO_TYPE_LZO;
*dlen = lzodlen + sizeof(struct nx842_crypto_header);
return 0;
}
static int nx842_crypto_decompress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
struct nx842_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_crypto_header *hdr;
unsigned int tmp_len = *dlen;
size_t lzodlen;
int err;
*dlen = 0;
hdr = (struct nx842_crypto_header *)src;
if (unlikely(hdr->sentinel != NX842_SENTINEL))
return -EINVAL;
src += sizeof(struct nx842_crypto_header);
slen -= sizeof(struct nx842_crypto_header);
if (likely(hdr->type == NX842_CRYPTO_TYPE_842)) {
err = nx842_decompress(src, slen, dst, &tmp_len,
ctx->nx842_wmem);
if (err)
return -EINVAL;
*dlen = tmp_len;
} else if (hdr->type == NX842_CRYPTO_TYPE_LZO) {
lzodlen = tmp_len;
err = lzo1x_decompress_safe(src, slen, dst, &lzodlen);
if (err != LZO_E_OK)
return -EINVAL;
*dlen = lzodlen;
} else
return -EINVAL;
return 0;
}
static int __init nx842_mod_init(void)
{
del_timer(&failover_timer);
return crypto_register_alg(&alg);
}
static void __exit nx842_mod_exit(void)
{
crypto_unregister_alg(&alg);
}
