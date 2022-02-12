static inline int hw_ep_bit(int num, int dir)
{
return num + (dir ? 16 : 0);
}
static inline int ep_to_bit(struct ci_hdrc *ci, int n)
{
int fill = 16 - ci->hw_ep_max / 2;
if (n >= ci->hw_ep_max / 2)
n += fill;
return n;
}
static int hw_device_state(struct ci_hdrc *ci, u32 dma)
{
if (dma) {
hw_write(ci, OP_ENDPTLISTADDR, ~0, dma);
hw_write(ci, OP_USBINTR, ~0,
USBi_UI|USBi_UEI|USBi_PCI|USBi_URI|USBi_SLI);
hw_write(ci, OP_USBCMD, USBCMD_RS, USBCMD_RS);
} else {
hw_write(ci, OP_USBINTR, ~0, 0);
hw_write(ci, OP_USBCMD, USBCMD_RS, 0);
}
return 0;
}
static int hw_ep_flush(struct ci_hdrc *ci, int num, int dir)
{
int n = hw_ep_bit(num, dir);
do {
hw_write(ci, OP_ENDPTFLUSH, ~0, BIT(n));
while (hw_read(ci, OP_ENDPTFLUSH, BIT(n)))
cpu_relax();
} while (hw_read(ci, OP_ENDPTSTAT, BIT(n)));
return 0;
}
static int hw_ep_disable(struct ci_hdrc *ci, int num, int dir)
{
hw_ep_flush(ci, num, dir);
hw_write(ci, OP_ENDPTCTRL + num,
dir ? ENDPTCTRL_TXE : ENDPTCTRL_RXE, 0);
return 0;
}
static int hw_ep_enable(struct ci_hdrc *ci, int num, int dir, int type)
{
u32 mask, data;
if (dir) {
mask = ENDPTCTRL_TXT;
data = type << __ffs(mask);
mask |= ENDPTCTRL_TXS;
mask |= ENDPTCTRL_TXR;
data |= ENDPTCTRL_TXR;
mask |= ENDPTCTRL_TXE;
data |= ENDPTCTRL_TXE;
} else {
mask = ENDPTCTRL_RXT;
data = type << __ffs(mask);
mask |= ENDPTCTRL_RXS;
mask |= ENDPTCTRL_RXR;
data |= ENDPTCTRL_RXR;
mask |= ENDPTCTRL_RXE;
data |= ENDPTCTRL_RXE;
}
hw_write(ci, OP_ENDPTCTRL + num, mask, data);
return 0;
}
static int hw_ep_get_halt(struct ci_hdrc *ci, int num, int dir)
{
u32 mask = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
return hw_read(ci, OP_ENDPTCTRL + num, mask) ? 1 : 0;
}
static int hw_ep_prime(struct ci_hdrc *ci, int num, int dir, int is_ctrl)
{
int n = hw_ep_bit(num, dir);
if (is_ctrl && dir == RX && hw_read(ci, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
hw_write(ci, OP_ENDPTPRIME, ~0, BIT(n));
while (hw_read(ci, OP_ENDPTPRIME, BIT(n)))
cpu_relax();
if (is_ctrl && dir == RX && hw_read(ci, OP_ENDPTSETUPSTAT, BIT(num)))
return -EAGAIN;
return 0;
}
static int hw_ep_set_halt(struct ci_hdrc *ci, int num, int dir, int value)
{
if (value != 0 && value != 1)
return -EINVAL;
do {
enum ci_hw_regs reg = OP_ENDPTCTRL + num;
u32 mask_xs = dir ? ENDPTCTRL_TXS : ENDPTCTRL_RXS;
u32 mask_xr = dir ? ENDPTCTRL_TXR : ENDPTCTRL_RXR;
hw_write(ci, reg, mask_xs|mask_xr,
value ? mask_xs : mask_xr);
} while (value != hw_ep_get_halt(ci, num, dir));
return 0;
}
static int hw_port_is_high_speed(struct ci_hdrc *ci)
{
return ci->hw_bank.lpm ? hw_read(ci, OP_DEVLC, DEVLC_PSPD) :
hw_read(ci, OP_PORTSC, PORTSC_HSP);
}
static int hw_test_and_clear_complete(struct ci_hdrc *ci, int n)
{
n = ep_to_bit(ci, n);
return hw_test_and_clear(ci, OP_ENDPTCOMPLETE, BIT(n));
}
static u32 hw_test_and_clear_intr_active(struct ci_hdrc *ci)
{
u32 reg = hw_read_intr_status(ci) & hw_read_intr_enable(ci);
hw_write(ci, OP_USBSTS, ~0, reg);
return reg;
}
static int hw_test_and_clear_setup_guard(struct ci_hdrc *ci)
{
return hw_test_and_write(ci, OP_USBCMD, USBCMD_SUTW, 0);
}
static int hw_test_and_set_setup_guard(struct ci_hdrc *ci)
{
return hw_test_and_write(ci, OP_USBCMD, USBCMD_SUTW, USBCMD_SUTW);
}
static void hw_usb_set_address(struct ci_hdrc *ci, u8 value)
{
hw_write(ci, OP_DEVICEADDR, DEVICEADDR_USBADR,
value << __ffs(DEVICEADDR_USBADR));
}
static int hw_usb_reset(struct ci_hdrc *ci)
{
hw_usb_set_address(ci, 0);
hw_write(ci, OP_ENDPTFLUSH, ~0, ~0);
hw_write(ci, OP_ENDPTSETUPSTAT, 0, 0);
hw_write(ci, OP_ENDPTCOMPLETE, 0, 0);
while (hw_read(ci, OP_ENDPTPRIME, ~0))
udelay(10);
return 0;
}
static int add_td_to_list(struct ci_hw_ep *hwep, struct ci_hw_req *hwreq,
unsigned length)
{
int i;
u32 temp;
struct td_node *lastnode, *node = kzalloc(sizeof(struct td_node),
GFP_ATOMIC);
if (node == NULL)
return -ENOMEM;
node->ptr = dma_pool_alloc(hwep->td_pool, GFP_ATOMIC,
&node->dma);
if (node->ptr == NULL) {
kfree(node);
return -ENOMEM;
}
memset(node->ptr, 0, sizeof(struct ci_hw_td));
node->ptr->token = cpu_to_le32(length << __ffs(TD_TOTAL_BYTES));
node->ptr->token &= cpu_to_le32(TD_TOTAL_BYTES);
node->ptr->token |= cpu_to_le32(TD_STATUS_ACTIVE);
if (hwep->type == USB_ENDPOINT_XFER_ISOC && hwep->dir == TX) {
u32 mul = hwreq->req.length / hwep->ep.maxpacket;
if (hwreq->req.length == 0
|| hwreq->req.length % hwep->ep.maxpacket)
mul++;
node->ptr->token |= mul << __ffs(TD_MULTO);
}
temp = (u32) (hwreq->req.dma + hwreq->req.actual);
if (length) {
node->ptr->page[0] = cpu_to_le32(temp);
for (i = 1; i < TD_PAGE_COUNT; i++) {
u32 page = temp + i * CI_HDRC_PAGE_SIZE;
page &= ~TD_RESERVED_MASK;
node->ptr->page[i] = cpu_to_le32(page);
}
}
hwreq->req.actual += length;
if (!list_empty(&hwreq->tds)) {
lastnode = list_entry(hwreq->tds.prev,
struct td_node, td);
lastnode->ptr->next = cpu_to_le32(node->dma);
}
INIT_LIST_HEAD(&node->td);
list_add_tail(&node->td, &hwreq->tds);
return 0;
}
static inline u8 _usb_addr(struct ci_hw_ep *ep)
{
return ((ep->dir == TX) ? USB_ENDPOINT_DIR_MASK : 0) | ep->num;
}
static int _hardware_enqueue(struct ci_hw_ep *hwep, struct ci_hw_req *hwreq)
{
struct ci_hdrc *ci = hwep->ci;
int ret = 0;
unsigned rest = hwreq->req.length;
int pages = TD_PAGE_COUNT;
struct td_node *firstnode, *lastnode;
if (hwreq->req.status == -EALREADY)
return -EALREADY;
hwreq->req.status = -EALREADY;
ret = usb_gadget_map_request(&ci->gadget, &hwreq->req, hwep->dir);
if (ret)
return ret;
if (hwreq->req.dma % PAGE_SIZE)
pages--;
if (rest == 0)
add_td_to_list(hwep, hwreq, 0);
while (rest > 0) {
unsigned count = min(hwreq->req.length - hwreq->req.actual,
(unsigned)(pages * CI_HDRC_PAGE_SIZE));
add_td_to_list(hwep, hwreq, count);
rest -= count;
}
if (hwreq->req.zero && hwreq->req.length
&& (hwreq->req.length % hwep->ep.maxpacket == 0))
add_td_to_list(hwep, hwreq, 0);
firstnode = list_first_entry(&hwreq->tds, struct td_node, td);
lastnode = list_entry(hwreq->tds.prev,
struct td_node, td);
lastnode->ptr->next = cpu_to_le32(TD_TERMINATE);
if (!hwreq->req.no_interrupt)
lastnode->ptr->token |= cpu_to_le32(TD_IOC);
wmb();
hwreq->req.actual = 0;
if (!list_empty(&hwep->qh.queue)) {
struct ci_hw_req *hwreqprev;
int n = hw_ep_bit(hwep->num, hwep->dir);
int tmp_stat;
struct td_node *prevlastnode;
u32 next = firstnode->dma & TD_ADDR_MASK;
hwreqprev = list_entry(hwep->qh.queue.prev,
struct ci_hw_req, queue);
prevlastnode = list_entry(hwreqprev->tds.prev,
struct td_node, td);
prevlastnode->ptr->next = cpu_to_le32(next);
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
hwep->qh.ptr->td.next = cpu_to_le32(firstnode->dma);
hwep->qh.ptr->td.token &=
cpu_to_le32(~(TD_STATUS_HALTED|TD_STATUS_ACTIVE));
if (hwep->type == USB_ENDPOINT_XFER_ISOC && hwep->dir == RX) {
u32 mul = hwreq->req.length / hwep->ep.maxpacket;
if (hwreq->req.length == 0
|| hwreq->req.length % hwep->ep.maxpacket)
mul++;
hwep->qh.ptr->cap |= mul << __ffs(QH_MULT);
}
wmb();
ret = hw_ep_prime(ci, hwep->num, hwep->dir,
hwep->type == USB_ENDPOINT_XFER_CONTROL);
done:
return ret;
}
static void free_pending_td(struct ci_hw_ep *hwep)
{
struct td_node *pending = hwep->pending_td;
dma_pool_free(hwep->td_pool, pending->ptr, pending->dma);
hwep->pending_td = NULL;
kfree(pending);
}
static int _hardware_dequeue(struct ci_hw_ep *hwep, struct ci_hw_req *hwreq)
{
u32 tmptoken;
struct td_node *node, *tmpnode;
unsigned remaining_length;
unsigned actual = hwreq->req.length;
if (hwreq->req.status != -EALREADY)
return -EINVAL;
hwreq->req.status = 0;
list_for_each_entry_safe(node, tmpnode, &hwreq->tds, td) {
tmptoken = le32_to_cpu(node->ptr->token);
if ((TD_STATUS_ACTIVE & tmptoken) != 0) {
hwreq->req.status = -EALREADY;
return -EBUSY;
}
remaining_length = (tmptoken & TD_TOTAL_BYTES);
remaining_length >>= __ffs(TD_TOTAL_BYTES);
actual -= remaining_length;
hwreq->req.status = tmptoken & TD_STATUS;
if ((TD_STATUS_HALTED & hwreq->req.status)) {
hwreq->req.status = -EPIPE;
break;
} else if ((TD_STATUS_DT_ERR & hwreq->req.status)) {
hwreq->req.status = -EPROTO;
break;
} else if ((TD_STATUS_TR_ERR & hwreq->req.status)) {
hwreq->req.status = -EILSEQ;
break;
}
if (remaining_length) {
if (hwep->dir) {
hwreq->req.status = -EPROTO;
break;
}
}
if (hwep->pending_td)
free_pending_td(hwep);
hwep->pending_td = node;
list_del_init(&node->td);
}
usb_gadget_unmap_request(&hwep->ci->gadget, &hwreq->req, hwep->dir);
hwreq->req.actual += actual;
if (hwreq->req.status)
return hwreq->req.status;
return hwreq->req.actual;
}
static int _ep_nuke(struct ci_hw_ep *hwep)
__releases(hwep->lock)
__acquires(hwep->lock)
{
struct td_node *node, *tmpnode;
if (hwep == NULL)
return -EINVAL;
hw_ep_flush(hwep->ci, hwep->num, hwep->dir);
while (!list_empty(&hwep->qh.queue)) {
struct ci_hw_req *hwreq = list_entry(hwep->qh.queue.next,
struct ci_hw_req, queue);
list_for_each_entry_safe(node, tmpnode, &hwreq->tds, td) {
dma_pool_free(hwep->td_pool, node->ptr, node->dma);
list_del_init(&node->td);
node->ptr = NULL;
kfree(node);
}
list_del_init(&hwreq->queue);
hwreq->req.status = -ESHUTDOWN;
if (hwreq->req.complete != NULL) {
spin_unlock(hwep->lock);
usb_gadget_giveback_request(&hwep->ep, &hwreq->req);
spin_lock(hwep->lock);
}
}
if (hwep->pending_td)
free_pending_td(hwep);
return 0;
}
static int _gadget_stop_activity(struct usb_gadget *gadget)
{
struct usb_ep *ep;
struct ci_hdrc *ci = container_of(gadget, struct ci_hdrc, gadget);
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
gadget_for_each_ep(ep, gadget) {
usb_ep_disable(ep);
}
if (ci->status != NULL) {
usb_ep_free_request(&ci->ep0in->ep, ci->status);
ci->status = NULL;
}
return 0;
}
static void isr_reset_handler(struct ci_hdrc *ci)
__releases(ci->lock)
__acquires(ci->lock)
{
int retval;
spin_unlock(&ci->lock);
if (ci->gadget.speed != USB_SPEED_UNKNOWN)
usb_gadget_udc_reset(&ci->gadget, ci->driver);
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
static int _ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t __maybe_unused gfp_flags)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
struct ci_hw_req *hwreq = container_of(req, struct ci_hw_req, req);
struct ci_hdrc *ci = hwep->ci;
int retval = 0;
if (ep == NULL || req == NULL || hwep->ep.desc == NULL)
return -EINVAL;
if (hwep->type == USB_ENDPOINT_XFER_CONTROL) {
if (req->length)
hwep = (ci->ep0_dir == RX) ?
ci->ep0out : ci->ep0in;
if (!list_empty(&hwep->qh.queue)) {
_ep_nuke(hwep);
retval = -EOVERFLOW;
dev_warn(hwep->ci->dev, "endpoint ctrl %X nuked\n",
_usb_addr(hwep));
}
}
if (usb_endpoint_xfer_isoc(hwep->ep.desc) &&
hwreq->req.length > (1 + hwep->ep.mult) * hwep->ep.maxpacket) {
dev_err(hwep->ci->dev, "request length too big for isochronous\n");
return -EMSGSIZE;
}
if (!list_empty(&hwreq->queue)) {
dev_err(hwep->ci->dev, "request already in queue\n");
return -EBUSY;
}
hwreq->req.status = -EINPROGRESS;
hwreq->req.actual = 0;
retval = _hardware_enqueue(hwep, hwreq);
if (retval == -EALREADY)
retval = 0;
if (!retval)
list_add_tail(&hwreq->queue, &hwep->qh.queue);
return retval;
}
static int isr_get_status_response(struct ci_hdrc *ci,
struct usb_ctrlrequest *setup)
__releases(hwep->lock)
__acquires(hwep->lock)
{
struct ci_hw_ep *hwep = ci->ep0in;
struct usb_request *req = NULL;
gfp_t gfp_flags = GFP_ATOMIC;
int dir, num, retval;
if (hwep == NULL || setup == NULL)
return -EINVAL;
spin_unlock(hwep->lock);
req = usb_ep_alloc_request(&hwep->ep, gfp_flags);
spin_lock(hwep->lock);
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
*(u16 *)req->buf = (ci->remote_wakeup << 1) |
ci->gadget.is_selfpowered;
} else if ((setup->bRequestType & USB_RECIP_MASK) \
== USB_RECIP_ENDPOINT) {
dir = (le16_to_cpu(setup->wIndex) & USB_ENDPOINT_DIR_MASK) ?
TX : RX;
num = le16_to_cpu(setup->wIndex) & USB_ENDPOINT_NUMBER_MASK;
*(u16 *)req->buf = hw_ep_get_halt(ci, num, dir);
}
retval = _ep_queue(&hwep->ep, req, gfp_flags);
if (retval)
goto err_free_buf;
return 0;
err_free_buf:
kfree(req->buf);
err_free_req:
spin_unlock(hwep->lock);
usb_ep_free_request(&hwep->ep, req);
spin_lock(hwep->lock);
return retval;
}
static void
isr_setup_status_complete(struct usb_ep *ep, struct usb_request *req)
{
struct ci_hdrc *ci = req->context;
unsigned long flags;
if (ci->setaddr) {
hw_usb_set_address(ci, ci->address);
ci->setaddr = false;
if (ci->address)
usb_gadget_set_state(&ci->gadget, USB_STATE_ADDRESS);
}
spin_lock_irqsave(&ci->lock, flags);
if (ci->test_mode)
hw_port_test_set(ci, ci->test_mode);
spin_unlock_irqrestore(&ci->lock, flags);
}
static int isr_setup_status_phase(struct ci_hdrc *ci)
{
int retval;
struct ci_hw_ep *hwep;
hwep = (ci->ep0_dir == TX) ? ci->ep0out : ci->ep0in;
ci->status->context = ci;
ci->status->complete = isr_setup_status_complete;
retval = _ep_queue(&hwep->ep, ci->status, GFP_ATOMIC);
return retval;
}
static int isr_tr_complete_low(struct ci_hw_ep *hwep)
__releases(hwep->lock)
__acquires(hwep->lock)
{
struct ci_hw_req *hwreq, *hwreqtemp;
struct ci_hw_ep *hweptemp = hwep;
int retval = 0;
list_for_each_entry_safe(hwreq, hwreqtemp, &hwep->qh.queue,
queue) {
retval = _hardware_dequeue(hwep, hwreq);
if (retval < 0)
break;
list_del_init(&hwreq->queue);
if (hwreq->req.complete != NULL) {
spin_unlock(hwep->lock);
if ((hwep->type == USB_ENDPOINT_XFER_CONTROL) &&
hwreq->req.length)
hweptemp = hwep->ci->ep0in;
usb_gadget_giveback_request(&hweptemp->ep, &hwreq->req);
spin_lock(hwep->lock);
}
}
if (retval == -EBUSY)
retval = 0;
return retval;
}
static int otg_a_alt_hnp_support(struct ci_hdrc *ci)
{
dev_warn(&ci->gadget.dev,
"connect the device to an alternate port if you want HNP\n");
return isr_setup_status_phase(ci);
}
static void isr_setup_packet_handler(struct ci_hdrc *ci)
__releases(ci->lock)
__acquires(ci->lock)
{
struct ci_hw_ep *hwep = &ci->ci_hw_ep[0];
struct usb_ctrlrequest req;
int type, num, dir, err = -EINVAL;
u8 tmode = 0;
_ep_nuke(ci->ep0out);
_ep_nuke(ci->ep0in);
do {
hw_test_and_set_setup_guard(ci);
memcpy(&req, &hwep->qh.ptr->setup, sizeof(req));
} while (!hw_test_and_clear_setup_guard(ci));
type = req.bRequestType;
ci->ep0_dir = (type & USB_DIR_IN) ? TX : RX;
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
num += ci->hw_ep_max / 2;
if (!ci->ci_hw_ep[num].wedge) {
spin_unlock(&ci->lock);
err = usb_ep_clear_halt(
&ci->ci_hw_ep[num].ep);
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
num += ci->hw_ep_max / 2;
spin_unlock(&ci->lock);
err = usb_ep_set_halt(&ci->ci_hw_ep[num].ep);
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
break;
case USB_DEVICE_B_HNP_ENABLE:
if (ci_otg_is_fsm_mode(ci)) {
ci->gadget.b_hnp_enable = 1;
err = isr_setup_status_phase(
ci);
}
break;
case USB_DEVICE_A_ALT_HNP_SUPPORT:
if (ci_otg_is_fsm_mode(ci))
err = otg_a_alt_hnp_support(ci);
break;
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
spin_unlock(&ci->lock);
if (usb_ep_set_halt(&hwep->ep))
dev_err(ci->dev, "error: ep_set_halt\n");
spin_lock(&ci->lock);
}
}
static void isr_tr_complete_handler(struct ci_hdrc *ci)
__releases(ci->lock)
__acquires(ci->lock)
{
unsigned i;
int err;
for (i = 0; i < ci->hw_ep_max; i++) {
struct ci_hw_ep *hwep = &ci->ci_hw_ep[i];
if (hwep->ep.desc == NULL)
continue;
if (hw_test_and_clear_complete(ci, i)) {
err = isr_tr_complete_low(hwep);
if (hwep->type == USB_ENDPOINT_XFER_CONTROL) {
if (err > 0)
err = isr_setup_status_phase(ci);
if (err < 0) {
spin_unlock(&ci->lock);
if (usb_ep_set_halt(&hwep->ep))
dev_err(ci->dev,
"error: ep_set_halt\n");
spin_lock(&ci->lock);
}
}
}
if (i == 0 &&
hw_test_and_clear(ci, OP_ENDPTSETUPSTAT, BIT(0)))
isr_setup_packet_handler(ci);
}
}
static int ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
int retval = 0;
unsigned long flags;
u32 cap = 0;
if (ep == NULL || desc == NULL)
return -EINVAL;
spin_lock_irqsave(hwep->lock, flags);
hwep->ep.desc = desc;
if (!list_empty(&hwep->qh.queue))
dev_warn(hwep->ci->dev, "enabling a non-empty endpoint!\n");
hwep->dir = usb_endpoint_dir_in(desc) ? TX : RX;
hwep->num = usb_endpoint_num(desc);
hwep->type = usb_endpoint_type(desc);
hwep->ep.maxpacket = usb_endpoint_maxp(desc) & 0x07ff;
hwep->ep.mult = QH_ISO_MULT(usb_endpoint_maxp(desc));
if (hwep->type == USB_ENDPOINT_XFER_CONTROL)
cap |= QH_IOS;
cap |= QH_ZLT;
cap |= (hwep->ep.maxpacket << __ffs(QH_MAX_PKT)) & QH_MAX_PKT;
if (hwep->type == USB_ENDPOINT_XFER_ISOC && hwep->dir == TX)
cap |= 3 << __ffs(QH_MULT);
hwep->qh.ptr->cap = cpu_to_le32(cap);
hwep->qh.ptr->td.next |= cpu_to_le32(TD_TERMINATE);
if (hwep->num != 0 && hwep->type == USB_ENDPOINT_XFER_CONTROL) {
dev_err(hwep->ci->dev, "Set control xfer at non-ep0\n");
retval = -EINVAL;
}
if (hwep->num)
retval |= hw_ep_enable(hwep->ci, hwep->num, hwep->dir,
hwep->type);
spin_unlock_irqrestore(hwep->lock, flags);
return retval;
}
static int ep_disable(struct usb_ep *ep)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
int direction, retval = 0;
unsigned long flags;
if (ep == NULL)
return -EINVAL;
else if (hwep->ep.desc == NULL)
return -EBUSY;
spin_lock_irqsave(hwep->lock, flags);
direction = hwep->dir;
do {
retval |= _ep_nuke(hwep);
retval |= hw_ep_disable(hwep->ci, hwep->num, hwep->dir);
if (hwep->type == USB_ENDPOINT_XFER_CONTROL)
hwep->dir = (hwep->dir == TX) ? RX : TX;
} while (hwep->dir != direction);
hwep->ep.desc = NULL;
spin_unlock_irqrestore(hwep->lock, flags);
return retval;
}
static struct usb_request *ep_alloc_request(struct usb_ep *ep, gfp_t gfp_flags)
{
struct ci_hw_req *hwreq = NULL;
if (ep == NULL)
return NULL;
hwreq = kzalloc(sizeof(struct ci_hw_req), gfp_flags);
if (hwreq != NULL) {
INIT_LIST_HEAD(&hwreq->queue);
INIT_LIST_HEAD(&hwreq->tds);
}
return (hwreq == NULL) ? NULL : &hwreq->req;
}
static void ep_free_request(struct usb_ep *ep, struct usb_request *req)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
struct ci_hw_req *hwreq = container_of(req, struct ci_hw_req, req);
struct td_node *node, *tmpnode;
unsigned long flags;
if (ep == NULL || req == NULL) {
return;
} else if (!list_empty(&hwreq->queue)) {
dev_err(hwep->ci->dev, "freeing queued request\n");
return;
}
spin_lock_irqsave(hwep->lock, flags);
list_for_each_entry_safe(node, tmpnode, &hwreq->tds, td) {
dma_pool_free(hwep->td_pool, node->ptr, node->dma);
list_del_init(&node->td);
node->ptr = NULL;
kfree(node);
}
kfree(hwreq);
spin_unlock_irqrestore(hwep->lock, flags);
}
static int ep_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t __maybe_unused gfp_flags)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
int retval = 0;
unsigned long flags;
if (ep == NULL || req == NULL || hwep->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(hwep->lock, flags);
retval = _ep_queue(ep, req, gfp_flags);
spin_unlock_irqrestore(hwep->lock, flags);
return retval;
}
static int ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
struct ci_hw_req *hwreq = container_of(req, struct ci_hw_req, req);
unsigned long flags;
struct td_node *node, *tmpnode;
if (ep == NULL || req == NULL || hwreq->req.status != -EALREADY ||
hwep->ep.desc == NULL || list_empty(&hwreq->queue) ||
list_empty(&hwep->qh.queue))
return -EINVAL;
spin_lock_irqsave(hwep->lock, flags);
hw_ep_flush(hwep->ci, hwep->num, hwep->dir);
list_for_each_entry_safe(node, tmpnode, &hwreq->tds, td) {
dma_pool_free(hwep->td_pool, node->ptr, node->dma);
list_del(&node->td);
kfree(node);
}
list_del_init(&hwreq->queue);
usb_gadget_unmap_request(&hwep->ci->gadget, req, hwep->dir);
req->status = -ECONNRESET;
if (hwreq->req.complete != NULL) {
spin_unlock(hwep->lock);
usb_gadget_giveback_request(&hwep->ep, &hwreq->req);
spin_lock(hwep->lock);
}
spin_unlock_irqrestore(hwep->lock, flags);
return 0;
}
static int ep_set_halt(struct usb_ep *ep, int value)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
int direction, retval = 0;
unsigned long flags;
if (ep == NULL || hwep->ep.desc == NULL)
return -EINVAL;
if (usb_endpoint_xfer_isoc(hwep->ep.desc))
return -EOPNOTSUPP;
spin_lock_irqsave(hwep->lock, flags);
#ifndef STALL_IN
if (value && hwep->type == USB_ENDPOINT_XFER_BULK && hwep->dir == TX &&
!list_empty(&hwep->qh.queue)) {
spin_unlock_irqrestore(hwep->lock, flags);
return -EAGAIN;
}
#endif
direction = hwep->dir;
do {
retval |= hw_ep_set_halt(hwep->ci, hwep->num, hwep->dir, value);
if (!value)
hwep->wedge = 0;
if (hwep->type == USB_ENDPOINT_XFER_CONTROL)
hwep->dir = (hwep->dir == TX) ? RX : TX;
} while (hwep->dir != direction);
spin_unlock_irqrestore(hwep->lock, flags);
return retval;
}
static int ep_set_wedge(struct usb_ep *ep)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
unsigned long flags;
if (ep == NULL || hwep->ep.desc == NULL)
return -EINVAL;
spin_lock_irqsave(hwep->lock, flags);
hwep->wedge = 1;
spin_unlock_irqrestore(hwep->lock, flags);
return usb_ep_set_halt(ep);
}
static void ep_fifo_flush(struct usb_ep *ep)
{
struct ci_hw_ep *hwep = container_of(ep, struct ci_hw_ep, ep);
unsigned long flags;
if (ep == NULL) {
dev_err(hwep->ci->dev, "%02X: -EINVAL\n", _usb_addr(hwep));
return;
}
spin_lock_irqsave(hwep->lock, flags);
hw_ep_flush(hwep->ci, hwep->num, hwep->dir);
spin_unlock_irqrestore(hwep->lock, flags);
}
static int ci_udc_vbus_session(struct usb_gadget *_gadget, int is_active)
{
struct ci_hdrc *ci = container_of(_gadget, struct ci_hdrc, gadget);
unsigned long flags;
int gadget_ready = 0;
spin_lock_irqsave(&ci->lock, flags);
ci->vbus_active = is_active;
if (ci->driver)
gadget_ready = 1;
spin_unlock_irqrestore(&ci->lock, flags);
if (gadget_ready) {
if (is_active) {
pm_runtime_get_sync(&_gadget->dev);
hw_device_reset(ci);
hw_device_state(ci, ci->ep0out->qh.dma);
usb_gadget_set_state(_gadget, USB_STATE_POWERED);
} else {
if (ci->driver)
ci->driver->disconnect(&ci->gadget);
hw_device_state(ci, 0);
if (ci->platdata->notify_event)
ci->platdata->notify_event(ci,
CI_HDRC_CONTROLLER_STOPPED_EVENT);
_gadget_stop_activity(&ci->gadget);
pm_runtime_put_sync(&_gadget->dev);
usb_gadget_set_state(_gadget, USB_STATE_NOTATTACHED);
}
}
return 0;
}
static int ci_udc_wakeup(struct usb_gadget *_gadget)
{
struct ci_hdrc *ci = container_of(_gadget, struct ci_hdrc, gadget);
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
static int ci_udc_vbus_draw(struct usb_gadget *_gadget, unsigned ma)
{
struct ci_hdrc *ci = container_of(_gadget, struct ci_hdrc, gadget);
if (ci->usb_phy)
return usb_phy_set_power(ci->usb_phy, ma);
return -ENOTSUPP;
}
static int ci_udc_selfpowered(struct usb_gadget *_gadget, int is_on)
{
struct ci_hdrc *ci = container_of(_gadget, struct ci_hdrc, gadget);
struct ci_hw_ep *hwep = ci->ep0in;
unsigned long flags;
spin_lock_irqsave(hwep->lock, flags);
_gadget->is_selfpowered = (is_on != 0);
spin_unlock_irqrestore(hwep->lock, flags);
return 0;
}
static int ci_udc_pullup(struct usb_gadget *_gadget, int is_on)
{
struct ci_hdrc *ci = container_of(_gadget, struct ci_hdrc, gadget);
if (!ci->vbus_active)
return -EOPNOTSUPP;
if (is_on)
hw_write(ci, OP_USBCMD, USBCMD_RS, USBCMD_RS);
else
hw_write(ci, OP_USBCMD, USBCMD_RS, 0);
return 0;
}
static int init_eps(struct ci_hdrc *ci)
{
int retval = 0, i, j;
for (i = 0; i < ci->hw_ep_max/2; i++)
for (j = RX; j <= TX; j++) {
int k = i + j * ci->hw_ep_max/2;
struct ci_hw_ep *hwep = &ci->ci_hw_ep[k];
scnprintf(hwep->name, sizeof(hwep->name), "ep%i%s", i,
(j == TX) ? "in" : "out");
hwep->ci = ci;
hwep->lock = &ci->lock;
hwep->td_pool = ci->td_pool;
hwep->ep.name = hwep->name;
hwep->ep.ops = &usb_ep_ops;
usb_ep_set_maxpacket_limit(&hwep->ep, (unsigned short)~0);
INIT_LIST_HEAD(&hwep->qh.queue);
hwep->qh.ptr = dma_pool_alloc(ci->qh_pool, GFP_KERNEL,
&hwep->qh.dma);
if (hwep->qh.ptr == NULL)
retval = -ENOMEM;
else
memset(hwep->qh.ptr, 0, sizeof(*hwep->qh.ptr));
if (i == 0) {
if (j == RX)
ci->ep0out = hwep;
else
ci->ep0in = hwep;
usb_ep_set_maxpacket_limit(&hwep->ep, CTRL_PAYLOAD_MAX);
continue;
}
list_add_tail(&hwep->ep.ep_list, &ci->gadget.ep_list);
}
return retval;
}
static void destroy_eps(struct ci_hdrc *ci)
{
int i;
for (i = 0; i < ci->hw_ep_max; i++) {
struct ci_hw_ep *hwep = &ci->ci_hw_ep[i];
if (hwep->pending_td)
free_pending_td(hwep);
dma_pool_free(ci->qh_pool, hwep->qh.ptr, hwep->qh.dma);
}
}
static int ci_udc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct ci_hdrc *ci = container_of(gadget, struct ci_hdrc, gadget);
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
ci->driver = driver;
if (ci_otg_is_fsm_mode(ci) && ci->fsm.id) {
ci_hdrc_otg_fsm_start(ci);
return retval;
}
pm_runtime_get_sync(&ci->gadget.dev);
if (ci->vbus_active) {
spin_lock_irqsave(&ci->lock, flags);
hw_device_reset(ci);
} else {
pm_runtime_put_sync(&ci->gadget.dev);
return retval;
}
retval = hw_device_state(ci, ci->ep0out->qh.dma);
spin_unlock_irqrestore(&ci->lock, flags);
if (retval)
pm_runtime_put_sync(&ci->gadget.dev);
return retval;
}
static int ci_udc_stop(struct usb_gadget *gadget)
{
struct ci_hdrc *ci = container_of(gadget, struct ci_hdrc, gadget);
unsigned long flags;
spin_lock_irqsave(&ci->lock, flags);
if (ci->vbus_active) {
hw_device_state(ci, 0);
if (ci->platdata->notify_event)
ci->platdata->notify_event(ci,
CI_HDRC_CONTROLLER_STOPPED_EVENT);
spin_unlock_irqrestore(&ci->lock, flags);
_gadget_stop_activity(&ci->gadget);
spin_lock_irqsave(&ci->lock, flags);
pm_runtime_put(&ci->gadget.dev);
}
ci->driver = NULL;
spin_unlock_irqrestore(&ci->lock, flags);
return 0;
}
static irqreturn_t udc_irq(struct ci_hdrc *ci)
{
irqreturn_t retval;
u32 intr;
if (ci == NULL)
return IRQ_HANDLED;
spin_lock(&ci->lock);
if (ci->platdata->flags & CI_HDRC_REGS_SHARED) {
if (hw_read(ci, OP_USBMODE, USBMODE_CM) !=
USBMODE_CM_DC) {
spin_unlock(&ci->lock);
return IRQ_NONE;
}
}
intr = hw_test_and_clear_intr_active(ci);
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
usb_gadget_set_state(&ci->gadget,
USB_STATE_SUSPENDED);
spin_lock(&ci->lock);
}
}
retval = IRQ_HANDLED;
} else {
retval = IRQ_NONE;
}
spin_unlock(&ci->lock);
return retval;
}
static int udc_start(struct ci_hdrc *ci)
{
struct device *dev = ci->dev;
int retval = 0;
spin_lock_init(&ci->lock);
ci->gadget.ops = &usb_gadget_ops;
ci->gadget.speed = USB_SPEED_UNKNOWN;
ci->gadget.max_speed = USB_SPEED_HIGH;
ci->gadget.is_otg = ci->is_otg ? 1 : 0;
ci->gadget.name = ci->platdata->name;
INIT_LIST_HEAD(&ci->gadget.ep_list);
ci->qh_pool = dma_pool_create("ci_hw_qh", dev,
sizeof(struct ci_hw_qh),
64, CI_HDRC_PAGE_SIZE);
if (ci->qh_pool == NULL)
return -ENOMEM;
ci->td_pool = dma_pool_create("ci_hw_td", dev,
sizeof(struct ci_hw_td),
64, CI_HDRC_PAGE_SIZE);
if (ci->td_pool == NULL) {
retval = -ENOMEM;
goto free_qh_pool;
}
retval = init_eps(ci);
if (retval)
goto free_pools;
ci->gadget.ep0 = &ci->ep0in->ep;
retval = usb_add_gadget_udc(dev, &ci->gadget);
if (retval)
goto destroy_eps;
pm_runtime_no_callbacks(&ci->gadget.dev);
pm_runtime_enable(&ci->gadget.dev);
return retval;
destroy_eps:
destroy_eps(ci);
free_pools:
dma_pool_destroy(ci->td_pool);
free_qh_pool:
dma_pool_destroy(ci->qh_pool);
return retval;
}
void ci_hdrc_gadget_destroy(struct ci_hdrc *ci)
{
if (!ci->roles[CI_ROLE_GADGET])
return;
usb_del_gadget_udc(&ci->gadget);
destroy_eps(ci);
dma_pool_destroy(ci->td_pool);
dma_pool_destroy(ci->qh_pool);
}
static int udc_id_switch_for_device(struct ci_hdrc *ci)
{
if (ci->is_otg)
hw_write_otgsc(ci, OTGSC_BSVIS | OTGSC_BSVIE,
OTGSC_BSVIS | OTGSC_BSVIE);
return 0;
}
static void udc_id_switch_for_host(struct ci_hdrc *ci)
{
if (ci->is_otg)
hw_write_otgsc(ci, OTGSC_BSVIE | OTGSC_BSVIS, OTGSC_BSVIS);
}
int ci_hdrc_gadget_init(struct ci_hdrc *ci)
{
struct ci_role_driver *rdrv;
if (!hw_read(ci, CAP_DCCPARAMS, DCCPARAMS_DC))
return -ENXIO;
rdrv = devm_kzalloc(ci->dev, sizeof(struct ci_role_driver), GFP_KERNEL);
if (!rdrv)
return -ENOMEM;
rdrv->start = udc_id_switch_for_device;
rdrv->stop = udc_id_switch_for_host;
rdrv->irq = udc_irq;
rdrv->name = "gadget";
ci->roles[CI_ROLE_GADGET] = rdrv;
return udc_start(ci);
}
