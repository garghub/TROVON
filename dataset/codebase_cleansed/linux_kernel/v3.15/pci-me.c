static bool mei_me_quirk_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
u32 reg;
if (ent->device == MEI_DEV_ID_CPT_1 ||
ent->device == MEI_DEV_ID_PBG_1) {
pci_read_config_dword(pdev, PCI_CFG_HFS_2, &reg);
if ((reg & 0x600) == 0x200)
goto no_mei;
}
if (ent->device == MEI_DEV_ID_LPT_H ||
ent->device == MEI_DEV_ID_LPT_W ||
ent->device == MEI_DEV_ID_LPT_HR) {
pci_read_config_dword(pdev, PCI_CFG_HFS_1, &reg);
if ((reg & 0xf0000) == 0xf0000)
goto no_mei;
}
return true;
no_mei:
dev_info(&pdev->dev, "Device doesn't have valid ME Interface\n");
return false;
}
static int mei_me_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct mei_device *dev;
struct mei_me_hw *hw;
int err;
if (!mei_me_quirk_probe(pdev, ent)) {
err = -ENODEV;
goto end;
}
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable pci device.\n");
goto end;
}
pci_set_master(pdev);
err = pci_request_regions(pdev, KBUILD_MODNAME);
if (err) {
dev_err(&pdev->dev, "failed to get pci regions.\n");
goto disable_device;
}
if (dma_set_mask(&pdev->dev, DMA_BIT_MASK(64)) ||
dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64))) {
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err)
err = dma_set_coherent_mask(&pdev->dev,
DMA_BIT_MASK(32));
}
if (err) {
dev_err(&pdev->dev, "No usable DMA configuration, aborting\n");
goto release_regions;
}
dev = mei_me_dev_init(pdev);
if (!dev) {
err = -ENOMEM;
goto release_regions;
}
hw = to_me_hw(dev);
hw->mem_addr = pci_iomap(pdev, 0, 0);
if (!hw->mem_addr) {
dev_err(&pdev->dev, "mapping I/O device memory failure.\n");
err = -ENOMEM;
goto free_device;
}
pci_enable_msi(pdev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_me_irq_thread_handler,
IRQF_ONESHOT, KBUILD_MODNAME, dev);
else
err = request_threaded_irq(pdev->irq,
mei_me_irq_quick_handler,
mei_me_irq_thread_handler,
IRQF_SHARED, KBUILD_MODNAME, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failure. irq = %d\n",
pdev->irq);
goto disable_msi;
}
if (mei_start(dev)) {
dev_err(&pdev->dev, "init hw failure.\n");
err = -ENODEV;
goto release_irq;
}
err = mei_register(dev);
if (err)
goto release_irq;
pci_set_drvdata(pdev, dev);
schedule_delayed_work(&dev->timer_work, HZ);
dev_dbg(&pdev->dev, "initialization successful.\n");
return 0;
release_irq:
mei_cancel_work(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
disable_msi:
pci_disable_msi(pdev);
pci_iounmap(pdev, hw->mem_addr);
free_device:
kfree(dev);
release_regions:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
end:
dev_err(&pdev->dev, "initialization failed.\n");
return err;
}
static void mei_me_remove(struct pci_dev *pdev)
{
struct mei_device *dev;
struct mei_me_hw *hw;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
hw = to_me_hw(dev);
dev_dbg(&pdev->dev, "stop\n");
mei_stop(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
if (hw->mem_addr)
pci_iounmap(pdev, hw->mem_addr);
mei_deregister(dev);
kfree(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int mei_me_pci_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
dev_dbg(&pdev->dev, "suspend\n");
mei_stop(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
return 0;
}
static int mei_me_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int err;
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
pci_enable_msi(pdev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_me_irq_thread_handler,
IRQF_ONESHOT, KBUILD_MODNAME, dev);
else
err = request_threaded_irq(pdev->irq,
mei_me_irq_quick_handler,
mei_me_irq_thread_handler,
IRQF_SHARED, KBUILD_MODNAME, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failed: irq = %d.\n",
pdev->irq);
return err;
}
err = mei_restart(dev);
if (err)
return err;
schedule_delayed_work(&dev->timer_work, HZ);
return 0;
}
