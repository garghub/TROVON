static void safexcel_cipher_token(struct safexcel_cipher_ctx *ctx,
struct crypto_async_request *async,
struct safexcel_command_desc *cdesc,
u32 length)
{
struct skcipher_request *req = skcipher_request_cast(async);
struct safexcel_token *token;
unsigned offset = 0;
if (ctx->mode == CONTEXT_CONTROL_CRYPTO_MODE_CBC) {
offset = AES_BLOCK_SIZE / sizeof(u32);
memcpy(cdesc->control_data.token, req->iv, AES_BLOCK_SIZE);
cdesc->control_data.options |= EIP197_OPTION_4_TOKEN_IV_CMD;
}
token = (struct safexcel_token *)(cdesc->control_data.token + offset);
token[0].opcode = EIP197_TOKEN_OPCODE_DIRECTION;
token[0].packet_length = length;
token[0].stat = EIP197_TOKEN_STAT_LAST_PACKET;
token[0].instructions = EIP197_TOKEN_INS_LAST |
EIP197_TOKEN_INS_TYPE_CRYTO |
EIP197_TOKEN_INS_TYPE_OUTPUT;
}
static int safexcel_aes_setkey(struct crypto_skcipher *ctfm, const u8 *key,
unsigned int len)
{
struct crypto_tfm *tfm = crypto_skcipher_tfm(ctfm);
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypto_aes_ctx aes;
int ret, i;
ret = crypto_aes_expand_key(&aes, key, len);
if (ret) {
crypto_skcipher_set_flags(ctfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return ret;
}
for (i = 0; i < len / sizeof(u32); i++) {
if (ctx->key[i] != cpu_to_le32(aes.key_enc[i])) {
ctx->base.needs_inv = true;
break;
}
}
for (i = 0; i < len / sizeof(u32); i++)
ctx->key[i] = cpu_to_le32(aes.key_enc[i]);
ctx->key_len = len;
memzero_explicit(&aes, sizeof(aes));
return 0;
}
static int safexcel_context_control(struct safexcel_cipher_ctx *ctx,
struct safexcel_command_desc *cdesc)
{
struct safexcel_crypto_priv *priv = ctx->priv;
int ctrl_size;
if (ctx->direction == SAFEXCEL_ENCRYPT)
cdesc->control_data.control0 |= CONTEXT_CONTROL_TYPE_CRYPTO_OUT;
else
cdesc->control_data.control0 |= CONTEXT_CONTROL_TYPE_CRYPTO_IN;
cdesc->control_data.control0 |= CONTEXT_CONTROL_KEY_EN;
cdesc->control_data.control1 |= ctx->mode;
switch (ctx->key_len) {
case AES_KEYSIZE_128:
cdesc->control_data.control0 |= CONTEXT_CONTROL_CRYPTO_ALG_AES128;
ctrl_size = 4;
break;
case AES_KEYSIZE_192:
cdesc->control_data.control0 |= CONTEXT_CONTROL_CRYPTO_ALG_AES192;
ctrl_size = 6;
break;
case AES_KEYSIZE_256:
cdesc->control_data.control0 |= CONTEXT_CONTROL_CRYPTO_ALG_AES256;
ctrl_size = 8;
break;
default:
dev_err(priv->dev, "aes keysize not supported: %u\n",
ctx->key_len);
return -EINVAL;
}
cdesc->control_data.control0 |= CONTEXT_CONTROL_SIZE(ctrl_size);
return 0;
}
static int safexcel_handle_result(struct safexcel_crypto_priv *priv, int ring,
struct crypto_async_request *async,
bool *should_complete, int *ret)
{
struct skcipher_request *req = skcipher_request_cast(async);
struct safexcel_result_desc *rdesc;
int ndesc = 0;
*ret = 0;
spin_lock_bh(&priv->ring[ring].egress_lock);
do {
rdesc = safexcel_ring_next_rptr(priv, &priv->ring[ring].rdr);
if (IS_ERR(rdesc)) {
dev_err(priv->dev,
"cipher: result: could not retrieve the result descriptor\n");
*ret = PTR_ERR(rdesc);
break;
}
if (rdesc->result_data.error_code) {
dev_err(priv->dev,
"cipher: result: result descriptor error (%d)\n",
rdesc->result_data.error_code);
*ret = -EIO;
}
ndesc++;
} while (!rdesc->last_seg);
safexcel_complete(priv, ring);
spin_unlock_bh(&priv->ring[ring].egress_lock);
if (req->src == req->dst) {
dma_unmap_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_BIDIRECTIONAL);
} else {
dma_unmap_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_TO_DEVICE);
dma_unmap_sg(priv->dev, req->dst,
sg_nents_for_len(req->dst, req->cryptlen),
DMA_FROM_DEVICE);
}
*should_complete = true;
return ndesc;
}
static int safexcel_aes_send(struct crypto_async_request *async,
int ring, struct safexcel_request *request,
int *commands, int *results)
{
struct skcipher_request *req = skcipher_request_cast(async);
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct safexcel_crypto_priv *priv = ctx->priv;
struct safexcel_command_desc *cdesc;
struct safexcel_result_desc *rdesc;
struct scatterlist *sg;
int nr_src, nr_dst, n_cdesc = 0, n_rdesc = 0, queued = req->cryptlen;
int i, ret = 0;
if (req->src == req->dst) {
nr_src = dma_map_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_BIDIRECTIONAL);
nr_dst = nr_src;
if (!nr_src)
return -EINVAL;
} else {
nr_src = dma_map_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_TO_DEVICE);
if (!nr_src)
return -EINVAL;
nr_dst = dma_map_sg(priv->dev, req->dst,
sg_nents_for_len(req->dst, req->cryptlen),
DMA_FROM_DEVICE);
if (!nr_dst) {
dma_unmap_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_TO_DEVICE);
return -EINVAL;
}
}
memcpy(ctx->base.ctxr->data, ctx->key, ctx->key_len);
spin_lock_bh(&priv->ring[ring].egress_lock);
for_each_sg(req->src, sg, nr_src, i) {
int len = sg_dma_len(sg);
if (queued - len < 0)
len = queued;
cdesc = safexcel_add_cdesc(priv, ring, !n_cdesc, !(queued - len),
sg_dma_address(sg), len, req->cryptlen,
ctx->base.ctxr_dma);
if (IS_ERR(cdesc)) {
ret = PTR_ERR(cdesc);
goto cdesc_rollback;
}
n_cdesc++;
if (n_cdesc == 1) {
safexcel_context_control(ctx, cdesc);
safexcel_cipher_token(ctx, async, cdesc, req->cryptlen);
}
queued -= len;
if (!queued)
break;
}
for_each_sg(req->dst, sg, nr_dst, i) {
bool first = !i, last = (i == nr_dst - 1);
u32 len = sg_dma_len(sg);
rdesc = safexcel_add_rdesc(priv, ring, first, last,
sg_dma_address(sg), len);
if (IS_ERR(rdesc)) {
ret = PTR_ERR(rdesc);
goto rdesc_rollback;
}
n_rdesc++;
}
spin_unlock_bh(&priv->ring[ring].egress_lock);
request->req = &req->base;
ctx->base.handle_result = safexcel_handle_result;
*commands = n_cdesc;
*results = n_rdesc;
return 0;
rdesc_rollback:
for (i = 0; i < n_rdesc; i++)
safexcel_ring_rollback_wptr(priv, &priv->ring[ring].rdr);
cdesc_rollback:
for (i = 0; i < n_cdesc; i++)
safexcel_ring_rollback_wptr(priv, &priv->ring[ring].cdr);
spin_unlock_bh(&priv->ring[ring].egress_lock);
if (req->src == req->dst) {
dma_unmap_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_BIDIRECTIONAL);
} else {
dma_unmap_sg(priv->dev, req->src,
sg_nents_for_len(req->src, req->cryptlen),
DMA_TO_DEVICE);
dma_unmap_sg(priv->dev, req->dst,
sg_nents_for_len(req->dst, req->cryptlen),
DMA_FROM_DEVICE);
}
return ret;
}
static int safexcel_handle_inv_result(struct safexcel_crypto_priv *priv,
int ring,
struct crypto_async_request *async,
bool *should_complete, int *ret)
{
struct skcipher_request *req = skcipher_request_cast(async);
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct safexcel_result_desc *rdesc;
int ndesc = 0, enq_ret;
*ret = 0;
spin_lock_bh(&priv->ring[ring].egress_lock);
do {
rdesc = safexcel_ring_next_rptr(priv, &priv->ring[ring].rdr);
if (IS_ERR(rdesc)) {
dev_err(priv->dev,
"cipher: invalidate: could not retrieve the result descriptor\n");
*ret = PTR_ERR(rdesc);
break;
}
if (rdesc->result_data.error_code) {
dev_err(priv->dev, "cipher: invalidate: result descriptor error (%d)\n",
rdesc->result_data.error_code);
*ret = -EIO;
}
ndesc++;
} while (!rdesc->last_seg);
safexcel_complete(priv, ring);
spin_unlock_bh(&priv->ring[ring].egress_lock);
if (ctx->base.exit_inv) {
dma_pool_free(priv->context_pool, ctx->base.ctxr,
ctx->base.ctxr_dma);
*should_complete = true;
return ndesc;
}
ring = safexcel_select_ring(priv);
ctx->base.ring = ring;
ctx->base.needs_inv = false;
ctx->base.send = safexcel_aes_send;
spin_lock_bh(&priv->ring[ring].queue_lock);
enq_ret = crypto_enqueue_request(&priv->ring[ring].queue, async);
spin_unlock_bh(&priv->ring[ring].queue_lock);
if (enq_ret != -EINPROGRESS)
*ret = enq_ret;
if (!priv->ring[ring].need_dequeue)
safexcel_dequeue(priv, ring);
*should_complete = false;
return ndesc;
}
static int safexcel_cipher_send_inv(struct crypto_async_request *async,
int ring, struct safexcel_request *request,
int *commands, int *results)
{
struct skcipher_request *req = skcipher_request_cast(async);
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct safexcel_crypto_priv *priv = ctx->priv;
int ret;
ctx->base.handle_result = safexcel_handle_inv_result;
ret = safexcel_invalidate_cache(async, &ctx->base, priv,
ctx->base.ctxr_dma, ring, request);
if (unlikely(ret))
return ret;
*commands = 1;
*results = 1;
return 0;
}
static int safexcel_cipher_exit_inv(struct crypto_tfm *tfm)
{
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(tfm);
struct safexcel_crypto_priv *priv = ctx->priv;
struct skcipher_request req;
struct safexcel_inv_result result = { 0 };
int ring = ctx->base.ring;
memset(&req, 0, sizeof(struct skcipher_request));
init_completion(&result.completion);
skcipher_request_set_callback(&req, CRYPTO_TFM_REQ_MAY_BACKLOG,
safexcel_inv_complete, &result);
skcipher_request_set_tfm(&req, __crypto_skcipher_cast(tfm));
ctx = crypto_tfm_ctx(req.base.tfm);
ctx->base.exit_inv = true;
ctx->base.send = safexcel_cipher_send_inv;
spin_lock_bh(&priv->ring[ring].queue_lock);
crypto_enqueue_request(&priv->ring[ring].queue, &req.base);
spin_unlock_bh(&priv->ring[ring].queue_lock);
if (!priv->ring[ring].need_dequeue)
safexcel_dequeue(priv, ring);
wait_for_completion_interruptible(&result.completion);
if (result.error) {
dev_warn(priv->dev,
"cipher: sync: invalidate: completion error %d\n",
result.error);
return result.error;
}
return 0;
}
static int safexcel_aes(struct skcipher_request *req,
enum safexcel_cipher_direction dir, u32 mode)
{
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(req->base.tfm);
struct safexcel_crypto_priv *priv = ctx->priv;
int ret, ring;
ctx->direction = dir;
ctx->mode = mode;
if (ctx->base.ctxr) {
if (ctx->base.needs_inv)
ctx->base.send = safexcel_cipher_send_inv;
} else {
ctx->base.ring = safexcel_select_ring(priv);
ctx->base.send = safexcel_aes_send;
ctx->base.ctxr = dma_pool_zalloc(priv->context_pool,
EIP197_GFP_FLAGS(req->base),
&ctx->base.ctxr_dma);
if (!ctx->base.ctxr)
return -ENOMEM;
}
ring = ctx->base.ring;
spin_lock_bh(&priv->ring[ring].queue_lock);
ret = crypto_enqueue_request(&priv->ring[ring].queue, &req->base);
spin_unlock_bh(&priv->ring[ring].queue_lock);
if (!priv->ring[ring].need_dequeue)
safexcel_dequeue(priv, ring);
return ret;
}
static int safexcel_ecb_aes_encrypt(struct skcipher_request *req)
{
return safexcel_aes(req, SAFEXCEL_ENCRYPT,
CONTEXT_CONTROL_CRYPTO_MODE_ECB);
}
static int safexcel_ecb_aes_decrypt(struct skcipher_request *req)
{
return safexcel_aes(req, SAFEXCEL_DECRYPT,
CONTEXT_CONTROL_CRYPTO_MODE_ECB);
}
static int safexcel_skcipher_cra_init(struct crypto_tfm *tfm)
{
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(tfm);
struct safexcel_alg_template *tmpl =
container_of(tfm->__crt_alg, struct safexcel_alg_template,
alg.skcipher.base);
ctx->priv = tmpl->priv;
return 0;
}
static void safexcel_skcipher_cra_exit(struct crypto_tfm *tfm)
{
struct safexcel_cipher_ctx *ctx = crypto_tfm_ctx(tfm);
struct safexcel_crypto_priv *priv = ctx->priv;
int ret;
memzero_explicit(ctx->key, 8 * sizeof(u32));
if (!ctx->base.ctxr)
return;
memzero_explicit(ctx->base.ctxr->data, 8 * sizeof(u32));
ret = safexcel_cipher_exit_inv(tfm);
if (ret)
dev_warn(priv->dev, "cipher: invalidation error %d\n", ret);
}
static int safexcel_cbc_aes_encrypt(struct skcipher_request *req)
{
return safexcel_aes(req, SAFEXCEL_ENCRYPT,
CONTEXT_CONTROL_CRYPTO_MODE_CBC);
}
static int safexcel_cbc_aes_decrypt(struct skcipher_request *req)
{
return safexcel_aes(req, SAFEXCEL_DECRYPT,
CONTEXT_CONTROL_CRYPTO_MODE_CBC);
}
