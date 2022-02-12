int dwc3_gadget_set_test_mode(struct dwc3 *dwc, int mode)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_TSTCTRL_MASK;
switch (mode) {
case TEST_J:
case TEST_K:
case TEST_SE0_NAK:
case TEST_PACKET:
case TEST_FORCE_EN:
reg |= mode << 1;
break;
default:
return -EINVAL;
}
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
return 0;
}
int dwc3_gadget_get_link_state(struct dwc3 *dwc)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
return DWC3_DSTS_USBLNKST(reg);
}
int dwc3_gadget_set_link_state(struct dwc3 *dwc, enum dwc3_link_state state)
{
int retries = 10000;
u32 reg;
if (dwc->revision >= DWC3_REVISION_194A) {
while (--retries) {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
if (reg & DWC3_DSTS_DCNRD)
udelay(5);
else
break;
}
if (retries <= 0)
return -ETIMEDOUT;
}
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_ULSTCHNGREQ_MASK;
reg |= DWC3_DCTL_ULSTCHNGREQ(state);
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
if (dwc->revision >= DWC3_REVISION_194A)
return 0;
retries = 10000;
while (--retries) {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
if (DWC3_DSTS_USBLNKST(reg) == state)
return 0;
udelay(5);
}
return -ETIMEDOUT;
}
static void dwc3_ep_inc_trb(u8 *index)
{
(*index)++;
if (*index == (DWC3_TRB_NUM - 1))
*index = 0;
}
static void dwc3_ep_inc_enq(struct dwc3_ep *dep)
{
dwc3_ep_inc_trb(&dep->trb_enqueue);
}
static void dwc3_ep_inc_deq(struct dwc3_ep *dep)
{
dwc3_ep_inc_trb(&dep->trb_dequeue);
}
void dwc3_gadget_giveback(struct dwc3_ep *dep, struct dwc3_request *req,
int status)
{
struct dwc3 *dwc = dep->dwc;
req->started = false;
list_del(&req->list);
req->remaining = 0;
if (req->request.status == -EINPROGRESS)
req->request.status = status;
if (req->trb)
usb_gadget_unmap_request_by_dev(dwc->sysdev,
&req->request, req->direction);
req->trb = NULL;
trace_dwc3_gadget_giveback(req);
spin_unlock(&dwc->lock);
usb_gadget_giveback_request(&dep->endpoint, &req->request);
spin_lock(&dwc->lock);
if (dep->number > 1)
pm_runtime_put(dwc->dev);
}
int dwc3_send_gadget_generic_command(struct dwc3 *dwc, unsigned cmd, u32 param)
{
u32 timeout = 500;
int status = 0;
int ret = 0;
u32 reg;
dwc3_writel(dwc->regs, DWC3_DGCMDPAR, param);
dwc3_writel(dwc->regs, DWC3_DGCMD, cmd | DWC3_DGCMD_CMDACT);
do {
reg = dwc3_readl(dwc->regs, DWC3_DGCMD);
if (!(reg & DWC3_DGCMD_CMDACT)) {
status = DWC3_DGCMD_STATUS(reg);
if (status)
ret = -EINVAL;
break;
}
} while (--timeout);
if (!timeout) {
ret = -ETIMEDOUT;
status = -ETIMEDOUT;
}
trace_dwc3_gadget_generic_cmd(cmd, param, status);
return ret;
}
int dwc3_send_gadget_ep_cmd(struct dwc3_ep *dep, unsigned cmd,
struct dwc3_gadget_ep_cmd_params *params)
{
const struct usb_endpoint_descriptor *desc = dep->endpoint.desc;
struct dwc3 *dwc = dep->dwc;
u32 timeout = 500;
u32 reg;
int cmd_status = 0;
int susphy = false;
int ret = -EINVAL;
if (dwc->gadget.speed <= USB_SPEED_HIGH) {
reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
if (unlikely(reg & DWC3_GUSB2PHYCFG_SUSPHY)) {
susphy = true;
reg &= ~DWC3_GUSB2PHYCFG_SUSPHY;
dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);
}
}
if (DWC3_DEPCMD_CMD(cmd) == DWC3_DEPCMD_STARTTRANSFER) {
int needs_wakeup;
needs_wakeup = (dwc->link_state == DWC3_LINK_STATE_U1 ||
dwc->link_state == DWC3_LINK_STATE_U2 ||
dwc->link_state == DWC3_LINK_STATE_U3);
if (unlikely(needs_wakeup)) {
ret = __dwc3_gadget_wakeup(dwc);
dev_WARN_ONCE(dwc->dev, ret, "wakeup failed --> %d\n",
ret);
}
}
dwc3_writel(dep->regs, DWC3_DEPCMDPAR0, params->param0);
dwc3_writel(dep->regs, DWC3_DEPCMDPAR1, params->param1);
dwc3_writel(dep->regs, DWC3_DEPCMDPAR2, params->param2);
if (DWC3_DEPCMD_CMD(cmd) == DWC3_DEPCMD_UPDATETRANSFER &&
!usb_endpoint_xfer_isoc(desc))
cmd &= ~(DWC3_DEPCMD_CMDIOC | DWC3_DEPCMD_CMDACT);
else
cmd |= DWC3_DEPCMD_CMDACT;
dwc3_writel(dep->regs, DWC3_DEPCMD, cmd);
do {
reg = dwc3_readl(dep->regs, DWC3_DEPCMD);
if (!(reg & DWC3_DEPCMD_CMDACT)) {
cmd_status = DWC3_DEPCMD_STATUS(reg);
switch (cmd_status) {
case 0:
ret = 0;
break;
case DEPEVT_TRANSFER_NO_RESOURCE:
ret = -EINVAL;
break;
case DEPEVT_TRANSFER_BUS_EXPIRY:
ret = -EAGAIN;
break;
default:
dev_WARN(dwc->dev, "UNKNOWN cmd status\n");
}
break;
}
} while (--timeout);
if (timeout == 0) {
ret = -ETIMEDOUT;
cmd_status = -ETIMEDOUT;
}
trace_dwc3_gadget_ep_cmd(dep, cmd, params, cmd_status);
if (ret == 0) {
switch (DWC3_DEPCMD_CMD(cmd)) {
case DWC3_DEPCMD_STARTTRANSFER:
dep->flags |= DWC3_EP_TRANSFER_STARTED;
break;
case DWC3_DEPCMD_ENDTRANSFER:
dep->flags &= ~DWC3_EP_TRANSFER_STARTED;
break;
default:
break;
}
}
if (unlikely(susphy)) {
reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
reg |= DWC3_GUSB2PHYCFG_SUSPHY;
dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);
}
return ret;
}
static int dwc3_send_clear_stall_ep_cmd(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
struct dwc3_gadget_ep_cmd_params params;
u32 cmd = DWC3_DEPCMD_CLEARSTALL;
if (dep->direction && (dwc->revision >= DWC3_REVISION_260A) &&
(dwc->gadget.speed >= USB_SPEED_SUPER))
cmd |= DWC3_DEPCMD_CLEARPENDIN;
memset(&params, 0, sizeof(params));
return dwc3_send_gadget_ep_cmd(dep, cmd, &params);
}
static dma_addr_t dwc3_trb_dma_offset(struct dwc3_ep *dep,
struct dwc3_trb *trb)
{
u32 offset = (char *) trb - (char *) dep->trb_pool;
return dep->trb_pool_dma + offset;
}
static int dwc3_alloc_trb_pool(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
if (dep->trb_pool)
return 0;
dep->trb_pool = dma_alloc_coherent(dwc->sysdev,
sizeof(struct dwc3_trb) * DWC3_TRB_NUM,
&dep->trb_pool_dma, GFP_KERNEL);
if (!dep->trb_pool) {
dev_err(dep->dwc->dev, "failed to allocate trb pool for %s\n",
dep->name);
return -ENOMEM;
}
return 0;
}
static void dwc3_free_trb_pool(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
dma_free_coherent(dwc->sysdev, sizeof(struct dwc3_trb) * DWC3_TRB_NUM,
dep->trb_pool, dep->trb_pool_dma);
dep->trb_pool = NULL;
dep->trb_pool_dma = 0;
}
static int dwc3_gadget_start_config(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_gadget_ep_cmd_params params;
u32 cmd;
int i;
int ret;
if (dep->number)
return 0;
memset(&params, 0x00, sizeof(params));
cmd = DWC3_DEPCMD_DEPSTARTCFG;
ret = dwc3_send_gadget_ep_cmd(dep, cmd, &params);
if (ret)
return ret;
for (i = 0; i < DWC3_ENDPOINTS_NUM; i++) {
struct dwc3_ep *dep = dwc->eps[i];
if (!dep)
continue;
ret = dwc3_gadget_set_xfer_resource(dwc, dep);
if (ret)
return ret;
}
return 0;
}
static int dwc3_gadget_set_ep_config(struct dwc3 *dwc, struct dwc3_ep *dep,
bool modify, bool restore)
{
const struct usb_ss_ep_comp_descriptor *comp_desc;
const struct usb_endpoint_descriptor *desc;
struct dwc3_gadget_ep_cmd_params params;
if (dev_WARN_ONCE(dwc->dev, modify && restore,
"Can't modify and restore\n"))
return -EINVAL;
comp_desc = dep->endpoint.comp_desc;
desc = dep->endpoint.desc;
memset(&params, 0x00, sizeof(params));
params.param0 = DWC3_DEPCFG_EP_TYPE(usb_endpoint_type(desc))
| DWC3_DEPCFG_MAX_PACKET_SIZE(usb_endpoint_maxp(desc));
if (dwc->gadget.speed >= USB_SPEED_SUPER) {
u32 burst = dep->endpoint.maxburst;
params.param0 |= DWC3_DEPCFG_BURST_SIZE(burst - 1);
}
if (modify) {
params.param0 |= DWC3_DEPCFG_ACTION_MODIFY;
} else if (restore) {
params.param0 |= DWC3_DEPCFG_ACTION_RESTORE;
params.param2 |= dep->saved_state;
} else {
params.param0 |= DWC3_DEPCFG_ACTION_INIT;
}
if (usb_endpoint_xfer_control(desc))
params.param1 = DWC3_DEPCFG_XFER_COMPLETE_EN;
if (dep->number <= 1 || usb_endpoint_xfer_isoc(desc))
params.param1 |= DWC3_DEPCFG_XFER_NOT_READY_EN;
if (usb_ss_max_streams(comp_desc) && usb_endpoint_xfer_bulk(desc)) {
params.param1 |= DWC3_DEPCFG_STREAM_CAPABLE
| DWC3_DEPCFG_STREAM_EVENT_EN;
dep->stream_capable = true;
}
if (!usb_endpoint_xfer_control(desc))
params.param1 |= DWC3_DEPCFG_XFER_IN_PROGRESS_EN;
params.param1 |= DWC3_DEPCFG_EP_NUMBER(dep->number);
if (dep->direction)
params.param0 |= DWC3_DEPCFG_FIFO_NUMBER(dep->number >> 1);
if (desc->bInterval) {
params.param1 |= DWC3_DEPCFG_BINTERVAL_M1(desc->bInterval - 1);
dep->interval = 1 << (desc->bInterval - 1);
}
return dwc3_send_gadget_ep_cmd(dep, DWC3_DEPCMD_SETEPCONFIG, &params);
}
static int dwc3_gadget_set_xfer_resource(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_gadget_ep_cmd_params params;
memset(&params, 0x00, sizeof(params));
params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);
return dwc3_send_gadget_ep_cmd(dep, DWC3_DEPCMD_SETTRANSFRESOURCE,
&params);
}
static int __dwc3_gadget_ep_enable(struct dwc3_ep *dep,
bool modify, bool restore)
{
const struct usb_endpoint_descriptor *desc = dep->endpoint.desc;
struct dwc3 *dwc = dep->dwc;
u32 reg;
int ret;
if (!(dep->flags & DWC3_EP_ENABLED)) {
ret = dwc3_gadget_start_config(dwc, dep);
if (ret)
return ret;
}
ret = dwc3_gadget_set_ep_config(dwc, dep, modify, restore);
if (ret)
return ret;
if (!(dep->flags & DWC3_EP_ENABLED)) {
struct dwc3_trb *trb_st_hw;
struct dwc3_trb *trb_link;
dep->type = usb_endpoint_type(desc);
dep->flags |= DWC3_EP_ENABLED;
dep->flags &= ~DWC3_EP_END_TRANSFER_PENDING;
reg = dwc3_readl(dwc->regs, DWC3_DALEPENA);
reg |= DWC3_DALEPENA_EP(dep->number);
dwc3_writel(dwc->regs, DWC3_DALEPENA, reg);
init_waitqueue_head(&dep->wait_end_transfer);
if (usb_endpoint_xfer_control(desc))
goto out;
dep->trb_dequeue = 0;
dep->trb_enqueue = 0;
memset(dep->trb_pool, 0,
sizeof(struct dwc3_trb) * DWC3_TRB_NUM);
trb_st_hw = &dep->trb_pool[0];
trb_link = &dep->trb_pool[DWC3_TRB_NUM - 1];
trb_link->bpl = lower_32_bits(dwc3_trb_dma_offset(dep, trb_st_hw));
trb_link->bph = upper_32_bits(dwc3_trb_dma_offset(dep, trb_st_hw));
trb_link->ctrl |= DWC3_TRBCTL_LINK_TRB;
trb_link->ctrl |= DWC3_TRB_CTRL_HWO;
}
if (usb_endpoint_xfer_bulk(desc)) {
struct dwc3_gadget_ep_cmd_params params;
struct dwc3_trb *trb;
dma_addr_t trb_dma;
u32 cmd;
memset(&params, 0, sizeof(params));
trb = &dep->trb_pool[0];
trb_dma = dwc3_trb_dma_offset(dep, trb);
params.param0 = upper_32_bits(trb_dma);
params.param1 = lower_32_bits(trb_dma);
cmd = DWC3_DEPCMD_STARTTRANSFER;
ret = dwc3_send_gadget_ep_cmd(dep, cmd, &params);
if (ret < 0)
return ret;
dep->flags |= DWC3_EP_BUSY;
dep->resource_index = dwc3_gadget_ep_get_transfer_index(dep);
WARN_ON_ONCE(!dep->resource_index);
}
out:
trace_dwc3_gadget_ep_enable(dep);
return 0;
}
static void dwc3_remove_requests(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_request *req;
dwc3_stop_active_transfer(dwc, dep->number, true);
while (!list_empty(&dep->started_list)) {
req = next_request(&dep->started_list);
dwc3_gadget_giveback(dep, req, -ESHUTDOWN);
}
while (!list_empty(&dep->pending_list)) {
req = next_request(&dep->pending_list);
dwc3_gadget_giveback(dep, req, -ESHUTDOWN);
}
}
static int __dwc3_gadget_ep_disable(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
u32 reg;
trace_dwc3_gadget_ep_disable(dep);
dwc3_remove_requests(dwc, dep);
if (dep->flags & DWC3_EP_STALL)
__dwc3_gadget_ep_set_halt(dep, 0, false);
reg = dwc3_readl(dwc->regs, DWC3_DALEPENA);
reg &= ~DWC3_DALEPENA_EP(dep->number);
dwc3_writel(dwc->regs, DWC3_DALEPENA, reg);
dep->stream_capable = false;
dep->type = 0;
dep->flags &= DWC3_EP_END_TRANSFER_PENDING;
if (dep->number > 1) {
dep->endpoint.comp_desc = NULL;
dep->endpoint.desc = NULL;
}
return 0;
}
static int dwc3_gadget_ep0_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
return -EINVAL;
}
static int dwc3_gadget_ep0_disable(struct usb_ep *ep)
{
return -EINVAL;
}
static int dwc3_gadget_ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct dwc3_ep *dep;
struct dwc3 *dwc;
unsigned long flags;
int ret;
if (!ep || !desc || desc->bDescriptorType != USB_DT_ENDPOINT) {
pr_debug("dwc3: invalid parameters\n");
return -EINVAL;
}
if (!desc->wMaxPacketSize) {
pr_debug("dwc3: missing wMaxPacketSize\n");
return -EINVAL;
}
dep = to_dwc3_ep(ep);
dwc = dep->dwc;
if (dev_WARN_ONCE(dwc->dev, dep->flags & DWC3_EP_ENABLED,
"%s is already enabled\n",
dep->name))
return 0;
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_enable(dep, false, false);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_ep_disable(struct usb_ep *ep)
{
struct dwc3_ep *dep;
struct dwc3 *dwc;
unsigned long flags;
int ret;
if (!ep) {
pr_debug("dwc3: invalid parameters\n");
return -EINVAL;
}
dep = to_dwc3_ep(ep);
dwc = dep->dwc;
if (dev_WARN_ONCE(dwc->dev, !(dep->flags & DWC3_EP_ENABLED),
"%s is already disabled\n",
dep->name))
return 0;
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_disable(dep);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static struct usb_request *dwc3_gadget_ep_alloc_request(struct usb_ep *ep,
gfp_t gfp_flags)
{
struct dwc3_request *req;
struct dwc3_ep *dep = to_dwc3_ep(ep);
req = kzalloc(sizeof(*req), gfp_flags);
if (!req)
return NULL;
req->epnum = dep->number;
req->dep = dep;
dep->allocated_requests++;
trace_dwc3_alloc_request(req);
return &req->request;
}
static void dwc3_gadget_ep_free_request(struct usb_ep *ep,
struct usb_request *request)
{
struct dwc3_request *req = to_dwc3_request(request);
struct dwc3_ep *dep = to_dwc3_ep(ep);
dep->allocated_requests--;
trace_dwc3_free_request(req);
kfree(req);
}
static void __dwc3_prepare_one_trb(struct dwc3_ep *dep, struct dwc3_trb *trb,
dma_addr_t dma, unsigned length, unsigned chain, unsigned node,
unsigned stream_id, unsigned short_not_ok, unsigned no_interrupt)
{
struct dwc3 *dwc = dep->dwc;
struct usb_gadget *gadget = &dwc->gadget;
enum usb_device_speed speed = gadget->speed;
dwc3_ep_inc_enq(dep);
trb->size = DWC3_TRB_SIZE_LENGTH(length);
trb->bpl = lower_32_bits(dma);
trb->bph = upper_32_bits(dma);
switch (usb_endpoint_type(dep->endpoint.desc)) {
case USB_ENDPOINT_XFER_CONTROL:
trb->ctrl = DWC3_TRBCTL_CONTROL_SETUP;
break;
case USB_ENDPOINT_XFER_ISOC:
if (!node) {
trb->ctrl = DWC3_TRBCTL_ISOCHRONOUS_FIRST;
if (speed == USB_SPEED_HIGH) {
struct usb_ep *ep = &dep->endpoint;
unsigned int mult = ep->mult - 1;
unsigned int maxp = usb_endpoint_maxp(ep->desc);
if (length <= (2 * maxp))
mult--;
if (length <= maxp)
mult--;
trb->size |= DWC3_TRB_SIZE_PCM1(mult);
}
} else {
trb->ctrl = DWC3_TRBCTL_ISOCHRONOUS;
}
trb->ctrl |= DWC3_TRB_CTRL_ISP_IMI;
break;
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
trb->ctrl = DWC3_TRBCTL_NORMAL;
break;
default:
dev_WARN(dwc->dev, "Unknown endpoint type %d\n",
usb_endpoint_type(dep->endpoint.desc));
}
if (usb_endpoint_dir_out(dep->endpoint.desc)) {
trb->ctrl |= DWC3_TRB_CTRL_CSP;
if (short_not_ok)
trb->ctrl |= DWC3_TRB_CTRL_ISP_IMI;
}
if ((!no_interrupt && !chain) ||
(dwc3_calc_trbs_left(dep) == 0))
trb->ctrl |= DWC3_TRB_CTRL_IOC;
if (chain)
trb->ctrl |= DWC3_TRB_CTRL_CHN;
if (usb_endpoint_xfer_bulk(dep->endpoint.desc) && dep->stream_capable)
trb->ctrl |= DWC3_TRB_CTRL_SID_SOFN(stream_id);
trb->ctrl |= DWC3_TRB_CTRL_HWO;
trace_dwc3_prepare_trb(dep, trb);
}
static void dwc3_prepare_one_trb(struct dwc3_ep *dep,
struct dwc3_request *req, unsigned chain, unsigned node)
{
struct dwc3_trb *trb;
unsigned length = req->request.length;
unsigned stream_id = req->request.stream_id;
unsigned short_not_ok = req->request.short_not_ok;
unsigned no_interrupt = req->request.no_interrupt;
dma_addr_t dma = req->request.dma;
trb = &dep->trb_pool[dep->trb_enqueue];
if (!req->trb) {
dwc3_gadget_move_started_request(req);
req->trb = trb;
req->trb_dma = dwc3_trb_dma_offset(dep, trb);
dep->queued_requests++;
}
__dwc3_prepare_one_trb(dep, trb, dma, length, chain, node,
stream_id, short_not_ok, no_interrupt);
}
static struct dwc3_trb *dwc3_ep_prev_trb(struct dwc3_ep *dep, u8 index)
{
u8 tmp = index;
if (!tmp)
tmp = DWC3_TRB_NUM - 1;
return &dep->trb_pool[tmp - 1];
}
static u32 dwc3_calc_trbs_left(struct dwc3_ep *dep)
{
struct dwc3_trb *tmp;
u8 trbs_left;
if (dep->trb_enqueue == dep->trb_dequeue) {
tmp = dwc3_ep_prev_trb(dep, dep->trb_enqueue);
if (tmp->ctrl & DWC3_TRB_CTRL_HWO)
return 0;
return DWC3_TRB_NUM - 1;
}
trbs_left = dep->trb_dequeue - dep->trb_enqueue;
trbs_left &= (DWC3_TRB_NUM - 1);
if (dep->trb_dequeue < dep->trb_enqueue)
trbs_left--;
return trbs_left;
}
static void dwc3_prepare_one_trb_sg(struct dwc3_ep *dep,
struct dwc3_request *req)
{
struct scatterlist *sg = req->sg;
struct scatterlist *s;
int i;
for_each_sg(sg, s, req->num_pending_sgs, i) {
unsigned int length = req->request.length;
unsigned int maxp = usb_endpoint_maxp(dep->endpoint.desc);
unsigned int rem = length % maxp;
unsigned chain = true;
if (sg_is_last(s))
chain = false;
if (rem && usb_endpoint_dir_out(dep->endpoint.desc) && !chain) {
struct dwc3 *dwc = dep->dwc;
struct dwc3_trb *trb;
req->unaligned = true;
dwc3_prepare_one_trb(dep, req, true, i);
trb = &dep->trb_pool[dep->trb_enqueue];
__dwc3_prepare_one_trb(dep, trb, dwc->bounce_addr,
maxp - rem, false, 0,
req->request.stream_id,
req->request.short_not_ok,
req->request.no_interrupt);
} else {
dwc3_prepare_one_trb(dep, req, chain, i);
}
if (!dwc3_calc_trbs_left(dep))
break;
}
}
static void dwc3_prepare_one_trb_linear(struct dwc3_ep *dep,
struct dwc3_request *req)
{
unsigned int length = req->request.length;
unsigned int maxp = usb_endpoint_maxp(dep->endpoint.desc);
unsigned int rem = length % maxp;
if (rem && usb_endpoint_dir_out(dep->endpoint.desc)) {
struct dwc3 *dwc = dep->dwc;
struct dwc3_trb *trb;
req->unaligned = true;
dwc3_prepare_one_trb(dep, req, true, 0);
trb = &dep->trb_pool[dep->trb_enqueue];
__dwc3_prepare_one_trb(dep, trb, dwc->bounce_addr, maxp - rem,
false, 0, req->request.stream_id,
req->request.short_not_ok,
req->request.no_interrupt);
} else if (req->request.zero && req->request.length &&
(IS_ALIGNED(req->request.length,dep->endpoint.maxpacket))) {
struct dwc3 *dwc = dep->dwc;
struct dwc3_trb *trb;
req->zero = true;
dwc3_prepare_one_trb(dep, req, true, 0);
trb = &dep->trb_pool[dep->trb_enqueue];
__dwc3_prepare_one_trb(dep, trb, dwc->bounce_addr, 0,
false, 0, req->request.stream_id,
req->request.short_not_ok,
req->request.no_interrupt);
} else {
dwc3_prepare_one_trb(dep, req, false, 0);
}
}
static void dwc3_prepare_trbs(struct dwc3_ep *dep)
{
struct dwc3_request *req, *n;
BUILD_BUG_ON_NOT_POWER_OF_2(DWC3_TRB_NUM);
if (!dwc3_calc_trbs_left(dep))
return;
list_for_each_entry(req, &dep->started_list, list) {
if (req->num_pending_sgs > 0)
dwc3_prepare_one_trb_sg(dep, req);
if (!dwc3_calc_trbs_left(dep))
return;
}
list_for_each_entry_safe(req, n, &dep->pending_list, list) {
struct dwc3 *dwc = dep->dwc;
int ret;
ret = usb_gadget_map_request_by_dev(dwc->sysdev, &req->request,
dep->direction);
if (ret)
return;
req->sg = req->request.sg;
req->num_pending_sgs = req->request.num_mapped_sgs;
if (req->num_pending_sgs > 0)
dwc3_prepare_one_trb_sg(dep, req);
else
dwc3_prepare_one_trb_linear(dep, req);
if (!dwc3_calc_trbs_left(dep))
return;
}
}
static int __dwc3_gadget_kick_transfer(struct dwc3_ep *dep, u16 cmd_param)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3_request *req;
int starting;
int ret;
u32 cmd;
starting = !(dep->flags & DWC3_EP_BUSY);
dwc3_prepare_trbs(dep);
req = next_request(&dep->started_list);
if (!req) {
dep->flags |= DWC3_EP_PENDING_REQUEST;
return 0;
}
memset(&params, 0, sizeof(params));
if (starting) {
params.param0 = upper_32_bits(req->trb_dma);
params.param1 = lower_32_bits(req->trb_dma);
cmd = DWC3_DEPCMD_STARTTRANSFER |
DWC3_DEPCMD_PARAM(cmd_param);
} else {
cmd = DWC3_DEPCMD_UPDATETRANSFER |
DWC3_DEPCMD_PARAM(dep->resource_index);
}
ret = dwc3_send_gadget_ep_cmd(dep, cmd, &params);
if (ret < 0) {
if (req->trb)
memset(req->trb, 0, sizeof(struct dwc3_trb));
dep->queued_requests--;
dwc3_gadget_giveback(dep, req, ret);
return ret;
}
dep->flags |= DWC3_EP_BUSY;
if (starting) {
dep->resource_index = dwc3_gadget_ep_get_transfer_index(dep);
WARN_ON_ONCE(!dep->resource_index);
}
return 0;
}
static int __dwc3_gadget_get_frame(struct dwc3 *dwc)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
return DWC3_DSTS_SOFFN(reg);
}
static void __dwc3_gadget_start_isoc(struct dwc3 *dwc,
struct dwc3_ep *dep, u32 cur_uf)
{
u32 uf;
if (list_empty(&dep->pending_list)) {
dev_info(dwc->dev, "%s: ran out of requests\n",
dep->name);
dep->flags |= DWC3_EP_PENDING_REQUEST;
return;
}
uf = cur_uf + max_t(u32, 4, dep->interval);
__dwc3_gadget_kick_transfer(dep, uf);
}
static void dwc3_gadget_start_isoc(struct dwc3 *dwc,
struct dwc3_ep *dep, const struct dwc3_event_depevt *event)
{
u32 cur_uf, mask;
mask = ~(dep->interval - 1);
cur_uf = event->parameters & mask;
__dwc3_gadget_start_isoc(dwc, dep, cur_uf);
}
static int __dwc3_gadget_ep_queue(struct dwc3_ep *dep, struct dwc3_request *req)
{
struct dwc3 *dwc = dep->dwc;
int ret = 0;
if (!dep->endpoint.desc) {
dev_err(dwc->dev, "%s: can't queue to disabled endpoint\n",
dep->name);
return -ESHUTDOWN;
}
if (WARN(req->dep != dep, "request %pK belongs to '%s'\n",
&req->request, req->dep->name))
return -EINVAL;
pm_runtime_get(dwc->dev);
req->request.actual = 0;
req->request.status = -EINPROGRESS;
req->direction = dep->direction;
req->epnum = dep->number;
trace_dwc3_ep_queue(req);
list_add_tail(&req->list, &dep->pending_list);
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
if ((dep->flags & DWC3_EP_PENDING_REQUEST)) {
if (dep->flags & DWC3_EP_TRANSFER_STARTED) {
dwc3_stop_active_transfer(dwc, dep->number, true);
dep->flags = DWC3_EP_ENABLED;
} else {
u32 cur_uf;
cur_uf = __dwc3_gadget_get_frame(dwc);
__dwc3_gadget_start_isoc(dwc, dep, cur_uf);
dep->flags &= ~DWC3_EP_PENDING_REQUEST;
}
return 0;
}
if ((dep->flags & DWC3_EP_BUSY) &&
!(dep->flags & DWC3_EP_MISSED_ISOC)) {
WARN_ON_ONCE(!dep->resource_index);
ret = __dwc3_gadget_kick_transfer(dep,
dep->resource_index);
}
goto out;
}
if (!dwc3_calc_trbs_left(dep))
return 0;
ret = __dwc3_gadget_kick_transfer(dep, 0);
out:
if (ret == -EBUSY)
ret = 0;
return ret;
}
static int dwc3_gadget_ep_queue(struct usb_ep *ep, struct usb_request *request,
gfp_t gfp_flags)
{
struct dwc3_request *req = to_dwc3_request(request);
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret;
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_queue(dep, req);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_ep_dequeue(struct usb_ep *ep,
struct usb_request *request)
{
struct dwc3_request *req = to_dwc3_request(request);
struct dwc3_request *r = NULL;
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret = 0;
trace_dwc3_ep_dequeue(req);
spin_lock_irqsave(&dwc->lock, flags);
list_for_each_entry(r, &dep->pending_list, list) {
if (r == req)
break;
}
if (r != req) {
list_for_each_entry(r, &dep->started_list, list) {
if (r == req)
break;
}
if (r == req) {
dwc3_stop_active_transfer(dwc, dep->number, true);
wait_event_lock_irq(dep->wait_end_transfer,
!(dep->flags & DWC3_EP_END_TRANSFER_PENDING),
dwc->lock);
if (!r->trb)
goto out1;
if (r->num_pending_sgs) {
struct dwc3_trb *trb;
int i = 0;
for (i = 0; i < r->num_pending_sgs; i++) {
trb = r->trb + i;
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
dwc3_ep_inc_deq(dep);
}
if (r->unaligned || r->zero) {
trb = r->trb + r->num_pending_sgs + 1;
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
dwc3_ep_inc_deq(dep);
}
} else {
struct dwc3_trb *trb = r->trb;
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
dwc3_ep_inc_deq(dep);
if (r->unaligned || r->zero) {
trb = r->trb + 1;
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
dwc3_ep_inc_deq(dep);
}
}
goto out1;
}
dev_err(dwc->dev, "request %pK was not queued to %s\n",
request, ep->name);
ret = -EINVAL;
goto out0;
}
out1:
dep->queued_requests--;
dwc3_gadget_giveback(dep, req, -ECONNRESET);
out0:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
int __dwc3_gadget_ep_set_halt(struct dwc3_ep *dep, int value, int protocol)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3 *dwc = dep->dwc;
int ret;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dev_err(dwc->dev, "%s is of Isochronous type\n", dep->name);
return -EINVAL;
}
memset(&params, 0x00, sizeof(params));
if (value) {
struct dwc3_trb *trb;
unsigned transfer_in_flight;
unsigned started;
if (dep->flags & DWC3_EP_STALL)
return 0;
if (dep->number > 1)
trb = dwc3_ep_prev_trb(dep, dep->trb_enqueue);
else
trb = &dwc->ep0_trb[dep->trb_enqueue];
transfer_in_flight = trb->ctrl & DWC3_TRB_CTRL_HWO;
started = !list_empty(&dep->started_list);
if (!protocol && ((dep->direction && transfer_in_flight) ||
(!dep->direction && started))) {
return -EAGAIN;
}
ret = dwc3_send_gadget_ep_cmd(dep, DWC3_DEPCMD_SETSTALL,
&params);
if (ret)
dev_err(dwc->dev, "failed to set STALL on %s\n",
dep->name);
else
dep->flags |= DWC3_EP_STALL;
} else {
if (!(dep->flags & DWC3_EP_STALL))
return 0;
ret = dwc3_send_clear_stall_ep_cmd(dep);
if (ret)
dev_err(dwc->dev, "failed to clear STALL on %s\n",
dep->name);
else
dep->flags &= ~(DWC3_EP_STALL | DWC3_EP_WEDGE);
}
return ret;
}
static int dwc3_gadget_ep_set_halt(struct usb_ep *ep, int value)
{
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret;
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_set_halt(dep, value, false);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_ep_set_wedge(struct usb_ep *ep)
{
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret;
spin_lock_irqsave(&dwc->lock, flags);
dep->flags |= DWC3_EP_WEDGE;
if (dep->number == 0 || dep->number == 1)
ret = __dwc3_gadget_ep0_set_halt(ep, 1);
else
ret = __dwc3_gadget_ep_set_halt(dep, 1, false);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_get_frame(struct usb_gadget *g)
{
struct dwc3 *dwc = gadget_to_dwc(g);
return __dwc3_gadget_get_frame(dwc);
}
static int __dwc3_gadget_wakeup(struct dwc3 *dwc)
{
int retries;
int ret;
u32 reg;
u8 link_state;
u8 speed;
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
speed = reg & DWC3_DSTS_CONNECTSPD;
if ((speed == DWC3_DSTS_SUPERSPEED) ||
(speed == DWC3_DSTS_SUPERSPEED_PLUS))
return 0;
link_state = DWC3_DSTS_USBLNKST(reg);
switch (link_state) {
case DWC3_LINK_STATE_RX_DET:
case DWC3_LINK_STATE_U3:
break;
default:
return -EINVAL;
}
ret = dwc3_gadget_set_link_state(dwc, DWC3_LINK_STATE_RECOV);
if (ret < 0) {
dev_err(dwc->dev, "failed to put link in Recovery\n");
return ret;
}
if (dwc->revision < DWC3_REVISION_194A) {
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_ULSTCHNGREQ_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
}
retries = 20000;
while (retries--) {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
if (DWC3_DSTS_USBLNKST(reg) == DWC3_LINK_STATE_U0)
break;
}
if (DWC3_DSTS_USBLNKST(reg) != DWC3_LINK_STATE_U0) {
dev_err(dwc->dev, "failed to send remote wakeup\n");
return -EINVAL;
}
return 0;
}
static int dwc3_gadget_wakeup(struct usb_gadget *g)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
int ret;
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_wakeup(dwc);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_set_selfpowered(struct usb_gadget *g,
int is_selfpowered)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
g->is_selfpowered = !!is_selfpowered;
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_gadget_run_stop(struct dwc3 *dwc, int is_on, int suspend)
{
u32 reg;
u32 timeout = 500;
if (pm_runtime_suspended(dwc->dev))
return 0;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (is_on) {
if (dwc->revision <= DWC3_REVISION_187A) {
reg &= ~DWC3_DCTL_TRGTULST_MASK;
reg |= DWC3_DCTL_TRGTULST_RX_DET;
}
if (dwc->revision >= DWC3_REVISION_194A)
reg &= ~DWC3_DCTL_KEEP_CONNECT;
reg |= DWC3_DCTL_RUN_STOP;
if (dwc->has_hibernation)
reg |= DWC3_DCTL_KEEP_CONNECT;
dwc->pullups_connected = true;
} else {
reg &= ~DWC3_DCTL_RUN_STOP;
if (dwc->has_hibernation && !suspend)
reg &= ~DWC3_DCTL_KEEP_CONNECT;
dwc->pullups_connected = false;
}
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
do {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
reg &= DWC3_DSTS_DEVCTRLHLT;
} while (--timeout && !(!is_on ^ !reg));
if (!timeout)
return -ETIMEDOUT;
return 0;
}
static int dwc3_gadget_pullup(struct usb_gadget *g, int is_on)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
int ret;
is_on = !!is_on;
if (!is_on && dwc->ep0state != EP0_SETUP_PHASE) {
reinit_completion(&dwc->ep0_in_setup);
ret = wait_for_completion_timeout(&dwc->ep0_in_setup,
msecs_to_jiffies(DWC3_PULL_UP_TIMEOUT));
if (ret == 0) {
dev_err(dwc->dev, "timed out waiting for SETUP phase\n");
return -ETIMEDOUT;
}
}
spin_lock_irqsave(&dwc->lock, flags);
ret = dwc3_gadget_run_stop(dwc, is_on, false);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static void dwc3_gadget_enable_irq(struct dwc3 *dwc)
{
u32 reg;
reg = (DWC3_DEVTEN_VNDRDEVTSTRCVEDEN |
DWC3_DEVTEN_EVNTOVERFLOWEN |
DWC3_DEVTEN_CMDCMPLTEN |
DWC3_DEVTEN_ERRTICERREN |
DWC3_DEVTEN_WKUPEVTEN |
DWC3_DEVTEN_CONNECTDONEEN |
DWC3_DEVTEN_USBRSTEN |
DWC3_DEVTEN_DISCONNEVTEN);
if (dwc->revision < DWC3_REVISION_250A)
reg |= DWC3_DEVTEN_ULSTCNGEN;
dwc3_writel(dwc->regs, DWC3_DEVTEN, reg);
}
static void dwc3_gadget_disable_irq(struct dwc3 *dwc)
{
dwc3_writel(dwc->regs, DWC3_DEVTEN, 0x00);
}
static void dwc3_gadget_setup_nump(struct dwc3 *dwc)
{
u32 ram2_depth;
u32 mdwidth;
u32 nump;
u32 reg;
ram2_depth = DWC3_GHWPARAMS7_RAM2_DEPTH(dwc->hwparams.hwparams7);
mdwidth = DWC3_GHWPARAMS0_MDWIDTH(dwc->hwparams.hwparams0);
nump = ((ram2_depth * mdwidth / 8) - 24 - 16) / 1024;
nump = min_t(u32, nump, 16);
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~DWC3_DCFG_NUMP_MASK;
reg |= nump << DWC3_DCFG_NUMP_SHIFT;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
}
static int __dwc3_gadget_start(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
int ret = 0;
u32 reg;
if (dwc->imod_interval) {
dwc3_writel(dwc->regs, DWC3_DEV_IMOD(0), dwc->imod_interval);
dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(0), DWC3_GEVNTCOUNT_EHB);
} else if (dwc3_has_imod(dwc)) {
dwc3_writel(dwc->regs, DWC3_DEV_IMOD(0), 0);
}
reg = dwc3_readl(dwc->regs, DWC3_GRXTHRCFG);
reg &= ~DWC3_GRXTHRCFG_PKTCNTSEL;
dwc3_writel(dwc->regs, DWC3_GRXTHRCFG, reg);
dwc3_gadget_setup_nump(dwc);
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, false, false);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
goto err0;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, false, false);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
goto err1;
}
dwc->ep0state = EP0_SETUP_PHASE;
dwc3_ep0_out_start(dwc);
dwc3_gadget_enable_irq(dwc);
return 0;
err1:
__dwc3_gadget_ep_disable(dwc->eps[0]);
err0:
return ret;
}
static int dwc3_gadget_start(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
int ret = 0;
int irq;
irq = dwc->irq_gadget;
ret = request_threaded_irq(irq, dwc3_interrupt, dwc3_thread_interrupt,
IRQF_SHARED, "dwc3", dwc->ev_buf);
if (ret) {
dev_err(dwc->dev, "failed to request irq #%d --> %d\n",
irq, ret);
goto err0;
}
spin_lock_irqsave(&dwc->lock, flags);
if (dwc->gadget_driver) {
dev_err(dwc->dev, "%s is already bound to %s\n",
dwc->gadget.name,
dwc->gadget_driver->driver.name);
ret = -EBUSY;
goto err1;
}
dwc->gadget_driver = driver;
if (pm_runtime_active(dwc->dev))
__dwc3_gadget_start(dwc);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
err1:
spin_unlock_irqrestore(&dwc->lock, flags);
free_irq(irq, dwc);
err0:
return ret;
}
static void __dwc3_gadget_stop(struct dwc3 *dwc)
{
dwc3_gadget_disable_irq(dwc);
__dwc3_gadget_ep_disable(dwc->eps[0]);
__dwc3_gadget_ep_disable(dwc->eps[1]);
}
static int dwc3_gadget_stop(struct usb_gadget *g)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
int epnum;
spin_lock_irqsave(&dwc->lock, flags);
if (pm_runtime_suspended(dwc->dev))
goto out;
__dwc3_gadget_stop(dwc);
for (epnum = 2; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
struct dwc3_ep *dep = dwc->eps[epnum];
if (!dep)
continue;
if (!(dep->flags & DWC3_EP_END_TRANSFER_PENDING))
continue;
wait_event_lock_irq(dep->wait_end_transfer,
!(dep->flags & DWC3_EP_END_TRANSFER_PENDING),
dwc->lock);
}
out:
dwc->gadget_driver = NULL;
spin_unlock_irqrestore(&dwc->lock, flags);
free_irq(dwc->irq_gadget, dwc->ev_buf);
return 0;
}
static void dwc3_gadget_set_speed(struct usb_gadget *g,
enum usb_device_speed speed)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
u32 reg;
spin_lock_irqsave(&dwc->lock, flags);
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~(DWC3_DCFG_SPEED_MASK);
if (dwc->revision < DWC3_REVISION_220A) {
reg |= DWC3_DCFG_SUPERSPEED;
} else {
switch (speed) {
case USB_SPEED_LOW:
reg |= DWC3_DCFG_LOWSPEED;
break;
case USB_SPEED_FULL:
reg |= DWC3_DCFG_FULLSPEED;
break;
case USB_SPEED_HIGH:
reg |= DWC3_DCFG_HIGHSPEED;
break;
case USB_SPEED_SUPER:
reg |= DWC3_DCFG_SUPERSPEED;
break;
case USB_SPEED_SUPER_PLUS:
reg |= DWC3_DCFG_SUPERSPEED_PLUS;
break;
default:
dev_err(dwc->dev, "invalid speed (%d)\n", speed);
if (dwc->revision & DWC3_REVISION_IS_DWC31)
reg |= DWC3_DCFG_SUPERSPEED_PLUS;
else
reg |= DWC3_DCFG_SUPERSPEED;
}
}
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
spin_unlock_irqrestore(&dwc->lock, flags);
}
static int dwc3_gadget_init_endpoints(struct dwc3 *dwc, u8 total)
{
struct dwc3_ep *dep;
u8 epnum;
INIT_LIST_HEAD(&dwc->gadget.ep_list);
for (epnum = 0; epnum < total; epnum++) {
bool direction = epnum & 1;
u8 num = epnum >> 1;
dep = kzalloc(sizeof(*dep), GFP_KERNEL);
if (!dep)
return -ENOMEM;
dep->dwc = dwc;
dep->number = epnum;
dep->direction = direction;
dep->regs = dwc->regs + DWC3_DEP_BASE(epnum);
dwc->eps[epnum] = dep;
snprintf(dep->name, sizeof(dep->name), "ep%u%s", num,
direction ? "in" : "out");
dep->endpoint.name = dep->name;
if (!(dep->number > 1)) {
dep->endpoint.desc = &dwc3_gadget_ep0_desc;
dep->endpoint.comp_desc = NULL;
}
spin_lock_init(&dep->lock);
if (num == 0) {
usb_ep_set_maxpacket_limit(&dep->endpoint, 512);
dep->endpoint.maxburst = 1;
dep->endpoint.ops = &dwc3_gadget_ep0_ops;
if (!direction)
dwc->gadget.ep0 = &dep->endpoint;
} else if (direction) {
int mdwidth;
int kbytes;
int size;
int ret;
mdwidth = DWC3_MDWIDTH(dwc->hwparams.hwparams0);
mdwidth /= 8;
size = dwc3_readl(dwc->regs, DWC3_GTXFIFOSIZ(num));
size = DWC3_GTXFIFOSIZ_TXFDEF(size);
size *= mdwidth;
kbytes = size / 1024;
if (kbytes == 0)
kbytes = 1;
size -= mdwidth * (kbytes + 1);
size /= kbytes;
usb_ep_set_maxpacket_limit(&dep->endpoint, size);
dep->endpoint.max_streams = 15;
dep->endpoint.ops = &dwc3_gadget_ep_ops;
list_add_tail(&dep->endpoint.ep_list,
&dwc->gadget.ep_list);
ret = dwc3_alloc_trb_pool(dep);
if (ret)
return ret;
} else {
int ret;
usb_ep_set_maxpacket_limit(&dep->endpoint, 1024);
dep->endpoint.max_streams = 15;
dep->endpoint.ops = &dwc3_gadget_ep_ops;
list_add_tail(&dep->endpoint.ep_list,
&dwc->gadget.ep_list);
ret = dwc3_alloc_trb_pool(dep);
if (ret)
return ret;
}
if (num == 0) {
dep->endpoint.caps.type_control = true;
} else {
dep->endpoint.caps.type_iso = true;
dep->endpoint.caps.type_bulk = true;
dep->endpoint.caps.type_int = true;
}
dep->endpoint.caps.dir_in = direction;
dep->endpoint.caps.dir_out = !direction;
INIT_LIST_HEAD(&dep->pending_list);
INIT_LIST_HEAD(&dep->started_list);
}
return 0;
}
static void dwc3_gadget_free_endpoints(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
u8 epnum;
for (epnum = 0; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
dep = dwc->eps[epnum];
if (!dep)
continue;
if (epnum != 0 && epnum != 1) {
dwc3_free_trb_pool(dep);
list_del(&dep->endpoint.ep_list);
}
kfree(dep);
}
}
static int __dwc3_cleanup_done_trbs(struct dwc3 *dwc, struct dwc3_ep *dep,
struct dwc3_request *req, struct dwc3_trb *trb,
const struct dwc3_event_depevt *event, int status,
int chain)
{
unsigned int count;
unsigned int s_pkt = 0;
unsigned int trb_status;
dwc3_ep_inc_deq(dep);
if (req->trb == trb)
dep->queued_requests--;
trace_dwc3_complete_trb(dep, trb);
if (chain && (trb->ctrl & DWC3_TRB_CTRL_HWO))
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
if ((req->zero || req->unaligned) && (trb->ctrl & DWC3_TRB_CTRL_HWO)) {
trb->ctrl &= ~DWC3_TRB_CTRL_HWO;
return 1;
}
count = trb->size & DWC3_TRB_SIZE_MASK;
req->remaining += count;
if ((trb->ctrl & DWC3_TRB_CTRL_HWO) && status != -ESHUTDOWN)
return 1;
if (dep->direction) {
if (count) {
trb_status = DWC3_TRB_SIZE_TRBSTS(trb->size);
if (trb_status == DWC3_TRBSTS_MISSED_ISOC) {
dep->flags |= DWC3_EP_MISSED_ISOC;
} else {
dev_err(dwc->dev, "incomplete IN transfer %s\n",
dep->name);
status = -ECONNRESET;
}
} else {
dep->flags &= ~DWC3_EP_MISSED_ISOC;
}
} else {
if (count && (event->status & DEPEVT_STATUS_SHORT))
s_pkt = 1;
}
if (s_pkt && !chain)
return 1;
if ((event->status & DEPEVT_STATUS_IOC) &&
(trb->ctrl & DWC3_TRB_CTRL_IOC))
return 1;
return 0;
}
static int dwc3_cleanup_done_reqs(struct dwc3 *dwc, struct dwc3_ep *dep,
const struct dwc3_event_depevt *event, int status)
{
struct dwc3_request *req, *n;
struct dwc3_trb *trb;
bool ioc = false;
int ret = 0;
list_for_each_entry_safe(req, n, &dep->started_list, list) {
unsigned length;
int chain;
length = req->request.length;
chain = req->num_pending_sgs > 0;
if (chain) {
struct scatterlist *sg = req->sg;
struct scatterlist *s;
unsigned int pending = req->num_pending_sgs;
unsigned int i;
for_each_sg(sg, s, pending, i) {
trb = &dep->trb_pool[dep->trb_dequeue];
if (trb->ctrl & DWC3_TRB_CTRL_HWO)
break;
req->sg = sg_next(s);
req->num_pending_sgs--;
ret = __dwc3_cleanup_done_trbs(dwc, dep, req, trb,
event, status, chain);
if (ret)
break;
}
} else {
trb = &dep->trb_pool[dep->trb_dequeue];
ret = __dwc3_cleanup_done_trbs(dwc, dep, req, trb,
event, status, chain);
}
if (req->unaligned || req->zero) {
trb = &dep->trb_pool[dep->trb_dequeue];
ret = __dwc3_cleanup_done_trbs(dwc, dep, req, trb,
event, status, false);
req->unaligned = false;
req->zero = false;
}
req->request.actual = length - req->remaining;
if ((req->request.actual < length) && req->num_pending_sgs)
return __dwc3_gadget_kick_transfer(dep, 0);
dwc3_gadget_giveback(dep, req, status);
if (ret) {
if ((event->status & DEPEVT_STATUS_IOC) &&
(trb->ctrl & DWC3_TRB_CTRL_IOC))
ioc = true;
break;
}
}
if (!dep->endpoint.desc)
return 1;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc) &&
list_empty(&dep->started_list)) {
if (list_empty(&dep->pending_list)) {
dep->flags = DWC3_EP_PENDING_REQUEST;
} else {
dwc3_stop_active_transfer(dwc, dep->number, true);
dep->flags = DWC3_EP_ENABLED;
}
return 1;
}
if (usb_endpoint_xfer_isoc(dep->endpoint.desc) && ioc)
return 0;
return 1;
}
static void dwc3_endpoint_transfer_complete(struct dwc3 *dwc,
struct dwc3_ep *dep, const struct dwc3_event_depevt *event)
{
unsigned status = 0;
int clean_busy;
u32 is_xfer_complete;
is_xfer_complete = (event->endpoint_event == DWC3_DEPEVT_XFERCOMPLETE);
if (event->status & DEPEVT_STATUS_BUSERR)
status = -ECONNRESET;
clean_busy = dwc3_cleanup_done_reqs(dwc, dep, event, status);
if (clean_busy && (!dep->endpoint.desc || is_xfer_complete ||
usb_endpoint_xfer_isoc(dep->endpoint.desc)))
dep->flags &= ~DWC3_EP_BUSY;
if (dwc->revision < DWC3_REVISION_183A) {
u32 reg;
int i;
for (i = 0; i < DWC3_ENDPOINTS_NUM; i++) {
dep = dwc->eps[i];
if (!(dep->flags & DWC3_EP_ENABLED))
continue;
if (!list_empty(&dep->started_list))
return;
}
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg |= dwc->u1u2;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc->u1u2 = 0;
}
if (!dep->endpoint.desc)
return;
if (!usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
int ret;
ret = __dwc3_gadget_kick_transfer(dep, 0);
if (!ret || ret == -EBUSY)
return;
}
}
static void dwc3_endpoint_interrupt(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep;
u8 epnum = event->endpoint_number;
u8 cmd;
dep = dwc->eps[epnum];
if (!(dep->flags & DWC3_EP_ENABLED)) {
if (!(dep->flags & DWC3_EP_END_TRANSFER_PENDING))
return;
if (event->endpoint_event != DWC3_DEPEVT_EPCMDCMPLT)
return;
}
if (epnum == 0 || epnum == 1) {
dwc3_ep0_interrupt(dwc, event);
return;
}
switch (event->endpoint_event) {
case DWC3_DEPEVT_XFERCOMPLETE:
dep->resource_index = 0;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dev_err(dwc->dev, "XferComplete for Isochronous endpoint\n");
return;
}
dwc3_endpoint_transfer_complete(dwc, dep, event);
break;
case DWC3_DEPEVT_XFERINPROGRESS:
dwc3_endpoint_transfer_complete(dwc, dep, event);
break;
case DWC3_DEPEVT_XFERNOTREADY:
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dwc3_gadget_start_isoc(dwc, dep, event);
} else {
int ret;
ret = __dwc3_gadget_kick_transfer(dep, 0);
if (!ret || ret == -EBUSY)
return;
}
break;
case DWC3_DEPEVT_STREAMEVT:
if (!usb_endpoint_xfer_bulk(dep->endpoint.desc)) {
dev_err(dwc->dev, "Stream event for non-Bulk %s\n",
dep->name);
return;
}
break;
case DWC3_DEPEVT_EPCMDCMPLT:
cmd = DEPEVT_PARAMETER_CMD(event->parameters);
if (cmd == DWC3_DEPCMD_ENDTRANSFER) {
dep->flags &= ~DWC3_EP_END_TRANSFER_PENDING;
wake_up(&dep->wait_end_transfer);
}
break;
case DWC3_DEPEVT_RXTXFIFOEVT:
break;
}
}
static void dwc3_disconnect_gadget(struct dwc3 *dwc)
{
if (dwc->gadget_driver && dwc->gadget_driver->disconnect) {
spin_unlock(&dwc->lock);
dwc->gadget_driver->disconnect(&dwc->gadget);
spin_lock(&dwc->lock);
}
}
static void dwc3_suspend_gadget(struct dwc3 *dwc)
{
if (dwc->gadget_driver && dwc->gadget_driver->suspend) {
spin_unlock(&dwc->lock);
dwc->gadget_driver->suspend(&dwc->gadget);
spin_lock(&dwc->lock);
}
}
static void dwc3_resume_gadget(struct dwc3 *dwc)
{
if (dwc->gadget_driver && dwc->gadget_driver->resume) {
spin_unlock(&dwc->lock);
dwc->gadget_driver->resume(&dwc->gadget);
spin_lock(&dwc->lock);
}
}
static void dwc3_reset_gadget(struct dwc3 *dwc)
{
if (!dwc->gadget_driver)
return;
if (dwc->gadget.speed != USB_SPEED_UNKNOWN) {
spin_unlock(&dwc->lock);
usb_gadget_udc_reset(&dwc->gadget, dwc->gadget_driver);
spin_lock(&dwc->lock);
}
}
static void dwc3_stop_active_transfer(struct dwc3 *dwc, u32 epnum, bool force)
{
struct dwc3_ep *dep;
struct dwc3_gadget_ep_cmd_params params;
u32 cmd;
int ret;
dep = dwc->eps[epnum];
if ((dep->flags & DWC3_EP_END_TRANSFER_PENDING) ||
!dep->resource_index)
return;
cmd = DWC3_DEPCMD_ENDTRANSFER;
cmd |= force ? DWC3_DEPCMD_HIPRI_FORCERM : 0;
cmd |= DWC3_DEPCMD_CMDIOC;
cmd |= DWC3_DEPCMD_PARAM(dep->resource_index);
memset(&params, 0, sizeof(params));
ret = dwc3_send_gadget_ep_cmd(dep, cmd, &params);
WARN_ON_ONCE(ret);
dep->resource_index = 0;
dep->flags &= ~DWC3_EP_BUSY;
if (dwc3_is_usb31(dwc) || dwc->revision < DWC3_REVISION_310A) {
dep->flags |= DWC3_EP_END_TRANSFER_PENDING;
udelay(100);
}
}
static void dwc3_clear_stall_all_ep(struct dwc3 *dwc)
{
u32 epnum;
for (epnum = 1; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
struct dwc3_ep *dep;
int ret;
dep = dwc->eps[epnum];
if (!dep)
continue;
if (!(dep->flags & DWC3_EP_STALL))
continue;
dep->flags &= ~DWC3_EP_STALL;
ret = dwc3_send_clear_stall_ep_cmd(dep);
WARN_ON_ONCE(ret);
}
}
static void dwc3_gadget_disconnect_interrupt(struct dwc3 *dwc)
{
int reg;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc3_disconnect_gadget(dwc);
dwc->gadget.speed = USB_SPEED_UNKNOWN;
dwc->setup_packet_pending = false;
usb_gadget_set_state(&dwc->gadget, USB_STATE_NOTATTACHED);
dwc->connected = false;
}
static void dwc3_gadget_reset_interrupt(struct dwc3 *dwc)
{
u32 reg;
dwc->connected = true;
if (dwc->revision < DWC3_REVISION_188A) {
if (dwc->setup_packet_pending)
dwc3_gadget_disconnect_interrupt(dwc);
}
dwc3_reset_gadget(dwc);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_TSTCTRL_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc->test_mode = false;
dwc3_clear_stall_all_ep(dwc);
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~(DWC3_DCFG_DEVADDR_MASK);
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
}
static void dwc3_gadget_conndone_interrupt(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
int ret;
u32 reg;
u8 speed;
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
speed = reg & DWC3_DSTS_CONNECTSPD;
dwc->speed = speed;
switch (speed) {
case DWC3_DSTS_SUPERSPEED_PLUS:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dwc->gadget.ep0->maxpacket = 512;
dwc->gadget.speed = USB_SPEED_SUPER_PLUS;
break;
case DWC3_DSTS_SUPERSPEED:
if (dwc->revision < DWC3_REVISION_190A)
dwc3_gadget_reset_interrupt(dwc);
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dwc->gadget.ep0->maxpacket = 512;
dwc->gadget.speed = USB_SPEED_SUPER;
break;
case DWC3_DSTS_HIGHSPEED:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(64);
dwc->gadget.ep0->maxpacket = 64;
dwc->gadget.speed = USB_SPEED_HIGH;
break;
case DWC3_DSTS_FULLSPEED:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(64);
dwc->gadget.ep0->maxpacket = 64;
dwc->gadget.speed = USB_SPEED_FULL;
break;
case DWC3_DSTS_LOWSPEED:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(8);
dwc->gadget.ep0->maxpacket = 8;
dwc->gadget.speed = USB_SPEED_LOW;
break;
}
if ((dwc->revision > DWC3_REVISION_194A) &&
(speed != DWC3_DSTS_SUPERSPEED) &&
(speed != DWC3_DSTS_SUPERSPEED_PLUS)) {
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg |= DWC3_DCFG_LPM_CAP;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~(DWC3_DCTL_HIRD_THRES_MASK | DWC3_DCTL_L1_HIBER_EN);
reg |= DWC3_DCTL_HIRD_THRES(dwc->hird_threshold);
WARN_ONCE(dwc->revision < DWC3_REVISION_240A
&& dwc->has_lpm_erratum,
"LPM Erratum not available on dwc3 revisions < 2.40a\n");
if (dwc->has_lpm_erratum && dwc->revision >= DWC3_REVISION_240A)
reg |= DWC3_DCTL_LPM_ERRATA(dwc->lpm_nyet_threshold);
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
} else {
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_HIRD_THRES_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
}
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, true, false);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
return;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, true, false);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
return;
}
}
static void dwc3_gadget_wakeup_interrupt(struct dwc3 *dwc)
{
if (dwc->gadget_driver && dwc->gadget_driver->resume) {
spin_unlock(&dwc->lock);
dwc->gadget_driver->resume(&dwc->gadget);
spin_lock(&dwc->lock);
}
}
static void dwc3_gadget_linksts_change_interrupt(struct dwc3 *dwc,
unsigned int evtinfo)
{
enum dwc3_link_state next = evtinfo & DWC3_LINK_STATE_MASK;
unsigned int pwropt;
pwropt = DWC3_GHWPARAMS1_EN_PWROPT(dwc->hwparams.hwparams1);
if ((dwc->revision < DWC3_REVISION_250A) &&
(pwropt != DWC3_GHWPARAMS1_EN_PWROPT_HIB)) {
if ((dwc->link_state == DWC3_LINK_STATE_U3) &&
(next == DWC3_LINK_STATE_RESUME)) {
return;
}
}
if (dwc->revision < DWC3_REVISION_183A) {
if (next == DWC3_LINK_STATE_U0) {
u32 u1u2;
u32 reg;
switch (dwc->link_state) {
case DWC3_LINK_STATE_U1:
case DWC3_LINK_STATE_U2:
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
u1u2 = reg & (DWC3_DCTL_INITU2ENA
| DWC3_DCTL_ACCEPTU2ENA
| DWC3_DCTL_INITU1ENA
| DWC3_DCTL_ACCEPTU1ENA);
if (!dwc->u1u2)
dwc->u1u2 = reg & u1u2;
reg &= ~u1u2;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
break;
default:
break;
}
}
}
switch (next) {
case DWC3_LINK_STATE_U1:
if (dwc->speed == USB_SPEED_SUPER)
dwc3_suspend_gadget(dwc);
break;
case DWC3_LINK_STATE_U2:
case DWC3_LINK_STATE_U3:
dwc3_suspend_gadget(dwc);
break;
case DWC3_LINK_STATE_RESUME:
dwc3_resume_gadget(dwc);
break;
default:
break;
}
dwc->link_state = next;
}
static void dwc3_gadget_suspend_interrupt(struct dwc3 *dwc,
unsigned int evtinfo)
{
enum dwc3_link_state next = evtinfo & DWC3_LINK_STATE_MASK;
if (dwc->link_state != next && next == DWC3_LINK_STATE_U3)
dwc3_suspend_gadget(dwc);
dwc->link_state = next;
}
static void dwc3_gadget_hibernation_interrupt(struct dwc3 *dwc,
unsigned int evtinfo)
{
unsigned int is_ss = evtinfo & BIT(4);
if (is_ss ^ (dwc->speed == USB_SPEED_SUPER))
return;
}
static void dwc3_gadget_interrupt(struct dwc3 *dwc,
const struct dwc3_event_devt *event)
{
switch (event->type) {
case DWC3_DEVICE_EVENT_DISCONNECT:
dwc3_gadget_disconnect_interrupt(dwc);
break;
case DWC3_DEVICE_EVENT_RESET:
dwc3_gadget_reset_interrupt(dwc);
break;
case DWC3_DEVICE_EVENT_CONNECT_DONE:
dwc3_gadget_conndone_interrupt(dwc);
break;
case DWC3_DEVICE_EVENT_WAKEUP:
dwc3_gadget_wakeup_interrupt(dwc);
break;
case DWC3_DEVICE_EVENT_HIBER_REQ:
if (dev_WARN_ONCE(dwc->dev, !dwc->has_hibernation,
"unexpected hibernation event\n"))
break;
dwc3_gadget_hibernation_interrupt(dwc, event->event_info);
break;
case DWC3_DEVICE_EVENT_LINK_STATUS_CHANGE:
dwc3_gadget_linksts_change_interrupt(dwc, event->event_info);
break;
case DWC3_DEVICE_EVENT_EOPF:
if (dwc->revision >= DWC3_REVISION_230A) {
if (dwc->gadget.state >= USB_STATE_CONFIGURED)
dwc3_gadget_suspend_interrupt(dwc,
event->event_info);
}
break;
case DWC3_DEVICE_EVENT_SOF:
case DWC3_DEVICE_EVENT_ERRATIC_ERROR:
case DWC3_DEVICE_EVENT_CMD_CMPL:
case DWC3_DEVICE_EVENT_OVERFLOW:
break;
default:
dev_WARN(dwc->dev, "UNKNOWN IRQ %d\n", event->type);
}
}
static void dwc3_process_event_entry(struct dwc3 *dwc,
const union dwc3_event *event)
{
trace_dwc3_event(event->raw, dwc);
if (!event->type.is_devspec)
dwc3_endpoint_interrupt(dwc, &event->depevt);
else if (event->type.type == DWC3_EVENT_TYPE_DEV)
dwc3_gadget_interrupt(dwc, &event->devt);
else
dev_err(dwc->dev, "UNKNOWN IRQ type %d\n", event->raw);
}
static irqreturn_t dwc3_process_event_buf(struct dwc3_event_buffer *evt)
{
struct dwc3 *dwc = evt->dwc;
irqreturn_t ret = IRQ_NONE;
int left;
u32 reg;
left = evt->count;
if (!(evt->flags & DWC3_EVENT_PENDING))
return IRQ_NONE;
while (left > 0) {
union dwc3_event event;
event.raw = *(u32 *) (evt->cache + evt->lpos);
dwc3_process_event_entry(dwc, &event);
evt->lpos = (evt->lpos + 4) % evt->length;
left -= 4;
}
evt->count = 0;
evt->flags &= ~DWC3_EVENT_PENDING;
ret = IRQ_HANDLED;
reg = dwc3_readl(dwc->regs, DWC3_GEVNTSIZ(0));
reg &= ~DWC3_GEVNTSIZ_INTMASK;
dwc3_writel(dwc->regs, DWC3_GEVNTSIZ(0), reg);
if (dwc->imod_interval) {
dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(0), DWC3_GEVNTCOUNT_EHB);
dwc3_writel(dwc->regs, DWC3_DEV_IMOD(0), dwc->imod_interval);
}
return ret;
}
static irqreturn_t dwc3_thread_interrupt(int irq, void *_evt)
{
struct dwc3_event_buffer *evt = _evt;
struct dwc3 *dwc = evt->dwc;
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
spin_lock_irqsave(&dwc->lock, flags);
ret = dwc3_process_event_buf(evt);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static irqreturn_t dwc3_check_event_buf(struct dwc3_event_buffer *evt)
{
struct dwc3 *dwc = evt->dwc;
u32 amount;
u32 count;
u32 reg;
if (pm_runtime_suspended(dwc->dev)) {
pm_runtime_get(dwc->dev);
disable_irq_nosync(dwc->irq_gadget);
dwc->pending_events = true;
return IRQ_HANDLED;
}
if (evt->flags & DWC3_EVENT_PENDING)
return IRQ_HANDLED;
count = dwc3_readl(dwc->regs, DWC3_GEVNTCOUNT(0));
count &= DWC3_GEVNTCOUNT_MASK;
if (!count)
return IRQ_NONE;
evt->count = count;
evt->flags |= DWC3_EVENT_PENDING;
reg = dwc3_readl(dwc->regs, DWC3_GEVNTSIZ(0));
reg |= DWC3_GEVNTSIZ_INTMASK;
dwc3_writel(dwc->regs, DWC3_GEVNTSIZ(0), reg);
amount = min(count, evt->length - evt->lpos);
memcpy(evt->cache + evt->lpos, evt->buf + evt->lpos, amount);
if (amount < count)
memcpy(evt->cache, evt->buf, count - amount);
dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(0), count);
return IRQ_WAKE_THREAD;
}
static irqreturn_t dwc3_interrupt(int irq, void *_evt)
{
struct dwc3_event_buffer *evt = _evt;
return dwc3_check_event_buf(evt);
}
static int dwc3_gadget_get_irq(struct dwc3 *dwc)
{
struct platform_device *dwc3_pdev = to_platform_device(dwc->dev);
int irq;
irq = platform_get_irq_byname(dwc3_pdev, "peripheral");
if (irq > 0)
goto out;
if (irq == -EPROBE_DEFER)
goto out;
irq = platform_get_irq_byname(dwc3_pdev, "dwc_usb3");
if (irq > 0)
goto out;
if (irq == -EPROBE_DEFER)
goto out;
irq = platform_get_irq(dwc3_pdev, 0);
if (irq > 0)
goto out;
if (irq != -EPROBE_DEFER)
dev_err(dwc->dev, "missing peripheral IRQ\n");
if (!irq)
irq = -EINVAL;
out:
return irq;
}
int dwc3_gadget_init(struct dwc3 *dwc)
{
int ret;
int irq;
irq = dwc3_gadget_get_irq(dwc);
if (irq < 0) {
ret = irq;
goto err0;
}
dwc->irq_gadget = irq;
dwc->ep0_trb = dma_alloc_coherent(dwc->sysdev,
sizeof(*dwc->ep0_trb) * 2,
&dwc->ep0_trb_addr, GFP_KERNEL);
if (!dwc->ep0_trb) {
dev_err(dwc->dev, "failed to allocate ep0 trb\n");
ret = -ENOMEM;
goto err0;
}
dwc->setup_buf = kzalloc(DWC3_EP0_SETUP_SIZE, GFP_KERNEL);
if (!dwc->setup_buf) {
ret = -ENOMEM;
goto err1;
}
dwc->bounce = dma_alloc_coherent(dwc->sysdev, DWC3_BOUNCE_SIZE,
&dwc->bounce_addr, GFP_KERNEL);
if (!dwc->bounce) {
ret = -ENOMEM;
goto err2;
}
init_completion(&dwc->ep0_in_setup);
dwc->gadget.ops = &dwc3_gadget_ops;
dwc->gadget.speed = USB_SPEED_UNKNOWN;
dwc->gadget.sg_supported = true;
dwc->gadget.name = "dwc3-gadget";
dwc->gadget.is_otg = dwc->dr_mode == USB_DR_MODE_OTG;
if (dwc->revision < DWC3_REVISION_220A)
dev_info(dwc->dev, "changing max_speed on rev %08x\n",
dwc->revision);
dwc->gadget.max_speed = dwc->maximum_speed;
ret = dwc3_gadget_init_endpoints(dwc, dwc->num_eps);
if (ret)
goto err3;
ret = usb_add_gadget_udc(dwc->dev, &dwc->gadget);
if (ret) {
dev_err(dwc->dev, "failed to register udc\n");
goto err4;
}
return 0;
err4:
dwc3_gadget_free_endpoints(dwc);
err3:
dma_free_coherent(dwc->sysdev, DWC3_BOUNCE_SIZE, dwc->bounce,
dwc->bounce_addr);
err2:
kfree(dwc->setup_buf);
err1:
dma_free_coherent(dwc->sysdev, sizeof(*dwc->ep0_trb) * 2,
dwc->ep0_trb, dwc->ep0_trb_addr);
err0:
return ret;
}
void dwc3_gadget_exit(struct dwc3 *dwc)
{
usb_del_gadget_udc(&dwc->gadget);
dwc3_gadget_free_endpoints(dwc);
dma_free_coherent(dwc->sysdev, DWC3_BOUNCE_SIZE, dwc->bounce,
dwc->bounce_addr);
kfree(dwc->setup_buf);
dma_free_coherent(dwc->sysdev, sizeof(*dwc->ep0_trb) * 2,
dwc->ep0_trb, dwc->ep0_trb_addr);
}
int dwc3_gadget_suspend(struct dwc3 *dwc)
{
if (!dwc->gadget_driver)
return 0;
dwc3_gadget_run_stop(dwc, false, false);
dwc3_disconnect_gadget(dwc);
__dwc3_gadget_stop(dwc);
return 0;
}
int dwc3_gadget_resume(struct dwc3 *dwc)
{
int ret;
if (!dwc->gadget_driver)
return 0;
ret = __dwc3_gadget_start(dwc);
if (ret < 0)
goto err0;
ret = dwc3_gadget_run_stop(dwc, true, false);
if (ret < 0)
goto err1;
return 0;
err1:
__dwc3_gadget_stop(dwc);
err0:
return ret;
}
void dwc3_gadget_process_pending_events(struct dwc3 *dwc)
{
if (dwc->pending_events) {
dwc3_interrupt(dwc->irq_gadget, dwc->ev_buf);
dwc->pending_events = false;
enable_irq(dwc->irq_gadget);
}
}
