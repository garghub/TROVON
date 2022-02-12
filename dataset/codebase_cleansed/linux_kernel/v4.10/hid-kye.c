static __u8 *kye_consumer_control_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize, int offset, const char *device_name) {
if (*rsize >= offset + 31 &&
rdesc[offset] == 0x05 && rdesc[offset + 1] == 0x0c &&
rdesc[offset + 2] == 0x09 && rdesc[offset + 3] == 0x01 &&
rdesc[offset + 10] == 0x2a && rdesc[offset + 12] > 0x2f) {
hid_info(hdev, "fixing up %s report descriptor\n", device_name);
rdesc[offset + 12] = 0x2f;
}
return rdesc;
}
static __u8 *kye_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
switch (hdev->product) {
case USB_DEVICE_ID_KYE_ERGO_525V:
if (*rsize >= 75 &&
rdesc[61] == 0x05 && rdesc[62] == 0x08 &&
rdesc[63] == 0x19 && rdesc[64] == 0x08 &&
rdesc[65] == 0x29 && rdesc[66] == 0x0f &&
rdesc[71] == 0x75 && rdesc[72] == 0x08 &&
rdesc[73] == 0x95 && rdesc[74] == 0x01) {
hid_info(hdev,
"fixing up Kye/Genius Ergo Mouse "
"report descriptor\n");
rdesc[62] = 0x09;
rdesc[64] = 0x04;
rdesc[66] = 0x07;
rdesc[72] = 0x01;
rdesc[74] = 0x08;
}
break;
case USB_DEVICE_ID_KYE_EASYPEN_I405X:
if (*rsize == EASYPEN_I405X_RDESC_ORIG_SIZE) {
rdesc = easypen_i405x_rdesc_fixed;
*rsize = sizeof(easypen_i405x_rdesc_fixed);
}
break;
case USB_DEVICE_ID_KYE_MOUSEPEN_I608X:
if (*rsize == MOUSEPEN_I608X_RDESC_ORIG_SIZE) {
rdesc = mousepen_i608x_rdesc_fixed;
*rsize = sizeof(mousepen_i608x_rdesc_fixed);
}
break;
case USB_DEVICE_ID_KYE_MOUSEPEN_I608X_V2:
if (*rsize == MOUSEPEN_I608X_V2_RDESC_ORIG_SIZE) {
rdesc = mousepen_i608x_v2_rdesc_fixed;
*rsize = sizeof(mousepen_i608x_v2_rdesc_fixed);
}
break;
case USB_DEVICE_ID_KYE_EASYPEN_M610X:
if (*rsize == EASYPEN_M610X_RDESC_ORIG_SIZE) {
rdesc = easypen_m610x_rdesc_fixed;
*rsize = sizeof(easypen_m610x_rdesc_fixed);
}
break;
case USB_DEVICE_ID_KYE_PENSKETCH_M912:
if (*rsize == PENSKETCH_M912_RDESC_ORIG_SIZE) {
rdesc = pensketch_m912_rdesc_fixed;
*rsize = sizeof(pensketch_m912_rdesc_fixed);
}
break;
case USB_DEVICE_ID_GENIUS_GILA_GAMING_MOUSE:
rdesc = kye_consumer_control_fixup(hdev, rdesc, rsize, 104,
"Genius Gila Gaming Mouse");
break;
case USB_DEVICE_ID_GENIUS_GX_IMPERATOR:
rdesc = kye_consumer_control_fixup(hdev, rdesc, rsize, 83,
"Genius Gx Imperator Keyboard");
break;
case USB_DEVICE_ID_GENIUS_MANTICORE:
rdesc = kye_consumer_control_fixup(hdev, rdesc, rsize, 104,
"Genius Manticore Keyboard");
break;
}
return rdesc;
}
static int kye_tablet_enable(struct hid_device *hdev)
{
struct list_head *list;
struct list_head *head;
struct hid_report *report;
__s32 *value;
list = &hdev->report_enum[HID_FEATURE_REPORT].report_list;
list_for_each(head, list) {
report = list_entry(head, struct hid_report, list);
if (report->id == 5)
break;
}
if (head == list) {
hid_err(hdev, "tablet-enabling feature report not found\n");
return -ENODEV;
}
if (report->maxfield < 1 || report->field[0]->report_count < 7) {
hid_err(hdev, "invalid tablet-enabling feature report\n");
return -ENODEV;
}
value = report->field[0]->value;
value[0] = 0x12;
value[1] = 0x10;
value[2] = 0x11;
value[3] = 0x12;
value[4] = 0x00;
value[5] = 0x00;
value[6] = 0x00;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
return 0;
}
static int kye_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err;
}
switch (id->product) {
case USB_DEVICE_ID_KYE_EASYPEN_I405X:
case USB_DEVICE_ID_KYE_MOUSEPEN_I608X:
case USB_DEVICE_ID_KYE_MOUSEPEN_I608X_V2:
case USB_DEVICE_ID_KYE_EASYPEN_M610X:
case USB_DEVICE_ID_KYE_PENSKETCH_M912:
ret = kye_tablet_enable(hdev);
if (ret) {
hid_err(hdev, "tablet enabling failed\n");
goto enabling_err;
}
break;
case USB_DEVICE_ID_GENIUS_MANTICORE:
if (hid_hw_open(hdev))
hid_hw_close(hdev);
break;
}
return 0;
enabling_err:
hid_hw_stop(hdev);
err:
return ret;
}
