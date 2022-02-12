static int dnp_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
outb(PADR, CSCIR);
outb((inb(CSCDR)
& ~(u8) (data[0] & 0x0000FF))
| (u8) (data[1] & 0x0000FF), CSCDR);
outb(PBDR, CSCIR);
outb((inb(CSCDR)
& ~(u8) ((data[0] & 0x00FF00) >> 8))
| (u8) ((data[1] & 0x00FF00) >> 8), CSCDR);
outb(PCDR, CSCIR);
outb((inb(CSCDR)
& ~(u8) ((data[0] & 0x0F0000) >> 12))
| (u8) ((data[1] & 0x0F0000) >> 12), CSCDR);
}
outb(PADR, CSCIR);
data[0] = inb(CSCDR);
outb(PBDR, CSCIR);
data[0] += inb(CSCDR) << 8;
outb(PCDR, CSCIR);
data[0] += ((inb(CSCDR) & 0xF0) << 12);
return insn->n;
}
static int dnp_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
unsigned int val;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
if (chan < 8) {
mask = 1 << chan;
outb(PAMR, CSCIR);
} else if (chan < 16) {
mask = 1 << (chan - 8);
outb(PBMR, CSCIR);
} else {
mask = 1 << ((chan - 16) * 2);
outb(PCMR, CSCIR);
}
val = inb(CSCDR);
if (data[0] == COMEDI_OUTPUT)
val |= mask;
else
val &= ~mask;
outb(val, CSCDR);
return insn->n;
}
static int dnp_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 20;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = dnp_dio_insn_bits;
s->insn_config = dnp_dio_insn_config;
outb(PAMR, CSCIR);
outb(0x00, CSCDR);
outb(PBMR, CSCIR);
outb(0x00, CSCDR);
outb(PCMR, CSCIR);
outb((inb(CSCDR) & 0xAA), CSCDR);
dev_info(dev->class_dev, "%s: attached\n", dev->board_name);
return 1;
}
static void dnp_detach(struct comedi_device *dev)
{
outb(PAMR, CSCIR);
outb(0x00, CSCDR);
outb(PBMR, CSCIR);
outb(0x00, CSCDR);
outb(PCMR, CSCIR);
outb((inb(CSCDR) & 0xAA), CSCDR);
}
