static void pcmuio_write(struct comedi_device *dev, unsigned int val,
int asic, int page, int port)
{
unsigned long iobase = dev->iobase + (asic * PCMUIO_ASIC_IOSIZE);
if (page == 0) {
outb(val & 0xff, iobase + PCMUIO_PORT_REG(port + 0));
outb((val >> 8) & 0xff, iobase + PCMUIO_PORT_REG(port + 1));
outb((val >> 16) & 0xff, iobase + PCMUIO_PORT_REG(port + 2));
} else {
outb(PCMUIO_PAGE(page), iobase + PCMUIO_PAGE_LOCK_REG);
outb(val & 0xff, iobase + PCMUIO_PAGE_REG(0));
outb((val >> 8) & 0xff, iobase + PCMUIO_PAGE_REG(1));
outb((val >> 16) & 0xff, iobase + PCMUIO_PAGE_REG(2));
}
}
static unsigned int pcmuio_read(struct comedi_device *dev,
int asic, int page, int port)
{
unsigned long iobase = dev->iobase + (asic * PCMUIO_ASIC_IOSIZE);
unsigned int val;
if (page == 0) {
val = inb(iobase + PCMUIO_PORT_REG(port + 0));
val |= (inb(iobase + PCMUIO_PORT_REG(port + 1)) << 8);
val |= (inb(iobase + PCMUIO_PORT_REG(port + 2)) << 16);
} else {
outb(PCMUIO_PAGE(page), iobase + PCMUIO_PAGE_LOCK_REG);
val = inb(iobase + PCMUIO_PAGE_REG(0));
val |= (inb(iobase + PCMUIO_PAGE_REG(1)) << 8);
val |= (inb(iobase + PCMUIO_PAGE_REG(2)) << 16);
}
return val;
}
static int pcmuio_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int mask = data[0] & s->io_bits;
unsigned int bits = data[1];
int asic = s->index / 2;
int port = (s->index % 2) ? 3 : 0;
unsigned int val;
val = pcmuio_read(dev, asic, 0, port);
s->state = val ^ ((0x1 << s->n_chan) - 1);
if (mask) {
s->state &= ~mask;
s->state |= (mask & bits);
val = s->state ^ ((0x1 << s->n_chan) - 1);
pcmuio_write(dev, val, asic, 0, port);
}
data[1] = s->state;
return insn->n;
}
static int pcmuio_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int asic = s->index / 2;
int port = (s->index % 2) ? 3 : 0;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
if (data[0] == INSN_CONFIG_DIO_INPUT)
pcmuio_write(dev, s->io_bits, asic, 0, port);
return insn->n;
}
static void pcmuio_reset(struct comedi_device *dev)
{
const struct pcmuio_board *board = comedi_board(dev);
int asic;
for (asic = 0; asic < board->num_asics; ++asic) {
pcmuio_write(dev, 0, asic, 0, 0);
pcmuio_write(dev, 0, asic, 0, 3);
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_POL, 0);
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_ENAB, 0);
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_INT_ID, 0);
}
}
static void pcmuio_stop_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmuio_subdev_private *subpriv = s->private;
int asic;
asic = subpriv->intr.asic;
if (asic < 0)
return;
subpriv->intr.enabled_mask = 0;
subpriv->intr.active = 0;
s->async->inttrig = NULL;
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_ENAB, 0);
}
static void pcmuio_handle_intr_subdev(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned triggered)
{
struct pcmuio_subdev_private *subpriv = s->private;
unsigned int len = s->async->cmd.chanlist_len;
unsigned oldevents = s->async->events;
unsigned int val = 0;
unsigned long flags;
unsigned mytrig;
unsigned int i;
spin_lock_irqsave(&subpriv->intr.spinlock, flags);
if (!subpriv->intr.active)
goto done;
mytrig = triggered;
mytrig &= ((0x1 << s->n_chan) - 1);
if (!(mytrig & subpriv->intr.enabled_mask))
goto done;
for (i = 0; i < len; i++) {
unsigned int chan = CR_CHAN(s->async->cmd.chanlist[i]);
if (mytrig & (1U << chan))
val |= (1U << i);
}
if (comedi_buf_put(s->async, val) &&
comedi_buf_put(s->async, val >> 16)) {
s->async->events |= (COMEDI_CB_BLOCK | COMEDI_CB_EOS);
} else {
pcmuio_stop_intr(dev, s);
}
if (!subpriv->intr.continuous) {
if (subpriv->intr.stop_count > 0) {
subpriv->intr.stop_count--;
if (subpriv->intr.stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
pcmuio_stop_intr(dev, s);
}
}
}
done:
spin_unlock_irqrestore(&subpriv->intr.spinlock, flags);
if (oldevents != s->async->events)
comedi_event(dev, s);
}
static int pcmuio_handle_asic_interrupt(struct comedi_device *dev, int asic)
{
struct pcmuio_private *devpriv = dev->private;
struct pcmuio_subdev_private *subpriv;
unsigned long iobase = dev->iobase + (asic * PCMUIO_ASIC_IOSIZE);
unsigned int triggered = 0;
int got1 = 0;
unsigned long flags;
unsigned char int_pend;
int i;
spin_lock_irqsave(&devpriv->asics[asic].spinlock, flags);
int_pend = inb(iobase + PCMUIO_INT_PENDING_REG) & 0x07;
if (int_pend) {
triggered = pcmuio_read(dev, asic, PCMUIO_PAGE_INT_ID, 0);
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_INT_ID, 0);
++got1;
}
spin_unlock_irqrestore(&devpriv->asics[asic].spinlock, flags);
if (triggered) {
struct comedi_subdevice *s;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
subpriv = s->private;
if (subpriv->intr.asic == asic) {
pcmuio_handle_intr_subdev(dev, s,
triggered);
}
}
}
return got1;
}
static irqreturn_t pcmuio_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcmuio_private *devpriv = dev->private;
int got1 = 0;
int asic;
for (asic = 0; asic < PCMUIO_MAX_ASICS; ++asic) {
if (irq == devpriv->asics[asic].irq) {
if (pcmuio_handle_asic_interrupt(dev, asic))
got1++;
}
}
if (!got1)
return IRQ_NONE;
return IRQ_HANDLED;
}
static int pcmuio_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmuio_subdev_private *subpriv = s->private;
if (!subpriv->intr.continuous && subpriv->intr.stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
subpriv->intr.active = 0;
return 1;
} else {
unsigned bits = 0, pol_bits = 0, n;
int asic;
struct comedi_cmd *cmd = &s->async->cmd;
asic = subpriv->intr.asic;
if (asic < 0)
return 1;
subpriv->intr.enabled_mask = 0;
subpriv->intr.active = 1;
if (cmd->chanlist) {
for (n = 0; n < cmd->chanlist_len; n++) {
bits |= (1U << CR_CHAN(cmd->chanlist[n]));
pol_bits |= (CR_AREF(cmd->chanlist[n])
|| CR_RANGE(cmd->
chanlist[n]) ? 1U : 0U)
<< CR_CHAN(cmd->chanlist[n]);
}
}
bits &= ((0x1 << s->n_chan) - 1);
subpriv->intr.enabled_mask = bits;
pcmuio_write(dev, pol_bits, asic, PCMUIO_PAGE_POL, 0);
pcmuio_write(dev, bits, asic, PCMUIO_PAGE_ENAB, 0);
}
return 0;
}
static int pcmuio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcmuio_subdev_private *subpriv = s->private;
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
struct pcmuio_subdev_private *subpriv = s->private;
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
struct pcmuio_subdev_private *subpriv = s->private;
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
struct comedi_subdevice *s;
struct pcmuio_private *devpriv;
struct pcmuio_subdev_private *subpriv;
int sdev_no, n_subdevs, asic;
unsigned int irq[PCMUIO_MAX_ASICS];
int ret;
irq[0] = it->options[1];
irq[1] = it->options[2];
ret = comedi_request_region(dev, it->options[0],
board->num_asics * PCMUIO_ASIC_IOSIZE);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
for (asic = 0; asic < PCMUIO_MAX_ASICS; ++asic)
spin_lock_init(&devpriv->asics[asic].spinlock);
n_subdevs = board->num_asics * 2;
devpriv->sprivs = kcalloc(n_subdevs, sizeof(*subpriv), GFP_KERNEL);
if (!devpriv->sprivs)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, n_subdevs);
if (ret)
return ret;
for (sdev_no = 0; sdev_no < (int)dev->n_subdevices; ++sdev_no) {
s = &dev->subdevices[sdev_no];
subpriv = &devpriv->sprivs[sdev_no];
s->private = subpriv;
s->maxdata = 1;
s->range_table = &range_digital;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->type = COMEDI_SUBD_DIO;
s->insn_bits = pcmuio_dio_insn_bits;
s->insn_config = pcmuio_dio_insn_config;
s->n_chan = 24;
if ((sdev_no % 2) == 0) {
subpriv->intr.asic = sdev_no / 2;
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->cancel = pcmuio_cancel;
s->do_cmd = pcmuio_cmd;
s->do_cmdtest = pcmuio_cmdtest;
s->len_chanlist = s->n_chan;
} else {
subpriv->intr.asic = -1;
s->len_chanlist = 1;
}
spin_lock_init(&subpriv->intr.spinlock);
}
pcmuio_reset(dev);
for (asic = 0; irq[0] && asic < PCMUIO_MAX_ASICS; ++asic) {
if (irq[asic]
&& request_irq(irq[asic], pcmuio_interrupt,
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
return 0;
}
static void pcmuio_detach(struct comedi_device *dev)
{
struct pcmuio_private *devpriv = dev->private;
int i;
if (devpriv) {
for (i = 0; i < PCMUIO_MAX_ASICS; ++i) {
if (devpriv->asics[i].irq)
free_irq(devpriv->asics[i].irq, dev);
}
kfree(devpriv->sprivs);
}
comedi_legacy_detach(dev);
}
