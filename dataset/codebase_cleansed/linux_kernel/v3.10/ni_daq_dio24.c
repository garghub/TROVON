static int dio24_auto_attach(struct comedi_device *dev,
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
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
ret = subdev_8255_init(dev, s, NULL, dev->iobase);
if (ret)
return ret;
return 0;
}
static void dio24_detach(struct comedi_device *dev)
{
comedi_spriv_free(dev, 0);
comedi_pcmcia_disable(dev);
}
static int dio24_cs_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_dio24);
}
