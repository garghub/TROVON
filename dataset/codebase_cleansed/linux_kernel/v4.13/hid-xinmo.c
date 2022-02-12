static int xinmo_event(struct hid_device *hdev, struct hid_field *field,
struct hid_usage *usage, __s32 value)
{
switch (usage->code) {
case ABS_X:
case ABS_Y:
case ABS_Z:
case ABS_RX:
if (value < -1) {
input_event(field->hidinput->input, usage->type,
usage->code, -1);
return 1;
}
break;
}
return 0;
}
