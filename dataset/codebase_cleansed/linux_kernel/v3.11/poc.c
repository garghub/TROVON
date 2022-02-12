static int readback_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct poc_private *devpriv = dev->private;
int chan;
chan = CR_CHAN(insn->chanspec);
data[0] = devpriv->ao_readback[chan];
return 1;
}
static int dac02_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct poc_private *devpriv = dev->private;
int temp;
int chan;
int output;
chan = CR_CHAN(insn->chanspec);
devpriv->ao_readback[chan] = data[0];
output = data[0];
#ifdef wrong
if ((CR_RANGE(insn->chanspec) & 0x2) == 0)
output = ~output;
#endif
temp = (output << 4) & 0xf0;
outb(temp, dev->iobase + DAC02_LSB(chan));
temp = (output >> 4) & 0xff;
outb(temp, dev->iobase + DAC02_MSB(chan));
return 1;
}
static int poc_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct boarddef_struct *board = comedi_board(dev);
struct poc_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], board->iosize);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
s = &dev->subdevices[0];
s->type = board->type;
s->n_chan = board->n_chan;
s->maxdata = (1 << board->n_bits) - 1;
s->range_table = board->range;
s->insn_write = board->winsn;
s->insn_read = board->rinsn;
s->insn_bits = board->insnbits;
if (s->type == COMEDI_SUBD_AO || s->type == COMEDI_SUBD_DO)
s->subdev_flags = SDF_WRITABLE;
return 0;
}
