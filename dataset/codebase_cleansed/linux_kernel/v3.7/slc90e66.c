static void slc90e66_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
int is_slave = drive->dn & 1;
int master_port = hwif->channel ? 0x42 : 0x40;
int slave_port = 0x44;
unsigned long flags;
u16 master_data;
u8 slave_data;
int control = 0;
const u8 pio = drive->pio_mode - XFER_PIO_0;
static const u8 timings[][2] = {
{ 0, 0 },
{ 0, 0 },
{ 1, 0 },
{ 2, 1 },
{ 2, 3 }, };
spin_lock_irqsave(&slc90e66_lock, flags);
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
spin_unlock_irqrestore(&slc90e66_lock, flags);
}
static void slc90e66_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 maslave = hwif->channel ? 0x42 : 0x40;
int sitre = 0, a_speed = 7 << (drive->dn * 4);
int u_speed = 0, u_flag = 1 << drive->dn;
u16 reg4042, reg44, reg48, reg4a;
const u8 speed = drive->dma_mode;
pci_read_config_word(dev, maslave, &reg4042);
sitre = (reg4042 & 0x4000) ? 1 : 0;
pci_read_config_word(dev, 0x44, &reg44);
pci_read_config_word(dev, 0x48, &reg48);
pci_read_config_word(dev, 0x4a, &reg4a);
if (speed >= XFER_UDMA_0) {
u_speed = (speed - XFER_UDMA_0) << (drive->dn * 4);
if (!(reg48 & u_flag))
pci_write_config_word(dev, 0x48, reg48|u_flag);
if ((reg4a & a_speed) != u_speed) {
pci_write_config_word(dev, 0x4a, reg4a & ~a_speed);
pci_read_config_word(dev, 0x4a, &reg4a);
pci_write_config_word(dev, 0x4a, reg4a|u_speed);
}
} else {
const u8 mwdma_to_pio[] = { 0, 3, 4 };
if (reg48 & u_flag)
pci_write_config_word(dev, 0x48, reg48 & ~u_flag);
if (reg4a & a_speed)
pci_write_config_word(dev, 0x4a, reg4a & ~a_speed);
if (speed >= XFER_MW_DMA_0)
drive->pio_mode =
mwdma_to_pio[speed - XFER_MW_DMA_0] + XFER_PIO_0;
else
drive->pio_mode = XFER_PIO_2;
slc90e66_set_pio_mode(hwif, drive);
}
}
static u8 slc90e66_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 reg47 = 0, mask = hwif->channel ? 0x01 : 0x02;
pci_read_config_byte(dev, 0x47, &reg47);
return (reg47 & mask) ? ATA_CBL_PATA40 : ATA_CBL_PATA80;
}
static int __devinit slc90e66_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
return ide_pci_init_one(dev, &slc90e66_chipset, NULL);
}
static int __init slc90e66_ide_init(void)
{
return ide_pci_register_driver(&slc90e66_pci_driver);
}
static void __exit slc90e66_ide_exit(void)
{
pci_unregister_driver(&slc90e66_pci_driver);
}
