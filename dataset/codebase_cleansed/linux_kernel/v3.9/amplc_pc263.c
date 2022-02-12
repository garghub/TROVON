static inline bool is_isa_board(const struct pc263_board *board)
{
return DO_ISA && board->bustype == isa_bustype;
}
static inline bool is_pci_board(const struct pc263_board *board)
{
return DO_PCI && board->bustype == pci_bustype;
}
static const struct pc263_board *pc263_find_pci_board(struct pci_dev *pci_dev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(pc263_boards); i++)
if (is_pci_board(&pc263_boards[i]) &&
pci_dev->device == pc263_boards[i].devid)
return &pc263_boards[i];
return NULL;
}
static struct pci_dev *pc263_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct pc263_board *thisboard = comedi_board(dev);
struct pci_dev *pci_dev = NULL;
int bus = it->options[0];
int slot = it->options[1];
for_each_pci_dev(pci_dev) {
if (bus || slot) {
if (bus != pci_dev->bus->number ||
slot != PCI_SLOT(pci_dev->devfn))
continue;
}
if (pci_dev->vendor != PCI_VENDOR_ID_AMPLICON)
continue;
if (thisboard->model == anypci_model) {
const struct pc263_board *foundboard;
foundboard = pc263_find_pci_board(pci_dev);
if (foundboard == NULL)
continue;
dev->board_ptr = thisboard = foundboard;
} else {
if (pci_dev->device != thisboard->devid)
continue;
}
return pci_dev;
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int pc263_request_region(struct comedi_device *dev, unsigned long from,
unsigned long extent)
{
if (!from || !request_region(from, extent, PC263_DRIVER_NAME)) {
dev_err(dev->class_dev, "I/O port conflict (%#lx,%lu)!\n",
from, extent);
return -EIO;
}
return 0;
}
static int pc263_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state & 0xFF, dev->iobase);
outb(s->state >> 8, dev->iobase + 1);
}
return insn->n;
}
static void pc263_report_attach(struct comedi_device *dev)
{
const struct pc263_board *thisboard = comedi_board(dev);
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
char tmpbuf[40];
if (is_isa_board(thisboard))
snprintf(tmpbuf, sizeof(tmpbuf), "(base %#lx) ", dev->iobase);
else if (is_pci_board(thisboard))
snprintf(tmpbuf, sizeof(tmpbuf), "(pci %s) ",
pci_name(pcidev));
else
tmpbuf[0] = '\0';
dev_info(dev->class_dev, "%s %sattached\n", dev->board_name, tmpbuf);
}
static int pc263_common_attach(struct comedi_device *dev, unsigned long iobase)
{
const struct pc263_board *thisboard = comedi_board(dev);
struct comedi_subdevice *s;
int ret;
dev->board_name = thisboard->name;
dev->iobase = iobase;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pc263_do_insn_bits;
s->state = inb(dev->iobase) | (inb(dev->iobase + 1) << 8);
pc263_report_attach(dev);
return 1;
}
static int pc263_pci_common_attach(struct comedi_device *dev,
struct pci_dev *pci_dev)
{
unsigned long iobase;
int ret;
comedi_set_hw_dev(dev, &pci_dev->dev);
ret = comedi_pci_enable(pci_dev, PC263_DRIVER_NAME);
if (ret < 0) {
dev_err(dev->class_dev,
"error! cannot enable PCI device and request regions!\n");
return ret;
}
iobase = pci_resource_start(pci_dev, 2);
return pc263_common_attach(dev, iobase);
}
static int pc263_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pc263_board *thisboard = comedi_board(dev);
int ret;
dev_info(dev->class_dev, PC263_DRIVER_NAME ": attach\n");
if (is_isa_board(thisboard)) {
unsigned long iobase = it->options[0];
ret = pc263_request_region(dev, iobase, PC263_IO_SIZE);
if (ret < 0)
return ret;
return pc263_common_attach(dev, iobase);
} else if (is_pci_board(thisboard)) {
struct pci_dev *pci_dev;
pci_dev = pc263_find_pci_dev(dev, it);
if (!pci_dev)
return -EIO;
return pc263_pci_common_attach(dev, pci_dev);
} else {
dev_err(dev->class_dev, PC263_DRIVER_NAME
": BUG! cannot determine board type!\n");
return -EINVAL;
}
}
static int pc263_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pci_dev;
if (!DO_PCI)
return -EINVAL;
pci_dev = comedi_to_pci_dev(dev);
dev_info(dev->class_dev, PC263_DRIVER_NAME ": attach pci %s\n",
pci_name(pci_dev));
dev->board_ptr = pc263_find_pci_board(pci_dev);
if (dev->board_ptr == NULL) {
dev_err(dev->class_dev, "BUG! cannot determine board type!\n");
return -EINVAL;
}
pci_dev_get(pci_dev);
return pc263_pci_common_attach(dev, pci_dev);
}
static void pc263_detach(struct comedi_device *dev)
{
const struct pc263_board *thisboard = comedi_board(dev);
if (!thisboard)
return;
if (is_isa_board(thisboard)) {
if (dev->iobase)
release_region(dev->iobase, PC263_IO_SIZE);
} else if (is_pci_board(thisboard)) {
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
}
static int amplc_pc263_pci_probe(struct pci_dev *dev,
const struct pci_device_id
*ent)
{
return comedi_pci_auto_config(dev, &amplc_pc263_driver);
}
