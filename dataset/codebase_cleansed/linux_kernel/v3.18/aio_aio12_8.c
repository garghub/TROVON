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
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned char control;
int ret;
int n;
control = AIO12_8_ADC_MODE_NORMAL | AIO12_8_ADC_ACQ_3USEC |
AIO12_8_ADC_RANGE(range) | AIO12_8_ADC_CHAN(chan);
inb(dev->iobase + AIO12_8_STATUS_REG);
for (n = 0; n < insn->n; n++) {
outb(control, dev->iobase + AIO12_8_ADC_REG);
ret = comedi_timeout(dev, s, insn, aio_aio12_8_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(dev->iobase + AIO12_8_ADC_REG) & s->maxdata;
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
static int aio_aio12_8_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct aio12_8_boardtype *board = dev->board_ptr;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 32);
if (ret)
return ret;
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
s->insn_write = aio_aio12_8_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
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
s->type = COMEDI_SUBD_UNUSED;
return 0;
}
