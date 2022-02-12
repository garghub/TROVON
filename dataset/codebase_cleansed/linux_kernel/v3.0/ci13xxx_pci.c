static irqreturn_t ci13xxx_pci_irq(int irq, void *pdev)
{
if (irq == 0) {
dev_err(&((struct pci_dev *)pdev)->dev, "Invalid IRQ0 usage!");
return IRQ_HANDLED;
}
return udc_irq();
}
static int __devinit ci13xxx_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
void __iomem *regs = NULL;
int retval = 0;
if (id == NULL)
return -EINVAL;
retval = pci_enable_device(pdev);
if (retval)
goto done;
if (!pdev->irq) {
dev_err(&pdev->dev, "No IRQ, check BIOS/PCI setup!");
retval = -ENODEV;
goto disable_device;
}
retval = pci_request_regions(pdev, UDC_DRIVER_NAME);
if (retval)
goto disable_device;
regs = pci_iomap(pdev, 0, 0);
if (!regs) {
dev_err(&pdev->dev, "Error mapping memory!");
retval = -EFAULT;
goto release_regions;
}
pci_set_drvdata(pdev, (__force void *)regs);
pci_set_master(pdev);
pci_try_set_mwi(pdev);
retval = udc_probe(&ci13xxx_pci_udc_driver, &pdev->dev, regs);
if (retval)
goto iounmap;
retval = request_irq(pdev->irq, ci13xxx_pci_irq, IRQF_SHARED,
UDC_DRIVER_NAME, pdev);
if (retval)
goto gadget_remove;
return 0;
gadget_remove:
udc_remove();
iounmap:
pci_iounmap(pdev, regs);
release_regions:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
done:
return retval;
}
static void __devexit ci13xxx_pci_remove(struct pci_dev *pdev)
{
free_irq(pdev->irq, pdev);
udc_remove();
pci_iounmap(pdev, (__force void __iomem *)pci_get_drvdata(pdev));
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init ci13xxx_pci_init(void)
{
return pci_register_driver(&ci13xxx_pci_driver);
}
static void __exit ci13xxx_pci_exit(void)
{
pci_unregister_driver(&ci13xxx_pci_driver);
}
