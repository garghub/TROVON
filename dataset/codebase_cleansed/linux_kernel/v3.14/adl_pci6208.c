static int pci6208_ao_wait_for_data_send(struct comedi_device *dev,
unsigned int timeout)
{
unsigned int status;
while (timeout--) {
status = inw(dev->iobase + PCI6208_AO_STATUS);
if ((status & PCI6208_AO_STATUS_DATA_SEND) == 0)
return 0;
udelay(1);
}
return -ETIME;
}
static int pci6208_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci6208_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = devpriv->ao_readback[chan];
int ret;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
ret = pci6208_ao_wait_for_data_send(dev, 10);
if (ret)
return ret;
outw(comedi_offset_munge(s, val),
dev->iobase + PCI6208_AO_CONTROL(chan));
}
devpriv->ao_readback[chan] = val;
return insn->n;
}
static int pci6208_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci6208_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
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
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + PCI6208_DIO);
data[1] = s->state;
return insn->n;
}
static int pci6208_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci6208_board *boardinfo = NULL;
struct pci6208_private *devpriv;
struct comedi_subdevice *s;
unsigned int val;
int ret;
if (context < ARRAY_SIZE(pci6208_boards))
boardinfo = &pci6208_boards[context];
if (!boardinfo)
return -ENODEV;
dev->board_ptr = boardinfo;
dev->board_name = boardinfo->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
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
s->insn_write = pci6208_ao_insn_write;
s->insn_read = pci6208_ao_insn_read;
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
return 0;
}
static int adl_pci6208_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adl_pci6208_driver,
id->driver_data);
}
