static int daqp_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct daqp_private *devpriv = dev->private;
if (devpriv->stop)
return -EIO;
outb(DAQP_COMMAND_STOP, dev->iobase + DAQP_COMMAND);
devpriv->interrupt_mode = semaphore;
return 0;
}
static enum irqreturn daqp_interrupt(int irq, void *dev_id)
{
struct comedi_device *dev = dev_id;
struct daqp_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
int loop_limit = 10000;
int status;
if (!dev->attached)
return IRQ_NONE;
switch (devpriv->interrupt_mode) {
case semaphore:
complete(&devpriv->eos);
break;
case buffer:
while (!((status = inb(dev->iobase + DAQP_STATUS))
& DAQP_STATUS_FIFO_EMPTY)) {
unsigned short data;
if (status & DAQP_STATUS_DATA_LOST) {
s->async->events |=
COMEDI_CB_EOA | COMEDI_CB_OVERFLOW;
dev_warn(dev->class_dev, "data lost\n");
daqp_ai_cancel(dev, s);
break;
}
data = inb(dev->iobase + DAQP_FIFO);
data |= inb(dev->iobase + DAQP_FIFO) << 8;
data ^= 0x8000;
comedi_buf_put(s->async, data);
if (devpriv->count > 0) {
devpriv->count--;
if (devpriv->count == 0) {
daqp_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
break;
}
}
if ((loop_limit--) <= 0)
break;
}
if (loop_limit <= 0) {
dev_warn(dev->class_dev,
"loop_limit reached in daqp_interrupt()\n");
daqp_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
s->async->events |= COMEDI_CB_BLOCK;
comedi_event(dev, s);
}
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
outb(val & 0xff, dev->iobase + DAQP_SCANLIST);
outb((val >> 8) & 0xff, dev->iobase + DAQP_SCANLIST);
}
static int daqp_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
int i;
int v;
int counter = 10000;
if (devpriv->stop)
return -EIO;
daqp_ai_cancel(dev, s);
outb(0, dev->iobase + DAQP_AUX);
outb(DAQP_COMMAND_RSTQ, dev->iobase + DAQP_COMMAND);
daqp_ai_set_one_scanlist_entry(dev, insn->chanspec, 1);
outb(DAQP_COMMAND_RSTF, dev->iobase + DAQP_COMMAND);
v = DAQP_CONTROL_TRIGGER_ONESHOT | DAQP_CONTROL_TRIGGER_INTERNAL
| DAQP_CONTROL_PACER_100kHz | DAQP_CONTROL_EOS_INT_ENABLE;
outb(v, dev->iobase + DAQP_CONTROL);
while (--counter
&& (inb(dev->iobase + DAQP_STATUS) & DAQP_STATUS_EVENTS))
;
if (!counter) {
dev_err(dev->class_dev,
"couldn't clear interrupts in status register\n");
return -1;
}
init_completion(&devpriv->eos);
devpriv->interrupt_mode = semaphore;
for (i = 0; i < insn->n; i++) {
outb(DAQP_COMMAND_ARM | DAQP_COMMAND_FIFO_DATA,
dev->iobase + DAQP_COMMAND);
if (wait_for_completion_interruptible(&devpriv->eos))
return -EINTR;
data[i] = inb(dev->iobase + DAQP_FIFO);
data[i] |= inb(dev->iobase + DAQP_FIFO) << 8;
data[i] ^= 0x8000;
}
return insn->n;
}
static int daqp_ns_to_timer(unsigned int *ns, int round)
{
int timer;
timer = *ns / 200;
*ns = timer * 200;
return timer;
}
static int daqp_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
#define MAX_SPEED 10000
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED);
if (cmd->scan_begin_src == TRIG_TIMER && cmd->convert_src == TRIG_TIMER
&& cmd->scan_begin_arg != cmd->convert_arg * cmd->scan_end_arg) {
err |= -EINVAL;
}
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, MAX_SPEED);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
daqp_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
daqp_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
return 0;
}
static int daqp_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct daqp_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int counter;
int scanlist_start_on_every_entry;
int threshold;
int i;
int v;
if (devpriv->stop)
return -EIO;
daqp_ai_cancel(dev, s);
outb(0, dev->iobase + DAQP_AUX);
outb(DAQP_COMMAND_RSTQ, dev->iobase + DAQP_COMMAND);
if (cmd->convert_src == TRIG_TIMER) {
counter = daqp_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
outb(counter & 0xff, dev->iobase + DAQP_PACER_LOW);
outb((counter >> 8) & 0xff, dev->iobase + DAQP_PACER_MID);
outb((counter >> 16) & 0xff, dev->iobase + DAQP_PACER_HIGH);
scanlist_start_on_every_entry = 1;
} else {
counter = daqp_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
outb(counter & 0xff, dev->iobase + DAQP_PACER_LOW);
outb((counter >> 8) & 0xff, dev->iobase + DAQP_PACER_MID);
outb((counter >> 16) & 0xff, dev->iobase + DAQP_PACER_HIGH);
scanlist_start_on_every_entry = 0;
}
for (i = 0; i < cmd->chanlist_len; i++) {
int start = (i == 0 || scanlist_start_on_every_entry);
daqp_ai_set_one_scanlist_entry(dev, cmd->chanlist[i], start);
}
if (cmd->stop_src == TRIG_COUNT) {
devpriv->count = cmd->stop_arg * cmd->scan_end_arg;
threshold = 2 * devpriv->count;
while (threshold > DAQP_FIFO_SIZE * 3 / 4)
threshold /= 2;
} else {
devpriv->count = -1;
threshold = DAQP_FIFO_SIZE / 2;
}
outb(DAQP_COMMAND_RSTF, dev->iobase + DAQP_COMMAND);
outb(0x00, dev->iobase + DAQP_FIFO);
outb(0x00, dev->iobase + DAQP_FIFO);
outb((DAQP_FIFO_SIZE - threshold) & 0xff, dev->iobase + DAQP_FIFO);
outb((DAQP_FIFO_SIZE - threshold) >> 8, dev->iobase + DAQP_FIFO);
v = DAQP_CONTROL_TRIGGER_CONTINUOUS | DAQP_CONTROL_TRIGGER_INTERNAL
| DAQP_CONTROL_PACER_5MHz | DAQP_CONTROL_FIFO_INT_ENABLE;
outb(v, dev->iobase + DAQP_CONTROL);
counter = 100;
while (--counter
&& (inb(dev->iobase + DAQP_STATUS) & DAQP_STATUS_EVENTS))
;
if (!counter) {
dev_err(dev->class_dev,
"couldn't clear interrupts in status register\n");
return -1;
}
devpriv->interrupt_mode = buffer;
outb(DAQP_COMMAND_ARM | DAQP_COMMAND_FIFO_DATA,
dev->iobase + DAQP_COMMAND);
return 0;
}
static int daqp_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqp_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
int i;
if (devpriv->stop)
return -EIO;
outb(0, dev->iobase + DAQP_AUX);
for (i = 0; i > insn->n; i++) {
val = data[0];
val &= 0x0fff;
val ^= 0x0800;
val |= (chan << 12);
outw(val, dev->iobase + DAQP_DA);
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
data[0] = inb(dev->iobase + DAQP_DIGITAL_IO);
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
outb(s->state, dev->iobase + DAQP_DIGITAL_IO);
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
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = 8;
s->len_chanlist = 2048;
s->maxdata = 0xffff;
s->range_table = &range_daqp_ai;
s->insn_read = daqp_ai_insn_read;
s->do_cmdtest = daqp_ai_cmdtest;
s->do_cmd = daqp_ai_cmd;
s->cancel = daqp_ai_cancel;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &range_bipolar5;
s->insn_write = daqp_ao_insn_write;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->maxdata = 1;
s->insn_bits = daqp_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 1;
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
