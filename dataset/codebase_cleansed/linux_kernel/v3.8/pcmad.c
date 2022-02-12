static int pcmad_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct pcmad_board_struct *board = comedi_board(dev);
struct pcmad_priv_struct *devpriv = dev->private;
int i;
int chan;
int n;
chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++) {
outb(chan, dev->iobase + PCMAD_CONVERT);
for (i = 0; i < TIMEOUT; i++) {
if ((inb(dev->iobase + PCMAD_STATUS) & 0x3) == 0x3)
break;
}
data[n] = inb(dev->iobase + PCMAD_LSB);
data[n] |= (inb(dev->iobase + PCMAD_MSB) << 8);
if (devpriv->twos_comp)
data[n] ^= (1 << (board->n_ai_bits - 1));
}
return n;
}
static int pcmad_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcmad_board_struct *board = comedi_board(dev);
struct pcmad_priv_struct *devpriv;
int ret;
struct comedi_subdevice *s;
unsigned long iobase;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: pcmad: 0x%04lx ", dev->minor, iobase);
if (!request_region(iobase, PCMAD_SIZE, "pcmad")) {
printk(KERN_CONT "I/O port conflict\n");
return -EIO;
}
printk(KERN_CONT "\n");
dev->iobase = iobase;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
dev->board_name = board->name;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | AREF_GROUND;
s->n_chan = 16;
s->len_chanlist = 1;
s->insn_read = pcmad_ai_insn_read;
s->maxdata = (1 << board->n_ai_bits) - 1;
s->range_table = &range_unknown;
return 0;
}
static void pcmad_detach(struct comedi_device *dev)
{
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->iobase)
release_region(dev->iobase, PCMAD_SIZE);
}
