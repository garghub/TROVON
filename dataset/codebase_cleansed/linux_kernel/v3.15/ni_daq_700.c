static int daq700_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0xff)
outb(s->state & 0xff, dev->iobase + DIO_W);
}
val = s->state & 0xff;
val |= inb(dev->iobase + DIO_R) << 8;
data[1] = val;
return insn->n;
}
static int daq700_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
s->io_bits = 0x00ff;
return insn->n;
}
static int daq700_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + STA_R2);
if ((status & 0x03))
return -EOVERFLOW;
status = inb(dev->iobase + STA_R1);
if ((status & 0x02))
return -ENODATA;
if ((status & 0x11) == 0x01)
return 0;
return -EBUSY;
}
static int daq700_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, chan;
int d;
int ret;
chan = CR_CHAN(insn->chanspec);
outb(chan | 0x80, dev->iobase + CMD_R1);
udelay(2);
for (n = 0; n < insn->n; n++) {
outb(0x00, dev->iobase + CMD_R2);
outb(0x30, dev->iobase + CMO_R);
outb(0x32, dev->iobase + CMO_R);
ret = comedi_timeout(dev, s, insn, daq700_ai_eoc, 0);
if (ret)
return ret;
d = inw(dev->iobase + ADFIFO_R);
d &= 0x0fff;
d ^= 0x0800;
data[n] = d;
}
return n;
}
static void daq700_ai_config(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned long iobase = dev->iobase;
outb(0x80, iobase + CMD_R1);
outb(0x00, iobase + CMD_R2);
outb(0x00, iobase + CMD_R3);
outb(0x32, iobase + CMO_R);
outb(0x00, iobase + TIC_R);
outb(0x00, iobase + ADCLEAR_R);
inw(iobase + ADFIFO_R);
}
static int daq700_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
struct comedi_subdevice *s;
int ret;
link->config_flags |= CONF_AUTO_SET_IO;
ret = comedi_pcmcia_enable(dev, NULL);
if (ret)
return ret;
dev->iobase = link->resource[0]->start;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = daq700_dio_insn_bits;
s->insn_config = daq700_dio_insn_config;
s->io_bits = 0x00ff;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_bipolar10;
s->insn_read = daq700_ai_rinsn;
daq700_ai_config(dev, s);
return 0;
}
static int daq700_cs_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &daq700_driver);
}
