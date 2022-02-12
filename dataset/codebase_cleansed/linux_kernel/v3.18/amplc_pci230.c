static unsigned short pci230_ai_read(struct comedi_device *dev)
{
const struct pci230_board *thisboard = dev->board_ptr;
struct pci230_private *devpriv = dev->private;
unsigned short data;
data = inw(devpriv->daqio + PCI230_ADCDATA);
if (devpriv->ai_bipolar)
data ^= 0x8000;
data >>= (16 - thisboard->ai_bits);
return data;
}
static unsigned short pci230_ao_mangle_datum(struct comedi_device *dev,
unsigned short datum)
{
const struct pci230_board *thisboard = dev->board_ptr;
struct pci230_private *devpriv = dev->private;
datum <<= (16 - thisboard->ao_bits);
if (devpriv->ao_bipolar)
datum ^= 0x8000;
return datum;
}
static void pci230_ao_write_nofifo(struct comedi_device *dev,
unsigned short datum, unsigned int chan)
{
struct pci230_private *devpriv = dev->private;
outw(pci230_ao_mangle_datum(dev, datum),
devpriv->daqio + ((chan == 0) ? PCI230_DACOUT1 : PCI230_DACOUT2));
}
static void pci230_ao_write_fifo(struct comedi_device *dev,
unsigned short datum, unsigned int chan)
{
struct pci230_private *devpriv = dev->private;
outw(pci230_ao_mangle_datum(dev, datum),
devpriv->daqio + PCI230P2_DACDATA);
}
static bool pci230_claim_shared(struct comedi_device *dev,
unsigned char res_mask, unsigned int owner)
{
struct pci230_private *devpriv = dev->private;
unsigned int o;
unsigned long irqflags;
spin_lock_irqsave(&devpriv->res_spinlock, irqflags);
for (o = 0; o < NUM_OWNERS; o++) {
if (o == owner)
continue;
if (devpriv->res_owned[o] & res_mask) {
spin_unlock_irqrestore(&devpriv->res_spinlock,
irqflags);
return false;
}
}
devpriv->res_owned[owner] |= res_mask;
spin_unlock_irqrestore(&devpriv->res_spinlock, irqflags);
return true;
}
static void pci230_release_shared(struct comedi_device *dev,
unsigned char res_mask, unsigned int owner)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
spin_lock_irqsave(&devpriv->res_spinlock, irqflags);
devpriv->res_owned[owner] &= ~res_mask;
spin_unlock_irqrestore(&devpriv->res_spinlock, irqflags);
}
static void pci230_release_all_resources(struct comedi_device *dev,
unsigned int owner)
{
pci230_release_shared(dev, (unsigned char)~0, owner);
}
static unsigned int pci230_divide_ns(uint64_t ns, unsigned int timebase,
unsigned int flags)
{
uint64_t div;
unsigned int rem;
div = ns;
rem = do_div(div, timebase);
switch (flags & CMDF_ROUND_MASK) {
default:
case CMDF_ROUND_NEAREST:
div += (rem + (timebase / 2)) / timebase;
break;
case CMDF_ROUND_DOWN:
break;
case CMDF_ROUND_UP:
div += (rem + timebase - 1) / timebase;
break;
}
return div > UINT_MAX ? UINT_MAX : (unsigned int)div;
}
static unsigned int pci230_choose_clk_count(uint64_t ns, unsigned int *count,
unsigned int flags)
{
unsigned int clk_src, cnt;
for (clk_src = CLK_10MHZ;; clk_src++) {
cnt = pci230_divide_ns(ns, pci230_timebase[clk_src], flags);
if (cnt <= 65536 || clk_src == CLK_1KHZ)
break;
}
*count = cnt;
return clk_src;
}
static void pci230_ns_to_single_timer(unsigned int *ns, unsigned int flags)
{
unsigned int count;
unsigned int clk_src;
clk_src = pci230_choose_clk_count(*ns, &count, flags);
*ns = count * pci230_timebase[clk_src];
}
static void pci230_ct_setup_ns_mode(struct comedi_device *dev, unsigned int ct,
unsigned int mode, uint64_t ns,
unsigned int flags)
{
unsigned int clk_src;
unsigned int count;
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, ct, mode);
clk_src = pci230_choose_clk_count(ns, &count, flags);
outb(CLK_CONFIG(ct, clk_src), dev->iobase + PCI230_ZCLK_SCE);
if (count >= 65536)
count = 0;
i8254_write(dev->iobase + PCI230_Z2_CT_BASE, 0, ct, count);
}
static void pci230_cancel_ct(struct comedi_device *dev, unsigned int ct)
{
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, ct, I8254_MODE1);
}
static int pci230_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct pci230_private *devpriv = dev->private;
unsigned int status;
status = inw(devpriv->daqio + PCI230_ADCCON);
if ((status & PCI230_ADC_FIFO_EMPTY) == 0)
return 0;
return -EBUSY;
}
static int pci230_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci230_private *devpriv = dev->private;
unsigned int n;
unsigned int chan, range, aref;
unsigned int gainshift;
unsigned short adccon, adcen;
int ret;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
aref = CR_AREF(insn->chanspec);
if (aref == AREF_DIFF) {
if (chan >= s->n_chan / 2) {
dev_dbg(dev->class_dev,
"%s: differential channel number out of range 0 to %u\n",
__func__, (s->n_chan / 2) - 1);
return -EINVAL;
}
}
adccon = PCI230_ADC_TRIG_Z2CT2 | PCI230_ADC_FIFO_EN;
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE0);
devpriv->ai_bipolar = comedi_range_is_bipolar(s, range);
if (aref == AREF_DIFF) {
gainshift = chan * 2;
if (devpriv->hwver == 0) {
adcen = 3 << gainshift;
} else {
adcen = 1 << gainshift;
}
adccon |= PCI230_ADC_IM_DIF;
} else {
adcen = 1 << chan;
gainshift = chan & ~1;
adccon |= PCI230_ADC_IM_SE;
}
devpriv->adcg = (devpriv->adcg & ~(3 << gainshift)) |
(pci230_ai_gain[range] << gainshift);
if (devpriv->ai_bipolar)
adccon |= PCI230_ADC_IR_BIP;
else
adccon |= PCI230_ADC_IR_UNI;
outw(adcen, devpriv->daqio + PCI230_ADCEN);
outw(devpriv->adcg, devpriv->daqio + PCI230_ADCG);
devpriv->adccon = adccon;
outw(adccon | PCI230_ADC_FIFO_RESET, devpriv->daqio + PCI230_ADCCON);
for (n = 0; n < insn->n; n++) {
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0,
2, I8254_MODE0);
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0,
2, I8254_MODE1);
ret = comedi_timeout(dev, s, insn, pci230_ai_eoc, 0);
if (ret)
return ret;
data[n] = pci230_ai_read(dev);
}
return n;
}
static int pci230_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci230_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
devpriv->ao_bipolar = comedi_range_is_bipolar(s, range);
outw(range, devpriv->daqio + PCI230_DACCON);
for (i = 0; i < insn->n; i++) {
val = data[i];
pci230_ao_write_nofifo(dev, val, chan);
}
s->readback[chan] = val;
return insn->n;
}
static int pci230_ao_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int prev_chan = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan < prev_chan) {
dev_dbg(dev->class_dev,
"%s: channel numbers must increase\n",
__func__);
return -EINVAL;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"%s: channels must have the same range\n",
__func__);
return -EINVAL;
}
prev_chan = chan;
}
return 0;
}
static int pci230_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pci230_board *thisboard = dev->board_ptr;
struct pci230_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT);
tmp = TRIG_TIMER | TRIG_INT;
if (thisboard->min_hwver > 0 && devpriv->hwver >= 2) {
tmp |= TRIG_EXT;
}
err |= cfc_check_trigger_src(&cmd->scan_begin_src, tmp);
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
#define MAX_SPEED_AO 8000
#define MIN_SPEED_AO 4294967295u
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED_AO);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
MIN_SPEED_AO);
break;
case TRIG_EXT:
if (cmd->scan_begin_arg & ~CR_FLAGS_MASK) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if (cmd->scan_begin_arg & CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT)) {
cmd->scan_begin_arg =
COMBINE(cmd->scan_begin_arg, 0,
CR_FLAGS_MASK & ~(CR_EDGE | CR_INVERT));
err |= -EINVAL;
}
break;
default:
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
break;
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
pci230_ns_to_single_timer(&cmd->scan_begin_arg, cmd->flags);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= pci230_ao_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static void pci230_ao_stop(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned char intsrc;
bool started;
struct comedi_cmd *cmd;
spin_lock_irqsave(&devpriv->ao_stop_spinlock, irqflags);
started = devpriv->ao_cmd_started;
devpriv->ao_cmd_started = false;
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock, irqflags);
if (!started)
return;
cmd = &s->async->cmd;
if (cmd->scan_begin_src == TRIG_TIMER) {
pci230_cancel_ct(dev, 1);
}
if (devpriv->hwver < 2) {
intsrc = PCI230_INT_ZCLK_CT1;
} else {
intsrc = PCI230P2_INT_DAC;
}
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->ier &= ~intsrc;
while (devpriv->intr_running && devpriv->intr_cpuid != THISCPU) {
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
}
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
if (devpriv->hwver >= 2) {
devpriv->daccon &= PCI230_DAC_OR_MASK;
outw(devpriv->daccon | PCI230P2_DAC_FIFO_RESET |
PCI230P2_DAC_FIFO_UNDERRUN_CLEAR,
devpriv->daqio + PCI230_DACCON);
}
pci230_release_all_resources(dev, OWNER_AOCMD);
}
static void pci230_handle_ao_nofifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned short data;
int i, ret;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
if (cmd->stop_src == TRIG_COUNT && devpriv->ao_scan_count == 0)
return;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
ret = comedi_buf_get(s, &data);
if (ret == 0) {
s->async->events |= COMEDI_CB_OVERFLOW;
pci230_ao_stop(dev, s);
dev_err(dev->class_dev, "AO buffer underrun\n");
return;
}
pci230_ao_write_nofifo(dev, data, chan);
s->readback[chan] = data;
}
async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ao_scan_count--;
if (devpriv->ao_scan_count == 0) {
async->events |= COMEDI_CB_EOA;
pci230_ao_stop(dev, s);
}
}
}
static bool pci230_handle_ao_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int num_scans;
unsigned int room;
unsigned short dacstat;
unsigned int i, n;
unsigned int events = 0;
bool running;
dacstat = inw(devpriv->daqio + PCI230_DACCON);
num_scans = comedi_buf_read_n_available(s) / cfc_bytes_per_scan(s);
if (cmd->stop_src == TRIG_COUNT) {
if (num_scans > devpriv->ao_scan_count)
num_scans = devpriv->ao_scan_count;
if (devpriv->ao_scan_count == 0) {
events |= COMEDI_CB_EOA;
}
}
if (events == 0) {
if (dacstat & PCI230P2_DAC_FIFO_UNDERRUN_LATCHED) {
dev_err(dev->class_dev, "AO FIFO underrun\n");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
if (num_scans == 0 &&
(dacstat & PCI230P2_DAC_FIFO_HALF) == 0) {
dev_err(dev->class_dev, "AO buffer underrun\n");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
}
if (events == 0) {
if (dacstat & PCI230P2_DAC_FIFO_FULL)
room = PCI230P2_DAC_FIFOROOM_FULL;
else if (dacstat & PCI230P2_DAC_FIFO_HALF)
room = PCI230P2_DAC_FIFOROOM_HALFTOFULL;
else if (dacstat & PCI230P2_DAC_FIFO_EMPTY)
room = PCI230P2_DAC_FIFOROOM_EMPTY;
else
room = PCI230P2_DAC_FIFOROOM_ONETOHALF;
room /= cmd->chanlist_len;
if (num_scans > room)
num_scans = room;
for (n = 0; n < num_scans; n++) {
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned short datum;
comedi_buf_get(s, &datum);
pci230_ao_write_fifo(dev, datum, chan);
s->readback[chan] = datum;
}
}
events |= COMEDI_CB_EOS | COMEDI_CB_BLOCK;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ao_scan_count -= num_scans;
if (devpriv->ao_scan_count == 0) {
devpriv->daccon =
(devpriv->daccon &
~PCI230P2_DAC_INT_FIFO_MASK) |
PCI230P2_DAC_INT_FIFO_EMPTY;
outw(devpriv->daccon,
devpriv->daqio + PCI230_DACCON);
}
}
dacstat = inw(devpriv->daqio + PCI230_DACCON);
if (dacstat & PCI230P2_DAC_FIFO_UNDERRUN_LATCHED) {
dev_err(dev->class_dev, "AO FIFO underrun\n");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
}
if (events & (COMEDI_CB_EOA | COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW)) {
pci230_ao_stop(dev, s);
running = false;
} else {
running = true;
}
async->events |= events;
return running;
}
static int pci230_ao_inttrig_scan_begin(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
if (trig_num)
return -EINVAL;
spin_lock_irqsave(&devpriv->ao_stop_spinlock, irqflags);
if (!devpriv->ao_cmd_started) {
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock, irqflags);
return 1;
}
if (devpriv->hwver < 2) {
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock, irqflags);
pci230_handle_ao_nofifo(dev, s);
comedi_event(dev, s);
} else {
inw(devpriv->daqio + PCI230P2_DACSWTRIG);
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock, irqflags);
}
udelay(8);
return 1;
}
static void pci230_ao_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long irqflags;
devpriv->ao_cmd_started = true;
if (devpriv->hwver >= 2) {
unsigned short scantrig;
bool run;
run = pci230_handle_ao_fifo(dev, s);
comedi_event(dev, s);
if (!run) {
return;
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
scantrig = PCI230P2_DAC_TRIG_Z2CT1;
break;
case TRIG_EXT:
if ((cmd->scan_begin_arg & CR_INVERT) == 0) {
scantrig = PCI230P2_DAC_TRIG_EXTP;
} else {
scantrig = PCI230P2_DAC_TRIG_EXTN;
}
break;
case TRIG_INT:
scantrig = PCI230P2_DAC_TRIG_SW;
break;
default:
scantrig = PCI230P2_DAC_TRIG_NONE;
break;
}
devpriv->daccon =
(devpriv->daccon & ~PCI230P2_DAC_TRIG_MASK) | scantrig;
outw(devpriv->daccon, devpriv->daqio + PCI230_DACCON);
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
if (devpriv->hwver < 2) {
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->ier |= PCI230_INT_ZCLK_CT1;
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock,
irqflags);
}
outb(GAT_CONFIG(1, GAT_VCC), dev->iobase + PCI230_ZGAT_SCE);
break;
case TRIG_INT:
async->inttrig = pci230_ao_inttrig_scan_begin;
break;
}
if (devpriv->hwver >= 2) {
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->ier |= PCI230P2_INT_DAC;
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
}
}
static int pci230_ao_inttrig_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_src)
return -EINVAL;
s->async->inttrig = NULL;
pci230_ao_start(dev, s);
return 1;
}
static int pci230_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned short daccon;
unsigned int range;
struct comedi_cmd *cmd = &s->async->cmd;
if (cmd->scan_begin_src == TRIG_TIMER) {
if (!pci230_claim_shared(dev, RES_Z2CT1, OWNER_AOCMD))
return -EBUSY;
}
devpriv->ao_scan_count = cmd->stop_arg;
range = CR_RANGE(cmd->chanlist[0]);
devpriv->ao_bipolar = comedi_range_is_bipolar(s, range);
daccon = devpriv->ao_bipolar ? PCI230_DAC_OR_BIP : PCI230_DAC_OR_UNI;
if (devpriv->hwver >= 2) {
unsigned short dacen;
unsigned int i;
dacen = 0;
for (i = 0; i < cmd->chanlist_len; i++)
dacen |= 1 << CR_CHAN(cmd->chanlist[i]);
outw(dacen, devpriv->daqio + PCI230P2_DACEN);
daccon |= PCI230P2_DAC_FIFO_EN | PCI230P2_DAC_FIFO_RESET |
PCI230P2_DAC_FIFO_UNDERRUN_CLEAR |
PCI230P2_DAC_TRIG_NONE | PCI230P2_DAC_INT_FIFO_NHALF;
}
outw(daccon, devpriv->daqio + PCI230_DACCON);
devpriv->daccon = daccon & ~(PCI230P2_DAC_FIFO_RESET |
PCI230P2_DAC_FIFO_UNDERRUN_CLEAR);
if (cmd->scan_begin_src == TRIG_TIMER) {
outb(GAT_CONFIG(1, GAT_GND), dev->iobase + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 1, I8254_MODE3,
cmd->scan_begin_arg,
cmd->flags);
}
s->async->inttrig = pci230_ao_inttrig_start;
return 0;
}
static int pci230_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
pci230_ao_stop(dev, s);
return 0;
}
static int pci230_ai_check_scan_period(struct comedi_cmd *cmd)
{
unsigned int min_scan_period, chanlist_len;
int err = 0;
chanlist_len = cmd->chanlist_len;
if (cmd->chanlist_len == 0)
chanlist_len = 1;
min_scan_period = chanlist_len * cmd->convert_arg;
if (min_scan_period < chanlist_len ||
min_scan_period < cmd->convert_arg) {
min_scan_period = UINT_MAX;
err++;
}
if (cmd->scan_begin_arg < min_scan_period) {
cmd->scan_begin_arg = min_scan_period;
err++;
}
return !err;
}
static int pci230_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct pci230_private *devpriv = dev->private;
unsigned int max_diff_chan = (s->n_chan / 2) - 1;
unsigned int prev_chan = 0;
unsigned int prev_range = 0;
unsigned int prev_aref = 0;
bool prev_bipolar = false;
unsigned int subseq_len = 0;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chanspec = cmd->chanlist[i];
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
bool bipolar = comedi_range_is_bipolar(s, range);
if (aref == AREF_DIFF && chan >= max_diff_chan) {
dev_dbg(dev->class_dev,
"%s: differential channel number out of range 0 to %u\n",
__func__, max_diff_chan);
return -EINVAL;
}
if (i > 0) {
if (chan <= prev_chan && subseq_len == 0)
subseq_len = i;
if (subseq_len > 0 &&
cmd->chanlist[i % subseq_len] != chanspec) {
dev_dbg(dev->class_dev,
"%s: channel numbers must increase or sequence must repeat exactly\n",
__func__);
return -EINVAL;
}
if (aref != prev_aref) {
dev_dbg(dev->class_dev,
"%s: channel sequence analogue references must be all the same (single-ended or differential)\n",
__func__);
return -EINVAL;
}
if (bipolar != prev_bipolar) {
dev_dbg(dev->class_dev,
"%s: channel sequence ranges must be all bipolar or all unipolar\n",
__func__);
return -EINVAL;
}
if (aref != AREF_DIFF && range != prev_range &&
((chan ^ prev_chan) & ~1) == 0) {
dev_dbg(dev->class_dev,
"%s: single-ended channel pairs must have the same range\n",
__func__);
return -EINVAL;
}
}
prev_chan = chan;
prev_range = range;
prev_aref = aref;
prev_bipolar = bipolar;
}
if (subseq_len == 0)
subseq_len = cmd->chanlist_len;
if (cmd->chanlist_len % subseq_len) {
dev_dbg(dev->class_dev,
"%s: sequence must repeat exactly\n", __func__);
return -EINVAL;
}
if (devpriv->hwver > 0 && devpriv->hwver < 4) {
if (subseq_len > 1 && CR_CHAN(cmd->chanlist[0])) {
dev_info(dev->class_dev,
"amplc_pci230: ai_cmdtest: Buggy PCI230+/260+ h/w version %u requires first channel of multi-channel sequence to be 0 (corrected in h/w version 4)\n",
devpriv->hwver);
return -EINVAL;
}
}
return 0;
}
static int pci230_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pci230_board *thisboard = dev->board_ptr;
struct pci230_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
tmp = TRIG_FOLLOW | TRIG_TIMER | TRIG_INT;
if (thisboard->have_dio || thisboard->min_hwver > 0) {
tmp |= TRIG_EXT;
}
err |= cfc_check_trigger_src(&cmd->scan_begin_src, tmp);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_INT | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src != TRIG_FOLLOW &&
cmd->convert_src != TRIG_TIMER)
err |= -EINVAL;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
#define MAX_SPEED_AI_SE 3200
#define MAX_SPEED_AI_DIFF 8000
#define MAX_SPEED_AI_PLUS 4000
#define MIN_SPEED_AI 4294967295u
if (cmd->convert_src == TRIG_TIMER) {
unsigned int max_speed_ai;
if (devpriv->hwver == 0) {
if (cmd->chanlist && cmd->chanlist_len > 0) {
if (CR_AREF(cmd->chanlist[0]) == AREF_DIFF)
max_speed_ai = MAX_SPEED_AI_DIFF;
else
max_speed_ai = MAX_SPEED_AI_SE;
} else {
max_speed_ai = MAX_SPEED_AI_SE;
}
} else {
max_speed_ai = MAX_SPEED_AI_PLUS;
}
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
max_speed_ai);
err |= cfc_check_trigger_arg_max(&cmd->convert_arg,
MIN_SPEED_AI);
} else if (cmd->convert_src == TRIG_EXT) {
if (cmd->convert_arg & CR_FLAGS_MASK) {
if (cmd->convert_arg & ~CR_FLAGS_MASK) {
cmd->convert_arg = COMBINE(cmd->convert_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->convert_arg & CR_FLAGS_MASK & ~CR_INVERT) !=
CR_EDGE) {
cmd->convert_arg =
COMBINE(cmd->start_arg, CR_EDGE | 0,
CR_FLAGS_MASK & ~CR_INVERT);
err |= -EINVAL;
}
} else {
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, 1);
}
} else {
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (cmd->scan_begin_src == TRIG_EXT) {
if (cmd->scan_begin_arg & ~CR_FLAGS_MASK) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if (cmd->scan_begin_arg & CR_FLAGS_MASK & ~CR_EDGE) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
CR_FLAGS_MASK & ~CR_EDGE);
err |= -EINVAL;
}
} else if (cmd->scan_begin_src == TRIG_TIMER) {
if (!pci230_ai_check_scan_period(cmd))
err |= -EINVAL;
} else {
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
}
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
pci230_ns_to_single_timer(&cmd->convert_arg, cmd->flags);
if (tmp != cmd->convert_arg)
err++;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
pci230_ns_to_single_timer(&cmd->scan_begin_arg, cmd->flags);
if (!pci230_ai_check_scan_period(cmd)) {
pci230_ns_to_single_timer(&cmd->scan_begin_arg,
CMDF_ROUND_UP);
pci230_ai_check_scan_period(cmd);
}
if (tmp != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= pci230_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static void pci230_ai_update_fifo_trigger_level(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int scanlen = cmd->scan_end_arg;
unsigned int wake;
unsigned short triglev;
unsigned short adccon;
if (cmd->flags & CMDF_WAKE_EOS)
wake = scanlen - devpriv->ai_scan_pos;
else if (cmd->stop_src != TRIG_COUNT ||
devpriv->ai_scan_count >= PCI230_ADC_FIFOLEVEL_HALFFULL ||
scanlen >= PCI230_ADC_FIFOLEVEL_HALFFULL)
wake = PCI230_ADC_FIFOLEVEL_HALFFULL;
else
wake = devpriv->ai_scan_count * scanlen - devpriv->ai_scan_pos;
if (wake >= PCI230_ADC_FIFOLEVEL_HALFFULL) {
triglev = PCI230_ADC_INT_FIFO_HALF;
} else if (wake > 1 && devpriv->hwver > 0) {
if (devpriv->adcfifothresh != wake) {
devpriv->adcfifothresh = wake;
outw(wake, devpriv->daqio + PCI230P_ADCFFTH);
}
triglev = PCI230P_ADC_INT_FIFO_THRESH;
} else {
triglev = PCI230_ADC_INT_FIFO_NEMPTY;
}
adccon = (devpriv->adccon & ~PCI230_ADC_INT_FIFO_MASK) | triglev;
if (adccon != devpriv->adccon) {
devpriv->adccon = adccon;
outw(adccon, devpriv->daqio + PCI230_ADCCON);
}
}
static int pci230_ai_inttrig_convert(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned int delayus;
if (trig_num)
return -EINVAL;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
if (!devpriv->ai_cmd_started) {
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
return 1;
}
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE0);
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE1);
if ((devpriv->adccon & PCI230_ADC_IM_MASK) == PCI230_ADC_IM_DIF &&
devpriv->hwver == 0) {
delayus = 8;
} else {
delayus = 4;
}
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
udelay(delayus);
return 1;
}
static int pci230_ai_inttrig_scan_begin(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned char zgat;
if (trig_num)
return -EINVAL;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
if (devpriv->ai_cmd_started) {
zgat = GAT_CONFIG(0, GAT_GND);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
zgat = GAT_CONFIG(0, GAT_VCC);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
}
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
return 1;
}
static void pci230_ai_stop(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
struct comedi_cmd *cmd;
bool started;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
started = devpriv->ai_cmd_started;
devpriv->ai_cmd_started = false;
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
if (!started)
return;
cmd = &s->async->cmd;
if (cmd->convert_src == TRIG_TIMER) {
pci230_cancel_ct(dev, 2);
}
if (cmd->scan_begin_src != TRIG_FOLLOW) {
pci230_cancel_ct(dev, 0);
}
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->ier &= ~PCI230_INT_ADC;
while (devpriv->intr_running && devpriv->intr_cpuid != THISCPU) {
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
}
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
devpriv->adccon =
(devpriv->adccon & (PCI230_ADC_IR_MASK | PCI230_ADC_IM_MASK)) |
PCI230_ADC_TRIG_NONE;
outw(devpriv->adccon | PCI230_ADC_FIFO_RESET,
devpriv->daqio + PCI230_ADCCON);
pci230_release_all_resources(dev, OWNER_AICMD);
}
static void pci230_ai_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned short conv;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
devpriv->ai_cmd_started = true;
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->ier |= PCI230_INT_ADC;
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
switch (cmd->convert_src) {
default:
conv = PCI230_ADC_TRIG_NONE;
break;
case TRIG_TIMER:
conv = PCI230_ADC_TRIG_Z2CT2;
break;
case TRIG_EXT:
if (cmd->convert_arg & CR_EDGE) {
if ((cmd->convert_arg & CR_INVERT) == 0) {
conv = PCI230_ADC_TRIG_EXTP;
} else {
conv = PCI230_ADC_TRIG_EXTN;
}
} else {
if (cmd->convert_arg) {
conv = PCI230_ADC_TRIG_EXTP;
} else {
conv = PCI230_ADC_TRIG_EXTN;
}
}
break;
case TRIG_INT:
conv = PCI230_ADC_TRIG_Z2CT2;
break;
}
devpriv->adccon = (devpriv->adccon & ~PCI230_ADC_TRIG_MASK) | conv;
outw(devpriv->adccon, devpriv->daqio + PCI230_ADCCON);
if (cmd->convert_src == TRIG_INT)
async->inttrig = pci230_ai_inttrig_convert;
pci230_ai_update_fifo_trigger_level(dev, s);
if (cmd->convert_src == TRIG_TIMER) {
unsigned char zgat;
if (cmd->scan_begin_src != TRIG_FOLLOW) {
zgat = GAT_CONFIG(2, GAT_NOUTNM2);
} else {
zgat = GAT_CONFIG(2, GAT_VCC);
}
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
if (cmd->scan_begin_src != TRIG_FOLLOW) {
switch (cmd->scan_begin_src) {
default:
zgat = GAT_CONFIG(0, GAT_VCC);
break;
case TRIG_EXT:
zgat = GAT_CONFIG(0, GAT_EXT);
break;
case TRIG_TIMER:
zgat = GAT_CONFIG(0, GAT_NOUTNM2);
break;
case TRIG_INT:
zgat = GAT_CONFIG(0, GAT_VCC);
break;
}
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
zgat = GAT_CONFIG(1, GAT_VCC);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
break;
case TRIG_INT:
async->inttrig = pci230_ai_inttrig_scan_begin;
break;
}
}
} else if (cmd->convert_src != TRIG_INT) {
pci230_release_shared(dev, RES_Z2CT2, OWNER_AICMD);
}
}
static int pci230_ai_inttrig_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
s->async->inttrig = NULL;
pci230_ai_start(dev, s);
return 1;
}
static void pci230_handle_ai(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int scanlen = cmd->scan_end_arg;
unsigned int events = 0;
unsigned int status_fifo;
unsigned int i;
unsigned int todo;
unsigned int fifoamount;
if (cmd->stop_src != TRIG_COUNT) {
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else if (devpriv->ai_scan_count == 0) {
todo = 0;
} else if (devpriv->ai_scan_count > PCI230_ADC_FIFOLEVEL_HALFFULL ||
scanlen > PCI230_ADC_FIFOLEVEL_HALFFULL) {
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else {
todo = devpriv->ai_scan_count * scanlen - devpriv->ai_scan_pos;
if (todo > PCI230_ADC_FIFOLEVEL_HALFFULL)
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
}
if (todo == 0)
return;
fifoamount = 0;
for (i = 0; i < todo; i++) {
if (fifoamount == 0) {
status_fifo = inw(devpriv->daqio + PCI230_ADCCON);
if (status_fifo & PCI230_ADC_FIFO_FULL_LATCHED) {
dev_err(dev->class_dev, "AI FIFO overrun\n");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
break;
} else if (status_fifo & PCI230_ADC_FIFO_EMPTY) {
break;
} else if (status_fifo & PCI230_ADC_FIFO_HALF) {
fifoamount = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else if (devpriv->hwver > 0) {
fifoamount = inw(devpriv->daqio +
PCI230P_ADCFFLEV);
if (fifoamount == 0)
break;
} else {
fifoamount = 1;
}
}
if (comedi_buf_put(s, pci230_ai_read(dev)) == 0) {
events |= COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW;
dev_err(dev->class_dev, "AI buffer overflow\n");
break;
}
fifoamount--;
devpriv->ai_scan_pos++;
if (devpriv->ai_scan_pos == scanlen) {
devpriv->ai_scan_pos = 0;
devpriv->ai_scan_count--;
async->events |= COMEDI_CB_EOS;
}
}
if (cmd->stop_src == TRIG_COUNT && devpriv->ai_scan_count == 0) {
events |= COMEDI_CB_EOA;
} else {
events |= COMEDI_CB_BLOCK;
}
async->events |= events;
if (async->events & (COMEDI_CB_EOA | COMEDI_CB_ERROR |
COMEDI_CB_OVERFLOW)) {
pci230_ai_stop(dev, s);
} else {
pci230_ai_update_fifo_trigger_level(dev, s);
}
}
static int pci230_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned int i, chan, range, diff;
unsigned int res_mask;
unsigned short adccon, adcen;
unsigned char zgat;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
res_mask = 0;
res_mask |= RES_Z2CT2;
if (cmd->scan_begin_src != TRIG_FOLLOW) {
res_mask |= RES_Z2CT0;
if (cmd->scan_begin_src == TRIG_TIMER) {
res_mask |= RES_Z2CT1;
}
}
if (!pci230_claim_shared(dev, res_mask, OWNER_AICMD))
return -EBUSY;
devpriv->ai_scan_count = cmd->stop_arg;
devpriv->ai_scan_pos = 0;
adccon = PCI230_ADC_FIFO_EN;
adcen = 0;
if (CR_AREF(cmd->chanlist[0]) == AREF_DIFF) {
diff = 1;
adccon |= PCI230_ADC_IM_DIF;
} else {
diff = 0;
adccon |= PCI230_ADC_IM_SE;
}
range = CR_RANGE(cmd->chanlist[0]);
devpriv->ai_bipolar = comedi_range_is_bipolar(s, range);
if (devpriv->ai_bipolar)
adccon |= PCI230_ADC_IR_BIP;
else
adccon |= PCI230_ADC_IR_UNI;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int gainshift;
chan = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
if (diff) {
gainshift = 2 * chan;
if (devpriv->hwver == 0) {
adcen |= 3 << gainshift;
} else {
adcen |= 1 << gainshift;
}
} else {
gainshift = chan & ~1;
adcen |= 1 << chan;
}
devpriv->adcg = (devpriv->adcg & ~(3 << gainshift)) |
(pci230_ai_gain[range] << gainshift);
}
outw(adcen, devpriv->daqio + PCI230_ADCEN);
outw(devpriv->adcg, devpriv->daqio + PCI230_ADCG);
i8254_set_mode(dev->iobase + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE1);
adccon |= PCI230_ADC_INT_FIFO_FULL | PCI230_ADC_TRIG_Z2CT2;
devpriv->adccon = adccon;
outw(adccon | PCI230_ADC_FIFO_RESET, devpriv->daqio + PCI230_ADCCON);
usleep_range(25, 100);
outw(adccon | PCI230_ADC_FIFO_RESET, devpriv->daqio + PCI230_ADCCON);
if (cmd->convert_src == TRIG_TIMER) {
zgat = GAT_CONFIG(2, GAT_GND);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 2, I8254_MODE3, cmd->convert_arg,
cmd->flags);
if (cmd->scan_begin_src != TRIG_FOLLOW) {
zgat = GAT_CONFIG(0, GAT_VCC);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 0, I8254_MODE1,
((uint64_t)cmd->convert_arg *
cmd->scan_end_arg),
CMDF_ROUND_UP);
if (cmd->scan_begin_src == TRIG_TIMER) {
zgat = GAT_CONFIG(1, GAT_GND);
outb(zgat, dev->iobase + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 1, I8254_MODE3,
cmd->scan_begin_arg,
cmd->flags);
}
}
}
if (cmd->start_src == TRIG_INT)
s->async->inttrig = pci230_ai_inttrig_start;
else
pci230_ai_start(dev, s);
return 0;
}
static int pci230_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
pci230_ai_stop(dev, s);
return 0;
}
static irqreturn_t pci230_interrupt(int irq, void *d)
{
unsigned char status_int, valid_status_int, temp_ier;
struct comedi_device *dev = (struct comedi_device *)d;
struct pci230_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned long irqflags;
status_int = inb(dev->iobase + PCI230_INT_STAT);
if (status_int == PCI230_INT_DISABLE)
return IRQ_NONE;
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
valid_status_int = devpriv->ier & status_int;
temp_ier = devpriv->ier & ~status_int;
outb(temp_ier, dev->iobase + PCI230_INT_SCE);
devpriv->intr_running = true;
devpriv->intr_cpuid = THISCPU;
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
if (valid_status_int & PCI230_INT_ZCLK_CT1) {
s = dev->write_subdev;
pci230_handle_ao_nofifo(dev, s);
comedi_event(dev, s);
}
if (valid_status_int & PCI230P2_INT_DAC) {
s = dev->write_subdev;
pci230_handle_ao_fifo(dev, s);
comedi_event(dev, s);
}
if (valid_status_int & PCI230_INT_ADC) {
s = dev->read_subdev;
pci230_handle_ai(dev, s);
comedi_event(dev, s);
}
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
if (devpriv->ier != temp_ier)
outb(devpriv->ier, dev->iobase + PCI230_INT_SCE);
devpriv->intr_running = false;
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
return IRQ_HANDLED;
}
static bool pci230_match_pci_board(const struct pci230_board *board,
struct pci_dev *pci_dev)
{
if (board->id != pci_dev->device)
return false;
if (board->min_hwver == 0)
return true;
if (pci_resource_len(pci_dev, 3) < 32)
return false;
return true;
}
static const struct pci230_board *pci230_find_pci_board(struct pci_dev *pci_dev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(pci230_boards); i++)
if (pci230_match_pci_board(&pci230_boards[i], pci_dev))
return &pci230_boards[i];
return NULL;
}
static int pci230_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
const struct pci230_board *thisboard;
struct pci230_private *devpriv;
struct comedi_subdevice *s;
int rc;
dev_info(dev->class_dev, "amplc_pci230: attach pci %s\n",
pci_name(pci_dev));
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->isr_spinlock);
spin_lock_init(&devpriv->res_spinlock);
spin_lock_init(&devpriv->ai_stop_spinlock);
spin_lock_init(&devpriv->ao_stop_spinlock);
dev->board_ptr = pci230_find_pci_board(pci_dev);
if (dev->board_ptr == NULL) {
dev_err(dev->class_dev,
"amplc_pci230: BUG! cannot determine board type!\n");
return -EINVAL;
}
thisboard = dev->board_ptr;
dev->board_name = thisboard->name;
rc = comedi_pci_enable(dev);
if (rc)
return rc;
dev->iobase = pci_resource_start(pci_dev, 2);
devpriv->daqio = pci_resource_start(pci_dev, 3);
dev_dbg(dev->class_dev,
"%s I/O region 1 0x%04lx I/O region 2 0x%04lx\n",
dev->board_name, dev->iobase, devpriv->daqio);
devpriv->daccon = inw(devpriv->daqio + PCI230_DACCON) &
PCI230_DAC_OR_MASK;
if (pci_resource_len(pci_dev, 3) >= 32) {
unsigned short extfunc = 0;
devpriv->hwver = inw(devpriv->daqio + PCI230P_HWVER);
if (devpriv->hwver < thisboard->min_hwver) {
dev_err(dev->class_dev,
"%s - bad hardware version - got %u, need %u\n",
dev->board_name, devpriv->hwver,
thisboard->min_hwver);
return -EIO;
}
if (devpriv->hwver > 0) {
if (!thisboard->have_dio) {
extfunc |= PCI230P_EXTFUNC_GAT_EXTTRIG;
}
if (thisboard->ao_bits && devpriv->hwver >= 2) {
extfunc |= PCI230P2_EXTFUNC_DACFIFO;
}
}
outw(extfunc, devpriv->daqio + PCI230P_EXTFUNC);
if (extfunc & PCI230P2_EXTFUNC_DACFIFO) {
outw(devpriv->daccon | PCI230P2_DAC_FIFO_EN |
PCI230P2_DAC_FIFO_RESET,
devpriv->daqio + PCI230_DACCON);
outw(0, devpriv->daqio + PCI230P2_DACEN);
outw(devpriv->daccon, devpriv->daqio + PCI230_DACCON);
}
}
outb(0, dev->iobase + PCI230_INT_SCE);
devpriv->adcg = 0;
devpriv->adccon = PCI230_ADC_TRIG_NONE | PCI230_ADC_IM_SE |
PCI230_ADC_IR_BIP;
outw(1 << 0, devpriv->daqio + PCI230_ADCEN);
outw(devpriv->adcg, devpriv->daqio + PCI230_ADCG);
outw(devpriv->adccon | PCI230_ADC_FIFO_RESET,
devpriv->daqio + PCI230_ADCCON);
if (pci_dev->irq) {
rc = request_irq(pci_dev->irq, pci230_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (rc == 0)
dev->irq = pci_dev->irq;
}
rc = comedi_alloc_subdevices(dev, 3);
if (rc)
return rc;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF | SDF_GROUND;
s->n_chan = 16;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &pci230_ai_range;
s->insn_read = pci230_ai_insn_read;
s->len_chanlist = 256;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmd = pci230_ai_cmd;
s->do_cmdtest = pci230_ai_cmdtest;
s->cancel = pci230_ai_cancel;
}
s = &dev->subdevices[1];
if (thisboard->ao_bits) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 2;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = &pci230_ao_range;
s->insn_write = pci230_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
s->len_chanlist = 2;
if (dev->irq) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->do_cmd = pci230_ao_cmd;
s->do_cmdtest = pci230_ao_cmdtest;
s->cancel = pci230_ao_cancel;
}
rc = comedi_alloc_subdev_readback(s);
if (rc)
return rc;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (thisboard->have_dio) {
rc = subdev_8255_init(dev, s, NULL, PCI230_PPI_X_BASE);
if (rc)
return rc;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static int amplc_pci230_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &amplc_pci230_driver,
id->driver_data);
}
