static __u8 *sony_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & VAIO_RDESC_CONSTANT) && *rsize >= 56 &&
rdesc[2] == 0x09 && rdesc[3] == 0x02 &&
rdesc[54] == 0x81 && rdesc[55] == 0x07) {
hid_info(hdev, "Fixing up Sony RF Receiver report descriptor\n");
rdesc[55] = 0x06;
}
if ((((sc->quirks & SIXAXIS_CONTROLLER_USB) && *rsize == 148) ||
((sc->quirks & SIXAXIS_CONTROLLER_BT) && *rsize == 149)) &&
rdesc[83] == 0x75) {
hid_info(hdev, "Fixing up Sony Sixaxis report descriptor\n");
memcpy((void *)&rdesc[83], (void *)&sixaxis_rdesc_fixup,
sizeof(sixaxis_rdesc_fixup));
} else if (sc->quirks & SIXAXIS_CONTROLLER_USB &&
*rsize > sizeof(sixaxis_rdesc_fixup2)) {
hid_info(hdev, "Sony Sixaxis clone detected. Using original report descriptor (size: %d clone; %d new)\n",
*rsize, (int)sizeof(sixaxis_rdesc_fixup2));
*rsize = sizeof(sixaxis_rdesc_fixup2);
memcpy(rdesc, &sixaxis_rdesc_fixup2, *rsize);
}
return rdesc;
}
static int sony_raw_event(struct hid_device *hdev, struct hid_report *report,
__u8 *rd, int size)
{
struct sony_sc *sc = hid_get_drvdata(hdev);
if ((sc->quirks & (SIXAXIS_CONTROLLER_USB | SIXAXIS_CONTROLLER_BT)) &&
rd[0] == 0x01 && size == 49) {
swap(rd[41], rd[42]);
swap(rd[43], rd[44]);
swap(rd[45], rd[46]);
swap(rd[47], rd[48]);
}
return 0;
}
static int sixaxis_usb_output_raw_report(struct hid_device *hid, __u8 *buf,
size_t count, unsigned char report_type)
{
struct usb_interface *intf = to_usb_interface(hid->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_host_interface *interface = intf->cur_altsetting;
int report_id = buf[0];
int ret;
if (report_type == HID_OUTPUT_REPORT) {
buf++;
count--;
}
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
HID_REQ_SET_REPORT,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
((report_type + 1) << 8) | report_id,
interface->desc.bInterfaceNumber, buf, count,
USB_CTRL_SET_TIMEOUT);
if (ret > 0 && report_type == HID_OUTPUT_REPORT)
ret++;
return ret;
}
static int sixaxis_set_operational_usb(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *dev = interface_to_usbdev(intf);
__u16 ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
int ret;
char *buf = kmalloc(18, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
HID_REQ_GET_REPORT,
USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE,
(3 << 8) | 0xf2, ifnum, buf, 17,
USB_CTRL_GET_TIMEOUT);
if (ret < 0)
hid_err(hdev, "can't set operational mode\n");
kfree(buf);
return ret;
}
static int sixaxis_set_operational_bt(struct hid_device *hdev)
{
unsigned char buf[] = { 0xf4, 0x42, 0x03, 0x00, 0x00 };
return hdev->hid_output_raw_report(hdev, buf, sizeof(buf), HID_FEATURE_REPORT);
}
static int sony_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
int ret;
unsigned long quirks = id->driver_data;
struct sony_sc *sc;
sc = kzalloc(sizeof(*sc), GFP_KERNEL);
if (sc == NULL) {
hid_err(hdev, "can't alloc sony descriptor\n");
return -ENOMEM;
}
sc->quirks = quirks;
hid_set_drvdata(hdev, sc);
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "parse failed\n");
goto err_free;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT |
HID_CONNECT_HIDDEV_FORCE);
if (ret) {
hid_err(hdev, "hw start failed\n");
goto err_free;
}
if (sc->quirks & SIXAXIS_CONTROLLER_USB) {
hdev->hid_output_raw_report = sixaxis_usb_output_raw_report;
ret = sixaxis_set_operational_usb(hdev);
}
else if (sc->quirks & SIXAXIS_CONTROLLER_BT)
ret = sixaxis_set_operational_bt(hdev);
else
ret = 0;
if (ret < 0)
goto err_stop;
return 0;
err_stop:
hid_hw_stop(hdev);
err_free:
kfree(sc);
return ret;
}
static void sony_remove(struct hid_device *hdev)
{
hid_hw_stop(hdev);
kfree(hid_get_drvdata(hdev));
}
