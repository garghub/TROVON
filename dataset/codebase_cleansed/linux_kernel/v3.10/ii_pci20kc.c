static int pci20xxx_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci20xxx_private *devpriv;
unsigned char i;
int ret;
int id;
struct comedi_subdevice *s;
union pci20xxx_subdev_private *sdp;
ret = comedi_alloc_subdevices(dev, 1 + PCI20000_MODULES);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
devpriv->ioaddr = (void __iomem *)(unsigned long)it->options[0];
if ((readb(devpriv->ioaddr) & PCI20000_ID) != PCI20000_ID) {
dev_warn(dev->class_dev,
"PCI-20001 C-2A Carrier Board at base=0x%p not found !\n",
devpriv->ioaddr);
return -EINVAL;
}
dev_info(dev->class_dev, "PCI-20001 C-2A at base=0x%p\n",
devpriv->ioaddr);
for (i = 0; i < PCI20000_MODULES; i++) {
s = &dev->subdevices[i];
id = readb(devpriv->ioaddr + (i + 1) * PCI20000_OFFSET);
s->private = devpriv->subdev_private + i;
sdp = s->private;
switch (id) {
case PCI20006_ID:
sdp->pci20006.iobase =
devpriv->ioaddr + (i + 1) * PCI20000_OFFSET;
pci20006_init(dev, s, it->options[2 * i + 2],
it->options[2 * i + 3]);
dev_info(dev->class_dev,
"PCI-20006 module in slot %d\n", i + 1);
break;
case PCI20341_ID:
sdp->pci20341.iobase =
devpriv->ioaddr + (i + 1) * PCI20000_OFFSET;
pci20341_init(dev, s, it->options[2 * i + 2],
it->options[2 * i + 3]);
dev_info(dev->class_dev,
"PCI-20341 module in slot %d\n", i + 1);
break;
default:
dev_warn(dev->class_dev,
"unknown module code 0x%02x in slot %d: module disabled\n",
id, i);
case PCI20xxx_EMPTY_ID:
s->type = COMEDI_SUBD_UNUSED;
break;
}
}
pci20xxx_dio_init(dev, &dev->subdevices[PCI20000_MODULES]);
return 1;
}
static void pci20xxx_detach(struct comedi_device *dev)
{
}
static int pci20006_init(struct comedi_device *dev, struct comedi_subdevice *s,
int opt0, int opt1)
{
union pci20xxx_subdev_private *sdp = s->private;
if (opt0 < 0 || opt0 > 2)
opt0 = 0;
if (opt1 < 0 || opt1 > 2)
opt1 = 0;
sdp->pci20006.ao_range_list[0] = pci20006_range_list[opt0];
sdp->pci20006.ao_range_list[1] = pci20006_range_list[opt1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->len_chanlist = 2;
s->insn_read = pci20006_insn_read;
s->insn_write = pci20006_insn_write;
s->maxdata = 0xffff;
s->range_table_list = sdp->pci20006.ao_range_list;
return 0;
}
static int pci20006_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
union pci20xxx_subdev_private *sdp = s->private;
data[0] = sdp->pci20006.last_data[CR_CHAN(insn->chanspec)];
return 1;
}
static int pci20006_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
union pci20xxx_subdev_private *sdp = s->private;
int hi, lo;
unsigned int boarddata;
sdp->pci20006.last_data[CR_CHAN(insn->chanspec)] = data[0];
boarddata = (((unsigned int)data[0] + 0x8000) & 0xffff);
lo = (boarddata & 0xff);
hi = ((boarddata >> 8) & 0xff);
switch (CR_CHAN(insn->chanspec)) {
case 0:
writeb(lo, sdp->iobase + PCI20006_LCHAN0);
writeb(hi, sdp->iobase + PCI20006_LCHAN0 + 1);
writeb(0x00, sdp->iobase + PCI20006_STROBE0);
break;
case 1:
writeb(lo, sdp->iobase + PCI20006_LCHAN1);
writeb(hi, sdp->iobase + PCI20006_LCHAN1 + 1);
writeb(0x00, sdp->iobase + PCI20006_STROBE1);
break;
default:
dev_warn(dev->class_dev, "ao channel Error!\n");
return -EINVAL;
}
return 1;
}
static int pci20341_init(struct comedi_device *dev, struct comedi_subdevice *s,
int opt0, int opt1)
{
union pci20xxx_subdev_private *sdp = s->private;
int option;
if (opt0 < 0 || opt0 > 3)
opt0 = 0;
sdp->pci20341.timebase = pci20341_timebase[opt0];
sdp->pci20341.settling_time = pci20341_settling_time[opt0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
s->n_chan = PCI20341_CHAN_NR;
s->len_chanlist = PCI20341_SCANLIST;
s->insn_read = pci20341_insn_read;
s->maxdata = 0xffff;
s->range_table = pci20341_ranges[opt0];
option = sdp->pci20341.timebase | PCI20341_REPMODE;
writeb(PCI20341_INIT, sdp->iobase + PCI20341_CONFIG_REG);
writeb(PCI20341_PACER, sdp->iobase + PCI20341_MOD_STATUS);
writeb(option, sdp->iobase + PCI20341_OPT_REG);
writeb(sdp->pci20341.settling_time,
sdp->iobase + PCI20341_SET_TIME_REG);
return 0;
}
static int pci20341_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
union pci20xxx_subdev_private *sdp = s->private;
unsigned int i = 0, j = 0;
int lo, hi;
unsigned char eoc;
unsigned int clb;
unsigned int boarddata;
writeb(1, sdp->iobase + PCI20341_LCHAN_ADDR_REG);
clb = PCI20341_DAISY_CHAIN | PCI20341_MUX | (sdp->pci20341.ai_gain << 3)
| CR_CHAN(insn->chanspec);
writeb(clb, sdp->iobase + PCI20341_CHAN_LIST);
writeb(0x00, sdp->iobase + PCI20341_CC_RESET);
writeb(0x00, sdp->iobase + PCI20341_CHAN_RESET);
for (i = 0; i < insn->n; i++) {
j = 0;
readb(sdp->iobase + PCI20341_SOFT_PACER);
eoc = readb(sdp->iobase + PCI20341_STATUS_REG);
while ((eoc < 0x80) && j < 100) {
j++;
eoc = readb(sdp->iobase + PCI20341_STATUS_REG);
}
if (j >= 100) {
dev_warn(dev->class_dev,
"AI interrupt channel %i polling exit !\n", i);
return -EINVAL;
}
lo = readb(sdp->iobase + PCI20341_LDATA);
hi = readb(sdp->iobase + PCI20341_LDATA + 1);
boarddata = lo + 0x100 * hi;
data[i] = (short)((boarddata + 0x8000) & 0xffff);
}
return i;
}
static int pci20xxx_dio_init(struct comedi_device *dev,
struct comedi_subdevice *s)
{
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 32;
s->insn_bits = pci20xxx_dio_insn_bits;
s->insn_config = pci20xxx_dio_insn_config;
s->maxdata = 1;
s->len_chanlist = 32;
s->range_table = &range_digital;
s->io_bits = 0;
pci20xxx_dio_config(dev, s);
return 0;
}
static int pci20xxx_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int mask, bits;
mask = 1 << CR_CHAN(insn->chanspec);
if (mask & 0x000000ff)
bits = 0x000000ff;
else if (mask & 0x0000ff00)
bits = 0x0000ff00;
else if (mask & 0x00ff0000)
bits = 0x00ff0000;
else
bits = 0xff000000;
if (data[0])
s->io_bits |= bits;
else
s->io_bits &= ~bits;
pci20xxx_dio_config(dev, s);
return 1;
}
static int pci20xxx_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci20xxx_private *devpriv = dev->private;
unsigned int mask = data[0];
s->state &= ~mask;
s->state |= (mask & data[1]);
mask &= s->io_bits;
if (mask & 0x000000ff)
writeb((s->state >> 0) & 0xff,
devpriv->ioaddr + PCI20000_DIO_0);
if (mask & 0x0000ff00)
writeb((s->state >> 8) & 0xff,
devpriv->ioaddr + PCI20000_DIO_1);
if (mask & 0x00ff0000)
writeb((s->state >> 16) & 0xff,
devpriv->ioaddr + PCI20000_DIO_2);
if (mask & 0xff000000)
writeb((s->state >> 24) & 0xff,
devpriv->ioaddr + PCI20000_DIO_3);
data[1] = readb(devpriv->ioaddr + PCI20000_DIO_0);
data[1] |= readb(devpriv->ioaddr + PCI20000_DIO_1) << 8;
data[1] |= readb(devpriv->ioaddr + PCI20000_DIO_2) << 16;
data[1] |= readb(devpriv->ioaddr + PCI20000_DIO_3) << 24;
return insn->n;
}
static void pci20xxx_dio_config(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pci20xxx_private *devpriv = dev->private;
unsigned char control_01;
unsigned char control_23;
unsigned char buffer;
control_01 = readb(devpriv->ioaddr + PCI20000_DIO_CONTROL_01);
control_23 = readb(devpriv->ioaddr + PCI20000_DIO_CONTROL_23);
buffer = readb(devpriv->ioaddr + PCI20000_DIO_BUFFER);
if (s->io_bits & 0x000000ff) {
control_01 &= PCI20000_DIO_EOC;
buffer = (buffer & (~(DIO_BE << DIO_PS_0))) | (DIO_BO <<
DIO_PS_0);
} else {
control_01 = (control_01 & DIO_CAND) | PCI20000_DIO_EIC;
buffer = (buffer & (~(DIO_BI << DIO_PS_0)));
}
if (s->io_bits & 0x0000ff00) {
control_01 &= PCI20000_DIO_OOC;
buffer = (buffer & (~(DIO_BE << DIO_PS_1))) | (DIO_BO <<
DIO_PS_1);
} else {
control_01 = (control_01 & DIO_CAND) | PCI20000_DIO_OIC;
buffer = (buffer & (~(DIO_BI << DIO_PS_1)));
}
if (s->io_bits & 0x00ff0000) {
control_23 &= PCI20000_DIO_EOC;
buffer = (buffer & (~(DIO_BE << DIO_PS_2))) | (DIO_BO <<
DIO_PS_2);
} else {
control_23 = (control_23 & DIO_CAND) | PCI20000_DIO_EIC;
buffer = (buffer & (~(DIO_BI << DIO_PS_2)));
}
if (s->io_bits & 0xff000000) {
control_23 &= PCI20000_DIO_OOC;
buffer = (buffer & (~(DIO_BE << DIO_PS_3))) | (DIO_BO <<
DIO_PS_3);
} else {
control_23 = (control_23 & DIO_CAND) | PCI20000_DIO_OIC;
buffer = (buffer & (~(DIO_BI << DIO_PS_3)));
}
writeb(control_01, devpriv->ioaddr + PCI20000_DIO_CONTROL_01);
writeb(control_23, devpriv->ioaddr + PCI20000_DIO_CONTROL_23);
writeb(buffer, devpriv->ioaddr + PCI20000_DIO_BUFFER);
}
