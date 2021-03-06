static int dt2815_ao_status(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DT2815_STATUS);
if (status == context)
return 0;
return -EBUSY;
}
static int dt2815_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2815_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int dt2815_ao_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2815_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
unsigned int lo, hi;
int ret;
for (i = 0; i < insn->n; i++) {
lo = ((data[i] & 0x0f) << 4) | (chan << 1) | 0x01;
hi = (data[i] & 0xff0) >> 4;
ret = comedi_timeout(dev, s, insn, dt2815_ao_status, 0x00);
if (ret)
return ret;
outb(lo, dev->iobase + DT2815_DATA);
ret = comedi_timeout(dev, s, insn, dt2815_ao_status, 0x10);
if (ret)
return ret;
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int dt2815_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct dt2815_private *devpriv;
struct comedi_subdevice *s;
int i;
const struct comedi_lrange *current_range_type, *voltage_range_type;
int ret;
ret = comedi_request_region(dev, it->options[0], DT2815_SIZE);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 0xfff;
s->n_chan = 8;
s->insn_write = dt2815_ao_insn;
s->insn_read = dt2815_ao_insn_read;
s->range_table_list = devpriv->range_type_list;
current_range_type = (it->options[3])
? &range_4_20mA : &range_0_32mA;
voltage_range_type = (it->options[2])
? &range_bipolar5 : &range_unipolar5;
for (i = 0; i < 8; i++) {
devpriv->range_type_list[i] = (it->options[5 + i])
? current_range_type : voltage_range_type;
}
outb(0x00, dev->iobase + DT2815_STATUS);
for (i = 0; i < 100; i++) {
unsigned int status;
udelay(1000);
status = inb(dev->iobase + DT2815_STATUS);
if (status == 4) {
unsigned int program;
program = (it->options[4] & 0x3) << 3 | 0x7;
outb(program, dev->iobase + DT2815_DATA);
dev_dbg(dev->class_dev, "program: 0x%x (@t=%d)\n",
program, i);
break;
} else if (status != 0x00) {
dev_dbg(dev->class_dev,
"unexpected status 0x%x (@t=%d)\n",
status, i);
if (status & 0x60)
outb(0x00, dev->iobase + DT2815_STATUS);
}
}
return 0;
}
