static irqreturn_t netx_handler(int irq, struct uio_info *dev_info)
{
void __iomem *int_enable_reg = dev_info->mem[0].internal_addr
+ DPM_HOST_INT_EN0;
void __iomem *int_status_reg = dev_info->mem[0].internal_addr
+ DPM_HOST_INT_STAT0;
if (!(ioread32(int_enable_reg) & ioread32(int_status_reg)
& DPM_HOST_INT_MASK))
return IRQ_NONE;
iowrite32(ioread32(int_enable_reg) & ~DPM_HOST_INT_GLOBAL_EN,
int_enable_reg);
return IRQ_HANDLED;
}
static int netx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct uio_info *info;
int bar;
info = kzalloc(sizeof(struct uio_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (pci_enable_device(dev))
goto out_free;
if (pci_request_regions(dev, "netx"))
goto out_disable;
switch (id->device) {
case PCI_DEVICE_ID_HILSCHER_NETX:
bar = 0;
info->name = "netx";
break;
case PCI_DEVICE_ID_HILSCHER_NETPLC:
bar = 0;
info->name = "netplc";
break;
default:
bar = 2;
info->name = "netx_plx";
}
info->mem[0].addr = pci_resource_start(dev, bar);
if (!info->mem[0].addr)
goto out_release;
info->mem[0].internal_addr = ioremap(pci_resource_start(dev, bar),
pci_resource_len(dev, bar));
if (!info->mem[0].internal_addr)
goto out_release;
info->mem[0].size = pci_resource_len(dev, bar);
info->mem[0].memtype = UIO_MEM_PHYS;
info->irq = dev->irq;
info->irq_flags = IRQF_SHARED;
info->handler = netx_handler;
info->version = "0.0.1";
iowrite32(0, info->mem[0].internal_addr + DPM_HOST_INT_EN0);
if (uio_register_device(&dev->dev, info))
goto out_unmap;
pci_set_drvdata(dev, info);
dev_info(&dev->dev, "Found %s card, registered UIO device.\n",
info->name);
return 0;
out_unmap:
iounmap(info->mem[0].internal_addr);
out_release:
pci_release_regions(dev);
out_disable:
pci_disable_device(dev);
out_free:
kfree(info);
return -ENODEV;
}
static void netx_pci_remove(struct pci_dev *dev)
{
struct uio_info *info = pci_get_drvdata(dev);
iowrite32(0, info->mem[0].internal_addr + DPM_HOST_INT_EN0);
uio_unregister_device(info);
pci_release_regions(dev);
pci_disable_device(dev);
pci_set_drvdata(dev, NULL);
iounmap(info->mem[0].internal_addr);
kfree(info);
}
static int __init netx_init_module(void)
{
return pci_register_driver(&netx_pci_driver);
}
static void __exit netx_exit_module(void)
{
pci_unregister_driver(&netx_pci_driver);
}
