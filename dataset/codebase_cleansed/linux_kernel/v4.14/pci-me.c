static inline void mei_me_set_pm_domain(struct mei_device *dev) {}
static inline void mei_me_unset_pm_domain(struct mei_device *dev) {}
static bool mei_me_quirk_probe(struct pci_dev *pdev,
const struct mei_cfg *cfg)
{
if (cfg->quirk_probe && cfg->quirk_probe(pdev)) {
dev_info(&pdev->dev, "Device doesn't have valid ME Interface\n");
return false;
}
return true;
}
static int mei_me_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct mei_cfg *cfg;
struct mei_device *dev;
struct mei_me_hw *hw;
unsigned int irqflags;
int err;
cfg = mei_me_get_cfg(ent->driver_data);
if (!cfg)
return -ENODEV;
if (!mei_me_quirk_probe(pdev, cfg))
return -ENODEV;
err = pcim_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable pci device.\n");
goto end;
}
pci_set_master(pdev);
err = pcim_iomap_regions(pdev, BIT(0), KBUILD_MODNAME);
if (err) {
dev_err(&pdev->dev, "failed to get pci regions.\n");
goto end;
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
goto end;
}
dev = mei_me_dev_init(pdev, cfg);
if (!dev) {
err = -ENOMEM;
goto end;
}
hw = to_me_hw(dev);
hw->mem_addr = pcim_iomap_table(pdev)[0];
pci_enable_msi(pdev);
irqflags = pci_dev_msi_enabled(pdev) ? IRQF_ONESHOT : IRQF_SHARED;
err = request_threaded_irq(pdev->irq,
mei_me_irq_quick_handler,
mei_me_irq_thread_handler,
irqflags, KBUILD_MODNAME, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failure. irq = %d\n",
pdev->irq);
goto end;
}
if (mei_start(dev)) {
dev_err(&pdev->dev, "init hw failure.\n");
err = -ENODEV;
goto release_irq;
}
pm_runtime_set_autosuspend_delay(&pdev->dev, MEI_ME_RPM_TIMEOUT);
pm_runtime_use_autosuspend(&pdev->dev);
err = mei_register(dev, &pdev->dev);
if (err)
goto stop;
pci_set_drvdata(pdev, dev);
pdev->dev_flags |= PCI_DEV_FLAGS_NEEDS_RESUME;
mei_me_set_pm_domain(dev);
if (mei_pg_is_enabled(dev))
pm_runtime_put_noidle(&pdev->dev);
dev_dbg(&pdev->dev, "initialization successful.\n");
return 0;
stop:
mei_stop(dev);
release_irq:
mei_cancel_work(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
end:
dev_err(&pdev->dev, "initialization failed.\n");
return err;
}
static void mei_me_shutdown(struct pci_dev *pdev)
{
struct mei_device *dev;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
dev_dbg(&pdev->dev, "shutdown\n");
mei_stop(dev);
mei_me_unset_pm_domain(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
}
static void mei_me_remove(struct pci_dev *pdev)
{
struct mei_device *dev;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
if (mei_pg_is_enabled(dev))
pm_runtime_get_noresume(&pdev->dev);
dev_dbg(&pdev->dev, "stop\n");
mei_stop(dev);
mei_me_unset_pm_domain(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
mei_deregister(dev);
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
unsigned int irqflags;
int err;
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
pci_enable_msi(pdev);
irqflags = pci_dev_msi_enabled(pdev) ? IRQF_ONESHOT : IRQF_SHARED;
err = request_threaded_irq(pdev->irq,
mei_me_irq_quick_handler,
mei_me_irq_thread_handler,
irqflags, KBUILD_MODNAME, dev);
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
static int mei_me_pm_runtime_idle(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
dev_dbg(&pdev->dev, "rpm: me: runtime_idle\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
if (mei_write_is_idle(dev))
pm_runtime_autosuspend(device);
return -EBUSY;
}
static int mei_me_pm_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int ret;
dev_dbg(&pdev->dev, "rpm: me: runtime suspend\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
if (mei_write_is_idle(dev))
ret = mei_me_pg_enter_sync(dev);
else
ret = -EAGAIN;
mutex_unlock(&dev->device_lock);
dev_dbg(&pdev->dev, "rpm: me: runtime suspend ret=%d\n", ret);
if (ret && ret != -EAGAIN)
schedule_work(&dev->reset_work);
return ret;
}
static int mei_me_pm_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int ret;
dev_dbg(&pdev->dev, "rpm: me: runtime resume\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
ret = mei_me_pg_exit_sync(dev);
mutex_unlock(&dev->device_lock);
dev_dbg(&pdev->dev, "rpm: me: runtime resume ret = %d\n", ret);
if (ret)
schedule_work(&dev->reset_work);
return ret;
}
static inline void mei_me_set_pm_domain(struct mei_device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev->dev);
if (pdev->dev.bus && pdev->dev.bus->pm) {
dev->pg_domain.ops = *pdev->dev.bus->pm;
dev->pg_domain.ops.runtime_suspend = mei_me_pm_runtime_suspend;
dev->pg_domain.ops.runtime_resume = mei_me_pm_runtime_resume;
dev->pg_domain.ops.runtime_idle = mei_me_pm_runtime_idle;
dev_pm_domain_set(&pdev->dev, &dev->pg_domain);
}
}
static inline void mei_me_unset_pm_domain(struct mei_device *dev)
{
dev_pm_domain_set(dev->dev, NULL);
}
