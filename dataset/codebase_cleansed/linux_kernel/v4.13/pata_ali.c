static int ali_cable_override(struct pci_dev *pdev)
{
if (pdev->subsystem_vendor == 0x10CF && pdev->subsystem_device == 0x10AF)
return 1;
if (pdev->subsystem_vendor == 0x1071 && pdev->subsystem_device == 0x8317)
return 1;
if (dmi_check_system(cable_dmi_table))
return 1;
return 0;
}
static int ali_c2_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 ata66;
if (ali_cable_override(pdev))
return ATA_CBL_PATA40_SHORT;
pci_read_config_byte(pdev, 0x4A, &ata66);
if (ata66 & (1 << ap->port_no))
return ATA_CBL_PATA40;
else
return ATA_CBL_PATA80;
}
static unsigned long ali_20_filter(struct ata_device *adev, unsigned long mask)
{
char model_num[ATA_ID_PROD_LEN + 1];
if (adev->class != ATA_DEV_ATA)
mask &= ~(ATA_MASK_MWDMA | ATA_MASK_UDMA);
ata_id_c_string(adev->id, model_num, ATA_ID_PROD, sizeof(model_num));
if (strstr(model_num, "WDC"))
return mask &= ~ATA_MASK_UDMA;
return mask;
}
static void ali_fifo_control(struct ata_port *ap, struct ata_device *adev, int on)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int pio_fifo = 0x54 + ap->port_no;
u8 fifo;
int shift = 4 * adev->devno;
pci_read_config_byte(pdev, pio_fifo, &fifo);
fifo &= ~(0x0F << shift);
fifo |= (on << shift);
pci_write_config_byte(pdev, pio_fifo, fifo);
}
static void ali_program_modes(struct ata_port *ap, struct ata_device *adev, struct ata_timing *t, u8 ultra)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int cas = 0x58 + 4 * ap->port_no;
int cbt = 0x59 + 4 * ap->port_no;
int drwt = 0x5A + 4 * ap->port_no + adev->devno;
int udmat = 0x56 + ap->port_no;
int shift = 4 * adev->devno;
u8 udma;
if (t != NULL) {
t->setup = clamp_val(t->setup, 1, 8) & 7;
t->act8b = clamp_val(t->act8b, 1, 8) & 7;
t->rec8b = clamp_val(t->rec8b, 1, 16) & 15;
t->active = clamp_val(t->active, 1, 8) & 7;
t->recover = clamp_val(t->recover, 1, 16) & 15;
pci_write_config_byte(pdev, cas, t->setup);
pci_write_config_byte(pdev, cbt, (t->act8b << 4) | t->rec8b);
pci_write_config_byte(pdev, drwt, (t->active << 4) | t->recover);
}
pci_read_config_byte(pdev, udmat, &udma);
udma &= ~(0x0F << shift);
udma |= ultra << shift;
pci_write_config_byte(pdev, udmat, udma);
}
static void ali_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct ata_device *pair = ata_dev_pair(adev);
struct ata_timing t;
unsigned long T = 1000000000 / 33333;
ata_timing_compute(adev, adev->pio_mode, &t, T, 1);
if (pair) {
struct ata_timing p;
ata_timing_compute(pair, pair->pio_mode, &p, T, 1);
ata_timing_merge(&p, &t, &t, ATA_TIMING_SETUP|ATA_TIMING_8BIT);
if (pair->dma_mode) {
ata_timing_compute(pair, pair->dma_mode, &p, T, 1);
ata_timing_merge(&p, &t, &t, ATA_TIMING_SETUP|ATA_TIMING_8BIT);
}
}
if (adev->class != ATA_DEV_ATA)
ali_fifo_control(ap, adev, 0x00);
ali_program_modes(ap, adev, &t, 0);
if (adev->class == ATA_DEV_ATA)
ali_fifo_control(ap, adev, 0x05);
}
static void ali_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static u8 udma_timing[7] = { 0xC, 0xB, 0xA, 0x9, 0x8, 0xF, 0xD };
struct ata_device *pair = ata_dev_pair(adev);
struct ata_timing t;
unsigned long T = 1000000000 / 33333;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (adev->class == ATA_DEV_ATA)
ali_fifo_control(ap, adev, 0x08);
if (adev->dma_mode >= XFER_UDMA_0) {
ali_program_modes(ap, adev, NULL, udma_timing[adev->dma_mode - XFER_UDMA_0]);
if (adev->dma_mode >= XFER_UDMA_3) {
u8 reg4b;
pci_read_config_byte(pdev, 0x4B, &reg4b);
reg4b |= 1;
pci_write_config_byte(pdev, 0x4B, reg4b);
}
} else {
ata_timing_compute(adev, adev->dma_mode, &t, T, 1);
if (pair) {
struct ata_timing p;
ata_timing_compute(pair, pair->pio_mode, &p, T, 1);
ata_timing_merge(&p, &t, &t, ATA_TIMING_SETUP|ATA_TIMING_8BIT);
if (pair->dma_mode) {
ata_timing_compute(pair, pair->dma_mode, &p, T, 1);
ata_timing_merge(&p, &t, &t, ATA_TIMING_SETUP|ATA_TIMING_8BIT);
}
}
ali_program_modes(ap, adev, &t, 0);
}
}
static void ali_warn_atapi_dma(struct ata_device *adev)
{
struct ata_eh_context *ehc = &adev->link->eh_context;
int print_info = ehc->i.flags & ATA_EHI_PRINTINFO;
if (print_info && adev->class == ATA_DEV_ATAPI && !ali_atapi_dma) {
ata_dev_warn(adev,
"WARNING: ATAPI DMA disabled for reliability issues. It can be enabled\n");
ata_dev_warn(adev,
"WARNING: via pata_ali.atapi_dma modparam or corresponding sysfs node.\n");
}
}
static void ali_lock_sectors(struct ata_device *adev)
{
adev->max_sectors = 255;
ali_warn_atapi_dma(adev);
}
static int ali_check_atapi_dma(struct ata_queued_cmd *qc)
{
if (!ali_atapi_dma) {
return -EOPNOTSUPP;
}
if (atapi_cmd_type(qc->cdb[0]) == ATAPI_MISC)
return -EOPNOTSUPP;
return 0;
}
static void ali_c2_c3_postreset(struct ata_link *link, unsigned int *classes)
{
u8 r;
int port_bit = 4 << link->ap->port_no;
if (ali_isa_bridge) {
pci_read_config_byte(ali_isa_bridge, 0x58, &r);
r &= ~port_bit;
pci_write_config_byte(ali_isa_bridge, 0x58, r);
r |= port_bit;
pci_write_config_byte(ali_isa_bridge, 0x58, r);
}
ata_sff_postreset(link, classes);
}
static void ali_init_chipset(struct pci_dev *pdev)
{
u8 tmp;
struct pci_dev *north;
if (pdev->revision <= 0x20) {
pci_read_config_byte(pdev, 0x53, &tmp);
tmp |= 0x03;
pci_write_config_byte(pdev, 0x53, tmp);
} else {
pci_read_config_byte(pdev, 0x4a, &tmp);
pci_write_config_byte(pdev, 0x4a, tmp | 0x20);
pci_read_config_byte(pdev, 0x4B, &tmp);
if (pdev->revision < 0xC2)
tmp &= 0x7F;
if (pdev->revision >= 0xc2)
tmp |= 0x01;
pci_write_config_byte(pdev, 0x4B, tmp | 0x08);
pci_read_config_byte(pdev, 0x53, &tmp);
if (pdev->revision >= 0xc7)
tmp |= 0x03;
else
tmp |= 0x01;
pci_write_config_byte(pdev, 0x53, tmp);
}
north = pci_get_bus_and_slot(0, PCI_DEVFN(0,0));
if (north && north->vendor == PCI_VENDOR_ID_AL && ali_isa_bridge) {
pci_read_config_byte(ali_isa_bridge, 0x79, &tmp);
if (pdev->revision == 0xC2)
pci_write_config_byte(ali_isa_bridge, 0x79, tmp | 0x04);
else if (pdev->revision > 0xC2 && pdev->revision < 0xC5)
pci_write_config_byte(ali_isa_bridge, 0x79, tmp | 0x02);
}
pci_dev_put(north);
ata_pci_bmdma_clear_simplex(pdev);
}
static int ali_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info_early = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.port_ops = &ali_early_port_ops
};
static const struct ata_port_info info_20 = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_PIO_LBA48 |
ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &ali_20_port_ops
};
static const struct ata_port_info info_20_udma = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_PIO_LBA48 |
ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &ali_20_port_ops
};
static const struct ata_port_info info_c2 = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_PIO_LBA48 |
ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &ali_c2_port_ops
};
static const struct ata_port_info info_c3 = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_PIO_LBA48 |
ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &ali_c2_port_ops
};
static const struct ata_port_info info_c4 = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_PIO_LBA48 |
ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &ali_c4_port_ops
};
static const struct ata_port_info info_c5 = {
.flags = ATA_FLAG_SLAVE_POSS | ATA_FLAG_IGN_SIMPLEX,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &ali_c5_port_ops
};
const struct ata_port_info *ppi[] = { NULL, NULL };
u8 tmp;
int rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (pdev->revision < 0x20) {
ppi[0] = &info_early;
} else if (pdev->revision < 0xC2) {
ppi[0] = &info_20;
} else if (pdev->revision == 0xC2) {
ppi[0] = &info_c2;
} else if (pdev->revision == 0xC3) {
ppi[0] = &info_c3;
} else if (pdev->revision == 0xC4) {
ppi[0] = &info_c4;
} else
ppi[0] = &info_c5;
ali_init_chipset(pdev);
if (ali_isa_bridge && pdev->revision >= 0x20 && pdev->revision < 0xC2) {
pci_read_config_byte(ali_isa_bridge, 0x5E, &tmp);
if ((tmp & 0x1E) == 0x12)
ppi[0] = &info_20_udma;
}
if (!ppi[0]->mwdma_mask && !ppi[0]->udma_mask)
return ata_pci_sff_init_one(pdev, ppi, &ali_sht, NULL, 0);
else
return ata_pci_bmdma_init_one(pdev, ppi, &ali_sht, NULL, 0);
}
static int ali_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
ali_init_chipset(pdev);
ata_host_resume(host);
return 0;
}
static int __init ali_init(void)
{
int ret;
ali_isa_bridge = pci_get_device(PCI_VENDOR_ID_AL, PCI_DEVICE_ID_AL_M1533, NULL);
ret = pci_register_driver(&ali_pci_driver);
if (ret < 0)
pci_dev_put(ali_isa_bridge);
return ret;
}
static void __exit ali_exit(void)
{
pci_unregister_driver(&ali_pci_driver);
pci_dev_put(ali_isa_bridge);
}
