static int __init gfs_init(void)
{
int i;
ENTER();
if (!func_num) {
gfs_single_func = true;
func_num = 1;
}
ffs_tab = kcalloc(func_num, sizeof *ffs_tab, GFP_KERNEL);
if (!ffs_tab)
return -ENOMEM;
if (!gfs_single_func)
for (i = 0; i < func_num; i++)
ffs_tab[i].name = func_names[i];
missing_funcs = func_num;
return functionfs_init();
}
static void __exit gfs_exit(void)
{
ENTER();
mutex_lock(&gfs_lock);
if (gfs_registered)
usb_composite_unregister(&gfs_driver);
gfs_registered = false;
functionfs_cleanup();
mutex_unlock(&gfs_lock);
kfree(ffs_tab);
}
static struct gfs_ffs_obj *gfs_find_dev(const char *dev_name)
{
int i;
ENTER();
if (gfs_single_func)
return &ffs_tab[0];
for (i = 0; i < func_num; i++)
if (strcmp(ffs_tab[i].name, dev_name) == 0)
return &ffs_tab[i];
return NULL;
}
static int functionfs_ready_callback(struct ffs_data *ffs)
{
struct gfs_ffs_obj *ffs_obj;
int ret;
ENTER();
mutex_lock(&gfs_lock);
ffs_obj = ffs->private_data;
if (!ffs_obj) {
ret = -EINVAL;
goto done;
}
if (WARN_ON(ffs_obj->desc_ready)) {
ret = -EBUSY;
goto done;
}
ffs_obj->desc_ready = true;
ffs_obj->ffs_data = ffs;
if (--missing_funcs) {
ret = 0;
goto done;
}
if (gfs_registered) {
ret = -EBUSY;
goto done;
}
gfs_registered = true;
ret = usb_composite_probe(&gfs_driver);
if (unlikely(ret < 0))
gfs_registered = false;
done:
mutex_unlock(&gfs_lock);
return ret;
}
static void functionfs_closed_callback(struct ffs_data *ffs)
{
struct gfs_ffs_obj *ffs_obj;
ENTER();
mutex_lock(&gfs_lock);
ffs_obj = ffs->private_data;
if (!ffs_obj)
goto done;
ffs_obj->desc_ready = false;
missing_funcs++;
if (gfs_registered)
usb_composite_unregister(&gfs_driver);
gfs_registered = false;
done:
mutex_unlock(&gfs_lock);
}
static void *functionfs_acquire_dev_callback(const char *dev_name)
{
struct gfs_ffs_obj *ffs_dev;
ENTER();
mutex_lock(&gfs_lock);
ffs_dev = gfs_find_dev(dev_name);
if (!ffs_dev) {
ffs_dev = ERR_PTR(-ENODEV);
goto done;
}
if (ffs_dev->mounted) {
ffs_dev = ERR_PTR(-EBUSY);
goto done;
}
ffs_dev->mounted = true;
done:
mutex_unlock(&gfs_lock);
return ffs_dev;
}
static void functionfs_release_dev_callback(struct ffs_data *ffs_data)
{
struct gfs_ffs_obj *ffs_dev;
ENTER();
mutex_lock(&gfs_lock);
ffs_dev = ffs_data->private_data;
if (ffs_dev)
ffs_dev->mounted = false;
mutex_unlock(&gfs_lock);
}
static int gfs_bind(struct usb_composite_dev *cdev)
{
int ret, i;
ENTER();
if (missing_funcs)
return -ENODEV;
#if defined CONFIG_USB_FUNCTIONFS_ETH || defined CONFIG_USB_FUNCTIONFS_RNDIS
the_dev = gether_setup(cdev->gadget, dev_addr, host_addr, gfs_host_mac,
qmult);
#endif
if (IS_ERR(the_dev)) {
ret = PTR_ERR(the_dev);
goto error_quick;
}
gfs_ether_setup = true;
ret = usb_string_ids_tab(cdev, gfs_strings);
if (unlikely(ret < 0))
goto error;
gfs_dev_desc.iProduct = gfs_strings[USB_GADGET_PRODUCT_IDX].id;
for (i = func_num; i--; ) {
ret = functionfs_bind(ffs_tab[i].ffs_data, cdev);
if (unlikely(ret < 0)) {
while (++i < func_num)
functionfs_unbind(ffs_tab[i].ffs_data);
goto error;
}
}
for (i = 0; i < ARRAY_SIZE(gfs_configurations); ++i) {
struct gfs_configuration *c = gfs_configurations + i;
int sid = USB_GADGET_FIRST_AVAIL_IDX + i;
c->c.label = gfs_strings[sid].s;
c->c.iConfiguration = gfs_strings[sid].id;
c->c.bConfigurationValue = 1 + i;
c->c.bmAttributes = USB_CONFIG_ATT_SELFPOWER;
ret = usb_add_config(cdev, &c->c, gfs_do_config);
if (unlikely(ret < 0))
goto error_unbind;
}
usb_composite_overwrite_options(cdev, &coverwrite);
return 0;
error_unbind:
for (i = 0; i < func_num; i++)
functionfs_unbind(ffs_tab[i].ffs_data);
error:
gether_cleanup(the_dev);
error_quick:
gfs_ether_setup = false;
return ret;
}
static int gfs_unbind(struct usb_composite_dev *cdev)
{
int i;
ENTER();
if (gfs_ether_setup)
gether_cleanup(the_dev);
gfs_ether_setup = false;
for (i = func_num; i--; )
if (ffs_tab[i].ffs_data)
functionfs_unbind(ffs_tab[i].ffs_data);
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
ret = gc->eth(c, gfs_host_mac, the_dev);
if (unlikely(ret < 0))
return ret;
}
for (i = 0; i < func_num; i++) {
ret = functionfs_bind_config(c->cdev, c, ffs_tab[i].ffs_data);
if (unlikely(ret < 0))
return ret;
}
if (c->next_interface_id < ARRAY_SIZE(c->interface))
c->interface[c->next_interface_id] = NULL;
return 0;
}
static int eth_bind_config(struct usb_configuration *c, u8 ethaddr[ETH_ALEN],
struct eth_dev *dev)
{
return can_support_ecm(c->cdev->gadget)
? ecm_bind_config(c, ethaddr, dev)
: geth_bind_config(c, ethaddr, dev);
}
