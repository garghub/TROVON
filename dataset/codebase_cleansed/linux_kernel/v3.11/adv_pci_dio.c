static int pci_dio_insn_bits_di_b(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
int i;
data[1] = 0;
for (i = 0; i < d->regs; i++)
data[1] |= inb(dev->iobase + d->addr + i) << (8 * i);
return insn->n;
}
static int pci_dio_insn_bits_di_w(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
int i;
data[1] = 0;
for (i = 0; i < d->regs; i++)
data[1] |= inw(dev->iobase + d->addr + 2 * i) << (16 * i);
return insn->n;
}
static int pci_dio_insn_bits_do_b(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
int i;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
for (i = 0; i < d->regs; i++)
outb((s->state >> (8 * i)) & 0xff,
dev->iobase + d->addr + i);
}
data[1] = s->state;
return insn->n;
}
static int pci_dio_insn_bits_do_w(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
int i;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
for (i = 0; i < d->regs; i++)
outw((s->state >> (16 * i)) & 0xffff,
dev->iobase + d->addr + 2 * i);
}
data[1] = s->state;
return insn->n;
}
static int pci_8254_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
unsigned int chan, chip, chipchan;
unsigned long flags;
chan = CR_CHAN(insn->chanspec);
chip = chan / 3;
chipchan = chan - (3 * chip);
spin_lock_irqsave(&s->spin_lock, flags);
data[0] = i8254_read(dev->iobase + d->addr + (SIZE_8254 * chip),
0, chipchan);
spin_unlock_irqrestore(&s->spin_lock, flags);
return 1;
}
static int pci_8254_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
unsigned int chan, chip, chipchan;
unsigned long flags;
chan = CR_CHAN(insn->chanspec);
chip = chan / 3;
chipchan = chan - (3 * chip);
spin_lock_irqsave(&s->spin_lock, flags);
i8254_write(dev->iobase + d->addr + (SIZE_8254 * chip),
0, chipchan, data[0]);
spin_unlock_irqrestore(&s->spin_lock, flags);
return 1;
}
static int pci_8254_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
unsigned int chan, chip, chipchan;
unsigned long iobase;
int ret = 0;
unsigned long flags;
chan = CR_CHAN(insn->chanspec);
chip = chan / 3;
chipchan = chan - (3 * chip);
iobase = dev->iobase + d->addr + (SIZE_8254 * chip);
spin_lock_irqsave(&s->spin_lock, flags);
switch (data[0]) {
case INSN_CONFIG_SET_COUNTER_MODE:
ret = i8254_set_mode(iobase, 0, chipchan, data[1]);
if (ret < 0)
ret = -EINVAL;
break;
case INSN_CONFIG_8254_READ_STATUS:
data[1] = i8254_status(iobase, 0, chipchan);
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&s->spin_lock, flags);
return ret < 0 ? ret : insn->n;
}
static int pci1760_unchecked_mbxrequest(struct comedi_device *dev,
unsigned char *omb, unsigned char *imb,
int repeats)
{
int cnt, tout, ok = 0;
for (cnt = 0; cnt < repeats; cnt++) {
outb(omb[0], dev->iobase + OMB0);
outb(omb[1], dev->iobase + OMB1);
outb(omb[2], dev->iobase + OMB2);
outb(omb[3], dev->iobase + OMB3);
for (tout = 0; tout < 251; tout++) {
imb[2] = inb(dev->iobase + IMB2);
if (imb[2] == omb[2]) {
imb[0] = inb(dev->iobase + IMB0);
imb[1] = inb(dev->iobase + IMB1);
imb[3] = inb(dev->iobase + IMB3);
ok = 1;
break;
}
udelay(1);
}
if (ok)
return 0;
}
comedi_error(dev, "PCI-1760 mailbox request timeout!");
return -ETIME;
}
static int pci1760_clear_imb2(struct comedi_device *dev)
{
unsigned char omb[4] = { 0x0, 0x0, CMD_ClearIMB2, 0x0 };
unsigned char imb[4];
if (inb(dev->iobase + IMB2) == CMD_ClearIMB2)
return 0;
return pci1760_unchecked_mbxrequest(dev, omb, imb, OMBCMD_RETRY);
}
static int pci1760_mbxrequest(struct comedi_device *dev,
unsigned char *omb, unsigned char *imb)
{
if (omb[2] == CMD_ClearIMB2) {
comedi_error(dev,
"bug! this function should not be used for CMD_ClearIMB2 command");
return -EINVAL;
}
if (inb(dev->iobase + IMB2) == omb[2]) {
int retval;
retval = pci1760_clear_imb2(dev);
if (retval < 0)
return retval;
}
return pci1760_unchecked_mbxrequest(dev, omb, imb, OMBCMD_RETRY);
}
static int pci1760_insn_bits_di(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + IMB3);
return insn->n;
}
static int pci1760_insn_bits_do(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int ret;
unsigned char omb[4] = {
0x00,
0x00,
CMD_SetRelaysOutput,
0x00
};
unsigned char imb[4];
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
omb[0] = s->state;
ret = pci1760_mbxrequest(dev, omb, imb);
if (!ret)
return ret;
}
data[1] = s->state;
return insn->n;
}
static int pci1760_insn_cnt_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int ret, n;
unsigned char omb[4] = {
CR_CHAN(insn->chanspec) & 0x07,
0x00,
CMD_GetIDICntCurValue,
0x00
};
unsigned char imb[4];
for (n = 0; n < insn->n; n++) {
ret = pci1760_mbxrequest(dev, omb, imb);
if (!ret)
return ret;
data[n] = (imb[1] << 8) + imb[0];
}
return n;
}
static int pci1760_insn_cnt_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci_dio_private *devpriv = dev->private;
int ret;
unsigned char chan = CR_CHAN(insn->chanspec) & 0x07;
unsigned char bitmask = 1 << chan;
unsigned char omb[4] = {
data[0] & 0xff,
(data[0] >> 8) & 0xff,
CMD_SetIDI0CntResetValue + chan,
0x00
};
unsigned char imb[4];
if (devpriv->CntResValue[chan] != (data[0] & 0xffff)) {
ret = pci1760_mbxrequest(dev, omb, imb);
if (!ret)
return ret;
devpriv->CntResValue[chan] = data[0] & 0xffff;
}
omb[0] = bitmask;
omb[2] = CMD_ResetIDICounters;
ret = pci1760_mbxrequest(dev, omb, imb);
if (!ret)
return ret;
if (!(bitmask & devpriv->IDICntEnable)) {
omb[0] = bitmask;
omb[2] = CMD_EnableIDICounters;
ret = pci1760_mbxrequest(dev, omb, imb);
if (!ret)
return ret;
devpriv->IDICntEnable |= bitmask;
}
return 1;
}
static int pci1760_reset(struct comedi_device *dev)
{
struct pci_dio_private *devpriv = dev->private;
int i;
unsigned char omb[4] = { 0x00, 0x00, 0x00, 0x00 };
unsigned char imb[4];
outb(0, dev->iobase + INTCSR0);
outb(0, dev->iobase + INTCSR1);
outb(0, dev->iobase + INTCSR2);
outb(0, dev->iobase + INTCSR3);
devpriv->GlobalIrqEnabled = 0;
omb[0] = 0x00;
omb[2] = CMD_SetRelaysOutput;
pci1760_mbxrequest(dev, omb, imb);
omb[0] = 0x00;
omb[2] = CMD_EnableIDICounters;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDICntEnable = 0;
omb[0] = 0x00;
omb[2] = CMD_OverflowIDICounters;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDICntOverEnable = 0;
omb[0] = 0x00;
omb[2] = CMD_MatchIntIDICounters;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDICntMatchEnable = 0;
omb[0] = 0x00;
omb[1] = 0x80;
for (i = 0; i < 8; i++) {
omb[2] = CMD_SetIDI0CntMatchValue + i;
pci1760_mbxrequest(dev, omb, imb);
devpriv->CntMatchValue[i] = 0x8000;
}
omb[0] = 0x00;
omb[1] = 0x00;
for (i = 0; i < 8; i++) {
omb[2] = CMD_SetIDI0CntResetValue + i;
pci1760_mbxrequest(dev, omb, imb);
devpriv->CntResValue[i] = 0x0000;
}
omb[0] = 0xff;
omb[2] = CMD_ResetIDICounters;
pci1760_mbxrequest(dev, omb, imb);
omb[0] = 0x00;
omb[2] = CMD_EdgeIDICounters;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDICntEdge = 0x00;
omb[0] = 0x00;
omb[2] = CMD_EnableIDIFilters;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDIFiltersEn = 0x00;
omb[0] = 0x00;
omb[2] = CMD_EnableIDIPatternMatch;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDIPatMatchEn = 0x00;
omb[0] = 0x00;
omb[2] = CMD_SetIDIPatternMatch;
pci1760_mbxrequest(dev, omb, imb);
devpriv->IDIPatMatchValue = 0x00;
return 0;
}
static int pci_dio_reset(struct comedi_device *dev)
{
const struct dio_boardtype *this_board = comedi_board(dev);
switch (this_board->cardtype) {
case TYPE_PCI1730:
outb(0, dev->iobase + PCI1730_DO);
outb(0, dev->iobase + PCI1730_DO + 1);
outb(0, dev->iobase + PCI1730_IDO);
outb(0, dev->iobase + PCI1730_IDO + 1);
case TYPE_PCI1733:
outb(0, dev->iobase + PCI1730_3_INT_EN);
outb(0x0f, dev->iobase + PCI1730_3_INT_CLR);
outb(0, dev->iobase + PCI1730_3_INT_RF);
break;
case TYPE_PCI1734:
outb(0, dev->iobase + PCI1734_IDO);
outb(0, dev->iobase + PCI1734_IDO + 1);
outb(0, dev->iobase + PCI1734_IDO + 2);
outb(0, dev->iobase + PCI1734_IDO + 3);
break;
case TYPE_PCI1735:
outb(0, dev->iobase + PCI1735_DO);
outb(0, dev->iobase + PCI1735_DO + 1);
outb(0, dev->iobase + PCI1735_DO + 2);
outb(0, dev->iobase + PCI1735_DO + 3);
i8254_set_mode(dev->iobase + PCI1735_C8254, 0, 0, I8254_MODE0);
i8254_set_mode(dev->iobase + PCI1735_C8254, 0, 1, I8254_MODE0);
i8254_set_mode(dev->iobase + PCI1735_C8254, 0, 2, I8254_MODE0);
break;
case TYPE_PCI1736:
outb(0, dev->iobase + PCI1736_IDO);
outb(0, dev->iobase + PCI1736_IDO + 1);
outb(0, dev->iobase + PCI1736_3_INT_EN);
outb(0x0f, dev->iobase + PCI1736_3_INT_CLR);
outb(0, dev->iobase + PCI1736_3_INT_RF);
break;
case TYPE_PCI1739:
outb(0x88, dev->iobase + PCI1739_ICR);
break;
case TYPE_PCI1750:
case TYPE_PCI1751:
outb(0x88, dev->iobase + PCI1750_ICR);
break;
case TYPE_PCI1752:
outw(0, dev->iobase + PCI1752_6_CFC);
outw(0, dev->iobase + PCI1752_IDO);
outw(0, dev->iobase + PCI1752_IDO + 2);
outw(0, dev->iobase + PCI1752_IDO2);
outw(0, dev->iobase + PCI1752_IDO2 + 2);
break;
case TYPE_PCI1753E:
outb(0x88, dev->iobase + PCI1753E_ICR0);
outb(0x80, dev->iobase + PCI1753E_ICR1);
outb(0x80, dev->iobase + PCI1753E_ICR2);
outb(0x80, dev->iobase + PCI1753E_ICR3);
case TYPE_PCI1753:
outb(0x88, dev->iobase + PCI1753_ICR0);
outb(0x80, dev->iobase + PCI1753_ICR1);
outb(0x80, dev->iobase + PCI1753_ICR2);
outb(0x80, dev->iobase + PCI1753_ICR3);
break;
case TYPE_PCI1754:
outw(0x08, dev->iobase + PCI1754_6_ICR0);
outw(0x08, dev->iobase + PCI1754_6_ICR1);
outw(0x08, dev->iobase + PCI1754_ICR2);
outw(0x08, dev->iobase + PCI1754_ICR3);
break;
case TYPE_PCI1756:
outw(0, dev->iobase + PCI1752_6_CFC);
outw(0x08, dev->iobase + PCI1754_6_ICR0);
outw(0x08, dev->iobase + PCI1754_6_ICR1);
outw(0, dev->iobase + PCI1756_IDO);
outw(0, dev->iobase + PCI1756_IDO + 2);
break;
case TYPE_PCI1760:
pci1760_reset(dev);
break;
case TYPE_PCI1762:
outw(0x0101, dev->iobase + PCI1762_ICR);
break;
}
return 0;
}
static int pci1760_attach(struct comedi_device *dev)
{
struct comedi_subdevice *s;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s->insn_bits = pci1760_insn_bits_di;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s->state = 0;
s->insn_bits = pci1760_insn_bits_do;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITABLE | SDF_LSAMPL;
s->n_chan = 2;
s->maxdata = 0xffffffff;
s->len_chanlist = 2;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 0xffff;
s->len_chanlist = 8;
s->insn_read = pci1760_insn_cnt_read;
s->insn_write = pci1760_insn_cnt_write;
return 0;
}
static int pci_dio_add_di(struct comedi_device *dev,
struct comedi_subdevice *s,
const struct diosubd_data *d)
{
const struct dio_boardtype *this_board = comedi_board(dev);
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON | d->specflags;
if (d->chans > 16)
s->subdev_flags |= SDF_LSAMPL;
s->n_chan = d->chans;
s->maxdata = 1;
s->len_chanlist = d->chans;
s->range_table = &range_digital;
switch (this_board->io_access) {
case IO_8b:
s->insn_bits = pci_dio_insn_bits_di_b;
break;
case IO_16b:
s->insn_bits = pci_dio_insn_bits_di_w;
break;
}
s->private = (void *)d;
return 0;
}
static int pci_dio_add_do(struct comedi_device *dev,
struct comedi_subdevice *s,
const struct diosubd_data *d)
{
const struct dio_boardtype *this_board = comedi_board(dev);
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
if (d->chans > 16)
s->subdev_flags |= SDF_LSAMPL;
s->n_chan = d->chans;
s->maxdata = 1;
s->len_chanlist = d->chans;
s->range_table = &range_digital;
s->state = 0;
switch (this_board->io_access) {
case IO_8b:
s->insn_bits = pci_dio_insn_bits_do_b;
break;
case IO_16b:
s->insn_bits = pci_dio_insn_bits_do_w;
break;
}
s->private = (void *)d;
return 0;
}
static int pci_dio_add_8254(struct comedi_device *dev,
struct comedi_subdevice *s,
const struct diosubd_data *d)
{
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = d->chans;
s->maxdata = 65535;
s->len_chanlist = d->chans;
s->insn_read = pci_8254_insn_read;
s->insn_write = pci_8254_insn_write;
s->insn_config = pci_8254_insn_config;
s->private = (void *)d;
return 0;
}
static unsigned long pci_dio_override_cardtype(struct pci_dev *pcidev,
unsigned long cardtype)
{
if (cardtype != TYPE_PCI1753)
return cardtype;
if (pci_enable_device(pcidev) < 0)
return cardtype;
if (pci_request_region(pcidev, PCIDIO_MAINREG, "adv_pci_dio") == 0) {
unsigned long reg =
pci_resource_start(pcidev, PCIDIO_MAINREG) + 53;
outb(0x05, reg);
if ((inb(reg) & 0x07) == 0x02) {
outb(0x02, reg);
if ((inb(reg) & 0x07) == 0x05)
cardtype = TYPE_PCI1753E;
}
pci_release_region(pcidev, PCIDIO_MAINREG);
}
pci_disable_device(pcidev);
return cardtype;
}
static int pci_dio_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct dio_boardtype *this_board = NULL;
struct pci_dio_private *devpriv;
struct comedi_subdevice *s;
int ret, subdev, i, j;
if (context < ARRAY_SIZE(boardtypes))
this_board = &boardtypes[context];
if (!this_board)
return -ENODEV;
dev->board_ptr = this_board;
dev->board_name = this_board->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, this_board->main_pci_region);
ret = comedi_alloc_subdevices(dev, this_board->nsubdevs);
if (ret)
return ret;
subdev = 0;
for (i = 0; i < MAX_DI_SUBDEVS; i++)
if (this_board->sdi[i].chans) {
s = &dev->subdevices[subdev];
pci_dio_add_di(dev, s, &this_board->sdi[i]);
subdev++;
}
for (i = 0; i < MAX_DO_SUBDEVS; i++)
if (this_board->sdo[i].chans) {
s = &dev->subdevices[subdev];
pci_dio_add_do(dev, s, &this_board->sdo[i]);
subdev++;
}
for (i = 0; i < MAX_DIO_SUBDEVG; i++)
for (j = 0; j < this_board->sdio[i].regs; j++) {
s = &dev->subdevices[subdev];
subdev_8255_init(dev, s, NULL,
dev->iobase +
this_board->sdio[i].addr +
SIZE_8255 * j);
subdev++;
}
if (this_board->boardid.chans) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
pci_dio_add_di(dev, s, &this_board->boardid);
subdev++;
}
for (i = 0; i < MAX_8254_SUBDEVS; i++)
if (this_board->s8254[i].chans) {
s = &dev->subdevices[subdev];
pci_dio_add_8254(dev, s, &this_board->s8254[i]);
subdev++;
}
if (this_board->cardtype == TYPE_PCI1760)
pci1760_attach(dev);
devpriv->valid = 1;
pci_dio_reset(dev);
return 0;
}
static void pci_dio_detach(struct comedi_device *dev)
{
struct pci_dio_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->valid)
pci_dio_reset(dev);
}
comedi_pci_disable(dev);
}
static int adv_pci_dio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned long cardtype;
cardtype = pci_dio_override_cardtype(dev, id->driver_data);
return comedi_pci_auto_config(dev, &adv_pci_dio_driver, cardtype);
}
