static struct cdrom_info *ide_cd_get(struct gendisk *disk)
{
struct cdrom_info *cd = NULL;
mutex_lock(&idecd_ref_mutex);
cd = ide_drv_g(disk, cdrom_info);
if (cd) {
if (ide_device_get(cd->drive))
cd = NULL;
else
get_device(&cd->dev);
}
mutex_unlock(&idecd_ref_mutex);
return cd;
}
static void ide_cd_put(struct cdrom_info *cd)
{
ide_drive_t *drive = cd->drive;
mutex_lock(&idecd_ref_mutex);
put_device(&cd->dev);
ide_device_put(drive);
mutex_unlock(&idecd_ref_mutex);
}
static void cdrom_saw_media_change(ide_drive_t *drive)
{
drive->dev_flags |= IDE_DFLAG_MEDIA_CHANGED;
drive->atapi_flags &= ~IDE_AFLAG_TOC_VALID;
}
static int cdrom_log_sense(ide_drive_t *drive, struct request *rq)
{
struct request_sense *sense = &drive->sense_data;
int log = 0;
if (!sense || !rq || (rq->cmd_flags & REQ_QUIET))
return 0;
ide_debug_log(IDE_DBG_SENSE, "sense_key: 0x%x", sense->sense_key);
switch (sense->sense_key) {
case NO_SENSE:
case RECOVERED_ERROR:
break;
case NOT_READY:
if (sense->asc == 0x3a || sense->asc == 0x04)
break;
log = 1;
break;
case ILLEGAL_REQUEST:
if (rq->cmd[0] == GPCMD_START_STOP_UNIT && sense->asc == 0x24)
break;
log = 1;
break;
case UNIT_ATTENTION:
cdrom_saw_media_change(drive);
break;
default:
log = 1;
break;
}
return log;
}
static void cdrom_analyze_sense_data(ide_drive_t *drive,
struct request *failed_command)
{
struct request_sense *sense = &drive->sense_data;
struct cdrom_info *info = drive->driver_data;
unsigned long sector;
unsigned long bio_sectors;
ide_debug_log(IDE_DBG_SENSE, "error_code: 0x%x, sense_key: 0x%x",
sense->error_code, sense->sense_key);
if (failed_command)
ide_debug_log(IDE_DBG_SENSE, "failed cmd: 0x%x",
failed_command->cmd[0]);
if (!cdrom_log_sense(drive, failed_command))
return;
if (failed_command && failed_command->cmd[0] == GPCMD_READ_TOC_PMA_ATIP)
if (sense->sense_key == 0x05 && sense->asc == 0x24)
return;
if (sense->error_code == 0x70) {
switch (sense->sense_key) {
case MEDIUM_ERROR:
case VOLUME_OVERFLOW:
case ILLEGAL_REQUEST:
if (!sense->valid)
break;
if (failed_command == NULL ||
failed_command->cmd_type != REQ_TYPE_FS)
break;
sector = (sense->information[0] << 24) |
(sense->information[1] << 16) |
(sense->information[2] << 8) |
(sense->information[3]);
if (queue_logical_block_size(drive->queue) == 2048)
sector <<= 2;
bio_sectors = max(bio_sectors(failed_command->bio), 4U);
sector &= ~(bio_sectors - 1);
if (sector < get_capacity(info->disk) &&
drive->probed_capacity - sector < 4 * 75)
set_capacity(info->disk, sector);
}
}
ide_cd_log_error(drive->name, failed_command, sense);
}
static void ide_cd_complete_failed_rq(ide_drive_t *drive, struct request *rq)
{
struct request *failed = (struct request *)rq->special;
void *sense = bio_data(rq->bio);
if (failed) {
if (failed->sense) {
memcpy(failed->sense, sense, 18);
failed->sense_len = rq->sense_len;
}
cdrom_analyze_sense_data(drive, failed);
if (ide_end_rq(drive, failed, -EIO, blk_rq_bytes(failed)))
BUG();
} else
cdrom_analyze_sense_data(drive, NULL);
}
static int ide_cd_breathe(ide_drive_t *drive, struct request *rq)
{
struct cdrom_info *info = drive->driver_data;
if (!rq->errors)
info->write_timeout = jiffies + ATAPI_WAIT_WRITE_BUSY;
rq->errors = 1;
if (time_after(jiffies, info->write_timeout))
return 0;
else {
blk_delay_queue(drive->queue, 1);
return 1;
}
}
static int cdrom_decode_status(ide_drive_t *drive, u8 stat)
{
ide_hwif_t *hwif = drive->hwif;
struct request *rq = hwif->rq;
int err, sense_key, do_end_request = 0;
err = ide_read_error(drive);
sense_key = err >> 4;
ide_debug_log(IDE_DBG_RQ, "cmd: 0x%x, rq->cmd_type: 0x%x, err: 0x%x, "
"stat 0x%x",
rq->cmd[0], rq->cmd_type, err, stat);
if (rq->cmd_type == REQ_TYPE_ATA_SENSE) {
rq->cmd_flags |= REQ_FAILED;
return 2;
}
if (rq->cmd_type == REQ_TYPE_BLOCK_PC && !rq->errors)
rq->errors = SAM_STAT_CHECK_CONDITION;
if (blk_noretry_request(rq))
do_end_request = 1;
switch (sense_key) {
case NOT_READY:
if (rq->cmd_type == REQ_TYPE_FS && rq_data_dir(rq) == WRITE) {
if (ide_cd_breathe(drive, rq))
return 1;
} else {
cdrom_saw_media_change(drive);
if (rq->cmd_type == REQ_TYPE_FS &&
!(rq->cmd_flags & REQ_QUIET))
printk(KERN_ERR PFX "%s: tray open\n",
drive->name);
}
do_end_request = 1;
break;
case UNIT_ATTENTION:
cdrom_saw_media_change(drive);
if (rq->cmd_type != REQ_TYPE_FS)
return 0;
if (++rq->errors > ERROR_MAX)
do_end_request = 1;
break;
case ILLEGAL_REQUEST:
if (rq->cmd[0] == GPCMD_START_STOP_UNIT)
break;
case DATA_PROTECT:
if (!(rq->cmd_flags & REQ_QUIET))
ide_dump_status(drive, "command error", stat);
do_end_request = 1;
break;
case MEDIUM_ERROR:
if (!(rq->cmd_flags & REQ_QUIET))
ide_dump_status(drive, "media error "
"(bad sector)", stat);
do_end_request = 1;
break;
case BLANK_CHECK:
if (!(rq->cmd_flags & REQ_QUIET))
ide_dump_status(drive, "media error (blank)",
stat);
do_end_request = 1;
break;
default:
if (rq->cmd_type != REQ_TYPE_FS)
break;
if (err & ~ATA_ABORTED) {
ide_error(drive, "cdrom_decode_status", stat);
return 1;
} else if (++rq->errors > ERROR_MAX)
do_end_request = 1;
}
if (rq->cmd_type != REQ_TYPE_FS) {
rq->cmd_flags |= REQ_FAILED;
do_end_request = 1;
}
if (do_end_request)
goto end_request;
if (stat & ATA_ERR)
return ide_queue_sense_rq(drive, NULL) ? 2 : 1;
return 1;
end_request:
if (stat & ATA_ERR) {
hwif->rq = NULL;
return ide_queue_sense_rq(drive, rq) ? 2 : 1;
} else
return 2;
}
static void ide_cd_request_sense_fixup(ide_drive_t *drive, struct ide_cmd *cmd)
{
struct request *rq = cmd->rq;
ide_debug_log(IDE_DBG_FUNC, "rq->cmd[0]: 0x%x", rq->cmd[0]);
if (rq->cmd[0] == GPCMD_REQUEST_SENSE &&
cmd->nleft > 0 && cmd->nleft <= 5)
cmd->nleft = 0;
}
int ide_cd_queue_pc(ide_drive_t *drive, const unsigned char *cmd,
int write, void *buffer, unsigned *bufflen,
struct request_sense *sense, int timeout,
unsigned int cmd_flags)
{
struct cdrom_info *info = drive->driver_data;
struct request_sense local_sense;
int retries = 10;
unsigned int flags = 0;
if (!sense)
sense = &local_sense;
ide_debug_log(IDE_DBG_PC, "cmd[0]: 0x%x, write: 0x%x, timeout: %d, "
"cmd_flags: 0x%x",
cmd[0], write, timeout, cmd_flags);
do {
struct request *rq;
int error;
rq = blk_get_request(drive->queue, write, __GFP_RECLAIM);
memcpy(rq->cmd, cmd, BLK_MAX_CDB);
rq->cmd_type = REQ_TYPE_ATA_PC;
rq->sense = sense;
rq->cmd_flags |= cmd_flags;
rq->timeout = timeout;
if (buffer) {
error = blk_rq_map_kern(drive->queue, rq, buffer,
*bufflen, GFP_NOIO);
if (error) {
blk_put_request(rq);
return error;
}
}
error = blk_execute_rq(drive->queue, info->disk, rq, 0);
if (buffer)
*bufflen = rq->resid_len;
flags = rq->cmd_flags;
blk_put_request(rq);
if (flags & REQ_FAILED) {
struct request_sense *reqbuf = sense;
if (reqbuf->sense_key == UNIT_ATTENTION)
cdrom_saw_media_change(drive);
else if (reqbuf->sense_key == NOT_READY &&
reqbuf->asc == 4 && reqbuf->ascq != 4) {
ssleep(2);
} else {
retries = 0;
}
--retries;
}
} while ((flags & REQ_FAILED) && retries >= 0);
return (flags & REQ_FAILED) ? -EIO : 0;
}
static bool ide_cd_error_cmd(ide_drive_t *drive, struct ide_cmd *cmd)
{
unsigned int nr_bytes = cmd->nbytes - cmd->nleft;
if (cmd->tf_flags & IDE_TFLAG_WRITE)
nr_bytes -= cmd->last_xfer_len;
if (nr_bytes > 0) {
ide_complete_rq(drive, 0, nr_bytes);
return true;
}
return false;
}
static ide_startstop_t cdrom_newpc_intr(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
struct ide_cmd *cmd = &hwif->cmd;
struct request *rq = hwif->rq;
ide_expiry_t *expiry = NULL;
int dma_error = 0, dma, thislen, uptodate = 0;
int write = (rq_data_dir(rq) == WRITE) ? 1 : 0, rc = 0;
int sense = (rq->cmd_type == REQ_TYPE_ATA_SENSE);
unsigned int timeout;
u16 len;
u8 ireason, stat;
ide_debug_log(IDE_DBG_PC, "cmd: 0x%x, write: 0x%x", rq->cmd[0], write);
dma = drive->dma;
if (dma) {
drive->dma = 0;
drive->waiting_for_dma = 0;
dma_error = hwif->dma_ops->dma_end(drive);
ide_dma_unmap_sg(drive, cmd);
if (dma_error) {
printk(KERN_ERR PFX "%s: DMA %s error\n", drive->name,
write ? "write" : "read");
ide_dma_off(drive);
}
}
stat = hwif->tp_ops->read_status(hwif);
if (!OK_STAT(stat, 0, BAD_R_STAT)) {
rc = cdrom_decode_status(drive, stat);
if (rc) {
if (rc == 2)
goto out_end;
return ide_stopped;
}
}
if (dma) {
if (dma_error)
return ide_error(drive, "dma error", stat);
uptodate = 1;
goto out_end;
}
ide_read_bcount_and_ireason(drive, &len, &ireason);
thislen = (rq->cmd_type == REQ_TYPE_FS) ? len : cmd->nleft;
if (thislen > len)
thislen = len;
ide_debug_log(IDE_DBG_PC, "DRQ: stat: 0x%x, thislen: %d",
stat, thislen);
if ((stat & ATA_DRQ) == 0) {
if (rq->cmd_type == REQ_TYPE_FS) {
uptodate = 1;
if (cmd->nleft > 0) {
printk(KERN_ERR PFX "%s: %s: data underrun "
"(%u bytes)\n", drive->name, __func__,
cmd->nleft);
if (!write)
rq->cmd_flags |= REQ_FAILED;
uptodate = 0;
}
} else if (rq->cmd_type != REQ_TYPE_BLOCK_PC) {
ide_cd_request_sense_fixup(drive, cmd);
uptodate = cmd->nleft ? 0 : 1;
if (!(stat & ATA_ERR) && !uptodate && thislen) {
ide_pio_bytes(drive, cmd, write, thislen);
uptodate = cmd->nleft ? 0 : 1;
}
if (!uptodate)
rq->cmd_flags |= REQ_FAILED;
}
goto out_end;
}
rc = ide_check_ireason(drive, rq, len, ireason, write);
if (rc)
goto out_end;
cmd->last_xfer_len = 0;
ide_debug_log(IDE_DBG_PC, "data transfer, rq->cmd_type: 0x%x, "
"ireason: 0x%x",
rq->cmd_type, ireason);
while (thislen > 0) {
int blen = min_t(int, thislen, cmd->nleft);
if (cmd->nleft == 0)
break;
ide_pio_bytes(drive, cmd, write, blen);
cmd->last_xfer_len += blen;
thislen -= blen;
len -= blen;
if (sense && write == 0)
rq->sense_len += blen;
}
if (len > 0) {
if (rq->cmd_type != REQ_TYPE_FS || write == 0)
ide_pad_transfer(drive, write, len);
else {
printk(KERN_ERR PFX "%s: confused, missing data\n",
drive->name);
blk_dump_rq_flags(rq, "cdrom_newpc_intr");
}
}
if (rq->cmd_type == REQ_TYPE_BLOCK_PC) {
timeout = rq->timeout;
} else {
timeout = ATAPI_WAIT_PC;
if (rq->cmd_type != REQ_TYPE_FS)
expiry = ide_cd_expiry;
}
hwif->expiry = expiry;
ide_set_handler(drive, cdrom_newpc_intr, timeout);
return ide_started;
out_end:
if (rq->cmd_type == REQ_TYPE_BLOCK_PC && rc == 0) {
rq->resid_len = 0;
blk_end_request_all(rq, 0);
hwif->rq = NULL;
} else {
if (sense && uptodate)
ide_cd_complete_failed_rq(drive, rq);
if (rq->cmd_type == REQ_TYPE_FS) {
if (cmd->nleft == 0)
uptodate = 1;
} else {
if (uptodate <= 0 && rq->errors == 0)
rq->errors = -EIO;
}
if (uptodate == 0 && rq->bio)
if (ide_cd_error_cmd(drive, cmd))
return ide_stopped;
if (rq->cmd_type != REQ_TYPE_FS) {
rq->resid_len -= cmd->nbytes - cmd->nleft;
if (uptodate == 0 && (cmd->tf_flags & IDE_TFLAG_WRITE))
rq->resid_len += cmd->last_xfer_len;
}
ide_complete_rq(drive, uptodate ? 0 : -EIO, blk_rq_bytes(rq));
if (sense && rc == 2)
ide_error(drive, "request sense failure", stat);
}
return ide_stopped;
}
static ide_startstop_t cdrom_start_rw(ide_drive_t *drive, struct request *rq)
{
struct cdrom_info *cd = drive->driver_data;
struct request_queue *q = drive->queue;
int write = rq_data_dir(rq) == WRITE;
unsigned short sectors_per_frame =
queue_logical_block_size(q) >> SECTOR_BITS;
ide_debug_log(IDE_DBG_RQ, "rq->cmd[0]: 0x%x, rq->cmd_flags: 0x%x, "
"secs_per_frame: %u",
rq->cmd[0], rq->cmd_flags, sectors_per_frame);
if (write) {
if (get_disk_ro(cd->disk))
return ide_stopped;
} else {
q->prep_rq_fn(q, rq);
}
if ((blk_rq_sectors(rq) & (sectors_per_frame - 1)) ||
(blk_rq_pos(rq) & (sectors_per_frame - 1)))
return ide_stopped;
drive->dma = !!(drive->dev_flags & IDE_DFLAG_USING_DMA);
if (write)
cd->devinfo.media_written = 1;
rq->timeout = ATAPI_WAIT_PC;
return ide_started;
}
static void cdrom_do_block_pc(ide_drive_t *drive, struct request *rq)
{
ide_debug_log(IDE_DBG_PC, "rq->cmd[0]: 0x%x, rq->cmd_type: 0x%x",
rq->cmd[0], rq->cmd_type);
if (rq->cmd_type == REQ_TYPE_BLOCK_PC)
rq->cmd_flags |= REQ_QUIET;
else
rq->cmd_flags &= ~REQ_FAILED;
drive->dma = 0;
if (rq->bio) {
struct request_queue *q = drive->queue;
char *buf = bio_data(rq->bio);
unsigned int alignment;
drive->dma = !!(drive->dev_flags & IDE_DFLAG_USING_DMA);
alignment = queue_dma_alignment(q) | q->dma_pad_mask;
if ((unsigned long)buf & alignment
|| blk_rq_bytes(rq) & q->dma_pad_mask
|| object_is_on_stack(buf))
drive->dma = 0;
}
}
static ide_startstop_t ide_cd_do_request(ide_drive_t *drive, struct request *rq,
sector_t block)
{
struct ide_cmd cmd;
int uptodate = 0;
unsigned int nsectors;
ide_debug_log(IDE_DBG_RQ, "cmd: 0x%x, block: %llu",
rq->cmd[0], (unsigned long long)block);
if (drive->debug_mask & IDE_DBG_RQ)
blk_dump_rq_flags(rq, "ide_cd_do_request");
switch (rq->cmd_type) {
case REQ_TYPE_FS:
if (cdrom_start_rw(drive, rq) == ide_stopped)
goto out_end;
break;
case REQ_TYPE_ATA_SENSE:
case REQ_TYPE_BLOCK_PC:
case REQ_TYPE_ATA_PC:
if (!rq->timeout)
rq->timeout = ATAPI_WAIT_PC;
cdrom_do_block_pc(drive, rq);
break;
case REQ_TYPE_DRV_PRIV:
uptodate = 1;
goto out_end;
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
return ide_issue_pc(drive, &cmd);
out_end:
nsectors = blk_rq_sectors(rq);
if (nsectors == 0)
nsectors = 1;
ide_complete_rq(drive, uptodate ? 0 : -EIO, nsectors << 9);
return ide_stopped;
}
static void msf_from_bcd(struct atapi_msf *msf)
{
msf->minute = bcd2bin(msf->minute);
msf->second = bcd2bin(msf->second);
msf->frame = bcd2bin(msf->frame);
}
int cdrom_check_status(ide_drive_t *drive, struct request_sense *sense)
{
struct cdrom_info *info = drive->driver_data;
struct cdrom_device_info *cdi = &info->devinfo;
unsigned char cmd[BLK_MAX_CDB];
ide_debug_log(IDE_DBG_FUNC, "enter");
memset(cmd, 0, BLK_MAX_CDB);
cmd[0] = GPCMD_TEST_UNIT_READY;
cmd[7] = cdi->sanyo_slot % 3;
return ide_cd_queue_pc(drive, cmd, 0, NULL, NULL, sense, 0, REQ_QUIET);
}
static int cdrom_read_capacity(ide_drive_t *drive, unsigned long *capacity,
unsigned long *sectors_per_frame,
struct request_sense *sense)
{
struct {
__be32 lba;
__be32 blocklen;
} capbuf;
int stat;
unsigned char cmd[BLK_MAX_CDB];
unsigned len = sizeof(capbuf);
u32 blocklen;
ide_debug_log(IDE_DBG_FUNC, "enter");
memset(cmd, 0, BLK_MAX_CDB);
cmd[0] = GPCMD_READ_CDVD_CAPACITY;
stat = ide_cd_queue_pc(drive, cmd, 0, &capbuf, &len, sense, 0,
REQ_QUIET);
if (stat)
return stat;
blocklen = be32_to_cpu(capbuf.blocklen);
blocklen = (blocklen >> SECTOR_BITS) << SECTOR_BITS;
switch (blocklen) {
case 512:
case 1024:
case 2048:
case 4096:
break;
default:
printk_once(KERN_ERR PFX "%s: weird block size %u; "
"setting default block size to 2048\n",
drive->name, blocklen);
blocklen = 2048;
break;
}
*capacity = 1 + be32_to_cpu(capbuf.lba);
*sectors_per_frame = blocklen >> SECTOR_BITS;
ide_debug_log(IDE_DBG_PROBE, "cap: %lu, sectors_per_frame: %lu",
*capacity, *sectors_per_frame);
return 0;
}
static int cdrom_read_tocentry(ide_drive_t *drive, int trackno, int msf_flag,
int format, char *buf, int buflen,
struct request_sense *sense)
{
unsigned char cmd[BLK_MAX_CDB];
ide_debug_log(IDE_DBG_FUNC, "enter");
memset(cmd, 0, BLK_MAX_CDB);
cmd[0] = GPCMD_READ_TOC_PMA_ATIP;
cmd[6] = trackno;
cmd[7] = (buflen >> 8);
cmd[8] = (buflen & 0xff);
cmd[9] = (format << 6);
if (msf_flag)
cmd[1] = 2;
return ide_cd_queue_pc(drive, cmd, 0, buf, &buflen, sense, 0, REQ_QUIET);
}
int ide_cd_read_toc(ide_drive_t *drive, struct request_sense *sense)
{
int stat, ntracks, i;
struct cdrom_info *info = drive->driver_data;
struct cdrom_device_info *cdi = &info->devinfo;
struct atapi_toc *toc = info->toc;
struct {
struct atapi_toc_header hdr;
struct atapi_toc_entry ent;
} ms_tmp;
long last_written;
unsigned long sectors_per_frame = SECTORS_PER_FRAME;
ide_debug_log(IDE_DBG_FUNC, "enter");
if (toc == NULL) {
toc = kmalloc(sizeof(struct atapi_toc), GFP_KERNEL);
if (toc == NULL) {
printk(KERN_ERR PFX "%s: No cdrom TOC buffer!\n",
drive->name);
return -ENOMEM;
}
info->toc = toc;
}
(void) cdrom_check_status(drive, sense);
if (drive->atapi_flags & IDE_AFLAG_TOC_VALID)
return 0;
stat = cdrom_read_capacity(drive, &toc->capacity, &sectors_per_frame,
sense);
if (stat)
toc->capacity = 0x1fffff;
set_capacity(info->disk, toc->capacity * sectors_per_frame);
drive->probed_capacity = toc->capacity * sectors_per_frame;
blk_queue_logical_block_size(drive->queue,
sectors_per_frame << SECTOR_BITS);
stat = cdrom_read_tocentry(drive, 0, 1, 0, (char *) &toc->hdr,
sizeof(struct atapi_toc_header), sense);
if (stat)
return stat;
if (drive->atapi_flags & IDE_AFLAG_TOCTRACKS_AS_BCD) {
toc->hdr.first_track = bcd2bin(toc->hdr.first_track);
toc->hdr.last_track = bcd2bin(toc->hdr.last_track);
}
ntracks = toc->hdr.last_track - toc->hdr.first_track + 1;
if (ntracks <= 0)
return -EIO;
if (ntracks > MAX_TRACKS)
ntracks = MAX_TRACKS;
stat = cdrom_read_tocentry(drive, toc->hdr.first_track, 1, 0,
(char *)&toc->hdr,
sizeof(struct atapi_toc_header) +
(ntracks + 1) *
sizeof(struct atapi_toc_entry), sense);
if (stat && toc->hdr.first_track > 1) {
ntracks = 0;
stat = cdrom_read_tocentry(drive, CDROM_LEADOUT, 1, 0,
(char *)&toc->hdr,
sizeof(struct atapi_toc_header) +
(ntracks + 1) *
sizeof(struct atapi_toc_entry),
sense);
if (stat)
return stat;
if (drive->atapi_flags & IDE_AFLAG_TOCTRACKS_AS_BCD) {
toc->hdr.first_track = (u8)bin2bcd(CDROM_LEADOUT);
toc->hdr.last_track = (u8)bin2bcd(CDROM_LEADOUT);
} else {
toc->hdr.first_track = CDROM_LEADOUT;
toc->hdr.last_track = CDROM_LEADOUT;
}
}
if (stat)
return stat;
toc->hdr.toc_length = be16_to_cpu(toc->hdr.toc_length);
if (drive->atapi_flags & IDE_AFLAG_TOCTRACKS_AS_BCD) {
toc->hdr.first_track = bcd2bin(toc->hdr.first_track);
toc->hdr.last_track = bcd2bin(toc->hdr.last_track);
}
for (i = 0; i <= ntracks; i++) {
if (drive->atapi_flags & IDE_AFLAG_TOCADDR_AS_BCD) {
if (drive->atapi_flags & IDE_AFLAG_TOCTRACKS_AS_BCD)
toc->ent[i].track = bcd2bin(toc->ent[i].track);
msf_from_bcd(&toc->ent[i].addr.msf);
}
toc->ent[i].addr.lba = msf_to_lba(toc->ent[i].addr.msf.minute,
toc->ent[i].addr.msf.second,
toc->ent[i].addr.msf.frame);
}
if (toc->hdr.first_track != CDROM_LEADOUT) {
stat = cdrom_read_tocentry(drive, 0, 0, 1, (char *)&ms_tmp,
sizeof(ms_tmp), sense);
if (stat)
return stat;
toc->last_session_lba = be32_to_cpu(ms_tmp.ent.addr.lba);
} else {
ms_tmp.hdr.last_track = CDROM_LEADOUT;
ms_tmp.hdr.first_track = ms_tmp.hdr.last_track;
toc->last_session_lba = msf_to_lba(0, 2, 0);
}
if (drive->atapi_flags & IDE_AFLAG_TOCADDR_AS_BCD) {
stat = cdrom_read_tocentry(drive, 0, 1, 1, (char *)&ms_tmp,
sizeof(ms_tmp), sense);
if (stat)
return stat;
msf_from_bcd(&ms_tmp.ent.addr.msf);
toc->last_session_lba = msf_to_lba(ms_tmp.ent.addr.msf.minute,
ms_tmp.ent.addr.msf.second,
ms_tmp.ent.addr.msf.frame);
}
toc->xa_flag = (ms_tmp.hdr.first_track != ms_tmp.hdr.last_track);
stat = cdrom_get_last_written(cdi, &last_written);
if (!stat && (last_written > toc->capacity)) {
toc->capacity = last_written;
set_capacity(info->disk, toc->capacity * sectors_per_frame);
drive->probed_capacity = toc->capacity * sectors_per_frame;
}
drive->atapi_flags |= IDE_AFLAG_TOC_VALID;
return 0;
}
int ide_cdrom_get_capabilities(ide_drive_t *drive, u8 *buf)
{
struct cdrom_info *info = drive->driver_data;
struct cdrom_device_info *cdi = &info->devinfo;
struct packet_command cgc;
int stat, attempts = 3, size = ATAPI_CAPABILITIES_PAGE_SIZE;
ide_debug_log(IDE_DBG_FUNC, "enter");
if ((drive->atapi_flags & IDE_AFLAG_FULL_CAPS_PAGE) == 0)
size -= ATAPI_CAPABILITIES_PAGE_PAD_SIZE;
init_cdrom_command(&cgc, buf, size, CGC_DATA_UNKNOWN);
do {
stat = cdrom_mode_sense(cdi, &cgc, GPMODE_CAPABILITIES_PAGE, 0);
if (!stat)
break;
} while (--attempts);
return stat;
}
void ide_cdrom_update_speed(ide_drive_t *drive, u8 *buf)
{
struct cdrom_info *cd = drive->driver_data;
u16 curspeed, maxspeed;
ide_debug_log(IDE_DBG_FUNC, "enter");
if (drive->atapi_flags & IDE_AFLAG_LE_SPEED_FIELDS) {
curspeed = le16_to_cpup((__le16 *)&buf[8 + 14]);
maxspeed = le16_to_cpup((__le16 *)&buf[8 + 8]);
} else {
curspeed = be16_to_cpup((__be16 *)&buf[8 + 14]);
maxspeed = be16_to_cpup((__be16 *)&buf[8 + 8]);
}
ide_debug_log(IDE_DBG_PROBE, "curspeed: %u, maxspeed: %u",
curspeed, maxspeed);
cd->current_speed = DIV_ROUND_CLOSEST(curspeed, 176);
cd->max_speed = DIV_ROUND_CLOSEST(maxspeed, 176);
}
static int ide_cdrom_register(ide_drive_t *drive, int nslots)
{
struct cdrom_info *info = drive->driver_data;
struct cdrom_device_info *devinfo = &info->devinfo;
ide_debug_log(IDE_DBG_PROBE, "nslots: %d", nslots);
devinfo->ops = &ide_cdrom_dops;
devinfo->speed = info->current_speed;
devinfo->capacity = nslots;
devinfo->handle = drive;
strcpy(devinfo->name, drive->name);
if (drive->atapi_flags & IDE_AFLAG_NO_SPEED_SELECT)
devinfo->mask |= CDC_SELECT_SPEED;
devinfo->disk = info->disk;
return register_cdrom(devinfo);
}
static int ide_cdrom_probe_capabilities(ide_drive_t *drive)
{
struct cdrom_info *cd = drive->driver_data;
struct cdrom_device_info *cdi = &cd->devinfo;
u8 buf[ATAPI_CAPABILITIES_PAGE_SIZE];
mechtype_t mechtype;
int nslots = 1;
ide_debug_log(IDE_DBG_PROBE, "media: 0x%x, atapi_flags: 0x%lx",
drive->media, drive->atapi_flags);
cdi->mask = (CDC_CD_R | CDC_CD_RW | CDC_DVD | CDC_DVD_R |
CDC_DVD_RAM | CDC_SELECT_DISC | CDC_PLAY_AUDIO |
CDC_MO_DRIVE | CDC_RAM);
if (drive->media == ide_optical) {
cdi->mask &= ~(CDC_MO_DRIVE | CDC_RAM);
printk(KERN_ERR PFX "%s: ATAPI magneto-optical drive\n",
drive->name);
return nslots;
}
if (drive->atapi_flags & IDE_AFLAG_PRE_ATAPI12) {
drive->atapi_flags &= ~IDE_AFLAG_NO_EJECT;
cdi->mask &= ~CDC_PLAY_AUDIO;
return nslots;
}
cdi->handle = drive;
cdi->ops = &ide_cdrom_dops;
if (ide_cdrom_get_capabilities(drive, buf))
return 0;
if ((buf[8 + 6] & 0x01) == 0)
drive->dev_flags &= ~IDE_DFLAG_DOORLOCKING;
if (buf[8 + 6] & 0x08)
drive->atapi_flags &= ~IDE_AFLAG_NO_EJECT;
if (buf[8 + 3] & 0x01)
cdi->mask &= ~CDC_CD_R;
if (buf[8 + 3] & 0x02)
cdi->mask &= ~(CDC_CD_RW | CDC_RAM);
if (buf[8 + 2] & 0x38)
cdi->mask &= ~CDC_DVD;
if (buf[8 + 3] & 0x20)
cdi->mask &= ~(CDC_DVD_RAM | CDC_RAM);
if (buf[8 + 3] & 0x10)
cdi->mask &= ~CDC_DVD_R;
if ((buf[8 + 4] & 0x01) || (drive->atapi_flags & IDE_AFLAG_PLAY_AUDIO_OK))
cdi->mask &= ~CDC_PLAY_AUDIO;
mechtype = buf[8 + 6] >> 5;
if (mechtype == mechtype_caddy ||
mechtype == mechtype_popup ||
(drive->atapi_flags & IDE_AFLAG_NO_AUTOCLOSE))
cdi->mask |= CDC_CLOSE_TRAY;
if (cdi->sanyo_slot > 0) {
cdi->mask &= ~CDC_SELECT_DISC;
nslots = 3;
} else if (mechtype == mechtype_individual_changer ||
mechtype == mechtype_cartridge_changer) {
nslots = cdrom_number_of_slots(cdi);
if (nslots > 1)
cdi->mask &= ~CDC_SELECT_DISC;
}
ide_cdrom_update_speed(drive, buf);
printk(KERN_INFO PFX "%s: ATAPI", drive->name);
if (cd->max_speed)
printk(KERN_CONT " %dX", cd->max_speed);
printk(KERN_CONT " %s", (cdi->mask & CDC_DVD) ? "CD-ROM" : "DVD-ROM");
if ((cdi->mask & CDC_DVD_R) == 0 || (cdi->mask & CDC_DVD_RAM) == 0)
printk(KERN_CONT " DVD%s%s",
(cdi->mask & CDC_DVD_R) ? "" : "-R",
(cdi->mask & CDC_DVD_RAM) ? "" : "/RAM");
if ((cdi->mask & CDC_CD_R) == 0 || (cdi->mask & CDC_CD_RW) == 0)
printk(KERN_CONT " CD%s%s",
(cdi->mask & CDC_CD_R) ? "" : "-R",
(cdi->mask & CDC_CD_RW) ? "" : "/RW");
if ((cdi->mask & CDC_SELECT_DISC) == 0)
printk(KERN_CONT " changer w/%d slots", nslots);
else
printk(KERN_CONT " drive");
printk(KERN_CONT ", %dkB Cache\n",
be16_to_cpup((__be16 *)&buf[8 + 12]));
return nslots;
}
static int ide_cdrom_prep_fs(struct request_queue *q, struct request *rq)
{
int hard_sect = queue_logical_block_size(q);
long block = (long)blk_rq_pos(rq) / (hard_sect >> 9);
unsigned long blocks = blk_rq_sectors(rq) / (hard_sect >> 9);
memset(rq->cmd, 0, BLK_MAX_CDB);
if (rq_data_dir(rq) == READ)
rq->cmd[0] = GPCMD_READ_10;
else
rq->cmd[0] = GPCMD_WRITE_10;
rq->cmd[2] = (block >> 24) & 0xff;
rq->cmd[3] = (block >> 16) & 0xff;
rq->cmd[4] = (block >> 8) & 0xff;
rq->cmd[5] = block & 0xff;
rq->cmd[7] = (blocks >> 8) & 0xff;
rq->cmd[8] = blocks & 0xff;
rq->cmd_len = 10;
return BLKPREP_OK;
}
static int ide_cdrom_prep_pc(struct request *rq)
{
u8 *c = rq->cmd;
if (c[0] == READ_6 || c[0] == WRITE_6) {
c[8] = c[4];
c[5] = c[3];
c[4] = c[2];
c[3] = c[1] & 0x1f;
c[2] = 0;
c[1] &= 0xe0;
c[0] += (READ_10 - READ_6);
rq->cmd_len = 10;
return BLKPREP_OK;
}
if (c[0] == MODE_SENSE || c[0] == MODE_SELECT) {
rq->errors = ILLEGAL_REQUEST;
return BLKPREP_KILL;
}
return BLKPREP_OK;
}
static int ide_cdrom_prep_fn(struct request_queue *q, struct request *rq)
{
if (rq->cmd_type == REQ_TYPE_FS)
return ide_cdrom_prep_fs(q, rq);
else if (rq->cmd_type == REQ_TYPE_BLOCK_PC)
return ide_cdrom_prep_pc(rq);
return 0;
}
static sector_t ide_cdrom_capacity(ide_drive_t *drive)
{
unsigned long capacity, sectors_per_frame;
if (cdrom_read_capacity(drive, &capacity, &sectors_per_frame, NULL))
return 0;
return capacity * sectors_per_frame;
}
static int idecd_capacity_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = m->private;
seq_printf(m, "%llu\n", (long long)ide_cdrom_capacity(drive));
return 0;
}
static int idecd_capacity_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idecd_capacity_proc_show, PDE_DATA(inode));
}
static ide_proc_entry_t *ide_cd_proc_entries(ide_drive_t *drive)
{
return idecd_proc;
}
static const struct ide_proc_devset *ide_cd_proc_devsets(ide_drive_t *drive)
{
return NULL;
}
static unsigned int ide_cd_flags(u16 *id)
{
const struct cd_list_entry *cle = ide_cd_quirks_list;
while (cle->id_model) {
if (strcmp(cle->id_model, (char *)&id[ATA_ID_PROD]) == 0 &&
(cle->id_firmware == NULL ||
strstr((char *)&id[ATA_ID_FW_REV], cle->id_firmware)))
return cle->cd_flags;
cle++;
}
return 0;
}
static int ide_cdrom_setup(ide_drive_t *drive)
{
struct cdrom_info *cd = drive->driver_data;
struct cdrom_device_info *cdi = &cd->devinfo;
struct request_queue *q = drive->queue;
u16 *id = drive->id;
char *fw_rev = (char *)&id[ATA_ID_FW_REV];
int nslots;
ide_debug_log(IDE_DBG_PROBE, "enter");
blk_queue_prep_rq(q, ide_cdrom_prep_fn);
blk_queue_dma_alignment(q, 31);
blk_queue_update_dma_pad(q, 15);
drive->dev_flags |= IDE_DFLAG_MEDIA_CHANGED;
drive->atapi_flags = IDE_AFLAG_NO_EJECT | ide_cd_flags(id);
if ((drive->atapi_flags & IDE_AFLAG_VERTOS_300_SSD) &&
fw_rev[4] == '1' && fw_rev[6] <= '2')
drive->atapi_flags |= (IDE_AFLAG_TOCTRACKS_AS_BCD |
IDE_AFLAG_TOCADDR_AS_BCD);
else if ((drive->atapi_flags & IDE_AFLAG_VERTOS_600_ESD) &&
fw_rev[4] == '1' && fw_rev[6] <= '2')
drive->atapi_flags |= IDE_AFLAG_TOCTRACKS_AS_BCD;
else if (drive->atapi_flags & IDE_AFLAG_SANYO_3CD)
cdi->sanyo_slot = 3;
nslots = ide_cdrom_probe_capabilities(drive);
blk_queue_logical_block_size(q, CD_FRAMESIZE);
if (ide_cdrom_register(drive, nslots)) {
printk(KERN_ERR PFX "%s: %s failed to register device with the"
" cdrom driver.\n", drive->name, __func__);
cd->devinfo.handle = NULL;
return 1;
}
ide_proc_register_driver(drive, cd->driver);
return 0;
}
static void ide_cd_remove(ide_drive_t *drive)
{
struct cdrom_info *info = drive->driver_data;
ide_debug_log(IDE_DBG_FUNC, "enter");
ide_proc_unregister_driver(drive, info->driver);
device_del(&info->dev);
del_gendisk(info->disk);
mutex_lock(&idecd_ref_mutex);
put_device(&info->dev);
mutex_unlock(&idecd_ref_mutex);
}
static void ide_cd_release(struct device *dev)
{
struct cdrom_info *info = to_ide_drv(dev, cdrom_info);
struct cdrom_device_info *devinfo = &info->devinfo;
ide_drive_t *drive = info->drive;
struct gendisk *g = info->disk;
ide_debug_log(IDE_DBG_FUNC, "enter");
kfree(info->toc);
if (devinfo->handle == drive)
unregister_cdrom(devinfo);
drive->driver_data = NULL;
blk_queue_prep_rq(drive->queue, NULL);
g->private_data = NULL;
put_disk(g);
kfree(info);
}
static int idecd_open(struct block_device *bdev, fmode_t mode)
{
struct cdrom_info *info;
int rc = -ENXIO;
mutex_lock(&ide_cd_mutex);
info = ide_cd_get(bdev->bd_disk);
if (!info)
goto out;
rc = cdrom_open(&info->devinfo, bdev, mode);
if (rc < 0)
ide_cd_put(info);
out:
mutex_unlock(&ide_cd_mutex);
return rc;
}
static void idecd_release(struct gendisk *disk, fmode_t mode)
{
struct cdrom_info *info = ide_drv_g(disk, cdrom_info);
mutex_lock(&ide_cd_mutex);
cdrom_release(&info->devinfo, mode);
ide_cd_put(info);
mutex_unlock(&ide_cd_mutex);
}
static int idecd_set_spindown(struct cdrom_device_info *cdi, unsigned long arg)
{
struct packet_command cgc;
char buffer[16];
int stat;
char spindown;
if (copy_from_user(&spindown, (void __user *)arg, sizeof(char)))
return -EFAULT;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_UNKNOWN);
stat = cdrom_mode_sense(cdi, &cgc, GPMODE_CDROM_PAGE, 0);
if (stat)
return stat;
buffer[11] = (buffer[11] & 0xf0) | (spindown & 0x0f);
return cdrom_mode_select(cdi, &cgc);
}
static int idecd_get_spindown(struct cdrom_device_info *cdi, unsigned long arg)
{
struct packet_command cgc;
char buffer[16];
int stat;
char spindown;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_UNKNOWN);
stat = cdrom_mode_sense(cdi, &cgc, GPMODE_CDROM_PAGE, 0);
if (stat)
return stat;
spindown = buffer[11] & 0x0f;
if (copy_to_user((void __user *)arg, &spindown, sizeof(char)))
return -EFAULT;
return 0;
}
static int idecd_locked_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct cdrom_info *info = ide_drv_g(bdev->bd_disk, cdrom_info);
int err;
switch (cmd) {
case CDROMSETSPINDOWN:
return idecd_set_spindown(&info->devinfo, arg);
case CDROMGETSPINDOWN:
return idecd_get_spindown(&info->devinfo, arg);
default:
break;
}
err = generic_ide_ioctl(info->drive, bdev, cmd, arg);
if (err == -EINVAL)
err = cdrom_ioctl(&info->devinfo, bdev, mode, cmd, arg);
return err;
}
static int idecd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&ide_cd_mutex);
ret = idecd_locked_ioctl(bdev, mode, cmd, arg);
mutex_unlock(&ide_cd_mutex);
return ret;
}
static unsigned int idecd_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct cdrom_info *info = ide_drv_g(disk, cdrom_info);
return cdrom_check_events(&info->devinfo, clearing);
}
static int idecd_revalidate_disk(struct gendisk *disk)
{
struct cdrom_info *info = ide_drv_g(disk, cdrom_info);
struct request_sense sense;
ide_cd_read_toc(info->drive, &sense);
return 0;
}
static int ide_cd_probe(ide_drive_t *drive)
{
struct cdrom_info *info;
struct gendisk *g;
struct request_sense sense;
ide_debug_log(IDE_DBG_PROBE, "driver_req: %s, media: 0x%x",
drive->driver_req, drive->media);
if (!strstr("ide-cdrom", drive->driver_req))
goto failed;
if (drive->media != ide_cdrom && drive->media != ide_optical)
goto failed;
drive->debug_mask = debug_mask;
drive->irq_handler = cdrom_newpc_intr;
info = kzalloc(sizeof(struct cdrom_info), GFP_KERNEL);
if (info == NULL) {
printk(KERN_ERR PFX "%s: Can't allocate a cdrom structure\n",
drive->name);
goto failed;
}
g = alloc_disk(1 << PARTN_BITS);
if (!g)
goto out_free_cd;
ide_init_disk(g, drive);
info->dev.parent = &drive->gendev;
info->dev.release = ide_cd_release;
dev_set_name(&info->dev, "%s", dev_name(&drive->gendev));
if (device_register(&info->dev))
goto out_free_disk;
info->drive = drive;
info->driver = &ide_cdrom_driver;
info->disk = g;
g->private_data = &info->driver;
drive->driver_data = info;
g->minors = 1;
g->driverfs_dev = &drive->gendev;
g->flags = GENHD_FL_CD | GENHD_FL_REMOVABLE;
if (ide_cdrom_setup(drive)) {
put_device(&info->dev);
goto failed;
}
ide_cd_read_toc(drive, &sense);
g->fops = &idecd_ops;
g->flags |= GENHD_FL_REMOVABLE | GENHD_FL_BLOCK_EVENTS_ON_EXCL_WRITE;
add_disk(g);
return 0;
out_free_disk:
put_disk(g);
out_free_cd:
kfree(info);
failed:
return -ENODEV;
}
static void __exit ide_cdrom_exit(void)
{
driver_unregister(&ide_cdrom_driver.gen_driver);
}
static int __init ide_cdrom_init(void)
{
printk(KERN_INFO DRV_NAME " driver " IDECD_VERSION "\n");
return driver_register(&ide_cdrom_driver.gen_driver);
}
