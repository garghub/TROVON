static void steelseries_srws1_set_leds(struct hid_device *hdev, __u16 leds)
{
struct list_head *report_list = &hdev->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
__s32 *value = report->field[0]->value;
value[0] = 0x40;
value[1] = leds & 0xFF;
value[2] = leds >> 8;
value[3] = 0x00;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
value[7] = 0x00;
value[8] = 0x00;
value[9] = 0x00;
value[10] = 0x00;
value[11] = 0x00;
value[12] = 0x00;
value[13] = 0x00;
value[14] = 0x00;
value[15] = 0x00;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static void steelseries_srws1_led_all_set_brightness(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct steelseries_srws1_data *drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Device data not found.");
return;
}
if (value == LED_OFF)
drv_data->led_state = 0;
else
drv_data->led_state = (1 << (SRWS1_NUMBER_LEDS + 1)) - 1;
steelseries_srws1_set_leds(hid, drv_data->led_state);
}
static enum led_brightness steelseries_srws1_led_all_get_brightness(struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct steelseries_srws1_data *drv_data;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Device data not found.");
return LED_OFF;
}
return (drv_data->led_state >> SRWS1_NUMBER_LEDS) ? LED_FULL : LED_OFF;
}
static void steelseries_srws1_led_set_brightness(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct steelseries_srws1_data *drv_data = hid_get_drvdata(hid);
int i, state = 0;
if (!drv_data) {
hid_err(hid, "Device data not found.");
return;
}
for (i = 0; i < SRWS1_NUMBER_LEDS; i++) {
if (led_cdev != drv_data->led[i])
continue;
state = (drv_data->led_state >> i) & 1;
if (value == LED_OFF && state) {
drv_data->led_state &= ~(1 << i);
steelseries_srws1_set_leds(hid, drv_data->led_state);
} else if (value != LED_OFF && !state) {
drv_data->led_state |= 1 << i;
steelseries_srws1_set_leds(hid, drv_data->led_state);
}
break;
}
}
static enum led_brightness steelseries_srws1_led_get_brightness(struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = to_hid_device(dev);
struct steelseries_srws1_data *drv_data;
int i, value = 0;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Device data not found.");
return LED_OFF;
}
for (i = 0; i < SRWS1_NUMBER_LEDS; i++)
if (led_cdev == drv_data->led[i]) {
value = (drv_data->led_state >> i) & 1;
break;
}
return value ? LED_FULL : LED_OFF;
}
static int steelseries_srws1_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret, i;
struct led_classdev *led;
size_t name_sz;
char *name;
struct steelseries_srws1_data *drv_data = kzalloc(sizeof(*drv_data), GFP_KERNEL);
if (drv_data == NULL) {
hid_err(hdev, "can't alloc SRW-S1 memory\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, drv_data);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 0, 0, 16)) {
ret = -ENODEV;
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
drv_data->led_state = 0;
for (i = 0; i < SRWS1_NUMBER_LEDS + 1; i++)
drv_data->led[i] = NULL;
steelseries_srws1_set_leds(hdev, 0);
name_sz = strlen(hdev->uniq) + 16;
led = kzalloc(sizeof(struct led_classdev)+name_sz, GFP_KERNEL);
if (!led) {
hid_err(hdev, "can't allocate memory for LED ALL\n");
goto err_led;
}
name = (void *)(&led[1]);
snprintf(name, name_sz, "SRWS1::%s::RPMALL", hdev->uniq);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = steelseries_srws1_led_all_get_brightness;
led->brightness_set = steelseries_srws1_led_all_set_brightness;
drv_data->led[SRWS1_NUMBER_LEDS] = led;
ret = led_classdev_register(&hdev->dev, led);
if (ret)
goto err_led;
for (i = 0; i < SRWS1_NUMBER_LEDS; i++) {
led = kzalloc(sizeof(struct led_classdev)+name_sz, GFP_KERNEL);
if (!led) {
hid_err(hdev, "can't allocate memory for LED %d\n", i);
goto err_led;
}
name = (void *)(&led[1]);
snprintf(name, name_sz, "SRWS1::%s::RPM%d", hdev->uniq, i+1);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = steelseries_srws1_led_get_brightness;
led->brightness_set = steelseries_srws1_led_set_brightness;
drv_data->led[i] = led;
ret = led_classdev_register(&hdev->dev, led);
if (ret) {
hid_err(hdev, "failed to register LED %d. Aborting.\n", i);
err_led:
for (i = 0; i < SRWS1_NUMBER_LEDS + 1; i++) {
led = drv_data->led[i];
drv_data->led[i] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
goto out;
}
}
out:
return 0;
err_free:
kfree(drv_data);
return ret;
}
static void steelseries_srws1_remove(struct hid_device *hdev)
{
int i;
struct led_classdev *led;
struct steelseries_srws1_data *drv_data = hid_get_drvdata(hdev);
if (drv_data) {
for (i = 0; i < SRWS1_NUMBER_LEDS + 1; i++) {
led = drv_data->led[i];
drv_data->led[i] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
}
hid_hw_stop(hdev);
kfree(drv_data);
return;
}
static __u8 *steelseries_srws1_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 115 && rdesc[11] == 0x02 && rdesc[13] == 0xc8
&& rdesc[29] == 0xbb && rdesc[40] == 0xc5) {
hid_info(hdev, "Fixing up Steelseries SRW-S1 report descriptor\n");
rdesc = steelseries_srws1_rdesc_fixed;
*rsize = sizeof(steelseries_srws1_rdesc_fixed);
}
return rdesc;
}
