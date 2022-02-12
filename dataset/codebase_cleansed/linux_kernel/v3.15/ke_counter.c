static int ke_counter_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
int i;
for (i = 0; i < insn->n; i++) {
val = data[0];
outb((val >> 24) & 0xff, dev->iobase + KE_SIGN_REG(chan));
outb((val >> 16) & 0xff, dev->iobase + KE_MSB_REG(chan));
outb((val >> 8) & 0xff, dev->iobase + KE_MID_REG(chan));
outb((val >> 0) & 0xff, dev->iobase + KE_LSB_REG(chan));
}
return insn->n;
}
static int ke_counter_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
int i;
for (i = 0; i < insn->n; i++) {
inb(dev->iobase + KE_LATCH_REG(chan));
val = inb(dev->iobase + KE_LSB_REG(chan));
val |= (inb(dev->iobase + KE_MID_REG(chan)) << 8);
val |= (inb(dev->iobase + KE_MSB_REG(chan)) << 16);
val |= (inb(dev->iobase + KE_SIGN_REG(chan)) << 24);
data[i] = val;
}
return insn->n;
}
static int ke_counter_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + KE_DO_REG);
data[1] = s->state;
return insn->n;
}
static int ke_counter_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 0);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE;
s->n_chan = 3;
s->maxdata = 0x01ffffff;
s->range_table = &range_unknown;
s->insn_read = ke_counter_insn_read;
s->insn_write = ke_counter_insn_write;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 3;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ke_counter_do_insn_bits;
outb(KE_OSC_SEL_20MHZ, dev->iobase + KE_OSC_SEL_REG);
outb(0, dev->iobase + KE_RESET_REG(0));
outb(0, dev->iobase + KE_RESET_REG(1));
outb(0, dev->iobase + KE_RESET_REG(2));
return 0;
}
static int ke_counter_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ke_counter_driver,
id->driver_data);
}
