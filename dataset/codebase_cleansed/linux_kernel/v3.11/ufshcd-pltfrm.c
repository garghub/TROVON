static int ufshcd_pltfrm_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ufs_hba *hba = platform_get_drvdata(pdev);
disable_irq(hba->irq);
return 0;
}
static int ufshcd_pltfrm_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ufs_hba *hba = platform_get_drvdata(pdev);
enable_irq(hba->irq);
return 0;
}
static int ufshcd_pltfrm_probe(struct platform_device *pdev)
{
struct ufs_hba *hba;
void __iomem *mmio_base;
struct resource *mem_res;
int irq, err;
struct device *dev = &pdev->dev;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res) {
dev_err(dev, "Memory resource not available\n");
err = -ENODEV;
goto out;
}
mmio_base = devm_ioremap_resource(dev, mem_res);
if (IS_ERR(mmio_base)) {
dev_err(dev, "memory map failed\n");
err = PTR_ERR(mmio_base);
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "IRQ resource not available\n");
err = -ENODEV;
goto out;
}
err = ufshcd_init(dev, &hba, mmio_base, irq);
if (err) {
dev_err(dev, "Intialization failed\n");
goto out;
}
platform_set_drvdata(pdev, hba);
out:
return err;
}
static int ufshcd_pltfrm_remove(struct platform_device *pdev)
{
struct ufs_hba *hba = platform_get_drvdata(pdev);
disable_irq(hba->irq);
ufshcd_remove(hba);
return 0;
}
