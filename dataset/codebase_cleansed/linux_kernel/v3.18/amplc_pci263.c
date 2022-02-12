static int pci263_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, dev->iobase);
outb((s->state >> 8) & 0xff, dev->iobase + 1);
}
data[1] = s->state;
return insn->n;
}
static int pci263_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pci_dev, 2);
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci263_do_insn_bits;
s->state = inb(dev->iobase) | (inb(dev->iobase + 1) << 8);
return 0;
}
static int amplc_pci263_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &amplc_pci263_driver,
id->driver_data);
}
