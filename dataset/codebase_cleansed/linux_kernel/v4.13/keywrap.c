static inline void crypto_kw_cpu_to_be64(u64 val, u8 *buf)
{
__be64 *a = (__be64 *)buf;
*a = cpu_to_be64(val);
}
static void crypto_kw_scatterlist_ff(struct scatter_walk *walk,
struct scatterlist *sg,
unsigned int end)
{
unsigned int skip = 0;
BUG_ON(end < SEMIBSIZE);
skip = end - SEMIBSIZE;
while (sg) {
if (sg->length > skip) {
scatterwalk_start(walk, sg);
scatterwalk_advance(walk, skip);
break;
} else
skip -= sg->length;
sg = sg_next(sg);
}
}
static int crypto_kw_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_blkcipher *tfm = desc->tfm;
struct crypto_kw_ctx *ctx = crypto_blkcipher_ctx(tfm);
struct crypto_cipher *child = ctx->child;
unsigned long alignmask = max_t(unsigned long, SEMIBSIZE,
crypto_cipher_alignmask(child));
unsigned int i;
u8 blockbuf[sizeof(struct crypto_kw_block) + alignmask];
struct crypto_kw_block *block = (struct crypto_kw_block *)
PTR_ALIGN(blockbuf + 0, alignmask + 1);
u64 t = 6 * ((nbytes) >> 3);
struct scatterlist *lsrc, *ldst;
int ret = 0;
if (nbytes < (2 * SEMIBSIZE) || nbytes % SEMIBSIZE)
return -EINVAL;
memcpy(block->A, desc->info, SEMIBSIZE);
lsrc = src;
ldst = dst;
for (i = 0; i < 6; i++) {
u8 tbe_buffer[SEMIBSIZE + alignmask];
u8 *tbe = PTR_ALIGN(tbe_buffer + 0, alignmask + 1);
unsigned int tmp_nbytes = nbytes;
struct scatter_walk src_walk, dst_walk;
while (tmp_nbytes) {
crypto_kw_scatterlist_ff(&src_walk, lsrc, tmp_nbytes);
scatterwalk_copychunks(block->R, &src_walk, SEMIBSIZE,
false);
crypto_kw_cpu_to_be64(t, tbe);
crypto_xor(block->A, tbe, SEMIBSIZE);
t--;
crypto_cipher_decrypt_one(child, (u8*)block,
(u8*)block);
crypto_kw_scatterlist_ff(&dst_walk, ldst, tmp_nbytes);
scatterwalk_copychunks(block->R, &dst_walk, SEMIBSIZE,
true);
tmp_nbytes -= SEMIBSIZE;
}
lsrc = dst;
ldst = dst;
}
if (crypto_memneq("\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6", block->A,
SEMIBSIZE))
ret = -EBADMSG;
memzero_explicit(block, sizeof(struct crypto_kw_block));
return ret;
}
static int crypto_kw_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct crypto_blkcipher *tfm = desc->tfm;
struct crypto_kw_ctx *ctx = crypto_blkcipher_ctx(tfm);
struct crypto_cipher *child = ctx->child;
unsigned long alignmask = max_t(unsigned long, SEMIBSIZE,
crypto_cipher_alignmask(child));
unsigned int i;
u8 blockbuf[sizeof(struct crypto_kw_block) + alignmask];
struct crypto_kw_block *block = (struct crypto_kw_block *)
PTR_ALIGN(blockbuf + 0, alignmask + 1);
u64 t = 1;
struct scatterlist *lsrc, *ldst;
if (nbytes < (2 * SEMIBSIZE) || nbytes % SEMIBSIZE)
return -EINVAL;
memcpy(block->A, "\xA6\xA6\xA6\xA6\xA6\xA6\xA6\xA6", SEMIBSIZE);
lsrc = src;
ldst = dst;
for (i = 0; i < 6; i++) {
u8 tbe_buffer[SEMIBSIZE + alignmask];
u8 *tbe = PTR_ALIGN(tbe_buffer + 0, alignmask + 1);
unsigned int tmp_nbytes = nbytes;
struct scatter_walk src_walk, dst_walk;
scatterwalk_start(&src_walk, lsrc);
scatterwalk_start(&dst_walk, ldst);
while (tmp_nbytes) {
scatterwalk_copychunks(block->R, &src_walk, SEMIBSIZE,
false);
crypto_cipher_encrypt_one(child, (u8 *)block,
(u8 *)block);
crypto_kw_cpu_to_be64(t, tbe);
crypto_xor(block->A, tbe, SEMIBSIZE);
t++;
scatterwalk_copychunks(block->R, &dst_walk, SEMIBSIZE,
true);
tmp_nbytes -= SEMIBSIZE;
}
lsrc = dst;
ldst = dst;
}
memcpy(desc->info, block->A, SEMIBSIZE);
memzero_explicit(block, sizeof(struct crypto_kw_block));
return 0;
}
static int crypto_kw_setkey(struct crypto_tfm *parent, const u8 *key,
unsigned int keylen)
{
struct crypto_kw_ctx *ctx = crypto_tfm_ctx(parent);
struct crypto_cipher *child = ctx->child;
int err;
crypto_cipher_clear_flags(child, CRYPTO_TFM_REQ_MASK);
crypto_cipher_set_flags(child, crypto_tfm_get_flags(parent) &
CRYPTO_TFM_REQ_MASK);
err = crypto_cipher_setkey(child, key, keylen);
crypto_tfm_set_flags(parent, crypto_cipher_get_flags(child) &
CRYPTO_TFM_RES_MASK);
return err;
}
static int crypto_kw_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_instance *inst = crypto_tfm_alg_instance(tfm);
struct crypto_spawn *spawn = crypto_instance_ctx(inst);
struct crypto_kw_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypto_cipher *cipher;
cipher = crypto_spawn_cipher(spawn);
if (IS_ERR(cipher))
return PTR_ERR(cipher);
ctx->child = cipher;
return 0;
}
static void crypto_kw_exit_tfm(struct crypto_tfm *tfm)
{
struct crypto_kw_ctx *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->child);
}
static struct crypto_instance *crypto_kw_alloc(struct rtattr **tb)
{
struct crypto_instance *inst = NULL;
struct crypto_alg *alg = NULL;
int err;
err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_BLKCIPHER);
if (err)
return ERR_PTR(err);
alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER,
CRYPTO_ALG_TYPE_MASK);
if (IS_ERR(alg))
return ERR_CAST(alg);
inst = ERR_PTR(-EINVAL);
if (alg->cra_blocksize != sizeof(struct crypto_kw_block))
goto err;
inst = crypto_alloc_instance("kw", alg);
if (IS_ERR(inst))
goto err;
inst->alg.cra_flags = CRYPTO_ALG_TYPE_BLKCIPHER;
inst->alg.cra_priority = alg->cra_priority;
inst->alg.cra_blocksize = SEMIBSIZE;
inst->alg.cra_alignmask = 0;
inst->alg.cra_type = &crypto_blkcipher_type;
inst->alg.cra_blkcipher.ivsize = SEMIBSIZE;
inst->alg.cra_blkcipher.min_keysize = alg->cra_cipher.cia_min_keysize;
inst->alg.cra_blkcipher.max_keysize = alg->cra_cipher.cia_max_keysize;
inst->alg.cra_ctxsize = sizeof(struct crypto_kw_ctx);
inst->alg.cra_init = crypto_kw_init_tfm;
inst->alg.cra_exit = crypto_kw_exit_tfm;
inst->alg.cra_blkcipher.setkey = crypto_kw_setkey;
inst->alg.cra_blkcipher.encrypt = crypto_kw_encrypt;
inst->alg.cra_blkcipher.decrypt = crypto_kw_decrypt;
err:
crypto_mod_put(alg);
return inst;
}
static void crypto_kw_free(struct crypto_instance *inst)
{
crypto_drop_spawn(crypto_instance_ctx(inst));
kfree(inst);
}
static int __init crypto_kw_init(void)
{
return crypto_register_template(&crypto_kw_tmpl);
}
static void __exit crypto_kw_exit(void)
{
crypto_unregister_template(&crypto_kw_tmpl);
}
