static int labpc_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
int ret;
dev->board_ptr = &labpc_cs_boards[0];
link->config_flags |= CONF_AUTO_SET_IO |
CONF_ENABLE_IRQ | CONF_ENABLE_PULSE_IRQ;
ret = comedi_pcmcia_enable(dev, NULL);
if (ret)
return ret;
dev->iobase = link->resource[0]->start;
if (!link->irq)
return -EINVAL;
return labpc_common_attach(dev, link->irq, IRQF_SHARED);
}
static int labpc_cs_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_labpc_cs);
}
