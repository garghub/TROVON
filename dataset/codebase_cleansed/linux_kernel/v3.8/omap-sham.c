static inline u32 omap_sham_read(struct omap_sham_dev *dd, u32 offset)
{
return __raw_readl(dd->io_base + offset);
}
static inline void omap_sham_write(struct omap_sham_dev *dd,
u32 offset, u32 value)
{
__raw_writel(value, dd->io_base + offset);
}
static inline void omap_sham_write_mask(struct omap_sham_dev *dd, u32 address,
u32 value, u32 mask)
{
u32 val;
val = omap_sham_read(dd, address);
val &= ~mask;
val |= value;
omap_sham_write(dd, address, val);
}
static inline int omap_sham_wait(struct omap_sham_dev *dd, u32 offset, u32 bit)
{
unsigned long timeout = jiffies + DEFAULT_TIMEOUT_INTERVAL;
while (!(omap_sham_read(dd, offset) & bit)) {
if (time_is_before_jiffies(timeout))
return -ETIMEDOUT;
}
return 0;
}
static void omap_sham_copy_hash(struct ahash_request *req, int out)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
u32 *hash = (u32 *)ctx->digest;
int i;
for (i = 0; i < SHA1_DIGEST_SIZE / sizeof(u32); i++) {
if (out)
hash[i] = omap_sham_read(ctx->dd,
SHA_REG_DIGEST(i));
else
omap_sham_write(ctx->dd,
SHA_REG_DIGEST(i), hash[i]);
}
}
static void omap_sham_copy_ready_hash(struct ahash_request *req)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
u32 *in = (u32 *)ctx->digest;
u32 *hash = (u32 *)req->result;
int i;
if (!hash)
return;
if (likely(ctx->flags & BIT(FLAGS_SHA1))) {
for (i = 0; i < SHA1_DIGEST_SIZE / sizeof(u32); i++)
hash[i] = be32_to_cpu(in[i]);
} else {
for (i = 0; i < MD5_DIGEST_SIZE / sizeof(u32); i++)
hash[i] = le32_to_cpu(in[i]);
}
}
static int omap_sham_hw_init(struct omap_sham_dev *dd)
{
clk_enable(dd->iclk);
if (!test_bit(FLAGS_INIT, &dd->flags)) {
omap_sham_write_mask(dd, SHA_REG_MASK,
SHA_REG_MASK_SOFTRESET, SHA_REG_MASK_SOFTRESET);
if (omap_sham_wait(dd, SHA_REG_SYSSTATUS,
SHA_REG_SYSSTATUS_RESETDONE))
return -ETIMEDOUT;
set_bit(FLAGS_INIT, &dd->flags);
dd->err = 0;
}
return 0;
}
static void omap_sham_write_ctrl(struct omap_sham_dev *dd, size_t length,
int final, int dma)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
u32 val = length << 5, mask;
if (likely(ctx->digcnt))
omap_sham_write(dd, SHA_REG_DIGCNT, ctx->digcnt);
omap_sham_write_mask(dd, SHA_REG_MASK,
SHA_REG_MASK_IT_EN | (dma ? SHA_REG_MASK_DMA_EN : 0),
SHA_REG_MASK_IT_EN | SHA_REG_MASK_DMA_EN);
if (ctx->flags & BIT(FLAGS_SHA1))
val |= SHA_REG_CTRL_ALGO;
if (!ctx->digcnt)
val |= SHA_REG_CTRL_ALGO_CONST;
if (final)
val |= SHA_REG_CTRL_CLOSE_HASH;
mask = SHA_REG_CTRL_ALGO_CONST | SHA_REG_CTRL_CLOSE_HASH |
SHA_REG_CTRL_ALGO | SHA_REG_CTRL_LENGTH;
omap_sham_write_mask(dd, SHA_REG_CTRL, val, mask);
}
static int omap_sham_xmit_cpu(struct omap_sham_dev *dd, const u8 *buf,
size_t length, int final)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
int count, len32;
const u32 *buffer = (const u32 *)buf;
dev_dbg(dd->dev, "xmit_cpu: digcnt: %d, length: %d, final: %d\n",
ctx->digcnt, length, final);
omap_sham_write_ctrl(dd, length, final, 0);
ctx->digcnt += length;
if (omap_sham_wait(dd, SHA_REG_CTRL, SHA_REG_CTRL_INPUT_READY))
return -ETIMEDOUT;
if (final)
set_bit(FLAGS_FINAL, &dd->flags);
set_bit(FLAGS_CPU, &dd->flags);
len32 = DIV_ROUND_UP(length, sizeof(u32));
for (count = 0; count < len32; count++)
omap_sham_write(dd, SHA_REG_DIN(count), buffer[count]);
return -EINPROGRESS;
}
static int omap_sham_xmit_dma(struct omap_sham_dev *dd, dma_addr_t dma_addr,
size_t length, int final)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
int len32;
dev_dbg(dd->dev, "xmit_dma: digcnt: %d, length: %d, final: %d\n",
ctx->digcnt, length, final);
len32 = DIV_ROUND_UP(length, sizeof(u32));
omap_set_dma_transfer_params(dd->dma_lch, OMAP_DMA_DATA_TYPE_S32, len32,
1, OMAP_DMA_SYNC_PACKET, dd->dma,
OMAP_DMA_DST_SYNC_PREFETCH);
omap_set_dma_src_params(dd->dma_lch, 0, OMAP_DMA_AMODE_POST_INC,
dma_addr, 0, 0);
omap_sham_write_ctrl(dd, length, final, 1);
ctx->digcnt += length;
if (final)
set_bit(FLAGS_FINAL, &dd->flags);
set_bit(FLAGS_DMA_ACTIVE, &dd->flags);
omap_start_dma(dd->dma_lch);
return -EINPROGRESS;
}
static size_t omap_sham_append_buffer(struct omap_sham_reqctx *ctx,
const u8 *data, size_t length)
{
size_t count = min(length, ctx->buflen - ctx->bufcnt);
count = min(count, ctx->total);
if (count <= 0)
return 0;
memcpy(ctx->buffer + ctx->bufcnt, data, count);
ctx->bufcnt += count;
return count;
}
static size_t omap_sham_append_sg(struct omap_sham_reqctx *ctx)
{
size_t count;
while (ctx->sg) {
count = omap_sham_append_buffer(ctx,
sg_virt(ctx->sg) + ctx->offset,
ctx->sg->length - ctx->offset);
if (!count)
break;
ctx->offset += count;
ctx->total -= count;
if (ctx->offset == ctx->sg->length) {
ctx->sg = sg_next(ctx->sg);
if (ctx->sg)
ctx->offset = 0;
else
ctx->total = 0;
}
}
return 0;
}
static int omap_sham_xmit_dma_map(struct omap_sham_dev *dd,
struct omap_sham_reqctx *ctx,
size_t length, int final)
{
ctx->dma_addr = dma_map_single(dd->dev, ctx->buffer, ctx->buflen,
DMA_TO_DEVICE);
if (dma_mapping_error(dd->dev, ctx->dma_addr)) {
dev_err(dd->dev, "dma %u bytes error\n", ctx->buflen);
return -EINVAL;
}
ctx->flags &= ~BIT(FLAGS_SG);
return omap_sham_xmit_dma(dd, ctx->dma_addr, length, final);
}
static int omap_sham_update_dma_slow(struct omap_sham_dev *dd)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
unsigned int final;
size_t count;
omap_sham_append_sg(ctx);
final = (ctx->flags & BIT(FLAGS_FINUP)) && !ctx->total;
dev_dbg(dd->dev, "slow: bufcnt: %u, digcnt: %d, final: %d\n",
ctx->bufcnt, ctx->digcnt, final);
if (final || (ctx->bufcnt == ctx->buflen && ctx->total)) {
count = ctx->bufcnt;
ctx->bufcnt = 0;
return omap_sham_xmit_dma_map(dd, ctx, count, final);
}
return 0;
}
static int omap_sham_update_dma_start(struct omap_sham_dev *dd)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
unsigned int length, final, tail;
struct scatterlist *sg;
if (!ctx->total)
return 0;
if (ctx->bufcnt || ctx->offset)
return omap_sham_update_dma_slow(dd);
dev_dbg(dd->dev, "fast: digcnt: %d, bufcnt: %u, total: %u\n",
ctx->digcnt, ctx->bufcnt, ctx->total);
sg = ctx->sg;
if (!SG_AA(sg))
return omap_sham_update_dma_slow(dd);
if (!sg_is_last(sg) && !SG_SA(sg))
return omap_sham_update_dma_slow(dd);
length = min(ctx->total, sg->length);
if (sg_is_last(sg)) {
if (!(ctx->flags & BIT(FLAGS_FINUP))) {
tail = length & (SHA1_MD5_BLOCK_SIZE - 1);
if (!tail)
tail = SHA1_MD5_BLOCK_SIZE;
length -= tail;
}
}
if (!dma_map_sg(dd->dev, ctx->sg, 1, DMA_TO_DEVICE)) {
dev_err(dd->dev, "dma_map_sg error\n");
return -EINVAL;
}
ctx->flags |= BIT(FLAGS_SG);
ctx->total -= length;
ctx->offset = length;
final = (ctx->flags & BIT(FLAGS_FINUP)) && !ctx->total;
return omap_sham_xmit_dma(dd, sg_dma_address(ctx->sg), length, final);
}
static int omap_sham_update_cpu(struct omap_sham_dev *dd)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
int bufcnt;
omap_sham_append_sg(ctx);
bufcnt = ctx->bufcnt;
ctx->bufcnt = 0;
return omap_sham_xmit_cpu(dd, ctx->buffer, bufcnt, 1);
}
static int omap_sham_update_dma_stop(struct omap_sham_dev *dd)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(dd->req);
omap_stop_dma(dd->dma_lch);
if (ctx->flags & BIT(FLAGS_SG)) {
dma_unmap_sg(dd->dev, ctx->sg, 1, DMA_TO_DEVICE);
if (ctx->sg->length == ctx->offset) {
ctx->sg = sg_next(ctx->sg);
if (ctx->sg)
ctx->offset = 0;
}
} else {
dma_unmap_single(dd->dev, ctx->dma_addr, ctx->buflen,
DMA_TO_DEVICE);
}
return 0;
}
static int omap_sham_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct omap_sham_ctx *tctx = crypto_ahash_ctx(tfm);
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
struct omap_sham_dev *dd = NULL, *tmp;
spin_lock_bh(&sham.lock);
if (!tctx->dd) {
list_for_each_entry(tmp, &sham.dev_list, list) {
dd = tmp;
break;
}
tctx->dd = dd;
} else {
dd = tctx->dd;
}
spin_unlock_bh(&sham.lock);
ctx->dd = dd;
ctx->flags = 0;
dev_dbg(dd->dev, "init: digest size: %d\n",
crypto_ahash_digestsize(tfm));
if (crypto_ahash_digestsize(tfm) == SHA1_DIGEST_SIZE)
ctx->flags |= BIT(FLAGS_SHA1);
ctx->bufcnt = 0;
ctx->digcnt = 0;
ctx->buflen = BUFLEN;
if (tctx->flags & BIT(FLAGS_HMAC)) {
struct omap_sham_hmac_ctx *bctx = tctx->base;
memcpy(ctx->buffer, bctx->ipad, SHA1_MD5_BLOCK_SIZE);
ctx->bufcnt = SHA1_MD5_BLOCK_SIZE;
ctx->flags |= BIT(FLAGS_HMAC);
}
return 0;
}
static int omap_sham_update_req(struct omap_sham_dev *dd)
{
struct ahash_request *req = dd->req;
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
int err;
dev_dbg(dd->dev, "update_req: total: %u, digcnt: %d, finup: %d\n",
ctx->total, ctx->digcnt, (ctx->flags & BIT(FLAGS_FINUP)) != 0);
if (ctx->flags & BIT(FLAGS_CPU))
err = omap_sham_update_cpu(dd);
else
err = omap_sham_update_dma_start(dd);
dev_dbg(dd->dev, "update: err: %d, digcnt: %d\n", err, ctx->digcnt);
return err;
}
static int omap_sham_final_req(struct omap_sham_dev *dd)
{
struct ahash_request *req = dd->req;
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
int err = 0, use_dma = 1;
if (ctx->bufcnt <= 64)
use_dma = 0;
if (use_dma)
err = omap_sham_xmit_dma_map(dd, ctx, ctx->bufcnt, 1);
else
err = omap_sham_xmit_cpu(dd, ctx->buffer, ctx->bufcnt, 1);
ctx->bufcnt = 0;
dev_dbg(dd->dev, "final_req: err: %d\n", err);
return err;
}
static int omap_sham_finish_hmac(struct ahash_request *req)
{
struct omap_sham_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
struct omap_sham_hmac_ctx *bctx = tctx->base;
int bs = crypto_shash_blocksize(bctx->shash);
int ds = crypto_shash_digestsize(bctx->shash);
struct {
struct shash_desc shash;
char ctx[crypto_shash_descsize(bctx->shash)];
} desc;
desc.shash.tfm = bctx->shash;
desc.shash.flags = 0;
return crypto_shash_init(&desc.shash) ?:
crypto_shash_update(&desc.shash, bctx->opad, bs) ?:
crypto_shash_finup(&desc.shash, req->result, ds, req->result);
}
static int omap_sham_finish(struct ahash_request *req)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
struct omap_sham_dev *dd = ctx->dd;
int err = 0;
if (ctx->digcnt) {
omap_sham_copy_ready_hash(req);
if (ctx->flags & BIT(FLAGS_HMAC))
err = omap_sham_finish_hmac(req);
}
dev_dbg(dd->dev, "digcnt: %d, bufcnt: %d\n", ctx->digcnt, ctx->bufcnt);
return err;
}
static void omap_sham_finish_req(struct ahash_request *req, int err)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
struct omap_sham_dev *dd = ctx->dd;
if (!err) {
omap_sham_copy_hash(req, 1);
if (test_bit(FLAGS_FINAL, &dd->flags))
err = omap_sham_finish(req);
} else {
ctx->flags |= BIT(FLAGS_ERROR);
}
dd->flags &= ~(BIT(FLAGS_BUSY) | BIT(FLAGS_FINAL) | BIT(FLAGS_CPU) |
BIT(FLAGS_DMA_READY) | BIT(FLAGS_OUTPUT_READY));
clk_disable(dd->iclk);
if (req->base.complete)
req->base.complete(&req->base, err);
tasklet_schedule(&dd->done_task);
}
static int omap_sham_handle_queue(struct omap_sham_dev *dd,
struct ahash_request *req)
{
struct crypto_async_request *async_req, *backlog;
struct omap_sham_reqctx *ctx;
unsigned long flags;
int err = 0, ret = 0;
spin_lock_irqsave(&dd->lock, flags);
if (req)
ret = ahash_enqueue_request(&dd->queue, req);
if (test_bit(FLAGS_BUSY, &dd->flags)) {
spin_unlock_irqrestore(&dd->lock, flags);
return ret;
}
backlog = crypto_get_backlog(&dd->queue);
async_req = crypto_dequeue_request(&dd->queue);
if (async_req)
set_bit(FLAGS_BUSY, &dd->flags);
spin_unlock_irqrestore(&dd->lock, flags);
if (!async_req)
return ret;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ahash_request_cast(async_req);
dd->req = req;
ctx = ahash_request_ctx(req);
dev_dbg(dd->dev, "handling new req, op: %lu, nbytes: %d\n",
ctx->op, req->nbytes);
err = omap_sham_hw_init(dd);
if (err)
goto err1;
omap_set_dma_dest_params(dd->dma_lch, 0,
OMAP_DMA_AMODE_CONSTANT,
dd->phys_base + SHA_REG_DIN(0), 0, 16);
omap_set_dma_dest_burst_mode(dd->dma_lch,
OMAP_DMA_DATA_BURST_16);
omap_set_dma_src_burst_mode(dd->dma_lch,
OMAP_DMA_DATA_BURST_4);
if (ctx->digcnt)
omap_sham_copy_hash(req, 0);
if (ctx->op == OP_UPDATE) {
err = omap_sham_update_req(dd);
if (err != -EINPROGRESS && (ctx->flags & BIT(FLAGS_FINUP)))
err = omap_sham_final_req(dd);
} else if (ctx->op == OP_FINAL) {
err = omap_sham_final_req(dd);
}
err1:
if (err != -EINPROGRESS)
omap_sham_finish_req(req, err);
dev_dbg(dd->dev, "exit, err: %d\n", err);
return ret;
}
static int omap_sham_enqueue(struct ahash_request *req, unsigned int op)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
struct omap_sham_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
struct omap_sham_dev *dd = tctx->dd;
ctx->op = op;
return omap_sham_handle_queue(dd, req);
}
static int omap_sham_update(struct ahash_request *req)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
if (!req->nbytes)
return 0;
ctx->total = req->nbytes;
ctx->sg = req->src;
ctx->offset = 0;
if (ctx->flags & BIT(FLAGS_FINUP)) {
if ((ctx->digcnt + ctx->bufcnt + ctx->total) < 9) {
omap_sham_append_sg(ctx);
return 0;
} else if (ctx->bufcnt + ctx->total <= SHA1_MD5_BLOCK_SIZE) {
ctx->flags |= BIT(FLAGS_CPU);
}
} else if (ctx->bufcnt + ctx->total < ctx->buflen) {
omap_sham_append_sg(ctx);
return 0;
}
return omap_sham_enqueue(req, OP_UPDATE);
}
static int omap_sham_shash_digest(struct crypto_shash *shash, u32 flags,
const u8 *data, unsigned int len, u8 *out)
{
struct {
struct shash_desc shash;
char ctx[crypto_shash_descsize(shash)];
} desc;
desc.shash.tfm = shash;
desc.shash.flags = flags & CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_shash_digest(&desc.shash, data, len, out);
}
static int omap_sham_final_shash(struct ahash_request *req)
{
struct omap_sham_ctx *tctx = crypto_tfm_ctx(req->base.tfm);
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
return omap_sham_shash_digest(tctx->fallback, req->base.flags,
ctx->buffer, ctx->bufcnt, req->result);
}
static int omap_sham_final(struct ahash_request *req)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
ctx->flags |= BIT(FLAGS_FINUP);
if (ctx->flags & BIT(FLAGS_ERROR))
return 0;
if ((ctx->digcnt + ctx->bufcnt) < 9)
return omap_sham_final_shash(req);
else if (ctx->bufcnt)
return omap_sham_enqueue(req, OP_FINAL);
return omap_sham_finish(req);
}
static int omap_sham_finup(struct ahash_request *req)
{
struct omap_sham_reqctx *ctx = ahash_request_ctx(req);
int err1, err2;
ctx->flags |= BIT(FLAGS_FINUP);
err1 = omap_sham_update(req);
if (err1 == -EINPROGRESS || err1 == -EBUSY)
return err1;
err2 = omap_sham_final(req);
return err1 ?: err2;
}
static int omap_sham_digest(struct ahash_request *req)
{
return omap_sham_init(req) ?: omap_sham_finup(req);
}
static int omap_sham_setkey(struct crypto_ahash *tfm, const u8 *key,
unsigned int keylen)
{
struct omap_sham_ctx *tctx = crypto_ahash_ctx(tfm);
struct omap_sham_hmac_ctx *bctx = tctx->base;
int bs = crypto_shash_blocksize(bctx->shash);
int ds = crypto_shash_digestsize(bctx->shash);
int err, i;
err = crypto_shash_setkey(tctx->fallback, key, keylen);
if (err)
return err;
if (keylen > bs) {
err = omap_sham_shash_digest(bctx->shash,
crypto_shash_get_flags(bctx->shash),
key, keylen, bctx->ipad);
if (err)
return err;
keylen = ds;
} else {
memcpy(bctx->ipad, key, keylen);
}
memset(bctx->ipad + keylen, 0, bs - keylen);
memcpy(bctx->opad, bctx->ipad, bs);
for (i = 0; i < bs; i++) {
bctx->ipad[i] ^= 0x36;
bctx->opad[i] ^= 0x5c;
}
return err;
}
static int omap_sham_cra_init_alg(struct crypto_tfm *tfm, const char *alg_base)
{
struct omap_sham_ctx *tctx = crypto_tfm_ctx(tfm);
const char *alg_name = crypto_tfm_alg_name(tfm);
tctx->fallback = crypto_alloc_shash(alg_name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(tctx->fallback)) {
pr_err("omap-sham: fallback driver '%s' "
"could not be loaded.\n", alg_name);
return PTR_ERR(tctx->fallback);
}
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct omap_sham_reqctx) + BUFLEN);
if (alg_base) {
struct omap_sham_hmac_ctx *bctx = tctx->base;
tctx->flags |= BIT(FLAGS_HMAC);
bctx->shash = crypto_alloc_shash(alg_base, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(bctx->shash)) {
pr_err("omap-sham: base driver '%s' "
"could not be loaded.\n", alg_base);
crypto_free_shash(tctx->fallback);
return PTR_ERR(bctx->shash);
}
}
return 0;
}
static int omap_sham_cra_init(struct crypto_tfm *tfm)
{
return omap_sham_cra_init_alg(tfm, NULL);
}
static int omap_sham_cra_sha1_init(struct crypto_tfm *tfm)
{
return omap_sham_cra_init_alg(tfm, "sha1");
}
static int omap_sham_cra_md5_init(struct crypto_tfm *tfm)
{
return omap_sham_cra_init_alg(tfm, "md5");
}
static void omap_sham_cra_exit(struct crypto_tfm *tfm)
{
struct omap_sham_ctx *tctx = crypto_tfm_ctx(tfm);
crypto_free_shash(tctx->fallback);
tctx->fallback = NULL;
if (tctx->flags & BIT(FLAGS_HMAC)) {
struct omap_sham_hmac_ctx *bctx = tctx->base;
crypto_free_shash(bctx->shash);
}
}
static void omap_sham_done_task(unsigned long data)
{
struct omap_sham_dev *dd = (struct omap_sham_dev *)data;
int err = 0;
if (!test_bit(FLAGS_BUSY, &dd->flags)) {
omap_sham_handle_queue(dd, NULL);
return;
}
if (test_bit(FLAGS_CPU, &dd->flags)) {
if (test_and_clear_bit(FLAGS_OUTPUT_READY, &dd->flags))
goto finish;
} else if (test_bit(FLAGS_DMA_READY, &dd->flags)) {
if (test_and_clear_bit(FLAGS_DMA_ACTIVE, &dd->flags)) {
omap_sham_update_dma_stop(dd);
if (dd->err) {
err = dd->err;
goto finish;
}
}
if (test_and_clear_bit(FLAGS_OUTPUT_READY, &dd->flags)) {
clear_bit(FLAGS_DMA_READY, &dd->flags);
err = omap_sham_update_dma_start(dd);
if (err != -EINPROGRESS)
goto finish;
}
}
return;
finish:
dev_dbg(dd->dev, "update done: err: %d\n", err);
omap_sham_finish_req(dd->req, err);
}
static irqreturn_t omap_sham_irq(int irq, void *dev_id)
{
struct omap_sham_dev *dd = dev_id;
if (unlikely(test_bit(FLAGS_FINAL, &dd->flags)))
omap_sham_write_mask(dd, SHA_REG_CTRL, 0, SHA_REG_CTRL_LENGTH);
omap_sham_write_mask(dd, SHA_REG_CTRL, SHA_REG_CTRL_OUTPUT_READY,
SHA_REG_CTRL_OUTPUT_READY);
omap_sham_read(dd, SHA_REG_CTRL);
if (!test_bit(FLAGS_BUSY, &dd->flags)) {
dev_warn(dd->dev, "Interrupt when no active requests.\n");
return IRQ_HANDLED;
}
set_bit(FLAGS_OUTPUT_READY, &dd->flags);
tasklet_schedule(&dd->done_task);
return IRQ_HANDLED;
}
static void omap_sham_dma_callback(int lch, u16 ch_status, void *data)
{
struct omap_sham_dev *dd = data;
if (ch_status != OMAP_DMA_BLOCK_IRQ) {
pr_err("omap-sham DMA error status: 0x%hx\n", ch_status);
dd->err = -EIO;
clear_bit(FLAGS_INIT, &dd->flags);
}
set_bit(FLAGS_DMA_READY, &dd->flags);
tasklet_schedule(&dd->done_task);
}
static int omap_sham_dma_init(struct omap_sham_dev *dd)
{
int err;
dd->dma_lch = -1;
err = omap_request_dma(dd->dma, dev_name(dd->dev),
omap_sham_dma_callback, dd, &dd->dma_lch);
if (err) {
dev_err(dd->dev, "Unable to request DMA channel\n");
return err;
}
return 0;
}
static void omap_sham_dma_cleanup(struct omap_sham_dev *dd)
{
if (dd->dma_lch >= 0) {
omap_free_dma(dd->dma_lch);
dd->dma_lch = -1;
}
}
static int omap_sham_probe(struct platform_device *pdev)
{
struct omap_sham_dev *dd;
struct device *dev = &pdev->dev;
struct resource *res;
int err, i, j;
dd = kzalloc(sizeof(struct omap_sham_dev), GFP_KERNEL);
if (dd == NULL) {
dev_err(dev, "unable to alloc data struct.\n");
err = -ENOMEM;
goto data_err;
}
dd->dev = dev;
platform_set_drvdata(pdev, dd);
INIT_LIST_HEAD(&dd->list);
spin_lock_init(&dd->lock);
tasklet_init(&dd->done_task, omap_sham_done_task, (unsigned long)dd);
crypto_init_queue(&dd->queue, OMAP_SHAM_QUEUE_LENGTH);
dd->irq = -1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "no MEM resource info\n");
err = -ENODEV;
goto res_err;
}
dd->phys_base = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!res) {
dev_err(dev, "no DMA resource info\n");
err = -ENODEV;
goto res_err;
}
dd->dma = res->start;
dd->irq = platform_get_irq(pdev, 0);
if (dd->irq < 0) {
dev_err(dev, "no IRQ resource info\n");
err = dd->irq;
goto res_err;
}
err = request_irq(dd->irq, omap_sham_irq,
IRQF_TRIGGER_LOW, dev_name(dev), dd);
if (err) {
dev_err(dev, "unable to request irq.\n");
goto res_err;
}
err = omap_sham_dma_init(dd);
if (err)
goto dma_err;
dd->iclk = clk_get(dev, "ick");
if (IS_ERR(dd->iclk)) {
dev_err(dev, "clock intialization failed.\n");
err = PTR_ERR(dd->iclk);
goto clk_err;
}
dd->io_base = ioremap(dd->phys_base, SZ_4K);
if (!dd->io_base) {
dev_err(dev, "can't ioremap\n");
err = -ENOMEM;
goto io_err;
}
clk_enable(dd->iclk);
dev_info(dev, "hw accel on OMAP rev %u.%u\n",
(omap_sham_read(dd, SHA_REG_REV) & SHA_REG_REV_MAJOR) >> 4,
omap_sham_read(dd, SHA_REG_REV) & SHA_REG_REV_MINOR);
clk_disable(dd->iclk);
spin_lock(&sham.lock);
list_add_tail(&dd->list, &sham.dev_list);
spin_unlock(&sham.lock);
for (i = 0; i < ARRAY_SIZE(algs); i++) {
err = crypto_register_ahash(&algs[i]);
if (err)
goto err_algs;
}
return 0;
err_algs:
for (j = 0; j < i; j++)
crypto_unregister_ahash(&algs[j]);
iounmap(dd->io_base);
io_err:
clk_put(dd->iclk);
clk_err:
omap_sham_dma_cleanup(dd);
dma_err:
if (dd->irq >= 0)
free_irq(dd->irq, dd);
res_err:
kfree(dd);
dd = NULL;
data_err:
dev_err(dev, "initialization failed.\n");
return err;
}
static int omap_sham_remove(struct platform_device *pdev)
{
static struct omap_sham_dev *dd;
int i;
dd = platform_get_drvdata(pdev);
if (!dd)
return -ENODEV;
spin_lock(&sham.lock);
list_del(&dd->list);
spin_unlock(&sham.lock);
for (i = 0; i < ARRAY_SIZE(algs); i++)
crypto_unregister_ahash(&algs[i]);
tasklet_kill(&dd->done_task);
iounmap(dd->io_base);
clk_put(dd->iclk);
omap_sham_dma_cleanup(dd);
if (dd->irq >= 0)
free_irq(dd->irq, dd);
kfree(dd);
dd = NULL;
return 0;
}
static int __init omap_sham_mod_init(void)
{
pr_info("loading %s driver\n", "omap-sham");
return platform_driver_register(&omap_sham_driver);
}
static void __exit omap_sham_mod_exit(void)
{
platform_driver_unregister(&omap_sham_driver);
}
