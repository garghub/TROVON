static int __devinit sdhci_pltfm_probe(struct platform_device *pdev)
{
const struct platform_device_id *platid = platform_get_device_id(pdev);
struct sdhci_pltfm_data *pdata;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct resource *iomem;
int ret;
if (platid && platid->driver_data)
pdata = (void *)platid->driver_data;
else
pdata = pdev->dev.platform_data;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem) {
ret = -ENOMEM;
goto err;
}
if (resource_size(iomem) < 0x100)
dev_err(&pdev->dev, "Invalid iomem size. You may "
"experience problems.\n");
if (pdev->dev.parent != &platform_bus)
host = sdhci_alloc_host(pdev->dev.parent, sizeof(*pltfm_host));
else
host = sdhci_alloc_host(&pdev->dev, sizeof(*pltfm_host));
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto err;
}
pltfm_host = sdhci_priv(host);
host->hw_name = "platform";
if (pdata && pdata->ops)
host->ops = pdata->ops;
else
host->ops = &sdhci_pltfm_ops;
if (pdata)
host->quirks = pdata->quirks;
host->irq = platform_get_irq(pdev, 0);
if (!request_mem_region(iomem->start, resource_size(iomem),
mmc_hostname(host->mmc))) {
dev_err(&pdev->dev, "cannot request region\n");
ret = -EBUSY;
goto err_request;
}
host->ioaddr = ioremap(iomem->start, resource_size(iomem));
if (!host->ioaddr) {
dev_err(&pdev->dev, "failed to remap registers\n");
ret = -ENOMEM;
goto err_remap;
}
if (pdata && pdata->init) {
ret = pdata->init(host, pdata);
if (ret)
goto err_plat_init;
}
ret = sdhci_add_host(host);
if (ret)
goto err_add_host;
platform_set_drvdata(pdev, host);
return 0;
err_add_host:
if (pdata && pdata->exit)
pdata->exit(host);
err_plat_init:
iounmap(host->ioaddr);
err_remap:
release_mem_region(iomem->start, resource_size(iomem));
err_request:
sdhci_free_host(host);
err:
printk(KERN_ERR"Probing of sdhci-pltfm failed: %d\n", ret);
return ret;
}
static int __devexit sdhci_pltfm_remove(struct platform_device *pdev)
{
struct sdhci_pltfm_data *pdata = pdev->dev.platform_data;
struct sdhci_host *host = platform_get_drvdata(pdev);
struct resource *iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
int dead;
u32 scratch;
dead = 0;
scratch = readl(host->ioaddr + SDHCI_INT_STATUS);
if (scratch == (u32)-1)
dead = 1;
sdhci_remove_host(host, dead);
if (pdata && pdata->exit)
pdata->exit(host);
iounmap(host->ioaddr);
release_mem_region(iomem->start, resource_size(iomem));
sdhci_free_host(host);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int sdhci_pltfm_suspend(struct platform_device *dev, pm_message_t state)
{
struct sdhci_host *host = platform_get_drvdata(dev);
return sdhci_suspend_host(host, state);
}
static int sdhci_pltfm_resume(struct platform_device *dev)
{
struct sdhci_host *host = platform_get_drvdata(dev);
return sdhci_resume_host(host);
}
static int __init sdhci_drv_init(void)
{
return platform_driver_register(&sdhci_pltfm_driver);
}
static void __exit sdhci_drv_exit(void)
{
platform_driver_unregister(&sdhci_pltfm_driver);
}
