static void mv_cesa_dequeue_req_unlocked(struct mv_cesa_engine *engine)
{
struct crypto_async_request *req, *backlog;
struct mv_cesa_ctx *ctx;
spin_lock_bh(&cesa_dev->lock);
backlog = crypto_get_backlog(&cesa_dev->queue);
req = crypto_dequeue_request(&cesa_dev->queue);
engine->req = req;
spin_unlock_bh(&cesa_dev->lock);
if (!req)
return;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
ctx = crypto_tfm_ctx(req->tfm);
ctx->ops->prepare(req, engine);
ctx->ops->step(req);
}
static irqreturn_t mv_cesa_int(int irq, void *priv)
{
struct mv_cesa_engine *engine = priv;
struct crypto_async_request *req;
struct mv_cesa_ctx *ctx;
u32 status, mask;
irqreturn_t ret = IRQ_NONE;
while (true) {
int res;
mask = mv_cesa_get_int_mask(engine);
status = readl(engine->regs + CESA_SA_INT_STATUS);
if (!(status & mask))
break;
writel(~status, engine->regs + CESA_SA_FPGA_INT_STATUS);
writel(~status, engine->regs + CESA_SA_INT_STATUS);
ret = IRQ_HANDLED;
spin_lock_bh(&engine->lock);
req = engine->req;
spin_unlock_bh(&engine->lock);
if (req) {
ctx = crypto_tfm_ctx(req->tfm);
res = ctx->ops->process(req, status & mask);
if (res != -EINPROGRESS) {
spin_lock_bh(&engine->lock);
engine->req = NULL;
mv_cesa_dequeue_req_unlocked(engine);
spin_unlock_bh(&engine->lock);
ctx->ops->cleanup(req);
local_bh_disable();
req->complete(req, res);
local_bh_enable();
} else {
ctx->ops->step(req);
}
}
}
return ret;
}
int mv_cesa_queue_req(struct crypto_async_request *req)
{
int ret;
int i;
spin_lock_bh(&cesa_dev->lock);
ret = crypto_enqueue_request(&cesa_dev->queue, req);
spin_unlock_bh(&cesa_dev->lock);
if (ret != -EINPROGRESS)
return ret;
for (i = 0; i < cesa_dev->caps->nengines; i++) {
spin_lock_bh(&cesa_dev->engines[i].lock);
if (!cesa_dev->engines[i].req)
mv_cesa_dequeue_req_unlocked(&cesa_dev->engines[i]);
spin_unlock_bh(&cesa_dev->engines[i].lock);
}
return -EINPROGRESS;
}
static int mv_cesa_add_algs(struct mv_cesa_dev *cesa)
{
int ret;
int i, j;
for (i = 0; i < cesa->caps->ncipher_algs; i++) {
ret = crypto_register_alg(cesa->caps->cipher_algs[i]);
if (ret)
goto err_unregister_crypto;
}
for (i = 0; i < cesa->caps->nahash_algs; i++) {
ret = crypto_register_ahash(cesa->caps->ahash_algs[i]);
if (ret)
goto err_unregister_ahash;
}
return 0;
err_unregister_ahash:
for (j = 0; j < i; j++)
crypto_unregister_ahash(cesa->caps->ahash_algs[j]);
i = cesa->caps->ncipher_algs;
err_unregister_crypto:
for (j = 0; j < i; j++)
crypto_unregister_alg(cesa->caps->cipher_algs[j]);
return ret;
}
static void mv_cesa_remove_algs(struct mv_cesa_dev *cesa)
{
int i;
for (i = 0; i < cesa->caps->nahash_algs; i++)
crypto_unregister_ahash(cesa->caps->ahash_algs[i]);
for (i = 0; i < cesa->caps->ncipher_algs; i++)
crypto_unregister_alg(cesa->caps->cipher_algs[i]);
}
static void
mv_cesa_conf_mbus_windows(struct mv_cesa_engine *engine,
const struct mbus_dram_target_info *dram)
{
void __iomem *iobase = engine->regs;
int i;
for (i = 0; i < 4; i++) {
writel(0, iobase + CESA_TDMA_WINDOW_CTRL(i));
writel(0, iobase + CESA_TDMA_WINDOW_BASE(i));
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
writel(((cs->size - 1) & 0xffff0000) |
(cs->mbus_attr << 8) |
(dram->mbus_dram_target_id << 4) | 1,
iobase + CESA_TDMA_WINDOW_CTRL(i));
writel(cs->base, iobase + CESA_TDMA_WINDOW_BASE(i));
}
}
static int mv_cesa_dev_dma_init(struct mv_cesa_dev *cesa)
{
struct device *dev = cesa->dev;
struct mv_cesa_dev_dma *dma;
if (!cesa->caps->has_tdma)
return 0;
dma = devm_kzalloc(dev, sizeof(*dma), GFP_KERNEL);
if (!dma)
return -ENOMEM;
dma->tdma_desc_pool = dmam_pool_create("tdma_desc", dev,
sizeof(struct mv_cesa_tdma_desc),
16, 0);
if (!dma->tdma_desc_pool)
return -ENOMEM;
dma->op_pool = dmam_pool_create("cesa_op", dev,
sizeof(struct mv_cesa_op_ctx), 16, 0);
if (!dma->op_pool)
return -ENOMEM;
dma->cache_pool = dmam_pool_create("cesa_cache", dev,
CESA_MAX_HASH_BLOCK_SIZE, 1, 0);
if (!dma->cache_pool)
return -ENOMEM;
dma->padding_pool = dmam_pool_create("cesa_padding", dev, 72, 1, 0);
if (!dma->cache_pool)
return -ENOMEM;
cesa->dma = dma;
return 0;
}
static int mv_cesa_get_sram(struct platform_device *pdev, int idx)
{
struct mv_cesa_dev *cesa = platform_get_drvdata(pdev);
struct mv_cesa_engine *engine = &cesa->engines[idx];
const char *res_name = "sram";
struct resource *res;
engine->pool = of_gen_pool_get(cesa->dev->of_node,
"marvell,crypto-srams", idx);
if (engine->pool) {
engine->sram = gen_pool_dma_alloc(engine->pool,
cesa->sram_size,
&engine->sram_dma);
if (engine->sram)
return 0;
engine->pool = NULL;
return -ENOMEM;
}
if (cesa->caps->nengines > 1) {
if (!idx)
res_name = "sram0";
else
res_name = "sram1";
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
res_name);
if (!res || resource_size(res) < cesa->sram_size)
return -EINVAL;
engine->sram = devm_ioremap_resource(cesa->dev, res);
if (IS_ERR(engine->sram))
return PTR_ERR(engine->sram);
engine->sram_dma = phys_to_dma(cesa->dev,
(phys_addr_t)res->start);
return 0;
}
static void mv_cesa_put_sram(struct platform_device *pdev, int idx)
{
struct mv_cesa_dev *cesa = platform_get_drvdata(pdev);
struct mv_cesa_engine *engine = &cesa->engines[idx];
if (!engine->pool)
return;
gen_pool_free(engine->pool, (unsigned long)engine->sram,
cesa->sram_size);
}
static int mv_cesa_probe(struct platform_device *pdev)
{
const struct mv_cesa_caps *caps = &orion_caps;
const struct mbus_dram_target_info *dram;
const struct of_device_id *match;
struct device *dev = &pdev->dev;
struct mv_cesa_dev *cesa;
struct mv_cesa_engine *engines;
struct resource *res;
int irq, ret, i;
u32 sram_size;
if (cesa_dev) {
dev_err(&pdev->dev, "Only one CESA device authorized\n");
return -EEXIST;
}
if (dev->of_node) {
match = of_match_node(mv_cesa_of_match_table, dev->of_node);
if (!match || !match->data)
return -ENOTSUPP;
caps = match->data;
}
if ((caps == &orion_caps || caps == &kirkwood_caps) && !allhwsupport)
return -ENOTSUPP;
cesa = devm_kzalloc(dev, sizeof(*cesa), GFP_KERNEL);
if (!cesa)
return -ENOMEM;
cesa->caps = caps;
cesa->dev = dev;
sram_size = CESA_SA_DEFAULT_SRAM_SIZE;
of_property_read_u32(cesa->dev->of_node, "marvell,crypto-sram-size",
&sram_size);
if (sram_size < CESA_SA_MIN_SRAM_SIZE)
sram_size = CESA_SA_MIN_SRAM_SIZE;
cesa->sram_size = sram_size;
cesa->engines = devm_kzalloc(dev, caps->nengines * sizeof(*engines),
GFP_KERNEL);
if (!cesa->engines)
return -ENOMEM;
spin_lock_init(&cesa->lock);
crypto_init_queue(&cesa->queue, 50);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "regs");
cesa->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(cesa->regs))
return -ENOMEM;
ret = mv_cesa_dev_dma_init(cesa);
if (ret)
return ret;
dram = mv_mbus_dram_info_nooverlap();
platform_set_drvdata(pdev, cesa);
for (i = 0; i < caps->nengines; i++) {
struct mv_cesa_engine *engine = &cesa->engines[i];
char res_name[7];
engine->id = i;
spin_lock_init(&engine->lock);
ret = mv_cesa_get_sram(pdev, i);
if (ret)
goto err_cleanup;
irq = platform_get_irq(pdev, i);
if (irq < 0) {
ret = irq;
goto err_cleanup;
}
snprintf(res_name, sizeof(res_name), "cesa%d", i);
engine->clk = devm_clk_get(dev, res_name);
if (IS_ERR(engine->clk)) {
engine->clk = devm_clk_get(dev, NULL);
if (IS_ERR(engine->clk))
engine->clk = NULL;
}
snprintf(res_name, sizeof(res_name), "cesaz%d", i);
engine->zclk = devm_clk_get(dev, res_name);
if (IS_ERR(engine->zclk))
engine->zclk = NULL;
ret = clk_prepare_enable(engine->clk);
if (ret)
goto err_cleanup;
ret = clk_prepare_enable(engine->zclk);
if (ret)
goto err_cleanup;
engine->regs = cesa->regs + CESA_ENGINE_OFF(i);
if (dram && cesa->caps->has_tdma)
mv_cesa_conf_mbus_windows(&cesa->engines[i], dram);
writel(0, cesa->engines[i].regs + CESA_SA_INT_STATUS);
writel(CESA_SA_CFG_STOP_DIG_ERR,
cesa->engines[i].regs + CESA_SA_CFG);
writel(engine->sram_dma & CESA_SA_SRAM_MSK,
cesa->engines[i].regs + CESA_SA_DESC_P0);
ret = devm_request_threaded_irq(dev, irq, NULL, mv_cesa_int,
IRQF_ONESHOT,
dev_name(&pdev->dev),
&cesa->engines[i]);
if (ret)
goto err_cleanup;
}
cesa_dev = cesa;
ret = mv_cesa_add_algs(cesa);
if (ret) {
cesa_dev = NULL;
goto err_cleanup;
}
dev_info(dev, "CESA device successfully registered\n");
return 0;
err_cleanup:
for (i = 0; i < caps->nengines; i++) {
clk_disable_unprepare(cesa->engines[i].zclk);
clk_disable_unprepare(cesa->engines[i].clk);
mv_cesa_put_sram(pdev, i);
}
return ret;
}
static int mv_cesa_remove(struct platform_device *pdev)
{
struct mv_cesa_dev *cesa = platform_get_drvdata(pdev);
int i;
mv_cesa_remove_algs(cesa);
for (i = 0; i < cesa->caps->nengines; i++) {
clk_disable_unprepare(cesa->engines[i].zclk);
clk_disable_unprepare(cesa->engines[i].clk);
mv_cesa_put_sram(pdev, i);
}
return 0;
}
