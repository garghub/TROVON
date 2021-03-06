static void timing_setup(struct ata_port *ap, struct ata_device *adev, int offset, int speed, int clock)
{
static const unsigned char amd_cyc2udma[] = {
6, 6, 5, 4, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 7
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_device *peer = ata_dev_pair(adev);
int dn = ap->port_no * 2 + adev->devno;
struct ata_timing at, apeer;
int T, UT;
const int amd_clock = 33333;
u8 t;
T = 1000000000 / amd_clock;
UT = T;
if (clock >= 2)
UT = T / 2;
if (ata_timing_compute(adev, speed, &at, T, UT) < 0) {
dev_err(&pdev->dev, "unknown mode %d\n", speed);
return;
}
if (peer) {
if (peer->dma_mode) {
ata_timing_compute(peer, peer->dma_mode, &apeer, T, UT);
ata_timing_merge(&apeer, &at, &at, ATA_TIMING_8BIT);
}
ata_timing_compute(peer, peer->pio_mode, &apeer, T, UT);
ata_timing_merge(&apeer, &at, &at, ATA_TIMING_8BIT);
}
if (speed == XFER_UDMA_5 && amd_clock <= 33333) at.udma = 1;
if (speed == XFER_UDMA_6 && amd_clock <= 33333) at.udma = 15;
pci_read_config_byte(pdev, offset + 0x0C, &t);
t = (t & ~(3 << ((3 - dn) << 1))) | ((clamp_val(at.setup, 1, 4) - 1) << ((3 - dn) << 1));
pci_write_config_byte(pdev, offset + 0x0C , t);
pci_write_config_byte(pdev, offset + 0x0E + (1 - (dn >> 1)),
((clamp_val(at.act8b, 1, 16) - 1) << 4) | (clamp_val(at.rec8b, 1, 16) - 1));
pci_write_config_byte(pdev, offset + 0x08 + (3 - dn),
((clamp_val(at.active, 1, 16) - 1) << 4) | (clamp_val(at.recover, 1, 16) - 1));
switch (clock) {
case 1:
t = at.udma ? (0xc0 | (clamp_val(at.udma, 2, 5) - 2)) : 0x03;
break;
case 2:
t = at.udma ? (0xc0 | amd_cyc2udma[clamp_val(at.udma, 2, 10)]) : 0x03;
break;
case 3:
t = at.udma ? (0xc0 | amd_cyc2udma[clamp_val(at.udma, 1, 10)]) : 0x03;
break;
case 4:
t = at.udma ? (0xc0 | amd_cyc2udma[clamp_val(at.udma, 1, 15)]) : 0x03;
break;
default:
return;
}
if (at.udma)
pci_write_config_byte(pdev, offset + 0x10 + (3 - dn), t);
}
static int amd_pre_reset(struct ata_link *link, unsigned long deadline)
{
static const struct pci_bits amd_enable_bits[] = {
{ 0x40, 1, 0x02, 0x02 },
{ 0x40, 1, 0x01, 0x01 }
};
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &amd_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static int amd_cable_detect(struct ata_port *ap)
{
static const u32 bitmask[2] = {0x03, 0x0C};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 ata66;
pci_read_config_byte(pdev, 0x42, &ata66);
if (ata66 & bitmask[ap->port_no])
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static void amd_fifo_setup(struct ata_port *ap)
{
struct ata_device *adev;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const u8 fifobit[2] = { 0xC0, 0x30};
u8 fifo = fifobit[ap->port_no];
u8 r;
ata_for_each_dev(adev, &ap->link, ENABLED) {
if (adev->class == ATA_DEV_ATAPI)
fifo = 0;
}
if (pdev->device == PCI_DEVICE_ID_AMD_VIPER_7411)
fifo = 0;
pci_read_config_byte(pdev, 0x41, &r);
r &= ~fifobit[ap->port_no];
r |= fifo;
pci_write_config_byte(pdev, 0x41, r);
}
static void amd33_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
amd_fifo_setup(ap);
timing_setup(ap, adev, 0x40, adev->pio_mode, 1);
}
static void amd66_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
amd_fifo_setup(ap);
timing_setup(ap, adev, 0x40, adev->pio_mode, 2);
}
static void amd100_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
amd_fifo_setup(ap);
timing_setup(ap, adev, 0x40, adev->pio_mode, 3);
}
static void amd133_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
amd_fifo_setup(ap);
timing_setup(ap, adev, 0x40, adev->pio_mode, 4);
}
static void amd33_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x40, adev->dma_mode, 1);
}
static void amd66_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x40, adev->dma_mode, 2);
}
static void amd100_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x40, adev->dma_mode, 3);
}
static void amd133_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x40, adev->dma_mode, 4);
}
static unsigned long nv_mode_filter(struct ata_device *dev,
unsigned long xfer_mask)
{
static const unsigned int udma_mask_map[] =
{ ATA_UDMA2, ATA_UDMA1, ATA_UDMA0, 0,
ATA_UDMA3, ATA_UDMA4, ATA_UDMA5, ATA_UDMA6 };
struct ata_port *ap = dev->link->ap;
char acpi_str[32] = "";
u32 saved_udma, udma;
const struct ata_acpi_gtm *gtm;
unsigned long bios_limit = 0, acpi_limit = 0, limit;
udma = saved_udma = (unsigned long)ap->host->private_data;
if (ap->port_no == 0)
udma >>= 16;
if (dev->devno == 0)
udma >>= 8;
if ((udma & 0xc0) == 0xc0)
bios_limit = ata_pack_xfermask(0, 0, udma_mask_map[udma & 0x7]);
gtm = ata_acpi_init_gtm(ap);
if (gtm) {
acpi_limit = ata_acpi_gtm_xfermask(dev, gtm);
snprintf(acpi_str, sizeof(acpi_str), " (%u:%u:0x%x)",
gtm->drive[0].dma, gtm->drive[1].dma, gtm->flags);
}
limit = bios_limit | acpi_limit;
if (!(limit & ATA_MASK_PIO))
limit |= ATA_MASK_PIO;
if (!(limit & (ATA_MASK_MWDMA | ATA_MASK_UDMA)))
limit |= ATA_MASK_MWDMA | ATA_MASK_UDMA;
limit |= ata_pack_xfermask(ATA_PIO4, ATA_MWDMA2, ATA_UDMA2);
ata_port_dbg(ap, "nv_mode_filter: 0x%lx&0x%lx->0x%lx, "
"BIOS=0x%lx (0x%x) ACPI=0x%lx%s\n",
xfer_mask, limit, xfer_mask & limit, bios_limit,
saved_udma, acpi_limit, acpi_str);
return xfer_mask & limit;
}
static int nv_pre_reset(struct ata_link *link, unsigned long deadline)
{
static const struct pci_bits nv_enable_bits[] = {
{ 0x50, 1, 0x02, 0x02 },
{ 0x50, 1, 0x01, 0x01 }
};
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &nv_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void nv100_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x50, adev->pio_mode, 3);
}
static void nv133_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x50, adev->pio_mode, 4);
}
static void nv100_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x50, adev->dma_mode, 3);
}
static void nv133_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
timing_setup(ap, adev, 0x50, adev->dma_mode, 4);
}
static void nv_host_stop(struct ata_host *host)
{
u32 udma = (unsigned long)host->private_data;
pci_write_config_dword(to_pci_dev(host->dev), 0x60, udma);
}
static void amd_clear_fifo(struct pci_dev *pdev)
{
u8 fifo;
pci_read_config_byte(pdev, 0x41, &fifo);
fifo &= 0x0F;
pci_write_config_byte(pdev, 0x41, fifo);
}
static int amd_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info[10] = {
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &amd33_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &amd66_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &amd66_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &amd100_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &amd100_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &amd133_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &amd133_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &nv100_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &nv133_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &amd100_port_ops
}
};
const struct ata_port_info *ppi[] = { NULL, NULL };
int type = id->driver_data;
void *hpriv = NULL;
u8 fifo;
int rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
pci_read_config_byte(pdev, 0x41, &fifo);
if (type == 1 && pdev->revision > 0x7)
type = 2;
if (type == 5 && pdev->subsystem_vendor == PCI_VENDOR_ID_AMD &&
pdev->subsystem_device == PCI_DEVICE_ID_AMD_SERENADE)
type = 6;
ppi[0] = &info[type];
if (type < 3)
ata_pci_bmdma_clear_simplex(pdev);
if (pdev->vendor == PCI_VENDOR_ID_AMD)
amd_clear_fifo(pdev);
if (type == 7 || type == 8) {
u32 udma;
pci_read_config_dword(pdev, 0x60, &udma);
hpriv = (void *)(unsigned long)udma;
}
return ata_pci_bmdma_init_one(pdev, ppi, &amd_sht, hpriv, 0);
}
static int amd_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->vendor == PCI_VENDOR_ID_AMD) {
amd_clear_fifo(pdev);
if (pdev->device == PCI_DEVICE_ID_AMD_VIPER_7409 ||
pdev->device == PCI_DEVICE_ID_AMD_COBRA_7401)
ata_pci_bmdma_clear_simplex(pdev);
}
ata_host_resume(host);
return 0;
}
static int __init amd_init(void)
{
return pci_register_driver(&amd_pci_driver);
}
static void __exit amd_exit(void)
{
pci_unregister_driver(&amd_pci_driver);
}
