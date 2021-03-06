static int setkey(struct crypto_tfm *parent, const u8 *key,
unsigned int keylen)
{
struct priv *ctx = crypto_tfm_ctx(parent);
struct crypto_cipher *child = ctx->tweak;
int err;
err = xts_check_key(parent, key, keylen);
if (err)
return err;
crypto_cipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
crypto_cipher_set_flags(child, crypto_tfm_get_flags(parent) &
CRYPTO_TFM_REQ_MASK);
err = crypto_cipher_setkey(child, key + keylen/2, keylen/2);
if (err)
return err;
crypto_tfm_set_flags(parent, crypto_cipher_get_flags(child) &
CRYPTO_TFM_RES_MASK);
child = ctx->child;
crypto_cipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
crypto_cipher_set_flags(child, crypto_tfm_get_flags(parent) &
CRYPTO_TFM_REQ_MASK);
err = crypto_cipher_setkey(child, key, keylen/2);
if (err)
return err;
crypto_tfm_set_flags(parent, crypto_cipher_get_flags(child) &
CRYPTO_TFM_RES_MASK);
return 0;
}
static inline void xts_round(struct sinfo *s, void *dst, const void *src)
{
be128_xor(dst, s->t, src);
s->fn(s->tfm, dst, dst);
be128_xor(dst, dst, s->t);
}
static int crypt(struct blkcipher_desc *d,
struct blkcipher_walk *w, struct priv *ctx,
void (*tw)(struct crypto_tfm *, u8 *, const u8 *),
void (*fn)(struct crypto_tfm *, u8 *, const u8 *))
{
int err;
unsigned int avail;
const int bs = XTS_BLOCK_SIZE;
struct sinfo s = {
.tfm = crypto_cipher_tfm(ctx->child),
.fn = fn
};
u8 *wsrc;
u8 *wdst;
err = blkcipher_walk_virt(d, w);
if (!w->nbytes)
return err;
s.t = (be128 *)w->iv;
avail = w->nbytes;
wsrc = w->src.virt.addr;
wdst = w->dst.virt.addr;
tw(crypto_cipher_tfm(ctx->tweak), w->iv, w->iv);
goto first;
for (;;) {
do {
gf128mul_x_ble(s.t, s.t);
first:
xts_round(&s, wdst, wsrc);
wsrc += bs;
wdst += bs;
} while ((avail -= bs) >= bs);
err = blkcipher_walk_done(d, w, avail);
if (!w->nbytes)
break;
avail = w->nbytes;
wsrc = w->src.virt.addr;
wdst = w->dst.virt.addr;
}
return err;
}
static int encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct priv *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk w;
blkcipher_walk_init(&w, dst, src, nbytes);
return crypt(desc, &w, ctx, crypto_cipher_alg(ctx->tweak)->cia_encrypt,
crypto_cipher_alg(ctx->child)->cia_encrypt);
}
static int decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct priv *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk w;
blkcipher_walk_init(&w, dst, src, nbytes);
return crypt(desc, &w, ctx, crypto_cipher_alg(ctx->tweak)->cia_encrypt,
crypto_cipher_alg(ctx->child)->cia_decrypt);
}
int xts_crypt(struct blkcipher_desc *desc, struct scatterlist *sdst,
struct scatterlist *ssrc, unsigned int nbytes,
struct xts_crypt_req *req)
{
const unsigned int bsize = XTS_BLOCK_SIZE;
const unsigned int max_blks = req->tbuflen / bsize;
struct blkcipher_walk walk;
unsigned int nblocks;
be128 *src, *dst, *t;
be128 *t_buf = req->tbuf;
int err, i;
BUG_ON(max_blks < 1);
blkcipher_walk_init(&walk, sdst, ssrc, nbytes);
err = blkcipher_walk_virt(desc, &walk);
nbytes = walk.nbytes;
if (!nbytes)
return err;
nblocks = min(nbytes / bsize, max_blks);
src = (be128 *)walk.src.virt.addr;
dst = (be128 *)walk.dst.virt.addr;
req->tweak_fn(req->tweak_ctx, (u8 *)&t_buf[0], walk.iv);
i = 0;
goto first;
for (;;) {
do {
for (i = 0; i < nblocks; i++) {
gf128mul_x_ble(&t_buf[i], t);
first:
t = &t_buf[i];
be128_xor(dst + i, t, src + i);
}
req->crypt_fn(req->crypt_ctx, (u8 *)dst,
nblocks * bsize);
for (i = 0; i < nblocks; i++)
be128_xor(dst + i, dst + i, &t_buf[i]);
src += nblocks;
dst += nblocks;
nbytes -= nblocks * bsize;
nblocks = min(nbytes / bsize, max_blks);
} while (nblocks > 0);
*(be128 *)walk.iv = *t;
err = blkcipher_walk_done(desc, &walk, nbytes);
nbytes = walk.nbytes;
if (!nbytes)
break;
nblocks = min(nbytes / bsize, max_blks);
src = (be128 *)walk.src.virt.addr;
dst = (be128 *)walk.dst.virt.addr;
}
return err;
}
static int init_tfm(struct crypto_tfm *tfm)
{
struct crypto_cipher *cipher;
struct crypto_instance *inst = (void *)tfm->__crt_alg;
struct crypto_spawn *spawn = crypto_instance_ctx(inst);
struct priv *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
cipher = crypto_spawn_cipher(spawn);
if (IS_ERR(cipher))
return PTR_ERR(cipher);
if (crypto_cipher_blocksize(cipher) != XTS_BLOCK_SIZE) {
*flags |= CRYPTO_TFM_RES_BAD_BLOCK_LEN;
crypto_free_cipher(cipher);
return -EINVAL;
}
ctx->child = cipher;
cipher = crypto_spawn_cipher(spawn);
if (IS_ERR(cipher)) {
crypto_free_cipher(ctx->child);
return PTR_ERR(cipher);
}
if (crypto_cipher_blocksize(cipher) != XTS_BLOCK_SIZE) {
crypto_free_cipher(cipher);
crypto_free_cipher(ctx->child);
*flags |= CRYPTO_TFM_RES_BAD_BLOCK_LEN;
return -EINVAL;
}
ctx->tweak = cipher;
return 0;
}
static void exit_tfm(struct crypto_tfm *tfm)
{
struct priv *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->child);
crypto_free_cipher(ctx->tweak);
}
static struct crypto_instance *alloc(struct rtattr **tb)
{
struct crypto_instance *inst;
struct crypto_alg *alg;
int err;
err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_BLKCIPHER);
if (err)
return ERR_PTR(err);
alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER,
CRYPTO_ALG_TYPE_MASK);
if (IS_ERR(alg))
return ERR_CAST(alg);
inst = crypto_alloc_instance("xts", alg);
if (IS_ERR(inst))
goto out_put_alg;
inst->alg.cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER;
inst->alg.cra_priority = alg->cra_priority;
inst->alg.cra_blocksize = alg->cra_blocksize;
if (alg->cra_alignmask < 7)
inst->alg.cra_alignmask = 7;
else
inst->alg.cra_alignmask = alg->cra_alignmask;
inst->alg.cra_type = &crypto_blkcipher_type;
inst->alg.cra_blkcipher.ivsize = alg->cra_blocksize;
inst->alg.cra_blkcipher.min_keysize =
2 * alg->cra_cipher.cia_min_keysize;
inst->alg.cra_blkcipher.max_keysize =
2 * alg->cra_cipher.cia_max_keysize;
inst->alg.cra_ctxsize = sizeof(struct priv);
inst->alg.cra_init = init_tfm;
inst->alg.cra_exit = exit_tfm;
inst->alg.cra_blkcipher.setkey = setkey;
inst->alg.cra_blkcipher.encrypt = encrypt;
inst->alg.cra_blkcipher.decrypt = decrypt;
out_put_alg:
crypto_mod_put(alg);
return inst;
}
static void free(struct crypto_instance *inst)
{
crypto_drop_spawn(crypto_instance_ctx(inst));
kfree(inst);
}
static int __init crypto_module_init(void)
{
return crypto_register_template(&crypto_tmpl);
}
static void __exit crypto_module_exit(void)
{
crypto_unregister_template(&crypto_tmpl);
}
