static int hid_lg4ff_play(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
int x;
#define CLAMP(x) if (x < 0) x = 0; if (x > 0xff) x = 0xff
switch (effect->type) {
case FF_CONSTANT:
x = effect->u.ramp.start_level + 0x80;
CLAMP(x);
report->field[0]->value[0] = 0x11;
report->field[0]->value[1] = 0x08;
report->field[0]->value[2] = x;
report->field[0]->value[3] = 0x80;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
break;
}
return 0;
}
static void hid_lg4ff_set_autocenter_default(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
report->field[0]->value[0] = 0xfe;
report->field[0]->value[1] = 0x0d;
report->field[0]->value[2] = magnitude >> 13;
report->field[0]->value[3] = magnitude >> 13;
report->field[0]->value[4] = magnitude >> 8;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
static void hid_lg4ff_set_autocenter_ffex(struct input_dev *dev, u16 magnitude)
{
struct hid_device *hid = input_get_drvdata(dev);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
magnitude = magnitude * 90 / 65535;
report->field[0]->value[0] = 0xfe;
report->field[0]->value[1] = 0x03;
report->field[0]->value[2] = magnitude >> 14;
report->field[0]->value[3] = magnitude >> 14;
report->field[0]->value[4] = magnitude;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
static void hid_lg4ff_set_range_g25(struct hid_device *hid, u16 range)
{
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
dbg_hid("G25/G27/DFGT: setting range to %u\n", range);
report->field[0]->value[0] = 0xf8;
report->field[0]->value[1] = 0x81;
report->field[0]->value[2] = range & 0x00ff;
report->field[0]->value[3] = (range & 0xff00) >> 8;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
static void hid_lg4ff_set_range_dfp(struct hid_device *hid, __u16 range)
{
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
int start_left, start_right, full_range;
dbg_hid("Driving Force Pro: setting range to %u\n", range);
report->field[0]->value[0] = 0xf8;
report->field[0]->value[1] = 0x00;
report->field[0]->value[2] = 0x00;
report->field[0]->value[3] = 0x00;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
if (range > 200) {
report->field[0]->value[1] = 0x03;
full_range = 900;
} else {
report->field[0]->value[1] = 0x02;
full_range = 200;
}
usbhid_submit_report(hid, report, USB_DIR_OUT);
report->field[0]->value[0] = 0x81;
report->field[0]->value[1] = 0x0b;
report->field[0]->value[2] = 0x00;
report->field[0]->value[3] = 0x00;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
if (range == 200 || range == 900) {
usbhid_submit_report(hid, report, USB_DIR_OUT);
return;
}
start_left = (((full_range - range + 1) * 2047) / full_range);
start_right = 0xfff - start_left;
report->field[0]->value[2] = start_left >> 4;
report->field[0]->value[3] = start_right >> 4;
report->field[0]->value[4] = 0xff;
report->field[0]->value[5] = (start_right & 0xe) << 4 | (start_left & 0xe);
report->field[0]->value[6] = 0xff;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
static void hid_lg4ff_switch_native(struct hid_device *hid, const struct lg4ff_native_cmd *cmd)
{
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
__u8 i, j;
j = 0;
while (j < 7*cmd->cmd_num) {
for (i = 0; i < 7; i++)
report->field[0]->value[i] = cmd->cmd[j++];
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
}
static ssize_t lg4ff_range_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
size_t count;
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
count = scnprintf(buf, PAGE_SIZE, "%u\n", entry->range);
return count;
}
static ssize_t lg4ff_range_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct hid_device *hid = to_hid_device(dev);
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
__u16 range = simple_strtoul(buf, NULL, 10);
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Private driver data not found!\n");
return 0;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found!\n");
return 0;
}
if (range == 0)
range = entry->max_range;
if (entry->set_range != NULL && range >= entry->min_range && range <= entry->max_range) {
entry->set_range(hid, range);
entry->range = range;
}
return count;
}
static void lg4ff_set_leds(struct hid_device *hid, __u8 leds)
{
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct hid_report *report = list_entry(report_list->next, struct hid_report, list);
report->field[0]->value[0] = 0xf8;
report->field[0]->value[1] = 0x12;
report->field[0]->value[2] = leds;
report->field[0]->value[3] = 0x00;
report->field[0]->value[4] = 0x00;
report->field[0]->value[5] = 0x00;
report->field[0]->value[6] = 0x00;
usbhid_submit_report(hid, report, USB_DIR_OUT);
}
static void lg4ff_led_set_brightness(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = container_of(dev, struct hid_device, dev);
struct lg_drv_data *drv_data = (struct lg_drv_data *)hid_get_drvdata(hid);
struct lg4ff_device_entry *entry;
int i, state = 0;
if (!drv_data) {
hid_err(hid, "Device data not found.");
return;
}
entry = (struct lg4ff_device_entry *)drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found.");
return;
}
for (i = 0; i < 5; i++) {
if (led_cdev != entry->led[i])
continue;
state = (entry->led_state >> i) & 1;
if (value == LED_OFF && state) {
entry->led_state &= ~(1 << i);
lg4ff_set_leds(hid, entry->led_state);
} else if (value != LED_OFF && !state) {
entry->led_state |= 1 << i;
lg4ff_set_leds(hid, entry->led_state);
}
break;
}
}
static enum led_brightness lg4ff_led_get_brightness(struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hid = container_of(dev, struct hid_device, dev);
struct lg_drv_data *drv_data = (struct lg_drv_data *)hid_get_drvdata(hid);
struct lg4ff_device_entry *entry;
int i, value = 0;
if (!drv_data) {
hid_err(hid, "Device data not found.");
return LED_OFF;
}
entry = (struct lg4ff_device_entry *)drv_data->device_props;
if (!entry) {
hid_err(hid, "Device properties not found.");
return LED_OFF;
}
for (i = 0; i < 5; i++)
if (led_cdev == entry->led[i]) {
value = (entry->led_state >> i) & 1;
break;
}
return value ? LED_FULL : LED_OFF;
}
int lg4ff_init(struct hid_device *hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
struct hid_report *report;
struct hid_field *field;
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
struct usb_device_descriptor *udesc;
int error, i, j;
__u16 bcdDevice, rev_maj, rev_min;
if (list_empty(report_list)) {
hid_err(hid, "No output report found\n");
return -1;
}
report = list_entry(report_list->next, struct hid_report, list);
if (!report) {
hid_err(hid, "NULL output report\n");
return -1;
}
field = report->field[0];
if (!field) {
hid_err(hid, "NULL field\n");
return -1;
}
for (i = 0; i < ARRAY_SIZE(lg4ff_devices); i++) {
if (hid->product == lg4ff_devices[i].product_id) {
dbg_hid("Found compatible device, product ID %04X\n", lg4ff_devices[i].product_id);
break;
}
}
if (i == ARRAY_SIZE(lg4ff_devices)) {
hid_err(hid, "Device is not supported by lg4ff driver. If you think it should be, consider reporting a bug to"
"LKML, Simon Wood <simon@mungewell.org> or Michal Maly <madcatxster@gmail.com>\n");
return -1;
}
udesc = &(hid_to_usb_dev(hid)->descriptor);
if (!udesc) {
hid_err(hid, "NULL USB device descriptor\n");
return -1;
}
bcdDevice = le16_to_cpu(udesc->bcdDevice);
rev_maj = bcdDevice >> 8;
rev_min = bcdDevice & 0xff;
if (lg4ff_devices[i].product_id == USB_DEVICE_ID_LOGITECH_WHEEL) {
dbg_hid("Generic wheel detected, can it do native?\n");
dbg_hid("USB revision: %2x.%02x\n", rev_maj, rev_min);
for (j = 0; j < ARRAY_SIZE(lg4ff_revs); j++) {
if (lg4ff_revs[j].rev_maj == rev_maj && lg4ff_revs[j].rev_min == rev_min) {
hid_lg4ff_switch_native(hid, lg4ff_revs[j].command);
hid_info(hid, "Switched to native mode\n");
}
}
}
for (j = 0; lg4ff_devices[i].ff_effects[j] >= 0; j++)
set_bit(lg4ff_devices[i].ff_effects[j], dev->ffbit);
error = input_ff_create_memless(dev, NULL, hid_lg4ff_play);
if (error)
return error;
if (test_bit(FF_AUTOCENTER, dev->ffbit)) {
if(rev_maj == FFEX_REV_MAJ && rev_min == FFEX_REV_MIN)
dev->ff->set_autocenter = hid_lg4ff_set_autocenter_ffex;
else
dev->ff->set_autocenter = hid_lg4ff_set_autocenter_default;
dev->ff->set_autocenter(dev, 0);
}
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Cannot add device, private driver data not allocated\n");
return -1;
}
entry = kzalloc(sizeof(struct lg4ff_device_entry), GFP_KERNEL);
if (!entry) {
hid_err(hid, "Cannot add device, insufficient memory to allocate device properties.\n");
return -ENOMEM;
}
drv_data->device_props = entry;
entry->min_range = lg4ff_devices[i].min_range;
entry->max_range = lg4ff_devices[i].max_range;
entry->set_range = lg4ff_devices[i].set_range;
error = device_create_file(&hid->dev, &dev_attr_range);
if (error)
return error;
dbg_hid("sysfs interface created\n");
entry->range = entry->max_range;
if (entry->set_range != NULL)
entry->set_range(hid, entry->range);
#ifdef CONFIG_LEDS_CLASS
entry->led_state = 0;
for (j = 0; j < 5; j++)
entry->led[j] = NULL;
if (lg4ff_devices[i].product_id == USB_DEVICE_ID_LOGITECH_G27_WHEEL) {
struct led_classdev *led;
size_t name_sz;
char *name;
lg4ff_set_leds(hid, 0);
name_sz = strlen(dev_name(&hid->dev)) + 8;
for (j = 0; j < 5; j++) {
led = kzalloc(sizeof(struct led_classdev)+name_sz, GFP_KERNEL);
if (!led) {
hid_err(hid, "can't allocate memory for LED %d\n", j);
goto err;
}
name = (void *)(&led[1]);
snprintf(name, name_sz, "%s::RPM%d", dev_name(&hid->dev), j+1);
led->name = name;
led->brightness = 0;
led->max_brightness = 1;
led->brightness_get = lg4ff_led_get_brightness;
led->brightness_set = lg4ff_led_set_brightness;
entry->led[j] = led;
error = led_classdev_register(&hid->dev, led);
if (error) {
hid_err(hid, "failed to register LED %d. Aborting.\n", j);
err:
for (j = 0; j < 5; j++) {
led = entry->led[j];
entry->led[j] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
goto out;
}
}
}
out:
#endif
hid_info(hid, "Force feedback support for Logitech Gaming Wheels\n");
return 0;
}
int lg4ff_deinit(struct hid_device *hid)
{
struct lg4ff_device_entry *entry;
struct lg_drv_data *drv_data;
device_remove_file(&hid->dev, &dev_attr_range);
drv_data = hid_get_drvdata(hid);
if (!drv_data) {
hid_err(hid, "Error while deinitializing device, no private driver data.\n");
return -1;
}
entry = drv_data->device_props;
if (!entry) {
hid_err(hid, "Error while deinitializing device, no device properties data.\n");
return -1;
}
#ifdef CONFIG_LEDS_CLASS
{
int j;
struct led_classdev *led;
for (j = 0; j < 5; j++) {
led = entry->led[j];
entry->led[j] = NULL;
if (!led)
continue;
led_classdev_unregister(led);
kfree(led);
}
}
#endif
kfree(entry);
dbg_hid("Device successfully unregistered\n");
return 0;
}
