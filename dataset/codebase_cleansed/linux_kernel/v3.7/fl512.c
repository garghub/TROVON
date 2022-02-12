static int fl512_ai_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int n;
unsigned int lo_byte, hi_byte;
char chan = CR_CHAN(insn->chanspec);
unsigned long iobase = dev->iobase;
for (n = 0; n < insn->n; n++) {
outb(chan, iobase + 2);
outb(0, iobase + 3);
udelay(30);
lo_byte = inb(iobase + 2);
hi_byte = inb(iobase + 3) & 0xf;
data[n] = lo_byte + (hi_byte << 8);
}
return n;
}
static int fl512_ao_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int n;
int chan = CR_CHAN(insn->chanspec);
unsigned long iobase = dev->iobase;
for (n = 0; n < insn->n; n++) {
outb(data[n] & 0x0ff, iobase + 4 + 2 * chan);
outb((data[n] & 0xf00) >> 8, iobase + 4 + 2 * chan);
inb(iobase + 4 + 2 * chan);
devpriv->ao_readback[chan] = data[n];
}
return n;
}
static int fl512_ao_insn_readback(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_readback[chan];
return n;
}
static int fl512_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
unsigned long iobase;
int ret;
struct comedi_subdevice *s;
iobase = it->options[0];
printk(KERN_INFO "comedi:%d fl512: 0x%04lx", dev->minor, iobase);
if (!request_region(iobase, FL512_SIZE, "fl512")) {
printk(KERN_WARNING " I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = "fl512";
if (alloc_private(dev, sizeof(struct fl512_private)) < 0)
return -ENOMEM;
#if DEBUG
printk(KERN_DEBUG "malloc ok\n");
#endif
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->range_table = &range_fl512;
s->insn_read = fl512_ai_insn;
printk(KERN_INFO "comedi: fl512: subdevice 0 initialized\n");
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &range_fl512;
s->insn_write = fl512_ao_insn;
s->insn_read = fl512_ao_insn_readback;
printk(KERN_INFO "comedi: fl512: subdevice 1 initialized\n");
return 1;
}
static void fl512_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, FL512_SIZE);
}
