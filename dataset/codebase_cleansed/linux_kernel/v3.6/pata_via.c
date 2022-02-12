static int via_cable_override(struct pci_dev *pdev)
{
if (dmi_check_system(cable_dmi_table))
return 1;
if (pdev->subsystem_vendor == 0x161F && pdev->subsystem_device == 0x2032)
return 1;
return 0;
}
static int via_cable_detect(struct ata_port *ap) {
const struct via_isa_bridge *config = ap->host->private_data;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 ata66;
if (via_cable_override(pdev))
return ATA_CBL_PATA40_SHORT;
if ((config->flags & VIA_SATA_PATA) && ap->port_no == 0)
return ATA_CBL_SATA;
if (config->udma_mask < ATA_UDMA4)
return ATA_CBL_PATA40;
else if (config->udma_mask < ATA_UDMA5)
return ATA_CBL_PATA_UNK;
pci_read_config_dword(pdev, 0x50, &ata66);
if (ata66 & (0x10100000 >> (16 * ap->port_no)))
return ATA_CBL_PATA80;
if (ata_acpi_init_gtm(ap) &&
ata_acpi_cbl_80wire(ap, ata_acpi_init_gtm(ap)))
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static int via_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
const struct via_isa_bridge *config = ap->host->private_data;
if (!(config->flags & VIA_NO_ENABLES)) {
static const struct pci_bits via_enable_bits[] = {
{ 0x40, 1, 0x02, 0x02 },
{ 0x40, 1, 0x01, 0x01 }
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &via_enable_bits[ap->port_no]))
return -ENOENT;
}
return ata_sff_prereset(link, deadline);
}
static void via_do_set_mode(struct ata_port *ap, struct ata_device *adev,
int mode, int set_ast, int udma_type)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_device *peer = ata_dev_pair(adev);
struct ata_timing t, p;
static int via_clock = 33333;
unsigned long T = 1000000000 / via_clock;
unsigned long UT = T;
int ut;
int offset = 3 - (2*ap->port_no) - adev->devno;
switch (udma_type) {
case ATA_UDMA4:
UT = T / 2; break;
case ATA_UDMA5:
UT = T / 3; break;
case ATA_UDMA6:
UT = T / 4; break;
}
ata_timing_compute(adev, mode, &t, T, UT);
if (peer) {
if (peer->pio_mode) {
ata_timing_compute(peer, peer->pio_mode, &p, T, UT);
ata_timing_merge(&p, &t, &t, ATA_TIMING_8BIT);
}
}
if (set_ast) {
u8 setup;
int shift = 2 * offset;
pci_read_config_byte(pdev, 0x4C, &setup);
setup &= ~(3 << shift);
setup |= (clamp_val(t.setup, 1, 4) - 1) << shift;
pci_write_config_byte(pdev, 0x4C, setup);
}
pci_write_config_byte(pdev, 0x4F - ap->port_no,
((clamp_val(t.act8b, 1, 16) - 1) << 4) | (clamp_val(t.rec8b, 1, 16) - 1));
pci_write_config_byte(pdev, 0x48 + offset,
((clamp_val(t.active, 1, 16) - 1) << 4) | (clamp_val(t.recover, 1, 16) - 1));
switch (udma_type) {
case ATA_UDMA2:
default:
ut = t.udma ? (0xe0 | (clamp_val(t.udma, 2, 5) - 2)) : 0x03;
break;
case ATA_UDMA4:
ut = t.udma ? (0xe8 | (clamp_val(t.udma, 2, 9) - 2)) : 0x0f;
break;
case ATA_UDMA5:
ut = t.udma ? (0xe0 | (clamp_val(t.udma, 2, 9) - 2)) : 0x07;
break;
case ATA_UDMA6:
ut = t.udma ? (0xe0 | (clamp_val(t.udma, 2, 9) - 2)) : 0x07;
break;
}
if (udma_type) {
u8 udma_etc;
pci_read_config_byte(pdev, 0x50 + offset, &udma_etc);
udma_etc &= ~0x20;
if (t.udma) {
udma_etc &= 0x10;
udma_etc |= ut;
}
pci_write_config_byte(pdev, 0x50 + offset, udma_etc);
}
}
static void via_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
const struct via_isa_bridge *config = ap->host->private_data;
int set_ast = (config->flags & VIA_BAD_AST) ? 0 : 1;
via_do_set_mode(ap, adev, adev->pio_mode, set_ast, config->udma_mask);
}
static void via_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
const struct via_isa_bridge *config = ap->host->private_data;
int set_ast = (config->flags & VIA_BAD_AST) ? 0 : 1;
via_do_set_mode(ap, adev, adev->dma_mode, set_ast, config->udma_mask);
}
static unsigned long via_mode_filter(struct ata_device *dev, unsigned long mask)
{
struct ata_host *host = dev->link->ap->host;
const struct via_isa_bridge *config = host->private_data;
unsigned char model_num[ATA_ID_PROD_LEN + 1];
if (config->id == PCI_DEVICE_ID_VIA_82C586_0) {
ata_id_c_string(dev->id, model_num, ATA_ID_PROD, sizeof(model_num));
if (strcmp(model_num, "TS64GSSD25-M") == 0) {
ata_dev_warn(dev,
"disabling UDMA mode due to reported lockups with this device\n");
mask &= ~ ATA_MASK_UDMA;
}
}
if (dev->class == ATA_DEV_ATAPI &&
dmi_check_system(no_atapi_dma_dmi_table)) {
ata_dev_warn(dev, "controller locks up on ATAPI DMA, forcing PIO\n");
mask &= ATA_MASK_PIO;
}
return mask;
}
static void via_tf_load(struct ata_port *ap, const struct ata_taskfile *tf)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
struct via_port *vp = ap->private_data;
unsigned int is_addr = tf->flags & ATA_TFLAG_ISADDR;
int newctl = 0;
if (tf->ctl != ap->last_ctl) {
iowrite8(tf->ctl, ioaddr->ctl_addr);
ap->last_ctl = tf->ctl;
ata_wait_idle(ap);
newctl = 1;
}
if (tf->flags & ATA_TFLAG_DEVICE) {
iowrite8(tf->device, ioaddr->device_addr);
vp->cached_device = tf->device;
} else if (newctl)
iowrite8(vp->cached_device, ioaddr->device_addr);
if (is_addr && (tf->flags & ATA_TFLAG_LBA48)) {
WARN_ON_ONCE(!ioaddr->ctl_addr);
iowrite8(tf->hob_feature, ioaddr->feature_addr);
iowrite8(tf->hob_nsect, ioaddr->nsect_addr);
iowrite8(tf->hob_lbal, ioaddr->lbal_addr);
iowrite8(tf->hob_lbam, ioaddr->lbam_addr);
iowrite8(tf->hob_lbah, ioaddr->lbah_addr);
VPRINTK("hob: feat 0x%X nsect 0x%X, lba 0x%X 0x%X 0x%X\n",
tf->hob_feature,
tf->hob_nsect,
tf->hob_lbal,
tf->hob_lbam,
tf->hob_lbah);
}
if (is_addr) {
iowrite8(tf->feature, ioaddr->feature_addr);
iowrite8(tf->nsect, ioaddr->nsect_addr);
iowrite8(tf->lbal, ioaddr->lbal_addr);
iowrite8(tf->lbam, ioaddr->lbam_addr);
iowrite8(tf->lbah, ioaddr->lbah_addr);
VPRINTK("feat 0x%X nsect 0x%X lba 0x%X 0x%X 0x%X\n",
tf->feature,
tf->nsect,
tf->lbal,
tf->lbam,
tf->lbah);
}
ata_wait_idle(ap);
}
static int via_port_start(struct ata_port *ap)
{
struct via_port *vp;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int ret = ata_bmdma_port_start(ap);
if (ret < 0)
return ret;
vp = devm_kzalloc(&pdev->dev, sizeof(struct via_port), GFP_KERNEL);
if (vp == NULL)
return -ENOMEM;
ap->private_data = vp;
return 0;
}
static void via_config_fifo(struct pci_dev *pdev, unsigned int flags)
{
u8 enable;
pci_read_config_byte(pdev, 0x40 , &enable);
enable &= 3;
if (flags & VIA_SET_FIFO) {
static const u8 fifo_setting[4] = {0x00, 0x60, 0x00, 0x20};
u8 fifo;
pci_read_config_byte(pdev, 0x43, &fifo);
if (flags & VIA_BAD_PREQ)
fifo &= 0x7F;
else
fifo &= 0x9f;
fifo |= fifo_setting[enable];
pci_write_config_byte(pdev, 0x43, fifo);
}
}
static void via_fixup(struct pci_dev *pdev, const struct via_isa_bridge *config)
{
u32 timing;
via_config_fifo(pdev, config->flags);
if (config->udma_mask == ATA_UDMA4) {
pci_read_config_dword(pdev, 0x50, &timing);
timing |= 0x80008;
pci_write_config_dword(pdev, 0x50, timing);
}
if (config->flags & VIA_BAD_CLK66) {
pci_read_config_dword(pdev, 0x50, &timing);
timing &= ~0x80008;
pci_write_config_dword(pdev, 0x50, timing);
}
}
static int via_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info via_mwdma_info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &via_port_ops
};
static const struct ata_port_info via_mwdma_info_borked = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &via_port_ops_noirq,
};
static const struct ata_port_info via_udma33_info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &via_port_ops
};
static const struct ata_port_info via_udma66_info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &via_port_ops
};
static const struct ata_port_info via_udma100_info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &via_port_ops
};
static const struct ata_port_info via_udma133_info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &via_port_ops
};
const struct ata_port_info *ppi[] = { NULL, NULL };
struct pci_dev *isa;
const struct via_isa_bridge *config;
u8 enable;
unsigned long flags = id->driver_data;
int rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (flags & VIA_IDFLAG_SINGLE)
ppi[1] = &ata_dummy_port_info;
for (config = via_isa_bridges; config->id != PCI_DEVICE_ID_VIA_ANON;
config++)
if ((isa = pci_get_device(PCI_VENDOR_ID_VIA +
!!(config->flags & VIA_BAD_ID),
config->id, NULL))) {
u8 rev = isa->revision;
pci_dev_put(isa);
if ((id->device == 0x0415 || id->device == 0x3164) &&
(config->id != id->device))
continue;
if (rev >= config->rev_min && rev <= config->rev_max)
break;
}
if (!(config->flags & VIA_NO_ENABLES)) {
pci_read_config_byte(pdev, 0x40 , &enable);
enable &= 3;
if (enable == 0)
return -ENODEV;
}
switch (config->udma_mask) {
case 0x00:
if (config->flags & VIA_NO_UNMASK)
ppi[0] = &via_mwdma_info_borked;
else
ppi[0] = &via_mwdma_info;
break;
case ATA_UDMA2:
ppi[0] = &via_udma33_info;
break;
case ATA_UDMA4:
ppi[0] = &via_udma66_info;
break;
case ATA_UDMA5:
ppi[0] = &via_udma100_info;
break;
case ATA_UDMA6:
ppi[0] = &via_udma133_info;
break;
default:
WARN_ON(1);
return -ENODEV;
}
via_fixup(pdev, config);
return ata_pci_bmdma_init_one(pdev, ppi, &via_sht, (void *)config, 0);
}
static int via_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
via_fixup(pdev, host->private_data);
ata_host_resume(host);
return 0;
}
