static ssize_t flash_brightness_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
unsigned long state;
ssize_t ret;
mutex_lock(&led_cdev->led_access);
if (led_sysfs_is_disabled(led_cdev)) {
ret = -EBUSY;
goto unlock;
}
ret = kstrtoul(buf, 10, &state);
if (ret)
goto unlock;
ret = led_set_flash_brightness(fled_cdev, state);
if (ret < 0)
goto unlock;
ret = size;
unlock:
mutex_unlock(&led_cdev->led_access);
return ret;
}
static ssize_t flash_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
led_update_flash_brightness(fled_cdev);
return sprintf(buf, "%u\n", fled_cdev->brightness.val);
}
static ssize_t max_flash_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
return sprintf(buf, "%u\n", fled_cdev->brightness.max);
}
static ssize_t flash_strobe_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
unsigned long state;
ssize_t ret = -EINVAL;
mutex_lock(&led_cdev->led_access);
if (led_sysfs_is_disabled(led_cdev)) {
ret = -EBUSY;
goto unlock;
}
ret = kstrtoul(buf, 10, &state);
if (ret)
goto unlock;
if (state < 0 || state > 1) {
ret = -EINVAL;
goto unlock;
}
ret = led_set_flash_strobe(fled_cdev, state);
if (ret < 0)
goto unlock;
ret = size;
unlock:
mutex_unlock(&led_cdev->led_access);
return ret;
}
static ssize_t flash_strobe_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
bool state;
int ret;
ret = led_get_flash_strobe(fled_cdev, &state);
if (ret < 0)
return ret;
return sprintf(buf, "%u\n", state);
}
static ssize_t flash_timeout_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
unsigned long flash_timeout;
ssize_t ret;
mutex_lock(&led_cdev->led_access);
if (led_sysfs_is_disabled(led_cdev)) {
ret = -EBUSY;
goto unlock;
}
ret = kstrtoul(buf, 10, &flash_timeout);
if (ret)
goto unlock;
ret = led_set_flash_timeout(fled_cdev, flash_timeout);
if (ret < 0)
goto unlock;
ret = size;
unlock:
mutex_unlock(&led_cdev->led_access);
return ret;
}
static ssize_t flash_timeout_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
return sprintf(buf, "%u\n", fled_cdev->timeout.val);
}
static ssize_t max_flash_timeout_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
return sprintf(buf, "%u\n", fled_cdev->timeout.max);
}
static ssize_t flash_fault_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
u32 fault, mask = 0x1;
char *pbuf = buf;
int i, ret, buf_len;
ret = led_get_flash_fault(fled_cdev, &fault);
if (ret < 0)
return -EINVAL;
*buf = '\0';
for (i = 0; i < LED_NUM_FLASH_FAULTS; ++i) {
if (fault & mask) {
buf_len = sprintf(pbuf, "%s ",
led_flash_fault_names[i]);
pbuf += buf_len;
}
mask <<= 1;
}
return sprintf(buf, "%s\n", buf);
}
static void led_flash_resume(struct led_classdev *led_cdev)
{
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
call_flash_op(fled_cdev, flash_brightness_set,
fled_cdev->brightness.val);
call_flash_op(fled_cdev, timeout_set, fled_cdev->timeout.val);
}
static void led_flash_init_sysfs_groups(struct led_classdev_flash *fled_cdev)
{
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
const struct led_flash_ops *ops = fled_cdev->ops;
const struct attribute_group **flash_groups = fled_cdev->sysfs_groups;
int num_sysfs_groups = 0;
flash_groups[num_sysfs_groups++] = &led_flash_strobe_group;
if (ops->flash_brightness_set)
flash_groups[num_sysfs_groups++] = &led_flash_brightness_group;
if (ops->timeout_set)
flash_groups[num_sysfs_groups++] = &led_flash_timeout_group;
if (ops->fault_get)
flash_groups[num_sysfs_groups++] = &led_flash_fault_group;
led_cdev->groups = flash_groups;
}
int led_classdev_flash_register(struct device *parent,
struct led_classdev_flash *fled_cdev)
{
struct led_classdev *led_cdev;
const struct led_flash_ops *ops;
int ret;
if (!fled_cdev)
return -EINVAL;
led_cdev = &fled_cdev->led_cdev;
if (led_cdev->flags & LED_DEV_CAP_FLASH) {
if (!led_cdev->brightness_set_sync)
return -EINVAL;
ops = fled_cdev->ops;
if (!ops || !ops->strobe_set)
return -EINVAL;
led_cdev->flash_resume = led_flash_resume;
led_flash_init_sysfs_groups(fled_cdev);
}
ret = led_classdev_register(parent, led_cdev);
if (ret < 0)
return ret;
led_cdev->flags &= ~SET_BRIGHTNESS_ASYNC;
led_cdev->flags |= SET_BRIGHTNESS_SYNC;
return 0;
}
void led_classdev_flash_unregister(struct led_classdev_flash *fled_cdev)
{
if (!fled_cdev)
return;
led_classdev_unregister(&fled_cdev->led_cdev);
}
static void led_clamp_align(struct led_flash_setting *s)
{
u32 v, offset;
v = s->val + s->step / 2;
v = clamp(v, s->min, s->max);
offset = v - s->min;
offset = s->step * (offset / s->step);
s->val = s->min + offset;
}
int led_set_flash_timeout(struct led_classdev_flash *fled_cdev, u32 timeout)
{
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct led_flash_setting *s = &fled_cdev->timeout;
s->val = timeout;
led_clamp_align(s);
if (!(led_cdev->flags & LED_SUSPENDED))
return call_flash_op(fled_cdev, timeout_set, s->val);
return 0;
}
int led_get_flash_fault(struct led_classdev_flash *fled_cdev, u32 *fault)
{
return call_flash_op(fled_cdev, fault_get, fault);
}
int led_set_flash_brightness(struct led_classdev_flash *fled_cdev,
u32 brightness)
{
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct led_flash_setting *s = &fled_cdev->brightness;
s->val = brightness;
led_clamp_align(s);
if (!(led_cdev->flags & LED_SUSPENDED))
return call_flash_op(fled_cdev, flash_brightness_set, s->val);
return 0;
}
int led_update_flash_brightness(struct led_classdev_flash *fled_cdev)
{
struct led_flash_setting *s = &fled_cdev->brightness;
u32 brightness;
if (has_flash_op(fled_cdev, flash_brightness_get)) {
int ret = call_flash_op(fled_cdev, flash_brightness_get,
&brightness);
if (ret < 0)
return ret;
s->val = brightness;
}
return 0;
}
