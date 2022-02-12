int ide_disk_ioctl(ide_drive_t *drive, struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int err;
mutex_lock(&ide_disk_ioctl_mutex);
err = ide_setting_ioctl(drive, bdev, cmd, arg, ide_disk_ioctl_settings);
if (err != -EOPNOTSUPP)
goto out;
err = generic_ide_ioctl(drive, bdev, cmd, arg);
out:
mutex_unlock(&ide_disk_ioctl_mutex);
return err;
}
