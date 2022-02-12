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
static int __init
gser_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_gser *gser = func_to_gser(f);
int status;
struct usb_ep *ep;
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
f->descriptors = usb_copy_descriptors(gser_fs_function);
if (gadget_is_dualspeed(c->cdev->gadget)) {
gser_hs_in_desc.bEndpointAddress =
gser_fs_in_desc.bEndpointAddress;
gser_hs_out_desc.bEndpointAddress =
gser_fs_out_desc.bEndpointAddress;
f->hs_descriptors = usb_copy_descriptors(gser_hs_function);
}
DBG(cdev, "generic ttyGS%d: %s speed IN/%s OUT/%s\n",
gser->port_num,
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
static void
gser_unbind(struct usb_configuration *c, struct usb_function *f)
{
if (gadget_is_dualspeed(c->cdev->gadget))
usb_free_descriptors(f->hs_descriptors);
usb_free_descriptors(f->descriptors);
kfree(func_to_gser(f));
}
int __init gser_bind_config(struct usb_configuration *c, u8 port_num)
{
struct f_gser *gser;
int status;
if (gser_string_defs[0].id == 0) {
status = usb_string_id(c->cdev);
if (status < 0)
return status;
gser_string_defs[0].id = status;
}
gser = kzalloc(sizeof *gser, GFP_KERNEL);
if (!gser)
return -ENOMEM;
gser->port_num = port_num;
gser->port.func.name = "gser";
gser->port.func.strings = gser_strings;
gser->port.func.bind = gser_bind;
gser->port.func.unbind = gser_unbind;
gser->port.func.set_alt = gser_set_alt;
gser->port.func.disable = gser_disable;
status = usb_add_function(c, &gser->port.func);
if (status)
kfree(gser);
return status;
}
