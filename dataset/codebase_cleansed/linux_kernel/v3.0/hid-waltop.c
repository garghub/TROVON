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
static int __init waltop_init(void)
{
return hid_register_driver(&waltop_driver);
}
static void __exit waltop_exit(void)
{
hid_unregister_driver(&waltop_driver);
}
