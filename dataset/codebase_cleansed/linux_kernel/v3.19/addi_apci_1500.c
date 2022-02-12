static int apci1500_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct apci1500_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 1);
devpriv->iobase = dev->iobase;
devpriv->i_IobaseAmcc = pci_resource_start(pcidev, 0);
devpriv->i_IobaseAddon = pci_resource_start(pcidev, 2);
devpriv->i_IobaseReserved = pci_resource_start(pcidev, 3);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci1500_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = apci1500_di_config;
s->insn_read = apci1500_di_read;
s->insn_write = apci1500_di_write;
s->insn_bits = apci1500_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = apci1500_do_config;
s->insn_write = apci1500_do_write;
s->insn_bits = apci1500_do_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 1;
s->maxdata = 0;
s->len_chanlist = 1;
s->range_table = &range_digital;
s->insn_write = apci1500_timer_write;
s->insn_read = apci1500_timer_read;
s->insn_config = apci1500_timer_config;
s->insn_bits = apci1500_timer_bits;
apci1500_reset(dev);
return 0;
}
static void apci1500_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci1500_reset(dev);
comedi_pci_detach(dev);
}
static int apci1500_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1500_driver, id->driver_data);
}
