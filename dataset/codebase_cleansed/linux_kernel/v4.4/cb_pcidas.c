static int cb_pcidas_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int status;
status = inw(devpriv->pcibar1 + PCIDAS_AI_REG);
if (status & PCIDAS_AI_EOC)
return 0;
return -EBUSY;
}
static int cb_pcidas_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned int bits;
int ret;
int n;
if (insn->chanspec & CR_ALT_SOURCE) {
outw(PCIDAS_CALIB_EN | PCIDAS_CALIB_SRC(devpriv->calib_src),
devpriv->pcibar1 + PCIDAS_CALIB_REG);
chan = 0;
} else {
outw(0, devpriv->pcibar1 + PCIDAS_CALIB_REG);
}
bits = PCIDAS_AI_CHAN(chan) | PCIDAS_AI_GAIN(range);
if (comedi_range_is_unipolar(s, range))
bits |= PCIDAS_AI_UNIP;
if (aref != AREF_DIFF)
bits |= PCIDAS_AI_SE;
outw(bits, devpriv->pcibar1 + PCIDAS_AI_REG);
outw(0, devpriv->pcibar2 + PCIDAS_AI_FIFO_CLR_REG);
for (n = 0; n < insn->n; n++) {
outw(0, devpriv->pcibar2 + PCIDAS_AI_DATA_REG);
ret = comedi_timeout(dev, s, insn, cb_pcidas_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(devpriv->pcibar2 + PCIDAS_AI_DATA_REG);
}
return n;
}
static int cb_pcidas_ai_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
int id = data[0];
unsigned int source = data[1];
switch (id) {
case INSN_CONFIG_ALT_SOURCE:
if (source >= 8) {
dev_err(dev->class_dev,
"invalid calibration source: %i\n",
source);
return -EINVAL;
}
devpriv->calib_src = source;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int cb_pcidas_ao_nofifo_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val = s->readback[chan];
unsigned long flags;
int i;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ao_ctrl &= ~(PCIDAS_AO_UPDATE_BOTH |
PCIDAS_AO_RANGE_MASK(chan));
devpriv->ao_ctrl |= PCIDAS_AO_DACEN | PCIDAS_AO_RANGE(chan, range);
outw(devpriv->ao_ctrl, devpriv->pcibar1 + PCIDAS_AO_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, devpriv->pcibar4 + PCIDAS_AO_DATA_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int cb_pcidas_ao_fifo_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val = s->readback[chan];
unsigned long flags;
int i;
outw(0, devpriv->pcibar4 + PCIDAS_AO_FIFO_CLR_REG);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ao_ctrl &= ~(PCIDAS_AO_CHAN_MASK | PCIDAS_AO_RANGE_MASK(chan) |
PCIDAS_AO_PACER_MASK);
devpriv->ao_ctrl |= PCIDAS_AO_DACEN | PCIDAS_AO_RANGE(chan, range) |
PCIDAS_AO_CHAN_EN(chan) | PCIDAS_AO_START;
outw(devpriv->ao_ctrl, devpriv->pcibar1 + PCIDAS_AO_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, devpriv->pcibar4 + PCIDAS_AO_FIFO_REG);
}
s->readback[chan] = val;
return insn->n;
}
static int cb_pcidas_eeprom_ready(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->amcc + AMCC_OP_REG_MCSR_NVCMD);
if ((status & MCSR_NV_BUSY) == 0)
return 0;
return -EBUSY;
}
static int cb_pcidas_eeprom_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int ret;
int i;
for (i = 0; i < insn->n; i++) {
ret = comedi_timeout(dev, s, insn, cb_pcidas_eeprom_ready, 0);
if (ret)
return ret;
outb(MCSR_NV_ENABLE | MCSR_NV_LOAD_LOW_ADDR,
devpriv->amcc + AMCC_OP_REG_MCSR_NVCMD);
outb(chan & 0xff, devpriv->amcc + AMCC_OP_REG_MCSR_NVDATA);
outb(MCSR_NV_ENABLE | MCSR_NV_LOAD_HIGH_ADDR,
devpriv->amcc + AMCC_OP_REG_MCSR_NVCMD);
outb((chan >> 8) & 0xff,
devpriv->amcc + AMCC_OP_REG_MCSR_NVDATA);
outb(MCSR_NV_ENABLE | MCSR_NV_READ,
devpriv->amcc + AMCC_OP_REG_MCSR_NVCMD);
ret = comedi_timeout(dev, s, insn, cb_pcidas_eeprom_ready, 0);
if (ret)
return ret;
data[i] = inb(devpriv->amcc + AMCC_OP_REG_MCSR_NVDATA);
}
return insn->n;
}
static void cb_pcidas_calib_write(struct comedi_device *dev,
unsigned int val, unsigned int len,
bool trimpot)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int calib_bits;
unsigned int bit;
calib_bits = PCIDAS_CALIB_EN | PCIDAS_CALIB_SRC(devpriv->calib_src);
if (trimpot) {
calib_bits |= PCIDAS_CALIB_TRIM_SEL;
outw(calib_bits, devpriv->pcibar1 + PCIDAS_CALIB_REG);
}
for (bit = 1 << (len - 1); bit; bit >>= 1) {
if (val & bit)
calib_bits |= PCIDAS_CALIB_DATA;
else
calib_bits &= ~PCIDAS_CALIB_DATA;
udelay(1);
outw(calib_bits, devpriv->pcibar1 + PCIDAS_CALIB_REG);
}
udelay(1);
calib_bits = PCIDAS_CALIB_EN | PCIDAS_CALIB_SRC(devpriv->calib_src);
if (!trimpot) {
outw(calib_bits | PCIDAS_CALIB_8800_SEL,
devpriv->pcibar1 + PCIDAS_CALIB_REG);
udelay(1);
}
outw(calib_bits, devpriv->pcibar1 + PCIDAS_CALIB_REG);
}
static int cb_pcidas_caldac_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
cb_pcidas_calib_write(dev, (chan << 8) | val, 11,
false);
s->readback[chan] = val;
}
}
return insn->n;
}
static void cb_pcidas_dac08_write(struct comedi_device *dev, unsigned int val)
{
struct cb_pcidas_private *devpriv = dev->private;
val |= PCIDAS_CALIB_EN | PCIDAS_CALIB_SRC(devpriv->calib_src);
outw(val, devpriv->pcibar1 + PCIDAS_CALIB_REG);
udelay(1);
outw(val | PCIDAS_CALIB_DAC08_SEL,
devpriv->pcibar1 + PCIDAS_CALIB_REG);
udelay(1);
outw(val, devpriv->pcibar1 + PCIDAS_CALIB_REG);
udelay(1);
}
static int cb_pcidas_dac08_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
cb_pcidas_dac08_write(dev, val);
s->readback[chan] = val;
}
}
return insn->n;
}
static void cb_pcidas_trimpot_write(struct comedi_device *dev,
unsigned int chan, unsigned int val)
{
const struct cb_pcidas_board *board = dev->board_ptr;
if (board->has_ad8402) {
cb_pcidas_calib_write(dev, (chan << 8) | val, 10, true);
} else {
cb_pcidas_calib_write(dev, val, 7, true);
}
}
static int cb_pcidas_trimpot_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
cb_pcidas_trimpot_write(dev, chan, val);
s->readback[chan] = val;
}
}
return insn->n;
}
static int cb_pcidas_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan != (chan0 + i) % s->n_chan) {
dev_dbg(dev->class_dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
return -EINVAL;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"entries in chanlist must all have the same gain\n");
return -EINVAL;
}
}
return 0;
}
static int cb_pcidas_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct cb_pcidas_board *board = dev->board_ptr;
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src == TRIG_FOLLOW && cmd->convert_src == TRIG_NOW)
err |= -EINVAL;
if (cmd->scan_begin_src != TRIG_FOLLOW && cmd->convert_src != TRIG_NOW)
err |= -EINVAL;
if (cmd->start_src == TRIG_EXT &&
(cmd->convert_src == TRIG_EXT || cmd->scan_begin_src == TRIG_EXT))
err |= -EINVAL;
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
if ((cmd->start_arg
& (CR_FLAGS_MASK & ~(CR_EDGE | CR_INVERT))) != 0) {
cmd->start_arg &= ~(CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT));
err |= -EINVAL;
}
if (!board->is_1602 && (cmd->start_arg & CR_INVERT)) {
cmd->start_arg &= (CR_FLAGS_MASK & ~CR_INVERT);
err |= -EINVAL;
}
break;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ai_speed *
cmd->chanlist_len);
}
if (cmd->convert_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= cb_pcidas_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int cb_pcidas_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct cb_pcidas_board *board = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
unsigned int bits;
unsigned long flags;
outw(0, devpriv->pcibar1 + PCIDAS_CALIB_REG);
outw(PCIDAS_TRIG_SEL_NONE, devpriv->pcibar1 + PCIDAS_TRIG_REG);
outw(0, devpriv->pcibar2 + PCIDAS_AI_FIFO_CLR_REG);
bits = PCIDAS_AI_FIRST(CR_CHAN(cmd->chanlist[0])) |
PCIDAS_AI_LAST(CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1])) |
PCIDAS_AI_GAIN(range0);
if (comedi_range_is_unipolar(s, range0))
bits |= PCIDAS_AI_UNIP;
if (CR_AREF(cmd->chanlist[0]) != AREF_DIFF)
bits |= PCIDAS_AI_SE;
if (cmd->convert_src == TRIG_EXT || cmd->scan_begin_src == TRIG_EXT)
bits |= PCIDAS_AI_PACER_EXTP;
else
bits |= PCIDAS_AI_PACER_INT;
outw(bits, devpriv->pcibar1 + PCIDAS_AI_REG);
if (cmd->scan_begin_src == TRIG_TIMER ||
cmd->convert_src == TRIG_TIMER) {
comedi_8254_update_divisors(dev->pacer);
comedi_8254_pacer_enable(dev->pacer, 1, 2, true);
}
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ctrl |= PCIDAS_CTRL_INTE;
devpriv->ctrl &= ~PCIDAS_CTRL_INT_MASK;
if (cmd->flags & CMDF_WAKE_EOS) {
if (cmd->convert_src == TRIG_NOW && cmd->chanlist_len > 1) {
devpriv->ctrl |= PCIDAS_CTRL_INT_EOS;
} else {
devpriv->ctrl |= PCIDAS_CTRL_INT_FNE;
}
} else {
devpriv->ctrl |= PCIDAS_CTRL_INT_FHF;
}
outw(devpriv->ctrl |
PCIDAS_CTRL_EOAI | PCIDAS_CTRL_INT_CLR | PCIDAS_CTRL_LADFUL,
devpriv->pcibar1 + PCIDAS_CTRL_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
bits = 0;
if (cmd->start_src == TRIG_NOW) {
bits |= PCIDAS_TRIG_SEL_SW;
} else {
bits |= PCIDAS_TRIG_SEL_EXT | PCIDAS_TRIG_EN | PCIDAS_TRIG_CLR;
if (board->is_1602) {
if (cmd->start_arg & CR_INVERT)
bits |= PCIDAS_TRIG_POL;
if (cmd->start_arg & CR_EDGE)
bits |= PCIDAS_TRIG_MODE;
}
}
if (cmd->convert_src == TRIG_NOW && cmd->chanlist_len > 1)
bits |= PCIDAS_TRIG_BURSTE;
outw(bits, devpriv->pcibar1 + PCIDAS_TRIG_REG);
return 0;
}
static int cb_pcidas_ao_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
if (cmd->chanlist_len > 1) {
unsigned int chan1 = CR_CHAN(cmd->chanlist[1]);
if (chan0 != 0 || chan1 != 1) {
dev_dbg(dev->class_dev,
"channels must be ordered channel 0, channel 1 in chanlist\n");
return -EINVAL;
}
}
return 0;
}
static int cb_pcidas_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct cb_pcidas_board *board = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_INT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ao_scan_speed);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
unsigned int arg = cmd->scan_begin_arg;
comedi_8254_cascade_ns_to_timer(devpriv->ao_pacer,
&arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= cb_pcidas_ao_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int cb_pcidas_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ctrl &= ~(PCIDAS_CTRL_INTE | PCIDAS_CTRL_EOAIE);
outw(devpriv->ctrl, devpriv->pcibar1 + PCIDAS_CTRL_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
outw(PCIDAS_TRIG_SEL_NONE, devpriv->pcibar1 + PCIDAS_TRIG_REG);
outw(PCIDAS_AI_PACER_SW, devpriv->pcibar1 + PCIDAS_AI_REG);
return 0;
}
static void cb_pcidas_ao_load_fifo(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int nsamples)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int nbytes;
nsamples = comedi_nsamples_left(s, nsamples);
nbytes = comedi_buf_read_samples(s, devpriv->ao_buffer, nsamples);
nsamples = comedi_bytes_to_samples(s, nbytes);
outsw(devpriv->pcibar4 + PCIDAS_AO_FIFO_REG,
devpriv->ao_buffer, nsamples);
}
static int cb_pcidas_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
const struct cb_pcidas_board *board = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long flags;
if (trig_num != cmd->start_arg)
return -EINVAL;
cb_pcidas_ao_load_fifo(dev, s, board->fifo_size);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ctrl |= PCIDAS_CTRL_DAEMIE | PCIDAS_CTRL_DAHFIE;
outw(devpriv->ctrl | PCIDAS_CTRL_DAEMI | PCIDAS_CTRL_DAHFI,
devpriv->pcibar1 + PCIDAS_CTRL_REG);
devpriv->ao_ctrl |= PCIDAS_AO_START | PCIDAS_AO_DACEN | PCIDAS_AO_EMPTY;
outw(devpriv->ao_ctrl, devpriv->pcibar1 + PCIDAS_AO_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
async->inttrig = NULL;
return 0;
}
static int cb_pcidas_ao_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int i;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
devpriv->ao_ctrl |= PCIDAS_AO_CHAN_EN(chan);
devpriv->ao_ctrl |= PCIDAS_AO_RANGE(chan, range);
}
outw(devpriv->ao_ctrl, devpriv->pcibar1 + PCIDAS_AO_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
outw(0, devpriv->pcibar4 + PCIDAS_AO_FIFO_CLR_REG);
if (cmd->scan_begin_src == TRIG_TIMER) {
comedi_8254_update_divisors(devpriv->ao_pacer);
comedi_8254_pacer_enable(devpriv->ao_pacer, 1, 2, true);
}
spin_lock_irqsave(&dev->spinlock, flags);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
devpriv->ao_ctrl |= PCIDAS_AO_PACER_INT;
break;
case TRIG_EXT:
devpriv->ao_ctrl |= PCIDAS_AO_PACER_EXTP;
break;
default:
spin_unlock_irqrestore(&dev->spinlock, flags);
dev_err(dev->class_dev, "error setting dac pacer source\n");
return -1;
}
spin_unlock_irqrestore(&dev->spinlock, flags);
async->inttrig = cb_pcidas_ao_inttrig;
return 0;
}
static int cb_pcidas_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ctrl &= ~(PCIDAS_CTRL_DAHFIE | PCIDAS_CTRL_DAEMIE);
outw(devpriv->ctrl, devpriv->pcibar1 + PCIDAS_CTRL_REG);
devpriv->ao_ctrl &= ~(PCIDAS_AO_DACEN | PCIDAS_AO_PACER_MASK);
outw(devpriv->ao_ctrl, devpriv->pcibar1 + PCIDAS_AO_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static unsigned int cb_pcidas_ao_interrupt(struct comedi_device *dev,
unsigned int status)
{
const struct cb_pcidas_board *board = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int irq_clr = 0;
if (status & PCIDAS_CTRL_DAEMI) {
irq_clr |= PCIDAS_CTRL_DAEMI;
if (inw(devpriv->pcibar4 + PCIDAS_AO_REG) & PCIDAS_AO_EMPTY) {
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
} else {
dev_err(dev->class_dev, "dac fifo underflow\n");
async->events |= COMEDI_CB_ERROR;
}
}
} else if (status & PCIDAS_CTRL_DAHFI) {
irq_clr |= PCIDAS_CTRL_DAHFI;
cb_pcidas_ao_load_fifo(dev, s, board->fifo_size / 2);
}
comedi_handle_events(dev, s);
return irq_clr;
}
static unsigned int cb_pcidas_ai_interrupt(struct comedi_device *dev,
unsigned int status)
{
const struct cb_pcidas_board *board = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int irq_clr = 0;
if (status & PCIDAS_CTRL_ADHFI) {
unsigned int num_samples;
irq_clr |= PCIDAS_CTRL_INT_CLR;
num_samples = comedi_nsamples_left(s, board->fifo_size / 2);
insw(devpriv->pcibar2 + PCIDAS_AI_DATA_REG,
devpriv->ai_buffer, num_samples);
comedi_buf_write_samples(s, devpriv->ai_buffer, num_samples);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
} else if (status & (PCIDAS_CTRL_ADNEI | PCIDAS_CTRL_EOBI)) {
unsigned int i;
irq_clr |= PCIDAS_CTRL_INT_CLR;
for (i = 0; i < 10000; i++) {
unsigned short val;
if ((inw(devpriv->pcibar1 + PCIDAS_CTRL_REG) &
PCIDAS_CTRL_ADNE) == 0)
break;
val = inw(devpriv->pcibar2 + PCIDAS_AI_DATA_REG);
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
break;
}
}
} else if (status & PCIDAS_CTRL_EOAI) {
irq_clr |= PCIDAS_CTRL_EOAI;
dev_err(dev->class_dev,
"bug! encountered end of acquisition interrupt?\n");
}
if (status & PCIDAS_CTRL_LADFUL) {
irq_clr |= PCIDAS_CTRL_LADFUL;
dev_err(dev->class_dev, "fifo overflow\n");
async->events |= COMEDI_CB_ERROR;
}
comedi_handle_events(dev, s);
return irq_clr;
}
static irqreturn_t cb_pcidas_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct cb_pcidas_private *devpriv = dev->private;
unsigned int irq_clr = 0;
unsigned int amcc_status;
unsigned int status;
if (!dev->attached)
return IRQ_NONE;
amcc_status = inl(devpriv->amcc + AMCC_OP_REG_INTCSR);
if ((INTCSR_INTR_ASSERTED & amcc_status) == 0)
return IRQ_NONE;
inl_p(devpriv->amcc + AMCC_OP_REG_IMB4);
outl(devpriv->amcc_intcsr | INTCSR_INBOX_INTR_STATUS,
devpriv->amcc + AMCC_OP_REG_INTCSR);
status = inw(devpriv->pcibar1 + PCIDAS_CTRL_REG);
if (status & PCIDAS_CTRL_AO_INT)
irq_clr |= cb_pcidas_ao_interrupt(dev, status);
if (status & PCIDAS_CTRL_AI_INT)
irq_clr |= cb_pcidas_ai_interrupt(dev, status);
if (irq_clr) {
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->ctrl | irq_clr,
devpriv->pcibar1 + PCIDAS_CTRL_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
return IRQ_HANDLED;
}
static int cb_pcidas_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct cb_pcidas_board *board = NULL;
struct cb_pcidas_private *devpriv;
struct comedi_subdevice *s;
int i;
int ret;
if (context < ARRAY_SIZE(cb_pcidas_boards))
board = &cb_pcidas_boards[context];
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
devpriv->amcc = pci_resource_start(pcidev, 0);
devpriv->pcibar1 = pci_resource_start(pcidev, 1);
devpriv->pcibar2 = pci_resource_start(pcidev, 2);
dev->iobase = pci_resource_start(pcidev, 3);
if (board->has_ao)
devpriv->pcibar4 = pci_resource_start(pcidev, 4);
outl(INTCSR_INBOX_INTR_STATUS,
devpriv->amcc + AMCC_OP_REG_INTCSR);
ret = request_irq(pcidev->irq, cb_pcidas_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret) {
dev_dbg(dev->class_dev, "unable to allocate irq %d\n",
pcidev->irq);
return ret;
}
dev->irq = pcidev->irq;
dev->pacer = comedi_8254_init(dev->iobase + PCIDAS_AI_8254_BASE,
I8254_OSC_BASE_10MHZ, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
devpriv->ao_pacer = comedi_8254_init(dev->iobase + PCIDAS_AO_8254_BASE,
I8254_OSC_BASE_10MHZ,
I8254_IO8, 0);
if (!devpriv->ao_pacer)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 7);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = board->is_16bit ? 0xffff : 0x0fff;
s->range_table = board->use_alt_range ? &cb_pcidas_alt_ranges
: &cb_pcidas_ranges;
s->insn_read = cb_pcidas_ai_insn_read;
s->insn_config = cb_pcidas_ai_insn_config;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmd = cb_pcidas_ai_cmd;
s->do_cmdtest = cb_pcidas_ai_cmdtest;
s->cancel = cb_pcidas_ai_cancel;
}
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 2;
s->maxdata = board->is_16bit ? 0xffff : 0x0fff;
s->range_table = &cb_pcidas_ao_ranges;
s->insn_write = (board->has_ao_fifo)
? cb_pcidas_ao_fifo_insn_write
: cb_pcidas_ao_nofifo_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
if (dev->irq && board->has_ao_fifo) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->do_cmdtest = cb_pcidas_ao_cmdtest;
s->do_cmd = cb_pcidas_ao_cmd;
s->cancel = cb_pcidas_ao_cancel;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL, PCIDAS_8255_BASE);
if (ret)
return ret;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 256;
s->maxdata = 0xff;
s->insn_read = cb_pcidas_eeprom_insn_read;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 8;
s->maxdata = 0xff;
s->insn_write = cb_pcidas_caldac_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
unsigned int val = s->maxdata / 2;
cb_pcidas_calib_write(dev, (i << 8) | val, 11, false);
s->readback[i] = val;
}
s = &dev->subdevices[5];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_WRITABLE | SDF_INTERNAL;
if (board->has_ad8402) {
s->n_chan = 2;
s->maxdata = 0xff;
} else {
s->n_chan = 1;
s->maxdata = 0x7f;
}
s->insn_write = cb_pcidas_trimpot_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
cb_pcidas_trimpot_write(dev, i, s->maxdata / 2);
s->readback[i] = s->maxdata / 2;
}
s = &dev->subdevices[6];
if (board->has_dac08) {
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 1;
s->maxdata = 0xff;
s->insn_write = cb_pcidas_dac08_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
cb_pcidas_dac08_write(dev, s->maxdata / 2);
s->readback[i] = s->maxdata / 2;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
inl(devpriv->amcc + AMCC_OP_REG_IMB4);
devpriv->amcc_intcsr = INTCSR_INBOX_BYTE(3) | INTCSR_INBOX_SELECT(3) |
INTCSR_INBOX_FULL_INT;
outl(devpriv->amcc_intcsr | INTCSR_INBOX_INTR_STATUS,
devpriv->amcc + AMCC_OP_REG_INTCSR);
return 0;
}
static void cb_pcidas_detach(struct comedi_device *dev)
{
struct cb_pcidas_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->amcc)
outl(INTCSR_INBOX_INTR_STATUS,
devpriv->amcc + AMCC_OP_REG_INTCSR);
kfree(devpriv->ao_pacer);
}
comedi_pci_detach(dev);
}
static int cb_pcidas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &cb_pcidas_driver,
id->driver_data);
}
