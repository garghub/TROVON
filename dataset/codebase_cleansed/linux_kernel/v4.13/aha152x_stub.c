static int aha152x_probe(struct pcmcia_device *link)
{
scsi_info_t *info;
dev_dbg(&link->dev, "aha152x_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
link->config_regs = PRESENT_OPTION;
return aha152x_config_cs(link);
}
static void aha152x_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "aha152x_detach\n");
aha152x_release_cs(link);
kfree(link->priv);
}
static int aha152x_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->io_lines = 10;
if ((p_dev->resource[0]->end < 0x20) &&
(p_dev->resource[1]->end >= 0x20))
p_dev->resource[0]->start = p_dev->resource[1]->start;
if (p_dev->resource[0]->start >= 0xffff)
return -EINVAL;
p_dev->resource[1]->start = p_dev->resource[1]->end = 0;
p_dev->resource[0]->end = 0x20;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
return pcmcia_request_io(p_dev);
}
static int aha152x_config_cs(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
struct aha152x_setup s;
int ret;
struct Scsi_Host *host;
dev_dbg(&link->dev, "aha152x_config\n");
ret = pcmcia_loop_config(link, aha152x_config_check, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
memset(&s, 0, sizeof(s));
s.conf = "PCMCIA setup";
s.io_port = link->resource[0]->start;
s.irq = link->irq;
s.scsiid = host_id;
s.reconnect = reconnect;
s.parity = parity;
s.synchronous = synchronous;
s.delay = reset_delay;
if (ext_trans)
s.ext_trans = ext_trans;
host = aha152x_probe_one(&s);
if (host == NULL) {
printk(KERN_INFO "aha152x_cs: no SCSI devices found\n");
goto failed;
}
info->host = host;
return 0;
failed:
aha152x_release_cs(link);
return -ENODEV;
}
static void aha152x_release_cs(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
aha152x_release(info->host);
pcmcia_disable_device(link);
}
static int aha152x_resume(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
aha152x_host_reset_host(info->host);
return 0;
}
static int __init init_aha152x_cs(void)
{
return pcmcia_register_driver(&aha152x_cs_driver);
}
static void __exit exit_aha152x_cs(void)
{
pcmcia_unregister_driver(&aha152x_cs_driver);
}
