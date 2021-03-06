ide_startstop_t ide_dma_intr(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_cmd *cmd = &hwif->cmd;
u8 stat = 0, dma_stat = 0;
drive->waiting_for_dma = 0;
dma_stat = hwif->dma_ops->dma_end(drive);
ide_dma_unmap_sg(drive, cmd);
stat = hwif->tp_ops->read_status(hwif);
if (OK_STAT(stat, DRIVE_READY, drive->bad_wstat | ATA_DRQ)) {
if (!dma_stat) {
if ((cmd->tf_flags & IDE_TFLAG_FS) == 0)
ide_finish_cmd(drive, cmd, stat);
else
ide_complete_rq(drive, 0,
blk_rq_sectors(cmd->rq) << 9);
return ide_stopped;
}
printk(KERN_ERR "%s: %s: bad DMA status (0x%02x)\n",
drive->name, __func__, dma_stat);
}
return ide_error(drive, "dma_intr", stat);
}
int ide_dma_good_drive(ide_drive_t *drive)
{
return ide_in_drive_list(drive->id, drive_whitelist);
}
static int ide_dma_map_sg(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
struct scatterlist *sg = hwif->sg_table;
int i;
if (cmd->tf_flags & IDE_TFLAG_WRITE)
cmd->sg_dma_direction = DMA_TO_DEVICE;
else
cmd->sg_dma_direction = DMA_FROM_DEVICE;
i = dma_map_sg(hwif->dev, sg, cmd->sg_nents, cmd->sg_dma_direction);
if (i) {
cmd->orig_sg_nents = cmd->sg_nents;
cmd->sg_nents = i;
}
return i;
}
void ide_dma_unmap_sg(ide_drive_t *drive, struct ide_cmd *cmd)
{
ide_hwif_t *hwif = drive->hwif;
dma_unmap_sg(hwif->dev, hwif->sg_table, cmd->orig_sg_nents,
cmd->sg_dma_direction);
}
void ide_dma_off_quietly(ide_drive_t *drive)
{
drive->dev_flags &= ~IDE_DFLAG_USING_DMA;
ide_toggle_bounce(drive, 0);
drive->hwif->dma_ops->dma_host_set(drive, 0);
}
void ide_dma_off(ide_drive_t *drive)
{
printk(KERN_INFO "%s: DMA disabled\n", drive->name);
ide_dma_off_quietly(drive);
}
void ide_dma_on(ide_drive_t *drive)
{
drive->dev_flags |= IDE_DFLAG_USING_DMA;
ide_toggle_bounce(drive, 1);
drive->hwif->dma_ops->dma_host_set(drive, 1);
}
int __ide_dma_bad_drive(ide_drive_t *drive)
{
u16 *id = drive->id;
int blacklist = ide_in_drive_list(id, drive_blacklist);
if (blacklist) {
printk(KERN_WARNING "%s: Disabling (U)DMA for %s (blacklisted)\n",
drive->name, (char *)&id[ATA_ID_PROD]);
return blacklist;
}
return 0;
}
static unsigned int ide_get_mode_mask(ide_drive_t *drive, u8 base, u8 req_mode)
{
u16 *id = drive->id;
ide_hwif_t *hwif = drive->hwif;
const struct ide_port_ops *port_ops = hwif->port_ops;
unsigned int mask = 0;
switch (base) {
case XFER_UDMA_0:
if ((id[ATA_ID_FIELD_VALID] & 4) == 0)
break;
mask = id[ATA_ID_UDMA_MODES];
if (port_ops && port_ops->udma_filter)
mask &= port_ops->udma_filter(drive);
else
mask &= hwif->ultra_mask;
if (req_mode > XFER_UDMA_2) {
if ((mask & 0x78) && (eighty_ninty_three(drive) == 0))
mask &= 0x07;
}
break;
case XFER_MW_DMA_0:
mask = id[ATA_ID_MWDMA_MODES];
if (ata_id_is_cfa(id) && (id[ATA_ID_CFA_MODES] & 0x38)) {
u8 mode = ((id[ATA_ID_CFA_MODES] & 0x38) >> 3) - 1;
mask |= ((2 << mode) - 1) << 3;
}
if (port_ops && port_ops->mdma_filter)
mask &= port_ops->mdma_filter(drive);
else
mask &= hwif->mwdma_mask;
break;
case XFER_SW_DMA_0:
mask = id[ATA_ID_SWDMA_MODES];
if (!(mask & ATA_SWDMA2) && (id[ATA_ID_OLD_DMA_MODES] >> 8)) {
u8 mode = id[ATA_ID_OLD_DMA_MODES] >> 8;
if (mode <= 2)
mask = (2 << mode) - 1;
}
mask &= hwif->swdma_mask;
break;
default:
BUG();
break;
}
return mask;
}
u8 ide_find_dma_mode(ide_drive_t *drive, u8 req_mode)
{
ide_hwif_t *hwif = drive->hwif;
unsigned int mask;
int x, i;
u8 mode = 0;
if (drive->media != ide_disk) {
if (hwif->host_flags & IDE_HFLAG_NO_ATAPI_DMA)
return 0;
}
for (i = 0; i < ARRAY_SIZE(xfer_mode_bases); i++) {
if (req_mode < xfer_mode_bases[i])
continue;
mask = ide_get_mode_mask(drive, xfer_mode_bases[i], req_mode);
x = fls(mask) - 1;
if (x >= 0) {
mode = xfer_mode_bases[i] + x;
break;
}
}
if (hwif->chipset == ide_acorn && mode == 0) {
if (ide_dma_good_drive(drive) &&
drive->id[ATA_ID_EIDE_DMA_TIME] < 150)
mode = XFER_MW_DMA_1;
}
mode = min(mode, req_mode);
printk(KERN_INFO "%s: %s mode selected\n", drive->name,
mode ? ide_xfer_verbose(mode) : "no DMA");
return mode;
}
static int ide_tune_dma(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 speed;
if (ata_id_has_dma(drive->id) == 0 ||
(drive->dev_flags & IDE_DFLAG_NODMA))
return 0;
if (__ide_dma_bad_drive(drive))
return 0;
if (hwif->host_flags & IDE_HFLAG_TRUST_BIOS_FOR_DMA)
return config_drive_for_dma(drive);
speed = ide_max_dma_mode(drive);
if (!speed)
return 0;
if (ide_set_dma_mode(drive, speed))
return 0;
return 1;
}
static int ide_dma_check(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
if (ide_tune_dma(drive))
return 0;
if (hwif->host_flags & IDE_HFLAG_TRUST_BIOS_FOR_DMA)
return -1;
ide_set_max_pio(drive);
return -1;
}
int ide_set_dma(ide_drive_t *drive)
{
int rc;
ide_dma_off_quietly(drive);
rc = ide_dma_check(drive);
if (rc)
return rc;
ide_dma_on(drive);
return 0;
}
void ide_check_dma_crc(ide_drive_t *drive)
{
u8 mode;
ide_dma_off_quietly(drive);
drive->crc_count = 0;
mode = drive->current_speed;
if (mode > XFER_UDMA_0 && mode <= XFER_UDMA_7)
mode--;
else
mode = XFER_PIO_4;
ide_set_xfer_rate(drive, mode);
if (drive->current_speed >= XFER_SW_DMA_0)
ide_dma_on(drive);
}
void ide_dma_lost_irq(ide_drive_t *drive)
{
printk(KERN_ERR "%s: DMA interrupt recovery\n", drive->name);
}
ide_startstop_t ide_dma_timeout_retry(ide_drive_t *drive, int error)
{
ide_hwif_t *hwif = drive->hwif;
const struct ide_dma_ops *dma_ops = hwif->dma_ops;
struct ide_cmd *cmd = &hwif->cmd;
ide_startstop_t ret = ide_stopped;
if (error < 0) {
printk(KERN_WARNING "%s: DMA timeout error\n", drive->name);
drive->waiting_for_dma = 0;
(void)dma_ops->dma_end(drive);
ide_dma_unmap_sg(drive, cmd);
ret = ide_error(drive, "dma timeout error",
hwif->tp_ops->read_status(hwif));
} else {
printk(KERN_WARNING "%s: DMA timeout retry\n", drive->name);
if (dma_ops->dma_clear)
dma_ops->dma_clear(drive);
printk(KERN_ERR "%s: timeout waiting for DMA\n", drive->name);
if (dma_ops->dma_test_irq(drive) == 0) {
ide_dump_status(drive, "DMA timeout",
hwif->tp_ops->read_status(hwif));
drive->waiting_for_dma = 0;
(void)dma_ops->dma_end(drive);
ide_dma_unmap_sg(drive, cmd);
}
}
drive->dev_flags |= IDE_DFLAG_DMA_PIO_RETRY;
drive->retry_pio++;
ide_dma_off_quietly(drive);
if (hwif->rq)
hwif->rq->errors = 0;
return ret;
}
void ide_release_dma_engine(ide_hwif_t *hwif)
{
if (hwif->dmatable_cpu) {
int prd_size = hwif->prd_max_nents * hwif->prd_ent_size;
dma_free_coherent(hwif->dev, prd_size,
hwif->dmatable_cpu, hwif->dmatable_dma);
hwif->dmatable_cpu = NULL;
}
}
int ide_allocate_dma_engine(ide_hwif_t *hwif)
{
int prd_size;
if (hwif->prd_max_nents == 0)
hwif->prd_max_nents = PRD_ENTRIES;
if (hwif->prd_ent_size == 0)
hwif->prd_ent_size = PRD_BYTES;
prd_size = hwif->prd_max_nents * hwif->prd_ent_size;
hwif->dmatable_cpu = dma_alloc_coherent(hwif->dev, prd_size,
&hwif->dmatable_dma,
GFP_ATOMIC);
if (hwif->dmatable_cpu == NULL) {
printk(KERN_ERR "%s: unable to allocate PRD table\n",
hwif->name);
return -ENOMEM;
}
return 0;
}
int ide_dma_prepare(ide_drive_t *drive, struct ide_cmd *cmd)
{
const struct ide_dma_ops *dma_ops = drive->hwif->dma_ops;
if ((drive->dev_flags & IDE_DFLAG_USING_DMA) == 0 ||
(dma_ops->dma_check && dma_ops->dma_check(drive, cmd)))
goto out;
ide_map_sg(drive, cmd);
if (ide_dma_map_sg(drive, cmd) == 0)
goto out_map;
if (dma_ops->dma_setup(drive, cmd))
goto out_dma_unmap;
drive->waiting_for_dma = 1;
return 0;
out_dma_unmap:
ide_dma_unmap_sg(drive, cmd);
out_map:
ide_map_sg(drive, cmd);
out:
return 1;
}
