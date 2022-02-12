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
struct resource *irq_res;
resource_size_t mem_size;
int err;
struct device *dev = &pdev->dev;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res) {
dev_err(&pdev->dev,
"Memory resource not available\n");
err = -ENODEV;
goto out_error;
}
mem_size = resource_size(mem_res);
if (!request_mem_region(mem_res->start, mem_size, "ufshcd")) {
dev_err(&pdev->dev,
"Cannot reserve the memory resource\n");
err = -EBUSY;
goto out_error;
}
mmio_base = ioremap_nocache(mem_res->start, mem_size);
if (!mmio_base) {
dev_err(&pdev->dev, "memory map failed\n");
err = -ENOMEM;
goto out_release_regions;
}
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq_res) {
dev_err(&pdev->dev, "IRQ resource not available\n");
err = -ENODEV;
goto out_iounmap;
}
err = dma_set_coherent_mask(dev, dev->coherent_dma_mask);
if (err) {
dev_err(&pdev->dev, "set dma mask failed\n");
goto out_iounmap;
}
err = ufshcd_init(&pdev->dev, &hba, mmio_base, irq_res->start);
if (err) {
dev_err(&pdev->dev, "Intialization failed\n");
goto out_iounmap;
}
platform_set_drvdata(pdev, hba);
return 0;
out_iounmap:
iounmap(mmio_base);
out_release_regions:
release_mem_region(mem_res->start, mem_size);
out_error:
return err;
}
static int ufshcd_pltfrm_remove(struct platform_device *pdev)
{
struct resource *mem_res;
resource_size_t mem_size;
struct ufs_hba *hba = platform_get_drvdata(pdev);
disable_irq(hba->irq);
free_irq(hba->irq, hba);
ufshcd_remove(hba);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res)
dev_err(&pdev->dev, "ufshcd: Memory resource not available\n");
else {
mem_size = resource_size(mem_res);
release_mem_region(mem_res->start, mem_size);
}
platform_set_drvdata(pdev, NULL);
return 0;
}
