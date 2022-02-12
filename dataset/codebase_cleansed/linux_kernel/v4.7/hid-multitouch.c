static int cypress_compute_slot(struct mt_device *td)
{
if (td->curdata.contactid != 0 || td->num_received == 0)
return td->curdata.contactid;
else
return -1;
}
static ssize_t mt_show_quirks(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = to_hid_device(dev);
struct mt_device *td = hid_get_drvdata(hdev);
return sprintf(buf, "%u\n", td->mtclass.quirks);
}
static ssize_t mt_set_quirks(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hid_device *hdev = to_hid_device(dev);
struct mt_device *td = hid_get_drvdata(hdev);
unsigned long val;
if (kstrtoul(buf, 0, &val))
return -EINVAL;
td->mtclass.quirks = val;
if (td->cc_index < 0)
td->mtclass.quirks &= ~MT_QUIRK_CONTACT_CNT_ACCURATE;
return count;
}
static void mt_get_feature(struct hid_device *hdev, struct hid_report *report)
{
struct mt_device *td = hid_get_drvdata(hdev);
int ret, size = hid_report_len(report);
u8 *buf;
if (!(hdev->quirks & HID_QUIRK_NO_INIT_REPORTS))
return;
if (td->mtclass.name != MT_CLS_WIN_8)
return;
buf = hid_alloc_report_buf(report, GFP_KERNEL);
if (!buf)
return;
ret = hid_hw_raw_request(hdev, report->id, buf, size,
HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
if (ret < 0) {
dev_warn(&hdev->dev, "failed to fetch feature %d\n",
report->id);
} else {
ret = hid_report_raw_event(hdev, HID_FEATURE_REPORT, buf,
size, 0);
if (ret)
dev_warn(&hdev->dev, "failed to report feature\n");
}
kfree(buf);
}
static void mt_feature_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct mt_device *td = hid_get_drvdata(hdev);
switch (usage->hid) {
case HID_DG_INPUTMODE:
if (usage->usage_index >= field->report_count) {
dev_err(&hdev->dev, "HID_DG_INPUTMODE out of range\n");
break;
}
if (td->inputmode < 0) {
td->inputmode = field->report->id;
td->inputmode_index = usage->usage_index;
} else {
dev_info(&hdev->dev,
"Ignoring the extra HID_DG_INPUTMODE\n");
}
break;
case HID_DG_CONTACTMAX:
mt_get_feature(hdev, field->report);
td->maxcontact_report_id = field->report->id;
td->maxcontacts = field->value[0];
if (!td->maxcontacts &&
field->logical_maximum <= MT_MAX_MAXCONTACT)
td->maxcontacts = field->logical_maximum;
if (td->mtclass.maxcontacts)
td->maxcontacts = td->mtclass.maxcontacts;
break;
case HID_DG_BUTTONTYPE:
if (usage->usage_index >= field->report_count) {
dev_err(&hdev->dev, "HID_DG_BUTTONTYPE out of range\n");
break;
}
mt_get_feature(hdev, field->report);
if (field->value[usage->usage_index] == MT_BUTTONTYPE_CLICKPAD)
td->is_buttonpad = true;
break;
case 0xff0000c5:
if (usage->usage_index == 0)
mt_get_feature(hdev, field->report);
break;
}
}
static void set_abs(struct input_dev *input, unsigned int code,
struct hid_field *field, int snratio)
{
int fmin = field->logical_minimum;
int fmax = field->logical_maximum;
int fuzz = snratio ? (fmax - fmin) / snratio : 0;
input_set_abs_params(input, code, fmin, fmax, fuzz, 0);
input_abs_set_res(input, code, hidinput_calc_abs_res(field, code));
}
static void mt_store_field(struct hid_usage *usage, struct mt_device *td,
struct hid_input *hi)
{
struct mt_fields *f = td->fields;
if (f->length >= HID_MAX_FIELDS)
return;
f->usages[f->length++] = usage->hid;
}
static int mt_touch_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct mt_class *cls = &td->mtclass;
int code;
struct hid_usage *prev_usage = NULL;
if (field->application == HID_DG_TOUCHSCREEN)
td->mt_flags |= INPUT_MT_DIRECT;
if (field->application == HID_DG_TOUCHPAD ||
(usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
td->mt_flags |= INPUT_MT_POINTER;
td->inputmode_value = MT_INPUTMODE_TOUCHPAD;
}
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON)
td->buttons_count++;
if (usage->usage_index)
prev_usage = &field->usage[usage->usage_index - 1];
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_GENDESK:
switch (usage->hid) {
case HID_GD_X:
if (prev_usage && (prev_usage->hid == usage->hid)) {
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOOL_X);
set_abs(hi->input, ABS_MT_TOOL_X, field,
cls->sn_move);
} else {
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_X);
set_abs(hi->input, ABS_MT_POSITION_X, field,
cls->sn_move);
}
mt_store_field(usage, td, hi);
return 1;
case HID_GD_Y:
if (prev_usage && (prev_usage->hid == usage->hid)) {
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOOL_Y);
set_abs(hi->input, ABS_MT_TOOL_Y, field,
cls->sn_move);
} else {
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_Y);
set_abs(hi->input, ABS_MT_POSITION_Y, field,
cls->sn_move);
}
mt_store_field(usage, td, hi);
return 1;
}
return 0;
case HID_UP_DIGITIZER:
switch (usage->hid) {
case HID_DG_INRANGE:
if (cls->quirks & MT_QUIRK_HOVERING) {
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_DISTANCE);
input_set_abs_params(hi->input,
ABS_MT_DISTANCE, 0, 1, 0, 0);
}
mt_store_field(usage, td, hi);
return 1;
case HID_DG_CONFIDENCE:
if (cls->name == MT_CLS_WIN_8 &&
field->application == HID_DG_TOUCHPAD)
cls->quirks |= MT_QUIRK_CONFIDENCE;
mt_store_field(usage, td, hi);
return 1;
case HID_DG_TIPSWITCH:
hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_TOUCH);
input_set_capability(hi->input, EV_KEY, BTN_TOUCH);
mt_store_field(usage, td, hi);
return 1;
case HID_DG_CONTACTID:
mt_store_field(usage, td, hi);
td->touches_by_report++;
td->mt_report_id = field->report->id;
return 1;
case HID_DG_WIDTH:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MAJOR);
if (!(cls->quirks & MT_QUIRK_NO_AREA))
set_abs(hi->input, ABS_MT_TOUCH_MAJOR, field,
cls->sn_width);
mt_store_field(usage, td, hi);
return 1;
case HID_DG_HEIGHT:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MINOR);
if (!(cls->quirks & MT_QUIRK_NO_AREA)) {
set_abs(hi->input, ABS_MT_TOUCH_MINOR, field,
cls->sn_height);
input_set_abs_params(hi->input,
ABS_MT_ORIENTATION, 0, 1, 0, 0);
}
mt_store_field(usage, td, hi);
return 1;
case HID_DG_TIPPRESSURE:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_PRESSURE);
set_abs(hi->input, ABS_MT_PRESSURE, field,
cls->sn_pressure);
mt_store_field(usage, td, hi);
return 1;
case HID_DG_CONTACTCOUNT:
if (field->index >= field->report->maxfield ||
usage->usage_index >= field->report_count)
return 1;
td->cc_index = field->index;
td->cc_value_index = usage->usage_index;
return 1;
case HID_DG_CONTACTMAX:
return -1;
case HID_DG_TOUCH:
return -1;
}
return 0;
case HID_UP_BUTTON:
code = BTN_MOUSE + ((usage->hid - 1) & HID_USAGE);
hid_map_usage(hi, usage, bit, max, EV_KEY, code);
input_set_capability(hi->input, EV_KEY, code);
return 1;
case 0xff000000:
return -1;
}
return 0;
}
static int mt_touch_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (usage->type == EV_KEY || usage->type == EV_ABS)
set_bit(usage->type, hi->input->evbit);
return -1;
}
static int mt_compute_slot(struct mt_device *td, struct input_dev *input)
{
__s32 quirks = td->mtclass.quirks;
if (quirks & MT_QUIRK_SLOT_IS_CONTACTID)
return td->curdata.contactid;
if (quirks & MT_QUIRK_CYPRESS)
return cypress_compute_slot(td);
if (quirks & MT_QUIRK_SLOT_IS_CONTACTNUMBER)
return td->num_received;
if (quirks & MT_QUIRK_SLOT_IS_CONTACTID_MINUS_ONE)
return td->curdata.contactid - 1;
return input_mt_get_slot_by_key(input, td->curdata.contactid);
}
static void mt_complete_slot(struct mt_device *td, struct input_dev *input)
{
if ((td->mtclass.quirks & MT_QUIRK_CONTACT_CNT_ACCURATE) &&
td->num_received >= td->num_expected)
return;
if (td->curvalid || (td->mtclass.quirks & MT_QUIRK_ALWAYS_VALID)) {
int active;
int slotnum = mt_compute_slot(td, input);
struct mt_slot *s = &td->curdata;
struct input_mt *mt = input->mt;
if (slotnum < 0 || slotnum >= td->maxcontacts)
return;
if ((td->mtclass.quirks & MT_QUIRK_IGNORE_DUPLICATES) && mt) {
struct input_mt_slot *slot = &mt->slots[slotnum];
if (input_mt_is_active(slot) &&
input_mt_is_used(mt, slot))
return;
}
if (!(td->mtclass.quirks & MT_QUIRK_CONFIDENCE))
s->confidence_state = 1;
active = (s->touch_state || s->inrange_state) &&
s->confidence_state;
input_mt_slot(input, slotnum);
input_mt_report_slot_state(input, MT_TOOL_FINGER, active);
if (active) {
int wide = (s->w > s->h);
int major = max(s->w, s->h) >> 1;
int minor = min(s->w, s->h) >> 1;
input_event(input, EV_ABS, ABS_MT_POSITION_X, s->x);
input_event(input, EV_ABS, ABS_MT_POSITION_Y, s->y);
input_event(input, EV_ABS, ABS_MT_TOOL_X, s->cx);
input_event(input, EV_ABS, ABS_MT_TOOL_Y, s->cy);
input_event(input, EV_ABS, ABS_MT_DISTANCE,
!s->touch_state);
input_event(input, EV_ABS, ABS_MT_ORIENTATION, wide);
input_event(input, EV_ABS, ABS_MT_PRESSURE, s->p);
input_event(input, EV_ABS, ABS_MT_TOUCH_MAJOR, major);
input_event(input, EV_ABS, ABS_MT_TOUCH_MINOR, minor);
}
}
td->num_received++;
}
static void mt_sync_frame(struct mt_device *td, struct input_dev *input)
{
input_mt_sync_frame(input);
input_sync(input);
td->num_received = 0;
}
static int mt_touch_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
if (hid->claimed & HID_CLAIMED_HIDDEV && hid->hiddev_hid_event)
hid->hiddev_hid_event(hid, field, usage, value);
return 1;
}
static void mt_process_mt_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct mt_device *td = hid_get_drvdata(hid);
__s32 quirks = td->mtclass.quirks;
struct input_dev *input = field->hidinput->input;
if (hid->claimed & HID_CLAIMED_INPUT) {
switch (usage->hid) {
case HID_DG_INRANGE:
if (quirks & MT_QUIRK_VALID_IS_INRANGE)
td->curvalid = value;
if (quirks & MT_QUIRK_HOVERING)
td->curdata.inrange_state = value;
break;
case HID_DG_TIPSWITCH:
if (quirks & MT_QUIRK_NOT_SEEN_MEANS_UP)
td->curvalid = value;
td->curdata.touch_state = value;
break;
case HID_DG_CONFIDENCE:
if (quirks & MT_QUIRK_CONFIDENCE)
td->curdata.confidence_state = value;
if (quirks & MT_QUIRK_VALID_IS_CONFIDENCE)
td->curvalid = value;
break;
case HID_DG_CONTACTID:
td->curdata.contactid = value;
break;
case HID_DG_TIPPRESSURE:
td->curdata.p = value;
break;
case HID_GD_X:
if (usage->code == ABS_MT_TOOL_X)
td->curdata.cx = value;
else
td->curdata.x = value;
break;
case HID_GD_Y:
if (usage->code == ABS_MT_TOOL_Y)
td->curdata.cy = value;
else
td->curdata.y = value;
break;
case HID_DG_WIDTH:
td->curdata.w = value;
break;
case HID_DG_HEIGHT:
td->curdata.h = value;
break;
case HID_DG_CONTACTCOUNT:
break;
case HID_DG_TOUCH:
break;
default:
if (usage->type)
input_event(input, usage->type, usage->code,
value);
return;
}
if (usage->usage_index + 1 == field->report_count) {
if (usage->hid == td->last_slot_field)
mt_complete_slot(td, field->hidinput->input);
}
}
}
static void mt_touch_report(struct hid_device *hid, struct hid_report *report)
{
struct mt_device *td = hid_get_drvdata(hid);
struct hid_field *field;
unsigned count;
int r, n;
if (td->cc_index >= 0) {
struct hid_field *field = report->field[td->cc_index];
int value = field->value[td->cc_value_index];
if (value)
td->num_expected = value;
}
for (r = 0; r < report->maxfield; r++) {
field = report->field[r];
count = field->report_count;
if (!(HID_MAIN_ITEM_VARIABLE & field->flags))
continue;
for (n = 0; n < count; n++)
mt_process_mt_event(hid, field, &field->usage[n],
field->value[n]);
}
if (td->num_received >= td->num_expected)
mt_sync_frame(td, report->field[0]->hidinput->input);
}
static int mt_touch_input_configured(struct hid_device *hdev,
struct hid_input *hi)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct mt_class *cls = &td->mtclass;
struct input_dev *input = hi->input;
int ret;
if (!td->maxcontacts)
td->maxcontacts = MT_DEFAULT_MAXCONTACT;
mt_post_parse(td);
if (td->serial_maybe)
mt_post_parse_default_settings(td);
if (cls->is_indirect)
td->mt_flags |= INPUT_MT_POINTER;
if (cls->quirks & MT_QUIRK_NOT_SEEN_MEANS_UP)
td->mt_flags |= INPUT_MT_DROP_UNUSED;
if ((td->mt_flags & INPUT_MT_POINTER) && (td->buttons_count == 1))
td->is_buttonpad = true;
if (td->is_buttonpad)
__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);
ret = input_mt_init_slots(input, td->maxcontacts, td->mt_flags);
if (ret)
return ret;
td->mt_flags = 0;
return 0;
}
static int mt_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct mt_device *td = hid_get_drvdata(hdev);
if (!td->mtclass.export_all_inputs &&
field->application != HID_DG_TOUCHSCREEN &&
field->application != HID_DG_PEN &&
field->application != HID_DG_TOUCHPAD)
return -1;
if (field->physical == HID_DG_STYLUS)
return 0;
else if ((field->physical == 0) &&
(field->report->id != td->mt_report_id) &&
(td->mt_report_id != -1))
return 0;
if (field->application == HID_DG_TOUCHSCREEN ||
field->application == HID_DG_TOUCHPAD)
return mt_touch_input_mapping(hdev, hi, field, usage, bit, max);
return 0;
}
static int mt_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (field->physical == HID_DG_STYLUS)
return 0;
if (field->application == HID_DG_TOUCHSCREEN ||
field->application == HID_DG_TOUCHPAD)
return mt_touch_input_mapped(hdev, hi, field, usage, bit, max);
return 0;
}
static int mt_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct mt_device *td = hid_get_drvdata(hid);
if (field->report->id == td->mt_report_id)
return mt_touch_event(hid, field, usage, value);
return 0;
}
static void mt_report(struct hid_device *hid, struct hid_report *report)
{
struct mt_device *td = hid_get_drvdata(hid);
struct hid_field *field = report->field[0];
if (!(hid->claimed & HID_CLAIMED_INPUT))
return;
if (report->id == td->mt_report_id)
return mt_touch_report(hid, report);
if (field && field->hidinput && field->hidinput->input)
input_sync(field->hidinput->input);
}
static void mt_set_input_mode(struct hid_device *hdev)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct hid_report *r;
struct hid_report_enum *re;
struct mt_class *cls = &td->mtclass;
char *buf;
int report_len;
if (td->inputmode < 0)
return;
re = &(hdev->report_enum[HID_FEATURE_REPORT]);
r = re->report_id_hash[td->inputmode];
if (r) {
if (cls->quirks & MT_QUIRK_FORCE_GET_FEATURE) {
report_len = hid_report_len(r);
buf = hid_alloc_report_buf(r, GFP_KERNEL);
if (!buf) {
hid_err(hdev, "failed to allocate buffer for report\n");
return;
}
hid_hw_raw_request(hdev, r->id, buf, report_len,
HID_FEATURE_REPORT,
HID_REQ_GET_REPORT);
kfree(buf);
}
r->field[0]->value[td->inputmode_index] = td->inputmode_value;
hid_hw_request(hdev, r, HID_REQ_SET_REPORT);
}
}
static void mt_set_maxcontacts(struct hid_device *hdev)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct hid_report *r;
struct hid_report_enum *re;
int fieldmax, max;
if (td->maxcontact_report_id < 0)
return;
if (!td->mtclass.maxcontacts)
return;
re = &hdev->report_enum[HID_FEATURE_REPORT];
r = re->report_id_hash[td->maxcontact_report_id];
if (r) {
max = td->mtclass.maxcontacts;
fieldmax = r->field[0]->logical_maximum;
max = min(fieldmax, max);
if (r->field[0]->value[0] != max) {
r->field[0]->value[0] = max;
hid_hw_request(hdev, r, HID_REQ_SET_REPORT);
}
}
}
static void mt_post_parse_default_settings(struct mt_device *td)
{
__s32 quirks = td->mtclass.quirks;
if (td->touches_by_report == 1) {
quirks |= MT_QUIRK_ALWAYS_VALID;
quirks &= ~MT_QUIRK_NOT_SEEN_MEANS_UP;
quirks &= ~MT_QUIRK_VALID_IS_INRANGE;
quirks &= ~MT_QUIRK_VALID_IS_CONFIDENCE;
quirks &= ~MT_QUIRK_CONTACT_CNT_ACCURATE;
}
td->mtclass.quirks = quirks;
}
static void mt_post_parse(struct mt_device *td)
{
struct mt_fields *f = td->fields;
struct mt_class *cls = &td->mtclass;
if (td->touches_by_report > 0) {
int field_count_per_touch = f->length / td->touches_by_report;
td->last_slot_field = f->usages[field_count_per_touch - 1];
}
if (td->cc_index < 0)
cls->quirks &= ~MT_QUIRK_CONTACT_CNT_ACCURATE;
}
static int mt_input_configured(struct hid_device *hdev, struct hid_input *hi)
{
struct mt_device *td = hid_get_drvdata(hdev);
char *name;
const char *suffix = NULL;
struct hid_field *field = hi->report->field[0];
int ret;
if (hi->report->id == td->mt_report_id) {
ret = mt_touch_input_configured(hdev, hi);
if (ret)
return ret;
}
if (hi->report->field[0]->physical == HID_DG_STYLUS) {
suffix = "Pen";
__set_bit(BTN_STYLUS, hi->input->keybit);
} else {
switch (field->application) {
case HID_GD_KEYBOARD:
suffix = "Keyboard";
break;
case HID_GD_KEYPAD:
suffix = "Keypad";
break;
case HID_GD_MOUSE:
suffix = "Mouse";
break;
case HID_DG_STYLUS:
suffix = "Pen";
__set_bit(BTN_STYLUS, hi->input->keybit);
break;
case HID_DG_TOUCHSCREEN:
break;
case HID_DG_TOUCHPAD:
suffix = "Touchpad";
break;
case HID_GD_SYSTEM_CONTROL:
suffix = "System Control";
break;
case HID_CP_CONSUMER_CONTROL:
suffix = "Consumer Control";
break;
default:
suffix = "UNKNOWN";
break;
}
}
if (suffix) {
name = devm_kzalloc(&hi->input->dev,
strlen(hdev->name) + strlen(suffix) + 2,
GFP_KERNEL);
if (name) {
sprintf(name, "%s %s", hdev->name, suffix);
hi->input->name = name;
}
}
return 0;
}
static int mt_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret, i;
struct mt_device *td;
struct mt_class *mtclass = mt_classes;
for (i = 0; mt_classes[i].name ; i++) {
if (id->driver_data == mt_classes[i].name) {
mtclass = &(mt_classes[i]);
break;
}
}
hdev->quirks |= HID_QUIRK_NO_INPUT_SYNC;
hdev->quirks |= HID_QUIRK_MULTI_INPUT;
hdev->quirks |= HID_QUIRK_NO_EMPTY_INPUT;
if (id->group == HID_GROUP_MULTITOUCH_WIN_8)
hdev->quirks |= HID_QUIRK_NO_INIT_REPORTS;
td = devm_kzalloc(&hdev->dev, sizeof(struct mt_device), GFP_KERNEL);
if (!td) {
dev_err(&hdev->dev, "cannot allocate multitouch data\n");
return -ENOMEM;
}
td->mtclass = *mtclass;
td->inputmode = -1;
td->maxcontact_report_id = -1;
td->inputmode_value = MT_INPUTMODE_TOUCHSCREEN;
td->cc_index = -1;
td->mt_report_id = -1;
hid_set_drvdata(hdev, td);
td->fields = devm_kzalloc(&hdev->dev, sizeof(struct mt_fields),
GFP_KERNEL);
if (!td->fields) {
dev_err(&hdev->dev, "cannot allocate multitouch fields data\n");
return -ENOMEM;
}
if (id->vendor == HID_ANY_ID && id->product == HID_ANY_ID)
td->serial_maybe = true;
ret = hid_parse(hdev);
if (ret != 0)
return ret;
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret)
return ret;
ret = sysfs_create_group(&hdev->dev.kobj, &mt_attribute_group);
if (ret)
dev_warn(&hdev->dev, "Cannot allocate sysfs group for %s\n",
hdev->name);
mt_set_maxcontacts(hdev);
mt_set_input_mode(hdev);
devm_kfree(&hdev->dev, td->fields);
td->fields = NULL;
return 0;
}
static void mt_release_contacts(struct hid_device *hid)
{
struct hid_input *hidinput;
list_for_each_entry(hidinput, &hid->inputs, list) {
struct input_dev *input_dev = hidinput->input;
struct input_mt *mt = input_dev->mt;
int i;
if (mt) {
for (i = 0; i < mt->num_slots; i++) {
input_mt_slot(input_dev, i);
input_mt_report_slot_state(input_dev,
MT_TOOL_FINGER,
false);
}
input_mt_sync_frame(input_dev);
input_sync(input_dev);
}
}
}
static int mt_reset_resume(struct hid_device *hdev)
{
mt_release_contacts(hdev);
mt_set_maxcontacts(hdev);
mt_set_input_mode(hdev);
return 0;
}
static int mt_resume(struct hid_device *hdev)
{
hid_hw_idle(hdev, 0, 0, HID_REQ_SET_IDLE);
return 0;
}
static void mt_remove(struct hid_device *hdev)
{
sysfs_remove_group(&hdev->dev.kobj, &mt_attribute_group);
hid_hw_stop(hdev);
}
