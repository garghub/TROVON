static char *type_string (u8 bmAttributes)
{
switch ((bmAttributes) & USB_ENDPOINT_XFERTYPE_MASK) {
case USB_ENDPOINT_XFER_BULK: return "bulk";
case USB_ENDPOINT_XFER_ISOC: return "iso";
case USB_ENDPOINT_XFER_INT: return "intr";
}
return "control";
}
static int
net2280_enable (struct usb_ep *_ep, const struct usb_endpoint_descriptor *desc)
{
struct net2280 *dev;
struct net2280_ep *ep;
u32 max, tmp;
unsigned long flags;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || !desc || ep->desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT)
return -EINVAL;
dev = ep->dev;
if (!dev->driver || dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
if ((desc->bEndpointAddress & 0x0f) == EP_DONTUSE)
return -EDOM;
max = usb_endpoint_maxp (desc) & 0x1fff;
if (ep->num > 4 && max > 64)
return -ERANGE;
spin_lock_irqsave (&dev->lock, flags);
_ep->maxpacket = max & 0x7ff;
ep->desc = desc;
ep->stopped = 0;
ep->wedged = 0;
ep->out_overflow = 0;
set_idx_reg (dev->regs, REG_EP_MAXPKT (dev, ep->num), max);
if (ep->dma && (max % 4) != 0 && use_dma_chaining) {
DEBUG (ep->dev, "%s, no dma for maxpacket %d\n",
ep->ep.name, ep->ep.maxpacket);
ep->dma = NULL;
}
writel ((1 << FIFO_FLUSH), &ep->regs->ep_stat);
tmp = (desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
if (tmp == USB_ENDPOINT_XFER_INT) {
if (dev->chiprev == 0100
&& dev->gadget.speed == USB_SPEED_HIGH
&& !(desc->bEndpointAddress & USB_DIR_IN))
writel ((1 << CLEAR_NAK_OUT_PACKETS_MODE),
&ep->regs->ep_rsp);
} else if (tmp == USB_ENDPOINT_XFER_BULK) {
if ((dev->gadget.speed == USB_SPEED_HIGH
&& max != 512)
|| (dev->gadget.speed == USB_SPEED_FULL
&& max > 64)) {
spin_unlock_irqrestore (&dev->lock, flags);
return -ERANGE;
}
}
ep->is_iso = (tmp == USB_ENDPOINT_XFER_ISOC) ? 1 : 0;
tmp <<= ENDPOINT_TYPE;
tmp |= desc->bEndpointAddress;
tmp |= (4 << ENDPOINT_BYTE_COUNT);
tmp |= 1 << ENDPOINT_ENABLE;
wmb ();
ep->is_in = (tmp & USB_DIR_IN) != 0;
if (!ep->is_in)
writel ((1 << SET_NAK_OUT_PACKETS), &ep->regs->ep_rsp);
else if (dev->pdev->device != 0x2280) {
writel ((1 << CLEAR_NAK_OUT_PACKETS)
| (1 << CLEAR_NAK_OUT_PACKETS_MODE), &ep->regs->ep_rsp);
}
writel (tmp, &ep->regs->ep_cfg);
if (!ep->dma) {
tmp = (1 << ep->num) | readl (&dev->regs->pciirqenb0);
writel (tmp, &dev->regs->pciirqenb0);
tmp = (1 << DATA_PACKET_RECEIVED_INTERRUPT_ENABLE)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT_ENABLE);
if (dev->pdev->device == 0x2280)
tmp |= readl (&ep->regs->ep_irqenb);
writel (tmp, &ep->regs->ep_irqenb);
} else {
tmp = (1 << (8 + ep->num));
tmp |= readl (&dev->regs->pciirqenb1);
writel (tmp, &dev->regs->pciirqenb1);
if ((desc->bEndpointAddress & USB_DIR_IN) == 0) {
tmp = (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT_ENABLE);
writel (tmp, &ep->regs->ep_irqenb);
tmp = (1 << ep->num) | readl (&dev->regs->pciirqenb0);
writel (tmp, &dev->regs->pciirqenb0);
}
}
tmp = desc->bEndpointAddress;
DEBUG (dev, "enabled %s (ep%d%s-%s) %s max %04x\n",
_ep->name, tmp & 0x0f, DIR_STRING (tmp),
type_string (desc->bmAttributes),
ep->dma ? "dma" : "pio", max);
spin_unlock_irqrestore (&dev->lock, flags);
return 0;
}
static int handshake (u32 __iomem *ptr, u32 mask, u32 done, int usec)
{
u32 result;
do {
result = readl (ptr);
if (result == ~(u32)0)
return -ENODEV;
result &= mask;
if (result == done)
return 0;
udelay (1);
usec--;
} while (usec > 0);
return -ETIMEDOUT;
}
static void ep_reset (struct net2280_regs __iomem *regs, struct net2280_ep *ep)
{
u32 tmp;
ep->desc = NULL;
INIT_LIST_HEAD (&ep->queue);
ep->ep.maxpacket = ~0;
ep->ep.ops = &net2280_ep_ops;
if (ep->dma) {
writel (0, &ep->dma->dmactl);
writel ( (1 << DMA_SCATTER_GATHER_DONE_INTERRUPT)
| (1 << DMA_TRANSACTION_DONE_INTERRUPT)
| (1 << DMA_ABORT)
, &ep->dma->dmastat);
tmp = readl (&regs->pciirqenb0);
tmp &= ~(1 << ep->num);
writel (tmp, &regs->pciirqenb0);
} else {
tmp = readl (&regs->pciirqenb1);
tmp &= ~(1 << (8 + ep->num));
writel (tmp, &regs->pciirqenb1);
}
writel (0, &ep->regs->ep_irqenb);
if (!ep->is_in || ep->dev->pdev->device == 0x2280) {
tmp = (1 << SET_NAK_OUT_PACKETS_MODE)
| (1 << SET_NAK_OUT_PACKETS)
| (1 << CLEAR_EP_HIDE_STATUS_PHASE)
| (1 << CLEAR_INTERRUPT_MODE);
} else {
tmp = (1 << CLEAR_NAK_OUT_PACKETS_MODE)
| (1 << CLEAR_NAK_OUT_PACKETS)
| (1 << CLEAR_EP_HIDE_STATUS_PHASE)
| (1 << CLEAR_INTERRUPT_MODE);
}
if (ep->num != 0) {
tmp |= (1 << CLEAR_ENDPOINT_TOGGLE)
| (1 << CLEAR_ENDPOINT_HALT);
}
writel (tmp, &ep->regs->ep_rsp);
if (ep->dev->pdev->device == 0x2280)
tmp = (1 << FIFO_OVERFLOW)
| (1 << FIFO_UNDERFLOW);
else
tmp = 0;
writel (tmp | (1 << TIMEOUT)
| (1 << USB_STALL_SENT)
| (1 << USB_IN_NAK_SENT)
| (1 << USB_IN_ACK_RCVD)
| (1 << USB_OUT_PING_NAK_SENT)
| (1 << USB_OUT_ACK_SENT)
| (1 << FIFO_FLUSH)
| (1 << SHORT_PACKET_OUT_DONE_INTERRUPT)
| (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)
| (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
| (1 << DATA_IN_TOKEN_INTERRUPT)
, &ep->regs->ep_stat);
}
static int net2280_disable (struct usb_ep *_ep)
{
struct net2280_ep *ep;
unsigned long flags;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || !ep->desc || _ep->name == ep0name)
return -EINVAL;
spin_lock_irqsave (&ep->dev->lock, flags);
nuke (ep);
ep_reset (ep->dev->regs, ep);
VDEBUG (ep->dev, "disabled %s %s\n",
ep->dma ? "dma" : "pio", _ep->name);
(void) readl (&ep->regs->ep_cfg);
if (use_dma && !ep->dma && ep->num >= 1 && ep->num <= 4)
ep->dma = &ep->dev->dma [ep->num - 1];
spin_unlock_irqrestore (&ep->dev->lock, flags);
return 0;
}
static struct usb_request *
net2280_alloc_request (struct usb_ep *_ep, gfp_t gfp_flags)
{
struct net2280_ep *ep;
struct net2280_request *req;
if (!_ep)
return NULL;
ep = container_of (_ep, struct net2280_ep, ep);
req = kzalloc(sizeof(*req), gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD (&req->queue);
if (ep->dma) {
struct net2280_dma *td;
td = pci_pool_alloc (ep->dev->requests, gfp_flags,
&req->td_dma);
if (!td) {
kfree (req);
return NULL;
}
td->dmacount = 0;
td->dmadesc = td->dmaaddr;
req->td = td;
}
return &req->req;
}
static void
net2280_free_request (struct usb_ep *_ep, struct usb_request *_req)
{
struct net2280_ep *ep;
struct net2280_request *req;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || !_req)
return;
req = container_of (_req, struct net2280_request, req);
WARN_ON (!list_empty (&req->queue));
if (req->td)
pci_pool_free (ep->dev->requests, req->td, req->td_dma);
kfree (req);
}
static void
write_fifo (struct net2280_ep *ep, struct usb_request *req)
{
struct net2280_ep_regs __iomem *regs = ep->regs;
u8 *buf;
u32 tmp;
unsigned count, total;
if (req) {
buf = req->buf + req->actual;
prefetch (buf);
total = req->length - req->actual;
} else {
total = 0;
buf = NULL;
}
count = ep->ep.maxpacket;
if (count > total)
count = total;
VDEBUG (ep->dev, "write %s fifo (IN) %d bytes%s req %p\n",
ep->ep.name, count,
(count != ep->ep.maxpacket) ? " (short)" : "",
req);
while (count >= 4) {
tmp = get_unaligned ((u32 *)buf);
cpu_to_le32s (&tmp);
writel (tmp, &regs->ep_data);
buf += 4;
count -= 4;
}
if (count || total < ep->ep.maxpacket) {
tmp = count ? get_unaligned ((u32 *)buf) : count;
cpu_to_le32s (&tmp);
set_fifo_bytecount (ep, count & 0x03);
writel (tmp, &regs->ep_data);
}
}
static void out_flush (struct net2280_ep *ep)
{
u32 __iomem *statp;
u32 tmp;
ASSERT_OUT_NAKING (ep);
statp = &ep->regs->ep_stat;
writel ( (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT)
, statp);
writel ((1 << FIFO_FLUSH), statp);
mb ();
tmp = readl (statp);
if (tmp & (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
&& ep->dev->gadget.speed == USB_SPEED_FULL) {
unsigned usec;
usec = 50;
handshake (statp, (1 << USB_OUT_PING_NAK_SENT),
(1 << USB_OUT_PING_NAK_SENT), usec);
}
}
static int
read_fifo (struct net2280_ep *ep, struct net2280_request *req)
{
struct net2280_ep_regs __iomem *regs = ep->regs;
u8 *buf = req->req.buf + req->req.actual;
unsigned count, tmp, is_short;
unsigned cleanup = 0, prevent = 0;
if (ep->dev->chiprev == 0x0100
&& ep->dev->gadget.speed == USB_SPEED_FULL) {
udelay (1);
tmp = readl (&ep->regs->ep_stat);
if ((tmp & (1 << NAK_OUT_PACKETS)))
cleanup = 1;
else if ((tmp & (1 << FIFO_FULL))) {
start_out_naking (ep);
prevent = 1;
}
}
prefetchw (buf);
count = readl (&regs->ep_avail);
if (unlikely (count == 0)) {
udelay (1);
tmp = readl (&ep->regs->ep_stat);
count = readl (&regs->ep_avail);
if (count == 0 && (tmp & (1 << NAK_OUT_PACKETS)) == 0)
return 0;
}
tmp = req->req.length - req->req.actual;
if (count > tmp) {
if ((tmp % ep->ep.maxpacket) != 0) {
ERROR (ep->dev,
"%s out fifo %d bytes, expected %d\n",
ep->ep.name, count, tmp);
req->req.status = -EOVERFLOW;
cleanup = 1;
}
count = tmp;
}
req->req.actual += count;
is_short = (count == 0) || ((count % ep->ep.maxpacket) != 0);
VDEBUG (ep->dev, "read %s fifo (OUT) %d bytes%s%s%s req %p %d/%d\n",
ep->ep.name, count, is_short ? " (short)" : "",
cleanup ? " flush" : "", prevent ? " nak" : "",
req, req->req.actual, req->req.length);
while (count >= 4) {
tmp = readl (&regs->ep_data);
cpu_to_le32s (&tmp);
put_unaligned (tmp, (u32 *)buf);
buf += 4;
count -= 4;
}
if (count) {
tmp = readl (&regs->ep_data);
do {
*buf++ = (u8) tmp;
tmp >>= 8;
} while (--count);
}
if (cleanup)
out_flush (ep);
if (prevent) {
writel ((1 << CLEAR_NAK_OUT_PACKETS), &ep->regs->ep_rsp);
(void) readl (&ep->regs->ep_rsp);
}
return is_short || ((req->req.actual == req->req.length)
&& !req->req.zero);
}
static void
fill_dma_desc (struct net2280_ep *ep, struct net2280_request *req, int valid)
{
struct net2280_dma *td = req->td;
u32 dmacount = req->req.length;
if (ep->is_in)
dmacount |= (1 << DMA_DIRECTION);
if ((!ep->is_in && (dmacount % ep->ep.maxpacket) != 0)
|| ep->dev->pdev->device != 0x2280)
dmacount |= (1 << END_OF_CHAIN);
req->valid = valid;
if (valid)
dmacount |= (1 << VALID_BIT);
if (likely(!req->req.no_interrupt || !use_dma_chaining))
dmacount |= (1 << DMA_DONE_INTERRUPT_ENABLE);
td->dmaaddr = cpu_to_le32 (req->req.dma);
wmb ();
td->dmacount = cpu_to_le32(dmacount);
}
static inline void spin_stop_dma (struct net2280_dma_regs __iomem *dma)
{
handshake (&dma->dmactl, (1 << DMA_ENABLE), 0, 50);
}
static inline void stop_dma (struct net2280_dma_regs __iomem *dma)
{
writel (readl (&dma->dmactl) & ~(1 << DMA_ENABLE), &dma->dmactl);
spin_stop_dma (dma);
}
static void start_queue (struct net2280_ep *ep, u32 dmactl, u32 td_dma)
{
struct net2280_dma_regs __iomem *dma = ep->dma;
unsigned int tmp = (1 << VALID_BIT) | (ep->is_in << DMA_DIRECTION);
if (ep->dev->pdev->device != 0x2280)
tmp |= (1 << END_OF_CHAIN);
writel (tmp, &dma->dmacount);
writel (readl (&dma->dmastat), &dma->dmastat);
writel (td_dma, &dma->dmadesc);
writel (dmactl, &dma->dmactl);
(void) readl (&ep->dev->pci->pcimstctl);
writel ((1 << DMA_START), &dma->dmastat);
if (!ep->is_in)
stop_out_naking (ep);
}
static void start_dma (struct net2280_ep *ep, struct net2280_request *req)
{
u32 tmp;
struct net2280_dma_regs __iomem *dma = ep->dma;
WARN_ON (readl (&dma->dmactl) & (1 << DMA_ENABLE));
writel (0, &ep->dma->dmactl);
if (!ep->is_in && ((tmp = readl (&ep->regs->ep_stat))
& (1 << NAK_OUT_PACKETS)) != 0) {
writel ((1 << SHORT_PACKET_TRANSFERRED_INTERRUPT),
&ep->regs->ep_stat);
tmp = readl (&ep->regs->ep_avail);
if (tmp) {
writel (readl (&dma->dmastat), &dma->dmastat);
writel (req->req.dma, &dma->dmaaddr);
tmp = min (tmp, req->req.length);
req->td->dmacount = cpu_to_le32 (req->req.length - tmp);
writel ((1 << DMA_DONE_INTERRUPT_ENABLE)
| tmp, &dma->dmacount);
req->td->dmadesc = 0;
req->valid = 1;
writel ((1 << DMA_ENABLE), &dma->dmactl);
writel ((1 << DMA_START), &dma->dmastat);
return;
}
}
tmp = dmactl_default;
if (ep->is_in) {
if (likely ((req->req.length % ep->ep.maxpacket) != 0
|| req->req.zero)) {
tmp |= (1 << DMA_FIFO_VALIDATE);
ep->in_fifo_validate = 1;
} else
ep->in_fifo_validate = 0;
}
req->td->dmadesc = cpu_to_le32 (ep->td_dma);
fill_dma_desc (ep, req, 1);
if (!use_dma_chaining)
req->td->dmacount |= cpu_to_le32 (1 << END_OF_CHAIN);
start_queue (ep, tmp, req->td_dma);
}
static inline void
queue_dma (struct net2280_ep *ep, struct net2280_request *req, int valid)
{
struct net2280_dma *end;
dma_addr_t tmp;
end = ep->dummy;
ep->dummy = req->td;
req->td = end;
tmp = ep->td_dma;
ep->td_dma = req->td_dma;
req->td_dma = tmp;
end->dmadesc = cpu_to_le32 (ep->td_dma);
fill_dma_desc (ep, req, valid);
}
static void
done (struct net2280_ep *ep, struct net2280_request *req, int status)
{
struct net2280 *dev;
unsigned stopped = ep->stopped;
list_del_init (&req->queue);
if (req->req.status == -EINPROGRESS)
req->req.status = status;
else
status = req->req.status;
dev = ep->dev;
if (ep->dma)
usb_gadget_unmap_request(&dev->gadget, &req->req, ep->is_in);
if (status && status != -ESHUTDOWN)
VDEBUG (dev, "complete %s req %p stat %d len %u/%u\n",
ep->ep.name, &req->req, status,
req->req.actual, req->req.length);
ep->stopped = 1;
spin_unlock (&dev->lock);
req->req.complete (&ep->ep, &req->req);
spin_lock (&dev->lock);
ep->stopped = stopped;
}
static int
net2280_queue (struct usb_ep *_ep, struct usb_request *_req, gfp_t gfp_flags)
{
struct net2280_request *req;
struct net2280_ep *ep;
struct net2280 *dev;
unsigned long flags;
req = container_of (_req, struct net2280_request, req);
if (!_req || !_req->complete || !_req->buf
|| !list_empty (&req->queue))
return -EINVAL;
if (_req->length > (~0 & DMA_BYTE_COUNT_MASK))
return -EDOM;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -EINVAL;
dev = ep->dev;
if (!dev->driver || dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
if (ep->dma && _req->length == 0)
return -EOPNOTSUPP;
if (ep->dma) {
int ret;
ret = usb_gadget_map_request(&dev->gadget, _req,
ep->is_in);
if (ret)
return ret;
}
#if 0
VDEBUG (dev, "%s queue req %p, len %d buf %p\n",
_ep->name, _req, _req->length, _req->buf);
#endif
spin_lock_irqsave (&dev->lock, flags);
_req->status = -EINPROGRESS;
_req->actual = 0;
if (list_empty (&ep->queue) && !ep->stopped) {
if (ep->dma)
start_dma (ep, req);
else {
if (ep->num == 0 && _req->length == 0) {
allow_status (ep);
done (ep, req, 0);
VDEBUG (dev, "%s status ack\n", ep->ep.name);
goto done;
}
if (ep->is_in)
write_fifo (ep, _req);
else if (list_empty (&ep->queue)) {
u32 s;
s = readl (&ep->regs->ep_stat);
if ((s & (1 << FIFO_EMPTY)) == 0) {
if (read_fifo (ep, req)) {
done (ep, req, 0);
if (ep->num == 0)
allow_status (ep);
req = NULL;
} else
s = readl (&ep->regs->ep_stat);
}
if (req && (s & (1 << NAK_OUT_PACKETS)))
writel ((1 << CLEAR_NAK_OUT_PACKETS),
&ep->regs->ep_rsp);
}
}
} else if (ep->dma) {
int valid = 1;
if (ep->is_in) {
int expect;
expect = likely (req->req.zero
|| (req->req.length % ep->ep.maxpacket) != 0);
if (expect != ep->in_fifo_validate)
valid = 0;
}
queue_dma (ep, req, valid);
}
ep->responded = 1;
if (req)
list_add_tail (&req->queue, &ep->queue);
done:
spin_unlock_irqrestore (&dev->lock, flags);
return 0;
}
static inline void
dma_done (
struct net2280_ep *ep,
struct net2280_request *req,
u32 dmacount,
int status
)
{
req->req.actual = req->req.length - (DMA_BYTE_COUNT_MASK & dmacount);
done (ep, req, status);
}
static void scan_dma_completions (struct net2280_ep *ep)
{
while (!list_empty (&ep->queue)) {
struct net2280_request *req;
u32 tmp;
req = list_entry (ep->queue.next,
struct net2280_request, queue);
if (!req->valid)
break;
rmb ();
tmp = le32_to_cpup (&req->td->dmacount);
if ((tmp & (1 << VALID_BIT)) != 0)
break;
if (unlikely (req->td->dmadesc == 0)) {
tmp = readl (&ep->dma->dmacount);
if (tmp & DMA_BYTE_COUNT_MASK)
break;
dma_done (ep, req, tmp, 0);
break;
} else if (!ep->is_in
&& (req->req.length % ep->ep.maxpacket) != 0) {
tmp = readl (&ep->regs->ep_stat);
if ((tmp & (1 << NAK_OUT_PACKETS)) == 0) {
WARNING (ep->dev, "%s lost packet sync!\n",
ep->ep.name);
req->req.status = -EOVERFLOW;
} else if ((tmp = readl (&ep->regs->ep_avail)) != 0) {
ep->out_overflow = 1;
DEBUG (ep->dev, "%s dma, discard %d len %d\n",
ep->ep.name, tmp,
req->req.length);
req->req.status = -EOVERFLOW;
}
}
dma_done (ep, req, tmp, 0);
}
}
static void restart_dma (struct net2280_ep *ep)
{
struct net2280_request *req;
u32 dmactl = dmactl_default;
if (ep->stopped)
return;
req = list_entry (ep->queue.next, struct net2280_request, queue);
if (!use_dma_chaining) {
start_dma (ep, req);
return;
}
if (ep->is_in && !req->valid) {
struct net2280_request *entry, *prev = NULL;
int reqmode, done = 0;
DEBUG (ep->dev, "%s dma hiccup td %p\n", ep->ep.name, req->td);
ep->in_fifo_validate = likely (req->req.zero
|| (req->req.length % ep->ep.maxpacket) != 0);
if (ep->in_fifo_validate)
dmactl |= (1 << DMA_FIFO_VALIDATE);
list_for_each_entry (entry, &ep->queue, queue) {
__le32 dmacount;
if (entry == req)
continue;
dmacount = entry->td->dmacount;
if (!done) {
reqmode = likely (entry->req.zero
|| (entry->req.length
% ep->ep.maxpacket) != 0);
if (reqmode == ep->in_fifo_validate) {
entry->valid = 1;
dmacount |= valid_bit;
entry->td->dmacount = dmacount;
prev = entry;
continue;
} else {
prev->td->dmacount |= dma_done_ie;
done = 1;
}
}
entry->valid = 0;
dmacount &= ~valid_bit;
entry->td->dmacount = dmacount;
prev = entry;
}
}
writel (0, &ep->dma->dmactl);
start_queue (ep, dmactl, req->td_dma);
}
static void abort_dma (struct net2280_ep *ep)
{
if (likely (!list_empty (&ep->queue))) {
writel ((1 << DMA_ABORT), &ep->dma->dmastat);
spin_stop_dma (ep->dma);
} else
stop_dma (ep->dma);
scan_dma_completions (ep);
}
static void nuke (struct net2280_ep *ep)
{
struct net2280_request *req;
ep->stopped = 1;
if (ep->dma)
abort_dma (ep);
while (!list_empty (&ep->queue)) {
req = list_entry (ep->queue.next,
struct net2280_request,
queue);
done (ep, req, -ESHUTDOWN);
}
}
static int net2280_dequeue (struct usb_ep *_ep, struct usb_request *_req)
{
struct net2280_ep *ep;
struct net2280_request *req;
unsigned long flags;
u32 dmactl;
int stopped;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0) || !_req)
return -EINVAL;
spin_lock_irqsave (&ep->dev->lock, flags);
stopped = ep->stopped;
dmactl = 0;
ep->stopped = 1;
if (ep->dma) {
dmactl = readl (&ep->dma->dmactl);
stop_dma (ep->dma);
scan_dma_completions (ep);
}
list_for_each_entry (req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
spin_unlock_irqrestore (&ep->dev->lock, flags);
return -EINVAL;
}
if (ep->queue.next == &req->queue) {
if (ep->dma) {
DEBUG (ep->dev, "unlink (%s) dma\n", _ep->name);
_req->status = -ECONNRESET;
abort_dma (ep);
if (likely (ep->queue.next == &req->queue)) {
req->td->dmacount = 0;
dma_done (ep, req,
readl (&ep->dma->dmacount),
-ECONNRESET);
}
} else {
DEBUG (ep->dev, "unlink (%s) pio\n", _ep->name);
done (ep, req, -ECONNRESET);
}
req = NULL;
} else if (ep->dma && use_dma_chaining) {
if (req->queue.prev == ep->queue.next) {
writel (le32_to_cpu (req->td->dmadesc),
&ep->dma->dmadesc);
if (req->td->dmacount & dma_done_ie)
writel (readl (&ep->dma->dmacount)
| le32_to_cpu(dma_done_ie),
&ep->dma->dmacount);
} else {
struct net2280_request *prev;
prev = list_entry (req->queue.prev,
struct net2280_request, queue);
prev->td->dmadesc = req->td->dmadesc;
if (req->td->dmacount & dma_done_ie)
prev->td->dmacount |= dma_done_ie;
}
}
if (req)
done (ep, req, -ECONNRESET);
ep->stopped = stopped;
if (ep->dma) {
if (list_empty (&ep->queue))
stop_dma (ep->dma);
else if (!ep->stopped) {
if (req)
writel (dmactl, &ep->dma->dmactl);
else
start_dma (ep, list_entry (ep->queue.next,
struct net2280_request, queue));
}
}
spin_unlock_irqrestore (&ep->dev->lock, flags);
return 0;
}
static int
net2280_set_halt_and_wedge(struct usb_ep *_ep, int value, int wedged)
{
struct net2280_ep *ep;
unsigned long flags;
int retval = 0;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -EINVAL;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
if (ep->desc && (ep->desc->bmAttributes & 0x03)
== USB_ENDPOINT_XFER_ISOC)
return -EINVAL;
spin_lock_irqsave (&ep->dev->lock, flags);
if (!list_empty (&ep->queue))
retval = -EAGAIN;
else if (ep->is_in && value && net2280_fifo_status (_ep) != 0)
retval = -EAGAIN;
else {
VDEBUG (ep->dev, "%s %s %s\n", _ep->name,
value ? "set" : "clear",
wedged ? "wedge" : "halt");
if (value) {
if (ep->num == 0)
ep->dev->protocol_stall = 1;
else
set_halt (ep);
if (wedged)
ep->wedged = 1;
} else {
clear_halt (ep);
ep->wedged = 0;
}
(void) readl (&ep->regs->ep_rsp);
}
spin_unlock_irqrestore (&ep->dev->lock, flags);
return retval;
}
static int
net2280_set_halt(struct usb_ep *_ep, int value)
{
return net2280_set_halt_and_wedge(_ep, value, 0);
}
static int
net2280_set_wedge(struct usb_ep *_ep)
{
if (!_ep || _ep->name == ep0name)
return -EINVAL;
return net2280_set_halt_and_wedge(_ep, 1, 1);
}
static int
net2280_fifo_status (struct usb_ep *_ep)
{
struct net2280_ep *ep;
u32 avail;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -ENODEV;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
avail = readl (&ep->regs->ep_avail) & ((1 << 12) - 1);
if (avail > ep->fifo_size)
return -EOVERFLOW;
if (ep->is_in)
avail = ep->fifo_size - avail;
return avail;
}
static void
net2280_fifo_flush (struct usb_ep *_ep)
{
struct net2280_ep *ep;
ep = container_of (_ep, struct net2280_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return;
writel ((1 << FIFO_FLUSH), &ep->regs->ep_stat);
(void) readl (&ep->regs->ep_rsp);
}
static int net2280_get_frame (struct usb_gadget *_gadget)
{
struct net2280 *dev;
unsigned long flags;
u16 retval;
if (!_gadget)
return -ENODEV;
dev = container_of (_gadget, struct net2280, gadget);
spin_lock_irqsave (&dev->lock, flags);
retval = get_idx_reg (dev->regs, REG_FRAME) & 0x03ff;
spin_unlock_irqrestore (&dev->lock, flags);
return retval;
}
static int net2280_wakeup (struct usb_gadget *_gadget)
{
struct net2280 *dev;
u32 tmp;
unsigned long flags;
if (!_gadget)
return 0;
dev = container_of (_gadget, struct net2280, gadget);
spin_lock_irqsave (&dev->lock, flags);
tmp = readl (&dev->usb->usbctl);
if (tmp & (1 << DEVICE_REMOTE_WAKEUP_ENABLE))
writel (1 << GENERATE_RESUME, &dev->usb->usbstat);
spin_unlock_irqrestore (&dev->lock, flags);
return 0;
}
static int net2280_set_selfpowered (struct usb_gadget *_gadget, int value)
{
struct net2280 *dev;
u32 tmp;
unsigned long flags;
if (!_gadget)
return 0;
dev = container_of (_gadget, struct net2280, gadget);
spin_lock_irqsave (&dev->lock, flags);
tmp = readl (&dev->usb->usbctl);
if (value)
tmp |= (1 << SELF_POWERED_STATUS);
else
tmp &= ~(1 << SELF_POWERED_STATUS);
writel (tmp, &dev->usb->usbctl);
spin_unlock_irqrestore (&dev->lock, flags);
return 0;
}
static int net2280_pullup(struct usb_gadget *_gadget, int is_on)
{
struct net2280 *dev;
u32 tmp;
unsigned long flags;
if (!_gadget)
return -ENODEV;
dev = container_of (_gadget, struct net2280, gadget);
spin_lock_irqsave (&dev->lock, flags);
tmp = readl (&dev->usb->usbctl);
dev->softconnect = (is_on != 0);
if (is_on)
tmp |= (1 << USB_DETECT_ENABLE);
else
tmp &= ~(1 << USB_DETECT_ENABLE);
writel (tmp, &dev->usb->usbctl);
spin_unlock_irqrestore (&dev->lock, flags);
return 0;
}
static ssize_t function_show(struct device *_dev, struct device_attribute *attr,
char *buf)
{
struct net2280 *dev = dev_get_drvdata (_dev);
if (!dev->driver
|| !dev->driver->function
|| strlen (dev->driver->function) > PAGE_SIZE)
return 0;
return scnprintf (buf, PAGE_SIZE, "%s\n", dev->driver->function);
}
static ssize_t registers_show(struct device *_dev,
struct device_attribute *attr, char *buf)
{
struct net2280 *dev;
char *next;
unsigned size, t;
unsigned long flags;
int i;
u32 t1, t2;
const char *s;
dev = dev_get_drvdata (_dev);
next = buf;
size = PAGE_SIZE;
spin_lock_irqsave (&dev->lock, flags);
if (dev->driver)
s = dev->driver->driver.name;
else
s = "(none)";
t = scnprintf (next, size, "%s version " DRIVER_VERSION
", chiprev %04x, dma %s\n\n"
"devinit %03x fifoctl %08x gadget '%s'\n"
"pci irqenb0 %02x irqenb1 %08x "
"irqstat0 %04x irqstat1 %08x\n",
driver_name, dev->chiprev,
use_dma
? (use_dma_chaining ? "chaining" : "enabled")
: "disabled",
readl (&dev->regs->devinit),
readl (&dev->regs->fifoctl),
s,
readl (&dev->regs->pciirqenb0),
readl (&dev->regs->pciirqenb1),
readl (&dev->regs->irqstat0),
readl (&dev->regs->irqstat1));
size -= t;
next += t;
t1 = readl (&dev->usb->usbctl);
t2 = readl (&dev->usb->usbstat);
if (t1 & (1 << VBUS_PIN)) {
if (t2 & (1 << HIGH_SPEED))
s = "high speed";
else if (dev->gadget.speed == USB_SPEED_UNKNOWN)
s = "powered";
else
s = "full speed";
} else
s = "not attached";
t = scnprintf (next, size,
"stdrsp %08x usbctl %08x usbstat %08x "
"addr 0x%02x (%s)\n",
readl (&dev->usb->stdrsp), t1, t2,
readl (&dev->usb->ouraddr), s);
size -= t;
next += t;
for (i = 0; i < 7; i++) {
struct net2280_ep *ep;
ep = &dev->ep [i];
if (i && !ep->desc)
continue;
t1 = readl (&ep->regs->ep_cfg);
t2 = readl (&ep->regs->ep_rsp) & 0xff;
t = scnprintf (next, size,
"\n%s\tcfg %05x rsp (%02x) %s%s%s%s%s%s%s%s"
"irqenb %02x\n",
ep->ep.name, t1, t2,
(t2 & (1 << CLEAR_NAK_OUT_PACKETS))
? "NAK " : "",
(t2 & (1 << CLEAR_EP_HIDE_STATUS_PHASE))
? "hide " : "",
(t2 & (1 << CLEAR_EP_FORCE_CRC_ERROR))
? "CRC " : "",
(t2 & (1 << CLEAR_INTERRUPT_MODE))
? "interrupt " : "",
(t2 & (1<<CLEAR_CONTROL_STATUS_PHASE_HANDSHAKE))
? "status " : "",
(t2 & (1 << CLEAR_NAK_OUT_PACKETS_MODE))
? "NAKmode " : "",
(t2 & (1 << CLEAR_ENDPOINT_TOGGLE))
? "DATA1 " : "DATA0 ",
(t2 & (1 << CLEAR_ENDPOINT_HALT))
? "HALT " : "",
readl (&ep->regs->ep_irqenb));
size -= t;
next += t;
t = scnprintf (next, size,
"\tstat %08x avail %04x "
"(ep%d%s-%s)%s\n",
readl (&ep->regs->ep_stat),
readl (&ep->regs->ep_avail),
t1 & 0x0f, DIR_STRING (t1),
type_string (t1 >> 8),
ep->stopped ? "*" : "");
size -= t;
next += t;
if (!ep->dma)
continue;
t = scnprintf (next, size,
" dma\tctl %08x stat %08x count %08x\n"
"\taddr %08x desc %08x\n",
readl (&ep->dma->dmactl),
readl (&ep->dma->dmastat),
readl (&ep->dma->dmacount),
readl (&ep->dma->dmaaddr),
readl (&ep->dma->dmadesc));
size -= t;
next += t;
}
t = scnprintf (next, size, "\nirqs: ");
size -= t;
next += t;
for (i = 0; i < 7; i++) {
struct net2280_ep *ep;
ep = &dev->ep [i];
if (i && !ep->irqs)
continue;
t = scnprintf (next, size, " %s/%lu", ep->ep.name, ep->irqs);
size -= t;
next += t;
}
t = scnprintf (next, size, "\n");
size -= t;
next += t;
spin_unlock_irqrestore (&dev->lock, flags);
return PAGE_SIZE - size;
}
static ssize_t queues_show(struct device *_dev, struct device_attribute *attr,
char *buf)
{
struct net2280 *dev;
char *next;
unsigned size;
unsigned long flags;
int i;
dev = dev_get_drvdata (_dev);
next = buf;
size = PAGE_SIZE;
spin_lock_irqsave (&dev->lock, flags);
for (i = 0; i < 7; i++) {
struct net2280_ep *ep = &dev->ep [i];
struct net2280_request *req;
int t;
if (i != 0) {
const struct usb_endpoint_descriptor *d;
d = ep->desc;
if (!d)
continue;
t = d->bEndpointAddress;
t = scnprintf (next, size,
"\n%s (ep%d%s-%s) max %04x %s fifo %d\n",
ep->ep.name, t & USB_ENDPOINT_NUMBER_MASK,
(t & USB_DIR_IN) ? "in" : "out",
({ char *val;
switch (d->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_BULK:
val = "bulk"; break;
case USB_ENDPOINT_XFER_INT:
val = "intr"; break;
default:
val = "iso"; break;
} val; }),
usb_endpoint_maxp (d) & 0x1fff,
ep->dma ? "dma" : "pio", ep->fifo_size
);
} else
t = scnprintf (next, size, "ep0 max 64 pio %s\n",
ep->is_in ? "in" : "out");
if (t <= 0 || t > size)
goto done;
size -= t;
next += t;
if (list_empty (&ep->queue)) {
t = scnprintf (next, size, "\t(nothing queued)\n");
if (t <= 0 || t > size)
goto done;
size -= t;
next += t;
continue;
}
list_for_each_entry (req, &ep->queue, queue) {
if (ep->dma && req->td_dma == readl (&ep->dma->dmadesc))
t = scnprintf (next, size,
"\treq %p len %d/%d "
"buf %p (dmacount %08x)\n",
&req->req, req->req.actual,
req->req.length, req->req.buf,
readl (&ep->dma->dmacount));
else
t = scnprintf (next, size,
"\treq %p len %d/%d buf %p\n",
&req->req, req->req.actual,
req->req.length, req->req.buf);
if (t <= 0 || t > size)
goto done;
size -= t;
next += t;
if (ep->dma) {
struct net2280_dma *td;
td = req->td;
t = scnprintf (next, size, "\t td %08x "
" count %08x buf %08x desc %08x\n",
(u32) req->td_dma,
le32_to_cpu (td->dmacount),
le32_to_cpu (td->dmaaddr),
le32_to_cpu (td->dmadesc));
if (t <= 0 || t > size)
goto done;
size -= t;
next += t;
}
}
}
done:
spin_unlock_irqrestore (&dev->lock, flags);
return PAGE_SIZE - size;
}
static void set_fifo_mode (struct net2280 *dev, int mode)
{
writel ((0xffff << PCI_BASE2_RANGE) | mode, &dev->regs->fifoctl);
INIT_LIST_HEAD (&dev->gadget.ep_list);
list_add_tail (&dev->ep [1].ep.ep_list, &dev->gadget.ep_list);
list_add_tail (&dev->ep [2].ep.ep_list, &dev->gadget.ep_list);
switch (mode) {
case 0:
list_add_tail (&dev->ep [3].ep.ep_list, &dev->gadget.ep_list);
list_add_tail (&dev->ep [4].ep.ep_list, &dev->gadget.ep_list);
dev->ep [1].fifo_size = dev->ep [2].fifo_size = 1024;
break;
case 1:
dev->ep [1].fifo_size = dev->ep [2].fifo_size = 2048;
break;
case 2:
list_add_tail (&dev->ep [3].ep.ep_list, &dev->gadget.ep_list);
dev->ep [1].fifo_size = 2048;
dev->ep [2].fifo_size = 1024;
break;
}
list_add_tail (&dev->ep [5].ep.ep_list, &dev->gadget.ep_list);
list_add_tail (&dev->ep [6].ep.ep_list, &dev->gadget.ep_list);
}
static void usb_reset (struct net2280 *dev)
{
u32 tmp;
dev->gadget.speed = USB_SPEED_UNKNOWN;
(void) readl (&dev->usb->usbctl);
net2280_led_init (dev);
writel (0, &dev->usb->stdrsp);
writel (0, &dev->regs->pciirqenb0);
writel (0, &dev->regs->pciirqenb1);
for (tmp = 0; tmp < 4; tmp++) {
struct net2280_ep *ep = &dev->ep [tmp + 1];
if (ep->dma)
abort_dma (ep);
}
writel (~0, &dev->regs->irqstat0),
writel (~(1 << SUSPEND_REQUEST_INTERRUPT), &dev->regs->irqstat1),
tmp = readl (&dev->regs->devinit)
| (1 << PCI_ENABLE)
| (1 << FIFO_SOFT_RESET)
| (1 << USB_SOFT_RESET)
| (1 << M8051_RESET);
writel (tmp, &dev->regs->devinit);
set_fifo_mode (dev, (fifo_mode <= 2) ? fifo_mode : 0);
}
static void usb_reinit (struct net2280 *dev)
{
u32 tmp;
int init_dma;
init_dma = use_dma;
for (tmp = 0; tmp < 7; tmp++) {
struct net2280_ep *ep = &dev->ep [tmp];
ep->ep.name = ep_name [tmp];
ep->dev = dev;
ep->num = tmp;
if (tmp > 0 && tmp <= 4) {
ep->fifo_size = 1024;
if (init_dma)
ep->dma = &dev->dma [tmp - 1];
} else
ep->fifo_size = 64;
ep->regs = &dev->epregs [tmp];
ep_reset (dev->regs, ep);
}
dev->ep [0].ep.maxpacket = 64;
dev->ep [5].ep.maxpacket = 64;
dev->ep [6].ep.maxpacket = 64;
dev->gadget.ep0 = &dev->ep [0].ep;
dev->ep [0].stopped = 0;
INIT_LIST_HEAD (&dev->gadget.ep0->ep_list);
for (tmp = 0; tmp < 5; tmp++)
writel (EP_DONTUSE, &dev->dep [tmp].dep_cfg);
}
static void ep0_start (struct net2280 *dev)
{
writel ( (1 << CLEAR_EP_HIDE_STATUS_PHASE)
| (1 << CLEAR_NAK_OUT_PACKETS)
| (1 << CLEAR_CONTROL_STATUS_PHASE_HANDSHAKE)
, &dev->epregs [0].ep_rsp);
writel ( (1 << SET_TEST_MODE)
| (1 << SET_ADDRESS)
| (1 << DEVICE_SET_CLEAR_DEVICE_REMOTE_WAKEUP)
| (1 << GET_DEVICE_STATUS)
| (1 << GET_INTERFACE_STATUS)
, &dev->usb->stdrsp);
writel ( (1 << USB_ROOT_PORT_WAKEUP_ENABLE)
| (1 << SELF_POWERED_USB_DEVICE)
| (1 << REMOTE_WAKEUP_SUPPORT)
| (dev->softconnect << USB_DETECT_ENABLE)
| (1 << SELF_POWERED_STATUS)
, &dev->usb->usbctl);
writel ( (1 << SETUP_PACKET_INTERRUPT_ENABLE)
| (1 << ENDPOINT_0_INTERRUPT_ENABLE)
, &dev->regs->pciirqenb0);
writel ( (1 << PCI_INTERRUPT_ENABLE)
| (1 << PCI_MASTER_ABORT_RECEIVED_INTERRUPT_ENABLE)
| (1 << PCI_TARGET_ABORT_RECEIVED_INTERRUPT_ENABLE)
| (1 << PCI_RETRY_ABORT_INTERRUPT_ENABLE)
| (1 << VBUS_INTERRUPT_ENABLE)
| (1 << ROOT_PORT_RESET_INTERRUPT_ENABLE)
| (1 << SUSPEND_REQUEST_CHANGE_INTERRUPT_ENABLE)
, &dev->regs->pciirqenb1);
(void) readl (&dev->usb->usbctl);
}
static int net2280_start(struct usb_gadget *_gadget,
struct usb_gadget_driver *driver)
{
struct net2280 *dev;
int retval;
unsigned i;
if (!driver || driver->max_speed < USB_SPEED_HIGH
|| !driver->setup)
return -EINVAL;
dev = container_of (_gadget, struct net2280, gadget);
for (i = 0; i < 7; i++)
dev->ep [i].irqs = 0;
dev->softconnect = 1;
driver->driver.bus = NULL;
dev->driver = driver;
retval = device_create_file (&dev->pdev->dev, &dev_attr_function);
if (retval) goto err_unbind;
retval = device_create_file (&dev->pdev->dev, &dev_attr_queues);
if (retval) goto err_func;
if (full_speed)
writel(1 << FORCE_FULL_SPEED_MODE, &dev->usb->xcvrdiag);
net2280_led_active (dev, 1);
ep0_start (dev);
DEBUG (dev, "%s ready, usbctl %08x stdrsp %08x\n",
driver->driver.name,
readl (&dev->usb->usbctl),
readl (&dev->usb->stdrsp));
return 0;
err_func:
device_remove_file (&dev->pdev->dev, &dev_attr_function);
err_unbind:
dev->driver = NULL;
return retval;
}
static void
stop_activity (struct net2280 *dev, struct usb_gadget_driver *driver)
{
int i;
if (dev->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
usb_reset (dev);
for (i = 0; i < 7; i++)
nuke (&dev->ep [i]);
if (driver) {
spin_unlock(&dev->lock);
driver->disconnect(&dev->gadget);
spin_lock(&dev->lock);
}
usb_reinit (dev);
}
static int net2280_stop(struct usb_gadget *_gadget,
struct usb_gadget_driver *driver)
{
struct net2280 *dev;
unsigned long flags;
dev = container_of (_gadget, struct net2280, gadget);
spin_lock_irqsave (&dev->lock, flags);
stop_activity (dev, driver);
spin_unlock_irqrestore (&dev->lock, flags);
dev->driver = NULL;
net2280_led_active (dev, 0);
writel(0, &dev->usb->xcvrdiag);
device_remove_file (&dev->pdev->dev, &dev_attr_function);
device_remove_file (&dev->pdev->dev, &dev_attr_queues);
DEBUG (dev, "unregistered driver '%s'\n", driver->driver.name);
return 0;
}
static void handle_ep_small (struct net2280_ep *ep)
{
struct net2280_request *req;
u32 t;
int mode = 1;
if (!list_empty (&ep->queue))
req = list_entry (ep->queue.next,
struct net2280_request, queue);
else
req = NULL;
t = readl (&ep->regs->ep_stat);
ep->irqs++;
#if 0
VDEBUG (ep->dev, "%s ack ep_stat %08x, req %p\n",
ep->ep.name, t, req ? &req->req : 0);
#endif
if (!ep->is_in || ep->dev->pdev->device == 0x2280)
writel (t & ~(1 << NAK_OUT_PACKETS), &ep->regs->ep_stat);
else
writel (t, &ep->regs->ep_stat);
if (unlikely (ep->num == 0)) {
if (ep->is_in) {
if (t & (1 << DATA_OUT_PING_TOKEN_INTERRUPT)) {
if (ep->dev->protocol_stall) {
ep->stopped = 1;
set_halt (ep);
}
if (!req)
allow_status (ep);
mode = 2;
} else if (t & (1 << DATA_IN_TOKEN_INTERRUPT)) {
if (ep->dev->protocol_stall) {
ep->stopped = 1;
set_halt (ep);
mode = 2;
} else if (ep->responded &&
!req && !ep->stopped)
write_fifo (ep, NULL);
}
} else {
if (t & (1 << DATA_IN_TOKEN_INTERRUPT)) {
if (ep->dev->protocol_stall) {
ep->stopped = 1;
set_halt (ep);
}
mode = 2;
} else if (((t & (1 << DATA_OUT_PING_TOKEN_INTERRUPT))
&& req
&& req->req.actual == req->req.length)
|| (ep->responded && !req)) {
ep->dev->protocol_stall = 1;
set_halt (ep);
ep->stopped = 1;
if (req)
done (ep, req, -EOVERFLOW);
req = NULL;
}
}
}
if (unlikely (!req))
return;
if (likely (ep->dma)) {
if (t & (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT)) {
u32 count;
int stopped = ep->stopped;
ep->stopped = 1;
for (count = 0; ; t = readl (&ep->regs->ep_stat)) {
scan_dma_completions (ep);
if (unlikely (list_empty (&ep->queue)
|| ep->out_overflow)) {
req = NULL;
break;
}
req = list_entry (ep->queue.next,
struct net2280_request, queue);
if (likely (t & (1 << FIFO_EMPTY))) {
count = readl (&ep->dma->dmacount);
count &= DMA_BYTE_COUNT_MASK;
if (readl (&ep->dma->dmadesc)
!= req->td_dma)
req = NULL;
break;
}
udelay(1);
}
writel ((1 << DMA_ABORT), &ep->dma->dmastat);
spin_stop_dma (ep->dma);
if (likely (req)) {
req->td->dmacount = 0;
t = readl (&ep->regs->ep_avail);
dma_done (ep, req, count,
(ep->out_overflow || t)
? -EOVERFLOW : 0);
}
if (unlikely (ep->out_overflow
|| (ep->dev->chiprev == 0x0100
&& ep->dev->gadget.speed
== USB_SPEED_FULL))) {
out_flush (ep);
ep->out_overflow = 0;
}
ep->stopped = stopped;
if (!list_empty (&ep->queue))
restart_dma (ep);
} else
DEBUG (ep->dev, "%s dma ep_stat %08x ??\n",
ep->ep.name, t);
return;
} else if (t & (1 << DATA_PACKET_RECEIVED_INTERRUPT)) {
if (read_fifo (ep, req) && ep->num != 0)
mode = 2;
} else if (t & (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)) {
unsigned len;
len = req->req.length - req->req.actual;
if (len > ep->ep.maxpacket)
len = ep->ep.maxpacket;
req->req.actual += len;
if (req->req.actual == req->req.length) {
if (ep->num == 0) {
} else if (!req->req.zero || len != ep->ep.maxpacket)
mode = 2;
}
} else if (mode == 1)
return;
if (mode == 2) {
done (ep, req, 0);
if (ep->num == 0) {
if (!ep->stopped)
allow_status (ep);
req = NULL;
} else {
if (!list_empty (&ep->queue) && !ep->stopped)
req = list_entry (ep->queue.next,
struct net2280_request, queue);
else
req = NULL;
if (req && !ep->is_in)
stop_out_naking (ep);
}
}
if (req && !ep->stopped) {
if (t & (1 << DATA_PACKET_TRANSMITTED_INTERRUPT))
write_fifo (ep, &req->req);
}
}
static struct net2280_ep *
get_ep_by_addr (struct net2280 *dev, u16 wIndex)
{
struct net2280_ep *ep;
if ((wIndex & USB_ENDPOINT_NUMBER_MASK) == 0)
return &dev->ep [0];
list_for_each_entry (ep, &dev->gadget.ep_list, ep.ep_list) {
u8 bEndpointAddress;
if (!ep->desc)
continue;
bEndpointAddress = ep->desc->bEndpointAddress;
if ((wIndex ^ bEndpointAddress) & USB_DIR_IN)
continue;
if ((wIndex & 0x0f) == (bEndpointAddress & 0x0f))
return ep;
}
return NULL;
}
static void handle_stat0_irqs (struct net2280 *dev, u32 stat)
{
struct net2280_ep *ep;
u32 num, scratch;
stat &= ~(1 << INTA_ASSERTED);
if (!stat)
return;
if (unlikely (stat & (1 << SETUP_PACKET_INTERRUPT))) {
union {
u32 raw [2];
struct usb_ctrlrequest r;
} u;
int tmp;
struct net2280_request *req;
if (dev->gadget.speed == USB_SPEED_UNKNOWN) {
if (readl (&dev->usb->usbstat) & (1 << HIGH_SPEED))
dev->gadget.speed = USB_SPEED_HIGH;
else
dev->gadget.speed = USB_SPEED_FULL;
net2280_led_speed (dev, dev->gadget.speed);
DEBUG(dev, "%s\n", usb_speed_string(dev->gadget.speed));
}
ep = &dev->ep [0];
ep->irqs++;
stat &= ~(1 << ENDPOINT_0_INTERRUPT);
while (!list_empty (&ep->queue)) {
req = list_entry (ep->queue.next,
struct net2280_request, queue);
done (ep, req, (req->req.actual == req->req.length)
? 0 : -EPROTO);
}
ep->stopped = 0;
dev->protocol_stall = 0;
if (ep->dev->pdev->device == 0x2280)
tmp = (1 << FIFO_OVERFLOW)
| (1 << FIFO_UNDERFLOW);
else
tmp = 0;
writel (tmp | (1 << TIMEOUT)
| (1 << USB_STALL_SENT)
| (1 << USB_IN_NAK_SENT)
| (1 << USB_IN_ACK_RCVD)
| (1 << USB_OUT_PING_NAK_SENT)
| (1 << USB_OUT_ACK_SENT)
| (1 << SHORT_PACKET_OUT_DONE_INTERRUPT)
| (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)
| (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
| (1 << DATA_IN_TOKEN_INTERRUPT)
, &ep->regs->ep_stat);
u.raw [0] = readl (&dev->usb->setup0123);
u.raw [1] = readl (&dev->usb->setup4567);
cpu_to_le32s (&u.raw [0]);
cpu_to_le32s (&u.raw [1]);
tmp = 0;
#define w_value le16_to_cpu(u.r.wValue)
#define w_index le16_to_cpu(u.r.wIndex)
#define w_length le16_to_cpu(u.r.wLength)
writel (1 << SETUP_PACKET_INTERRUPT, &dev->regs->irqstat0);
stat ^= (1 << SETUP_PACKET_INTERRUPT);
ep->is_in = (u.r.bRequestType & USB_DIR_IN) != 0;
if (ep->is_in) {
scratch = (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)
| (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
| (1 << DATA_IN_TOKEN_INTERRUPT);
stop_out_naking (ep);
} else
scratch = (1 << DATA_PACKET_RECEIVED_INTERRUPT)
| (1 << DATA_OUT_PING_TOKEN_INTERRUPT)
| (1 << DATA_IN_TOKEN_INTERRUPT);
writel (scratch, &dev->epregs [0].ep_irqenb);
ep->responded = 1;
switch (u.r.bRequest) {
case USB_REQ_GET_STATUS: {
struct net2280_ep *e;
__le32 status;
if (u.r.bRequestType != (USB_DIR_IN|USB_RECIP_ENDPOINT))
goto delegate;
if ((e = get_ep_by_addr (dev, w_index)) == NULL
|| w_length > 2)
goto do_stall;
if (readl (&e->regs->ep_rsp)
& (1 << SET_ENDPOINT_HALT))
status = cpu_to_le32 (1);
else
status = cpu_to_le32 (0);
writel (0, &dev->epregs [0].ep_irqenb);
set_fifo_bytecount (ep, w_length);
writel ((__force u32)status, &dev->epregs [0].ep_data);
allow_status (ep);
VDEBUG (dev, "%s stat %02x\n", ep->ep.name, status);
goto next_endpoints;
}
break;
case USB_REQ_CLEAR_FEATURE: {
struct net2280_ep *e;
if (u.r.bRequestType != USB_RECIP_ENDPOINT)
goto delegate;
if (w_value != USB_ENDPOINT_HALT
|| w_length != 0)
goto do_stall;
if ((e = get_ep_by_addr (dev, w_index)) == NULL)
goto do_stall;
if (e->wedged) {
VDEBUG(dev, "%s wedged, halt not cleared\n",
ep->ep.name);
} else {
VDEBUG(dev, "%s clear halt\n", ep->ep.name);
clear_halt(e);
}
allow_status (ep);
goto next_endpoints;
}
break;
case USB_REQ_SET_FEATURE: {
struct net2280_ep *e;
if (u.r.bRequestType != USB_RECIP_ENDPOINT)
goto delegate;
if (w_value != USB_ENDPOINT_HALT
|| w_length != 0)
goto do_stall;
if ((e = get_ep_by_addr (dev, w_index)) == NULL)
goto do_stall;
if (e->ep.name == ep0name)
goto do_stall;
set_halt (e);
allow_status (ep);
VDEBUG (dev, "%s set halt\n", ep->ep.name);
goto next_endpoints;
}
break;
default:
delegate:
VDEBUG (dev, "setup %02x.%02x v%04x i%04x l%04x "
"ep_cfg %08x\n",
u.r.bRequestType, u.r.bRequest,
w_value, w_index, w_length,
readl (&ep->regs->ep_cfg));
ep->responded = 0;
spin_unlock (&dev->lock);
tmp = dev->driver->setup (&dev->gadget, &u.r);
spin_lock (&dev->lock);
}
if (tmp < 0) {
do_stall:
VDEBUG (dev, "req %02x.%02x protocol STALL; stat %d\n",
u.r.bRequestType, u.r.bRequest, tmp);
dev->protocol_stall = 1;
}
}
#undef w_value
#undef w_index
#undef w_length
next_endpoints:
scratch = stat & 0x7f;
stat &= ~0x7f;
for (num = 0; scratch; num++) {
u32 t;
t = 1 << num;
if ((scratch & t) == 0)
continue;
scratch ^= t;
ep = &dev->ep [num];
handle_ep_small (ep);
}
if (stat)
DEBUG (dev, "unhandled irqstat0 %08x\n", stat);
}
static void handle_stat1_irqs (struct net2280 *dev, u32 stat)
{
struct net2280_ep *ep;
u32 tmp, num, mask, scratch;
tmp = (1 << VBUS_INTERRUPT) | (1 << ROOT_PORT_RESET_INTERRUPT);
mask = (1 << HIGH_SPEED) | (1 << FULL_SPEED);
if (stat & tmp) {
writel (tmp, &dev->regs->irqstat1);
if ((((stat & (1 << ROOT_PORT_RESET_INTERRUPT))
&& ((readl (&dev->usb->usbstat) & mask)
== 0))
|| ((readl (&dev->usb->usbctl)
& (1 << VBUS_PIN)) == 0)
) && ( dev->gadget.speed != USB_SPEED_UNKNOWN)) {
DEBUG (dev, "disconnect %s\n",
dev->driver->driver.name);
stop_activity (dev, dev->driver);
ep0_start (dev);
return;
}
stat &= ~tmp;
if (!stat)
return;
}
tmp = (1 << SUSPEND_REQUEST_CHANGE_INTERRUPT);
if (stat & tmp) {
writel (tmp, &dev->regs->irqstat1);
if (stat & (1 << SUSPEND_REQUEST_INTERRUPT)) {
if (dev->driver->suspend)
dev->driver->suspend (&dev->gadget);
if (!enable_suspend)
stat &= ~(1 << SUSPEND_REQUEST_INTERRUPT);
} else {
if (dev->driver->resume)
dev->driver->resume (&dev->gadget);
}
stat &= ~tmp;
}
if (stat)
writel (stat, &dev->regs->irqstat1);
if (dev->pdev->device == 0x2280)
stat &= ~((1 << CONTROL_STATUS_INTERRUPT)
| (1 << SUSPEND_REQUEST_INTERRUPT)
| (1 << RESUME_INTERRUPT)
| (1 << SOF_INTERRUPT));
else
stat &= ~((1 << CONTROL_STATUS_INTERRUPT)
| (1 << RESUME_INTERRUPT)
| (1 << SOF_DOWN_INTERRUPT)
| (1 << SOF_INTERRUPT));
if (!stat)
return;
scratch = stat & DMA_INTERRUPTS;
stat &= ~DMA_INTERRUPTS;
scratch >>= 9;
for (num = 0; scratch; num++) {
struct net2280_dma_regs __iomem *dma;
tmp = 1 << num;
if ((tmp & scratch) == 0)
continue;
scratch ^= tmp;
ep = &dev->ep [num + 1];
dma = ep->dma;
if (!dma)
continue;
tmp = readl (&dma->dmastat);
writel (tmp, &dma->dmastat);
if (!use_dma_chaining) {
if ((tmp & (1 << DMA_TRANSACTION_DONE_INTERRUPT))
== 0) {
DEBUG (ep->dev, "%s no xact done? %08x\n",
ep->ep.name, tmp);
continue;
}
stop_dma (ep->dma);
}
scan_dma_completions (ep);
if (list_empty (&ep->queue)) {
if (use_dma_chaining)
stop_dma (ep->dma);
} else {
tmp = readl (&dma->dmactl);
if (!use_dma_chaining
|| (tmp & (1 << DMA_ENABLE)) == 0)
restart_dma (ep);
else if (ep->is_in && use_dma_chaining) {
struct net2280_request *req;
__le32 dmacount;
req = list_entry (ep->queue.next,
struct net2280_request, queue);
dmacount = req->td->dmacount;
dmacount &= cpu_to_le32 (
(1 << VALID_BIT)
| DMA_BYTE_COUNT_MASK);
if (dmacount && (dmacount & valid_bit) == 0)
restart_dma (ep);
}
}
ep->irqs++;
}
if (stat & PCI_ERROR_INTERRUPTS) {
ERROR (dev, "pci dma error; stat %08x\n", stat);
stat &= ~PCI_ERROR_INTERRUPTS;
stop_activity (dev, dev->driver);
ep0_start (dev);
stat = 0;
}
if (stat)
DEBUG (dev, "unhandled irqstat1 %08x\n", stat);
}
static irqreturn_t net2280_irq (int irq, void *_dev)
{
struct net2280 *dev = _dev;
if (!(readl(&dev->regs->irqstat0) & (1 << INTA_ASSERTED)))
return IRQ_NONE;
spin_lock (&dev->lock);
handle_stat1_irqs (dev, readl (&dev->regs->irqstat1));
handle_stat0_irqs (dev, readl (&dev->regs->irqstat0));
spin_unlock (&dev->lock);
return IRQ_HANDLED;
}
static void gadget_release (struct device *_dev)
{
struct net2280 *dev = dev_get_drvdata (_dev);
kfree (dev);
}
static void net2280_remove (struct pci_dev *pdev)
{
struct net2280 *dev = pci_get_drvdata (pdev);
usb_del_gadget_udc(&dev->gadget);
BUG_ON(dev->driver);
net2280_led_shutdown (dev);
if (dev->requests) {
int i;
for (i = 1; i < 5; i++) {
if (!dev->ep [i].dummy)
continue;
pci_pool_free (dev->requests, dev->ep [i].dummy,
dev->ep [i].td_dma);
}
pci_pool_destroy (dev->requests);
}
if (dev->got_irq)
free_irq (pdev->irq, dev);
if (dev->regs)
iounmap (dev->regs);
if (dev->region)
release_mem_region (pci_resource_start (pdev, 0),
pci_resource_len (pdev, 0));
if (dev->enabled)
pci_disable_device (pdev);
device_remove_file (&pdev->dev, &dev_attr_registers);
INFO (dev, "unbind\n");
}
static int net2280_probe (struct pci_dev *pdev, const struct pci_device_id *id)
{
struct net2280 *dev;
unsigned long resource, len;
void __iomem *base = NULL;
int retval, i;
dev = kzalloc (sizeof *dev, GFP_KERNEL);
if (dev == NULL){
retval = -ENOMEM;
goto done;
}
pci_set_drvdata (pdev, dev);
spin_lock_init (&dev->lock);
dev->pdev = pdev;
dev->gadget.ops = &net2280_ops;
dev->gadget.max_speed = USB_SPEED_HIGH;
dev->gadget.name = driver_name;
if (pci_enable_device (pdev) < 0) {
retval = -ENODEV;
goto done;
}
dev->enabled = 1;
resource = pci_resource_start (pdev, 0);
len = pci_resource_len (pdev, 0);
if (!request_mem_region (resource, len, driver_name)) {
DEBUG (dev, "controller already in use\n");
retval = -EBUSY;
goto done;
}
dev->region = 1;
base = ioremap_nocache (resource, len);
if (base == NULL) {
DEBUG (dev, "can't map memory\n");
retval = -EFAULT;
goto done;
}
dev->regs = (struct net2280_regs __iomem *) base;
dev->usb = (struct net2280_usb_regs __iomem *) (base + 0x0080);
dev->pci = (struct net2280_pci_regs __iomem *) (base + 0x0100);
dev->dma = (struct net2280_dma_regs __iomem *) (base + 0x0180);
dev->dep = (struct net2280_dep_regs __iomem *) (base + 0x0200);
dev->epregs = (struct net2280_ep_regs __iomem *) (base + 0x0300);
writel (0, &dev->usb->usbctl);
usb_reset (dev);
usb_reinit (dev);
if (!pdev->irq) {
ERROR (dev, "No IRQ. Check PCI setup!\n");
retval = -ENODEV;
goto done;
}
if (request_irq (pdev->irq, net2280_irq, IRQF_SHARED, driver_name, dev)
!= 0) {
ERROR (dev, "request interrupt %d failed\n", pdev->irq);
retval = -EBUSY;
goto done;
}
dev->got_irq = 1;
dev->requests = pci_pool_create ("requests", pdev,
sizeof (struct net2280_dma),
0 ,
0 );
if (!dev->requests) {
DEBUG (dev, "can't get request pool\n");
retval = -ENOMEM;
goto done;
}
for (i = 1; i < 5; i++) {
struct net2280_dma *td;
td = pci_pool_alloc (dev->requests, GFP_KERNEL,
&dev->ep [i].td_dma);
if (!td) {
DEBUG (dev, "can't get dummy %d\n", i);
retval = -ENOMEM;
goto done;
}
td->dmacount = 0;
td->dmadesc = td->dmaaddr;
dev->ep [i].dummy = td;
}
writel ( (1 << DMA_MEMORY_WRITE_AND_INVALIDATE_ENABLE)
| (1 << DMA_READ_MULTIPLE_ENABLE)
| (1 << DMA_READ_LINE_ENABLE)
, &dev->pci->pcimstctl);
pci_set_master (pdev);
pci_try_set_mwi (pdev);
dev->chiprev = get_idx_reg (dev->regs, REG_CHIPREV) & 0xffff;
INFO (dev, "%s\n", driver_desc);
INFO (dev, "irq %d, pci mem %p, chip rev %04x\n",
pdev->irq, base, dev->chiprev);
INFO (dev, "version: " DRIVER_VERSION "; dma %s\n",
use_dma
? (use_dma_chaining ? "chaining" : "enabled")
: "disabled");
retval = device_create_file (&pdev->dev, &dev_attr_registers);
if (retval) goto done;
retval = usb_add_gadget_udc_release(&pdev->dev, &dev->gadget,
gadget_release);
if (retval)
goto done;
return 0;
done:
if (dev)
net2280_remove (pdev);
return retval;
}
static void net2280_shutdown (struct pci_dev *pdev)
{
struct net2280 *dev = pci_get_drvdata (pdev);
writel (0, &dev->regs->pciirqenb0);
writel (0, &dev->regs->pciirqenb1);
writel (0, &dev->usb->usbctl);
writel(0, &dev->usb->xcvrdiag);
}
static int __init init (void)
{
if (!use_dma)
use_dma_chaining = 0;
return pci_register_driver (&net2280_pci_driver);
}
static void __exit cleanup (void)
{
pci_unregister_driver (&net2280_pci_driver);
}
