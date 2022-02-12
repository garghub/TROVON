static __u8 *elecom_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 48 && rdesc[46] == 0x05 && rdesc[47] == 0x0c) {
hid_info(hdev, "Fixing up Elecom BM084 report descriptor\n");
rdesc[47] = 0x00;
}
return rdesc;
}
