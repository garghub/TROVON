static unsigned long *cpm_pdat(int port)
{
switch (port) {
case 0:
return &io->iop_pdata;
case 1:
return &io->iop_pdatb;
case 2:
return &io->iop_pdatc;
case 3:
return &io->iop_pdatd;
}
}
static int mpc8260cpm_dio_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
unsigned int d;
unsigned int mask;
int port;
port = (int)s->private;
mask = 1 << CR_CHAN(insn->chanspec);
if (mask & cpm_reserved_bits[port]) {
return -EINVAL;
}
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= mask;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~mask;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & mask) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
}
switch (port) {
case 0:
return &io->iop_pdira;
case 1:
return &io->iop_pdirb;
case 2:
return &io->iop_pdirc;
case 3:
return &io->iop_pdird;
}
return 1;
}
static int mpc8260cpm_dio_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int port;
unsigned long *p;
p = cpm_pdat((int)s->private);
return 2;
}
static int mpc8260cpm_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int i;
printk("comedi%d: mpc8260cpm: ", dev->minor);
dev->board_ptr = mpc8260cpm_boards + dev->board;
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct mpc8260cpm_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 4) < 0)
return -ENOMEM;
for (i = 0; i < 4; i++) {
s = dev->subdevices + i;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = mpc8260cpm_dio_config;
s->insn_bits = mpc8260cpm_dio_bits;
}
return 1;
}
static void mpc8260cpm_detach(struct comedi_device *dev)
{
}
