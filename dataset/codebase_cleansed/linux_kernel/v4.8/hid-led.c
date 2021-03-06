static int hidled_send(struct hidled_device *ldev, __u8 *buf)
{
int ret;
mutex_lock(&ldev->lock);
if (ldev->config->report_type == RAW_REQUEST)
ret = hid_hw_raw_request(ldev->hdev, buf[0], buf,
ldev->config->report_size,
HID_FEATURE_REPORT,
HID_REQ_SET_REPORT);
else if (ldev->config->report_type == OUTPUT_REPORT)
ret = hid_hw_output_report(ldev->hdev, buf,
ldev->config->report_size);
else
ret = -EINVAL;
mutex_unlock(&ldev->lock);
if (ret < 0)
return ret;
return ret == ldev->config->report_size ? 0 : -EMSGSIZE;
}
static int hidled_recv(struct hidled_device *ldev, __u8 *buf)
{
int ret;
if (ldev->config->report_type != RAW_REQUEST)
return -EINVAL;
mutex_lock(&ldev->lock);
ret = hid_hw_raw_request(ldev->hdev, buf[0], buf,
ldev->config->report_size,
HID_FEATURE_REPORT,
HID_REQ_SET_REPORT);
if (ret < 0)
goto err;
ret = hid_hw_raw_request(ldev->hdev, buf[0], buf,
ldev->config->report_size,
HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
err:
mutex_unlock(&ldev->lock);
return ret < 0 ? ret : 0;
}
static u8 riso_kagaku_index(struct hidled_rgb *rgb)
{
enum led_brightness r, g, b;
r = rgb->red.cdev.brightness;
g = rgb->green.cdev.brightness;
b = rgb->blue.cdev.brightness;
if (riso_kagaku_switch_green_blue)
return RISO_KAGAKU_IX(r, b, g);
else
return RISO_KAGAKU_IX(r, g, b);
}
static int riso_kagaku_write(struct led_classdev *cdev, enum led_brightness br)
{
struct hidled_led *led = to_hidled_led(cdev);
struct hidled_rgb *rgb = led->rgb;
__u8 buf[MAX_REPORT_SIZE] = {};
buf[1] = riso_kagaku_index(rgb);
return hidled_send(rgb->ldev, buf);
}
static int dream_cheeky_write(struct led_classdev *cdev, enum led_brightness br)
{
struct hidled_led *led = to_hidled_led(cdev);
struct hidled_rgb *rgb = led->rgb;
__u8 buf[MAX_REPORT_SIZE] = {};
buf[1] = rgb->red.cdev.brightness;
buf[2] = rgb->green.cdev.brightness;
buf[3] = rgb->blue.cdev.brightness;
buf[7] = 0x1a;
buf[8] = 0x05;
return hidled_send(rgb->ldev, buf);
}
static int dream_cheeky_init(struct hidled_device *ldev)
{
__u8 buf[MAX_REPORT_SIZE] = {};
buf[1] = 0x1f;
buf[2] = 0x02;
buf[4] = 0x5f;
buf[7] = 0x1a;
buf[8] = 0x03;
return hidled_send(ldev, buf);
}
static int _thingm_write(struct led_classdev *cdev, enum led_brightness br,
u8 offset)
{
struct hidled_led *led = to_hidled_led(cdev);
__u8 buf[MAX_REPORT_SIZE] = { 1, 'c' };
buf[2] = led->rgb->red.cdev.brightness;
buf[3] = led->rgb->green.cdev.brightness;
buf[4] = led->rgb->blue.cdev.brightness;
buf[7] = led->rgb->num + offset;
return hidled_send(led->rgb->ldev, buf);
}
static int thingm_write_v1(struct led_classdev *cdev, enum led_brightness br)
{
return _thingm_write(cdev, br, 0);
}
static int thingm_write(struct led_classdev *cdev, enum led_brightness br)
{
return _thingm_write(cdev, br, 1);
}
static int thingm_init(struct hidled_device *ldev)
{
__u8 buf[MAX_REPORT_SIZE] = { 1, 'v' };
int ret;
ret = hidled_recv(ldev, buf);
if (ret)
return ret;
if (buf[3] == '1')
ldev->config = &hidled_config_thingm_v1;
return 0;
}
static inline int delcom_get_lednum(const struct hidled_led *led)
{
if (led == &led->rgb->red)
return DELCOM_RED_LED;
else if (led == &led->rgb->green)
return DELCOM_GREEN_LED;
else
return DELCOM_BLUE_LED;
}
static int delcom_enable_led(struct hidled_led *led)
{
union delcom_packet dp = { .tx.major_cmd = 101, .tx.minor_cmd = 12 };
dp.tx.data_lsb = 1 << delcom_get_lednum(led);
dp.tx.data_msb = 0;
return hidled_send(led->rgb->ldev, dp.data);
}
static int delcom_set_pwm(struct hidled_led *led)
{
union delcom_packet dp = { .tx.major_cmd = 101, .tx.minor_cmd = 34 };
dp.tx.data_lsb = delcom_get_lednum(led);
dp.tx.data_msb = led->cdev.brightness;
return hidled_send(led->rgb->ldev, dp.data);
}
static int delcom_write(struct led_classdev *cdev, enum led_brightness br)
{
struct hidled_led *led = to_hidled_led(cdev);
int ret;
ret = delcom_enable_led(led);
if (ret)
return ret;
return delcom_set_pwm(led);
}
static int delcom_init(struct hidled_device *ldev)
{
union delcom_packet dp = { .rx.cmd = 104 };
int ret;
ret = hidled_recv(ldev, dp.data);
if (ret)
return ret;
return le16_to_cpu(dp.fw.family_code) == 2 ? 0 : -ENODEV;
}
static int luxafor_write(struct led_classdev *cdev, enum led_brightness br)
{
struct hidled_led *led = to_hidled_led(cdev);
__u8 buf[MAX_REPORT_SIZE] = { [1] = 1 };
buf[2] = led->rgb->num + 1;
buf[3] = led->rgb->red.cdev.brightness;
buf[4] = led->rgb->green.cdev.brightness;
buf[5] = led->rgb->blue.cdev.brightness;
return hidled_send(led->rgb->ldev, buf);
}
static int hidled_init_led(struct hidled_led *led, const char *color_name,
struct hidled_rgb *rgb, unsigned int minor)
{
const struct hidled_config *config = rgb->ldev->config;
if (config->num_leds > 1)
snprintf(led->name, sizeof(led->name), "%s%u:%s:led%u",
config->short_name, minor, color_name, rgb->num);
else
snprintf(led->name, sizeof(led->name), "%s%u:%s",
config->short_name, minor, color_name);
led->cdev.name = led->name;
led->cdev.max_brightness = config->max_brightness;
led->cdev.brightness_set_blocking = config->write;
led->cdev.flags = LED_HW_PLUGGABLE;
led->rgb = rgb;
return devm_led_classdev_register(&rgb->ldev->hdev->dev, &led->cdev);
}
static int hidled_init_rgb(struct hidled_rgb *rgb, unsigned int minor)
{
int ret;
ret = hidled_init_led(&rgb->red, "red", rgb, minor);
if (ret)
return ret;
ret = hidled_init_led(&rgb->green, "green", rgb, minor);
if (ret)
return ret;
return hidled_init_led(&rgb->blue, "blue", rgb, minor);
}
static int hidled_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct hidled_device *ldev;
unsigned int minor;
int ret, i;
ldev = devm_kzalloc(&hdev->dev, sizeof(*ldev), GFP_KERNEL);
if (!ldev)
return -ENOMEM;
ret = hid_parse(hdev);
if (ret)
return ret;
ldev->hdev = hdev;
mutex_init(&ldev->lock);
for (i = 0; !ldev->config && i < ARRAY_SIZE(hidled_configs); i++)
if (hidled_configs[i].type == id->driver_data)
ldev->config = &hidled_configs[i];
if (!ldev->config)
return -EINVAL;
if (ldev->config->init) {
ret = ldev->config->init(ldev);
if (ret)
return ret;
}
ldev->rgb = devm_kcalloc(&hdev->dev, ldev->config->num_leds,
sizeof(struct hidled_rgb), GFP_KERNEL);
if (!ldev->rgb)
return -ENOMEM;
ret = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (ret)
return ret;
minor = ((struct hidraw *) hdev->hidraw)->minor;
for (i = 0; i < ldev->config->num_leds; i++) {
ldev->rgb[i].ldev = ldev;
ldev->rgb[i].num = i;
ret = hidled_init_rgb(&ldev->rgb[i], minor);
if (ret) {
hid_hw_stop(hdev);
return ret;
}
}
hid_info(hdev, "%s initialized\n", ldev->config->name);
return 0;
}
