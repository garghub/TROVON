static int das08_cs_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
struct das08_private_struct *devpriv;
unsigned long iobase;
int ret;
dev->board_ptr = &das08_cs_boards[0];
link->config_flags |= CONF_AUTO_SET_IO;
ret = comedi_pcmcia_enable(dev, NULL);
if (ret)
return ret;
iobase = link->resource[0]->start;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
return das08_common_attach(dev, iobase);
}
static int das08_pcmcia_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_das08_cs);
}
