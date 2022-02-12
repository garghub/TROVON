static __u8 *huion_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
switch (hdev->product) {
case USB_DEVICE_ID_HUION_580:
if (*rsize == HUION_580_RDESC_ORIG_SIZE) {
rdesc = huion_580_rdesc_fixed;
*rsize = sizeof(huion_580_rdesc_fixed);
}
break;
}
return rdesc;
}
static int huion_tablet_enable(struct hid_device *hdev)
{
int rc;
char buf[22];
rc = usb_string(hid_to_usb_dev(hdev), 0x64, buf, sizeof(buf));
if (rc < 0)
return rc;
return 0;
}
static int huion_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
switch (id->product) {
case USB_DEVICE_ID_HUION_580:
if (intf->cur_altsetting->desc.bInterfaceNumber != 0x00)
return -ENODEV;
break;
}
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
case USB_DEVICE_ID_HUION_580:
ret = huion_tablet_enable(hdev);
if (ret) {
hid_err(hdev, "tablet enabling failed\n");
goto enabling_err;
}
break;
}
return 0;
enabling_err:
hid_hw_stop(hdev);
err:
return ret;
}
static int huion_raw_event(struct hid_device *hdev, struct hid_report *report,
u8 *data, int size)
{
if (report->type == HID_INPUT_REPORT && report->id == 0x07 && size >= 2)
data[1] ^= 0x40;
return 0;
}
