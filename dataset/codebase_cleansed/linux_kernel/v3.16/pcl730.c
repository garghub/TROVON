static int pcl730_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned int mask;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0x00ff)
outb(s->state & 0xff, dev->iobase + reg);
if ((mask & 0xff00) && (s->n_chan > 8))
outb((s->state >> 8) & 0xff, dev->iobase + reg + 1);
if ((mask & 0xff0000) && (s->n_chan > 16))
outb((s->state >> 16) & 0xff, dev->iobase + reg + 2);
if ((mask & 0xff000000) && (s->n_chan > 24))
outb((s->state >> 24) & 0xff, dev->iobase + reg + 3);
}
data[1] = s->state;
return insn->n;
}
static unsigned int pcl730_get_bits(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned long reg = (unsigned long)s->private;
unsigned int val;
val = inb(dev->iobase + reg);
if (s->n_chan > 8)
val |= (inb(dev->iobase + reg + 1) << 8);
if (s->n_chan > 16)
val |= (inb(dev->iobase + reg + 2) << 16);
if (s->n_chan > 24)
val |= (inb(dev->iobase + reg + 3) << 24);
return val;
}
static int pcl730_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = pcl730_get_bits(dev, s);
return insn->n;
}
static int pcl730_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pcl730_board *board = comedi_board(dev);
struct comedi_subdevice *s;
int subdev;
int ret;
ret = comedi_request_region(dev, it->options[0], board->io_range);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, board->n_subdevs);
if (ret)
return ret;
subdev = 0;
if (board->n_iso_out_chan) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_iso_out_chan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl730_do_insn_bits;
s->private = (void *)0;
if (board->has_readback)
s->state = pcl730_get_bits(dev, s);
}
if (board->n_iso_in_chan) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_iso_in_chan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl730_di_insn_bits;
s->private = board->is_acl7225b ? (void *)2 :
board->is_pcl725 ? (void *)1 : (void *)0;
}
if (board->has_ttl_io) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_ttl_chan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl730_do_insn_bits;
s->private = (void *)2;
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_ttl_chan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl730_di_insn_bits;
s->private = (void *)2;
}
return 0;
}
