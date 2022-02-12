static int pci1723_reset(struct comedi_device *dev)
{
int i;
DPRINTK("adv_pci1723 EDBG: BGN: pci1723_reset(...)\n");
outw(0x01, dev->iobase + PCI1723_SYN_SET);
for (i = 0; i < 8; i++) {
devpriv->ao_data[i] = 0x8000;
outw(devpriv->ao_data[i], dev->iobase + PCI1723_DA(i));
devpriv->da_range[i] = 0;
outw(((devpriv->da_range[i] << 4) | i),
PCI1723_RANGE_CALIBRATION_MODE);
}
outw(0, dev->iobase + PCI1723_CHANGE_CHA_OUTPUT_TYPE_STROBE);
outw(0, dev->iobase + PCI1723_SYN_STROBE);
outw(0, dev->iobase + PCI1723_SYN_SET);
DPRINTK("adv_pci1723 EDBG: END: pci1723_reset(...)\n");
return 0;
}
static int pci1723_insn_read_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, chan;
chan = CR_CHAN(insn->chanspec);
DPRINTK(" adv_PCI1723 DEBUG: pci1723_insn_read_ao() -----\n");
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_data[chan];
return n;
}
static int pci1723_ao_write_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, chan;
chan = CR_CHAN(insn->chanspec);
DPRINTK("PCI1723: the pci1723_ao_write_winsn() ------\n");
for (n = 0; n < insn->n; n++) {
devpriv->ao_data[chan] = data[n];
outw(data[n], dev->iobase + PCI1723_DA(chan));
}
return n;
}
static int pci1723_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int mask;
unsigned int bits;
unsigned short dio_mode;
mask = 1 << CR_CHAN(insn->chanspec);
if (mask & 0x00FF)
bits = 0x00FF;
else
bits = 0xFF00;
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~bits;
break;
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= bits;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & bits) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
default:
return -EINVAL;
}
dio_mode = 0x0000;
if ((s->io_bits & 0x00FF) == 0)
dio_mode |= 0x0001;
if ((s->io_bits & 0xFF00) == 0)
dio_mode |= 0x0002;
outw(dio_mode, dev->iobase + PCI1723_DIGITAL_IO_PORT_SET);
return 1;
}
static int pci1723_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outw(s->state, dev->iobase + PCI1723_WRITE_DIGITAL_OUTPUT_CMD);
}
data[1] = inw(dev->iobase + PCI1723_READ_DIGITAL_INPUT_DATA);
return insn->n;
}
static struct pci_dev *pci1723_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pcidev) {
if (bus || slot) {
if (bus != pcidev->bus->number ||
slot != PCI_SLOT(pcidev->devfn))
continue;
}
if (pcidev->vendor != PCI_VENDOR_ID_ADVANTECH)
continue;
return pcidev;
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pci1723_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
struct comedi_subdevice *s;
int ret, subdev, n_subdevices;
printk(KERN_ERR "comedi%d: adv_pci1723: board=%s",
dev->minor, this_board->name);
ret = alloc_private(dev, sizeof(struct pci1723_private));
if (ret < 0) {
printk(" - Allocation failed!\n");
return -ENOMEM;
}
pcidev = pci1723_find_pci_dev(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
ret = comedi_pci_enable(pcidev, "adv_pci1723");
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
dev->board_name = this_board->name;
n_subdevices = 0;
if (this_board->n_aochan)
n_subdevices++;
if (this_board->n_diochan)
n_subdevices++;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
pci1723_reset(dev);
subdev = 0;
if (this_board->n_aochan) {
s = dev->subdevices + subdev;
dev->write_subdev = s;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = this_board->n_aochan;
s->maxdata = this_board->ao_maxdata;
s->len_chanlist = this_board->n_aochan;
s->range_table = this_board->rangelist_ao;
s->insn_write = pci1723_ao_write_winsn;
s->insn_read = pci1723_insn_read_ao;
switch (inw(dev->iobase + PCI1723_DIGITAL_IO_PORT_MODE)
& 0x03) {
case 0x00:
s->io_bits = 0xFFFF;
break;
case 0x01:
s->io_bits = 0xFF00;
break;
case 0x02:
s->io_bits = 0x00FF;
break;
case 0x03:
s->io_bits = 0x0000;
break;
}
s->state = inw(dev->iobase + PCI1723_READ_DIGITAL_INPUT_DATA);
subdev++;
}
if (this_board->n_diochan) {
s = dev->subdevices + subdev;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags =
SDF_READABLE | SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = this_board->n_diochan;
s->maxdata = 1;
s->len_chanlist = this_board->n_diochan;
s->range_table = &range_digital;
s->insn_config = pci1723_dio_insn_config;
s->insn_bits = pci1723_dio_insn_bits;
subdev++;
}
devpriv->valid = 1;
pci1723_reset(dev);
return 0;
}
static void pci1723_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->private) {
if (devpriv->valid)
pci1723_reset(dev);
}
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit adv_pci1723_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adv_pci1723_driver);
}
static void __devexit adv_pci1723_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
