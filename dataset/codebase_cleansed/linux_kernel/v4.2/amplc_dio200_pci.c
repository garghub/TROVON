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
const struct dio200_board *board = NULL;
unsigned int bar;
int ret;
if (context_model < ARRAY_SIZE(dio200_pci_boards))
board = &dio200_pci_boards[context_model];
if (!board)
return -EINVAL;
dev->board_ptr = board;
dev->board_name = board->name;
dev_info(dev->class_dev, "%s: attach pci %s (%s)\n",
dev->driver->driver_name, pci_name(pci_dev), dev->board_name);
ret = comedi_pci_enable(dev);
if (ret)
return ret;
bar = board->mainbar;
if (pci_resource_flags(pci_dev, bar) & IORESOURCE_MEM) {
dev->mmio = pci_ioremap_bar(pci_dev, bar);
if (!dev->mmio) {
dev_err(dev->class_dev,
"error! cannot remap registers\n");
return -ENOMEM;
}
} else {
dev->iobase = pci_resource_start(pci_dev, bar);
}
if (board->is_pcie) {
ret = dio200_pcie_board_setup(dev);
if (ret < 0)
return ret;
}
return amplc_dio200_common_attach(dev, pci_dev->irq, IRQF_SHARED);
}
static int dio200_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &dio200_pci_comedi_driver,
id->driver_data);
}
