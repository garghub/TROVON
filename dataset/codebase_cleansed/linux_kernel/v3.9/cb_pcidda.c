static unsigned int cb_pcidda_serial_in(struct comedi_device *dev)
{
unsigned int value = 0;
int i;
const int value_width = 16;
for (i = 1; i <= value_width; i++) {
if (inw_p(dev->iobase + DACALIBRATION1) & SERIAL_OUT_BIT)
value |= 1 << (value_width - i);
}
return value;
}
static void cb_pcidda_serial_out(struct comedi_device *dev, unsigned int value,
unsigned int num_bits)
{
struct cb_pcidda_private *devpriv = dev->private;
int i;
for (i = 1; i <= num_bits; i++) {
if (value & (1 << (num_bits - i)))
devpriv->dac_cal1_bits |= SERIAL_IN_BIT;
else
devpriv->dac_cal1_bits &= ~SERIAL_IN_BIT;
outw_p(devpriv->dac_cal1_bits, dev->iobase + DACALIBRATION1);
}
}
static unsigned int cb_pcidda_read_eeprom(struct comedi_device *dev,
unsigned int address)
{
unsigned int i;
unsigned int cal2_bits;
unsigned int value;
const int max_num_caldacs = 4;
const int read_instruction = 0x6;
const int instruction_length = 3;
const int address_length = 8;
cal2_bits = SELECT_EEPROM_BIT | DESELECT_REF_DAC_BIT | DUMMY_BIT;
for (i = 0; i < max_num_caldacs; i++)
cal2_bits |= DESELECT_CALDAC_BIT(i);
outw_p(cal2_bits, dev->iobase + DACALIBRATION2);
cb_pcidda_serial_out(dev, read_instruction, instruction_length);
cb_pcidda_serial_out(dev, address, address_length);
value = cb_pcidda_serial_in(dev);
cal2_bits &= ~SELECT_EEPROM_BIT;
outw_p(cal2_bits, dev->iobase + DACALIBRATION2);
return value;
}
static void cb_pcidda_write_caldac(struct comedi_device *dev,
unsigned int caldac, unsigned int channel,
unsigned int value)
{
unsigned int cal2_bits;
unsigned int i;
const int num_channel_bits = 3;
const int num_caldac_bits = 8;
const int max_num_caldacs = 4;
cb_pcidda_serial_out(dev, channel, num_channel_bits);
cb_pcidda_serial_out(dev, value, num_caldac_bits);
cal2_bits = DESELECT_REF_DAC_BIT | DUMMY_BIT;
for (i = 0; i < max_num_caldacs; i++)
cal2_bits |= DESELECT_CALDAC_BIT(i);
cal2_bits &= ~DESELECT_CALDAC_BIT(caldac);
outw_p(cal2_bits, dev->iobase + DACALIBRATION2);
cal2_bits |= DESELECT_CALDAC_BIT(caldac);
outw_p(cal2_bits, dev->iobase + DACALIBRATION2);
}
static void cb_pcidda_calibrate(struct comedi_device *dev, unsigned int channel,
unsigned int range)
{
struct cb_pcidda_private *devpriv = dev->private;
unsigned int caldac = channel / 2;
unsigned int chan = 4 * (channel % 2);
unsigned int index = 2 * range + 12 * channel;
unsigned int offset;
unsigned int gain;
devpriv->ao_range[channel] = range;
offset = devpriv->eeprom_data[0x7 + index];
gain = devpriv->eeprom_data[0x8 + index];
cb_pcidda_write_caldac(dev, caldac, chan + CB_DDA_CALDAC_COURSE_OFFSET,
(offset >> 8) & 0xff);
cb_pcidda_write_caldac(dev, caldac, chan + CB_DDA_CALDAC_FINE_OFFSET,
offset & 0xff);
cb_pcidda_write_caldac(dev, caldac, chan + CB_DDA_CALDAC_COURSE_GAIN,
(gain >> 8) & 0xff);
cb_pcidda_write_caldac(dev, caldac, chan + CB_DDA_CALDAC_FINE_GAIN,
gain & 0xff);
}
static int cb_pcidda_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidda_private *devpriv = dev->private;
unsigned int channel = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int ctrl;
if (range != devpriv->ao_range[channel])
cb_pcidda_calibrate(dev, channel, range);
ctrl = CB_DDA_DA_CTRL_EN | CB_DDA_DA_CTRL_DAC(channel);
switch (range) {
case 0:
case 3:
ctrl |= CB_DDA_DA_CTRL_RANGE10V;
break;
case 1:
case 4:
ctrl |= CB_DDA_DA_CTRL_RANGE5V;
break;
case 2:
case 5:
ctrl |= CB_DDA_DA_CTRL_RANGE2V5;
break;
}
if (range > 2)
ctrl |= CB_DDA_DA_CTRL_UNIP;
outw(ctrl, dev->iobase + CB_DDA_DA_CTRL_REG);
outw(data[0], dev->iobase + CB_DDA_DA_DATA_REG(channel));
return insn->n;
}
static const void *cb_pcidda_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct cb_pcidda_board *thisboard;
int i;
for (i = 0; i < ARRAY_SIZE(cb_pcidda_boards); i++) {
thisboard = &cb_pcidda_boards[i];
if (thisboard->device_id != pcidev->device)
return thisboard;
}
return NULL;
}
static int cb_pcidda_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct cb_pcidda_board *thisboard;
struct cb_pcidda_private *devpriv;
struct comedi_subdevice *s;
unsigned long iobase_8255;
int i;
int ret;
thisboard = cb_pcidda_find_boardinfo(dev, pcidev);
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 3);
iobase_8255 = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = &cb_pcidda_ranges;
s->insn_write = cb_pcidda_ao_insn_write;
for (i = 0; i < 2; i++) {
s = &dev->subdevices[1 + i];
ret = subdev_8255_init(dev, s, NULL, iobase_8255 + (i * 4));
if (ret)
return ret;
}
for (i = 0; i < EEPROM_SIZE; i++)
devpriv->eeprom_data[i] = cb_pcidda_read_eeprom(dev, i);
for (i = 0; i < thisboard->ao_chans; i++)
cb_pcidda_calibrate(dev, i, devpriv->ao_range[i]);
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void cb_pcidda_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (dev->subdevices) {
subdev_8255_cleanup(dev, &dev->subdevices[1]);
subdev_8255_cleanup(dev, &dev->subdevices[2]);
}
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int cb_pcidda_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcidda_driver);
}
