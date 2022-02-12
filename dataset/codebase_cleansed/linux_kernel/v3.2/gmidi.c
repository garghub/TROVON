static int __exit midi_unbind(struct usb_composite_dev *dev)
{
return 0;
}
static int __init midi_bind_config(struct usb_configuration *c)
{
return f_midi_bind_config(c, index, id,
in_ports, out_ports,
buflen, qlen);
}
static int __init midi_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int gcnum, status;
status = usb_string_id(cdev);
if (status < 0)
return status;
strings_dev[STRING_MANUFACTURER_IDX].id = status;
device_desc.iManufacturer = status;
status = usb_string_id(cdev);
if (status < 0)
return status;
strings_dev[STRING_PRODUCT_IDX].id = status;
device_desc.iProduct = status;
status = usb_string_id(cdev);
if (status < 0)
return status;
strings_dev[STRING_DESCRIPTION_IDX].id = status;
midi_config.iConfiguration = status;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum < 0) {
pr_warning("%s: controller '%s' not recognized\n",
__func__, gadget->name);
device_desc.bcdDevice = cpu_to_le16(0x9999);
} else {
device_desc.bcdDevice = cpu_to_le16(0x0200 + gcnum);
}
status = usb_add_config(cdev, &midi_config, midi_bind_config);
if (status < 0)
return status;
pr_info("%s\n", longname);
return 0;
}
static int __init midi_init(void)
{
return usb_composite_probe(&midi_driver, midi_bind);
}
static void __exit midi_cleanup(void)
{
usb_composite_unregister(&midi_driver);
}
