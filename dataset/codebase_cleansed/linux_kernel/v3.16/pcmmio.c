static void pcmmio_dio_write(struct comedi_device *dev, unsigned int val,
int page, int port)
{
struct pcmmio_private *devpriv = dev->private;
unsigned long iobase = dev->iobase;
unsigned long flags;
spin_lock_irqsave(&devpriv->pagelock, flags);
if (page == 0) {
outb(val & 0xff, iobase + PCMMIO_PORT_REG(port + 0));
outb((val >> 8) & 0xff, iobase + PCMMIO_PORT_REG(port + 1));
outb((val >> 16) & 0xff, iobase + PCMMIO_PORT_REG(port + 2));
} else {
outb(PCMMIO_PAGE(page), iobase + PCMMIO_PAGE_LOCK_REG);
outb(val & 0xff, iobase + PCMMIO_PAGE_REG(0));
outb((val >> 8) & 0xff, iobase + PCMMIO_PAGE_REG(1));
outb((val >> 16) & 0xff, iobase + PCMMIO_PAGE_REG(2));
}
spin_unlock_irqrestore(&devpriv->pagelock, flags);
}
static unsigned int pcmmio_dio_read(struct comedi_device *dev,
int page, int port)
{
struct pcmmio_private *devpriv = dev->private;
unsigned long iobase = dev->iobase;
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&devpriv->pagelock, flags);
if (page == 0) {
val = inb(iobase + PCMMIO_PORT_REG(port + 0));
val |= (inb(iobase + PCMMIO_PORT_REG(port + 1)) << 8);
val |= (inb(iobase + PCMMIO_PORT_REG(port + 2)) << 16);
} else {
outb(PCMMIO_PAGE(page), iobase + PCMMIO_PAGE_LOCK_REG);
val = inb(iobase + PCMMIO_PAGE_REG(0));
val |= (inb(iobase + PCMMIO_PAGE_REG(1)) << 8);
val |= (inb(iobase + PCMMIO_PAGE_REG(2)) << 16);
}
spin_unlock_irqrestore(&devpriv->pagelock, flags);
return val;
}
static int pcmmio_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int port = s->index == 2 ? 0 : 3;
unsigned int chanmask = (1 << s->n_chan) - 1;
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
val = ~s->state & chanmask;
val &= s->io_bits;
pcmmio_dio_write(dev, val, 0, port);
}
val = pcmmio_dio_read(dev, 0, port);
data[1] = ~val & chanmask;
return insn->n;
}
static int pcmmio_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int port = s->index == 2 ? 0 : 3;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
if (data[0] == INSN_CONFIG_DIO_INPUT)
pcmmio_dio_write(dev, s->io_bits, 0, port);
return insn->n;
}
static void pcmmio_reset(struct comedi_device *dev)
{
pcmmio_dio_write(dev, 0, 0, 0);
pcmmio_dio_write(dev, 0, 0, 3);
pcmmio_dio_write(dev, 0, PCMMIO_PAGE_POL, 0);
pcmmio_dio_write(dev, 0, PCMMIO_PAGE_ENAB, 0);
pcmmio_dio_write(dev, 0, PCMMIO_PAGE_INT_ID, 0);
}
static void pcmmio_stop_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmmio_private *devpriv = dev->private;
devpriv->enabled_mask = 0;
devpriv->active = 0;
s->async->inttrig = NULL;
pcmmio_dio_write(dev, 0, PCMMIO_PAGE_ENAB, 0);
}
static void pcmmio_handle_dio_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int triggered)
{
struct pcmmio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int oldevents = s->async->events;
unsigned int val = 0;
unsigned long flags;
int i;
spin_lock_irqsave(&devpriv->spinlock, flags);
if (!devpriv->active)
goto done;
if (!(triggered & devpriv->enabled_mask))
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
pcmmio_stop_intr(dev, s);
}
if (cmd->stop_src == TRIG_COUNT && devpriv->stop_count > 0) {
devpriv->stop_count--;
if (devpriv->stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
pcmmio_stop_intr(dev, s);
}
}
done:
spin_unlock_irqrestore(&devpriv->spinlock, flags);
if (oldevents != s->async->events)
comedi_event(dev, s);
}
static irqreturn_t interrupt_pcmmio(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int triggered;
unsigned char int_pend;
int_pend = inb(dev->iobase + PCMMIO_INT_PENDING_REG) & 0x07;
if (!int_pend)
return IRQ_NONE;
triggered = pcmmio_dio_read(dev, PCMMIO_PAGE_INT_ID, 0);
pcmmio_dio_write(dev, 0, PCMMIO_PAGE_INT_ID, 0);
pcmmio_handle_dio_intr(dev, s, triggered);
return IRQ_HANDLED;
}
static int pcmmio_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcmmio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int bits = 0;
unsigned int pol_bits = 0;
int i;
if (cmd->stop_src == TRIG_COUNT && devpriv->stop_count == 0) {
s->async->events |= COMEDI_CB_EOA;
devpriv->active = 0;
return 1;
}
devpriv->enabled_mask = 0;
devpriv->active = 1;
if (cmd->chanlist) {
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chanspec = cmd->chanlist[i];
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
bits |= (1 << chan);
pol_bits |= (((aref || range) ? 1 : 0) << chan);
}
}
bits &= ((1 << s->n_chan) - 1);
devpriv->enabled_mask = bits;
pcmmio_dio_write(dev, pol_bits, PCMMIO_PAGE_POL, 0);
pcmmio_dio_write(dev, bits, PCMMIO_PAGE_ENAB, 0);
return 0;
}
static int pcmmio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcmmio_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->spinlock, flags);
if (devpriv->active)
pcmmio_stop_intr(dev, s);
spin_unlock_irqrestore(&devpriv->spinlock, flags);
return 0;
}
static int pcmmio_inttrig_start_intr(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pcmmio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
int event = 0;
if (trig_num != cmd->start_arg)
return -EINVAL;
spin_lock_irqsave(&devpriv->spinlock, flags);
s->async->inttrig = NULL;
if (devpriv->active)
event = pcmmio_start_intr(dev, s);
spin_unlock_irqrestore(&devpriv->spinlock, flags);
if (event)
comedi_event(dev, s);
return 1;
}
static int pcmmio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcmmio_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
int event = 0;
spin_lock_irqsave(&devpriv->spinlock, flags);
devpriv->active = 1;
if (cmd->stop_src == TRIG_COUNT)
devpriv->stop_count = cmd->stop_arg;
else
devpriv->stop_count = 0;
if (cmd->start_src == TRIG_INT)
s->async->inttrig = pcmmio_inttrig_start_intr;
else
event = pcmmio_start_intr(dev, s);
spin_unlock_irqrestore(&devpriv->spinlock, flags);
if (event)
comedi_event(dev, s);
return 0;
}
static int pcmmio_cmdtest(struct comedi_device *dev,
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
static int pcmmio_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + PCMMIO_AI_STATUS_REG);
if (status & PCMMIO_AI_STATUS_DATA_READY)
return 0;
return -EBUSY;
}
static int pcmmio_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long iobase = dev->iobase;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned char cmd = 0;
unsigned int val;
int ret;
int i;
if (chan > 7) {
chan -= 8;
iobase += PCMMIO_AI_2ND_ADC_OFFSET;
}
if (aref == AREF_GROUND)
cmd |= PCMMIO_AI_CMD_SE;
if (chan % 2)
cmd |= PCMMIO_AI_CMD_ODD_CHAN;
cmd |= PCMMIO_AI_CMD_CHAN_SEL(chan / 2);
cmd |= PCMMIO_AI_CMD_RANGE(range);
outb(cmd, iobase + PCMMIO_AI_CMD_REG);
ret = comedi_timeout(dev, s, insn, pcmmio_ai_eoc, 0);
if (ret)
return ret;
val = inb(iobase + PCMMIO_AI_LSB_REG);
val |= inb(iobase + PCMMIO_AI_MSB_REG) << 8;
for (i = 0; i < insn->n; i++) {
outb(cmd, iobase + PCMMIO_AI_CMD_REG);
ret = comedi_timeout(dev, s, insn, pcmmio_ai_eoc, 0);
if (ret)
return ret;
val = inb(iobase + PCMMIO_AI_LSB_REG);
val |= inb(iobase + PCMMIO_AI_MSB_REG) << 8;
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
data[i] = val;
}
return insn->n;
}
static int pcmmio_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcmmio_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static int pcmmio_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + PCMMIO_AO_STATUS_REG);
if (status & PCMMIO_AO_STATUS_DATA_READY)
return 0;
return -EBUSY;
}
static int pcmmio_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcmmio_private *devpriv = dev->private;
unsigned long iobase = dev->iobase;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val = devpriv->ao_readback[chan];
unsigned char cmd = 0;
int ret;
int i;
if (chan > 3) {
cmd |= PCMMIO_AO_CMD_CHAN_SEL(chan - 4);
iobase += PCMMIO_AO_2ND_DAC_OFFSET;
} else {
cmd |= PCMMIO_AO_CMD_CHAN_SEL(chan);
}
outb(PCMMIO_AO_LSB_SPAN(range), iobase + PCMMIO_AO_LSB_REG);
outb(0, iobase + PCMMIO_AO_MSB_REG);
outb(cmd | PCMMIO_AO_CMD_WR_SPAN_UPDATE, iobase + PCMMIO_AO_CMD_REG);
ret = comedi_timeout(dev, s, insn, pcmmio_ao_eoc, 0);
if (ret)
return ret;
for (i = 0; i < insn->n; i++) {
val = data[i];
outb(val & 0xff, iobase + PCMMIO_AO_LSB_REG);
outb((val >> 8) & 0xff, iobase + PCMMIO_AO_MSB_REG);
outb(cmd | PCMMIO_AO_CMD_WR_CODE_UPDATE,
iobase + PCMMIO_AO_CMD_REG);
ret = comedi_timeout(dev, s, insn, pcmmio_ao_eoc, 0);
if (ret)
return ret;
devpriv->ao_readback[chan] = val;
}
return insn->n;
}
static int pcmmio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pcmmio_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 32);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->pagelock);
spin_lock_init(&devpriv->spinlock);
pcmmio_reset(dev);
if (it->options[1]) {
ret = request_irq(it->options[1], interrupt_pcmmio, 0,
dev->board_name, dev);
if (ret == 0) {
dev->irq = it->options[1];
outb(PCMMIO_AI_RES_ENA_DIO_RES_ACCESS,
dev->iobase + PCMMIO_AI_RES_ENA_REG);
outb(PCMMIO_RESOURCE_IRQ(dev->irq),
dev->iobase + PCMMIO_RESOURCE_REG);
}
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0xffff;
s->range_table = &pcmmio_ai_ranges;
s->insn_read = pcmmio_ai_insn_read;
outb(PCMMIO_AI_RES_ENA_CMD_REG_ACCESS,
dev->iobase + PCMMIO_AI_RES_ENA_REG);
outb(PCMMIO_AI_RES_ENA_CMD_REG_ACCESS,
dev->iobase + PCMMIO_AI_RES_ENA_REG + PCMMIO_AI_2ND_ADC_OFFSET);
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 0xffff;
s->range_table = &pcmmio_ao_ranges;
s->insn_read = pcmmio_ao_insn_read;
s->insn_write = pcmmio_ao_insn_write;
outb(0, dev->iobase + PCMMIO_AO_RESOURCE_ENA_REG);
outb(0, dev->iobase + PCMMIO_AO_2ND_DAC_OFFSET +
PCMMIO_AO_RESOURCE_ENA_REG);
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->len_chanlist = 1;
s->range_table = &range_digital;
s->insn_bits = pcmmio_dio_insn_bits;
s->insn_config = pcmmio_dio_insn_config;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->cancel = pcmmio_cancel;
s->do_cmd = pcmmio_cmd;
s->do_cmdtest = pcmmio_cmdtest;
}
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcmmio_dio_insn_bits;
s->insn_config = pcmmio_dio_insn_config;
return 0;
}
