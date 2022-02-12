static int apci16xx_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan_mask = 1 << CR_CHAN(insn->chanspec);
unsigned int bits;
if (chan_mask & 0x000000ff)
bits = 0x000000ff;
else if (chan_mask & 0x0000ff00)
bits = 0x0000ff00;
else if (chan_mask & 0x00ff0000)
bits = 0x00ff0000;
else
bits = 0xff000000;
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~bits;
break;
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= bits;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & bits) ? COMEDI_INPUT : COMEDI_OUTPUT;
return insn->n;
default:
return -EINVAL;
}
outl(s->io_bits, dev->iobase + APCI16XX_DIR_REG(s->index));
return insn->n;
}
static int apci16xx_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = data[0];
unsigned int bits = data[1];
mask &= s->io_bits;
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outl(s->state, dev->iobase + APCI16XX_OUT_REG(s->index));
}
data[1] = inl(dev->iobase + APCI16XX_IN_REG(s->index));
return insn->n;
}
static const void *apci16xx_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct apci16xx_boardinfo *board;
int i;
for (i = 0; i < ARRAY_SIZE(apci16xx_boardtypes); i++) {
board = &apci16xx_boardtypes[i];
if (board->vendor == pcidev->vendor &&
board->device == pcidev->device)
return board;
}
return NULL;
}
static int apci16xx_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct apci16xx_boardinfo *board;
struct comedi_subdevice *s;
unsigned int n_subdevs;
unsigned int last;
int i;
int ret;
board = apci16xx_find_boardinfo(dev, pcidev);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 0);
n_subdevs = board->n_chan / 32;
if ((n_subdevs * 32) < board->n_chan) {
last = board->n_chan - (n_subdevs * 32);
n_subdevs++;
} else {
last = 0;
}
ret = comedi_alloc_subdevices(dev, n_subdevs);
if (ret)
return ret;
for (i = 0; i < n_subdevs; i++) {
s = &dev->subdevices[i];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITEABLE | SDF_READABLE;
s->n_chan = ((i * 32) < board->n_chan) ? 32 : last;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = apci16xx_insn_config;
s->insn_bits = apci16xx_dio_insn_bits;
s->io_bits = 0;
outl(s->io_bits, dev->iobase + APCI16XX_DIR_REG(i));
}
return 0;
}
static void apci16xx_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int apci16xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci16xx_driver);
}
