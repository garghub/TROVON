static int dmm32at_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int ret;
struct comedi_subdevice *s;
unsigned char aihi, ailo, fifostat, aistat, intstat, airback;
unsigned long iobase;
unsigned int irq;
iobase = it->options[0];
irq = it->options[1];
printk(KERN_INFO "comedi%d: dmm32at: attaching\n", dev->minor);
printk(KERN_DEBUG "dmm32at: probing at address 0x%04lx, irq %u\n",
iobase, irq);
if (!request_region(iobase, DMM32AT_MEMSIZE, thisboard->name)) {
printk(KERN_ERR "comedi%d: dmm32at: I/O port conflict\n",
dev->minor);
return -EIO;
}
dev->iobase = iobase;
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_RESET);
udelay(1000);
dmm_outb(dev, DMM32AT_FIFOCNTRL, 0x0);
dmm_outb(dev, DMM32AT_INTCLOCK, 0x0);
dmm_outb(dev, DMM32AT_AILOW, 0x80);
dmm_outb(dev, DMM32AT_AIHIGH, 0xff);
dmm_outb(dev, DMM32AT_AICONF, DMM32AT_RANGE_U10);
udelay(100);
ailo = dmm_inb(dev, DMM32AT_AILOW);
aihi = dmm_inb(dev, DMM32AT_AIHIGH);
fifostat = dmm_inb(dev, DMM32AT_FIFOSTAT);
aistat = dmm_inb(dev, DMM32AT_AISTAT);
intstat = dmm_inb(dev, DMM32AT_INTCLOCK);
airback = dmm_inb(dev, DMM32AT_AIRBACK);
printk(KERN_DEBUG "dmm32at: lo=0x%02x hi=0x%02x fifostat=0x%02x\n",
ailo, aihi, fifostat);
printk(KERN_DEBUG
"dmm32at: aistat=0x%02x intstat=0x%02x airback=0x%02x\n",
aistat, intstat, airback);
if ((ailo != 0x00) || (aihi != 0x1f) || (fifostat != 0x80) ||
(aistat != 0x60 || (intstat != 0x00) || airback != 0x0c)) {
printk(KERN_ERR "dmmat32: board detection failed\n");
return -EIO;
}
if (irq) {
ret = request_irq(irq, dmm32at_isr, 0, thisboard->name, dev);
if (ret < 0) {
printk(KERN_ERR "dmm32at: irq conflict\n");
return ret;
}
dev->irq = irq;
}
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct dmm32at_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 3) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = thisboard->ai_chans;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = thisboard->ai_ranges;
s->len_chanlist = 32;
s->insn_read = dmm32at_ai_rinsn;
s->do_cmd = dmm32at_ai_cmd;
s->do_cmdtest = dmm32at_ai_cmdtest;
s->cancel = dmm32at_ai_cancel;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = thisboard->ao_ranges;
s->insn_write = dmm32at_ao_winsn;
s->insn_read = dmm32at_ao_rinsn;
s = dev->subdevices + 2;
if (thisboard->have_dio) {
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_DIOACC);
devpriv->dio_config = DMM32AT_DIRA | DMM32AT_DIRB |
DMM32AT_DIRCL | DMM32AT_DIRCH | DMM32AT_DIENABLE;
dmm_outb(dev, DMM32AT_DIOCONF, devpriv->dio_config);
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = thisboard->dio_chans;
s->maxdata = 1;
s->state = 0;
s->range_table = &range_digital;
s->insn_bits = dmm32at_dio_insn_bits;
s->insn_config = dmm32at_dio_insn_config;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
printk(KERN_INFO "comedi%d: dmm32at: attached\n", dev->minor);
return 1;
}
static int dmm32at_detach(struct comedi_device *dev)
{
printk(KERN_INFO "comedi%d: dmm32at: remove\n", dev->minor);
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->iobase)
release_region(dev->iobase, DMM32AT_MEMSIZE);
return 0;
}
static int dmm32at_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, i;
unsigned int d;
unsigned char status;
unsigned short msb, lsb;
unsigned char chan;
int range;
chan = CR_CHAN(insn->chanspec) & (s->n_chan - 1);
range = CR_RANGE(insn->chanspec);
dmm_outb(dev, DMM32AT_FIFOCNTRL, DMM32AT_FIFORESET);
dmm_outb(dev, DMM32AT_AILOW, chan);
dmm_outb(dev, DMM32AT_AIHIGH, chan);
dmm_outb(dev, DMM32AT_AICONF, dmm32at_rangebits[range]);
for (i = 0; i < 40000; i++) {
status = dmm_inb(dev, DMM32AT_AIRBACK);
if ((status & DMM32AT_STATUS) == 0)
break;
}
if (i == 40000) {
printk(KERN_WARNING "dmm32at: timeout\n");
return -ETIMEDOUT;
}
for (n = 0; n < insn->n; n++) {
dmm_outb(dev, DMM32AT_CONV, 0xff);
for (i = 0; i < 40000; i++) {
status = dmm_inb(dev, DMM32AT_AISTAT);
if ((status & DMM32AT_STATUS) == 0)
break;
}
if (i == 40000) {
printk(KERN_WARNING "dmm32at: timeout\n");
return -ETIMEDOUT;
}
lsb = dmm_inb(dev, DMM32AT_AILSB);
msb = dmm_inb(dev, DMM32AT_AIMSB);
d = ((msb ^ 0x0080) << 8) + lsb;
data[n] = d;
}
return n;
}
static int dmm32at_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
int start_chan, gain, i;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER ;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER ;
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
if (cmd->scan_begin_src != TRIG_TIMER &&
cmd->scan_begin_src != TRIG_EXT)
err++;
if (cmd->convert_src != TRIG_TIMER && cmd->convert_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
#define MAX_SCAN_SPEED 1000000
#define MIN_SCAN_SPEED 1000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->scan_begin_arg < MAX_SCAN_SPEED) {
cmd->scan_begin_arg = MAX_SCAN_SPEED;
err++;
}
if (cmd->scan_begin_arg > MIN_SCAN_SPEED) {
cmd->scan_begin_arg = MIN_SCAN_SPEED;
err++;
}
} else {
if (cmd->scan_begin_arg > 9) {
cmd->scan_begin_arg = 9;
err++;
}
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg >= 17500)
cmd->convert_arg = 20000;
else if (cmd->convert_arg >= 12500)
cmd->convert_arg = 15000;
else if (cmd->convert_arg >= 7500)
cmd->convert_arg = 10000;
else
cmd->convert_arg = 5000;
} else {
if (cmd->convert_arg > 9) {
cmd->convert_arg = 9;
err++;
}
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0xfffffff0) {
cmd->stop_arg = 0xfffffff0;
err++;
}
if (cmd->stop_arg == 0) {
cmd->stop_arg = 1;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
dmm32at_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
dmm32at_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->scan_end_arg) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
if (err)
return 4;
if (cmd->chanlist) {
gain = CR_RANGE(cmd->chanlist[0]);
start_chan = CR_CHAN(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) !=
(start_chan + i) % s->n_chan) {
comedi_error(dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
err++;
}
if (CR_RANGE(cmd->chanlist[i]) != gain) {
comedi_error(dev,
"entries in chanlist must all have the same gain\n");
err++;
}
}
}
if (err)
return 5;
return 0;
}
static int dmm32at_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
int i, range;
unsigned char chanlo, chanhi, status;
if (!cmd->chanlist)
return -EINVAL;
chanlo = CR_CHAN(cmd->chanlist[0]) & (s->n_chan - 1);
chanhi = chanlo + cmd->chanlist_len - 1;
if (chanhi >= s->n_chan)
return -EINVAL;
range = CR_RANGE(cmd->chanlist[0]);
dmm_outb(dev, DMM32AT_FIFOCNTRL, DMM32AT_FIFORESET);
dmm_outb(dev, DMM32AT_FIFOCNTRL, DMM32AT_SCANENABLE);
dmm_outb(dev, DMM32AT_AILOW, chanlo);
dmm_outb(dev, DMM32AT_AIHIGH, chanhi);
dmm_outb(dev, DMM32AT_AICONF, dmm32at_rangebits[range]);
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_INTRESET);
if (cmd->stop_src == TRIG_COUNT)
devpriv->ai_scans_left = cmd->stop_arg;
else {
devpriv->ai_scans_left = 0xffffffff;
}
for (i = 0; i < 40000; i++) {
status = dmm_inb(dev, DMM32AT_AIRBACK);
if ((status & DMM32AT_STATUS) == 0)
break;
}
if (i == 40000) {
printk(KERN_WARNING "dmm32at: timeout\n");
return -ETIMEDOUT;
}
if (devpriv->ai_scans_left > 1) {
dmm32at_setaitimer(dev, cmd->scan_begin_arg);
} else {
dmm_outb(dev, DMM32AT_INTCLOCK, DMM32AT_ADINT);
dmm_outb(dev, DMM32AT_CONV, 0xff);
}
return 0;
}
static int dmm32at_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
devpriv->ai_scans_left = 1;
return 0;
}
static irqreturn_t dmm32at_isr(int irq, void *d)
{
unsigned char intstat;
unsigned int samp;
unsigned short msb, lsb;
int i;
struct comedi_device *dev = d;
if (!dev->attached) {
comedi_error(dev, "spurious interrupt");
return IRQ_HANDLED;
}
intstat = dmm_inb(dev, DMM32AT_INTCLOCK);
if (intstat & DMM32AT_ADINT) {
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
for (i = 0; i < cmd->chanlist_len; i++) {
lsb = dmm_inb(dev, DMM32AT_AILSB);
msb = dmm_inb(dev, DMM32AT_AIMSB);
samp = ((msb ^ 0x0080) << 8) + lsb;
comedi_buf_put(s->async, samp);
}
if (devpriv->ai_scans_left != 0xffffffff) {
devpriv->ai_scans_left--;
if (devpriv->ai_scans_left == 0) {
dmm_outb(dev, DMM32AT_INTCLOCK, 0x0);
s->async->events |= COMEDI_CB_EOA;
}
}
comedi_event(dev, s);
}
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_INTRESET);
return IRQ_HANDLED;
}
static int dmm32at_ns_to_timer(unsigned int *ns, int round)
{
return *ns;
}
static int dmm32at_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
unsigned char hi, lo, status;
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = data[i];
lo = data[i] & 0x00ff;
hi = (data[i] >> 8) + chan * (1 << 6);
dmm_outb(dev, DMM32AT_DACLSB, lo);
dmm_outb(dev, DMM32AT_DACMSB, hi);
for (i = 0; i < 40000; i++) {
status = dmm_inb(dev, DMM32AT_DACSTAT);
if ((status & DMM32AT_DACBUSY) == 0)
break;
}
if (i == 40000) {
printk(KERN_WARNING "dmm32at: timeout\n");
return -ETIMEDOUT;
}
status = dmm_inb(dev, DMM32AT_DACMSB);
}
return i;
}
static int dmm32at_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int dmm32at_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned char diobits;
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
}
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_DIOACC);
if (((devpriv->dio_config & DMM32AT_DIRCL) == 0) ||
((devpriv->dio_config & DMM32AT_DIRCH) == 0)) {
diobits = (s->state & 0x00ff0000) >> 16;
dmm_outb(dev, DMM32AT_DIOC, diobits);
}
if ((devpriv->dio_config & DMM32AT_DIRB) == 0) {
diobits = (s->state & 0x0000ff00) >> 8;
dmm_outb(dev, DMM32AT_DIOB, diobits);
}
if ((devpriv->dio_config & DMM32AT_DIRA) == 0) {
diobits = (s->state & 0x000000ff);
dmm_outb(dev, DMM32AT_DIOA, diobits);
}
s->state = dmm_inb(dev, DMM32AT_DIOC);
s->state <<= 8;
s->state |= dmm_inb(dev, DMM32AT_DIOB);
s->state <<= 8;
s->state |= dmm_inb(dev, DMM32AT_DIOA);
data[1] = s->state;
return 2;
}
static int dmm32at_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned char chanbit;
int chan = CR_CHAN(insn->chanspec);
if (insn->n != 1)
return -EINVAL;
if (chan < 8)
chanbit = DMM32AT_DIRA;
else if (chan < 16)
chanbit = DMM32AT_DIRB;
else if (chan < 20)
chanbit = DMM32AT_DIRCL;
else
chanbit = DMM32AT_DIRCH;
if (data[0] == COMEDI_OUTPUT)
devpriv->dio_config &= ~chanbit;
else
devpriv->dio_config |= chanbit;
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_DIOACC);
dmm_outb(dev, DMM32AT_DIOCONF, devpriv->dio_config);
return 1;
}
void dmm32at_setaitimer(struct comedi_device *dev, unsigned int nansec)
{
unsigned char lo1, lo2, hi2;
unsigned short both2;
lo1 = 200;
both2 = nansec / 20000;
hi2 = (both2 & 0xff00) >> 8;
lo2 = both2 & 0x00ff;
dmm_outb(dev, DMM32AT_CNTRDIO, 0);
dmm_outb(dev, DMM32AT_CNTRL, DMM32AT_CLKACC);
dmm_outb(dev, DMM32AT_CLKCT, DMM32AT_CLKCT1);
dmm_outb(dev, DMM32AT_CLK1, lo1);
dmm_outb(dev, DMM32AT_CLKCT, DMM32AT_CLKCT2);
dmm_outb(dev, DMM32AT_CLK2, lo2);
dmm_outb(dev, DMM32AT_CLK2, hi2);
dmm_outb(dev, DMM32AT_INTCLOCK, DMM32AT_ADINT | DMM32AT_CLKSEL);
}
static int __init driver_dmm32at_init_module(void)
{
return comedi_driver_register(&driver_dmm32at);
}
static void __exit driver_dmm32at_cleanup_module(void)
{
comedi_driver_unregister(&driver_dmm32at);
}
