static inline struct f_obex *func_to_obex(struct usb_function *f)
{
return container_of(f, struct f_obex, port.func);
}
static inline struct f_obex *port_to_obex(struct gserial *p)
{
return container_of(p, struct f_obex, port);
}
static int obex_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_obex *obex = func_to_obex(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (intf == obex->ctrl_id) {
if (alt != 0)
goto fail;
dev_dbg(&cdev->gadget->dev,
"reset obex ttyGS%d control\n", obex->port_num);
} else if (intf == obex->data_id) {
if (alt > 1)
goto fail;
if (obex->port.in->enabled) {
dev_dbg(&cdev->gadget->dev,
"reset obex ttyGS%d\n", obex->port_num);
gserial_disconnect(&obex->port);
}
if (!obex->port.in->desc || !obex->port.out->desc) {
dev_dbg(&cdev->gadget->dev,
"init obex ttyGS%d\n", obex->port_num);
if (config_ep_by_speed(cdev->gadget, f,
obex->port.in) ||
config_ep_by_speed(cdev->gadget, f,
obex->port.out)) {
obex->port.out->desc = NULL;
obex->port.in->desc = NULL;
goto fail;
}
}
if (alt == 1) {
dev_dbg(&cdev->gadget->dev,
"activate obex ttyGS%d\n", obex->port_num);
gserial_connect(&obex->port, obex->port_num);
}
} else
goto fail;
obex->cur_alt = alt;
return 0;
fail:
return -EINVAL;
}
static int obex_get_alt(struct usb_function *f, unsigned intf)
{
struct f_obex *obex = func_to_obex(f);
return obex->cur_alt;
}
static void obex_disable(struct usb_function *f)
{
struct f_obex *obex = func_to_obex(f);
struct usb_composite_dev *cdev = f->config->cdev;
dev_dbg(&cdev->gadget->dev, "obex ttyGS%d disable\n", obex->port_num);
gserial_disconnect(&obex->port);
}
static void obex_connect(struct gserial *g)
{
struct f_obex *obex = port_to_obex(g);
struct usb_composite_dev *cdev = g->func.config->cdev;
int status;
status = usb_function_activate(&g->func);
if (status)
dev_dbg(&cdev->gadget->dev,
"obex ttyGS%d function activate --> %d\n",
obex->port_num, status);
}
static void obex_disconnect(struct gserial *g)
{
struct f_obex *obex = port_to_obex(g);
struct usb_composite_dev *cdev = g->func.config->cdev;
int status;
status = usb_function_deactivate(&g->func);
if (status)
dev_dbg(&cdev->gadget->dev,
"obex ttyGS%d function deactivate --> %d\n",
obex->port_num, status);
}
static inline bool can_support_obex(struct usb_configuration *c)
{
if (!gadget_is_altset_supported(c->cdev->gadget))
return false;
return true;
}
static int obex_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_obex *obex = func_to_obex(f);
struct usb_string *us;
int status;
struct usb_ep *ep;
if (!can_support_obex(c))
return -EINVAL;
us = usb_gstrings_attach(cdev, obex_strings,
ARRAY_SIZE(obex_string_defs));
if (IS_ERR(us))
return PTR_ERR(us);
obex_control_intf.iInterface = us[OBEX_CTRL_IDX].id;
obex_data_nop_intf.iInterface = us[OBEX_DATA_IDX].id;
obex_data_intf.iInterface = us[OBEX_DATA_IDX].id;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
obex->ctrl_id = status;
obex_control_intf.bInterfaceNumber = status;
obex_cdc_union_desc.bMasterInterface0 = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
obex->data_id = status;
obex_data_nop_intf.bInterfaceNumber = status;
obex_data_intf.bInterfaceNumber = status;
obex_cdc_union_desc.bSlaveInterface0 = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &obex_fs_ep_in_desc);
if (!ep)
goto fail;
obex->port.in = ep;
ep = usb_ep_autoconfig(cdev->gadget, &obex_fs_ep_out_desc);
if (!ep)
goto fail;
obex->port.out = ep;
obex_hs_ep_in_desc.bEndpointAddress =
obex_fs_ep_in_desc.bEndpointAddress;
obex_hs_ep_out_desc.bEndpointAddress =
obex_fs_ep_out_desc.bEndpointAddress;
status = usb_assign_descriptors(f, fs_function, hs_function, NULL);
if (status)
goto fail;
dev_dbg(&cdev->gadget->dev, "obex ttyGS%d: %s speed IN/%s OUT/%s\n",
obex->port_num,
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
obex->port.in->name, obex->port.out->name);
return 0;
fail:
ERROR(cdev, "%s/%p: can't bind, err %d\n", f->name, f, status);
return status;
}
static inline struct f_serial_opts *to_f_serial_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_serial_opts,
func_inst.group);
}
static void obex_attr_release(struct config_item *item)
{
struct f_serial_opts *opts = to_f_serial_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static ssize_t f_obex_port_num_show(struct config_item *item, char *page)
{
return sprintf(page, "%u\n", to_f_serial_opts(item)->port_num);
}
static void obex_free_inst(struct usb_function_instance *f)
{
struct f_serial_opts *opts;
opts = container_of(f, struct f_serial_opts, func_inst);
gserial_free_line(opts->port_num);
kfree(opts);
}
static struct usb_function_instance *obex_alloc_inst(void)
{
struct f_serial_opts *opts;
int ret;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.free_func_inst = obex_free_inst;
ret = gserial_alloc_line(&opts->port_num);
if (ret) {
kfree(opts);
return ERR_PTR(ret);
}
config_group_init_type_name(&opts->func_inst.group, "",
&obex_func_type);
return &opts->func_inst;
}
static void obex_free(struct usb_function *f)
{
struct f_obex *obex;
obex = func_to_obex(f);
kfree(obex);
}
static void obex_unbind(struct usb_configuration *c, struct usb_function *f)
{
usb_free_all_descriptors(f);
}
static struct usb_function *obex_alloc(struct usb_function_instance *fi)
{
struct f_obex *obex;
struct f_serial_opts *opts;
obex = kzalloc(sizeof(*obex), GFP_KERNEL);
if (!obex)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_serial_opts, func_inst);
obex->port_num = opts->port_num;
obex->port.connect = obex_connect;
obex->port.disconnect = obex_disconnect;
obex->port.func.name = "obex";
obex->port.func.bind = obex_bind;
obex->port.func.unbind = obex_unbind;
obex->port.func.set_alt = obex_set_alt;
obex->port.func.get_alt = obex_get_alt;
obex->port.func.disable = obex_disable;
obex->port.func.free_func = obex_free;
obex->port.func.bind_deactivated = true;
return &obex->port.func;
}
