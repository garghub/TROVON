static int waltop_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret;
struct waltop_state *s;
s = kzalloc(sizeof(*s), GFP_KERNEL);
if (s == NULL) {
hid_err(hdev, "can't allocate device state\n");
ret = -ENOMEM;
goto err;
}
s->pressure0 = 0;
s->pressure1 = 0;
hid_set_drvdata(hdev, s);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err;
}
return 0;
err:
kfree(s);
return ret;
}
static __u8 *waltop_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
switch (hdev->product) {
case USB_DEVICE_ID_WALTOP_SLIM_TABLET_5_8_INCH:
if (*rsize == SLIM_TABLET_5_8_INCH_RDESC_ORIG_SIZE) {
rdesc = slim_tablet_5_8_inch_rdesc_fixed;
*rsize = sizeof(slim_tablet_5_8_inch_rdesc_fixed);
}
break;
case USB_DEVICE_ID_WALTOP_SLIM_TABLET_12_1_INCH:
if (*rsize == SLIM_TABLET_12_1_INCH_RDESC_ORIG_SIZE) {
rdesc = slim_tablet_12_1_inch_rdesc_fixed;
*rsize = sizeof(slim_tablet_12_1_inch_rdesc_fixed);
}
break;
case USB_DEVICE_ID_WALTOP_Q_PAD:
if (*rsize == Q_PAD_RDESC_ORIG_SIZE) {
rdesc = q_pad_rdesc_fixed;
*rsize = sizeof(q_pad_rdesc_fixed);
}
break;
case USB_DEVICE_ID_WALTOP_PID_0038:
if (*rsize == PID_0038_RDESC_ORIG_SIZE) {
rdesc = pid_0038_rdesc_fixed;
*rsize = sizeof(pid_0038_rdesc_fixed);
}
break;
case USB_DEVICE_ID_WALTOP_MEDIA_TABLET_10_6_INCH:
if (*rsize == MEDIA_TABLET_10_6_INCH_RDESC_ORIG_SIZE) {
rdesc = media_tablet_10_6_inch_rdesc_fixed;
*rsize = sizeof(media_tablet_10_6_inch_rdesc_fixed);
}
break;
case USB_DEVICE_ID_WALTOP_MEDIA_TABLET_14_1_INCH:
if (*rsize == MEDIA_TABLET_14_1_INCH_RDESC_ORIG_SIZE) {
rdesc = media_tablet_14_1_inch_rdesc_fixed;
*rsize = sizeof(media_tablet_14_1_inch_rdesc_fixed);
}
break;
}
return rdesc;
}
static int waltop_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
if (hdev->product == USB_DEVICE_ID_WALTOP_PID_0038 &&
report->type == HID_INPUT_REPORT &&
report->id == 16 &&
size == 8) {
struct waltop_state *s = hid_get_drvdata(hdev);
if ((data[1] & 0xF) > 1) {
data[6] = s->pressure0;
data[7] = s->pressure1;
} else {
s->pressure0 = data[6];
s->pressure1 = data[7];
}
}
return 0;
}
static void waltop_remove(struct hid_device *hdev)
{
struct waltop_state *s = hid_get_drvdata(hdev);
hid_hw_stop(hdev);
kfree(s);
}
static int __init waltop_init(void)
{
return hid_register_driver(&waltop_driver);
}
static void __exit waltop_exit(void)
{
hid_unregister_driver(&waltop_driver);
}
