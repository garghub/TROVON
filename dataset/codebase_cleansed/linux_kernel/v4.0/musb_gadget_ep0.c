static char *decode_ep0stage(u8 stage)
{
switch (stage) {
case MUSB_EP0_STAGE_IDLE: return "idle";
case MUSB_EP0_STAGE_SETUP: return "setup";
case MUSB_EP0_STAGE_TX: return "in";
case MUSB_EP0_STAGE_RX: return "out";
case MUSB_EP0_STAGE_ACKWAIT: return "wait";
case MUSB_EP0_STAGE_STATUSIN: return "in/status";
case MUSB_EP0_STAGE_STATUSOUT: return "out/status";
default: return "?";
}
}
static int service_tx_status_request(
struct musb *musb,
const struct usb_ctrlrequest *ctrlrequest)
{
void __iomem *mbase = musb->mregs;
int handled = 1;
u8 result[2], epnum = 0;
const u8 recip = ctrlrequest->bRequestType & USB_RECIP_MASK;
result[1] = 0;
switch (recip) {
case USB_RECIP_DEVICE:
result[0] = musb->g.is_selfpowered << USB_DEVICE_SELF_POWERED;
result[0] |= musb->may_wakeup << USB_DEVICE_REMOTE_WAKEUP;
if (musb->g.is_otg) {
result[0] |= musb->g.b_hnp_enable
<< USB_DEVICE_B_HNP_ENABLE;
result[0] |= musb->g.a_alt_hnp_support
<< USB_DEVICE_A_ALT_HNP_SUPPORT;
result[0] |= musb->g.a_hnp_support
<< USB_DEVICE_A_HNP_SUPPORT;
}
break;
case USB_RECIP_INTERFACE:
result[0] = 0;
break;
case USB_RECIP_ENDPOINT: {
int is_in;
struct musb_ep *ep;
u16 tmp;
void __iomem *regs;
epnum = (u8) ctrlrequest->wIndex;
if (!epnum) {
result[0] = 0;
break;
}
is_in = epnum & USB_DIR_IN;
if (is_in) {
epnum &= 0x0f;
ep = &musb->endpoints[epnum].ep_in;
} else {
ep = &musb->endpoints[epnum].ep_out;
}
regs = musb->endpoints[epnum].regs;
if (epnum >= MUSB_C_NUM_EPS || !ep->desc) {
handled = -EINVAL;
break;
}
musb_ep_select(mbase, epnum);
if (is_in)
tmp = musb_readw(regs, MUSB_TXCSR)
& MUSB_TXCSR_P_SENDSTALL;
else
tmp = musb_readw(regs, MUSB_RXCSR)
& MUSB_RXCSR_P_SENDSTALL;
musb_ep_select(mbase, 0);
result[0] = tmp ? 1 : 0;
} break;
default:
handled = 0;
break;
}
if (handled > 0) {
u16 len = le16_to_cpu(ctrlrequest->wLength);
if (len > 2)
len = 2;
musb_write_fifo(&musb->endpoints[0], len, result);
}
return handled;
}
static int
service_in_request(struct musb *musb, const struct usb_ctrlrequest *ctrlrequest)
{
int handled = 0;
if ((ctrlrequest->bRequestType & USB_TYPE_MASK)
== USB_TYPE_STANDARD) {
switch (ctrlrequest->bRequest) {
case USB_REQ_GET_STATUS:
handled = service_tx_status_request(musb,
ctrlrequest);
break;
default:
break;
}
}
return handled;
}
static void musb_g_ep0_giveback(struct musb *musb, struct usb_request *req)
{
musb_g_giveback(&musb->endpoints[0].ep_in, req, 0);
}
static inline void musb_try_b_hnp_enable(struct musb *musb)
{
void __iomem *mbase = musb->mregs;
u8 devctl;
dev_dbg(musb->controller, "HNP: Setting HR\n");
devctl = musb_readb(mbase, MUSB_DEVCTL);
musb_writeb(mbase, MUSB_DEVCTL, devctl | MUSB_DEVCTL_HR);
}
static int
service_zero_data_request(struct musb *musb,
struct usb_ctrlrequest *ctrlrequest)
__releases(musb->lock)
__acquires(musb->lock)
{
int handled = -EINVAL;
void __iomem *mbase = musb->mregs;
const u8 recip = ctrlrequest->bRequestType & USB_RECIP_MASK;
if ((ctrlrequest->bRequestType & USB_TYPE_MASK)
== USB_TYPE_STANDARD) {
switch (ctrlrequest->bRequest) {
case USB_REQ_SET_ADDRESS:
musb->set_address = true;
musb->address = (u8) (ctrlrequest->wValue & 0x7f);
handled = 1;
break;
case USB_REQ_CLEAR_FEATURE:
switch (recip) {
case USB_RECIP_DEVICE:
if (ctrlrequest->wValue
!= USB_DEVICE_REMOTE_WAKEUP)
break;
musb->may_wakeup = 0;
handled = 1;
break;
case USB_RECIP_INTERFACE:
break;
case USB_RECIP_ENDPOINT:{
const u8 epnum =
ctrlrequest->wIndex & 0x0f;
struct musb_ep *musb_ep;
struct musb_hw_ep *ep;
struct musb_request *request;
void __iomem *regs;
int is_in;
u16 csr;
if (epnum == 0 || epnum >= MUSB_C_NUM_EPS ||
ctrlrequest->wValue != USB_ENDPOINT_HALT)
break;
ep = musb->endpoints + epnum;
regs = ep->regs;
is_in = ctrlrequest->wIndex & USB_DIR_IN;
if (is_in)
musb_ep = &ep->ep_in;
else
musb_ep = &ep->ep_out;
if (!musb_ep->desc)
break;
handled = 1;
if (musb_ep->wedged)
break;
musb_ep_select(mbase, epnum);
if (is_in) {
csr = musb_readw(regs, MUSB_TXCSR);
csr |= MUSB_TXCSR_CLRDATATOG |
MUSB_TXCSR_P_WZC_BITS;
csr &= ~(MUSB_TXCSR_P_SENDSTALL |
MUSB_TXCSR_P_SENTSTALL |
MUSB_TXCSR_TXPKTRDY);
musb_writew(regs, MUSB_TXCSR, csr);
} else {
csr = musb_readw(regs, MUSB_RXCSR);
csr |= MUSB_RXCSR_CLRDATATOG |
MUSB_RXCSR_P_WZC_BITS;
csr &= ~(MUSB_RXCSR_P_SENDSTALL |
MUSB_RXCSR_P_SENTSTALL);
musb_writew(regs, MUSB_RXCSR, csr);
}
request = next_request(musb_ep);
if (!musb_ep->busy && request) {
dev_dbg(musb->controller, "restarting the request\n");
musb_ep_restart(musb, request);
}
musb_ep_select(mbase, 0);
} break;
default:
handled = 0;
break;
}
break;
case USB_REQ_SET_FEATURE:
switch (recip) {
case USB_RECIP_DEVICE:
handled = 1;
switch (ctrlrequest->wValue) {
case USB_DEVICE_REMOTE_WAKEUP:
musb->may_wakeup = 1;
break;
case USB_DEVICE_TEST_MODE:
if (musb->g.speed != USB_SPEED_HIGH)
goto stall;
if (ctrlrequest->wIndex & 0xff)
goto stall;
switch (ctrlrequest->wIndex >> 8) {
case 1:
pr_debug("TEST_J\n");
musb->test_mode_nr =
MUSB_TEST_J;
break;
case 2:
pr_debug("TEST_K\n");
musb->test_mode_nr =
MUSB_TEST_K;
break;
case 3:
pr_debug("TEST_SE0_NAK\n");
musb->test_mode_nr =
MUSB_TEST_SE0_NAK;
break;
case 4:
pr_debug("TEST_PACKET\n");
musb->test_mode_nr =
MUSB_TEST_PACKET;
break;
case 0xc0:
pr_debug("TEST_FORCE_HS\n");
musb->test_mode_nr =
MUSB_TEST_FORCE_HS;
break;
case 0xc1:
pr_debug("TEST_FORCE_FS\n");
musb->test_mode_nr =
MUSB_TEST_FORCE_FS;
break;
case 0xc2:
pr_debug("TEST_FIFO_ACCESS\n");
musb->test_mode_nr =
MUSB_TEST_FIFO_ACCESS;
break;
case 0xc3:
pr_debug("TEST_FORCE_HOST\n");
musb->test_mode_nr =
MUSB_TEST_FORCE_HOST;
break;
default:
goto stall;
}
if (handled > 0)
musb->test_mode = true;
break;
case USB_DEVICE_B_HNP_ENABLE:
if (!musb->g.is_otg)
goto stall;
musb->g.b_hnp_enable = 1;
musb_try_b_hnp_enable(musb);
break;
case USB_DEVICE_A_HNP_SUPPORT:
if (!musb->g.is_otg)
goto stall;
musb->g.a_hnp_support = 1;
break;
case USB_DEVICE_A_ALT_HNP_SUPPORT:
if (!musb->g.is_otg)
goto stall;
musb->g.a_alt_hnp_support = 1;
break;
case USB_DEVICE_DEBUG_MODE:
handled = 0;
break;
stall:
default:
handled = -EINVAL;
break;
}
break;
case USB_RECIP_INTERFACE:
break;
case USB_RECIP_ENDPOINT:{
const u8 epnum =
ctrlrequest->wIndex & 0x0f;
struct musb_ep *musb_ep;
struct musb_hw_ep *ep;
void __iomem *regs;
int is_in;
u16 csr;
if (epnum == 0 || epnum >= MUSB_C_NUM_EPS ||
ctrlrequest->wValue != USB_ENDPOINT_HALT)
break;
ep = musb->endpoints + epnum;
regs = ep->regs;
is_in = ctrlrequest->wIndex & USB_DIR_IN;
if (is_in)
musb_ep = &ep->ep_in;
else
musb_ep = &ep->ep_out;
if (!musb_ep->desc)
break;
musb_ep_select(mbase, epnum);
if (is_in) {
csr = musb_readw(regs, MUSB_TXCSR);
if (csr & MUSB_TXCSR_FIFONOTEMPTY)
csr |= MUSB_TXCSR_FLUSHFIFO;
csr |= MUSB_TXCSR_P_SENDSTALL
| MUSB_TXCSR_CLRDATATOG
| MUSB_TXCSR_P_WZC_BITS;
musb_writew(regs, MUSB_TXCSR, csr);
} else {
csr = musb_readw(regs, MUSB_RXCSR);
csr |= MUSB_RXCSR_P_SENDSTALL
| MUSB_RXCSR_FLUSHFIFO
| MUSB_RXCSR_CLRDATATOG
| MUSB_RXCSR_P_WZC_BITS;
musb_writew(regs, MUSB_RXCSR, csr);
}
musb_ep_select(mbase, 0);
handled = 1;
} break;
default:
handled = 0;
break;
}
break;
default:
handled = 0;
}
} else
handled = 0;
return handled;
}
static void ep0_rxstate(struct musb *musb)
{
void __iomem *regs = musb->control_ep->regs;
struct musb_request *request;
struct usb_request *req;
u16 count, csr;
request = next_ep0_request(musb);
req = &request->request;
if (req) {
void *buf = req->buf + req->actual;
unsigned len = req->length - req->actual;
count = musb_readb(regs, MUSB_COUNT0);
if (count > len) {
req->status = -EOVERFLOW;
count = len;
}
if (count > 0) {
musb_read_fifo(&musb->endpoints[0], count, buf);
req->actual += count;
}
csr = MUSB_CSR0_P_SVDRXPKTRDY;
if (count < 64 || req->actual == req->length) {
musb->ep0_state = MUSB_EP0_STAGE_STATUSIN;
csr |= MUSB_CSR0_P_DATAEND;
} else
req = NULL;
} else
csr = MUSB_CSR0_P_SVDRXPKTRDY | MUSB_CSR0_P_SENDSTALL;
if (req) {
musb->ackpend = csr;
musb_g_ep0_giveback(musb, req);
if (!musb->ackpend)
return;
musb->ackpend = 0;
}
musb_ep_select(musb->mregs, 0);
musb_writew(regs, MUSB_CSR0, csr);
}
static void ep0_txstate(struct musb *musb)
{
void __iomem *regs = musb->control_ep->regs;
struct musb_request *req = next_ep0_request(musb);
struct usb_request *request;
u16 csr = MUSB_CSR0_TXPKTRDY;
u8 *fifo_src;
u8 fifo_count;
if (!req) {
dev_dbg(musb->controller, "odd; csr0 %04x\n", musb_readw(regs, MUSB_CSR0));
return;
}
request = &req->request;
fifo_src = (u8 *) request->buf + request->actual;
fifo_count = min((unsigned) MUSB_EP0_FIFOSIZE,
request->length - request->actual);
musb_write_fifo(&musb->endpoints[0], fifo_count, fifo_src);
request->actual += fifo_count;
if (fifo_count < MUSB_MAX_END0_PACKET
|| (request->actual == request->length
&& !request->zero)) {
musb->ep0_state = MUSB_EP0_STAGE_STATUSOUT;
csr |= MUSB_CSR0_P_DATAEND;
} else
request = NULL;
if (request) {
musb->ackpend = csr;
musb_g_ep0_giveback(musb, request);
if (!musb->ackpend)
return;
musb->ackpend = 0;
}
musb_ep_select(musb->mregs, 0);
musb_writew(regs, MUSB_CSR0, csr);
}
static void
musb_read_setup(struct musb *musb, struct usb_ctrlrequest *req)
{
struct musb_request *r;
void __iomem *regs = musb->control_ep->regs;
musb_read_fifo(&musb->endpoints[0], sizeof *req, (u8 *)req);
dev_dbg(musb->controller, "SETUP req%02x.%02x v%04x i%04x l%d\n",
req->bRequestType,
req->bRequest,
le16_to_cpu(req->wValue),
le16_to_cpu(req->wIndex),
le16_to_cpu(req->wLength));
r = next_ep0_request(musb);
if (r)
musb_g_ep0_giveback(musb, &r->request);
musb->set_address = false;
musb->ackpend = MUSB_CSR0_P_SVDRXPKTRDY;
if (req->wLength == 0) {
if (req->bRequestType & USB_DIR_IN)
musb->ackpend |= MUSB_CSR0_TXPKTRDY;
musb->ep0_state = MUSB_EP0_STAGE_ACKWAIT;
} else if (req->bRequestType & USB_DIR_IN) {
musb->ep0_state = MUSB_EP0_STAGE_TX;
musb_writew(regs, MUSB_CSR0, MUSB_CSR0_P_SVDRXPKTRDY);
while ((musb_readw(regs, MUSB_CSR0)
& MUSB_CSR0_RXPKTRDY) != 0)
cpu_relax();
musb->ackpend = 0;
} else
musb->ep0_state = MUSB_EP0_STAGE_RX;
}
static int
forward_to_driver(struct musb *musb, const struct usb_ctrlrequest *ctrlrequest)
__releases(musb->lock)
__acquires(musb->lock)
{
int retval;
if (!musb->gadget_driver)
return -EOPNOTSUPP;
spin_unlock(&musb->lock);
retval = musb->gadget_driver->setup(&musb->g, ctrlrequest);
spin_lock(&musb->lock);
return retval;
}
irqreturn_t musb_g_ep0_irq(struct musb *musb)
{
u16 csr;
u16 len;
void __iomem *mbase = musb->mregs;
void __iomem *regs = musb->endpoints[0].regs;
irqreturn_t retval = IRQ_NONE;
musb_ep_select(mbase, 0);
csr = musb_readw(regs, MUSB_CSR0);
len = musb_readb(regs, MUSB_COUNT0);
dev_dbg(musb->controller, "csr %04x, count %d, ep0stage %s\n",
csr, len, decode_ep0stage(musb->ep0_state));
if (csr & MUSB_CSR0_P_DATAEND) {
return IRQ_HANDLED;
}
if (csr & MUSB_CSR0_P_SENTSTALL) {
musb_writew(regs, MUSB_CSR0,
csr & ~MUSB_CSR0_P_SENTSTALL);
retval = IRQ_HANDLED;
musb->ep0_state = MUSB_EP0_STAGE_IDLE;
csr = musb_readw(regs, MUSB_CSR0);
}
if (csr & MUSB_CSR0_P_SETUPEND) {
musb_writew(regs, MUSB_CSR0, MUSB_CSR0_P_SVDSETUPEND);
retval = IRQ_HANDLED;
switch (musb->ep0_state) {
case MUSB_EP0_STAGE_TX:
musb->ep0_state = MUSB_EP0_STAGE_STATUSOUT;
break;
case MUSB_EP0_STAGE_RX:
musb->ep0_state = MUSB_EP0_STAGE_STATUSIN;
break;
default:
ERR("SetupEnd came in a wrong ep0stage %s\n",
decode_ep0stage(musb->ep0_state));
}
csr = musb_readw(regs, MUSB_CSR0);
}
switch (musb->ep0_state) {
case MUSB_EP0_STAGE_TX:
if ((csr & MUSB_CSR0_TXPKTRDY) == 0) {
ep0_txstate(musb);
retval = IRQ_HANDLED;
}
break;
case MUSB_EP0_STAGE_RX:
if (csr & MUSB_CSR0_RXPKTRDY) {
ep0_rxstate(musb);
retval = IRQ_HANDLED;
}
break;
case MUSB_EP0_STAGE_STATUSIN:
if (musb->set_address) {
musb->set_address = false;
musb_writeb(mbase, MUSB_FADDR, musb->address);
}
else if (musb->test_mode) {
dev_dbg(musb->controller, "entering TESTMODE\n");
if (MUSB_TEST_PACKET == musb->test_mode_nr)
musb_load_testpacket(musb);
musb_writeb(mbase, MUSB_TESTMODE,
musb->test_mode_nr);
}
case MUSB_EP0_STAGE_STATUSOUT:
{
struct musb_request *req;
req = next_ep0_request(musb);
if (req)
musb_g_ep0_giveback(musb, &req->request);
}
if (csr & MUSB_CSR0_RXPKTRDY)
goto setup;
retval = IRQ_HANDLED;
musb->ep0_state = MUSB_EP0_STAGE_IDLE;
break;
case MUSB_EP0_STAGE_IDLE:
retval = IRQ_HANDLED;
musb->ep0_state = MUSB_EP0_STAGE_SETUP;
case MUSB_EP0_STAGE_SETUP:
setup:
if (csr & MUSB_CSR0_RXPKTRDY) {
struct usb_ctrlrequest setup;
int handled = 0;
if (len != 8) {
ERR("SETUP packet len %d != 8 ?\n", len);
break;
}
musb_read_setup(musb, &setup);
retval = IRQ_HANDLED;
if (unlikely(musb->g.speed == USB_SPEED_UNKNOWN)) {
u8 power;
printk(KERN_NOTICE "%s: peripheral reset "
"irq lost!\n",
musb_driver_name);
power = musb_readb(mbase, MUSB_POWER);
musb->g.speed = (power & MUSB_POWER_HSMODE)
? USB_SPEED_HIGH : USB_SPEED_FULL;
}
switch (musb->ep0_state) {
case MUSB_EP0_STAGE_ACKWAIT:
handled = service_zero_data_request(
musb, &setup);
musb->ackpend |= MUSB_CSR0_P_DATAEND;
if (handled > 0)
musb->ep0_state =
MUSB_EP0_STAGE_STATUSIN;
break;
case MUSB_EP0_STAGE_TX:
handled = service_in_request(musb, &setup);
if (handled > 0) {
musb->ackpend = MUSB_CSR0_TXPKTRDY
| MUSB_CSR0_P_DATAEND;
musb->ep0_state =
MUSB_EP0_STAGE_STATUSOUT;
}
break;
default:
break;
}
dev_dbg(musb->controller, "handled %d, csr %04x, ep0stage %s\n",
handled, csr,
decode_ep0stage(musb->ep0_state));
if (handled < 0)
goto stall;
else if (handled > 0)
goto finish;
handled = forward_to_driver(musb, &setup);
if (handled < 0) {
musb_ep_select(mbase, 0);
stall:
dev_dbg(musb->controller, "stall (%d)\n", handled);
musb->ackpend |= MUSB_CSR0_P_SENDSTALL;
musb->ep0_state = MUSB_EP0_STAGE_IDLE;
finish:
musb_writew(regs, MUSB_CSR0,
musb->ackpend);
musb->ackpend = 0;
}
}
break;
case MUSB_EP0_STAGE_ACKWAIT:
retval = IRQ_HANDLED;
break;
default:
WARN_ON(1);
musb_writew(regs, MUSB_CSR0, MUSB_CSR0_P_SENDSTALL);
musb->ep0_state = MUSB_EP0_STAGE_IDLE;
break;
}
return retval;
}
static int
musb_g_ep0_enable(struct usb_ep *ep, const struct usb_endpoint_descriptor *desc)
{
return -EINVAL;
}
static int musb_g_ep0_disable(struct usb_ep *e)
{
return -EINVAL;
}
static int
musb_g_ep0_queue(struct usb_ep *e, struct usb_request *r, gfp_t gfp_flags)
{
struct musb_ep *ep;
struct musb_request *req;
struct musb *musb;
int status;
unsigned long lockflags;
void __iomem *regs;
if (!e || !r)
return -EINVAL;
ep = to_musb_ep(e);
musb = ep->musb;
regs = musb->control_ep->regs;
req = to_musb_request(r);
req->musb = musb;
req->request.actual = 0;
req->request.status = -EINPROGRESS;
req->tx = ep->is_in;
spin_lock_irqsave(&musb->lock, lockflags);
if (!list_empty(&ep->req_list)) {
status = -EBUSY;
goto cleanup;
}
switch (musb->ep0_state) {
case MUSB_EP0_STAGE_RX:
case MUSB_EP0_STAGE_TX:
case MUSB_EP0_STAGE_ACKWAIT:
status = 0;
break;
default:
dev_dbg(musb->controller, "ep0 request queued in state %d\n",
musb->ep0_state);
status = -EINVAL;
goto cleanup;
}
list_add_tail(&req->list, &ep->req_list);
dev_dbg(musb->controller, "queue to %s (%s), length=%d\n",
ep->name, ep->is_in ? "IN/TX" : "OUT/RX",
req->request.length);
musb_ep_select(musb->mregs, 0);
if (musb->ep0_state == MUSB_EP0_STAGE_TX)
ep0_txstate(musb);
else if (musb->ep0_state == MUSB_EP0_STAGE_ACKWAIT) {
if (req->request.length)
status = -EINVAL;
else {
musb->ep0_state = MUSB_EP0_STAGE_STATUSIN;
musb_writew(regs, MUSB_CSR0,
musb->ackpend | MUSB_CSR0_P_DATAEND);
musb->ackpend = 0;
musb_g_ep0_giveback(ep->musb, r);
}
} else if (musb->ackpend) {
musb_writew(regs, MUSB_CSR0, musb->ackpend);
musb->ackpend = 0;
}
cleanup:
spin_unlock_irqrestore(&musb->lock, lockflags);
return status;
}
static int musb_g_ep0_dequeue(struct usb_ep *ep, struct usb_request *req)
{
return -EINVAL;
}
static int musb_g_ep0_halt(struct usb_ep *e, int value)
{
struct musb_ep *ep;
struct musb *musb;
void __iomem *base, *regs;
unsigned long flags;
int status;
u16 csr;
if (!e || !value)
return -EINVAL;
ep = to_musb_ep(e);
musb = ep->musb;
base = musb->mregs;
regs = musb->control_ep->regs;
status = 0;
spin_lock_irqsave(&musb->lock, flags);
if (!list_empty(&ep->req_list)) {
status = -EBUSY;
goto cleanup;
}
musb_ep_select(base, 0);
csr = musb->ackpend;
switch (musb->ep0_state) {
case MUSB_EP0_STAGE_TX:
case MUSB_EP0_STAGE_ACKWAIT:
case MUSB_EP0_STAGE_RX:
csr = musb_readw(regs, MUSB_CSR0);
case MUSB_EP0_STAGE_STATUSIN:
case MUSB_EP0_STAGE_STATUSOUT:
csr |= MUSB_CSR0_P_SENDSTALL;
musb_writew(regs, MUSB_CSR0, csr);
musb->ep0_state = MUSB_EP0_STAGE_IDLE;
musb->ackpend = 0;
break;
default:
dev_dbg(musb->controller, "ep0 can't halt in state %d\n", musb->ep0_state);
status = -EINVAL;
}
cleanup:
spin_unlock_irqrestore(&musb->lock, flags);
return status;
}
