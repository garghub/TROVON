static int pcmuio_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int byte_no;
#ifdef DAMMIT_ITS_BROKEN
dev_dbg(dev->class_dev, "write mask: %08x data: %08x\n", data[0],
data[1]);
#endif
s->state = 0;
for (byte_no = 0; byte_no < s->n_chan / CHANS_PER_PORT; ++byte_no) {
unsigned long ioaddr = subpriv->iobases[byte_no],
offset = byte_no * 8;
unsigned char byte = 0,
write_mask_byte = (data[0] >> offset) & 0xff,
data_byte = (data[1] >> offset) & 0xff;
byte = inb(ioaddr);
#ifdef DAMMIT_ITS_BROKEN
printk
("byte %d wmb %02x db %02x offset %02d io %04x, data_in %02x ",
byte_no, (unsigned)write_mask_byte, (unsigned)data_byte,
offset, ioaddr, (unsigned)byte);
#endif
if (write_mask_byte) {
byte &= ~write_mask_byte;
byte |= ~data_byte & write_mask_byte;
outb(byte, ioaddr);
}
#ifdef DAMMIT_ITS_BROKEN
dev_dbg(dev->class_dev, "data_out_byte %02x\n", (unsigned)byte);
#endif
s->state |= ((unsigned int)byte) << offset;
}
data[1] = ~s->state;
#ifdef DAMMIT_ITS_BROKEN
dev_dbg(dev->class_dev, "s->state %08x data_out %08x\n", s->state,
data[1]);
#endif
return insn->n;
}
static int pcmuio_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec), byte_no = chan / 8, bit_no =
chan % 8;
unsigned long ioaddr;
unsigned char byte;
ioaddr = subpriv->iobases[byte_no];
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
byte = inb(ioaddr);
byte &= ~(1 << bit_no);
outb(byte, ioaddr);
s->io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
return insn->n;
}
static void switch_page(struct comedi_device *dev, int asic, int page)
{
const struct pcmuio_board *board = comedi_board(dev);
struct pcmuio_private *devpriv = dev->private;
if (asic < 0 || asic >= board->num_asics)
return;
if (page < 0 || page >= NUM_PAGES)
return;
devpriv->asics[asic].pagelock &= ~REG_PAGE_MASK;
devpriv->asics[asic].pagelock |= page << REG_PAGE_BITOFFSET;
outb(devpriv->asics[asic].pagelock,
dev->iobase + ASIC_IOSIZE * asic + REG_PAGELOCK);
}
static void init_asics(struct comedi_device *dev)
{
const struct pcmuio_board *board = comedi_board(dev);
int asic;
for (asic = 0; asic < board->num_asics; ++asic) {
int port, page;
unsigned long baseaddr = dev->iobase + asic * ASIC_IOSIZE;
switch_page(dev, asic, 0);
for (port = 0; port < PORTS_PER_ASIC; ++port)
outb(0, baseaddr + REG_PORT0 + port);
for (page = 1; page < NUM_PAGES; ++page) {
int reg;
switch_page(dev, asic, page);
for (reg = FIRST_PAGED_REG;
reg < FIRST_PAGED_REG + NUM_PAGED_REGS; ++reg)
outb(0, baseaddr + reg);
}
switch_page(dev, asic, 0);
}
}
static void lock_port(struct comedi_device *dev, int asic, int port)
{
const struct pcmuio_board *board = comedi_board(dev);
struct pcmuio_private *devpriv = dev->private;
if (asic < 0 || asic >= board->num_asics)
return;
if (port < 0 || port >= PORTS_PER_ASIC)
return;
devpriv->asics[asic].pagelock |= 0x1 << port;
outb(devpriv->asics[asic].pagelock,
dev->iobase + ASIC_IOSIZE * asic + REG_PAGELOCK);
}
static void unlock_port(struct comedi_device *dev, int asic, int port)
{
const struct pcmuio_board *board = comedi_board(dev);
struct pcmuio_private *devpriv = dev->private;
if (asic < 0 || asic >= board->num_asics)
return;
if (port < 0 || port >= PORTS_PER_ASIC)
return;
devpriv->asics[asic].pagelock &= ~(0x1 << port) | REG_LOCK_MASK;
outb(devpriv->asics[asic].pagelock,
dev->iobase + ASIC_IOSIZE * asic + REG_PAGELOCK);
}
static void pcmuio_stop_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int nports, firstport, asic, port;
struct pcmuio_private *devpriv = dev->private;
asic = subpriv->intr.asic;
if (asic < 0)
return;
subpriv->intr.enabled_mask = 0;
subpriv->intr.active = 0;
s->async->inttrig = NULL;
nports = subpriv->intr.num_asic_chans / CHANS_PER_PORT;
firstport = subpriv->intr.asic_chan / CHANS_PER_PORT;
switch_page(dev, asic, PAGE_ENAB);
for (port = firstport; port < firstport + nports; ++port) {
outb(0, devpriv->asics[asic].iobase + REG_ENAB0 + port);
}
}
static irqreturn_t interrupt_pcmuio(int irq, void *d)
{
int asic, got1 = 0;
struct comedi_device *dev = (struct comedi_device *)d;
struct pcmuio_private *devpriv = dev->private;
int i;
for (asic = 0; asic < MAX_ASICS; ++asic) {
if (irq == devpriv->asics[asic].irq) {
unsigned long flags;
unsigned triggered = 0;
unsigned long iobase = devpriv->asics[asic].iobase;
unsigned char int_pend;
spin_lock_irqsave(&devpriv->asics[asic].spinlock,
flags);
int_pend = inb(iobase + REG_INT_PENDING) & 0x07;
if (int_pend) {
int port;
for (port = 0; port < INTR_PORTS_PER_ASIC;
++port) {
if (int_pend & (0x1 << port)) {
unsigned char
io_lines_with_edges = 0;
switch_page(dev, asic,
PAGE_INT_ID);
io_lines_with_edges =
inb(iobase +
REG_INT_ID0 + port);
if (io_lines_with_edges)
outb(0, iobase +
REG_INT_ID0 +
port);
triggered |=
io_lines_with_edges <<
port * 8;
}
}
++got1;
}
spin_unlock_irqrestore(&devpriv->asics[asic].spinlock,
flags);
if (triggered) {
struct comedi_subdevice *s;
printk
("PCMUIO DEBUG: got edge detect interrupt %d asic %d which_chans: %06x\n",
irq, asic, triggered);
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
if (subpriv->intr.asic == asic) {
unsigned long flags;
unsigned oldevents;
spin_lock_irqsave(&subpriv->
intr.spinlock,
flags);
oldevents = s->async->events;
if (subpriv->intr.active) {
unsigned mytrig =
((triggered >>
subpriv->intr.asic_chan)
&
((0x1 << subpriv->
intr.
num_asic_chans) -
1)) << subpriv->
intr.first_chan;
if (mytrig &
subpriv->intr.enabled_mask)
{
unsigned int val
= 0;
unsigned int n,
ch, len;
len =
s->
async->cmd.chanlist_len;
for (n = 0;
n < len;
n++) {
ch = CR_CHAN(s->async->cmd.chanlist[n]);
if (mytrig & (1U << ch)) {
val |= (1U << n);
}
}
if (comedi_buf_put(s->async, ((short *)&val)[0])
&&
comedi_buf_put
(s->async,
((short *)
&val)[1]))
{
s->async->events |= (COMEDI_CB_BLOCK | COMEDI_CB_EOS);
} else {
pcmuio_stop_intr
(dev,
s);
}
if (!subpriv->intr.continuous) {
if (subpriv->intr.stop_count > 0) {
subpriv->intr.stop_count--;
if (subpriv->intr.stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
pcmuio_stop_intr
(dev,
s);
}
}
}
}
}
spin_unlock_irqrestore
(&subpriv->intr.spinlock,
flags);
if (oldevents !=
s->async->events) {
comedi_event(dev, s);
}
}
}
}
}
}
if (!got1)
return IRQ_NONE;
return IRQ_HANDLED;
}
static int pcmuio_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmuio_private *devpriv = dev->private;
if (!subpriv->intr.continuous && subpriv->intr.stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
subpriv->intr.active = 0;
return 1;
} else {
unsigned bits = 0, pol_bits = 0, n;
int nports, firstport, asic, port;
struct comedi_cmd *cmd = &s->async->cmd;
asic = subpriv->intr.asic;
if (asic < 0)
return 1;
subpriv->intr.enabled_mask = 0;
subpriv->intr.active = 1;
nports = subpriv->intr.num_asic_chans / CHANS_PER_PORT;
firstport = subpriv->intr.asic_chan / CHANS_PER_PORT;
if (cmd->chanlist) {
for (n = 0; n < cmd->chanlist_len; n++) {
bits |= (1U << CR_CHAN(cmd->chanlist[n]));
pol_bits |= (CR_AREF(cmd->chanlist[n])
|| CR_RANGE(cmd->
chanlist[n]) ? 1U : 0U)
<< CR_CHAN(cmd->chanlist[n]);
}
}
bits &= ((0x1 << subpriv->intr.num_asic_chans) -
1) << subpriv->intr.first_chan;
subpriv->intr.enabled_mask = bits;
switch_page(dev, asic, PAGE_ENAB);
for (port = firstport; port < firstport + nports; ++port) {
unsigned enab =
bits >> (subpriv->intr.first_chan + (port -
firstport) *
8) & 0xff, pol =
pol_bits >> (subpriv->intr.first_chan +
(port - firstport) * 8) & 0xff;
outb(enab,
devpriv->asics[asic].iobase + REG_ENAB0 + port);
switch_page(dev, asic, PAGE_POL);
outb(pol,
devpriv->asics[asic].iobase + REG_ENAB0 + port);
}
}
return 0;
}
static int pcmuio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
unsigned long flags;
spin_lock_irqsave(&subpriv->intr.spinlock, flags);
if (subpriv->intr.active)
pcmuio_stop_intr(dev, s);
spin_unlock_irqrestore(&subpriv->intr.spinlock, flags);
return 0;
}
static int
pcmuio_inttrig_start_intr(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned int trignum)
{
unsigned long flags;
int event = 0;
if (trignum != 0)
return -EINVAL;
spin_lock_irqsave(&subpriv->intr.spinlock, flags);
s->async->inttrig = NULL;
if (subpriv->intr.active)
event = pcmuio_start_intr(dev, s);
spin_unlock_irqrestore(&subpriv->intr.spinlock, flags);
if (event)
comedi_event(dev, s);
return 1;
}
static int pcmuio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
int event = 0;
spin_lock_irqsave(&subpriv->intr.spinlock, flags);
subpriv->intr.active = 1;
switch (cmd->stop_src) {
case TRIG_COUNT:
subpriv->intr.continuous = 0;
subpriv->intr.stop_count = cmd->stop_arg;
break;
default:
subpriv->intr.continuous = 1;
subpriv->intr.stop_count = 0;
break;
}
switch (cmd->start_src) {
case TRIG_INT:
s->async->inttrig = pcmuio_inttrig_start_intr;
break;
default:
event = pcmuio_start_intr(dev, s);
break;
}
spin_unlock_irqrestore(&subpriv->intr.spinlock, flags);
if (event)
comedi_event(dev, s);
return 0;
}
static int pcmuio_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_COUNT:
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
return 0;
}
static int pcmuio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcmuio_board *board = comedi_board(dev);
struct pcmuio_private *devpriv;
struct comedi_subdevice *s;
int sdev_no, chans_left, n_subdevs, port, asic, thisasic_chanct = 0;
unsigned int irq[MAX_ASICS];
int ret;
irq[0] = it->options[1];
irq[1] = it->options[2];
ret = comedi_request_region(dev, it->options[0],
board->num_asics * ASIC_IOSIZE);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
for (asic = 0; asic < MAX_ASICS; ++asic) {
devpriv->asics[asic].num = asic;
devpriv->asics[asic].iobase = dev->iobase + asic * ASIC_IOSIZE;
devpriv->asics[asic].irq = 0;
spin_lock_init(&devpriv->asics[asic].spinlock);
}
chans_left = CHANS_PER_ASIC * board->num_asics;
n_subdevs = CALC_N_SUBDEVS(chans_left);
devpriv->sprivs = kcalloc(n_subdevs,
sizeof(struct pcmuio_subdev_private),
GFP_KERNEL);
if (!devpriv->sprivs)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, n_subdevs);
if (ret)
return ret;
port = 0;
asic = 0;
for (sdev_no = 0; sdev_no < (int)dev->n_subdevices; ++sdev_no) {
int byte_no;
s = &dev->subdevices[sdev_no];
s->private = &devpriv->sprivs[sdev_no];
s->maxdata = 1;
s->range_table = &range_digital;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->type = COMEDI_SUBD_DIO;
s->insn_bits = pcmuio_dio_insn_bits;
s->insn_config = pcmuio_dio_insn_config;
s->n_chan = min(chans_left, MAX_CHANS_PER_SUBDEV);
subpriv->intr.asic = -1;
subpriv->intr.first_chan = -1;
subpriv->intr.asic_chan = -1;
subpriv->intr.num_asic_chans = -1;
subpriv->intr.active = 0;
s->len_chanlist = 1;
for (byte_no = 0; byte_no < PORTS_PER_SUBDEV; ++byte_no, ++port) {
if (port >= PORTS_PER_ASIC) {
port = 0;
++asic;
thisasic_chanct = 0;
}
subpriv->iobases[byte_no] =
devpriv->asics[asic].iobase + port;
if (thisasic_chanct <
CHANS_PER_PORT * INTR_PORTS_PER_ASIC
&& subpriv->intr.asic < 0) {
subpriv->intr.asic = asic;
subpriv->intr.active = 0;
subpriv->intr.stop_count = 0;
subpriv->intr.first_chan = byte_no * 8;
subpriv->intr.asic_chan = thisasic_chanct;
subpriv->intr.num_asic_chans =
s->n_chan - subpriv->intr.first_chan;
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->cancel = pcmuio_cancel;
s->do_cmd = pcmuio_cmd;
s->do_cmdtest = pcmuio_cmdtest;
s->len_chanlist = subpriv->intr.num_asic_chans;
}
thisasic_chanct += CHANS_PER_PORT;
}
spin_lock_init(&subpriv->intr.spinlock);
chans_left -= s->n_chan;
if (!chans_left) {
asic = 0;
port = 0;
}
}
init_asics(dev);
for (asic = 0; irq[0] && asic < MAX_ASICS; ++asic) {
if (irq[asic]
&& request_irq(irq[asic], interrupt_pcmuio,
IRQF_SHARED, board->name, dev)) {
int i;
for (i = asic - 1; i >= 0; --i) {
free_irq(irq[i], dev);
devpriv->asics[i].irq = irq[i] = 0;
}
irq[asic] = 0;
}
devpriv->asics[asic].irq = irq[asic];
}
if (irq[0]) {
dev_dbg(dev->class_dev, "irq: %u\n", irq[0]);
if (irq[1] && board->num_asics == 2)
dev_dbg(dev->class_dev, "second ASIC irq: %u\n",
irq[1]);
} else {
dev_dbg(dev->class_dev, "(IRQ mode disabled)\n");
}
return 1;
}
static void pcmuio_detach(struct comedi_device *dev)
{
struct pcmuio_private *devpriv = dev->private;
int i;
for (i = 0; i < MAX_ASICS; ++i) {
if (devpriv->asics[i].irq)
free_irq(devpriv->asics[i].irq, dev);
}
if (devpriv && devpriv->sprivs)
kfree(devpriv->sprivs);
comedi_legacy_detach(dev);
}
