static ssize_t brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
led_update_brightness(led_cdev);
return sprintf(buf, "%u\n", led_cdev->brightness);
}
static ssize_t brightness_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
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
if (state == LED_OFF)
led_trigger_remove(led_cdev);
led_set_brightness(led_cdev, state);
ret = size;
unlock:
mutex_unlock(&led_cdev->led_access);
return ret;
}
static ssize_t max_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", led_cdev->max_brightness);
}
static ssize_t brightness_hw_changed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
if (led_cdev->brightness_hw_changed == -1)
return -ENODATA;
return sprintf(buf, "%u\n", led_cdev->brightness_hw_changed);
}
static int led_add_brightness_hw_changed(struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev;
int ret;
ret = device_create_file(dev, &dev_attr_brightness_hw_changed);
if (ret) {
dev_err(dev, "Error creating brightness_hw_changed\n");
return ret;
}
led_cdev->brightness_hw_changed_kn =
sysfs_get_dirent(dev->kobj.sd, "brightness_hw_changed");
if (!led_cdev->brightness_hw_changed_kn) {
dev_err(dev, "Error getting brightness_hw_changed kn\n");
device_remove_file(dev, &dev_attr_brightness_hw_changed);
return -ENXIO;
}
return 0;
}
static void led_remove_brightness_hw_changed(struct led_classdev *led_cdev)
{
sysfs_put(led_cdev->brightness_hw_changed_kn);
device_remove_file(led_cdev->dev, &dev_attr_brightness_hw_changed);
}
void led_classdev_notify_brightness_hw_changed(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
if (WARN_ON(!led_cdev->brightness_hw_changed_kn))
return;
led_cdev->brightness_hw_changed = brightness;
sysfs_notify_dirent(led_cdev->brightness_hw_changed_kn);
}
static int led_add_brightness_hw_changed(struct led_classdev *led_cdev)
{
return 0;
}
static void led_remove_brightness_hw_changed(struct led_classdev *led_cdev)
{
}
void led_classdev_suspend(struct led_classdev *led_cdev)
{
led_cdev->flags |= LED_SUSPENDED;
led_set_brightness_nopm(led_cdev, 0);
}
void led_classdev_resume(struct led_classdev *led_cdev)
{
led_set_brightness_nopm(led_cdev, led_cdev->brightness);
if (led_cdev->flash_resume)
led_cdev->flash_resume(led_cdev);
led_cdev->flags &= ~LED_SUSPENDED;
}
static int led_suspend(struct device *dev)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
if (led_cdev->flags & LED_CORE_SUSPENDRESUME)
led_classdev_suspend(led_cdev);
return 0;
}
static int led_resume(struct device *dev)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
if (led_cdev->flags & LED_CORE_SUSPENDRESUME)
led_classdev_resume(led_cdev);
return 0;
}
static int match_name(struct device *dev, const void *data)
{
if (!dev_name(dev))
return 0;
return !strcmp(dev_name(dev), (char *)data);
}
static int led_classdev_next_name(const char *init_name, char *name,
size_t len)
{
unsigned int i = 0;
int ret = 0;
struct device *dev;
strlcpy(name, init_name, len);
while ((ret < len) &&
(dev = class_find_device(leds_class, NULL, name, match_name))) {
put_device(dev);
ret = snprintf(name, len, "%s_%u", init_name, ++i);
}
if (ret >= len)
return -ENOMEM;
return i;
}
int of_led_classdev_register(struct device *parent, struct device_node *np,
struct led_classdev *led_cdev)
{
char name[LED_MAX_NAME_SIZE];
int ret;
ret = led_classdev_next_name(led_cdev->name, name, sizeof(name));
if (ret < 0)
return ret;
led_cdev->dev = device_create_with_groups(leds_class, parent, 0,
led_cdev, led_cdev->groups, "%s", name);
if (IS_ERR(led_cdev->dev))
return PTR_ERR(led_cdev->dev);
led_cdev->dev->of_node = np;
if (ret)
dev_warn(parent, "Led %s renamed to %s due to name collision",
led_cdev->name, dev_name(led_cdev->dev));
if (led_cdev->flags & LED_BRIGHT_HW_CHANGED) {
ret = led_add_brightness_hw_changed(led_cdev);
if (ret) {
device_unregister(led_cdev->dev);
return ret;
}
}
led_cdev->work_flags = 0;
#ifdef CONFIG_LEDS_TRIGGERS
init_rwsem(&led_cdev->trigger_lock);
#endif
#ifdef CONFIG_LEDS_BRIGHTNESS_HW_CHANGED
led_cdev->brightness_hw_changed = -1;
#endif
mutex_init(&led_cdev->led_access);
down_write(&leds_list_lock);
list_add_tail(&led_cdev->node, &leds_list);
up_write(&leds_list_lock);
if (!led_cdev->max_brightness)
led_cdev->max_brightness = LED_FULL;
led_update_brightness(led_cdev);
led_init_core(led_cdev);
#ifdef CONFIG_LEDS_TRIGGERS
led_trigger_set_default(led_cdev);
#endif
dev_dbg(parent, "Registered led device: %s\n",
led_cdev->name);
return 0;
}
void led_classdev_unregister(struct led_classdev *led_cdev)
{
#ifdef CONFIG_LEDS_TRIGGERS
down_write(&led_cdev->trigger_lock);
if (led_cdev->trigger)
led_trigger_set(led_cdev, NULL);
up_write(&led_cdev->trigger_lock);
#endif
led_cdev->flags |= LED_UNREGISTERING;
led_stop_software_blink(led_cdev);
led_set_brightness(led_cdev, LED_OFF);
flush_work(&led_cdev->set_brightness_work);
if (led_cdev->flags & LED_BRIGHT_HW_CHANGED)
led_remove_brightness_hw_changed(led_cdev);
device_unregister(led_cdev->dev);
down_write(&leds_list_lock);
list_del(&led_cdev->node);
up_write(&leds_list_lock);
mutex_destroy(&led_cdev->led_access);
}
static void devm_led_classdev_release(struct device *dev, void *res)
{
led_classdev_unregister(*(struct led_classdev **)res);
}
int devm_of_led_classdev_register(struct device *parent,
struct device_node *np,
struct led_classdev *led_cdev)
{
struct led_classdev **dr;
int rc;
dr = devres_alloc(devm_led_classdev_release, sizeof(*dr), GFP_KERNEL);
if (!dr)
return -ENOMEM;
rc = of_led_classdev_register(parent, np, led_cdev);
if (rc) {
devres_free(dr);
return rc;
}
*dr = led_cdev;
devres_add(parent, dr);
return 0;
}
static int devm_led_classdev_match(struct device *dev, void *res, void *data)
{
struct led_cdev **p = res;
if (WARN_ON(!p || !*p))
return 0;
return *p == data;
}
void devm_led_classdev_unregister(struct device *dev,
struct led_classdev *led_cdev)
{
WARN_ON(devres_release(dev,
devm_led_classdev_release,
devm_led_classdev_match, led_cdev));
}
static int __init leds_init(void)
{
leds_class = class_create(THIS_MODULE, "leds");
if (IS_ERR(leds_class))
return PTR_ERR(leds_class);
leds_class->pm = &leds_class_dev_pm_ops;
leds_class->dev_groups = led_groups;
return 0;
}
static void __exit leds_exit(void)
{
class_destroy(leds_class);
}
