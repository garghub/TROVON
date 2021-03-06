void imx_udc_enable(struct imx_udc_struct *imx_usb)
{
int temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp | CTRL_FE_ENA | CTRL_AFE_ENA,
imx_usb->base + USB_CTRL);
imx_usb->gadget.speed = USB_SPEED_FULL;
}
void imx_udc_disable(struct imx_udc_struct *imx_usb)
{
int temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp & ~(CTRL_FE_ENA | CTRL_AFE_ENA),
imx_usb->base + USB_CTRL);
ep0_chg_stat(__func__, imx_usb, EP0_IDLE);
imx_usb->gadget.speed = USB_SPEED_UNKNOWN;
}
void imx_udc_reset(struct imx_udc_struct *imx_usb)
{
int temp = __raw_readl(imx_usb->base + USB_ENAB);
__raw_writel(temp | ENAB_RST, imx_usb->base + USB_ENAB);
do {} while (__raw_readl(imx_usb->base + USB_ENAB) & ENAB_RST);
do {} while (!(__raw_readl(imx_usb->base + USB_DADR) & DADR_CFG));
}
void imx_udc_config(struct imx_udc_struct *imx_usb)
{
u8 ep_conf[5];
u8 i, j, cfg;
struct imx_ep_struct *imx_ep;
do {} while (!(__raw_readl(imx_usb->base + USB_DADR) & DADR_CFG));
for (j = 0; j < 5; j++) {
i = (j == 2 ? imx_usb->imx_ep[0].fifosize : 0x00);
__raw_writeb(i, imx_usb->base + USB_DDAT);
do {} while (__raw_readl(imx_usb->base + USB_DADR) & DADR_BSY);
}
for (cfg = 1; cfg < 3; cfg++) {
for (i = 1; i < IMX_USB_NB_EP; i++) {
imx_ep = &imx_usb->imx_ep[i];
ep_conf[0] = (i << 4) | (cfg << 2);
ep_conf[1] = (imx_ep->bmAttributes << 3) |
(EP_DIR(imx_ep) << 2);
ep_conf[2] = imx_ep->fifosize;
ep_conf[3] = 0xC0;
ep_conf[4] = i;
D_INI(imx_usb->dev,
"<%s> ep%d_conf[%d]:"
"[%02x-%02x-%02x-%02x-%02x]\n",
__func__, i, cfg,
ep_conf[0], ep_conf[1], ep_conf[2],
ep_conf[3], ep_conf[4]);
for (j = 0; j < 5; j++) {
__raw_writeb(ep_conf[j],
imx_usb->base + USB_DDAT);
do {} while (__raw_readl(imx_usb->base
+ USB_DADR)
& DADR_BSY);
}
}
}
do {} while (__raw_readl(imx_usb->base + USB_DADR) & DADR_CFG);
}
void imx_udc_init_irq(struct imx_udc_struct *imx_usb)
{
int i;
__raw_writel(0xFFFFFFFF, imx_usb->base + USB_MASK);
__raw_writel(0xFFFFFFFF, imx_usb->base + USB_INTR);
for (i = 0; i < IMX_USB_NB_EP; i++) {
__raw_writel(0x1FF, imx_usb->base + USB_EP_MASK(i));
__raw_writel(0x1FF, imx_usb->base + USB_EP_INTR(i));
}
__raw_writel(INTR_MSOF | INTR_FRAME_MATCH, imx_usb->base + USB_MASK);
__raw_writel(0x1FF & ~(EPINTR_DEVREQ | EPINTR_MDEVREQ | EPINTR_EOT
| EPINTR_EOF | EPINTR_FIFO_EMPTY | EPINTR_FIFO_FULL),
imx_usb->base + USB_EP_MASK(0));
}
void imx_udc_init_ep(struct imx_udc_struct *imx_usb)
{
int i, max, temp;
struct imx_ep_struct *imx_ep;
for (i = 0; i < IMX_USB_NB_EP; i++) {
imx_ep = &imx_usb->imx_ep[i];
switch (imx_ep->fifosize) {
case 8:
max = 0;
break;
case 16:
max = 1;
break;
case 32:
max = 2;
break;
case 64:
max = 3;
break;
default:
max = 1;
break;
}
temp = (EP_DIR(imx_ep) << 7) | (max << 5)
| (imx_ep->bmAttributes << 3);
__raw_writel(temp, imx_usb->base + USB_EP_STAT(i));
__raw_writel(temp | EPSTAT_FLUSH,
imx_usb->base + USB_EP_STAT(i));
D_INI(imx_usb->dev, "<%s> ep%d_stat %08x\n", __func__, i,
__raw_readl(imx_usb->base + USB_EP_STAT(i)));
}
}
void imx_udc_init_fifo(struct imx_udc_struct *imx_usb)
{
int i, temp;
struct imx_ep_struct *imx_ep;
for (i = 0; i < IMX_USB_NB_EP; i++) {
imx_ep = &imx_usb->imx_ep[i];
temp = EP_DIR(imx_ep) ? 0x0B000000 : 0x0F000000;
__raw_writel(temp, imx_usb->base + USB_EP_FCTRL(i));
D_INI(imx_usb->dev, "<%s> ep%d_fctrl %08x\n", __func__, i,
__raw_readl(imx_usb->base + USB_EP_FCTRL(i)));
temp = (i ? imx_ep->fifosize / 2 : 0);
__raw_writel(temp, imx_usb->base + USB_EP_FALRM(i));
D_INI(imx_usb->dev, "<%s> ep%d_falrm %08x\n", __func__, i,
__raw_readl(imx_usb->base + USB_EP_FALRM(i)));
}
}
static void imx_udc_init(struct imx_udc_struct *imx_usb)
{
imx_udc_reset(imx_usb);
imx_udc_config(imx_usb);
imx_udc_init_irq(imx_usb);
imx_udc_init_ep(imx_usb);
imx_udc_init_fifo(imx_usb);
}
void imx_ep_irq_enable(struct imx_ep_struct *imx_ep)
{
int i = EP_NO(imx_ep);
__raw_writel(0x1FF, imx_ep->imx_usb->base + USB_EP_MASK(i));
__raw_writel(0x1FF, imx_ep->imx_usb->base + USB_EP_INTR(i));
__raw_writel(0x1FF & ~(EPINTR_EOT | EPINTR_EOF),
imx_ep->imx_usb->base + USB_EP_MASK(i));
}
void imx_ep_irq_disable(struct imx_ep_struct *imx_ep)
{
int i = EP_NO(imx_ep);
__raw_writel(0x1FF, imx_ep->imx_usb->base + USB_EP_MASK(i));
__raw_writel(0x1FF, imx_ep->imx_usb->base + USB_EP_INTR(i));
}
int imx_ep_empty(struct imx_ep_struct *imx_ep)
{
struct imx_udc_struct *imx_usb = imx_ep->imx_usb;
return __raw_readl(imx_usb->base + USB_EP_FSTAT(EP_NO(imx_ep)))
& FSTAT_EMPTY;
}
unsigned imx_fifo_bcount(struct imx_ep_struct *imx_ep)
{
struct imx_udc_struct *imx_usb = imx_ep->imx_usb;
return (__raw_readl(imx_usb->base + USB_EP_STAT(EP_NO(imx_ep)))
& EPSTAT_BCOUNT) >> 16;
}
void imx_flush(struct imx_ep_struct *imx_ep)
{
struct imx_udc_struct *imx_usb = imx_ep->imx_usb;
int temp = __raw_readl(imx_usb->base + USB_EP_STAT(EP_NO(imx_ep)));
__raw_writel(temp | EPSTAT_FLUSH,
imx_usb->base + USB_EP_STAT(EP_NO(imx_ep)));
}
void imx_ep_stall(struct imx_ep_struct *imx_ep)
{
struct imx_udc_struct *imx_usb = imx_ep->imx_usb;
int temp, i;
D_ERR(imx_usb->dev,
"<%s> Forced stall on %s\n", __func__, imx_ep->ep.name);
imx_flush(imx_ep);
if (!EP_NO(imx_ep)) {
temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp | CTRL_CMDOVER | CTRL_CMDERROR,
imx_usb->base + USB_CTRL);
do { } while (__raw_readl(imx_usb->base + USB_CTRL)
& CTRL_CMDOVER);
temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp & ~CTRL_CMDERROR, imx_usb->base + USB_CTRL);
}
else {
temp = __raw_readl(imx_usb->base + USB_EP_STAT(EP_NO(imx_ep)));
__raw_writel(temp | EPSTAT_STALL,
imx_usb->base + USB_EP_STAT(EP_NO(imx_ep)));
for (i = 0; i < 100; i ++) {
temp = __raw_readl(imx_usb->base
+ USB_EP_STAT(EP_NO(imx_ep)));
if (!(temp & EPSTAT_STALL))
break;
udelay(20);
}
if (i == 100)
D_ERR(imx_usb->dev, "<%s> Non finished stall on %s\n",
__func__, imx_ep->ep.name);
}
}
static int imx_udc_get_frame(struct usb_gadget *_gadget)
{
struct imx_udc_struct *imx_usb = container_of(_gadget,
struct imx_udc_struct, gadget);
return __raw_readl(imx_usb->base + USB_FRAME) & 0x7FF;
}
static int imx_udc_wakeup(struct usb_gadget *_gadget)
{
return 0;
}
static void ep_add_request(struct imx_ep_struct *imx_ep,
struct imx_request *req)
{
if (unlikely(!req))
return;
req->in_use = 1;
list_add_tail(&req->queue, &imx_ep->queue);
}
static void ep_del_request(struct imx_ep_struct *imx_ep,
struct imx_request *req)
{
if (unlikely(!req))
return;
list_del_init(&req->queue);
req->in_use = 0;
}
static void done(struct imx_ep_struct *imx_ep,
struct imx_request *req, int status)
{
ep_del_request(imx_ep, req);
if (likely(req->req.status == -EINPROGRESS))
req->req.status = status;
else
status = req->req.status;
if (status && status != -ESHUTDOWN)
D_ERR(imx_ep->imx_usb->dev,
"<%s> complete %s req %p stat %d len %u/%u\n", __func__,
imx_ep->ep.name, &req->req, status,
req->req.actual, req->req.length);
req->req.complete(&imx_ep->ep, &req->req);
}
static void nuke(struct imx_ep_struct *imx_ep, int status)
{
struct imx_request *req;
while (!list_empty(&imx_ep->queue)) {
req = list_entry(imx_ep->queue.next, struct imx_request, queue);
done(imx_ep, req, status);
}
}
static int read_packet(struct imx_ep_struct *imx_ep, struct imx_request *req)
{
u8 *buf;
int bytes_ep, bufferspace, count, i;
bytes_ep = imx_fifo_bcount(imx_ep);
bufferspace = req->req.length - req->req.actual;
buf = req->req.buf + req->req.actual;
prefetchw(buf);
if (unlikely(imx_ep_empty(imx_ep)))
count = 0;
else
count = min(bytes_ep, bufferspace);
for (i = count; i > 0; i--)
*buf++ = __raw_readb(imx_ep->imx_usb->base
+ USB_EP_FDAT0(EP_NO(imx_ep)));
req->req.actual += count;
return count;
}
static int write_packet(struct imx_ep_struct *imx_ep, struct imx_request *req)
{
u8 *buf;
int length, count, temp;
if (unlikely(__raw_readl(imx_ep->imx_usb->base +
USB_EP_STAT(EP_NO(imx_ep))) & EPSTAT_ZLPS)) {
D_TRX(imx_ep->imx_usb->dev, "<%s> zlp still queued in EP %s\n",
__func__, imx_ep->ep.name);
return -1;
}
buf = req->req.buf + req->req.actual;
prefetch(buf);
length = min(req->req.length - req->req.actual, (u32)imx_ep->fifosize);
if (imx_fifo_bcount(imx_ep) + length > imx_ep->fifosize) {
D_TRX(imx_ep->imx_usb->dev, "<%s> packet overfill %s fifo\n",
__func__, imx_ep->ep.name);
return -1;
}
req->req.actual += length;
count = length;
if (!count && req->req.zero) {
temp = __raw_readl(imx_ep->imx_usb->base
+ USB_EP_STAT(EP_NO(imx_ep)));
__raw_writel(temp | EPSTAT_ZLPS, imx_ep->imx_usb->base
+ USB_EP_STAT(EP_NO(imx_ep)));
D_TRX(imx_ep->imx_usb->dev, "<%s> zero packet\n", __func__);
return 0;
}
while (count--) {
if (count == 0) {
temp = __raw_readl(imx_ep->imx_usb->base
+ USB_EP_FCTRL(EP_NO(imx_ep)));
__raw_writel(temp | FCTRL_WFR, imx_ep->imx_usb->base
+ USB_EP_FCTRL(EP_NO(imx_ep)));
}
__raw_writeb(*buf++,
imx_ep->imx_usb->base + USB_EP_FDAT0(EP_NO(imx_ep)));
}
return length;
}
static int read_fifo(struct imx_ep_struct *imx_ep, struct imx_request *req)
{
int bytes = 0,
count,
completed = 0;
while (__raw_readl(imx_ep->imx_usb->base + USB_EP_FSTAT(EP_NO(imx_ep)))
& FSTAT_FR) {
count = read_packet(imx_ep, req);
bytes += count;
completed = (count != imx_ep->fifosize);
if (completed || req->req.actual == req->req.length) {
completed = 1;
break;
}
}
if (completed || !req->req.length) {
done(imx_ep, req, 0);
D_REQ(imx_ep->imx_usb->dev, "<%s> %s req<%p> %s\n",
__func__, imx_ep->ep.name, req,
completed ? "completed" : "not completed");
if (!EP_NO(imx_ep))
ep0_chg_stat(__func__, imx_ep->imx_usb, EP0_IDLE);
}
D_TRX(imx_ep->imx_usb->dev, "<%s> bytes read: %d\n", __func__, bytes);
return completed;
}
static int write_fifo(struct imx_ep_struct *imx_ep, struct imx_request *req)
{
int bytes = 0,
count,
completed = 0;
while (!completed) {
count = write_packet(imx_ep, req);
if (count < 0)
break;
bytes += count;
completed = (count != imx_ep->fifosize);
if (unlikely(completed)) {
done(imx_ep, req, 0);
D_REQ(imx_ep->imx_usb->dev, "<%s> %s req<%p> %s\n",
__func__, imx_ep->ep.name, req,
completed ? "completed" : "not completed");
if (!EP_NO(imx_ep))
ep0_chg_stat(__func__,
imx_ep->imx_usb, EP0_IDLE);
}
}
D_TRX(imx_ep->imx_usb->dev, "<%s> bytes sent: %d\n", __func__, bytes);
return completed;
}
static int handle_ep(struct imx_ep_struct *imx_ep)
{
struct imx_request *req;
int completed = 0;
do {
if (!list_empty(&imx_ep->queue))
req = list_entry(imx_ep->queue.next,
struct imx_request, queue);
else {
D_REQ(imx_ep->imx_usb->dev, "<%s> no request on %s\n",
__func__, imx_ep->ep.name);
return 0;
}
if (EP_DIR(imx_ep))
completed = write_fifo(imx_ep, req);
else
completed = read_fifo(imx_ep, req);
dump_ep_stat(__func__, imx_ep);
} while (completed);
return 0;
}
static int handle_ep0(struct imx_ep_struct *imx_ep)
{
struct imx_request *req = NULL;
int ret = 0;
if (!list_empty(&imx_ep->queue)) {
req = list_entry(imx_ep->queue.next, struct imx_request, queue);
switch (imx_ep->imx_usb->ep0state) {
case EP0_IN_DATA_PHASE:
write_fifo(imx_ep, req);
break;
case EP0_OUT_DATA_PHASE:
read_fifo(imx_ep, req);
break;
default:
D_EP0(imx_ep->imx_usb->dev,
"<%s> ep0 i/o, odd state %d\n",
__func__, imx_ep->imx_usb->ep0state);
ep_del_request(imx_ep, req);
ret = -EL2HLT;
break;
}
}
else
D_ERR(imx_ep->imx_usb->dev, "<%s> no request on %s\n",
__func__, imx_ep->ep.name);
return ret;
}
static void handle_ep0_devreq(struct imx_udc_struct *imx_usb)
{
struct imx_ep_struct *imx_ep = &imx_usb->imx_ep[0];
union {
struct usb_ctrlrequest r;
u8 raw[8];
u32 word[2];
} u;
int temp, i;
nuke(imx_ep, -EPROTO);
for (i = 0; i < 2; i++) {
if (imx_ep_empty(imx_ep)) {
D_ERR(imx_usb->dev,
"<%s> no setup packet received\n", __func__);
goto stall;
}
u.word[i] = __raw_readl(imx_usb->base
+ USB_EP_FDAT(EP_NO(imx_ep)));
}
temp = imx_ep_empty(imx_ep);
while (!imx_ep_empty(imx_ep)) {
i = __raw_readl(imx_usb->base + USB_EP_FDAT(EP_NO(imx_ep)));
D_ERR(imx_usb->dev,
"<%s> wrong to have extra bytes for setup : 0x%08x\n",
__func__, i);
}
if (!temp)
goto stall;
le16_to_cpus(&u.r.wValue);
le16_to_cpus(&u.r.wIndex);
le16_to_cpus(&u.r.wLength);
D_REQ(imx_usb->dev, "<%s> SETUP %02x.%02x v%04x i%04x l%04x\n",
__func__, u.r.bRequestType, u.r.bRequest,
u.r.wValue, u.r.wIndex, u.r.wLength);
if (imx_usb->set_config) {
temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp | CTRL_CMDOVER, imx_usb->base + USB_CTRL);
D_ERR(imx_usb->dev,
"<%s> set config req is pending, NACK the host\n",
__func__);
return;
}
if (u.r.bRequestType & USB_DIR_IN)
ep0_chg_stat(__func__, imx_usb, EP0_IN_DATA_PHASE);
else
ep0_chg_stat(__func__, imx_usb, EP0_OUT_DATA_PHASE);
i = imx_usb->driver->setup(&imx_usb->gadget, &u.r);
if (i < 0) {
D_ERR(imx_usb->dev, "<%s> device setup error %d\n",
__func__, i);
goto stall;
}
return;
stall:
D_ERR(imx_usb->dev, "<%s> protocol STALL\n", __func__);
imx_ep_stall(imx_ep);
ep0_chg_stat(__func__, imx_usb, EP0_STALL);
return;
}
static int imx_ep_enable(struct usb_ep *usb_ep,
const struct usb_endpoint_descriptor *desc)
{
struct imx_ep_struct *imx_ep = container_of(usb_ep,
struct imx_ep_struct, ep);
struct imx_udc_struct *imx_usb = imx_ep->imx_usb;
unsigned long flags;
if (!usb_ep
|| !desc
|| !EP_NO(imx_ep)
|| desc->bDescriptorType != USB_DT_ENDPOINT
|| imx_ep->bEndpointAddress != desc->bEndpointAddress) {
D_ERR(imx_usb->dev,
"<%s> bad ep or descriptor\n", __func__);
return -EINVAL;
}
if (imx_ep->bmAttributes != desc->bmAttributes) {
D_ERR(imx_usb->dev,
"<%s> %s type mismatch\n", __func__, usb_ep->name);
return -EINVAL;
}
if (imx_ep->fifosize < le16_to_cpu(desc->wMaxPacketSize)) {
D_ERR(imx_usb->dev,
"<%s> bad %s maxpacket\n", __func__, usb_ep->name);
return -ERANGE;
}
if (!imx_usb->driver || imx_usb->gadget.speed == USB_SPEED_UNKNOWN) {
D_ERR(imx_usb->dev, "<%s> bogus device state\n", __func__);
return -ESHUTDOWN;
}
local_irq_save(flags);
imx_ep->stopped = 0;
imx_flush(imx_ep);
imx_ep_irq_enable(imx_ep);
local_irq_restore(flags);
D_EPX(imx_usb->dev, "<%s> ENABLED %s\n", __func__, usb_ep->name);
return 0;
}
static int imx_ep_disable(struct usb_ep *usb_ep)
{
struct imx_ep_struct *imx_ep = container_of(usb_ep,
struct imx_ep_struct, ep);
unsigned long flags;
if (!usb_ep || !EP_NO(imx_ep) || !list_empty(&imx_ep->queue)) {
D_ERR(imx_ep->imx_usb->dev, "<%s> %s can not be disabled\n",
__func__, usb_ep ? imx_ep->ep.name : NULL);
return -EINVAL;
}
local_irq_save(flags);
imx_ep->stopped = 1;
nuke(imx_ep, -ESHUTDOWN);
imx_flush(imx_ep);
imx_ep_irq_disable(imx_ep);
local_irq_restore(flags);
D_EPX(imx_ep->imx_usb->dev,
"<%s> DISABLED %s\n", __func__, usb_ep->name);
return 0;
}
static struct usb_request *imx_ep_alloc_request
(struct usb_ep *usb_ep, gfp_t gfp_flags)
{
struct imx_request *req;
if (!usb_ep)
return NULL;
req = kzalloc(sizeof *req, gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD(&req->queue);
req->in_use = 0;
return &req->req;
}
static void imx_ep_free_request
(struct usb_ep *usb_ep, struct usb_request *usb_req)
{
struct imx_request *req;
req = container_of(usb_req, struct imx_request, req);
WARN_ON(!list_empty(&req->queue));
kfree(req);
}
static int imx_ep_queue
(struct usb_ep *usb_ep, struct usb_request *usb_req, gfp_t gfp_flags)
{
struct imx_ep_struct *imx_ep;
struct imx_udc_struct *imx_usb;
struct imx_request *req;
unsigned long flags;
int ret = 0;
imx_ep = container_of(usb_ep, struct imx_ep_struct, ep);
imx_usb = imx_ep->imx_usb;
req = container_of(usb_req, struct imx_request, req);
if (imx_usb->set_config && !EP_NO(imx_ep)) {
imx_usb->set_config = 0;
D_ERR(imx_usb->dev,
"<%s> gadget reply set config\n", __func__);
return 0;
}
if (unlikely(!usb_req || !req || !usb_req->complete || !usb_req->buf)) {
D_ERR(imx_usb->dev, "<%s> bad params\n", __func__);
return -EINVAL;
}
if (unlikely(!usb_ep || !imx_ep)) {
D_ERR(imx_usb->dev, "<%s> bad ep\n", __func__);
return -EINVAL;
}
if (!imx_usb->driver || imx_usb->gadget.speed == USB_SPEED_UNKNOWN) {
D_ERR(imx_usb->dev, "<%s> bogus device state\n", __func__);
return -ESHUTDOWN;
}
D_REQ(imx_usb->dev, "<%s> ep%d %s request for [%d] bytes\n",
__func__, EP_NO(imx_ep),
((!EP_NO(imx_ep) && imx_ep->imx_usb->ep0state
== EP0_IN_DATA_PHASE)
|| (EP_NO(imx_ep) && EP_DIR(imx_ep)))
? "IN" : "OUT", usb_req->length);
dump_req(__func__, imx_ep, usb_req);
if (imx_ep->stopped) {
usb_req->status = -ESHUTDOWN;
return -ESHUTDOWN;
}
if (req->in_use) {
D_ERR(imx_usb->dev,
"<%s> refusing to queue req %p (already queued)\n",
__func__, req);
return 0;
}
local_irq_save(flags);
usb_req->status = -EINPROGRESS;
usb_req->actual = 0;
ep_add_request(imx_ep, req);
if (!EP_NO(imx_ep))
ret = handle_ep0(imx_ep);
else
ret = handle_ep(imx_ep);
local_irq_restore(flags);
return ret;
}
static int imx_ep_dequeue(struct usb_ep *usb_ep, struct usb_request *usb_req)
{
struct imx_ep_struct *imx_ep = container_of
(usb_ep, struct imx_ep_struct, ep);
struct imx_request *req;
unsigned long flags;
if (unlikely(!usb_ep || !EP_NO(imx_ep))) {
D_ERR(imx_ep->imx_usb->dev, "<%s> bad ep\n", __func__);
return -EINVAL;
}
local_irq_save(flags);
list_for_each_entry(req, &imx_ep->queue, queue) {
if (&req->req == usb_req)
break;
}
if (&req->req != usb_req) {
local_irq_restore(flags);
return -EINVAL;
}
done(imx_ep, req, -ECONNRESET);
local_irq_restore(flags);
return 0;
}
static int imx_ep_set_halt(struct usb_ep *usb_ep, int value)
{
struct imx_ep_struct *imx_ep = container_of
(usb_ep, struct imx_ep_struct, ep);
unsigned long flags;
if (unlikely(!usb_ep || !EP_NO(imx_ep))) {
D_ERR(imx_ep->imx_usb->dev, "<%s> bad ep\n", __func__);
return -EINVAL;
}
local_irq_save(flags);
if ((imx_ep->bEndpointAddress & USB_DIR_IN)
&& !list_empty(&imx_ep->queue)) {
local_irq_restore(flags);
return -EAGAIN;
}
imx_ep_stall(imx_ep);
local_irq_restore(flags);
D_EPX(imx_ep->imx_usb->dev, "<%s> %s halt\n", __func__, usb_ep->name);
return 0;
}
static int imx_ep_fifo_status(struct usb_ep *usb_ep)
{
struct imx_ep_struct *imx_ep = container_of
(usb_ep, struct imx_ep_struct, ep);
if (!usb_ep) {
D_ERR(imx_ep->imx_usb->dev, "<%s> bad ep\n", __func__);
return -ENODEV;
}
if (imx_ep->imx_usb->gadget.speed == USB_SPEED_UNKNOWN)
return 0;
else
return imx_fifo_bcount(imx_ep);
}
static void imx_ep_fifo_flush(struct usb_ep *usb_ep)
{
struct imx_ep_struct *imx_ep = container_of
(usb_ep, struct imx_ep_struct, ep);
unsigned long flags;
local_irq_save(flags);
if (!usb_ep || !EP_NO(imx_ep) || !list_empty(&imx_ep->queue)) {
D_ERR(imx_ep->imx_usb->dev, "<%s> bad ep\n", __func__);
local_irq_restore(flags);
return;
}
imx_flush(imx_ep);
local_irq_restore(flags);
}
void ep0_chg_stat(const char *label,
struct imx_udc_struct *imx_usb, enum ep0_state stat)
{
D_EP0(imx_usb->dev, "<%s> from %15s to %15s\n",
label, state_name[imx_usb->ep0state], state_name[stat]);
if (imx_usb->ep0state == stat)
return;
imx_usb->ep0state = stat;
}
static void usb_init_data(struct imx_udc_struct *imx_usb)
{
struct imx_ep_struct *imx_ep;
u8 i;
INIT_LIST_HEAD(&imx_usb->gadget.ep_list);
INIT_LIST_HEAD(&imx_usb->gadget.ep0->ep_list);
ep0_chg_stat(__func__, imx_usb, EP0_IDLE);
for (i = 0; i < IMX_USB_NB_EP; i++) {
imx_ep = &imx_usb->imx_ep[i];
if (i) {
list_add_tail(&imx_ep->ep.ep_list,
&imx_usb->gadget.ep_list);
imx_ep->stopped = 1;
} else
imx_ep->stopped = 0;
INIT_LIST_HEAD(&imx_ep->queue);
}
}
static void udc_stop_activity(struct imx_udc_struct *imx_usb,
struct usb_gadget_driver *driver)
{
struct imx_ep_struct *imx_ep;
int i;
if (imx_usb->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
for (i = 1; i < IMX_USB_NB_EP; i++) {
imx_ep = &imx_usb->imx_ep[i];
imx_flush(imx_ep);
imx_ep->stopped = 1;
imx_ep_irq_disable(imx_ep);
nuke(imx_ep, -ESHUTDOWN);
}
imx_usb->cfg = 0;
imx_usb->intf = 0;
imx_usb->alt = 0;
if (driver)
driver->disconnect(&imx_usb->gadget);
}
static void handle_config(unsigned long data)
{
struct imx_udc_struct *imx_usb = (void *)data;
struct usb_ctrlrequest u;
int temp, cfg, intf, alt;
local_irq_disable();
temp = __raw_readl(imx_usb->base + USB_STAT);
cfg = (temp & STAT_CFG) >> 5;
intf = (temp & STAT_INTF) >> 3;
alt = temp & STAT_ALTSET;
D_REQ(imx_usb->dev,
"<%s> orig config C=%d, I=%d, A=%d / "
"req config C=%d, I=%d, A=%d\n",
__func__, imx_usb->cfg, imx_usb->intf, imx_usb->alt,
cfg, intf, alt);
if (cfg == 1 || cfg == 2) {
if (imx_usb->cfg != cfg) {
u.bRequest = USB_REQ_SET_CONFIGURATION;
u.bRequestType = USB_DIR_OUT |
USB_TYPE_STANDARD |
USB_RECIP_DEVICE;
u.wValue = cfg;
u.wIndex = 0;
u.wLength = 0;
imx_usb->cfg = cfg;
imx_usb->driver->setup(&imx_usb->gadget, &u);
}
if (imx_usb->intf != intf || imx_usb->alt != alt) {
u.bRequest = USB_REQ_SET_INTERFACE;
u.bRequestType = USB_DIR_OUT |
USB_TYPE_STANDARD |
USB_RECIP_INTERFACE;
u.wValue = alt;
u.wIndex = intf;
u.wLength = 0;
imx_usb->intf = intf;
imx_usb->alt = alt;
imx_usb->driver->setup(&imx_usb->gadget, &u);
}
}
imx_usb->set_config = 0;
local_irq_enable();
}
static irqreturn_t imx_udc_irq(int irq, void *dev)
{
struct imx_udc_struct *imx_usb = dev;
int intr = __raw_readl(imx_usb->base + USB_INTR);
int temp;
if (intr & (INTR_WAKEUP | INTR_SUSPEND | INTR_RESUME | INTR_RESET_START
| INTR_RESET_STOP | INTR_CFG_CHG)) {
dump_intr(__func__, intr, imx_usb->dev);
dump_usb_stat(__func__, imx_usb);
}
if (!imx_usb->driver)
goto end_irq;
if (intr & INTR_SOF) {
if (imx_usb->ep0state == EP0_IDLE) {
temp = __raw_readl(imx_usb->base + USB_CTRL);
__raw_writel(temp | CTRL_CMDOVER,
imx_usb->base + USB_CTRL);
}
}
if (intr & INTR_CFG_CHG) {
__raw_writel(INTR_CFG_CHG, imx_usb->base + USB_INTR);
imx_usb->set_config = 1;
mod_timer(&imx_usb->timer, jiffies + 5);
goto end_irq;
}
if (intr & INTR_WAKEUP) {
if (imx_usb->gadget.speed == USB_SPEED_UNKNOWN
&& imx_usb->driver && imx_usb->driver->resume)
imx_usb->driver->resume(&imx_usb->gadget);
imx_usb->set_config = 0;
del_timer(&imx_usb->timer);
imx_usb->gadget.speed = USB_SPEED_FULL;
}
if (intr & INTR_SUSPEND) {
if (imx_usb->gadget.speed != USB_SPEED_UNKNOWN
&& imx_usb->driver && imx_usb->driver->suspend)
imx_usb->driver->suspend(&imx_usb->gadget);
imx_usb->set_config = 0;
del_timer(&imx_usb->timer);
imx_usb->gadget.speed = USB_SPEED_UNKNOWN;
}
if (intr & INTR_RESET_START) {
__raw_writel(intr, imx_usb->base + USB_INTR);
udc_stop_activity(imx_usb, imx_usb->driver);
imx_usb->set_config = 0;
del_timer(&imx_usb->timer);
imx_usb->gadget.speed = USB_SPEED_UNKNOWN;
}
if (intr & INTR_RESET_STOP)
imx_usb->gadget.speed = USB_SPEED_FULL;
end_irq:
__raw_writel(intr, imx_usb->base + USB_INTR);
return IRQ_HANDLED;
}
static irqreturn_t imx_udc_ctrl_irq(int irq, void *dev)
{
struct imx_udc_struct *imx_usb = dev;
struct imx_ep_struct *imx_ep = &imx_usb->imx_ep[0];
int intr = __raw_readl(imx_usb->base + USB_EP_INTR(0));
dump_ep_intr(__func__, 0, intr, imx_usb->dev);
if (!imx_usb->driver) {
__raw_writel(intr, imx_usb->base + USB_EP_INTR(0));
return IRQ_HANDLED;
}
if (intr & (EPINTR_DEVREQ | EPINTR_MDEVREQ))
handle_ep0_devreq(imx_usb);
else if (!list_empty(&imx_ep->queue))
handle_ep0(imx_ep);
__raw_writel(intr, imx_usb->base + USB_EP_INTR(0));
return IRQ_HANDLED;
}
static irqreturn_t imx_udc_bulk_irq(int irq, void *dev)
{
struct imx_udc_struct *imx_usb = dev;
struct imx_ep_struct *imx_ep = &imx_usb->imx_ep[irq - MX1_INT_USBD0];
int intr = __raw_readl(imx_usb->base + USB_EP_INTR(EP_NO(imx_ep)));
dump_ep_intr(__func__, irq - MX1_INT_USBD0, intr, imx_usb->dev);
if (!imx_usb->driver) {
__raw_writel(intr, imx_usb->base + USB_EP_INTR(EP_NO(imx_ep)));
return IRQ_HANDLED;
}
handle_ep(imx_ep);
__raw_writel(intr, imx_usb->base + USB_EP_INTR(EP_NO(imx_ep)));
return IRQ_HANDLED;
}
irq_handler_t intr_handler(int i)
{
switch (i) {
case 0:
return imx_udc_ctrl_irq;
case 1:
case 2:
case 3:
case 4:
case 5:
return imx_udc_bulk_irq;
default:
return imx_udc_irq;
}
}
static int imx_udc_start(struct usb_gadget_driver *driver,
int (*bind)(struct usb_gadget *))
{
struct imx_udc_struct *imx_usb = &controller;
int retval;
if (!driver
|| driver->speed < USB_SPEED_FULL
|| !bind
|| !driver->disconnect
|| !driver->setup)
return -EINVAL;
if (!imx_usb)
return -ENODEV;
if (imx_usb->driver)
return -EBUSY;
imx_usb->driver = driver;
imx_usb->gadget.dev.driver = &driver->driver;
retval = device_add(&imx_usb->gadget.dev);
if (retval)
goto fail;
retval = bind(&imx_usb->gadget);
if (retval) {
D_ERR(imx_usb->dev, "<%s> bind to driver %s --> error %d\n",
__func__, driver->driver.name, retval);
device_del(&imx_usb->gadget.dev);
goto fail;
}
D_INI(imx_usb->dev, "<%s> registered gadget driver '%s'\n",
__func__, driver->driver.name);
imx_udc_enable(imx_usb);
return 0;
fail:
imx_usb->driver = NULL;
imx_usb->gadget.dev.driver = NULL;
return retval;
}
static int imx_udc_stop(struct usb_gadget_driver *driver)
{
struct imx_udc_struct *imx_usb = &controller;
if (!imx_usb)
return -ENODEV;
if (!driver || driver != imx_usb->driver || !driver->unbind)
return -EINVAL;
udc_stop_activity(imx_usb, driver);
imx_udc_disable(imx_usb);
del_timer(&imx_usb->timer);
driver->unbind(&imx_usb->gadget);
imx_usb->gadget.dev.driver = NULL;
imx_usb->driver = NULL;
device_del(&imx_usb->gadget.dev);
D_INI(imx_usb->dev, "<%s> unregistered gadget driver '%s'\n",
__func__, driver->driver.name);
return 0;
}
static int __init imx_udc_probe(struct platform_device *pdev)
{
struct imx_udc_struct *imx_usb = &controller;
struct resource *res;
struct imxusb_platform_data *pdata;
struct clk *clk;
void __iomem *base;
int ret = 0;
int i;
resource_size_t res_size;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "can't get device resources\n");
return -ENODEV;
}
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "driver needs platform data\n");
return -ENODEV;
}
res_size = resource_size(res);
if (!request_mem_region(res->start, res_size, res->name)) {
dev_err(&pdev->dev, "can't allocate %d bytes at %d address\n",
res_size, res->start);
return -ENOMEM;
}
if (pdata->init) {
ret = pdata->init(&pdev->dev);
if (ret)
goto fail0;
}
base = ioremap(res->start, res_size);
if (!base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -EIO;
goto fail1;
}
clk = clk_get(NULL, "usbd_clk");
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
dev_err(&pdev->dev, "can't get USB clock\n");
goto fail2;
}
clk_enable(clk);
if (clk_get_rate(clk) != 48000000) {
D_INI(&pdev->dev,
"Bad USB clock (%d Hz), changing to 48000000 Hz\n",
(int)clk_get_rate(clk));
if (clk_set_rate(clk, 48000000)) {
dev_err(&pdev->dev,
"Unable to set correct USB clock (48MHz)\n");
ret = -EIO;
goto fail3;
}
}
for (i = 0; i < IMX_USB_NB_EP + 1; i++) {
imx_usb->usbd_int[i] = platform_get_irq(pdev, i);
if (imx_usb->usbd_int[i] < 0) {
dev_err(&pdev->dev, "can't get irq number\n");
ret = -ENODEV;
goto fail3;
}
}
for (i = 0; i < IMX_USB_NB_EP + 1; i++) {
ret = request_irq(imx_usb->usbd_int[i], intr_handler(i),
IRQF_DISABLED, driver_name, imx_usb);
if (ret) {
dev_err(&pdev->dev, "can't get irq %i, err %d\n",
imx_usb->usbd_int[i], ret);
for (--i; i >= 0; i--)
free_irq(imx_usb->usbd_int[i], imx_usb);
goto fail3;
}
}
imx_usb->res = res;
imx_usb->base = base;
imx_usb->clk = clk;
imx_usb->dev = &pdev->dev;
device_initialize(&imx_usb->gadget.dev);
imx_usb->gadget.dev.parent = &pdev->dev;
imx_usb->gadget.dev.dma_mask = pdev->dev.dma_mask;
platform_set_drvdata(pdev, imx_usb);
usb_init_data(imx_usb);
imx_udc_init(imx_usb);
init_timer(&imx_usb->timer);
imx_usb->timer.function = handle_config;
imx_usb->timer.data = (unsigned long)imx_usb;
ret = usb_add_gadget_udc(&pdev->dev, &imx_usb->gadget);
if (ret)
goto fail4;
return 0;
fail4:
for (i = 0; i < IMX_USB_NB_EP + 1; i++)
free_irq(imx_usb->usbd_int[i], imx_usb);
fail3:
clk_put(clk);
clk_disable(clk);
fail2:
iounmap(base);
fail1:
if (pdata->exit)
pdata->exit(&pdev->dev);
fail0:
release_mem_region(res->start, res_size);
return ret;
}
static int __exit imx_udc_remove(struct platform_device *pdev)
{
struct imx_udc_struct *imx_usb = platform_get_drvdata(pdev);
struct imxusb_platform_data *pdata = pdev->dev.platform_data;
int i;
usb_del_gadget_udc(&imx_usb->gadget);
imx_udc_disable(imx_usb);
del_timer(&imx_usb->timer);
for (i = 0; i < IMX_USB_NB_EP + 1; i++)
free_irq(imx_usb->usbd_int[i], imx_usb);
clk_put(imx_usb->clk);
clk_disable(imx_usb->clk);
iounmap(imx_usb->base);
release_mem_region(imx_usb->res->start, resource_size(imx_usb->res));
if (pdata->exit)
pdata->exit(&pdev->dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init udc_init(void)
{
return platform_driver_probe(&udc_driver, imx_udc_probe);
}
static void __exit udc_exit(void)
{
platform_driver_unregister(&udc_driver);
}
