static int subdev_700_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
if (data[0] & 0xff)
outb(s->state & 0xff, dev->iobase + DIO_W);
}
data[1] = s->state & 0xff;
data[1] |= inb(dev->iobase + DIO_R);
return insn->n;
}
static int subdev_700_insn_config(struct comedi_device *dev,
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
static int dio700_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dio700_board *thisboard = comedi_board(dev);
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
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = subdev_700_insn;
s->insn_config = subdev_700_insn_config;
s->state = 0;
s->io_bits = 0x00ff;
dev_info(dev->class_dev, "%s: %s, io 0x%lx\n",
dev->driver->driver_name,
dev->board_name,
dev->iobase);
return 0;
}
static void dio700_detach(struct comedi_device *dev)
{
}
static int dio700_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int dio700_cs_attach(struct pcmcia_device *link)
{
int ret;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_AUDIO |
CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, dio700_pcmcia_config_loop, NULL);
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
static void dio700_cs_detach(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
pcmcia_cur_dev = NULL;
}
static int __init dio700_cs_init(void)
{
int ret;
ret = comedi_driver_register(&driver_dio700);
if (ret < 0)
return ret;
ret = pcmcia_register_driver(&dio700_cs_driver);
if (ret < 0) {
comedi_driver_unregister(&driver_dio700);
return ret;
}
return 0;
}
static void __exit dio700_cs_exit(void)
{
pcmcia_unregister_driver(&dio700_cs_driver);
comedi_driver_unregister(&driver_dio700);
}
