static int pci_dio_insn_bits_di_b(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct diosubd_data *d = (const struct diosubd_data *)s->private;
int i;
data[1] = 0;
for (i = 0; i < d->regs; i++)
data[1] |= inb(dev->iobase + d->addr + i) << (8 * i);
return 2;
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
return 2;
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
return 2;
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
return 2;
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
return 2;
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
return 2;
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
DPRINTK("adv_pci_dio EDBG: BGN: pci171x_reset(...)\n");
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
DPRINTK("adv_pci_dio EDBG: END: pci171x_reset(...)\n");
return 0;
}
static int pci1760_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int subdev = 0;
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s->insn_bits = pci1760_insn_bits_di;
subdev++;
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s->state = 0;
s->insn_bits = pci1760_insn_bits_do;
subdev++;
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITABLE | SDF_LSAMPL;
s->n_chan = 2;
s->maxdata = 0xffffffff;
s->len_chanlist = 2;
subdev++;
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 0xffff;
s->len_chanlist = 8;
s->insn_read = pci1760_insn_cnt_read;
s->insn_write = pci1760_insn_cnt_write;
subdev++;
return 0;
}
static int pci_dio_add_di(struct comedi_device *dev, struct comedi_subdevice *s,
const struct diosubd_data *d, int subdev)
{
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
static int pci_dio_add_do(struct comedi_device *dev, struct comedi_subdevice *s,
const struct diosubd_data *d, int subdev)
{
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
const struct diosubd_data *d, int subdev)
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
static int CheckAndAllocCard(struct comedi_device *dev,
struct comedi_devconfig *it,
struct pci_dev *pcidev)
{
struct pci_dio_private *pr, *prev;
for (pr = pci_priv, prev = NULL; pr != NULL; prev = pr, pr = pr->next) {
if (pr->pcidev == pcidev)
return 0;
}
if (prev) {
devpriv->prev = prev;
prev->next = devpriv;
} else {
pci_priv = devpriv;
}
devpriv->pcidev = pcidev;
return 1;
}
static int pci_dio_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret, subdev, n_subdevices, i, j;
unsigned long iobase;
struct pci_dev *pcidev = NULL;
ret = alloc_private(dev, sizeof(struct pci_dio_private));
if (ret < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
for (i = 0; i < n_boardtypes; ++i) {
if (boardtypes[i].vendor_id != pcidev->vendor)
continue;
if (boardtypes[i].device_id != pcidev->device)
continue;
if (it->options[0] || it->options[1]) {
if (pcidev->bus->number != it->options[0] ||
PCI_SLOT(pcidev->devfn) != it->options[1]) {
continue;
}
}
ret = CheckAndAllocCard(dev, it, pcidev);
if (ret != 1)
continue;
dev->board_ptr = boardtypes + i;
break;
}
if (dev->board_ptr)
break;
}
if (!dev->board_ptr) {
dev_err(dev->hw_dev, "Error: Requested type of the card was not found!\n");
return -EIO;
}
if (comedi_pci_enable(pcidev, driver_pci_dio.driver_name)) {
dev_err(dev->hw_dev, "Error: Can't enable PCI device and request regions!\n");
return -EIO;
}
iobase = pci_resource_start(pcidev, this_board->main_pci_region);
dev_dbg(dev->hw_dev, "b:s:f=%d:%d:%d, io=0x%4lx\n",
pcidev->bus->number, PCI_SLOT(pcidev->devfn),
PCI_FUNC(pcidev->devfn), iobase);
dev->iobase = iobase;
dev->board_name = this_board->name;
if (this_board->cardtype == TYPE_PCI1760) {
n_subdevices = 4;
} else {
n_subdevices = 0;
for (i = 0; i < MAX_DI_SUBDEVS; i++)
if (this_board->sdi[i].chans)
n_subdevices++;
for (i = 0; i < MAX_DO_SUBDEVS; i++)
if (this_board->sdo[i].chans)
n_subdevices++;
for (i = 0; i < MAX_DIO_SUBDEVG; i++)
n_subdevices += this_board->sdio[i].regs;
if (this_board->boardid.chans)
n_subdevices++;
for (i = 0; i < MAX_8254_SUBDEVS; i++)
if (this_board->s8254[i].chans)
n_subdevices++;
}
ret = alloc_subdevices(dev, n_subdevices);
if (ret < 0)
return ret;
subdev = 0;
for (i = 0; i < MAX_DI_SUBDEVS; i++)
if (this_board->sdi[i].chans) {
s = dev->subdevices + subdev;
pci_dio_add_di(dev, s, &this_board->sdi[i], subdev);
subdev++;
}
for (i = 0; i < MAX_DO_SUBDEVS; i++)
if (this_board->sdo[i].chans) {
s = dev->subdevices + subdev;
pci_dio_add_do(dev, s, &this_board->sdo[i], subdev);
subdev++;
}
for (i = 0; i < MAX_DIO_SUBDEVG; i++)
for (j = 0; j < this_board->sdio[i].regs; j++) {
s = dev->subdevices + subdev;
subdev_8255_init(dev, s, NULL,
dev->iobase +
this_board->sdio[i].addr +
SIZE_8255 * j);
subdev++;
}
if (this_board->boardid.chans) {
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_DI;
pci_dio_add_di(dev, s, &this_board->boardid, subdev);
subdev++;
}
for (i = 0; i < MAX_8254_SUBDEVS; i++)
if (this_board->s8254[i].chans) {
s = dev->subdevices + subdev;
pci_dio_add_8254(dev, s, &this_board->s8254[i], subdev);
subdev++;
}
if (this_board->cardtype == TYPE_PCI1760)
pci1760_attach(dev, it);
devpriv->valid = 1;
pci_dio_reset(dev);
return 0;
}
static int pci_dio_detach(struct comedi_device *dev)
{
int i, j;
struct comedi_subdevice *s;
int subdev;
if (dev->private) {
if (devpriv->valid)
pci_dio_reset(dev);
subdev = 0;
for (i = 0; i < MAX_DI_SUBDEVS; i++) {
if (this_board->sdi[i].chans)
subdev++;
}
for (i = 0; i < MAX_DO_SUBDEVS; i++) {
if (this_board->sdo[i].chans)
subdev++;
}
for (i = 0; i < MAX_DIO_SUBDEVG; i++) {
for (j = 0; j < this_board->sdio[i].regs; j++) {
s = dev->subdevices + subdev;
subdev_8255_cleanup(dev, s);
subdev++;
}
}
if (this_board->boardid.chans)
subdev++;
for (i = 0; i < MAX_8254_SUBDEVS; i++)
if (this_board->s8254[i].chans)
subdev++;
for (i = 0; i < dev->n_subdevices; i++) {
s = dev->subdevices + i;
s->private = NULL;
}
if (devpriv->pcidev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pcidev);
pci_dev_put(devpriv->pcidev);
}
if (devpriv->prev)
devpriv->prev->next = devpriv->next;
else
pci_priv = devpriv->next;
if (devpriv->next)
devpriv->next->prev = devpriv->prev;
}
return 0;
}
static int __devinit driver_pci_dio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, driver_pci_dio.driver_name);
}
static void __devexit driver_pci_dio_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_pci_dio_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_pci_dio);
if (retval < 0)
return retval;
driver_pci_dio_pci_driver.name = (char *)driver_pci_dio.driver_name;
return pci_register_driver(&driver_pci_dio_pci_driver);
}
static void __exit driver_pci_dio_cleanup_module(void)
{
pci_unregister_driver(&driver_pci_dio_pci_driver);
comedi_driver_unregister(&driver_pci_dio);
}
