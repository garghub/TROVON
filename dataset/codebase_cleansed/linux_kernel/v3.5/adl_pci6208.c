static int pci6208_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i = 0, Data_Read;
unsigned short chan = CR_CHAN(insn->chanspec);
unsigned long invert = 1 << (16 - 1);
unsigned long out_value;
for (i = 0; i < insn->n; i++) {
out_value = data[i] ^ invert;
do {
Data_Read = (inw(dev->iobase) & 1);
} while (Data_Read);
outw(out_value, dev->iobase + (0x02 * chan));
devpriv->ao_readback[chan] = out_value;
}
return i;
}
static int pci6208_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int pci6208_find_device(struct comedi_device *dev, int bus, int slot)
{
struct pci_dev *pci_dev = NULL;
int i;
for_each_pci_dev(pci_dev) {
if (pci_dev->vendor == PCI_VENDOR_ID_ADLINK) {
for (i = 0; i < ARRAY_SIZE(pci6208_boards); i++) {
if (pci6208_boards[i].dev_id ==
pci_dev->device) {
if ((bus != 0) || (slot != 0)) {
if (pci_dev->bus->number
!= bus ||
PCI_SLOT(pci_dev->devfn)
!= slot) {
continue;
}
}
dev->board_ptr = pci6208_boards + i;
goto found;
}
}
}
}
printk(KERN_ERR "comedi%d: no supported board found! "
"(req. bus/slot : %d/%d)\n",
dev->minor, bus, slot);
return -EIO;
found:
printk("comedi%d: found %s (b:s:f=%d:%d:%d) , irq=%d\n",
dev->minor,
pci6208_boards[i].name,
pci_dev->bus->number,
PCI_SLOT(pci_dev->devfn),
PCI_FUNC(pci_dev->devfn), pci_dev->irq);
devpriv->pci_dev = pci_dev;
return 0;
}
static int
pci6208_pci_setup(struct pci_dev *pci_dev, unsigned long *io_base_ptr,
int dev_minor)
{
unsigned long io_base, io_range, lcr_io_base, lcr_io_range;
if (comedi_pci_enable(pci_dev, "adl_pci6208") < 0) {
printk(KERN_ERR "comedi%d: Failed to enable PCI device "
"and request regions\n",
dev_minor);
return -EIO;
}
lcr_io_base = pci_resource_start(pci_dev, 1);
lcr_io_range = pci_resource_len(pci_dev, 1);
printk(KERN_INFO "comedi%d: local config registers at address"
" 0x%4lx [0x%4lx]\n",
dev_minor, lcr_io_base, lcr_io_range);
io_base = pci_resource_start(pci_dev, 2);
io_range = pci_resource_end(pci_dev, 2) - io_base + 1;
printk("comedi%d: 6208 registers at address 0x%4lx [0x%4lx]\n",
dev_minor, io_base, io_range);
*io_base_ptr = io_base;
return 0;
}
static int pci6208_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int retval;
unsigned long io_base;
printk(KERN_INFO "comedi%d: pci6208: ", dev->minor);
retval = alloc_private(dev, sizeof(struct pci6208_private));
if (retval < 0)
return retval;
retval = pci6208_find_device(dev, it->options[0], it->options[1]);
if (retval < 0)
return retval;
retval = pci6208_pci_setup(devpriv->pci_dev, &io_base, dev->minor);
if (retval < 0)
return retval;
dev->iobase = io_base;
dev->board_name = thisboard->name;
if (alloc_subdevices(dev, 2) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = pci6208_ao_winsn;
s->insn_read = pci6208_ao_rinsn;
printk(KERN_INFO "attached\n");
return 1;
}
static void pci6208_detach(struct comedi_device *dev)
{
if (devpriv && devpriv->pci_dev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
}
}
static int __devinit adl_pci6208_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci6208_driver);
}
static void __devexit adl_pci6208_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
