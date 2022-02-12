static __u8 *kye_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
if (*rsize >= 74 &&
rdesc[61] == 0x05 && rdesc[62] == 0x08 &&
rdesc[63] == 0x19 && rdesc[64] == 0x08 &&
rdesc[65] == 0x29 && rdesc[66] == 0x0f &&
rdesc[71] == 0x75 && rdesc[72] == 0x08 &&
rdesc[73] == 0x95 && rdesc[74] == 0x01) {
hid_info(hdev,
"fixing up Kye/Genius Ergo Mouse report descriptor\n");
rdesc[62] = 0x09;
rdesc[64] = 0x04;
rdesc[66] = 0x07;
rdesc[72] = 0x01;
rdesc[74] = 0x08;
}
return rdesc;
}
static int __init kye_init(void)
{
return hid_register_driver(&kye_driver);
}
static void __exit kye_exit(void)
{
hid_unregister_driver(&kye_driver);
}
