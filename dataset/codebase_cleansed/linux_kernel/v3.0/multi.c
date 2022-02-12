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
ret = acm_bind_config(c, 0);
if (ret < 0)
return ret;
ret = fsg_bind_config(c->cdev, c, &fsg_common);
if (ret < 0)
return ret;
return 0;
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
ret = acm_bind_config(c, 0);
if (ret < 0)
return ret;
ret = fsg_bind_config(c->cdev, c, &fsg_common);
if (ret < 0)
return ret;
return 0;
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
int status, gcnum;
if (!can_support_ecm(cdev->gadget)) {
dev_err(&gadget->dev, "controller '%s' not usable\n",
gadget->name);
return -EINVAL;
}
status = gether_setup(cdev->gadget, hostaddr);
if (status < 0)
return status;
status = gserial_setup(cdev->gadget, 1);
if (status < 0)
goto fail0;
{
void *retp;
retp = fsg_common_from_params(&fsg_common, cdev, &fsg_mod_data);
if (IS_ERR(retp)) {
status = PTR_ERR(retp);
goto fail1;
}
}
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0) {
device_desc.bcdDevice = cpu_to_le16(0x0300 | gcnum);
} else {
WARNING(cdev, "controller '%s' not recognized\n", gadget->name);
device_desc.bcdDevice = cpu_to_le16(0x0300 | 0x0099);
}
status = usb_string_ids_tab(cdev, strings_dev);
if (unlikely(status < 0))
goto fail2;
status = rndis_config_register(cdev);
if (unlikely(status < 0))
goto fail2;
status = cdc_config_register(cdev);
if (unlikely(status < 0))
goto fail2;
dev_info(&gadget->dev, DRIVER_DESC "\n");
fsg_common_put(&fsg_common);
return 0;
fail2:
fsg_common_put(&fsg_common);
fail1:
gserial_cleanup();
fail0:
gether_cleanup();
return status;
}
static int __exit multi_unbind(struct usb_composite_dev *cdev)
{
gserial_cleanup();
gether_cleanup();
return 0;
}
static int __init multi_init(void)
{
return usb_composite_probe(&multi_driver, multi_bind);
}
static void __exit multi_exit(void)
{
usb_composite_unregister(&multi_driver);
}
