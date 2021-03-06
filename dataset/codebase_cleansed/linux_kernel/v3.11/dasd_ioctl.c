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
static int dasd_ioctl_abortio(struct dasd_block *block)
{
unsigned long flags;
struct dasd_device *base;
struct dasd_ccw_req *cqr, *n;
base = block->base;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (test_and_set_bit(DASD_FLAG_ABORTALL, &base->flags))
return 0;
DBF_DEV_EVENT(DBF_NOTICE, base, "%s", "abortall flag set");
spin_lock_irqsave(&block->request_queue_lock, flags);
spin_lock(&block->queue_lock);
list_for_each_entry_safe(cqr, n, &block->ccw_queue, blocklist) {
if (test_bit(DASD_CQR_FLAGS_FAILFAST, &cqr->flags) &&
cqr->callback_data &&
cqr->callback_data != DASD_SLEEPON_START_TAG &&
cqr->callback_data != DASD_SLEEPON_END_TAG) {
spin_unlock(&block->queue_lock);
blk_abort_request(cqr->callback_data);
spin_lock(&block->queue_lock);
}
}
spin_unlock(&block->queue_lock);
spin_unlock_irqrestore(&block->request_queue_lock, flags);
dasd_schedule_block_bh(block);
return 0;
}
static int dasd_ioctl_allowio(struct dasd_block *block)
{
struct dasd_device *base;
base = block->base;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (test_and_clear_bit(DASD_FLAG_ABORTALL, &base->flags))
DBF_DEV_EVENT(DBF_NOTICE, base, "%s", "abortall flag unset");
return 0;
}
static int
dasd_format(struct dasd_block *block, struct format_data_t *fdata)
{
struct dasd_device *base;
int rc;
base = block->base;
if (base->discipline->format_device == NULL)
return -EPERM;
if (base->state != DASD_STATE_BASIC) {
pr_warn("%s: The DASD cannot be formatted while it is enabled\n",
dev_name(&base->cdev->dev));
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
rc = base->discipline->format_device(base, fdata);
if (rc)
return rc;
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
dasd_profile_reset(&block->profile);
return 0;
}
static int dasd_ioctl_read_profile(struct dasd_block *block, void __user *argp)
{
struct dasd_profile_info_t *data;
int rc = 0;
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_bh(&block->profile.lock);
if (block->profile.data) {
data->dasd_io_reqs = block->profile.data->dasd_io_reqs;
data->dasd_io_sects = block->profile.data->dasd_io_sects;
memcpy(data->dasd_io_secs, block->profile.data->dasd_io_secs,
sizeof(data->dasd_io_secs));
memcpy(data->dasd_io_times, block->profile.data->dasd_io_times,
sizeof(data->dasd_io_times));
memcpy(data->dasd_io_timps, block->profile.data->dasd_io_timps,
sizeof(data->dasd_io_timps));
memcpy(data->dasd_io_time1, block->profile.data->dasd_io_time1,
sizeof(data->dasd_io_time1));
memcpy(data->dasd_io_time2, block->profile.data->dasd_io_time2,
sizeof(data->dasd_io_time2));
memcpy(data->dasd_io_time2ps,
block->profile.data->dasd_io_time2ps,
sizeof(data->dasd_io_time2ps));
memcpy(data->dasd_io_time3, block->profile.data->dasd_io_time3,
sizeof(data->dasd_io_time3));
memcpy(data->dasd_io_nr_req,
block->profile.data->dasd_io_nr_req,
sizeof(data->dasd_io_nr_req));
spin_unlock_bh(&block->profile.lock);
} else {
spin_unlock_bh(&block->profile.lock);
rc = -EIO;
goto out;
}
if (copy_to_user(argp, data, sizeof(*data)))
rc = -EFAULT;
out:
kfree(data);
return rc;
}
static int dasd_ioctl_reset_profile(struct dasd_block *block)
{
return -ENOTTY;
}
static int dasd_ioctl_read_profile(struct dasd_block *block, void __user *argp)
{
return -ENOTTY;
}
static int dasd_ioctl_information(struct dasd_block *block,
unsigned int cmd, void __user *argp)
{
struct dasd_information2_t *dasd_info;
struct subchannel_id sch_id;
struct ccw_dev_id dev_id;
struct dasd_device *base;
struct ccw_device *cdev;
unsigned long flags;
int rc;
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
ccw_device_get_schid(cdev, &sch_id);
dasd_info->devno = dev_id.devno;
dasd_info->schid = sch_id.sch_no;
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
case BIODASDABORTIO:
rc = dasd_ioctl_abortio(block);
break;
case BIODASDALLOWIO:
rc = dasd_ioctl_allowio(block);
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
rc = -ENOTTY;
if (base->discipline->ioctl)
rc = base->discipline->ioctl(block, cmd, argp);
}
dasd_put_device(base);
return rc;
}
