static int cnt_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
outb((unsigned char)((data[0] >> 24) & 0xff),
dev->iobase + chan * 0x20 + 0x10);
outb((unsigned char)((data[0] >> 16) & 0xff),
dev->iobase + chan * 0x20 + 0x0c);
outb((unsigned char)((data[0] >> 8) & 0xff),
dev->iobase + chan * 0x20 + 0x08);
outb((unsigned char)((data[0] >> 0) & 0xff),
dev->iobase + chan * 0x20 + 0x04);
return 1;
}
static int cnt_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
unsigned char a0, a1, a2, a3, a4;
int chan = CR_CHAN(insn->chanspec);
int result;
a0 = inb(dev->iobase + chan * 0x20);
a1 = inb(dev->iobase + chan * 0x20 + 0x04);
a2 = inb(dev->iobase + chan * 0x20 + 0x08);
a3 = inb(dev->iobase + chan * 0x20 + 0x0c);
a4 = inb(dev->iobase + chan * 0x20 + 0x10);
result = (a1 + (a2 * 256) + (a3 * 65536));
if (a4 > 0)
result = result - s->maxdata;
*data = (unsigned int)result;
return 1;
}
static int cnt_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
dev->board_name = dev->driver->driver_name;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 0);
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE ;
s->n_chan = 3;
s->maxdata = 0x00ffffff;
s->insn_read = cnt_rinsn;
s->insn_write = cnt_winsn;
outb(3, dev->iobase + 248);
outb(0, dev->iobase);
outb(0, dev->iobase + 0x20);
outb(0, dev->iobase + 0x40);
dev_info(dev->class_dev, "%s: %s attached\n",
dev->driver->driver_name, dev->board_name);
return 0;
}
static void cnt_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int ke_counter_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &ke_counter_driver);
}
