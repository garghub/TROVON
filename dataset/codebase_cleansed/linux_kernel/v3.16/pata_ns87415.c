static void ns87415_set_mode(struct ata_port *ap, struct ata_device *adev, u8 mode)
{
struct pci_dev *dev = to_pci_dev(ap->host->dev);
int unit = 2 * ap->port_no + adev->devno;
int timing = 0x44 + 2 * unit;
unsigned long T = 1000000000 / 33333;
struct ata_timing t;
u16 clocking;
u8 iordy;
u8 status;
ata_timing_compute(adev, adev->pio_mode, &t, T, 0);
clocking = 17 - clamp_val(t.active, 2, 17);
clocking |= (16 - clamp_val(t.recover, 1, 16)) << 4;
clocking |= (clocking << 8);
pci_write_config_word(dev, timing, clocking);
pci_read_config_byte(dev, 0x42, &iordy);
iordy &= ~(1 << (4 + unit));
if (mode >= XFER_MW_DMA_0 || !ata_pio_need_iordy(adev))
iordy |= (1 << (4 + unit));
pci_read_config_byte(dev, 0x43, &status);
while (status & 0x03) {
udelay(1);
pci_read_config_byte(dev, 0x43, &status);
}
pci_write_config_byte(dev, 0x42, iordy);
}
static void ns87415_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
ns87415_set_mode(ap, adev, adev->pio_mode);
}
static void ns87415_bmdma_setup(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
unsigned int rw = (qc->tf.flags & ATA_TFLAG_WRITE);
u8 dmactl;
mb();
iowrite32(ap->bmdma_prd_dma, ap->ioaddr.bmdma_addr + ATA_DMA_TABLE_OFS);
dmactl = ioread8(ap->ioaddr.bmdma_addr + ATA_DMA_CMD);
dmactl &= ~(ATA_DMA_WR | ATA_DMA_START);
dmactl |= ATA_DMA_INTR | ATA_DMA_ERR;
if (!rw)
dmactl |= ATA_DMA_WR;
iowrite8(dmactl, ap->ioaddr.bmdma_addr + ATA_DMA_CMD);
ap->ops->sff_exec_command(ap, &qc->tf);
}
static void ns87415_bmdma_start(struct ata_queued_cmd *qc)
{
ns87415_set_mode(qc->ap, qc->dev, qc->dev->dma_mode);
ata_bmdma_start(qc);
}
static void ns87415_bmdma_stop(struct ata_queued_cmd *qc)
{
ata_bmdma_stop(qc);
ns87415_set_mode(qc->ap, qc->dev, qc->dev->pio_mode);
}
static void ns87415_irq_clear(struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
if (!mmio)
return;
iowrite8((ioread8(mmio + ATA_DMA_CMD) | ATA_DMA_INTR | ATA_DMA_ERR),
mmio + ATA_DMA_CMD);
}
static int ns87415_check_atapi_dma(struct ata_queued_cmd *qc)
{
return -EOPNOTSUPP;
}
static u8 ns87560_read_buggy(void __iomem *port)
{
u8 tmp;
int retries = SUPERIO_IDE_MAX_RETRIES;
do {
tmp = ioread8(port);
if (tmp != 0)
return tmp;
udelay(50);
} while(retries-- > 0);
return tmp;
}
static u8 ns87560_check_status(struct ata_port *ap)
{
return ns87560_read_buggy(ap->ioaddr.status_addr);
}
void ns87560_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
tf->command = ns87560_check_status(ap);
tf->feature = ioread8(ioaddr->error_addr);
tf->nsect = ioread8(ioaddr->nsect_addr);
tf->lbal = ioread8(ioaddr->lbal_addr);
tf->lbam = ioread8(ioaddr->lbam_addr);
tf->lbah = ioread8(ioaddr->lbah_addr);
tf->device = ns87560_read_buggy(ioaddr->device_addr);
if (tf->flags & ATA_TFLAG_LBA48) {
iowrite8(tf->ctl | ATA_HOB, ioaddr->ctl_addr);
tf->hob_feature = ioread8(ioaddr->error_addr);
tf->hob_nsect = ioread8(ioaddr->nsect_addr);
tf->hob_lbal = ioread8(ioaddr->lbal_addr);
tf->hob_lbam = ioread8(ioaddr->lbam_addr);
tf->hob_lbah = ioread8(ioaddr->lbah_addr);
iowrite8(tf->ctl, ioaddr->ctl_addr);
ap->last_ctl = tf->ctl;
}
}
static u8 ns87560_bmdma_status(struct ata_port *ap)
{
return ns87560_read_buggy(ap->ioaddr.bmdma_addr + ATA_DMA_STATUS);
}
static void ns87415_fixup(struct pci_dev *pdev)
{
pci_write_config_byte(pdev, 0x55, 0xEE);
pci_write_config_byte(pdev, 0x54, 0xB7);
}
static int ns87415_init_one (struct pci_dev *pdev, const struct pci_device_id *ent)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &ns87415_pata_ops,
};
const struct ata_port_info *ppi[] = { &info, NULL };
int rc;
#if defined(CONFIG_SUPERIO)
static const struct ata_port_info info87560 = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &ns87560_pata_ops,
};
if (PCI_SLOT(pdev->devfn) == 0x0E)
ppi[0] = &info87560;
#endif
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
ns87415_fixup(pdev);
return ata_pci_bmdma_init_one(pdev, ppi, &ns87415_sht, NULL, 0);
}
static int ns87415_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
ns87415_fixup(pdev);
ata_host_resume(host);
return 0;
}
