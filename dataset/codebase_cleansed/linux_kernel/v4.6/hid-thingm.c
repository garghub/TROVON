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
int ret;
ret = thingm_write_color(led->rgb);
if (ret)
hid_err(led->rgb->tdev->hdev, "failed to write color\n");
return ret;
}
static int thingm_init_rgb(struct thingm_rgb *rgb)
{
const int minor = ((struct hidraw *) rgb->tdev->hdev->hidraw)->minor;
int err;
snprintf(rgb->red.name, sizeof(rgb->red.name),
"thingm%d:red:led%d", minor, rgb->num);
rgb->red.ldev.name = rgb->red.name;
rgb->red.ldev.max_brightness = 255;
rgb->red.ldev.brightness_set_blocking = thingm_led_set;
rgb->red.rgb = rgb;
err = devm_led_classdev_register(&rgb->tdev->hdev->dev,
&rgb->red.ldev);
if (err)
return err;
snprintf(rgb->green.name, sizeof(rgb->green.name),
"thingm%d:green:led%d", minor, rgb->num);
rgb->green.ldev.name = rgb->green.name;
rgb->green.ldev.max_brightness = 255;
rgb->green.ldev.brightness_set_blocking = thingm_led_set;
rgb->green.rgb = rgb;
err = devm_led_classdev_register(&rgb->tdev->hdev->dev,
&rgb->green.ldev);
if (err)
return err;
snprintf(rgb->blue.name, sizeof(rgb->blue.name),
"thingm%d:blue:led%d", minor, rgb->num);
rgb->blue.ldev.name = rgb->blue.name;
rgb->blue.ldev.max_brightness = 255;
rgb->blue.ldev.brightness_set_blocking = thingm_led_set;
rgb->blue.rgb = rgb;
err = devm_led_classdev_register(&rgb->tdev->hdev->dev,
&rgb->blue.ldev);
return err;
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
