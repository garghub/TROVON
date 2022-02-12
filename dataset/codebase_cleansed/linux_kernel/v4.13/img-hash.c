static inline u32 img_hash_read(struct img_hash_dev *hdev, u32 offset)
{
return readl_relaxed(hdev->io_base + offset);
}
static inline void img_hash_write(struct img_hash_dev *hdev,
u32 offset, u32 value)
{
writel_relaxed(value, hdev->io_base + offset);
}
static inline u32 img_hash_read_result_queue(struct img_hash_dev *hdev)
{
return be32_to_cpu(img_hash_read(hdev, CR_RESULT_QUEUE));
}
static void img_hash_start(struct img_hash_dev *hdev, bool dma)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
u32 cr = IMG_HASH_BYTE_ORDER << CR_CONTROL_BYTE_ORDER_SHIFT;
if (ctx->flags & DRIVER_FLAGS_MD5)
cr |= CR_CONTROL_ALGO_MD5;
else if (ctx->flags & DRIVER_FLAGS_SHA1)
cr |= CR_CONTROL_ALGO_SHA1;
else if (ctx->flags & DRIVER_FLAGS_SHA224)
cr |= CR_CONTROL_ALGO_SHA224;
else if (ctx->flags & DRIVER_FLAGS_SHA256)
cr |= CR_CONTROL_ALGO_SHA256;
dev_dbg(hdev->dev, "Starting hash process\n");
img_hash_write(hdev, CR_CONTROL, cr);
if (!dma)
img_hash_read(hdev, CR_CONTROL);
}
static int img_hash_xmit_cpu(struct img_hash_dev *hdev, const u8 *buf,
size_t length, int final)
{
u32 count, len32;
const u32 *buffer = (const u32 *)buf;
dev_dbg(hdev->dev, "xmit_cpu: length: %zu bytes\n", length);
if (final)
hdev->flags |= DRIVER_FLAGS_FINAL;
len32 = DIV_ROUND_UP(length, sizeof(u32));
for (count = 0; count < len32; count++)
writel_relaxed(buffer[count], hdev->cpu_addr);
return -EINPROGRESS;
}
static void img_hash_dma_callback(void *data)
{
struct img_hash_dev *hdev = (struct img_hash_dev *)data;
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
if (ctx->bufcnt) {
img_hash_xmit_cpu(hdev, ctx->buffer, ctx->bufcnt, 0);
ctx->bufcnt = 0;
}
if (ctx->sg)
tasklet_schedule(&hdev->dma_task);
}
static int img_hash_xmit_dma(struct img_hash_dev *hdev, struct scatterlist *sg)
{
struct dma_async_tx_descriptor *desc;
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
ctx->dma_ct = dma_map_sg(hdev->dev, sg, 1, DMA_TO_DEVICE);
if (ctx->dma_ct == 0) {
dev_err(hdev->dev, "Invalid DMA sg\n");
hdev->err = -EINVAL;
return -EINVAL;
}
desc = dmaengine_prep_slave_sg(hdev->dma_lch,
sg,
ctx->dma_ct,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(hdev->dev, "Null DMA descriptor\n");
hdev->err = -EINVAL;
dma_unmap_sg(hdev->dev, sg, 1, DMA_TO_DEVICE);
return -EINVAL;
}
desc->callback = img_hash_dma_callback;
desc->callback_param = hdev;
dmaengine_submit(desc);
dma_async_issue_pending(hdev->dma_lch);
return 0;
}
static int img_hash_write_via_cpu(struct img_hash_dev *hdev)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
ctx->bufcnt = sg_copy_to_buffer(hdev->req->src, sg_nents(ctx->sg),
ctx->buffer, hdev->req->nbytes);
ctx->total = hdev->req->nbytes;
ctx->bufcnt = 0;
hdev->flags |= (DRIVER_FLAGS_CPU | DRIVER_FLAGS_FINAL);
img_hash_start(hdev, false);
return img_hash_xmit_cpu(hdev, ctx->buffer, ctx->total, 1);
}
static int img_hash_finish(struct ahash_request *req)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(req);
if (!req->result)
return -EINVAL;
memcpy(req->result, ctx->digest, ctx->digsize);
return 0;
}
static void img_hash_copy_hash(struct ahash_request *req)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(req);
u32 *hash = (u32 *)ctx->digest;
int i;
for (i = (ctx->digsize / sizeof(u32)) - 1; i >= 0; i--)
hash[i] = img_hash_read_result_queue(ctx->hdev);
}
static void img_hash_finish_req(struct ahash_request *req, int err)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(req);
struct img_hash_dev *hdev = ctx->hdev;
if (!err) {
img_hash_copy_hash(req);
if (DRIVER_FLAGS_FINAL & hdev->flags)
err = img_hash_finish(req);
} else {
dev_warn(hdev->dev, "Hash failed with error %d\n", err);
ctx->flags |= DRIVER_FLAGS_ERROR;
}
hdev->flags &= ~(DRIVER_FLAGS_DMA_READY | DRIVER_FLAGS_OUTPUT_READY |
DRIVER_FLAGS_CPU | DRIVER_FLAGS_BUSY | DRIVER_FLAGS_FINAL);
if (req->base.complete)
req->base.complete(&req->base, err);
}
static int img_hash_write_via_dma(struct img_hash_dev *hdev)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
img_hash_start(hdev, true);
dev_dbg(hdev->dev, "xmit dma size: %d\n", ctx->total);
if (!ctx->total)
hdev->flags |= DRIVER_FLAGS_FINAL;
hdev->flags |= DRIVER_FLAGS_DMA_ACTIVE | DRIVER_FLAGS_FINAL;
tasklet_schedule(&hdev->dma_task);
return -EINPROGRESS;
}
static int img_hash_dma_init(struct img_hash_dev *hdev)
{
struct dma_slave_config dma_conf;
int err = -EINVAL;
hdev->dma_lch = dma_request_slave_channel(hdev->dev, "tx");
if (!hdev->dma_lch) {
dev_err(hdev->dev, "Couldn't acquire a slave DMA channel.\n");
return -EBUSY;
}
dma_conf.direction = DMA_MEM_TO_DEV;
dma_conf.dst_addr = hdev->bus_addr;
dma_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
dma_conf.dst_maxburst = IMG_HASH_DMA_BURST;
dma_conf.device_fc = false;
err = dmaengine_slave_config(hdev->dma_lch, &dma_conf);
if (err) {
dev_err(hdev->dev, "Couldn't configure DMA slave.\n");
dma_release_channel(hdev->dma_lch);
return err;
}
return 0;
}
static void img_hash_dma_task(unsigned long d)
{
struct img_hash_dev *hdev = (struct img_hash_dev *)d;
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
u8 *addr;
size_t nbytes, bleft, wsend, len, tbc;
struct scatterlist tsg;
if (!hdev->req || !ctx->sg)
return;
addr = sg_virt(ctx->sg);
nbytes = ctx->sg->length - ctx->offset;
bleft = nbytes % 4;
wsend = (nbytes / 4);
if (wsend) {
sg_init_one(&tsg, addr + ctx->offset, wsend * 4);
if (img_hash_xmit_dma(hdev, &tsg)) {
dev_err(hdev->dev, "DMA failed, falling back to CPU");
ctx->flags |= DRIVER_FLAGS_CPU;
hdev->err = 0;
img_hash_xmit_cpu(hdev, addr + ctx->offset,
wsend * 4, 0);
ctx->sent += wsend * 4;
wsend = 0;
} else {
ctx->sent += wsend * 4;
}
}
if (bleft) {
ctx->bufcnt = sg_pcopy_to_buffer(ctx->sgfirst, ctx->nents,
ctx->buffer, bleft, ctx->sent);
tbc = 0;
ctx->sg = sg_next(ctx->sg);
while (ctx->sg && (ctx->bufcnt < 4)) {
len = ctx->sg->length;
if (likely(len > (4 - ctx->bufcnt)))
len = 4 - ctx->bufcnt;
tbc = sg_pcopy_to_buffer(ctx->sgfirst, ctx->nents,
ctx->buffer + ctx->bufcnt, len,
ctx->sent + ctx->bufcnt);
ctx->bufcnt += tbc;
if (tbc >= ctx->sg->length) {
ctx->sg = sg_next(ctx->sg);
tbc = 0;
}
}
ctx->sent += ctx->bufcnt;
ctx->offset = tbc;
if (!wsend)
img_hash_dma_callback(hdev);
} else {
ctx->offset = 0;
ctx->sg = sg_next(ctx->sg);
}
}
static int img_hash_write_via_dma_stop(struct img_hash_dev *hdev)
{
struct img_hash_request_ctx *ctx = ahash_request_ctx(hdev->req);
if (ctx->flags & DRIVER_FLAGS_SG)
dma_unmap_sg(hdev->dev, ctx->sg, ctx->dma_ct, DMA_TO_DEVICE);
return 0;
}
static int img_hash_process_data(struct img_hash_dev *hdev)
{
struct ahash_request *req = hdev->req;
struct img_hash_request_ctx *ctx = ahash_request_ctx(req);
int err = 0;
ctx->bufcnt = 0;
if (req->nbytes >= IMG_HASH_DMA_THRESHOLD) {
dev_dbg(hdev->dev, "process data request(%d bytes) using DMA\n",
req->nbytes);
err = img_hash_write_via_dma(hdev);
} else {
dev_dbg(hdev->dev, "process data request(%d bytes) using CPU\n",
req->nbytes);
err = img_hash_write_via_cpu(hdev);
}
return err;
}
static int img_hash_hw_init(struct img_hash_dev *hdev)
{
unsigned long long nbits;
u32 u, l;
img_hash_write(hdev, CR_RESET, CR_RESET_SET);
img_hash_write(hdev, CR_RESET, CR_RESET_UNSET);
img_hash_write(hdev, CR_INTENAB, CR_INT_NEW_RESULTS_SET);
nbits = (u64)hdev->req->nbytes << 3;
u = nbits >> 32;
l = nbits;
img_hash_write(hdev, CR_MESSAGE_LENGTH_H, u);
img_hash_write(hdev, CR_MESSAGE_LENGTH_L, l);
if (!(DRIVER_FLAGS_INIT & hdev->flags)) {
hdev->flags |= DRIVER_FLAGS_INIT;
hdev->err = 0;
}
dev_dbg(hdev->dev, "hw initialized, nbits: %llx\n", nbits);
return 0;
}
static int img_hash_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_init(&rctx->fallback_req);
}
static int img_hash_handle_queue(struct img_hash_dev *hdev,
struct ahash_request *req)
{
struct crypto_async_request *async_req, *backlog;
struct img_hash_request_ctx *ctx;
unsigned long flags;
int err = 0, res = 0;
spin_lock_irqsave(&hdev->lock, flags);
if (req)
res = ahash_enqueue_request(&hdev->queue, req);
if (DRIVER_FLAGS_BUSY & hdev->flags) {
spin_unlock_irqrestore(&hdev->lock, flags);
return res;
}
backlog = crypto_get_backlog(&hdev->queue);
async_req = crypto_dequeue_request(&hdev->queue);
if (async_req)
hdev->flags |= DRIVER_FLAGS_BUSY;
spin_unlock_irqrestore(&hdev->lock, flags);
if (!async_req)
return res;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ahash_request_cast(async_req);
hdev->req = req;
ctx = ahash_request_ctx(req);
dev_info(hdev->dev, "processing req, op: %lu, bytes: %d\n",
ctx->op, req->nbytes);
err = img_hash_hw_init(hdev);
if (!err)
err = img_hash_process_data(hdev);
if (err != -EINPROGRESS) {
img_hash_finish_req(req, err);
}
return res;
}
static int img_hash_update(struct ahash_request *req)
{
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.nbytes = req->nbytes;
rctx->fallback_req.src = req->src;
return crypto_ahash_update(&rctx->fallback_req);
}
static int img_hash_final(struct ahash_request *req)
{
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.result = req->result;
return crypto_ahash_final(&rctx->fallback_req);
}
static int img_hash_finup(struct ahash_request *req)
{
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
rctx->fallback_req.nbytes = req->nbytes;
rctx->fallback_req.src = req->src;
rctx->fallback_req.result = req->result;
return crypto_ahash_finup(&rctx->fallback_req);
}
static int img_hash_import(struct ahash_request *req, const void *in)
{
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_import(&rctx->fallback_req, in);
}
static int img_hash_export(struct ahash_request *req, void *out)
{
struct img_hash_request_ctx *rctx = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *ctx = crypto_ahash_ctx(tfm);
ahash_request_set_tfm(&rctx->fallback_req, ctx->fallback);
rctx->fallback_req.base.flags = req->base.flags
& CRYPTO_TFM_REQ_MAY_SLEEP;
return crypto_ahash_export(&rctx->fallback_req, out);
}
static int img_hash_digest(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct img_hash_ctx *tctx = crypto_ahash_ctx(tfm);
struct img_hash_request_ctx *ctx = ahash_request_ctx(req);
struct img_hash_dev *hdev = NULL;
struct img_hash_dev *tmp;
int err;
spin_lock(&img_hash.lock);
if (!tctx->hdev) {
list_for_each_entry(tmp, &img_hash.dev_list, list) {
hdev = tmp;
break;
}
tctx->hdev = hdev;
} else {
hdev = tctx->hdev;
}
spin_unlock(&img_hash.lock);
ctx->hdev = hdev;
ctx->flags = 0;
ctx->digsize = crypto_ahash_digestsize(tfm);
switch (ctx->digsize) {
case SHA1_DIGEST_SIZE:
ctx->flags |= DRIVER_FLAGS_SHA1;
break;
case SHA256_DIGEST_SIZE:
ctx->flags |= DRIVER_FLAGS_SHA256;
break;
case SHA224_DIGEST_SIZE:
ctx->flags |= DRIVER_FLAGS_SHA224;
break;
case MD5_DIGEST_SIZE:
ctx->flags |= DRIVER_FLAGS_MD5;
break;
default:
return -EINVAL;
}
ctx->bufcnt = 0;
ctx->offset = 0;
ctx->sent = 0;
ctx->total = req->nbytes;
ctx->sg = req->src;
ctx->sgfirst = req->src;
ctx->nents = sg_nents(ctx->sg);
err = img_hash_handle_queue(tctx->hdev, req);
return err;
}
static int img_hash_cra_init(struct crypto_tfm *tfm, const char *alg_name)
{
struct img_hash_ctx *ctx = crypto_tfm_ctx(tfm);
int err = -ENOMEM;
ctx->fallback = crypto_alloc_ahash(alg_name, 0,
CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(ctx->fallback)) {
pr_err("img_hash: Could not load fallback driver.\n");
err = PTR_ERR(ctx->fallback);
goto err;
}
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct img_hash_request_ctx) +
crypto_ahash_reqsize(ctx->fallback) +
IMG_HASH_DMA_THRESHOLD);
return 0;
err:
return err;
}
static int img_hash_cra_md5_init(struct crypto_tfm *tfm)
{
return img_hash_cra_init(tfm, "md5-generic");
}
static int img_hash_cra_sha1_init(struct crypto_tfm *tfm)
{
return img_hash_cra_init(tfm, "sha1-generic");
}
static int img_hash_cra_sha224_init(struct crypto_tfm *tfm)
{
return img_hash_cra_init(tfm, "sha224-generic");
}
static int img_hash_cra_sha256_init(struct crypto_tfm *tfm)
{
return img_hash_cra_init(tfm, "sha256-generic");
}
static void img_hash_cra_exit(struct crypto_tfm *tfm)
{
struct img_hash_ctx *tctx = crypto_tfm_ctx(tfm);
crypto_free_ahash(tctx->fallback);
}
static irqreturn_t img_irq_handler(int irq, void *dev_id)
{
struct img_hash_dev *hdev = dev_id;
u32 reg;
reg = img_hash_read(hdev, CR_INTSTAT);
img_hash_write(hdev, CR_INTCLEAR, reg);
if (reg & CR_INT_NEW_RESULTS_SET) {
dev_dbg(hdev->dev, "IRQ CR_INT_NEW_RESULTS_SET\n");
if (DRIVER_FLAGS_BUSY & hdev->flags) {
hdev->flags |= DRIVER_FLAGS_OUTPUT_READY;
if (!(DRIVER_FLAGS_CPU & hdev->flags))
hdev->flags |= DRIVER_FLAGS_DMA_READY;
tasklet_schedule(&hdev->done_task);
} else {
dev_warn(hdev->dev,
"HASH interrupt when no active requests.\n");
}
} else if (reg & CR_INT_RESULTS_AVAILABLE) {
dev_warn(hdev->dev,
"IRQ triggered before the hash had completed\n");
} else if (reg & CR_INT_RESULT_READ_ERR) {
dev_warn(hdev->dev,
"Attempt to read from an empty result queue\n");
} else if (reg & CR_INT_MESSAGE_WRITE_ERROR) {
dev_warn(hdev->dev,
"Data written before the hardware was configured\n");
}
return IRQ_HANDLED;
}
static int img_register_algs(struct img_hash_dev *hdev)
{
int i, err;
for (i = 0; i < ARRAY_SIZE(img_algs); i++) {
err = crypto_register_ahash(&img_algs[i]);
if (err)
goto err_reg;
}
return 0;
err_reg:
for (; i--; )
crypto_unregister_ahash(&img_algs[i]);
return err;
}
static int img_unregister_algs(struct img_hash_dev *hdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(img_algs); i++)
crypto_unregister_ahash(&img_algs[i]);
return 0;
}
static void img_hash_done_task(unsigned long data)
{
struct img_hash_dev *hdev = (struct img_hash_dev *)data;
int err = 0;
if (hdev->err == -EINVAL) {
err = hdev->err;
goto finish;
}
if (!(DRIVER_FLAGS_BUSY & hdev->flags)) {
img_hash_handle_queue(hdev, NULL);
return;
}
if (DRIVER_FLAGS_CPU & hdev->flags) {
if (DRIVER_FLAGS_OUTPUT_READY & hdev->flags) {
hdev->flags &= ~DRIVER_FLAGS_OUTPUT_READY;
goto finish;
}
} else if (DRIVER_FLAGS_DMA_READY & hdev->flags) {
if (DRIVER_FLAGS_DMA_ACTIVE & hdev->flags) {
hdev->flags &= ~DRIVER_FLAGS_DMA_ACTIVE;
img_hash_write_via_dma_stop(hdev);
if (hdev->err) {
err = hdev->err;
goto finish;
}
}
if (DRIVER_FLAGS_OUTPUT_READY & hdev->flags) {
hdev->flags &= ~(DRIVER_FLAGS_DMA_READY |
DRIVER_FLAGS_OUTPUT_READY);
goto finish;
}
}
return;
finish:
img_hash_finish_req(hdev->req, err);
}
static int img_hash_probe(struct platform_device *pdev)
{
struct img_hash_dev *hdev;
struct device *dev = &pdev->dev;
struct resource *hash_res;
int irq;
int err;
hdev = devm_kzalloc(dev, sizeof(*hdev), GFP_KERNEL);
if (hdev == NULL)
return -ENOMEM;
spin_lock_init(&hdev->lock);
hdev->dev = dev;
platform_set_drvdata(pdev, hdev);
INIT_LIST_HEAD(&hdev->list);
tasklet_init(&hdev->done_task, img_hash_done_task, (unsigned long)hdev);
tasklet_init(&hdev->dma_task, img_hash_dma_task, (unsigned long)hdev);
crypto_init_queue(&hdev->queue, IMG_HASH_QUEUE_LENGTH);
hash_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hdev->io_base = devm_ioremap_resource(dev, hash_res);
if (IS_ERR(hdev->io_base)) {
err = PTR_ERR(hdev->io_base);
dev_err(dev, "can't ioremap, returned %d\n", err);
goto res_err;
}
hash_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
hdev->cpu_addr = devm_ioremap_resource(dev, hash_res);
if (IS_ERR(hdev->cpu_addr)) {
dev_err(dev, "can't ioremap write port\n");
err = PTR_ERR(hdev->cpu_addr);
goto res_err;
}
hdev->bus_addr = hash_res->start;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no IRQ resource info\n");
err = irq;
goto res_err;
}
err = devm_request_irq(dev, irq, img_irq_handler, 0,
dev_name(dev), hdev);
if (err) {
dev_err(dev, "unable to request irq\n");
goto res_err;
}
dev_dbg(dev, "using IRQ channel %d\n", irq);
hdev->hash_clk = devm_clk_get(&pdev->dev, "hash");
if (IS_ERR(hdev->hash_clk)) {
dev_err(dev, "clock initialization failed.\n");
err = PTR_ERR(hdev->hash_clk);
goto res_err;
}
hdev->sys_clk = devm_clk_get(&pdev->dev, "sys");
if (IS_ERR(hdev->sys_clk)) {
dev_err(dev, "clock initialization failed.\n");
err = PTR_ERR(hdev->sys_clk);
goto res_err;
}
err = clk_prepare_enable(hdev->hash_clk);
if (err)
goto res_err;
err = clk_prepare_enable(hdev->sys_clk);
if (err)
goto clk_err;
err = img_hash_dma_init(hdev);
if (err)
goto dma_err;
dev_dbg(dev, "using %s for DMA transfers\n",
dma_chan_name(hdev->dma_lch));
spin_lock(&img_hash.lock);
list_add_tail(&hdev->list, &img_hash.dev_list);
spin_unlock(&img_hash.lock);
err = img_register_algs(hdev);
if (err)
goto err_algs;
dev_info(dev, "Img MD5/SHA1/SHA224/SHA256 Hardware accelerator initialized\n");
return 0;
err_algs:
spin_lock(&img_hash.lock);
list_del(&hdev->list);
spin_unlock(&img_hash.lock);
dma_release_channel(hdev->dma_lch);
dma_err:
clk_disable_unprepare(hdev->sys_clk);
clk_err:
clk_disable_unprepare(hdev->hash_clk);
res_err:
tasklet_kill(&hdev->done_task);
tasklet_kill(&hdev->dma_task);
return err;
}
static int img_hash_remove(struct platform_device *pdev)
{
static struct img_hash_dev *hdev;
hdev = platform_get_drvdata(pdev);
spin_lock(&img_hash.lock);
list_del(&hdev->list);
spin_unlock(&img_hash.lock);
img_unregister_algs(hdev);
tasklet_kill(&hdev->done_task);
tasklet_kill(&hdev->dma_task);
dma_release_channel(hdev->dma_lch);
clk_disable_unprepare(hdev->hash_clk);
clk_disable_unprepare(hdev->sys_clk);
return 0;
}
static int img_hash_suspend(struct device *dev)
{
struct img_hash_dev *hdev = dev_get_drvdata(dev);
clk_disable_unprepare(hdev->hash_clk);
clk_disable_unprepare(hdev->sys_clk);
return 0;
}
static int img_hash_resume(struct device *dev)
{
struct img_hash_dev *hdev = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(hdev->hash_clk);
if (ret)
return ret;
ret = clk_prepare_enable(hdev->sys_clk);
if (ret) {
clk_disable_unprepare(hdev->hash_clk);
return ret;
}
return 0;
}
