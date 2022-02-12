static void dw_mci_rockchip_prepare_command(struct dw_mci *host, u32 *cmdr)
{
*cmdr |= SDMMC_CMD_USE_HOLD_REG;
}
int dw_mci_pltfm_register(struct platform_device *pdev,
const struct dw_mci_drv_data *drv_data)
{
struct dw_mci *host;
struct resource *regs;
host = devm_kzalloc(&pdev->dev, sizeof(struct dw_mci), GFP_KERNEL);
if (!host)
return -ENOMEM;
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0)
return host->irq;
host->drv_data = drv_data;
host->dev = &pdev->dev;
host->irq_flags = 0;
host->pdata = pdev->dev.platform_data;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->regs = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(host->regs))
return PTR_ERR(host->regs);
platform_set_drvdata(pdev, host);
return dw_mci_probe(host);
}
static int dw_mci_pltfm_suspend(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
return dw_mci_suspend(host);
}
static int dw_mci_pltfm_resume(struct device *dev)
{
struct dw_mci *host = dev_get_drvdata(dev);
return dw_mci_resume(host);
}
static int dw_mci_pltfm_probe(struct platform_device *pdev)
{
const struct dw_mci_drv_data *drv_data = NULL;
const struct of_device_id *match;
if (pdev->dev.of_node) {
match = of_match_node(dw_mci_pltfm_match, pdev->dev.of_node);
drv_data = match->data;
}
return dw_mci_pltfm_register(pdev, drv_data);
}
int dw_mci_pltfm_remove(struct platform_device *pdev)
{
struct dw_mci *host = platform_get_drvdata(pdev);
dw_mci_remove(host);
return 0;
}
