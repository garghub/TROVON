static struct Scsi_Host *__qlogicfas_detect(struct scsi_host_template *host,
int qbase,
int qlirq)
{
int qltyp;
int qinitid;
struct Scsi_Host *hreg;
struct qlogicfas408_priv *priv;
if (!qbase || qlirq == -1)
goto err;
if (!request_region(qbase, 0x10, qlogicfas_name)) {
printk(KERN_INFO "%s: address %#x is busy\n", qlogicfas_name,
qbase);
goto err;
}
if (!qlogicfas408_detect(qbase, INT_TYPE)) {
printk(KERN_WARNING "%s: probe failed for %#x\n",
qlogicfas_name,
qbase);
goto err_release_mem;
}
printk(KERN_INFO "%s: Using preset base address of %03x,"
" IRQ %d\n", qlogicfas_name, qbase, qlirq);
qltyp = qlogicfas408_get_chip_type(qbase, INT_TYPE);
qinitid = host->this_id;
if (qinitid < 0)
qinitid = 7;
qlogicfas408_setup(qbase, qinitid, INT_TYPE);
hreg = scsi_host_alloc(host, sizeof(struct qlogicfas408_priv));
if (!hreg)
goto err_release_mem;
priv = get_priv_by_host(hreg);
hreg->io_port = qbase;
hreg->n_io_port = 16;
hreg->dma_channel = -1;
if (qlirq != -1)
hreg->irq = qlirq;
priv->qbase = qbase;
priv->qlirq = qlirq;
priv->qinitid = qinitid;
priv->shost = hreg;
priv->int_type = INT_TYPE;
sprintf(priv->qinfo,
"Qlogicfas Driver version 0.46, chip %02X at %03X, IRQ %d, TPdma:%d",
qltyp, qbase, qlirq, QL_TURBO_PDMA);
host->name = qlogicfas_name;
if (request_irq(qlirq, qlogicfas408_ihandl, 0, qlogicfas_name, hreg))
goto free_scsi_host;
if (scsi_add_host(hreg, NULL))
goto free_interrupt;
scsi_scan_host(hreg);
return hreg;
free_interrupt:
free_irq(qlirq, hreg);
free_scsi_host:
scsi_host_put(hreg);
err_release_mem:
release_region(qbase, 0x10);
err:
return NULL;
}
static int qlogicfas_detect(struct scsi_host_template *sht)
{
struct Scsi_Host *shost;
struct qlogicfas408_priv *priv;
int num;
for (num = 0; num < MAX_QLOGICFAS; num++) {
shost = __qlogicfas_detect(sht, iobase[num], irq[num]);
if (shost == NULL) {
break;
}
priv = get_priv_by_host(shost);
priv->next = cards;
cards = priv;
}
return num;
}
static int qlogicfas_release(struct Scsi_Host *shost)
{
struct qlogicfas408_priv *priv = get_priv_by_host(shost);
scsi_remove_host(shost);
if (shost->irq) {
qlogicfas408_disable_ints(priv);
free_irq(shost->irq, shost);
}
if (shost->io_port && shost->n_io_port)
release_region(shost->io_port, shost->n_io_port);
scsi_host_put(shost);
return 0;
}
static __init int qlogicfas_init(void)
{
if (!qlogicfas_detect(&qlogicfas_driver_template)) {
printk(KERN_INFO "%s: no cards were found, please specify "
"I/O address and IRQ using iobase= and irq= "
"options", qlogicfas_name);
return -ENODEV;
}
return 0;
}
static __exit void qlogicfas_exit(void)
{
struct qlogicfas408_priv *priv;
for (priv = cards; priv != NULL; priv = priv->next)
qlogicfas_release(priv->shost);
}
