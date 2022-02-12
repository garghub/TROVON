static void usbhsg_queue_push(struct usbhsg_uep *uep,
struct usbhsg_request *ureq)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usbhs_pkt *pkt = usbhsg_ureq_to_pkt(ureq);
struct usb_request *req = &ureq->req;
req->actual = 0;
req->status = -EINPROGRESS;
usbhs_pkt_push(pipe, pkt, uep->handler,
req->buf, req->length, req->zero);
dev_dbg(dev, "pipe %d : queue push (%d)\n",
usbhs_pipe_number(pipe),
req->length);
}
static void usbhsg_queue_pop(struct usbhsg_uep *uep,
struct usbhsg_request *ureq,
int status)
{
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
dev_dbg(dev, "pipe %d : queue pop\n", usbhs_pipe_number(pipe));
ureq->req.status = status;
ureq->req.complete(&uep->ep, &ureq->req);
}
static void usbhsg_queue_done(struct usbhs_pkt *pkt)
{
struct usbhs_pipe *pipe = pkt->pipe;
struct usbhsg_uep *uep = usbhsg_pipe_to_uep(pipe);
struct usbhsg_request *ureq = usbhsg_pkt_to_ureq(pkt);
ureq->req.actual = pkt->actual;
usbhsg_queue_pop(uep, ureq, 0);
}
static int usbhsg_dma_map(struct device *dev,
struct usbhs_pkt *pkt,
enum dma_data_direction dir)
{
struct usbhsg_request *ureq = usbhsg_pkt_to_ureq(pkt);
struct usb_request *req = &ureq->req;
if (pkt->dma != DMA_ADDR_INVALID) {
dev_err(dev, "dma is already mapped\n");
return -EIO;
}
if (req->dma == DMA_ADDR_INVALID) {
pkt->dma = dma_map_single(dev, pkt->buf, pkt->length, dir);
} else {
dma_sync_single_for_device(dev, req->dma, req->length, dir);
pkt->dma = req->dma;
}
if (dma_mapping_error(dev, pkt->dma)) {
dev_err(dev, "dma mapping error %x\n", pkt->dma);
return -EIO;
}
return 0;
}
static int usbhsg_dma_unmap(struct device *dev,
struct usbhs_pkt *pkt,
enum dma_data_direction dir)
{
struct usbhsg_request *ureq = usbhsg_pkt_to_ureq(pkt);
struct usb_request *req = &ureq->req;
if (pkt->dma == DMA_ADDR_INVALID) {
dev_err(dev, "dma is not mapped\n");
return -EIO;
}
if (req->dma == DMA_ADDR_INVALID)
dma_unmap_single(dev, pkt->dma, pkt->length, dir);
else
dma_sync_single_for_cpu(dev, req->dma, req->length, dir);
pkt->dma = DMA_ADDR_INVALID;
return 0;
}
static int usbhsg_dma_map_ctrl(struct usbhs_pkt *pkt, int map)
{
struct usbhs_pipe *pipe = pkt->pipe;
struct usbhsg_uep *uep = usbhsg_pipe_to_uep(pipe);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
enum dma_data_direction dir;
dir = usbhs_pipe_is_dir_in(pipe) ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
if (map)
return usbhsg_dma_map(dev, pkt, dir);
else
return usbhsg_dma_unmap(dev, pkt, dir);
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
usbhs_pipe_disable(pipe);
usbhs_pipe_clear_sequence(pipe);
usbhs_pipe_enable(pipe);
}
usbhsg_recip_handler_std_control_done(priv, uep, ctrl);
return 0;
}
static int usbhsg_recip_run_handle(struct usbhs_priv *priv,
struct usbhsg_recip_handle *handler,
struct usb_ctrlrequest *ctrl)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
struct usbhsg_uep *uep;
struct usbhs_pipe *pipe;
int recip = ctrl->bRequestType & USB_RECIP_MASK;
int nth = le16_to_cpu(ctrl->wIndex) & USB_ENDPOINT_NUMBER_MASK;
int ret;
int (*func)(struct usbhs_priv *priv, struct usbhsg_uep *uep,
struct usb_ctrlrequest *ctrl);
char *msg;
uep = usbhsg_gpriv_to_nth_uep(gpriv, nth);
pipe = usbhsg_uep_to_pipe(uep);
if (!pipe) {
dev_err(dev, "wrong recip request\n");
ret = -EINVAL;
goto usbhsg_recip_run_handle_end;
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
unsigned long flags;
dev_dbg(dev, "%s (pipe %d :%s)\n", handler->name, nth, msg);
usbhs_lock(priv, flags);
ret = func(priv, uep, ctrl);
usbhs_unlock(priv, flags);
}
usbhsg_recip_run_handle_end:
usbhs_pkt_start(pipe);
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
dcp->handler = &usbhs_fifo_pio_push_handler;
break;
case WRITE_DATA_STAGE:
dcp->handler = &usbhs_fifo_pio_pop_handler;
break;
case NODATA_STATUS_STAGE:
dcp->handler = &usbhs_ctrl_stage_end_handler;
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
usbhs_pipe_stall(pipe);
return ret;
}
static int usbhsg_pipe_disable(struct usbhsg_uep *uep)
{
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usbhs_pkt *pkt;
usbhs_pipe_disable(pipe);
while (1) {
pkt = usbhs_pkt_pop(pipe, NULL);
if (!pkt)
break;
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
int ret = -EIO;
if (uep->pipe) {
usbhs_pipe_clear(uep->pipe);
usbhs_pipe_clear_sequence(uep->pipe);
return 0;
}
pipe = usbhs_pipe_malloc(priv, desc);
if (pipe) {
uep->pipe = pipe;
pipe->mod_private = uep;
if (usb_endpoint_dir_in(desc))
uep->handler = &usbhs_fifo_dma_push_handler;
else
uep->handler = &usbhs_fifo_dma_pop_handler;
ret = 0;
}
return ret;
}
static int usbhsg_ep_disable(struct usb_ep *ep)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
return usbhsg_pipe_disable(uep);
}
static struct usb_request *usbhsg_ep_alloc_request(struct usb_ep *ep,
gfp_t gfp_flags)
{
struct usbhsg_request *ureq;
ureq = kzalloc(sizeof *ureq, gfp_flags);
if (!ureq)
return NULL;
usbhs_pkt_init(usbhsg_ureq_to_pkt(ureq));
ureq->req.dma = DMA_ADDR_INVALID;
return &ureq->req;
}
static void usbhsg_ep_free_request(struct usb_ep *ep,
struct usb_request *req)
{
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
WARN_ON(!list_empty(&ureq->pkt.node));
kfree(ureq);
}
static int usbhsg_ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t gfp_flags)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
if (usbhsg_is_not_connected(gpriv) ||
unlikely(!gpriv->driver) ||
unlikely(!pipe))
return -ESHUTDOWN;
usbhsg_queue_push(uep, ureq);
return 0;
}
static int usbhsg_ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhsg_request *ureq = usbhsg_req_to_ureq(req);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
usbhs_pkt_pop(pipe, usbhsg_ureq_to_pkt(ureq));
usbhsg_queue_pop(uep, ureq, -ECONNRESET);
return 0;
}
static int __usbhsg_ep_set_halt_wedge(struct usb_ep *ep, int halt, int wedge)
{
struct usbhsg_uep *uep = usbhsg_ep_to_uep(ep);
struct usbhs_pipe *pipe = usbhsg_uep_to_pipe(uep);
struct usbhsg_gpriv *gpriv = usbhsg_uep_to_gpriv(uep);
struct usbhs_priv *priv = usbhsg_gpriv_to_priv(gpriv);
struct device *dev = usbhsg_gpriv_to_dev(gpriv);
unsigned long flags;
usbhsg_pipe_disable(uep);
dev_dbg(dev, "set halt %d (pipe %d)\n",
halt, usbhs_pipe_number(pipe));
usbhs_lock(priv, flags);
if (halt)
usbhs_pipe_stall(pipe);
else
usbhs_pipe_disable(pipe);
if (halt && wedge)
usbhsg_status_set(gpriv, USBHSG_STATUS_WEDGE);
else
usbhsg_status_clr(gpriv, USBHSG_STATUS_WEDGE);
usbhs_unlock(priv, flags);
return 0;
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
unsigned long flags;
int ret = 0;
usbhs_lock(priv, flags);
usbhsg_status_set(gpriv, status);
if (!(usbhsg_status_has(gpriv, USBHSG_STATUS_STARTED) &&
usbhsg_status_has(gpriv, USBHSG_STATUS_REGISTERD)))
ret = -1;
usbhs_unlock(priv, flags);
if (ret < 0)
return 0;
dev_dbg(dev, "start gadget\n");
usbhs_pipe_init(priv,
usbhsg_queue_done,
usbhsg_dma_map_ctrl);
usbhs_fifo_init(priv);
usbhsg_uep_init(gpriv);
dcp->pipe = usbhs_dcp_malloc(priv);
dcp->pipe->mod_private = dcp;
usbhs_sys_hispeed_ctrl(priv, 1);
usbhs_sys_function_ctrl(priv, 1);
usbhs_sys_usb_ctrl(priv, 1);
mod->irq_dev_state = usbhsg_irq_dev_state;
mod->irq_ctrl_stage = usbhsg_irq_ctrl_stage;
usbhs_irq_callback_update(priv, mod);
return 0;
}
static int usbhsg_try_stop(struct usbhs_priv *priv, u32 status)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
struct usbhs_mod *mod = usbhs_mod_get_current(priv);
struct usbhsg_uep *dcp = usbhsg_gpriv_to_dcp(gpriv);
struct device *dev = usbhs_priv_to_dev(priv);
unsigned long flags;
int ret = 0;
usbhs_lock(priv, flags);
usbhsg_status_clr(gpriv, status);
if (!usbhsg_status_has(gpriv, USBHSG_STATUS_STARTED) &&
!usbhsg_status_has(gpriv, USBHSG_STATUS_REGISTERD))
ret = -1;
usbhs_unlock(priv, flags);
if (ret < 0)
return 0;
usbhs_fifo_quit(priv);
mod->irq_dev_state = NULL;
mod->irq_ctrl_stage = NULL;
usbhs_irq_callback_update(priv, mod);
gpriv->gadget.speed = USB_SPEED_UNKNOWN;
usbhs_sys_hispeed_ctrl(priv, 0);
usbhs_sys_function_ctrl(priv, 0);
usbhs_sys_usb_ctrl(priv, 0);
usbhsg_pipe_disable(dcp);
if (gpriv->driver &&
gpriv->driver->disconnect)
gpriv->driver->disconnect(&gpriv->gadget);
dev_dbg(dev, "stop gadget\n");
return 0;
}
static int usbhsg_gadget_start(struct usb_gadget_driver *driver,
int (*bind)(struct usb_gadget *))
{
struct usbhsg_gpriv *gpriv;
struct usbhs_priv *priv;
struct device *dev;
int ret;
if (!bind ||
!driver ||
!driver->setup ||
driver->speed != USB_SPEED_HIGH)
return -EINVAL;
usbhsg_for_each_controller(gpriv) {
if (!gpriv->driver)
goto find_unused_controller;
}
return -ENODEV;
find_unused_controller:
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
static int usbhsg_gadget_stop(struct usb_gadget_driver *driver)
{
struct usbhsg_gpriv *gpriv;
struct usbhs_priv *priv;
struct device *dev;
if (!driver ||
!driver->unbind)
return -EINVAL;
usbhsg_for_each_controller(gpriv) {
if (gpriv->driver == driver)
goto find_matching_controller;
}
return -ENODEV;
find_matching_controller:
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
int ret;
gpriv = kzalloc(sizeof(struct usbhsg_gpriv), GFP_KERNEL);
if (!gpriv) {
dev_err(dev, "Could not allocate gadget priv\n");
return -ENOMEM;
}
uep = kzalloc(sizeof(struct usbhsg_uep) * pipe_size, GFP_KERNEL);
if (!uep) {
dev_err(dev, "Could not allocate ep\n");
ret = -ENOMEM;
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
if (usbhsg_is_dcp(uep)) {
gpriv->gadget.ep0 = &uep->ep;
uep->ep.maxpacket = 64;
}
else {
uep->ep.maxpacket = 512;
list_add_tail(&uep->ep.ep_list, &gpriv->gadget.ep_list);
}
}
usbhsg_controller_register(gpriv);
ret = usb_add_gadget_udc(dev, &gpriv->gadget);
if (ret)
goto err_add_udc;
dev_info(dev, "gadget probed\n");
return 0;
err_add_udc:
kfree(gpriv->uep);
usbhs_mod_gadget_probe_err_gpriv:
kfree(gpriv);
return ret;
}
void __devexit usbhs_mod_gadget_remove(struct usbhs_priv *priv)
{
struct usbhsg_gpriv *gpriv = usbhsg_priv_to_gpriv(priv);
usb_del_gadget_udc(&gpriv->gadget);
usbhsg_controller_unregister(gpriv);
kfree(gpriv->uep);
kfree(gpriv);
}
