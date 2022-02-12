static int contec_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
dev_dbg(dev->class_dev, "contec_do_insn_bits called\n");
dev_dbg(dev->class_dev, "data: %d %d\n", data[0], data[1]);
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
dev_dbg(dev->class_dev, "out: %d on %lx\n", s->state,
dev->iobase + thisboard->out_offs);
outw(s->state, dev->iobase + thisboard->out_offs);
}
return insn->n;
}
static int contec_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
dev_dbg(dev->class_dev, "contec_di_insn_bits called\n");
dev_dbg(dev->class_dev, "data: %d %d\n", data[0], data[1]);
data[1] = inw(dev->iobase + thisboard->in_offs);
return insn->n;
}
static struct pci_dev *contec_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pcidev) {
if (bus || slot) {
if (bus != pcidev->bus->number ||
slot != PCI_SLOT(pcidev->devfn))
continue;
}
if (pcidev->vendor != PCI_VENDOR_ID_CONTEC ||
pcidev->device != PCI_DEVICE_ID_PIO1616L)
continue;
dev->board_ptr = contec_boards + 0;
return pcidev;
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int contec_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
struct comedi_subdevice *s;
int ret;
printk("comedi%d: contec: ", dev->minor);
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
pcidev = contec_find_pci_dev(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
if (comedi_pci_enable(pcidev, "contec_pci_dio")) {
printk("error enabling PCI device and request regions!\n");
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 0);
printk(" base addr %lx ", dev->iobase);
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = contec_di_insn_bits;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = contec_do_insn_bits;
printk("attached\n");
return 1;
}
static void contec_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit contec_pci_dio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &contec_pci_dio_driver);
}
static void __devexit contec_pci_dio_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
