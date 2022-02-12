static int pcmcia_set_mode(struct ata_link *link, struct ata_device **r_failed_dev)
{
struct ata_device *master = &link->device[0];
struct ata_device *slave = &link->device[1];
if (!ata_dev_enabled(master) || !ata_dev_enabled(slave))
return ata_do_set_mode(link, r_failed_dev);
if (memcmp(master->id + ATA_ID_FW_REV, slave->id + ATA_ID_FW_REV,
ATA_ID_FW_REV_LEN + ATA_ID_PROD_LEN) == 0) {
if (memcmp(master->id + ATA_ID_SERNO, slave->id + ATA_ID_SERNO,
ATA_ID_SERNO_LEN) == 0 && master->id[ATA_ID_SERNO] >> 8) {
ata_dev_warn(slave, "is a ghost device, ignoring\n");
ata_dev_disable(slave);
}
}
return ata_do_set_mode(link, r_failed_dev);
}
static int pcmcia_set_mode_8bit(struct ata_link *link,
struct ata_device **r_failed_dev)
{
return 0;
}
static unsigned int ata_data_xfer_8bit(struct ata_queued_cmd *qc,
unsigned char *buf, unsigned int buflen, int rw)
{
struct ata_port *ap = qc->dev->link->ap;
if (rw == READ)
ioread8_rep(ap->ioaddr.data_addr, buf, buflen);
else
iowrite8_rep(ap->ioaddr.data_addr, buf, buflen);
return buflen;
}
static void pcmcia_8bit_drain_fifo(struct ata_queued_cmd *qc)
{
int count;
struct ata_port *ap;
if (qc == NULL || qc->dma_dir == DMA_TO_DEVICE)
return;
ap = qc->ap;
for (count = 0; (ap->ops->sff_check_status(ap) & ATA_DRQ)
&& count++ < 65536;)
ioread8(ap->ioaddr.data_addr);
if (count)
ata_port_warn(ap, "drained %d bytes to clear DRQ\n", count);
}
static int pcmcia_check_one_config(struct pcmcia_device *pdev, void *priv_data)
{
int *is_kme = priv_data;
if ((pdev->resource[0]->flags & IO_DATA_PATH_WIDTH)
!= IO_DATA_PATH_WIDTH_8) {
pdev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
pdev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
}
pdev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
pdev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
if (pdev->resource[1]->end) {
pdev->resource[0]->end = 8;
pdev->resource[1]->end = (*is_kme) ? 2 : 1;
} else {
if (pdev->resource[0]->end < 16)
return -ENODEV;
}
return pcmcia_request_io(pdev);
}
static int pcmcia_init_one(struct pcmcia_device *pdev)
{
struct ata_host *host;
struct ata_port *ap;
int is_kme = 0, ret = -ENOMEM, p;
unsigned long io_base, ctl_base;
void __iomem *io_addr, *ctl_addr;
int n_ports = 1;
struct ata_port_operations *ops = &pcmcia_port_ops;
pdev->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO |
CONF_AUTO_SET_VPP | CONF_AUTO_CHECK_VCC;
is_kme = ((pdev->manf_id == MANFID_KME) &&
((pdev->card_id == PRODID_KME_KXLC005_A) ||
(pdev->card_id == PRODID_KME_KXLC005_B)));
if (pcmcia_loop_config(pdev, pcmcia_check_one_config, &is_kme)) {
pdev->config_flags &= ~CONF_AUTO_CHECK_VCC;
if (pcmcia_loop_config(pdev, pcmcia_check_one_config, &is_kme))
goto failed;
}
io_base = pdev->resource[0]->start;
if (pdev->resource[1]->end)
ctl_base = pdev->resource[1]->start;
else
ctl_base = pdev->resource[0]->start + 0x0e;
if (!pdev->irq)
goto failed;
ret = pcmcia_enable_device(pdev);
if (ret)
goto failed;
ret = -ENOMEM;
io_addr = devm_ioport_map(&pdev->dev, io_base, 8);
ctl_addr = devm_ioport_map(&pdev->dev, ctl_base, 1);
if (!io_addr || !ctl_addr)
goto failed;
iowrite8(0x02, ctl_addr);
if (is_kme)
iowrite8(0x81, ctl_addr + 0x01);
if (resource_size(pdev->resource[0]) >= 0x20)
n_ports = 2;
if (pdev->manf_id == 0x0097 && pdev->card_id == 0x1620)
ops = &pcmcia_8bit_port_ops;
ret = -ENOMEM;
host = ata_host_alloc(&pdev->dev, n_ports);
if (!host)
goto failed;
for (p = 0; p < n_ports; p++) {
ap = host->ports[p];
ap->ops = ops;
ap->pio_mask = ATA_PIO0;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->ioaddr.cmd_addr = io_addr + 0x10 * p;
ap->ioaddr.altstatus_addr = ctl_addr + 0x10 * p;
ap->ioaddr.ctl_addr = ctl_addr + 0x10 * p;
ata_sff_std_ports(&ap->ioaddr);
ata_port_desc(ap, "cmd 0x%lx ctl 0x%lx", io_base, ctl_base);
}
ret = ata_host_activate(host, pdev->irq, ata_sff_interrupt,
IRQF_SHARED, &pcmcia_sht);
if (ret)
goto failed;
pdev->priv = host;
return 0;
failed:
pcmcia_disable_device(pdev);
return ret;
}
static void pcmcia_remove_one(struct pcmcia_device *pdev)
{
struct ata_host *host = pdev->priv;
if (host)
ata_host_detach(host);
pcmcia_disable_device(pdev);
}
