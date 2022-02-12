static int acm_ms_do_config(struct usb_configuration *c)
{
struct fsg_opts *opts;
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
opts = fsg_opts_from_func_inst(fi_msg);
f_acm = usb_get_function(f_acm_inst);
if (IS_ERR(f_acm))
return PTR_ERR(f_acm);
f_msg = usb_get_function(fi_msg);
if (IS_ERR(f_msg)) {
status = PTR_ERR(f_msg);
goto put_acm;
}
status = usb_add_function(c, f_acm);
if (status < 0)
goto put_msg;
status = usb_add_function(c, f_msg);
if (status)
goto remove_acm;
return 0;
remove_acm:
usb_remove_function(c, f_acm);
put_msg:
usb_put_function(f_msg);
put_acm:
usb_put_function(f_acm);
return status;
}
static int acm_ms_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct fsg_opts *opts;
struct fsg_config config;
int status;
f_acm_inst = usb_get_function_instance("acm");
if (IS_ERR(f_acm_inst))
return PTR_ERR(f_acm_inst);
fi_msg = usb_get_function_instance("mass_storage");
if (IS_ERR(fi_msg)) {
status = PTR_ERR(fi_msg);
goto fail_get_msg;
}
fsg_config_from_params(&config, &fsg_mod_data, fsg_num_buffers);
opts = fsg_opts_from_func_inst(fi_msg);
opts->no_configfs = true;
status = fsg_common_set_num_buffers(opts->common, fsg_num_buffers);
if (status)
goto fail;
status = fsg_common_set_cdev(opts->common, cdev, config.can_stall);
if (status)
goto fail_set_cdev;
fsg_common_set_sysfs(opts->common, true);
status = fsg_common_create_luns(opts->common, &config);
if (status)
goto fail_set_cdev;
fsg_common_set_inquiry_string(opts->common, config.vendor_name,
config.product_name);
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail_string_ids;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
if (gadget_is_otg(gadget) && !otg_desc[0]) {
struct usb_descriptor_header *usb_desc;
usb_desc = usb_otg_descriptor_alloc(gadget);
if (!usb_desc)
goto fail_string_ids;
usb_otg_descriptor_init(gadget, usb_desc);
otg_desc[0] = usb_desc;
otg_desc[1] = NULL;
}
status = usb_add_config(cdev, &acm_ms_config_driver, acm_ms_do_config);
if (status < 0)
goto fail_otg_desc;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
return 0;
fail_otg_desc:
kfree(otg_desc[0]);
otg_desc[0] = NULL;
fail_string_ids:
fsg_common_remove_luns(opts->common);
fail_set_cdev:
fsg_common_free_buffers(opts->common);
fail:
usb_put_function_instance(fi_msg);
fail_get_msg:
usb_put_function_instance(f_acm_inst);
return status;
}
static int acm_ms_unbind(struct usb_composite_dev *cdev)
{
usb_put_function(f_msg);
usb_put_function_instance(fi_msg);
usb_put_function(f_acm);
usb_put_function_instance(f_acm_inst);
kfree(otg_desc[0]);
otg_desc[0] = NULL;
return 0;
}
