static int thingm_send(struct thingm_device *tdev, u8 buf[REPORT_SIZE])
{
int ret;
hid_dbg(tdev->hdev, "-> %d %c %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx\n",
buf[0], buf[1], buf[2], buf[3], buf[4],
buf[5], buf[6], buf[7], buf[8]);
mutex_lock(&tdev->lock);
ret = hid_hw_raw_request(tdev->hdev, buf[0], buf, REPORT_SIZE,
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
mutex_unlock(&tdev->lock);
return ret < 0 ? ret : 0;
}
static int thingm_recv(struct thingm_device *tdev, u8 buf[REPORT_SIZE])
{
int ret;
mutex_lock(&tdev->lock);
ret = hid_hw_raw_request(tdev->hdev, buf[0], buf, REPORT_SIZE,
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
if (ret < 0)
goto err;
ret = hid_hw_raw_request(tdev->hdev, buf[0], buf, REPORT_SIZE,
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret < 0)
goto err;
ret = 0;
hid_dbg(tdev->hdev, "<- %d %c %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx\n",
buf[0], buf[1], buf[2], buf[3], buf[4],
buf[5], buf[6], buf[7], buf[8]);
err:
mutex_unlock(&tdev->lock);
return ret;
}
static int thingm_version(struct thingm_device *tdev)
{
u8 buf[REPORT_SIZE] = { REPORT_ID, 'v', 0, 0, 0, 0, 0, 0, 0 };
int err;
err = thingm_recv(tdev, buf);
if (err)
return err;
tdev->version.major = buf[3];
tdev->version.minor = buf[4];
return 0;
}
static int thingm_write_color(struct thingm_rgb *rgb)
{
u8 buf[REPORT_SIZE] = { REPORT_ID, 'c', 0, 0, 0, 0, 0, rgb->num, 0 };
buf[2] = rgb->red.ldev.brightness;
buf[3] = rgb->green.ldev.brightness;
buf[4] = rgb->blue.ldev.brightness;
return thingm_send(rgb->tdev, buf);
}
static int thingm_led_set(struct led_classdev *ldev,
enum led_brightness brightness)
{
struct thingm_led *led = container_of(ldev, struct thingm_led, ldev);
return thingm_write_color(led->rgb);
}
static int thingm_init_led(struct thingm_led *led, const char *color_name,
struct thingm_rgb *rgb, int minor)
{
snprintf(led->name, sizeof(led->name), "thingm%d:%s:led%d",
minor, color_name, rgb->num);
led->ldev.name = led->name;
led->ldev.max_brightness = 255;
led->ldev.brightness_set_blocking = thingm_led_set;
led->ldev.flags = LED_HW_PLUGGABLE;
led->rgb = rgb;
return devm_led_classdev_register(&rgb->tdev->hdev->dev, &led->ldev);
}
static int thingm_init_rgb(struct thingm_rgb *rgb)
{
const int minor = ((struct hidraw *) rgb->tdev->hdev->hidraw)->minor;
int err;
err = thingm_init_led(&rgb->red, "red", rgb, minor);
if (err)
return err;
err = thingm_init_led(&rgb->green, "green", rgb, minor);
if (err)
return err;
return thingm_init_led(&rgb->blue, "blue", rgb, minor);
}
static int thingm_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
struct thingm_device *tdev;
int i, err;
tdev = devm_kzalloc(&hdev->dev, sizeof(struct thingm_device),
GFP_KERNEL);
if (!tdev)
return -ENOMEM;
tdev->hdev = hdev;
hid_set_drvdata(hdev, tdev);
err = hid_parse(hdev);
if (err)
return err;
mutex_init(&tdev->lock);
err = thingm_version(tdev);
if (err)
return err;
hid_dbg(hdev, "firmware version: %c.%c\n",
tdev->version.major, tdev->version.minor);
for (i = 0; i < ARRAY_SIZE(thingm_fwinfo) && !tdev->fwinfo; ++i)
if (thingm_fwinfo[i].major == tdev->version.major)
tdev->fwinfo = &thingm_fwinfo[i];
if (!tdev->fwinfo) {
hid_err(hdev, "unsupported firmware %c\n", tdev->version.major);
return -ENODEV;
}
tdev->rgb = devm_kzalloc(&hdev->dev,
sizeof(struct thingm_rgb) * tdev->fwinfo->numrgb,
GFP_KERNEL);
if (!tdev->rgb)
return -ENOMEM;
err = hid_hw_start(hdev, HID_CONNECT_HIDRAW);
if (err)
return err;
for (i = 0; i < tdev->fwinfo->numrgb; ++i) {
struct thingm_rgb *rgb = tdev->rgb + i;
rgb->tdev = tdev;
rgb->num = tdev->fwinfo->first + i;
err = thingm_init_rgb(rgb);
if (err) {
hid_hw_stop(hdev);
return err;
}
}
return 0;
}
