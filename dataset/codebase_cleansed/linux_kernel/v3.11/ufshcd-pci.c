static int ufshcd_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
return -ENOSYS;
}
static int ufshcd_pci_resume(struct pci_dev *pdev)
{
return -ENOSYS;
}
static void ufshcd_pci_shutdown(struct pci_dev *pdev)
{
ufshcd_hba_stop((struct ufs_hba *)pci_get_drvdata(pdev));
}
static void ufshcd_pci_remove(struct pci_dev *pdev)
{
struct ufs_hba *hba = pci_get_drvdata(pdev);
disable_irq(pdev->irq);
ufshcd_remove(hba);
pci_release_regions(pdev);
pci_set_drvdata(pdev, NULL);
pci_clear_master(pdev);
pci_disable_device(pdev);
}
static int ufshcd_set_dma_mask(struct pci_dev *pdev)
{
int err;
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))
&& !pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)))
return 0;
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (!err)
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
return err;
}
static int
ufshcd_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct ufs_hba *hba;
void __iomem *mmio_base;
int err;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "pci_enable_device failed\n");
goto out_error;
}
pci_set_master(pdev);
err = pci_request_regions(pdev, UFSHCD);
if (err < 0) {
dev_err(&pdev->dev, "request regions failed\n");
goto out_disable;
}
mmio_base = pci_ioremap_bar(pdev, 0);
if (!mmio_base) {
dev_err(&pdev->dev, "memory map failed\n");
err = -ENOMEM;
goto out_release_regions;
}
err = ufshcd_set_dma_mask(pdev);
if (err) {
dev_err(&pdev->dev, "set dma mask failed\n");
goto out_iounmap;
}
err = ufshcd_init(&pdev->dev, &hba, mmio_base, pdev->irq);
if (err) {
dev_err(&pdev->dev, "Initialization failed\n");
goto out_iounmap;
}
pci_set_drvdata(pdev, hba);
return 0;
out_iounmap:
iounmap(mmio_base);
out_release_regions:
pci_release_regions(pdev);
out_disable:
pci_clear_master(pdev);
pci_disable_device(pdev);
out_error:
return err;
}
