static char *hmcdrv_dev_name(struct device *dev, umode_t *mode)
{
char *nodename = NULL;
const char *devname = dev_name(dev);
if (devname)
nodename = kasprintf(GFP_KERNEL, "%s", devname);
if (mode)
*mode = hmcdrv_dev.mode;
return nodename;
}
static int hmcdrv_dev_open(struct inode *inode, struct file *fp)
{
int rc;
if (fp->f_flags & O_NONBLOCK)
return -EINVAL;
if ((fp->f_flags & O_ACCMODE) == O_RDONLY)
return -EINVAL;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
fp->private_data = NULL;
rc = hmcdrv_ftp_startup();
if (rc)
module_put(THIS_MODULE);
pr_debug("open file '/dev/%s' with return code %d\n",
fp->f_dentry->d_name.name, rc);
return rc;
}
static int hmcdrv_dev_release(struct inode *inode, struct file *fp)
{
pr_debug("closing file '/dev/%s'\n", fp->f_dentry->d_name.name);
kfree(fp->private_data);
fp->private_data = NULL;
hmcdrv_ftp_shutdown();
module_put(THIS_MODULE);
return 0;
}
static loff_t hmcdrv_dev_seek(struct file *fp, loff_t pos, int whence)
{
switch (whence) {
case SEEK_CUR:
pos += fp->f_pos;
break;
case SEEK_SET:
break;
case SEEK_END:
if (fp->private_data) {
kfree(fp->private_data);
fp->private_data = NULL;
}
break;
default:
return -EINVAL;
}
if (pos < 0)
return -EINVAL;
if (fp->f_pos != pos)
++fp->f_version;
fp->f_pos = pos;
return pos;
}
static ssize_t hmcdrv_dev_transfer(char __kernel *cmd, loff_t offset,
char __user *buf, size_t len)
{
ssize_t retlen;
unsigned trials = HMCDRV_DEV_BUSY_RETRIES;
do {
retlen = hmcdrv_ftp_cmd(cmd, offset, buf, len);
if (retlen != -EBUSY)
break;
msleep(HMCDRV_DEV_BUSY_DELAY);
} while (--trials > 0);
return retlen;
}
static ssize_t hmcdrv_dev_read(struct file *fp, char __user *ubuf,
size_t len, loff_t *pos)
{
ssize_t retlen;
if (((fp->f_flags & O_ACCMODE) == O_WRONLY) ||
(fp->private_data == NULL)) {
return -EBADF;
}
retlen = hmcdrv_dev_transfer((char *) fp->private_data,
*pos, ubuf, len);
pr_debug("read from file '/dev/%s' at %lld returns %zd/%zu\n",
fp->f_dentry->d_name.name, (long long) *pos, retlen, len);
if (retlen > 0)
*pos += retlen;
return retlen;
}
static ssize_t hmcdrv_dev_write(struct file *fp, const char __user *ubuf,
size_t len, loff_t *pos)
{
ssize_t retlen;
pr_debug("writing file '/dev/%s' at pos. %lld with length %zd\n",
fp->f_dentry->d_name.name, (long long) *pos, len);
if (!fp->private_data) {
fp->private_data = kmalloc(len + 1, GFP_KERNEL);
if (!fp->private_data)
return -ENOMEM;
if (!copy_from_user(fp->private_data, ubuf, len)) {
((char *)fp->private_data)[len] = '\0';
return len;
}
kfree(fp->private_data);
fp->private_data = NULL;
return -EFAULT;
}
retlen = hmcdrv_dev_transfer((char *) fp->private_data,
*pos, (char __user *) ubuf, len);
if (retlen > 0)
*pos += retlen;
pr_debug("write to file '/dev/%s' returned %zd\n",
fp->f_dentry->d_name.name, retlen);
return retlen;
}
int hmcdrv_dev_init(void)
{
int rc;
#ifdef HMCDRV_DEV_CLASS
struct device *dev;
rc = alloc_chrdev_region(&hmcdrv_dev_no, 0, 1, HMCDRV_DEV_NAME);
if (rc)
goto out_err;
cdev_init(&hmcdrv_dev.dev, &hmcdrv_dev_fops);
hmcdrv_dev.dev.owner = THIS_MODULE;
rc = cdev_add(&hmcdrv_dev.dev, hmcdrv_dev_no, 1);
if (rc)
goto out_unreg;
hmcdrv_dev_class = class_create(THIS_MODULE, HMCDRV_DEV_CLASS);
if (IS_ERR(hmcdrv_dev_class)) {
rc = PTR_ERR(hmcdrv_dev_class);
goto out_devdel;
}
hmcdrv_dev.mode = 0;
hmcdrv_dev_class->devnode = hmcdrv_dev_name;
dev = device_create(hmcdrv_dev_class, NULL, hmcdrv_dev_no, NULL,
"%s", HMCDRV_DEV_NAME);
if (!IS_ERR(dev))
return 0;
rc = PTR_ERR(dev);
class_destroy(hmcdrv_dev_class);
hmcdrv_dev_class = NULL;
out_devdel:
cdev_del(&hmcdrv_dev.dev);
out_unreg:
unregister_chrdev_region(hmcdrv_dev_no, 1);
out_err:
#else
hmcdrv_dev.dev.minor = MISC_DYNAMIC_MINOR;
hmcdrv_dev.dev.name = HMCDRV_DEV_NAME;
hmcdrv_dev.dev.fops = &hmcdrv_dev_fops;
hmcdrv_dev.dev.mode = 0;
rc = misc_register(&hmcdrv_dev.dev);
#endif
return rc;
}
void hmcdrv_dev_exit(void)
{
#ifdef HMCDRV_DEV_CLASS
if (!IS_ERR_OR_NULL(hmcdrv_dev_class)) {
device_destroy(hmcdrv_dev_class, hmcdrv_dev_no);
class_destroy(hmcdrv_dev_class);
}
cdev_del(&hmcdrv_dev.dev);
unregister_chrdev_region(hmcdrv_dev_no, 1);
#else
misc_deregister(&hmcdrv_dev.dev);
#endif
}
