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
static int pci6208_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int val;
val = inw(dev->iobase + PCI6208_DIO);
val = (val & PCI6208_DIO_DI_MASK) >> PCI6208_DIO_DI_SHIFT;
data[1] = val;
return insn->n;
}
static int pci6208_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = data[0];
unsigned int bits = data[1];
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outw(s->state, dev->iobase + PCI6208_DIO);
}
data[1] = s->state;
return insn->n;
}
static const void *pci6208_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct pci6208_board *boardinfo;
int i;
for (i = 0; i < ARRAY_SIZE(pci6208_boards); i++) {
boardinfo = &pci6208_boards[i];
if (boardinfo->dev_id == pcidev->device)
return boardinfo;
}
return NULL;
}
static int pci6208_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci6208_board *boardinfo;
struct pci6208_private *devpriv;
struct comedi_subdevice *s;
unsigned int val;
int ret;
boardinfo = pci6208_find_boardinfo(dev, pcidev);
if (!boardinfo)
return -ENODEV;
dev->board_ptr = boardinfo;
dev->board_name = boardinfo->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = boardinfo->ao_chans;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = pci6208_ao_winsn;
s->insn_read = pci6208_ao_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci6208_di_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci6208_do_insn_bits;
val = inw(dev->iobase + PCI6208_DIO);
val = (val & PCI6208_DIO_DO_MASK) >> PCI6208_DIO_DO_SHIFT;
s->state = val;
s->io_bits = 0x0f;
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
}
}
static int adl_pci6208_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci6208_driver);
}
