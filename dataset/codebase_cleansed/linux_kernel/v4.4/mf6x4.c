static int mf6x4_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = ioread16(dev->mmio + MF6X4_DIN_REG) & MF6X4_DIN_MASK;
return insn->n;
}
static int mf6x4_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
iowrite16(s->state, dev->mmio + MF6X4_DOUT_REG);
data[1] = s->state;
return insn->n;
}
static int mf6x4_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct mf6x4_private *devpriv = dev->private;
unsigned int status;
status = ioread32(devpriv->gpioc_reg);
if (status & MF6X4_GPIOC_EOLC)
return 0;
return -EBUSY;
}
static int mf6x4_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int d;
int ret;
int i;
iowrite16(MF6X4_ADCTRL_CHAN(chan), dev->mmio + MF6X4_ADCTRL_REG);
for (i = 0; i < insn->n; i++) {
ioread16(dev->mmio + MF6X4_ADSTART_REG);
ret = comedi_timeout(dev, s, insn, mf6x4_ai_eoc, 0);
if (ret)
return ret;
d = ioread16(dev->mmio + MF6X4_ADDATA_REG);
d &= s->maxdata;
data[i] = comedi_offset_munge(s, d);
}
iowrite16(0x0, dev->mmio + MF6X4_ADCTRL_REG);
return insn->n;
}
static int mf6x4_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
unsigned int gpioc;
int i;
gpioc = ioread32(devpriv->gpioc_reg);
iowrite32((gpioc & ~MF6X4_GPIOC_LDAC) | MF6X4_GPIOC_DACEN,
devpriv->gpioc_reg);
for (i = 0; i < insn->n; i++) {
val = data[i];
iowrite16(val, dev->mmio + MF6X4_DAC_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int mf6x4_auto_attach(struct comedi_device *dev, unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct mf6x4_board *board = NULL;
struct mf6x4_private *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(mf6x4_boards))
board = &mf6x4_boards[context];
else
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->bar0_mem = pci_ioremap_bar(pcidev, board->bar_nums[0]);
if (!devpriv->bar0_mem)
return -ENODEV;
dev->mmio = pci_ioremap_bar(pcidev, board->bar_nums[1]);
if (!dev->mmio)
return -ENODEV;
devpriv->bar2_mem = pci_ioremap_bar(pcidev, board->bar_nums[2]);
if (!devpriv->bar2_mem)
return -ENODEV;
if (board == &mf6x4_boards[BOARD_MF634])
devpriv->gpioc_reg = devpriv->bar2_mem + MF634_GPIOC_REG;
else
devpriv->gpioc_reg = devpriv->bar0_mem + MF624_GPIOC_REG;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->maxdata = 0x3fff;
s->range_table = &range_bipolar10;
s->insn_read = mf6x4_ai_insn_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 0x3fff;
s->range_table = &range_bipolar10;
s->insn_write = mf6x4_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = mf6x4_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = mf6x4_do_insn_bits;
return 0;
}
static void mf6x4_detach(struct comedi_device *dev)
{
struct mf6x4_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->bar0_mem)
iounmap(devpriv->bar0_mem);
if (devpriv->bar2_mem)
iounmap(devpriv->bar2_mem);
}
comedi_pci_detach(dev);
}
static int mf6x4_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &mf6x4_driver, id->driver_data);
}
