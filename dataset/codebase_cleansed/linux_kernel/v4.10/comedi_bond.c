static int bonding_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct comedi_bond_private *devpriv = dev->private;
unsigned int n_left, n_done, base_chan;
unsigned int write_mask, data_bits;
struct bonded_device **devs;
write_mask = data[0];
data_bits = data[1];
base_chan = CR_CHAN(insn->chanspec);
n_left = devpriv->nchans - base_chan;
if (n_left > 32)
n_left = 32;
n_done = 0;
devs = devpriv->devs;
do {
struct bonded_device *bdev = *devs++;
if (base_chan < bdev->nchans) {
unsigned int b_chans, b_mask, b_write_mask, b_data_bits;
int ret;
b_chans = bdev->nchans - base_chan;
if (b_chans > n_left)
b_chans = n_left;
b_mask = (b_chans < 32) ? ((1 << b_chans) - 1)
: 0xffffffff;
b_write_mask = (write_mask >> n_done) & b_mask;
b_data_bits = (data_bits >> n_done) & b_mask;
ret = comedi_dio_bitfield2(bdev->dev, bdev->subdev,
b_write_mask, &b_data_bits,
base_chan);
if (ret < 0)
return ret;
data[1] &= ~(b_mask << n_done);
data[1] |= (b_data_bits & b_mask) << n_done;
base_chan = 0;
n_done += b_chans;
n_left -= b_chans;
} else {
base_chan -= bdev->nchans;
}
} while (n_left);
return insn->n;
}
static int bonding_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct comedi_bond_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int ret;
struct bonded_device *bdev;
struct bonded_device **devs;
devs = devpriv->devs;
for (bdev = *devs++; chan >= bdev->nchans; bdev = *devs++)
chan -= bdev->nchans;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
case INSN_CONFIG_DIO_INPUT:
ret = comedi_dio_config(bdev->dev, bdev->subdev, chan, data[0]);
break;
case INSN_CONFIG_DIO_QUERY:
ret = comedi_dio_get_config(bdev->dev, bdev->subdev, chan,
&data[1]);
break;
default:
ret = -EINVAL;
break;
}
if (ret >= 0)
ret = insn->n;
return ret;
}
static int do_dev_config(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_bond_private *devpriv = dev->private;
DECLARE_BITMAP(devs_opened, COMEDI_NUM_BOARD_MINORS);
int i;
memset(&devs_opened, 0, sizeof(devs_opened));
devpriv->name[0] = 0;
for (i = 0; i < COMEDI_NDEVCONFOPTS && (!i || it->options[i]); ++i) {
char file[sizeof("/dev/comediXXXXXX")];
int minor = it->options[i];
struct comedi_device *d;
int sdev = -1, nchans;
struct bonded_device *bdev;
struct bonded_device **devs;
if (minor < 0 || minor >= COMEDI_NUM_BOARD_MINORS) {
dev_err(dev->class_dev,
"Minor %d is invalid!\n", minor);
return -EINVAL;
}
if (minor == dev->minor) {
dev_err(dev->class_dev,
"Cannot bond this driver to itself!\n");
return -EINVAL;
}
if (test_and_set_bit(minor, devs_opened)) {
dev_err(dev->class_dev,
"Minor %d specified more than once!\n", minor);
return -EINVAL;
}
snprintf(file, sizeof(file), "/dev/comedi%d", minor);
file[sizeof(file) - 1] = 0;
d = comedi_open(file);
if (!d) {
dev_err(dev->class_dev,
"Minor %u could not be opened\n", minor);
return -ENODEV;
}
while ((sdev = comedi_find_subdevice_by_type(d, COMEDI_SUBD_DIO,
sdev + 1)) > -1) {
nchans = comedi_get_n_channels(d, sdev);
if (nchans <= 0) {
dev_err(dev->class_dev,
"comedi_get_n_channels() returned %d on minor %u subdev %d!\n",
nchans, minor, sdev);
return -EINVAL;
}
bdev = kmalloc(sizeof(*bdev), GFP_KERNEL);
if (!bdev)
return -ENOMEM;
bdev->dev = d;
bdev->minor = minor;
bdev->subdev = sdev;
bdev->nchans = nchans;
devpriv->nchans += nchans;
devs = krealloc(devpriv->devs,
(devpriv->ndevs + 1) * sizeof(*devs),
GFP_KERNEL);
if (!devs) {
dev_err(dev->class_dev,
"Could not allocate memory. Out of memory?\n");
kfree(bdev);
return -ENOMEM;
}
devpriv->devs = devs;
devpriv->devs[devpriv->ndevs++] = bdev;
{
char buf[20];
snprintf(buf, sizeof(buf), "%u:%u ",
bdev->minor, bdev->subdev);
strlcat(devpriv->name, buf,
sizeof(devpriv->name));
}
}
}
if (!devpriv->nchans) {
dev_err(dev->class_dev, "No channels found!\n");
return -EINVAL;
}
return 0;
}
static int bonding_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_bond_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = do_dev_config(dev, it);
if (ret)
return ret;
dev->board_name = devpriv->name;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = devpriv->nchans;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = bonding_dio_insn_bits;
s->insn_config = bonding_dio_insn_config;
dev_info(dev->class_dev,
"%s: %s attached, %u channels from %u devices\n",
dev->driver->driver_name, dev->board_name,
devpriv->nchans, devpriv->ndevs);
return 0;
}
static void bonding_detach(struct comedi_device *dev)
{
struct comedi_bond_private *devpriv = dev->private;
if (devpriv && devpriv->devs) {
DECLARE_BITMAP(devs_closed, COMEDI_NUM_BOARD_MINORS);
memset(&devs_closed, 0, sizeof(devs_closed));
while (devpriv->ndevs--) {
struct bonded_device *bdev;
bdev = devpriv->devs[devpriv->ndevs];
if (!bdev)
continue;
if (!test_and_set_bit(bdev->minor, devs_closed))
comedi_close(bdev->dev);
kfree(bdev);
}
kfree(devpriv->devs);
devpriv->devs = NULL;
}
}
