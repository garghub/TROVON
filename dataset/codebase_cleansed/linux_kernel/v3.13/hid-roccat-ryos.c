static int ryos_init_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *usb_dev = interface_to_usbdev(intf);
struct roccat_common2_device *ryos;
int retval;
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= RYOS_USB_INTERFACE_PROTOCOL) {
hid_set_drvdata(hdev, NULL);
return 0;
}
ryos = kzalloc(sizeof(*ryos), GFP_KERNEL);
if (!ryos) {
hid_err(hdev, "can't alloc device descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, ryos);
retval = roccat_common2_device_init_struct(usb_dev, ryos);
if (retval) {
hid_err(hdev, "couldn't init Ryos device\n");
goto exit_free;
}
retval = roccat_connect(ryos_class, hdev,
sizeof(struct ryos_report_special));
if (retval < 0) {
hid_err(hdev, "couldn't init char dev\n");
} else {
ryos->chrdev_minor = retval;
ryos->roccat_claimed = 1;
}
return 0;
exit_free:
kfree(ryos);
return retval;
}
static void ryos_remove_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct roccat_common2_device *ryos;
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= RYOS_USB_INTERFACE_PROTOCOL)
return;
ryos = hid_get_drvdata(hdev);
if (ryos->roccat_claimed)
roccat_disconnect(ryos->chrdev_minor);
kfree(ryos);
}
static int ryos_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int retval;
retval = hid_parse(hdev);
if (retval) {
hid_err(hdev, "parse failed\n");
goto exit;
}
retval = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (retval) {
hid_err(hdev, "hw start failed\n");
goto exit;
}
retval = ryos_init_specials(hdev);
if (retval) {
hid_err(hdev, "couldn't install mouse\n");
goto exit_stop;
}
return 0;
exit_stop:
hid_hw_stop(hdev);
exit:
return retval;
}
static void ryos_remove(struct hid_device *hdev)
{
ryos_remove_specials(hdev);
hid_hw_stop(hdev);
}
static int ryos_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct roccat_common2_device *ryos = hid_get_drvdata(hdev);
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= RYOS_USB_INTERFACE_PROTOCOL)
return 0;
if (data[0] != RYOS_REPORT_NUMBER_SPECIAL)
return 0;
if (ryos != NULL && ryos->roccat_claimed)
roccat_report_event(ryos->chrdev_minor, data);
return 0;
}
static int __init ryos_init(void)
{
int retval;
ryos_class = class_create(THIS_MODULE, "ryos");
if (IS_ERR(ryos_class))
return PTR_ERR(ryos_class);
ryos_class->dev_groups = ryos_groups;
retval = hid_register_driver(&ryos_driver);
if (retval)
class_destroy(ryos_class);
return retval;
}
static void __exit ryos_exit(void)
{
hid_unregister_driver(&ryos_driver);
class_destroy(ryos_class);
}
