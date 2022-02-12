static int airo_probe(struct pcmcia_device *p_dev)
{
local_info_t *local;
dev_dbg(&p_dev->dev, "airo_attach()\n");
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
p_dev->priv = local;
return airo_config(p_dev);
}
static void airo_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "airo_detach\n");
airo_release(link);
if (((local_info_t *)link->priv)->eth_dev) {
stop_airo_card(((local_info_t *)link->priv)->eth_dev, 0);
}
((local_info_t *)link->priv)->eth_dev = NULL;
kfree(link->priv);
}
static int airo_cs_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int airo_config(struct pcmcia_device *link)
{
local_info_t *dev;
int ret;
dev = link->priv;
dev_dbg(&link->dev, "airo_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, airo_cs_config_check, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
((local_info_t *)link->priv)->eth_dev =
init_airo_card(link->irq,
link->resource[0]->start, 1, &link->dev);
if (!((local_info_t *)link->priv)->eth_dev)
goto failed;
return 0;
failed:
airo_release(link);
return -ENODEV;
}
static void airo_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "airo_release\n");
pcmcia_disable_device(link);
}
static int airo_suspend(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
netif_device_detach(local->eth_dev);
return 0;
}
static int airo_resume(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
if (link->open) {
reset_airo_card(local->eth_dev);
netif_device_attach(local->eth_dev);
}
return 0;
}
