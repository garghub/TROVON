static void ide_tf_set_cmd(ide_drive_t *drive, struct ide_cmd *cmd, u8 dma)
{
u8 index, lba48, write;
lba48 = (cmd->tf_flags & IDE_TFLAG_LBA48) ? 2 : 0;
write = (cmd->tf_flags & IDE_TFLAG_WRITE) ? 1 : 0;
if (dma) {
cmd->protocol = ATA_PROT_DMA;
index = 8;
} else {
cmd->protocol = ATA_PROT_PIO;
if (drive->mult_count) {
cmd->tf_flags |= IDE_TFLAG_MULTI_PIO;
index = 0;
} else
index = 4;
}
cmd->tf.command = ide_rw_cmds[index + lba48 + write];
}
static ide_startstop_t __ide_do_rw_disk(ide_drive_t *drive, struct request *rq,
sector_t block)
{
ide_hwif_t *hwif = drive->hwif;
u16 nsectors = (u16)blk_rq_sectors(rq);
u8 lba48 = !!(drive->dev_flags & IDE_DFLAG_LBA48);
u8 dma = !!(drive->dev_flags & IDE_DFLAG_USING_DMA);
struct ide_cmd cmd;
struct ide_taskfile *tf = &cmd.tf;
ide_startstop_t rc;
if ((hwif->host_flags & IDE_HFLAG_NO_LBA48_DMA) && lba48 && dma) {
if (block + blk_rq_sectors(rq) > 1ULL << 28)
dma = 0;
else
lba48 = 0;
}
memset(&cmd, 0, sizeof(cmd));
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
if (drive->dev_flags & IDE_DFLAG_LBA) {
if (lba48) {
pr_debug("%s: LBA=0x%012llx\n", drive->name,
(unsigned long long)block);
tf->nsect = nsectors & 0xff;
tf->lbal = (u8) block;
tf->lbam = (u8)(block >> 8);
tf->lbah = (u8)(block >> 16);
tf->device = ATA_LBA;
tf = &cmd.hob;
tf->nsect = (nsectors >> 8) & 0xff;
tf->lbal = (u8)(block >> 24);
if (sizeof(block) != 4) {
tf->lbam = (u8)((u64)block >> 32);
tf->lbah = (u8)((u64)block >> 40);
}
cmd.valid.out.hob = IDE_VALID_OUT_HOB;
cmd.valid.in.hob = IDE_VALID_IN_HOB;
cmd.tf_flags |= IDE_TFLAG_LBA48;
} else {
tf->nsect = nsectors & 0xff;
tf->lbal = block;
tf->lbam = block >>= 8;
tf->lbah = block >>= 8;
tf->device = ((block >> 8) & 0xf) | ATA_LBA;
}
} else {
unsigned int sect, head, cyl, track;
track = (int)block / drive->sect;
sect = (int)block % drive->sect + 1;
head = track % drive->head;
cyl = track / drive->head;
pr_debug("%s: CHS=%u/%u/%u\n", drive->name, cyl, head, sect);
tf->nsect = nsectors & 0xff;
tf->lbal = sect;
tf->lbam = cyl;
tf->lbah = cyl >> 8;
tf->device = head;
}
cmd.tf_flags |= IDE_TFLAG_FS;
if (rq_data_dir(rq))
cmd.tf_flags |= IDE_TFLAG_WRITE;
ide_tf_set_cmd(drive, &cmd, dma);
cmd.rq = rq;
if (dma == 0) {
ide_init_sg_cmd(&cmd, nsectors << 9);
ide_map_sg(drive, &cmd);
}
rc = do_rw_taskfile(drive, &cmd);
if (rc == ide_stopped && dma) {
cmd.tf_flags |= IDE_TFLAG_DMA_PIO_FALLBACK;
ide_tf_set_cmd(drive, &cmd, 0);
ide_init_sg_cmd(&cmd, nsectors << 9);
rc = do_rw_taskfile(drive, &cmd);
}
return rc;
}
static ide_startstop_t ide_do_rw_disk(ide_drive_t *drive, struct request *rq,
sector_t block)
{
ide_hwif_t *hwif = drive->hwif;
BUG_ON(drive->dev_flags & IDE_DFLAG_BLOCKED);
BUG_ON(blk_rq_is_passthrough(rq));
ledtrig_disk_activity();
pr_debug("%s: %sing: block=%llu, sectors=%u\n",
drive->name, rq_data_dir(rq) == READ ? "read" : "writ",
(unsigned long long)block, blk_rq_sectors(rq));
if (hwif->rw_disk)
hwif->rw_disk(drive, rq);
return __ide_do_rw_disk(drive, rq, block);
}
static u64 idedisk_read_native_max_address(ide_drive_t *drive, int lba48)
{
struct ide_cmd cmd;
struct ide_taskfile *tf = &cmd.tf;
u64 addr = 0;
memset(&cmd, 0, sizeof(cmd));
if (lba48)
tf->command = ATA_CMD_READ_NATIVE_MAX_EXT;
else
tf->command = ATA_CMD_READ_NATIVE_MAX;
tf->device = ATA_LBA;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
if (lba48) {
cmd.valid.out.hob = IDE_VALID_OUT_HOB;
cmd.valid.in.hob = IDE_VALID_IN_HOB;
cmd.tf_flags = IDE_TFLAG_LBA48;
}
ide_no_data_taskfile(drive, &cmd);
if (!(tf->status & ATA_ERR))
addr = ide_get_lba_addr(&cmd, lba48) + 1;
return addr;
}
static u64 idedisk_set_max_address(ide_drive_t *drive, u64 addr_req, int lba48)
{
struct ide_cmd cmd;
struct ide_taskfile *tf = &cmd.tf;
u64 addr_set = 0;
addr_req--;
memset(&cmd, 0, sizeof(cmd));
tf->lbal = (addr_req >> 0) & 0xff;
tf->lbam = (addr_req >>= 8) & 0xff;
tf->lbah = (addr_req >>= 8) & 0xff;
if (lba48) {
cmd.hob.lbal = (addr_req >>= 8) & 0xff;
cmd.hob.lbam = (addr_req >>= 8) & 0xff;
cmd.hob.lbah = (addr_req >>= 8) & 0xff;
tf->command = ATA_CMD_SET_MAX_EXT;
} else {
tf->device = (addr_req >>= 8) & 0x0f;
tf->command = ATA_CMD_SET_MAX;
}
tf->device |= ATA_LBA;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
if (lba48) {
cmd.valid.out.hob = IDE_VALID_OUT_HOB;
cmd.valid.in.hob = IDE_VALID_IN_HOB;
cmd.tf_flags = IDE_TFLAG_LBA48;
}
ide_no_data_taskfile(drive, &cmd);
if (!(tf->status & ATA_ERR))
addr_set = ide_get_lba_addr(&cmd, lba48) + 1;
return addr_set;
}
static unsigned long long sectors_to_MB(unsigned long long n)
{
n <<= 9;
do_div(n, 1000000);
return n;
}
static u64 ide_disk_hpa_get_native_capacity(ide_drive_t *drive, int lba48)
{
u64 capacity, set_max;
capacity = drive->capacity64;
set_max = idedisk_read_native_max_address(drive, lba48);
if (ide_in_drive_list(drive->id, hpa_list)) {
if (set_max == capacity + 1)
set_max--;
}
return set_max;
}
static u64 ide_disk_hpa_set_capacity(ide_drive_t *drive, u64 set_max, int lba48)
{
set_max = idedisk_set_max_address(drive, set_max, lba48);
if (set_max)
drive->capacity64 = set_max;
return set_max;
}
static void idedisk_check_hpa(ide_drive_t *drive)
{
u64 capacity, set_max;
int lba48 = ata_id_lba48_enabled(drive->id);
capacity = drive->capacity64;
set_max = ide_disk_hpa_get_native_capacity(drive, lba48);
if (set_max <= capacity)
return;
drive->probed_capacity = set_max;
printk(KERN_INFO "%s: Host Protected Area detected.\n"
"\tcurrent capacity is %llu sectors (%llu MB)\n"
"\tnative capacity is %llu sectors (%llu MB)\n",
drive->name,
capacity, sectors_to_MB(capacity),
set_max, sectors_to_MB(set_max));
if ((drive->dev_flags & IDE_DFLAG_NOHPA) == 0)
return;
set_max = ide_disk_hpa_set_capacity(drive, set_max, lba48);
if (set_max)
printk(KERN_INFO "%s: Host Protected Area disabled.\n",
drive->name);
}
static int ide_disk_get_capacity(ide_drive_t *drive)
{
u16 *id = drive->id;
int lba;
if (ata_id_lba48_enabled(id)) {
lba = 1;
drive->capacity64 = ata_id_u64(id, ATA_ID_LBA_CAPACITY_2);
} else if (ata_id_has_lba(id) && ata_id_is_lba_capacity_ok(id)) {
lba = 1;
drive->capacity64 = ata_id_u32(id, ATA_ID_LBA_CAPACITY);
} else {
lba = 0;
drive->capacity64 = drive->cyl * drive->head * drive->sect;
}
drive->probed_capacity = drive->capacity64;
if (lba) {
drive->dev_flags |= IDE_DFLAG_LBA;
if (ata_id_hpa_enabled(id))
idedisk_check_hpa(drive);
}
if ((drive->dev_flags & IDE_DFLAG_LBA48) == 0 &&
drive->capacity64 > 1ULL << 28) {
printk(KERN_WARNING "%s: cannot use LBA48 - full capacity "
"%llu sectors (%llu MB)\n",
drive->name, (unsigned long long)drive->capacity64,
sectors_to_MB(drive->capacity64));
drive->probed_capacity = drive->capacity64 = 1ULL << 28;
}
if ((drive->hwif->host_flags & IDE_HFLAG_NO_LBA48_DMA) &&
(drive->dev_flags & IDE_DFLAG_LBA48)) {
if (drive->capacity64 > 1ULL << 28) {
printk(KERN_INFO "%s: cannot use LBA48 DMA - PIO mode"
" will be used for accessing sectors "
"> %u\n", drive->name, 1 << 28);
} else
drive->dev_flags &= ~IDE_DFLAG_LBA48;
}
return 0;
}
static void ide_disk_unlock_native_capacity(ide_drive_t *drive)
{
u16 *id = drive->id;
int lba48 = ata_id_lba48_enabled(id);
if ((drive->dev_flags & IDE_DFLAG_LBA) == 0 ||
ata_id_hpa_enabled(id) == 0)
return;
if (!ide_disk_hpa_get_native_capacity(drive, lba48))
return;
if (ide_disk_hpa_set_capacity(drive, drive->probed_capacity, lba48))
drive->dev_flags |= IDE_DFLAG_NOHPA;
}
static int idedisk_prep_fn(struct request_queue *q, struct request *rq)
{
ide_drive_t *drive = q->queuedata;
struct ide_cmd *cmd;
if (req_op(rq) != REQ_OP_FLUSH)
return BLKPREP_OK;
if (rq->special) {
cmd = rq->special;
memset(cmd, 0, sizeof(*cmd));
} else {
cmd = kzalloc(sizeof(*cmd), GFP_ATOMIC);
}
BUG_ON(cmd == NULL);
if (ata_id_flush_ext_enabled(drive->id) &&
(drive->capacity64 >= (1UL << 28)))
cmd->tf.command = ATA_CMD_FLUSH_EXT;
else
cmd->tf.command = ATA_CMD_FLUSH;
cmd->valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd->tf_flags = IDE_TFLAG_DYN;
cmd->protocol = ATA_PROT_NODATA;
rq->cmd_flags &= ~REQ_OP_MASK;
rq->cmd_flags |= REQ_OP_DRV_OUT;
ide_req(rq)->type = ATA_PRIV_TASKFILE;
rq->special = cmd;
cmd->rq = rq;
return BLKPREP_OK;
}
static int set_multcount(ide_drive_t *drive, int arg)
{
struct request *rq;
if (arg < 0 || arg > (drive->id[ATA_ID_MAX_MULTSECT] & 0xff))
return -EINVAL;
if (drive->special_flags & IDE_SFLAG_SET_MULTMODE)
return -EBUSY;
rq = blk_get_request(drive->queue, REQ_OP_DRV_IN, __GFP_RECLAIM);
scsi_req_init(rq);
ide_req(rq)->type = ATA_PRIV_TASKFILE;
drive->mult_req = arg;
drive->special_flags |= IDE_SFLAG_SET_MULTMODE;
blk_execute_rq(drive->queue, NULL, rq, 0);
blk_put_request(rq);
return (drive->mult_count == arg) ? 0 : -EIO;
}
static int set_nowerr(ide_drive_t *drive, int arg)
{
if (arg < 0 || arg > 1)
return -EINVAL;
if (arg)
drive->dev_flags |= IDE_DFLAG_NOWERR;
else
drive->dev_flags &= ~IDE_DFLAG_NOWERR;
drive->bad_wstat = arg ? BAD_R_STAT : BAD_W_STAT;
return 0;
}
static int ide_do_setfeature(ide_drive_t *drive, u8 feature, u8 nsect)
{
struct ide_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.tf.feature = feature;
cmd.tf.nsect = nsect;
cmd.tf.command = ATA_CMD_SET_FEATURES;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
return ide_no_data_taskfile(drive, &cmd);
}
static void update_flush(ide_drive_t *drive)
{
u16 *id = drive->id;
bool wc = false;
if (drive->dev_flags & IDE_DFLAG_WCACHE) {
unsigned long long capacity;
int barrier;
capacity = ide_gd_capacity(drive);
barrier = ata_id_flush_enabled(id) &&
(drive->dev_flags & IDE_DFLAG_NOFLUSH) == 0 &&
((drive->dev_flags & IDE_DFLAG_LBA48) == 0 ||
capacity <= (1ULL << 28) ||
ata_id_flush_ext_enabled(id));
printk(KERN_INFO "%s: cache flushes %ssupported\n",
drive->name, barrier ? "" : "not ");
if (barrier) {
wc = true;
blk_queue_prep_rq(drive->queue, idedisk_prep_fn);
}
}
blk_queue_write_cache(drive->queue, wc, false);
}
static int set_wcache(ide_drive_t *drive, int arg)
{
int err = 1;
if (arg < 0 || arg > 1)
return -EINVAL;
if (ata_id_flush_enabled(drive->id)) {
err = ide_do_setfeature(drive,
arg ? SETFEATURES_WC_ON : SETFEATURES_WC_OFF, 0);
if (err == 0) {
if (arg)
drive->dev_flags |= IDE_DFLAG_WCACHE;
else
drive->dev_flags &= ~IDE_DFLAG_WCACHE;
}
}
update_flush(drive);
return err;
}
static int do_idedisk_flushcache(ide_drive_t *drive)
{
struct ide_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
if (ata_id_flush_ext_enabled(drive->id))
cmd.tf.command = ATA_CMD_FLUSH_EXT;
else
cmd.tf.command = ATA_CMD_FLUSH;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
return ide_no_data_taskfile(drive, &cmd);
}
static int set_acoustic(ide_drive_t *drive, int arg)
{
if (arg < 0 || arg > 254)
return -EINVAL;
ide_do_setfeature(drive,
arg ? SETFEATURES_AAM_ON : SETFEATURES_AAM_OFF, arg);
drive->acoustic = arg;
return 0;
}
static int set_addressing(ide_drive_t *drive, int arg)
{
if (arg < 0 || arg > 2)
return -EINVAL;
if (arg && ((drive->hwif->host_flags & IDE_HFLAG_NO_LBA48) ||
ata_id_lba48_enabled(drive->id) == 0))
return -EIO;
if (arg == 2)
arg = 0;
if (arg)
drive->dev_flags |= IDE_DFLAG_LBA48;
else
drive->dev_flags &= ~IDE_DFLAG_LBA48;
return 0;
}
static int ide_disk_check(ide_drive_t *drive, const char *s)
{
return 1;
}
static void ide_disk_setup(ide_drive_t *drive)
{
struct ide_disk_obj *idkp = drive->driver_data;
struct request_queue *q = drive->queue;
ide_hwif_t *hwif = drive->hwif;
u16 *id = drive->id;
char *m = (char *)&id[ATA_ID_PROD];
unsigned long long capacity;
ide_proc_register_driver(drive, idkp->driver);
if ((drive->dev_flags & IDE_DFLAG_ID_READ) == 0)
return;
if (drive->dev_flags & IDE_DFLAG_REMOVABLE) {
if (m[0] != 'W' || m[1] != 'D')
drive->dev_flags |= IDE_DFLAG_DOORLOCKING;
}
(void)set_addressing(drive, 1);
if (drive->dev_flags & IDE_DFLAG_LBA48) {
int max_s = 2048;
if (max_s > hwif->rqsize)
max_s = hwif->rqsize;
blk_queue_max_hw_sectors(q, max_s);
}
printk(KERN_INFO "%s: max request size: %dKiB\n", drive->name,
queue_max_sectors(q) / 2);
if (ata_id_is_ssd(id)) {
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, q);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, q);
}
ide_disk_get_capacity(drive);
capacity = ide_gd_capacity(drive);
if ((drive->dev_flags & IDE_DFLAG_FORCED_GEOM) == 0) {
if (ata_id_lba48_enabled(drive->id)) {
drive->bios_sect = 63;
drive->bios_head = 255;
}
if (drive->bios_sect && drive->bios_head) {
unsigned int cap0 = capacity;
unsigned int cylsz, cyl;
if (cap0 != capacity)
drive->bios_cyl = 65535;
else {
cylsz = drive->bios_sect * drive->bios_head;
cyl = cap0 / cylsz;
if (cyl > 65535)
cyl = 65535;
if (cyl > drive->bios_cyl)
drive->bios_cyl = cyl;
}
}
}
printk(KERN_INFO "%s: %llu sectors (%llu MB)",
drive->name, capacity, sectors_to_MB(capacity));
if (id[ATA_ID_BUF_SIZE])
printk(KERN_CONT " w/%dKiB Cache", id[ATA_ID_BUF_SIZE] / 2);
printk(KERN_CONT ", CHS=%d/%d/%d\n",
drive->bios_cyl, drive->bios_head, drive->bios_sect);
if ((id[ATA_ID_CSFO] & 1) || ata_id_wcache_enabled(id))
drive->dev_flags |= IDE_DFLAG_WCACHE;
set_wcache(drive, 1);
if ((drive->dev_flags & IDE_DFLAG_LBA) == 0 &&
(drive->head == 0 || drive->head > 16)) {
printk(KERN_ERR "%s: invalid geometry: %d physical heads?\n",
drive->name, drive->head);
drive->dev_flags &= ~IDE_DFLAG_ATTACH;
} else
drive->dev_flags |= IDE_DFLAG_ATTACH;
}
static void ide_disk_flush(ide_drive_t *drive)
{
if (ata_id_flush_enabled(drive->id) == 0 ||
(drive->dev_flags & IDE_DFLAG_WCACHE) == 0)
return;
if (do_idedisk_flushcache(drive))
printk(KERN_INFO "%s: wcache flush failed!\n", drive->name);
}
static int ide_disk_init_media(ide_drive_t *drive, struct gendisk *disk)
{
return 0;
}
static int ide_disk_set_doorlock(ide_drive_t *drive, struct gendisk *disk,
int on)
{
struct ide_cmd cmd;
int ret;
if ((drive->dev_flags & IDE_DFLAG_DOORLOCKING) == 0)
return 0;
memset(&cmd, 0, sizeof(cmd));
cmd.tf.command = on ? ATA_CMD_MEDIA_LOCK : ATA_CMD_MEDIA_UNLOCK;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
ret = ide_no_data_taskfile(drive, &cmd);
if (ret)
drive->dev_flags &= ~IDE_DFLAG_DOORLOCKING;
return ret;
}
