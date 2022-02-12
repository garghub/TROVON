static u8 sis_ata133_get_base(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u32 reg54 = 0;
pci_read_config_dword(dev, 0x54, &reg54);
return ((reg54 & 0x40000000) ? 0x70 : 0x40) + drive->dn * 4;
}
static void sis_ata16_program_timings(ide_drive_t *drive, const u8 mode)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u16 t1 = 0;
u8 drive_pci = 0x40 + drive->dn * 2;
const u16 pio_timings[] = { 0x000, 0x607, 0x404, 0x303, 0x301 };
const u16 mwdma_timings[] = { 0x008, 0x302, 0x301 };
pci_read_config_word(dev, drive_pci, &t1);
t1 &= ~0x070f;
if (mode >= XFER_MW_DMA_0) {
if (chipset_family > ATA_16)
t1 &= ~0x8000;
t1 |= mwdma_timings[mode - XFER_MW_DMA_0];
} else
t1 |= pio_timings[mode - XFER_PIO_0];
pci_write_config_word(dev, drive_pci, t1);
}
static void sis_ata100_program_timings(ide_drive_t *drive, const u8 mode)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u8 t1, drive_pci = 0x40 + drive->dn * 2;
const u8 pio_timings[] = { 0x00, 0x67, 0x44, 0x33, 0x31 };
const u8 mwdma_timings[] = { 0x08, 0x32, 0x31 };
if (mode >= XFER_MW_DMA_0) {
u8 t2 = 0;
pci_read_config_byte(dev, drive_pci, &t2);
t2 &= ~0x80;
pci_write_config_byte(dev, drive_pci, t2);
t1 = mwdma_timings[mode - XFER_MW_DMA_0];
} else
t1 = pio_timings[mode - XFER_PIO_0];
pci_write_config_byte(dev, drive_pci + 1, t1);
}
static void sis_ata133_program_timings(ide_drive_t *drive, const u8 mode)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u32 t1 = 0;
u8 drive_pci = sis_ata133_get_base(drive), clk, idx;
pci_read_config_dword(dev, drive_pci, &t1);
t1 &= 0xc0c00fff;
clk = (t1 & 0x08) ? ATA_133 : ATA_100;
if (mode >= XFER_MW_DMA_0) {
t1 &= ~0x04;
idx = mode - XFER_MW_DMA_0 + 5;
} else
idx = mode - XFER_PIO_0;
t1 |= ini_time_value[clk][idx] << 12;
t1 |= act_time_value[clk][idx] << 16;
t1 |= rco_time_value[clk][idx] << 24;
pci_write_config_dword(dev, drive_pci, t1);
}
static void sis_program_timings(ide_drive_t *drive, const u8 mode)
{
if (chipset_family < ATA_100)
sis_ata16_program_timings(drive, mode);
else if (chipset_family < ATA_133)
sis_ata100_program_timings(drive, mode);
else
sis_ata133_program_timings(drive, mode);
}
static void config_drive_art_rwp(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 reg4bh = 0;
u8 rw_prefetch = 0;
pci_read_config_byte(dev, 0x4b, &reg4bh);
rw_prefetch = reg4bh & ~(0x11 << drive->dn);
if (drive->media == ide_disk)
rw_prefetch |= 0x11 << drive->dn;
if (reg4bh != rw_prefetch)
pci_write_config_byte(dev, 0x4b, rw_prefetch);
}
static void sis_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
config_drive_art_rwp(drive);
sis_program_timings(drive, drive->pio_mode);
}
static void sis_ata133_program_udma_timings(ide_drive_t *drive, const u8 mode)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u32 regdw = 0;
u8 drive_pci = sis_ata133_get_base(drive), clk, idx;
pci_read_config_dword(dev, drive_pci, &regdw);
regdw |= 0x04;
regdw &= 0xfffff00f;
clk = (regdw & 0x08) ? ATA_133 : ATA_100;
idx = mode - XFER_UDMA_0;
regdw |= cycle_time_value[clk][idx] << 4;
regdw |= cvs_time_value[clk][idx] << 8;
pci_write_config_dword(dev, drive_pci, regdw);
}
static void sis_ata33_program_udma_timings(ide_drive_t *drive, const u8 mode)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u8 drive_pci = 0x40 + drive->dn * 2, reg = 0, i = chipset_family;
pci_read_config_byte(dev, drive_pci + 1, &reg);
reg |= 0x80;
reg &= ~((0xff >> (8 - cycle_time_range[i])) << cycle_time_offset[i]);
reg |= cycle_time_value[i][mode - XFER_UDMA_0] << cycle_time_offset[i];
pci_write_config_byte(dev, drive_pci + 1, reg);
}
static void sis_program_udma_timings(ide_drive_t *drive, const u8 mode)
{
if (chipset_family >= ATA_133)
sis_ata133_program_udma_timings(drive, mode);
else
sis_ata33_program_udma_timings(drive, mode);
}
static void sis_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
const u8 speed = drive->dma_mode;
if (speed >= XFER_UDMA_0)
sis_program_udma_timings(drive, speed);
else
sis_program_timings(drive, speed);
}
static u8 sis_ata133_udma_filter(ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(drive->hwif->dev);
u32 regdw = 0;
u8 drive_pci = sis_ata133_get_base(drive);
pci_read_config_dword(dev, drive_pci, &regdw);
return (regdw & 0x08) ? ATA_UDMA6 : ATA_UDMA5;
}
static int __devinit sis_find_family(struct pci_dev *dev)
{
struct pci_dev *host;
int i = 0;
chipset_family = 0;
for (i = 0; i < ARRAY_SIZE(SiSHostChipInfo) && !chipset_family; i++) {
host = pci_get_device(PCI_VENDOR_ID_SI, SiSHostChipInfo[i].host_id, NULL);
if (!host)
continue;
chipset_family = SiSHostChipInfo[i].chipset_family;
if (SiSHostChipInfo[i].host_id == PCI_DEVICE_ID_SI_630) {
if (host->revision >= 0x30)
chipset_family = ATA_100a;
}
pci_dev_put(host);
printk(KERN_INFO DRV_NAME " %s: %s %s controller\n",
pci_name(dev), SiSHostChipInfo[i].name,
chipset_capability[chipset_family]);
}
if (!chipset_family) {
u32 idemisc;
u16 trueid;
pci_read_config_dword(dev, 0x54, &idemisc);
pci_write_config_dword(dev, 0x54, (idemisc & 0x7fffffff));
pci_read_config_word(dev, PCI_DEVICE_ID, &trueid);
pci_write_config_dword(dev, 0x54, idemisc);
if (trueid == 0x5518) {
printk(KERN_INFO DRV_NAME " %s: SiS 962/963 MuTIOL IDE UDMA133 controller\n",
pci_name(dev));
chipset_family = ATA_133;
if ((idemisc & 0x40000000) == 0) {
pci_write_config_dword(dev, 0x54, idemisc | 0x40000000);
printk(KERN_INFO DRV_NAME " %s: Switching to 5513 register mapping\n",
pci_name(dev));
}
}
}
if (!chipset_family) {
struct pci_dev *lpc_bridge;
u16 trueid;
u8 prefctl;
u8 idecfg;
pci_read_config_byte(dev, 0x4a, &idecfg);
pci_write_config_byte(dev, 0x4a, idecfg | 0x10);
pci_read_config_word(dev, PCI_DEVICE_ID, &trueid);
pci_write_config_byte(dev, 0x4a, idecfg);
if (trueid == 0x5517) {
lpc_bridge = pci_get_slot(dev->bus, 0x10);
pci_read_config_byte(dev, 0x49, &prefctl);
pci_dev_put(lpc_bridge);
if (lpc_bridge->revision == 0x10 && (prefctl & 0x80)) {
printk(KERN_INFO DRV_NAME " %s: SiS 961B MuTIOL IDE UDMA133 controller\n",
pci_name(dev));
chipset_family = ATA_133a;
} else {
printk(KERN_INFO DRV_NAME " %s: SiS 961 MuTIOL IDE UDMA100 controller\n",
pci_name(dev));
chipset_family = ATA_100;
}
}
}
return chipset_family;
}
static int init_chipset_sis5513(struct pci_dev *dev)
{
u8 reg;
u16 regw;
switch (chipset_family) {
case ATA_133:
pci_read_config_word(dev, 0x50, &regw);
if (regw & 0x08)
pci_write_config_word(dev, 0x50, regw&0xfff7);
pci_read_config_word(dev, 0x52, &regw);
if (regw & 0x08)
pci_write_config_word(dev, 0x52, regw&0xfff7);
break;
case ATA_133a:
case ATA_100:
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x80);
pci_read_config_byte(dev, 0x49, &reg);
if (!(reg & 0x01))
pci_write_config_byte(dev, 0x49, reg|0x01);
break;
case ATA_100a:
case ATA_66:
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x10);
pci_read_config_byte(dev, 0x52, &reg);
if (!(reg & 0x04))
pci_write_config_byte(dev, 0x52, reg|0x04);
break;
case ATA_33:
pci_read_config_byte(dev, 0x09, &reg);
if ((reg & 0x0f) != 0x00)
pci_write_config_byte(dev, 0x09, reg&0xf0);
case ATA_16:
pci_read_config_byte(dev, 0x52, &reg);
if (!(reg & 0x08))
pci_write_config_byte(dev, 0x52, reg|0x08);
break;
}
return 0;
}
static u8 sis_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
const struct sis_laptop *lap = &sis_laptop[0];
u8 ata66 = 0;
while (lap->device) {
if (lap->device == pdev->device &&
lap->subvendor == pdev->subsystem_vendor &&
lap->subdevice == pdev->subsystem_device)
return ATA_CBL_PATA40_SHORT;
lap++;
}
if (chipset_family >= ATA_133) {
u16 regw = 0;
u16 reg_addr = hwif->channel ? 0x52: 0x50;
pci_read_config_word(pdev, reg_addr, &regw);
ata66 = (regw & 0x8000) ? 0 : 1;
} else if (chipset_family >= ATA_66) {
u8 reg48h = 0;
u8 mask = hwif->channel ? 0x20 : 0x10;
pci_read_config_byte(pdev, 0x48, &reg48h);
ata66 = (reg48h & mask) ? 0 : 1;
}
return ata66 ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
}
static int __devinit sis5513_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_port_info d = sis5513_chipset;
u8 udma_rates[] = { 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f };
int rc;
rc = pci_enable_device(dev);
if (rc)
return rc;
if (sis_find_family(dev) == 0)
return -ENOTSUPP;
if (chipset_family >= ATA_133)
d.port_ops = &sis_ata133_port_ops;
else
d.port_ops = &sis_port_ops;
d.udma_mask = udma_rates[chipset_family];
return ide_pci_init_one(dev, &d, NULL);
}
static void __devexit sis5513_remove(struct pci_dev *dev)
{
ide_pci_remove(dev);
pci_disable_device(dev);
}
static int __init sis5513_ide_init(void)
{
return ide_pci_register_driver(&sis5513_pci_driver);
}
static void __exit sis5513_ide_exit(void)
{
pci_unregister_driver(&sis5513_pci_driver);
}
