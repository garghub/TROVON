static int cypress_compute_slot(struct mt_device *td)
{
if (td->curdata.contactid != 0 || td->num_received == 0)
return td->curdata.contactid;
else
return -1;
}
static int find_slot_from_contactid(struct mt_device *td)
{
int i;
for (i = 0; i < td->maxcontacts; ++i) {
if (td->slots[i].contactid == td->curdata.contactid &&
td->slots[i].touch_state)
return i;
}
for (i = 0; i < td->maxcontacts; ++i) {
if (!td->slots[i].seen_in_this_frame &&
!td->slots[i].touch_state)
return i;
}
return -1;
}
static void mt_feature_mapping(struct hid_device *hdev,
struct hid_field *field, struct hid_usage *usage)
{
struct mt_device *td = hid_get_drvdata(hdev);
switch (usage->hid) {
case HID_DG_INPUTMODE:
td->inputmode = field->report->id;
break;
case HID_DG_CONTACTMAX:
td->maxcontacts = field->value[0];
if (td->mtclass->maxcontacts)
td->maxcontacts = td->mtclass->maxcontacts;
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
}
static int mt_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct mt_class *cls = td->mtclass;
__s32 quirks = cls->quirks;
switch (usage->hid & HID_USAGE_PAGE) {
case HID_UP_GENDESK:
switch (usage->hid) {
case HID_GD_X:
if (quirks & MT_QUIRK_EGALAX_XYZ_FIXUP)
field->logical_maximum = 32760;
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_X);
set_abs(hi->input, ABS_MT_POSITION_X, field,
cls->sn_move);
set_abs(hi->input, ABS_X, field, cls->sn_move);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_GD_Y:
if (quirks & MT_QUIRK_EGALAX_XYZ_FIXUP)
field->logical_maximum = 32760;
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_POSITION_Y);
set_abs(hi->input, ABS_MT_POSITION_Y, field,
cls->sn_move);
set_abs(hi->input, ABS_Y, field, cls->sn_move);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
}
return 0;
case HID_UP_DIGITIZER:
switch (usage->hid) {
case HID_DG_INRANGE:
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_CONFIDENCE:
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_TIPSWITCH:
hid_map_usage(hi, usage, bit, max, EV_KEY, BTN_TOUCH);
input_set_capability(hi->input, EV_KEY, BTN_TOUCH);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_CONTACTID:
if (!td->maxcontacts)
td->maxcontacts = MT_DEFAULT_MAXCONTACT;
input_mt_init_slots(hi->input, td->maxcontacts);
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
td->last_mt_collection = usage->collection_index;
return 1;
case HID_DG_WIDTH:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MAJOR);
set_abs(hi->input, ABS_MT_TOUCH_MAJOR, field,
cls->sn_width);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_HEIGHT:
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_TOUCH_MINOR);
set_abs(hi->input, ABS_MT_TOUCH_MINOR, field,
cls->sn_height);
input_set_abs_params(hi->input,
ABS_MT_ORIENTATION, 0, 1, 0, 0);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_TIPPRESSURE:
if (quirks & MT_QUIRK_EGALAX_XYZ_FIXUP)
field->logical_minimum = 0;
hid_map_usage(hi, usage, bit, max,
EV_ABS, ABS_MT_PRESSURE);
set_abs(hi->input, ABS_MT_PRESSURE, field,
cls->sn_pressure);
set_abs(hi->input, ABS_PRESSURE, field,
cls->sn_pressure);
if (td->last_mt_collection == usage->collection_index) {
td->last_slot_field = usage->hid;
td->last_field_index = field->index;
}
return 1;
case HID_DG_CONTACTCOUNT:
if (td->last_mt_collection == usage->collection_index)
td->last_field_index = field->index;
return 1;
case HID_DG_CONTACTMAX:
if (td->last_mt_collection == usage->collection_index)
td->last_field_index = field->index;
return -1;
}
return 0;
case 0xff000000:
return -1;
}
return 0;
}
static int mt_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (usage->type == EV_KEY || usage->type == EV_ABS)
set_bit(usage->type, hi->input->evbit);
return -1;
}
static int mt_compute_slot(struct mt_device *td)
{
__s32 quirks = td->mtclass->quirks;
if (quirks & MT_QUIRK_SLOT_IS_CONTACTID)
return td->curdata.contactid;
if (quirks & MT_QUIRK_CYPRESS)
return cypress_compute_slot(td);
if (quirks & MT_QUIRK_SLOT_IS_CONTACTNUMBER)
return td->num_received;
if (quirks & MT_QUIRK_SLOT_IS_CONTACTID_MINUS_ONE)
return td->curdata.contactid - 1;
return find_slot_from_contactid(td);
}
static void mt_complete_slot(struct mt_device *td)
{
td->curdata.seen_in_this_frame = true;
if (td->curvalid) {
int slotnum = mt_compute_slot(td);
if (slotnum >= 0 && slotnum < td->maxcontacts)
td->slots[slotnum] = td->curdata;
}
td->num_received++;
}
static void mt_emit_event(struct mt_device *td, struct input_dev *input)
{
int i;
for (i = 0; i < td->maxcontacts; ++i) {
struct mt_slot *s = &(td->slots[i]);
if ((td->mtclass->quirks & MT_QUIRK_NOT_SEEN_MEANS_UP) &&
!s->seen_in_this_frame) {
s->touch_state = false;
}
input_mt_slot(input, i);
input_mt_report_slot_state(input, MT_TOOL_FINGER,
s->touch_state);
if (s->touch_state) {
int wide = (s->w > s->h);
int major = max(s->w, s->h) >> 1;
int minor = min(s->w, s->h) >> 1;
input_event(input, EV_ABS, ABS_MT_POSITION_X, s->x);
input_event(input, EV_ABS, ABS_MT_POSITION_Y, s->y);
input_event(input, EV_ABS, ABS_MT_ORIENTATION, wide);
input_event(input, EV_ABS, ABS_MT_PRESSURE, s->p);
input_event(input, EV_ABS, ABS_MT_TOUCH_MAJOR, major);
input_event(input, EV_ABS, ABS_MT_TOUCH_MINOR, minor);
}
s->seen_in_this_frame = false;
}
input_mt_report_pointer_emulation(input, true);
input_sync(input);
td->num_received = 0;
}
static int mt_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
struct mt_device *td = hid_get_drvdata(hid);
__s32 quirks = td->mtclass->quirks;
if (hid->claimed & HID_CLAIMED_INPUT && td->slots) {
switch (usage->hid) {
case HID_DG_INRANGE:
if (quirks & MT_QUIRK_VALID_IS_INRANGE)
td->curvalid = value;
break;
case HID_DG_TIPSWITCH:
if (quirks & MT_QUIRK_NOT_SEEN_MEANS_UP)
td->curvalid = value;
td->curdata.touch_state = value;
break;
case HID_DG_CONFIDENCE:
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
td->curdata.x = value;
break;
case HID_GD_Y:
td->curdata.y = value;
break;
case HID_DG_WIDTH:
td->curdata.w = value;
break;
case HID_DG_HEIGHT:
td->curdata.h = value;
break;
case HID_DG_CONTACTCOUNT:
if (value)
td->num_expected = value;
break;
default:
return 0;
}
if (usage->hid == td->last_slot_field) {
mt_complete_slot(td);
}
if (field->index == td->last_field_index
&& td->num_received >= td->num_expected)
mt_emit_event(td, field->hidinput->input);
}
if (hid->claimed & HID_CLAIMED_HIDDEV && hid->hiddev_hid_event)
hid->hiddev_hid_event(hid, field, usage, value);
return 1;
}
static void mt_set_input_mode(struct hid_device *hdev)
{
struct mt_device *td = hid_get_drvdata(hdev);
struct hid_report *r;
struct hid_report_enum *re;
if (td->inputmode < 0)
return;
re = &(hdev->report_enum[HID_FEATURE_REPORT]);
r = re->report_id_hash[td->inputmode];
if (r) {
r->field[0]->value[0] = 0x02;
usbhid_submit_report(hdev, r, USB_DIR_OUT);
}
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
td = kzalloc(sizeof(struct mt_device), GFP_KERNEL);
if (!td) {
dev_err(&hdev->dev, "cannot allocate multitouch data\n");
return -ENOMEM;
}
td->mtclass = mtclass;
td->inputmode = -1;
td->last_mt_collection = -1;
hid_set_drvdata(hdev, td);
ret = hid_parse(hdev);
if (ret != 0)
goto fail;
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret)
goto fail;
td->slots = kzalloc(td->maxcontacts * sizeof(struct mt_slot),
GFP_KERNEL);
if (!td->slots) {
dev_err(&hdev->dev, "cannot allocate multitouch slots\n");
hid_hw_stop(hdev);
ret = -ENOMEM;
goto fail;
}
mt_set_input_mode(hdev);
return 0;
fail:
kfree(td);
return ret;
}
static int mt_reset_resume(struct hid_device *hdev)
{
mt_set_input_mode(hdev);
return 0;
}
static void mt_remove(struct hid_device *hdev)
{
struct mt_device *td = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
kfree(td->slots);
kfree(td);
hid_set_drvdata(hdev, NULL);
}
static int __init mt_init(void)
{
return hid_register_driver(&mt_driver);
}
static void __exit mt_exit(void)
{
hid_unregister_driver(&mt_driver);
}
