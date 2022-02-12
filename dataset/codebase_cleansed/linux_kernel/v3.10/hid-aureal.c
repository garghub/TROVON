static __u8 *aureal_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 54 && rdesc[52] == 0x25 && rdesc[53] == 0x01) {
dev_info(&hdev->dev, "fixing Aureal Cy se W-01RN USB_V3.1 report descriptor.\n");
rdesc[53] = 0x65;
} return rdesc;
}
