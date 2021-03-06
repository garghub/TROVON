static const char *dwc3_ep0_state_string(enum dwc3_ep0_state state)
{
switch (state) {
case EP0_UNCONNECTED:
return "Unconnected";
case EP0_SETUP_PHASE:
return "Setup Phase";
case EP0_DATA_PHASE:
return "Data Phase";
case EP0_STATUS_PHASE:
return "Status Phase";
default:
return "UNKNOWN";
}
}
static int dwc3_ep0_start_trans(struct dwc3 *dwc, u8 epnum, dma_addr_t buf_dma,
u32 len, u32 type)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3_trb *trb;
struct dwc3_ep *dep;
int ret;
dep = dwc->eps[epnum];
if (dep->flags & DWC3_EP_BUSY) {
dev_vdbg(dwc->dev, "%s: still busy\n", dep->name);
return 0;
}
trb = dwc->ep0_trb;
trb->bpl = lower_32_bits(buf_dma);
trb->bph = upper_32_bits(buf_dma);
trb->size = len;
trb->ctrl = type;
trb->ctrl |= (DWC3_TRB_CTRL_HWO
| DWC3_TRB_CTRL_LST
| DWC3_TRB_CTRL_IOC
| DWC3_TRB_CTRL_ISP_IMI);
memset(&params, 0, sizeof(params));
params.param0 = upper_32_bits(dwc->ep0_trb_addr);
params.param1 = lower_32_bits(dwc->ep0_trb_addr);
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_STARTTRANSFER, &params);
if (ret < 0) {
dev_dbg(dwc->dev, "failed to send STARTTRANSFER command\n");
return ret;
}
dep->flags |= DWC3_EP_BUSY;
dep->resource_index = dwc3_gadget_ep_get_transfer_index(dwc,
dep->number);
dwc->ep0_next_event = DWC3_EP0_COMPLETE;
return 0;
}
static int __dwc3_gadget_ep0_queue(struct dwc3_ep *dep,
struct dwc3_request *req)
{
struct dwc3 *dwc = dep->dwc;
int ret = 0;
req->request.actual = 0;
req->request.status = -EINPROGRESS;
req->epnum = dep->number;
list_add_tail(&req->list, &dep->request_list);
if (dep->flags & DWC3_EP_PENDING_REQUEST) {
unsigned direction;
direction = !!(dep->flags & DWC3_EP0_DIR_IN);
if (dwc->ep0state != EP0_DATA_PHASE) {
dev_WARN(dwc->dev, "Unexpected pending request\n");
return 0;
}
__dwc3_ep0_do_control_data(dwc, dwc->eps[direction], req);
dep->flags &= ~(DWC3_EP_PENDING_REQUEST |
DWC3_EP0_DIR_IN);
} else if (dwc->delayed_status) {
dwc->delayed_status = false;
if (dwc->ep0state == EP0_STATUS_PHASE)
__dwc3_ep0_do_control_status(dwc, dwc->eps[1]);
else
dev_dbg(dwc->dev, "too early for delayed status\n");
}
return ret;
}
int dwc3_gadget_ep0_queue(struct usb_ep *ep, struct usb_request *request,
gfp_t gfp_flags)
{
struct dwc3_request *req = to_dwc3_request(request);
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret;
spin_lock_irqsave(&dwc->lock, flags);
if (!dep->endpoint.desc) {
dev_dbg(dwc->dev, "trying to queue request %p to disabled %s\n",
request, dep->name);
ret = -ESHUTDOWN;
goto out;
}
if (!list_empty(&dep->request_list)) {
ret = -EBUSY;
goto out;
}
dev_vdbg(dwc->dev, "queueing request %p to %s length %d, state '%s'\n",
request, dep->name, request->length,
dwc3_ep0_state_string(dwc->ep0state));
ret = __dwc3_gadget_ep0_queue(dep, req);
out:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static void dwc3_ep0_stall_and_restart(struct dwc3 *dwc)
{
struct dwc3_ep *dep = dwc->eps[0];
__dwc3_gadget_ep_set_halt(dep, 1);
dep->flags = DWC3_EP_ENABLED;
dwc->delayed_status = false;
if (!list_empty(&dep->request_list)) {
struct dwc3_request *req;
req = next_request(&dep->request_list);
dwc3_gadget_giveback(dep, req, -ECONNRESET);
}
dwc->ep0state = EP0_SETUP_PHASE;
dwc3_ep0_out_start(dwc);
}
int dwc3_gadget_ep0_set_halt(struct usb_ep *ep, int value)
{
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
dwc3_ep0_stall_and_restart(dwc);
return 0;
}
void dwc3_ep0_out_start(struct dwc3 *dwc)
{
int ret;
ret = dwc3_ep0_start_trans(dwc, 0, dwc->ctrl_req_addr, 8,
DWC3_TRBCTL_CONTROL_SETUP);
WARN_ON(ret < 0);
}
static struct dwc3_ep *dwc3_wIndex_to_dep(struct dwc3 *dwc, __le16 wIndex_le)
{
struct dwc3_ep *dep;
u32 windex = le16_to_cpu(wIndex_le);
u32 epnum;
epnum = (windex & USB_ENDPOINT_NUMBER_MASK) << 1;
if ((windex & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
epnum |= 1;
dep = dwc->eps[epnum];
if (dep->flags & DWC3_EP_ENABLED)
return dep;
return NULL;
}
static void dwc3_ep0_status_cmpl(struct usb_ep *ep, struct usb_request *req)
{
}
static int dwc3_ep0_handle_status(struct dwc3 *dwc,
struct usb_ctrlrequest *ctrl)
{
struct dwc3_ep *dep;
u32 recip;
u32 reg;
u16 usb_status = 0;
__le16 *response_pkt;
recip = ctrl->bRequestType & USB_RECIP_MASK;
switch (recip) {
case USB_RECIP_DEVICE:
usb_status |= dwc->is_selfpowered << USB_DEVICE_SELF_POWERED;
if (dwc->speed == DWC3_DSTS_SUPERSPEED) {
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (reg & DWC3_DCTL_INITU1ENA)
usb_status |= 1 << USB_DEV_STAT_U1_ENABLED;
if (reg & DWC3_DCTL_INITU2ENA)
usb_status |= 1 << USB_DEV_STAT_U2_ENABLED;
}
break;
case USB_RECIP_INTERFACE:
break;
case USB_RECIP_ENDPOINT:
dep = dwc3_wIndex_to_dep(dwc, ctrl->wIndex);
if (!dep)
return -EINVAL;
if (dep->flags & DWC3_EP_STALL)
usb_status = 1 << USB_ENDPOINT_HALT;
break;
default:
return -EINVAL;
};
response_pkt = (__le16 *) dwc->setup_buf;
*response_pkt = cpu_to_le16(usb_status);
dep = dwc->eps[0];
dwc->ep0_usb_req.dep = dep;
dwc->ep0_usb_req.request.length = sizeof(*response_pkt);
dwc->ep0_usb_req.request.buf = dwc->setup_buf;
dwc->ep0_usb_req.request.complete = dwc3_ep0_status_cmpl;
return __dwc3_gadget_ep0_queue(dep, &dwc->ep0_usb_req);
}
static int dwc3_ep0_handle_feature(struct dwc3 *dwc,
struct usb_ctrlrequest *ctrl, int set)
{
struct dwc3_ep *dep;
u32 recip;
u32 wValue;
u32 wIndex;
u32 reg;
int ret;
wValue = le16_to_cpu(ctrl->wValue);
wIndex = le16_to_cpu(ctrl->wIndex);
recip = ctrl->bRequestType & USB_RECIP_MASK;
switch (recip) {
case USB_RECIP_DEVICE:
switch (wValue) {
case USB_DEVICE_REMOTE_WAKEUP:
break;
case USB_DEVICE_U1_ENABLE:
if (dwc->dev_state != DWC3_CONFIGURED_STATE)
return -EINVAL;
if (dwc->speed != DWC3_DSTS_SUPERSPEED)
return -EINVAL;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (set)
reg |= DWC3_DCTL_INITU1ENA;
else
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
break;
case USB_DEVICE_U2_ENABLE:
if (dwc->dev_state != DWC3_CONFIGURED_STATE)
return -EINVAL;
if (dwc->speed != DWC3_DSTS_SUPERSPEED)
return -EINVAL;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (set)
reg |= DWC3_DCTL_INITU2ENA;
else
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
break;
case USB_DEVICE_LTM_ENABLE:
return -EINVAL;
break;
case USB_DEVICE_TEST_MODE:
if ((wIndex & 0xff) != 0)
return -EINVAL;
if (!set)
return -EINVAL;
dwc->test_mode_nr = wIndex >> 8;
dwc->test_mode = true;
break;
default:
return -EINVAL;
}
break;
case USB_RECIP_INTERFACE:
switch (wValue) {
case USB_INTRF_FUNC_SUSPEND:
if (wIndex & USB_INTRF_FUNC_SUSPEND_LP)
;
if (wIndex & USB_INTRF_FUNC_SUSPEND_RW)
;
break;
default:
return -EINVAL;
}
break;
case USB_RECIP_ENDPOINT:
switch (wValue) {
case USB_ENDPOINT_HALT:
dep = dwc3_wIndex_to_dep(dwc, wIndex);
if (!dep)
return -EINVAL;
ret = __dwc3_gadget_ep_set_halt(dep, set);
if (ret)
return -EINVAL;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
};
return 0;
}
static int dwc3_ep0_set_address(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
u32 addr;
u32 reg;
addr = le16_to_cpu(ctrl->wValue);
if (addr > 127) {
dev_dbg(dwc->dev, "invalid device address %d\n", addr);
return -EINVAL;
}
if (dwc->dev_state == DWC3_CONFIGURED_STATE) {
dev_dbg(dwc->dev, "trying to set address when configured\n");
return -EINVAL;
}
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~(DWC3_DCFG_DEVADDR_MASK);
reg |= DWC3_DCFG_DEVADDR(addr);
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
if (addr)
dwc->dev_state = DWC3_ADDRESS_STATE;
else
dwc->dev_state = DWC3_DEFAULT_STATE;
return 0;
}
static int dwc3_ep0_delegate_req(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
int ret;
spin_unlock(&dwc->lock);
ret = dwc->gadget_driver->setup(&dwc->gadget, ctrl);
spin_lock(&dwc->lock);
return ret;
}
static int dwc3_ep0_set_config(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
u32 cfg;
int ret;
u32 reg;
dwc->start_config_issued = false;
cfg = le16_to_cpu(ctrl->wValue);
switch (dwc->dev_state) {
case DWC3_DEFAULT_STATE:
return -EINVAL;
break;
case DWC3_ADDRESS_STATE:
ret = dwc3_ep0_delegate_req(dwc, ctrl);
if (cfg && (!ret || (ret == USB_GADGET_DELAYED_STATUS))) {
dwc->dev_state = DWC3_CONFIGURED_STATE;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg |= (DWC3_DCTL_ACCEPTU1ENA | DWC3_DCTL_ACCEPTU2ENA);
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc->resize_fifos = true;
dev_dbg(dwc->dev, "resize fifos flag SET\n");
}
break;
case DWC3_CONFIGURED_STATE:
ret = dwc3_ep0_delegate_req(dwc, ctrl);
if (!cfg)
dwc->dev_state = DWC3_ADDRESS_STATE;
break;
default:
ret = -EINVAL;
}
return ret;
}
static void dwc3_ep0_set_sel_cmpl(struct usb_ep *ep, struct usb_request *req)
{
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
u32 param = 0;
u32 reg;
struct timing {
u8 u1sel;
u8 u1pel;
u16 u2sel;
u16 u2pel;
} __packed timing;
int ret;
memcpy(&timing, req->buf, sizeof(timing));
dwc->u1sel = timing.u1sel;
dwc->u1pel = timing.u1pel;
dwc->u2sel = le16_to_cpu(timing.u2sel);
dwc->u2pel = le16_to_cpu(timing.u2pel);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (reg & DWC3_DCTL_INITU2ENA)
param = dwc->u2pel;
if (reg & DWC3_DCTL_INITU1ENA)
param = dwc->u1pel;
if (param > 125)
param = 0;
ret = dwc3_send_gadget_generic_command(dwc,
DWC3_DGCMD_SET_PERIODIC_PAR, param);
WARN_ON(ret < 0);
}
static int dwc3_ep0_set_sel(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
struct dwc3_ep *dep;
u16 wLength;
u16 wValue;
if (dwc->dev_state == DWC3_DEFAULT_STATE)
return -EINVAL;
wValue = le16_to_cpu(ctrl->wValue);
wLength = le16_to_cpu(ctrl->wLength);
if (wLength != 6) {
dev_err(dwc->dev, "Set SEL should be 6 bytes, got %d\n",
wLength);
return -EINVAL;
}
dep = dwc->eps[0];
dwc->ep0_usb_req.dep = dep;
dwc->ep0_usb_req.request.length = dep->endpoint.maxpacket;
dwc->ep0_usb_req.request.buf = dwc->setup_buf;
dwc->ep0_usb_req.request.complete = dwc3_ep0_set_sel_cmpl;
return __dwc3_gadget_ep0_queue(dep, &dwc->ep0_usb_req);
}
static int dwc3_ep0_set_isoch_delay(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
u16 wLength;
u16 wValue;
u16 wIndex;
wValue = le16_to_cpu(ctrl->wValue);
wLength = le16_to_cpu(ctrl->wLength);
wIndex = le16_to_cpu(ctrl->wIndex);
if (wIndex || wLength)
return -EINVAL;
dwc->isoch_delay = wValue;
return 0;
}
static int dwc3_ep0_std_request(struct dwc3 *dwc, struct usb_ctrlrequest *ctrl)
{
int ret;
switch (ctrl->bRequest) {
case USB_REQ_GET_STATUS:
dev_vdbg(dwc->dev, "USB_REQ_GET_STATUS\n");
ret = dwc3_ep0_handle_status(dwc, ctrl);
break;
case USB_REQ_CLEAR_FEATURE:
dev_vdbg(dwc->dev, "USB_REQ_CLEAR_FEATURE\n");
ret = dwc3_ep0_handle_feature(dwc, ctrl, 0);
break;
case USB_REQ_SET_FEATURE:
dev_vdbg(dwc->dev, "USB_REQ_SET_FEATURE\n");
ret = dwc3_ep0_handle_feature(dwc, ctrl, 1);
break;
case USB_REQ_SET_ADDRESS:
dev_vdbg(dwc->dev, "USB_REQ_SET_ADDRESS\n");
ret = dwc3_ep0_set_address(dwc, ctrl);
break;
case USB_REQ_SET_CONFIGURATION:
dev_vdbg(dwc->dev, "USB_REQ_SET_CONFIGURATION\n");
ret = dwc3_ep0_set_config(dwc, ctrl);
break;
case USB_REQ_SET_SEL:
dev_vdbg(dwc->dev, "USB_REQ_SET_SEL\n");
ret = dwc3_ep0_set_sel(dwc, ctrl);
break;
case USB_REQ_SET_ISOCH_DELAY:
dev_vdbg(dwc->dev, "USB_REQ_SET_ISOCH_DELAY\n");
ret = dwc3_ep0_set_isoch_delay(dwc, ctrl);
break;
default:
dev_vdbg(dwc->dev, "Forwarding to gadget driver\n");
ret = dwc3_ep0_delegate_req(dwc, ctrl);
break;
};
return ret;
}
static void dwc3_ep0_inspect_setup(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct usb_ctrlrequest *ctrl = dwc->ctrl_req;
int ret = -EINVAL;
u32 len;
if (!dwc->gadget_driver)
goto out;
len = le16_to_cpu(ctrl->wLength);
if (!len) {
dwc->three_stage_setup = false;
dwc->ep0_expect_in = false;
dwc->ep0_next_event = DWC3_EP0_NRDY_STATUS;
} else {
dwc->three_stage_setup = true;
dwc->ep0_expect_in = !!(ctrl->bRequestType & USB_DIR_IN);
dwc->ep0_next_event = DWC3_EP0_NRDY_DATA;
}
if ((ctrl->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD)
ret = dwc3_ep0_std_request(dwc, ctrl);
else
ret = dwc3_ep0_delegate_req(dwc, ctrl);
if (ret == USB_GADGET_DELAYED_STATUS)
dwc->delayed_status = true;
out:
if (ret < 0)
dwc3_ep0_stall_and_restart(dwc);
}
static void dwc3_ep0_complete_data(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_request *r = NULL;
struct usb_request *ur;
struct dwc3_trb *trb;
struct dwc3_ep *ep0;
u32 transferred;
u32 length;
u8 epnum;
epnum = event->endpoint_number;
ep0 = dwc->eps[0];
dwc->ep0_next_event = DWC3_EP0_NRDY_STATUS;
r = next_request(&ep0->request_list);
ur = &r->request;
trb = dwc->ep0_trb;
length = trb->size & DWC3_TRB_SIZE_MASK;
if (dwc->ep0_bounced) {
unsigned transfer_size = ur->length;
unsigned maxp = ep0->endpoint.maxpacket;
transfer_size += (maxp - (transfer_size % maxp));
transferred = min_t(u32, ur->length,
transfer_size - length);
memcpy(ur->buf, dwc->ep0_bounce, transferred);
} else {
transferred = ur->length - length;
}
ur->actual += transferred;
if ((epnum & 1) && ur->actual < ur->length) {
dwc3_ep0_stall_and_restart(dwc);
} else {
if (r)
dwc3_gadget_giveback(ep0, r, 0);
}
}
static void dwc3_ep0_complete_status(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_request *r;
struct dwc3_ep *dep;
dep = dwc->eps[0];
if (!list_empty(&dep->request_list)) {
r = next_request(&dep->request_list);
dwc3_gadget_giveback(dep, r, 0);
}
if (dwc->test_mode) {
int ret;
ret = dwc3_gadget_set_test_mode(dwc, dwc->test_mode_nr);
if (ret < 0) {
dev_dbg(dwc->dev, "Invalid Test #%d\n",
dwc->test_mode_nr);
dwc3_ep0_stall_and_restart(dwc);
return;
}
}
dwc->ep0state = EP0_SETUP_PHASE;
dwc3_ep0_out_start(dwc);
}
static void dwc3_ep0_xfer_complete(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep = dwc->eps[event->endpoint_number];
dep->flags &= ~DWC3_EP_BUSY;
dep->resource_index = 0;
dwc->setup_packet_pending = false;
switch (dwc->ep0state) {
case EP0_SETUP_PHASE:
dev_vdbg(dwc->dev, "Inspecting Setup Bytes\n");
dwc3_ep0_inspect_setup(dwc, event);
break;
case EP0_DATA_PHASE:
dev_vdbg(dwc->dev, "Data Phase\n");
dwc3_ep0_complete_data(dwc, event);
break;
case EP0_STATUS_PHASE:
dev_vdbg(dwc->dev, "Status Phase\n");
dwc3_ep0_complete_status(dwc, event);
break;
default:
WARN(true, "UNKNOWN ep0state %d\n", dwc->ep0state);
}
}
static void dwc3_ep0_do_control_setup(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
dwc3_ep0_out_start(dwc);
}
static void __dwc3_ep0_do_control_data(struct dwc3 *dwc,
struct dwc3_ep *dep, struct dwc3_request *req)
{
int ret;
req->direction = !!dep->number;
if (req->request.length == 0) {
ret = dwc3_ep0_start_trans(dwc, dep->number,
dwc->ctrl_req_addr, 0,
DWC3_TRBCTL_CONTROL_DATA);
} else if (!IS_ALIGNED(req->request.length, dep->endpoint.maxpacket)
&& (dep->number == 0)) {
u32 transfer_size;
ret = usb_gadget_map_request(&dwc->gadget, &req->request,
dep->number);
if (ret) {
dev_dbg(dwc->dev, "failed to map request\n");
return;
}
WARN_ON(req->request.length > DWC3_EP0_BOUNCE_SIZE);
transfer_size = roundup(req->request.length,
(u32) dep->endpoint.maxpacket);
dwc->ep0_bounced = true;
ret = dwc3_ep0_start_trans(dwc, dep->number,
dwc->ep0_bounce_addr, transfer_size,
DWC3_TRBCTL_CONTROL_DATA);
} else {
ret = usb_gadget_map_request(&dwc->gadget, &req->request,
dep->number);
if (ret) {
dev_dbg(dwc->dev, "failed to map request\n");
return;
}
ret = dwc3_ep0_start_trans(dwc, dep->number, req->request.dma,
req->request.length, DWC3_TRBCTL_CONTROL_DATA);
}
WARN_ON(ret < 0);
}
static void dwc3_ep0_do_control_data(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep;
struct dwc3_request *req;
dep = dwc->eps[0];
if (list_empty(&dep->request_list)) {
dev_vdbg(dwc->dev, "pending request for EP0 Data phase\n");
dep->flags |= DWC3_EP_PENDING_REQUEST;
if (event->endpoint_number)
dep->flags |= DWC3_EP0_DIR_IN;
return;
}
req = next_request(&dep->request_list);
dep = dwc->eps[event->endpoint_number];
__dwc3_ep0_do_control_data(dwc, dep, req);
}
static int dwc3_ep0_start_control_status(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
u32 type;
type = dwc->three_stage_setup ? DWC3_TRBCTL_CONTROL_STATUS3
: DWC3_TRBCTL_CONTROL_STATUS2;
return dwc3_ep0_start_trans(dwc, dep->number,
dwc->ctrl_req_addr, 0, type);
}
static void __dwc3_ep0_do_control_status(struct dwc3 *dwc, struct dwc3_ep *dep)
{
if (dwc->resize_fifos) {
dev_dbg(dwc->dev, "starting to resize fifos\n");
dwc3_gadget_resize_tx_fifos(dwc);
dwc->resize_fifos = 0;
}
WARN_ON(dwc3_ep0_start_control_status(dep));
}
static void dwc3_ep0_do_control_status(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep = dwc->eps[event->endpoint_number];
__dwc3_ep0_do_control_status(dwc, dep);
}
static void dwc3_ep0_xfernotready(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
dwc->setup_packet_pending = true;
if (dwc->ep0_next_event == DWC3_EP0_COMPLETE) {
switch (event->status) {
case DEPEVT_STATUS_CONTROL_SETUP:
dev_vdbg(dwc->dev, "Unexpected XferNotReady(Setup)\n");
dwc3_ep0_stall_and_restart(dwc);
break;
case DEPEVT_STATUS_CONTROL_DATA:
case DEPEVT_STATUS_CONTROL_STATUS:
default:
dev_vdbg(dwc->dev, "waiting for XferComplete\n");
}
return;
}
switch (event->status) {
case DEPEVT_STATUS_CONTROL_SETUP:
dev_vdbg(dwc->dev, "Control Setup\n");
dwc->ep0state = EP0_SETUP_PHASE;
dwc3_ep0_do_control_setup(dwc, event);
break;
case DEPEVT_STATUS_CONTROL_DATA:
dev_vdbg(dwc->dev, "Control Data\n");
dwc->ep0state = EP0_DATA_PHASE;
if (dwc->ep0_next_event != DWC3_EP0_NRDY_DATA) {
dev_vdbg(dwc->dev, "Expected %d got %d\n",
dwc->ep0_next_event,
DWC3_EP0_NRDY_DATA);
dwc3_ep0_stall_and_restart(dwc);
return;
}
if (dwc->ep0_expect_in != event->endpoint_number) {
dev_vdbg(dwc->dev, "Wrong direction for Data phase\n");
dwc3_ep0_stall_and_restart(dwc);
return;
}
dwc3_ep0_do_control_data(dwc, event);
break;
case DEPEVT_STATUS_CONTROL_STATUS:
dev_vdbg(dwc->dev, "Control Status\n");
dwc->ep0state = EP0_STATUS_PHASE;
if (dwc->ep0_next_event != DWC3_EP0_NRDY_STATUS) {
dev_vdbg(dwc->dev, "Expected %d got %d\n",
dwc->ep0_next_event,
DWC3_EP0_NRDY_STATUS);
dwc3_ep0_stall_and_restart(dwc);
return;
}
if (dwc->delayed_status) {
WARN_ON_ONCE(event->endpoint_number != 1);
dev_vdbg(dwc->dev, "Mass Storage delayed status\n");
return;
}
dwc3_ep0_do_control_status(dwc, event);
}
}
void dwc3_ep0_interrupt(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
u8 epnum = event->endpoint_number;
dev_dbg(dwc->dev, "%s while ep%d%s in state '%s'\n",
dwc3_ep_event_string(event->endpoint_event),
epnum >> 1, (epnum & 1) ? "in" : "out",
dwc3_ep0_state_string(dwc->ep0state));
switch (event->endpoint_event) {
case DWC3_DEPEVT_XFERCOMPLETE:
dwc3_ep0_xfer_complete(dwc, event);
break;
case DWC3_DEPEVT_XFERNOTREADY:
dwc3_ep0_xfernotready(dwc, event);
break;
case DWC3_DEPEVT_XFERINPROGRESS:
case DWC3_DEPEVT_RXTXFIFOEVT:
case DWC3_DEPEVT_STREAMEVT:
case DWC3_DEPEVT_EPCMDCMPLT:
break;
}
}
