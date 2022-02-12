static int __init gfs_init(void)
{
struct f_fs_opts *opts;
int i;
int ret = 0;
ENTER();
if (func_num < 2) {
gfs_single_func = true;
func_num = 1;
}
f_ffs[0] = kcalloc(func_num * N_CONF, sizeof(*f_ffs), GFP_KERNEL);
if (!f_ffs[0]) {
ret = -ENOMEM;
goto no_func;
}
for (i = 1; i < N_CONF; ++i)
f_ffs[i] = f_ffs[0] + i * func_num;
fi_ffs = kcalloc(func_num, sizeof(*fi_ffs), GFP_KERNEL);
if (!fi_ffs) {
ret = -ENOMEM;
goto no_func;
}
for (i = 0; i < func_num; i++) {
fi_ffs[i] = usb_get_function_instance("ffs");
if (IS_ERR(fi_ffs[i])) {
ret = PTR_ERR(fi_ffs[i]);
--i;
goto no_dev;
}
opts = to_f_fs_opts(fi_ffs[i]);
if (gfs_single_func)
ret = ffs_single_dev(opts->dev);
else
ret = ffs_name_dev(opts->dev, func_names[i]);
if (ret)
goto no_dev;
opts->dev->ffs_ready_callback = functionfs_ready_callback;
opts->dev->ffs_closed_callback = functionfs_closed_callback;
opts->dev->ffs_acquire_dev_callback = functionfs_acquire_dev;
opts->dev->ffs_release_dev_callback = functionfs_release_dev;
opts->no_configfs = true;
}
missing_funcs = func_num;
return 0;
no_dev:
while (i >= 0)
usb_put_function_instance(fi_ffs[i--]);
kfree(fi_ffs);
no_func:
kfree(f_ffs[0]);
return ret;
}
static void __exit gfs_exit(void)
{
int i;
ENTER();
if (gfs_registered)
usb_composite_unregister(&gfs_driver);
gfs_registered = false;
kfree(f_ffs[0]);
for (i = 0; i < func_num; i++)
usb_put_function_instance(fi_ffs[i]);
kfree(fi_ffs);
}
static void *functionfs_acquire_dev(struct ffs_dev *dev)
{
if (!try_module_get(THIS_MODULE))
return ERR_PTR(-ENOENT);
return NULL;
}
static void functionfs_release_dev(struct ffs_dev *dev)
{
module_put(THIS_MODULE);
}
static int functionfs_ready_callback(struct ffs_data *ffs)
{
int ret = 0;
if (--missing_funcs)
return 0;
if (gfs_registered)
return -EBUSY;
gfs_registered = true;
ret = usb_composite_probe(&gfs_driver);
if (unlikely(ret < 0)) {
++missing_funcs;
gfs_registered = false;
}
return ret;
}
static void functionfs_closed_callback(struct ffs_data *ffs)
{
missing_funcs++;
if (gfs_registered)
usb_composite_unregister(&gfs_driver);
gfs_registered = false;
}
static int gfs_bind(struct usb_composite_dev *cdev)
{
#if defined CONFIG_USB_FUNCTIONFS_ETH || defined CONFIG_USB_FUNCTIONFS_RNDIS
struct net_device *net;
#endif
int ret, i;
ENTER();
if (missing_funcs)
return -ENODEV;
#if defined CONFIG_USB_FUNCTIONFS_ETH
if (can_support_ecm(cdev->gadget)) {
struct f_ecm_opts *ecm_opts;
fi_ecm = usb_get_function_instance("ecm");
if (IS_ERR(fi_ecm))
return PTR_ERR(fi_ecm);
ecm_opts = container_of(fi_ecm, struct f_ecm_opts, func_inst);
net = ecm_opts->net;
} else {
struct f_gether_opts *geth_opts;
fi_geth = usb_get_function_instance("geth");
if (IS_ERR(fi_geth))
return PTR_ERR(fi_geth);
geth_opts = container_of(fi_geth, struct f_gether_opts,
func_inst);
net = geth_opts->net;
}
#endif
#ifdef CONFIG_USB_FUNCTIONFS_RNDIS
{
fi_rndis = usb_get_function_instance("rndis");
if (IS_ERR(fi_rndis)) {
ret = PTR_ERR(fi_rndis);
goto error;
}
#ifndef CONFIG_USB_FUNCTIONFS_ETH
net = container_of(fi_rndis, struct f_rndis_opts,
func_inst)->net;
#endif
}
#endif
#if defined CONFIG_USB_FUNCTIONFS_ETH || defined CONFIG_USB_FUNCTIONFS_RNDIS
gether_set_qmult(net, qmult);
if (!gether_set_host_addr(net, host_addr))
pr_info("using host ethernet address: %s", host_addr);
if (!gether_set_dev_addr(net, dev_addr))
pr_info("using self ethernet address: %s", dev_addr);
#endif
#if defined CONFIG_USB_FUNCTIONFS_RNDIS && defined CONFIG_USB_FUNCTIONFS_ETH
gether_set_gadget(net, cdev->gadget);
ret = gether_register_netdev(net);
if (ret)
goto error_rndis;
if (can_support_ecm(cdev->gadget)) {
struct f_ecm_opts *ecm_opts;
ecm_opts = container_of(fi_ecm, struct f_ecm_opts, func_inst);
ecm_opts->bound = true;
} else {
struct f_gether_opts *geth_opts;
geth_opts = container_of(fi_geth, struct f_gether_opts,
func_inst);
geth_opts->bound = true;
}
rndis_borrow_net(fi_rndis, net);
#endif
ret = usb_string_ids_tab(cdev, gfs_strings);
if (unlikely(ret < 0))
goto error_rndis;
gfs_dev_desc.iProduct = gfs_strings[USB_GADGET_PRODUCT_IDX].id;
if (gadget_is_otg(cdev->gadget) && !gfs_otg_desc[0]) {
struct usb_descriptor_header *usb_desc;
usb_desc = usb_otg_descriptor_alloc(cdev->gadget);
if (!usb_desc)
goto error_rndis;
usb_otg_descriptor_init(cdev->gadget, usb_desc);
gfs_otg_desc[0] = usb_desc;
gfs_otg_desc[1] = NULL;
}
for (i = 0; i < ARRAY_SIZE(gfs_configurations); ++i) {
struct gfs_configuration *c = gfs_configurations + i;
int sid = USB_GADGET_FIRST_AVAIL_IDX + i;
c->c.label = gfs_strings[sid].s;
c->c.iConfiguration = gfs_strings[sid].id;
c->c.bConfigurationValue = 1 + i;
c->c.bmAttributes = USB_CONFIG_ATT_SELFPOWER;
c->num = i;
ret = usb_add_config(cdev, &c->c, gfs_do_config);
if (unlikely(ret < 0))
goto error_unbind;
}
usb_composite_overwrite_options(cdev, &coverwrite);
return 0;
error_unbind:
kfree(gfs_otg_desc[0]);
gfs_otg_desc[0] = NULL;
error_rndis:
#ifdef CONFIG_USB_FUNCTIONFS_RNDIS
usb_put_function_instance(fi_rndis);
error:
#endif
#if defined CONFIG_USB_FUNCTIONFS_ETH
if (can_support_ecm(cdev->gadget))
usb_put_function_instance(fi_ecm);
else
usb_put_function_instance(fi_geth);
#endif
return ret;
}
static int gfs_unbind(struct usb_composite_dev *cdev)
{
int i;
ENTER();
#ifdef CONFIG_USB_FUNCTIONFS_RNDIS
usb_put_function(f_rndis);
usb_put_function_instance(fi_rndis);
#endif
#if defined CONFIG_USB_FUNCTIONFS_ETH
if (can_support_ecm(cdev->gadget)) {
usb_put_function(f_ecm);
usb_put_function_instance(fi_ecm);
} else {
usb_put_function(f_geth);
usb_put_function_instance(fi_geth);
}
#endif
for (i = 0; i < N_CONF * func_num; ++i)
usb_put_function(*(f_ffs[0] + i));
kfree(gfs_otg_desc[0]);
gfs_otg_desc[0] = NULL;
return 0;
}
static int gfs_do_config(struct usb_configuration *c)
{
struct gfs_configuration *gc =
container_of(c, struct gfs_configuration, c);
int i;
int ret;
if (missing_funcs)
return -ENODEV;
if (gadget_is_otg(c->cdev->gadget)) {
c->descriptors = gfs_otg_desc;
c->bmAttributes |= USB_CONFIG_ATT_WAKEUP;
}
if (gc->eth) {
ret = gc->eth(c);
if (unlikely(ret < 0))
return ret;
}
for (i = 0; i < func_num; i++) {
f_ffs[gc->num][i] = usb_get_function(fi_ffs[i]);
if (IS_ERR(f_ffs[gc->num][i])) {
ret = PTR_ERR(f_ffs[gc->num][i]);
goto error;
}
ret = usb_add_function(c, f_ffs[gc->num][i]);
if (ret < 0) {
usb_put_function(f_ffs[gc->num][i]);
goto error;
}
}
if (c->next_interface_id < ARRAY_SIZE(c->interface))
c->interface[c->next_interface_id] = NULL;
return 0;
error:
while (--i >= 0) {
if (!IS_ERR(f_ffs[gc->num][i]))
usb_remove_function(c, f_ffs[gc->num][i]);
usb_put_function(f_ffs[gc->num][i]);
}
return ret;
}
static int eth_bind_config(struct usb_configuration *c)
{
int status = 0;
if (can_support_ecm(c->cdev->gadget)) {
f_ecm = usb_get_function(fi_ecm);
if (IS_ERR(f_ecm))
return PTR_ERR(f_ecm);
status = usb_add_function(c, f_ecm);
if (status < 0)
usb_put_function(f_ecm);
} else {
f_geth = usb_get_function(fi_geth);
if (IS_ERR(f_geth))
return PTR_ERR(f_geth);
status = usb_add_function(c, f_geth);
if (status < 0)
usb_put_function(f_geth);
}
return status;
}
static int bind_rndis_config(struct usb_configuration *c)
{
int status = 0;
f_rndis = usb_get_function(fi_rndis);
if (IS_ERR(f_rndis))
return PTR_ERR(f_rndis);
status = usb_add_function(c, f_rndis);
if (status < 0)
usb_put_function(f_rndis);
return status;
}
