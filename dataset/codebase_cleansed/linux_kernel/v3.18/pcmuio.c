static inline unsigned long pcmuio_asic_iobase(struct comedi_device *dev,
int asic)
{
return dev->iobase + (asic * PCMUIO_ASIC_IOSIZE);
}
static inline int pcmuio_subdevice_to_asic(struct comedi_subdevice *s)
{
return s->index / 2;
}
static inline int pcmuio_subdevice_to_port(struct comedi_subdevice *s)
{
return (s->index % 2) ? 3 : 0;
}
static void pcmuio_write(struct comedi_device *dev, unsigned int val,
int asic, int page, int port)
{
struct pcmuio_private *devpriv = dev->private;
struct pcmuio_asic *chip = &devpriv->asics[asic];
unsigned long iobase = pcmuio_asic_iobase(dev, asic);
unsigned long flags;
spin_lock_irqsave(&chip->pagelock, flags);
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
spin_unlock_irqrestore(&chip->pagelock, flags);
}
static unsigned int pcmuio_read(struct comedi_device *dev,
int asic, int page, int port)
{
struct pcmuio_private *devpriv = dev->private;
struct pcmuio_asic *chip = &devpriv->asics[asic];
unsigned long iobase = pcmuio_asic_iobase(dev, asic);
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&chip->pagelock, flags);
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
spin_unlock_irqrestore(&chip->pagelock, flags);
return val;
}
static int pcmuio_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int asic = pcmuio_subdevice_to_asic(s);
int port = pcmuio_subdevice_to_port(s);
unsigned int chanmask = (1 << s->n_chan) - 1;
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
val = ~s->state & chanmask;
val &= s->io_bits;
pcmuio_write(dev, val, asic, 0, port);
}
val = pcmuio_read(dev, asic, 0, port);
data[1] = ~val & chanmask;
return insn->n;
}
static int pcmuio_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int asic = pcmuio_subdevice_to_asic(s);
int port = pcmuio_subdevice_to_port(s);
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
const struct pcmuio_board *board = dev->board_ptr;
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
struct pcmuio_private *devpriv = dev->private;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
chip->enabled_mask = 0;
chip->active = 0;
s->async->inttrig = NULL;
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_ENAB, 0);
}
static void pcmuio_handle_intr_subdev(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned triggered)
{
struct pcmuio_private *devpriv = dev->private;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
struct comedi_cmd *cmd = &s->async->cmd;
unsigned oldevents = s->async->events;
unsigned int val = 0;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&chip->spinlock, flags);
if (!chip->active)
goto done;
if (!(triggered & chip->enabled_mask))
goto done;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
if (triggered & (1 << chan))
val |= (1 << i);
}
if (comedi_buf_put(s, val) &&
comedi_buf_put(s, val >> 16)) {
s->async->events |= (COMEDI_CB_BLOCK | COMEDI_CB_EOS);
} else {
pcmuio_stop_intr(dev, s);
}
if (cmd->stop_src == TRIG_COUNT) {
if (chip->stop_count > 0) {
chip->stop_count--;
if (chip->stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
pcmuio_stop_intr(dev, s);
}
}
}
done:
spin_unlock_irqrestore(&chip->spinlock, flags);
if (oldevents != s->async->events)
comedi_event(dev, s);
}
static int pcmuio_handle_asic_interrupt(struct comedi_device *dev, int asic)
{
struct comedi_subdevice *s = &dev->subdevices[asic * 2];
unsigned long iobase = pcmuio_asic_iobase(dev, asic);
unsigned int val;
val = inb(iobase + PCMUIO_INT_PENDING_REG) & 0x07;
if (!val)
return 0;
val = pcmuio_read(dev, asic, PCMUIO_PAGE_INT_ID, 0);
pcmuio_write(dev, 0, asic, PCMUIO_PAGE_INT_ID, 0);
pcmuio_handle_intr_subdev(dev, s, val);
return 1;
}
static irqreturn_t pcmuio_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcmuio_private *devpriv = dev->private;
int handled = 0;
if (irq == dev->irq)
handled += pcmuio_handle_asic_interrupt(dev, 0);
if (irq == devpriv->irq2)
handled += pcmuio_handle_asic_interrupt(dev, 1);
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static void pcmuio_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmuio_private *devpriv = dev->private;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int bits = 0;
unsigned int pol_bits = 0;
int i;
chip->enabled_mask = 0;
chip->active = 1;
if (cmd->chanlist) {
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chanspec = cmd->chanlist[i];
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
bits |= (1 << chan);
pol_bits |= ((aref || range) ? 1 : 0) << chan;
}
}
bits &= ((1 << s->n_chan) - 1);
chip->enabled_mask = bits;
pcmuio_write(dev, pol_bits, asic, PCMUIO_PAGE_POL, 0);
pcmuio_write(dev, bits, asic, PCMUIO_PAGE_ENAB, 0);
}
static int pcmuio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcmuio_private *devpriv = dev->private;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
unsigned long flags;
spin_lock_irqsave(&chip->spinlock, flags);
if (chip->active)
pcmuio_stop_intr(dev, s);
spin_unlock_irqrestore(&chip->spinlock, flags);
return 0;
}
static int pcmuio_inttrig_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pcmuio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
unsigned long flags;
if (trig_num != cmd->start_arg)
return -EINVAL;
spin_lock_irqsave(&chip->spinlock, flags);
s->async->inttrig = NULL;
if (chip->active)
pcmuio_start_intr(dev, s);
spin_unlock_irqrestore(&chip->spinlock, flags);
return 1;
}
static int pcmuio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcmuio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int asic = pcmuio_subdevice_to_asic(s);
struct pcmuio_asic *chip = &devpriv->asics[asic];
unsigned long flags;
spin_lock_irqsave(&chip->spinlock, flags);
chip->active = 1;
chip->stop_count = cmd->stop_arg;
if (cmd->start_src == TRIG_INT)
s->async->inttrig = pcmuio_inttrig_start_intr;
else
pcmuio_start_intr(dev, s);
spin_unlock_irqrestore(&chip->spinlock, flags);
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
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int pcmuio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcmuio_board *board = dev->board_ptr;
struct comedi_subdevice *s;
struct pcmuio_private *devpriv;
int ret;
int i;
ret = comedi_request_region(dev, it->options[0],
board->num_asics * PCMUIO_ASIC_IOSIZE);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
for (i = 0; i < PCMUIO_MAX_ASICS; ++i) {
struct pcmuio_asic *chip = &devpriv->asics[i];
spin_lock_init(&chip->pagelock);
spin_lock_init(&chip->spinlock);
}
pcmuio_reset(dev);
if (it->options[1]) {
ret = request_irq(it->options[1], pcmuio_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
if (board->num_asics == 2) {
if (it->options[2] == dev->irq) {
devpriv->irq2 = it->options[2];
} else if (it->options[2]) {
ret = request_irq(it->options[2], pcmuio_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
devpriv->irq2 = it->options[2];
}
}
ret = comedi_alloc_subdevices(dev, board->num_asics * 2);
if (ret)
return ret;
for (i = 0; i < dev->n_subdevices; ++i) {
s = &dev->subdevices[i];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcmuio_dio_insn_bits;
s->insn_config = pcmuio_dio_insn_config;
if ((i == 0 && dev->irq) || (i == 2 && devpriv->irq2)) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->cancel = pcmuio_cancel;
s->do_cmd = pcmuio_cmd;
s->do_cmdtest = pcmuio_cmdtest;
}
}
return 0;
}
static void pcmuio_detach(struct comedi_device *dev)
{
struct pcmuio_private *devpriv = dev->private;
if (devpriv) {
pcmuio_reset(dev);
if (devpriv->irq2 && devpriv->irq2 != dev->irq)
free_irq(devpriv->irq2, dev);
}
comedi_legacy_detach(dev);
}
