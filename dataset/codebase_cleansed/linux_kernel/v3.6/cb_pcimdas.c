static struct pci_dev *cb_pcimdas_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pcidev) {
if (bus || slot) {
if (bus != pcidev->bus->number ||
slot != PCI_SLOT(pcidev->devfn))
continue;
}
if (pcidev->vendor != PCI_VENDOR_ID_COMPUTERBOARDS)
continue;
for (i = 0; i < ARRAY_SIZE(cb_pcimdas_boards); i++) {
if (cb_pcimdas_boards[i].device_id != pcidev->device)
continue;
dev->board_ptr = cb_pcimdas_boards + i;
return pcidev;
}
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int cb_pcimdas_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
struct comedi_subdevice *s;
unsigned long iobase_8255;
int ret;
if (alloc_private(dev, sizeof(struct cb_pcimdas_private)) < 0)
return -ENOMEM;
pcidev = cb_pcimdas_find_pci_dev(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
switch (thisboard->device_id) {
case 0x56:
break;
default:
dev_dbg(dev->class_dev, "THIS CARD IS UNSUPPORTED.\n");
dev_dbg(dev->class_dev,
"PLEASE REPORT USAGE TO <mocelet@sucs.org>\n");
}
if (comedi_pci_enable(pcidev, "cb_pcimdas")) {
dev_err(dev->class_dev,
"Failed to enable PCI device and request regions\n");
return -EIO;
}
dev->iobase = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
iobase_8255 = pci_resource_start(pcidev, 4);
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = thisboard->ai_se_chans;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &range_unknown;
s->len_chanlist = 1;
s->insn_read = cb_pcimdas_ai_rinsn;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_nchan;
s->maxdata = 1 << thisboard->ao_bits;
s->range_table = &range_unknown;
s->insn_write = &cb_pcimdas_ao_winsn;
s->insn_read = &cb_pcimdas_ao_rinsn;
s = dev->subdevices + 2;
if (thisboard->has_dio)
subdev_8255_init(dev, s, NULL, iobase_8255);
else
s->type = COMEDI_SUBD_UNUSED;
return 1;
}
static void cb_pcimdas_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int cb_pcimdas_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, i;
unsigned int d;
unsigned int busy;
int chan = CR_CHAN(insn->chanspec);
unsigned short chanlims;
int maxchans;
if ((inb(devpriv->BADR3 + 2) & 0x20) == 0)
maxchans = thisboard->ai_diff_chans;
else
maxchans = thisboard->ai_se_chans;
if (chan > (maxchans - 1))
return -ETIMEDOUT;
d = inb(devpriv->BADR3 + 5);
if ((d & 0x03) > 0) {
d = d & 0xfd;
outb(d, devpriv->BADR3 + 5);
}
outb(0x01, devpriv->BADR3 + 6);
outb(0x00, devpriv->BADR3 + 7);
chanlims = chan | (chan << 4);
outb(chanlims, devpriv->BADR3 + 0);
for (n = 0; n < insn->n; n++) {
outw(0, dev->iobase + 0);
#define TIMEOUT 1000
for (i = 0; i < TIMEOUT; i++) {
busy = inb(devpriv->BADR3 + 2) & 0x80;
if (!busy)
break;
}
if (i == TIMEOUT) {
printk("timeout\n");
return -ETIMEDOUT;
}
d = inw(dev->iobase + 0);
data[n] = d;
}
return n;
}
static int cb_pcimdas_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
switch (chan) {
case 0:
outw(data[i] & 0x0FFF, dev->iobase + DAC0_OFFSET);
break;
case 1:
outw(data[i] & 0x0FFF, dev->iobase + DAC1_OFFSET);
break;
default:
return -1;
}
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int cb_pcimdas_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int __devinit cb_pcimdas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcimdas_driver);
}
static void __devexit cb_pcimdas_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
