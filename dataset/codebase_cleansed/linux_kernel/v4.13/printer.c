static int printer_do_config(struct usb_configuration *c)
{
struct usb_gadget *gadget = c->cdev->gadget;
int status = 0;
usb_ep_autoconfig_reset(gadget);
usb_gadget_set_selfpowered(gadget);
if (gadget_is_otg(gadget)) {
printer_cfg_driver.descriptors = otg_desc;
printer_cfg_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_printer = usb_get_function(fi_printer);
if (IS_ERR(f_printer))
return PTR_ERR(f_printer);
status = usb_add_function(c, f_printer);
if (status < 0)
usb_put_function(f_printer);
return status;
}
static int printer_bind(struct usb_composite_dev *cdev)
{
struct f_printer_opts *opts;
int ret;
fi_printer = usb_get_function_instance("printer");
if (IS_ERR(fi_printer))
return PTR_ERR(fi_printer);
opts = container_of(fi_printer, struct f_printer_opts, func_inst);
opts->minor = 0;
opts->q_len = QLEN;
if (iPNPstring) {
opts->pnp_string = kstrdup(iPNPstring, GFP_KERNEL);
if (!opts->pnp_string) {
ret = -ENOMEM;
goto fail_put_func_inst;
}
opts->pnp_string_allocated = true;
} else {
opts->pnp_string = pnp_string;
}
ret = usb_string_ids_tab(cdev, strings);
if (ret < 0)
goto fail_put_func_inst;
device_desc.iManufacturer = strings[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings[USB_GADGET_PRODUCT_IDX].id;
device_desc.iSerialNumber = strings[USB_GADGET_SERIAL_IDX].id;
if (gadget_is_otg(cdev->gadget) && !otg_desc[0]) {
struct usb_descriptor_header *usb_desc;
usb_desc = usb_otg_descriptor_alloc(cdev->gadget);
if (!usb_desc) {
ret = -ENOMEM;
goto fail_put_func_inst;
}
usb_otg_descriptor_init(cdev->gadget, usb_desc);
otg_desc[0] = usb_desc;
otg_desc[1] = NULL;
}
ret = usb_add_config(cdev, &printer_cfg_driver, printer_do_config);
if (ret)
goto fail_free_otg_desc;
usb_composite_overwrite_options(cdev, &coverwrite);
return ret;
fail_free_otg_desc:
kfree(otg_desc[0]);
otg_desc[0] = NULL;
fail_put_func_inst:
usb_put_function_instance(fi_printer);
return ret;
}
static int printer_unbind(struct usb_composite_dev *cdev)
{
usb_put_function(f_printer);
usb_put_function_instance(fi_printer);
kfree(otg_desc[0]);
otg_desc[0] = NULL;
return 0;
}
