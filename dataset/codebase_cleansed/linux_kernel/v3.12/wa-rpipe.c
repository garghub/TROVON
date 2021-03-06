static int __rpipe_get_descr(struct wahc *wa,
struct usb_rpipe_descriptor *descr, u16 index)
{
ssize_t result;
struct device *dev = &wa->usb_iface->dev;
result = usb_control_msg(
wa->usb_dev, usb_rcvctrlpipe(wa->usb_dev, 0),
USB_REQ_GET_DESCRIPTOR,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_RPIPE,
USB_DT_RPIPE<<8, index, descr, sizeof(*descr),
1000 );
if (result < 0) {
dev_err(dev, "rpipe %u: get descriptor failed: %d\n",
index, (int)result);
goto error;
}
if (result < sizeof(*descr)) {
dev_err(dev, "rpipe %u: got short descriptor "
"(%zd vs %zd bytes needed)\n",
index, result, sizeof(*descr));
result = -EINVAL;
goto error;
}
result = 0;
error:
return result;
}
static int __rpipe_set_descr(struct wahc *wa,
struct usb_rpipe_descriptor *descr, u16 index)
{
ssize_t result;
struct device *dev = &wa->usb_iface->dev;
result = usb_control_msg(
wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
USB_REQ_SET_DESCRIPTOR,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_RPIPE,
USB_DT_RPIPE<<8, index, descr, sizeof(*descr),
HZ / 10);
if (result < 0) {
dev_err(dev, "rpipe %u: set descriptor failed: %d\n",
index, (int)result);
goto error;
}
if (result < sizeof(*descr)) {
dev_err(dev, "rpipe %u: sent short descriptor "
"(%zd vs %zd bytes required)\n",
index, result, sizeof(*descr));
result = -EINVAL;
goto error;
}
result = 0;
error:
return result;
}
static void rpipe_init(struct wa_rpipe *rpipe)
{
kref_init(&rpipe->refcnt);
spin_lock_init(&rpipe->seg_lock);
INIT_LIST_HEAD(&rpipe->seg_list);
}
static unsigned rpipe_get_idx(struct wahc *wa, unsigned rpipe_idx)
{
unsigned long flags;
spin_lock_irqsave(&wa->rpipe_bm_lock, flags);
rpipe_idx = find_next_zero_bit(wa->rpipe_bm, wa->rpipes, rpipe_idx);
if (rpipe_idx < wa->rpipes)
set_bit(rpipe_idx, wa->rpipe_bm);
spin_unlock_irqrestore(&wa->rpipe_bm_lock, flags);
return rpipe_idx;
}
static void rpipe_put_idx(struct wahc *wa, unsigned rpipe_idx)
{
unsigned long flags;
spin_lock_irqsave(&wa->rpipe_bm_lock, flags);
clear_bit(rpipe_idx, wa->rpipe_bm);
spin_unlock_irqrestore(&wa->rpipe_bm_lock, flags);
}
void rpipe_destroy(struct kref *_rpipe)
{
struct wa_rpipe *rpipe = container_of(_rpipe, struct wa_rpipe, refcnt);
u8 index = le16_to_cpu(rpipe->descr.wRPipeIndex);
if (rpipe->ep)
rpipe->ep->hcpriv = NULL;
rpipe_put_idx(rpipe->wa, index);
wa_put(rpipe->wa);
kfree(rpipe);
}
static int rpipe_get_idle(struct wa_rpipe **prpipe, struct wahc *wa, u8 crs,
gfp_t gfp)
{
int result;
unsigned rpipe_idx;
struct wa_rpipe *rpipe;
struct device *dev = &wa->usb_iface->dev;
rpipe = kzalloc(sizeof(*rpipe), gfp);
if (rpipe == NULL)
return -ENOMEM;
rpipe_init(rpipe);
for (rpipe_idx = 0; rpipe_idx < wa->rpipes; rpipe_idx++) {
rpipe_idx = rpipe_get_idx(wa, rpipe_idx);
if (rpipe_idx >= wa->rpipes)
break;
result = __rpipe_get_descr(wa, &rpipe->descr, rpipe_idx);
if (result < 0)
dev_err(dev, "Can't get descriptor for rpipe %u: %d\n",
rpipe_idx, result);
else if ((rpipe->descr.bmCharacteristics & crs) != 0)
goto found;
rpipe_put_idx(wa, rpipe_idx);
}
*prpipe = NULL;
kfree(rpipe);
return -ENXIO;
found:
set_bit(rpipe_idx, wa->rpipe_bm);
rpipe->wa = wa_get(wa);
*prpipe = rpipe;
return 0;
}
static int __rpipe_reset(struct wahc *wa, unsigned index)
{
int result;
struct device *dev = &wa->usb_iface->dev;
result = usb_control_msg(
wa->usb_dev, usb_sndctrlpipe(wa->usb_dev, 0),
USB_REQ_RPIPE_RESET,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_RPIPE,
0, index, NULL, 0, 1000 );
if (result < 0)
dev_err(dev, "rpipe %u: reset failed: %d\n",
index, result);
return result;
}
static struct usb_wireless_ep_comp_descriptor *rpipe_epc_find(
struct device *dev, struct usb_host_endpoint *ep)
{
void *itr;
size_t itr_size;
struct usb_descriptor_header *hdr;
struct usb_wireless_ep_comp_descriptor *epcd;
if (ep->desc.bEndpointAddress == 0) {
epcd = &epc0;
goto out;
}
itr = ep->extra;
itr_size = ep->extralen;
epcd = NULL;
while (itr_size > 0) {
if (itr_size < sizeof(*hdr)) {
dev_err(dev, "HW Bug? ep 0x%02x: extra descriptors "
"at offset %zu: only %zu bytes left\n",
ep->desc.bEndpointAddress,
itr - (void *) ep->extra, itr_size);
break;
}
hdr = itr;
if (hdr->bDescriptorType == USB_DT_WIRELESS_ENDPOINT_COMP) {
epcd = itr;
break;
}
if (hdr->bLength > itr_size) {
dev_err(dev, "HW Bug? ep 0x%02x: extra descriptor "
"at offset %zu (type 0x%02x) "
"length %d but only %zu bytes left\n",
ep->desc.bEndpointAddress,
itr - (void *) ep->extra, hdr->bDescriptorType,
hdr->bLength, itr_size);
break;
}
itr += hdr->bLength;
itr_size -= hdr->bDescriptorType;
}
out:
return epcd;
}
static int rpipe_aim(struct wa_rpipe *rpipe, struct wahc *wa,
struct usb_host_endpoint *ep, struct urb *urb, gfp_t gfp)
{
int result = -ENOMSG;
struct device *dev = &wa->usb_iface->dev;
struct usb_device *usb_dev = urb->dev;
struct usb_wireless_ep_comp_descriptor *epcd;
u32 ack_window, epcd_max_sequence;
u8 unauth;
epcd = rpipe_epc_find(dev, ep);
if (epcd == NULL) {
dev_err(dev, "ep 0x%02x: can't find companion descriptor\n",
ep->desc.bEndpointAddress);
goto error;
}
unauth = usb_dev->wusb && !usb_dev->authenticated ? 0x80 : 0;
__rpipe_reset(wa, le16_to_cpu(rpipe->descr.wRPipeIndex));
atomic_set(&rpipe->segs_available, le16_to_cpu(rpipe->descr.wRequests));
rpipe->descr.wBlocks = cpu_to_le16(16);
rpipe->descr.wMaxPacketSize = cpu_to_le16(ep->desc.wMaxPacketSize);
rpipe->descr.hwa_bMaxBurst = max(min_t(unsigned int,
epcd->bMaxBurst, 16U), 1U);
rpipe->descr.hwa_bDeviceInfoIndex =
wusb_port_no_to_idx(urb->dev->portnum);
rpipe->descr.bSpeed = usb_pipeendpoint(urb->pipe) == 0 ?
UWB_PHY_RATE_53 : UWB_PHY_RATE_200;
dev_dbg(dev, "addr %u (0x%02x) rpipe #%u ep# %u speed %d\n",
urb->dev->devnum, urb->dev->devnum | unauth,
le16_to_cpu(rpipe->descr.wRPipeIndex),
usb_pipeendpoint(urb->pipe), rpipe->descr.bSpeed);
rpipe->descr.hwa_reserved = 0;
rpipe->descr.bEndpointAddress = ep->desc.bEndpointAddress;
rpipe->descr.bDataSequence = 0;
ack_window = 0xFFFFFFFF >> (32 - rpipe->descr.hwa_bMaxBurst);
rpipe->descr.dwCurrentWindow = cpu_to_le32(ack_window);
epcd_max_sequence = max(min_t(unsigned int,
epcd->bMaxSequence, 32U), 2U);
rpipe->descr.bMaxDataSequence = epcd_max_sequence - 1;
rpipe->descr.bInterval = ep->desc.bInterval;
rpipe->descr.bOverTheAirInterval = 0;
rpipe->descr.bmAttribute = (ep->desc.bmAttributes &
USB_ENDPOINT_XFERTYPE_MASK);
rpipe->descr.bmRetryOptions = (wa->wusb->retry_count & 0xF);
rpipe->descr.wNumTransactionErrors = 0;
result = __rpipe_set_descr(wa, &rpipe->descr,
le16_to_cpu(rpipe->descr.wRPipeIndex));
if (result < 0) {
dev_err(dev, "Cannot aim rpipe: %d\n", result);
goto error;
}
result = 0;
error:
return result;
}
static int rpipe_check_aim(const struct wa_rpipe *rpipe, const struct wahc *wa,
const struct usb_host_endpoint *ep,
const struct urb *urb, gfp_t gfp)
{
int result = 0;
struct device *dev = &wa->usb_iface->dev;
u8 portnum = wusb_port_no_to_idx(urb->dev->portnum);
#define AIM_CHECK(rdf, val, text) \
do { \
if (rpipe->descr.rdf != (val)) { \
dev_err(dev, \
"rpipe aim discrepancy: " #rdf " " text "\n", \
rpipe->descr.rdf, (val)); \
result = -EINVAL; \
WARN_ON(1); \
} \
} while (0)
AIM_CHECK(hwa_bDeviceInfoIndex, portnum, "(%u vs %u)");
AIM_CHECK(bSpeed, usb_pipeendpoint(urb->pipe) == 0 ?
UWB_PHY_RATE_53 : UWB_PHY_RATE_200,
"(%u vs %u)");
AIM_CHECK(bEndpointAddress, ep->desc.bEndpointAddress, "(%u vs %u)");
AIM_CHECK(bInterval, ep->desc.bInterval, "(%u vs %u)");
AIM_CHECK(bmAttribute, ep->desc.bmAttributes & 0x03, "(%u vs %u)");
#undef AIM_CHECK
return result;
}
int rpipe_get_by_ep(struct wahc *wa, struct usb_host_endpoint *ep,
struct urb *urb, gfp_t gfp)
{
int result = 0;
struct device *dev = &wa->usb_iface->dev;
struct wa_rpipe *rpipe;
u8 eptype;
mutex_lock(&wa->rpipe_mutex);
rpipe = ep->hcpriv;
if (rpipe != NULL) {
if (CONFIG_BUG == 1) {
result = rpipe_check_aim(rpipe, wa, ep, urb, gfp);
if (result < 0)
goto error;
}
__rpipe_get(rpipe);
dev_dbg(dev, "ep 0x%02x: reusing rpipe %u\n",
ep->desc.bEndpointAddress,
le16_to_cpu(rpipe->descr.wRPipeIndex));
} else {
result = -ENOBUFS;
eptype = ep->desc.bmAttributes & 0x03;
result = rpipe_get_idle(&rpipe, wa, 1 << eptype, gfp);
if (result < 0)
goto error;
result = rpipe_aim(rpipe, wa, ep, urb, gfp);
if (result < 0) {
rpipe_put(rpipe);
goto error;
}
ep->hcpriv = rpipe;
rpipe->ep = ep;
__rpipe_get(rpipe);
dev_dbg(dev, "ep 0x%02x: using rpipe %u\n",
ep->desc.bEndpointAddress,
le16_to_cpu(rpipe->descr.wRPipeIndex));
}
error:
mutex_unlock(&wa->rpipe_mutex);
return result;
}
int wa_rpipes_create(struct wahc *wa)
{
wa->rpipes = wa->wa_descr->wNumRPipes;
wa->rpipe_bm = kzalloc(BITS_TO_LONGS(wa->rpipes)*sizeof(unsigned long),
GFP_KERNEL);
if (wa->rpipe_bm == NULL)
return -ENOMEM;
return 0;
}
void wa_rpipes_destroy(struct wahc *wa)
{
struct device *dev = &wa->usb_iface->dev;
if (!bitmap_empty(wa->rpipe_bm, wa->rpipes)) {
char buf[256];
WARN_ON(1);
bitmap_scnprintf(buf, sizeof(buf), wa->rpipe_bm, wa->rpipes);
dev_err(dev, "BUG: pipes not released on exit: %s\n", buf);
}
kfree(wa->rpipe_bm);
}
void rpipe_ep_disable(struct wahc *wa, struct usb_host_endpoint *ep)
{
struct wa_rpipe *rpipe;
mutex_lock(&wa->rpipe_mutex);
rpipe = ep->hcpriv;
if (rpipe != NULL) {
u16 index = le16_to_cpu(rpipe->descr.wRPipeIndex);
usb_control_msg(
wa->usb_dev, usb_rcvctrlpipe(wa->usb_dev, 0),
USB_REQ_RPIPE_ABORT,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_RPIPE,
0, index, NULL, 0, 1000 );
rpipe_put(rpipe);
}
mutex_unlock(&wa->rpipe_mutex);
}
void rpipe_clear_feature_stalled(struct wahc *wa, struct usb_host_endpoint *ep)
{
struct wa_rpipe *rpipe;
mutex_lock(&wa->rpipe_mutex);
rpipe = ep->hcpriv;
if (rpipe != NULL) {
u16 index = le16_to_cpu(rpipe->descr.wRPipeIndex);
usb_control_msg(
wa->usb_dev, usb_rcvctrlpipe(wa->usb_dev, 0),
USB_REQ_CLEAR_FEATURE,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_RPIPE,
RPIPE_STALL, index, NULL, 0, 1000);
}
mutex_unlock(&wa->rpipe_mutex);
}
