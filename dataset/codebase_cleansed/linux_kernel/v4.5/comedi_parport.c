static int parport_data_reg_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + PARPORT_DATA_REG);
data[1] = inb(dev->iobase + PARPORT_DATA_REG);
return insn->n;
}
static int parport_data_reg_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int ctrl;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0xff);
if (ret)
return ret;
ctrl = inb(dev->iobase + PARPORT_CTRL_REG);
if (s->io_bits)
ctrl &= ~PARPORT_CTRL_BIDIR_ENA;
else
ctrl |= PARPORT_CTRL_BIDIR_ENA;
outb(ctrl, dev->iobase + PARPORT_CTRL_REG);
return insn->n;
}
static int parport_status_reg_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + PARPORT_STATUS_REG) >> 3;
return insn->n;
}
static int parport_ctrl_reg_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int ctrl;
if (comedi_dio_update_state(s, data)) {
ctrl = inb(dev->iobase + PARPORT_CTRL_REG);
ctrl &= (PARPORT_CTRL_IRQ_ENA | PARPORT_CTRL_BIDIR_ENA);
ctrl |= s->state;
outb(ctrl, dev->iobase + PARPORT_CTRL_REG);
}
data[1] = s->state;
return insn->n;
}
static int parport_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int parport_intr_cmdtest(struct comedi_device *dev,
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
static int parport_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int ctrl;
ctrl = inb(dev->iobase + PARPORT_CTRL_REG);
ctrl |= PARPORT_CTRL_IRQ_ENA;
outb(ctrl, dev->iobase + PARPORT_CTRL_REG);
return 0;
}
static int parport_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int ctrl;
ctrl = inb(dev->iobase + PARPORT_CTRL_REG);
ctrl &= ~PARPORT_CTRL_IRQ_ENA;
outb(ctrl, dev->iobase + PARPORT_CTRL_REG);
return 0;
}
static irqreturn_t parport_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int ctrl;
ctrl = inb(dev->iobase + PARPORT_CTRL_REG);
if (!(ctrl & PARPORT_CTRL_IRQ_ENA))
return IRQ_NONE;
comedi_buf_write_samples(s, &s->state, 1);
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int parport_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x03);
if (ret)
return ret;
if (it->options[1]) {
ret = request_irq(it->options[1], parport_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, dev->irq ? 4 : 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_data_reg_insn_bits;
s->insn_config = parport_data_reg_insn_config;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 5;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_status_reg_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_ctrl_reg_insn_bits;
if (dev->irq) {
s = &dev->subdevices[3];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_intr_insn_bits;
s->len_chanlist = 1;
s->do_cmdtest = parport_intr_cmdtest;
s->do_cmd = parport_intr_cmd;
s->cancel = parport_intr_cancel;
}
outb(0, dev->iobase + PARPORT_DATA_REG);
outb(0, dev->iobase + PARPORT_CTRL_REG);
return 0;
}
