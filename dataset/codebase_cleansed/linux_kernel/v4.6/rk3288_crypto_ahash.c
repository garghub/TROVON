static int zero_message_process(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
int rk_digest_size = crypto_ahash_digestsize(tfm);
switch (rk_digest_size) {
case SHA1_DIGEST_SIZE:
memcpy(req->result, sha1_zero_message_hash, rk_digest_size);
break;
case SHA256_DIGEST_SIZE:
memcpy(req->result, sha256_zero_message_hash, rk_digest_size);
break;
case MD5_DIGEST_SIZE:
memcpy(req->result, md5_zero_message_hash, rk_digest_size);
break;
default:
return -EINVAL;
}
return 0;
}
static void rk_ahash_crypto_complete(struct rk_crypto_info *dev, int err)
{
if (dev->ahash_req->base.complete)
dev->ahash_req->base.complete(&dev->ahash_req->base, err);
}
static void rk_ahash_reg_init(struct rk_crypto_info *dev)
{
int reg_status = 0;
reg_status = CRYPTO_READ(dev, RK_CRYPTO_CTRL) |
RK_CRYPTO_HASH_FLUSH | _SBF(0xffff, 16);
CRYPTO_WRITE(dev, RK_CRYPTO_CTRL, reg_status);
reg_status = CRYPTO_READ(dev, RK_CRYPTO_CTRL);
reg_status &= (~RK_CRYPTO_HASH_FLUSH);
reg_status |= _SBF(0xffff, 16);
CRYPTO_WRITE(dev, RK_CRYPTO_CTRL, reg_status);
memset_io(dev->reg + RK_CRYPTO_HASH_DOUT_0, 0, 32);
CRYPTO_WRITE(dev, RK_CRYPTO_INTENA, RK_CRYPTO_HRDMA_ERR_ENA |
RK_CRYPTO_HRDMA_DONE_ENA);
CRYPTO_WRITE(dev, RK_CRYPTO_INTSTS, RK_CRYPTO_HRDMA_ERR_INT |
RK_CRYPTO_HRDMA_DONE_INT);
CRYPTO_WRITE(dev, RK_CRYPTO_HASH_CTRL, dev->mode |
RK_CRYPTO_HASH_SWAP_DO);
CRYPTO_WRITE(dev, RK_CRYPTO_CONF, RK_CRYPTO_BYTESWAP_HRFIFO |
RK_CRYPTO_BYTESWAP_BRFIFO |
RK_CRYPTO_BYTESWAP_BTFIFO);
CRYPTO_WRITE(dev, RK_CRYPTO_HASH_MSG_LEN, dev->total);
}
static int rk_ahash_init(struct ahash_request *req)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_init(&rctx->fallback_req);
}
static int rk_ahash_update(struct ahash_request *req)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.nbytes = req->nbytes;
rctx->fallback_req.src = req->src;
return crypto_ahash_update(&rctx->fallback_req);
}
static int rk_ahash_final(struct ahash_request *req)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.result = req->result;
return crypto_ahash_final(&rctx->fallback_req);
}
static int rk_ahash_finup(struct ahash_request *req)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.nbytes = req->nbytes;
rctx->fallback_req.src = req->src;
rctx->fallback_req.result = req->result;
return crypto_ahash_finup(&rctx->fallback_req);
}
static int rk_ahash_import(struct ahash_request *req, const void *in)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_import(&rctx->fallback_req, in);
}
static int rk_ahash_export(struct ahash_request *req, void *out)
{
struct rk_ahash_rctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback_tfm);
rctx->fallback_req.base.flags = req->base.flags &
CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_export(&rctx->fallback_req, out);
}
static int rk_ahash_digest(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct rk_ahash_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
struct rk_crypto_info *dev = NULL;
unsigned long flags;
int ret;
if (!req->nbytes)
return zero_message_process(req);
dev = tctx->dev;
dev->total = req->nbytes;
dev->left_bytes = req->nbytes;
dev->aligned = 0;
dev->mode = 0;
dev->align_size = 4;
dev->sg_dst = NULL;
dev->sg_src = req->src;
dev->first = req->src;
dev->nents = sg_nents(req->src);
switch (crypto_ahash_digestsize(tfm)) {
case SHA1_DIGEST_SIZE:
dev->mode = RK_CRYPTO_HASH_SHA1;
break;
case SHA256_DIGEST_SIZE:
dev->mode = RK_CRYPTO_HASH_SHA256;
break;
case MD5_DIGEST_SIZE:
dev->mode = RK_CRYPTO_HASH_MD5;
break;
default:
return -EINVAL;
}
rk_ahash_reg_init(dev);
spin_lock_irqsave(&dev->lock, flags);
ret = crypto_enqueue_request(&dev->queue, &req->base);
spin_unlock_irqrestore(&dev->lock, flags);
tasklet_schedule(&dev->crypto_tasklet);
while (!CRYPTO_READ(dev, RK_CRYPTO_HASH_STS))
usleep_range(10, 50);
memcpy_fromio(req->result, dev->reg + RK_CRYPTO_HASH_DOUT_0,
crypto_ahash_digestsize(tfm));
return 0;
}
static void crypto_ahash_dma_start(struct rk_crypto_info *dev)
{
CRYPTO_WRITE(dev, RK_CRYPTO_HRDMAS, dev->addr_in);
CRYPTO_WRITE(dev, RK_CRYPTO_HRDMAL, (dev->count + 3) / 4);
CRYPTO_WRITE(dev, RK_CRYPTO_CTRL, RK_CRYPTO_HASH_START |
(RK_CRYPTO_HASH_START << 16));
}
static int rk_ahash_set_data_start(struct rk_crypto_info *dev)
{
int err;
err = dev->load_data(dev, dev->sg_src, NULL);
if (!err)
crypto_ahash_dma_start(dev);
return err;
}
static int rk_ahash_start(struct rk_crypto_info *dev)
{
return rk_ahash_set_data_start(dev);
}
static int rk_ahash_crypto_rx(struct rk_crypto_info *dev)
{
int err = 0;
dev->unload_data(dev);
if (dev->left_bytes) {
if (dev->aligned) {
if (sg_is_last(dev->sg_src)) {
dev_warn(dev->dev, "[%s:%d], Lack of data\n",
__func__, __LINE__);
err = -ENOMEM;
goto out_rx;
}
dev->sg_src = sg_next(dev->sg_src);
}
err = rk_ahash_set_data_start(dev);
} else {
dev->complete(dev, 0);
}
out_rx:
return err;
}
static int rk_cra_hash_init(struct crypto_tfm *tfm)
{
struct rk_ahash_ctx *tctx = crypto_tfm_ctx(tfm);
struct rk_crypto_tmp *algt;
struct ahash_alg *alg = __crypto_ahash_alg(tfm->__crt_alg);
const char *alg_name = crypto_tfm_alg_name(tfm);
algt = container_of(alg, struct rk_crypto_tmp, alg.hash);
tctx->dev = algt->dev;
tctx->dev->addr_vir = (void *)__get_free_page(GFP_KERNEL);
if (!tctx->dev->addr_vir) {
dev_err(tctx->dev->dev, "failed to kmalloc for addr_vir\n");
return -ENOMEM;
}
tctx->dev->start = rk_ahash_start;
tctx->dev->update = rk_ahash_crypto_rx;
tctx->dev->complete = rk_ahash_crypto_complete;
tctx->fallback_tfm = crypto_alloc_ahash(alg_name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(tctx->fallback_tfm)) {
dev_err(tctx->dev->dev, "Could not load fallback driver.\n");
return PTR_ERR(tctx->fallback_tfm);
}
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct rk_ahash_rctx) +
crypto_ahash_reqsize(tctx->fallback_tfm));
return tctx->dev->enable_clk(tctx->dev);
}
static void rk_cra_hash_exit(struct crypto_tfm *tfm)
{
struct rk_ahash_ctx *tctx = crypto_tfm_ctx(tfm);
free_page((unsigned long)tctx->dev->addr_vir);
return tctx->dev->disable_clk(tctx->dev);
}
