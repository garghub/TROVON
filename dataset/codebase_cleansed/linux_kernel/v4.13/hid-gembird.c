static __u8 *gembird_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
__u8 *new_rdesc;
size_t delta_size = sizeof(gembird_jpd_fixed_rdesc) -
sizeof(gembird_jpd_faulty_rdesc);
size_t new_size = *rsize + delta_size;
if (*rsize >= 31 && !memcmp(&rdesc[GEMBIRD_START_FAULTY_RDESC],
gembird_jpd_faulty_rdesc,
sizeof(gembird_jpd_faulty_rdesc))) {
new_rdesc = devm_kzalloc(&hdev->dev, new_size, GFP_KERNEL);
if (new_rdesc == NULL)
return rdesc;
dev_info(&hdev->dev,
"fixing Gembird JPD-DualForce 2 report descriptor.\n");
memcpy(new_rdesc + delta_size, rdesc, *rsize);
memcpy(new_rdesc, rdesc, GEMBIRD_START_FAULTY_RDESC);
memcpy(new_rdesc + GEMBIRD_START_FAULTY_RDESC,
gembird_jpd_fixed_rdesc,
sizeof(gembird_jpd_fixed_rdesc));
*rsize = new_size;
rdesc = new_rdesc;
}
return rdesc;
}
