static int aio_aio12_8_ai_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
unsigned char control;
int n;
control = AIO12_8_ADC_MODE_NORMAL | AIO12_8_ADC_ACQ_3USEC |
AIO12_8_ADC_RANGE(range) | AIO12_8_ADC_CHAN(chan);
inb(dev->iobase + AIO12_8_STATUS_REG);
for (n = 0; n < insn->n; n++) {
int timeout = 5;
outb(control, dev->iobase + AIO12_8_ADC_REG);
do {
val = inb(dev->iobase + AIO12_8_STATUS_REG);
timeout--;
if (timeout == 0) {
dev_err(dev->class_dev, "ADC timeout\n");
return -ETIMEDOUT;
}
} while (!(val & AIO12_8_STATUS_ADC_EOC));
data[n] = inw(dev->iobase + AIO12_8_ADC_REG) & s->maxdata;
}
return insn->n;
}
static int aio_aio12_8_ao_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct aio12_8_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int val = devpriv->ao_readback[chan];
int i;
for (i = 0; i < insn->n; i++)
data[i] = val;
return insn->n;
}
static int aio_aio12_8_ao_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct aio12_8_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long port = dev->iobase + AIO12_8_DAC_REG(chan);
unsigned int val = 0;
int i;
outb(AIO12_8_DAC_ENABLE_REF_ENA, dev->iobase + AIO12_8_DAC_ENABLE_REG);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, port);
}
devpriv->ao_readback[chan] = val;
return insn->n;
}
static int aio_aio12_8_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct aio12_8_boardtype *board = comedi_board(dev);
struct aio12_8_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 32);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board->ai_nchan) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = board->ai_nchan;
s->maxdata = 0x0fff;
s->range_table = &range_aio_aio12_8;
s->insn_read = aio_aio12_8_ai_read;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (board->ao_nchan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->range_table = &range_aio_aio12_8;
s->insn_read = aio_aio12_8_ao_read;
s->insn_write = aio_aio12_8_ao_write;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL,
dev->iobase + AIO12_8_8255_BASE_REG);
if (ret)
return ret;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_UNUSED;
dev_info(dev->class_dev, "%s: %s attached\n",
dev->driver->driver_name, dev->board_name);
return 0;
}
