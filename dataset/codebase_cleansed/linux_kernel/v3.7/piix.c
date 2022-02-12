static void piix_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
int is_slave = drive->dn & 1;
int master_port = hwif->channel ? 0x42 : 0x40;
int slave_port = 0x44;
unsigned long flags;
u16 master_data;
u8 slave_data;
static DEFINE_SPINLOCK(tune_lock);
int control = 0;
const u8 pio = drive->pio_mode - XFER_PIO_0;
static const u8 timings[][2]= {
{ 0, 0 },
{ 0, 0 },
{ 1, 0 },
{ 2, 1 },
{ 2, 3 }, };
spin_lock_irqsave(&tune_lock, flags);
pci_read_config_word(dev, master_port, &master_data);
if (pio > 1)
control |= 1;
if (drive->media == ide_disk)
control |= 4;
if (ide_pio_need_iordy(drive, pio))
control |= 2;
if (is_slave) {
master_data |= 0x4000;
master_data &= ~0x0070;
if (pio > 1) {
master_data |= control << 4;
}
pci_read_config_byte(dev, slave_port, &slave_data);
slave_data &= hwif->channel ? 0x0f : 0xf0;
slave_data |= ((timings[pio][0] << 2) | timings[pio][1]) <<
(hwif->channel ? 4 : 0);
} else {
master_data &= ~0x3307;
if (pio > 1) {
master_data |= control;
}
master_data |= (timings[pio][0] << 12) | (timings[pio][1] << 8);
}
pci_write_config_word(dev, master_port, master_data);
if (is_slave)
pci_write_config_byte(dev, slave_port, slave_data);
spin_unlock_irqrestore(&tune_lock, flags);
}
static void piix_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 maslave = hwif->channel ? 0x42 : 0x40;
int a_speed = 3 << (drive->dn * 4);
int u_flag = 1 << drive->dn;
int v_flag = 0x01 << drive->dn;
int w_flag = 0x10 << drive->dn;
int u_speed = 0;
int sitre;
u16 reg4042, reg4a;
u8 reg48, reg54, reg55;
const u8 speed = drive->dma_mode;
pci_read_config_word(dev, maslave, &reg4042);
sitre = (reg4042 & 0x4000) ? 1 : 0;
pci_read_config_byte(dev, 0x48, &reg48);
pci_read_config_word(dev, 0x4a, &reg4a);
pci_read_config_byte(dev, 0x54, &reg54);
pci_read_config_byte(dev, 0x55, &reg55);
if (speed >= XFER_UDMA_0) {
u8 udma = speed - XFER_UDMA_0;
u_speed = min_t(u8, 2 - (udma & 1), udma) << (drive->dn * 4);
if (!(reg48 & u_flag))
pci_write_config_byte(dev, 0x48, reg48 | u_flag);
if (speed == XFER_UDMA_5) {
pci_write_config_byte(dev, 0x55, (u8) reg55|w_flag);
} else {
pci_write_config_byte(dev, 0x55, (u8) reg55 & ~w_flag);
}
if ((reg4a & a_speed) != u_speed)
pci_write_config_word(dev, 0x4a, (reg4a & ~a_speed) | u_speed);
if (speed > XFER_UDMA_2) {
if (!(reg54 & v_flag))
pci_write_config_byte(dev, 0x54, reg54 | v_flag);
} else
pci_write_config_byte(dev, 0x54, reg54 & ~v_flag);
} else {
const u8 mwdma_to_pio[] = { 0, 3, 4 };
if (reg48 & u_flag)
pci_write_config_byte(dev, 0x48, reg48 & ~u_flag);
if (reg4a & a_speed)
pci_write_config_word(dev, 0x4a, reg4a & ~a_speed);
if (reg54 & v_flag)
pci_write_config_byte(dev, 0x54, reg54 & ~v_flag);
if (reg55 & w_flag)
pci_write_config_byte(dev, 0x55, (u8) reg55 & ~w_flag);
if (speed >= XFER_MW_DMA_0)
drive->pio_mode =
mwdma_to_pio[speed - XFER_MW_DMA_0] + XFER_PIO_0;
else
drive->pio_mode = XFER_PIO_2;
piix_set_pio_mode(hwif, drive);
}
}
static int init_chipset_ich(struct pci_dev *dev)
{
u32 extra = 0;
pci_read_config_dword(dev, 0x54, &extra);
pci_write_config_dword(dev, 0x54, extra | 0x400);
return 0;
}
static void ich_clear_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 dma_stat;
if (drive->waiting_for_dma || hwif->dma_base == 0)
return;
dma_stat = inb(hwif->dma_base + ATA_DMA_STATUS);
outb(dma_stat, hwif->dma_base + ATA_DMA_STATUS);
}
static u8 piix_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *pdev = to_pci_dev(hwif->dev);
const struct ich_laptop *lap = &ich_laptop[0];
u8 reg54h = 0, mask = hwif->channel ? 0xc0 : 0x30;
while (lap->device) {
if (lap->device == pdev->device &&
lap->subvendor == pdev->subsystem_vendor &&
lap->subdevice == pdev->subsystem_device) {
return ATA_CBL_PATA40_SHORT;
}
lap++;
}
pci_read_config_byte(pdev, 0x54, &reg54h);
return (reg54h & mask) ? ATA_CBL_PATA80 : ATA_CBL_PATA40;
}
static void __devinit init_hwif_piix(ide_hwif_t *hwif)
{
if (!hwif->dma_base)
return;
if (no_piix_dma)
hwif->ultra_mask = hwif->mwdma_mask = hwif->swdma_mask = 0;
}
static int __devinit piix_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &piix_pci_info[id->driver_data], NULL);
}
static void __devinit piix_check_450nx(void)
{
struct pci_dev *pdev = NULL;
u16 cfg;
while((pdev=pci_get_device(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82454NX, pdev))!=NULL)
{
pci_read_config_word(pdev, 0x41, &cfg);
if (pdev->revision == 0x00)
no_piix_dma = 1;
else if (cfg & (1<<14) && pdev->revision < 5)
no_piix_dma = 2;
}
if(no_piix_dma)
printk(KERN_WARNING DRV_NAME ": 450NX errata present, disabling IDE DMA.\n");
if(no_piix_dma == 2)
printk(KERN_WARNING DRV_NAME ": A BIOS update may resolve this.\n");
}
static int __init piix_ide_init(void)
{
piix_check_450nx();
return ide_pci_register_driver(&piix_pci_driver);
}
static void __exit piix_ide_exit(void)
{
pci_unregister_driver(&piix_pci_driver);
}
