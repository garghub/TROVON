static int mf6x4_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
data[1] = ioread16(devpriv->bar1_mem + MF6X4_DIN_R) & MF6X4_DIN_M;
return insn->n;
}
static int mf6x4_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
if (comedi_dio_update_state(s, data))
iowrite16(s->state & MF6X4_DOUT_M,
devpriv->bar1_mem + MF6X4_DOUT_R);
data[1] = s->state;
return insn->n;
}
static int mf6x4_ai_wait_for_eoc(struct comedi_device *dev,
unsigned int timeout)
{
struct mf6x4_private *devpriv = dev->private;
unsigned int eolc;
while (timeout--) {
eolc = ioread32(devpriv->gpioc_R) & MF6X4_GPIOC_EOLC;
if (eolc)
return 0;
udelay(1);
}
return -ETIME;
}
static int mf6x4_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int ret;
int i;
int d;
iowrite16((1 << chan) & MF6X4_ADCTRL_M,
devpriv->bar1_mem + MF6X4_ADCTRL_R);
for (i = 0; i < insn->n; i++) {
ioread16(devpriv->bar1_mem + MF6X4_ADSTART_R);
ret = mf6x4_ai_wait_for_eoc(dev, 100);
if (ret)
return ret;
d = ioread16(devpriv->bar1_mem + MF6X4_ADDATA_R);
d &= s->maxdata;
data[i] = d;
}
iowrite16(0x0, devpriv->bar1_mem + MF6X4_ADCTRL_R);
return insn->n;
}
static int mf6x4_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
uint32_t gpioc;
int i;
gpioc = ioread32(devpriv->gpioc_R);
iowrite32((gpioc & ~MF6X4_GPIOC_LDAC) | MF6X4_GPIOC_DACEN,
devpriv->gpioc_R);
for (i = 0; i < insn->n; i++) {
iowrite16(data[i] & MF6X4_DA_M,
devpriv->bar1_mem + MF6X4_DAC_R(chan));
devpriv->ao_readback[chan] = data[i];
}
return insn->n;
}
static int mf6x4_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct mf6x4_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
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
devpriv->bar1_mem = pci_ioremap_bar(pcidev, board->bar_nums[1]);
if (!devpriv->bar1_mem)
return -ENODEV;
devpriv->bar2_mem = pci_ioremap_bar(pcidev, board->bar_nums[2]);
if (!devpriv->bar2_mem)
return -ENODEV;
if (board == &mf6x4_boards[BOARD_MF634])
devpriv->gpioc_R = devpriv->bar2_mem + MF634_GPIOC_R;
else
devpriv->gpioc_R = devpriv->bar0_mem + MF624_GPIOC_R;
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
s->insn_read = mf6x4_ao_insn_read;
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
if (devpriv->bar0_mem)
iounmap(devpriv->bar0_mem);
if (devpriv->bar1_mem)
iounmap(devpriv->bar1_mem);
if (devpriv->bar2_mem)
iounmap(devpriv->bar2_mem);
comedi_pci_disable(dev);
}
static int mf6x4_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &mf6x4_driver, id->driver_data);
}
