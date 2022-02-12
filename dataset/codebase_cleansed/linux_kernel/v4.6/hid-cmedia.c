static void hp_ev(struct hid_device *hid, struct cmhid *cm, int value)
{
input_report_switch(cm->input_dev, SW_HEADPHONE_INSERT, value);
input_sync(cm->input_dev);
}
static int cmhid_raw_event(struct hid_device *hid, struct hid_report *report,
u8 *data, int len)
{
struct cmhid *cm = hid_get_drvdata(hid);
if (len != CM6533_JD_RAWEV_LEN)
goto out;
if (memcmp(data+CM6533_JD_SFX_OFFSET, ji_sfx, sizeof(ji_sfx)))
goto out;
if (!memcmp(data, ji_out, sizeof(ji_out))) {
hp_ev(hid, cm, 0);
goto out;
}
if (!memcmp(data, ji_in, sizeof(ji_in))) {
hp_ev(hid, cm, 1);
goto out;
}
out:
return 0;
}
static int cmhid_input_configured(struct hid_device *hid,
struct hid_input *hidinput)
{
struct input_dev *input_dev = hidinput->input;
struct cmhid *cm = hid_get_drvdata(hid);
int i;
cm->input_dev = input_dev;
memcpy(cm->switch_map, jack_switch_types, sizeof(cm->switch_map));
input_dev->evbit[0] = BIT(EV_SW);
for (i = 0; i < CM6533_JD_TYPE_COUNT; i++)
input_set_capability(cm->input_dev,
EV_SW, jack_switch_types[i]);
return 0;
}
static int cmhid_input_mapping(struct hid_device *hid,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
return -1;
}
static int cmhid_probe(struct hid_device *hid, const struct hid_device_id *id)
{
int ret;
struct cmhid *cm;
cm = kzalloc(sizeof(struct cmhid), GFP_KERNEL);
if (!cm) {
ret = -ENOMEM;
goto allocfail;
}
cm->hid = hid;
hid->quirks |= HID_QUIRK_HIDINPUT_FORCE;
hid_set_drvdata(hid, cm);
ret = hid_parse(hid);
if (ret) {
hid_err(hid, "parse failed\n");
goto fail;
}
ret = hid_hw_start(hid, HID_CONNECT_DEFAULT | HID_CONNECT_HIDDEV_FORCE);
if (ret) {
hid_err(hid, "hw start failed\n");
goto fail;
}
return 0;
fail:
kfree(cm);
allocfail:
return ret;
}
static void cmhid_remove(struct hid_device *hid)
{
struct cmhid *cm = hid_get_drvdata(hid);
hid_hw_stop(hid);
kfree(cm);
}
