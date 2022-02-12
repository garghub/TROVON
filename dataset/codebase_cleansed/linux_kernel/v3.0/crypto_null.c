static int null_compress(struct crypto_tfm *tfm, const u8 *src,
unsigned int slen, u8 *dst, unsigned int *dlen)
{
if (slen > *dlen)
return -EINVAL;
memcpy(dst, src, slen);
*dlen = slen;
return 0;
}
static int null_init(struct shash_desc *desc)
{
return 0;
}
static int null_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return 0;
}
static int null_final(struct shash_desc *desc, u8 *out)
{
return 0;
}
static int null_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return 0;
}
static int null_hash_setkey(struct crypto_shash *tfm, const u8 *key,
unsigned int keylen)
{ return 0; }
static int null_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{ return 0; }
static void null_crypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
memcpy(dst, src, NULL_BLOCK_SIZE);
}
static int skcipher_null_crypt(struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while (walk.nbytes) {
if (walk.src.virt.addr != walk.dst.virt.addr)
memcpy(walk.dst.virt.addr, walk.src.virt.addr,
walk.nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init crypto_null_mod_init(void)
{
int ret = 0;
ret = crypto_register_alg(&cipher_null);
if (ret < 0)
goto out;
ret = crypto_register_alg(&skcipher_null);
if (ret < 0)
goto out_unregister_cipher;
ret = crypto_register_shash(&digest_null);
if (ret < 0)
goto out_unregister_skcipher;
ret = crypto_register_alg(&compress_null);
if (ret < 0)
goto out_unregister_digest;
out:
return ret;
out_unregister_digest:
crypto_unregister_shash(&digest_null);
out_unregister_skcipher:
crypto_unregister_alg(&skcipher_null);
out_unregister_cipher:
crypto_unregister_alg(&cipher_null);
goto out;
}
static void __exit crypto_null_mod_fini(void)
{
crypto_unregister_alg(&compress_null);
crypto_unregister_shash(&digest_null);
crypto_unregister_alg(&skcipher_null);
crypto_unregister_alg(&cipher_null);
}
