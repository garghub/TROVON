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
DBG(cdev, "reset obex ttyGS%d control\n", obex->port_num);
} else if (intf == obex->data_id) {
if (alt > 1)
goto fail;
if (obex->port.in->driver_data) {
DBG(cdev, "reset obex ttyGS%d\n", obex->port_num);
gserial_disconnect(&obex->port);
}
if (!obex->port.in->desc || !obex->port.out->desc) {
DBG(cdev, "init obex ttyGS%d\n", obex->port_num);
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
DBG(cdev, "activate obex ttyGS%d\n", obex->port_num);
gserial_connect(&obex->port, obex->port_num);
}
} else
goto fail;
return 0;
fail:
return -EINVAL;
}
static int obex_get_alt(struct usb_function *f, unsigned intf)
{
struct f_obex *obex = func_to_obex(f);
if (intf == obex->ctrl_id)
return 0;
return obex->port.in->driver_data ? 1 : 0;
}
static void obex_disable(struct usb_function *f)
{
struct f_obex *obex = func_to_obex(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "obex ttyGS%d disable\n", obex->port_num);
gserial_disconnect(&obex->port);
}
static void obex_connect(struct gserial *g)
{
struct f_obex *obex = port_to_obex(g);
struct usb_composite_dev *cdev = g->func.config->cdev;
int status;
if (!obex->can_activate)
return;
status = usb_function_activate(&g->func);
if (status)
DBG(cdev, "obex ttyGS%d function activate --> %d\n",
obex->port_num, status);
}
static void obex_disconnect(struct gserial *g)
{
struct f_obex *obex = port_to_obex(g);
struct usb_composite_dev *cdev = g->func.config->cdev;
int status;
if (!obex->can_activate)
return;
status = usb_function_deactivate(&g->func);
if (status)
DBG(cdev, "obex ttyGS%d function deactivate --> %d\n",
obex->port_num, status);
}
static int __init
obex_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_obex *obex = func_to_obex(f);
int status;
struct usb_ep *ep;
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
ep = usb_ep_autoconfig(cdev->gadget, &obex_fs_ep_in_desc);
if (!ep)
goto fail;
obex->port.in = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &obex_fs_ep_out_desc);
if (!ep)
goto fail;
obex->port.out = ep;
ep->driver_data = cdev;
f->descriptors = usb_copy_descriptors(fs_function);
if (gadget_is_dualspeed(c->cdev->gadget)) {
obex_hs_ep_in_desc.bEndpointAddress =
obex_fs_ep_in_desc.bEndpointAddress;
obex_hs_ep_out_desc.bEndpointAddress =
obex_fs_ep_out_desc.bEndpointAddress;
f->hs_descriptors = usb_copy_descriptors(hs_function);
}
status = usb_function_deactivate(f);
if (status < 0)
WARNING(cdev, "obex ttyGS%d: can't prevent enumeration, %d\n",
obex->port_num, status);
else
obex->can_activate = true;
DBG(cdev, "obex ttyGS%d: %s speed IN/%s OUT/%s\n",
obex->port_num,
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
obex->port.in->name, obex->port.out->name);
return 0;
fail:
if (obex->port.out)
obex->port.out->driver_data = NULL;
if (obex->port.in)
obex->port.in->driver_data = NULL;
ERROR(cdev, "%s/%p: can't bind, err %d\n", f->name, f, status);
return status;
}
static void
obex_unbind(struct usb_configuration *c, struct usb_function *f)
{
if (gadget_is_dualspeed(c->cdev->gadget))
usb_free_descriptors(f->hs_descriptors);
usb_free_descriptors(f->descriptors);
kfree(func_to_obex(f));
}
static inline bool can_support_obex(struct usb_configuration *c)
{
if (!gadget_supports_altsettings(c->cdev->gadget))
return false;
return true;
}
int __init obex_bind_config(struct usb_configuration *c, u8 port_num)
{
struct f_obex *obex;
int status;
if (!can_support_obex(c))
return -EINVAL;
if (obex_string_defs[OBEX_CTRL_IDX].id == 0) {
status = usb_string_id(c->cdev);
if (status < 0)
return status;
obex_string_defs[OBEX_CTRL_IDX].id = status;
obex_control_intf.iInterface = status;
status = usb_string_id(c->cdev);
if (status < 0)
return status;
obex_string_defs[OBEX_DATA_IDX].id = status;
obex_data_nop_intf.iInterface =
obex_data_intf.iInterface = status;
}
obex = kzalloc(sizeof *obex, GFP_KERNEL);
if (!obex)
return -ENOMEM;
obex->port_num = port_num;
obex->port.connect = obex_connect;
obex->port.disconnect = obex_disconnect;
obex->port.func.name = "obex";
obex->port.func.strings = obex_strings;
obex->port.func.bind = obex_bind;
obex->port.func.unbind = obex_unbind;
obex->port.func.set_alt = obex_set_alt;
obex->port.func.get_alt = obex_get_alt;
obex->port.func.disable = obex_disable;
status = usb_add_function(c, &obex->port.func);
if (status)
kfree(obex);
return status;
}
