static int adl_pci8164_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long offset = (unsigned long)s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = inw(dev->iobase + PCI8164_AXIS(chan) + offset);
return insn->n;
}
static int adl_pci8164_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long offset = (unsigned long)s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
outw(data[i], dev->iobase + PCI8164_AXIS(chan) + offset);
return insn->n;
}
static int adl_pci8164_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read;
s->insn_write = adl_pci8164_insn_write;
s->private = (void *)PCI8164_CMD_MSTS_REG;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read;
s->insn_write = adl_pci8164_insn_write;
s->private = (void *)PCI8164_OTP_SSTS_REG;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read;
s->insn_write = adl_pci8164_insn_write;
s->private = (void *)PCI8164_BUF0_REG;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read;
s->insn_write = adl_pci8164_insn_write;
s->private = (void *)PCI8164_BUF1_REG;
return 0;
}
static int adl_pci8164_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adl_pci8164_driver,
id->driver_data);
}
