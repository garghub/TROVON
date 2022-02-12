static inline bool has_rndis(void)
{
#ifdef USB_ETH_RNDIS
return true;
#else
return false;
#endif
}
static int __init rndis_do_config(struct usb_configuration *c)
{
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
return rndis_bind_config(c, hostaddr, the_dev);
}
static int __init eth_do_config(struct usb_configuration *c)
{
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
if (use_eem)
return eem_bind_config(c, the_dev);
else if (can_support_ecm(c->cdev->gadget))
return ecm_bind_config(c, hostaddr, the_dev);
else
return geth_bind_config(c, hostaddr, the_dev);
}
static int __init eth_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
int status;
the_dev = gether_setup(cdev->gadget, hostaddr);
if (IS_ERR(the_dev))
return PTR_ERR(the_dev);
if (use_eem) {
eth_config_driver.label = "CDC Ethernet (EEM)";
device_desc.idVendor = cpu_to_le16(EEM_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(EEM_PRODUCT_NUM);
} else if (can_support_ecm(cdev->gadget)) {
eth_config_driver.label = "CDC Ethernet (ECM)";
} else {
eth_config_driver.label = "CDC Subset/SAFE";
device_desc.idVendor = cpu_to_le16(SIMPLE_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(SIMPLE_PRODUCT_NUM);
if (!has_rndis())
device_desc.bDeviceClass = USB_CLASS_VENDOR_SPEC;
}
if (has_rndis()) {
device_desc.idVendor = cpu_to_le16(RNDIS_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(RNDIS_PRODUCT_NUM);
device_desc.bNumConfigurations = 2;
}
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
if (has_rndis()) {
status = usb_add_config(cdev, &rndis_config_driver,
rndis_do_config);
if (status < 0)
goto fail;
}
status = usb_add_config(cdev, &eth_config_driver, eth_do_config);
if (status < 0)
goto fail;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
return 0;
fail:
gether_cleanup(the_dev);
return status;
}
static int __exit eth_unbind(struct usb_composite_dev *cdev)
{
gether_cleanup(the_dev);
return 0;
}
static int __init init(void)
{
return usb_composite_probe(&eth_driver);
}
static void __exit cleanup(void)
{
usb_composite_unregister(&eth_driver);
}
