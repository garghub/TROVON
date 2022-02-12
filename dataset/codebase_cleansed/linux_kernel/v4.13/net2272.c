static void assert_out_naking(struct net2272_ep *ep, const char *where)
{
u8 tmp;
#ifndef DEBUG
return;
#endif
tmp = net2272_ep_read(ep, EP_STAT0);
if ((tmp & (1 << NAK_OUT_PACKETS)) == 0) {
dev_dbg(ep->dev->dev, "%s %s %02x !NAK\n",
ep->ep.name, where, tmp);
net2272_ep_write(ep, EP_RSPSET, 1 << ALT_NAK_OUT_PACKETS);
}
}
static void stop_out_naking(struct net2272_ep *ep)
{
u8 tmp = net2272_ep_read(ep, EP_STAT0);
if ((tmp & (1 << NAK_OUT_PACKETS)) != 0)
net2272_ep_write(ep, EP_RSPCLR, 1 << ALT_NAK_OUT_PACKETS);
}
static char *type_string(u8 bmAttributes)
{
switch ((bmAttributes) & USB_ENDPOINT_XFERTYPE_MASK) {
case USB_ENDPOINT_XFER_BULK: return "bulk";
case USB_ENDPOINT_XFER_ISOC: return "iso";
case USB_ENDPOINT_XFER_INT: return "intr";
default: return "control";
}
}
static char *buf_state_string(unsigned state)
{
switch (state) {
case BUFF_FREE: return "free";
case BUFF_VALID: return "valid";
case BUFF_LCL: return "local";
case BUFF_USB: return "usb";
default: return "unknown";
}
}
static char *dma_mode_string(void)
{
if (!use_dma)
return "PIO";
switch (dma_mode) {
case 0: return "SLOW DREQ";
case 1: return "FAST DREQ";
case 2: return "BURST";
default: return "invalid";
}
}
static int
net2272_enable(struct usb_ep *_ep, const struct usb_endpoint_descriptor *desc)
{
struct net2272 *dev;
struct net2272_ep *ep;
u32 max;
u8 tmp;
unsigned long flags;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || !desc || ep->desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT)
return -EINVAL;
dev = ep->dev;
if (!dev->driver || dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
max = usb_endpoint_maxp(desc);
spin_lock_irqsave(&dev->lock, flags);
_ep->maxpacket = max;
ep->desc = desc;
ep->stopped = 0;
ep->wedged = 0;
net2272_ep_write(ep, EP_MAXPKT0, max & 0xff);
net2272_ep_write(ep, EP_MAXPKT1, (max & 0xff00) >> 8);
net2272_ep_write(ep, EP_STAT1, 1 << BUFFER_FLUSH);
tmp = usb_endpoint_type(desc);
if (usb_endpoint_xfer_bulk(desc)) {
if ((dev->gadget.speed == USB_SPEED_HIGH && max != 512) ||
(dev->gadget.speed == USB_SPEED_FULL && max > 64)) {
spin_unlock_irqrestore(&dev->lock, flags);
return -ERANGE;
}
}
ep->is_iso = usb_endpoint_xfer_isoc(desc) ? 1 : 0;
tmp <<= ENDPOINT_TYPE;
tmp |= ((desc->bEndpointAddress & 0x0f) << ENDPOINT_NUMBER);
tmp |= usb_endpoint_dir_in(desc) << ENDPOINT_DIRECTION;
tmp |= (1 << ENDPOINT_ENABLE);
ep->is_in = usb_endpoint_dir_in(desc);
if (!ep->is_in)
net2272_ep_write(ep, EP_RSPSET, 1 << ALT_NAK_OUT_PACKETS);
net2272_ep_write(ep, EP_CFG, tmp);
tmp = (1 << ep->num) | net2272_read(dev, IRQENB0);
net2272_write(dev, IRQENB0, tmp);
tmp = (1 << DATA_PACKET_RECEIVED_INTERRUPT_ENABLE)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT_ENABLE)
| net2272_ep_read(ep, EP_IRQENB);
net2272_ep_write(ep, EP_IRQENB, tmp);
tmp = desc->bEndpointAddress;
dev_dbg(dev->dev, "enabled %s (ep%d%s-%s) max %04x cfg %02x\n",
_ep->name, tmp & 0x0f, PIPEDIR(tmp),
type_string(desc->bmAttributes), max,
net2272_ep_read(ep, EP_CFG));
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static void net2272_ep_reset(struct net2272_ep *ep)
{
u8 tmp;
ep->desc = NULL;
INIT_LIST_HEAD(&ep->queue);
usb_ep_set_maxpacket_limit(&ep->ep, ~0);
ep->ep.ops = &net2272_ep_ops;
net2272_ep_write(ep, EP_IRQENB, 0);
tmp = (1 << NAK_OUT_PACKETS_MODE) | (1 << ALT_NAK_OUT_PACKETS);
net2272_ep_write(ep, EP_RSPSET, tmp);
tmp = (1 << INTERRUPT_MODE) | (1 << HIDE_STATUS_PHASE);
if (ep->num != 0)
tmp |= (1 << ENDPOINT_TOGGLE) | (1 << ENDPOINT_HALT);
net2272_ep_write(ep, EP_RSPCLR, tmp);
net2272_ep_write(ep, EP_STAT0,
(1 << DATA_IN_TOKEN_INTERRUPT)
| (1 << DATA_OUT_TOKEN_INTERRUPT)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT)
| (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT));
net2272_ep_write(ep, EP_STAT1,
(1 << TIMEOUT)
| (1 << USB_OUT_ACK_SENT)
| (1 << USB_OUT_NAK_SENT)
| (1 << USB_IN_ACK_RCVD)
| (1 << USB_IN_NAK_SENT)
| (1 << USB_STALL_SENT)
| (1 << LOCAL_OUT_ZLP)
| (1 << BUFFER_FLUSH));
}
static int net2272_disable(struct usb_ep *_ep)
{
struct net2272_ep *ep;
unsigned long flags;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || !ep->desc || _ep->name == ep0name)
return -EINVAL;
spin_lock_irqsave(&ep->dev->lock, flags);
net2272_dequeue_all(ep);
net2272_ep_reset(ep);
dev_vdbg(ep->dev->dev, "disabled %s\n", _ep->name);
spin_unlock_irqrestore(&ep->dev->lock, flags);
return 0;
}
static struct usb_request *
net2272_alloc_request(struct usb_ep *_ep, gfp_t gfp_flags)
{
struct net2272_request *req;
if (!_ep)
return NULL;
req = kzalloc(sizeof(*req), gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD(&req->queue);
return &req->req;
}
static void
net2272_free_request(struct usb_ep *_ep, struct usb_request *_req)
{
struct net2272_request *req;
if (!_ep || !_req)
return;
req = container_of(_req, struct net2272_request, req);
WARN_ON(!list_empty(&req->queue));
kfree(req);
}
static void
net2272_done(struct net2272_ep *ep, struct net2272_request *req, int status)
{
struct net2272 *dev;
unsigned stopped = ep->stopped;
if (ep->num == 0) {
if (ep->dev->protocol_stall) {
ep->stopped = 1;
set_halt(ep);
}
allow_status(ep);
}
list_del_init(&req->queue);
if (req->req.status == -EINPROGRESS)
req->req.status = status;
else
status = req->req.status;
dev = ep->dev;
if (use_dma && ep->dma)
usb_gadget_unmap_request(&dev->gadget, &req->req,
ep->is_in);
if (status && status != -ESHUTDOWN)
dev_vdbg(dev->dev, "complete %s req %p stat %d len %u/%u buf %p\n",
ep->ep.name, &req->req, status,
req->req.actual, req->req.length, req->req.buf);
ep->stopped = 1;
spin_unlock(&dev->lock);
usb_gadget_giveback_request(&ep->ep, &req->req);
spin_lock(&dev->lock);
ep->stopped = stopped;
}
static int
net2272_write_packet(struct net2272_ep *ep, u8 *buf,
struct net2272_request *req, unsigned max)
{
u16 __iomem *ep_data = net2272_reg_addr(ep->dev, EP_DATA);
u16 *bufp;
unsigned length, count;
u8 tmp;
length = min(req->req.length - req->req.actual, max);
req->req.actual += length;
dev_vdbg(ep->dev->dev, "write packet %s req %p max %u len %u avail %u\n",
ep->ep.name, req, max, length,
(net2272_ep_read(ep, EP_AVAIL1) << 8) | net2272_ep_read(ep, EP_AVAIL0));
count = length;
bufp = (u16 *)buf;
while (likely(count >= 2)) {
writew(*bufp++, ep_data);
count -= 2;
}
buf = (u8 *)bufp;
if (unlikely(count)) {
tmp = net2272_read(ep->dev, LOCCTL);
net2272_write(ep->dev, LOCCTL, tmp & ~(1 << DATA_WIDTH));
writeb(*buf, ep_data);
net2272_write(ep->dev, LOCCTL, tmp);
}
return length;
}
static int
net2272_write_fifo(struct net2272_ep *ep, struct net2272_request *req)
{
u8 *buf;
unsigned count, max;
int status;
dev_vdbg(ep->dev->dev, "write_fifo %s actual %d len %d\n",
ep->ep.name, req->req.actual, req->req.length);
top:
net2272_ep_write(ep, EP_STAT0, (1 << DATA_PACKET_TRANSMITTED_INTERRUPT));
while (!(net2272_ep_read(ep, EP_STAT0) & (1 << BUFFER_FULL))) {
buf = req->req.buf + req->req.actual;
prefetch(buf);
net2272_ep_read(ep, EP_STAT0);
max = (net2272_ep_read(ep, EP_AVAIL1) << 8) |
(net2272_ep_read(ep, EP_AVAIL0));
if (max < ep->ep.maxpacket)
max = (net2272_ep_read(ep, EP_AVAIL1) << 8)
| (net2272_ep_read(ep, EP_AVAIL0));
count = net2272_write_packet(ep, buf, req, max);
if (req->req.length == req->req.actual) {
if (count < ep->ep.maxpacket)
set_fifo_bytecount(ep, 0);
net2272_done(ep, req, 0);
if (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct net2272_request,
queue);
status = net2272_kick_dma(ep, req);
if (status < 0)
if ((net2272_ep_read(ep, EP_STAT0)
& (1 << BUFFER_EMPTY)))
goto top;
}
return 1;
}
net2272_ep_write(ep, EP_STAT0, (1 << DATA_PACKET_TRANSMITTED_INTERRUPT));
}
return 0;
}
static void
net2272_out_flush(struct net2272_ep *ep)
{
ASSERT_OUT_NAKING(ep);
net2272_ep_write(ep, EP_STAT0, (1 << DATA_OUT_TOKEN_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT));
net2272_ep_write(ep, EP_STAT1, 1 << BUFFER_FLUSH);
}
static int
net2272_read_packet(struct net2272_ep *ep, u8 *buf,
struct net2272_request *req, unsigned avail)
{
u16 __iomem *ep_data = net2272_reg_addr(ep->dev, EP_DATA);
unsigned is_short;
u16 *bufp;
req->req.actual += avail;
dev_vdbg(ep->dev->dev, "read packet %s req %p len %u avail %u\n",
ep->ep.name, req, avail,
(net2272_ep_read(ep, EP_AVAIL1) << 8) | net2272_ep_read(ep, EP_AVAIL0));
is_short = (avail < ep->ep.maxpacket);
if (unlikely(avail == 0)) {
(void)readw(ep_data);
return is_short;
}
if (unlikely(avail % 2))
avail++;
bufp = (u16 *)buf;
do {
*bufp++ = readw(ep_data);
avail -= 2;
} while (avail);
if (net2272_ep_read(ep, EP_STAT0) & (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT))
net2272_ep_read(ep, EP_STAT0);
return is_short;
}
static int
net2272_read_fifo(struct net2272_ep *ep, struct net2272_request *req)
{
u8 *buf;
unsigned is_short;
int count;
int tmp;
int cleanup = 0;
int status = -1;
dev_vdbg(ep->dev->dev, "read_fifo %s actual %d len %d\n",
ep->ep.name, req->req.actual, req->req.length);
top:
do {
buf = req->req.buf + req->req.actual;
prefetchw(buf);
count = (net2272_ep_read(ep, EP_AVAIL1) << 8)
| net2272_ep_read(ep, EP_AVAIL0);
net2272_ep_write(ep, EP_STAT0,
(1 << SHORT_PACKET_TRANSFERRED_INTERRUPT) |
(1 << DATA_PACKET_RECEIVED_INTERRUPT));
tmp = req->req.length - req->req.actual;
if (count > tmp) {
if ((tmp % ep->ep.maxpacket) != 0) {
dev_err(ep->dev->dev,
"%s out fifo %d bytes, expected %d\n",
ep->ep.name, count, tmp);
cleanup = 1;
}
count = (tmp > 0) ? tmp : 0;
}
is_short = net2272_read_packet(ep, buf, req, count);
if (unlikely(cleanup || is_short ||
((req->req.actual == req->req.length)
&& !req->req.zero))) {
if (cleanup) {
net2272_out_flush(ep);
net2272_done(ep, req, -EOVERFLOW);
} else
net2272_done(ep, req, 0);
if (unlikely(ep->num == 0)) {
net2272_ep_write(ep, EP_TRANSFER2, 0);
net2272_ep_write(ep, EP_TRANSFER1, 0);
net2272_ep_write(ep, EP_TRANSFER0, 0);
}
if (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct net2272_request, queue);
status = net2272_kick_dma(ep, req);
if ((status < 0) &&
!(net2272_ep_read(ep, EP_STAT0) & (1 << BUFFER_EMPTY)))
goto top;
}
return 1;
}
} while (!(net2272_ep_read(ep, EP_STAT0) & (1 << BUFFER_EMPTY)));
return 0;
}
static void
net2272_pio_advance(struct net2272_ep *ep)
{
struct net2272_request *req;
if (unlikely(list_empty(&ep->queue)))
return;
req = list_entry(ep->queue.next, struct net2272_request, queue);
(ep->is_in ? net2272_write_fifo : net2272_read_fifo)(ep, req);
}
static int
net2272_request_dma(struct net2272 *dev, unsigned ep, u32 buf,
unsigned len, unsigned dir)
{
dev_vdbg(dev->dev, "request_dma ep %d buf %08x len %d dir %d\n",
ep, buf, len, dir);
if (dev->dma_busy)
return -EBUSY;
if ((dir == 1) && (len > 0x1000000))
return -EINVAL;
dev->dma_busy = 1;
#ifdef CONFIG_USB_PCI
switch (dev->dev_id) {
case PCI_DEVICE_ID_RDK1:
writel((1 << LOCAL_BUS_WIDTH) |
(1 << TA_READY_INPUT_ENABLE) |
(0 << LOCAL_BURST_ENABLE) |
(1 << DONE_INTERRUPT_ENABLE) |
(1 << LOCAL_ADDRESSING_MODE) |
(1 << DEMAND_MODE) |
(1 << DMA_EOT_ENABLE) |
(1 << FAST_SLOW_TERMINATE_MODE_SELECT) |
(1 << DMA_CHANNEL_INTERRUPT_SELECT),
dev->rdk1.plx9054_base_addr + DMAMODE0);
writel(0x100000, dev->rdk1.plx9054_base_addr + DMALADR0);
writel(buf, dev->rdk1.plx9054_base_addr + DMAPADR0);
writel(len, dev->rdk1.plx9054_base_addr + DMASIZ0);
writel((dir << DIRECTION_OF_TRANSFER) |
(1 << INTERRUPT_AFTER_TERMINAL_COUNT),
dev->rdk1.plx9054_base_addr + DMADPR0);
writel((1 << LOCAL_DMA_CHANNEL_0_INTERRUPT_ENABLE) |
readl(dev->rdk1.plx9054_base_addr + INTCSR),
dev->rdk1.plx9054_base_addr + INTCSR);
break;
}
#endif
net2272_write(dev, DMAREQ,
(0 << DMA_BUFFER_VALID) |
(1 << DMA_REQUEST_ENABLE) |
(1 << DMA_CONTROL_DACK) |
(dev->dma_eot_polarity << EOT_POLARITY) |
(dev->dma_dack_polarity << DACK_POLARITY) |
(dev->dma_dreq_polarity << DREQ_POLARITY) |
((ep >> 1) << DMA_ENDPOINT_SELECT));
(void) net2272_read(dev, SCRATCH);
return 0;
}
static void
net2272_start_dma(struct net2272 *dev)
{
#ifdef CONFIG_USB_PCI
switch (dev->dev_id) {
case PCI_DEVICE_ID_RDK1:
writeb((1 << CHANNEL_ENABLE) | (1 << CHANNEL_START),
dev->rdk1.plx9054_base_addr + DMACSR0);
break;
}
#endif
}
static int
net2272_kick_dma(struct net2272_ep *ep, struct net2272_request *req)
{
unsigned size;
u8 tmp;
if (!use_dma || (ep->num < 1) || (ep->num > 2) || !ep->dma)
return -EINVAL;
if (req->req.length & 1)
return -EINVAL;
dev_vdbg(ep->dev->dev, "kick_dma %s req %p dma %08llx\n",
ep->ep.name, req, (unsigned long long) req->req.dma);
net2272_ep_write(ep, EP_RSPSET, 1 << ALT_NAK_OUT_PACKETS);
if (ep->dev->dma_busy)
return -EBUSY;
size = req->req.length;
size &= ~1;
if (ep->is_in) {
if (net2272_request_dma(ep->dev, ep->num, req->req.dma, size, 0))
return -EBUSY;
req->req.actual += size;
} else {
tmp = net2272_ep_read(ep, EP_STAT0);
if (net2272_request_dma(ep->dev, ep->num, req->req.dma, size, 1))
return -EBUSY;
if (!(tmp & (1 << BUFFER_EMPTY)))
ep->not_empty = 1;
else
ep->not_empty = 0;
net2272_ep_write(ep, EP_RSPCLR, 1 << ALT_NAK_OUT_PACKETS);
if (tmp & (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT)) {
net2272_write(ep->dev, DMAREQ,
(0 << DMA_BUFFER_VALID) |
(0 << DMA_REQUEST_ENABLE) |
(1 << DMA_CONTROL_DACK) |
(ep->dev->dma_eot_polarity << EOT_POLARITY) |
(ep->dev->dma_dack_polarity << DACK_POLARITY) |
(ep->dev->dma_dreq_polarity << DREQ_POLARITY) |
((ep->num >> 1) << DMA_ENDPOINT_SELECT));
return -EBUSY;
}
}
net2272_ep_write(ep, EP_IRQENB, 0);
net2272_start_dma(ep->dev);
return 0;
}
static void net2272_cancel_dma(struct net2272 *dev)
{
#ifdef CONFIG_USB_PCI
switch (dev->dev_id) {
case PCI_DEVICE_ID_RDK1:
writeb(0, dev->rdk1.plx9054_base_addr + DMACSR0);
writeb(1 << CHANNEL_ABORT, dev->rdk1.plx9054_base_addr + DMACSR0);
while (!(readb(dev->rdk1.plx9054_base_addr + DMACSR0) &
(1 << CHANNEL_DONE)))
continue;
writeb(1 << CHANNEL_CLEAR_INTERRUPT,
dev->rdk1.plx9054_base_addr + DMACSR0);
break;
}
#endif
dev->dma_busy = 0;
}
static int
net2272_queue(struct usb_ep *_ep, struct usb_request *_req, gfp_t gfp_flags)
{
struct net2272_request *req;
struct net2272_ep *ep;
struct net2272 *dev;
unsigned long flags;
int status = -1;
u8 s;
req = container_of(_req, struct net2272_request, req);
if (!_req || !_req->complete || !_req->buf
|| !list_empty(&req->queue))
return -EINVAL;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -EINVAL;
dev = ep->dev;
if (!dev->driver || dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
if (use_dma && ep->dma) {
status = usb_gadget_map_request(&dev->gadget, _req,
ep->is_in);
if (status)
return status;
}
dev_vdbg(dev->dev, "%s queue req %p, len %d buf %p dma %08llx %s\n",
_ep->name, _req, _req->length, _req->buf,
(unsigned long long) _req->dma, _req->zero ? "zero" : "!zero");
spin_lock_irqsave(&dev->lock, flags);
_req->status = -EINPROGRESS;
_req->actual = 0;
if (list_empty(&ep->queue) && !ep->stopped) {
if (ep->num == 0 && _req->length == 0) {
net2272_done(ep, req, 0);
dev_vdbg(dev->dev, "%s status ack\n", ep->ep.name);
goto done;
}
s = net2272_ep_read(ep, EP_STAT0);
if (s & (1 << BUFFER_EMPTY)) {
if ((s & (1 << NAK_OUT_PACKETS)) &&
net2272_ep_read(ep, EP_STAT1) & (1 << LOCAL_OUT_ZLP)) {
dev_dbg(dev->dev, "WARNING: returning ZLP short packet termination!\n");
status = net2272_read_fifo(ep, req);
net2272_ep_write(ep, EP_STAT0, (1 << NAK_OUT_PACKETS));
goto done;
}
}
status = net2272_kick_dma(ep, req);
if (status < 0) {
status = 0;
if (ep->is_in)
status = net2272_write_fifo(ep, req);
else {
s = net2272_ep_read(ep, EP_STAT0);
if ((s & (1 << BUFFER_EMPTY)) == 0)
status = net2272_read_fifo(ep, req);
}
if (unlikely(status != 0)) {
if (status > 0)
status = 0;
req = NULL;
}
}
}
if (likely(req))
list_add_tail(&req->queue, &ep->queue);
if (likely(!list_empty(&ep->queue)))
net2272_ep_write(ep, EP_RSPCLR, 1 << ALT_NAK_OUT_PACKETS);
done:
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static void
net2272_dequeue_all(struct net2272_ep *ep)
{
struct net2272_request *req;
ep->stopped = 1;
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct net2272_request,
queue);
net2272_done(ep, req, -ESHUTDOWN);
}
}
static int
net2272_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct net2272_ep *ep;
struct net2272_request *req;
unsigned long flags;
int stopped;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0) || !_req)
return -EINVAL;
spin_lock_irqsave(&ep->dev->lock, flags);
stopped = ep->stopped;
ep->stopped = 1;
list_for_each_entry(req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
spin_unlock_irqrestore(&ep->dev->lock, flags);
return -EINVAL;
}
if (ep->queue.next == &req->queue) {
dev_dbg(ep->dev->dev, "unlink (%s) pio\n", _ep->name);
net2272_done(ep, req, -ECONNRESET);
}
req = NULL;
ep->stopped = stopped;
spin_unlock_irqrestore(&ep->dev->lock, flags);
return 0;
}
static int
net2272_set_halt_and_wedge(struct usb_ep *_ep, int value, int wedged)
{
struct net2272_ep *ep;
unsigned long flags;
int ret = 0;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -EINVAL;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
if (ep->desc && usb_endpoint_xfer_isoc(ep->desc))
return -EINVAL;
spin_lock_irqsave(&ep->dev->lock, flags);
if (!list_empty(&ep->queue))
ret = -EAGAIN;
else if (ep->is_in && value && net2272_fifo_status(_ep) != 0)
ret = -EAGAIN;
else {
dev_vdbg(ep->dev->dev, "%s %s %s\n", _ep->name,
value ? "set" : "clear",
wedged ? "wedge" : "halt");
if (value) {
if (ep->num == 0)
ep->dev->protocol_stall = 1;
else
set_halt(ep);
if (wedged)
ep->wedged = 1;
} else {
clear_halt(ep);
ep->wedged = 0;
}
}
spin_unlock_irqrestore(&ep->dev->lock, flags);
return ret;
}
static int
net2272_set_halt(struct usb_ep *_ep, int value)
{
return net2272_set_halt_and_wedge(_ep, value, 0);
}
static int
net2272_set_wedge(struct usb_ep *_ep)
{
if (!_ep || _ep->name == ep0name)
return -EINVAL;
return net2272_set_halt_and_wedge(_ep, 1, 1);
}
static int
net2272_fifo_status(struct usb_ep *_ep)
{
struct net2272_ep *ep;
u16 avail;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return -ENODEV;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
avail = net2272_ep_read(ep, EP_AVAIL1) << 8;
avail |= net2272_ep_read(ep, EP_AVAIL0);
if (avail > ep->fifo_size)
return -EOVERFLOW;
if (ep->is_in)
avail = ep->fifo_size - avail;
return avail;
}
static void
net2272_fifo_flush(struct usb_ep *_ep)
{
struct net2272_ep *ep;
ep = container_of(_ep, struct net2272_ep, ep);
if (!_ep || (!ep->desc && ep->num != 0))
return;
if (!ep->dev->driver || ep->dev->gadget.speed == USB_SPEED_UNKNOWN)
return;
net2272_ep_write(ep, EP_STAT1, 1 << BUFFER_FLUSH);
}
static int
net2272_get_frame(struct usb_gadget *_gadget)
{
struct net2272 *dev;
unsigned long flags;
u16 ret;
if (!_gadget)
return -ENODEV;
dev = container_of(_gadget, struct net2272, gadget);
spin_lock_irqsave(&dev->lock, flags);
ret = net2272_read(dev, FRAME1) << 8;
ret |= net2272_read(dev, FRAME0);
spin_unlock_irqrestore(&dev->lock, flags);
return ret;
}
static int
net2272_wakeup(struct usb_gadget *_gadget)
{
struct net2272 *dev;
u8 tmp;
unsigned long flags;
if (!_gadget)
return 0;
dev = container_of(_gadget, struct net2272, gadget);
spin_lock_irqsave(&dev->lock, flags);
tmp = net2272_read(dev, USBCTL0);
if (tmp & (1 << IO_WAKEUP_ENABLE))
net2272_write(dev, USBCTL1, (1 << GENERATE_RESUME));
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int
net2272_set_selfpowered(struct usb_gadget *_gadget, int value)
{
if (!_gadget)
return -ENODEV;
_gadget->is_selfpowered = (value != 0);
return 0;
}
static int
net2272_pullup(struct usb_gadget *_gadget, int is_on)
{
struct net2272 *dev;
u8 tmp;
unsigned long flags;
if (!_gadget)
return -ENODEV;
dev = container_of(_gadget, struct net2272, gadget);
spin_lock_irqsave(&dev->lock, flags);
tmp = net2272_read(dev, USBCTL0);
dev->softconnect = (is_on != 0);
if (is_on)
tmp |= (1 << USB_DETECT_ENABLE);
else
tmp &= ~(1 << USB_DETECT_ENABLE);
net2272_write(dev, USBCTL0, tmp);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static ssize_t
registers_show(struct device *_dev, struct device_attribute *attr, char *buf)
{
struct net2272 *dev;
char *next;
unsigned size, t;
unsigned long flags;
u8 t1, t2;
int i;
const char *s;
dev = dev_get_drvdata(_dev);
next = buf;
size = PAGE_SIZE;
spin_lock_irqsave(&dev->lock, flags);
if (dev->driver)
s = dev->driver->driver.name;
else
s = "(none)";
t = scnprintf(next, size, "%s version %s,"
"chiprev %02x, locctl %02x\n"
"irqenb0 %02x irqenb1 %02x "
"irqstat0 %02x irqstat1 %02x\n",
driver_name, driver_vers, dev->chiprev,
net2272_read(dev, LOCCTL),
net2272_read(dev, IRQENB0),
net2272_read(dev, IRQENB1),
net2272_read(dev, IRQSTAT0),
net2272_read(dev, IRQSTAT1));
size -= t;
next += t;
t1 = net2272_read(dev, DMAREQ);
t = scnprintf(next, size, "\ndmareq %02x: %s %s%s%s%s\n",
t1, ep_name[(t1 & 0x01) + 1],
t1 & (1 << DMA_CONTROL_DACK) ? "dack " : "",
t1 & (1 << DMA_REQUEST_ENABLE) ? "reqenb " : "",
t1 & (1 << DMA_REQUEST) ? "req " : "",
t1 & (1 << DMA_BUFFER_VALID) ? "valid " : "");
size -= t;
next += t;
t1 = net2272_read(dev, USBCTL1);
if (t1 & (1 << VBUS_PIN)) {
if (t1 & (1 << USB_HIGH_SPEED))
s = "high speed";
else if (dev->gadget.speed == USB_SPEED_UNKNOWN)
s = "powered";
else
s = "full speed";
} else
s = "not attached";
t = scnprintf(next, size,
"usbctl0 %02x usbctl1 %02x addr 0x%02x (%s)\n",
net2272_read(dev, USBCTL0), t1,
net2272_read(dev, OURADDR), s);
size -= t;
next += t;
for (i = 0; i < 4; ++i) {
struct net2272_ep *ep;
ep = &dev->ep[i];
if (i && !ep->desc)
continue;
t1 = net2272_ep_read(ep, EP_CFG);
t2 = net2272_ep_read(ep, EP_RSPSET);
t = scnprintf(next, size,
"\n%s\tcfg %02x rsp (%02x) %s%s%s%s%s%s%s%s"
"irqenb %02x\n",
ep->ep.name, t1, t2,
(t2 & (1 << ALT_NAK_OUT_PACKETS)) ? "NAK " : "",
(t2 & (1 << HIDE_STATUS_PHASE)) ? "hide " : "",
(t2 & (1 << AUTOVALIDATE)) ? "auto " : "",
(t2 & (1 << INTERRUPT_MODE)) ? "interrupt " : "",
(t2 & (1 << CONTROL_STATUS_PHASE_HANDSHAKE)) ? "status " : "",
(t2 & (1 << NAK_OUT_PACKETS_MODE)) ? "NAKmode " : "",
(t2 & (1 << ENDPOINT_TOGGLE)) ? "DATA1 " : "DATA0 ",
(t2 & (1 << ENDPOINT_HALT)) ? "HALT " : "",
net2272_ep_read(ep, EP_IRQENB));
size -= t;
next += t;
t = scnprintf(next, size,
"\tstat0 %02x stat1 %02x avail %04x "
"(ep%d%s-%s)%s\n",
net2272_ep_read(ep, EP_STAT0),
net2272_ep_read(ep, EP_STAT1),
(net2272_ep_read(ep, EP_AVAIL1) << 8) | net2272_ep_read(ep, EP_AVAIL0),
t1 & 0x0f,
ep->is_in ? "in" : "out",
type_string(t1 >> 5),
ep->stopped ? "*" : "");
size -= t;
next += t;
t = scnprintf(next, size,
"\tep_transfer %06x\n",
((net2272_ep_read(ep, EP_TRANSFER2) & 0xff) << 16) |
((net2272_ep_read(ep, EP_TRANSFER1) & 0xff) << 8) |
((net2272_ep_read(ep, EP_TRANSFER0) & 0xff)));
size -= t;
next += t;
t1 = net2272_ep_read(ep, EP_BUFF_STATES) & 0x03;
t2 = (net2272_ep_read(ep, EP_BUFF_STATES) >> 2) & 0x03;
t = scnprintf(next, size,
"\tbuf-a %s buf-b %s\n",
buf_state_string(t1),
buf_state_string(t2));
size -= t;
next += t;
}
spin_unlock_irqrestore(&dev->lock, flags);
return PAGE_SIZE - size;
}
static void
net2272_set_fifo_mode(struct net2272 *dev, int mode)
{
u8 tmp;
tmp = net2272_read(dev, LOCCTL) & 0x3f;
tmp |= (mode << 6);
net2272_write(dev, LOCCTL, tmp);
INIT_LIST_HEAD(&dev->gadget.ep_list);
list_add_tail(&dev->ep[1].ep.ep_list, &dev->gadget.ep_list);
switch (mode) {
case 0:
list_add_tail(&dev->ep[2].ep.ep_list, &dev->gadget.ep_list);
dev->ep[1].fifo_size = dev->ep[2].fifo_size = 512;
break;
case 1:
list_add_tail(&dev->ep[2].ep.ep_list, &dev->gadget.ep_list);
dev->ep[1].fifo_size = 1024;
dev->ep[2].fifo_size = 512;
break;
case 2:
list_add_tail(&dev->ep[2].ep.ep_list, &dev->gadget.ep_list);
dev->ep[1].fifo_size = dev->ep[2].fifo_size = 1024;
break;
case 3:
dev->ep[1].fifo_size = 1024;
break;
}
list_add_tail(&dev->ep[3].ep.ep_list, &dev->gadget.ep_list);
dev->ep[3].fifo_size = 512;
}
static void
net2272_usb_reset(struct net2272 *dev)
{
dev->gadget.speed = USB_SPEED_UNKNOWN;
net2272_cancel_dma(dev);
net2272_write(dev, IRQENB0, 0);
net2272_write(dev, IRQENB1, 0);
net2272_write(dev, IRQSTAT0, 0xff);
net2272_write(dev, IRQSTAT1, ~(1 << SUSPEND_REQUEST_INTERRUPT));
net2272_write(dev, DMAREQ,
(0 << DMA_BUFFER_VALID) |
(0 << DMA_REQUEST_ENABLE) |
(1 << DMA_CONTROL_DACK) |
(dev->dma_eot_polarity << EOT_POLARITY) |
(dev->dma_dack_polarity << DACK_POLARITY) |
(dev->dma_dreq_polarity << DREQ_POLARITY) |
((dma_ep >> 1) << DMA_ENDPOINT_SELECT));
net2272_cancel_dma(dev);
net2272_set_fifo_mode(dev, (fifo_mode <= 3) ? fifo_mode : 0);
net2272_write(dev, LOCCTL, net2272_read(dev, LOCCTL) | (1 << DATA_WIDTH));
net2272_write(dev, LOCCTL1, (dma_mode << DMA_MODE));
}
static void
net2272_usb_reinit(struct net2272 *dev)
{
int i;
for (i = 0; i < 4; ++i) {
struct net2272_ep *ep = &dev->ep[i];
ep->ep.name = ep_name[i];
ep->dev = dev;
ep->num = i;
ep->not_empty = 0;
if (use_dma && ep->num == dma_ep)
ep->dma = 1;
if (i > 0 && i <= 3)
ep->fifo_size = 512;
else
ep->fifo_size = 64;
net2272_ep_reset(ep);
if (i == 0) {
ep->ep.caps.type_control = true;
} else {
ep->ep.caps.type_iso = true;
ep->ep.caps.type_bulk = true;
ep->ep.caps.type_int = true;
}
ep->ep.caps.dir_in = true;
ep->ep.caps.dir_out = true;
}
usb_ep_set_maxpacket_limit(&dev->ep[0].ep, 64);
dev->gadget.ep0 = &dev->ep[0].ep;
dev->ep[0].stopped = 0;
INIT_LIST_HEAD(&dev->gadget.ep0->ep_list);
}
static void
net2272_ep0_start(struct net2272 *dev)
{
struct net2272_ep *ep0 = &dev->ep[0];
net2272_ep_write(ep0, EP_RSPSET,
(1 << NAK_OUT_PACKETS_MODE) |
(1 << ALT_NAK_OUT_PACKETS));
net2272_ep_write(ep0, EP_RSPCLR,
(1 << HIDE_STATUS_PHASE) |
(1 << CONTROL_STATUS_PHASE_HANDSHAKE));
net2272_write(dev, USBCTL0,
(dev->softconnect << USB_DETECT_ENABLE) |
(1 << USB_ROOT_PORT_WAKEUP_ENABLE) |
(1 << IO_WAKEUP_ENABLE));
net2272_write(dev, IRQENB0,
(1 << SETUP_PACKET_INTERRUPT_ENABLE) |
(1 << ENDPOINT_0_INTERRUPT_ENABLE) |
(1 << DMA_DONE_INTERRUPT_ENABLE));
net2272_write(dev, IRQENB1,
(1 << VBUS_INTERRUPT_ENABLE) |
(1 << ROOT_PORT_RESET_INTERRUPT_ENABLE) |
(1 << SUSPEND_REQUEST_CHANGE_INTERRUPT_ENABLE));
}
static int net2272_start(struct usb_gadget *_gadget,
struct usb_gadget_driver *driver)
{
struct net2272 *dev;
unsigned i;
if (!driver || !driver->setup ||
driver->max_speed != USB_SPEED_HIGH)
return -EINVAL;
dev = container_of(_gadget, struct net2272, gadget);
for (i = 0; i < 4; ++i)
dev->ep[i].irqs = 0;
dev->softconnect = 1;
driver->driver.bus = NULL;
dev->driver = driver;
net2272_ep0_start(dev);
return 0;
}
static void
stop_activity(struct net2272 *dev, struct usb_gadget_driver *driver)
{
int i;
if (dev->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
net2272_usb_reset(dev);
for (i = 0; i < 4; ++i)
net2272_dequeue_all(&dev->ep[i]);
if (driver) {
spin_unlock(&dev->lock);
driver->disconnect(&dev->gadget);
spin_lock(&dev->lock);
}
net2272_usb_reinit(dev);
}
static int net2272_stop(struct usb_gadget *_gadget)
{
struct net2272 *dev;
unsigned long flags;
dev = container_of(_gadget, struct net2272, gadget);
spin_lock_irqsave(&dev->lock, flags);
stop_activity(dev, NULL);
spin_unlock_irqrestore(&dev->lock, flags);
dev->driver = NULL;
return 0;
}
static void
net2272_handle_dma(struct net2272_ep *ep)
{
struct net2272_request *req;
unsigned len;
int status;
if (!list_empty(&ep->queue))
req = list_entry(ep->queue.next,
struct net2272_request, queue);
else
req = NULL;
dev_vdbg(ep->dev->dev, "handle_dma %s req %p\n", ep->ep.name, req);
net2272_write(ep->dev, DMAREQ,
(0 << DMA_BUFFER_VALID)
| (0 << DMA_REQUEST_ENABLE)
| (1 << DMA_CONTROL_DACK)
| (ep->dev->dma_eot_polarity << EOT_POLARITY)
| (ep->dev->dma_dack_polarity << DACK_POLARITY)
| (ep->dev->dma_dreq_polarity << DREQ_POLARITY)
| (ep->dma << DMA_ENDPOINT_SELECT));
ep->dev->dma_busy = 0;
net2272_ep_write(ep, EP_IRQENB,
(1 << DATA_PACKET_RECEIVED_INTERRUPT_ENABLE)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT_ENABLE)
| net2272_ep_read(ep, EP_IRQENB));
if (ep->is_in) {
if ((req->req.length % ep->ep.maxpacket != 0) ||
req->req.zero)
set_fifo_bytecount(ep, 0);
net2272_done(ep, req, 0);
if (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct net2272_request, queue);
status = net2272_kick_dma(ep, req);
if (status < 0)
net2272_pio_advance(ep);
}
} else {
if (net2272_read(ep->dev, IRQSTAT0) &
(1 << DMA_DONE_INTERRUPT)) {
net2272_cancel_dma(ep->dev);
}
len = (net2272_ep_read(ep, EP_TRANSFER2) << 16)
| (net2272_ep_read(ep, EP_TRANSFER1) << 8)
| (net2272_ep_read(ep, EP_TRANSFER0));
if (ep->not_empty)
len += 4;
req->req.actual += len;
net2272_pio_advance(ep);
}
}
static void
net2272_handle_ep(struct net2272_ep *ep)
{
struct net2272_request *req;
u8 stat0, stat1;
if (!list_empty(&ep->queue))
req = list_entry(ep->queue.next,
struct net2272_request, queue);
else
req = NULL;
stat0 = net2272_ep_read(ep, EP_STAT0);
stat1 = net2272_ep_read(ep, EP_STAT1);
ep->irqs++;
dev_vdbg(ep->dev->dev, "%s ack ep_stat0 %02x, ep_stat1 %02x, req %p\n",
ep->ep.name, stat0, stat1, req ? &req->req : NULL);
net2272_ep_write(ep, EP_STAT0, stat0 &
~((1 << NAK_OUT_PACKETS)
| (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT)));
net2272_ep_write(ep, EP_STAT1, stat1);
if (!ep->is_in && (stat0 & (1 << DATA_PACKET_RECEIVED_INTERRUPT)))
net2272_pio_advance(ep);
else if (stat0 & (1 << DATA_PACKET_TRANSMITTED_INTERRUPT))
net2272_pio_advance(ep);
}
static struct net2272_ep *
net2272_get_ep_by_addr(struct net2272 *dev, u16 wIndex)
{
struct net2272_ep *ep;
if ((wIndex & USB_ENDPOINT_NUMBER_MASK) == 0)
return &dev->ep[0];
list_for_each_entry(ep, &dev->gadget.ep_list, ep.ep_list) {
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
static void
net2272_set_test_mode(struct net2272 *dev, int mode)
{
int i;
net2272_write(dev, IRQENB0, 0x00);
net2272_write(dev, IRQENB1, 0x00);
net2272_write(dev, XCVRDIAG, 1 << FORCE_HIGH_SPEED);
net2272_write(dev, PAGESEL, 0);
net2272_write(dev, EP_STAT0, 1 << DATA_PACKET_TRANSMITTED_INTERRUPT);
net2272_write(dev, EP_RSPCLR,
(1 << CONTROL_STATUS_PHASE_HANDSHAKE)
| (1 << HIDE_STATUS_PHASE));
net2272_write(dev, EP_CFG, 1 << ENDPOINT_DIRECTION);
net2272_write(dev, EP_STAT1, 1 << BUFFER_FLUSH);
while (!(net2272_read(dev, EP_STAT0) &
(1 << DATA_PACKET_TRANSMITTED_INTERRUPT)))
;
net2272_write(dev, USBTEST, mode);
if (mode == TEST_PACKET) {
net2272_write(dev, LOCCTL, net2272_read(dev, LOCCTL) &
~(1 << DATA_WIDTH));
for (i = 0; i < sizeof(net2272_test_packet); ++i)
net2272_write(dev, EP_DATA, net2272_test_packet[i]);
net2272_write(dev, EP_TRANSFER0, 0);
}
}
static void
net2272_handle_stat0_irqs(struct net2272 *dev, u8 stat)
{
struct net2272_ep *ep;
u8 num, scratch;
if (unlikely(stat & (1 << SETUP_PACKET_INTERRUPT))) {
union {
u8 raw[8];
struct usb_ctrlrequest r;
} u;
int tmp = 0;
struct net2272_request *req;
if (dev->gadget.speed == USB_SPEED_UNKNOWN) {
if (net2272_read(dev, USBCTL1) & (1 << USB_HIGH_SPEED))
dev->gadget.speed = USB_SPEED_HIGH;
else
dev->gadget.speed = USB_SPEED_FULL;
dev_dbg(dev->dev, "%s\n",
usb_speed_string(dev->gadget.speed));
}
ep = &dev->ep[0];
ep->irqs++;
stat &= ~(1 << ENDPOINT_0_INTERRUPT);
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct net2272_request, queue);
net2272_done(ep, req,
(req->req.actual == req->req.length) ? 0 : -EPROTO);
}
ep->stopped = 0;
dev->protocol_stall = 0;
net2272_ep_write(ep, EP_STAT0,
(1 << DATA_IN_TOKEN_INTERRUPT)
| (1 << DATA_OUT_TOKEN_INTERRUPT)
| (1 << DATA_PACKET_TRANSMITTED_INTERRUPT)
| (1 << DATA_PACKET_RECEIVED_INTERRUPT)
| (1 << SHORT_PACKET_TRANSFERRED_INTERRUPT));
net2272_ep_write(ep, EP_STAT1,
(1 << TIMEOUT)
| (1 << USB_OUT_ACK_SENT)
| (1 << USB_OUT_NAK_SENT)
| (1 << USB_IN_ACK_RCVD)
| (1 << USB_IN_NAK_SENT)
| (1 << USB_STALL_SENT)
| (1 << LOCAL_OUT_ZLP));
net2272_write(dev, PAGESEL, 0);
net2272_write(dev, EP_TRANSFER2, 0xff);
net2272_write(dev, EP_TRANSFER1, 0xff);
net2272_write(dev, EP_TRANSFER0, 0xff);
u.raw[0] = net2272_read(dev, SETUP0);
u.raw[1] = net2272_read(dev, SETUP1);
u.raw[2] = net2272_read(dev, SETUP2);
u.raw[3] = net2272_read(dev, SETUP3);
u.raw[4] = net2272_read(dev, SETUP4);
u.raw[5] = net2272_read(dev, SETUP5);
u.raw[6] = net2272_read(dev, SETUP6);
u.raw[7] = net2272_read(dev, SETUP7);
le16_to_cpus(&u.r.wValue);
le16_to_cpus(&u.r.wIndex);
le16_to_cpus(&u.r.wLength);
net2272_write(dev, IRQSTAT0, 1 << SETUP_PACKET_INTERRUPT);
stat ^= (1 << SETUP_PACKET_INTERRUPT);
ep->is_in = (u.r.bRequestType & USB_DIR_IN) != 0;
if (ep->is_in) {
scratch = (1 << DATA_PACKET_TRANSMITTED_INTERRUPT_ENABLE)
| (1 << DATA_OUT_TOKEN_INTERRUPT_ENABLE)
| (1 << DATA_IN_TOKEN_INTERRUPT_ENABLE);
stop_out_naking(ep);
} else
scratch = (1 << DATA_PACKET_RECEIVED_INTERRUPT_ENABLE)
| (1 << DATA_OUT_TOKEN_INTERRUPT_ENABLE)
| (1 << DATA_IN_TOKEN_INTERRUPT_ENABLE);
net2272_ep_write(ep, EP_IRQENB, scratch);
if ((u.r.bRequestType & USB_TYPE_MASK) != USB_TYPE_STANDARD)
goto delegate;
switch (u.r.bRequest) {
case USB_REQ_GET_STATUS: {
struct net2272_ep *e;
u16 status = 0;
switch (u.r.bRequestType & USB_RECIP_MASK) {
case USB_RECIP_ENDPOINT:
e = net2272_get_ep_by_addr(dev, u.r.wIndex);
if (!e || u.r.wLength > 2)
goto do_stall;
if (net2272_ep_read(e, EP_RSPSET) & (1 << ENDPOINT_HALT))
status = cpu_to_le16(1);
else
status = cpu_to_le16(0);
net2272_ep_write(&dev->ep[0], EP_IRQENB, 0);
writew(status, net2272_reg_addr(dev, EP_DATA));
set_fifo_bytecount(&dev->ep[0], 0);
allow_status(ep);
dev_vdbg(dev->dev, "%s stat %02x\n",
ep->ep.name, status);
goto next_endpoints;
case USB_RECIP_DEVICE:
if (u.r.wLength > 2)
goto do_stall;
if (dev->gadget.is_selfpowered)
status = (1 << USB_DEVICE_SELF_POWERED);
net2272_ep_write(&dev->ep[0], EP_IRQENB, 0);
writew(status, net2272_reg_addr(dev, EP_DATA));
set_fifo_bytecount(&dev->ep[0], 0);
allow_status(ep);
dev_vdbg(dev->dev, "device stat %02x\n", status);
goto next_endpoints;
case USB_RECIP_INTERFACE:
if (u.r.wLength > 2)
goto do_stall;
net2272_ep_write(&dev->ep[0], EP_IRQENB, 0);
writew(status, net2272_reg_addr(dev, EP_DATA));
set_fifo_bytecount(&dev->ep[0], 0);
allow_status(ep);
dev_vdbg(dev->dev, "interface status %02x\n", status);
goto next_endpoints;
}
break;
}
case USB_REQ_CLEAR_FEATURE: {
struct net2272_ep *e;
if (u.r.bRequestType != USB_RECIP_ENDPOINT)
goto delegate;
if (u.r.wValue != USB_ENDPOINT_HALT ||
u.r.wLength != 0)
goto do_stall;
e = net2272_get_ep_by_addr(dev, u.r.wIndex);
if (!e)
goto do_stall;
if (e->wedged) {
dev_vdbg(dev->dev, "%s wedged, halt not cleared\n",
ep->ep.name);
} else {
dev_vdbg(dev->dev, "%s clear halt\n", ep->ep.name);
clear_halt(e);
}
allow_status(ep);
goto next_endpoints;
}
case USB_REQ_SET_FEATURE: {
struct net2272_ep *e;
if (u.r.bRequestType == USB_RECIP_DEVICE) {
if (u.r.wIndex != NORMAL_OPERATION)
net2272_set_test_mode(dev, (u.r.wIndex >> 8));
allow_status(ep);
dev_vdbg(dev->dev, "test mode: %d\n", u.r.wIndex);
goto next_endpoints;
} else if (u.r.bRequestType != USB_RECIP_ENDPOINT)
goto delegate;
if (u.r.wValue != USB_ENDPOINT_HALT ||
u.r.wLength != 0)
goto do_stall;
e = net2272_get_ep_by_addr(dev, u.r.wIndex);
if (!e)
goto do_stall;
set_halt(e);
allow_status(ep);
dev_vdbg(dev->dev, "%s set halt\n", ep->ep.name);
goto next_endpoints;
}
case USB_REQ_SET_ADDRESS: {
net2272_write(dev, OURADDR, u.r.wValue & 0xff);
allow_status(ep);
break;
}
default:
delegate:
dev_vdbg(dev->dev, "setup %02x.%02x v%04x i%04x "
"ep_cfg %08x\n",
u.r.bRequestType, u.r.bRequest,
u.r.wValue, u.r.wIndex,
net2272_ep_read(ep, EP_CFG));
spin_unlock(&dev->lock);
tmp = dev->driver->setup(&dev->gadget, &u.r);
spin_lock(&dev->lock);
}
if (tmp < 0) {
do_stall:
dev_vdbg(dev->dev, "req %02x.%02x protocol STALL; stat %d\n",
u.r.bRequestType, u.r.bRequest, tmp);
dev->protocol_stall = 1;
}
} else if (stat & (1 << DMA_DONE_INTERRUPT)) {
net2272_cancel_dma(dev);
net2272_write(dev, IRQSTAT0, 1 << DMA_DONE_INTERRUPT);
stat &= ~(1 << DMA_DONE_INTERRUPT);
num = (net2272_read(dev, DMAREQ) & (1 << DMA_ENDPOINT_SELECT))
? 2 : 1;
ep = &dev->ep[num];
net2272_handle_dma(ep);
}
next_endpoints:
scratch = stat & 0x0f;
stat &= ~0x0f;
for (num = 0; scratch; num++) {
u8 t;
t = 1 << num;
if ((scratch & t) == 0)
continue;
scratch ^= t;
ep = &dev->ep[num];
net2272_handle_ep(ep);
}
stat &= ~(1 << SOF_INTERRUPT);
if (stat)
dev_dbg(dev->dev, "unhandled irqstat0 %02x\n", stat);
}
static void
net2272_handle_stat1_irqs(struct net2272 *dev, u8 stat)
{
u8 tmp, mask;
tmp = (1 << VBUS_INTERRUPT) | (1 << ROOT_PORT_RESET_INTERRUPT);
mask = (1 << USB_HIGH_SPEED) | (1 << USB_FULL_SPEED);
if (stat & tmp) {
bool reset = false;
bool disconnect = false;
net2272_write(dev, IRQSTAT1, tmp);
if (dev->gadget.speed != USB_SPEED_UNKNOWN) {
if ((stat & (1 << VBUS_INTERRUPT)) &&
(net2272_read(dev, USBCTL1) &
(1 << VBUS_PIN)) == 0) {
disconnect = true;
dev_dbg(dev->dev, "disconnect %s\n",
dev->driver->driver.name);
} else if ((stat & (1 << ROOT_PORT_RESET_INTERRUPT)) &&
(net2272_read(dev, USBCTL1) & mask)
== 0) {
reset = true;
dev_dbg(dev->dev, "reset %s\n",
dev->driver->driver.name);
}
if (disconnect || reset) {
stop_activity(dev, dev->driver);
net2272_ep0_start(dev);
spin_unlock(&dev->lock);
if (reset)
usb_gadget_udc_reset
(&dev->gadget, dev->driver);
else
(dev->driver->disconnect)
(&dev->gadget);
spin_lock(&dev->lock);
return;
}
}
stat &= ~tmp;
if (!stat)
return;
}
tmp = (1 << SUSPEND_REQUEST_CHANGE_INTERRUPT);
if (stat & tmp) {
net2272_write(dev, IRQSTAT1, tmp);
if (stat & (1 << SUSPEND_REQUEST_INTERRUPT)) {
if (dev->driver->suspend)
dev->driver->suspend(&dev->gadget);
if (!enable_suspend) {
stat &= ~(1 << SUSPEND_REQUEST_INTERRUPT);
dev_dbg(dev->dev, "Suspend disabled, ignoring\n");
}
} else {
if (dev->driver->resume)
dev->driver->resume(&dev->gadget);
}
stat &= ~tmp;
}
if (stat)
net2272_write(dev, IRQSTAT1, stat);
stat &= ~((1 << CONTROL_STATUS_INTERRUPT)
| (1 << SUSPEND_REQUEST_INTERRUPT)
| (1 << RESUME_INTERRUPT));
if (!stat)
return;
else
dev_dbg(dev->dev, "unhandled irqstat1 %02x\n", stat);
}
static irqreturn_t net2272_irq(int irq, void *_dev)
{
struct net2272 *dev = _dev;
#if defined(PLX_PCI_RDK) || defined(PLX_PCI_RDK2)
u32 intcsr;
#endif
#if defined(PLX_PCI_RDK)
u8 dmareq;
#endif
spin_lock(&dev->lock);
#if defined(PLX_PCI_RDK)
intcsr = readl(dev->rdk1.plx9054_base_addr + INTCSR);
if ((intcsr & LOCAL_INTERRUPT_TEST) == LOCAL_INTERRUPT_TEST) {
writel(intcsr & ~(1 << PCI_INTERRUPT_ENABLE),
dev->rdk1.plx9054_base_addr + INTCSR);
net2272_handle_stat1_irqs(dev, net2272_read(dev, IRQSTAT1));
net2272_handle_stat0_irqs(dev, net2272_read(dev, IRQSTAT0));
intcsr = readl(dev->rdk1.plx9054_base_addr + INTCSR);
writel(intcsr | (1 << PCI_INTERRUPT_ENABLE),
dev->rdk1.plx9054_base_addr + INTCSR);
}
if ((intcsr & DMA_CHANNEL_0_TEST) == DMA_CHANNEL_0_TEST) {
writeb((1 << CHANNEL_CLEAR_INTERRUPT | (0 << CHANNEL_ENABLE)),
dev->rdk1.plx9054_base_addr + DMACSR0);
dmareq = net2272_read(dev, DMAREQ);
if (dmareq & 0x01)
net2272_handle_dma(&dev->ep[2]);
else
net2272_handle_dma(&dev->ep[1]);
}
#endif
#if defined(PLX_PCI_RDK2)
intcsr = readl(dev->rdk2.fpga_base_addr + RDK2_IRQSTAT);
if (!intcsr & (1 << NET2272_PCI_IRQ)) {
spin_unlock(&dev->lock);
return IRQ_NONE;
}
#endif
#if !defined(PLX_PCI_RDK)
net2272_handle_stat1_irqs(dev, net2272_read(dev, IRQSTAT1));
net2272_handle_stat0_irqs(dev, net2272_read(dev, IRQSTAT0));
#endif
spin_unlock(&dev->lock);
return IRQ_HANDLED;
}
static int net2272_present(struct net2272 *dev)
{
unsigned int ii;
u8 val, refval;
refval = net2272_read(dev, SCRATCH);
for (ii = 0; ii < 0x100; ii += 7) {
net2272_write(dev, SCRATCH, ii);
val = net2272_read(dev, SCRATCH);
if (val != ii) {
dev_dbg(dev->dev,
"%s: write/read SCRATCH register test failed: "
"wrote:0x%2.2x, read:0x%2.2x\n",
__func__, ii, val);
return -EINVAL;
}
}
net2272_write(dev, SCRATCH, refval);
refval = net2272_read(dev, CHIPREV_2272);
for (ii = 0; ii < 0x100; ii += 7) {
net2272_write(dev, CHIPREV_2272, ii);
val = net2272_read(dev, CHIPREV_2272);
if (val != refval) {
dev_dbg(dev->dev,
"%s: write/read CHIPREV register test failed: "
"wrote 0x%2.2x, read:0x%2.2x expected:0x%2.2x\n",
__func__, ii, val, refval);
return -EINVAL;
}
}
val = net2272_read(dev, CHIPREV_LEGACY);
if (val != NET2270_LEGACY_REV) {
dev_dbg(dev->dev,
"%s: WARNING: UNEXPECTED NET2272 LEGACY REGISTER VALUE:\n"
" - CHIPREV_LEGACY: expected 0x%2.2x, got:0x%2.2x. (Not NET2272?)\n",
__func__, NET2270_LEGACY_REV, val);
return -EINVAL;
}
val = net2272_read(dev, CHIPREV_2272);
switch (val) {
case CHIPREV_NET2272_R1:
dev_dbg(dev->dev,
"%s: Rev 1 detected: newer silicon recommended for DMA support\n",
__func__);
break;
case CHIPREV_NET2272_R1A:
break;
default:
dev_dbg(dev->dev,
"%s: unexpected silicon revision register value: "
" CHIPREV_2272: 0x%2.2x\n",
__func__, val);
}
return 0;
}
static void
net2272_gadget_release(struct device *_dev)
{
struct net2272 *dev = dev_get_drvdata(_dev);
kfree(dev);
}
static void
net2272_remove(struct net2272 *dev)
{
usb_del_gadget_udc(&dev->gadget);
free_irq(dev->irq, dev);
iounmap(dev->base_addr);
device_remove_file(dev->dev, &dev_attr_registers);
dev_info(dev->dev, "unbind\n");
}
static struct net2272 *net2272_probe_init(struct device *dev, unsigned int irq)
{
struct net2272 *ret;
if (!irq) {
dev_dbg(dev, "No IRQ!\n");
return ERR_PTR(-ENODEV);
}
ret = kzalloc(sizeof(*ret), GFP_KERNEL);
if (!ret)
return ERR_PTR(-ENOMEM);
spin_lock_init(&ret->lock);
ret->irq = irq;
ret->dev = dev;
ret->gadget.ops = &net2272_ops;
ret->gadget.max_speed = USB_SPEED_HIGH;
ret->gadget.name = driver_name;
return ret;
}
static int
net2272_probe_fin(struct net2272 *dev, unsigned int irqflags)
{
int ret;
if (net2272_present(dev)) {
dev_warn(dev->dev, "2272 not found!\n");
ret = -ENODEV;
goto err;
}
net2272_usb_reset(dev);
net2272_usb_reinit(dev);
ret = request_irq(dev->irq, net2272_irq, irqflags, driver_name, dev);
if (ret) {
dev_err(dev->dev, "request interrupt %i failed\n", dev->irq);
goto err;
}
dev->chiprev = net2272_read(dev, CHIPREV_2272);
dev_info(dev->dev, "%s\n", driver_desc);
dev_info(dev->dev, "irq %i, mem %p, chip rev %04x, dma %s\n",
dev->irq, dev->base_addr, dev->chiprev,
dma_mode_string());
dev_info(dev->dev, "version: %s\n", driver_vers);
ret = device_create_file(dev->dev, &dev_attr_registers);
if (ret)
goto err_irq;
ret = usb_add_gadget_udc_release(dev->dev, &dev->gadget,
net2272_gadget_release);
if (ret)
goto err_add_udc;
return 0;
err_add_udc:
device_remove_file(dev->dev, &dev_attr_registers);
err_irq:
free_irq(dev->irq, dev);
err:
return ret;
}
static int
net2272_rdk1_probe(struct pci_dev *pdev, struct net2272 *dev)
{
unsigned long resource, len, tmp;
void __iomem *mem_mapped_addr[4];
int ret, i;
for (i = 0; i < 4; ++i) {
if (i == 1)
continue;
resource = pci_resource_start(pdev, i);
len = pci_resource_len(pdev, i);
if (!request_mem_region(resource, len, driver_name)) {
dev_dbg(dev->dev, "controller already in use\n");
ret = -EBUSY;
goto err;
}
mem_mapped_addr[i] = ioremap_nocache(resource, len);
if (mem_mapped_addr[i] == NULL) {
release_mem_region(resource, len);
dev_dbg(dev->dev, "can't map memory\n");
ret = -EFAULT;
goto err;
}
}
dev->rdk1.plx9054_base_addr = mem_mapped_addr[0];
dev->rdk1.epld_base_addr = mem_mapped_addr[2];
dev->base_addr = mem_mapped_addr[3];
tmp = readl(dev->rdk1.plx9054_base_addr + LBRD1);
writel((tmp & ~(3 << MEMORY_SPACE_LOCAL_BUS_WIDTH)) | W16_BIT,
dev->rdk1.plx9054_base_addr + LBRD1);
writel(readl(dev->rdk1.plx9054_base_addr + INTCSR) |
(1 << PCI_INTERRUPT_ENABLE) |
(1 << LOCAL_INTERRUPT_INPUT_ENABLE),
dev->rdk1.plx9054_base_addr + INTCSR);
writeb((1 << CHANNEL_CLEAR_INTERRUPT | (0 << CHANNEL_ENABLE)),
dev->rdk1.plx9054_base_addr + DMACSR0);
writeb((1 << EPLD_DMA_ENABLE) |
(1 << DMA_CTL_DACK) |
(1 << DMA_TIMEOUT_ENABLE) |
(1 << USER) |
(0 << MPX_MODE) |
(1 << BUSWIDTH) |
(1 << NET2272_RESET),
dev->base_addr + EPLD_IO_CONTROL_REGISTER);
mb();
writeb(readb(dev->base_addr + EPLD_IO_CONTROL_REGISTER) &
~(1 << NET2272_RESET),
dev->base_addr + EPLD_IO_CONTROL_REGISTER);
udelay(200);
return 0;
err:
while (--i >= 0) {
iounmap(mem_mapped_addr[i]);
release_mem_region(pci_resource_start(pdev, i),
pci_resource_len(pdev, i));
}
return ret;
}
static int
net2272_rdk2_probe(struct pci_dev *pdev, struct net2272 *dev)
{
unsigned long resource, len;
void __iomem *mem_mapped_addr[2];
int ret, i;
for (i = 0; i < 2; ++i) {
resource = pci_resource_start(pdev, i);
len = pci_resource_len(pdev, i);
if (!request_mem_region(resource, len, driver_name)) {
dev_dbg(dev->dev, "controller already in use\n");
ret = -EBUSY;
goto err;
}
mem_mapped_addr[i] = ioremap_nocache(resource, len);
if (mem_mapped_addr[i] == NULL) {
release_mem_region(resource, len);
dev_dbg(dev->dev, "can't map memory\n");
ret = -EFAULT;
goto err;
}
}
dev->rdk2.fpga_base_addr = mem_mapped_addr[0];
dev->base_addr = mem_mapped_addr[1];
mb();
writel((1 << CHIP_RESET), dev->rdk2.fpga_base_addr + RDK2_LOCCTLRDK);
udelay(200);
writel((1 << BUS_WIDTH), dev->rdk2.fpga_base_addr + RDK2_LOCCTLRDK);
dev_info(dev->dev, "RDK2 FPGA version %08x\n",
readl(dev->rdk2.fpga_base_addr + RDK2_FPGAREV));
writel((1 << NET2272_PCI_IRQ), dev->rdk2.fpga_base_addr + RDK2_IRQENB);
return 0;
err:
while (--i >= 0) {
iounmap(mem_mapped_addr[i]);
release_mem_region(pci_resource_start(pdev, i),
pci_resource_len(pdev, i));
}
return ret;
}
static int
net2272_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct net2272 *dev;
int ret;
dev = net2272_probe_init(&pdev->dev, pdev->irq);
if (IS_ERR(dev))
return PTR_ERR(dev);
dev->dev_id = pdev->device;
if (pci_enable_device(pdev) < 0) {
ret = -ENODEV;
goto err_free;
}
pci_set_master(pdev);
switch (pdev->device) {
case PCI_DEVICE_ID_RDK1: ret = net2272_rdk1_probe(pdev, dev); break;
case PCI_DEVICE_ID_RDK2: ret = net2272_rdk2_probe(pdev, dev); break;
default: BUG();
}
if (ret)
goto err_pci;
ret = net2272_probe_fin(dev, 0);
if (ret)
goto err_pci;
pci_set_drvdata(pdev, dev);
return 0;
err_pci:
pci_disable_device(pdev);
err_free:
kfree(dev);
return ret;
}
static void
net2272_rdk1_remove(struct pci_dev *pdev, struct net2272 *dev)
{
int i;
writel(readl(dev->rdk1.plx9054_base_addr + INTCSR) &
~(1 << PCI_INTERRUPT_ENABLE),
dev->rdk1.plx9054_base_addr + INTCSR);
iounmap(dev->rdk1.plx9054_base_addr);
iounmap(dev->rdk1.epld_base_addr);
for (i = 0; i < 4; ++i) {
if (i == 1)
continue;
release_mem_region(pci_resource_start(pdev, i),
pci_resource_len(pdev, i));
}
}
static void
net2272_rdk2_remove(struct pci_dev *pdev, struct net2272 *dev)
{
int i;
iounmap(dev->rdk2.fpga_base_addr);
for (i = 0; i < 2; ++i)
release_mem_region(pci_resource_start(pdev, i),
pci_resource_len(pdev, i));
}
static void
net2272_pci_remove(struct pci_dev *pdev)
{
struct net2272 *dev = pci_get_drvdata(pdev);
net2272_remove(dev);
switch (pdev->device) {
case PCI_DEVICE_ID_RDK1: net2272_rdk1_remove(pdev, dev); break;
case PCI_DEVICE_ID_RDK2: net2272_rdk2_remove(pdev, dev); break;
default: BUG();
}
pci_disable_device(pdev);
kfree(dev);
}
static int net2272_pci_register(void)
{
return pci_register_driver(&net2272_pci_driver);
}
static void net2272_pci_unregister(void)
{
pci_unregister_driver(&net2272_pci_driver);
}
static inline int net2272_pci_register(void) { return 0; }
static inline void net2272_pci_unregister(void) { }
static int
net2272_plat_probe(struct platform_device *pdev)
{
struct net2272 *dev;
int ret;
unsigned int irqflags;
resource_size_t base, len;
struct resource *iomem, *iomem_bus, *irq_res;
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iomem_bus = platform_get_resource(pdev, IORESOURCE_BUS, 0);
if (!irq_res || !iomem) {
dev_err(&pdev->dev, "must provide irq/base addr");
return -EINVAL;
}
dev = net2272_probe_init(&pdev->dev, irq_res->start);
if (IS_ERR(dev))
return PTR_ERR(dev);
irqflags = 0;
if (irq_res->flags & IORESOURCE_IRQ_HIGHEDGE)
irqflags |= IRQF_TRIGGER_RISING;
if (irq_res->flags & IORESOURCE_IRQ_LOWEDGE)
irqflags |= IRQF_TRIGGER_FALLING;
if (irq_res->flags & IORESOURCE_IRQ_HIGHLEVEL)
irqflags |= IRQF_TRIGGER_HIGH;
if (irq_res->flags & IORESOURCE_IRQ_LOWLEVEL)
irqflags |= IRQF_TRIGGER_LOW;
base = iomem->start;
len = resource_size(iomem);
if (iomem_bus)
dev->base_shift = iomem_bus->start;
if (!request_mem_region(base, len, driver_name)) {
dev_dbg(dev->dev, "get request memory region!\n");
ret = -EBUSY;
goto err;
}
dev->base_addr = ioremap_nocache(base, len);
if (!dev->base_addr) {
dev_dbg(dev->dev, "can't map memory\n");
ret = -EFAULT;
goto err_req;
}
ret = net2272_probe_fin(dev, IRQF_TRIGGER_LOW);
if (ret)
goto err_io;
platform_set_drvdata(pdev, dev);
dev_info(&pdev->dev, "running in 16-bit, %sbyte swap local bus mode\n",
(net2272_read(dev, LOCCTL) & (1 << BYTE_SWAP)) ? "" : "no ");
return 0;
err_io:
iounmap(dev->base_addr);
err_req:
release_mem_region(base, len);
err:
return ret;
}
static int
net2272_plat_remove(struct platform_device *pdev)
{
struct net2272 *dev = platform_get_drvdata(pdev);
net2272_remove(dev);
release_mem_region(pdev->resource[0].start,
resource_size(&pdev->resource[0]));
kfree(dev);
return 0;
}
static int __init net2272_init(void)
{
int ret;
ret = net2272_pci_register();
if (ret)
return ret;
ret = platform_driver_register(&net2272_plat_driver);
if (ret)
goto err_pci;
return ret;
err_pci:
net2272_pci_unregister();
return ret;
}
static void __exit net2272_cleanup(void)
{
net2272_pci_unregister();
platform_driver_unregister(&net2272_plat_driver);
}
