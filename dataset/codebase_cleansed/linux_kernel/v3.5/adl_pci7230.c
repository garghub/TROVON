static int adl_pci7230_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outl((s->state << 16) & 0xffffffff, dev->iobase + PCI7230_DO);
}
return 2;
}
static int adl_pci7230_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
data[1] = inl(dev->iobase + PCI7230_DI) & 0xffffffff;
return 2;
}
static int adl_pci7230_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
struct comedi_subdevice *s;
int bus, slot;
printk(KERN_INFO "comedi%d: adl_pci7230\n", dev->minor);
dev->board_name = "pci7230";
bus = it->options[0];
slot = it->options[1];
if (alloc_private(dev, sizeof(struct adl_pci7230_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 2) < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
if (pcidev->vendor == PCI_VENDOR_ID_ADLINK &&
pcidev->device == PCI_DEVICE_ID_PCI7230) {
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot) {
continue;
}
}
devpriv->pci_dev = pcidev;
break;
}
}
if (pcidev == NULL) {
printk(KERN_ERR "comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
dev->minor, bus, slot);
return -EIO;
}
if (comedi_pci_enable(pcidev, "adl_pci7230") < 0) {
printk(KERN_ERR "comedi%d: Failed to enable PCI device and request regions\n",
dev->minor);
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 2);
printk(KERN_DEBUG "comedi: base addr %4lx\n", dev->iobase);
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = adl_pci7230_do_insn_bits;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = adl_pci7230_di_insn_bits;
printk(KERN_DEBUG "comedi: attached\n");
return 1;
}
static void adl_pci7230_detach(struct comedi_device *dev)
{
if (devpriv && devpriv->pci_dev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
}
static int __devinit adl_pci7230_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci7230_driver);
}
static void __devexit adl_pci7230_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
