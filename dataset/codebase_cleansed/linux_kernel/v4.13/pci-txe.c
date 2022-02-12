static inline void mei_txe_set_pm_domain(struct mei_device *dev) {}
static inline void mei_txe_unset_pm_domain(struct mei_device *dev) {}
static int mei_txe_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct mei_device *dev;
struct mei_txe_hw *hw;
const int mask = BIT(SEC_BAR) | BIT(BRIDGE_BAR);
int err;
err = pcim_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable pci device.\n");
goto end;
}
pci_set_master(pdev);
err = pcim_iomap_regions(pdev, mask, KBUILD_MODNAME);
if (err) {
dev_err(&pdev->dev, "failed to get pci regions.\n");
goto end;
}
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(36));
if (err) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No suitable DMA available.\n");
goto end;
}
}
dev = mei_txe_dev_init(pdev);
if (!dev) {
err = -ENOMEM;
goto end;
}
hw = to_txe_hw(dev);
hw->mem_addr = pcim_iomap_table(pdev);
pci_enable_msi(pdev);
mei_clear_interrupts(dev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_txe_irq_thread_handler,
IRQF_ONESHOT, KBUILD_MODNAME, dev);
else
err = request_threaded_irq(pdev->irq,
mei_txe_irq_quick_handler,
mei_txe_irq_thread_handler,
IRQF_SHARED, KBUILD_MODNAME, dev);
if (err) {
dev_err(&pdev->dev, "mei: request_threaded_irq failure. irq = %d\n",
pdev->irq);
goto end;
}
if (mei_start(dev)) {
dev_err(&pdev->dev, "init hw failure.\n");
err = -ENODEV;
goto release_irq;
}
pm_runtime_set_autosuspend_delay(&pdev->dev, MEI_TXI_RPM_TIMEOUT);
pm_runtime_use_autosuspend(&pdev->dev);
err = mei_register(dev, &pdev->dev);
if (err)
goto stop;
pci_set_drvdata(pdev, dev);
pdev->dev_flags |= PCI_DEV_FLAGS_NEEDS_RESUME;
if (!pci_dev_run_wake(pdev))
mei_txe_set_pm_domain(dev);
pm_runtime_put_noidle(&pdev->dev);
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
static void mei_txe_shutdown(struct pci_dev *pdev)
{
struct mei_device *dev;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
dev_dbg(&pdev->dev, "shutdown\n");
mei_stop(dev);
if (!pci_dev_run_wake(pdev))
mei_txe_unset_pm_domain(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
}
static void mei_txe_remove(struct pci_dev *pdev)
{
struct mei_device *dev;
dev = pci_get_drvdata(pdev);
if (!dev) {
dev_err(&pdev->dev, "mei: dev == NULL\n");
return;
}
pm_runtime_get_noresume(&pdev->dev);
mei_stop(dev);
if (!pci_dev_run_wake(pdev))
mei_txe_unset_pm_domain(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
mei_deregister(dev);
}
static int mei_txe_pci_suspend(struct device *device)
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
static int mei_txe_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int err;
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
pci_enable_msi(pdev);
mei_clear_interrupts(dev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_txe_irq_thread_handler,
IRQF_ONESHOT, KBUILD_MODNAME, dev);
else
err = request_threaded_irq(pdev->irq,
mei_txe_irq_quick_handler,
mei_txe_irq_thread_handler,
IRQF_SHARED, KBUILD_MODNAME, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failed: irq = %d.\n",
pdev->irq);
return err;
}
err = mei_restart(dev);
return err;
}
static int mei_txe_pm_runtime_idle(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
dev_dbg(&pdev->dev, "rpm: txe: runtime_idle\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
if (mei_write_is_idle(dev))
pm_runtime_autosuspend(device);
return -EBUSY;
}
static int mei_txe_pm_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int ret;
dev_dbg(&pdev->dev, "rpm: txe: runtime suspend\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
if (mei_write_is_idle(dev))
ret = mei_txe_aliveness_set_sync(dev, 0);
else
ret = -EAGAIN;
if (!ret && pci_dev_run_wake(pdev))
mei_disable_interrupts(dev);
dev_dbg(&pdev->dev, "rpm: txe: runtime suspend ret=%d\n", ret);
mutex_unlock(&dev->device_lock);
if (ret && ret != -EAGAIN)
schedule_work(&dev->reset_work);
return ret;
}
static int mei_txe_pm_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int ret;
dev_dbg(&pdev->dev, "rpm: txe: runtime resume\n");
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
mei_enable_interrupts(dev);
ret = mei_txe_aliveness_set_sync(dev, 1);
mutex_unlock(&dev->device_lock);
dev_dbg(&pdev->dev, "rpm: txe: runtime resume ret = %d\n", ret);
if (ret)
schedule_work(&dev->reset_work);
return ret;
}
static inline void mei_txe_set_pm_domain(struct mei_device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev->dev);
if (pdev->dev.bus && pdev->dev.bus->pm) {
dev->pg_domain.ops = *pdev->dev.bus->pm;
dev->pg_domain.ops.runtime_suspend = mei_txe_pm_runtime_suspend;
dev->pg_domain.ops.runtime_resume = mei_txe_pm_runtime_resume;
dev->pg_domain.ops.runtime_idle = mei_txe_pm_runtime_idle;
dev_pm_domain_set(&pdev->dev, &dev->pg_domain);
}
}
static inline void mei_txe_unset_pm_domain(struct mei_device *dev)
{
dev_pm_domain_set(dev->dev, NULL);
}
