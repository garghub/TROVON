static const struct icade_key *icade_find_translation(u16 from)
{
if (from > ICADE_MAX_USAGE)
return NULL;
return &icade_usage_table[from];
}
static int icade_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
const struct icade_key *trans;
if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput ||
!usage->type)
return 0;
if (!value)
return 1;
trans = icade_find_translation(usage->hid & HID_USAGE);
if (!trans)
return 1;
input_event(field->hidinput->input, usage->type,
trans->to, trans->press);
return 1;
}
static int icade_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
const struct icade_key *trans;
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_KEYBOARD) {
trans = icade_find_translation(usage->hid & HID_USAGE);
if (!trans)
return -1;
hid_map_usage(hi, usage, bit, max, EV_KEY, trans->to);
set_bit(trans->to, hi->input->keybit);
return 1;
}
return -1;
}
static int icade_input_mapped(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if (usage->type == EV_KEY)
set_bit(usage->type, hi->input->evbit);
return -1;
}
