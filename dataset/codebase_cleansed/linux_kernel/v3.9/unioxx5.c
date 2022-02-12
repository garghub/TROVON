static int __unioxx5_define_chan_offset(int chan_num)
{
if (chan_num < 0 || chan_num > 23)
return -1;
return (chan_num >> 3) + 1;
}
static void __unioxx5_analog_config(struct unioxx5_subd_priv *usp, int channel)
{
int chan_a, chan_b, conf, channel_offset;
channel_offset = __unioxx5_define_chan_offset(channel);
conf = usp->usp_prev_cn_val[channel_offset - 1];
chan_a = chan_b = 1;
if (channel % 2 == 0) {
chan_a <<= channel & 0x07;
chan_b <<= (channel + 1) & 0x07;
} else {
chan_a <<= (channel - 1) & 0x07;
chan_b <<= channel & 0x07;
}
conf |= chan_a;
conf &= ~chan_b;
outb(1, usp->usp_iobase + 0);
outb(conf, usp->usp_iobase + channel_offset);
outb(0, usp->usp_iobase + 0);
usp->usp_prev_cn_val[channel_offset - 1] = conf;
}
static int __unioxx5_digital_read(struct unioxx5_subd_priv *usp,
unsigned int *data, int channel, int minor)
{
int channel_offset, mask = 1 << (channel & 0x07);
channel_offset = __unioxx5_define_chan_offset(channel);
if (channel_offset < 0) {
pr_err("comedi%d: undefined channel %d. channel range is 0 .. 23\n",
minor, channel);
return 0;
}
*data = inb(usp->usp_iobase + channel_offset);
*data &= mask;
if (channel_offset > 1)
channel -= 2 << channel_offset;
*data >>= channel;
return 1;
}
static int __unioxx5_analog_read(struct unioxx5_subd_priv *usp,
unsigned int *data, int channel, int minor)
{
int module_no, read_ch;
char control;
module_no = channel / 2;
read_ch = channel % 2;
if (usp->usp_module_type[module_no] & MODULE_OUTPUT_MASK) {
pr_err("comedi%d: module in position %d with id 0x%02x is for output only",
minor, module_no, usp->usp_module_type[module_no]);
return 0;
}
__unioxx5_analog_config(usp, channel);
outb(module_no + 1, usp->usp_iobase + 5);
outb('V', usp->usp_iobase + 6);
control = inb(usp->usp_iobase);
while (!((control = inb(usp->usp_iobase + 0)) & Rx4CA))
;
if ((control & Rx4CA_ERR_MASK)) {
printk("COMEDI: 4 bytes error\n");
return 0;
}
if (read_ch)
*data = inw(usp->usp_iobase + 6);
else
*data = inw(usp->usp_iobase + 4);
return 1;
}
static int __unioxx5_digital_write(struct unioxx5_subd_priv *usp,
unsigned int *data, int channel, int minor)
{
int channel_offset, val;
int mask = 1 << (channel & 0x07);
channel_offset = __unioxx5_define_chan_offset(channel);
if (channel_offset < 0) {
pr_err("comedi%d: undefined channel %d. channel range is 0 .. 23\n",
minor, channel);
return 0;
}
val = usp->usp_prev_wr_val[channel_offset - 1];
if (*data)
val |= mask;
else
val &= ~mask;
outb(val, usp->usp_iobase + channel_offset);
usp->usp_prev_wr_val[channel_offset - 1] = val;
return 1;
}
static int __unioxx5_analog_write(struct unioxx5_subd_priv *usp,
unsigned int *data, int channel, int minor)
{
int module, i;
module = channel / 2;
i = (channel % 2) << 1;
if (!(usp->usp_module_type[module] & MODULE_OUTPUT_MASK)) {
pr_err("comedi%d: module in position %d with id 0x%0x is for input only!\n",
minor, module, usp->usp_module_type[module]);
return 0;
}
__unioxx5_analog_config(usp, channel);
usp->usp_extra_data[module][i++] = (unsigned char)(*data & 0x00FF);
usp->usp_extra_data[module][i] = (unsigned char)((*data & 0xFF00) >> 8);
outb(module + 1, usp->usp_iobase + 5);
outb('W', usp->usp_iobase + 6);
for (i = 0; i < 4; i++) {
while (!((inb(usp->usp_iobase + 0)) & TxBE))
;
outb(usp->usp_extra_data[module][i], usp->usp_iobase + 6);
}
return 1;
}
static int unioxx5_subdev_read(struct comedi_device *dev,
struct comedi_subdevice *subdev,
struct comedi_insn *insn, unsigned int *data)
{
struct unioxx5_subd_priv *usp = subdev->private;
int channel, type;
channel = CR_CHAN(insn->chanspec);
type = usp->usp_module_type[channel / 2];
if (type == MODULE_DIGITAL) {
if (!__unioxx5_digital_read(usp, data, channel, dev->minor))
return -1;
} else {
if (!__unioxx5_analog_read(usp, data, channel, dev->minor))
return -1;
}
return 1;
}
static int unioxx5_subdev_write(struct comedi_device *dev,
struct comedi_subdevice *subdev,
struct comedi_insn *insn, unsigned int *data)
{
struct unioxx5_subd_priv *usp = subdev->private;
int channel, type;
channel = CR_CHAN(insn->chanspec);
type = usp->usp_module_type[channel / 2];
if (type == MODULE_DIGITAL) {
if (!__unioxx5_digital_write(usp, data, channel, dev->minor))
return -1;
} else {
if (!__unioxx5_analog_write(usp, data, channel, dev->minor))
return -1;
}
return 1;
}
static int unioxx5_insn_config(struct comedi_device *dev,
struct comedi_subdevice *subdev,
struct comedi_insn *insn, unsigned int *data)
{
int channel_offset, flags, channel = CR_CHAN(insn->chanspec), type;
struct unioxx5_subd_priv *usp = subdev->private;
int mask = 1 << (channel & 0x07);
type = usp->usp_module_type[channel / 2];
if (type != MODULE_DIGITAL) {
dev_err(dev->class_dev,
"comedi%d: channel configuration accessible only for digital modules\n",
dev->minor);
return -1;
}
channel_offset = __unioxx5_define_chan_offset(channel);
if (channel_offset < 0) {
dev_err(dev->class_dev,
"comedi%d: undefined channel %d. channel range is 0 .. 23\n",
dev->minor, channel);
return -1;
}
flags = usp->usp_prev_cn_val[channel_offset - 1];
switch (*data) {
case COMEDI_INPUT:
flags &= ~mask;
break;
case COMEDI_OUTPUT:
flags |= mask;
break;
default:
dev_err(dev->class_dev,
"comedi%d: unknown flag\n", dev->minor);
return -1;
}
outb(1, usp->usp_iobase + 0);
outb(flags, usp->usp_iobase + channel_offset);
outb(0, usp->usp_iobase + 0);
usp->usp_prev_cn_val[channel_offset - 1] = flags;
return 0;
}
static int __unioxx5_subdev_init(struct comedi_subdevice *subdev,
int subdev_iobase, int minor)
{
struct unioxx5_subd_priv *usp;
int i, to, ndef_flag = 0;
if (!request_region(subdev_iobase, UNIOXX5_SIZE, DRIVER_NAME)) {
dev_err(subdev->class_dev,
"comedi%d: I/O port conflict\n", minor);
return -EIO;
}
usp = kzalloc(sizeof(*usp), GFP_KERNEL);
if (usp == NULL)
return -1;
usp->usp_iobase = subdev_iobase;
dev_info(subdev->class_dev, "comedi%d: |", minor);
for (i = 0; i < 12; i++) {
to = 10000;
__unioxx5_analog_config(usp, i * 2);
outb(i + 1, subdev_iobase + 5);
outb('H', subdev_iobase + 6);
while (!(inb(subdev_iobase + 0) & TxBE))
;
outb(0, subdev_iobase + 6);
while (!(inb(subdev_iobase + 0) & Rx2CA)) {
if (--to <= 0) {
ndef_flag = 1;
break;
}
}
if (ndef_flag) {
usp->usp_module_type[i] = 0;
ndef_flag = 0;
} else
usp->usp_module_type[i] = inb(subdev_iobase + 6);
printk(" [%d] 0x%02x |", i, usp->usp_module_type[i]);
udelay(1);
}
printk("\n");
subdev->type = COMEDI_SUBD_DIO;
subdev->private = usp;
subdev->subdev_flags = SDF_READABLE | SDF_WRITABLE;
subdev->n_chan = UNIOXX5_NUM_OF_CHANS;
subdev->maxdata = 0xFFF;
subdev->range_table = &range_digital;
subdev->insn_read = unioxx5_subdev_read;
subdev->insn_write = unioxx5_subdev_write;
subdev->insn_config = unioxx5_insn_config;
return 0;
}
static int unioxx5_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int iobase, i, n_subd;
int id, num, ba;
int ret;
iobase = it->options[0];
dev->board_name = DRIVER_NAME;
dev->iobase = iobase;
iobase += UNIOXX5_SUBDEV_BASE;
for (i = n_subd = 0, ba = iobase; i < 4; i++, ba += UNIOXX5_SUBDEV_ODDS) {
id = inb(ba + 0xE);
num = inb(ba + 0xF);
if (id != 'g' || num != 1)
continue;
n_subd++;
}
if (n_subd < 2) {
dev_err(dev->class_dev,
"your card must has at least 2 'g01' subdevices\n");
return -1;
}
ret = comedi_alloc_subdevices(dev, n_subd);
if (ret)
return ret;
for (i = 0; i < n_subd; i++, iobase += UNIOXX5_SUBDEV_ODDS) {
if (__unioxx5_subdev_init(&dev->subdevices[i], iobase,
dev->minor) < 0)
return -1;
}
return 0;
}
static void unioxx5_detach(struct comedi_device *dev)
{
int i;
struct comedi_subdevice *subdev;
struct unioxx5_subd_priv *usp;
for (i = 0; i < dev->n_subdevices; i++) {
subdev = &dev->subdevices[i];
usp = subdev->private;
release_region(usp->usp_iobase, UNIOXX5_SIZE);
kfree(subdev->private);
}
}
