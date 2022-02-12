static int __init ncm_do_config(struct usb_configuration *c)
{
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_ncm = usb_get_function(f_ncm_inst);
if (IS_ERR(f_ncm)) {
status = PTR_ERR(f_ncm);
return status;
}
status = usb_add_function(c, f_ncm);
if (status < 0) {
usb_put_function(f_ncm);
return status;
}
return 0;
}
static int __init gncm_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct f_ncm_opts *ncm_opts;
int status;
f_ncm_inst = usb_get_function_instance("ncm");
if (IS_ERR(f_ncm_inst))
return PTR_ERR(f_ncm_inst);
ncm_opts = container_of(f_ncm_inst, struct f_ncm_opts, func_inst);
gether_set_qmult(ncm_opts->net, qmult);
if (!gether_set_host_addr(ncm_opts->net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(ncm_opts->net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
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
usb_put_function_instance(f_ncm_inst);
return status;
}
static int __exit gncm_unbind(struct usb_composite_dev *cdev)
{
if (!IS_ERR_OR_NULL(f_ncm))
usb_put_function(f_ncm);
if (!IS_ERR_OR_NULL(f_ncm_inst))
usb_put_function_instance(f_ncm_inst);
return 0;
}
