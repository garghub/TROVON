static void eseqiv_complete2(struct skcipher_givcrypt_request *req)
{
struct crypto_ablkcipher *geniv = skcipher_givcrypt_reqtfm(req);
struct eseqiv_request_ctx *reqctx = skcipher_givcrypt_reqctx(req);
memcpy(req->giv, PTR_ALIGN((u8 *)reqctx->tail,
crypto_ablkcipher_alignmask(geniv) + 1),
crypto_ablkcipher_ivsize(geniv));
}
static void eseqiv_complete(struct crypto_async_request *base, int err)
{
struct skcipher_givcrypt_request *req = base->data;
if (err)
goto out;
eseqiv_complete2(req);
out:
skcipher_givcrypt_complete(req, err);
}
static int eseqiv_givencrypt(struct skcipher_givcrypt_request *req)
{
struct crypto_ablkcipher *geniv = skcipher_givcrypt_reqtfm(req);
struct eseqiv_ctx *ctx = crypto_ablkcipher_ctx(geniv);
struct eseqiv_request_ctx *reqctx = skcipher_givcrypt_reqctx(req);
struct ablkcipher_request *subreq;
crypto_completion_t compl;
void *data;
struct scatterlist *osrc, *odst;
struct scatterlist *dst;
struct page *srcp;
struct page *dstp;
u8 *giv;
u8 *vsrc;
u8 *vdst;
__be64 seq;
unsigned int ivsize;
unsigned int len;
int err;
subreq = (void *)(reqctx->tail + ctx->reqoff);
ablkcipher_request_set_tfm(subreq, skcipher_geniv_cipher(geniv));
giv = req->giv;
compl = req->creq.base.complete;
data = req->creq.base.data;
osrc = req->creq.src;
odst = req->creq.dst;
srcp = sg_page(osrc);
dstp = sg_page(odst);
vsrc = PageHighMem(srcp) ? NULL : page_address(srcp) + osrc->offset;
vdst = PageHighMem(dstp) ? NULL : page_address(dstp) + odst->offset;
ivsize = crypto_ablkcipher_ivsize(geniv);
if (vsrc != giv + ivsize && vdst != giv + ivsize) {
giv = PTR_ALIGN((u8 *)reqctx->tail,
crypto_ablkcipher_alignmask(geniv) + 1);
compl = eseqiv_complete;
data = req;
}
ablkcipher_request_set_callback(subreq, req->creq.base.flags, compl,
data);
sg_init_table(reqctx->src, 2);
sg_set_buf(reqctx->src, giv, ivsize);
scatterwalk_crypto_chain(reqctx->src, osrc, vsrc == giv + ivsize, 2);
dst = reqctx->src;
if (osrc != odst) {
sg_init_table(reqctx->dst, 2);
sg_set_buf(reqctx->dst, giv, ivsize);
scatterwalk_crypto_chain(reqctx->dst, odst, vdst == giv + ivsize, 2);
dst = reqctx->dst;
}
ablkcipher_request_set_crypt(subreq, reqctx->src, dst,
req->creq.nbytes + ivsize,
req->creq.info);
memcpy(req->creq.info, ctx->salt, ivsize);
len = ivsize;
if (ivsize > sizeof(u64)) {
memset(req->giv, 0, ivsize - sizeof(u64));
len = sizeof(u64);
}
seq = cpu_to_be64(req->seq);
memcpy(req->giv + ivsize - len, &seq, len);
err = crypto_ablkcipher_encrypt(subreq);
if (err)
goto out;
if (giv != req->giv)
eseqiv_complete2(req);
out:
return err;
}
static int eseqiv_init(struct crypto_tfm *tfm)
{
struct crypto_ablkcipher *geniv = __crypto_ablkcipher_cast(tfm);
struct eseqiv_ctx *ctx = crypto_ablkcipher_ctx(geniv);
unsigned long alignmask;
unsigned int reqsize;
int err;
spin_lock_init(&ctx->lock);
alignmask = crypto_tfm_ctx_alignment() - 1;
reqsize = sizeof(struct eseqiv_request_ctx);
if (alignmask & reqsize) {
alignmask &= reqsize;
alignmask--;
}
alignmask = ~alignmask;
alignmask &= crypto_ablkcipher_alignmask(geniv);
reqsize += alignmask;
reqsize += crypto_ablkcipher_ivsize(geniv);
reqsize = ALIGN(reqsize, crypto_tfm_ctx_alignment());
ctx->reqoff = reqsize - sizeof(struct eseqiv_request_ctx);
tfm->crt_ablkcipher.reqsize = reqsize +
sizeof(struct ablkcipher_request);
err = 0;
if (!crypto_get_default_rng()) {
crypto_ablkcipher_crt(geniv)->givencrypt = eseqiv_givencrypt;
err = crypto_rng_get_bytes(crypto_default_rng, ctx->salt,
crypto_ablkcipher_ivsize(geniv));
crypto_put_default_rng();
}
return err ?: skcipher_geniv_init(tfm);
}
static struct crypto_instance *eseqiv_alloc(struct rtattr **tb)
{
struct crypto_instance *inst;
int err;
inst = skcipher_geniv_alloc(&eseqiv_tmpl, tb, 0, 0);
if (IS_ERR(inst))
goto out;
err = -EINVAL;
if (inst->alg.cra_ablkcipher.ivsize != inst->alg.cra_blocksize)
goto free_inst;
inst->alg.cra_init = eseqiv_init;
inst->alg.cra_exit = skcipher_geniv_exit;
inst->alg.cra_ctxsize = sizeof(struct eseqiv_ctx);
inst->alg.cra_ctxsize += inst->alg.cra_ablkcipher.ivsize;
out:
return inst;
free_inst:
skcipher_geniv_free(inst);
inst = ERR_PTR(err);
goto out;
}
static int __init eseqiv_module_init(void)
{
return crypto_register_template(&eseqiv_tmpl);
}
static void __exit eseqiv_module_exit(void)
{
crypto_unregister_template(&eseqiv_tmpl);
}
