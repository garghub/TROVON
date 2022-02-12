static int guas_unbind(struct usb_composite_dev *cdev)
{
if (!IS_ERR_OR_NULL(f_tcm))
usb_put_function(f_tcm);
return 0;
}
static int tcm_do_config(struct usb_configuration *c)
{
int status;
f_tcm = usb_get_function(fi_tcm);
if (IS_ERR(f_tcm))
return PTR_ERR(f_tcm);
status = usb_add_function(c, f_tcm);
if (status < 0) {
usb_put_function(f_tcm);
return status;
}
return 0;
}
static int usb_target_bind(struct usb_composite_dev *cdev)
{
int ret;
ret = usb_string_ids_tab(cdev, usbg_us_strings);
if (ret)
return ret;
usbg_device_desc.iManufacturer =
usbg_us_strings[USB_GADGET_MANUFACTURER_IDX].id;
usbg_device_desc.iProduct = usbg_us_strings[USB_GADGET_PRODUCT_IDX].id;
usbg_device_desc.iSerialNumber =
usbg_us_strings[USB_GADGET_SERIAL_IDX].id;
usbg_config_driver.iConfiguration =
usbg_us_strings[USB_G_STR_CONFIG].id;
ret = usb_add_config(cdev, &usbg_config_driver, tcm_do_config);
if (ret)
return ret;
usb_composite_overwrite_options(cdev, &coverwrite);
return 0;
}
static int usbg_attach(struct usb_function_instance *f)
{
return usb_composite_probe(&usbg_driver);
}
static void usbg_detach(struct usb_function_instance *f)
{
usb_composite_unregister(&usbg_driver);
}
static int __init usb_target_gadget_init(void)
{
struct f_tcm_opts *tcm_opts;
fi_tcm = usb_get_function_instance("tcm");
if (IS_ERR(fi_tcm))
return PTR_ERR(fi_tcm);
tcm_opts = container_of(fi_tcm, struct f_tcm_opts, func_inst);
mutex_lock(&tcm_opts->dep_lock);
tcm_opts->tcm_register_callback = usbg_attach;
tcm_opts->tcm_unregister_callback = usbg_detach;
tcm_opts->dependent = THIS_MODULE;
tcm_opts->can_attach = true;
tcm_opts->has_dep = true;
mutex_unlock(&tcm_opts->dep_lock);
fi_tcm->set_inst_name(fi_tcm, "tcm-legacy");
return 0;
}
static void __exit usb_target_gadget_exit(void)
{
if (!IS_ERR_OR_NULL(fi_tcm))
usb_put_function_instance(fi_tcm);
}
