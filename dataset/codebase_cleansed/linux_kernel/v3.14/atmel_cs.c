static int atmel_probe(struct pcmcia_device *p_dev)
{
local_info_t *local;
dev_dbg(&p_dev->dev, "atmel_attach()\n");
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local)
return -ENOMEM;
p_dev->priv = local;
return atmel_config(p_dev);
}
static void atmel_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "atmel_detach\n");
atmel_release(link);
kfree(link->priv);
}
static int card_present(void *arg)
{
struct pcmcia_device *link = (struct pcmcia_device *)arg;
if (pcmcia_dev_present(link))
return 1;
return 0;
}
static int atmel_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int atmel_config(struct pcmcia_device *link)
{
local_info_t *dev;
int ret;
const struct pcmcia_device_id *did;
dev = link->priv;
did = dev_get_drvdata(&link->dev);
dev_dbg(&link->dev, "atmel_config\n");
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;
if (pcmcia_loop_config(link, atmel_config_check, NULL))
goto failed;
if (!link->irq) {
dev_err(&link->dev, "atmel: cannot assign IRQ: check that CONFIG_ISA is set in kernel config.");
goto failed;
}
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
((local_info_t*)link->priv)->eth_dev =
init_atmel_card(link->irq,
link->resource[0]->start,
did ? did->driver_info : ATMEL_FW_TYPE_NONE,
&link->dev,
card_present,
link);
if (!((local_info_t*)link->priv)->eth_dev)
goto failed;
return 0;
failed:
atmel_release(link);
return -ENODEV;
}
static void atmel_release(struct pcmcia_device *link)
{
struct net_device *dev = ((local_info_t*)link->priv)->eth_dev;
dev_dbg(&link->dev, "atmel_release\n");
if (dev)
stop_atmel_card(dev);
((local_info_t*)link->priv)->eth_dev = NULL;
pcmcia_disable_device(link);
}
static int atmel_suspend(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
netif_device_detach(local->eth_dev);
return 0;
}
static int atmel_resume(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
atmel_open(local->eth_dev);
netif_device_attach(local->eth_dev);
return 0;
}
