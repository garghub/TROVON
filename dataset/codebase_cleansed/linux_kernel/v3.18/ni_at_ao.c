static void atao_select_reg_group(struct comedi_device *dev, int group)
{
struct atao_private *devpriv = dev->private;
if (group)
devpriv->cfg1 |= ATAO_CFG1_GRP2WR;
else
devpriv->cfg1 &= ~ATAO_CFG1_GRP2WR;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1_REG);
}
static int atao_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
if (chan == 0)
atao_select_reg_group(dev, 1);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(comedi_offset_munge(s, val),
dev->iobase + ATAO_AO_REG(chan));
}
s->readback[chan] = val;
if (chan == 0)
atao_select_reg_group(dev, 0);
return insn->n;
}
static int atao_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + ATAO_DIO_REG);
data[1] = inw(dev->iobase + ATAO_DIO_REG);
return insn->n;
}
static int atao_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct atao_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 4)
mask = 0x0f;
else
mask = 0xf0;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
if (s->io_bits & 0x0f)
devpriv->cfg3 |= ATAO_CFG3_DOUTEN1;
else
devpriv->cfg3 &= ~ATAO_CFG3_DOUTEN1;
if (s->io_bits & 0xf0)
devpriv->cfg3 |= ATAO_CFG3_DOUTEN2;
else
devpriv->cfg3 &= ~ATAO_CFG3_DOUTEN2;
outw(devpriv->cfg3, dev->iobase + ATAO_CFG3_REG);
return insn->n;
}
static int atao_calib_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct atao_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int bitstring;
unsigned int val;
int bit;
if (insn->n == 0)
return 0;
devpriv->caldac[chan] = data[insn->n - 1] & s->maxdata;
bitstring = ((chan & 0x7) << 8) | devpriv->caldac[chan];
for (bit = 1 << 10; bit; bit >>= 1) {
val = (bit & bitstring) ? ATAO_CFG2_SDATA : 0;
outw(val, dev->iobase + ATAO_CFG2_REG);
outw(val | ATAO_CFG2_SCLK, dev->iobase + ATAO_CFG2_REG);
}
outw(ATAO_CFG2_CALLD(chan), dev->iobase + ATAO_CFG2_REG);
outw(ATAO_CFG2_CALLD_NOP, dev->iobase + ATAO_CFG2_REG);
return insn->n;
}
static int atao_calib_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct atao_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->caldac[chan];
return insn->n;
}
static void atao_reset(struct comedi_device *dev)
{
struct atao_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + ATAO_82C53_BASE;
devpriv->cfg1 = 0;
outw(devpriv->cfg1, dev->iobase + ATAO_CFG1_REG);
i8254_set_mode(timer_base, 0, 0, I8254_MODE4 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 1, I8254_MODE4 | I8254_BINARY);
i8254_write(timer_base, 0, 0, 0x0003);
outw(ATAO_CFG2_CALLD_NOP, dev->iobase + ATAO_CFG2_REG);
devpriv->cfg3 = 0;
outw(devpriv->cfg3, dev->iobase + ATAO_CFG3_REG);
inw(dev->iobase + ATAO_FIFO_CLEAR_REG);
atao_select_reg_group(dev, 1);
outw(0, dev->iobase + ATAO_2_INT1CLR_REG);
outw(0, dev->iobase + ATAO_2_INT2CLR_REG);
outw(0, dev->iobase + ATAO_2_DMATCCLR_REG);
atao_select_reg_group(dev, 0);
}
static int atao_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct atao_board *board = dev->board_ptr;
struct atao_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x20);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_ao_chans;
s->maxdata = 0x0fff;
s->range_table = it->options[3] ? &range_unipolar10 : &range_bipolar10;
s->insn_write = atao_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = atao_dio_insn_bits;
s->insn_config = atao_dio_insn_config;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = (board->n_ao_chans * 2) + 1;
s->maxdata = 0xff;
s->insn_read = atao_calib_insn_read;
s->insn_write = atao_calib_insn_write;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_UNUSED;
atao_reset(dev);
return 0;
}
