static __u8 *ps3remote_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
*rsize = sizeof(ps3remote_rdesc);
return ps3remote_rdesc;
}
static int ps3remote_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned int key = usage->hid & HID_USAGE;
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_BUTTON)
return -1;
switch (usage->collection_index) {
case 1:
if (key >= ARRAY_SIZE(ps3remote_keymap_joypad_buttons))
return -1;
key = ps3remote_keymap_joypad_buttons[key];
if (!key)
return -1;
break;
case 2:
if (key >= ARRAY_SIZE(ps3remote_keymap_remote_buttons))
return -1;
key = ps3remote_keymap_remote_buttons[key];
if (!key)
return -1;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
}
static __u8 *sony_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & VAIO_RDESC_CONSTANT) && *rsize >= 56 &&
rdesc[2] == 0x09 && rdesc[3] == 0x02 &&
rdesc[54] == 0x81 && rdesc[55] == 0x07) {
hid_info(hdev, "Fixing up Sony RF Receiver report descriptor\n");
rdesc[55] = 0x06;
}
if ((((sc->quirks & SIXAXIS_CONTROLLER_USB) && *rsize == 148) ||
((sc->quirks & SIXAXIS_CONTROLLER_BT) && *rsize == 149)) &&
rdesc[83] == 0x75) {
hid_info(hdev, "Fixing up Sony Sixaxis report descriptor\n");
memcpy((void *)&rdesc[83], (void *)&sixaxis_rdesc_fixup,
sizeof(sixaxis_rdesc_fixup));
} else if (sc->quirks & SIXAXIS_CONTROLLER_USB &&
*rsize > sizeof(sixaxis_rdesc_fixup2)) {
hid_info(hdev, "Sony Sixaxis clone detected. Using original report descriptor (size: %d clone; %d new)\n",
*rsize, (int)sizeof(sixaxis_rdesc_fixup2));
*rsize = sizeof(sixaxis_rdesc_fixup2);
memcpy(rdesc, &sixaxis_rdesc_fixup2, *rsize);
}
if (sc->quirks & PS3REMOTE)
return ps3remote_fixup(hdev, rdesc, rsize);
return rdesc;
}
static int sony_raw_event(struct hid_device *hdev, struct hid_report *report,
__u8 *rd, int size)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & (SIXAXIS_CONTROLLER_USB | SIXAXIS_CONTROLLER_BT)) &&
rd[0] == 0x01 && size == 49) {
swap(rd[41], rd[42]);
swap(rd[43], rd[44]);
swap(rd[45], rd[46]);
swap(rd[47], rd[48]);
}
return 0;
}
static int sony_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & BUZZ_CONTROLLER) {
unsigned int key = usage->hid & HID_USAGE;
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_BUTTON)
return -1;
switch (usage->collection_index) {
case 1:
if (key >= ARRAY_SIZE(buzz_keymap))
return -1;
key = buzz_keymap[key];
if (!key)
return -1;
break;
default:
return -1;
}
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, key);
return 1;
}
if (sc->quirks & PS3REMOTE)
return ps3remote_mapping(hdev, hi, field, usage, bit, max);
return 0;
}
static int sixaxis_usb_output_raw_report(struct hid_device *hid, __u8 *buf,
size_t count, unsigned char report_type)
{
struct usb_interface *intf = to_usb_interface(hid->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_host_interface *interface = intf->cur_altsetting;
int report_id = buf[0];
int ret;
if (report_type == HID_OUTPUT_REPORT) {
buf++;
count--;
}
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
HID_REQ_SET_REPORT,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
((report_type + 1) << 8) | report_id,
interface->desc.bInterfaceNumber, buf, count,
USB_CTRL_SET_TIMEOUT);
if (ret > 0 && report_type == HID_OUTPUT_REPORT)
ret++;
return ret;
}
static int sixaxis_set_operational_usb(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
__u16 ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
int ret;
char *buf = kmalloc(18, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
HID_REQ_GET_REPORT,
USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE,
(3 << 8) | 0xf2, ifnum, buf, 17,
USB_CTRL_GET_TIMEOUT);
if (ret < 0)
hid_err(hdev, "can't set operational mode\n");
kfree(buf);
return ret;
}
static int sixaxis_set_operational_bt(struct hid_device *hdev)
{
unsigned char buf[] = { 0xf4, 0x42, 0x03, 0x00, 0x00 };
return hdev->hid_output_raw_report(hdev, buf, sizeof(buf), HID_FEATURE_REPORT);
}
static void buzz_set_leds(struct hid_device *hdev, int leds)
{
struct list_head *report_list =
&hdev->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next,
struct hid_report, list);
__s32 *value = report->field[0]->value;
value[0] = 0x00;
value[1] = (leds & 1) ? 0xff : 0x00;
value[2] = (leds & 2) ? 0xff : 0x00;
value[3] = (leds & 4) ? 0xff : 0x00;
value[4] = (leds & 8) ? 0xff : 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static void buzz_led_set_brightness(struct led_classdev *led,
enum led_brightness value)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct sony_sc *drv_data;
struct buzz_extra *buzz;
int n;
drv_data = hid_get_drvdata(hdev);
if (!drv_data || !drv_data->extra) {
hid_err(hdev, "No device data\n");
return;
}
buzz = drv_data->extra;
for (n = 0; n < 4; n++) {
if (led == buzz->leds[n]) {
int on = !! (buzz->led_state & (1 << n));
if (value == LED_OFF && on) {
buzz->led_state &= ~(1 << n);
buzz_set_leds(hdev, buzz->led_state);
} else if (value != LED_OFF && !on) {
buzz->led_state |= (1 << n);
buzz_set_leds(hdev, buzz->led_state);
}
break;
}
}
}
static enum led_brightness buzz_led_get_brightness(struct led_classdev *led)
{
struct device *dev = led->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct sony_sc *drv_data;
struct buzz_extra *buzz;
int n;
int on = 0;
drv_data = hid_get_drvdata(hdev);
if (!drv_data || !drv_data->extra) {
hid_err(hdev, "No device data\n");
return LED_OFF;
}
buzz = drv_data->extra;
for (n = 0; n < 4; n++) {
if (led == buzz->leds[n]) {
on = !! (buzz->led_state & (1 << n));
break;
}
}
return on ? LED_FULL : LED_OFF;
}
static int buzz_init(struct hid_device *hdev)
{
struct sony_sc *drv_data;
struct buzz_extra *buzz;
int n, ret = 0;
struct led_classdev *led;
size_t name_sz;
char *name;
drv_data = hid_get_drvdata(hdev);
BUG_ON(!(drv_data->quirks & BUZZ_CONTROLLER));
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 0, 0, 7))
return -ENODEV;
buzz = kzalloc(sizeof(*buzz), GFP_KERNEL);
if (!buzz) {
hid_err(hdev, "Insufficient memory, cannot allocate driver data\n");
return -ENOMEM;
}
drv_data->extra = buzz;
buzz_set_leds(hdev, 0x00);
name_sz = strlen(dev_name(&hdev->dev)) + strlen("::buzz#") + 1;
for (n = 0; n < 4; n++) {
led = kzalloc(sizeof(struct led_classdev) + name_sz, GFP_KERNEL);
if (!led) {
hid_err(hdev, "Couldn't allocate memory for LED %d\n", n);
goto error_leds;
}
name = (void *)(&led[1]);
snprintf(name, name_sz, "%s::buzz%d", dev_name(&hdev->dev), n + 1);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = buzz_led_get_brightness;
led->brightness_set = buzz_led_set_brightness;
if (led_classdev_register(&hdev->dev, led)) {
hid_err(hdev, "Failed to register LED %d\n", n);
kfree(led);
goto error_leds;
}
buzz->leds[n] = led;
}
return ret;
error_leds:
for (n = 0; n < 4; n++) {
led = buzz->leds[n];
buzz->leds[n] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
kfree(drv_data->extra);
drv_data->extra = NULL;
return ret;
}
static void buzz_remove(struct hid_device *hdev)
{
struct sony_sc *drv_data;
struct buzz_extra *buzz;
struct led_classdev *led;
int n;
drv_data = hid_get_drvdata(hdev);
BUG_ON(!(drv_data->quirks & BUZZ_CONTROLLER));
buzz = drv_data->extra;
for (n = 0; n < 4; n++) {
led = buzz->leds[n];
buzz->leds[n] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
kfree(drv_data->extra);
drv_data->extra = NULL;
}
static int sony_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
unsigned long quirks = id->driver_data;
struct sony_sc *sc;
unsigned int connect_mask = HID_CONNECT_DEFAULT;
sc = devm_kzalloc(&hdev->dev, sizeof(*sc), GFP_KERNEL);
if (sc == NULL) {
hid_err(hdev, "can't alloc sony descriptor\n");
return -ENOMEM;
}
sc->quirks = quirks;
hid_set_drvdata(hdev, sc);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
return ret;
}
if (sc->quirks & VAIO_RDESC_CONSTANT)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
else if (sc->quirks & SIXAXIS_CONTROLLER_USB)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
else if (sc->quirks & SIXAXIS_CONTROLLER_BT)
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
ret = hid_hw_start(hdev, connect_mask);
if (ret) {
hid_err(hdev, "hw start failed\n");
return ret;
}
if (sc->quirks & SIXAXIS_CONTROLLER_USB) {
hdev->hid_output_raw_report = sixaxis_usb_output_raw_report;
ret = sixaxis_set_operational_usb(hdev);
}
else if (sc->quirks & SIXAXIS_CONTROLLER_BT)
ret = sixaxis_set_operational_bt(hdev);
else if (sc->quirks & BUZZ_CONTROLLER)
ret = buzz_init(hdev);
else
ret = 0;
if (ret < 0)
goto err_stop;
return 0;
err_stop:
hid_hw_stop(hdev);
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if (sc->quirks & BUZZ_CONTROLLER)
buzz_remove(hdev);
hid_hw_stop(hdev);
}
