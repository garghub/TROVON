static int me4000_xilinx_download(struct comedi_device *dev,
const u8 *data, size_t size,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct me4000_info *info = dev->private;
unsigned long xilinx_iobase = pci_resource_start(pcidev, 5);
unsigned int file_length;
unsigned int val;
unsigned int i;
if (!xilinx_iobase)
return -ENODEV;
outl(PLX9052_INTCSR_LI2POL, info->plx_regbase + PLX9052_INTCSR);
val = inl(info->plx_regbase + PLX9052_CNTRL);
val |= PLX9052_CNTRL_UIO2_DATA;
outl(val, info->plx_regbase + PLX9052_CNTRL);
inb(xilinx_iobase + 0xC8);
udelay(20);
val = inl(info->plx_regbase + PLX9052_INTCSR);
if (!(val & PLX9052_INTCSR_LI2STAT)) {
dev_err(dev->class_dev, "Can't init Xilinx\n");
return -EIO;
}
val = inl(info->plx_regbase + PLX9052_CNTRL);
val &= ~PLX9052_CNTRL_UIO2_DATA;
outl(val, info->plx_regbase + PLX9052_CNTRL);
file_length = (((unsigned int)data[0] & 0xff) << 24) +
(((unsigned int)data[1] & 0xff) << 16) +
(((unsigned int)data[2] & 0xff) << 8) +
((unsigned int)data[3] & 0xff);
udelay(10);
for (i = 0; i < file_length; i++) {
outb(data[16 + i], xilinx_iobase);
udelay(10);
val = inl(info->plx_regbase + PLX9052_CNTRL);
if (val & PLX9052_CNTRL_UIO1_DATA) {
dev_err(dev->class_dev,
"Xilinx is still busy (i = %d)\n", i);
return -EIO;
}
}
val = inl(info->plx_regbase + PLX9052_CNTRL);
if (!(val & PLX9052_CNTRL_UIO0_DATA)) {
dev_err(dev->class_dev, "DONE flag is not set\n");
dev_err(dev->class_dev, "Download not successful\n");
return -EIO;
}
val = inl(info->plx_regbase + PLX9052_CNTRL);
val |= PLX9052_CNTRL_UIO2_DATA;
outl(val, info->plx_regbase + PLX9052_CNTRL);
return 0;
}
static void me4000_reset(struct comedi_device *dev)
{
struct me4000_info *info = dev->private;
unsigned int val;
int chan;
val = inl(info->plx_regbase + PLX9052_CNTRL);
val |= PLX9052_CNTRL_PCI_RESET;
outl(val, info->plx_regbase + PLX9052_CNTRL);
val &= ~PLX9052_CNTRL_PCI_RESET;
outl(val, info->plx_regbase + PLX9052_CNTRL);
for (chan = 0; chan < 4; chan++)
outl(0x8000, dev->iobase + ME4000_AO_SINGLE_REG(chan));
outl(ME4000_AI_CTRL_BIT_IMMEDIATE_STOP | ME4000_AI_CTRL_BIT_STOP,
dev->iobase + ME4000_AI_CTRL_REG);
val = ME4000_AO_CTRL_BIT_IMMEDIATE_STOP | ME4000_AO_CTRL_BIT_STOP;
for (chan = 0; chan < 4; chan++)
outl(val, dev->iobase + ME4000_AO_CTRL_REG(chan));
outl(PLX9052_INTCSR_LI1ENAB |
PLX9052_INTCSR_LI1POL |
PLX9052_INTCSR_PCIENAB, info->plx_regbase + PLX9052_INTCSR);
outl(ME4000_AO_DEMUX_ADJUST_VALUE,
dev->iobase + ME4000_AO_DEMUX_ADJUST_REG);
if (!(inl(dev->iobase + ME4000_DIO_DIR_REG) & 0x1))
outl(0x1, dev->iobase + ME4000_DIO_CTRL_REG);
}
static int me4000_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *subdevice,
struct comedi_insn *insn, unsigned int *data)
{
const struct me4000_board *thisboard = dev->board_ptr;
int chan = CR_CHAN(insn->chanspec);
int rang = CR_RANGE(insn->chanspec);
int aref = CR_AREF(insn->chanspec);
unsigned int entry = 0;
unsigned int tmp;
unsigned int lval;
if (insn->n == 0) {
return 0;
} else if (insn->n > 1) {
dev_err(dev->class_dev, "Invalid instruction length %d\n",
insn->n);
return -EINVAL;
}
switch (rang) {
case 0:
entry |= ME4000_AI_LIST_RANGE_UNIPOLAR_2_5;
break;
case 1:
entry |= ME4000_AI_LIST_RANGE_UNIPOLAR_10;
break;
case 2:
entry |= ME4000_AI_LIST_RANGE_BIPOLAR_2_5;
break;
case 3:
entry |= ME4000_AI_LIST_RANGE_BIPOLAR_10;
break;
default:
dev_err(dev->class_dev, "Invalid range specified\n");
return -EINVAL;
}
switch (aref) {
case AREF_GROUND:
case AREF_COMMON:
if (chan >= thisboard->ai_nchan) {
dev_err(dev->class_dev,
"Analog input is not available\n");
return -EINVAL;
}
entry |= ME4000_AI_LIST_INPUT_SINGLE_ENDED | chan;
break;
case AREF_DIFF:
if (rang == 0 || rang == 1) {
dev_err(dev->class_dev,
"Range must be bipolar when aref = diff\n");
return -EINVAL;
}
if (chan >= thisboard->ai_diff_nchan) {
dev_err(dev->class_dev,
"Analog input is not available\n");
return -EINVAL;
}
entry |= ME4000_AI_LIST_INPUT_DIFFERENTIAL | chan;
break;
default:
dev_err(dev->class_dev, "Invalid aref specified\n");
return -EINVAL;
}
entry |= ME4000_AI_LIST_LAST_ENTRY;
tmp = inl(dev->iobase + ME4000_AI_CTRL_REG);
tmp &= ~(ME4000_AI_CTRL_BIT_CHANNEL_FIFO |
ME4000_AI_CTRL_BIT_DATA_FIFO |
ME4000_AI_CTRL_BIT_STOP | ME4000_AI_CTRL_BIT_IMMEDIATE_STOP);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
tmp &= ~(ME4000_AI_CTRL_BIT_MODE_0 | ME4000_AI_CTRL_BIT_MODE_1 |
ME4000_AI_CTRL_BIT_MODE_2);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
tmp |= ME4000_AI_CTRL_BIT_CHANNEL_FIFO | ME4000_AI_CTRL_BIT_DATA_FIFO;
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
outl(entry, dev->iobase + ME4000_AI_CHANNEL_LIST_REG);
outl(ME4000_AI_MIN_TICKS, dev->iobase + ME4000_AI_CHAN_TIMER_REG);
outl(ME4000_AI_MIN_TICKS, dev->iobase + ME4000_AI_CHAN_PRE_TIMER_REG);
inl(dev->iobase + ME4000_AI_START_REG);
udelay(10);
if (!(inl(dev->iobase + ME4000_AI_STATUS_REG) &
ME4000_AI_STATUS_BIT_EF_DATA)) {
dev_err(dev->class_dev, "Value not available after wait\n");
return -EIO;
}
lval = inl(dev->iobase + ME4000_AI_DATA_REG) & 0xFFFF;
data[0] = lval ^ 0x8000;
return 1;
}
static int me4000_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int tmp;
tmp = inl(dev->iobase + ME4000_AI_CTRL_REG);
tmp &= ~(ME4000_AI_CTRL_BIT_STOP | ME4000_AI_CTRL_BIT_IMMEDIATE_STOP);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
outl(0x0, dev->iobase + ME4000_AI_CTRL_REG);
return 0;
}
static int me4000_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct me4000_board *board = dev->board_ptr;
unsigned int max_diff_chan = board->ai_diff_nchan;
unsigned int aref0 = CR_AREF(cmd->chanlist[0]);
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
unsigned int aref = CR_AREF(cmd->chanlist[i]);
if (aref != aref0) {
dev_dbg(dev->class_dev,
"Mode is not equal for all entries\n");
return -EINVAL;
}
if (aref == AREF_DIFF) {
if (chan >= max_diff_chan) {
dev_dbg(dev->class_dev,
"Channel number to high\n");
return -EINVAL;
}
if (!comedi_range_is_bipolar(s, range)) {
dev_dbg(dev->class_dev,
"Bipolar is not selected in differential mode\n");
return -EINVAL;
}
}
}
return 0;
}
static int ai_round_cmd_args(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd,
unsigned int *init_ticks,
unsigned int *scan_ticks, unsigned int *chan_ticks)
{
int rest;
*init_ticks = 0;
*scan_ticks = 0;
*chan_ticks = 0;
if (cmd->start_arg) {
*init_ticks = (cmd->start_arg * 33) / 1000;
rest = (cmd->start_arg * 33) % 1000;
if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_NEAREST) {
if (rest > 33)
(*init_ticks)++;
} else if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_UP) {
if (rest)
(*init_ticks)++;
}
}
if (cmd->scan_begin_arg) {
*scan_ticks = (cmd->scan_begin_arg * 33) / 1000;
rest = (cmd->scan_begin_arg * 33) % 1000;
if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_NEAREST) {
if (rest > 33)
(*scan_ticks)++;
} else if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_UP) {
if (rest)
(*scan_ticks)++;
}
}
if (cmd->convert_arg) {
*chan_ticks = (cmd->convert_arg * 33) / 1000;
rest = (cmd->convert_arg * 33) % 1000;
if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_NEAREST) {
if (rest > 33)
(*chan_ticks)++;
} else if ((cmd->flags & CMDF_ROUND_MASK) == CMDF_ROUND_UP) {
if (rest)
(*chan_ticks)++;
}
}
return 0;
}
static void ai_write_timer(struct comedi_device *dev,
unsigned int init_ticks,
unsigned int scan_ticks, unsigned int chan_ticks)
{
outl(init_ticks - 1, dev->iobase + ME4000_AI_SCAN_PRE_TIMER_LOW_REG);
outl(0x0, dev->iobase + ME4000_AI_SCAN_PRE_TIMER_HIGH_REG);
if (scan_ticks) {
outl(scan_ticks - 1, dev->iobase + ME4000_AI_SCAN_TIMER_LOW_REG);
outl(0x0, dev->iobase + ME4000_AI_SCAN_TIMER_HIGH_REG);
}
outl(chan_ticks - 1, dev->iobase + ME4000_AI_CHAN_PRE_TIMER_REG);
outl(chan_ticks - 1, dev->iobase + ME4000_AI_CHAN_TIMER_REG);
}
static int ai_write_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
unsigned int entry;
unsigned int chan;
unsigned int rang;
unsigned int aref;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
chan = CR_CHAN(cmd->chanlist[i]);
rang = CR_RANGE(cmd->chanlist[i]);
aref = CR_AREF(cmd->chanlist[i]);
entry = chan;
if (rang == 0)
entry |= ME4000_AI_LIST_RANGE_UNIPOLAR_2_5;
else if (rang == 1)
entry |= ME4000_AI_LIST_RANGE_UNIPOLAR_10;
else if (rang == 2)
entry |= ME4000_AI_LIST_RANGE_BIPOLAR_2_5;
else
entry |= ME4000_AI_LIST_RANGE_BIPOLAR_10;
if (aref == AREF_DIFF)
entry |= ME4000_AI_LIST_INPUT_DIFFERENTIAL;
else
entry |= ME4000_AI_LIST_INPUT_SINGLE_ENDED;
outl(entry, dev->iobase + ME4000_AI_CHANNEL_LIST_REG);
}
return 0;
}
static int ai_prepare(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd,
unsigned int init_ticks,
unsigned int scan_ticks, unsigned int chan_ticks)
{
unsigned int tmp = 0;
ai_write_timer(dev, init_ticks, scan_ticks, chan_ticks);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
if ((cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_TIMER) ||
(cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER)) {
tmp = ME4000_AI_CTRL_BIT_MODE_1 |
ME4000_AI_CTRL_BIT_CHANNEL_FIFO |
ME4000_AI_CTRL_BIT_DATA_FIFO;
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_TIMER) {
tmp = ME4000_AI_CTRL_BIT_MODE_2 |
ME4000_AI_CTRL_BIT_CHANNEL_FIFO |
ME4000_AI_CTRL_BIT_DATA_FIFO;
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_EXT) {
tmp = ME4000_AI_CTRL_BIT_MODE_0 |
ME4000_AI_CTRL_BIT_MODE_1 |
ME4000_AI_CTRL_BIT_CHANNEL_FIFO |
ME4000_AI_CTRL_BIT_DATA_FIFO;
} else {
tmp = ME4000_AI_CTRL_BIT_MODE_0 |
ME4000_AI_CTRL_BIT_CHANNEL_FIFO |
ME4000_AI_CTRL_BIT_DATA_FIFO;
}
if (cmd->stop_src == TRIG_COUNT) {
outl(cmd->chanlist_len * cmd->stop_arg,
dev->iobase + ME4000_AI_SAMPLE_COUNTER_REG);
tmp |= ME4000_AI_CTRL_BIT_HF_IRQ | ME4000_AI_CTRL_BIT_SC_IRQ;
} else if (cmd->stop_src == TRIG_NONE &&
cmd->scan_end_src == TRIG_COUNT) {
outl(cmd->scan_end_arg,
dev->iobase + ME4000_AI_SAMPLE_COUNTER_REG);
tmp |= ME4000_AI_CTRL_BIT_HF_IRQ | ME4000_AI_CTRL_BIT_SC_IRQ;
} else {
tmp |= ME4000_AI_CTRL_BIT_HF_IRQ;
}
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
ai_write_chanlist(dev, s, cmd);
return 0;
}
static int me4000_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int err;
unsigned int init_ticks = 0;
unsigned int scan_ticks = 0;
unsigned int chan_ticks = 0;
struct comedi_cmd *cmd = &s->async->cmd;
err = me4000_ai_cancel(dev, s);
if (err)
return err;
err = ai_round_cmd_args(dev,
s, cmd, &init_ticks, &scan_ticks, &chan_ticks);
if (err)
return err;
err = ai_prepare(dev, s, cmd, init_ticks, scan_ticks, chan_ticks);
if (err)
return err;
inl(dev->iobase + ME4000_AI_START_REG);
return 0;
}
static int me4000_ai_do_cmd_test(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int init_ticks;
unsigned int chan_ticks;
unsigned int scan_ticks;
int err = 0;
ai_round_cmd_args(dev, s, cmd, &init_ticks, &scan_ticks, &chan_ticks);
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src,
TRIG_NONE | TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE | TRIG_COUNT);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->scan_end_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (cmd->start_src == TRIG_NOW &&
cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_TIMER) {
} else if (cmd->start_src == TRIG_NOW &&
cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER) {
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_TIMER) {
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER) {
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_TIMER) {
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_EXT) {
} else {
err |= -EINVAL;
}
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->chanlist_len < 1) {
cmd->chanlist_len = 1;
err |= -EINVAL;
}
if (init_ticks < 66) {
cmd->start_arg = 2000;
err |= -EINVAL;
}
if (scan_ticks && scan_ticks < 67) {
cmd->scan_begin_arg = 2031;
err |= -EINVAL;
}
if (chan_ticks < 66) {
cmd->convert_arg = 2000;
err |= -EINVAL;
}
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->start_src == TRIG_NOW &&
cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_TIMER) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
if (chan_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid convert arg\n");
cmd->convert_arg = 2000;
err++;
}
if (scan_ticks <= cmd->chanlist_len * chan_ticks) {
dev_err(dev->class_dev, "Invalid scan end arg\n");
cmd->scan_end_arg = 2000 * cmd->chanlist_len + 31;
err++;
}
} else if (cmd->start_src == TRIG_NOW &&
cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
if (chan_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid convert arg\n");
cmd->convert_arg = 2000;
err++;
}
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_TIMER) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
if (chan_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid convert arg\n");
cmd->convert_arg = 2000;
err++;
}
if (scan_ticks <= cmd->chanlist_len * chan_ticks) {
dev_err(dev->class_dev, "Invalid scan end arg\n");
cmd->scan_end_arg = 2000 * cmd->chanlist_len + 31;
err++;
}
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
if (chan_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid convert arg\n");
cmd->convert_arg = 2000;
err++;
}
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_TIMER) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
if (chan_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid convert arg\n");
cmd->convert_arg = 2000;
err++;
}
} else if (cmd->start_src == TRIG_EXT &&
cmd->scan_begin_src == TRIG_EXT &&
cmd->convert_src == TRIG_EXT) {
if (init_ticks < ME4000_AI_MIN_TICKS) {
dev_err(dev->class_dev, "Invalid start arg\n");
cmd->start_arg = 2000;
err++;
}
}
if (cmd->scan_end_src == TRIG_COUNT) {
if (cmd->scan_end_arg == 0) {
dev_err(dev->class_dev, "Invalid scan end arg\n");
cmd->scan_end_arg = 1;
err++;
}
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= me4000_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static irqreturn_t me4000_ai_isr(int irq, void *dev_id)
{
unsigned int tmp;
struct comedi_device *dev = dev_id;
struct comedi_subdevice *s = dev->read_subdev;
int i;
int c = 0;
unsigned int lval;
if (!dev->attached)
return IRQ_NONE;
if (inl(dev->iobase + ME4000_IRQ_STATUS_REG) &
ME4000_IRQ_STATUS_BIT_AI_HF) {
tmp = inl(dev->iobase + ME4000_AI_CTRL_REG);
if (!(tmp & ME4000_AI_STATUS_BIT_FF_DATA) &&
!(tmp & ME4000_AI_STATUS_BIT_HF_DATA) &&
(tmp & ME4000_AI_STATUS_BIT_EF_DATA)) {
c = ME4000_AI_FIFO_COUNT;
tmp |= ME4000_AI_CTRL_BIT_IMMEDIATE_STOP;
tmp &= ~(ME4000_AI_CTRL_BIT_HF_IRQ |
ME4000_AI_CTRL_BIT_SC_IRQ);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
s->async->events |= COMEDI_CB_ERROR;
dev_err(dev->class_dev, "FIFO overflow\n");
} else if ((tmp & ME4000_AI_STATUS_BIT_FF_DATA)
&& !(tmp & ME4000_AI_STATUS_BIT_HF_DATA)
&& (tmp & ME4000_AI_STATUS_BIT_EF_DATA)) {
c = ME4000_AI_FIFO_COUNT / 2;
} else {
dev_err(dev->class_dev,
"Can't determine state of fifo\n");
c = 0;
tmp |= ME4000_AI_CTRL_BIT_IMMEDIATE_STOP;
tmp &= ~(ME4000_AI_CTRL_BIT_HF_IRQ |
ME4000_AI_CTRL_BIT_SC_IRQ);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
s->async->events |= COMEDI_CB_ERROR;
dev_err(dev->class_dev, "Undefined FIFO state\n");
}
for (i = 0; i < c; i++) {
lval = inl(dev->iobase + ME4000_AI_DATA_REG) & 0xFFFF;
lval ^= 0x8000;
if (!comedi_buf_write_samples(s, &lval, 1)) {
tmp |= ME4000_AI_CTRL_BIT_IMMEDIATE_STOP;
tmp &= ~(ME4000_AI_CTRL_BIT_HF_IRQ |
ME4000_AI_CTRL_BIT_SC_IRQ);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
break;
}
}
tmp |= ME4000_AI_CTRL_BIT_HF_IRQ_RESET;
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
tmp &= ~ME4000_AI_CTRL_BIT_HF_IRQ_RESET;
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
}
if (inl(dev->iobase + ME4000_IRQ_STATUS_REG) &
ME4000_IRQ_STATUS_BIT_SC) {
s->async->events |= COMEDI_CB_EOA;
tmp = inl(dev->iobase + ME4000_AI_CTRL_REG);
tmp |= ME4000_AI_CTRL_BIT_IMMEDIATE_STOP;
tmp &= ~(ME4000_AI_CTRL_BIT_HF_IRQ | ME4000_AI_CTRL_BIT_SC_IRQ);
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
while (inl(dev->iobase + ME4000_AI_CTRL_REG) &
ME4000_AI_STATUS_BIT_EF_DATA) {
lval = inl(dev->iobase + ME4000_AI_DATA_REG) & 0xFFFF;
lval ^= 0x8000;
if (!comedi_buf_write_samples(s, &lval, 1))
break;
}
tmp |= ME4000_AI_CTRL_BIT_SC_IRQ_RESET;
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
tmp &= ~ME4000_AI_CTRL_BIT_SC_IRQ_RESET;
outl(tmp, dev->iobase + ME4000_AI_CTRL_REG);
}
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int me4000_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
unsigned int tmp;
tmp = inl(dev->iobase + ME4000_AO_CTRL_REG(chan));
tmp |= ME4000_AO_CTRL_BIT_IMMEDIATE_STOP;
outl(tmp, dev->iobase + ME4000_AO_CTRL_REG(chan));
outl(0x0, dev->iobase + ME4000_AO_CTRL_REG(chan));
outl(data[0], dev->iobase + ME4000_AO_SINGLE_REG(chan));
s->readback[chan] = data[0];
return 1;
}
static int me4000_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outl((s->state >> 0) & 0xFF,
dev->iobase + ME4000_DIO_PORT_0_REG);
outl((s->state >> 8) & 0xFF,
dev->iobase + ME4000_DIO_PORT_1_REG);
outl((s->state >> 16) & 0xFF,
dev->iobase + ME4000_DIO_PORT_2_REG);
outl((s->state >> 24) & 0xFF,
dev->iobase + ME4000_DIO_PORT_3_REG);
}
data[1] = ((inl(dev->iobase + ME4000_DIO_PORT_0_REG) & 0xFF) << 0) |
((inl(dev->iobase + ME4000_DIO_PORT_1_REG) & 0xFF) << 8) |
((inl(dev->iobase + ME4000_DIO_PORT_2_REG) & 0xFF) << 16) |
((inl(dev->iobase + ME4000_DIO_PORT_3_REG) & 0xFF) << 24);
return insn->n;
}
static int me4000_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
unsigned int tmp;
int ret;
if (chan < 8)
mask = 0x000000ff;
else if (chan < 16)
mask = 0x0000ff00;
else if (chan < 24)
mask = 0x00ff0000;
else
mask = 0xff000000;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
tmp = inl(dev->iobase + ME4000_DIO_CTRL_REG);
tmp &= ~(ME4000_DIO_CTRL_BIT_MODE_0 | ME4000_DIO_CTRL_BIT_MODE_1 |
ME4000_DIO_CTRL_BIT_MODE_2 | ME4000_DIO_CTRL_BIT_MODE_3 |
ME4000_DIO_CTRL_BIT_MODE_4 | ME4000_DIO_CTRL_BIT_MODE_5 |
ME4000_DIO_CTRL_BIT_MODE_6 | ME4000_DIO_CTRL_BIT_MODE_7);
if (s->io_bits & 0x000000ff)
tmp |= ME4000_DIO_CTRL_BIT_MODE_0;
if (s->io_bits & 0x0000ff00)
tmp |= ME4000_DIO_CTRL_BIT_MODE_2;
if (s->io_bits & 0x00ff0000)
tmp |= ME4000_DIO_CTRL_BIT_MODE_4;
if (s->io_bits & 0xff000000)
tmp |= ME4000_DIO_CTRL_BIT_MODE_6;
if (inl(dev->iobase + ME4000_DIO_DIR_REG)) {
s->io_bits |= 0x000000ff;
s->io_bits &= ~0x0000ff00;
tmp |= ME4000_DIO_CTRL_BIT_MODE_0;
tmp &= ~(ME4000_DIO_CTRL_BIT_MODE_2 |
ME4000_DIO_CTRL_BIT_MODE_3);
}
outl(tmp, dev->iobase + ME4000_DIO_CTRL_REG);
return insn->n;
}
static int me4000_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct me4000_board *thisboard = NULL;
struct me4000_info *info;
struct comedi_subdevice *s;
int result;
if (context < ARRAY_SIZE(me4000_boards))
thisboard = &me4000_boards[context];
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
info = comedi_alloc_devpriv(dev, sizeof(*info));
if (!info)
return -ENOMEM;
result = comedi_pci_enable(dev);
if (result)
return result;
info->plx_regbase = pci_resource_start(pcidev, 1);
dev->iobase = pci_resource_start(pcidev, 2);
if (!info->plx_regbase || !dev->iobase)
return -ENODEV;
result = comedi_load_firmware(dev, &pcidev->dev, ME4000_FIRMWARE,
me4000_xilinx_download, 0);
if (result < 0)
return result;
me4000_reset(dev);
if (pcidev->irq > 0) {
result = request_irq(pcidev->irq, me4000_ai_isr, IRQF_SHARED,
dev->board_name, dev);
if (result == 0)
dev->irq = pcidev->irq;
}
result = comedi_alloc_subdevices(dev, 4);
if (result)
return result;
s = &dev->subdevices[0];
if (thisboard->ai_nchan) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags =
SDF_READABLE | SDF_COMMON | SDF_GROUND | SDF_DIFF;
s->n_chan = thisboard->ai_nchan;
s->maxdata = 0xFFFF;
s->len_chanlist = ME4000_AI_CHANNEL_LIST_COUNT;
s->range_table = &me4000_ai_range;
s->insn_read = me4000_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->cancel = me4000_ai_cancel;
s->do_cmdtest = me4000_ai_do_cmd_test;
s->do_cmd = me4000_ai_do_cmd;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (thisboard->ao_nchan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_COMMON | SDF_GROUND;
s->n_chan = thisboard->ao_nchan;
s->maxdata = 0xFFFF;
s->range_table = &range_bipolar10;
s->insn_write = me4000_ao_insn_write;
result = comedi_alloc_subdev_readback(s);
if (result)
return result;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (thisboard->dio_nchan) {
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = thisboard->dio_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = me4000_dio_insn_bits;
s->insn_config = me4000_dio_insn_config;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
if (!inl(dev->iobase + ME4000_DIO_DIR_REG)) {
s->io_bits |= 0xFF;
outl(ME4000_DIO_CTRL_BIT_MODE_0,
dev->iobase + ME4000_DIO_DIR_REG);
}
s = &dev->subdevices[3];
if (thisboard->has_counter) {
unsigned long timer_base = pci_resource_start(pcidev, 3);
if (!timer_base)
return -ENODEV;
dev->pacer = comedi_8254_init(timer_base, 0, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
comedi_8254_subdevice_init(s, dev->pacer);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static void me4000_detach(struct comedi_device *dev)
{
if (dev->iobase)
me4000_reset(dev);
comedi_pci_detach(dev);
}
static int me4000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &me4000_driver, id->driver_data);
}
