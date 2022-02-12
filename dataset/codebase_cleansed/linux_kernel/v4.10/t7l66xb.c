static int t7l66xb_mmc_enable(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
unsigned long flags;
u8 dev_ctl;
clk_prepare_enable(t7l66xb->clk32k);
spin_lock_irqsave(&t7l66xb->lock, flags);
dev_ctl = tmio_ioread8(t7l66xb->scr + SCR_DEV_CTL);
dev_ctl |= SCR_DEV_CTL_MMC;
tmio_iowrite8(dev_ctl, t7l66xb->scr + SCR_DEV_CTL);
spin_unlock_irqrestore(&t7l66xb->lock, flags);
tmio_core_mmc_enable(t7l66xb->scr + 0x200, 0,
t7l66xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static int t7l66xb_mmc_disable(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
unsigned long flags;
u8 dev_ctl;
spin_lock_irqsave(&t7l66xb->lock, flags);
dev_ctl = tmio_ioread8(t7l66xb->scr + SCR_DEV_CTL);
dev_ctl &= ~SCR_DEV_CTL_MMC;
tmio_iowrite8(dev_ctl, t7l66xb->scr + SCR_DEV_CTL);
spin_unlock_irqrestore(&t7l66xb->lock, flags);
clk_disable_unprepare(t7l66xb->clk32k);
return 0;
}
static void t7l66xb_mmc_pwr(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
tmio_core_mmc_pwr(t7l66xb->scr + 0x200, 0, state);
}
static void t7l66xb_mmc_clk_div(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
tmio_core_mmc_clk_div(t7l66xb->scr + 0x200, 0, state);
}
static void t7l66xb_irq(struct irq_desc *desc)
{
struct t7l66xb *t7l66xb = irq_desc_get_handler_data(desc);
unsigned int isr;
unsigned int i, irq_base;
irq_base = t7l66xb->irq_base;
while ((isr = tmio_ioread8(t7l66xb->scr + SCR_ISR) &
~tmio_ioread8(t7l66xb->scr + SCR_IMR)))
for (i = 0; i < T7L66XB_NR_IRQS; i++)
if (isr & (1 << i))
generic_handle_irq(irq_base + i);
}
static void t7l66xb_irq_mask(struct irq_data *data)
{
struct t7l66xb *t7l66xb = irq_data_get_irq_chip_data(data);
unsigned long flags;
u8 imr;
spin_lock_irqsave(&t7l66xb->lock, flags);
imr = tmio_ioread8(t7l66xb->scr + SCR_IMR);
imr |= 1 << (data->irq - t7l66xb->irq_base);
tmio_iowrite8(imr, t7l66xb->scr + SCR_IMR);
spin_unlock_irqrestore(&t7l66xb->lock, flags);
}
static void t7l66xb_irq_unmask(struct irq_data *data)
{
struct t7l66xb *t7l66xb = irq_data_get_irq_chip_data(data);
unsigned long flags;
u8 imr;
spin_lock_irqsave(&t7l66xb->lock, flags);
imr = tmio_ioread8(t7l66xb->scr + SCR_IMR);
imr &= ~(1 << (data->irq - t7l66xb->irq_base));
tmio_iowrite8(imr, t7l66xb->scr + SCR_IMR);
spin_unlock_irqrestore(&t7l66xb->lock, flags);
}
static void t7l66xb_attach_irq(struct platform_device *dev)
{
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
unsigned int irq, irq_base;
irq_base = t7l66xb->irq_base;
for (irq = irq_base; irq < irq_base + T7L66XB_NR_IRQS; irq++) {
irq_set_chip_and_handler(irq, &t7l66xb_chip, handle_level_irq);
irq_set_chip_data(irq, t7l66xb);
}
irq_set_irq_type(t7l66xb->irq, IRQ_TYPE_EDGE_FALLING);
irq_set_chained_handler_and_data(t7l66xb->irq, t7l66xb_irq, t7l66xb);
}
static void t7l66xb_detach_irq(struct platform_device *dev)
{
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
unsigned int irq, irq_base;
irq_base = t7l66xb->irq_base;
irq_set_chained_handler_and_data(t7l66xb->irq, NULL, NULL);
for (irq = irq_base; irq < irq_base + T7L66XB_NR_IRQS; irq++) {
irq_set_chip(irq, NULL);
irq_set_chip_data(irq, NULL);
}
}
static int t7l66xb_suspend(struct platform_device *dev, pm_message_t state)
{
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
struct t7l66xb_platform_data *pdata = dev_get_platdata(&dev->dev);
if (pdata && pdata->suspend)
pdata->suspend(dev);
clk_disable_unprepare(t7l66xb->clk48m);
return 0;
}
static int t7l66xb_resume(struct platform_device *dev)
{
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
struct t7l66xb_platform_data *pdata = dev_get_platdata(&dev->dev);
clk_prepare_enable(t7l66xb->clk48m);
if (pdata && pdata->resume)
pdata->resume(dev);
tmio_core_mmc_enable(t7l66xb->scr + 0x200, 0,
t7l66xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static int t7l66xb_probe(struct platform_device *dev)
{
struct t7l66xb_platform_data *pdata = dev_get_platdata(&dev->dev);
struct t7l66xb *t7l66xb;
struct resource *iomem, *rscr;
int ret;
if (!pdata)
return -EINVAL;
iomem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!iomem)
return -EINVAL;
t7l66xb = kzalloc(sizeof *t7l66xb, GFP_KERNEL);
if (!t7l66xb)
return -ENOMEM;
spin_lock_init(&t7l66xb->lock);
platform_set_drvdata(dev, t7l66xb);
ret = platform_get_irq(dev, 0);
if (ret >= 0)
t7l66xb->irq = ret;
else
goto err_noirq;
t7l66xb->irq_base = pdata->irq_base;
t7l66xb->clk32k = clk_get(&dev->dev, "CLK_CK32K");
if (IS_ERR(t7l66xb->clk32k)) {
ret = PTR_ERR(t7l66xb->clk32k);
goto err_clk32k_get;
}
t7l66xb->clk48m = clk_get(&dev->dev, "CLK_CK48M");
if (IS_ERR(t7l66xb->clk48m)) {
ret = PTR_ERR(t7l66xb->clk48m);
goto err_clk48m_get;
}
rscr = &t7l66xb->rscr;
rscr->name = "t7l66xb-core";
rscr->start = iomem->start;
rscr->end = iomem->start + 0xff;
rscr->flags = IORESOURCE_MEM;
ret = request_resource(iomem, rscr);
if (ret)
goto err_request_scr;
t7l66xb->scr = ioremap(rscr->start, resource_size(rscr));
if (!t7l66xb->scr) {
ret = -ENOMEM;
goto err_ioremap;
}
clk_prepare_enable(t7l66xb->clk48m);
if (pdata->enable)
pdata->enable(dev);
tmio_iowrite8(0xbf, t7l66xb->scr + SCR_IMR);
printk(KERN_INFO "%s rev %d @ 0x%08lx, irq %d\n",
dev->name, tmio_ioread8(t7l66xb->scr + SCR_REVID),
(unsigned long)iomem->start, t7l66xb->irq);
t7l66xb_attach_irq(dev);
t7l66xb_cells[T7L66XB_CELL_NAND].platform_data = pdata->nand_data;
t7l66xb_cells[T7L66XB_CELL_NAND].pdata_size = sizeof(*pdata->nand_data);
ret = mfd_add_devices(&dev->dev, dev->id,
t7l66xb_cells, ARRAY_SIZE(t7l66xb_cells),
iomem, t7l66xb->irq_base, NULL);
if (!ret)
return 0;
t7l66xb_detach_irq(dev);
iounmap(t7l66xb->scr);
err_ioremap:
release_resource(&t7l66xb->rscr);
err_request_scr:
clk_put(t7l66xb->clk48m);
err_clk48m_get:
clk_put(t7l66xb->clk32k);
err_clk32k_get:
err_noirq:
kfree(t7l66xb);
return ret;
}
static int t7l66xb_remove(struct platform_device *dev)
{
struct t7l66xb_platform_data *pdata = dev_get_platdata(&dev->dev);
struct t7l66xb *t7l66xb = platform_get_drvdata(dev);
int ret;
ret = pdata->disable(dev);
clk_disable_unprepare(t7l66xb->clk48m);
clk_put(t7l66xb->clk48m);
clk_disable_unprepare(t7l66xb->clk32k);
clk_put(t7l66xb->clk32k);
t7l66xb_detach_irq(dev);
iounmap(t7l66xb->scr);
release_resource(&t7l66xb->rscr);
mfd_remove_devices(&dev->dev);
kfree(t7l66xb);
return ret;
}
