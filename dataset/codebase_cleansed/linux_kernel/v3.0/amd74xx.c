static inline u8 amd_offset(struct pci_dev *dev)
{
return (dev->vendor == PCI_VENDOR_ID_NVIDIA) ? 0x10 : 0;
}
static void amd_set_speed(struct pci_dev *dev, u8 dn, u8 udma_mask,
struct ide_timing *timing)
{
u8 t = 0, offset = amd_offset(dev);
pci_read_config_byte(dev, AMD_ADDRESS_SETUP + offset, &t);
t = (t & ~(3 << ((3 - dn) << 1))) | ((clamp_val(timing->setup, 1, 4) - 1) << ((3 - dn) << 1));
pci_write_config_byte(dev, AMD_ADDRESS_SETUP + offset, t);
pci_write_config_byte(dev, AMD_8BIT_TIMING + offset + (1 - (dn >> 1)),
((clamp_val(timing->act8b, 1, 16) - 1) << 4) | (clamp_val(timing->rec8b, 1, 16) - 1));
pci_write_config_byte(dev, AMD_DRIVE_TIMING + offset + (3 - dn),
((clamp_val(timing->active, 1, 16) - 1) << 4) | (clamp_val(timing->recover, 1, 16) - 1));
switch (udma_mask) {
case ATA_UDMA2: t = timing->udma ? (0xc0 | (clamp_val(timing->udma, 2, 5) - 2)) : 0x03; break;
case ATA_UDMA4: t = timing->udma ? (0xc0 | amd_cyc2udma[clamp_val(timing->udma, 2, 10)]) : 0x03; break;
case ATA_UDMA5: t = timing->udma ? (0xc0 | amd_cyc2udma[clamp_val(timing->udma, 1, 10)]) : 0x03; break;
case ATA_UDMA6: t = timing->udma ? (0xc0 | amd_cyc2udma[clamp_val(timing->udma, 1, 15)]) : 0x03; break;
default: return;
}
if (timing->udma)
pci_write_config_byte(dev, AMD_UDMA_TIMING + offset + 3 - dn, t);
}
static void amd_set_drive(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
ide_drive_t *peer = ide_get_pair_dev(drive);
struct ide_timing t, p;
int T, UT;
u8 udma_mask = hwif->ultra_mask;
const u8 speed = drive->dma_mode;
T = 1000000000 / amd_clock;
UT = (udma_mask == ATA_UDMA2) ? T : (T / 2);
ide_timing_compute(drive, speed, &t, T, UT);
if (peer) {
ide_timing_compute(peer, peer->pio_mode, &p, T, UT);
ide_timing_merge(&p, &t, &t, IDE_TIMING_8BIT);
}
if (speed == XFER_UDMA_5 && amd_clock <= 33333) t.udma = 1;
if (speed == XFER_UDMA_6 && amd_clock <= 33333) t.udma = 15;
amd_set_speed(dev, drive->dn, udma_mask, &t);
}
static void amd_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
amd_set_drive(hwif, drive);
}
static void amd7409_cable_detect(struct pci_dev *dev)
{
amd_80w = 0x03;
}
static void amd7411_cable_detect(struct pci_dev *dev)
{
int i;
u32 u = 0;
u8 t = 0, offset = amd_offset(dev);
pci_read_config_byte(dev, AMD_CABLE_DETECT + offset, &t);
pci_read_config_dword(dev, AMD_UDMA_TIMING + offset, &u);
amd_80w = ((t & 0x3) ? 1 : 0) | ((t & 0xc) ? 2 : 0);
for (i = 24; i >= 0; i -= 8)
if (((u >> i) & 4) && !(amd_80w & (1 << (1 - (i >> 4))))) {
printk(KERN_WARNING DRV_NAME " %s: BIOS didn't set "
"cable bits correctly. Enabling workaround.\n",
pci_name(dev));
amd_80w |= (1 << (1 - (i >> 4)));
}
}
static int init_chipset_amd74xx(struct pci_dev *dev)
{
u8 t = 0, offset = amd_offset(dev);
if (dev->vendor == PCI_VENDOR_ID_AMD &&
dev->device == PCI_DEVICE_ID_AMD_COBRA_7401)
;
else if (dev->vendor == PCI_VENDOR_ID_AMD &&
dev->device == PCI_DEVICE_ID_AMD_VIPER_7409)
amd7409_cable_detect(dev);
else
amd7411_cable_detect(dev);
pci_read_config_byte(dev, AMD_IDE_CONFIG + offset, &t);
if (dev->vendor == PCI_VENDOR_ID_AMD &&
dev->device == PCI_DEVICE_ID_AMD_VIPER_7411)
t &= 0x0f;
else
t |= 0xf0;
pci_write_config_byte(dev, AMD_IDE_CONFIG + offset, t);
return 0;
}
static u8 amd_cable_detect(ide_hwif_t *hwif)
{
if ((amd_80w >> hwif->channel) & 1)
return ATA_CBL_PATA80;
else
return ATA_CBL_PATA40;
}
static int __devinit amd74xx_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d;
u8 idx = id->driver_data;
d = amd74xx_chipsets[idx];
if (idx == 1) {
if (dev->revision <= 7)
d.swdma_mask = 0;
d.host_flags |= IDE_HFLAG_CLEAR_SIMPLEX;
} else if (idx == 3) {
if (dev->subsystem_vendor == PCI_VENDOR_ID_AMD &&
dev->subsystem_device == PCI_DEVICE_ID_AMD_SERENADE)
d.udma_mask = ATA_UDMA5;
}
if (dev->vendor == PCI_VENDOR_ID_NVIDIA &&
ide_pci_is_in_compatibility_mode(dev))
d.host_flags |= IDE_HFLAG_BROKEN_ALTSTATUS;
printk(KERN_INFO "%s %s: UDMA%s controller\n",
d.name, pci_name(dev), amd_dma[fls(d.udma_mask) - 1]);
amd_clock = (ide_pci_clk ? ide_pci_clk : 33) * 1000;
switch (amd_clock) {
case 33000: amd_clock = 33333; break;
case 37000: amd_clock = 37500; break;
case 41000: amd_clock = 41666; break;
}
if (amd_clock < 20000 || amd_clock > 50000) {
printk(KERN_WARNING "%s: User given PCI clock speed impossible"
" (%d), using 33 MHz instead.\n",
d.name, amd_clock);
amd_clock = 33333;
}
return ide_pci_init_one(dev, &d, NULL);
}
static int __init amd74xx_ide_init(void)
{
return ide_pci_register_driver(&amd74xx_pci_driver);
}
static void __exit amd74xx_ide_exit(void)
{
pci_unregister_driver(&amd74xx_pci_driver);
}
