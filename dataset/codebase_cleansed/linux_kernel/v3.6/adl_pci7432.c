static int adl_pci7432_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
printk(KERN_DEBUG "comedi: pci7432_do_insn_bits called\n");
printk(KERN_DEBUG "comedi: data0: %8x data1: %8x\n", data[0], data[1]);
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
printk(KERN_DEBUG "comedi: out: %8x on iobase %4lx\n", s->state,
dev->iobase + PCI7432_DO);
outl(s->state & 0xffffffff, dev->iobase + PCI7432_DO);
}
return insn->n;
}
static int adl_pci7432_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
printk(KERN_DEBUG "comedi: pci7432_di_insn_bits called\n");
printk(KERN_DEBUG "comedi: data0: %8x data1: %8x\n", data[0], data[1]);
data[1] = inl(dev->iobase + PCI7432_DI) & 0xffffffff;
printk(KERN_DEBUG "comedi: data1 %8x\n", data[1]);
return insn->n;
}
static struct pci_dev *adl_pci7432_find_pci(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_ADLINK ||
pcidev->device != PCI_DEVICE_ID_PCI7432)
continue;
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot)
continue;
}
return pcidev;
}
printk(KERN_ERR
"comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
dev->minor, bus, slot);
return NULL;
}
static int adl_pci7432_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
struct comedi_subdevice *s;
int ret;
printk(KERN_INFO "comedi%d: attach adl_pci7432\n", dev->minor);
dev->board_name = "pci7432";
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
pcidev = adl_pci7432_find_pci(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
if (comedi_pci_enable(pcidev, "adl_pci7432") < 0) {
printk(KERN_ERR "comedi%d: Failed to enable PCI device and request regions\n",
dev->minor);
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 2);
printk(KERN_INFO "comedi: base addr %4lx\n", dev->iobase);
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 32;
s->maxdata = 1;
s->len_chanlist = 32;
s->io_bits = 0x00000000;
s->range_table = &range_digital;
s->insn_bits = adl_pci7432_di_insn_bits;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 32;
s->maxdata = 1;
s->len_chanlist = 32;
s->io_bits = 0xffffffff;
s->range_table = &range_digital;
s->insn_bits = adl_pci7432_do_insn_bits;
printk(KERN_DEBUG "comedi%d: adl_pci7432 attached\n", dev->minor);
return 0;
}
static void adl_pci7432_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit adl_pci7432_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci7432_driver);
}
static void __devexit adl_pci7432_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
