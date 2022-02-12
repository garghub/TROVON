static int ssb_host_pcmcia_probe(struct pcmcia_device *dev)
{
struct ssb_bus *ssb;
int err = -ENOMEM;
int res = 0;
ssb = kzalloc(sizeof(*ssb), GFP_KERNEL);
if (!ssb)
goto out_error;
err = -ENODEV;
dev->config_flags |= CONF_ENABLE_IRQ;
dev->resource[2]->flags |= WIN_ENABLE | WIN_DATA_WIDTH_16 |
WIN_USE_WAIT;
dev->resource[2]->start = 0;
dev->resource[2]->end = SSB_CORE_SIZE;
res = pcmcia_request_window(dev, dev->resource[2], 250);
if (res != 0)
goto err_kfree_ssb;
res = pcmcia_map_mem_page(dev, dev->resource[2], 0);
if (res != 0)
goto err_disable;
if (!dev->irq)
goto err_disable;
res = pcmcia_enable_device(dev);
if (res != 0)
goto err_disable;
err = ssb_bus_pcmciabus_register(ssb, dev, dev->resource[2]->start);
if (err)
goto err_disable;
dev->priv = ssb;
return 0;
err_disable:
pcmcia_disable_device(dev);
err_kfree_ssb:
kfree(ssb);
out_error:
ssb_err("Initialization failed (%d, %d)\n", res, err);
return err;
}
static void ssb_host_pcmcia_remove(struct pcmcia_device *dev)
{
struct ssb_bus *ssb = dev->priv;
ssb_bus_unregister(ssb);
pcmcia_disable_device(dev);
kfree(ssb);
dev->priv = NULL;
}
static int ssb_host_pcmcia_suspend(struct pcmcia_device *dev)
{
struct ssb_bus *ssb = dev->priv;
return ssb_bus_suspend(ssb);
}
static int ssb_host_pcmcia_resume(struct pcmcia_device *dev)
{
struct ssb_bus *ssb = dev->priv;
return ssb_bus_resume(ssb);
}
int ssb_host_pcmcia_init(void)
{
return pcmcia_register_driver(&ssb_host_pcmcia_driver);
}
void ssb_host_pcmcia_exit(void)
{
pcmcia_unregister_driver(&ssb_host_pcmcia_driver);
}
