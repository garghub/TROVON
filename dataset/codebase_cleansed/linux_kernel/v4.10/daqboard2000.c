static void daqboard2000_write_acq_scan_list_entry(struct comedi_device *dev,
u16 entry)
{
writew(entry & 0x00ff, dev->mmio + DB2K_REG_ACQ_SCAN_LIST_FIFO);
writew((entry >> 8) & 0x00ff,
dev->mmio + DB2K_REG_ACQ_SCAN_LIST_FIFO);
}
static void daqboard2000_setup_sampling(struct comedi_device *dev, int chan,
int gain)
{
u16 word0, word1, word2, word3;
word0 = 0;
word1 = 0x0004;
word2 = (chan << 6) & 0x00c0;
switch (chan / 4) {
case 0:
word3 = 0x0001;
break;
case 1:
word3 = 0x0002;
break;
case 2:
word3 = 0x0005;
break;
case 3:
word3 = 0x0006;
break;
case 4:
word3 = 0x0041;
break;
case 5:
word3 = 0x0042;
break;
default:
word3 = 0;
break;
}
word2 |= 0x0800;
word3 |= 0xc000;
daqboard2000_write_acq_scan_list_entry(dev, word0);
daqboard2000_write_acq_scan_list_entry(dev, word1);
daqboard2000_write_acq_scan_list_entry(dev, word2);
daqboard2000_write_acq_scan_list_entry(dev, word3);
}
static int daqboard2000_ai_status(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readw(dev->mmio + DB2K_REG_ACQ_STATUS);
if (status & context)
return 0;
return -EBUSY;
}
static int daqboard2000_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int gain, chan;
int ret;
int i;
writew(DB2K_ACQ_CONTROL_RESET_SCAN_LIST_FIFO |
DB2K_ACQ_CONTROL_RESET_RESULTS_FIFO |
DB2K_ACQ_CONTROL_RESET_CONFIG_PIPE,
dev->mmio + DB2K_REG_ACQ_CONTROL);
writel(1000000, dev->mmio + DB2K_REG_ACQ_PACER_CLOCK_DIV_LOW);
writew(0, dev->mmio + DB2K_REG_ACQ_PACER_CLOCK_DIV_HIGH);
gain = CR_RANGE(insn->chanspec);
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
daqboard2000_setup_sampling(dev, chan, gain);
writew(DB2K_ACQ_CONTROL_SEQ_START_SCAN_LIST,
dev->mmio + DB2K_REG_ACQ_CONTROL);
ret = comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DB2K_ACQ_STATUS_CONFIG_PIPE_FULL);
if (ret)
return ret;
writew(DB2K_ACQ_CONTROL_ADC_PACER_ENABLE,
dev->mmio + DB2K_REG_ACQ_CONTROL);
ret = comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DB2K_ACQ_STATUS_LOGIC_SCANNING);
if (ret)
return ret;
ret =
comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DB2K_ACQ_STATUS_RESULTS_FIFO_HAS_DATA);
if (ret)
return ret;
data[i] = readw(dev->mmio + DB2K_REG_ACQ_RESULTS_FIFO);
writew(DB2K_ACQ_CONTROL_ADC_PACER_DISABLE,
dev->mmio + DB2K_REG_ACQ_CONTROL);
writew(DB2K_ACQ_CONTROL_SEQ_STOP_SCAN_LIST,
dev->mmio + DB2K_REG_ACQ_CONTROL);
}
return i;
}
static int daqboard2000_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int status;
status = readw(dev->mmio + DB2K_REG_DAC_STATUS);
if ((status & DB2K_DAC_STATUS_DAC_BUSY(chan)) == 0)
return 0;
return -EBUSY;
}
static int daqboard2000_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
int ret;
writew(val, dev->mmio + DB2K_REG_DAC_SETTING(chan));
ret = comedi_timeout(dev, s, insn, daqboard2000_ao_eoc, 0);
if (ret)
return ret;
s->readback[chan] = val;
}
return insn->n;
}
static void daqboard2000_reset_local_bus(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DB2K_SECR_LOCAL_BUS_HI, devpriv->plx + 0x6c);
mdelay(10);
writel(DB2K_SECR_LOCAL_BUS_LO, devpriv->plx + 0x6c);
mdelay(10);
}
static void daqboard2000_reload_plx(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DB2K_SECR_RELOAD_LO, devpriv->plx + 0x6c);
mdelay(10);
writel(DB2K_SECR_RELOAD_HI, devpriv->plx + 0x6c);
mdelay(10);
writel(DB2K_SECR_RELOAD_LO, devpriv->plx + 0x6c);
mdelay(10);
}
static void daqboard2000_pulse_prog_pin(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DB2K_SECR_PROG_PIN_HI, devpriv->plx + 0x6c);
mdelay(10);
writel(DB2K_SECR_PROG_PIN_LO, devpriv->plx + 0x6c);
mdelay(10);
}
static int daqboard2000_poll_cpld(struct comedi_device *dev, int mask)
{
int result = 0;
int i;
int cpld;
for (i = 0; i < 50; i++) {
cpld = readw(dev->mmio + 0x1000);
if ((cpld & mask) == mask) {
result = 1;
break;
}
usleep_range(100, 1000);
}
udelay(5);
return result;
}
static int daqboard2000_write_cpld(struct comedi_device *dev, int data)
{
int result = 0;
usleep_range(10, 20);
writew(data, dev->mmio + 0x1000);
if ((readw(dev->mmio + 0x1000) & DAQBOARD2000_CPLD_INIT) ==
DAQBOARD2000_CPLD_INIT) {
result = 1;
}
return result;
}
static int daqboard2000_load_firmware(struct comedi_device *dev,
const u8 *cpld_array, size_t len,
unsigned long context)
{
struct daqboard2000_private *devpriv = dev->private;
int result = -EIO;
int secr;
int retry;
size_t i;
secr = readl(devpriv->plx + 0x6c);
if (!(secr & DAQBOARD2000_EEPROM_PRESENT))
return -EIO;
for (retry = 0; retry < 3; retry++) {
daqboard2000_reset_local_bus(dev);
daqboard2000_reload_plx(dev);
daqboard2000_pulse_prog_pin(dev);
if (daqboard2000_poll_cpld(dev, DAQBOARD2000_CPLD_INIT)) {
for (i = 0; i < len; i++) {
if (cpld_array[i] == 0xff &&
cpld_array[i + 1] == 0x20)
break;
}
for (; i < len; i += 2) {
int data =
(cpld_array[i] << 8) + cpld_array[i + 1];
if (!daqboard2000_write_cpld(dev, data))
break;
}
if (i >= len) {
daqboard2000_reset_local_bus(dev);
daqboard2000_reload_plx(dev);
result = 0;
break;
}
}
}
return result;
}
static void daqboard2000_adc_stop_dma_transfer(struct comedi_device *dev)
{
}
static void daqboard2000_adc_disarm(struct comedi_device *dev)
{
udelay(2);
writew(DB2K_TRIG_CONTROL_TYPE_ANALOG | DB2K_TRIG_CONTROL_DISABLE,
dev->mmio + DB2K_REG_TRIG_CONTROL);
udelay(2);
writew(DB2K_TRIG_CONTROL_TYPE_TTL | DB2K_TRIG_CONTROL_DISABLE,
dev->mmio + DB2K_REG_TRIG_CONTROL);
udelay(2);
writew(DB2K_ACQ_CONTROL_SEQ_STOP_SCAN_LIST,
dev->mmio + DB2K_REG_ACQ_CONTROL);
udelay(2);
writew(DB2K_ACQ_CONTROL_ADC_PACER_DISABLE,
dev->mmio + DB2K_REG_ACQ_CONTROL);
daqboard2000_adc_stop_dma_transfer(dev);
}
static void daqboard2000_activate_reference_dacs(struct comedi_device *dev)
{
unsigned int val;
int timeout;
writew(DB2K_REF_DACS_SET | DB2K_REF_DACS_SELECT_POS_REF,
dev->mmio + DB2K_REG_REF_DACS);
for (timeout = 0; timeout < 20; timeout++) {
val = readw(dev->mmio + DB2K_REG_DAC_STATUS);
if ((val & DB2K_DAC_STATUS_REF_BUSY) == 0)
break;
udelay(2);
}
writew(DB2K_REF_DACS_SET | DB2K_REF_DACS_SELECT_NEG_REF,
dev->mmio + DB2K_REG_REF_DACS);
for (timeout = 0; timeout < 20; timeout++) {
val = readw(dev->mmio + DB2K_REG_DAC_STATUS);
if ((val & DB2K_DAC_STATUS_REF_BUSY) == 0)
break;
udelay(2);
}
}
static void daqboard2000_initialize_ctrs(struct comedi_device *dev)
{
}
static void daqboard2000_initialize_tmrs(struct comedi_device *dev)
{
}
static void daqboard2000_dac_disarm(struct comedi_device *dev)
{
}
static void daqboard2000_initialize_adc(struct comedi_device *dev)
{
daqboard2000_adc_disarm(dev);
daqboard2000_activate_reference_dacs(dev);
daqboard2000_initialize_ctrs(dev);
daqboard2000_initialize_tmrs(dev);
}
static void daqboard2000_initialize_dac(struct comedi_device *dev)
{
daqboard2000_dac_disarm(dev);
}
static int daqboard2000_8255_cb(struct comedi_device *dev,
int dir, int port, int data,
unsigned long iobase)
{
if (dir) {
writew(data, dev->mmio + iobase + port * 2);
return 0;
}
return readw(dev->mmio + iobase + port * 2);
}
static const void *daqboard2000_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct daq200_boardtype *board;
int i;
if (pcidev->subsystem_vendor != PCI_VENDOR_ID_IOTECH)
return NULL;
for (i = 0; i < ARRAY_SIZE(boardtypes); i++) {
board = &boardtypes[i];
if (pcidev->subsystem_device == board->id)
return board;
}
return NULL;
}
static int daqboard2000_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct daq200_boardtype *board;
struct daqboard2000_private *devpriv;
struct comedi_subdevice *s;
int result;
board = daqboard2000_find_boardinfo(dev, pcidev);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
result = comedi_pci_enable(dev);
if (result)
return result;
devpriv->plx = pci_ioremap_bar(pcidev, 0);
dev->mmio = pci_ioremap_bar(pcidev, 2);
if (!devpriv->plx || !dev->mmio)
return -ENOMEM;
result = comedi_alloc_subdevices(dev, 3);
if (result)
return result;
readl(devpriv->plx + 0x6c);
result = comedi_load_firmware(dev, &comedi_to_pci_dev(dev)->dev,
DAQBOARD2000_FIRMWARE,
daqboard2000_load_firmware, 0);
if (result < 0)
return result;
daqboard2000_initialize_adc(dev);
daqboard2000_initialize_dac(dev);
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 24;
s->maxdata = 0xffff;
s->insn_read = daqboard2000_ai_insn_read;
s->range_table = &range_daqboard2000_ai;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xffff;
s->insn_write = daqboard2000_ao_insn_write;
s->range_table = &range_bipolar10;
result = comedi_alloc_subdev_readback(s);
if (result)
return result;
s = &dev->subdevices[2];
return subdev_8255_init(dev, s, daqboard2000_8255_cb,
DB2K_REG_DIO_P2_EXP_IO_8_BIT);
}
static void daqboard2000_detach(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
if (devpriv && devpriv->plx)
iounmap(devpriv->plx);
comedi_pci_detach(dev);
}
static int daqboard2000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &daqboard2000_driver,
id->driver_data);
}
