static void udc_pci_remove(struct pci_dev *pdev)
{
struct udc *dev;
dev = pci_get_drvdata(pdev);
usb_del_gadget_udc(&udc->gadget);
if (WARN_ON(dev->driver))
return;
free_dma_pools(dev);
writel(AMD_BIT(UDC_DEVCFG_SOFTRESET), &dev->regs->cfg);
free_irq(pdev->irq, dev);
iounmap(dev->virt_addr);
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
pci_disable_device(pdev);
udc_remove(dev);
}
static int udc_pci_probe(
struct pci_dev *pdev,
const struct pci_device_id *id
)
{
struct udc *dev;
unsigned long resource;
unsigned long len;
int retval = 0;
if (udc) {
dev_dbg(&pdev->dev, "already probed\n");
return -EBUSY;
}
dev = kzalloc(sizeof(struct udc), GFP_KERNEL);
if (!dev)
return -ENOMEM;
if (pci_enable_device(pdev) < 0) {
retval = -ENODEV;
goto err_pcidev;
}
resource = pci_resource_start(pdev, 0);
len = pci_resource_len(pdev, 0);
if (!request_mem_region(resource, len, name)) {
dev_dbg(&pdev->dev, "pci device used already\n");
retval = -EBUSY;
goto err_memreg;
}
dev->virt_addr = ioremap_nocache(resource, len);
if (!dev->virt_addr) {
dev_dbg(&pdev->dev, "start address cannot be mapped\n");
retval = -EFAULT;
goto err_ioremap;
}
if (!pdev->irq) {
dev_err(&pdev->dev, "irq not set\n");
retval = -ENODEV;
goto err_irq;
}
spin_lock_init(&dev->lock);
dev->csr = dev->virt_addr + UDC_CSR_ADDR;
dev->regs = dev->virt_addr + UDC_DEVCFG_ADDR;
dev->ep_regs = dev->virt_addr + UDC_EPREGS_ADDR;
dev->rxfifo = (u32 __iomem *)(dev->virt_addr + UDC_RXFIFO_ADDR);
dev->txfifo = (u32 __iomem *)(dev->virt_addr + UDC_TXFIFO_ADDR);
if (request_irq(pdev->irq, udc_irq, IRQF_SHARED, name, dev) != 0) {
dev_dbg(&pdev->dev, "request_irq(%d) fail\n", pdev->irq);
retval = -EBUSY;
goto err_irq;
}
pci_set_drvdata(pdev, dev);
dev->chiprev = pdev->revision;
pci_set_master(pdev);
pci_try_set_mwi(pdev);
if (use_dma) {
retval = init_dma_pools(dev);
if (retval != 0)
goto err_dma;
}
dev->phys_addr = resource;
dev->irq = pdev->irq;
dev->pdev = pdev;
if (udc_probe(dev)) {
retval = -ENODEV;
goto err_probe;
}
return 0;
err_probe:
if (use_dma)
free_dma_pools(dev);
err_dma:
free_irq(pdev->irq, dev);
err_irq:
iounmap(dev->virt_addr);
err_ioremap:
release_mem_region(resource, len);
err_memreg:
pci_disable_device(pdev);
err_pcidev:
kfree(dev);
return retval;
}
