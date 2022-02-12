static void plx9050_interrupt_control(unsigned long io_base,
bool LINTi1_enable,
bool LINTi1_active_high,
bool LINTi2_enable,
bool LINTi2_active_high,
bool interrupt_enable)
{
int flags = 0;
if (LINTi1_enable)
flags |= PLX9050_LINTI1_ENABLE;
if (LINTi1_active_high)
flags |= PLX9050_LINTI1_ACTIVE_HIGH;
if (LINTi2_enable)
flags |= PLX9050_LINTI2_ENABLE;
if (LINTi2_active_high)
flags |= PLX9050_LINTI2_ACTIVE_HIGH;
if (interrupt_enable)
flags |= PLX9050_PCI_INTERRUPT_ENABLE;
outb(flags, io_base + PLX9050_REGISTER_INTERRUPT_CONTROL);
}
static void pci9111_timer_set(struct comedi_device *dev)
{
pci9111_8254_control_set(PCI9111_8254_COUNTER_0 |
PCI9111_8254_READ_LOAD_LSB_MSB |
PCI9111_8254_MODE_0 |
PCI9111_8254_BINARY_COUNTER);
pci9111_8254_control_set(PCI9111_8254_COUNTER_1 |
PCI9111_8254_READ_LOAD_LSB_MSB |
PCI9111_8254_MODE_2 |
PCI9111_8254_BINARY_COUNTER);
pci9111_8254_control_set(PCI9111_8254_COUNTER_2 |
PCI9111_8254_READ_LOAD_LSB_MSB |
PCI9111_8254_MODE_2 |
PCI9111_8254_BINARY_COUNTER);
udelay(1);
pci9111_8254_counter_2_set(dev_private->timer_divisor_2);
pci9111_8254_counter_1_set(dev_private->timer_divisor_1);
}
static void pci9111_trigger_source_set(struct comedi_device *dev,
enum pci9111_trigger_sources source)
{
int flags;
flags = pci9111_trigger_and_autoscan_get() & 0x09;
switch (source) {
case software:
flags |= PCI9111_EITS_INTERNAL | PCI9111_TPST_SOFTWARE_TRIGGER;
break;
case timer_pacer:
flags |= PCI9111_EITS_INTERNAL | PCI9111_TPST_TIMER_PACER;
break;
case external:
flags |= PCI9111_EITS_EXTERNAL;
break;
}
pci9111_trigger_and_autoscan_set(flags);
}
static void pci9111_pretrigger_set(struct comedi_device *dev, bool pretrigger)
{
int flags;
flags = pci9111_trigger_and_autoscan_get() & 0x07;
if (pretrigger)
flags |= PCI9111_PTRG_ON;
pci9111_trigger_and_autoscan_set(flags);
}
static void pci9111_autoscan_set(struct comedi_device *dev, bool autoscan)
{
int flags;
flags = pci9111_trigger_and_autoscan_get() & 0x0e;
if (autoscan)
flags |= PCI9111_ASCAN_ON;
pci9111_trigger_and_autoscan_set(flags);
}
static void pci9111_interrupt_source_set(struct comedi_device *dev,
enum pci9111_ISC0_sources irq_0_source,
enum pci9111_ISC1_sources irq_1_source)
{
int flags;
flags = pci9111_interrupt_and_fifo_get() & 0x04;
if (irq_0_source == irq_on_fifo_half_full)
flags |= PCI9111_ISC0_SET_IRQ_ON_FIFO_HALF_FULL;
if (irq_1_source == irq_on_external_trigger)
flags |= PCI9111_ISC1_SET_IRQ_ON_EXT_TRG;
pci9111_interrupt_and_fifo_set(flags);
}
static int pci9111_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
plx9050_interrupt_control(dev_private->lcr_io_base, true, true, true,
true, false);
pci9111_trigger_source_set(dev, software);
pci9111_autoscan_set(dev, false);
pci9111_fifo_reset();
#ifdef AI_DO_CMD_DEBUG
printk(PCI9111_DRIVER_NAME ": ai_cancel\n");
#endif
return 0;
}
static int
pci9111_ai_do_cmd_test(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int tmp;
int error = 0;
int range, reference;
int i;
struct pci9111_board *board = (struct pci9111_board *)dev->board_ptr;
pci9111_check_trigger_src(cmd->start_src, TRIG_NOW);
pci9111_check_trigger_src(cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW | TRIG_EXT);
pci9111_check_trigger_src(cmd->convert_src, TRIG_TIMER | TRIG_EXT);
pci9111_check_trigger_src(cmd->scan_end_src, TRIG_COUNT);
pci9111_check_trigger_src(cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (error)
return 1;
if (cmd->start_src != TRIG_NOW)
error++;
if ((cmd->scan_begin_src != TRIG_TIMER) &&
(cmd->scan_begin_src != TRIG_FOLLOW) &&
(cmd->scan_begin_src != TRIG_EXT))
error++;
if ((cmd->convert_src != TRIG_TIMER) && (cmd->convert_src != TRIG_EXT))
error++;
if ((cmd->convert_src == TRIG_TIMER) &&
!((cmd->scan_begin_src == TRIG_TIMER) ||
(cmd->scan_begin_src == TRIG_FOLLOW)))
error++;
if ((cmd->convert_src == TRIG_EXT) &&
!((cmd->scan_begin_src == TRIG_EXT) ||
(cmd->scan_begin_src == TRIG_FOLLOW)))
error++;
if (cmd->scan_end_src != TRIG_COUNT)
error++;
if ((cmd->stop_src != TRIG_COUNT) && (cmd->stop_src != TRIG_NONE))
error++;
if (error)
return 2;
if (cmd->chanlist_len < 1) {
cmd->chanlist_len = 1;
error++;
}
if (cmd->chanlist_len > board->ai_channel_nbr) {
cmd->chanlist_len = board->ai_channel_nbr;
error++;
}
if ((cmd->start_src == TRIG_NOW) && (cmd->start_arg != 0)) {
cmd->start_arg = 0;
error++;
}
if ((cmd->convert_src == TRIG_TIMER) &&
(cmd->convert_arg < board->ai_acquisition_period_min_ns)) {
cmd->convert_arg = board->ai_acquisition_period_min_ns;
error++;
}
if ((cmd->convert_src == TRIG_EXT) && (cmd->convert_arg != 0)) {
cmd->convert_arg = 0;
error++;
}
if ((cmd->scan_begin_src == TRIG_TIMER) &&
(cmd->scan_begin_arg < board->ai_acquisition_period_min_ns)) {
cmd->scan_begin_arg = board->ai_acquisition_period_min_ns;
error++;
}
if ((cmd->scan_begin_src == TRIG_FOLLOW)
&& (cmd->scan_begin_arg != 0)) {
cmd->scan_begin_arg = 0;
error++;
}
if ((cmd->scan_begin_src == TRIG_EXT) && (cmd->scan_begin_arg != 0)) {
cmd->scan_begin_arg = 0;
error++;
}
if ((cmd->scan_end_src == TRIG_COUNT) &&
(cmd->scan_end_arg != cmd->chanlist_len)) {
cmd->scan_end_arg = cmd->chanlist_len;
error++;
}
if ((cmd->stop_src == TRIG_COUNT) && (cmd->stop_arg < 1)) {
cmd->stop_arg = 1;
error++;
}
if ((cmd->stop_src == TRIG_NONE) && (cmd->stop_arg != 0)) {
cmd->stop_arg = 0;
error++;
}
if (error)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer_2div(PCI9111_8254_CLOCK_PERIOD_NS,
&(dev_private->timer_divisor_1),
&(dev_private->timer_divisor_2),
&(cmd->convert_arg),
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
error++;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
unsigned int scan_begin_min;
unsigned int scan_begin_arg;
unsigned int scan_factor;
scan_begin_min = cmd->chanlist_len * cmd->convert_arg;
if (cmd->scan_begin_arg != scan_begin_min) {
if (scan_begin_min < cmd->scan_begin_arg) {
scan_factor =
cmd->scan_begin_arg / scan_begin_min;
scan_begin_arg = scan_factor * scan_begin_min;
if (cmd->scan_begin_arg != scan_begin_arg) {
cmd->scan_begin_arg = scan_begin_arg;
error++;
}
} else {
cmd->scan_begin_arg = scan_begin_min;
error++;
}
}
}
if (error)
return 4;
if (cmd->chanlist) {
range = CR_RANGE(cmd->chanlist[0]);
reference = CR_AREF(cmd->chanlist[0]);
if (cmd->chanlist_len > 1) {
for (i = 0; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) != i) {
comedi_error(dev,
"entries in chanlist must be consecutive "
"channels,counting upwards from 0\n");
error++;
}
if (CR_RANGE(cmd->chanlist[i]) != range) {
comedi_error(dev,
"entries in chanlist must all have the same gain\n");
error++;
}
if (CR_AREF(cmd->chanlist[i]) != reference) {
comedi_error(dev,
"entries in chanlist must all have the same reference\n");
error++;
}
}
} else {
if ((CR_CHAN(cmd->chanlist[0]) >
(board->ai_channel_nbr - 1))
|| (CR_CHAN(cmd->chanlist[0]) < 0)) {
comedi_error(dev,
"channel number is out of limits\n");
error++;
}
}
}
if (error)
return 5;
return 0;
}
static int pci9111_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *subdevice)
{
struct comedi_cmd *async_cmd = &subdevice->async->cmd;
if (!dev->irq) {
comedi_error(dev,
"no irq assigned for PCI9111, cannot do hardware conversion");
return -1;
}
if (async_cmd->chanlist_len > 1) {
pci9111_ai_channel_set((async_cmd->chanlist_len) - 1);
pci9111_autoscan_set(dev, true);
} else {
pci9111_ai_channel_set(CR_CHAN(async_cmd->chanlist[0]));
pci9111_autoscan_set(dev, false);
}
pci9111_ai_range_set(CR_RANGE(async_cmd->chanlist[0]));
switch (async_cmd->stop_src) {
case TRIG_COUNT:
dev_private->stop_counter =
async_cmd->stop_arg * async_cmd->chanlist_len;
dev_private->stop_is_none = 0;
break;
case TRIG_NONE:
dev_private->stop_counter = 0;
dev_private->stop_is_none = 1;
break;
default:
comedi_error(dev, "Invalid stop trigger");
return -1;
}
dev_private->scan_delay = 0;
switch (async_cmd->convert_src) {
case TRIG_TIMER:
i8253_cascade_ns_to_timer_2div(PCI9111_8254_CLOCK_PERIOD_NS,
&(dev_private->timer_divisor_1),
&(dev_private->timer_divisor_2),
&(async_cmd->convert_arg),
async_cmd->
flags & TRIG_ROUND_MASK);
#ifdef AI_DO_CMD_DEBUG
printk(PCI9111_DRIVER_NAME ": divisors = %d, %d\n",
dev_private->timer_divisor_1,
dev_private->timer_divisor_2);
#endif
pci9111_trigger_source_set(dev, software);
pci9111_timer_set(dev);
pci9111_fifo_reset();
pci9111_interrupt_source_set(dev, irq_on_fifo_half_full,
irq_on_timer_tick);
pci9111_trigger_source_set(dev, timer_pacer);
plx9050_interrupt_control(dev_private->lcr_io_base, true, true,
false, true, true);
if (async_cmd->scan_begin_src == TRIG_TIMER) {
dev_private->scan_delay =
(async_cmd->scan_begin_arg /
(async_cmd->convert_arg *
async_cmd->chanlist_len)) - 1;
}
break;
case TRIG_EXT:
pci9111_trigger_source_set(dev, external);
pci9111_fifo_reset();
pci9111_interrupt_source_set(dev, irq_on_fifo_half_full,
irq_on_timer_tick);
plx9050_interrupt_control(dev_private->lcr_io_base, true, true,
false, true, true);
break;
default:
comedi_error(dev, "Invalid convert trigger");
return -1;
}
dev_private->stop_counter *= (1 + dev_private->scan_delay);
dev_private->chanlist_len = async_cmd->chanlist_len;
dev_private->chunk_counter = 0;
dev_private->chunk_num_samples =
dev_private->chanlist_len * (1 + dev_private->scan_delay);
#ifdef AI_DO_CMD_DEBUG
printk(PCI9111_DRIVER_NAME ": start interruptions!\n");
printk(PCI9111_DRIVER_NAME ": trigger source = %2x\n",
pci9111_trigger_and_autoscan_get());
printk(PCI9111_DRIVER_NAME ": irq source = %2x\n",
pci9111_interrupt_and_fifo_get());
printk(PCI9111_DRIVER_NAME ": ai_do_cmd\n");
printk(PCI9111_DRIVER_NAME ": stop counter = %d\n",
dev_private->stop_counter);
printk(PCI9111_DRIVER_NAME ": scan delay = %d\n",
dev_private->scan_delay);
printk(PCI9111_DRIVER_NAME ": chanlist_len = %d\n",
dev_private->chanlist_len);
printk(PCI9111_DRIVER_NAME ": chunk num samples = %d\n",
dev_private->chunk_num_samples);
#endif
return 0;
}
static void pci9111_ai_munge(struct comedi_device *dev,
struct comedi_subdevice *s, void *data,
unsigned int num_bytes,
unsigned int start_chan_index)
{
unsigned int i, num_samples = num_bytes / sizeof(short);
short *array = data;
int resolution =
((struct pci9111_board *)dev->board_ptr)->ai_resolution;
for (i = 0; i < num_samples; i++) {
if (resolution == PCI9111_HR_AI_RESOLUTION)
array[i] =
(array[i] & PCI9111_HR_AI_RESOLUTION_MASK) ^
PCI9111_HR_AI_RESOLUTION_2_CMP_BIT;
else
array[i] =
((array[i] >> 4) & PCI9111_AI_RESOLUTION_MASK) ^
PCI9111_AI_RESOLUTION_2_CMP_BIT;
}
}
static irqreturn_t pci9111_interrupt(int irq, void *p_device)
{
struct comedi_device *dev = p_device;
struct comedi_subdevice *subdevice = dev->read_subdev;
struct comedi_async *async;
unsigned long irq_flags;
unsigned char intcsr;
if (!dev->attached) {
return IRQ_NONE;
}
async = subdevice->async;
spin_lock_irqsave(&dev->spinlock, irq_flags);
intcsr = inb(dev_private->lcr_io_base +
PLX9050_REGISTER_INTERRUPT_CONTROL);
if (!(((intcsr & PLX9050_PCI_INTERRUPT_ENABLE) != 0)
&& (((intcsr & (PLX9050_LINTI1_ENABLE | PLX9050_LINTI1_STATUS))
== (PLX9050_LINTI1_ENABLE | PLX9050_LINTI1_STATUS))
|| ((intcsr & (PLX9050_LINTI2_ENABLE | PLX9050_LINTI2_STATUS))
== (PLX9050_LINTI2_ENABLE | PLX9050_LINTI2_STATUS))))) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return IRQ_NONE;
}
if ((intcsr & (PLX9050_LINTI1_ENABLE | PLX9050_LINTI1_STATUS)) ==
(PLX9050_LINTI1_ENABLE | PLX9050_LINTI1_STATUS)) {
if (pci9111_is_fifo_full()) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
comedi_error(dev, PCI9111_DRIVER_NAME " fifo overflow");
pci9111_interrupt_clear();
pci9111_ai_cancel(dev, subdevice);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
comedi_event(dev, subdevice);
return IRQ_HANDLED;
}
if (pci9111_is_fifo_half_full()) {
unsigned int num_samples;
unsigned int bytes_written = 0;
#ifdef INTERRUPT_DEBUG
printk(PCI9111_DRIVER_NAME ": fifo is half full\n");
#endif
num_samples =
PCI9111_FIFO_HALF_SIZE >
dev_private->stop_counter
&& !dev_private->
stop_is_none ? dev_private->stop_counter :
PCI9111_FIFO_HALF_SIZE;
insw(PCI9111_IO_BASE + PCI9111_REGISTER_AD_FIFO_VALUE,
dev_private->ai_bounce_buffer, num_samples);
if (dev_private->scan_delay < 1) {
bytes_written =
cfc_write_array_to_buffer(subdevice,
dev_private->
ai_bounce_buffer,
num_samples *
sizeof(short));
} else {
int position = 0;
int to_read;
while (position < num_samples) {
if (dev_private->chunk_counter <
dev_private->chanlist_len) {
to_read =
dev_private->chanlist_len -
dev_private->chunk_counter;
if (to_read >
num_samples - position)
to_read =
num_samples -
position;
bytes_written +=
cfc_write_array_to_buffer
(subdevice,
dev_private->ai_bounce_buffer
+ position,
to_read * sizeof(short));
} else {
to_read =
dev_private->chunk_num_samples
-
dev_private->chunk_counter;
if (to_read >
num_samples - position)
to_read =
num_samples -
position;
bytes_written +=
sizeof(short) * to_read;
}
position += to_read;
dev_private->chunk_counter += to_read;
if (dev_private->chunk_counter >=
dev_private->chunk_num_samples)
dev_private->chunk_counter = 0;
}
}
dev_private->stop_counter -=
bytes_written / sizeof(short);
}
}
if ((dev_private->stop_counter == 0) && (!dev_private->stop_is_none)) {
async->events |= COMEDI_CB_EOA;
pci9111_ai_cancel(dev, subdevice);
}
pci9111_interrupt_clear();
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
comedi_event(dev, subdevice);
return IRQ_HANDLED;
}
static int pci9111_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *subdevice,
struct comedi_insn *insn, unsigned int *data)
{
int resolution =
((struct pci9111_board *)dev->board_ptr)->ai_resolution;
int timeout, i;
#ifdef AI_INSN_DEBUG
printk(PCI9111_DRIVER_NAME ": ai_insn set c/r/n = %2x/%2x/%2x\n",
CR_CHAN((&insn->chanspec)[0]),
CR_RANGE((&insn->chanspec)[0]), insn->n);
#endif
pci9111_ai_channel_set(CR_CHAN((&insn->chanspec)[0]));
if ((pci9111_ai_range_get()) != CR_RANGE((&insn->chanspec)[0]))
pci9111_ai_range_set(CR_RANGE((&insn->chanspec)[0]));
pci9111_fifo_reset();
for (i = 0; i < insn->n; i++) {
pci9111_software_trigger();
timeout = PCI9111_AI_INSTANT_READ_TIMEOUT;
while (timeout--) {
if (!pci9111_is_fifo_empty())
goto conversion_done;
}
comedi_error(dev, "A/D read timeout");
data[i] = 0;
pci9111_fifo_reset();
return -ETIME;
conversion_done:
if (resolution == PCI9111_HR_AI_RESOLUTION)
data[i] = pci9111_hr_ai_get_data();
else
data[i] = pci9111_ai_get_data();
}
#ifdef AI_INSN_DEBUG
printk(PCI9111_DRIVER_NAME ": ai_insn get c/r/t = %2x/%2x/%2x\n",
pci9111_ai_channel_get(),
pci9111_ai_range_get(), pci9111_trigger_and_autoscan_get());
#endif
return i;
}
static int
pci9111_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++) {
pci9111_ao_set_data(data[i]);
dev_private->ao_readback = data[i];
}
return i;
}
static int pci9111_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = dev_private->ao_readback & PCI9111_AO_RESOLUTION_MASK;
return i;
}
static int pci9111_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *subdevice,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int bits;
bits = pci9111_di_get_bits();
data[1] = bits;
return insn->n;
}
static int pci9111_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *subdevice,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int bits;
data[0] &= PCI9111_DO_MASK;
bits = subdevice->state;
bits &= ~data[0];
bits |= data[0] & data[1];
subdevice->state = bits;
pci9111_do_set_bits(bits);
data[1] = bits;
return insn->n;
}
static int pci9111_reset(struct comedi_device *dev)
{
plx9050_interrupt_control(dev_private->lcr_io_base, true, true, true,
true, false);
pci9111_trigger_source_set(dev, software);
pci9111_pretrigger_set(dev, false);
pci9111_autoscan_set(dev, false);
dev_private->timer_divisor_1 = 0;
dev_private->timer_divisor_2 = 0;
pci9111_timer_set(dev);
return 0;
}
static struct pci_dev *pci9111_find_pci(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_ADLINK)
continue;
for (i = 0; i < pci9111_board_nbr; i++) {
if (pcidev->device != pci9111_boards[i].device_id)
continue;
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot)
continue;
}
dev->board_ptr = pci9111_boards + i;
printk(KERN_ERR
"comedi%d: found %s (b:s:f=%d:%d:%d), irq=%d\n",
dev->minor, pci9111_boards[i].name,
pcidev->bus->number, PCI_SLOT(pcidev->devfn),
PCI_FUNC(pcidev->devfn), pcidev->irq);
return pcidev;
}
}
printk(KERN_ERR
"comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
dev->minor, bus, slot);
return NULL;
}
static int pci9111_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
struct comedi_subdevice *subdevice;
unsigned long io_base, io_range, lcr_io_base, lcr_io_range;
int error;
const struct pci9111_board *board;
if (alloc_private(dev, sizeof(struct pci9111_private_data)) < 0)
return -ENOMEM;
printk(KERN_ERR "comedi%d: " PCI9111_DRIVER_NAME " driver\n",
dev->minor);
pcidev = pci9111_find_pci(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
board = (struct pci9111_board *)dev->board_ptr;
lcr_io_base = pci_resource_start(pcidev, 1);
lcr_io_range = pci_resource_len(pcidev, 1);
printk
("comedi%d: local configuration registers at address 0x%4lx [0x%4lx]\n",
dev->minor, lcr_io_base, lcr_io_range);
if (comedi_pci_enable(pcidev, PCI9111_DRIVER_NAME) < 0) {
printk
("comedi%d: Failed to enable PCI device and request regions\n",
dev->minor);
return -EIO;
}
io_base = pci_resource_start(pcidev, 2);
io_range = pci_resource_len(pcidev, 2);
printk(KERN_ERR "comedi%d: 6503 registers at address 0x%4lx [0x%4lx]\n",
dev->minor, io_base, io_range);
dev->iobase = io_base;
dev->board_name = board->name;
dev_private->io_range = io_range;
dev_private->is_valid = 0;
dev_private->lcr_io_base = lcr_io_base;
dev_private->lcr_io_range = lcr_io_range;
pci9111_reset(dev);
dev->irq = 0;
if (pcidev->irq > 0) {
dev->irq = pcidev->irq;
if (request_irq(dev->irq, pci9111_interrupt,
IRQF_SHARED, PCI9111_DRIVER_NAME, dev) != 0) {
printk(KERN_ERR
"comedi%d: unable to allocate irq %u\n",
dev->minor, dev->irq);
return -EINVAL;
}
}
error = comedi_alloc_subdevices(dev, 4);
if (error)
return error;
subdevice = dev->subdevices + 0;
dev->read_subdev = subdevice;
subdevice->type = COMEDI_SUBD_AI;
subdevice->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_CMD_READ;
subdevice->n_chan = board->ai_channel_nbr;
subdevice->maxdata = board->ai_resolution_mask;
subdevice->len_chanlist = board->ai_channel_nbr;
subdevice->range_table = board->ai_range_list;
subdevice->cancel = pci9111_ai_cancel;
subdevice->insn_read = pci9111_ai_insn_read;
subdevice->do_cmdtest = pci9111_ai_do_cmd_test;
subdevice->do_cmd = pci9111_ai_do_cmd;
subdevice->munge = pci9111_ai_munge;
subdevice = dev->subdevices + 1;
subdevice->type = COMEDI_SUBD_AO;
subdevice->subdev_flags = SDF_WRITABLE | SDF_COMMON;
subdevice->n_chan = board->ao_channel_nbr;
subdevice->maxdata = board->ao_resolution_mask;
subdevice->len_chanlist = board->ao_channel_nbr;
subdevice->range_table = board->ao_range_list;
subdevice->insn_write = pci9111_ao_insn_write;
subdevice->insn_read = pci9111_ao_insn_read;
subdevice = dev->subdevices + 2;
subdevice->type = COMEDI_SUBD_DI;
subdevice->subdev_flags = SDF_READABLE;
subdevice->n_chan = PCI9111_DI_CHANNEL_NBR;
subdevice->maxdata = 1;
subdevice->range_table = &range_digital;
subdevice->insn_bits = pci9111_di_insn_bits;
subdevice = dev->subdevices + 3;
subdevice->type = COMEDI_SUBD_DO;
subdevice->subdev_flags = SDF_READABLE | SDF_WRITABLE;
subdevice->n_chan = PCI9111_DO_CHANNEL_NBR;
subdevice->maxdata = 1;
subdevice->range_table = &range_digital;
subdevice->insn_bits = pci9111_do_insn_bits;
dev_private->is_valid = 1;
return 0;
}
static void pci9111_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->private != NULL) {
if (dev_private->is_valid)
pci9111_reset(dev);
}
if (dev->irq != 0)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit pci9111_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci9111_driver);
}
static void __devexit pci9111_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
