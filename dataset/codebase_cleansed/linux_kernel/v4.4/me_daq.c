static inline void sleep(unsigned sec)
{
schedule_timeout_interruptible(sec * HZ);
}
static int me_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 16)
mask = 0x0000ffff;
else
mask = 0xffff0000;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
if (s->io_bits & 0x0000ffff)
devpriv->ctrl2 |= ME_CTRL2_PORT_A_ENA;
else
devpriv->ctrl2 &= ~ME_CTRL2_PORT_A_ENA;
if (s->io_bits & 0xffff0000)
devpriv->ctrl2 |= ME_CTRL2_PORT_B_ENA;
else
devpriv->ctrl2 &= ~ME_CTRL2_PORT_B_ENA;
writew(devpriv->ctrl2, dev->mmio + ME_CTRL2_REG);
return insn->n;
}
static int me_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
void __iomem *mmio_porta = dev->mmio + ME_DIO_PORT_A_REG;
void __iomem *mmio_portb = dev->mmio + ME_DIO_PORT_B_REG;
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0x0000ffff)
writew((s->state & 0xffff), mmio_porta);
if (mask & 0xffff0000)
writew(((s->state >> 16) & 0xffff), mmio_portb);
}
if (s->io_bits & 0x0000ffff)
val = s->state & 0xffff;
else
val = readw(mmio_porta);
if (s->io_bits & 0xffff0000)
val |= (s->state & 0xffff0000);
else
val |= (readw(mmio_portb) << 16);
data[1] = val;
return insn->n;
}
static int me_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readw(dev->mmio + ME_STATUS_REG);
if ((status & ME_STATUS_ADFIFO_EMPTY) == 0)
return 0;
return -EBUSY;
}
static int me_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned int val;
int ret = 0;
int i;
if (aref & AREF_DIFF) {
if (chan > 7 || comedi_range_is_unipolar(s, range))
return -EINVAL;
}
devpriv->ctrl2 &= ~(ME_CTRL2_ADFIFO_ENA | ME_CTRL2_CHANLIST_ENA);
writew(devpriv->ctrl2, dev->mmio + ME_CTRL2_REG);
writew(0x00, dev->mmio + ME_STATUS_REG);
devpriv->ctrl2 |= (ME_CTRL2_ADFIFO_ENA | ME_CTRL2_CHANLIST_ENA);
writew(devpriv->ctrl2, dev->mmio + ME_CTRL2_REG);
val = ME_AI_FIFO_CHANLIST_CHAN(chan) | ME_AI_FIFO_CHANLIST_GAIN(range);
if (comedi_range_is_unipolar(s, range))
val |= ME_AI_FIFO_CHANLIST_UNIPOLAR;
if (aref & AREF_DIFF)
val |= ME_AI_FIFO_CHANLIST_DIFF;
writew(val, dev->mmio + ME_AI_FIFO_REG);
devpriv->ctrl1 |= ME_CTRL1_ADC_MODE_SOFT_TRIG;
writew(devpriv->ctrl1, dev->mmio + ME_CTRL1_REG);
for (i = 0; i < insn->n; i++) {
readw(dev->mmio + ME_CTRL1_REG);
ret = comedi_timeout(dev, s, insn, me_ai_eoc, 0);
if (ret)
break;
val = readw(dev->mmio + ME_AI_FIFO_REG) & s->maxdata;
data[i] = comedi_offset_munge(s, val);
}
devpriv->ctrl1 &= ~ME_CTRL1_ADC_MODE_MASK;
writew(devpriv->ctrl1, dev->mmio + ME_CTRL1_REG);
return ret ? ret : insn->n;
}
static int me_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
devpriv->ctrl2 |= ME_CTRL2_DAC_ENA;
writew(devpriv->ctrl2, dev->mmio + ME_CTRL2_REG);
devpriv->ctrl2 |= ME_CTRL2_BUFFERED_DAC;
writew(devpriv->ctrl2, dev->mmio + ME_CTRL2_REG);
devpriv->dac_ctrl &= ~ME_DAC_CTRL_MASK(chan);
if (range == 0)
devpriv->dac_ctrl |= ME_DAC_CTRL_GAIN(chan);
if (comedi_range_is_bipolar(s, range))
devpriv->dac_ctrl |= ME_DAC_CTRL_BIPOLAR(chan);
writew(devpriv->dac_ctrl, dev->mmio + ME_DAC_CTRL_REG);
readw(dev->mmio + ME_DAC_CTRL_REG);
for (i = 0; i < insn->n; i++) {
val = data[i];
writew(val, dev->mmio + ME_AO_DATA_REG(chan));
}
s->readback[chan] = val;
readw(dev->mmio + ME_CTRL2_REG);
return insn->n;
}
static int me2600_xilinx_download(struct comedi_device *dev,
const u8 *data, size_t size,
unsigned long context)
{
struct me_private_data *devpriv = dev->private;
unsigned int value;
unsigned int file_length;
unsigned int i;
writel(0x00, devpriv->plx_regbase + PLX9052_INTCSR);
value = readw(dev->mmio + XILINX_DOWNLOAD_RESET);
sleep(1);
writeb(0x00, dev->mmio + 0x0);
sleep(1);
if (size < 16)
return -EINVAL;
file_length = (((unsigned int)data[0] & 0xff) << 24) +
(((unsigned int)data[1] & 0xff) << 16) +
(((unsigned int)data[2] & 0xff) << 8) +
((unsigned int)data[3] & 0xff);
for (i = 0; i < file_length; i++)
writeb((data[16 + i] & 0xff), dev->mmio + 0x0);
for (i = 0; i < 5; i++)
writeb(0x00, dev->mmio + 0x0);
value = readl(devpriv->plx_regbase + PLX9052_INTCSR);
if (value & PLX9052_INTCSR_LI2STAT) {
writel(0x00, devpriv->plx_regbase + PLX9052_INTCSR);
dev_err(dev->class_dev, "Xilinx download failed\n");
return -EIO;
}
sleep(1);
writel(PLX9052_INTCSR_LI1ENAB |
PLX9052_INTCSR_LI1POL |
PLX9052_INTCSR_PCIENAB,
devpriv->plx_regbase + PLX9052_INTCSR);
return 0;
}
static int me_reset(struct comedi_device *dev)
{
struct me_private_data *devpriv = dev->private;
writew(0x00, dev->mmio + ME_CTRL1_REG);
writew(0x00, dev->mmio + ME_CTRL2_REG);
writew(0x00, dev->mmio + ME_STATUS_REG);
writew(0x00, dev->mmio + ME_DAC_CTRL_REG);
devpriv->dac_ctrl = 0;
devpriv->ctrl1 = 0;
devpriv->ctrl2 = 0;
return 0;
}
static int me_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct me_board *board = NULL;
struct me_private_data *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(me_boards))
board = &me_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->plx_regbase = pci_ioremap_bar(pcidev, 0);
if (!devpriv->plx_regbase)
return -ENOMEM;
dev->mmio = pci_ioremap_bar(pcidev, 2);
if (!dev->mmio)
return -ENOMEM;
if (board->needs_firmware) {
ret = comedi_load_firmware(dev, &comedi_to_pci_dev(dev)->dev,
ME2600_FIRMWARE,
me2600_xilinx_download, 0);
if (ret < 0)
return ret;
}
me_reset(dev);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->len_chanlist = 16;
s->range_table = &me_ai_range;
s->insn_read = me_ai_insn_read;
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->len_chanlist = 4;
s->range_table = &me_ao_range;
s->insn_write = me_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 32;
s->maxdata = 1;
s->len_chanlist = 32;
s->range_table = &range_digital;
s->insn_bits = me_dio_insn_bits;
s->insn_config = me_dio_insn_config;
return 0;
}
static void me_detach(struct comedi_device *dev)
{
struct me_private_data *devpriv = dev->private;
if (devpriv) {
if (dev->mmio)
me_reset(dev);
if (devpriv->plx_regbase)
iounmap(devpriv->plx_regbase);
}
comedi_pci_detach(dev);
}
static int me_daq_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &me_daq_driver, id->driver_data);
}
