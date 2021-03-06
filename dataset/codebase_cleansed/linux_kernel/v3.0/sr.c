static inline struct scsi_cd *scsi_cd(struct gendisk *disk)
{
return container_of(disk->private_data, struct scsi_cd, driver);
}
static inline struct scsi_cd *scsi_cd_get(struct gendisk *disk)
{
struct scsi_cd *cd = NULL;
mutex_lock(&sr_ref_mutex);
if (disk->private_data == NULL)
goto out;
cd = scsi_cd(disk);
kref_get(&cd->kref);
if (scsi_device_get(cd->device))
goto out_put;
goto out;
out_put:
kref_put(&cd->kref, sr_kref_release);
cd = NULL;
out:
mutex_unlock(&sr_ref_mutex);
return cd;
}
static void scsi_cd_put(struct scsi_cd *cd)
{
struct scsi_device *sdev = cd->device;
mutex_lock(&sr_ref_mutex);
kref_put(&cd->kref, sr_kref_release);
scsi_device_put(sdev);
mutex_unlock(&sr_ref_mutex);
}
static unsigned int sr_get_events(struct scsi_device *sdev)
{
u8 buf[8];
u8 cmd[] = { GET_EVENT_STATUS_NOTIFICATION,
1,
0, 0,
1 << 4,
0, 0,
0, sizeof(buf),
0,
};
struct event_header *eh = (void *)buf;
struct media_event_desc *med = (void *)(buf + 4);
struct scsi_sense_hdr sshdr;
int result;
result = scsi_execute_req(sdev, cmd, DMA_FROM_DEVICE, buf, sizeof(buf),
&sshdr, SR_TIMEOUT, MAX_RETRIES, NULL);
if (scsi_sense_valid(&sshdr) && sshdr.sense_key == UNIT_ATTENTION)
return DISK_EVENT_MEDIA_CHANGE;
if (result || be16_to_cpu(eh->data_len) < sizeof(*med))
return 0;
if (eh->nea || eh->notification_class != 0x4)
return 0;
if (med->media_event_code == 1)
return DISK_EVENT_EJECT_REQUEST;
else if (med->media_event_code == 2)
return DISK_EVENT_MEDIA_CHANGE;
return 0;
}
static unsigned int sr_check_events(struct cdrom_device_info *cdi,
unsigned int clearing, int slot)
{
struct scsi_cd *cd = cdi->handle;
bool last_present;
struct scsi_sense_hdr sshdr;
unsigned int events;
int ret;
if (CDSL_CURRENT != slot)
return 0;
events = sr_get_events(cd->device);
if (!(clearing & DISK_EVENT_MEDIA_CHANGE))
goto skip_tur;
last_present = cd->media_present;
ret = scsi_test_unit_ready(cd->device, SR_TIMEOUT, MAX_RETRIES, &sshdr);
cd->media_present = scsi_status_is_good(ret) ||
(scsi_sense_valid(&sshdr) && sshdr.asc != 0x3a);
if (last_present != cd->media_present)
events |= DISK_EVENT_MEDIA_CHANGE;
skip_tur:
if (cd->device->changed) {
events |= DISK_EVENT_MEDIA_CHANGE;
cd->device->changed = 0;
}
return events;
}
static int sr_done(struct scsi_cmnd *SCpnt)
{
int result = SCpnt->result;
int this_count = scsi_bufflen(SCpnt);
int good_bytes = (result == 0 ? this_count : 0);
int block_sectors = 0;
long error_sector;
struct scsi_cd *cd = scsi_cd(SCpnt->request->rq_disk);
#ifdef DEBUG
printk("sr.c done: %x\n", result);
#endif
if (driver_byte(result) != 0 &&
(SCpnt->sense_buffer[0] & 0x7f) == 0x70) {
switch (SCpnt->sense_buffer[2]) {
case MEDIUM_ERROR:
case VOLUME_OVERFLOW:
case ILLEGAL_REQUEST:
if (!(SCpnt->sense_buffer[0] & 0x90))
break;
error_sector = (SCpnt->sense_buffer[3] << 24) |
(SCpnt->sense_buffer[4] << 16) |
(SCpnt->sense_buffer[5] << 8) |
SCpnt->sense_buffer[6];
if (SCpnt->request->bio != NULL)
block_sectors =
bio_sectors(SCpnt->request->bio);
if (block_sectors < 4)
block_sectors = 4;
if (cd->device->sector_size == 2048)
error_sector <<= 2;
error_sector &= ~(block_sectors - 1);
good_bytes = (error_sector -
blk_rq_pos(SCpnt->request)) << 9;
if (good_bytes < 0 || good_bytes >= this_count)
good_bytes = 0;
if (error_sector < get_capacity(cd->disk) &&
cd->capacity - error_sector < 4 * 75)
set_capacity(cd->disk, error_sector);
break;
case RECOVERED_ERROR:
good_bytes = this_count;
break;
default:
break;
}
}
return good_bytes;
}
static int sr_prep_fn(struct request_queue *q, struct request *rq)
{
int block = 0, this_count, s_size;
struct scsi_cd *cd;
struct scsi_cmnd *SCpnt;
struct scsi_device *sdp = q->queuedata;
int ret;
if (rq->cmd_type == REQ_TYPE_BLOCK_PC) {
ret = scsi_setup_blk_pc_cmnd(sdp, rq);
goto out;
} else if (rq->cmd_type != REQ_TYPE_FS) {
ret = BLKPREP_KILL;
goto out;
}
ret = scsi_setup_fs_cmnd(sdp, rq);
if (ret != BLKPREP_OK)
goto out;
SCpnt = rq->special;
cd = scsi_cd(rq->rq_disk);
ret = BLKPREP_KILL;
SCSI_LOG_HLQUEUE(1, printk("Doing sr request, dev = %s, block = %d\n",
cd->disk->disk_name, block));
if (!cd->device || !scsi_device_online(cd->device)) {
SCSI_LOG_HLQUEUE(2, printk("Finishing %u sectors\n",
blk_rq_sectors(rq)));
SCSI_LOG_HLQUEUE(2, printk("Retry with 0x%p\n", SCpnt));
goto out;
}
if (cd->device->changed) {
goto out;
}
s_size = cd->device->sector_size;
if (s_size > 2048) {
if (!in_interrupt())
sr_set_blocklength(cd, 2048);
else
printk("sr: can't switch blocksize: in interrupt\n");
}
if (s_size != 512 && s_size != 1024 && s_size != 2048) {
scmd_printk(KERN_ERR, SCpnt, "bad sector size %d\n", s_size);
goto out;
}
if (rq_data_dir(rq) == WRITE) {
if (!cd->device->writeable)
goto out;
SCpnt->cmnd[0] = WRITE_10;
SCpnt->sc_data_direction = DMA_TO_DEVICE;
cd->cdi.media_written = 1;
} else if (rq_data_dir(rq) == READ) {
SCpnt->cmnd[0] = READ_10;
SCpnt->sc_data_direction = DMA_FROM_DEVICE;
} else {
blk_dump_rq_flags(rq, "Unknown sr command");
goto out;
}
{
struct scatterlist *sg;
int i, size = 0, sg_count = scsi_sg_count(SCpnt);
scsi_for_each_sg(SCpnt, sg, sg_count, i)
size += sg->length;
if (size != scsi_bufflen(SCpnt)) {
scmd_printk(KERN_ERR, SCpnt,
"mismatch count %d, bytes %d\n",
size, scsi_bufflen(SCpnt));
if (scsi_bufflen(SCpnt) > size)
SCpnt->sdb.length = size;
}
}
if (((unsigned int)blk_rq_pos(rq) % (s_size >> 9)) ||
(scsi_bufflen(SCpnt) % s_size)) {
scmd_printk(KERN_NOTICE, SCpnt, "unaligned transfer\n");
goto out;
}
this_count = (scsi_bufflen(SCpnt) >> 9) / (s_size >> 9);
SCSI_LOG_HLQUEUE(2, printk("%s : %s %d/%u 512 byte blocks.\n",
cd->cdi.name,
(rq_data_dir(rq) == WRITE) ?
"writing" : "reading",
this_count, blk_rq_sectors(rq)));
SCpnt->cmnd[1] = 0;
block = (unsigned int)blk_rq_pos(rq) / (s_size >> 9);
if (this_count > 0xffff) {
this_count = 0xffff;
SCpnt->sdb.length = this_count * s_size;
}
SCpnt->cmnd[2] = (unsigned char) (block >> 24) & 0xff;
SCpnt->cmnd[3] = (unsigned char) (block >> 16) & 0xff;
SCpnt->cmnd[4] = (unsigned char) (block >> 8) & 0xff;
SCpnt->cmnd[5] = (unsigned char) block & 0xff;
SCpnt->cmnd[6] = SCpnt->cmnd[9] = 0;
SCpnt->cmnd[7] = (unsigned char) (this_count >> 8) & 0xff;
SCpnt->cmnd[8] = (unsigned char) this_count & 0xff;
SCpnt->transfersize = cd->device->sector_size;
SCpnt->underflow = this_count << 9;
SCpnt->allowed = MAX_RETRIES;
ret = BLKPREP_OK;
out:
return scsi_prep_return(q, rq, ret);
}
static int sr_block_open(struct block_device *bdev, fmode_t mode)
{
struct scsi_cd *cd;
int ret = -ENXIO;
mutex_lock(&sr_mutex);
cd = scsi_cd_get(bdev->bd_disk);
if (cd) {
ret = cdrom_open(&cd->cdi, bdev, mode);
if (ret)
scsi_cd_put(cd);
}
mutex_unlock(&sr_mutex);
return ret;
}
static int sr_block_release(struct gendisk *disk, fmode_t mode)
{
struct scsi_cd *cd = scsi_cd(disk);
mutex_lock(&sr_mutex);
cdrom_release(&cd->cdi, mode);
scsi_cd_put(cd);
mutex_unlock(&sr_mutex);
return 0;
}
static int sr_block_ioctl(struct block_device *bdev, fmode_t mode, unsigned cmd,
unsigned long arg)
{
struct scsi_cd *cd = scsi_cd(bdev->bd_disk);
struct scsi_device *sdev = cd->device;
void __user *argp = (void __user *)arg;
int ret;
mutex_lock(&sr_mutex);
switch (cmd) {
case SCSI_IOCTL_GET_IDLUN:
case SCSI_IOCTL_GET_BUS_NUMBER:
ret = scsi_ioctl(sdev, cmd, argp);
goto out;
}
ret = cdrom_ioctl(&cd->cdi, bdev, mode, cmd, arg);
if (ret != -ENOSYS)
goto out;
ret = scsi_nonblockable_ioctl(sdev, cmd, argp,
(mode & FMODE_NDELAY) != 0);
if (ret != -ENODEV)
goto out;
ret = scsi_ioctl(sdev, cmd, argp);
out:
mutex_unlock(&sr_mutex);
return ret;
}
static unsigned int sr_block_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct scsi_cd *cd = scsi_cd(disk);
return cdrom_check_events(&cd->cdi, clearing);
}
static int sr_block_revalidate_disk(struct gendisk *disk)
{
struct scsi_cd *cd = scsi_cd(disk);
struct scsi_sense_hdr sshdr;
if (scsi_test_unit_ready(cd->device, SR_TIMEOUT, MAX_RETRIES, &sshdr))
return 0;
sr_cd_check(&cd->cdi);
get_sectorsize(cd);
return 0;
}
static int sr_open(struct cdrom_device_info *cdi, int purpose)
{
struct scsi_cd *cd = cdi->handle;
struct scsi_device *sdev = cd->device;
int retval;
retval = -ENXIO;
if (!scsi_block_when_processing_errors(sdev))
goto error_out;
return 0;
error_out:
return retval;
}
static void sr_release(struct cdrom_device_info *cdi)
{
struct scsi_cd *cd = cdi->handle;
if (cd->device->sector_size > 2048)
sr_set_blocklength(cd, 2048);
}
static int sr_probe(struct device *dev)
{
struct scsi_device *sdev = to_scsi_device(dev);
struct gendisk *disk;
struct scsi_cd *cd;
int minor, error;
error = -ENODEV;
if (sdev->type != TYPE_ROM && sdev->type != TYPE_WORM)
goto fail;
error = -ENOMEM;
cd = kzalloc(sizeof(*cd), GFP_KERNEL);
if (!cd)
goto fail;
kref_init(&cd->kref);
disk = alloc_disk(1);
if (!disk)
goto fail_free;
spin_lock(&sr_index_lock);
minor = find_first_zero_bit(sr_index_bits, SR_DISKS);
if (minor == SR_DISKS) {
spin_unlock(&sr_index_lock);
error = -EBUSY;
goto fail_put;
}
__set_bit(minor, sr_index_bits);
spin_unlock(&sr_index_lock);
disk->major = SCSI_CDROM_MAJOR;
disk->first_minor = minor;
sprintf(disk->disk_name, "sr%d", minor);
disk->fops = &sr_bdops;
disk->flags = GENHD_FL_CD | GENHD_FL_BLOCK_EVENTS_ON_EXCL_WRITE;
disk->events = DISK_EVENT_MEDIA_CHANGE | DISK_EVENT_EJECT_REQUEST;
blk_queue_rq_timeout(sdev->request_queue, SR_TIMEOUT);
cd->device = sdev;
cd->disk = disk;
cd->driver = &sr_template;
cd->disk = disk;
cd->capacity = 0x1fffff;
cd->device->changed = 1;
cd->media_present = 1;
cd->use = 1;
cd->readcd_known = 0;
cd->readcd_cdda = 0;
cd->cdi.ops = &sr_dops;
cd->cdi.handle = cd;
cd->cdi.mask = 0;
cd->cdi.capacity = 1;
sprintf(cd->cdi.name, "sr%d", minor);
sdev->sector_size = 2048;
get_capabilities(cd);
blk_queue_prep_rq(sdev->request_queue, sr_prep_fn);
sr_vendor_init(cd);
disk->driverfs_dev = &sdev->sdev_gendev;
set_capacity(disk, cd->capacity);
disk->private_data = &cd->driver;
disk->queue = sdev->request_queue;
cd->cdi.disk = disk;
if (register_cdrom(&cd->cdi))
goto fail_put;
dev_set_drvdata(dev, cd);
disk->flags |= GENHD_FL_REMOVABLE;
add_disk(disk);
sdev_printk(KERN_DEBUG, sdev,
"Attached scsi CD-ROM %s\n", cd->cdi.name);
return 0;
fail_put:
put_disk(disk);
fail_free:
kfree(cd);
fail:
return error;
}
static void get_sectorsize(struct scsi_cd *cd)
{
unsigned char cmd[10];
unsigned char buffer[8];
int the_result, retries = 3;
int sector_size;
struct request_queue *queue;
do {
cmd[0] = READ_CAPACITY;
memset((void *) &cmd[1], 0, 9);
memset(buffer, 0, sizeof(buffer));
the_result = scsi_execute_req(cd->device, cmd, DMA_FROM_DEVICE,
buffer, sizeof(buffer), NULL,
SR_TIMEOUT, MAX_RETRIES, NULL);
retries--;
} while (the_result && retries);
if (the_result) {
cd->capacity = 0x1fffff;
sector_size = 2048;
} else {
long last_written;
cd->capacity = 1 + ((buffer[0] << 24) | (buffer[1] << 16) |
(buffer[2] << 8) | buffer[3]);
if (!cdrom_get_last_written(&cd->cdi, &last_written))
cd->capacity = max_t(long, cd->capacity, last_written);
sector_size = (buffer[4] << 24) |
(buffer[5] << 16) | (buffer[6] << 8) | buffer[7];
switch (sector_size) {
case 0:
case 2340:
case 2352:
sector_size = 2048;
case 2048:
cd->capacity *= 4;
case 512:
break;
default:
printk("%s: unsupported sector size %d.\n",
cd->cdi.name, sector_size);
cd->capacity = 0;
}
cd->device->sector_size = sector_size;
set_capacity(cd->disk, cd->capacity);
}
queue = cd->device->request_queue;
blk_queue_logical_block_size(queue, sector_size);
return;
}
static void get_capabilities(struct scsi_cd *cd)
{
unsigned char *buffer;
struct scsi_mode_data data;
struct scsi_sense_hdr sshdr;
int rc, n;
static const char *loadmech[] =
{
"caddy",
"tray",
"pop-up",
"",
"changer",
"cartridge changer",
"",
""
};
buffer = kmalloc(512, GFP_KERNEL | GFP_DMA);
if (!buffer) {
printk(KERN_ERR "sr: out of memory.\n");
return;
}
scsi_test_unit_ready(cd->device, SR_TIMEOUT, MAX_RETRIES, &sshdr);
rc = scsi_mode_sense(cd->device, 0, 0x2a, buffer, 128,
SR_TIMEOUT, 3, &data, NULL);
if (!scsi_status_is_good(rc)) {
cd->cdi.speed = 1;
cd->cdi.mask |= (CDC_CD_R | CDC_CD_RW | CDC_DVD_R |
CDC_DVD | CDC_DVD_RAM |
CDC_SELECT_DISC | CDC_SELECT_SPEED |
CDC_MRW | CDC_MRW_W | CDC_RAM);
kfree(buffer);
printk("%s: scsi-1 drive\n", cd->cdi.name);
return;
}
n = data.header_length + data.block_descriptor_length;
cd->cdi.speed = ((buffer[n + 8] << 8) + buffer[n + 9]) / 176;
cd->readcd_known = 1;
cd->readcd_cdda = buffer[n + 5] & 0x01;
printk("%s: scsi3-mmc drive: %dx/%dx %s%s%s%s%s%s\n", cd->cdi.name,
((buffer[n + 14] << 8) + buffer[n + 15]) / 176,
cd->cdi.speed,
buffer[n + 3] & 0x01 ? "writer " : "",
buffer[n + 3] & 0x20 ? "dvd-ram " : "",
buffer[n + 2] & 0x02 ? "cd/rw " : "",
buffer[n + 4] & 0x20 ? "xa/form2 " : "",
buffer[n + 5] & 0x01 ? "cdda " : "",
loadmech[buffer[n + 6] >> 5]);
if ((buffer[n + 6] >> 5) == 0)
cd->cdi.mask |= CDC_CLOSE_TRAY;
if ((buffer[n + 2] & 0x8) == 0)
cd->cdi.mask |= CDC_DVD;
if ((buffer[n + 3] & 0x20) == 0)
cd->cdi.mask |= CDC_DVD_RAM;
if ((buffer[n + 3] & 0x10) == 0)
cd->cdi.mask |= CDC_DVD_R;
if ((buffer[n + 3] & 0x2) == 0)
cd->cdi.mask |= CDC_CD_RW;
if ((buffer[n + 3] & 0x1) == 0)
cd->cdi.mask |= CDC_CD_R;
if ((buffer[n + 6] & 0x8) == 0)
cd->cdi.mask |= CDC_OPEN_TRAY;
if ((buffer[n + 6] >> 5) == mechtype_individual_changer ||
(buffer[n + 6] >> 5) == mechtype_cartridge_changer)
cd->cdi.capacity =
cdrom_number_of_slots(&cd->cdi);
if (cd->cdi.capacity <= 1)
cd->cdi.mask |= CDC_SELECT_DISC;
if ((cd->cdi.mask & (CDC_DVD_RAM | CDC_MRW_W | CDC_RAM | CDC_CD_RW)) !=
(CDC_DVD_RAM | CDC_MRW_W | CDC_RAM | CDC_CD_RW)) {
cd->device->writeable = 1;
}
kfree(buffer);
}
static int sr_packet(struct cdrom_device_info *cdi,
struct packet_command *cgc)
{
struct scsi_cd *cd = cdi->handle;
struct scsi_device *sdev = cd->device;
if (cgc->cmd[0] == GPCMD_READ_DISC_INFO && sdev->no_read_disc_info)
return -EDRIVE_CANT_DO_THIS;
if (cgc->timeout <= 0)
cgc->timeout = IOCTL_TIMEOUT;
sr_do_ioctl(cd, cgc);
return cgc->stat;
}
static void sr_kref_release(struct kref *kref)
{
struct scsi_cd *cd = container_of(kref, struct scsi_cd, kref);
struct gendisk *disk = cd->disk;
spin_lock(&sr_index_lock);
clear_bit(MINOR(disk_devt(disk)), sr_index_bits);
spin_unlock(&sr_index_lock);
unregister_cdrom(&cd->cdi);
disk->private_data = NULL;
put_disk(disk);
kfree(cd);
}
static int sr_remove(struct device *dev)
{
struct scsi_cd *cd = dev_get_drvdata(dev);
blk_queue_prep_rq(cd->device->request_queue, scsi_prep_fn);
del_gendisk(cd->disk);
mutex_lock(&sr_ref_mutex);
kref_put(&cd->kref, sr_kref_release);
mutex_unlock(&sr_ref_mutex);
return 0;
}
static int __init init_sr(void)
{
int rc;
rc = register_blkdev(SCSI_CDROM_MAJOR, "sr");
if (rc)
return rc;
rc = scsi_register_driver(&sr_template.gendrv);
if (rc)
unregister_blkdev(SCSI_CDROM_MAJOR, "sr");
return rc;
}
static void __exit exit_sr(void)
{
scsi_unregister_driver(&sr_template.gendrv);
unregister_blkdev(SCSI_CDROM_MAJOR, "sr");
}
