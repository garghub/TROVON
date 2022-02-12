static int das08_cs_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int ret;
unsigned long iobase;
struct pcmcia_device *link = cur_dev;
ret = alloc_private(dev, sizeof(struct das08_private_struct));
if (ret < 0)
return ret;
printk("comedi%d: das08_cs: ", dev->minor);
if (thisboard->bustype == pcmcia) {
if (link == NULL) {
printk(" no pcmcia cards found\n");
return -EIO;
}
iobase = link->resource[0]->start;
} else {
printk(" bug! board does not have PCMCIA bustype\n");
return -EINVAL;
}
printk("\n");
return das08_common_attach(dev, iobase);
}
static int das08_pcmcia_attach(struct pcmcia_device *link)
{
struct local_info_t *local;
dev_dbg(&link->dev, "das08_pcmcia_attach()\n");
local = kzalloc(sizeof(struct local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->link = link;
link->priv = local;
cur_dev = link;
das08_pcmcia_config(link);
return 0;
}
static void das08_pcmcia_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "das08_pcmcia_detach\n");
((struct local_info_t *)link->priv)->stop = 1;
das08_pcmcia_release(link);
kfree(link->priv);
}
static int das08_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static void das08_pcmcia_config(struct pcmcia_device *link)
{
int ret;
dev_dbg(&link->dev, "das08_pcmcia_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, das08_pcmcia_config_loop, NULL);
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
das08_pcmcia_release(link);
}
static void das08_pcmcia_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "das08_pcmcia_release\n");
pcmcia_disable_device(link);
}
static int das08_pcmcia_suspend(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 1;
return 0;
}
static int das08_pcmcia_resume(struct pcmcia_device *link)
{
struct local_info_t *local = link->priv;
local->stop = 0;
return 0;
}
static int __init init_das08_pcmcia_cs(void)
{
pcmcia_register_driver(&das08_cs_driver);
return 0;
}
static void __exit exit_das08_pcmcia_cs(void)
{
pr_debug("das08_pcmcia_cs: unloading\n");
pcmcia_unregister_driver(&das08_cs_driver);
}
static int __init das08_cs_init_module(void)
{
int ret;
ret = init_das08_pcmcia_cs();
if (ret < 0)
return ret;
return comedi_driver_register(&driver_das08_cs);
}
static void __exit das08_cs_exit_module(void)
{
exit_das08_pcmcia_cs();
comedi_driver_unregister(&driver_das08_cs);
}
