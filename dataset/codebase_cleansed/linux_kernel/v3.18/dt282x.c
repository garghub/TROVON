static int dt282x_prep_ai_dma(struct comedi_device *dev, int dma_index, int n)
{
struct dt282x_private *devpriv = dev->private;
int dma_chan;
unsigned long dma_ptr;
unsigned long flags;
if (!devpriv->ntrig)
return 0;
if (n == 0)
n = devpriv->dma_maxsize;
if (n > devpriv->ntrig * 2)
n = devpriv->ntrig * 2;
devpriv->ntrig -= n / 2;
devpriv->dma[dma_index].size = n;
dma_chan = devpriv->dma[dma_index].chan;
dma_ptr = virt_to_bus(devpriv->dma[dma_index].buf);
set_dma_mode(dma_chan, DMA_MODE_READ);
flags = claim_dma_lock();
clear_dma_ff(dma_chan);
set_dma_addr(dma_chan, dma_ptr);
set_dma_count(dma_chan, n);
release_dma_lock(flags);
enable_dma(dma_chan);
return n;
}
static int dt282x_prep_ao_dma(struct comedi_device *dev, int dma_index, int n)
{
struct dt282x_private *devpriv = dev->private;
int dma_chan;
unsigned long dma_ptr;
unsigned long flags;
devpriv->dma[dma_index].size = n;
dma_chan = devpriv->dma[dma_index].chan;
dma_ptr = virt_to_bus(devpriv->dma[dma_index].buf);
set_dma_mode(dma_chan, DMA_MODE_WRITE);
flags = claim_dma_lock();
clear_dma_ff(dma_chan);
set_dma_addr(dma_chan, dma_ptr);
set_dma_count(dma_chan, n);
release_dma_lock(flags);
enable_dma(dma_chan);
return n;
}
static void dt282x_disable_dma(struct comedi_device *dev)
{
struct dt282x_private *devpriv = dev->private;
disable_dma(devpriv->dma[0].chan);
disable_dma(devpriv->dma[1].chan);
}
static unsigned int dt282x_ns_to_timer(unsigned int *ns, unsigned int flags)
{
unsigned int prescale, base, divider;
for (prescale = 0; prescale < 16; prescale++) {
if (prescale == 1)
continue;
base = 250 * (1 << prescale);
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
divider = (*ns + base / 2) / base;
break;
case CMDF_ROUND_DOWN:
divider = (*ns) / base;
break;
case CMDF_ROUND_UP:
divider = (*ns + base - 1) / base;
break;
}
if (divider < 256) {
*ns = divider * base;
return (prescale << 8) | (255 - divider);
}
}
base = 250 * (1 << 15);
divider = 255;
*ns = divider * base;
return (15 << 8) | (255 - divider);
}
static void dt282x_munge(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short *buf,
unsigned int nbytes)
{
struct dt282x_private *devpriv = dev->private;
unsigned int val;
int i;
if (nbytes % 2)
dev_err(dev->class_dev,
"bug! odd number of bytes from dma xfer\n");
for (i = 0; i < nbytes / 2; i++) {
val = buf[i];
val &= s->maxdata;
if (devpriv->ad_2scomp)
val = comedi_offset_munge(s, val);
buf[i] = val;
}
}
static void dt282x_ao_dma_interrupt(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
int cur_dma = devpriv->current_dma_index;
void *ptr = devpriv->dma[cur_dma].buf;
int size;
outw(devpriv->supcsr | DT2821_SUPCSR_CLRDMADNE,
dev->iobase + DT2821_SUPCSR_REG);
disable_dma(devpriv->dma[cur_dma].chan);
devpriv->current_dma_index = 1 - cur_dma;
size = cfc_read_array_from_buffer(s, ptr, devpriv->dma_maxsize);
if (size == 0) {
dev_err(dev->class_dev, "AO underrun\n");
s->async->events |= COMEDI_CB_OVERFLOW;
} else {
dt282x_prep_ao_dma(dev, cur_dma, size);
}
}
static void dt282x_ai_dma_interrupt(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
int cur_dma = devpriv->current_dma_index;
void *ptr = devpriv->dma[cur_dma].buf;
int size = devpriv->dma[cur_dma].size;
int ret;
outw(devpriv->supcsr | DT2821_SUPCSR_CLRDMADNE,
dev->iobase + DT2821_SUPCSR_REG);
disable_dma(devpriv->dma[cur_dma].chan);
devpriv->current_dma_index = 1 - cur_dma;
dt282x_munge(dev, s, ptr, size);
ret = cfc_write_array_to_buffer(s, ptr, size);
if (ret != size) {
s->async->events |= COMEDI_CB_OVERFLOW;
return;
}
devpriv->nread -= size / 2;
if (devpriv->nread < 0) {
dev_info(dev->class_dev, "nread off by one\n");
devpriv->nread = 0;
}
if (!devpriv->nread) {
s->async->events |= COMEDI_CB_EOA;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~DT2821_SUPCSR_DDMA;
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR_REG);
}
#endif
dt282x_prep_ai_dma(dev, cur_dma, 0);
}
static irqreturn_t dt282x_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct dt282x_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_subdevice *s_ao = dev->write_subdev;
unsigned int supcsr, adcsr, dacsr;
int handled = 0;
if (!dev->attached) {
dev_err(dev->class_dev, "spurious interrupt\n");
return IRQ_HANDLED;
}
adcsr = inw(dev->iobase + DT2821_ADCSR_REG);
dacsr = inw(dev->iobase + DT2821_DACSR_REG);
supcsr = inw(dev->iobase + DT2821_SUPCSR_REG);
if (supcsr & DT2821_SUPCSR_DMAD) {
if (devpriv->dma_dir == DMA_MODE_READ)
dt282x_ai_dma_interrupt(dev, s);
else
dt282x_ao_dma_interrupt(dev, s_ao);
handled = 1;
}
if (adcsr & DT2821_ADCSR_ADERR) {
if (devpriv->nread != 0) {
dev_err(dev->class_dev, "A/D error\n");
s->async->events |= COMEDI_CB_ERROR;
}
handled = 1;
}
if (dacsr & DT2821_DACSR_DAERR) {
dev_err(dev->class_dev, "D/A error\n");
s_ao->async->events |= COMEDI_CB_ERROR;
handled = 1;
}
#if 0
if (adcsr & DT2821_ADCSR_ADDONE) {
int ret;
unsigned short data;
data = inw(dev->iobase + DT2821_ADDAT_REG);
data &= s->maxdata;
if (devpriv->ad_2scomp)
data = comedi_offset_munge(s, data);
ret = comedi_buf_put(s, data);
if (ret == 0)
s->async->events |= COMEDI_CB_OVERFLOW;
devpriv->nread--;
if (!devpriv->nread) {
s->async->events |= COMEDI_CB_EOA;
} else {
if (supcsr & DT2821_SUPCSR_SCDN)
outw(devpriv->supcsr | DT2821_SUPCSR_STRIG,
dev->iobase + DT2821_SUPCSR_REG);
}
handled = 1;
}
#endif
cfc_handle_events(dev, s);
cfc_handle_events(dev, s_ao);
return IRQ_RETVAL(handled);
}
static void dt282x_load_changain(struct comedi_device *dev, int n,
unsigned int *chanlist)
{
struct dt282x_private *devpriv = dev->private;
int i;
outw(DT2821_CHANCSR_LLE | DT2821_CHANCSR_NUMB(n),
dev->iobase + DT2821_CHANCSR_REG);
for (i = 0; i < n; i++) {
unsigned int chan = CR_CHAN(chanlist[i]);
unsigned int range = CR_RANGE(chanlist[i]);
outw(devpriv->adcsr |
DT2821_ADCSR_GS(range) |
DT2821_ADCSR_CHAN(chan),
dev->iobase + DT2821_ADCSR_REG);
}
outw(DT2821_CHANCSR_NUMB(n), dev->iobase + DT2821_CHANCSR_REG);
}
static int dt282x_ai_timeout(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + DT2821_ADCSR_REG);
switch (context) {
case DT2821_ADCSR_MUXBUSY:
if ((status & DT2821_ADCSR_MUXBUSY) == 0)
return 0;
break;
case DT2821_ADCSR_ADDONE:
if (status & DT2821_ADCSR_ADDONE)
return 0;
break;
default:
return -EINVAL;
}
return -EBUSY;
}
static int dt282x_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dt282x_private *devpriv = dev->private;
unsigned int val;
int ret;
int i;
devpriv->adcsr = DT2821_ADCSR_ADCLK;
outw(devpriv->adcsr, dev->iobase + DT2821_ADCSR_REG);
dt282x_load_changain(dev, 1, &insn->chanspec);
outw(devpriv->supcsr | DT2821_SUPCSR_PRLD,
dev->iobase + DT2821_SUPCSR_REG);
ret = comedi_timeout(dev, s, insn,
dt282x_ai_timeout, DT2821_ADCSR_MUXBUSY);
if (ret)
return ret;
for (i = 0; i < insn->n; i++) {
outw(devpriv->supcsr | DT2821_SUPCSR_STRIG,
dev->iobase + DT2821_SUPCSR_REG);
ret = comedi_timeout(dev, s, insn,
dt282x_ai_timeout, DT2821_ADCSR_ADDONE);
if (ret)
return ret;
val = inw(dev->iobase + DT2821_ADDAT_REG);
val &= s->maxdata;
if (devpriv->ad_2scomp)
val = comedi_offset_munge(s, val);
data[i] = val;
}
return i;
}
static int dt282x_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct dt282x_board *board = dev->board_ptr;
struct dt282x_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW) {
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
} else {
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
}
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, 4000);
#define SLOWEST_TIMER (250*(1<<15)*255)
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, SLOWEST_TIMER);
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, board->ai_speed);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
arg = cmd->convert_arg;
devpriv->divisor = dt282x_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
if (err)
return 4;
return 0;
}
static int dt282x_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
dt282x_disable_dma(dev);
outw(devpriv->divisor, dev->iobase + DT2821_TMRCTR_REG);
devpriv->supcsr = DT2821_SUPCSR_ERRINTEN;
if (cmd->scan_begin_src == TRIG_FOLLOW)
devpriv->supcsr = DT2821_SUPCSR_DS_AD_CLK;
else
devpriv->supcsr = DT2821_SUPCSR_DS_AD_TRIG;
outw(devpriv->supcsr |
DT2821_SUPCSR_CLRDMADNE |
DT2821_SUPCSR_BUFFB |
DT2821_SUPCSR_ADCINIT,
dev->iobase + DT2821_SUPCSR_REG);
devpriv->ntrig = cmd->stop_arg * cmd->scan_end_arg;
devpriv->nread = devpriv->ntrig;
devpriv->dma_dir = DMA_MODE_READ;
devpriv->current_dma_index = 0;
dt282x_prep_ai_dma(dev, 0, 0);
if (devpriv->ntrig) {
dt282x_prep_ai_dma(dev, 1, 0);
devpriv->supcsr |= DT2821_SUPCSR_DDMA;
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR_REG);
}
devpriv->adcsr = 0;
dt282x_load_changain(dev, cmd->chanlist_len, cmd->chanlist);
devpriv->adcsr = DT2821_ADCSR_ADCLK | DT2821_ADCSR_IADDONE;
outw(devpriv->adcsr, dev->iobase + DT2821_ADCSR_REG);
outw(devpriv->supcsr | DT2821_SUPCSR_PRLD,
dev->iobase + DT2821_SUPCSR_REG);
ret = comedi_timeout(dev, s, NULL,
dt282x_ai_timeout, DT2821_ADCSR_MUXBUSY);
if (ret)
return ret;
if (cmd->scan_begin_src == TRIG_FOLLOW) {
outw(devpriv->supcsr | DT2821_SUPCSR_STRIG,
dev->iobase + DT2821_SUPCSR_REG);
} else {
devpriv->supcsr |= DT2821_SUPCSR_XTRIG;
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR_REG);
}
return 0;
}
static int dt282x_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
dt282x_disable_dma(dev);
devpriv->adcsr = 0;
outw(devpriv->adcsr, dev->iobase + DT2821_ADCSR_REG);
devpriv->supcsr = 0;
outw(devpriv->supcsr | DT2821_SUPCSR_ADCINIT,
dev->iobase + DT2821_SUPCSR_REG);
return 0;
}
static int dt282x_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dt282x_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int i;
devpriv->dacsr |= DT2821_DACSR_SSEL | DT2821_DACSR_YSEL(chan);
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
outw(devpriv->dacsr, dev->iobase + DT2821_DACSR_REG);
outw(val, dev->iobase + DT2821_DADAT_REG);
outw(devpriv->supcsr | DT2821_SUPCSR_DACON,
dev->iobase + DT2821_SUPCSR_REG);
}
return insn->n;
}
static int dt282x_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct dt282x_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg, 5000);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
arg = cmd->scan_begin_arg;
devpriv->divisor = dt282x_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
if (err)
return 4;
return 0;
}
static int dt282x_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct dt282x_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int size;
if (trig_num != cmd->start_src)
return -EINVAL;
size = cfc_read_array_from_buffer(s, devpriv->dma[0].buf,
devpriv->dma_maxsize);
if (size == 0) {
dev_err(dev->class_dev, "AO underrun\n");
return -EPIPE;
}
dt282x_prep_ao_dma(dev, 0, size);
size = cfc_read_array_from_buffer(s, devpriv->dma[1].buf,
devpriv->dma_maxsize);
if (size == 0) {
dev_err(dev->class_dev, "AO underrun\n");
return -EPIPE;
}
dt282x_prep_ao_dma(dev, 1, size);
outw(devpriv->supcsr | DT2821_SUPCSR_STRIG,
dev->iobase + DT2821_SUPCSR_REG);
s->async->inttrig = NULL;
return 1;
}
static int dt282x_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
dt282x_disable_dma(dev);
devpriv->supcsr = DT2821_SUPCSR_ERRINTEN |
DT2821_SUPCSR_DS_DA_CLK |
DT2821_SUPCSR_DDMA;
outw(devpriv->supcsr |
DT2821_SUPCSR_CLRDMADNE |
DT2821_SUPCSR_BUFFB |
DT2821_SUPCSR_DACINIT,
dev->iobase + DT2821_SUPCSR_REG);
devpriv->ntrig = cmd->stop_arg * cmd->chanlist_len;
devpriv->nread = devpriv->ntrig;
devpriv->dma_dir = DMA_MODE_WRITE;
devpriv->current_dma_index = 0;
outw(devpriv->divisor, dev->iobase + DT2821_TMRCTR_REG);
devpriv->dacsr &= (DT2821_DACSR_LBOE | DT2821_DACSR_HBOE);
devpriv->dacsr |= (DT2821_DACSR_SSEL |
DT2821_DACSR_DACLK |
DT2821_DACSR_IDARDY);
outw(devpriv->dacsr, dev->iobase + DT2821_DACSR_REG);
s->async->inttrig = dt282x_ao_inttrig;
return 0;
}
static int dt282x_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt282x_private *devpriv = dev->private;
dt282x_disable_dma(dev);
devpriv->dacsr &= (DT2821_DACSR_LBOE | DT2821_DACSR_HBOE);
outw(devpriv->dacsr, dev->iobase + DT2821_DACSR_REG);
devpriv->supcsr = 0;
outw(devpriv->supcsr | DT2821_SUPCSR_DACINIT,
dev->iobase + DT2821_SUPCSR_REG);
return 0;
}
static int dt282x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + DT2821_DIODAT_REG);
data[1] = inw(dev->iobase + DT2821_DIODAT_REG);
return insn->n;
}
static int dt282x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dt282x_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 8)
mask = 0x00ff;
else
mask = 0xff00;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
devpriv->dacsr &= ~(DT2821_DACSR_LBOE | DT2821_DACSR_HBOE);
if (s->io_bits & 0x00ff)
devpriv->dacsr |= DT2821_DACSR_LBOE;
if (s->io_bits & 0xff00)
devpriv->dacsr |= DT2821_DACSR_HBOE;
outw(devpriv->dacsr, dev->iobase + DT2821_DACSR_REG);
return insn->n;
}
static const struct comedi_lrange *opt_ai_range_lkup(int ispgl, int x)
{
if (ispgl) {
if (x < 0 || x >= 2)
x = 0;
return ai_range_pgl_table[x];
}
if (x < 0 || x >= 4)
x = 0;
return ai_range_table[x];
}
static int dt282x_grab_dma(struct comedi_device *dev, int dma1, int dma2)
{
struct dt282x_private *devpriv = dev->private;
int ret;
ret = request_dma(dma1, "dt282x A");
if (ret)
return -EBUSY;
devpriv->dma[0].chan = dma1;
ret = request_dma(dma2, "dt282x B");
if (ret)
return -EBUSY;
devpriv->dma[1].chan = dma2;
devpriv->dma_maxsize = PAGE_SIZE;
devpriv->dma[0].buf = (void *)__get_free_page(GFP_KERNEL | GFP_DMA);
devpriv->dma[1].buf = (void *)__get_free_page(GFP_KERNEL | GFP_DMA);
if (!devpriv->dma[0].buf || !devpriv->dma[1].buf)
return -ENOMEM;
return 0;
}
static void dt282x_free_dma(struct comedi_device *dev)
{
struct dt282x_private *devpriv = dev->private;
int i;
if (!devpriv)
return;
for (i = 0; i < 2; i++) {
if (devpriv->dma[i].chan)
free_dma(devpriv->dma[i].chan);
if (devpriv->dma[i].buf)
free_page((unsigned long)devpriv->dma[i].buf);
devpriv->dma[i].chan = 0;
devpriv->dma[i].buf = NULL;
}
}
static int dt282x_initialize(struct comedi_device *dev)
{
outw(DT2821_SUPCSR_BDINIT, dev->iobase + DT2821_SUPCSR_REG);
inw(dev->iobase + DT2821_ADCSR_REG);
if (((inw(dev->iobase + DT2821_ADCSR_REG) & 0xfff0) != 0x7c00) ||
((inw(dev->iobase + DT2821_CHANCSR_REG) & 0xf0f0) != 0x70f0) ||
((inw(dev->iobase + DT2821_DACSR_REG) & 0x7c93) != 0x7c90) ||
((inw(dev->iobase + DT2821_SUPCSR_REG) & 0xf8ff) != 0x0000) ||
((inw(dev->iobase + DT2821_TMRCTR_REG) & 0xff00) != 0xf000)) {
dev_err(dev->class_dev, "board not found\n");
return -EIO;
}
return 0;
}
static int dt282x_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dt282x_board *board = dev->board_ptr;
struct dt282x_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
ret = dt282x_initialize(dev);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
if (it->options[1] && it->options[2] && it->options[3]) {
unsigned int irq = it->options[1];
unsigned int dma1 = it->options[2];
unsigned int dma2 = it->options[3];
if (dma2 < dma1) {
unsigned int swap;
swap = dma1;
dma1 = dma2;
dma2 = swap;
}
if (dma1 != dma2 &&
dma1 >= 5 && dma1 <= 7 &&
dma2 >= 5 && dma2 <= 7) {
ret = request_irq(irq, dt282x_interrupt, 0,
dev->board_name, dev);
if (ret == 0) {
dev->irq = irq;
ret = dt282x_grab_dma(dev, dma1, dma2);
if (ret < 0) {
dt282x_free_dma(dev);
free_irq(dev->irq, dev);
dev->irq = 0;
}
}
}
}
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
if ((it->options[4] && board->adchan_di) || board->adchan_se == 0) {
s->subdev_flags |= SDF_DIFF;
s->n_chan = board->adchan_di;
} else {
s->subdev_flags |= SDF_COMMON;
s->n_chan = board->adchan_se;
}
s->maxdata = board->ai_maxdata;
s->range_table = opt_ai_range_lkup(board->ispgl, it->options[8]);
devpriv->ad_2scomp = it->options[5] ? 1 : 0;
s->insn_read = dt282x_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = dt282x_ai_cmdtest;
s->do_cmd = dt282x_ai_cmd;
s->cancel = dt282x_ai_cancel;
}
s = &dev->subdevices[1];
if (board->dachan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->dachan;
s->maxdata = board->ao_maxdata;
s->range_table = &dt282x_ao_range;
s->insn_write = dt282x_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
if (dev->irq) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->len_chanlist = s->n_chan;
s->do_cmdtest = dt282x_ao_cmdtest;
s->do_cmd = dt282x_ao_cmd;
s->cancel = dt282x_ao_cancel;
}
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dt282x_dio_insn_bits;
s->insn_config = dt282x_dio_insn_config;
return 0;
}
static void dt282x_detach(struct comedi_device *dev)
{
dt282x_free_dma(dev);
comedi_legacy_detach(dev);
}
