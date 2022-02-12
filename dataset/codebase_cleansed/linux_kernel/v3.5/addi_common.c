void fpu_begin(void)
{
kernel_fpu_begin();
}
void fpu_end(void)
{
kernel_fpu_end();
}
static int __devinit driver_addi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &driver_addi);
}
static void __devexit driver_addi_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_addi_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_addi);
if (retval < 0)
return retval;
driver_addi_pci_driver.name = (char *)driver_addi.driver_name;
return pci_register_driver(&driver_addi_pci_driver);
}
static void __exit driver_addi_cleanup_module(void)
{
pci_unregister_driver(&driver_addi_pci_driver);
comedi_driver_unregister(&driver_addi);
}
static int i_ADDI_Attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret, pages, i, n_subdevices;
unsigned int dw_Dummy;
resource_size_t io_addr[5];
unsigned int irq;
resource_size_t iobase_a, iobase_main, iobase_addon, iobase_reserved;
struct pcilst_struct *card = NULL;
unsigned char pci_bus, pci_slot, pci_func;
int i_Dma = 0;
ret = alloc_private(dev, sizeof(struct addi_private));
if (ret < 0)
return -ENOMEM;
if (!pci_list_builded) {
v_pci_card_list_init(this_board->i_VendorId, 1);
pci_list_builded = 1;
}
if ((this_board->i_Dma) && (it->options[2] == 0)) {
i_Dma = 1;
}
card = ptr_select_and_alloc_pci_card(this_board->i_VendorId,
this_board->i_DeviceId,
it->options[0],
it->options[1], i_Dma);
if (card == NULL)
return -EIO;
devpriv->allocated = 1;
if ((i_pci_card_data(card, &pci_bus, &pci_slot, &pci_func, &io_addr[0],
&irq)) < 0) {
i_pci_card_free(card);
printk(" - Can't get AMCC data!\n");
return -EIO;
}
iobase_a = io_addr[0];
iobase_main = io_addr[1];
iobase_addon = io_addr[2];
iobase_reserved = io_addr[3];
printk("\nBus %d: Slot %d: Funct%d\nBase0: 0x%8llx\nBase1: 0x%8llx\nBase2: 0x%8llx\nBase3: 0x%8llx\n", pci_bus, pci_slot, pci_func, (unsigned long long)io_addr[0], (unsigned long long)io_addr[1], (unsigned long long)io_addr[2], (unsigned long long)io_addr[3]);
if ((this_board->pc_EepromChip == NULL)
|| (strcmp(this_board->pc_EepromChip, ADDIDATA_9054) != 0)) {
if (this_board->i_IorangeBase1 != 0) {
dev->iobase = (unsigned long)iobase_main;
} else {
dev->iobase = (unsigned long)iobase_a;
}
dev->board_name = this_board->pc_DriverName;
devpriv->amcc = card;
devpriv->iobase = (int) dev->iobase;
devpriv->i_IobaseAmcc = (int) iobase_a;
devpriv->i_IobaseAddon = (int) iobase_addon;
devpriv->i_IobaseReserved = (int) iobase_reserved;
} else {
dev->board_name = this_board->pc_DriverName;
dev->iobase = (unsigned long)io_addr[2];
devpriv->amcc = card;
devpriv->iobase = (int) io_addr[2];
devpriv->i_IobaseReserved = (int) io_addr[3];
printk("\nioremap begin");
devpriv->dw_AiBase = ioremap(io_addr[3],
this_board->i_IorangeBase3);
printk("\nioremap end");
}
devpriv->s_EeParameters.i_NbrAiChannel = this_board->i_NbrAiChannel;
devpriv->s_EeParameters.i_NbrAoChannel = this_board->i_NbrAoChannel;
devpriv->s_EeParameters.i_AiMaxdata = this_board->i_AiMaxdata;
devpriv->s_EeParameters.i_AoMaxdata = this_board->i_AoMaxdata;
devpriv->s_EeParameters.i_NbrDiChannel = this_board->i_NbrDiChannel;
devpriv->s_EeParameters.i_NbrDoChannel = this_board->i_NbrDoChannel;
devpriv->s_EeParameters.i_DoMaxdata = this_board->i_DoMaxdata;
devpriv->s_EeParameters.i_Dma = this_board->i_Dma;
devpriv->s_EeParameters.i_Timer = this_board->i_Timer;
devpriv->s_EeParameters.ui_MinAcquisitiontimeNs =
this_board->ui_MinAcquisitiontimeNs;
devpriv->s_EeParameters.ui_MinDelaytimeNs =
this_board->ui_MinDelaytimeNs;
if (irq > 0) {
if (request_irq(irq, v_ADDI_Interrupt, IRQF_SHARED,
this_board->pc_DriverName, dev) < 0) {
printk(", unable to allocate IRQ %u, DISABLING IT",
irq);
irq = 0;
} else {
printk("\nirq=%u", irq);
}
} else {
printk(", IRQ disabled");
}
printk("\nOption %d %d %d\n", it->options[0], it->options[1],
it->options[2]);
dev->irq = irq;
if (this_board->i_PCIEeprom) {
printk("\nPCI Eeprom used");
if (!(strcmp(this_board->pc_EepromChip, "S5920"))) {
if (!(strcmp(this_board->pc_DriverName, "apci035"))) {
outl(0x80808082, devpriv->i_IobaseAmcc + 0x60);
} else {
outl(0x83838383, devpriv->i_IobaseAmcc + 0x60);
}
dw_Dummy = inl(devpriv->i_IobaseAmcc + 0x38);
outl(dw_Dummy | 0x2000, devpriv->i_IobaseAmcc + 0x38);
printk("\nEnable the interrupt for the controller");
}
printk("\nRead Eeprom");
i_EepromReadMainHeader(io_addr[0], this_board->pc_EepromChip,
dev);
} else {
printk("\nPCI Eeprom unused");
}
if (it->options[2] > 0) {
devpriv->us_UseDma = ADDI_DISABLE;
} else {
devpriv->us_UseDma = ADDI_ENABLE;
}
if (devpriv->s_EeParameters.i_Dma) {
printk("\nDMA used");
if (devpriv->us_UseDma == ADDI_ENABLE) {
devpriv->b_DmaDoubleBuffer = 0;
for (i = 0; i < 2; i++) {
for (pages = 4; pages >= 0; pages--) {
devpriv->ul_DmaBufferVirtual[i] =
(void *) __get_free_pages(GFP_KERNEL, pages);
if (devpriv->ul_DmaBufferVirtual[i])
break;
}
if (devpriv->ul_DmaBufferVirtual[i]) {
devpriv->ui_DmaBufferPages[i] = pages;
devpriv->ui_DmaBufferSize[i] =
PAGE_SIZE * pages;
devpriv->ui_DmaBufferSamples[i] =
devpriv->
ui_DmaBufferSize[i] >> 1;
devpriv->ul_DmaBufferHw[i] =
virt_to_bus((void *)devpriv->
ul_DmaBufferVirtual[i]);
}
}
if (!devpriv->ul_DmaBufferVirtual[0]) {
printk
(", Can't allocate DMA buffer, DMA disabled!");
devpriv->us_UseDma = ADDI_DISABLE;
}
if (devpriv->ul_DmaBufferVirtual[1]) {
devpriv->b_DmaDoubleBuffer = 1;
}
}
if ((devpriv->us_UseDma == ADDI_ENABLE)) {
printk("\nDMA ENABLED\n");
} else {
printk("\nDMA DISABLED\n");
}
}
if (!strcmp(this_board->pc_DriverName, "apci1710")) {
#ifdef CONFIG_APCI_1710
i_ADDI_AttachPCI1710(dev);
devpriv->s_BoardInfos.ui_Address = io_addr[2];
#endif
} else {
n_subdevices = 7;
ret = alloc_subdevices(dev, n_subdevices);
if (ret < 0)
return ret;
s = dev->subdevices + 0;
if ((devpriv->s_EeParameters.i_NbrAiChannel)
|| (this_board->i_NbrAiChannelDiff)) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags =
SDF_READABLE | SDF_COMMON | SDF_GROUND
| SDF_DIFF;
if (devpriv->s_EeParameters.i_NbrAiChannel) {
s->n_chan =
devpriv->s_EeParameters.i_NbrAiChannel;
devpriv->b_SingelDiff = 0;
} else {
s->n_chan = this_board->i_NbrAiChannelDiff;
devpriv->b_SingelDiff = 1;
}
s->maxdata = devpriv->s_EeParameters.i_AiMaxdata;
s->len_chanlist = this_board->i_AiChannelList;
s->range_table = this_board->pr_AiRangelist;
devpriv->b_AiInitialisation = 1;
s->insn_config = this_board->ai_config;
s->insn_read = this_board->ai_read;
s->insn_write = this_board->ai_write;
s->insn_bits = this_board->ai_bits;
s->do_cmdtest = this_board->ai_cmdtest;
s->do_cmd = this_board->ai_cmd;
s->cancel = this_board->ai_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 1;
if (devpriv->s_EeParameters.i_NbrAoChannel) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = devpriv->s_EeParameters.i_NbrAoChannel;
s->maxdata = devpriv->s_EeParameters.i_AoMaxdata;
s->len_chanlist =
devpriv->s_EeParameters.i_NbrAoChannel;
s->range_table = this_board->pr_AoRangelist;
s->insn_config = this_board->ao_config;
s->insn_write = this_board->ao_write;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 2;
if (devpriv->s_EeParameters.i_NbrDiChannel) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = devpriv->s_EeParameters.i_NbrDiChannel;
s->maxdata = 1;
s->len_chanlist =
devpriv->s_EeParameters.i_NbrDiChannel;
s->range_table = &range_digital;
s->io_bits = 0;
s->insn_config = this_board->di_config;
s->insn_read = this_board->di_read;
s->insn_write = this_board->di_write;
s->insn_bits = this_board->di_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 3;
if (devpriv->s_EeParameters.i_NbrDoChannel) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags =
SDF_READABLE | SDF_WRITEABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = devpriv->s_EeParameters.i_NbrDoChannel;
s->maxdata = devpriv->s_EeParameters.i_DoMaxdata;
s->len_chanlist =
devpriv->s_EeParameters.i_NbrDoChannel;
s->range_table = &range_digital;
s->io_bits = 0xf;
s->insn_config = this_board->do_config;
s->insn_write = this_board->do_write;
s->insn_bits = this_board->do_bits;
s->insn_read = this_board->do_read;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 4;
if (devpriv->s_EeParameters.i_Timer) {
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 1;
s->maxdata = 0;
s->len_chanlist = 1;
s->range_table = &range_digital;
s->insn_write = this_board->timer_write;
s->insn_read = this_board->timer_read;
s->insn_config = this_board->timer_config;
s->insn_bits = this_board->timer_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 5;
if (this_board->i_NbrTTLChannel) {
s->type = COMEDI_SUBD_TTLIO;
s->subdev_flags =
SDF_WRITEABLE | SDF_READABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = this_board->i_NbrTTLChannel;
s->maxdata = 1;
s->io_bits = 0;
s->len_chanlist = this_board->i_NbrTTLChannel;
s->range_table = &range_digital;
s->insn_config = this_board->ttl_config;
s->insn_bits = this_board->ttl_bits;
s->insn_read = this_board->ttl_read;
s->insn_write = this_board->ttl_write;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 6;
if (this_board->i_PCIEeprom) {
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 256;
s->maxdata = 0xffff;
s->insn_read = i_ADDIDATA_InsnReadEeprom;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
}
printk("\ni_ADDI_Attach end\n");
i_ADDI_Reset(dev);
devpriv->b_ValidDriver = 1;
return 0;
}
static void i_ADDI_Detach(struct comedi_device *dev)
{
if (dev->private) {
if (devpriv->b_ValidDriver)
i_ADDI_Reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if ((this_board->pc_EepromChip == NULL) ||
(strcmp(this_board->pc_EepromChip, ADDIDATA_9054) != 0)) {
if (devpriv->allocated)
i_pci_card_free(devpriv->amcc);
if (devpriv->ul_DmaBufferVirtual[0]) {
free_pages((unsigned long)devpriv->
ul_DmaBufferVirtual[0],
devpriv->ui_DmaBufferPages[0]);
}
if (devpriv->ul_DmaBufferVirtual[1]) {
free_pages((unsigned long)devpriv->
ul_DmaBufferVirtual[1],
devpriv->ui_DmaBufferPages[1]);
}
} else {
iounmap(devpriv->dw_AiBase);
if (devpriv->allocated)
i_pci_card_free(devpriv->amcc);
}
if (pci_list_builded) {
v_pci_card_list_cleanup(this_board->i_VendorId);
pci_list_builded = 0;
}
}
}
static int i_ADDI_Reset(struct comedi_device *dev)
{
this_board->reset(dev);
return 0;
}
static irqreturn_t v_ADDI_Interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
this_board->interrupt(irq, d);
return IRQ_RETVAL(1);
}
static int i_ADDIDATA_InsnReadEeprom(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned short w_Data;
unsigned short w_Address;
w_Address = CR_CHAN(insn->chanspec);
w_Data = w_EepromReadWord(devpriv->i_IobaseAmcc,
this_board->pc_EepromChip, 0x100 + (2 * w_Address));
data[0] = w_Data;
return insn->n;
}
