static struct ide_disk_obj *ide_disk_get(struct gendisk *disk)
{
struct ide_disk_obj *idkp = NULL;
mutex_lock(&ide_disk_ref_mutex);
idkp = ide_drv_g(disk, ide_disk_obj);
if (idkp) {
if (ide_device_get(idkp->drive))
idkp = NULL;
else
get_device(&idkp->dev);
}
mutex_unlock(&ide_disk_ref_mutex);
return idkp;
}
static void ide_disk_put(struct ide_disk_obj *idkp)
{
ide_drive_t *drive = idkp->drive;
mutex_lock(&ide_disk_ref_mutex);
put_device(&idkp->dev);
ide_device_put(drive);
mutex_unlock(&ide_disk_ref_mutex);
}
sector_t ide_gd_capacity(ide_drive_t *drive)
{
return drive->capacity64;
}
static void ide_gd_remove(ide_drive_t *drive)
{
struct ide_disk_obj *idkp = drive->driver_data;
struct gendisk *g = idkp->disk;
ide_proc_unregister_driver(drive, idkp->driver);
device_del(&idkp->dev);
del_gendisk(g);
drive->disk_ops->flush(drive);
mutex_lock(&ide_disk_ref_mutex);
put_device(&idkp->dev);
mutex_unlock(&ide_disk_ref_mutex);
}
static void ide_disk_release(struct device *dev)
{
struct ide_disk_obj *idkp = to_ide_drv(dev, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
struct gendisk *g = idkp->disk;
drive->disk_ops = NULL;
drive->driver_data = NULL;
g->private_data = NULL;
put_disk(g);
kfree(idkp);
}
static void ide_gd_resume(ide_drive_t *drive)
{
if (ata_id_hpa_enabled(drive->id))
(void)drive->disk_ops->get_capacity(drive);
}
static ide_proc_entry_t *ide_disk_proc_entries(ide_drive_t *drive)
{
return (drive->media == ide_disk) ? ide_disk_proc : ide_floppy_proc;
}
static const struct ide_proc_devset *ide_disk_proc_devsets(ide_drive_t *drive)
{
return (drive->media == ide_disk) ? ide_disk_settings
: ide_floppy_settings;
}
static ide_startstop_t ide_gd_do_request(ide_drive_t *drive,
struct request *rq, sector_t sector)
{
return drive->disk_ops->do_request(drive, rq, sector);
}
static int ide_gd_open(struct block_device *bdev, fmode_t mode)
{
struct gendisk *disk = bdev->bd_disk;
struct ide_disk_obj *idkp;
ide_drive_t *drive;
int ret = 0;
idkp = ide_disk_get(disk);
if (idkp == NULL)
return -ENXIO;
drive = idkp->drive;
ide_debug_log(IDE_DBG_FUNC, "enter");
idkp->openers++;
if ((drive->dev_flags & IDE_DFLAG_REMOVABLE) && idkp->openers == 1) {
drive->dev_flags &= ~IDE_DFLAG_FORMAT_IN_PROGRESS;
ret = drive->disk_ops->init_media(drive, disk);
if (ret && (mode & FMODE_NDELAY) == 0) {
ret = -EIO;
goto out_put_idkp;
}
if ((drive->dev_flags & IDE_DFLAG_WP) && (mode & FMODE_WRITE)) {
ret = -EROFS;
goto out_put_idkp;
}
drive->disk_ops->set_doorlock(drive, disk, 1);
drive->dev_flags |= IDE_DFLAG_MEDIA_CHANGED;
check_disk_change(bdev);
} else if (drive->dev_flags & IDE_DFLAG_FORMAT_IN_PROGRESS) {
ret = -EBUSY;
goto out_put_idkp;
}
return 0;
out_put_idkp:
idkp->openers--;
ide_disk_put(idkp);
return ret;
}
static int ide_gd_unlocked_open(struct block_device *bdev, fmode_t mode)
{
int ret;
mutex_lock(&ide_gd_mutex);
ret = ide_gd_open(bdev, mode);
mutex_unlock(&ide_gd_mutex);
return ret;
}
static void ide_gd_release(struct gendisk *disk, fmode_t mode)
{
struct ide_disk_obj *idkp = ide_drv_g(disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
ide_debug_log(IDE_DBG_FUNC, "enter");
mutex_lock(&ide_gd_mutex);
if (idkp->openers == 1)
drive->disk_ops->flush(drive);
if ((drive->dev_flags & IDE_DFLAG_REMOVABLE) && idkp->openers == 1) {
drive->disk_ops->set_doorlock(drive, disk, 0);
drive->dev_flags &= ~IDE_DFLAG_FORMAT_IN_PROGRESS;
}
idkp->openers--;
ide_disk_put(idkp);
mutex_unlock(&ide_gd_mutex);
}
static int ide_gd_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct ide_disk_obj *idkp = ide_drv_g(bdev->bd_disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
geo->heads = drive->bios_head;
geo->sectors = drive->bios_sect;
geo->cylinders = (u16)drive->bios_cyl;
return 0;
}
static unsigned int ide_gd_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct ide_disk_obj *idkp = ide_drv_g(disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
bool ret;
if (drive->dev_flags & IDE_DFLAG_ATTACH) {
drive->dev_flags &= ~IDE_DFLAG_ATTACH;
return 0;
}
ret = drive->dev_flags & IDE_DFLAG_MEDIA_CHANGED;
drive->dev_flags &= ~IDE_DFLAG_MEDIA_CHANGED;
return ret ? DISK_EVENT_MEDIA_CHANGE : 0;
}
static void ide_gd_unlock_native_capacity(struct gendisk *disk)
{
struct ide_disk_obj *idkp = ide_drv_g(disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
const struct ide_disk_ops *disk_ops = drive->disk_ops;
if (disk_ops->unlock_native_capacity)
disk_ops->unlock_native_capacity(drive);
}
static int ide_gd_revalidate_disk(struct gendisk *disk)
{
struct ide_disk_obj *idkp = ide_drv_g(disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
if (ide_gd_check_events(disk, 0))
drive->disk_ops->get_capacity(drive);
set_capacity(disk, ide_gd_capacity(drive));
return 0;
}
static int ide_gd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct ide_disk_obj *idkp = ide_drv_g(bdev->bd_disk, ide_disk_obj);
ide_drive_t *drive = idkp->drive;
return drive->disk_ops->ioctl(drive, bdev, mode, cmd, arg);
}
static int ide_gd_probe(ide_drive_t *drive)
{
const struct ide_disk_ops *disk_ops = NULL;
struct ide_disk_obj *idkp;
struct gendisk *g;
if (!strstr("ide-gd", drive->driver_req))
goto failed;
#ifdef CONFIG_IDE_GD_ATA
if (drive->media == ide_disk)
disk_ops = &ide_ata_disk_ops;
#endif
#ifdef CONFIG_IDE_GD_ATAPI
if (drive->media == ide_floppy)
disk_ops = &ide_atapi_disk_ops;
#endif
if (disk_ops == NULL)
goto failed;
if (disk_ops->check(drive, DRV_NAME) == 0) {
printk(KERN_ERR PFX "%s: not supported by this driver\n",
drive->name);
goto failed;
}
idkp = kzalloc(sizeof(*idkp), GFP_KERNEL);
if (!idkp) {
printk(KERN_ERR PFX "%s: can't allocate a disk structure\n",
drive->name);
goto failed;
}
g = alloc_disk_node(IDE_DISK_MINORS, hwif_to_node(drive->hwif));
if (!g)
goto out_free_idkp;
ide_init_disk(g, drive);
idkp->dev.parent = &drive->gendev;
idkp->dev.release = ide_disk_release;
dev_set_name(&idkp->dev, "%s", dev_name(&drive->gendev));
if (device_register(&idkp->dev))
goto out_free_disk;
idkp->drive = drive;
idkp->driver = &ide_gd_driver;
idkp->disk = g;
g->private_data = &idkp->driver;
drive->driver_data = idkp;
drive->debug_mask = debug_mask;
drive->disk_ops = disk_ops;
disk_ops->setup(drive);
set_capacity(g, ide_gd_capacity(drive));
g->minors = IDE_DISK_MINORS;
g->flags |= GENHD_FL_EXT_DEVT;
if (drive->dev_flags & IDE_DFLAG_REMOVABLE)
g->flags = GENHD_FL_REMOVABLE;
g->fops = &ide_gd_ops;
device_add_disk(&drive->gendev, g);
return 0;
out_free_disk:
put_disk(g);
out_free_idkp:
kfree(idkp);
failed:
return -ENODEV;
}
static int __init ide_gd_init(void)
{
printk(KERN_INFO DRV_NAME " driver " IDE_GD_VERSION "\n");
return driver_register(&ide_gd_driver.gen_driver);
}
static void __exit ide_gd_exit(void)
{
driver_unregister(&ide_gd_driver.gen_driver);
}
