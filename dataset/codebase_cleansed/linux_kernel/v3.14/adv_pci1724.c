static uint32_t dac_data_bits(uint16_t dac_data)
{
return dac_data & DAC_DATA_MASK;
}
static uint32_t dac_channel_select_bits(unsigned channel)
{
return (channel << 16) & DAC_CHANNEL_SELECT_MASK;
}
static uint32_t dac_group_select_bits(unsigned group)
{
return (1 << (20 + group)) & DAC_GROUP_SELECT_MASK;
}
static uint32_t dac_channel_and_group_select_bits(unsigned comedi_channel)
{
return dac_channel_select_bits(comedi_channel % 8) |
dac_group_select_bits(comedi_channel / 8);
}
static int wait_for_dac_idle(struct comedi_device *dev)
{
static const int timeout = 10000;
int i;
for (i = 0; i < timeout; ++i) {
if ((inl(dev->iobase + SYNC_OUTPUT_REG) & DAC_BUSY) == 0)
break;
udelay(1);
}
if (i == timeout) {
comedi_error(dev, "Timed out waiting for dac to become idle.");
return -EIO;
}
return 0;
}
static int set_dac(struct comedi_device *dev, unsigned mode, unsigned channel,
unsigned data)
{
int retval;
unsigned control_bits;
retval = wait_for_dac_idle(dev);
if (retval < 0)
return retval;
control_bits = mode;
control_bits |= dac_channel_and_group_select_bits(channel);
control_bits |= dac_data_bits(data);
outl(control_bits, dev->iobase + DAC_CONTROL_REG);
return 0;
}
static int ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
int retval;
int i;
outl(0, dev->iobase + SYNC_OUTPUT_REG);
for (i = 0; i < insn->n; ++i) {
retval = set_dac(dev, DAC_NORMAL_MODE, channel, data[i]);
if (retval < 0)
return retval;
devpriv->ao_value[channel] = data[i];
}
return insn->n;
}
static int ao_readback_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
int i;
if (devpriv->ao_value[channel] < 0) {
comedi_error(dev,
"Cannot read back channels which have not yet been written to.");
return -EIO;
}
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_value[channel];
return insn->n;
}
static int offset_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
int retval;
int i;
outl(0, dev->iobase + SYNC_OUTPUT_REG);
for (i = 0; i < insn->n; ++i) {
retval = set_dac(dev, DAC_OFFSET_MODE, channel, data[i]);
if (retval < 0)
return retval;
devpriv->offset_value[channel] = data[i];
}
return insn->n;
}
static int offset_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
unsigned int channel = CR_CHAN(insn->chanspec);
int i;
if (devpriv->offset_value[channel] < 0) {
comedi_error(dev,
"Cannot read back channels which have not yet been written to.");
return -EIO;
}
for (i = 0; i < insn->n; i++)
data[i] = devpriv->offset_value[channel];
return insn->n;
}
static int gain_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
int retval;
int i;
outl(0, dev->iobase + SYNC_OUTPUT_REG);
for (i = 0; i < insn->n; ++i) {
retval = set_dac(dev, DAC_GAIN_MODE, channel, data[i]);
if (retval < 0)
return retval;
devpriv->gain_value[channel] = data[i];
}
return insn->n;
}
static int gain_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct adv_pci1724_private *devpriv = dev->private;
unsigned int channel = CR_CHAN(insn->chanspec);
int i;
if (devpriv->gain_value[channel] < 0) {
comedi_error(dev,
"Cannot read back channels which have not yet been written to.");
return -EIO;
}
for (i = 0; i < insn->n; i++)
data[i] = devpriv->gain_value[channel];
return insn->n;
}
static int setup_subdevices(struct comedi_device *dev)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_GROUND;
s->n_chan = NUM_AO_CHANNELS;
s->maxdata = 0x3fff;
s->range_table = &ao_ranges_1724;
s->insn_read = ao_readback_insn;
s->insn_write = ao_winsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = NUM_AO_CHANNELS;
s->insn_read = offset_read_insn;
s->insn_write = offset_write_insn;
s->maxdata = 0x3fff;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = NUM_AO_CHANNELS;
s->insn_read = gain_read_insn;
s->insn_write = gain_write_insn;
s->maxdata = 0x3fff;
return 0;
}
static int adv_pci1724_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct adv_pci1724_private *devpriv;
int i;
int retval;
unsigned int board_id;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
for (i = 0; i < NUM_AO_CHANNELS; ++i) {
devpriv->ao_value[i] = -1;
devpriv->offset_value[i] = -1;
devpriv->gain_value[i] = -1;
}
retval = comedi_pci_enable(dev);
if (retval)
return retval;
dev->iobase = pci_resource_start(pcidev, 2);
board_id = inl(dev->iobase + BOARD_ID_REG) & BOARD_ID_MASK;
dev_info(dev->class_dev, "board id: %d\n", board_id);
retval = setup_subdevices(dev);
if (retval < 0)
return retval;
dev_info(dev->class_dev, "%s (pci %s) attached, board id: %u\n",
dev->board_name, pci_name(pcidev), board_id);
return 0;
}
static int adv_pci1724_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adv_pci1724_driver,
id->driver_data);
}
