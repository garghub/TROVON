static inline int hw_ep_bit(int num, int dir)
{
return num + (dir ? 16 : 0);
}
static inline int ep_to_bit(struct ci13xxx *ci, int n)
{
int fill = 16 - ci->hw_ep_max / 2;
if (n >= ci->hw_ep_max / 2)
n += fill;
return n;
}
static int hw_device_state(struct ci13xxx *ci, u32 dma)
{
if (dma) {
hw_write(ci, OP_ENDPTLISTADDR, ~0, dma);
hw_write(ci, OP_USBINTR, ~0,
USBi_UI|USBi_UEI|USBi_PCI|USBi_URI|USBi_SLI);
} else {
hw_write(ci, OP_USBINTR, ~0, 0);
}
return 0;
}
static int hw_ep_flush(struct ci13xxx *ci, int num, int dir)
{
int n = hw_ep_bit(num, dir);
do {
hw_write(ci, OP_ENDPTFLUSH, BIT(n), BIT(n));
while (hw_read(ci, OP_ENDPTFLUSH, BIT(n)))
cpu_relax();
} while (hw_read(ci, OP_ENDPTSTAT, BIT(n)));
return 0;
}
static int hw_ep_disable(struct ci13xxx *ci, int num, int dir)
{
hw_ep_flush(ci, num, dir);
hw_write(ci, OP_ENDPTCTRL + num,
dir ? ENDPTCTRL_TXE : ENDPTCTRL_RXE, 0);
return 0;
}
static int hw_ep_enable(struct ci13xxx *ci, int num, int dir, int type)
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
hw_write(ci, OP_ENDPTCTRL + num, mask, data);
return 0;
}
static int hw_ep_get_halt(struct ci13xxx *ci, int num, int dir)
{
u32 mask = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
return hw_read(ci, OP_ENDPTCTRL + num, mask) ? 1 : 0;
}
static int hw_test_and_clear_setup_status(struct ci13xxx *ci, int n)
{
n = ep_to_bit(ci, n);
return hw_test_and_clear(ci, OP_ENDPTSETUPSTAT, BIT(n));
}
static int hw_ep_prime(struct ci13xxx *ci, int num, int dir, int is_ctrl)
{
int n = hw_ep_bit(num, dir);
if (is_ctrl && dir == RX && hw_read(ci, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
hw_write(ci, OP_ENDPTPRIME, BIT(n), BIT(n));
while (hw_read(ci, OP_ENDPTPRIME, BIT(n)))
cpu_relax();
if (is_ctrl && dir == RX && hw_read(ci, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
return 0;
}
static int hw_ep_set_halt(struct ci13xxx *ci, int num, int dir, int value)
{
if (value != 0 && value != 1)
return -EINVAL;
do {
enum ci13xxx_regs reg = OP_ENDPTCTRL + num;
u32 mask_xs = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
u32 mask_xr = dir ? ENDPTCTRL_TXR : ENDPTCTRL_RXR;
hw_write(ci, reg, mask_xs|mask_xr,
value ? mask_xs : mask_xr);
} while (value != hw_ep_get_halt(ci, num, dir));
return 0;
}
static int hw_port_is_high_speed(struct ci13xxx *ci)
{
return ci->hw_bank.lpm ? hw_read(ci, OP_DEVLC, DEVLC_PSPD) :
hw_read(ci, OP_PORTSC, PORTSC_HSP);
}
static u32 hw_read_intr_enable(struct ci13xxx *ci)
{
return hw_read(ci, OP_USBINTR, ~0);
}
static u32 hw_read_intr_status(struct ci13xxx *ci)
{
return hw_read(ci, OP_USBSTS, ~0);
}
static int hw_test_and_clear_complete(struct ci13xxx *ci, int n)
{
n = ep_to_bit(ci, n);
return hw_test_and_clear(ci, OP_ENDPTCOMPLETE, BIT(n));
}
static u32 hw_test_and_clear_intr_active(struct ci13xxx *ci)
{
u32 reg = hw_read_intr_status(ci) & hw_read_intr_enable(ci);
hw_write(ci, OP_USBSTS, ~0, reg);
return reg;
}
static void hw_enable_vbus_intr(struct ci13xxx *ci)
{
hw_write(ci, OP_OTGSC, OTGSC_AVVIS, OTGSC_AVVIS);
hw_write(ci, OP_OTGSC, OTGSC_AVVIE, OTGSC_AVVIE);
queue_work(ci->wq, &ci->vbus_work);
}
static void hw_disable_vbus_intr(struct ci13xxx *ci)
{
hw_write(ci, OP_OTGSC, OTGSC_AVVIE, 0);
}
static int hw_test_and_clear_setup_guard(struct ci13xxx *ci)
{
return hw_test_and_write(ci, OP_USBCMD, USBCMD_SUTW, 0);
}
static int hw_test_and_set_setup_guard(struct ci13xxx *ci)
{
return hw_test_and_write(ci, OP_USBCMD, USBCMD_SUTW, USBCMD_SUTW);
}
static void hw_usb_set_address(struct ci13xxx *ci, u8 value)
{
hw_write(ci, OP_DEVICEADDR, DEVICEADDR_USBADR,
value << ffs_nr(DEVICEADDR_USBADR));
}
static int hw_usb_reset(struct ci13xxx *ci)
{
hw_usb_set_address(ci, 0);
hw_write(ci, OP_ENDPTFLUSH, ~0, ~0);
hw_write(ci, OP_ENDPTSETUPSTAT, 0, 0);
hw_write(ci, OP_ENDPTCOMPLETE, 0, 0);
while (hw_read(ci, OP_ENDPTPRIME, ~0))
udelay(10);
return 0;
}
static void vbus_work(struct work_struct *work)
{
struct ci13xxx *ci = container_of(work, struct ci13xxx, vbus_work);
if (hw_read(ci, OP_OTGSC, OTGSC_AVV))
usb_gadget_vbus_connect(&ci->gadget);
else
usb_gadget_vbus_disconnect(&ci->gadget);
}
static inline u8 _usb_addr(struct ci13xxx_ep *ep)
{
return ((ep->dir == TX) ? USB_ENDPOINT_DIR_MASK : 0) | ep->num;
}
static int _hardware_enqueue(struct ci13xxx_ep *mEp, struct ci13xxx_req *mReq)
{
struct ci13xxx *ci = mEp->ci;
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
ret = usb_gadget_map_request(&ci->gadget, &mReq->req, mEp->dir);
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
if (hw_read(ci, OP_ENDPTPRIME, BIT(n)))
goto done;
do {
hw_write(ci, OP_USBCMD, USBCMD_ATDTW, USBCMD_ATDTW);
tmp_stat = hw_read(ci, OP_ENDPTSTAT, BIT(n));
} while (!hw_read(ci, OP_USBCMD, USBCMD_ATDTW));
hw_write(ci, OP_USBCMD, USBCMD_ATDTW, 0);
if (tmp_stat)
goto done;
}
mEp->qh.ptr->td.next = mReq->dma;
mEp->qh.ptr->td.token &= ~TD_STATUS;
mEp->qh.ptr->cap |= QH_ZLT;
wmb();
ret = hw_ep_prime(ci, mEp->num, mEp->dir,
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
usb_gadget_unmap_request(&mEp->ci->gadget, &mReq->req, mEp->dir);
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
hw_ep_flush(mEp->ci, mEp->num, mEp->dir);
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
struct ci13xxx *ci = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
spin_lock_irqsave(&ci->lock, flags);
ci->gadget.speed = USB_SPEED_UNKNOWN;
ci->remote_wakeup = 0;
ci->suspended = 0;
spin_unlock_irqrestore(&ci->lock, flags);
gadget_for_each_ep(ep, gadget) {
usb_ep_fifo_flush(ep);
}
usb_ep_fifo_flush(&ci->ep0out->ep);
usb_ep_fifo_flush(&ci->ep0in->ep);
if (ci->driver)
ci->driver->disconnect(gadget);
gadget_for_each_ep(ep, gadget) {
usb_ep_disable(ep);
}
if (ci->status != NULL) {
usb_ep_free_request(&ci->ep0in->ep, ci->status);
ci->status = NULL;
}
return 0;
}
static void isr_reset_handler(struct ci13xxx *ci)
__releases(ci->lock)
__acquires(ci->lock)
{
int retval;
dbg_event(0xFF, "BUS RST", 0);
spin_unlock(&ci->lock);
retval = _gadget_stop_activity(&ci->gadget);
if (retval)
goto done;
retval = hw_usb_reset(ci);
if (retval)
goto done;
ci->status = usb_ep_alloc_request(&ci->ep0in->ep, GFP_ATOMIC);
if (ci->status == NULL)
retval = -ENOMEM;
done:
spin_lock(&ci->lock);
if (retval)
dev_err(ci->dev, "error: %i\n", retval);
}
static void isr_get_status_complete(struct usb_ep *ep, struct usb_request *req)
{
if (ep == NULL || req == NULL)
return;
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static int isr_get_status_response(struct ci13xxx *ci,
struct usb_ctrlrequest *setup)
__releases(mEp->lock)
__acquires(mEp->lock)
{
struct ci13xxx_ep *mEp = ci->ep0in;
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
*(u16 *)req->buf = ci->remote_wakeup << 1;
retval = 0;
} else if ((setup->bRequestType & USB_RECIP_MASK) \
== USB_RECIP_ENDPOINT) {
dir = (le16_to_cpu(setup->wIndex) & USB_ENDPOINT_DIR_MASK) ?
TX : RX;
num = le16_to_cpu(setup->wIndex) & USB_ENDPOINT_NUMBER_MASK;
*(u16 *)req->buf = hw_ep_get_halt(ci, num, dir);
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
struct ci13xxx *ci = req->context;
unsigned long flags;
if (ci->setaddr) {
hw_usb_set_address(ci, ci->address);
ci->setaddr = false;
}
spin_lock_irqsave(&ci->lock, flags);
if (ci->test_mode)
hw_port_test_set(ci, ci->test_mode);
spin_unlock_irqrestore(&ci->lock, flags);
}
static int isr_setup_status_phase(struct ci13xxx *ci)
__releases(mEp->lock)
__acquires(mEp->lock)
{
int retval;
struct ci13xxx_ep *mEp;
mEp = (ci->ep0_dir == TX) ? ci->ep0out : ci->ep0in;
ci->status->context = ci;
ci->status->complete = isr_setup_status_complete;
spin_unlock(mEp->lock);
retval = usb_ep_queue(&mEp->ep, ci->status, GFP_ATOMIC);
spin_lock(mEp->lock);
return retval;
}
static int isr_tr_complete_low(struct ci13xxx_ep *mEp)
__releases(mEp->lock)
__acquires(mEp->lock)
{
struct ci13xxx_req *mReq, *mReqTemp;
struct ci13xxx_ep *mEpTemp = mEp;
int retval = 0;
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
mEpTemp = mEp->ci->ep0in;
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
static void isr_tr_complete_handler(struct ci13xxx *ci)
__releases(ci->lock)
__acquires(ci->lock)
{
unsigned i;
u8 tmode = 0;
for (i = 0; i < ci->hw_ep_max; i++) {
struct ci13xxx_ep *mEp = &ci->ci13xxx_ep[i];
int type, num, dir, err = -EINVAL;
struct usb_ctrlrequest req;
if (mEp->ep.desc == NULL)
continue;
if (hw_test_and_clear_complete(ci, i)) {
err = isr_tr_complete_low(mEp);
if (mEp->type == USB_ENDPOINT_XFER_CONTROL) {
if (err > 0)
err = isr_setup_status_phase(ci);
if (err < 0) {
dbg_event(_usb_addr(mEp),
"ERROR", err);
spin_unlock(&ci->lock);
if (usb_ep_set_halt(&mEp->ep))
dev_err(ci->dev,
"error: ep_set_halt\n");
spin_lock(&ci->lock);
}
}
}
if (mEp->type != USB_ENDPOINT_XFER_CONTROL ||
!hw_test_and_clear_setup_status(ci, i))
continue;
if (i != 0) {
dev_warn(ci->dev, "ctrl traffic at endpoint %d\n", i);
continue;
}
_ep_nuke(ci->ep0out);
_ep_nuke(ci->ep0in);
do {
hw_test_and_set_setup_guard(ci);
memcpy(&req, &mEp->qh.ptr->setup, sizeof(req));
} while (!hw_test_and_clear_setup_guard(ci));
type = req.bRequestType;
ci->ep0_dir = (type & USB_DIR_IN) ? TX : RX;
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
num += ci->hw_ep_max/2;
if (!ci->ci13xxx_ep[num].wedge) {
spin_unlock(&ci->lock);
err = usb_ep_clear_halt(
&ci->ci13xxx_ep[num].ep);
spin_lock(&ci->lock);
if (err)
break;
}
err = isr_setup_status_phase(ci);
} else if (type == (USB_DIR_OUT|USB_RECIP_DEVICE) &&
le16_to_cpu(req.wValue) ==
USB_DEVICE_REMOTE_WAKEUP) {
if (req.wLength != 0)
break;
ci->remote_wakeup = 0;
err = isr_setup_status_phase(ci);
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
err = isr_get_status_response(ci, &req);
break;
case USB_REQ_SET_ADDRESS:
if (type != (USB_DIR_OUT|USB_RECIP_DEVICE))
goto delegate;
if (le16_to_cpu(req.wLength) != 0 ||
le16_to_cpu(req.wIndex) != 0)
break;
ci->address = (u8)le16_to_cpu(req.wValue);
ci->setaddr = true;
err = isr_setup_status_phase(ci);
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
num += ci->hw_ep_max/2;
spin_unlock(&ci->lock);
err = usb_ep_set_halt(&ci->ci13xxx_ep[num].ep);
spin_lock(&ci->lock);
if (!err)
isr_setup_status_phase(ci);
} else if (type == (USB_DIR_OUT|USB_RECIP_DEVICE)) {
if (req.wLength != 0)
break;
switch (le16_to_cpu(req.wValue)) {
case USB_DEVICE_REMOTE_WAKEUP:
ci->remote_wakeup = 1;
err = isr_setup_status_phase(ci);
break;
case USB_DEVICE_TEST_MODE:
tmode = le16_to_cpu(req.wIndex) >> 8;
switch (tmode) {
case TEST_J:
case TEST_K:
case TEST_SE0_NAK:
case TEST_PACKET:
case TEST_FORCE_EN:
ci->test_mode = tmode;
err = isr_setup_status_phase(
ci);
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
ci->ep0_dir = TX;
spin_unlock(&ci->lock);
err = ci->driver->setup(&ci->gadget, &req);
spin_lock(&ci->lock);
break;
}
if (err < 0) {
dbg_event(_usb_addr(mEp), "ERROR", err);
spin_unlock(&ci->lock);
if (usb_ep_set_halt(&mEp->ep))
dev_err(ci->dev, "error: ep_set_halt\n");
spin_lock(&ci->lock);
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
dev_warn(mEp->ci->dev, "enabling a non-empty endpoint!\n");
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
retval |= hw_ep_enable(mEp->ci, mEp->num, mEp->dir, mEp->type);
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
retval |= hw_ep_disable(mEp->ci, mEp->num, mEp->dir);
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
dev_err(mEp->ci->dev, "freeing queued request\n");
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
struct ci13xxx *ci = mEp->ci;
int retval = 0;
unsigned long flags;
if (ep == NULL || req == NULL || mEp->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(mEp->lock, flags);
if (mEp->type == USB_ENDPOINT_XFER_CONTROL) {
if (req->length)
mEp = (ci->ep0_dir == RX) ?
ci->ep0out : ci->ep0in;
if (!list_empty(&mEp->qh.queue)) {
_ep_nuke(mEp);
retval = -EOVERFLOW;
dev_warn(mEp->ci->dev, "endpoint ctrl %X nuked\n",
_usb_addr(mEp));
}
}
if (!list_empty(&mReq->queue)) {
retval = -EBUSY;
dev_err(mEp->ci->dev, "request already in queue\n");
goto done;
}
if (req->length > 4 * CI13XXX_PAGE_SIZE) {
req->length = 4 * CI13XXX_PAGE_SIZE;
retval = -EMSGSIZE;
dev_warn(mEp->ci->dev, "request length truncated\n");
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
hw_ep_flush(mEp->ci, mEp->num, mEp->dir);
list_del_init(&mReq->queue);
usb_gadget_unmap_request(&mEp->ci->gadget, req, mEp->dir);
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
retval |= hw_ep_set_halt(mEp->ci, mEp->num, mEp->dir, value);
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
dev_err(mEp->ci->dev, "%02X: -EINVAL\n", _usb_addr(mEp));
return;
}
spin_lock_irqsave(mEp->lock, flags);
dbg_event(_usb_addr(mEp), "FFLUSH", 0);
hw_ep_flush(mEp->ci, mEp->num, mEp->dir);
spin_unlock_irqrestore(mEp->lock, flags);
}
static int ci13xxx_vbus_session(struct usb_gadget *_gadget, int is_active)
{
struct ci13xxx *ci = container_of(_gadget, struct ci13xxx, gadget);
unsigned long flags;
int gadget_ready = 0;
if (!(ci->platdata->flags & CI13XXX_PULLUP_ON_VBUS))
return -EOPNOTSUPP;
spin_lock_irqsave(&ci->lock, flags);
ci->vbus_active = is_active;
if (ci->driver)
gadget_ready = 1;
spin_unlock_irqrestore(&ci->lock, flags);
if (gadget_ready) {
if (is_active) {
pm_runtime_get_sync(&_gadget->dev);
hw_device_reset(ci, USBMODE_CM_DC);
hw_enable_vbus_intr(ci);
hw_device_state(ci, ci->ep0out->qh.dma);
} else {
hw_device_state(ci, 0);
if (ci->platdata->notify_event)
ci->platdata->notify_event(ci,
CI13XXX_CONTROLLER_STOPPED_EVENT);
_gadget_stop_activity(&ci->gadget);
pm_runtime_put_sync(&_gadget->dev);
}
}
return 0;
}
static int ci13xxx_wakeup(struct usb_gadget *_gadget)
{
struct ci13xxx *ci = container_of(_gadget, struct ci13xxx, gadget);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&ci->lock, flags);
if (!ci->remote_wakeup) {
ret = -EOPNOTSUPP;
goto out;
}
if (!hw_read(ci, OP_PORTSC, PORTSC_SUSP)) {
ret = -EINVAL;
goto out;
}
hw_write(ci, OP_PORTSC, PORTSC_FPR, PORTSC_FPR);
out:
spin_unlock_irqrestore(&ci->lock, flags);
return ret;
}
static int ci13xxx_vbus_draw(struct usb_gadget *_gadget, unsigned mA)
{
struct ci13xxx *ci = container_of(_gadget, struct ci13xxx, gadget);
if (ci->transceiver)
return usb_phy_set_power(ci->transceiver, mA);
return -ENOTSUPP;
}
static int ci13xxx_pullup(struct usb_gadget *_gadget, int is_on)
{
struct ci13xxx *ci = container_of(_gadget, struct ci13xxx, gadget);
if (is_on)
hw_write(ci, OP_USBCMD, USBCMD_RS, USBCMD_RS);
else
hw_write(ci, OP_USBCMD, USBCMD_RS, 0);
return 0;
}
static int init_eps(struct ci13xxx *ci)
{
int retval = 0, i, j;
for (i = 0; i < ci->hw_ep_max/2; i++)
for (j = RX; j <= TX; j++) {
int k = i + j * ci->hw_ep_max/2;
struct ci13xxx_ep *mEp = &ci->ci13xxx_ep[k];
scnprintf(mEp->name, sizeof(mEp->name), "ep%i%s", i,
(j == TX) ? "in" : "out");
mEp->ci = ci;
mEp->lock = &ci->lock;
mEp->td_pool = ci->td_pool;
mEp->ep.name = mEp->name;
mEp->ep.ops = &usb_ep_ops;
mEp->ep.maxpacket = (unsigned short)~0;
INIT_LIST_HEAD(&mEp->qh.queue);
mEp->qh.ptr = dma_pool_alloc(ci->qh_pool, GFP_KERNEL,
&mEp->qh.dma);
if (mEp->qh.ptr == NULL)
retval = -ENOMEM;
else
memset(mEp->qh.ptr, 0, sizeof(*mEp->qh.ptr));
if (i == 0) {
if (j == RX)
ci->ep0out = mEp;
else
ci->ep0in = mEp;
mEp->ep.maxpacket = CTRL_PAYLOAD_MAX;
continue;
}
list_add_tail(&mEp->ep.ep_list, &ci->gadget.ep_list);
}
return retval;
}
static void destroy_eps(struct ci13xxx *ci)
{
int i;
for (i = 0; i < ci->hw_ep_max; i++) {
struct ci13xxx_ep *mEp = &ci->ci13xxx_ep[i];
dma_pool_free(ci->qh_pool, mEp->qh.ptr, mEp->qh.dma);
}
}
static int ci13xxx_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct ci13xxx *ci = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
int retval = -ENOMEM;
if (driver->disconnect == NULL)
return -EINVAL;
ci->ep0out->ep.desc = &ctrl_endpt_out_desc;
retval = usb_ep_enable(&ci->ep0out->ep);
if (retval)
return retval;
ci->ep0in->ep.desc = &ctrl_endpt_in_desc;
retval = usb_ep_enable(&ci->ep0in->ep);
if (retval)
return retval;
spin_lock_irqsave(&ci->lock, flags);
ci->driver = driver;
pm_runtime_get_sync(&ci->gadget.dev);
if (ci->platdata->flags & CI13XXX_PULLUP_ON_VBUS) {
if (ci->vbus_active) {
if (ci->platdata->flags & CI13XXX_REGS_SHARED) {
hw_device_reset(ci, USBMODE_CM_DC);
hw_enable_vbus_intr(ci);
}
} else {
pm_runtime_put_sync(&ci->gadget.dev);
goto done;
}
}
retval = hw_device_state(ci, ci->ep0out->qh.dma);
if (retval)
pm_runtime_put_sync(&ci->gadget.dev);
done:
spin_unlock_irqrestore(&ci->lock, flags);
return retval;
}
static int ci13xxx_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct ci13xxx *ci = container_of(gadget, struct ci13xxx, gadget);
unsigned long flags;
spin_lock_irqsave(&ci->lock, flags);
if (!(ci->platdata->flags & CI13XXX_PULLUP_ON_VBUS) ||
ci->vbus_active) {
hw_device_state(ci, 0);
if (ci->platdata->notify_event)
ci->platdata->notify_event(ci,
CI13XXX_CONTROLLER_STOPPED_EVENT);
ci->driver = NULL;
spin_unlock_irqrestore(&ci->lock, flags);
_gadget_stop_activity(&ci->gadget);
spin_lock_irqsave(&ci->lock, flags);
pm_runtime_put(&ci->gadget.dev);
}
spin_unlock_irqrestore(&ci->lock, flags);
return 0;
}
static irqreturn_t udc_irq(struct ci13xxx *ci)
{
irqreturn_t retval;
u32 intr;
if (ci == NULL)
return IRQ_HANDLED;
spin_lock(&ci->lock);
if (ci->platdata->flags & CI13XXX_REGS_SHARED) {
if (hw_read(ci, OP_USBMODE, USBMODE_CM) !=
USBMODE_CM_DC) {
spin_unlock(&ci->lock);
return IRQ_NONE;
}
}
intr = hw_test_and_clear_intr_active(ci);
dbg_interrupt(intr);
if (intr) {
if (USBi_URI & intr)
isr_reset_handler(ci);
if (USBi_PCI & intr) {
ci->gadget.speed = hw_port_is_high_speed(ci) ?
USB_SPEED_HIGH : USB_SPEED_FULL;
if (ci->suspended && ci->driver->resume) {
spin_unlock(&ci->lock);
ci->driver->resume(&ci->gadget);
spin_lock(&ci->lock);
ci->suspended = 0;
}
}
if (USBi_UI & intr)
isr_tr_complete_handler(ci);
if (USBi_SLI & intr) {
if (ci->gadget.speed != USB_SPEED_UNKNOWN &&
ci->driver->suspend) {
ci->suspended = 1;
spin_unlock(&ci->lock);
ci->driver->suspend(&ci->gadget);
spin_lock(&ci->lock);
}
}
retval = IRQ_HANDLED;
} else {
retval = IRQ_NONE;
}
intr = hw_read(ci, OP_OTGSC, ~0);
hw_write(ci, OP_OTGSC, ~0, intr);
if (intr & (OTGSC_AVVIE & OTGSC_AVVIS))
queue_work(ci->wq, &ci->vbus_work);
spin_unlock(&ci->lock);
return retval;
}
static void udc_release(struct device *dev)
{
}
static int udc_start(struct ci13xxx *ci)
{
struct device *dev = ci->dev;
int retval = 0;
spin_lock_init(&ci->lock);
ci->gadget.ops = &usb_gadget_ops;
ci->gadget.speed = USB_SPEED_UNKNOWN;
ci->gadget.max_speed = USB_SPEED_HIGH;
ci->gadget.is_otg = 0;
ci->gadget.name = ci->platdata->name;
INIT_LIST_HEAD(&ci->gadget.ep_list);
dev_set_name(&ci->gadget.dev, "gadget");
ci->gadget.dev.dma_mask = dev->dma_mask;
ci->gadget.dev.coherent_dma_mask = dev->coherent_dma_mask;
ci->gadget.dev.parent = dev;
ci->gadget.dev.release = udc_release;
ci->qh_pool = dma_pool_create("ci13xxx_qh", dev,
sizeof(struct ci13xxx_qh),
64, CI13XXX_PAGE_SIZE);
if (ci->qh_pool == NULL)
return -ENOMEM;
ci->td_pool = dma_pool_create("ci13xxx_td", dev,
sizeof(struct ci13xxx_td),
64, CI13XXX_PAGE_SIZE);
if (ci->td_pool == NULL) {
retval = -ENOMEM;
goto free_qh_pool;
}
retval = init_eps(ci);
if (retval)
goto free_pools;
ci->gadget.ep0 = &ci->ep0in->ep;
if (ci->global_phy)
ci->transceiver = usb_get_phy(USB_PHY_TYPE_USB2);
if (ci->platdata->flags & CI13XXX_REQUIRE_TRANSCEIVER) {
if (ci->transceiver == NULL) {
retval = -ENODEV;
goto destroy_eps;
}
}
if (!(ci->platdata->flags & CI13XXX_REGS_SHARED)) {
retval = hw_device_reset(ci, USBMODE_CM_DC);
if (retval)
goto put_transceiver;
hw_enable_vbus_intr(ci);
}
retval = device_register(&ci->gadget.dev);
if (retval) {
put_device(&ci->gadget.dev);
goto put_transceiver;
}
retval = dbg_create_files(&ci->gadget.dev);
if (retval)
goto unreg_device;
if (!IS_ERR_OR_NULL(ci->transceiver)) {
retval = otg_set_peripheral(ci->transceiver->otg,
&ci->gadget);
if (retval)
goto remove_dbg;
}
retval = usb_add_gadget_udc(dev, &ci->gadget);
if (retval)
goto remove_trans;
pm_runtime_no_callbacks(&ci->gadget.dev);
pm_runtime_enable(&ci->gadget.dev);
return retval;
remove_trans:
if (!IS_ERR_OR_NULL(ci->transceiver)) {
otg_set_peripheral(ci->transceiver->otg, NULL);
if (ci->global_phy)
usb_put_phy(ci->transceiver);
}
dev_err(dev, "error = %i\n", retval);
remove_dbg:
dbg_remove_files(&ci->gadget.dev);
unreg_device:
device_unregister(&ci->gadget.dev);
put_transceiver:
if (!IS_ERR_OR_NULL(ci->transceiver) && ci->global_phy)
usb_put_phy(ci->transceiver);
destroy_eps:
destroy_eps(ci);
free_pools:
dma_pool_destroy(ci->td_pool);
free_qh_pool:
dma_pool_destroy(ci->qh_pool);
return retval;
}
static void udc_stop(struct ci13xxx *ci)
{
if (ci == NULL)
return;
hw_disable_vbus_intr(ci);
cancel_work_sync(&ci->vbus_work);
usb_del_gadget_udc(&ci->gadget);
destroy_eps(ci);
dma_pool_destroy(ci->td_pool);
dma_pool_destroy(ci->qh_pool);
if (!IS_ERR_OR_NULL(ci->transceiver)) {
otg_set_peripheral(ci->transceiver->otg, NULL);
if (ci->global_phy)
usb_put_phy(ci->transceiver);
}
dbg_remove_files(&ci->gadget.dev);
device_unregister(&ci->gadget.dev);
memset(&ci->gadget, 0, sizeof(ci->gadget));
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
INIT_WORK(&ci->vbus_work, vbus_work);
return 0;
}
