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
u32 gsintmsk = readl(hsotg->regs + S3C_GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk | ints;
if (new_gsintmsk != gsintmsk) {
dev_dbg(hsotg->dev, "gsintmsk now 0x%08x\n", new_gsintmsk);
writel(new_gsintmsk, hsotg->regs + S3C_GINTMSK);
}
}
static void s3c_hsotg_disable_gsint(struct s3c_hsotg *hsotg, u32 ints)
{
u32 gsintmsk = readl(hsotg->regs + S3C_GINTMSK);
u32 new_gsintmsk;
new_gsintmsk = gsintmsk & ~ints;
if (new_gsintmsk != gsintmsk)
writel(new_gsintmsk, hsotg->regs + S3C_GINTMSK);
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
daint = readl(hsotg->regs + S3C_DAINTMSK);
if (en)
daint |= bit;
else
daint &= ~bit;
writel(daint, hsotg->regs + S3C_DAINTMSK);
local_irq_restore(flags);
}
static void s3c_hsotg_init_fifo(struct s3c_hsotg *hsotg)
{
unsigned int ep;
unsigned int addr;
unsigned int size;
int timeout;
u32 val;
writel(2048, hsotg->regs + S3C_GRXFSIZ);
writel(S3C_GNPTXFSIZ_NPTxFStAddr(2048) |
S3C_GNPTXFSIZ_NPTxFDep(1024),
hsotg->regs + S3C_GNPTXFSIZ);
addr = 2048 + 1024;
size = 768;
for (ep = 1; ep <= 15; ep++) {
val = addr;
val |= size << S3C_DPTXFSIZn_DPTxFSize_SHIFT;
addr += size;
writel(val, hsotg->regs + S3C_DPTXFSIZn(ep));
}
writel(S3C_GRSTCTL_TxFNum(0x10) | S3C_GRSTCTL_TxFFlsh |
S3C_GRSTCTL_RxFFlsh, hsotg->regs + S3C_GRSTCTL);
timeout = 100;
while (1) {
val = readl(hsotg->regs + S3C_GRSTCTL);
if ((val & (S3C_GRSTCTL_TxFFlsh | S3C_GRSTCTL_RxFFlsh)) == 0)
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
req->req.dma = DMA_ADDR_INVALID;
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
enum dma_data_direction dir;
dir = hs_ep->dir_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
if (hs_req->req.length == 0)
return;
if (hs_req->mapped) {
dma_unmap_single(hsotg->dev, req->dma, req->length, dir);
req->dma = DMA_ADDR_INVALID;
hs_req->mapped = 0;
} else {
dma_sync_single_for_cpu(hsotg->dev, req->dma, req->length, dir);
}
}
static int s3c_hsotg_write_fifo(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req)
{
bool periodic = is_ep_periodic(hs_ep);
u32 gnptxsts = readl(hsotg->regs + S3C_GNPTXSTS);
int buf_pos = hs_req->req.actual;
int to_write = hs_ep->size_loaded;
void *data;
int can_write;
int pkt_round;
to_write -= (buf_pos - hs_ep->last_load);
if (to_write == 0)
return 0;
if (periodic && !hsotg->dedicated_fifos) {
u32 epsize = readl(hsotg->regs + S3C_DIEPTSIZ(hs_ep->index));
int size_left;
int size_done;
size_left = S3C_DxEPTSIZ_XferSize_GET(epsize);
if (hs_ep->fifo_load != 0) {
s3c_hsotg_en_gsint(hsotg, S3C_GINTSTS_PTxFEmp);
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
s3c_hsotg_en_gsint(hsotg, S3C_GINTSTS_PTxFEmp);
return -ENOSPC;
}
} else if (hsotg->dedicated_fifos && hs_ep->index != 0) {
can_write = readl(hsotg->regs + S3C_DTXFSTS(hs_ep->index));
can_write &= 0xffff;
can_write *= 4;
} else {
if (S3C_GNPTXSTS_NPTxQSpcAvail_GET(gnptxsts) == 0) {
dev_dbg(hsotg->dev,
"%s: no queue slots available (0x%08x)\n",
__func__, gnptxsts);
s3c_hsotg_en_gsint(hsotg, S3C_GINTSTS_NPTxFEmp);
return -ENOSPC;
}
can_write = S3C_GNPTXSTS_NPTxFSpcAvail_GET(gnptxsts);
can_write *= 4;
}
dev_dbg(hsotg->dev, "%s: GNPTXSTS=%08x, can=%d, to=%d, mps %d\n",
__func__, gnptxsts, can_write, to_write, hs_ep->ep.maxpacket);
if (can_write > 512)
can_write = 512;
if (to_write > hs_ep->ep.maxpacket) {
to_write = hs_ep->ep.maxpacket;
s3c_hsotg_en_gsint(hsotg,
periodic ? S3C_GINTSTS_PTxFEmp :
S3C_GINTSTS_NPTxFEmp);
}
if (to_write > can_write) {
to_write = can_write;
pkt_round = to_write % hs_ep->ep.maxpacket;
if (pkt_round)
to_write -= pkt_round;
s3c_hsotg_en_gsint(hsotg,
periodic ? S3C_GINTSTS_PTxFEmp :
S3C_GINTSTS_NPTxFEmp);
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
writesl(hsotg->regs + S3C_EPFIFO(hs_ep->index), data, to_write);
return (to_write >= can_write) ? -ENOSPC : 0;
}
static unsigned get_ep_limit(struct s3c_hsotg_ep *hs_ep)
{
int index = hs_ep->index;
unsigned maxsize;
unsigned maxpkt;
if (index != 0) {
maxsize = S3C_DxEPTSIZ_XferSize_LIMIT + 1;
maxpkt = S3C_DxEPTSIZ_PktCnt_LIMIT + 1;
} else {
maxsize = 64+64;
if (hs_ep->dir_in)
maxpkt = S3C_DIEPTSIZ0_PktCnt_LIMIT + 1;
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
epctrl_reg = dir_in ? S3C_DIEPCTL(index) : S3C_DOEPCTL(index);
epsize_reg = dir_in ? S3C_DIEPTSIZ(index) : S3C_DOEPTSIZ(index);
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x, ep %d, dir %s\n",
__func__, readl(hsotg->regs + epctrl_reg), index,
hs_ep->dir_in ? "in" : "out");
ctrl = readl(hsotg->regs + epctrl_reg);
if (ctrl & S3C_DxEPCTL_Stall) {
dev_warn(hsotg->dev, "%s: ep%d is stalled\n", __func__, index);
return;
}
length = ureq->length - ureq->actual;
if (0)
dev_dbg(hsotg->dev,
"REQ buf %p len %d dma 0x%08x noi=%d zp=%d snok=%d\n",
ureq->buf, length, ureq->dma,
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
if (dir_in && index != 0)
epsize = S3C_DxEPTSIZ_MC(1);
else
epsize = 0;
if (index != 0 && ureq->zero) {
if (length == (packets * hs_ep->ep.maxpacket))
packets++;
}
epsize |= S3C_DxEPTSIZ_PktCnt(packets);
epsize |= S3C_DxEPTSIZ_XferSize(length);
dev_dbg(hsotg->dev, "%s: %d@%d/%d, 0x%08x => 0x%08x\n",
__func__, packets, length, ureq->length, epsize, epsize_reg);
hs_ep->req = hs_req;
writel(epsize, hsotg->regs + epsize_reg);
if (using_dma(hsotg) && !continuing) {
unsigned int dma_reg;
dma_reg = dir_in ? S3C_DIEPDMA(index) : S3C_DOEPDMA(index);
writel(ureq->dma, hsotg->regs + dma_reg);
dev_dbg(hsotg->dev, "%s: 0x%08x => 0x%08x\n",
__func__, ureq->dma, dma_reg);
}
ctrl |= S3C_DxEPCTL_EPEna;
ctrl |= S3C_DxEPCTL_USBActEp;
ctrl |= S3C_DxEPCTL_CNAK;
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x\n", __func__, ctrl);
writel(ctrl, hsotg->regs + epctrl_reg);
hs_ep->size_loaded = length;
hs_ep->last_load = ureq->actual;
if (dir_in && !using_dma(hsotg)) {
hs_ep->fifo_load = 0;
s3c_hsotg_write_fifo(hsotg, hs_ep, hs_req);
}
if (dir_in)
writel(S3C_DIEPMSK_INTknTXFEmpMsk,
hsotg->regs + S3C_DIEPINT(index));
if (!(readl(hsotg->regs + epctrl_reg) & S3C_DxEPCTL_EPEna))
dev_warn(hsotg->dev,
"ep%d: failed to become enabled (DxEPCTL=0x%08x)?\n",
index, readl(hsotg->regs + epctrl_reg));
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x\n",
__func__, readl(hsotg->regs + epctrl_reg));
}
static int s3c_hsotg_map_dma(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct usb_request *req)
{
enum dma_data_direction dir;
struct s3c_hsotg_req *hs_req = our_req(req);
dir = hs_ep->dir_in ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
if (hs_req->req.length == 0)
return 0;
if (req->dma == DMA_ADDR_INVALID) {
dma_addr_t dma;
dma = dma_map_single(hsotg->dev, req->buf, req->length, dir);
if (unlikely(dma_mapping_error(hsotg->dev, dma)))
goto dma_error;
if (dma & 3) {
dev_err(hsotg->dev, "%s: unaligned dma buffer\n",
__func__);
dma_unmap_single(hsotg->dev, dma, req->length, dir);
return -EINVAL;
}
hs_req->mapped = 1;
req->dma = dma;
} else {
dma_sync_single_for_cpu(hsotg->dev, req->dma, req->length, dir);
hs_req->mapped = 0;
}
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
unsigned long irqflags;
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
spin_lock_irqsave(&hs_ep->lock, irqflags);
first = list_empty(&hs_ep->queue);
list_add_tail(&hs_req->queue, &hs_ep->queue);
if (first)
s3c_hsotg_start_req(hs, hs_ep, hs_req, false);
spin_unlock_irqrestore(&hs_ep->lock, irqflags);
return 0;
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
if (idx > S3C_HSOTG_EPS)
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
s3c_hsotg_ep_sethalt(&ep->ep, set);
ret = s3c_hsotg_send_reply(hsotg, ep0, NULL, 0);
if (ret) {
dev_err(hsotg->dev,
"%s: failed to send reply\n", __func__);
return ret;
}
if (!set) {
if (ep->req) {
hs_req = ep->req;
ep->req = NULL;
list_del_init(&hs_req->queue);
hs_req->req.complete(&ep->ep,
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
dcfg = readl(hsotg->regs + S3C_DCFG);
dcfg &= ~S3C_DCFG_DevAddr_MASK;
dcfg |= ctrl->wValue << S3C_DCFG_DevAddr_SHIFT;
writel(dcfg, hsotg->regs + S3C_DCFG);
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
ret = hsotg->driver->setup(&hsotg->gadget, ctrl);
if (ret < 0)
dev_dbg(hsotg->dev, "driver->setup() ret %d\n", ret);
}
if (ret < 0) {
u32 reg;
u32 ctrl;
dev_dbg(hsotg->dev, "ep0 stall (dir=%d)\n", ep0->dir_in);
reg = (ep0->dir_in) ? S3C_DIEPCTL0 : S3C_DOEPCTL0;
ctrl = readl(hsotg->regs + reg);
ctrl |= S3C_DxEPCTL_Stall;
ctrl |= S3C_DxEPCTL_CNAK;
writel(ctrl, hsotg->regs + reg);
dev_dbg(hsotg->dev,
"written DxEPCTL=0x%08x to %08x (DxEPCTL=0x%08x)\n",
ctrl, reg, readl(hsotg->regs + reg));
}
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
if (req->actual == 0)
s3c_hsotg_enqueue_setup(hsotg);
else
s3c_hsotg_process_control(hsotg, req->buf);
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
spin_unlock(&hs_ep->lock);
hs_req->req.complete(&hs_ep->ep, &hs_req->req);
spin_lock(&hs_ep->lock);
}
if (!hs_ep->req && result >= 0) {
restart = !list_empty(&hs_ep->queue);
if (restart) {
hs_req = get_ep_head(hs_ep);
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, false);
}
}
}
static void s3c_hsotg_complete_request_lock(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
struct s3c_hsotg_req *hs_req,
int result)
{
unsigned long flags;
spin_lock_irqsave(&hs_ep->lock, flags);
s3c_hsotg_complete_request(hsotg, hs_ep, hs_req, result);
spin_unlock_irqrestore(&hs_ep->lock, flags);
}
static void s3c_hsotg_rx_data(struct s3c_hsotg *hsotg, int ep_idx, int size)
{
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[ep_idx];
struct s3c_hsotg_req *hs_req = hs_ep->req;
void __iomem *fifo = hsotg->regs + S3C_EPFIFO(ep_idx);
int to_read;
int max_req;
int read_ptr;
if (!hs_req) {
u32 epctl = readl(hsotg->regs + S3C_DOEPCTL(ep_idx));
int ptr;
dev_warn(hsotg->dev,
"%s: FIFO %d bytes on ep%d but no req (DxEPCTl=0x%08x)\n",
__func__, size, ep_idx, epctl);
for (ptr = 0; ptr < size; ptr += 4)
(void)readl(fifo);
return;
}
spin_lock(&hs_ep->lock);
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
readsl(fifo, hs_req->req.buf + read_ptr, to_read);
spin_unlock(&hs_ep->lock);
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
writel(S3C_DxEPTSIZ_MC(1) | S3C_DxEPTSIZ_PktCnt(1) |
S3C_DxEPTSIZ_XferSize(0), hsotg->regs + S3C_DIEPTSIZ(0));
ctrl = readl(hsotg->regs + S3C_DIEPCTL0);
ctrl |= S3C_DxEPCTL_CNAK;
ctrl |= S3C_DxEPCTL_EPEna;
ctrl |= S3C_DxEPCTL_USBActEp;
writel(ctrl, hsotg->regs + S3C_DIEPCTL0);
}
static void s3c_hsotg_handle_outdone(struct s3c_hsotg *hsotg,
int epnum, bool was_setup)
{
u32 epsize = readl(hsotg->regs + S3C_DOEPTSIZ(epnum));
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[epnum];
struct s3c_hsotg_req *hs_req = hs_ep->req;
struct usb_request *req = &hs_req->req;
unsigned size_left = S3C_DxEPTSIZ_XferSize_GET(epsize);
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
}
if (req->actual < req->length && req->short_not_ok) {
dev_dbg(hsotg->dev, "%s: got %d/%d (short not ok) => error\n",
__func__, req->actual, req->length);
}
if (epnum == 0) {
if (!was_setup && req->complete != s3c_hsotg_complete_setup)
s3c_hsotg_send_zlp(hsotg, hs_req);
}
s3c_hsotg_complete_request_lock(hsotg, hs_ep, hs_req, result);
}
static u32 s3c_hsotg_read_frameno(struct s3c_hsotg *hsotg)
{
u32 dsts;
dsts = readl(hsotg->regs + S3C_DSTS);
dsts &= S3C_DSTS_SOFFN_MASK;
dsts >>= S3C_DSTS_SOFFN_SHIFT;
return dsts;
}
static void s3c_hsotg_handle_rx(struct s3c_hsotg *hsotg)
{
u32 grxstsr = readl(hsotg->regs + S3C_GRXSTSP);
u32 epnum, status, size;
WARN_ON(using_dma(hsotg));
epnum = grxstsr & S3C_GRXSTS_EPNum_MASK;
status = grxstsr & S3C_GRXSTS_PktSts_MASK;
size = grxstsr & S3C_GRXSTS_ByteCnt_MASK;
size >>= S3C_GRXSTS_ByteCnt_SHIFT;
if (1)
dev_dbg(hsotg->dev, "%s: GRXSTSP=0x%08x (%d@%d)\n",
__func__, grxstsr, size, epnum);
#define __status(x) ((x) >> S3C_GRXSTS_PktSts_SHIFT)
switch (status >> S3C_GRXSTS_PktSts_SHIFT) {
case __status(S3C_GRXSTS_PktSts_GlobalOutNAK):
dev_dbg(hsotg->dev, "GlobalOutNAK\n");
break;
case __status(S3C_GRXSTS_PktSts_OutDone):
dev_dbg(hsotg->dev, "OutDone (Frame=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg));
if (!using_dma(hsotg))
s3c_hsotg_handle_outdone(hsotg, epnum, false);
break;
case __status(S3C_GRXSTS_PktSts_SetupDone):
dev_dbg(hsotg->dev,
"SetupDone (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + S3C_DOEPCTL(0)));
s3c_hsotg_handle_outdone(hsotg, epnum, true);
break;
case __status(S3C_GRXSTS_PktSts_OutRX):
s3c_hsotg_rx_data(hsotg, epnum, size);
break;
case __status(S3C_GRXSTS_PktSts_SetupRX):
dev_dbg(hsotg->dev,
"SetupRX (Frame=0x%08x, DOPEPCTL=0x%08x)\n",
s3c_hsotg_read_frameno(hsotg),
readl(hsotg->regs + S3C_DOEPCTL(0)));
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
return S3C_D0EPCTL_MPS_64;
case 32:
return S3C_D0EPCTL_MPS_32;
case 16:
return S3C_D0EPCTL_MPS_16;
case 8:
return S3C_D0EPCTL_MPS_8;
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
u32 reg;
if (ep == 0) {
mpsval = s3c_hsotg_ep0_mps(mps);
if (mpsval > 3)
goto bad_mps;
} else {
if (mps >= S3C_DxEPCTL_MPS_LIMIT+1)
goto bad_mps;
mpsval = mps;
}
hs_ep->ep.maxpacket = mps;
reg = readl(regs + S3C_DIEPCTL(ep));
reg &= ~S3C_DxEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + S3C_DIEPCTL(ep));
if (ep) {
reg = readl(regs + S3C_DOEPCTL(ep));
reg &= ~S3C_DxEPCTL_MPS_MASK;
reg |= mpsval;
writel(reg, regs + S3C_DOEPCTL(ep));
}
return;
bad_mps:
dev_err(hsotg->dev, "ep%d: bad mps of %d\n", ep, mps);
}
static void s3c_hsotg_txfifo_flush(struct s3c_hsotg *hsotg, unsigned int idx)
{
int timeout;
int val;
writel(S3C_GRSTCTL_TxFNum(idx) | S3C_GRSTCTL_TxFFlsh,
hsotg->regs + S3C_GRSTCTL);
timeout = 100;
while (1) {
val = readl(hsotg->regs + S3C_GRSTCTL);
if ((val & (S3C_GRSTCTL_TxFFlsh)) == 0)
break;
if (--timeout == 0) {
dev_err(hsotg->dev,
"%s: timeout flushing fifo (GRSTCTL=%08x)\n",
__func__, val);
}
udelay(1);
}
}
static int s3c_hsotg_trytx(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep)
{
struct s3c_hsotg_req *hs_req = hs_ep->req;
if (!hs_ep->dir_in || !hs_req)
return 0;
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
u32 epsize = readl(hsotg->regs + S3C_DIEPTSIZ(hs_ep->index));
int size_left, size_done;
if (!hs_req) {
dev_dbg(hsotg->dev, "XferCompl but no req\n");
return;
}
size_left = S3C_DxEPTSIZ_XferSize_GET(epsize);
size_done = hs_ep->size_loaded - size_left;
size_done += hs_ep->last_load;
if (hs_req->req.actual != size_done)
dev_dbg(hsotg->dev, "%s: adjusting size done %d => %d\n",
__func__, hs_req->req.actual, size_done);
hs_req->req.actual = size_done;
if (!size_left && hs_req->req.actual < hs_req->req.length) {
dev_dbg(hsotg->dev, "%s trying more for req...\n", __func__);
s3c_hsotg_start_req(hsotg, hs_ep, hs_req, true);
} else
s3c_hsotg_complete_request_lock(hsotg, hs_ep, hs_req, 0);
}
static void s3c_hsotg_epint(struct s3c_hsotg *hsotg, unsigned int idx,
int dir_in)
{
struct s3c_hsotg_ep *hs_ep = &hsotg->eps[idx];
u32 epint_reg = dir_in ? S3C_DIEPINT(idx) : S3C_DOEPINT(idx);
u32 epctl_reg = dir_in ? S3C_DIEPCTL(idx) : S3C_DOEPCTL(idx);
u32 epsiz_reg = dir_in ? S3C_DIEPTSIZ(idx) : S3C_DOEPTSIZ(idx);
u32 ints;
ints = readl(hsotg->regs + epint_reg);
writel(ints, hsotg->regs + epint_reg);
dev_dbg(hsotg->dev, "%s: ep%d(%s) DxEPINT=0x%08x\n",
__func__, idx, dir_in ? "in" : "out", ints);
if (ints & S3C_DxEPINT_XferCompl) {
dev_dbg(hsotg->dev,
"%s: XferCompl: DxEPCTL=0x%08x, DxEPTSIZ=%08x\n",
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
if (ints & S3C_DxEPINT_EPDisbld) {
dev_dbg(hsotg->dev, "%s: EPDisbld\n", __func__);
if (dir_in) {
int epctl = readl(hsotg->regs + epctl_reg);
s3c_hsotg_txfifo_flush(hsotg, idx);
if ((epctl & S3C_DxEPCTL_Stall) &&
(epctl & S3C_DxEPCTL_EPType_Bulk)) {
int dctl = readl(hsotg->regs + S3C_DCTL);
dctl |= S3C_DCTL_CGNPInNAK;
writel(dctl, hsotg->regs + S3C_DCTL);
}
}
}
if (ints & S3C_DxEPINT_AHBErr)
dev_dbg(hsotg->dev, "%s: AHBErr\n", __func__);
if (ints & S3C_DxEPINT_Setup) {
dev_dbg(hsotg->dev, "%s: Setup/Timeout\n", __func__);
if (using_dma(hsotg) && idx == 0) {
if (dir_in)
WARN_ON_ONCE(1);
else
s3c_hsotg_handle_outdone(hsotg, 0, true);
}
}
if (ints & S3C_DxEPINT_Back2BackSetup)
dev_dbg(hsotg->dev, "%s: B2BSetup/INEPNakEff\n", __func__);
if (dir_in) {
if (ints & S3C_DIEPMSK_INTknTXFEmpMsk) {
dev_dbg(hsotg->dev, "%s: ep%d: INTknTXFEmpMsk\n",
__func__, idx);
}
if (ints & S3C_DIEPMSK_INTknEPMisMsk) {
dev_warn(hsotg->dev, "%s: ep%d: INTknEP\n",
__func__, idx);
}
if (hsotg->dedicated_fifos &&
ints & S3C_DIEPMSK_TxFIFOEmpty) {
dev_dbg(hsotg->dev, "%s: ep%d: TxFIFOEmpty\n",
__func__, idx);
if (!using_dma(hsotg))
s3c_hsotg_trytx(hsotg, hs_ep);
}
}
}
static void s3c_hsotg_irq_enumdone(struct s3c_hsotg *hsotg)
{
u32 dsts = readl(hsotg->regs + S3C_DSTS);
int ep0_mps = 0, ep_mps;
dev_dbg(hsotg->dev, "EnumDone (DSTS=0x%08x)\n", dsts);
switch (dsts & S3C_DSTS_EnumSpd_MASK) {
case S3C_DSTS_EnumSpd_FS:
case S3C_DSTS_EnumSpd_FS48:
hsotg->gadget.speed = USB_SPEED_FULL;
ep0_mps = EP0_MPS_LIMIT;
ep_mps = 64;
break;
case S3C_DSTS_EnumSpd_HS:
hsotg->gadget.speed = USB_SPEED_HIGH;
ep0_mps = EP0_MPS_LIMIT;
ep_mps = 512;
break;
case S3C_DSTS_EnumSpd_LS:
hsotg->gadget.speed = USB_SPEED_LOW;
break;
}
dev_info(hsotg->dev, "new device is %s\n",
usb_speed_string(hsotg->gadget.speed));
if (ep0_mps) {
int i;
s3c_hsotg_set_ep_maxpacket(hsotg, 0, ep0_mps);
for (i = 1; i < S3C_HSOTG_EPS; i++)
s3c_hsotg_set_ep_maxpacket(hsotg, i, ep_mps);
}
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + S3C_DIEPCTL0),
readl(hsotg->regs + S3C_DOEPCTL0));
}
static void kill_all_requests(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *ep,
int result, bool force)
{
struct s3c_hsotg_req *req, *treq;
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
list_for_each_entry_safe(req, treq, &ep->queue, queue) {
if (ep->req == req && ep->dir_in && !force)
continue;
s3c_hsotg_complete_request(hsotg, ep, req,
result);
}
spin_unlock_irqrestore(&ep->lock, flags);
}
static void s3c_hsotg_disconnect_irq(struct s3c_hsotg *hsotg)
{
unsigned ep;
for (ep = 0; ep < S3C_HSOTG_EPS; ep++)
kill_all_requests(hsotg, &hsotg->eps[ep], -ESHUTDOWN, true);
call_gadget(hsotg, disconnect);
}
static void s3c_hsotg_irq_fifoempty(struct s3c_hsotg *hsotg, bool periodic)
{
struct s3c_hsotg_ep *ep;
int epno, ret;
for (epno = 0; epno < S3C_HSOTG_EPS; epno++) {
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
static irqreturn_t s3c_hsotg_irq(int irq, void *pw)
{
struct s3c_hsotg *hsotg = pw;
int retry_count = 8;
u32 gintsts;
u32 gintmsk;
irq_retry:
gintsts = readl(hsotg->regs + S3C_GINTSTS);
gintmsk = readl(hsotg->regs + S3C_GINTMSK);
dev_dbg(hsotg->dev, "%s: %08x %08x (%08x) retry %d\n",
__func__, gintsts, gintsts & gintmsk, gintmsk, retry_count);
gintsts &= gintmsk;
if (gintsts & S3C_GINTSTS_OTGInt) {
u32 otgint = readl(hsotg->regs + S3C_GOTGINT);
dev_info(hsotg->dev, "OTGInt: %08x\n", otgint);
writel(otgint, hsotg->regs + S3C_GOTGINT);
}
if (gintsts & S3C_GINTSTS_DisconnInt) {
dev_dbg(hsotg->dev, "%s: DisconnInt\n", __func__);
writel(S3C_GINTSTS_DisconnInt, hsotg->regs + S3C_GINTSTS);
s3c_hsotg_disconnect_irq(hsotg);
}
if (gintsts & S3C_GINTSTS_SessReqInt) {
dev_dbg(hsotg->dev, "%s: SessReqInt\n", __func__);
writel(S3C_GINTSTS_SessReqInt, hsotg->regs + S3C_GINTSTS);
}
if (gintsts & S3C_GINTSTS_EnumDone) {
writel(S3C_GINTSTS_EnumDone, hsotg->regs + S3C_GINTSTS);
s3c_hsotg_irq_enumdone(hsotg);
}
if (gintsts & S3C_GINTSTS_ConIDStsChng) {
dev_dbg(hsotg->dev, "ConIDStsChg (DSTS=0x%08x, GOTCTL=%08x)\n",
readl(hsotg->regs + S3C_DSTS),
readl(hsotg->regs + S3C_GOTGCTL));
writel(S3C_GINTSTS_ConIDStsChng, hsotg->regs + S3C_GINTSTS);
}
if (gintsts & (S3C_GINTSTS_OEPInt | S3C_GINTSTS_IEPInt)) {
u32 daint = readl(hsotg->regs + S3C_DAINT);
u32 daint_out = daint >> S3C_DAINT_OutEP_SHIFT;
u32 daint_in = daint & ~(daint_out << S3C_DAINT_OutEP_SHIFT);
int ep;
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
if (gintsts & S3C_GINTSTS_USBRst) {
dev_info(hsotg->dev, "%s: USBRst\n", __func__);
dev_dbg(hsotg->dev, "GNPTXSTS=%08x\n",
readl(hsotg->regs + S3C_GNPTXSTS));
writel(S3C_GINTSTS_USBRst, hsotg->regs + S3C_GINTSTS);
kill_all_requests(hsotg, &hsotg->eps[0], -ECONNRESET, true);
s3c_hsotg_init_fifo(hsotg);
s3c_hsotg_enqueue_setup(hsotg);
}
if (gintsts & S3C_GINTSTS_NPTxFEmp) {
dev_dbg(hsotg->dev, "NPTxFEmp\n");
s3c_hsotg_disable_gsint(hsotg, S3C_GINTSTS_NPTxFEmp);
s3c_hsotg_irq_fifoempty(hsotg, false);
}
if (gintsts & S3C_GINTSTS_PTxFEmp) {
dev_dbg(hsotg->dev, "PTxFEmp\n");
s3c_hsotg_disable_gsint(hsotg, S3C_GINTSTS_PTxFEmp);
s3c_hsotg_irq_fifoempty(hsotg, true);
}
if (gintsts & S3C_GINTSTS_RxFLvl) {
s3c_hsotg_handle_rx(hsotg);
}
if (gintsts & S3C_GINTSTS_ModeMis) {
dev_warn(hsotg->dev, "warning, mode mismatch triggered\n");
writel(S3C_GINTSTS_ModeMis, hsotg->regs + S3C_GINTSTS);
}
if (gintsts & S3C_GINTSTS_USBSusp) {
dev_info(hsotg->dev, "S3C_GINTSTS_USBSusp\n");
writel(S3C_GINTSTS_USBSusp, hsotg->regs + S3C_GINTSTS);
call_gadget(hsotg, suspend);
}
if (gintsts & S3C_GINTSTS_WkUpInt) {
dev_info(hsotg->dev, "S3C_GINTSTS_WkUpIn\n");
writel(S3C_GINTSTS_WkUpInt, hsotg->regs + S3C_GINTSTS);
call_gadget(hsotg, resume);
}
if (gintsts & S3C_GINTSTS_ErlySusp) {
dev_dbg(hsotg->dev, "S3C_GINTSTS_ErlySusp\n");
writel(S3C_GINTSTS_ErlySusp, hsotg->regs + S3C_GINTSTS);
}
if (gintsts & S3C_GINTSTS_GOUTNakEff) {
dev_info(hsotg->dev, "GOUTNakEff triggered\n");
writel(S3C_DCTL_CGOUTNak, hsotg->regs + S3C_DCTL);
s3c_hsotg_dump(hsotg);
}
if (gintsts & S3C_GINTSTS_GINNakEff) {
dev_info(hsotg->dev, "GINNakEff triggered\n");
writel(S3C_DCTL_CGNPInNAK, hsotg->regs + S3C_DCTL);
s3c_hsotg_dump(hsotg);
}
if (gintsts & IRQ_RETRY_MASK && --retry_count > 0)
goto irq_retry;
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
epctrl_reg = dir_in ? S3C_DIEPCTL(index) : S3C_DOEPCTL(index);
epctrl = readl(hsotg->regs + epctrl_reg);
dev_dbg(hsotg->dev, "%s: read DxEPCTL=0x%08x from 0x%08x\n",
__func__, epctrl, epctrl_reg);
spin_lock_irqsave(&hs_ep->lock, flags);
epctrl &= ~(S3C_DxEPCTL_EPType_MASK | S3C_DxEPCTL_MPS_MASK);
epctrl |= S3C_DxEPCTL_MPS(mps);
epctrl |= S3C_DxEPCTL_USBActEp;
epctrl |= S3C_DxEPCTL_SNAK;
hs_ep->ep.maxpacket = mps;
hs_ep->periodic = 0;
switch (desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) {
case USB_ENDPOINT_XFER_ISOC:
dev_err(hsotg->dev, "no current ISOC support\n");
ret = -EINVAL;
goto out;
case USB_ENDPOINT_XFER_BULK:
epctrl |= S3C_DxEPCTL_EPType_Bulk;
break;
case USB_ENDPOINT_XFER_INT:
if (dir_in) {
hs_ep->periodic = 1;
epctrl |= S3C_DxEPCTL_TxFNum(index);
}
epctrl |= S3C_DxEPCTL_EPType_Intterupt;
break;
case USB_ENDPOINT_XFER_CONTROL:
epctrl |= S3C_DxEPCTL_EPType_Control;
break;
}
if (dir_in && hsotg->dedicated_fifos)
epctrl |= S3C_DxEPCTL_TxFNum(index);
if (index)
epctrl |= S3C_DxEPCTL_SetD0PID;
dev_dbg(hsotg->dev, "%s: write DxEPCTL=0x%08x\n",
__func__, epctrl);
writel(epctrl, hsotg->regs + epctrl_reg);
dev_dbg(hsotg->dev, "%s: read DxEPCTL=0x%08x\n",
__func__, readl(hsotg->regs + epctrl_reg));
s3c_hsotg_ctrl_epint(hsotg, index, dir_in, 1);
out:
spin_unlock_irqrestore(&hs_ep->lock, flags);
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
dev_info(hsotg->dev, "%s(ep %p)\n", __func__, ep);
if (ep == &hsotg->eps[0].ep) {
dev_err(hsotg->dev, "%s: called for ep0\n", __func__);
return -EINVAL;
}
epctrl_reg = dir_in ? S3C_DIEPCTL(index) : S3C_DOEPCTL(index);
kill_all_requests(hsotg, hs_ep, -ESHUTDOWN, false);
spin_lock_irqsave(&hs_ep->lock, flags);
ctrl = readl(hsotg->regs + epctrl_reg);
ctrl &= ~S3C_DxEPCTL_EPEna;
ctrl &= ~S3C_DxEPCTL_USBActEp;
ctrl |= S3C_DxEPCTL_SNAK;
dev_dbg(hsotg->dev, "%s: DxEPCTL=0x%08x\n", __func__, ctrl);
writel(ctrl, hsotg->regs + epctrl_reg);
s3c_hsotg_ctrl_epint(hsotg, hs_ep->index, hs_ep->dir_in, 0);
spin_unlock_irqrestore(&hs_ep->lock, flags);
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
dev_info(hs->dev, "ep_dequeue(%p,%p)\n", ep, req);
spin_lock_irqsave(&hs_ep->lock, flags);
if (!on_list(hs_ep, hs_req)) {
spin_unlock_irqrestore(&hs_ep->lock, flags);
return -EINVAL;
}
s3c_hsotg_complete_request(hs, hs_ep, hs_req, -ECONNRESET);
spin_unlock_irqrestore(&hs_ep->lock, flags);
return 0;
}
static int s3c_hsotg_ep_sethalt(struct usb_ep *ep, int value)
{
struct s3c_hsotg_ep *hs_ep = our_ep(ep);
struct s3c_hsotg *hs = hs_ep->parent;
int index = hs_ep->index;
unsigned long irqflags;
u32 epreg;
u32 epctl;
u32 xfertype;
dev_info(hs->dev, "%s(ep %p %s, %d)\n", __func__, ep, ep->name, value);
spin_lock_irqsave(&hs_ep->lock, irqflags);
epreg = S3C_DIEPCTL(index);
epctl = readl(hs->regs + epreg);
if (value) {
epctl |= S3C_DxEPCTL_Stall + S3C_DxEPCTL_SNAK;
if (epctl & S3C_DxEPCTL_EPEna)
epctl |= S3C_DxEPCTL_EPDis;
} else {
epctl &= ~S3C_DxEPCTL_Stall;
xfertype = epctl & S3C_DxEPCTL_EPType_MASK;
if (xfertype == S3C_DxEPCTL_EPType_Bulk ||
xfertype == S3C_DxEPCTL_EPType_Intterupt)
epctl |= S3C_DxEPCTL_SetD0PID;
}
writel(epctl, hs->regs + epreg);
epreg = S3C_DOEPCTL(index);
epctl = readl(hs->regs + epreg);
if (value)
epctl |= S3C_DxEPCTL_Stall;
else {
epctl &= ~S3C_DxEPCTL_Stall;
xfertype = epctl & S3C_DxEPCTL_EPType_MASK;
if (xfertype == S3C_DxEPCTL_EPType_Bulk ||
xfertype == S3C_DxEPCTL_EPType_Intterupt)
epctl |= S3C_DxEPCTL_SetD0PID;
}
writel(epctl, hs->regs + epreg);
spin_unlock_irqrestore(&hs_ep->lock, irqflags);
return 0;
}
static int s3c_hsotg_corereset(struct s3c_hsotg *hsotg)
{
int timeout;
u32 grstctl;
dev_dbg(hsotg->dev, "resetting core\n");
writel(S3C_GRSTCTL_CSftRst, hsotg->regs + S3C_GRSTCTL);
timeout = 1000;
do {
grstctl = readl(hsotg->regs + S3C_GRSTCTL);
} while ((grstctl & S3C_GRSTCTL_CSftRst) && timeout-- > 0);
if (grstctl & S3C_GRSTCTL_CSftRst) {
dev_err(hsotg->dev, "Failed to get CSftRst asserted\n");
return -EINVAL;
}
timeout = 1000;
while (1) {
u32 grstctl = readl(hsotg->regs + S3C_GRSTCTL);
if (timeout-- < 0) {
dev_info(hsotg->dev,
"%s: reset failed, GRSTCTL=%08x\n",
__func__, grstctl);
return -ETIMEDOUT;
}
if (!(grstctl & S3C_GRSTCTL_AHBIdle))
continue;
break;
}
dev_dbg(hsotg->dev, "reset successful\n");
return 0;
}
static int s3c_hsotg_start(struct usb_gadget_driver *driver,
int (*bind)(struct usb_gadget *))
{
struct s3c_hsotg *hsotg = our_hsotg;
int ret;
if (!hsotg) {
printk(KERN_ERR "%s: called with no device\n", __func__);
return -ENODEV;
}
if (!driver) {
dev_err(hsotg->dev, "%s: no driver\n", __func__);
return -EINVAL;
}
if (driver->max_speed < USB_SPEED_FULL)
dev_err(hsotg->dev, "%s: bad speed\n", __func__);
if (!bind || !driver->setup) {
dev_err(hsotg->dev, "%s: missing entry points\n", __func__);
return -EINVAL;
}
WARN_ON(hsotg->driver);
driver->driver.bus = NULL;
hsotg->driver = driver;
hsotg->gadget.dev.driver = &driver->driver;
hsotg->gadget.dev.dma_mask = hsotg->dev->dma_mask;
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
ret = device_add(&hsotg->gadget.dev);
if (ret) {
dev_err(hsotg->dev, "failed to register gadget device\n");
goto err;
}
ret = bind(&hsotg->gadget);
if (ret) {
dev_err(hsotg->dev, "failed bind %s\n", driver->driver.name);
hsotg->gadget.dev.driver = NULL;
hsotg->driver = NULL;
goto err;
}
s3c_hsotg_corereset(hsotg);
writel(S3C_GUSBCFG_PHYIf16 | S3C_GUSBCFG_TOutCal(7) |
(0x5 << 10), hsotg->regs + S3C_GUSBCFG);
s3c_hsotg_init_fifo(hsotg);
__orr32(hsotg->regs + S3C_DCTL, S3C_DCTL_SftDiscon);
writel(1 << 18 | S3C_DCFG_DevSpd_HS, hsotg->regs + S3C_DCFG);
writel(0xffffffff, hsotg->regs + S3C_GOTGINT);
writel(0xffffffff, hsotg->regs + S3C_GINTSTS);
writel(S3C_GINTSTS_DisconnInt | S3C_GINTSTS_SessReqInt |
S3C_GINTSTS_ConIDStsChng | S3C_GINTSTS_USBRst |
S3C_GINTSTS_EnumDone | S3C_GINTSTS_OTGInt |
S3C_GINTSTS_USBSusp | S3C_GINTSTS_WkUpInt |
S3C_GINTSTS_GOUTNakEff | S3C_GINTSTS_GINNakEff |
S3C_GINTSTS_ErlySusp,
hsotg->regs + S3C_GINTMSK);
if (using_dma(hsotg))
writel(S3C_GAHBCFG_GlblIntrEn | S3C_GAHBCFG_DMAEn |
S3C_GAHBCFG_HBstLen_Incr4,
hsotg->regs + S3C_GAHBCFG);
else
writel(S3C_GAHBCFG_GlblIntrEn, hsotg->regs + S3C_GAHBCFG);
writel(S3C_DIEPMSK_TimeOUTMsk | S3C_DIEPMSK_AHBErrMsk |
S3C_DIEPMSK_INTknEPMisMsk |
S3C_DIEPMSK_EPDisbldMsk | S3C_DIEPMSK_XferComplMsk |
((hsotg->dedicated_fifos) ? S3C_DIEPMSK_TxFIFOEmpty : 0),
hsotg->regs + S3C_DIEPMSK);
writel(S3C_DOEPMSK_SetupMsk | S3C_DOEPMSK_AHBErrMsk |
S3C_DOEPMSK_EPDisbldMsk |
(using_dma(hsotg) ? (S3C_DIEPMSK_XferComplMsk |
S3C_DIEPMSK_TimeOUTMsk) : 0),
hsotg->regs + S3C_DOEPMSK);
writel(0, hsotg->regs + S3C_DAINTMSK);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + S3C_DIEPCTL0),
readl(hsotg->regs + S3C_DOEPCTL0));
s3c_hsotg_en_gsint(hsotg, S3C_GINTSTS_OEPInt | S3C_GINTSTS_IEPInt);
if (!using_dma(hsotg))
s3c_hsotg_en_gsint(hsotg, S3C_GINTSTS_RxFLvl);
s3c_hsotg_ctrl_epint(hsotg, 0, 0, 1);
s3c_hsotg_ctrl_epint(hsotg, 0, 1, 1);
__orr32(hsotg->regs + S3C_DCTL, S3C_DCTL_PWROnPrgDone);
udelay(10);
__bic32(hsotg->regs + S3C_DCTL, S3C_DCTL_PWROnPrgDone);
dev_dbg(hsotg->dev, "DCTL=0x%08x\n", readl(hsotg->regs + S3C_DCTL));
writel(S3C_DxEPTSIZ_MC(1) | S3C_DxEPTSIZ_PktCnt(1) |
S3C_DxEPTSIZ_XferSize(8), hsotg->regs + DOEPTSIZ0);
writel(s3c_hsotg_ep0_mps(hsotg->eps[0].ep.maxpacket) |
S3C_DxEPCTL_CNAK | S3C_DxEPCTL_EPEna |
S3C_DxEPCTL_USBActEp,
hsotg->regs + S3C_DOEPCTL0);
writel(s3c_hsotg_ep0_mps(hsotg->eps[0].ep.maxpacket) |
S3C_DxEPCTL_USBActEp, hsotg->regs + S3C_DIEPCTL0);
s3c_hsotg_enqueue_setup(hsotg);
dev_dbg(hsotg->dev, "EP0: DIEPCTL0=0x%08x, DOEPCTL0=0x%08x\n",
readl(hsotg->regs + S3C_DIEPCTL0),
readl(hsotg->regs + S3C_DOEPCTL0));
writel(S3C_DCTL_CGOUTNak | S3C_DCTL_CGNPInNAK,
hsotg->regs + S3C_DCTL);
msleep(3);
__bic32(hsotg->regs + S3C_DCTL, S3C_DCTL_SftDiscon);
dev_info(hsotg->dev, "bound driver %s\n", driver->driver.name);
return 0;
err:
hsotg->driver = NULL;
hsotg->gadget.dev.driver = NULL;
return ret;
}
static int s3c_hsotg_stop(struct usb_gadget_driver *driver)
{
struct s3c_hsotg *hsotg = our_hsotg;
int ep;
if (!hsotg)
return -ENODEV;
if (!driver || driver != hsotg->driver || !driver->unbind)
return -EINVAL;
for (ep = 0; ep < S3C_HSOTG_EPS; ep++)
s3c_hsotg_ep_disable(&hsotg->eps[ep].ep);
call_gadget(hsotg, disconnect);
driver->unbind(&hsotg->gadget);
hsotg->driver = NULL;
hsotg->gadget.speed = USB_SPEED_UNKNOWN;
device_del(&hsotg->gadget.dev);
dev_info(hsotg->dev, "unregistered gadget driver '%s'\n",
driver->driver.name);
return 0;
}
static int s3c_hsotg_gadget_getframe(struct usb_gadget *gadget)
{
return s3c_hsotg_read_frameno(to_hsotg(gadget));
}
static void __devinit s3c_hsotg_initep(struct s3c_hsotg *hsotg,
struct s3c_hsotg_ep *hs_ep,
int epnum)
{
u32 ptxfifo;
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
spin_lock_init(&hs_ep->lock);
if (epnum)
list_add_tail(&hs_ep->ep.ep_list, &hsotg->gadget.ep_list);
hs_ep->parent = hsotg;
hs_ep->ep.name = hs_ep->name;
hs_ep->ep.maxpacket = epnum ? 512 : EP0_MPS_LIMIT;
hs_ep->ep.ops = &s3c_hsotg_ep_ops;
ptxfifo = readl(hsotg->regs + S3C_DPTXFSIZn(epnum));
hs_ep->fifo_size = S3C_DPTXFSIZn_DPTxFSize_GET(ptxfifo) * 4;
if (using_dma(hsotg)) {
u32 next = S3C_DxEPCTL_NextEp((epnum + 1) % 15);
writel(next, hsotg->regs + S3C_DIEPCTL(epnum));
writel(next, hsotg->regs + S3C_DOEPCTL(epnum));
}
}
static void s3c_hsotg_otgreset(struct s3c_hsotg *hsotg)
{
struct clk *xusbxti;
u32 pwr, osc;
pwr = readl(S3C_PHYPWR);
pwr &= ~0x19;
writel(pwr, S3C_PHYPWR);
mdelay(1);
osc = hsotg->plat->is_osc ? S3C_PHYCLK_EXT_OSC : 0;
xusbxti = clk_get(hsotg->dev, "xusbxti");
if (xusbxti && !IS_ERR(xusbxti)) {
switch (clk_get_rate(xusbxti)) {
case 12*MHZ:
osc |= S3C_PHYCLK_CLKSEL_12M;
break;
case 24*MHZ:
osc |= S3C_PHYCLK_CLKSEL_24M;
break;
default:
case 48*MHZ:
break;
}
clk_put(xusbxti);
}
writel(osc | 0x10, S3C_PHYCLK);
writel(S3C_RSTCON_PHY, S3C_RSTCON);
udelay(20);
writel(0, S3C_RSTCON);
}
static void s3c_hsotg_init(struct s3c_hsotg *hsotg)
{
u32 cfg4;
writel(S3C_DIEPMSK_TimeOUTMsk | S3C_DIEPMSK_AHBErrMsk |
S3C_DIEPMSK_EPDisbldMsk | S3C_DIEPMSK_XferComplMsk,
hsotg->regs + S3C_DIEPMSK);
writel(S3C_DOEPMSK_SetupMsk | S3C_DOEPMSK_AHBErrMsk |
S3C_DOEPMSK_EPDisbldMsk | S3C_DOEPMSK_XferComplMsk,
hsotg->regs + S3C_DOEPMSK);
writel(0, hsotg->regs + S3C_DAINTMSK);
__orr32(hsotg->regs + S3C_DCTL, S3C_DCTL_SftDiscon);
if (0) {
writel(S3C_DCTL_SGNPInNAK | S3C_DCTL_SGOUTNak,
hsotg->regs + S3C_DCTL);
}
dev_dbg(hsotg->dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(hsotg->regs + S3C_GRXFSIZ),
readl(hsotg->regs + S3C_GNPTXFSIZ));
s3c_hsotg_init_fifo(hsotg);
writel(S3C_GUSBCFG_PHYIf16 | S3C_GUSBCFG_TOutCal(7) | (0x5 << 10),
hsotg->regs + S3C_GUSBCFG);
writel(using_dma(hsotg) ? S3C_GAHBCFG_DMAEn : 0x0,
hsotg->regs + S3C_GAHBCFG);
cfg4 = readl(hsotg->regs + 0x50);
hsotg->dedicated_fifos = (cfg4 >> 25) & 1;
dev_info(hsotg->dev, "%s fifos\n",
hsotg->dedicated_fifos ? "dedicated" : "shared");
}
static void s3c_hsotg_dump(struct s3c_hsotg *hsotg)
{
#ifdef DEBUG
struct device *dev = hsotg->dev;
void __iomem *regs = hsotg->regs;
u32 val;
int idx;
dev_info(dev, "DCFG=0x%08x, DCTL=0x%08x, DIEPMSK=%08x\n",
readl(regs + S3C_DCFG), readl(regs + S3C_DCTL),
readl(regs + S3C_DIEPMSK));
dev_info(dev, "GAHBCFG=0x%08x, 0x44=0x%08x\n",
readl(regs + S3C_GAHBCFG), readl(regs + 0x44));
dev_info(dev, "GRXFSIZ=0x%08x, GNPTXFSIZ=0x%08x\n",
readl(regs + S3C_GRXFSIZ), readl(regs + S3C_GNPTXFSIZ));
for (idx = 1; idx <= 15; idx++) {
val = readl(regs + S3C_DPTXFSIZn(idx));
dev_info(dev, "DPTx[%d] FSize=%d, StAddr=0x%08x\n", idx,
val >> S3C_DPTXFSIZn_DPTxFSize_SHIFT,
val & S3C_DPTXFSIZn_DPTxFStAddr_MASK);
}
for (idx = 0; idx < 15; idx++) {
dev_info(dev,
"ep%d-in: EPCTL=0x%08x, SIZ=0x%08x, DMA=0x%08x\n", idx,
readl(regs + S3C_DIEPCTL(idx)),
readl(regs + S3C_DIEPTSIZ(idx)),
readl(regs + S3C_DIEPDMA(idx)));
val = readl(regs + S3C_DOEPCTL(idx));
dev_info(dev,
"ep%d-out: EPCTL=0x%08x, SIZ=0x%08x, DMA=0x%08x\n",
idx, readl(regs + S3C_DOEPCTL(idx)),
readl(regs + S3C_DOEPTSIZ(idx)),
readl(regs + S3C_DOEPDMA(idx)));
}
dev_info(dev, "DVBUSDIS=0x%08x, DVBUSPULSE=%08x\n",
readl(regs + S3C_DVBUSDIS), readl(regs + S3C_DVBUSPULSE));
#endif
}
static int state_show(struct seq_file *seq, void *v)
{
struct s3c_hsotg *hsotg = seq->private;
void __iomem *regs = hsotg->regs;
int idx;
seq_printf(seq, "DCFG=0x%08x, DCTL=0x%08x, DSTS=0x%08x\n",
readl(regs + S3C_DCFG),
readl(regs + S3C_DCTL),
readl(regs + S3C_DSTS));
seq_printf(seq, "DIEPMSK=0x%08x, DOEPMASK=0x%08x\n",
readl(regs + S3C_DIEPMSK), readl(regs + S3C_DOEPMSK));
seq_printf(seq, "GINTMSK=0x%08x, GINTSTS=0x%08x\n",
readl(regs + S3C_GINTMSK),
readl(regs + S3C_GINTSTS));
seq_printf(seq, "DAINTMSK=0x%08x, DAINT=0x%08x\n",
readl(regs + S3C_DAINTMSK),
readl(regs + S3C_DAINT));
seq_printf(seq, "GNPTXSTS=0x%08x, GRXSTSR=%08x\n",
readl(regs + S3C_GNPTXSTS),
readl(regs + S3C_GRXSTSR));
seq_printf(seq, "\nEndpoint status:\n");
for (idx = 0; idx < 15; idx++) {
u32 in, out;
in = readl(regs + S3C_DIEPCTL(idx));
out = readl(regs + S3C_DOEPCTL(idx));
seq_printf(seq, "ep%d: DIEPCTL=0x%08x, DOEPCTL=0x%08x",
idx, in, out);
in = readl(regs + S3C_DIEPTSIZ(idx));
out = readl(regs + S3C_DOEPTSIZ(idx));
seq_printf(seq, ", DIEPTSIZ=0x%08x, DOEPTSIZ=0x%08x",
in, out);
seq_printf(seq, "\n");
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
seq_printf(seq, "Non-periodic FIFOs:\n");
seq_printf(seq, "RXFIFO: Size %d\n", readl(regs + S3C_GRXFSIZ));
val = readl(regs + S3C_GNPTXFSIZ);
seq_printf(seq, "NPTXFIFO: Size %d, Start 0x%08x\n",
val >> S3C_GNPTXFSIZ_NPTxFDep_SHIFT,
val & S3C_GNPTXFSIZ_NPTxFStAddr_MASK);
seq_printf(seq, "\nPeriodic TXFIFOs:\n");
for (idx = 1; idx <= 15; idx++) {
val = readl(regs + S3C_DPTXFSIZn(idx));
seq_printf(seq, "\tDPTXFIFO%2d: Size %d, Start 0x%08x\n", idx,
val >> S3C_DPTXFSIZn_DPTxFSize_SHIFT,
val & S3C_DPTXFSIZn_DPTxFStAddr_MASK);
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
readl(regs + S3C_DIEPCTL(index)),
readl(regs + S3C_DOEPCTL(index)));
seq_printf(seq, "\tDIEPDMA=0x%08x, DOEPDMA=0x%08x\n",
readl(regs + S3C_DIEPDMA(index)),
readl(regs + S3C_DOEPDMA(index)));
seq_printf(seq, "\tDIEPINT=0x%08x, DOEPINT=0x%08x\n",
readl(regs + S3C_DIEPINT(index)),
readl(regs + S3C_DOEPINT(index)));
seq_printf(seq, "\tDIEPTSIZ=0x%08x, DOEPTSIZ=0x%08x\n",
readl(regs + S3C_DIEPTSIZ(index)),
readl(regs + S3C_DOEPTSIZ(index)));
seq_printf(seq, "\n");
seq_printf(seq, "mps %d\n", ep->ep.maxpacket);
seq_printf(seq, "total_data=%ld\n", ep->total_data);
seq_printf(seq, "request list (%p,%p):\n",
ep->queue.next, ep->queue.prev);
spin_lock_irqsave(&ep->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (--show_limit < 0) {
seq_printf(seq, "not showing more requests...\n");
break;
}
seq_printf(seq, "%c req %p: %d bytes @%p, ",
req == ep->req ? '*' : ' ',
req, req->req.length, req->req.buf);
seq_printf(seq, "%d done, res %d\n",
req->req.actual, req->req.status);
}
spin_unlock_irqrestore(&ep->lock, flags);
return 0;
}
static int ep_open(struct inode *inode, struct file *file)
{
return single_open(file, ep_show, inode->i_private);
}
static void __devinit s3c_hsotg_create_debug(struct s3c_hsotg *hsotg)
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
for (epidx = 0; epidx < S3C_HSOTG_EPS; epidx++) {
struct s3c_hsotg_ep *ep = &hsotg->eps[epidx];
ep->debugfs = debugfs_create_file(ep->name, 0444,
root, ep, &ep_fops);
if (IS_ERR(ep->debugfs))
dev_err(hsotg->dev, "failed to create %s debug file\n",
ep->name);
}
}
static void __devexit s3c_hsotg_delete_debug(struct s3c_hsotg *hsotg)
{
unsigned epidx;
for (epidx = 0; epidx < S3C_HSOTG_EPS; epidx++) {
struct s3c_hsotg_ep *ep = &hsotg->eps[epidx];
debugfs_remove(ep->debugfs);
}
debugfs_remove(hsotg->debug_file);
debugfs_remove(hsotg->debug_fifo);
debugfs_remove(hsotg->debug_root);
}
static void s3c_hsotg_gate(struct platform_device *pdev, bool on)
{
unsigned long flags;
u32 others;
local_irq_save(flags);
others = __raw_readl(S3C64XX_OTHERS);
if (on)
others |= S3C64XX_OTHERS_USBMASK;
else
others &= ~S3C64XX_OTHERS_USBMASK;
__raw_writel(others, S3C64XX_OTHERS);
local_irq_restore(flags);
}
static int __devinit s3c_hsotg_probe(struct platform_device *pdev)
{
struct s3c_hsotg_plat *plat = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct s3c_hsotg *hsotg;
struct resource *res;
int epnum;
int ret;
if (!plat)
plat = &s3c_hsotg_default_pdata;
hsotg = kzalloc(sizeof(struct s3c_hsotg) +
sizeof(struct s3c_hsotg_ep) * S3C_HSOTG_EPS,
GFP_KERNEL);
if (!hsotg) {
dev_err(dev, "cannot get memory\n");
return -ENOMEM;
}
hsotg->dev = dev;
hsotg->plat = plat;
hsotg->clk = clk_get(&pdev->dev, "otg");
if (IS_ERR(hsotg->clk)) {
dev_err(dev, "cannot get otg clock\n");
ret = PTR_ERR(hsotg->clk);
goto err_mem;
}
platform_set_drvdata(pdev, hsotg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "cannot find register resource 0\n");
ret = -EINVAL;
goto err_clk;
}
hsotg->regs_res = request_mem_region(res->start, resource_size(res),
dev_name(dev));
if (!hsotg->regs_res) {
dev_err(dev, "cannot reserve registers\n");
ret = -ENOENT;
goto err_clk;
}
hsotg->regs = ioremap(res->start, resource_size(res));
if (!hsotg->regs) {
dev_err(dev, "cannot map registers\n");
ret = -ENXIO;
goto err_regs_res;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "cannot find IRQ\n");
goto err_regs;
}
hsotg->irq = ret;
ret = request_irq(ret, s3c_hsotg_irq, 0, dev_name(dev), hsotg);
if (ret < 0) {
dev_err(dev, "cannot claim IRQ\n");
goto err_regs;
}
dev_info(dev, "regs %p, irq %d\n", hsotg->regs, hsotg->irq);
device_initialize(&hsotg->gadget.dev);
dev_set_name(&hsotg->gadget.dev, "gadget");
hsotg->gadget.max_speed = USB_SPEED_HIGH;
hsotg->gadget.ops = &s3c_hsotg_gadget_ops;
hsotg->gadget.name = dev_name(dev);
hsotg->gadget.dev.parent = dev;
hsotg->gadget.dev.dma_mask = dev->dma_mask;
INIT_LIST_HEAD(&hsotg->gadget.ep_list);
hsotg->gadget.ep0 = &hsotg->eps[0].ep;
hsotg->ctrl_req = s3c_hsotg_ep_alloc_request(&hsotg->eps[0].ep,
GFP_KERNEL);
if (!hsotg->ctrl_req) {
dev_err(dev, "failed to allocate ctrl req\n");
goto err_regs;
}
clk_enable(hsotg->clk);
s3c_hsotg_gate(pdev, true);
s3c_hsotg_otgreset(hsotg);
s3c_hsotg_corereset(hsotg);
s3c_hsotg_init(hsotg);
for (epnum = 0; epnum < S3C_HSOTG_EPS; epnum++)
s3c_hsotg_initep(hsotg, &hsotg->eps[epnum], epnum);
ret = usb_add_gadget_udc(&pdev->dev, &hsotg->gadget);
if (ret)
goto err_add_udc;
s3c_hsotg_create_debug(hsotg);
s3c_hsotg_dump(hsotg);
our_hsotg = hsotg;
return 0;
err_add_udc:
s3c_hsotg_gate(pdev, false);
clk_disable(hsotg->clk);
clk_put(hsotg->clk);
err_regs:
iounmap(hsotg->regs);
err_regs_res:
release_resource(hsotg->regs_res);
kfree(hsotg->regs_res);
err_clk:
clk_put(hsotg->clk);
err_mem:
kfree(hsotg);
return ret;
}
static int __devexit s3c_hsotg_remove(struct platform_device *pdev)
{
struct s3c_hsotg *hsotg = platform_get_drvdata(pdev);
usb_del_gadget_udc(&hsotg->gadget);
s3c_hsotg_delete_debug(hsotg);
usb_gadget_unregister_driver(hsotg->driver);
free_irq(hsotg->irq, hsotg);
iounmap(hsotg->regs);
release_resource(hsotg->regs_res);
kfree(hsotg->regs_res);
s3c_hsotg_gate(pdev, false);
clk_disable(hsotg->clk);
clk_put(hsotg->clk);
kfree(hsotg);
return 0;
}
