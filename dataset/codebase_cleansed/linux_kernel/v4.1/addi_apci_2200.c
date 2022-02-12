static int apci2200_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inw(dev->iobase + APCI2200_DI_REG);
return insn->n;
}
static int apci2200_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
s->state = inw(dev->iobase + APCI2200_DO_REG);
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + APCI2200_DO_REG);
data[1] = s->state;
return insn->n;
}
static int apci2200_reset(struct comedi_device *dev)
{
outw(0x0, dev->iobase + APCI2200_DO_REG);
addi_watchdog_reset(dev->iobase + APCI2200_WDOG_REG);
return 0;
}
static int apci2200_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 1);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci2200_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci2200_do_insn_bits;
s = &dev->subdevices[2];
ret = addi_watchdog_init(s, dev->iobase + APCI2200_WDOG_REG);
if (ret)
return ret;
apci2200_reset(dev);
return 0;
}
static void apci2200_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci2200_reset(dev);
comedi_pci_detach(dev);
}
static int apci2200_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci2200_driver, id->driver_data);
}
