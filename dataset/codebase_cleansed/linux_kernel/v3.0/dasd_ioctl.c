static int
dasd_ioctl_api_version(void __user *argp)
{
int ver = DASD_API_VERSION;
return put_user(ver, (int __user *)argp);
}
static int
dasd_ioctl_enable(struct block_device *bdev)
{
struct dasd_device *base;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
base = dasd_device_from_gendisk(bdev->bd_disk);
if (!base)
return -ENODEV;
dasd_enable_device(base);
mutex_lock(&bdev->bd_mutex);
i_size_write(bdev->bd_inode,
(loff_t)get_capacity(base->block->gdp) << 9);
mutex_unlock(&bdev->bd_mutex);
dasd_put_device(base);
return 0;
}
static int
dasd_ioctl_disable(struct block_device *bdev)
{
struct dasd_device *base;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
base = dasd_device_from_gendisk(bdev->bd_disk);
if (!base)
return -ENODEV;
dasd_set_target_state(base, DASD_STATE_BASIC);
mutex_lock(&bdev->bd_mutex);
i_size_write(bdev->bd_inode, 0);
mutex_unlock(&bdev->bd_mutex);
dasd_put_device(base);
return 0;
}
static int dasd_ioctl_quiesce(struct dasd_block *block)
{
unsigned long flags;
struct dasd_device *base;
base = block->base;
if (!capable (CAP_SYS_ADMIN))
return -EACCES;
pr_info("%s: The DASD has been put in the quiesce "
"state\n", dev_name(&base->cdev->dev));
spin_lock_irqsave(get_ccwdev_lock(base->cdev), flags);
dasd_device_set_stop_bits(base, DASD_STOPPED_QUIESCE);
spin_unlock_irqrestore(get_ccwdev_lock(base->cdev), flags);
return 0;
}
static int dasd_ioctl_resume(struct dasd_block *block)
{
unsigned long flags;
struct dasd_device *base;
base = block->base;
if (!capable (CAP_SYS_ADMIN))
return -EACCES;
pr_info("%s: I/O operations have been resumed "
"on the DASD\n", dev_name(&base->cdev->dev));
spin_lock_irqsave(get_ccwdev_lock(base->cdev), flags);
dasd_device_remove_stop_bits(base, DASD_STOPPED_QUIESCE);
spin_unlock_irqrestore(get_ccwdev_lock(base->cdev), flags);
dasd_schedule_block_bh(block);
return 0;
}
static int dasd_format(struct dasd_block *block, struct format_data_t *fdata)
{
struct dasd_ccw_req *cqr;
struct dasd_device *base;
int rc;
base = block->base;
if (base->discipline->format_device == NULL)
return -EPERM;
if (base->state != DASD_STATE_BASIC) {
pr_warning("%s: The DASD cannot be formatted while it is "
"enabled\n", dev_name(&base->cdev->dev));
return -EBUSY;
}
DBF_DEV_EVENT(DBF_NOTICE, base,
"formatting units %u to %u (%u B blocks) flags %u",
fdata->start_unit,
fdata->stop_unit, fdata->blksize, fdata->intensity);
if (fdata->start_unit == 0) {
struct block_device *bdev = bdget_disk(block->gdp, 0);
bdev->bd_inode->i_blkbits = blksize_bits(fdata->blksize);
bdput(bdev);
}
while (fdata->start_unit <= fdata->stop_unit) {
cqr = base->discipline->format_device(base, fdata);
if (IS_ERR(cqr))
return PTR_ERR(cqr);
rc = dasd_sleep_on_interruptible(cqr);
dasd_sfree_request(cqr, cqr->memdev);
if (rc) {
if (rc != -ERESTARTSYS)
pr_err("%s: Formatting unit %d failed with "
"rc=%d\n", dev_name(&base->cdev->dev),
fdata->start_unit, rc);
return rc;
}
fdata->start_unit++;
}
return 0;
}
static int
dasd_ioctl_format(struct block_device *bdev, void __user *argp)
{
struct dasd_device *base;
struct format_data_t fdata;
int rc;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!argp)
return -EINVAL;
base = dasd_device_from_gendisk(bdev->bd_disk);
if (!base)
return -ENODEV;
if (base->features & DASD_FEATURE_READONLY ||
test_bit(DASD_FLAG_DEVICE_RO, &base->flags)) {
dasd_put_device(base);
return -EROFS;
}
if (copy_from_user(&fdata, argp, sizeof(struct format_data_t))) {
dasd_put_device(base);
return -EFAULT;
}
if (bdev != bdev->bd_contains) {
pr_warning("%s: The specified DASD is a partition and cannot "
"be formatted\n",
dev_name(&base->cdev->dev));
dasd_put_device(base);
return -EINVAL;
}
rc = dasd_format(base->block, &fdata);
dasd_put_device(base);
return rc;
}
static int dasd_ioctl_reset_profile(struct dasd_block *block)
{
memset(&block->profile, 0, sizeof(struct dasd_profile_info_t));
return 0;
}
static int dasd_ioctl_read_profile(struct dasd_block *block, void __user *argp)
{
if (dasd_profile_level == DASD_PROFILE_OFF)
return -EIO;
if (copy_to_user(argp, &block->profile,
sizeof(struct dasd_profile_info_t)))
return -EFAULT;
return 0;
}
static int dasd_ioctl_reset_profile(struct dasd_block *block)
{
return -ENOSYS;
}
static int dasd_ioctl_read_profile(struct dasd_block *block, void __user *argp)
{
return -ENOSYS;
}
static int dasd_ioctl_information(struct dasd_block *block,
unsigned int cmd, void __user *argp)
{
struct dasd_information2_t *dasd_info;
unsigned long flags;
int rc;
struct dasd_device *base;
struct ccw_device *cdev;
struct ccw_dev_id dev_id;
base = block->base;
if (!base->discipline || !base->discipline->fill_info)
return -EINVAL;
dasd_info = kzalloc(sizeof(struct dasd_information2_t), GFP_KERNEL);
if (dasd_info == NULL)
return -ENOMEM;
rc = base->discipline->fill_info(base, dasd_info);
if (rc) {
kfree(dasd_info);
return rc;
}
cdev = base->cdev;
ccw_device_get_id(cdev, &dev_id);
dasd_info->devno = dev_id.devno;
dasd_info->schid = _ccw_device_get_subchannel_number(base->cdev);
dasd_info->cu_type = cdev->id.cu_type;
dasd_info->cu_model = cdev->id.cu_model;
dasd_info->dev_type = cdev->id.dev_type;
dasd_info->dev_model = cdev->id.dev_model;
dasd_info->status = base->state;
dasd_info->open_count = atomic_read(&block->open_count);
if (!block->bdev)
dasd_info->open_count++;
if ((base->state < DASD_STATE_READY) ||
(dasd_check_blocksize(block->bp_block)))
dasd_info->format = DASD_FORMAT_NONE;
dasd_info->features |=
((base->features & DASD_FEATURE_READONLY) != 0);
memcpy(dasd_info->type, base->discipline->name, 4);
if (block->request_queue->request_fn) {
struct list_head *l;
#ifdef DASD_EXTENDED_PROFILING
{
struct list_head *l;
spin_lock_irqsave(&block->lock, flags);
list_for_each(l, &block->request_queue->queue_head)
dasd_info->req_queue_len++;
spin_unlock_irqrestore(&block->lock, flags);
}
#endif
spin_lock_irqsave(get_ccwdev_lock(base->cdev), flags);
list_for_each(l, &base->ccw_queue)
dasd_info->chanq_len++;
spin_unlock_irqrestore(get_ccwdev_lock(base->cdev),
flags);
}
rc = 0;
if (copy_to_user(argp, dasd_info,
((cmd == (unsigned int) BIODASDINFO2) ?
sizeof(struct dasd_information2_t) :
sizeof(struct dasd_information_t))))
rc = -EFAULT;
kfree(dasd_info);
return rc;
}
static int
dasd_ioctl_set_ro(struct block_device *bdev, void __user *argp)
{
struct dasd_device *base;
int intval, rc;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (bdev != bdev->bd_contains)
return -EINVAL;
if (get_user(intval, (int __user *)argp))
return -EFAULT;
base = dasd_device_from_gendisk(bdev->bd_disk);
if (!base)
return -ENODEV;
if (!intval && test_bit(DASD_FLAG_DEVICE_RO, &base->flags)) {
dasd_put_device(base);
return -EROFS;
}
set_disk_ro(bdev->bd_disk, intval);
rc = dasd_set_feature(base->cdev, DASD_FEATURE_READONLY, intval);
dasd_put_device(base);
return rc;
}
static int dasd_ioctl_readall_cmb(struct dasd_block *block, unsigned int cmd,
struct cmbdata __user *argp)
{
size_t size = _IOC_SIZE(cmd);
struct cmbdata data;
int ret;
ret = cmf_readall(block->base->cdev, &data);
if (!ret && copy_to_user(argp, &data, min(size, sizeof(*argp))))
return -EFAULT;
return ret;
}
int dasd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct dasd_block *block;
struct dasd_device *base;
void __user *argp;
int rc;
if (is_compat_task())
argp = compat_ptr(arg);
else
argp = (void __user *)arg;
if ((_IOC_DIR(cmd) != _IOC_NONE) && !arg) {
PRINT_DEBUG("empty data ptr");
return -EINVAL;
}
base = dasd_device_from_gendisk(bdev->bd_disk);
if (!base)
return -ENODEV;
block = base->block;
rc = 0;
switch (cmd) {
case BIODASDDISABLE:
rc = dasd_ioctl_disable(bdev);
break;
case BIODASDENABLE:
rc = dasd_ioctl_enable(bdev);
break;
case BIODASDQUIESCE:
rc = dasd_ioctl_quiesce(block);
break;
case BIODASDRESUME:
rc = dasd_ioctl_resume(block);
break;
case BIODASDFMT:
rc = dasd_ioctl_format(bdev, argp);
break;
case BIODASDINFO:
rc = dasd_ioctl_information(block, cmd, argp);
break;
case BIODASDINFO2:
rc = dasd_ioctl_information(block, cmd, argp);
break;
case BIODASDPRRD:
rc = dasd_ioctl_read_profile(block, argp);
break;
case BIODASDPRRST:
rc = dasd_ioctl_reset_profile(block);
break;
case BLKROSET:
rc = dasd_ioctl_set_ro(bdev, argp);
break;
case DASDAPIVER:
rc = dasd_ioctl_api_version(argp);
break;
case BIODASDCMFENABLE:
rc = enable_cmf(base->cdev);
break;
case BIODASDCMFDISABLE:
rc = disable_cmf(base->cdev);
break;
case BIODASDREADALLCMB:
rc = dasd_ioctl_readall_cmb(block, cmd, argp);
break;
default:
if (base->discipline->ioctl) {
rc = base->discipline->ioctl(block, cmd, argp);
if (rc == -ENOIOCTLCMD)
rc = -EINVAL;
} else
rc = -EINVAL;
}
dasd_put_device(base);
return rc;
}
