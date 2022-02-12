static inline struct s3c_hsudc_req *our_req(struct usb_request *req)
{
return container_of(req, struct s3c_hsudc_req, req);
}
static inline struct s3c_hsudc_ep *our_ep(struct usb_ep *ep)
{
return container_of(ep, struct s3c_hsudc_ep, ep);
}
static inline struct s3c_hsudc *to_hsudc(struct usb_gadget *gadget)
{
return container_of(gadget, struct s3c_hsudc, gadget);
}
static inline void set_index(struct s3c_hsudc *hsudc, int ep_addr)
{
ep_addr &= USB_ENDPOINT_NUMBER_MASK;
writel(ep_addr, hsudc->regs + S3C_IR);
}
static inline void __orr32(void __iomem *ptr, u32 val)
{
writel(readl(ptr) | val, ptr);
}
static void s3c_hsudc_init_phy(void)
{
u32 cfg;
cfg = readl(S3C2443_PWRCFG) | S3C2443_PWRCFG_USBPHY;
writel(cfg, S3C2443_PWRCFG);
cfg = readl(S3C2443_URSTCON);
cfg |= (S3C2443_URSTCON_FUNCRST | S3C2443_URSTCON_PHYRST);
writel(cfg, S3C2443_URSTCON);
mdelay(1);
cfg = readl(S3C2443_URSTCON);
cfg &= ~(S3C2443_URSTCON_FUNCRST | S3C2443_URSTCON_PHYRST);
writel(cfg, S3C2443_URSTCON);
cfg = readl(S3C2443_PHYCTRL);
cfg &= ~(S3C2443_PHYCTRL_CLKSEL | S3C2443_PHYCTRL_DSPORT);
cfg |= (S3C2443_PHYCTRL_EXTCLK | S3C2443_PHYCTRL_PLLSEL);
writel(cfg, S3C2443_PHYCTRL);
cfg = readl(S3C2443_PHYPWR);
cfg &= ~(S3C2443_PHYPWR_FSUSPEND | S3C2443_PHYPWR_PLL_PWRDN |
S3C2443_PHYPWR_XO_ON | S3C2443_PHYPWR_PLL_REFCLK |
S3C2443_PHYPWR_ANALOG_PD);
cfg |= S3C2443_PHYPWR_COMMON_ON;
writel(cfg, S3C2443_PHYPWR);
cfg = readl(S3C2443_UCLKCON);
cfg |= (S3C2443_UCLKCON_DETECT_VBUS | S3C2443_UCLKCON_FUNC_CLKEN |
S3C2443_UCLKCON_TCLKEN);
writel(cfg, S3C2443_UCLKCON);
}
static void s3c_hsudc_uninit_phy(void)
{
u32 cfg;
cfg = readl(S3C2443_PWRCFG) & ~S3C2443_PWRCFG_USBPHY;
writel(cfg, S3C2443_PWRCFG);
writel(S3C2443_PHYPWR_FSUSPEND, S3C2443_PHYPWR);
cfg = readl(S3C2443_UCLKCON) & ~S3C2443_UCLKCON_FUNC_CLKEN;
writel(cfg, S3C2443_UCLKCON);
}
static void s3c_hsudc_complete_request(struct s3c_hsudc_ep *hsep,
struct s3c_hsudc_req *hsreq, int status)
{
unsigned int stopped = hsep->stopped;
struct s3c_hsudc *hsudc = hsep->dev;
list_del_init(&hsreq->queue);
hsreq->req.status = status;
if (!ep_index(hsep)) {
hsudc->ep0state = WAIT_FOR_SETUP;
hsep->bEndpointAddress &= ~USB_DIR_IN;
}
hsep->stopped = 1;
spin_unlock(&hsudc->lock);
if (hsreq->req.complete != NULL)
hsreq->req.complete(&hsep->ep, &hsreq->req);
spin_lock(&hsudc->lock);
hsep->stopped = stopped;
}
static void s3c_hsudc_nuke_ep(struct s3c_hsudc_ep *hsep, int status)
{
struct s3c_hsudc_req *hsreq;
while (!list_empty(&hsep->queue)) {
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
s3c_hsudc_complete_request(hsep, hsreq, status);
}
}
static void s3c_hsudc_stop_activity(struct s3c_hsudc *hsudc)
{
struct s3c_hsudc_ep *hsep;
int epnum;
hsudc->gadget.speed = USB_SPEED_UNKNOWN;
for (epnum = 0; epnum < hsudc->pd->epnum; epnum++) {
hsep = &hsudc->ep[epnum];
hsep->stopped = 1;
s3c_hsudc_nuke_ep(hsep, -ESHUTDOWN);
}
}
static void s3c_hsudc_read_setup_pkt(struct s3c_hsudc *hsudc, u16 *buf)
{
int count;
count = readl(hsudc->regs + S3C_BRCR);
while (count--)
*buf++ = (u16)readl(hsudc->regs + S3C_BR(0));
writel(S3C_EP0SR_RX_SUCCESS, hsudc->regs + S3C_EP0SR);
}
static int s3c_hsudc_write_fifo(struct s3c_hsudc_ep *hsep,
struct s3c_hsudc_req *hsreq)
{
u16 *buf;
u32 max = ep_maxpacket(hsep);
u32 count, length;
bool is_last;
void __iomem *fifo = hsep->fifo;
buf = hsreq->req.buf + hsreq->req.actual;
prefetch(buf);
length = hsreq->req.length - hsreq->req.actual;
length = min(length, max);
hsreq->req.actual += length;
writel(length, hsep->dev->regs + S3C_BWCR);
for (count = 0; count < length; count += 2)
writel(*buf++, fifo);
if (count != max) {
is_last = true;
} else {
if (hsreq->req.length != hsreq->req.actual || hsreq->req.zero)
is_last = false;
else
is_last = true;
}
if (is_last) {
s3c_hsudc_complete_request(hsep, hsreq, 0);
return 1;
}
return 0;
}
static int s3c_hsudc_read_fifo(struct s3c_hsudc_ep *hsep,
struct s3c_hsudc_req *hsreq)
{
struct s3c_hsudc *hsudc = hsep->dev;
u32 csr, offset;
u16 *buf, word;
u32 buflen, rcnt, rlen;
void __iomem *fifo = hsep->fifo;
u32 is_short = 0;
offset = (ep_index(hsep)) ? S3C_ESR : S3C_EP0SR;
csr = readl(hsudc->regs + offset);
if (!(csr & S3C_ESR_RX_SUCCESS))
return -EINVAL;
buf = hsreq->req.buf + hsreq->req.actual;
prefetchw(buf);
buflen = hsreq->req.length - hsreq->req.actual;
rcnt = readl(hsudc->regs + S3C_BRCR);
rlen = (csr & S3C_ESR_LWO) ? (rcnt * 2 - 1) : (rcnt * 2);
hsreq->req.actual += min(rlen, buflen);
is_short = (rlen < hsep->ep.maxpacket);
while (rcnt-- != 0) {
word = (u16)readl(fifo);
if (buflen) {
*buf++ = word;
buflen--;
} else {
hsreq->req.status = -EOVERFLOW;
}
}
writel(S3C_ESR_RX_SUCCESS, hsudc->regs + offset);
if (is_short || hsreq->req.actual == hsreq->req.length) {
s3c_hsudc_complete_request(hsep, hsreq, 0);
return 1;
}
return 0;
}
static void s3c_hsudc_epin_intr(struct s3c_hsudc *hsudc, u32 ep_idx)
{
struct s3c_hsudc_ep *hsep = &hsudc->ep[ep_idx];
struct s3c_hsudc_req *hsreq;
u32 csr;
csr = readl(hsudc->regs + S3C_ESR);
if (csr & S3C_ESR_STALL) {
writel(S3C_ESR_STALL, hsudc->regs + S3C_ESR);
return;
}
if (csr & S3C_ESR_TX_SUCCESS) {
writel(S3C_ESR_TX_SUCCESS, hsudc->regs + S3C_ESR);
if (list_empty(&hsep->queue))
return;
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
if ((s3c_hsudc_write_fifo(hsep, hsreq) == 0) &&
(csr & S3C_ESR_PSIF_TWO))
s3c_hsudc_write_fifo(hsep, hsreq);
}
}
static void s3c_hsudc_epout_intr(struct s3c_hsudc *hsudc, u32 ep_idx)
{
struct s3c_hsudc_ep *hsep = &hsudc->ep[ep_idx];
struct s3c_hsudc_req *hsreq;
u32 csr;
csr = readl(hsudc->regs + S3C_ESR);
if (csr & S3C_ESR_STALL) {
writel(S3C_ESR_STALL, hsudc->regs + S3C_ESR);
return;
}
if (csr & S3C_ESR_FLUSH) {
__orr32(hsudc->regs + S3C_ECR, S3C_ECR_FLUSH);
return;
}
if (csr & S3C_ESR_RX_SUCCESS) {
if (list_empty(&hsep->queue))
return;
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
if (((s3c_hsudc_read_fifo(hsep, hsreq)) == 0) &&
(csr & S3C_ESR_PSIF_TWO))
s3c_hsudc_read_fifo(hsep, hsreq);
}
}
static int s3c_hsudc_set_halt(struct usb_ep *_ep, int value)
{
struct s3c_hsudc_ep *hsep = our_ep(_ep);
struct s3c_hsudc *hsudc = hsep->dev;
struct s3c_hsudc_req *hsreq;
unsigned long irqflags;
u32 ecr;
u32 offset;
if (value && ep_is_in(hsep) && !list_empty(&hsep->queue))
return -EAGAIN;
spin_lock_irqsave(&hsudc->lock, irqflags);
set_index(hsudc, ep_index(hsep));
offset = (ep_index(hsep)) ? S3C_ECR : S3C_EP0CR;
ecr = readl(hsudc->regs + offset);
if (value) {
ecr |= S3C_ECR_STALL;
if (ep_index(hsep))
ecr |= S3C_ECR_FLUSH;
hsep->stopped = 1;
} else {
ecr &= ~S3C_ECR_STALL;
hsep->stopped = hsep->wedge = 0;
}
writel(ecr, hsudc->regs + offset);
if (ep_is_in(hsep) && !list_empty(&hsep->queue) && !value) {
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
if (hsreq)
s3c_hsudc_write_fifo(hsep, hsreq);
}
spin_unlock_irqrestore(&hsudc->lock, irqflags);
return 0;
}
static int s3c_hsudc_set_wedge(struct usb_ep *_ep)
{
struct s3c_hsudc_ep *hsep = our_ep(_ep);
if (!hsep)
return -EINVAL;
hsep->wedge = 1;
return usb_ep_set_halt(_ep);
}
static int s3c_hsudc_handle_reqfeat(struct s3c_hsudc *hsudc,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsudc_ep *hsep;
bool set = (ctrl->bRequest == USB_REQ_SET_FEATURE);
u8 ep_num = ctrl->wIndex & USB_ENDPOINT_NUMBER_MASK;
if (ctrl->bRequestType == USB_RECIP_ENDPOINT) {
hsep = &hsudc->ep[ep_num];
switch (le16_to_cpu(ctrl->wValue)) {
case USB_ENDPOINT_HALT:
if (set || (!set && !hsep->wedge))
s3c_hsudc_set_halt(&hsep->ep, set);
return 0;
}
}
return -ENOENT;
}
static void s3c_hsudc_process_req_status(struct s3c_hsudc *hsudc,
struct usb_ctrlrequest *ctrl)
{
struct s3c_hsudc_ep *hsep0 = &hsudc->ep[0];
struct s3c_hsudc_req hsreq;
struct s3c_hsudc_ep *hsep;
__le16 reply;
u8 epnum;
switch (ctrl->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_DEVICE:
reply = cpu_to_le16(0);
break;
case USB_RECIP_INTERFACE:
reply = cpu_to_le16(0);
break;
case USB_RECIP_ENDPOINT:
epnum = le16_to_cpu(ctrl->wIndex) & USB_ENDPOINT_NUMBER_MASK;
hsep = &hsudc->ep[epnum];
reply = cpu_to_le16(hsep->stopped ? 1 : 0);
break;
}
INIT_LIST_HEAD(&hsreq.queue);
hsreq.req.length = 2;
hsreq.req.buf = &reply;
hsreq.req.actual = 0;
hsreq.req.complete = NULL;
s3c_hsudc_write_fifo(hsep0, &hsreq);
}
static void s3c_hsudc_process_setup(struct s3c_hsudc *hsudc)
{
struct s3c_hsudc_ep *hsep = &hsudc->ep[0];
struct usb_ctrlrequest ctrl = {0};
int ret;
s3c_hsudc_nuke_ep(hsep, -EPROTO);
s3c_hsudc_read_setup_pkt(hsudc, (u16 *)&ctrl);
if (ctrl.bRequestType & USB_DIR_IN) {
hsep->bEndpointAddress |= USB_DIR_IN;
hsudc->ep0state = DATA_STATE_XMIT;
} else {
hsep->bEndpointAddress &= ~USB_DIR_IN;
hsudc->ep0state = DATA_STATE_RECV;
}
switch (ctrl.bRequest) {
case USB_REQ_SET_ADDRESS:
if (ctrl.bRequestType != (USB_TYPE_STANDARD | USB_RECIP_DEVICE))
break;
hsudc->ep0state = WAIT_FOR_SETUP;
return;
case USB_REQ_GET_STATUS:
if ((ctrl.bRequestType & USB_TYPE_MASK) != USB_TYPE_STANDARD)
break;
s3c_hsudc_process_req_status(hsudc, &ctrl);
return;
case USB_REQ_SET_FEATURE:
case USB_REQ_CLEAR_FEATURE:
if ((ctrl.bRequestType & USB_TYPE_MASK) != USB_TYPE_STANDARD)
break;
s3c_hsudc_handle_reqfeat(hsudc, &ctrl);
hsudc->ep0state = WAIT_FOR_SETUP;
return;
}
if (hsudc->driver) {
spin_unlock(&hsudc->lock);
ret = hsudc->driver->setup(&hsudc->gadget, &ctrl);
spin_lock(&hsudc->lock);
if (ctrl.bRequest == USB_REQ_SET_CONFIGURATION) {
hsep->bEndpointAddress &= ~USB_DIR_IN;
hsudc->ep0state = WAIT_FOR_SETUP;
}
if (ret < 0) {
dev_err(hsudc->dev, "setup failed, returned %d\n",
ret);
s3c_hsudc_set_halt(&hsep->ep, 1);
hsudc->ep0state = WAIT_FOR_SETUP;
hsep->bEndpointAddress &= ~USB_DIR_IN;
}
}
}
static void s3c_hsudc_handle_ep0_intr(struct s3c_hsudc *hsudc)
{
struct s3c_hsudc_ep *hsep = &hsudc->ep[0];
struct s3c_hsudc_req *hsreq;
u32 csr = readl(hsudc->regs + S3C_EP0SR);
u32 ecr;
if (csr & S3C_EP0SR_STALL) {
ecr = readl(hsudc->regs + S3C_EP0CR);
ecr &= ~(S3C_ECR_STALL | S3C_ECR_FLUSH);
writel(ecr, hsudc->regs + S3C_EP0CR);
writel(S3C_EP0SR_STALL, hsudc->regs + S3C_EP0SR);
hsep->stopped = 0;
s3c_hsudc_nuke_ep(hsep, -ECONNABORTED);
hsudc->ep0state = WAIT_FOR_SETUP;
hsep->bEndpointAddress &= ~USB_DIR_IN;
return;
}
if (csr & S3C_EP0SR_TX_SUCCESS) {
writel(S3C_EP0SR_TX_SUCCESS, hsudc->regs + S3C_EP0SR);
if (ep_is_in(hsep)) {
if (list_empty(&hsep->queue))
return;
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
s3c_hsudc_write_fifo(hsep, hsreq);
}
}
if (csr & S3C_EP0SR_RX_SUCCESS) {
if (hsudc->ep0state == WAIT_FOR_SETUP)
s3c_hsudc_process_setup(hsudc);
else {
if (!ep_is_in(hsep)) {
if (list_empty(&hsep->queue))
return;
hsreq = list_entry(hsep->queue.next,
struct s3c_hsudc_req, queue);
s3c_hsudc_read_fifo(hsep, hsreq);
}
}
}
}
static int s3c_hsudc_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct s3c_hsudc_ep *hsep;
struct s3c_hsudc *hsudc;
unsigned long flags;
u32 ecr = 0;
hsep = our_ep(_ep);
if (!_ep || !desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT
|| hsep->bEndpointAddress != desc->bEndpointAddress
|| ep_maxpacket(hsep) < usb_endpoint_maxp(desc))
return -EINVAL;
if ((desc->bmAttributes == USB_ENDPOINT_XFER_BULK
&& usb_endpoint_maxp(desc) != ep_maxpacket(hsep))
|| !desc->wMaxPacketSize)
return -ERANGE;
hsudc = hsep->dev;
if (!hsudc->driver || hsudc->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
spin_lock_irqsave(&hsudc->lock, flags);
set_index(hsudc, hsep->bEndpointAddress);
ecr |= ((usb_endpoint_xfer_int(desc)) ? S3C_ECR_IEMS : S3C_ECR_DUEN);
writel(ecr, hsudc->regs + S3C_ECR);
hsep->stopped = hsep->wedge = 0;
hsep->ep.desc = desc;
hsep->ep.maxpacket = usb_endpoint_maxp(desc);
s3c_hsudc_set_halt(_ep, 0);
__set_bit(ep_index(hsep), hsudc->regs + S3C_EIER);
spin_unlock_irqrestore(&hsudc->lock, flags);
return 0;
}
static int s3c_hsudc_ep_disable(struct usb_ep *_ep)
{
struct s3c_hsudc_ep *hsep = our_ep(_ep);
struct s3c_hsudc *hsudc = hsep->dev;
unsigned long flags;
if (!_ep || !hsep->ep.desc)
return -EINVAL;
spin_lock_irqsave(&hsudc->lock, flags);
set_index(hsudc, hsep->bEndpointAddress);
__clear_bit(ep_index(hsep), hsudc->regs + S3C_EIER);
s3c_hsudc_nuke_ep(hsep, -ESHUTDOWN);
hsep->ep.desc = NULL;
hsep->stopped = 1;
spin_unlock_irqrestore(&hsudc->lock, flags);
return 0;
}
static struct usb_request *s3c_hsudc_alloc_request(struct usb_ep *_ep,
gfp_t gfp_flags)
{
struct s3c_hsudc_req *hsreq;
hsreq = kzalloc(sizeof(*hsreq), gfp_flags);
if (!hsreq)
return NULL;
INIT_LIST_HEAD(&hsreq->queue);
return &hsreq->req;
}
static void s3c_hsudc_free_request(struct usb_ep *ep, struct usb_request *_req)
{
struct s3c_hsudc_req *hsreq;
hsreq = our_req(_req);
WARN_ON(!list_empty(&hsreq->queue));
kfree(hsreq);
}
static int s3c_hsudc_queue(struct usb_ep *_ep, struct usb_request *_req,
gfp_t gfp_flags)
{
struct s3c_hsudc_req *hsreq;
struct s3c_hsudc_ep *hsep;
struct s3c_hsudc *hsudc;
unsigned long flags;
u32 offset;
u32 csr;
hsreq = our_req(_req);
if ((!_req || !_req->complete || !_req->buf ||
!list_empty(&hsreq->queue)))
return -EINVAL;
hsep = our_ep(_ep);
hsudc = hsep->dev;
if (!hsudc->driver || hsudc->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
spin_lock_irqsave(&hsudc->lock, flags);
set_index(hsudc, hsep->bEndpointAddress);
_req->status = -EINPROGRESS;
_req->actual = 0;
if (!ep_index(hsep) && _req->length == 0) {
hsudc->ep0state = WAIT_FOR_SETUP;
s3c_hsudc_complete_request(hsep, hsreq, 0);
spin_unlock_irqrestore(&hsudc->lock, flags);
return 0;
}
if (list_empty(&hsep->queue) && !hsep->stopped) {
offset = (ep_index(hsep)) ? S3C_ESR : S3C_EP0SR;
if (ep_is_in(hsep)) {
csr = readl(hsudc->regs + offset);
if (!(csr & S3C_ESR_TX_SUCCESS) &&
(s3c_hsudc_write_fifo(hsep, hsreq) == 1))
hsreq = NULL;
} else {
csr = readl(hsudc->regs + offset);
if ((csr & S3C_ESR_RX_SUCCESS)
&& (s3c_hsudc_read_fifo(hsep, hsreq) == 1))
hsreq = NULL;
}
}
if (hsreq)
list_add_tail(&hsreq->queue, &hsep->queue);
spin_unlock_irqrestore(&hsudc->lock, flags);
return 0;
}
static int s3c_hsudc_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct s3c_hsudc_ep *hsep = our_ep(_ep);
struct s3c_hsudc *hsudc = hsep->dev;
struct s3c_hsudc_req *hsreq;
unsigned long flags;
hsep = our_ep(_ep);
if (!_ep || hsep->ep.name == ep0name)
return -EINVAL;
spin_lock_irqsave(&hsudc->lock, flags);
list_for_each_entry(hsreq, &hsep->queue, queue) {
if (&hsreq->req == _req)
break;
}
if (&hsreq->req != _req) {
spin_unlock_irqrestore(&hsudc->lock, flags);
return -EINVAL;
}
set_index(hsudc, hsep->bEndpointAddress);
s3c_hsudc_complete_request(hsep, hsreq, -ECONNRESET);
spin_unlock_irqrestore(&hsudc->lock, flags);
return 0;
}
static void s3c_hsudc_initep(struct s3c_hsudc *hsudc,
struct s3c_hsudc_ep *hsep, int epnum)
{
char *dir;
if ((epnum % 2) == 0) {
dir = "out";
} else {
dir = "in";
hsep->bEndpointAddress = USB_DIR_IN;
}
hsep->bEndpointAddress |= epnum;
if (epnum)
snprintf(hsep->name, sizeof(hsep->name), "ep%d%s", epnum, dir);
else
snprintf(hsep->name, sizeof(hsep->name), "%s", ep0name);
INIT_LIST_HEAD(&hsep->queue);
INIT_LIST_HEAD(&hsep->ep.ep_list);
if (epnum)
list_add_tail(&hsep->ep.ep_list, &hsudc->gadget.ep_list);
hsep->dev = hsudc;
hsep->ep.name = hsep->name;
usb_ep_set_maxpacket_limit(&hsep->ep, epnum ? 512 : 64);
hsep->ep.ops = &s3c_hsudc_ep_ops;
hsep->fifo = hsudc->regs + S3C_BR(epnum);
hsep->ep.desc = NULL;
hsep->stopped = 0;
hsep->wedge = 0;
set_index(hsudc, epnum);
writel(hsep->ep.maxpacket, hsudc->regs + S3C_MPR);
}
static void s3c_hsudc_setup_ep(struct s3c_hsudc *hsudc)
{
int epnum;
hsudc->ep0state = WAIT_FOR_SETUP;
INIT_LIST_HEAD(&hsudc->gadget.ep_list);
for (epnum = 0; epnum < hsudc->pd->epnum; epnum++)
s3c_hsudc_initep(hsudc, &hsudc->ep[epnum], epnum);
}
static void s3c_hsudc_reconfig(struct s3c_hsudc *hsudc)
{
writel(0xAA, hsudc->regs + S3C_EDR);
writel(1, hsudc->regs + S3C_EIER);
writel(0, hsudc->regs + S3C_TR);
writel(S3C_SCR_DTZIEN_EN | S3C_SCR_RRD_EN | S3C_SCR_SUS_EN |
S3C_SCR_RST_EN, hsudc->regs + S3C_SCR);
writel(0, hsudc->regs + S3C_EP0CR);
s3c_hsudc_setup_ep(hsudc);
}
static irqreturn_t s3c_hsudc_irq(int irq, void *_dev)
{
struct s3c_hsudc *hsudc = _dev;
struct s3c_hsudc_ep *hsep;
u32 ep_intr;
u32 sys_status;
u32 ep_idx;
spin_lock(&hsudc->lock);
sys_status = readl(hsudc->regs + S3C_SSR);
ep_intr = readl(hsudc->regs + S3C_EIR) & 0x3FF;
if (!ep_intr && !(sys_status & S3C_SSR_DTZIEN_EN)) {
spin_unlock(&hsudc->lock);
return IRQ_HANDLED;
}
if (sys_status) {
if (sys_status & S3C_SSR_VBUSON)
writel(S3C_SSR_VBUSON, hsudc->regs + S3C_SSR);
if (sys_status & S3C_SSR_ERR)
writel(S3C_SSR_ERR, hsudc->regs + S3C_SSR);
if (sys_status & S3C_SSR_SDE) {
writel(S3C_SSR_SDE, hsudc->regs + S3C_SSR);
hsudc->gadget.speed = (sys_status & S3C_SSR_HSP) ?
USB_SPEED_HIGH : USB_SPEED_FULL;
}
if (sys_status & S3C_SSR_SUSPEND) {
writel(S3C_SSR_SUSPEND, hsudc->regs + S3C_SSR);
if (hsudc->gadget.speed != USB_SPEED_UNKNOWN
&& hsudc->driver && hsudc->driver->suspend)
hsudc->driver->suspend(&hsudc->gadget);
}
if (sys_status & S3C_SSR_RESUME) {
writel(S3C_SSR_RESUME, hsudc->regs + S3C_SSR);
if (hsudc->gadget.speed != USB_SPEED_UNKNOWN
&& hsudc->driver && hsudc->driver->resume)
hsudc->driver->resume(&hsudc->gadget);
}
if (sys_status & S3C_SSR_RESET) {
writel(S3C_SSR_RESET, hsudc->regs + S3C_SSR);
for (ep_idx = 0; ep_idx < hsudc->pd->epnum; ep_idx++) {
hsep = &hsudc->ep[ep_idx];
hsep->stopped = 1;
s3c_hsudc_nuke_ep(hsep, -ECONNRESET);
}
s3c_hsudc_reconfig(hsudc);
hsudc->ep0state = WAIT_FOR_SETUP;
}
}
if (ep_intr & S3C_EIR_EP0) {
writel(S3C_EIR_EP0, hsudc->regs + S3C_EIR);
set_index(hsudc, 0);
s3c_hsudc_handle_ep0_intr(hsudc);
}
ep_intr >>= 1;
ep_idx = 1;
while (ep_intr) {
if (ep_intr & 1) {
hsep = &hsudc->ep[ep_idx];
set_index(hsudc, ep_idx);
writel(1 << ep_idx, hsudc->regs + S3C_EIR);
if (ep_is_in(hsep))
s3c_hsudc_epin_intr(hsudc, ep_idx);
else
s3c_hsudc_epout_intr(hsudc, ep_idx);
}
ep_intr >>= 1;
ep_idx++;
}
spin_unlock(&hsudc->lock);
return IRQ_HANDLED;
}
static int s3c_hsudc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct s3c_hsudc *hsudc = to_hsudc(gadget);
int ret;
if (!driver
|| driver->max_speed < USB_SPEED_FULL
|| !driver->setup)
return -EINVAL;
if (!hsudc)
return -ENODEV;
if (hsudc->driver)
return -EBUSY;
hsudc->driver = driver;
ret = regulator_bulk_enable(ARRAY_SIZE(hsudc->supplies),
hsudc->supplies);
if (ret != 0) {
dev_err(hsudc->dev, "failed to enable supplies: %d\n", ret);
goto err_supplies;
}
if (!IS_ERR_OR_NULL(hsudc->transceiver)) {
ret = otg_set_peripheral(hsudc->transceiver->otg,
&hsudc->gadget);
if (ret) {
dev_err(hsudc->dev, "%s: can't bind to transceiver\n",
hsudc->gadget.name);
goto err_otg;
}
}
enable_irq(hsudc->irq);
dev_info(hsudc->dev, "bound driver %s\n", driver->driver.name);
s3c_hsudc_reconfig(hsudc);
pm_runtime_get_sync(hsudc->dev);
s3c_hsudc_init_phy();
if (hsudc->pd->gpio_init)
hsudc->pd->gpio_init();
return 0;
err_otg:
regulator_bulk_disable(ARRAY_SIZE(hsudc->supplies), hsudc->supplies);
err_supplies:
hsudc->driver = NULL;
return ret;
}
static int s3c_hsudc_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct s3c_hsudc *hsudc = to_hsudc(gadget);
unsigned long flags;
if (!hsudc)
return -ENODEV;
if (!driver || driver != hsudc->driver)
return -EINVAL;
spin_lock_irqsave(&hsudc->lock, flags);
hsudc->driver = NULL;
hsudc->gadget.speed = USB_SPEED_UNKNOWN;
s3c_hsudc_uninit_phy();
pm_runtime_put(hsudc->dev);
if (hsudc->pd->gpio_uninit)
hsudc->pd->gpio_uninit();
s3c_hsudc_stop_activity(hsudc);
spin_unlock_irqrestore(&hsudc->lock, flags);
if (!IS_ERR_OR_NULL(hsudc->transceiver))
(void) otg_set_peripheral(hsudc->transceiver->otg, NULL);
disable_irq(hsudc->irq);
regulator_bulk_disable(ARRAY_SIZE(hsudc->supplies), hsudc->supplies);
dev_info(hsudc->dev, "unregistered gadget driver '%s'\n",
driver->driver.name);
return 0;
}
static inline u32 s3c_hsudc_read_frameno(struct s3c_hsudc *hsudc)
{
return readl(hsudc->regs + S3C_FNR) & 0x3FF;
}
static int s3c_hsudc_gadget_getframe(struct usb_gadget *gadget)
{
return s3c_hsudc_read_frameno(to_hsudc(gadget));
}
static int s3c_hsudc_vbus_draw(struct usb_gadget *gadget, unsigned mA)
{
struct s3c_hsudc *hsudc = to_hsudc(gadget);
if (!hsudc)
return -ENODEV;
if (!IS_ERR_OR_NULL(hsudc->transceiver))
return usb_phy_set_power(hsudc->transceiver, mA);
return -EOPNOTSUPP;
}
static int s3c_hsudc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct s3c_hsudc *hsudc;
struct s3c24xx_hsudc_platdata *pd = dev_get_platdata(&pdev->dev);
int ret, i;
hsudc = devm_kzalloc(&pdev->dev, sizeof(struct s3c_hsudc) +
sizeof(struct s3c_hsudc_ep) * pd->epnum,
GFP_KERNEL);
if (!hsudc) {
dev_err(dev, "cannot allocate memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, dev);
hsudc->dev = dev;
hsudc->pd = dev_get_platdata(&pdev->dev);
hsudc->transceiver = usb_get_phy(USB_PHY_TYPE_USB2);
for (i = 0; i < ARRAY_SIZE(hsudc->supplies); i++)
hsudc->supplies[i].supply = s3c_hsudc_supply_names[i];
ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(hsudc->supplies),
hsudc->supplies);
if (ret != 0) {
dev_err(dev, "failed to request supplies: %d\n", ret);
goto err_supplies;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hsudc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hsudc->regs)) {
ret = PTR_ERR(hsudc->regs);
goto err_res;
}
spin_lock_init(&hsudc->lock);
hsudc->gadget.max_speed = USB_SPEED_HIGH;
hsudc->gadget.ops = &s3c_hsudc_gadget_ops;
hsudc->gadget.name = dev_name(dev);
hsudc->gadget.ep0 = &hsudc->ep[0].ep;
hsudc->gadget.is_otg = 0;
hsudc->gadget.is_a_peripheral = 0;
hsudc->gadget.speed = USB_SPEED_UNKNOWN;
s3c_hsudc_setup_ep(hsudc);
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "unable to obtain IRQ number\n");
goto err_res;
}
hsudc->irq = ret;
ret = devm_request_irq(&pdev->dev, hsudc->irq, s3c_hsudc_irq, 0,
driver_name, hsudc);
if (ret < 0) {
dev_err(dev, "irq request failed\n");
goto err_res;
}
hsudc->uclk = devm_clk_get(&pdev->dev, "usb-device");
if (IS_ERR(hsudc->uclk)) {
dev_err(dev, "failed to find usb-device clock source\n");
ret = PTR_ERR(hsudc->uclk);
goto err_res;
}
clk_enable(hsudc->uclk);
local_irq_disable();
disable_irq(hsudc->irq);
local_irq_enable();
ret = usb_add_gadget_udc(&pdev->dev, &hsudc->gadget);
if (ret)
goto err_add_udc;
pm_runtime_enable(dev);
return 0;
err_add_udc:
clk_disable(hsudc->uclk);
err_res:
if (!IS_ERR_OR_NULL(hsudc->transceiver))
usb_put_phy(hsudc->transceiver);
err_supplies:
return ret;
}
