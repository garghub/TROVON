static int cb_pcimdas_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
struct pci_dev *pcidev = NULL;
int index;
if (alloc_private(dev, sizeof(struct cb_pcimdas_private)) < 0)
return -ENOMEM;
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_COMPUTERBOARDS)
continue;
for (index = 0; index < N_BOARDS; index++) {
if (cb_pcimdas_boards[index].device_id !=
pcidev->device)
continue;
if (it->options[0] || it->options[1]) {
if (pcidev->bus->number != it->options[0] ||
PCI_SLOT(pcidev->devfn) != it->options[1]) {
continue;
}
}
devpriv->pci_dev = pcidev;
dev->board_ptr = cb_pcimdas_boards + index;
goto found;
}
}
dev_err(dev->hw_dev, "No supported ComputerBoards/MeasurementComputing card found on requested position\n");
return -EIO;
found:
dev_dbg(dev->hw_dev, "Found %s on bus %i, slot %i\n",
cb_pcimdas_boards[index].name, pcidev->bus->number,
PCI_SLOT(pcidev->devfn));
switch (thisboard->device_id) {
case 0x56:
break;
default:
dev_dbg(dev->hw_dev, "THIS CARD IS UNSUPPORTED.\n"
"PLEASE REPORT USAGE TO <mocelet@sucs.org>\n");
}
if (comedi_pci_enable(pcidev, "cb_pcimdas")) {
dev_err(dev->hw_dev, "Failed to enable PCI device and request regions\n");
return -EIO;
}
devpriv->BADR0 = pci_resource_start(devpriv->pci_dev, 0);
devpriv->BADR1 = pci_resource_start(devpriv->pci_dev, 1);
devpriv->BADR2 = pci_resource_start(devpriv->pci_dev, 2);
devpriv->BADR3 = pci_resource_start(devpriv->pci_dev, 3);
devpriv->BADR4 = pci_resource_start(devpriv->pci_dev, 4);
dev_dbg(dev->hw_dev, "devpriv->BADR0 = 0x%lx\n", devpriv->BADR0);
dev_dbg(dev->hw_dev, "devpriv->BADR1 = 0x%lx\n", devpriv->BADR1);
dev_dbg(dev->hw_dev, "devpriv->BADR2 = 0x%lx\n", devpriv->BADR2);
dev_dbg(dev->hw_dev, "devpriv->BADR3 = 0x%lx\n", devpriv->BADR3);
dev_dbg(dev->hw_dev, "devpriv->BADR4 = 0x%lx\n", devpriv->BADR4);
dev->board_name = thisboard->name;
if (alloc_subdevices(dev, 3) < 0)
return -ENOMEM;
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
subdev_8255_init(dev, s, NULL, devpriv->BADR4);
else
s->type = COMEDI_SUBD_UNUSED;
return 1;
}
static int cb_pcimdas_detach(struct comedi_device *dev)
{
if (devpriv) {
dev_dbg(dev->hw_dev, "devpriv->BADR0 = 0x%lx\n",
devpriv->BADR0);
dev_dbg(dev->hw_dev, "devpriv->BADR1 = 0x%lx\n",
devpriv->BADR1);
dev_dbg(dev->hw_dev, "devpriv->BADR2 = 0x%lx\n",
devpriv->BADR2);
dev_dbg(dev->hw_dev, "devpriv->BADR3 = 0x%lx\n",
devpriv->BADR3);
dev_dbg(dev->hw_dev, "devpriv->BADR4 = 0x%lx\n",
devpriv->BADR4);
}
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->pci_dev) {
if (devpriv->BADR0)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
}
return 0;
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
outw(0, devpriv->BADR2 + 0);
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
d = inw(devpriv->BADR2 + 0);
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
outw(data[i] & 0x0FFF, devpriv->BADR2 + DAC0_OFFSET);
break;
case 1:
outw(data[i] & 0x0FFF, devpriv->BADR2 + DAC1_OFFSET);
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
static int __devinit driver_cb_pcimdas_pci_probe(struct pci_dev *dev,
const struct pci_device_id
*ent)
{
return comedi_pci_auto_config(dev, driver_cb_pcimdas.driver_name);
}
static void __devexit driver_cb_pcimdas_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_cb_pcimdas_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_cb_pcimdas);
if (retval < 0)
return retval;
driver_cb_pcimdas_pci_driver.name =
(char *)driver_cb_pcimdas.driver_name;
return pci_register_driver(&driver_cb_pcimdas_pci_driver);
}
static void __exit driver_cb_pcimdas_cleanup_module(void)
{
pci_unregister_driver(&driver_cb_pcimdas_pci_driver);
comedi_driver_unregister(&driver_cb_pcimdas);
}
