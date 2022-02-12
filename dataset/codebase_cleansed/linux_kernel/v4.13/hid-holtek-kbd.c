static __u8 *holtek_kbd_report_fixup(struct hid_device *hdev, __u8 *rdesc,
unsigned int *rsize)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
if (intf->cur_altsetting->desc.bInterfaceNumber == 1) {
rdesc = holtek_kbd_rdesc_fixed;
*rsize = sizeof(holtek_kbd_rdesc_fixed);
}
return rdesc;
}
static int holtek_kbd_input_event(struct input_dev *dev, unsigned int type,
unsigned int code,
int value)
{
struct hid_device *hid = input_get_drvdata(dev);
struct usb_device *usb_dev = hid_to_usb_dev(hid);
struct usb_interface *boot_interface = usb_ifnum_to_if(usb_dev, 0);
struct hid_device *boot_hid = usb_get_intfdata(boot_interface);
struct hid_input *boot_hid_input = list_first_entry(&boot_hid->inputs,
struct hid_input, list);
return boot_hid_input->input->event(boot_hid_input->input, type, code,
value);
}
static int holtek_kbd_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
int ret = hid_parse(hdev);
if (!ret)
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (!ret && intf->cur_altsetting->desc.bInterfaceNumber == 1) {
struct hid_input *hidinput;
list_for_each_entry(hidinput, &hdev->inputs, list) {
hidinput->input->event = holtek_kbd_input_event;
}
}
return ret;
}
