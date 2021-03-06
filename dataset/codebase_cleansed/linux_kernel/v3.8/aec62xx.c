static u8 pci_bus_clock_list (u8 speed, struct chipset_bus_clock_list_entry * chipset_table)
{
for ( ; chipset_table->xfer_speed ; chipset_table++)
if (chipset_table->xfer_speed == speed) {
return chipset_table->chipset_settings;
}
return chipset_table->chipset_settings;
}
static u8 pci_bus_clock_list_ultra (u8 speed, struct chipset_bus_clock_list_entry * chipset_table)
{
for ( ; chipset_table->xfer_speed ; chipset_table++)
if (chipset_table->xfer_speed == speed) {
return chipset_table->ultra_settings;
}
return chipset_table->ultra_settings;
}
static void aec6210_set_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
struct ide_host *host = pci_get_drvdata(dev);
struct chipset_bus_clock_list_entry *bus_clock = host->host_priv;
u16 d_conf = 0;
u8 ultra = 0, ultra_conf = 0;
u8 tmp0 = 0, tmp1 = 0, tmp2 = 0;
const u8 speed = drive->dma_mode;
unsigned long flags;
local_irq_save(flags);
pci_read_config_word(dev, 0x40|(2*drive->dn), &d_conf);
tmp0 = pci_bus_clock_list(speed, bus_clock);
d_conf = ((tmp0 & 0xf0) << 4) | (tmp0 & 0xf);
pci_write_config_word(dev, 0x40|(2*drive->dn), d_conf);
tmp1 = 0x00;
tmp2 = 0x00;
pci_read_config_byte(dev, 0x54, &ultra);
tmp1 = ((0x00 << (2*drive->dn)) | (ultra & ~(3 << (2*drive->dn))));
ultra_conf = pci_bus_clock_list_ultra(speed, bus_clock);
tmp2 = ((ultra_conf << (2*drive->dn)) | (tmp1 & ~(3 << (2*drive->dn))));
pci_write_config_byte(dev, 0x54, tmp2);
local_irq_restore(flags);
}
static void aec6260_set_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
struct ide_host *host = pci_get_drvdata(dev);
struct chipset_bus_clock_list_entry *bus_clock = host->host_priv;
u8 unit = drive->dn & 1;
u8 tmp1 = 0, tmp2 = 0;
u8 ultra = 0, drive_conf = 0, ultra_conf = 0;
const u8 speed = drive->dma_mode;
unsigned long flags;
local_irq_save(flags);
pci_read_config_byte(dev, 0x40|drive->dn, &drive_conf);
drive_conf = pci_bus_clock_list(speed, bus_clock);
pci_write_config_byte(dev, 0x40|drive->dn, drive_conf);
pci_read_config_byte(dev, (0x44|hwif->channel), &ultra);
tmp1 = ((0x00 << (4*unit)) | (ultra & ~(7 << (4*unit))));
ultra_conf = pci_bus_clock_list_ultra(speed, bus_clock);
tmp2 = ((ultra_conf << (4*unit)) | (tmp1 & ~(7 << (4*unit))));
pci_write_config_byte(dev, (0x44|hwif->channel), tmp2);
local_irq_restore(flags);
}
static void aec_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
drive->dma_mode = drive->pio_mode;
hwif->port_ops->set_dma_mode(hwif, drive);
}
static int init_chipset_aec62xx(struct pci_dev *dev)
{
if ((dev->device == PCI_DEVICE_ID_ARTOP_ATP865) ||
(dev->device == PCI_DEVICE_ID_ARTOP_ATP865R)) {
u8 reg49h = 0, reg4ah = 0;
pci_read_config_byte(dev, 0x49, &reg49h);
pci_write_config_byte(dev, 0x49, reg49h & ~0x30);
pci_read_config_byte(dev, 0x4a, &reg4ah);
pci_write_config_byte(dev, 0x4a, reg4ah & ~0x01);
pci_read_config_byte(dev, 0x4a, &reg4ah);
pci_write_config_byte(dev, 0x4a, reg4ah | 0x80);
}
return 0;
}
static u8 atp86x_cable_detect(ide_hwif_t *hwif)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 ata66 = 0, mask = hwif->channel ? 0x02 : 0x01;
pci_read_config_byte(dev, 0x49, &ata66);
return (ata66 & mask) ? ATA_CBL_PATA40 : ATA_CBL_PATA80;
}
static int aec62xx_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
const struct chipset_bus_clock_list_entry *bus_clock;
struct ide_port_info d;
u8 idx = id->driver_data;
int bus_speed = ide_pci_clk ? ide_pci_clk : 33;
int err;
if (bus_speed <= 33)
bus_clock = aec6xxx_33_base;
else
bus_clock = aec6xxx_34_base;
err = pci_enable_device(dev);
if (err)
return err;
d = aec62xx_chipsets[idx];
if (idx == 3 || idx == 4) {
unsigned long dma_base = pci_resource_start(dev, 4);
if (inb(dma_base + 2) & 0x10) {
printk(KERN_INFO DRV_NAME " %s: AEC6880%s card detected"
"\n", pci_name(dev), (idx == 4) ? "R" : "");
d.udma_mask = ATA_UDMA6;
}
}
err = ide_pci_init_one(dev, &d, (void *)bus_clock);
if (err)
pci_disable_device(dev);
return err;
}
static void aec62xx_remove(struct pci_dev *dev)
{
ide_pci_remove(dev);
pci_disable_device(dev);
}
static int __init aec62xx_ide_init(void)
{
return ide_pci_register_driver(&aec62xx_pci_driver);
}
static void __exit aec62xx_ide_exit(void)
{
pci_unregister_driver(&aec62xx_pci_driver);
}
