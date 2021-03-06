static int crypto_xcbc_digest_setkey(struct crypto_shash *parent,
const u8 *inkey, unsigned int keylen)
{
unsigned long alignmask = crypto_shash_alignmask(parent);
struct xcbc_tfm_ctx *ctx = crypto_shash_ctx(parent);
int bs = crypto_shash_blocksize(parent);
u8 *consts = PTR_ALIGN(&ctx->ctx[0], alignmask + 1);
int err = 0;
u8 key1[bs];
if ((err = crypto_cipher_setkey(ctx->child, inkey, keylen)))
return err;
crypto_cipher_encrypt_one(ctx->child, consts, (u8 *)ks + bs);
crypto_cipher_encrypt_one(ctx->child, consts + bs, (u8 *)ks + bs * 2);
crypto_cipher_encrypt_one(ctx->child, key1, (u8 *)ks);
return crypto_cipher_setkey(ctx->child, key1, bs);
}
static int crypto_xcbc_digest_init(struct shash_desc *pdesc)
{
unsigned long alignmask = crypto_shash_alignmask(pdesc->tfm);
struct xcbc_desc_ctx *ctx = shash_desc_ctx(pdesc);
int bs = crypto_shash_blocksize(pdesc->tfm);
u8 *prev = PTR_ALIGN(&ctx->ctx[0], alignmask + 1) + bs;
ctx->len = 0;
memset(prev, 0, bs);
return 0;
}
static int crypto_xcbc_digest_update(struct shash_desc *pdesc, const u8 *p,
unsigned int len)
{
struct crypto_shash *parent = pdesc->tfm;
unsigned long alignmask = crypto_shash_alignmask(parent);
struct xcbc_tfm_ctx *tctx = crypto_shash_ctx(parent);
struct xcbc_desc_ctx *ctx = shash_desc_ctx(pdesc);
struct crypto_cipher *tfm = tctx->child;
int bs = crypto_shash_blocksize(parent);
u8 *odds = PTR_ALIGN(&ctx->ctx[0], alignmask + 1);
u8 *prev = odds + bs;
if ((ctx->len + len) <= bs) {
memcpy(odds + ctx->len, p, len);
ctx->len += len;
return 0;
}
memcpy(odds + ctx->len, p, bs - ctx->len);
len -= bs - ctx->len;
p += bs - ctx->len;
crypto_xor(prev, odds, bs);
crypto_cipher_encrypt_one(tfm, prev, prev);
ctx->len = 0;
while (len > bs) {
crypto_xor(prev, p, bs);
crypto_cipher_encrypt_one(tfm, prev, prev);
p += bs;
len -= bs;
}
if (len) {
memcpy(odds, p, len);
ctx->len = len;
}
return 0;
}
static int crypto_xcbc_digest_final(struct shash_desc *pdesc, u8 *out)
{
struct crypto_shash *parent = pdesc->tfm;
unsigned long alignmask = crypto_shash_alignmask(parent);
struct xcbc_tfm_ctx *tctx = crypto_shash_ctx(parent);
struct xcbc_desc_ctx *ctx = shash_desc_ctx(pdesc);
struct crypto_cipher *tfm = tctx->child;
int bs = crypto_shash_blocksize(parent);
u8 *consts = PTR_ALIGN(&tctx->ctx[0], alignmask + 1);
u8 *odds = PTR_ALIGN(&ctx->ctx[0], alignmask + 1);
u8 *prev = odds + bs;
unsigned int offset = 0;
if (ctx->len != bs) {
unsigned int rlen;
u8 *p = odds + ctx->len;
*p = 0x80;
p++;
rlen = bs - ctx->len -1;
if (rlen)
memset(p, 0, rlen);
offset += bs;
}
crypto_xor(prev, odds, bs);
crypto_xor(prev, consts + offset, bs);
crypto_cipher_encrypt_one(tfm, out, prev);
return 0;
}
static int xcbc_init_tfm(struct crypto_tfm *tfm)
{
struct crypto_cipher *cipher;
struct crypto_instance *inst = (void *)tfm->__crt_alg;
struct crypto_spawn *spawn = crypto_instance_ctx(inst);
struct xcbc_tfm_ctx *ctx = crypto_tfm_ctx(tfm);
cipher = crypto_spawn_cipher(spawn);
if (IS_ERR(cipher))
return PTR_ERR(cipher);
ctx->child = cipher;
return 0;
}
static void xcbc_exit_tfm(struct crypto_tfm *tfm)
{
struct xcbc_tfm_ctx *ctx = crypto_tfm_ctx(tfm);
crypto_free_cipher(ctx->child);
}
static int xcbc_create(struct crypto_template *tmpl, struct rtattr **tb)
{
struct shash_instance *inst;
struct crypto_alg *alg;
unsigned long alignmask;
int err;
err = crypto_check_attr_type(tb, CRYPTO_ALG_TYPE_SHASH);
if (err)
return err;
alg = crypto_get_attr_alg(tb, CRYPTO_ALG_TYPE_CIPHER,
CRYPTO_ALG_TYPE_MASK);
if (IS_ERR(alg))
return PTR_ERR(alg);
switch(alg->cra_blocksize) {
case 16:
break;
default:
goto out_put_alg;
}
inst = shash_alloc_instance("xcbc", alg);
err = PTR_ERR(inst);
if (IS_ERR(inst))
goto out_put_alg;
err = crypto_init_spawn(shash_instance_ctx(inst), alg,
shash_crypto_instance(inst),
CRYPTO_ALG_TYPE_MASK);
if (err)
goto out_free_inst;
alignmask = alg->cra_alignmask | 3;
inst->alg.base.cra_alignmask = alignmask;
inst->alg.base.cra_priority = alg->cra_priority;
inst->alg.base.cra_blocksize = alg->cra_blocksize;
inst->alg.digestsize = alg->cra_blocksize;
inst->alg.descsize = ALIGN(sizeof(struct xcbc_desc_ctx),
crypto_tfm_ctx_alignment()) +
(alignmask &
~(crypto_tfm_ctx_alignment() - 1)) +
alg->cra_blocksize * 2;
inst->alg.base.cra_ctxsize = ALIGN(sizeof(struct xcbc_tfm_ctx),
alignmask + 1) +
alg->cra_blocksize * 2;
inst->alg.base.cra_init = xcbc_init_tfm;
inst->alg.base.cra_exit = xcbc_exit_tfm;
inst->alg.init = crypto_xcbc_digest_init;
inst->alg.update = crypto_xcbc_digest_update;
inst->alg.final = crypto_xcbc_digest_final;
inst->alg.setkey = crypto_xcbc_digest_setkey;
err = shash_register_instance(tmpl, inst);
if (err) {
out_free_inst:
shash_free_instance(shash_crypto_instance(inst));
}
out_put_alg:
crypto_mod_put(alg);
return err;
}
static int __init crypto_xcbc_module_init(void)
{
return crypto_register_template(&crypto_xcbc_tmpl);
}
static void __exit crypto_xcbc_module_exit(void)
{
crypto_unregister_template(&crypto_xcbc_tmpl);
}
