static int adv_pci1724_dac_idle(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inl(dev->iobase + PCI1724_SYNC_CTRL_REG);
if ((status & PCI1724_SYNC_CTRL_DACSTAT) == 0)
return 0;
return -EBUSY;
}
static int adv_pci1724_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long mode = (unsigned long)s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int ctrl;
int ret;
int i;
ctrl = PCI1724_DAC_CTRL_GX(chan) | PCI1724_DAC_CTRL_CX(chan) | mode;
outl(0, dev->iobase + PCI1724_SYNC_CTRL_REG);
for (i = 0; i < insn->n; ++i) {
unsigned int val = data[i];
ret = comedi_timeout(dev, s, insn, adv_pci1724_dac_idle, 0);
if (ret)
return ret;
outl(ctrl | PCI1724_DAC_CTRL_DATA(val),
dev->iobase + PCI1724_DAC_CTRL_REG);
s->readback[chan] = val;
}
return insn->n;
}
static int adv_pci1724_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
unsigned int board_id;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
board_id = inl(dev->iobase + PCI1724_BOARD_ID_REG);
dev_info(dev->class_dev, "board id: %d\n",
board_id & PCI1724_BOARD_ID_MASK);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_GROUND;
s->n_chan = 32;
s->maxdata = 0x3fff;
s->range_table = &adv_pci1724_ao_ranges;
s->insn_write = adv_pci1724_insn_write;
s->private = (void *)PCI1724_DAC_CTRL_MODE_NORMAL;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 32;
s->maxdata = 0x3fff;
s->insn_write = adv_pci1724_insn_write;
s->private = (void *)PCI1724_DAC_CTRL_MODE_OFFSET;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 32;
s->maxdata = 0x3fff;
s->insn_write = adv_pci1724_insn_write;
s->private = (void *)PCI1724_DAC_CTRL_MODE_GAIN;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
return 0;
}
static int adv_pci1724_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adv_pci1724_driver,
id->driver_data);
}
