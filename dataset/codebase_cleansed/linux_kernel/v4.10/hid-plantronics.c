static int plantronics_input_mapping(struct hid_device *hdev,
struct hid_input *hi,
struct hid_field *field,
struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned short mapped_key;
unsigned long plt_type = (unsigned long)hid_get_drvdata(hdev);
if (!(plt_type & HID_USAGE_PAGE)) {
switch (plt_type) {
case PLT_DA60:
if (PLT_ALLOW_CONSUMER)
goto defaulted;
goto ignored;
default:
if (PLT_ALLOW_CONSUMER)
goto defaulted;
}
}
else if ((plt_type & HID_USAGE) >= PLT_BASIC_TELEPHONY &&
(plt_type & HID_USAGE) != PLT_BASIC_EXCEPTION) {
if (PLT_ALLOW_CONSUMER)
goto defaulted;
}
else if (!((field->application ^ plt_type) & HID_USAGE_PAGE)) {
switch (usage->hid) {
case PLT1_VOL_UP:
case PLT2_VOL_UP:
mapped_key = KEY_VOLUMEUP;
goto mapped;
case PLT1_VOL_DOWN:
case PLT2_VOL_DOWN:
mapped_key = KEY_VOLUMEDOWN;
goto mapped;
}
}
ignored:
return -1;
defaulted:
hid_dbg(hdev, "usage: %08x (appl: %08x) - defaulted\n",
usage->hid, field->application);
return 0;
mapped:
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, mapped_key);
hid_dbg(hdev, "usage: %08x (appl: %08x) - mapped to key %d\n",
usage->hid, field->application, mapped_key);
return 1;
}
static unsigned long plantronics_device_type(struct hid_device *hdev)
{
unsigned i, col_page;
unsigned long plt_type = hdev->product;
if (plt_type >= PLT_BT300_MIN && plt_type <= PLT_BT300_MAX)
goto exit;
for (i = 0; i < hdev->maxcollection; i++) {
col_page = hdev->collection[i].usage & HID_USAGE_PAGE;
if (col_page == PLT_HID_2_0_PAGE) {
plt_type = hdev->collection[i].usage;
break;
}
if (col_page == PLT_HID_1_0_PAGE)
plt_type = hdev->collection[i].usage;
}
exit:
hid_dbg(hdev, "plt_type decoded as: %08lx\n", plt_type);
return plt_type;
}
static int plantronics_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err;
}
hid_set_drvdata(hdev, (void *)plantronics_device_type(hdev));
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT |
HID_CONNECT_HIDINPUT_FORCE | HID_CONNECT_HIDDEV_FORCE);
if (ret)
hid_err(hdev, "hw start failed\n");
err:
return ret;
}
