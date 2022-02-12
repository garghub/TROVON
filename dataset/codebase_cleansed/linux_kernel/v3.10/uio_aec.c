static irqreturn_t aectc_irq(int irq, struct uio_info *dev_info)
{
void __iomem *int_flag = dev_info->priv + INTA_DRVR_ADDR;
unsigned char status = ioread8(int_flag);
if ((status & INTA_ENABLED_FLAG) && (status & INTA_FLAG)) {
status = ioread8(dev_info->priv + MAILBOX);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void print_board_data(struct pci_dev *pdev, struct uio_info *i)
{
dev_info(&pdev->dev, "PCI-TC board vendor: %x%x number: %x%x"
" revision: %c%c\n",
ioread8(i->priv + 0x01),
ioread8(i->priv + 0x00),
ioread8(i->priv + 0x03),
ioread8(i->priv + 0x02),
ioread8(i->priv + 0x06),
ioread8(i->priv + 0x07));
}
static int probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct uio_info *info;
int ret;
info = kzalloc(sizeof(struct uio_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (pci_enable_device(pdev))
goto out_free;
if (pci_request_regions(pdev, "aectc"))
goto out_disable;
info->name = "aectc";
info->port[0].start = pci_resource_start(pdev, 0);
if (!info->port[0].start)
goto out_release;
info->priv = pci_iomap(pdev, 0, 0);
if (!info->priv)
goto out_release;
info->port[0].size = pci_resource_len(pdev, 0);
info->port[0].porttype = UIO_PORT_GPIO;
info->version = "0.0.1";
info->irq = pdev->irq;
info->irq_flags = IRQF_SHARED;
info->handler = aectc_irq;
print_board_data(pdev, info);
ret = uio_register_device(&pdev->dev, info);
if (ret)
goto out_unmap;
iowrite32(INT_ENABLE, info->priv + INT_ENABLE_ADDR);
iowrite8(INT_MASK_ALL, info->priv + INT_MASK_ADDR);
if (!(ioread8(info->priv + INTA_DRVR_ADDR)
& INTA_ENABLED_FLAG))
dev_err(&pdev->dev, "aectc: interrupts not enabled\n");
pci_set_drvdata(pdev, info);
return 0;
out_unmap:
pci_iounmap(pdev, info->priv);
out_release:
pci_release_regions(pdev);
out_disable:
pci_disable_device(pdev);
out_free:
kfree(info);
return -ENODEV;
}
static void remove(struct pci_dev *pdev)
{
struct uio_info *info = pci_get_drvdata(pdev);
iowrite8(INT_DISABLE, info->priv + INT_MASK_ADDR);
iowrite32(INT_DISABLE, info->priv + INT_ENABLE_ADDR);
ioread8(info->priv + MAILBOX);
uio_unregister_device(info);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
iounmap(info->priv);
kfree(info);
}
static int __init aectc_init(void)
{
return pci_register_driver(&pci_driver);
}
static void __exit aectc_exit(void)
{
pci_unregister_driver(&pci_driver);
}
