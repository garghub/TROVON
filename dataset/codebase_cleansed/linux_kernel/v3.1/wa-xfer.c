static void wa_seg_init(struct wa_seg *seg)
{
kref_init(&seg->urb.kref);
}
static inline void wa_xfer_init(struct wa_xfer *xfer)
{
kref_init(&xfer->refcnt);
INIT_LIST_HEAD(&xfer->list_node);
spin_lock_init(&xfer->lock);
}
static void wa_xfer_destroy(struct kref *_xfer)
{
struct wa_xfer *xfer = container_of(_xfer, struct wa_xfer, refcnt);
if (xfer->seg) {
unsigned cnt;
for (cnt = 0; cnt < xfer->segs; cnt++) {
if (xfer->is_inbound)
usb_put_urb(xfer->seg[cnt]->dto_urb);
usb_put_urb(&xfer->seg[cnt]->urb);
}
}
kfree(xfer);
}
static void wa_xfer_get(struct wa_xfer *xfer)
{
kref_get(&xfer->refcnt);
}
static void wa_xfer_put(struct wa_xfer *xfer)
{
kref_put(&xfer->refcnt, wa_xfer_destroy);
}
static void wa_xfer_giveback(struct wa_xfer *xfer)
{
unsigned long flags;
spin_lock_irqsave(&xfer->wa->xfer_list_lock, flags);
list_del_init(&xfer->list_node);
spin_unlock_irqrestore(&xfer->wa->xfer_list_lock, flags);
wusbhc_giveback_urb(xfer->wa->wusb, xfer->urb, xfer->result);
wa_put(xfer->wa);
wa_xfer_put(xfer);
}
static void wa_xfer_completion(struct wa_xfer *xfer)
{
if (xfer->wusb_dev)
wusb_dev_put(xfer->wusb_dev);
rpipe_put(xfer->ep->hcpriv);
wa_xfer_giveback(xfer);
}
static unsigned __wa_xfer_is_done(struct wa_xfer *xfer)
{
struct device *dev = &xfer->wa->usb_iface->dev;
unsigned result, cnt;
struct wa_seg *seg;
struct urb *urb = xfer->urb;
unsigned found_short = 0;
result = xfer->segs_done == xfer->segs_submitted;
if (result == 0)
goto out;
urb->actual_length = 0;
for (cnt = 0; cnt < xfer->segs; cnt++) {
seg = xfer->seg[cnt];
switch (seg->status) {
case WA_SEG_DONE:
if (found_short && seg->result > 0) {
dev_dbg(dev, "xfer %p#%u: bad short segments (%zu)\n",
xfer, cnt, seg->result);
urb->status = -EINVAL;
goto out;
}
urb->actual_length += seg->result;
if (seg->result < xfer->seg_size
&& cnt != xfer->segs-1)
found_short = 1;
dev_dbg(dev, "xfer %p#%u: DONE short %d "
"result %zu urb->actual_length %d\n",
xfer, seg->index, found_short, seg->result,
urb->actual_length);
break;
case WA_SEG_ERROR:
xfer->result = seg->result;
dev_dbg(dev, "xfer %p#%u: ERROR result %zu\n",
xfer, seg->index, seg->result);
goto out;
case WA_SEG_ABORTED:
dev_dbg(dev, "xfer %p#%u ABORTED: result %d\n",
xfer, seg->index, urb->status);
xfer->result = urb->status;
goto out;
default:
dev_warn(dev, "xfer %p#%u: is_done bad state %d\n",
xfer, cnt, seg->status);
xfer->result = -EINVAL;
goto out;
}
}
xfer->result = 0;
out:
return result;
}
static void wa_xfer_id_init(struct wa_xfer *xfer)
{
xfer->id = atomic_add_return(1, &xfer->wa->xfer_id_count);
}
static u32 wa_xfer_id(struct wa_xfer *xfer)
{
return xfer->id;
}
static struct wa_xfer *wa_xfer_get_by_id(struct wahc *wa, u32 id)
{
unsigned long flags;
struct wa_xfer *xfer_itr;
spin_lock_irqsave(&wa->xfer_list_lock, flags);
list_for_each_entry(xfer_itr, &wa->xfer_list, list_node) {
if (id == xfer_itr->id) {
wa_xfer_get(xfer_itr);
goto out;
}
}
xfer_itr = NULL;
out:
spin_unlock_irqrestore(&wa->xfer_list_lock, flags);
return xfer_itr;
}
static void __wa_xfer_abort_cb(struct urb *urb)
{
struct wa_xfer_abort_buffer *b = urb->context;
usb_put_urb(&b->urb);
}
static void __wa_xfer_abort(struct wa_xfer *xfer)
{
int result;
struct device *dev = &xfer->wa->usb_iface->dev;
struct wa_xfer_abort_buffer *b;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
b = kmalloc(sizeof(*b), GFP_ATOMIC);
if (b == NULL)
goto error_kmalloc;
b->cmd.bLength = sizeof(b->cmd);
b->cmd.bRequestType = WA_XFER_ABORT;
b->cmd.wRPipe = rpipe->descr.wRPipeIndex;
b->cmd.dwTransferID = wa_xfer_id(xfer);
usb_init_urb(&b->urb);
usb_fill_bulk_urb(&b->urb, xfer->wa->usb_dev,
usb_sndbulkpipe(xfer->wa->usb_dev,
xfer->wa->dto_epd->bEndpointAddress),
&b->cmd, sizeof(b->cmd), __wa_xfer_abort_cb, b);
result = usb_submit_urb(&b->urb, GFP_ATOMIC);
if (result < 0)
goto error_submit;
return;
error_submit:
if (printk_ratelimit())
dev_err(dev, "xfer %p: Can't submit abort request: %d\n",
xfer, result);
kfree(b);
error_kmalloc:
return;
}
static ssize_t __wa_xfer_setup_sizes(struct wa_xfer *xfer,
enum wa_xfer_type *pxfer_type)
{
ssize_t result;
struct device *dev = &xfer->wa->usb_iface->dev;
size_t maxpktsize;
struct urb *urb = xfer->urb;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
switch (rpipe->descr.bmAttribute & 0x3) {
case USB_ENDPOINT_XFER_CONTROL:
*pxfer_type = WA_XFER_TYPE_CTL;
result = sizeof(struct wa_xfer_ctl);
break;
case USB_ENDPOINT_XFER_INT:
case USB_ENDPOINT_XFER_BULK:
*pxfer_type = WA_XFER_TYPE_BI;
result = sizeof(struct wa_xfer_bi);
break;
case USB_ENDPOINT_XFER_ISOC:
dev_err(dev, "FIXME: ISOC not implemented\n");
result = -ENOSYS;
goto error;
default:
BUG();
result = -EINVAL;
};
xfer->is_inbound = urb->pipe & USB_DIR_IN ? 1 : 0;
xfer->is_dma = urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP ? 1 : 0;
xfer->seg_size = le16_to_cpu(rpipe->descr.wBlocks)
* 1 << (xfer->wa->wa_descr->bRPipeBlockSize - 1);
maxpktsize = le16_to_cpu(rpipe->descr.wMaxPacketSize);
if (xfer->seg_size < maxpktsize) {
dev_err(dev, "HW BUG? seg_size %zu smaller than maxpktsize "
"%zu\n", xfer->seg_size, maxpktsize);
result = -EINVAL;
goto error;
}
xfer->seg_size = (xfer->seg_size / maxpktsize) * maxpktsize;
xfer->segs = (urb->transfer_buffer_length + xfer->seg_size - 1)
/ xfer->seg_size;
if (xfer->segs >= WA_SEGS_MAX) {
dev_err(dev, "BUG? ops, number of segments %d bigger than %d\n",
(int)(urb->transfer_buffer_length / xfer->seg_size),
WA_SEGS_MAX);
result = -EINVAL;
goto error;
}
if (xfer->segs == 0 && *pxfer_type == WA_XFER_TYPE_CTL)
xfer->segs = 1;
error:
return result;
}
static void __wa_xfer_setup_hdr0(struct wa_xfer *xfer,
struct wa_xfer_hdr *xfer_hdr0,
enum wa_xfer_type xfer_type,
size_t xfer_hdr_size)
{
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
xfer_hdr0 = &xfer->seg[0]->xfer_hdr;
xfer_hdr0->bLength = xfer_hdr_size;
xfer_hdr0->bRequestType = xfer_type;
xfer_hdr0->wRPipe = rpipe->descr.wRPipeIndex;
xfer_hdr0->dwTransferID = wa_xfer_id(xfer);
xfer_hdr0->bTransferSegment = 0;
switch (xfer_type) {
case WA_XFER_TYPE_CTL: {
struct wa_xfer_ctl *xfer_ctl =
container_of(xfer_hdr0, struct wa_xfer_ctl, hdr);
xfer_ctl->bmAttribute = xfer->is_inbound ? 1 : 0;
memcpy(&xfer_ctl->baSetupData, xfer->urb->setup_packet,
sizeof(xfer_ctl->baSetupData));
break;
}
case WA_XFER_TYPE_BI:
break;
case WA_XFER_TYPE_ISO:
printk(KERN_ERR "FIXME: ISOC not implemented\n");
default:
BUG();
};
}
static void wa_seg_dto_cb(struct urb *urb)
{
struct wa_seg *seg = urb->context;
struct wa_xfer *xfer = seg->xfer;
struct wahc *wa;
struct device *dev;
struct wa_rpipe *rpipe;
unsigned long flags;
unsigned rpipe_ready = 0;
u8 done = 0;
switch (urb->status) {
case 0:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
dev_dbg(dev, "xfer %p#%u: data out done (%d bytes)\n",
xfer, seg->index, urb->actual_length);
if (seg->status < WA_SEG_PENDING)
seg->status = WA_SEG_PENDING;
seg->result = urb->actual_length;
spin_unlock_irqrestore(&xfer->lock, flags);
break;
case -ECONNRESET:
case -ENOENT:
break;
default:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
rpipe = xfer->ep->hcpriv;
dev_dbg(dev, "xfer %p#%u: data out error %d\n",
xfer, seg->index, urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
if (seg->status != WA_SEG_ERROR) {
seg->status = WA_SEG_ERROR;
seg->result = urb->status;
xfer->segs_done++;
__wa_xfer_abort(xfer);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_is_done(xfer);
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
}
static void wa_seg_cb(struct urb *urb)
{
struct wa_seg *seg = urb->context;
struct wa_xfer *xfer = seg->xfer;
struct wahc *wa;
struct device *dev;
struct wa_rpipe *rpipe;
unsigned long flags;
unsigned rpipe_ready;
u8 done = 0;
switch (urb->status) {
case 0:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
dev_dbg(dev, "xfer %p#%u: request done\n", xfer, seg->index);
if (xfer->is_inbound && seg->status < WA_SEG_PENDING)
seg->status = WA_SEG_PENDING;
spin_unlock_irqrestore(&xfer->lock, flags);
break;
case -ECONNRESET:
case -ENOENT:
break;
default:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
rpipe = xfer->ep->hcpriv;
if (printk_ratelimit())
dev_err(dev, "xfer %p#%u: request error %d\n",
xfer, seg->index, urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
usb_unlink_urb(seg->dto_urb);
seg->status = WA_SEG_ERROR;
seg->result = urb->status;
xfer->segs_done++;
__wa_xfer_abort(xfer);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
}
static int __wa_xfer_setup_segs(struct wa_xfer *xfer, size_t xfer_hdr_size)
{
int result, cnt;
size_t alloc_size = sizeof(*xfer->seg[0])
- sizeof(xfer->seg[0]->xfer_hdr) + xfer_hdr_size;
struct usb_device *usb_dev = xfer->wa->usb_dev;
const struct usb_endpoint_descriptor *dto_epd = xfer->wa->dto_epd;
struct wa_seg *seg;
size_t buf_itr, buf_size, buf_itr_size;
result = -ENOMEM;
xfer->seg = kcalloc(xfer->segs, sizeof(xfer->seg[0]), GFP_ATOMIC);
if (xfer->seg == NULL)
goto error_segs_kzalloc;
buf_itr = 0;
buf_size = xfer->urb->transfer_buffer_length;
for (cnt = 0; cnt < xfer->segs; cnt++) {
seg = xfer->seg[cnt] = kzalloc(alloc_size, GFP_ATOMIC);
if (seg == NULL)
goto error_seg_kzalloc;
wa_seg_init(seg);
seg->xfer = xfer;
seg->index = cnt;
usb_fill_bulk_urb(&seg->urb, usb_dev,
usb_sndbulkpipe(usb_dev,
dto_epd->bEndpointAddress),
&seg->xfer_hdr, xfer_hdr_size,
wa_seg_cb, seg);
buf_itr_size = buf_size > xfer->seg_size ?
xfer->seg_size : buf_size;
if (xfer->is_inbound == 0 && buf_size > 0) {
seg->dto_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (seg->dto_urb == NULL)
goto error_dto_alloc;
usb_fill_bulk_urb(
seg->dto_urb, usb_dev,
usb_sndbulkpipe(usb_dev,
dto_epd->bEndpointAddress),
NULL, 0, wa_seg_dto_cb, seg);
if (xfer->is_dma) {
seg->dto_urb->transfer_dma =
xfer->urb->transfer_dma + buf_itr;
seg->dto_urb->transfer_flags |=
URB_NO_TRANSFER_DMA_MAP;
} else
seg->dto_urb->transfer_buffer =
xfer->urb->transfer_buffer + buf_itr;
seg->dto_urb->transfer_buffer_length = buf_itr_size;
}
seg->status = WA_SEG_READY;
buf_itr += buf_itr_size;
buf_size -= buf_itr_size;
}
return 0;
error_dto_alloc:
kfree(xfer->seg[cnt]);
cnt--;
error_seg_kzalloc:
for (; cnt > 0; cnt--) {
if (xfer->is_inbound == 0)
kfree(xfer->seg[cnt]->dto_urb);
kfree(xfer->seg[cnt]);
}
error_segs_kzalloc:
return result;
}
static int __wa_xfer_setup(struct wa_xfer *xfer, struct urb *urb)
{
int result;
struct device *dev = &xfer->wa->usb_iface->dev;
enum wa_xfer_type xfer_type = 0;
size_t xfer_hdr_size, cnt, transfer_size;
struct wa_xfer_hdr *xfer_hdr0, *xfer_hdr;
result = __wa_xfer_setup_sizes(xfer, &xfer_type);
if (result < 0)
goto error_setup_sizes;
xfer_hdr_size = result;
result = __wa_xfer_setup_segs(xfer, xfer_hdr_size);
if (result < 0) {
dev_err(dev, "xfer %p: Failed to allocate %d segments: %d\n",
xfer, xfer->segs, result);
goto error_setup_segs;
}
xfer_hdr0 = &xfer->seg[0]->xfer_hdr;
wa_xfer_id_init(xfer);
__wa_xfer_setup_hdr0(xfer, xfer_hdr0, xfer_type, xfer_hdr_size);
xfer_hdr = xfer_hdr0;
transfer_size = urb->transfer_buffer_length;
xfer_hdr0->dwTransferLength = transfer_size > xfer->seg_size ?
xfer->seg_size : transfer_size;
transfer_size -= xfer->seg_size;
for (cnt = 1; cnt < xfer->segs; cnt++) {
xfer_hdr = &xfer->seg[cnt]->xfer_hdr;
memcpy(xfer_hdr, xfer_hdr0, xfer_hdr_size);
xfer_hdr->bTransferSegment = cnt;
xfer_hdr->dwTransferLength = transfer_size > xfer->seg_size ?
cpu_to_le32(xfer->seg_size)
: cpu_to_le32(transfer_size);
xfer->seg[cnt]->status = WA_SEG_READY;
transfer_size -= xfer->seg_size;
}
xfer_hdr->bTransferSegment |= 0x80;
result = 0;
error_setup_segs:
error_setup_sizes:
return result;
}
static int __wa_seg_submit(struct wa_rpipe *rpipe, struct wa_xfer *xfer,
struct wa_seg *seg)
{
int result;
result = usb_submit_urb(&seg->urb, GFP_ATOMIC);
if (result < 0) {
printk(KERN_ERR "xfer %p#%u: REQ submit failed: %d\n",
xfer, seg->index, result);
goto error_seg_submit;
}
if (seg->dto_urb) {
result = usb_submit_urb(seg->dto_urb, GFP_ATOMIC);
if (result < 0) {
printk(KERN_ERR "xfer %p#%u: DTO submit failed: %d\n",
xfer, seg->index, result);
goto error_dto_submit;
}
}
seg->status = WA_SEG_SUBMITTED;
rpipe_avail_dec(rpipe);
return 0;
error_dto_submit:
usb_unlink_urb(&seg->urb);
error_seg_submit:
seg->status = WA_SEG_ERROR;
seg->result = result;
return result;
}
static void wa_xfer_delayed_run(struct wa_rpipe *rpipe)
{
int result;
struct device *dev = &rpipe->wa->usb_iface->dev;
struct wa_seg *seg;
struct wa_xfer *xfer;
unsigned long flags;
spin_lock_irqsave(&rpipe->seg_lock, flags);
while (atomic_read(&rpipe->segs_available) > 0
&& !list_empty(&rpipe->seg_list)) {
seg = list_entry(rpipe->seg_list.next, struct wa_seg,
list_node);
list_del(&seg->list_node);
xfer = seg->xfer;
result = __wa_seg_submit(rpipe, xfer, seg);
dev_dbg(dev, "xfer %p#%u submitted from delayed [%d segments available] %d\n",
xfer, seg->index, atomic_read(&rpipe->segs_available), result);
if (unlikely(result < 0)) {
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
spin_lock_irqsave(&xfer->lock, flags);
__wa_xfer_abort(xfer);
xfer->segs_done++;
spin_unlock_irqrestore(&xfer->lock, flags);
spin_lock_irqsave(&rpipe->seg_lock, flags);
}
}
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
}
static int __wa_xfer_submit(struct wa_xfer *xfer)
{
int result;
struct wahc *wa = xfer->wa;
struct device *dev = &wa->usb_iface->dev;
unsigned cnt;
struct wa_seg *seg;
unsigned long flags;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
size_t maxrequests = le16_to_cpu(rpipe->descr.wRequests);
u8 available;
u8 empty;
spin_lock_irqsave(&wa->xfer_list_lock, flags);
list_add_tail(&xfer->list_node, &wa->xfer_list);
spin_unlock_irqrestore(&wa->xfer_list_lock, flags);
BUG_ON(atomic_read(&rpipe->segs_available) > maxrequests);
result = 0;
spin_lock_irqsave(&rpipe->seg_lock, flags);
for (cnt = 0; cnt < xfer->segs; cnt++) {
available = atomic_read(&rpipe->segs_available);
empty = list_empty(&rpipe->seg_list);
seg = xfer->seg[cnt];
dev_dbg(dev, "xfer %p#%u: available %u empty %u (%s)\n",
xfer, cnt, available, empty,
available == 0 || !empty ? "delayed" : "submitted");
if (available == 0 || !empty) {
dev_dbg(dev, "xfer %p#%u: delayed\n", xfer, cnt);
seg->status = WA_SEG_DELAYED;
list_add_tail(&seg->list_node, &rpipe->seg_list);
} else {
result = __wa_seg_submit(rpipe, xfer, seg);
if (result < 0) {
__wa_xfer_abort(xfer);
goto error_seg_submit;
}
}
xfer->segs_submitted++;
}
error_seg_submit:
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
return result;
}
static void wa_urb_enqueue_b(struct wa_xfer *xfer)
{
int result;
unsigned long flags;
struct urb *urb = xfer->urb;
struct wahc *wa = xfer->wa;
struct wusbhc *wusbhc = wa->wusb;
struct wusb_dev *wusb_dev;
unsigned done;
result = rpipe_get_by_ep(wa, xfer->ep, urb, xfer->gfp);
if (result < 0)
goto error_rpipe_get;
result = -ENODEV;
mutex_lock(&wusbhc->mutex);
if (urb->dev == NULL) {
mutex_unlock(&wusbhc->mutex);
goto error_dev_gone;
}
wusb_dev = __wusb_dev_get_by_usb_dev(wusbhc, urb->dev);
if (wusb_dev == NULL) {
mutex_unlock(&wusbhc->mutex);
goto error_dev_gone;
}
mutex_unlock(&wusbhc->mutex);
spin_lock_irqsave(&xfer->lock, flags);
xfer->wusb_dev = wusb_dev;
result = urb->status;
if (urb->status != -EINPROGRESS)
goto error_dequeued;
result = __wa_xfer_setup(xfer, urb);
if (result < 0)
goto error_xfer_setup;
result = __wa_xfer_submit(xfer);
if (result < 0)
goto error_xfer_submit;
spin_unlock_irqrestore(&xfer->lock, flags);
return;
error_xfer_setup:
error_dequeued:
spin_unlock_irqrestore(&xfer->lock, flags);
if (wusb_dev)
wusb_dev_put(wusb_dev);
error_dev_gone:
rpipe_put(xfer->ep->hcpriv);
error_rpipe_get:
xfer->result = result;
wa_xfer_giveback(xfer);
return;
error_xfer_submit:
done = __wa_xfer_is_done(xfer);
xfer->result = result;
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
}
void wa_urb_enqueue_run(struct work_struct *ws)
{
struct wahc *wa = container_of(ws, struct wahc, xfer_work);
struct wa_xfer *xfer, *next;
struct urb *urb;
spin_lock_irq(&wa->xfer_list_lock);
list_for_each_entry_safe(xfer, next, &wa->xfer_delayed_list,
list_node) {
list_del_init(&xfer->list_node);
spin_unlock_irq(&wa->xfer_list_lock);
urb = xfer->urb;
wa_urb_enqueue_b(xfer);
usb_put_urb(urb);
spin_lock_irq(&wa->xfer_list_lock);
}
spin_unlock_irq(&wa->xfer_list_lock);
}
int wa_urb_enqueue(struct wahc *wa, struct usb_host_endpoint *ep,
struct urb *urb, gfp_t gfp)
{
int result;
struct device *dev = &wa->usb_iface->dev;
struct wa_xfer *xfer;
unsigned long my_flags;
unsigned cant_sleep = irqs_disabled() | in_atomic();
if (urb->transfer_buffer == NULL
&& !(urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP)
&& urb->transfer_buffer_length != 0) {
dev_err(dev, "BUG? urb %p: NULL xfer buffer & NODMA\n", urb);
dump_stack();
}
result = -ENOMEM;
xfer = kzalloc(sizeof(*xfer), gfp);
if (xfer == NULL)
goto error_kmalloc;
result = -ENOENT;
if (urb->status != -EINPROGRESS)
goto error_dequeued;
wa_xfer_init(xfer);
xfer->wa = wa_get(wa);
xfer->urb = urb;
xfer->gfp = gfp;
xfer->ep = ep;
urb->hcpriv = xfer;
dev_dbg(dev, "xfer %p urb %p pipe 0x%02x [%d bytes] %s %s %s\n",
xfer, urb, urb->pipe, urb->transfer_buffer_length,
urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP ? "dma" : "nodma",
urb->pipe & USB_DIR_IN ? "inbound" : "outbound",
cant_sleep ? "deferred" : "inline");
if (cant_sleep) {
usb_get_urb(urb);
spin_lock_irqsave(&wa->xfer_list_lock, my_flags);
list_add_tail(&xfer->list_node, &wa->xfer_delayed_list);
spin_unlock_irqrestore(&wa->xfer_list_lock, my_flags);
queue_work(wusbd, &wa->xfer_work);
} else {
wa_urb_enqueue_b(xfer);
}
return 0;
error_dequeued:
kfree(xfer);
error_kmalloc:
return result;
}
int wa_urb_dequeue(struct wahc *wa, struct urb *urb)
{
unsigned long flags, flags2;
struct wa_xfer *xfer;
struct wa_seg *seg;
struct wa_rpipe *rpipe;
unsigned cnt;
unsigned rpipe_ready = 0;
xfer = urb->hcpriv;
if (xfer == NULL) {
BUG_ON(urb->status == -EINPROGRESS);
goto out;
}
spin_lock_irqsave(&xfer->lock, flags);
rpipe = xfer->ep->hcpriv;
spin_lock_irqsave(&wa->xfer_list_lock, flags2);
if (!list_empty(&xfer->list_node) && xfer->seg == NULL)
goto dequeue_delayed;
spin_unlock_irqrestore(&wa->xfer_list_lock, flags2);
if (xfer->seg == NULL)
goto out_unlock;
__wa_xfer_abort(xfer);
for (cnt = 0; cnt < xfer->segs; cnt++) {
seg = xfer->seg[cnt];
switch (seg->status) {
case WA_SEG_NOTREADY:
case WA_SEG_READY:
printk(KERN_ERR "xfer %p#%u: dequeue bad state %u\n",
xfer, cnt, seg->status);
WARN_ON(1);
break;
case WA_SEG_DELAYED:
seg->status = WA_SEG_ABORTED;
spin_lock_irqsave(&rpipe->seg_lock, flags2);
list_del(&seg->list_node);
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
spin_unlock_irqrestore(&rpipe->seg_lock, flags2);
break;
case WA_SEG_SUBMITTED:
seg->status = WA_SEG_ABORTED;
usb_unlink_urb(&seg->urb);
if (xfer->is_inbound == 0)
usb_unlink_urb(seg->dto_urb);
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
break;
case WA_SEG_PENDING:
seg->status = WA_SEG_ABORTED;
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
break;
case WA_SEG_DTI_PENDING:
usb_unlink_urb(wa->dti_urb);
seg->status = WA_SEG_ABORTED;
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
break;
case WA_SEG_DONE:
case WA_SEG_ERROR:
case WA_SEG_ABORTED:
break;
}
}
xfer->result = urb->status;
__wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
return 0;
out_unlock:
spin_unlock_irqrestore(&xfer->lock, flags);
out:
return 0;
dequeue_delayed:
list_del_init(&xfer->list_node);
spin_unlock_irqrestore(&wa->xfer_list_lock, flags2);
xfer->result = urb->status;
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_giveback(xfer);
usb_put_urb(urb);
return 0;
}
static int wa_xfer_status_to_errno(u8 status)
{
int errno;
u8 real_status = status;
static int xlat[] = {
[WA_XFER_STATUS_SUCCESS] = 0,
[WA_XFER_STATUS_HALTED] = -EPIPE,
[WA_XFER_STATUS_DATA_BUFFER_ERROR] = -ENOBUFS,
[WA_XFER_STATUS_BABBLE] = -EOVERFLOW,
[WA_XFER_RESERVED] = EINVAL,
[WA_XFER_STATUS_NOT_FOUND] = 0,
[WA_XFER_STATUS_INSUFFICIENT_RESOURCE] = -ENOMEM,
[WA_XFER_STATUS_TRANSACTION_ERROR] = -EILSEQ,
[WA_XFER_STATUS_ABORTED] = -EINTR,
[WA_XFER_STATUS_RPIPE_NOT_READY] = EINVAL,
[WA_XFER_INVALID_FORMAT] = EINVAL,
[WA_XFER_UNEXPECTED_SEGMENT_NUMBER] = EINVAL,
[WA_XFER_STATUS_RPIPE_TYPE_MISMATCH] = EINVAL,
};
status &= 0x3f;
if (status == 0)
return 0;
if (status >= ARRAY_SIZE(xlat)) {
printk_ratelimited(KERN_ERR "%s(): BUG? "
"Unknown WA transfer status 0x%02x\n",
__func__, real_status);
return -EINVAL;
}
errno = xlat[status];
if (unlikely(errno > 0)) {
printk_ratelimited(KERN_ERR "%s(): BUG? "
"Inconsistent WA status: 0x%02x\n",
__func__, real_status);
errno = -errno;
}
return errno;
}
static void wa_xfer_result_chew(struct wahc *wa, struct wa_xfer *xfer)
{
int result;
struct device *dev = &wa->usb_iface->dev;
unsigned long flags;
u8 seg_idx;
struct wa_seg *seg;
struct wa_rpipe *rpipe;
struct wa_xfer_result *xfer_result = wa->xfer_result;
u8 done = 0;
u8 usb_status;
unsigned rpipe_ready = 0;
spin_lock_irqsave(&xfer->lock, flags);
seg_idx = xfer_result->bTransferSegment & 0x7f;
if (unlikely(seg_idx >= xfer->segs))
goto error_bad_seg;
seg = xfer->seg[seg_idx];
rpipe = xfer->ep->hcpriv;
usb_status = xfer_result->bTransferStatus;
dev_dbg(dev, "xfer %p#%u: bTransferStatus 0x%02x (seg %u)\n",
xfer, seg_idx, usb_status, seg->status);
if (seg->status == WA_SEG_ABORTED
|| seg->status == WA_SEG_ERROR)
goto segment_aborted;
if (seg->status == WA_SEG_SUBMITTED)
seg->status = WA_SEG_PENDING;
if (seg->status != WA_SEG_PENDING) {
if (printk_ratelimit())
dev_err(dev, "xfer %p#%u: Bad segment state %u\n",
xfer, seg_idx, seg->status);
seg->status = WA_SEG_PENDING;
}
if (usb_status & 0x80) {
seg->result = wa_xfer_status_to_errno(usb_status);
dev_err(dev, "DTI: xfer %p#%u failed (0x%02x)\n",
xfer, seg->index, usb_status);
goto error_complete;
}
if (usb_status & 0x40)
usb_status = 0;
if (xfer->is_inbound) {
seg->status = WA_SEG_DTI_PENDING;
BUG_ON(wa->buf_in_urb->status == -EINPROGRESS);
if (xfer->is_dma) {
wa->buf_in_urb->transfer_dma =
xfer->urb->transfer_dma
+ seg_idx * xfer->seg_size;
wa->buf_in_urb->transfer_flags
|= URB_NO_TRANSFER_DMA_MAP;
} else {
wa->buf_in_urb->transfer_buffer =
xfer->urb->transfer_buffer
+ seg_idx * xfer->seg_size;
wa->buf_in_urb->transfer_flags
&= ~URB_NO_TRANSFER_DMA_MAP;
}
wa->buf_in_urb->transfer_buffer_length =
le32_to_cpu(xfer_result->dwTransferLength);
wa->buf_in_urb->context = seg;
result = usb_submit_urb(wa->buf_in_urb, GFP_ATOMIC);
if (result < 0)
goto error_submit_buf_in;
} else {
seg->status = WA_SEG_DONE;
seg->result = le32_to_cpu(xfer_result->dwTransferLength);
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_is_done(xfer);
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
return;
error_submit_buf_in:
if (edc_inc(&wa->dti_edc, EDC_MAX_ERRORS, EDC_ERROR_TIMEFRAME)) {
dev_err(dev, "DTI: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
if (printk_ratelimit())
dev_err(dev, "xfer %p#%u: can't submit DTI data phase: %d\n",
xfer, seg_idx, result);
seg->result = result;
error_complete:
seg->status = WA_SEG_ERROR;
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
__wa_xfer_abort(xfer);
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
return;
error_bad_seg:
spin_unlock_irqrestore(&xfer->lock, flags);
wa_urb_dequeue(wa, xfer->urb);
if (printk_ratelimit())
dev_err(dev, "xfer %p#%u: bad segment\n", xfer, seg_idx);
if (edc_inc(&wa->dti_edc, EDC_MAX_ERRORS, EDC_ERROR_TIMEFRAME)) {
dev_err(dev, "DTI: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
return;
segment_aborted:
spin_unlock_irqrestore(&xfer->lock, flags);
}
static void wa_buf_in_cb(struct urb *urb)
{
struct wa_seg *seg = urb->context;
struct wa_xfer *xfer = seg->xfer;
struct wahc *wa;
struct device *dev;
struct wa_rpipe *rpipe;
unsigned rpipe_ready;
unsigned long flags;
u8 done = 0;
switch (urb->status) {
case 0:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
rpipe = xfer->ep->hcpriv;
dev_dbg(dev, "xfer %p#%u: data in done (%zu bytes)\n",
xfer, seg->index, (size_t)urb->actual_length);
seg->status = WA_SEG_DONE;
seg->result = urb->actual_length;
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
break;
case -ECONNRESET:
case -ENOENT:
break;
default:
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
rpipe = xfer->ep->hcpriv;
if (printk_ratelimit())
dev_err(dev, "xfer %p#%u: data in error %d\n",
xfer, seg->index, urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
seg->status = WA_SEG_ERROR;
seg->result = urb->status;
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
__wa_xfer_abort(xfer);
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
}
static void wa_xfer_result_cb(struct urb *urb)
{
int result;
struct wahc *wa = urb->context;
struct device *dev = &wa->usb_iface->dev;
struct wa_xfer_result *xfer_result;
u32 xfer_id;
struct wa_xfer *xfer;
u8 usb_status;
BUG_ON(wa->dti_urb != urb);
switch (wa->dti_urb->status) {
case 0:
dev_dbg(dev, "DTI: xfer result %d bytes at %p\n",
urb->actual_length, urb->transfer_buffer);
if (wa->dti_urb->actual_length != sizeof(*xfer_result)) {
dev_err(dev, "DTI Error: xfer result--bad size "
"xfer result (%d bytes vs %zu needed)\n",
urb->actual_length, sizeof(*xfer_result));
break;
}
xfer_result = wa->xfer_result;
if (xfer_result->hdr.bLength != sizeof(*xfer_result)) {
dev_err(dev, "DTI Error: xfer result--"
"bad header length %u\n",
xfer_result->hdr.bLength);
break;
}
if (xfer_result->hdr.bNotifyType != WA_XFER_RESULT) {
dev_err(dev, "DTI Error: xfer result--"
"bad header type 0x%02x\n",
xfer_result->hdr.bNotifyType);
break;
}
usb_status = xfer_result->bTransferStatus & 0x3f;
if (usb_status == WA_XFER_STATUS_ABORTED
|| usb_status == WA_XFER_STATUS_NOT_FOUND)
break;
xfer_id = xfer_result->dwTransferID;
xfer = wa_xfer_get_by_id(wa, xfer_id);
if (xfer == NULL) {
dev_err(dev, "DTI Error: xfer result--"
"unknown xfer 0x%08x (status 0x%02x)\n",
xfer_id, usb_status);
break;
}
wa_xfer_result_chew(wa, xfer);
wa_xfer_put(xfer);
break;
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "DTI: going down! %d\n", urb->status);
goto out;
default:
if (edc_inc(&wa->dti_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)) {
dev_err(dev, "DTI: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
goto out;
}
if (printk_ratelimit())
dev_err(dev, "DTI: URB error %d\n", urb->status);
break;
}
result = usb_submit_urb(wa->dti_urb, GFP_ATOMIC);
if (result < 0) {
dev_err(dev, "DTI Error: Could not submit DTI URB (%d), "
"resetting\n", result);
wa_reset_all(wa);
}
out:
return;
}
void wa_handle_notif_xfer(struct wahc *wa, struct wa_notif_hdr *notif_hdr)
{
int result;
struct device *dev = &wa->usb_iface->dev;
struct wa_notif_xfer *notif_xfer;
const struct usb_endpoint_descriptor *dti_epd = wa->dti_epd;
notif_xfer = container_of(notif_hdr, struct wa_notif_xfer, hdr);
BUG_ON(notif_hdr->bNotifyType != WA_NOTIF_TRANSFER);
if ((0x80 | notif_xfer->bEndpoint) != dti_epd->bEndpointAddress) {
dev_err(dev, "BUG: DTI ep is %u, not %u (hack me)\n",
notif_xfer->bEndpoint, dti_epd->bEndpointAddress);
goto error;
}
if (wa->dti_urb != NULL)
goto out;
wa->dti_urb = usb_alloc_urb(0, GFP_KERNEL);
if (wa->dti_urb == NULL) {
dev_err(dev, "Can't allocate DTI URB\n");
goto error_dti_urb_alloc;
}
usb_fill_bulk_urb(
wa->dti_urb, wa->usb_dev,
usb_rcvbulkpipe(wa->usb_dev, 0x80 | notif_xfer->bEndpoint),
wa->xfer_result, wa->xfer_result_size,
wa_xfer_result_cb, wa);
wa->buf_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (wa->buf_in_urb == NULL) {
dev_err(dev, "Can't allocate BUF-IN URB\n");
goto error_buf_in_urb_alloc;
}
usb_fill_bulk_urb(
wa->buf_in_urb, wa->usb_dev,
usb_rcvbulkpipe(wa->usb_dev, 0x80 | notif_xfer->bEndpoint),
NULL, 0, wa_buf_in_cb, wa);
result = usb_submit_urb(wa->dti_urb, GFP_KERNEL);
if (result < 0) {
dev_err(dev, "DTI Error: Could not submit DTI URB (%d), "
"resetting\n", result);
goto error_dti_urb_submit;
}
out:
return;
error_dti_urb_submit:
usb_put_urb(wa->buf_in_urb);
error_buf_in_urb_alloc:
usb_put_urb(wa->dti_urb);
wa->dti_urb = NULL;
error_dti_urb_alloc:
error:
wa_reset_all(wa);
}
