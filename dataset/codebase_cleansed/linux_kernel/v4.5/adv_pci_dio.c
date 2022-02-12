static int pci_dio_insn_bits_di_b(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned long iobase = dev->iobase + reg;
data[1] = inb(iobase);
if (s->n_chan > 8)
data[1] |= (inb(iobase + 1) << 8);
if (s->n_chan > 16)
data[1] |= (inb(iobase + 2) << 16);
if (s->n_chan > 24)
data[1] |= (inb(iobase + 3) << 24);
return insn->n;
}
static int pci_dio_insn_bits_di_w(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned long iobase = dev->iobase + reg;
data[1] = inw(iobase);
if (s->n_chan > 16)
data[1] |= (inw(iobase + 2) << 16);
return insn->n;
}
static int pci_dio_insn_bits_do_b(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned long iobase = dev->iobase + reg;
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, iobase);
if (s->n_chan > 8)
outb((s->state >> 8) & 0xff, iobase + 1);
if (s->n_chan > 16)
outb((s->state >> 16) & 0xff, iobase + 2);
if (s->n_chan > 24)
outb((s->state >> 24) & 0xff, iobase + 3);
}
data[1] = s->state;
return insn->n;
}
static int pci_dio_insn_bits_do_w(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned long iobase = dev->iobase + reg;
if (comedi_dio_update_state(s, data)) {
outw(s->state & 0xffff, iobase);
if (s->n_chan > 16)
outw((s->state >> 16) & 0xffff, iobase + 2);
}
data[1] = s->state;
return insn->n;
}
static int pci_dio_reset(struct comedi_device *dev, unsigned long cardtype)
{
if (cardtype == TYPE_PCI1752 || cardtype == TYPE_PCI1756)
outw(0, dev->iobase + PCI1752_CFC_REG);
switch (cardtype) {
case TYPE_PCI1730:
case TYPE_PCI1733:
case TYPE_PCI1736:
outb(0, dev->iobase + PCI173X_INT_EN_REG);
outb(0x0f, dev->iobase + PCI173X_INT_CLR_REG);
outb(0, dev->iobase + PCI173X_INT_RF_REG);
break;
case TYPE_PCI1739:
case TYPE_PCI1750:
case TYPE_PCI1751:
outb(0x88, dev->iobase + PCI1750_INT_REG);
break;
case TYPE_PCI1753:
case TYPE_PCI1753E:
outb(0x88, dev->iobase + PCI1753_INT_REG(0));
outb(0x80, dev->iobase + PCI1753_INT_REG(1));
outb(0x80, dev->iobase + PCI1753_INT_REG(2));
outb(0x80, dev->iobase + PCI1753_INT_REG(3));
if (cardtype == TYPE_PCI1753E) {
outb(0x88, dev->iobase + PCI1753E_INT_REG(0));
outb(0x80, dev->iobase + PCI1753E_INT_REG(1));
outb(0x80, dev->iobase + PCI1753E_INT_REG(2));
outb(0x80, dev->iobase + PCI1753E_INT_REG(3));
}
break;
case TYPE_PCI1754:
case TYPE_PCI1756:
outw(0x08, dev->iobase + PCI1754_INT_REG(0));
outw(0x08, dev->iobase + PCI1754_INT_REG(1));
if (cardtype == TYPE_PCI1754) {
outw(0x08, dev->iobase + PCI1754_INT_REG(2));
outw(0x08, dev->iobase + PCI1754_INT_REG(3));
}
break;
case TYPE_PCI1762:
outw(0x0101, dev->iobase + PCI1762_INT_REG);
break;
default:
break;
}
return 0;
}
static int pci_dio_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct dio_boardtype *board = NULL;
const struct diosubd_data *d;
struct comedi_subdevice *s;
int ret, subdev, i, j;
if (context < ARRAY_SIZE(boardtypes))
board = &boardtypes[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
if (context == TYPE_PCI1736)
dev->iobase = pci_resource_start(pcidev, 0);
else
dev->iobase = pci_resource_start(pcidev, 2);
pci_dio_reset(dev, context);
ret = comedi_alloc_subdevices(dev, board->nsubdevs);
if (ret)
return ret;
subdev = 0;
for (i = 0; i < PCI_DIO_MAX_DI_SUBDEVS; i++) {
d = &board->sdi[i];
if (d->chans) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = d->chans;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = board->is_16bit
? pci_dio_insn_bits_di_w
: pci_dio_insn_bits_di_b;
s->private = (void *)d->addr;
}
}
for (i = 0; i < PCI_DIO_MAX_DO_SUBDEVS; i++) {
d = &board->sdo[i];
if (d->chans) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = d->chans;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = board->is_16bit
? pci_dio_insn_bits_do_w
: pci_dio_insn_bits_do_b;
s->private = (void *)d->addr;
if (board->is_16bit) {
outw(0, dev->iobase + d->addr);
if (s->n_chan > 16)
outw(0, dev->iobase + d->addr + 2);
} else {
outb(0, dev->iobase + d->addr);
if (s->n_chan > 8)
outb(0, dev->iobase + d->addr + 1);
if (s->n_chan > 16)
outb(0, dev->iobase + d->addr + 2);
if (s->n_chan > 24)
outb(0, dev->iobase + d->addr + 3);
}
}
}
for (i = 0; i < PCI_DIO_MAX_DIO_SUBDEVG; i++) {
d = &board->sdio[i];
for (j = 0; j < d->chans; j++) {
s = &dev->subdevices[subdev++];
ret = subdev_8255_init(dev, s, NULL,
d->addr + j * I8255_SIZE);
if (ret)
return ret;
}
}
if (board->id_reg) {
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = board->is_16bit ? pci_dio_insn_bits_di_w
: pci_dio_insn_bits_di_b;
s->private = (void *)board->id_reg;
}
if (board->timer_regbase) {
s = &dev->subdevices[subdev++];
dev->pacer = comedi_8254_init(dev->iobase +
board->timer_regbase,
0, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
comedi_8254_subdevice_init(s, dev->pacer);
}
return 0;
}
static unsigned long pci_dio_override_cardtype(struct pci_dev *pcidev,
unsigned long cardtype)
{
if (cardtype != TYPE_PCI1753)
return cardtype;
if (pci_enable_device(pcidev) < 0)
return cardtype;
if (pci_request_region(pcidev, 2, "adv_pci_dio") == 0) {
unsigned long reg = pci_resource_start(pcidev, 2) + 53;
outb(0x05, reg);
if ((inb(reg) & 0x07) == 0x02) {
outb(0x02, reg);
if ((inb(reg) & 0x07) == 0x05)
cardtype = TYPE_PCI1753E;
}
pci_release_region(pcidev, 2);
}
pci_disable_device(pcidev);
return cardtype;
}
static int adv_pci_dio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned long cardtype;
cardtype = pci_dio_override_cardtype(dev, id->driver_data);
return comedi_pci_auto_config(dev, &adv_pci_dio_driver, cardtype);
}
