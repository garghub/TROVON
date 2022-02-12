static void pcl711_ai_set_mode(struct comedi_device *dev, unsigned int mode)
{
if (mode == PCL711_MODE_EXT_IRQ || mode == PCL711_MODE_PACER_IRQ)
mode |= PCL711_MODE_IRQ(dev->irq);
outb(mode, dev->iobase + PCL711_MODE_REG);
}
static unsigned int pcl711_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inb(dev->iobase + PCL711_AI_MSB_REG) << 8;
val |= inb(dev->iobase + PCL711_AI_LSB_REG);
return val & s->maxdata;
}
static int pcl711_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outb(PCL711_INT_STAT_CLR, dev->iobase + PCL711_INT_STAT_REG);
pcl711_ai_set_mode(dev, PCL711_MODE_SOFTTRIG);
return 0;
}
static irqreturn_t pcl711_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int data;
if (!dev->attached) {
dev_err(dev->class_dev, "spurious interrupt\n");
return IRQ_HANDLED;
}
data = pcl711_ai_get_sample(dev, s);
outb(PCL711_INT_STAT_CLR, dev->iobase + PCL711_INT_STAT_REG);
comedi_buf_write_samples(s, &data, 1);
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg)
s->async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static void pcl711_set_changain(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec)
{
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
unsigned int mux = 0;
outb(PCL711_AI_GAIN(range), dev->iobase + PCL711_AI_GAIN_REG);
if (s->n_chan > 8) {
if (aref == AREF_DIFF) {
chan &= 0x7;
mux |= PCL711_MUX_DIFF;
} else {
if (chan < 8)
mux |= PCL711_MUX_CS0;
else
mux |= PCL711_MUX_CS1;
}
}
outb(mux | PCL711_MUX_CHAN(chan), dev->iobase + PCL711_MUX_REG);
}
static int pcl711_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + PCL711_AI_MSB_REG);
if ((status & PCL711_AI_MSB_DRDY) == 0)
return 0;
return -EBUSY;
}
static int pcl711_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
int i;
pcl711_set_changain(dev, s, insn->chanspec);
pcl711_ai_set_mode(dev, PCL711_MODE_SOFTTRIG);
for (i = 0; i < insn->n; i++) {
outb(PCL711_SOFTTRIG, dev->iobase + PCL711_SOFTTRIG_REG);
ret = comedi_timeout(dev, s, insn, pcl711_ai_eoc, 0);
if (ret)
return ret;
data[i] = pcl711_ai_get_sample(dev, s);
}
return insn->n;
}
static int pcl711_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
struct pcl711_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_EXT) {
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
} else {
#define MAX_SPEED 1000
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED);
}
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_2MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
return 0;
}
static void pcl711_ai_load_counters(struct comedi_device *dev)
{
struct pcl711_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + PCL711_TIMER_BASE;
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
i8254_write(timer_base, 0, 2, devpriv->divisor2);
}
static int pcl711_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
pcl711_set_changain(dev, s, cmd->chanlist[0]);
if (cmd->scan_begin_src == TRIG_TIMER) {
pcl711_ai_load_counters(dev);
outb(PCL711_INT_STAT_CLR, dev->iobase + PCL711_INT_STAT_REG);
pcl711_ai_set_mode(dev, PCL711_MODE_PACER_IRQ);
} else {
pcl711_ai_set_mode(dev, PCL711_MODE_EXT_IRQ);
}
return 0;
}
static void pcl711_ao_write(struct comedi_device *dev,
unsigned int chan, unsigned int val)
{
outb(val & 0xff, dev->iobase + PCL711_AO_LSB_REG(chan));
outb((val >> 8) & 0xff, dev->iobase + PCL711_AO_MSB_REG(chan));
}
static int pcl711_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
pcl711_ao_write(dev, chan, val);
}
s->readback[chan] = val;
return insn->n;
}
static int pcl711_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int val;
val = inb(dev->iobase + PCL711_DI_LSB_REG);
val |= (inb(dev->iobase + PCL711_DI_MSB_REG) << 8);
data[1] = val;
return insn->n;
}
static int pcl711_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0x00ff)
outb(s->state & 0xff, dev->iobase + PCL711_DO_LSB_REG);
if (mask & 0xff00)
outb((s->state >> 8), dev->iobase + PCL711_DO_MSB_REG);
}
data[1] = s->state;
return insn->n;
}
static int pcl711_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl711_board *board = dev->board_ptr;
struct pcl711_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
if (it->options[1] && it->options[1] <= board->maxirq) {
ret = request_irq(it->options[1], pcl711_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
if (board->n_aichan > 8)
s->subdev_flags |= SDF_DIFF;
s->n_chan = board->n_aichan;
s->maxdata = 0xfff;
s->range_table = board->ai_range_type;
s->insn_read = pcl711_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 1;
s->do_cmdtest = pcl711_ai_cmdtest;
s->do_cmd = pcl711_ai_cmd;
s->cancel = pcl711_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_aochan;
s->maxdata = 0xfff;
s->range_table = &range_bipolar5;
s->insn_write = pcl711_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl711_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl711_do_insn_bits;
pcl711_ao_write(dev, 0, 0x0);
pcl711_ao_write(dev, 1, 0x0);
return 0;
}
