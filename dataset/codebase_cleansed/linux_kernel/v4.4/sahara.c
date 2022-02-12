static inline void sahara_write(struct sahara_dev *dev, u32 data, u32 reg)
{
writel(data, dev->regs_base + reg);
}
static inline unsigned int sahara_read(struct sahara_dev *dev, u32 reg)
{
return readl(dev->regs_base + reg);
}
static u32 sahara_aes_key_hdr(struct sahara_dev *dev)
{
u32 hdr = SAHARA_HDR_BASE | SAHARA_HDR_SKHA_ALG_AES |
SAHARA_HDR_FORM_KEY | SAHARA_HDR_LLO |
SAHARA_HDR_CHA_SKHA | SAHARA_HDR_PARITY_BIT;
if (dev->flags & FLAGS_CBC) {
hdr |= SAHARA_HDR_SKHA_MODE_CBC;
hdr ^= SAHARA_HDR_PARITY_BIT;
}
if (dev->flags & FLAGS_ENCRYPT) {
hdr |= SAHARA_HDR_SKHA_OP_ENC;
hdr ^= SAHARA_HDR_PARITY_BIT;
}
return hdr;
}
static u32 sahara_aes_data_link_hdr(struct sahara_dev *dev)
{
return SAHARA_HDR_BASE | SAHARA_HDR_FORM_DATA |
SAHARA_HDR_CHA_SKHA | SAHARA_HDR_PARITY_BIT;
}
static void sahara_decode_error(struct sahara_dev *dev, unsigned int error)
{
u8 source = SAHARA_ERRSTATUS_GET_SOURCE(error);
u16 chasrc = ffs(SAHARA_ERRSTATUS_GET_CHASRC(error));
dev_err(dev->device, "%s: Error Register = 0x%08x\n", __func__, error);
dev_err(dev->device, " - %s.\n", sahara_err_src[source]);
if (source == SAHARA_ERRSOURCE_DMA) {
if (error & SAHARA_ERRSTATUS_DMA_DIR)
dev_err(dev->device, " * DMA read.\n");
else
dev_err(dev->device, " * DMA write.\n");
dev_err(dev->device, " * %s.\n",
sahara_err_dmasize[SAHARA_ERRSTATUS_GET_DMASZ(error)]);
dev_err(dev->device, " * %s.\n",
sahara_err_dmasrc[SAHARA_ERRSTATUS_GET_DMASRC(error)]);
} else if (source == SAHARA_ERRSOURCE_CHA) {
dev_err(dev->device, " * %s.\n",
sahara_cha_errsrc[chasrc]);
dev_err(dev->device, " * %s.\n",
sahara_cha_err[SAHARA_ERRSTATUS_GET_CHAERR(error)]);
}
dev_err(dev->device, "\n");
}
static void sahara_decode_status(struct sahara_dev *dev, unsigned int status)
{
u8 state;
if (!IS_ENABLED(DEBUG))
return;
state = SAHARA_STATUS_GET_STATE(status);
dev_dbg(dev->device, "%s: Status Register = 0x%08x\n",
__func__, status);
dev_dbg(dev->device, " - State = %d:\n", state);
if (state & SAHARA_STATE_COMP_FLAG)
dev_dbg(dev->device, " * Descriptor completed. IRQ pending.\n");
dev_dbg(dev->device, " * %s.\n",
sahara_state[state & ~SAHARA_STATE_COMP_FLAG]);
if (status & SAHARA_STATUS_DAR_FULL)
dev_dbg(dev->device, " - DAR Full.\n");
if (status & SAHARA_STATUS_ERROR)
dev_dbg(dev->device, " - Error.\n");
if (status & SAHARA_STATUS_SECURE)
dev_dbg(dev->device, " - Secure.\n");
if (status & SAHARA_STATUS_FAIL)
dev_dbg(dev->device, " - Fail.\n");
if (status & SAHARA_STATUS_RNG_RESEED)
dev_dbg(dev->device, " - RNG Reseed Request.\n");
if (status & SAHARA_STATUS_ACTIVE_RNG)
dev_dbg(dev->device, " - RNG Active.\n");
if (status & SAHARA_STATUS_ACTIVE_MDHA)
dev_dbg(dev->device, " - MDHA Active.\n");
if (status & SAHARA_STATUS_ACTIVE_SKHA)
dev_dbg(dev->device, " - SKHA Active.\n");
if (status & SAHARA_STATUS_MODE_BATCH)
dev_dbg(dev->device, " - Batch Mode.\n");
else if (status & SAHARA_STATUS_MODE_DEDICATED)
dev_dbg(dev->device, " - Decidated Mode.\n");
else if (status & SAHARA_STATUS_MODE_DEBUG)
dev_dbg(dev->device, " - Debug Mode.\n");
dev_dbg(dev->device, " - Internal state = 0x%02x\n",
SAHARA_STATUS_GET_ISTATE(status));
dev_dbg(dev->device, "Current DAR: 0x%08x\n",
sahara_read(dev, SAHARA_REG_CDAR));
dev_dbg(dev->device, "Initial DAR: 0x%08x\n\n",
sahara_read(dev, SAHARA_REG_IDAR));
}
static void sahara_dump_descriptors(struct sahara_dev *dev)
{
int i;
if (!IS_ENABLED(DEBUG))
return;
for (i = 0; i < SAHARA_MAX_HW_DESC; i++) {
dev_dbg(dev->device, "Descriptor (%d) (0x%08x):\n",
i, dev->hw_phys_desc[i]);
dev_dbg(dev->device, "\thdr = 0x%08x\n", dev->hw_desc[i]->hdr);
dev_dbg(dev->device, "\tlen1 = %u\n", dev->hw_desc[i]->len1);
dev_dbg(dev->device, "\tp1 = 0x%08x\n", dev->hw_desc[i]->p1);
dev_dbg(dev->device, "\tlen2 = %u\n", dev->hw_desc[i]->len2);
dev_dbg(dev->device, "\tp2 = 0x%08x\n", dev->hw_desc[i]->p2);
dev_dbg(dev->device, "\tnext = 0x%08x\n",
dev->hw_desc[i]->next);
}
dev_dbg(dev->device, "\n");
}
static void sahara_dump_links(struct sahara_dev *dev)
{
int i;
if (!IS_ENABLED(DEBUG))
return;
for (i = 0; i < SAHARA_MAX_HW_LINK; i++) {
dev_dbg(dev->device, "Link (%d) (0x%08x):\n",
i, dev->hw_phys_link[i]);
dev_dbg(dev->device, "\tlen = %u\n", dev->hw_link[i]->len);
dev_dbg(dev->device, "\tp = 0x%08x\n", dev->hw_link[i]->p);
dev_dbg(dev->device, "\tnext = 0x%08x\n",
dev->hw_link[i]->next);
}
dev_dbg(dev->device, "\n");
}
static int sahara_hw_descriptor_create(struct sahara_dev *dev)
{
struct sahara_ctx *ctx = dev->ctx;
struct scatterlist *sg;
int ret;
int i, j;
int idx = 0;
if (ctx->flags & FLAGS_NEW_KEY) {
memcpy(dev->key_base, ctx->key, ctx->keylen);
ctx->flags &= ~FLAGS_NEW_KEY;
if (dev->flags & FLAGS_CBC) {
dev->hw_desc[idx]->len1 = AES_BLOCK_SIZE;
dev->hw_desc[idx]->p1 = dev->iv_phys_base;
} else {
dev->hw_desc[idx]->len1 = 0;
dev->hw_desc[idx]->p1 = 0;
}
dev->hw_desc[idx]->len2 = ctx->keylen;
dev->hw_desc[idx]->p2 = dev->key_phys_base;
dev->hw_desc[idx]->next = dev->hw_phys_desc[1];
dev->hw_desc[idx]->hdr = sahara_aes_key_hdr(dev);
idx++;
}
dev->nb_in_sg = sg_nents_for_len(dev->in_sg, dev->total);
dev->nb_out_sg = sg_nents_for_len(dev->out_sg, dev->total);
if ((dev->nb_in_sg + dev->nb_out_sg) > SAHARA_MAX_HW_LINK) {
dev_err(dev->device, "not enough hw links (%d)\n",
dev->nb_in_sg + dev->nb_out_sg);
return -EINVAL;
}
ret = dma_map_sg(dev->device, dev->in_sg, dev->nb_in_sg,
DMA_TO_DEVICE);
if (ret != dev->nb_in_sg) {
dev_err(dev->device, "couldn't map in sg\n");
goto unmap_in;
}
ret = dma_map_sg(dev->device, dev->out_sg, dev->nb_out_sg,
DMA_FROM_DEVICE);
if (ret != dev->nb_out_sg) {
dev_err(dev->device, "couldn't map out sg\n");
goto unmap_out;
}
dev->hw_desc[idx]->p1 = dev->hw_phys_link[0];
sg = dev->in_sg;
for (i = 0; i < dev->nb_in_sg; i++) {
dev->hw_link[i]->len = sg->length;
dev->hw_link[i]->p = sg->dma_address;
if (i == (dev->nb_in_sg - 1)) {
dev->hw_link[i]->next = 0;
} else {
dev->hw_link[i]->next = dev->hw_phys_link[i + 1];
sg = sg_next(sg);
}
}
dev->hw_desc[idx]->p2 = dev->hw_phys_link[i];
sg = dev->out_sg;
for (j = i; j < dev->nb_out_sg + i; j++) {
dev->hw_link[j]->len = sg->length;
dev->hw_link[j]->p = sg->dma_address;
if (j == (dev->nb_out_sg + i - 1)) {
dev->hw_link[j]->next = 0;
} else {
dev->hw_link[j]->next = dev->hw_phys_link[j + 1];
sg = sg_next(sg);
}
}
dev->hw_desc[idx]->hdr = sahara_aes_data_link_hdr(dev);
dev->hw_desc[idx]->len1 = dev->total;
dev->hw_desc[idx]->len2 = dev->total;
dev->hw_desc[idx]->next = 0;
sahara_dump_descriptors(dev);
sahara_dump_links(dev);
sahara_write(dev, dev->hw_phys_desc[0], SAHARA_REG_DAR);
return 0;
unmap_out:
dma_unmap_sg(dev->device, dev->out_sg, dev->nb_out_sg,
DMA_TO_DEVICE);
unmap_in:
dma_unmap_sg(dev->device, dev->in_sg, dev->nb_in_sg,
DMA_FROM_DEVICE);
return -EINVAL;
}
static int sahara_aes_process(struct ablkcipher_request *req)
{
struct sahara_dev *dev = dev_ptr;
struct sahara_ctx *ctx;
struct sahara_aes_reqctx *rctx;
int ret;
unsigned long timeout;
dev_dbg(dev->device,
"dispatch request (nbytes=%d, src=%p, dst=%p)\n",
req->nbytes, req->src, req->dst);
dev->total = req->nbytes;
dev->in_sg = req->src;
dev->out_sg = req->dst;
rctx = ablkcipher_request_ctx(req);
ctx = crypto_ablkcipher_ctx(crypto_ablkcipher_reqtfm(req));
rctx->mode &= FLAGS_MODE_MASK;
dev->flags = (dev->flags & ~FLAGS_MODE_MASK) | rctx->mode;
if ((dev->flags & FLAGS_CBC) && req->info)
memcpy(dev->iv_base, req->info, AES_KEYSIZE_128);
dev->ctx = ctx;
reinit_completion(&dev->dma_completion);
ret = sahara_hw_descriptor_create(dev);
if (ret)
return -EINVAL;
timeout = wait_for_completion_timeout(&dev->dma_completion,
msecs_to_jiffies(SAHARA_TIMEOUT_MS));
if (!timeout) {
dev_err(dev->device, "AES timeout\n");
return -ETIMEDOUT;
}
dma_unmap_sg(dev->device, dev->out_sg, dev->nb_out_sg,
DMA_TO_DEVICE);
dma_unmap_sg(dev->device, dev->in_sg, dev->nb_in_sg,
DMA_FROM_DEVICE);
return 0;
}
static int sahara_aes_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int keylen)
{
struct sahara_ctx *ctx = crypto_ablkcipher_ctx(tfm);
int ret;
ctx->keylen = keylen;
if (keylen == AES_KEYSIZE_128) {
memcpy(ctx->key, key, keylen);
ctx->flags |= FLAGS_NEW_KEY;
return 0;
}
if (keylen != AES_KEYSIZE_128 &&
keylen != AES_KEYSIZE_192 && keylen != AES_KEYSIZE_256)
return -EINVAL;
ctx->fallback->base.crt_flags &= ~CRYPTO_TFM_REQ_MASK;
ctx->fallback->base.crt_flags |=
(tfm->base.crt_flags & CRYPTO_TFM_REQ_MASK);
ret = crypto_ablkcipher_setkey(ctx->fallback, key, keylen);
if (ret) {
struct crypto_tfm *tfm_aux = crypto_ablkcipher_tfm(tfm);
tfm_aux->crt_flags &= ~CRYPTO_TFM_RES_MASK;
tfm_aux->crt_flags |=
(ctx->fallback->base.crt_flags & CRYPTO_TFM_RES_MASK);
}
return ret;
}
static int sahara_aes_crypt(struct ablkcipher_request *req, unsigned long mode)
{
struct sahara_aes_reqctx *rctx = ablkcipher_request_ctx(req);
struct sahara_dev *dev = dev_ptr;
int err = 0;
dev_dbg(dev->device, "nbytes: %d, enc: %d, cbc: %d\n",
req->nbytes, !!(mode & FLAGS_ENCRYPT), !!(mode & FLAGS_CBC));
if (!IS_ALIGNED(req->nbytes, AES_BLOCK_SIZE)) {
dev_err(dev->device,
"request size is not exact amount of AES blocks\n");
return -EINVAL;
}
rctx->mode = mode;
mutex_lock(&dev->queue_mutex);
err = ablkcipher_enqueue_request(&dev->queue, req);
mutex_unlock(&dev->queue_mutex);
wake_up_process(dev->kthread);
return err;
}
static int sahara_aes_ecb_encrypt(struct ablkcipher_request *req)
{
struct crypto_tfm *tfm =
crypto_ablkcipher_tfm(crypto_ablkcipher_reqtfm(req));
struct sahara_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
int err;
if (unlikely(ctx->keylen != AES_KEYSIZE_128)) {
ablkcipher_request_set_tfm(req, ctx->fallback);
err = crypto_ablkcipher_encrypt(req);
ablkcipher_request_set_tfm(req, __crypto_ablkcipher_cast(tfm));
return err;
}
return sahara_aes_crypt(req, FLAGS_ENCRYPT);
}
static int sahara_aes_ecb_decrypt(struct ablkcipher_request *req)
{
struct crypto_tfm *tfm =
crypto_ablkcipher_tfm(crypto_ablkcipher_reqtfm(req));
struct sahara_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
int err;
if (unlikely(ctx->keylen != AES_KEYSIZE_128)) {
ablkcipher_request_set_tfm(req, ctx->fallback);
err = crypto_ablkcipher_decrypt(req);
ablkcipher_request_set_tfm(req, __crypto_ablkcipher_cast(tfm));
return err;
}
return sahara_aes_crypt(req, 0);
}
static int sahara_aes_cbc_encrypt(struct ablkcipher_request *req)
{
struct crypto_tfm *tfm =
crypto_ablkcipher_tfm(crypto_ablkcipher_reqtfm(req));
struct sahara_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
int err;
if (unlikely(ctx->keylen != AES_KEYSIZE_128)) {
ablkcipher_request_set_tfm(req, ctx->fallback);
err = crypto_ablkcipher_encrypt(req);
ablkcipher_request_set_tfm(req, __crypto_ablkcipher_cast(tfm));
return err;
}
return sahara_aes_crypt(req, FLAGS_ENCRYPT | FLAGS_CBC);
}
static int sahara_aes_cbc_decrypt(struct ablkcipher_request *req)
{
struct crypto_tfm *tfm =
crypto_ablkcipher_tfm(crypto_ablkcipher_reqtfm(req));
struct sahara_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
int err;
if (unlikely(ctx->keylen != AES_KEYSIZE_128)) {
ablkcipher_request_set_tfm(req, ctx->fallback);
err = crypto_ablkcipher_decrypt(req);
ablkcipher_request_set_tfm(req, __crypto_ablkcipher_cast(tfm));
return err;
}
return sahara_aes_crypt(req, FLAGS_CBC);
}
static int sahara_aes_cra_init(struct crypto_tfm *tfm)
{
const char *name = crypto_tfm_alg_name(tfm);
struct sahara_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->fallback = crypto_alloc_ablkcipher(name, 0,
CRYPTO_ALG_ASYNC | CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->fallback)) {
pr_err("Error allocating fallback algo %s\n", name);
return PTR_ERR(ctx->fallback);
}
tfm->crt_ablkcipher.reqsize = sizeof(struct sahara_aes_reqctx);
return 0;
}
static void sahara_aes_cra_exit(struct crypto_tfm *tfm)
{
struct sahara_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback)
crypto_free_ablkcipher(ctx->fallback);
ctx->fallback = NULL;
}
static u32 sahara_sha_init_hdr(struct sahara_dev *dev,
struct sahara_sha_reqctx *rctx)
{
u32 hdr = 0;
hdr = rctx->mode;
if (rctx->first) {
hdr |= SAHARA_HDR_MDHA_SET_MODE_HASH;
hdr |= SAHARA_HDR_MDHA_INIT;
} else {
hdr |= SAHARA_HDR_MDHA_SET_MODE_MD_KEY;
}
if (rctx->last)
hdr |= SAHARA_HDR_MDHA_PDATA;
if (hweight_long(hdr) % 2 == 0)
hdr |= SAHARA_HDR_PARITY_BIT;
return hdr;
}
static int sahara_sha_hw_links_create(struct sahara_dev *dev,
struct sahara_sha_reqctx *rctx,
int start)
{
struct scatterlist *sg;
unsigned int i;
int ret;
dev->in_sg = rctx->in_sg;
dev->nb_in_sg = sg_nents_for_len(dev->in_sg, rctx->total);
if ((dev->nb_in_sg) > SAHARA_MAX_HW_LINK) {
dev_err(dev->device, "not enough hw links (%d)\n",
dev->nb_in_sg + dev->nb_out_sg);
return -EINVAL;
}
sg = dev->in_sg;
ret = dma_map_sg(dev->device, dev->in_sg, dev->nb_in_sg, DMA_TO_DEVICE);
if (!ret)
return -EFAULT;
for (i = start; i < dev->nb_in_sg + start; i++) {
dev->hw_link[i]->len = sg->length;
dev->hw_link[i]->p = sg->dma_address;
if (i == (dev->nb_in_sg + start - 1)) {
dev->hw_link[i]->next = 0;
} else {
dev->hw_link[i]->next = dev->hw_phys_link[i + 1];
sg = sg_next(sg);
}
}
return i;
}
static int sahara_sha_hw_data_descriptor_create(struct sahara_dev *dev,
struct sahara_sha_reqctx *rctx,
struct ahash_request *req,
int index)
{
unsigned result_len;
int i = index;
if (rctx->first)
dev->hw_desc[index]->hdr = sahara_sha_init_hdr(dev, rctx);
else
dev->hw_desc[index]->hdr = SAHARA_HDR_MDHA_HASH;
dev->hw_desc[index]->len1 = rctx->total;
if (dev->hw_desc[index]->len1 == 0) {
dev->hw_desc[index]->p1 = 0;
rctx->sg_in_idx = 0;
} else {
dev->hw_desc[index]->p1 = dev->hw_phys_link[index];
i = sahara_sha_hw_links_create(dev, rctx, index);
rctx->sg_in_idx = index;
if (i < 0)
return i;
}
dev->hw_desc[index]->p2 = dev->hw_phys_link[i];
result_len = rctx->context_size;
dev->hw_link[i]->p = dev->context_phys_base;
dev->hw_link[i]->len = result_len;
dev->hw_desc[index]->len2 = result_len;
dev->hw_link[i]->next = 0;
return 0;
}
static int sahara_sha_hw_context_descriptor_create(struct sahara_dev *dev,
struct sahara_sha_reqctx *rctx,
struct ahash_request *req,
int index)
{
dev->hw_desc[index]->hdr = sahara_sha_init_hdr(dev, rctx);
dev->hw_desc[index]->len1 = rctx->context_size;
dev->hw_desc[index]->p1 = dev->hw_phys_link[index];
dev->hw_desc[index]->len2 = 0;
dev->hw_desc[index]->p2 = 0;
dev->hw_link[index]->len = rctx->context_size;
dev->hw_link[index]->p = dev->context_phys_base;
dev->hw_link[index]->next = 0;
return 0;
}
static int sahara_walk_and_recalc(struct scatterlist *sg, unsigned int nbytes)
{
if (!sg || !sg->length)
return nbytes;
while (nbytes && sg) {
if (nbytes <= sg->length) {
sg->length = nbytes;
sg_mark_end(sg);
break;
}
nbytes -= sg->length;
sg = sg_next(sg);
}
return nbytes;
}
static int sahara_sha_prepare_request(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
unsigned int hash_later;
unsigned int block_size;
unsigned int len;
block_size = crypto_tfm_alg_blocksize(crypto_ahash_tfm(tfm));
len = rctx->buf_cnt + req->nbytes;
if (!rctx->last && (len < block_size)) {
scatterwalk_map_and_copy(rctx->buf + rctx->buf_cnt, req->src,
0, req->nbytes, 0);
rctx->buf_cnt += req->nbytes;
return 0;
}
if (rctx->buf_cnt)
memcpy(rctx->rembuf, rctx->buf, rctx->buf_cnt);
hash_later = rctx->last ? 0 : len & (block_size - 1);
if (hash_later) {
unsigned int offset = req->nbytes - hash_later;
scatterwalk_map_and_copy(rctx->buf, req->src, offset,
hash_later, 0);
}
req->nbytes = req->nbytes - hash_later;
sahara_walk_and_recalc(req->src, req->nbytes);
if (rctx->buf_cnt && req->nbytes) {
sg_init_table(rctx->in_sg_chain, 2);
sg_set_buf(rctx->in_sg_chain, rctx->rembuf, rctx->buf_cnt);
sg_chain(rctx->in_sg_chain, 2, req->src);
rctx->total = req->nbytes + rctx->buf_cnt;
rctx->in_sg = rctx->in_sg_chain;
req->src = rctx->in_sg_chain;
} else if (rctx->buf_cnt) {
if (req->src)
rctx->in_sg = req->src;
else
rctx->in_sg = rctx->in_sg_chain;
sg_init_one(rctx->in_sg, rctx->rembuf, rctx->buf_cnt);
rctx->total = rctx->buf_cnt;
} else {
rctx->in_sg = req->src;
rctx->total = req->nbytes;
req->src = rctx->in_sg;
}
rctx->buf_cnt = hash_later;
return -EINPROGRESS;
}
static int sahara_sha_process(struct ahash_request *req)
{
struct sahara_dev *dev = dev_ptr;
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
int ret;
unsigned long timeout;
ret = sahara_sha_prepare_request(req);
if (!ret)
return ret;
if (rctx->first) {
sahara_sha_hw_data_descriptor_create(dev, rctx, req, 0);
dev->hw_desc[0]->next = 0;
rctx->first = 0;
} else {
memcpy(dev->context_base, rctx->context, rctx->context_size);
sahara_sha_hw_context_descriptor_create(dev, rctx, req, 0);
dev->hw_desc[0]->next = dev->hw_phys_desc[1];
sahara_sha_hw_data_descriptor_create(dev, rctx, req, 1);
dev->hw_desc[1]->next = 0;
}
sahara_dump_descriptors(dev);
sahara_dump_links(dev);
reinit_completion(&dev->dma_completion);
sahara_write(dev, dev->hw_phys_desc[0], SAHARA_REG_DAR);
timeout = wait_for_completion_timeout(&dev->dma_completion,
msecs_to_jiffies(SAHARA_TIMEOUT_MS));
if (!timeout) {
dev_err(dev->device, "SHA timeout\n");
return -ETIMEDOUT;
}
if (rctx->sg_in_idx)
dma_unmap_sg(dev->device, dev->in_sg, dev->nb_in_sg,
DMA_TO_DEVICE);
memcpy(rctx->context, dev->context_base, rctx->context_size);
if (req->result)
memcpy(req->result, rctx->context, rctx->digest_size);
return 0;
}
static int sahara_queue_manage(void *data)
{
struct sahara_dev *dev = (struct sahara_dev *)data;
struct crypto_async_request *async_req;
struct crypto_async_request *backlog;
int ret = 0;
do {
__set_current_state(TASK_INTERRUPTIBLE);
mutex_lock(&dev->queue_mutex);
backlog = crypto_get_backlog(&dev->queue);
async_req = crypto_dequeue_request(&dev->queue);
mutex_unlock(&dev->queue_mutex);
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
if (async_req) {
if (crypto_tfm_alg_type(async_req->tfm) ==
CRYPTO_ALG_TYPE_AHASH) {
struct ahash_request *req =
ahash_request_cast(async_req);
ret = sahara_sha_process(req);
} else {
struct ablkcipher_request *req =
ablkcipher_request_cast(async_req);
ret = sahara_aes_process(req);
}
async_req->complete(async_req, ret);
continue;
}
schedule();
} while (!kthread_should_stop());
return 0;
}
static int sahara_sha_enqueue(struct ahash_request *req, int last)
{
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
struct sahara_dev *dev = dev_ptr;
int ret;
if (!req->nbytes && !last)
return 0;
mutex_lock(&rctx->mutex);
rctx->last = last;
if (!rctx->active) {
rctx->active = 1;
rctx->first = 1;
}
mutex_lock(&dev->queue_mutex);
ret = crypto_enqueue_request(&dev->queue, &req->base);
mutex_unlock(&dev->queue_mutex);
wake_up_process(dev->kthread);
mutex_unlock(&rctx->mutex);
return ret;
}
static int sahara_sha_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
memset(rctx, 0, sizeof(*rctx));
switch (crypto_ahash_digestsize(tfm)) {
case SHA1_DIGEST_SIZE:
rctx->mode |= SAHARA_HDR_MDHA_ALG_SHA1;
rctx->digest_size = SHA1_DIGEST_SIZE;
break;
case SHA256_DIGEST_SIZE:
rctx->mode |= SAHARA_HDR_MDHA_ALG_SHA256;
rctx->digest_size = SHA256_DIGEST_SIZE;
break;
default:
return -EINVAL;
}
rctx->context_size = rctx->digest_size + 4;
rctx->active = 0;
mutex_init(&rctx->mutex);
return 0;
}
static int sahara_sha_update(struct ahash_request *req)
{
return sahara_sha_enqueue(req, 0);
}
static int sahara_sha_final(struct ahash_request *req)
{
req->nbytes = 0;
return sahara_sha_enqueue(req, 1);
}
static int sahara_sha_finup(struct ahash_request *req)
{
return sahara_sha_enqueue(req, 1);
}
static int sahara_sha_digest(struct ahash_request *req)
{
sahara_sha_init(req);
return sahara_sha_finup(req);
}
static int sahara_sha_export(struct ahash_request *req, void *out)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct sahara_ctx *ctx = crypto_ahash_ctx(ahash);
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
memcpy(out, ctx, sizeof(struct sahara_ctx));
memcpy(out + sizeof(struct sahara_sha_reqctx), rctx,
sizeof(struct sahara_sha_reqctx));
return 0;
}
static int sahara_sha_import(struct ahash_request *req, const void *in)
{
struct crypto_ahash *ahash = crypto_ahash_reqtfm(req);
struct sahara_ctx *ctx = crypto_ahash_ctx(ahash);
struct sahara_sha_reqctx *rctx = ahash_request_ctx(req);
memcpy(ctx, in, sizeof(struct sahara_ctx));
memcpy(rctx, in + sizeof(struct sahara_sha_reqctx),
sizeof(struct sahara_sha_reqctx));
return 0;
}
static int sahara_sha_cra_init(struct crypto_tfm *tfm)
{
const char *name = crypto_tfm_alg_name(tfm);
struct sahara_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->shash_fallback = crypto_alloc_shash(name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->shash_fallback)) {
pr_err("Error allocating fallback algo %s\n", name);
return PTR_ERR(ctx->shash_fallback);
}
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct sahara_sha_reqctx) +
SHA_BUFFER_LEN + SHA256_BLOCK_SIZE);
return 0;
}
static void sahara_sha_cra_exit(struct crypto_tfm *tfm)
{
struct sahara_ctx *ctx = crypto_tfm_ctx(tfm);
crypto_free_shash(ctx->shash_fallback);
ctx->shash_fallback = NULL;
}
static irqreturn_t sahara_irq_handler(int irq, void *data)
{
struct sahara_dev *dev = (struct sahara_dev *)data;
unsigned int stat = sahara_read(dev, SAHARA_REG_STATUS);
unsigned int err = sahara_read(dev, SAHARA_REG_ERRSTATUS);
sahara_write(dev, SAHARA_CMD_CLEAR_INT | SAHARA_CMD_CLEAR_ERR,
SAHARA_REG_CMD);
sahara_decode_status(dev, stat);
if (SAHARA_STATUS_GET_STATE(stat) == SAHARA_STATE_BUSY) {
return IRQ_NONE;
} else if (SAHARA_STATUS_GET_STATE(stat) == SAHARA_STATE_COMPLETE) {
dev->error = 0;
} else {
sahara_decode_error(dev, err);
dev->error = -EINVAL;
}
complete(&dev->dma_completion);
return IRQ_HANDLED;
}
static int sahara_register_algs(struct sahara_dev *dev)
{
int err;
unsigned int i, j, k, l;
for (i = 0; i < ARRAY_SIZE(aes_algs); i++) {
INIT_LIST_HEAD(&aes_algs[i].cra_list);
err = crypto_register_alg(&aes_algs[i]);
if (err)
goto err_aes_algs;
}
for (k = 0; k < ARRAY_SIZE(sha_v3_algs); k++) {
err = crypto_register_ahash(&sha_v3_algs[k]);
if (err)
goto err_sha_v3_algs;
}
if (dev->version > SAHARA_VERSION_3)
for (l = 0; l < ARRAY_SIZE(sha_v4_algs); l++) {
err = crypto_register_ahash(&sha_v4_algs[l]);
if (err)
goto err_sha_v4_algs;
}
return 0;
err_sha_v4_algs:
for (j = 0; j < l; j++)
crypto_unregister_ahash(&sha_v4_algs[j]);
err_sha_v3_algs:
for (j = 0; j < k; j++)
crypto_unregister_ahash(&sha_v4_algs[j]);
err_aes_algs:
for (j = 0; j < i; j++)
crypto_unregister_alg(&aes_algs[j]);
return err;
}
static void sahara_unregister_algs(struct sahara_dev *dev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(aes_algs); i++)
crypto_unregister_alg(&aes_algs[i]);
for (i = 0; i < ARRAY_SIZE(sha_v4_algs); i++)
crypto_unregister_ahash(&sha_v3_algs[i]);
if (dev->version > SAHARA_VERSION_3)
for (i = 0; i < ARRAY_SIZE(sha_v4_algs); i++)
crypto_unregister_ahash(&sha_v4_algs[i]);
}
static int sahara_probe(struct platform_device *pdev)
{
struct sahara_dev *dev;
struct resource *res;
u32 version;
int irq;
int err;
int i;
dev = devm_kzalloc(&pdev->dev, sizeof(struct sahara_dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&pdev->dev, "unable to alloc data struct.\n");
return -ENOMEM;
}
dev->device = &pdev->dev;
platform_set_drvdata(pdev, dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->regs_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dev->regs_base))
return PTR_ERR(dev->regs_base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq resource\n");
return irq;
}
err = devm_request_irq(&pdev->dev, irq, sahara_irq_handler,
0, dev_name(&pdev->dev), dev);
if (err) {
dev_err(&pdev->dev, "failed to request irq\n");
return err;
}
dev->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(dev->clk_ipg)) {
dev_err(&pdev->dev, "Could not get ipg clock\n");
return PTR_ERR(dev->clk_ipg);
}
dev->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(dev->clk_ahb)) {
dev_err(&pdev->dev, "Could not get ahb clock\n");
return PTR_ERR(dev->clk_ahb);
}
dev->hw_desc[0] = dmam_alloc_coherent(&pdev->dev,
SAHARA_MAX_HW_DESC * sizeof(struct sahara_hw_desc),
&dev->hw_phys_desc[0], GFP_KERNEL);
if (!dev->hw_desc[0]) {
dev_err(&pdev->dev, "Could not allocate hw descriptors\n");
return -ENOMEM;
}
dev->hw_desc[1] = dev->hw_desc[0] + 1;
dev->hw_phys_desc[1] = dev->hw_phys_desc[0] +
sizeof(struct sahara_hw_desc);
dev->key_base = dmam_alloc_coherent(&pdev->dev, 2 * AES_KEYSIZE_128,
&dev->key_phys_base, GFP_KERNEL);
if (!dev->key_base) {
dev_err(&pdev->dev, "Could not allocate memory for key\n");
return -ENOMEM;
}
dev->iv_base = dev->key_base + AES_KEYSIZE_128;
dev->iv_phys_base = dev->key_phys_base + AES_KEYSIZE_128;
dev->context_base = dmam_alloc_coherent(&pdev->dev,
SHA256_DIGEST_SIZE + 4,
&dev->context_phys_base, GFP_KERNEL);
if (!dev->context_base) {
dev_err(&pdev->dev, "Could not allocate memory for MDHA context\n");
return -ENOMEM;
}
dev->hw_link[0] = dmam_alloc_coherent(&pdev->dev,
SAHARA_MAX_HW_LINK * sizeof(struct sahara_hw_link),
&dev->hw_phys_link[0], GFP_KERNEL);
if (!dev->hw_link[0]) {
dev_err(&pdev->dev, "Could not allocate hw links\n");
return -ENOMEM;
}
for (i = 1; i < SAHARA_MAX_HW_LINK; i++) {
dev->hw_phys_link[i] = dev->hw_phys_link[i - 1] +
sizeof(struct sahara_hw_link);
dev->hw_link[i] = dev->hw_link[i - 1] + 1;
}
crypto_init_queue(&dev->queue, SAHARA_QUEUE_LENGTH);
spin_lock_init(&dev->lock);
mutex_init(&dev->queue_mutex);
dev_ptr = dev;
dev->kthread = kthread_run(sahara_queue_manage, dev, "sahara_crypto");
if (IS_ERR(dev->kthread)) {
return PTR_ERR(dev->kthread);
}
init_completion(&dev->dma_completion);
err = clk_prepare_enable(dev->clk_ipg);
if (err)
return err;
err = clk_prepare_enable(dev->clk_ahb);
if (err)
goto clk_ipg_disable;
version = sahara_read(dev, SAHARA_REG_VERSION);
if (of_device_is_compatible(pdev->dev.of_node, "fsl,imx27-sahara")) {
if (version != SAHARA_VERSION_3)
err = -ENODEV;
} else if (of_device_is_compatible(pdev->dev.of_node,
"fsl,imx53-sahara")) {
if (((version >> 8) & 0xff) != SAHARA_VERSION_4)
err = -ENODEV;
version = (version >> 8) & 0xff;
}
if (err == -ENODEV) {
dev_err(&pdev->dev, "SAHARA version %d not supported\n",
version);
goto err_algs;
}
dev->version = version;
sahara_write(dev, SAHARA_CMD_RESET | SAHARA_CMD_MODE_BATCH,
SAHARA_REG_CMD);
sahara_write(dev, SAHARA_CONTROL_SET_THROTTLE(0) |
SAHARA_CONTROL_SET_MAXBURST(8) |
SAHARA_CONTROL_RNG_AUTORSD |
SAHARA_CONTROL_ENABLE_INT,
SAHARA_REG_CONTROL);
err = sahara_register_algs(dev);
if (err)
goto err_algs;
dev_info(&pdev->dev, "SAHARA version %d initialized\n", version);
return 0;
err_algs:
kthread_stop(dev->kthread);
dev_ptr = NULL;
clk_disable_unprepare(dev->clk_ahb);
clk_ipg_disable:
clk_disable_unprepare(dev->clk_ipg);
return err;
}
static int sahara_remove(struct platform_device *pdev)
{
struct sahara_dev *dev = platform_get_drvdata(pdev);
kthread_stop(dev->kthread);
sahara_unregister_algs(dev);
clk_disable_unprepare(dev->clk_ipg);
clk_disable_unprepare(dev->clk_ahb);
dev_ptr = NULL;
return 0;
}
