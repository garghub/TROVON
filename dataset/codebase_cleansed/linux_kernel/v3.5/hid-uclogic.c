static __u8 *uclogic_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct usb_interface *iface = to_usb_interface(hdev->dev.parent);
__u8 iface_num = iface->cur_altsetting->desc.bInterfaceNumber;
switch (hdev->product) {
case USB_DEVICE_ID_UCLOGIC_TABLET_PF1209:
if (*rsize == PF1209_RDESC_ORIG_SIZE) {
rdesc = pf1209_rdesc_fixed;
*rsize = sizeof(pf1209_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP4030U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp4030u_rdesc_fixed;
*rsize = sizeof(wp4030u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP5540U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp5540u_rdesc_fixed;
*rsize = sizeof(wp5540u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP8060U:
if (*rsize == WPXXXXU_RDESC_ORIG_SIZE) {
rdesc = wp8060u_rdesc_fixed;
*rsize = sizeof(wp8060u_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_TABLET_WP1062:
if (*rsize == WP1062_RDESC_ORIG_SIZE) {
rdesc = wp1062_rdesc_fixed;
*rsize = sizeof(wp1062_rdesc_fixed);
}
break;
case USB_DEVICE_ID_UCLOGIC_WIRELESS_TABLET_TWHL850:
switch (iface_num) {
case 0:
if (*rsize == TWHL850_RDESC_ORIG_SIZE0) {
rdesc = twhl850_rdesc_fixed0;
*rsize = sizeof(twhl850_rdesc_fixed0);
}
break;
case 1:
if (*rsize == TWHL850_RDESC_ORIG_SIZE1) {
rdesc = twhl850_rdesc_fixed1;
*rsize = sizeof(twhl850_rdesc_fixed1);
}
break;
case 2:
if (*rsize == TWHL850_RDESC_ORIG_SIZE2) {
rdesc = twhl850_rdesc_fixed2;
*rsize = sizeof(twhl850_rdesc_fixed2);
}
break;
}
break;
}
return rdesc;
}
static int __init uclogic_init(void)
{
return hid_register_driver(&uclogic_driver);
}
static void __exit uclogic_exit(void)
{
hid_unregister_driver(&uclogic_driver);
}
