static int savu_init_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *usb_dev = interface_to_usbdev(intf);
struct roccat_common2_device *savu;
int retval;
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= USB_INTERFACE_PROTOCOL_MOUSE) {
hid_set_drvdata(hdev, NULL);
return 0;
}
savu = kzalloc(sizeof(*savu), GFP_KERNEL);
if (!savu) {
hid_err(hdev, "can't alloc device descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, savu);
retval = roccat_common2_device_init_struct(usb_dev, savu);
if (retval) {
hid_err(hdev, "couldn't init Savu device\n");
goto exit_free;
}
retval = roccat_connect(savu_class, hdev,
sizeof(struct savu_roccat_report));
if (retval < 0) {
hid_err(hdev, "couldn't init char dev\n");
} else {
savu->chrdev_minor = retval;
savu->roccat_claimed = 1;
}
return 0;
exit_free:
kfree(savu);
return retval;
}
static void savu_remove_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct roccat_common2_device *savu;
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= USB_INTERFACE_PROTOCOL_MOUSE)
return;
savu = hid_get_drvdata(hdev);
if (savu->roccat_claimed)
roccat_disconnect(savu->chrdev_minor);
kfree(savu);
}
static int savu_probe(struct hid_device *hdev,
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
retval = savu_init_specials(hdev);
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
static void savu_remove(struct hid_device *hdev)
{
savu_remove_specials(hdev);
hid_hw_stop(hdev);
}
static void savu_report_to_chrdev(struct roccat_common2_device const *savu,
u8 const *data)
{
struct savu_roccat_report roccat_report;
struct savu_mouse_report_special const *special_report;
if (data[0] != SAVU_MOUSE_REPORT_NUMBER_SPECIAL)
return;
special_report = (struct savu_mouse_report_special const *)data;
roccat_report.type = special_report->type;
roccat_report.data[0] = special_report->data[0];
roccat_report.data[1] = special_report->data[1];
roccat_report_event(savu->chrdev_minor,
(uint8_t const *)&roccat_report);
}
static int savu_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct roccat_common2_device *savu = hid_get_drvdata(hdev);
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= USB_INTERFACE_PROTOCOL_MOUSE)
return 0;
if (savu == NULL)
return 0;
if (savu->roccat_claimed)
savu_report_to_chrdev(savu, data);
return 0;
}
static int __init savu_init(void)
{
int retval;
savu_class = class_create(THIS_MODULE, "savu");
if (IS_ERR(savu_class))
return PTR_ERR(savu_class);
savu_class->dev_groups = savu_groups;
retval = hid_register_driver(&savu_driver);
if (retval)
class_destroy(savu_class);
return retval;
}
static void __exit savu_exit(void)
{
hid_unregister_driver(&savu_driver);
class_destroy(savu_class);
}
