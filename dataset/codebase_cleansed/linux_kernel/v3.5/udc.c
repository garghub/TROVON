static inline int hw_ep_bit(int num, int dir)
{
return num + (dir ? 16 : 0);
}
static inline int ep_to_bit(struct ci13xxx *udc, int n)
{
int fill = 16 - udc->hw_ep_max / 2;
if (n >= udc->hw_ep_max / 2)
n += fill;
return n;
}
static int hw_device_state(struct ci13xxx *udc, u32 dma)
{
if (dma) {
hw_write(udc, OP_ENDPTLISTADDR, ~0, dma);
hw_write(udc, OP_USBINTR, ~0,
USBi_UI|USBi_UEI|USBi_PCI|USBi_URI|USBi_SLI);
hw_write(udc, OP_USBCMD, USBCMD_RS, USBCMD_RS);
} else {
hw_write(udc, OP_USBCMD, USBCMD_RS, 0);
hw_write(udc, OP_USBINTR, ~0, 0);
}
return 0;
}
static int hw_ep_flush(struct ci13xxx *udc, int num, int dir)
{
int n = hw_ep_bit(num, dir);
do {
hw_write(udc, OP_ENDPTFLUSH, BIT(n), BIT(n));
while (hw_read(udc, OP_ENDPTFLUSH, BIT(n)))
cpu_relax();
} while (hw_read(udc, OP_ENDPTSTAT, BIT(n)));
return 0;
}
static int hw_ep_disable(struct ci13xxx *udc, int num, int dir)
{
hw_ep_flush(udc, num, dir);
hw_write(udc, OP_ENDPTCTRL + num,
dir ? ENDPTCTRL_TXE : ENDPTCTRL_RXE, 0);
return 0;
}
static int hw_ep_enable(struct ci13xxx *udc, int num, int dir, int type)
{
u32 mask, data;
if (dir) {
mask = ENDPTCTRL_TXT;
data = type << ffs_nr(mask);
mask |= ENDPTCTRL_TXS;
mask |= ENDPTCTRL_TXR;
data |= ENDPTCTRL_TXR;
mask |= ENDPTCTRL_TXE;
data |= ENDPTCTRL_TXE;
} else {
mask = ENDPTCTRL_RXT;
data = type << ffs_nr(mask);
mask |= ENDPTCTRL_RXS;
mask |= ENDPTCTRL_RXR;
data |= ENDPTCTRL_RXR;
mask |= ENDPTCTRL_RXE;
data |= ENDPTCTRL_RXE;
}
hw_write(udc, OP_ENDPTCTRL + num, mask, data);
return 0;
}
static int hw_ep_get_halt(struct ci13xxx *udc, int num, int dir)
{
u32 mask = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
return hw_read(udc, OP_ENDPTCTRL + num, mask) ? 1 : 0;
}
static int hw_test_and_clear_setup_status(struct ci13xxx *udc, int n)
{
n = ep_to_bit(udc, n);
return hw_test_and_clear(udc, OP_ENDPTSETUPSTAT, BIT(n));
}
static int hw_ep_prime(struct ci13xxx *udc, int num, int dir, int is_ctrl)
{
int n = hw_ep_bit(num, dir);
if (is_ctrl && dir == RX && hw_read(udc, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
hw_write(udc, OP_ENDPTPRIME, BIT(n), BIT(n));
while (hw_read(udc, OP_ENDPTPRIME, BIT(n)))
cpu_relax();
if (is_ctrl && dir == RX && hw_read(udc, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
return 0;
}
static int hw_ep_set_halt(struct ci13xxx *udc, int num, int dir, int value)
{
if (value != 0 && value != 1)
return -EINVAL;
do {
enum ci13xxx_regs reg = OP_ENDPTCTRL + num;
u32 mask_xs = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
u32 mask_xr = dir ? ENDPTCTRL_TXR : ENDPTCTRL_RXR;
hw_write(udc, reg, mask_xs|mask_xr,
value ? mask_xs : mask_xr);
} while (value != hw_ep_get_halt(udc, num, dir));
return 0;
}
static int hw_port_is_high_speed(struct ci13xxx *udc)
{
return udc->hw_bank.lpm ? hw_read(udc, OP_DEVLC, DEVLC_PSPD) :
hw_read(udc, OP_PORTSC, PORTSC_HSP);
}
static u32 hw_read_intr_enable(struct ci13xxx *udc)
{
return hw_read(udc, OP_USBINTR, ~0);
}
static u32 hw_read_intr_status(struct ci13xxx *udc)
{
return hw_read(udc, OP_USBSTS, ~0);
}
static int hw_test_and_clear_complete(struct ci13xxx *udc, int n)
{
n = ep_to_bit(udc, n);
return hw_test_and_clear(udc, OP_ENDPTCOMPLETE, BIT(n));
}
static u32 hw_test_and_clear_intr_active(struct ci13xxx *udc)
{
u32 reg = hw_read_intr_status(udc) & hw_read_intr_enable(udc);
hw_write(udc, OP_USBSTS, ~0, reg);
return reg;
}
static int hw_test_and_clear_setup_guard(struct ci13xxx *udc)
{
return hw_test_and_write(udc, OP_USBCMD, USBCMD_SUTW, 0);
}
static int hw_test_and_set_setup_guard(struct ci13xxx *udc)
{
return hw_test_and_write(udc, OP_USBCMD, USBCMD_SUTW, USBCMD_SUTW);
}
static void hw_usb_set_address(struct ci13xxx *udc, u8 value)
{
hw_write(udc, OP_DEVICEADDR, DEVICEADDR_USBADR,
value << ffs_nr(DEVICEADDR_USBADR));
}
static int hw_usb_reset(struct ci13xxx *udc)
{
hw_usb_set_address(udc, 0);
hw_write(udc, OP_ENDPTFLUSH, ~0, ~0);
hw_write(udc, OP_ENDPTSETUPSTAT, 0, 0);
hw_write(udc, OP_ENDPTCOMPLETE, 0, 0);
while (hw_read(udc, OP_ENDPTPRIME, ~0))
udelay(10);
return 0;
}
static inline u8 _usb_addr(struct ci13xxx_ep *ep)
{
return ((ep->dir == TX) ? USB_ENDPOINT_DIR_MASK : 0) | ep->num;
}
static int _hardware_enqueue(struct ci13xxx_ep *mEp, struct ci13xxx_req *mReq)
{
struct ci13xxx *udc = mEp->udc;
unsigned i;
int ret = 0;
unsigned length = mReq->req.length;
if (mReq->req.status == -EALREADY)
return -EALREADY;
mReq->req.status = -EALREADY;
if (mReq->req.zero && length && (length % mEp->ep.maxpacket == 0)) {
mReq->zptr = dma_pool_alloc(mEp->td_pool, GFP_ATOMIC,
&mReq->zdma);
if (mReq->zptr == NULL)
return -ENOMEM;
memset(mReq->zptr, 0, sizeof(*mReq->zptr));
mReq->zptr->next = TD_TERMINATE;
mReq->zptr->token = TD_STATUS_ACTIVE;
if (!mReq->req.no_interrupt)
mReq->zptr->token |= TD_IOC;
}
ret = usb_gadget_map_request(&udc->gadget, &mReq->req, mEp->dir);
if (ret)
return ret;
memset(mReq->ptr, 0, sizeof(*mReq->ptr));
mReq->ptr->token = length << ffs_nr(TD_TOTAL_BYTES);
mReq->ptr->token &= TD_TOTAL_BYTES;
mReq->ptr->token |= TD_STATUS_ACTIVE;
if (mReq->zptr) {
mReq->ptr->next = mReq->zdma;
} else {
mReq->ptr->next = TD_TERMINATE;
if (!mReq->req.no_interrupt)
mReq->ptr->token |= TD_IOC;
}
mReq->ptr->page[0] = mReq->req.dma;
for (i = 1; i < 5; i++)
mReq->ptr->page[i] =
(mReq->req.dma + i * CI13XXX_PAGE_SIZE) & ~TD_RESERVED_MASK;
if (!list_empty(&mEp->qh.queue)) {
struct ci13xxx_req *mReqPrev;
int n = hw_ep_bit(mEp->num, mEp->dir);
int tmp_stat;
mReqPrev = list_entry(mEp->qh.queue.prev,
struct ci13xxx_req, queue);
if (mReqPrev->zptr)
mReqPrev->zptr->next = mReq->dma & TD_ADDR_MASK;
else
mReqPrev->ptr->next = mReq->dma & TD_ADDR_MASK;
wmb();
if (hw_read(udc, OP_ENDPTPRIME, BIT(n)))
goto done;
do {
hw_write(udc, OP_USBCMD, USBCMD_ATDTW, USBCMD_ATDTW);
tmp_stat = hw_read(udc, OP_ENDPTSTAT, BIT(n));
} while (!hw_read(udc, OP_USBCMD, USBCMD_ATDTW));
hw_write(udc, OP_USBCMD, USBCMD_ATDTW, 0);
if (tmp_stat)
goto done;
}
mEp->qh.ptr->td.next = mReq->dma;
mEp->qh.ptr->td.token &= ~TD_STATUS;
mEp->qh.ptr->cap |= QH_ZLT;
wmb();
ret = hw_ep_prime(udc, mEp->num, mEp->dir,
mEp->type == USB_ENDPOINT_XFER_CONTROL);
done:
return ret;
}
static int _hardware_dequeue(struct ci13xxx_ep *mEp, struct ci13xxx_req *mReq)
{
if (mReq->req.status != -EALREADY)
return -EINVAL;
if ((TD_STATUS_ACTIVE & mReq->ptr->token) != 0)
return -EBUSY;
if (mReq->zptr) {
if ((TD_STATUS_ACTIVE & mReq->zptr->token) != 0)
return -EBUSY;
dma_pool_free(mEp->td_pool, mReq->zptr, mReq->zdma);
mReq->zptr = NULL;
}
mReq->req.status = 0;
usb_gadget_unmap_request(&mEp->udc->gadget, &mReq->req, mEp->dir);
mReq->req.status = mReq->ptr->token & TD_STATUS;
if ((TD_STATUS_HALTED & mReq->req.status) != 0)
mReq->req.status = -1;
else if ((TD_STATUS_DT_ERR & mReq->req.status) != 0)
mReq->req.status = -1;
else if ((TD_STATUS_TR_ERR & mReq->req.status) != 0)
mReq->req.status = -1;
mReq->req.actual = mReq->ptr->token & TD_TOTAL_BYTES;
mReq->req.actual >>= ffs_nr(TD_TOTAL_BYTES);
mReq->req.actual = mReq->req.length - mReq->req.actual;
mReq->req.actual = mReq->req.status ? 0 : mReq->req.actual;
return mReq->req.actual;
}
static int _ep_nuke(struct ci13xxx_ep *mEp)
__releases(mEp->lock)
__acquires(mEp->lock)
{
if (mEp == NULL)
return -EINVAL;
hw_ep_flush(mEp->udc, mEp->num, mEp->dir);
while (!list_empty(&mEp->qh.queue)) {
struct ci13xxx_req *mReq = \
list_entry(mEp->qh.queue.next,
struct ci13xxx_req, queue);
list_del_init(&mReq->queue);
mReq->req.status = -ESHUTDOWN;
if (mReq->req.complete != NULL) {
spin_unlock(mEp->lock);
mReq->req.complete(&mEp->ep, &mReq->req);
spin_lock(mEp->lock);
}
}
return 0;
}
static int _gadget_stop_activity(struct usb_gadget *gadget)
{
struct usb_ep *ep;
struct ci13xxx *udc = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->remote_wakeup = 0;
udc->suspended = 0;
spin_unlock_irqrestore(&udc->lock, flags);
gadget_for_each_ep(ep, gadget) {
usb_ep_fifo_flush(ep);
}
usb_ep_fifo_flush(&udc->ep0out->ep);
usb_ep_fifo_flush(&udc->ep0in->ep);
if (udc->driver)
udc->driver->disconnect(gadget);
gadget_for_each_ep(ep, gadget) {
usb_ep_disable(ep);
}
if (udc->status != NULL) {
usb_ep_free_request(&udc->ep0in->ep, udc->status);
udc->status = NULL;
}
return 0;
}
static void isr_reset_handler(struct ci13xxx *udc)
__releases(udc->lock)
__acquires(udc->lock)
{
int retval;
dbg_event(0xFF, "BUS RST", 0);
spin_unlock(&udc->lock);
retval = _gadget_stop_activity(&udc->gadget);
if (retval)
goto done;
retval = hw_usb_reset(udc);
if (retval)
goto done;
udc->status = usb_ep_alloc_request(&udc->ep0in->ep, GFP_ATOMIC);
if (udc->status == NULL)
retval = -ENOMEM;
done:
spin_lock(&udc->lock);
if (retval)
dev_err(udc->dev, "error: %i\n", retval);
}
static void isr_get_status_complete(struct usb_ep *ep, struct usb_request *req)
{
if (ep == NULL || req == NULL)
return;
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static int isr_get_status_response(struct ci13xxx *udc,
struct usb_ctrlrequest *setup)
__releases(mEp->lock)
__acquires(mEp->lock)
{
struct ci13xxx_ep *mEp = udc->ep0in;
struct usb_request *req = NULL;
gfp_t gfp_flags = GFP_ATOMIC;
int dir, num, retval;
if (mEp == NULL || setup == NULL)
return -EINVAL;
spin_unlock(mEp->lock);
req = usb_ep_alloc_request(&mEp->ep, gfp_flags);
spin_lock(mEp->lock);
if (req == NULL)
return -ENOMEM;
req->complete = isr_get_status_complete;
req->length = 2;
req->buf = kzalloc(req->length, gfp_flags);
if (req->buf == NULL) {
retval = -ENOMEM;
goto err_free_req;
}
if ((setup->bRequestType & USB_RECIP_MASK) == USB_RECIP_DEVICE) {
*(u16 *)req->buf = udc->remote_wakeup << 1;
retval = 0;
} else if ((setup->bRequestType & USB_RECIP_MASK) \
== USB_RECIP_ENDPOINT) {
dir = (le16_to_cpu(setup->wIndex) & USB_ENDPOINT_DIR_MASK) ?
TX : RX;
num = le16_to_cpu(setup->wIndex) & USB_ENDPOINT_NUMBER_MASK;
*(u16 *)req->buf = hw_ep_get_halt(udc, num, dir);
}
spin_unlock(mEp->lock);
retval = usb_ep_queue(&mEp->ep, req, gfp_flags);
spin_lock(mEp->lock);
if (retval)
goto err_free_buf;
return 0;
err_free_buf:
kfree(req->buf);
err_free_req:
spin_unlock(mEp->lock);
usb_ep_free_request(&mEp->ep, req);
spin_lock(mEp->lock);
return retval;
}
static void
isr_setup_status_complete(struct usb_ep *ep, struct usb_request *req)
{
struct ci13xxx *udc = req->context;
unsigned long flags;
if (udc->setaddr) {
hw_usb_set_address(udc, udc->address);
udc->setaddr = false;
}
spin_lock_irqsave(&udc->lock, flags);
if (udc->test_mode)
hw_port_test_set(udc, udc->test_mode);
spin_unlock_irqrestore(&udc->lock, flags);
}
static int isr_setup_status_phase(struct ci13xxx *udc)
__releases(mEp->lock)
__acquires(mEp->lock)
{
int retval;
struct ci13xxx_ep *mEp;
mEp = (udc->ep0_dir == TX) ? udc->ep0out : udc->ep0in;
udc->status->context = udc;
udc->status->complete = isr_setup_status_complete;
spin_unlock(mEp->lock);
retval = usb_ep_queue(&mEp->ep, udc->status, GFP_ATOMIC);
spin_lock(mEp->lock);
return retval;
}
static int isr_tr_complete_low(struct ci13xxx_ep *mEp)
__releases(mEp->lock)
__acquires(mEp->lock)
{
struct ci13xxx_req *mReq, *mReqTemp;
struct ci13xxx_ep *mEpTemp = mEp;
int uninitialized_var(retval);
if (list_empty(&mEp->qh.queue))
return -EINVAL;
list_for_each_entry_safe(mReq, mReqTemp, &mEp->qh.queue,
queue) {
retval = _hardware_dequeue(mEp, mReq);
if (retval < 0)
break;
list_del_init(&mReq->queue);
dbg_done(_usb_addr(mEp), mReq->ptr->token, retval);
if (mReq->req.complete != NULL) {
spin_unlock(mEp->lock);
if ((mEp->type == USB_ENDPOINT_XFER_CONTROL) &&
mReq->req.length)
mEpTemp = mEp->udc->ep0in;
mReq->req.complete(&mEpTemp->ep, &mReq->req);
spin_lock(mEp->lock);
}
}
if (retval == -EBUSY)
retval = 0;
if (retval < 0)
dbg_event(_usb_addr(mEp), "DONE", retval);
return retval;
}
static void isr_tr_complete_handler(struct ci13xxx *udc)
__releases(udc->lock)
__acquires(udc->lock)
{
unsigned i;
u8 tmode = 0;
for (i = 0; i < udc->hw_ep_max; i++) {
struct ci13xxx_ep *mEp = &udc->ci13xxx_ep[i];
int type, num, dir, err = -EINVAL;
struct usb_ctrlrequest req;
if (mEp->ep.desc == NULL)
continue;
if (hw_test_and_clear_complete(udc, i)) {
err = isr_tr_complete_low(mEp);
if (mEp->type == USB_ENDPOINT_XFER_CONTROL) {
if (err > 0)
err = isr_setup_status_phase(udc);
if (err < 0) {
dbg_event(_usb_addr(mEp),
"ERROR", err);
spin_unlock(&udc->lock);
if (usb_ep_set_halt(&mEp->ep))
dev_err(udc->dev,
"error: ep_set_halt\n");
spin_lock(&udc->lock);
}
}
}
if (mEp->type != USB_ENDPOINT_XFER_CONTROL ||
!hw_test_and_clear_setup_status(udc, i))
continue;
if (i != 0) {
dev_warn(udc->dev, "ctrl traffic at endpoint %d\n", i);
continue;
}
_ep_nuke(udc->ep0out);
_ep_nuke(udc->ep0in);
do {
hw_test_and_set_setup_guard(udc);
memcpy(&req, &mEp->qh.ptr->setup, sizeof(req));
} while (!hw_test_and_clear_setup_guard(udc));
type = req.bRequestType;
udc->ep0_dir = (type & USB_DIR_IN) ? TX : RX;
dbg_setup(_usb_addr(mEp), &req);
switch (req.bRequest) {
case USB_REQ_CLEAR_FEATURE:
if (type == (USB_DIR_OUT|USB_RECIP_ENDPOINT) &&
le16_to_cpu(req.wValue) ==
USB_ENDPOINT_HALT) {
if (req.wLength != 0)
break;
num = le16_to_cpu(req.wIndex);
dir = num & USB_ENDPOINT_DIR_MASK;
num &= USB_ENDPOINT_NUMBER_MASK;
if (dir)
num += udc->hw_ep_max/2;
if (!udc->ci13xxx_ep[num].wedge) {
spin_unlock(&udc->lock);
err = usb_ep_clear_halt(
&udc->ci13xxx_ep[num].ep);
spin_lock(&udc->lock);
if (err)
break;
}
err = isr_setup_status_phase(udc);
} else if (type == (USB_DIR_OUT|USB_RECIP_DEVICE) &&
le16_to_cpu(req.wValue) ==
USB_DEVICE_REMOTE_WAKEUP) {
if (req.wLength != 0)
break;
udc->remote_wakeup = 0;
err = isr_setup_status_phase(udc);
} else {
goto delegate;
}
break;
case USB_REQ_GET_STATUS:
if (type != (USB_DIR_IN|USB_RECIP_DEVICE) &&
type != (USB_DIR_IN|USB_RECIP_ENDPOINT) &&
type != (USB_DIR_IN|USB_RECIP_INTERFACE))
goto delegate;
if (le16_to_cpu(req.wLength) != 2 ||
le16_to_cpu(req.wValue) != 0)
break;
err = isr_get_status_response(udc, &req);
break;
case USB_REQ_SET_ADDRESS:
if (type != (USB_DIR_OUT|USB_RECIP_DEVICE))
goto delegate;
if (le16_to_cpu(req.wLength) != 0 ||
le16_to_cpu(req.wIndex) != 0)
break;
udc->address = (u8)le16_to_cpu(req.wValue);
udc->setaddr = true;
err = isr_setup_status_phase(udc);
break;
case USB_REQ_SET_FEATURE:
if (type == (USB_DIR_OUT|USB_RECIP_ENDPOINT) &&
le16_to_cpu(req.wValue) ==
USB_ENDPOINT_HALT) {
if (req.wLength != 0)
break;
num = le16_to_cpu(req.wIndex);
dir = num & USB_ENDPOINT_DIR_MASK;
num &= USB_ENDPOINT_NUMBER_MASK;
if (dir)
num += udc->hw_ep_max/2;
spin_unlock(&udc->lock);
err = usb_ep_set_halt(&udc->ci13xxx_ep[num].ep);
spin_lock(&udc->lock);
if (!err)
isr_setup_status_phase(udc);
} else if (type == (USB_DIR_OUT|USB_RECIP_DEVICE)) {
if (req.wLength != 0)
break;
switch (le16_to_cpu(req.wValue)) {
case USB_DEVICE_REMOTE_WAKEUP:
udc->remote_wakeup = 1;
err = isr_setup_status_phase(udc);
break;
case USB_DEVICE_TEST_MODE:
tmode = le16_to_cpu(req.wIndex) >> 8;
switch (tmode) {
case TEST_J:
case TEST_K:
case TEST_SE0_NAK:
case TEST_PACKET:
case TEST_FORCE_EN:
udc->test_mode = tmode;
err = isr_setup_status_phase(
udc);
break;
default:
break;
}
default:
goto delegate;
}
} else {
goto delegate;
}
break;
default:
delegate:
if (req.wLength == 0)
udc->ep0_dir = TX;
spin_unlock(&udc->lock);
err = udc->driver->setup(&udc->gadget, &req);
spin_lock(&udc->lock);
break;
}
if (err < 0) {
dbg_event(_usb_addr(mEp), "ERROR", err);
spin_unlock(&udc->lock);
if (usb_ep_set_halt(&mEp->ep))
dev_err(udc->dev, "error: ep_set_halt\n");
spin_lock(&udc->lock);
}
}
}
static int ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
int retval = 0;
unsigned long flags;
if (ep == NULL || desc == NULL)
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
mEp->ep.desc = desc;
if (!list_empty(&mEp->qh.queue))
dev_warn(mEp->udc->dev, "enabling a non-empty endpoint!\n");
mEp->dir = usb_endpoint_dir_in(desc) ? TX : RX;
mEp->num = usb_endpoint_num(desc);
mEp->type = usb_endpoint_type(desc);
mEp->ep.maxpacket = usb_endpoint_maxp(desc);
dbg_event(_usb_addr(mEp), "ENABLE", 0);
mEp->qh.ptr->cap = 0;
if (mEp->type == USB_ENDPOINT_XFER_CONTROL)
mEp->qh.ptr->cap |= QH_IOS;
else if (mEp->type == USB_ENDPOINT_XFER_ISOC)
mEp->qh.ptr->cap &= ~QH_MULT;
else
mEp->qh.ptr->cap &= ~QH_ZLT;
mEp->qh.ptr->cap |=
(mEp->ep.maxpacket << ffs_nr(QH_MAX_PKT)) & QH_MAX_PKT;
mEp->qh.ptr->td.next |= TD_TERMINATE;
if (mEp->num)
retval |= hw_ep_enable(mEp->udc, mEp->num, mEp->dir, mEp->type);
spin_unlock_irqrestore(mEp->lock, flags);
return retval;
}
static int ep_disable(struct usb_ep *ep)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
int direction, retval = 0;
unsigned long flags;
if (ep == NULL)
return -EINVAL;
else if (mEp->ep.desc == NULL)
return -EBUSY;
spin_lock_irqsave(mEp->lock, flags);
direction = mEp->dir;
do {
dbg_event(_usb_addr(mEp), "DISABLE", 0);
retval |= _ep_nuke(mEp);
retval |= hw_ep_disable(mEp->udc, mEp->num, mEp->dir);
if (mEp->type == USB_ENDPOINT_XFER_CONTROL)
mEp->dir = (mEp->dir == TX) ? RX : TX;
} while (mEp->dir != direction);
mEp->ep.desc = NULL;
spin_unlock_irqrestore(mEp->lock, flags);
return retval;
}
static struct usb_request *ep_alloc_request(struct usb_ep *ep, gfp_t gfp_flags)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
struct ci13xxx_req *mReq = NULL;
if (ep == NULL)
return NULL;
mReq = kzalloc(sizeof(struct ci13xxx_req), gfp_flags);
if (mReq != NULL) {
INIT_LIST_HEAD(&mReq->queue);
mReq->ptr = dma_pool_alloc(mEp->td_pool, gfp_flags,
&mReq->dma);
if (mReq->ptr == NULL) {
kfree(mReq);
mReq = NULL;
}
}
dbg_event(_usb_addr(mEp), "ALLOC", mReq == NULL);
return (mReq == NULL) ? NULL : &mReq->req;
}
static void ep_free_request(struct usb_ep *ep, struct usb_request *req)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
struct ci13xxx_req *mReq = container_of(req, struct ci13xxx_req, req);
unsigned long flags;
if (ep == NULL || req == NULL) {
return;
} else if (!list_empty(&mReq->queue)) {
dev_err(mEp->udc->dev, "freeing queued request\n");
return;
}
spin_lock_irqsave(mEp->lock, flags);
if (mReq->ptr)
dma_pool_free(mEp->td_pool, mReq->ptr, mReq->dma);
kfree(mReq);
dbg_event(_usb_addr(mEp), "FREE", 0);
spin_unlock_irqrestore(mEp->lock, flags);
}
static int ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t __maybe_unused gfp_flags)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
struct ci13xxx_req *mReq = container_of(req, struct ci13xxx_req, req);
struct ci13xxx *udc = mEp->udc;
int retval = 0;
unsigned long flags;
if (ep == NULL || req == NULL || mEp->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
if (mEp->type == USB_ENDPOINT_XFER_CONTROL) {
if (req->length)
mEp = (udc->ep0_dir == RX) ?
udc->ep0out : udc->ep0in;
if (!list_empty(&mEp->qh.queue)) {
_ep_nuke(mEp);
retval = -EOVERFLOW;
dev_warn(mEp->udc->dev, "endpoint ctrl %X nuked\n",
_usb_addr(mEp));
}
}
if (!list_empty(&mReq->queue)) {
retval = -EBUSY;
dev_err(mEp->udc->dev, "request already in queue\n");
goto done;
}
if (req->length > 4 * CI13XXX_PAGE_SIZE) {
req->length = 4 * CI13XXX_PAGE_SIZE;
retval = -EMSGSIZE;
dev_warn(mEp->udc->dev, "request length truncated\n");
}
dbg_queue(_usb_addr(mEp), req, retval);
mReq->req.status = -EINPROGRESS;
mReq->req.actual = 0;
retval = _hardware_enqueue(mEp, mReq);
if (retval == -EALREADY) {
dbg_event(_usb_addr(mEp), "QUEUE", retval);
retval = 0;
}
if (!retval)
list_add_tail(&mReq->queue, &mEp->qh.queue);
done:
spin_unlock_irqrestore(mEp->lock, flags);
return retval;
}
static int ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
struct ci13xxx_req *mReq = container_of(req, struct ci13xxx_req, req);
unsigned long flags;
if (ep == NULL || req == NULL || mReq->req.status != -EALREADY ||
mEp->ep.desc == NULL || list_empty(&mReq->queue) ||
list_empty(&mEp->qh.queue))
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
dbg_event(_usb_addr(mEp), "DEQUEUE", 0);
hw_ep_flush(mEp->udc, mEp->num, mEp->dir);
list_del_init(&mReq->queue);
usb_gadget_unmap_request(&mEp->udc->gadget, req, mEp->dir);
req->status = -ECONNRESET;
if (mReq->req.complete != NULL) {
spin_unlock(mEp->lock);
mReq->req.complete(&mEp->ep, &mReq->req);
spin_lock(mEp->lock);
}
spin_unlock_irqrestore(mEp->lock, flags);
return 0;
}
static int ep_set_halt(struct usb_ep *ep, int value)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
int direction, retval = 0;
unsigned long flags;
if (ep == NULL || mEp->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
#ifndef STALL_IN
if (value && mEp->type == USB_ENDPOINT_XFER_BULK && mEp->dir == TX &&
!list_empty(&mEp->qh.queue)) {
spin_unlock_irqrestore(mEp->lock, flags);
return -EAGAIN;
}
#endif
direction = mEp->dir;
do {
dbg_event(_usb_addr(mEp), "HALT", value);
retval |= hw_ep_set_halt(mEp->udc, mEp->num, mEp->dir, value);
if (!value)
mEp->wedge = 0;
if (mEp->type == USB_ENDPOINT_XFER_CONTROL)
mEp->dir = (mEp->dir == TX) ? RX : TX;
} while (mEp->dir != direction);
spin_unlock_irqrestore(mEp->lock, flags);
return retval;
}
static int ep_set_wedge(struct usb_ep *ep)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
unsigned long flags;
if (ep == NULL || mEp->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
dbg_event(_usb_addr(mEp), "WEDGE", 0);
mEp->wedge = 1;
spin_unlock_irqrestore(mEp->lock, flags);
return usb_ep_set_halt(ep);
}
static void ep_fifo_flush(struct usb_ep *ep)
{
struct ci13xxx_ep *mEp = container_of(ep, struct ci13xxx_ep, ep);
unsigned long flags;
if (ep == NULL) {
dev_err(mEp->udc->dev, "%02X: -EINVAL\n", _usb_addr(mEp));
return;
}
spin_lock_irqsave(mEp->lock, flags);
dbg_event(_usb_addr(mEp), "FFLUSH", 0);
hw_ep_flush(mEp->udc, mEp->num, mEp->dir);
spin_unlock_irqrestore(mEp->lock, flags);
}
static int ci13xxx_vbus_session(struct usb_gadget *_gadget, int is_active)
{
struct ci13xxx *udc = container_of(_gadget, struct ci13xxx, gadget);
unsigned long flags;
int gadget_ready = 0;
if (!(udc->udc_driver->flags & CI13XXX_PULLUP_ON_VBUS))
return -EOPNOTSUPP;
spin_lock_irqsave(&udc->lock, flags);
udc->vbus_active = is_active;
if (udc->driver)
gadget_ready = 1;
spin_unlock_irqrestore(&udc->lock, flags);
if (gadget_ready) {
if (is_active) {
pm_runtime_get_sync(&_gadget->dev);
hw_device_reset(udc, USBMODE_CM_DC);
hw_device_state(udc, udc->ep0out->qh.dma);
} else {
hw_device_state(udc, 0);
if (udc->udc_driver->notify_event)
udc->udc_driver->notify_event(udc,
CI13XXX_CONTROLLER_STOPPED_EVENT);
_gadget_stop_activity(&udc->gadget);
pm_runtime_put_sync(&_gadget->dev);
}
}
return 0;
}
static int ci13xxx_wakeup(struct usb_gadget *_gadget)
{
struct ci13xxx *udc = container_of(_gadget, struct ci13xxx, gadget);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&udc->lock, flags);
if (!udc->remote_wakeup) {
ret = -EOPNOTSUPP;
goto out;
}
if (!hw_read(udc, OP_PORTSC, PORTSC_SUSP)) {
ret = -EINVAL;
goto out;
}
hw_write(udc, OP_PORTSC, PORTSC_FPR, PORTSC_FPR);
out:
spin_unlock_irqrestore(&udc->lock, flags);
return ret;
}
static int ci13xxx_vbus_draw(struct usb_gadget *_gadget, unsigned mA)
{
struct ci13xxx *udc = container_of(_gadget, struct ci13xxx, gadget);
if (udc->transceiver)
return usb_phy_set_power(udc->transceiver, mA);
return -ENOTSUPP;
}
static int init_eps(struct ci13xxx *udc)
{
int retval = 0, i, j;
for (i = 0; i < udc->hw_ep_max/2; i++)
for (j = RX; j <= TX; j++) {
int k = i + j * udc->hw_ep_max/2;
struct ci13xxx_ep *mEp = &udc->ci13xxx_ep[k];
scnprintf(mEp->name, sizeof(mEp->name), "ep%i%s", i,
(j == TX) ? "in" : "out");
mEp->udc = udc;
mEp->lock = &udc->lock;
mEp->td_pool = udc->td_pool;
mEp->ep.name = mEp->name;
mEp->ep.ops = &usb_ep_ops;
mEp->ep.maxpacket = CTRL_PAYLOAD_MAX;
INIT_LIST_HEAD(&mEp->qh.queue);
mEp->qh.ptr = dma_pool_alloc(udc->qh_pool, GFP_KERNEL,
&mEp->qh.dma);
if (mEp->qh.ptr == NULL)
retval = -ENOMEM;
else
memset(mEp->qh.ptr, 0, sizeof(*mEp->qh.ptr));
if (i == 0) {
if (j == RX)
udc->ep0out = mEp;
else
udc->ep0in = mEp;
continue;
}
list_add_tail(&mEp->ep.ep_list, &udc->gadget.ep_list);
}
return retval;
}
static int ci13xxx_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct ci13xxx *udc = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
int retval = -ENOMEM;
if (driver->disconnect == NULL)
return -EINVAL;
udc->ep0out->ep.desc = &ctrl_endpt_out_desc;
retval = usb_ep_enable(&udc->ep0out->ep);
if (retval)
return retval;
udc->ep0in->ep.desc = &ctrl_endpt_in_desc;
retval = usb_ep_enable(&udc->ep0in->ep);
if (retval)
return retval;
spin_lock_irqsave(&udc->lock, flags);
udc->driver = driver;
pm_runtime_get_sync(&udc->gadget.dev);
if (udc->udc_driver->flags & CI13XXX_PULLUP_ON_VBUS) {
if (udc->vbus_active) {
if (udc->udc_driver->flags & CI13XXX_REGS_SHARED)
hw_device_reset(udc, USBMODE_CM_DC);
} else {
pm_runtime_put_sync(&udc->gadget.dev);
goto done;
}
}
retval = hw_device_state(udc, udc->ep0out->qh.dma);
if (retval)
pm_runtime_put_sync(&udc->gadget.dev);
done:
spin_unlock_irqrestore(&udc->lock, flags);
return retval;
}
static int ci13xxx_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct ci13xxx *udc = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
if (!(udc->udc_driver->flags & CI13XXX_PULLUP_ON_VBUS) ||
udc->vbus_active) {
hw_device_state(udc, 0);
if (udc->udc_driver->notify_event)
udc->udc_driver->notify_event(udc,
CI13XXX_CONTROLLER_STOPPED_EVENT);
udc->driver = NULL;
spin_unlock_irqrestore(&udc->lock, flags);
_gadget_stop_activity(&udc->gadget);
spin_lock_irqsave(&udc->lock, flags);
pm_runtime_put(&udc->gadget.dev);
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static irqreturn_t udc_irq(struct ci13xxx *udc)
{
irqreturn_t retval;
u32 intr;
if (udc == NULL)
return IRQ_HANDLED;
spin_lock(&udc->lock);
if (udc->udc_driver->flags & CI13XXX_REGS_SHARED) {
if (hw_read(udc, OP_USBMODE, USBMODE_CM) !=
USBMODE_CM_DC) {
spin_unlock(&udc->lock);
return IRQ_NONE;
}
}
intr = hw_test_and_clear_intr_active(udc);
dbg_interrupt(intr);
if (intr) {
if (USBi_URI & intr)
isr_reset_handler(udc);
if (USBi_PCI & intr) {
udc->gadget.speed = hw_port_is_high_speed(udc) ?
USB_SPEED_HIGH : USB_SPEED_FULL;
if (udc->suspended && udc->driver->resume) {
spin_unlock(&udc->lock);
udc->driver->resume(&udc->gadget);
spin_lock(&udc->lock);
udc->suspended = 0;
}
}
if (USBi_UI & intr)
isr_tr_complete_handler(udc);
if (USBi_SLI & intr) {
if (udc->gadget.speed != USB_SPEED_UNKNOWN &&
udc->driver->suspend) {
udc->suspended = 1;
spin_unlock(&udc->lock);
udc->driver->suspend(&udc->gadget);
spin_lock(&udc->lock);
}
}
retval = IRQ_HANDLED;
} else {
retval = IRQ_NONE;
}
spin_unlock(&udc->lock);
return retval;
}
static void udc_release(struct device *dev)
{
}
static int udc_start(struct ci13xxx *udc)
{
struct device *dev = udc->dev;
int retval = 0;
if (!udc)
return -EINVAL;
spin_lock_init(&udc->lock);
udc->gadget.ops = &usb_gadget_ops;
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->gadget.max_speed = USB_SPEED_HIGH;
udc->gadget.is_otg = 0;
udc->gadget.name = udc->udc_driver->name;
INIT_LIST_HEAD(&udc->gadget.ep_list);
dev_set_name(&udc->gadget.dev, "gadget");
udc->gadget.dev.dma_mask = dev->dma_mask;
udc->gadget.dev.coherent_dma_mask = dev->coherent_dma_mask;
udc->gadget.dev.parent = dev;
udc->gadget.dev.release = udc_release;
udc->qh_pool = dma_pool_create("ci13xxx_qh", dev,
sizeof(struct ci13xxx_qh),
64, CI13XXX_PAGE_SIZE);
if (udc->qh_pool == NULL)
return -ENOMEM;
udc->td_pool = dma_pool_create("ci13xxx_td", dev,
sizeof(struct ci13xxx_td),
64, CI13XXX_PAGE_SIZE);
if (udc->td_pool == NULL) {
retval = -ENOMEM;
goto free_qh_pool;
}
retval = init_eps(udc);
if (retval)
goto free_pools;
udc->gadget.ep0 = &udc->ep0in->ep;
udc->transceiver = usb_get_transceiver();
if (udc->udc_driver->flags & CI13XXX_REQUIRE_TRANSCEIVER) {
if (udc->transceiver == NULL) {
retval = -ENODEV;
goto free_pools;
}
}
if (!(udc->udc_driver->flags & CI13XXX_REGS_SHARED)) {
retval = hw_device_reset(udc, USBMODE_CM_DC);
if (retval)
goto put_transceiver;
}
retval = device_register(&udc->gadget.dev);
if (retval) {
put_device(&udc->gadget.dev);
goto put_transceiver;
}
retval = dbg_create_files(&udc->gadget.dev);
if (retval)
goto unreg_device;
if (udc->transceiver) {
retval = otg_set_peripheral(udc->transceiver->otg,
&udc->gadget);
if (retval)
goto remove_dbg;
}
retval = usb_add_gadget_udc(dev, &udc->gadget);
if (retval)
goto remove_trans;
pm_runtime_no_callbacks(&udc->gadget.dev);
pm_runtime_enable(&udc->gadget.dev);
return retval;
remove_trans:
if (udc->transceiver) {
otg_set_peripheral(udc->transceiver->otg, &udc->gadget);
usb_put_transceiver(udc->transceiver);
}
dev_err(dev, "error = %i\n", retval);
remove_dbg:
dbg_remove_files(&udc->gadget.dev);
unreg_device:
device_unregister(&udc->gadget.dev);
put_transceiver:
if (udc->transceiver)
usb_put_transceiver(udc->transceiver);
free_pools:
dma_pool_destroy(udc->td_pool);
free_qh_pool:
dma_pool_destroy(udc->qh_pool);
return retval;
}
static void udc_stop(struct ci13xxx *udc)
{
int i;
if (udc == NULL)
return;
usb_del_gadget_udc(&udc->gadget);
for (i = 0; i < udc->hw_ep_max; i++) {
struct ci13xxx_ep *mEp = &udc->ci13xxx_ep[i];
dma_pool_free(udc->qh_pool, mEp->qh.ptr, mEp->qh.dma);
}
dma_pool_destroy(udc->td_pool);
dma_pool_destroy(udc->qh_pool);
if (udc->transceiver) {
otg_set_peripheral(udc->transceiver->otg, NULL);
usb_put_transceiver(udc->transceiver);
}
dbg_remove_files(&udc->gadget.dev);
device_unregister(&udc->gadget.dev);
memset(&udc->gadget, 0, sizeof(udc->gadget));
}
int ci_hdrc_gadget_init(struct ci13xxx *ci)
{
struct ci_role_driver *rdrv;
if (!hw_read(ci, CAP_DCCPARAMS, DCCPARAMS_DC))
return -ENXIO;
rdrv = devm_kzalloc(ci->dev, sizeof(struct ci_role_driver), GFP_KERNEL);
if (!rdrv)
return -ENOMEM;
rdrv->start = udc_start;
rdrv->stop = udc_stop;
rdrv->irq = udc_irq;
rdrv->name = "gadget";
ci->roles[CI_ROLE_GADGET] = rdrv;
return 0;
}
