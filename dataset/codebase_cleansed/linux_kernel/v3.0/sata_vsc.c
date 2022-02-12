static int vsc_sata_scr_read(struct ata_link *link,
unsigned int sc_reg, u32 *val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
*val = readl(link->ap->ioaddr.scr_addr + (sc_reg * 4));
return 0;
}
static int vsc_sata_scr_write(struct ata_link *link,
unsigned int sc_reg, u32 val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
writel(val, link->ap->ioaddr.scr_addr + (sc_reg * 4));
return 0;
}
static void vsc_freeze(struct ata_port *ap)
{
void __iomem *mask_addr;
mask_addr = ap->host->iomap[VSC_MMIO_BAR] +
VSC_SATA_INT_MASK_OFFSET + ap->port_no;
writeb(0, mask_addr);
}
static void vsc_thaw(struct ata_port *ap)
{
void __iomem *mask_addr;
mask_addr = ap->host->iomap[VSC_MMIO_BAR] +
VSC_SATA_INT_MASK_OFFSET + ap->port_no;
writeb(0xff, mask_addr);
}
static void vsc_intr_mask_update(struct ata_port *ap, u8 ctl)
{
void __iomem *mask_addr;
u8 mask;
mask_addr = ap->host->iomap[VSC_MMIO_BAR] +
VSC_SATA_INT_MASK_OFFSET + ap->port_no;
mask = readb(mask_addr);
if (ctl & ATA_NIEN)
mask |= 0x80;
else
mask &= 0x7F;
writeb(mask, mask_addr);
}
static void vsc_sata_tf_load(struct ata_port *ap, const struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
if ((tf->ctl & ATA_NIEN) != (ap->last_ctl & ATA_NIEN)) {
ap->last_ctl = tf->ctl;
vsc_intr_mask_update(ap, tf->ctl & ATA_NIEN);
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
static void vsc_sata_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
u16 nsect, lbal, lbam, lbah, feature;
tf->command = ata_sff_check_status(ap);
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
static inline void vsc_error_intr(u8 port_status, struct ata_port *ap)
{
if (port_status & (VSC_SATA_INT_PHY_CHANGE | VSC_SATA_INT_ERROR_M))
ata_port_freeze(ap);
else
ata_port_abort(ap);
}
static void vsc_port_intr(u8 port_status, struct ata_port *ap)
{
struct ata_queued_cmd *qc;
int handled = 0;
if (unlikely(port_status & VSC_SATA_INT_ERROR)) {
vsc_error_intr(port_status, ap);
return;
}
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (qc && likely(!(qc->tf.flags & ATA_TFLAG_POLLING)))
handled = ata_bmdma_port_intr(ap, qc);
if (unlikely(!handled))
ap->ops->sff_check_status(ap);
}
static irqreturn_t vsc_sata_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
unsigned int i;
unsigned int handled = 0;
u32 status;
status = readl(host->iomap[VSC_MMIO_BAR] + VSC_SATA_INT_STAT_OFFSET);
if (unlikely(status == 0xffffffff || status == 0)) {
if (status)
dev_printk(KERN_ERR, host->dev,
": IRQ status == 0xffffffff, "
"PCI fault or device removal?\n");
goto out;
}
spin_lock(&host->lock);
for (i = 0; i < host->n_ports; i++) {
u8 port_status = (status >> (8 * i)) & 0xff;
if (port_status) {
vsc_port_intr(port_status, host->ports[i]);
handled++;
}
}
spin_unlock(&host->lock);
out:
return IRQ_RETVAL(handled);
}
static void __devinit vsc_sata_setup_port(struct ata_ioports *port,
void __iomem *base)
{
port->cmd_addr = base + VSC_SATA_TF_CMD_OFFSET;
port->data_addr = base + VSC_SATA_TF_DATA_OFFSET;
port->error_addr = base + VSC_SATA_TF_ERROR_OFFSET;
port->feature_addr = base + VSC_SATA_TF_FEATURE_OFFSET;
port->nsect_addr = base + VSC_SATA_TF_NSECT_OFFSET;
port->lbal_addr = base + VSC_SATA_TF_LBAL_OFFSET;
port->lbam_addr = base + VSC_SATA_TF_LBAM_OFFSET;
port->lbah_addr = base + VSC_SATA_TF_LBAH_OFFSET;
port->device_addr = base + VSC_SATA_TF_DEVICE_OFFSET;
port->status_addr = base + VSC_SATA_TF_STATUS_OFFSET;
port->command_addr = base + VSC_SATA_TF_COMMAND_OFFSET;
port->altstatus_addr = base + VSC_SATA_TF_ALTSTATUS_OFFSET;
port->ctl_addr = base + VSC_SATA_TF_CTL_OFFSET;
port->bmdma_addr = base + VSC_SATA_DMA_CMD_OFFSET;
port->scr_addr = base + VSC_SATA_SCR_STATUS_OFFSET;
writel(0, base + VSC_SATA_UP_DESCRIPTOR_OFFSET);
writel(0, base + VSC_SATA_UP_DATA_BUFFER_OFFSET);
}
static int __devinit vsc_sata_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static const struct ata_port_info pi = {
.flags = ATA_FLAG_SATA,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &vsc_sata_ops,
};
const struct ata_port_info *ppi[] = { &pi, NULL };
static int printed_version;
struct ata_host *host;
void __iomem *mmio_base;
int i, rc;
u8 cls;
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev, "version " DRV_VERSION "\n");
host = ata_host_alloc_pinfo(&pdev->dev, ppi, 4);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (pci_resource_len(pdev, 0) == 0)
return -ENODEV;
rc = pcim_iomap_regions(pdev, 1 << VSC_MMIO_BAR, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
mmio_base = host->iomap[VSC_MMIO_BAR];
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
unsigned int offset = (i + 1) * VSC_SATA_PORT_OFFSET;
vsc_sata_setup_port(&ap->ioaddr, mmio_base + offset);
ata_port_pbar_desc(ap, VSC_MMIO_BAR, -1, "mmio");
ata_port_pbar_desc(ap, VSC_MMIO_BAR, offset, "port");
}
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc)
return rc;
pci_read_config_byte(pdev, PCI_CACHE_LINE_SIZE, &cls);
if (cls == 0x00)
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE, 0x80);
if (pci_enable_msi(pdev) == 0)
pci_intx(pdev, 0);
pci_write_config_dword(pdev, 0x98, 0);
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, vsc_sata_interrupt,
IRQF_SHARED, &vsc_sata_sht);
}
static int __init vsc_sata_init(void)
{
return pci_register_driver(&vsc_sata_pci_driver);
}
static void __exit vsc_sata_exit(void)
{
pci_unregister_driver(&vsc_sata_pci_driver);
}
