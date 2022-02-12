static int daq700_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
if (data[0] & 0xff)
outb(s->state & 0xff, dev->iobase + DIO_W);
}
data[1] = s->state & 0xff;
data[1] |= inb(dev->iobase + DIO_R) << 8;
return insn->n;
}
static int daq700_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = 1 << CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
break;
case INSN_CONFIG_DIO_OUTPUT:
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & chan) ? COMEDI_OUTPUT : COMEDI_INPUT;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int daq700_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, i, chan;
int d;
unsigned int status;
enum { TIMEOUT = 100 };
chan = CR_CHAN(insn->chanspec);
outb(chan | 0x80, dev->iobase + CMD_R1);
for (n = 0; n < insn->n; n++) {
outb(0x00, dev->iobase + CMD_R2);
outb(0x30, dev->iobase + CMO_R);
outb(0x32, dev->iobase + CMO_R);
for (i = 0; i < TIMEOUT; i++) {
status = inb(dev->iobase + STA_R2);
if ((status & 0x03) != 0) {
dev_info(dev->class_dev,
"Overflow/run Error\n");
return -EOVERFLOW;
}
status = inb(dev->iobase + STA_R1);
if ((status & 0x02) != 0) {
dev_info(dev->class_dev, "Data Error\n");
return -ENODATA;
}
if ((status & 0x11) == 0x01) {
break;
}
udelay(1);
}
if (i == TIMEOUT) {
dev_info(dev->class_dev,
"timeout during ADC conversion\n");
return -ETIMEDOUT;
}
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
static int daq700_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct daq700_board *thisboard = comedi_board(dev);
struct comedi_subdevice *s;
struct pcmcia_device *link;
int ret;
link = pcmcia_cur_dev;
if (!link)
return -EIO;
dev->iobase = link->resource[0]->start;
if (!dev->iobase) {
dev_err(dev->class_dev, "io base address is zero!\n");
return -EINVAL;
}
dev->board_name = thisboard->name;
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
s->state = 0;
s->io_bits = 0x00ff;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_bipolar10;
s->insn_read = daq700_ai_rinsn;
daq700_ai_config(dev, s);
dev_info(dev->class_dev, "%s: %s, io 0x%lx\n",
dev->driver->driver_name,
dev->board_name,
dev->iobase);
return 0;
}
static void daq700_detach(struct comedi_device *dev)
{
}
static int daq700_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int daq700_cs_attach(struct pcmcia_device *link)
{
int ret;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_AUDIO |
CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, daq700_pcmcia_config_loop, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
pcmcia_cur_dev = link;
return 0;
failed:
pcmcia_disable_device(link);
return ret;
}
static void daq700_cs_detach(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
pcmcia_cur_dev = NULL;
}
static int __init daq700_cs_init(void)
{
int ret;
ret = comedi_driver_register(&daq700_driver);
if (ret < 0)
return ret;
ret = pcmcia_register_driver(&daq700_cs_driver);
if (ret < 0) {
comedi_driver_unregister(&daq700_driver);
return ret;
}
return 0;
}
static void __exit daq700_cs_exit(void)
{
pcmcia_unregister_driver(&daq700_cs_driver);
comedi_driver_unregister(&daq700_driver);
}
