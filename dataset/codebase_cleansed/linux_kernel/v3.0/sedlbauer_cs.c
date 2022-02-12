static int __devinit sedlbauer_probe(struct pcmcia_device *link)
{
local_info_t *local;
dev_dbg(&link->dev, "sedlbauer_attach()\n");
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local) return -ENOMEM;
local->cardnr = -1;
local->p_dev = link;
link->priv = local;
return sedlbauer_config(link);
}
static void __devexit sedlbauer_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "sedlbauer_detach(0x%p)\n", link);
((local_info_t *)link->priv)->stop = 1;
sedlbauer_release(link);
kfree(link->priv);
}
static int sedlbauer_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
p_dev->io_lines = 3;
return pcmcia_request_io(p_dev);
}
static int __devinit sedlbauer_config(struct pcmcia_device *link)
{
int ret;
IsdnCard_t icard;
dev_dbg(&link->dev, "sedlbauer_config(0x%p)\n", link);
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_CHECK_VCC |
CONF_AUTO_SET_VPP | CONF_AUTO_AUDIO | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, sedlbauer_config_check, NULL);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
icard.para[0] = link->irq;
icard.para[1] = link->resource[0]->start;
icard.protocol = protocol;
icard.typ = ISDN_CTYPE_SEDLBAUER_PCMCIA;
ret = hisax_init_pcmcia(link,
&(((local_info_t *)link->priv)->stop), &icard);
if (ret < 0) {
printk(KERN_ERR "sedlbauer_cs: failed to initialize SEDLBAUER PCMCIA %d with %pR\n",
ret, link->resource[0]);
sedlbauer_release(link);
return -ENODEV;
} else
((local_info_t *)link->priv)->cardnr = ret;
return 0;
failed:
sedlbauer_release(link);
return -ENODEV;
}
static void sedlbauer_release(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
dev_dbg(&link->dev, "sedlbauer_release(0x%p)\n", link);
if (local) {
if (local->cardnr >= 0) {
HiSax_closecard(local->cardnr);
}
}
pcmcia_disable_device(link);
}
static int sedlbauer_suspend(struct pcmcia_device *link)
{
local_info_t *dev = link->priv;
dev->stop = 1;
return 0;
}
static int sedlbauer_resume(struct pcmcia_device *link)
{
local_info_t *dev = link->priv;
dev->stop = 0;
return 0;
}
static int __init init_sedlbauer_cs(void)
{
return pcmcia_register_driver(&sedlbauer_driver);
}
static void __exit exit_sedlbauer_cs(void)
{
pcmcia_unregister_driver(&sedlbauer_driver);
}
