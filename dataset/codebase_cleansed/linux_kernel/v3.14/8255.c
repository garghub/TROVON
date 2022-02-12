static int subdev_8255_io(int dir, int port, int data, unsigned long iobase)
{
if (dir) {
outb(data, iobase + port);
return 0;
} else {
return inb(iobase + port);
}
}
void subdev_8255_interrupt(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct subdev_8255_private *spriv = s->private;
unsigned long iobase = spriv->iobase;
unsigned short d;
d = spriv->io(0, _8255_DATA, 0, iobase);
d |= (spriv->io(0, _8255_DATA + 1, 0, iobase) << 8);
comedi_buf_put(s->async, d);
s->async->events |= COMEDI_CB_EOS;
comedi_event(dev, s);
}
static int subdev_8255_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct subdev_8255_private *spriv = s->private;
unsigned long iobase = spriv->iobase;
unsigned int mask;
unsigned int v;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0xff)
spriv->io(1, _8255_DATA, s->state & 0xff, iobase);
if (mask & 0xff00)
spriv->io(1, _8255_DATA + 1, (s->state >> 8) & 0xff,
iobase);
if (mask & 0xff0000)
spriv->io(1, _8255_DATA + 2, (s->state >> 16) & 0xff,
iobase);
}
v = spriv->io(0, _8255_DATA, 0, iobase);
v |= (spriv->io(0, _8255_DATA + 1, 0, iobase) << 8);
v |= (spriv->io(0, _8255_DATA + 2, 0, iobase) << 16);
data[1] = v;
return insn->n;
}
static void subdev_8255_do_config(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct subdev_8255_private *spriv = s->private;
unsigned long iobase = spriv->iobase;
int config;
config = CR_CW;
if (!(s->io_bits & 0x0000ff))
config |= CR_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= CR_B_IO;
if (!(s->io_bits & 0x0f0000))
config |= CR_C_LO_IO;
if (!(s->io_bits & 0xf00000))
config |= CR_C_HI_IO;
spriv->io(1, _8255_CR, config, iobase);
}
static int subdev_8255_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 8)
mask = 0x0000ff;
else if (chan < 16)
mask = 0x00ff00;
else if (chan < 20)
mask = 0x0f0000;
else
mask = 0xf00000;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
subdev_8255_do_config(dev, s);
return insn->n;
}
static int subdev_8255_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, 1);
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int subdev_8255_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return 0;
}
static int subdev_8255_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return 0;
}
int subdev_8255_init(struct comedi_device *dev, struct comedi_subdevice *s,
int (*io)(int, int, int, unsigned long),
unsigned long iobase)
{
struct subdev_8255_private *spriv;
spriv = comedi_alloc_spriv(s, sizeof(*spriv));
if (!spriv)
return -ENOMEM;
spriv->iobase = iobase;
spriv->io = io ? io : subdev_8255_io;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = subdev_8255_insn;
s->insn_config = subdev_8255_insn_config;
subdev_8255_do_config(dev, s);
return 0;
}
int subdev_8255_init_irq(struct comedi_device *dev, struct comedi_subdevice *s,
int (*io)(int, int, int, unsigned long),
unsigned long iobase)
{
int ret;
ret = subdev_8255_init(dev, s, io, iobase);
if (ret)
return ret;
s->do_cmdtest = subdev_8255_cmdtest;
s->do_cmd = subdev_8255_cmd;
s->cancel = subdev_8255_cancel;
return 0;
}
static int dev_8255_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
unsigned long iobase;
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
ret = __comedi_request_region(dev, iobase, _8255_SIZE);
if (ret) {
s->type = COMEDI_SUBD_UNUSED;
} else {
ret = subdev_8255_init(dev, s, NULL, iobase);
if (ret)
return ret;
}
}
return 0;
}
static void dev_8255_detach(struct comedi_device *dev)
{
struct comedi_subdevice *s;
struct subdev_8255_private *spriv;
int i;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
if (s->type != COMEDI_SUBD_UNUSED) {
spriv = s->private;
release_region(spriv->iobase, _8255_SIZE);
}
}
}
