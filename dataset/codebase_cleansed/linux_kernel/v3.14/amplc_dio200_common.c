static unsigned char clk_gat_sce(unsigned int which, unsigned int chan,
unsigned int source)
{
return (which << 5) | (chan << 3) |
((source & 030) << 3) | (source & 007);
}
static unsigned char clk_sce(unsigned int which, unsigned int chan,
unsigned int source)
{
return clk_gat_sce(which, chan, source);
}
static unsigned char gat_sce(unsigned int which, unsigned int chan,
unsigned int source)
{
return clk_gat_sce(which, chan, source);
}
static inline const struct dio200_layout *
dio200_board_layout(const struct dio200_board *board)
{
return &board->layout;
}
static inline const struct dio200_layout *
dio200_dev_layout(struct comedi_device *dev)
{
return dio200_board_layout(comedi_board(dev));
}
static unsigned char dio200_read8(struct comedi_device *dev,
unsigned int offset)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
offset <<= thisboard->mainshift;
if (devpriv->io.regtype == io_regtype)
return inb(devpriv->io.u.iobase + offset);
else
return readb(devpriv->io.u.membase + offset);
}
static void dio200_write8(struct comedi_device *dev, unsigned int offset,
unsigned char val)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
offset <<= thisboard->mainshift;
if (devpriv->io.regtype == io_regtype)
outb(val, devpriv->io.u.iobase + offset);
else
writeb(val, devpriv->io.u.membase + offset);
}
static unsigned int dio200_read32(struct comedi_device *dev,
unsigned int offset)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
offset <<= thisboard->mainshift;
if (devpriv->io.regtype == io_regtype)
return inl(devpriv->io.u.iobase + offset);
else
return readl(devpriv->io.u.membase + offset);
}
static void dio200_write32(struct comedi_device *dev, unsigned int offset,
unsigned int val)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
offset <<= thisboard->mainshift;
if (devpriv->io.regtype == io_regtype)
outl(val, devpriv->io.u.iobase + offset);
else
writel(val, devpriv->io.u.membase + offset);
}
static int
dio200_subdev_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_intr *subpriv = s->private;
if (layout->has_int_sce) {
data[1] = dio200_read8(dev, subpriv->ofs) & subpriv->valid_isns;
} else {
data[0] = 0;
}
return insn->n;
}
static void dio200_stop_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_intr *subpriv = s->private;
subpriv->active = false;
subpriv->enabled_isns = 0;
if (layout->has_int_sce)
dio200_write8(dev, subpriv->ofs, 0);
}
static int dio200_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int n;
unsigned isn_bits;
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_intr *subpriv = s->private;
struct comedi_cmd *cmd = &s->async->cmd;
int retval = 0;
if (!subpriv->continuous && subpriv->stopcount == 0) {
s->async->events |= COMEDI_CB_EOA;
subpriv->active = false;
retval = 1;
} else {
isn_bits = 0;
if (cmd->chanlist) {
for (n = 0; n < cmd->chanlist_len; n++)
isn_bits |= (1U << CR_CHAN(cmd->chanlist[n]));
}
isn_bits &= subpriv->valid_isns;
subpriv->enabled_isns = isn_bits;
if (layout->has_int_sce)
dio200_write8(dev, subpriv->ofs, isn_bits);
}
return retval;
}
static int
dio200_inttrig_start_intr(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned int trignum)
{
struct dio200_subdev_intr *subpriv;
unsigned long flags;
int event = 0;
if (trignum != 0)
return -EINVAL;
subpriv = s->private;
spin_lock_irqsave(&subpriv->spinlock, flags);
s->async->inttrig = NULL;
if (subpriv->active)
event = dio200_start_intr(dev, s);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
if (event)
comedi_event(dev, s);
return 1;
}
static void dio200_read_scan_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int triggered)
{
struct dio200_subdev_intr *subpriv = s->private;
unsigned short val;
unsigned int n, ch, len;
val = 0;
len = s->async->cmd.chanlist_len;
for (n = 0; n < len; n++) {
ch = CR_CHAN(s->async->cmd.chanlist[n]);
if (triggered & (1U << ch))
val |= (1U << n);
}
if (comedi_buf_put(s->async, val)) {
s->async->events |= (COMEDI_CB_BLOCK | COMEDI_CB_EOS);
} else {
dio200_stop_intr(dev, s);
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW;
comedi_error(dev, "buffer overflow");
}
if (!subpriv->continuous) {
if (subpriv->stopcount > 0) {
subpriv->stopcount--;
if (subpriv->stopcount == 0) {
s->async->events |= COMEDI_CB_EOA;
dio200_stop_intr(dev, s);
}
}
}
}
static int dio200_handle_read_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_intr *subpriv = s->private;
unsigned triggered;
unsigned intstat;
unsigned cur_enabled;
unsigned int oldevents;
unsigned long flags;
triggered = 0;
spin_lock_irqsave(&subpriv->spinlock, flags);
oldevents = s->async->events;
if (layout->has_int_sce) {
cur_enabled = subpriv->enabled_isns;
while ((intstat = (dio200_read8(dev, subpriv->ofs) &
subpriv->valid_isns & ~triggered)) != 0) {
triggered |= intstat;
cur_enabled &= ~triggered;
dio200_write8(dev, subpriv->ofs, cur_enabled);
}
} else {
triggered = subpriv->enabled_isns;
}
if (triggered) {
cur_enabled = subpriv->enabled_isns;
if (layout->has_int_sce)
dio200_write8(dev, subpriv->ofs, cur_enabled);
if (subpriv->active) {
if (triggered & subpriv->enabled_isns)
dio200_read_scan_intr(dev, s, triggered);
}
}
spin_unlock_irqrestore(&subpriv->spinlock, flags);
if (oldevents != s->async->events)
comedi_event(dev, s);
return (triggered != 0);
}
static int dio200_subdev_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dio200_subdev_intr *subpriv = s->private;
unsigned long flags;
spin_lock_irqsave(&subpriv->spinlock, flags);
if (subpriv->active)
dio200_stop_intr(dev, s);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
return 0;
}
static int
dio200_subdev_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_COUNT:
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
return 0;
}
static int dio200_subdev_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
struct dio200_subdev_intr *subpriv = s->private;
unsigned long flags;
int event = 0;
spin_lock_irqsave(&subpriv->spinlock, flags);
subpriv->active = true;
switch (cmd->stop_src) {
case TRIG_COUNT:
subpriv->continuous = false;
subpriv->stopcount = cmd->stop_arg;
break;
default:
subpriv->continuous = true;
subpriv->stopcount = 0;
break;
}
switch (cmd->start_src) {
case TRIG_INT:
s->async->inttrig = dio200_inttrig_start_intr;
break;
default:
event = dio200_start_intr(dev, s);
break;
}
spin_unlock_irqrestore(&subpriv->spinlock, flags);
if (event)
comedi_event(dev, s);
return 0;
}
static int
dio200_subdev_intr_init(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned int offset, unsigned valid_isns)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_intr *subpriv;
subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
if (!subpriv)
return -ENOMEM;
subpriv->ofs = offset;
subpriv->valid_isns = valid_isns;
spin_lock_init(&subpriv->spinlock);
if (layout->has_int_sce)
dio200_write8(dev, subpriv->ofs, 0);
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
if (layout->has_int_sce) {
s->n_chan = DIO200_MAX_ISNS;
s->len_chanlist = DIO200_MAX_ISNS;
} else {
s->n_chan = 1;
s->len_chanlist = 1;
}
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = dio200_subdev_intr_insn_bits;
s->do_cmdtest = dio200_subdev_intr_cmdtest;
s->do_cmd = dio200_subdev_intr_cmd;
s->cancel = dio200_subdev_intr_cancel;
return 0;
}
static irqreturn_t dio200_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct dio200_private *devpriv = dev->private;
struct comedi_subdevice *s;
int handled;
if (!dev->attached)
return IRQ_NONE;
if (devpriv->intr_sd >= 0) {
s = &dev->subdevices[devpriv->intr_sd];
handled = dio200_handle_read_intr(dev, s);
} else {
handled = 0;
}
return IRQ_RETVAL(handled);
}
static unsigned int
dio200_subdev_8254_read_chan(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int chan)
{
struct dio200_subdev_8254 *subpriv = s->private;
unsigned int val;
val = chan << 6;
dio200_write8(dev, subpriv->ofs + i8254_control_reg, val);
val = dio200_read8(dev, subpriv->ofs + chan);
val += dio200_read8(dev, subpriv->ofs + chan) << 8;
return val;
}
static void
dio200_subdev_8254_write_chan(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int chan,
unsigned int count)
{
struct dio200_subdev_8254 *subpriv = s->private;
dio200_write8(dev, subpriv->ofs + chan, count & 0xff);
dio200_write8(dev, subpriv->ofs + chan, (count >> 8) & 0xff);
}
static void
dio200_subdev_8254_set_mode(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int chan,
unsigned int mode)
{
struct dio200_subdev_8254 *subpriv = s->private;
unsigned int byte;
byte = chan << 6;
byte |= 0x30;
byte |= (mode & 0xf);
dio200_write8(dev, subpriv->ofs + i8254_control_reg, byte);
}
static unsigned int
dio200_subdev_8254_status(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int chan)
{
struct dio200_subdev_8254 *subpriv = s->private;
dio200_write8(dev, subpriv->ofs + i8254_control_reg,
0xe0 | (2 << chan));
return dio200_read8(dev, subpriv->ofs + chan);
}
static int
dio200_subdev_8254_read(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dio200_subdev_8254 *subpriv = s->private;
int chan = CR_CHAN(insn->chanspec);
unsigned int n;
unsigned long flags;
for (n = 0; n < insn->n; n++) {
spin_lock_irqsave(&subpriv->spinlock, flags);
data[n] = dio200_subdev_8254_read_chan(dev, s, chan);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
}
return insn->n;
}
static int
dio200_subdev_8254_write(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dio200_subdev_8254 *subpriv = s->private;
int chan = CR_CHAN(insn->chanspec);
unsigned int n;
unsigned long flags;
for (n = 0; n < insn->n; n++) {
spin_lock_irqsave(&subpriv->spinlock, flags);
dio200_subdev_8254_write_chan(dev, s, chan, data[n]);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
}
return insn->n;
}
static int
dio200_subdev_8254_set_gate_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int counter_number,
unsigned int gate_src)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_8254 *subpriv = s->private;
unsigned char byte;
if (!layout->has_clk_gat_sce)
return -1;
if (counter_number > 2)
return -1;
if (gate_src > (layout->has_enhancements ? 31 : 7))
return -1;
subpriv->gate_src[counter_number] = gate_src;
byte = gat_sce(subpriv->which, counter_number, gate_src);
dio200_write8(dev, subpriv->gat_sce_ofs, byte);
return 0;
}
static int
dio200_subdev_8254_get_gate_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int counter_number)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_8254 *subpriv = s->private;
if (!layout->has_clk_gat_sce)
return -1;
if (counter_number > 2)
return -1;
return subpriv->gate_src[counter_number];
}
static int
dio200_subdev_8254_set_clock_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int counter_number,
unsigned int clock_src)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_8254 *subpriv = s->private;
unsigned char byte;
if (!layout->has_clk_gat_sce)
return -1;
if (counter_number > 2)
return -1;
if (clock_src > (layout->has_enhancements ? 31 : 7))
return -1;
subpriv->clock_src[counter_number] = clock_src;
byte = clk_sce(subpriv->which, counter_number, clock_src);
dio200_write8(dev, subpriv->clk_sce_ofs, byte);
return 0;
}
static int
dio200_subdev_8254_get_clock_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int counter_number,
unsigned int *period_ns)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_8254 *subpriv = s->private;
unsigned clock_src;
if (!layout->has_clk_gat_sce)
return -1;
if (counter_number > 2)
return -1;
clock_src = subpriv->clock_src[counter_number];
*period_ns = clock_period[clock_src];
return clock_src;
}
static int
dio200_subdev_8254_config(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dio200_subdev_8254 *subpriv = s->private;
int ret = 0;
int chan = CR_CHAN(insn->chanspec);
unsigned long flags;
spin_lock_irqsave(&subpriv->spinlock, flags);
switch (data[0]) {
case INSN_CONFIG_SET_COUNTER_MODE:
if (data[1] > (I8254_MODE5 | I8254_BINARY))
ret = -EINVAL;
else
dio200_subdev_8254_set_mode(dev, s, chan, data[1]);
break;
case INSN_CONFIG_8254_READ_STATUS:
data[1] = dio200_subdev_8254_status(dev, s, chan);
break;
case INSN_CONFIG_SET_GATE_SRC:
ret = dio200_subdev_8254_set_gate_src(dev, s, chan, data[2]);
if (ret < 0)
ret = -EINVAL;
break;
case INSN_CONFIG_GET_GATE_SRC:
ret = dio200_subdev_8254_get_gate_src(dev, s, chan);
if (ret < 0) {
ret = -EINVAL;
break;
}
data[2] = ret;
break;
case INSN_CONFIG_SET_CLOCK_SRC:
ret = dio200_subdev_8254_set_clock_src(dev, s, chan, data[1]);
if (ret < 0)
ret = -EINVAL;
break;
case INSN_CONFIG_GET_CLOCK_SRC:
ret = dio200_subdev_8254_get_clock_src(dev, s, chan, &data[2]);
if (ret < 0) {
ret = -EINVAL;
break;
}
data[1] = ret;
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&subpriv->spinlock, flags);
return ret < 0 ? ret : insn->n;
}
static int
dio200_subdev_8254_init(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned int offset)
{
const struct dio200_layout *layout = dio200_dev_layout(dev);
struct dio200_subdev_8254 *subpriv;
unsigned int chan;
subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
if (!subpriv)
return -ENOMEM;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 3;
s->maxdata = 0xFFFF;
s->insn_read = dio200_subdev_8254_read;
s->insn_write = dio200_subdev_8254_write;
s->insn_config = dio200_subdev_8254_config;
spin_lock_init(&subpriv->spinlock);
subpriv->ofs = offset;
if (layout->has_clk_gat_sce) {
subpriv->clk_sce_ofs = DIO200_XCLK_SCE + (offset >> 3);
subpriv->gat_sce_ofs = DIO200_XGAT_SCE + (offset >> 3);
subpriv->which = (offset >> 2) & 1;
}
for (chan = 0; chan < 3; chan++) {
dio200_subdev_8254_set_mode(dev, s, chan,
I8254_MODE0 | I8254_BINARY);
if (layout->has_clk_gat_sce) {
dio200_subdev_8254_set_gate_src(dev, s, chan, 0);
dio200_subdev_8254_set_clock_src(dev, s, chan, 0);
}
}
return 0;
}
static void dio200_subdev_8255_set_dir(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dio200_subdev_8255 *subpriv = s->private;
int config;
config = CR_CW;
if (!(s->io_bits & 0x0000ff))
config |= CR_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= CR_B_IO;
if (!(s->io_bits & 0x0f0000))
config |= CR_C_LO_IO;
if (!(s->io_bits & 0xf00000))
config |= CR_C_HI_IO;
dio200_write8(dev, subpriv->ofs + 3, config);
}
static int dio200_subdev_8255_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dio200_subdev_8255 *subpriv = s->private;
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0xff)
dio200_write8(dev, subpriv->ofs, s->state & 0xff);
if (mask & 0xff00)
dio200_write8(dev, subpriv->ofs + 1,
(s->state >> 8) & 0xff);
if (mask & 0xff0000)
dio200_write8(dev, subpriv->ofs + 2,
(s->state >> 16) & 0xff);
}
val = dio200_read8(dev, subpriv->ofs);
val |= dio200_read8(dev, subpriv->ofs + 1) << 8;
val |= dio200_read8(dev, subpriv->ofs + 2) << 16;
data[1] = val;
return insn->n;
}
static int dio200_subdev_8255_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 8)
mask = 0x0000ff;
else if (chan < 16)
mask = 0x00ff00;
else if (chan < 20)
mask = 0x0f0000;
else
mask = 0xf00000;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
dio200_subdev_8255_set_dir(dev, s);
return insn->n;
}
static int dio200_subdev_8255_init(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int offset)
{
struct dio200_subdev_8255 *subpriv;
subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
if (!subpriv)
return -ENOMEM;
subpriv->ofs = offset;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = dio200_subdev_8255_bits;
s->insn_config = dio200_subdev_8255_config;
dio200_subdev_8255_set_dir(dev, s);
return 0;
}
static int dio200_subdev_timer_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int n;
for (n = 0; n < insn->n; n++)
data[n] = dio200_read32(dev, DIO200_TS_COUNT);
return n;
}
static void dio200_subdev_timer_reset(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int clock;
clock = dio200_read32(dev, DIO200_TS_CONFIG) & TS_CONFIG_CLK_SRC_MASK;
dio200_write32(dev, DIO200_TS_CONFIG, clock | TS_CONFIG_RESET);
dio200_write32(dev, DIO200_TS_CONFIG, clock);
}
static void dio200_subdev_timer_get_clock_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *src,
unsigned int *period)
{
unsigned int clk;
clk = dio200_read32(dev, DIO200_TS_CONFIG) & TS_CONFIG_CLK_SRC_MASK;
*src = clk;
*period = (clk < ARRAY_SIZE(ts_clock_period)) ?
ts_clock_period[clk] : 0;
}
static int dio200_subdev_timer_set_clock_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int src)
{
if (src > TS_CONFIG_MAX_CLK_SRC)
return -EINVAL;
dio200_write32(dev, DIO200_TS_CONFIG, src);
return 0;
}
static int dio200_subdev_timer_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret = 0;
switch (data[0]) {
case INSN_CONFIG_RESET:
dio200_subdev_timer_reset(dev, s);
break;
case INSN_CONFIG_SET_CLOCK_SRC:
ret = dio200_subdev_timer_set_clock_src(dev, s, data[1]);
if (ret < 0)
ret = -EINVAL;
break;
case INSN_CONFIG_GET_CLOCK_SRC:
dio200_subdev_timer_get_clock_src(dev, s, &data[1], &data[2]);
break;
default:
ret = -EINVAL;
break;
}
return ret < 0 ? ret : insn->n;
}
static int dio200_subdev_timer_init(struct comedi_device *dev,
struct comedi_subdevice *s)
{
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_READABLE | SDF_LSAMPL;
s->n_chan = 1;
s->maxdata = 0xFFFFFFFF;
s->insn_read = dio200_subdev_timer_read;
s->insn_config = dio200_subdev_timer_config;
return 0;
}
void amplc_dio200_set_enhance(struct comedi_device *dev, unsigned char val)
{
dio200_write8(dev, DIO200_ENHANCE, val);
}
int amplc_dio200_common_attach(struct comedi_device *dev, unsigned int irq,
unsigned long req_irq_flags)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
const struct dio200_layout *layout = dio200_board_layout(thisboard);
struct comedi_subdevice *s;
int sdx;
unsigned int n;
int ret;
devpriv->intr_sd = -1;
ret = comedi_alloc_subdevices(dev, layout->n_subdevs);
if (ret)
return ret;
for (n = 0; n < dev->n_subdevices; n++) {
s = &dev->subdevices[n];
switch (layout->sdtype[n]) {
case sd_8254:
ret = dio200_subdev_8254_init(dev, s,
layout->sdinfo[n]);
if (ret < 0)
return ret;
break;
case sd_8255:
ret = dio200_subdev_8255_init(dev, s,
layout->sdinfo[n]);
if (ret < 0)
return ret;
break;
case sd_intr:
if (irq) {
ret = dio200_subdev_intr_init(dev, s,
DIO200_INT_SCE,
layout->sdinfo[n]
);
if (ret < 0)
return ret;
devpriv->intr_sd = n;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
break;
case sd_timer:
ret = dio200_subdev_timer_init(dev, s);
if (ret < 0)
return ret;
break;
default:
s->type = COMEDI_SUBD_UNUSED;
break;
}
}
sdx = devpriv->intr_sd;
if (sdx >= 0 && sdx < dev->n_subdevices)
dev->read_subdev = &dev->subdevices[sdx];
if (irq) {
if (request_irq(irq, dio200_interrupt, req_irq_flags,
dev->board_name, dev) >= 0) {
dev->irq = irq;
} else {
dev_warn(dev->class_dev,
"warning! irq %u unavailable!\n", irq);
}
}
dev_info(dev->class_dev, "attached\n");
return 0;
}
void amplc_dio200_common_detach(struct comedi_device *dev)
{
const struct dio200_board *thisboard = comedi_board(dev);
struct dio200_private *devpriv = dev->private;
if (!thisboard || !devpriv)
return;
if (dev->irq)
free_irq(dev->irq, dev);
}
static int __init amplc_dio200_common_init(void)
{
return 0;
}
static void __exit amplc_dio200_common_exit(void)
{
}
