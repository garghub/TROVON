void mic_set_shutdown_status(struct mic_device *mdev, u8 shutdown_status)
{
dev_dbg(mdev->sdev->parent, "Shutdown Status %s -> %s\n",
mic_shutdown_status_string[mdev->shutdown_status],
mic_shutdown_status_string[shutdown_status]);
mdev->shutdown_status = shutdown_status;
}
void mic_set_state(struct mic_device *mdev, u8 state)
{
dev_dbg(mdev->sdev->parent, "State %s -> %s\n",
mic_state_string[mdev->state],
mic_state_string[state]);
mdev->state = state;
sysfs_notify_dirent(mdev->state_sysfs);
}
static ssize_t
family_show(struct device *dev, struct device_attribute *attr, char *buf)
{
static const char x100[] = "x100";
static const char unknown[] = "Unknown";
const char *card = NULL;
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
switch (mdev->family) {
case MIC_FAMILY_X100:
card = x100;
break;
default:
card = unknown;
break;
}
return scnprintf(buf, PAGE_SIZE, "%s\n", card);
}
static ssize_t
stepping_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
char *string = "??";
if (!mdev)
return -EINVAL;
switch (mdev->stepping) {
case MIC_A0_STEP:
string = "A0";
break;
case MIC_B0_STEP:
string = "B0";
break;
case MIC_B1_STEP:
string = "B1";
break;
case MIC_C0_STEP:
string = "C0";
break;
default:
break;
}
return scnprintf(buf, PAGE_SIZE, "%s\n", string);
}
static ssize_t
state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev || mdev->state >= MIC_LAST)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%s\n",
mic_state_string[mdev->state]);
}
static ssize_t
state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int rc = 0;
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
if (sysfs_streq(buf, "boot")) {
rc = mic_start(mdev, buf);
if (rc) {
dev_err(mdev->sdev->parent,
"mic_boot failed rc %d\n", rc);
count = rc;
}
goto done;
}
if (sysfs_streq(buf, "reset")) {
schedule_work(&mdev->reset_trigger_work);
goto done;
}
if (sysfs_streq(buf, "shutdown")) {
mic_shutdown(mdev);
goto done;
}
if (sysfs_streq(buf, "suspend")) {
mic_suspend(mdev);
goto done;
}
count = -EINVAL;
done:
return count;
}
static ssize_t shutdown_status_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev || mdev->shutdown_status >= MIC_STATUS_LAST)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%s\n",
mic_shutdown_status_string[mdev->shutdown_status]);
}
static ssize_t
cmdline_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
char *cmdline;
if (!mdev)
return -EINVAL;
cmdline = mdev->cmdline;
if (cmdline)
return scnprintf(buf, PAGE_SIZE, "%s\n", cmdline);
return 0;
}
static ssize_t
cmdline_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
mutex_lock(&mdev->mic_mutex);
kfree(mdev->cmdline);
mdev->cmdline = kmalloc(count + 1, GFP_KERNEL);
if (!mdev->cmdline) {
count = -ENOMEM;
goto unlock;
}
strncpy(mdev->cmdline, buf, count);
if (mdev->cmdline[count - 1] == '\n')
mdev->cmdline[count - 1] = '\0';
else
mdev->cmdline[count] = '\0';
unlock:
mutex_unlock(&mdev->mic_mutex);
return count;
}
static ssize_t
firmware_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
char *firmware;
if (!mdev)
return -EINVAL;
firmware = mdev->firmware;
if (firmware)
return scnprintf(buf, PAGE_SIZE, "%s\n", firmware);
return 0;
}
static ssize_t
firmware_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
mutex_lock(&mdev->mic_mutex);
kfree(mdev->firmware);
mdev->firmware = kmalloc(count + 1, GFP_KERNEL);
if (!mdev->firmware) {
count = -ENOMEM;
goto unlock;
}
strncpy(mdev->firmware, buf, count);
if (mdev->firmware[count - 1] == '\n')
mdev->firmware[count - 1] = '\0';
else
mdev->firmware[count] = '\0';
unlock:
mutex_unlock(&mdev->mic_mutex);
return count;
}
static ssize_t
ramdisk_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
char *ramdisk;
if (!mdev)
return -EINVAL;
ramdisk = mdev->ramdisk;
if (ramdisk)
return scnprintf(buf, PAGE_SIZE, "%s\n", ramdisk);
return 0;
}
static ssize_t
ramdisk_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
mutex_lock(&mdev->mic_mutex);
kfree(mdev->ramdisk);
mdev->ramdisk = kmalloc(count + 1, GFP_KERNEL);
if (!mdev->ramdisk) {
count = -ENOMEM;
goto unlock;
}
strncpy(mdev->ramdisk, buf, count);
if (mdev->ramdisk[count - 1] == '\n')
mdev->ramdisk[count - 1] = '\0';
else
mdev->ramdisk[count] = '\0';
unlock:
mutex_unlock(&mdev->mic_mutex);
return count;
}
static ssize_t
bootmode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
char *bootmode;
if (!mdev)
return -EINVAL;
bootmode = mdev->bootmode;
if (bootmode)
return scnprintf(buf, PAGE_SIZE, "%s\n", bootmode);
return 0;
}
static ssize_t
bootmode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
if (!sysfs_streq(buf, "linux") && !sysfs_streq(buf, "elf"))
return -EINVAL;
mutex_lock(&mdev->mic_mutex);
kfree(mdev->bootmode);
mdev->bootmode = kmalloc(count + 1, GFP_KERNEL);
if (!mdev->bootmode) {
count = -ENOMEM;
goto unlock;
}
strncpy(mdev->bootmode, buf, count);
if (mdev->bootmode[count - 1] == '\n')
mdev->bootmode[count - 1] = '\0';
else
mdev->bootmode[count] = '\0';
unlock:
mutex_unlock(&mdev->mic_mutex);
return count;
}
static ssize_t
log_buf_addr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%p\n", mdev->log_buf_addr);
}
static ssize_t
log_buf_addr_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
int ret;
unsigned long addr;
if (!mdev)
return -EINVAL;
ret = kstrtoul(buf, 16, &addr);
if (ret)
goto exit;
mdev->log_buf_addr = (void *)addr;
ret = count;
exit:
return ret;
}
static ssize_t
log_buf_len_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
if (!mdev)
return -EINVAL;
return scnprintf(buf, PAGE_SIZE, "%p\n", mdev->log_buf_len);
}
static ssize_t
log_buf_len_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
int ret;
unsigned long addr;
if (!mdev)
return -EINVAL;
ret = kstrtoul(buf, 16, &addr);
if (ret)
goto exit;
mdev->log_buf_len = (int *)addr;
ret = count;
exit:
return ret;
}
void mic_sysfs_init(struct mic_device *mdev)
{
mdev->attr_group = mic_default_groups;
}
