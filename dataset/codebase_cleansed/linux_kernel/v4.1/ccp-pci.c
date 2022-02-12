static int ccp_get_msix_irqs(struct ccp_device *ccp)
{
struct ccp_pci *ccp_pci = ccp->dev_specific;
struct device *dev = ccp->dev;
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct msix_entry msix_entry[MSIX_VECTORS];
unsigned int name_len = sizeof(ccp_pci->msix[0].name) - 1;
int v, ret;
for (v = 0; v < ARRAY_SIZE(msix_entry); v++)
msix_entry[v].entry = v;
ret = pci_enable_msix_range(pdev, msix_entry, 1, v);
if (ret < 0)
return ret;
ccp_pci->msix_count = ret;
for (v = 0; v < ccp_pci->msix_count; v++) {
snprintf(ccp_pci->msix[v].name, name_len, "ccp-%u", v);
ccp_pci->msix[v].vector = msix_entry[v].vector;
ret = request_irq(ccp_pci->msix[v].vector, ccp_irq_handler,
0, ccp_pci->msix[v].name, dev);
if (ret) {
dev_notice(dev, "unable to allocate MSI-X IRQ (%d)\n",
ret);
goto e_irq;
}
}
return 0;
e_irq:
while (v--)
free_irq(ccp_pci->msix[v].vector, dev);
pci_disable_msix(pdev);
ccp_pci->msix_count = 0;
return ret;
}
static int ccp_get_msi_irq(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
int ret;
ret = pci_enable_msi(pdev);
if (ret)
return ret;
ccp->irq = pdev->irq;
ret = request_irq(ccp->irq, ccp_irq_handler, 0, "ccp", dev);
if (ret) {
dev_notice(dev, "unable to allocate MSI IRQ (%d)\n", ret);
goto e_msi;
}
return 0;
e_msi:
pci_disable_msi(pdev);
return ret;
}
static int ccp_get_irqs(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
int ret;
ret = ccp_get_msix_irqs(ccp);
if (!ret)
return 0;
dev_notice(dev, "could not enable MSI-X (%d), trying MSI\n", ret);
ret = ccp_get_msi_irq(ccp);
if (!ret)
return 0;
dev_notice(dev, "could not enable MSI (%d)\n", ret);
return ret;
}
static void ccp_free_irqs(struct ccp_device *ccp)
{
struct ccp_pci *ccp_pci = ccp->dev_specific;
struct device *dev = ccp->dev;
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
if (ccp_pci->msix_count) {
while (ccp_pci->msix_count--)
free_irq(ccp_pci->msix[ccp_pci->msix_count].vector,
dev);
pci_disable_msix(pdev);
} else {
free_irq(ccp->irq, dev);
pci_disable_msi(pdev);
}
}
static int ccp_find_mmio_area(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
resource_size_t io_len;
unsigned long io_flags;
io_flags = pci_resource_flags(pdev, IO_BAR);
io_len = pci_resource_len(pdev, IO_BAR);
if ((io_flags & IORESOURCE_MEM) && (io_len >= (IO_OFFSET + 0x800)))
return IO_BAR;
return -EIO;
}
static int ccp_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct ccp_device *ccp;
struct ccp_pci *ccp_pci;
struct device *dev = &pdev->dev;
unsigned int bar;
int ret;
ret = -ENOMEM;
ccp = ccp_alloc_struct(dev);
if (!ccp)
goto e_err;
ccp_pci = devm_kzalloc(dev, sizeof(*ccp_pci), GFP_KERNEL);
if (!ccp_pci)
goto e_err;
ccp->dev_specific = ccp_pci;
ccp->get_irq = ccp_get_irqs;
ccp->free_irq = ccp_free_irqs;
ret = pci_request_regions(pdev, "ccp");
if (ret) {
dev_err(dev, "pci_request_regions failed (%d)\n", ret);
goto e_err;
}
ret = pci_enable_device(pdev);
if (ret) {
dev_err(dev, "pci_enable_device failed (%d)\n", ret);
goto e_regions;
}
pci_set_master(pdev);
ret = ccp_find_mmio_area(ccp);
if (ret < 0)
goto e_device;
bar = ret;
ret = -EIO;
ccp->io_map = pci_iomap(pdev, bar, 0);
if (!ccp->io_map) {
dev_err(dev, "pci_iomap failed\n");
goto e_device;
}
ccp->io_regs = ccp->io_map + IO_OFFSET;
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
if (ret) {
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(dev, "dma_set_mask_and_coherent failed (%d)\n",
ret);
goto e_iomap;
}
}
dev_set_drvdata(dev, ccp);
ret = ccp_init(ccp);
if (ret)
goto e_iomap;
dev_notice(dev, "enabled\n");
return 0;
e_iomap:
pci_iounmap(pdev, ccp->io_map);
e_device:
pci_disable_device(pdev);
e_regions:
pci_release_regions(pdev);
e_err:
dev_notice(dev, "initialization failed\n");
return ret;
}
static void ccp_pci_remove(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
if (!ccp)
return;
ccp_destroy(ccp);
pci_iounmap(pdev, ccp->io_map);
pci_disable_device(pdev);
pci_release_regions(pdev);
dev_notice(dev, "disabled\n");
}
static int ccp_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&ccp->cmd_lock, flags);
ccp->suspending = 1;
for (i = 0; i < ccp->cmd_q_count; i++)
wake_up_process(ccp->cmd_q[i].kthread);
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
while (!ccp_queues_suspended(ccp))
wait_event_interruptible(ccp->suspend_queue,
ccp_queues_suspended(ccp));
return 0;
}
static int ccp_pci_resume(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&ccp->cmd_lock, flags);
ccp->suspending = 0;
for (i = 0; i < ccp->cmd_q_count; i++) {
ccp->cmd_q[i].suspended = 0;
wake_up_process(ccp->cmd_q[i].kthread);
}
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
return 0;
}
int ccp_pci_init(void)
{
return pci_register_driver(&ccp_pci_driver);
}
void ccp_pci_exit(void)
{
pci_unregister_driver(&ccp_pci_driver);
}
