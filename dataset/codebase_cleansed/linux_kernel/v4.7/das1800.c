static void das1800_ai_munge(struct comedi_device *dev,
struct comedi_subdevice *s,
void *data, unsigned int num_bytes,
unsigned int start_chan_index)
{
struct das1800_private *devpriv = dev->private;
unsigned short *array = data;
unsigned int num_samples = comedi_bytes_to_samples(s, num_bytes);
unsigned int i;
if (devpriv->ai_is_unipolar)
return;
for (i = 0; i < num_samples; i++)
array[i] = comedi_offset_munge(s, array[i]);
}
static void das1800_handle_fifo_half_full(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
unsigned int nsamples = comedi_nsamples_left(s, FIFO_SIZE / 2);
insw(dev->iobase + DAS1800_FIFO, devpriv->fifo_buf, nsamples);
comedi_buf_write_samples(s, devpriv->fifo_buf, nsamples);
}
static void das1800_handle_fifo_not_empty(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned short dpnt;
while (inb(dev->iobase + DAS1800_STATUS) & FNE) {
dpnt = inw(dev->iobase + DAS1800_FIFO);
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
static int das1800_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc;
int i;
outb(0x0, dev->iobase + DAS1800_STATUS);
outb(0x0, dev->iobase + DAS1800_CONTROL_B);
outb(0x0, dev->iobase + DAS1800_CONTROL_A);
if (dma) {
for (i = 0; i < 2; i++) {
desc = &dma->desc[i];
if (desc->chan)
comedi_isadma_disable(desc->chan);
}
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
if (devpriv->irq_dma_bits & DMA_ENABLED)
das1800_handle_dma(dev, s, status);
else if (status & FHF)
das1800_handle_fifo_half_full(dev, s);
else if (status & FNE)
das1800_handle_fifo_not_empty(dev, s);
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
static int das1800_ai_fixup_paced_timing(struct comedi_device *dev,
struct comedi_cmd *cmd)
{
unsigned int arg = cmd->convert_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
return comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
}
static int das1800_ai_fixup_burst_timing(struct comedi_device *dev,
struct comedi_cmd *cmd)
{
unsigned int arg = cmd->convert_arg;
int err = 0;
err |= comedi_check_trigger_arg_max(&arg, 64000);
switch (cmd->flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
arg = DIV_ROUND_CLOSEST(arg, 1000);
break;
case CMDF_ROUND_DOWN:
arg = arg / 1000;
break;
case CMDF_ROUND_UP:
arg = DIV_ROUND_UP(arg, 1000);
break;
}
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg * 1000);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->chanlist_len;
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg, arg);
arg = cmd->scan_begin_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
return err;
}
static int das1800_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int range = CR_RANGE(cmd->chanlist[0]);
bool unipolar0 = comedi_range_is_unipolar(s, range);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
range = CR_RANGE(cmd->chanlist[i]);
if (unipolar0 != comedi_range_is_unipolar(s, range)) {
dev_dbg(dev->class_dev,
"unipolar and bipolar ranges cannot be mixed in the chanlist\n");
return -EINVAL;
}
}
return 0;
}
static int das1800_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct das1800_board *board = dev->board_ptr;
int err = 0;
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
if (cmd->start_src == TRIG_EXT && cmd->stop_src == TRIG_EXT)
err |= comedi_check_trigger_arg_is(&cmd->start_arg,
cmd->stop_arg);
if (err)
return 2;
if (cmd->start_arg == TRIG_NOW)
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->convert_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
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
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= das1800_ai_fixup_paced_timing(dev, cmd);
else
err |= das1800_ai_fixup_burst_timing(dev, cmd);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= das1800_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static unsigned char das1800_ai_chanspec_bits(struct comedi_subdevice *s,
unsigned int chanspec)
{
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
unsigned char bits;
bits = UQEN;
if (aref != AREF_DIFF)
bits |= SD;
if (aref == AREF_COMMON)
bits |= CMEN;
if (comedi_range_is_unipolar(s, range))
bits |= UB;
return bits;
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
struct comedi_isadma_desc *desc;
unsigned int bytes;
if ((devpriv->irq_dma_bits & DMA_ENABLED) == 0)
return;
dma->cur_dma = 0;
desc = &dma->desc[0];
bytes = das1800_ai_transfer_size(dev, s, desc->maxsize, 300000000);
desc->size = bytes;
comedi_isadma_program(desc);
if (devpriv->irq_dma_bits & DMA_DUAL) {
desc = &dma->desc[1];
desc->size = bytes;
comedi_isadma_program(desc);
}
}
static void das1800_ai_set_chanlist(struct comedi_device *dev,
unsigned int *chanlist, unsigned int len)
{
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&dev->spinlock, flags);
outb(QRAM, dev->iobase + DAS1800_SELECT);
outb(len - 1, dev->iobase + DAS1800_QRAM_ADDRESS);
for (i = 0; i < len; i++) {
unsigned int chan = CR_CHAN(chanlist[i]);
unsigned int range = CR_RANGE(chanlist[i]);
unsigned short val;
val = chan | ((range & 0x3) << 8);
outw(val, dev->iobase + DAS1800_QRAM);
}
outb(len - 1, dev->iobase + DAS1800_QRAM_ADDRESS);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static int das1800_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das1800_private *devpriv = dev->private;
int control_a, control_c;
struct comedi_async *async = s->async;
const struct comedi_cmd *cmd = &async->cmd;
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
if (cmd->flags & (CMDF_WAKE_EOS | CMDF_PRIORITY))
devpriv->irq_dma_bits &= ~DMA_ENABLED;
else
devpriv->irq_dma_bits |= devpriv->dma_bits;
if (cmd->flags & CMDF_WAKE_EOS) {
devpriv->irq_dma_bits &= ~FIMD;
} else {
devpriv->irq_dma_bits |= FIMD;
}
das1800_ai_cancel(dev, s);
devpriv->ai_is_unipolar = comedi_range_is_unipolar(s, range0);
control_a = FFEN;
if (cmd->stop_src == TRIG_EXT)
control_a |= ATEN;
if (cmd->start_src == TRIG_EXT)
control_a |= TGEN | CGSL;
else
control_a |= CGEN;
if (control_a & (ATEN | TGEN)) {
if ((cmd->start_arg & CR_INVERT) || (cmd->stop_arg & CR_INVERT))
control_a |= TGPL;
}
control_c = das1800_ai_chanspec_bits(s, cmd->chanlist[0]);
if (cmd->scan_begin_src == TRIG_FOLLOW) {
if (cmd->convert_src == TRIG_TIMER) {
control_c |= IPCLK;
} else {
control_c |= XPCLK;
}
} else if (cmd->scan_begin_src == TRIG_TIMER) {
control_c |= BMDE | IPCLK;
} else {
control_c |= BMDE | XPCLK;
}
das1800_ai_set_chanlist(dev, cmd->chanlist, cmd->chanlist_len);
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
static int das1800_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + DAS1800_STATUS);
if (status & FNE)
return 0;
return -EBUSY;
}
static int das1800_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int range = CR_RANGE(insn->chanspec);
bool is_unipolar = comedi_range_is_unipolar(s, range);
int ret = 0;
int n;
unsigned short dpnt;
unsigned long flags;
outb(das1800_ai_chanspec_bits(s, insn->chanspec),
dev->iobase + DAS1800_CONTROL_C);
outb(CVEN, dev->iobase + DAS1800_STATUS);
outb(0x0, dev->iobase + DAS1800_CONTROL_A);
outb(FFEN, dev->iobase + DAS1800_CONTROL_A);
das1800_ai_set_chanlist(dev, &insn->chanspec, 1);
spin_lock_irqsave(&dev->spinlock, flags);
outb(ADC, dev->iobase + DAS1800_SELECT);
for (n = 0; n < insn->n; n++) {
outb(0, dev->iobase + DAS1800_FIFO);
ret = comedi_timeout(dev, s, insn, das1800_ai_eoc, 0);
if (ret)
break;
dpnt = inw(dev->iobase + DAS1800_FIFO);
if (!is_unipolar)
dpnt = comedi_offset_munge(s, dpnt);
data[n] = dpnt;
}
spin_unlock_irqrestore(&dev->spinlock, flags);
return ret ? ret : insn->n;
}
static int das1800_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int update_chan = s->n_chan - 1;
unsigned long flags;
int i;
spin_lock_irqsave(&dev->spinlock, flags);
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
val = comedi_offset_munge(s, val);
outb(DAC(chan), dev->iobase + DAS1800_SELECT);
outw(val, dev->iobase + DAS1800_DAC);
if (chan != update_chan) {
val = comedi_offset_munge(s, s->readback[update_chan]);
outb(DAC(update_chan), dev->iobase + DAS1800_SELECT);
outw(val, dev->iobase + DAS1800_DAC);
}
}
spin_unlock_irqrestore(&dev->spinlock, flags);
return insn->n;
}
static int das1800_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + DAS1800_DIGITAL) & 0xf;
data[0] = 0;
return insn->n;
}
static int das1800_do_insn_bits(struct comedi_device *dev,
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
unsigned char id;
id = (inb(dev->iobase + DAS1800_DIGITAL) >> 4) & 0xf;
if (board) {
if (board->id == id)
return 0;
dev_err(dev->class_dev,
"probed id does not match board id (0x%x != 0x%x)\n",
id, board->id);
return -ENODEV;
}
switch (id) {
case DAS1800_ID_ST_DA:
board = &das1800_boards[BOARD_DAS1801ST_DA];
break;
case DAS1800_ID_HR_DA:
board = &das1800_boards[BOARD_DAS1802HR_DA];
break;
case DAS1800_ID_AO:
board = &das1800_boards[BOARD_DAS1801AO];
break;
case DAS1800_ID_HR:
board = &das1800_boards[BOARD_DAS1802HR];
break;
case DAS1800_ID_ST:
board = &das1800_boards[BOARD_DAS1801ST];
break;
case DAS1800_ID_HC:
board = &das1800_boards[BOARD_DAS1801HC];
break;
default:
dev_err(dev->class_dev, "invalid probe id 0x%x\n", id);
return -ENODEV;
}
dev->board_ptr = board;
dev->board_name = board->name;
dev_warn(dev->class_dev,
"probed id 0x%0x: %s series (not recommended)\n",
id, board->name);
return 0;
}
static int das1800_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das1800_board *board;
struct das1800_private *devpriv;
struct comedi_subdevice *s;
unsigned int irq = it->options[1];
bool is_16bit;
int ret;
int i;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], DAS1800_SIZE);
if (ret)
return ret;
ret = das1800_probe(dev);
if (ret)
return ret;
board = dev->board_ptr;
is_16bit = board->id == DAS1800_ID_HR || board->id == DAS1800_ID_HR_DA;
if (board->id == DAS1800_ID_AO) {
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
devpriv->fifo_buf = kmalloc_array(FIFO_SIZE,
sizeof(*devpriv->fifo_buf),
GFP_KERNEL);
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
if (board->id != DAS1800_ID_HC)
s->subdev_flags |= SDF_COMMON;
s->n_chan = (board->id == DAS1800_ID_HC) ? 64 : 256;
s->maxdata = is_16bit ? 0xffff : 0x0fff;
s->range_table = board->is_01_series ? &das1801_ai_range
: &das1802_ai_range;
s->insn_read = das1800_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmd = das1800_ai_cmd;
s->do_cmdtest = das1800_ai_cmdtest;
s->poll = das1800_ai_poll;
s->cancel = das1800_ai_cancel;
s->munge = das1800_ai_munge;
}
s = &dev->subdevices[1];
if (board->id == DAS1800_ID_ST_DA || board->id == DAS1800_ID_HR_DA) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = (board->id == DAS1800_ID_ST_DA) ? 4 : 2;
s->maxdata = is_16bit ? 0xffff : 0x0fff;
s->range_table = &range_bipolar10;
s->insn_write = das1800_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
outb(DAC(i), dev->iobase + DAS1800_SELECT);
outw(0, dev->iobase + DAS1800_DAC);
}
} else if (board->id == DAS1800_ID_AO) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das1800_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = (board->id == DAS1800_ID_HC) ? 8 : 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das1800_do_insn_bits;
das1800_ai_cancel(dev, dev->read_subdev);
outb(0, dev->iobase + DAS1800_DIGITAL);
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
