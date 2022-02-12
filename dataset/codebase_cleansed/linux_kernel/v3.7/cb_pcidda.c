static unsigned int cb_pcidda_serial_in(struct comedi_device *dev)
{
struct cb_pcidda_private *devpriv = dev->private;
unsigned int value = 0;
int i;
const int value_width = 16;
for (i = 1; i <= value_width; i++) {
if (inw_p(devpriv->dac + DACALIBRATION1) & SERIAL_OUT_BIT)
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
outw_p(devpriv->dac_cal1_bits, devpriv->dac + DACALIBRATION1);
}
}
static unsigned int cb_pcidda_read_eeprom(struct comedi_device *dev,
unsigned int address)
{
struct cb_pcidda_private *devpriv = dev->private;
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
outw_p(cal2_bits, devpriv->dac + DACALIBRATION2);
cb_pcidda_serial_out(dev, read_instruction, instruction_length);
cb_pcidda_serial_out(dev, address, address_length);
value = cb_pcidda_serial_in(dev);
cal2_bits &= ~SELECT_EEPROM_BIT;
outw_p(cal2_bits, devpriv->dac + DACALIBRATION2);
return value;
}
static void cb_pcidda_write_caldac(struct comedi_device *dev,
unsigned int caldac, unsigned int channel,
unsigned int value)
{
struct cb_pcidda_private *devpriv = dev->private;
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
outw_p(cal2_bits, devpriv->dac + DACALIBRATION2);
cal2_bits |= DESELECT_CALDAC_BIT(caldac);
outw_p(cal2_bits, devpriv->dac + DACALIBRATION2);
}
static unsigned int caldac_number(unsigned int channel)
{
return channel / 2;
}
static unsigned int fine_gain_channel(unsigned int ao_channel)
{
return 4 * (ao_channel % 2);
}
static unsigned int coarse_gain_channel(unsigned int ao_channel)
{
return 1 + 4 * (ao_channel % 2);
}
static unsigned int coarse_offset_channel(unsigned int ao_channel)
{
return 2 + 4 * (ao_channel % 2);
}
static unsigned int fine_offset_channel(unsigned int ao_channel)
{
return 3 + 4 * (ao_channel % 2);
}
static unsigned int offset_eeprom_address(unsigned int ao_channel,
unsigned int range)
{
return 0x7 + 2 * range + 12 * ao_channel;
}
static unsigned int gain_eeprom_address(unsigned int ao_channel,
unsigned int range)
{
return 0x8 + 2 * range + 12 * ao_channel;
}
static unsigned int eeprom_coarse_byte(unsigned int word)
{
return (word >> 8) & 0xff;
}
static unsigned int eeprom_fine_byte(unsigned int word)
{
return word & 0xff;
}
static void cb_pcidda_calibrate(struct comedi_device *dev, unsigned int channel,
unsigned int range)
{
struct cb_pcidda_private *devpriv = dev->private;
unsigned int coarse_offset, fine_offset, coarse_gain, fine_gain;
devpriv->ao_range[channel] = range;
coarse_offset =
eeprom_coarse_byte(devpriv->eeprom_data
[offset_eeprom_address(channel, range)]);
fine_offset =
eeprom_fine_byte(devpriv->eeprom_data
[offset_eeprom_address(channel, range)]);
coarse_gain =
eeprom_coarse_byte(devpriv->eeprom_data
[gain_eeprom_address(channel, range)]);
fine_gain =
eeprom_fine_byte(devpriv->eeprom_data
[gain_eeprom_address(channel, range)]);
cb_pcidda_write_caldac(dev, caldac_number(channel),
coarse_offset_channel(channel), coarse_offset);
cb_pcidda_write_caldac(dev, caldac_number(channel),
fine_offset_channel(channel), fine_offset);
cb_pcidda_write_caldac(dev, caldac_number(channel),
coarse_gain_channel(channel), coarse_gain);
cb_pcidda_write_caldac(dev, caldac_number(channel),
fine_gain_channel(channel), fine_gain);
}
static int cb_pcidda_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcidda_private *devpriv = dev->private;
unsigned int command;
unsigned int channel, range;
channel = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
if (range != devpriv->ao_range[channel])
cb_pcidda_calibrate(dev, channel, range);
command = NOSU | ENABLEDAC;
switch (range) {
case 0:
command |= BIP | RANGE10V;
break;
case 1:
command |= BIP | RANGE5V;
break;
case 2:
command |= BIP | RANGE2V5;
break;
case 3:
command |= UNIP | RANGE10V;
break;
case 4:
command |= UNIP | RANGE5V;
break;
case 5:
command |= UNIP | RANGE2V5;
break;
}
command |= channel << 2;
outw(command, devpriv->dac + DACONTROL);
outw(data[0], devpriv->dac + DADATA + channel * 2);
return 1;
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
static int cb_pcidda_attach_pci(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct cb_pcidda_board *thisboard;
struct cb_pcidda_private *devpriv;
struct comedi_subdevice *s;
int index;
int ret;
comedi_set_hw_dev(dev, &pcidev->dev);
thisboard = cb_pcidda_find_boardinfo(dev, pcidev);
if (!pcidev)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
ret = alloc_private(dev, sizeof(*devpriv));
if (ret)
return ret;
devpriv = dev->private;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
devpriv->digitalio = pci_resource_start(pcidev, 2);
devpriv->dac = pci_resource_start(pcidev, 3);
dev->iobase = devpriv->dac;
if (thisboard->status == 2)
printk
("WARNING: DRIVER FOR THIS BOARD NOT CHECKED WITH MANUAL. "
"WORKS ASSUMING FULL COMPATIBILITY WITH PCI-DDA08/12. "
"PLEASE REPORT USAGE TO <ivanmr@altavista.com>.\n");
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = thisboard->ranges;
s->insn_write = cb_pcidda_ao_winsn;
s = &dev->subdevices[1];
subdev_8255_init(dev, s, NULL, devpriv->digitalio);
s = &dev->subdevices[2];
subdev_8255_init(dev, s, NULL, devpriv->digitalio + PORT2A);
dev_dbg(dev->class_dev, "eeprom:\n");
for (index = 0; index < EEPROM_SIZE; index++) {
devpriv->eeprom_data[index] = cb_pcidda_read_eeprom(dev, index);
dev_dbg(dev->class_dev, "%i:0x%x\n", index,
devpriv->eeprom_data[index]);
}
for (index = 0; index < thisboard->ao_chans; index++)
cb_pcidda_calibrate(dev, index, devpriv->ao_range[index]);
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
static int __devinit cb_pcidda_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcidda_driver);
}
static void __devexit cb_pcidda_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
