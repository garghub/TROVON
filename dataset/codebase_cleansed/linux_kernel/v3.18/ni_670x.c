static int ni_670x_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
writel(((chan & 15) << 1) | ((chan & 16) >> 4),
dev->mmio + AO_CHAN_OFFSET);
writel(val, dev->mmio + AO_VALUE_OFFSET);
}
s->readback[chan] = val;
return insn->n;
}
static int ni_670x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
writel(s->state, dev->mmio + DIO_PORT0_DATA_OFFSET);
data[1] = readl(dev->mmio + DIO_PORT0_DATA_OFFSET);
return insn->n;
}
static int ni_670x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
writel(s->io_bits, dev->mmio + DIO_PORT0_DIR_OFFSET);
return insn->n;
}
static int ni_670x_mite_init(struct pci_dev *pcidev)
{
void __iomem *mite_base;
u32 main_phys_addr;
mite_base = pci_ioremap_bar(pcidev, 0);
if (!mite_base)
return -ENOMEM;
main_phys_addr = pci_resource_start(pcidev, 1);
writel(main_phys_addr | WENAB, mite_base + MITE_IODWBSR);
iounmap(mite_base);
return 0;
}
static int ni_670x_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_670x_board *thisboard = NULL;
struct ni_670x_private *devpriv;
struct comedi_subdevice *s;
int ret;
int i;
if (context < ARRAY_SIZE(ni_670x_boards))
thisboard = &ni_670x_boards[context];
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = ni_670x_mite_init(pcidev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 1);
if (!dev->mmio)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = 0xffff;
if (s->n_chan == 32) {
const struct comedi_lrange **range_table_list;
range_table_list = kmalloc(sizeof(struct comedi_lrange *) * 32,
GFP_KERNEL);
if (!range_table_list)
return -ENOMEM;
s->range_table_list = range_table_list;
for (i = 0; i < 16; i++) {
range_table_list[i] = &range_bipolar10;
range_table_list[16 + i] = &range_0_20mA;
}
} else {
s->range_table = &range_bipolar10;
}
s->insn_write = ni_670x_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_670x_dio_insn_bits;
s->insn_config = ni_670x_dio_insn_config;
writel(0x10, dev->mmio + MISC_CONTROL_OFFSET);
writel(0x00, dev->mmio + AO_CONTROL_OFFSET);
return 0;
}
static void ni_670x_detach(struct comedi_device *dev)
{
struct comedi_subdevice *s;
comedi_pci_detach(dev);
if (dev->n_subdevices) {
s = &dev->subdevices[0];
if (s)
kfree(s->range_table_list);
}
}
static int ni_670x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_670x_driver, id->driver_data);
}
