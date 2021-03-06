static inline u32 omap_aes_read(struct omap_aes_dev *dd, u32 offset)
{
return __raw_readl(dd->io_base + offset);
}
static inline void omap_aes_write(struct omap_aes_dev *dd, u32 offset,
u32 value)
{
__raw_writel(value, dd->io_base + offset);
}
static inline void omap_aes_write_mask(struct omap_aes_dev *dd, u32 offset,
u32 value, u32 mask)
{
u32 val;
val = omap_aes_read(dd, offset);
val &= ~mask;
val |= value;
omap_aes_write(dd, offset, val);
}
static void omap_aes_write_n(struct omap_aes_dev *dd, u32 offset,
u32 *value, int count)
{
for (; count--; value++, offset += 4)
omap_aes_write(dd, offset, *value);
}
static int omap_aes_hw_init(struct omap_aes_dev *dd)
{
int err;
if (!(dd->flags & FLAGS_INIT)) {
dd->flags |= FLAGS_INIT;
dd->err = 0;
}
err = pm_runtime_get_sync(dd->dev);
if (err < 0) {
dev_err(dd->dev, "failed to get sync: %d\n", err);
return err;
}
return 0;
}
static int omap_aes_write_ctrl(struct omap_aes_dev *dd)
{
unsigned int key32;
int i, err;
u32 val;
err = omap_aes_hw_init(dd);
if (err)
return err;
key32 = dd->ctx->keylen / sizeof(u32);
for (i = 0; i < key32; i++) {
omap_aes_write(dd, AES_REG_KEY(dd, i),
__le32_to_cpu(dd->ctx->key[i]));
}
if ((dd->flags & (FLAGS_CBC | FLAGS_CTR)) && dd->req->info)
omap_aes_write_n(dd, AES_REG_IV(dd, 0), dd->req->info, 4);
val = FLD_VAL(((dd->ctx->keylen >> 3) - 1), 4, 3);
if (dd->flags & FLAGS_CBC)
val |= AES_REG_CTRL_CBC;
if (dd->flags & FLAGS_CTR)
val |= AES_REG_CTRL_CTR | AES_REG_CTRL_CTR_WIDTH_128;
if (dd->flags & FLAGS_ENCRYPT)
val |= AES_REG_CTRL_DIRECTION;
omap_aes_write_mask(dd, AES_REG_CTRL(dd), val, AES_REG_CTRL_MASK);
return 0;
}
static void omap_aes_dma_trigger_omap2(struct omap_aes_dev *dd, int length)
{
u32 mask, val;
val = dd->pdata->dma_start;
if (dd->dma_lch_out != NULL)
val |= dd->pdata->dma_enable_out;
if (dd->dma_lch_in != NULL)
val |= dd->pdata->dma_enable_in;
mask = dd->pdata->dma_enable_out | dd->pdata->dma_enable_in |
dd->pdata->dma_start;
omap_aes_write_mask(dd, AES_REG_MASK(dd), val, mask);
}
static void omap_aes_dma_trigger_omap4(struct omap_aes_dev *dd, int length)
{
omap_aes_write(dd, AES_REG_LENGTH_N(0), length);
omap_aes_write(dd, AES_REG_LENGTH_N(1), 0);
omap_aes_dma_trigger_omap2(dd, length);
}
static void omap_aes_dma_stop(struct omap_aes_dev *dd)
{
u32 mask;
mask = dd->pdata->dma_enable_out | dd->pdata->dma_enable_in |
dd->pdata->dma_start;
omap_aes_write_mask(dd, AES_REG_MASK(dd), 0, mask);
}
static struct omap_aes_dev *omap_aes_find_dev(struct omap_aes_ctx *ctx)
{
struct omap_aes_dev *dd;
spin_lock_bh(&list_lock);
dd = list_first_entry(&dev_list, struct omap_aes_dev, list);
list_move_tail(&dd->list, &dev_list);
ctx->dd = dd;
spin_unlock_bh(&list_lock);
return dd;
}
static void omap_aes_dma_out_callback(void *data)
{
struct omap_aes_dev *dd = data;
tasklet_schedule(&dd->done_task);
}
static int omap_aes_dma_init(struct omap_aes_dev *dd)
{
int err;
dd->dma_lch_out = NULL;
dd->dma_lch_in = NULL;
dd->dma_lch_in = dma_request_chan(dd->dev, "rx");
if (IS_ERR(dd->dma_lch_in)) {
dev_err(dd->dev, "Unable to request in DMA channel\n");
return PTR_ERR(dd->dma_lch_in);
}
dd->dma_lch_out = dma_request_chan(dd->dev, "tx");
if (IS_ERR(dd->dma_lch_out)) {
dev_err(dd->dev, "Unable to request out DMA channel\n");
err = PTR_ERR(dd->dma_lch_out);
goto err_dma_out;
}
return 0;
err_dma_out:
dma_release_channel(dd->dma_lch_in);
return err;
}
static void omap_aes_dma_cleanup(struct omap_aes_dev *dd)
{
if (dd->pio_only)
return;
dma_release_channel(dd->dma_lch_out);
dma_release_channel(dd->dma_lch_in);
}
static void sg_copy_buf(void *buf, struct scatterlist *sg,
unsigned int start, unsigned int nbytes, int out)
{
struct scatter_walk walk;
if (!nbytes)
return;
scatterwalk_start(&walk, sg);
scatterwalk_advance(&walk, start);
scatterwalk_copychunks(buf, &walk, nbytes, out);
scatterwalk_done(&walk, out, 0);
}
static int omap_aes_crypt_dma(struct crypto_tfm *tfm,
struct scatterlist *in_sg, struct scatterlist *out_sg,
int in_sg_len, int out_sg_len)
{
struct omap_aes_ctx *ctx = crypto_tfm_ctx(tfm);
struct omap_aes_dev *dd = ctx->dd;
struct dma_async_tx_descriptor *tx_in, *tx_out;
struct dma_slave_config cfg;
int ret;
if (dd->pio_only) {
scatterwalk_start(&dd->in_walk, dd->in_sg);
scatterwalk_start(&dd->out_walk, dd->out_sg);
omap_aes_write(dd, AES_REG_IRQ_ENABLE(dd), 0x2);
return 0;
}
dma_sync_sg_for_device(dd->dev, dd->in_sg, in_sg_len, DMA_TO_DEVICE);
memset(&cfg, 0, sizeof(cfg));
cfg.src_addr = dd->phys_base + AES_REG_DATA_N(dd, 0);
cfg.dst_addr = dd->phys_base + AES_REG_DATA_N(dd, 0);
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.src_maxburst = DST_MAXBURST;
cfg.dst_maxburst = DST_MAXBURST;
ret = dmaengine_slave_config(dd->dma_lch_in, &cfg);
if (ret) {
dev_err(dd->dev, "can't configure IN dmaengine slave: %d\n",
ret);
return ret;
}
tx_in = dmaengine_prep_slave_sg(dd->dma_lch_in, in_sg, in_sg_len,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!tx_in) {
dev_err(dd->dev, "IN prep_slave_sg() failed\n");
return -EINVAL;
}
tx_in->callback_param = dd;
ret = dmaengine_slave_config(dd->dma_lch_out, &cfg);
if (ret) {
dev_err(dd->dev, "can't configure OUT dmaengine slave: %d\n",
ret);
return ret;
}
tx_out = dmaengine_prep_slave_sg(dd->dma_lch_out, out_sg, out_sg_len,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!tx_out) {
dev_err(dd->dev, "OUT prep_slave_sg() failed\n");
return -EINVAL;
}
tx_out->callback = omap_aes_dma_out_callback;
tx_out->callback_param = dd;
dmaengine_submit(tx_in);
dmaengine_submit(tx_out);
dma_async_issue_pending(dd->dma_lch_in);
dma_async_issue_pending(dd->dma_lch_out);
dd->pdata->trigger(dd, dd->total);
return 0;
}
static int omap_aes_crypt_dma_start(struct omap_aes_dev *dd)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(
crypto_ablkcipher_reqtfm(dd->req));
int err;
pr_debug("total: %d\n", dd->total);
if (!dd->pio_only) {
err = dma_map_sg(dd->dev, dd->in_sg, dd->in_sg_len,
DMA_TO_DEVICE);
if (!err) {
dev_err(dd->dev, "dma_map_sg() error\n");
return -EINVAL;
}
err = dma_map_sg(dd->dev, dd->out_sg, dd->out_sg_len,
DMA_FROM_DEVICE);
if (!err) {
dev_err(dd->dev, "dma_map_sg() error\n");
return -EINVAL;
}
}
err = omap_aes_crypt_dma(tfm, dd->in_sg, dd->out_sg, dd->in_sg_len,
dd->out_sg_len);
if (err && !dd->pio_only) {
dma_unmap_sg(dd->dev, dd->in_sg, dd->in_sg_len, DMA_TO_DEVICE);
dma_unmap_sg(dd->dev, dd->out_sg, dd->out_sg_len,
DMA_FROM_DEVICE);
}
return err;
}
static void omap_aes_finish_req(struct omap_aes_dev *dd, int err)
{
struct ablkcipher_request *req = dd->req;
pr_debug("err: %d\n", err);
crypto_finalize_cipher_request(dd->engine, req, err);
pm_runtime_mark_last_busy(dd->dev);
pm_runtime_put_autosuspend(dd->dev);
}
static int omap_aes_crypt_dma_stop(struct omap_aes_dev *dd)
{
pr_debug("total: %d\n", dd->total);
omap_aes_dma_stop(dd);
return 0;
}
static int omap_aes_check_aligned(struct scatterlist *sg, int total)
{
int len = 0;
if (!IS_ALIGNED(total, AES_BLOCK_SIZE))
return -EINVAL;
while (sg) {
if (!IS_ALIGNED(sg->offset, 4))
return -1;
if (!IS_ALIGNED(sg->length, AES_BLOCK_SIZE))
return -1;
len += sg->length;
sg = sg_next(sg);
}
if (len != total)
return -1;
return 0;
}
static int omap_aes_copy_sgs(struct omap_aes_dev *dd)
{
void *buf_in, *buf_out;
int pages, total;
total = ALIGN(dd->total, AES_BLOCK_SIZE);
pages = get_order(total);
buf_in = (void *)__get_free_pages(GFP_ATOMIC, pages);
buf_out = (void *)__get_free_pages(GFP_ATOMIC, pages);
if (!buf_in || !buf_out) {
pr_err("Couldn't allocated pages for unaligned cases.\n");
return -1;
}
dd->orig_out = dd->out_sg;
sg_copy_buf(buf_in, dd->in_sg, 0, dd->total, 0);
sg_init_table(&dd->in_sgl, 1);
sg_set_buf(&dd->in_sgl, buf_in, total);
dd->in_sg = &dd->in_sgl;
dd->in_sg_len = 1;
sg_init_table(&dd->out_sgl, 1);
sg_set_buf(&dd->out_sgl, buf_out, total);
dd->out_sg = &dd->out_sgl;
dd->out_sg_len = 1;
return 0;
}
static int omap_aes_handle_queue(struct omap_aes_dev *dd,
struct ablkcipher_request *req)
{
if (req)
return crypto_transfer_cipher_request_to_engine(dd->engine, req);
return 0;
}
static int omap_aes_prepare_req(struct crypto_engine *engine,
struct ablkcipher_request *req)
{
struct omap_aes_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
struct omap_aes_dev *dd = ctx->dd;
struct omap_aes_reqctx *rctx;
if (!dd)
return -ENODEV;
dd->req = req;
dd->total = req->nbytes;
dd->total_save = req->nbytes;
dd->in_sg = req->src;
dd->out_sg = req->dst;
dd->in_sg_len = sg_nents_for_len(dd->in_sg, dd->total);
if (dd->in_sg_len < 0)
return dd->in_sg_len;
dd->out_sg_len = sg_nents_for_len(dd->out_sg, dd->total);
if (dd->out_sg_len < 0)
return dd->out_sg_len;
if (omap_aes_check_aligned(dd->in_sg, dd->total) ||
omap_aes_check_aligned(dd->out_sg, dd->total)) {
if (omap_aes_copy_sgs(dd))
pr_err("Failed to copy SGs for unaligned cases\n");
dd->sgs_copied = 1;
} else {
dd->sgs_copied = 0;
}
rctx = ablkcipher_request_ctx(req);
ctx = crypto_ablkcipher_ctx(crypto_ablkcipher_reqtfm(req));
rctx->mode &= FLAGS_MODE_MASK;
dd->flags = (dd->flags & ~FLAGS_MODE_MASK) | rctx->mode;
dd->ctx = ctx;
ctx->dd = dd;
return omap_aes_write_ctrl(dd);
}
static int omap_aes_crypt_req(struct crypto_engine *engine,
struct ablkcipher_request *req)
{
struct omap_aes_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
struct omap_aes_dev *dd = ctx->dd;
if (!dd)
return -ENODEV;
return omap_aes_crypt_dma_start(dd);
}
static void omap_aes_done_task(unsigned long data)
{
struct omap_aes_dev *dd = (struct omap_aes_dev *)data;
void *buf_in, *buf_out;
int pages, len;
pr_debug("enter done_task\n");
if (!dd->pio_only) {
dma_sync_sg_for_device(dd->dev, dd->out_sg, dd->out_sg_len,
DMA_FROM_DEVICE);
dma_unmap_sg(dd->dev, dd->in_sg, dd->in_sg_len, DMA_TO_DEVICE);
dma_unmap_sg(dd->dev, dd->out_sg, dd->out_sg_len,
DMA_FROM_DEVICE);
omap_aes_crypt_dma_stop(dd);
}
if (dd->sgs_copied) {
buf_in = sg_virt(&dd->in_sgl);
buf_out = sg_virt(&dd->out_sgl);
sg_copy_buf(buf_out, dd->orig_out, 0, dd->total_save, 1);
len = ALIGN(dd->total_save, AES_BLOCK_SIZE);
pages = get_order(len);
free_pages((unsigned long)buf_in, pages);
free_pages((unsigned long)buf_out, pages);
}
omap_aes_finish_req(dd, 0);
pr_debug("exit\n");
}
static int omap_aes_crypt(struct ablkcipher_request *req, unsigned long mode)
{
struct omap_aes_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
struct omap_aes_reqctx *rctx = ablkcipher_request_ctx(req);
struct omap_aes_dev *dd;
int ret;
pr_debug("nbytes: %d, enc: %d, cbc: %d\n", req->nbytes,
!!(mode & FLAGS_ENCRYPT),
!!(mode & FLAGS_CBC));
if (req->nbytes < 200) {
SKCIPHER_REQUEST_ON_STACK(subreq, ctx->fallback);
skcipher_request_set_tfm(subreq, ctx->fallback);
skcipher_request_set_callback(subreq, req->base.flags, NULL,
NULL);
skcipher_request_set_crypt(subreq, req->src, req->dst,
req->nbytes, req->info);
if (mode & FLAGS_ENCRYPT)
ret = crypto_skcipher_encrypt(subreq);
else
ret = crypto_skcipher_decrypt(subreq);
skcipher_request_zero(subreq);
return ret;
}
dd = omap_aes_find_dev(ctx);
if (!dd)
return -ENODEV;
rctx->mode = mode;
return omap_aes_handle_queue(dd, req);
}
static int omap_aes_setkey(struct crypto_ablkcipher *tfm, const u8 *key,
unsigned int keylen)
{
struct omap_aes_ctx *ctx = crypto_ablkcipher_ctx(tfm);
int ret;
if (keylen != AES_KEYSIZE_128 && keylen != AES_KEYSIZE_192 &&
keylen != AES_KEYSIZE_256)
return -EINVAL;
pr_debug("enter, keylen: %d\n", keylen);
memcpy(ctx->key, key, keylen);
ctx->keylen = keylen;
crypto_skcipher_clear_flags(ctx->fallback, CRYPTO_TFM_REQ_MASK);
crypto_skcipher_set_flags(ctx->fallback, tfm->base.crt_flags &
CRYPTO_TFM_REQ_MASK);
ret = crypto_skcipher_setkey(ctx->fallback, key, keylen);
if (!ret)
return 0;
return 0;
}
static int omap_aes_ecb_encrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, FLAGS_ENCRYPT);
}
static int omap_aes_ecb_decrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, 0);
}
static int omap_aes_cbc_encrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, FLAGS_ENCRYPT | FLAGS_CBC);
}
static int omap_aes_cbc_decrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, FLAGS_CBC);
}
static int omap_aes_ctr_encrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, FLAGS_ENCRYPT | FLAGS_CTR);
}
static int omap_aes_ctr_decrypt(struct ablkcipher_request *req)
{
return omap_aes_crypt(req, FLAGS_CTR);
}
static int omap_aes_cra_init(struct crypto_tfm *tfm)
{
const char *name = crypto_tfm_alg_name(tfm);
const u32 flags = CRYPTO_ALG_ASYNC | CRYPTO_ALG_NEED_FALLBACK;
struct omap_aes_ctx *ctx = crypto_tfm_ctx(tfm);
struct crypto_skcipher *blk;
blk = crypto_alloc_skcipher(name, 0, flags);
if (IS_ERR(blk))
return PTR_ERR(blk);
ctx->fallback = blk;
tfm->crt_ablkcipher.reqsize = sizeof(struct omap_aes_reqctx);
return 0;
}
static void omap_aes_cra_exit(struct crypto_tfm *tfm)
{
struct omap_aes_ctx *ctx = crypto_tfm_ctx(tfm);
if (ctx->fallback)
crypto_free_skcipher(ctx->fallback);
ctx->fallback = NULL;
}
static irqreturn_t omap_aes_irq(int irq, void *dev_id)
{
struct omap_aes_dev *dd = dev_id;
u32 status, i;
u32 *src, *dst;
status = omap_aes_read(dd, AES_REG_IRQ_STATUS(dd));
if (status & AES_REG_IRQ_DATA_IN) {
omap_aes_write(dd, AES_REG_IRQ_ENABLE(dd), 0x0);
BUG_ON(!dd->in_sg);
BUG_ON(_calc_walked(in) > dd->in_sg->length);
src = sg_virt(dd->in_sg) + _calc_walked(in);
for (i = 0; i < AES_BLOCK_WORDS; i++) {
omap_aes_write(dd, AES_REG_DATA_N(dd, i), *src);
scatterwalk_advance(&dd->in_walk, 4);
if (dd->in_sg->length == _calc_walked(in)) {
dd->in_sg = sg_next(dd->in_sg);
if (dd->in_sg) {
scatterwalk_start(&dd->in_walk,
dd->in_sg);
src = sg_virt(dd->in_sg) +
_calc_walked(in);
}
} else {
src++;
}
}
status &= ~AES_REG_IRQ_DATA_IN;
omap_aes_write(dd, AES_REG_IRQ_STATUS(dd), status);
omap_aes_write(dd, AES_REG_IRQ_ENABLE(dd), 0x4);
} else if (status & AES_REG_IRQ_DATA_OUT) {
omap_aes_write(dd, AES_REG_IRQ_ENABLE(dd), 0x0);
BUG_ON(!dd->out_sg);
BUG_ON(_calc_walked(out) > dd->out_sg->length);
dst = sg_virt(dd->out_sg) + _calc_walked(out);
for (i = 0; i < AES_BLOCK_WORDS; i++) {
*dst = omap_aes_read(dd, AES_REG_DATA_N(dd, i));
scatterwalk_advance(&dd->out_walk, 4);
if (dd->out_sg->length == _calc_walked(out)) {
dd->out_sg = sg_next(dd->out_sg);
if (dd->out_sg) {
scatterwalk_start(&dd->out_walk,
dd->out_sg);
dst = sg_virt(dd->out_sg) +
_calc_walked(out);
}
} else {
dst++;
}
}
dd->total -= min_t(size_t, AES_BLOCK_SIZE, dd->total);
status &= ~AES_REG_IRQ_DATA_OUT;
omap_aes_write(dd, AES_REG_IRQ_STATUS(dd), status);
if (!dd->total)
tasklet_schedule(&dd->done_task);
else
omap_aes_write(dd, AES_REG_IRQ_ENABLE(dd), 0x2);
}
return IRQ_HANDLED;
}
static int omap_aes_get_res_of(struct omap_aes_dev *dd,
struct device *dev, struct resource *res)
{
struct device_node *node = dev->of_node;
const struct of_device_id *match;
int err = 0;
match = of_match_device(of_match_ptr(omap_aes_of_match), dev);
if (!match) {
dev_err(dev, "no compatible OF match\n");
err = -EINVAL;
goto err;
}
err = of_address_to_resource(node, 0, res);
if (err < 0) {
dev_err(dev, "can't translate OF node address\n");
err = -EINVAL;
goto err;
}
dd->pdata = match->data;
err:
return err;
}
static int omap_aes_get_res_of(struct omap_aes_dev *dd,
struct device *dev, struct resource *res)
{
return -EINVAL;
}
static int omap_aes_get_res_pdev(struct omap_aes_dev *dd,
struct platform_device *pdev, struct resource *res)
{
struct device *dev = &pdev->dev;
struct resource *r;
int err = 0;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(dev, "no MEM resource info\n");
err = -ENODEV;
goto err;
}
memcpy(res, r, sizeof(*res));
dd->pdata = &omap_aes_pdata_omap2;
err:
return err;
}
static int omap_aes_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct omap_aes_dev *dd;
struct crypto_alg *algp;
struct resource res;
int err = -ENOMEM, i, j, irq = -1;
u32 reg;
dd = devm_kzalloc(dev, sizeof(struct omap_aes_dev), GFP_KERNEL);
if (dd == NULL) {
dev_err(dev, "unable to alloc data struct.\n");
goto err_data;
}
dd->dev = dev;
platform_set_drvdata(pdev, dd);
err = (dev->of_node) ? omap_aes_get_res_of(dd, dev, &res) :
omap_aes_get_res_pdev(dd, pdev, &res);
if (err)
goto err_res;
dd->io_base = devm_ioremap_resource(dev, &res);
if (IS_ERR(dd->io_base)) {
err = PTR_ERR(dd->io_base);
goto err_res;
}
dd->phys_base = res.start;
pm_runtime_use_autosuspend(dev);
pm_runtime_set_autosuspend_delay(dev, DEFAULT_AUTOSUSPEND_DELAY);
pm_runtime_enable(dev);
err = pm_runtime_get_sync(dev);
if (err < 0) {
dev_err(dev, "%s: failed to get_sync(%d)\n",
__func__, err);
goto err_res;
}
omap_aes_dma_stop(dd);
reg = omap_aes_read(dd, AES_REG_REV(dd));
pm_runtime_put_sync(dev);
dev_info(dev, "OMAP AES hw accel rev: %u.%u\n",
(reg & dd->pdata->major_mask) >> dd->pdata->major_shift,
(reg & dd->pdata->minor_mask) >> dd->pdata->minor_shift);
tasklet_init(&dd->done_task, omap_aes_done_task, (unsigned long)dd);
err = omap_aes_dma_init(dd);
if (err == -EPROBE_DEFER) {
goto err_irq;
} else if (err && AES_REG_IRQ_STATUS(dd) && AES_REG_IRQ_ENABLE(dd)) {
dd->pio_only = 1;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "can't get IRQ resource\n");
goto err_irq;
}
err = devm_request_irq(dev, irq, omap_aes_irq, 0,
dev_name(dev), dd);
if (err) {
dev_err(dev, "Unable to grab omap-aes IRQ\n");
goto err_irq;
}
}
INIT_LIST_HEAD(&dd->list);
spin_lock(&list_lock);
list_add_tail(&dd->list, &dev_list);
spin_unlock(&list_lock);
dd->engine = crypto_engine_alloc_init(dev, 1);
if (!dd->engine) {
err = -ENOMEM;
goto err_engine;
}
dd->engine->prepare_cipher_request = omap_aes_prepare_req;
dd->engine->cipher_one_request = omap_aes_crypt_req;
err = crypto_engine_start(dd->engine);
if (err)
goto err_engine;
for (i = 0; i < dd->pdata->algs_info_size; i++) {
if (!dd->pdata->algs_info[i].registered) {
for (j = 0; j < dd->pdata->algs_info[i].size; j++) {
algp = &dd->pdata->algs_info[i].algs_list[j];
pr_debug("reg alg: %s\n", algp->cra_name);
INIT_LIST_HEAD(&algp->cra_list);
err = crypto_register_alg(algp);
if (err)
goto err_algs;
dd->pdata->algs_info[i].registered++;
}
}
}
return 0;
err_algs:
for (i = dd->pdata->algs_info_size - 1; i >= 0; i--)
for (j = dd->pdata->algs_info[i].registered - 1; j >= 0; j--)
crypto_unregister_alg(
&dd->pdata->algs_info[i].algs_list[j]);
err_engine:
if (dd->engine)
crypto_engine_exit(dd->engine);
omap_aes_dma_cleanup(dd);
err_irq:
tasklet_kill(&dd->done_task);
pm_runtime_disable(dev);
err_res:
dd = NULL;
err_data:
dev_err(dev, "initialization failed.\n");
return err;
}
static int omap_aes_remove(struct platform_device *pdev)
{
struct omap_aes_dev *dd = platform_get_drvdata(pdev);
int i, j;
if (!dd)
return -ENODEV;
spin_lock(&list_lock);
list_del(&dd->list);
spin_unlock(&list_lock);
for (i = dd->pdata->algs_info_size - 1; i >= 0; i--)
for (j = dd->pdata->algs_info[i].registered - 1; j >= 0; j--)
crypto_unregister_alg(
&dd->pdata->algs_info[i].algs_list[j]);
crypto_engine_exit(dd->engine);
tasklet_kill(&dd->done_task);
omap_aes_dma_cleanup(dd);
pm_runtime_disable(dd->dev);
dd = NULL;
return 0;
}
static int omap_aes_suspend(struct device *dev)
{
pm_runtime_put_sync(dev);
return 0;
}
static int omap_aes_resume(struct device *dev)
{
pm_runtime_get_sync(dev);
return 0;
}
