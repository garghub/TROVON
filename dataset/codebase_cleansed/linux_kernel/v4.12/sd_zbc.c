static void sd_zbc_parse_report(struct scsi_disk *sdkp,
u8 *buf,
struct blk_zone *zone)
{
struct scsi_device *sdp = sdkp->device;
memset(zone, 0, sizeof(struct blk_zone));
zone->type = buf[0] & 0x0f;
zone->cond = (buf[1] >> 4) & 0xf;
if (buf[1] & 0x01)
zone->reset = 1;
if (buf[1] & 0x02)
zone->non_seq = 1;
zone->len = logical_to_sectors(sdp, get_unaligned_be64(&buf[8]));
zone->start = logical_to_sectors(sdp, get_unaligned_be64(&buf[16]));
zone->wp = logical_to_sectors(sdp, get_unaligned_be64(&buf[24]));
if (zone->type != ZBC_ZONE_TYPE_CONV &&
zone->cond == ZBC_ZONE_COND_FULL)
zone->wp = zone->start + zone->len;
}
static int sd_zbc_report_zones(struct scsi_disk *sdkp, unsigned char *buf,
unsigned int buflen, sector_t lba)
{
struct scsi_device *sdp = sdkp->device;
const int timeout = sdp->request_queue->rq_timeout;
struct scsi_sense_hdr sshdr;
unsigned char cmd[16];
unsigned int rep_len;
int result;
memset(cmd, 0, 16);
cmd[0] = ZBC_IN;
cmd[1] = ZI_REPORT_ZONES;
put_unaligned_be64(lba, &cmd[2]);
put_unaligned_be32(buflen, &cmd[10]);
memset(buf, 0, buflen);
result = scsi_execute_req(sdp, cmd, DMA_FROM_DEVICE,
buf, buflen, &sshdr,
timeout, SD_MAX_RETRIES, NULL);
if (result) {
sd_printk(KERN_ERR, sdkp,
"REPORT ZONES lba %llu failed with %d/%d\n",
(unsigned long long)lba,
host_byte(result), driver_byte(result));
return -EIO;
}
rep_len = get_unaligned_be32(&buf[0]);
if (rep_len < 64) {
sd_printk(KERN_ERR, sdkp,
"REPORT ZONES report invalid length %u\n",
rep_len);
return -EIO;
}
return 0;
}
int sd_zbc_setup_report_cmnd(struct scsi_cmnd *cmd)
{
struct request *rq = cmd->request;
struct scsi_disk *sdkp = scsi_disk(rq->rq_disk);
sector_t lba, sector = blk_rq_pos(rq);
unsigned int nr_bytes = blk_rq_bytes(rq);
int ret;
WARN_ON(nr_bytes == 0);
if (!sd_is_zoned(sdkp))
return BLKPREP_KILL;
ret = scsi_init_io(cmd);
if (ret != BLKPREP_OK)
return ret;
cmd->cmd_len = 16;
memset(cmd->cmnd, 0, cmd->cmd_len);
cmd->cmnd[0] = ZBC_IN;
cmd->cmnd[1] = ZI_REPORT_ZONES;
lba = sectors_to_logical(sdkp->device, sector);
put_unaligned_be64(lba, &cmd->cmnd[2]);
put_unaligned_be32(nr_bytes, &cmd->cmnd[10]);
cmd->cmnd[14] = ZBC_REPORT_ZONE_PARTIAL;
cmd->sc_data_direction = DMA_FROM_DEVICE;
cmd->sdb.length = nr_bytes;
cmd->transfersize = sdkp->device->sector_size;
cmd->allowed = 0;
rq->__data_len = nr_bytes;
return BLKPREP_OK;
}
static void sd_zbc_report_zones_complete(struct scsi_cmnd *scmd,
unsigned int good_bytes)
{
struct request *rq = scmd->request;
struct scsi_disk *sdkp = scsi_disk(rq->rq_disk);
struct sg_mapping_iter miter;
struct blk_zone_report_hdr hdr;
struct blk_zone zone;
unsigned int offset, bytes = 0;
unsigned long flags;
u8 *buf;
if (good_bytes < 64)
return;
memset(&hdr, 0, sizeof(struct blk_zone_report_hdr));
sg_miter_start(&miter, scsi_sglist(scmd), scsi_sg_count(scmd),
SG_MITER_TO_SG | SG_MITER_ATOMIC);
local_irq_save(flags);
while (sg_miter_next(&miter) && bytes < good_bytes) {
buf = miter.addr;
offset = 0;
if (bytes == 0) {
hdr.nr_zones = min_t(unsigned int,
(good_bytes - 64) / 64,
get_unaligned_be32(&buf[0]) / 64);
memcpy(buf, &hdr, sizeof(struct blk_zone_report_hdr));
offset += 64;
bytes += 64;
}
while (offset < miter.length && hdr.nr_zones) {
WARN_ON(offset > miter.length);
buf = miter.addr + offset;
sd_zbc_parse_report(sdkp, buf, &zone);
memcpy(buf, &zone, sizeof(struct blk_zone));
offset += 64;
bytes += 64;
hdr.nr_zones--;
}
if (!hdr.nr_zones)
break;
}
sg_miter_stop(&miter);
local_irq_restore(flags);
}
static inline sector_t sd_zbc_zone_sectors(struct scsi_disk *sdkp)
{
return logical_to_sectors(sdkp->device, sdkp->zone_blocks);
}
static inline unsigned int sd_zbc_zone_no(struct scsi_disk *sdkp,
sector_t sector)
{
return sectors_to_logical(sdkp->device, sector) >> sdkp->zone_shift;
}
int sd_zbc_setup_reset_cmnd(struct scsi_cmnd *cmd)
{
struct request *rq = cmd->request;
struct scsi_disk *sdkp = scsi_disk(rq->rq_disk);
sector_t sector = blk_rq_pos(rq);
sector_t block = sectors_to_logical(sdkp->device, sector);
if (!sd_is_zoned(sdkp))
return BLKPREP_KILL;
if (sdkp->device->changed)
return BLKPREP_KILL;
if (sector & (sd_zbc_zone_sectors(sdkp) - 1))
return BLKPREP_KILL;
cmd->cmd_len = 16;
memset(cmd->cmnd, 0, cmd->cmd_len);
cmd->cmnd[0] = ZBC_OUT;
cmd->cmnd[1] = ZO_RESET_WRITE_POINTER;
put_unaligned_be64(block, &cmd->cmnd[2]);
rq->timeout = SD_TIMEOUT;
cmd->sc_data_direction = DMA_NONE;
cmd->transfersize = 0;
cmd->allowed = 0;
return BLKPREP_OK;
}
int sd_zbc_write_lock_zone(struct scsi_cmnd *cmd)
{
struct request *rq = cmd->request;
struct scsi_disk *sdkp = scsi_disk(rq->rq_disk);
sector_t sector = blk_rq_pos(rq);
sector_t zone_sectors = sd_zbc_zone_sectors(sdkp);
unsigned int zno = sd_zbc_zone_no(sdkp, sector);
if (blk_queue_zoned_model(sdkp->disk->queue) == BLK_ZONED_HM &&
(sector & (zone_sectors - 1)) + blk_rq_sectors(rq) > zone_sectors)
return BLKPREP_KILL;
if (sdkp->zones_wlock &&
test_and_set_bit(zno, sdkp->zones_wlock))
return BLKPREP_DEFER;
return BLKPREP_OK;
}
void sd_zbc_write_unlock_zone(struct scsi_cmnd *cmd)
{
struct request *rq = cmd->request;
struct scsi_disk *sdkp = scsi_disk(rq->rq_disk);
if (sdkp->zones_wlock) {
unsigned int zno = sd_zbc_zone_no(sdkp, blk_rq_pos(rq));
WARN_ON_ONCE(!test_bit(zno, sdkp->zones_wlock));
clear_bit_unlock(zno, sdkp->zones_wlock);
smp_mb__after_atomic();
}
}
void sd_zbc_complete(struct scsi_cmnd *cmd,
unsigned int good_bytes,
struct scsi_sense_hdr *sshdr)
{
int result = cmd->result;
struct request *rq = cmd->request;
switch (req_op(rq)) {
case REQ_OP_ZONE_RESET:
if (result &&
sshdr->sense_key == ILLEGAL_REQUEST &&
sshdr->asc == 0x24)
rq->rq_flags |= RQF_QUIET;
break;
case REQ_OP_WRITE:
case REQ_OP_WRITE_ZEROES:
case REQ_OP_WRITE_SAME:
sd_zbc_write_unlock_zone(cmd);
if (result &&
sshdr->sense_key == ILLEGAL_REQUEST &&
sshdr->asc == 0x21)
cmd->allowed = 0;
break;
case REQ_OP_ZONE_REPORT:
if (!result)
sd_zbc_report_zones_complete(cmd, good_bytes);
break;
}
}
static int sd_zbc_read_zoned_characteristics(struct scsi_disk *sdkp,
unsigned char *buf)
{
if (scsi_get_vpd_page(sdkp->device, 0xb6, buf, 64)) {
sd_printk(KERN_NOTICE, sdkp,
"Unconstrained-read check failed\n");
return -ENODEV;
}
if (sdkp->device->type != TYPE_ZBC) {
sdkp->urswrz = 1;
sdkp->zones_optimal_open = get_unaligned_be64(&buf[8]);
sdkp->zones_optimal_nonseq = get_unaligned_be64(&buf[12]);
sdkp->zones_max_open = 0;
} else {
sdkp->urswrz = buf[4] & 1;
sdkp->zones_optimal_open = 0;
sdkp->zones_optimal_nonseq = 0;
sdkp->zones_max_open = get_unaligned_be64(&buf[16]);
}
return 0;
}
static int sd_zbc_check_capacity(struct scsi_disk *sdkp,
unsigned char *buf)
{
sector_t lba;
int ret;
if (sdkp->rc_basis != 0)
return 0;
ret = sd_zbc_report_zones(sdkp, buf, SD_BUF_SIZE, 0);
if (ret)
return ret;
lba = get_unaligned_be64(&buf[8]);
if (lba + 1 == sdkp->capacity)
return 0;
if (sdkp->first_scan)
sd_printk(KERN_WARNING, sdkp,
"Changing capacity from %llu to max LBA+1 %llu\n",
(unsigned long long)sdkp->capacity,
(unsigned long long)lba + 1);
sdkp->capacity = lba + 1;
return 0;
}
static int sd_zbc_check_zone_size(struct scsi_disk *sdkp)
{
u64 zone_blocks;
sector_t block = 0;
unsigned char *buf;
unsigned char *rec;
unsigned int buf_len;
unsigned int list_length;
int ret;
u8 same;
sdkp->zone_blocks = 0;
buf = kmalloc(SD_ZBC_BUF_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = sd_zbc_report_zones(sdkp, buf, SD_ZBC_BUF_SIZE, 0);
if (ret) {
zone_blocks = 0;
goto out;
}
same = buf[4] & 0x0f;
if (same > 0) {
rec = &buf[64];
zone_blocks = get_unaligned_be64(&rec[8]);
goto out;
}
do {
list_length = get_unaligned_be32(&buf[0]) + 64;
rec = buf + 64;
if (list_length < SD_ZBC_BUF_SIZE)
buf_len = list_length;
else
buf_len = SD_ZBC_BUF_SIZE;
while (rec < buf + buf_len) {
zone_blocks = get_unaligned_be64(&rec[8]);
if (sdkp->zone_blocks == 0) {
sdkp->zone_blocks = zone_blocks;
} else if (zone_blocks != sdkp->zone_blocks &&
(block + zone_blocks < sdkp->capacity
|| zone_blocks > sdkp->zone_blocks)) {
zone_blocks = 0;
goto out;
}
block += zone_blocks;
rec += 64;
}
if (block < sdkp->capacity) {
ret = sd_zbc_report_zones(sdkp, buf,
SD_ZBC_BUF_SIZE, block);
if (ret)
return ret;
}
} while (block < sdkp->capacity);
zone_blocks = sdkp->zone_blocks;
out:
kfree(buf);
if (!zone_blocks) {
if (sdkp->first_scan)
sd_printk(KERN_NOTICE, sdkp,
"Devices with non constant zone "
"size are not supported\n");
return -ENODEV;
}
if (!is_power_of_2(zone_blocks)) {
if (sdkp->first_scan)
sd_printk(KERN_NOTICE, sdkp,
"Devices with non power of 2 zone "
"size are not supported\n");
return -ENODEV;
}
if (logical_to_sectors(sdkp->device, zone_blocks) > UINT_MAX) {
if (sdkp->first_scan)
sd_printk(KERN_NOTICE, sdkp,
"Zone size too large\n");
return -ENODEV;
}
sdkp->zone_blocks = zone_blocks;
return 0;
}
static int sd_zbc_setup(struct scsi_disk *sdkp)
{
blk_queue_chunk_sectors(sdkp->disk->queue,
logical_to_sectors(sdkp->device, sdkp->zone_blocks));
sdkp->zone_shift = ilog2(sdkp->zone_blocks);
sdkp->nr_zones = sdkp->capacity >> sdkp->zone_shift;
if (sdkp->capacity & (sdkp->zone_blocks - 1))
sdkp->nr_zones++;
if (!sdkp->zones_wlock) {
sdkp->zones_wlock = kcalloc(BITS_TO_LONGS(sdkp->nr_zones),
sizeof(unsigned long),
GFP_KERNEL);
if (!sdkp->zones_wlock)
return -ENOMEM;
}
return 0;
}
int sd_zbc_read_zones(struct scsi_disk *sdkp,
unsigned char *buf)
{
int ret;
if (!sd_is_zoned(sdkp))
return 0;
ret = sd_zbc_read_zoned_characteristics(sdkp, buf);
if (ret)
goto err;
if (!sdkp->urswrz) {
if (sdkp->first_scan)
sd_printk(KERN_NOTICE, sdkp,
"constrained reads devices are not supported\n");
ret = -ENODEV;
goto err;
}
ret = sd_zbc_check_capacity(sdkp, buf);
if (ret)
goto err;
ret = sd_zbc_check_zone_size(sdkp);
if (ret)
goto err;
ret = sd_zbc_setup(sdkp);
if (ret)
goto err;
sdkp->device->use_16_for_rw = 1;
sdkp->device->use_10_for_rw = 0;
return 0;
err:
sdkp->capacity = 0;
return ret;
}
void sd_zbc_remove(struct scsi_disk *sdkp)
{
kfree(sdkp->zones_wlock);
sdkp->zones_wlock = NULL;
}
void sd_zbc_print_zones(struct scsi_disk *sdkp)
{
if (!sd_is_zoned(sdkp) || !sdkp->capacity)
return;
if (sdkp->capacity & (sdkp->zone_blocks - 1))
sd_printk(KERN_NOTICE, sdkp,
"%u zones of %u logical blocks + 1 runt zone\n",
sdkp->nr_zones - 1,
sdkp->zone_blocks);
else
sd_printk(KERN_NOTICE, sdkp,
"%u zones of %u logical blocks\n",
sdkp->nr_zones,
sdkp->zone_blocks);
}
