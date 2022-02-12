static inline void set_swim_mode(struct swim __iomem *base, int enable)
{
struct iwm __iomem *iwm_base;
unsigned long flags;
if (!enable) {
swim_write(base, mode0, 0xf8);
return;
}
iwm_base = (struct iwm __iomem *)base;
local_irq_save(flags);
iwm_read(iwm_base, q7L);
iwm_read(iwm_base, mtrOff);
iwm_read(iwm_base, q6H);
iwm_write(iwm_base, q7H, 0x57);
iwm_write(iwm_base, q7H, 0x17);
iwm_write(iwm_base, q7H, 0x57);
iwm_write(iwm_base, q7H, 0x57);
local_irq_restore(flags);
}
static inline int get_swim_mode(struct swim __iomem *base)
{
unsigned long flags;
local_irq_save(flags);
swim_write(base, phase, 0xf5);
if (swim_read(base, phase) != 0xf5)
goto is_iwm;
swim_write(base, phase, 0xf6);
if (swim_read(base, phase) != 0xf6)
goto is_iwm;
swim_write(base, phase, 0xf7);
if (swim_read(base, phase) != 0xf7)
goto is_iwm;
local_irq_restore(flags);
return 1;
is_iwm:
local_irq_restore(flags);
return 0;
}
static inline void swim_select(struct swim __iomem *base, int sel)
{
swim_write(base, phase, RELAX);
via1_set_head(sel & 0x100);
swim_write(base, phase, sel & CA_MASK);
}
static inline void swim_action(struct swim __iomem *base, int action)
{
unsigned long flags;
local_irq_save(flags);
swim_select(base, action);
udelay(1);
swim_write(base, phase, (LSTRB<<4) | LSTRB);
udelay(1);
swim_write(base, phase, (LSTRB<<4) | ((~LSTRB) & 0x0F));
udelay(1);
local_irq_restore(flags);
}
static inline int swim_readbit(struct swim __iomem *base, int bit)
{
int stat;
swim_select(base, bit);
udelay(10);
stat = swim_read(base, handshake);
return (stat & SENSE) == 0;
}
static inline void swim_drive(struct swim __iomem *base,
enum drive_location location)
{
if (location == INTERNAL_DRIVE) {
swim_write(base, mode0, EXTERNAL_DRIVE);
swim_write(base, mode1, INTERNAL_DRIVE);
} else if (location == EXTERNAL_DRIVE) {
swim_write(base, mode0, INTERNAL_DRIVE);
swim_write(base, mode1, EXTERNAL_DRIVE);
}
}
static inline void swim_motor(struct swim __iomem *base,
enum motor_action action)
{
if (action == ON) {
int i;
swim_action(base, MOTOR_ON);
for (i = 0; i < 2*HZ; i++) {
swim_select(base, RELAX);
if (swim_readbit(base, MOTOR_ON))
break;
current->state = TASK_INTERRUPTIBLE;
schedule_timeout(1);
}
} else if (action == OFF) {
swim_action(base, MOTOR_OFF);
swim_select(base, RELAX);
}
}
static inline void swim_eject(struct swim __iomem *base)
{
int i;
swim_action(base, EJECT);
for (i = 0; i < 2*HZ; i++) {
swim_select(base, RELAX);
if (!swim_readbit(base, DISK_IN))
break;
current->state = TASK_INTERRUPTIBLE;
schedule_timeout(1);
}
swim_select(base, RELAX);
}
static inline void swim_head(struct swim __iomem *base, enum head head)
{
if (head == UPPER_HEAD)
swim_select(base, READ_DATA_1);
else if (head == LOWER_HEAD)
swim_select(base, READ_DATA_0);
}
static inline int swim_step(struct swim __iomem *base)
{
int wait;
swim_action(base, STEP);
for (wait = 0; wait < HZ; wait++) {
current->state = TASK_INTERRUPTIBLE;
schedule_timeout(1);
swim_select(base, RELAX);
if (!swim_readbit(base, STEP))
return 0;
}
return -1;
}
static inline int swim_track00(struct swim __iomem *base)
{
int try;
swim_action(base, SEEK_NEGATIVE);
for (try = 0; try < 100; try++) {
swim_select(base, RELAX);
if (swim_readbit(base, TRACK_ZERO))
break;
if (swim_step(base))
return -1;
}
if (swim_readbit(base, TRACK_ZERO))
return 0;
return -1;
}
static inline int swim_seek(struct swim __iomem *base, int step)
{
if (step == 0)
return 0;
if (step < 0) {
swim_action(base, SEEK_NEGATIVE);
step = -step;
} else
swim_action(base, SEEK_POSITIVE);
for ( ; step > 0; step--) {
if (swim_step(base))
return -1;
}
return 0;
}
static inline int swim_track(struct floppy_state *fs, int track)
{
struct swim __iomem *base = fs->swd->base;
int ret;
ret = swim_seek(base, track - fs->track);
if (ret == 0)
fs->track = track;
else {
swim_track00(base);
fs->track = 0;
}
return ret;
}
static int floppy_eject(struct floppy_state *fs)
{
struct swim __iomem *base = fs->swd->base;
swim_drive(base, fs->location);
swim_motor(base, OFF);
swim_eject(base);
fs->disk_in = 0;
fs->ejected = 1;
return 0;
}
static inline int swim_read_sector(struct floppy_state *fs,
int side, int track,
int sector, unsigned char *buffer)
{
struct swim __iomem *base = fs->swd->base;
unsigned long flags;
struct sector_header header;
int ret = -1;
short i;
swim_track(fs, track);
swim_write(base, mode1, MOTON);
swim_head(base, side);
swim_write(base, mode0, side);
local_irq_save(flags);
for (i = 0; i < 36; i++) {
ret = swim_read_sector_header(base, &header);
if (!ret && (header.sector == sector)) {
ret = swim_read_sector_data(base, buffer);
break;
}
}
local_irq_restore(flags);
swim_write(base, mode0, MOTON);
if ((header.side != side) || (header.track != track) ||
(header.sector != sector))
return 0;
return ret;
}
static int floppy_read_sectors(struct floppy_state *fs,
int req_sector, int sectors_nb,
unsigned char *buffer)
{
struct swim __iomem *base = fs->swd->base;
int ret;
int side, track, sector;
int i, try;
swim_drive(base, fs->location);
for (i = req_sector; i < req_sector + sectors_nb; i++) {
int x;
track = i / fs->secpercyl;
x = i % fs->secpercyl;
side = x / fs->secpertrack;
sector = x % fs->secpertrack + 1;
try = 5;
do {
ret = swim_read_sector(fs, side, track, sector,
buffer);
if (try-- == 0)
return -EIO;
} while (ret != 512);
buffer += ret;
}
return 0;
}
static void redo_fd_request(struct request_queue *q)
{
struct request *req;
struct floppy_state *fs;
req = blk_fetch_request(q);
while (req) {
int err = -EIO;
fs = req->rq_disk->private_data;
if (blk_rq_pos(req) >= fs->total_secs)
goto done;
if (!fs->disk_in)
goto done;
if (rq_data_dir(req) == WRITE && fs->write_protected)
goto done;
switch (rq_data_dir(req)) {
case WRITE:
break;
case READ:
err = floppy_read_sectors(fs, blk_rq_pos(req),
blk_rq_cur_sectors(req),
req->buffer);
break;
}
done:
if (!__blk_end_request_cur(req, err))
req = blk_fetch_request(q);
}
}
static void do_fd_request(struct request_queue *q)
{
redo_fd_request(q);
}
static int get_floppy_geometry(struct floppy_state *fs, int type,
struct floppy_struct **g)
{
if (type >= ARRAY_SIZE(floppy_type))
return -EINVAL;
if (type)
*g = &floppy_type[type];
else if (fs->type == HD_MEDIA)
*g = &floppy_type[3];
else if (fs->head_number == 2)
*g = &floppy_type[2];
else
*g = &floppy_type[1];
return 0;
}
static void setup_medium(struct floppy_state *fs)
{
struct swim __iomem *base = fs->swd->base;
if (swim_readbit(base, DISK_IN)) {
struct floppy_struct *g;
fs->disk_in = 1;
fs->write_protected = swim_readbit(base, WRITE_PROT);
fs->type = swim_readbit(base, ONEMEG_MEDIA);
if (swim_track00(base))
printk(KERN_ERR
"SWIM: cannot move floppy head to track 0\n");
swim_track00(base);
get_floppy_geometry(fs, 0, &g);
fs->total_secs = g->size;
fs->secpercyl = g->head * g->sect;
fs->secpertrack = g->sect;
fs->track = 0;
} else {
fs->disk_in = 0;
}
}
static int floppy_open(struct block_device *bdev, fmode_t mode)
{
struct floppy_state *fs = bdev->bd_disk->private_data;
struct swim __iomem *base = fs->swd->base;
int err;
if (fs->ref_count == -1 || (fs->ref_count && mode & FMODE_EXCL))
return -EBUSY;
if (mode & FMODE_EXCL)
fs->ref_count = -1;
else
fs->ref_count++;
swim_write(base, setup, S_IBM_DRIVE | S_FCLK_DIV2);
udelay(10);
swim_drive(base, INTERNAL_DRIVE);
swim_motor(base, ON);
swim_action(base, SETMFM);
if (fs->ejected)
setup_medium(fs);
if (!fs->disk_in) {
err = -ENXIO;
goto out;
}
if (mode & FMODE_NDELAY)
return 0;
if (mode & (FMODE_READ|FMODE_WRITE)) {
check_disk_change(bdev);
if ((mode & FMODE_WRITE) && fs->write_protected) {
err = -EROFS;
goto out;
}
}
return 0;
out:
if (fs->ref_count < 0)
fs->ref_count = 0;
else if (fs->ref_count > 0)
--fs->ref_count;
if (fs->ref_count == 0)
swim_motor(base, OFF);
return err;
}
static int floppy_unlocked_open(struct block_device *bdev, fmode_t mode)
{
int ret;
mutex_lock(&swim_mutex);
ret = floppy_open(bdev, mode);
mutex_unlock(&swim_mutex);
return ret;
}
static int floppy_release(struct gendisk *disk, fmode_t mode)
{
struct floppy_state *fs = disk->private_data;
struct swim __iomem *base = fs->swd->base;
mutex_lock(&swim_mutex);
if (fs->ref_count < 0)
fs->ref_count = 0;
else if (fs->ref_count > 0)
--fs->ref_count;
if (fs->ref_count == 0)
swim_motor(base, OFF);
mutex_unlock(&swim_mutex);
return 0;
}
static int floppy_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long param)
{
struct floppy_state *fs = bdev->bd_disk->private_data;
int err;
if ((cmd & 0x80) && !capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd) {
case FDEJECT:
if (fs->ref_count != 1)
return -EBUSY;
mutex_lock(&swim_mutex);
err = floppy_eject(fs);
mutex_unlock(&swim_mutex);
return err;
case FDGETPRM:
if (copy_to_user((void __user *) param, (void *) &floppy_type,
sizeof(struct floppy_struct)))
return -EFAULT;
break;
default:
printk(KERN_DEBUG "SWIM floppy_ioctl: unknown cmd %d\n",
cmd);
return -ENOSYS;
}
return 0;
}
static int floppy_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct floppy_state *fs = bdev->bd_disk->private_data;
struct floppy_struct *g;
int ret;
ret = get_floppy_geometry(fs, 0, &g);
if (ret)
return ret;
geo->heads = g->head;
geo->sectors = g->sect;
geo->cylinders = g->track;
return 0;
}
static unsigned int floppy_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct floppy_state *fs = disk->private_data;
return fs->ejected ? DISK_EVENT_MEDIA_CHANGE : 0;
}
static int floppy_revalidate(struct gendisk *disk)
{
struct floppy_state *fs = disk->private_data;
struct swim __iomem *base = fs->swd->base;
swim_drive(base, fs->location);
if (fs->ejected)
setup_medium(fs);
if (!fs->disk_in)
swim_motor(base, OFF);
else
fs->ejected = 0;
return !fs->disk_in;
}
static struct kobject *floppy_find(dev_t dev, int *part, void *data)
{
struct swim_priv *swd = data;
int drive = (*part & 3);
if (drive > swd->floppy_count)
return NULL;
*part = 0;
return get_disk(swd->unit[drive].disk);
}
static int swim_add_floppy(struct swim_priv *swd, enum drive_location location)
{
struct floppy_state *fs = &swd->unit[swd->floppy_count];
struct swim __iomem *base = swd->base;
fs->location = location;
swim_drive(base, location);
swim_motor(base, OFF);
if (swim_readbit(base, SINGLE_SIDED))
fs->head_number = 1;
else
fs->head_number = 2;
fs->ref_count = 0;
fs->ejected = 1;
swd->floppy_count++;
return 0;
}
static int swim_floppy_init(struct swim_priv *swd)
{
int err;
int drive;
struct swim __iomem *base = swd->base;
swim_drive(base, INTERNAL_DRIVE);
if (swim_readbit(base, DRIVE_PRESENT))
swim_add_floppy(swd, INTERNAL_DRIVE);
swim_drive(base, EXTERNAL_DRIVE);
if (swim_readbit(base, DRIVE_PRESENT))
swim_add_floppy(swd, EXTERNAL_DRIVE);
err = register_blkdev(FLOPPY_MAJOR, "fd");
if (err) {
printk(KERN_ERR "Unable to get major %d for SWIM floppy\n",
FLOPPY_MAJOR);
return -EBUSY;
}
for (drive = 0; drive < swd->floppy_count; drive++) {
swd->unit[drive].disk = alloc_disk(1);
if (swd->unit[drive].disk == NULL) {
err = -ENOMEM;
goto exit_put_disks;
}
swd->unit[drive].swd = swd;
}
spin_lock_init(&swd->lock);
swd->queue = blk_init_queue(do_fd_request, &swd->lock);
if (!swd->queue) {
err = -ENOMEM;
goto exit_put_disks;
}
for (drive = 0; drive < swd->floppy_count; drive++) {
swd->unit[drive].disk->flags = GENHD_FL_REMOVABLE;
swd->unit[drive].disk->major = FLOPPY_MAJOR;
swd->unit[drive].disk->first_minor = drive;
sprintf(swd->unit[drive].disk->disk_name, "fd%d", drive);
swd->unit[drive].disk->fops = &floppy_fops;
swd->unit[drive].disk->private_data = &swd->unit[drive];
swd->unit[drive].disk->queue = swd->queue;
set_capacity(swd->unit[drive].disk, 2880);
add_disk(swd->unit[drive].disk);
}
blk_register_region(MKDEV(FLOPPY_MAJOR, 0), 256, THIS_MODULE,
floppy_find, NULL, swd);
return 0;
exit_put_disks:
unregister_blkdev(FLOPPY_MAJOR, "fd");
while (drive--)
put_disk(swd->unit[drive].disk);
return err;
}
static int swim_probe(struct platform_device *dev)
{
struct resource *res;
struct swim __iomem *swim_base;
struct swim_priv *swd;
int ret;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto out;
}
if (!request_mem_region(res->start, resource_size(res), CARDNAME)) {
ret = -EBUSY;
goto out;
}
swim_base = ioremap(res->start, resource_size(res));
if (!swim_base) {
return -ENOMEM;
goto out_release_io;
}
set_swim_mode(swim_base, 1);
if (!get_swim_mode(swim_base)) {
printk(KERN_INFO "SWIM device not found !\n");
ret = -ENODEV;
goto out_iounmap;
}
swd = kzalloc(sizeof(struct swim_priv), GFP_KERNEL);
if (!swd) {
ret = -ENOMEM;
goto out_iounmap;
}
platform_set_drvdata(dev, swd);
swd->base = swim_base;
ret = swim_floppy_init(swd);
if (ret)
goto out_kfree;
return 0;
out_kfree:
platform_set_drvdata(dev, NULL);
kfree(swd);
out_iounmap:
iounmap(swim_base);
out_release_io:
release_mem_region(res->start, resource_size(res));
out:
return ret;
}
static int swim_remove(struct platform_device *dev)
{
struct swim_priv *swd = platform_get_drvdata(dev);
int drive;
struct resource *res;
blk_unregister_region(MKDEV(FLOPPY_MAJOR, 0), 256);
for (drive = 0; drive < swd->floppy_count; drive++) {
del_gendisk(swd->unit[drive].disk);
put_disk(swd->unit[drive].disk);
}
unregister_blkdev(FLOPPY_MAJOR, "fd");
blk_cleanup_queue(swd->queue);
for (drive = 0; drive < swd->floppy_count; drive++)
floppy_eject(&swd->unit[drive]);
iounmap(swd->base);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(dev, NULL);
kfree(swd);
return 0;
}
static int __init swim_init(void)
{
printk(KERN_INFO "SWIM floppy driver %s\n", DRIVER_VERSION);
return platform_driver_register(&swim_driver);
}
static void __exit swim_exit(void)
{
platform_driver_unregister(&swim_driver);
}
