static int subdev_8255_cb(int dir, int port, int data, unsigned long arg)
{
unsigned long iobase = arg;
unsigned char inbres;
if (dir) {
outb(data, iobase + port);
return 0;
} else {
inbres = inb(iobase + port);
return inbres;
}
}
static int compute_buffer(int config, int devno, struct comedi_subdevice *s)
{
if (s->io_bits & 0x0000ff) {
if (devno == 0)
config |= BUF_A0;
else
config |= BUF_A1;
}
if (s->io_bits & 0x00ff00) {
if (devno == 0)
config |= BUF_B0;
else
config |= BUF_B1;
}
if (s->io_bits & 0xff0000) {
if (devno == 0)
config |= BUF_C0;
else
config |= BUF_C1;
}
return config;
}
static void do_3724_config(struct comedi_device *dev,
struct comedi_subdevice *s, int chanspec)
{
struct comedi_subdevice *s_dio1 = &dev->subdevices[0];
struct comedi_subdevice *s_dio2 = &dev->subdevices[1];
int config;
int buffer_config;
unsigned long port_8255_cfg;
config = CR_CW;
buffer_config = 0;
if (!(s->io_bits & 0x0000ff))
config |= CR_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= CR_B_IO;
if (!(s->io_bits & 0xff0000))
config |= CR_C_IO;
buffer_config = compute_buffer(0, 0, s_dio1);
buffer_config = compute_buffer(buffer_config, 1, s_dio2);
if (s == s_dio1)
port_8255_cfg = dev->iobase + _8255_CR;
else
port_8255_cfg = dev->iobase + SIZE_8255 + _8255_CR;
outb(buffer_config, dev->iobase + 8);
outb(config, port_8255_cfg);
}
static void enable_chan(struct comedi_device *dev, struct comedi_subdevice *s,
int chanspec)
{
struct priv_pcm3724 *priv = dev->private;
struct comedi_subdevice *s_dio1 = &dev->subdevices[0];
unsigned int mask;
int gatecfg;
gatecfg = 0;
mask = 1 << CR_CHAN(chanspec);
if (s == s_dio1)
priv->dio_1 |= mask;
else
priv->dio_2 |= mask;
if (priv->dio_1 & 0xff0000)
gatecfg |= GATE_C0;
if (priv->dio_1 & 0xff00)
gatecfg |= GATE_B0;
if (priv->dio_1 & 0xff)
gatecfg |= GATE_A0;
if (priv->dio_2 & 0xff0000)
gatecfg |= GATE_C1;
if (priv->dio_2 & 0xff00)
gatecfg |= GATE_B1;
if (priv->dio_2 & 0xff)
gatecfg |= GATE_A1;
outb(gatecfg, dev->iobase + 9);
}
static int subdev_3724_insn_config(struct comedi_device *dev,
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
do_3724_config(dev, s, insn->chanspec);
enable_chan(dev, s, insn->chanspec);
return insn->n;
}
static int pcm3724_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct priv_pcm3724 *priv;
struct comedi_subdevice *s;
int ret, i;
priv = comedi_alloc_devpriv(dev, sizeof(*priv));
if (!priv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], PCM3724_SIZE);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
subdev_8255_init(dev, s, subdev_8255_cb,
(unsigned long)(dev->iobase + SIZE_8255 * i));
s->insn_config = subdev_3724_insn_config;
}
return 0;
}
