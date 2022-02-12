static int apci2032_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = data[0];
unsigned int bits = data[1];
s->state = inl(dev->iobase + APCI2032_DO_REG);
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outl(s->state, dev->iobase + APCI2032_DO_REG);
}
data[1] = s->state;
return insn->n;
}
static int apci2032_wdog_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci2032_private *devpriv = dev->private;
unsigned int reload;
switch (data[0]) {
case INSN_CONFIG_ARM:
devpriv->wdog_ctrl = APCI2032_WDOG_CTRL_ENABLE;
reload = data[1] & s->maxdata;
outw(reload, dev->iobase + APCI2032_WDOG_RELOAD_REG);
dev_info(dev->class_dev, "watchdog enabled, timeout:%dms\n",
20 * reload + 20);
break;
case INSN_CONFIG_DISARM:
devpriv->wdog_ctrl = 0;
break;
default:
return -EINVAL;
}
outw(devpriv->wdog_ctrl, dev->iobase + APCI2032_WDOG_CTRL_REG);
return insn->n;
}
static int apci2032_wdog_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci2032_private *devpriv = dev->private;
int i;
if (devpriv->wdog_ctrl == 0) {
dev_warn(dev->class_dev, "watchdog is disabled\n");
return -EINVAL;
}
for (i = 0; i < insn->n; i++) {
outw(devpriv->wdog_ctrl | APCI2032_WDOG_CTRL_SW_TRIG,
dev->iobase + APCI2032_WDOG_CTRL_REG);
}
return insn->n;
}
static int apci2032_wdog_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = inl(dev->iobase + APCI2032_WDOG_STATUS_REG);
return insn->n;
}
static int apci2032_int_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = s->state;
return insn->n;
}
static int apci2032_int_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_OTHER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 3);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, 1);
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int apci2032_int_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
outl(cmd->scan_begin_arg, dev->iobase + APCI2032_INT_CTRL_REG);
return 0;
}
static int apci2032_int_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outl(0x0, dev->iobase + APCI2032_INT_CTRL_REG);
return 0;
}
static irqreturn_t apci2032_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int val;
val = inl(dev->iobase + APCI2032_STATUS_REG) & APCI2032_STATUS_IRQ;
if (!val)
return IRQ_NONE;
s->state = inl(dev->iobase + APCI2032_INT_STATUS_REG);
outl(0x0, dev->iobase + APCI2032_INT_CTRL_REG);
comedi_buf_put(s->async, s->state);
s->async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int apci2032_reset(struct comedi_device *dev)
{
outl(0x0, dev->iobase + APCI2032_DO_REG);
outl(0x0, dev->iobase + APCI2032_INT_CTRL_REG);
outl(0x0, dev->iobase + APCI2032_WDOG_CTRL_REG);
outl(0x0, dev->iobase + APCI2032_WDOG_RELOAD_REG);
return 0;
}
static int apci2032_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct apci2032_private *devpriv;
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
dev->iobase = pci_resource_start(pcidev, 1);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci2032_interrupt,
IRQF_SHARED, dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci2032_do_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 1;
s->maxdata = 0xff;
s->insn_write = apci2032_wdog_insn_write;
s->insn_read = apci2032_wdog_insn_read;
s->insn_config = apci2032_wdog_insn_config;
s = &dev->subdevices[2];
if (dev->irq) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI | SDF_CMD_READ;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci2032_int_insn_bits;
s->do_cmdtest = apci2032_int_cmdtest;
s->do_cmd = apci2032_int_cmd;
s->cancel = apci2032_int_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
apci2032_reset(dev);
return 0;
}
static void apci2032_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->iobase)
apci2032_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int apci2032_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci2032_driver);
}
static void apci2032_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
