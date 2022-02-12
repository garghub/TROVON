static inline void sleep(unsigned sec)
{
current->state = TASK_INTERRUPTIBLE;
schedule_timeout(sec * HZ);
}
static int me_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *dev_private = dev->private;
unsigned int mask = 1 << CR_CHAN(insn->chanspec);
unsigned int bits;
unsigned int port;
if (mask & 0x0000ffff) {
bits = 0x0000ffff;
port = ENABLE_PORT_A;
} else {
bits = 0xffff0000;
port = ENABLE_PORT_B;
}
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~bits;
dev_private->control_2 &= ~port;
break;
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= bits;
dev_private->control_2 |= port;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & bits) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
}
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
return insn->n;
}
static int me_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *dev_private = dev->private;
void __iomem *mmio_porta = dev_private->me_regbase + ME_DIO_PORT_A;
void __iomem *mmio_portb = dev_private->me_regbase + ME_DIO_PORT_B;
unsigned int mask = data[0];
unsigned int bits = data[1];
unsigned int val;
mask &= s->io_bits;
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
if (mask & 0x0000ffff)
writew((s->state & 0xffff), mmio_porta);
if (mask & 0xffff0000)
writew(((s->state >> 16) & 0xffff), mmio_portb);
}
if (s->io_bits & 0x0000ffff)
val = s->state & 0xffff;
else
val = readw(mmio_porta);
if (s->io_bits & 0xffff0000)
val |= (s->state & 0xffff0000);
else
val |= (readw(mmio_portb) << 16);
data[1] = val;
return insn->n;
}
static int me_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *dev_private = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int rang = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned short val;
int i;
dev_private->control_1 &= 0xFFFC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
dev_private->control_2 &= ~(ENABLE_ADFIFO | ENABLE_CHANLIST);
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
writew(0x00, dev_private->me_regbase + ME_RESET_INTERRUPT);
dev_private->control_2 |= (ENABLE_ADFIFO | ENABLE_CHANLIST);
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
val = chan & 0x0f;
val |= (rang & 0x03) << 4;
val |= (rang & 0x04) << 4;
val |= ((aref & AREF_DIFF) ? 0x80 : 0);
writew(val & 0xff, dev_private->me_regbase + ME_CHANNEL_LIST);
dev_private->control_1 |= SOFTWARE_TRIGGERED_ADC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
readw(dev_private->me_regbase + ME_ADC_START);
for (i = 100000; i > 0; i--)
if (!(readw(dev_private->me_regbase + ME_STATUS) & 0x0004))
break;
if (i) {
val = readw(dev_private->me_regbase + ME_READ_AD_FIFO);
val = (val ^ 0x800) & 0x0fff;
data[0] = val;
} else {
dev_err(dev->class_dev, "Cannot get single value\n");
return -EIO;
}
dev_private->control_1 &= 0xFFFC;
writew(dev_private->control_1, dev_private->me_regbase + ME_CONTROL_1);
return 1;
}
static int me_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *dev_private = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int rang = CR_RANGE(insn->chanspec);
int i;
dev_private->control_2 |= ENABLE_DAC;
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
dev_private->control_2 |= BUFFERED_DAC;
writew(dev_private->control_2, dev_private->me_regbase + ME_CONTROL_2);
for (i = 0; i < insn->n; i++) {
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
writew((data[0] & s->maxdata),
dev_private->me_regbase + ME_DAC_DATA_A + (chan << 1));
dev_private->ao_readback[chan] = (data[0] & s->maxdata);
}
readw(dev_private->me_regbase + ME_DAC_UPDATE);
return insn->n;
}
static int me_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct me_private_data *dev_private = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = dev_private->ao_readback[chan];
return insn->n;
}
static int me2600_xilinx_download(struct comedi_device *dev,
const u8 *data, size_t size)
{
struct me_private_data *dev_private = dev->private;
unsigned int value;
unsigned int file_length;
unsigned int i;
writel(0x00, dev_private->plx_regbase + PLX_INTCSR);
value = readw(dev_private->me_regbase + XILINX_DOWNLOAD_RESET);
sleep(1);
writeb(0x00, dev_private->me_regbase + 0x0);
sleep(1);
if (size < 16)
return -EINVAL;
file_length = (((unsigned int)data[0] & 0xff) << 24) +
(((unsigned int)data[1] & 0xff) << 16) +
(((unsigned int)data[2] & 0xff) << 8) +
((unsigned int)data[3] & 0xff);
for (i = 0; i < file_length; i++)
writeb((data[16 + i] & 0xff),
dev_private->me_regbase + 0x0);
for (i = 0; i < 5; i++)
writeb(0x00, dev_private->me_regbase + 0x0);
value = readl(dev_private->plx_regbase + PLX_INTCSR);
if (value & 0x20) {
writel(0x00, dev_private->plx_regbase + PLX_INTCSR);
dev_err(dev->class_dev, "Xilinx download failed\n");
return -EIO;
}
sleep(1);
writel(0x43, dev_private->plx_regbase + PLX_INTCSR);
return 0;
}
static int me2600_upload_firmware(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct firmware *fw;
int ret;
ret = request_firmware(&fw, ME2600_FIRMWARE, &pcidev->dev);
if (ret)
return ret;
ret = me2600_xilinx_download(dev, fw->data, fw->size);
release_firmware(fw);
return ret;
}
static int me_reset(struct comedi_device *dev)
{
struct me_private_data *dev_private = dev->private;
writew(0x00, dev_private->me_regbase + ME_CONTROL_1);
writew(0x00, dev_private->me_regbase + ME_CONTROL_2);
writew(0x00, dev_private->me_regbase + ME_RESET_INTERRUPT);
writew(0x00, dev_private->me_regbase + ME_DAC_CONTROL);
dev_private->dac_control = 0;
dev_private->control_1 = 0;
dev_private->control_2 = 0;
return 0;
}
static const void *me_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct me_board *board;
int i;
for (i = 0; i < ARRAY_SIZE(me_boards); i++) {
board = &me_boards[i];
if (board->device_id == pcidev->device)
return board;
}
return NULL;
}
static int me_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct me_board *board;
struct me_private_data *dev_private;
struct comedi_subdevice *s;
int ret;
board = me_find_boardinfo(dev, pcidev);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
dev_private = kzalloc(sizeof(*dev_private), GFP_KERNEL);
if (!dev_private)
return -ENOMEM;
dev->private = dev_private;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = 1;
dev_private->plx_regbase = ioremap(pci_resource_start(pcidev, 0),
pci_resource_len(pcidev, 0));
if (!dev_private->plx_regbase)
return -ENOMEM;
dev_private->me_regbase = ioremap(pci_resource_start(pcidev, 2),
pci_resource_len(pcidev, 2));
if (!dev_private->me_regbase)
return -ENOMEM;
if (board->device_id == ME2600_DEVICE_ID) {
ret = me2600_upload_firmware(dev);
if (ret < 0)
return ret;
}
me_reset(dev);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->len_chanlist = 16;
s->range_table = &me_ai_range;
s->insn_read = me_ai_insn_read;
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->len_chanlist = 4;
s->range_table = &me_ao_range;
s->insn_read = me_ao_insn_read;
s->insn_write = me_ao_insn_write;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITEABLE;
s->n_chan = 32;
s->maxdata = 1;
s->len_chanlist = 32;
s->range_table = &range_digital;
s->insn_bits = me_dio_insn_bits;
s->insn_config = me_dio_insn_config;
s->io_bits = 0;
dev_info(dev->class_dev, "%s: %s attached\n",
dev->driver->driver_name, dev->board_name);
return 0;
}
static void me_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct me_private_data *dev_private = dev->private;
if (dev_private) {
if (dev_private->me_regbase) {
me_reset(dev);
iounmap(dev_private->me_regbase);
}
if (dev_private->plx_regbase)
iounmap(dev_private->plx_regbase);
}
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int me_daq_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &me_daq_driver);
}
static void me_daq_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
