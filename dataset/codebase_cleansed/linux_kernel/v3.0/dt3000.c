static int __devinit driver_dt3000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, driver_dt3000.driver_name);
}
static void __devexit driver_dt3000_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_dt3000_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_dt3000);
if (retval < 0)
return retval;
driver_dt3000_pci_driver.name = (char *)driver_dt3000.driver_name;
return pci_register_driver(&driver_dt3000_pci_driver);
}
static void __exit driver_dt3000_cleanup_module(void)
{
pci_unregister_driver(&driver_dt3000_pci_driver);
comedi_driver_unregister(&driver_dt3000);
}
static int dt3k_send_cmd(struct comedi_device *dev, unsigned int cmd)
{
int i;
unsigned int status = 0;
writew(cmd, devpriv->io_addr + DPR_Command_Mbx);
for (i = 0; i < TIMEOUT; i++) {
status = readw(devpriv->io_addr + DPR_Command_Mbx);
if ((status & DT3000_COMPLETION_MASK) != DT3000_NOTPROCESSED)
break;
udelay(1);
}
if ((status & DT3000_COMPLETION_MASK) == DT3000_NOERROR)
return 0;
printk("dt3k_send_cmd() timeout/error status=0x%04x\n", status);
return -ETIME;
}
static unsigned int dt3k_readsingle(struct comedi_device *dev,
unsigned int subsys, unsigned int chan,
unsigned int gain)
{
writew(subsys, devpriv->io_addr + DPR_SubSys);
writew(chan, devpriv->io_addr + DPR_Params(0));
writew(gain, devpriv->io_addr + DPR_Params(1));
dt3k_send_cmd(dev, CMD_READSINGLE);
return readw(devpriv->io_addr + DPR_Params(2));
}
static void dt3k_writesingle(struct comedi_device *dev, unsigned int subsys,
unsigned int chan, unsigned int data)
{
writew(subsys, devpriv->io_addr + DPR_SubSys);
writew(chan, devpriv->io_addr + DPR_Params(0));
writew(0, devpriv->io_addr + DPR_Params(1));
writew(data, devpriv->io_addr + DPR_Params(2));
dt3k_send_cmd(dev, CMD_WRITESINGLE);
}
static irqreturn_t dt3k_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s;
unsigned int status;
if (!dev->attached)
return IRQ_NONE;
s = dev->subdevices + 0;
status = readw(devpriv->io_addr + DPR_Intr_Flag);
#ifdef DEBUG
debug_intr_flags(status);
#endif
if (status & DT3000_ADFULL) {
dt3k_ai_empty_fifo(dev, s);
s->async->events |= COMEDI_CB_BLOCK;
}
if (status & (DT3000_ADSWERR | DT3000_ADHWERR))
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
debug_n_ints++;
if (debug_n_ints >= 10) {
dt3k_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
}
comedi_event(dev, s);
return IRQ_HANDLED;
}
static void debug_intr_flags(unsigned int flags)
{
int i;
printk("dt3k: intr_flags:");
for (i = 0; i < 8; i++) {
if (flags & (1 << i))
printk(" %s", intr_flags[i]);
}
printk("\n");
}
static void dt3k_ai_empty_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int front;
int rear;
int count;
int i;
short data;
front = readw(devpriv->io_addr + DPR_AD_Buf_Front);
count = front - devpriv->ai_front;
if (count < 0)
count += AI_FIFO_DEPTH;
printk("reading %d samples\n", count);
rear = devpriv->ai_rear;
for (i = 0; i < count; i++) {
data = readw(devpriv->io_addr + DPR_ADC_buffer + rear);
comedi_buf_put(s->async, data);
rear++;
if (rear >= AI_FIFO_DEPTH)
rear = 0;
}
devpriv->ai_rear = rear;
writew(rear, devpriv->io_addr + DPR_AD_Buf_Rear);
}
static int dt3k_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER;
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
cmd->stop_src &= TRIG_COUNT;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->scan_begin_arg < this_board->ai_speed) {
cmd->scan_begin_arg = this_board->ai_speed;
err++;
}
if (cmd->scan_begin_arg > 100 * 16 * 65535) {
cmd->scan_begin_arg = 100 * 16 * 65535;
err++;
}
} else {
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < this_board->ai_speed) {
cmd->convert_arg = this_board->ai_speed;
err++;
}
if (cmd->convert_arg > 50 * 16 * 65535) {
cmd->convert_arg = 50 * 16 * 65535;
err++;
}
} else {
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0x00ffffff) {
cmd->stop_arg = 0x00ffffff;
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
dt3k_ns_to_timer(100, &cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
} else {
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
dt3k_ns_to_timer(50, &cmd->convert_arg,
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
} else {
}
if (err)
return 4;
return 0;
}
static int dt3k_ns_to_timer(unsigned int timer_base, unsigned int *nanosec,
unsigned int round_mode)
{
int divider, base, prescale;
for (prescale = 0; prescale < 16; prescale++) {
base = timer_base * (prescale + 1);
switch (round_mode) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
divider = (*nanosec) / base;
break;
}
if (divider < 65536) {
*nanosec = divider * base;
return (prescale << 16) | (divider);
}
}
prescale = 15;
base = timer_base * (1 << prescale);
divider = 65535;
*nanosec = divider * base;
return (prescale << 16) | (divider);
}
static int dt3k_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
int i;
unsigned int chan, range, aref;
unsigned int divider;
unsigned int tscandiv;
int ret;
unsigned int mode;
printk("dt3k_ai_cmd:\n");
for (i = 0; i < cmd->chanlist_len; i++) {
chan = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
writew((range << 6) | chan,
devpriv->io_addr + DPR_ADC_buffer + i);
}
aref = CR_AREF(cmd->chanlist[0]);
writew(cmd->scan_end_arg, devpriv->io_addr + DPR_Params(0));
printk("param[0]=0x%04x\n", cmd->scan_end_arg);
if (cmd->convert_src == TRIG_TIMER) {
divider = dt3k_ns_to_timer(50, &cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
writew((divider >> 16), devpriv->io_addr + DPR_Params(1));
printk("param[1]=0x%04x\n", divider >> 16);
writew((divider & 0xffff), devpriv->io_addr + DPR_Params(2));
printk("param[2]=0x%04x\n", divider & 0xffff);
} else {
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tscandiv = dt3k_ns_to_timer(100, &cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
writew((tscandiv >> 16), devpriv->io_addr + DPR_Params(3));
printk("param[3]=0x%04x\n", tscandiv >> 16);
writew((tscandiv & 0xffff), devpriv->io_addr + DPR_Params(4));
printk("param[4]=0x%04x\n", tscandiv & 0xffff);
} else {
}
mode = DT3000_AD_RETRIG_INTERNAL | 0 | 0;
writew(mode, devpriv->io_addr + DPR_Params(5));
printk("param[5]=0x%04x\n", mode);
writew(aref == AREF_DIFF, devpriv->io_addr + DPR_Params(6));
printk("param[6]=0x%04x\n", aref == AREF_DIFF);
writew(AI_FIFO_DEPTH / 2, devpriv->io_addr + DPR_Params(7));
printk("param[7]=0x%04x\n", AI_FIFO_DEPTH / 2);
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
ret = dt3k_send_cmd(dev, CMD_CONFIG);
writew(DT3000_ADFULL | DT3000_ADSWERR | DT3000_ADHWERR,
devpriv->io_addr + DPR_Int_Mask);
debug_n_ints = 0;
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
ret = dt3k_send_cmd(dev, CMD_START);
return 0;
}
static int dt3k_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
int ret;
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
ret = dt3k_send_cmd(dev, CMD_STOP);
writew(0, devpriv->io_addr + DPR_Int_Mask);
return 0;
}
static int dt3k_ai_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
unsigned int chan, gain, aref;
chan = CR_CHAN(insn->chanspec);
gain = CR_RANGE(insn->chanspec);
aref = CR_AREF(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = dt3k_readsingle(dev, SUBS_AI, chan, gain);
return i;
}
static int dt3k_ao_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
unsigned int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
dt3k_writesingle(dev, SUBS_AO, chan, data[i]);
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int dt3k_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
unsigned int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static void dt3k_dio_config(struct comedi_device *dev, int bits)
{
writew(SUBS_DOUT, devpriv->io_addr + DPR_SubSys);
writew(bits, devpriv->io_addr + DPR_Params(0));
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
dt3k_send_cmd(dev, CMD_CONFIG);
}
static int dt3k_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int mask;
mask = (CR_CHAN(insn->chanspec) < 4) ? 0x0f : 0xf0;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= mask;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~mask;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->
io_bits & (1 << CR_CHAN(insn->chanspec))) ? COMEDI_OUTPUT :
COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
mask = (s->io_bits & 0x01) | ((s->io_bits & 0x10) >> 3);
dt3k_dio_config(dev, mask);
return insn->n;
}
static int dt3k_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[1] & data[0];
dt3k_writesingle(dev, SUBS_DOUT, 0, s->state);
}
data[1] = dt3k_readsingle(dev, SUBS_DIN, 0, 0);
return 2;
}
static int dt3k_mem_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int addr = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
writew(SUBS_MEM, devpriv->io_addr + DPR_SubSys);
writew(addr, devpriv->io_addr + DPR_Params(0));
writew(1, devpriv->io_addr + DPR_Params(1));
dt3k_send_cmd(dev, CMD_READCODE);
data[i] = readw(devpriv->io_addr + DPR_Params(2));
}
return i;
}
static int dt3000_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int bus, slot;
int ret = 0;
printk("dt3000:");
bus = it->options[0];
slot = it->options[1];
ret = alloc_private(dev, sizeof(struct dt3k_private));
if (ret < 0)
return ret;
ret = dt_pci_probe(dev, bus, slot);
if (ret < 0)
return ret;
if (ret == 0) {
printk(" no DT board found\n");
return -ENODEV;
}
dev->board_name = this_board->name;
if (request_irq(devpriv->pci_dev->irq, dt3k_interrupt, IRQF_SHARED,
"dt3000", dev)) {
printk(" unable to allocate IRQ %u\n", devpriv->pci_dev->irq);
return -EINVAL;
}
dev->irq = devpriv->pci_dev->irq;
ret = alloc_subdevices(dev, 4);
if (ret < 0)
return ret;
s = dev->subdevices;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = this_board->adchan;
s->insn_read = dt3k_ai_insn;
s->maxdata = (1 << this_board->adbits) - 1;
s->len_chanlist = 512;
s->range_table = &range_dt3000_ai;
s->do_cmd = dt3k_ai_cmd;
s->do_cmdtest = dt3k_ai_cmdtest;
s->cancel = dt3k_ai_cancel;
s++;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->insn_read = dt3k_ao_insn_read;
s->insn_write = dt3k_ao_insn;
s->maxdata = (1 << this_board->dabits) - 1;
s->len_chanlist = 1;
s->range_table = &range_bipolar10;
s++;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->insn_config = dt3k_dio_insn_config;
s->insn_bits = dt3k_dio_insn_bits;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s++;
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE;
s->n_chan = 0x1000;
s->insn_read = dt3k_mem_insn_read;
s->maxdata = 0xff;
s->len_chanlist = 1;
s->range_table = &range_unknown;
#if 0
s++;
s->type = COMEDI_SUBD_PROC;
#endif
return 0;
}
static int dt3000_detach(struct comedi_device *dev)
{
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->pci_dev) {
if (devpriv->phys_addr)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
if (devpriv->io_addr)
iounmap(devpriv->io_addr);
}
return 0;
}
static int dt_pci_probe(struct comedi_device *dev, int bus, int slot)
{
int board;
int ret;
struct pci_dev *pcidev;
pcidev = NULL;
while ((pcidev = dt_pci_find_device(pcidev, &board)) != NULL) {
if ((bus == 0 && slot == 0) ||
(pcidev->bus->number == bus &&
PCI_SLOT(pcidev->devfn) == slot)) {
break;
}
}
devpriv->pci_dev = pcidev;
if (board >= 0)
dev->board_ptr = dt3k_boardtypes + board;
if (!devpriv->pci_dev)
return 0;
ret = setup_pci(dev);
if (ret < 0)
return ret;
return 1;
}
static int setup_pci(struct comedi_device *dev)
{
resource_size_t addr;
int ret;
ret = comedi_pci_enable(devpriv->pci_dev, "dt3000");
if (ret < 0)
return ret;
addr = pci_resource_start(devpriv->pci_dev, 0);
devpriv->phys_addr = addr;
devpriv->io_addr = ioremap(devpriv->phys_addr, DT3000_SIZE);
if (!devpriv->io_addr)
return -ENOMEM;
#if DEBUG
printk("0x%08llx mapped to %p, ",
(unsigned long long)devpriv->phys_addr, devpriv->io_addr);
#endif
return 0;
}
static struct pci_dev *dt_pci_find_device(struct pci_dev *from, int *board)
{
int i;
for (from = pci_get_device(PCI_VENDOR_ID_DT, PCI_ANY_ID, from);
from != NULL;
from = pci_get_device(PCI_VENDOR_ID_DT, PCI_ANY_ID, from)) {
for (i = 0; i < n_dt3k_boards; i++) {
if (from->device == dt3k_boardtypes[i].device_id) {
*board = i;
return from;
}
}
printk
("unknown Data Translation PCI device found with device_id=0x%04x\n",
from->device);
}
*board = -1;
return from;
}
