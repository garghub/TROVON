static u32 _fsl_readl_be(const unsigned __iomem *p)
{
return in_be32(p);
}
static u32 _fsl_readl_le(const unsigned __iomem *p)
{
return in_le32(p);
}
static void _fsl_writel_be(u32 v, unsigned __iomem *p)
{
out_be32(p, v);
}
static void _fsl_writel_le(u32 v, unsigned __iomem *p)
{
out_le32(p, v);
}
static inline void fsl_set_accessors(struct fsl_usb2_platform_data *pdata)
{
if (pdata->big_endian_mmio) {
_fsl_readl = _fsl_readl_be;
_fsl_writel = _fsl_writel_be;
} else {
_fsl_readl = _fsl_readl_le;
_fsl_writel = _fsl_writel_le;
}
}
static inline u32 cpu_to_hc32(const u32 x)
{
return udc_controller->pdata->big_endian_desc
? (__force u32)cpu_to_be32(x)
: (__force u32)cpu_to_le32(x);
}
static inline u32 hc32_to_cpu(const u32 x)
{
return udc_controller->pdata->big_endian_desc
? be32_to_cpu((__force __be32)x)
: le32_to_cpu((__force __le32)x);
}
static inline void fsl_set_accessors(struct fsl_usb2_platform_data *pdata) {}
static void done(struct fsl_ep *ep, struct fsl_req *req, int status)
{
struct fsl_udc *udc = NULL;
unsigned char stopped = ep->stopped;
struct ep_td_struct *curr_td, *next_td;
int j;
udc = (struct fsl_udc *)ep->udc;
list_del_init(&req->queue);
if (req->req.status == -EINPROGRESS)
req->req.status = status;
else
status = req->req.status;
next_td = req->head;
for (j = 0; j < req->dtd_count; j++) {
curr_td = next_td;
if (j != req->dtd_count - 1) {
next_td = curr_td->next_td_virt;
}
dma_pool_free(udc->td_pool, curr_td, curr_td->td_dma);
}
usb_gadget_unmap_request(&ep->udc->gadget, &req->req, ep_is_in(ep));
if (status && (status != -ESHUTDOWN))
VDBG("complete %s req %p stat %d len %u/%u",
ep->ep.name, &req->req, status,
req->req.actual, req->req.length);
ep->stopped = 1;
spin_unlock(&ep->udc->lock);
if (req->req.complete)
req->req.complete(&ep->ep, &req->req);
spin_lock(&ep->udc->lock);
ep->stopped = stopped;
}
static void nuke(struct fsl_ep *ep, int status)
{
ep->stopped = 1;
fsl_ep_fifo_flush(&ep->ep);
while (!list_empty(&ep->queue)) {
struct fsl_req *req = NULL;
req = list_entry(ep->queue.next, struct fsl_req, queue);
done(ep, req, status);
}
}
static int dr_controller_setup(struct fsl_udc *udc)
{
unsigned int tmp, portctrl, ep_num;
unsigned int max_no_of_ep;
unsigned int ctrl;
unsigned long timeout;
#define FSL_UDC_RESET_TIMEOUT 1000
portctrl = fsl_readl(&dr_regs->portsc1);
portctrl &= ~(PORTSCX_PHY_TYPE_SEL | PORTSCX_PORT_WIDTH);
switch (udc->phy_mode) {
case FSL_USB2_PHY_ULPI:
if (udc->pdata->have_sysif_regs) {
if (udc->pdata->controller_ver) {
ctrl = __raw_readl(&usb_sys_regs->control);
ctrl &= ~USB_CTRL_UTMI_PHY_EN;
ctrl |= USB_CTRL_USB_EN;
__raw_writel(ctrl, &usb_sys_regs->control);
}
}
portctrl |= PORTSCX_PTS_ULPI;
break;
case FSL_USB2_PHY_UTMI_WIDE:
portctrl |= PORTSCX_PTW_16BIT;
case FSL_USB2_PHY_UTMI:
if (udc->pdata->have_sysif_regs) {
if (udc->pdata->controller_ver) {
ctrl = __raw_readl(&usb_sys_regs->control);
ctrl |= (USB_CTRL_UTMI_PHY_EN |
USB_CTRL_USB_EN);
__raw_writel(ctrl, &usb_sys_regs->control);
mdelay(FSL_UTMI_PHY_DLY);
}
}
portctrl |= PORTSCX_PTS_UTMI;
break;
case FSL_USB2_PHY_SERIAL:
portctrl |= PORTSCX_PTS_FSLS;
break;
default:
return -EINVAL;
}
fsl_writel(portctrl, &dr_regs->portsc1);
tmp = fsl_readl(&dr_regs->usbcmd);
tmp &= ~USB_CMD_RUN_STOP;
fsl_writel(tmp, &dr_regs->usbcmd);
tmp = fsl_readl(&dr_regs->usbcmd);
tmp |= USB_CMD_CTRL_RESET;
fsl_writel(tmp, &dr_regs->usbcmd);
timeout = jiffies + FSL_UDC_RESET_TIMEOUT;
while (fsl_readl(&dr_regs->usbcmd) & USB_CMD_CTRL_RESET) {
if (time_after(jiffies, timeout)) {
ERR("udc reset timeout!\n");
return -ETIMEDOUT;
}
cpu_relax();
}
tmp = fsl_readl(&dr_regs->usbmode);
tmp &= ~USB_MODE_CTRL_MODE_MASK;
tmp |= USB_MODE_CTRL_MODE_DEVICE;
tmp |= USB_MODE_SETUP_LOCK_OFF;
if (udc->pdata->es)
tmp |= USB_MODE_ES;
fsl_writel(tmp, &dr_regs->usbmode);
fsl_writel(0, &dr_regs->usbsts);
tmp = udc->ep_qh_dma;
tmp &= USB_EP_LIST_ADDRESS_MASK;
fsl_writel(tmp, &dr_regs->endpointlistaddr);
VDBG("vir[qh_base] is %p phy[qh_base] is 0x%8x reg is 0x%8x",
udc->ep_qh, (int)tmp,
fsl_readl(&dr_regs->endpointlistaddr));
max_no_of_ep = (0x0000001F & fsl_readl(&dr_regs->dccparams));
for (ep_num = 1; ep_num < max_no_of_ep; ep_num++) {
tmp = fsl_readl(&dr_regs->endptctrl[ep_num]);
tmp &= ~(EPCTRL_TX_TYPE | EPCTRL_RX_TYPE);
tmp |= (EPCTRL_EP_TYPE_BULK << EPCTRL_TX_EP_TYPE_SHIFT)
| (EPCTRL_EP_TYPE_BULK << EPCTRL_RX_EP_TYPE_SHIFT);
fsl_writel(tmp, &dr_regs->endptctrl[ep_num]);
}
#ifndef CONFIG_ARCH_MXC
if (udc->pdata->have_sysif_regs) {
ctrl = __raw_readl(&usb_sys_regs->control);
ctrl |= USB_CTRL_IOENB;
__raw_writel(ctrl, &usb_sys_regs->control);
}
#endif
#if defined(CONFIG_PPC32) && !defined(CONFIG_NOT_COHERENT_CACHE)
if (udc->pdata->have_sysif_regs) {
tmp = SNOOP_SIZE_2GB;
__raw_writel(tmp, &usb_sys_regs->snoop1);
tmp |= 0x80000000;
__raw_writel(tmp, &usb_sys_regs->snoop2);
}
#endif
return 0;
}
static void dr_controller_run(struct fsl_udc *udc)
{
u32 temp;
temp = USB_INTR_INT_EN | USB_INTR_ERR_INT_EN
| USB_INTR_PTC_DETECT_EN | USB_INTR_RESET_EN
| USB_INTR_DEVICE_SUSPEND | USB_INTR_SYS_ERR_EN;
fsl_writel(temp, &dr_regs->usbintr);
udc->stopped = 0;
temp = fsl_readl(&dr_regs->usbmode);
temp |= USB_MODE_CTRL_MODE_DEVICE;
fsl_writel(temp, &dr_regs->usbmode);
temp = fsl_readl(&dr_regs->usbcmd);
temp |= USB_CMD_RUN_STOP;
fsl_writel(temp, &dr_regs->usbcmd);
}
static void dr_controller_stop(struct fsl_udc *udc)
{
unsigned int tmp;
pr_debug("%s\n", __func__);
if (udc->gadget.is_otg) {
if (!(fsl_readl(&dr_regs->otgsc) & OTGSC_STS_USB_ID)) {
pr_debug("udc: Leaving early\n");
return;
}
}
fsl_writel(0, &dr_regs->usbintr);
udc->stopped = 1;
tmp = fsl_readl(&dr_regs->usbcmd);
tmp &= ~USB_CMD_RUN_STOP;
fsl_writel(tmp, &dr_regs->usbcmd);
}
static void dr_ep_setup(unsigned char ep_num, unsigned char dir,
unsigned char ep_type)
{
unsigned int tmp_epctrl = 0;
tmp_epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (dir) {
if (ep_num)
tmp_epctrl |= EPCTRL_TX_DATA_TOGGLE_RST;
tmp_epctrl |= EPCTRL_TX_ENABLE;
tmp_epctrl &= ~EPCTRL_TX_TYPE;
tmp_epctrl |= ((unsigned int)(ep_type)
<< EPCTRL_TX_EP_TYPE_SHIFT);
} else {
if (ep_num)
tmp_epctrl |= EPCTRL_RX_DATA_TOGGLE_RST;
tmp_epctrl |= EPCTRL_RX_ENABLE;
tmp_epctrl &= ~EPCTRL_RX_TYPE;
tmp_epctrl |= ((unsigned int)(ep_type)
<< EPCTRL_RX_EP_TYPE_SHIFT);
}
fsl_writel(tmp_epctrl, &dr_regs->endptctrl[ep_num]);
}
static void
dr_ep_change_stall(unsigned char ep_num, unsigned char dir, int value)
{
u32 tmp_epctrl = 0;
tmp_epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (value) {
if (dir)
tmp_epctrl |= EPCTRL_TX_EP_STALL;
else
tmp_epctrl |= EPCTRL_RX_EP_STALL;
} else {
if (dir) {
tmp_epctrl &= ~EPCTRL_TX_EP_STALL;
tmp_epctrl |= EPCTRL_TX_DATA_TOGGLE_RST;
} else {
tmp_epctrl &= ~EPCTRL_RX_EP_STALL;
tmp_epctrl |= EPCTRL_RX_DATA_TOGGLE_RST;
}
}
fsl_writel(tmp_epctrl, &dr_regs->endptctrl[ep_num]);
}
static int dr_ep_get_stall(unsigned char ep_num, unsigned char dir)
{
u32 epctrl;
epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (dir)
return (epctrl & EPCTRL_TX_EP_STALL) ? 1 : 0;
else
return (epctrl & EPCTRL_RX_EP_STALL) ? 1 : 0;
}
static void struct_ep_qh_setup(struct fsl_udc *udc, unsigned char ep_num,
unsigned char dir, unsigned char ep_type,
unsigned int max_pkt_len,
unsigned int zlt, unsigned char mult)
{
struct ep_queue_head *p_QH = &udc->ep_qh[2 * ep_num + dir];
unsigned int tmp = 0;
switch (ep_type) {
case USB_ENDPOINT_XFER_CONTROL:
tmp = (max_pkt_len << EP_QUEUE_HEAD_MAX_PKT_LEN_POS)
| EP_QUEUE_HEAD_IOS;
break;
case USB_ENDPOINT_XFER_ISOC:
tmp = (max_pkt_len << EP_QUEUE_HEAD_MAX_PKT_LEN_POS)
| (mult << EP_QUEUE_HEAD_MULT_POS);
break;
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
tmp = max_pkt_len << EP_QUEUE_HEAD_MAX_PKT_LEN_POS;
break;
default:
VDBG("error ep type is %d", ep_type);
return;
}
if (zlt)
tmp |= EP_QUEUE_HEAD_ZLT_SEL;
p_QH->max_pkt_length = cpu_to_hc32(tmp);
p_QH->next_dtd_ptr = 1;
p_QH->size_ioc_int_sts = 0;
}
static void ep0_setup(struct fsl_udc *udc)
{
struct_ep_qh_setup(udc, 0, USB_RECV, USB_ENDPOINT_XFER_CONTROL,
USB_MAX_CTRL_PAYLOAD, 0, 0);
struct_ep_qh_setup(udc, 0, USB_SEND, USB_ENDPOINT_XFER_CONTROL,
USB_MAX_CTRL_PAYLOAD, 0, 0);
dr_ep_setup(0, USB_RECV, USB_ENDPOINT_XFER_CONTROL);
dr_ep_setup(0, USB_SEND, USB_ENDPOINT_XFER_CONTROL);
return;
}
static int fsl_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct fsl_udc *udc = NULL;
struct fsl_ep *ep = NULL;
unsigned short max = 0;
unsigned char mult = 0, zlt;
int retval = -EINVAL;
unsigned long flags = 0;
ep = container_of(_ep, struct fsl_ep, ep);
if (!_ep || !desc
|| (desc->bDescriptorType != USB_DT_ENDPOINT))
return -EINVAL;
udc = ep->udc;
if (!udc->driver || (udc->gadget.speed == USB_SPEED_UNKNOWN))
return -ESHUTDOWN;
max = usb_endpoint_maxp(desc);
zlt = 1;
switch (desc->bmAttributes & 0x03) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
mult = 0;
break;
case USB_ENDPOINT_XFER_ISOC:
mult = (unsigned char)(1 + ((max >> 11) & 0x03));
max = max & 0x7ff;
if (mult > 3)
goto en_done;
break;
default:
goto en_done;
}
spin_lock_irqsave(&udc->lock, flags);
ep->ep.maxpacket = max;
ep->ep.desc = desc;
ep->stopped = 0;
struct_ep_qh_setup(udc, (unsigned char) ep_index(ep),
(unsigned char) ((desc->bEndpointAddress & USB_DIR_IN)
? USB_SEND : USB_RECV),
(unsigned char) (desc->bmAttributes
& USB_ENDPOINT_XFERTYPE_MASK),
max, zlt, mult);
dr_ep_setup((unsigned char) ep_index(ep),
(unsigned char) ((desc->bEndpointAddress & USB_DIR_IN)
? USB_SEND : USB_RECV),
(unsigned char) (desc->bmAttributes
& USB_ENDPOINT_XFERTYPE_MASK));
spin_unlock_irqrestore(&udc->lock, flags);
retval = 0;
VDBG("enabled %s (ep%d%s) maxpacket %d",ep->ep.name,
ep->ep.desc->bEndpointAddress & 0x0f,
(desc->bEndpointAddress & USB_DIR_IN)
? "in" : "out", max);
en_done:
return retval;
}
static int fsl_ep_disable(struct usb_ep *_ep)
{
struct fsl_udc *udc = NULL;
struct fsl_ep *ep = NULL;
unsigned long flags = 0;
u32 epctrl;
int ep_num;
ep = container_of(_ep, struct fsl_ep, ep);
if (!_ep || !ep->ep.desc) {
VDBG("%s not enabled", _ep ? ep->ep.name : NULL);
return -EINVAL;
}
ep_num = ep_index(ep);
epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (ep_is_in(ep)) {
epctrl &= ~(EPCTRL_TX_ENABLE | EPCTRL_TX_TYPE);
epctrl |= EPCTRL_EP_TYPE_BULK << EPCTRL_TX_EP_TYPE_SHIFT;
} else {
epctrl &= ~(EPCTRL_RX_ENABLE | EPCTRL_TX_TYPE);
epctrl |= EPCTRL_EP_TYPE_BULK << EPCTRL_RX_EP_TYPE_SHIFT;
}
fsl_writel(epctrl, &dr_regs->endptctrl[ep_num]);
udc = (struct fsl_udc *)ep->udc;
spin_lock_irqsave(&udc->lock, flags);
nuke(ep, -ESHUTDOWN);
ep->ep.desc = NULL;
ep->stopped = 1;
spin_unlock_irqrestore(&udc->lock, flags);
VDBG("disabled %s OK", _ep->name);
return 0;
}
static struct usb_request *
fsl_alloc_request(struct usb_ep *_ep, gfp_t gfp_flags)
{
struct fsl_req *req = NULL;
req = kzalloc(sizeof *req, gfp_flags);
if (!req)
return NULL;
req->req.dma = DMA_ADDR_INVALID;
INIT_LIST_HEAD(&req->queue);
return &req->req;
}
static void fsl_free_request(struct usb_ep *_ep, struct usb_request *_req)
{
struct fsl_req *req = NULL;
req = container_of(_req, struct fsl_req, req);
if (_req)
kfree(req);
}
static void fsl_prime_ep(struct fsl_ep *ep, struct ep_td_struct *td)
{
struct ep_queue_head *qh = get_qh_by_ep(ep);
qh->next_dtd_ptr = cpu_to_hc32(td->td_dma
& EP_QUEUE_HEAD_NEXT_POINTER_MASK);
qh->size_ioc_int_sts &= cpu_to_hc32(~(EP_QUEUE_HEAD_STATUS_ACTIVE
| EP_QUEUE_HEAD_STATUS_HALT));
wmb();
fsl_writel(ep_is_in(ep) ? (1 << (ep_index(ep) + 16))
: (1 << (ep_index(ep))), &dr_regs->endpointprime);
}
static void fsl_queue_td(struct fsl_ep *ep, struct fsl_req *req)
{
u32 temp, bitmask, tmp_stat;
bitmask = ep_is_in(ep)
? (1 << (ep_index(ep) + 16))
: (1 << (ep_index(ep)));
if (!(list_empty(&ep->queue)) && !(ep_index(ep) == 0)) {
struct fsl_req *lastreq;
lastreq = list_entry(ep->queue.prev, struct fsl_req, queue);
lastreq->tail->next_td_ptr =
cpu_to_hc32(req->head->td_dma & DTD_ADDR_MASK);
wmb();
if (fsl_readl(&dr_regs->endpointprime) & bitmask)
return;
do {
temp = fsl_readl(&dr_regs->usbcmd);
fsl_writel(temp | USB_CMD_ATDTW, &dr_regs->usbcmd);
tmp_stat = fsl_readl(&dr_regs->endptstatus) & bitmask;
} while (!(fsl_readl(&dr_regs->usbcmd) & USB_CMD_ATDTW));
temp = fsl_readl(&dr_regs->usbcmd);
fsl_writel(temp & ~USB_CMD_ATDTW, &dr_regs->usbcmd);
if (tmp_stat)
return;
}
fsl_prime_ep(ep, req->head);
}
static struct ep_td_struct *fsl_build_dtd(struct fsl_req *req, unsigned *length,
dma_addr_t *dma, int *is_last, gfp_t gfp_flags)
{
u32 swap_temp;
struct ep_td_struct *dtd;
*length = min(req->req.length - req->req.actual,
(unsigned)EP_MAX_LENGTH_TRANSFER);
dtd = dma_pool_alloc(udc_controller->td_pool, gfp_flags, dma);
if (dtd == NULL)
return dtd;
dtd->td_dma = *dma;
swap_temp = hc32_to_cpu(dtd->size_ioc_sts);
swap_temp &= ~DTD_RESERVED_FIELDS;
dtd->size_ioc_sts = cpu_to_hc32(swap_temp);
swap_temp = (u32) (req->req.dma + req->req.actual);
dtd->buff_ptr0 = cpu_to_hc32(swap_temp);
dtd->buff_ptr1 = cpu_to_hc32(swap_temp + 0x1000);
dtd->buff_ptr2 = cpu_to_hc32(swap_temp + 0x2000);
dtd->buff_ptr3 = cpu_to_hc32(swap_temp + 0x3000);
dtd->buff_ptr4 = cpu_to_hc32(swap_temp + 0x4000);
req->req.actual += *length;
if (req->req.zero) {
if (*length == 0 || (*length % req->ep->ep.maxpacket) != 0)
*is_last = 1;
else
*is_last = 0;
} else if (req->req.length == req->req.actual)
*is_last = 1;
else
*is_last = 0;
if ((*is_last) == 0)
VDBG("multi-dtd request!");
swap_temp = ((*length << DTD_LENGTH_BIT_POS) | DTD_STATUS_ACTIVE);
if (*is_last && !req->req.no_interrupt)
swap_temp |= DTD_IOC;
dtd->size_ioc_sts = cpu_to_hc32(swap_temp);
mb();
VDBG("length = %d address= 0x%x", *length, (int)*dma);
return dtd;
}
static int fsl_req_to_dtd(struct fsl_req *req, gfp_t gfp_flags)
{
unsigned count;
int is_last;
int is_first =1;
struct ep_td_struct *last_dtd = NULL, *dtd;
dma_addr_t dma;
do {
dtd = fsl_build_dtd(req, &count, &dma, &is_last, gfp_flags);
if (dtd == NULL)
return -ENOMEM;
if (is_first) {
is_first = 0;
req->head = dtd;
} else {
last_dtd->next_td_ptr = cpu_to_hc32(dma);
last_dtd->next_td_virt = dtd;
}
last_dtd = dtd;
req->dtd_count++;
} while (!is_last);
dtd->next_td_ptr = cpu_to_hc32(DTD_NEXT_TERMINATE);
req->tail = dtd;
return 0;
}
static int
fsl_ep_queue(struct usb_ep *_ep, struct usb_request *_req, gfp_t gfp_flags)
{
struct fsl_ep *ep = container_of(_ep, struct fsl_ep, ep);
struct fsl_req *req = container_of(_req, struct fsl_req, req);
struct fsl_udc *udc;
unsigned long flags;
int ret;
if (!_req || !req->req.complete || !req->req.buf
|| !list_empty(&req->queue)) {
VDBG("%s, bad params", __func__);
return -EINVAL;
}
if (unlikely(!_ep || !ep->ep.desc)) {
VDBG("%s, bad ep", __func__);
return -EINVAL;
}
if (usb_endpoint_xfer_isoc(ep->ep.desc)) {
if (req->req.length > ep->ep.maxpacket)
return -EMSGSIZE;
}
udc = ep->udc;
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
req->ep = ep;
ret = usb_gadget_map_request(&ep->udc->gadget, &req->req, ep_is_in(ep));
if (ret)
return ret;
req->req.status = -EINPROGRESS;
req->req.actual = 0;
req->dtd_count = 0;
if (!fsl_req_to_dtd(req, gfp_flags)) {
spin_lock_irqsave(&udc->lock, flags);
fsl_queue_td(ep, req);
} else {
return -ENOMEM;
}
if (req != NULL)
list_add_tail(&req->queue, &ep->queue);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int fsl_ep_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct fsl_ep *ep = container_of(_ep, struct fsl_ep, ep);
struct fsl_req *req;
unsigned long flags;
int ep_num, stopped, ret = 0;
u32 epctrl;
if (!_ep || !_req)
return -EINVAL;
spin_lock_irqsave(&ep->udc->lock, flags);
stopped = ep->stopped;
ep->stopped = 1;
ep_num = ep_index(ep);
epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (ep_is_in(ep))
epctrl &= ~EPCTRL_TX_ENABLE;
else
epctrl &= ~EPCTRL_RX_ENABLE;
fsl_writel(epctrl, &dr_regs->endptctrl[ep_num]);
list_for_each_entry(req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
ret = -EINVAL;
goto out;
}
if (ep->queue.next == &req->queue) {
_req->status = -ECONNRESET;
fsl_ep_fifo_flush(_ep);
if (req->queue.next != &ep->queue) {
struct fsl_req *next_req;
next_req = list_entry(req->queue.next, struct fsl_req,
queue);
fsl_prime_ep(ep, next_req->head);
}
} else {
struct fsl_req *prev_req;
prev_req = list_entry(req->queue.prev, struct fsl_req, queue);
prev_req->tail->next_td_ptr = req->tail->next_td_ptr;
}
done(ep, req, -ECONNRESET);
out: epctrl = fsl_readl(&dr_regs->endptctrl[ep_num]);
if (ep_is_in(ep))
epctrl |= EPCTRL_TX_ENABLE;
else
epctrl |= EPCTRL_RX_ENABLE;
fsl_writel(epctrl, &dr_regs->endptctrl[ep_num]);
ep->stopped = stopped;
spin_unlock_irqrestore(&ep->udc->lock, flags);
return ret;
}
static int fsl_ep_set_halt(struct usb_ep *_ep, int value)
{
struct fsl_ep *ep = NULL;
unsigned long flags = 0;
int status = -EOPNOTSUPP;
unsigned char ep_dir = 0, ep_num = 0;
struct fsl_udc *udc = NULL;
ep = container_of(_ep, struct fsl_ep, ep);
udc = ep->udc;
if (!_ep || !ep->ep.desc) {
status = -EINVAL;
goto out;
}
if (usb_endpoint_xfer_isoc(ep->ep.desc)) {
status = -EOPNOTSUPP;
goto out;
}
if (value && ep_is_in(ep) && !list_empty(&ep->queue)) {
status = -EAGAIN;
goto out;
}
status = 0;
ep_dir = ep_is_in(ep) ? USB_SEND : USB_RECV;
ep_num = (unsigned char)(ep_index(ep));
spin_lock_irqsave(&ep->udc->lock, flags);
dr_ep_change_stall(ep_num, ep_dir, value);
spin_unlock_irqrestore(&ep->udc->lock, flags);
if (ep_index(ep) == 0) {
udc->ep0_state = WAIT_FOR_SETUP;
udc->ep0_dir = 0;
}
out:
VDBG(" %s %s halt stat %d", ep->ep.name,
value ? "set" : "clear", status);
return status;
}
static int fsl_ep_fifo_status(struct usb_ep *_ep)
{
struct fsl_ep *ep;
struct fsl_udc *udc;
int size = 0;
u32 bitmask;
struct ep_queue_head *qh;
ep = container_of(_ep, struct fsl_ep, ep);
if (!_ep || (!ep->ep.desc && ep_index(ep) != 0))
return -ENODEV;
udc = (struct fsl_udc *)ep->udc;
if (!udc->driver || udc->gadget.speed == USB_SPEED_UNKNOWN)
return -ESHUTDOWN;
qh = get_qh_by_ep(ep);
bitmask = (ep_is_in(ep)) ? (1 << (ep_index(ep) + 16)) :
(1 << (ep_index(ep)));
if (fsl_readl(&dr_regs->endptstatus) & bitmask)
size = (qh->size_ioc_int_sts & DTD_PACKET_SIZE)
>> DTD_LENGTH_BIT_POS;
pr_debug("%s %u\n", __func__, size);
return size;
}
static void fsl_ep_fifo_flush(struct usb_ep *_ep)
{
struct fsl_ep *ep;
int ep_num, ep_dir;
u32 bits;
unsigned long timeout;
#define FSL_UDC_FLUSH_TIMEOUT 1000
if (!_ep) {
return;
} else {
ep = container_of(_ep, struct fsl_ep, ep);
if (!ep->ep.desc)
return;
}
ep_num = ep_index(ep);
ep_dir = ep_is_in(ep) ? USB_SEND : USB_RECV;
if (ep_num == 0)
bits = (1 << 16) | 1;
else if (ep_dir == USB_SEND)
bits = 1 << (16 + ep_num);
else
bits = 1 << ep_num;
timeout = jiffies + FSL_UDC_FLUSH_TIMEOUT;
do {
fsl_writel(bits, &dr_regs->endptflush);
while (fsl_readl(&dr_regs->endptflush)) {
if (time_after(jiffies, timeout)) {
ERR("ep flush timeout\n");
return;
}
cpu_relax();
}
} while (fsl_readl(&dr_regs->endptstatus) & bits);
}
static int fsl_get_frame(struct usb_gadget *gadget)
{
return (int)(fsl_readl(&dr_regs->frindex) & USB_FRINDEX_MASKS);
}
static int fsl_wakeup(struct usb_gadget *gadget)
{
struct fsl_udc *udc = container_of(gadget, struct fsl_udc, gadget);
u32 portsc;
if (!udc->remote_wakeup)
return -ENOTSUPP;
portsc = fsl_readl(&dr_regs->portsc1);
if (!(portsc & PORTSCX_PORT_SUSPEND))
return 0;
portsc |= PORTSCX_PORT_FORCE_RESUME;
fsl_writel(portsc, &dr_regs->portsc1);
return 0;
}
static int can_pullup(struct fsl_udc *udc)
{
return udc->driver && udc->softconnect && udc->vbus_active;
}
static int fsl_vbus_session(struct usb_gadget *gadget, int is_active)
{
struct fsl_udc *udc;
unsigned long flags;
udc = container_of(gadget, struct fsl_udc, gadget);
spin_lock_irqsave(&udc->lock, flags);
VDBG("VBUS %s", is_active ? "on" : "off");
udc->vbus_active = (is_active != 0);
if (can_pullup(udc))
fsl_writel((fsl_readl(&dr_regs->usbcmd) | USB_CMD_RUN_STOP),
&dr_regs->usbcmd);
else
fsl_writel((fsl_readl(&dr_regs->usbcmd) & ~USB_CMD_RUN_STOP),
&dr_regs->usbcmd);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int fsl_vbus_draw(struct usb_gadget *gadget, unsigned mA)
{
struct fsl_udc *udc;
udc = container_of(gadget, struct fsl_udc, gadget);
if (!IS_ERR_OR_NULL(udc->transceiver))
return usb_phy_set_power(udc->transceiver, mA);
return -ENOTSUPP;
}
static int fsl_pullup(struct usb_gadget *gadget, int is_on)
{
struct fsl_udc *udc;
udc = container_of(gadget, struct fsl_udc, gadget);
udc->softconnect = (is_on != 0);
if (can_pullup(udc))
fsl_writel((fsl_readl(&dr_regs->usbcmd) | USB_CMD_RUN_STOP),
&dr_regs->usbcmd);
else
fsl_writel((fsl_readl(&dr_regs->usbcmd) & ~USB_CMD_RUN_STOP),
&dr_regs->usbcmd);
return 0;
}
static void ep0stall(struct fsl_udc *udc)
{
u32 tmp;
tmp = fsl_readl(&dr_regs->endptctrl[0]);
tmp |= EPCTRL_TX_EP_STALL | EPCTRL_RX_EP_STALL;
fsl_writel(tmp, &dr_regs->endptctrl[0]);
udc->ep0_state = WAIT_FOR_SETUP;
udc->ep0_dir = 0;
}
static int ep0_prime_status(struct fsl_udc *udc, int direction)
{
struct fsl_req *req = udc->status_req;
struct fsl_ep *ep;
int ret;
if (direction == EP_DIR_IN)
udc->ep0_dir = USB_DIR_IN;
else
udc->ep0_dir = USB_DIR_OUT;
ep = &udc->eps[0];
if (udc->ep0_state != DATA_STATE_XMIT)
udc->ep0_state = WAIT_FOR_OUT_STATUS;
req->ep = ep;
req->req.length = 0;
req->req.status = -EINPROGRESS;
req->req.actual = 0;
req->req.complete = NULL;
req->dtd_count = 0;
ret = usb_gadget_map_request(&ep->udc->gadget, &req->req, ep_is_in(ep));
if (ret)
return ret;
if (fsl_req_to_dtd(req, GFP_ATOMIC) == 0)
fsl_queue_td(ep, req);
else
return -ENOMEM;
list_add_tail(&req->queue, &ep->queue);
return 0;
}
static void udc_reset_ep_queue(struct fsl_udc *udc, u8 pipe)
{
struct fsl_ep *ep = get_ep_by_pipe(udc, pipe);
if (ep->name)
nuke(ep, -ESHUTDOWN);
}
static void ch9setaddress(struct fsl_udc *udc, u16 value, u16 index, u16 length)
{
udc->device_address = (u8) value;
udc->usb_state = USB_STATE_ADDRESS;
if (ep0_prime_status(udc, EP_DIR_IN))
ep0stall(udc);
}
static void ch9getstatus(struct fsl_udc *udc, u8 request_type, u16 value,
u16 index, u16 length)
{
u16 tmp = 0;
struct fsl_req *req;
struct fsl_ep *ep;
int ret;
ep = &udc->eps[0];
if ((request_type & USB_RECIP_MASK) == USB_RECIP_DEVICE) {
tmp = 1 << USB_DEVICE_SELF_POWERED;
tmp |= udc->remote_wakeup << USB_DEVICE_REMOTE_WAKEUP;
} else if ((request_type & USB_RECIP_MASK) == USB_RECIP_INTERFACE) {
tmp = 0;
} else if ((request_type & USB_RECIP_MASK) == USB_RECIP_ENDPOINT) {
struct fsl_ep *target_ep;
target_ep = get_ep_by_pipe(udc, get_pipe_by_windex(index));
if (!target_ep->ep.desc)
goto stall;
tmp = dr_ep_get_stall(ep_index(target_ep), ep_is_in(target_ep))
<< USB_ENDPOINT_HALT;
}
udc->ep0_dir = USB_DIR_IN;
req = udc->status_req;
*((u16 *) req->req.buf) = cpu_to_le16(tmp);
req->ep = ep;
req->req.length = 2;
req->req.status = -EINPROGRESS;
req->req.actual = 0;
req->req.complete = NULL;
req->dtd_count = 0;
ret = usb_gadget_map_request(&ep->udc->gadget, &req->req, ep_is_in(ep));
if (ret)
goto stall;
if ((fsl_req_to_dtd(req, GFP_ATOMIC) == 0))
fsl_queue_td(ep, req);
else
goto stall;
list_add_tail(&req->queue, &ep->queue);
udc->ep0_state = DATA_STATE_XMIT;
if (ep0_prime_status(udc, EP_DIR_OUT))
ep0stall(udc);
return;
stall:
ep0stall(udc);
}
static void setup_received_irq(struct fsl_udc *udc,
struct usb_ctrlrequest *setup)
{
u16 wValue = le16_to_cpu(setup->wValue);
u16 wIndex = le16_to_cpu(setup->wIndex);
u16 wLength = le16_to_cpu(setup->wLength);
udc_reset_ep_queue(udc, 0);
switch (setup->bRequest) {
case USB_REQ_GET_STATUS:
if ((setup->bRequestType & (USB_DIR_IN | USB_TYPE_MASK))
!= (USB_DIR_IN | USB_TYPE_STANDARD))
break;
ch9getstatus(udc, setup->bRequestType, wValue, wIndex, wLength);
return;
case USB_REQ_SET_ADDRESS:
if (setup->bRequestType != (USB_DIR_OUT | USB_TYPE_STANDARD
| USB_RECIP_DEVICE))
break;
ch9setaddress(udc, wValue, wIndex, wLength);
return;
case USB_REQ_CLEAR_FEATURE:
case USB_REQ_SET_FEATURE:
{
int rc = -EOPNOTSUPP;
u16 ptc = 0;
if ((setup->bRequestType & (USB_RECIP_MASK | USB_TYPE_MASK))
== (USB_RECIP_ENDPOINT | USB_TYPE_STANDARD)) {
int pipe = get_pipe_by_windex(wIndex);
struct fsl_ep *ep;
if (wValue != 0 || wLength != 0 || pipe >= udc->max_ep)
break;
ep = get_ep_by_pipe(udc, pipe);
spin_unlock(&udc->lock);
rc = fsl_ep_set_halt(&ep->ep,
(setup->bRequest == USB_REQ_SET_FEATURE)
? 1 : 0);
spin_lock(&udc->lock);
} else if ((setup->bRequestType & (USB_RECIP_MASK
| USB_TYPE_MASK)) == (USB_RECIP_DEVICE
| USB_TYPE_STANDARD)) {
if (wValue == USB_DEVICE_TEST_MODE)
ptc = wIndex >> 8;
else if (gadget_is_otg(&udc->gadget)) {
if (setup->bRequest ==
USB_DEVICE_B_HNP_ENABLE)
udc->gadget.b_hnp_enable = 1;
else if (setup->bRequest ==
USB_DEVICE_A_HNP_SUPPORT)
udc->gadget.a_hnp_support = 1;
else if (setup->bRequest ==
USB_DEVICE_A_ALT_HNP_SUPPORT)
udc->gadget.a_alt_hnp_support = 1;
}
rc = 0;
} else
break;
if (rc == 0) {
if (ep0_prime_status(udc, EP_DIR_IN))
ep0stall(udc);
}
if (ptc) {
u32 tmp;
mdelay(10);
tmp = fsl_readl(&dr_regs->portsc1) | (ptc << 16);
fsl_writel(tmp, &dr_regs->portsc1);
printk(KERN_INFO "udc: switch to test mode %d.\n", ptc);
}
return;
}
default:
break;
}
if (wLength) {
udc->ep0_dir = (setup->bRequestType & USB_DIR_IN)
? USB_DIR_IN : USB_DIR_OUT;
spin_unlock(&udc->lock);
if (udc->driver->setup(&udc->gadget,
&udc->local_setup_buff) < 0)
ep0stall(udc);
spin_lock(&udc->lock);
udc->ep0_state = (setup->bRequestType & USB_DIR_IN)
? DATA_STATE_XMIT : DATA_STATE_RECV;
if (udc->ep0_state == DATA_STATE_XMIT)
if (ep0_prime_status(udc, EP_DIR_OUT))
ep0stall(udc);
} else {
udc->ep0_dir = USB_DIR_IN;
spin_unlock(&udc->lock);
if (udc->driver->setup(&udc->gadget,
&udc->local_setup_buff) < 0)
ep0stall(udc);
spin_lock(&udc->lock);
udc->ep0_state = WAIT_FOR_OUT_STATUS;
}
}
static void ep0_req_complete(struct fsl_udc *udc, struct fsl_ep *ep0,
struct fsl_req *req)
{
if (udc->usb_state == USB_STATE_ADDRESS) {
u32 new_address = (u32) udc->device_address;
fsl_writel(new_address << USB_DEVICE_ADDRESS_BIT_POS,
&dr_regs->deviceaddr);
}
done(ep0, req, 0);
switch (udc->ep0_state) {
case DATA_STATE_XMIT:
udc->ep0_state = WAIT_FOR_OUT_STATUS;
break;
case DATA_STATE_RECV:
if (ep0_prime_status(udc, EP_DIR_IN))
ep0stall(udc);
break;
case WAIT_FOR_OUT_STATUS:
udc->ep0_state = WAIT_FOR_SETUP;
break;
case WAIT_FOR_SETUP:
ERR("Unexpect ep0 packets\n");
break;
default:
ep0stall(udc);
break;
}
}
static void tripwire_handler(struct fsl_udc *udc, u8 ep_num, u8 *buffer_ptr)
{
u32 temp;
struct ep_queue_head *qh;
struct fsl_usb2_platform_data *pdata = udc->pdata;
qh = &udc->ep_qh[ep_num * 2 + EP_DIR_OUT];
temp = fsl_readl(&dr_regs->endptsetupstat);
fsl_writel(temp | (1 << ep_num), &dr_regs->endptsetupstat);
do {
temp = fsl_readl(&dr_regs->usbcmd);
fsl_writel(temp | USB_CMD_SUTW, &dr_regs->usbcmd);
if (pdata->le_setup_buf) {
u32 *p = (u32 *)buffer_ptr;
u32 *s = (u32 *)qh->setup_buffer;
*p++ = le32_to_cpu(*s++);
*p = le32_to_cpu(*s);
} else {
memcpy(buffer_ptr, (u8 *) qh->setup_buffer, 8);
}
} while (!(fsl_readl(&dr_regs->usbcmd) & USB_CMD_SUTW));
temp = fsl_readl(&dr_regs->usbcmd);
fsl_writel(temp & ~USB_CMD_SUTW, &dr_regs->usbcmd);
}
static int process_ep_req(struct fsl_udc *udc, int pipe,
struct fsl_req *curr_req)
{
struct ep_td_struct *curr_td;
int td_complete, actual, remaining_length, j, tmp;
int status = 0;
int errors = 0;
struct ep_queue_head *curr_qh = &udc->ep_qh[pipe];
int direction = pipe % 2;
curr_td = curr_req->head;
td_complete = 0;
actual = curr_req->req.length;
for (j = 0; j < curr_req->dtd_count; j++) {
remaining_length = (hc32_to_cpu(curr_td->size_ioc_sts)
& DTD_PACKET_SIZE)
>> DTD_LENGTH_BIT_POS;
actual -= remaining_length;
errors = hc32_to_cpu(curr_td->size_ioc_sts);
if (errors & DTD_ERROR_MASK) {
if (errors & DTD_STATUS_HALTED) {
ERR("dTD error %08x QH=%d\n", errors, pipe);
tmp = hc32_to_cpu(curr_qh->size_ioc_int_sts);
tmp &= ~errors;
curr_qh->size_ioc_int_sts = cpu_to_hc32(tmp);
status = -EPIPE;
break;
}
if (errors & DTD_STATUS_DATA_BUFF_ERR) {
VDBG("Transfer overflow");
status = -EPROTO;
break;
} else if (errors & DTD_STATUS_TRANSACTION_ERR) {
VDBG("ISO error");
status = -EILSEQ;
break;
} else
ERR("Unknown error has occurred (0x%x)!\n",
errors);
} else if (hc32_to_cpu(curr_td->size_ioc_sts)
& DTD_STATUS_ACTIVE) {
VDBG("Request not complete");
status = REQ_UNCOMPLETE;
return status;
} else if (remaining_length) {
if (direction) {
VDBG("Transmit dTD remaining length not zero");
status = -EPROTO;
break;
} else {
td_complete++;
break;
}
} else {
td_complete++;
VDBG("dTD transmitted successful");
}
if (j != curr_req->dtd_count - 1)
curr_td = (struct ep_td_struct *)curr_td->next_td_virt;
}
if (status)
return status;
curr_req->req.actual = actual;
return 0;
}
static void dtd_complete_irq(struct fsl_udc *udc)
{
u32 bit_pos;
int i, ep_num, direction, bit_mask, status;
struct fsl_ep *curr_ep;
struct fsl_req *curr_req, *temp_req;
bit_pos = fsl_readl(&dr_regs->endptcomplete);
fsl_writel(bit_pos, &dr_regs->endptcomplete);
if (!bit_pos)
return;
for (i = 0; i < udc->max_ep; i++) {
ep_num = i >> 1;
direction = i % 2;
bit_mask = 1 << (ep_num + 16 * direction);
if (!(bit_pos & bit_mask))
continue;
curr_ep = get_ep_by_pipe(udc, i);
if (curr_ep->name == NULL) {
WARNING("Invalid EP?");
continue;
}
list_for_each_entry_safe(curr_req, temp_req, &curr_ep->queue,
queue) {
status = process_ep_req(udc, i, curr_req);
VDBG("status of process_ep_req= %d, ep = %d",
status, ep_num);
if (status == REQ_UNCOMPLETE)
break;
curr_req->req.status = status;
if (ep_num == 0) {
ep0_req_complete(udc, curr_ep, curr_req);
break;
} else
done(curr_ep, curr_req, status);
}
}
}
static inline enum usb_device_speed portscx_device_speed(u32 reg)
{
switch (reg & PORTSCX_PORT_SPEED_MASK) {
case PORTSCX_PORT_SPEED_HIGH:
return USB_SPEED_HIGH;
case PORTSCX_PORT_SPEED_FULL:
return USB_SPEED_FULL;
case PORTSCX_PORT_SPEED_LOW:
return USB_SPEED_LOW;
default:
return USB_SPEED_UNKNOWN;
}
}
static void port_change_irq(struct fsl_udc *udc)
{
if (udc->bus_reset)
udc->bus_reset = 0;
if (!(fsl_readl(&dr_regs->portsc1) & PORTSCX_PORT_RESET))
udc->gadget.speed =
portscx_device_speed(fsl_readl(&dr_regs->portsc1));
if (!udc->resume_state)
udc->usb_state = USB_STATE_DEFAULT;
}
static void suspend_irq(struct fsl_udc *udc)
{
udc->resume_state = udc->usb_state;
udc->usb_state = USB_STATE_SUSPENDED;
if (udc->driver->suspend)
udc->driver->suspend(&udc->gadget);
}
static void bus_resume(struct fsl_udc *udc)
{
udc->usb_state = udc->resume_state;
udc->resume_state = 0;
if (udc->driver->resume)
udc->driver->resume(&udc->gadget);
}
static int reset_queues(struct fsl_udc *udc)
{
u8 pipe;
for (pipe = 0; pipe < udc->max_pipes; pipe++)
udc_reset_ep_queue(udc, pipe);
spin_unlock(&udc->lock);
udc->driver->disconnect(&udc->gadget);
spin_lock(&udc->lock);
return 0;
}
static void reset_irq(struct fsl_udc *udc)
{
u32 temp;
unsigned long timeout;
temp = fsl_readl(&dr_regs->deviceaddr);
fsl_writel(temp & ~USB_DEVICE_ADDRESS_MASK, &dr_regs->deviceaddr);
udc->device_address = 0;
udc->resume_state = 0;
udc->ep0_dir = 0;
udc->ep0_state = WAIT_FOR_SETUP;
udc->remote_wakeup = 0;
udc->gadget.b_hnp_enable = 0;
udc->gadget.a_hnp_support = 0;
udc->gadget.a_alt_hnp_support = 0;
temp = fsl_readl(&dr_regs->endptsetupstat);
fsl_writel(temp, &dr_regs->endptsetupstat);
temp = fsl_readl(&dr_regs->endptcomplete);
fsl_writel(temp, &dr_regs->endptcomplete);
timeout = jiffies + 100;
while (fsl_readl(&dr_regs->endpointprime)) {
if (time_after(jiffies, timeout)) {
ERR("Timeout for reset\n");
break;
}
cpu_relax();
}
fsl_writel(0xffffffff, &dr_regs->endptflush);
if (fsl_readl(&dr_regs->portsc1) & PORTSCX_PORT_RESET) {
VDBG("Bus reset");
udc->bus_reset = 1;
reset_queues(udc);
udc->usb_state = USB_STATE_DEFAULT;
} else {
VDBG("Controller reset");
dr_controller_setup(udc);
reset_queues(udc);
ep0_setup(udc);
dr_controller_run(udc);
udc->usb_state = USB_STATE_ATTACHED;
}
}
static irqreturn_t fsl_udc_irq(int irq, void *_udc)
{
struct fsl_udc *udc = _udc;
u32 irq_src;
irqreturn_t status = IRQ_NONE;
unsigned long flags;
if (udc->stopped)
return IRQ_NONE;
spin_lock_irqsave(&udc->lock, flags);
irq_src = fsl_readl(&dr_regs->usbsts) & fsl_readl(&dr_regs->usbintr);
fsl_writel(irq_src, &dr_regs->usbsts);
if (udc->usb_state == USB_STATE_SUSPENDED)
if ((fsl_readl(&dr_regs->portsc1) & PORTSCX_PORT_SUSPEND) == 0)
bus_resume(udc);
if (irq_src & USB_STS_INT) {
VDBG("Packet int");
if (fsl_readl(&dr_regs->endptsetupstat) & EP_SETUP_STATUS_EP0) {
tripwire_handler(udc, 0,
(u8 *) (&udc->local_setup_buff));
setup_received_irq(udc, &udc->local_setup_buff);
status = IRQ_HANDLED;
}
if (fsl_readl(&dr_regs->endptcomplete)) {
dtd_complete_irq(udc);
status = IRQ_HANDLED;
}
}
if (irq_src & USB_STS_SOF) {
status = IRQ_HANDLED;
}
if (irq_src & USB_STS_PORT_CHANGE) {
port_change_irq(udc);
status = IRQ_HANDLED;
}
if (irq_src & USB_STS_RESET) {
VDBG("reset int");
reset_irq(udc);
status = IRQ_HANDLED;
}
if (irq_src & USB_STS_SUSPEND) {
suspend_irq(udc);
status = IRQ_HANDLED;
}
if (irq_src & (USB_STS_ERR | USB_STS_SYS_ERR)) {
VDBG("Error IRQ %x", irq_src);
}
spin_unlock_irqrestore(&udc->lock, flags);
return status;
}
static int fsl_udc_start(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
int retval = 0;
unsigned long flags = 0;
spin_lock_irqsave(&udc_controller->lock, flags);
driver->driver.bus = NULL;
udc_controller->driver = driver;
spin_unlock_irqrestore(&udc_controller->lock, flags);
if (!IS_ERR_OR_NULL(udc_controller->transceiver)) {
udc_controller->stopped = 1;
printk(KERN_INFO "Suspend udc for OTG auto detect\n");
if (!IS_ERR_OR_NULL(udc_controller->transceiver)) {
retval = otg_set_peripheral(
udc_controller->transceiver->otg,
&udc_controller->gadget);
if (retval < 0) {
ERR("can't bind to transceiver\n");
driver->unbind(&udc_controller->gadget);
udc_controller->driver = 0;
return retval;
}
}
} else {
dr_controller_run(udc_controller);
udc_controller->usb_state = USB_STATE_ATTACHED;
udc_controller->ep0_state = WAIT_FOR_SETUP;
udc_controller->ep0_dir = 0;
}
return retval;
}
static int fsl_udc_stop(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct fsl_ep *loop_ep;
unsigned long flags;
if (!IS_ERR_OR_NULL(udc_controller->transceiver))
otg_set_peripheral(udc_controller->transceiver->otg, NULL);
dr_controller_stop(udc_controller);
udc_controller->usb_state = USB_STATE_ATTACHED;
udc_controller->ep0_state = WAIT_FOR_SETUP;
udc_controller->ep0_dir = 0;
spin_lock_irqsave(&udc_controller->lock, flags);
udc_controller->gadget.speed = USB_SPEED_UNKNOWN;
nuke(&udc_controller->eps[0], -ESHUTDOWN);
list_for_each_entry(loop_ep, &udc_controller->gadget.ep_list,
ep.ep_list)
nuke(loop_ep, -ESHUTDOWN);
spin_unlock_irqrestore(&udc_controller->lock, flags);
udc_controller->driver = NULL;
return 0;
}
static int fsl_proc_read(struct seq_file *m, void *v)
{
unsigned long flags;
int i;
u32 tmp_reg;
struct fsl_ep *ep = NULL;
struct fsl_req *req;
struct fsl_udc *udc = udc_controller;
spin_lock_irqsave(&udc->lock, flags);
seq_printf(m,
DRIVER_DESC "\n"
"%s version: %s\n"
"Gadget driver: %s\n\n",
driver_name, DRIVER_VERSION,
udc->driver ? udc->driver->driver.name : "(none)");
tmp_reg = fsl_readl(&dr_regs->usbcmd);
seq_printf(m,
"USBCMD reg:\n"
"SetupTW: %d\n"
"Run/Stop: %s\n\n",
(tmp_reg & USB_CMD_SUTW) ? 1 : 0,
(tmp_reg & USB_CMD_RUN_STOP) ? "Run" : "Stop");
tmp_reg = fsl_readl(&dr_regs->usbsts);
seq_printf(m,
"USB Status Reg:\n"
"Dr Suspend: %d Reset Received: %d System Error: %s "
"USB Error Interrupt: %s\n\n",
(tmp_reg & USB_STS_SUSPEND) ? 1 : 0,
(tmp_reg & USB_STS_RESET) ? 1 : 0,
(tmp_reg & USB_STS_SYS_ERR) ? "Err" : "Normal",
(tmp_reg & USB_STS_ERR) ? "Err detected" : "No err");
tmp_reg = fsl_readl(&dr_regs->usbintr);
seq_printf(m,
"USB Interrupt Enable Reg:\n"
"Sleep Enable: %d SOF Received Enable: %d "
"Reset Enable: %d\n"
"System Error Enable: %d "
"Port Change Dectected Enable: %d\n"
"USB Error Intr Enable: %d USB Intr Enable: %d\n\n",
(tmp_reg & USB_INTR_DEVICE_SUSPEND) ? 1 : 0,
(tmp_reg & USB_INTR_SOF_EN) ? 1 : 0,
(tmp_reg & USB_INTR_RESET_EN) ? 1 : 0,
(tmp_reg & USB_INTR_SYS_ERR_EN) ? 1 : 0,
(tmp_reg & USB_INTR_PTC_DETECT_EN) ? 1 : 0,
(tmp_reg & USB_INTR_ERR_INT_EN) ? 1 : 0,
(tmp_reg & USB_INTR_INT_EN) ? 1 : 0);
tmp_reg = fsl_readl(&dr_regs->frindex);
seq_printf(m,
"USB Frame Index Reg: Frame Number is 0x%x\n\n",
(tmp_reg & USB_FRINDEX_MASKS));
tmp_reg = fsl_readl(&dr_regs->deviceaddr);
seq_printf(m,
"USB Device Address Reg: Device Addr is 0x%x\n\n",
(tmp_reg & USB_DEVICE_ADDRESS_MASK));
tmp_reg = fsl_readl(&dr_regs->endpointlistaddr);
seq_printf(m,
"USB Endpoint List Address Reg: "
"Device Addr is 0x%x\n\n",
(tmp_reg & USB_EP_LIST_ADDRESS_MASK));
tmp_reg = fsl_readl(&dr_regs->portsc1);
seq_printf(m,
"USB Port Status&Control Reg:\n"
"Port Transceiver Type : %s Port Speed: %s\n"
"PHY Low Power Suspend: %s Port Reset: %s "
"Port Suspend Mode: %s\n"
"Over-current Change: %s "
"Port Enable/Disable Change: %s\n"
"Port Enabled/Disabled: %s "
"Current Connect Status: %s\n\n", ( {
const char *s;
switch (tmp_reg & PORTSCX_PTS_FSLS) {
case PORTSCX_PTS_UTMI:
s = "UTMI"; break;
case PORTSCX_PTS_ULPI:
s = "ULPI "; break;
case PORTSCX_PTS_FSLS:
s = "FS/LS Serial"; break;
default:
s = "None"; break;
}
s;} ),
usb_speed_string(portscx_device_speed(tmp_reg)),
(tmp_reg & PORTSCX_PHY_LOW_POWER_SPD) ?
"Normal PHY mode" : "Low power mode",
(tmp_reg & PORTSCX_PORT_RESET) ? "In Reset" :
"Not in Reset",
(tmp_reg & PORTSCX_PORT_SUSPEND) ? "In " : "Not in",
(tmp_reg & PORTSCX_OVER_CURRENT_CHG) ? "Dected" :
"No",
(tmp_reg & PORTSCX_PORT_EN_DIS_CHANGE) ? "Disable" :
"Not change",
(tmp_reg & PORTSCX_PORT_ENABLE) ? "Enable" :
"Not correct",
(tmp_reg & PORTSCX_CURRENT_CONNECT_STATUS) ?
"Attached" : "Not-Att");
tmp_reg = fsl_readl(&dr_regs->usbmode);
seq_printf(m,
"USB Mode Reg: Controller Mode is: %s\n\n", ( {
const char *s;
switch (tmp_reg & USB_MODE_CTRL_MODE_HOST) {
case USB_MODE_CTRL_MODE_IDLE:
s = "Idle"; break;
case USB_MODE_CTRL_MODE_DEVICE:
s = "Device Controller"; break;
case USB_MODE_CTRL_MODE_HOST:
s = "Host Controller"; break;
default:
s = "None"; break;
}
s;
} ));
tmp_reg = fsl_readl(&dr_regs->endptsetupstat);
seq_printf(m,
"Endpoint Setup Status Reg: SETUP on ep 0x%x\n\n",
(tmp_reg & EP_SETUP_STATUS_MASK));
for (i = 0; i < udc->max_ep / 2; i++) {
tmp_reg = fsl_readl(&dr_regs->endptctrl[i]);
seq_printf(m, "EP Ctrl Reg [0x%x]: = [0x%x]\n", i, tmp_reg);
}
tmp_reg = fsl_readl(&dr_regs->endpointprime);
seq_printf(m, "EP Prime Reg = [0x%x]\n\n", tmp_reg);
#ifndef CONFIG_ARCH_MXC
if (udc->pdata->have_sysif_regs) {
tmp_reg = usb_sys_regs->snoop1;
seq_printf(m, "Snoop1 Reg : = [0x%x]\n\n", tmp_reg);
tmp_reg = usb_sys_regs->control;
seq_printf(m, "General Control Reg : = [0x%x]\n\n", tmp_reg);
}
#endif
ep = &udc->eps[0];
seq_printf(m, "For %s Maxpkt is 0x%x index is 0x%x\n",
ep->ep.name, ep_maxpacket(ep), ep_index(ep));
if (list_empty(&ep->queue)) {
seq_puts(m, "its req queue is empty\n\n");
} else {
list_for_each_entry(req, &ep->queue, queue) {
seq_printf(m,
"req %p actual 0x%x length 0x%x buf %p\n",
&req->req, req->req.actual,
req->req.length, req->req.buf);
}
}
list_for_each_entry(ep, &udc->gadget.ep_list, ep.ep_list) {
if (ep->ep.desc) {
seq_printf(m,
"\nFor %s Maxpkt is 0x%x "
"index is 0x%x\n",
ep->ep.name, ep_maxpacket(ep),
ep_index(ep));
if (list_empty(&ep->queue)) {
seq_puts(m, "its req queue is empty\n\n");
} else {
list_for_each_entry(req, &ep->queue, queue) {
seq_printf(m,
"req %p actual 0x%x length "
"0x%x buf %p\n",
&req->req, req->req.actual,
req->req.length, req->req.buf);
}
}
}
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int fsl_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, fsl_proc_read, NULL);
}
static void fsl_udc_release(struct device *dev)
{
complete(udc_controller->done);
dma_free_coherent(dev->parent, udc_controller->ep_qh_size,
udc_controller->ep_qh, udc_controller->ep_qh_dma);
kfree(udc_controller);
}
static int __init struct_udc_setup(struct fsl_udc *udc,
struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata;
size_t size;
pdata = dev_get_platdata(&pdev->dev);
udc->phy_mode = pdata->phy_mode;
udc->eps = kzalloc(sizeof(struct fsl_ep) * udc->max_ep, GFP_KERNEL);
if (!udc->eps) {
ERR("malloc fsl_ep failed\n");
return -1;
}
size = udc->max_ep * sizeof(struct ep_queue_head);
if (size < QH_ALIGNMENT)
size = QH_ALIGNMENT;
else if ((size % QH_ALIGNMENT) != 0) {
size += QH_ALIGNMENT + 1;
size &= ~(QH_ALIGNMENT - 1);
}
udc->ep_qh = dma_alloc_coherent(&pdev->dev, size,
&udc->ep_qh_dma, GFP_KERNEL);
if (!udc->ep_qh) {
ERR("malloc QHs for udc failed\n");
kfree(udc->eps);
return -1;
}
udc->ep_qh_size = size;
udc->status_req = container_of(fsl_alloc_request(NULL, GFP_KERNEL),
struct fsl_req, req);
udc->status_req->req.buf = kmalloc(8, GFP_KERNEL);
udc->resume_state = USB_STATE_NOTATTACHED;
udc->usb_state = USB_STATE_POWERED;
udc->ep0_dir = 0;
udc->remote_wakeup = 0;
return 0;
}
static int __init struct_ep_setup(struct fsl_udc *udc, unsigned char index,
char *name, int link)
{
struct fsl_ep *ep = &udc->eps[index];
ep->udc = udc;
strcpy(ep->name, name);
ep->ep.name = ep->name;
ep->ep.ops = &fsl_ep_ops;
ep->stopped = 0;
usb_ep_set_maxpacket_limit(&ep->ep, (unsigned short) ~0);
INIT_LIST_HEAD(&ep->queue);
if (link)
list_add_tail(&ep->ep.ep_list, &udc->gadget.ep_list);
ep->gadget = &udc->gadget;
ep->qh = &udc->ep_qh[index];
return 0;
}
static int __init fsl_udc_probe(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata;
struct resource *res;
int ret = -ENODEV;
unsigned int i;
u32 dccparams;
udc_controller = kzalloc(sizeof(struct fsl_udc), GFP_KERNEL);
if (udc_controller == NULL) {
ERR("malloc udc failed\n");
return -ENOMEM;
}
pdata = dev_get_platdata(&pdev->dev);
udc_controller->pdata = pdata;
spin_lock_init(&udc_controller->lock);
udc_controller->stopped = 1;
#ifdef CONFIG_USB_OTG
if (pdata->operating_mode == FSL_USB2_DR_OTG) {
udc_controller->transceiver = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(udc_controller->transceiver)) {
ERR("Can't find OTG driver!\n");
ret = -ENODEV;
goto err_kfree;
}
}
#endif
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENXIO;
goto err_kfree;
}
if (pdata->operating_mode == FSL_USB2_DR_DEVICE) {
if (!request_mem_region(res->start, resource_size(res),
driver_name)) {
ERR("request mem region for %s failed\n", pdev->name);
ret = -EBUSY;
goto err_kfree;
}
}
dr_regs = ioremap(res->start, resource_size(res));
if (!dr_regs) {
ret = -ENOMEM;
goto err_release_mem_region;
}
pdata->regs = (void *)dr_regs;
if (pdata->init && pdata->init(pdev)) {
ret = -ENODEV;
goto err_iounmap_noclk;
}
fsl_set_accessors(pdata);
#ifndef CONFIG_ARCH_MXC
if (pdata->have_sysif_regs)
usb_sys_regs = (void *)dr_regs + USB_DR_SYS_OFFSET;
#endif
ret = fsl_udc_clk_init(pdev);
if (ret < 0)
goto err_iounmap_noclk;
dccparams = fsl_readl(&dr_regs->dccparams);
if (!(dccparams & DCCPARAMS_DC)) {
ERR("This SOC doesn't support device role\n");
ret = -ENODEV;
goto err_iounmap;
}
udc_controller->max_ep = (dccparams & DCCPARAMS_DEN_MASK) * 2;
udc_controller->irq = platform_get_irq(pdev, 0);
if (!udc_controller->irq) {
ret = -ENODEV;
goto err_iounmap;
}
ret = request_irq(udc_controller->irq, fsl_udc_irq, IRQF_SHARED,
driver_name, udc_controller);
if (ret != 0) {
ERR("cannot request irq %d err %d\n",
udc_controller->irq, ret);
goto err_iounmap;
}
if (struct_udc_setup(udc_controller, pdev)) {
ERR("Can't initialize udc data structure\n");
ret = -ENOMEM;
goto err_free_irq;
}
if (IS_ERR_OR_NULL(udc_controller->transceiver)) {
dr_controller_setup(udc_controller);
}
ret = fsl_udc_clk_finalize(pdev);
if (ret)
goto err_free_irq;
udc_controller->gadget.ops = &fsl_gadget_ops;
udc_controller->gadget.max_speed = USB_SPEED_HIGH;
udc_controller->gadget.ep0 = &udc_controller->eps[0].ep;
INIT_LIST_HEAD(&udc_controller->gadget.ep_list);
udc_controller->gadget.speed = USB_SPEED_UNKNOWN;
udc_controller->gadget.name = driver_name;
dev_set_name(&udc_controller->gadget.dev, "gadget");
udc_controller->gadget.dev.of_node = pdev->dev.of_node;
if (!IS_ERR_OR_NULL(udc_controller->transceiver))
udc_controller->gadget.is_otg = 1;
ep0_setup(udc_controller);
struct_ep_setup(udc_controller, 0, "ep0", 0);
udc_controller->eps[0].ep.desc = &fsl_ep0_desc;
usb_ep_set_maxpacket_limit(&udc_controller->eps[0].ep,
USB_MAX_CTRL_PAYLOAD);
for (i = 1; i < (int)(udc_controller->max_ep / 2); i++) {
char name[14];
sprintf(name, "ep%dout", i);
struct_ep_setup(udc_controller, i * 2, name, 1);
sprintf(name, "ep%din", i);
struct_ep_setup(udc_controller, i * 2 + 1, name, 1);
}
udc_controller->td_pool = dma_pool_create("udc_td", &pdev->dev,
sizeof(struct ep_td_struct),
DTD_ALIGNMENT, UDC_DMA_BOUNDARY);
if (udc_controller->td_pool == NULL) {
ret = -ENOMEM;
goto err_free_irq;
}
ret = usb_add_gadget_udc_release(&pdev->dev, &udc_controller->gadget,
fsl_udc_release);
if (ret)
goto err_del_udc;
create_proc_file();
return 0;
err_del_udc:
dma_pool_destroy(udc_controller->td_pool);
err_free_irq:
free_irq(udc_controller->irq, udc_controller);
err_iounmap:
if (pdata->exit)
pdata->exit(pdev);
fsl_udc_clk_release();
err_iounmap_noclk:
iounmap(dr_regs);
err_release_mem_region:
if (pdata->operating_mode == FSL_USB2_DR_DEVICE)
release_mem_region(res->start, resource_size(res));
err_kfree:
kfree(udc_controller);
udc_controller = NULL;
return ret;
}
static int __exit fsl_udc_remove(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
DECLARE_COMPLETION(done);
if (!udc_controller)
return -ENODEV;
usb_del_gadget_udc(&udc_controller->gadget);
udc_controller->done = &done;
fsl_udc_clk_release();
remove_proc_file();
kfree(udc_controller->status_req->req.buf);
kfree(udc_controller->status_req);
kfree(udc_controller->eps);
dma_pool_destroy(udc_controller->td_pool);
free_irq(udc_controller->irq, udc_controller);
iounmap(dr_regs);
if (pdata->operating_mode == FSL_USB2_DR_DEVICE)
release_mem_region(res->start, resource_size(res));
wait_for_completion(&done);
if (pdata->exit)
pdata->exit(pdev);
return 0;
}
static int fsl_udc_suspend(struct platform_device *pdev, pm_message_t state)
{
dr_controller_stop(udc_controller);
return 0;
}
static int fsl_udc_resume(struct platform_device *pdev)
{
if (udc_controller->stopped) {
dr_controller_setup(udc_controller);
dr_controller_run(udc_controller);
}
udc_controller->usb_state = USB_STATE_ATTACHED;
udc_controller->ep0_state = WAIT_FOR_SETUP;
udc_controller->ep0_dir = 0;
return 0;
}
static int fsl_udc_otg_suspend(struct device *dev, pm_message_t state)
{
struct fsl_udc *udc = udc_controller;
u32 mode, usbcmd;
mode = fsl_readl(&dr_regs->usbmode) & USB_MODE_CTRL_MODE_MASK;
pr_debug("%s(): mode 0x%x stopped %d\n", __func__, mode, udc->stopped);
if (udc->stopped) {
pr_debug("gadget already stopped, leaving early\n");
udc->already_stopped = 1;
return 0;
}
if (mode != USB_MODE_CTRL_MODE_DEVICE) {
pr_debug("gadget not in device mode, leaving early\n");
return 0;
}
usbcmd = fsl_readl(&dr_regs->usbcmd) & ~USB_CMD_RUN_STOP;
fsl_writel(usbcmd, &dr_regs->usbcmd);
udc->stopped = 1;
pr_info("USB Gadget suspended\n");
return 0;
}
static int fsl_udc_otg_resume(struct device *dev)
{
pr_debug("%s(): stopped %d already_stopped %d\n", __func__,
udc_controller->stopped, udc_controller->already_stopped);
if (udc_controller->already_stopped) {
udc_controller->already_stopped = 0;
pr_debug("gadget was already stopped, leaving early\n");
return 0;
}
pr_info("USB Gadget resume\n");
return fsl_udc_resume(NULL);
}
