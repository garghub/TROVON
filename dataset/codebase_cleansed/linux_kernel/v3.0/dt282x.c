static int __init driver_dt282x_init_module(void)
{
return comedi_driver_register(&driver_dt282x);
}
static void __exit driver_dt282x_cleanup_module(void)
{
comedi_driver_unregister(&driver_dt282x);
}
static void dt282x_munge(struct comedi_device *dev, short *buf,
unsigned int nbytes)
{
unsigned int i;
unsigned short mask = (1 << boardtype.adbits) - 1;
unsigned short sign = 1 << (boardtype.adbits - 1);
int n;
if (devpriv->ad_2scomp)
sign = 1 << (boardtype.adbits - 1);
else
sign = 0;
if (nbytes % 2)
comedi_error(dev, "bug! odd number of bytes from dma xfer");
n = nbytes / 2;
for (i = 0; i < n; i++)
buf[i] = (buf[i] & mask) ^ sign;
}
static void dt282x_ao_dma_interrupt(struct comedi_device *dev)
{
void *ptr;
int size;
int i;
struct comedi_subdevice *s = dev->subdevices + 1;
update_supcsr(DT2821_CLRDMADNE);
if (!s->async->prealloc_buf) {
printk(KERN_ERR "async->data disappeared. dang!\n");
return;
}
i = devpriv->current_dma_index;
ptr = devpriv->dma[i].buf;
disable_dma(devpriv->dma[i].chan);
devpriv->current_dma_index = 1 - i;
size = cfc_read_array_from_buffer(s, ptr, devpriv->dma_maxsize);
if (size == 0) {
printk(KERN_ERR "dt282x: AO underrun\n");
dt282x_ao_cancel(dev, s);
s->async->events |= COMEDI_CB_OVERFLOW;
return;
}
prep_ao_dma(dev, i, size);
return;
}
static void dt282x_ai_dma_interrupt(struct comedi_device *dev)
{
void *ptr;
int size;
int i;
int ret;
struct comedi_subdevice *s = dev->subdevices;
update_supcsr(DT2821_CLRDMADNE);
if (!s->async->prealloc_buf) {
printk(KERN_ERR "async->data disappeared. dang!\n");
return;
}
i = devpriv->current_dma_index;
ptr = devpriv->dma[i].buf;
size = devpriv->dma[i].size;
disable_dma(devpriv->dma[i].chan);
devpriv->current_dma_index = 1 - i;
dt282x_munge(dev, ptr, size);
ret = cfc_write_array_to_buffer(s, ptr, size);
if (ret != size) {
dt282x_ai_cancel(dev, s);
return;
}
devpriv->nread -= size / 2;
if (devpriv->nread < 0) {
printk(KERN_INFO "dt282x: off by one\n");
devpriv->nread = 0;
}
if (!devpriv->nread) {
dt282x_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
update_supcsr(0);
}
#endif
prep_ai_dma(dev, i, 0);
}
static int prep_ai_dma(struct comedi_device *dev, int dma_index, int n)
{
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
static int prep_ao_dma(struct comedi_device *dev, int dma_index, int n)
{
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
static irqreturn_t dt282x_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s;
struct comedi_subdevice *s_ao;
unsigned int supcsr, adcsr, dacsr;
int handled = 0;
if (!dev->attached) {
comedi_error(dev, "spurious interrupt");
return IRQ_HANDLED;
}
s = dev->subdevices + 0;
s_ao = dev->subdevices + 1;
adcsr = inw(dev->iobase + DT2821_ADCSR);
dacsr = inw(dev->iobase + DT2821_DACSR);
supcsr = inw(dev->iobase + DT2821_SUPCSR);
if (supcsr & DT2821_DMAD) {
if (devpriv->dma_dir == DMA_MODE_READ)
dt282x_ai_dma_interrupt(dev);
else
dt282x_ao_dma_interrupt(dev);
handled = 1;
}
if (adcsr & DT2821_ADERR) {
if (devpriv->nread != 0) {
comedi_error(dev, "A/D error");
dt282x_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_ERROR;
}
handled = 1;
}
if (dacsr & DT2821_DAERR) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
comedi_error(dev, "D/A error");
dt282x_ao_cancel(dev, s_ao);
s->async->events |= COMEDI_CB_ERROR;
handled = 1;
}
#if 0
if (adcsr & DT2821_ADDONE) {
int ret;
short data;
data = (short)inw(dev->iobase + DT2821_ADDAT);
data &= (1 << boardtype.adbits) - 1;
if (devpriv->ad_2scomp)
data ^= 1 << (boardtype.adbits - 1);
ret = comedi_buf_put(s->async, data);
if (ret == 0)
s->async->events |= COMEDI_CB_OVERFLOW;
devpriv->nread--;
if (!devpriv->nread) {
s->async->events |= COMEDI_CB_EOA;
} else {
if (supcsr & DT2821_SCDN)
update_supcsr(DT2821_STRIG);
}
handled = 1;
}
#endif
comedi_event(dev, s);
return IRQ_RETVAL(handled);
}
static void dt282x_load_changain(struct comedi_device *dev, int n,
unsigned int *chanlist)
{
unsigned int i;
unsigned int chan, range;
outw(DT2821_LLE | (n - 1), dev->iobase + DT2821_CHANCSR);
for (i = 0; i < n; i++) {
chan = CR_CHAN(chanlist[i]);
range = CR_RANGE(chanlist[i]);
update_adcsr((range << 4) | (chan));
}
outw(n - 1, dev->iobase + DT2821_CHANCSR);
}
static int dt282x_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
devpriv->adcsr = DT2821_ADCLK;
update_adcsr(0);
dt282x_load_changain(dev, 1, &insn->chanspec);
update_supcsr(DT2821_PRLD);
wait_for(!mux_busy(), comedi_error(dev, "timeout\n"); return -ETIME;);
for (i = 0; i < insn->n; i++) {
update_supcsr(DT2821_STRIG);
wait_for(ad_done(), comedi_error(dev, "timeout\n");
return -ETIME;);
data[i] =
inw(dev->iobase +
DT2821_ADDAT) & ((1 << boardtype.adbits) - 1);
if (devpriv->ad_2scomp)
data[i] ^= (1 << (boardtype.adbits - 1));
}
return i;
}
static int dt282x_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_FOLLOW | TRIG_EXT;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_COUNT | TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->scan_begin_src != TRIG_FOLLOW &&
cmd->scan_begin_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->scan_begin_src == TRIG_FOLLOW) {
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
} else {
if (cmd->scan_begin_arg != 0) {
cmd->scan_begin_arg = 0;
err++;
}
}
if (cmd->convert_arg < 4000) {
cmd->convert_arg = 4000;
err++;
}
#define SLOWEST_TIMER (250*(1<<15)*255)
if (cmd->convert_arg > SLOWEST_TIMER) {
cmd->convert_arg = SLOWEST_TIMER;
err++;
}
if (cmd->convert_arg < this_board->ai_speed) {
cmd->convert_arg = this_board->ai_speed;
err++;
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
tmp = cmd->convert_arg;
dt282x_ns_to_timer(&cmd->convert_arg, cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (err)
return 4;
return 0;
}
static int dt282x_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
int timer;
if (devpriv->usedma == 0) {
comedi_error(dev,
"driver requires 2 dma channels"
" to execute command");
return -EIO;
}
dt282x_disable_dma(dev);
if (cmd->convert_arg < this_board->ai_speed)
cmd->convert_arg = this_board->ai_speed;
timer = dt282x_ns_to_timer(&cmd->convert_arg, TRIG_ROUND_NEAREST);
outw(timer, dev->iobase + DT2821_TMRCTR);
if (cmd->scan_begin_src == TRIG_FOLLOW) {
devpriv->supcsr = DT2821_ERRINTEN | DT2821_DS0;
} else {
devpriv->supcsr = DT2821_ERRINTEN | DT2821_DS0 | DT2821_DS1;
}
update_supcsr(DT2821_CLRDMADNE | DT2821_BUFFB | DT2821_ADCINIT);
devpriv->ntrig = cmd->stop_arg * cmd->scan_end_arg;
devpriv->nread = devpriv->ntrig;
devpriv->dma_dir = DMA_MODE_READ;
devpriv->current_dma_index = 0;
prep_ai_dma(dev, 0, 0);
if (devpriv->ntrig) {
prep_ai_dma(dev, 1, 0);
devpriv->supcsr |= DT2821_DDMA;
update_supcsr(0);
}
devpriv->adcsr = 0;
dt282x_load_changain(dev, cmd->chanlist_len, cmd->chanlist);
devpriv->adcsr = DT2821_ADCLK | DT2821_IADDONE;
update_adcsr(0);
update_supcsr(DT2821_PRLD);
wait_for(!mux_busy(), comedi_error(dev, "timeout\n"); return -ETIME;);
if (cmd->scan_begin_src == TRIG_FOLLOW) {
update_supcsr(DT2821_STRIG);
} else {
devpriv->supcsr |= DT2821_XTRIG;
update_supcsr(0);
}
return 0;
}
static void dt282x_disable_dma(struct comedi_device *dev)
{
if (devpriv->usedma) {
disable_dma(devpriv->dma[0].chan);
disable_dma(devpriv->dma[1].chan);
}
}
static int dt282x_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
dt282x_disable_dma(dev);
devpriv->adcsr = 0;
update_adcsr(0);
devpriv->supcsr = 0;
update_supcsr(DT2821_ADCINIT);
return 0;
}
static int dt282x_ns_to_timer(int *nanosec, int round_mode)
{
int prescale, base, divider;
for (prescale = 0; prescale < 16; prescale++) {
if (prescale == 1)
continue;
base = 250 * (1 << prescale);
switch (round_mode) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
divider = (*nanosec + base - 1) / base;
break;
}
if (divider < 256) {
*nanosec = divider * base;
return (prescale << 8) | (255 - divider);
}
}
base = 250 * (1 << 15);
divider = 255;
*nanosec = divider * base;
return (15 << 8) | (255 - divider);
}
static int dt282x_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = devpriv->ao[CR_CHAN(insn->chanspec)];
return 1;
}
static int dt282x_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
short d;
unsigned int chan;
chan = CR_CHAN(insn->chanspec);
d = data[0];
d &= (1 << boardtype.dabits) - 1;
devpriv->ao[chan] = d;
devpriv->dacsr |= DT2821_SSEL;
if (chan) {
devpriv->dacsr |= DT2821_YSEL;
if (devpriv->da0_2scomp)
d ^= (1 << (boardtype.dabits - 1));
} else {
devpriv->dacsr &= ~DT2821_YSEL;
if (devpriv->da1_2scomp)
d ^= (1 << (boardtype.dabits - 1));
}
update_dacsr(0);
outw(d, dev->iobase + DT2821_DADAT);
update_supcsr(DT2821_DACON);
return 1;
}
static int dt282x_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_INT;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_NOW;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->scan_begin_arg < 5000 ) {
cmd->scan_begin_arg = 5000;
err++;
}
if (cmd->convert_arg != 0) {
cmd->convert_arg = 0;
err++;
}
if (cmd->scan_end_arg > 2) {
cmd->scan_end_arg = 2;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
tmp = cmd->scan_begin_arg;
dt282x_ns_to_timer(&cmd->scan_begin_arg, cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
if (err)
return 4;
return 0;
}
static int dt282x_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int x)
{
int size;
if (x != 0)
return -EINVAL;
size = cfc_read_array_from_buffer(s, devpriv->dma[0].buf,
devpriv->dma_maxsize);
if (size == 0) {
printk(KERN_ERR "dt282x: AO underrun\n");
return -EPIPE;
}
prep_ao_dma(dev, 0, size);
size = cfc_read_array_from_buffer(s, devpriv->dma[1].buf,
devpriv->dma_maxsize);
if (size == 0) {
printk(KERN_ERR "dt282x: AO underrun\n");
return -EPIPE;
}
prep_ao_dma(dev, 1, size);
update_supcsr(DT2821_STRIG);
s->async->inttrig = NULL;
return 1;
}
static int dt282x_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
int timer;
struct comedi_cmd *cmd = &s->async->cmd;
if (devpriv->usedma == 0) {
comedi_error(dev,
"driver requires 2 dma channels"
" to execute command");
return -EIO;
}
dt282x_disable_dma(dev);
devpriv->supcsr = DT2821_ERRINTEN | DT2821_DS1 | DT2821_DDMA;
update_supcsr(DT2821_CLRDMADNE | DT2821_BUFFB | DT2821_DACINIT);
devpriv->ntrig = cmd->stop_arg * cmd->chanlist_len;
devpriv->nread = devpriv->ntrig;
devpriv->dma_dir = DMA_MODE_WRITE;
devpriv->current_dma_index = 0;
timer = dt282x_ns_to_timer(&cmd->scan_begin_arg, TRIG_ROUND_NEAREST);
outw(timer, dev->iobase + DT2821_TMRCTR);
devpriv->dacsr = DT2821_SSEL | DT2821_DACLK | DT2821_IDARDY;
update_dacsr(0);
s->async->inttrig = dt282x_ao_inttrig;
return 0;
}
static int dt282x_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
dt282x_disable_dma(dev);
devpriv->dacsr = 0;
update_dacsr(0);
devpriv->supcsr = 0;
update_supcsr(DT2821_DACINIT);
return 0;
}
static int dt282x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outw(s->state, dev->iobase + DT2821_DIODAT);
}
data[1] = inw(dev->iobase + DT2821_DIODAT);
return 2;
}
static int dt282x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int mask;
mask = (CR_CHAN(insn->chanspec) < 8) ? 0x00ff : 0xff00;
if (data[0])
s->io_bits |= mask;
else
s->io_bits &= ~mask;
if (s->io_bits & 0x00ff)
devpriv->dacsr |= DT2821_LBOE;
else
devpriv->dacsr &= ~DT2821_LBOE;
if (s->io_bits & 0xff00)
devpriv->dacsr |= DT2821_HBOE;
else
devpriv->dacsr &= ~DT2821_HBOE;
outw(devpriv->dacsr, dev->iobase + DT2821_DACSR);
return 1;
}
static const struct comedi_lrange *opt_ai_range_lkup(int ispgl, int x)
{
if (ispgl) {
if (x < 0 || x >= 2)
x = 0;
return ai_range_pgl_table[x];
} else {
if (x < 0 || x >= 4)
x = 0;
return ai_range_table[x];
}
}
static const struct comedi_lrange *opt_ao_range_lkup(int x)
{
if (x < 0 || x >= 5)
x = 0;
return ao_range_table[x];
}
static int dt282x_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int i, irq;
int ret;
struct comedi_subdevice *s;
unsigned long iobase;
dev->board_name = this_board->name;
iobase = it->options[opt_iobase];
if (!iobase)
iobase = 0x240;
printk(KERN_INFO "comedi%d: dt282x: 0x%04lx", dev->minor, iobase);
if (!request_region(iobase, DT2821_SIZE, "dt282x")) {
printk(KERN_INFO " I/O port conflict\n");
return -EBUSY;
}
dev->iobase = iobase;
outw(DT2821_BDINIT, dev->iobase + DT2821_SUPCSR);
i = inw(dev->iobase + DT2821_ADCSR);
#ifdef DEBUG
printk(KERN_DEBUG " fingerprint=%x,%x,%x,%x,%x",
inw(dev->iobase + DT2821_ADCSR),
inw(dev->iobase + DT2821_CHANCSR),
inw(dev->iobase + DT2821_DACSR),
inw(dev->iobase + DT2821_SUPCSR),
inw(dev->iobase + DT2821_TMRCTR));
#endif
if (((inw(dev->iobase + DT2821_ADCSR) & DT2821_ADCSR_MASK)
!= DT2821_ADCSR_VAL) ||
((inw(dev->iobase + DT2821_CHANCSR) & DT2821_CHANCSR_MASK)
!= DT2821_CHANCSR_VAL) ||
((inw(dev->iobase + DT2821_DACSR) & DT2821_DACSR_MASK)
!= DT2821_DACSR_VAL) ||
((inw(dev->iobase + DT2821_SUPCSR) & DT2821_SUPCSR_MASK)
!= DT2821_SUPCSR_VAL) ||
((inw(dev->iobase + DT2821_TMRCTR) & DT2821_TMRCTR_MASK)
!= DT2821_TMRCTR_VAL)) {
printk(KERN_ERR " board not found");
return -EIO;
}
irq = it->options[opt_irq];
#if 0
if (irq < 0) {
unsigned long flags;
int irqs;
save_flags(flags);
sti();
irqs = probe_irq_on();
udelay(100);
irq = probe_irq_off(irqs);
restore_flags(flags);
if (0 )
printk(KERN_ERR " error probing irq (bad)");
}
#endif
if (irq > 0) {
printk(KERN_INFO " ( irq = %d )", irq);
ret = request_irq(irq, dt282x_interrupt, 0, "dt282x", dev);
if (ret < 0) {
printk(KERN_ERR " failed to get irq\n");
return -EIO;
}
dev->irq = irq;
} else if (irq == 0) {
printk(KERN_INFO " (no irq)");
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
printk(KERN_INFO " (irq probe not implemented)");
#endif
}
ret = alloc_private(dev, sizeof(struct dt282x_private));
if (ret < 0)
return ret;
ret = dt282x_grab_dma(dev, it->options[opt_dma1],
it->options[opt_dma2]);
if (ret < 0)
return ret;
ret = alloc_subdevices(dev, 3);
if (ret < 0)
return ret;
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ |
((it->options[opt_diff]) ? SDF_DIFF : SDF_COMMON);
s->n_chan =
(it->options[opt_diff]) ? boardtype.adchan_di : boardtype.adchan_se;
s->insn_read = dt282x_ai_insn_read;
s->do_cmdtest = dt282x_ai_cmdtest;
s->do_cmd = dt282x_ai_cmd;
s->cancel = dt282x_ai_cancel;
s->maxdata = (1 << boardtype.adbits) - 1;
s->len_chanlist = 16;
s->range_table =
opt_ai_range_lkup(boardtype.ispgl, it->options[opt_ai_range]);
devpriv->ad_2scomp = it->options[opt_ai_twos];
s++;
s->n_chan = boardtype.dachan;
if (s->n_chan) {
s->type = COMEDI_SUBD_AO;
dev->write_subdev = s;
s->subdev_flags = SDF_WRITABLE | SDF_CMD_WRITE;
s->insn_read = dt282x_ao_insn_read;
s->insn_write = dt282x_ao_insn_write;
s->do_cmdtest = dt282x_ao_cmdtest;
s->do_cmd = dt282x_ao_cmd;
s->cancel = dt282x_ao_cancel;
s->maxdata = (1 << boardtype.dabits) - 1;
s->len_chanlist = 2;
s->range_table_list = devpriv->darangelist;
devpriv->darangelist[0] =
opt_ao_range_lkup(it->options[opt_ao0_range]);
devpriv->darangelist[1] =
opt_ao_range_lkup(it->options[opt_ao1_range]);
devpriv->da0_2scomp = it->options[opt_ao0_twos];
devpriv->da1_2scomp = it->options[opt_ao1_twos];
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s++;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->insn_bits = dt282x_dio_insn_bits;
s->insn_config = dt282x_dio_insn_config;
s->maxdata = 1;
s->range_table = &range_digital;
printk(KERN_INFO "\n");
return 0;
}
static void free_resources(struct comedi_device *dev)
{
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->iobase)
release_region(dev->iobase, DT2821_SIZE);
if (dev->private) {
if (devpriv->dma[0].chan)
free_dma(devpriv->dma[0].chan);
if (devpriv->dma[1].chan)
free_dma(devpriv->dma[1].chan);
if (devpriv->dma[0].buf)
free_page((unsigned long)devpriv->dma[0].buf);
if (devpriv->dma[1].buf)
free_page((unsigned long)devpriv->dma[1].buf);
}
}
static int dt282x_detach(struct comedi_device *dev)
{
printk(KERN_INFO "comedi%d: dt282x: remove\n", dev->minor);
free_resources(dev);
return 0;
}
static int dt282x_grab_dma(struct comedi_device *dev, int dma1, int dma2)
{
int ret;
devpriv->usedma = 0;
if (!dma1 && !dma2) {
printk(KERN_ERR " (no dma)");
return 0;
}
if (dma1 == dma2 || dma1 < 5 || dma2 < 5 || dma1 > 7 || dma2 > 7)
return -EINVAL;
if (dma2 < dma1) {
int i;
i = dma1;
dma1 = dma2;
dma2 = i;
}
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
if (!devpriv->dma[0].buf || !devpriv->dma[1].buf) {
printk(KERN_ERR " can't get DMA memory");
return -ENOMEM;
}
printk(KERN_INFO " (dma=%d,%d)", dma1, dma2);
devpriv->usedma = 1;
return 0;
}
