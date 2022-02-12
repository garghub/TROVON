static void gt683r_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
int i;
struct device *dev = led_cdev->dev->parent;
struct hid_device *hdev = to_hid_device(dev);
struct gt683r_led *led = hid_get_drvdata(hdev);
for (i = 0; i < GT683R_LED_COUNT; i++) {
if (led_cdev == &led->led_devs[i])
break;
}
if (i < GT683R_LED_COUNT) {
led->brightnesses[i] = brightness;
schedule_work(&led->work);
}
}
static ssize_t mode_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
u8 sysfs_mode;
struct hid_device *hdev = to_hid_device(dev->parent);
struct gt683r_led *led = hid_get_drvdata(hdev);
if (led->mode == GT683R_LED_NORMAL)
sysfs_mode = 0;
else if (led->mode == GT683R_LED_AUDIO)
sysfs_mode = 1;
else
sysfs_mode = 2;
return scnprintf(buf, PAGE_SIZE, "%u\n", sysfs_mode);
}
static ssize_t mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u8 sysfs_mode;
struct hid_device *hdev = to_hid_device(dev->parent);
struct gt683r_led *led = hid_get_drvdata(hdev);
if (kstrtou8(buf, 10, &sysfs_mode) || sysfs_mode > 2)
return -EINVAL;
mutex_lock(&led->lock);
if (sysfs_mode == 0)
led->mode = GT683R_LED_NORMAL;
else if (sysfs_mode == 1)
led->mode = GT683R_LED_AUDIO;
else
led->mode = GT683R_LED_BREATHING;
mutex_unlock(&led->lock);
schedule_work(&led->work);
return count;
}
static int gt683r_led_snd_msg(struct gt683r_led *led, u8 *msg)
{
int ret;
ret = hid_hw_raw_request(led->hdev, msg[0], msg, GT683R_BUFFER_SIZE,
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret != GT683R_BUFFER_SIZE) {
hid_err(led->hdev,
"failed to send set report request: %i\n", ret);
if (ret < 0)
return ret;
return -EIO;
}
return 0;
}
static int gt683r_leds_set(struct gt683r_led *led, u8 leds)
{
int ret;
u8 *buffer;
buffer = kzalloc(GT683R_BUFFER_SIZE, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = 0x01;
buffer[1] = 0x02;
buffer[2] = 0x30;
buffer[3] = leds;
ret = gt683r_led_snd_msg(led, buffer);
kfree(buffer);
return ret;
}
static int gt683r_mode_set(struct gt683r_led *led, u8 mode)
{
int ret;
u8 *buffer;
buffer = kzalloc(GT683R_BUFFER_SIZE, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = 0x01;
buffer[1] = 0x02;
buffer[2] = 0x20;
buffer[3] = mode;
buffer[4] = 0x01;
ret = gt683r_led_snd_msg(led, buffer);
kfree(buffer);
return ret;
}
static void gt683r_led_work(struct work_struct *work)
{
int i;
u8 leds = 0;
u8 mode;
struct gt683r_led *led = container_of(work, struct gt683r_led, work);
mutex_lock(&led->lock);
for (i = 0; i < GT683R_LED_COUNT; i++) {
if (led->brightnesses[i])
leds |= BIT(i);
}
if (gt683r_leds_set(led, leds))
goto fail;
if (leds)
mode = led->mode;
else
mode = GT683R_LED_OFF;
gt683r_mode_set(led, mode);
fail:
mutex_unlock(&led->lock);
}
static int gt683r_led_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int i;
int ret;
int name_sz;
char *name;
struct gt683r_led *led;
led = devm_kzalloc(&hdev->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
mutex_init(&led->lock);
INIT_WORK(&led->work, gt683r_led_work);
led->mode = GT683R_LED_NORMAL;
led->hdev = hdev;
hid_set_drvdata(hdev, led);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "hid parsing failed\n");
return ret;
}
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
for (i = 0; i < GT683R_LED_COUNT; i++) {
name_sz = strlen(dev_name(&hdev->dev)) +
strlen(gt683r_panel_names[i]) + 3;
name = devm_kzalloc(&hdev->dev, name_sz, GFP_KERNEL);
if (!name) {
ret = -ENOMEM;
goto fail;
}
snprintf(name, name_sz, "%s::%s",
dev_name(&hdev->dev), gt683r_panel_names[i]);
led->led_devs[i].name = name;
led->led_devs[i].max_brightness = 1;
led->led_devs[i].brightness_set = gt683r_brightness_set;
led->led_devs[i].groups = gt683r_led_groups;
ret = led_classdev_register(&hdev->dev, &led->led_devs[i]);
if (ret) {
hid_err(hdev, "could not register led device\n");
goto fail;
}
}
return 0;
fail:
for (i = i - 1; i >= 0; i--)
led_classdev_unregister(&led->led_devs[i]);
hid_hw_stop(hdev);
return ret;
}
static void gt683r_led_remove(struct hid_device *hdev)
{
int i;
struct gt683r_led *led = hid_get_drvdata(hdev);
for (i = 0; i < GT683R_LED_COUNT; i++)
led_classdev_unregister(&led->led_devs[i]);
flush_work(&led->work);
hid_hw_stop(hdev);
}
