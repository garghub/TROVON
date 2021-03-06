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
if (!(dd->flags & FLAGS_INIT)) {
dd->flags |= FLAGS_INIT;
dd->err = 0;
}
return 0;
}
static int omap_aes_write_ctrl(struct omap_aes_dev *dd)
{
unsigned int key32;
int i, err;
u32 val, mask = 0;
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
if (dd->flags & FLAGS_CTR) {
val |= AES_REG_CTRL_CTR | AES_REG_CTRL_CTR_WIDTH_32;
mask = AES_REG_CTRL_CTR | AES_REG_CTRL_CTR_WIDTH_MASK;
}
if (dd->flags & FLAGS_ENCRYPT)
val |= AES_REG_CTRL_DIRECTION;
mask |= AES_REG_CTRL_CBC | AES_REG_CTRL_DIRECTION |
AES_REG_CTRL_KEY_SIZE;
omap_aes_write_mask(dd, AES_REG_CTRL(dd), val, mask);
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
struct omap_aes_dev *dd = NULL, *tmp;
spin_lock_bh(&list_lock);
if (!ctx->dd) {
list_for_each_entry(tmp, &dev_list, list) {
dd = tmp;
break;
}
ctx->dd = dd;
} else {
dd = ctx->dd;
}
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
int err = -ENOMEM;
dma_cap_mask_t mask;
dd->dma_lch_out = NULL;
dd->dma_lch_in = NULL;
dd->buf_in = (void *)__get_free_pages(GFP_KERNEL, OMAP_AES_CACHE_SIZE);
dd->buf_out = (void *)__get_free_pages(GFP_KERNEL, OMAP_AES_CACHE_SIZE);
dd->buflen = PAGE_SIZE << OMAP_AES_CACHE_SIZE;
dd->buflen &= ~(AES_BLOCK_SIZE - 1);
if (!dd->buf_in || !dd->buf_out) {
dev_err(dd->dev, "unable to alloc pages.\n");
goto err_alloc;
}
dd->dma_addr_in = dma_map_single(dd->dev, dd->buf_in, dd->buflen,
DMA_TO_DEVICE);
if (dma_mapping_error(dd->dev, dd->dma_addr_in)) {
dev_err(dd->dev, "dma %d bytes error\n", dd->buflen);
err = -EINVAL;
goto err_map_in;
}
dd->dma_addr_out = dma_map_single(dd->dev, dd->buf_out, dd->buflen,
DMA_FROM_DEVICE);
if (dma_mapping_error(dd->dev, dd->dma_addr_out)) {
dev_err(dd->dev, "dma %d bytes error\n", dd->buflen);
err = -EINVAL;
goto err_map_out;
}
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dd->dma_lch_in = dma_request_slave_channel_compat(mask,
omap_dma_filter_fn,
&dd->dma_in,
dd->dev, "rx");
if (!dd->dma_lch_in) {
dev_err(dd->dev, "Unable to request in DMA channel\n");
goto err_dma_in;
}
dd->dma_lch_out = dma_request_slave_channel_compat(mask,
omap_dma_filter_fn,
&dd->dma_out,
dd->dev, "tx");
if (!dd->dma_lch_out) {
dev_err(dd->dev, "Unable to request out DMA channel\n");
goto err_dma_out;
}
return 0;
err_dma_out:
dma_release_channel(dd->dma_lch_in);
err_dma_in:
dma_unmap_single(dd->dev, dd->dma_addr_out, dd->buflen,
DMA_FROM_DEVICE);
err_map_out:
dma_unmap_single(dd->dev, dd->dma_addr_in, dd->buflen, DMA_TO_DEVICE);
err_map_in:
free_pages((unsigned long)dd->buf_out, OMAP_AES_CACHE_SIZE);
free_pages((unsigned long)dd->buf_in, OMAP_AES_CACHE_SIZE);
err_alloc:
if (err)
pr_err("error: %d\n", err);
return err;
}
static void omap_aes_dma_cleanup(struct omap_aes_dev *dd)
{
dma_release_channel(dd->dma_lch_out);
dma_release_channel(dd->dma_lch_in);
dma_unmap_single(dd->dev, dd->dma_addr_out, dd->buflen,
DMA_FROM_DEVICE);
dma_unmap_single(dd->dev, dd->dma_addr_in, dd->buflen, DMA_TO_DEVICE);
free_pages((unsigned long)dd->buf_out, OMAP_AES_CACHE_SIZE);
free_pages((unsigned long)dd->buf_in, OMAP_AES_CACHE_SIZE);
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
static int sg_copy(struct scatterlist **sg, size_t *offset, void *buf,
size_t buflen, size_t total, int out)
{
unsigned int count, off = 0;
while (buflen && total) {
count = min((*sg)->length - *offset, total);
count = min(count, buflen);
if (!count)
return off;
sg_copy_buf(buf + off, *sg, *offset, count, out);
off += count;
buflen -= count;
*offset += count;
total -= count;
if (*offset == (*sg)->length) {
*sg = sg_next(*sg);
if (*sg)
*offset = 0;
else
total = 0;
}
}
return off;
}
static int omap_aes_crypt_dma(struct crypto_tfm *tfm,
struct scatterlist *in_sg, struct scatterlist *out_sg)
{
struct omap_aes_ctx *ctx = crypto_tfm_ctx(tfm);
struct omap_aes_dev *dd = ctx->dd;
struct dma_async_tx_descriptor *tx_in, *tx_out;
struct dma_slave_config cfg;
dma_addr_t dma_addr_in = sg_dma_address(in_sg);
int ret, length = sg_dma_len(in_sg);
pr_debug("len: %d\n", length);
dd->dma_size = length;
if (!(dd->flags & FLAGS_FAST))
dma_sync_single_for_device(dd->dev, dma_addr_in, length,
DMA_TO_DEVICE);
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
tx_in = dmaengine_prep_slave_sg(dd->dma_lch_in, in_sg, 1,
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
tx_out = dmaengine_prep_slave_sg(dd->dma_lch_out, out_sg, 1,
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
dd->pdata->trigger(dd, length);
return 0;
}
static int omap_aes_crypt_dma_start(struct omap_aes_dev *dd)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(
crypto_ablkcipher_reqtfm(dd->req));
int err, fast = 0, in, out;
size_t count;
dma_addr_t addr_in, addr_out;
struct scatterlist *in_sg, *out_sg;
int len32;
pr_debug("total: %d\n", dd->total);
if (sg_is_last(dd->in_sg) && sg_is_last(dd->out_sg)) {
in = IS_ALIGNED((u32)dd->in_sg->offset, sizeof(u32));
out = IS_ALIGNED((u32)dd->out_sg->offset, sizeof(u32));
fast = in && out;
}
if (fast) {
count = min(dd->total, sg_dma_len(dd->in_sg));
count = min(count, sg_dma_len(dd->out_sg));
if (count != dd->total) {
pr_err("request length != buffer length\n");
return -EINVAL;
}
pr_debug("fast\n");
err = dma_map_sg(dd->dev, dd->in_sg, 1, DMA_TO_DEVICE);
if (!err) {
dev_err(dd->dev, "dma_map_sg() error\n");
return -EINVAL;
}
err = dma_map_sg(dd->dev, dd->out_sg, 1, DMA_FROM_DEVICE);
if (!err) {
dev_err(dd->dev, "dma_map_sg() error\n");
dma_unmap_sg(dd->dev, dd->in_sg, 1, DMA_TO_DEVICE);
return -EINVAL;
}
addr_in = sg_dma_address(dd->in_sg);
addr_out = sg_dma_address(dd->out_sg);
in_sg = dd->in_sg;
out_sg = dd->out_sg;
dd->flags |= FLAGS_FAST;
} else {
count = sg_copy(&dd->in_sg, &dd->in_offset, dd->buf_in,
dd->buflen, dd->total, 0);
len32 = DIV_ROUND_UP(count, DMA_MIN) * DMA_MIN;
sg_init_table(&dd->in_sgl, 1);
dd->in_sgl.offset = dd->in_offset;
sg_dma_len(&dd->in_sgl) = len32;
sg_dma_address(&dd->in_sgl) = dd->dma_addr_in;
sg_init_table(&dd->out_sgl, 1);
dd->out_sgl.offset = dd->out_offset;
sg_dma_len(&dd->out_sgl) = len32;
sg_dma_address(&dd->out_sgl) = dd->dma_addr_out;
in_sg = &dd->in_sgl;
out_sg = &dd->out_sgl;
addr_in = dd->dma_addr_in;
addr_out = dd->dma_addr_out;
dd->flags &= ~FLAGS_FAST;
}
dd->total -= count;
err = omap_aes_crypt_dma(tfm, in_sg, out_sg);
if (err) {
dma_unmap_sg(dd->dev, dd->in_sg, 1, DMA_TO_DEVICE);
dma_unmap_sg(dd->dev, dd->out_sg, 1, DMA_TO_DEVICE);
}
return err;
}
static void omap_aes_finish_req(struct omap_aes_dev *dd, int err)
{
struct ablkcipher_request *req = dd->req;
pr_debug("err: %d\n", err);
dd->flags &= ~FLAGS_BUSY;
req->base.complete(&req->base, err);
}
static int omap_aes_crypt_dma_stop(struct omap_aes_dev *dd)
{
int err = 0;
size_t count;
pr_debug("total: %d\n", dd->total);
omap_aes_dma_stop(dd);
dmaengine_terminate_all(dd->dma_lch_in);
dmaengine_terminate_all(dd->dma_lch_out);
if (dd->flags & FLAGS_FAST) {
dma_unmap_sg(dd->dev, dd->out_sg, 1, DMA_FROM_DEVICE);
dma_unmap_sg(dd->dev, dd->in_sg, 1, DMA_TO_DEVICE);
} else {
dma_sync_single_for_device(dd->dev, dd->dma_addr_out,
dd->dma_size, DMA_FROM_DEVICE);
count = sg_copy(&dd->out_sg, &dd->out_offset, dd->buf_out,
dd->buflen, dd->dma_size, 1);
if (count != dd->dma_size) {
err = -EINVAL;
pr_err("not all data converted: %u\n", count);
}
}
return err;
}
static int omap_aes_handle_queue(struct omap_aes_dev *dd,
struct ablkcipher_request *req)
{
struct crypto_async_request *async_req, *backlog;
struct omap_aes_ctx *ctx;
struct omap_aes_reqctx *rctx;
unsigned long flags;
int err, ret = 0;
spin_lock_irqsave(&dd->lock, flags);
if (req)
ret = ablkcipher_enqueue_request(&dd->queue, req);
if (dd->flags & FLAGS_BUSY) {
spin_unlock_irqrestore(&dd->lock, flags);
return ret;
}
backlog = crypto_get_backlog(&dd->queue);
async_req = crypto_dequeue_request(&dd->queue);
if (async_req)
dd->flags |= FLAGS_BUSY;
spin_unlock_irqrestore(&dd->lock, flags);
if (!async_req)
return ret;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ablkcipher_request_cast(async_req);
dd->req = req;
dd->total = req->nbytes;
dd->in_offset = 0;
dd->in_sg = req->src;
dd->out_offset = 0;
dd->out_sg = req->dst;
rctx = ablkcipher_request_ctx(req);
ctx = crypto_ablkcipher_ctx(crypto_ablkcipher_reqtfm(req));
rctx->mode &= FLAGS_MODE_MASK;
dd->flags = (dd->flags & ~FLAGS_MODE_MASK) | rctx->mode;
dd->ctx = ctx;
ctx->dd = dd;
err = omap_aes_write_ctrl(dd);
if (!err)
err = omap_aes_crypt_dma_start(dd);
if (err) {
omap_aes_finish_req(dd, err);
tasklet_schedule(&dd->queue_task);
}
return ret;
}
static void omap_aes_done_task(unsigned long data)
{
struct omap_aes_dev *dd = (struct omap_aes_dev *)data;
int err;
pr_debug("enter\n");
err = omap_aes_crypt_dma_stop(dd);
err = dd->err ? : err;
if (dd->total && !err) {
err = omap_aes_crypt_dma_start(dd);
if (!err)
return;
}
omap_aes_finish_req(dd, err);
omap_aes_handle_queue(dd, NULL);
pr_debug("exit\n");
}
static void omap_aes_queue_task(unsigned long data)
{
struct omap_aes_dev *dd = (struct omap_aes_dev *)data;
omap_aes_handle_queue(dd, NULL);
}
static int omap_aes_crypt(struct ablkcipher_request *req, unsigned long mode)
{
struct omap_aes_ctx *ctx = crypto_ablkcipher_ctx(
crypto_ablkcipher_reqtfm(req));
struct omap_aes_reqctx *rctx = ablkcipher_request_ctx(req);
struct omap_aes_dev *dd;
pr_debug("nbytes: %d, enc: %d, cbc: %d\n", req->nbytes,
!!(mode & FLAGS_ENCRYPT),
!!(mode & FLAGS_CBC));
if (!IS_ALIGNED(req->nbytes, AES_BLOCK_SIZE)) {
pr_err("request size is not exact amount of AES blocks\n");
return -EINVAL;
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
if (keylen != AES_KEYSIZE_128 && keylen != AES_KEYSIZE_192 &&
keylen != AES_KEYSIZE_256)
return -EINVAL;
pr_debug("enter, keylen: %d\n", keylen);
memcpy(ctx->key, key, keylen);
ctx->keylen = keylen;
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
struct omap_aes_dev *dd = NULL;
spin_lock_bh(&list_lock);
list_for_each_entry(dd, &dev_list, list) {
break;
}
spin_unlock_bh(&list_lock);
pm_runtime_get_sync(dd->dev);
tfm->crt_ablkcipher.reqsize = sizeof(struct omap_aes_reqctx);
return 0;
}
static void omap_aes_cra_exit(struct crypto_tfm *tfm)
{
struct omap_aes_dev *dd = NULL;
spin_lock_bh(&list_lock);
list_for_each_entry(dd, &dev_list, list) {
break;
}
spin_unlock_bh(&list_lock);
pm_runtime_put_sync(dd->dev);
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
dd->dma_out = -1;
dd->dma_in = -1;
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
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!r) {
dev_err(dev, "no DMA out resource info\n");
err = -ENODEV;
goto err;
}
dd->dma_out = r->start;
r = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!r) {
dev_err(dev, "no DMA in resource info\n");
err = -ENODEV;
goto err;
}
dd->dma_in = r->start;
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
int err = -ENOMEM, i, j;
u32 reg;
dd = kzalloc(sizeof(struct omap_aes_dev), GFP_KERNEL);
if (dd == NULL) {
dev_err(dev, "unable to alloc data struct.\n");
goto err_data;
}
dd->dev = dev;
platform_set_drvdata(pdev, dd);
spin_lock_init(&dd->lock);
crypto_init_queue(&dd->queue, OMAP_AES_QUEUE_LENGTH);
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
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
omap_aes_dma_stop(dd);
reg = omap_aes_read(dd, AES_REG_REV(dd));
pm_runtime_put_sync(dev);
dev_info(dev, "OMAP AES hw accel rev: %u.%u\n",
(reg & dd->pdata->major_mask) >> dd->pdata->major_shift,
(reg & dd->pdata->minor_mask) >> dd->pdata->minor_shift);
tasklet_init(&dd->done_task, omap_aes_done_task, (unsigned long)dd);
tasklet_init(&dd->queue_task, omap_aes_queue_task, (unsigned long)dd);
err = omap_aes_dma_init(dd);
if (err)
goto err_dma;
INIT_LIST_HEAD(&dd->list);
spin_lock(&list_lock);
list_add_tail(&dd->list, &dev_list);
spin_unlock(&list_lock);
for (i = 0; i < dd->pdata->algs_info_size; i++) {
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
return 0;
err_algs:
for (i = dd->pdata->algs_info_size - 1; i >= 0; i--)
for (j = dd->pdata->algs_info[i].registered - 1; j >= 0; j--)
crypto_unregister_alg(
&dd->pdata->algs_info[i].algs_list[j]);
omap_aes_dma_cleanup(dd);
err_dma:
tasklet_kill(&dd->done_task);
tasklet_kill(&dd->queue_task);
pm_runtime_disable(dev);
err_res:
kfree(dd);
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
tasklet_kill(&dd->done_task);
tasklet_kill(&dd->queue_task);
omap_aes_dma_cleanup(dd);
pm_runtime_disable(dd->dev);
kfree(dd);
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
