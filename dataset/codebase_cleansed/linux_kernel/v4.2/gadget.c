static inline struct s3c_hsotg_req *our_req(struct usb_request *req)
{
return container_of(req, struct s3c_hsotg_req, req);
}
static inline struct s3c_hsotg_ep *our_ep(struct usb_ep *ep)
{
return container_of(ep, struct s3c_hsotg_ep, ep);
}
static inline struct dwc2_hsotg *to_hsotg(struct usb_gadget *gadget)
{
return container_of(gadget, struct dwc2_hsotg, gadget);
}
static inline void __orr32(void __iomem *ptr, u32 val)
{
writel(readl(ptr) | val, ptr);
}
static inline void __bic32(void __iomem *ptr, u32 val)
{
writel(readl(ptr) & ~val, ptr);
}
static inline struct s3c_hsotg_ep *index_to_ep(struct dwc2_hsotg *hsotg,
u32 ep_index, u32 dir_in)
{
if (dir_in)
return hsotg->eps_in[ep_index];
else
return hsotg->eps_out[ep_index];
}
static inline bool using_dma(struct dwc2_hsotg *hsotg)
{
return hsotg->g_using_dma;
}
static void s3c_hsotg_en_gsint(struct dwc2_hsotg *hsotg, u32 ints)
{
u32 gsintmsk = readl(hsotg->regs + GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk | ints;
if (new_gsintmsk != gsintmsk) {
dev_dbg(hsotg->dev, "gsintmsk now 0x%08x\n", new_gsintmsk);
writel(new_gsintmsk, hsotg->regs + GINTMSK);
}
}
static void s3c_hsotg_disable_gsint(struct dwc2_hsotg *hsotg, u32 ints)
{
u32 gsintmsk = readl(hsotg->regs + GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk & ~ints;
if (new_gsintmsk != gsintmsk)
writel(new_gsintmsk, hsotg->regs + GINTMSK);
}
static void s3c_hsotg_ctrl_epint(struct dwc2_hsotg *hsotg,
unsigned int ep, unsigned int dir_in,
unsigned int en)
{
unsigned long flags;
u32 bit = 1 << ep;
u32 daint;
if (!dir_in)
bit <<= 16;
local_irq_save(flags);
daint = readl(hsotg->regs + DAINTMSK);
if (en)
daint |= bit;
else
daint &= ~bit;
writel(daint, hsotg->regs + DAINTMSK);
local_irq_restore(flags);
}
static void s3c_hsotg_init_fifo(struct dwc2_hsotg *hsotg)
{
unsigned int ep;
unsigned int addr;
int timeout;
u32 val;
WARN_ON(hsotg->fifo_map);
hsotg->fifo_map = 0;
writel(hsotg->g_rx_fifo_sz, hsotg->regs + GRXFSIZ);
writel((hsotg->g_rx_fifo_sz << FIFOSIZE_STARTADDR_SHIFT) |
(hsotg->g_np_g_tx_fifo_sz << FIFOSIZE_DEPTH_SHIFT),
hsotg->regs + GNPTXFSIZ);
addr = hsotg->g_rx_fifo_sz + hsotg->g_np_g_tx_fifo_sz;
for (ep = 1; ep < MAX_EPS_CHANNELS; ep++) {
if (!hsotg->g_tx_fifo_sz[ep])
continue;
val = addr;
val |= hsotg->g_tx_fifo_sz[ep] << FIFOSIZE_DEPTH_SHIFT;
WARN_ONCE(addr + hsotg->g_tx_fifo_sz[ep] > hsotg->fifo_mem,
"insufficient fifo memory");
addr += hsotg->g_tx_fifo_sz[ep];
writel(val, hsotg->regs + DPTXFSIZN(ep));
}
writel(GRSTCTL_TXFNUM(0x10) | GRSTCTL_TXFFLSH |
GRSTCTL_RXFFLSH, hsotg->regs + GRSTCTL);
timeout = 100;
while (1) {
val = readl(hsotg->regs + GRSTCTL);
if ((val & (GRSTCTL_TXFFLSH | GRSTCTL_RXFFLSH)) == 0)
break;
if (--timeout == 0) {
dev_err(hsotg->dev,
"%s: timeout flushing fifos (GRSTCTL=%08x)\n",
__func__, val);
break;
}
udelay(1);
}
dev_dbg(hsotg->dev, "FIFOs reset, timeout at %d\n", timeout);
}
static struct usb_request *s3c_hsotg_ep_alloc_request(struct usb_ep *ep,
gfp_t flags)
{
struct s3c_hsotg_req *req;
req = kzalloc(sizeof(struct s3c_hsotg_req), flags);
if (!req)
return NULL;
INIT_LIST_HEAD(&req->queue);
return &req->req;
}
static inline int is_ep_periodic(struct s3c_hsotg_ep *hs_ep)
{
return hs_ep->periodic;
}
static void s3c_hsotg_unmap_dma(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req)
{
struct usb_request *req = &hs_req->req;
if (hs_req->req.length == 0)
return;
usb_gadget_unmap_request(&hsotg->gadget, req, hs_ep->dir_in);
}
static int s3c_hsotg_write_fifo(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req)
{
bool periodic = is_ep_periodic(hs_ep);
u32 gnptxsts = readl(hsotg->regs + GNPTXSTS);
int buf_pos = hs_req->req.actual;
int to_write = hs_ep->size_loaded;
void *data;
int can_write;
int pkt_round;
int max_transfer;
to_write -= (buf_pos - hs_ep->last_load);
if (to_write == 0)
return 0;
if (periodic && !hsotg->dedicated_fifos) {
u32 epsize = readl(hsotg->regs + DIEPTSIZ(hs_ep->index));
int size_left;
int size_done;
size_left = DXEPTSIZ_XFERSIZE_GET(epsize);
if (hs_ep->fifo_load != 0) {
s3c_hsotg_en_gsint(hsotg, GINTSTS_PTXFEMP);
return -ENOSPC;
}
dev_dbg(hsotg->dev, "%s: left=%d, load=%d, fifo=%d, size %d\n",
__func__, size_left,
hs_ep->size_loaded, hs_ep->fifo_load, hs_ep->fifo_size);
size_done = hs_ep->size_loaded - size_left;
can_write = hs_ep->fifo_load - size_done;
dev_dbg(hsotg->dev, "%s: => can_write1=%d\n",
__func__, can_write);
can_write = hs_ep->fifo_size - can_write;
dev_dbg(hsotg->dev, "%s: => can_write2=%d\n",
__func__, can_write);
if (can_write <= 0) {
s3c_hsotg_en_gsint(hsotg, GINTSTS_PTXFEMP);
return -ENOSPC;
}
} else if (hsotg->dedicated_fifos && hs_ep->index != 0) {
can_write = readl(hsotg->regs + DTXFSTS(hs_ep->index));
can_write &= 0xffff;
can_write *= 4;
} else {
if (GNPTXSTS_NP_TXQ_SPC_AVAIL_GET(gnptxsts) == 0) {
dev_dbg(hsotg->dev,
"%s: no queue slots available (0x%08x)\n",
__func__, gnptxsts);
s3c_hsotg_en_gsint(hsotg, GINTSTS_NPTXFEMP);
return -ENOSPC;
}
can_write = GNPTXSTS_NP_TXF_SPC_AVAIL_GET(gnptxsts);
can_write *= 4;
}
max_transfer = hs_ep->ep.maxpacket * hs_ep->mc;
dev_dbg(hsotg->dev, "%s: GNPTXSTS=%08x, can=%d, to=%d, max_transfer %d\n",
__func__, gnptxsts, can_write, to_write, max_transfer);
if (can_write > 512 && !periodic)
can_write = 512;
if (to_write > max_transfer) {
to_write = max_transfer;
if (!hsotg->dedicated_fifos)
s3c_hsotg_en_gsint(hsotg,
periodic ? GINTSTS_PTXFEMP :
GINTSTS_NPTXFEMP);
}
if (to_write > can_write) {
to_write = can_write;
pkt_round = to_write % max_transfer;
if (pkt_round)
to_write -= pkt_round;
if (!hsotg->dedicated_fifos)
s3c_hsotg_en_gsint(hsotg,
periodic ? GINTSTS_PTXFEMP :
GINTSTS_NPTXFEMP);
}
dev_dbg(hsotg->dev, "write %d/%d, can_write %d, done %d\n",
to_write, hs_req->req.length, can_write, buf_pos);
if (to_write <= 0)
return -ENOSPC;
hs_req->req.actual = buf_pos + to_write;
hs_ep->total_data += to_write;
if (periodic)
hs_ep->fifo_load += to_write;
to_write = DIV_ROUND_UP(to_write, 4);
data = hs_req->req.buf + buf_pos;
iowrite32_rep(hsotg->regs + EPFIFO(hs_ep->index), data, to_write);
return (to_write >= can_write) ? -ENOSPC : 0;
}
static unsigned get_ep_limit(struct s3c_hsotg_ep *hs_ep)
{
int index = hs_ep->index;
unsigned maxsize;
unsigned maxpkt;
if (index != 0) {
maxsize = DXEPTSIZ_XFERSIZE_LIMIT + 1;
maxpkt = DXEPTSIZ_PKTCNT_LIMIT + 1;
} else {
maxsize = 64+64;
if (hs_ep->dir_in)
maxpkt = DIEPTSIZ0_PKTCNT_LIMIT + 1;
else
maxpkt = 2;
}
maxpkt--;
maxsize--;
if ((maxpkt * hs_ep->ep.maxpacket) < maxsize)
maxsize = maxpkt * hs_ep->ep.maxpacket;
return maxsize;
}
static void s3c_hsotg_start_req(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req,
bool continuing)
{
struct usb_request *ureq = &hs_req->req;
int index = hs_ep->index;
int dir_in = hs_ep->dir_in;
u32 epctrl_reg;
u32 epsize_reg;
u32 epsize;
u32 ctrl;
unsigned length;
unsigned packets;
unsigned maxreq;
if (index != 0) {
if (hs_ep->req && !continuing) {
dev_err(hsotg->dev, "%s: active request\n", __func__);
WARN_ON(1);
return;
} else if (hs_ep->req != hs_req && continuing) {
dev_err(hsotg->dev,
"%s: continue different req\n", __func__);
WARN_ON(1);
return;
}
}
epctrl_reg = dir_in ? DIEPCTL(index) : DOEPCTL(index);
epsize_reg = dir_in ? DIEPTSIZ(index) : DOEPTSIZ(index);
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x, ep %d, dir %s\n",
__func__, readl(hsotg->regs + epctrl_reg), index,
hs_ep->dir_in ? "in" : "out");
ctrl = readl(hsotg->regs + epctrl_reg);
if (ctrl & DXEPCTL_STALL) {
dev_warn(hsotg->dev, "%s: ep%d is stalled\n", __func__, index);
return;
}
length = ureq->length - ureq->actual;
dev_dbg(hsotg->dev, "ureq->length:%d ureq->actual:%d\n",
ureq->length, ureq->actual);
maxreq = get_ep_limit(hs_ep);
if (length > maxreq) {
int round = maxreq % hs_ep->ep.maxpacket;
dev_dbg(hsotg->dev, "%s: length %d, max-req %d, r %d\n",
__func__, length, maxreq, round);
if (round)
maxreq -= round;
length = maxreq;
}
if (length)
packets = DIV_ROUND_UP(length, hs_ep->ep.maxpacket);
else
packets = 1;
if (hs_ep->isochronous && length > (hs_ep->mc * hs_ep->ep.maxpacket)) {
dev_err(hsotg->dev, "req length > maxpacket*mc\n");
return;
}
if (dir_in && index != 0)
if (hs_ep->isochronous)
epsize = DXEPTSIZ_MC(packets);
else
epsize = DXEPTSIZ_MC(1);
else
epsize = 0;
if (dir_in && ureq->zero && !continuing) {
if ((ureq->length >= hs_ep->ep.maxpacket) &&
!(ureq->length % hs_ep->ep.maxpacket))
hs_ep->send_zlp = 1;
}
epsize |= DXEPTSIZ_PKTCNT(packets);
epsize |= DXEPTSIZ_XFERSIZE(length);
dev_dbg(hsotg->dev, "%s: %d@%d/%d, 0x%08x => 0x%08x\n",
__func__, packets, length, ureq->length, epsize, epsize_reg);
hs_ep->req = hs_req;
writel(epsize, hsotg->regs + epsize_reg);
if (using_dma(hsotg) && !continuing) {
unsigned int dma_reg;
dma_reg = dir_in ? DIEPDMA(index) : DOEPDMA(index);
writel(ureq->dma, hsotg->regs + dma_reg);
dev_dbg(hsotg->dev, "%s: %pad => 0x%08x\n",
__func__, &ureq->dma, dma_reg);
}
ctrl |= DXEPCTL_EPENA;
ctrl |= DXEPCTL_USBACTEP;
dev_dbg(hsotg->dev, "ep0 state:%d\n", hsotg->ep0_state);
if (!(index == 0 && hsotg->ep0_state == DWC2_EP0_SETUP))
ctrl |= DXEPCTL_CNAK;
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x\n", __func__, ctrl);
writel(ctrl, hsotg->regs + epctrl_reg);
hs_ep->size_loaded = length;
hs_ep->last_load = ureq->actual;
if (dir_in && !using_dma(hsotg)) {
hs_ep->fifo_load = 0;
s3c_hsotg_write_fifo(hsotg, hs_ep, hs_req);
}
if (dir_in)
writel(DIEPMSK_INTKNTXFEMPMSK,
hsotg->regs + DIEPINT(index));
if (!(readl(hsotg->regs + epctrl_reg) & DXEPCTL_EPENA))
dev_dbg(hsotg->dev,
"ep%d: failed to become enabled (DXEPCTL=0x%08x)?\n",
index, readl(hsotg->regs + epctrl_reg));
dev_dbg(hsotg->dev, "%s: DXEPCTL=0x%08x\n",
__func__, readl(hsotg->regs + epctrl_reg));
s3c_hsotg_ctrl_epint(hsotg, hs_ep->index, hs_ep->dir_in, 1);
}
static int s3c_hsotg_map_dma(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct usb_request *req)
{
struct s3c_hsotg_req *hs_req = our_req(req);
int ret;
if (hs_req->req.length == 0)
return 0;
ret = usb_gadget_map_request(&hsotg->gadget, req, hs_ep->dir_in);
if (ret)
goto dma_error;
return 0;
dma_error:
dev_err(hsotg->dev, "%s: failed to map buffer %p, %d bytes\n",
__func__, req->buf, req->length);
return -EIO;
}
static int s3c_hsotg_handle_unaligned_buf_start(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep, struct s3c_hsotg_req *hs_req)
{
void *req_buf = hs_req->req.buf;
if (!using_dma(hsotg) || !((long)req_buf & 3))
return 0;
WARN_ON(hs_req->saved_req_buf);
dev_dbg(hsotg->dev, "%s: %s: buf=%p length=%d\n", __func__,
hs_ep->ep.name, req_buf, hs_req->req.length);
hs_req->req.buf = kmalloc(hs_req->req.length, GFP_ATOMIC);
if (!hs_req->req.buf) {
hs_req->req.buf = req_buf;
dev_err(hsotg->dev,
"%s: unable to allocate memory for bounce buffer\n",
__func__);
return -ENOMEM;
}
hs_req->saved_req_buf = req_buf;
if (hs_ep->dir_in)
memcpy(hs_req->req.buf, req_buf, hs_req->req.length);
return 0;
}
static void s3c_hsotg_handle_unaligned_buf_complete(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep, struct s3c_hsotg_req *hs_req)
{
if (!using_dma(hsotg) || !hs_req->saved_req_buf)
return;
dev_dbg(hsotg->dev, "%s: %s: status=%d actual-length=%d\n", __func__,
hs_ep->ep.name, hs_req->req.status, hs_req->req.actual);
if (!hs_ep->dir_in && !hs_req->req.status)
memcpy(hs_req->saved_req_buf, hs_req->req.buf,
hs_req->req.actual);
kfree(hs_req->req.buf);
hs_req->req.buf = hs_req->saved_req_buf;
hs_req->saved_req_buf = NULL;
}
static int s3c_hsotg_ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t gfp_flags)
{
struct s3c_hsotg_req *hs_req = our_req(req);
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hs = hs_ep->parent;
bool first;
int ret;
dev_dbg(hs->dev, "%s: req %p: %d@%p, noi=%d, zero=%d, snok=%d\n",
ep->name, req, req->length, req->buf, req->no_interrupt,
req->zero, req->short_not_ok);
if (hs->lx_state == DWC2_L2) {
dev_dbg(hs->dev, "%s: don't submit request while suspended\n",
__func__);
return -EAGAIN;
}
INIT_LIST_HEAD(&hs_req->queue);
req->actual = 0;
req->status = -EINPROGRESS;
ret = s3c_hsotg_handle_unaligned_buf_start(hs, hs_ep, hs_req);
if (ret)
return ret;
if (using_dma(hs)) {
ret = s3c_hsotg_map_dma(hs, hs_ep, req);
if (ret)
return ret;
}
first = list_empty(&hs_ep->queue);
list_add_tail(&hs_req->queue, &hs_ep->queue);
if (first)
s3c_hsotg_start_req(hs, hs_ep, hs_req, false);
return 0;
}
static int s3c_hsotg_ep_queue_lock(struct usb_ep *ep, struct usb_request *req,
gfp_t gfp_flags)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hs = hs_ep->parent;
unsigned long flags = 0;
int ret = 0;
spin_lock_irqsave(&hs->lock, flags);
ret = s3c_hsotg_ep_queue(ep, req, gfp_flags);
spin_unlock_irqrestore(&hs->lock, flags);
return ret;
}
static void s3c_hsotg_ep_free_request(struct usb_ep *ep,
struct usb_request *req)
{
struct s3c_hsotg_req *hs_req = our_req(req);
kfree(hs_req);
}
static void s3c_hsotg_complete_oursetup(struct usb_ep *ep,
struct usb_request *req)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hsotg = hs_ep->parent;
dev_dbg(hsotg->dev, "%s: ep %p, req %p\n", __func__, ep, req);
s3c_hsotg_ep_free_request(ep, req);
}
static struct s3c_hsotg_ep *ep_from_windex(struct dwc2_hsotg *hsotg,
u32 windex)
{
struct s3c_hsotg_ep *ep;
int dir = (windex & USB_DIR_IN) ? 1 : 0;
int idx = windex & 0x7F;
if (windex >= 0x100)
return NULL;
if (idx > hsotg->num_of_eps)
return NULL;
ep = index_to_ep(hsotg, idx, dir);
if (idx && ep->dir_in != dir)
return NULL;
return ep;
}
int s3c_hsotg_set_test_mode(struct dwc2_hsotg *hsotg, int testmode)
{
int dctl = readl(hsotg->regs + DCTL);
dctl &= ~DCTL_TSTCTL_MASK;
switch (testmode) {
case TEST_J:
case TEST_K:
case TEST_SE0_NAK:
case TEST_PACKET:
case TEST_FORCE_EN:
dctl |= testmode << DCTL_TSTCTL_SHIFT;
break;
default:
return -EINVAL;
}
writel(dctl, hsotg->regs + DCTL);
return 0;
}
static int s3c_hsotg_send_reply(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *ep,
void *buff,
int length)
{
struct usb_request *req;
int ret;
dev_dbg(hsotg->dev, "%s: buff %p, len %d\n", __func__, buff, length);
req = s3c_hsotg_ep_alloc_request(&ep->ep, GFP_ATOMIC);
hsotg->ep0_reply = req;
if (!req) {
dev_warn(hsotg->dev, "%s: cannot alloc req\n", __func__);
return -ENOMEM;
}
req->buf = hsotg->ep0_buff;
req->length = length;
req->zero = 0;
req->complete = s3c_hsotg_complete_oursetup;
if (length)
memcpy(req->buf, buff, length);
ret = s3c_hsotg_ep_queue(&ep->ep, req, GFP_ATOMIC);
if (ret) {
dev_warn(hsotg->dev, "%s: cannot queue req\n", __func__);
return ret;
}
return 0;
}
static int s3c_hsotg_process_req_status(struct dwc2_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = hsotg->eps_out[0];
struct s3c_hsotg_ep *ep;
__le16 reply;
int ret;
dev_dbg(hsotg->dev, "%s: USB_REQ_GET_STATUS\n", __func__);
if (!ep0->dir_in) {
dev_warn(hsotg->dev, "%s: direction out?\n", __func__);
return -EINVAL;
}
switch (ctrl->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_DEVICE:
reply = cpu_to_le16(0);
break;
case USB_RECIP_INTERFACE:
reply = cpu_to_le16(0);
break;
case USB_RECIP_ENDPOINT:
ep = ep_from_windex(hsotg, le16_to_cpu(ctrl->wIndex));
if (!ep)
return -ENOENT;
reply = cpu_to_le16(ep->halted ? 1 : 0);
break;
default:
return 0;
}
if (le16_to_cpu(ctrl->wLength) != 2)
return -EINVAL;
ret = s3c_hsotg_send_reply(hsotg, ep0, &reply, 2);
if (ret) {
dev_err(hsotg->dev, "%s: failed to send reply\n", __func__);
return ret;
}
return 1;
}
static struct s3c_hsotg_req *get_ep_head(struct s3c_hsotg_ep *hs_ep)
{
if (list_empty(&hs_ep->queue))
return NULL;
return list_first_entry(&hs_ep->queue, struct s3c_hsotg_req, queue);
}
static int s3c_hsotg_process_req_feature(struct dwc2_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = hsotg->eps_out[0];
struct s3c_hsotg_req *hs_req;
bool restart;
bool set = (ctrl->bRequest == USB_REQ_SET_FEATURE);
struct s3c_hsotg_ep *ep;
int ret;
bool halted;
u32 recip;
u32 wValue;
u32 wIndex;
dev_dbg(hsotg->dev, "%s: %s_FEATURE\n",
__func__, set ? "SET" : "CLEAR");
wValue = le16_to_cpu(ctrl->wValue);
wIndex = le16_to_cpu(ctrl->wIndex);
recip = ctrl->bRequestType & USB_RECIP_MASK;
switch (recip) {
case USB_RECIP_DEVICE:
switch (wValue) {
case USB_DEVICE_TEST_MODE:
if ((wIndex & 0xff) != 0)
return -EINVAL;
if (!set)
return -EINVAL;
hsotg->test_mode = wIndex >> 8;
ret = s3c_hsotg_send_reply(hsotg, ep0, NULL, 0);
if (ret) {
dev_err(hsotg->dev,
"%s: failed to send reply\n", __func__);
return ret;
}
break;
default:
return -ENOENT;
}
break;
case USB_RECIP_ENDPOINT:
ep = ep_from_windex(hsotg, wIndex);
if (!ep) {
dev_dbg(hsotg->dev, "%s: no endpoint for 0x%04x\n",
__func__, wIndex);
return -ENOENT;
}
switch (wValue) {
case USB_ENDPOINT_HALT:
halted = ep->halted;
s3c_hsotg_ep_sethalt(&ep->ep, set);
ret = s3c_hsotg_send_reply(hsotg, ep0, NULL, 0);
if (ret) {
dev_err(hsotg->dev,
"%s: failed to send reply\n", __func__);
return ret;
}
if (!set && halted) {
if (ep->req) {
hs_req = ep->req;
ep->req = NULL;
list_del_init(&hs_req->queue);
if (hs_req->req.complete) {
spin_unlock(&hsotg->lock);
usb_gadget_giveback_request(
&ep->ep, &hs_req->req);
spin_lock(&hsotg->lock);
}
}
if (!ep->req) {
restart = !list_empty(&ep->queue);
if (restart) {
hs_req = get_ep_head(ep);
s3c_hsotg_start_req(hsotg, ep,
hs_req, false);
}
}
}
break;
default:
return -ENOENT;
}
break;
default:
return -ENOENT;
}
return 1;
}
static void s3c_hsotg_stall_ep0(struct dwc2_hsotg *hsotg)
{
struct s3c_hsotg_ep *ep0 = hsotg->eps_out[0];
u32 reg;
u32 ctrl;
dev_dbg(hsotg->dev, "ep0 stall (dir=%d)\n", ep0->dir_in);
reg = (ep0->dir_in) ? DIEPCTL0 : DOEPCTL0;
ctrl = readl(hsotg->regs + reg);
ctrl |= DXEPCTL_STALL;
ctrl |= DXEPCTL_CNAK;
writel(ctrl, hsotg->regs + reg);
dev_dbg(hsotg->dev,
"written DXEPCTL=0x%08x to %08x (DXEPCTL=0x%08x)\n",
ctrl, reg, readl(hsotg->regs + reg));
s3c_hsotg_enqueue_setup(hsotg);
}
static void s3c_hsotg_process_control(struct dwc2_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = hsotg->eps_out[0];
int ret = 0;
u32 dcfg;
dev_dbg(hsotg->dev, "ctrl Req=%02x, Type=%02x, V=%04x, L=%04x\n",
ctrl->bRequest, ctrl->bRequestType,
ctrl->wValue, ctrl->wLength);
if (ctrl->wLength == 0) {
ep0->dir_in = 1;
hsotg->ep0_state = DWC2_EP0_STATUS_IN;
} else if (ctrl->bRequestType & USB_DIR_IN) {
ep0->dir_in = 1;
hsotg->ep0_state = DWC2_EP0_DATA_IN;
} else {
ep0->dir_in = 0;
hsotg->ep0_state = DWC2_EP0_DATA_OUT;
}
if ((ctrl->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD) {
switch (ctrl->bRequest) {
case USB_REQ_SET_ADDRESS:
hsotg->connected = 1;
dcfg = readl(hsotg->regs + DCFG);
dcfg &= ~DCFG_DEVADDR_MASK;
dcfg |= (le16_to_cpu(ctrl->wValue) <<
DCFG_DEVADDR_SHIFT) & DCFG_DEVADDR_MASK;
writel(dcfg, hsotg->regs + DCFG);
dev_info(hsotg->dev, "new address %d\n", ctrl->wValue);
ret = s3c_hsotg_send_reply(hsotg, ep0, NULL, 0);
return;
case USB_REQ_GET_STATUS:
ret = s3c_hsotg_process_req_status(hsotg, ctrl);
break;
case USB_REQ_CLEAR_FEATURE:
case USB_REQ_SET_FEATURE:
ret = s3c_hsotg_process_req_feature(hsotg, ctrl);
break;
}
}
if (ret == 0 && hsotg->driver) {
spin_unlock(&hsotg->lock);
ret = hsotg->driver->setup(&hsotg->gadget, ctrl);
spin_lock(&hsotg->lock);
if (ret < 0)
dev_dbg(hsotg->dev, "driver->setup() ret %d\n", ret);
}
if (ret < 0)
s3c_hsotg_stall_ep0(hsotg);
}
static void s3c_hsotg_complete_setup(struct usb_ep *ep,
struct usb_request *req)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hsotg = hs_ep->parent;
if (req->status < 0) {
dev_dbg(hsotg->dev, "%s: failed %d\n", __func__, req->status);
return;
}
spin_lock(&hsotg->lock);
if (req->actual == 0)
s3c_hsotg_enqueue_setup(hsotg);
else
s3c_hsotg_process_control(hsotg, req->buf);
spin_unlock(&hsotg->lock);
}
static void s3c_hsotg_enqueue_setup(struct dwc2_hsotg *hsotg)
{
struct usb_request *req = hsotg->ctrl_req;
struct s3c_hsotg_req *hs_req = our_req(req);
int ret;
dev_dbg(hsotg->dev, "%s: queueing setup request\n", __func__);
req->zero = 0;
req->length = 8;
req->buf = hsotg->ctrl_buff;
req->complete = s3c_hsotg_complete_setup;
if (!list_empty(&hs_req->queue)) {
dev_dbg(hsotg->dev, "%s already queued???\n", __func__);
return;
}
hsotg->eps_out[0]->dir_in = 0;
hsotg->eps_out[0]->send_zlp = 0;
hsotg->ep0_state = DWC2_EP0_SETUP;
ret = s3c_hsotg_ep_queue(&hsotg->eps_out[0]->ep, req, GFP_ATOMIC);
if (ret < 0) {
dev_err(hsotg->dev, "%s: failed queue (%d)\n", __func__, ret);
}
}
static void s3c_hsotg_program_zlp(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep)
{
u32 ctrl;
u8 index = hs_ep->index;
u32 epctl_reg = hs_ep->dir_in ? DIEPCTL(index) : DOEPCTL(index);
u32 epsiz_reg = hs_ep->dir_in ? DIEPTSIZ(index) : DOEPTSIZ(index);
if (hs_ep->dir_in)
dev_dbg(hsotg->dev, "Sending zero-length packet on ep%d\n",
index);
else
dev_dbg(hsotg->dev, "Receiving zero-length packet on ep%d\n",
index);
writel(DXEPTSIZ_MC(1) | DXEPTSIZ_PKTCNT(1) |
DXEPTSIZ_XFERSIZE(0), hsotg->regs +
epsiz_reg);
ctrl = readl(hsotg->regs + epctl_reg);
ctrl |= DXEPCTL_CNAK;
ctrl |= DXEPCTL_EPENA;
ctrl |= DXEPCTL_USBACTEP;
writel(ctrl, hsotg->regs + epctl_reg);
}
static void s3c_hsotg_complete_request(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req,
int result)
{
bool restart;
if (!hs_req) {
dev_dbg(hsotg->dev, "%s: nothing to complete?\n", __func__);
return;
}
dev_dbg(hsotg->dev, "complete: ep %p %s, req %p, %d => %p\n",
hs_ep, hs_ep->ep.name, hs_req, result, hs_req->req.complete);
if (hs_req->req.status == -EINPROGRESS)
hs_req->req.status = result;
s3c_hsotg_handle_unaligned_buf_complete(hsotg, hs_ep, hs_req);
hs_ep->req = NULL;
list_del_init(&hs_req->queue);
if (using_dma(hsotg))
s3c_hsotg_unmap_dma(hsotg, hs_ep, hs_req);
if (hs_req->req.complete) {
spin_unlock(&hsotg->lock);
usb_gadget_giveback_request(&hs_ep->ep, &hs_req->req);
spin_lock(&hsotg->lock);
}
if (!hs_ep->req && result >= 0) {
restart = !list_empty(&hs_ep->queue);
if (restart) {
hs_req = get_ep_head(hs_ep);
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, false);
}
}
}
static void s3c_hsotg_rx_data(struct dwc2_hsotg *hsotg, int ep_idx, int size)
{
struct s3c_hsotg_ep *hs_ep = hsotg->eps_out[ep_idx];
struct s3c_hsotg_req *hs_req = hs_ep->req;
void __iomem *fifo = hsotg->regs + EPFIFO(ep_idx);
int to_read;
int max_req;
int read_ptr;
if (!hs_req) {
u32 epctl = readl(hsotg->regs + DOEPCTL(ep_idx));
int ptr;
dev_dbg(hsotg->dev,
"%s: FIFO %d bytes on ep%d but no req (DXEPCTl=0x%08x)\n",
__func__, size, ep_idx, epctl);
for (ptr = 0; ptr < size; ptr += 4)
(void)readl(fifo);
return;
}
to_read = size;
read_ptr = hs_req->req.actual;
max_req = hs_req->req.length - read_ptr;
dev_dbg(hsotg->dev, "%s: read %d/%d, done %d/%d\n",
__func__, to_read, max_req, read_ptr, hs_req->req.length);
if (to_read > max_req) {
WARN_ON_ONCE(1);
}
hs_ep->total_data += to_read;
hs_req->req.actual += to_read;
to_read = DIV_ROUND_UP(to_read, 4);
ioread32_rep(fifo, hs_req->req.buf + read_ptr, to_read);
}
static void s3c_hsotg_ep0_zlp(struct dwc2_hsotg *hsotg, bool dir_in)
{
hsotg->eps_out[0]->dir_in = dir_in;
hsotg->ep0_state = dir_in ? DWC2_EP0_STATUS_IN : DWC2_EP0_STATUS_OUT;
s3c_hsotg_program_zlp(hsotg, hsotg->eps_out[0]);
}
static void s3c_hsotg_handle_outdone(struct dwc2_hsotg *hsotg, int epnum)
{
u32 epsize = readl(hsotg->regs + DOEPTSIZ(epnum));
struct s3c_hsotg_ep *hs_ep = hsotg->eps_out[epnum];
struct s3c_hsotg_req *hs_req = hs_ep->req;
struct usb_request *req = &hs_req->req;
unsigned size_left = DXEPTSIZ_XFERSIZE_GET(epsize);
int result = 0;
if (!hs_req) {
dev_dbg(hsotg->dev, "%s: no request active\n", __func__);
return;
}
if (epnum == 0 && hsotg->ep0_state == DWC2_EP0_STATUS_OUT) {
dev_dbg(hsotg->dev, "zlp packet received\n");
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, 0);
s3c_hsotg_enqueue_setup(hsotg);
return;
}
if (using_dma(hsotg)) {
unsigned size_done;
size_done = hs_ep->size_loaded - size_left;
size_done += hs_ep->last_load;
req->actual = size_done;
}
if (req->actual < req->length && size_left == 0) {
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, true);
return;
}
if (req->actual < req->length && req->short_not_ok) {
dev_dbg(hsotg->dev, "%s: got %d/%d (short not ok) => error\n",
__func__, req->actual, req->length);
}
if (epnum == 0 && hsotg->ep0_state == DWC2_EP0_DATA_OUT) {
s3c_hsotg_ep0_zlp(hsotg, true);
return;
}
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, result);
}
static u32 s3c_hsotg_read_frameno(struct dwc2_hsotg *hsotg)
{
u32 dsts;
dsts = readl(hsotg->regs + DSTS);
dsts &= DSTS_SOFFN_MASK;
dsts >>= DSTS_SOFFN_SHIFT;
return dsts;
}
static void s3c_hsotg_handle_rx(struct dwc2_hsotg *hsotg)
{
u32 grxstsr = readl(hsotg->regs + GRXSTSP);
u32 epnum, status, size;
WARN_ON(using_dma(hsotg));
epnum = grxstsr & GRXSTS_EPNUM_MASK;
status = grxstsr & GRXSTS_PKTSTS_MASK;
size = grxstsr & GRXSTS_BYTECNT_MASK;
size >>= GRXSTS_BYTECNT_SHIFT;
dev_dbg(hsotg->dev, "%s: GRXSTSP=0x%08x (%d@%d)\n",
__func__, grxstsr, size, epnum);
switch ((status & GRXSTS_PKTSTS_MASK) >> GRXSTS_PKTSTS_SHIFT) {
case GRXSTS_PKTSTS_GLOBALOUTNAK:
dev_dbg(hsotg->dev, "GLOBALOUTNAK\n");
break;
case GRXSTS_PKTSTS_OUTDONE:
dev_dbg(hsotg->dev, "OutDone (Frame=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg));
if (!using_dma(hsotg))
s3c_hsotg_handle_outdone(hsotg, epnum);
break;
case GRXSTS_PKTSTS_SETUPDONE:
dev_dbg(hsotg->dev,
"SetupDone (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + DOEPCTL(0)));
if (hsotg->ep0_state == DWC2_EP0_SETUP)
s3c_hsotg_handle_outdone(hsotg, epnum);
break;
case GRXSTS_PKTSTS_OUTRX:
s3c_hsotg_rx_data(hsotg, epnum, size);
break;
case GRXSTS_PKTSTS_SETUPRX:
dev_dbg(hsotg->dev,
"SetupRX (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + DOEPCTL(0)));
WARN_ON(hsotg->ep0_state != DWC2_EP0_SETUP);
s3c_hsotg_rx_data(hsotg, epnum, size);
break;
default:
dev_warn(hsotg->dev, "%s: unknown status %08x\n",
__func__, grxstsr);
s3c_hsotg_dump(hsotg);
break;
}
}
static u32 s3c_hsotg_ep0_mps(unsigned int mps)
{
switch (mps) {
case 64:
return D0EPCTL_MPS_64;
case 32:
return D0EPCTL_MPS_32;
case 16:
return D0EPCTL_MPS_16;
case 8:
return D0EPCTL_MPS_8;
}
WARN_ON(1);
return (u32)-1;
}
static void s3c_hsotg_set_ep_maxpacket(struct dwc2_hsotg *hsotg,
unsigned int ep, unsigned int mps, unsigned int dir_in)
{
struct s3c_hsotg_ep *hs_ep;
void __iomem *regs = hsotg->regs;
u32 mpsval;
u32 mcval;
u32 reg;
hs_ep = index_to_ep(hsotg, ep, dir_in);
if (!hs_ep)
return;
if (ep == 0) {
mpsval = s3c_hsotg_ep0_mps(mps);
if (mpsval > 3)
goto bad_mps;
hs_ep->ep.maxpacket = mps;
hs_ep->mc = 1;
} else {
mpsval = mps & DXEPCTL_MPS_MASK;
if (mpsval > 1024)
goto bad_mps;
mcval = ((mps >> 11) & 0x3) + 1;
hs_ep->mc = mcval;
if (mcval > 3)
goto bad_mps;
hs_ep->ep.maxpacket = mpsval;
}
if (dir_in) {
reg = readl(regs + DIEPCTL(ep));
reg &= ~DXEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + DIEPCTL(ep));
} else {
reg = readl(regs + DOEPCTL(ep));
reg &= ~DXEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + DOEPCTL(ep));
}
return;
bad_mps:
dev_err(hsotg->dev, "ep%d: bad mps of %d\n", ep, mps);
}
static void s3c_hsotg_txfifo_flush(struct dwc2_hsotg *hsotg, unsigned int idx)
{
int timeout;
int val;
writel(GRSTCTL_TXFNUM(idx) | GRSTCTL_TXFFLSH,
hsotg->regs + GRSTCTL);
timeout = 100;
while (1) {
val = readl(hsotg->regs + GRSTCTL);
if ((val & (GRSTCTL_TXFFLSH)) == 0)
break;
if (--timeout == 0) {
dev_err(hsotg->dev,
"%s: timeout flushing fifo (GRSTCTL=%08x)\n",
__func__, val);
break;
}
udelay(1);
}
}
static int s3c_hsotg_trytx(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep)
{
struct s3c_hsotg_req *hs_req = hs_ep->req;
if (!hs_ep->dir_in || !hs_req) {
if (hs_ep->index != 0)
s3c_hsotg_ctrl_epint(hsotg, hs_ep->index,
hs_ep->dir_in, 0);
return 0;
}
if (hs_req->req.actual < hs_req->req.length) {
dev_dbg(hsotg->dev, "trying to write more for ep%d\n",
hs_ep->index);
return s3c_hsotg_write_fifo(hsotg, hs_ep, hs_req);
}
return 0;
}
static void s3c_hsotg_complete_in(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep)
{
struct s3c_hsotg_req *hs_req = hs_ep->req;
u32 epsize = readl(hsotg->regs + DIEPTSIZ(hs_ep->index));
int size_left, size_done;
if (!hs_req) {
dev_dbg(hsotg->dev, "XferCompl but no req\n");
return;
}
if (hs_ep->index == 0 && hsotg->ep0_state == DWC2_EP0_STATUS_IN) {
dev_dbg(hsotg->dev, "zlp packet sent\n");
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, 0);
if (hsotg->test_mode) {
int ret;
ret = s3c_hsotg_set_test_mode(hsotg, hsotg->test_mode);
if (ret < 0) {
dev_dbg(hsotg->dev, "Invalid Test #%d\n",
hsotg->test_mode);
s3c_hsotg_stall_ep0(hsotg);
return;
}
}
s3c_hsotg_enqueue_setup(hsotg);
return;
}
size_left = DXEPTSIZ_XFERSIZE_GET(epsize);
size_done = hs_ep->size_loaded - size_left;
size_done += hs_ep->last_load;
if (hs_req->req.actual != size_done)
dev_dbg(hsotg->dev, "%s: adjusting size done %d => %d\n",
__func__, hs_req->req.actual, size_done);
hs_req->req.actual = size_done;
dev_dbg(hsotg->dev, "req->length:%d req->actual:%d req->zero:%d\n",
hs_req->req.length, hs_req->req.actual, hs_req->req.zero);
if (!size_left && hs_req->req.actual < hs_req->req.length) {
dev_dbg(hsotg->dev, "%s trying more for req...\n", __func__);
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, true);
return;
}
if (hs_ep->send_zlp) {
s3c_hsotg_program_zlp(hsotg, hs_ep);
hs_ep->send_zlp = 0;
return;
}
if (hs_ep->index == 0 && hsotg->ep0_state == DWC2_EP0_DATA_IN) {
s3c_hsotg_ep0_zlp(hsotg, false);
return;
}
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, 0);
}
static void s3c_hsotg_epint(struct dwc2_hsotg *hsotg, unsigned int idx,
int dir_in)
{
struct s3c_hsotg_ep *hs_ep = index_to_ep(hsotg, idx, dir_in);
u32 epint_reg = dir_in ? DIEPINT(idx) : DOEPINT(idx);
u32 epctl_reg = dir_in ? DIEPCTL(idx) : DOEPCTL(idx);
u32 epsiz_reg = dir_in ? DIEPTSIZ(idx) : DOEPTSIZ(idx);
u32 ints;
u32 ctrl;
ints = readl(hsotg->regs + epint_reg);
ctrl = readl(hsotg->regs + epctl_reg);
writel(ints, hsotg->regs + epint_reg);
if (!hs_ep) {
dev_err(hsotg->dev, "%s:Interrupt for unconfigured ep%d(%s)\n",
__func__, idx, dir_in ? "in" : "out");
return;
}
dev_dbg(hsotg->dev, "%s: ep%d(%s) DxEPINT=0x%08x\n",
__func__, idx, dir_in ? "in" : "out", ints);
if (idx == 0 && (ints & (DXEPINT_SETUP | DXEPINT_SETUP_RCVD)))
ints &= ~DXEPINT_XFERCOMPL;
if (ints & DXEPINT_XFERCOMPL) {
if (hs_ep->isochronous && hs_ep->interval == 1) {
if (ctrl & DXEPCTL_EOFRNUM)
ctrl |= DXEPCTL_SETEVENFR;
else
ctrl |= DXEPCTL_SETODDFR;
writel(ctrl, hsotg->regs + epctl_reg);
}
dev_dbg(hsotg->dev,
"%s: XferCompl: DxEPCTL=0x%08x, DXEPTSIZ=%08x\n",
__func__, readl(hsotg->regs + epctl_reg),
readl(hsotg->regs + epsiz_reg));
if (dir_in) {
s3c_hsotg_complete_in(hsotg, hs_ep);
if (idx == 0 && !hs_ep->req)
s3c_hsotg_enqueue_setup(hsotg);
} else if (using_dma(hsotg)) {
s3c_hsotg_handle_outdone(hsotg, idx);
}
}
if (ints & DXEPINT_EPDISBLD) {
dev_dbg(hsotg->dev, "%s: EPDisbld\n", __func__);
if (dir_in) {
int epctl = readl(hsotg->regs + epctl_reg);
s3c_hsotg_txfifo_flush(hsotg, hs_ep->fifo_index);
if ((epctl & DXEPCTL_STALL) &&
(epctl & DXEPCTL_EPTYPE_BULK)) {
int dctl = readl(hsotg->regs + DCTL);
dctl |= DCTL_CGNPINNAK;
writel(dctl, hsotg->regs + DCTL);
}
}
}
if (ints & DXEPINT_AHBERR)
dev_dbg(hsotg->dev, "%s: AHBErr\n", __func__);
if (ints & DXEPINT_SETUP) {
dev_dbg(hsotg->dev, "%s: Setup/Timeout\n", __func__);
if (using_dma(hsotg) && idx == 0) {
if (dir_in)
WARN_ON_ONCE(1);
else
s3c_hsotg_handle_outdone(hsotg, 0);
}
}
if (ints & DXEPINT_BACK2BACKSETUP)
dev_dbg(hsotg->dev, "%s: B2BSetup/INEPNakEff\n", __func__);
if (dir_in && !hs_ep->isochronous) {
if (ints & DIEPMSK_INTKNTXFEMPMSK) {
dev_dbg(hsotg->dev, "%s: ep%d: INTknTXFEmpMsk\n",
__func__, idx);
}
if (ints & DIEPMSK_INTKNEPMISMSK) {
dev_warn(hsotg->dev, "%s: ep%d: INTknEP\n",
__func__, idx);
}
if (hsotg->dedicated_fifos &&
ints & DIEPMSK_TXFIFOEMPTY) {
dev_dbg(hsotg->dev, "%s: ep%d: TxFIFOEmpty\n",
__func__, idx);
if (!using_dma(hsotg))
s3c_hsotg_trytx(hsotg, hs_ep);
}
}
}
static void s3c_hsotg_irq_enumdone(struct dwc2_hsotg *hsotg)
{
u32 dsts = readl(hsotg->regs + DSTS);
int ep0_mps = 0, ep_mps = 8;
dev_dbg(hsotg->dev, "EnumDone (DSTS=0x%08x)\n", dsts);
switch (dsts & DSTS_ENUMSPD_MASK) {
case DSTS_ENUMSPD_FS:
case DSTS_ENUMSPD_FS48:
hsotg->gadget.speed = USB_SPEED_FULL;
ep0_mps = EP0_MPS_LIMIT;
ep_mps = 1023;
break;
case DSTS_ENUMSPD_HS:
hsotg->gadget.speed = USB_SPEED_HIGH;
ep0_mps = EP0_MPS_LIMIT;
ep_mps = 1024;
break;
case DSTS_ENUMSPD_LS:
hsotg->gadget.speed = USB_SPEED_LOW;
break;
}
dev_info(hsotg->dev, "new device is %s\n",
usb_speed_string(hsotg->gadget.speed));
if (ep0_mps) {
int i;
s3c_hsotg_set_ep_maxpacket(hsotg, 0, ep0_mps, 1);
s3c_hsotg_set_ep_maxpacket(hsotg, 0, ep0_mps, 0);
for (i = 1; i < hsotg->num_of_eps; i++) {
if (hsotg->eps_in[i])
s3c_hsotg_set_ep_maxpacket(hsotg, i, ep_mps, 1);
if (hsotg->eps_out[i])
s3c_hsotg_set_ep_maxpacket(hsotg, i, ep_mps, 0);
}
}
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + DIEPCTL0),
readl(hsotg->regs + DOEPCTL0));
}
static void kill_all_requests(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *ep,
int result)
{
struct s3c_hsotg_req *req, *treq;
unsigned size;
ep->req = NULL;
list_for_each_entry_safe(req, treq, &ep->queue, queue)
s3c_hsotg_complete_request(hsotg, ep, req,
result);
if (!hsotg->dedicated_fifos)
return;
size = (readl(hsotg->regs + DTXFSTS(ep->index)) & 0xffff) * 4;
if (size < ep->fifo_size)
s3c_hsotg_txfifo_flush(hsotg, ep->fifo_index);
}
void s3c_hsotg_disconnect(struct dwc2_hsotg *hsotg)
{
unsigned ep;
if (!hsotg->connected)
return;
hsotg->connected = 0;
hsotg->test_mode = 0;
for (ep = 0; ep < hsotg->num_of_eps; ep++) {
if (hsotg->eps_in[ep])
kill_all_requests(hsotg, hsotg->eps_in[ep],
-ESHUTDOWN);
if (hsotg->eps_out[ep])
kill_all_requests(hsotg, hsotg->eps_out[ep],
-ESHUTDOWN);
}
call_gadget(hsotg, disconnect);
}
static void s3c_hsotg_irq_fifoempty(struct dwc2_hsotg *hsotg, bool periodic)
{
struct s3c_hsotg_ep *ep;
int epno, ret;
for (epno = 0; epno < hsotg->num_of_eps; epno++) {
ep = index_to_ep(hsotg, epno, 1);
if (!ep)
continue;
if (!ep->dir_in)
continue;
if ((periodic && !ep->periodic) ||
(!periodic && ep->periodic))
continue;
ret = s3c_hsotg_trytx(hsotg, ep);
if (ret < 0)
break;
}
}
static int s3c_hsotg_corereset(struct dwc2_hsotg *hsotg)
{
int timeout;
u32 grstctl;
dev_dbg(hsotg->dev, "resetting core\n");
writel(GRSTCTL_CSFTRST, hsotg->regs + GRSTCTL);
timeout = 10000;
do {
grstctl = readl(hsotg->regs + GRSTCTL);
} while ((grstctl & GRSTCTL_CSFTRST) && timeout-- > 0);
if (grstctl & GRSTCTL_CSFTRST) {
dev_err(hsotg->dev, "Failed to get CSftRst asserted\n");
return -EINVAL;
}
timeout = 10000;
while (1) {
u32 grstctl = readl(hsotg->regs + GRSTCTL);
if (timeout-- < 0) {
dev_info(hsotg->dev,
"%s: reset failed, GRSTCTL=%08x\n",
__func__, grstctl);
return -ETIMEDOUT;
}
if (!(grstctl & GRSTCTL_AHBIDLE))
continue;
break;
}
dev_dbg(hsotg->dev, "reset successful\n");
return 0;
}
void s3c_hsotg_core_init_disconnected(struct dwc2_hsotg *hsotg,
bool is_usb_reset)
{
u32 val;
if (!is_usb_reset)
s3c_hsotg_corereset(hsotg);
val = (hsotg->phyif == GUSBCFG_PHYIF8) ? 9 : 5;
writel(hsotg->phyif | GUSBCFG_TOUTCAL(7) |
(val << GUSBCFG_USBTRDTIM_SHIFT), hsotg->regs + GUSBCFG);
s3c_hsotg_init_fifo(hsotg);
if (!is_usb_reset)
__orr32(hsotg->regs + DCTL, DCTL_SFTDISCON);
writel(DCFG_EPMISCNT(1) | DCFG_DEVSPD_HS, hsotg->regs + DCFG);
writel(0xffffffff, hsotg->regs + GOTGINT);
writel(0xffffffff, hsotg->regs + GINTSTS);
writel(GINTSTS_ERLYSUSP | GINTSTS_SESSREQINT |
GINTSTS_GOUTNAKEFF | GINTSTS_GINNAKEFF |
GINTSTS_CONIDSTSCHNG | GINTSTS_USBRST |
GINTSTS_RESETDET | GINTSTS_ENUMDONE |
GINTSTS_OTGINT | GINTSTS_USBSUSP |
GINTSTS_WKUPINT,
hsotg->regs + GINTMSK);
if (using_dma(hsotg))
writel(GAHBCFG_GLBL_INTR_EN | GAHBCFG_DMA_EN |
(GAHBCFG_HBSTLEN_INCR4 << GAHBCFG_HBSTLEN_SHIFT),
hsotg->regs + GAHBCFG);
else
writel(((hsotg->dedicated_fifos) ? (GAHBCFG_NP_TXF_EMP_LVL |
GAHBCFG_P_TXF_EMP_LVL) : 0) |
GAHBCFG_GLBL_INTR_EN,
hsotg->regs + GAHBCFG);
writel(((hsotg->dedicated_fifos && !using_dma(hsotg)) ?
DIEPMSK_TXFIFOEMPTY | DIEPMSK_INTKNTXFEMPMSK : 0) |
DIEPMSK_EPDISBLDMSK | DIEPMSK_XFERCOMPLMSK |
DIEPMSK_TIMEOUTMSK | DIEPMSK_AHBERRMSK |
DIEPMSK_INTKNEPMISMSK,
hsotg->regs + DIEPMSK);
writel((using_dma(hsotg) ? (DIEPMSK_XFERCOMPLMSK |
DIEPMSK_TIMEOUTMSK) : 0) |
DOEPMSK_EPDISBLDMSK | DOEPMSK_AHBERRMSK |
DOEPMSK_SETUPMSK,
hsotg->regs + DOEPMSK);
writel(0, hsotg->regs + DAINTMSK);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + DIEPCTL0),
readl(hsotg->regs + DOEPCTL0));
s3c_hsotg_en_gsint(hsotg, GINTSTS_OEPINT | GINTSTS_IEPINT);
if (!using_dma(hsotg))
s3c_hsotg_en_gsint(hsotg, GINTSTS_RXFLVL);
s3c_hsotg_ctrl_epint(hsotg, 0, 0, 1);
s3c_hsotg_ctrl_epint(hsotg, 0, 1, 1);
if (!is_usb_reset) {
__orr32(hsotg->regs + DCTL, DCTL_PWRONPRGDONE);
udelay(10);
__bic32(hsotg->regs + DCTL, DCTL_PWRONPRGDONE);
}
dev_dbg(hsotg->dev, "DCTL=0x%08x\n", readl(hsotg->regs + DCTL));
writel(DXEPTSIZ_MC(1) | DXEPTSIZ_PKTCNT(1) |
DXEPTSIZ_XFERSIZE(8), hsotg->regs + DOEPTSIZ0);
writel(s3c_hsotg_ep0_mps(hsotg->eps_out[0]->ep.maxpacket) |
DXEPCTL_CNAK | DXEPCTL_EPENA |
DXEPCTL_USBACTEP,
hsotg->regs + DOEPCTL0);
writel(s3c_hsotg_ep0_mps(hsotg->eps_out[0]->ep.maxpacket) |
DXEPCTL_USBACTEP, hsotg->regs + DIEPCTL0);
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + DIEPCTL0),
readl(hsotg->regs + DOEPCTL0));
val = DCTL_CGOUTNAK | DCTL_CGNPINNAK;
if (!is_usb_reset)
val |= DCTL_SFTDISCON;
__orr32(hsotg->regs + DCTL, val);
mdelay(3);
hsotg->last_rst = jiffies;
}
static void s3c_hsotg_core_disconnect(struct dwc2_hsotg *hsotg)
{
__orr32(hsotg->regs + DCTL, DCTL_SFTDISCON);
}
void s3c_hsotg_core_connect(struct dwc2_hsotg *hsotg)
{
__bic32(hsotg->regs + DCTL, DCTL_SFTDISCON);
}
static irqreturn_t s3c_hsotg_irq(int irq, void *pw)
{
struct dwc2_hsotg *hsotg = pw;
int retry_count = 8;
u32 gintsts;
u32 gintmsk;
spin_lock(&hsotg->lock);
irq_retry:
gintsts = readl(hsotg->regs + GINTSTS);
gintmsk = readl(hsotg->regs + GINTMSK);
dev_dbg(hsotg->dev, "%s: %08x %08x (%08x) retry %d\n",
__func__, gintsts, gintsts & gintmsk, gintmsk, retry_count);
gintsts &= gintmsk;
if (gintsts & GINTSTS_ENUMDONE) {
writel(GINTSTS_ENUMDONE, hsotg->regs + GINTSTS);
s3c_hsotg_irq_enumdone(hsotg);
}
if (gintsts & (GINTSTS_OEPINT | GINTSTS_IEPINT)) {
u32 daint = readl(hsotg->regs + DAINT);
u32 daintmsk = readl(hsotg->regs + DAINTMSK);
u32 daint_out, daint_in;
int ep;
daint &= daintmsk;
daint_out = daint >> DAINT_OUTEP_SHIFT;
daint_in = daint & ~(daint_out << DAINT_OUTEP_SHIFT);
dev_dbg(hsotg->dev, "%s: daint=%08x\n", __func__, daint);
for (ep = 0; ep < hsotg->num_of_eps && daint_out;
ep++, daint_out >>= 1) {
if (daint_out & 1)
s3c_hsotg_epint(hsotg, ep, 0);
}
for (ep = 0; ep < hsotg->num_of_eps && daint_in;
ep++, daint_in >>= 1) {
if (daint_in & 1)
s3c_hsotg_epint(hsotg, ep, 1);
}
}
if (gintsts & GINTSTS_RESETDET) {
dev_dbg(hsotg->dev, "%s: USBRstDet\n", __func__);
writel(GINTSTS_RESETDET, hsotg->regs + GINTSTS);
if (hsotg->lx_state == DWC2_L2) {
dwc2_exit_hibernation(hsotg, true);
hsotg->lx_state = DWC2_L0;
}
}
if (gintsts & (GINTSTS_USBRST | GINTSTS_RESETDET)) {
u32 usb_status = readl(hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "%s: USBRst\n", __func__);
dev_dbg(hsotg->dev, "GNPTXSTS=%08x\n",
readl(hsotg->regs + GNPTXSTS));
writel(GINTSTS_USBRST, hsotg->regs + GINTSTS);
s3c_hsotg_disconnect(hsotg);
if (usb_status & GOTGCTL_BSESVLD) {
if (time_after(jiffies, hsotg->last_rst +
msecs_to_jiffies(200))) {
kill_all_requests(hsotg, hsotg->eps_out[0],
-ECONNRESET);
hsotg->lx_state = DWC2_L0;
s3c_hsotg_core_init_disconnected(hsotg, true);
}
}
}
if (gintsts & GINTSTS_NPTXFEMP) {
dev_dbg(hsotg->dev, "NPTxFEmp\n");
s3c_hsotg_disable_gsint(hsotg, GINTSTS_NPTXFEMP);
s3c_hsotg_irq_fifoempty(hsotg, false);
}
if (gintsts & GINTSTS_PTXFEMP) {
dev_dbg(hsotg->dev, "PTxFEmp\n");
s3c_hsotg_disable_gsint(hsotg, GINTSTS_PTXFEMP);
s3c_hsotg_irq_fifoempty(hsotg, true);
}
if (gintsts & GINTSTS_RXFLVL) {
s3c_hsotg_handle_rx(hsotg);
}
if (gintsts & GINTSTS_ERLYSUSP) {
dev_dbg(hsotg->dev, "GINTSTS_ErlySusp\n");
writel(GINTSTS_ERLYSUSP, hsotg->regs + GINTSTS);
}
if (gintsts & GINTSTS_GOUTNAKEFF) {
dev_info(hsotg->dev, "GOUTNakEff triggered\n");
writel(DCTL_CGOUTNAK, hsotg->regs + DCTL);
s3c_hsotg_dump(hsotg);
}
if (gintsts & GINTSTS_GINNAKEFF) {
dev_info(hsotg->dev, "GINNakEff triggered\n");
writel(DCTL_CGNPINNAK, hsotg->regs + DCTL);
s3c_hsotg_dump(hsotg);
}
if (gintsts & IRQ_RETRY_MASK && --retry_count > 0)
goto irq_retry;
spin_unlock(&hsotg->lock);
return IRQ_HANDLED;
}
static int s3c_hsotg_ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hsotg = hs_ep->parent;
unsigned long flags;
unsigned int index = hs_ep->index;
u32 epctrl_reg;
u32 epctrl;
u32 mps;
unsigned int dir_in;
unsigned int i, val, size;
int ret = 0;
dev_dbg(hsotg->dev,
"%s: ep %s: a 0x%02x, attr 0x%02x, mps 0x%04x, intr %d\n",
__func__, ep->name, desc->bEndpointAddress, desc->bmAttributes,
desc->wMaxPacketSize, desc->bInterval);
WARN_ON(index == 0);
dir_in = (desc->bEndpointAddress & USB_ENDPOINT_DIR_MASK) ? 1 : 0;
if (dir_in != hs_ep->dir_in) {
dev_err(hsotg->dev, "%s: direction mismatch!\n", __func__);
return -EINVAL;
}
mps = usb_endpoint_maxp(desc);
epctrl_reg = dir_in ? DIEPCTL(index) : DOEPCTL(index);
epctrl = readl(hsotg->regs + epctrl_reg);
dev_dbg(hsotg->dev, "%s: read DxEPCTL=0x%08x from 0x%08x\n",
__func__, epctrl, epctrl_reg);
spin_lock_irqsave(&hsotg->lock, flags);
epctrl &= ~(DXEPCTL_EPTYPE_MASK | DXEPCTL_MPS_MASK);
epctrl |= DXEPCTL_MPS(mps);
epctrl |= DXEPCTL_USBACTEP;
epctrl |= DXEPCTL_SNAK;
s3c_hsotg_set_ep_maxpacket(hsotg, hs_ep->index, mps, dir_in);
hs_ep->isochronous = 0;
hs_ep->periodic = 0;
hs_ep->halted = 0;
hs_ep->interval = desc->bInterval;
if (hs_ep->interval > 1 && hs_ep->mc > 1)
dev_err(hsotg->dev, "MC > 1 when interval is not 1\n");
switch (desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) {
case USB_ENDPOINT_XFER_ISOC:
epctrl |= DXEPCTL_EPTYPE_ISO;
epctrl |= DXEPCTL_SETEVENFR;
hs_ep->isochronous = 1;
if (dir_in)
hs_ep->periodic = 1;
break;
case USB_ENDPOINT_XFER_BULK:
epctrl |= DXEPCTL_EPTYPE_BULK;
break;
case USB_ENDPOINT_XFER_INT:
if (dir_in)
hs_ep->periodic = 1;
epctrl |= DXEPCTL_EPTYPE_INTERRUPT;
break;
case USB_ENDPOINT_XFER_CONTROL:
epctrl |= DXEPCTL_EPTYPE_CONTROL;
break;
}
if (hs_ep->fifo_index) {
size = hs_ep->ep.maxpacket * hs_ep->mc;
if (size > hs_ep->fifo_size) {
hsotg->fifo_map &= ~(1 << hs_ep->fifo_index);
hs_ep->fifo_index = 0;
hs_ep->fifo_size = 0;
}
}
if (dir_in && hsotg->dedicated_fifos && !hs_ep->fifo_index) {
u32 fifo_index = 0;
u32 fifo_size = UINT_MAX;
size = hs_ep->ep.maxpacket*hs_ep->mc;
for (i = 1; i < hsotg->num_of_eps; ++i) {
if (hsotg->fifo_map & (1<<i))
continue;
val = readl(hsotg->regs + DPTXFSIZN(i));
val = (val >> FIFOSIZE_DEPTH_SHIFT)*4;
if (val < size)
continue;
if (val < fifo_size) {
fifo_size = val;
fifo_index = i;
}
}
if (!fifo_index) {
dev_err(hsotg->dev,
"%s: No suitable fifo found\n", __func__);
ret = -ENOMEM;
goto error;
}
hsotg->fifo_map |= 1 << fifo_index;
epctrl |= DXEPCTL_TXFNUM(fifo_index);
hs_ep->fifo_index = fifo_index;
hs_ep->fifo_size = fifo_size;
}
if (index)
epctrl |= DXEPCTL_SETD0PID;
dev_dbg(hsotg->dev, "%s: write DxEPCTL=0x%08x\n",
__func__, epctrl);
writel(epctrl, hsotg->regs + epctrl_reg);
dev_dbg(hsotg->dev, "%s: read DxEPCTL=0x%08x\n",
__func__, readl(hsotg->regs + epctrl_reg));
s3c_hsotg_ctrl_epint(hsotg, index, dir_in, 1);
error:
spin_unlock_irqrestore(&hsotg->lock, flags);
return ret;
}
static int s3c_hsotg_ep_disable(struct usb_ep *ep)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hsotg = hs_ep->parent;
int dir_in = hs_ep->dir_in;
int index = hs_ep->index;
unsigned long flags;
u32 epctrl_reg;
u32 ctrl;
dev_dbg(hsotg->dev, "%s(ep %p)\n", __func__, ep);
if (ep == &hsotg->eps_out[0]->ep) {
dev_err(hsotg->dev, "%s: called for ep0\n", __func__);
return -EINVAL;
}
epctrl_reg = dir_in ? DIEPCTL(index) : DOEPCTL(index);
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->fifo_map &= ~(1<<hs_ep->fifo_index);
hs_ep->fifo_index = 0;
hs_ep->fifo_size = 0;
ctrl = readl(hsotg->regs + epctrl_reg);
ctrl &= ~DXEPCTL_EPENA;
ctrl &= ~DXEPCTL_USBACTEP;
ctrl |= DXEPCTL_SNAK;
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x\n", __func__, ctrl);
writel(ctrl, hsotg->regs + epctrl_reg);
s3c_hsotg_ctrl_epint(hsotg, hs_ep->index, hs_ep->dir_in, 0);
kill_all_requests(hsotg, hs_ep, -ESHUTDOWN);
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
static bool on_list(struct s3c_hsotg_ep *ep, struct s3c_hsotg_req *test)
{
struct s3c_hsotg_req *req, *treq;
list_for_each_entry_safe(req, treq, &ep->queue, queue) {
if (req == test)
return true;
}
return false;
}
static int s3c_hsotg_ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct s3c_hsotg_req *hs_req = our_req(req);
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hs = hs_ep->parent;
unsigned long flags;
dev_dbg(hs->dev, "ep_dequeue(%p,%p)\n", ep, req);
spin_lock_irqsave(&hs->lock, flags);
if (!on_list(hs_ep, hs_req)) {
spin_unlock_irqrestore(&hs->lock, flags);
return -EINVAL;
}
s3c_hsotg_complete_request(hs, hs_ep, hs_req, -ECONNRESET);
spin_unlock_irqrestore(&hs->lock, flags);
return 0;
}
static int s3c_hsotg_ep_sethalt(struct usb_ep *ep, int value)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hs = hs_ep->parent;
int index = hs_ep->index;
u32 epreg;
u32 epctl;
u32 xfertype;
dev_info(hs->dev, "%s(ep %p %s, %d)\n", __func__, ep, ep->name, value);
if (index == 0) {
if (value)
s3c_hsotg_stall_ep0(hs);
else
dev_warn(hs->dev,
"%s: can't clear halt on ep0\n", __func__);
return 0;
}
if (hs_ep->dir_in) {
epreg = DIEPCTL(index);
epctl = readl(hs->regs + epreg);
if (value) {
epctl |= DXEPCTL_STALL + DXEPCTL_SNAK;
if (epctl & DXEPCTL_EPENA)
epctl |= DXEPCTL_EPDIS;
} else {
epctl &= ~DXEPCTL_STALL;
xfertype = epctl & DXEPCTL_EPTYPE_MASK;
if (xfertype == DXEPCTL_EPTYPE_BULK ||
xfertype == DXEPCTL_EPTYPE_INTERRUPT)
epctl |= DXEPCTL_SETD0PID;
}
writel(epctl, hs->regs + epreg);
} else {
epreg = DOEPCTL(index);
epctl = readl(hs->regs + epreg);
if (value)
epctl |= DXEPCTL_STALL;
else {
epctl &= ~DXEPCTL_STALL;
xfertype = epctl & DXEPCTL_EPTYPE_MASK;
if (xfertype == DXEPCTL_EPTYPE_BULK ||
xfertype == DXEPCTL_EPTYPE_INTERRUPT)
epctl |= DXEPCTL_SETD0PID;
}
writel(epctl, hs->regs + epreg);
}
hs_ep->halted = value;
return 0;
}
static int s3c_hsotg_ep_sethalt_lock(struct usb_ep *ep, int value)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct dwc2_hsotg *hs = hs_ep->parent;
unsigned long flags = 0;
int ret = 0;
spin_lock_irqsave(&hs->lock, flags);
ret = s3c_hsotg_ep_sethalt(ep, value);
spin_unlock_irqrestore(&hs->lock, flags);
return ret;
}
static void s3c_hsotg_phy_enable(struct dwc2_hsotg *hsotg)
{
struct platform_device *pdev = to_platform_device(hsotg->dev);
dev_dbg(hsotg->dev, "pdev 0x%p\n", pdev);
if (hsotg->uphy)
usb_phy_init(hsotg->uphy);
else if (hsotg->plat && hsotg->plat->phy_init)
hsotg->plat->phy_init(pdev, hsotg->plat->phy_type);
else {
phy_init(hsotg->phy);
phy_power_on(hsotg->phy);
}
}
static void s3c_hsotg_phy_disable(struct dwc2_hsotg *hsotg)
{
struct platform_device *pdev = to_platform_device(hsotg->dev);
if (hsotg->uphy)
usb_phy_shutdown(hsotg->uphy);
else if (hsotg->plat && hsotg->plat->phy_exit)
hsotg->plat->phy_exit(pdev, hsotg->plat->phy_type);
else {
phy_power_off(hsotg->phy);
phy_exit(hsotg->phy);
}
}
static void s3c_hsotg_init(struct dwc2_hsotg *hsotg)
{
u32 trdtim;
writel(DIEPMSK_TIMEOUTMSK | DIEPMSK_AHBERRMSK |
DIEPMSK_EPDISBLDMSK | DIEPMSK_XFERCOMPLMSK,
hsotg->regs + DIEPMSK);
writel(DOEPMSK_SETUPMSK | DOEPMSK_AHBERRMSK |
DOEPMSK_EPDISBLDMSK | DOEPMSK_XFERCOMPLMSK,
hsotg->regs + DOEPMSK);
writel(0, hsotg->regs + DAINTMSK);
__orr32(hsotg->regs + DCTL, DCTL_SFTDISCON);
dev_dbg(hsotg->dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(hsotg->regs + GRXFSIZ),
readl(hsotg->regs + GNPTXFSIZ));
s3c_hsotg_init_fifo(hsotg);
trdtim = (hsotg->phyif == GUSBCFG_PHYIF8) ? 9 : 5;
writel(hsotg->phyif | GUSBCFG_TOUTCAL(7) |
(trdtim << GUSBCFG_USBTRDTIM_SHIFT),
hsotg->regs + GUSBCFG);
if (using_dma(hsotg))
__orr32(hsotg->regs + GAHBCFG, GAHBCFG_DMA_EN);
}
static int s3c_hsotg_udc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct dwc2_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags;
int ret;
if (!hsotg) {
pr_err("%s: called with no device\n", __func__);
return -ENODEV;
}
if (!driver) {
dev_err(hsotg->dev, "%s: no driver\n", __func__);
return -EINVAL;
}
if (driver->max_speed < USB_SPEED_FULL)
dev_err(hsotg->dev, "%s: bad speed\n", __func__);
if (!driver->setup) {
dev_err(hsotg->dev, "%s: missing entry points\n", __func__);
return -EINVAL;
}
mutex_lock(&hsotg->init_mutex);
WARN_ON(hsotg->driver);
driver->driver.bus = NULL;
hsotg->driver = driver;
hsotg->gadget.dev.of_node = hsotg->dev->of_node;
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
clk_enable(hsotg->clk);
ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(hsotg->dev, "failed to enable supplies: %d\n", ret);
goto err;
}
s3c_hsotg_phy_enable(hsotg);
if (!IS_ERR_OR_NULL(hsotg->uphy))
otg_set_peripheral(hsotg->uphy->otg, &hsotg->gadget);
spin_lock_irqsave(&hsotg->lock, flags);
s3c_hsotg_init(hsotg);
s3c_hsotg_core_init_disconnected(hsotg, false);
hsotg->enabled = 0;
spin_unlock_irqrestore(&hsotg->lock, flags);
dev_info(hsotg->dev, "bound driver %s\n", driver->driver.name);
mutex_unlock(&hsotg->init_mutex);
return 0;
err:
mutex_unlock(&hsotg->init_mutex);
hsotg->driver = NULL;
return ret;
}
static int s3c_hsotg_udc_stop(struct usb_gadget *gadget)
{
struct dwc2_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags = 0;
int ep;
if (!hsotg)
return -ENODEV;
mutex_lock(&hsotg->init_mutex);
for (ep = 1; ep < hsotg->num_of_eps; ep++) {
if (hsotg->eps_in[ep])
s3c_hsotg_ep_disable(&hsotg->eps_in[ep]->ep);
if (hsotg->eps_out[ep])
s3c_hsotg_ep_disable(&hsotg->eps_out[ep]->ep);
}
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->driver = NULL;
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
hsotg->enabled = 0;
spin_unlock_irqrestore(&hsotg->lock, flags);
if (!IS_ERR_OR_NULL(hsotg->uphy))
otg_set_peripheral(hsotg->uphy->otg, NULL);
s3c_hsotg_phy_disable(hsotg);
regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies), hsotg->supplies);
clk_disable(hsotg->clk);
mutex_unlock(&hsotg->init_mutex);
return 0;
}
static int s3c_hsotg_gadget_getframe(struct usb_gadget *gadget)
{
return s3c_hsotg_read_frameno(to_hsotg(gadget));
}
static int s3c_hsotg_pullup(struct usb_gadget *gadget, int is_on)
{
struct dwc2_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags = 0;
dev_dbg(hsotg->dev, "%s: is_on: %d\n", __func__, is_on);
mutex_lock(&hsotg->init_mutex);
spin_lock_irqsave(&hsotg->lock, flags);
if (is_on) {
clk_enable(hsotg->clk);
hsotg->enabled = 1;
s3c_hsotg_core_init_disconnected(hsotg, false);
s3c_hsotg_core_connect(hsotg);
} else {
s3c_hsotg_core_disconnect(hsotg);
s3c_hsotg_disconnect(hsotg);
hsotg->enabled = 0;
clk_disable(hsotg->clk);
}
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
spin_unlock_irqrestore(&hsotg->lock, flags);
mutex_unlock(&hsotg->init_mutex);
return 0;
}
static int s3c_hsotg_vbus_session(struct usb_gadget *gadget, int is_active)
{
struct dwc2_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags;
dev_dbg(hsotg->dev, "%s: is_active: %d\n", __func__, is_active);
spin_lock_irqsave(&hsotg->lock, flags);
if (is_active) {
if (hsotg->lx_state == DWC2_L2) {
dwc2_exit_hibernation(hsotg, false);
hsotg->lx_state = DWC2_L0;
}
kill_all_requests(hsotg, hsotg->eps_out[0], -ECONNRESET);
s3c_hsotg_core_init_disconnected(hsotg, false);
if (hsotg->enabled)
s3c_hsotg_core_connect(hsotg);
} else {
s3c_hsotg_core_disconnect(hsotg);
s3c_hsotg_disconnect(hsotg);
}
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
static int s3c_hsotg_vbus_draw(struct usb_gadget *gadget, unsigned mA)
{
struct dwc2_hsotg *hsotg = to_hsotg(gadget);
if (IS_ERR_OR_NULL(hsotg->uphy))
return -ENOTSUPP;
return usb_phy_set_power(hsotg->uphy, mA);
}
static void s3c_hsotg_initep(struct dwc2_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
int epnum,
bool dir_in)
{
char *dir;
if (epnum == 0)
dir = "";
else if (dir_in)
dir = "in";
else
dir = "out";
hs_ep->dir_in = dir_in;
hs_ep->index = epnum;
snprintf(hs_ep->name, sizeof(hs_ep->name), "ep%d%s", epnum, dir);
INIT_LIST_HEAD(&hs_ep->queue);
INIT_LIST_HEAD(&hs_ep->ep.ep_list);
if (epnum)
list_add_tail(&hs_ep->ep.ep_list, &hsotg->gadget.ep_list);
hs_ep->parent = hsotg;
hs_ep->ep.name = hs_ep->name;
usb_ep_set_maxpacket_limit(&hs_ep->ep, epnum ? 1024 : EP0_MPS_LIMIT);
hs_ep->ep.ops = &s3c_hsotg_ep_ops;
if (using_dma(hsotg)) {
u32 next = DXEPCTL_NEXTEP((epnum + 1) % 15);
if (dir_in)
writel(next, hsotg->regs + DIEPCTL(epnum));
else
writel(next, hsotg->regs + DOEPCTL(epnum));
}
}
static int s3c_hsotg_hw_cfg(struct dwc2_hsotg *hsotg)
{
u32 cfg;
u32 ep_type;
u32 i;
cfg = readl(hsotg->regs + GHWCFG2);
hsotg->num_of_eps = (cfg >> GHWCFG2_NUM_DEV_EP_SHIFT) & 0xF;
hsotg->num_of_eps++;
hsotg->eps_in[0] = devm_kzalloc(hsotg->dev, sizeof(struct s3c_hsotg_ep),
GFP_KERNEL);
if (!hsotg->eps_in[0])
return -ENOMEM;
hsotg->eps_out[0] = hsotg->eps_in[0];
cfg = readl(hsotg->regs + GHWCFG1);
for (i = 1, cfg >>= 2; i < hsotg->num_of_eps; i++, cfg >>= 2) {
ep_type = cfg & 3;
if (!(ep_type & 2)) {
hsotg->eps_in[i] = devm_kzalloc(hsotg->dev,
sizeof(struct s3c_hsotg_ep), GFP_KERNEL);
if (!hsotg->eps_in[i])
return -ENOMEM;
}
if (!(ep_type & 1)) {
hsotg->eps_out[i] = devm_kzalloc(hsotg->dev,
sizeof(struct s3c_hsotg_ep), GFP_KERNEL);
if (!hsotg->eps_out[i])
return -ENOMEM;
}
}
cfg = readl(hsotg->regs + GHWCFG3);
hsotg->fifo_mem = (cfg >> GHWCFG3_DFIFO_DEPTH_SHIFT);
cfg = readl(hsotg->regs + GHWCFG4);
hsotg->dedicated_fifos = (cfg >> GHWCFG4_DED_FIFO_SHIFT) & 1;
dev_info(hsotg->dev, "EPs: %d, %s fifos, %d entries in SPRAM\n",
hsotg->num_of_eps,
hsotg->dedicated_fifos ? "dedicated" : "shared",
hsotg->fifo_mem);
return 0;
}
static void s3c_hsotg_dump(struct dwc2_hsotg *hsotg)
{
#ifdef DEBUG
struct device *dev = hsotg->dev;
void __iomem *regs = hsotg->regs;
u32 val;
int idx;
dev_info(dev, "DCFG=0x%08x, DCTL=0x%08x, DIEPMSK=%08x\n",
readl(regs + DCFG), readl(regs + DCTL),
readl(regs + DIEPMSK));
dev_info(dev, "GAHBCFG=0x%08x, GHWCFG1=0x%08x\n",
readl(regs + GAHBCFG), readl(regs + GHWCFG1));
dev_info(dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(regs + GRXFSIZ), readl(regs + GNPTXFSIZ));
for (idx = 1; idx < hsotg->num_of_eps; idx++) {
val = readl(regs + DPTXFSIZN(idx));
dev_info(dev, "DPTx[%d] FSize=%d, StAddr=0x%08x\n", idx,
val >> FIFOSIZE_DEPTH_SHIFT,
val & FIFOSIZE_STARTADDR_MASK);
}
for (idx = 0; idx < hsotg->num_of_eps; idx++) {
dev_info(dev,
"ep%d-in: EPCTL=0x%08x, SIZ=0x%08x, DMA=0x%08x\n", idx,
readl(regs + DIEPCTL(idx)),
readl(regs + DIEPTSIZ(idx)),
readl(regs + DIEPDMA(idx)));
val = readl(regs + DOEPCTL(idx));
dev_info(dev,
"ep%d-out: EPCTL=0x%08x, SIZ=0x%08x, DMA=0x%08x\n",
idx, readl(regs + DOEPCTL(idx)),
readl(regs + DOEPTSIZ(idx)),
readl(regs + DOEPDMA(idx)));
}
dev_info(dev, "DVBUSDIS=0x%08x, DVBUSPULSE=%08x\n",
readl(regs + DVBUSDIS), readl(regs + DVBUSPULSE));
#endif
}
static void s3c_hsotg_of_probe(struct dwc2_hsotg *hsotg)
{
struct device_node *np = hsotg->dev->of_node;
u32 len = 0;
u32 i = 0;
hsotg->g_using_dma = of_property_read_bool(np, "g-use-dma");
if (!of_find_property(np, "g-tx-fifo-size", &len))
goto rx_fifo;
len /= sizeof(u32);
if (of_property_read_u32_array(np, "g-tx-fifo-size",
&hsotg->g_tx_fifo_sz[1], len))
goto rx_fifo;
len++;
if (len < MAX_EPS_CHANNELS) {
for (i = len; i < MAX_EPS_CHANNELS; i++)
hsotg->g_tx_fifo_sz[i] = 0;
}
rx_fifo:
of_property_read_u32(np, "g-rx-fifo-size", &hsotg->g_rx_fifo_sz);
of_property_read_u32(np, "g-np-tx-fifo-size",
&hsotg->g_np_g_tx_fifo_sz);
}
static inline void s3c_hsotg_of_probe(struct dwc2_hsotg *hsotg) { }
int dwc2_gadget_init(struct dwc2_hsotg *hsotg, int irq)
{
struct device *dev = hsotg->dev;
struct s3c_hsotg_plat *plat = dev->platform_data;
int epnum;
int ret;
int i;
u32 p_tx_fifo[] = DWC2_G_P_LEGACY_TX_FIFO_SIZE;
hsotg->phyif = GUSBCFG_PHYIF16;
s3c_hsotg_of_probe(hsotg);
hsotg->g_rx_fifo_sz = 2048;
hsotg->g_np_g_tx_fifo_sz = 1024;
memcpy(&hsotg->g_tx_fifo_sz[1], p_tx_fifo, sizeof(p_tx_fifo));
s3c_hsotg_of_probe(hsotg);
dev_dbg(dev, "NonPeriodic TXFIFO size: %d\n",
hsotg->g_np_g_tx_fifo_sz);
dev_dbg(dev, "RXFIFO size: %d\n", hsotg->g_rx_fifo_sz);
for (i = 0; i < MAX_EPS_CHANNELS; i++)
dev_dbg(dev, "Periodic TXFIFO%2d size: %d\n", i,
hsotg->g_tx_fifo_sz[i]);
if (IS_ERR_OR_NULL(hsotg->phy) && IS_ERR_OR_NULL(hsotg->uphy)) {
plat = dev_get_platdata(dev);
if (!plat) {
dev_err(dev,
"no platform data or transceiver defined\n");
return -EPROBE_DEFER;
}
hsotg->plat = plat;
} else if (hsotg->phy) {
if (phy_get_bus_width(hsotg->phy) == 8)
hsotg->phyif = GUSBCFG_PHYIF8;
}
hsotg->clk = devm_clk_get(dev, "otg");
if (IS_ERR(hsotg->clk)) {
hsotg->clk = NULL;
dev_dbg(dev, "cannot get otg clock\n");
}
hsotg->gadget.max_speed = USB_SPEED_HIGH;
hsotg->gadget.ops = &s3c_hsotg_gadget_ops;
hsotg->gadget.name = dev_name(dev);
if (hsotg->dr_mode == USB_DR_MODE_OTG)
hsotg->gadget.is_otg = 1;
ret = clk_prepare_enable(hsotg->clk);
if (ret) {
dev_err(dev, "failed to enable otg clk\n");
goto err_clk;
}
for (i = 0; i < ARRAY_SIZE(hsotg->supplies); i++)
hsotg->supplies[i].supply = s3c_hsotg_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(dev, "failed to request supplies: %d\n", ret);
goto err_clk;
}
ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
goto err_clk;
}
s3c_hsotg_phy_enable(hsotg);
__bic32(hsotg->regs + GUSBCFG, GUSBCFG_FORCEHOSTMODE);
__orr32(hsotg->regs + GUSBCFG, GUSBCFG_FORCEDEVMODE);
msleep(25);
s3c_hsotg_corereset(hsotg);
ret = s3c_hsotg_hw_cfg(hsotg);
if (ret) {
dev_err(hsotg->dev, "Hardware configuration failed: %d\n", ret);
goto err_clk;
}
s3c_hsotg_init(hsotg);
__bic32(hsotg->regs + GUSBCFG, GUSBCFG_FORCEDEVMODE);
hsotg->ctrl_buff = devm_kzalloc(hsotg->dev,
DWC2_CTRL_BUFF_SIZE, GFP_KERNEL);
if (!hsotg->ctrl_buff) {
dev_err(dev, "failed to allocate ctrl request buff\n");
ret = -ENOMEM;
goto err_supplies;
}
hsotg->ep0_buff = devm_kzalloc(hsotg->dev,
DWC2_CTRL_BUFF_SIZE, GFP_KERNEL);
if (!hsotg->ep0_buff) {
dev_err(dev, "failed to allocate ctrl reply buff\n");
ret = -ENOMEM;
goto err_supplies;
}
ret = devm_request_irq(hsotg->dev, irq, s3c_hsotg_irq, IRQF_SHARED,
dev_name(hsotg->dev), hsotg);
if (ret < 0) {
s3c_hsotg_phy_disable(hsotg);
clk_disable_unprepare(hsotg->clk);
regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
dev_err(dev, "cannot claim IRQ for gadget\n");
goto err_supplies;
}
if (hsotg->num_of_eps == 0) {
dev_err(dev, "wrong number of EPs (zero)\n");
ret = -EINVAL;
goto err_supplies;
}
INIT_LIST_HEAD(&hsotg->gadget.ep_list);
hsotg->gadget.ep0 = &hsotg->eps_out[0]->ep;
hsotg->ctrl_req = s3c_hsotg_ep_alloc_request(&hsotg->eps_out[0]->ep,
GFP_KERNEL);
if (!hsotg->ctrl_req) {
dev_err(dev, "failed to allocate ctrl req\n");
ret = -ENOMEM;
goto err_supplies;
}
for (epnum = 0; epnum < hsotg->num_of_eps; epnum++) {
if (hsotg->eps_in[epnum])
s3c_hsotg_initep(hsotg, hsotg->eps_in[epnum],
epnum, 1);
if (hsotg->eps_out[epnum])
s3c_hsotg_initep(hsotg, hsotg->eps_out[epnum],
epnum, 0);
}
s3c_hsotg_phy_disable(hsotg);
ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(dev, "failed to disable supplies: %d\n", ret);
goto err_supplies;
}
ret = usb_add_gadget_udc(dev, &hsotg->gadget);
if (ret)
goto err_supplies;
s3c_hsotg_dump(hsotg);
return 0;
err_supplies:
s3c_hsotg_phy_disable(hsotg);
err_clk:
clk_disable_unprepare(hsotg->clk);
return ret;
}
int s3c_hsotg_remove(struct dwc2_hsotg *hsotg)
{
usb_del_gadget_udc(&hsotg->gadget);
clk_disable_unprepare(hsotg->clk);
return 0;
}
int s3c_hsotg_suspend(struct dwc2_hsotg *hsotg)
{
unsigned long flags;
int ret = 0;
if (hsotg->lx_state != DWC2_L0)
return ret;
mutex_lock(&hsotg->init_mutex);
if (hsotg->driver) {
int ep;
dev_info(hsotg->dev, "suspending usb gadget %s\n",
hsotg->driver->driver.name);
spin_lock_irqsave(&hsotg->lock, flags);
if (hsotg->enabled)
s3c_hsotg_core_disconnect(hsotg);
s3c_hsotg_disconnect(hsotg);
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
spin_unlock_irqrestore(&hsotg->lock, flags);
s3c_hsotg_phy_disable(hsotg);
for (ep = 0; ep < hsotg->num_of_eps; ep++) {
if (hsotg->eps_in[ep])
s3c_hsotg_ep_disable(&hsotg->eps_in[ep]->ep);
if (hsotg->eps_out[ep])
s3c_hsotg_ep_disable(&hsotg->eps_out[ep]->ep);
}
ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
clk_disable(hsotg->clk);
}
mutex_unlock(&hsotg->init_mutex);
return ret;
}
int s3c_hsotg_resume(struct dwc2_hsotg *hsotg)
{
unsigned long flags;
int ret = 0;
if (hsotg->lx_state == DWC2_L2)
return ret;
mutex_lock(&hsotg->init_mutex);
if (hsotg->driver) {
dev_info(hsotg->dev, "resuming usb gadget %s\n",
hsotg->driver->driver.name);
clk_enable(hsotg->clk);
ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
s3c_hsotg_phy_enable(hsotg);
spin_lock_irqsave(&hsotg->lock, flags);
s3c_hsotg_core_init_disconnected(hsotg, false);
if (hsotg->enabled)
s3c_hsotg_core_connect(hsotg);
spin_unlock_irqrestore(&hsotg->lock, flags);
}
mutex_unlock(&hsotg->init_mutex);
return ret;
}
