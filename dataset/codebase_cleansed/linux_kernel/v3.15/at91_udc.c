static void proc_ep_show(struct seq_file *s, struct at91_ep *ep)
{
static char *types[] = {
"control", "out-iso", "out-bulk", "out-int",
"BOGUS", "in-iso", "in-bulk", "in-int"};
u32 csr;
struct at91_request *req;
unsigned long flags;
struct at91_udc *udc = ep->udc;
spin_lock_irqsave(&udc->lock, flags);
csr = __raw_readl(ep->creg);
seq_printf(s, "\n");
seq_printf(s, "%s, maxpacket %d %s%s %s%s\n",
ep->ep.name, ep->ep.maxpacket,
ep->is_in ? "in" : "out",
ep->is_iso ? " iso" : "",
ep->is_pingpong
? (ep->fifo_bank ? "pong" : "ping")
: "",
ep->stopped ? " stopped" : "");
seq_printf(s, "csr %08x rxbytes=%d %s %s %s" EIGHTBITS "\n",
csr,
(csr & 0x07ff0000) >> 16,
(csr & (1 << 15)) ? "enabled" : "disabled",
(csr & (1 << 11)) ? "DATA1" : "DATA0",
types[(csr & 0x700) >> 8],
(!(csr & 0x700))
? ((csr & (1 << 7)) ? " IN" : " OUT")
: "",
(csr & (1 << 6)) ? " rxdatabk1" : "",
(csr & (1 << 5)) ? " forcestall" : "",
(csr & (1 << 4)) ? " txpktrdy" : "",
(csr & (1 << 3)) ? " stallsent" : "",
(csr & (1 << 2)) ? " rxsetup" : "",
(csr & (1 << 1)) ? " rxdatabk0" : "",
(csr & (1 << 0)) ? " txcomp" : "");
if (list_empty (&ep->queue))
seq_printf(s, "\t(queue empty)\n");
else list_for_each_entry (req, &ep->queue, queue) {
unsigned length = req->req.actual;
seq_printf(s, "\treq %p len %d/%d buf %p\n",
&req->req, length,
req->req.length, req->req.buf);
}
spin_unlock_irqrestore(&udc->lock, flags);
}
static void proc_irq_show(struct seq_file *s, const char *label, u32 mask)
{
int i;
seq_printf(s, "%s %04x:%s%s" FOURBITS, label, mask,
(mask & (1 << 13)) ? " wakeup" : "",
(mask & (1 << 12)) ? " endbusres" : "",
(mask & (1 << 11)) ? " sofint" : "",
(mask & (1 << 10)) ? " extrsm" : "",
(mask & (1 << 9)) ? " rxrsm" : "",
(mask & (1 << 8)) ? " rxsusp" : "");
for (i = 0; i < 8; i++) {
if (mask & (1 << i))
seq_printf(s, " ep%d", i);
}
seq_printf(s, "\n");
}
static int proc_udc_show(struct seq_file *s, void *unused)
{
struct at91_udc *udc = s->private;
struct at91_ep *ep;
u32 tmp;
seq_printf(s, "%s: version %s\n", driver_name, DRIVER_VERSION);
seq_printf(s, "vbus %s, pullup %s, %s powered%s, gadget %s\n\n",
udc->vbus ? "present" : "off",
udc->enabled
? (udc->vbus ? "active" : "enabled")
: "disabled",
udc->selfpowered ? "self" : "VBUS",
udc->suspended ? ", suspended" : "",
udc->driver ? udc->driver->driver.name : "(none)");
if (!udc->clocked) {
seq_printf(s, "(not clocked)\n");
return 0;
}
tmp = at91_udp_read(udc, AT91_UDP_FRM_NUM);
seq_printf(s, "frame %05x:%s%s frame=%d\n", tmp,
(tmp & AT91_UDP_FRM_OK) ? " ok" : "",
(tmp & AT91_UDP_FRM_ERR) ? " err" : "",
(tmp & AT91_UDP_NUM));
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT);
seq_printf(s, "glbstate %02x:%s" FOURBITS "\n", tmp,
(tmp & AT91_UDP_RMWUPE) ? " rmwupe" : "",
(tmp & AT91_UDP_RSMINPR) ? " rsminpr" : "",
(tmp & AT91_UDP_ESR) ? " esr" : "",
(tmp & AT91_UDP_CONFG) ? " confg" : "",
(tmp & AT91_UDP_FADDEN) ? " fadden" : "");
tmp = at91_udp_read(udc, AT91_UDP_FADDR);
seq_printf(s, "faddr %03x:%s fadd=%d\n", tmp,
(tmp & AT91_UDP_FEN) ? " fen" : "",
(tmp & AT91_UDP_FADD));
proc_irq_show(s, "imr ", at91_udp_read(udc, AT91_UDP_IMR));
proc_irq_show(s, "isr ", at91_udp_read(udc, AT91_UDP_ISR));
if (udc->enabled && udc->vbus) {
proc_ep_show(s, &udc->ep[0]);
list_for_each_entry (ep, &udc->gadget.ep_list, ep.ep_list) {
if (ep->ep.desc)
proc_ep_show(s, ep);
}
}
return 0;
}
static int proc_udc_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_udc_show, PDE_DATA(inode));
}
static void create_debug_file(struct at91_udc *udc)
{
udc->pde = proc_create_data(debug_filename, 0, NULL, &proc_ops, udc);
}
static void remove_debug_file(struct at91_udc *udc)
{
if (udc->pde)
remove_proc_entry(debug_filename, NULL);
}
static inline void create_debug_file(struct at91_udc *udc) {}
static inline void remove_debug_file(struct at91_udc *udc) {}
static void done(struct at91_ep *ep, struct at91_request *req, int status)
{
unsigned stopped = ep->stopped;
struct at91_udc *udc = ep->udc;
list_del_init(&req->queue);
if (req->req.status == -EINPROGRESS)
req->req.status = status;
else
status = req->req.status;
if (status && status != -ESHUTDOWN)
VDBG("%s done %p, status %d\n", ep->ep.name, req, status);
ep->stopped = 1;
spin_unlock(&udc->lock);
req->req.complete(&ep->ep, &req->req);
spin_lock(&udc->lock);
ep->stopped = stopped;
if (list_empty(&ep->queue) && ep->int_mask != (1 << 0))
at91_udp_write(udc, AT91_UDP_IDR, ep->int_mask);
}
static int read_fifo (struct at91_ep *ep, struct at91_request *req)
{
u32 __iomem *creg = ep->creg;
u8 __iomem *dreg = ep->creg + (AT91_UDP_FDR(0) - AT91_UDP_CSR(0));
u32 csr;
u8 *buf;
unsigned int count, bufferspace, is_done;
buf = req->req.buf + req->req.actual;
bufferspace = req->req.length - req->req.actual;
rescan:
csr = __raw_readl(creg);
if ((csr & RX_DATA_READY) == 0)
return 0;
count = (csr & AT91_UDP_RXBYTECNT) >> 16;
if (count > ep->ep.maxpacket)
count = ep->ep.maxpacket;
if (count > bufferspace) {
DBG("%s buffer overflow\n", ep->ep.name);
req->req.status = -EOVERFLOW;
count = bufferspace;
}
__raw_readsb(dreg, buf, count);
csr |= CLR_FX;
if (ep->is_pingpong) {
if (ep->fifo_bank == 0) {
csr &= ~(SET_FX | AT91_UDP_RX_DATA_BK0);
ep->fifo_bank = 1;
} else {
csr &= ~(SET_FX | AT91_UDP_RX_DATA_BK1);
ep->fifo_bank = 0;
}
} else
csr &= ~(SET_FX | AT91_UDP_RX_DATA_BK0);
__raw_writel(csr, creg);
req->req.actual += count;
is_done = (count < ep->ep.maxpacket);
if (count == bufferspace)
is_done = 1;
PACKET("%s %p out/%d%s\n", ep->ep.name, &req->req, count,
is_done ? " (done)" : "");
if (is_done)
done(ep, req, 0);
else if (ep->is_pingpong) {
csr = __raw_readl(creg);
bufferspace -= count;
buf += count;
goto rescan;
}
return is_done;
}
static int write_fifo(struct at91_ep *ep, struct at91_request *req)
{
u32 __iomem *creg = ep->creg;
u32 csr = __raw_readl(creg);
u8 __iomem *dreg = ep->creg + (AT91_UDP_FDR(0) - AT91_UDP_CSR(0));
unsigned total, count, is_last;
u8 *buf;
if (unlikely(csr & (AT91_UDP_TXCOMP | AT91_UDP_TXPKTRDY))) {
if (csr & AT91_UDP_TXCOMP) {
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_TXCOMP);
__raw_writel(csr, creg);
csr = __raw_readl(creg);
}
if (csr & AT91_UDP_TXPKTRDY)
return 0;
}
buf = req->req.buf + req->req.actual;
prefetch(buf);
total = req->req.length - req->req.actual;
if (ep->ep.maxpacket < total) {
count = ep->ep.maxpacket;
is_last = 0;
} else {
count = total;
is_last = (count < ep->ep.maxpacket) || !req->req.zero;
}
__raw_writesb(dreg, buf, count);
csr &= ~SET_FX;
csr |= CLR_FX | AT91_UDP_TXPKTRDY;
__raw_writel(csr, creg);
req->req.actual += count;
PACKET("%s %p in/%d%s\n", ep->ep.name, &req->req, count,
is_last ? " (done)" : "");
if (is_last)
done(ep, req, 0);
return is_last;
}
static void nuke(struct at91_ep *ep, int status)
{
struct at91_request *req;
ep->stopped = 1;
if (list_empty(&ep->queue))
return;
VDBG("%s %s\n", __func__, ep->ep.name);
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct at91_request, queue);
done(ep, req, status);
}
}
static int at91_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct at91_ep *ep = container_of(_ep, struct at91_ep, ep);
struct at91_udc *udc;
u16 maxpacket;
u32 tmp;
unsigned long flags;
if (!_ep || !ep
|| !desc || _ep->name == ep0name
|| desc->bDescriptorType != USB_DT_ENDPOINT
|| (maxpacket = usb_endpoint_maxp(desc)) == 0
|| maxpacket > ep->maxpacket) {
DBG("bad ep or descriptor\n");
return -EINVAL;
}
udc = ep->udc;
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN) {
DBG("bogus device state\n");
return -ESHUTDOWN;
}
tmp = usb_endpoint_type(desc);
switch (tmp) {
case USB_ENDPOINT_XFER_CONTROL:
DBG("only one control endpoint\n");
return -EINVAL;
case USB_ENDPOINT_XFER_INT:
if (maxpacket > 64)
goto bogus_max;
break;
case USB_ENDPOINT_XFER_BULK:
switch (maxpacket) {
case 8:
case 16:
case 32:
case 64:
goto ok;
}
bogus_max:
DBG("bogus maxpacket %d\n", maxpacket);
return -EINVAL;
case USB_ENDPOINT_XFER_ISOC:
if (!ep->is_pingpong) {
DBG("iso requires double buffering\n");
return -EINVAL;
}
break;
}
ok:
spin_lock_irqsave(&udc->lock, flags);
ep->is_in = usb_endpoint_dir_in(desc);
ep->is_iso = (tmp == USB_ENDPOINT_XFER_ISOC);
ep->stopped = 0;
if (ep->is_in)
tmp |= 0x04;
tmp <<= 8;
tmp |= AT91_UDP_EPEDS;
__raw_writel(tmp, ep->creg);
ep->ep.maxpacket = maxpacket;
at91_udp_write(udc, AT91_UDP_RST_EP, ep->int_mask);
at91_udp_write(udc, AT91_UDP_RST_EP, 0);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int at91_ep_disable (struct usb_ep * _ep)
{
struct at91_ep *ep = container_of(_ep, struct at91_ep, ep);
struct at91_udc *udc = ep->udc;
unsigned long flags;
if (ep == &ep->udc->ep[0])
return -EINVAL;
spin_lock_irqsave(&udc->lock, flags);
nuke(ep, -ESHUTDOWN);
ep->ep.desc = NULL;
ep->ep.maxpacket = ep->maxpacket;
if (ep->udc->clocked) {
at91_udp_write(udc, AT91_UDP_RST_EP, ep->int_mask);
at91_udp_write(udc, AT91_UDP_RST_EP, 0);
__raw_writel(0, ep->creg);
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static struct usb_request *
at91_ep_alloc_request(struct usb_ep *_ep, gfp_t gfp_flags)
{
struct at91_request *req;
req = kzalloc(sizeof (struct at91_request), gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD(&req->queue);
return &req->req;
}
static void at91_ep_free_request(struct usb_ep *_ep, struct usb_request *_req)
{
struct at91_request *req;
req = container_of(_req, struct at91_request, req);
BUG_ON(!list_empty(&req->queue));
kfree(req);
}
static int at91_ep_queue(struct usb_ep *_ep,
struct usb_request *_req, gfp_t gfp_flags)
{
struct at91_request *req;
struct at91_ep *ep;
struct at91_udc *udc;
int status;
unsigned long flags;
req = container_of(_req, struct at91_request, req);
ep = container_of(_ep, struct at91_ep, ep);
if (!_req || !_req->complete
|| !_req->buf || !list_empty(&req->queue)) {
DBG("invalid request\n");
return -EINVAL;
}
if (!_ep || (!ep->ep.desc && ep->ep.name != ep0name)) {
DBG("invalid ep\n");
return -EINVAL;
}
udc = ep->udc;
if (!udc || !udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN) {
DBG("invalid device\n");
return -EINVAL;
}
_req->status = -EINPROGRESS;
_req->actual = 0;
spin_lock_irqsave(&udc->lock, flags);
if (list_empty(&ep->queue) && !ep->stopped) {
int is_ep0;
is_ep0 = (ep->ep.name == ep0name);
if (is_ep0) {
u32 tmp;
if (!udc->req_pending) {
status = -EINVAL;
goto done;
}
if (udc->wait_for_config_ack) {
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT);
tmp ^= AT91_UDP_CONFG;
VDBG("toggle config\n");
at91_udp_write(udc, AT91_UDP_GLB_STAT, tmp);
}
if (req->req.length == 0) {
ep0_in_status:
PACKET("ep0 in/status\n");
status = 0;
tmp = __raw_readl(ep->creg);
tmp &= ~SET_FX;
tmp |= CLR_FX | AT91_UDP_TXPKTRDY;
__raw_writel(tmp, ep->creg);
udc->req_pending = 0;
goto done;
}
}
if (ep->is_in)
status = write_fifo(ep, req);
else {
status = read_fifo(ep, req);
if (status && is_ep0)
goto ep0_in_status;
}
} else
status = 0;
if (req && !status) {
list_add_tail (&req->queue, &ep->queue);
at91_udp_write(udc, AT91_UDP_IER, ep->int_mask);
}
done:
spin_unlock_irqrestore(&udc->lock, flags);
return (status < 0) ? status : 0;
}
static int at91_ep_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct at91_ep *ep;
struct at91_request *req;
unsigned long flags;
struct at91_udc *udc;
ep = container_of(_ep, struct at91_ep, ep);
if (!_ep || ep->ep.name == ep0name)
return -EINVAL;
udc = ep->udc;
spin_lock_irqsave(&udc->lock, flags);
list_for_each_entry (req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
spin_unlock_irqrestore(&udc->lock, flags);
return -EINVAL;
}
done(ep, req, -ECONNRESET);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int at91_ep_set_halt(struct usb_ep *_ep, int value)
{
struct at91_ep *ep = container_of(_ep, struct at91_ep, ep);
struct at91_udc *udc = ep->udc;
u32 __iomem *creg;
u32 csr;
unsigned long flags;
int status = 0;
if (!_ep || ep->is_iso || !ep->udc->clocked)
return -EINVAL;
creg = ep->creg;
spin_lock_irqsave(&udc->lock, flags);
csr = __raw_readl(creg);
if (ep->is_in && (!list_empty(&ep->queue) || (csr >> 16) != 0))
status = -EAGAIN;
else {
csr |= CLR_FX;
csr &= ~SET_FX;
if (value) {
csr |= AT91_UDP_FORCESTALL;
VDBG("halt %s\n", ep->ep.name);
} else {
at91_udp_write(udc, AT91_UDP_RST_EP, ep->int_mask);
at91_udp_write(udc, AT91_UDP_RST_EP, 0);
csr &= ~AT91_UDP_FORCESTALL;
}
__raw_writel(csr, creg);
}
spin_unlock_irqrestore(&udc->lock, flags);
return status;
}
static int at91_get_frame(struct usb_gadget *gadget)
{
struct at91_udc *udc = to_udc(gadget);
if (!to_udc(gadget)->clocked)
return -EINVAL;
return at91_udp_read(udc, AT91_UDP_FRM_NUM) & AT91_UDP_NUM;
}
static int at91_wakeup(struct usb_gadget *gadget)
{
struct at91_udc *udc = to_udc(gadget);
u32 glbstate;
int status = -EINVAL;
unsigned long flags;
DBG("%s\n", __func__ );
spin_lock_irqsave(&udc->lock, flags);
if (!udc->clocked || !udc->suspended)
goto done;
glbstate = at91_udp_read(udc, AT91_UDP_GLB_STAT);
if (!(glbstate & AT91_UDP_ESR))
goto done;
glbstate |= AT91_UDP_ESR;
at91_udp_write(udc, AT91_UDP_GLB_STAT, glbstate);
done:
spin_unlock_irqrestore(&udc->lock, flags);
return status;
}
static void udc_reinit(struct at91_udc *udc)
{
u32 i;
INIT_LIST_HEAD(&udc->gadget.ep_list);
INIT_LIST_HEAD(&udc->gadget.ep0->ep_list);
for (i = 0; i < NUM_ENDPOINTS; i++) {
struct at91_ep *ep = &udc->ep[i];
if (i != 0)
list_add_tail(&ep->ep.ep_list, &udc->gadget.ep_list);
ep->ep.desc = NULL;
ep->stopped = 0;
ep->fifo_bank = 0;
usb_ep_set_maxpacket_limit(&ep->ep, ep->maxpacket);
ep->creg = (void __iomem *) udc->udp_baseaddr + AT91_UDP_CSR(i);
INIT_LIST_HEAD(&ep->queue);
}
}
static void stop_activity(struct at91_udc *udc)
{
struct usb_gadget_driver *driver = udc->driver;
int i;
if (udc->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->suspended = 0;
for (i = 0; i < NUM_ENDPOINTS; i++) {
struct at91_ep *ep = &udc->ep[i];
ep->stopped = 1;
nuke(ep, -ESHUTDOWN);
}
if (driver) {
spin_unlock(&udc->lock);
driver->disconnect(&udc->gadget);
spin_lock(&udc->lock);
}
udc_reinit(udc);
}
static void clk_on(struct at91_udc *udc)
{
if (udc->clocked)
return;
udc->clocked = 1;
if (IS_ENABLED(CONFIG_COMMON_CLK)) {
clk_set_rate(udc->uclk, 48000000);
clk_prepare_enable(udc->uclk);
}
clk_prepare_enable(udc->iclk);
clk_prepare_enable(udc->fclk);
}
static void clk_off(struct at91_udc *udc)
{
if (!udc->clocked)
return;
udc->clocked = 0;
udc->gadget.speed = USB_SPEED_UNKNOWN;
clk_disable_unprepare(udc->fclk);
clk_disable_unprepare(udc->iclk);
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_disable_unprepare(udc->uclk);
}
static void pullup(struct at91_udc *udc, int is_on)
{
int active = !udc->board.pullup_active_low;
if (!udc->enabled || !udc->vbus)
is_on = 0;
DBG("%sactive\n", is_on ? "" : "in");
if (is_on) {
clk_on(udc);
at91_udp_write(udc, AT91_UDP_ICR, AT91_UDP_RXRSM);
at91_udp_write(udc, AT91_UDP_TXVC, 0);
if (cpu_is_at91rm9200())
gpio_set_value(udc->board.pullup_pin, active);
else if (cpu_is_at91sam9260() || cpu_is_at91sam9263() || cpu_is_at91sam9g20()) {
u32 txvc = at91_udp_read(udc, AT91_UDP_TXVC);
txvc |= AT91_UDP_TXVC_PUON;
at91_udp_write(udc, AT91_UDP_TXVC, txvc);
} else if (cpu_is_at91sam9261() || cpu_is_at91sam9g10()) {
u32 usbpucr;
usbpucr = at91_matrix_read(AT91_MATRIX_USBPUCR);
usbpucr |= AT91_MATRIX_USBPUCR_PUON;
at91_matrix_write(AT91_MATRIX_USBPUCR, usbpucr);
}
} else {
stop_activity(udc);
at91_udp_write(udc, AT91_UDP_IDR, AT91_UDP_RXRSM);
at91_udp_write(udc, AT91_UDP_TXVC, AT91_UDP_TXVC_TXVDIS);
if (cpu_is_at91rm9200())
gpio_set_value(udc->board.pullup_pin, !active);
else if (cpu_is_at91sam9260() || cpu_is_at91sam9263() || cpu_is_at91sam9g20()) {
u32 txvc = at91_udp_read(udc, AT91_UDP_TXVC);
txvc &= ~AT91_UDP_TXVC_PUON;
at91_udp_write(udc, AT91_UDP_TXVC, txvc);
} else if (cpu_is_at91sam9261() || cpu_is_at91sam9g10()) {
u32 usbpucr;
usbpucr = at91_matrix_read(AT91_MATRIX_USBPUCR);
usbpucr &= ~AT91_MATRIX_USBPUCR_PUON;
at91_matrix_write(AT91_MATRIX_USBPUCR, usbpucr);
}
clk_off(udc);
}
}
static int at91_vbus_session(struct usb_gadget *gadget, int is_active)
{
struct at91_udc *udc = to_udc(gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->vbus = (is_active != 0);
if (udc->driver)
pullup(udc, is_active);
else
pullup(udc, 0);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int at91_pullup(struct usb_gadget *gadget, int is_on)
{
struct at91_udc *udc = to_udc(gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->enabled = is_on = !!is_on;
pullup(udc, is_on);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int at91_set_selfpowered(struct usb_gadget *gadget, int is_on)
{
struct at91_udc *udc = to_udc(gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->selfpowered = (is_on != 0);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int handle_ep(struct at91_ep *ep)
{
struct at91_request *req;
u32 __iomem *creg = ep->creg;
u32 csr = __raw_readl(creg);
if (!list_empty(&ep->queue))
req = list_entry(ep->queue.next,
struct at91_request, queue);
else
req = NULL;
if (ep->is_in) {
if (csr & (AT91_UDP_STALLSENT | AT91_UDP_TXCOMP)) {
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_STALLSENT | AT91_UDP_TXCOMP);
__raw_writel(csr, creg);
}
if (req)
return write_fifo(ep, req);
} else {
if (csr & AT91_UDP_STALLSENT) {
if (ep->is_iso && req)
req->req.status = -EILSEQ;
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_STALLSENT);
__raw_writel(csr, creg);
csr = __raw_readl(creg);
}
if (req && (csr & RX_DATA_READY))
return read_fifo(ep, req);
}
return 0;
}
static void handle_setup(struct at91_udc *udc, struct at91_ep *ep, u32 csr)
{
u32 __iomem *creg = ep->creg;
u8 __iomem *dreg = ep->creg + (AT91_UDP_FDR(0) - AT91_UDP_CSR(0));
unsigned rxcount, i = 0;
u32 tmp;
union setup pkt;
int status = 0;
rxcount = (csr & AT91_UDP_RXBYTECNT) >> 16;
if (likely(rxcount == 8)) {
while (rxcount--)
pkt.raw[i++] = __raw_readb(dreg);
if (pkt.r.bRequestType & USB_DIR_IN) {
csr |= AT91_UDP_DIR;
ep->is_in = 1;
} else {
csr &= ~AT91_UDP_DIR;
ep->is_in = 0;
}
} else {
ERR("SETUP len %d, csr %08x\n", rxcount, csr);
status = -EINVAL;
}
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_RXSETUP);
__raw_writel(csr, creg);
udc->wait_for_addr_ack = 0;
udc->wait_for_config_ack = 0;
ep->stopped = 0;
if (unlikely(status != 0))
goto stall;
#define w_index le16_to_cpu(pkt.r.wIndex)
#define w_value le16_to_cpu(pkt.r.wValue)
#define w_length le16_to_cpu(pkt.r.wLength)
VDBG("SETUP %02x.%02x v%04x i%04x l%04x\n",
pkt.r.bRequestType, pkt.r.bRequest,
w_value, w_index, w_length);
udc->req_pending = 1;
csr = __raw_readl(creg);
csr |= CLR_FX;
csr &= ~SET_FX;
switch ((pkt.r.bRequestType << 8) | pkt.r.bRequest) {
case ((USB_TYPE_STANDARD|USB_RECIP_DEVICE) << 8)
| USB_REQ_SET_ADDRESS:
__raw_writel(csr | AT91_UDP_TXPKTRDY, creg);
udc->addr = w_value;
udc->wait_for_addr_ack = 1;
udc->req_pending = 0;
return;
case ((USB_TYPE_STANDARD|USB_RECIP_DEVICE) << 8)
| USB_REQ_SET_CONFIGURATION:
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT) & AT91_UDP_CONFG;
if (pkt.r.wValue)
udc->wait_for_config_ack = (tmp == 0);
else
udc->wait_for_config_ack = (tmp != 0);
if (udc->wait_for_config_ack)
VDBG("wait for config\n");
break;
case ((USB_DIR_IN|USB_TYPE_STANDARD|USB_RECIP_DEVICE) << 8)
| USB_REQ_GET_STATUS:
tmp = (udc->selfpowered << USB_DEVICE_SELF_POWERED);
if (at91_udp_read(udc, AT91_UDP_GLB_STAT) & AT91_UDP_ESR)
tmp |= (1 << USB_DEVICE_REMOTE_WAKEUP);
PACKET("get device status\n");
__raw_writeb(tmp, dreg);
__raw_writeb(0, dreg);
goto write_in;
case ((USB_TYPE_STANDARD|USB_RECIP_DEVICE) << 8)
| USB_REQ_SET_FEATURE:
if (w_value != USB_DEVICE_REMOTE_WAKEUP)
goto stall;
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT);
tmp |= AT91_UDP_ESR;
at91_udp_write(udc, AT91_UDP_GLB_STAT, tmp);
goto succeed;
case ((USB_TYPE_STANDARD|USB_RECIP_DEVICE) << 8)
| USB_REQ_CLEAR_FEATURE:
if (w_value != USB_DEVICE_REMOTE_WAKEUP)
goto stall;
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT);
tmp &= ~AT91_UDP_ESR;
at91_udp_write(udc, AT91_UDP_GLB_STAT, tmp);
goto succeed;
case ((USB_DIR_IN|USB_TYPE_STANDARD|USB_RECIP_INTERFACE) << 8)
| USB_REQ_GET_STATUS:
PACKET("get interface status\n");
__raw_writeb(0, dreg);
__raw_writeb(0, dreg);
goto write_in;
case ((USB_TYPE_STANDARD|USB_RECIP_INTERFACE) << 8)
| USB_REQ_SET_FEATURE:
case ((USB_TYPE_STANDARD|USB_RECIP_INTERFACE) << 8)
| USB_REQ_CLEAR_FEATURE:
goto stall;
case ((USB_DIR_IN|USB_TYPE_STANDARD|USB_RECIP_ENDPOINT) << 8)
| USB_REQ_GET_STATUS:
tmp = w_index & USB_ENDPOINT_NUMBER_MASK;
ep = &udc->ep[tmp];
if (tmp >= NUM_ENDPOINTS || (tmp && !ep->ep.desc))
goto stall;
if (tmp) {
if ((w_index & USB_DIR_IN)) {
if (!ep->is_in)
goto stall;
} else if (ep->is_in)
goto stall;
}
PACKET("get %s status\n", ep->ep.name);
if (__raw_readl(ep->creg) & AT91_UDP_FORCESTALL)
tmp = (1 << USB_ENDPOINT_HALT);
else
tmp = 0;
__raw_writeb(tmp, dreg);
__raw_writeb(0, dreg);
goto write_in;
case ((USB_TYPE_STANDARD|USB_RECIP_ENDPOINT) << 8)
| USB_REQ_SET_FEATURE:
tmp = w_index & USB_ENDPOINT_NUMBER_MASK;
ep = &udc->ep[tmp];
if (w_value != USB_ENDPOINT_HALT || tmp >= NUM_ENDPOINTS)
goto stall;
if (!ep->ep.desc || ep->is_iso)
goto stall;
if ((w_index & USB_DIR_IN)) {
if (!ep->is_in)
goto stall;
} else if (ep->is_in)
goto stall;
tmp = __raw_readl(ep->creg);
tmp &= ~SET_FX;
tmp |= CLR_FX | AT91_UDP_FORCESTALL;
__raw_writel(tmp, ep->creg);
goto succeed;
case ((USB_TYPE_STANDARD|USB_RECIP_ENDPOINT) << 8)
| USB_REQ_CLEAR_FEATURE:
tmp = w_index & USB_ENDPOINT_NUMBER_MASK;
ep = &udc->ep[tmp];
if (w_value != USB_ENDPOINT_HALT || tmp >= NUM_ENDPOINTS)
goto stall;
if (tmp == 0)
goto succeed;
if (!ep->ep.desc || ep->is_iso)
goto stall;
if ((w_index & USB_DIR_IN)) {
if (!ep->is_in)
goto stall;
} else if (ep->is_in)
goto stall;
at91_udp_write(udc, AT91_UDP_RST_EP, ep->int_mask);
at91_udp_write(udc, AT91_UDP_RST_EP, 0);
tmp = __raw_readl(ep->creg);
tmp |= CLR_FX;
tmp &= ~(SET_FX | AT91_UDP_FORCESTALL);
__raw_writel(tmp, ep->creg);
if (!list_empty(&ep->queue))
handle_ep(ep);
goto succeed;
}
#undef w_value
#undef w_index
#undef w_length
if (udc->driver) {
spin_unlock(&udc->lock);
status = udc->driver->setup(&udc->gadget, &pkt.r);
spin_lock(&udc->lock);
}
else
status = -ENODEV;
if (status < 0) {
stall:
VDBG("req %02x.%02x protocol STALL; stat %d\n",
pkt.r.bRequestType, pkt.r.bRequest, status);
csr |= AT91_UDP_FORCESTALL;
__raw_writel(csr, creg);
udc->req_pending = 0;
}
return;
succeed:
PACKET("ep0 in/status\n");
write_in:
csr |= AT91_UDP_TXPKTRDY;
__raw_writel(csr, creg);
udc->req_pending = 0;
}
static void handle_ep0(struct at91_udc *udc)
{
struct at91_ep *ep0 = &udc->ep[0];
u32 __iomem *creg = ep0->creg;
u32 csr = __raw_readl(creg);
struct at91_request *req;
if (unlikely(csr & AT91_UDP_STALLSENT)) {
nuke(ep0, -EPROTO);
udc->req_pending = 0;
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_STALLSENT | AT91_UDP_FORCESTALL);
__raw_writel(csr, creg);
VDBG("ep0 stalled\n");
csr = __raw_readl(creg);
}
if (csr & AT91_UDP_RXSETUP) {
nuke(ep0, 0);
udc->req_pending = 0;
handle_setup(udc, ep0, csr);
return;
}
if (list_empty(&ep0->queue))
req = NULL;
else
req = list_entry(ep0->queue.next, struct at91_request, queue);
if (csr & AT91_UDP_TXCOMP) {
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_TXCOMP);
if (req && ep0->is_in) {
if (handle_ep(ep0))
udc->req_pending = 0;
} else {
udc->req_pending = 0;
__raw_writel(csr, creg);
if (udc->wait_for_addr_ack) {
u32 tmp;
at91_udp_write(udc, AT91_UDP_FADDR,
AT91_UDP_FEN | udc->addr);
tmp = at91_udp_read(udc, AT91_UDP_GLB_STAT);
tmp &= ~AT91_UDP_FADDEN;
if (udc->addr)
tmp |= AT91_UDP_FADDEN;
at91_udp_write(udc, AT91_UDP_GLB_STAT, tmp);
udc->wait_for_addr_ack = 0;
VDBG("address %d\n", udc->addr);
}
}
}
else if (csr & AT91_UDP_RX_DATA_BK0) {
csr |= CLR_FX;
csr &= ~(SET_FX | AT91_UDP_RX_DATA_BK0);
if (!ep0->is_in) {
if (req) {
if (handle_ep(ep0)) {
PACKET("ep0 in/status\n");
csr = __raw_readl(creg);
csr &= ~SET_FX;
csr |= CLR_FX | AT91_UDP_TXPKTRDY;
__raw_writel(csr, creg);
udc->req_pending = 0;
}
} else if (udc->req_pending) {
DBG("no control-OUT deferred responses!\n");
__raw_writel(csr | AT91_UDP_FORCESTALL, creg);
udc->req_pending = 0;
}
} else {
PACKET("ep0 out/status ACK\n");
__raw_writel(csr, creg);
if (req)
done(ep0, req, 0);
}
}
}
static irqreturn_t at91_udc_irq (int irq, void *_udc)
{
struct at91_udc *udc = _udc;
u32 rescans = 5;
int disable_clock = 0;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
if (!udc->clocked) {
clk_on(udc);
disable_clock = 1;
}
while (rescans--) {
u32 status;
status = at91_udp_read(udc, AT91_UDP_ISR)
& at91_udp_read(udc, AT91_UDP_IMR);
if (!status)
break;
if (status & AT91_UDP_ENDBUSRES) {
at91_udp_write(udc, AT91_UDP_IDR, ~MINIMUS_INTERRUPTUS);
at91_udp_write(udc, AT91_UDP_IER, MINIMUS_INTERRUPTUS);
at91_udp_write(udc, AT91_UDP_ICR, AT91_UDP_ENDBUSRES);
at91_udp_write(udc, AT91_UDP_ICR, AT91_UDP_ENDBUSRES);
VDBG("end bus reset\n");
udc->addr = 0;
stop_activity(udc);
at91_udp_write(udc, AT91_UDP_CSR(0),
AT91_UDP_EPEDS | AT91_UDP_EPTYPE_CTRL);
udc->gadget.speed = USB_SPEED_FULL;
udc->suspended = 0;
at91_udp_write(udc, AT91_UDP_IER, AT91_UDP_EP(0));
} else if (status & AT91_UDP_RXSUSP) {
at91_udp_write(udc, AT91_UDP_IDR, AT91_UDP_RXSUSP);
at91_udp_write(udc, AT91_UDP_IER, AT91_UDP_RXRSM);
at91_udp_write(udc, AT91_UDP_ICR, AT91_UDP_RXSUSP);
if (udc->suspended)
continue;
udc->suspended = 1;
if (udc->driver && udc->driver->suspend) {
spin_unlock(&udc->lock);
udc->driver->suspend(&udc->gadget);
spin_lock(&udc->lock);
}
} else if (status & AT91_UDP_RXRSM) {
at91_udp_write(udc, AT91_UDP_IDR, AT91_UDP_RXRSM);
at91_udp_write(udc, AT91_UDP_IER, AT91_UDP_RXSUSP);
at91_udp_write(udc, AT91_UDP_ICR, AT91_UDP_RXRSM);
if (!udc->suspended)
continue;
udc->suspended = 0;
if (udc->driver && udc->driver->resume) {
spin_unlock(&udc->lock);
udc->driver->resume(&udc->gadget);
spin_lock(&udc->lock);
}
} else {
int i;
unsigned mask = 1;
struct at91_ep *ep = &udc->ep[1];
if (status & mask)
handle_ep0(udc);
for (i = 1; i < NUM_ENDPOINTS; i++) {
mask <<= 1;
if (status & mask)
handle_ep(ep);
ep++;
}
}
}
if (disable_clock)
clk_off(udc);
spin_unlock_irqrestore(&udc->lock, flags);
return IRQ_HANDLED;
}
static void nop_release(struct device *dev)
{
}
static void at91_vbus_update(struct at91_udc *udc, unsigned value)
{
value ^= udc->board.vbus_active_low;
if (value != udc->vbus)
at91_vbus_session(&udc->gadget, value);
}
static irqreturn_t at91_vbus_irq(int irq, void *_udc)
{
struct at91_udc *udc = _udc;
udelay(10);
at91_vbus_update(udc, gpio_get_value(udc->board.vbus_pin));
return IRQ_HANDLED;
}
static void at91_vbus_timer_work(struct work_struct *work)
{
struct at91_udc *udc = container_of(work, struct at91_udc,
vbus_timer_work);
at91_vbus_update(udc, gpio_get_value_cansleep(udc->board.vbus_pin));
if (!timer_pending(&udc->vbus_timer))
mod_timer(&udc->vbus_timer, jiffies + VBUS_POLL_TIMEOUT);
}
static void at91_vbus_timer(unsigned long data)
{
struct at91_udc *udc = (struct at91_udc *)data;
schedule_work(&udc->vbus_timer_work);
}
static int at91_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct at91_udc *udc;
udc = container_of(gadget, struct at91_udc, gadget);
udc->driver = driver;
udc->gadget.dev.of_node = udc->pdev->dev.of_node;
udc->enabled = 1;
udc->selfpowered = 1;
DBG("bound to %s\n", driver->driver.name);
return 0;
}
static int at91_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct at91_udc *udc;
unsigned long flags;
udc = container_of(gadget, struct at91_udc, gadget);
spin_lock_irqsave(&udc->lock, flags);
udc->enabled = 0;
at91_udp_write(udc, AT91_UDP_IDR, ~0);
spin_unlock_irqrestore(&udc->lock, flags);
udc->driver = NULL;
DBG("unbound from %s\n", driver->driver.name);
return 0;
}
static void at91udc_shutdown(struct platform_device *dev)
{
struct at91_udc *udc = platform_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
pullup(platform_get_drvdata(dev), 0);
spin_unlock_irqrestore(&udc->lock, flags);
}
static void at91udc_of_init(struct at91_udc *udc,
struct device_node *np)
{
struct at91_udc_data *board = &udc->board;
u32 val;
enum of_gpio_flags flags;
if (of_property_read_u32(np, "atmel,vbus-polled", &val) == 0)
board->vbus_polled = 1;
board->vbus_pin = of_get_named_gpio_flags(np, "atmel,vbus-gpio", 0,
&flags);
board->vbus_active_low = (flags & OF_GPIO_ACTIVE_LOW) ? 1 : 0;
board->pullup_pin = of_get_named_gpio_flags(np, "atmel,pullup-gpio", 0,
&flags);
board->pullup_active_low = (flags & OF_GPIO_ACTIVE_LOW) ? 1 : 0;
}
static int at91udc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct at91_udc *udc;
int retval;
struct resource *res;
if (!dev_get_platdata(dev) && !pdev->dev.of_node) {
DBG("missing platform_data\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
if (!request_mem_region(res->start, resource_size(res), driver_name)) {
DBG("someone's using UDC memory\n");
return -EBUSY;
}
udc = &controller;
udc->gadget.dev.parent = dev;
if (IS_ENABLED(CONFIG_OF) && pdev->dev.of_node)
at91udc_of_init(udc, pdev->dev.of_node);
else
memcpy(&udc->board, dev_get_platdata(dev),
sizeof(struct at91_udc_data));
udc->pdev = pdev;
udc->enabled = 0;
spin_lock_init(&udc->lock);
if (cpu_is_at91rm9200()) {
if (!gpio_is_valid(udc->board.pullup_pin)) {
DBG("no D+ pullup?\n");
retval = -ENODEV;
goto fail0;
}
retval = gpio_request(udc->board.pullup_pin, "udc_pullup");
if (retval) {
DBG("D+ pullup is busy\n");
goto fail0;
}
gpio_direction_output(udc->board.pullup_pin,
udc->board.pullup_active_low);
}
if (cpu_is_at91sam9260() || cpu_is_at91sam9g20()) {
udc->ep[0].maxpacket = 64;
udc->ep[3].maxpacket = 64;
udc->ep[4].maxpacket = 512;
udc->ep[5].maxpacket = 512;
} else if (cpu_is_at91sam9261() || cpu_is_at91sam9g10()) {
udc->ep[3].maxpacket = 64;
} else if (cpu_is_at91sam9263()) {
udc->ep[0].maxpacket = 64;
udc->ep[3].maxpacket = 64;
}
udc->udp_baseaddr = ioremap(res->start, resource_size(res));
if (!udc->udp_baseaddr) {
retval = -ENOMEM;
goto fail0a;
}
udc_reinit(udc);
udc->iclk = clk_get(dev, "udc_clk");
udc->fclk = clk_get(dev, "udpck");
if (IS_ENABLED(CONFIG_COMMON_CLK))
udc->uclk = clk_get(dev, "usb_clk");
if (IS_ERR(udc->iclk) || IS_ERR(udc->fclk) ||
(IS_ENABLED(CONFIG_COMMON_CLK) && IS_ERR(udc->uclk))) {
DBG("clocks missing\n");
retval = -ENODEV;
goto fail1;
}
retval = clk_prepare_enable(udc->iclk);
if (retval)
goto fail1;
at91_udp_write(udc, AT91_UDP_TXVC, AT91_UDP_TXVC_TXVDIS);
at91_udp_write(udc, AT91_UDP_IDR, 0xffffffff);
at91_udp_write(udc, AT91_UDP_ICR, 0xffffffff);
clk_disable_unprepare(udc->iclk);
udc->udp_irq = platform_get_irq(pdev, 0);
retval = request_irq(udc->udp_irq, at91_udc_irq,
0, driver_name, udc);
if (retval < 0) {
DBG("request irq %d failed\n", udc->udp_irq);
goto fail1;
}
if (gpio_is_valid(udc->board.vbus_pin)) {
retval = gpio_request(udc->board.vbus_pin, "udc_vbus");
if (retval < 0) {
DBG("request vbus pin failed\n");
goto fail2;
}
gpio_direction_input(udc->board.vbus_pin);
udc->vbus = gpio_get_value_cansleep(udc->board.vbus_pin) ^
udc->board.vbus_active_low;
if (udc->board.vbus_polled) {
INIT_WORK(&udc->vbus_timer_work, at91_vbus_timer_work);
setup_timer(&udc->vbus_timer, at91_vbus_timer,
(unsigned long)udc);
mod_timer(&udc->vbus_timer,
jiffies + VBUS_POLL_TIMEOUT);
} else {
if (request_irq(gpio_to_irq(udc->board.vbus_pin),
at91_vbus_irq, 0, driver_name, udc)) {
DBG("request vbus irq %d failed\n",
udc->board.vbus_pin);
retval = -EBUSY;
goto fail3;
}
}
} else {
DBG("no VBUS detection, assuming always-on\n");
udc->vbus = 1;
}
retval = usb_add_gadget_udc(dev, &udc->gadget);
if (retval)
goto fail4;
dev_set_drvdata(dev, udc);
device_init_wakeup(dev, 1);
create_debug_file(udc);
INFO("%s version %s\n", driver_name, DRIVER_VERSION);
return 0;
fail4:
if (gpio_is_valid(udc->board.vbus_pin) && !udc->board.vbus_polled)
free_irq(gpio_to_irq(udc->board.vbus_pin), udc);
fail3:
if (gpio_is_valid(udc->board.vbus_pin))
gpio_free(udc->board.vbus_pin);
fail2:
free_irq(udc->udp_irq, udc);
fail1:
if (IS_ENABLED(CONFIG_COMMON_CLK) && !IS_ERR(udc->uclk))
clk_put(udc->uclk);
if (!IS_ERR(udc->fclk))
clk_put(udc->fclk);
if (!IS_ERR(udc->iclk))
clk_put(udc->iclk);
iounmap(udc->udp_baseaddr);
fail0a:
if (cpu_is_at91rm9200())
gpio_free(udc->board.pullup_pin);
fail0:
release_mem_region(res->start, resource_size(res));
DBG("%s probe failed, %d\n", driver_name, retval);
return retval;
}
static int __exit at91udc_remove(struct platform_device *pdev)
{
struct at91_udc *udc = platform_get_drvdata(pdev);
struct resource *res;
unsigned long flags;
DBG("remove\n");
usb_del_gadget_udc(&udc->gadget);
if (udc->driver)
return -EBUSY;
spin_lock_irqsave(&udc->lock, flags);
pullup(udc, 0);
spin_unlock_irqrestore(&udc->lock, flags);
device_init_wakeup(&pdev->dev, 0);
remove_debug_file(udc);
if (gpio_is_valid(udc->board.vbus_pin)) {
free_irq(gpio_to_irq(udc->board.vbus_pin), udc);
gpio_free(udc->board.vbus_pin);
}
free_irq(udc->udp_irq, udc);
iounmap(udc->udp_baseaddr);
if (cpu_is_at91rm9200())
gpio_free(udc->board.pullup_pin);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
clk_put(udc->iclk);
clk_put(udc->fclk);
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_put(udc->uclk);
return 0;
}
static int at91udc_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct at91_udc *udc = platform_get_drvdata(pdev);
int wake = udc->driver && device_may_wakeup(&pdev->dev);
unsigned long flags;
if ((!udc->suspended && udc->addr)
|| !wake
|| at91_suspend_entering_slow_clock()) {
spin_lock_irqsave(&udc->lock, flags);
pullup(udc, 0);
wake = 0;
spin_unlock_irqrestore(&udc->lock, flags);
} else
enable_irq_wake(udc->udp_irq);
udc->active_suspend = wake;
if (gpio_is_valid(udc->board.vbus_pin) && !udc->board.vbus_polled && wake)
enable_irq_wake(udc->board.vbus_pin);
return 0;
}
static int at91udc_resume(struct platform_device *pdev)
{
struct at91_udc *udc = platform_get_drvdata(pdev);
unsigned long flags;
if (gpio_is_valid(udc->board.vbus_pin) && !udc->board.vbus_polled &&
udc->active_suspend)
disable_irq_wake(udc->board.vbus_pin);
if (udc->active_suspend)
disable_irq_wake(udc->udp_irq);
else {
spin_lock_irqsave(&udc->lock, flags);
pullup(udc, 1);
spin_unlock_irqrestore(&udc->lock, flags);
}
return 0;
}
