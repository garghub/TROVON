static void ni6527_set_filter_interval(struct comedi_device *dev,
unsigned int val)
{
struct ni6527_private *devpriv = dev->private;
if (val != devpriv->filter_interval) {
writeb(val & 0xff, dev->mmio + NI6527_FILT_INTERVAL_REG(0));
writeb((val >> 8) & 0xff,
dev->mmio + NI6527_FILT_INTERVAL_REG(1));
writeb((val >> 16) & 0x0f,
dev->mmio + NI6527_FILT_INTERVAL_REG(2));
writeb(NI6527_CLR_INTERVAL, dev->mmio + NI6527_CLR_REG);
devpriv->filter_interval = val;
}
}
static void ni6527_set_filter_enable(struct comedi_device *dev,
unsigned int val)
{
writeb(val & 0xff, dev->mmio + NI6527_FILT_ENA_REG(0));
writeb((val >> 8) & 0xff, dev->mmio + NI6527_FILT_ENA_REG(1));
writeb((val >> 16) & 0xff, dev->mmio + NI6527_FILT_ENA_REG(2));
}
static int ni6527_di_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni6527_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int interval;
switch (data[0]) {
case INSN_CONFIG_FILTER:
interval = (data[1] + 100) / 200;
data[1] = interval * 200;
if (interval) {
ni6527_set_filter_interval(dev, interval);
devpriv->filter_enable |= 1 << chan;
} else {
devpriv->filter_enable &= ~(1 << chan);
}
ni6527_set_filter_enable(dev, devpriv->filter_enable);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int ni6527_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int val;
val = readb(dev->mmio + NI6527_DI_REG(0));
val |= (readb(dev->mmio + NI6527_DI_REG(1)) << 8);
val |= (readb(dev->mmio + NI6527_DI_REG(2)) << 16);
data[1] = val;
return insn->n;
}
static int ni6527_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
mask = comedi_dio_update_state(s, data);
if (mask) {
unsigned int val = s->state ^ 0xffffff;
if (mask & 0x0000ff)
writeb(val & 0xff, dev->mmio + NI6527_DO_REG(0));
if (mask & 0x00ff00)
writeb((val >> 8) & 0xff,
dev->mmio + NI6527_DO_REG(1));
if (mask & 0xff0000)
writeb((val >> 16) & 0xff,
dev->mmio + NI6527_DO_REG(2));
}
data[1] = s->state;
return insn->n;
}
static irqreturn_t ni6527_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
status = readb(dev->mmio + NI6527_STATUS_REG);
if (!(status & NI6527_STATUS_IRQ))
return IRQ_NONE;
if (status & NI6527_STATUS_EDGE) {
comedi_buf_write_samples(s, &s->state, 1);
comedi_handle_events(dev, s);
}
writeb(NI6527_CLR_IRQS, dev->mmio + NI6527_CLR_REG);
return IRQ_HANDLED;
}
static int ni6527_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_OTHER);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT);
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
static int ni6527_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writeb(NI6527_CLR_IRQS, dev->mmio + NI6527_CLR_REG);
writeb(NI6527_CTRL_ENABLE_IRQS, dev->mmio + NI6527_CTRL_REG);
return 0;
}
static int ni6527_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writeb(NI6527_CTRL_DISABLE_IRQS, dev->mmio + NI6527_CTRL_REG);
return 0;
}
static int ni6527_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static void ni6527_set_edge_detection(struct comedi_device *dev,
unsigned int mask,
unsigned int rising,
unsigned int falling)
{
unsigned int i;
rising &= mask;
falling &= mask;
for (i = 0; i < 2; i++) {
if (mask & 0xff) {
if (~mask & 0xff) {
rising |= readb(dev->mmio +
NI6527_RISING_EDGE_REG(i)) &
(~mask & 0xff);
falling |= readb(dev->mmio +
NI6527_FALLING_EDGE_REG(i)) &
(~mask & 0xff);
}
writeb(rising & 0xff,
dev->mmio + NI6527_RISING_EDGE_REG(i));
writeb(falling & 0xff,
dev->mmio + NI6527_FALLING_EDGE_REG(i));
}
rising >>= 8;
falling >>= 8;
mask >>= 8;
}
}
static int ni6527_intr_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = 0xffffffff;
unsigned int rising, falling, shift;
switch (data[0]) {
case INSN_CONFIG_CHANGE_NOTIFY:
if (insn->n != 3)
return -EINVAL;
rising = data[1];
falling = data[2];
ni6527_set_edge_detection(dev, mask, rising, falling);
break;
case INSN_CONFIG_DIGITAL_TRIG:
if (data[1] != 0)
return -EINVAL;
switch (data[2]) {
case COMEDI_DIGITAL_TRIG_DISABLE:
rising = 0;
falling = 0;
break;
case COMEDI_DIGITAL_TRIG_ENABLE_EDGES:
shift = data[3];
if (shift >= s->n_chan) {
mask = 0;
rising = 0;
falling = 0;
} else {
mask <<= shift;
rising = data[4] << shift;
falling = data[5] << shift;
}
break;
default:
return -EINVAL;
}
ni6527_set_edge_detection(dev, mask, rising, falling);
break;
default:
return -EINVAL;
}
return insn->n;
}
static void ni6527_reset(struct comedi_device *dev)
{
ni6527_set_filter_enable(dev, 0);
ni6527_set_edge_detection(dev, 0xffffffff, 0, 0);
writeb(NI6527_CLR_IRQS | NI6527_CLR_RESET_FILT,
dev->mmio + NI6527_CLR_REG);
writeb(NI6527_CTRL_DISABLE_IRQS, dev->mmio + NI6527_CTRL_REG);
}
static int ni6527_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni6527_board *board = NULL;
struct ni6527_private *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(ni6527_boards))
board = &ni6527_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 1);
if (!dev->mmio)
return -ENOMEM;
if (readb(dev->mmio + NI6527_ID_REG) != 0x27)
return -ENODEV;
ni6527_reset(dev);
ret = request_irq(pcidev->irq, ni6527_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 24;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = ni6527_di_insn_config;
s->insn_bits = ni6527_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni6527_do_insn_bits;
s = &dev->subdevices[2];
if (dev->irq) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = ni6527_intr_insn_config;
s->insn_bits = ni6527_intr_insn_bits;
s->len_chanlist = 1;
s->do_cmdtest = ni6527_intr_cmdtest;
s->do_cmd = ni6527_intr_cmd;
s->cancel = ni6527_intr_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static void ni6527_detach(struct comedi_device *dev)
{
if (dev->mmio)
ni6527_reset(dev);
comedi_pci_detach(dev);
}
static int ni6527_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni6527_driver, id->driver_data);
}
