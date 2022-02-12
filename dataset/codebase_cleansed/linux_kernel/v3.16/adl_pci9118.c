static int check_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s, int n_chan,
unsigned int *chanlist, int frontadd, int backadd)
{
const struct boardtype *this_board = comedi_board(dev);
struct pci9118_private *devpriv = dev->private;
unsigned int i, differencial = 0, bipolar = 0;
if (n_chan < 1) {
comedi_error(dev, "range/channel list is empty!");
return 0;
}
if ((frontadd + n_chan + backadd) > s->len_chanlist) {
comedi_error(dev,
"range/channel list is too long for actual configuration!\n");
return 0;
}
if (CR_AREF(chanlist[0]) == AREF_DIFF)
differencial = 1;
if (CR_RANGE(chanlist[0]) < PCI9118_BIPOLAR_RANGES)
bipolar = 1;
if (n_chan > 1)
for (i = 1; i < n_chan; i++) {
if ((CR_AREF(chanlist[i]) == AREF_DIFF) !=
(differencial)) {
comedi_error(dev,
"Differencial and single ended "
"inputs can't be mixtured!");
return 0;
}
if ((CR_RANGE(chanlist[i]) < PCI9118_BIPOLAR_RANGES) !=
(bipolar)) {
comedi_error(dev,
"Bipolar and unipolar ranges "
"can't be mixtured!");
return 0;
}
if (!devpriv->usemux && differencial &&
(CR_CHAN(chanlist[i]) >= this_board->n_aichand)) {
comedi_error(dev,
"If AREF_DIFF is used then is "
"available only first 8 channels!");
return 0;
}
}
return 1;
}
static int setup_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s, int n_chan,
unsigned int *chanlist, int rot, int frontadd,
int backadd, int usedma)
{
struct pci9118_private *devpriv = dev->private;
unsigned int i, differencial = 0, bipolar = 0;
unsigned int scanquad, gain, ssh = 0x00;
if (usedma == 1) {
rot = 8;
usedma = 0;
}
if (CR_AREF(chanlist[0]) == AREF_DIFF)
differencial = 1;
if (CR_RANGE(chanlist[0]) < PCI9118_BIPOLAR_RANGES)
bipolar = 1;
if (!bipolar) {
devpriv->AdControlReg |= AdControl_UniP;
} else {
devpriv->AdControlReg &= ((~AdControl_UniP) & 0xff);
}
if (differencial) {
devpriv->AdControlReg |= AdControl_Diff;
} else {
devpriv->AdControlReg &= ((~AdControl_Diff) & 0xff);
}
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
outl(2, dev->iobase + PCI9118_SCANMOD);
outl(0, dev->iobase + PCI9118_SCANMOD);
outl(1, dev->iobase + PCI9118_SCANMOD);
#ifdef PCI9118_PARANOIDCHECK
devpriv->chanlistlen = n_chan;
for (i = 0; i < (PCI9118_CHANLEN + 1); i++)
devpriv->chanlist[i] = 0x55aa;
#endif
if (frontadd) {
ssh = devpriv->softsshsample;
for (i = 0; i < frontadd; i++) {
scanquad = CR_CHAN(chanlist[0]);
gain = CR_RANGE(chanlist[0]);
scanquad |= ((gain & 0x03) << 8);
outl(scanquad | ssh, dev->iobase + PCI9118_GAIN);
ssh = devpriv->softsshhold;
}
}
for (i = 0; i < n_chan; i++) {
scanquad = CR_CHAN(chanlist[i]);
#ifdef PCI9118_PARANOIDCHECK
devpriv->chanlist[i ^ usedma] = (scanquad & 0xf) << rot;
#endif
gain = CR_RANGE(chanlist[i]);
scanquad |= ((gain & 0x03) << 8);
outl(scanquad | ssh, dev->iobase + PCI9118_GAIN);
}
if (backadd) {
for (i = 0; i < backadd; i++) {
scanquad = CR_CHAN(chanlist[0]);
gain = CR_RANGE(chanlist[0]);
scanquad |= ((gain & 0x03) << 8);
outl(scanquad | ssh, dev->iobase + PCI9118_GAIN);
}
}
#ifdef PCI9118_PARANOIDCHECK
devpriv->chanlist[n_chan ^ usedma] = devpriv->chanlist[0 ^ usedma];
#endif
outl(0, dev->iobase + PCI9118_SCANMOD);
return 1;
}
static int pci9118_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inl(dev->iobase + PCI9118_ADSTAT);
if (status & AdStatus_ADrdy)
return 0;
return -EBUSY;
}
static int pci9118_insn_read_ai(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci9118_private *devpriv = dev->private;
int ret;
int n;
devpriv->AdControlReg = AdControl_Int & 0xff;
devpriv->AdFunctionReg = AdFunction_PDTrg | AdFunction_PETrg;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
if (!setup_channel_list(dev, s, 1, &insn->chanspec, 0, 0, 0, 0))
return -EINVAL;
outl(0, dev->iobase + PCI9118_DELFIFO);
for (n = 0; n < insn->n; n++) {
outw(0, dev->iobase + PCI9118_SOFTTRG);
udelay(2);
ret = comedi_timeout(dev, s, insn, pci9118_ai_eoc, 0);
if (ret) {
outl(0, dev->iobase + PCI9118_DELFIFO);
return ret;
}
if (s->maxdata == 0xffff) {
data[n] =
(inl(dev->iobase +
PCI9118_AD_DATA) & 0xffff) ^ 0x8000;
} else {
data[n] =
(inw(dev->iobase + PCI9118_AD_DATA) >> 4) & 0xfff;
}
}
outl(0, dev->iobase + PCI9118_DELFIFO);
return n;
}
static int pci9118_insn_write_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci9118_private *devpriv = dev->private;
int n, chanreg, ch;
ch = CR_CHAN(insn->chanspec);
if (ch)
chanreg = PCI9118_DA2;
else
chanreg = PCI9118_DA1;
for (n = 0; n < insn->n; n++) {
outl(data[n], dev->iobase + chanreg);
devpriv->ao_data[ch] = data[n];
}
return n;
}
static int pci9118_insn_read_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci9118_private *devpriv = dev->private;
int n, chan;
chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_data[chan];
return n;
}
static int pci9118_insn_bits_di(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inl(dev->iobase + PCI9118_DI) & 0xf;
return insn->n;
}
static int pci9118_insn_bits_do(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outl(s->state & 0x0f, dev->iobase + PCI9118_DO);
data[1] = s->state;
return insn->n;
}
static void interrupt_pci9118_ai_mode4_switch(struct comedi_device *dev)
{
struct pci9118_private *devpriv = dev->private;
devpriv->AdFunctionReg =
AdFunction_PDTrg | AdFunction_PETrg | AdFunction_AM;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
outl(0x30, dev->iobase + PCI9118_CNTCTRL);
outl((devpriv->dmabuf_hw[1 - devpriv->dma_actbuf] >> 1) & 0xff,
dev->iobase + PCI9118_CNT0);
outl((devpriv->dmabuf_hw[1 - devpriv->dma_actbuf] >> 9) & 0xff,
dev->iobase + PCI9118_CNT0);
devpriv->AdFunctionReg |= AdFunction_Start;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
}
static unsigned int defragment_dma_buffer(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short *dma_buffer,
unsigned int num_samples)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int i = 0, j = 0;
unsigned int start_pos = devpriv->ai_add_front,
stop_pos = devpriv->ai_add_front + cmd->chanlist_len;
unsigned int raw_scanlen = devpriv->ai_add_front + cmd->chanlist_len +
devpriv->ai_add_back;
for (i = 0; i < num_samples; i++) {
if (devpriv->ai_act_dmapos >= start_pos &&
devpriv->ai_act_dmapos < stop_pos) {
dma_buffer[j++] = dma_buffer[i];
}
devpriv->ai_act_dmapos++;
devpriv->ai_act_dmapos %= raw_scanlen;
}
return j;
}
static int move_block_from_dma(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short *dma_buffer,
unsigned int num_samples)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int num_bytes;
num_samples = defragment_dma_buffer(dev, s, dma_buffer, num_samples);
devpriv->ai_act_scan +=
(s->async->cur_chan + num_samples) / cmd->scan_end_arg;
s->async->cur_chan += num_samples;
s->async->cur_chan %= cmd->scan_end_arg;
num_bytes =
cfc_write_array_to_buffer(s, dma_buffer,
num_samples * sizeof(short));
if (num_bytes < num_samples * sizeof(short))
return -1;
return 0;
}
static int pci9118_exttrg_add(struct comedi_device *dev, unsigned char source)
{
struct pci9118_private *devpriv = dev->private;
if (source > 3)
return -1;
devpriv->exttrg_users |= (1 << source);
devpriv->IntControlReg |= Int_DTrg;
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
outl(inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR) | 0x1f00,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
return 0;
}
static int pci9118_exttrg_del(struct comedi_device *dev, unsigned char source)
{
struct pci9118_private *devpriv = dev->private;
if (source > 3)
return -1;
devpriv->exttrg_users &= ~(1 << source);
if (!devpriv->exttrg_users) {
devpriv->IntControlReg &= ~Int_DTrg;
if (!devpriv->IntControlReg)
outl(inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR) &
(~0x00001f00),
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
}
return 0;
}
static void pci9118_calc_divisors(char mode, struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *tim1, unsigned int *tim2,
unsigned int flags, int chans,
unsigned int *div1, unsigned int *div2,
unsigned int chnsshfront)
{
const struct boardtype *this_board = comedi_board(dev);
struct comedi_cmd *cmd = &s->async->cmd;
switch (mode) {
case 1:
case 4:
if (*tim2 < this_board->ai_ns_min)
*tim2 = this_board->ai_ns_min;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_4MHZ,
div1, div2,
tim2, flags & TRIG_ROUND_NEAREST);
break;
case 2:
if (*tim2 < this_board->ai_ns_min)
*tim2 = this_board->ai_ns_min;
*div1 = *tim2 / I8254_OSC_BASE_4MHZ;
if (*div1 < this_board->ai_pacer_min)
*div1 = this_board->ai_pacer_min;
*div2 = *tim1 / I8254_OSC_BASE_4MHZ;
*div2 = *div2 / *div1;
if (*div2 < chans)
*div2 = chans;
*tim2 = *div1 * I8254_OSC_BASE_4MHZ;
if (cmd->convert_src == TRIG_NOW && !chnsshfront) {
if (*div2 < (chans + 2))
*div2 = chans + 2;
}
*tim1 = *div1 * *div2 * I8254_OSC_BASE_4MHZ;
break;
}
}
static void pci9118_start_pacer(struct comedi_device *dev, int mode)
{
struct pci9118_private *devpriv = dev->private;
unsigned int divisor1 = devpriv->ai_divisor1;
unsigned int divisor2 = devpriv->ai_divisor2;
outl(0x74, dev->iobase + PCI9118_CNTCTRL);
outl(0xb4, dev->iobase + PCI9118_CNTCTRL);
udelay(1);
if ((mode == 1) || (mode == 2) || (mode == 4)) {
outl(divisor2 & 0xff, dev->iobase + PCI9118_CNT2);
outl((divisor2 >> 8) & 0xff, dev->iobase + PCI9118_CNT2);
outl(divisor1 & 0xff, dev->iobase + PCI9118_CNT1);
outl((divisor1 >> 8) & 0xff, dev->iobase + PCI9118_CNT1);
}
}
static int pci9118_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci9118_private *devpriv = dev->private;
if (devpriv->usedma)
outl(inl(devpriv->iobase_a + AMCC_OP_REG_MCSR) &
(~EN_A2P_TRANSFERS),
devpriv->iobase_a + AMCC_OP_REG_MCSR);
pci9118_exttrg_del(dev, EXTTRG_AI);
pci9118_start_pacer(dev, 0);
devpriv->AdFunctionReg = AdFunction_PDTrg | AdFunction_PETrg;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
devpriv->AdControlReg = 0x00;
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
outl(0, dev->iobase + PCI9118_BURST);
outl(1, dev->iobase + PCI9118_SCANMOD);
outl(2, dev->iobase + PCI9118_SCANMOD);
outl(0, dev->iobase + PCI9118_DELFIFO);
devpriv->ai_do = 0;
devpriv->usedma = 0;
devpriv->ai_act_scan = 0;
devpriv->ai_act_dmapos = 0;
s->async->cur_chan = 0;
s->async->inttrig = NULL;
devpriv->ai_neverending = 0;
devpriv->dma_actbuf = 0;
if (!devpriv->IntControlReg)
outl(inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR) | 0x1f00,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
return 0;
}
static char pci9118_decode_error_status(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned char m)
{
struct pci9118_private *devpriv = dev->private;
if (m & 0x100) {
comedi_error(dev, "A/D FIFO Full status (Fatal Error!)");
devpriv->ai_maskerr &= ~0x100L;
}
if (m & 0x008) {
comedi_error(dev,
"A/D Burst Mode Overrun Status (Fatal Error!)");
devpriv->ai_maskerr &= ~0x008L;
}
if (m & 0x004) {
comedi_error(dev, "A/D Over Speed Status (Warning!)");
devpriv->ai_maskerr &= ~0x004L;
}
if (m & 0x002) {
comedi_error(dev, "A/D Overrun Status (Fatal Error!)");
devpriv->ai_maskerr &= ~0x002L;
}
if (m & devpriv->ai_maskharderr) {
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return 1;
}
return 0;
}
static void pci9118_ai_munge(struct comedi_device *dev,
struct comedi_subdevice *s, void *data,
unsigned int num_bytes,
unsigned int start_chan_index)
{
struct pci9118_private *devpriv = dev->private;
unsigned int i, num_samples = num_bytes / sizeof(short);
unsigned short *array = data;
for (i = 0; i < num_samples; i++) {
if (devpriv->usedma)
array[i] = be16_to_cpu(array[i]);
if (s->maxdata == 0xffff)
array[i] ^= 0x8000;
else
array[i] = (array[i] >> 4) & 0x0fff;
}
}
static void interrupt_pci9118_ai_onesample(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short int_adstat,
unsigned int int_amcc,
unsigned short int_daq)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned short sampl;
if (int_adstat & devpriv->ai_maskerr)
if (pci9118_decode_error_status(dev, s, int_adstat))
return;
sampl = inw(dev->iobase + PCI9118_AD_DATA);
#ifdef PCI9118_PARANOIDCHECK
if (s->maxdata != 0xffff) {
if ((sampl & 0x000f) != devpriv->chanlist[s->async->cur_chan]) {
dev_info(dev->class_dev,
"A/D SAMPL - data dropout: received channel %d, expected %d!\n",
sampl & 0x000f,
devpriv->chanlist[s->async->cur_chan]);
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return;
}
}
#endif
cfc_write_to_buffer(s, sampl);
s->async->cur_chan++;
if (s->async->cur_chan >= cmd->scan_end_arg) {
s->async->cur_chan %= cmd->scan_end_arg;
devpriv->ai_act_scan++;
if (!devpriv->ai_neverending) {
if (devpriv->ai_act_scan >= cmd->stop_arg)
s->async->events |= COMEDI_CB_EOA;
}
}
cfc_handle_events(dev, s);
}
static void interrupt_pci9118_ai_dma(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short int_adstat,
unsigned int int_amcc,
unsigned short int_daq)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int next_dma_buf, samplesinbuf, sampls, m;
if (int_amcc & MASTER_ABORT_INT) {
comedi_error(dev, "AMCC IRQ - MASTER DMA ABORT!");
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return;
}
if (int_amcc & TARGET_ABORT_INT) {
comedi_error(dev, "AMCC IRQ - TARGET DMA ABORT!");
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return;
}
if (int_adstat & devpriv->ai_maskerr)
if (pci9118_decode_error_status(dev, s, int_adstat))
return;
samplesinbuf = devpriv->dmabuf_use_size[devpriv->dma_actbuf] >> 1;
if (devpriv->dma_doublebuf) {
next_dma_buf = 1 - devpriv->dma_actbuf;
outl(devpriv->dmabuf_hw[next_dma_buf],
devpriv->iobase_a + AMCC_OP_REG_MWAR);
outl(devpriv->dmabuf_use_size[next_dma_buf],
devpriv->iobase_a + AMCC_OP_REG_MWTC);
devpriv->dmabuf_used_size[next_dma_buf] =
devpriv->dmabuf_use_size[next_dma_buf];
if (devpriv->ai_do == 4)
interrupt_pci9118_ai_mode4_switch(dev);
}
if (samplesinbuf) {
m = s->async->prealloc_bufsz >> 1;
sampls = m;
move_block_from_dma(dev, s,
devpriv->dmabuf_virt[devpriv->dma_actbuf],
samplesinbuf);
m = m - sampls;
}
if (!devpriv->ai_neverending) {
if (devpriv->ai_act_scan >= cmd->stop_arg)
s->async->events |= COMEDI_CB_EOA;
}
if (devpriv->dma_doublebuf) {
devpriv->dma_actbuf = 1 - devpriv->dma_actbuf;
} else {
outl(devpriv->dmabuf_hw[0],
devpriv->iobase_a + AMCC_OP_REG_MWAR);
outl(devpriv->dmabuf_use_size[0],
devpriv->iobase_a + AMCC_OP_REG_MWTC);
if (devpriv->ai_do == 4)
interrupt_pci9118_ai_mode4_switch(dev);
}
cfc_handle_events(dev, s);
}
static irqreturn_t pci9118_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct pci9118_private *devpriv = dev->private;
unsigned int intsrc;
unsigned int intcsr;
unsigned int adstat;
if (!dev->attached)
return IRQ_NONE;
intsrc = inl(dev->iobase + PCI9118_INTSRC) & 0xf;
intcsr = inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR);
if (!intsrc && !(intcsr & ANY_S593X_INT))
return IRQ_NONE;
outl(intcsr | 0x00ff0000, devpriv->iobase_a + AMCC_OP_REG_INTCSR);
adstat = inw(dev->iobase + PCI9118_ADSTAT) & 0x1ff;
if (!devpriv->ai_do)
return IRQ_HANDLED;
if (devpriv->ai12_startstop) {
if ((adstat & AdStatus_DTH) && (intsrc & Int_DTrg)) {
if (devpriv->ai12_startstop & START_AI_EXT) {
devpriv->ai12_startstop &= ~START_AI_EXT;
if (!(devpriv->ai12_startstop & STOP_AI_EXT))
pci9118_exttrg_del(dev, EXTTRG_AI);
pci9118_start_pacer(dev, devpriv->ai_do);
outl(devpriv->AdControlReg,
dev->iobase + PCI9118_ADCNTRL);
} else if (devpriv->ai12_startstop & STOP_AI_EXT) {
devpriv->ai12_startstop &= ~STOP_AI_EXT;
pci9118_exttrg_del(dev, EXTTRG_AI);
devpriv->ai_neverending = 0;
}
}
}
if (devpriv->usedma)
interrupt_pci9118_ai_dma(dev, s, adstat, intcsr, intsrc);
else
interrupt_pci9118_ai_onesample(dev, s, adstat, intcsr, intsrc);
return IRQ_HANDLED;
}
static int pci9118_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
devpriv->ai12_startstop &= ~START_AI_INT;
s->async->inttrig = NULL;
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
if (devpriv->ai_do != 3) {
pci9118_start_pacer(dev, devpriv->ai_do);
devpriv->AdControlReg |= AdControl_SoftG;
}
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
return 1;
}
static int pci9118_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct boardtype *this_board = comedi_board(dev);
struct pci9118_private *devpriv = dev->private;
int err = 0;
unsigned int flags;
unsigned int arg;
unsigned int divisor1 = 0, divisor2 = 0;
err |= cfc_check_trigger_src(&cmd->start_src,
TRIG_NOW | TRIG_EXT | TRIG_INT);
flags = TRIG_FOLLOW;
if (devpriv->master)
flags |= TRIG_TIMER | TRIG_EXT;
err |= cfc_check_trigger_src(&cmd->scan_begin_src, flags);
flags = TRIG_TIMER | TRIG_EXT;
if (devpriv->master)
flags |= TRIG_NOW;
err |= cfc_check_trigger_src(&cmd->convert_src, flags);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src,
TRIG_COUNT | TRIG_NONE | TRIG_EXT);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->start_src == TRIG_EXT && cmd->scan_begin_src == TRIG_EXT)
err |= -EINVAL;
if (cmd->start_src == TRIG_INT && cmd->scan_begin_src == TRIG_INT)
err |= -EINVAL;
if ((cmd->scan_begin_src & (TRIG_TIMER | TRIG_EXT)) &&
(!(cmd->convert_src & (TRIG_TIMER | TRIG_NOW))))
err |= -EINVAL;
if ((cmd->scan_begin_src == TRIG_FOLLOW) &&
(!(cmd->convert_src & (TRIG_TIMER | TRIG_EXT))))
err |= -EINVAL;
if (cmd->stop_src == TRIG_EXT && cmd->scan_begin_src == TRIG_EXT)
err |= -EINVAL;
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
case TRIG_EXT:
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_INT:
break;
}
if (cmd->scan_begin_src & (TRIG_FOLLOW | TRIG_EXT))
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if ((cmd->scan_begin_src == TRIG_TIMER) &&
(cmd->convert_src == TRIG_TIMER) && (cmd->scan_end_arg == 1)) {
cmd->scan_begin_src = TRIG_FOLLOW;
cmd->convert_arg = cmd->scan_begin_arg;
cmd->scan_begin_arg = 0;
}
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
this_board->ai_ns_min);
if (cmd->scan_begin_src == TRIG_EXT)
if (cmd->scan_begin_arg) {
cmd->scan_begin_arg = 0;
err |= -EINVAL;
err |= cfc_check_trigger_arg_max(&cmd->scan_end_arg,
65535);
}
if (cmd->convert_src & (TRIG_TIMER | TRIG_NOW))
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
this_board->ai_ns_min);
if (cmd->convert_src == TRIG_EXT)
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_min(&cmd->scan_end_arg,
cmd->chanlist_len);
if ((cmd->scan_end_arg % cmd->chanlist_len)) {
cmd->scan_end_arg =
cmd->chanlist_len * (cmd->scan_end_arg / cmd->chanlist_len);
err |= -EINVAL;
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_4MHZ,
&divisor1, &divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src & (TRIG_TIMER | TRIG_NOW)) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_4MHZ,
&divisor1, &divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->convert_src == TRIG_NOW) {
if (cmd->convert_arg == 0) {
arg = this_board->ai_ns_min *
(cmd->scan_end_arg + 2);
} else {
arg = cmd->convert_arg * cmd->chanlist_len;
}
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
arg);
}
}
if (err)
return 4;
if (cmd->chanlist)
if (!check_channel_list(dev, s, cmd->chanlist_len,
cmd->chanlist, 0, 0))
return 5;
return 0;
}
static int Compute_and_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int dmalen0, dmalen1, i;
dmalen0 = devpriv->dmabuf_size[0];
dmalen1 = devpriv->dmabuf_size[1];
if (dmalen0 > s->async->prealloc_bufsz) {
dmalen0 = s->async->prealloc_bufsz & ~3L;
}
if (dmalen1 > s->async->prealloc_bufsz) {
dmalen1 = s->async->prealloc_bufsz & ~3L;
}
if (devpriv->ai_flags & TRIG_WAKE_EOS) {
if (dmalen0 < (devpriv->ai_n_realscanlen << 1)) {
devpriv->ai_flags &= (~TRIG_WAKE_EOS);
dev_info(dev->class_dev,
"WAR: DMA0 buf too short, can't support TRIG_WAKE_EOS (%d<%d)\n",
dmalen0, devpriv->ai_n_realscanlen << 1);
} else {
dmalen0 = devpriv->ai_n_realscanlen << 1;
if (dmalen0 < 4) {
dev_info(dev->class_dev,
"ERR: DMA0 buf len bug? (%d<4)\n",
dmalen0);
dmalen0 = 4;
}
}
}
if (devpriv->ai_flags & TRIG_WAKE_EOS) {
if (dmalen1 < (devpriv->ai_n_realscanlen << 1)) {
devpriv->ai_flags &= (~TRIG_WAKE_EOS);
dev_info(dev->class_dev,
"WAR: DMA1 buf too short, can't support TRIG_WAKE_EOS (%d<%d)\n",
dmalen1, devpriv->ai_n_realscanlen << 1);
} else {
dmalen1 = devpriv->ai_n_realscanlen << 1;
if (dmalen1 < 4) {
dev_info(dev->class_dev,
"ERR: DMA1 buf len bug? (%d<4)\n",
dmalen1);
dmalen1 = 4;
}
}
}
if (!(devpriv->ai_flags & TRIG_WAKE_EOS)) {
i = dmalen0;
dmalen0 =
(dmalen0 / (devpriv->ai_n_realscanlen << 1)) *
(devpriv->ai_n_realscanlen << 1);
dmalen0 &= ~3L;
if (!dmalen0)
dmalen0 = i;
i = dmalen1;
dmalen1 =
(dmalen1 / (devpriv->ai_n_realscanlen << 1)) *
(devpriv->ai_n_realscanlen << 1);
dmalen1 &= ~3L;
if (!dmalen1)
dmalen1 = i;
if (!devpriv->ai_neverending) {
if (dmalen0 >
((devpriv->ai_n_realscanlen << 1) *
cmd->stop_arg)) {
dmalen0 =
(devpriv->ai_n_realscanlen << 1) *
cmd->stop_arg;
dmalen0 &= ~3L;
} else {
if (dmalen1 >
((devpriv->ai_n_realscanlen << 1) *
cmd->stop_arg - dmalen0))
dmalen1 =
(devpriv->ai_n_realscanlen << 1) *
cmd->stop_arg - dmalen0;
dmalen1 &= ~3L;
}
}
}
devpriv->dma_actbuf = 0;
devpriv->dmabuf_use_size[0] = dmalen0;
devpriv->dmabuf_use_size[1] = dmalen1;
#if 0
if (cmd->scan_end_arg < this_board->half_fifo_size) {
devpriv->dmabuf_panic_size[0] =
(this_board->half_fifo_size / cmd->scan_end_arg +
1) * cmd->scan_end_arg * sizeof(short);
devpriv->dmabuf_panic_size[1] =
(this_board->half_fifo_size / cmd->scan_end_arg +
1) * cmd->scan_end_arg * sizeof(short);
} else {
devpriv->dmabuf_panic_size[0] =
(cmd->scan_end_arg << 1) % devpriv->dmabuf_size[0];
devpriv->dmabuf_panic_size[1] =
(cmd->scan_end_arg << 1) % devpriv->dmabuf_size[1];
}
#endif
outl(inl(devpriv->iobase_a + AMCC_OP_REG_MCSR) & (~EN_A2P_TRANSFERS),
devpriv->iobase_a + AMCC_OP_REG_MCSR);
outl(devpriv->dmabuf_hw[0], devpriv->iobase_a + AMCC_OP_REG_MWAR);
outl(devpriv->dmabuf_use_size[0], devpriv->iobase_a + AMCC_OP_REG_MWTC);
outl(0x00000000 | AINT_WRITE_COMPL,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
outl(inl(devpriv->iobase_a +
AMCC_OP_REG_MCSR) | RESET_A2P_FLAGS | A2P_HI_PRIORITY |
EN_A2P_TRANSFERS, devpriv->iobase_a + AMCC_OP_REG_MCSR);
outl(inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR) | EN_A2P_TRANSFERS,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
return 0;
}
static int pci9118_ai_docmd_sampl(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci9118_private *devpriv = dev->private;
switch (devpriv->ai_do) {
case 1:
devpriv->AdControlReg |= AdControl_TmrTr;
break;
case 2:
comedi_error(dev, "pci9118_ai_docmd_sampl() mode 2 bug!\n");
return -EIO;
case 3:
devpriv->AdControlReg |= AdControl_ExtM;
break;
case 4:
comedi_error(dev, "pci9118_ai_docmd_sampl() mode 4 bug!\n");
return -EIO;
default:
comedi_error(dev,
"pci9118_ai_docmd_sampl() mode number bug!\n");
return -EIO;
}
if (devpriv->ai12_startstop)
pci9118_exttrg_add(dev, EXTTRG_AI);
if ((devpriv->ai_do == 1) || (devpriv->ai_do == 2))
devpriv->IntControlReg |= Int_Timer;
devpriv->AdControlReg |= AdControl_Int;
outl(inl(devpriv->iobase_a + AMCC_OP_REG_INTCSR) | 0x1f00,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
if (!(devpriv->ai12_startstop & (START_AI_EXT | START_AI_INT))) {
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
if (devpriv->ai_do != 3) {
pci9118_start_pacer(dev, devpriv->ai_do);
devpriv->AdControlReg |= AdControl_SoftG;
}
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
}
return 0;
}
static int pci9118_ai_docmd_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
Compute_and_setup_dma(dev, s);
switch (devpriv->ai_do) {
case 1:
devpriv->AdControlReg |=
((AdControl_TmrTr | AdControl_Dma) & 0xff);
break;
case 2:
devpriv->AdControlReg |=
((AdControl_TmrTr | AdControl_Dma) & 0xff);
devpriv->AdFunctionReg =
AdFunction_PDTrg | AdFunction_PETrg | AdFunction_BM |
AdFunction_BS;
if (cmd->convert_src == TRIG_NOW && !devpriv->softsshdelay)
devpriv->AdFunctionReg |= AdFunction_BSSH;
outl(devpriv->ai_n_realscanlen, dev->iobase + PCI9118_BURST);
break;
case 3:
devpriv->AdControlReg |=
((AdControl_ExtM | AdControl_Dma) & 0xff);
devpriv->AdFunctionReg = AdFunction_PDTrg | AdFunction_PETrg;
break;
case 4:
devpriv->AdControlReg |=
((AdControl_TmrTr | AdControl_Dma) & 0xff);
devpriv->AdFunctionReg =
AdFunction_PDTrg | AdFunction_PETrg | AdFunction_AM;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
outl(0x30, dev->iobase + PCI9118_CNTCTRL);
outl((devpriv->dmabuf_hw[0] >> 1) & 0xff,
dev->iobase + PCI9118_CNT0);
outl((devpriv->dmabuf_hw[0] >> 9) & 0xff,
dev->iobase + PCI9118_CNT0);
devpriv->AdFunctionReg |= AdFunction_Start;
break;
default:
comedi_error(dev, "pci9118_ai_docmd_dma() mode number bug!\n");
return -EIO;
}
if (devpriv->ai12_startstop) {
pci9118_exttrg_add(dev, EXTTRG_AI);
}
outl(0x02000000 | AINT_WRITE_COMPL,
devpriv->iobase_a + AMCC_OP_REG_INTCSR);
if (!(devpriv->ai12_startstop & (START_AI_EXT | START_AI_INT))) {
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
if (devpriv->ai_do != 3) {
pci9118_start_pacer(dev, devpriv->ai_do);
devpriv->AdControlReg |= AdControl_SoftG;
}
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
}
return 0;
}
static int pci9118_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct boardtype *this_board = comedi_board(dev);
struct pci9118_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int addchans = 0;
int ret = 0;
devpriv->ai12_startstop = 0;
devpriv->ai_flags = cmd->flags;
devpriv->ai_add_front = 0;
devpriv->ai_add_back = 0;
devpriv->ai_maskerr = 0x10e;
if (cmd->start_src == TRIG_EXT)
devpriv->ai12_startstop |= START_AI_EXT;
if (cmd->stop_src == TRIG_EXT) {
devpriv->ai_neverending = 1;
devpriv->ai12_startstop |= STOP_AI_EXT;
}
if (cmd->start_src == TRIG_INT) {
devpriv->ai12_startstop |= START_AI_INT;
s->async->inttrig = pci9118_ai_inttrig;
}
if (cmd->stop_src == TRIG_NONE)
devpriv->ai_neverending = 1;
if (cmd->stop_src == TRIG_COUNT)
devpriv->ai_neverending = 0;
devpriv->ai_add_front = 0;
devpriv->ai_add_back = 0;
if (devpriv->master) {
devpriv->usedma = 1;
if ((cmd->flags & TRIG_WAKE_EOS) &&
(cmd->scan_end_arg == 1)) {
if (cmd->convert_src == TRIG_NOW)
devpriv->ai_add_back = 1;
if (cmd->convert_src == TRIG_TIMER) {
devpriv->usedma = 0;
}
}
if ((cmd->flags & TRIG_WAKE_EOS) &&
(cmd->scan_end_arg & 1) &&
(cmd->scan_end_arg > 1)) {
if (cmd->scan_begin_src == TRIG_FOLLOW) {
devpriv->usedma = 0;
} else {
devpriv->ai_add_back = 1;
}
}
} else {
devpriv->usedma = 0;
}
if (cmd->convert_src == TRIG_NOW && devpriv->softsshdelay) {
devpriv->ai_add_front = 2;
if ((devpriv->usedma == 1) && (devpriv->ai_add_back == 1)) {
devpriv->ai_add_front++;
devpriv->ai_add_back = 0;
}
if (cmd->convert_arg < this_board->ai_ns_min)
cmd->convert_arg = this_board->ai_ns_min;
addchans = devpriv->softsshdelay / cmd->convert_arg;
if (devpriv->softsshdelay % cmd->convert_arg)
addchans++;
if (addchans > (devpriv->ai_add_front - 1)) {
devpriv->ai_add_front = addchans + 1;
if (devpriv->usedma == 1)
if ((devpriv->ai_add_front +
cmd->chanlist_len +
devpriv->ai_add_back) & 1)
devpriv->ai_add_front++;
}
}
devpriv->ai_n_realscanlen =
(devpriv->ai_add_front + cmd->chanlist_len +
devpriv->ai_add_back) * (cmd->scan_end_arg /
cmd->chanlist_len);
if (!check_channel_list(dev, s, cmd->chanlist_len,
cmd->chanlist, devpriv->ai_add_front,
devpriv->ai_add_back))
return -EINVAL;
if (!setup_channel_list(dev, s, cmd->chanlist_len,
cmd->chanlist, 0, devpriv->ai_add_front,
devpriv->ai_add_back, devpriv->usedma))
return -EINVAL;
if (((cmd->scan_begin_src == TRIG_FOLLOW) ||
(cmd->scan_begin_src == TRIG_EXT) ||
(cmd->scan_begin_src == TRIG_INT)) &&
(cmd->convert_src == TRIG_TIMER)) {
if (cmd->scan_begin_src == TRIG_EXT)
devpriv->ai_do = 4;
else
devpriv->ai_do = 1;
pci9118_calc_divisors(devpriv->ai_do, dev, s,
&cmd->scan_begin_arg, &cmd->convert_arg,
devpriv->ai_flags,
devpriv->ai_n_realscanlen,
&devpriv->ai_divisor1,
&devpriv->ai_divisor2,
devpriv->ai_add_front);
}
if ((cmd->scan_begin_src == TRIG_TIMER) &&
((cmd->convert_src == TRIG_TIMER) ||
(cmd->convert_src == TRIG_NOW))) {
if (!devpriv->usedma) {
comedi_error(dev,
"cmd->scan_begin_src=TRIG_TIMER works "
"only with bus mastering!");
return -EIO;
}
devpriv->ai_do = 2;
pci9118_calc_divisors(devpriv->ai_do, dev, s,
&cmd->scan_begin_arg, &cmd->convert_arg,
devpriv->ai_flags,
devpriv->ai_n_realscanlen,
&devpriv->ai_divisor1,
&devpriv->ai_divisor2,
devpriv->ai_add_front);
}
if ((cmd->scan_begin_src == TRIG_FOLLOW)
&& (cmd->convert_src == TRIG_EXT)) {
devpriv->ai_do = 3;
}
pci9118_start_pacer(dev, -1);
devpriv->AdControlReg = 0;
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
devpriv->AdFunctionReg = AdFunction_PDTrg | AdFunction_PETrg;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
udelay(1);
outl(0, dev->iobase + PCI9118_DELFIFO);
inl(dev->iobase + PCI9118_ADSTAT);
inl(dev->iobase + PCI9118_INTSRC);
devpriv->ai_act_scan = 0;
devpriv->ai_act_dmapos = 0;
s->async->cur_chan = 0;
if (devpriv->usedma)
ret = pci9118_ai_docmd_dma(dev, s);
else
ret = pci9118_ai_docmd_sampl(dev, s);
return ret;
}
static int pci9118_reset(struct comedi_device *dev)
{
struct pci9118_private *devpriv = dev->private;
devpriv->IntControlReg = 0;
devpriv->exttrg_users = 0;
inl(dev->iobase + PCI9118_INTCTRL);
outl(devpriv->IntControlReg, dev->iobase + PCI9118_INTCTRL);
outl(0x30, dev->iobase + PCI9118_CNTCTRL);
pci9118_start_pacer(dev, 0);
devpriv->AdControlReg = 0;
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
outl(0, dev->iobase + PCI9118_BURST);
outl(1, dev->iobase + PCI9118_SCANMOD);
outl(2, dev->iobase + PCI9118_SCANMOD);
devpriv->AdFunctionReg = AdFunction_PDTrg | AdFunction_PETrg;
outl(devpriv->AdFunctionReg, dev->iobase + PCI9118_ADFUNC);
devpriv->ao_data[0] = 2047;
devpriv->ao_data[1] = 2047;
outl(devpriv->ao_data[0], dev->iobase + PCI9118_DA1);
outl(devpriv->ao_data[1], dev->iobase + PCI9118_DA2);
outl(0, dev->iobase + PCI9118_DO);
udelay(10);
inl(dev->iobase + PCI9118_AD_DATA);
outl(0, dev->iobase + PCI9118_DELFIFO);
outl(0, dev->iobase + PCI9118_INTSRC);
inl(dev->iobase + PCI9118_ADSTAT);
inl(dev->iobase + PCI9118_INTSRC);
devpriv->AdControlReg = 0;
outl(devpriv->AdControlReg, dev->iobase + PCI9118_ADCNTRL);
devpriv->exttrg_users = 0;
return 0;
}
static const struct boardtype *pci9118_find_boardinfo(struct pci_dev *pcidev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(boardtypes); i++)
if (pcidev->device == boardtypes[i].device_id)
return &boardtypes[i];
return NULL;
}
static struct pci_dev *pci9118_find_pci(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct boardtype *this_board = comedi_board(dev);
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_AMCC)
continue;
if (pcidev->device != this_board->device_id)
continue;
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot)
continue;
}
return pcidev;
}
dev_err(dev->class_dev,
"no supported board found! (req. bus/slot : %d/%d)\n",
bus, slot);
return NULL;
}
static int pci9118_common_attach(struct comedi_device *dev, int disable_irq,
int master, int ext_mux, int softsshdelay,
int hw_err_mask)
{
const struct boardtype *this_board = comedi_board(dev);
struct pci9118_private *devpriv = dev->private;
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret, pages, i;
u16 u16w;
dev->board_name = this_board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
if (master)
pci_set_master(pcidev);
devpriv->iobase_a = pci_resource_start(pcidev, 0);
dev->iobase = pci_resource_start(pcidev, 2);
pci9118_reset(dev);
if (master) {
devpriv->dma_doublebuf = 0;
for (i = 0; i < 2; i++) {
for (pages = 4; pages >= 0; pages--) {
devpriv->dmabuf_virt[i] =
(unsigned short *)
__get_free_pages(GFP_KERNEL, pages);
if (devpriv->dmabuf_virt[i])
break;
}
if (devpriv->dmabuf_virt[i]) {
devpriv->dmabuf_pages[i] = pages;
devpriv->dmabuf_size[i] = PAGE_SIZE * pages;
devpriv->dmabuf_hw[i] =
virt_to_bus((void *)
devpriv->dmabuf_virt[i]);
}
}
if (!devpriv->dmabuf_virt[0]) {
dev_warn(dev->class_dev,
"Can't allocate DMA buffer, DMA disabled!\n");
master = 0;
}
if (devpriv->dmabuf_virt[1])
devpriv->dma_doublebuf = 1;
}
devpriv->master = master;
if (ext_mux > 0) {
if (ext_mux > 256)
ext_mux = 256;
if (softsshdelay > 0)
if (ext_mux > 128)
ext_mux = 128;
devpriv->usemux = ext_mux;
} else {
devpriv->usemux = 0;
}
if (softsshdelay < 0) {
devpriv->softsshdelay = -softsshdelay;
devpriv->softsshsample = 0x80;
devpriv->softsshhold = 0x00;
} else {
devpriv->softsshdelay = softsshdelay;
devpriv->softsshsample = 0x00;
devpriv->softsshhold = 0x80;
}
pci_read_config_word(pcidev, PCI_COMMAND, &u16w);
pci_write_config_word(pcidev, PCI_COMMAND, u16w | 64);
if (!disable_irq && pcidev->irq) {
ret = request_irq(pcidev->irq, pci9118_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_GROUND | SDF_DIFF;
if (devpriv->usemux)
s->n_chan = devpriv->usemux;
else
s->n_chan = this_board->n_aichan;
s->maxdata = this_board->ai_maxdata;
s->range_table = this_board->rangelist_ai;
s->insn_read = pci9118_insn_read_ai;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = this_board->n_aichanlist;
s->do_cmdtest = pci9118_ai_cmdtest;
s->do_cmd = pci9118_ai_cmd;
s->cancel = pci9118_ai_cancel;
s->munge = pci9118_ai_munge;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = this_board->n_aochan;
s->maxdata = this_board->ao_maxdata;
s->len_chanlist = this_board->n_aochan;
s->range_table = this_board->rangelist_ao;
s->insn_write = pci9118_insn_write_ao;
s->insn_read = pci9118_insn_read_ao;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 1;
s->len_chanlist = 4;
s->range_table = &range_digital;
s->insn_bits = pci9118_insn_bits_di;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 1;
s->len_chanlist = 4;
s->range_table = &range_digital;
s->insn_bits = pci9118_insn_bits_do;
devpriv->ai_maskharderr = 0x10a;
if (hw_err_mask)
devpriv->ai_maskharderr &= ~hw_err_mask;
return 0;
}
static int pci9118_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci9118_private *devpriv;
struct pci_dev *pcidev;
int ext_mux, disable_irq, master, softsshdelay, hw_err_mask;
ext_mux = it->options[2];
master = ((it->options[3] & 1) == 0);
disable_irq = ((it->options[3] & 2) != 0);
softsshdelay = it->options[4];
hw_err_mask = it->options[5];
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
pcidev = pci9118_find_pci(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
return pci9118_common_attach(dev, disable_irq, master, ext_mux,
softsshdelay, hw_err_mask);
}
static int pci9118_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct pci9118_private *devpriv;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
dev->board_ptr = pci9118_find_boardinfo(pcidev);
if (dev->board_ptr == NULL) {
dev_err(dev->class_dev,
"adl_pci9118: cannot determine board type for pci %s\n",
pci_name(pcidev));
return -EINVAL;
}
pci_dev_get(pcidev);
return pci9118_common_attach(dev, 0, 1, 0, 0, 0);
}
static void pci9118_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct pci9118_private *devpriv = dev->private;
if (devpriv) {
if (dev->iobase)
pci9118_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv->dmabuf_virt[0])
free_pages((unsigned long)devpriv->dmabuf_virt[0],
devpriv->dmabuf_pages[0]);
if (devpriv->dmabuf_virt[1])
free_pages((unsigned long)devpriv->dmabuf_virt[1],
devpriv->dmabuf_pages[1]);
}
comedi_pci_disable(dev);
if (pcidev)
pci_dev_put(pcidev);
}
static int adl_pci9118_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adl_pci9118_driver,
id->driver_data);
}
