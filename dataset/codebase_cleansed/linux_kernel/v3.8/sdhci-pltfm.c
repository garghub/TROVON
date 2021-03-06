static bool sdhci_of_wp_inverted(struct device_node *np)
{
if (of_get_property(np, "sdhci,wp-inverted", NULL) ||
of_get_property(np, "wp-inverted", NULL))
return true;
#ifdef CONFIG_PPC
return machine_is(mpc837x_rdb) || machine_is(mpc837x_mds);
#else
return false;
#endif
}
void sdhci_get_of_property(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
const __be32 *clk;
u32 bus_width;
int size;
if (of_device_is_available(np)) {
if (of_get_property(np, "sdhci,auto-cmd12", NULL))
host->quirks |= SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;
if (of_get_property(np, "sdhci,1-bit-only", NULL) ||
(of_property_read_u32(np, "bus-width", &bus_width) == 0 &&
bus_width == 1))
host->quirks |= SDHCI_QUIRK_FORCE_1_BIT_DATA;
if (sdhci_of_wp_inverted(np))
host->quirks |= SDHCI_QUIRK_INVERTED_WRITE_PROTECT;
if (of_get_property(np, "broken-cd", NULL))
host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;
if (of_get_property(np, "no-1-8-v", NULL))
host->quirks2 |= SDHCI_QUIRK2_NO_1_8_V;
if (of_device_is_compatible(np, "fsl,p2020-rev1-esdhc"))
host->quirks |= SDHCI_QUIRK_BROKEN_DMA;
if (of_device_is_compatible(np, "fsl,p2020-esdhc") ||
of_device_is_compatible(np, "fsl,p1010-esdhc") ||
of_device_is_compatible(np, "fsl,mpc8536-esdhc"))
host->quirks |= SDHCI_QUIRK_BROKEN_TIMEOUT_VAL;
clk = of_get_property(np, "clock-frequency", &size);
if (clk && size == sizeof(*clk) && *clk)
pltfm_host->clock = be32_to_cpup(clk);
if (of_find_property(np, "keep-power-in-suspend", NULL))
host->mmc->pm_caps |= MMC_PM_KEEP_POWER;
if (of_find_property(np, "enable-sdio-wakeup", NULL))
host->mmc->pm_caps |= MMC_PM_WAKE_SDIO_IRQ;
}
}
void sdhci_get_of_property(struct platform_device *pdev) {}
struct sdhci_host *sdhci_pltfm_init(struct platform_device *pdev,
struct sdhci_pltfm_data *pdata)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct device_node *np = pdev->dev.of_node;
struct resource *iomem;
int ret;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem) {
ret = -ENOMEM;
goto err;
}
if (resource_size(iomem) < 0x100)
dev_err(&pdev->dev, "Invalid iomem size!\n");
if (pdev->dev.parent != &platform_bus && !np)
host = sdhci_alloc_host(pdev->dev.parent, sizeof(*pltfm_host));
else
host = sdhci_alloc_host(&pdev->dev, sizeof(*pltfm_host));
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto err;
}
pltfm_host = sdhci_priv(host);
host->hw_name = dev_name(&pdev->dev);
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
if (host->ops && host->ops->platform_init)
host->ops->platform_init(host);
platform_set_drvdata(pdev, host);
return host;
err_remap:
release_mem_region(iomem->start, resource_size(iomem));
err_request:
sdhci_free_host(host);
err:
dev_err(&pdev->dev, "%s failed %d\n", __func__, ret);
return ERR_PTR(ret);
}
void sdhci_pltfm_free(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct resource *iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iounmap(host->ioaddr);
release_mem_region(iomem->start, resource_size(iomem));
sdhci_free_host(host);
platform_set_drvdata(pdev, NULL);
}
int sdhci_pltfm_register(struct platform_device *pdev,
struct sdhci_pltfm_data *pdata)
{
struct sdhci_host *host;
int ret = 0;
host = sdhci_pltfm_init(pdev, pdata);
if (IS_ERR(host))
return PTR_ERR(host);
sdhci_get_of_property(pdev);
ret = sdhci_add_host(host);
if (ret)
sdhci_pltfm_free(pdev);
return ret;
}
int sdhci_pltfm_unregister(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
int dead = (readl(host->ioaddr + SDHCI_INT_STATUS) == 0xffffffff);
sdhci_remove_host(host, dead);
sdhci_pltfm_free(pdev);
return 0;
}
static int sdhci_pltfm_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
return sdhci_suspend_host(host);
}
static int sdhci_pltfm_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
return sdhci_resume_host(host);
}
static int __init sdhci_pltfm_drv_init(void)
{
pr_info("sdhci-pltfm: SDHCI platform and OF driver helper\n");
return 0;
}
static void __exit sdhci_pltfm_drv_exit(void)
{
}
