static inline struct f_acm *func_to_acm(struct usb_function *f)
{
return container_of(f, struct f_acm, port.func);
}
static inline struct f_acm *port_to_acm(struct gserial *p)
{
return container_of(p, struct f_acm, port);
}
static void acm_complete_set_line_coding(struct usb_ep *ep,
struct usb_request *req)
{
struct f_acm *acm = ep->driver_data;
struct usb_composite_dev *cdev = acm->port.func.config->cdev;
if (req->status != 0) {
DBG(cdev, "acm ttyGS%d completion, err %d\n",
acm->port_num, req->status);
return;
}
if (req->actual != sizeof(acm->port_line_coding)) {
DBG(cdev, "acm ttyGS%d short resp, len %d\n",
acm->port_num, req->actual);
usb_ep_set_halt(ep);
} else {
struct usb_cdc_line_coding *value = req->buf;
acm->port_line_coding = *value;
}
}
static int acm_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct f_acm *acm = func_to_acm(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
switch ((ctrl->bRequestType << 8) | ctrl->bRequest) {
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_REQ_SET_LINE_CODING:
if (w_length != sizeof(struct usb_cdc_line_coding)
|| w_index != acm->ctrl_id)
goto invalid;
value = w_length;
cdev->gadget->ep0->driver_data = acm;
req->complete = acm_complete_set_line_coding;
break;
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_REQ_GET_LINE_CODING:
if (w_index != acm->ctrl_id)
goto invalid;
value = min_t(unsigned, w_length,
sizeof(struct usb_cdc_line_coding));
memcpy(req->buf, &acm->port_line_coding, value);
break;
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_REQ_SET_CONTROL_LINE_STATE:
if (w_index != acm->ctrl_id)
goto invalid;
value = 0;
acm->port_handshake_bits = w_value;
break;
default:
invalid:
VDBG(cdev, "invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
DBG(cdev, "acm ttyGS%d req%02x.%02x v%04x i%04x l%d\n",
acm->port_num, ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
req->zero = 0;
req->length = value;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0)
ERROR(cdev, "acm response on ttyGS%d, err %d\n",
acm->port_num, value);
}
return value;
}
static int acm_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_acm *acm = func_to_acm(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (intf == acm->ctrl_id) {
if (acm->notify->driver_data) {
VDBG(cdev, "reset acm control interface %d\n", intf);
usb_ep_disable(acm->notify);
} else {
VDBG(cdev, "init acm ctrl interface %d\n", intf);
if (config_ep_by_speed(cdev->gadget, f, acm->notify))
return -EINVAL;
}
usb_ep_enable(acm->notify);
acm->notify->driver_data = acm;
} else if (intf == acm->data_id) {
if (acm->port.in->driver_data) {
DBG(cdev, "reset acm ttyGS%d\n", acm->port_num);
gserial_disconnect(&acm->port);
}
if (!acm->port.in->desc || !acm->port.out->desc) {
DBG(cdev, "activate acm ttyGS%d\n", acm->port_num);
if (config_ep_by_speed(cdev->gadget, f,
acm->port.in) ||
config_ep_by_speed(cdev->gadget, f,
acm->port.out)) {
acm->port.in->desc = NULL;
acm->port.out->desc = NULL;
return -EINVAL;
}
}
gserial_connect(&acm->port, acm->port_num);
} else
return -EINVAL;
return 0;
}
static void acm_disable(struct usb_function *f)
{
struct f_acm *acm = func_to_acm(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "acm ttyGS%d deactivated\n", acm->port_num);
gserial_disconnect(&acm->port);
usb_ep_disable(acm->notify);
acm->notify->driver_data = NULL;
}
static int acm_cdc_notify(struct f_acm *acm, u8 type, u16 value,
void *data, unsigned length)
{
struct usb_ep *ep = acm->notify;
struct usb_request *req;
struct usb_cdc_notification *notify;
const unsigned len = sizeof(*notify) + length;
void *buf;
int status;
req = acm->notify_req;
acm->notify_req = NULL;
acm->pending = false;
req->length = len;
notify = req->buf;
buf = notify + 1;
notify->bmRequestType = USB_DIR_IN | USB_TYPE_CLASS
| USB_RECIP_INTERFACE;
notify->bNotificationType = type;
notify->wValue = cpu_to_le16(value);
notify->wIndex = cpu_to_le16(acm->ctrl_id);
notify->wLength = cpu_to_le16(length);
memcpy(buf, data, length);
spin_unlock(&acm->lock);
status = usb_ep_queue(ep, req, GFP_ATOMIC);
spin_lock(&acm->lock);
if (status < 0) {
ERROR(acm->port.func.config->cdev,
"acm ttyGS%d can't notify serial state, %d\n",
acm->port_num, status);
acm->notify_req = req;
}
return status;
}
static int acm_notify_serial_state(struct f_acm *acm)
{
struct usb_composite_dev *cdev = acm->port.func.config->cdev;
int status;
spin_lock(&acm->lock);
if (acm->notify_req) {
DBG(cdev, "acm ttyGS%d serial state %04x\n",
acm->port_num, acm->serial_state);
status = acm_cdc_notify(acm, USB_CDC_NOTIFY_SERIAL_STATE,
0, &acm->serial_state, sizeof(acm->serial_state));
} else {
acm->pending = true;
status = 0;
}
spin_unlock(&acm->lock);
return status;
}
static void acm_cdc_notify_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_acm *acm = req->context;
u8 doit = false;
spin_lock(&acm->lock);
if (req->status != -ESHUTDOWN)
doit = acm->pending;
acm->notify_req = req;
spin_unlock(&acm->lock);
if (doit)
acm_notify_serial_state(acm);
}
static void acm_connect(struct gserial *port)
{
struct f_acm *acm = port_to_acm(port);
acm->serial_state |= ACM_CTRL_DSR | ACM_CTRL_DCD;
acm_notify_serial_state(acm);
}
static void acm_disconnect(struct gserial *port)
{
struct f_acm *acm = port_to_acm(port);
acm->serial_state &= ~(ACM_CTRL_DSR | ACM_CTRL_DCD);
acm_notify_serial_state(acm);
}
static int acm_send_break(struct gserial *port, int duration)
{
struct f_acm *acm = port_to_acm(port);
u16 state;
state = acm->serial_state;
state &= ~ACM_CTRL_BRK;
if (duration)
state |= ACM_CTRL_BRK;
acm->serial_state = state;
return acm_notify_serial_state(acm);
}
static int
acm_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_acm *acm = func_to_acm(f);
int status;
struct usb_ep *ep;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
acm->ctrl_id = status;
acm_iad_descriptor.bFirstInterface = status;
acm_control_interface_desc.bInterfaceNumber = status;
acm_union_desc .bMasterInterface0 = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
acm->data_id = status;
acm_data_interface_desc.bInterfaceNumber = status;
acm_union_desc.bSlaveInterface0 = status;
acm_call_mgmt_descriptor.bDataInterface = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &acm_fs_in_desc);
if (!ep)
goto fail;
acm->port.in = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &acm_fs_out_desc);
if (!ep)
goto fail;
acm->port.out = ep;
ep->driver_data = cdev;
ep = usb_ep_autoconfig(cdev->gadget, &acm_fs_notify_desc);
if (!ep)
goto fail;
acm->notify = ep;
ep->driver_data = cdev;
acm->notify_req = gs_alloc_req(ep,
sizeof(struct usb_cdc_notification) + 2,
GFP_KERNEL);
if (!acm->notify_req)
goto fail;
acm->notify_req->complete = acm_cdc_notify_complete;
acm->notify_req->context = acm;
f->descriptors = usb_copy_descriptors(acm_fs_function);
if (!f->descriptors)
goto fail;
if (gadget_is_dualspeed(c->cdev->gadget)) {
acm_hs_in_desc.bEndpointAddress =
acm_fs_in_desc.bEndpointAddress;
acm_hs_out_desc.bEndpointAddress =
acm_fs_out_desc.bEndpointAddress;
acm_hs_notify_desc.bEndpointAddress =
acm_fs_notify_desc.bEndpointAddress;
f->hs_descriptors = usb_copy_descriptors(acm_hs_function);
}
DBG(cdev, "acm ttyGS%d: %s speed IN/%s OUT/%s NOTIFY/%s\n",
acm->port_num,
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
acm->port.in->name, acm->port.out->name,
acm->notify->name);
return 0;
fail:
if (acm->notify_req)
gs_free_req(acm->notify, acm->notify_req);
if (acm->notify)
acm->notify->driver_data = NULL;
if (acm->port.out)
acm->port.out->driver_data = NULL;
if (acm->port.in)
acm->port.in->driver_data = NULL;
ERROR(cdev, "%s/%p: can't bind, err %d\n", f->name, f, status);
return status;
}
static void
acm_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_acm *acm = func_to_acm(f);
if (gadget_is_dualspeed(c->cdev->gadget))
usb_free_descriptors(f->hs_descriptors);
usb_free_descriptors(f->descriptors);
gs_free_req(acm->notify, acm->notify_req);
kfree(acm);
}
static inline bool can_support_cdc(struct usb_configuration *c)
{
return true;
}
int acm_bind_config(struct usb_configuration *c, u8 port_num)
{
struct f_acm *acm;
int status;
if (!can_support_cdc(c))
return -EINVAL;
if (acm_string_defs[ACM_CTRL_IDX].id == 0) {
status = usb_string_id(c->cdev);
if (status < 0)
return status;
acm_string_defs[ACM_CTRL_IDX].id = status;
acm_control_interface_desc.iInterface = status;
status = usb_string_id(c->cdev);
if (status < 0)
return status;
acm_string_defs[ACM_DATA_IDX].id = status;
acm_data_interface_desc.iInterface = status;
status = usb_string_id(c->cdev);
if (status < 0)
return status;
acm_string_defs[ACM_IAD_IDX].id = status;
acm_iad_descriptor.iFunction = status;
}
acm = kzalloc(sizeof *acm, GFP_KERNEL);
if (!acm)
return -ENOMEM;
spin_lock_init(&acm->lock);
acm->port_num = port_num;
acm->port.connect = acm_connect;
acm->port.disconnect = acm_disconnect;
acm->port.send_break = acm_send_break;
acm->port.func.name = "acm";
acm->port.func.strings = acm_strings;
acm->port.func.bind = acm_bind;
acm->port.func.unbind = acm_unbind;
acm->port.func.set_alt = acm_set_alt;
acm->port.func.setup = acm_setup;
acm->port.func.disable = acm_disable;
status = usb_add_function(c, &acm->port.func);
if (status)
kfree(acm);
return status;
}
