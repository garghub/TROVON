static inline struct f_gser *func_to_gser(struct usb_function *f)
{
return container_of(f, struct f_gser, port.func);
}
static int gser_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_gser *gser = func_to_gser(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (gser->port.in->driver_data) {
DBG(cdev, "reset generic ttyGS%d\n", gser->port_num);
gserial_disconnect(&gser->port);
}
if (!gser->port.in->desc || !gser->port.out->desc) {
DBG(cdev, "activate generic ttyGS%d\n", gser->port_num);
if (config_ep_by_speed(cdev->gadget, f, gser->port.in) ||
config_ep_by_speed(cdev->gadget, f, gser->port.out)) {
gser->port.in->desc = NULL;
gser->port.out->desc = NULL;
return -EINVAL;
}
}
gserial_connect(&gser->port, gser->port_num);
return 0;
}
static void gser_disable(struct usb_function *f)
{
struct f_gser *gser = func_to_gser(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "generic ttyGS%d deactivated\n", gser->port_num);
gserial_disconnect(&gser->port);
}
static int gser_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_gser *gser = func_to_gser(f);
int status;
struct usb_ep *ep;
if (gser_string_defs[0].id == 0) {
status = usb_string_id(c->cdev);
if (status < 0)
return status;
gser_string_defs[0].id = status;
}
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
gser->data_id = status;
gser_interface_desc.bInterfaceNumber = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &gser_fs_in_desc);
if (!ep)
goto fail;
gser->port.in = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &gser_fs_out_desc);
if (!ep)
goto fail;
gser->port.out = ep;
ep->driver_data = cdev;
gser_hs_in_desc.bEndpointAddress = gser_fs_in_desc.bEndpointAddress;
gser_hs_out_desc.bEndpointAddress = gser_fs_out_desc.bEndpointAddress;
gser_ss_in_desc.bEndpointAddress = gser_fs_in_desc.bEndpointAddress;
gser_ss_out_desc.bEndpointAddress = gser_fs_out_desc.bEndpointAddress;
status = usb_assign_descriptors(f, gser_fs_function, gser_hs_function,
gser_ss_function);
if (status)
goto fail;
DBG(cdev, "generic ttyGS%d: %s speed IN/%s OUT/%s\n",
gser->port_num,
gadget_is_superspeed(c->cdev->gadget) ? "super" :
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
gser->port.in->name, gser->port.out->name);
return 0;
fail:
if (gser->port.out)
gser->port.out->driver_data = NULL;
if (gser->port.in)
gser->port.in->driver_data = NULL;
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static inline struct f_serial_opts *to_f_serial_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_serial_opts,
func_inst.group);
}
static ssize_t f_serial_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
struct f_serial_opts *opts = to_f_serial_opts(item);
struct f_serial_opts_attribute *f_serial_opts_attr =
container_of(attr, struct f_serial_opts_attribute, attr);
ssize_t ret = 0;
if (f_serial_opts_attr->show)
ret = f_serial_opts_attr->show(opts, page);
return ret;
}
static void serial_attr_release(struct config_item *item)
{
struct f_serial_opts *opts = to_f_serial_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static ssize_t f_serial_port_num_show(struct f_serial_opts *opts, char *page)
{
return sprintf(page, "%u\n", opts->port_num);
}
static void gser_free_inst(struct usb_function_instance *f)
{
struct f_serial_opts *opts;
opts = container_of(f, struct f_serial_opts, func_inst);
gserial_free_line(opts->port_num);
kfree(opts);
}
static struct usb_function_instance *gser_alloc_inst(void)
{
struct f_serial_opts *opts;
int ret;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.free_func_inst = gser_free_inst;
ret = gserial_alloc_line(&opts->port_num);
if (ret) {
kfree(opts);
return ERR_PTR(ret);
}
config_group_init_type_name(&opts->func_inst.group, "",
&serial_func_type);
return &opts->func_inst;
}
static void gser_free(struct usb_function *f)
{
struct f_gser *serial;
serial = func_to_gser(f);
kfree(serial);
}
static void gser_unbind(struct usb_configuration *c, struct usb_function *f)
{
usb_free_all_descriptors(f);
}
static struct usb_function *gser_alloc(struct usb_function_instance *fi)
{
struct f_gser *gser;
struct f_serial_opts *opts;
gser = kzalloc(sizeof(*gser), GFP_KERNEL);
if (!gser)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_serial_opts, func_inst);
gser->port_num = opts->port_num;
gser->port.func.name = "gser";
gser->port.func.strings = gser_strings;
gser->port.func.bind = gser_bind;
gser->port.func.unbind = gser_unbind;
gser->port.func.set_alt = gser_set_alt;
gser->port.func.disable = gser_disable;
gser->port.func.free_func = gser_free;
return &gser->port.func;
}
