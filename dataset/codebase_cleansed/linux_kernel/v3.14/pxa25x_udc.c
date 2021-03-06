static void pullup_off(void)
{
struct pxa2xx_udc_mach_info *mach = the_controller->mach;
int off_level = mach->gpio_pullup_inverted;
if (gpio_is_valid(mach->gpio_pullup))
gpio_set_value(mach->gpio_pullup, off_level);
else if (mach->udc_command)
mach->udc_command(PXA2XX_UDC_CMD_DISCONNECT);
}
static void pullup_on(void)
{
struct pxa2xx_udc_mach_info *mach = the_controller->mach;
int on_level = !mach->gpio_pullup_inverted;
if (gpio_is_valid(mach->gpio_pullup))
gpio_set_value(mach->gpio_pullup, on_level);
else if (mach->udc_command)
mach->udc_command(PXA2XX_UDC_CMD_CONNECT);
}
static void pio_irq_enable(int bEndpointAddress)
{
bEndpointAddress &= 0xf;
if (bEndpointAddress < 8)
UICR0 &= ~(1 << bEndpointAddress);
else {
bEndpointAddress -= 8;
UICR1 &= ~(1 << bEndpointAddress);
}
}
static void pio_irq_disable(int bEndpointAddress)
{
bEndpointAddress &= 0xf;
if (bEndpointAddress < 8)
UICR0 |= 1 << bEndpointAddress;
else {
bEndpointAddress -= 8;
UICR1 |= 1 << bEndpointAddress;
}
}
static inline void udc_set_mask_UDCCR(int mask)
{
UDCCR = (UDCCR & UDCCR_MASK_BITS) | (mask & UDCCR_MASK_BITS);
}
static inline void udc_clear_mask_UDCCR(int mask)
{
UDCCR = (UDCCR & UDCCR_MASK_BITS) & ~(mask & UDCCR_MASK_BITS);
}
static inline void udc_ack_int_UDCCR(int mask)
{
__u32 udccr = UDCCR & UDCCR_MASK_BITS;
UDCCR = udccr | (mask & ~UDCCR_MASK_BITS);
}
static int pxa25x_ep_enable (struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct pxa25x_ep *ep;
struct pxa25x_udc *dev;
ep = container_of (_ep, struct pxa25x_ep, ep);
if (!_ep || !desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT
|| ep->bEndpointAddress != desc->bEndpointAddress
|| ep->fifo_size < usb_endpoint_maxp (desc)) {
DMSG("%s, bad ep or descriptor\n", __func__);
return -EINVAL;
}
if (ep->bmAttributes != desc->bmAttributes
&& ep->bmAttributes != USB_ENDPOINT_XFER_BULK
&& desc->bmAttributes != USB_ENDPOINT_XFER_INT) {
DMSG("%s, %s type mismatch\n", __func__, _ep->name);
return -EINVAL;
}
if ((desc->bmAttributes == USB_ENDPOINT_XFER_BULK
&& usb_endpoint_maxp (desc)
!= BULK_FIFO_SIZE)
|| !desc->wMaxPacketSize) {
DMSG("%s, bad %s maxpacket\n", __func__, _ep->name);
return -ERANGE;
}
dev = ep->dev;
if (!dev->driver || dev->gadget.speed == USB_SPEED_UNKNOWN) {
DMSG("%s, bogus device state\n", __func__);
return -ESHUTDOWN;
}
ep->ep.desc = desc;
ep->stopped = 0;
ep->pio_irqs = 0;
ep->ep.maxpacket = usb_endpoint_maxp (desc);
pxa25x_ep_fifo_flush (_ep);
DBG(DBG_VERBOSE, "enabled %s\n", _ep->name);
return 0;
}
static int pxa25x_ep_disable (struct usb_ep *_ep)
{
struct pxa25x_ep *ep;
unsigned long flags;
ep = container_of (_ep, struct pxa25x_ep, ep);
if (!_ep || !ep->ep.desc) {
DMSG("%s, %s not enabled\n", __func__,
_ep ? ep->ep.name : NULL);
return -EINVAL;
}
local_irq_save(flags);
nuke (ep, -ESHUTDOWN);
pxa25x_ep_fifo_flush (_ep);
ep->ep.desc = NULL;
ep->stopped = 1;
local_irq_restore(flags);
DBG(DBG_VERBOSE, "%s disabled\n", _ep->name);
return 0;
}
static struct usb_request *
pxa25x_ep_alloc_request (struct usb_ep *_ep, gfp_t gfp_flags)
{
struct pxa25x_request *req;
req = kzalloc(sizeof(*req), gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD (&req->queue);
return &req->req;
}
static void
pxa25x_ep_free_request (struct usb_ep *_ep, struct usb_request *_req)
{
struct pxa25x_request *req;
req = container_of (_req, struct pxa25x_request, req);
WARN_ON(!list_empty (&req->queue));
kfree(req);
}
static void done(struct pxa25x_ep *ep, struct pxa25x_request *req, int status)
{
unsigned stopped = ep->stopped;
list_del_init(&req->queue);
if (likely (req->req.status == -EINPROGRESS))
req->req.status = status;
else
status = req->req.status;
if (status && status != -ESHUTDOWN)
DBG(DBG_VERBOSE, "complete %s req %p stat %d len %u/%u\n",
ep->ep.name, &req->req, status,
req->req.actual, req->req.length);
ep->stopped = 1;
req->req.complete(&ep->ep, &req->req);
ep->stopped = stopped;
}
static inline void ep0_idle (struct pxa25x_udc *dev)
{
dev->ep0state = EP0_IDLE;
}
static int
write_packet(volatile u32 *uddr, struct pxa25x_request *req, unsigned max)
{
u8 *buf;
unsigned length, count;
buf = req->req.buf + req->req.actual;
prefetch(buf);
length = min(req->req.length - req->req.actual, max);
req->req.actual += length;
count = length;
while (likely(count--))
*uddr = *buf++;
return length;
}
static int
write_fifo (struct pxa25x_ep *ep, struct pxa25x_request *req)
{
unsigned max;
max = usb_endpoint_maxp(ep->ep.desc);
do {
unsigned count;
int is_last, is_short;
count = write_packet(ep->reg_uddr, req, max);
if (unlikely (count != max))
is_last = is_short = 1;
else {
if (likely(req->req.length != req->req.actual)
|| req->req.zero)
is_last = 0;
else
is_last = 1;
is_short = unlikely (max < ep->fifo_size);
}
DBG(DBG_VERY_NOISY, "wrote %s %d bytes%s%s %d left %p\n",
ep->ep.name, count,
is_last ? "/L" : "", is_short ? "/S" : "",
req->req.length - req->req.actual, req);
*ep->reg_udccs = UDCCS_BI_TPC;
if (is_short)
*ep->reg_udccs = UDCCS_BI_TSP;
if (is_last) {
done (ep, req, 0);
if (list_empty(&ep->queue))
pio_irq_disable (ep->bEndpointAddress);
return 1;
}
} while (*ep->reg_udccs & UDCCS_BI_TFS);
return 0;
}
static inline
void ep0start(struct pxa25x_udc *dev, u32 flags, const char *tag)
{
UDCCS0 = flags|UDCCS0_SA|UDCCS0_OPR;
USIR0 = USIR0_IR0;
dev->req_pending = 0;
DBG(DBG_VERY_NOISY, "%s %s, %02x/%02x\n",
__func__, tag, UDCCS0, flags);
}
static int
write_ep0_fifo (struct pxa25x_ep *ep, struct pxa25x_request *req)
{
unsigned count;
int is_short;
count = write_packet(&UDDR0, req, EP0_FIFO_SIZE);
ep->dev->stats.write.bytes += count;
is_short = (count != EP0_FIFO_SIZE);
DBG(DBG_VERY_NOISY, "ep0in %d bytes %d left %p\n", count,
req->req.length - req->req.actual, req);
if (unlikely (is_short)) {
if (ep->dev->req_pending)
ep0start(ep->dev, UDCCS0_IPR, "short IN");
else
UDCCS0 = UDCCS0_IPR;
count = req->req.length;
done (ep, req, 0);
ep0_idle(ep->dev);
#ifndef CONFIG_ARCH_IXP4XX
#if 1
if (count >= EP0_FIFO_SIZE) {
count = 100;
do {
if ((UDCCS0 & UDCCS0_OPR) != 0) {
UDCCS0 = UDCCS0_OPR;
break;
}
count--;
udelay(1);
} while (count);
}
#endif
#endif
} else if (ep->dev->req_pending)
ep0start(ep->dev, 0, "IN");
return is_short;
}
static int
read_fifo (struct pxa25x_ep *ep, struct pxa25x_request *req)
{
for (;;) {
u32 udccs;
u8 *buf;
unsigned bufferspace, count, is_short;
udccs = *ep->reg_udccs;
if (unlikely ((udccs & UDCCS_BO_RPC) == 0))
break;
buf = req->req.buf + req->req.actual;
prefetchw(buf);
bufferspace = req->req.length - req->req.actual;
if (likely (udccs & UDCCS_BO_RNE)) {
count = 1 + (0x0ff & *ep->reg_ubcr);
req->req.actual += min (count, bufferspace);
} else
count = 0;
is_short = (count < ep->ep.maxpacket);
DBG(DBG_VERY_NOISY, "read %s %02x, %d bytes%s req %p %d/%d\n",
ep->ep.name, udccs, count,
is_short ? "/S" : "",
req, req->req.actual, req->req.length);
while (likely (count-- != 0)) {
u8 byte = (u8) *ep->reg_uddr;
if (unlikely (bufferspace == 0)) {
if (req->req.status != -EOVERFLOW)
DMSG("%s overflow %d\n",
ep->ep.name, count);
req->req.status = -EOVERFLOW;
} else {
*buf++ = byte;
bufferspace--;
}
}
*ep->reg_udccs = UDCCS_BO_RPC;
if (ep->bmAttributes == USB_ENDPOINT_XFER_ISOC) {
if (udccs & UDCCS_IO_ROF)
req->req.status = -EHOSTUNREACH;
is_short = 1;
}
if (is_short || req->req.actual == req->req.length) {
done (ep, req, 0);
if (list_empty(&ep->queue))
pio_irq_disable (ep->bEndpointAddress);
return 1;
}
}
return 0;
}
static int
read_ep0_fifo (struct pxa25x_ep *ep, struct pxa25x_request *req)
{
u8 *buf, byte;
unsigned bufferspace;
buf = req->req.buf + req->req.actual;
bufferspace = req->req.length - req->req.actual;
while (UDCCS0 & UDCCS0_RNE) {
byte = (u8) UDDR0;
if (unlikely (bufferspace == 0)) {
if (req->req.status != -EOVERFLOW)
DMSG("%s overflow\n", ep->ep.name);
req->req.status = -EOVERFLOW;
} else {
*buf++ = byte;
req->req.actual++;
bufferspace--;
}
}
UDCCS0 = UDCCS0_OPR | UDCCS0_IPR;
if (req->req.actual >= req->req.length)
return 1;
return 0;
}
static int
pxa25x_ep_queue(struct usb_ep *_ep, struct usb_request *_req, gfp_t gfp_flags)
{
struct pxa25x_request *req;
struct pxa25x_ep *ep;
struct pxa25x_udc *dev;
unsigned long flags;
req = container_of(_req, struct pxa25x_request, req);
if (unlikely (!_req || !_req->complete || !_req->buf
|| !list_empty(&req->queue))) {
DMSG("%s, bad params\n", __func__);
return -EINVAL;
}
ep = container_of(_ep, struct pxa25x_ep, ep);
if (unlikely(!_ep || (!ep->ep.desc && ep->ep.name != ep0name))) {
DMSG("%s, bad ep\n", __func__);
return -EINVAL;
}
dev = ep->dev;
if (unlikely (!dev->driver
|| dev->gadget.speed == USB_SPEED_UNKNOWN)) {
DMSG("%s, bogus device state\n", __func__);
return -ESHUTDOWN;
}
if (unlikely (ep->bmAttributes == USB_ENDPOINT_XFER_ISOC
&& req->req.length > usb_endpoint_maxp(ep->ep.desc)))
return -EMSGSIZE;
DBG(DBG_NOISY, "%s queue req %p, len %d buf %p\n",
_ep->name, _req, _req->length, _req->buf);
local_irq_save(flags);
_req->status = -EINPROGRESS;
_req->actual = 0;
if (list_empty(&ep->queue) && !ep->stopped) {
if (ep->ep.desc == NULL) {
unsigned length = _req->length;
switch (dev->ep0state) {
case EP0_IN_DATA_PHASE:
dev->stats.write.ops++;
if (write_ep0_fifo(ep, req))
req = NULL;
break;
case EP0_OUT_DATA_PHASE:
dev->stats.read.ops++;
if (dev->req_config) {
DBG(DBG_VERBOSE, "ep0 config ack%s\n",
dev->has_cfr ? "" : " raced");
if (dev->has_cfr)
UDCCFR = UDCCFR_AREN|UDCCFR_ACM
|UDCCFR_MB1;
done(ep, req, 0);
dev->ep0state = EP0_END_XFER;
local_irq_restore (flags);
return 0;
}
if (dev->req_pending)
ep0start(dev, UDCCS0_IPR, "OUT");
if (length == 0 || ((UDCCS0 & UDCCS0_RNE) != 0
&& read_ep0_fifo(ep, req))) {
ep0_idle(dev);
done(ep, req, 0);
req = NULL;
}
break;
default:
DMSG("ep0 i/o, odd state %d\n", dev->ep0state);
local_irq_restore (flags);
return -EL2HLT;
}
} else if ((ep->bEndpointAddress & USB_DIR_IN) != 0) {
if ((*ep->reg_udccs & UDCCS_BI_TFS) != 0
&& write_fifo(ep, req))
req = NULL;
} else if ((*ep->reg_udccs & UDCCS_BO_RFS) != 0
&& read_fifo(ep, req)) {
req = NULL;
}
if (likely(req && ep->ep.desc))
pio_irq_enable(ep->bEndpointAddress);
}
if (likely(req != NULL))
list_add_tail(&req->queue, &ep->queue);
local_irq_restore(flags);
return 0;
}
static void nuke(struct pxa25x_ep *ep, int status)
{
struct pxa25x_request *req;
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next,
struct pxa25x_request,
queue);
done(ep, req, status);
}
if (ep->ep.desc)
pio_irq_disable (ep->bEndpointAddress);
}
static int pxa25x_ep_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct pxa25x_ep *ep;
struct pxa25x_request *req;
unsigned long flags;
ep = container_of(_ep, struct pxa25x_ep, ep);
if (!_ep || ep->ep.name == ep0name)
return -EINVAL;
local_irq_save(flags);
list_for_each_entry (req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
local_irq_restore(flags);
return -EINVAL;
}
done(ep, req, -ECONNRESET);
local_irq_restore(flags);
return 0;
}
static int pxa25x_ep_set_halt(struct usb_ep *_ep, int value)
{
struct pxa25x_ep *ep;
unsigned long flags;
ep = container_of(_ep, struct pxa25x_ep, ep);
if (unlikely (!_ep
|| (!ep->ep.desc && ep->ep.name != ep0name))
|| ep->bmAttributes == USB_ENDPOINT_XFER_ISOC) {
DMSG("%s, bad ep\n", __func__);
return -EINVAL;
}
if (value == 0) {
DMSG("only host can clear %s halt\n", _ep->name);
return -EROFS;
}
local_irq_save(flags);
if ((ep->bEndpointAddress & USB_DIR_IN) != 0
&& ((*ep->reg_udccs & UDCCS_BI_TFS) == 0
|| !list_empty(&ep->queue))) {
local_irq_restore(flags);
return -EAGAIN;
}
*ep->reg_udccs = UDCCS_BI_FST|UDCCS_BI_FTF;
if (!ep->ep.desc) {
start_watchdog(ep->dev);
ep->dev->req_pending = 0;
ep->dev->ep0state = EP0_STALL;
} else {
unsigned i;
for (i = 0; i < 1000; i += 20) {
if (*ep->reg_udccs & UDCCS_BI_SST)
break;
udelay(20);
}
}
local_irq_restore(flags);
DBG(DBG_VERBOSE, "%s halt\n", _ep->name);
return 0;
}
static int pxa25x_ep_fifo_status(struct usb_ep *_ep)
{
struct pxa25x_ep *ep;
ep = container_of(_ep, struct pxa25x_ep, ep);
if (!_ep) {
DMSG("%s, bad ep\n", __func__);
return -ENODEV;
}
if ((ep->bEndpointAddress & USB_DIR_IN) != 0)
return -EOPNOTSUPP;
if (ep->dev->gadget.speed == USB_SPEED_UNKNOWN
|| (*ep->reg_udccs & UDCCS_BO_RFS) == 0)
return 0;
else
return (*ep->reg_ubcr & 0xfff) + 1;
}
static void pxa25x_ep_fifo_flush(struct usb_ep *_ep)
{
struct pxa25x_ep *ep;
ep = container_of(_ep, struct pxa25x_ep, ep);
if (!_ep || ep->ep.name == ep0name || !list_empty(&ep->queue)) {
DMSG("%s, bad ep\n", __func__);
return;
}
if ((ep->bEndpointAddress & USB_DIR_IN) == 0) {
while (((*ep->reg_udccs) & UDCCS_BO_RNE) != 0)
(void) *ep->reg_uddr;
return;
}
*ep->reg_udccs = UDCCS_BI_TPC|UDCCS_BI_FTF|UDCCS_BI_TUR
| (ep->bmAttributes == USB_ENDPOINT_XFER_ISOC
? 0 : UDCCS_BI_SST);
}
static int pxa25x_udc_get_frame(struct usb_gadget *_gadget)
{
return ((UFNRH & 0x07) << 8) | (UFNRL & 0xff);
}
static int pxa25x_udc_wakeup(struct usb_gadget *_gadget)
{
if ((UDCCS0 & UDCCS0_DRWF) == 0)
return -EHOSTUNREACH;
udc_set_mask_UDCCR(UDCCR_RSM);
return 0;
}
static int pullup(struct pxa25x_udc *udc)
{
int is_active = udc->vbus && udc->pullup && !udc->suspended;
DMSG("%s\n", is_active ? "active" : "inactive");
if (is_active) {
if (!udc->active) {
udc->active = 1;
clk_enable(udc->clk);
udc_enable(udc);
}
} else {
if (udc->active) {
if (udc->gadget.speed != USB_SPEED_UNKNOWN) {
DMSG("disconnect %s\n", udc->driver
? udc->driver->driver.name
: "(no driver)");
stop_activity(udc, udc->driver);
}
udc_disable(udc);
clk_disable(udc->clk);
udc->active = 0;
}
}
return 0;
}
static int pxa25x_udc_vbus_session(struct usb_gadget *_gadget, int is_active)
{
struct pxa25x_udc *udc;
udc = container_of(_gadget, struct pxa25x_udc, gadget);
udc->vbus = is_active;
DMSG("vbus %s\n", is_active ? "supplied" : "inactive");
pullup(udc);
return 0;
}
static int pxa25x_udc_pullup(struct usb_gadget *_gadget, int is_active)
{
struct pxa25x_udc *udc;
udc = container_of(_gadget, struct pxa25x_udc, gadget);
if (!gpio_is_valid(udc->mach->gpio_pullup) && !udc->mach->udc_command)
return -EOPNOTSUPP;
udc->pullup = (is_active != 0);
pullup(udc);
return 0;
}
static int pxa25x_udc_vbus_draw(struct usb_gadget *_gadget, unsigned mA)
{
struct pxa25x_udc *udc;
udc = container_of(_gadget, struct pxa25x_udc, gadget);
if (!IS_ERR_OR_NULL(udc->transceiver))
return usb_phy_set_power(udc->transceiver, mA);
return -EOPNOTSUPP;
}
static int
udc_seq_show(struct seq_file *m, void *_d)
{
struct pxa25x_udc *dev = m->private;
unsigned long flags;
int i;
u32 tmp;
local_irq_save(flags);
seq_printf(m, DRIVER_DESC "\n"
"%s version: %s\nGadget driver: %s\nHost %s\n\n",
driver_name, DRIVER_VERSION SIZE_STR "(pio)",
dev->driver ? dev->driver->driver.name : "(none)",
dev->gadget.speed == USB_SPEED_FULL ? "full speed" : "disconnected");
seq_printf(m,
"uicr %02X.%02X, usir %02X.%02x, ufnr %02X.%02X\n",
UICR1, UICR0, USIR1, USIR0, UFNRH, UFNRL);
tmp = UDCCR;
seq_printf(m,
"udccr %02X =%s%s%s%s%s%s%s%s\n", tmp,
(tmp & UDCCR_REM) ? " rem" : "",
(tmp & UDCCR_RSTIR) ? " rstir" : "",
(tmp & UDCCR_SRM) ? " srm" : "",
(tmp & UDCCR_SUSIR) ? " susir" : "",
(tmp & UDCCR_RESIR) ? " resir" : "",
(tmp & UDCCR_RSM) ? " rsm" : "",
(tmp & UDCCR_UDA) ? " uda" : "",
(tmp & UDCCR_UDE) ? " ude" : "");
tmp = UDCCS0;
seq_printf(m,
"udccs0 %02X =%s%s%s%s%s%s%s%s\n", tmp,
(tmp & UDCCS0_SA) ? " sa" : "",
(tmp & UDCCS0_RNE) ? " rne" : "",
(tmp & UDCCS0_FST) ? " fst" : "",
(tmp & UDCCS0_SST) ? " sst" : "",
(tmp & UDCCS0_DRWF) ? " dwrf" : "",
(tmp & UDCCS0_FTF) ? " ftf" : "",
(tmp & UDCCS0_IPR) ? " ipr" : "",
(tmp & UDCCS0_OPR) ? " opr" : "");
if (dev->has_cfr) {
tmp = UDCCFR;
seq_printf(m,
"udccfr %02X =%s%s\n", tmp,
(tmp & UDCCFR_AREN) ? " aren" : "",
(tmp & UDCCFR_ACM) ? " acm" : "");
}
if (dev->gadget.speed != USB_SPEED_FULL || !dev->driver)
goto done;
seq_printf(m, "ep0 IN %lu/%lu, OUT %lu/%lu\nirqs %lu\n\n",
dev->stats.write.bytes, dev->stats.write.ops,
dev->stats.read.bytes, dev->stats.read.ops,
dev->stats.irqs);
for (i = 0; i < PXA_UDC_NUM_ENDPOINTS; i++) {
struct pxa25x_ep *ep = &dev->ep [i];
struct pxa25x_request *req;
if (i != 0) {
const struct usb_endpoint_descriptor *desc;
desc = ep->ep.desc;
if (!desc)
continue;
tmp = *dev->ep [i].reg_udccs;
seq_printf(m,
"%s max %d %s udccs %02x irqs %lu\n",
ep->ep.name, usb_endpoint_maxp(desc),
"pio", tmp, ep->pio_irqs);
} else
seq_printf(m, "ep0 max 16 pio irqs %lu\n",
ep->pio_irqs);
if (list_empty(&ep->queue)) {
seq_printf(m, "\t(nothing queued)\n");
continue;
}
list_for_each_entry(req, &ep->queue, queue) {
seq_printf(m,
"\treq %p len %d/%d buf %p\n",
&req->req, req->req.actual,
req->req.length, req->req.buf);
}
}
done:
local_irq_restore(flags);
return 0;
}
static int
udc_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, udc_seq_show, inode->i_private);
}
static void udc_disable(struct pxa25x_udc *dev)
{
udc_set_mask_UDCCR(UDCCR_SRM|UDCCR_REM);
UICR0 = UICR1 = 0xff;
UFNRH = UFNRH_SIM;
pullup_off();
udc_clear_mask_UDCCR(UDCCR_UDE);
ep0_idle (dev);
dev->gadget.speed = USB_SPEED_UNKNOWN;
}
static void udc_reinit(struct pxa25x_udc *dev)
{
u32 i;
INIT_LIST_HEAD (&dev->gadget.ep_list);
INIT_LIST_HEAD (&dev->gadget.ep0->ep_list);
dev->ep0state = EP0_IDLE;
for (i = 0; i < PXA_UDC_NUM_ENDPOINTS; i++) {
struct pxa25x_ep *ep = &dev->ep[i];
if (i != 0)
list_add_tail (&ep->ep.ep_list, &dev->gadget.ep_list);
ep->ep.desc = NULL;
ep->stopped = 0;
INIT_LIST_HEAD (&ep->queue);
ep->pio_irqs = 0;
usb_ep_set_maxpacket_limit(&ep->ep, ep->ep.maxpacket);
}
}
static void udc_enable (struct pxa25x_udc *dev)
{
udc_clear_mask_UDCCR(UDCCR_UDE);
udc_ack_int_UDCCR(UDCCR_SUSIR|UDCCR_RESIR);
ep0_idle(dev);
dev->gadget.speed = USB_SPEED_UNKNOWN;
dev->stats.irqs = 0;
udc_set_mask_UDCCR(UDCCR_UDE);
if (!(UDCCR & UDCCR_UDA))
udc_ack_int_UDCCR(UDCCR_RSTIR);
if (dev->has_cfr ) {
UDCCFR = UDCCFR_ACM | UDCCFR_MB1;
} else {
UDC_RES1 = 0x00;
UDC_RES2 = 0x00;
}
udc_clear_mask_UDCCR(UDCCR_SRM | UDCCR_REM);
UICR0 &= ~UICR0_IM0;
pullup_on();
}
static int pxa25x_udc_start(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct pxa25x_udc *dev = to_pxa25x(g);
int retval;
dev->driver = driver;
dev->pullup = 1;
if (!IS_ERR_OR_NULL(dev->transceiver)) {
retval = otg_set_peripheral(dev->transceiver->otg,
&dev->gadget);
if (retval)
goto bind_fail;
}
pullup(dev);
dump_state(dev);
return 0;
bind_fail:
return retval;
}
static void
stop_activity(struct pxa25x_udc *dev, struct usb_gadget_driver *driver)
{
int i;
if (dev->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
dev->gadget.speed = USB_SPEED_UNKNOWN;
for (i = 0; i < PXA_UDC_NUM_ENDPOINTS; i++) {
struct pxa25x_ep *ep = &dev->ep[i];
ep->stopped = 1;
nuke(ep, -ESHUTDOWN);
}
del_timer_sync(&dev->timer);
if (driver)
driver->disconnect(&dev->gadget);
udc_reinit(dev);
}
static int pxa25x_udc_stop(struct usb_gadget*g,
struct usb_gadget_driver *driver)
{
struct pxa25x_udc *dev = to_pxa25x(g);
local_irq_disable();
dev->pullup = 0;
pullup(dev);
stop_activity(dev, driver);
local_irq_enable();
if (!IS_ERR_OR_NULL(dev->transceiver))
(void) otg_set_peripheral(dev->transceiver->otg, NULL);
dev->driver = NULL;
dump_state(dev);
return 0;
}
static irqreturn_t
lubbock_vbus_irq(int irq, void *_dev)
{
struct pxa25x_udc *dev = _dev;
int vbus;
dev->stats.irqs++;
switch (irq) {
case LUBBOCK_USB_IRQ:
vbus = 1;
disable_irq(LUBBOCK_USB_IRQ);
enable_irq(LUBBOCK_USB_DISC_IRQ);
break;
case LUBBOCK_USB_DISC_IRQ:
vbus = 0;
disable_irq(LUBBOCK_USB_DISC_IRQ);
enable_irq(LUBBOCK_USB_IRQ);
break;
default:
return IRQ_NONE;
}
pxa25x_udc_vbus_session(&dev->gadget, vbus);
return IRQ_HANDLED;
}
static inline void clear_ep_state (struct pxa25x_udc *dev)
{
unsigned i;
for (i = 1; i < PXA_UDC_NUM_ENDPOINTS; i++)
nuke(&dev->ep[i], -ECONNABORTED);
}
static void udc_watchdog(unsigned long _dev)
{
struct pxa25x_udc *dev = (void *)_dev;
local_irq_disable();
if (dev->ep0state == EP0_STALL
&& (UDCCS0 & UDCCS0_FST) == 0
&& (UDCCS0 & UDCCS0_SST) == 0) {
UDCCS0 = UDCCS0_FST|UDCCS0_FTF;
DBG(DBG_VERBOSE, "ep0 re-stall\n");
start_watchdog(dev);
}
local_irq_enable();
}
static void handle_ep0 (struct pxa25x_udc *dev)
{
u32 udccs0 = UDCCS0;
struct pxa25x_ep *ep = &dev->ep [0];
struct pxa25x_request *req;
union {
struct usb_ctrlrequest r;
u8 raw [8];
u32 word [2];
} u;
if (list_empty(&ep->queue))
req = NULL;
else
req = list_entry(ep->queue.next, struct pxa25x_request, queue);
if (udccs0 & UDCCS0_SST) {
nuke(ep, -EPIPE);
UDCCS0 = UDCCS0_SST;
del_timer(&dev->timer);
ep0_idle(dev);
}
if ((udccs0 & UDCCS0_SA) != 0 && dev->ep0state != EP0_IDLE) {
nuke(ep, 0);
del_timer(&dev->timer);
ep0_idle(dev);
}
switch (dev->ep0state) {
case EP0_IDLE:
udccs0 = UDCCS0;
if (likely((udccs0 & (UDCCS0_OPR|UDCCS0_SA|UDCCS0_RNE))
== (UDCCS0_OPR|UDCCS0_SA|UDCCS0_RNE))) {
int i;
nuke (ep, -EPROTO);
for (i = 0; i < 8; i++) {
if (unlikely(!(UDCCS0 & UDCCS0_RNE))) {
bad_setup:
DMSG("SETUP %d!\n", i);
goto stall;
}
u.raw [i] = (u8) UDDR0;
}
if (unlikely((UDCCS0 & UDCCS0_RNE) != 0))
goto bad_setup;
got_setup:
DBG(DBG_VERBOSE, "SETUP %02x.%02x v%04x i%04x l%04x\n",
u.r.bRequestType, u.r.bRequest,
le16_to_cpu(u.r.wValue),
le16_to_cpu(u.r.wIndex),
le16_to_cpu(u.r.wLength));
dev->req_std = (u.r.bRequestType & USB_TYPE_MASK)
== USB_TYPE_STANDARD;
dev->req_config = 0;
dev->req_pending = 1;
switch (u.r.bRequest) {
case USB_REQ_SET_CONFIGURATION:
if (u.r.bRequestType == USB_RECIP_DEVICE) {
config_change:
dev->req_config = 1;
clear_ep_state(dev);
}
break;
case USB_REQ_SET_INTERFACE:
if (u.r.bRequestType == USB_RECIP_INTERFACE) {
DMSG("broken set_interface (%d/%d)\n",
le16_to_cpu(u.r.wIndex),
le16_to_cpu(u.r.wValue));
goto config_change;
}
break;
case USB_REQ_SET_ADDRESS:
if (u.r.bRequestType == USB_RECIP_DEVICE) {
ep0start(dev, 0, "address");
return;
}
break;
}
if (u.r.bRequestType & USB_DIR_IN)
dev->ep0state = EP0_IN_DATA_PHASE;
else
dev->ep0state = EP0_OUT_DATA_PHASE;
i = dev->driver->setup(&dev->gadget, &u.r);
if (i < 0) {
if (dev->req_config) {
WARNING("config change %02x fail %d?\n",
u.r.bRequest, i);
return;
}
DBG(DBG_VERBOSE, "protocol STALL, "
"%02x err %d\n", UDCCS0, i);
stall:
ep0start(dev, UDCCS0_FST|UDCCS0_FTF, "stall");
start_watchdog(dev);
dev->ep0state = EP0_STALL;
} else if (dev->req_pending) {
if (likely(dev->ep0state == EP0_IN_DATA_PHASE
|| dev->req_std || u.r.wLength))
ep0start(dev, 0, "defer");
else
ep0start(dev, UDCCS0_IPR, "defer/IPR");
}
return;
} else if (likely((udccs0 & (UDCCS0_OPR|UDCCS0_SA))
== (UDCCS0_OPR|UDCCS0_SA))) {
unsigned i;
DBG(DBG_VERBOSE, "e131\n");
nuke(ep, -EPROTO);
for (i = 0; i < 8; i++)
u.raw [i] = (u8) UDDR0;
if ((u.r.bRequestType & USB_RECIP_MASK)
> USB_RECIP_OTHER)
goto stall;
if (u.word [0] == 0 && u.word [1] == 0)
goto stall;
goto got_setup;
} else {
UDCCS0 = udccs0 & (UDCCS0_SA|UDCCS0_OPR);
}
break;
case EP0_IN_DATA_PHASE:
if (udccs0 & UDCCS0_OPR) {
UDCCS0 = UDCCS0_OPR|UDCCS0_FTF;
DBG(DBG_VERBOSE, "ep0in premature status\n");
if (req)
done(ep, req, 0);
ep0_idle(dev);
} else {
if (req) {
(void) write_ep0_fifo(ep, req);
}
}
break;
case EP0_OUT_DATA_PHASE:
if (udccs0 & UDCCS0_OPR) {
if (req) {
if (read_ep0_fifo(ep, req))
done(ep, req, 0);
}
} else {
DBG(DBG_VERBOSE, "ep0out premature status\n");
if (req)
done(ep, req, 0);
ep0_idle(dev);
}
break;
case EP0_END_XFER:
if (req)
done(ep, req, 0);
if (udccs0 & UDCCS0_OPR)
UDCCS0 = UDCCS0_OPR;
ep0_idle(dev);
break;
case EP0_STALL:
UDCCS0 = UDCCS0_FST;
break;
}
USIR0 = USIR0_IR0;
}
static void handle_ep(struct pxa25x_ep *ep)
{
struct pxa25x_request *req;
int is_in = ep->bEndpointAddress & USB_DIR_IN;
int completed;
u32 udccs, tmp;
do {
completed = 0;
if (likely (!list_empty(&ep->queue)))
req = list_entry(ep->queue.next,
struct pxa25x_request, queue);
else
req = NULL;
udccs = *ep->reg_udccs;
if (unlikely(is_in)) {
tmp = UDCCS_BI_TUR;
if (likely(ep->bmAttributes == USB_ENDPOINT_XFER_BULK))
tmp |= UDCCS_BI_SST;
tmp &= udccs;
if (likely (tmp))
*ep->reg_udccs = tmp;
if (req && likely ((udccs & UDCCS_BI_TFS) != 0))
completed = write_fifo(ep, req);
} else {
if (likely(ep->bmAttributes == USB_ENDPOINT_XFER_BULK))
tmp = UDCCS_BO_SST | UDCCS_BO_DME;
else
tmp = UDCCS_IO_ROF | UDCCS_IO_DME;
tmp &= udccs;
if (likely(tmp))
*ep->reg_udccs = tmp;
if (likely(req)) {
completed = read_fifo(ep, req);
} else
pio_irq_disable (ep->bEndpointAddress);
}
ep->pio_irqs++;
} while (completed);
}
static irqreturn_t
pxa25x_udc_irq(int irq, void *_dev)
{
struct pxa25x_udc *dev = _dev;
int handled;
dev->stats.irqs++;
do {
u32 udccr = UDCCR;
handled = 0;
if (unlikely(udccr & UDCCR_SUSIR)) {
udc_ack_int_UDCCR(UDCCR_SUSIR);
handled = 1;
DBG(DBG_VERBOSE, "USB suspend\n");
if (dev->gadget.speed != USB_SPEED_UNKNOWN
&& dev->driver
&& dev->driver->suspend)
dev->driver->suspend(&dev->gadget);
ep0_idle (dev);
}
if (unlikely(udccr & UDCCR_RESIR)) {
udc_ack_int_UDCCR(UDCCR_RESIR);
handled = 1;
DBG(DBG_VERBOSE, "USB resume\n");
if (dev->gadget.speed != USB_SPEED_UNKNOWN
&& dev->driver
&& dev->driver->resume)
dev->driver->resume(&dev->gadget);
}
if (unlikely(udccr & UDCCR_RSTIR)) {
udc_ack_int_UDCCR(UDCCR_RSTIR);
handled = 1;
if ((UDCCR & UDCCR_UDA) == 0) {
DBG(DBG_VERBOSE, "USB reset start\n");
stop_activity (dev, dev->driver);
} else {
DBG(DBG_VERBOSE, "USB reset end\n");
dev->gadget.speed = USB_SPEED_FULL;
memset(&dev->stats, 0, sizeof dev->stats);
}
} else {
u32 usir0 = USIR0 & ~UICR0;
u32 usir1 = USIR1 & ~UICR1;
int i;
if (unlikely (!usir0 && !usir1))
continue;
DBG(DBG_VERY_NOISY, "irq %02x.%02x\n", usir1, usir0);
if (usir0 & USIR0_IR0) {
dev->ep[0].pio_irqs++;
handle_ep0(dev);
handled = 1;
}
for (i = 0; i < 8; i++) {
u32 tmp = 1 << i;
if (i && (usir0 & tmp)) {
handle_ep(&dev->ep[i]);
USIR0 |= tmp;
handled = 1;
}
#ifndef CONFIG_USB_PXA25X_SMALL
if (usir1 & tmp) {
handle_ep(&dev->ep[i+8]);
USIR1 |= tmp;
handled = 1;
}
#endif
}
}
} while (handled);
return IRQ_HANDLED;
}
static void nop_release (struct device *dev)
{
DMSG("%s %s\n", __func__, dev_name(dev));
}
static int pxa25x_udc_probe(struct platform_device *pdev)
{
struct pxa25x_udc *dev = &memory;
int retval, irq;
u32 chiprev;
pr_info("%s: version %s\n", driver_name, DRIVER_VERSION);
asm("mrc%? p15, 0, %0, c0, c0" : "=r" (chiprev));
if ((chiprev & CP15R0_VENDOR_MASK) != CP15R0_XSCALE_VALUE) {
pr_err("%s: not XScale!\n", driver_name);
return -ENODEV;
}
switch (chiprev & CP15R0_PRODREV_MASK) {
#if defined(CONFIG_ARCH_PXA)
case PXA255_A0:
dev->has_cfr = 1;
break;
case PXA250_A0:
case PXA250_A1:
case PXA250_B2: case PXA210_B2:
case PXA250_B1: case PXA210_B1:
case PXA250_B0: case PXA210_B0:
case PXA250_C0: case PXA210_C0:
break;
#elif defined(CONFIG_ARCH_IXP4XX)
case IXP425_A0:
case IXP425_B0:
case IXP465_AD:
dev->has_cfr = 1;
break;
#endif
default:
pr_err("%s: unrecognized processor: %08x\n",
driver_name, chiprev);
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENODEV;
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk)) {
retval = PTR_ERR(dev->clk);
goto err_clk;
}
pr_debug("%s: IRQ %d%s%s\n", driver_name, irq,
dev->has_cfr ? "" : " (!cfr)",
SIZE_STR "(pio)"
);
dev->dev = &pdev->dev;
dev->mach = dev_get_platdata(&pdev->dev);
dev->transceiver = usb_get_phy(USB_PHY_TYPE_USB2);
if (gpio_is_valid(dev->mach->gpio_pullup)) {
if ((retval = gpio_request(dev->mach->gpio_pullup,
"pca25x_udc GPIO PULLUP"))) {
dev_dbg(&pdev->dev,
"can't get pullup gpio %d, err: %d\n",
dev->mach->gpio_pullup, retval);
goto err_gpio_pullup;
}
gpio_direction_output(dev->mach->gpio_pullup, 0);
}
init_timer(&dev->timer);
dev->timer.function = udc_watchdog;
dev->timer.data = (unsigned long) dev;
the_controller = dev;
platform_set_drvdata(pdev, dev);
udc_disable(dev);
udc_reinit(dev);
dev->vbus = 0;
retval = request_irq(irq, pxa25x_udc_irq,
0, driver_name, dev);
if (retval != 0) {
pr_err("%s: can't get irq %d, err %d\n",
driver_name, irq, retval);
goto err_irq1;
}
dev->got_irq = 1;
#ifdef CONFIG_ARCH_LUBBOCK
if (machine_is_lubbock()) {
retval = request_irq(LUBBOCK_USB_DISC_IRQ, lubbock_vbus_irq,
0, driver_name, dev);
if (retval != 0) {
pr_err("%s: can't get irq %i, err %d\n",
driver_name, LUBBOCK_USB_DISC_IRQ, retval);
goto err_irq_lub;
}
retval = request_irq(LUBBOCK_USB_IRQ, lubbock_vbus_irq,
0, driver_name, dev);
if (retval != 0) {
pr_err("%s: can't get irq %i, err %d\n",
driver_name, LUBBOCK_USB_IRQ, retval);
goto lubbock_fail0;
}
} else
#endif
create_debug_files(dev);
retval = usb_add_gadget_udc(&pdev->dev, &dev->gadget);
if (!retval)
return retval;
remove_debug_files(dev);
#ifdef CONFIG_ARCH_LUBBOCK
lubbock_fail0:
free_irq(LUBBOCK_USB_DISC_IRQ, dev);
err_irq_lub:
free_irq(irq, dev);
#endif
err_irq1:
if (gpio_is_valid(dev->mach->gpio_pullup))
gpio_free(dev->mach->gpio_pullup);
err_gpio_pullup:
if (!IS_ERR_OR_NULL(dev->transceiver)) {
usb_put_phy(dev->transceiver);
dev->transceiver = NULL;
}
clk_put(dev->clk);
err_clk:
return retval;
}
static void pxa25x_udc_shutdown(struct platform_device *_dev)
{
pullup_off();
}
static int pxa25x_udc_remove(struct platform_device *pdev)
{
struct pxa25x_udc *dev = platform_get_drvdata(pdev);
if (dev->driver)
return -EBUSY;
usb_del_gadget_udc(&dev->gadget);
dev->pullup = 0;
pullup(dev);
remove_debug_files(dev);
if (dev->got_irq) {
free_irq(platform_get_irq(pdev, 0), dev);
dev->got_irq = 0;
}
#ifdef CONFIG_ARCH_LUBBOCK
if (machine_is_lubbock()) {
free_irq(LUBBOCK_USB_DISC_IRQ, dev);
free_irq(LUBBOCK_USB_IRQ, dev);
}
#endif
if (gpio_is_valid(dev->mach->gpio_pullup))
gpio_free(dev->mach->gpio_pullup);
clk_put(dev->clk);
if (!IS_ERR_OR_NULL(dev->transceiver)) {
usb_put_phy(dev->transceiver);
dev->transceiver = NULL;
}
the_controller = NULL;
return 0;
}
static int pxa25x_udc_suspend(struct platform_device *dev, pm_message_t state)
{
struct pxa25x_udc *udc = platform_get_drvdata(dev);
unsigned long flags;
if (!gpio_is_valid(udc->mach->gpio_pullup) && !udc->mach->udc_command)
WARNING("USB host won't detect disconnect!\n");
udc->suspended = 1;
local_irq_save(flags);
pullup(udc);
local_irq_restore(flags);
return 0;
}
static int pxa25x_udc_resume(struct platform_device *dev)
{
struct pxa25x_udc *udc = platform_get_drvdata(dev);
unsigned long flags;
udc->suspended = 0;
local_irq_save(flags);
pullup(udc);
local_irq_restore(flags);
return 0;
}
