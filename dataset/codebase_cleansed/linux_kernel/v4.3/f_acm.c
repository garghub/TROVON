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
dev_dbg(&cdev->gadget->dev, "acm ttyGS%d completion, err %d\n",
acm->port_num, req->status);
return;
}
if (req->actual != sizeof(acm->port_line_coding)) {
dev_dbg(&cdev->gadget->dev, "acm ttyGS%d short resp, len %d\n",
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
dev_vdbg(&cdev->gadget->dev,
"invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
dev_dbg(&cdev->gadget->dev,
"acm ttyGS%d req%02x.%02x v%04x i%04x l%d\n",
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
dev_vdbg(&cdev->gadget->dev,
"reset acm control interface %d\n", intf);
usb_ep_disable(acm->notify);
}
if (!acm->notify->desc)
if (config_ep_by_speed(cdev->gadget, f, acm->notify))
return -EINVAL;
usb_ep_enable(acm->notify);
acm->notify->driver_data = acm;
} else if (intf == acm->data_id) {
if (acm->port.in->driver_data) {
dev_dbg(&cdev->gadget->dev,
"reset acm ttyGS%d\n", acm->port_num);
gserial_disconnect(&acm->port);
}
if (!acm->port.in->desc || !acm->port.out->desc) {
dev_dbg(&cdev->gadget->dev,
"activate acm ttyGS%d\n", acm->port_num);
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
dev_dbg(&cdev->gadget->dev, "acm ttyGS%d deactivated\n", acm->port_num);
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
dev_dbg(&cdev->gadget->dev, "acm ttyGS%d serial state %04x\n",
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
struct usb_string *us;
int status;
struct usb_ep *ep;
us = usb_gstrings_attach(cdev, acm_strings,
ARRAY_SIZE(acm_string_defs));
if (IS_ERR(us))
return PTR_ERR(us);
acm_control_interface_desc.iInterface = us[ACM_CTRL_IDX].id;
acm_data_interface_desc.iInterface = us[ACM_DATA_IDX].id;
acm_iad_descriptor.iFunction = us[ACM_IAD_IDX].id;
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
acm_hs_in_desc.bEndpointAddress = acm_fs_in_desc.bEndpointAddress;
acm_hs_out_desc.bEndpointAddress = acm_fs_out_desc.bEndpointAddress;
acm_hs_notify_desc.bEndpointAddress =
acm_fs_notify_desc.bEndpointAddress;
acm_ss_in_desc.bEndpointAddress = acm_fs_in_desc.bEndpointAddress;
acm_ss_out_desc.bEndpointAddress = acm_fs_out_desc.bEndpointAddress;
status = usb_assign_descriptors(f, acm_fs_function, acm_hs_function,
acm_ss_function);
if (status)
goto fail;
dev_dbg(&cdev->gadget->dev,
"acm ttyGS%d: %s speed IN/%s OUT/%s NOTIFY/%s\n",
acm->port_num,
gadget_is_superspeed(c->cdev->gadget) ? "super" :
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
static void acm_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_acm *acm = func_to_acm(f);
acm_string_defs[0].id = 0;
usb_free_all_descriptors(f);
if (acm->notify_req)
gs_free_req(acm->notify, acm->notify_req);
}
static void acm_free_func(struct usb_function *f)
{
struct f_acm *acm = func_to_acm(f);
kfree(acm);
}
static struct usb_function *acm_alloc_func(struct usb_function_instance *fi)
{
struct f_serial_opts *opts;
struct f_acm *acm;
acm = kzalloc(sizeof(*acm), GFP_KERNEL);
if (!acm)
return ERR_PTR(-ENOMEM);
spin_lock_init(&acm->lock);
acm->port.connect = acm_connect;
acm->port.disconnect = acm_disconnect;
acm->port.send_break = acm_send_break;
acm->port.func.name = "acm";
acm->port.func.strings = acm_strings;
acm->port.func.bind = acm_bind;
acm->port.func.set_alt = acm_set_alt;
acm->port.func.setup = acm_setup;
acm->port.func.disable = acm_disable;
opts = container_of(fi, struct f_serial_opts, func_inst);
acm->port_num = opts->port_num;
acm->port.func.unbind = acm_unbind;
acm->port.func.free_func = acm_free_func;
return &acm->port.func;
}
static inline struct f_serial_opts *to_f_serial_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_serial_opts,
func_inst.group);
}
static ssize_t f_acm_attr_show(struct config_item *item,
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
static void acm_attr_release(struct config_item *item)
{
struct f_serial_opts *opts = to_f_serial_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static ssize_t f_acm_port_num_show(struct f_serial_opts *opts, char *page)
{
return sprintf(page, "%u\n", opts->port_num);
}
static void acm_free_instance(struct usb_function_instance *fi)
{
struct f_serial_opts *opts;
opts = container_of(fi, struct f_serial_opts, func_inst);
gserial_free_line(opts->port_num);
kfree(opts);
}
static struct usb_function_instance *acm_alloc_instance(void)
{
struct f_serial_opts *opts;
int ret;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.free_func_inst = acm_free_instance;
ret = gserial_alloc_line(&opts->port_num);
if (ret) {
kfree(opts);
return ERR_PTR(ret);
}
config_group_init_type_name(&opts->func_inst.group, "",
&acm_func_type);
return &opts->func_inst;
}
