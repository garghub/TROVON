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
int status;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
return status;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
midi_config.iConfiguration = strings_dev[STRING_DESCRIPTION_IDX].id;
status = usb_add_config(cdev, &midi_config, midi_bind_config);
if (status < 0)
return status;
usb_composite_overwrite_options(cdev, &coverwrite);
pr_info("%s\n", longname);
return 0;
}
static int __init midi_init(void)
{
return usb_composite_probe(&midi_driver);
}
static void __exit midi_cleanup(void)
{
usb_composite_unregister(&midi_driver);
}
