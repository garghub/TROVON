static int pci171x_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct pci1710_private *devpriv = dev->private;
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int last_aref = CR_AREF(cmd->chanlist[0]);
unsigned int next_chan = (chan0 + 1) % s->n_chan;
unsigned int chansegment[32];
unsigned int seglen;
int i;
if (cmd->chanlist_len == 1) {
devpriv->saved_seglen = cmd->chanlist_len;
return 0;
}
chansegment[0] = cmd->chanlist[0];
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int aref = CR_AREF(cmd->chanlist[i]);
if (cmd->chanlist[0] == cmd->chanlist[i])
break;
if (aref == AREF_DIFF && (chan & 1)) {
dev_err(dev->class_dev,
"Odd channel cannot be differential input!\n");
return -EINVAL;
}
if (last_aref == AREF_DIFF)
next_chan = (next_chan + 1) % s->n_chan;
if (chan != next_chan) {
dev_err(dev->class_dev,
"channel list must be continuous! chanlist[%i]=%d but must be %d or %d!\n",
i, chan, next_chan, chan0);
return -EINVAL;
}
chansegment[i] = cmd->chanlist[i];
last_aref = aref;
}
seglen = i;
for (i = 0; i < cmd->chanlist_len; i++) {
if (cmd->chanlist[i] != chansegment[i % seglen]) {
dev_err(dev->class_dev,
"bad channel, reference or range number! chanlist[%i]=%d,%d,%d and not %d,%d,%d!\n",
i, CR_CHAN(chansegment[i]),
CR_RANGE(chansegment[i]),
CR_AREF(chansegment[i]),
CR_CHAN(cmd->chanlist[i % seglen]),
CR_RANGE(cmd->chanlist[i % seglen]),
CR_AREF(chansegment[i % seglen]));
return -EINVAL;
}
}
devpriv->saved_seglen = seglen;
return 0;
}
static void pci171x_ai_setup_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chanlist,
unsigned int n_chan,
unsigned int seglen)
{
const struct boardtype *board = dev->board_ptr;
struct pci1710_private *devpriv = dev->private;
unsigned int first_chan = CR_CHAN(chanlist[0]);
unsigned int last_chan = CR_CHAN(chanlist[seglen - 1]);
unsigned int i;
for (i = 0; i < seglen; i++) {
unsigned int chan = CR_CHAN(chanlist[i]);
unsigned int range = CR_RANGE(chanlist[i]);
unsigned int aref = CR_AREF(chanlist[i]);
unsigned int rangeval;
rangeval = board->rangecode_ai[range];
if (aref == AREF_DIFF)
rangeval |= 0x0020;
outw(chan | (chan << 8), dev->iobase + PCI171x_MUX);
outw(rangeval, dev->iobase + PCI171x_RANGE);
devpriv->act_chanlist[i] = chan;
}
for ( ; i < n_chan; i++)
devpriv->act_chanlist[i] = CR_CHAN(chanlist[i]);
devpriv->ai_et_MuxVal = first_chan | (last_chan << 8);
outw(devpriv->ai_et_MuxVal, dev->iobase + PCI171x_MUX);
}
static int pci171x_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + PCI171x_STATUS);
if ((status & Status_FE) == 0)
return 0;
return -EBUSY;
}
static int pci171x_ai_read_sample(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int cur_chan,
unsigned int *val)
{
const struct boardtype *board = dev->board_ptr;
struct pci1710_private *devpriv = dev->private;
unsigned int sample;
unsigned int chan;
sample = inw(dev->iobase + PCI171x_AD_DATA);
if (!board->is_pci1713) {
chan = sample >> 12;
if (chan != devpriv->act_chanlist[cur_chan]) {
dev_err(dev->class_dev,
"A/D data droput: received from channel %d, expected %d\n",
chan, devpriv->act_chanlist[cur_chan]);
return -ENODATA;
}
}
*val = sample & s->maxdata;
return 0;
}
static int pci171x_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci1710_private *devpriv = dev->private;
int ret = 0;
int i;
devpriv->CntrlReg &= Control_CNT0;
devpriv->CntrlReg |= Control_SW;
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
pci171x_ai_setup_chanlist(dev, s, &insn->chanspec, 1, 1);
for (i = 0; i < insn->n; i++) {
unsigned int val;
outw(0, dev->iobase + PCI171x_SOFTTRG);
ret = comedi_timeout(dev, s, insn, pci171x_ai_eoc, 0);
if (ret)
break;
ret = pci171x_ai_read_sample(dev, s, 0, &val);
if (ret)
break;
data[i] = val;
}
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
return ret ? ret : insn->n;
}
static int pci171x_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci1710_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int reg = chan ? PCI171x_DA2 : PCI171x_DA1;
unsigned int val = s->readback[chan];
int i;
devpriv->da_ranges &= ~(1 << (chan << 1));
devpriv->da_ranges |= (range << (chan << 1));
outw(devpriv->da_ranges, dev->iobase + PCI171x_DAREF);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + reg);
}
s->readback[chan] = val;
return insn->n;
}
static int pci171x_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inw(dev->iobase + PCI171x_DI);
return insn->n;
}
static int pci171x_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + PCI171x_DO);
data[1] = s->state;
return insn->n;
}
static void pci171x_start_pacer(struct comedi_device *dev,
bool load_counters)
{
struct pci1710_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + PCI171X_TIMER_BASE;
i8254_set_mode(timer_base, 1, 2, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 1, 1, I8254_MODE2 | I8254_BINARY);
if (load_counters) {
i8254_write(timer_base, 1, 2, devpriv->divisor2);
i8254_write(timer_base, 1, 1, devpriv->divisor1);
}
}
static int pci171x_counter_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int msb, lsb, ccntrl;
int i;
ccntrl = 0xD2;
for (i = 0; i < insn->n; i++) {
outw(ccntrl, dev->iobase + PCI171x_CNTCTRL);
lsb = inw(dev->iobase + PCI171x_CNT0) & 0xFF;
msb = inw(dev->iobase + PCI171x_CNT0) & 0xFF;
data[0] = lsb | (msb << 8);
}
return insn->n;
}
static int pci171x_counter_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci1710_private *devpriv = dev->private;
uint msb, lsb, ccntrl, status;
lsb = data[0] & 0x00FF;
msb = (data[0] & 0xFF00) >> 8;
outw(lsb, dev->iobase + PCI171x_CNT0);
outw(msb, dev->iobase + PCI171x_CNT0);
if (devpriv->cnt0_write_wait) {
ccntrl = 0xE2;
do {
outw(ccntrl, dev->iobase + PCI171x_CNTCTRL);
status = inw(dev->iobase + PCI171x_CNT0) & 0xFF;
} while (status & 0x40);
}
return insn->n;
}
static int pci171x_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
#ifdef unused
struct pci1710_private *devpriv = dev->private;
uint ccntrl = 0;
devpriv->cnt0_write_wait = data[0] & 0x20;
if (!(data[0] & 0x10)) {
devpriv->CntrlReg &= ~Control_CNT0;
} else {
devpriv->CntrlReg |= Control_CNT0;
}
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
if (data[0] & 0x01)
ccntrl |= Counter_M0;
if (data[0] & 0x02)
ccntrl |= Counter_M1;
if (data[0] & 0x04)
ccntrl |= Counter_M2;
if (data[0] & 0x08)
ccntrl |= Counter_BCD;
ccntrl |= Counter_RW0;
ccntrl |= Counter_RW1;
outw(ccntrl, dev->iobase + PCI171x_CNTCTRL);
#endif
return 1;
}
static int pci1720_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci1710_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int i;
val = devpriv->da_ranges & (~(0x03 << (chan << 1)));
val |= (range << (chan << 1));
if (val != devpriv->da_ranges) {
outb(val, dev->iobase + PCI1720_RANGE);
devpriv->da_ranges = val;
}
val = s->readback[chan];
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + PCI1720_DA0 + (chan << 1));
outb(0, dev->iobase + PCI1720_SYNCOUT);
}
s->readback[chan] = val;
return insn->n;
}
static int pci171x_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci1710_private *devpriv = dev->private;
devpriv->CntrlReg &= Control_CNT0;
devpriv->CntrlReg |= Control_SW;
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
pci171x_start_pacer(dev, false);
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
return 0;
}
static void pci1710_handle_every_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int status;
unsigned int val;
int ret;
status = inw(dev->iobase + PCI171x_STATUS);
if (status & Status_FE) {
dev_dbg(dev->class_dev, "A/D FIFO empty (%4x)\n", status);
s->async->events |= COMEDI_CB_ERROR;
return;
}
if (status & Status_FF) {
dev_dbg(dev->class_dev,
"A/D FIFO Full status (Fatal Error!) (%4x)\n", status);
s->async->events |= COMEDI_CB_ERROR;
return;
}
outb(0, dev->iobase + PCI171x_CLRINT);
for (; !(inw(dev->iobase + PCI171x_STATUS) & Status_FE);) {
ret = pci171x_ai_read_sample(dev, s, s->async->cur_chan, &val);
if (ret) {
s->async->events |= COMEDI_CB_ERROR;
break;
}
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg) {
s->async->events |= COMEDI_CB_EOA;
break;
}
}
outb(0, dev->iobase + PCI171x_CLRINT);
}
static void pci1710_handle_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci1710_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status;
int i;
status = inw(dev->iobase + PCI171x_STATUS);
if (!(status & Status_FH)) {
dev_dbg(dev->class_dev, "A/D FIFO not half full!\n");
async->events |= COMEDI_CB_ERROR;
return;
}
if (status & Status_FF) {
dev_dbg(dev->class_dev,
"A/D FIFO Full status (Fatal Error!)\n");
async->events |= COMEDI_CB_ERROR;
return;
}
for (i = 0; i < devpriv->max_samples; i++) {
unsigned int val;
int ret;
ret = pci171x_ai_read_sample(dev, s, s->async->cur_chan, &val);
if (ret) {
s->async->events |= COMEDI_CB_ERROR;
break;
}
if (!comedi_buf_write_samples(s, &val, 1))
break;
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
break;
}
}
outb(0, dev->iobase + PCI171x_CLRINT);
}
static irqreturn_t interrupt_service_pci1710(int irq, void *d)
{
struct comedi_device *dev = d;
struct pci1710_private *devpriv = dev->private;
struct comedi_subdevice *s;
struct comedi_cmd *cmd;
if (!dev->attached)
return IRQ_NONE;
s = dev->read_subdev;
cmd = &s->async->cmd;
if (!(inw(dev->iobase + PCI171x_STATUS) & Status_IRQ))
return IRQ_NONE;
if (devpriv->ai_et) {
devpriv->ai_et = 0;
devpriv->CntrlReg &= Control_CNT0;
devpriv->CntrlReg |= Control_SW;
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
devpriv->CntrlReg = devpriv->ai_et_CntrlReg;
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
outw(devpriv->ai_et_MuxVal, dev->iobase + PCI171x_MUX);
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
pci171x_start_pacer(dev, true);
return IRQ_HANDLED;
}
if (cmd->flags & CMDF_WAKE_EOS)
pci1710_handle_every_sample(dev, s);
else
pci1710_handle_fifo(dev, s);
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int pci171x_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pci1710_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
pci171x_start_pacer(dev, false);
pci171x_ai_setup_chanlist(dev, s, cmd->chanlist, cmd->chanlist_len,
devpriv->saved_seglen);
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
devpriv->CntrlReg &= Control_CNT0;
if ((cmd->flags & CMDF_WAKE_EOS) == 0)
devpriv->CntrlReg |= Control_ONEFH;
devpriv->divisor1 = devpriv->next_divisor1;
devpriv->divisor2 = devpriv->next_divisor2;
if (cmd->convert_src == TRIG_TIMER) {
devpriv->CntrlReg |= Control_PACER | Control_IRQEN;
if (cmd->start_src == TRIG_EXT) {
devpriv->ai_et_CntrlReg = devpriv->CntrlReg;
devpriv->CntrlReg &=
~(Control_PACER | Control_ONEFH | Control_GATE);
devpriv->CntrlReg |= Control_EXT;
devpriv->ai_et = 1;
} else {
devpriv->ai_et = 0;
}
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
if (cmd->start_src == TRIG_NOW)
pci171x_start_pacer(dev, true);
} else {
devpriv->CntrlReg |= Control_EXT | Control_IRQEN;
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
}
return 0;
}
static int pci171x_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct pci1710_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, 10000);
else
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->next_divisor1,
&devpriv->next_divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
err |= pci171x_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int pci171x_reset(struct comedi_device *dev)
{
const struct boardtype *board = dev->board_ptr;
struct pci1710_private *devpriv = dev->private;
outw(0x30, dev->iobase + PCI171x_CNTCTRL);
devpriv->CntrlReg = Control_SW | Control_CNT0;
outw(devpriv->CntrlReg, dev->iobase + PCI171x_CONTROL);
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
pci171x_start_pacer(dev, false);
devpriv->da_ranges = 0;
if (board->has_ao) {
outb(devpriv->da_ranges, dev->iobase + PCI171x_DAREF);
outw(0, dev->iobase + PCI171x_DA1);
outw(0, dev->iobase + PCI171x_DA2);
}
outw(0, dev->iobase + PCI171x_DO);
outb(0, dev->iobase + PCI171x_CLRFIFO);
outb(0, dev->iobase + PCI171x_CLRINT);
return 0;
}
static int pci1720_reset(struct comedi_device *dev)
{
struct pci1710_private *devpriv = dev->private;
outb(Syncont_SC0, dev->iobase + PCI1720_SYNCONT);
devpriv->da_ranges = 0xAA;
outb(devpriv->da_ranges, dev->iobase + PCI1720_RANGE);
outw(0x0800, dev->iobase + PCI1720_DA0);
outw(0x0800, dev->iobase + PCI1720_DA1);
outw(0x0800, dev->iobase + PCI1720_DA2);
outw(0x0800, dev->iobase + PCI1720_DA3);
outb(0, dev->iobase + PCI1720_SYNCOUT);
return 0;
}
static int pci1710_reset(struct comedi_device *dev)
{
const struct boardtype *board = dev->board_ptr;
if (board->is_pci1720)
return pci1720_reset(dev);
return pci171x_reset(dev);
}
static int pci1710_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct boardtype *board = NULL;
struct pci1710_private *devpriv;
struct comedi_subdevice *s;
int ret, subdev, n_subdevices;
if (context < ARRAY_SIZE(boardtypes))
board = &boardtypes[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
n_subdevices = 0;
if (board->n_aichan)
n_subdevices++;
if (board->has_ao)
n_subdevices++;
if (board->has_di_do)
n_subdevices += 2;
if (board->has_counter)
n_subdevices++;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
pci1710_reset(dev);
if (board->has_irq && pcidev->irq) {
ret = request_irq(pcidev->irq, interrupt_service_pci1710,
IRQF_SHARED, dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
subdev = 0;
if (board->n_aichan) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_GROUND;
if (board->has_diff_ai)
s->subdev_flags |= SDF_DIFF;
s->n_chan = board->n_aichan;
s->maxdata = 0x0fff;
s->range_table = board->rangelist_ai;
s->insn_read = pci171x_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = pci171x_ai_cmdtest;
s->do_cmd = pci171x_ai_cmd;
s->cancel = pci171x_ai_cancel;
}
subdev++;
}
if (board->has_ao) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->maxdata = 0x0fff;
if (board->is_pci1720) {
s->n_chan = 4;
s->range_table = &pci1720_ao_range;
s->insn_write = pci1720_ao_insn_write;
} else {
s->n_chan = 2;
s->range_table = &pci171x_ao_range;
s->insn_write = pci171x_ao_insn_write;
}
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
if (board->is_pci1720) {
int i;
for (i = 0; i < s->n_chan; i++)
s->readback[i] = 0x0800;
}
subdev++;
}
if (board->has_di_do) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci171x_di_insn_bits;
subdev++;
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pci171x_do_insn_bits;
subdev++;
}
if (board->has_counter) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 1;
s->maxdata = 0xffff;
s->range_table = &range_unknown;
s->insn_read = pci171x_counter_insn_read;
s->insn_write = pci171x_counter_insn_write;
s->insn_config = pci171x_counter_insn_config;
subdev++;
}
devpriv->max_samples = (board->has_large_fifo) ? 2048 : 512;
return 0;
}
static void pci1710_detach(struct comedi_device *dev)
{
if (dev->iobase)
pci1710_reset(dev);
comedi_pci_detach(dev);
}
static int adv_pci1710_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adv_pci1710_driver,
id->driver_data);
}
