static int aio_aio12_8_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + AIO12_8_STATUS_REG);
if (status & AIO12_8_STATUS_ADC_EOC)
return 0;
return -EBUSY;
}
static int aio_aio12_8_ai_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
unsigned char control;
int ret;
int i;
control = AIO12_8_ADC_MODE_NORMAL | AIO12_8_ADC_ACQ_3USEC |
AIO12_8_ADC_RANGE(range) | AIO12_8_ADC_CHAN(chan);
inb(dev->iobase + AIO12_8_STATUS_REG);
for (i = 0; i < insn->n; i++) {
outb(control, dev->iobase + AIO12_8_ADC_REG);
ret = comedi_timeout(dev, s, insn, aio_aio12_8_ai_eoc, 0);
if (ret)
return ret;
val = inw(dev->iobase + AIO12_8_ADC_REG) & s->maxdata;
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
data[i] = val;
}
return insn->n;
}
static int aio_aio12_8_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
outb(AIO12_8_DAC_ENABLE_REF_ENA, dev->iobase + AIO12_8_DAC_ENABLE_REG);
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + AIO12_8_DAC_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int aio_aio12_8_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_GET_CLOCK_SRC:
data[0] = 0;
data[1] = (chan == 1) ? I8254_OSC_BASE_1MHZ : 0;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int aio_aio12_8_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct aio12_8_boardtype *board = dev->board_ptr;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 32);
if (ret)
return ret;
dev->pacer = comedi_8254_init(dev->iobase + AIO12_8_8254_BASE_REG,
0, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board->has_ai) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 8;
s->maxdata = 0x0fff;
s->range_table = &aio_aio12_8_range;
s->insn_read = aio_aio12_8_ai_read;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->range_table = &aio_aio12_8_range;
s->insn_write = aio_aio12_8_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL, AIO12_8_8255_BASE_REG);
if (ret)
return ret;
s = &dev->subdevices[3];
comedi_8254_subdevice_init(s, dev->pacer);
dev->pacer->insn_config = aio_aio12_8_counter_insn_config;
return 0;
}
