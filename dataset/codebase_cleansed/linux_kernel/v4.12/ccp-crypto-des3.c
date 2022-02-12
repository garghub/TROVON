static int ccp_des3_complete(struct crypto_async_request *async_req, int ret)
{
struct ablkcipher_request *req = ablkcipher_request_cast(async_req);
struct ccp_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct ccp_des3_req_ctx *rctx = ablkcipher_request_ctx(req);
if (ret)
return ret;
if (ctx->u.des3.mode != CCP_DES3_MODE_ECB)
memcpy(req->info, rctx->iv, DES3_EDE_BLOCK_SIZE);
return 0;
}
static int ccp_des3_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int key_len)
{
struct ccp_ctx *ctx = crypto_tfm_ctx(crypto_ablkcipher_tfm(tfm));
struct ccp_crypto_ablkcipher_alg *alg =
ccp_crypto_ablkcipher_alg(crypto_ablkcipher_tfm(tfm));
u32 *flags = &tfm->base.crt_flags;
const u32 *K = (const u32 *)key;
if (unlikely(!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||
!((K[2] ^ K[4]) | (K[3] ^ K[5]))) &&
(*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
ctx->u.des3.type = CCP_DES3_TYPE_168;
ctx->u.des3.mode = alg->mode;
ctx->u.des3.key_len = key_len;
memcpy(ctx->u.des3.key, key, key_len);
sg_init_one(&ctx->u.des3.key_sg, ctx->u.des3.key, key_len);
return 0;
}
static int ccp_des3_crypt(struct ablkcipher_request *req, bool encrypt)
{
struct ccp_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct ccp_des3_req_ctx *rctx = ablkcipher_request_ctx(req);
struct scatterlist *iv_sg = NULL;
unsigned int iv_len = 0;
int ret;
if (!ctx->u.des3.key_len)
return -EINVAL;
if (((ctx->u.des3.mode == CCP_DES3_MODE_ECB) ||
(ctx->u.des3.mode == CCP_DES3_MODE_CBC)) &&
(req->nbytes & (DES3_EDE_BLOCK_SIZE - 1)))
return -EINVAL;
if (ctx->u.des3.mode != CCP_DES3_MODE_ECB) {
if (!req->info)
return -EINVAL;
memcpy(rctx->iv, req->info, DES3_EDE_BLOCK_SIZE);
iv_sg = &rctx->iv_sg;
iv_len = DES3_EDE_BLOCK_SIZE;
sg_init_one(iv_sg, rctx->iv, iv_len);
}
memset(&rctx->cmd, 0, sizeof(rctx->cmd));
INIT_LIST_HEAD(&rctx->cmd.entry);
rctx->cmd.engine = CCP_ENGINE_DES3;
rctx->cmd.u.des3.type = ctx->u.des3.type;
rctx->cmd.u.des3.mode = ctx->u.des3.mode;
rctx->cmd.u.des3.action = (encrypt)
? CCP_DES3_ACTION_ENCRYPT
: CCP_DES3_ACTION_DECRYPT;
rctx->cmd.u.des3.key = &ctx->u.des3.key_sg;
rctx->cmd.u.des3.key_len = ctx->u.des3.key_len;
rctx->cmd.u.des3.iv = iv_sg;
rctx->cmd.u.des3.iv_len = iv_len;
rctx->cmd.u.des3.src = req->src;
rctx->cmd.u.des3.src_len = req->nbytes;
rctx->cmd.u.des3.dst = req->dst;
ret = ccp_crypto_enqueue_request(&req->base, &rctx->cmd);
return ret;
}
static int ccp_des3_encrypt(struct ablkcipher_request *req)
{
return ccp_des3_crypt(req, true);
}
static int ccp_des3_decrypt(struct ablkcipher_request *req)
{
return ccp_des3_crypt(req, false);
}
static int ccp_des3_cra_init(struct crypto_tfm *tfm)
{
struct ccp_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->complete = ccp_des3_complete;
ctx->u.des3.key_len = 0;
tfm->crt_ablkcipher.reqsize = sizeof(struct ccp_des3_req_ctx);
return 0;
}
static void ccp_des3_cra_exit(struct crypto_tfm *tfm)
{
}
static int ccp_register_des3_alg(struct list_head *head,
const struct ccp_des3_def *def)
{
struct ccp_crypto_ablkcipher_alg *ccp_alg;
struct crypto_alg *alg;
int ret;
ccp_alg = kzalloc(sizeof(*ccp_alg), GFP_KERNEL);
if (!ccp_alg)
return -ENOMEM;
INIT_LIST_HEAD(&ccp_alg->entry);
ccp_alg->mode = def->mode;
alg = &ccp_alg->alg;
*alg = *def->alg_defaults;
snprintf(alg->cra_name, CRYPTO_MAX_ALG_NAME, "%s", def->name);
snprintf(alg->cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s",
def->driver_name);
alg->cra_blocksize = def->blocksize;
alg->cra_ablkcipher.ivsize = def->ivsize;
ret = crypto_register_alg(alg);
if (ret) {
pr_err("%s ablkcipher algorithm registration error (%d)\n",
alg->cra_name, ret);
kfree(ccp_alg);
return ret;
}
list_add(&ccp_alg->entry, head);
return 0;
}
int ccp_register_des3_algs(struct list_head *head)
{
int i, ret;
unsigned int ccpversion = ccp_version();
for (i = 0; i < ARRAY_SIZE(des3_algs); i++) {
if (des3_algs[i].version > ccpversion)
continue;
ret = ccp_register_des3_alg(head, &des3_algs[i]);
if (ret)
return ret;
}
return 0;
}
