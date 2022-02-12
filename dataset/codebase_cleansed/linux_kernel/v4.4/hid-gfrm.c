static int gfrm_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
unsigned long hdev_type = (unsigned long) hid_get_drvdata(hdev);
if (hdev_type == GFRM100) {
if (usage->hid == (HID_UP_CONSUMER | 0x4)) {
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, KEY_INFO);
return 1;
}
if (usage->hid == (HID_UP_CONSUMER | 0x41)) {
hid_map_usage_clear(hi, usage, bit, max, EV_KEY, KEY_OK);
return 1;
}
}
return 0;
}
static int gfrm_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
unsigned long hdev_type = (unsigned long) hid_get_drvdata(hdev);
int ret = 0;
if (hdev_type != GFRM100)
return 0;
if (size < 2 || data[0] != GFRM100_SEARCH_KEY_REPORT_ID)
return 0;
switch (data[1]) {
case GFRM100_SEARCH_KEY_DOWN:
ret = hid_report_raw_event(hdev, HID_INPUT_REPORT, search_key_dn,
sizeof(search_key_dn), 1);
break;
case GFRM100_SEARCH_KEY_AUDIO_DATA:
break;
case GFRM100_SEARCH_KEY_UP:
ret = hid_report_raw_event(hdev, HID_INPUT_REPORT, search_key_up,
sizeof(search_key_up), 1);
break;
default:
break;
}
return (ret < 0) ? ret : -1;
}
static int gfrm_input_configured(struct hid_device *hid, struct hid_input *hidinput)
{
input_enable_softrepeat(hidinput->input, 400, 100);
return 0;
}
static int gfrm_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
hid_set_drvdata(hdev, (void *) id->driver_data);
ret = hid_parse(hdev);
if (ret)
goto done;
if (id->driver_data == GFRM100) {
if (!hid_register_report(hdev, HID_INPUT_REPORT,
GFRM100_SEARCH_KEY_REPORT_ID)) {
ret = -ENOMEM;
goto done;
}
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
done:
return ret;
}
static void gfrm_remove(struct hid_device *hdev)
{
hid_hw_stop(hdev);
hid_set_drvdata(hdev, NULL);
}
