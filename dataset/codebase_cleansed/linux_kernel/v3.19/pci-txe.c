static inline void mei_txe_set_pm_domain(struct mei_device *dev) {}
static inline void mei_txe_unset_pm_domain(struct mei_device *dev) {}
static void mei_txe_pci_iounmap(struct pci_dev *pdev, struct mei_txe_hw *hw)
{
int i;
for (i = SEC_BAR; i < NUM_OF_MEM_BARS; i++) {
if (hw->mem_addr[i]) {
pci_iounmap(pdev, hw->mem_addr[i]);
hw->mem_addr[i] = NULL;
}
}
}
static int mei_txe_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct mei_device *dev;
struct mei_txe_hw *hw;
int err;
int i;
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
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(36));
if (err) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No suitable DMA available.\n");
goto release_regions;
}
}
dev = mei_txe_dev_init(pdev);
if (!dev) {
err = -ENOMEM;
goto release_regions;
}
hw = to_txe_hw(dev);
for (i = SEC_BAR; i < NUM_OF_MEM_BARS; i++) {
hw->mem_addr[i] = pci_iomap(pdev, i, 0);
if (!hw->mem_addr[i]) {
dev_err(&pdev->dev, "mapping I/O device memory failure.\n");
err = -ENOMEM;
goto free_device;
}
}
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
goto free_device;
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
goto release_irq;
pci_set_drvdata(pdev, dev);
if (!pci_dev_run_wake(pdev))
mei_txe_set_pm_domain(dev);
pm_runtime_put_noidle(&pdev->dev);
return 0;
release_irq:
mei_cancel_work(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
free_device:
mei_txe_pci_iounmap(pdev, hw);
kfree(dev);
release_regions:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
end:
dev_err(&pdev->dev, "initialization failed.\n");
return err;
}
static void mei_txe_remove(struct pci_dev *pdev)
{
struct mei_device *dev;
struct mei_txe_hw *hw;
dev = pci_get_drvdata(pdev);
if (!dev) {
dev_err(&pdev->dev, "mei: dev =NULL\n");
return;
}
pm_runtime_get_noresume(&pdev->dev);
hw = to_txe_hw(dev);
mei_stop(dev);
if (!pci_dev_run_wake(pdev))
mei_txe_unset_pm_domain(dev);
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
pci_set_drvdata(pdev, NULL);
mei_txe_pci_iounmap(pdev, hw);
mei_deregister(dev);
kfree(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
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
pdev->dev.pm_domain = &dev->pg_domain;
}
}
static inline void mei_txe_unset_pm_domain(struct mei_device *dev)
{
dev->dev->pm_domain = NULL;
}
