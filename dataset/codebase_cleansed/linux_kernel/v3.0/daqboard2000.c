static void writeAcqScanListEntry(struct comedi_device *dev, u16 entry)
{
struct daqboard2000_hw *fpga = devpriv->daq;
fpga->acqScanListFIFO = entry & 0x00ff;
fpga->acqScanListFIFO = (entry >> 8) & 0x00ff;
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
static int daqboard2000_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
struct daqboard2000_hw *fpga = devpriv->daq;
int gain, chan, timeout;
fpga->acqControl =
DAQBOARD2000_AcqResetScanListFifo |
DAQBOARD2000_AcqResetResultsFifo | DAQBOARD2000_AcqResetConfigPipe;
fpga->acqPacerClockDivLow = 1000000;
fpga->acqPacerClockDivHigh = 0;
gain = CR_RANGE(insn->chanspec);
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
setup_sampling(dev, chan, gain);
fpga->acqControl = DAQBOARD2000_SeqStartScanList;
for (timeout = 0; timeout < 20; timeout++) {
if (fpga->acqControl & DAQBOARD2000_AcqConfigPipeFull) {
break;
}
}
fpga->acqControl = DAQBOARD2000_AdcPacerEnable;
for (timeout = 0; timeout < 20; timeout++) {
if (fpga->acqControl & DAQBOARD2000_AcqLogicScanning) {
break;
}
}
for (timeout = 0; timeout < 20; timeout++) {
if (fpga->acqControl &
DAQBOARD2000_AcqResultsFIFOHasValidData) {
break;
}
}
data[i] = fpga->acqResultsFIFO;
fpga->acqControl = DAQBOARD2000_AdcPacerDisable;
fpga->acqControl = DAQBOARD2000_SeqStopScanList;
}
return i;
}
static int daqboard2000_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
data[i] = devpriv->ao_readback[chan];
}
return i;
}
static int daqboard2000_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
struct daqboard2000_hw *fpga = devpriv->daq;
int timeout;
for (i = 0; i < insn->n; i++) {
fpga->dacSetting[chan] = data[i];
for (timeout = 0; timeout < 20; timeout++) {
if ((fpga->dacControl & ((chan + 1) * 0x0010)) == 0) {
break;
}
}
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static void daqboard2000_resetLocalBus(struct comedi_device *dev)
{
printk("daqboard2000_resetLocalBus\n");
writel(DAQBOARD2000_SECRLocalBusHi, devpriv->plx + 0x6c);
udelay(10000);
writel(DAQBOARD2000_SECRLocalBusLo, devpriv->plx + 0x6c);
udelay(10000);
}
static void daqboard2000_reloadPLX(struct comedi_device *dev)
{
printk("daqboard2000_reloadPLX\n");
writel(DAQBOARD2000_SECRReloadLo, devpriv->plx + 0x6c);
udelay(10000);
writel(DAQBOARD2000_SECRReloadHi, devpriv->plx + 0x6c);
udelay(10000);
writel(DAQBOARD2000_SECRReloadLo, devpriv->plx + 0x6c);
udelay(10000);
}
static void daqboard2000_pulseProgPin(struct comedi_device *dev)
{
printk("daqboard2000_pulseProgPin 1\n");
writel(DAQBOARD2000_SECRProgPinHi, devpriv->plx + 0x6c);
udelay(10000);
writel(DAQBOARD2000_SECRProgPinLo, devpriv->plx + 0x6c);
udelay(10000);
}
static int daqboard2000_pollCPLD(struct comedi_device *dev, int mask)
{
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
unsigned char *cpld_array, int len)
{
int result = -EIO;
int secr;
int retry;
int i;
secr = readl(devpriv->plx + 0x6c);
if (!(secr & DAQBOARD2000_EEPROM_PRESENT)) {
#ifdef DEBUG_EEPROM
printk("no serial eeprom\n");
#endif
return -EIO;
}
for (retry = 0; retry < 3; retry++) {
#ifdef DEBUG_EEPROM
printk("Programming EEPROM try %x\n", retry);
#endif
daqboard2000_resetLocalBus(dev);
daqboard2000_reloadPLX(dev);
daqboard2000_pulseProgPin(dev);
if (daqboard2000_pollCPLD(dev, DAQBOARD2000_CPLD_INIT)) {
for (i = 0; i < len; i++) {
if (cpld_array[i] == 0xff
&& cpld_array[i + 1] == 0x20) {
#ifdef DEBUG_EEPROM
printk("Preamble found at %d\n", i);
#endif
break;
}
}
for (; i < len; i += 2) {
int data =
(cpld_array[i] << 8) + cpld_array[i + 1];
if (!daqboard2000_writeCPLD(dev, data)) {
break;
}
}
if (i >= len) {
#ifdef DEBUG_EEPROM
printk("Programmed\n");
#endif
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
struct daqboard2000_hw *fpga = devpriv->daq;
udelay(2);
fpga->trigControl = DAQBOARD2000_TrigAnalog | DAQBOARD2000_TrigDisable;
udelay(2);
fpga->trigControl = DAQBOARD2000_TrigTTL | DAQBOARD2000_TrigDisable;
udelay(2);
fpga->acqControl = DAQBOARD2000_SeqStopScanList;
udelay(2);
fpga->acqControl = DAQBOARD2000_AdcPacerDisable;
daqboard2000_adcStopDmaTransfer(dev);
}
static void daqboard2000_activateReferenceDacs(struct comedi_device *dev)
{
struct daqboard2000_hw *fpga = devpriv->daq;
int timeout;
fpga->refDacs = 0x80 | DAQBOARD2000_PosRefDacSelect;
for (timeout = 0; timeout < 20; timeout++) {
if ((fpga->dacControl & DAQBOARD2000_RefBusy) == 0) {
break;
}
udelay(2);
}
fpga->refDacs = 0x80 | DAQBOARD2000_NegRefDacSelect;
for (timeout = 0; timeout < 20; timeout++) {
if ((fpga->dacControl & DAQBOARD2000_RefBusy) == 0) {
break;
}
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
int result = 0;
if (dir) {
writew(data, ((void *)ioaddr) + port * 2);
result = 0;
} else {
result = readw(((void *)ioaddr) + port * 2);
}
return result;
}
static int daqboard2000_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int result = 0;
struct comedi_subdevice *s;
struct pci_dev *card = NULL;
void *aux_data;
unsigned int aux_len;
int bus, slot;
printk("comedi%d: daqboard2000:", dev->minor);
bus = it->options[0];
slot = it->options[1];
result = alloc_private(dev, sizeof(struct daqboard2000_private));
if (result < 0) {
return -ENOMEM;
}
for (card = pci_get_device(0x1616, 0x0409, NULL);
card != NULL; card = pci_get_device(0x1616, 0x0409, card)) {
if (bus || slot) {
if (card->bus->number != bus ||
PCI_SLOT(card->devfn) != slot) {
continue;
}
}
break;
}
if (!card) {
if (bus || slot)
printk(" no daqboard2000 found at bus/slot: %d/%d\n",
bus, slot);
else
printk(" no daqboard2000 found\n");
return -EIO;
} else {
u32 id;
int i;
devpriv->pci_dev = card;
id = ((u32) card->
subsystem_device << 16) | card->subsystem_vendor;
for (i = 0; i < n_boardtypes; i++) {
if (boardtypes[i].id == id) {
printk(" %s", boardtypes[i].name);
dev->board_ptr = boardtypes + i;
}
}
if (!dev->board_ptr) {
printk
(" unknown subsystem id %08x (pretend it is an ids2)",
id);
dev->board_ptr = boardtypes;
}
}
result = comedi_pci_enable(card, "daqboard2000");
if (result < 0) {
printk(" failed to enable PCI device and request regions\n");
return -EIO;
}
devpriv->got_regions = 1;
devpriv->plx =
ioremap(pci_resource_start(card, 0), DAQBOARD2000_PLX_SIZE);
devpriv->daq =
ioremap(pci_resource_start(card, 2), DAQBOARD2000_DAQ_SIZE);
if (!devpriv->plx || !devpriv->daq) {
return -ENOMEM;
}
result = alloc_subdevices(dev, 3);
if (result < 0)
goto out;
readl(devpriv->plx + 0x6c);
aux_data = comedi_aux_data(it->options, 0);
aux_len = it->options[COMEDI_DEVCONF_AUX_DATA_LENGTH];
if (aux_data && aux_len) {
result = initialize_daqboard2000(dev, aux_data, aux_len);
} else {
printk("no FPGA initialization code, aborting\n");
result = -EIO;
}
if (result < 0)
goto out;
daqboard2000_initializeAdc(dev);
daqboard2000_initializeDac(dev);
dev->iobase = (unsigned long)devpriv->daq;
dev->board_name = this_board->name;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 24;
s->maxdata = 0xffff;
s->insn_read = daqboard2000_ai_insn_read;
s->range_table = &range_daqboard2000_ai;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xffff;
s->insn_read = daqboard2000_ao_insn_read;
s->insn_write = daqboard2000_ao_insn_write;
s->range_table = &range_daqboard2000_ao;
s = dev->subdevices + 2;
result = subdev_8255_init(dev, s, daqboard2000_8255_cb,
(unsigned long)(dev->iobase + 0x40));
printk("\n");
out:
return result;
}
static int daqboard2000_detach(struct comedi_device *dev)
{
printk("comedi%d: daqboard2000: remove\n", dev->minor);
if (dev->subdevices)
subdev_8255_cleanup(dev, dev->subdevices + 2);
if (dev->irq) {
free_irq(dev->irq, dev);
}
if (devpriv) {
if (devpriv->daq)
iounmap(devpriv->daq);
if (devpriv->plx)
iounmap(devpriv->plx);
if (devpriv->pci_dev) {
if (devpriv->got_regions) {
comedi_pci_disable(devpriv->pci_dev);
}
pci_dev_put(devpriv->pci_dev);
}
}
return 0;
}
static int __devinit driver_daqboard2000_pci_probe(struct pci_dev *dev,
const struct pci_device_id
*ent)
{
return comedi_pci_auto_config(dev, driver_daqboard2000.driver_name);
}
static void __devexit driver_daqboard2000_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_daqboard2000_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_daqboard2000);
if (retval < 0)
return retval;
driver_daqboard2000_pci_driver.name =
(char *)driver_daqboard2000.driver_name;
return pci_register_driver(&driver_daqboard2000_pci_driver);
}
static void __exit driver_daqboard2000_cleanup_module(void)
{
pci_unregister_driver(&driver_daqboard2000_pci_driver);
comedi_driver_unregister(&driver_daqboard2000);
}
