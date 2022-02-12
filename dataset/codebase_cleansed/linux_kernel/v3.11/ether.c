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
int status;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
f_rndis = usb_get_function(fi_rndis);
if (IS_ERR(f_rndis))
return PTR_ERR(f_rndis);
status = usb_add_function(c, f_rndis);
if (status < 0)
usb_put_function(f_rndis);
return status;
}
static int __init eth_do_config(struct usb_configuration *c)
{
int status = 0;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
if (use_eem) {
f_eem = usb_get_function(fi_eem);
if (IS_ERR(f_eem))
return PTR_ERR(f_eem);
status = usb_add_function(c, f_eem);
if (status < 0)
usb_put_function(f_eem);
return status;
} else if (can_support_ecm(c->cdev->gadget)) {
f_ecm = usb_get_function(fi_ecm);
if (IS_ERR(f_ecm))
return PTR_ERR(f_ecm);
status = usb_add_function(c, f_ecm);
if (status < 0)
usb_put_function(f_ecm);
return status;
} else {
f_geth = usb_get_function(fi_geth);
if (IS_ERR(f_geth))
return PTR_ERR(f_geth);
status = usb_add_function(c, f_geth);
if (status < 0)
usb_put_function(f_geth);
return status;
}
}
static int __init eth_bind(struct usb_composite_dev *cdev)
{
struct usb_gadget *gadget = cdev->gadget;
struct f_eem_opts *eem_opts = NULL;
struct f_ecm_opts *ecm_opts = NULL;
struct f_gether_opts *geth_opts = NULL;
struct net_device *net;
int status;
if (use_eem) {
fi_eem = usb_get_function_instance("eem");
if (IS_ERR(fi_eem))
return PTR_ERR(fi_eem);
eem_opts = container_of(fi_eem, struct f_eem_opts, func_inst);
net = eem_opts->net;
eth_config_driver.label = "CDC Ethernet (EEM)";
device_desc.idVendor = cpu_to_le16(EEM_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(EEM_PRODUCT_NUM);
} else if (can_support_ecm(gadget)) {
fi_ecm = usb_get_function_instance("ecm");
if (IS_ERR(fi_ecm))
return PTR_ERR(fi_ecm);
ecm_opts = container_of(fi_ecm, struct f_ecm_opts, func_inst);
net = ecm_opts->net;
eth_config_driver.label = "CDC Ethernet (ECM)";
} else {
fi_geth = usb_get_function_instance("geth");
if (IS_ERR(fi_geth))
return PTR_ERR(fi_geth);
geth_opts = container_of(fi_geth, struct f_gether_opts,
func_inst);
net = geth_opts->net;
eth_config_driver.label = "CDC Subset/SAFE";
device_desc.idVendor = cpu_to_le16(SIMPLE_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(SIMPLE_PRODUCT_NUM);
if (!has_rndis())
device_desc.bDeviceClass = USB_CLASS_VENDOR_SPEC;
}
gether_set_qmult(net, qmult);
if (!gether_set_host_addr(net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
if (has_rndis()) {
gether_set_gadget(net, cdev->gadget);
status = gether_register_netdev(net);
if (status)
goto fail;
if (use_eem)
eem_opts->bound = true;
else if (can_support_ecm(gadget))
ecm_opts->bound = true;
else
geth_opts->bound = true;
fi_rndis = usb_get_function_instance("rndis");
if (IS_ERR(fi_rndis)) {
status = PTR_ERR(fi_rndis);
goto fail;
}
rndis_borrow_net(fi_rndis, net);
device_desc.idVendor = cpu_to_le16(RNDIS_VENDOR_NUM);
device_desc.idProduct = cpu_to_le16(RNDIS_PRODUCT_NUM);
device_desc.bNumConfigurations = 2;
}
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto fail1;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
if (has_rndis()) {
status = usb_add_config(cdev, &rndis_config_driver,
rndis_do_config);
if (status < 0)
goto fail1;
}
status = usb_add_config(cdev, &eth_config_driver, eth_do_config);
if (status < 0)
goto fail1;
usb_composite_overwrite_options(cdev, &coverwrite);
dev_info(&gadget->dev, "%s, version: " DRIVER_VERSION "\n",
DRIVER_DESC);
return 0;
fail1:
if (has_rndis())
usb_put_function_instance(fi_rndis);
fail:
if (use_eem)
usb_put_function_instance(fi_eem);
else if (can_support_ecm(gadget))
usb_put_function_instance(fi_ecm);
else
usb_put_function_instance(fi_geth);
return status;
}
static int __exit eth_unbind(struct usb_composite_dev *cdev)
{
if (has_rndis()) {
usb_put_function(f_rndis);
usb_put_function_instance(fi_rndis);
}
if (use_eem) {
usb_put_function(f_eem);
usb_put_function_instance(fi_eem);
} else if (can_support_ecm(cdev->gadget)) {
usb_put_function(f_ecm);
usb_put_function_instance(fi_ecm);
} else {
usb_put_function(f_geth);
usb_put_function_instance(fi_geth);
}
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
