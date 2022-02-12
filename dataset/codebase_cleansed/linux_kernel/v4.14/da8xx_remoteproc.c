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
davinci_clk_reset_assert(drproc->dsp_clk);
clk_disable(drproc->dsp_clk);
return 0;
}
static void da8xx_rproc_kick(struct rproc *rproc, int vqid)
{
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
writel(SYSCFG_CHIPSIG2, drproc->chipsig);
}
static int da8xx_rproc_get_internal_memories(struct platform_device *pdev,
struct da8xx_rproc *drproc)
{
static const char * const mem_names[] = {"l2sram", "l1pram", "l1dram"};
int num_mems = ARRAY_SIZE(mem_names);
struct device *dev = &pdev->dev;
struct resource *res;
int i;
drproc->mem = devm_kcalloc(dev, num_mems, sizeof(*drproc->mem),
GFP_KERNEL);
if (!drproc->mem)
return -ENOMEM;
for (i = 0; i < num_mems; i++) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
mem_names[i]);
drproc->mem[i].cpu_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(drproc->mem[i].cpu_addr)) {
dev_err(dev, "failed to parse and map %s memory\n",
mem_names[i]);
return PTR_ERR(drproc->mem[i].cpu_addr);
}
drproc->mem[i].bus_addr = res->start;
drproc->mem[i].dev_addr =
res->start & DA8XX_RPROC_LOCAL_ADDRESS_MASK;
drproc->mem[i].size = resource_size(res);
dev_dbg(dev, "memory %8s: bus addr %pa size 0x%x va %p da 0x%x\n",
mem_names[i], &drproc->mem[i].bus_addr,
drproc->mem[i].size, drproc->mem[i].cpu_addr,
drproc->mem[i].dev_addr);
}
drproc->num_mems = num_mems;
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
bootreg_res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"host1cfg");
bootreg = devm_ioremap_resource(dev, bootreg_res);
if (IS_ERR(bootreg))
return PTR_ERR(bootreg);
chipsig_res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"chipsig");
chipsig = devm_ioremap_resource(dev, chipsig_res);
if (IS_ERR(chipsig))
return PTR_ERR(chipsig);
dsp_clk = devm_clk_get(dev, NULL);
if (IS_ERR(dsp_clk)) {
dev_err(dev, "clk_get error: %ld\n", PTR_ERR(dsp_clk));
return PTR_ERR(dsp_clk);
}
if (dev->of_node) {
ret = of_reserved_mem_device_init(dev);
if (ret) {
dev_err(dev, "device does not have specific CMA pool: %d\n",
ret);
return ret;
}
}
rproc = rproc_alloc(dev, "dsp", &da8xx_rproc_ops, da8xx_fw_name,
sizeof(*drproc));
if (!rproc) {
ret = -ENOMEM;
goto free_mem;
}
drproc = rproc->priv;
drproc->rproc = rproc;
drproc->dsp_clk = dsp_clk;
rproc->has_iommu = false;
ret = da8xx_rproc_get_internal_memories(pdev, drproc);
if (ret)
goto free_rproc;
platform_set_drvdata(pdev, rproc);
ret = devm_request_threaded_irq(dev, irq, da8xx_rproc_callback,
handle_event, 0, "da8xx-remoteproc",
rproc);
if (ret) {
dev_err(dev, "devm_request_threaded_irq error: %d\n", ret);
goto free_rproc;
}
ret = davinci_clk_reset_assert(drproc->dsp_clk);
if (ret)
goto free_rproc;
drproc->chipsig = chipsig;
drproc->bootreg = bootreg;
drproc->ack_fxn = irq_data->chip->irq_ack;
drproc->irq_data = irq_data;
drproc->irq = irq;
ret = rproc_add(rproc);
if (ret) {
dev_err(dev, "rproc_add failed: %d\n", ret);
goto free_rproc;
}
return 0;
free_rproc:
rproc_free(rproc);
free_mem:
if (dev->of_node)
of_reserved_mem_device_release(dev);
return ret;
}
static int da8xx_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct da8xx_rproc *drproc = (struct da8xx_rproc *)rproc->priv;
struct device *dev = &pdev->dev;
disable_irq(drproc->irq);
rproc_del(rproc);
rproc_free(rproc);
if (dev->of_node)
of_reserved_mem_device_release(dev);
return 0;
}
