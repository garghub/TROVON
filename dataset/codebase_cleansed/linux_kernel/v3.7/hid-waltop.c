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
case USB_DEVICE_ID_WALTOP_SIRIUS_BATTERY_FREE_TABLET:
if (*rsize == SIRIUS_BATTERY_FREE_TABLET_RDESC_ORIG_SIZE) {
rdesc = sirius_battery_free_tablet_rdesc_fixed;
*rsize = sizeof(sirius_battery_free_tablet_rdesc_fixed);
}
break;
}
return rdesc;
}
static int waltop_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
if (report->type == HID_INPUT_REPORT && report->id == 16 && size >= 8) {
if ((data[1] & 0xF) > 1) {
data[6] = 0;
data[7] = 0;
}
}
if (hdev->product == USB_DEVICE_ID_WALTOP_SIRIUS_BATTERY_FREE_TABLET &&
report->type == HID_INPUT_REPORT &&
report->id == 16 &&
size == 10) {
static const s8 tilt_to_radians[] = {
0, 5, 10, 14, 19, 24, 29, 34, 40, 45,
50, 56, 62, 68, 74, 81, 88, 96, 105
};
s8 tilt_x = (s8)data[8];
s8 tilt_y = (s8)data[9];
s8 sign_x = tilt_x >= 0 ? 1 : -1;
s8 sign_y = tilt_y >= 0 ? 1 : -1;
tilt_x *= sign_x;
tilt_y *= sign_y;
sign_y *= -1;
if (tilt_x > ARRAY_SIZE(tilt_to_radians) - 1)
tilt_x = ARRAY_SIZE(tilt_to_radians) - 1;
if (tilt_y > ARRAY_SIZE(tilt_to_radians) - 1)
tilt_y = ARRAY_SIZE(tilt_to_radians) - 1;
data[8] = tilt_to_radians[tilt_x] * sign_x;
data[9] = tilt_to_radians[tilt_y] * sign_y;
}
return 0;
}
static int __init waltop_init(void)
{
return hid_register_driver(&waltop_driver);
}
static void __exit waltop_exit(void)
{
hid_unregister_driver(&waltop_driver);
}
