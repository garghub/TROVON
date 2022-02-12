static int dyna_pci10xx_insn_read_ai(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, counter;
u16 d = 0;
unsigned int chan, range;
chan = CR_CHAN(insn->chanspec);
range = thisboard->range_codes_ai[CR_RANGE((insn->chanspec))];
mutex_lock(&devpriv->mutex);
for (n = 0; n < insn->n; n++) {
smp_mb();
outw_p(0x0000 + range + chan, devpriv->BADR2 + 2);
udelay(10);
for (counter = 0; counter < READ_TIMEOUT; counter++) {
d = inw_p(devpriv->BADR2);
if (d & (1 << 15))
goto conv_finish;
}
data[n] = 0;
printk(KERN_DEBUG "comedi: dyna_pci10xx: "
"timeout reading analog input\n");
continue;
conv_finish:
d &= 0x0FFF;
data[n] = d;
}
mutex_unlock(&devpriv->mutex);
return n;
}
static int dyna_pci10xx_insn_write_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
unsigned int chan, range;
chan = CR_CHAN(insn->chanspec);
range = thisboard->range_codes_ai[CR_RANGE((insn->chanspec))];
mutex_lock(&devpriv->mutex);
for (n = 0; n < insn->n; n++) {
smp_mb();
outw_p(data[n], devpriv->BADR2);
udelay(10);
}
mutex_unlock(&devpriv->mutex);
return n;
}
static int dyna_pci10xx_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
u16 d = 0;
if (insn->n != 2)
return -EINVAL;
mutex_lock(&devpriv->mutex);
smp_mb();
d = inw_p(devpriv->BADR3);
udelay(10);
data[1] = d;
data[0] = s->state;
mutex_unlock(&devpriv->mutex);
return 2;
}
static int dyna_pci10xx_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
mutex_lock(&devpriv->mutex);
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
smp_mb();
outw_p(s->state, devpriv->BADR3);
udelay(10);
}
data[1] = s->state;
mutex_unlock(&devpriv->mutex);
return 2;
}
static int dyna_pci10xx_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
struct pci_dev *pcidev;
unsigned int opt_bus, opt_slot;
int board_index, i;
mutex_lock(&start_stop_sem);
if (alloc_private(dev, sizeof(struct dyna_pci10xx_private)) < 0) {
printk(KERN_ERR "comedi: dyna_pci10xx: "
"failed to allocate memory!\n");
mutex_unlock(&start_stop_sem);
return -ENOMEM;
}
opt_bus = it->options[0];
opt_slot = it->options[1];
dev->board_name = thisboard->name;
dev->irq = 0;
for (pcidev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, NULL);
pcidev != NULL;
pcidev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, pcidev)) {
board_index = -1;
for (i = 0; i < ARRAY_SIZE(boardtypes); ++i) {
if ((pcidev->vendor == PCI_VENDOR_ID_DYNALOG) &&
(pcidev->device == boardtypes[i].device_id)) {
board_index = i;
break;
}
}
if (board_index < 0)
continue;
if (opt_bus || opt_slot) {
if (opt_bus != pcidev->bus->number
|| opt_slot != PCI_SLOT(pcidev->devfn))
continue;
}
goto found;
}
printk(KERN_ERR "comedi: dyna_pci10xx: no supported device found!\n");
mutex_unlock(&start_stop_sem);
return -EIO;
found:
if (!pcidev) {
if (opt_bus || opt_slot) {
printk(KERN_ERR "comedi: dyna_pci10xx: "
"invalid PCI device at b:s %d:%d\n",
opt_bus, opt_slot);
} else {
printk(KERN_ERR "comedi: dyna_pci10xx: "
"invalid PCI device\n");
}
mutex_unlock(&start_stop_sem);
return -EIO;
}
if (comedi_pci_enable(pcidev, DRV_NAME)) {
printk(KERN_ERR "comedi: dyna_pci10xx: "
"failed to enable PCI device and request regions!");
mutex_unlock(&start_stop_sem);
return -EIO;
}
mutex_init(&devpriv->mutex);
dev->board_ptr = &boardtypes[board_index];
devpriv->pci_dev = pcidev;
printk(KERN_INFO "comedi: dyna_pci10xx: device found!\n");
devpriv->BADR0 = pci_resource_start(pcidev, 0);
devpriv->BADR1 = pci_resource_start(pcidev, 1);
devpriv->BADR2 = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
devpriv->BADR4 = pci_resource_start(pcidev, 4);
devpriv->BADR5 = pci_resource_start(pcidev, 5);
if (alloc_subdevices(dev, 4) < 0) {
printk(KERN_ERR "comedi: dyna_pci10xx: "
"failed allocating subdevices\n");
mutex_unlock(&start_stop_sem);
return -ENOMEM;
}
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = thisboard->ai_chans;
s->maxdata = 0x0FFF;
s->range_table = thisboard->range_ai;
s->len_chanlist = 16;
s->insn_read = dyna_pci10xx_insn_read_ai;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = 0x0FFF;
s->range_table = thisboard->range_ao;
s->len_chanlist = 16;
s->insn_write = dyna_pci10xx_insn_write_ao;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = thisboard->di_chans;
s->maxdata = 1;
s->range_table = &range_digital;
s->len_chanlist = thisboard->di_chans;
s->insn_bits = dyna_pci10xx_di_insn_bits;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = thisboard->do_chans;
s->maxdata = 1;
s->range_table = &range_digital;
s->len_chanlist = thisboard->do_chans;
s->state = 0;
s->insn_bits = dyna_pci10xx_do_insn_bits;
devpriv->valid = 1;
mutex_unlock(&start_stop_sem);
printk(KERN_INFO "comedi: dyna_pci10xx: %s - device setup completed!\n",
boardtypes[board_index].name);
return 1;
}
static void dyna_pci10xx_detach(struct comedi_device *dev)
{
if (devpriv && devpriv->pci_dev) {
comedi_pci_disable(devpriv->pci_dev);
mutex_destroy(&devpriv->mutex);
}
}
static int __devinit dyna_pci10xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &dyna_pci10xx_driver);
}
static void __devexit dyna_pci10xx_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
