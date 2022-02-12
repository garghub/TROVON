static void writeAcqScanListEntry(struct comedi_device *dev, u16 entry)
{
struct daqboard2000_private *devpriv = dev->private;
writew(entry & 0x00ff, devpriv->daq + acqScanListFIFO);
writew((entry >> 8) & 0x00ff, devpriv->daq + acqScanListFIFO);
}
static void setup_sampling(struct comedi_device *dev, int chan, int gain)
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
writeAcqScanListEntry(dev, word0);
writeAcqScanListEntry(dev, word1);
writeAcqScanListEntry(dev, word2);
writeAcqScanListEntry(dev, word3);
}
static int daqboard2000_ai_status(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct daqboard2000_private *devpriv = dev->private;
unsigned int status;
status = readw(devpriv->daq + acqControl);
if (status & context)
return 0;
return -EBUSY;
}
static int daqboard2000_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqboard2000_private *devpriv = dev->private;
int gain, chan;
int ret;
int i;
writew(DAQBOARD2000_AcqResetScanListFifo |
DAQBOARD2000_AcqResetResultsFifo |
DAQBOARD2000_AcqResetConfigPipe, devpriv->daq + acqControl);
writel(1000000, devpriv->daq + acqPacerClockDivLow);
writew(0, devpriv->daq + acqPacerClockDivHigh);
gain = CR_RANGE(insn->chanspec);
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
setup_sampling(dev, chan, gain);
writew(DAQBOARD2000_SeqStartScanList,
devpriv->daq + acqControl);
ret = comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DAQBOARD2000_AcqConfigPipeFull);
if (ret)
return ret;
writew(DAQBOARD2000_AdcPacerEnable, devpriv->daq + acqControl);
ret = comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DAQBOARD2000_AcqLogicScanning);
if (ret)
return ret;
ret = comedi_timeout(dev, s, insn, daqboard2000_ai_status,
DAQBOARD2000_AcqResultsFIFOHasValidData);
if (ret)
return ret;
data[i] = readw(devpriv->daq + acqResultsFIFO);
writew(DAQBOARD2000_AdcPacerDisable, devpriv->daq + acqControl);
writew(DAQBOARD2000_SeqStopScanList, devpriv->daq + acqControl);
}
return i;
}
static int daqboard2000_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqboard2000_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int daqboard2000_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct daqboard2000_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int status;
status = readw(devpriv->daq + dacControl);
if ((status & ((chan + 1) * 0x0010)) == 0)
return 0;
return -EBUSY;
}
static int daqboard2000_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct daqboard2000_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int ret;
int i;
for (i = 0; i < insn->n; i++) {
#if 0
writew((chan + 2) * 0x0010 | 0x0001,
devpriv->daq + dacControl);
udelay(1000);
#endif
writew(data[i], devpriv->daq + dacSetting(chan));
ret = comedi_timeout(dev, s, insn, daqboard2000_ao_eoc, 0);
if (ret)
return ret;
devpriv->ao_readback[chan] = data[i];
#if 0
writew((chan + 2) * 0x0010 | 0x0000,
devpriv->daq + dacControl);
udelay(1000);
#endif
}
return i;
}
static void daqboard2000_resetLocalBus(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DAQBOARD2000_SECRLocalBusHi, devpriv->plx + 0x6c);
mdelay(10);
writel(DAQBOARD2000_SECRLocalBusLo, devpriv->plx + 0x6c);
mdelay(10);
}
static void daqboard2000_reloadPLX(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DAQBOARD2000_SECRReloadLo, devpriv->plx + 0x6c);
mdelay(10);
writel(DAQBOARD2000_SECRReloadHi, devpriv->plx + 0x6c);
mdelay(10);
writel(DAQBOARD2000_SECRReloadLo, devpriv->plx + 0x6c);
mdelay(10);
}
static void daqboard2000_pulseProgPin(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
writel(DAQBOARD2000_SECRProgPinHi, devpriv->plx + 0x6c);
mdelay(10);
writel(DAQBOARD2000_SECRProgPinLo, devpriv->plx + 0x6c);
mdelay(10);
}
static int daqboard2000_pollCPLD(struct comedi_device *dev, int mask)
{
struct daqboard2000_private *devpriv = dev->private;
int result = 0;
int i;
int cpld;
for (i = 0; i < 50; i++) {
cpld = readw(devpriv->daq + 0x1000);
if ((cpld & mask) == mask) {
result = 1;
break;
}
udelay(100);
}
udelay(5);
return result;
}
static int daqboard2000_writeCPLD(struct comedi_device *dev, int data)
{
struct daqboard2000_private *devpriv = dev->private;
int result = 0;
udelay(10);
writew(data, devpriv->daq + 0x1000);
if ((readw(devpriv->daq + 0x1000) & DAQBOARD2000_CPLD_INIT) ==
DAQBOARD2000_CPLD_INIT) {
result = 1;
}
return result;
}
static int initialize_daqboard2000(struct comedi_device *dev,
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
daqboard2000_resetLocalBus(dev);
daqboard2000_reloadPLX(dev);
daqboard2000_pulseProgPin(dev);
if (daqboard2000_pollCPLD(dev, DAQBOARD2000_CPLD_INIT)) {
for (i = 0; i < len; i++) {
if (cpld_array[i] == 0xff &&
cpld_array[i + 1] == 0x20)
break;
}
for (; i < len; i += 2) {
int data =
(cpld_array[i] << 8) + cpld_array[i + 1];
if (!daqboard2000_writeCPLD(dev, data))
break;
}
if (i >= len) {
daqboard2000_resetLocalBus(dev);
daqboard2000_reloadPLX(dev);
result = 0;
break;
}
}
}
return result;
}
static void daqboard2000_adcStopDmaTransfer(struct comedi_device *dev)
{
}
static void daqboard2000_adcDisarm(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
udelay(2);
writew(DAQBOARD2000_TrigAnalog | DAQBOARD2000_TrigDisable,
devpriv->daq + trigControl);
udelay(2);
writew(DAQBOARD2000_TrigTTL | DAQBOARD2000_TrigDisable,
devpriv->daq + trigControl);
udelay(2);
writew(DAQBOARD2000_SeqStopScanList, devpriv->daq + acqControl);
udelay(2);
writew(DAQBOARD2000_AdcPacerDisable, devpriv->daq + acqControl);
daqboard2000_adcStopDmaTransfer(dev);
}
static void daqboard2000_activateReferenceDacs(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
unsigned int val;
int timeout;
writew(0x80 | DAQBOARD2000_PosRefDacSelect, devpriv->daq + refDacs);
for (timeout = 0; timeout < 20; timeout++) {
val = readw(devpriv->daq + dacControl);
if ((val & DAQBOARD2000_RefBusy) == 0)
break;
udelay(2);
}
writew(0x80 | DAQBOARD2000_NegRefDacSelect, devpriv->daq + refDacs);
for (timeout = 0; timeout < 20; timeout++) {
val = readw(devpriv->daq + dacControl);
if ((val & DAQBOARD2000_RefBusy) == 0)
break;
udelay(2);
}
}
static void daqboard2000_initializeCtrs(struct comedi_device *dev)
{
}
static void daqboard2000_initializeTmrs(struct comedi_device *dev)
{
}
static void daqboard2000_dacDisarm(struct comedi_device *dev)
{
}
static void daqboard2000_initializeAdc(struct comedi_device *dev)
{
daqboard2000_adcDisarm(dev);
daqboard2000_activateReferenceDacs(dev);
daqboard2000_initializeCtrs(dev);
daqboard2000_initializeTmrs(dev);
}
static void daqboard2000_initializeDac(struct comedi_device *dev)
{
daqboard2000_dacDisarm(dev);
}
static int daqboard2000_8255_cb(int dir, int port, int data,
unsigned long ioaddr)
{
void __iomem *mmio_base = (void __iomem *)ioaddr;
if (dir) {
writew(data, mmio_base + port * 2);
return 0;
} else {
return readw(mmio_base + port * 2);
}
}
static const void *daqboard2000_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct daq200_boardtype *board;
int i;
if (pcidev->subsystem_device != PCI_VENDOR_ID_IOTECH)
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
devpriv->daq = pci_ioremap_bar(pcidev, 2);
if (!devpriv->plx || !devpriv->daq)
return -ENOMEM;
result = comedi_alloc_subdevices(dev, 3);
if (result)
return result;
readl(devpriv->plx + 0x6c);
result = comedi_load_firmware(dev, &comedi_to_pci_dev(dev)->dev,
DAQBOARD2000_FIRMWARE,
initialize_daqboard2000, 0);
if (result < 0)
return result;
daqboard2000_initializeAdc(dev);
daqboard2000_initializeDac(dev);
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
s->insn_read = daqboard2000_ao_insn_read;
s->insn_write = daqboard2000_ao_insn_write;
s->range_table = &range_bipolar10;
s = &dev->subdevices[2];
result = subdev_8255_init(dev, s, daqboard2000_8255_cb,
(unsigned long)(devpriv->daq + dioP2ExpansionIO8Bit));
if (result)
return result;
return 0;
}
static void daqboard2000_detach(struct comedi_device *dev)
{
struct daqboard2000_private *devpriv = dev->private;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->daq)
iounmap(devpriv->daq);
if (devpriv->plx)
iounmap(devpriv->plx);
}
comedi_pci_disable(dev);
}
static int daqboard2000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &daqboard2000_driver,
id->driver_data);
}
