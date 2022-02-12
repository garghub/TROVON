static __u8 *keytouch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
hid_info(hdev, "fixing up Keytouch IEC report descriptor\n");
rdesc = keytouch_fixed_rdesc;
*rsize = sizeof(keytouch_fixed_rdesc);
return rdesc;
}
