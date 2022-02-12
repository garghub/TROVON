static int pcl726_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int pcl726_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int pcl726_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl726_private *devpriv = dev->private;
devpriv->cmd_running = 1;
return 0;
}
static int pcl726_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl726_private *devpriv = dev->private;
devpriv->cmd_running = 0;
return 0;
}
static irqreturn_t pcl726_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct pcl726_private *devpriv = dev->private;
if (devpriv->cmd_running) {
pcl726_intr_cancel(dev, s);
comedi_buf_write_samples(s, &s->state, 1);
comedi_handle_events(dev, s);
}
return IRQ_HANDLED;
}
static int pcl726_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
if (comedi_chan_range_is_bipolar(s, chan, range))
val = comedi_offset_munge(s, val);
outb((val >> 8) & 0xff, dev->iobase + PCL726_AO_MSB_REG(chan));
outb(val & 0xff, dev->iobase + PCL726_AO_LSB_REG(chan));
}
return insn->n;
}
static int pcl726_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct pcl726_board *board = dev->board_ptr;
unsigned int val;
if (board->is_pcl727) {
val = inb(dev->iobase + PCL727_DI_LSB_REG);
val |= (inb(dev->iobase + PCL727_DI_MSB_REG) << 8);
} else {
val = inb(dev->iobase + PCL726_DI_LSB_REG);
val |= (inb(dev->iobase + PCL726_DI_MSB_REG) << 8);
}
data[1] = val;
return insn->n;
}
static int pcl726_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct pcl726_board *board = dev->board_ptr;
unsigned long io = dev->iobase;
unsigned int mask;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (board->is_pcl727) {
if (mask & 0x00ff)
outb(s->state & 0xff, io + PCL727_DO_LSB_REG);
if (mask & 0xff00)
outb((s->state >> 8), io + PCL727_DO_MSB_REG);
} else {
if (mask & 0x00ff)
outb(s->state & 0xff, io + PCL726_DO_LSB_REG);
if (mask & 0xff00)
outb((s->state >> 8), io + PCL726_DO_MSB_REG);
}
}
data[1] = s->state;
return insn->n;
}
static int pcl726_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pcl726_board *board = dev->board_ptr;
struct pcl726_private *devpriv;
struct comedi_subdevice *s;
int subdev;
int ret;
int i;
ret = comedi_request_region(dev, it->options[0], board->io_len);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
if (it->options[1] && (board->irq_mask & (1 << it->options[1]))) {
ret = request_irq(it->options[1], pcl726_interrupt, 0,
dev->board_name, dev);
if (ret == 0) {
dev->irq = it->options[1];
}
}
for (i = 0; i < 12; i++) {
unsigned int opt = it->options[2 + i];
if (opt < board->ao_num_ranges && i < board->ao_nchan)
devpriv->rangelist[i] = board->ao_ranges[opt];
else
devpriv->rangelist[i] = &range_unknown;
}
subdev = board->have_dio ? 3 : 1;
if (dev->irq)
subdev++;
ret = comedi_alloc_subdevices(dev, subdev);
if (ret)
return ret;
subdev = 0;
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->ao_nchan;
s->maxdata = 0x0fff;
s->range_table_list = devpriv->rangelist;
s->insn_write = pcl726_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
if (board->have_dio) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->insn_bits = pcl726_di_insn_bits;
s->range_table = &range_digital;
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->insn_bits = pcl726_do_insn_bits;
s->range_table = &range_digital;
}
if (dev->irq) {
s = &dev->subdevices[subdev++];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl726_intr_insn_bits;
s->len_chanlist = 1;
s->do_cmdtest = pcl726_intr_cmdtest;
s->do_cmd = pcl726_intr_cmd;
s->cancel = pcl726_intr_cancel;
}
return 0;
}
