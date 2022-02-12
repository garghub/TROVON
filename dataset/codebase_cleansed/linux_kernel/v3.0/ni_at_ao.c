static int __init driver_atao_init_module(void)
{
return comedi_driver_register(&driver_atao);
}
static void __exit driver_atao_cleanup_module(void)
{
comedi_driver_unregister(&driver_atao);
}
static int atao_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
int ao_unipolar;
iobase = it->options[0];
if (iobase == 0)
iobase = 0x1c0;
ao_unipolar = it->options[3];
printk(KERN_INFO "comedi%d: ni_at_ao: 0x%04lx", dev->minor, iobase);
if (!request_region(iobase, ATAO_SIZE, "ni_at_ao")) {
printk(" I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct atao_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 4) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->n_ao_chans;
s->maxdata = (1 << 12) - 1;
if (ao_unipolar)
s->range_table = &range_unipolar10;
else
s->range_table = &range_bipolar10;
s->insn_write = &atao_ao_winsn;
s->insn_read = &atao_ao_rinsn;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = atao_dio_insn_bits;
s->insn_config = atao_dio_insn_config;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 21;
s->maxdata = 0xff;
s->insn_read = atao_calib_insn_read;
s->insn_write = atao_calib_insn_write;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_UNUSED;
atao_reset(dev);
printk(KERN_INFO "\n");
return 0;
}
static int atao_detach(struct comedi_device *dev)
{
printk(KERN_INFO "comedi%d: atao: remove\n", dev->minor);
if (dev->iobase)
release_region(dev->iobase, ATAO_SIZE);
return 0;
}
static void atao_reset(struct comedi_device *dev)
{
devpriv->cfg1 = 0;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1);
outb(RWSEL0 | MODESEL2, dev->iobase + ATAO_82C53_CNTRCMD);
outb(0x03, dev->iobase + ATAO_82C53_CNTR1);
outb(CNTRSEL0 | RWSEL0 | MODESEL2, dev->iobase + ATAO_82C53_CNTRCMD);
devpriv->cfg2 = 0;
outw(devpriv->cfg2, dev->iobase + ATAO_CFG2);
devpriv->cfg3 = 0;
outw(devpriv->cfg3, dev->iobase + ATAO_CFG3);
inw(dev->iobase + ATAO_FIFO_CLEAR);
devpriv->cfg1 |= GRP2WR;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1);
outw(0, dev->iobase + ATAO_2_INT1CLR);
outw(0, dev->iobase + ATAO_2_INT2CLR);
outw(0, dev->iobase + ATAO_2_DMATCCLR);
devpriv->cfg1 &= ~GRP2WR;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1);
}
static int atao_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
short bits;
for (i = 0; i < insn->n; i++) {
bits = data[i] - 0x800;
if (chan == 0) {
devpriv->cfg1 |= GRP2WR;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1);
}
outw(bits, dev->iobase + ATAO_DACn(chan));
if (chan == 0) {
devpriv->cfg1 &= ~GRP2WR;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1);
}
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int atao_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int atao_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outw(s->state, dev->iobase + ATAO_DOUT);
}
data[1] = inw(dev->iobase + ATAO_DIN);
return 2;
}
static int atao_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
unsigned int mask, bit;
mask = (chan < 4) ? 0x0f : 0xf0;
bit = (chan < 4) ? DOUTEN1 : DOUTEN2;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= mask;
devpriv->cfg3 |= bit;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~mask;
devpriv->cfg3 &= ~bit;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
outw(devpriv->cfg3, dev->iobase + ATAO_CFG3);
return 1;
}
static int atao_calib_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = 0;
return insn->n;
}
static int atao_calib_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int bitstring, bit;
unsigned int chan = CR_CHAN(insn->chanspec);
bitstring = ((chan & 0x7) << 8) | (data[insn->n - 1] & 0xff);
for (bit = 1 << (11 - 1); bit; bit >>= 1) {
outw(devpriv->cfg2 | ((bit & bitstring) ? SDATA : 0),
dev->iobase + ATAO_CFG2);
outw(devpriv->cfg2 | SCLK | ((bit & bitstring) ? SDATA : 0),
dev->iobase + ATAO_CFG2);
}
outw(devpriv->cfg2 | (((chan >> 3) + 1) << 14),
dev->iobase + ATAO_CFG2);
outw(devpriv->cfg2, dev->iobase + ATAO_CFG2);
return insn->n;
}
