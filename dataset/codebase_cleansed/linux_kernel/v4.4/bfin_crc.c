static struct scatterlist *sg_get(struct scatterlist *sg_list, unsigned int nents,
unsigned int index)
{
struct scatterlist *sg = NULL;
int i;
for_each_sg(sg_list, sg, nents, i)
if (i == index)
break;
return sg;
}
static int bfin_crypto_crc_init_hw(struct bfin_crypto_crc *crc, u32 key)
{
writel(0, &crc->regs->datacntrld);
writel(MODE_CALC_CRC << OPMODE_OFFSET, &crc->regs->control);
writel(key, &crc->regs->curresult);
writel(CMPERRI | DCNTEXPI, &crc->regs->status);
writel(CMPERRI | DCNTEXPI, &crc->regs->intrenset);
return 0;
}
static int bfin_crypto_crc_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct bfin_crypto_crc_ctx *crc_ctx = crypto_ahash_ctx(tfm);
struct bfin_crypto_crc_reqctx *ctx = ahash_request_ctx(req);
struct bfin_crypto_crc *crc;
dev_dbg(ctx->crc->dev, "crc_init\n");
spin_lock_bh(&crc_list.lock);
list_for_each_entry(crc, &crc_list.dev_list, list) {
crc_ctx->crc = crc;
break;
}
spin_unlock_bh(&crc_list.lock);
if (sg_nents(req->src) > CRC_MAX_DMA_DESC) {
dev_dbg(ctx->crc->dev, "init: requested sg list is too big > %d\n",
CRC_MAX_DMA_DESC);
return -EINVAL;
}
ctx->crc = crc;
ctx->bufnext_len = 0;
ctx->buflast_len = 0;
ctx->sg_buflen = 0;
ctx->total = 0;
ctx->flag = 0;
put_unaligned_le32(crc_ctx->key, req->result);
dev_dbg(ctx->crc->dev, "init: digest size: %d\n",
crypto_ahash_digestsize(tfm));
return bfin_crypto_crc_init_hw(crc, crc_ctx->key);
}
static void bfin_crypto_crc_config_dma(struct bfin_crypto_crc *crc)
{
struct scatterlist *sg;
struct bfin_crypto_crc_reqctx *ctx = ahash_request_ctx(crc->req);
int i = 0, j = 0;
unsigned long dma_config;
unsigned int dma_count;
unsigned int dma_addr;
unsigned int mid_dma_count = 0;
int dma_mod;
dma_map_sg(crc->dev, ctx->sg, ctx->sg_nents, DMA_TO_DEVICE);
for_each_sg(ctx->sg, sg, ctx->sg_nents, j) {
dma_addr = sg_dma_address(sg);
if (sg_is_last(sg))
dma_count = sg_dma_len(sg) - ctx->bufnext_len;
else
dma_count = sg_dma_len(sg);
if (mid_dma_count) {
memcpy(crc->sg_mid_buf +(i << 2) + mid_dma_count,
sg_virt(sg),
CHKSUM_DIGEST_SIZE - mid_dma_count);
dma_addr += CHKSUM_DIGEST_SIZE - mid_dma_count;
dma_count -= CHKSUM_DIGEST_SIZE - mid_dma_count;
dma_config = DMAFLOW_ARRAY | RESTART | NDSIZE_3 |
DMAEN | PSIZE_32 | WDSIZE_32;
crc->sg_cpu[i].start_addr = crc->sg_mid_dma + (i << 2);
crc->sg_cpu[i].cfg = dma_config;
crc->sg_cpu[i].x_count = 1;
crc->sg_cpu[i].x_modify = CHKSUM_DIGEST_SIZE;
dev_dbg(crc->dev, "%d: crc_dma: start_addr:0x%lx, "
"cfg:0x%lx, x_count:0x%lx, x_modify:0x%lx\n",
i, crc->sg_cpu[i].start_addr,
crc->sg_cpu[i].cfg, crc->sg_cpu[i].x_count,
crc->sg_cpu[i].x_modify);
i++;
}
dma_config = DMAFLOW_ARRAY | RESTART | NDSIZE_3 | DMAEN | PSIZE_32;
mid_dma_count = dma_count % 4;
dma_count &= ~0x3;
if (dma_addr % 4 == 0) {
dma_config |= WDSIZE_32;
dma_count >>= 2;
dma_mod = 4;
} else if (dma_addr % 2 == 0) {
dma_config |= WDSIZE_16;
dma_count >>= 1;
dma_mod = 2;
} else {
dma_config |= WDSIZE_8;
dma_mod = 1;
}
crc->sg_cpu[i].start_addr = dma_addr;
crc->sg_cpu[i].cfg = dma_config;
crc->sg_cpu[i].x_count = dma_count;
crc->sg_cpu[i].x_modify = dma_mod;
dev_dbg(crc->dev, "%d: crc_dma: start_addr:0x%lx, "
"cfg:0x%lx, x_count:0x%lx, x_modify:0x%lx\n",
i, crc->sg_cpu[i].start_addr,
crc->sg_cpu[i].cfg, crc->sg_cpu[i].x_count,
crc->sg_cpu[i].x_modify);
i++;
if (mid_dma_count) {
memcpy(crc->sg_mid_buf + (i << 2),
(u8*)sg_virt(sg) + (dma_count << 2),
mid_dma_count);
}
}
dma_config = DMAFLOW_ARRAY | RESTART | NDSIZE_3 | DMAEN | PSIZE_32 | WDSIZE_32;
if (ctx->bufnext_len && (ctx->flag == CRC_CRYPTO_STATE_FINALUPDATE ||
ctx->flag == CRC_CRYPTO_STATE_FINISH)) {
crc->sg_cpu[i].start_addr = dma_map_single(crc->dev, ctx->bufnext,
CHKSUM_DIGEST_SIZE, DMA_TO_DEVICE);
crc->sg_cpu[i].cfg = dma_config;
crc->sg_cpu[i].x_count = 1;
crc->sg_cpu[i].x_modify = CHKSUM_DIGEST_SIZE;
dev_dbg(crc->dev, "%d: crc_dma: start_addr:0x%lx, "
"cfg:0x%lx, x_count:0x%lx, x_modify:0x%lx\n",
i, crc->sg_cpu[i].start_addr,
crc->sg_cpu[i].cfg, crc->sg_cpu[i].x_count,
crc->sg_cpu[i].x_modify);
i++;
}
if (i == 0)
return;
crc->sg_cpu[i - 1].cfg &= ~(DMAFLOW | NDSIZE);
crc->sg_cpu[i - 1].cfg |= DI_EN;
set_dma_curr_desc_addr(crc->dma_ch, (unsigned long *)crc->sg_dma);
set_dma_x_count(crc->dma_ch, 0);
set_dma_x_modify(crc->dma_ch, 0);
set_dma_config(crc->dma_ch, dma_config);
}
static int bfin_crypto_crc_handle_queue(struct bfin_crypto_crc *crc,
struct ahash_request *req)
{
struct crypto_async_request *async_req, *backlog;
struct bfin_crypto_crc_reqctx *ctx;
struct scatterlist *sg;
int ret = 0;
int nsg, i, j;
unsigned int nextlen;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&crc->lock, flags);
if (req)
ret = ahash_enqueue_request(&crc->queue, req);
if (crc->busy) {
spin_unlock_irqrestore(&crc->lock, flags);
return ret;
}
backlog = crypto_get_backlog(&crc->queue);
async_req = crypto_dequeue_request(&crc->queue);
if (async_req)
crc->busy = 1;
spin_unlock_irqrestore(&crc->lock, flags);
if (!async_req)
return ret;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ahash_request_cast(async_req);
crc->req = req;
ctx = ahash_request_ctx(req);
ctx->sg = NULL;
ctx->sg_buflen = 0;
ctx->sg_nents = 0;
dev_dbg(crc->dev, "handling new req, flag=%u, nbytes: %d\n",
ctx->flag, req->nbytes);
if (ctx->flag == CRC_CRYPTO_STATE_FINISH) {
if (ctx->bufnext_len == 0) {
crc->busy = 0;
return 0;
}
memset(ctx->bufnext + ctx->bufnext_len, 0,
CHKSUM_DIGEST_SIZE - ctx->bufnext_len);
} else {
if (ctx->bufnext_len + req->nbytes < CHKSUM_DIGEST_SIZE) {
memcpy(ctx->bufnext + ctx->bufnext_len,
sg_virt(req->src), req->nbytes);
ctx->bufnext_len += req->nbytes;
if (ctx->flag == CRC_CRYPTO_STATE_FINALUPDATE &&
ctx->bufnext_len) {
goto finish_update;
} else {
crc->busy = 0;
return 0;
}
}
if (ctx->bufnext_len) {
ctx->buflast_len = ctx->bufnext_len;
memcpy(ctx->buflast, ctx->bufnext, ctx->buflast_len);
nsg = ctx->sg_buflen ? 2 : 1;
sg_init_table(ctx->bufsl, nsg);
sg_set_buf(ctx->bufsl, ctx->buflast, ctx->buflast_len);
if (nsg > 1)
sg_chain(ctx->bufsl, nsg, req->src);
ctx->sg = ctx->bufsl;
} else
ctx->sg = req->src;
nsg = sg_nents(ctx->sg);
ctx->sg_nents = nsg;
ctx->sg_buflen = ctx->buflast_len + req->nbytes;
ctx->bufnext_len = ctx->sg_buflen % 4;
ctx->sg_buflen &= ~0x3;
if (ctx->bufnext_len) {
memset(ctx->bufnext, 0, CHKSUM_DIGEST_SIZE);
nextlen = ctx->bufnext_len;
for (i = nsg - 1; i >= 0; i--) {
sg = sg_get(ctx->sg, nsg, i);
j = min(nextlen, sg_dma_len(sg));
memcpy(ctx->bufnext + nextlen - j,
sg_virt(sg) + sg_dma_len(sg) - j, j);
if (j == sg_dma_len(sg))
ctx->sg_nents--;
nextlen -= j;
if (nextlen == 0)
break;
}
}
}
finish_update:
if (ctx->bufnext_len && (ctx->flag == CRC_CRYPTO_STATE_FINALUPDATE ||
ctx->flag == CRC_CRYPTO_STATE_FINISH))
ctx->sg_buflen += CHKSUM_DIGEST_SIZE;
writel(ctx->sg_buflen >> 2, &crc->regs->datacnt);
bfin_crypto_crc_config_dma(crc);
reg = readl(&crc->regs->control);
writel(reg | BLKEN, &crc->regs->control);
return -EINPROGRESS;
}
static int bfin_crypto_crc_update(struct ahash_request *req)
{
struct bfin_crypto_crc_reqctx *ctx = ahash_request_ctx(req);
if (!req->nbytes)
return 0;
dev_dbg(ctx->crc->dev, "crc_update\n");
ctx->total += req->nbytes;
ctx->flag = CRC_CRYPTO_STATE_UPDATE;
return bfin_crypto_crc_handle_queue(ctx->crc, req);
}
static int bfin_crypto_crc_final(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct bfin_crypto_crc_ctx *crc_ctx = crypto_ahash_ctx(tfm);
struct bfin_crypto_crc_reqctx *ctx = ahash_request_ctx(req);
dev_dbg(ctx->crc->dev, "crc_final\n");
ctx->flag = CRC_CRYPTO_STATE_FINISH;
crc_ctx->key = 0;
return bfin_crypto_crc_handle_queue(ctx->crc, req);
}
static int bfin_crypto_crc_finup(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct bfin_crypto_crc_ctx *crc_ctx = crypto_ahash_ctx(tfm);
struct bfin_crypto_crc_reqctx *ctx = ahash_request_ctx(req);
dev_dbg(ctx->crc->dev, "crc_finishupdate\n");
ctx->total += req->nbytes;
ctx->flag = CRC_CRYPTO_STATE_FINALUPDATE;
crc_ctx->key = 0;
return bfin_crypto_crc_handle_queue(ctx->crc, req);
}
static int bfin_crypto_crc_digest(struct ahash_request *req)
{
int ret;
ret = bfin_crypto_crc_init(req);
if (ret)
return ret;
return bfin_crypto_crc_finup(req);
}
static int bfin_crypto_crc_setkey(struct crypto_ahash *tfm, const u8 *key,
unsigned int keylen)
{
struct bfin_crypto_crc_ctx *crc_ctx = crypto_ahash_ctx(tfm);
dev_dbg(crc_ctx->crc->dev, "crc_setkey\n");
if (keylen != CHKSUM_DIGEST_SIZE) {
crypto_ahash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
crc_ctx->key = get_unaligned_le32(key);
return 0;
}
static int bfin_crypto_crc_cra_init(struct crypto_tfm *tfm)
{
struct bfin_crypto_crc_ctx *crc_ctx = crypto_tfm_ctx(tfm);
crc_ctx->key = 0;
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct bfin_crypto_crc_reqctx));
return 0;
}
static void bfin_crypto_crc_cra_exit(struct crypto_tfm *tfm)
{
}
static void bfin_crypto_crc_done_task(unsigned long data)
{
struct bfin_crypto_crc *crc = (struct bfin_crypto_crc *)data;
bfin_crypto_crc_handle_queue(crc, NULL);
}
static irqreturn_t bfin_crypto_crc_handler(int irq, void *dev_id)
{
struct bfin_crypto_crc *crc = dev_id;
u32 reg;
if (readl(&crc->regs->status) & DCNTEXP) {
writel(DCNTEXP, &crc->regs->status);
put_unaligned_le32(readl(&crc->regs->result),
crc->req->result);
reg = readl(&crc->regs->control);
writel(reg & ~BLKEN, &crc->regs->control);
crc->busy = 0;
if (crc->req->base.complete)
crc->req->base.complete(&crc->req->base, 0);
tasklet_schedule(&crc->done_task);
return IRQ_HANDLED;
} else
return IRQ_NONE;
}
static int bfin_crypto_crc_suspend(struct platform_device *pdev, pm_message_t state)
{
struct bfin_crypto_crc *crc = platform_get_drvdata(pdev);
int i = 100000;
while ((readl(&crc->regs->control) & BLKEN) && --i)
cpu_relax();
if (i == 0)
return -EBUSY;
return 0;
}
static int bfin_crypto_crc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct bfin_crypto_crc *crc;
unsigned int timeout = 100000;
int ret;
crc = devm_kzalloc(dev, sizeof(*crc), GFP_KERNEL);
if (!crc) {
dev_err(&pdev->dev, "fail to malloc bfin_crypto_crc\n");
return -ENOMEM;
}
crc->dev = dev;
INIT_LIST_HEAD(&crc->list);
spin_lock_init(&crc->lock);
tasklet_init(&crc->done_task, bfin_crypto_crc_done_task, (unsigned long)crc);
crypto_init_queue(&crc->queue, CRC_CCRYPTO_QUEUE_LENGTH);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "Cannot get IORESOURCE_MEM\n");
return -ENOENT;
}
crc->regs = devm_ioremap_resource(dev, res);
if (IS_ERR((void *)crc->regs)) {
dev_err(&pdev->dev, "Cannot map CRC IO\n");
return PTR_ERR((void *)crc->regs);
}
crc->irq = platform_get_irq(pdev, 0);
if (crc->irq < 0) {
dev_err(&pdev->dev, "No CRC DCNTEXP IRQ specified\n");
return -ENOENT;
}
ret = devm_request_irq(dev, crc->irq, bfin_crypto_crc_handler,
IRQF_SHARED, dev_name(dev), crc);
if (ret) {
dev_err(&pdev->dev, "Unable to request blackfin crc irq\n");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No CRC DMA channel specified\n");
return -ENOENT;
}
crc->dma_ch = res->start;
ret = request_dma(crc->dma_ch, dev_name(dev));
if (ret) {
dev_err(&pdev->dev, "Unable to attach Blackfin CRC DMA channel\n");
return ret;
}
crc->sg_cpu = dma_alloc_coherent(&pdev->dev, PAGE_SIZE, &crc->sg_dma, GFP_KERNEL);
if (crc->sg_cpu == NULL) {
ret = -ENOMEM;
goto out_error_dma;
}
crc->sg_mid_buf = (u8 *)(crc->sg_cpu + ((CRC_MAX_DMA_DESC + 1) << 1));
crc->sg_mid_dma = crc->sg_dma + sizeof(struct dma_desc_array)
* ((CRC_MAX_DMA_DESC + 1) << 1);
writel(0, &crc->regs->control);
crc->poly = (u32)pdev->dev.platform_data;
writel(crc->poly, &crc->regs->poly);
while (!(readl(&crc->regs->status) & LUTDONE) && (--timeout) > 0)
cpu_relax();
if (timeout == 0)
dev_info(&pdev->dev, "init crc poly timeout\n");
platform_set_drvdata(pdev, crc);
spin_lock(&crc_list.lock);
list_add(&crc->list, &crc_list.dev_list);
spin_unlock(&crc_list.lock);
if (list_is_singular(&crc_list.dev_list)) {
ret = crypto_register_ahash(&algs);
if (ret) {
dev_err(&pdev->dev,
"Can't register crypto ahash device\n");
goto out_error_dma;
}
}
dev_info(&pdev->dev, "initialized\n");
return 0;
out_error_dma:
if (crc->sg_cpu)
dma_free_coherent(&pdev->dev, PAGE_SIZE, crc->sg_cpu, crc->sg_dma);
free_dma(crc->dma_ch);
return ret;
}
static int bfin_crypto_crc_remove(struct platform_device *pdev)
{
struct bfin_crypto_crc *crc = platform_get_drvdata(pdev);
if (!crc)
return -ENODEV;
spin_lock(&crc_list.lock);
list_del(&crc->list);
spin_unlock(&crc_list.lock);
crypto_unregister_ahash(&algs);
tasklet_kill(&crc->done_task);
free_dma(crc->dma_ch);
return 0;
}
static int __init bfin_crypto_crc_mod_init(void)
{
int ret;
pr_info("Blackfin hardware CRC crypto driver\n");
INIT_LIST_HEAD(&crc_list.dev_list);
spin_lock_init(&crc_list.lock);
ret = platform_driver_register(&bfin_crypto_crc_driver);
if (ret) {
pr_err("unable to register driver\n");
return ret;
}
return 0;
}
static void __exit bfin_crypto_crc_mod_exit(void)
{
platform_driver_unregister(&bfin_crypto_crc_driver);
}
