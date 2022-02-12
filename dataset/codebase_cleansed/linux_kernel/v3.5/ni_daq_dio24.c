static int dio24_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase = 0;
#ifdef incomplete
unsigned int irq = 0;
#endif
struct pcmcia_device *link;
if (alloc_private(dev, sizeof(struct dio24_private)) < 0)
return -ENOMEM;
switch (thisboard->bustype) {
case pcmcia_bustype:
link = pcmcia_cur_dev;
if (!link)
return -EIO;
iobase = link->resource[0]->start;
#ifdef incomplete
irq = link->irq;
#endif
break;
default:
pr_err("bug! couldn't determine board type\n");
return -EINVAL;
break;
}
pr_debug("comedi%d: ni_daq_dio24: %s, io 0x%lx", dev->minor,
thisboard->name, iobase);
#ifdef incomplete
if (irq)
pr_debug("irq %u\n", irq);
#endif
if (iobase == 0) {
pr_err("io base address is zero!\n");
return -EINVAL;
}
dev->iobase = iobase;
#ifdef incomplete
dev->irq = irq;
#endif
dev->board_name = thisboard->name;
if (alloc_subdevices(dev, 1) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
subdev_8255_init(dev, s, NULL, dev->iobase);
return 0;
}
static void dio24_detach(struct comedi_device *dev)
{
if (dev->subdevices)
subdev_8255_cleanup(dev, dev->subdevices + 0);
if (thisboard->bustype != pcmcia_bustype && dev->iobase)
release_region(dev->iobase, DIO24_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
}
static int dio24_cs_attach(struct pcmcia_device *link)
{
struct local_info_t *local;
printk(KERN_INFO "ni_daq_dio24: HOLA SOY YO - CS-attach!\n");
dev_dbg(&link->dev, "dio24_cs_attach()\n");
local = kzalloc(sizeof(struct local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->link = link;
link->priv = local;
pcmcia_cur_dev = link;
dio24_config(link);
return 0;
}
static void dio24_cs_detach(struct pcmcia_device *link)
{
((struct local_info_t *)link->priv)->stop = 1;
dio24_release(link);
kfree(link->priv);
}
static int dio24_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static void dio24_config(struct pcmcia_device *link)
{
int ret;
printk(KERN_INFO "ni_daq_dio24: HOLA SOY YO! - config\n");
dev_dbg(&link->dev, "dio24_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_AUDIO |
CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, dio24_pcmcia_config_loop, NULL);
if (ret) {
dev_warn(&link->dev, "no configuration found\n");
goto failed;
}
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
return;
failed:
printk(KERN_INFO "Fallo");
dio24_release(link);
}
static void dio24_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "dio24_release\n");
pcmcia_disable_device(link);
}
static int dio24_cs_suspend(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 1;
return 0;
}
static int dio24_cs_resume(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 0;
return 0;
}
static int __init init_dio24_cs(void)
{
printk("ni_daq_dio24: HOLA SOY YO!\n");
pcmcia_register_driver(&dio24_cs_driver);
return 0;
}
static void __exit exit_dio24_cs(void)
{
pcmcia_unregister_driver(&dio24_cs_driver);
}
int __init init_module(void)
{
int ret;
ret = init_dio24_cs();
if (ret < 0)
return ret;
return comedi_driver_register(&driver_dio24);
}
void __exit cleanup_module(void)
{
exit_dio24_cs();
comedi_driver_unregister(&driver_dio24);
}
