static unsigned short pci230_ai_read(struct comedi_device *dev)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci230_private *devpriv = dev->private;
unsigned short data;
data = inw(dev->iobase + PCI230_ADCDATA);
data = data >> (16 - thisboard->ai_bits);
if (devpriv->ai_bipolar)
data ^= 1 << (thisboard->ai_bits - 1);
return data;
}
static inline unsigned short pci230_ao_mangle_datum(struct comedi_device *dev,
unsigned short datum)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci230_private *devpriv = dev->private;
if (devpriv->ao_bipolar)
datum ^= 1 << (thisboard->ao_bits - 1);
datum <<= (16 - thisboard->ao_bits);
return datum;
}
static inline void pci230_ao_write_nofifo(struct comedi_device *dev,
unsigned short datum,
unsigned int chan)
{
struct pci230_private *devpriv = dev->private;
devpriv->ao_readback[chan] = datum;
outw(pci230_ao_mangle_datum(dev, datum), dev->iobase + (((chan) == 0)
? PCI230_DACOUT1
:
PCI230_DACOUT2));
}
static inline void pci230_ao_write_fifo(struct comedi_device *dev,
unsigned short datum, unsigned int chan)
{
struct pci230_private *devpriv = dev->private;
devpriv->ao_readback[chan] = datum;
outw(pci230_ao_mangle_datum(dev, datum),
dev->iobase + PCI230P2_DACDATA);
}
static int get_resources(struct comedi_device *dev, unsigned int res_mask,
unsigned char owner)
{
struct pci230_private *devpriv = dev->private;
int ok;
unsigned int i;
unsigned int b;
unsigned int claimed;
unsigned long irqflags;
ok = 1;
claimed = 0;
spin_lock_irqsave(&devpriv->res_spinlock, irqflags);
for (b = 1, i = 0; (i < NUM_RESOURCES)
&& (res_mask != 0); b <<= 1, i++) {
if ((res_mask & b) != 0) {
res_mask &= ~b;
if (devpriv->res_owner[i] == OWNER_NONE) {
devpriv->res_owner[i] = owner;
claimed |= b;
} else if (devpriv->res_owner[i] != owner) {
for (b = 1, i = 0; claimed != 0; b <<= 1, i++) {
if ((claimed & b) != 0) {
devpriv->res_owner[i]
= OWNER_NONE;
claimed &= ~b;
}
}
ok = 0;
break;
}
}
}
spin_unlock_irqrestore(&devpriv->res_spinlock, irqflags);
return ok;
}
static inline int get_one_resource(struct comedi_device *dev,
unsigned int resource, unsigned char owner)
{
return get_resources(dev, (1U << resource), owner);
}
static void put_resources(struct comedi_device *dev, unsigned int res_mask,
unsigned char owner)
{
struct pci230_private *devpriv = dev->private;
unsigned int i;
unsigned int b;
unsigned long irqflags;
spin_lock_irqsave(&devpriv->res_spinlock, irqflags);
for (b = 1, i = 0; (i < NUM_RESOURCES)
&& (res_mask != 0); b <<= 1, i++) {
if ((res_mask & b) != 0) {
res_mask &= ~b;
if (devpriv->res_owner[i] == owner)
devpriv->res_owner[i] = OWNER_NONE;
}
}
spin_unlock_irqrestore(&devpriv->res_spinlock, irqflags);
}
static inline void put_one_resource(struct comedi_device *dev,
unsigned int resource, unsigned char owner)
{
put_resources(dev, (1U << resource), owner);
}
static inline void put_all_resources(struct comedi_device *dev,
unsigned char owner)
{
put_resources(dev, (1U << NUM_RESOURCES) - 1, owner);
}
static unsigned int divide_ns(uint64_t ns, unsigned int timebase,
unsigned int round_mode)
{
uint64_t div;
unsigned int rem;
div = ns;
rem = do_div(div, timebase);
round_mode &= TRIG_ROUND_MASK;
switch (round_mode) {
default:
case TRIG_ROUND_NEAREST:
div += (rem + (timebase / 2)) / timebase;
break;
case TRIG_ROUND_DOWN:
break;
case TRIG_ROUND_UP:
div += (rem + timebase - 1) / timebase;
break;
}
return div > UINT_MAX ? UINT_MAX : (unsigned int)div;
}
static unsigned int pci230_choose_clk_count(uint64_t ns, unsigned int *count,
unsigned int round_mode)
{
unsigned int clk_src, cnt;
for (clk_src = CLK_10MHZ;; clk_src++) {
cnt = divide_ns(ns, pci230_timebase[clk_src], round_mode);
if ((cnt <= 65536) || (clk_src == CLK_1KHZ))
break;
}
*count = cnt;
return clk_src;
}
static void pci230_ns_to_single_timer(unsigned int *ns, unsigned int round)
{
unsigned int count;
unsigned int clk_src;
clk_src = pci230_choose_clk_count(*ns, &count, round);
*ns = count * pci230_timebase[clk_src];
return;
}
static void pci230_ct_setup_ns_mode(struct comedi_device *dev, unsigned int ct,
unsigned int mode, uint64_t ns,
unsigned int round)
{
struct pci230_private *devpriv = dev->private;
unsigned int clk_src;
unsigned int count;
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, ct, mode);
clk_src = pci230_choose_clk_count(ns, &count, round);
outb(CLK_CONFIG(ct, clk_src), devpriv->iobase1 + PCI230_ZCLK_SCE);
if (count >= 65536)
count = 0;
i8254_write(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, ct, count);
}
static void pci230_cancel_ct(struct comedi_device *dev, unsigned int ct)
{
struct pci230_private *devpriv = dev->private;
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, ct,
I8254_MODE1);
}
static int pci230_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct pci230_private *devpriv = dev->private;
unsigned int n, i;
unsigned int chan, range, aref;
unsigned int gainshift;
unsigned int status;
unsigned short adccon, adcen;
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
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE0);
devpriv->ai_bipolar = pci230_ai_bipolar[range];
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
devpriv->adcg = (devpriv->adcg & ~(3 << gainshift))
| (pci230_ai_gain[range] << gainshift);
if (devpriv->ai_bipolar)
adccon |= PCI230_ADC_IR_BIP;
else
adccon |= PCI230_ADC_IR_UNI;
outw(adcen, dev->iobase + PCI230_ADCEN);
outw(devpriv->adcg, dev->iobase + PCI230_ADCG);
devpriv->adccon = adccon;
outw(adccon | PCI230_ADC_FIFO_RESET, dev->iobase + PCI230_ADCCON);
for (n = 0; n < insn->n; n++) {
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2,
I8254_MODE0);
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2,
I8254_MODE1);
#define TIMEOUT 100
for (i = 0; i < TIMEOUT; i++) {
status = inw(dev->iobase + PCI230_ADCCON);
if (!(status & PCI230_ADC_FIFO_EMPTY))
break;
udelay(1);
}
if (i == TIMEOUT) {
dev_err(dev->class_dev, "timeout\n");
return -ETIMEDOUT;
}
data[n] = pci230_ai_read(dev);
}
return n;
}
static int pci230_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct pci230_private *devpriv = dev->private;
int i;
int chan, range;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
devpriv->ao_bipolar = pci230_ao_bipolar[range];
outw(range, dev->iobase + PCI230_DACCON);
for (i = 0; i < insn->n; i++) {
pci230_ao_write_nofifo(dev, data[i], chan);
}
return i;
}
static int pci230_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct pci230_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int pci230_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci230_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT);
tmp = TRIG_TIMER | TRIG_INT;
if ((thisboard->min_hwver > 0) && (devpriv->hwver >= 2)) {
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
if ((cmd->scan_begin_arg & ~CR_FLAGS_MASK) != 0) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->scan_begin_arg
& (CR_FLAGS_MASK & ~(CR_EDGE | CR_INVERT))) != 0) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT));
err |= -EINVAL;
}
break;
default:
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
break;
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_NONE)
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
pci230_ns_to_single_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0) {
enum {
seq_err = (1 << 0),
range_err = (1 << 1)
};
unsigned int errors;
unsigned int n;
unsigned int chan, prev_chan;
unsigned int range, first_range;
prev_chan = CR_CHAN(cmd->chanlist[0]);
first_range = CR_RANGE(cmd->chanlist[0]);
errors = 0;
for (n = 1; n < cmd->chanlist_len; n++) {
chan = CR_CHAN(cmd->chanlist[n]);
range = CR_RANGE(cmd->chanlist[n]);
if (chan < prev_chan)
errors |= seq_err;
if (range != first_range)
errors |= range_err;
prev_chan = chan;
}
if (errors != 0) {
err++;
if ((errors & seq_err) != 0) {
dev_dbg(dev->class_dev,
"%s: channel numbers must increase\n",
__func__);
}
if ((errors & range_err) != 0) {
dev_dbg(dev->class_dev,
"%s: channels must have the same range\n",
__func__);
}
}
}
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
int started;
struct comedi_cmd *cmd;
spin_lock_irqsave(&devpriv->ao_stop_spinlock, irqflags);
started = test_and_clear_bit(AO_CMD_STARTED, &devpriv->state);
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
devpriv->int_en &= ~intsrc;
while (devpriv->intr_running && devpriv->intr_cpuid != THISCPU) {
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
}
if (devpriv->ier != devpriv->int_en) {
devpriv->ier = devpriv->int_en;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
}
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
if (devpriv->hwver >= 2) {
devpriv->daccon &= PCI230_DAC_OR_MASK;
outw(devpriv->daccon | PCI230P2_DAC_FIFO_RESET
| PCI230P2_DAC_FIFO_UNDERRUN_CLEAR,
dev->iobase + PCI230_DACCON);
}
put_all_resources(dev, OWNER_AOCMD);
}
static void pci230_handle_ao_nofifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned short data;
int i, ret;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
if (!devpriv->ao_continuous && (devpriv->ao_scan_count == 0))
return;
for (i = 0; i < cmd->chanlist_len; i++) {
ret = comedi_buf_get(s->async, &data);
if (ret == 0) {
s->async->events |= COMEDI_CB_OVERFLOW;
pci230_ao_stop(dev, s);
comedi_error(dev, "AO buffer underrun");
return;
}
pci230_ao_write_nofifo(dev, data, CR_CHAN(cmd->chanlist[i]));
}
async->events |= COMEDI_CB_BLOCK | COMEDI_CB_EOS;
if (!devpriv->ao_continuous) {
devpriv->ao_scan_count--;
if (devpriv->ao_scan_count == 0) {
async->events |= COMEDI_CB_EOA;
pci230_ao_stop(dev, s);
}
}
}
static int pci230_handle_ao_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int num_scans;
unsigned int room;
unsigned short dacstat;
unsigned int i, n;
unsigned int bytes_per_scan;
unsigned int events = 0;
int running;
dacstat = inw(dev->iobase + PCI230_DACCON);
bytes_per_scan = cmd->chanlist_len * sizeof(short);
num_scans = comedi_buf_read_n_available(async) / bytes_per_scan;
if (!devpriv->ao_continuous) {
if (num_scans > devpriv->ao_scan_count)
num_scans = devpriv->ao_scan_count;
if (devpriv->ao_scan_count == 0) {
events |= COMEDI_CB_EOA;
}
}
if (events == 0) {
if ((dacstat & PCI230P2_DAC_FIFO_UNDERRUN_LATCHED) != 0) {
comedi_error(dev, "AO FIFO underrun");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
if ((num_scans == 0)
&& ((dacstat & PCI230P2_DAC_FIFO_HALF) == 0)) {
comedi_error(dev, "AO buffer underrun");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
}
if (events == 0) {
if ((dacstat & PCI230P2_DAC_FIFO_FULL) != 0)
room = PCI230P2_DAC_FIFOROOM_FULL;
else if ((dacstat & PCI230P2_DAC_FIFO_HALF) != 0)
room = PCI230P2_DAC_FIFOROOM_HALFTOFULL;
else if ((dacstat & PCI230P2_DAC_FIFO_EMPTY) != 0)
room = PCI230P2_DAC_FIFOROOM_EMPTY;
else
room = PCI230P2_DAC_FIFOROOM_ONETOHALF;
room /= cmd->chanlist_len;
if (num_scans > room)
num_scans = room;
for (n = 0; n < num_scans; n++) {
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned short datum;
comedi_buf_get(async, &datum);
pci230_ao_write_fifo(dev, datum,
CR_CHAN(cmd->chanlist[i]));
}
}
events |= COMEDI_CB_EOS | COMEDI_CB_BLOCK;
if (!devpriv->ao_continuous) {
devpriv->ao_scan_count -= num_scans;
if (devpriv->ao_scan_count == 0) {
devpriv->daccon = (devpriv->daccon
&
~PCI230P2_DAC_INT_FIFO_MASK)
| PCI230P2_DAC_INT_FIFO_EMPTY;
outw(devpriv->daccon,
dev->iobase + PCI230_DACCON);
}
}
dacstat = inw(dev->iobase + PCI230_DACCON);
if ((dacstat & PCI230P2_DAC_FIFO_UNDERRUN_LATCHED) != 0) {
comedi_error(dev, "AO FIFO underrun");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
}
}
if ((events & (COMEDI_CB_EOA | COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW))
!= 0) {
pci230_ao_stop(dev, s);
running = 0;
} else {
running = 1;
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
if (trig_num != 0)
return -EINVAL;
spin_lock_irqsave(&devpriv->ao_stop_spinlock, irqflags);
if (test_bit(AO_CMD_STARTED, &devpriv->state)) {
if (devpriv->hwver < 2) {
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock,
irqflags);
pci230_handle_ao_nofifo(dev, s);
comedi_event(dev, s);
} else {
inw(dev->iobase + PCI230P2_DACSWTRIG);
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock,
irqflags);
}
udelay(8);
} else {
spin_unlock_irqrestore(&devpriv->ao_stop_spinlock, irqflags);
}
return 1;
}
static void pci230_ao_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long irqflags;
set_bit(AO_CMD_STARTED, &devpriv->state);
if (!devpriv->ao_continuous && (devpriv->ao_scan_count == 0)) {
async->events |= COMEDI_CB_EOA;
pci230_ao_stop(dev, s);
comedi_event(dev, s);
} else {
if (devpriv->hwver >= 2) {
unsigned short scantrig;
int run;
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
devpriv->daccon = (devpriv->daccon
& ~PCI230P2_DAC_TRIG_MASK) |
scantrig;
outw(devpriv->daccon, dev->iobase + PCI230_DACCON);
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
if (devpriv->hwver < 2) {
spin_lock_irqsave(&devpriv->isr_spinlock,
irqflags);
devpriv->int_en |= PCI230_INT_ZCLK_CT1;
devpriv->ier |= PCI230_INT_ZCLK_CT1;
outb(devpriv->ier,
devpriv->iobase1 + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock,
irqflags);
}
outb(GAT_CONFIG(1, GAT_VCC),
devpriv->iobase1 + PCI230_ZGAT_SCE);
break;
case TRIG_INT:
async->inttrig = pci230_ao_inttrig_scan_begin;
break;
}
if (devpriv->hwver >= 2) {
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->int_en |= PCI230P2_INT_DAC;
devpriv->ier |= PCI230P2_INT_DAC;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock,
irqflags);
}
}
}
static int pci230_ao_inttrig_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
if (trig_num != 0)
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
if (!get_one_resource(dev, RES_Z2CT1, OWNER_AOCMD))
return -EBUSY;
}
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ao_scan_count = cmd->stop_arg;
devpriv->ao_continuous = 0;
} else {
devpriv->ao_scan_count = 0;
devpriv->ao_continuous = 1;
}
range = CR_RANGE(cmd->chanlist[0]);
devpriv->ao_bipolar = pci230_ao_bipolar[range];
daccon = devpriv->ao_bipolar ? PCI230_DAC_OR_BIP : PCI230_DAC_OR_UNI;
if (devpriv->hwver >= 2) {
unsigned short dacen;
unsigned int i;
dacen = 0;
for (i = 0; i < cmd->chanlist_len; i++)
dacen |= 1 << CR_CHAN(cmd->chanlist[i]);
outw(dacen, dev->iobase + PCI230P2_DACEN);
daccon |= PCI230P2_DAC_FIFO_EN | PCI230P2_DAC_FIFO_RESET
| PCI230P2_DAC_FIFO_UNDERRUN_CLEAR
| PCI230P2_DAC_TRIG_NONE | PCI230P2_DAC_INT_FIFO_NHALF;
}
outw(daccon, dev->iobase + PCI230_DACCON);
devpriv->daccon = daccon
& ~(PCI230P2_DAC_FIFO_RESET | PCI230P2_DAC_FIFO_UNDERRUN_CLEAR);
if (cmd->scan_begin_src == TRIG_TIMER) {
outb(GAT_CONFIG(1, GAT_GND),
devpriv->iobase1 + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 1, I8254_MODE3,
cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
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
if ((min_scan_period < chanlist_len)
|| (min_scan_period < cmd->convert_arg)) {
min_scan_period = UINT_MAX;
err++;
}
if (cmd->scan_begin_arg < min_scan_period) {
cmd->scan_begin_arg = min_scan_period;
err++;
}
return !err;
}
static int pci230_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci230_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
tmp = TRIG_FOLLOW | TRIG_TIMER | TRIG_INT;
if ((thisboard->have_dio) || (thisboard->min_hwver > 0)) {
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
if ((cmd->scan_begin_src != TRIG_FOLLOW)
&& (cmd->convert_src != TRIG_TIMER))
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
if (cmd->chanlist && (cmd->chanlist_len > 0)) {
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
if ((cmd->convert_arg & CR_FLAGS_MASK) != 0) {
if ((cmd->convert_arg & ~CR_FLAGS_MASK) != 0) {
cmd->convert_arg = COMBINE(cmd->convert_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->convert_arg & (CR_FLAGS_MASK & ~CR_INVERT))
!= CR_EDGE) {
cmd->convert_arg = COMBINE(cmd->start_arg,
(CR_EDGE | 0),
CR_FLAGS_MASK &
~CR_INVERT);
err |= -EINVAL;
}
} else {
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, 1);
}
} else {
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_NONE)
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (cmd->scan_begin_src == TRIG_EXT) {
if ((cmd->scan_begin_arg & ~CR_FLAGS_MASK) != 0) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->scan_begin_arg & CR_FLAGS_MASK & ~CR_EDGE) != 0) {
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
pci230_ns_to_single_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
pci230_ns_to_single_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (!pci230_ai_check_scan_period(cmd)) {
pci230_ns_to_single_timer(&cmd->scan_begin_arg,
TRIG_ROUND_UP);
pci230_ai_check_scan_period(cmd);
}
if (tmp != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0) {
enum {
seq_err = 1 << 0,
rangepair_err = 1 << 1,
polarity_err = 1 << 2,
aref_err = 1 << 3,
diffchan_err = 1 << 4,
buggy_chan0_err = 1 << 5
};
unsigned int errors;
unsigned int chan, prev_chan;
unsigned int range, prev_range;
unsigned int polarity, prev_polarity;
unsigned int aref, prev_aref;
unsigned int subseq_len;
unsigned int n;
subseq_len = 0;
errors = 0;
prev_chan = prev_aref = prev_range = prev_polarity = 0;
for (n = 0; n < cmd->chanlist_len; n++) {
chan = CR_CHAN(cmd->chanlist[n]);
range = CR_RANGE(cmd->chanlist[n]);
aref = CR_AREF(cmd->chanlist[n]);
polarity = pci230_ai_bipolar[range];
if ((aref == AREF_DIFF)
&& (chan >= (s->n_chan / 2))) {
errors |= diffchan_err;
}
if (n > 0) {
if ((chan <= prev_chan)
&& (subseq_len == 0)) {
subseq_len = n;
}
if ((subseq_len > 0)
&& (cmd->chanlist[n] !=
cmd->chanlist[n % subseq_len])) {
errors |= seq_err;
}
if (aref != prev_aref)
errors |= aref_err;
if (polarity != prev_polarity)
errors |= polarity_err;
if ((aref != AREF_DIFF)
&& (((chan ^ prev_chan) & ~1) == 0)
&& (range != prev_range)) {
errors |= rangepair_err;
}
}
prev_chan = chan;
prev_range = range;
prev_aref = aref;
prev_polarity = polarity;
}
if (subseq_len == 0) {
subseq_len = n;
}
if ((n % subseq_len) != 0)
errors |= seq_err;
if ((devpriv->hwver > 0) && (devpriv->hwver < 4)) {
if ((subseq_len > 1)
&& (CR_CHAN(cmd->chanlist[0]) != 0)) {
errors |= buggy_chan0_err;
}
}
if (errors != 0) {
err++;
if ((errors & seq_err) != 0) {
dev_dbg(dev->class_dev,
"%s: channel numbers must increase or sequence must repeat exactly\n",
__func__);
}
if ((errors & rangepair_err) != 0) {
dev_dbg(dev->class_dev,
"%s: single-ended channel pairs must have the same range\n",
__func__);
}
if ((errors & polarity_err) != 0) {
dev_dbg(dev->class_dev,
"%s: channel sequence ranges must be all bipolar or all unipolar\n",
__func__);
}
if ((errors & aref_err) != 0) {
dev_dbg(dev->class_dev,
"%s: channel sequence analogue references must be all the same (single-ended or differential)\n",
__func__);
}
if ((errors & diffchan_err) != 0) {
dev_dbg(dev->class_dev,
"%s: differential channel number out of range 0 to %u\n",
__func__, (s->n_chan / 2) - 1);
}
if ((errors & buggy_chan0_err) != 0) {
dev_info(dev->class_dev,
"amplc_pci230: ai_cmdtest: Buggy PCI230+/260+ h/w version %u requires first channel of multi-channel sequence to be 0 (corrected in h/w version 4)\n",
devpriv->hwver);
}
}
}
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
if ((cmd->flags & TRIG_WAKE_EOS) != 0) {
wake = scanlen - devpriv->ai_scan_pos;
} else {
if (devpriv->ai_continuous
|| (devpriv->ai_scan_count >= PCI230_ADC_FIFOLEVEL_HALFFULL)
|| (scanlen >= PCI230_ADC_FIFOLEVEL_HALFFULL)) {
wake = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else {
wake = (devpriv->ai_scan_count * scanlen)
- devpriv->ai_scan_pos;
}
}
if (wake >= PCI230_ADC_FIFOLEVEL_HALFFULL) {
triglev = PCI230_ADC_INT_FIFO_HALF;
} else {
if ((wake > 1) && (devpriv->hwver > 0)) {
if (devpriv->adcfifothresh != wake) {
devpriv->adcfifothresh = wake;
outw(wake, dev->iobase + PCI230P_ADCFFTH);
}
triglev = PCI230P_ADC_INT_FIFO_THRESH;
} else {
triglev = PCI230_ADC_INT_FIFO_NEMPTY;
}
}
adccon = (devpriv->adccon & ~PCI230_ADC_INT_FIFO_MASK) | triglev;
if (adccon != devpriv->adccon) {
devpriv->adccon = adccon;
outw(adccon, dev->iobase + PCI230_ADCCON);
}
}
static int pci230_ai_inttrig_convert(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
if (trig_num != 0)
return -EINVAL;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
if (test_bit(AI_CMD_STARTED, &devpriv->state)) {
unsigned int delayus;
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2,
I8254_MODE0);
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2,
I8254_MODE1);
if (((devpriv->adccon & PCI230_ADC_IM_MASK)
== PCI230_ADC_IM_DIF)
&& (devpriv->hwver == 0)) {
delayus = 8;
} else {
delayus = 4;
}
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
udelay(delayus);
} else {
spin_unlock_irqrestore(&devpriv->ai_stop_spinlock, irqflags);
}
return 1;
}
static int pci230_ai_inttrig_scan_begin(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned char zgat;
if (trig_num != 0)
return -EINVAL;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
if (test_bit(AI_CMD_STARTED, &devpriv->state)) {
zgat = GAT_CONFIG(0, GAT_GND);
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
zgat = GAT_CONFIG(0, GAT_VCC);
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
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
int started;
spin_lock_irqsave(&devpriv->ai_stop_spinlock, irqflags);
started = test_and_clear_bit(AI_CMD_STARTED, &devpriv->state);
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
devpriv->int_en &= ~PCI230_INT_ADC;
while (devpriv->intr_running && devpriv->intr_cpuid != THISCPU) {
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
}
if (devpriv->ier != devpriv->int_en) {
devpriv->ier = devpriv->int_en;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
}
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
devpriv->adccon = (devpriv->adccon & (PCI230_ADC_IR_MASK
| PCI230_ADC_IM_MASK)) |
PCI230_ADC_TRIG_NONE;
outw(devpriv->adccon | PCI230_ADC_FIFO_RESET,
dev->iobase + PCI230_ADCCON);
put_all_resources(dev, OWNER_AICMD);
}
static void pci230_ai_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned long irqflags;
unsigned short conv;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
set_bit(AI_CMD_STARTED, &devpriv->state);
if (!devpriv->ai_continuous && (devpriv->ai_scan_count == 0)) {
async->events |= COMEDI_CB_EOA;
pci230_ai_stop(dev, s);
comedi_event(dev, s);
} else {
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
devpriv->int_en |= PCI230_INT_ADC;
devpriv->ier |= PCI230_INT_ADC;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
switch (cmd->convert_src) {
default:
conv = PCI230_ADC_TRIG_NONE;
break;
case TRIG_TIMER:
conv = PCI230_ADC_TRIG_Z2CT2;
break;
case TRIG_EXT:
if ((cmd->convert_arg & CR_EDGE) != 0) {
if ((cmd->convert_arg & CR_INVERT) == 0) {
conv = PCI230_ADC_TRIG_EXTP;
} else {
conv = PCI230_ADC_TRIG_EXTN;
}
} else {
if (cmd->convert_arg != 0) {
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
devpriv->adccon = (devpriv->adccon & ~PCI230_ADC_TRIG_MASK)
| conv;
outw(devpriv->adccon, dev->iobase + PCI230_ADCCON);
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
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
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
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
zgat = GAT_CONFIG(1, GAT_VCC);
outb(zgat, devpriv->iobase1
+ PCI230_ZGAT_SCE);
break;
case TRIG_INT:
async->inttrig =
pci230_ai_inttrig_scan_begin;
break;
}
}
} else if (cmd->convert_src != TRIG_INT) {
put_one_resource(dev, RES_Z2CT2, OWNER_AICMD);
}
}
}
static int pci230_ai_inttrig_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
if (trig_num != 0)
return -EINVAL;
s->async->inttrig = NULL;
pci230_ai_start(dev, s);
return 1;
}
static void pci230_handle_ai(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci230_private *devpriv = dev->private;
unsigned int events = 0;
unsigned int status_fifo;
unsigned int i;
unsigned int todo;
unsigned int fifoamount;
struct comedi_async *async = s->async;
unsigned int scanlen = async->cmd.scan_end_arg;
if (devpriv->ai_continuous) {
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else if (devpriv->ai_scan_count == 0) {
todo = 0;
} else if ((devpriv->ai_scan_count > PCI230_ADC_FIFOLEVEL_HALFFULL)
|| (scanlen > PCI230_ADC_FIFOLEVEL_HALFFULL)) {
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else {
todo = (devpriv->ai_scan_count * scanlen)
- devpriv->ai_scan_pos;
if (todo > PCI230_ADC_FIFOLEVEL_HALFFULL)
todo = PCI230_ADC_FIFOLEVEL_HALFFULL;
}
if (todo == 0)
return;
fifoamount = 0;
for (i = 0; i < todo; i++) {
if (fifoamount == 0) {
status_fifo = inw(dev->iobase + PCI230_ADCCON);
if ((status_fifo & PCI230_ADC_FIFO_FULL_LATCHED) != 0) {
comedi_error(dev, "AI FIFO overrun");
events |= COMEDI_CB_OVERFLOW | COMEDI_CB_ERROR;
break;
} else if ((status_fifo & PCI230_ADC_FIFO_EMPTY) != 0) {
break;
} else if ((status_fifo & PCI230_ADC_FIFO_HALF) != 0) {
fifoamount = PCI230_ADC_FIFOLEVEL_HALFFULL;
} else {
if (devpriv->hwver > 0) {
fifoamount = inw(dev->iobase
+ PCI230P_ADCFFLEV);
if (fifoamount == 0) {
break;
}
} else {
fifoamount = 1;
}
}
}
if (comedi_buf_put(async, pci230_ai_read(dev)) == 0) {
events |= COMEDI_CB_ERROR | COMEDI_CB_OVERFLOW;
comedi_error(dev, "AI buffer overflow");
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
if (!devpriv->ai_continuous && (devpriv->ai_scan_count == 0)) {
events |= COMEDI_CB_EOA;
} else {
events |= COMEDI_CB_BLOCK;
}
async->events |= events;
if ((async->events & (COMEDI_CB_EOA | COMEDI_CB_ERROR |
COMEDI_CB_OVERFLOW)) != 0) {
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
res_mask |= (1U << RES_Z2CT2);
if (cmd->scan_begin_src != TRIG_FOLLOW) {
res_mask |= (1U << RES_Z2CT0);
if (cmd->scan_begin_src == TRIG_TIMER) {
res_mask |= (1U << RES_Z2CT1);
}
}
if (!get_resources(dev, res_mask, OWNER_AICMD))
return -EBUSY;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ai_scan_count = cmd->stop_arg;
devpriv->ai_continuous = 0;
} else {
devpriv->ai_scan_count = 0;
devpriv->ai_continuous = 1;
}
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
devpriv->ai_bipolar = pci230_ai_bipolar[range];
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
gainshift = (chan & ~1);
adcen |= 1 << chan;
}
devpriv->adcg = (devpriv->adcg & ~(3 << gainshift))
| (pci230_ai_gain[range] << gainshift);
}
outw(adcen, dev->iobase + PCI230_ADCEN);
outw(devpriv->adcg, dev->iobase + PCI230_ADCG);
i8254_set_mode(devpriv->iobase1 + PCI230_Z2_CT_BASE, 0, 2, I8254_MODE1);
adccon |= PCI230_ADC_INT_FIFO_FULL | PCI230_ADC_TRIG_Z2CT2;
devpriv->adccon = adccon;
outw(adccon | PCI230_ADC_FIFO_RESET, dev->iobase + PCI230_ADCCON);
udelay(25);
outw(adccon | PCI230_ADC_FIFO_RESET, dev->iobase + PCI230_ADCCON);
if (cmd->convert_src == TRIG_TIMER) {
zgat = GAT_CONFIG(2, GAT_GND);
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 2, I8254_MODE3, cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (cmd->scan_begin_src != TRIG_FOLLOW) {
zgat = GAT_CONFIG(0, GAT_VCC);
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 0, I8254_MODE1,
((uint64_t) cmd->convert_arg
* cmd->scan_end_arg),
TRIG_ROUND_UP);
if (cmd->scan_begin_src == TRIG_TIMER) {
zgat = GAT_CONFIG(1, GAT_GND);
outb(zgat, devpriv->iobase1 + PCI230_ZGAT_SCE);
pci230_ct_setup_ns_mode(dev, 1, I8254_MODE3,
cmd->scan_begin_arg,
cmd->
flags &
TRIG_ROUND_MASK);
}
}
}
if (cmd->start_src == TRIG_INT) {
s->async->inttrig = pci230_ai_inttrig_start;
} else {
pci230_ai_start(dev, s);
}
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
unsigned char status_int, valid_status_int;
struct comedi_device *dev = (struct comedi_device *)d;
struct pci230_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned long irqflags;
status_int = inb(devpriv->iobase1 + PCI230_INT_STAT);
if (status_int == PCI230_INT_DISABLE)
return IRQ_NONE;
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
valid_status_int = devpriv->int_en & status_int;
devpriv->ier = devpriv->int_en & ~status_int;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
devpriv->intr_running = 1;
devpriv->intr_cpuid = THISCPU;
spin_unlock_irqrestore(&devpriv->isr_spinlock, irqflags);
if ((valid_status_int & PCI230_INT_ZCLK_CT1) != 0) {
s = dev->write_subdev;
pci230_handle_ao_nofifo(dev, s);
comedi_event(dev, s);
}
if ((valid_status_int & PCI230P2_INT_DAC) != 0) {
s = dev->write_subdev;
pci230_handle_ao_fifo(dev, s);
comedi_event(dev, s);
}
if ((valid_status_int & PCI230_INT_ADC) != 0) {
s = dev->read_subdev;
pci230_handle_ai(dev, s);
comedi_event(dev, s);
}
spin_lock_irqsave(&devpriv->isr_spinlock, irqflags);
if (devpriv->ier != devpriv->int_en) {
devpriv->ier = devpriv->int_en;
outb(devpriv->ier, devpriv->iobase1 + PCI230_INT_SCE);
}
devpriv->intr_running = 0;
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
static struct pci_dev *pci230_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci_dev *pci_dev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pci_dev) {
if (pci_dev->vendor != PCI_VENDOR_ID_AMPLICON)
continue;
if ((bus || slot) &&
(bus != pci_dev->bus->number ||
slot != PCI_SLOT(pci_dev->devfn)))
continue;
if (thisboard->id == PCI_DEVICE_ID_INVALID) {
const struct pci230_board *foundboard;
foundboard = pci230_find_pci_board(pci_dev);
if (foundboard == NULL)
continue;
dev->board_ptr = foundboard;
} else {
if (!pci230_match_pci_board(thisboard, pci_dev))
continue;
}
return pci_dev;
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pci230_alloc_private(struct comedi_device *dev)
{
struct pci230_private *devpriv;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->isr_spinlock);
spin_lock_init(&devpriv->res_spinlock);
spin_lock_init(&devpriv->ai_stop_spinlock);
spin_lock_init(&devpriv->ao_stop_spinlock);
return 0;
}
static int pci230_attach_common(struct comedi_device *dev,
struct pci_dev *pci_dev)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci230_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned long iobase1, iobase2;
int rc;
comedi_set_hw_dev(dev, &pci_dev->dev);
dev->board_name = thisboard->name;
rc = comedi_pci_enable(dev);
if (rc)
return rc;
iobase1 = pci_resource_start(pci_dev, 2);
iobase2 = pci_resource_start(pci_dev, 3);
dev_dbg(dev->class_dev,
"%s I/O region 1 0x%04lx I/O region 2 0x%04lx\n",
dev->board_name, iobase1, iobase2);
devpriv->iobase1 = iobase1;
dev->iobase = iobase2;
devpriv->daccon = inw(dev->iobase + PCI230_DACCON) & PCI230_DAC_OR_MASK;
if (pci_resource_len(pci_dev, 3) >= 32) {
unsigned short extfunc = 0;
devpriv->hwver = inw(dev->iobase + PCI230P_HWVER);
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
if ((thisboard->ao_chans > 0)
&& (devpriv->hwver >= 2)) {
extfunc |= PCI230P2_EXTFUNC_DACFIFO;
}
}
outw(extfunc, dev->iobase + PCI230P_EXTFUNC);
if ((extfunc & PCI230P2_EXTFUNC_DACFIFO) != 0) {
outw(devpriv->daccon | PCI230P2_DAC_FIFO_EN
| PCI230P2_DAC_FIFO_RESET,
dev->iobase + PCI230_DACCON);
outw(0, dev->iobase + PCI230P2_DACEN);
outw(devpriv->daccon, dev->iobase + PCI230_DACCON);
}
}
outb(0, devpriv->iobase1 + PCI230_INT_SCE);
devpriv->adcg = 0;
devpriv->adccon = PCI230_ADC_TRIG_NONE | PCI230_ADC_IM_SE
| PCI230_ADC_IR_BIP;
outw(1 << 0, dev->iobase + PCI230_ADCEN);
outw(devpriv->adcg, dev->iobase + PCI230_ADCG);
outw(devpriv->adccon | PCI230_ADC_FIFO_RESET,
dev->iobase + PCI230_ADCCON);
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
s->n_chan = thisboard->ai_chans;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &pci230_ai_range;
s->insn_read = &pci230_ai_rinsn;
s->len_chanlist = 256;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmd = &pci230_ai_cmd;
s->do_cmdtest = &pci230_ai_cmdtest;
s->cancel = pci230_ai_cancel;
}
s = &dev->subdevices[1];
if (thisboard->ao_chans > 0) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = thisboard->ao_chans;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = &pci230_ao_range;
s->insn_write = &pci230_ao_winsn;
s->insn_read = &pci230_ao_rinsn;
s->len_chanlist = thisboard->ao_chans;
if (dev->irq) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->do_cmd = &pci230_ao_cmd;
s->do_cmdtest = &pci230_ao_cmdtest;
s->cancel = pci230_ao_cancel;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (thisboard->have_dio) {
rc = subdev_8255_init(dev, s, NULL,
(devpriv->iobase1 + PCI230_PPI_X_BASE));
if (rc < 0)
return rc;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
dev_info(dev->class_dev, "attached\n");
return 1;
}
static int pci230_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pci230_board *thisboard = comedi_board(dev);
struct pci_dev *pci_dev;
int rc;
dev_info(dev->class_dev, "amplc_pci230: attach %s %d,%d\n",
thisboard->name, it->options[0], it->options[1]);
rc = pci230_alloc_private(dev);
if (rc)
return rc;
pci_dev = pci230_find_pci_dev(dev, it);
if (!pci_dev)
return -EIO;
return pci230_attach_common(dev, pci_dev);
}
static int pci230_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
int rc;
dev_info(dev->class_dev, "amplc_pci230: attach pci %s\n",
pci_name(pci_dev));
rc = pci230_alloc_private(dev);
if (rc)
return rc;
dev->board_ptr = pci230_find_pci_board(pci_dev);
if (dev->board_ptr == NULL) {
dev_err(dev->class_dev,
"amplc_pci230: BUG! cannot determine board type!\n");
return -EINVAL;
}
pci_dev_get(pci_dev);
return pci230_attach_common(dev, pci_dev);
}
static void pci230_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->irq)
free_irq(dev->irq, dev);
comedi_pci_disable(dev);
if (pcidev)
pci_dev_put(pcidev);
}
static int amplc_pci230_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &amplc_pci230_driver,
id->driver_data);
}
