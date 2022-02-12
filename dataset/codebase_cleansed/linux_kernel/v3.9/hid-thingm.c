static int blink1_send_command(struct blink1_data *data,
u8 buf[BLINK1_CMD_SIZE])
{
int ret;
hid_dbg(data->hdev, "command: %d%c%.2x%.2x%.2x%.2x%.2x%.2x%.2x\n",
buf[0], buf[1], buf[2], buf[3], buf[4],
buf[5], buf[6], buf[7], buf[8]);
ret = data->hdev->hid_output_raw_report(data->hdev, buf,
BLINK1_CMD_SIZE, HID_FEATURE_REPORT);
return ret < 0 ? ret : 0;
}
static int blink1_update_color(struct blink1_data *data)
{
u8 buf[BLINK1_CMD_SIZE] = { 1, 'n', 0, 0, 0, 0, 0, 0, 0 };
if (data->brightness) {
unsigned int coef = DIV_ROUND_CLOSEST(255, data->brightness);
buf[2] = DIV_ROUND_CLOSEST(blink1_rgb_to_r(data->rgb), coef);
buf[3] = DIV_ROUND_CLOSEST(blink1_rgb_to_g(data->rgb), coef);
buf[4] = DIV_ROUND_CLOSEST(blink1_rgb_to_b(data->rgb), coef);
}
if (data->fade) {
buf[1] = 'c';
buf[5] = (data->fade & 0xFF00) >> 8;
buf[6] = (data->fade & 0x00FF);
}
return blink1_send_command(data, buf);
}
static void blink1_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct blink1_data *data = dev_get_drvdata(led_cdev->dev->parent);
data->brightness = brightness;
if (blink1_update_color(data))
hid_err(data->hdev, "failed to update color\n");
}
static enum led_brightness blink1_led_get(struct led_classdev *led_cdev)
{
struct blink1_data *data = dev_get_drvdata(led_cdev->dev->parent);
return data->brightness;
}
static ssize_t blink1_show_rgb(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
return sprintf(buf, "%.6X\n", data->rgb);
}
static ssize_t blink1_store_rgb(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
long unsigned int rgb;
int ret;
ret = kstrtoul(buf, 16, &rgb);
if (ret)
return ret;
if (rgb > 0xFFFFFF)
return -EINVAL;
data->rgb = rgb;
ret = blink1_update_color(data);
return ret ? ret : count;
}
static ssize_t blink1_show_fade(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
return sprintf(buf, "%d\n", data->fade * 10);
}
static ssize_t blink1_store_fade(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
long unsigned int fade;
int ret;
ret = kstrtoul(buf, 10, &fade);
if (ret)
return ret;
fade = DIV_ROUND_CLOSEST(fade, 10);
if (fade > 65535)
return -EINVAL;
data->fade = fade;
return count;
}
static ssize_t blink1_show_play(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
return sprintf(buf, "%d\n", data->play);
}
static ssize_t blink1_store_play(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct blink1_data *data = dev_get_drvdata(dev->parent);
u8 cmd[BLINK1_CMD_SIZE] = { 1, 'p', 0, 0, 0, 0, 0, 0, 0 };
long unsigned int play;
int ret;
ret = kstrtoul(buf, 10, &play);
if (ret)
return ret;
data->play = !!play;
cmd[2] = data->play;
ret = blink1_send_command(data, cmd);
return ret ? ret : count;
}
static int thingm_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct blink1_data *data;
struct led_classdev *led;
char led_name[13];
int ret;
data = devm_kzalloc(&hdev->dev, sizeof(struct blink1_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
hid_set_drvdata(hdev, data);
data->hdev = hdev;
data->rgb = 0xFFFFFF;
ret = hid_parse(hdev);
if (ret)
goto error;
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret)
goto error;
led = &data->led_cdev;
snprintf(led_name, sizeof(led_name), "blink1::%s", hdev->uniq + 4);
led->name = led_name;
led->brightness_set = blink1_led_set;
led->brightness_get = blink1_led_get;
ret = led_classdev_register(&hdev->dev, led);
if (ret)
goto stop;
ret = sysfs_create_group(&led->dev->kobj, &blink1_sysfs_group);
if (ret)
goto remove_led;
return 0;
remove_led:
led_classdev_unregister(led);
stop:
hid_hw_stop(hdev);
error:
return ret;
}
static void thingm_remove(struct hid_device *hdev)
{
struct blink1_data *data = hid_get_drvdata(hdev);
struct led_classdev *led = &data->led_cdev;
sysfs_remove_group(&led->dev->kobj, &blink1_sysfs_group);
led_classdev_unregister(led);
hid_hw_stop(hdev);
}
