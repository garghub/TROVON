static int cb_pcimdas_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
int n, i;
unsigned int d;
unsigned int busy;
int chan = CR_CHAN(insn->chanspec);
unsigned short chanlims;
int maxchans;
if ((inb(devpriv->BADR3 + 2) & 0x20) == 0)
maxchans = s->n_chan / 2;
else
maxchans = s->n_chan;
if (chan > (maxchans - 1))
return -ETIMEDOUT;
d = inb(devpriv->BADR3 + 5);
if ((d & 0x03) > 0) {
d = d & 0xfd;
outb(d, devpriv->BADR3 + 5);
}
outb(0x01, devpriv->BADR3 + 6);
outb(0x00, devpriv->BADR3 + 7);
chanlims = chan | (chan << 4);
outb(chanlims, devpriv->BADR3 + 0);
for (n = 0; n < insn->n; n++) {
outw(0, dev->iobase + 0);
#define TIMEOUT 1000
for (i = 0; i < TIMEOUT; i++) {
busy = inb(devpriv->BADR3 + 2) & 0x80;
if (!busy)
break;
}
if (i == TIMEOUT) {
printk("timeout\n");
return -ETIMEDOUT;
}
data[n] = inw(dev->iobase + 0);
}
return n;
}
static int cb_pcimdas_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
switch (chan) {
case 0:
outw(data[i] & 0x0FFF, dev->iobase + DAC0_OFFSET);
break;
case 1:
outw(data[i] & 0x0FFF, dev->iobase + DAC1_OFFSET);
break;
default:
return -1;
}
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int cb_pcimdas_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int cb_pcimdas_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct cb_pcimdas_private *devpriv;
struct comedi_subdevice *s;
unsigned long iobase_8255;
int ret;
dev->board_name = dev->driver->driver_name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
iobase_8255 = pci_resource_start(pcidev, 4);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 0xffff;
s->range_table = &range_unknown;
s->len_chanlist = 1;
s->insn_read = cb_pcimdas_ai_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xfff;
s->range_table = &range_unknown;
s->insn_write = &cb_pcimdas_ao_winsn;
s->insn_read = &cb_pcimdas_ao_rinsn;
s = &dev->subdevices[2];
subdev_8255_init(dev, s, NULL, iobase_8255);
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void cb_pcimdas_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int cb_pcimdas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcimdas_driver);
}
static void cb_pcimdas_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
