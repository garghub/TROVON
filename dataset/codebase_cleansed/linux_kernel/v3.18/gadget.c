static inline struct s3c_hsotg_req *our_req(struct usb_request *req)
{
return container_of(req, struct s3c_hsotg_req, req);
}
static inline struct s3c_hsotg_ep *our_ep(struct usb_ep *ep)
{
return container_of(ep, struct s3c_hsotg_ep, ep);
}
static inline struct s3c_hsotg *to_hsotg(struct usb_gadget *gadget)
{
return container_of(gadget, struct s3c_hsotg, gadget);
}
static inline void __orr32(void __iomem *ptr, u32 val)
{
writel(readl(ptr) | val, ptr);
}
static inline void __bic32(void __iomem *ptr, u32 val)
{
writel(readl(ptr) & ~val, ptr);
}
static inline bool using_dma(struct s3c_hsotg *hsotg)
{
return false;
}
static void s3c_hsotg_en_gsint(struct s3c_hsotg *hsotg, u32 ints)
{
u32 gsintmsk = readl(hsotg->regs + GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk | ints;
if (new_gsintmsk != gsintmsk) {
dev_dbg(hsotg->dev, "gsintmsk now 0x%08x\n", new_gsintmsk);
writel(new_gsintmsk, hsotg->regs + GINTMSK);
}
}
static void s3c_hsotg_disable_gsint(struct s3c_hsotg *hsotg, u32 ints)
{
u32 gsintmsk = readl(hsotg->regs + GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk & ~ints;
if (new_gsintmsk != gsintmsk)
writel(new_gsintmsk, hsotg->regs + GINTMSK);
}
static void s3c_hsotg_ctrl_epint(struct s3c_hsotg *hsotg,
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
static void s3c_hsotg_init_fifo(struct s3c_hsotg *hsotg)
{
unsigned int ep;
unsigned int addr;
unsigned int size;
int timeout;
u32 val;
writel(2048, hsotg->regs + GRXFSIZ);
writel((2048 << FIFOSIZE_STARTADDR_SHIFT) |
(1024 << FIFOSIZE_DEPTH_SHIFT), hsotg->regs + GNPTXFSIZ);
addr = 2048 + 1024;
size = 256;
for (ep = 1; ep <= 4; ep++) {
val = addr;
val |= size << FIFOSIZE_DEPTH_SHIFT;
WARN_ONCE(addr + size > hsotg->fifo_mem,
"insufficient fifo memory");
addr += size;
writel(val, hsotg->regs + DPTXFSIZN(ep));
}
size = 768;
for (ep = 5; ep <= 8; ep++) {
val = addr;
val |= size << FIFOSIZE_DEPTH_SHIFT;
WARN_ONCE(addr + size > hsotg->fifo_mem,
"insufficient fifo memory");
addr += size;
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
static void s3c_hsotg_unmap_dma(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req)
{
struct usb_request *req = &hs_req->req;
if (hs_req->req.length == 0)
return;
usb_gadget_unmap_request(&hsotg->gadget, req, hs_ep->dir_in);
}
static int s3c_hsotg_write_fifo(struct s3c_hsotg *hsotg,
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
static void s3c_hsotg_start_req(struct s3c_hsotg *hsotg,
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
if (0)
dev_dbg(hsotg->dev,
"REQ buf %p len %d dma %pad noi=%d zp=%d snok=%d\n",
ureq->buf, length, &ureq->dma,
ureq->no_interrupt, ureq->zero, ureq->short_not_ok);
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
if (index != 0 && ureq->zero) {
if (length == (packets * hs_ep->ep.maxpacket))
packets++;
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
dev_dbg(hsotg->dev, "setup req:%d\n", hsotg->setup);
if (hsotg->setup && index == 0)
hsotg->setup = 0;
else
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
dev_warn(hsotg->dev,
"ep%d: failed to become enabled (DXEPCTL=0x%08x)?\n",
index, readl(hsotg->regs + epctrl_reg));
dev_dbg(hsotg->dev, "%s: DXEPCTL=0x%08x\n",
__func__, readl(hsotg->regs + epctrl_reg));
s3c_hsotg_ctrl_epint(hsotg, hs_ep->index, hs_ep->dir_in, 1);
}
static int s3c_hsotg_map_dma(struct s3c_hsotg *hsotg,
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
static int s3c_hsotg_ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t gfp_flags)
{
struct s3c_hsotg_req *hs_req = our_req(req);
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct s3c_hsotg *hs = hs_ep->parent;
bool first;
dev_dbg(hs->dev, "%s: req %p: %d@%p, noi=%d, zero=%d, snok=%d\n",
ep->name, req, req->length, req->buf, req->no_interrupt,
req->zero, req->short_not_ok);
INIT_LIST_HEAD(&hs_req->queue);
req->actual = 0;
req->status = -EINPROGRESS;
if (using_dma(hs)) {
int ret = s3c_hsotg_map_dma(hs, hs_ep, req);
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
struct s3c_hsotg *hs = hs_ep->parent;
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
struct s3c_hsotg *hsotg = hs_ep->parent;
dev_dbg(hsotg->dev, "%s: ep %p, req %p\n", __func__, ep, req);
s3c_hsotg_ep_free_request(ep, req);
}
static struct s3c_hsotg_ep *ep_from_windex(struct s3c_hsotg *hsotg,
u32 windex)
{
struct s3c_hsotg_ep *ep = &hsotg->eps[windex & 0x7F];
int dir = (windex & USB_DIR_IN) ? 1 : 0;
int idx = windex & 0x7F;
if (windex >= 0x100)
return NULL;
if (idx > hsotg->num_of_eps)
return NULL;
if (idx && ep->dir_in != dir)
return NULL;
return ep;
}
static int s3c_hsotg_send_reply(struct s3c_hsotg *hsotg,
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
req->zero = 1;
req->complete = s3c_hsotg_complete_oursetup;
if (length)
memcpy(req->buf, buff, length);
else
ep->sent_zlp = 1;
ret = s3c_hsotg_ep_queue(&ep->ep, req, GFP_ATOMIC);
if (ret) {
dev_warn(hsotg->dev, "%s: cannot queue req\n", __func__);
return ret;
}
return 0;
}
static int s3c_hsotg_process_req_status(struct s3c_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = &hsotg->eps[0];
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
static int s3c_hsotg_process_req_feature(struct s3c_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = &hsotg->eps[0];
struct s3c_hsotg_req *hs_req;
bool restart;
bool set = (ctrl->bRequest == USB_REQ_SET_FEATURE);
struct s3c_hsotg_ep *ep;
int ret;
bool halted;
dev_dbg(hsotg->dev, "%s: %s_FEATURE\n",
__func__, set ? "SET" : "CLEAR");
if (ctrl->bRequestType == USB_RECIP_ENDPOINT) {
ep = ep_from_windex(hsotg, le16_to_cpu(ctrl->wIndex));
if (!ep) {
dev_dbg(hsotg->dev, "%s: no endpoint for 0x%04x\n",
__func__, le16_to_cpu(ctrl->wIndex));
return -ENOENT;
}
switch (le16_to_cpu(ctrl->wValue)) {
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
usb_gadget_giveback_request(&ep->ep,
&hs_req->req);
}
restart = !list_empty(&ep->queue);
if (restart) {
hs_req = get_ep_head(ep);
s3c_hsotg_start_req(hsotg, ep,
hs_req, false);
}
}
break;
default:
return -ENOENT;
}
} else
return -ENOENT;
return 1;
}
static void s3c_hsotg_stall_ep0(struct s3c_hsotg *hsotg)
{
struct s3c_hsotg_ep *ep0 = &hsotg->eps[0];
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
static void s3c_hsotg_process_control(struct s3c_hsotg *hsotg,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsotg_ep *ep0 = &hsotg->eps[0];
int ret = 0;
u32 dcfg;
ep0->sent_zlp = 0;
dev_dbg(hsotg->dev, "ctrl Req=%02x, Type=%02x, V=%04x, L=%04x\n",
ctrl->bRequest, ctrl->bRequestType,
ctrl->wValue, ctrl->wLength);
ep0->dir_in = (ctrl->bRequestType & USB_DIR_IN) ? 1 : 0;
dev_dbg(hsotg->dev, "ctrl: dir_in=%d\n", ep0->dir_in);
if (ctrl->wLength == 0)
ep0->dir_in = 1;
if ((ctrl->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD) {
switch (ctrl->bRequest) {
case USB_REQ_SET_ADDRESS:
s3c_hsotg_disconnect(hsotg);
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
struct s3c_hsotg *hsotg = hs_ep->parent;
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
static void s3c_hsotg_enqueue_setup(struct s3c_hsotg *hsotg)
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
hsotg->eps[0].dir_in = 0;
ret = s3c_hsotg_ep_queue(&hsotg->eps[0].ep, req, GFP_ATOMIC);
if (ret < 0) {
dev_err(hsotg->dev, "%s: failed queue (%d)\n", __func__, ret);
}
}
static void s3c_hsotg_complete_request(struct s3c_hsotg *hsotg,
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
static void s3c_hsotg_rx_data(struct s3c_hsotg *hsotg, int ep_idx, int size)
{
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[ep_idx];
struct s3c_hsotg_req *hs_req = hs_ep->req;
void __iomem *fifo = hsotg->regs + EPFIFO(ep_idx);
int to_read;
int max_req;
int read_ptr;
if (!hs_req) {
u32 epctl = readl(hsotg->regs + DOEPCTL(ep_idx));
int ptr;
dev_warn(hsotg->dev,
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
static void s3c_hsotg_send_zlp(struct s3c_hsotg *hsotg,
struct s3c_hsotg_req *req)
{
u32 ctrl;
if (!req) {
dev_warn(hsotg->dev, "%s: no request?\n", __func__);
return;
}
if (req->req.length == 0) {
hsotg->eps[0].sent_zlp = 1;
s3c_hsotg_enqueue_setup(hsotg);
return;
}
hsotg->eps[0].dir_in = 1;
hsotg->eps[0].sent_zlp = 1;
dev_dbg(hsotg->dev, "sending zero-length packet\n");
writel(DXEPTSIZ_MC(1) | DXEPTSIZ_PKTCNT(1) |
DXEPTSIZ_XFERSIZE(0), hsotg->regs + DIEPTSIZ(0));
ctrl = readl(hsotg->regs + DIEPCTL0);
ctrl |= DXEPCTL_CNAK;
ctrl |= DXEPCTL_EPENA;
ctrl |= DXEPCTL_USBACTEP;
writel(ctrl, hsotg->regs + DIEPCTL0);
}
static void s3c_hsotg_handle_outdone(struct s3c_hsotg *hsotg,
int epnum, bool was_setup)
{
u32 epsize = readl(hsotg->regs + DOEPTSIZ(epnum));
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[epnum];
struct s3c_hsotg_req *hs_req = hs_ep->req;
struct usb_request *req = &hs_req->req;
unsigned size_left = DXEPTSIZ_XFERSIZE_GET(epsize);
int result = 0;
if (!hs_req) {
dev_dbg(hsotg->dev, "%s: no request active\n", __func__);
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
} else if (epnum == 0) {
hsotg->setup = was_setup ? 0 : 1;
}
if (req->actual < req->length && req->short_not_ok) {
dev_dbg(hsotg->dev, "%s: got %d/%d (short not ok) => error\n",
__func__, req->actual, req->length);
}
if (epnum == 0) {
if (!was_setup && req->complete != s3c_hsotg_complete_setup)
s3c_hsotg_send_zlp(hsotg, hs_req);
}
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, result);
}
static u32 s3c_hsotg_read_frameno(struct s3c_hsotg *hsotg)
{
u32 dsts;
dsts = readl(hsotg->regs + DSTS);
dsts &= DSTS_SOFFN_MASK;
dsts >>= DSTS_SOFFN_SHIFT;
return dsts;
}
static void s3c_hsotg_handle_rx(struct s3c_hsotg *hsotg)
{
u32 grxstsr = readl(hsotg->regs + GRXSTSP);
u32 epnum, status, size;
WARN_ON(using_dma(hsotg));
epnum = grxstsr & GRXSTS_EPNUM_MASK;
status = grxstsr & GRXSTS_PKTSTS_MASK;
size = grxstsr & GRXSTS_BYTECNT_MASK;
size >>= GRXSTS_BYTECNT_SHIFT;
if (1)
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
s3c_hsotg_handle_outdone(hsotg, epnum, false);
break;
case GRXSTS_PKTSTS_SETUPDONE:
dev_dbg(hsotg->dev,
"SetupDone (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + DOEPCTL(0)));
s3c_hsotg_handle_outdone(hsotg, epnum, true);
break;
case GRXSTS_PKTSTS_OUTRX:
s3c_hsotg_rx_data(hsotg, epnum, size);
break;
case GRXSTS_PKTSTS_SETUPRX:
dev_dbg(hsotg->dev,
"SetupRX (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + DOEPCTL(0)));
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
static void s3c_hsotg_set_ep_maxpacket(struct s3c_hsotg *hsotg,
unsigned int ep, unsigned int mps)
{
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[ep];
void __iomem *regs = hsotg->regs;
u32 mpsval;
u32 mcval;
u32 reg;
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
reg = readl(regs + DIEPCTL(ep));
reg &= ~DXEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + DIEPCTL(ep));
if (ep) {
reg = readl(regs + DOEPCTL(ep));
reg &= ~DXEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + DOEPCTL(ep));
}
return;
bad_mps:
dev_err(hsotg->dev, "ep%d: bad mps of %d\n", ep, mps);
}
static void s3c_hsotg_txfifo_flush(struct s3c_hsotg *hsotg, unsigned int idx)
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
static int s3c_hsotg_trytx(struct s3c_hsotg *hsotg,
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
static void s3c_hsotg_complete_in(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep)
{
struct s3c_hsotg_req *hs_req = hs_ep->req;
u32 epsize = readl(hsotg->regs + DIEPTSIZ(hs_ep->index));
int size_left, size_done;
if (!hs_req) {
dev_dbg(hsotg->dev, "XferCompl but no req\n");
return;
}
if (hsotg->eps[0].sent_zlp) {
dev_dbg(hsotg->dev, "zlp packet received\n");
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, 0);
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
if (hs_req->req.length && hs_ep->index == 0 && hs_req->req.zero &&
hs_req->req.length == hs_req->req.actual &&
!(hs_req->req.length % hs_ep->ep.maxpacket)) {
dev_dbg(hsotg->dev, "ep0 zlp IN packet sent\n");
s3c_hsotg_send_zlp(hsotg, hs_req);
return;
}
if (!size_left && hs_req->req.actual < hs_req->req.length) {
dev_dbg(hsotg->dev, "%s trying more for req...\n", __func__);
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, true);
} else
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, 0);
}
static void s3c_hsotg_epint(struct s3c_hsotg *hsotg, unsigned int idx,
int dir_in)
{
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[idx];
u32 epint_reg = dir_in ? DIEPINT(idx) : DOEPINT(idx);
u32 epctl_reg = dir_in ? DIEPCTL(idx) : DOEPCTL(idx);
u32 epsiz_reg = dir_in ? DIEPTSIZ(idx) : DOEPTSIZ(idx);
u32 ints;
u32 ctrl;
ints = readl(hsotg->regs + epint_reg);
ctrl = readl(hsotg->regs + epctl_reg);
writel(ints, hsotg->regs + epint_reg);
dev_dbg(hsotg->dev, "%s: ep%d(%s) DxEPINT=0x%08x\n",
__func__, idx, dir_in ? "in" : "out", ints);
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
s3c_hsotg_handle_outdone(hsotg, idx, false);
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
s3c_hsotg_handle_outdone(hsotg, 0, true);
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
static void s3c_hsotg_irq_enumdone(struct s3c_hsotg *hsotg)
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
s3c_hsotg_set_ep_maxpacket(hsotg, 0, ep0_mps);
for (i = 1; i < hsotg->num_of_eps; i++)
s3c_hsotg_set_ep_maxpacket(hsotg, i, ep_mps);
}
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + DIEPCTL0),
readl(hsotg->regs + DOEPCTL0));
}
static void kill_all_requests(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *ep,
int result, bool force)
{
struct s3c_hsotg_req *req, *treq;
unsigned size;
list_for_each_entry_safe(req, treq, &ep->queue, queue) {
if (ep->req == req && ep->dir_in && !force)
continue;
s3c_hsotg_complete_request(hsotg, ep, req,
result);
}
if (!hsotg->dedicated_fifos)
return;
size = (readl(hsotg->regs + DTXFSTS(ep->index)) & 0xffff) * 4;
if (size < ep->fifo_size)
s3c_hsotg_txfifo_flush(hsotg, ep->fifo_index);
}
static void s3c_hsotg_disconnect(struct s3c_hsotg *hsotg)
{
unsigned ep;
for (ep = 0; ep < hsotg->num_of_eps; ep++)
kill_all_requests(hsotg, &hsotg->eps[ep], -ESHUTDOWN, true);
call_gadget(hsotg, disconnect);
}
static void s3c_hsotg_irq_fifoempty(struct s3c_hsotg *hsotg, bool periodic)
{
struct s3c_hsotg_ep *ep;
int epno, ret;
for (epno = 0; epno < hsotg->num_of_eps; epno++) {
ep = &hsotg->eps[epno];
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
static int s3c_hsotg_corereset(struct s3c_hsotg *hsotg)
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
static void s3c_hsotg_core_init(struct s3c_hsotg *hsotg)
{
s3c_hsotg_corereset(hsotg);
writel(hsotg->phyif | GUSBCFG_TOUTCAL(7) |
(0x5 << 10), hsotg->regs + GUSBCFG);
s3c_hsotg_init_fifo(hsotg);
__orr32(hsotg->regs + DCTL, DCTL_SFTDISCON);
writel(1 << 18 | DCFG_DEVSPD_HS, hsotg->regs + DCFG);
writel(0xffffffff, hsotg->regs + GOTGINT);
writel(0xffffffff, hsotg->regs + GINTSTS);
writel(GINTSTS_ERLYSUSP | GINTSTS_SESSREQINT |
GINTSTS_GOUTNAKEFF | GINTSTS_GINNAKEFF |
GINTSTS_CONIDSTSCHNG | GINTSTS_USBRST |
GINTSTS_ENUMDONE | GINTSTS_OTGINT |
GINTSTS_USBSUSP | GINTSTS_WKUPINT,
hsotg->regs + GINTMSK);
if (using_dma(hsotg))
writel(GAHBCFG_GLBL_INTR_EN | GAHBCFG_DMA_EN |
GAHBCFG_HBSTLEN_INCR4,
hsotg->regs + GAHBCFG);
else
writel(((hsotg->dedicated_fifos) ? (GAHBCFG_NP_TXF_EMP_LVL |
GAHBCFG_P_TXF_EMP_LVL) : 0) |
GAHBCFG_GLBL_INTR_EN,
hsotg->regs + GAHBCFG);
writel(((hsotg->dedicated_fifos) ? DIEPMSK_TXFIFOEMPTY |
DIEPMSK_INTKNTXFEMPMSK : 0) |
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
__orr32(hsotg->regs + DCTL, DCTL_PWRONPRGDONE);
udelay(10);
__bic32(hsotg->regs + DCTL, DCTL_PWRONPRGDONE);
dev_dbg(hsotg->dev, "DCTL=0x%08x\n", readl(hsotg->regs + DCTL));
writel(DXEPTSIZ_MC(1) | DXEPTSIZ_PKTCNT(1) |
DXEPTSIZ_XFERSIZE(8), hsotg->regs + DOEPTSIZ0);
writel(s3c_hsotg_ep0_mps(hsotg->eps[0].ep.maxpacket) |
DXEPCTL_CNAK | DXEPCTL_EPENA |
DXEPCTL_USBACTEP,
hsotg->regs + DOEPCTL0);
writel(s3c_hsotg_ep0_mps(hsotg->eps[0].ep.maxpacket) |
DXEPCTL_USBACTEP, hsotg->regs + DIEPCTL0);
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + DIEPCTL0),
readl(hsotg->regs + DOEPCTL0));
writel(DCTL_CGOUTNAK | DCTL_CGNPINNAK,
hsotg->regs + DCTL);
mdelay(3);
__bic32(hsotg->regs + DCTL, DCTL_SFTDISCON);
}
static irqreturn_t s3c_hsotg_irq(int irq, void *pw)
{
struct s3c_hsotg *hsotg = pw;
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
if (gintsts & GINTSTS_OTGINT) {
u32 otgint = readl(hsotg->regs + GOTGINT);
dev_info(hsotg->dev, "OTGInt: %08x\n", otgint);
writel(otgint, hsotg->regs + GOTGINT);
}
if (gintsts & GINTSTS_SESSREQINT) {
dev_dbg(hsotg->dev, "%s: SessReqInt\n", __func__);
writel(GINTSTS_SESSREQINT, hsotg->regs + GINTSTS);
}
if (gintsts & GINTSTS_ENUMDONE) {
writel(GINTSTS_ENUMDONE, hsotg->regs + GINTSTS);
s3c_hsotg_irq_enumdone(hsotg);
}
if (gintsts & GINTSTS_CONIDSTSCHNG) {
dev_dbg(hsotg->dev, "ConIDStsChg (DSTS=0x%08x, GOTCTL=%08x)\n",
readl(hsotg->regs + DSTS),
readl(hsotg->regs + GOTGCTL));
writel(GINTSTS_CONIDSTSCHNG, hsotg->regs + GINTSTS);
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
for (ep = 0; ep < 15 && daint_out; ep++, daint_out >>= 1) {
if (daint_out & 1)
s3c_hsotg_epint(hsotg, ep, 0);
}
for (ep = 0; ep < 15 && daint_in; ep++, daint_in >>= 1) {
if (daint_in & 1)
s3c_hsotg_epint(hsotg, ep, 1);
}
}
if (gintsts & GINTSTS_USBRST) {
u32 usb_status = readl(hsotg->regs + GOTGCTL);
dev_dbg(hsotg->dev, "%s: USBRst\n", __func__);
dev_dbg(hsotg->dev, "GNPTXSTS=%08x\n",
readl(hsotg->regs + GNPTXSTS));
writel(GINTSTS_USBRST, hsotg->regs + GINTSTS);
if (usb_status & GOTGCTL_BSESVLD) {
if (time_after(jiffies, hsotg->last_rst +
msecs_to_jiffies(200))) {
kill_all_requests(hsotg, &hsotg->eps[0],
-ECONNRESET, true);
s3c_hsotg_core_init(hsotg);
hsotg->last_rst = jiffies;
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
if (gintsts & GINTSTS_MODEMIS) {
dev_warn(hsotg->dev, "warning, mode mismatch triggered\n");
writel(GINTSTS_MODEMIS, hsotg->regs + GINTSTS);
}
if (gintsts & GINTSTS_USBSUSP) {
dev_info(hsotg->dev, "GINTSTS_USBSusp\n");
writel(GINTSTS_USBSUSP, hsotg->regs + GINTSTS);
call_gadget(hsotg, suspend);
}
if (gintsts & GINTSTS_WKUPINT) {
dev_info(hsotg->dev, "GINTSTS_WkUpIn\n");
writel(GINTSTS_WKUPINT, hsotg->regs + GINTSTS);
call_gadget(hsotg, resume);
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
struct s3c_hsotg *hsotg = hs_ep->parent;
unsigned long flags;
int index = hs_ep->index;
u32 epctrl_reg;
u32 epctrl;
u32 mps;
int dir_in;
int i, val, size;
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
s3c_hsotg_set_ep_maxpacket(hsotg, hs_ep->index, mps);
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
if (dir_in && hsotg->dedicated_fifos) {
size = hs_ep->ep.maxpacket*hs_ep->mc;
for (i = 1; i <= 8; ++i) {
if (hsotg->fifo_map & (1<<i))
continue;
val = readl(hsotg->regs + DPTXFSIZN(i));
val = (val >> FIFOSIZE_DEPTH_SHIFT)*4;
if (val < size)
continue;
hsotg->fifo_map |= 1<<i;
epctrl |= DXEPCTL_TXFNUM(i);
hs_ep->fifo_index = i;
hs_ep->fifo_size = val;
break;
}
if (i == 8) {
ret = -ENOMEM;
goto error;
}
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
struct s3c_hsotg *hsotg = hs_ep->parent;
int dir_in = hs_ep->dir_in;
int index = hs_ep->index;
unsigned long flags;
u32 epctrl_reg;
u32 ctrl;
dev_dbg(hsotg->dev, "%s(ep %p)\n", __func__, ep);
if (ep == &hsotg->eps[0].ep) {
dev_err(hsotg->dev, "%s: called for ep0\n", __func__);
return -EINVAL;
}
epctrl_reg = dir_in ? DIEPCTL(index) : DOEPCTL(index);
spin_lock_irqsave(&hsotg->lock, flags);
kill_all_requests(hsotg, hs_ep, -ESHUTDOWN, false);
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
struct s3c_hsotg *hs = hs_ep->parent;
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
struct s3c_hsotg *hs = hs_ep->parent;
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
hs_ep->halted = value;
return 0;
}
static int s3c_hsotg_ep_sethalt_lock(struct usb_ep *ep, int value)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct s3c_hsotg *hs = hs_ep->parent;
unsigned long flags = 0;
int ret = 0;
spin_lock_irqsave(&hs->lock, flags);
ret = s3c_hsotg_ep_sethalt(ep, value);
spin_unlock_irqrestore(&hs->lock, flags);
return ret;
}
static void s3c_hsotg_phy_enable(struct s3c_hsotg *hsotg)
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
static void s3c_hsotg_phy_disable(struct s3c_hsotg *hsotg)
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
static void s3c_hsotg_init(struct s3c_hsotg *hsotg)
{
writel(DIEPMSK_TIMEOUTMSK | DIEPMSK_AHBERRMSK |
DIEPMSK_EPDISBLDMSK | DIEPMSK_XFERCOMPLMSK,
hsotg->regs + DIEPMSK);
writel(DOEPMSK_SETUPMSK | DOEPMSK_AHBERRMSK |
DOEPMSK_EPDISBLDMSK | DOEPMSK_XFERCOMPLMSK,
hsotg->regs + DOEPMSK);
writel(0, hsotg->regs + DAINTMSK);
__orr32(hsotg->regs + DCTL, DCTL_SFTDISCON);
if (0) {
writel(DCTL_SGNPINNAK | DCTL_SGOUTNAK,
hsotg->regs + DCTL);
}
dev_dbg(hsotg->dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(hsotg->regs + GRXFSIZ),
readl(hsotg->regs + GNPTXFSIZ));
s3c_hsotg_init_fifo(hsotg);
writel(GUSBCFG_PHYIF16 | GUSBCFG_TOUTCAL(7) | (0x5 << 10),
hsotg->regs + GUSBCFG);
writel(using_dma(hsotg) ? GAHBCFG_DMA_EN : 0x0,
hsotg->regs + GAHBCFG);
}
static int s3c_hsotg_udc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct s3c_hsotg *hsotg = to_hsotg(gadget);
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
hsotg->last_rst = jiffies;
dev_info(hsotg->dev, "bound driver %s\n", driver->driver.name);
return 0;
err:
hsotg->driver = NULL;
return ret;
}
static int s3c_hsotg_udc_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct s3c_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags = 0;
int ep;
if (!hsotg)
return -ENODEV;
for (ep = 1; ep < hsotg->num_of_eps; ep++)
s3c_hsotg_ep_disable(&hsotg->eps[ep].ep);
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->driver = NULL;
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
spin_unlock_irqrestore(&hsotg->lock, flags);
regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies), hsotg->supplies);
clk_disable(hsotg->clk);
return 0;
}
static int s3c_hsotg_gadget_getframe(struct usb_gadget *gadget)
{
return s3c_hsotg_read_frameno(to_hsotg(gadget));
}
static int s3c_hsotg_pullup(struct usb_gadget *gadget, int is_on)
{
struct s3c_hsotg *hsotg = to_hsotg(gadget);
unsigned long flags = 0;
dev_dbg(hsotg->dev, "%s: is_on: %d\n", __func__, is_on);
spin_lock_irqsave(&hsotg->lock, flags);
if (is_on) {
s3c_hsotg_phy_enable(hsotg);
clk_enable(hsotg->clk);
s3c_hsotg_core_init(hsotg);
} else {
clk_disable(hsotg->clk);
s3c_hsotg_phy_disable(hsotg);
}
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
static void s3c_hsotg_initep(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
int epnum)
{
char *dir;
if (epnum == 0)
dir = "";
else if ((epnum % 2) == 0) {
dir = "out";
} else {
dir = "in";
hs_ep->dir_in = 1;
}
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
writel(next, hsotg->regs + DIEPCTL(epnum));
writel(next, hsotg->regs + DOEPCTL(epnum));
}
}
static void s3c_hsotg_hw_cfg(struct s3c_hsotg *hsotg)
{
u32 cfg2, cfg3, cfg4;
cfg2 = readl(hsotg->regs + 0x48);
hsotg->num_of_eps = (cfg2 >> 10) & 0xF;
cfg3 = readl(hsotg->regs + 0x4C);
hsotg->fifo_mem = (cfg3 >> 16);
cfg4 = readl(hsotg->regs + 0x50);
hsotg->dedicated_fifos = (cfg4 >> 25) & 1;
dev_info(hsotg->dev, "EPs: %d, %s fifos, %d entries in SPRAM\n",
hsotg->num_of_eps,
hsotg->dedicated_fifos ? "dedicated" : "shared",
hsotg->fifo_mem);
}
static void s3c_hsotg_dump(struct s3c_hsotg *hsotg)
{
#ifdef DEBUG
struct device *dev = hsotg->dev;
void __iomem *regs = hsotg->regs;
u32 val;
int idx;
dev_info(dev, "DCFG=0x%08x, DCTL=0x%08x, DIEPMSK=%08x\n",
readl(regs + DCFG), readl(regs + DCTL),
readl(regs + DIEPMSK));
dev_info(dev, "GAHBCFG=0x%08x, 0x44=0x%08x\n",
readl(regs + GAHBCFG), readl(regs + 0x44));
dev_info(dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(regs + GRXFSIZ), readl(regs + GNPTXFSIZ));
for (idx = 1; idx <= 15; idx++) {
val = readl(regs + DPTXFSIZN(idx));
dev_info(dev, "DPTx[%d] FSize=%d, StAddr=0x%08x\n", idx,
val >> FIFOSIZE_DEPTH_SHIFT,
val & FIFOSIZE_STARTADDR_MASK);
}
for (idx = 0; idx < 15; idx++) {
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
static int state_show(struct seq_file *seq, void *v)
{
struct s3c_hsotg *hsotg = seq->private;
void __iomem *regs = hsotg->regs;
int idx;
seq_printf(seq, "DCFG=0x%08x, DCTL=0x%08x, DSTS=0x%08x\n",
readl(regs + DCFG),
readl(regs + DCTL),
readl(regs + DSTS));
seq_printf(seq, "DIEPMSK=0x%08x, DOEPMASK=0x%08x\n",
readl(regs + DIEPMSK), readl(regs + DOEPMSK));
seq_printf(seq, "GINTMSK=0x%08x, GINTSTS=0x%08x\n",
readl(regs + GINTMSK),
readl(regs + GINTSTS));
seq_printf(seq, "DAINTMSK=0x%08x, DAINT=0x%08x\n",
readl(regs + DAINTMSK),
readl(regs + DAINT));
seq_printf(seq, "GNPTXSTS=0x%08x, GRXSTSR=%08x\n",
readl(regs + GNPTXSTS),
readl(regs + GRXSTSR));
seq_puts(seq, "\nEndpoint status:\n");
for (idx = 0; idx < 15; idx++) {
u32 in, out;
in = readl(regs + DIEPCTL(idx));
out = readl(regs + DOEPCTL(idx));
seq_printf(seq, "ep%d: DIEPCTL=0x%08x, DOEPCTL=0x%08x",
idx, in, out);
in = readl(regs + DIEPTSIZ(idx));
out = readl(regs + DOEPTSIZ(idx));
seq_printf(seq, ", DIEPTSIZ=0x%08x, DOEPTSIZ=0x%08x",
in, out);
seq_puts(seq, "\n");
}
return 0;
}
static int state_open(struct inode *inode, struct file *file)
{
return single_open(file, state_show, inode->i_private);
}
static int fifo_show(struct seq_file *seq, void *v)
{
struct s3c_hsotg *hsotg = seq->private;
void __iomem *regs = hsotg->regs;
u32 val;
int idx;
seq_puts(seq, "Non-periodic FIFOs:\n");
seq_printf(seq, "RXFIFO: Size %d\n", readl(regs + GRXFSIZ));
val = readl(regs + GNPTXFSIZ);
seq_printf(seq, "NPTXFIFO: Size %d, Start 0x%08x\n",
val >> FIFOSIZE_DEPTH_SHIFT,
val & FIFOSIZE_DEPTH_MASK);
seq_puts(seq, "\nPeriodic TXFIFOs:\n");
for (idx = 1; idx <= 15; idx++) {
val = readl(regs + DPTXFSIZN(idx));
seq_printf(seq, "\tDPTXFIFO%2d: Size %d, Start 0x%08x\n", idx,
val >> FIFOSIZE_DEPTH_SHIFT,
val & FIFOSIZE_STARTADDR_MASK);
}
return 0;
}
static int fifo_open(struct inode *inode, struct file *file)
{
return single_open(file, fifo_show, inode->i_private);
}
static const char *decode_direction(int is_in)
{
return is_in ? "in" : "out";
}
static int ep_show(struct seq_file *seq, void *v)
{
struct s3c_hsotg_ep *ep = seq->private;
struct s3c_hsotg *hsotg = ep->parent;
struct s3c_hsotg_req *req;
void __iomem *regs = hsotg->regs;
int index = ep->index;
int show_limit = 15;
unsigned long flags;
seq_printf(seq, "Endpoint index %d, named %s, dir %s:\n",
ep->index, ep->ep.name, decode_direction(ep->dir_in));
seq_printf(seq, "\tDIEPCTL=0x%08x, DOEPCTL=0x%08x\n",
readl(regs + DIEPCTL(index)),
readl(regs + DOEPCTL(index)));
seq_printf(seq, "\tDIEPDMA=0x%08x, DOEPDMA=0x%08x\n",
readl(regs + DIEPDMA(index)),
readl(regs + DOEPDMA(index)));
seq_printf(seq, "\tDIEPINT=0x%08x, DOEPINT=0x%08x\n",
readl(regs + DIEPINT(index)),
readl(regs + DOEPINT(index)));
seq_printf(seq, "\tDIEPTSIZ=0x%08x, DOEPTSIZ=0x%08x\n",
readl(regs + DIEPTSIZ(index)),
readl(regs + DOEPTSIZ(index)));
seq_puts(seq, "\n");
seq_printf(seq, "mps %d\n", ep->ep.maxpacket);
seq_printf(seq, "total_data=%ld\n", ep->total_data);
seq_printf(seq, "request list (%p,%p):\n",
ep->queue.next, ep->queue.prev);
spin_lock_irqsave(&hsotg->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (--show_limit < 0) {
seq_puts(seq, "not showing more requests...\n");
break;
}
seq_printf(seq, "%c req %p: %d bytes @%p, ",
req == ep->req ? '*' : ' ',
req, req->req.length, req->req.buf);
seq_printf(seq, "%d done, res %d\n",
req->req.actual, req->req.status);
}
spin_unlock_irqrestore(&hsotg->lock, flags);
return 0;
}
static int ep_open(struct inode *inode, struct file *file)
{
return single_open(file, ep_show, inode->i_private);
}
static void s3c_hsotg_create_debug(struct s3c_hsotg *hsotg)
{
struct dentry *root;
unsigned epidx;
root = debugfs_create_dir(dev_name(hsotg->dev), NULL);
hsotg->debug_root = root;
if (IS_ERR(root)) {
dev_err(hsotg->dev, "cannot create debug root\n");
return;
}
hsotg->debug_file = debugfs_create_file("state", 0444, root,
hsotg, &state_fops);
if (IS_ERR(hsotg->debug_file))
dev_err(hsotg->dev, "%s: failed to create state\n", __func__);
hsotg->debug_fifo = debugfs_create_file("fifo", 0444, root,
hsotg, &fifo_fops);
if (IS_ERR(hsotg->debug_fifo))
dev_err(hsotg->dev, "%s: failed to create fifo\n", __func__);
for (epidx = 0; epidx < hsotg->num_of_eps; epidx++) {
struct s3c_hsotg_ep *ep = &hsotg->eps[epidx];
ep->debugfs = debugfs_create_file(ep->name, 0444,
root, ep, &ep_fops);
if (IS_ERR(ep->debugfs))
dev_err(hsotg->dev, "failed to create %s debug file\n",
ep->name);
}
}
static void s3c_hsotg_delete_debug(struct s3c_hsotg *hsotg)
{
unsigned epidx;
for (epidx = 0; epidx < hsotg->num_of_eps; epidx++) {
struct s3c_hsotg_ep *ep = &hsotg->eps[epidx];
debugfs_remove(ep->debugfs);
}
debugfs_remove(hsotg->debug_file);
debugfs_remove(hsotg->debug_fifo);
debugfs_remove(hsotg->debug_root);
}
static int s3c_hsotg_probe(struct platform_device *pdev)
{
struct s3c_hsotg_plat *plat = dev_get_platdata(&pdev->dev);
struct phy *phy;
struct usb_phy *uphy;
struct device *dev = &pdev->dev;
struct s3c_hsotg_ep *eps;
struct s3c_hsotg *hsotg;
struct resource *res;
int epnum;
int ret;
int i;
hsotg = devm_kzalloc(&pdev->dev, sizeof(struct s3c_hsotg), GFP_KERNEL);
if (!hsotg)
return -ENOMEM;
hsotg->phyif = GUSBCFG_PHYIF16;
phy = devm_phy_get(&pdev->dev, "usb2-phy");
if (IS_ERR(phy)) {
uphy = devm_usb_get_phy(dev, USB_PHY_TYPE_USB2);
if (IS_ERR(uphy)) {
plat = dev_get_platdata(&pdev->dev);
if (!plat) {
dev_err(&pdev->dev,
"no platform data or transceiver defined\n");
return -EPROBE_DEFER;
}
hsotg->plat = plat;
} else
hsotg->uphy = uphy;
} else {
hsotg->phy = phy;
if (phy_get_bus_width(phy) == 8)
hsotg->phyif = GUSBCFG_PHYIF8;
}
hsotg->dev = dev;
hsotg->clk = devm_clk_get(&pdev->dev, "otg");
if (IS_ERR(hsotg->clk)) {
dev_err(dev, "cannot get otg clock\n");
return PTR_ERR(hsotg->clk);
}
platform_set_drvdata(pdev, hsotg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hsotg->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hsotg->regs)) {
ret = PTR_ERR(hsotg->regs);
goto err_clk;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "cannot find IRQ\n");
goto err_clk;
}
spin_lock_init(&hsotg->lock);
hsotg->irq = ret;
dev_info(dev, "regs %p, irq %d\n", hsotg->regs, hsotg->irq);
hsotg->gadget.max_speed = USB_SPEED_HIGH;
hsotg->gadget.ops = &s3c_hsotg_gadget_ops;
hsotg->gadget.name = dev_name(dev);
clk_prepare_enable(hsotg->clk);
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
dev_err(hsotg->dev, "failed to enable supplies: %d\n", ret);
goto err_supplies;
}
s3c_hsotg_phy_enable(hsotg);
s3c_hsotg_corereset(hsotg);
s3c_hsotg_hw_cfg(hsotg);
s3c_hsotg_init(hsotg);
ret = devm_request_irq(&pdev->dev, hsotg->irq, s3c_hsotg_irq, 0,
dev_name(dev), hsotg);
if (ret < 0) {
s3c_hsotg_phy_disable(hsotg);
clk_disable_unprepare(hsotg->clk);
regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
dev_err(dev, "cannot claim IRQ\n");
goto err_clk;
}
if (hsotg->num_of_eps == 0) {
dev_err(dev, "wrong number of EPs (zero)\n");
ret = -EINVAL;
goto err_supplies;
}
eps = kcalloc(hsotg->num_of_eps + 1, sizeof(struct s3c_hsotg_ep),
GFP_KERNEL);
if (!eps) {
ret = -ENOMEM;
goto err_supplies;
}
hsotg->eps = eps;
INIT_LIST_HEAD(&hsotg->gadget.ep_list);
hsotg->gadget.ep0 = &hsotg->eps[0].ep;
hsotg->ctrl_req = s3c_hsotg_ep_alloc_request(&hsotg->eps[0].ep,
GFP_KERNEL);
if (!hsotg->ctrl_req) {
dev_err(dev, "failed to allocate ctrl req\n");
ret = -ENOMEM;
goto err_ep_mem;
}
for (epnum = 0; epnum < hsotg->num_of_eps; epnum++)
s3c_hsotg_initep(hsotg, &hsotg->eps[epnum], epnum);
s3c_hsotg_phy_disable(hsotg);
ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
if (ret) {
dev_err(hsotg->dev, "failed to disable supplies: %d\n", ret);
goto err_ep_mem;
}
ret = usb_add_gadget_udc(&pdev->dev, &hsotg->gadget);
if (ret)
goto err_ep_mem;
s3c_hsotg_create_debug(hsotg);
s3c_hsotg_dump(hsotg);
return 0;
err_ep_mem:
kfree(eps);
err_supplies:
s3c_hsotg_phy_disable(hsotg);
err_clk:
clk_disable_unprepare(hsotg->clk);
return ret;
}
static int s3c_hsotg_remove(struct platform_device *pdev)
{
struct s3c_hsotg *hsotg = platform_get_drvdata(pdev);
usb_del_gadget_udc(&hsotg->gadget);
s3c_hsotg_delete_debug(hsotg);
if (hsotg->driver) {
usb_gadget_unregister_driver(hsotg->driver);
}
clk_disable_unprepare(hsotg->clk);
return 0;
}
static int s3c_hsotg_suspend(struct platform_device *pdev, pm_message_t state)
{
struct s3c_hsotg *hsotg = platform_get_drvdata(pdev);
unsigned long flags;
int ret = 0;
if (hsotg->driver)
dev_info(hsotg->dev, "suspending usb gadget %s\n",
hsotg->driver->driver.name);
spin_lock_irqsave(&hsotg->lock, flags);
s3c_hsotg_disconnect(hsotg);
s3c_hsotg_phy_disable(hsotg);
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
spin_unlock_irqrestore(&hsotg->lock, flags);
if (hsotg->driver) {
int ep;
for (ep = 0; ep < hsotg->num_of_eps; ep++)
s3c_hsotg_ep_disable(&hsotg->eps[ep].ep);
ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
clk_disable(hsotg->clk);
}
return ret;
}
static int s3c_hsotg_resume(struct platform_device *pdev)
{
struct s3c_hsotg *hsotg = platform_get_drvdata(pdev);
unsigned long flags;
int ret = 0;
if (hsotg->driver) {
dev_info(hsotg->dev, "resuming usb gadget %s\n",
hsotg->driver->driver.name);
clk_enable(hsotg->clk);
ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
hsotg->supplies);
}
spin_lock_irqsave(&hsotg->lock, flags);
hsotg->last_rst = jiffies;
s3c_hsotg_phy_enable(hsotg);
s3c_hsotg_core_init(hsotg);
spin_unlock_irqrestore(&hsotg->lock, flags);
return ret;
}
