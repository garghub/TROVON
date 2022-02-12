static __init int rndis_do_config(struct usb_configuration *c)
{
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
ret = rndis_bind_config(c, hostaddr);
if (ret < 0)
return ret;
f_acm_rndis = usb_get_function(fi_acm);
if (IS_ERR(f_acm_rndis))
goto err_func_acm;
ret = usb_add_function(c, f_acm_rndis);
if (ret)
goto err_conf;
ret = fsg_bind_config(c->cdev, c, &fsg_common);
if (ret < 0)
goto err_fsg;
return 0;
err_fsg:
usb_remove_function(c, f_acm_rndis);
err_conf:
usb_put_function(f_acm_rndis);
err_func_acm:
return ret;
}
static int rndis_config_register(struct usb_composite_dev *cdev)
{
static struct usb_configuration config = {
.bConfigurationValue = MULTI_RNDIS_CONFIG_NUM,
.bmAttributes = USB_CONFIG_ATT_SELFPOWER,
};
config.label = strings_dev[MULTI_STRING_RNDIS_CONFIG_IDX].s;
config.iConfiguration = strings_dev[MULTI_STRING_RNDIS_CONFIG_IDX].id;
return usb_add_config(cdev, &config, rndis_do_config);
}
static int rndis_config_register(struct usb_composite_dev *cdev)
{
return 0;
}
static __init int cdc_do_config(struct usb_configuration *c)
{
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
ret = ecm_bind_config(c, hostaddr);
if (ret < 0)
return ret;
f_acm_multi = usb_get_function(fi_acm);
if (IS_ERR(f_acm_multi))
goto err_func_acm;
ret = usb_add_function(c, f_acm_multi);
if (ret)
goto err_conf;
ret = fsg_bind_config(c->cdev, c, &fsg_common);
if (ret < 0)
goto err_fsg;
return 0;
err_fsg:
usb_remove_function(c, f_acm_multi);
err_conf:
usb_put_function(f_acm_multi);
err_func_acm:
return ret;
}
static int cdc_config_register(struct usb_composite_dev *cdev)
{
static struct usb_configuration config = {
.bConfigurationValue = MULTI_CDC_CONFIG_NUM,
.bmAttributes = USB_CONFIG_ATT_SELFPOWER,
};
config.label = strings_dev[MULTI_STRING_CDC_CONFIG_IDX].s;
config.iConfiguration = strings_dev[MULTI_STRING_CDC_CONFIG_IDX].id;
return usb_add_config(cdev, &config, cdc_do_config);
}
static int cdc_config_register(struct usb_composite_dev *cdev)
{
return 0;
}
static int __ref multi_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct f_serial_opts *opts;
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
fi_acm = usb_get_function_instance("acm");
if (IS_ERR(fi_acm)) {
status = PTR_ERR(fi_acm);
goto fail0dot5;
}
opts = container_of(fi_acm, struct f_serial_opts, func_inst);
opts->port_num = tty_line;
{
void *retp;
retp = fsg_common_from_params(&fsg_common, cdev, &fsg_mod_data);
if (IS_ERR(retp)) {
status = PTR_ERR(retp);
goto fail1;
}
}
status = usb_string_ids_tab(cdev, strings_dev);
if (unlikely(status < 0))
goto fail2;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = rndis_config_register(cdev);
if (unlikely(status < 0))
goto fail2;
status = cdc_config_register(cdev);
if (unlikely(status < 0))
goto fail2;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, DRIVER_DESC "\n");
fsg_common_put(&fsg_common);
return 0;
fail2:
fsg_common_put(&fsg_common);
fail1:
usb_put_function_instance(fi_acm);
fail0dot5:
gserial_free_line(tty_line);
fail0:
gether_cleanup();
return status;
}
static int __exit multi_unbind(struct usb_composite_dev *cdev)
{
#ifdef CONFIG_USB_G_MULTI_CDC
usb_put_function(f_acm_multi);
#endif
#ifdef USB_ETH_RNDIS
usb_put_function(f_acm_rndis);
#endif
usb_put_function_instance(fi_acm);
gserial_free_line(tty_line);
gether_cleanup();
return 0;
}
static int __init multi_init(void)
{
return usb_composite_probe(&multi_driver);
}
static void __exit multi_exit(void)
{
usb_composite_unregister(&multi_driver);
}
