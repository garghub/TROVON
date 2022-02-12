static ssize_t _srom_read(int hv_devhdl, void *buf,
loff_t off, size_t count)
{
int retval, retries = SROM_MAX_WAIT_TRY_TIMES;
for (;;) {
retval = hv_dev_pread(hv_devhdl, 0, (HV_VirtAddr)buf,
count, off);
if (retval >= 0)
return retval;
if (retval == HV_EAGAIN)
continue;
if (retval == HV_EBUSY && --retries > 0) {
msleep(SROM_WAIT_TRY_INTERVAL);
continue;
}
pr_err("_srom_read: error %d\n", retval);
return -EIO;
}
}
static ssize_t _srom_write(int hv_devhdl, const void *buf,
loff_t off, size_t count)
{
int retval, retries = SROM_MAX_WAIT_TRY_TIMES;
for (;;) {
retval = hv_dev_pwrite(hv_devhdl, 0, (HV_VirtAddr)buf,
count, off);
if (retval >= 0)
return retval;
if (retval == HV_EAGAIN)
continue;
if (retval == HV_EBUSY && --retries > 0) {
msleep(SROM_WAIT_TRY_INTERVAL);
continue;
}
pr_err("_srom_write: error %d\n", retval);
return -EIO;
}
}
static int srom_open(struct inode *inode, struct file *filp)
{
filp->private_data = &srom_devices[iminor(inode)];
return 0;
}
static int srom_release(struct inode *inode, struct file *filp)
{
struct srom_dev *srom = filp->private_data;
char dummy;
mutex_lock(&srom->lock);
if (srom->hv_devhdl >= 0)
_srom_write(srom->hv_devhdl, &dummy, SROM_FLUSH_OFF, 1);
mutex_unlock(&srom->lock);
filp->private_data = NULL;
return 0;
}
static ssize_t srom_read(struct file *filp, char __user *buf,
size_t count, loff_t *f_pos)
{
int retval = 0;
void *kernbuf;
struct srom_dev *srom = filp->private_data;
kernbuf = kmalloc(SROM_CHUNK_SIZE, GFP_KERNEL);
if (!kernbuf)
return -ENOMEM;
if (mutex_lock_interruptible(&srom->lock)) {
retval = -ERESTARTSYS;
kfree(kernbuf);
return retval;
}
while (count) {
int hv_retval;
int bytes_this_pass = min(count, SROM_CHUNK_SIZE);
hv_retval = _srom_read(srom->hv_devhdl, kernbuf,
*f_pos, bytes_this_pass);
if (hv_retval <= 0) {
if (retval == 0)
retval = hv_retval;
break;
}
if (copy_to_user(buf, kernbuf, hv_retval) != 0) {
retval = -EFAULT;
break;
}
retval += hv_retval;
*f_pos += hv_retval;
buf += hv_retval;
count -= hv_retval;
}
mutex_unlock(&srom->lock);
kfree(kernbuf);
return retval;
}
static ssize_t srom_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
int retval = 0;
void *kernbuf;
struct srom_dev *srom = filp->private_data;
kernbuf = kmalloc(SROM_CHUNK_SIZE, GFP_KERNEL);
if (!kernbuf)
return -ENOMEM;
if (mutex_lock_interruptible(&srom->lock)) {
retval = -ERESTARTSYS;
kfree(kernbuf);
return retval;
}
while (count) {
int hv_retval;
int bytes_this_pass = min(count, SROM_CHUNK_SIZE);
if (copy_from_user(kernbuf, buf, bytes_this_pass) != 0) {
retval = -EFAULT;
break;
}
hv_retval = _srom_write(srom->hv_devhdl, kernbuf,
*f_pos, bytes_this_pass);
if (hv_retval <= 0) {
if (retval == 0)
retval = hv_retval;
break;
}
retval += hv_retval;
*f_pos += hv_retval;
buf += hv_retval;
count -= hv_retval;
}
mutex_unlock(&srom->lock);
kfree(kernbuf);
return retval;
}
loff_t srom_llseek(struct file *file, loff_t offset, int origin)
{
struct srom_dev *srom = file->private_data;
return fixed_size_llseek(file, offset, origin, srom->total_size);
}
static ssize_t total_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct srom_dev *srom = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", srom->total_size);
}
static ssize_t sector_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct srom_dev *srom = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", srom->sector_size);
}
static ssize_t page_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct srom_dev *srom = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", srom->page_size);
}
static char *srom_devnode(struct device *dev, umode_t *mode)
{
if (mode)
*mode = 0644;
return kasprintf(GFP_KERNEL, "srom/%s", dev_name(dev));
}
static int srom_setup_minor(struct srom_dev *srom, int devhdl)
{
srom->hv_devhdl = devhdl;
mutex_init(&srom->lock);
if (_srom_read(devhdl, &srom->total_size,
SROM_TOTAL_SIZE_OFF, sizeof(srom->total_size)) < 0)
return -EIO;
if (_srom_read(devhdl, &srom->sector_size,
SROM_SECTOR_SIZE_OFF, sizeof(srom->sector_size)) < 0)
return -EIO;
if (_srom_read(devhdl, &srom->page_size,
SROM_PAGE_SIZE_OFF, sizeof(srom->page_size)) < 0)
return -EIO;
return 0;
}
static int srom_init(void)
{
int result, i;
dev_t dev = MKDEV(srom_major, 0);
srom_devices = kmalloc(4 * sizeof(struct srom_dev), GFP_KERNEL);
for (i = 0; ; i++) {
int devhdl;
char buf[20];
struct srom_dev *new_srom_devices =
krealloc(srom_devices, (i+1) * sizeof(struct srom_dev),
GFP_KERNEL);
if (!new_srom_devices) {
result = -ENOMEM;
goto fail_mem;
}
srom_devices = new_srom_devices;
sprintf(buf, "srom/0/%d", i);
devhdl = hv_dev_open((HV_VirtAddr)buf, 0);
if (devhdl < 0) {
if (devhdl != HV_ENODEV)
pr_notice("srom/%d: hv_dev_open failed: %d.\n",
i, devhdl);
break;
}
result = srom_setup_minor(&srom_devices[i], devhdl);
if (result != 0)
goto fail_mem;
}
srom_devs = i;
if (srom_devs == 0) {
result = -ENODEV;
goto fail_mem;
}
if (srom_major)
result = register_chrdev_region(dev, srom_devs, "srom");
else {
result = alloc_chrdev_region(&dev, 0, srom_devs, "srom");
srom_major = MAJOR(dev);
}
if (result < 0)
goto fail_mem;
cdev_init(&srom_cdev, &srom_fops);
srom_cdev.owner = THIS_MODULE;
srom_cdev.ops = &srom_fops;
result = cdev_add(&srom_cdev, dev, srom_devs);
if (result < 0)
goto fail_chrdev;
srom_parent = platform_device_register_simple("srom", -1, NULL, 0);
if (IS_ERR(srom_parent)) {
result = PTR_ERR(srom_parent);
goto fail_pdev;
}
srom_class = class_create(THIS_MODULE, "srom");
if (IS_ERR(srom_class)) {
result = PTR_ERR(srom_class);
goto fail_cdev;
}
srom_class->dev_groups = srom_dev_groups;
srom_class->devnode = srom_devnode;
for (i = 0; i < srom_devs; i++) {
struct device *dev =
device_create(srom_class, &srom_parent->dev,
MKDEV(srom_major, i), srom_devices + i,
"%d", i);
result = PTR_ERR_OR_ZERO(dev);
if (result < 0)
goto fail_class;
}
return 0;
fail_class:
for (i = 0; i < srom_devs; i++)
device_destroy(srom_class, MKDEV(srom_major, i));
class_destroy(srom_class);
fail_cdev:
platform_device_unregister(srom_parent);
fail_pdev:
cdev_del(&srom_cdev);
fail_chrdev:
unregister_chrdev_region(dev, srom_devs);
fail_mem:
kfree(srom_devices);
return result;
}
static void srom_cleanup(void)
{
int i;
for (i = 0; i < srom_devs; i++)
device_destroy(srom_class, MKDEV(srom_major, i));
class_destroy(srom_class);
cdev_del(&srom_cdev);
platform_device_unregister(srom_parent);
unregister_chrdev_region(MKDEV(srom_major, 0), srom_devs);
kfree(srom_devices);
}
