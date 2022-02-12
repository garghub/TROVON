static int dev_8255_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
int ret;
int i;
for (i = 0; i < COMEDI_NDEVCONFOPTS; i++) {
iobase = it->options[i];
if (!iobase)
break;
}
if (i == 0) {
dev_warn(dev->class_dev, "no devices specified\n");
return -EINVAL;
}
ret = comedi_alloc_subdevices(dev, i);
if (ret)
return ret;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
iobase = it->options[i];
ret = __comedi_request_region(dev, iobase, I8255_SIZE);
if (ret) {
s->type = COMEDI_SUBD_UNUSED;
} else {
ret = subdev_8255_init(dev, s, NULL, iobase);
if (ret) {
release_region(iobase, I8255_SIZE);
s->type = COMEDI_SUBD_UNUSED;
return ret;
}
}
}
return 0;
}
static void dev_8255_detach(struct comedi_device *dev)
{
struct comedi_subdevice *s;
int i;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
if (s->type != COMEDI_SUBD_UNUSED) {
unsigned long regbase = subdev_8255_regbase(s);
release_region(regbase, I8255_SIZE);
}
}
}
