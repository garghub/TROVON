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
struct crypto_blkcipher *crypto_get_default_null_skcipher(void)
{
struct crypto_blkcipher *tfm;
mutex_lock(&crypto_default_null_skcipher_lock);
tfm = crypto_default_null_skcipher;
if (!tfm) {
tfm = crypto_alloc_blkcipher("ecb(cipher_null)", 0, 0);
if (IS_ERR(tfm))
goto unlock;
crypto_default_null_skcipher = tfm;
}
crypto_default_null_skcipher_refcnt++;
unlock:
mutex_unlock(&crypto_default_null_skcipher_lock);
return tfm;
}
void crypto_put_default_null_skcipher(void)
{
mutex_lock(&crypto_default_null_skcipher_lock);
if (!--crypto_default_null_skcipher_refcnt) {
crypto_free_blkcipher(crypto_default_null_skcipher);
crypto_default_null_skcipher = NULL;
}
mutex_unlock(&crypto_default_null_skcipher_lock);
}
static int __init crypto_null_mod_init(void)
{
int ret = 0;
ret = crypto_register_algs(null_algs, ARRAY_SIZE(null_algs));
if (ret < 0)
goto out;
ret = crypto_register_shash(&digest_null);
if (ret < 0)
goto out_unregister_algs;
return 0;
out_unregister_algs:
crypto_unregister_algs(null_algs, ARRAY_SIZE(null_algs));
out:
return ret;
}
static void __exit crypto_null_mod_fini(void)
{
crypto_unregister_shash(&digest_null);
crypto_unregister_algs(null_algs, ARRAY_SIZE(null_algs));
}
