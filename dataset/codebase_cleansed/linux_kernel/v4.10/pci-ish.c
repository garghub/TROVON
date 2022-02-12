static void ish_event_tracer(struct ishtp_device *dev, char *format, ...)
{
if (trace_ishtp_dump_enabled()) {
va_list args;
char tmp_buf[100];
va_start(args, format);
vsnprintf(tmp_buf, sizeof(tmp_buf), format, args);
va_end(args);
trace_ishtp_dump(tmp_buf);
}
}
static int ish_init(struct ishtp_device *dev)
{
int ret;
ret = ish_hw_start(dev);
if (ret) {
dev_err(dev->devc, "ISH: hw start failed.\n");
return ret;
}
ret = ishtp_start(dev);
if (ret) {
dev_err(dev->devc, "ISHTP: Protocol init failed.\n");
return ret;
}
return 0;
}
static int ish_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct ishtp_device *dev;
struct ish_hw *hw;
int ret;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "ISH: Failed to enable PCI device\n");
return ret;
}
pci_set_master(pdev);
ret = pci_request_regions(pdev, KBUILD_MODNAME);
if (ret) {
dev_err(&pdev->dev, "ISH: Failed to get PCI regions\n");
goto disable_device;
}
dev = ish_dev_init(pdev);
if (!dev) {
ret = -ENOMEM;
goto release_regions;
}
hw = to_ish_hw(dev);
dev->print_log = ish_event_tracer;
hw->mem_addr = pci_iomap(pdev, 0, 0);
if (!hw->mem_addr) {
dev_err(&pdev->dev, "ISH: mapping I/O range failure\n");
ret = -ENOMEM;
goto free_device;
}
dev->pdev = pdev;
pdev->dev_flags |= PCI_DEV_FLAGS_NO_D3;
ret = request_irq(pdev->irq, ish_irq_handler, IRQF_SHARED,
KBUILD_MODNAME, dev);
if (ret) {
dev_err(&pdev->dev, "ISH: request IRQ failure (%d)\n",
pdev->irq);
goto free_device;
}
dev_set_drvdata(dev->devc, dev);
init_waitqueue_head(&dev->suspend_wait);
init_waitqueue_head(&dev->resume_wait);
ret = ish_init(dev);
if (ret)
goto free_irq;
return 0;
free_irq:
free_irq(pdev->irq, dev);
free_device:
pci_iounmap(pdev, hw->mem_addr);
kfree(dev);
release_regions:
pci_release_regions(pdev);
disable_device:
pci_clear_master(pdev);
pci_disable_device(pdev);
dev_err(&pdev->dev, "ISH: PCI driver initialization failed.\n");
return ret;
}
static void ish_remove(struct pci_dev *pdev)
{
struct ishtp_device *ishtp_dev = pci_get_drvdata(pdev);
struct ish_hw *hw = to_ish_hw(ishtp_dev);
ishtp_bus_remove_all_clients(ishtp_dev, false);
ish_device_disable(ishtp_dev);
free_irq(pdev->irq, ishtp_dev);
pci_iounmap(pdev, hw->mem_addr);
pci_release_regions(pdev);
pci_clear_master(pdev);
pci_disable_device(pdev);
kfree(ishtp_dev);
}
static void ish_resume_handler(struct work_struct *work)
{
struct pci_dev *pdev = to_pci_dev(ish_resume_device);
struct ishtp_device *dev = pci_get_drvdata(pdev);
int ret;
ishtp_send_resume(dev);
if (dev->resume_flag)
ret = wait_event_interruptible_timeout(dev->resume_wait,
!dev->resume_flag,
msecs_to_jiffies(50));
if (dev->resume_flag)
ish_init(dev);
}
static int ish_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct ishtp_device *dev = pci_get_drvdata(pdev);
enable_irq_wake(pdev->irq);
if (dev->suspend_flag)
return 0;
dev->resume_flag = 0;
dev->suspend_flag = 1;
ishtp_send_suspend(dev);
if (dev->suspend_flag)
wait_event_interruptible_timeout(dev->suspend_wait,
!dev->suspend_flag,
msecs_to_jiffies(25));
return 0;
}
static int ish_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct ishtp_device *dev = pci_get_drvdata(pdev);
ish_resume_device = device;
dev->resume_flag = 1;
disable_irq_wake(pdev->irq);
schedule_work(&resume_work);
return 0;
}
