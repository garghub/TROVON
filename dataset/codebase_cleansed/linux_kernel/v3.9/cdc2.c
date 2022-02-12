static int __init cdc_do_config(struct usb_configuration *c)
{
struct f_serial_opts *opts;
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
status = ecm_bind_config(c, hostaddr);
if (status < 0)
return status;
fi_serial = usb_get_function_instance("acm");
if (IS_ERR(fi_serial))
return PTR_ERR(fi_serial);
opts = container_of(fi_serial, struct f_serial_opts, func_inst);
opts->port_num = tty_line;
f_acm = usb_get_function(fi_serial);
if (IS_ERR(f_acm))
goto err_func_acm;
status = usb_add_function(c, f_acm);
if (status)
goto err_conf;
return 0;
err_conf:
usb_put_function(f_acm);
err_func_acm:
usb_put_function_instance(fi_serial);
return status;
}
static int __init cdc_bind(struct usb_composite_dev *cdev)
{
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
status = gserial_alloc_line(&tty_line);
if (status < 0)
goto fail0;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail1;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = usb_add_config(cdev, &cdc_config_driver, cdc_do_config);
if (status < 0)
goto fail1;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
return 0;
fail1:
gserial_free_line(tty_line);
fail0:
gether_cleanup();
return status;
}
static int __exit cdc_unbind(struct usb_composite_dev *cdev)
{
usb_put_function(f_acm);
usb_put_function_instance(fi_serial);
gserial_free_line(tty_line);
gether_cleanup();
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&cdc_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&cdc_driver);
}
