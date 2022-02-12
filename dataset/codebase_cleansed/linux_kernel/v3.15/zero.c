static void zero_autoresume(unsigned long _c)
{
struct usb_composite_dev *cdev = (void *)_c;
struct usb_gadget *g = cdev->gadget;
if (!cdev->config)
return;
if (g->speed != USB_SPEED_UNKNOWN) {
int status = usb_gadget_wakeup(g);
INFO(cdev, "%s --> %d\n", __func__, status);
}
}
static void zero_suspend(struct usb_composite_dev *cdev)
{
if (cdev->gadget->speed == USB_SPEED_UNKNOWN)
return;
if (autoresume) {
if (max_autoresume &&
(autoresume_step_ms > max_autoresume * 1000))
autoresume_step_ms = autoresume * 1000;
mod_timer(&autoresume_timer, jiffies +
msecs_to_jiffies(autoresume_step_ms));
DBG(cdev, "suspend, wakeup in %d milliseconds\n",
autoresume_step_ms);
autoresume_step_ms += autoresume_interval_ms;
} else
DBG(cdev, "%s\n", __func__);
}
static void zero_resume(struct usb_composite_dev *cdev)
{
DBG(cdev, "%s\n", __func__);
del_timer(&autoresume_timer);
}
static int ss_config_setup(struct usb_configuration *c,
const struct usb_ctrlrequest *ctrl)
{
switch (ctrl->bRequest) {
case 0x5b:
case 0x5c:
return func_ss->setup(func_ss, ctrl);
default:
return -EOPNOTSUPP;
}
}
static int __init zero_bind(struct usb_composite_dev *cdev)
{
struct f_ss_opts *ss_opts;
struct f_lb_opts *lb_opts;
int status;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
return status;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
device_desc.iSerialNumber = strings_dev[USB_GADGET_SERIAL_IDX].id;
setup_timer(&autoresume_timer, zero_autoresume, (unsigned long) cdev);
func_inst_ss = usb_get_function_instance("SourceSink");
if (IS_ERR(func_inst_ss))
return PTR_ERR(func_inst_ss);
ss_opts = container_of(func_inst_ss, struct f_ss_opts, func_inst);
ss_opts->pattern = gzero_options.pattern;
ss_opts->isoc_interval = gzero_options.isoc_interval;
ss_opts->isoc_maxpacket = gzero_options.isoc_maxpacket;
ss_opts->isoc_mult = gzero_options.isoc_mult;
ss_opts->isoc_maxburst = gzero_options.isoc_maxburst;
ss_opts->bulk_buflen = gzero_options.bulk_buflen;
func_ss = usb_get_function(func_inst_ss);
if (IS_ERR(func_ss)) {
status = PTR_ERR(func_ss);
goto err_put_func_inst_ss;
}
func_inst_lb = usb_get_function_instance("Loopback");
if (IS_ERR(func_inst_lb)) {
status = PTR_ERR(func_inst_lb);
goto err_put_func_ss;
}
lb_opts = container_of(func_inst_lb, struct f_lb_opts, func_inst);
lb_opts->bulk_buflen = gzero_options.bulk_buflen;
lb_opts->qlen = gzero_options.qlen;
func_lb = usb_get_function(func_inst_lb);
if (IS_ERR(func_lb)) {
status = PTR_ERR(func_lb);
goto err_put_func_inst_lb;
}
sourcesink_driver.iConfiguration = strings_dev[USB_GZERO_SS_DESC].id;
loopback_driver.iConfiguration = strings_dev[USB_GZERO_LB_DESC].id;
sourcesink_driver.bmAttributes &= ~USB_CONFIG_ATT_WAKEUP;
loopback_driver.bmAttributes &= ~USB_CONFIG_ATT_WAKEUP;
sourcesink_driver.descriptors = NULL;
loopback_driver.descriptors = NULL;
if (autoresume) {
sourcesink_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
loopback_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
autoresume_step_ms = autoresume * 1000;
}
if (gadget_is_otg(cdev->gadget)) {
sourcesink_driver.descriptors = otg_desc;
sourcesink_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
loopback_driver.descriptors = otg_desc;
loopback_driver.bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
if (loopdefault) {
usb_add_config_only(cdev, &loopback_driver);
usb_add_config_only(cdev, &sourcesink_driver);
} else {
usb_add_config_only(cdev, &sourcesink_driver);
usb_add_config_only(cdev, &loopback_driver);
}
status = usb_add_function(&sourcesink_driver, func_ss);
if (status)
goto err_conf_flb;
usb_ep_autoconfig_reset(cdev->gadget);
status = usb_add_function(&loopback_driver, func_lb);
if (status)
goto err_conf_flb;
usb_ep_autoconfig_reset(cdev->gadget);
usb_composite_overwrite_options(cdev, &coverwrite);
INFO(cdev, "%s, version: " DRIVER_VERSION "\n", longname);
return 0;
err_conf_flb:
usb_put_function(func_lb);
func_lb = NULL;
err_put_func_inst_lb:
usb_put_function_instance(func_inst_lb);
func_inst_lb = NULL;
err_put_func_ss:
usb_put_function(func_ss);
func_ss = NULL;
err_put_func_inst_ss:
usb_put_function_instance(func_inst_ss);
func_inst_ss = NULL;
return status;
}
static int zero_unbind(struct usb_composite_dev *cdev)
{
del_timer_sync(&autoresume_timer);
if (!IS_ERR_OR_NULL(func_ss))
usb_put_function(func_ss);
usb_put_function_instance(func_inst_ss);
if (!IS_ERR_OR_NULL(func_lb))
usb_put_function(func_lb);
usb_put_function_instance(func_inst_lb);
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&zero_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&zero_driver);
}
