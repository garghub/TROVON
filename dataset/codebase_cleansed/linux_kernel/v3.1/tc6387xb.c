static int tc6387xb_suspend(struct platform_device *dev, pm_message_t state)
{
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
struct tc6387xb_platform_data *pdata = dev->dev.platform_data;
if (pdata && pdata->suspend)
pdata->suspend(dev);
clk_disable(tc6387xb->clk32k);
return 0;
}
static int tc6387xb_resume(struct platform_device *dev)
{
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
struct tc6387xb_platform_data *pdata = dev->dev.platform_data;
clk_enable(tc6387xb->clk32k);
if (pdata && pdata->resume)
pdata->resume(dev);
tmio_core_mmc_resume(tc6387xb->scr + 0x200, 0,
tc6387xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static void tc6387xb_mmc_pwr(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
tmio_core_mmc_pwr(tc6387xb->scr + 0x200, 0, state);
}
static void tc6387xb_mmc_clk_div(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
tmio_core_mmc_clk_div(tc6387xb->scr + 0x200, 0, state);
}
static int tc6387xb_mmc_enable(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
clk_enable(tc6387xb->clk32k);
tmio_core_mmc_enable(tc6387xb->scr + 0x200, 0,
tc6387xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static int tc6387xb_mmc_disable(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
clk_disable(tc6387xb->clk32k);
return 0;
}
static int __devinit tc6387xb_probe(struct platform_device *dev)
{
struct tc6387xb_platform_data *pdata = dev->dev.platform_data;
struct resource *iomem, *rscr;
struct clk *clk32k;
struct tc6387xb *tc6387xb;
int irq, ret;
iomem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!iomem) {
return -EINVAL;
}
tc6387xb = kzalloc(sizeof *tc6387xb, GFP_KERNEL);
if (!tc6387xb)
return -ENOMEM;
ret = platform_get_irq(dev, 0);
if (ret >= 0)
irq = ret;
else
goto err_no_irq;
clk32k = clk_get(&dev->dev, "CLK_CK32K");
if (IS_ERR(clk32k)) {
ret = PTR_ERR(clk32k);
goto err_no_clk;
}
rscr = &tc6387xb->rscr;
rscr->name = "tc6387xb-core";
rscr->start = iomem->start;
rscr->end = iomem->start + 0xff;
rscr->flags = IORESOURCE_MEM;
ret = request_resource(iomem, rscr);
if (ret)
goto err_resource;
tc6387xb->scr = ioremap(rscr->start, resource_size(rscr));
if (!tc6387xb->scr) {
ret = -ENOMEM;
goto err_ioremap;
}
tc6387xb->clk32k = clk32k;
platform_set_drvdata(dev, tc6387xb);
if (pdata && pdata->enable)
pdata->enable(dev);
printk(KERN_INFO "Toshiba tc6387xb initialised\n");
ret = mfd_add_devices(&dev->dev, dev->id, tc6387xb_cells,
ARRAY_SIZE(tc6387xb_cells), iomem, irq);
if (!ret)
return 0;
iounmap(tc6387xb->scr);
err_ioremap:
release_resource(&tc6387xb->rscr);
err_resource:
clk_put(clk32k);
err_no_clk:
err_no_irq:
kfree(tc6387xb);
return ret;
}
static int __devexit tc6387xb_remove(struct platform_device *dev)
{
struct tc6387xb *tc6387xb = platform_get_drvdata(dev);
mfd_remove_devices(&dev->dev);
iounmap(tc6387xb->scr);
release_resource(&tc6387xb->rscr);
clk_disable(tc6387xb->clk32k);
clk_put(tc6387xb->clk32k);
platform_set_drvdata(dev, NULL);
kfree(tc6387xb);
return 0;
}
static int __init tc6387xb_init(void)
{
return platform_driver_register(&tc6387xb_platform_driver);
}
static void __exit tc6387xb_exit(void)
{
platform_driver_unregister(&tc6387xb_platform_driver);
}
