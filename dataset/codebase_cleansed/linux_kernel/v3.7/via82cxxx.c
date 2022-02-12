static void via_set_speed(ide_hwif_t *hwif, u8 dn, struct ide_timing *timing)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
struct ide_host *host = pci_get_drvdata(dev);
struct via82cxxx_dev *vdev = host->host_priv;
u8 t;
if (~vdev->via_config->flags & VIA_BAD_AST) {
pci_read_config_byte(dev, VIA_ADDRESS_SETUP, &t);
t = (t & ~(3 << ((3 - dn) << 1))) | ((clamp_val(timing->setup, 1, 4) - 1) << ((3 - dn) << 1));
pci_write_config_byte(dev, VIA_ADDRESS_SETUP, t);
}
pci_write_config_byte(dev, VIA_8BIT_TIMING + (1 - (dn >> 1)),
((clamp_val(timing->act8b, 1, 16) - 1) << 4) | (clamp_val(timing->rec8b, 1, 16) - 1));
pci_write_config_byte(dev, VIA_DRIVE_TIMING + (3 - dn),
((clamp_val(timing->active, 1, 16) - 1) << 4) | (clamp_val(timing->recover, 1, 16) - 1));
switch (vdev->via_config->udma_mask) {
case ATA_UDMA2: t = timing->udma ? (0xe0 | (clamp_val(timing->udma, 2, 5) - 2)) : 0x03; break;
case ATA_UDMA4: t = timing->udma ? (0xe8 | (clamp_val(timing->udma, 2, 9) - 2)) : 0x0f; break;
case ATA_UDMA5: t = timing->udma ? (0xe0 | (clamp_val(timing->udma, 2, 9) - 2)) : 0x07; break;
case ATA_UDMA6: t = timing->udma ? (0xe0 | (clamp_val(timing->udma, 2, 9) - 2)) : 0x07; break;
}
if (vdev->via_config->udma_mask) {
u8 udma_etc;
pci_read_config_byte(dev, VIA_UDMA_TIMING + 3 - dn, &udma_etc);
udma_etc &= ~0x20;
if (timing->udma) {
udma_etc &= 0x10;
udma_etc |= t;
}
pci_write_config_byte(dev, VIA_UDMA_TIMING + 3 - dn, udma_etc);
}
}
static void via_set_drive(ide_hwif_t *hwif, ide_drive_t *drive)
{
ide_drive_t *peer = ide_get_pair_dev(drive);
struct pci_dev *dev = to_pci_dev(hwif->dev);
struct ide_host *host = pci_get_drvdata(dev);
struct via82cxxx_dev *vdev = host->host_priv;
struct ide_timing t, p;
unsigned int T, UT;
const u8 speed = drive->dma_mode;
T = 1000000000 / via_clock;
switch (vdev->via_config->udma_mask) {
case ATA_UDMA2: UT = T; break;
case ATA_UDMA4: UT = T/2; break;
case ATA_UDMA5: UT = T/3; break;
case ATA_UDMA6: UT = T/4; break;
default: UT = T;
}
ide_timing_compute(drive, speed, &t, T, UT);
if (peer) {
ide_timing_compute(peer, peer->pio_mode, &p, T, UT);
ide_timing_merge(&p, &t, &t, IDE_TIMING_8BIT);
}
via_set_speed(hwif, drive->dn, &t);
}
static void via_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
via_set_drive(hwif, drive);
}
static struct via_isa_bridge *via_config_find(struct pci_dev **isa)
{
struct via_isa_bridge *via_config;
for (via_config = via_isa_bridges;
via_config->id != PCI_DEVICE_ID_VIA_ANON; via_config++)
if ((*isa = pci_get_device(PCI_VENDOR_ID_VIA +
!!(via_config->flags & VIA_BAD_ID),
via_config->id, NULL))) {
if ((*isa)->revision >= via_config->rev_min &&
(*isa)->revision <= via_config->rev_max)
break;
pci_dev_put(*isa);
}
return via_config;
}
static void via_cable_detect(struct via82cxxx_dev *vdev, u32 u)
{
int i;
switch (vdev->via_config->udma_mask) {
case ATA_UDMA4:
for (i = 24; i >= 0; i -= 8)
if (((u >> (i & 16)) & 8) &&
((u >> i) & 0x20) &&
(((u >> i) & 7) < 2)) {
vdev->via_80w |= (1 << (1 - (i >> 4)));
}
break;
case ATA_UDMA5:
for (i = 24; i >= 0; i -= 8)
if (((u >> i) & 0x10) ||
(((u >> i) & 0x20) &&
(((u >> i) & 7) < 4))) {
vdev->via_80w |= (1 << (1 - (i >> 4)));
}
break;
case ATA_UDMA6:
for (i = 24; i >= 0; i -= 8)
if (((u >> i) & 0x10) ||
(((u >> i) & 0x20) &&
(((u >> i) & 7) < 6))) {
vdev->via_80w |= (1 << (1 - (i >> 4)));
}
break;
}
}
static int init_chipset_via82cxxx(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
struct via82cxxx_dev *vdev = host->host_priv;
struct via_isa_bridge *via_config = vdev->via_config;
u8 t, v;
u32 u;
pci_read_config_dword(dev, VIA_UDMA_TIMING, &u);
via_cable_detect(vdev, u);
if (via_config->udma_mask == ATA_UDMA4) {
pci_write_config_dword(dev, VIA_UDMA_TIMING, u|0x80008);
} else if (via_config->flags & VIA_BAD_CLK66) {
pci_write_config_dword(dev, VIA_UDMA_TIMING, u & ~0x80008);
}
pci_read_config_byte(dev, VIA_IDE_ENABLE, &v);
pci_read_config_byte(dev, VIA_FIFO_CONFIG, &t);
if (via_config->flags & VIA_BAD_PREQ) {
t &= 0x7f;
}
if (via_config->flags & VIA_SET_FIFO) {
t &= (t & 0x9f);
switch (v & 3) {
case 2: t |= 0x00; break;
case 1: t |= 0x60; break;
case 3: t |= 0x20; break;
}
}
pci_write_config_byte(dev, VIA_FIFO_CONFIG, t);
return 0;
}
static int via_cable_override(struct pci_dev *pdev)
{
if (dmi_check_system(cable_dmi_table))
return 1;
if (pdev->subsystem_vendor == 0x161F &&
pdev->subsystem_device == 0x2032)
return 1;
return 0;
}
static u8 via82cxxx_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
struct ide_host *host = pci_get_drvdata(pdev);
struct via82cxxx_dev *vdev = host->host_priv;
if (via_cable_override(pdev))
return ATA_CBL_PATA40_SHORT;
if ((vdev->via_config->flags & VIA_SATA_PATA) && hwif->channel == 0)
return ATA_CBL_SATA;
if ((vdev->via_80w >> hwif->channel) & 1)
return ATA_CBL_PATA80;
else
return ATA_CBL_PATA40;
}
static int __devinit via_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct pci_dev *isa = NULL;
struct via_isa_bridge *via_config;
struct via82cxxx_dev *vdev;
int rc;
u8 idx = id->driver_data;
struct ide_port_info d;
d = via82cxxx_chipset;
via_config = via_config_find(&isa);
printk(KERN_INFO DRV_NAME " %s: VIA %s (rev %02x) IDE %sDMA%s\n",
pci_name(dev), via_config->name, isa->revision,
via_config->udma_mask ? "U" : "MW",
via_dma[via_config->udma_mask ?
(fls(via_config->udma_mask) - 1) : 0]);
pci_dev_put(isa);
via_clock = (ide_pci_clk ? ide_pci_clk : 33) * 1000;
switch (via_clock) {
case 33000: via_clock = 33333; break;
case 37000: via_clock = 37500; break;
case 41000: via_clock = 41666; break;
}
if (via_clock < 20000 || via_clock > 50000) {
printk(KERN_WARNING DRV_NAME ": User given PCI clock speed "
"impossible (%d), using 33 MHz instead.\n", via_clock);
via_clock = 33333;
}
if (idx == 1)
d.enablebits[1].reg = d.enablebits[0].reg = 0;
else
d.host_flags |= IDE_HFLAG_NO_AUTODMA;
if (idx == VIA_IDFLAG_SINGLE)
d.host_flags |= IDE_HFLAG_SINGLE;
if ((via_config->flags & VIA_NO_UNMASK) == 0)
d.host_flags |= IDE_HFLAG_UNMASK_IRQS;
d.udma_mask = via_config->udma_mask;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev) {
printk(KERN_ERR DRV_NAME " %s: out of memory :(\n",
pci_name(dev));
return -ENOMEM;
}
vdev->via_config = via_config;
rc = ide_pci_init_one(dev, &d, vdev);
if (rc)
kfree(vdev);
return rc;
}
static void __devexit via_remove(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
struct via82cxxx_dev *vdev = host->host_priv;
ide_pci_remove(dev);
kfree(vdev);
}
static int __init via_ide_init(void)
{
return ide_pci_register_driver(&via_pci_driver);
}
static void __exit via_ide_exit(void)
{
pci_unregister_driver(&via_pci_driver);
}
