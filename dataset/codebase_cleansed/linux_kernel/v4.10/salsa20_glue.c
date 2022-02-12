static int setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keysize)
{
struct salsa20_ctx *ctx = crypto_tfm_ctx(tfm);
salsa20_keysetup(ctx, key, keysize*8, SALSA20_IV_SIZE*8);
return 0;
}
static int encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
struct crypto_blkcipher *tfm = desc->tfm;
struct salsa20_ctx *ctx = crypto_blkcipher_ctx(tfm);
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 64);
salsa20_ivsetup(ctx, walk.iv);
if (likely(walk.nbytes == nbytes))
{
salsa20_encrypt_bytes(ctx, walk.src.virt.addr,
walk.dst.virt.addr, nbytes);
return blkcipher_walk_done(desc, &walk, 0);
}
while (walk.nbytes >= 64) {
salsa20_encrypt_bytes(ctx, walk.src.virt.addr,
walk.dst.virt.addr,
walk.nbytes - (walk.nbytes % 64));
err = blkcipher_walk_done(desc, &walk, walk.nbytes % 64);
}
if (walk.nbytes) {
salsa20_encrypt_bytes(ctx, walk.src.virt.addr,
walk.dst.virt.addr, walk.nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init init(void)
{
return crypto_register_alg(&alg);
}
static void __exit fini(void)
{
crypto_unregister_alg(&alg);
}
