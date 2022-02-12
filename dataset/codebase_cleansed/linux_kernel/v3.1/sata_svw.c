static int k2_sata_check_atapi_dma(struct ata_queued_cmd *qc)
{
u8 cmnd = qc->scsicmd->cmnd[0];
if (qc->ap->flags & K2_FLAG_NO_ATAPI_DMA)
return -1;
else {
switch (cmnd) {
case READ_10:
case READ_12:
case READ_16:
case WRITE_10:
case WRITE_12:
case WRITE_16:
return 0;
default:
return -1;
}
}
}
static int k2_sata_scr_read(struct ata_link *link,
unsigned int sc_reg, u32 *val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
*val = readl(link->ap->ioaddr.scr_addr + (sc_reg * 4));
return 0;
}
static int k2_sata_scr_write(struct ata_link *link,
unsigned int sc_reg, u32 val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
writel(val, link->ap->ioaddr.scr_addr + (sc_reg * 4));
return 0;
}
static void k2_sata_tf_load(struct ata_port *ap, const struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
if (tf->ctl != ap->last_ctl) {
writeb(tf->ctl, ioaddr->ctl_addr);
ap->last_ctl = tf->ctl;
ata_wait_idle(ap);
}
if (is_addr && (tf->flags & ATA_TFLAG_LBA48)) {
writew(tf->feature | (((u16)tf->hob_feature) << 8),
ioaddr->feature_addr);
writew(tf->nsect | (((u16)tf->hob_nsect) << 8),
ioaddr->nsect_addr);
writew(tf->lbal | (((u16)tf->hob_lbal) << 8),
ioaddr->lbal_addr);
writew(tf->lbam | (((u16)tf->hob_lbam) << 8),
ioaddr->lbam_addr);
writew(tf->lbah | (((u16)tf->hob_lbah) << 8),
ioaddr->lbah_addr);
} else if (is_addr) {
writew(tf->feature, ioaddr->feature_addr);
writew(tf->nsect, ioaddr->nsect_addr);
writew(tf->lbal, ioaddr->lbal_addr);
writew(tf->lbam, ioaddr->lbam_addr);
writew(tf->lbah, ioaddr->lbah_addr);
}
if (tf->flags & ATA_TFLAG_DEVICE)
writeb(tf->device, ioaddr->device_addr);
ata_wait_idle(ap);
}
static void k2_sata_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
u16 nsect, lbal, lbam, lbah, feature;
tf->command = k2_stat_check_status(ap);
tf->device = readw(ioaddr->device_addr);
feature = readw(ioaddr->error_addr);
nsect = readw(ioaddr->nsect_addr);
lbal = readw(ioaddr->lbal_addr);
lbam = readw(ioaddr->lbam_addr);
lbah = readw(ioaddr->lbah_addr);
tf->feature = feature;
tf->nsect = nsect;
tf->lbal = lbal;
tf->lbam = lbam;
tf->lbah = lbah;
if (tf->flags & ATA_TFLAG_LBA48) {
tf->hob_feature = feature >> 8;
tf->hob_nsect = nsect >> 8;
tf->hob_lbal = lbal >> 8;
tf->hob_lbam = lbam >> 8;
tf->hob_lbah = lbah >> 8;
}
}
static void k2_bmdma_setup_mmio(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
unsigned int rw = (qc->tf.flags & ATA_TFLAG_WRITE);
u8 dmactl;
void __iomem *mmio = ap->ioaddr.bmdma_addr;
mb();
writel(ap->bmdma_prd_dma, mmio + ATA_DMA_TABLE_OFS);
dmactl = readb(mmio + ATA_DMA_CMD);
dmactl &= ~(ATA_DMA_WR | ATA_DMA_START);
if (!rw)
dmactl |= ATA_DMA_WR;
writeb(dmactl, mmio + ATA_DMA_CMD);
if (qc->tf.protocol != ATA_PROT_DMA)
ap->ops->sff_exec_command(ap, &qc->tf);
}
static void k2_bmdma_start_mmio(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *mmio = ap->ioaddr.bmdma_addr;
u8 dmactl;
dmactl = readb(mmio + ATA_DMA_CMD);
writeb(dmactl | ATA_DMA_START, mmio + ATA_DMA_CMD);
if (qc->tf.protocol == ATA_PROT_DMA)
ap->ops->sff_exec_command(ap, &qc->tf);
}
static u8 k2_stat_check_status(struct ata_port *ap)
{
return readl(ap->ioaddr.status_addr);
}
static int k2_sata_proc_info(struct Scsi_Host *shost, char *page, char **start,
off_t offset, int count, int inout)
{
struct ata_port *ap;
struct device_node *np;
int len, index;
ap = ata_shost_to_port(shost);
if (ap == NULL)
return 0;
np = pci_device_to_OF_node(to_pci_dev(ap->host->dev));
if (np == NULL)
return 0;
index = (ap == ap->host->ports[0]) ? 0 : 1;
for (np = np->child; np != NULL; np = np->sibling) {
const u32 *reg = of_get_property(np, "reg", NULL);
if (!reg)
continue;
if (index == *reg)
break;
}
if (np == NULL)
return 0;
len = sprintf(page, "devspec: %s\n", np->full_name);
return len;
}
static void k2_sata_setup_port(struct ata_ioports *port, void __iomem *base)
{
port->cmd_addr = base + K2_SATA_TF_CMD_OFFSET;
port->data_addr = base + K2_SATA_TF_DATA_OFFSET;
port->feature_addr =
port->error_addr = base + K2_SATA_TF_ERROR_OFFSET;
port->nsect_addr = base + K2_SATA_TF_NSECT_OFFSET;
port->lbal_addr = base + K2_SATA_TF_LBAL_OFFSET;
port->lbam_addr = base + K2_SATA_TF_LBAM_OFFSET;
port->lbah_addr = base + K2_SATA_TF_LBAH_OFFSET;
port->device_addr = base + K2_SATA_TF_DEVICE_OFFSET;
port->command_addr =
port->status_addr = base + K2_SATA_TF_CMDSTAT_OFFSET;
port->altstatus_addr =
port->ctl_addr = base + K2_SATA_TF_CTL_OFFSET;
port->bmdma_addr = base + K2_SATA_DMA_CMD_OFFSET;
port->scr_addr = base + K2_SATA_SCR_STATUS_OFFSET;
}
static int k2_sata_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct ata_port_info *ppi[] =
{ &k2_port_info[ent->driver_data], NULL };
struct ata_host *host;
void __iomem *mmio_base;
int n_ports, i, rc, bar_pos;
ata_print_version_once(&pdev->dev, DRV_VERSION);
n_ports = 4;
if (ppi[0]->flags & K2_FLAG_SATA_8_PORTS)
n_ports = 8;
host = ata_host_alloc_pinfo(&pdev->dev, ppi, n_ports);
if (!host)
return -ENOMEM;
bar_pos = 5;
if (ppi[0]->flags & K2_FLAG_BAR_POS_3)
bar_pos = 3;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (pci_resource_len(pdev, bar_pos) == 0) {
pcim_pin_device(pdev);
return -ENODEV;
}
rc = pcim_iomap_regions(pdev, 1 << bar_pos, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
mmio_base = host->iomap[bar_pos];
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
unsigned int offset = i * K2_SATA_PORT_OFFSET;
k2_sata_setup_port(&ap->ioaddr, mmio_base + offset);
ata_port_pbar_desc(ap, 5, -1, "mmio");
ata_port_pbar_desc(ap, 5, offset, "port");
}
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
writel(readl(mmio_base + K2_SATA_SICR1_OFFSET) & ~0x00040000,
mmio_base + K2_SATA_SICR1_OFFSET);
writel(0xffffffff, mmio_base + K2_SATA_SCR_ERROR_OFFSET);
writel(0x0, mmio_base + K2_SATA_SIM_OFFSET);
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &k2_sata_sht);
}
static int __init k2_sata_init(void)
{
return pci_register_driver(&k2_sata_pci_driver);
}
static void __exit k2_sata_exit(void)
{
pci_unregister_driver(&k2_sata_pci_driver);
}
