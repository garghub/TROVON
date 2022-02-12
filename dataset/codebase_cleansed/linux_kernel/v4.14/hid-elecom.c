static __u8 *elecom_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
switch (hdev->product) {
case USB_DEVICE_ID_ELECOM_BM084:
if (*rsize >= 48 && rdesc[46] == 0x05 && rdesc[47] == 0x0c) {
hid_info(hdev, "Fixing up Elecom BM084 report descriptor\n");
rdesc[47] = 0x00;
}
break;
case USB_DEVICE_ID_ELECOM_DEFT_WIRED:
case USB_DEVICE_ID_ELECOM_DEFT_WIRELESS:
case USB_DEVICE_ID_ELECOM_HUGE_WIRED:
case USB_DEVICE_ID_ELECOM_HUGE_WIRELESS:
if (*rsize == 213 && rdesc[13] == 5 && rdesc[21] == 5) {
hid_info(hdev, "Fixing up Elecom DEFT/HUGE Fn buttons\n");
rdesc[13] = 8;
rdesc[21] = 8;
rdesc[29] = 0;
}
break;
}
return rdesc;
}
