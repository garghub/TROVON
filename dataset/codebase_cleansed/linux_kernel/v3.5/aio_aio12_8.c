static int aio_aio12_8_ai_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
unsigned char control =
ADC_MODE_NORMAL |
(CR_RANGE(insn->chanspec) << 3) | CR_CHAN(insn->chanspec);
inb(dev->iobase + AIO12_8_STATUS);
for (n = 0; n < insn->n; n++) {
int timeout = 5;
outb(control, dev->iobase + AIO12_8_ADC);
while (timeout &&
!(inb(dev->iobase + AIO12_8_STATUS) & STATUS_ADC_EOC)) {
timeout--;
printk(KERN_ERR "timeout %d\n", timeout);
udelay(1);
}
if (timeout == 0) {
comedi_error(dev, "ADC timeout");
return -EIO;
}
data[n] = inw(dev->iobase + AIO12_8_ADC) & 0x0FFF;
}
return n;
}
static int aio_aio12_8_ao_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int val = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
for (i = 0; i < insn->n; i++)
data[i] = val;
return insn->n;
}
static int aio_aio12_8_ao_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
unsigned long port = dev->iobase + AIO12_8_DAC_0 + (2 * chan);
outb(0x01, dev->iobase + DAC_ENABLE);
for (i = 0; i < insn->n; i++) {
outb(data[i] & 0xFF, port);
outb((data[i] >> 8) & 0x0F, port + 1);
devpriv->ao_readback[chan] = data[i];
}
return insn->n;
}
static int aio_aio12_8_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int iobase;
struct comedi_subdevice *s;
iobase = it->options[0];
if (!request_region(iobase, 24, "aio_aio12_8")) {
printk(KERN_ERR "I/O port conflict");
return -EIO;
}
dev->board_name = thisboard->name;
dev->iobase = iobase;
if (alloc_private(dev, sizeof(struct aio12_8_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 3) < 0)
return -ENOMEM;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 8;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_aio_aio12_8;
s->insn_read = aio_aio12_8_ai_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 4;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_aio_aio12_8;
s->insn_read = aio_aio12_8_ao_read;
s->insn_write = aio_aio12_8_ao_write;
s = &dev->subdevices[2];
subdev_8255_init(dev, s, NULL, dev->iobase + AIO12_8_DIO_0);
return 0;
}
static void aio_aio12_8_detach(struct comedi_device *dev)
{
subdev_8255_cleanup(dev, &dev->subdevices[2]);
if (dev->iobase)
release_region(dev->iobase, 24);
}
