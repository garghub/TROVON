static __u8 *saitek_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize == 137 && rdesc[20] == 0x09 && rdesc[21] == 0x33
&& rdesc[94] == 0x81 && rdesc[95] == 0x03
&& rdesc[110] == 0x81 && rdesc[111] == 0x03) {
hid_info(hdev, "Fixing up Saitek PS1000 report descriptor\n");
rdesc[20] = 0x15;
rdesc[21] = 0x00;
rdesc[95] = 0x02;
rdesc[111] = 0x02;
}
return rdesc;
}
