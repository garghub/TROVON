static inline uint16_t munge_bipolar_sample(const struct comedi_device *dev,
uint16_t sample)
{
const struct das1800_board *thisboard = dev->board_ptr;
sample += 1 << (thisboard->resolution - 1);
return sample;
}
static void munge_data(struct comedi_device *dev, uint16_t *array,
unsigned int num_elements)
{
unsigned int i;
int unipolar;
unipolar = inb(dev->iobase + DAS1800_CONTROL_C) & UB;
if (!unipolar) {
for (i = 0; i < num_elements; i++)
array[i] = munge_bipolar_sample(dev, array[i]);
}
}
static void das1800_handle_fifo_half_full(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
unsigned int nsamples = comedi_nsamples_left(s, FIFO_SIZE / 2);
insw(dev->iobase + DAS1800_FIFO, devpriv->fifo_buf, nsamples);
munge_data(dev, devpriv->fifo_buf, nsamples);
comedi_buf_write_samples(s, devpriv->fifo_buf, nsamples);
}
static void das1800_handle_fifo_not_empty(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned short dpnt;
int unipolar;
unipolar = inb(dev->iobase + DAS1800_CONTROL_C) & UB;
while (inb(dev->iobase + DAS1800_STATUS) & FNE) {
dpnt = inw(dev->iobase + DAS1800_FIFO);
dpnt = munge_bipolar_sample(dev, dpnt);
comedi_buf_write_samples(s, &dpnt, 1);
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg)
break;
}
}
static void das1800_flush_dma_channel(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_isadma_desc *desc)
{
unsigned int residue = comedi_isadma_disable(desc->chan);
unsigned int nbytes = desc->size - residue;
unsigned int nsamples;
nsamples = comedi_bytes_to_samples(s, nbytes);
nsamples = comedi_nsamples_left(s, nsamples);
munge_data(dev, desc->virt_addr, nsamples);
comedi_buf_write_samples(s, desc->virt_addr, nsamples);
}
static void das1800_flush_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
const int dual_dma = devpriv->irq_dma_bits & DMA_DUAL;
das1800_flush_dma_channel(dev, s, desc);
if (dual_dma) {
dma->cur_dma = 1 - dma->cur_dma;
desc = &dma->desc[dma->cur_dma];
das1800_flush_dma_channel(dev, s, desc);
}
das1800_handle_fifo_not_empty(dev, s);
}
static void das1800_handle_dma(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int status)
{
struct das1800_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
const int dual_dma = devpriv->irq_dma_bits & DMA_DUAL;
das1800_flush_dma_channel(dev, s, desc);
comedi_isadma_program(desc);
if (status & DMATC) {
outb(CLEAR_INTR_MASK & ~DMATC, dev->iobase + DAS1800_STATUS);
if (dual_dma)
dma->cur_dma = 1 - dma->cur_dma;
}
}
static int das1800_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc;
int i;
outb(0x0, dev->iobase + DAS1800_STATUS);
outb(0x0, dev->iobase + DAS1800_CONTROL_B);
outb(0x0, dev->iobase + DAS1800_CONTROL_A);
for (i = 0; i < 2; i++) {
desc = &dma->desc[i];
if (desc->chan)
comedi_isadma_disable(desc->chan);
}
return 0;
}
static void das1800_ai_handler(struct comedi_device *dev)
{
struct das1800_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status = inb(dev->iobase + DAS1800_STATUS);
outb(ADC, dev->iobase + DAS1800_SELECT);
if (devpriv->irq_dma_bits & DMA_ENABLED) {
das1800_handle_dma(dev, s, status);
} else if (status & FHF) {
das1800_handle_fifo_half_full(dev, s);
} else if (status & FNE) {
das1800_handle_fifo_not_empty(dev, s);
}
if (status & OVF) {
outb(CLEAR_INTR_MASK & ~OVF, dev->iobase + DAS1800_STATUS);
dev_err(dev->class_dev, "FIFO overflow\n");
async->events |= COMEDI_CB_ERROR;
comedi_handle_events(dev, s);
return;
}
if (status & CT0TC) {
outb(CLEAR_INTR_MASK & ~CT0TC, dev->iobase + DAS1800_STATUS);
if (devpriv->irq_dma_bits & DMA_ENABLED)
das1800_flush_dma(dev, s);
else
das1800_handle_fifo_not_empty(dev, s);
async->events |= COMEDI_CB_EOA;
} else if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
}
comedi_handle_events(dev, s);
}
static int das1800_ai_poll(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
das1800_ai_handler(dev);
spin_unlock_irqrestore(&dev->spinlock, flags);
return comedi_buf_n_bytes_ready(s);
}
static irqreturn_t das1800_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
unsigned int status;
if (!dev->attached) {
dev_err(dev->class_dev, "premature interrupt\n");
return IRQ_HANDLED;
}
spin_lock(&dev->spinlock);
status = inb(dev->iobase + DAS1800_STATUS);
if (!(status & INT)) {
spin_unlock(&dev->spinlock);
return IRQ_NONE;
}
outb(CLEAR_INTR_MASK & ~INT, dev->iobase + DAS1800_STATUS);
das1800_ai_handler(dev);
spin_unlock(&dev->spinlock);
return IRQ_HANDLED;
}
static unsigned int burst_convert_arg(unsigned int convert_arg, int flags)
{
unsigned int micro_sec;
if (convert_arg > 64000)
convert_arg = 64000;
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
micro_sec = (convert_arg + 500) / 1000;
break;
case CMDF_ROUND_DOWN:
micro_sec = convert_arg / 1000;
break;
case CMDF_ROUND_UP:
micro_sec = (convert_arg - 1) / 1000 + 1;
break;
}
return micro_sec * 1000;
}
static int das1800_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int unipolar0 = CR_RANGE(cmd->chanlist[0]) & UNIPOLAR;
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int unipolar = CR_RANGE(cmd->chanlist[i]) & UNIPOLAR;
if (unipolar != unipolar0) {
dev_dbg(dev->class_dev,
"unipolar and bipolar ranges cannot be mixed in the chanlist\n");
return -EINVAL;
}
}
return 0;
}
static int das1800_ai_do_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct das1800_board *thisboard = dev->board_ptr;
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src,
TRIG_COUNT | TRIG_EXT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src != TRIG_FOLLOW &&
cmd->convert_src != TRIG_TIMER)
err |= -EINVAL;
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->convert_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
thisboard->ai_speed);
}
err |= comedi_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_COUNT:
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
break;
case TRIG_NONE:
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_FOLLOW &&
cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
} else if (cmd->convert_src == TRIG_TIMER) {
arg = burst_convert_arg(cmd->convert_arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->chanlist_len;
err |= comedi_check_trigger_arg_max(&cmd->
scan_begin_arg,
arg);
arg = cmd->scan_begin_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg,
cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg,
arg);
}
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= das1800_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int control_a_bits(const struct comedi_cmd *cmd)
{
int control_a;
control_a = FFEN;
if (cmd->stop_src == TRIG_EXT)
control_a |= ATEN;
switch (cmd->start_src) {
case TRIG_EXT:
control_a |= TGEN | CGSL;
break;
case TRIG_NOW:
control_a |= CGEN;
break;
default:
break;
}
return control_a;
}
static int control_c_bits(const struct comedi_cmd *cmd)
{
int control_c;
int aref;
aref = CR_AREF(cmd->chanlist[0]);
control_c = UQEN;
if (aref != AREF_DIFF)
control_c |= SD;
if (aref == AREF_COMMON)
control_c |= CMEN;
if (CR_RANGE(cmd->chanlist[0]) & UNIPOLAR)
control_c |= UB;
switch (cmd->scan_begin_src) {
case TRIG_FOLLOW:
switch (cmd->convert_src) {
case TRIG_TIMER:
control_c |= IPCLK;
break;
case TRIG_EXT:
control_c |= XPCLK;
break;
default:
break;
}
break;
case TRIG_TIMER:
control_c |= BMDE | IPCLK;
break;
case TRIG_EXT:
control_c |= BMDE | XPCLK;
break;
default:
break;
}
return control_c;
}
static unsigned int das1800_ai_transfer_size(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int maxbytes,
unsigned int ns)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int max_samples = comedi_bytes_to_samples(s, maxbytes);
unsigned int samples;
samples = max_samples;
switch (cmd->scan_begin_src) {
case TRIG_FOLLOW:
if (cmd->convert_src == TRIG_TIMER)
samples = ns / cmd->convert_arg;
break;
case TRIG_TIMER:
samples = ns / (cmd->scan_begin_arg * cmd->chanlist_len);
break;
}
samples = comedi_nsamples_left(s, samples);
if (samples > max_samples)
samples = max_samples;
if (samples < 1)
samples = 1;
return comedi_samples_to_bytes(s, samples);
}
static void das1800_ai_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[0];
unsigned int bytes;
if ((devpriv->irq_dma_bits & DMA_ENABLED) == 0)
return;
dma->cur_dma = 0;
bytes = das1800_ai_transfer_size(dev, s, desc->maxsize, 300000000);
desc->size = bytes;
comedi_isadma_program(desc);
if (devpriv->irq_dma_bits & DMA_DUAL) {
desc = &dma->desc[1];
desc->size = bytes;
comedi_isadma_program(desc);
}
}
static void program_chanlist(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
int i, n, chan_range;
unsigned long irq_flags;
const int range_mask = 0x3;
const int range_bitshift = 8;
n = cmd->chanlist_len;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(QRAM, dev->iobase + DAS1800_SELECT);
outb(n - 1, dev->iobase + DAS1800_QRAM_ADDRESS);
for (i = 0; i < n; i++) {
chan_range =
CR_CHAN(cmd->chanlist[i]) |
((CR_RANGE(cmd->chanlist[i]) & range_mask) <<
range_bitshift);
outw(chan_range, dev->iobase + DAS1800_QRAM);
}
outb(n - 1, dev->iobase + DAS1800_QRAM_ADDRESS);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
static int das1800_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
int control_a, control_c;
struct comedi_async *async = s->async;
const struct comedi_cmd *cmd = &async->cmd;
if (cmd->flags & (CMDF_WAKE_EOS | CMDF_PRIORITY))
devpriv->irq_dma_bits &= ~DMA_ENABLED;
else
devpriv->irq_dma_bits |= devpriv->dma_bits;
if (cmd->flags & CMDF_WAKE_EOS) {
devpriv->irq_dma_bits &= ~FIMD;
} else {
devpriv->irq_dma_bits |= FIMD;
}
das1800_cancel(dev, s);
control_a = control_a_bits(cmd);
control_c = control_c_bits(cmd);
program_chanlist(dev, cmd);
if ((cmd->scan_begin_src == TRIG_FOLLOW ||
cmd->scan_begin_src == TRIG_TIMER) &&
cmd->convert_src == TRIG_TIMER) {
comedi_8254_update_divisors(dev->pacer);
comedi_8254_pacer_enable(dev->pacer, 1, 2, true);
}
if (cmd->stop_src == TRIG_EXT)
comedi_8254_load(dev->pacer, 0, 1, I8254_MODE0 | I8254_BINARY);
das1800_ai_setup_dma(dev, s);
outb(control_c, dev->iobase + DAS1800_CONTROL_C);
if (control_c & BMDE) {
outb(cmd->convert_arg / 1000 - 1,
dev->iobase + DAS1800_BURST_RATE);
outb(cmd->chanlist_len - 1, dev->iobase + DAS1800_BURST_LENGTH);
}
outb(devpriv->irq_dma_bits, dev->iobase + DAS1800_CONTROL_B);
outb(control_a, dev->iobase + DAS1800_CONTROL_A);
outb(CVEN, dev->iobase + DAS1800_STATUS);
return 0;
}
static int das1800_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct das1800_board *thisboard = dev->board_ptr;
int i, n;
int chan, range, aref, chan_range;
int timeout = 1000;
unsigned short dpnt;
int conv_flags = 0;
unsigned long irq_flags;
aref = CR_AREF(insn->chanspec);
conv_flags |= UQEN;
if (aref != AREF_DIFF)
conv_flags |= SD;
if (aref == AREF_COMMON)
conv_flags |= CMEN;
if (CR_RANGE(insn->chanspec) & UNIPOLAR)
conv_flags |= UB;
outb(conv_flags, dev->iobase + DAS1800_CONTROL_C);
outb(CVEN, dev->iobase + DAS1800_STATUS);
outb(0x0, dev->iobase + DAS1800_CONTROL_A);
outb(FFEN, dev->iobase + DAS1800_CONTROL_A);
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec) & 0x3;
chan_range = chan | (range << 8);
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(QRAM, dev->iobase + DAS1800_SELECT);
outb(0x0, dev->iobase + DAS1800_QRAM_ADDRESS);
outw(chan_range, dev->iobase + DAS1800_QRAM);
outb(0x0, dev->iobase + DAS1800_QRAM_ADDRESS);
outb(ADC, dev->iobase + DAS1800_SELECT);
for (n = 0; n < insn->n; n++) {
outb(0, dev->iobase + DAS1800_FIFO);
for (i = 0; i < timeout; i++) {
if (inb(dev->iobase + DAS1800_STATUS) & FNE)
break;
}
if (i == timeout) {
dev_err(dev->class_dev, "timeout\n");
n = -ETIME;
goto exit;
}
dpnt = inw(dev->iobase + DAS1800_FIFO);
if ((conv_flags & UB) == 0)
dpnt += 1 << (thisboard->resolution - 1);
data[n] = dpnt;
}
exit:
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return n;
}
static int das1800_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct das1800_board *thisboard = dev->board_ptr;
struct das1800_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int update_chan = thisboard->ao_n_chan - 1;
unsigned short output;
unsigned long irq_flags;
output = data[0] - (1 << (thisboard->resolution - 1));
if (chan == update_chan)
devpriv->ao_update_bits = output;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(DAC(chan), dev->iobase + DAS1800_SELECT);
outw(output, dev->iobase + DAS1800_DAC);
if (chan != update_chan) {
outb(DAC(update_chan), dev->iobase + DAS1800_SELECT);
outw(devpriv->ao_update_bits, dev->iobase + DAS1800_DAC);
}
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return 1;
}
static int das1800_di_rbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + DAS1800_DIGITAL) & 0xf;
data[0] = 0;
return insn->n;
}
static int das1800_do_wbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS1800_DIGITAL);
data[1] = s->state;
return insn->n;
}
static void das1800_init_dma(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct das1800_private *devpriv = dev->private;
unsigned int *dma_chan;
dma_chan = &it->options[2];
switch ((dma_chan[0] & 0x7) | (dma_chan[1] << 4)) {
case 0x5:
devpriv->dma_bits = DMA_CH5;
break;
case 0x6:
devpriv->dma_bits = DMA_CH6;
break;
case 0x7:
devpriv->dma_bits = DMA_CH7;
break;
case 0x65:
devpriv->dma_bits = DMA_CH5_CH6;
break;
case 0x76:
devpriv->dma_bits = DMA_CH6_CH7;
break;
case 0x57:
devpriv->dma_bits = DMA_CH7_CH5;
break;
default:
return;
}
devpriv->dma = comedi_isadma_alloc(dev, dma_chan[1] ? 2 : 1,
dma_chan[0], dma_chan[1],
DMA_BUF_SIZE, COMEDI_ISADMA_READ);
if (!devpriv->dma)
devpriv->dma_bits = 0;
}
static void das1800_free_dma(struct comedi_device *dev)
{
struct das1800_private *devpriv = dev->private;
if (devpriv)
comedi_isadma_free(devpriv->dma);
}
static int das1800_probe(struct comedi_device *dev)
{
const struct das1800_board *board = dev->board_ptr;
int index;
int id;
index = board - das1800_boards;
id = (inb(dev->iobase + DAS1800_DIGITAL) >> 4) & 0xf;
switch (id) {
case 0x3:
if (index == das1801st_da || index == das1802st_da ||
index == das1701st_da || index == das1702st_da)
return index;
index = das1801st;
break;
case 0x4:
if (index == das1802hr_da || index == das1702hr_da)
return index;
index = das1802hr;
break;
case 0x5:
if (index == das1801ao || index == das1802ao ||
index == das1701ao || index == das1702ao)
return index;
index = das1801ao;
break;
case 0x6:
if (index == das1802hr || index == das1702hr)
return index;
index = das1802hr;
break;
case 0x7:
if (index == das1801st || index == das1802st ||
index == das1701st || index == das1702st)
return index;
index = das1801st;
break;
case 0x8:
if (index == das1801hc || index == das1802hc)
return index;
index = das1801hc;
break;
default:
dev_err(dev->class_dev,
"Board model: probe returned 0x%x (unknown, please report)\n",
id);
break;
}
dev_err(dev->class_dev,
"Board model (probed, not recommended): %s series\n",
das1800_boards[index].name);
return index;
}
static int das1800_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das1800_board *thisboard;
struct das1800_private *devpriv;
struct comedi_subdevice *s;
unsigned int irq = it->options[1];
int board;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], DAS1800_SIZE);
if (ret)
return ret;
board = das1800_probe(dev);
if (board < 0) {
dev_err(dev->class_dev, "unable to determine board type\n");
return -ENODEV;
}
dev->board_ptr = das1800_boards + board;
thisboard = dev->board_ptr;
dev->board_name = thisboard->name;
if (thisboard->ao_ability == 2) {
unsigned long iobase2 = dev->iobase + IOBASE2;
ret = __comedi_request_region(dev, iobase2, DAS1800_SIZE);
if (ret)
return ret;
devpriv->iobase2 = iobase2;
}
if (irq == 3 || irq == 5 || irq == 7 || irq == 10 || irq == 11 ||
irq == 15) {
ret = request_irq(irq, das1800_interrupt, 0,
dev->board_name, dev);
if (ret == 0) {
dev->irq = irq;
switch (irq) {
case 3:
devpriv->irq_dma_bits |= 0x8;
break;
case 5:
devpriv->irq_dma_bits |= 0x10;
break;
case 7:
devpriv->irq_dma_bits |= 0x18;
break;
case 10:
devpriv->irq_dma_bits |= 0x28;
break;
case 11:
devpriv->irq_dma_bits |= 0x30;
break;
case 15:
devpriv->irq_dma_bits |= 0x38;
break;
}
}
}
if (dev->irq & it->options[2])
das1800_init_dma(dev, it);
devpriv->fifo_buf = kmalloc_array(FIFO_SIZE, sizeof(uint16_t), GFP_KERNEL);
if (!devpriv->fifo_buf)
return -ENOMEM;
dev->pacer = comedi_8254_init(dev->iobase + DAS1800_COUNTER,
I8254_OSC_BASE_5MHZ, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF | SDF_GROUND;
if (thisboard->common)
s->subdev_flags |= SDF_COMMON;
s->n_chan = thisboard->qram_len;
s->maxdata = (1 << thisboard->resolution) - 1;
s->range_table = thisboard->range_ai;
s->insn_read = das1800_ai_rinsn;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmd = das1800_ai_do_cmd;
s->do_cmdtest = das1800_ai_do_cmdtest;
s->poll = das1800_ai_poll;
s->cancel = das1800_cancel;
}
s = &dev->subdevices[1];
if (thisboard->ao_ability == 1) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_n_chan;
s->maxdata = (1 << thisboard->resolution) - 1;
s->range_table = &range_bipolar10;
s->insn_write = das1800_ao_winsn;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das1800_di_rbits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->do_n_chan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das1800_do_wbits;
das1800_cancel(dev, dev->read_subdev);
outb(0, dev->iobase + DAS1800_DIGITAL);
if (thisboard->ao_ability == 1) {
outb(DAC(thisboard->ao_n_chan - 1),
dev->iobase + DAS1800_SELECT);
outw(devpriv->ao_update_bits, dev->iobase + DAS1800_DAC);
}
return 0;
}
static void das1800_detach(struct comedi_device *dev)
{
struct das1800_private *devpriv = dev->private;
das1800_free_dma(dev);
if (devpriv) {
kfree(devpriv->fifo_buf);
if (devpriv->iobase2)
release_region(devpriv->iobase2, DAS1800_SIZE);
}
comedi_legacy_detach(dev);
}
