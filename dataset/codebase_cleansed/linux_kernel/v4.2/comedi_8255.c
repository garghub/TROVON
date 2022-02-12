static int subdev_8255_io(struct comedi_device *dev,
int dir, int port, int data, unsigned long regbase)
{
if (dir) {
outb(data, dev->iobase + regbase + port);
return 0;
}
return inb(dev->iobase + regbase + port);
}
static int subdev_8255_mmio(struct comedi_device *dev,
int dir, int port, int data, unsigned long regbase)
{
if (dir) {
writeb(data, dev->mmio + regbase + port);
return 0;
}
return readb(dev->mmio + regbase + port);
}
static int subdev_8255_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct subdev_8255_private *spriv = s->private;
unsigned long regbase = spriv->regbase;
unsigned int mask;
unsigned int v;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0xff)
spriv->io(dev, 1, I8255_DATA_A_REG,
s->state & 0xff, regbase);
if (mask & 0xff00)
spriv->io(dev, 1, I8255_DATA_B_REG,
(s->state >> 8) & 0xff, regbase);
if (mask & 0xff0000)
spriv->io(dev, 1, I8255_DATA_C_REG,
(s->state >> 16) & 0xff, regbase);
}
v = spriv->io(dev, 0, I8255_DATA_A_REG, 0, regbase);
v |= (spriv->io(dev, 0, I8255_DATA_B_REG, 0, regbase) << 8);
v |= (spriv->io(dev, 0, I8255_DATA_C_REG, 0, regbase) << 16);
data[1] = v;
return insn->n;
}
static void subdev_8255_do_config(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct subdev_8255_private *spriv = s->private;
unsigned long regbase = spriv->regbase;
int config;
config = I8255_CTRL_CW;
if (!(s->io_bits & 0x0000ff))
config |= I8255_CTRL_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= I8255_CTRL_B_IO;
if (!(s->io_bits & 0x0f0000))
config |= I8255_CTRL_C_LO_IO;
if (!(s->io_bits & 0xf00000))
config |= I8255_CTRL_C_HI_IO;
spriv->io(dev, 1, I8255_CTRL_REG, config, regbase);
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
static int __subdev_8255_init(struct comedi_device *dev,
struct comedi_subdevice *s,
int (*io)(struct comedi_device *dev,
int dir, int port, int data,
unsigned long regbase),
unsigned long regbase,
bool is_mmio)
{
struct subdev_8255_private *spriv;
spriv = comedi_alloc_spriv(s, sizeof(*spriv));
if (!spriv)
return -ENOMEM;
if (io)
spriv->io = io;
else if (is_mmio)
spriv->io = subdev_8255_mmio;
else
spriv->io = subdev_8255_io;
spriv->regbase = regbase;
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
int subdev_8255_init(struct comedi_device *dev, struct comedi_subdevice *s,
int (*io)(struct comedi_device *dev, int dir, int port,
int data, unsigned long regbase),
unsigned long regbase)
{
return __subdev_8255_init(dev, s, io, regbase, false);
}
int subdev_8255_mm_init(struct comedi_device *dev, struct comedi_subdevice *s,
int (*io)(struct comedi_device *dev, int dir, int port,
int data, unsigned long regbase),
unsigned long regbase)
{
return __subdev_8255_init(dev, s, io, regbase, true);
}
unsigned long subdev_8255_regbase(struct comedi_subdevice *s)
{
struct subdev_8255_private *spriv = s->private;
return spriv->regbase;
}
static int __init comedi_8255_module_init(void)
{
return 0;
}
static void __exit comedi_8255_module_exit(void)
{
}
