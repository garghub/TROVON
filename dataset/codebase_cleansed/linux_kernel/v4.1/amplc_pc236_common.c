static void pc236_intr_update(struct comedi_device *dev, bool enable)
{
const struct pc236_board *thisboard = dev->board_ptr;
struct pc236_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->enable_irq = enable;
if (thisboard->intr_update_cb)
thisboard->intr_update_cb(dev, enable);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static bool pc236_intr_check(struct comedi_device *dev)
{
const struct pc236_board *thisboard = dev->board_ptr;
struct pc236_private *devpriv = dev->private;
bool retval = false;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
if (devpriv->enable_irq) {
if (thisboard->intr_chk_clr_cb)
retval = thisboard->intr_chk_clr_cb(dev);
else
retval = true;
}
spin_unlock_irqrestore(&dev->spinlock, flags);
return retval;
}
static int pc236_intr_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int pc236_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int pc236_intr_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
pc236_intr_update(dev, true);
return 0;
}
static int pc236_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
pc236_intr_update(dev, false);
return 0;
}
static irqreturn_t pc236_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
bool handled;
handled = pc236_intr_check(dev);
if (dev->attached && handled) {
comedi_buf_write_samples(s, &s->state, 1);
comedi_handle_events(dev, s);
}
return IRQ_RETVAL(handled);
}
int amplc_pc236_common_attach(struct comedi_device *dev, unsigned long iobase,
unsigned int irq, unsigned long req_irq_flags)
{
struct comedi_subdevice *s;
int ret;
dev->iobase = iobase;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
ret = subdev_8255_init(dev, s, NULL, 0x00);
if (ret)
return ret;
s = &dev->subdevices[1];
dev->read_subdev = s;
s->type = COMEDI_SUBD_UNUSED;
pc236_intr_update(dev, false);
if (irq) {
if (request_irq(irq, pc236_interrupt, req_irq_flags,
dev->board_name, dev) >= 0) {
dev->irq = irq;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pc236_intr_insn;
s->len_chanlist = 1;
s->do_cmdtest = pc236_intr_cmdtest;
s->do_cmd = pc236_intr_cmd;
s->cancel = pc236_intr_cancel;
}
}
return 0;
}
static int __init amplc_pc236_common_init(void)
{
return 0;
}
static void __exit amplc_pc236_common_exit(void)
{
}
