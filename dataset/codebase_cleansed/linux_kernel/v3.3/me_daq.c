static int __devinit me_driver_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, me_driver.driver_name);
}
static void __devexit me_driver_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init me_driver_init_module(void)
{
int retval;
retval = comedi_driver_register(&me_driver);
if (retval < 0)
return retval;
me_driver_pci_driver.name = (char *)me_driver.driver_name;
return pci_register_driver(&me_driver_pci_driver);
}
static void __exit me_driver_cleanup_module(void)
{
pci_unregister_driver(&me_driver_pci_driver);
comedi_driver_unregister(&me_driver);
}
static inline void sleep(unsigned sec)
{
current->state = TASK_INTERRUPTIBLE;
schedule_timeout(sec * HZ);
}
static int me_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int bits;
int mask = 1 << CR_CHAN(insn->chanspec);
if (mask & 0x0000ffff) {
bits = 0x0000ffff;
dev_private->control_2 |= ENABLE_PORT_A;
writew(dev_private->control_2,
dev_private->me_regbase + ME_CONTROL_2);
} else {
bits = 0xffff0000;
dev_private->control_2 |= ENABLE_PORT_B;
writew(dev_private->control_2,
dev_private->me_regbase + ME_CONTROL_2);
}
if (data[0]) {
s->io_bits |= bits;
} else {
s->io_bits &= ~bits;
}
return 1;
}
static int me_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int mask = data[0];
s->state &= ~mask;
s->state |= (mask & data[1]);
mask &= s->io_bits;
if (mask & 0x0000ffff) {
writew((s->state & 0xffff),
dev_private->me_regbase + ME_DIO_PORT_A);
} else {
data[1] &= ~0x0000ffff;
data[1] |= readw(dev_private->me_regbase + ME_DIO_PORT_A);
}
if (mask & 0xffff0000) {
writew(((s->state >> 16) & 0xffff),
dev_private->me_regbase + ME_DIO_PORT_B);
} else {
data[1] &= ~0xffff0000;
data[1] |= readw(dev_private->me_regbase + ME_DIO_PORT_B) << 16;
}
return 2;
}
static int me_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *subdevice,
struct comedi_insn *insn, unsigned int *data)
{
unsigned short value;
int chan = CR_CHAN((&insn->chanspec)[0]);
int rang = CR_RANGE((&insn->chanspec)[0]);
int aref = CR_AREF((&insn->chanspec)[0]);
int i;
dev_private->control_1 &= 0xFFFC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
dev_private->control_2 &= ~(ENABLE_ADFIFO | ENABLE_CHANLIST);
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
writew(0x00, dev_private->me_regbase + ME_RESET_INTERRUPT);
dev_private->control_2 |= (ENABLE_ADFIFO | ENABLE_CHANLIST);
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
value = chan & 0x0f;
value |= (rang & 0x03) << 4;
value |= (rang & 0x04) << 4;
value |= ((aref & AREF_DIFF) ? 0x80 : 0);
writew(value & 0xff, dev_private->me_regbase + ME_CHANNEL_LIST);
dev_private->control_1 |= SOFTWARE_TRIGGERED_ADC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
readw(dev_private->me_regbase + ME_ADC_START);
for (i = 100000; i > 0; i--)
if (!(readw(dev_private->me_regbase + ME_STATUS) & 0x0004))
break;
if (i) {
data[0] =
(readw(dev_private->me_regbase +
ME_READ_AD_FIFO) ^ 0x800) & 0x0FFF;
} else {
printk(KERN_ERR "comedi%d: Cannot get single value\n",
dev->minor);
return -EIO;
}
dev_private->control_1 &= 0xFFFC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
return 1;
}
static int me_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
dev_private->control_1 &= 0xFFFC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
return 0;
}
static int me_ai_do_cmd_test(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
return 0;
}
static int me_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *subdevice)
{
return 0;
}
static int me_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan;
int rang;
int i;
dev_private->control_2 |= ENABLE_DAC;
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
dev_private->control_2 |= BUFFERED_DAC;
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
for (i = 0; i < insn->n; i++) {
chan = CR_CHAN((&insn->chanspec)[i]);
rang = CR_RANGE((&insn->chanspec)[i]);
dev_private->dac_control &= ~(0x0880 >> chan);
if (rang == 0)
dev_private->dac_control |=
((DAC_BIPOLAR_A | DAC_GAIN_1_A) >> chan);
else if (rang == 1)
dev_private->dac_control |=
((DAC_BIPOLAR_A | DAC_GAIN_0_A) >> chan);
}
writew(dev_private->dac_control,
dev_private->me_regbase + ME_DAC_CONTROL);
readw(dev_private->me_regbase + ME_DAC_CONTROL_UPDATE);
for (i = 0; i < insn->n; i++) {
chan = CR_CHAN((&insn->chanspec)[i]);
writew((data[0] & s->maxdata),
dev_private->me_regbase + ME_DAC_DATA_A + (chan << 1));
dev_private->ao_readback[chan] = (data[0] & s->maxdata);
}
readw(dev_private->me_regbase + ME_DAC_UPDATE);
return i;
}
static int me_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++) {
data[i] =
dev_private->ao_readback[CR_CHAN((&insn->chanspec)[i])];
}
return 1;
}
static int me2600_xilinx_download(struct comedi_device *dev,
unsigned char *me2600_firmware,
unsigned int length)
{
unsigned int value;
unsigned int file_length;
unsigned int i;
writel(0x00, dev_private->plx_regbase + PLX_INTCSR);
value = readw(dev_private->me_regbase + XILINX_DOWNLOAD_RESET);
sleep(1);
writeb(0x00, dev_private->me_regbase + 0x0);
sleep(1);
if (length < 16)
return -EINVAL;
file_length = (((unsigned int)me2600_firmware[0] & 0xff) << 24) +
(((unsigned int)me2600_firmware[1] & 0xff) << 16) +
(((unsigned int)me2600_firmware[2] & 0xff) << 8) +
((unsigned int)me2600_firmware[3] & 0xff);
for (i = 0; i < file_length; i++)
writeb((me2600_firmware[16 + i] & 0xff),
dev_private->me_regbase + 0x0);
for (i = 0; i < 5; i++)
writeb(0x00, dev_private->me_regbase + 0x0);
value = readl(dev_private->plx_regbase + PLX_INTCSR);
if (value & 0x20) {
writel(0x00, dev_private->plx_regbase + PLX_INTCSR);
printk(KERN_ERR "comedi%d: Xilinx download failed\n",
dev->minor);
return -EIO;
}
sleep(1);
writel(0x43, dev_private->plx_regbase + PLX_INTCSR);
return 0;
}
static int me_reset(struct comedi_device *dev)
{
writew(0x00, dev_private->me_regbase + ME_CONTROL_1);
writew(0x00, dev_private->me_regbase + ME_CONTROL_2);
writew(0x00, dev_private->me_regbase + ME_RESET_INTERRUPT);
writew(0x00, dev_private->me_regbase + ME_DAC_CONTROL);
dev_private->dac_control = 0;
dev_private->control_1 = 0;
dev_private->control_2 = 0;
return 0;
}
static int me_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pci_device = NULL;
struct comedi_subdevice *subdevice;
struct me_board *board;
resource_size_t plx_regbase_tmp;
unsigned long plx_regbase_size_tmp;
resource_size_t me_regbase_tmp;
unsigned long me_regbase_size_tmp;
resource_size_t swap_regbase_tmp;
unsigned long swap_regbase_size_tmp;
resource_size_t regbase_tmp;
int result, error, i;
if (alloc_private(dev, sizeof(struct me_private_data)) < 0)
return -ENOMEM;
for_each_pci_dev(pci_device) {
if (pci_device->vendor == PCI_VENDOR_ID_MEILHAUS) {
for (i = 0; i < me_board_nbr; i++) {
if (me_boards[i].device_id ==
pci_device->device) {
if ((it->options[0] != 0)
|| (it->options[1] != 0)) {
if (pci_device->bus->number !=
it->options[0]
||
PCI_SLOT(pci_device->devfn)
!= it->options[1]) {
continue;
}
}
dev->board_ptr = me_boards + i;
board =
(struct me_board *)dev->board_ptr;
dev_private->pci_device = pci_device;
goto found;
}
}
}
}
printk(KERN_ERR
"comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
dev->minor, it->options[0], it->options[1]);
return -EIO;
found:
printk(KERN_INFO "comedi%d: found %s at PCI bus %d, slot %d\n",
dev->minor, me_boards[i].name,
pci_device->bus->number, PCI_SLOT(pci_device->devfn));
if (comedi_pci_enable(pci_device, ME_DRIVER_NAME) < 0) {
printk(KERN_ERR "comedi%d: Failed to enable PCI device and "
"request regions\n", dev->minor);
return -EIO;
}
dev->board_name = board->name;
plx_regbase_tmp = pci_resource_start(pci_device, 0);
plx_regbase_size_tmp = pci_resource_len(pci_device, 0);
dev_private->plx_regbase =
ioremap(plx_regbase_tmp, plx_regbase_size_tmp);
dev_private->plx_regbase_size = plx_regbase_size_tmp;
if (!dev_private->plx_regbase) {
printk("comedi%d: Failed to remap I/O memory\n", dev->minor);
return -ENOMEM;
}
swap_regbase_tmp = pci_resource_start(pci_device, 5);
swap_regbase_size_tmp = pci_resource_len(pci_device, 5);
if (!swap_regbase_tmp)
printk(KERN_ERR "comedi%d: Swap not present\n", dev->minor);
if (plx_regbase_tmp & 0x0080) {
printk(KERN_ERR "comedi%d: PLX-Bug detected\n", dev->minor);
if (swap_regbase_tmp) {
regbase_tmp = plx_regbase_tmp;
plx_regbase_tmp = swap_regbase_tmp;
swap_regbase_tmp = regbase_tmp;
result = pci_write_config_dword(pci_device,
PCI_BASE_ADDRESS_0,
plx_regbase_tmp);
if (result != PCIBIOS_SUCCESSFUL)
return -EIO;
result = pci_write_config_dword(pci_device,
PCI_BASE_ADDRESS_5,
swap_regbase_tmp);
if (result != PCIBIOS_SUCCESSFUL)
return -EIO;
} else {
plx_regbase_tmp -= 0x80;
result = pci_write_config_dword(pci_device,
PCI_BASE_ADDRESS_0,
plx_regbase_tmp);
if (result != PCIBIOS_SUCCESSFUL)
return -EIO;
}
}
me_regbase_tmp = pci_resource_start(pci_device, 2);
me_regbase_size_tmp = pci_resource_len(pci_device, 2);
dev_private->me_regbase_size = me_regbase_size_tmp;
dev_private->me_regbase = ioremap(me_regbase_tmp, me_regbase_size_tmp);
if (!dev_private->me_regbase) {
printk(KERN_ERR "comedi%d: Failed to remap I/O memory\n",
dev->minor);
return -ENOMEM;
}
if (board->device_id == ME2600_DEVICE_ID) {
unsigned char *aux_data;
int aux_len;
aux_data = comedi_aux_data(it->options, 0);
aux_len = it->options[COMEDI_DEVCONF_AUX_DATA_LENGTH];
if (!aux_data || aux_len < 1) {
comedi_error(dev, "You must provide me2600 firmware "
"using the --init-data option of "
"comedi_config");
return -EINVAL;
}
me2600_xilinx_download(dev, aux_data, aux_len);
}
me_reset(dev);
error = alloc_subdevices(dev, 3);
if (error < 0)
return error;
subdevice = dev->subdevices + 0;
subdevice->type = COMEDI_SUBD_AI;
subdevice->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_CMD_READ;
subdevice->n_chan = board->ai_channel_nbr;
subdevice->maxdata = board->ai_resolution_mask;
subdevice->len_chanlist = board->ai_channel_nbr;
subdevice->range_table = board->ai_range_list;
subdevice->cancel = me_ai_cancel;
subdevice->insn_read = me_ai_insn_read;
subdevice->do_cmdtest = me_ai_do_cmd_test;
subdevice->do_cmd = me_ai_do_cmd;
subdevice = dev->subdevices + 1;
subdevice->type = COMEDI_SUBD_AO;
subdevice->subdev_flags = SDF_WRITEABLE | SDF_COMMON;
subdevice->n_chan = board->ao_channel_nbr;
subdevice->maxdata = board->ao_resolution_mask;
subdevice->len_chanlist = board->ao_channel_nbr;
subdevice->range_table = board->ao_range_list;
subdevice->insn_read = me_ao_insn_read;
subdevice->insn_write = me_ao_insn_write;
subdevice = dev->subdevices + 2;
subdevice->type = COMEDI_SUBD_DIO;
subdevice->subdev_flags = SDF_READABLE | SDF_WRITEABLE;
subdevice->n_chan = board->dio_channel_nbr;
subdevice->maxdata = 1;
subdevice->len_chanlist = board->dio_channel_nbr;
subdevice->range_table = &range_digital;
subdevice->insn_bits = me_dio_insn_bits;
subdevice->insn_config = me_dio_insn_config;
subdevice->io_bits = 0;
printk(KERN_INFO "comedi%d: " ME_DRIVER_NAME " attached.\n",
dev->minor);
return 0;
}
static int me_detach(struct comedi_device *dev)
{
if (dev_private) {
if (dev_private->me_regbase) {
me_reset(dev);
iounmap(dev_private->me_regbase);
}
if (dev_private->plx_regbase)
iounmap(dev_private->plx_regbase);
if (dev_private->pci_device) {
if (dev_private->plx_regbase_size)
comedi_pci_disable(dev_private->pci_device);
pci_dev_put(dev_private->pci_device);
}
}
return 0;
}
