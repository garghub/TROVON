static int parport_probe(struct pcmcia_device *link)
{
parport_info_t *info;
dev_dbg(&link->dev, "parport_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) return -ENOMEM;
link->priv = info;
info->p_dev = link;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
return parport_config(link);
}
static void parport_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "parport_detach\n");
parport_cs_release(link);
kfree(link->priv);
}
static int parport_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
return pcmcia_request_io(p_dev);
}
static int parport_config(struct pcmcia_device *link)
{
parport_info_t *info = link->priv;
struct parport *p;
int ret;
dev_dbg(&link->dev, "parport_config\n");
if (epp_mode)
link->config_index |= FORCE_EPP_MODE;
ret = pcmcia_loop_config(link, parport_config_check, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
p = parport_pc_probe_port(link->resource[0]->start,
link->resource[1]->start,
link->irq, PARPORT_DMA_NONE,
&link->dev, IRQF_SHARED);
if (p == NULL) {
printk(KERN_NOTICE "parport_cs: parport_pc_probe_port() at "
"0x%3x, irq %u failed\n",
(unsigned int) link->resource[0]->start,
link->irq);
goto failed;
}
p->modes |= PARPORT_MODE_PCSPP;
if (epp_mode)
p->modes |= PARPORT_MODE_TRISTATE | PARPORT_MODE_EPP;
info->ndev = 1;
info->port = p;
return 0;
failed:
parport_cs_release(link);
return -ENODEV;
}
static void parport_cs_release(struct pcmcia_device *link)
{
parport_info_t *info = link->priv;
dev_dbg(&link->dev, "parport_release\n");
if (info->ndev) {
struct parport *p = info->port;
parport_pc_unregister_port(p);
}
info->ndev = 0;
pcmcia_disable_device(link);
}
static int __init init_parport_cs(void)
{
return pcmcia_register_driver(&parport_cs_driver);
}
static void __exit exit_parport_cs(void)
{
pcmcia_unregister_driver(&parport_cs_driver);
}
