const char *ide_xfer_verbose(u8 mode)
{
const char *s;
u8 i = mode & 0xf;
if (mode >= XFER_UDMA_0 && mode <= XFER_UDMA_7)
s = udma_str[i];
else if (mode >= XFER_MW_DMA_0 && mode <= XFER_MW_DMA_4)
s = mwdma_str[i];
else if (mode >= XFER_SW_DMA_0 && mode <= XFER_SW_DMA_2)
s = swdma_str[i];
else if (mode >= XFER_PIO_0 && mode <= XFER_PIO_6)
s = pio_str[i & 0x7];
else if (mode == XFER_PIO_SLOW)
s = "PIO SLOW";
else
s = "XFER ERROR";
return s;
}
static u8 ide_get_best_pio_mode(ide_drive_t *drive, u8 mode_wanted, u8 max_mode)
{
u16 *id = drive->id;
int pio_mode = -1, overridden = 0;
if (mode_wanted != 255)
return min_t(u8, mode_wanted, max_mode);
if ((drive->hwif->host_flags & IDE_HFLAG_PIO_NO_BLACKLIST) == 0)
pio_mode = ide_scan_pio_blacklist((char *)&id[ATA_ID_PROD]);
if (pio_mode != -1) {
printk(KERN_INFO "%s: is on PIO blacklist\n", drive->name);
} else {
pio_mode = id[ATA_ID_OLD_PIO_MODES] >> 8;
if (pio_mode > 2) {
pio_mode = 2;
overridden = 1;
}
if (id[ATA_ID_FIELD_VALID] & 2) {
if (ata_id_is_cfa(id) && (id[ATA_ID_CFA_MODES] & 7))
pio_mode = 4 + min_t(int, 2,
id[ATA_ID_CFA_MODES] & 7);
else if (ata_id_has_iordy(id)) {
if (id[ATA_ID_PIO_MODES] & 7) {
overridden = 0;
if (id[ATA_ID_PIO_MODES] & 4)
pio_mode = 5;
else if (id[ATA_ID_PIO_MODES] & 2)
pio_mode = 4;
else
pio_mode = 3;
}
}
}
if (overridden)
printk(KERN_INFO "%s: tPIO > 2, assuming tPIO = 2\n",
drive->name);
}
if (pio_mode > max_mode)
pio_mode = max_mode;
return pio_mode;
}
int ide_pio_need_iordy(ide_drive_t *drive, const u8 pio)
{
if (pio == 0 && (drive->hwif->port_flags & IDE_PFLAG_PROBING))
return 0;
return ata_id_pio_need_iordy(drive->id, pio);
}
int ide_set_pio_mode(ide_drive_t *drive, const u8 mode)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
if (hwif->host_flags & IDE_HFLAG_NO_SET_MODE)
return 0;
if (port_ops == NULL || port_ops->set_pio_mode == NULL)
return -1;
if (port_ops->set_dma_mode == NULL) {
drive->pio_mode = mode;
port_ops->set_pio_mode(hwif, drive);
return 0;
}
if (hwif->host_flags & IDE_HFLAG_POST_SET_MODE) {
if (ide_config_drive_speed(drive, mode))
return -1;
drive->pio_mode = mode;
port_ops->set_pio_mode(hwif, drive);
return 0;
} else {
drive->pio_mode = mode;
port_ops->set_pio_mode(hwif, drive);
return ide_config_drive_speed(drive, mode);
}
}
int ide_set_dma_mode(ide_drive_t *drive, const u8 mode)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
if (hwif->host_flags & IDE_HFLAG_NO_SET_MODE)
return 0;
if (port_ops == NULL || port_ops->set_dma_mode == NULL)
return -1;
if (hwif->host_flags & IDE_HFLAG_POST_SET_MODE) {
if (ide_config_drive_speed(drive, mode))
return -1;
drive->dma_mode = mode;
port_ops->set_dma_mode(hwif, drive);
return 0;
} else {
drive->dma_mode = mode;
port_ops->set_dma_mode(hwif, drive);
return ide_config_drive_speed(drive, mode);
}
}
void ide_set_pio(ide_drive_t *drive, u8 req_pio)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
u8 host_pio, pio;
if (port_ops == NULL || port_ops->set_pio_mode == NULL ||
(hwif->host_flags & IDE_HFLAG_NO_SET_MODE))
return;
BUG_ON(hwif->pio_mask == 0x00);
host_pio = fls(hwif->pio_mask) - 1;
pio = ide_get_best_pio_mode(drive, req_pio, host_pio);
printk(KERN_DEBUG "%s: host max PIO%d wanted PIO%d%s selected PIO%d\n",
drive->name, host_pio, req_pio,
req_pio == 255 ? "(auto-tune)" : "", pio);
(void)ide_set_pio_mode(drive, XFER_PIO_0 + pio);
}
static u8 ide_rate_filter(ide_drive_t *drive, u8 speed)
{
ide_hwif_t *hwif = drive->hwif;
u8 mode = ide_find_dma_mode(drive, speed);
if (mode == 0) {
if (hwif->pio_mask)
mode = fls(hwif->pio_mask) - 1 + XFER_PIO_0;
else
mode = XFER_PIO_4;
}
return min(speed, mode);
}
int ide_set_xfer_rate(ide_drive_t *drive, u8 rate)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
if (port_ops == NULL || port_ops->set_dma_mode == NULL ||
(hwif->host_flags & IDE_HFLAG_NO_SET_MODE))
return -1;
rate = ide_rate_filter(drive, rate);
BUG_ON(rate < XFER_PIO_0);
if (rate >= XFER_PIO_0 && rate <= XFER_PIO_6)
return ide_set_pio_mode(drive, rate);
return ide_set_dma_mode(drive, rate);
}
