static int compute_buffer(int config, int devno, struct comedi_subdevice *s)
{
if (s->io_bits & 0x0000ff) {
if (devno == 0)
config |= PCM3724_DIO_DIR_A0_OUT;
else
config |= PCM3724_DIO_DIR_A1_OUT;
}
if (s->io_bits & 0x00ff00) {
if (devno == 0)
config |= PCM3724_DIO_DIR_B0_OUT;
else
config |= PCM3724_DIO_DIR_B1_OUT;
}
if (s->io_bits & 0xff0000) {
if (devno == 0)
config |= PCM3724_DIO_DIR_C0_OUT;
else
config |= PCM3724_DIO_DIR_C1_OUT;
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
config = I8255_CTRL_CW;
buffer_config = 0;
if (!(s->io_bits & 0x0000ff))
config |= I8255_CTRL_A_IO;
if (!(s->io_bits & 0x00ff00))
config |= I8255_CTRL_B_IO;
if (!(s->io_bits & 0xff0000))
config |= I8255_CTRL_C_HI_IO | I8255_CTRL_C_LO_IO;
buffer_config = compute_buffer(0, 0, s_dio1);
buffer_config = compute_buffer(buffer_config, 1, s_dio2);
if (s == s_dio1)
port_8255_cfg = dev->iobase + I8255_CTRL_REG;
else
port_8255_cfg = dev->iobase + I8255_SIZE + I8255_CTRL_REG;
outb(buffer_config, dev->iobase + PCM3724_DIO_DIR_REG);
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
gatecfg |= PCM3724_GATE_CTRL_C0_ENA;
if (priv->dio_1 & 0xff00)
gatecfg |= PCM3724_GATE_CTRL_B0_ENA;
if (priv->dio_1 & 0xff)
gatecfg |= PCM3724_GATE_CTRL_A0_ENA;
if (priv->dio_2 & 0xff0000)
gatecfg |= PCM3724_GATE_CTRL_C1_ENA;
if (priv->dio_2 & 0xff00)
gatecfg |= PCM3724_GATE_CTRL_B1_ENA;
if (priv->dio_2 & 0xff)
gatecfg |= PCM3724_GATE_CTRL_A1_ENA;
outb(gatecfg, dev->iobase + PCM3724_GATE_CTRL_REG);
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
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
for (i = 0; i < dev->n_subdevices; i++) {
s = &dev->subdevices[i];
ret = subdev_8255_init(dev, s, NULL, i * I8255_SIZE);
if (ret)
return ret;
s->insn_config = subdev_3724_insn_config;
}
return 0;
}
