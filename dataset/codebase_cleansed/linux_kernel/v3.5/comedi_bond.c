static int bonding_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
#define LSAMPL_BITS (sizeof(unsigned int)*8)
unsigned nchans = LSAMPL_BITS, num_done = 0, i;
if (insn->n != 2)
return -EINVAL;
if (devpriv->nchans < nchans)
nchans = devpriv->nchans;
for (i = 0; num_done < nchans && i < devpriv->ndevs; ++i) {
struct BondedDevice *bdev = devpriv->devs[i];
unsigned int subdevMask = ((1 << bdev->nchans) - 1);
unsigned int writeMask, dataBits;
if (bdev->nchans >= LSAMPL_BITS)
subdevMask = (unsigned int)(-1);
writeMask = (data[0] >> num_done) & subdevMask;
dataBits = (data[1] >> num_done) & subdevMask;
if (comedi_dio_bitfield(bdev->dev, bdev->subdev, writeMask,
&dataBits) != 2)
return -EINVAL;
data[1] &= ~(subdevMask << num_done);
data[1] |= (dataBits & subdevMask) << num_done;
s->state = data[1];
num_done += bdev->nchans;
}
return insn->n;
}
static int bonding_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec), ret, io_bits = s->io_bits;
unsigned int io;
struct BondedDevice *bdev;
if (chan < 0 || chan >= devpriv->nchans)
return -EINVAL;
bdev = devpriv->chanIdDevMap[chan];
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
io = COMEDI_OUTPUT;
io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
io = COMEDI_INPUT;
io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
chan -= bdev->chanid_offset;
ret = comedi_dio_config(bdev->dev, bdev->subdev, chan, io);
if (ret != 1)
return -EINVAL;
s->io_bits = io_bits;
return insn->n;
}
static void *Realloc(const void *oldmem, size_t newlen, size_t oldlen)
{
void *newmem = kmalloc(newlen, GFP_KERNEL);
if (newmem && oldmem)
memcpy(newmem, oldmem, min(oldlen, newlen));
kfree(oldmem);
return newmem;
}
static int doDevConfig(struct comedi_device *dev, struct comedi_devconfig *it)
{
int i;
struct comedi_device *devs_opened[COMEDI_NUM_BOARD_MINORS];
memset(devs_opened, 0, sizeof(devs_opened));
devpriv->name[0] = 0;
for (i = 0; i < COMEDI_NDEVCONFOPTS && (!i || it->options[i]); ++i) {
char file[] = "/dev/comediXXXXXX";
int minor = it->options[i];
struct comedi_device *d;
int sdev = -1, nchans, tmp;
struct BondedDevice *bdev = NULL;
if (minor < 0 || minor >= COMEDI_NUM_BOARD_MINORS) {
ERROR("Minor %d is invalid!\n", minor);
return 0;
}
if (minor == dev->minor) {
ERROR("Cannot bond this driver to itself!\n");
return 0;
}
if (devs_opened[minor]) {
ERROR("Minor %d specified more than once!\n", minor);
return 0;
}
snprintf(file, sizeof(file), "/dev/comedi%u", minor);
file[sizeof(file) - 1] = 0;
d = devs_opened[minor] = comedi_open(file);
if (!d) {
ERROR("Minor %u could not be opened\n", minor);
return 0;
}
while ((sdev = comedi_find_subdevice_by_type(d, COMEDI_SUBD_DIO,
sdev + 1)) > -1) {
nchans = comedi_get_n_channels(d, sdev);
if (nchans <= 0) {
ERROR("comedi_get_n_channels() returned %d "
"on minor %u subdev %d!\n",
nchans, minor, sdev);
return 0;
}
bdev = kmalloc(sizeof(*bdev), GFP_KERNEL);
if (!bdev) {
ERROR("Out of memory.\n");
return 0;
}
bdev->dev = d;
bdev->minor = minor;
bdev->subdev = sdev;
bdev->subdev_type = COMEDI_SUBD_DIO;
bdev->nchans = nchans;
bdev->chanid_offset = devpriv->nchans;
while (nchans--)
devpriv->chanIdDevMap[devpriv->nchans++] = bdev;
tmp = devpriv->ndevs * sizeof(bdev);
devpriv->devs =
Realloc(devpriv->devs,
++devpriv->ndevs * sizeof(bdev), tmp);
if (!devpriv->devs) {
ERROR("Could not allocate memory. "
"Out of memory?");
return 0;
}
devpriv->devs[devpriv->ndevs - 1] = bdev;
{
char buf[20];
int left =
MAX_BOARD_NAME - strlen(devpriv->name) - 1;
snprintf(buf, sizeof(buf), "%d:%d ", dev->minor,
bdev->subdev);
buf[sizeof(buf) - 1] = 0;
strncat(devpriv->name, buf, left);
}
}
}
if (!devpriv->nchans) {
ERROR("No channels found!\n");
return 0;
}
return 1;
}
static int bonding_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
LOG_MSG("comedi%d\n", dev->minor);
if (alloc_private(dev, sizeof(struct Private)) < 0)
return -ENOMEM;
if (!doDevConfig(dev, it))
return -EINVAL;
dev->board_name = devpriv->name;
if (alloc_subdevices(dev, 1) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = devpriv->nchans;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = bonding_dio_insn_bits;
s->insn_config = bonding_dio_insn_config;
LOG_MSG("attached with %u DIO channels coming from %u different "
"subdevices all bonded together. "
"John Lennon would be proud!\n",
devpriv->nchans, devpriv->ndevs);
return 1;
}
static void bonding_detach(struct comedi_device *dev)
{
unsigned long devs_closed = 0;
if (devpriv) {
while (devpriv->ndevs-- && devpriv->devs) {
struct BondedDevice *bdev;
bdev = devpriv->devs[devpriv->ndevs];
if (!bdev)
continue;
if (!(devs_closed & (0x1 << bdev->minor))) {
comedi_close(bdev->dev);
devs_closed |= (0x1 << bdev->minor);
}
kfree(bdev);
}
kfree(devpriv->devs);
devpriv->devs = NULL;
kfree(devpriv);
dev->private = NULL;
}
}
