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
static unsigned char dio200_read8(struct comedi_device *dev,
unsigned int offset)
{
const struct dio200_board *board = dev->board_ptr;
if (board->is_pcie)
offset <<= 3;
if (dev->mmio)
return readb(dev->mmio + offset);
return inb(dev->iobase + offset);
}
static void dio200_write8(struct comedi_device *dev,
unsigned int offset, unsigned char val)
{
const struct dio200_board *board = dev->board_ptr;
if (board->is_pcie)
offset <<= 3;
if (dev->mmio)
writeb(val, dev->mmio + offset);
else
outb(val, dev->iobase + offset);
}
static unsigned int dio200_read32(struct comedi_device *dev,
unsigned int offset)
{
const struct dio200_board *board = dev->board_ptr;
if (board->is_pcie)
offset <<= 3;
if (dev->mmio)
return readl(dev->mmio + offset);
return inl(dev->iobase + offset);
}
static void dio200_write32(struct comedi_device *dev,
unsigned int offset, unsigned int val)
{
const struct dio200_board *board = dev->board_ptr;
if (board->is_pcie)
offset <<= 3;
if (dev->mmio)
writel(val, dev->mmio + offset);
else
outl(val, dev->iobase + offset);
}
static unsigned int dio200_subdev_8254_offset(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_board *board = dev->board_ptr;
struct comedi_8254 *i8254 = s->private;
unsigned int offset;
if (dev->mmio)
offset = i8254->mmio - dev->mmio;
else
offset = i8254->iobase - dev->iobase;
if (board->is_pcie)
offset >>= 3;
return offset;
}
static int dio200_subdev_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct dio200_board *board = dev->board_ptr;
struct dio200_subdev_intr *subpriv = s->private;
if (board->has_int_sce) {
data[1] = dio200_read8(dev, subpriv->ofs) & subpriv->valid_isns;
} else {
data[0] = 0;
}
return insn->n;
}
static void dio200_stop_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_board *board = dev->board_ptr;
struct dio200_subdev_intr *subpriv = s->private;
subpriv->active = false;
subpriv->enabled_isns = 0;
if (board->has_int_sce)
dio200_write8(dev, subpriv->ofs, 0);
}
static void dio200_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_board *board = dev->board_ptr;
struct dio200_subdev_intr *subpriv = s->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int n;
unsigned isn_bits;
isn_bits = 0;
if (cmd->chanlist) {
for (n = 0; n < cmd->chanlist_len; n++)
isn_bits |= (1U << CR_CHAN(cmd->chanlist[n]));
}
isn_bits &= subpriv->valid_isns;
subpriv->enabled_isns = isn_bits;
if (board->has_int_sce)
dio200_write8(dev, subpriv->ofs, isn_bits);
}
static int dio200_inttrig_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct dio200_subdev_intr *subpriv = s->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
if (trig_num != cmd->start_arg)
return -EINVAL;
spin_lock_irqsave(&subpriv->spinlock, flags);
s->async->inttrig = NULL;
if (subpriv->active)
dio200_start_intr(dev, s);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
return 1;
}
static void dio200_read_scan_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int triggered)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned short val;
unsigned int n, ch;
val = 0;
for (n = 0; n < cmd->chanlist_len; n++) {
ch = CR_CHAN(cmd->chanlist[n]);
if (triggered & (1U << ch))
val |= (1U << n);
}
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg)
s->async->events |= COMEDI_CB_EOA;
}
static int dio200_handle_read_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct dio200_board *board = dev->board_ptr;
struct dio200_subdev_intr *subpriv = s->private;
unsigned triggered;
unsigned intstat;
unsigned cur_enabled;
unsigned long flags;
triggered = 0;
spin_lock_irqsave(&subpriv->spinlock, flags);
if (board->has_int_sce) {
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
if (board->has_int_sce)
dio200_write8(dev, subpriv->ofs, cur_enabled);
if (subpriv->active) {
if (triggered & subpriv->enabled_isns)
dio200_read_scan_intr(dev, s, triggered);
}
}
spin_unlock_irqrestore(&subpriv->spinlock, flags);
comedi_handle_events(dev, s);
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
static int dio200_subdev_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
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
spin_lock_irqsave(&subpriv->spinlock, flags);
subpriv->active = true;
if (cmd->start_src == TRIG_INT)
s->async->inttrig = dio200_inttrig_start_intr;
else
dio200_start_intr(dev, s);
spin_unlock_irqrestore(&subpriv->spinlock, flags);
return 0;
}
static int dio200_subdev_intr_init(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int offset,
unsigned valid_isns)
{
const struct dio200_board *board = dev->board_ptr;
struct dio200_subdev_intr *subpriv;
subpriv = comedi_alloc_spriv(s, sizeof(*subpriv));
if (!subpriv)
return -ENOMEM;
subpriv->ofs = offset;
subpriv->valid_isns = valid_isns;
spin_lock_init(&subpriv->spinlock);
if (board->has_int_sce)
dio200_write8(dev, subpriv->ofs, 0);
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ | SDF_PACKED;
if (board->has_int_sce) {
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
struct comedi_subdevice *s = dev->read_subdev;
int handled;
if (!dev->attached)
return IRQ_NONE;
handled = dio200_handle_read_intr(dev, s);
return IRQ_RETVAL(handled);
}
static void dio200_subdev_8254_set_gate_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chan,
unsigned int src)
{
unsigned int offset = dio200_subdev_8254_offset(dev, s);
dio200_write8(dev, DIO200_GAT_SCE(offset >> 3),
gat_sce((offset >> 2) & 1, chan, src));
}
static void dio200_subdev_8254_set_clock_src(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chan,
unsigned int src)
{
unsigned int offset = dio200_subdev_8254_offset(dev, s);
dio200_write8(dev, DIO200_CLK_SCE(offset >> 3),
clk_sce((offset >> 2) & 1, chan, src));
}
static int dio200_subdev_8254_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct dio200_board *board = dev->board_ptr;
struct comedi_8254 *i8254 = s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int max_src = board->is_pcie ? 31 : 7;
unsigned int src;
if (!board->has_clk_gat_sce)
return -EINVAL;
switch (data[0]) {
case INSN_CONFIG_SET_GATE_SRC:
src = data[2];
if (src > max_src)
return -EINVAL;
dio200_subdev_8254_set_gate_src(dev, s, chan, src);
i8254->gate_src[chan] = src;
break;
case INSN_CONFIG_GET_GATE_SRC:
data[2] = i8254->gate_src[chan];
break;
case INSN_CONFIG_SET_CLOCK_SRC:
src = data[1];
if (src > max_src)
return -EINVAL;
dio200_subdev_8254_set_clock_src(dev, s, chan, src);
i8254->clock_src[chan] = src;
break;
case INSN_CONFIG_GET_CLOCK_SRC:
data[1] = i8254->clock_src[chan];
data[2] = clock_period[i8254->clock_src[chan]];
break;
default:
return -EINVAL;
}
return insn->n;
}
static int dio200_subdev_8254_init(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int offset)
{
const struct dio200_board *board = dev->board_ptr;
struct comedi_8254 *i8254;
unsigned int regshift;
int chan;
if (board->is_pcie) {
offset <<= 3;
regshift = 3;
} else {
regshift = 0;
}
if (dev->mmio)
i8254 = comedi_8254_mm_init(dev->mmio + offset,
0, I8254_IO8, regshift);
else
i8254 = comedi_8254_init(dev->iobase + offset,
0, I8254_IO8, regshift);
if (!i8254)
return -ENOMEM;
comedi_8254_subdevice_init(s, i8254);
i8254->insn_config = dio200_subdev_8254_config;
s->runflags |= COMEDI_SRF_FREE_SPRIV;
if (board->has_clk_gat_sce) {
for (chan = 0; chan < 3; chan++) {
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
config = I8255_CTRL_CW;
if (!(s->io_bits & 0x0000ff))
config |= I8255_CTRL_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= I8255_CTRL_B_IO;
if (!(s->io_bits & 0x0f0000))
config |= I8255_CTRL_C_LO_IO;
if (!(s->io_bits & 0xf00000))
config |= I8255_CTRL_C_HI_IO;
dio200_write8(dev, subpriv->ofs + I8255_CTRL_REG, config);
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
dio200_write8(dev, subpriv->ofs + I8255_DATA_A_REG,
s->state & 0xff);
if (mask & 0xff00)
dio200_write8(dev, subpriv->ofs + I8255_DATA_B_REG,
(s->state >> 8) & 0xff);
if (mask & 0xff0000)
dio200_write8(dev, subpriv->ofs + I8255_DATA_C_REG,
(s->state >> 16) & 0xff);
}
val = dio200_read8(dev, subpriv->ofs + I8255_DATA_A_REG);
val |= dio200_read8(dev, subpriv->ofs + I8255_DATA_B_REG) << 8;
val |= dio200_read8(dev, subpriv->ofs + I8255_DATA_C_REG) << 16;
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
void amplc_dio200_set_enhance(struct comedi_device *dev, unsigned char val)
{
dio200_write8(dev, DIO200_ENHANCE, val);
}
int amplc_dio200_common_attach(struct comedi_device *dev, unsigned int irq,
unsigned long req_irq_flags)
{
const struct dio200_board *board = dev->board_ptr;
struct comedi_subdevice *s;
unsigned int n;
int ret;
ret = comedi_alloc_subdevices(dev, board->n_subdevs);
if (ret)
return ret;
for (n = 0; n < dev->n_subdevices; n++) {
s = &dev->subdevices[n];
switch (board->sdtype[n]) {
case sd_8254:
ret = dio200_subdev_8254_init(dev, s,
board->sdinfo[n]);
if (ret < 0)
return ret;
break;
case sd_8255:
ret = dio200_subdev_8255_init(dev, s,
board->sdinfo[n]);
if (ret < 0)
return ret;
break;
case sd_intr:
if (irq && !dev->read_subdev) {
ret = dio200_subdev_intr_init(dev, s,
DIO200_INT_SCE,
board->sdinfo[n]);
if (ret < 0)
return ret;
dev->read_subdev = s;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
break;
case sd_timer:
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_READABLE | SDF_LSAMPL;
s->n_chan = 1;
s->maxdata = 0xffffffff;
s->insn_read = dio200_subdev_timer_read;
s->insn_config = dio200_subdev_timer_config;
break;
default:
s->type = COMEDI_SUBD_UNUSED;
break;
}
}
if (irq && dev->read_subdev) {
if (request_irq(irq, dio200_interrupt, req_irq_flags,
dev->board_name, dev) >= 0) {
dev->irq = irq;
} else {
dev_warn(dev->class_dev,
"warning! irq %u unavailable!\n", irq);
}
}
return 0;
}
static int __init amplc_dio200_common_init(void)
{
return 0;
}
static void __exit amplc_dio200_common_exit(void)
{
}
