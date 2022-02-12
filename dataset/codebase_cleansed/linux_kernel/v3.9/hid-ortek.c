static __u8 *ortek_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 56 && rdesc[54] == 0x25 && rdesc[55] == 0x01) {
hid_info(hdev, "Fixing up logical minimum in report descriptor (Ortek)\n");
rdesc[55] = 0x92;
} else if (*rsize >= 54 && rdesc[52] == 0x25 && rdesc[53] == 0x01) {
hid_info(hdev, "Fixing up logical minimum in report descriptor (Skycable)\n");
rdesc[53] = 0x65;
}
return rdesc;
}
