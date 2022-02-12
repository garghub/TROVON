static __init int rndis_do_config(struct usb_configuration *c)
{
struct fsg_opts *fsg_opts;
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_rndis = usb_get_function(fi_rndis);
if (IS_ERR(f_rndis))
return PTR_ERR(f_rndis);
ret = usb_add_function(c, f_rndis);
if (ret < 0)
goto err_func_rndis;
f_acm_rndis = usb_get_function(fi_acm);
if (IS_ERR(f_acm_rndis)) {
ret = PTR_ERR(f_acm_rndis);
goto err_func_acm;
}
ret = usb_add_function(c, f_acm_rndis);
if (ret)
goto err_conf;
f_msg_rndis = usb_get_function(fi_msg);
if (IS_ERR(f_msg_rndis)) {
ret = PTR_ERR(f_msg_rndis);
goto err_fsg;
}
fsg_opts = fsg_opts_from_func_inst(fi_msg);
ret = fsg_common_run_thread(fsg_opts->common);
if (ret)
goto err_run;
ret = usb_add_function(c, f_msg_rndis);
if (ret)
goto err_run;
return 0;
err_run:
usb_put_function(f_msg_rndis);
err_fsg:
usb_remove_function(c, f_acm_rndis);
err_conf:
usb_put_function(f_acm_rndis);
err_func_acm:
usb_remove_function(c, f_rndis);
err_func_rndis:
usb_put_function(f_rndis);
return ret;
}
static __ref int rndis_config_register(struct usb_composite_dev *cdev)
{
static struct usb_configuration config = {
.bConfigurationValue = MULTI_RNDIS_CONFIG_NUM,
.bmAttributes = USB_CONFIG_ATT_SELFPOWER,
};
config.label = strings_dev[MULTI_STRING_RNDIS_CONFIG_IDX].s;
config.iConfiguration = strings_dev[MULTI_STRING_RNDIS_CONFIG_IDX].id;
return usb_add_config(cdev, &config, rndis_do_config);
}
static __ref int rndis_config_register(struct usb_composite_dev *cdev)
{
return 0;
}
static __init int cdc_do_config(struct usb_configuration *c)
{
struct fsg_opts *fsg_opts;
int ret;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_ecm = usb_get_function(fi_ecm);
if (IS_ERR(f_ecm))
return PTR_ERR(f_ecm);
ret = usb_add_function(c, f_ecm);
if (ret < 0)
goto err_func_ecm;
f_acm_multi = usb_get_function(fi_acm);
if (IS_ERR(f_acm_multi)) {
ret = PTR_ERR(f_acm_multi);
goto err_func_acm;
}
ret = usb_add_function(c, f_acm_multi);
if (ret)
goto err_conf;
f_msg_multi = usb_get_function(fi_msg);
if (IS_ERR(f_msg_multi)) {
ret = PTR_ERR(f_msg_multi);
goto err_fsg;
}
fsg_opts = fsg_opts_from_func_inst(fi_msg);
ret = fsg_common_run_thread(fsg_opts->common);
if (ret)
goto err_run;
ret = usb_add_function(c, f_msg_multi);
if (ret)
goto err_run;
return 0;
err_run:
usb_put_function(f_msg_multi);
err_fsg:
usb_remove_function(c, f_acm_multi);
err_conf:
usb_put_function(f_acm_multi);
err_func_acm:
usb_remove_function(c, f_ecm);
err_func_ecm:
usb_put_function(f_ecm);
return ret;
}
static __ref int cdc_config_register(struct usb_composite_dev *cdev)
{
static struct usb_configuration config = {
.bConfigurationValue = MULTI_CDC_CONFIG_NUM,
.bmAttributes = USB_CONFIG_ATT_SELFPOWER,
};
config.label = strings_dev[MULTI_STRING_CDC_CONFIG_IDX].s;
config.iConfiguration = strings_dev[MULTI_STRING_CDC_CONFIG_IDX].id;
return usb_add_config(cdev, &config, cdc_do_config);
}
static __ref int cdc_config_register(struct usb_composite_dev *cdev)
{
return 0;
}
static int __ref multi_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
#ifdef CONFIG_USB_G_MULTI_CDC
struct f_ecm_opts *ecm_opts;
#endif
#ifdef USB_ETH_RNDIS
struct f_rndis_opts *rndis_opts;
#endif
struct fsg_opts *fsg_opts;
struct fsg_config config;
int status;
if (!can_support_ecm(cdev->gadget)) {
dev_err(&gadget->dev, "controller '%s' not usable\n",
gadget->name);
return -EINVAL;
}
#ifdef CONFIG_USB_G_MULTI_CDC
fi_ecm = usb_get_function_instance("ecm");
if (IS_ERR(fi_ecm))
return PTR_ERR(fi_ecm);
ecm_opts = container_of(fi_ecm, struct f_ecm_opts, func_inst);
gether_set_qmult(ecm_opts->net, qmult);
if (!gether_set_host_addr(ecm_opts->net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(ecm_opts->net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
#endif
#ifdef USB_ETH_RNDIS
fi_rndis = usb_get_function_instance("rndis");
if (IS_ERR(fi_rndis)) {
status = PTR_ERR(fi_rndis);
goto fail;
}
rndis_opts = container_of(fi_rndis, struct f_rndis_opts, func_inst);
gether_set_qmult(rndis_opts->net, qmult);
if (!gether_set_host_addr(rndis_opts->net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(rndis_opts->net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
#endif
#if (defined CONFIG_USB_G_MULTI_CDC && defined USB_ETH_RNDIS)
gether_set_gadget(ecm_opts->net, cdev->gadget);
status = gether_register_netdev(ecm_opts->net);
if (status)
goto fail0;
rndis_borrow_net(fi_rndis, ecm_opts->net);
ecm_opts->bound = true;
#endif
fi_acm = usb_get_function_instance("acm");
if (IS_ERR(fi_acm)) {
status = PTR_ERR(fi_acm);
goto fail0;
}
fi_msg = usb_get_function_instance("mass_storage");
if (IS_ERR(fi_msg)) {
status = PTR_ERR(fi_msg);
goto fail1;
}
fsg_config_from_params(&config, &fsg_mod_data, fsg_num_buffers);
fsg_opts = fsg_opts_from_func_inst(fi_msg);
fsg_opts->no_configfs = true;
status = fsg_common_set_num_buffers(fsg_opts->common, fsg_num_buffers);
if (status)
goto fail2;
status = fsg_common_set_nluns(fsg_opts->common, config.nluns);
if (status)
goto fail_set_nluns;
status = fsg_common_set_cdev(fsg_opts->common, cdev, config.can_stall);
if (status)
goto fail_set_cdev;
fsg_common_set_sysfs(fsg_opts->common, true);
status = fsg_common_create_luns(fsg_opts->common, &config);
if (status)
goto fail_set_cdev;
fsg_common_set_inquiry_string(fsg_opts->common, config.vendor_name,
config.product_name);
status = usb_string_ids_tab(cdev, strings_dev);
if (unlikely(status < 0))
goto fail_string_ids;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
status = rndis_config_register(cdev);
if (unlikely(status < 0))
goto fail_string_ids;
status = cdc_config_register(cdev);
if (unlikely(status < 0))
goto fail_string_ids;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, DRIVER_DESC "\n");
return 0;
fail_string_ids:
fsg_common_remove_luns(fsg_opts->common);
fail_set_cdev:
fsg_common_free_luns(fsg_opts->common);
fail_set_nluns:
fsg_common_free_buffers(fsg_opts->common);
fail2:
usb_put_function_instance(fi_msg);
fail1:
usb_put_function_instance(fi_acm);
fail0:
#ifdef USB_ETH_RNDIS
usb_put_function_instance(fi_rndis);
fail:
#endif
#ifdef CONFIG_USB_G_MULTI_CDC
usb_put_function_instance(fi_ecm);
#endif
return status;
}
static int __exit multi_unbind(struct usb_composite_dev *cdev)
{
#ifdef CONFIG_USB_G_MULTI_CDC
usb_put_function(f_msg_multi);
#endif
#ifdef USB_ETH_RNDIS
usb_put_function(f_msg_rndis);
#endif
usb_put_function_instance(fi_msg);
#ifdef CONFIG_USB_G_MULTI_CDC
usb_put_function(f_acm_multi);
#endif
#ifdef USB_ETH_RNDIS
usb_put_function(f_acm_rndis);
#endif
usb_put_function_instance(fi_acm);
#ifdef USB_ETH_RNDIS
usb_put_function(f_rndis);
usb_put_function_instance(fi_rndis);
#endif
#ifdef CONFIG_USB_G_MULTI_CDC
usb_put_function(f_ecm);
usb_put_function_instance(fi_ecm);
#endif
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
