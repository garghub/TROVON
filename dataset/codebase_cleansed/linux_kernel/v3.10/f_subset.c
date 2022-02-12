static inline struct f_gether *func_to_geth(struct usb_function *f)
{
return container_of(f, struct f_gether, port.func);
}
static int geth_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_gether *geth = func_to_geth(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct net_device *net;
if (geth->port.in_ep->driver_data) {
DBG(cdev, "reset cdc subset\n");
gether_disconnect(&geth->port);
}
DBG(cdev, "init + activate cdc subset\n");
if (config_ep_by_speed(cdev->gadget, f, geth->port.in_ep) ||
config_ep_by_speed(cdev->gadget, f, geth->port.out_ep)) {
geth->port.in_ep->desc = NULL;
geth->port.out_ep->desc = NULL;
return -EINVAL;
}
net = gether_connect(&geth->port);
return IS_ERR(net) ? PTR_ERR(net) : 0;
}
static void geth_disable(struct usb_function *f)
{
struct f_gether *geth = func_to_geth(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "net deactivated\n");
gether_disconnect(&geth->port);
}
static int
geth_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_gether *geth = func_to_geth(f);
int status;
struct usb_ep *ep;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
subset_data_intf.bInterfaceNumber = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &fs_subset_in_desc);
if (!ep)
goto fail;
geth->port.in_ep = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &fs_subset_out_desc);
if (!ep)
goto fail;
geth->port.out_ep = ep;
ep->driver_data = cdev;
hs_subset_in_desc.bEndpointAddress = fs_subset_in_desc.bEndpointAddress;
hs_subset_out_desc.bEndpointAddress =
fs_subset_out_desc.bEndpointAddress;
ss_subset_in_desc.bEndpointAddress = fs_subset_in_desc.bEndpointAddress;
ss_subset_out_desc.bEndpointAddress =
fs_subset_out_desc.bEndpointAddress;
status = usb_assign_descriptors(f, fs_eth_function, hs_eth_function,
ss_eth_function);
if (status)
goto fail;
DBG(cdev, "CDC Subset: %s speed IN/%s OUT/%s\n",
gadget_is_superspeed(c->cdev->gadget) ? "super" :
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
geth->port.in_ep->name, geth->port.out_ep->name);
return 0;
fail:
usb_free_all_descriptors(f);
if (geth->port.out_ep)
geth->port.out_ep->driver_data = NULL;
if (geth->port.in_ep)
geth->port.in_ep->driver_data = NULL;
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static void
geth_unbind(struct usb_configuration *c, struct usb_function *f)
{
geth_string_defs[0].id = 0;
usb_free_all_descriptors(f);
kfree(func_to_geth(f));
}
int geth_bind_config(struct usb_configuration *c, u8 ethaddr[ETH_ALEN],
struct eth_dev *dev)
{
struct f_gether *geth;
int status;
if (!ethaddr)
return -EINVAL;
if (geth_string_defs[0].id == 0) {
status = usb_string_ids_tab(c->cdev, geth_string_defs);
if (status < 0)
return status;
subset_data_intf.iInterface = geth_string_defs[0].id;
ether_desc.iMACAddress = geth_string_defs[1].id;
}
geth = kzalloc(sizeof *geth, GFP_KERNEL);
if (!geth)
return -ENOMEM;
snprintf(geth->ethaddr, sizeof geth->ethaddr, "%pm", ethaddr);
geth_string_defs[1].s = geth->ethaddr;
geth->port.ioport = dev;
geth->port.cdc_filter = DEFAULT_FILTER;
geth->port.func.name = "cdc_subset";
geth->port.func.strings = geth_strings;
geth->port.func.bind = geth_bind;
geth->port.func.unbind = geth_unbind;
geth->port.func.set_alt = geth_set_alt;
geth->port.func.disable = geth_disable;
status = usb_add_function(c, &geth->port.func);
if (status)
kfree(geth);
return status;
}
