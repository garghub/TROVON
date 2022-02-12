static int cb_pcimdda_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdda_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long offset = dev->iobase + PCIMDDA_DA_CHAN(chan);
unsigned int val = 0;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outb(val & 0x00ff, offset);
outb((val >> 8) & 0x00ff, offset + 1);
}
devpriv->ao_readback[chan] = val;
return insn->n;
}
static int cb_pcimdda_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdda_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
unsigned long offset = dev->iobase + PCIMDDA_DA_CHAN(chan);
int i;
for (i = 0; i < insn->n; i++) {
inw(offset);
data[i] = devpriv->ao_readback[chan];
}
return insn->n;
}
static int cb_pcimdda_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct cb_pcimdda_private *devpriv;
struct comedi_subdevice *s;
int ret;
dev->board_name = dev->driver->driver_name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 3);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 6;
s->maxdata = 0xffff;
s->range_table = &range_bipolar5;
s->insn_write = cb_pcimdda_ao_winsn;
s->insn_read = cb_pcimdda_ao_rinsn;
s = &dev->subdevices[1];
ret = subdev_8255_init(dev, s, NULL,
dev->iobase + PCIMDDA_8255_BASE_REG);
if (ret)
return ret;
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 1;
}
static void cb_pcimdda_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->subdevices)
subdev_8255_cleanup(dev, &dev->subdevices[1]);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int cb_pcimdda_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcimdda_driver);
}
static void cb_pcimdda_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
