static int labpc_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
unsigned long iobase = 0;
unsigned int irq = 0;
struct pcmcia_device *link;
if (alloc_private(dev, sizeof(struct labpc_private)) < 0)
return -ENOMEM;
switch (thisboard->bustype) {
case pcmcia_bustype:
link = pcmcia_cur_dev;
if (!link)
return -EIO;
iobase = link->resource[0]->start;
irq = link->irq;
break;
default:
pr_err("bug! couldn't determine board type\n");
return -EINVAL;
break;
}
return labpc_common_attach(dev, iobase, irq, 0);
}
static int labpc_cs_attach(struct pcmcia_device *link)
{
struct local_info_t *local;
dev_dbg(&link->dev, "labpc_cs_attach()\n");
local = kzalloc(sizeof(struct local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->link = link;
link->priv = local;
pcmcia_cur_dev = link;
labpc_config(link);
return 0;
}
static void labpc_cs_detach(struct pcmcia_device *link)
{
((struct local_info_t *)link->priv)->stop = 1;
labpc_release(link);
kfree(link->priv);
}
static int labpc_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static void labpc_config(struct pcmcia_device *link)
{
int ret;
dev_dbg(&link->dev, "labpc_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_ENABLE_PULSE_IRQ |
CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, labpc_pcmcia_config_loop, NULL);
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
labpc_release(link);
}
static void labpc_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "labpc_release\n");
pcmcia_disable_device(link);
}
static int labpc_cs_suspend(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 1;
return 0;
}
static int labpc_cs_resume(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 0;
return 0;
}
static int __init init_labpc_cs(void)
{
pcmcia_register_driver(&labpc_cs_driver);
return 0;
}
static void __exit exit_labpc_cs(void)
{
pcmcia_unregister_driver(&labpc_cs_driver);
}
int __init labpc_init_module(void)
{
int ret;
ret = init_labpc_cs();
if (ret < 0)
return ret;
return comedi_driver_register(&driver_labpc_cs);
}
void __exit labpc_exit_module(void)
{
exit_labpc_cs();
comedi_driver_unregister(&driver_labpc_cs);
}
