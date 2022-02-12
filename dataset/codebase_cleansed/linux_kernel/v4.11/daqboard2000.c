static void db2k_write_acq_scan_list_entry(struct comedi_device *dev, u16 entry)
{
writew(entry & 0x00ff, dev->mmio + DB2K_REG_ACQ_SCAN_LIST_FIFO);
writew((entry >> 8) & 0x00ff,
dev->mmio + DB2K_REG_ACQ_SCAN_LIST_FIFO);
}
static void db2k_setup_sampling(struct comedi_device *dev, int chan, int gain)
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
db2k_write_acq_scan_list_entry(dev, word0);
db2k_write_acq_scan_list_entry(dev, word1);
db2k_write_acq_scan_list_entry(dev, word2);
db2k_write_acq_scan_list_entry(dev, word3);
}
static int db2k_ai_status(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned long context)
{
unsigned int status;
status = readw(dev->mmio + DB2K_REG_ACQ_STATUS);
if (status & context)
return 0;
return -EBUSY;
}
static int db2k_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
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
db2k_setup_sampling(dev, chan, gain);
writew(DB2K_ACQ_CONTROL_SEQ_START_SCAN_LIST,
dev->mmio + DB2K_REG_ACQ_CONTROL);
ret = comedi_timeout(dev, s, insn, db2k_ai_status,
DB2K_ACQ_STATUS_CONFIG_PIPE_FULL);
if (ret)
return ret;
writew(DB2K_ACQ_CONTROL_ADC_PACER_ENABLE,
dev->mmio + DB2K_REG_ACQ_CONTROL);
ret = comedi_timeout(dev, s, insn, db2k_ai_status,
DB2K_ACQ_STATUS_LOGIC_SCANNING);
if (ret)
return ret;
ret =
comedi_timeout(dev, s, insn, db2k_ai_status,
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
static int db2k_ao_eoc(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned long context)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int status;
status = readw(dev->mmio + DB2K_REG_DAC_STATUS);
if ((status & DB2K_DAC_STATUS_DAC_BUSY(chan)) == 0)
return 0;
return -EBUSY;
}
static int db2k_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
int ret;
writew(val, dev->mmio + DB2K_REG_DAC_SETTING(chan));
ret = comedi_timeout(dev, s, insn, db2k_ao_eoc, 0);
if (ret)
return ret;
s->readback[chan] = val;
}
return insn->n;
}
static void db2k_reset_local_bus(struct comedi_device *dev)
{
struct db2k_private *devpriv = dev->private;
u32 cntrl;
cntrl = readl(devpriv->plx + PLX_REG_CNTRL);
cntrl |= PLX_CNTRL_RESET;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
cntrl &= ~PLX_CNTRL_RESET;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
}
static void db2k_reload_plx(struct comedi_device *dev)
{
struct db2k_private *devpriv = dev->private;
u32 cntrl;
cntrl = readl(devpriv->plx + PLX_REG_CNTRL);
cntrl &= ~PLX_CNTRL_EERELOAD;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
cntrl |= PLX_CNTRL_EERELOAD;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
cntrl &= ~PLX_CNTRL_EERELOAD;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
}
static void db2k_pulse_prog_pin(struct comedi_device *dev)
{
struct db2k_private *devpriv = dev->private;
u32 cntrl;
cntrl = readl(devpriv->plx + PLX_REG_CNTRL);
cntrl |= PLX_CNTRL_USERO;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
cntrl &= ~PLX_CNTRL_USERO;
writel(cntrl, devpriv->plx + PLX_REG_CNTRL);
mdelay(10);
}
static int db2k_wait_cpld_init(struct comedi_device *dev)
{
int result = -ETIMEDOUT;
int i;
u16 cpld;
for (i = 0; i < 50; i++) {
cpld = readw(dev->mmio + DB2K_REG_CPLD_STATUS);
if (cpld & DB2K_CPLD_STATUS_INIT) {
result = 0;
break;
}
usleep_range(100, 1000);
}
udelay(5);
return result;
}
static int db2k_wait_cpld_txready(struct comedi_device *dev)
{
int i;
for (i = 0; i < 100; i++) {
if (readw(dev->mmio + DB2K_REG_CPLD_STATUS) &
DB2K_CPLD_STATUS_TXREADY) {
return 0;
}
udelay(1);
}
return -ETIMEDOUT;
}
static int db2k_write_cpld(struct comedi_device *dev, u16 data, bool new_cpld)
{
int result = 0;
if (new_cpld) {
result = db2k_wait_cpld_txready(dev);
if (result)
return result;
} else {
usleep_range(10, 20);
}
writew(data, dev->mmio + DB2K_REG_CPLD_WDATA);
if (!(readw(dev->mmio + DB2K_REG_CPLD_STATUS) & DB2K_CPLD_STATUS_INIT))
result = -EIO;
return result;
}
static int db2k_wait_fpga_programmed(struct comedi_device *dev)
{
struct db2k_private *devpriv = dev->private;
int i;
for (i = 0; i < 200; i++) {
u32 cntrl = readl(devpriv->plx + PLX_REG_CNTRL);
if (cntrl & PLX_CNTRL_USERI)
return 0;
usleep_range(100, 1000);
}
return -ETIMEDOUT;
}
static int db2k_load_firmware(struct comedi_device *dev, const u8 *cpld_array,
size_t len, unsigned long context)
{
struct db2k_private *devpriv = dev->private;
int result = -EIO;
u32 cntrl;
int retry;
size_t i;
bool new_cpld;
for (i = 0; i + 1 < len; i++) {
if (cpld_array[i] == 0xff && cpld_array[i + 1] == 0x20)
break;
}
if (i + 1 >= len) {
dev_err(dev->class_dev, "bad firmware - no start sequence\n");
return -EINVAL;
}
if ((len - i) & 1) {
dev_err(dev->class_dev,
"bad firmware - odd length (%zu = %zu - %zu)\n",
len - i, len, i);
return -EINVAL;
}
cpld_array += i;
len -= i;
cntrl = readl(devpriv->plx + PLX_REG_CNTRL);
if (!(cntrl & PLX_CNTRL_EEPRESENT))
return -EIO;
for (retry = 0; retry < 3; retry++) {
db2k_reset_local_bus(dev);
db2k_reload_plx(dev);
db2k_pulse_prog_pin(dev);
result = db2k_wait_cpld_init(dev);
if (result)
continue;
new_cpld = (readw(dev->mmio + DB2K_REG_CPLD_STATUS) &
DB2K_CPLD_VERSION_MASK) == DB2K_CPLD_VERSION_NEW;
for (; i < len; i += 2) {
u16 data = (cpld_array[i] << 8) + cpld_array[i + 1];
result = db2k_write_cpld(dev, data, new_cpld);
if (result)
break;
}
if (result == 0)
result = db2k_wait_fpga_programmed(dev);
if (result == 0) {
db2k_reset_local_bus(dev);
db2k_reload_plx(dev);
break;
}
}
return result;
}
static void db2k_adc_stop_dma_transfer(struct comedi_device *dev)
{
}
static void db2k_adc_disarm(struct comedi_device *dev)
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
db2k_adc_stop_dma_transfer(dev);
}
static void db2k_activate_reference_dacs(struct comedi_device *dev)
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
static void db2k_initialize_ctrs(struct comedi_device *dev)
{
}
static void db2k_initialize_tmrs(struct comedi_device *dev)
{
}
static void db2k_dac_disarm(struct comedi_device *dev)
{
}
static void db2k_initialize_adc(struct comedi_device *dev)
{
db2k_adc_disarm(dev);
db2k_activate_reference_dacs(dev);
db2k_initialize_ctrs(dev);
db2k_initialize_tmrs(dev);
}
static void db2k_initialize_dac(struct comedi_device *dev)
{
db2k_dac_disarm(dev);
}
static int db2k_8255_cb(struct comedi_device *dev, int dir, int port, int data,
unsigned long iobase)
{
if (dir) {
writew(data, dev->mmio + iobase + port * 2);
return 0;
}
return readw(dev->mmio + iobase + port * 2);
}
static int db2k_auto_attach(struct comedi_device *dev, unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct db2k_boardtype *board;
struct db2k_private *devpriv;
struct comedi_subdevice *s;
int result;
if (context >= ARRAY_SIZE(db2k_boardtypes))
return -ENODEV;
board = &db2k_boardtypes[context];
if (!board->name)
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
result = comedi_load_firmware(dev, &comedi_to_pci_dev(dev)->dev,
DB2K_FIRMWARE, db2k_load_firmware, 0);
if (result < 0)
return result;
db2k_initialize_adc(dev);
db2k_initialize_dac(dev);
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 24;
s->maxdata = 0xffff;
s->insn_read = db2k_ai_insn_read;
s->range_table = &db2k_ai_range;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->has_2_ao ? 2 : 4;
s->maxdata = 0xffff;
s->insn_write = db2k_ao_insn_write;
s->range_table = &range_bipolar10;
result = comedi_alloc_subdev_readback(s);
if (result)
return result;
s = &dev->subdevices[2];
return subdev_8255_init(dev, s, db2k_8255_cb,
DB2K_REG_DIO_P2_EXP_IO_8_BIT);
}
static void db2k_detach(struct comedi_device *dev)
{
struct db2k_private *devpriv = dev->private;
if (devpriv && devpriv->plx)
iounmap(devpriv->plx);
comedi_pci_detach(dev);
}
static int db2k_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &db2k_driver, id->driver_data);
}
