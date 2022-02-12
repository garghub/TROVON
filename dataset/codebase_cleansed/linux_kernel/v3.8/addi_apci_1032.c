static int apci1032_reset(struct comedi_device *dev)
{
outl(0x0, dev->iobase + APCI1032_CTRL_REG);
inl(dev->iobase + APCI1032_STATUS_REG);
outl(0x0, dev->iobase + APCI1032_MODE1_REG);
outl(0x0, dev->iobase + APCI1032_MODE2_REG);
return 0;
}
static int apci1032_cos_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1032_private *devpriv = dev->private;
unsigned int shift, oldmask;
switch (data[0]) {
case INSN_CONFIG_DIGITAL_TRIG:
if (data[1] != 0)
return -EINVAL;
shift = data[3];
oldmask = (1U << shift) - 1;
switch (data[2]) {
case COMEDI_DIGITAL_TRIG_DISABLE:
devpriv->ctrl = 0;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
apci1032_reset(dev);
break;
case COMEDI_DIGITAL_TRIG_ENABLE_EDGES:
if (devpriv->ctrl != (APCI1032_CTRL_INT_ENA |
APCI1032_CTRL_INT_OR)) {
devpriv->ctrl = APCI1032_CTRL_INT_ENA |
APCI1032_CTRL_INT_OR;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
} else {
devpriv->mode1 &= oldmask;
devpriv->mode2 &= oldmask;
}
devpriv->mode1 |= data[4] << shift;
devpriv->mode2 |= data[5] << shift;
break;
case COMEDI_DIGITAL_TRIG_ENABLE_LEVELS:
if (devpriv->ctrl != (APCI1032_CTRL_INT_ENA |
APCI1032_CTRL_INT_AND)) {
devpriv->ctrl = APCI1032_CTRL_INT_ENA |
APCI1032_CTRL_INT_AND;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
} else {
devpriv->mode1 &= oldmask;
devpriv->mode2 &= oldmask;
}
devpriv->mode1 |= data[4] << shift;
devpriv->mode2 |= data[5] << shift;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static int apci1032_cos_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = s->state;
return 0;
}
static int apci1032_cos_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, 1);
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int apci1032_cos_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci1032_private *devpriv = dev->private;
if (!devpriv->ctrl) {
dev_warn(dev->class_dev,
"Interrupts disabled due to mode configuration!\n");
return -EINVAL;
}
outl(devpriv->mode1, dev->iobase + APCI1032_MODE1_REG);
outl(devpriv->mode2, dev->iobase + APCI1032_MODE2_REG);
outl(devpriv->ctrl, dev->iobase + APCI1032_CTRL_REG);
return 0;
}
static int apci1032_cos_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return apci1032_reset(dev);
}
static irqreturn_t apci1032_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct apci1032_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int ctrl;
if ((inl(devpriv->amcc_iobase + AMCC_OP_REG_INTCSR) &
INTCSR_INTR_ASSERTED) == 0)
return IRQ_NONE;
ctrl = inl(dev->iobase + APCI1032_CTRL_REG);
if ((ctrl & APCI1032_CTRL_INT_ENA) == 0)
return IRQ_HANDLED;
outl(ctrl & ~APCI1032_CTRL_INT_ENA, dev->iobase + APCI1032_CTRL_REG);
s->state = inl(dev->iobase + APCI1032_STATUS_REG) & 0xffff;
comedi_buf_put(s->async, s->state);
s->async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
comedi_event(dev, s);
outl(ctrl, dev->iobase + APCI1032_CTRL_REG);
return IRQ_HANDLED;
}
static int apci1032_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + APCI1032_DI_REG);
return insn->n;
}
static int apci1032_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct apci1032_private *devpriv;
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
devpriv->amcc_iobase = pci_resource_start(pcidev, 0);
dev->iobase = pci_resource_start(pcidev, 1);
apci1032_reset(dev);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci1032_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1032_di_insn_bits;
s = &dev->subdevices[1];
if (dev->irq) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI | SDF_CMD_READ;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = apci1032_cos_insn_config;
s->insn_bits = apci1032_cos_insn_bits;
s->do_cmdtest = apci1032_cos_cmdtest;
s->do_cmd = apci1032_cos_cmd;
s->cancel = apci1032_cos_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static void apci1032_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->iobase)
apci1032_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int apci1032_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci1032_driver);
}
static void apci1032_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
