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
struct lg4ff_device_entry *uninitialized_var(entry);
struct list_head *h;
struct hid_device *hid = to_hid_device(dev);
size_t count;
list_for_each(h, &device_list.list) {
entry = list_entry(h, struct lg4ff_device_entry, list);
if (strcmp(entry->device_id, (&hid->dev)->kobj.name) == 0)
break;
}
if (h == &device_list.list) {
dbg_hid("Device not found!");
return 0;
}
count = scnprintf(buf, PAGE_SIZE, "%u\n", entry->range);
return count;
}
static ssize_t lg4ff_range_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct lg4ff_device_entry *uninitialized_var(entry);
struct list_head *h;
struct hid_device *hid = to_hid_device(dev);
__u16 range = simple_strtoul(buf, NULL, 10);
list_for_each(h, &device_list.list) {
entry = list_entry(h, struct lg4ff_device_entry, list);
if (strcmp(entry->device_id, (&hid->dev)->kobj.name) == 0)
break;
}
if (h == &device_list.list) {
dbg_hid("Device not found!");
return count;
}
if (range == 0)
range = entry->max_range;
if (entry->set_range != NULL && range >= entry->min_range && range <= entry->max_range) {
entry->set_range(hid, range);
entry->range = range;
}
return count;
}
int lg4ff_init(struct hid_device *hid)
{
struct hid_input *hidinput = list_entry(hid->inputs.next, struct hid_input, list);
struct list_head *report_list = &hid->report_enum[HID_OUTPUT_REPORT].report_list;
struct input_dev *dev = hidinput->input;
struct hid_report *report;
struct hid_field *field;
struct lg4ff_device_entry *entry;
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
if (!list_inited) {
INIT_LIST_HEAD(&device_list.list);
list_inited = 1;
}
entry = kzalloc(sizeof(struct lg4ff_device_entry), GFP_KERNEL);
if (!entry) {
hid_err(hid, "Cannot add device, insufficient memory.\n");
return -ENOMEM;
}
entry->device_id = kstrdup((&hid->dev)->kobj.name, GFP_KERNEL);
if (!entry->device_id) {
hid_err(hid, "Cannot set device_id, insufficient memory.\n");
kfree(entry);
return -ENOMEM;
}
entry->min_range = lg4ff_devices[i].min_range;
entry->max_range = lg4ff_devices[i].max_range;
entry->set_range = lg4ff_devices[i].set_range;
list_add(&entry->list, &device_list.list);
error = device_create_file(&hid->dev, &dev_attr_range);
if (error)
return error;
dbg_hid("sysfs interface created\n");
entry->range = entry->max_range;
if (entry->set_range != NULL)
entry->set_range(hid, entry->range);
hid_info(hid, "Force feedback for Logitech Speed Force Wireless by Simon Wood <simon@mungewell.org>\n");
return 0;
}
int lg4ff_deinit(struct hid_device *hid)
{
bool found = 0;
struct lg4ff_device_entry *entry;
struct list_head *h, *g;
list_for_each_safe(h, g, &device_list.list) {
entry = list_entry(h, struct lg4ff_device_entry, list);
if (strcmp(entry->device_id, (&hid->dev)->kobj.name) == 0) {
list_del(h);
kfree(entry->device_id);
kfree(entry);
found = 1;
break;
}
}
if (!found) {
dbg_hid("Device entry not found!\n");
return -1;
}
device_remove_file(&hid->dev, &dev_attr_range);
dbg_hid("Device successfully unregistered\n");
return 0;
}
