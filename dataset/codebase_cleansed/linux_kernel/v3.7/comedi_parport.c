static int parport_insn_a(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct parport_private *devpriv = dev->private;
if (data[0]) {
devpriv->a_data &= ~data[0];
devpriv->a_data |= (data[0] & data[1]);
outb(devpriv->a_data, dev->iobase + PARPORT_A);
}
data[1] = inb(dev->iobase + PARPORT_A);
return insn->n;
}
static int parport_insn_config_a(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct parport_private *devpriv = dev->private;
if (data[0]) {
s->io_bits = 0xff;
devpriv->c_data &= ~(1 << 5);
} else {
s->io_bits = 0;
devpriv->c_data |= (1 << 5);
}
outb(devpriv->c_data, dev->iobase + PARPORT_C);
return 1;
}
static int parport_insn_b(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
}
data[1] = (inb(dev->iobase + PARPORT_B) >> 3);
return insn->n;
}
static int parport_insn_c(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct parport_private *devpriv = dev->private;
data[0] &= 0x0f;
if (data[0]) {
devpriv->c_data &= ~data[0];
devpriv->c_data |= (data[0] & data[1]);
outb(devpriv->c_data, dev->iobase + PARPORT_C);
}
data[1] = devpriv->c_data & 0xf;
return insn->n;
}
static int parport_intr_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int parport_intr_cmdtest(struct comedi_device *dev,
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
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
if (cmd->convert_arg != 0) {
cmd->convert_arg = 0;
err++;
}
if (cmd->scan_end_arg != 1) {
cmd->scan_end_arg = 1;
err++;
}
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int parport_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct parport_private *devpriv = dev->private;
devpriv->c_data |= 0x10;
outb(devpriv->c_data, dev->iobase + PARPORT_C);
devpriv->enable_irq = 1;
return 0;
}
static int parport_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct parport_private *devpriv = dev->private;
devpriv->c_data &= ~0x10;
outb(devpriv->c_data, dev->iobase + PARPORT_C);
devpriv->enable_irq = 0;
return 0;
}
static irqreturn_t parport_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct parport_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[3];
if (!devpriv->enable_irq)
return IRQ_NONE;
comedi_buf_put(s->async, 0);
s->async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int parport_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct parport_private *devpriv;
int ret;
unsigned int irq;
unsigned long iobase;
struct comedi_subdevice *s;
dev->board_name = dev->driver->driver_name;
iobase = it->options[0];
if (!request_region(iobase, PARPORT_SIZE, dev->board_name)) {
dev_err(dev->class_dev, "I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
irq = it->options[1];
if (irq) {
ret = request_irq(irq, parport_interrupt, 0, dev->board_name,
dev);
if (ret < 0) {
dev_err(dev->class_dev, "irq not available\n");
return -EINVAL;
}
dev->irq = irq;
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
ret = alloc_private(dev, sizeof(*devpriv));
if (ret < 0)
return ret;
devpriv = dev->private;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_insn_a;
s->insn_config = parport_insn_config_a;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 5;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_insn_b;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_insn_c;
s = &dev->subdevices[3];
if (irq) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = parport_intr_insn;
s->do_cmdtest = parport_intr_cmdtest;
s->do_cmd = parport_intr_cmd;
s->cancel = parport_intr_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
devpriv->a_data = 0;
outb(devpriv->a_data, dev->iobase + PARPORT_A);
devpriv->c_data = 0;
outb(devpriv->c_data, dev->iobase + PARPORT_C);
dev_info(dev->class_dev, "%s: iobase=0x%04lx, irq %sabled",
dev->board_name, dev->iobase, dev->irq ? "en" : "dis");
return 0;
}
static void parport_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, PARPORT_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
}
