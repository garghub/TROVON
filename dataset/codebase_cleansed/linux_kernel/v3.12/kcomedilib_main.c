struct comedi_device *comedi_open(const char *filename)
{
struct comedi_device *dev;
unsigned int minor;
if (strncmp(filename, "/dev/comedi", 11) != 0)
return NULL;
minor = simple_strtoul(filename + 11, NULL, 0);
if (minor >= COMEDI_NUM_BOARD_MINORS)
return NULL;
dev = comedi_dev_from_minor(minor);
if (!dev || !dev->attached)
return NULL;
if (!try_module_get(dev->driver->module))
return NULL;
return dev;
}
int comedi_close(struct comedi_device *d)
{
struct comedi_device *dev = (struct comedi_device *)d;
module_put(dev->driver->module);
return 0;
}
static int comedi_do_insn(struct comedi_device *dev,
struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_subdevice *s;
int ret = 0;
if (insn->subdev >= dev->n_subdevices) {
ret = -EINVAL;
goto error;
}
s = &dev->subdevices[insn->subdev];
if (s->type == COMEDI_SUBD_UNUSED) {
dev_err(dev->class_dev,
"%d not useable subdevice\n", insn->subdev);
ret = -EIO;
goto error;
}
ret = comedi_check_chanlist(s, 1, &insn->chanspec);
if (ret < 0) {
dev_err(dev->class_dev, "bad chanspec\n");
ret = -EINVAL;
goto error;
}
if (s->busy) {
ret = -EBUSY;
goto error;
}
s->busy = dev;
switch (insn->insn) {
case INSN_BITS:
ret = s->insn_bits(dev, s, insn, data);
break;
case INSN_CONFIG:
ret = s->insn_config(dev, s, insn, data);
break;
default:
ret = -EINVAL;
break;
}
s->busy = NULL;
error:
return ret;
}
int comedi_dio_get_config(struct comedi_device *dev, unsigned int subdev,
unsigned int chan, unsigned int *io)
{
struct comedi_insn insn;
unsigned int data[2];
int ret;
memset(&insn, 0, sizeof(insn));
insn.insn = INSN_CONFIG;
insn.n = 2;
insn.subdev = subdev;
insn.chanspec = CR_PACK(chan, 0, 0);
data[0] = INSN_CONFIG_DIO_QUERY;
data[1] = 0;
ret = comedi_do_insn(dev, &insn, data);
if (ret >= 0)
*io = data[1];
return ret;
}
int comedi_dio_config(struct comedi_device *dev, unsigned int subdev,
unsigned int chan, unsigned int io)
{
struct comedi_insn insn;
memset(&insn, 0, sizeof(insn));
insn.insn = INSN_CONFIG;
insn.n = 1;
insn.subdev = subdev;
insn.chanspec = CR_PACK(chan, 0, 0);
return comedi_do_insn(dev, &insn, &io);
}
int comedi_dio_bitfield2(struct comedi_device *dev, unsigned int subdev,
unsigned int mask, unsigned int *bits,
unsigned int base_channel)
{
struct comedi_insn insn;
unsigned int data[2];
unsigned int n_chan;
unsigned int shift;
int ret;
if (subdev >= dev->n_subdevices)
return -EINVAL;
base_channel = CR_CHAN(base_channel);
n_chan = comedi_get_n_channels(dev, subdev);
if (base_channel >= n_chan)
return -EINVAL;
memset(&insn, 0, sizeof(insn));
insn.insn = INSN_BITS;
insn.chanspec = base_channel;
insn.n = 2;
insn.subdev = subdev;
data[0] = mask;
data[1] = *bits;
if (n_chan <= 32) {
shift = base_channel;
if (shift) {
insn.chanspec = 0;
data[0] <<= shift;
data[1] <<= shift;
}
} else {
shift = 0;
}
ret = comedi_do_insn(dev, &insn, data);
*bits = data[1] >> shift;
return ret;
}
int comedi_find_subdevice_by_type(struct comedi_device *dev, int type,
unsigned int subd)
{
struct comedi_subdevice *s;
if (subd > dev->n_subdevices)
return -ENODEV;
for (; subd < dev->n_subdevices; subd++) {
s = &dev->subdevices[subd];
if (s->type == type)
return subd;
}
return -1;
}
int comedi_get_n_channels(struct comedi_device *dev, unsigned int subdevice)
{
struct comedi_subdevice *s = &dev->subdevices[subdevice];
return s->n_chan;
}
