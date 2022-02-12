static int cdc_do_config(struct usb_configuration *c)
{
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_ecm = usb_get_function(fi_ecm);
if (IS_ERR(f_ecm)) {
status = PTR_ERR(f_ecm);
goto err_get_ecm;
}
status = usb_add_function(c, f_ecm);
if (status)
goto err_add_ecm;
f_acm = usb_get_function(fi_serial);
if (IS_ERR(f_acm)) {
status = PTR_ERR(f_acm);
goto err_get_acm;
}
status = usb_add_function(c, f_acm);
if (status)
goto err_add_acm;
return 0;
err_add_acm:
usb_put_function(f_acm);
err_get_acm:
usb_remove_function(c, f_ecm);
err_add_ecm:
usb_put_function(f_ecm);
err_get_ecm:
return status;
}
static int cdc_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct f_ecm_opts *ecm_opts;
int status;
if (!can_support_ecm(cdev->gadget)) {
dev_err(&gadget->dev, "controller '%s' not usable\n",
gadget->name);
return -EINVAL;
}
fi_ecm = usb_get_function_instance("ecm");
if (IS_ERR(fi_ecm))
return PTR_ERR(fi_ecm);
ecm_opts = container_of(fi_ecm, struct f_ecm_opts, func_inst);
gether_set_qmult(ecm_opts->net, qmult);
if (!gether_set_host_addr(ecm_opts->net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(ecm_opts->net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
fi_serial = usb_get_function_instance("acm");
if (IS_ERR(fi_serial)) {
status = PTR_ERR(fi_serial);
goto fail;
}
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
usb_put_function_instance(fi_serial);
fail:
usb_put_function_instance(fi_ecm);
return status;
}
static int cdc_unbind(struct usb_composite_dev *cdev)
{
usb_put_function(f_acm);
usb_put_function_instance(fi_serial);
if (!IS_ERR_OR_NULL(f_ecm))
usb_put_function(f_ecm);
if (!IS_ERR_OR_NULL(fi_ecm))
usb_put_function_instance(fi_ecm);
return 0;
}
