void dwc3_map_buffer_to_dma(struct dwc3_request *req)
{
struct dwc3 *dwc = req->dep->dwc;
if (req->request.length == 0) {
return;
}
if (req->request.num_sgs) {
int mapped;
mapped = dma_map_sg(dwc->dev, req->request.sg,
req->request.num_sgs,
req->direction ? DMA_TO_DEVICE
: DMA_FROM_DEVICE);
if (mapped < 0) {
dev_err(dwc->dev, "failed to map SGs\n");
return;
}
req->request.num_mapped_sgs = mapped;
return;
}
if (req->request.dma == DMA_ADDR_INVALID) {
req->request.dma = dma_map_single(dwc->dev, req->request.buf,
req->request.length, req->direction
? DMA_TO_DEVICE : DMA_FROM_DEVICE);
req->mapped = true;
}
}
void dwc3_unmap_buffer_from_dma(struct dwc3_request *req)
{
struct dwc3 *dwc = req->dep->dwc;
if (req->request.length == 0) {
req->request.dma = DMA_ADDR_INVALID;
return;
}
if (req->request.num_mapped_sgs) {
req->request.dma = DMA_ADDR_INVALID;
dma_unmap_sg(dwc->dev, req->request.sg,
req->request.num_mapped_sgs,
req->direction ? DMA_TO_DEVICE
: DMA_FROM_DEVICE);
req->request.num_mapped_sgs = 0;
return;
}
if (req->mapped) {
dma_unmap_single(dwc->dev, req->request.dma,
req->request.length, req->direction
? DMA_TO_DEVICE : DMA_FROM_DEVICE);
req->mapped = 0;
req->request.dma = DMA_ADDR_INVALID;
}
}
void dwc3_gadget_giveback(struct dwc3_ep *dep, struct dwc3_request *req,
int status)
{
struct dwc3 *dwc = dep->dwc;
if (req->queued) {
if (req->request.num_mapped_sgs)
dep->busy_slot += req->request.num_mapped_sgs;
else
dep->busy_slot++;
if (((dep->busy_slot & DWC3_TRB_MASK) == DWC3_TRB_NUM - 1) &&
usb_endpoint_xfer_isoc(dep->desc))
dep->busy_slot++;
}
list_del(&req->list);
req->trb = NULL;
if (req->request.status == -EINPROGRESS)
req->request.status = status;
dwc3_unmap_buffer_from_dma(req);
dev_dbg(dwc->dev, "request %p from %s completed %d/%d ===> %d\n",
req, dep->name, req->request.actual,
req->request.length, status);
spin_unlock(&dwc->lock);
req->request.complete(&req->dep->endpoint, &req->request);
spin_lock(&dwc->lock);
}
static const char *dwc3_gadget_ep_cmd_string(u8 cmd)
{
switch (cmd) {
case DWC3_DEPCMD_DEPSTARTCFG:
return "Start New Configuration";
case DWC3_DEPCMD_ENDTRANSFER:
return "End Transfer";
case DWC3_DEPCMD_UPDATETRANSFER:
return "Update Transfer";
case DWC3_DEPCMD_STARTTRANSFER:
return "Start Transfer";
case DWC3_DEPCMD_CLEARSTALL:
return "Clear Stall";
case DWC3_DEPCMD_SETSTALL:
return "Set Stall";
case DWC3_DEPCMD_GETSEQNUMBER:
return "Get Data Sequence Number";
case DWC3_DEPCMD_SETTRANSFRESOURCE:
return "Set Endpoint Transfer Resource";
case DWC3_DEPCMD_SETEPCONFIG:
return "Set Endpoint Configuration";
default:
return "UNKNOWN command";
}
}
int dwc3_send_gadget_ep_cmd(struct dwc3 *dwc, unsigned ep,
unsigned cmd, struct dwc3_gadget_ep_cmd_params *params)
{
struct dwc3_ep *dep = dwc->eps[ep];
u32 timeout = 500;
u32 reg;
dev_vdbg(dwc->dev, "%s: cmd '%s' params %08x %08x %08x\n",
dep->name,
dwc3_gadget_ep_cmd_string(cmd), params->param0,
params->param1, params->param2);
dwc3_writel(dwc->regs, DWC3_DEPCMDPAR0(ep), params->param0);
dwc3_writel(dwc->regs, DWC3_DEPCMDPAR1(ep), params->param1);
dwc3_writel(dwc->regs, DWC3_DEPCMDPAR2(ep), params->param2);
dwc3_writel(dwc->regs, DWC3_DEPCMD(ep), cmd | DWC3_DEPCMD_CMDACT);
do {
reg = dwc3_readl(dwc->regs, DWC3_DEPCMD(ep));
if (!(reg & DWC3_DEPCMD_CMDACT)) {
dev_vdbg(dwc->dev, "Command Complete --> %d\n",
DWC3_DEPCMD_STATUS(reg));
return 0;
}
timeout--;
if (!timeout)
return -ETIMEDOUT;
udelay(1);
} while (1);
}
static dma_addr_t dwc3_trb_dma_offset(struct dwc3_ep *dep,
struct dwc3_trb_hw *trb)
{
u32 offset = (char *) trb - (char *) dep->trb_pool;
return dep->trb_pool_dma + offset;
}
static int dwc3_alloc_trb_pool(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
if (dep->trb_pool)
return 0;
if (dep->number == 0 || dep->number == 1)
return 0;
dep->trb_pool = dma_alloc_coherent(dwc->dev,
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
dma_free_coherent(dwc->dev, sizeof(struct dwc3_trb) * DWC3_TRB_NUM,
dep->trb_pool, dep->trb_pool_dma);
dep->trb_pool = NULL;
dep->trb_pool_dma = 0;
}
static int dwc3_gadget_start_config(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_gadget_ep_cmd_params params;
u32 cmd;
memset(&params, 0x00, sizeof(params));
if (dep->number != 1) {
cmd = DWC3_DEPCMD_DEPSTARTCFG;
if (dep->number > 1) {
if (dwc->start_config_issued)
return 0;
dwc->start_config_issued = true;
cmd |= DWC3_DEPCMD_PARAM(2);
}
return dwc3_send_gadget_ep_cmd(dwc, 0, cmd, &params);
}
return 0;
}
static int dwc3_gadget_set_ep_config(struct dwc3 *dwc, struct dwc3_ep *dep,
const struct usb_endpoint_descriptor *desc,
const struct usb_ss_ep_comp_descriptor *comp_desc)
{
struct dwc3_gadget_ep_cmd_params params;
memset(&params, 0x00, sizeof(params));
params.param0 = DWC3_DEPCFG_EP_TYPE(usb_endpoint_type(desc))
| DWC3_DEPCFG_MAX_PACKET_SIZE(usb_endpoint_maxp(desc))
| DWC3_DEPCFG_BURST_SIZE(dep->endpoint.maxburst);
params.param1 = DWC3_DEPCFG_XFER_COMPLETE_EN
| DWC3_DEPCFG_XFER_NOT_READY_EN;
if (usb_ss_max_streams(comp_desc) && usb_endpoint_xfer_bulk(desc)) {
params.param1 |= DWC3_DEPCFG_STREAM_CAPABLE
| DWC3_DEPCFG_STREAM_EVENT_EN;
dep->stream_capable = true;
}
if (usb_endpoint_xfer_isoc(desc))
params.param1 |= DWC3_DEPCFG_XFER_IN_PROGRESS_EN;
params.param1 |= DWC3_DEPCFG_EP_NUMBER(dep->number);
if (dep->direction)
params.param0 |= DWC3_DEPCFG_FIFO_NUMBER(dep->number >> 1);
if (desc->bInterval) {
params.param1 |= DWC3_DEPCFG_BINTERVAL_M1(desc->bInterval - 1);
dep->interval = 1 << (desc->bInterval - 1);
}
return dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_SETEPCONFIG, &params);
}
static int dwc3_gadget_set_xfer_resource(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_gadget_ep_cmd_params params;
memset(&params, 0x00, sizeof(params));
params.param0 = DWC3_DEPXFERCFG_NUM_XFER_RES(1);
return dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_SETTRANSFRESOURCE, &params);
}
static int __dwc3_gadget_ep_enable(struct dwc3_ep *dep,
const struct usb_endpoint_descriptor *desc,
const struct usb_ss_ep_comp_descriptor *comp_desc)
{
struct dwc3 *dwc = dep->dwc;
u32 reg;
int ret = -ENOMEM;
if (!(dep->flags & DWC3_EP_ENABLED)) {
ret = dwc3_gadget_start_config(dwc, dep);
if (ret)
return ret;
}
ret = dwc3_gadget_set_ep_config(dwc, dep, desc, comp_desc);
if (ret)
return ret;
if (!(dep->flags & DWC3_EP_ENABLED)) {
struct dwc3_trb_hw *trb_st_hw;
struct dwc3_trb_hw *trb_link_hw;
struct dwc3_trb trb_link;
ret = dwc3_gadget_set_xfer_resource(dwc, dep);
if (ret)
return ret;
dep->desc = desc;
dep->comp_desc = comp_desc;
dep->type = usb_endpoint_type(desc);
dep->flags |= DWC3_EP_ENABLED;
reg = dwc3_readl(dwc->regs, DWC3_DALEPENA);
reg |= DWC3_DALEPENA_EP(dep->number);
dwc3_writel(dwc->regs, DWC3_DALEPENA, reg);
if (!usb_endpoint_xfer_isoc(desc))
return 0;
memset(&trb_link, 0, sizeof(trb_link));
trb_st_hw = &dep->trb_pool[0];
trb_link.bplh = dwc3_trb_dma_offset(dep, trb_st_hw);
trb_link.trbctl = DWC3_TRBCTL_LINK_TRB;
trb_link.hwo = true;
trb_link_hw = &dep->trb_pool[DWC3_TRB_NUM - 1];
dwc3_trb_to_hw(&trb_link, trb_link_hw);
}
return 0;
}
static void dwc3_remove_requests(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_request *req;
if (!list_empty(&dep->req_queued))
dwc3_stop_active_transfer(dwc, dep->number);
while (!list_empty(&dep->request_list)) {
req = next_request(&dep->request_list);
dwc3_gadget_giveback(dep, req, -ESHUTDOWN);
}
}
static int __dwc3_gadget_ep_disable(struct dwc3_ep *dep)
{
struct dwc3 *dwc = dep->dwc;
u32 reg;
dwc3_remove_requests(dwc, dep);
reg = dwc3_readl(dwc->regs, DWC3_DALEPENA);
reg &= ~DWC3_DALEPENA_EP(dep->number);
dwc3_writel(dwc->regs, DWC3_DALEPENA, reg);
dep->stream_capable = false;
dep->desc = NULL;
dep->comp_desc = NULL;
dep->type = 0;
dep->flags = 0;
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
switch (usb_endpoint_type(desc)) {
case USB_ENDPOINT_XFER_CONTROL:
strncat(dep->name, "-control", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_ISOC:
strncat(dep->name, "-isoc", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_BULK:
strncat(dep->name, "-bulk", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_INT:
strncat(dep->name, "-int", sizeof(dep->name));
break;
default:
dev_err(dwc->dev, "invalid endpoint transfer type\n");
}
if (dep->flags & DWC3_EP_ENABLED) {
dev_WARN_ONCE(dwc->dev, true, "%s is already enabled\n",
dep->name);
return 0;
}
dev_vdbg(dwc->dev, "Enabling %s\n", dep->name);
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_enable(dep, desc, ep->comp_desc);
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
if (!(dep->flags & DWC3_EP_ENABLED)) {
dev_WARN_ONCE(dwc->dev, true, "%s is already disabled\n",
dep->name);
return 0;
}
snprintf(dep->name, sizeof(dep->name), "ep%d%s",
dep->number >> 1,
(dep->number & 1) ? "in" : "out");
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
struct dwc3 *dwc = dep->dwc;
req = kzalloc(sizeof(*req), gfp_flags);
if (!req) {
dev_err(dwc->dev, "not enough memory\n");
return NULL;
}
req->epnum = dep->number;
req->dep = dep;
req->request.dma = DMA_ADDR_INVALID;
return &req->request;
}
static void dwc3_gadget_ep_free_request(struct usb_ep *ep,
struct usb_request *request)
{
struct dwc3_request *req = to_dwc3_request(request);
kfree(req);
}
static void dwc3_prepare_one_trb(struct dwc3_ep *dep,
struct dwc3_request *req, dma_addr_t dma,
unsigned length, unsigned last, unsigned chain)
{
struct dwc3 *dwc = dep->dwc;
struct dwc3_trb_hw *trb_hw;
struct dwc3_trb trb;
unsigned int cur_slot;
dev_vdbg(dwc->dev, "%s: req %p dma %08llx length %d%s%s\n",
dep->name, req, (unsigned long long) dma,
length, last ? " last" : "",
chain ? " chain" : "");
trb_hw = &dep->trb_pool[dep->free_slot & DWC3_TRB_MASK];
cur_slot = dep->free_slot;
dep->free_slot++;
if (((cur_slot & DWC3_TRB_MASK) == DWC3_TRB_NUM - 1) &&
usb_endpoint_xfer_isoc(dep->desc))
return;
memset(&trb, 0, sizeof(trb));
if (!req->trb) {
dwc3_gadget_move_request_queued(req);
req->trb = trb_hw;
req->trb_dma = dwc3_trb_dma_offset(dep, trb_hw);
}
if (usb_endpoint_xfer_isoc(dep->desc)) {
trb.isp_imi = true;
trb.csp = true;
} else {
trb.chn = chain;
trb.lst = last;
}
if (usb_endpoint_xfer_bulk(dep->desc) && dep->stream_capable)
trb.sid_sofn = req->request.stream_id;
switch (usb_endpoint_type(dep->desc)) {
case USB_ENDPOINT_XFER_CONTROL:
trb.trbctl = DWC3_TRBCTL_CONTROL_SETUP;
break;
case USB_ENDPOINT_XFER_ISOC:
trb.trbctl = DWC3_TRBCTL_ISOCHRONOUS_FIRST;
if (!(cur_slot % (DWC3_TRB_NUM / 4)))
trb.ioc = last;
break;
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
trb.trbctl = DWC3_TRBCTL_NORMAL;
break;
default:
BUG();
}
trb.length = length;
trb.bplh = dma;
trb.hwo = true;
dwc3_trb_to_hw(&trb, trb_hw);
}
static void dwc3_prepare_trbs(struct dwc3_ep *dep, bool starting)
{
struct dwc3_request *req, *n;
u32 trbs_left;
unsigned int last_one = 0;
BUILD_BUG_ON_NOT_POWER_OF_2(DWC3_TRB_NUM);
trbs_left = (dep->busy_slot - dep->free_slot) & DWC3_TRB_MASK;
if (!trbs_left) {
if (!starting)
return;
trbs_left = DWC3_TRB_NUM;
if (usb_endpoint_xfer_isoc(dep->desc)) {
dep->busy_slot = 1;
dep->free_slot = 1;
} else {
dep->busy_slot = 0;
dep->free_slot = 0;
}
}
if ((trbs_left <= 1) && usb_endpoint_xfer_isoc(dep->desc))
return;
list_for_each_entry_safe(req, n, &dep->request_list, list) {
unsigned length;
dma_addr_t dma;
if (req->request.num_mapped_sgs > 0) {
struct usb_request *request = &req->request;
struct scatterlist *sg = request->sg;
struct scatterlist *s;
int i;
for_each_sg(sg, s, request->num_mapped_sgs, i) {
unsigned chain = true;
length = sg_dma_len(s);
dma = sg_dma_address(s);
if (i == (request->num_mapped_sgs - 1)
|| sg_is_last(s)) {
last_one = true;
chain = false;
}
trbs_left--;
if (!trbs_left)
last_one = true;
if (last_one)
chain = false;
dwc3_prepare_one_trb(dep, req, dma, length,
last_one, chain);
if (last_one)
break;
}
} else {
dma = req->request.dma;
length = req->request.length;
trbs_left--;
if (!trbs_left)
last_one = 1;
if (list_is_last(&req->list, &dep->request_list))
last_one = 1;
dwc3_prepare_one_trb(dep, req, dma, length,
last_one, false);
if (last_one)
break;
}
}
}
static int __dwc3_gadget_kick_transfer(struct dwc3_ep *dep, u16 cmd_param,
int start_new)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3_request *req;
struct dwc3 *dwc = dep->dwc;
int ret;
u32 cmd;
if (start_new && (dep->flags & DWC3_EP_BUSY)) {
dev_vdbg(dwc->dev, "%s: endpoint busy\n", dep->name);
return -EBUSY;
}
dep->flags &= ~DWC3_EP_PENDING_REQUEST;
if (start_new) {
if (list_empty(&dep->req_queued))
dwc3_prepare_trbs(dep, start_new);
req = next_request(&dep->req_queued);
} else {
dwc3_prepare_trbs(dep, start_new);
req = next_request(&dep->req_queued);
}
if (!req) {
dep->flags |= DWC3_EP_PENDING_REQUEST;
return 0;
}
memset(&params, 0, sizeof(params));
params.param0 = upper_32_bits(req->trb_dma);
params.param1 = lower_32_bits(req->trb_dma);
if (start_new)
cmd = DWC3_DEPCMD_STARTTRANSFER;
else
cmd = DWC3_DEPCMD_UPDATETRANSFER;
cmd |= DWC3_DEPCMD_PARAM(cmd_param);
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number, cmd, &params);
if (ret < 0) {
dev_dbg(dwc->dev, "failed to send STARTTRANSFER command\n");
dwc3_unmap_buffer_from_dma(req);
list_del(&req->list);
return ret;
}
dep->flags |= DWC3_EP_BUSY;
dep->res_trans_idx = dwc3_gadget_ep_get_transfer_index(dwc,
dep->number);
WARN_ON_ONCE(!dep->res_trans_idx);
return 0;
}
static int __dwc3_gadget_ep_queue(struct dwc3_ep *dep, struct dwc3_request *req)
{
req->request.actual = 0;
req->request.status = -EINPROGRESS;
req->direction = dep->direction;
req->epnum = dep->number;
dwc3_map_buffer_to_dma(req);
list_add_tail(&req->list, &dep->request_list);
if (dep->flags & DWC3_EP_PENDING_REQUEST) {
int ret;
int start_trans;
start_trans = 1;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc) &&
dep->flags & DWC3_EP_BUSY)
start_trans = 0;
ret = __dwc3_gadget_kick_transfer(dep, 0, start_trans);
if (ret && ret != -EBUSY) {
struct dwc3 *dwc = dep->dwc;
dev_dbg(dwc->dev, "%s: failed to kick transfers\n",
dep->name);
}
};
return 0;
}
static int dwc3_gadget_ep_queue(struct usb_ep *ep, struct usb_request *request,
gfp_t gfp_flags)
{
struct dwc3_request *req = to_dwc3_request(request);
struct dwc3_ep *dep = to_dwc3_ep(ep);
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int ret;
if (!dep->desc) {
dev_dbg(dwc->dev, "trying to queue request %p to disabled %s\n",
request, ep->name);
return -ESHUTDOWN;
}
dev_vdbg(dwc->dev, "queing request %p to %s length %d\n",
request, ep->name, request->length);
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
spin_lock_irqsave(&dwc->lock, flags);
list_for_each_entry(r, &dep->request_list, list) {
if (r == req)
break;
}
if (r != req) {
list_for_each_entry(r, &dep->req_queued, list) {
if (r == req)
break;
}
if (r == req) {
dwc3_stop_active_transfer(dwc, dep->number);
goto out0;
}
dev_err(dwc->dev, "request %p was not queued to %s\n",
request, ep->name);
ret = -EINVAL;
goto out0;
}
dwc3_gadget_giveback(dep, req, -ECONNRESET);
out0:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
int __dwc3_gadget_ep_set_halt(struct dwc3_ep *dep, int value)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3 *dwc = dep->dwc;
int ret;
memset(&params, 0x00, sizeof(params));
if (value) {
if (dep->number == 0 || dep->number == 1) {
dwc->ep0state = EP0_SETUP_PHASE;
}
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_SETSTALL, &params);
if (ret)
dev_err(dwc->dev, "failed to %s STALL on %s\n",
value ? "set" : "clear",
dep->name);
else
dep->flags |= DWC3_EP_STALL;
} else {
if (dep->flags & DWC3_EP_WEDGE)
return 0;
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_CLEARSTALL, &params);
if (ret)
dev_err(dwc->dev, "failed to %s STALL on %s\n",
value ? "set" : "clear",
dep->name);
else
dep->flags &= ~DWC3_EP_STALL;
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
if (usb_endpoint_xfer_isoc(dep->desc)) {
dev_err(dwc->dev, "%s is of Isochronous type\n", dep->name);
ret = -EINVAL;
goto out;
}
ret = __dwc3_gadget_ep_set_halt(dep, value);
out:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_ep_set_wedge(struct usb_ep *ep)
{
struct dwc3_ep *dep = to_dwc3_ep(ep);
dep->flags |= DWC3_EP_WEDGE;
return dwc3_gadget_ep_set_halt(ep, 1);
}
static int dwc3_gadget_get_frame(struct usb_gadget *g)
{
struct dwc3 *dwc = gadget_to_dwc(g);
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
return DWC3_DSTS_SOFFN(reg);
}
static int dwc3_gadget_wakeup(struct usb_gadget *g)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long timeout;
unsigned long flags;
u32 reg;
int ret = 0;
u8 link_state;
u8 speed;
spin_lock_irqsave(&dwc->lock, flags);
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
speed = reg & DWC3_DSTS_CONNECTSPD;
if (speed == DWC3_DSTS_SUPERSPEED) {
dev_dbg(dwc->dev, "no wakeup on SuperSpeed\n");
ret = -EINVAL;
goto out;
}
link_state = DWC3_DSTS_USBLNKST(reg);
switch (link_state) {
case DWC3_LINK_STATE_RX_DET:
case DWC3_LINK_STATE_U3:
break;
default:
dev_dbg(dwc->dev, "can't wakeup from link state %d\n",
link_state);
ret = -EINVAL;
goto out;
}
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg |= DWC3_DCTL_ULSTCHNG_RECOVERY;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
usleep_range(2000, 2500);
reg &= ~DWC3_DCTL_ULSTCHNGREQ_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
timeout = jiffies + msecs_to_jiffies(100);
while (!(time_after(jiffies, timeout))) {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
if (DWC3_DSTS_USBLNKST(reg) == DWC3_LINK_STATE_U0)
break;
}
if (DWC3_DSTS_USBLNKST(reg) != DWC3_LINK_STATE_U0) {
dev_err(dwc->dev, "failed to send remote wakeup\n");
ret = -EINVAL;
}
out:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_set_selfpowered(struct usb_gadget *g,
int is_selfpowered)
{
struct dwc3 *dwc = gadget_to_dwc(g);
dwc->is_selfpowered = !!is_selfpowered;
return 0;
}
static void dwc3_gadget_run_stop(struct dwc3 *dwc, int is_on)
{
u32 reg;
u32 timeout = 500;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (is_on)
reg |= DWC3_DCTL_RUN_STOP;
else
reg &= ~DWC3_DCTL_RUN_STOP;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
do {
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
if (is_on) {
if (!(reg & DWC3_DSTS_DEVCTRLHLT))
break;
} else {
if (reg & DWC3_DSTS_DEVCTRLHLT)
break;
}
timeout--;
if (!timeout)
break;
udelay(1);
} while (1);
dev_vdbg(dwc->dev, "gadget %s data soft-%s\n",
dwc->gadget_driver
? dwc->gadget_driver->function : "no-function",
is_on ? "connect" : "disconnect");
}
static int dwc3_gadget_pullup(struct usb_gadget *g, int is_on)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
is_on = !!is_on;
spin_lock_irqsave(&dwc->lock, flags);
dwc3_gadget_run_stop(dwc, is_on);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_gadget_start(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct dwc3 *dwc = gadget_to_dwc(g);
struct dwc3_ep *dep;
unsigned long flags;
int ret = 0;
u32 reg;
spin_lock_irqsave(&dwc->lock, flags);
if (dwc->gadget_driver) {
dev_err(dwc->dev, "%s is already bound to %s\n",
dwc->gadget.name,
dwc->gadget_driver->driver.name);
ret = -EBUSY;
goto err0;
}
dwc->gadget_driver = driver;
dwc->gadget.dev.driver = &driver->driver;
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~(DWC3_DCFG_SPEED_MASK);
reg |= dwc->maximum_speed;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
dwc->start_config_issued = false;
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
goto err0;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
goto err1;
}
dwc->ep0state = EP0_SETUP_PHASE;
dwc3_ep0_out_start(dwc);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
err1:
__dwc3_gadget_ep_disable(dwc->eps[0]);
err0:
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
}
static int dwc3_gadget_stop(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
__dwc3_gadget_ep_disable(dwc->eps[0]);
__dwc3_gadget_ep_disable(dwc->eps[1]);
dwc->gadget_driver = NULL;
dwc->gadget.dev.driver = NULL;
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int __devinit dwc3_gadget_init_endpoints(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
u8 epnum;
INIT_LIST_HEAD(&dwc->gadget.ep_list);
for (epnum = 0; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
dep = kzalloc(sizeof(*dep), GFP_KERNEL);
if (!dep) {
dev_err(dwc->dev, "can't allocate endpoint %d\n",
epnum);
return -ENOMEM;
}
dep->dwc = dwc;
dep->number = epnum;
dwc->eps[epnum] = dep;
snprintf(dep->name, sizeof(dep->name), "ep%d%s", epnum >> 1,
(epnum & 1) ? "in" : "out");
dep->endpoint.name = dep->name;
dep->direction = (epnum & 1);
if (epnum == 0 || epnum == 1) {
dep->endpoint.maxpacket = 512;
dep->endpoint.ops = &dwc3_gadget_ep0_ops;
if (!epnum)
dwc->gadget.ep0 = &dep->endpoint;
} else {
int ret;
dep->endpoint.maxpacket = 1024;
dep->endpoint.max_streams = 15;
dep->endpoint.ops = &dwc3_gadget_ep_ops;
list_add_tail(&dep->endpoint.ep_list,
&dwc->gadget.ep_list);
ret = dwc3_alloc_trb_pool(dep);
if (ret)
return ret;
}
INIT_LIST_HEAD(&dep->request_list);
INIT_LIST_HEAD(&dep->req_queued);
}
return 0;
}
static void dwc3_gadget_free_endpoints(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
u8 epnum;
for (epnum = 0; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
dep = dwc->eps[epnum];
dwc3_free_trb_pool(dep);
if (epnum != 0 && epnum != 1)
list_del(&dep->endpoint.ep_list);
kfree(dep);
}
}
static void dwc3_gadget_release(struct device *dev)
{
dev_dbg(dev, "%s\n", __func__);
}
static int dwc3_cleanup_done_reqs(struct dwc3 *dwc, struct dwc3_ep *dep,
const struct dwc3_event_depevt *event, int status)
{
struct dwc3_request *req;
struct dwc3_trb trb;
unsigned int count;
unsigned int s_pkt = 0;
do {
req = next_request(&dep->req_queued);
if (!req) {
WARN_ON_ONCE(1);
return 1;
}
dwc3_trb_to_nat(req->trb, &trb);
if (trb.hwo && status != -ESHUTDOWN)
dev_err(dwc->dev, "%s's TRB (%p) still owned by HW\n",
dep->name, req->trb);
count = trb.length;
if (dep->direction) {
if (count) {
dev_err(dwc->dev, "incomplete IN transfer %s\n",
dep->name);
status = -ECONNRESET;
}
} else {
if (count && (event->status & DEPEVT_STATUS_SHORT))
s_pkt = 1;
}
req->request.actual += req->request.length - count;
dwc3_gadget_giveback(dep, req, status);
if (s_pkt)
break;
if ((event->status & DEPEVT_STATUS_LST) && trb.lst)
break;
if ((event->status & DEPEVT_STATUS_IOC) && trb.ioc)
break;
} while (1);
if ((event->status & DEPEVT_STATUS_IOC) && trb.ioc)
return 0;
return 1;
}
static void dwc3_endpoint_transfer_complete(struct dwc3 *dwc,
struct dwc3_ep *dep, const struct dwc3_event_depevt *event,
int start_new)
{
unsigned status = 0;
int clean_busy;
if (event->status & DEPEVT_STATUS_BUSERR)
status = -ECONNRESET;
clean_busy = dwc3_cleanup_done_reqs(dwc, dep, event, status);
if (clean_busy) {
dep->flags &= ~DWC3_EP_BUSY;
dep->res_trans_idx = 0;
}
if (dwc->revision < DWC3_REVISION_183A) {
u32 reg;
int i;
for (i = 0; i < DWC3_ENDPOINTS_NUM; i++) {
struct dwc3_ep *dep = dwc->eps[i];
if (!(dep->flags & DWC3_EP_ENABLED))
continue;
if (!list_empty(&dep->req_queued))
return;
}
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg |= dwc->u1u2;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc->u1u2 = 0;
}
}
static void dwc3_gadget_start_isoc(struct dwc3 *dwc,
struct dwc3_ep *dep, const struct dwc3_event_depevt *event)
{
u32 uf;
if (list_empty(&dep->request_list)) {
dev_vdbg(dwc->dev, "ISOC ep %s run out for requests.\n",
dep->name);
return;
}
if (event->parameters) {
u32 mask;
mask = ~(dep->interval - 1);
uf = event->parameters & mask;
uf += dep->interval * 4;
} else {
uf = 0;
}
__dwc3_gadget_kick_transfer(dep, uf, 1);
}
static void dwc3_process_ep_cmd_complete(struct dwc3_ep *dep,
const struct dwc3_event_depevt *event)
{
struct dwc3 *dwc = dep->dwc;
struct dwc3_event_depevt mod_ev = *event;
mod_ev.status = DEPEVT_STATUS_LST;
dwc3_cleanup_done_reqs(dwc, dep, &mod_ev, -ESHUTDOWN);
dep->flags &= ~DWC3_EP_BUSY;
}
static void dwc3_ep_cmd_compl(struct dwc3_ep *dep,
const struct dwc3_event_depevt *event)
{
u32 param = event->parameters;
u32 cmd_type = (param >> 8) & ((1 << 5) - 1);
switch (cmd_type) {
case DWC3_DEPCMD_ENDTRANSFER:
dwc3_process_ep_cmd_complete(dep, event);
break;
case DWC3_DEPCMD_STARTTRANSFER:
dep->res_trans_idx = param & 0x7f;
break;
default:
printk(KERN_ERR "%s() unknown /unexpected type: %d\n",
__func__, cmd_type);
break;
};
}
static void dwc3_endpoint_interrupt(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep;
u8 epnum = event->endpoint_number;
dep = dwc->eps[epnum];
dev_vdbg(dwc->dev, "%s: %s\n", dep->name,
dwc3_ep_event_string(event->endpoint_event));
if (epnum == 0 || epnum == 1) {
dwc3_ep0_interrupt(dwc, event);
return;
}
switch (event->endpoint_event) {
case DWC3_DEPEVT_XFERCOMPLETE:
if (usb_endpoint_xfer_isoc(dep->desc)) {
dev_dbg(dwc->dev, "%s is an Isochronous endpoint\n",
dep->name);
return;
}
dwc3_endpoint_transfer_complete(dwc, dep, event, 1);
break;
case DWC3_DEPEVT_XFERINPROGRESS:
if (!usb_endpoint_xfer_isoc(dep->desc)) {
dev_dbg(dwc->dev, "%s is not an Isochronous endpoint\n",
dep->name);
return;
}
dwc3_endpoint_transfer_complete(dwc, dep, event, 0);
break;
case DWC3_DEPEVT_XFERNOTREADY:
if (usb_endpoint_xfer_isoc(dep->desc)) {
dwc3_gadget_start_isoc(dwc, dep, event);
} else {
int ret;
dev_vdbg(dwc->dev, "%s: reason %s\n",
dep->name, event->status
? "Transfer Active"
: "Transfer Not Active");
ret = __dwc3_gadget_kick_transfer(dep, 0, 1);
if (!ret || ret == -EBUSY)
return;
dev_dbg(dwc->dev, "%s: failed to kick transfers\n",
dep->name);
}
break;
case DWC3_DEPEVT_STREAMEVT:
if (!usb_endpoint_xfer_bulk(dep->desc)) {
dev_err(dwc->dev, "Stream event for non-Bulk %s\n",
dep->name);
return;
}
switch (event->status) {
case DEPEVT_STREAMEVT_FOUND:
dev_vdbg(dwc->dev, "Stream %d found and started\n",
event->parameters);
break;
case DEPEVT_STREAMEVT_NOTFOUND:
default:
dev_dbg(dwc->dev, "Couldn't find suitable stream\n");
}
break;
case DWC3_DEPEVT_RXTXFIFOEVT:
dev_dbg(dwc->dev, "%s FIFO Overrun\n", dep->name);
break;
case DWC3_DEPEVT_EPCMDCMPLT:
dwc3_ep_cmd_compl(dep, event);
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
static void dwc3_stop_active_transfer(struct dwc3 *dwc, u32 epnum)
{
struct dwc3_ep *dep;
struct dwc3_gadget_ep_cmd_params params;
u32 cmd;
int ret;
dep = dwc->eps[epnum];
WARN_ON(!dep->res_trans_idx);
if (dep->res_trans_idx) {
cmd = DWC3_DEPCMD_ENDTRANSFER;
cmd |= DWC3_DEPCMD_HIPRI_FORCERM | DWC3_DEPCMD_CMDIOC;
cmd |= DWC3_DEPCMD_PARAM(dep->res_trans_idx);
memset(&params, 0, sizeof(params));
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number, cmd, &params);
WARN_ON_ONCE(ret);
dep->res_trans_idx = 0;
}
}
static void dwc3_stop_active_transfers(struct dwc3 *dwc)
{
u32 epnum;
for (epnum = 2; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
struct dwc3_ep *dep;
dep = dwc->eps[epnum];
if (!(dep->flags & DWC3_EP_ENABLED))
continue;
dwc3_remove_requests(dwc, dep);
}
}
static void dwc3_clear_stall_all_ep(struct dwc3 *dwc)
{
u32 epnum;
for (epnum = 1; epnum < DWC3_ENDPOINTS_NUM; epnum++) {
struct dwc3_ep *dep;
struct dwc3_gadget_ep_cmd_params params;
int ret;
dep = dwc->eps[epnum];
if (!(dep->flags & DWC3_EP_STALL))
continue;
dep->flags &= ~DWC3_EP_STALL;
memset(&params, 0, sizeof(params));
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number,
DWC3_DEPCMD_CLEARSTALL, &params);
WARN_ON_ONCE(ret);
}
}
static void dwc3_gadget_disconnect_interrupt(struct dwc3 *dwc)
{
dev_vdbg(dwc->dev, "%s\n", __func__);
#if 0
XXX
U1/U2 is powersave optimization. Skip it for now. Anyway we need to
enable it before we can disable it.
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
#endif
dwc3_stop_active_transfers(dwc);
dwc3_disconnect_gadget(dwc);
dwc->start_config_issued = false;
dwc->gadget.speed = USB_SPEED_UNKNOWN;
dwc->setup_packet_pending = false;
}
static void dwc3_gadget_usb3_phy_power(struct dwc3 *dwc, int on)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_GUSB3PIPECTL(0));
if (on)
reg &= ~DWC3_GUSB3PIPECTL_SUSPHY;
else
reg |= DWC3_GUSB3PIPECTL_SUSPHY;
dwc3_writel(dwc->regs, DWC3_GUSB3PIPECTL(0), reg);
}
static void dwc3_gadget_usb2_phy_power(struct dwc3 *dwc, int on)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
if (on)
reg &= ~DWC3_GUSB2PHYCFG_SUSPHY;
else
reg |= DWC3_GUSB2PHYCFG_SUSPHY;
dwc3_writel(dwc->regs, DWC3_GUSB2PHYCFG(0), reg);
}
static void dwc3_gadget_reset_interrupt(struct dwc3 *dwc)
{
u32 reg;
dev_vdbg(dwc->dev, "%s\n", __func__);
if (dwc->revision < DWC3_REVISION_188A) {
if (dwc->setup_packet_pending)
dwc3_gadget_disconnect_interrupt(dwc);
}
dwc->dev_state = DWC3_DEFAULT_STATE;
dwc3_gadget_usb2_phy_power(dwc, true);
dwc3_gadget_usb3_phy_power(dwc, true);
if (dwc->gadget.speed != USB_SPEED_UNKNOWN)
dwc3_disconnect_gadget(dwc);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_TSTCTRL_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc3_stop_active_transfers(dwc);
dwc3_clear_stall_all_ep(dwc);
dwc->start_config_issued = false;
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg &= ~(DWC3_DCFG_DEVADDR_MASK);
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
}
static void dwc3_update_ram_clk_sel(struct dwc3 *dwc, u32 speed)
{
u32 reg;
u32 usb30_clock = DWC3_GCTL_CLK_BUS;
if (speed != DWC3_DSTS_SUPERSPEED)
return;
if (!usb30_clock)
return;
reg = dwc3_readl(dwc->regs, DWC3_GCTL);
reg |= DWC3_GCTL_RAMCLKSEL(usb30_clock);
dwc3_writel(dwc->regs, DWC3_GCTL, reg);
}
static void dwc3_gadget_disable_phy(struct dwc3 *dwc, u8 speed)
{
switch (speed) {
case USB_SPEED_SUPER:
dwc3_gadget_usb2_phy_power(dwc, false);
break;
case USB_SPEED_HIGH:
case USB_SPEED_FULL:
case USB_SPEED_LOW:
dwc3_gadget_usb3_phy_power(dwc, false);
break;
}
}
static void dwc3_gadget_conndone_interrupt(struct dwc3 *dwc)
{
struct dwc3_gadget_ep_cmd_params params;
struct dwc3_ep *dep;
int ret;
u32 reg;
u8 speed;
dev_vdbg(dwc->dev, "%s\n", __func__);
memset(&params, 0x00, sizeof(params));
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
speed = reg & DWC3_DSTS_CONNECTSPD;
dwc->speed = speed;
dwc3_update_ram_clk_sel(dwc, speed);
switch (speed) {
case DWC3_DCFG_SUPERSPEED:
if (dwc->revision < DWC3_REVISION_190A)
dwc3_gadget_reset_interrupt(dwc);
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dwc->gadget.ep0->maxpacket = 512;
dwc->gadget.speed = USB_SPEED_SUPER;
break;
case DWC3_DCFG_HIGHSPEED:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(64);
dwc->gadget.ep0->maxpacket = 64;
dwc->gadget.speed = USB_SPEED_HIGH;
break;
case DWC3_DCFG_FULLSPEED2:
case DWC3_DCFG_FULLSPEED1:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(64);
dwc->gadget.ep0->maxpacket = 64;
dwc->gadget.speed = USB_SPEED_FULL;
break;
case DWC3_DCFG_LOWSPEED:
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(8);
dwc->gadget.ep0->maxpacket = 8;
dwc->gadget.speed = USB_SPEED_LOW;
break;
}
dwc3_gadget_disable_phy(dwc, dwc->gadget.speed);
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
return;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
return;
}
}
static void dwc3_gadget_wakeup_interrupt(struct dwc3 *dwc)
{
dev_vdbg(dwc->dev, "%s\n", __func__);
dwc->gadget_driver->resume(&dwc->gadget);
}
static void dwc3_gadget_linksts_change_interrupt(struct dwc3 *dwc,
unsigned int evtinfo)
{
enum dwc3_link_state next = evtinfo & DWC3_LINK_STATE_MASK;
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
dwc->link_state = next;
dev_vdbg(dwc->dev, "%s link %d\n", __func__, dwc->link_state);
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
case DWC3_DEVICE_EVENT_LINK_STATUS_CHANGE:
dwc3_gadget_linksts_change_interrupt(dwc, event->event_info);
break;
case DWC3_DEVICE_EVENT_EOPF:
dev_vdbg(dwc->dev, "End of Periodic Frame\n");
break;
case DWC3_DEVICE_EVENT_SOF:
dev_vdbg(dwc->dev, "Start of Periodic Frame\n");
break;
case DWC3_DEVICE_EVENT_ERRATIC_ERROR:
dev_vdbg(dwc->dev, "Erratic Error\n");
break;
case DWC3_DEVICE_EVENT_CMD_CMPL:
dev_vdbg(dwc->dev, "Command Complete\n");
break;
case DWC3_DEVICE_EVENT_OVERFLOW:
dev_vdbg(dwc->dev, "Overflow\n");
break;
default:
dev_dbg(dwc->dev, "UNKNOWN IRQ %d\n", event->type);
}
}
static void dwc3_process_event_entry(struct dwc3 *dwc,
const union dwc3_event *event)
{
if (event->type.is_devspec == 0) {
return dwc3_endpoint_interrupt(dwc, &event->depevt);
}
switch (event->type.type) {
case DWC3_EVENT_TYPE_DEV:
dwc3_gadget_interrupt(dwc, &event->devt);
break;
default:
dev_err(dwc->dev, "UNKNOWN IRQ type %d\n", event->raw);
}
}
static irqreturn_t dwc3_process_event_buf(struct dwc3 *dwc, u32 buf)
{
struct dwc3_event_buffer *evt;
int left;
u32 count;
count = dwc3_readl(dwc->regs, DWC3_GEVNTCOUNT(buf));
count &= DWC3_GEVNTCOUNT_MASK;
if (!count)
return IRQ_NONE;
evt = dwc->ev_buffs[buf];
left = count;
while (left > 0) {
union dwc3_event event;
memcpy(&event.raw, (evt->buf + evt->lpos), sizeof(event.raw));
dwc3_process_event_entry(dwc, &event);
evt->lpos = (evt->lpos + 4) % DWC3_EVENT_BUFFERS_SIZE;
left -= 4;
dwc3_writel(dwc->regs, DWC3_GEVNTCOUNT(buf), 4);
}
return IRQ_HANDLED;
}
static irqreturn_t dwc3_interrupt(int irq, void *_dwc)
{
struct dwc3 *dwc = _dwc;
int i;
irqreturn_t ret = IRQ_NONE;
spin_lock(&dwc->lock);
for (i = 0; i < dwc->num_event_buffers; i++) {
irqreturn_t status;
status = dwc3_process_event_buf(dwc, i);
if (status == IRQ_HANDLED)
ret = status;
}
spin_unlock(&dwc->lock);
return ret;
}
int __devinit dwc3_gadget_init(struct dwc3 *dwc)
{
u32 reg;
int ret;
int irq;
dwc->ctrl_req = dma_alloc_coherent(dwc->dev, sizeof(*dwc->ctrl_req),
&dwc->ctrl_req_addr, GFP_KERNEL);
if (!dwc->ctrl_req) {
dev_err(dwc->dev, "failed to allocate ctrl request\n");
ret = -ENOMEM;
goto err0;
}
dwc->ep0_trb = dma_alloc_coherent(dwc->dev, sizeof(*dwc->ep0_trb),
&dwc->ep0_trb_addr, GFP_KERNEL);
if (!dwc->ep0_trb) {
dev_err(dwc->dev, "failed to allocate ep0 trb\n");
ret = -ENOMEM;
goto err1;
}
dwc->setup_buf = dma_alloc_coherent(dwc->dev,
sizeof(*dwc->setup_buf) * 2,
&dwc->setup_buf_addr, GFP_KERNEL);
if (!dwc->setup_buf) {
dev_err(dwc->dev, "failed to allocate setup buffer\n");
ret = -ENOMEM;
goto err2;
}
dwc->ep0_bounce = dma_alloc_coherent(dwc->dev,
512, &dwc->ep0_bounce_addr, GFP_KERNEL);
if (!dwc->ep0_bounce) {
dev_err(dwc->dev, "failed to allocate ep0 bounce buffer\n");
ret = -ENOMEM;
goto err3;
}
dev_set_name(&dwc->gadget.dev, "gadget");
dwc->gadget.ops = &dwc3_gadget_ops;
dwc->gadget.max_speed = USB_SPEED_SUPER;
dwc->gadget.speed = USB_SPEED_UNKNOWN;
dwc->gadget.dev.parent = dwc->dev;
dwc->gadget.sg_supported = true;
dma_set_coherent_mask(&dwc->gadget.dev, dwc->dev->coherent_dma_mask);
dwc->gadget.dev.dma_parms = dwc->dev->dma_parms;
dwc->gadget.dev.dma_mask = dwc->dev->dma_mask;
dwc->gadget.dev.release = dwc3_gadget_release;
dwc->gadget.name = "dwc3-gadget";
ret = dwc3_gadget_init_endpoints(dwc);
if (ret)
goto err4;
irq = platform_get_irq(to_platform_device(dwc->dev), 0);
ret = request_irq(irq, dwc3_interrupt, IRQF_SHARED,
"dwc3", dwc);
if (ret) {
dev_err(dwc->dev, "failed to request irq #%d --> %d\n",
irq, ret);
goto err5;
}
reg = (DWC3_DEVTEN_VNDRDEVTSTRCVEDEN |
DWC3_DEVTEN_EVNTOVERFLOWEN |
DWC3_DEVTEN_CMDCMPLTEN |
DWC3_DEVTEN_ERRTICERREN |
DWC3_DEVTEN_WKUPEVTEN |
DWC3_DEVTEN_ULSTCNGEN |
DWC3_DEVTEN_CONNECTDONEEN |
DWC3_DEVTEN_USBRSTEN |
DWC3_DEVTEN_DISCONNEVTEN);
dwc3_writel(dwc->regs, DWC3_DEVTEN, reg);
ret = device_register(&dwc->gadget.dev);
if (ret) {
dev_err(dwc->dev, "failed to register gadget device\n");
put_device(&dwc->gadget.dev);
goto err6;
}
ret = usb_add_gadget_udc(dwc->dev, &dwc->gadget);
if (ret) {
dev_err(dwc->dev, "failed to register udc\n");
goto err7;
}
return 0;
err7:
device_unregister(&dwc->gadget.dev);
err6:
dwc3_writel(dwc->regs, DWC3_DEVTEN, 0x00);
free_irq(irq, dwc);
err5:
dwc3_gadget_free_endpoints(dwc);
err4:
dma_free_coherent(dwc->dev, 512, dwc->ep0_bounce,
dwc->ep0_bounce_addr);
err3:
dma_free_coherent(dwc->dev, sizeof(*dwc->setup_buf) * 2,
dwc->setup_buf, dwc->setup_buf_addr);
err2:
dma_free_coherent(dwc->dev, sizeof(*dwc->ep0_trb),
dwc->ep0_trb, dwc->ep0_trb_addr);
err1:
dma_free_coherent(dwc->dev, sizeof(*dwc->ctrl_req),
dwc->ctrl_req, dwc->ctrl_req_addr);
err0:
return ret;
}
void dwc3_gadget_exit(struct dwc3 *dwc)
{
int irq;
usb_del_gadget_udc(&dwc->gadget);
irq = platform_get_irq(to_platform_device(dwc->dev), 0);
dwc3_writel(dwc->regs, DWC3_DEVTEN, 0x00);
free_irq(irq, dwc);
dwc3_gadget_free_endpoints(dwc);
dma_free_coherent(dwc->dev, 512, dwc->ep0_bounce,
dwc->ep0_bounce_addr);
dma_free_coherent(dwc->dev, sizeof(*dwc->setup_buf) * 2,
dwc->setup_buf, dwc->setup_buf_addr);
dma_free_coherent(dwc->dev, sizeof(*dwc->ep0_trb),
dwc->ep0_trb, dwc->ep0_trb_addr);
dma_free_coherent(dwc->dev, sizeof(*dwc->ctrl_req),
dwc->ctrl_req, dwc->ctrl_req_addr);
device_unregister(&dwc->gadget.dev);
}
