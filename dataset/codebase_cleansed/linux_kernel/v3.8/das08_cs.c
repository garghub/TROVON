static int das08_cs_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das08_board_struct *thisboard = comedi_board(dev);
struct das08_private_struct *devpriv;
unsigned long iobase;
struct pcmcia_device *link = cur_dev;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
dev_info(dev->class_dev, "das08_cs: attach\n");
if (thisboard->bustype == pcmcia) {
if (link == NULL) {
dev_err(dev->class_dev, "no pcmcia cards found\n");
return -EIO;
}
iobase = link->resource[0]->start;
} else {
dev_err(dev->class_dev,
"bug! board does not have PCMCIA bustype\n");
return -EINVAL;
}
return das08_common_attach(dev, iobase);
}
static int das08_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int das08_pcmcia_attach(struct pcmcia_device *link)
{
int ret;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, das08_pcmcia_config_loop, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
cur_dev = link;
return 0;
failed:
pcmcia_disable_device(link);
return ret;
}
static void das08_pcmcia_detach(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
cur_dev = NULL;
}
static int __init das08_cs_init_module(void)
{
int ret;
ret = comedi_driver_register(&driver_das08_cs);
if (ret < 0)
return ret;
ret = pcmcia_register_driver(&das08_cs_driver);
if (ret < 0) {
comedi_driver_unregister(&driver_das08_cs);
return ret;
}
return 0;
}
static void __exit das08_cs_exit_module(void)
{
pcmcia_unregister_driver(&das08_cs_driver);
comedi_driver_unregister(&driver_das08_cs);
}
