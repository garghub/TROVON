static __u8 *nti_usbsun_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 60 && rdesc[53] == 0x65 && rdesc[59] == 0x65) {
hid_info(hdev, "fixing up NTI USB-SUN keyboard adapter report descriptor\n");
rdesc[53] = rdesc[59] = 0xe7;
}
return rdesc;
}
