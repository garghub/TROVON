static void release_platform_dev(struct device * dev)
{
dev_dbg(dev, "sl811_cs platform_dev release\n");
dev->parent = NULL;
}
static int sl811_hc_init(struct device *parent, resource_size_t base_addr,
int irq)
{
if (platform_dev.dev.parent)
return -EBUSY;
platform_dev.dev.parent = parent;
resources[0].start = irq;
resources[1].start = base_addr;
resources[1].end = base_addr;
resources[2].start = base_addr + 1;
resources[2].end = base_addr + 1;
platform_dev.name = sl811h_driver.driver.name;
return platform_device_register(&platform_dev);
}
static void sl811_cs_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "sl811_cs_detach\n");
sl811_cs_release(link);
kfree(link->priv);
}
static void sl811_cs_release(struct pcmcia_device * link)
{
dev_dbg(&link->dev, "sl811_cs_release\n");
pcmcia_disable_device(link);
platform_device_unregister(&platform_dev);
}
static int sl811_cs_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int sl811_cs_config(struct pcmcia_device *link)
{
struct device *parent = &link->dev;
int ret;
dev_dbg(&link->dev, "sl811_cs_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
CONF_AUTO_CHECK_VCC | CONF_AUTO_SET_IO;
if (pcmcia_loop_config(link, sl811_cs_config_check, NULL))
goto failed;
if (resource_size(link->resource[0]) < 2)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
if (sl811_hc_init(parent, link->resource[0]->start, link->irq)
< 0) {
failed:
printk(KERN_WARNING "sl811_cs_config failed\n");
sl811_cs_release(link);
return -ENODEV;
}
return 0;
}
static int sl811_cs_probe(struct pcmcia_device *link)
{
local_info_t *local;
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
local->p_dev = link;
link->priv = local;
return sl811_cs_config(link);
}
static int __init init_sl811_cs(void)
{
return pcmcia_register_driver(&sl811_cs_driver);
}
static void __exit exit_sl811_cs(void)
{
pcmcia_unregister_driver(&sl811_cs_driver);
}
