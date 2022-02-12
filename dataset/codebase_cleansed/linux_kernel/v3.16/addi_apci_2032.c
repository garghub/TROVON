static int apci2032_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
s->state = inl(dev->iobase + APCI2032_DO_REG);
if (comedi_dio_update_state(s, data))
outl(s->state, dev->iobase + APCI2032_DO_REG);
data[1] = s->state;
return insn->n;
}
static int apci2032_int_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + APCI2032_INT_STATUS_REG) & 3;
return insn->n;
}
static void apci2032_int_stop(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci2032_int_private *subpriv = s->private;
subpriv->active = false;
subpriv->enabled_isns = 0;
outl(0x0, dev->iobase + APCI2032_INT_CTRL_REG);
}
static bool apci2032_int_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned char enabled_isns)
{
struct apci2032_int_private *subpriv = s->private;
struct comedi_cmd *cmd = &s->async->cmd;
bool do_event;
subpriv->enabled_isns = enabled_isns;
subpriv->stop_count = cmd->stop_arg;
if (cmd->stop_src == TRIG_COUNT && subpriv->stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
subpriv->active = false;
do_event = true;
} else {
subpriv->active = true;
outl(enabled_isns, dev->iobase + APCI2032_INT_CTRL_REG);
do_event = false;
}
return do_event;
}
static int apci2032_int_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_NONE)
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
struct apci2032_int_private *subpriv = s->private;
unsigned char enabled_isns;
unsigned int n;
unsigned long flags;
bool do_event;
enabled_isns = 0;
for (n = 0; n < cmd->chanlist_len; n++)
enabled_isns |= 1 << CR_CHAN(cmd->chanlist[n]);
spin_lock_irqsave(&subpriv->spinlock, flags);
do_event = apci2032_int_start(dev, s, enabled_isns);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
if (do_event)
comedi_event(dev, s);
return 0;
}
static int apci2032_int_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci2032_int_private *subpriv = s->private;
unsigned long flags;
spin_lock_irqsave(&subpriv->spinlock, flags);
if (subpriv->active)
apci2032_int_stop(dev, s);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
return 0;
}
static irqreturn_t apci2032_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
struct apci2032_int_private *subpriv;
unsigned int val;
bool do_event = false;
if (!dev->attached)
return IRQ_NONE;
val = inl(dev->iobase + APCI2032_STATUS_REG) & APCI2032_STATUS_IRQ;
if (!val)
return IRQ_NONE;
subpriv = s->private;
spin_lock(&subpriv->spinlock);
val = inl(dev->iobase + APCI2032_INT_STATUS_REG) & 3;
outl(~val & 3, dev->iobase + APCI2032_INT_CTRL_REG);
if (subpriv->active && (val & subpriv->enabled_isns) != 0) {
unsigned short bits = 0;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
if (val & (1 << chan))
bits |= (1 << i);
}
if (comedi_buf_put(s, bits)) {
s->async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
if (cmd->stop_src == TRIG_COUNT &&
subpriv->stop_count > 0) {
subpriv->stop_count--;
if (subpriv->stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
apci2032_int_stop(dev, s);
}
}
} else {
apci2032_int_stop(dev, s);
s->async->events |= COMEDI_CB_OVERFLOW;
}
do_event = true;
}
spin_unlock(&subpriv->spinlock);
if (do_event)
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int apci2032_reset(struct comedi_device *dev)
{
outl(0x0, dev->iobase + APCI2032_DO_REG);
outl(0x0, dev->iobase + APCI2032_INT_CTRL_REG);
addi_watchdog_reset(dev->iobase + APCI2032_WDOG_REG);
return 0;
}
static int apci2032_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 1);
apci2032_reset(dev);
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
ret = addi_watchdog_init(s, dev->iobase + APCI2032_WDOG_REG);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 2;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci2032_int_insn_bits;
if (dev->irq) {
struct apci2032_int_private *subpriv;
dev->read_subdev = s;
subpriv = kzalloc(sizeof(*subpriv), GFP_KERNEL);
if (!subpriv)
return -ENOMEM;
spin_lock_init(&subpriv->spinlock);
s->private = subpriv;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->len_chanlist = 2;
s->do_cmdtest = apci2032_int_cmdtest;
s->do_cmd = apci2032_int_cmd;
s->cancel = apci2032_int_cancel;
}
return 0;
}
static void apci2032_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci2032_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->read_subdev)
kfree(dev->read_subdev->private);
comedi_pci_disable(dev);
}
static int apci2032_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci2032_driver, id->driver_data);
}
