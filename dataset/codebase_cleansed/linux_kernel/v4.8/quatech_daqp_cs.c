static int daqp_clear_events(struct comedi_device *dev, int loops)
{
unsigned int status;
while (--loops) {
status = inb(dev->iobase + DAQP_STATUS_REG);
if ((status & DAQP_STATUS_EVENTS) == 0)
return 0;
}
dev_err(dev->class_dev, "couldn't clear events in status register\n");
return -EBUSY;
}
static int daqp_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct daqp_private *devpriv = dev->private;
if (devpriv->stop)
return -EIO;
outb(DAQP_CMD_STOP, dev->iobase + DAQP_CMD_REG);
outb(0, dev->iobase + DAQP_CTRL_REG);
inb(dev->iobase + DAQP_STATUS_REG);
return 0;
}
static unsigned int daqp_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inb(dev->iobase + DAQP_AI_FIFO_REG);
val |= inb(dev->iobase + DAQP_AI_FIFO_REG) << 8;
return comedi_offset_munge(s, val);
}
static irqreturn_t daqp_interrupt(int irq, void *dev_id)
{
struct comedi_device *dev = dev_id;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
int loop_limit = 10000;
int status;
if (!dev->attached)
return IRQ_NONE;
status = inb(dev->iobase + DAQP_STATUS_REG);
if (!(status & DAQP_STATUS_EVENTS))
return IRQ_NONE;
while (!(status & DAQP_STATUS_FIFO_EMPTY)) {
unsigned short data;
if (status & DAQP_STATUS_DATA_LOST) {
s->async->events |= COMEDI_CB_OVERFLOW;
dev_warn(dev->class_dev, "data lost\n");
break;
}
data = daqp_ai_get_sample(dev, s);
comedi_buf_write_samples(s, &data, 1);
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg) {
s->async->events |= COMEDI_CB_EOA;
break;
}
if ((loop_limit--) <= 0)
break;
status = inb(dev->iobase + DAQP_STATUS_REG);
}
if (loop_limit <= 0) {
dev_warn(dev->class_dev,
"loop_limit reached in daqp_interrupt()\n");
s->async->events |= COMEDI_CB_ERROR;
}
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static void daqp_ai_set_one_scanlist_entry(struct comedi_device *dev,
unsigned int chanspec,
int start)
{
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
unsigned int val;
val = DAQP_SCANLIST_CHANNEL(chan) | DAQP_SCANLIST_GAIN(range);
if (aref == AREF_DIFF)
val |= DAQP_SCANLIST_DIFFERENTIAL;
if (start)
val |= DAQP_SCANLIST_START;
outb(val & 0xff, dev->iobase + DAQP_SCANLIST_REG);
outb((val >> 8) & 0xff, dev->iobase + DAQP_SCANLIST_REG);
}
static int daqp_ai_eos(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAQP_AUX_REG);
if (status & DAQP_AUX_CONVERSION)
return 0;
return -EBUSY;
}
static int daqp_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
int ret = 0;
int i;
if (devpriv->stop)
return -EIO;
outb(0, dev->iobase + DAQP_AUX_REG);
outb(DAQP_CMD_RSTQ, dev->iobase + DAQP_CMD_REG);
daqp_ai_set_one_scanlist_entry(dev, insn->chanspec, 1);
outb(DAQP_CMD_RSTF, dev->iobase + DAQP_CMD_REG);
outb(DAQP_CTRL_PACER_CLK_100KHZ, dev->iobase + DAQP_CTRL_REG);
ret = daqp_clear_events(dev, 10000);
if (ret)
return ret;
for (i = 0; i < insn->n; i++) {
outb(DAQP_CMD_ARM | DAQP_CMD_FIFO_DATA,
dev->iobase + DAQP_CMD_REG);
ret = comedi_timeout(dev, s, insn, daqp_ai_eos, 0);
if (ret)
break;
inb(dev->iobase + DAQP_STATUS_REG);
data[i] = daqp_ai_get_sample(dev, s);
}
outb(DAQP_CMD_STOP, dev->iobase + DAQP_CMD_REG);
inb(dev->iobase + DAQP_STATUS_REG);
return ret ? ret : insn->n;
}
static int daqp_ns_to_timer(unsigned int *ns, unsigned int flags)
{
int timer;
timer = *ns / 200;
*ns = timer * 200;
return timer;
}
static void daqp_set_pacer(struct comedi_device *dev, unsigned int val)
{
outb(val & 0xff, dev->iobase + DAQP_PACER_LOW_REG);
outb((val >> 8) & 0xff, dev->iobase + DAQP_PACER_MID_REG);
outb((val >> 16) & 0xff, dev->iobase + DAQP_PACER_HIGH_REG);
}
static int daqp_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct daqp_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src != TRIG_TIMER && cmd->convert_src != TRIG_TIMER)
err |= -EINVAL;
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
DAQP_MAX_TIMER_SPEED);
if (cmd->convert_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
DAQP_MAX_TIMER_SPEED);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg,
arg);
}
}
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
devpriv->pacer_div = daqp_ns_to_timer(&arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
} else if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
devpriv->pacer_div = daqp_ns_to_timer(&arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
return 0;
}
static int daqp_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct daqp_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int scanlist_start_on_every_entry;
int threshold;
int ret;
int i;
if (devpriv->stop)
return -EIO;
outb(0, dev->iobase + DAQP_AUX_REG);
outb(DAQP_CMD_RSTQ, dev->iobase + DAQP_CMD_REG);
daqp_set_pacer(dev, devpriv->pacer_div);
if (cmd->convert_src == TRIG_TIMER)
scanlist_start_on_every_entry = 1;
else
scanlist_start_on_every_entry = 0;
for (i = 0; i < cmd->chanlist_len; i++) {
int start = (i == 0 || scanlist_start_on_every_entry);
daqp_ai_set_one_scanlist_entry(dev, cmd->chanlist[i], start);
}
if (cmd->stop_src == TRIG_COUNT) {
unsigned long long nsamples;
unsigned long long nbytes;
nsamples = (unsigned long long)cmd->stop_arg *
cmd->scan_end_arg;
nbytes = nsamples * comedi_bytes_per_sample(s);
while (nbytes > DAQP_FIFO_SIZE * 3 / 4)
nbytes /= 2;
threshold = nbytes;
} else {
threshold = DAQP_FIFO_SIZE / 2;
}
outb(DAQP_CMD_RSTF, dev->iobase + DAQP_CMD_REG);
outb(0x00, dev->iobase + DAQP_AI_FIFO_REG);
outb(0x00, dev->iobase + DAQP_AI_FIFO_REG);
outb((DAQP_FIFO_SIZE - threshold) & 0xff,
dev->iobase + DAQP_AI_FIFO_REG);
outb((DAQP_FIFO_SIZE - threshold) >> 8, dev->iobase + DAQP_AI_FIFO_REG);
outb(DAQP_CTRL_TRIG_MODE | DAQP_CTRL_PACER_CLK_5MHZ |
DAQP_CTRL_FIFO_INT_ENA, dev->iobase + DAQP_CTRL_REG);
ret = daqp_clear_events(dev, 100);
if (ret)
return ret;
outb(DAQP_CMD_ARM | DAQP_CMD_FIFO_DATA, dev->iobase + DAQP_CMD_REG);
return 0;
}
static int daqp_ao_empty(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAQP_AUX_REG);
if ((status & DAQP_AUX_DA_BUFFER) == 0)
return 0;
return -EBUSY;
}
static int daqp_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
if (devpriv->stop)
return -EIO;
outb(0, dev->iobase + DAQP_AUX_REG);
for (i = 0; i > insn->n; i++) {
unsigned int val = data[i];
int ret;
ret = comedi_timeout(dev, s, insn, daqp_ao_empty, 0);
if (ret)
return ret;
outw((chan << 12) | comedi_offset_munge(s, val),
dev->iobase + DAQP_AO_REG);
s->readback[chan] = val;
}
return insn->n;
}
static int daqp_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
if (devpriv->stop)
return -EIO;
data[0] = inb(dev->iobase + DAQP_DI_REG);
return insn->n;
}
static int daqp_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
if (devpriv->stop)
return -EIO;
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAQP_DO_REG);
data[1] = s->state;
return insn->n;
}
static int daqp_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
struct daqp_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
link->config_flags |= CONF_AUTO_SET_IO | CONF_ENABLE_IRQ;
ret = comedi_pcmcia_enable(dev, NULL);
if (ret)
return ret;
dev->iobase = link->resource[0]->start;
link->priv = dev;
ret = pcmcia_request_irq(link, daqp_interrupt);
if (ret == 0)
dev->irq = link->irq;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 8;
s->maxdata = 0xffff;
s->range_table = &range_daqp_ai;
s->insn_read = daqp_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 2048;
s->do_cmdtest = daqp_ai_cmdtest;
s->do_cmd = daqp_ai_cmd;
s->cancel = daqp_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &range_bipolar5;
s->insn_write = daqp_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->insn_bits = daqp_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->insn_bits = daqp_do_insn_bits;
return 0;
}
static int daqp_cs_suspend(struct pcmcia_device *link)
{
struct comedi_device *dev = link->priv;
struct daqp_private *devpriv = dev ? dev->private : NULL;
if (devpriv)
devpriv->stop = 1;
return 0;
}
static int daqp_cs_resume(struct pcmcia_device *link)
{
struct comedi_device *dev = link->priv;
struct daqp_private *devpriv = dev ? dev->private : NULL;
if (devpriv)
devpriv->stop = 0;
return 0;
}
static int daqp_cs_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_daqp);
}
