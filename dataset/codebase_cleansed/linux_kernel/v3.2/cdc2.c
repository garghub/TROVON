static int __init cdc_do_config(struct usb_configuration *c)
{
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
status = ecm_bind_config(c, hostaddr);
if (status < 0)
return status;
status = acm_bind_config(c, 0);
if (status < 0)
return status;
return 0;
}
static int __init cdc_bind(struct usb_composite_dev *cdev)
{
int gcnum;
struct usb_gadget *gadget = cdev->gadget;
int status;
if (!can_support_ecm(cdev->gadget)) {
dev_err(&gadget->dev, "controller '%s' not usable\n",
gadget->name);
return -EINVAL;
}
status = gether_setup(cdev->gadget, hostaddr);
if (status < 0)
return status;
status = gserial_setup(cdev->gadget, 1);
if (status < 0)
goto fail0;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0)
device_desc.bcdDevice = cpu_to_le16(0x0300 | gcnum);
else {
WARNING(cdev, "controller '%s' not recognized; trying %s\n",
gadget->name,
cdc_config_driver.label);
device_desc.bcdDevice =
cpu_to_le16(0x0300 | 0x0099);
}
snprintf(manufacturer, sizeof manufacturer, "%s %s with %s",
init_utsname()->sysname, init_utsname()->release,
gadget->name);
status = usb_string_id(cdev);
if (status < 0)
goto fail1;
strings_dev[STRING_MANUFACTURER_IDX].id = status;
device_desc.iManufacturer = status;
status = usb_string_id(cdev);
if (status < 0)
goto fail1;
strings_dev[STRING_PRODUCT_IDX].id = status;
device_desc.iProduct = status;
status = usb_add_config(cdev, &cdc_config_driver, cdc_do_config);
if (status < 0)
goto fail1;
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
return 0;
fail1:
gserial_cleanup();
fail0:
gether_cleanup();
return status;
}
static int __exit cdc_unbind(struct usb_composite_dev *cdev)
{
gserial_cleanup();
gether_cleanup();
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&cdc_driver, cdc_bind);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&cdc_driver);
}
