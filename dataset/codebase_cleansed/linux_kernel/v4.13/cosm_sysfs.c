void cosm_set_shutdown_status(struct cosm_device *cdev, u8 shutdown_status)
{
dev_dbg(&cdev->dev, "Shutdown Status %s -> %s\n",
cosm_shutdown_status_string[cdev->shutdown_status],
cosm_shutdown_status_string[shutdown_status]);
cdev->shutdown_status = shutdown_status;
}
void cosm_set_state(struct cosm_device *cdev, u8 state)
{
dev_dbg(&cdev->dev, "State %s -> %s\n",
cosm_state_string[cdev->state],
cosm_state_string[state]);
cdev->state = state;
sysfs_notify_dirent(cdev->state_sysfs);
}
static ssize_t
family_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
return cdev->hw_ops->family(cdev, buf);
}
static ssize_t
stepping_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
return cdev->hw_ops->stepping(cdev, buf);
}
static ssize_t
state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev || cdev->state >= MIC_LAST)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%s\n",
cosm_state_string[cdev->state]);
}
static ssize_t
state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
int rc;
if (!cdev)
return -EINVAL;
if (sysfs_streq(buf, "boot")) {
rc = cosm_start(cdev);
goto done;
}
if (sysfs_streq(buf, "reset")) {
rc = cosm_reset(cdev);
goto done;
}
if (sysfs_streq(buf, "shutdown")) {
rc = cosm_shutdown(cdev);
goto done;
}
rc = -EINVAL;
done:
if (rc)
count = rc;
return count;
}
static ssize_t shutdown_status_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev || cdev->shutdown_status >= MIC_STATUS_LAST)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%s\n",
cosm_shutdown_status_string[cdev->shutdown_status]);
}
static ssize_t
heartbeat_enable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%d\n", cdev->sysfs_heartbeat_enable);
}
static ssize_t
heartbeat_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
int enable;
int ret;
if (!cdev)
return -EINVAL;
mutex_lock(&cdev->cosm_mutex);
ret = kstrtoint(buf, 10, &enable);
if (ret)
goto unlock;
cdev->sysfs_heartbeat_enable = enable;
if (cdev->state == MIC_ONLINE)
cdev->heartbeat_watchdog_enable = enable;
ret = count;
unlock:
mutex_unlock(&cdev->cosm_mutex);
return ret;
}
static ssize_t
cmdline_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
char *cmdline;
if (!cdev)
return -EINVAL;
cmdline = cdev->cmdline;
if (cmdline)
return scnprintf(buf, PAGE_SIZE, "%s\n", cmdline);
return 0;
}
static ssize_t
cmdline_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
mutex_lock(&cdev->cosm_mutex);
kfree(cdev->cmdline);
cdev->cmdline = kmalloc(count + 1, GFP_KERNEL);
if (!cdev->cmdline) {
count = -ENOMEM;
goto unlock;
}
strncpy(cdev->cmdline, buf, count);
if (cdev->cmdline[count - 1] == '\n')
cdev->cmdline[count - 1] = '\0';
else
cdev->cmdline[count] = '\0';
unlock:
mutex_unlock(&cdev->cosm_mutex);
return count;
}
static ssize_t
firmware_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
char *firmware;
if (!cdev)
return -EINVAL;
firmware = cdev->firmware;
if (firmware)
return scnprintf(buf, PAGE_SIZE, "%s\n", firmware);
return 0;
}
static ssize_t
firmware_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
mutex_lock(&cdev->cosm_mutex);
kfree(cdev->firmware);
cdev->firmware = kmalloc(count + 1, GFP_KERNEL);
if (!cdev->firmware) {
count = -ENOMEM;
goto unlock;
}
strncpy(cdev->firmware, buf, count);
if (cdev->firmware[count - 1] == '\n')
cdev->firmware[count - 1] = '\0';
else
cdev->firmware[count] = '\0';
unlock:
mutex_unlock(&cdev->cosm_mutex);
return count;
}
static ssize_t
ramdisk_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
char *ramdisk;
if (!cdev)
return -EINVAL;
ramdisk = cdev->ramdisk;
if (ramdisk)
return scnprintf(buf, PAGE_SIZE, "%s\n", ramdisk);
return 0;
}
static ssize_t
ramdisk_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
mutex_lock(&cdev->cosm_mutex);
kfree(cdev->ramdisk);
cdev->ramdisk = kmalloc(count + 1, GFP_KERNEL);
if (!cdev->ramdisk) {
count = -ENOMEM;
goto unlock;
}
strncpy(cdev->ramdisk, buf, count);
if (cdev->ramdisk[count - 1] == '\n')
cdev->ramdisk[count - 1] = '\0';
else
cdev->ramdisk[count] = '\0';
unlock:
mutex_unlock(&cdev->cosm_mutex);
return count;
}
static ssize_t
bootmode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
char *bootmode;
if (!cdev)
return -EINVAL;
bootmode = cdev->bootmode;
if (bootmode)
return scnprintf(buf, PAGE_SIZE, "%s\n", bootmode);
return 0;
}
static ssize_t
bootmode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
if (!sysfs_streq(buf, "linux") && !sysfs_streq(buf, "flash"))
return -EINVAL;
mutex_lock(&cdev->cosm_mutex);
kfree(cdev->bootmode);
cdev->bootmode = kmalloc(count + 1, GFP_KERNEL);
if (!cdev->bootmode) {
count = -ENOMEM;
goto unlock;
}
strncpy(cdev->bootmode, buf, count);
if (cdev->bootmode[count - 1] == '\n')
cdev->bootmode[count - 1] = '\0';
else
cdev->bootmode[count] = '\0';
unlock:
mutex_unlock(&cdev->cosm_mutex);
return count;
}
static ssize_t
log_buf_addr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%p\n", cdev->log_buf_addr);
}
static ssize_t
log_buf_addr_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
int ret;
unsigned long addr;
if (!cdev)
return -EINVAL;
ret = kstrtoul(buf, 16, &addr);
if (ret)
goto exit;
cdev->log_buf_addr = (void *)addr;
ret = count;
exit:
return ret;
}
static ssize_t
log_buf_len_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
if (!cdev)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%p\n", cdev->log_buf_len);
}
static ssize_t
log_buf_len_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct cosm_device *cdev = dev_get_drvdata(dev);
int ret;
unsigned long addr;
if (!cdev)
return -EINVAL;
ret = kstrtoul(buf, 16, &addr);
if (ret)
goto exit;
cdev->log_buf_len = (int *)addr;
ret = count;
exit:
return ret;
}
void cosm_sysfs_init(struct cosm_device *cdev)
{
cdev->attr_group = cosm_default_groups;
}
