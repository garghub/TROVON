static spinlock_t *usbhsg_trylock(struct usbhsg_gpriv *gpriv,
unsigned long *flags)
{
spinlock_t *lock = usbhsg_gpriv_to_lock(gpriv);
if (spin_is_locked(lock))
return NULL;
spin_lock_irqsave(lock, *flags);
return lock;
}
static void usbhsg_unlock(spinlock_t *lock, unsigned long *flags)
{
if (!lock)
return;
spin_unlock_irqrestore(lock, *flags);
}
static void usbhsg_queue_push(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
list_del_init(&ureq->node);
list_add_tail(&ureq->node, &uep->list);
ureq->req.actual = 0;
ureq->req.status = -EINPROGRESS;
dev_dbg(dev, "pipe %d : queue push (%d)\n",
usbhs_pipe_number(pipe),
ureq->req.length);
}
static struct usbhsg_request *usbhsg_queue_get(struct usbhsg_uep *uep)
{
if (list_empty(&uep->list))
return NULL;
return list_entry(uep->list.next, struct usbhsg_request, node);
}
static int __usbhsg_queue_handler(struct usbhsg_uep *uep, int prepare)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usbhsg_request *ureq;
spinlock_t *lock;
unsigned long flags;
int ret = 0;
if (!uep->handler) {
dev_err(dev, "no handler function\n");
return -EIO;
}
lock = usbhsg_trylock(gpriv, &flags);
ureq = usbhsg_queue_get(uep);
if (ureq) {
if (prepare)
ret = uep->handler->prepare(uep, ureq);
else
ret = uep->handler->try_run(uep, ureq);
}
usbhsg_unlock(lock, &flags);
return ret;
}
static void usbhsg_queue_pop(struct usbhsg_uep *uep,
struct usbhsg_request *ureq,
int status)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
dev_dbg(dev, "pipe %d : queue pop\n", usbhs_pipe_number(pipe));
list_del_init(&ureq->node);
ureq->req.status = status;
ureq->req.complete(&uep->ep, &ureq->req);
if (0 == status)
usbhsg_queue_prepare(uep);
}
static void usbhsg_irq_empty_ctrl(struct usbhsg_uep *uep, int enable)
{
usbhsg_irq_callback_ctrl(uep, bempsts, enable);
}
static void usbhsg_irq_ready_ctrl(struct usbhsg_uep *uep, int enable)
{
usbhsg_irq_callback_ctrl(uep, brdysts, enable);
}
static int usbhsg_try_run_ctrl_stage_end(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
usbhs_dcp_control_transfer_done(pipe);
usbhsg_queue_pop(uep, ureq, 0);
return 0;
}
static int usbhsg_try_run_send_packet(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usb_request *req = &ureq->req;
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
void *buf;
int remainder, send;
int is_done = 0;
int enable;
int maxp;
maxp = usbhs_pipe_get_maxpacket(pipe);
buf = req->buf + req->actual;
remainder = req->length - req->actual;
send = usbhs_fifo_write(pipe, buf, remainder);
if (send > 0)
req->actual += send;
if (send < remainder)
is_done = 0;
else if (send < maxp)
is_done = 1;
else
is_done = !req->zero;
dev_dbg(dev, " send %d (%d/ %d/ %d/ %d)\n",
usbhs_pipe_number(pipe),
remainder, send, is_done, req->zero);
enable = !is_done;
uep->handler->irq_mask(uep, enable);
usbhs_fifo_enable(pipe);
if (is_done) {
if (usbhsg_is_dcp(uep))
usbhs_dcp_control_transfer_done(pipe);
usbhsg_queue_pop(uep, ureq, 0);
}
return 0;
}
static int usbhsg_prepare_send_packet(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
usbhs_fifo_prepare_write(pipe);
usbhsg_try_run_send_packet(uep, ureq);
return 0;
}
static int usbhsg_try_run_receive_packet(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usb_request *req = &ureq->req;
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
void *buf;
int maxp;
int remainder, recv;
int is_done = 0;
maxp = usbhs_pipe_get_maxpacket(pipe);
buf = req->buf + req->actual;
remainder = req->length - req->actual;
recv = usbhs_fifo_read(pipe, buf, remainder);
if (recv < 0)
return -EBUSY;
req->actual += recv;
if ((recv == remainder) ||
(recv < maxp))
is_done = 1;
dev_dbg(dev, " recv %d (%d/ %d/ %d/ %d)\n",
usbhs_pipe_number(pipe),
remainder, recv, is_done, req->zero);
if (is_done) {
int disable = 0;
uep->handler->irq_mask(uep, disable);
usbhs_fifo_disable(pipe);
usbhsg_queue_pop(uep, ureq, 0);
}
return 0;
}
static int usbhsg_prepare_receive_packet(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
int enable = 1;
int ret;
ret = usbhs_fifo_prepare_read(pipe);
if (ret < 0)
return ret;
uep->handler->irq_mask(uep, enable);
return ret;
}
static int usbhsg_recip_handler_std_control_done(struct usbhs_priv *priv,
struct usbhsg_uep *uep,
struct usb_ctrlrequest *ctrl)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhsg_uep *dcp = usbhsg_gpriv_to_dcp(gpriv);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(dcp);
usbhs_dcp_control_transfer_done(pipe);
return 0;
}
static int usbhsg_recip_handler_std_clear_endpoint(struct usbhs_priv *priv,
struct usbhsg_uep *uep,
struct usb_ctrlrequest *ctrl)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
if (!usbhsg_status_has(gpriv, USBHSG_STATUS_WEDGE)) {
usbhs_fifo_disable(pipe);
usbhs_pipe_clear_sequence(pipe);
usbhs_fifo_enable(pipe);
}
usbhsg_recip_handler_std_control_done(priv, uep, ctrl);
usbhsg_queue_prepare(uep);
return 0;
}
static int usbhsg_recip_run_handle(struct usbhs_priv *priv,
struct usbhsg_recip_handle *handler,
struct usb_ctrlrequest *ctrl)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usbhsg_uep *uep;
int recip = ctrl->bRequestType & USB_RECIP_MASK;
int nth = le16_to_cpu(ctrl->wIndex) & USB_ENDPOINT_NUMBER_MASK;
int ret;
int (*func)(struct usbhs_priv *priv, struct usbhsg_uep *uep,
struct usb_ctrlrequest *ctrl);
char *msg;
uep = usbhsg_gpriv_to_nth_uep(gpriv, nth);
if (!usbhsg_uep_to_pipe(uep)) {
dev_err(dev, "wrong recip request\n");
return -EINVAL;
}
switch (recip) {
case USB_RECIP_DEVICE:
msg = "DEVICE";
func = handler->device;
break;
case USB_RECIP_INTERFACE:
msg = "INTERFACE";
func = handler->interface;
break;
case USB_RECIP_ENDPOINT:
msg = "ENDPOINT";
func = handler->endpoint;
break;
default:
dev_warn(dev, "unsupported RECIP(%d)\n", recip);
func = NULL;
ret = -EINVAL;
}
if (func) {
dev_dbg(dev, "%s (pipe %d :%s)\n", handler->name, nth, msg);
ret = func(priv, uep, ctrl);
}
return ret;
}
static int usbhsg_irq_dev_state(struct usbhs_priv *priv,
struct usbhs_irq_state *irq_state)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
gpriv->gadget.speed = usbhs_status_get_usb_speed(irq_state);
dev_dbg(dev, "state = %x : speed : %d\n",
usbhs_status_get_device_state(irq_state),
gpriv->gadget.speed);
return 0;
}
static int usbhsg_irq_ctrl_stage(struct usbhs_priv *priv,
struct usbhs_irq_state *irq_state)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhsg_uep *dcp = usbhsg_gpriv_to_dcp(gpriv);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(dcp);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usb_ctrlrequest ctrl;
struct usbhsg_recip_handle *recip_handler = NULL;
int stage = usbhs_status_get_ctrl_stage(irq_state);
int ret = 0;
dev_dbg(dev, "stage = %d\n", stage);
switch (stage) {
case READ_DATA_STAGE:
dcp->handler = &usbhsg_handler_send_ctrl;
break;
case WRITE_DATA_STAGE:
dcp->handler = &usbhsg_handler_recv_ctrl;
break;
case NODATA_STATUS_STAGE:
dcp->handler = &usbhsg_handler_ctrl_stage_end;
break;
default:
return ret;
}
usbhs_usbreq_get_val(priv, &ctrl);
switch (ctrl.bRequestType & USB_TYPE_MASK) {
case USB_TYPE_STANDARD:
switch (ctrl.bRequest) {
case USB_REQ_CLEAR_FEATURE:
recip_handler = &req_clear_feature;
break;
}
}
if (recip_handler)
ret = usbhsg_recip_run_handle(priv, recip_handler, &ctrl);
else
ret = gpriv->driver->setup(&gpriv->gadget, &ctrl);
if (ret < 0)
usbhs_fifo_stall(pipe);
return ret;
}
static int usbhsg_irq_empty(struct usbhs_priv *priv,
struct usbhs_irq_state *irq_state)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhsg_uep *uep;
struct usbhs_pipe *pipe;
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
int i, ret;
if (!irq_state->bempsts) {
dev_err(dev, "debug %s !!\n", __func__);
return -EIO;
}
dev_dbg(dev, "irq empty [0x%04x]\n", irq_state->bempsts);
usbhs_for_each_pipe_with_dcp(pipe, priv, i) {
if (!(irq_state->bempsts & (1 << i)))
continue;
uep = usbhsg_pipe_to_uep(pipe);
ret = usbhsg_queue_handle(uep);
if (ret < 0)
dev_err(dev, "send error %d : %d\n", i, ret);
}
return 0;
}
static int usbhsg_irq_ready(struct usbhs_priv *priv,
struct usbhs_irq_state *irq_state)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhsg_uep *uep;
struct usbhs_pipe *pipe;
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
int i, ret;
if (!irq_state->brdysts) {
dev_err(dev, "debug %s !!\n", __func__);
return -EIO;
}
dev_dbg(dev, "irq ready [0x%04x]\n", irq_state->brdysts);
usbhs_for_each_pipe_with_dcp(pipe, priv, i) {
if (!(irq_state->brdysts & (1 << i)))
continue;
uep = usbhsg_pipe_to_uep(pipe);
ret = usbhsg_queue_handle(uep);
if (ret < 0)
dev_err(dev, "receive error %d : %d\n", i, ret);
}
return 0;
}
static int usbhsg_dcp_enable(struct usbhsg_uep *uep)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_priv *priv = usbhsg_gpriv_to_priv(gpriv);
struct usbhs_pipe *pipe;
pipe = usbhs_dcp_malloc(priv);
if (!pipe)
return -EIO;
uep->pipe = pipe;
uep->pipe->mod_private = uep;
INIT_LIST_HEAD(&uep->list);
return 0;
}
static int usbhsg_pipe_disable(struct usbhsg_uep *uep)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usbhsg_request *ureq;
int disable = 0;
usbhs_fifo_disable(pipe);
usbhsg_irq_empty_ctrl(uep, disable);
usbhsg_irq_ready_ctrl(uep, disable);
while (1) {
ureq = usbhsg_queue_get(uep);
if (!ureq)
break;
usbhsg_queue_pop(uep, ureq, -ECONNRESET);
}
return 0;
}
static void usbhsg_uep_init(struct usbhsg_gpriv *gpriv)
{
int i;
struct usbhsg_uep *uep;
usbhsg_for_each_uep_with_dcp(uep, gpriv, i)
uep->pipe = NULL;
}
static int usbhsg_ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_priv *priv = usbhsg_gpriv_to_priv(gpriv);
struct usbhs_pipe *pipe;
spinlock_t *lock;
unsigned long flags;
int ret = -EIO;
if (uep->pipe)
return 0;
lock = usbhsg_trylock(gpriv, &flags);
pipe = usbhs_pipe_malloc(priv, desc);
if (pipe) {
uep->pipe = pipe;
pipe->mod_private = uep;
INIT_LIST_HEAD(&uep->list);
if (usb_endpoint_dir_in(desc))
uep->handler = &usbhsg_handler_send_packet;
else
uep->handler = &usbhsg_handler_recv_packet;
ret = 0;
}
usbhsg_unlock(lock, &flags);
return ret;
}
static int usbhsg_ep_disable(struct usb_ep *ep)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
spinlock_t *lock;
unsigned long flags;
int ret;
lock = usbhsg_trylock(gpriv, &flags);
ret = usbhsg_pipe_disable(uep);
usbhsg_unlock(lock, &flags);
return ret;
}
static struct usb_request *usbhsg_ep_alloc_request(struct usb_ep *ep,
gfp_t gfp_flags)
{
struct usbhsg_request *ureq;
ureq = kzalloc(sizeof *ureq, gfp_flags);
if (!ureq)
return NULL;
INIT_LIST_HEAD(&ureq->node);
return &ureq->req;
}
static void usbhsg_ep_free_request(struct usb_ep *ep,
struct usb_request *req)
{
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
WARN_ON(!list_empty(&ureq->node));
kfree(ureq);
}
static int usbhsg_ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t gfp_flags)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
spinlock_t *lock;
unsigned long flags;
int ret = 0;
lock = usbhsg_trylock(gpriv, &flags);
if (usbhsg_is_not_connected(gpriv) ||
unlikely(!gpriv->driver) ||
unlikely(!pipe))
ret = -ESHUTDOWN;
else
usbhsg_queue_push(uep, ureq);
usbhsg_unlock(lock, &flags);
usbhsg_queue_prepare(uep);
return ret;
}
static int usbhsg_ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
spinlock_t *lock;
unsigned long flags;
lock = usbhsg_trylock(gpriv, &flags);
usbhsg_queue_pop(uep, ureq, -ECONNRESET);
usbhsg_unlock(lock, &flags);
return 0;
}
static int __usbhsg_ep_set_halt_wedge(struct usb_ep *ep, int halt, int wedge)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
spinlock_t *lock;
unsigned long flags;
int ret = -EAGAIN;
lock = usbhsg_trylock(gpriv, &flags);
if (!usbhsg_queue_get(uep)) {
dev_dbg(dev, "set halt %d (pipe %d)\n",
halt, usbhs_pipe_number(pipe));
if (halt)
usbhs_fifo_stall(pipe);
else
usbhs_fifo_disable(pipe);
if (halt && wedge)
usbhsg_status_set(gpriv, USBHSG_STATUS_WEDGE);
else
usbhsg_status_clr(gpriv, USBHSG_STATUS_WEDGE);
ret = 0;
}
usbhsg_unlock(lock, &flags);
return ret;
}
static int usbhsg_ep_set_halt(struct usb_ep *ep, int value)
{
return __usbhsg_ep_set_halt_wedge(ep, value, 0);
}
static int usbhsg_ep_set_wedge(struct usb_ep *ep)
{
return __usbhsg_ep_set_halt_wedge(ep, 1, 1);
}
static int usbhsg_try_start(struct usbhs_priv *priv, u32 status)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhsg_uep *dcp = usbhsg_gpriv_to_dcp(gpriv);
struct usbhs_mod *mod = usbhs_mod_get_current(priv);
struct device *dev = usbhs_priv_to_dev(priv);
spinlock_t *lock;
unsigned long flags;
lock = usbhsg_trylock(gpriv, &flags);
usbhsg_status_set(gpriv, status);
if (!(usbhsg_status_has(gpriv, USBHSG_STATUS_STARTED) &&
usbhsg_status_has(gpriv, USBHSG_STATUS_REGISTERD)))
goto usbhsg_try_start_unlock;
dev_dbg(dev, "start gadget\n");
usbhs_pipe_init(priv);
usbhsg_uep_init(gpriv);
usbhsg_dcp_enable(dcp);
usbhs_sys_hispeed_ctrl(priv, 1);
usbhs_sys_function_ctrl(priv, 1);
usbhs_sys_usb_ctrl(priv, 1);
mod->irq_dev_state = usbhsg_irq_dev_state;
mod->irq_ctrl_stage = usbhsg_irq_ctrl_stage;
mod->irq_empty = usbhsg_irq_empty;
mod->irq_ready = usbhsg_irq_ready;
mod->irq_bempsts = 0;
mod->irq_brdysts = 0;
usbhs_irq_callback_update(priv, mod);
usbhsg_try_start_unlock:
usbhsg_unlock(lock, &flags);
return 0;
}
static int usbhsg_try_stop(struct usbhs_priv *priv, u32 status)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhs_mod *mod = usbhs_mod_get_current(priv);
struct usbhsg_uep *dcp = usbhsg_gpriv_to_dcp(gpriv);
struct device *dev = usbhs_priv_to_dev(priv);
spinlock_t *lock;
unsigned long flags;
lock = usbhsg_trylock(gpriv, &flags);
usbhsg_status_clr(gpriv, status);
if (!usbhsg_status_has(gpriv, USBHSG_STATUS_STARTED) &&
!usbhsg_status_has(gpriv, USBHSG_STATUS_REGISTERD))
goto usbhsg_try_stop_unlock;
mod->irq_dev_state = NULL;
mod->irq_ctrl_stage = NULL;
mod->irq_empty = NULL;
mod->irq_ready = NULL;
mod->irq_bempsts = 0;
mod->irq_brdysts = 0;
usbhs_irq_callback_update(priv, mod);
usbhsg_dcp_disable(dcp);
gpriv->gadget.speed = USB_SPEED_UNKNOWN;
usbhs_sys_hispeed_ctrl(priv, 0);
usbhs_sys_function_ctrl(priv, 0);
usbhs_sys_usb_ctrl(priv, 0);
usbhsg_unlock(lock, &flags);
if (gpriv->driver &&
gpriv->driver->disconnect)
gpriv->driver->disconnect(&gpriv->gadget);
dev_dbg(dev, "stop gadget\n");
return 0;
usbhsg_try_stop_unlock:
usbhsg_unlock(lock, &flags);
return 0;
}
int usb_gadget_probe_driver(struct usb_gadget_driver *driver,
int (*bind)(struct usb_gadget *))
{
struct usbhsg_gpriv *gpriv = the_controller;
struct usbhs_priv *priv;
struct device *dev;
int ret;
if (!bind ||
!driver ||
!driver->setup ||
driver->speed != USB_SPEED_HIGH)
return -EINVAL;
if (!gpriv)
return -ENODEV;
if (gpriv->driver)
return -EBUSY;
dev = usbhsg_gpriv_to_dev(gpriv);
priv = usbhsg_gpriv_to_priv(gpriv);
gpriv->driver = driver;
gpriv->gadget.dev.driver = &driver->driver;
ret = device_add(&gpriv->gadget.dev);
if (ret) {
dev_err(dev, "device_add error %d\n", ret);
goto add_fail;
}
ret = bind(&gpriv->gadget);
if (ret) {
dev_err(dev, "bind to driver %s error %d\n",
driver->driver.name, ret);
goto bind_fail;
}
dev_dbg(dev, "bind %s\n", driver->driver.name);
return usbhsg_try_start(priv, USBHSG_STATUS_REGISTERD);
bind_fail:
device_del(&gpriv->gadget.dev);
add_fail:
gpriv->driver = NULL;
gpriv->gadget.dev.driver = NULL;
return ret;
}
int usb_gadget_unregister_driver(struct usb_gadget_driver *driver)
{
struct usbhsg_gpriv *gpriv = the_controller;
struct usbhs_priv *priv;
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
if (!gpriv)
return -ENODEV;
if (!driver ||
!driver->unbind ||
driver != gpriv->driver)
return -EINVAL;
dev = usbhsg_gpriv_to_dev(gpriv);
priv = usbhsg_gpriv_to_priv(gpriv);
usbhsg_try_stop(priv, USBHSG_STATUS_REGISTERD);
device_del(&gpriv->gadget.dev);
gpriv->driver = NULL;
if (driver->disconnect)
driver->disconnect(&gpriv->gadget);
driver->unbind(&gpriv->gadget);
dev_dbg(dev, "unbind %s\n", driver->driver.name);
return 0;
}
static int usbhsg_get_frame(struct usb_gadget *gadget)
{
struct usbhsg_gpriv *gpriv = usbhsg_gadget_to_gpriv(gadget);
struct usbhs_priv *priv = usbhsg_gpriv_to_priv(gpriv);
return usbhs_frame_get_num(priv);
}
static int usbhsg_start(struct usbhs_priv *priv)
{
return usbhsg_try_start(priv, USBHSG_STATUS_STARTED);
}
static int usbhsg_stop(struct usbhs_priv *priv)
{
return usbhsg_try_stop(priv, USBHSG_STATUS_STARTED);
}
int __devinit usbhs_mod_gadget_probe(struct usbhs_priv *priv)
{
struct usbhsg_gpriv *gpriv;
struct usbhsg_uep *uep;
struct device *dev = usbhs_priv_to_dev(priv);
int pipe_size = usbhs_get_dparam(priv, pipe_size);
int i;
gpriv = kzalloc(sizeof(struct usbhsg_gpriv), GFP_KERNEL);
if (!gpriv) {
dev_err(dev, "Could not allocate gadget priv\n");
return -ENOMEM;
}
uep = kzalloc(sizeof(struct usbhsg_uep) * pipe_size, GFP_KERNEL);
if (!uep) {
dev_err(dev, "Could not allocate ep\n");
goto usbhs_mod_gadget_probe_err_gpriv;
}
usbhs_mod_register(priv, &gpriv->mod, USBHS_GADGET);
gpriv->mod.name = "gadget";
gpriv->mod.start = usbhsg_start;
gpriv->mod.stop = usbhsg_stop;
gpriv->uep = uep;
gpriv->uep_size = pipe_size;
usbhsg_status_init(gpriv);
device_initialize(&gpriv->gadget.dev);
dev_set_name(&gpriv->gadget.dev, "gadget");
gpriv->gadget.dev.parent = dev;
gpriv->gadget.name = "renesas_usbhs_udc";
gpriv->gadget.ops = &usbhsg_gadget_ops;
gpriv->gadget.is_dualspeed = 1;
INIT_LIST_HEAD(&gpriv->gadget.ep_list);
usbhsg_for_each_uep_with_dcp(uep, gpriv, i) {
uep->gpriv = gpriv;
snprintf(uep->ep_name, EP_NAME_SIZE, "ep%d", i);
uep->ep.name = uep->ep_name;
uep->ep.ops = &usbhsg_ep_ops;
INIT_LIST_HEAD(&uep->ep.ep_list);
INIT_LIST_HEAD(&uep->list);
if (usbhsg_is_dcp(uep)) {
gpriv->gadget.ep0 = &uep->ep;
uep->ep.maxpacket = 64;
}
else {
uep->ep.maxpacket = 512;
list_add_tail(&uep->ep.ep_list, &gpriv->gadget.ep_list);
}
}
the_controller = gpriv;
dev_info(dev, "gadget probed\n");
return 0;
usbhs_mod_gadget_probe_err_gpriv:
kfree(gpriv);
return -ENOMEM;
}
void __devexit usbhs_mod_gadget_remove(struct usbhs_priv *priv)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
kfree(gpriv->uep);
kfree(gpriv);
}
