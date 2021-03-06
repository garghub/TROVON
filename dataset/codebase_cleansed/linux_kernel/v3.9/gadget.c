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
dev_vdbg(dwc->dev, "link state change request timed out\n");
return -ETIMEDOUT;
}
int dwc3_gadget_resize_tx_fifos(struct dwc3 *dwc)
{
int last_fifo_depth = 0;
int ram1_depth;
int fifo_size;
int mdwidth;
int num;
if (!dwc->needs_fifo_resize)
return 0;
ram1_depth = DWC3_RAM1_DEPTH(dwc->hwparams.hwparams7);
mdwidth = DWC3_MDWIDTH(dwc->hwparams.hwparams0);
mdwidth >>= 3;
for (num = 0; num < DWC3_ENDPOINTS_NUM; num++) {
struct dwc3_ep *dep = dwc->eps[num];
int fifo_number = dep->number >> 1;
int mult = 1;
int tmp;
if (!(dep->number & 1))
continue;
if (!(dep->flags & DWC3_EP_ENABLED))
continue;
if (usb_endpoint_xfer_bulk(dep->endpoint.desc)
|| usb_endpoint_xfer_isoc(dep->endpoint.desc))
mult = 3;
tmp = mult * (dep->endpoint.maxpacket + mdwidth);
tmp += mdwidth;
fifo_size = DIV_ROUND_UP(tmp, mdwidth);
fifo_size |= (last_fifo_depth << 16);
dev_vdbg(dwc->dev, "%s: Fifo Addr %04x Size %d\n",
dep->name, last_fifo_depth, fifo_size & 0xffff);
dwc3_writel(dwc->regs, DWC3_GTXFIFOSIZ(fifo_number),
fifo_size);
last_fifo_depth += (fifo_size & 0xffff);
}
return 0;
}
void dwc3_gadget_giveback(struct dwc3_ep *dep, struct dwc3_request *req,
int status)
{
struct dwc3 *dwc = dep->dwc;
int i;
if (req->queued) {
i = 0;
do {
dep->busy_slot++;
if (((dep->busy_slot & DWC3_TRB_MASK) ==
DWC3_TRB_NUM- 1) &&
usb_endpoint_xfer_isoc(dep->endpoint.desc))
dep->busy_slot++;
} while(++i < req->request.num_mapped_sgs);
req->queued = false;
}
list_del(&req->list);
req->trb = NULL;
if (req->request.status == -EINPROGRESS)
req->request.status = status;
if (dwc->ep0_bounced && dep->number == 0)
dwc->ep0_bounced = false;
else
usb_gadget_unmap_request(&dwc->gadget, &req->request,
req->direction);
dev_dbg(dwc->dev, "request %p from %s completed %d/%d ===> %d\n",
req, dep->name, req->request.actual,
req->request.length, status);
spin_unlock(&dwc->lock);
req->request.complete(&dep->endpoint, &req->request);
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
case DWC3_DEPCMD_GETEPSTATE:
return "Get Endpoint State";
case DWC3_DEPCMD_SETTRANSFRESOURCE:
return "Set Endpoint Transfer Resource";
case DWC3_DEPCMD_SETEPCONFIG:
return "Set Endpoint Configuration";
default:
return "UNKNOWN command";
}
}
int dwc3_send_gadget_generic_command(struct dwc3 *dwc, int cmd, u32 param)
{
u32 timeout = 500;
u32 reg;
dwc3_writel(dwc->regs, DWC3_DGCMDPAR, param);
dwc3_writel(dwc->regs, DWC3_DGCMD, cmd | DWC3_DGCMD_CMDACT);
do {
reg = dwc3_readl(dwc->regs, DWC3_DGCMD);
if (!(reg & DWC3_DGCMD_CMDACT)) {
dev_vdbg(dwc->dev, "Command Complete --> %d\n",
DWC3_DGCMD_STATUS(reg));
return 0;
}
timeout--;
if (!timeout)
return -ETIMEDOUT;
udelay(1);
} while (1);
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
const struct usb_ss_ep_comp_descriptor *comp_desc,
bool ignore)
{
struct dwc3_gadget_ep_cmd_params params;
memset(&params, 0x00, sizeof(params));
params.param0 = DWC3_DEPCFG_EP_TYPE(usb_endpoint_type(desc))
| DWC3_DEPCFG_MAX_PACKET_SIZE(usb_endpoint_maxp(desc));
if (dwc->gadget.speed == USB_SPEED_SUPER) {
u32 burst = dep->endpoint.maxburst - 1;
params.param0 |= DWC3_DEPCFG_BURST_SIZE(burst);
}
if (ignore)
params.param0 |= DWC3_DEPCFG_IGN_SEQ_NUM;
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
const struct usb_ss_ep_comp_descriptor *comp_desc,
bool ignore)
{
struct dwc3 *dwc = dep->dwc;
u32 reg;
int ret = -ENOMEM;
if (!(dep->flags & DWC3_EP_ENABLED)) {
ret = dwc3_gadget_start_config(dwc, dep);
if (ret)
return ret;
}
ret = dwc3_gadget_set_ep_config(dwc, dep, desc, comp_desc, ignore);
if (ret)
return ret;
if (!(dep->flags & DWC3_EP_ENABLED)) {
struct dwc3_trb *trb_st_hw;
struct dwc3_trb *trb_link;
ret = dwc3_gadget_set_xfer_resource(dwc, dep);
if (ret)
return ret;
dep->endpoint.desc = desc;
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
trb_link = &dep->trb_pool[DWC3_TRB_NUM - 1];
trb_link->bpl = lower_32_bits(dwc3_trb_dma_offset(dep, trb_st_hw));
trb_link->bph = upper_32_bits(dwc3_trb_dma_offset(dep, trb_st_hw));
trb_link->ctrl |= DWC3_TRBCTL_LINK_TRB;
trb_link->ctrl |= DWC3_TRB_CTRL_HWO;
}
return 0;
}
static void dwc3_remove_requests(struct dwc3 *dwc, struct dwc3_ep *dep)
{
struct dwc3_request *req;
if (!list_empty(&dep->req_queued)) {
dwc3_stop_active_transfer(dwc, dep->number);
while (!list_empty(&dep->req_queued)) {
req = next_request(&dep->req_queued);
dwc3_gadget_giveback(dep, req, -ESHUTDOWN);
}
}
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
dep->endpoint.desc = NULL;
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
if (dep->flags & DWC3_EP_ENABLED) {
dev_WARN_ONCE(dwc->dev, true, "%s is already enabled\n",
dep->name);
return 0;
}
switch (usb_endpoint_type(desc)) {
case USB_ENDPOINT_XFER_CONTROL:
strlcat(dep->name, "-control", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_ISOC:
strlcat(dep->name, "-isoc", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_BULK:
strlcat(dep->name, "-bulk", sizeof(dep->name));
break;
case USB_ENDPOINT_XFER_INT:
strlcat(dep->name, "-int", sizeof(dep->name));
break;
default:
dev_err(dwc->dev, "invalid endpoint transfer type\n");
}
dev_vdbg(dwc->dev, "Enabling %s\n", dep->name);
spin_lock_irqsave(&dwc->lock, flags);
ret = __dwc3_gadget_ep_enable(dep, desc, ep->comp_desc, false);
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
unsigned length, unsigned last, unsigned chain, unsigned node)
{
struct dwc3 *dwc = dep->dwc;
struct dwc3_trb *trb;
dev_vdbg(dwc->dev, "%s: req %p dma %08llx length %d%s%s\n",
dep->name, req, (unsigned long long) dma,
length, last ? " last" : "",
chain ? " chain" : "");
if (((dep->free_slot & DWC3_TRB_MASK) == DWC3_TRB_NUM - 1) &&
usb_endpoint_xfer_isoc(dep->endpoint.desc))
dep->free_slot++;
trb = &dep->trb_pool[dep->free_slot & DWC3_TRB_MASK];
if (!req->trb) {
dwc3_gadget_move_request_queued(req);
req->trb = trb;
req->trb_dma = dwc3_trb_dma_offset(dep, trb);
req->start_slot = dep->free_slot & DWC3_TRB_MASK;
}
dep->free_slot++;
trb->size = DWC3_TRB_SIZE_LENGTH(length);
trb->bpl = lower_32_bits(dma);
trb->bph = upper_32_bits(dma);
switch (usb_endpoint_type(dep->endpoint.desc)) {
case USB_ENDPOINT_XFER_CONTROL:
trb->ctrl = DWC3_TRBCTL_CONTROL_SETUP;
break;
case USB_ENDPOINT_XFER_ISOC:
if (!node)
trb->ctrl = DWC3_TRBCTL_ISOCHRONOUS_FIRST;
else
trb->ctrl = DWC3_TRBCTL_ISOCHRONOUS;
if (!req->request.no_interrupt && !chain)
trb->ctrl |= DWC3_TRB_CTRL_IOC;
break;
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
trb->ctrl = DWC3_TRBCTL_NORMAL;
break;
default:
BUG();
}
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
trb->ctrl |= DWC3_TRB_CTRL_ISP_IMI;
trb->ctrl |= DWC3_TRB_CTRL_CSP;
} else if (last) {
trb->ctrl |= DWC3_TRB_CTRL_LST;
}
if (chain)
trb->ctrl |= DWC3_TRB_CTRL_CHN;
if (usb_endpoint_xfer_bulk(dep->endpoint.desc) && dep->stream_capable)
trb->ctrl |= DWC3_TRB_CTRL_SID_SOFN(req->request.stream_id);
trb->ctrl |= DWC3_TRB_CTRL_HWO;
}
static void dwc3_prepare_trbs(struct dwc3_ep *dep, bool starting)
{
struct dwc3_request *req, *n;
u32 trbs_left;
u32 max;
unsigned int last_one = 0;
BUILD_BUG_ON_NOT_POWER_OF_2(DWC3_TRB_NUM);
trbs_left = (dep->busy_slot - dep->free_slot) & DWC3_TRB_MASK;
if (!usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
max = DWC3_TRB_NUM - (dep->free_slot & DWC3_TRB_MASK);
if (trbs_left > max)
trbs_left = max;
}
if (!trbs_left) {
if (!starting)
return;
trbs_left = DWC3_TRB_NUM;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dep->busy_slot = 1;
dep->free_slot = 1;
} else {
dep->busy_slot = 0;
dep->free_slot = 0;
}
}
if ((trbs_left <= 1) && usb_endpoint_xfer_isoc(dep->endpoint.desc))
return;
list_for_each_entry_safe(req, n, &dep->request_list, list) {
unsigned length;
dma_addr_t dma;
last_one = false;
if (req->request.num_mapped_sgs > 0) {
struct usb_request *request = &req->request;
struct scatterlist *sg = request->sg;
struct scatterlist *s;
int i;
for_each_sg(sg, s, request->num_mapped_sgs, i) {
unsigned chain = true;
length = sg_dma_len(s);
dma = sg_dma_address(s);
if (i == (request->num_mapped_sgs - 1) ||
sg_is_last(s)) {
if (list_is_last(&req->list,
&dep->request_list))
last_one = true;
chain = false;
}
trbs_left--;
if (!trbs_left)
last_one = true;
if (last_one)
chain = false;
dwc3_prepare_one_trb(dep, req, dma, length,
last_one, chain, i);
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
last_one, false, 0);
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
if (start_new) {
params.param0 = upper_32_bits(req->trb_dma);
params.param1 = lower_32_bits(req->trb_dma);
cmd = DWC3_DEPCMD_STARTTRANSFER;
} else {
cmd = DWC3_DEPCMD_UPDATETRANSFER;
}
cmd |= DWC3_DEPCMD_PARAM(cmd_param);
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number, cmd, &params);
if (ret < 0) {
dev_dbg(dwc->dev, "failed to send STARTTRANSFER command\n");
usb_gadget_unmap_request(&dwc->gadget, &req->request,
req->direction);
list_del(&req->list);
return ret;
}
dep->flags |= DWC3_EP_BUSY;
if (start_new) {
dep->resource_index = dwc3_gadget_ep_get_transfer_index(dwc,
dep->number);
WARN_ON_ONCE(!dep->resource_index);
}
return 0;
}
static void __dwc3_gadget_start_isoc(struct dwc3 *dwc,
struct dwc3_ep *dep, u32 cur_uf)
{
u32 uf;
if (list_empty(&dep->request_list)) {
dev_vdbg(dwc->dev, "ISOC ep %s run out for requests.\n",
dep->name);
dep->flags |= DWC3_EP_PENDING_REQUEST;
return;
}
uf = cur_uf + dep->interval * 4;
__dwc3_gadget_kick_transfer(dep, uf, 1);
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
int ret;
req->request.actual = 0;
req->request.status = -EINPROGRESS;
req->direction = dep->direction;
req->epnum = dep->number;
ret = usb_gadget_map_request(&dwc->gadget, &req->request,
dep->direction);
if (ret)
return ret;
list_add_tail(&req->list, &dep->request_list);
if (dep->flags & DWC3_EP_PENDING_REQUEST) {
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
if (list_empty(&dep->req_queued)) {
dwc3_stop_active_transfer(dwc, dep->number);
dep->flags = DWC3_EP_ENABLED;
}
return 0;
}
ret = __dwc3_gadget_kick_transfer(dep, 0, true);
if (ret && ret != -EBUSY)
dev_dbg(dwc->dev, "%s: failed to kick transfers\n",
dep->name);
return ret;
}
if (usb_endpoint_xfer_isoc(dep->endpoint.desc) &&
(dep->flags & DWC3_EP_BUSY) &&
!(dep->flags & DWC3_EP_MISSED_ISOC)) {
WARN_ON_ONCE(!dep->resource_index);
ret = __dwc3_gadget_kick_transfer(dep, dep->resource_index,
false);
if (ret && ret != -EBUSY)
dev_dbg(dwc->dev, "%s: failed to kick transfers\n",
dep->name);
return ret;
}
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
if (!dep->endpoint.desc) {
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
goto out1;
}
dev_err(dwc->dev, "request %p was not queued to %s\n",
request, ep->name);
ret = -EINVAL;
goto out0;
}
out1:
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
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
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
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
dep->flags |= DWC3_EP_WEDGE;
spin_unlock_irqrestore(&dwc->lock, flags);
if (dep->number == 0 || dep->number == 1)
return dwc3_gadget_ep0_set_halt(ep, 1);
else
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
ret = dwc3_gadget_set_link_state(dwc, DWC3_LINK_STATE_RECOV);
if (ret < 0) {
dev_err(dwc->dev, "failed to put link in Recovery\n");
goto out;
}
if (dwc->revision < DWC3_REVISION_194A) {
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_ULSTCHNGREQ_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
}
timeout = jiffies + msecs_to_jiffies(100);
while (!time_after(jiffies, timeout)) {
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
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
dwc->is_selfpowered = !!is_selfpowered;
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_gadget_run_stop(struct dwc3 *dwc, int is_on)
{
u32 reg;
u32 timeout = 500;
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
if (is_on) {
if (dwc->revision <= DWC3_REVISION_187A) {
reg &= ~DWC3_DCTL_TRGTULST_MASK;
reg |= DWC3_DCTL_TRGTULST_RX_DET;
}
if (dwc->revision >= DWC3_REVISION_194A)
reg &= ~DWC3_DCTL_KEEP_CONNECT;
reg |= DWC3_DCTL_RUN_STOP;
} else {
reg &= ~DWC3_DCTL_RUN_STOP;
}
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
return -ETIMEDOUT;
udelay(1);
} while (1);
dev_vdbg(dwc->dev, "gadget %s data soft-%s\n",
dwc->gadget_driver
? dwc->gadget_driver->function : "no-function",
is_on ? "connect" : "disconnect");
return 0;
}
static int dwc3_gadget_pullup(struct usb_gadget *g, int is_on)
{
struct dwc3 *dwc = gadget_to_dwc(g);
unsigned long flags;
int ret;
is_on = !!is_on;
spin_lock_irqsave(&dwc->lock, flags);
ret = dwc3_gadget_run_stop(dwc, is_on);
spin_unlock_irqrestore(&dwc->lock, flags);
return ret;
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
if (dwc->revision < DWC3_REVISION_220A)
reg |= DWC3_DCFG_SUPERSPEED;
else
reg |= dwc->maximum_speed;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
dwc->start_config_issued = false;
dwc3_gadget_ep0_desc.wMaxPacketSize = cpu_to_le16(512);
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL, false);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
goto err0;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL, false);
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
static int dwc3_gadget_init_endpoints(struct dwc3 *dwc)
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
dep->endpoint.maxburst = 1;
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
static int __dwc3_cleanup_done_trbs(struct dwc3 *dwc, struct dwc3_ep *dep,
struct dwc3_request *req, struct dwc3_trb *trb,
const struct dwc3_event_depevt *event, int status)
{
unsigned int count;
unsigned int s_pkt = 0;
unsigned int trb_status;
if ((trb->ctrl & DWC3_TRB_CTRL_HWO) && status != -ESHUTDOWN)
dev_err(dwc->dev, "%s's TRB (%p) still owned by HW\n",
dep->name, trb);
count = trb->size & DWC3_TRB_SIZE_MASK;
if (dep->direction) {
if (count) {
trb_status = DWC3_TRB_SIZE_TRBSTS(trb->size);
if (trb_status == DWC3_TRBSTS_MISSED_ISOC) {
dev_dbg(dwc->dev, "incomplete IN transfer %s\n",
dep->name);
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
req->request.actual += req->request.length - count;
if (s_pkt)
return 1;
if ((event->status & DEPEVT_STATUS_LST) &&
(trb->ctrl & (DWC3_TRB_CTRL_LST |
DWC3_TRB_CTRL_HWO)))
return 1;
if ((event->status & DEPEVT_STATUS_IOC) &&
(trb->ctrl & DWC3_TRB_CTRL_IOC))
return 1;
return 0;
}
static int dwc3_cleanup_done_reqs(struct dwc3 *dwc, struct dwc3_ep *dep,
const struct dwc3_event_depevt *event, int status)
{
struct dwc3_request *req;
struct dwc3_trb *trb;
unsigned int slot;
unsigned int i;
int ret;
do {
req = next_request(&dep->req_queued);
if (!req) {
WARN_ON_ONCE(1);
return 1;
}
i = 0;
do {
slot = req->start_slot + i;
if ((slot == DWC3_TRB_NUM - 1) &&
usb_endpoint_xfer_isoc(dep->endpoint.desc))
slot++;
slot %= DWC3_TRB_NUM;
trb = &dep->trb_pool[slot];
ret = __dwc3_cleanup_done_trbs(dwc, dep, req, trb,
event, status);
if (ret)
break;
}while (++i < req->request.num_mapped_sgs);
dwc3_gadget_giveback(dep, req, status);
if (ret)
break;
} while (1);
if (usb_endpoint_xfer_isoc(dep->endpoint.desc) &&
list_empty(&dep->req_queued)) {
if (list_empty(&dep->request_list)) {
dep->flags = DWC3_EP_PENDING_REQUEST;
} else {
dwc3_stop_active_transfer(dwc, dep->number);
dep->flags = DWC3_EP_ENABLED;
}
return 1;
}
if ((event->status & DEPEVT_STATUS_IOC) &&
(trb->ctrl & DWC3_TRB_CTRL_IOC))
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
if (clean_busy)
dep->flags &= ~DWC3_EP_BUSY;
if (dwc->revision < DWC3_REVISION_183A) {
u32 reg;
int i;
for (i = 0; i < DWC3_ENDPOINTS_NUM; i++) {
dep = dwc->eps[i];
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
static void dwc3_endpoint_interrupt(struct dwc3 *dwc,
const struct dwc3_event_depevt *event)
{
struct dwc3_ep *dep;
u8 epnum = event->endpoint_number;
dep = dwc->eps[epnum];
if (!(dep->flags & DWC3_EP_ENABLED))
return;
dev_vdbg(dwc->dev, "%s: %s\n", dep->name,
dwc3_ep_event_string(event->endpoint_event));
if (epnum == 0 || epnum == 1) {
dwc3_ep0_interrupt(dwc, event);
return;
}
switch (event->endpoint_event) {
case DWC3_DEPEVT_XFERCOMPLETE:
dep->resource_index = 0;
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dev_dbg(dwc->dev, "%s is an Isochronous endpoint\n",
dep->name);
return;
}
dwc3_endpoint_transfer_complete(dwc, dep, event, 1);
break;
case DWC3_DEPEVT_XFERINPROGRESS:
if (!usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dev_dbg(dwc->dev, "%s is not an Isochronous endpoint\n",
dep->name);
return;
}
dwc3_endpoint_transfer_complete(dwc, dep, event, 0);
break;
case DWC3_DEPEVT_XFERNOTREADY:
if (usb_endpoint_xfer_isoc(dep->endpoint.desc)) {
dwc3_gadget_start_isoc(dwc, dep, event);
} else {
int ret;
dev_vdbg(dwc->dev, "%s: reason %s\n",
dep->name, event->status &
DEPEVT_STATUS_TRANSFER_ACTIVE
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
if (!usb_endpoint_xfer_bulk(dep->endpoint.desc)) {
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
dev_vdbg(dwc->dev, "Endpoint Command Complete\n");
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
if (!dep->resource_index)
return;
cmd = DWC3_DEPCMD_ENDTRANSFER;
cmd |= DWC3_DEPCMD_HIPRI_FORCERM | DWC3_DEPCMD_CMDIOC;
cmd |= DWC3_DEPCMD_PARAM(dep->resource_index);
memset(&params, 0, sizeof(params));
ret = dwc3_send_gadget_ep_cmd(dwc, dep->number, cmd, &params);
WARN_ON_ONCE(ret);
dep->resource_index = 0;
dep->flags &= ~DWC3_EP_BUSY;
udelay(100);
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
int reg;
dev_vdbg(dwc->dev, "%s\n", __func__);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc3_disconnect_gadget(dwc);
dwc->start_config_issued = false;
dwc->gadget.speed = USB_SPEED_UNKNOWN;
dwc->setup_packet_pending = false;
}
static void dwc3_gadget_usb3_phy_suspend(struct dwc3 *dwc, int suspend)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_GUSB3PIPECTL(0));
if (suspend)
reg |= DWC3_GUSB3PIPECTL_SUSPHY;
else
reg &= ~DWC3_GUSB3PIPECTL_SUSPHY;
dwc3_writel(dwc->regs, DWC3_GUSB3PIPECTL(0), reg);
}
static void dwc3_gadget_usb2_phy_suspend(struct dwc3 *dwc, int suspend)
{
u32 reg;
reg = dwc3_readl(dwc->regs, DWC3_GUSB2PHYCFG(0));
if (suspend)
reg |= DWC3_GUSB2PHYCFG_SUSPHY;
else
reg &= ~DWC3_GUSB2PHYCFG_SUSPHY;
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
if (dwc->revision < DWC3_REVISION_194A) {
dwc3_gadget_usb2_phy_suspend(dwc, false);
dwc3_gadget_usb3_phy_suspend(dwc, false);
}
if (dwc->gadget.speed != USB_SPEED_UNKNOWN)
dwc3_disconnect_gadget(dwc);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_TSTCTRL_MASK;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
dwc->test_mode = false;
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
static void dwc3_gadget_phy_suspend(struct dwc3 *dwc, u8 speed)
{
switch (speed) {
case USB_SPEED_SUPER:
dwc3_gadget_usb2_phy_suspend(dwc, true);
break;
case USB_SPEED_HIGH:
case USB_SPEED_FULL:
case USB_SPEED_LOW:
dwc3_gadget_usb3_phy_suspend(dwc, true);
break;
}
}
static void dwc3_gadget_conndone_interrupt(struct dwc3 *dwc)
{
struct dwc3_ep *dep;
int ret;
u32 reg;
u8 speed;
dev_vdbg(dwc->dev, "%s\n", __func__);
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
if ((dwc->revision > DWC3_REVISION_194A)
&& (speed != DWC3_DCFG_SUPERSPEED)) {
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg |= DWC3_DCFG_LPM_CAP;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~(DWC3_DCTL_HIRD_THRES_MASK | DWC3_DCTL_L1_HIBER_EN);
reg |= DWC3_DCTL_HIRD_THRES(12);
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
}
if (dwc->revision < DWC3_REVISION_194A) {
dwc3_gadget_phy_suspend(dwc, dwc->gadget.speed);
}
dep = dwc->eps[0];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL, true);
if (ret) {
dev_err(dwc->dev, "failed to enable %s\n", dep->name);
return;
}
dep = dwc->eps[1];
ret = __dwc3_gadget_ep_enable(dep, &dwc3_gadget_ep0_desc, NULL, true);
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
event.raw = *(u32 *) (evt->buf + evt->lpos);
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
int dwc3_gadget_init(struct dwc3 *dwc)
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
dwc->setup_buf = kzalloc(DWC3_EP0_BOUNCE_SIZE, GFP_KERNEL);
if (!dwc->setup_buf) {
dev_err(dwc->dev, "failed to allocate setup buffer\n");
ret = -ENOMEM;
goto err2;
}
dwc->ep0_bounce = dma_alloc_coherent(dwc->dev,
DWC3_EP0_BOUNCE_SIZE, &dwc->ep0_bounce_addr,
GFP_KERNEL);
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
reg = dwc3_readl(dwc->regs, DWC3_DCFG);
reg |= DWC3_DCFG_LPM_CAP;
dwc3_writel(dwc->regs, DWC3_DCFG, reg);
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
if (dwc->revision >= DWC3_REVISION_194A) {
dwc3_gadget_usb2_phy_suspend(dwc, false);
dwc3_gadget_usb3_phy_suspend(dwc, false);
}
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
dma_free_coherent(dwc->dev, DWC3_EP0_BOUNCE_SIZE,
dwc->ep0_bounce, dwc->ep0_bounce_addr);
err3:
kfree(dwc->setup_buf);
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
dma_free_coherent(dwc->dev, DWC3_EP0_BOUNCE_SIZE,
dwc->ep0_bounce, dwc->ep0_bounce_addr);
kfree(dwc->setup_buf);
dma_free_coherent(dwc->dev, sizeof(*dwc->ep0_trb),
dwc->ep0_trb, dwc->ep0_trb_addr);
dma_free_coherent(dwc->dev, sizeof(*dwc->ctrl_req),
dwc->ctrl_req, dwc->ctrl_req_addr);
device_unregister(&dwc->gadget.dev);
}
