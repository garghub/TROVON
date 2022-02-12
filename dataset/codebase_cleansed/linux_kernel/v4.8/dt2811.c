static unsigned int dt2811_ai_read_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inb(dev->iobase + DT2811_ADDATA_LO_REG) |
(inb(dev->iobase + DT2811_ADDATA_HI_REG) << 8);
return val & s->maxdata;
}
static irqreturn_t dt2811_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status;
if (!dev->attached)
return IRQ_NONE;
status = inb(dev->iobase + DT2811_ADCSR_REG);
if (status & DT2811_ADCSR_ADERROR) {
async->events |= COMEDI_CB_OVERFLOW;
outb(status | DT2811_ADCSR_CLRERROR,
dev->iobase + DT2811_ADCSR_REG);
}
if (status & DT2811_ADCSR_ADDONE) {
unsigned short val;
val = dt2811_ai_read_sample(dev, s);
comedi_buf_write_samples(s, &val, 1);
}
if (cmd->stop_src == TRIG_COUNT && async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int dt2811_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outb(DT2811_ADCSR_ADMODE(0), dev->iobase + DT2811_ADCSR_REG);
return 0;
}
static void dt2811_ai_set_chanspec(struct comedi_device *dev,
unsigned int chanspec)
{
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
outb(DT2811_ADGCR_CHAN(chan) | DT2811_ADGCR_GAIN(range),
dev->iobase + DT2811_ADGCR_REG);
}
static int dt2811_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt2811_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int mode;
if (cmd->start_src == TRIG_NOW) {
mode = DT2811_ADCSR_ADMODE(1);
} else {
if (cmd->convert_src == TRIG_TIMER) {
mode = DT2811_ADCSR_ADMODE(2);
} else {
mode = DT2811_ADCSR_ADMODE(3);
}
}
outb(mode | DT2811_ADCSR_INTENB, dev->iobase + DT2811_ADCSR_REG);
outb(devpriv->ai_divisor, dev->iobase + DT2811_TMRCTR_REG);
dt2811_ai_set_chanspec(dev, cmd->chanlist[0]);
return 0;
}
static unsigned int dt2811_ns_to_timer(unsigned int *nanosec,
unsigned int flags)
{
unsigned long long ns = *nanosec;
unsigned int ns_lo = COMEDI_MIN_SPEED;
unsigned int ns_hi = 0;
unsigned int divisor_hi = 0;
unsigned int divisor_lo = 0;
unsigned int _div;
unsigned int _mult;
for (_div = 0; _div <= 7; _div++) {
for (_mult = 0; _mult <= 7; _mult++) {
unsigned int div = dt2811_clk_dividers[_div];
unsigned int mult = dt2811_clk_multipliers[_mult];
unsigned long long divider = div * mult;
unsigned int divisor = DT2811_TMRCTR_MANTISSA(_div) |
DT2811_TMRCTR_EXPONENT(_mult);
ns = divider * DT2811_OSC_BASE;
if (ns > COMEDI_MIN_SPEED)
continue;
if (ns <= *nanosec && ns > ns_hi) {
ns_hi = ns;
divisor_hi = divisor;
}
if (ns >= *nanosec && ns < ns_lo) {
ns_lo = ns;
divisor_lo = divisor;
}
}
}
if (ns_lo == COMEDI_MIN_SPEED) {
ns_lo = ns_hi;
divisor_lo = divisor_hi;
}
if (ns_hi == 0) {
ns_hi = ns_lo;
divisor_hi = divisor_lo;
}
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
if (ns_hi - *nanosec < *nanosec - ns_lo) {
*nanosec = ns_lo;
return divisor_lo;
}
*nanosec = ns_hi;
return divisor_hi;
case CMDF_ROUND_UP:
*nanosec = ns_lo;
return divisor_lo;
case CMDF_ROUND_DOWN:
*nanosec = ns_hi;
return divisor_hi;
}
}
static int dt2811_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct dt2811_private *devpriv = dev->private;
unsigned int arg;
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (cmd->convert_src == TRIG_EXT && cmd->start_src != TRIG_EXT)
err |= -EINVAL;
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 12500);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
devpriv->ai_divisor = dt2811_ns_to_timer(&arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
} else {
devpriv->ai_divisor = cmd->convert_arg;
}
if (err)
return 4;
return 0;
}
static int dt2811_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DT2811_ADCSR_REG);
if ((status & DT2811_ADCSR_ADBUSY) == 0)
return 0;
return -EBUSY;
}
static int dt2811_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
int i;
for (i = 0; i < insn->n; i++) {
dt2811_ai_set_chanspec(dev, insn->chanspec);
ret = comedi_timeout(dev, s, insn, dt2811_ai_eoc, 0);
if (ret)
return ret;
data[i] = dt2811_ai_read_sample(dev, s);
}
return insn->n;
}
static int dt2811_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outb(val & 0xff, dev->iobase + DT2811_DADATA_LO_REG(chan));
outb((val >> 8) & 0xff,
dev->iobase + DT2811_DADATA_HI_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int dt2811_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + DT2811_DI_REG);
return insn->n;
}
static int dt2811_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DT2811_DO_REG);
data[1] = s->state;
return insn->n;
}
static void dt2811_reset(struct comedi_device *dev)
{
outb(DT2811_ADCSR_ADMODE(0), dev->iobase + DT2811_ADCSR_REG);
usleep_range(100, 1000);
inb(dev->iobase + DT2811_ADDATA_LO_REG);
inb(dev->iobase + DT2811_ADDATA_HI_REG);
outb(DT2811_ADCSR_ADMODE(0) | DT2811_ADCSR_CLRERROR,
dev->iobase + DT2811_ADCSR_REG);
}
static int dt2811_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dt2811_board *board = dev->board_ptr;
struct dt2811_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x8);
if (ret)
return ret;
dt2811_reset(dev);
if (it->options[1] <= 7 && (BIT(it->options[1]) & 0xac)) {
ret = request_irq(it->options[1], dt2811_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE |
((it->options[2] == 1) ? SDF_DIFF :
(it->options[2] == 2) ? SDF_COMMON : SDF_GROUND);
s->n_chan = (it->options[2] == 1) ? 8 : 16;
s->maxdata = 0x0fff;
s->range_table = board->is_pgh ? &dt2811_pgh_ai_ranges
: &dt2811_pgl_ai_ranges;
s->insn_read = dt2811_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 1;
s->do_cmdtest = dt2811_ai_cmdtest;
s->do_cmd = dt2811_ai_cmd;
s->cancel = dt2811_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &dt2811_ao_ranges;
s->insn_write = dt2811_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2811_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt2811_do_insn_bits;
return 0;
}
