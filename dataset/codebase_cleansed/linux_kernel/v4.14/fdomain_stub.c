static int fdomain_probe(struct pcmcia_device *link)
{
scsi_info_t *info;
dev_dbg(&link->dev, "fdomain_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
link->config_regs = PRESENT_OPTION;
return fdomain_config(link);
}
static void fdomain_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "fdomain_detach\n");
fdomain_release(link);
kfree(link->priv);
}
static int fdomain_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->io_lines = 10;
p_dev->resource[0]->end = 0x10;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
return pcmcia_request_io(p_dev);
}
static int fdomain_config(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
int ret;
char str[22];
struct Scsi_Host *host;
dev_dbg(&link->dev, "fdomain_config\n");
ret = pcmcia_loop_config(link, fdomain_config_check, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
release_region(link->resource[0]->start, resource_size(link->resource[0]));
sprintf(str, "%d,%d", (unsigned int) link->resource[0]->start, link->irq);
fdomain_setup(str);
host = __fdomain_16x0_detect(&fdomain_driver_template);
if (!host) {
printk(KERN_INFO "fdomain_cs: no SCSI devices found\n");
goto failed;
}
if (scsi_add_host(host, NULL))
goto failed;
scsi_scan_host(host);
info->host = host;
return 0;
failed:
fdomain_release(link);
return -ENODEV;
}
static void fdomain_release(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
dev_dbg(&link->dev, "fdomain_release\n");
scsi_remove_host(info->host);
pcmcia_disable_device(link);
scsi_unregister(info->host);
}
static int fdomain_resume(struct pcmcia_device *link)
{
fdomain_16x0_host_reset(NULL);
return 0;
}
static int __init init_fdomain_cs(void)
{
return pcmcia_register_driver(&fdomain_cs_driver);
}
static void __exit exit_fdomain_cs(void)
{
pcmcia_unregister_driver(&fdomain_cs_driver);
}
