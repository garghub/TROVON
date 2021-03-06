static void media_devnode_release(struct device *cd)
{
struct media_devnode *mdev = to_media_devnode(cd);
mutex_lock(&media_devnode_lock);
cdev_del(&mdev->cdev);
clear_bit(mdev->minor, media_devnode_nums);
mutex_unlock(&media_devnode_lock);
if (mdev->release)
mdev->release(mdev);
}
static ssize_t media_read(struct file *filp, char __user *buf,
size_t sz, loff_t *off)
{
struct media_devnode *mdev = media_devnode_data(filp);
if (!mdev->fops->read)
return -EINVAL;
if (!media_devnode_is_registered(mdev))
return -EIO;
return mdev->fops->read(filp, buf, sz, off);
}
static ssize_t media_write(struct file *filp, const char __user *buf,
size_t sz, loff_t *off)
{
struct media_devnode *mdev = media_devnode_data(filp);
if (!mdev->fops->write)
return -EINVAL;
if (!media_devnode_is_registered(mdev))
return -EIO;
return mdev->fops->write(filp, buf, sz, off);
}
static unsigned int media_poll(struct file *filp,
struct poll_table_struct *poll)
{
struct media_devnode *mdev = media_devnode_data(filp);
if (!media_devnode_is_registered(mdev))
return POLLERR | POLLHUP;
if (!mdev->fops->poll)
return DEFAULT_POLLMASK;
return mdev->fops->poll(filp, poll);
}
static long media_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
struct media_devnode *mdev = media_devnode_data(filp);
if (!mdev->fops->ioctl)
return -ENOTTY;
if (!media_devnode_is_registered(mdev))
return -EIO;
return mdev->fops->ioctl(filp, cmd, arg);
}
static int media_open(struct inode *inode, struct file *filp)
{
struct media_devnode *mdev;
int ret;
mutex_lock(&media_devnode_lock);
mdev = container_of(inode->i_cdev, struct media_devnode, cdev);
if (!media_devnode_is_registered(mdev)) {
mutex_unlock(&media_devnode_lock);
return -ENXIO;
}
get_device(&mdev->dev);
mutex_unlock(&media_devnode_lock);
filp->private_data = mdev;
if (mdev->fops->open) {
ret = mdev->fops->open(filp);
if (ret) {
put_device(&mdev->dev);
return ret;
}
}
return 0;
}
static int media_release(struct inode *inode, struct file *filp)
{
struct media_devnode *mdev = media_devnode_data(filp);
int ret = 0;
if (mdev->fops->release)
mdev->fops->release(filp);
put_device(&mdev->dev);
filp->private_data = NULL;
return ret;
}
int __must_check media_devnode_register(struct media_devnode *mdev)
{
int minor;
int ret;
mutex_lock(&media_devnode_lock);
minor = find_next_zero_bit(media_devnode_nums, MEDIA_NUM_DEVICES, 0);
if (minor == MEDIA_NUM_DEVICES) {
mutex_unlock(&media_devnode_lock);
printk(KERN_ERR "could not get a free minor\n");
return -ENFILE;
}
set_bit(minor, media_devnode_nums);
mutex_unlock(&media_devnode_lock);
mdev->minor = minor;
cdev_init(&mdev->cdev, &media_devnode_fops);
mdev->cdev.owner = mdev->fops->owner;
ret = cdev_add(&mdev->cdev, MKDEV(MAJOR(media_dev_t), mdev->minor), 1);
if (ret < 0) {
printk(KERN_ERR "%s: cdev_add failed\n", __func__);
goto error;
}
mdev->dev.bus = &media_bus_type;
mdev->dev.devt = MKDEV(MAJOR(media_dev_t), mdev->minor);
mdev->dev.release = media_devnode_release;
if (mdev->parent)
mdev->dev.parent = mdev->parent;
dev_set_name(&mdev->dev, "media%d", mdev->minor);
ret = device_register(&mdev->dev);
if (ret < 0) {
printk(KERN_ERR "%s: device_register failed\n", __func__);
goto error;
}
set_bit(MEDIA_FLAG_REGISTERED, &mdev->flags);
return 0;
error:
cdev_del(&mdev->cdev);
clear_bit(mdev->minor, media_devnode_nums);
return ret;
}
void media_devnode_unregister(struct media_devnode *mdev)
{
if (!media_devnode_is_registered(mdev))
return;
mutex_lock(&media_devnode_lock);
clear_bit(MEDIA_FLAG_REGISTERED, &mdev->flags);
mutex_unlock(&media_devnode_lock);
device_unregister(&mdev->dev);
}
static int __init media_devnode_init(void)
{
int ret;
printk(KERN_INFO "Linux media interface: v0.10\n");
ret = alloc_chrdev_region(&media_dev_t, 0, MEDIA_NUM_DEVICES,
MEDIA_NAME);
if (ret < 0) {
printk(KERN_WARNING "media: unable to allocate major\n");
return ret;
}
ret = bus_register(&media_bus_type);
if (ret < 0) {
unregister_chrdev_region(media_dev_t, MEDIA_NUM_DEVICES);
printk(KERN_WARNING "media: bus_register failed\n");
return -EIO;
}
return 0;
}
static void __exit media_devnode_exit(void)
{
bus_unregister(&media_bus_type);
unregister_chrdev_region(media_dev_t, MEDIA_NUM_DEVICES);
}
