static int pcl726_ao_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int hi, lo;
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++) {
lo = data[n] & 0xff;
hi = (data[n] >> 8) & 0xf;
if (devpriv->bipolar[chan])
hi ^= 0x8;
outb(hi, dev->iobase + PCL726_DAC0_HI + 2 * chan);
outb(lo, dev->iobase + PCL726_DAC0_LO + 2 * chan);
devpriv->ao_readback[chan] = data[n];
}
return n;
}
static int pcl726_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
int n;
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_readback[chan];
return n;
}
static int pcl726_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct pcl726_board *board = comedi_board(dev);
data[1] = inb(dev->iobase + board->di_lo) |
(inb(dev->iobase + board->di_hi) << 8);
return insn->n;
}
static int pcl726_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct pcl726_board *board = comedi_board(dev);
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
}
if (data[1] & 0x00ff)
outb(s->state & 0xff, dev->iobase + board->do_lo);
if (data[1] & 0xff00)
outb((s->state >> 8), dev->iobase + board->do_hi);
data[1] = s->state;
return insn->n;
}
static int pcl726_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl726_board *board = comedi_board(dev);
struct comedi_subdevice *s;
unsigned long iobase;
unsigned int iorange;
int ret, i;
#ifdef ACL6126_IRQ
unsigned int irq;
#endif
iobase = it->options[0];
iorange = board->io_range;
printk(KERN_WARNING "comedi%d: pcl726: board=%s, 0x%03lx ", dev->minor,
board->name, iobase);
if (!request_region(iobase, iorange, "pcl726")) {
printk(KERN_WARNING "I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = board->name;
ret = alloc_private(dev, sizeof(struct pcl726_private));
if (ret < 0)
return -ENOMEM;
for (i = 0; i < 12; i++) {
devpriv->bipolar[i] = 0;
devpriv->rangelist[i] = &range_unknown;
}
#ifdef ACL6126_IRQ
irq = 0;
if (boardtypes[board].IRQbits != 0) {
irq = it->options[1];
devpriv->first_chan = 2;
if (irq) {
if (((1 << irq) & boardtypes[board].IRQbits) == 0) {
printk(KERN_WARNING
", IRQ %d is out of allowed range,"
" DISABLING IT", irq);
irq = 0;
} else {
if (request_irq(irq, interrupt_pcl818, 0,
"pcl726", dev)) {
printk(KERN_WARNING
", unable to allocate IRQ %d,"
" DISABLING IT", irq);
irq = 0;
} else {
printk(", irq=%d", irq);
}
}
}
}
dev->irq = irq;
#endif
printk("\n");
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = 0xfff;
s->len_chanlist = 1;
s->insn_write = pcl726_ao_insn;
s->insn_read = pcl726_ao_insn_read;
s->range_table_list = devpriv->rangelist;
for (i = 0; i < board->n_aochan; i++) {
int j;
j = it->options[2 + 1];
if ((j < 0) || (j >= board->num_of_ranges)) {
printk
("Invalid range for channel %d! Must be 0<=%d<%d\n",
i, j, board->num_of_ranges - 1);
j = 0;
}
devpriv->rangelist[i] = board->range_type_list[j];
if (devpriv->rangelist[i]->range[0].min ==
-devpriv->rangelist[i]->range[0].max)
devpriv->bipolar[i] = 1;
}
s = &dev->subdevices[1];
if (!board->have_dio) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 1;
s->len_chanlist = 1;
s->insn_bits = pcl726_di_insn_bits;
s->range_table = &range_digital;
}
s = &dev->subdevices[2];
if (!board->have_dio) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 1;
s->len_chanlist = 1;
s->insn_bits = pcl726_do_insn_bits;
s->range_table = &range_digital;
}
return 0;
}
static void pcl726_detach(struct comedi_device *dev)
{
const struct pcl726_board *board = comedi_board(dev);
#ifdef ACL6126_IRQ
if (dev->irq)
free_irq(dev->irq, dev);
#endif
if (dev->iobase)
release_region(dev->iobase, board->io_range);
}
