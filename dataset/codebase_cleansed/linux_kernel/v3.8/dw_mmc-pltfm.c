int dw_mci_pltfm_register(struct platform_device *pdev,
const struct dw_mci_drv_data *drv_data)
{
struct dw_mci *host;
struct resource *regs;
int ret;
host = devm_kzalloc(&pdev->dev, sizeof(struct dw_mci), GFP_KERNEL);
if (!host)
return -ENOMEM;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs)
return -ENXIO;
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0)
return host->irq;
host->drv_data = drv_data;
host->dev = &pdev->dev;
host->irq_flags = 0;
host->pdata = pdev->dev.platform_data;
host->regs = devm_request_and_ioremap(&pdev->dev, regs);
if (!host->regs)
return -ENOMEM;
if (drv_data && drv_data->init) {
ret = drv_data->init(host);
if (ret)
return ret;
}
platform_set_drvdata(pdev, host);
ret = dw_mci_probe(host);
return ret;
}
static int dw_mci_pltfm_probe(struct platform_device *pdev)
{
return dw_mci_pltfm_register(pdev, NULL);
}
static int dw_mci_pltfm_remove(struct platform_device *pdev)
{
struct dw_mci *host = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
dw_mci_remove(host);
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
