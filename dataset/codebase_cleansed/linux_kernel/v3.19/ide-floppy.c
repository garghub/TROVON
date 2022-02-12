static int ide_floppy_callback(ide_drive_t *drive, int dsc)
{
struct ide_disk_obj *floppy = drive->driver_data;
struct ide_atapi_pc *pc = drive->pc;
struct request *rq = pc->rq;
int uptodate = pc->error ? 0 : 1;
ide_debug_log(IDE_DBG_FUNC, "enter");
if (drive->failed_pc == pc)
drive->failed_pc = NULL;
if (pc->c[0] == GPCMD_READ_10 || pc->c[0] == GPCMD_WRITE_10 ||
rq->cmd_type == REQ_TYPE_BLOCK_PC)
uptodate = 1;
else if (pc->c[0] == GPCMD_REQUEST_SENSE) {
u8 *buf = bio_data(rq->bio);
if (!pc->error) {
floppy->sense_key = buf[2] & 0x0F;
floppy->asc = buf[12];
floppy->ascq = buf[13];
floppy->progress_indication = buf[15] & 0x80 ?
(u16)get_unaligned((u16 *)&buf[16]) : 0x10000;
if (drive->failed_pc)
ide_debug_log(IDE_DBG_PC, "pc = %x",
drive->failed_pc->c[0]);
ide_debug_log(IDE_DBG_SENSE, "sense key = %x, asc = %x,"
"ascq = %x", floppy->sense_key,
floppy->asc, floppy->ascq);
} else
printk(KERN_ERR PFX "Error in REQUEST SENSE itself - "
"Aborting request!\n");
}
if (rq->cmd_type == REQ_TYPE_SPECIAL)
rq->errors = uptodate ? 0 : IDE_DRV_ERROR_GENERAL;
return uptodate;
}
static void ide_floppy_report_error(struct ide_disk_obj *floppy,
struct ide_atapi_pc *pc)
{
if (floppy->sense_key == 0x02 &&
floppy->asc == 0x3a &&
floppy->ascq == 0x00)
return;
printk(KERN_ERR PFX "%s: I/O error, pc = %2x, key = %2x, "
"asc = %2x, ascq = %2x\n",
floppy->drive->name, pc->c[0], floppy->sense_key,
floppy->asc, floppy->ascq);
}
static ide_startstop_t ide_floppy_issue_pc(ide_drive_t *drive,
struct ide_cmd *cmd,
struct ide_atapi_pc *pc)
{
struct ide_disk_obj *floppy = drive->driver_data;
if (drive->failed_pc == NULL &&
pc->c[0] != GPCMD_REQUEST_SENSE)
drive->failed_pc = pc;
drive->pc = pc;
if (pc->retries > IDEFLOPPY_MAX_PC_RETRIES) {
unsigned int done = blk_rq_bytes(drive->hwif->rq);
if (!(pc->flags & PC_FLAG_SUPPRESS_ERROR))
ide_floppy_report_error(floppy, pc);
pc->error = IDE_DRV_ERROR_GENERAL;
drive->failed_pc = NULL;
drive->pc_callback(drive, 0);
ide_complete_rq(drive, -EIO, done);
return ide_stopped;
}
ide_debug_log(IDE_DBG_FUNC, "retry #%d", pc->retries);
pc->retries++;
return ide_issue_pc(drive, cmd);
}
void ide_floppy_create_read_capacity_cmd(struct ide_atapi_pc *pc)
{
ide_init_pc(pc);
pc->c[0] = GPCMD_READ_FORMAT_CAPACITIES;
pc->c[7] = 255;
pc->c[8] = 255;
pc->req_xfer = 255;
}
void ide_floppy_create_mode_sense_cmd(struct ide_atapi_pc *pc, u8 page_code)
{
u16 length = 8;
ide_init_pc(pc);
pc->c[0] = GPCMD_MODE_SENSE_10;
pc->c[1] = 0;
pc->c[2] = page_code;
switch (page_code) {
case IDEFLOPPY_CAPABILITIES_PAGE:
length += 12;
break;
case IDEFLOPPY_FLEXIBLE_DISK_PAGE:
length += 32;
break;
default:
printk(KERN_ERR PFX "unsupported page code in %s\n", __func__);
}
put_unaligned(cpu_to_be16(length), (u16 *) &pc->c[7]);
pc->req_xfer = length;
}
static void idefloppy_create_rw_cmd(ide_drive_t *drive,
struct ide_atapi_pc *pc, struct request *rq,
unsigned long sector)
{
struct ide_disk_obj *floppy = drive->driver_data;
int block = sector / floppy->bs_factor;
int blocks = blk_rq_sectors(rq) / floppy->bs_factor;
int cmd = rq_data_dir(rq);
ide_debug_log(IDE_DBG_FUNC, "block: %d, blocks: %d", block, blocks);
ide_init_pc(pc);
pc->c[0] = cmd == READ ? GPCMD_READ_10 : GPCMD_WRITE_10;
put_unaligned(cpu_to_be16(blocks), (unsigned short *)&pc->c[7]);
put_unaligned(cpu_to_be32(block), (unsigned int *) &pc->c[2]);
memcpy(rq->cmd, pc->c, 12);
pc->rq = rq;
if (rq->cmd_flags & REQ_WRITE)
pc->flags |= PC_FLAG_WRITING;
pc->flags |= PC_FLAG_DMA_OK;
}
static void idefloppy_blockpc_cmd(struct ide_disk_obj *floppy,
struct ide_atapi_pc *pc, struct request *rq)
{
ide_init_pc(pc);
memcpy(pc->c, rq->cmd, sizeof(pc->c));
pc->rq = rq;
if (blk_rq_bytes(rq)) {
pc->flags |= PC_FLAG_DMA_OK;
if (rq_data_dir(rq) == WRITE)
pc->flags |= PC_FLAG_WRITING;
}
}
static ide_startstop_t ide_floppy_do_request(ide_drive_t *drive,
struct request *rq, sector_t block)
{
struct ide_disk_obj *floppy = drive->driver_data;
struct ide_cmd cmd;
struct ide_atapi_pc *pc;
ide_debug_log(IDE_DBG_FUNC, "enter, cmd: 0x%x\n", rq->cmd[0]);
if (drive->debug_mask & IDE_DBG_RQ)
blk_dump_rq_flags(rq, (rq->rq_disk
? rq->rq_disk->disk_name
: "dev?"));
if (rq->errors >= ERROR_MAX) {
if (drive->failed_pc) {
ide_floppy_report_error(floppy, drive->failed_pc);
drive->failed_pc = NULL;
} else
printk(KERN_ERR PFX "%s: I/O error\n", drive->name);
if (rq->cmd_type == REQ_TYPE_SPECIAL) {
rq->errors = 0;
ide_complete_rq(drive, 0, blk_rq_bytes(rq));
return ide_stopped;
} else
goto out_end;
}
switch (rq->cmd_type) {
case REQ_TYPE_FS:
if (((long)blk_rq_pos(rq) % floppy->bs_factor) ||
(blk_rq_sectors(rq) % floppy->bs_factor)) {
printk(KERN_ERR PFX "%s: unsupported r/w rq size\n",
drive->name);
goto out_end;
}
pc = &floppy->queued_pc;
idefloppy_create_rw_cmd(drive, pc, rq, (unsigned long)block);
break;
case REQ_TYPE_SPECIAL:
case REQ_TYPE_SENSE:
pc = (struct ide_atapi_pc *)rq->special;
break;
case REQ_TYPE_BLOCK_PC:
pc = &floppy->queued_pc;
idefloppy_blockpc_cmd(floppy, pc, rq);
break;
default:
BUG();
}
ide_prep_sense(drive, rq);
memset(&cmd, 0, sizeof(cmd));
if (rq_data_dir(rq))
cmd.tf_flags |= IDE_TFLAG_WRITE;
cmd.rq = rq;
if (rq->cmd_type == REQ_TYPE_FS || blk_rq_bytes(rq)) {
ide_init_sg_cmd(&cmd, blk_rq_bytes(rq));
ide_map_sg(drive, &cmd);
}
pc->rq = rq;
return ide_floppy_issue_pc(drive, &cmd, pc);
out_end:
drive->failed_pc = NULL;
if (rq->cmd_type != REQ_TYPE_FS && rq->errors == 0)
rq->errors = -EIO;
ide_complete_rq(drive, -EIO, blk_rq_bytes(rq));
return ide_stopped;
}
static int ide_floppy_get_flexible_disk_page(ide_drive_t *drive,
struct ide_atapi_pc *pc)
{
struct ide_disk_obj *floppy = drive->driver_data;
struct gendisk *disk = floppy->disk;
u8 *page, buf[40];
int capacity, lba_capacity;
u16 transfer_rate, sector_size, cyls, rpm;
u8 heads, sectors;
ide_floppy_create_mode_sense_cmd(pc, IDEFLOPPY_FLEXIBLE_DISK_PAGE);
if (ide_queue_pc_tail(drive, disk, pc, buf, pc->req_xfer)) {
printk(KERN_ERR PFX "Can't get flexible disk page params\n");
return 1;
}
if (buf[3] & 0x80)
drive->dev_flags |= IDE_DFLAG_WP;
else
drive->dev_flags &= ~IDE_DFLAG_WP;
set_disk_ro(disk, !!(drive->dev_flags & IDE_DFLAG_WP));
page = &buf[8];
transfer_rate = be16_to_cpup((__be16 *)&buf[8 + 2]);
sector_size = be16_to_cpup((__be16 *)&buf[8 + 6]);
cyls = be16_to_cpup((__be16 *)&buf[8 + 8]);
rpm = be16_to_cpup((__be16 *)&buf[8 + 28]);
heads = buf[8 + 4];
sectors = buf[8 + 5];
capacity = cyls * heads * sectors * sector_size;
if (memcmp(page, &floppy->flexible_disk_page, 32))
printk(KERN_INFO PFX "%s: %dkB, %d/%d/%d CHS, %d kBps, "
"%d sector size, %d rpm\n",
drive->name, capacity / 1024, cyls, heads,
sectors, transfer_rate / 8, sector_size, rpm);
memcpy(&floppy->flexible_disk_page, page, 32);
drive->bios_cyl = cyls;
drive->bios_head = heads;
drive->bios_sect = sectors;
lba_capacity = floppy->blocks * floppy->block_size;
if (capacity < lba_capacity) {
printk(KERN_NOTICE PFX "%s: The disk reports a capacity of %d "
"bytes, but the drive only handles %d\n",
drive->name, lba_capacity, capacity);
floppy->blocks = floppy->block_size ?
capacity / floppy->block_size : 0;
drive->capacity64 = floppy->blocks * floppy->bs_factor;
}
return 0;
}
static int ide_floppy_get_capacity(ide_drive_t *drive)
{
struct ide_disk_obj *floppy = drive->driver_data;
struct gendisk *disk = floppy->disk;
struct ide_atapi_pc pc;
u8 *cap_desc;
u8 pc_buf[256], header_len, desc_cnt;
int i, rc = 1, blocks, length;
ide_debug_log(IDE_DBG_FUNC, "enter");
drive->bios_cyl = 0;
drive->bios_head = drive->bios_sect = 0;
floppy->blocks = 0;
floppy->bs_factor = 1;
drive->capacity64 = 0;
ide_floppy_create_read_capacity_cmd(&pc);
if (ide_queue_pc_tail(drive, disk, &pc, pc_buf, pc.req_xfer)) {
printk(KERN_ERR PFX "Can't get floppy parameters\n");
return 1;
}
header_len = pc_buf[3];
cap_desc = &pc_buf[4];
desc_cnt = header_len / 8;
for (i = 0; i < desc_cnt; i++) {
unsigned int desc_start = 4 + i*8;
blocks = be32_to_cpup((__be32 *)&pc_buf[desc_start]);
length = be16_to_cpup((__be16 *)&pc_buf[desc_start + 6]);
ide_debug_log(IDE_DBG_PROBE, "Descriptor %d: %dkB, %d blocks, "
"%d sector size",
i, blocks * length / 1024,
blocks, length);
if (i)
continue;
switch (pc_buf[desc_start + 4] & 0x03) {
case CAPACITY_UNFORMATTED:
if (!(drive->atapi_flags & IDE_AFLAG_CLIK_DRIVE))
break;
case CAPACITY_CURRENT:
if (memcmp(cap_desc, &floppy->cap_desc, 8))
printk(KERN_INFO PFX "%s: %dkB, %d blocks, %d "
"sector size\n",
drive->name, blocks * length / 1024,
blocks, length);
memcpy(&floppy->cap_desc, cap_desc, 8);
if (!length || length % 512) {
printk(KERN_NOTICE PFX "%s: %d bytes block size"
" not supported\n", drive->name, length);
} else {
floppy->blocks = blocks;
floppy->block_size = length;
floppy->bs_factor = length / 512;
if (floppy->bs_factor != 1)
printk(KERN_NOTICE PFX "%s: Warning: "
"non 512 bytes block size not "
"fully supported\n",
drive->name);
drive->capacity64 =
floppy->blocks * floppy->bs_factor;
rc = 0;
}
break;
case CAPACITY_NO_CARTRIDGE:
printk(KERN_ERR PFX "%s: No disk in drive\n",
drive->name);
break;
case CAPACITY_INVALID:
printk(KERN_ERR PFX "%s: Invalid capacity for disk "
"in drive\n", drive->name);
break;
}
ide_debug_log(IDE_DBG_PROBE, "Descriptor 0 Code: %d",
pc_buf[desc_start + 4] & 0x03);
}
if (!(drive->atapi_flags & IDE_AFLAG_CLIK_DRIVE))
(void) ide_floppy_get_flexible_disk_page(drive, &pc);
return rc;
}
static void ide_floppy_setup(ide_drive_t *drive)
{
struct ide_disk_obj *floppy = drive->driver_data;
u16 *id = drive->id;
drive->pc_callback = ide_floppy_callback;
if (strstarts((char *)&id[ATA_ID_PROD], "IOMEGA ZIP 100 ATAPI")) {
drive->atapi_flags |= IDE_AFLAG_ZIP_DRIVE;
drive->pc_delay = IDEFLOPPY_PC_DELAY;
blk_queue_max_hw_sectors(drive->queue, 64);
}
if (strstarts((char *)&id[ATA_ID_PROD], "IOMEGA Clik!")) {
blk_queue_max_hw_sectors(drive->queue, 64);
drive->atapi_flags |= IDE_AFLAG_CLIK_DRIVE;
drive->dev_flags &= ~IDE_DFLAG_DOORLOCKING;
}
(void) ide_floppy_get_capacity(drive);
ide_proc_register_driver(drive, floppy->driver);
drive->dev_flags |= IDE_DFLAG_ATTACH;
}
static void ide_floppy_flush(ide_drive_t *drive)
{
}
static int ide_floppy_init_media(ide_drive_t *drive, struct gendisk *disk)
{
int ret = 0;
if (ide_do_test_unit_ready(drive, disk))
ide_do_start_stop(drive, disk, 1);
ret = ide_floppy_get_capacity(drive);
set_capacity(disk, ide_gd_capacity(drive));
return ret;
}
