static int __init ncm_do_config(struct usb_configuration *c)
{
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
return ncm_bind_config(c, hostaddr);
}
static int __init gncm_bind(struct usb_composite_dev *cdev)
{
int gcnum;
struct usb_gadget *gadget = cdev->gadget;
int status;
status = gether_setup(cdev->gadget, hostaddr);
if (status < 0)
return status;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0)
device_desc.bcdDevice = cpu_to_le16(0x0300 | gcnum);
else {
dev_warn(&gadget->dev,
"controller '%s' not recognized; trying %s\n",
gadget->name,
ncm_config_driver.label);
device_desc.bcdDevice =
cpu_to_le16(0x0300 | 0x0099);
}
snprintf(manufacturer, sizeof manufacturer, "%s %s with %s",
init_utsname()->sysname, init_utsname()->release,
gadget->name);
status = usb_string_id(cdev);
if (status < 0)
goto fail;
strings_dev[STRING_MANUFACTURER_IDX].id = status;
device_desc.iManufacturer = status;
status = usb_string_id(cdev);
if (status < 0)
goto fail;
strings_dev[STRING_PRODUCT_IDX].id = status;
device_desc.iProduct = status;
status = usb_add_config(cdev, &ncm_config_driver,
ncm_do_config);
if (status < 0)
goto fail;
dev_info(&gadget->dev, "%s\n", DRIVER_DESC);
return 0;
fail:
gether_cleanup();
return status;
}
static int __exit gncm_unbind(struct usb_composite_dev *cdev)
{
gether_cleanup();
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&ncm_driver, gncm_bind);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&ncm_driver);
}
