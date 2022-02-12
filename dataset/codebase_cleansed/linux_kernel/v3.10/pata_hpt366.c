static u32 hpt36x_find_mode(struct ata_port *ap, int speed)
{
struct hpt_clock *clocks = ap->host->private_data;
while (clocks->xfer_mode) {
if (clocks->xfer_mode == speed)
return clocks->timing;
clocks++;
}
BUG();
return 0xffffffffU;
}
static int hpt_dma_blacklisted(const struct ata_device *dev, char *modestr,
const char * const list[])
{
unsigned char model_num[ATA_ID_PROD_LEN + 1];
int i = 0;
ata_id_c_string(dev->id, model_num, ATA_ID_PROD, sizeof(model_num));
while (list[i] != NULL) {
if (!strcmp(list[i], model_num)) {
pr_warn("%s is not supported for %s\n",
modestr, list[i]);
return 1;
}
i++;
}
return 0;
}
static unsigned long hpt366_filter(struct ata_device *adev, unsigned long mask)
{
if (adev->class == ATA_DEV_ATA) {
if (hpt_dma_blacklisted(adev, "UDMA", bad_ata33))
mask &= ~ATA_MASK_UDMA;
if (hpt_dma_blacklisted(adev, "UDMA3", bad_ata66_3))
mask &= ~(0xF8 << ATA_SHIFT_UDMA);
if (hpt_dma_blacklisted(adev, "UDMA4", bad_ata66_4))
mask &= ~(0xF0 << ATA_SHIFT_UDMA);
} else if (adev->class == ATA_DEV_ATAPI)
mask &= ~(ATA_MASK_MWDMA | ATA_MASK_UDMA);
return mask;
}
static int hpt36x_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 ata66;
pci_read_config_byte(pdev, 0x5A, &ata66);
if (ata66 & 2)
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
}
static void hpt366_set_mode(struct ata_port *ap, struct ata_device *adev,
u8 mode)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 addr = 0x40 + 4 * adev->devno;
u32 mask, reg, t;
if (mode < XFER_MW_DMA_0)
mask = 0xc1f8ffff;
else if (mode < XFER_UDMA_0)
mask = 0x303800ff;
else
mask = 0x30070000;
t = hpt36x_find_mode(ap, mode);
pci_read_config_dword(pdev, addr, &reg);
reg = ((reg & ~mask) | (t & mask)) & ~0xc0000000;
pci_write_config_dword(pdev, addr, reg);
}
static void hpt366_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
hpt366_set_mode(ap, adev, adev->pio_mode);
}
static void hpt366_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
hpt366_set_mode(ap, adev, adev->dma_mode);
}
static void hpt36x_init_chipset(struct pci_dev *dev)
{
u8 drive_fast;
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, (L1_CACHE_BYTES / 4));
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x78);
pci_write_config_byte(dev, PCI_MIN_GNT, 0x08);
pci_write_config_byte(dev, PCI_MAX_LAT, 0x08);
pci_read_config_byte(dev, 0x51, &drive_fast);
if (drive_fast & 0x80)
pci_write_config_byte(dev, 0x51, drive_fast & ~0x80);
}
static int hpt36x_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info_hpt366 = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &hpt366_port_ops
};
const struct ata_port_info *ppi[] = { &info_hpt366, NULL };
void *hpriv = NULL;
u32 reg1;
int rc;
rc = pcim_enable_device(dev);
if (rc)
return rc;
if (dev->revision > 2)
return -ENODEV;
hpt36x_init_chipset(dev);
pci_read_config_dword(dev, 0x40, &reg1);
switch ((reg1 & 0x700) >> 8) {
case 9:
hpriv = &hpt366_40;
break;
case 5:
hpriv = &hpt366_25;
break;
default:
hpriv = &hpt366_33;
break;
}
return ata_pci_bmdma_init_one(dev, ppi, &hpt36x_sht, hpriv, 0);
}
static int hpt36x_reinit_one(struct pci_dev *dev)
{
struct ata_host *host = dev_get_drvdata(&dev->dev);
int rc;
rc = ata_pci_device_do_resume(dev);
if (rc)
return rc;
hpt36x_init_chipset(dev);
ata_host_resume(host);
return 0;
}
