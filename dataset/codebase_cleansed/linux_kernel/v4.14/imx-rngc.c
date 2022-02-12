static inline void imx_rngc_irq_mask_clear(struct imx_rngc *rngc)
{
u32 ctrl, cmd;
ctrl = readl(rngc->base + RNGC_CONTROL);
ctrl |= RNGC_CTRL_MASK_DONE | RNGC_CTRL_MASK_ERROR;
writel(ctrl, rngc->base + RNGC_CONTROL);
cmd = readl(rngc->base + RNGC_COMMAND);
cmd |= RNGC_CMD_CLR_INT | RNGC_CMD_CLR_ERR;
writel(cmd, rngc->base + RNGC_COMMAND);
}
static inline void imx_rngc_irq_unmask(struct imx_rngc *rngc)
{
u32 ctrl;
ctrl = readl(rngc->base + RNGC_CONTROL);
ctrl &= ~(RNGC_CTRL_MASK_DONE | RNGC_CTRL_MASK_ERROR);
writel(ctrl, rngc->base + RNGC_CONTROL);
}
static int imx_rngc_self_test(struct imx_rngc *rngc)
{
u32 cmd;
int ret;
imx_rngc_irq_unmask(rngc);
cmd = readl(rngc->base + RNGC_COMMAND);
writel(cmd | RNGC_CMD_SELF_TEST, rngc->base + RNGC_COMMAND);
ret = wait_for_completion_timeout(&rngc->rng_op_done, RNGC_TIMEOUT);
if (!ret) {
imx_rngc_irq_mask_clear(rngc);
return -ETIMEDOUT;
}
if (rngc->err_reg != 0)
return -EIO;
return 0;
}
static int imx_rngc_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
struct imx_rngc *rngc = container_of(rng, struct imx_rngc, rng);
unsigned int status;
unsigned int level;
int retval = 0;
while (max >= sizeof(u32)) {
status = readl(rngc->base + RNGC_STATUS);
if (status & RNGC_STATUS_ERROR)
break;
level = (status & RNGC_STATUS_FIFO_LEVEL_MASK) >>
RNGC_STATUS_FIFO_LEVEL_SHIFT;
if (level) {
*(u32 *)data = readl(rngc->base + RNGC_FIFO);
retval += sizeof(u32);
data += sizeof(u32);
max -= sizeof(u32);
}
}
return retval ? retval : -EIO;
}
static irqreturn_t imx_rngc_irq(int irq, void *priv)
{
struct imx_rngc *rngc = (struct imx_rngc *)priv;
u32 status;
status = readl(rngc->base + RNGC_STATUS);
rngc->err_reg = readl(rngc->base + RNGC_ERROR);
imx_rngc_irq_mask_clear(rngc);
if (status & (RNGC_STATUS_SEED_DONE | RNGC_STATUS_ST_DONE))
complete(&rngc->rng_op_done);
return IRQ_HANDLED;
}
static int imx_rngc_init(struct hwrng *rng)
{
struct imx_rngc *rngc = container_of(rng, struct imx_rngc, rng);
u32 cmd;
int ret;
cmd = readl(rngc->base + RNGC_COMMAND);
writel(cmd | RNGC_CMD_CLR_ERR, rngc->base + RNGC_COMMAND);
do {
imx_rngc_irq_unmask(rngc);
cmd = readl(rngc->base + RNGC_COMMAND);
writel(cmd | RNGC_CMD_SEED, rngc->base + RNGC_COMMAND);
ret = wait_for_completion_timeout(&rngc->rng_op_done,
RNGC_TIMEOUT);
if (!ret) {
imx_rngc_irq_mask_clear(rngc);
return -ETIMEDOUT;
}
} while (rngc->err_reg == RNGC_ERROR_STATUS_STAT_ERR);
return rngc->err_reg ? -EIO : 0;
}
static int imx_rngc_probe(struct platform_device *pdev)
{
struct imx_rngc *rngc;
struct resource *res;
int ret;
int irq;
rngc = devm_kzalloc(&pdev->dev, sizeof(*rngc), GFP_KERNEL);
if (!rngc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rngc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rngc->base))
return PTR_ERR(rngc->base);
rngc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rngc->clk)) {
dev_err(&pdev->dev, "Can not get rng_clk\n");
return PTR_ERR(rngc->clk);
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "Couldn't get irq %d\n", irq);
return irq;
}
ret = clk_prepare_enable(rngc->clk);
if (ret)
return ret;
ret = devm_request_irq(&pdev->dev,
irq, imx_rngc_irq, 0, pdev->name, (void *)rngc);
if (ret) {
dev_err(rngc->dev, "Can't get interrupt working.\n");
goto err;
}
init_completion(&rngc->rng_op_done);
rngc->rng.name = pdev->name;
rngc->rng.init = imx_rngc_init;
rngc->rng.read = imx_rngc_read;
rngc->dev = &pdev->dev;
platform_set_drvdata(pdev, rngc);
imx_rngc_irq_mask_clear(rngc);
if (self_test) {
ret = imx_rngc_self_test(rngc);
if (ret) {
dev_err(rngc->dev, "FSL RNGC self test failed.\n");
goto err;
}
}
ret = hwrng_register(&rngc->rng);
if (ret) {
dev_err(&pdev->dev, "FSL RNGC registering failed (%d)\n", ret);
goto err;
}
dev_info(&pdev->dev, "Freescale RNGC registered.\n");
return 0;
err:
clk_disable_unprepare(rngc->clk);
return ret;
}
static int __exit imx_rngc_remove(struct platform_device *pdev)
{
struct imx_rngc *rngc = platform_get_drvdata(pdev);
hwrng_unregister(&rngc->rng);
clk_disable_unprepare(rngc->clk);
return 0;
}
static int imx_rngc_suspend(struct device *dev)
{
struct imx_rngc *rngc = dev_get_drvdata(dev);
clk_disable_unprepare(rngc->clk);
return 0;
}
static int imx_rngc_resume(struct device *dev)
{
struct imx_rngc *rngc = dev_get_drvdata(dev);
clk_prepare_enable(rngc->clk);
return 0;
}
