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
outw(chan | (chan << 8), dev->iobase + PCI171X_MUX_REG);
outw(rangeval, dev->iobase + PCI171X_RANGE_REG);
devpriv->act_chanlist[i] = chan;
}
for ( ; i < n_chan; i++)
devpriv->act_chanlist[i] = CR_CHAN(chanlist[i]);
devpriv->mux_ext = first_chan | (last_chan << 8);
outw(devpriv->mux_ext, dev->iobase + PCI171X_MUX_REG);
}
static int pci171x_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + PCI171X_STATUS_REG);
if ((status & PCI171X_STATUS_FE) == 0)
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
sample = inw(dev->iobase + PCI171X_AD_DATA_REG);
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
devpriv->ctrl &= PCI171X_CTRL_CNT0;
devpriv->ctrl |= PCI171X_CTRL_SW;
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
pci171x_ai_setup_chanlist(dev, s, &insn->chanspec, 1, 1);
for (i = 0; i < insn->n; i++) {
unsigned int val;
outw(0, dev->iobase + PCI171X_SOFTTRG_REG);
ret = comedi_timeout(dev, s, insn, pci171x_ai_eoc, 0);
if (ret)
break;
ret = pci171x_ai_read_sample(dev, s, 0, &val);
if (ret)
break;
data[i] = val;
}
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
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
unsigned int val = s->readback[chan];
int i;
devpriv->da_ranges &= ~(1 << (chan << 1));
devpriv->da_ranges |= (range << (chan << 1));
outw(devpriv->da_ranges, dev->iobase + PCI171X_DAREF_REG);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + PCI171X_DA_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int pci171x_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inw(dev->iobase + PCI171X_DI_REG);
return insn->n;
}
static int pci171x_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + PCI171X_DO_REG);
data[1] = s->state;
return insn->n;
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
outb(val, dev->iobase + PCI1720_RANGE_REG);
devpriv->da_ranges = val;
}
val = s->readback[chan];
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + PCI1720_DA_REG(chan));
outb(0, dev->iobase + PCI1720_SYNC_REG);
}
s->readback[chan] = val;
return insn->n;
}
static int pci171x_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci1710_private *devpriv = dev->private;
devpriv->ctrl &= PCI171X_CTRL_CNT0;
devpriv->ctrl |= PCI171X_CTRL_SW;
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
comedi_8254_pacer_enable(dev->pacer, 1, 2, false);
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
return 0;
}
static void pci1710_handle_every_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int status;
unsigned int val;
int ret;
status = inw(dev->iobase + PCI171X_STATUS_REG);
if (status & PCI171X_STATUS_FE) {
dev_dbg(dev->class_dev, "A/D FIFO empty (%4x)\n", status);
s->async->events |= COMEDI_CB_ERROR;
return;
}
if (status & PCI171X_STATUS_FF) {
dev_dbg(dev->class_dev,
"A/D FIFO Full status (Fatal Error!) (%4x)\n", status);
s->async->events |= COMEDI_CB_ERROR;
return;
}
outb(0, dev->iobase + PCI171X_CLRINT_REG);
for (; !(inw(dev->iobase + PCI171X_STATUS_REG) & PCI171X_STATUS_FE);) {
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
outb(0, dev->iobase + PCI171X_CLRINT_REG);
}
static void pci1710_handle_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci1710_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status;
int i;
status = inw(dev->iobase + PCI171X_STATUS_REG);
if (!(status & PCI171X_STATUS_FH)) {
dev_dbg(dev->class_dev, "A/D FIFO not half full!\n");
async->events |= COMEDI_CB_ERROR;
return;
}
if (status & PCI171X_STATUS_FF) {
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
outb(0, dev->iobase + PCI171X_CLRINT_REG);
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
if (!(inw(dev->iobase + PCI171X_STATUS_REG) & PCI171X_STATUS_IRQ))
return IRQ_NONE;
if (devpriv->ai_et) {
devpriv->ai_et = 0;
devpriv->ctrl &= PCI171X_CTRL_CNT0;
devpriv->ctrl |= PCI171X_CTRL_SW;
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
devpriv->ctrl = devpriv->ctrl_ext;
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
outw(devpriv->mux_ext, dev->iobase + PCI171X_MUX_REG);
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
comedi_8254_pacer_enable(dev->pacer, 1, 2, true);
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
pci171x_ai_setup_chanlist(dev, s, cmd->chanlist, cmd->chanlist_len,
devpriv->saved_seglen);
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
devpriv->ctrl &= PCI171X_CTRL_CNT0;
if ((cmd->flags & CMDF_WAKE_EOS) == 0)
devpriv->ctrl |= PCI171X_CTRL_ONEFH;
if (cmd->convert_src == TRIG_TIMER) {
comedi_8254_update_divisors(dev->pacer);
devpriv->ctrl |= PCI171X_CTRL_PACER | PCI171X_CTRL_IRQEN;
if (cmd->start_src == TRIG_EXT) {
devpriv->ctrl_ext = devpriv->ctrl;
devpriv->ctrl &= ~(PCI171X_CTRL_PACER |
PCI171X_CTRL_ONEFH |
PCI171X_CTRL_GATE);
devpriv->ctrl |= PCI171X_CTRL_EXT;
devpriv->ai_et = 1;
} else {
devpriv->ai_et = 0;
}
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
if (cmd->start_src == TRIG_NOW)
comedi_8254_pacer_enable(dev->pacer, 1, 2, true);
} else {
devpriv->ctrl |= PCI171X_CTRL_EXT | PCI171X_CTRL_IRQEN;
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
}
return 0;
}
static int pci171x_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 10000);
else
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
unsigned int arg = cmd->convert_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
err |= pci171x_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int pci171x_insn_counter_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pci1710_private *devpriv = dev->private;
switch (data[0]) {
case INSN_CONFIG_SET_CLOCK_SRC:
switch (data[1]) {
case 0:
devpriv->ctrl_ext &= ~PCI171X_CTRL_CNT0;
break;
case 1:
devpriv->ctrl_ext |= PCI171X_CTRL_CNT0;
break;
default:
return -EINVAL;
}
outw(devpriv->ctrl_ext, dev->iobase + PCI171X_CTRL_REG);
break;
case INSN_CONFIG_GET_CLOCK_SRC:
if (devpriv->ctrl_ext & PCI171X_CTRL_CNT0) {
data[1] = 1;
data[2] = 0;
} else {
data[1] = 0;
data[2] = I8254_OSC_BASE_10MHZ;
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static int pci171x_reset(struct comedi_device *dev)
{
const struct boardtype *board = dev->board_ptr;
struct pci1710_private *devpriv = dev->private;
devpriv->ctrl = PCI171X_CTRL_SW | PCI171X_CTRL_CNT0;
outw(devpriv->ctrl, dev->iobase + PCI171X_CTRL_REG);
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
devpriv->da_ranges = 0;
if (board->has_ao) {
outb(devpriv->da_ranges, dev->iobase + PCI171X_DAREF_REG);
outw(0, dev->iobase + PCI171X_DA_REG(0));
outw(0, dev->iobase + PCI171X_DA_REG(1));
}
outw(0, dev->iobase + PCI171X_DO_REG);
outb(0, dev->iobase + PCI171X_CLRFIFO_REG);
outb(0, dev->iobase + PCI171X_CLRINT_REG);
return 0;
}
static int pci1720_reset(struct comedi_device *dev)
{
struct pci1710_private *devpriv = dev->private;
outb(PCI1720_SYNC_CTRL_SC0, dev->iobase + PCI1720_SYNC_CTRL_REG);
devpriv->da_ranges = 0xAA;
outb(devpriv->da_ranges, dev->iobase + PCI1720_RANGE_REG);
outw(0x0800, dev->iobase + PCI1720_DA_REG(0));
outw(0x0800, dev->iobase + PCI1720_DA_REG(1));
outw(0x0800, dev->iobase + PCI1720_DA_REG(2));
outw(0x0800, dev->iobase + PCI1720_DA_REG(3));
outb(0, dev->iobase + PCI1720_SYNC_REG);
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
dev->pacer = comedi_8254_init(dev->iobase + PCI171X_TIMER_BASE,
I8254_OSC_BASE_10MHZ, I8254_IO16, 0);
if (!dev->pacer)
return -ENOMEM;
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
comedi_8254_subdevice_init(s, dev->pacer);
dev->pacer->insn_config = pci171x_insn_counter_config;
comedi_8254_set_busy(dev->pacer, 1, true);
comedi_8254_set_busy(dev->pacer, 2, true);
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
