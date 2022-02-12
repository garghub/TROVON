static void xudc_write32(void __iomem *addr, u32 offset, u32 val)
{
iowrite32(val, addr + offset);
}
static unsigned int xudc_read32(void __iomem *addr)
{
return ioread32(addr);
}
static void xudc_write32_be(void __iomem *addr, u32 offset, u32 val)
{
iowrite32be(val, addr + offset);
}
static unsigned int xudc_read32_be(void __iomem *addr)
{
return ioread32be(addr);
}
static void xudc_wrstatus(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[XUSB_EP_NUMBER_ZERO];
u32 epcfgreg;
epcfgreg = udc->read_fn(udc->addr + ep0->offset)|
XUSB_EP_CFG_DATA_TOGGLE_MASK;
udc->write_fn(udc->addr, ep0->offset, epcfgreg);
udc->write_fn(udc->addr, ep0->offset + XUSB_EP_BUF0COUNT_OFFSET, 0);
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET, 1);
}
static void xudc_epconfig(struct xusb_ep *ep, struct xusb_udc *udc)
{
u32 epcfgreg;
epcfgreg = ((ep->is_in << 29) | (ep->is_iso << 28) |
(ep->ep_usb.maxpacket << 15) | (ep->rambase));
udc->write_fn(udc->addr, ep->offset, epcfgreg);
udc->write_fn(udc->addr, ep->offset + XUSB_EP_BUF0COUNT_OFFSET,
ep->buffer0count);
udc->write_fn(udc->addr, ep->offset + XUSB_EP_BUF1COUNT_OFFSET,
ep->buffer1count);
if (ep->buffer0ready)
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
1 << ep->epnumber);
if (ep->buffer1ready)
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
1 << (ep->epnumber + XUSB_STATUS_EP_BUFF2_SHIFT));
}
static int xudc_start_dma(struct xusb_ep *ep, dma_addr_t src,
dma_addr_t dst, u32 length)
{
struct xusb_udc *udc = ep->udc;
int rc = 0;
u32 timeout = 500;
u32 reg;
udc->write_fn(udc->addr, XUSB_DMA_DSAR_ADDR_OFFSET, src);
udc->write_fn(udc->addr, XUSB_DMA_DDAR_ADDR_OFFSET, dst);
udc->write_fn(udc->addr, XUSB_DMA_LENGTH_OFFSET, length);
do {
reg = udc->read_fn(udc->addr + XUSB_DMA_STATUS_OFFSET);
if (!(reg & XUSB_DMA_DMASR_BUSY))
break;
timeout--;
if (!timeout) {
dev_err(udc->dev, "DMA timeout\n");
return -ETIMEDOUT;
}
udelay(1);
} while (1);
if ((udc->read_fn(udc->addr + XUSB_DMA_STATUS_OFFSET) &
XUSB_DMA_DMASR_ERROR) == XUSB_DMA_DMASR_ERROR){
dev_err(udc->dev, "DMA Error\n");
rc = -EINVAL;
}
return rc;
}
static int xudc_dma_send(struct xusb_ep *ep, struct xusb_req *req,
u8 *buffer, u32 length)
{
u32 *eprambase;
dma_addr_t src;
dma_addr_t dst;
struct xusb_udc *udc = ep->udc;
src = req->usb_req.dma + req->usb_req.actual;
if (req->usb_req.length)
dma_sync_single_for_device(udc->dev, src,
length, DMA_TO_DEVICE);
if (!ep->curbufnum && !ep->buffer0ready) {
eprambase = (u32 __force *)(udc->addr + ep->rambase);
dst = virt_to_phys(eprambase);
udc->write_fn(udc->addr, ep->offset +
XUSB_EP_BUF0COUNT_OFFSET, length);
udc->write_fn(udc->addr, XUSB_DMA_CONTROL_OFFSET,
XUSB_DMA_BRR_CTRL | (1 << ep->epnumber));
ep->buffer0ready = 1;
ep->curbufnum = 1;
} else if (ep->curbufnum && !ep->buffer1ready) {
eprambase = (u32 __force *)(udc->addr + ep->rambase +
ep->ep_usb.maxpacket);
dst = virt_to_phys(eprambase);
udc->write_fn(udc->addr, ep->offset +
XUSB_EP_BUF1COUNT_OFFSET, length);
udc->write_fn(udc->addr, XUSB_DMA_CONTROL_OFFSET,
XUSB_DMA_BRR_CTRL | (1 << (ep->epnumber +
XUSB_STATUS_EP_BUFF2_SHIFT)));
ep->buffer1ready = 1;
ep->curbufnum = 0;
} else {
return -EAGAIN;
}
return xudc_start_dma(ep, src, dst, length);
}
static int xudc_dma_receive(struct xusb_ep *ep, struct xusb_req *req,
u8 *buffer, u32 length)
{
u32 *eprambase;
dma_addr_t src;
dma_addr_t dst;
struct xusb_udc *udc = ep->udc;
dst = req->usb_req.dma + req->usb_req.actual;
if (!ep->curbufnum && !ep->buffer0ready) {
eprambase = (u32 __force *)(udc->addr + ep->rambase);
src = virt_to_phys(eprambase);
udc->write_fn(udc->addr, XUSB_DMA_CONTROL_OFFSET,
XUSB_DMA_BRR_CTRL | XUSB_DMA_READ_FROM_DPRAM |
(1 << ep->epnumber));
ep->buffer0ready = 1;
ep->curbufnum = 1;
} else if (ep->curbufnum && !ep->buffer1ready) {
eprambase = (u32 __force *)(udc->addr +
ep->rambase + ep->ep_usb.maxpacket);
src = virt_to_phys(eprambase);
udc->write_fn(udc->addr, XUSB_DMA_CONTROL_OFFSET,
XUSB_DMA_BRR_CTRL | XUSB_DMA_READ_FROM_DPRAM |
(1 << (ep->epnumber +
XUSB_STATUS_EP_BUFF2_SHIFT)));
ep->buffer1ready = 1;
ep->curbufnum = 0;
} else {
return -EAGAIN;
}
return xudc_start_dma(ep, src, dst, length);
}
static int xudc_eptxrx(struct xusb_ep *ep, struct xusb_req *req,
u8 *bufferptr, u32 bufferlen)
{
u32 *eprambase;
u32 bytestosend;
int rc = 0;
struct xusb_udc *udc = ep->udc;
bytestosend = bufferlen;
if (udc->dma_enabled) {
if (ep->is_in)
rc = xudc_dma_send(ep, req, bufferptr, bufferlen);
else
rc = xudc_dma_receive(ep, req, bufferptr, bufferlen);
return rc;
}
if (!ep->curbufnum && !ep->buffer0ready) {
eprambase = (u32 __force *)(udc->addr + ep->rambase);
if (ep->is_in) {
memcpy(eprambase, bufferptr, bytestosend);
udc->write_fn(udc->addr, ep->offset +
XUSB_EP_BUF0COUNT_OFFSET, bufferlen);
} else {
memcpy(bufferptr, eprambase, bytestosend);
}
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
1 << ep->epnumber);
ep->buffer0ready = 1;
ep->curbufnum = 1;
} else if (ep->curbufnum && !ep->buffer1ready) {
eprambase = (u32 __force *)(udc->addr + ep->rambase +
ep->ep_usb.maxpacket);
if (ep->is_in) {
memcpy(eprambase, bufferptr, bytestosend);
udc->write_fn(udc->addr, ep->offset +
XUSB_EP_BUF1COUNT_OFFSET, bufferlen);
} else {
memcpy(bufferptr, eprambase, bytestosend);
}
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
1 << (ep->epnumber + XUSB_STATUS_EP_BUFF2_SHIFT));
ep->buffer1ready = 1;
ep->curbufnum = 0;
} else {
return -EAGAIN;
}
return rc;
}
static void xudc_done(struct xusb_ep *ep, struct xusb_req *req, int status)
{
struct xusb_udc *udc = ep->udc;
list_del_init(&req->queue);
if (req->usb_req.status == -EINPROGRESS)
req->usb_req.status = status;
else
status = req->usb_req.status;
if (status && status != -ESHUTDOWN)
dev_dbg(udc->dev, "%s done %p, status %d\n",
ep->ep_usb.name, req, status);
if (udc->dma_enabled && ep->epnumber && req->usb_req.length)
usb_gadget_unmap_request(&udc->gadget, &req->usb_req,
ep->is_in);
if (req->usb_req.complete) {
spin_unlock(&udc->lock);
req->usb_req.complete(&ep->ep_usb, &req->usb_req);
spin_lock(&udc->lock);
}
}
static int xudc_read_fifo(struct xusb_ep *ep, struct xusb_req *req)
{
u8 *buf;
u32 is_short, count, bufferspace;
u8 bufoffset;
u8 two_pkts = 0;
int ret;
int retval = -EAGAIN;
struct xusb_udc *udc = ep->udc;
if (ep->buffer0ready && ep->buffer1ready) {
dev_dbg(udc->dev, "Packet NOT ready!\n");
return retval;
}
top:
if (ep->curbufnum)
bufoffset = XUSB_EP_BUF1COUNT_OFFSET;
else
bufoffset = XUSB_EP_BUF0COUNT_OFFSET;
count = udc->read_fn(udc->addr + ep->offset + bufoffset);
if (!ep->buffer0ready && !ep->buffer1ready)
two_pkts = 1;
buf = req->usb_req.buf + req->usb_req.actual;
prefetchw(buf);
bufferspace = req->usb_req.length - req->usb_req.actual;
is_short = count < ep->ep_usb.maxpacket;
if (unlikely(!bufferspace)) {
if (req->usb_req.status != -EOVERFLOW)
dev_dbg(udc->dev, "%s overflow %d\n",
ep->ep_usb.name, count);
req->usb_req.status = -EOVERFLOW;
xudc_done(ep, req, -EOVERFLOW);
return 0;
}
ret = xudc_eptxrx(ep, req, buf, count);
switch (ret) {
case 0:
req->usb_req.actual += min(count, bufferspace);
dev_dbg(udc->dev, "read %s, %d bytes%s req %p %d/%d\n",
ep->ep_usb.name, count, is_short ? "/S" : "", req,
req->usb_req.actual, req->usb_req.length);
bufferspace -= count;
if ((req->usb_req.actual == req->usb_req.length) || is_short) {
if (udc->dma_enabled && req->usb_req.length)
dma_sync_single_for_cpu(udc->dev,
req->usb_req.dma,
req->usb_req.actual,
DMA_FROM_DEVICE);
xudc_done(ep, req, 0);
return 0;
}
if (two_pkts) {
two_pkts = 0;
goto top;
}
break;
case -EAGAIN:
dev_dbg(udc->dev, "receive busy\n");
break;
case -EINVAL:
case -ETIMEDOUT:
xudc_done(ep, req, -ECONNRESET);
retval = 0;
break;
}
return retval;
}
static int xudc_write_fifo(struct xusb_ep *ep, struct xusb_req *req)
{
u32 max;
u32 length;
int ret;
int retval = -EAGAIN;
struct xusb_udc *udc = ep->udc;
int is_last, is_short = 0;
u8 *buf;
max = le16_to_cpu(ep->desc->wMaxPacketSize);
buf = req->usb_req.buf + req->usb_req.actual;
prefetch(buf);
length = req->usb_req.length - req->usb_req.actual;
length = min(length, max);
ret = xudc_eptxrx(ep, req, buf, length);
switch (ret) {
case 0:
req->usb_req.actual += length;
if (unlikely(length != max)) {
is_last = is_short = 1;
} else {
if (likely(req->usb_req.length !=
req->usb_req.actual) || req->usb_req.zero)
is_last = 0;
else
is_last = 1;
}
dev_dbg(udc->dev, "%s: wrote %s %d bytes%s%s %d left %p\n",
__func__, ep->ep_usb.name, length, is_last ? "/L" : "",
is_short ? "/S" : "",
req->usb_req.length - req->usb_req.actual, req);
if (is_last) {
xudc_done(ep, req, 0);
retval = 0;
}
break;
case -EAGAIN:
dev_dbg(udc->dev, "Send busy\n");
break;
case -EINVAL:
case -ETIMEDOUT:
xudc_done(ep, req, -ECONNRESET);
retval = 0;
break;
}
return retval;
}
static void xudc_nuke(struct xusb_ep *ep, int status)
{
struct xusb_req *req;
while (!list_empty(&ep->queue)) {
req = list_first_entry(&ep->queue, struct xusb_req, queue);
xudc_done(ep, req, status);
}
}
static int xudc_ep_set_halt(struct usb_ep *_ep, int value)
{
struct xusb_ep *ep = to_xusb_ep(_ep);
struct xusb_udc *udc;
unsigned long flags;
u32 epcfgreg;
if (!_ep || (!ep->desc && ep->epnumber)) {
pr_debug("%s: bad ep or descriptor\n", __func__);
return -EINVAL;
}
udc = ep->udc;
if (ep->is_in && (!list_empty(&ep->queue)) && value) {
dev_dbg(udc->dev, "requests pending can't halt\n");
return -EAGAIN;
}
if (ep->buffer0ready || ep->buffer1ready) {
dev_dbg(udc->dev, "HW buffers busy can't halt\n");
return -EAGAIN;
}
spin_lock_irqsave(&udc->lock, flags);
if (value) {
epcfgreg = udc->read_fn(udc->addr + ep->offset);
epcfgreg |= XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr, ep->offset, epcfgreg);
} else {
epcfgreg = udc->read_fn(udc->addr + ep->offset);
epcfgreg &= ~XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr, ep->offset, epcfgreg);
if (ep->epnumber) {
epcfgreg = udc->read_fn(ep->udc->addr + ep->offset);
epcfgreg &= ~XUSB_EP_CFG_DATA_TOGGLE_MASK;
udc->write_fn(udc->addr, ep->offset, epcfgreg);
}
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int __xudc_ep_enable(struct xusb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct xusb_udc *udc = ep->udc;
u32 tmp;
u32 epcfg;
u32 ier;
u16 maxpacket;
ep->is_in = ((desc->bEndpointAddress & USB_DIR_IN) != 0);
ep->epnumber = (desc->bEndpointAddress & 0x0f);
ep->desc = desc;
ep->ep_usb.desc = desc;
tmp = desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
ep->ep_usb.maxpacket = maxpacket = le16_to_cpu(desc->wMaxPacketSize);
switch (tmp) {
case USB_ENDPOINT_XFER_CONTROL:
dev_dbg(udc->dev, "only one control endpoint\n");
ep->is_iso = 0;
return -EINVAL;
case USB_ENDPOINT_XFER_INT:
ep->is_iso = 0;
if (maxpacket > 64) {
dev_dbg(udc->dev, "bogus maxpacket %d\n", maxpacket);
return -EINVAL;
}
break;
case USB_ENDPOINT_XFER_BULK:
ep->is_iso = 0;
if (!(is_power_of_2(maxpacket) && maxpacket >= 8 &&
maxpacket <= 512)) {
dev_dbg(udc->dev, "bogus maxpacket %d\n", maxpacket);
return -EINVAL;
}
break;
case USB_ENDPOINT_XFER_ISOC:
ep->is_iso = 1;
break;
}
ep->buffer0ready = 0;
ep->buffer1ready = 0;
ep->curbufnum = 0;
ep->rambase = rambase[ep->epnumber];
xudc_epconfig(ep, udc);
dev_dbg(udc->dev, "Enable Endpoint %d max pkt is %d\n",
ep->epnumber, maxpacket);
epcfg = udc->read_fn(udc->addr + ep->offset);
epcfg |= XUSB_EP_CFG_VALID_MASK;
udc->write_fn(udc->addr, ep->offset, epcfg);
if (ep->epnumber)
ep->rambase <<= 2;
ier = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
ier |= (XUSB_STATUS_INTR_BUFF_COMP_SHIFT_MASK << ep->epnumber);
udc->write_fn(udc->addr, XUSB_IER_OFFSET, ier);
if (ep->epnumber && !ep->is_in) {
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
1 << ep->epnumber);
ep->buffer0ready = 1;
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET,
(1 << (ep->epnumber +
XUSB_STATUS_EP_BUFF2_SHIFT)));
ep->buffer1ready = 1;
}
return 0;
}
static int xudc_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct xusb_ep *ep;
struct xusb_udc *udc;
unsigned long flags;
int ret;
if (!_ep || !desc || desc->bDescriptorType != USB_DT_ENDPOINT) {
pr_debug("%s: bad ep or descriptor\n", __func__);
return -EINVAL;
}
ep = to_xusb_ep(_ep);
udc = ep->udc;
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN) {
dev_dbg(udc->dev, "bogus device state\n");
return -ESHUTDOWN;
}
spin_lock_irqsave(&udc->lock, flags);
ret = __xudc_ep_enable(ep, desc);
spin_unlock_irqrestore(&udc->lock, flags);
return ret;
}
static int xudc_ep_disable(struct usb_ep *_ep)
{
struct xusb_ep *ep;
unsigned long flags;
u32 epcfg;
struct xusb_udc *udc;
if (!_ep) {
pr_debug("%s: invalid ep\n", __func__);
return -EINVAL;
}
ep = to_xusb_ep(_ep);
udc = ep->udc;
spin_lock_irqsave(&udc->lock, flags);
xudc_nuke(ep, -ESHUTDOWN);
ep->desc = NULL;
ep->ep_usb.desc = NULL;
dev_dbg(udc->dev, "USB Ep %d disable\n ", ep->epnumber);
epcfg = udc->read_fn(udc->addr + ep->offset);
epcfg &= ~XUSB_EP_CFG_VALID_MASK;
udc->write_fn(udc->addr, ep->offset, epcfg);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static struct usb_request *xudc_ep_alloc_request(struct usb_ep *_ep,
gfp_t gfp_flags)
{
struct xusb_ep *ep = to_xusb_ep(_ep);
struct xusb_udc *udc;
struct xusb_req *req;
udc = ep->udc;
req = kzalloc(sizeof(*req), gfp_flags);
if (!req) {
dev_err(udc->dev, "%s:not enough memory", __func__);
return NULL;
}
req->ep = ep;
INIT_LIST_HEAD(&req->queue);
return &req->usb_req;
}
static void xudc_free_request(struct usb_ep *_ep, struct usb_request *_req)
{
struct xusb_req *req = to_xusb_req(_req);
kfree(req);
}
static int __xudc_ep0_queue(struct xusb_ep *ep0, struct xusb_req *req)
{
struct xusb_udc *udc = ep0->udc;
u32 length;
u8 *corebuf;
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN) {
dev_dbg(udc->dev, "%s, bogus device state\n", __func__);
return -EINVAL;
}
if (!list_empty(&ep0->queue)) {
dev_dbg(udc->dev, "%s:ep0 busy\n", __func__);
return -EBUSY;
}
req->usb_req.status = -EINPROGRESS;
req->usb_req.actual = 0;
list_add_tail(&req->queue, &ep0->queue);
if (udc->setup.bRequestType & USB_DIR_IN) {
prefetch(req->usb_req.buf);
length = req->usb_req.length;
corebuf = (void __force *) ((ep0->rambase << 2) +
udc->addr);
length = req->usb_req.actual = min_t(u32, length,
EP0_MAX_PACKET);
memcpy(corebuf, req->usb_req.buf, length);
udc->write_fn(udc->addr, XUSB_EP_BUF0COUNT_OFFSET, length);
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET, 1);
} else {
if (udc->setup.wLength) {
udc->write_fn(udc->addr, XUSB_EP_BUF0COUNT_OFFSET, 0);
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET, 1);
} else {
xudc_wrstatus(udc);
}
}
return 0;
}
static int xudc_ep0_queue(struct usb_ep *_ep, struct usb_request *_req,
gfp_t gfp_flags)
{
struct xusb_req *req = to_xusb_req(_req);
struct xusb_ep *ep0 = to_xusb_ep(_ep);
struct xusb_udc *udc = ep0->udc;
unsigned long flags;
int ret;
spin_lock_irqsave(&udc->lock, flags);
ret = __xudc_ep0_queue(ep0, req);
spin_unlock_irqrestore(&udc->lock, flags);
return ret;
}
static int xudc_ep_queue(struct usb_ep *_ep, struct usb_request *_req,
gfp_t gfp_flags)
{
struct xusb_req *req = to_xusb_req(_req);
struct xusb_ep *ep = to_xusb_ep(_ep);
struct xusb_udc *udc = ep->udc;
int ret;
unsigned long flags;
if (!ep->desc) {
dev_dbg(udc->dev, "%s:queing request to disabled %s\n",
__func__, ep->name);
return -ESHUTDOWN;
}
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN) {
dev_dbg(udc->dev, "%s, bogus device state\n", __func__);
return -EINVAL;
}
spin_lock_irqsave(&udc->lock, flags);
_req->status = -EINPROGRESS;
_req->actual = 0;
if (udc->dma_enabled) {
ret = usb_gadget_map_request(&udc->gadget, &req->usb_req,
ep->is_in);
if (ret) {
dev_dbg(udc->dev, "gadget_map failed ep%d\n",
ep->epnumber);
spin_unlock_irqrestore(&udc->lock, flags);
return -EAGAIN;
}
}
if (list_empty(&ep->queue)) {
if (ep->is_in) {
dev_dbg(udc->dev, "xudc_write_fifo from ep_queue\n");
if (!xudc_write_fifo(ep, req))
req = NULL;
} else {
dev_dbg(udc->dev, "xudc_read_fifo from ep_queue\n");
if (!xudc_read_fifo(ep, req))
req = NULL;
}
}
if (req != NULL)
list_add_tail(&req->queue, &ep->queue);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int xudc_ep_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct xusb_ep *ep = to_xusb_ep(_ep);
struct xusb_req *req = to_xusb_req(_req);
struct xusb_udc *udc = ep->udc;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (&req->usb_req == _req)
break;
}
if (&req->usb_req != _req) {
spin_unlock_irqrestore(&ep->udc->lock, flags);
return -EINVAL;
}
xudc_done(ep, req, -ECONNRESET);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int xudc_ep0_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
return -EINVAL;
}
static int xudc_ep0_disable(struct usb_ep *ep)
{
return -EINVAL;
}
static int xudc_get_frame(struct usb_gadget *gadget)
{
struct xusb_udc *udc;
int frame;
if (!gadget)
return -ENODEV;
udc = to_udc(gadget);
frame = udc->read_fn(udc->addr + XUSB_FRAMENUM_OFFSET);
return frame;
}
static int xudc_wakeup(struct usb_gadget *gadget)
{
struct xusb_udc *udc = to_udc(gadget);
u32 crtlreg;
int status = -EINVAL;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
if (!udc->remote_wkp)
goto done;
crtlreg = udc->read_fn(udc->addr + XUSB_CONTROL_OFFSET);
crtlreg |= XUSB_CONTROL_USB_RMTWAKE_MASK;
udc->write_fn(udc->addr, XUSB_CONTROL_OFFSET, crtlreg);
mdelay(2);
crtlreg &= ~XUSB_CONTROL_USB_RMTWAKE_MASK;
udc->write_fn(udc->addr, XUSB_CONTROL_OFFSET, crtlreg);
status = 0;
done:
spin_unlock_irqrestore(&udc->lock, flags);
return status;
}
static int xudc_pullup(struct usb_gadget *gadget, int is_on)
{
struct xusb_udc *udc = to_udc(gadget);
unsigned long flags;
u32 crtlreg;
spin_lock_irqsave(&udc->lock, flags);
crtlreg = udc->read_fn(udc->addr + XUSB_CONTROL_OFFSET);
if (is_on)
crtlreg |= XUSB_CONTROL_USB_READY_MASK;
else
crtlreg &= ~XUSB_CONTROL_USB_READY_MASK;
udc->write_fn(udc->addr, XUSB_CONTROL_OFFSET, crtlreg);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static void xudc_eps_init(struct xusb_udc *udc)
{
u32 ep_number;
INIT_LIST_HEAD(&udc->gadget.ep_list);
for (ep_number = 0; ep_number < XUSB_MAX_ENDPOINTS; ep_number++) {
struct xusb_ep *ep = &udc->ep[ep_number];
if (ep_number) {
list_add_tail(&ep->ep_usb.ep_list,
&udc->gadget.ep_list);
usb_ep_set_maxpacket_limit(&ep->ep_usb,
(unsigned short) ~0);
snprintf(ep->name, EPNAME_SIZE, "ep%d", ep_number);
ep->ep_usb.name = ep->name;
ep->ep_usb.ops = &xusb_ep_ops;
} else {
ep->ep_usb.name = ep0name;
usb_ep_set_maxpacket_limit(&ep->ep_usb, EP0_MAX_PACKET);
ep->ep_usb.ops = &xusb_ep0_ops;
}
ep->udc = udc;
ep->epnumber = ep_number;
ep->desc = NULL;
ep->offset = XUSB_EP0_CONFIG_OFFSET + (ep_number * 0x10);
ep->is_in = 0;
ep->is_iso = 0;
ep->maxpacket = 0;
xudc_epconfig(ep, udc);
INIT_LIST_HEAD(&ep->queue);
}
}
static void xudc_stop_activity(struct xusb_udc *udc)
{
int i;
struct xusb_ep *ep;
for (i = 0; i < XUSB_MAX_ENDPOINTS; i++) {
ep = &udc->ep[i];
xudc_nuke(ep, -ESHUTDOWN);
}
}
static int xudc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct xusb_udc *udc = to_udc(gadget);
struct xusb_ep *ep0 = &udc->ep[XUSB_EP_NUMBER_ZERO];
const struct usb_endpoint_descriptor *desc = &config_bulk_out_desc;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&udc->lock, flags);
if (udc->driver) {
dev_err(udc->dev, "%s is already bound to %s\n",
udc->gadget.name, udc->driver->driver.name);
ret = -EBUSY;
goto err;
}
udc->driver = driver;
udc->gadget.speed = driver->max_speed;
ret = __xudc_ep_enable(ep0, desc);
udc->write_fn(udc->addr, XUSB_ADDRESS_OFFSET, 0);
udc->remote_wkp = 0;
err:
spin_unlock_irqrestore(&udc->lock, flags);
return ret;
}
static int xudc_stop(struct usb_gadget *gadget)
{
struct xusb_udc *udc = to_udc(gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->driver = NULL;
udc->write_fn(udc->addr, XUSB_ADDRESS_OFFSET, 0);
udc->remote_wkp = 0;
xudc_stop_activity(udc);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static void xudc_clear_stall_all_ep(struct xusb_udc *udc)
{
struct xusb_ep *ep;
u32 epcfgreg;
int i;
for (i = 0; i < XUSB_MAX_ENDPOINTS; i++) {
ep = &udc->ep[i];
epcfgreg = udc->read_fn(udc->addr + ep->offset);
epcfgreg &= ~XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr, ep->offset, epcfgreg);
if (ep->epnumber) {
epcfgreg = udc->read_fn(udc->addr + ep->offset);
epcfgreg &= ~XUSB_EP_CFG_DATA_TOGGLE_MASK;
udc->write_fn(udc->addr, ep->offset, epcfgreg);
}
}
}
static void xudc_startup_handler(struct xusb_udc *udc, u32 intrstatus)
{
u32 intrreg;
if (intrstatus & XUSB_STATUS_RESET_MASK) {
dev_dbg(udc->dev, "Reset\n");
if (intrstatus & XUSB_STATUS_HIGH_SPEED_MASK)
udc->gadget.speed = USB_SPEED_HIGH;
else
udc->gadget.speed = USB_SPEED_FULL;
xudc_stop_activity(udc);
xudc_clear_stall_all_ep(udc);
udc->write_fn(udc->addr, XUSB_TESTMODE_OFFSET, 0);
udc->write_fn(udc->addr, XUSB_ADDRESS_OFFSET, 0);
udc->remote_wkp = 0;
intrreg = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
intrreg |= XUSB_STATUS_SUSPEND_MASK | XUSB_STATUS_RESUME_MASK |
XUSB_STATUS_DISCONNECT_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, intrreg);
}
if (intrstatus & XUSB_STATUS_SUSPEND_MASK) {
dev_dbg(udc->dev, "Suspend\n");
intrreg = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
intrreg |= XUSB_STATUS_RESET_MASK | XUSB_STATUS_RESUME_MASK |
XUSB_STATUS_DISCONNECT_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, intrreg);
udc->usb_state = USB_STATE_SUSPENDED;
if (udc->driver->suspend) {
spin_unlock(&udc->lock);
udc->driver->suspend(&udc->gadget);
spin_lock(&udc->lock);
}
}
if (intrstatus & XUSB_STATUS_RESUME_MASK) {
bool condition = (udc->usb_state != USB_STATE_SUSPENDED);
dev_WARN_ONCE(udc->dev, condition,
"Resume IRQ while not suspended\n");
dev_dbg(udc->dev, "Resume\n");
intrreg = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
intrreg |= XUSB_STATUS_RESET_MASK | XUSB_STATUS_SUSPEND_MASK |
XUSB_STATUS_DISCONNECT_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, intrreg);
udc->usb_state = 0;
if (udc->driver->resume) {
spin_unlock(&udc->lock);
udc->driver->resume(&udc->gadget);
spin_lock(&udc->lock);
}
}
if (intrstatus & XUSB_STATUS_DISCONNECT_MASK) {
dev_dbg(udc->dev, "Disconnect\n");
intrreg = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
intrreg |= XUSB_STATUS_RESET_MASK | XUSB_STATUS_RESUME_MASK |
XUSB_STATUS_SUSPEND_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, intrreg);
if (udc->driver && udc->driver->disconnect) {
spin_unlock(&udc->lock);
udc->driver->disconnect(&udc->gadget);
spin_lock(&udc->lock);
}
}
}
static void xudc_ep0_stall(struct xusb_udc *udc)
{
u32 epcfgreg;
struct xusb_ep *ep0 = &udc->ep[XUSB_EP_NUMBER_ZERO];
epcfgreg = udc->read_fn(udc->addr + ep0->offset);
epcfgreg |= XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr, ep0->offset, epcfgreg);
}
static void xudc_setaddress(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct xusb_req *req = udc->req;
int ret;
req->usb_req.length = 0;
ret = __xudc_ep0_queue(ep0, req);
if (ret == 0)
return;
dev_err(udc->dev, "Can't respond to SET ADDRESS request\n");
xudc_ep0_stall(udc);
}
static void xudc_getstatus(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct xusb_req *req = udc->req;
struct xusb_ep *target_ep;
u16 status = 0;
u32 epcfgreg;
int epnum;
u32 halt;
int ret;
switch (udc->setup.bRequestType & USB_RECIP_MASK) {
case USB_RECIP_DEVICE:
status = 1 << USB_DEVICE_SELF_POWERED;
if (udc->remote_wkp)
status |= (1 << USB_DEVICE_REMOTE_WAKEUP);
break;
case USB_RECIP_INTERFACE:
break;
case USB_RECIP_ENDPOINT:
epnum = udc->setup.wIndex & USB_ENDPOINT_NUMBER_MASK;
target_ep = &udc->ep[epnum];
epcfgreg = udc->read_fn(udc->addr + target_ep->offset);
halt = epcfgreg & XUSB_EP_CFG_STALL_MASK;
if (udc->setup.wIndex & USB_DIR_IN) {
if (!target_ep->is_in)
goto stall;
} else {
if (target_ep->is_in)
goto stall;
}
if (halt)
status = 1 << USB_ENDPOINT_HALT;
break;
default:
goto stall;
}
req->usb_req.length = 2;
*(u16 *)req->usb_req.buf = cpu_to_le16(status);
ret = __xudc_ep0_queue(ep0, req);
if (ret == 0)
return;
stall:
dev_err(udc->dev, "Can't respond to getstatus request\n");
xudc_ep0_stall(udc);
}
static void xudc_set_clear_feature(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct xusb_req *req = udc->req;
struct xusb_ep *target_ep;
u8 endpoint;
u8 outinbit;
u32 epcfgreg;
int flag = (udc->setup.bRequest == USB_REQ_SET_FEATURE ? 1 : 0);
int ret;
switch (udc->setup.bRequestType) {
case USB_RECIP_DEVICE:
switch (udc->setup.wValue) {
case USB_DEVICE_TEST_MODE:
break;
case USB_DEVICE_REMOTE_WAKEUP:
if (flag)
udc->remote_wkp = 1;
else
udc->remote_wkp = 0;
break;
default:
xudc_ep0_stall(udc);
break;
}
break;
case USB_RECIP_ENDPOINT:
if (!udc->setup.wValue) {
endpoint = udc->setup.wIndex & USB_ENDPOINT_NUMBER_MASK;
target_ep = &udc->ep[endpoint];
outinbit = udc->setup.wIndex & USB_ENDPOINT_DIR_MASK;
outinbit = outinbit >> 7;
if (outinbit != target_ep->is_in) {
xudc_ep0_stall(udc);
return;
}
epcfgreg = udc->read_fn(udc->addr + target_ep->offset);
if (!endpoint) {
epcfgreg &= ~XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr,
target_ep->offset, epcfgreg);
} else {
if (flag) {
epcfgreg |= XUSB_EP_CFG_STALL_MASK;
udc->write_fn(udc->addr,
target_ep->offset,
epcfgreg);
} else {
epcfgreg &= ~(XUSB_EP_CFG_STALL_MASK |
XUSB_EP_CFG_DATA_TOGGLE_MASK);
udc->write_fn(udc->addr,
target_ep->offset,
epcfgreg);
}
}
}
break;
default:
xudc_ep0_stall(udc);
return;
}
req->usb_req.length = 0;
ret = __xudc_ep0_queue(ep0, req);
if (ret == 0)
return;
dev_err(udc->dev, "Can't respond to SET/CLEAR FEATURE\n");
xudc_ep0_stall(udc);
}
static void xudc_handle_setup(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct usb_ctrlrequest setup;
u32 *ep0rambase;
ep0rambase = (u32 __force *) (udc->addr + XUSB_SETUP_PKT_ADDR_OFFSET);
memcpy(&setup, ep0rambase, 8);
udc->setup = setup;
udc->setup.wValue = cpu_to_le16(setup.wValue);
udc->setup.wIndex = cpu_to_le16(setup.wIndex);
udc->setup.wLength = cpu_to_le16(setup.wLength);
xudc_nuke(ep0, -ECONNRESET);
if (udc->setup.bRequestType & USB_DIR_IN) {
udc->setupseqrx = STATUS_PHASE;
udc->setupseqtx = DATA_PHASE;
} else {
udc->setupseqrx = DATA_PHASE;
udc->setupseqtx = STATUS_PHASE;
}
switch (udc->setup.bRequest) {
case USB_REQ_GET_STATUS:
if ((udc->setup.bRequestType &
(USB_DIR_IN | USB_TYPE_MASK)) !=
(USB_DIR_IN | USB_TYPE_STANDARD))
break;
xudc_getstatus(udc);
return;
case USB_REQ_SET_ADDRESS:
if (udc->setup.bRequestType != (USB_DIR_OUT |
USB_TYPE_STANDARD | USB_RECIP_DEVICE))
break;
xudc_setaddress(udc);
return;
case USB_REQ_CLEAR_FEATURE:
case USB_REQ_SET_FEATURE:
if ((udc->setup.bRequestType & USB_TYPE_MASK)
!= USB_TYPE_STANDARD)
break;
xudc_set_clear_feature(udc);
return;
default:
break;
}
spin_unlock(&udc->lock);
if (udc->driver->setup(&udc->gadget, &setup) < 0)
xudc_ep0_stall(udc);
spin_lock(&udc->lock);
}
static void xudc_ep0_out(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct xusb_req *req;
u8 *ep0rambase;
unsigned int bytes_to_rx;
void *buffer;
req = list_first_entry(&ep0->queue, struct xusb_req, queue);
switch (udc->setupseqrx) {
case STATUS_PHASE:
udc->setupseqrx = SETUP_PHASE;
udc->setupseqtx = SETUP_PHASE;
req->usb_req.actual = req->usb_req.length;
xudc_done(ep0, req, 0);
break;
case DATA_PHASE:
bytes_to_rx = udc->read_fn(udc->addr +
XUSB_EP_BUF0COUNT_OFFSET);
ep0rambase = (u8 __force *) (udc->addr +
(ep0->rambase << 2));
buffer = req->usb_req.buf + req->usb_req.actual;
req->usb_req.actual = req->usb_req.actual + bytes_to_rx;
memcpy(buffer, ep0rambase, bytes_to_rx);
if (req->usb_req.length == req->usb_req.actual) {
xudc_wrstatus(udc);
} else {
udc->write_fn(udc->addr, XUSB_EP_BUF0COUNT_OFFSET, 0);
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET, 1);
}
break;
default:
break;
}
}
static void xudc_ep0_in(struct xusb_udc *udc)
{
struct xusb_ep *ep0 = &udc->ep[0];
struct xusb_req *req;
unsigned int bytes_to_tx;
void *buffer;
u32 epcfgreg;
u16 count = 0;
u16 length;
u8 *ep0rambase;
u8 test_mode = udc->setup.wIndex >> 8;
req = list_first_entry(&ep0->queue, struct xusb_req, queue);
bytes_to_tx = req->usb_req.length - req->usb_req.actual;
switch (udc->setupseqtx) {
case STATUS_PHASE:
switch (udc->setup.bRequest) {
case USB_REQ_SET_ADDRESS:
udc->write_fn(udc->addr, XUSB_ADDRESS_OFFSET,
udc->setup.wValue);
break;
case USB_REQ_SET_FEATURE:
if (udc->setup.bRequestType ==
USB_RECIP_DEVICE) {
if (udc->setup.wValue ==
USB_DEVICE_TEST_MODE)
udc->write_fn(udc->addr,
XUSB_TESTMODE_OFFSET,
test_mode);
}
break;
}
req->usb_req.actual = req->usb_req.length;
xudc_done(ep0, req, 0);
break;
case DATA_PHASE:
if (!bytes_to_tx) {
epcfgreg = udc->read_fn(udc->addr + ep0->offset);
epcfgreg |= XUSB_EP_CFG_DATA_TOGGLE_MASK;
udc->write_fn(udc->addr, ep0->offset, epcfgreg);
udc->setupseqtx = STATUS_PHASE;
} else {
length = count = min_t(u32, bytes_to_tx,
EP0_MAX_PACKET);
ep0rambase = (u8 __force *) (udc->addr +
(ep0->rambase << 2));
buffer = req->usb_req.buf + req->usb_req.actual;
req->usb_req.actual = req->usb_req.actual + length;
memcpy(ep0rambase, buffer, length);
}
udc->write_fn(udc->addr, XUSB_EP_BUF0COUNT_OFFSET, count);
udc->write_fn(udc->addr, XUSB_BUFFREADY_OFFSET, 1);
break;
default:
break;
}
}
static void xudc_ctrl_ep_handler(struct xusb_udc *udc, u32 intrstatus)
{
if (intrstatus & XUSB_STATUS_SETUP_PACKET_MASK) {
xudc_handle_setup(udc);
} else {
if (intrstatus & XUSB_STATUS_FIFO_BUFF_RDY_MASK)
xudc_ep0_out(udc);
else if (intrstatus & XUSB_STATUS_FIFO_BUFF_FREE_MASK)
xudc_ep0_in(udc);
}
}
static void xudc_nonctrl_ep_handler(struct xusb_udc *udc, u8 epnum,
u32 intrstatus)
{
struct xusb_req *req;
struct xusb_ep *ep;
ep = &udc->ep[epnum];
if (intrstatus & (XUSB_STATUS_EP0_BUFF1_COMP_MASK << epnum))
ep->buffer0ready = 0;
if (intrstatus & (XUSB_STATUS_EP0_BUFF2_COMP_MASK << epnum))
ep->buffer1ready = 0;
if (list_empty(&ep->queue))
return;
req = list_first_entry(&ep->queue, struct xusb_req, queue);
if (ep->is_in)
xudc_write_fifo(ep, req);
else
xudc_read_fifo(ep, req);
}
static irqreturn_t xudc_irq(int irq, void *_udc)
{
struct xusb_udc *udc = _udc;
u32 intrstatus;
u32 ier;
u8 index;
u32 bufintr;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
ier = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
ier &= ~XUSB_STATUS_INTR_EVENT_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, ier);
intrstatus = udc->read_fn(udc->addr + XUSB_STATUS_OFFSET);
if (intrstatus & XUSB_STATUS_INTR_EVENT_MASK) {
xudc_startup_handler(udc, intrstatus);
}
if (intrstatus & XUSB_STATUS_INTR_BUFF_COMP_ALL_MASK) {
ier = udc->read_fn(udc->addr + XUSB_IER_OFFSET);
ier |= XUSB_STATUS_INTR_EVENT_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, ier);
if (intrstatus & XUSB_STATUS_EP0_BUFF1_COMP_MASK)
xudc_ctrl_ep_handler(udc, intrstatus);
for (index = 1; index < 8; index++) {
bufintr = ((intrstatus &
(XUSB_STATUS_EP1_BUFF1_COMP_MASK <<
(index - 1))) || (intrstatus &
(XUSB_STATUS_EP1_BUFF2_COMP_MASK <<
(index - 1))));
if (bufintr) {
xudc_nonctrl_ep_handler(udc, index,
intrstatus);
}
}
}
spin_unlock_irqrestore(&udc->lock, flags);
return IRQ_HANDLED;
}
static int xudc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res;
struct xusb_udc *udc;
struct xusb_ep *ep0;
int irq;
int ret;
u32 ier;
u8 *buff;
udc = devm_kzalloc(&pdev->dev, sizeof(*udc), GFP_KERNEL);
if (!udc)
return -ENOMEM;
udc->req = devm_kzalloc(&pdev->dev, sizeof(struct xusb_req),
GFP_KERNEL);
if (!udc->req)
return -ENOMEM;
buff = devm_kzalloc(&pdev->dev, STATUSBUFF_SIZE, GFP_KERNEL);
if (!buff)
return -ENOMEM;
udc->req->usb_req.buf = buff;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
udc->addr = devm_ioremap_resource(&pdev->dev, res);
if (!udc->addr)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "unable to get irq\n");
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, xudc_irq, 0,
dev_name(&pdev->dev), udc);
if (ret < 0) {
dev_dbg(&pdev->dev, "unable to request irq %d", irq);
goto fail;
}
udc->dma_enabled = of_property_read_bool(np, "xlnx,has-builtin-dma");
udc->gadget.ops = &xusb_udc_ops;
udc->gadget.max_speed = USB_SPEED_HIGH;
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->gadget.ep0 = &udc->ep[XUSB_EP_NUMBER_ZERO].ep_usb;
udc->gadget.name = driver_name;
spin_lock_init(&udc->lock);
udc->write_fn = xudc_write32_be;
udc->read_fn = xudc_read32_be;
udc->write_fn(udc->addr, XUSB_TESTMODE_OFFSET, TEST_J);
if ((udc->read_fn(udc->addr + XUSB_TESTMODE_OFFSET))
!= TEST_J) {
udc->write_fn = xudc_write32;
udc->read_fn = xudc_read32;
}
udc->write_fn(udc->addr, XUSB_TESTMODE_OFFSET, 0);
xudc_eps_init(udc);
ep0 = &udc->ep[0];
udc->write_fn(udc->addr, XUSB_ADDRESS_OFFSET, 0);
ret = usb_add_gadget_udc(&pdev->dev, &udc->gadget);
if (ret)
goto fail;
udc->dev = &udc->gadget.dev;
ier = XUSB_STATUS_GLOBAL_INTR_MASK | XUSB_STATUS_INTR_EVENT_MASK |
XUSB_STATUS_FIFO_BUFF_RDY_MASK | XUSB_STATUS_FIFO_BUFF_FREE_MASK |
XUSB_STATUS_SETUP_PACKET_MASK |
XUSB_STATUS_INTR_BUFF_COMP_ALL_MASK;
udc->write_fn(udc->addr, XUSB_IER_OFFSET, ier);
platform_set_drvdata(pdev, udc);
dev_vdbg(&pdev->dev, "%s at 0x%08X mapped to 0x%08X %s\n",
driver_name, (u32)res->start, (u32 __force)udc->addr,
udc->dma_enabled ? "with DMA" : "without DMA");
return 0;
fail:
dev_err(&pdev->dev, "probe failed, %d\n", ret);
return ret;
}
static int xudc_remove(struct platform_device *pdev)
{
struct xusb_udc *udc = platform_get_drvdata(pdev);
usb_del_gadget_udc(&udc->gadget);
return 0;
}
