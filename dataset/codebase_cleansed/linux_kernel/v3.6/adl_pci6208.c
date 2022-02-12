static int pci6208_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci6208_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
unsigned long invert = 1 << (16 - 1);
unsigned long value = 0;
unsigned short status;
int i;
for (i = 0; i < insn->n; i++) {
value = data[i] ^ invert;
do {
status = inw(dev->iobase + PCI6208_AO_STATUS);
} while (status & PCI6208_AO_STATUS_DATA_SEND);
outw(value, dev->iobase + PCI6208_AO_CONTROL(chan));
}
devpriv->ao_readback[chan] = value;
return insn->n;
}
static int pci6208_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci6208_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static int pci6208_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = data[0] & PCI6208_DIO_DO_MASK;
unsigned int bits = data[1];
if (mask) {
s->state &= ~mask;
s->state |= bits & mask;
outw(s->state, dev->iobase + PCI6208_DIO);
}
s->state = inw(dev->iobase + PCI6208_DIO);
data[1] = s->state;
return insn->n;
}
static int pci6208_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
unsigned int mask = 1 << chan;
switch (data[0]) {
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & mask) ? COMEDI_OUTPUT : COMEDI_INPUT;
break;
default:
return -EINVAL;
}
return insn->n;
}
static struct pci_dev *pci6208_find_device(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pci6208_board *thisboard;
struct pci_dev *pci_dev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pci_dev) {
if (pci_dev->vendor != PCI_VENDOR_ID_ADLINK)
continue;
for (i = 0; i < ARRAY_SIZE(pci6208_boards); i++) {
thisboard = &pci6208_boards[i];
if (thisboard->dev_id != pci_dev->device)
continue;
if (bus || slot) {
if (pci_dev->bus->number != bus ||
PCI_SLOT(pci_dev->devfn) != slot)
continue;
}
dev_dbg(dev->class_dev,
"Found %s on bus %d, slot, %d, irq=%d\n",
thisboard->name,
pci_dev->bus->number,
PCI_SLOT(pci_dev->devfn),
pci_dev->irq);
dev->board_ptr = thisboard;
return pci_dev;
}
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pci6208_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pci6208_board *thisboard;
struct pci6208_private *devpriv;
struct pci_dev *pcidev;
struct comedi_subdevice *s;
int ret;
ret = alloc_private(dev, sizeof(*devpriv));
if (ret < 0)
return ret;
devpriv = dev->private;
pcidev = pci6208_find_device(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
thisboard = comedi_board(dev);
dev->board_name = thisboard->name;
ret = comedi_pci_enable(pcidev, dev->driver->driver_name);
if (ret) {
dev_err(dev->class_dev,
"Failed to enable PCI device and request regions\n");
return ret;
}
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = pci6208_ao_winsn;
s->insn_read = pci6208_ao_rinsn;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci6208_dio_insn_bits;
s->insn_config = pci6208_dio_insn_config;
s->io_bits = 0x0f;
s->state = inw(dev->iobase + PCI6208_DIO);
dev_info(dev->class_dev, "%s: %s, I/O base=0x%04lx\n",
dev->driver->driver_name, dev->board_name, dev->iobase);
return 0;
}
static void pci6208_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit adl_pci6208_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci6208_driver);
}
static void __devexit adl_pci6208_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
