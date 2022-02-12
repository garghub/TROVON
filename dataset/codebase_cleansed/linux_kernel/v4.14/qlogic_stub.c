static struct Scsi_Host *qlogic_detect(struct scsi_host_template *host,
struct pcmcia_device *link, int qbase, int qlirq)
{
int qltyp;
int qinitid;
struct Scsi_Host *shost;
struct qlogicfas408_priv *priv;
qltyp = qlogicfas408_get_chip_type(qbase, INT_TYPE);
qinitid = host->this_id;
if (qinitid < 0)
qinitid = 7;
qlogicfas408_setup(qbase, qinitid, INT_TYPE);
host->name = qlogic_name;
shost = scsi_host_alloc(host, sizeof(struct qlogicfas408_priv));
if (!shost)
goto err;
shost->io_port = qbase;
shost->n_io_port = 16;
shost->dma_channel = -1;
if (qlirq != -1)
shost->irq = qlirq;
priv = get_priv_by_host(shost);
priv->qlirq = qlirq;
priv->qbase = qbase;
priv->qinitid = qinitid;
priv->shost = shost;
priv->int_type = INT_TYPE;
if (request_irq(qlirq, qlogicfas408_ihandl, 0, qlogic_name, shost))
goto free_scsi_host;
sprintf(priv->qinfo,
"Qlogicfas Driver version 0.46, chip %02X at %03X, IRQ %d, TPdma:%d",
qltyp, qbase, qlirq, QL_TURBO_PDMA);
if (scsi_add_host(shost, NULL))
goto free_interrupt;
scsi_scan_host(shost);
return shost;
free_interrupt:
free_irq(qlirq, shost);
free_scsi_host:
scsi_host_put(shost);
err:
return NULL;
}
static int qlogic_probe(struct pcmcia_device *link)
{
scsi_info_t *info;
dev_dbg(&link->dev, "qlogic_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
link->config_regs = PRESENT_OPTION;
return qlogic_config(link);
}
static void qlogic_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "qlogic_detach\n");
qlogic_release(link);
kfree(link->priv);
}
static int qlogic_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->io_lines = 10;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
if (p_dev->resource[0]->start == 0)
return -ENODEV;
return pcmcia_request_io(p_dev);
}
static int qlogic_config(struct pcmcia_device * link)
{
scsi_info_t *info = link->priv;
int ret;
struct Scsi_Host *host;
dev_dbg(&link->dev, "qlogic_config\n");
ret = pcmcia_loop_config(link, qlogic_config_check, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
if ((info->manf_id == MANFID_MACNICA) || (info->manf_id == MANFID_PIONEER) || (info->manf_id == 0x0098)) {
outb(0xb4, link->resource[0]->start + 0xd);
outb(0x24, link->resource[0]->start + 0x9);
outb(0x04, link->resource[0]->start + 0xd);
}
if (resource_size(link->resource[0]) == 32)
host = qlogic_detect(&qlogicfas_driver_template, link,
link->resource[0]->start + 16, link->irq);
else
host = qlogic_detect(&qlogicfas_driver_template, link,
link->resource[0]->start, link->irq);
if (!host) {
printk(KERN_INFO "%s: no SCSI devices found\n", qlogic_name);
goto failed;
}
info->host = host;
return 0;
failed:
pcmcia_disable_device(link);
return -ENODEV;
}
static void qlogic_release(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
dev_dbg(&link->dev, "qlogic_release\n");
scsi_remove_host(info->host);
free_irq(link->irq, info->host);
pcmcia_disable_device(link);
scsi_host_put(info->host);
}
static int qlogic_resume(struct pcmcia_device *link)
{
scsi_info_t *info = link->priv;
pcmcia_enable_device(link);
if ((info->manf_id == MANFID_MACNICA) ||
(info->manf_id == MANFID_PIONEER) ||
(info->manf_id == 0x0098)) {
outb(0x80, link->resource[0]->start + 0xd);
outb(0x24, link->resource[0]->start + 0x9);
outb(0x04, link->resource[0]->start + 0xd);
}
qlogicfas408_host_reset(NULL);
return 0;
}
static int __init init_qlogic_cs(void)
{
return pcmcia_register_driver(&qlogic_cs_driver);
}
static void __exit exit_qlogic_cs(void)
{
pcmcia_unregister_driver(&qlogic_cs_driver);
}
