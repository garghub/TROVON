static __u8 *holtek_mouse_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
if (intf->cur_altsetting->desc.bInterfaceNumber == 1) {
switch (hdev->product) {
case USB_DEVICE_ID_HOLTEK_ALT_MOUSE_A067:
if (*rsize >= 122 && rdesc[115] == 0xff && rdesc[116] == 0x7f
&& rdesc[120] == 0xff && rdesc[121] == 0x7f) {
hid_info(hdev, "Fixing up report descriptor\n");
rdesc[116] = rdesc[121] = 0x2f;
}
break;
case USB_DEVICE_ID_HOLTEK_ALT_MOUSE_A04A:
case USB_DEVICE_ID_HOLTEK_ALT_MOUSE_A081:
if (*rsize >= 113 && rdesc[106] == 0xff && rdesc[107] == 0x7f
&& rdesc[111] == 0xff && rdesc[112] == 0x7f) {
hid_info(hdev, "Fixing up report descriptor\n");
rdesc[107] = rdesc[112] = 0x2f;
}
break;
}
}
return rdesc;
}
