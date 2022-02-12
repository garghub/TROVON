static int __init acm_ms_do_config(struct usb_configuration *c)
{
struct f_serial_opts *opts;
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_acm_inst = usb_get_function_instance("acm");
if (IS_ERR(f_acm_inst))
return PTR_ERR(f_acm_inst);
opts = container_of(f_acm_inst, struct f_serial_opts, func_inst);
opts->port_num = tty_line;
f_acm = usb_get_function(f_acm_inst);
if (IS_ERR(f_acm)) {
status = PTR_ERR(f_acm);
goto err_func;
}
status = usb_add_function(c, f_acm);
if (status < 0)
goto err_conf;
status = fsg_bind_config(c->cdev, c, &fsg_common);
if (status < 0)
goto err_fsg;
return 0;
err_fsg:
usb_remove_function(c, f_acm);
err_conf:
usb_put_function(f_acm);
err_func:
usb_put_function_instance(f_acm_inst);
return status;
}
static int __init acm_ms_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int status;
void *retp;
status = gserial_alloc_line(&tty_line);
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
gserial_free_line(tty_line);
return status;
}
static int __exit acm_ms_unbind(struct usb_composite_dev *cdev)
{
usb_put_function(f_acm);
usb_put_function_instance(f_acm_inst);
gserial_free_line(tty_line);
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
