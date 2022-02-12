static void
pci224_ao_set_data(struct comedi_device *dev, int chan, int range,
unsigned int data)
{
const struct pci224_board *thisboard = comedi_board(dev);
struct pci224_private *devpriv = dev->private;
unsigned short mangled;
devpriv->ao_readback[chan] = data;
outw(1 << chan, dev->iobase + PCI224_DACCEN);
devpriv->daccon = COMBINE(devpriv->daccon, devpriv->hwrange[range],
(PCI224_DACCON_POLAR_MASK |
PCI224_DACCON_VREF_MASK));
outw(devpriv->daccon | PCI224_DACCON_FIFORESET,
dev->iobase + PCI224_DACCON);
mangled = (unsigned short)data << (16 - thisboard->ao_bits);
if ((devpriv->daccon & PCI224_DACCON_POLAR_MASK) ==
PCI224_DACCON_POLAR_BI) {
mangled ^= 0x8000;
}
outw(mangled, dev->iobase + PCI224_DACDATA);
inw(dev->iobase + PCI224_SOFTTRIG);
}
static int
pci224_ao_insn_write(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan, range;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
for (i = 0; i < insn->n; i++)
pci224_ao_set_data(dev, chan, range, data[i]);
return i;
}
static int
pci224_ao_insn_read(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci224_private *devpriv = dev->private;
int i;
int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static void pci224_ao_stop(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci224_private *devpriv = dev->private;
unsigned long flags;
if (!test_and_clear_bit(AO_CMD_STARTED, &devpriv->state))
return;
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
devpriv->intsce = 0;
outb(0, devpriv->iobase1 + PCI224_INT_SCE);
while (devpriv->intr_running && devpriv->intr_cpuid != THISCPU) {
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
}
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
outw(0, dev->iobase + PCI224_DACCEN);
devpriv->daccon = COMBINE(devpriv->daccon,
PCI224_DACCON_TRIG_SW |
PCI224_DACCON_FIFOINTR_EMPTY,
PCI224_DACCON_TRIG_MASK |
PCI224_DACCON_FIFOINTR_MASK);
outw(devpriv->daccon | PCI224_DACCON_FIFORESET,
dev->iobase + PCI224_DACCON);
}
static void pci224_ao_start(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci224_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
set_bit(AO_CMD_STARTED, &devpriv->state);
if (cmd->stop_src == TRIG_COUNT && devpriv->ao_stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
cfc_handle_events(dev, s);
} else {
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
if (cmd->stop_src == TRIG_EXT)
devpriv->intsce = PCI224_INTR_EXT | PCI224_INTR_DAC;
else
devpriv->intsce = PCI224_INTR_DAC;
outb(devpriv->intsce, devpriv->iobase1 + PCI224_INT_SCE);
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
}
}
static void pci224_ao_handle_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci224_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int bytes_per_scan = cfc_bytes_per_scan(s);
unsigned int num_scans;
unsigned int room;
unsigned short dacstat;
unsigned int i, n;
num_scans = comedi_buf_read_n_available(s) / bytes_per_scan;
if (cmd->stop_src == TRIG_COUNT) {
if (num_scans > devpriv->ao_stop_count)
num_scans = devpriv->ao_stop_count;
}
dacstat = inw(dev->iobase + PCI224_DACCON);
switch (dacstat & PCI224_DACCON_FIFOFL_MASK) {
case PCI224_DACCON_FIFOFL_EMPTY:
room = PCI224_FIFO_ROOM_EMPTY;
if (cmd->stop_src == TRIG_COUNT && devpriv->ao_stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return;
}
break;
case PCI224_DACCON_FIFOFL_ONETOHALF:
room = PCI224_FIFO_ROOM_ONETOHALF;
break;
case PCI224_DACCON_FIFOFL_HALFTOFULL:
room = PCI224_FIFO_ROOM_HALFTOFULL;
break;
default:
room = PCI224_FIFO_ROOM_FULL;
break;
}
if (room >= PCI224_FIFO_ROOM_ONETOHALF) {
if (num_scans == 0) {
dev_err(dev->class_dev, "AO buffer underrun\n");
s->async->events |= COMEDI_CB_OVERFLOW;
}
}
room /= cmd->chanlist_len;
if (num_scans > room)
num_scans = room;
for (n = 0; n < num_scans; n++) {
cfc_read_array_from_buffer(s, &devpriv->ao_scan_vals[0],
bytes_per_scan);
for (i = 0; i < cmd->chanlist_len; i++) {
outw(devpriv->ao_scan_vals[devpriv->ao_scan_order[i]],
dev->iobase + PCI224_DACDATA);
}
}
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ao_stop_count -= num_scans;
if (devpriv->ao_stop_count == 0) {
devpriv->daccon = COMBINE(devpriv->daccon,
PCI224_DACCON_FIFOINTR_EMPTY,
PCI224_DACCON_FIFOINTR_MASK);
outw(devpriv->daccon, dev->iobase + PCI224_DACCON);
}
}
if ((devpriv->daccon & PCI224_DACCON_TRIG_MASK) ==
PCI224_DACCON_TRIG_NONE) {
unsigned short trig;
if (cmd->scan_begin_src == TRIG_TIMER) {
trig = PCI224_DACCON_TRIG_Z2CT0;
} else {
if (cmd->scan_begin_arg & CR_INVERT)
trig = PCI224_DACCON_TRIG_EXTN;
else
trig = PCI224_DACCON_TRIG_EXTP;
}
devpriv->daccon = COMBINE(devpriv->daccon, trig,
PCI224_DACCON_TRIG_MASK);
outw(devpriv->daccon, dev->iobase + PCI224_DACCON);
}
cfc_handle_events(dev, s);
}
static int pci224_ao_inttrig_start(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
s->async->inttrig = NULL;
pci224_ao_start(dev, s);
return 1;
}
static int pci224_ao_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
unsigned int chan_mask = 0;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan_mask & (1 << chan)) {
dev_dbg(dev->class_dev,
"%s: entries in chanlist must contain no duplicate channels\n",
__func__);
return -EINVAL;
}
chan_mask |= (1 << chan);
if (range != range0) {
dev_dbg(dev->class_dev,
"%s: entries in chanlist must all have the same range index\n",
__func__);
return -EINVAL;
}
}
return 0;
}
static int
pci224_ao_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
struct pci224_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_EXT | TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src,
TRIG_COUNT | TRIG_EXT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
arg = 0;
if (cmd->start_src & TRIG_EXT)
arg++;
if (cmd->scan_begin_src & TRIG_EXT)
arg++;
if (cmd->stop_src & TRIG_EXT)
arg++;
if (arg > 1)
err |= -EINVAL;
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_INT:
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
if ((cmd->start_arg & ~CR_FLAGS_MASK) != 0) {
cmd->start_arg = COMBINE(cmd->start_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->start_arg & CR_FLAGS_MASK & ~CR_EDGE) != 0) {
cmd->start_arg = COMBINE(cmd->start_arg, 0,
CR_FLAGS_MASK & ~CR_EDGE);
err |= -EINVAL;
}
break;
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
MAX_SCAN_PERIOD);
arg = cmd->chanlist_len * CONVERT_PERIOD;
if (arg < MIN_SCAN_PERIOD)
arg = MIN_SCAN_PERIOD;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg, arg);
break;
case TRIG_EXT:
if ((cmd->scan_begin_arg & ~CR_FLAGS_MASK) != 0) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->scan_begin_arg & CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT)) != 0) {
cmd->scan_begin_arg = COMBINE(cmd->scan_begin_arg, 0,
CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT));
err |= -EINVAL;
}
break;
}
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_COUNT:
break;
case TRIG_EXT:
if ((cmd->stop_arg & ~CR_FLAGS_MASK) != 0) {
cmd->stop_arg = COMBINE(cmd->stop_arg, 0,
~CR_FLAGS_MASK);
err |= -EINVAL;
}
if ((cmd->stop_arg & CR_FLAGS_MASK & ~CR_EDGE) != 0) {
cmd->stop_arg = COMBINE(cmd->stop_arg, 0,
CR_FLAGS_MASK & ~CR_EDGE);
}
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->cached_div1,
&devpriv->cached_div2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= pci224_ao_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static void pci224_ao_start_pacer(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci224_private *devpriv = dev->private;
unsigned long timer_base = devpriv->iobase1 + PCI224_Z2_CT0;
outb(GAT_CONFIG(0, GAT_VCC), devpriv->iobase1 + PCI224_ZGAT_SCE);
outb(GAT_CONFIG(2, GAT_VCC), devpriv->iobase1 + PCI224_ZGAT_SCE);
outb(CLK_CONFIG(2, CLK_10MHZ), devpriv->iobase1 + PCI224_ZCLK_SCE);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 2, devpriv->cached_div1);
outb(CLK_CONFIG(0, CLK_OUTNM1), devpriv->iobase1 + PCI224_ZCLK_SCE);
i8254_set_mode(timer_base, 0, 0, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 0, devpriv->cached_div2);
}
static int pci224_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pci224_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int range;
unsigned int i, j;
unsigned int ch;
unsigned int rank;
unsigned long flags;
if (cmd->chanlist == NULL || cmd->chanlist_len == 0)
return -EINVAL;
devpriv->ao_enab = 0;
for (i = 0; i < cmd->chanlist_len; i++) {
ch = CR_CHAN(cmd->chanlist[i]);
devpriv->ao_enab |= 1U << ch;
rank = 0;
for (j = 0; j < cmd->chanlist_len; j++) {
if (CR_CHAN(cmd->chanlist[j]) < ch)
rank++;
}
devpriv->ao_scan_order[rank] = i;
}
outw(devpriv->ao_enab, dev->iobase + PCI224_DACCEN);
range = CR_RANGE(cmd->chanlist[0]);
devpriv->daccon = COMBINE(devpriv->daccon,
(devpriv->
hwrange[range] | PCI224_DACCON_TRIG_NONE |
PCI224_DACCON_FIFOINTR_NHALF),
(PCI224_DACCON_POLAR_MASK |
PCI224_DACCON_VREF_MASK |
PCI224_DACCON_TRIG_MASK |
PCI224_DACCON_FIFOINTR_MASK));
outw(devpriv->daccon | PCI224_DACCON_FIFORESET,
dev->iobase + PCI224_DACCON);
if (cmd->scan_begin_src == TRIG_TIMER)
pci224_ao_start_pacer(dev, s);
if (cmd->stop_src == TRIG_COUNT)
devpriv->ao_stop_count = cmd->stop_arg;
else
devpriv->ao_stop_count = 0;
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
if (cmd->start_src == TRIG_INT) {
s->async->inttrig = pci224_ao_inttrig_start;
} else {
devpriv->intsce |= PCI224_INTR_EXT;
outb(devpriv->intsce, devpriv->iobase1 + PCI224_INT_SCE);
}
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
return 0;
}
static int pci224_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
pci224_ao_stop(dev, s);
return 0;
}
static void
pci224_ao_munge(struct comedi_device *dev, struct comedi_subdevice *s,
void *data, unsigned int num_bytes, unsigned int chan_index)
{
const struct pci224_board *thisboard = comedi_board(dev);
struct pci224_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned short *array = data;
unsigned int length = num_bytes / sizeof(*array);
unsigned int offset;
unsigned int shift;
unsigned int i;
shift = 16 - thisboard->ao_bits;
if ((devpriv->hwrange[CR_RANGE(cmd->chanlist[0])] &
PCI224_DACCON_POLAR_MASK) == PCI224_DACCON_POLAR_UNI) {
offset = 0;
} else {
offset = 32768;
}
for (i = 0; i < length; i++)
array[i] = (array[i] << shift) - offset;
}
static irqreturn_t pci224_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct pci224_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
struct comedi_cmd *cmd;
unsigned char intstat, valid_intstat;
unsigned char curenab;
int retval = 0;
unsigned long flags;
intstat = inb(devpriv->iobase1 + PCI224_INT_SCE) & 0x3F;
if (intstat) {
retval = 1;
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
valid_intstat = devpriv->intsce & intstat;
curenab = devpriv->intsce & ~intstat;
outb(curenab, devpriv->iobase1 + PCI224_INT_SCE);
devpriv->intr_running = 1;
devpriv->intr_cpuid = THISCPU;
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
if (valid_intstat != 0) {
cmd = &s->async->cmd;
if (valid_intstat & PCI224_INTR_EXT) {
devpriv->intsce &= ~PCI224_INTR_EXT;
if (cmd->start_src == TRIG_EXT)
pci224_ao_start(dev, s);
else if (cmd->stop_src == TRIG_EXT)
pci224_ao_stop(dev, s);
}
if (valid_intstat & PCI224_INTR_DAC)
pci224_ao_handle_fifo(dev, s);
}
spin_lock_irqsave(&devpriv->ao_spinlock, flags);
if (curenab != devpriv->intsce) {
outb(devpriv->intsce,
devpriv->iobase1 + PCI224_INT_SCE);
}
devpriv->intr_running = 0;
spin_unlock_irqrestore(&devpriv->ao_spinlock, flags);
}
return IRQ_RETVAL(retval);
}
static const struct pci224_board
*pci224_find_pci_board(struct pci_dev *pci_dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(pci224_boards); i++)
if (pci_dev->device == pci224_boards[i].devid)
return &pci224_boards[i];
return NULL;
}
static struct pci_dev *pci224_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pci224_board *thisboard = comedi_board(dev);
struct pci_dev *pci_dev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pci_dev) {
if (bus || slot) {
if (bus != pci_dev->bus->number ||
slot != PCI_SLOT(pci_dev->devfn))
continue;
}
if (pci_dev->vendor != PCI_VENDOR_ID_AMPLICON)
continue;
if (thisboard->model == any_model) {
const struct pci224_board *board_ptr;
board_ptr = pci224_find_pci_board(pci_dev);
if (board_ptr == NULL)
continue;
dev->board_ptr = board_ptr;
} else {
if (thisboard->devid != pci_dev->device)
continue;
}
return pci_dev;
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pci224_attach_common(struct comedi_device *dev,
struct pci_dev *pci_dev, int *options)
{
const struct pci224_board *thisboard = comedi_board(dev);
struct pci224_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned int irq;
unsigned n;
int ret;
comedi_set_hw_dev(dev, &pci_dev->dev);
ret = comedi_pci_enable(dev);
if (ret)
return ret;
spin_lock_init(&devpriv->ao_spinlock);
devpriv->iobase1 = pci_resource_start(pci_dev, 2);
dev->iobase = pci_resource_start(pci_dev, 3);
irq = pci_dev->irq;
devpriv->ao_readback = kmalloc(sizeof(devpriv->ao_readback[0]) *
thisboard->ao_chans, GFP_KERNEL);
if (!devpriv->ao_readback)
return -ENOMEM;
devpriv->ao_scan_vals = kmalloc(sizeof(devpriv->ao_scan_vals[0]) *
thisboard->ao_chans, GFP_KERNEL);
if (!devpriv->ao_scan_vals)
return -ENOMEM;
devpriv->ao_scan_order = kmalloc(sizeof(devpriv->ao_scan_order[0]) *
thisboard->ao_chans, GFP_KERNEL);
if (!devpriv->ao_scan_order)
return -ENOMEM;
devpriv->intsce = 0;
outb(0, devpriv->iobase1 + PCI224_INT_SCE);
outw(PCI224_DACCON_GLOBALRESET, dev->iobase + PCI224_DACCON);
outw(0, dev->iobase + PCI224_DACCEN);
outw(0, dev->iobase + PCI224_FIFOSIZ);
devpriv->daccon = (PCI224_DACCON_TRIG_SW | PCI224_DACCON_POLAR_BI |
PCI224_DACCON_FIFOENAB |
PCI224_DACCON_FIFOINTR_EMPTY);
outw(devpriv->daccon | PCI224_DACCON_FIFORESET,
dev->iobase + PCI224_DACCON);
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_CMD_WRITE;
s->n_chan = thisboard->ao_chans;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->insn_write = &pci224_ao_insn_write;
s->insn_read = &pci224_ao_insn_read;
s->len_chanlist = s->n_chan;
dev->write_subdev = s;
s->do_cmd = &pci224_ao_cmd;
s->do_cmdtest = &pci224_ao_cmdtest;
s->cancel = &pci224_ao_cancel;
s->munge = &pci224_ao_munge;
if (thisboard->model == pci234_model) {
const struct comedi_lrange **range_table_list;
s->range_table_list = range_table_list =
kmalloc(sizeof(struct comedi_lrange *) * s->n_chan,
GFP_KERNEL);
if (!s->range_table_list)
return -ENOMEM;
if (options) {
for (n = 2; n < 3 + s->n_chan; n++) {
if (options[n] < 0 || options[n] > 1) {
dev_warn(dev->class_dev,
"warning! bad options[%u]=%d\n",
n, options[n]);
}
}
}
for (n = 0; n < s->n_chan; n++) {
if (n < COMEDI_NDEVCONFOPTS - 3 && options &&
options[3 + n] == 1) {
if (options[2] == 1)
range_table_list[n] = &range_pci234_ext;
else
range_table_list[n] = &range_bipolar5;
} else {
if (options && options[2] == 1) {
range_table_list[n] =
&range_pci234_ext2;
} else {
range_table_list[n] = &range_bipolar10;
}
}
}
devpriv->hwrange = hwrange_pci234;
} else {
if (options && options[2] == 1) {
s->range_table = &range_pci224_external;
devpriv->hwrange = hwrange_pci224_external;
} else {
if (options && options[2] != 0) {
dev_warn(dev->class_dev,
"warning! bad options[2]=%d\n",
options[2]);
}
s->range_table = &range_pci224_internal;
devpriv->hwrange = hwrange_pci224_internal;
}
}
dev->board_name = thisboard->name;
if (irq) {
ret = request_irq(irq, pci224_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret < 0) {
dev_err(dev->class_dev,
"error! unable to allocate irq %u\n", irq);
return ret;
}
dev->irq = irq;
}
return 0;
}
static int pci224_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci224_private *devpriv;
struct pci_dev *pci_dev;
dev_info(dev->class_dev, "attach\n");
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
pci_dev = pci224_find_pci_dev(dev, it);
if (!pci_dev)
return -EIO;
return pci224_attach_common(dev, pci_dev, it->options);
}
static int
pci224_auto_attach(struct comedi_device *dev, unsigned long context_unused)
{
struct pci_dev *pci_dev = comedi_to_pci_dev(dev);
struct pci224_private *devpriv;
dev_info(dev->class_dev, "attach pci %s\n", pci_name(pci_dev));
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
dev->board_ptr = pci224_find_pci_board(pci_dev);
if (dev->board_ptr == NULL) {
dev_err(dev->class_dev,
"BUG! cannot determine board type!\n");
return -EINVAL;
}
pci_dev_get(pci_dev);
return pci224_attach_common(dev, pci_dev, NULL);
}
static void pci224_detach(struct comedi_device *dev)
{
struct pci224_private *devpriv = dev->private;
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->subdevices) {
struct comedi_subdevice *s;
s = &dev->subdevices[0];
kfree(s->range_table_list);
}
if (devpriv) {
kfree(devpriv->ao_readback);
kfree(devpriv->ao_scan_vals);
kfree(devpriv->ao_scan_order);
}
comedi_pci_disable(dev);
if (pcidev)
pci_dev_put(pcidev);
}
static int amplc_pci224_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &amplc_pci224_driver,
id->driver_data);
}
