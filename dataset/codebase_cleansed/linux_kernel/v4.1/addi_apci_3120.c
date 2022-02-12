static void apci3120_addon_write(struct comedi_device *dev,
unsigned int val, unsigned int reg)
{
struct apci3120_private *devpriv = dev->private;
outw(reg, devpriv->addon + APCI3120_ADDON_ADDR_REG);
outw(val & 0xffff, devpriv->addon + APCI3120_ADDON_DATA_REG);
outw(reg + 2, devpriv->addon + APCI3120_ADDON_ADDR_REG);
outw((val >> 16) & 0xffff, devpriv->addon + APCI3120_ADDON_DATA_REG);
}
static void apci3120_init_dma(struct comedi_device *dev,
struct apci3120_dmabuf *dmabuf)
{
struct apci3120_private *devpriv = dev->private;
outl(AGCSTS_TC_ENABLE | AGCSTS_RESET_A2P_FIFO,
devpriv->amcc + AMCC_OP_REG_AGCSTS);
apci3120_addon_write(dev, AGCSTS_TC_ENABLE | AGCSTS_RESET_A2P_FIFO,
AMCC_OP_REG_AGCSTS);
outl(RESET_A2P_FLAGS | EN_A2P_TRANSFERS,
devpriv->amcc + AMCC_OP_REG_MCSR);
apci3120_addon_write(dev, dmabuf->hw, AMCC_OP_REG_AMWAR);
apci3120_addon_write(dev, dmabuf->use_size, AMCC_OP_REG_AMWTC);
outl(APCI3120_FIFO_ADVANCE_ON_BYTE_2 | AINT_WRITE_COMPL,
devpriv->amcc + AMCC_OP_REG_INTCSR);
outw(APCI3120_ADDON_CTRL_AMWEN_ENA | APCI3120_ADDON_CTRL_A2P_FIFO_ENA,
devpriv->addon + APCI3120_ADDON_CTRL_REG);
}
static void apci3120_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci3120_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
struct apci3120_dmabuf *dmabuf0 = &devpriv->dmabuf[0];
struct apci3120_dmabuf *dmabuf1 = &devpriv->dmabuf[1];
unsigned int dmalen0 = dmabuf0->size;
unsigned int dmalen1 = dmabuf1->size;
unsigned int scan_bytes;
scan_bytes = comedi_samples_to_bytes(s, cmd->scan_end_arg);
if (cmd->stop_src == TRIG_COUNT) {
if (dmalen0 > (cmd->stop_arg * scan_bytes))
dmalen0 = cmd->stop_arg * scan_bytes;
else if (dmalen1 > (cmd->stop_arg * scan_bytes - dmalen0))
dmalen1 = cmd->stop_arg * scan_bytes - dmalen0;
}
if (cmd->flags & CMDF_WAKE_EOS) {
if (dmalen0 > scan_bytes) {
dmalen0 = scan_bytes;
if (cmd->scan_end_arg & 1)
dmalen0 += 2;
}
if (dmalen1 > scan_bytes) {
dmalen1 = scan_bytes;
if (cmd->scan_end_arg & 1)
dmalen1 -= 2;
if (dmalen1 < 4)
dmalen1 = 4;
}
} else {
if (dmalen0 > s->async->prealloc_bufsz)
dmalen0 = s->async->prealloc_bufsz;
if (dmalen1 > s->async->prealloc_bufsz)
dmalen1 = s->async->prealloc_bufsz;
}
dmabuf0->use_size = dmalen0;
dmabuf1->use_size = dmalen1;
apci3120_init_dma(dev, dmabuf0);
}
static unsigned int apci3120_ns_to_timer(struct comedi_device *dev,
unsigned int timer,
unsigned int ns,
unsigned int flags)
{
struct apci3120_private *devpriv = dev->private;
unsigned int prescale = (timer == 0) ? 10 : 1000;
unsigned int timer_base = devpriv->osc_base * prescale;
unsigned int divisor;
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_UP:
divisor = DIV_ROUND_UP(ns, timer_base);
break;
case CMDF_ROUND_DOWN:
divisor = ns / timer_base;
break;
case CMDF_ROUND_NEAREST:
default:
divisor = DIV_ROUND_CLOSEST(ns, timer_base);
break;
}
if (timer == 2) {
if (divisor > 0x00ffffff)
divisor = 0x00ffffff;
} else {
if (divisor > 0xffff)
divisor = 0xffff;
}
if (divisor < 2)
divisor = 2;
return divisor;
}
static void apci3120_clr_timer2_interrupt(struct comedi_device *dev)
{
inb(dev->iobase + APCI3120_CTR0_REG);
}
static void apci3120_timer_write(struct comedi_device *dev,
unsigned int timer, unsigned int val)
{
struct apci3120_private *devpriv = dev->private;
outb(APCI3120_CTR0_DO_BITS(devpriv->do_bits) |
APCI3120_CTR0_TIMER_SEL(timer),
dev->iobase + APCI3120_CTR0_REG);
outw(val & 0xffff, dev->iobase + APCI3120_TIMER_REG);
if (timer == 2) {
outb(APCI3120_CTR0_DO_BITS(devpriv->do_bits) |
APCI3120_CTR0_TIMER_SEL(timer + 1),
dev->iobase + APCI3120_CTR0_REG);
outw((val >> 16) & 0xffff, dev->iobase + APCI3120_TIMER_REG);
}
}
static unsigned int apci3120_timer_read(struct comedi_device *dev,
unsigned int timer)
{
struct apci3120_private *devpriv = dev->private;
unsigned int val;
outb(APCI3120_CTR0_DO_BITS(devpriv->do_bits) |
APCI3120_CTR0_TIMER_SEL(timer),
dev->iobase + APCI3120_CTR0_REG);
val = inw(dev->iobase + APCI3120_TIMER_REG);
if (timer == 2) {
outb(APCI3120_CTR0_DO_BITS(devpriv->do_bits) |
APCI3120_CTR0_TIMER_SEL(timer + 1),
dev->iobase + APCI3120_CTR0_REG);
val |= (inw(dev->iobase + APCI3120_TIMER_REG) << 16);
}
return val;
}
static void apci3120_timer_set_mode(struct comedi_device *dev,
unsigned int timer, unsigned int mode)
{
struct apci3120_private *devpriv = dev->private;
devpriv->timer_mode &= ~APCI3120_TIMER_MODE_MASK(timer);
devpriv->timer_mode |= APCI3120_TIMER_MODE(timer, mode);
outb(devpriv->timer_mode, dev->iobase + APCI3120_TIMER_MODE_REG);
}
static void apci3120_timer_enable(struct comedi_device *dev,
unsigned int timer, bool enable)
{
struct apci3120_private *devpriv = dev->private;
if (enable)
devpriv->ctrl |= APCI3120_CTRL_GATE(timer);
else
devpriv->ctrl &= ~APCI3120_CTRL_GATE(timer);
outw(devpriv->ctrl, dev->iobase + APCI3120_CTRL_REG);
}
static void apci3120_exttrig_enable(struct comedi_device *dev, bool enable)
{
struct apci3120_private *devpriv = dev->private;
if (enable)
devpriv->ctrl |= APCI3120_CTRL_EXT_TRIG;
else
devpriv->ctrl &= ~APCI3120_CTRL_EXT_TRIG;
outw(devpriv->ctrl, dev->iobase + APCI3120_CTRL_REG);
}
static void apci3120_set_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
int n_chan, unsigned int *chanlist)
{
struct apci3120_private *devpriv = dev->private;
int i;
for (i = 0; i < n_chan; i++) {
unsigned int chan = CR_CHAN(chanlist[i]);
unsigned int range = CR_RANGE(chanlist[i]);
unsigned int val;
val = APCI3120_CHANLIST_MUX(chan) |
APCI3120_CHANLIST_GAIN(range) |
APCI3120_CHANLIST_INDEX(i);
if (comedi_range_is_unipolar(s, range))
val |= APCI3120_CHANLIST_UNIPOLAR;
outw(val, dev->iobase + APCI3120_CHANLIST_REG);
}
inw(dev->iobase + APCI3120_TIMER_MODE_REG);
devpriv->ctrl = APCI3120_CTRL_PR(n_chan - 1) | APCI3120_CTRL_PA(0);
outw(devpriv->ctrl, dev->iobase + APCI3120_CTRL_REG);
if (n_chan > 1)
devpriv->mode |= APCI3120_MODE_SCAN_ENA;
}
static void apci3120_interrupt_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci3120_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
struct apci3120_dmabuf *dmabuf;
unsigned int nbytes;
unsigned int nsamples;
dmabuf = &devpriv->dmabuf[devpriv->cur_dmabuf];
nbytes = dmabuf->use_size - inl(devpriv->amcc + AMCC_OP_REG_MWTC);
if (nbytes < dmabuf->use_size)
dev_err(dev->class_dev, "Interrupted DMA transfer!\n");
if (nbytes & 1) {
dev_err(dev->class_dev, "Odd count of bytes in DMA ring!\n");
async->events |= COMEDI_CB_ERROR;
return;
}
nsamples = comedi_bytes_to_samples(s, nbytes);
if (nsamples) {
comedi_buf_write_samples(s, dmabuf->virt, nsamples);
if (!(cmd->flags & CMDF_WAKE_EOS))
async->events |= COMEDI_CB_EOS;
}
if ((async->events & COMEDI_CB_CANCEL_MASK) ||
(cmd->stop_src == TRIG_COUNT && async->scans_done >= cmd->stop_arg))
return;
if (devpriv->use_double_buffer) {
devpriv->cur_dmabuf = !devpriv->cur_dmabuf;
dmabuf = &devpriv->dmabuf[devpriv->cur_dmabuf];
apci3120_init_dma(dev, dmabuf);
} else {
apci3120_init_dma(dev, dmabuf);
}
}
static irqreturn_t apci3120_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct apci3120_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status;
unsigned int int_amcc;
status = inw(dev->iobase + APCI3120_STATUS_REG);
int_amcc = inl(devpriv->amcc + AMCC_OP_REG_INTCSR);
if (!(status & APCI3120_STATUS_INT_MASK) &&
!(int_amcc & ANY_S593X_INT)) {
dev_err(dev->class_dev, "IRQ from unknown source\n");
return IRQ_NONE;
}
outl(int_amcc | AINT_INT_MASK, devpriv->amcc + AMCC_OP_REG_INTCSR);
if (devpriv->ctrl & APCI3120_CTRL_EXT_TRIG)
apci3120_exttrig_enable(dev, false);
if (int_amcc & MASTER_ABORT_INT)
dev_err(dev->class_dev, "AMCC IRQ - MASTER DMA ABORT!\n");
if (int_amcc & TARGET_ABORT_INT)
dev_err(dev->class_dev, "AMCC IRQ - TARGET DMA ABORT!\n");
if ((status & APCI3120_STATUS_EOC_INT) == 0 &&
(devpriv->mode & APCI3120_MODE_EOC_IRQ_ENA)) {
}
if ((status & APCI3120_STATUS_EOS_INT) &&
(devpriv->mode & APCI3120_MODE_EOS_IRQ_ENA)) {
unsigned short val;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
val = inw(dev->iobase + APCI3120_AI_FIFO_REG);
comedi_buf_write_samples(s, &val, 1);
}
devpriv->mode |= APCI3120_MODE_EOS_IRQ_ENA;
outb(devpriv->mode, dev->iobase + APCI3120_MODE_REG);
}
if (status & APCI3120_STATUS_TIMER2_INT) {
apci3120_clr_timer2_interrupt(dev);
}
if (status & APCI3120_STATUS_AMCC_INT) {
outl(AINT_WT_COMPLETE, devpriv->amcc + AMCC_OP_REG_INTCSR);
apci3120_interrupt_dma(dev, s);
}
if (cmd->stop_src == TRIG_COUNT && async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int apci3120_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci3120_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int divisor;
devpriv->mode = APCI3120_MODE_TIMER2_CLK_OSC |
APCI3120_MODE_TIMER2_AS_TIMER;
outl(AINT_WT_COMPLETE, devpriv->amcc + AMCC_OP_REG_INTCSR);
devpriv->cur_dmabuf = 0;
apci3120_set_chanlist(dev, s, cmd->chanlist_len, cmd->chanlist);
if (cmd->start_src == TRIG_EXT)
apci3120_exttrig_enable(dev, true);
if (cmd->scan_begin_src == TRIG_TIMER) {
divisor = apci3120_ns_to_timer(dev, 1, cmd->scan_begin_arg,
cmd->flags);
apci3120_timer_set_mode(dev, 1, APCI3120_TIMER_MODE2);
apci3120_timer_write(dev, 1, divisor);
}
divisor = apci3120_ns_to_timer(dev, 0, cmd->convert_arg, cmd->flags);
apci3120_timer_set_mode(dev, 0, APCI3120_TIMER_MODE2);
apci3120_timer_write(dev, 0, divisor);
if (devpriv->use_dma)
apci3120_setup_dma(dev, s);
else
devpriv->mode |= APCI3120_MODE_EOS_IRQ_ENA;
outb(devpriv->mode, dev->iobase + APCI3120_MODE_REG);
if (cmd->scan_begin_src == TRIG_TIMER)
apci3120_timer_enable(dev, 1, true);
apci3120_timer_enable(dev, 0, true);
return 0;
}
static int apci3120_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int arg;
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
100000);
}
err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 10000);
err |= comedi_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
return 0;
}
static int apci3120_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci3120_private *devpriv = dev->private;
outw(0, devpriv->addon + 4);
apci3120_addon_write(dev, 0, AMCC_OP_REG_AGCSTS);
outl(0, devpriv->amcc + AMCC_OP_REG_MCSR);
devpriv->ctrl = 0;
outw(devpriv->ctrl, dev->iobase + APCI3120_CTRL_REG);
devpriv->mode = 0;
outb(devpriv->mode, dev->iobase + APCI3120_MODE_REG);
inw(dev->iobase + APCI3120_STATUS_REG);
devpriv->cur_dmabuf = 0;
return 0;
}
static int apci3120_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + APCI3120_STATUS_REG);
if ((status & APCI3120_STATUS_EOC_INT) == 0)
return 0;
return -EBUSY;
}
static int apci3120_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3120_private *devpriv = dev->private;
unsigned int divisor;
int ret;
int i;
devpriv->mode = APCI3120_MODE_TIMER2_CLK_OSC |
APCI3120_MODE_TIMER2_AS_TIMER;
outb(devpriv->mode, dev->iobase + APCI3120_MODE_REG);
apci3120_set_chanlist(dev, s, 1, &insn->chanspec);
apci3120_timer_set_mode(dev, 0, APCI3120_TIMER_MODE4);
apci3120_timer_enable(dev, 0, true);
divisor = apci3120_ns_to_timer(dev, 0, 10000, CMDF_ROUND_NEAREST);
for (i = 0; i < insn->n; i++) {
apci3120_timer_write(dev, 0, divisor);
ret = comedi_timeout(dev, s, insn, apci3120_ai_eoc, 0);
if (ret)
return ret;
data[i] = inw(dev->iobase + APCI3120_AI_FIFO_REG);
}
return insn->n;
}
static int apci3120_ao_ready(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + APCI3120_STATUS_REG);
if (status & APCI3120_STATUS_DA_READY)
return 0;
return -EBUSY;
}
static int apci3120_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
int ret;
ret = comedi_timeout(dev, s, insn, apci3120_ao_ready, 0);
if (ret)
return ret;
outw(APCI3120_AO_MUX(chan) | APCI3120_AO_DATA(val),
dev->iobase + APCI3120_AO_REG(chan));
s->readback[chan] = val;
}
return insn->n;
}
static int apci3120_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int status;
status = inw(dev->iobase + APCI3120_STATUS_REG);
data[1] = APCI3120_STATUS_TO_DI_BITS(status);
return insn->n;
}
static int apci3120_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3120_private *devpriv = dev->private;
if (comedi_dio_update_state(s, data)) {
devpriv->do_bits = s->state;
outb(APCI3120_CTR0_DO_BITS(devpriv->do_bits),
dev->iobase + APCI3120_CTR0_REG);
}
data[1] = s->state;
return insn->n;
}
static int apci3120_timer_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3120_private *devpriv = dev->private;
unsigned int divisor;
unsigned int status;
unsigned int mode;
unsigned int timer_mode;
switch (data[0]) {
case INSN_CONFIG_ARM:
apci3120_clr_timer2_interrupt(dev);
divisor = apci3120_ns_to_timer(dev, 2, data[1],
CMDF_ROUND_DOWN);
apci3120_timer_write(dev, 2, divisor);
apci3120_timer_enable(dev, 2, true);
break;
case INSN_CONFIG_DISARM:
apci3120_timer_enable(dev, 2, false);
apci3120_clr_timer2_interrupt(dev);
break;
case INSN_CONFIG_GET_COUNTER_STATUS:
data[1] = 0;
data[2] = COMEDI_COUNTER_ARMED | COMEDI_COUNTER_COUNTING |
COMEDI_COUNTER_TERMINAL_COUNT;
if (devpriv->ctrl & APCI3120_CTRL_GATE(2)) {
data[1] |= COMEDI_COUNTER_ARMED;
data[1] |= COMEDI_COUNTER_COUNTING;
}
status = inw(dev->iobase + APCI3120_STATUS_REG);
if (status & APCI3120_STATUS_TIMER2_INT) {
data[1] &= ~COMEDI_COUNTER_COUNTING;
data[1] |= COMEDI_COUNTER_TERMINAL_COUNT;
}
break;
case INSN_CONFIG_SET_COUNTER_MODE:
switch (data[1]) {
case I8254_MODE0:
mode = APCI3120_MODE_TIMER2_AS_COUNTER;
timer_mode = APCI3120_TIMER_MODE0;
break;
case I8254_MODE2:
mode = APCI3120_MODE_TIMER2_AS_TIMER;
timer_mode = APCI3120_TIMER_MODE2;
break;
case I8254_MODE4:
mode = APCI3120_MODE_TIMER2_AS_TIMER;
timer_mode = APCI3120_TIMER_MODE4;
break;
case I8254_MODE5:
mode = APCI3120_MODE_TIMER2_AS_WDOG;
timer_mode = APCI3120_TIMER_MODE5;
break;
default:
return -EINVAL;
}
apci3120_timer_enable(dev, 2, false);
apci3120_clr_timer2_interrupt(dev);
apci3120_timer_set_mode(dev, 2, timer_mode);
devpriv->mode &= ~APCI3120_MODE_TIMER2_AS_MASK;
devpriv->mode |= mode;
outb(devpriv->mode, dev->iobase + APCI3120_MODE_REG);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int apci3120_timer_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = apci3120_timer_read(dev, 2);
return insn->n;
}
static void apci3120_dma_alloc(struct comedi_device *dev)
{
struct apci3120_private *devpriv = dev->private;
struct apci3120_dmabuf *dmabuf;
int order;
int i;
for (i = 0; i < 2; i++) {
dmabuf = &devpriv->dmabuf[i];
for (order = 2; order >= 0; order--) {
dmabuf->virt = dma_alloc_coherent(dev->hw_dev,
PAGE_SIZE << order,
&dmabuf->hw,
GFP_KERNEL);
if (dmabuf->virt)
break;
}
if (!dmabuf->virt)
break;
dmabuf->size = PAGE_SIZE << order;
if (i == 0)
devpriv->use_dma = 1;
if (i == 1)
devpriv->use_double_buffer = 1;
}
}
static void apci3120_dma_free(struct comedi_device *dev)
{
struct apci3120_private *devpriv = dev->private;
struct apci3120_dmabuf *dmabuf;
int i;
if (!devpriv)
return;
for (i = 0; i < 2; i++) {
dmabuf = &devpriv->dmabuf[i];
if (dmabuf->virt) {
dma_free_coherent(dev->hw_dev, dmabuf->size,
dmabuf->virt, dmabuf->hw);
}
}
}
static void apci3120_reset(struct comedi_device *dev)
{
outb(0, dev->iobase + APCI3120_MODE_REG);
outw(0, dev->iobase + APCI3120_CTRL_REG);
inw(dev->iobase + APCI3120_STATUS_REG);
}
static int apci3120_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct apci3120_board *this_board = NULL;
struct apci3120_private *devpriv;
struct comedi_subdevice *s;
unsigned int status;
int ret;
if (context < ARRAY_SIZE(apci3120_boardtypes))
this_board = &apci3120_boardtypes[context];
if (!this_board)
return -ENODEV;
dev->board_ptr = this_board;
dev->board_name = this_board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
pci_set_master(pcidev);
dev->iobase = pci_resource_start(pcidev, 1);
devpriv->amcc = pci_resource_start(pcidev, 0);
devpriv->addon = pci_resource_start(pcidev, 2);
apci3120_reset(dev);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci3120_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0) {
dev->irq = pcidev->irq;
apci3120_dma_alloc(dev);
}
}
status = inw(dev->iobase + APCI3120_STATUS_REG);
if (APCI3120_STATUS_TO_VERSION(status) == APCI3120_REVB ||
context == BOARD_APCI3001)
devpriv->osc_base = APCI3120_REVB_OSC_BASE;
else
devpriv->osc_base = APCI3120_REVA_OSC_BASE;
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = this_board->ai_is_16bit ? 0xffff : 0x0fff;
s->range_table = &apci3120_ai_range;
s->insn_read = apci3120_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = apci3120_ai_cmdtest;
s->do_cmd = apci3120_ai_cmd;
s->cancel = apci3120_cancel;
}
s = &dev->subdevices[1];
if (this_board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 0x3fff;
s->range_table = &range_bipolar10;
s->insn_write = apci3120_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3120_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3120_do_insn_bits;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->maxdata = 0x00ffffff;
s->insn_config = apci3120_timer_insn_config;
s->insn_read = apci3120_timer_insn_read;
return 0;
}
static void apci3120_detach(struct comedi_device *dev)
{
comedi_pci_detach(dev);
apci3120_dma_free(dev);
}
static int apci3120_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci3120_driver, id->driver_data);
}
