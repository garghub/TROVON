static void das6402_ai_fifo_dregs(struct comedi_device *dev,
struct comedi_subdevice *s)
{
while (1) {
if (!(inb(dev->iobase + 8) & 0x01))
return;
comedi_buf_put(s->async, inw(dev->iobase));
}
}
static void das6402_setcounter(struct comedi_device *dev)
{
BYTE p;
unsigned short ctrlwrd;
p = M0 | C0 | RWLH;
outb_p(p, dev->iobase + 15);
ctrlwrd = 2000;
p = (BYTE) (0xff & ctrlwrd);
outb_p(p, dev->iobase + 12);
p = (BYTE) (0xff & (ctrlwrd >> 8));
outb_p(p, dev->iobase + 12);
p = M2 | C1 | RWLH;
outb_p(p, dev->iobase + 15);
ctrlwrd = 10;
p = (BYTE) (0xff & ctrlwrd);
outb_p(p, dev->iobase + 13);
p = (BYTE) (0xff & (ctrlwrd >> 8));
outb_p(p, dev->iobase + 13);
p = M2 | C2 | RWLH;
outb_p(p, dev->iobase + 15);
ctrlwrd = 1000;
p = (BYTE) (0xff & ctrlwrd);
outb_p(p, dev->iobase + 14);
p = (BYTE) (0xff & (ctrlwrd >> 8));
outb_p(p, dev->iobase + 14);
}
static irqreturn_t intr_handler(int irq, void *d)
{
struct comedi_device *dev = d;
struct das6402_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
if (!dev->attached || devpriv->das6402_ignoreirq) {
dev_warn(dev->class_dev, "BUG: spurious interrupt\n");
return IRQ_HANDLED;
}
das6402_ai_fifo_dregs(dev, s);
if (s->async->buf_write_count >= devpriv->ai_bytes_to_read) {
outw_p(SCANL, dev->iobase + 2);
outb(0x07, dev->iobase + 8);
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
}
outb(0x01, dev->iobase + 8);
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int das6402_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das6402_private *devpriv = dev->private;
devpriv->das6402_ignoreirq = 1;
dev_dbg(dev->class_dev, "Stopping acquisition\n");
devpriv->das6402_ignoreirq = 1;
outb_p(0x02, dev->iobase + 10);
outw_p(SCANL, dev->iobase + 2);
outb_p(0, dev->iobase + 9);
outw_p(SCANL, dev->iobase + 2);
return 0;
}
static int das6402_ai_mode2(struct comedi_device *dev,
struct comedi_subdevice *s, comedi_trig *it)
{
struct das6402_private *devpriv = dev->private;
devpriv->das6402_ignoreirq = 1;
dev_dbg(dev->class_dev, "Starting acquisition\n");
outb_p(0x03, dev->iobase + 10);
outw_p(SCANL, dev->iobase + 2);
outb_p(IRQ | CONVSRC | BURSTEN | INTE, dev->iobase + 9);
devpriv->ai_bytes_to_read = it->n * sizeof(short);
devpriv->das6402_ignoreirq = 0;
outw_p(SCANL, dev->iobase + 2);
return 0;
}
static int board_init(struct comedi_device *dev)
{
struct das6402_private *devpriv = dev->private;
BYTE b;
devpriv->das6402_ignoreirq = 1;
outb(0x07, dev->iobase + 8);
outb_p(MODE, dev->iobase + 11);
b = BIP | SEM | MODE | GAIN | FIFOHFULL;
outb_p(b, dev->iobase + 11);
outb_p(EXTEND, dev->iobase + 8);
b = EXTEND | MHZ;
outb_p(b, dev->iobase + 8);
b = MHZ | CLRINT | CLRXTR | CLRXIN;
outb_p(b, dev->iobase + 8);
b = IRQ | CONVSRC | BURSTEN | INTE;
outb_p(b, dev->iobase + 9);
b = TGSEL | TGEN;
outb_p(b, dev->iobase + 10);
b = 0x07;
outb_p(b, dev->iobase + 8);
das6402_setcounter(dev);
outw_p(SCANL, dev->iobase + 2);
devpriv->das6402_ignoreirq = 0;
return 0;
}
static int das6402_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct das6402_private *devpriv;
unsigned int irq;
int ret;
struct comedi_subdevice *s;
ret = comedi_request_region(dev, it->options[0], DAS6402_SIZE);
if (ret)
return ret;
irq = it->options[0];
dev_dbg(dev->class_dev, "( irq = %u )\n", irq);
ret = request_irq(irq, intr_handler, 0, "das6402", dev);
if (ret < 0)
return ret;
dev->irq = irq;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->cancel = das6402_ai_cancel;
s->maxdata = (1 << 12) - 1;
s->len_chanlist = 16;
s->range_table = &range_unknown;
board_init(dev);
return 0;
}
