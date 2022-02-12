static int apci3501_wait_for_dac(struct comedi_device *dev)
{
unsigned int status;
do {
status = inl(dev->iobase + APCI3501_AO_CTRL_STATUS_REG);
} while (!(status & APCI3501_AO_STATUS_READY));
return 0;
}
static int apci3501_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int cfg = APCI3501_AO_DATA_CHAN(chan);
int ret;
int i;
if (range) {
outl(0, dev->iobase + APCI3501_AO_CTRL_STATUS_REG);
} else {
cfg |= APCI3501_AO_DATA_BIPOLAR;
outl(APCI3501_AO_CTRL_BIPOLAR,
dev->iobase + APCI3501_AO_CTRL_STATUS_REG);
}
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
if (range == 1) {
if (data[i] > 0x1fff) {
dev_err(dev->class_dev,
"Unipolar resolution is only 13-bits\n");
return -EINVAL;
}
}
ret = apci3501_wait_for_dac(dev);
if (ret)
return ret;
outl(cfg | APCI3501_AO_DATA_VAL(val),
dev->iobase + APCI3501_AO_DATA_REG);
s->readback[chan] = val;
}
return insn->n;
}
static int apci3501_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + APCI3501_DI_REG) & 0x3;
return insn->n;
}
static int apci3501_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
s->state = inl(dev->iobase + APCI3501_DO_REG);
if (comedi_dio_update_state(s, data))
outl(s->state, dev->iobase + APCI3501_DO_REG);
data[1] = s->state;
return insn->n;
}
static void apci3501_eeprom_wait(unsigned long iobase)
{
unsigned char val;
do {
val = inb(iobase + AMCC_OP_REG_MCSR_NVCMD);
} while (val & 0x80);
}
static unsigned short apci3501_eeprom_readw(unsigned long iobase,
unsigned short addr)
{
unsigned short val = 0;
unsigned char tmp;
unsigned char i;
addr += NVRAM_USER_DATA_START;
for (i = 0; i < 2; i++) {
outb(NVCMD_LOAD_LOW, iobase + AMCC_OP_REG_MCSR_NVCMD);
apci3501_eeprom_wait(iobase);
outb((addr + i) & 0xff, iobase + AMCC_OP_REG_MCSR_NVDATA);
apci3501_eeprom_wait(iobase);
outb(NVCMD_LOAD_HIGH, iobase + AMCC_OP_REG_MCSR_NVCMD);
apci3501_eeprom_wait(iobase);
outb(((addr + i) >> 8) & 0xff,
iobase + AMCC_OP_REG_MCSR_NVDATA);
apci3501_eeprom_wait(iobase);
outb(NVCMD_BEGIN_READ, iobase + AMCC_OP_REG_MCSR_NVCMD);
apci3501_eeprom_wait(iobase);
tmp = inb(iobase + AMCC_OP_REG_MCSR_NVDATA);
apci3501_eeprom_wait(iobase);
if (i == 0)
val |= tmp;
else
val |= (tmp << 8);
}
return val;
}
static int apci3501_eeprom_get_ao_n_chan(struct comedi_device *dev)
{
struct apci3501_private *devpriv = dev->private;
unsigned char nfuncs;
int i;
nfuncs = apci3501_eeprom_readw(devpriv->amcc, 10) & 0xff;
for (i = 0; i < nfuncs; i++) {
unsigned short offset = i * 4;
unsigned short addr;
unsigned char func;
unsigned short val;
func = apci3501_eeprom_readw(devpriv->amcc, 12 + offset) & 0x3f;
addr = apci3501_eeprom_readw(devpriv->amcc, 14 + offset);
if (func == EEPROM_ANALOGOUTPUT) {
val = apci3501_eeprom_readw(devpriv->amcc, addr + 10);
return (val >> 4) & 0x3ff;
}
}
return 0;
}
static int apci3501_eeprom_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3501_private *devpriv = dev->private;
unsigned short addr = CR_CHAN(insn->chanspec);
data[0] = apci3501_eeprom_readw(devpriv->amcc, 2 * addr);
return insn->n;
}
static int apci3501_reset(struct comedi_device *dev)
{
unsigned int val;
int chan;
int ret;
outl(0x0, dev->iobase + APCI3501_DO_REG);
outl(APCI3501_AO_CTRL_BIPOLAR,
dev->iobase + APCI3501_AO_CTRL_STATUS_REG);
val = APCI3501_AO_DATA_BIPOLAR | APCI3501_AO_DATA_VAL(0);
for (chan = 0; chan < 8; chan++) {
ret = apci3501_wait_for_dac(dev);
if (ret) {
dev_warn(dev->class_dev,
"%s: DAC not-ready for channel %i\n",
__func__, chan);
} else {
outl(val | APCI3501_AO_DATA_CHAN(chan),
dev->iobase + APCI3501_AO_DATA_REG);
}
}
return 0;
}
static int apci3501_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct apci3501_private *devpriv;
struct comedi_subdevice *s;
int ao_n_chan;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->amcc = pci_resource_start(pcidev, 0);
dev->iobase = pci_resource_start(pcidev, 1);
ao_n_chan = apci3501_eeprom_get_ao_n_chan(dev);
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
s = &dev->subdevices[0];
if (ao_n_chan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = ao_n_chan;
s->maxdata = 0x3fff;
s->range_table = &apci3501_ao_range;
s->insn_write = apci3501_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 2;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3501_di_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3501_do_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 256;
s->maxdata = 0xffff;
s->insn_read = apci3501_eeprom_insn_read;
apci3501_reset(dev);
return 0;
}
static void apci3501_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci3501_reset(dev);
comedi_pci_detach(dev);
}
static int apci3501_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci3501_driver, id->driver_data);
}
