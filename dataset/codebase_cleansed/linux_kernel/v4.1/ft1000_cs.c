static void ft1000_reset(struct pcmcia_device *link)
{
pcmcia_reset_card(link->socket);
}
static int ft1000_attach(struct pcmcia_device *link)
{
link->priv = NULL;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
return ft1000_config(link);
}
static void ft1000_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (dev)
stop_ft1000_card(dev);
pcmcia_disable_device(link);
free_netdev(dev);
}
static int ft1000_confcheck(struct pcmcia_device *link, void *priv_data)
{
return pcmcia_request_io(link);
}
static int ft1000_config(struct pcmcia_device *link)
{
int ret;
dev_dbg(&link->dev, "ft1000_cs: ft1000_config(0x%p)\n", link);
ret = pcmcia_loop_config(link, ft1000_confcheck, NULL);
if (ret) {
dev_err(&link->dev, "Could not configure pcmcia\n");
return -ENODEV;
}
ret = pcmcia_enable_device(link);
if (ret) {
dev_err(&link->dev, "Could not enable pcmcia\n");
goto failed;
}
link->priv = init_ft1000_card(link, &ft1000_reset);
if (!link->priv) {
dev_err(&link->dev, "Could not register as network device\n");
goto failed;
}
return 0;
failed:
pcmcia_disable_device(link);
return -ENODEV;
}
static int ft1000_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int ft1000_resume(struct pcmcia_device *link)
{
return 0;
}
