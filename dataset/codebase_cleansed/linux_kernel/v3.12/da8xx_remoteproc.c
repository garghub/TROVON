static irqreturn_t handle_event(int irq, void *p)
{
struct rproc *rproc = (struct rproc *)p;
rproc_vq_interrupt(rproc, 0);
rproc_vq_interrupt(rproc, 1);
return IRQ_HANDLED;
}
static irqreturn_t da8xx_rproc_callback(int irq, void *p)
{
struct rproc *rproc = (struct rproc *)p;
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
u32 chipsig;
chipsig = readl(drproc->chipsig);
if (chipsig & SYSCFG_CHIPSIG0) {
writel(SYSCFG_CHIPSIG0, drproc->chipsig + 4);
drproc->ack_fxn(drproc->irq_data);
return IRQ_WAKE_THREAD;
}
return IRQ_HANDLED;
}
static int da8xx_rproc_start(struct rproc *rproc)
{
struct device *dev = rproc->dev.parent;
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
struct clk *dsp_clk = drproc->dsp_clk;
if (rproc->bootaddr & 0x3ff) {
dev_err(dev, "invalid boot address: must be aligned to 1KB\n");
return -EINVAL;
}
writel(rproc->bootaddr, drproc->bootreg);
clk_enable(dsp_clk);
davinci_clk_reset_deassert(dsp_clk);
return 0;
}
static int da8xx_rproc_stop(struct rproc *rproc)
{
struct da8xx_rproc *drproc = rproc->priv;
clk_disable(drproc->dsp_clk);
return 0;
}
static void da8xx_rproc_kick(struct rproc *rproc, int vqid)
{
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
writel(SYSCFG_CHIPSIG2, drproc->chipsig);
}
static int reset_assert(struct device *dev)
{
struct clk *dsp_clk;
dsp_clk = clk_get(dev, NULL);
if (IS_ERR(dsp_clk)) {
dev_err(dev, "clk_get error: %ld\n", PTR_ERR(dsp_clk));
return PTR_ERR(dsp_clk);
}
davinci_clk_reset_assert(dsp_clk);
clk_put(dsp_clk);
return 0;
}
static int da8xx_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct da8xx_rproc *drproc;
struct rproc *rproc;
struct irq_data *irq_data;
struct resource *bootreg_res;
struct resource *chipsig_res;
struct clk *dsp_clk;
void __iomem *chipsig;
void __iomem *bootreg;
int irq;
int ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "platform_get_irq(pdev, 0) error: %d\n", irq);
return irq;
}
irq_data = irq_get_irq_data(irq);
if (!irq_data) {
dev_err(dev, "irq_get_irq_data(%d): NULL\n", irq);
return -EINVAL;
}
bootreg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!bootreg_res) {
dev_err(dev,
"platform_get_resource(IORESOURCE_MEM, 0): NULL\n");
return -EADDRNOTAVAIL;
}
chipsig_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!chipsig_res) {
dev_err(dev,
"platform_get_resource(IORESOURCE_MEM, 1): NULL\n");
return -EADDRNOTAVAIL;
}
bootreg = devm_ioremap_resource(dev, bootreg_res);
if (IS_ERR(bootreg))
return PTR_ERR(bootreg);
chipsig = devm_ioremap_resource(dev, chipsig_res);
if (IS_ERR(chipsig))
return PTR_ERR(chipsig);
dsp_clk = devm_clk_get(dev, NULL);
if (IS_ERR(dsp_clk)) {
dev_err(dev, "clk_get error: %ld\n", PTR_ERR(dsp_clk));
return PTR_ERR(dsp_clk);
}
rproc = rproc_alloc(dev, "dsp", &da8xx_rproc_ops, da8xx_fw_name,
sizeof(*drproc));
if (!rproc)
return -ENOMEM;
drproc = rproc->priv;
drproc->rproc = rproc;
platform_set_drvdata(pdev, rproc);
ret = devm_request_threaded_irq(dev, irq, da8xx_rproc_callback,
handle_event, 0, "da8xx-remoteproc",
rproc);
if (ret) {
dev_err(dev, "devm_request_threaded_irq error: %d\n", ret);
goto free_rproc;
}
ret = reset_assert(dev);
if (ret)
goto free_rproc;
drproc->chipsig = chipsig;
drproc->bootreg = bootreg;
drproc->ack_fxn = irq_data->chip->irq_ack;
drproc->irq_data = irq_data;
drproc->irq = irq;
drproc->dsp_clk = dsp_clk;
ret = rproc_add(rproc);
if (ret) {
dev_err(dev, "rproc_add failed: %d\n", ret);
goto free_rproc;
}
return 0;
free_rproc:
rproc_put(rproc);
return ret;
}
static int da8xx_rproc_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rproc *rproc = platform_get_drvdata(pdev);
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
reset_assert(dev);
disable_irq(drproc->irq);
devm_clk_put(dev, drproc->dsp_clk);
rproc_del(rproc);
rproc_put(rproc);
return 0;
}
