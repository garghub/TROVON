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
struct usb_string *us;
int status;
struct usb_ep *ep;
struct f_gether_opts *gether_opts;
gether_opts = container_of(f->fi, struct f_gether_opts, func_inst);
if (!gether_opts->bound) {
mutex_lock(&gether_opts->lock);
gether_set_gadget(gether_opts->net, cdev->gadget);
status = gether_register_netdev(gether_opts->net);
mutex_unlock(&gether_opts->lock);
if (status)
return status;
gether_opts->bound = true;
}
us = usb_gstrings_attach(cdev, geth_strings,
ARRAY_SIZE(geth_string_defs));
if (IS_ERR(us))
return PTR_ERR(us);
subset_data_intf.iInterface = us[0].id;
ether_desc.iMACAddress = us[1].id;
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
static inline struct f_gether_opts *to_f_gether_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_gether_opts,
func_inst.group);
}
static void geth_free_inst(struct usb_function_instance *f)
{
struct f_gether_opts *opts;
opts = container_of(f, struct f_gether_opts, func_inst);
if (opts->bound)
gether_cleanup(netdev_priv(opts->net));
else
free_netdev(opts->net);
kfree(opts);
}
static struct usb_function_instance *geth_alloc_inst(void)
{
struct f_gether_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
mutex_init(&opts->lock);
opts->func_inst.free_func_inst = geth_free_inst;
opts->net = gether_setup_default();
if (IS_ERR(opts->net)) {
struct net_device *net = opts->net;
kfree(opts);
return ERR_CAST(net);
}
config_group_init_type_name(&opts->func_inst.group, "",
&gether_func_type);
return &opts->func_inst;
}
static void geth_free(struct usb_function *f)
{
struct f_gether *eth;
eth = func_to_geth(f);
kfree(eth);
}
static void geth_unbind(struct usb_configuration *c, struct usb_function *f)
{
geth_string_defs[0].id = 0;
usb_free_all_descriptors(f);
}
static struct usb_function *geth_alloc(struct usb_function_instance *fi)
{
struct f_gether *geth;
struct f_gether_opts *opts;
int status;
geth = kzalloc(sizeof(*geth), GFP_KERNEL);
if (!geth)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_gether_opts, func_inst);
mutex_lock(&opts->lock);
opts->refcnt++;
status = gether_get_host_addr_cdc(opts->net, geth->ethaddr,
sizeof(geth->ethaddr));
if (status < 12) {
kfree(geth);
mutex_unlock(&opts->lock);
return ERR_PTR(-EINVAL);
}
geth_string_defs[1].s = geth->ethaddr;
geth->port.ioport = netdev_priv(opts->net);
mutex_unlock(&opts->lock);
geth->port.cdc_filter = DEFAULT_FILTER;
geth->port.func.name = "cdc_subset";
geth->port.func.bind = geth_bind;
geth->port.func.unbind = geth_unbind;
geth->port.func.set_alt = geth_set_alt;
geth->port.func.disable = geth_disable;
geth->port.func.free_func = geth_free;
return &geth->port.func;
}
