static int atiixp_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 udma;
pci_read_config_byte(pdev, ATIIXP_IDE_UDMA_MODE + ap->port_no, &udma);
if ((udma & 0x07) >= 0x04 || (udma & 0x70) >= 0x40)
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static int atiixp_prereset(struct ata_link *link, unsigned long deadline)
{
static const struct pci_bits atiixp_enable_bits[] = {
{ 0x48, 1, 0x01, 0x00 },
{ 0x48, 1, 0x08, 0x00 }
};
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &atiixp_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void atiixp_set_pio_timing(struct ata_port *ap, struct ata_device *adev, int pio)
{
static u8 pio_timings[5] = { 0x5D, 0x47, 0x34, 0x22, 0x20 };
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = 2 * ap->port_no + adev->devno;
int timing_shift = (16 * ap->port_no) + 8 * (adev->devno ^ 1);
u32 pio_timing_data;
u16 pio_mode_data;
pci_read_config_word(pdev, ATIIXP_IDE_PIO_MODE, &pio_mode_data);
pio_mode_data &= ~(0x7 << (4 * dn));
pio_mode_data |= pio << (4 * dn);
pci_write_config_word(pdev, ATIIXP_IDE_PIO_MODE, pio_mode_data);
pci_read_config_dword(pdev, ATIIXP_IDE_PIO_TIMING, &pio_timing_data);
pio_timing_data &= ~(0xFF << timing_shift);
pio_timing_data |= (pio_timings[pio] << timing_shift);
pci_write_config_dword(pdev, ATIIXP_IDE_PIO_TIMING, pio_timing_data);
}
static void atiixp_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
unsigned long flags;
spin_lock_irqsave(&atiixp_lock, flags);
atiixp_set_pio_timing(ap, adev, adev->pio_mode - XFER_PIO_0);
spin_unlock_irqrestore(&atiixp_lock, flags);
}
static void atiixp_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static u8 mwdma_timings[5] = { 0x77, 0x21, 0x20 };
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dma = adev->dma_mode;
int dn = 2 * ap->port_no + adev->devno;
int wanted_pio;
unsigned long flags;
spin_lock_irqsave(&atiixp_lock, flags);
if (adev->dma_mode >= XFER_UDMA_0) {
u16 udma_mode_data;
dma -= XFER_UDMA_0;
pci_read_config_word(pdev, ATIIXP_IDE_UDMA_MODE, &udma_mode_data);
udma_mode_data &= ~(0x7 << (4 * dn));
udma_mode_data |= dma << (4 * dn);
pci_write_config_word(pdev, ATIIXP_IDE_UDMA_MODE, udma_mode_data);
} else {
int timing_shift = (16 * ap->port_no) + 8 * (adev->devno ^ 1);
u32 mwdma_timing_data;
dma -= XFER_MW_DMA_0;
pci_read_config_dword(pdev, ATIIXP_IDE_MWDMA_TIMING,
&mwdma_timing_data);
mwdma_timing_data &= ~(0xFF << timing_shift);
mwdma_timing_data |= (mwdma_timings[dma] << timing_shift);
pci_write_config_dword(pdev, ATIIXP_IDE_MWDMA_TIMING,
mwdma_timing_data);
}
if (adev->dma_mode >= XFER_MW_DMA_2)
wanted_pio = 4;
else if (adev->dma_mode == XFER_MW_DMA_1)
wanted_pio = 3;
else if (adev->dma_mode == XFER_MW_DMA_0)
wanted_pio = 0;
else BUG();
if (adev->pio_mode != wanted_pio)
atiixp_set_pio_timing(ap, adev, wanted_pio);
spin_unlock_irqrestore(&atiixp_lock, flags);
}
static void atiixp_bmdma_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = (2 * ap->port_no) + adev->devno;
u16 tmp16;
pci_read_config_word(pdev, ATIIXP_IDE_UDMA_CONTROL, &tmp16);
if (ata_using_udma(adev))
tmp16 |= (1 << dn);
else
tmp16 &= ~(1 << dn);
pci_write_config_word(pdev, ATIIXP_IDE_UDMA_CONTROL, tmp16);
ata_bmdma_start(qc);
}
static void atiixp_bmdma_stop(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int dn = (2 * ap->port_no) + qc->dev->devno;
u16 tmp16;
pci_read_config_word(pdev, ATIIXP_IDE_UDMA_CONTROL, &tmp16);
tmp16 &= ~(1 << dn);
pci_write_config_word(pdev, ATIIXP_IDE_UDMA_CONTROL, tmp16);
ata_bmdma_stop(qc);
}
static int atiixp_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA12_ONLY,
.udma_mask = ATA_UDMA5,
.port_ops = &atiixp_port_ops
};
const struct ata_port_info *ppi[] = { &info, &info };
return ata_pci_bmdma_init_one(pdev, ppi, &atiixp_sht, NULL,
ATA_HOST_PARALLEL_SCAN);
}
static int __init atiixp_init(void)
{
return pci_register_driver(&atiixp_pci_driver);
}
static void __exit atiixp_exit(void)
{
pci_unregister_driver(&atiixp_pci_driver);
}
