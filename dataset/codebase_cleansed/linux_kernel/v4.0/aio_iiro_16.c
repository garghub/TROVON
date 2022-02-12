static unsigned int aio_iiro_16_read_inputs(struct comedi_device *dev)
{
unsigned int val;
val = inb(dev->iobase + AIO_IIRO_16_INPUT_0_7);
val |= inb(dev->iobase + AIO_IIRO_16_INPUT_8_15) << 8;
return val;
}
static irqreturn_t aio_iiro_16_cos(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
unsigned int val;
status = inb(dev->iobase + AIO_IIRO_16_STATUS);
if (!(status & AIO_IIRO_16_STATUS_IRQE))
return IRQ_NONE;
val = aio_iiro_16_read_inputs(dev);
val |= (status << 16);
comedi_buf_write_samples(s, &val, 1);
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static void aio_iiro_enable_irq(struct comedi_device *dev, bool enable)
{
if (enable)
inb(dev->iobase + AIO_IIRO_16_IRQ);
else
outb(0, dev->iobase + AIO_IIRO_16_IRQ);
}
static int aio_iiro_16_cos_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
aio_iiro_enable_irq(dev, false);
return 0;
}
static int aio_iiro_16_cos_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
aio_iiro_enable_irq(dev, true);
return 0;
}
static int aio_iiro_16_cos_cmdtest(struct comedi_device *dev,
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
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int aio_iiro_16_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, dev->iobase + AIO_IIRO_16_RELAY_0_7);
outb((s->state >> 8) & 0xff,
dev->iobase + AIO_IIRO_16_RELAY_8_15);
}
data[1] = s->state;
return insn->n;
}
static int aio_iiro_16_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = aio_iiro_16_read_inputs(dev);
return insn->n;
}
static int aio_iiro_16_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x8);
if (ret)
return ret;
aio_iiro_enable_irq(dev, false);
if ((1 << it->options[1]) & 0xdcfc) {
ret = request_irq(it->options[1], aio_iiro_16_cos, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = aio_iiro_16_do_insn_bits;
s->state = inb(dev->iobase + AIO_IIRO_16_RELAY_0_7) |
(inb(dev->iobase + AIO_IIRO_16_RELAY_8_15) << 8);
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = aio_iiro_16_di_insn_bits;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ | SDF_LSAMPL;
s->len_chanlist = 1;
s->do_cmdtest = aio_iiro_16_cos_cmdtest;
s->do_cmd = aio_iiro_16_cos_cmd;
s->cancel = aio_iiro_16_cos_cancel;
}
return 0;
}
