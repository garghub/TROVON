static int oem_cable(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (pdev->subsystem_device & (1 << (ap->port_no + 14)))
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static int serverworks_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct sv_cable_table *cb = cable_detect;
while(cb->device) {
if (cb->device == pdev->device &&
(cb->subvendor == pdev->subsystem_vendor ||
cb->subvendor == PCI_ANY_ID)) {
return cb->cable_detect(ap);
}
cb++;
}
BUG();
return -1;
}
static u8 serverworks_is_csb(struct pci_dev *pdev)
{
switch (pdev->device) {
case PCI_DEVICE_ID_SERVERWORKS_CSB5IDE:
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE:
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2:
case PCI_DEVICE_ID_SERVERWORKS_HT1000IDE:
return 1;
default:
break;
}
return 0;
}
static unsigned long serverworks_osb4_filter(struct ata_device *adev, unsigned long mask)
{
if (adev->class == ATA_DEV_ATA)
mask &= ~ATA_MASK_UDMA;
return mask;
}
static unsigned long serverworks_csb_filter(struct ata_device *adev, unsigned long mask)
{
const char *p;
char model_num[ATA_ID_PROD_LEN + 1];
int i;
if (adev->class != ATA_DEV_ATA)
return mask;
ata_id_c_string(adev->id, model_num, ATA_ID_PROD, sizeof(model_num));
for (i = 0; (p = csb_bad_ata100[i]) != NULL; i++) {
if (!strcmp(p, model_num))
mask &= ~(0xE0 << ATA_SHIFT_UDMA);
}
return mask;
}
static void serverworks_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u8 pio_mode[] = { 0x5d, 0x47, 0x34, 0x22, 0x20 };
int offset = 1 + 2 * ap->port_no - adev->devno;
int devbits = (2 * ap->port_no + adev->devno) * 4;
u16 csb5_pio;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int pio = adev->pio_mode - XFER_PIO_0;
pci_write_config_byte(pdev, 0x40 + offset, pio_mode[pio]);
if (serverworks_is_csb(pdev)) {
pci_read_config_word(pdev, 0x4A, &csb5_pio);
csb5_pio &= ~(0x0F << devbits);
pci_write_config_word(pdev, 0x4A, csb5_pio | (pio << devbits));
}
}
static void serverworks_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u8 dma_mode[] = { 0x77, 0x21, 0x20 };
int offset = 1 + 2 * ap->port_no - adev->devno;
int devbits = 2 * ap->port_no + adev->devno;
u8 ultra;
u8 ultra_cfg;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
pci_read_config_byte(pdev, 0x54, &ultra_cfg);
pci_read_config_byte(pdev, 0x56 + ap->port_no, &ultra);
ultra &= ~(0x0F << (adev->devno * 4));
if (adev->dma_mode >= XFER_UDMA_0) {
pci_write_config_byte(pdev, 0x44 + offset, 0x20);
ultra |= (adev->dma_mode - XFER_UDMA_0)
<< (adev->devno * 4);
ultra_cfg |= (1 << devbits);
} else {
pci_write_config_byte(pdev, 0x44 + offset,
dma_mode[adev->dma_mode - XFER_MW_DMA_0]);
ultra_cfg &= ~(1 << devbits);
}
pci_write_config_byte(pdev, 0x56 + ap->port_no, ultra);
pci_write_config_byte(pdev, 0x54, ultra_cfg);
}
static int serverworks_fixup_osb4(struct pci_dev *pdev)
{
u32 reg;
struct pci_dev *isa_dev = pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_OSB4, NULL);
if (isa_dev) {
pci_read_config_dword(isa_dev, 0x64, &reg);
reg &= ~0x00002000;
if (!(reg & 0x00004000))
printk(KERN_DEBUG DRV_NAME ": UDMA not BIOS enabled.\n");
reg |= 0x00004000;
pci_write_config_dword(isa_dev, 0x64, reg);
pci_dev_put(isa_dev);
return 0;
}
printk(KERN_WARNING DRV_NAME ": Unable to find bridge.\n");
return -ENODEV;
}
static int serverworks_fixup_csb(struct pci_dev *pdev)
{
u8 btr;
if (!(PCI_FUNC(pdev->devfn) & 1)) {
struct pci_dev * findev = NULL;
u32 reg4c = 0;
findev = pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_CSB5, NULL);
if (findev) {
pci_read_config_dword(findev, 0x4C, &reg4c);
reg4c &= ~0x000007FF;
reg4c |= 0x00000040;
reg4c |= 0x00000020;
pci_write_config_dword(findev, 0x4C, reg4c);
pci_dev_put(findev);
}
} else {
struct pci_dev * findev = NULL;
u8 reg41 = 0;
findev = pci_get_device(PCI_VENDOR_ID_SERVERWORKS,
PCI_DEVICE_ID_SERVERWORKS_CSB6, NULL);
if (findev) {
pci_read_config_byte(findev, 0x41, &reg41);
reg41 &= ~0x40;
pci_write_config_byte(findev, 0x41, reg41);
pci_dev_put(findev);
}
}
pci_read_config_byte(pdev, 0x5A, &btr);
btr &= ~0x40;
if (!(PCI_FUNC(pdev->devfn) & 1))
btr |= 0x2;
else
btr |= (pdev->revision >= SVWKS_CSB5_REVISION_NEW) ? 0x3 : 0x2;
pci_write_config_byte(pdev, 0x5A, btr);
return btr;
}
static void serverworks_fixup_ht1000(struct pci_dev *pdev)
{
u8 btr;
pci_read_config_byte(pdev, 0x5A, &btr);
btr &= ~0x40;
btr |= 0x3;
pci_write_config_byte(pdev, 0x5A, btr);
}
static int serverworks_fixup(struct pci_dev *pdev)
{
int rc = 0;
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x40);
switch (pdev->device) {
case PCI_DEVICE_ID_SERVERWORKS_OSB4IDE:
rc = serverworks_fixup_osb4(pdev);
break;
case PCI_DEVICE_ID_SERVERWORKS_CSB5IDE:
ata_pci_bmdma_clear_simplex(pdev);
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE:
case PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2:
rc = serverworks_fixup_csb(pdev);
break;
case PCI_DEVICE_ID_SERVERWORKS_HT1000IDE:
serverworks_fixup_ht1000(pdev);
break;
}
return rc;
}
static int serverworks_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info[4] = {
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &serverworks_osb4_port_ops
}, {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &serverworks_osb4_port_ops
}, {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &serverworks_csb_port_ops
}, {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &serverworks_csb_port_ops
}
};
const struct ata_port_info *ppi[] = { &info[id->driver_data], NULL };
int rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = serverworks_fixup(pdev);
if (pdev->device == PCI_DEVICE_ID_SERVERWORKS_OSB4IDE) {
if (rc < 0)
ppi[0] = &info[1];
}
else if ((pdev->device == PCI_DEVICE_ID_SERVERWORKS_CSB5IDE) ||
(pdev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE) ||
(pdev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2)) {
if (rc == 3)
ppi[0] = &info[3];
if (pdev->device == PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2)
ppi[1] = &ata_dummy_port_info;
}
return ata_pci_bmdma_init_one(pdev, ppi, &serverworks_sht, NULL, 0);
}
static int serverworks_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
(void)serverworks_fixup(pdev);
ata_host_resume(host);
return 0;
}
static int __init serverworks_init(void)
{
return pci_register_driver(&serverworks_pci_driver);
}
static void __exit serverworks_exit(void)
{
pci_unregister_driver(&serverworks_pci_driver);
}
