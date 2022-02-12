static int __init ncm_do_config(struct usb_configuration *c)
{
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
return ncm_bind_config(c, hostaddr, the_dev);
}
static int __init gncm_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int status;
the_dev = gether_setup(cdev->gadget, hostaddr);
if (IS_ERR(the_dev))
return PTR_ERR(the_dev);
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = usb_add_config(cdev, &ncm_config_driver,
ncm_do_config);
if (status < 0)
goto fail;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s\n", DRIVER_DESC);
return 0;
fail:
gether_cleanup(the_dev);
return status;
}
static int __exit gncm_unbind(struct usb_composite_dev *cdev)
{
gether_cleanup(the_dev);
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&ncm_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&ncm_driver);
}
