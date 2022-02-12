static irqreturn_t v_ADDI_Interrupt(int irq, void *d)
{
apci1564_interrupt(irq, d);
return IRQ_RETVAL(1);
}
static int apci1564_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
data[1] = inl(devpriv->i_IobaseAmcc + APCI1564_DI_REG);
return insn->n;
}
static int apci1564_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
s->state = inl(devpriv->i_IobaseAmcc + APCI1564_DO_REG);
if (comedi_dio_update_state(s, data))
outl(s->state, devpriv->i_IobaseAmcc + APCI1564_DO_REG);
data[1] = s->state;
return insn->n;
}
static int apci1564_reset(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
ui_Type = 0;
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DI_IRQ_REG);
inl(devpriv->i_IobaseAmcc + APCI1564_DI_INT_STATUS_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DI_INT_MODE1_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DI_INT_MODE2_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DO_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DO_INT_CTRL_REG);
addi_watchdog_reset(devpriv->i_IobaseAmcc + APCI1564_WDOG_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_TIMER_CTRL_REG);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_TIMER_RELOAD_REG);
outl(0x0, dev->iobase + APCI1564_TCW_CTRL_REG(APCI1564_COUNTER1));
outl(0x0, dev->iobase + APCI1564_TCW_CTRL_REG(APCI1564_COUNTER2));
outl(0x0, dev->iobase + APCI1564_TCW_CTRL_REG(APCI1564_COUNTER3));
outl(0x0, dev->iobase + APCI1564_TCW_CTRL_REG(APCI1564_COUNTER4));
return 0;
}
static int apci1564_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct addi_private *devpriv;
struct comedi_subdevice *s;
int ret;
dev->board_name = dev->driver->driver_name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 1);
devpriv->i_IobaseAmcc = pci_resource_start(pcidev, 0);
apci1564_reset(dev);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, v_ADDI_Interrupt, IRQF_SHARED,
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
s->n_chan = 32;
s->maxdata = 1;
s->len_chanlist = 32;
s->range_table = &range_digital;
s->insn_config = apci1564_di_config;
s->insn_bits = apci1564_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 32;
s->maxdata = 0xffffffff;
s->len_chanlist = 32;
s->range_table = &range_digital;
s->insn_config = apci1564_do_config;
s->insn_bits = apci1564_do_insn_bits;
s->insn_read = apci1564_do_read;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 1;
s->maxdata = 0;
s->len_chanlist = 1;
s->range_table = &range_digital;
s->insn_write = apci1564_timer_write;
s->insn_read = apci1564_timer_read;
s->insn_config = apci1564_timer_config;
return 0;
}
static void apci1564_detach(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
if (devpriv) {
if (dev->iobase)
apci1564_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
}
comedi_pci_disable(dev);
}
static int apci1564_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1564_driver, id->driver_data);
}
