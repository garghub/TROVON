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
static int ufshcd_pltfrm_runtime_suspend(struct device *dev)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
if (!hba)
return 0;
return ufshcd_runtime_suspend(hba);
}
static int ufshcd_pltfrm_runtime_resume(struct device *dev)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
if (!hba)
return 0;
return ufshcd_runtime_resume(hba);
}
static int ufshcd_pltfrm_runtime_idle(struct device *dev)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
if (!hba)
return 0;
return ufshcd_runtime_idle(hba);
}
static int ufshcd_pltfrm_probe(struct platform_device *pdev)
{
struct ufs_hba *hba;
void __iomem *mmio_base;
struct resource *mem_res;
int irq, err;
struct device *dev = &pdev->dev;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio_base = devm_ioremap_resource(dev, mem_res);
if (IS_ERR(mmio_base)) {
err = PTR_ERR(mmio_base);
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "IRQ resource not available\n");
err = -ENODEV;
goto out;
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
err = ufshcd_init(dev, &hba, mmio_base, irq);
if (err) {
dev_err(dev, "Intialization failed\n");
goto out_disable_rpm;
}
platform_set_drvdata(pdev, hba);
return 0;
out_disable_rpm:
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
out:
return err;
}
static int ufshcd_pltfrm_remove(struct platform_device *pdev)
{
struct ufs_hba *hba = platform_get_drvdata(pdev);
pm_runtime_get_sync(&(pdev)->dev);
ufshcd_remove(hba);
return 0;
}
