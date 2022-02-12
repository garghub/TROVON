static int sc1200_clock(void)
{
u8 chip_id = inb(0x903C);
u8 silicon_rev = inb(0x903D);
u16 pci_clock;
if (chip_id == 0x04 && silicon_rev < SC1200_REV_B1)
return 0;
pci_clock = inw(0x901E);
pci_clock >>= 8;
pci_clock &= 0x03;
if (pci_clock == 3)
pci_clock = 0;
return pci_clock;
}
static void sc1200_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u32 pio_timings[4][5] = {
{ 0x00009172, 0x00012171, 0x00020080, 0x00032010, 0x00040010 },
{ 0xd1329172, 0x71212171, 0x30200080, 0x20102010, 0x00100010 },
{ 0xfaa3f4f3, 0xc23232b2, 0x513101c1, 0x31213121, 0x10211021 },
{ 0xfff4fff4, 0xf35353d3, 0x814102f1, 0x42314231, 0x11311131 }
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 format;
unsigned int reg = 0x40 + 0x10 * ap->port_no;
int mode = adev->pio_mode - XFER_PIO_0;
pci_read_config_dword(pdev, reg + 4, &format);
format >>= 31;
format += sc1200_clock();
pci_write_config_dword(pdev, reg + 8 * adev->devno,
pio_timings[format][mode]);
}
static void sc1200_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u32 udma_timing[3][3] = {
{ 0x00921250, 0x00911140, 0x00911030 },
{ 0x00932470, 0x00922260, 0x00922140 },
{ 0x009436A1, 0x00933481, 0x00923261 }
};
static const u32 mwdma_timing[3][3] = {
{ 0x00077771, 0x00012121, 0x00002020 },
{ 0x000BBBB2, 0x00024241, 0x00013131 },
{ 0x000FFFF3, 0x00035352, 0x00015151 }
};
int clock = sc1200_clock();
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
unsigned int reg = 0x40 + 0x10 * ap->port_no;
int mode = adev->dma_mode;
u32 format;
if (mode >= XFER_UDMA_0)
format = udma_timing[clock][mode - XFER_UDMA_0];
else
format = mwdma_timing[clock][mode - XFER_MW_DMA_0];
if (adev->devno == 0) {
u32 timings;
pci_read_config_dword(pdev, reg + 4, &timings);
timings &= 0x80000000UL;
timings |= format;
pci_write_config_dword(pdev, reg + 4, timings);
} else
pci_write_config_dword(pdev, reg + 12, format);
}
static unsigned int sc1200_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
struct ata_device *prev = ap->private_data;
if (ata_dma_enabled(adev) && adev != prev && prev != NULL) {
if ((ata_using_udma(adev) && !ata_using_udma(prev)) ||
(ata_using_udma(prev) && !ata_using_udma(adev)))
sc1200_set_dmamode(ap, adev);
}
return ata_bmdma_qc_issue(qc);
}
static int sc1200_qc_defer(struct ata_queued_cmd *qc)
{
struct ata_host *host = qc->ap->host;
struct ata_port *alt = host->ports[1 ^ qc->ap->port_no];
int rc;
rc = ata_std_qc_defer(qc);
if (rc != 0)
return rc;
if (alt && alt->qc_active)
return ATA_DEFER_PORT;
return 0;
}
static int sc1200_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &sc1200_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
return ata_pci_bmdma_init_one(dev, ppi, &sc1200_sht, NULL, 0);
}
static int __init sc1200_init(void)
{
return pci_register_driver(&sc1200_pci_driver);
}
static void __exit sc1200_exit(void)
{
pci_unregister_driver(&sc1200_pci_driver);
}
