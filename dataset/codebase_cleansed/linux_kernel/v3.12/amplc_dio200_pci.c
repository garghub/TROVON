static int dio200_pcie_board_setup(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
void __iomem *brbase;
if (pci_resource_len(pcidev, 0) < 0x4000) {
dev_err(dev->class_dev, "error! bad PCI region!\n");
return -EINVAL;
}
brbase = pci_ioremap_bar(pcidev, 0);
if (!brbase) {
dev_err(dev->class_dev, "error! failed to map registers!\n");
return -ENOMEM;
}
writel(0x80, brbase + 0x50);
iounmap(brbase);
amplc_dio200_set_enhance(dev, 1);
return 0;
}
static int dio200_pci_auto_attach(struct comedi_device *dev,
unsigned long context_model)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
const struct dio200_board *thisboard = NULL;
struct dio200_private *devpriv;
unsigned int bar;
int ret;
if (context_model < ARRAY_SIZE(dio200_pci_boards))
thisboard = &dio200_pci_boards[context_model];
if (!thisboard)
return -EINVAL;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
dev_info(dev->class_dev, "%s: attach pci %s (%s)\n",
dev->driver->driver_name, pci_name(pci_dev), dev->board_name);
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
bar = thisboard->mainbar;
if (pci_resource_len(pci_dev, bar) < thisboard->mainsize) {
dev_err(dev->class_dev, "error! PCI region size too small!\n");
return -EINVAL;
}
if (pci_resource_flags(pci_dev, bar) & IORESOURCE_MEM) {
devpriv->io.u.membase = pci_ioremap_bar(pci_dev, bar);
if (!devpriv->io.u.membase) {
dev_err(dev->class_dev,
"error! cannot remap registers\n");
return -ENOMEM;
}
devpriv->io.regtype = mmio_regtype;
} else {
devpriv->io.u.iobase = pci_resource_start(pci_dev, bar);
devpriv->io.regtype = io_regtype;
}
switch (context_model) {
case pcie215_model:
case pcie236_model:
case pcie296_model:
ret = dio200_pcie_board_setup(dev);
if (ret < 0)
return ret;
break;
default:
break;
}
return amplc_dio200_common_attach(dev, pci_dev->irq, IRQF_SHARED);
}
static void dio200_pci_detach(struct comedi_device *dev)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
if (!thisboard || !devpriv)
return;
amplc_dio200_common_detach(dev);
if (devpriv->io.regtype == mmio_regtype)
iounmap(devpriv->io.u.membase);
comedi_pci_disable(dev);
}
static int dio200_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &dio200_pci_comedi_driver,
id->driver_data);
}
