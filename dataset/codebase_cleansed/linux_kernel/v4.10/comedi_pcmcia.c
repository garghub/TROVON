struct pcmcia_device *comedi_to_pcmcia_dev(struct comedi_device *dev)
{
return dev->hw_dev ? to_pcmcia_dev(dev->hw_dev) : NULL;
}
static int comedi_pcmcia_conf_check(struct pcmcia_device *link,
void *priv_data)
{
if (link->config_index == 0)
return -EINVAL;
return pcmcia_request_io(link);
}
int comedi_pcmcia_enable(struct comedi_device *dev,
int (*conf_check)(struct pcmcia_device *, void *))
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
int ret;
if (!link)
return -ENODEV;
if (!conf_check)
conf_check = comedi_pcmcia_conf_check;
ret = pcmcia_loop_config(link, conf_check, NULL);
if (ret)
return ret;
return pcmcia_enable_device(link);
}
void comedi_pcmcia_disable(struct comedi_device *dev)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
if (link)
pcmcia_disable_device(link);
}
int comedi_pcmcia_auto_config(struct pcmcia_device *link,
struct comedi_driver *driver)
{
return comedi_auto_config(&link->dev, driver, 0);
}
void comedi_pcmcia_auto_unconfig(struct pcmcia_device *link)
{
comedi_auto_unconfig(&link->dev);
}
int comedi_pcmcia_driver_register(struct comedi_driver *comedi_driver,
struct pcmcia_driver *pcmcia_driver)
{
int ret;
ret = comedi_driver_register(comedi_driver);
if (ret < 0)
return ret;
ret = pcmcia_register_driver(pcmcia_driver);
if (ret < 0) {
comedi_driver_unregister(comedi_driver);
return ret;
}
return 0;
}
void comedi_pcmcia_driver_unregister(struct comedi_driver *comedi_driver,
struct pcmcia_driver *pcmcia_driver)
{
pcmcia_unregister_driver(pcmcia_driver);
comedi_driver_unregister(comedi_driver);
}
static int __init comedi_pcmcia_init(void)
{
return 0;
}
static void __exit comedi_pcmcia_exit(void)
{
}
