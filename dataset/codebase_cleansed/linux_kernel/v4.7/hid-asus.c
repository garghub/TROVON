static __u8 *asus_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 56 && rdesc[54] == 0x25 && rdesc[55] == 0x65) {
hid_info(hdev, "Fixing up Asus notebook report descriptor\n");
rdesc[55] = 0xdd;
}
return rdesc;
}
