static void ft1000_reset(struct pcmcia_device * link)
{
pcmcia_reset_card(link->socket);
}
static int ft1000_attach(struct pcmcia_device *link)
{
local_info_t *local;
DEBUG(0, "ft1000_cs: ft1000_attach()\n");
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local) {
return -ENOMEM;
}
local->link = link;
link->priv = local;
local->dev = NULL;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
return ft1000_config(link);
}
static void ft1000_detach(struct pcmcia_device *link)
{
struct net_device *dev = ((local_info_t *) link->priv)->dev;
DEBUG(0, "ft1000_cs: ft1000_detach(0x%p)\n", link);
if (link == NULL) {
DEBUG(0,"ft1000_cs:ft1000_detach: Got a NULL pointer\n");
return;
}
if (dev) {
stop_ft1000_card(dev);
}
pcmcia_disable_device(link);
free_netdev(dev);
}
int ft1000_confcheck(struct pcmcia_device *link, void *priv_data)
{
return pcmcia_request_io(link);
}
static int ft1000_config(struct pcmcia_device *link)
{
int ret;
dev_dbg(&link->dev, "ft1000_cs: ft1000_config(0x%p)\n", link);
ret = pcmcia_loop_config(link, ft1000_confcheck, NULL);
if (ret) {
printk(KERN_INFO "ft1000: Could not configure pcmcia\n");
return -ENODEV;
}
ret = pcmcia_enable_device(link);
if (ret) {
printk(KERN_INFO "ft1000: could not enable pcmcia\n");
goto failed;
}
((local_info_t *) link->priv)->dev = init_ft1000_card(link,
&ft1000_reset);
if (((local_info_t *) link->priv)->dev == NULL) {
printk(KERN_INFO "ft1000: Could not register as network device\n");
goto failed;
}
return 0;
failed:
ft1000_release(link);
return -ENODEV;
}
static void ft1000_release(struct pcmcia_device * link)
{
DEBUG(0, "ft1000_cs: ft1000_release(0x%p)\n", link);
kfree((local_info_t *) link->priv);
pcmcia_disable_device(link);
}
static int ft1000_suspend(struct pcmcia_device *link)
{
struct net_device *dev = ((local_info_t *) link->priv)->dev;
DEBUG(1, "ft1000_cs: ft1000_event(0x%06x)\n", event);
if (link->open)
netif_device_detach(dev);
return 0;
}
static int ft1000_resume(struct pcmcia_device *link)
{
return 0;
}
static int __init init_ft1000_cs(void)
{
DEBUG(0, "ft1000_cs: loading\n");
return pcmcia_register_driver(&ft1000_cs_driver);
}
static void __exit exit_ft1000_cs(void)
{
DEBUG(0, "ft1000_cs: unloading\n");
pcmcia_unregister_driver(&ft1000_cs_driver);
}
