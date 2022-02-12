struct comedi_device *comedi_open(const char *filename)
{
struct comedi_device_file_info *dev_file_info;
struct comedi_device *dev;
unsigned int minor;
if (strncmp(filename, "/dev/comedi", 11) != 0)
return NULL;
minor = simple_strtoul(filename + 11, NULL, 0);
if (minor >= COMEDI_NUM_BOARD_MINORS)
return NULL;
dev_file_info = comedi_get_device_file_info(minor);
if (dev_file_info == NULL)
return NULL;
dev = dev_file_info->device;
if (dev == NULL || !dev->attached)
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
static int comedi_do_insn(struct comedi_device *dev, struct comedi_insn *insn)
{
struct comedi_subdevice *s;
int ret = 0;
if (insn->subdev >= dev->n_subdevices) {
ret = -EINVAL;
goto error;
}
s = dev->subdevices + insn->subdev;
if (s->type == COMEDI_SUBD_UNUSED) {
printk(KERN_ERR "%d not useable subdevice\n", insn->subdev);
ret = -EIO;
goto error;
}
ret = comedi_check_chanlist(s, 1, &insn->chanspec);
if (ret < 0) {
printk(KERN_ERR "bad chanspec\n");
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
ret = s->insn_bits(dev, s, insn, insn->data);
break;
case INSN_CONFIG:
ret = s->insn_config(dev, s, insn, insn->data);
break;
default:
ret = -EINVAL;
break;
}
s->busy = NULL;
error:
return ret;
}
int comedi_dio_config(struct comedi_device *dev, unsigned int subdev,
unsigned int chan, unsigned int io)
{
struct comedi_insn insn;
memset(&insn, 0, sizeof(insn));
insn.insn = INSN_CONFIG;
insn.n = 1;
insn.data = &io;
insn.subdev = subdev;
insn.chanspec = CR_PACK(chan, 0, 0);
return comedi_do_insn(dev, &insn);
}
int comedi_dio_bitfield(struct comedi_device *dev, unsigned int subdev,
unsigned int mask, unsigned int *bits)
{
struct comedi_insn insn;
unsigned int data[2];
int ret;
memset(&insn, 0, sizeof(insn));
insn.insn = INSN_BITS;
insn.n = 2;
insn.data = data;
insn.subdev = subdev;
data[0] = mask;
data[1] = *bits;
ret = comedi_do_insn(dev, &insn);
*bits = data[1];
return ret;
}
int comedi_find_subdevice_by_type(struct comedi_device *dev, int type,
unsigned int subd)
{
if (subd > dev->n_subdevices)
return -ENODEV;
for (; subd < dev->n_subdevices; subd++) {
if (dev->subdevices[subd].type == type)
return subd;
}
return -1;
}
int comedi_get_n_channels(struct comedi_device *dev, unsigned int subdevice)
{
struct comedi_subdevice *s = dev->subdevices + subdevice;
return s->n_chan;
}
