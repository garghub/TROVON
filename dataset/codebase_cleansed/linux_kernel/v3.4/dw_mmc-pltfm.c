static int dw_mci_pltfm_probe(struct platform_device *pdev)
{
struct dw_mci *host;
struct resource *regs;
int ret;
host = kzalloc(sizeof(struct dw_mci), GFP_KERNEL);
if (!host)
return -ENOMEM;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
ret = -ENXIO;
goto err_free;
}
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0) {
ret = host->irq;
goto err_free;
}
host->dev = pdev->dev;
host->irq_flags = 0;
host->pdata = pdev->dev.platform_data;
ret = -ENOMEM;
host->regs = ioremap(regs->start, resource_size(regs));
if (!host->regs)
goto err_free;
platform_set_drvdata(pdev, host);
ret = dw_mci_probe(host);
if (ret)
goto err_out;
return ret;
err_out:
iounmap(host->regs);
err_free:
kfree(host);
return ret;
}
static int __exit dw_mci_pltfm_remove(struct platform_device *pdev)
{
struct dw_mci *host = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
dw_mci_remove(host);
iounmap(host->regs);
kfree(host);
return 0;
}
static int dw_mci_pltfm_suspend(struct device *dev)
{
int ret;
struct dw_mci *host = dev_get_drvdata(dev);
ret = dw_mci_suspend(host);
if (ret)
return ret;
return 0;
}
static int dw_mci_pltfm_resume(struct device *dev)
{
int ret;
struct dw_mci *host = dev_get_drvdata(dev);
ret = dw_mci_resume(host);
if (ret)
return ret;
return 0;
}
static int __init dw_mci_init(void)
{
return platform_driver_probe(&dw_mci_pltfm_driver, dw_mci_pltfm_probe);
}
static void __exit dw_mci_exit(void)
{
platform_driver_unregister(&dw_mci_pltfm_driver);
}
