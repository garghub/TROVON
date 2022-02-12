static inline void wa_seg_init(struct wa_seg *seg)
{
usb_init_urb(&seg->tr_urb);
memset(((void *)seg) + sizeof(seg->tr_urb), 0,
sizeof(*seg) - sizeof(seg->tr_urb));
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
struct wa_seg *seg = xfer->seg[cnt];
if (seg) {
usb_free_urb(seg->isoc_pack_desc_urb);
if (seg->dto_urb) {
kfree(seg->dto_urb->sg);
usb_free_urb(seg->dto_urb);
}
usb_free_urb(&seg->tr_urb);
}
}
kfree(xfer->seg);
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
static inline int __wa_dto_try_get(struct wahc *wa)
{
return (test_and_set_bit(0, &wa->dto_in_use) == 0);
}
static inline void __wa_dto_put(struct wahc *wa)
{
clear_bit_unlock(0, &wa->dto_in_use);
}
static void wa_check_for_delayed_rpipes(struct wahc *wa)
{
unsigned long flags;
int dto_waiting = 0;
struct wa_rpipe *rpipe;
spin_lock_irqsave(&wa->rpipe_lock, flags);
while (!list_empty(&wa->rpipe_delayed_list) && !dto_waiting) {
rpipe = list_first_entry(&wa->rpipe_delayed_list,
struct wa_rpipe, list_node);
__wa_xfer_delayed_run(rpipe, &dto_waiting);
if (!dto_waiting) {
pr_debug("%s: RPIPE %d serviced and removed from delayed list.\n",
__func__,
le16_to_cpu(rpipe->descr.wRPipeIndex));
list_del_init(&rpipe->list_node);
}
}
spin_unlock_irqrestore(&wa->rpipe_lock, flags);
}
static void wa_add_delayed_rpipe(struct wahc *wa, struct wa_rpipe *rpipe)
{
unsigned long flags;
spin_lock_irqsave(&wa->rpipe_lock, flags);
if (list_empty(&rpipe->list_node)) {
pr_debug("%s: adding RPIPE %d to the delayed list.\n",
__func__, le16_to_cpu(rpipe->descr.wRPipeIndex));
list_add_tail(&rpipe->list_node, &wa->rpipe_delayed_list);
}
spin_unlock_irqrestore(&wa->rpipe_lock, flags);
}
static void wa_xfer_giveback(struct wa_xfer *xfer)
{
unsigned long flags;
spin_lock_irqsave(&xfer->wa->xfer_list_lock, flags);
list_del_init(&xfer->list_node);
usb_hcd_unlink_urb_from_ep(&(xfer->wa->wusb->usb_hcd), xfer->urb);
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
static void wa_xfer_id_init(struct wa_xfer *xfer)
{
xfer->id = atomic_add_return(1, &xfer->wa->xfer_id_count);
}
static inline u32 wa_xfer_id(struct wa_xfer *xfer)
{
return xfer->id;
}
static inline __le32 wa_xfer_id_le32(struct wa_xfer *xfer)
{
return cpu_to_le32(xfer->id);
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
dev_dbg(dev, "xfer %p ID %08X#%u: bad short segments (%zu)\n",
xfer, wa_xfer_id(xfer), cnt,
seg->result);
urb->status = -EINVAL;
goto out;
}
urb->actual_length += seg->result;
if (!(usb_pipeisoc(xfer->urb->pipe))
&& seg->result < xfer->seg_size
&& cnt != xfer->segs-1)
found_short = 1;
dev_dbg(dev, "xfer %p ID %08X#%u: DONE short %d "
"result %zu urb->actual_length %d\n",
xfer, wa_xfer_id(xfer), seg->index, found_short,
seg->result, urb->actual_length);
break;
case WA_SEG_ERROR:
xfer->result = seg->result;
dev_dbg(dev, "xfer %p ID %08X#%u: ERROR result %zi(0x%08zX)\n",
xfer, wa_xfer_id(xfer), seg->index, seg->result,
seg->result);
goto out;
case WA_SEG_ABORTED:
xfer->result = seg->result;
dev_dbg(dev, "xfer %p ID %08X#%u: ABORTED result %zi(0x%08zX)\n",
xfer, wa_xfer_id(xfer), seg->index, seg->result,
seg->result);
goto out;
default:
dev_warn(dev, "xfer %p ID %08X#%u: is_done bad state %d\n",
xfer, wa_xfer_id(xfer), cnt, seg->status);
xfer->result = -EINVAL;
goto out;
}
}
xfer->result = 0;
out:
return result;
}
static unsigned __wa_xfer_mark_seg_as_done(struct wa_xfer *xfer,
struct wa_seg *seg, enum wa_seg_status status)
{
seg->status = status;
xfer->segs_done++;
return __wa_xfer_is_done(xfer);
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
struct wahc *wa = b->wa;
if (urb->status < 0) {
struct wa_xfer *xfer;
struct device *dev = &wa->usb_iface->dev;
xfer = wa_xfer_get_by_id(wa, le32_to_cpu(b->cmd.dwTransferID));
dev_err(dev, "%s: Transfer Abort request failed. result: %d\n",
__func__, urb->status);
if (xfer) {
unsigned long flags;
int done;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
dev_err(dev, "%s: cleaning up xfer %p ID 0x%08X.\n",
__func__, xfer, wa_xfer_id(xfer));
spin_lock_irqsave(&xfer->lock, flags);
wa_complete_remaining_xfer_segs(xfer, 0,
WA_SEG_ABORTED);
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
wa_xfer_delayed_run(rpipe);
wa_xfer_put(xfer);
} else {
dev_err(dev, "%s: xfer ID 0x%08X already gone.\n",
__func__, le32_to_cpu(b->cmd.dwTransferID));
}
}
wa_put(wa);
usb_put_urb(&b->urb);
}
static int __wa_xfer_abort(struct wa_xfer *xfer)
{
int result = -ENOMEM;
struct device *dev = &xfer->wa->usb_iface->dev;
struct wa_xfer_abort_buffer *b;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
b = kmalloc(sizeof(*b), GFP_ATOMIC);
if (b == NULL)
goto error_kmalloc;
b->cmd.bLength = sizeof(b->cmd);
b->cmd.bRequestType = WA_XFER_ABORT;
b->cmd.wRPipe = rpipe->descr.wRPipeIndex;
b->cmd.dwTransferID = wa_xfer_id_le32(xfer);
b->wa = wa_get(xfer->wa);
usb_init_urb(&b->urb);
usb_fill_bulk_urb(&b->urb, xfer->wa->usb_dev,
usb_sndbulkpipe(xfer->wa->usb_dev,
xfer->wa->dto_epd->bEndpointAddress),
&b->cmd, sizeof(b->cmd), __wa_xfer_abort_cb, b);
result = usb_submit_urb(&b->urb, GFP_ATOMIC);
if (result < 0)
goto error_submit;
return result;
error_submit:
wa_put(xfer->wa);
if (printk_ratelimit())
dev_err(dev, "xfer %p: Can't submit abort request: %d\n",
xfer, result);
kfree(b);
error_kmalloc:
return result;
}
static int __wa_seg_calculate_isoc_frame_count(struct wa_xfer *xfer,
int isoc_frame_offset, int *total_size)
{
int segment_size = 0, frame_count = 0;
int index = isoc_frame_offset;
struct usb_iso_packet_descriptor *iso_frame_desc =
xfer->urb->iso_frame_desc;
while ((index < xfer->urb->number_of_packets)
&& ((segment_size + iso_frame_desc[index].length)
<= xfer->seg_size)) {
if ((xfer->wa->quirks & WUSB_QUIRK_ALEREON_HWA_CONCAT_ISOC)
&& (xfer->is_inbound == 0)
&& (index > isoc_frame_offset)
&& ((iso_frame_desc[index - 1].offset +
iso_frame_desc[index - 1].length) !=
iso_frame_desc[index].offset))
break;
++frame_count;
segment_size += iso_frame_desc[index].length;
++index;
}
*total_size = segment_size;
return frame_count;
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
*pxfer_type = WA_XFER_TYPE_ISO;
result = sizeof(struct wa_xfer_hwaiso);
break;
default:
BUG();
result = -EINVAL;
}
xfer->is_inbound = urb->pipe & USB_DIR_IN ? 1 : 0;
xfer->is_dma = urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP ? 1 : 0;
maxpktsize = le16_to_cpu(rpipe->descr.wMaxPacketSize);
xfer->seg_size = le16_to_cpu(rpipe->descr.wBlocks)
* 1 << (xfer->wa->wa_descr->bRPipeBlockSize - 1);
if (xfer->seg_size < maxpktsize) {
dev_err(dev,
"HW BUG? seg_size %zu smaller than maxpktsize %zu\n",
xfer->seg_size, maxpktsize);
result = -EINVAL;
goto error;
}
xfer->seg_size = (xfer->seg_size / maxpktsize) * maxpktsize;
if ((rpipe->descr.bmAttribute & 0x3) == USB_ENDPOINT_XFER_ISOC) {
int index = 0;
xfer->segs = 0;
while (index < urb->number_of_packets) {
int seg_size;
index += __wa_seg_calculate_isoc_frame_count(xfer,
index, &seg_size);
++xfer->segs;
}
} else {
xfer->segs = DIV_ROUND_UP(urb->transfer_buffer_length,
xfer->seg_size);
if (xfer->segs == 0 && *pxfer_type == WA_XFER_TYPE_CTL)
xfer->segs = 1;
}
if (xfer->segs > WA_SEGS_MAX) {
dev_err(dev, "BUG? oops, number of segments %zu bigger than %d\n",
(urb->transfer_buffer_length/xfer->seg_size),
WA_SEGS_MAX);
result = -EINVAL;
goto error;
}
error:
return result;
}
static void __wa_setup_isoc_packet_descr(
struct wa_xfer_packet_info_hwaiso *packet_desc,
struct wa_xfer *xfer,
struct wa_seg *seg) {
struct usb_iso_packet_descriptor *iso_frame_desc =
xfer->urb->iso_frame_desc;
int frame_index;
packet_desc->bPacketType = WA_XFER_ISO_PACKET_INFO;
packet_desc->wLength = cpu_to_le16(sizeof(*packet_desc) +
(sizeof(packet_desc->PacketLength[0]) *
seg->isoc_frame_count));
for (frame_index = 0; frame_index < seg->isoc_frame_count;
++frame_index) {
int offset_index = frame_index + seg->isoc_frame_offset;
packet_desc->PacketLength[frame_index] =
cpu_to_le16(iso_frame_desc[offset_index].length);
}
}
static void __wa_xfer_setup_hdr0(struct wa_xfer *xfer,
struct wa_xfer_hdr *xfer_hdr0,
enum wa_xfer_type xfer_type,
size_t xfer_hdr_size)
{
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
struct wa_seg *seg = xfer->seg[0];
xfer_hdr0 = &seg->xfer_hdr;
xfer_hdr0->bLength = xfer_hdr_size;
xfer_hdr0->bRequestType = xfer_type;
xfer_hdr0->wRPipe = rpipe->descr.wRPipeIndex;
xfer_hdr0->dwTransferID = wa_xfer_id_le32(xfer);
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
case WA_XFER_TYPE_ISO: {
struct wa_xfer_hwaiso *xfer_iso =
container_of(xfer_hdr0, struct wa_xfer_hwaiso, hdr);
struct wa_xfer_packet_info_hwaiso *packet_desc =
((void *)xfer_iso) + xfer_hdr_size;
xfer_iso->dwNumOfPackets = cpu_to_le32(seg->isoc_frame_count);
__wa_setup_isoc_packet_descr(packet_desc, xfer, seg);
break;
}
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
int data_send_done = 1, release_dto = 0, holding_dto = 0;
u8 done = 0;
int result;
kfree(urb->sg);
urb->sg = NULL;
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
if (usb_pipeisoc(xfer->urb->pipe)) {
if (wa->quirks & WUSB_QUIRK_ALEREON_HWA_CONCAT_ISOC)
seg->isoc_frame_index += seg->isoc_frame_count;
else
seg->isoc_frame_index += 1;
if (seg->isoc_frame_index < seg->isoc_frame_count) {
data_send_done = 0;
holding_dto = 1;
if ((seg->isoc_frame_index + 1) >=
seg->isoc_frame_count)
release_dto = 1;
}
dev_dbg(dev, "xfer 0x%08X#%u: isoc frame = %d, holding_dto = %d, release_dto = %d.\n",
wa_xfer_id(xfer), seg->index, seg->isoc_frame_index,
holding_dto, release_dto);
}
spin_unlock_irqrestore(&xfer->lock, flags);
switch (urb->status) {
case 0:
spin_lock_irqsave(&xfer->lock, flags);
seg->result += urb->actual_length;
if (data_send_done) {
dev_dbg(dev, "xfer 0x%08X#%u: data out done (%zu bytes)\n",
wa_xfer_id(xfer), seg->index, seg->result);
if (seg->status < WA_SEG_PENDING)
seg->status = WA_SEG_PENDING;
} else {
__wa_populate_dto_urb_isoc(xfer, seg,
seg->isoc_frame_offset + seg->isoc_frame_index);
wa_xfer_get(xfer);
result = usb_submit_urb(seg->dto_urb, GFP_ATOMIC);
if (result < 0) {
dev_err(dev, "xfer 0x%08X#%u: DTO submit failed: %d\n",
wa_xfer_id(xfer), seg->index, result);
spin_unlock_irqrestore(&xfer->lock, flags);
goto error_dto_submit;
}
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (release_dto) {
__wa_dto_put(wa);
wa_check_for_delayed_rpipes(wa);
}
break;
case -ECONNRESET:
case -ENOENT:
if (holding_dto) {
__wa_dto_put(wa);
wa_check_for_delayed_rpipes(wa);
}
break;
default:
dev_err(dev, "xfer 0x%08X#%u: data out error %d\n",
wa_xfer_id(xfer), seg->index, urb->status);
goto error_default;
}
wa_xfer_put(xfer);
return;
error_dto_submit:
wa_xfer_put(xfer);
error_default:
spin_lock_irqsave(&xfer->lock, flags);
rpipe = xfer->ep->hcpriv;
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors exceeded, resetting device\n");
wa_reset_all(wa);
}
if (seg->status != WA_SEG_ERROR) {
seg->result = urb->status;
__wa_xfer_abort(xfer);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg, WA_SEG_ERROR);
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (holding_dto) {
__wa_dto_put(wa);
wa_check_for_delayed_rpipes(wa);
}
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
wa_xfer_put(xfer);
}
static void wa_seg_iso_pack_desc_cb(struct urb *urb)
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
dev_dbg(dev, "iso xfer %08X#%u: packet descriptor done\n",
wa_xfer_id(xfer), seg->index);
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
pr_err_ratelimited("iso xfer %08X#%u: packet descriptor error %d\n",
wa_xfer_id(xfer), seg->index, urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "iso xfer: URB max acceptable errors exceeded, resetting device\n");
wa_reset_all(wa);
}
if (seg->status != WA_SEG_ERROR) {
usb_unlink_urb(seg->dto_urb);
seg->result = urb->status;
__wa_xfer_abort(xfer);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg,
WA_SEG_ERROR);
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
wa_xfer_put(xfer);
}
static void wa_seg_tr_cb(struct urb *urb)
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
dev_dbg(dev, "xfer %p ID 0x%08X#%u: request done\n",
xfer, wa_xfer_id(xfer), seg->index);
if (xfer->is_inbound &&
seg->status < WA_SEG_PENDING &&
!(usb_pipeisoc(xfer->urb->pipe)))
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
dev_err(dev, "xfer %p ID 0x%08X#%u: request error %d\n",
xfer, wa_xfer_id(xfer), seg->index,
urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
usb_unlink_urb(seg->isoc_pack_desc_urb);
usb_unlink_urb(seg->dto_urb);
seg->result = urb->status;
__wa_xfer_abort(xfer);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg, WA_SEG_ERROR);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
wa_xfer_put(xfer);
}
static struct scatterlist *wa_xfer_create_subset_sg(struct scatterlist *in_sg,
const unsigned int bytes_transferred,
const unsigned int bytes_to_transfer, int *out_num_sgs)
{
struct scatterlist *out_sg;
unsigned int bytes_processed = 0, offset_into_current_page_data = 0,
nents;
struct scatterlist *current_xfer_sg = in_sg;
struct scatterlist *current_seg_sg, *last_seg_sg;
while ((current_xfer_sg) &&
(bytes_processed < bytes_transferred)) {
bytes_processed += current_xfer_sg->length;
if (bytes_processed <= bytes_transferred)
current_xfer_sg = sg_next(current_xfer_sg);
}
if (bytes_processed > bytes_transferred) {
offset_into_current_page_data = current_xfer_sg->length -
(bytes_processed - bytes_transferred);
}
nents = DIV_ROUND_UP((bytes_to_transfer +
offset_into_current_page_data +
current_xfer_sg->offset),
PAGE_SIZE);
out_sg = kmalloc((sizeof(struct scatterlist) * nents), GFP_ATOMIC);
if (out_sg) {
sg_init_table(out_sg, nents);
last_seg_sg = current_seg_sg = out_sg;
bytes_processed = 0;
nents = 0;
while ((bytes_processed < bytes_to_transfer) &&
current_seg_sg && current_xfer_sg) {
unsigned int page_len = min((current_xfer_sg->length -
offset_into_current_page_data),
(bytes_to_transfer - bytes_processed));
sg_set_page(current_seg_sg, sg_page(current_xfer_sg),
page_len,
current_xfer_sg->offset +
offset_into_current_page_data);
bytes_processed += page_len;
last_seg_sg = current_seg_sg;
current_seg_sg = sg_next(current_seg_sg);
current_xfer_sg = sg_next(current_xfer_sg);
offset_into_current_page_data = 0;
nents++;
}
sg_mark_end(last_seg_sg);
*out_num_sgs = nents;
}
return out_sg;
}
static void __wa_populate_dto_urb_isoc(struct wa_xfer *xfer,
struct wa_seg *seg, int curr_iso_frame)
{
seg->dto_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
seg->dto_urb->sg = NULL;
seg->dto_urb->num_sgs = 0;
seg->dto_urb->transfer_dma = xfer->urb->transfer_dma +
xfer->urb->iso_frame_desc[curr_iso_frame].offset;
if (xfer->wa->quirks & WUSB_QUIRK_ALEREON_HWA_CONCAT_ISOC)
seg->dto_urb->transfer_buffer_length = seg->isoc_size;
else
seg->dto_urb->transfer_buffer_length =
xfer->urb->iso_frame_desc[curr_iso_frame].length;
}
static int __wa_populate_dto_urb(struct wa_xfer *xfer,
struct wa_seg *seg, size_t buf_itr_offset, size_t buf_itr_size)
{
int result = 0;
if (xfer->is_dma) {
seg->dto_urb->transfer_dma =
xfer->urb->transfer_dma + buf_itr_offset;
seg->dto_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
seg->dto_urb->sg = NULL;
seg->dto_urb->num_sgs = 0;
} else {
seg->dto_urb->transfer_flags &=
~URB_NO_TRANSFER_DMA_MAP;
seg->dto_urb->num_mapped_sgs = 0;
if (xfer->urb->transfer_buffer) {
seg->dto_urb->transfer_buffer =
xfer->urb->transfer_buffer +
buf_itr_offset;
seg->dto_urb->sg = NULL;
seg->dto_urb->num_sgs = 0;
} else {
seg->dto_urb->transfer_buffer = NULL;
seg->dto_urb->sg = wa_xfer_create_subset_sg(
xfer->urb->sg,
buf_itr_offset, buf_itr_size,
&(seg->dto_urb->num_sgs));
if (!(seg->dto_urb->sg))
result = -ENOMEM;
}
}
seg->dto_urb->transfer_buffer_length = buf_itr_size;
return result;
}
static int __wa_xfer_setup_segs(struct wa_xfer *xfer, size_t xfer_hdr_size)
{
int result, cnt, isoc_frame_offset = 0;
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
size_t iso_pkt_descr_size = 0;
int seg_isoc_frame_count = 0, seg_isoc_size = 0;
if (usb_pipeisoc(xfer->urb->pipe)) {
seg_isoc_frame_count =
__wa_seg_calculate_isoc_frame_count(xfer,
isoc_frame_offset, &seg_isoc_size);
iso_pkt_descr_size =
sizeof(struct wa_xfer_packet_info_hwaiso) +
(seg_isoc_frame_count * sizeof(__le16));
}
seg = xfer->seg[cnt] = kmalloc(alloc_size + iso_pkt_descr_size,
GFP_ATOMIC);
if (seg == NULL)
goto error_seg_kmalloc;
wa_seg_init(seg);
seg->xfer = xfer;
seg->index = cnt;
usb_fill_bulk_urb(&seg->tr_urb, usb_dev,
usb_sndbulkpipe(usb_dev,
dto_epd->bEndpointAddress),
&seg->xfer_hdr, xfer_hdr_size,
wa_seg_tr_cb, seg);
buf_itr_size = min(buf_size, xfer->seg_size);
if (usb_pipeisoc(xfer->urb->pipe)) {
seg->isoc_frame_count = seg_isoc_frame_count;
seg->isoc_frame_offset = isoc_frame_offset;
seg->isoc_size = seg_isoc_size;
seg->isoc_pack_desc_urb =
usb_alloc_urb(0, GFP_ATOMIC);
if (seg->isoc_pack_desc_urb == NULL)
goto error_iso_pack_desc_alloc;
usb_fill_bulk_urb(
seg->isoc_pack_desc_urb, usb_dev,
usb_sndbulkpipe(usb_dev,
dto_epd->bEndpointAddress),
(void *)(&seg->xfer_hdr) +
xfer_hdr_size,
iso_pkt_descr_size,
wa_seg_iso_pack_desc_cb, seg);
isoc_frame_offset += seg_isoc_frame_count;
}
if (xfer->is_inbound == 0 && buf_size > 0) {
seg->dto_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (seg->dto_urb == NULL)
goto error_dto_alloc;
usb_fill_bulk_urb(
seg->dto_urb, usb_dev,
usb_sndbulkpipe(usb_dev,
dto_epd->bEndpointAddress),
NULL, 0, wa_seg_dto_cb, seg);
if (usb_pipeisoc(xfer->urb->pipe)) {
__wa_populate_dto_urb_isoc(xfer, seg,
seg->isoc_frame_offset);
} else {
result = __wa_populate_dto_urb(xfer, seg,
buf_itr, buf_itr_size);
if (result < 0)
goto error_seg_outbound_populate;
buf_itr += buf_itr_size;
buf_size -= buf_itr_size;
}
}
seg->status = WA_SEG_READY;
}
return 0;
error_seg_outbound_populate:
usb_free_urb(xfer->seg[cnt]->dto_urb);
error_dto_alloc:
usb_free_urb(xfer->seg[cnt]->isoc_pack_desc_urb);
error_iso_pack_desc_alloc:
kfree(xfer->seg[cnt]);
xfer->seg[cnt] = NULL;
error_seg_kmalloc:
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
if (xfer_type == WA_XFER_TYPE_ISO) {
xfer_hdr0->dwTransferLength =
cpu_to_le32(xfer->seg[0]->isoc_size);
for (cnt = 1; cnt < xfer->segs; cnt++) {
struct wa_xfer_packet_info_hwaiso *packet_desc;
struct wa_seg *seg = xfer->seg[cnt];
struct wa_xfer_hwaiso *xfer_iso;
xfer_hdr = &seg->xfer_hdr;
xfer_iso = container_of(xfer_hdr,
struct wa_xfer_hwaiso, hdr);
packet_desc = ((void *)xfer_hdr) + xfer_hdr_size;
memcpy(xfer_hdr, xfer_hdr0, xfer_hdr_size);
xfer_hdr->bTransferSegment = cnt;
xfer_hdr->dwTransferLength =
cpu_to_le32(seg->isoc_size);
xfer_iso->dwNumOfPackets =
cpu_to_le32(seg->isoc_frame_count);
__wa_setup_isoc_packet_descr(packet_desc, xfer, seg);
seg->status = WA_SEG_READY;
}
} else {
transfer_size = urb->transfer_buffer_length;
xfer_hdr0->dwTransferLength = transfer_size > xfer->seg_size ?
cpu_to_le32(xfer->seg_size) :
cpu_to_le32(transfer_size);
transfer_size -= xfer->seg_size;
for (cnt = 1; cnt < xfer->segs; cnt++) {
xfer_hdr = &xfer->seg[cnt]->xfer_hdr;
memcpy(xfer_hdr, xfer_hdr0, xfer_hdr_size);
xfer_hdr->bTransferSegment = cnt;
xfer_hdr->dwTransferLength =
transfer_size > xfer->seg_size ?
cpu_to_le32(xfer->seg_size)
: cpu_to_le32(transfer_size);
xfer->seg[cnt]->status = WA_SEG_READY;
transfer_size -= xfer->seg_size;
}
}
xfer_hdr->bTransferSegment |= 0x80;
result = 0;
error_setup_segs:
error_setup_sizes:
return result;
}
static int __wa_seg_submit(struct wa_rpipe *rpipe, struct wa_xfer *xfer,
struct wa_seg *seg, int *dto_done)
{
int result;
*dto_done = 1;
wa_xfer_get(xfer);
seg->status = WA_SEG_SUBMITTED;
result = usb_submit_urb(&seg->tr_urb, GFP_ATOMIC);
if (result < 0) {
pr_err("%s: xfer %p#%u: REQ submit failed: %d\n",
__func__, xfer, seg->index, result);
wa_xfer_put(xfer);
goto error_tr_submit;
}
if (seg->isoc_pack_desc_urb) {
wa_xfer_get(xfer);
result = usb_submit_urb(seg->isoc_pack_desc_urb, GFP_ATOMIC);
seg->isoc_frame_index = 0;
if (result < 0) {
pr_err("%s: xfer %p#%u: ISO packet descriptor submit failed: %d\n",
__func__, xfer, seg->index, result);
wa_xfer_put(xfer);
goto error_iso_pack_desc_submit;
}
}
if (seg->dto_urb) {
struct wahc *wa = xfer->wa;
wa_xfer_get(xfer);
result = usb_submit_urb(seg->dto_urb, GFP_ATOMIC);
if (result < 0) {
pr_err("%s: xfer %p#%u: DTO submit failed: %d\n",
__func__, xfer, seg->index, result);
wa_xfer_put(xfer);
goto error_dto_submit;
}
if (((wa->quirks & WUSB_QUIRK_ALEREON_HWA_CONCAT_ISOC) == 0)
&& (seg->isoc_frame_count > 1))
*dto_done = 0;
}
rpipe_avail_dec(rpipe);
return 0;
error_dto_submit:
usb_unlink_urb(seg->isoc_pack_desc_urb);
error_iso_pack_desc_submit:
usb_unlink_urb(&seg->tr_urb);
error_tr_submit:
seg->status = WA_SEG_ERROR;
seg->result = result;
*dto_done = 1;
return result;
}
static int __wa_xfer_delayed_run(struct wa_rpipe *rpipe, int *dto_waiting)
{
int result, dto_acquired = 0, dto_done = 0;
struct device *dev = &rpipe->wa->usb_iface->dev;
struct wa_seg *seg;
struct wa_xfer *xfer;
unsigned long flags;
*dto_waiting = 0;
spin_lock_irqsave(&rpipe->seg_lock, flags);
while (atomic_read(&rpipe->segs_available) > 0
&& !list_empty(&rpipe->seg_list)
&& (dto_acquired = __wa_dto_try_get(rpipe->wa))) {
seg = list_first_entry(&(rpipe->seg_list), struct wa_seg,
list_node);
list_del(&seg->list_node);
xfer = seg->xfer;
wa_xfer_get(xfer);
result = __wa_seg_submit(rpipe, xfer, seg, &dto_done);
if (dto_done)
__wa_dto_put(rpipe->wa);
dev_dbg(dev, "xfer %p ID %08X#%u submitted from delayed [%d segments available] %d\n",
xfer, wa_xfer_id(xfer), seg->index,
atomic_read(&rpipe->segs_available), result);
if (unlikely(result < 0)) {
int done;
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
spin_lock_irqsave(&xfer->lock, flags);
__wa_xfer_abort(xfer);
xfer->segs_done++;
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
spin_lock_irqsave(&rpipe->seg_lock, flags);
}
wa_xfer_put(xfer);
}
if (!dto_acquired && !list_empty(&rpipe->seg_list)
&& (atomic_read(&rpipe->segs_available) ==
le16_to_cpu(rpipe->descr.wRequests)))
*dto_waiting = 1;
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
return dto_done;
}
static void wa_xfer_delayed_run(struct wa_rpipe *rpipe)
{
int dto_waiting;
int dto_done = __wa_xfer_delayed_run(rpipe, &dto_waiting);
if (dto_waiting)
wa_add_delayed_rpipe(rpipe->wa, rpipe);
else if (dto_done)
wa_check_for_delayed_rpipes(rpipe->wa);
}
static int __wa_xfer_submit(struct wa_xfer *xfer)
{
int result, dto_acquired = 0, dto_done = 0, dto_waiting = 0;
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
int delay_seg = 1;
available = atomic_read(&rpipe->segs_available);
empty = list_empty(&rpipe->seg_list);
seg = xfer->seg[cnt];
if (available && empty) {
dto_acquired = __wa_dto_try_get(rpipe->wa);
if (dto_acquired) {
delay_seg = 0;
result = __wa_seg_submit(rpipe, xfer, seg,
&dto_done);
dev_dbg(dev, "xfer %p ID 0x%08X#%u: available %u empty %u submitted\n",
xfer, wa_xfer_id(xfer), cnt, available,
empty);
if (dto_done)
__wa_dto_put(rpipe->wa);
if (result < 0) {
__wa_xfer_abort(xfer);
goto error_seg_submit;
}
}
}
if (delay_seg) {
dev_dbg(dev, "xfer %p ID 0x%08X#%u: available %u empty %u delayed\n",
xfer, wa_xfer_id(xfer), cnt, available, empty);
seg->status = WA_SEG_DELAYED;
list_add_tail(&seg->list_node, &rpipe->seg_list);
}
xfer->segs_submitted++;
}
error_seg_submit:
if (!dto_acquired && !list_empty(&rpipe->seg_list)
&& (atomic_read(&rpipe->segs_available) ==
le16_to_cpu(rpipe->descr.wRequests)))
dto_waiting = 1;
spin_unlock_irqrestore(&rpipe->seg_lock, flags);
if (dto_waiting)
wa_add_delayed_rpipe(rpipe->wa, rpipe);
else if (dto_done)
wa_check_for_delayed_rpipes(rpipe->wa);
return result;
}
static int wa_urb_enqueue_b(struct wa_xfer *xfer)
{
int result;
unsigned long flags;
struct urb *urb = xfer->urb;
struct wahc *wa = xfer->wa;
struct wusbhc *wusbhc = wa->wusb;
struct wusb_dev *wusb_dev;
unsigned done;
result = rpipe_get_by_ep(wa, xfer->ep, urb, xfer->gfp);
if (result < 0) {
pr_err("%s: error_rpipe_get\n", __func__);
goto error_rpipe_get;
}
result = -ENODEV;
mutex_lock(&wusbhc->mutex);
if (urb->dev == NULL) {
mutex_unlock(&wusbhc->mutex);
pr_err("%s: error usb dev gone\n", __func__);
goto error_dev_gone;
}
wusb_dev = __wusb_dev_get_by_usb_dev(wusbhc, urb->dev);
if (wusb_dev == NULL) {
mutex_unlock(&wusbhc->mutex);
dev_err(&(urb->dev->dev), "%s: error wusb dev gone\n",
__func__);
goto error_dev_gone;
}
mutex_unlock(&wusbhc->mutex);
spin_lock_irqsave(&xfer->lock, flags);
xfer->wusb_dev = wusb_dev;
result = urb->status;
if (urb->status != -EINPROGRESS) {
dev_err(&(urb->dev->dev), "%s: error_dequeued\n", __func__);
goto error_dequeued;
}
result = __wa_xfer_setup(xfer, urb);
if (result < 0) {
dev_err(&(urb->dev->dev), "%s: error_xfer_setup\n", __func__);
goto error_xfer_setup;
}
wa_xfer_get(xfer);
result = __wa_xfer_submit(xfer);
if (result < 0) {
dev_err(&(urb->dev->dev), "%s: error_xfer_submit\n", __func__);
goto error_xfer_submit;
}
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_put(xfer);
return 0;
error_xfer_setup:
error_dequeued:
spin_unlock_irqrestore(&xfer->lock, flags);
if (wusb_dev)
wusb_dev_put(wusb_dev);
error_dev_gone:
rpipe_put(xfer->ep->hcpriv);
error_rpipe_get:
xfer->result = result;
return result;
error_xfer_submit:
done = __wa_xfer_is_done(xfer);
xfer->result = result;
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
wa_xfer_put(xfer);
return 0;
}
void wa_urb_enqueue_run(struct work_struct *ws)
{
struct wahc *wa = container_of(ws, struct wahc, xfer_enqueue_work);
struct wa_xfer *xfer, *next;
struct urb *urb;
LIST_HEAD(tmp_list);
spin_lock_irq(&wa->xfer_list_lock);
list_cut_position(&tmp_list, &wa->xfer_delayed_list,
wa->xfer_delayed_list.prev);
spin_unlock_irq(&wa->xfer_list_lock);
list_for_each_entry_safe(xfer, next, &tmp_list, list_node) {
list_del_init(&xfer->list_node);
urb = xfer->urb;
if (wa_urb_enqueue_b(xfer) < 0)
wa_xfer_giveback(xfer);
usb_put_urb(urb);
}
}
void wa_process_errored_transfers_run(struct work_struct *ws)
{
struct wahc *wa = container_of(ws, struct wahc, xfer_error_work);
struct wa_xfer *xfer, *next;
LIST_HEAD(tmp_list);
pr_info("%s: Run delayed STALL processing.\n", __func__);
spin_lock_irq(&wa->xfer_list_lock);
list_cut_position(&tmp_list, &wa->xfer_errored_list,
wa->xfer_errored_list.prev);
spin_unlock_irq(&wa->xfer_list_lock);
list_for_each_entry_safe(xfer, next, &tmp_list, list_node) {
struct usb_host_endpoint *ep;
unsigned long flags;
struct wa_rpipe *rpipe;
spin_lock_irqsave(&xfer->lock, flags);
ep = xfer->ep;
rpipe = ep->hcpriv;
spin_unlock_irqrestore(&xfer->lock, flags);
rpipe_clear_feature_stalled(wa, ep);
wa_xfer_completion(xfer);
wa_xfer_delayed_run(rpipe);
}
}
int wa_urb_enqueue(struct wahc *wa, struct usb_host_endpoint *ep,
struct urb *urb, gfp_t gfp)
{
int result;
struct device *dev = &wa->usb_iface->dev;
struct wa_xfer *xfer;
unsigned long my_flags;
unsigned cant_sleep = irqs_disabled() | in_atomic();
if ((urb->transfer_buffer == NULL)
&& (urb->sg == NULL)
&& !(urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP)
&& urb->transfer_buffer_length != 0) {
dev_err(dev, "BUG? urb %p: NULL xfer buffer & NODMA\n", urb);
dump_stack();
}
spin_lock_irqsave(&wa->xfer_list_lock, my_flags);
result = usb_hcd_link_urb_to_ep(&(wa->wusb->usb_hcd), urb);
spin_unlock_irqrestore(&wa->xfer_list_lock, my_flags);
if (result < 0)
goto error_link_urb;
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
queue_work(wusbd, &wa->xfer_enqueue_work);
} else {
result = wa_urb_enqueue_b(xfer);
if (result < 0) {
dev_err(dev, "%s: URB enqueue failed: %d\n",
__func__, result);
wa_put(xfer->wa);
wa_xfer_put(xfer);
spin_lock_irqsave(&wa->xfer_list_lock, my_flags);
usb_hcd_unlink_urb_from_ep(&(wa->wusb->usb_hcd), urb);
spin_unlock_irqrestore(&wa->xfer_list_lock, my_flags);
return result;
}
}
return 0;
error_dequeued:
kfree(xfer);
error_kmalloc:
spin_lock_irqsave(&wa->xfer_list_lock, my_flags);
usb_hcd_unlink_urb_from_ep(&(wa->wusb->usb_hcd), urb);
spin_unlock_irqrestore(&wa->xfer_list_lock, my_flags);
error_link_urb:
return result;
}
int wa_urb_dequeue(struct wahc *wa, struct urb *urb, int status)
{
unsigned long flags, flags2;
struct wa_xfer *xfer;
struct wa_seg *seg;
struct wa_rpipe *rpipe;
unsigned cnt, done = 0, xfer_abort_pending;
unsigned rpipe_ready = 0;
int result;
spin_lock_irqsave(&wa->xfer_list_lock, flags);
result = usb_hcd_check_unlink_urb(&(wa->wusb->usb_hcd), urb, status);
if ((result == 0) && urb->hcpriv) {
wa_xfer_get(urb->hcpriv);
}
spin_unlock_irqrestore(&wa->xfer_list_lock, flags);
if (result)
return result;
xfer = urb->hcpriv;
if (xfer == NULL)
return -ENOENT;
spin_lock_irqsave(&xfer->lock, flags);
pr_debug("%s: DEQUEUE xfer id 0x%08X\n", __func__, wa_xfer_id(xfer));
rpipe = xfer->ep->hcpriv;
if (rpipe == NULL) {
pr_debug("%s: xfer %p id 0x%08X has no RPIPE. %s",
__func__, xfer, wa_xfer_id(xfer),
"Probably already aborted.\n" );
result = -ENOENT;
goto out_unlock;
}
if (__wa_xfer_is_done(xfer)) {
pr_debug("%s: xfer %p id 0x%08X already done.\n", __func__,
xfer, wa_xfer_id(xfer));
result = -ENOENT;
goto out_unlock;
}
spin_lock_irqsave(&wa->xfer_list_lock, flags2);
if (!list_empty(&xfer->list_node) && xfer->seg == NULL)
goto dequeue_delayed;
spin_unlock_irqrestore(&wa->xfer_list_lock, flags2);
if (xfer->seg == NULL)
goto out_unlock;
xfer_abort_pending = __wa_xfer_abort(xfer) >= 0;
spin_lock(&rpipe->seg_lock);
for (cnt = 0; cnt < xfer->segs; cnt++) {
seg = xfer->seg[cnt];
pr_debug("%s: xfer id 0x%08X#%d status = %d\n",
__func__, wa_xfer_id(xfer), cnt, seg->status);
switch (seg->status) {
case WA_SEG_NOTREADY:
case WA_SEG_READY:
printk(KERN_ERR "xfer %p#%u: dequeue bad state %u\n",
xfer, cnt, seg->status);
WARN_ON(1);
break;
case WA_SEG_DELAYED:
seg->status = WA_SEG_ABORTED;
seg->result = -ENOENT;
list_del(&seg->list_node);
xfer->segs_done++;
break;
case WA_SEG_DONE:
case WA_SEG_ERROR:
case WA_SEG_ABORTED:
break;
case WA_SEG_DTI_PENDING:
break;
case WA_SEG_SUBMITTED:
case WA_SEG_PENDING:
if (!xfer_abort_pending) {
seg->status = WA_SEG_ABORTED;
rpipe_ready = rpipe_avail_inc(rpipe);
xfer->segs_done++;
}
break;
}
}
spin_unlock(&rpipe->seg_lock);
xfer->result = urb->status;
done = __wa_xfer_is_done(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
wa_xfer_put(xfer);
return result;
out_unlock:
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_put(xfer);
return result;
dequeue_delayed:
list_del_init(&xfer->list_node);
spin_unlock_irqrestore(&wa->xfer_list_lock, flags2);
xfer->result = urb->status;
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_giveback(xfer);
wa_xfer_put(xfer);
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
[WA_XFER_STATUS_ABORTED] = -ENOENT,
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
static void wa_complete_remaining_xfer_segs(struct wa_xfer *xfer,
int starting_index, enum wa_seg_status status)
{
int index;
struct wa_rpipe *rpipe = xfer->ep->hcpriv;
for (index = starting_index; index < xfer->segs_submitted; index++) {
struct wa_seg *current_seg = xfer->seg[index];
BUG_ON(current_seg == NULL);
switch (current_seg->status) {
case WA_SEG_SUBMITTED:
case WA_SEG_PENDING:
case WA_SEG_DTI_PENDING:
rpipe_avail_inc(rpipe);
case WA_SEG_DELAYED:
xfer->segs_done++;
current_seg->status = status;
break;
case WA_SEG_ABORTED:
break;
default:
WARN(1, "%s: xfer 0x%08X#%d. bad seg status = %d\n",
__func__, wa_xfer_id(xfer), index,
current_seg->status);
break;
}
}
}
static int __wa_populate_buf_in_urb_isoc(struct wahc *wa,
struct urb *buf_in_urb, struct wa_xfer *xfer, struct wa_seg *seg)
{
int urb_start_frame = seg->isoc_frame_index + seg->isoc_frame_offset;
int seg_index, total_len = 0, urb_frame_index = urb_start_frame;
struct usb_iso_packet_descriptor *iso_frame_desc =
xfer->urb->iso_frame_desc;
const int dti_packet_size = usb_endpoint_maxp(wa->dti_epd);
int next_frame_contiguous;
struct usb_iso_packet_descriptor *iso_frame;
BUG_ON(buf_in_urb->status == -EINPROGRESS);
seg_index = seg->isoc_frame_index;
do {
next_frame_contiguous = 0;
iso_frame = &iso_frame_desc[urb_frame_index];
total_len += iso_frame->actual_length;
++urb_frame_index;
++seg_index;
if (seg_index < seg->isoc_frame_count) {
struct usb_iso_packet_descriptor *next_iso_frame;
next_iso_frame = &iso_frame_desc[urb_frame_index];
if ((iso_frame->offset + iso_frame->actual_length) ==
next_iso_frame->offset)
next_frame_contiguous = 1;
}
} while (next_frame_contiguous
&& ((iso_frame->actual_length % dti_packet_size) == 0));
buf_in_urb->num_mapped_sgs = 0;
buf_in_urb->transfer_dma = xfer->urb->transfer_dma +
iso_frame_desc[urb_start_frame].offset;
buf_in_urb->transfer_buffer_length = total_len;
buf_in_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
buf_in_urb->transfer_buffer = NULL;
buf_in_urb->sg = NULL;
buf_in_urb->num_sgs = 0;
buf_in_urb->context = seg;
return seg_index - seg->isoc_frame_index;
}
static int wa_populate_buf_in_urb(struct urb *buf_in_urb, struct wa_xfer *xfer,
unsigned int seg_idx, unsigned int bytes_transferred)
{
int result = 0;
struct wa_seg *seg = xfer->seg[seg_idx];
BUG_ON(buf_in_urb->status == -EINPROGRESS);
buf_in_urb->num_mapped_sgs = 0;
if (xfer->is_dma) {
buf_in_urb->transfer_dma = xfer->urb->transfer_dma
+ (seg_idx * xfer->seg_size);
buf_in_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
buf_in_urb->transfer_buffer = NULL;
buf_in_urb->sg = NULL;
buf_in_urb->num_sgs = 0;
} else {
buf_in_urb->transfer_flags &= ~URB_NO_TRANSFER_DMA_MAP;
if (xfer->urb->transfer_buffer) {
buf_in_urb->transfer_buffer =
xfer->urb->transfer_buffer
+ (seg_idx * xfer->seg_size);
buf_in_urb->sg = NULL;
buf_in_urb->num_sgs = 0;
} else {
buf_in_urb->sg = wa_xfer_create_subset_sg(
xfer->urb->sg,
seg_idx * xfer->seg_size,
bytes_transferred,
&(buf_in_urb->num_sgs));
if (!(buf_in_urb->sg)) {
buf_in_urb->num_sgs = 0;
result = -ENOMEM;
}
buf_in_urb->transfer_buffer = NULL;
}
}
buf_in_urb->transfer_buffer_length = bytes_transferred;
buf_in_urb->context = seg;
return result;
}
static void wa_xfer_result_chew(struct wahc *wa, struct wa_xfer *xfer,
struct wa_xfer_result *xfer_result)
{
int result;
struct device *dev = &wa->usb_iface->dev;
unsigned long flags;
unsigned int seg_idx;
struct wa_seg *seg;
struct wa_rpipe *rpipe;
unsigned done = 0;
u8 usb_status;
unsigned rpipe_ready = 0;
unsigned bytes_transferred = le32_to_cpu(xfer_result->dwTransferLength);
struct urb *buf_in_urb = &(wa->buf_in_urbs[0]);
spin_lock_irqsave(&xfer->lock, flags);
seg_idx = xfer_result->bTransferSegment & 0x7f;
if (unlikely(seg_idx >= xfer->segs))
goto error_bad_seg;
seg = xfer->seg[seg_idx];
rpipe = xfer->ep->hcpriv;
usb_status = xfer_result->bTransferStatus;
dev_dbg(dev, "xfer %p ID 0x%08X#%u: bTransferStatus 0x%02x (seg status %u)\n",
xfer, wa_xfer_id(xfer), seg_idx, usb_status, seg->status);
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
dev_err(dev, "DTI: xfer %p 0x%08X:#%u failed (0x%02x)\n",
xfer, xfer->id, seg->index, usb_status);
seg->status = ((usb_status & 0x7F) == WA_XFER_STATUS_ABORTED) ?
WA_SEG_ABORTED : WA_SEG_ERROR;
goto error_complete;
}
if (usb_status & 0x40)
usb_status = 0;
if (xfer_result->bTransferSegment & 0x80)
wa_complete_remaining_xfer_segs(xfer, seg->index + 1,
WA_SEG_DONE);
if (usb_pipeisoc(xfer->urb->pipe)
&& (le32_to_cpu(xfer_result->dwNumOfPackets) > 0)) {
wa->dti_isoc_xfer_in_progress = wa_xfer_id(xfer);
wa->dti_isoc_xfer_seg = seg_idx;
wa->dti_state = WA_DTI_ISOC_PACKET_STATUS_PENDING;
} else if (xfer->is_inbound && !usb_pipeisoc(xfer->urb->pipe)
&& (bytes_transferred > 0)) {
seg->status = WA_SEG_DTI_PENDING;
result = wa_populate_buf_in_urb(buf_in_urb, xfer, seg_idx,
bytes_transferred);
if (result < 0)
goto error_buf_in_populate;
++(wa->active_buf_in_urbs);
result = usb_submit_urb(buf_in_urb, GFP_ATOMIC);
if (result < 0) {
--(wa->active_buf_in_urbs);
goto error_submit_buf_in;
}
} else {
seg->result = bytes_transferred;
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg, WA_SEG_DONE);
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
kfree(buf_in_urb->sg);
buf_in_urb->sg = NULL;
error_buf_in_populate:
__wa_xfer_abort(xfer);
seg->status = WA_SEG_ERROR;
error_complete:
xfer->segs_done++;
rpipe_ready = rpipe_avail_inc(rpipe);
wa_complete_remaining_xfer_segs(xfer, seg->index + 1, seg->status);
done = __wa_xfer_is_done(xfer);
if (((usb_status & 0x3f) == WA_XFER_STATUS_HALTED) &&
usb_endpoint_xfer_control(&xfer->ep->desc) &&
done) {
dev_info(dev, "Control EP stall. Queue delayed work.\n");
spin_lock(&wa->xfer_list_lock);
list_move_tail(&xfer->list_node, &wa->xfer_errored_list);
spin_unlock(&wa->xfer_list_lock);
spin_unlock_irqrestore(&xfer->lock, flags);
queue_work(wusbd, &wa->xfer_error_work);
} else {
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
return;
error_bad_seg:
spin_unlock_irqrestore(&xfer->lock, flags);
wa_urb_dequeue(wa, xfer->urb, -ENOENT);
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
static int wa_process_iso_packet_status(struct wahc *wa, struct urb *urb)
{
struct device *dev = &wa->usb_iface->dev;
struct wa_xfer_packet_status_hwaiso *packet_status;
struct wa_xfer_packet_status_len_hwaiso *status_array;
struct wa_xfer *xfer;
unsigned long flags;
struct wa_seg *seg;
struct wa_rpipe *rpipe;
unsigned done = 0, dti_busy = 0, data_frame_count = 0, seg_index;
unsigned first_frame_index = 0, rpipe_ready = 0;
int expected_size;
dev_dbg(dev, "DTI: isoc packet status %d bytes at %p\n",
urb->actual_length, urb->transfer_buffer);
packet_status = (struct wa_xfer_packet_status_hwaiso *)(wa->dti_buf);
if (packet_status->bPacketType != WA_XFER_ISO_PACKET_STATUS) {
dev_err(dev, "DTI Error: isoc packet status--bad type 0x%02x\n",
packet_status->bPacketType);
goto error_parse_buffer;
}
xfer = wa_xfer_get_by_id(wa, wa->dti_isoc_xfer_in_progress);
if (xfer == NULL) {
dev_err(dev, "DTI Error: isoc packet status--unknown xfer 0x%08x\n",
wa->dti_isoc_xfer_in_progress);
goto error_parse_buffer;
}
spin_lock_irqsave(&xfer->lock, flags);
if (unlikely(wa->dti_isoc_xfer_seg >= xfer->segs))
goto error_bad_seg;
seg = xfer->seg[wa->dti_isoc_xfer_seg];
rpipe = xfer->ep->hcpriv;
expected_size = sizeof(*packet_status) +
(sizeof(packet_status->PacketStatus[0]) *
seg->isoc_frame_count);
if (urb->actual_length != expected_size) {
dev_err(dev, "DTI Error: isoc packet status--bad urb length (%d bytes vs %d needed)\n",
urb->actual_length, expected_size);
goto error_bad_seg;
}
if (le16_to_cpu(packet_status->wLength) != expected_size) {
dev_err(dev, "DTI Error: isoc packet status--bad length %u\n",
le16_to_cpu(packet_status->wLength));
goto error_bad_seg;
}
status_array = packet_status->PacketStatus;
xfer->urb->start_frame =
wa->wusb->usb_hcd.driver->get_frame_number(&wa->wusb->usb_hcd);
for (seg_index = 0; seg_index < seg->isoc_frame_count; ++seg_index) {
struct usb_iso_packet_descriptor *iso_frame_desc =
xfer->urb->iso_frame_desc;
const int xfer_frame_index =
seg->isoc_frame_offset + seg_index;
iso_frame_desc[xfer_frame_index].status =
wa_xfer_status_to_errno(
le16_to_cpu(status_array[seg_index].PacketStatus));
iso_frame_desc[xfer_frame_index].actual_length =
le16_to_cpu(status_array[seg_index].PacketLength);
if (iso_frame_desc[xfer_frame_index].actual_length > 0) {
if (!data_frame_count)
first_frame_index = seg_index;
++data_frame_count;
}
}
if (xfer->is_inbound && data_frame_count) {
int result, total_frames_read = 0, urb_index = 0;
struct urb *buf_in_urb;
seg->status = WA_SEG_DTI_PENDING;
seg->isoc_frame_index = first_frame_index;
do {
int urb_frame_index, urb_frame_count;
struct usb_iso_packet_descriptor *iso_frame_desc;
buf_in_urb = &(wa->buf_in_urbs[urb_index]);
urb_frame_count = __wa_populate_buf_in_urb_isoc(wa,
buf_in_urb, xfer, seg);
seg->isoc_frame_index += urb_frame_count;
total_frames_read += urb_frame_count;
++(wa->active_buf_in_urbs);
result = usb_submit_urb(buf_in_urb, GFP_ATOMIC);
urb_frame_index =
seg->isoc_frame_offset + seg->isoc_frame_index;
iso_frame_desc =
&(xfer->urb->iso_frame_desc[urb_frame_index]);
while ((seg->isoc_frame_index <
seg->isoc_frame_count) &&
(iso_frame_desc->actual_length == 0)) {
++(seg->isoc_frame_index);
++iso_frame_desc;
}
++urb_index;
} while ((result == 0) && (urb_index < WA_MAX_BUF_IN_URBS)
&& (seg->isoc_frame_index <
seg->isoc_frame_count));
if (result < 0) {
--(wa->active_buf_in_urbs);
dev_err(dev, "DTI Error: Could not submit buf in URB (%d)",
result);
wa_reset_all(wa);
} else if (data_frame_count > total_frames_read)
dti_busy = 1;
} else {
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg, WA_SEG_DONE);
}
spin_unlock_irqrestore(&xfer->lock, flags);
if (dti_busy)
wa->dti_state = WA_DTI_BUF_IN_DATA_PENDING;
else
wa->dti_state = WA_DTI_TRANSFER_RESULT_PENDING;
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
wa_xfer_put(xfer);
return dti_busy;
error_bad_seg:
spin_unlock_irqrestore(&xfer->lock, flags);
wa_xfer_put(xfer);
error_parse_buffer:
return dti_busy;
}
static void wa_buf_in_cb(struct urb *urb)
{
struct wa_seg *seg = urb->context;
struct wa_xfer *xfer = seg->xfer;
struct wahc *wa;
struct device *dev;
struct wa_rpipe *rpipe;
unsigned rpipe_ready = 0, isoc_data_frame_count = 0;
unsigned long flags;
int resubmit_dti = 0, active_buf_in_urbs;
u8 done = 0;
kfree(urb->sg);
urb->sg = NULL;
spin_lock_irqsave(&xfer->lock, flags);
wa = xfer->wa;
dev = &wa->usb_iface->dev;
--(wa->active_buf_in_urbs);
active_buf_in_urbs = wa->active_buf_in_urbs;
if (usb_pipeisoc(xfer->urb->pipe)) {
struct usb_iso_packet_descriptor *iso_frame_desc =
xfer->urb->iso_frame_desc;
int seg_index;
seg_index = seg->isoc_frame_index;
while (seg_index < seg->isoc_frame_count) {
const int urb_frame_index =
seg->isoc_frame_offset + seg_index;
if (iso_frame_desc[urb_frame_index].actual_length > 0) {
if (!isoc_data_frame_count)
seg->isoc_frame_index = seg_index;
++isoc_data_frame_count;
}
++seg_index;
}
}
spin_unlock_irqrestore(&xfer->lock, flags);
switch (urb->status) {
case 0:
spin_lock_irqsave(&xfer->lock, flags);
seg->result += urb->actual_length;
if (isoc_data_frame_count > 0) {
int result, urb_frame_count;
urb_frame_count = __wa_populate_buf_in_urb_isoc(wa, urb,
xfer, seg);
seg->isoc_frame_index += urb_frame_count;
++(wa->active_buf_in_urbs);
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result < 0) {
--(wa->active_buf_in_urbs);
dev_err(dev, "DTI Error: Could not submit buf in URB (%d)",
result);
wa_reset_all(wa);
}
resubmit_dti = (isoc_data_frame_count ==
urb_frame_count);
} else if (active_buf_in_urbs == 0) {
rpipe = xfer->ep->hcpriv;
dev_dbg(dev,
"xfer %p 0x%08X#%u: data in done (%zu bytes)\n",
xfer, wa_xfer_id(xfer), seg->index,
seg->result);
rpipe_ready = rpipe_avail_inc(rpipe);
done = __wa_xfer_mark_seg_as_done(xfer, seg,
WA_SEG_DONE);
}
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
resubmit_dti = wa->dti_state != WA_DTI_TRANSFER_RESULT_PENDING;
spin_lock_irqsave(&xfer->lock, flags);
rpipe = xfer->ep->hcpriv;
if (printk_ratelimit())
dev_err(dev, "xfer %p 0x%08X#%u: data in error %d\n",
xfer, wa_xfer_id(xfer), seg->index,
urb->status);
if (edc_inc(&wa->nep_edc, EDC_MAX_ERRORS,
EDC_ERROR_TIMEFRAME)){
dev_err(dev, "DTO: URB max acceptable errors "
"exceeded, resetting device\n");
wa_reset_all(wa);
}
seg->result = urb->status;
rpipe_ready = rpipe_avail_inc(rpipe);
if (active_buf_in_urbs == 0)
done = __wa_xfer_mark_seg_as_done(xfer, seg,
WA_SEG_ERROR);
else
__wa_xfer_abort(xfer);
spin_unlock_irqrestore(&xfer->lock, flags);
if (done)
wa_xfer_completion(xfer);
if (rpipe_ready)
wa_xfer_delayed_run(rpipe);
}
if (resubmit_dti) {
int result;
wa->dti_state = WA_DTI_TRANSFER_RESULT_PENDING;
result = usb_submit_urb(wa->dti_urb, GFP_ATOMIC);
if (result < 0) {
dev_err(dev, "DTI Error: Could not submit DTI URB (%d)\n",
result);
wa_reset_all(wa);
}
}
}
static void wa_dti_cb(struct urb *urb)
{
int result, dti_busy = 0;
struct wahc *wa = urb->context;
struct device *dev = &wa->usb_iface->dev;
u32 xfer_id;
u8 usb_status;
BUG_ON(wa->dti_urb != urb);
switch (wa->dti_urb->status) {
case 0:
if (wa->dti_state == WA_DTI_TRANSFER_RESULT_PENDING) {
struct wa_xfer_result *xfer_result;
struct wa_xfer *xfer;
dev_dbg(dev, "DTI: xfer result %d bytes at %p\n",
urb->actual_length, urb->transfer_buffer);
if (urb->actual_length != sizeof(*xfer_result)) {
dev_err(dev, "DTI Error: xfer result--bad size xfer result (%d bytes vs %zu needed)\n",
urb->actual_length,
sizeof(*xfer_result));
break;
}
xfer_result = (struct wa_xfer_result *)(wa->dti_buf);
if (xfer_result->hdr.bLength != sizeof(*xfer_result)) {
dev_err(dev, "DTI Error: xfer result--bad header length %u\n",
xfer_result->hdr.bLength);
break;
}
if (xfer_result->hdr.bNotifyType != WA_XFER_RESULT) {
dev_err(dev, "DTI Error: xfer result--bad header type 0x%02x\n",
xfer_result->hdr.bNotifyType);
break;
}
xfer_id = le32_to_cpu(xfer_result->dwTransferID);
usb_status = xfer_result->bTransferStatus & 0x3f;
if (usb_status == WA_XFER_STATUS_NOT_FOUND) {
dev_dbg(dev, "%s: xfer 0x%08X#%u not found.\n",
__func__, xfer_id,
xfer_result->bTransferSegment & 0x7f);
break;
}
xfer = wa_xfer_get_by_id(wa, xfer_id);
if (xfer == NULL) {
dev_err(dev, "DTI Error: xfer result--unknown xfer 0x%08x (status 0x%02x)\n",
xfer_id, usb_status);
break;
}
wa_xfer_result_chew(wa, xfer, xfer_result);
wa_xfer_put(xfer);
} else if (wa->dti_state == WA_DTI_ISOC_PACKET_STATUS_PENDING) {
dti_busy = wa_process_iso_packet_status(wa, urb);
} else {
dev_err(dev, "DTI Error: unexpected EP state = %d\n",
wa->dti_state);
}
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
if (!dti_busy) {
result = usb_submit_urb(wa->dti_urb, GFP_ATOMIC);
if (result < 0) {
dev_err(dev, "DTI Error: Could not submit DTI URB (%d)\n",
result);
wa_reset_all(wa);
}
}
out:
return;
}
int wa_dti_start(struct wahc *wa)
{
const struct usb_endpoint_descriptor *dti_epd = wa->dti_epd;
struct device *dev = &wa->usb_iface->dev;
int result = -ENOMEM, index;
if (wa->dti_urb != NULL)
goto out;
wa->dti_urb = usb_alloc_urb(0, GFP_KERNEL);
if (wa->dti_urb == NULL) {
dev_err(dev, "Can't allocate DTI URB\n");
goto error_dti_urb_alloc;
}
usb_fill_bulk_urb(
wa->dti_urb, wa->usb_dev,
usb_rcvbulkpipe(wa->usb_dev, 0x80 | dti_epd->bEndpointAddress),
wa->dti_buf, wa->dti_buf_size,
wa_dti_cb, wa);
for (index = 0; index < WA_MAX_BUF_IN_URBS; ++index) {
usb_fill_bulk_urb(
&(wa->buf_in_urbs[index]), wa->usb_dev,
usb_rcvbulkpipe(wa->usb_dev,
0x80 | dti_epd->bEndpointAddress),
NULL, 0, wa_buf_in_cb, wa);
}
result = usb_submit_urb(wa->dti_urb, GFP_KERNEL);
if (result < 0) {
dev_err(dev, "DTI Error: Could not submit DTI URB (%d) resetting\n",
result);
goto error_dti_urb_submit;
}
out:
return 0;
error_dti_urb_submit:
usb_put_urb(wa->dti_urb);
wa->dti_urb = NULL;
error_dti_urb_alloc:
return result;
}
void wa_handle_notif_xfer(struct wahc *wa, struct wa_notif_hdr *notif_hdr)
{
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
if (wa_dti_start(wa) < 0)
goto error;
return;
error:
wa_reset_all(wa);
}
