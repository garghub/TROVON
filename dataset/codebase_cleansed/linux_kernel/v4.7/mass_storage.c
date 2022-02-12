static int msg_thread_exits(struct fsg_common *common)
{
msg_cleanup();
return 0;
}
static int msg_do_config(struct usb_configuration *c)
{
struct fsg_opts *opts;
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
opts = fsg_opts_from_func_inst(fi_msg);
f_msg = usb_get_function(fi_msg);
if (IS_ERR(f_msg))
return PTR_ERR(f_msg);
ret = usb_add_function(c, f_msg);
if (ret)
goto put_func;
return 0;
put_func:
usb_put_function(f_msg);
return ret;
}
static int msg_bind(struct usb_composite_dev *cdev)
{
static const struct fsg_operations ops = {
.thread_exits = msg_thread_exits,
};
struct fsg_opts *opts;
struct fsg_config config;
int status;
fi_msg = usb_get_function_instance("mass_storage");
if (IS_ERR(fi_msg))
return PTR_ERR(fi_msg);
fsg_config_from_params(&config, &mod_data, fsg_num_buffers);
opts = fsg_opts_from_func_inst(fi_msg);
opts->no_configfs = true;
status = fsg_common_set_num_buffers(opts->common, fsg_num_buffers);
if (status)
goto fail;
fsg_common_set_ops(opts->common, &ops);
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
msg_device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
if (gadget_is_otg(cdev->gadget) && !otg_desc[0]) {
struct usb_descriptor_header *usb_desc;
usb_desc = usb_otg_descriptor_alloc(cdev->gadget);
if (!usb_desc)
goto fail_string_ids;
usb_otg_descriptor_init(cdev->gadget, usb_desc);
otg_desc[0] = usb_desc;
otg_desc[1] = NULL;
}
status = usb_add_config(cdev, &msg_config_driver, msg_do_config);
if (status < 0)
goto fail_otg_desc;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&cdev->gadget->dev,
DRIVER_DESC ", version: " DRIVER_VERSION "\n");
set_bit(0, &msg_registered);
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
return status;
}
static int msg_unbind(struct usb_composite_dev *cdev)
{
if (!IS_ERR(f_msg))
usb_put_function(f_msg);
if (!IS_ERR(fi_msg))
usb_put_function_instance(fi_msg);
kfree(otg_desc[0]);
otg_desc[0] = NULL;
return 0;
}
static int __init msg_init(void)
{
return usb_composite_probe(&msg_driver);
}
static void msg_cleanup(void)
{
if (test_and_clear_bit(0, &msg_registered))
usb_composite_unregister(&msg_driver);
}
