static int __init acm_ms_do_config(struct usb_configuration *c)
{
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
status = acm_bind_config(c, 0);
if (status < 0)
return status;
status = fsg_bind_config(c->cdev, c, &fsg_common);
if (status < 0)
return status;
return 0;
}
static int __init acm_ms_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int status;
void *retp;
status = gserial_setup(cdev->gadget, 1);
if (status < 0)
return status;
retp = fsg_common_from_params(&fsg_common, cdev, &fsg_mod_data);
if (IS_ERR(retp)) {
status = PTR_ERR(retp);
goto fail0;
}
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail1;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = usb_add_config(cdev, &acm_ms_config_driver, acm_ms_do_config);
if (status < 0)
goto fail1;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
fsg_common_put(&fsg_common);
return 0;
fail1:
fsg_common_put(&fsg_common);
fail0:
gserial_cleanup();
return status;
}
static int __exit acm_ms_unbind(struct usb_composite_dev *cdev)
{
gserial_cleanup();
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&acm_ms_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&acm_ms_driver);
}
