static inline struct bcm63xx_udc *gadget_to_udc(struct usb_gadget *g)
{
return container_of(g, struct bcm63xx_udc, gadget);
}
static inline struct bcm63xx_ep *our_ep(struct usb_ep *ep)
{
return container_of(ep, struct bcm63xx_ep, ep);
}
static inline struct bcm63xx_req *our_req(struct usb_request *req)
{
return container_of(req, struct bcm63xx_req, req);
}
static inline u32 usbd_readl(struct bcm63xx_udc *udc, u32 off)
{
return bcm_readl(udc->usbd_regs + off);
}
static inline void usbd_writel(struct bcm63xx_udc *udc, u32 val, u32 off)
{
bcm_writel(val, udc->usbd_regs + off);
}
static inline u32 usb_dma_readl(struct bcm63xx_udc *udc, u32 off)
{
return bcm_readl(udc->iudma_regs + off);
}
static inline void usb_dma_writel(struct bcm63xx_udc *udc, u32 val, u32 off)
{
bcm_writel(val, udc->iudma_regs + off);
}
static inline u32 usb_dmac_readl(struct bcm63xx_udc *udc, u32 off, int chan)
{
return bcm_readl(udc->iudma_regs + IUDMA_DMAC_OFFSET + off +
(ENETDMA_CHAN_WIDTH * chan));
}
static inline void usb_dmac_writel(struct bcm63xx_udc *udc, u32 val, u32 off,
int chan)
{
bcm_writel(val, udc->iudma_regs + IUDMA_DMAC_OFFSET + off +
(ENETDMA_CHAN_WIDTH * chan));
}
static inline u32 usb_dmas_readl(struct bcm63xx_udc *udc, u32 off, int chan)
{
return bcm_readl(udc->iudma_regs + IUDMA_DMAS_OFFSET + off +
(ENETDMA_CHAN_WIDTH * chan));
}
static inline void usb_dmas_writel(struct bcm63xx_udc *udc, u32 val, u32 off,
int chan)
{
bcm_writel(val, udc->iudma_regs + IUDMA_DMAS_OFFSET + off +
(ENETDMA_CHAN_WIDTH * chan));
}
static inline void set_clocks(struct bcm63xx_udc *udc, bool is_enabled)
{
if (is_enabled) {
clk_enable(udc->usbh_clk);
clk_enable(udc->usbd_clk);
udelay(10);
} else {
clk_disable(udc->usbd_clk);
clk_disable(udc->usbh_clk);
}
}
static void bcm63xx_ep_dma_select(struct bcm63xx_udc *udc, int idx)
{
u32 val = usbd_readl(udc, USBD_CONTROL_REG);
val &= ~USBD_CONTROL_INIT_SEL_MASK;
val |= idx << USBD_CONTROL_INIT_SEL_SHIFT;
usbd_writel(udc, val, USBD_CONTROL_REG);
}
static void bcm63xx_set_stall(struct bcm63xx_udc *udc, struct bcm63xx_ep *bep,
bool is_stalled)
{
u32 val;
val = USBD_STALL_UPDATE_MASK |
(is_stalled ? USBD_STALL_ENABLE_MASK : 0) |
(bep->ep_num << USBD_STALL_EPNUM_SHIFT);
usbd_writel(udc, val, USBD_STALL_REG);
}
static void bcm63xx_fifo_setup(struct bcm63xx_udc *udc)
{
int is_hs = udc->gadget.speed == USB_SPEED_HIGH;
u32 i, val, rx_fifo_slot, tx_fifo_slot;
rx_fifo_slot = tx_fifo_slot = 0;
for (i = 0; i < BCM63XX_NUM_IUDMA; i += 2) {
const struct iudma_ch_cfg *rx_cfg = &iudma_defaults[i];
const struct iudma_ch_cfg *tx_cfg = &iudma_defaults[i + 1];
bcm63xx_ep_dma_select(udc, i >> 1);
val = (rx_fifo_slot << USBD_RXFIFO_CONFIG_START_SHIFT) |
((rx_fifo_slot + rx_cfg->n_fifo_slots - 1) <<
USBD_RXFIFO_CONFIG_END_SHIFT);
rx_fifo_slot += rx_cfg->n_fifo_slots;
usbd_writel(udc, val, USBD_RXFIFO_CONFIG_REG);
usbd_writel(udc,
is_hs ? rx_cfg->max_pkt_hs : rx_cfg->max_pkt_fs,
USBD_RXFIFO_EPSIZE_REG);
val = (tx_fifo_slot << USBD_TXFIFO_CONFIG_START_SHIFT) |
((tx_fifo_slot + tx_cfg->n_fifo_slots - 1) <<
USBD_TXFIFO_CONFIG_END_SHIFT);
tx_fifo_slot += tx_cfg->n_fifo_slots;
usbd_writel(udc, val, USBD_TXFIFO_CONFIG_REG);
usbd_writel(udc,
is_hs ? tx_cfg->max_pkt_hs : tx_cfg->max_pkt_fs,
USBD_TXFIFO_EPSIZE_REG);
usbd_readl(udc, USBD_TXFIFO_EPSIZE_REG);
}
}
static void bcm63xx_fifo_reset_ep(struct bcm63xx_udc *udc, int ep_num)
{
u32 val;
bcm63xx_ep_dma_select(udc, ep_num);
val = usbd_readl(udc, USBD_CONTROL_REG);
val |= USBD_CONTROL_FIFO_RESET_MASK;
usbd_writel(udc, val, USBD_CONTROL_REG);
usbd_readl(udc, USBD_CONTROL_REG);
}
static void bcm63xx_fifo_reset(struct bcm63xx_udc *udc)
{
int i;
for (i = 0; i < BCM63XX_NUM_FIFO_PAIRS; i++)
bcm63xx_fifo_reset_ep(udc, i);
}
static void bcm63xx_ep_init(struct bcm63xx_udc *udc)
{
u32 i, val;
for (i = 0; i < BCM63XX_NUM_IUDMA; i++) {
const struct iudma_ch_cfg *cfg = &iudma_defaults[i];
if (cfg->ep_num < 0)
continue;
bcm63xx_ep_dma_select(udc, cfg->ep_num);
val = (cfg->ep_type << USBD_EPNUM_TYPEMAP_TYPE_SHIFT) |
((i >> 1) << USBD_EPNUM_TYPEMAP_DMA_CH_SHIFT);
usbd_writel(udc, val, USBD_EPNUM_TYPEMAP_REG);
}
}
static void bcm63xx_ep_setup(struct bcm63xx_udc *udc)
{
u32 val, i;
usbd_writel(udc, USBD_CSR_SETUPADDR_DEF, USBD_CSR_SETUPADDR_REG);
for (i = 0; i < BCM63XX_NUM_IUDMA; i++) {
const struct iudma_ch_cfg *cfg = &iudma_defaults[i];
int max_pkt = udc->gadget.speed == USB_SPEED_HIGH ?
cfg->max_pkt_hs : cfg->max_pkt_fs;
int idx = cfg->ep_num;
udc->iudma[i].max_pkt = max_pkt;
if (idx < 0)
continue;
usb_ep_set_maxpacket_limit(&udc->bep[idx].ep, max_pkt);
val = (idx << USBD_CSR_EP_LOG_SHIFT) |
(cfg->dir << USBD_CSR_EP_DIR_SHIFT) |
(cfg->ep_type << USBD_CSR_EP_TYPE_SHIFT) |
(udc->cfg << USBD_CSR_EP_CFG_SHIFT) |
(udc->iface << USBD_CSR_EP_IFACE_SHIFT) |
(udc->alt_iface << USBD_CSR_EP_ALTIFACE_SHIFT) |
(max_pkt << USBD_CSR_EP_MAXPKT_SHIFT);
usbd_writel(udc, val, USBD_CSR_EP_REG(idx));
}
}
static void iudma_write(struct bcm63xx_udc *udc, struct iudma_ch *iudma,
struct bcm63xx_req *breq)
{
int first_bd = 1, last_bd = 0, extra_zero_pkt = 0;
unsigned int bytes_left = breq->req.length - breq->offset;
const int max_bd_bytes = !irq_coalesce && !iudma->is_tx ?
iudma->max_pkt : IUDMA_MAX_FRAGMENT;
iudma->n_bds_used = 0;
breq->bd_bytes = 0;
breq->iudma = iudma;
if ((bytes_left % iudma->max_pkt == 0) && bytes_left && breq->req.zero)
extra_zero_pkt = 1;
do {
struct bcm_enet_desc *d = iudma->write_bd;
u32 dmaflags = 0;
unsigned int n_bytes;
if (d == iudma->end_bd) {
dmaflags |= DMADESC_WRAP_MASK;
iudma->write_bd = iudma->bd_ring;
} else {
iudma->write_bd++;
}
iudma->n_bds_used++;
n_bytes = min_t(int, bytes_left, max_bd_bytes);
if (n_bytes)
dmaflags |= n_bytes << DMADESC_LENGTH_SHIFT;
else
dmaflags |= (1 << DMADESC_LENGTH_SHIFT) |
DMADESC_USB_ZERO_MASK;
dmaflags |= DMADESC_OWNER_MASK;
if (first_bd) {
dmaflags |= DMADESC_SOP_MASK;
first_bd = 0;
}
if (extra_zero_pkt && !bytes_left)
extra_zero_pkt = 0;
if (!iudma->is_tx || iudma->n_bds_used == iudma->n_bds ||
(n_bytes == bytes_left && !extra_zero_pkt)) {
last_bd = 1;
dmaflags |= DMADESC_EOP_MASK;
}
d->address = breq->req.dma + breq->offset;
mb();
d->len_stat = dmaflags;
breq->offset += n_bytes;
breq->bd_bytes += n_bytes;
bytes_left -= n_bytes;
} while (!last_bd);
usb_dmac_writel(udc, ENETDMAC_CHANCFG_EN_MASK,
ENETDMAC_CHANCFG_REG, iudma->ch_idx);
}
static int iudma_read(struct bcm63xx_udc *udc, struct iudma_ch *iudma)
{
int i, actual_len = 0;
struct bcm_enet_desc *d = iudma->read_bd;
if (!iudma->n_bds_used)
return -EINVAL;
for (i = 0; i < iudma->n_bds_used; i++) {
u32 dmaflags;
dmaflags = d->len_stat;
if (dmaflags & DMADESC_OWNER_MASK)
return -EBUSY;
actual_len += (dmaflags & DMADESC_LENGTH_MASK) >>
DMADESC_LENGTH_SHIFT;
if (d == iudma->end_bd)
d = iudma->bd_ring;
else
d++;
}
iudma->read_bd = d;
iudma->n_bds_used = 0;
return actual_len;
}
static void iudma_reset_channel(struct bcm63xx_udc *udc, struct iudma_ch *iudma)
{
int timeout = IUDMA_RESET_TIMEOUT_US;
struct bcm_enet_desc *d;
int ch_idx = iudma->ch_idx;
if (!iudma->is_tx)
bcm63xx_fifo_reset_ep(udc, max(0, iudma->ep_num));
usb_dmac_writel(udc, 0, ENETDMAC_CHANCFG_REG, ch_idx);
while (usb_dmac_readl(udc, ENETDMAC_CHANCFG_REG, ch_idx) &
ENETDMAC_CHANCFG_EN_MASK) {
udelay(1);
if (iudma->is_tx && iudma->ep_num >= 0)
bcm63xx_fifo_reset_ep(udc, iudma->ep_num);
if (!timeout--) {
dev_err(udc->dev, "can't reset IUDMA channel %d\n",
ch_idx);
break;
}
if (timeout == IUDMA_RESET_TIMEOUT_US / 2) {
dev_warn(udc->dev, "forcibly halting IUDMA channel %d\n",
ch_idx);
usb_dmac_writel(udc, ENETDMAC_CHANCFG_BUFHALT_MASK,
ENETDMAC_CHANCFG_REG, ch_idx);
}
}
usb_dmac_writel(udc, ~0, ENETDMAC_IR_REG, ch_idx);
for (d = iudma->bd_ring; d <= iudma->end_bd; d++)
d->len_stat = 0;
mb();
iudma->read_bd = iudma->write_bd = iudma->bd_ring;
iudma->n_bds_used = 0;
usb_dmac_writel(udc, ENETDMAC_IR_BUFDONE_MASK,
ENETDMAC_IRMASK_REG, ch_idx);
usb_dmac_writel(udc, 8, ENETDMAC_MAXBURST_REG, ch_idx);
usb_dmas_writel(udc, iudma->bd_ring_dma, ENETDMAS_RSTART_REG, ch_idx);
usb_dmas_writel(udc, 0, ENETDMAS_SRAM2_REG, ch_idx);
}
static int iudma_init_channel(struct bcm63xx_udc *udc, unsigned int ch_idx)
{
struct iudma_ch *iudma = &udc->iudma[ch_idx];
const struct iudma_ch_cfg *cfg = &iudma_defaults[ch_idx];
unsigned int n_bds = cfg->n_bds;
struct bcm63xx_ep *bep = NULL;
iudma->ep_num = cfg->ep_num;
iudma->ch_idx = ch_idx;
iudma->is_tx = !!(ch_idx & 0x01);
if (iudma->ep_num >= 0) {
bep = &udc->bep[iudma->ep_num];
bep->iudma = iudma;
INIT_LIST_HEAD(&bep->queue);
}
iudma->bep = bep;
iudma->udc = udc;
if (iudma->ep_num <= 0)
iudma->enabled = true;
iudma->n_bds = n_bds;
iudma->bd_ring = dmam_alloc_coherent(udc->dev,
n_bds * sizeof(struct bcm_enet_desc),
&iudma->bd_ring_dma, GFP_KERNEL);
if (!iudma->bd_ring)
return -ENOMEM;
iudma->end_bd = &iudma->bd_ring[n_bds - 1];
return 0;
}
static int iudma_init(struct bcm63xx_udc *udc)
{
int i, rc;
usb_dma_writel(udc, ENETDMA_CFG_EN_MASK, ENETDMA_CFG_REG);
for (i = 0; i < BCM63XX_NUM_IUDMA; i++) {
rc = iudma_init_channel(udc, i);
if (rc)
return rc;
iudma_reset_channel(udc, &udc->iudma[i]);
}
usb_dma_writel(udc, BIT(BCM63XX_NUM_IUDMA)-1, ENETDMA_GLB_IRQMASK_REG);
return 0;
}
static void iudma_uninit(struct bcm63xx_udc *udc)
{
int i;
usb_dma_writel(udc, 0, ENETDMA_GLB_IRQMASK_REG);
for (i = 0; i < BCM63XX_NUM_IUDMA; i++)
iudma_reset_channel(udc, &udc->iudma[i]);
usb_dma_writel(udc, 0, ENETDMA_CFG_REG);
}
static void bcm63xx_set_ctrl_irqs(struct bcm63xx_udc *udc, bool enable_irqs)
{
u32 val;
usbd_writel(udc, 0, USBD_STATUS_REG);
val = BIT(USBD_EVENT_IRQ_USB_RESET) |
BIT(USBD_EVENT_IRQ_SETUP) |
BIT(USBD_EVENT_IRQ_SETCFG) |
BIT(USBD_EVENT_IRQ_SETINTF) |
BIT(USBD_EVENT_IRQ_USB_LINK);
usbd_writel(udc, enable_irqs ? val : 0, USBD_EVENT_IRQ_MASK_REG);
usbd_writel(udc, val, USBD_EVENT_IRQ_STATUS_REG);
}
static void bcm63xx_select_phy_mode(struct bcm63xx_udc *udc, bool is_device)
{
u32 val, portmask = BIT(udc->pd->port_no);
if (BCMCPU_IS_6328()) {
val = bcm_gpio_readl(GPIO_PINMUX_OTHR_REG);
val &= ~GPIO_PINMUX_OTHR_6328_USB_MASK;
val |= is_device ? GPIO_PINMUX_OTHR_6328_USB_DEV :
GPIO_PINMUX_OTHR_6328_USB_HOST;
bcm_gpio_writel(val, GPIO_PINMUX_OTHR_REG);
}
val = bcm_rset_readl(RSET_USBH_PRIV, USBH_PRIV_UTMI_CTL_6368_REG);
if (is_device) {
val |= (portmask << USBH_PRIV_UTMI_CTL_HOSTB_SHIFT);
val |= (portmask << USBH_PRIV_UTMI_CTL_NODRIV_SHIFT);
} else {
val &= ~(portmask << USBH_PRIV_UTMI_CTL_HOSTB_SHIFT);
val &= ~(portmask << USBH_PRIV_UTMI_CTL_NODRIV_SHIFT);
}
bcm_rset_writel(RSET_USBH_PRIV, val, USBH_PRIV_UTMI_CTL_6368_REG);
val = bcm_rset_readl(RSET_USBH_PRIV, USBH_PRIV_SWAP_6368_REG);
if (is_device)
val |= USBH_PRIV_SWAP_USBD_MASK;
else
val &= ~USBH_PRIV_SWAP_USBD_MASK;
bcm_rset_writel(RSET_USBH_PRIV, val, USBH_PRIV_SWAP_6368_REG);
}
static void bcm63xx_select_pullup(struct bcm63xx_udc *udc, bool is_on)
{
u32 val, portmask = BIT(udc->pd->port_no);
val = bcm_rset_readl(RSET_USBH_PRIV, USBH_PRIV_UTMI_CTL_6368_REG);
if (is_on)
val &= ~(portmask << USBH_PRIV_UTMI_CTL_NODRIV_SHIFT);
else
val |= (portmask << USBH_PRIV_UTMI_CTL_NODRIV_SHIFT);
bcm_rset_writel(RSET_USBH_PRIV, val, USBH_PRIV_UTMI_CTL_6368_REG);
}
static void bcm63xx_uninit_udc_hw(struct bcm63xx_udc *udc)
{
set_clocks(udc, true);
iudma_uninit(udc);
set_clocks(udc, false);
clk_put(udc->usbd_clk);
clk_put(udc->usbh_clk);
}
static int bcm63xx_init_udc_hw(struct bcm63xx_udc *udc)
{
int i, rc = 0;
u32 val;
udc->ep0_ctrl_buf = devm_kzalloc(udc->dev, BCM63XX_MAX_CTRL_PKT,
GFP_KERNEL);
if (!udc->ep0_ctrl_buf)
return -ENOMEM;
INIT_LIST_HEAD(&udc->gadget.ep_list);
for (i = 0; i < BCM63XX_NUM_EP; i++) {
struct bcm63xx_ep *bep = &udc->bep[i];
bep->ep.name = bcm63xx_ep_name[i];
bep->ep_num = i;
bep->ep.ops = &bcm63xx_udc_ep_ops;
list_add_tail(&bep->ep.ep_list, &udc->gadget.ep_list);
bep->halted = 0;
usb_ep_set_maxpacket_limit(&bep->ep, BCM63XX_MAX_CTRL_PKT);
bep->udc = udc;
bep->ep.desc = NULL;
INIT_LIST_HEAD(&bep->queue);
}
udc->gadget.ep0 = &udc->bep[0].ep;
list_del(&udc->bep[0].ep.ep_list);
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->ep0state = EP0_SHUTDOWN;
udc->usbh_clk = clk_get(udc->dev, "usbh");
if (IS_ERR(udc->usbh_clk))
return -EIO;
udc->usbd_clk = clk_get(udc->dev, "usbd");
if (IS_ERR(udc->usbd_clk)) {
clk_put(udc->usbh_clk);
return -EIO;
}
set_clocks(udc, true);
val = USBD_CONTROL_AUTO_CSRS_MASK |
USBD_CONTROL_DONE_CSRS_MASK |
(irq_coalesce ? USBD_CONTROL_RXZSCFG_MASK : 0);
usbd_writel(udc, val, USBD_CONTROL_REG);
val = USBD_STRAPS_APP_SELF_PWR_MASK |
USBD_STRAPS_APP_RAM_IF_MASK |
USBD_STRAPS_APP_CSRPRGSUP_MASK |
USBD_STRAPS_APP_8BITPHY_MASK |
USBD_STRAPS_APP_RMTWKUP_MASK;
if (udc->gadget.max_speed == USB_SPEED_HIGH)
val |= (BCM63XX_SPD_HIGH << USBD_STRAPS_SPEED_SHIFT);
else
val |= (BCM63XX_SPD_FULL << USBD_STRAPS_SPEED_SHIFT);
usbd_writel(udc, val, USBD_STRAPS_REG);
bcm63xx_set_ctrl_irqs(udc, false);
usbd_writel(udc, 0, USBD_EVENT_IRQ_CFG_LO_REG);
val = USBD_EVENT_IRQ_CFG_FALLING(USBD_EVENT_IRQ_ENUM_ON) |
USBD_EVENT_IRQ_CFG_FALLING(USBD_EVENT_IRQ_SET_CSRS);
usbd_writel(udc, val, USBD_EVENT_IRQ_CFG_HI_REG);
rc = iudma_init(udc);
set_clocks(udc, false);
if (rc)
bcm63xx_uninit_udc_hw(udc);
return 0;
}
static int bcm63xx_ep_enable(struct usb_ep *ep,
const struct usb_endpoint_descriptor *desc)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
struct iudma_ch *iudma = bep->iudma;
unsigned long flags;
if (!ep || !desc || ep->name == bcm63xx_ep0name)
return -EINVAL;
if (!udc->driver)
return -ESHUTDOWN;
spin_lock_irqsave(&udc->lock, flags);
if (iudma->enabled) {
spin_unlock_irqrestore(&udc->lock, flags);
return -EINVAL;
}
iudma->enabled = true;
BUG_ON(!list_empty(&bep->queue));
iudma_reset_channel(udc, iudma);
bep->halted = 0;
bcm63xx_set_stall(udc, bep, false);
clear_bit(bep->ep_num, &udc->wedgemap);
ep->desc = desc;
ep->maxpacket = usb_endpoint_maxp(desc);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int bcm63xx_ep_disable(struct usb_ep *ep)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
struct iudma_ch *iudma = bep->iudma;
struct list_head *pos, *n;
unsigned long flags;
if (!ep || !ep->desc)
return -EINVAL;
spin_lock_irqsave(&udc->lock, flags);
if (!iudma->enabled) {
spin_unlock_irqrestore(&udc->lock, flags);
return -EINVAL;
}
iudma->enabled = false;
iudma_reset_channel(udc, iudma);
if (!list_empty(&bep->queue)) {
list_for_each_safe(pos, n, &bep->queue) {
struct bcm63xx_req *breq =
list_entry(pos, struct bcm63xx_req, queue);
usb_gadget_unmap_request(&udc->gadget, &breq->req,
iudma->is_tx);
list_del(&breq->queue);
breq->req.status = -ESHUTDOWN;
spin_unlock_irqrestore(&udc->lock, flags);
usb_gadget_giveback_request(&iudma->bep->ep, &breq->req);
spin_lock_irqsave(&udc->lock, flags);
}
}
ep->desc = NULL;
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static struct usb_request *bcm63xx_udc_alloc_request(struct usb_ep *ep,
gfp_t mem_flags)
{
struct bcm63xx_req *breq;
breq = kzalloc(sizeof(*breq), mem_flags);
if (!breq)
return NULL;
return &breq->req;
}
static void bcm63xx_udc_free_request(struct usb_ep *ep,
struct usb_request *req)
{
struct bcm63xx_req *breq = our_req(req);
kfree(breq);
}
static int bcm63xx_udc_queue(struct usb_ep *ep, struct usb_request *req,
gfp_t mem_flags)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
struct bcm63xx_req *breq = our_req(req);
unsigned long flags;
int rc = 0;
if (unlikely(!req || !req->complete || !req->buf || !ep))
return -EINVAL;
req->actual = 0;
req->status = 0;
breq->offset = 0;
if (bep == &udc->bep[0]) {
if (udc->ep0_reply)
return -EINVAL;
udc->ep0_reply = req;
schedule_work(&udc->ep0_wq);
return 0;
}
spin_lock_irqsave(&udc->lock, flags);
if (!bep->iudma->enabled) {
rc = -ESHUTDOWN;
goto out;
}
rc = usb_gadget_map_request(&udc->gadget, req, bep->iudma->is_tx);
if (rc == 0) {
list_add_tail(&breq->queue, &bep->queue);
if (list_is_singular(&bep->queue))
iudma_write(udc, bep->iudma, breq);
}
out:
spin_unlock_irqrestore(&udc->lock, flags);
return rc;
}
static int bcm63xx_udc_dequeue(struct usb_ep *ep, struct usb_request *req)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
struct bcm63xx_req *breq = our_req(req), *cur;
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&udc->lock, flags);
if (list_empty(&bep->queue)) {
rc = -EINVAL;
goto out;
}
cur = list_first_entry(&bep->queue, struct bcm63xx_req, queue);
usb_gadget_unmap_request(&udc->gadget, &breq->req, bep->iudma->is_tx);
if (breq == cur) {
iudma_reset_channel(udc, bep->iudma);
list_del(&breq->queue);
if (!list_empty(&bep->queue)) {
struct bcm63xx_req *next;
next = list_first_entry(&bep->queue,
struct bcm63xx_req, queue);
iudma_write(udc, bep->iudma, next);
}
} else {
list_del(&breq->queue);
}
out:
spin_unlock_irqrestore(&udc->lock, flags);
req->status = -ESHUTDOWN;
req->complete(ep, req);
return rc;
}
static int bcm63xx_udc_set_halt(struct usb_ep *ep, int value)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
bcm63xx_set_stall(udc, bep, !!value);
bep->halted = value;
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int bcm63xx_udc_set_wedge(struct usb_ep *ep)
{
struct bcm63xx_ep *bep = our_ep(ep);
struct bcm63xx_udc *udc = bep->udc;
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
set_bit(bep->ep_num, &udc->wedgemap);
bcm63xx_set_stall(udc, bep, true);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int bcm63xx_ep0_setup_callback(struct bcm63xx_udc *udc,
struct usb_ctrlrequest *ctrl)
{
int rc;
spin_unlock_irq(&udc->lock);
rc = udc->driver->setup(&udc->gadget, ctrl);
spin_lock_irq(&udc->lock);
return rc;
}
static int bcm63xx_ep0_spoof_set_cfg(struct bcm63xx_udc *udc)
{
struct usb_ctrlrequest ctrl;
int rc;
ctrl.bRequestType = USB_DIR_OUT | USB_RECIP_DEVICE;
ctrl.bRequest = USB_REQ_SET_CONFIGURATION;
ctrl.wValue = cpu_to_le16(udc->cfg);
ctrl.wIndex = 0;
ctrl.wLength = 0;
rc = bcm63xx_ep0_setup_callback(udc, &ctrl);
if (rc < 0) {
dev_warn_ratelimited(udc->dev,
"hardware auto-acked bad SET_CONFIGURATION(%d) request\n",
udc->cfg);
}
return rc;
}
static int bcm63xx_ep0_spoof_set_iface(struct bcm63xx_udc *udc)
{
struct usb_ctrlrequest ctrl;
int rc;
ctrl.bRequestType = USB_DIR_OUT | USB_RECIP_INTERFACE;
ctrl.bRequest = USB_REQ_SET_INTERFACE;
ctrl.wValue = cpu_to_le16(udc->alt_iface);
ctrl.wIndex = cpu_to_le16(udc->iface);
ctrl.wLength = 0;
rc = bcm63xx_ep0_setup_callback(udc, &ctrl);
if (rc < 0) {
dev_warn_ratelimited(udc->dev,
"hardware auto-acked bad SET_INTERFACE(%d,%d) request\n",
udc->iface, udc->alt_iface);
}
return rc;
}
static void bcm63xx_ep0_map_write(struct bcm63xx_udc *udc, int ch_idx,
struct usb_request *req)
{
struct bcm63xx_req *breq = our_req(req);
struct iudma_ch *iudma = &udc->iudma[ch_idx];
BUG_ON(udc->ep0_request);
udc->ep0_request = req;
req->actual = 0;
breq->offset = 0;
usb_gadget_map_request(&udc->gadget, req, iudma->is_tx);
iudma_write(udc, iudma, breq);
}
static void bcm63xx_ep0_complete(struct bcm63xx_udc *udc,
struct usb_request *req, int status)
{
req->status = status;
if (status)
req->actual = 0;
if (req->complete) {
spin_unlock_irq(&udc->lock);
req->complete(&udc->bep[0].ep, req);
spin_lock_irq(&udc->lock);
}
}
static void bcm63xx_ep0_nuke_reply(struct bcm63xx_udc *udc, int is_tx)
{
struct usb_request *req = udc->ep0_reply;
udc->ep0_reply = NULL;
usb_gadget_unmap_request(&udc->gadget, req, is_tx);
if (udc->ep0_request == req) {
udc->ep0_req_completed = 0;
udc->ep0_request = NULL;
}
bcm63xx_ep0_complete(udc, req, -ESHUTDOWN);
}
static int bcm63xx_ep0_read_complete(struct bcm63xx_udc *udc)
{
struct usb_request *req = udc->ep0_request;
udc->ep0_req_completed = 0;
udc->ep0_request = NULL;
return req->actual;
}
static void bcm63xx_ep0_internal_request(struct bcm63xx_udc *udc, int ch_idx,
int length)
{
struct usb_request *req = &udc->ep0_ctrl_req.req;
req->buf = udc->ep0_ctrl_buf;
req->length = length;
req->complete = NULL;
bcm63xx_ep0_map_write(udc, ch_idx, req);
}
static enum bcm63xx_ep0_state bcm63xx_ep0_do_setup(struct bcm63xx_udc *udc)
{
int rc;
struct usb_ctrlrequest *ctrl = (void *)udc->ep0_ctrl_buf;
rc = bcm63xx_ep0_read_complete(udc);
if (rc < 0) {
dev_err(udc->dev, "missing SETUP packet\n");
return EP0_IDLE;
}
if (rc == 0)
return EP0_REQUEUE;
if (rc != sizeof(*ctrl)) {
dev_warn_ratelimited(udc->dev,
"malformed SETUP packet (%d bytes)\n", rc);
return EP0_REQUEUE;
}
rc = bcm63xx_ep0_setup_callback(udc, ctrl);
if (rc < 0) {
bcm63xx_set_stall(udc, &udc->bep[0], true);
return EP0_REQUEUE;
}
if (!ctrl->wLength)
return EP0_REQUEUE;
else if (ctrl->bRequestType & USB_DIR_IN)
return EP0_IN_DATA_PHASE_SETUP;
else
return EP0_OUT_DATA_PHASE_SETUP;
}
static int bcm63xx_ep0_do_idle(struct bcm63xx_udc *udc)
{
if (udc->ep0_req_reset) {
udc->ep0_req_reset = 0;
} else if (udc->ep0_req_set_cfg) {
udc->ep0_req_set_cfg = 0;
if (bcm63xx_ep0_spoof_set_cfg(udc) >= 0)
udc->ep0state = EP0_IN_FAKE_STATUS_PHASE;
} else if (udc->ep0_req_set_iface) {
udc->ep0_req_set_iface = 0;
if (bcm63xx_ep0_spoof_set_iface(udc) >= 0)
udc->ep0state = EP0_IN_FAKE_STATUS_PHASE;
} else if (udc->ep0_req_completed) {
udc->ep0state = bcm63xx_ep0_do_setup(udc);
return udc->ep0state == EP0_IDLE ? -EAGAIN : 0;
} else if (udc->ep0_req_shutdown) {
udc->ep0_req_shutdown = 0;
udc->ep0_req_completed = 0;
udc->ep0_request = NULL;
iudma_reset_channel(udc, &udc->iudma[IUDMA_EP0_RXCHAN]);
usb_gadget_unmap_request(&udc->gadget,
&udc->ep0_ctrl_req.req, 0);
mb();
udc->ep0state = EP0_SHUTDOWN;
} else if (udc->ep0_reply) {
dev_warn(udc->dev, "nuking unexpected reply\n");
bcm63xx_ep0_nuke_reply(udc, 0);
} else {
return -EAGAIN;
}
return 0;
}
static int bcm63xx_ep0_one_round(struct bcm63xx_udc *udc)
{
enum bcm63xx_ep0_state ep0state = udc->ep0state;
bool shutdown = udc->ep0_req_reset || udc->ep0_req_shutdown;
switch (udc->ep0state) {
case EP0_REQUEUE:
bcm63xx_ep0_internal_request(udc, IUDMA_EP0_RXCHAN,
BCM63XX_MAX_CTRL_PKT);
ep0state = EP0_IDLE;
break;
case EP0_IDLE:
return bcm63xx_ep0_do_idle(udc);
case EP0_IN_DATA_PHASE_SETUP:
if (udc->ep0_reply) {
bcm63xx_ep0_map_write(udc, IUDMA_EP0_TXCHAN,
udc->ep0_reply);
ep0state = EP0_IN_DATA_PHASE_COMPLETE;
} else if (shutdown) {
ep0state = EP0_REQUEUE;
}
break;
case EP0_IN_DATA_PHASE_COMPLETE: {
if (udc->ep0_req_completed) {
udc->ep0_reply = NULL;
bcm63xx_ep0_read_complete(udc);
ep0state = EP0_REQUEUE;
} else if (shutdown) {
iudma_reset_channel(udc, &udc->iudma[IUDMA_EP0_TXCHAN]);
bcm63xx_ep0_nuke_reply(udc, 1);
ep0state = EP0_REQUEUE;
}
break;
}
case EP0_OUT_DATA_PHASE_SETUP:
if (udc->ep0_reply) {
bcm63xx_ep0_map_write(udc, IUDMA_EP0_RXCHAN,
udc->ep0_reply);
ep0state = EP0_OUT_DATA_PHASE_COMPLETE;
} else if (shutdown) {
ep0state = EP0_REQUEUE;
}
break;
case EP0_OUT_DATA_PHASE_COMPLETE: {
if (udc->ep0_req_completed) {
udc->ep0_reply = NULL;
bcm63xx_ep0_read_complete(udc);
bcm63xx_ep0_internal_request(udc, IUDMA_EP0_TXCHAN, 0);
ep0state = EP0_OUT_STATUS_PHASE;
} else if (shutdown) {
iudma_reset_channel(udc, &udc->iudma[IUDMA_EP0_RXCHAN]);
bcm63xx_ep0_nuke_reply(udc, 0);
ep0state = EP0_REQUEUE;
}
break;
}
case EP0_OUT_STATUS_PHASE:
if (udc->ep0_req_completed) {
bcm63xx_ep0_read_complete(udc);
ep0state = EP0_REQUEUE;
} else if (shutdown) {
iudma_reset_channel(udc, &udc->iudma[IUDMA_EP0_TXCHAN]);
udc->ep0_request = NULL;
ep0state = EP0_REQUEUE;
}
break;
case EP0_IN_FAKE_STATUS_PHASE: {
struct usb_request *r = udc->ep0_reply;
if (!r) {
if (shutdown)
ep0state = EP0_IDLE;
break;
}
bcm63xx_ep0_complete(udc, r, 0);
udc->ep0_reply = NULL;
ep0state = EP0_IDLE;
break;
}
case EP0_SHUTDOWN:
break;
}
if (udc->ep0state == ep0state)
return -EAGAIN;
udc->ep0state = ep0state;
return 0;
}
static void bcm63xx_ep0_process(struct work_struct *w)
{
struct bcm63xx_udc *udc = container_of(w, struct bcm63xx_udc, ep0_wq);
spin_lock_irq(&udc->lock);
while (bcm63xx_ep0_one_round(udc) == 0)
;
spin_unlock_irq(&udc->lock);
}
static int bcm63xx_udc_get_frame(struct usb_gadget *gadget)
{
struct bcm63xx_udc *udc = gadget_to_udc(gadget);
return (usbd_readl(udc, USBD_STATUS_REG) &
USBD_STATUS_SOF_MASK) >> USBD_STATUS_SOF_SHIFT;
}
static int bcm63xx_udc_pullup(struct usb_gadget *gadget, int is_on)
{
struct bcm63xx_udc *udc = gadget_to_udc(gadget);
unsigned long flags;
int i, rc = -EINVAL;
spin_lock_irqsave(&udc->lock, flags);
if (is_on && udc->ep0state == EP0_SHUTDOWN) {
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->ep0state = EP0_REQUEUE;
bcm63xx_fifo_setup(udc);
bcm63xx_fifo_reset(udc);
bcm63xx_ep_setup(udc);
bitmap_zero(&udc->wedgemap, BCM63XX_NUM_EP);
for (i = 0; i < BCM63XX_NUM_EP; i++)
bcm63xx_set_stall(udc, &udc->bep[i], false);
bcm63xx_set_ctrl_irqs(udc, true);
bcm63xx_select_pullup(gadget_to_udc(gadget), true);
rc = 0;
} else if (!is_on && udc->ep0state != EP0_SHUTDOWN) {
bcm63xx_select_pullup(gadget_to_udc(gadget), false);
udc->ep0_req_shutdown = 1;
spin_unlock_irqrestore(&udc->lock, flags);
while (1) {
schedule_work(&udc->ep0_wq);
if (udc->ep0state == EP0_SHUTDOWN)
break;
msleep(50);
}
bcm63xx_set_ctrl_irqs(udc, false);
cancel_work_sync(&udc->ep0_wq);
return 0;
}
spin_unlock_irqrestore(&udc->lock, flags);
return rc;
}
static int bcm63xx_udc_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct bcm63xx_udc *udc = gadget_to_udc(gadget);
unsigned long flags;
if (!driver || driver->max_speed < USB_SPEED_HIGH ||
!driver->setup)
return -EINVAL;
if (!udc)
return -ENODEV;
if (udc->driver)
return -EBUSY;
spin_lock_irqsave(&udc->lock, flags);
set_clocks(udc, true);
bcm63xx_fifo_setup(udc);
bcm63xx_ep_init(udc);
bcm63xx_ep_setup(udc);
bcm63xx_fifo_reset(udc);
bcm63xx_select_phy_mode(udc, true);
udc->driver = driver;
driver->driver.bus = NULL;
udc->gadget.dev.of_node = udc->dev->of_node;
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int bcm63xx_udc_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct bcm63xx_udc *udc = gadget_to_udc(gadget);
unsigned long flags;
spin_lock_irqsave(&udc->lock, flags);
udc->driver = NULL;
msleep(100);
bcm63xx_select_phy_mode(udc, false);
set_clocks(udc, false);
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static void bcm63xx_update_cfg_iface(struct bcm63xx_udc *udc)
{
u32 reg = usbd_readl(udc, USBD_STATUS_REG);
udc->cfg = (reg & USBD_STATUS_CFG_MASK) >> USBD_STATUS_CFG_SHIFT;
udc->iface = (reg & USBD_STATUS_INTF_MASK) >> USBD_STATUS_INTF_SHIFT;
udc->alt_iface = (reg & USBD_STATUS_ALTINTF_MASK) >>
USBD_STATUS_ALTINTF_SHIFT;
bcm63xx_ep_setup(udc);
}
static int bcm63xx_update_link_speed(struct bcm63xx_udc *udc)
{
u32 reg = usbd_readl(udc, USBD_STATUS_REG);
enum usb_device_speed oldspeed = udc->gadget.speed;
switch ((reg & USBD_STATUS_SPD_MASK) >> USBD_STATUS_SPD_SHIFT) {
case BCM63XX_SPD_HIGH:
udc->gadget.speed = USB_SPEED_HIGH;
break;
case BCM63XX_SPD_FULL:
udc->gadget.speed = USB_SPEED_FULL;
break;
default:
udc->gadget.speed = USB_SPEED_UNKNOWN;
dev_err(udc->dev,
"received SETUP packet with invalid link speed\n");
return 0;
}
if (udc->gadget.speed != oldspeed) {
dev_info(udc->dev, "link up, %s-speed mode\n",
udc->gadget.speed == USB_SPEED_HIGH ? "high" : "full");
return 1;
} else {
return 0;
}
}
static void bcm63xx_update_wedge(struct bcm63xx_udc *udc, bool new_status)
{
int i;
for_each_set_bit(i, &udc->wedgemap, BCM63XX_NUM_EP) {
bcm63xx_set_stall(udc, &udc->bep[i], new_status);
if (!new_status)
clear_bit(i, &udc->wedgemap);
}
}
static irqreturn_t bcm63xx_udc_ctrl_isr(int irq, void *dev_id)
{
struct bcm63xx_udc *udc = dev_id;
u32 stat;
bool disconnected = false;
stat = usbd_readl(udc, USBD_EVENT_IRQ_STATUS_REG) &
usbd_readl(udc, USBD_EVENT_IRQ_MASK_REG);
usbd_writel(udc, stat, USBD_EVENT_IRQ_STATUS_REG);
spin_lock(&udc->lock);
if (stat & BIT(USBD_EVENT_IRQ_USB_LINK)) {
if (!(usbd_readl(udc, USBD_EVENTS_REG) &
USBD_EVENTS_USB_LINK_MASK) &&
udc->gadget.speed != USB_SPEED_UNKNOWN)
dev_info(udc->dev, "link down\n");
udc->gadget.speed = USB_SPEED_UNKNOWN;
disconnected = true;
}
if (stat & BIT(USBD_EVENT_IRQ_USB_RESET)) {
bcm63xx_fifo_setup(udc);
bcm63xx_fifo_reset(udc);
bcm63xx_ep_setup(udc);
bcm63xx_update_wedge(udc, false);
udc->ep0_req_reset = 1;
schedule_work(&udc->ep0_wq);
disconnected = true;
}
if (stat & BIT(USBD_EVENT_IRQ_SETUP)) {
if (bcm63xx_update_link_speed(udc)) {
bcm63xx_fifo_setup(udc);
bcm63xx_ep_setup(udc);
}
bcm63xx_update_wedge(udc, true);
}
if (stat & BIT(USBD_EVENT_IRQ_SETCFG)) {
bcm63xx_update_cfg_iface(udc);
udc->ep0_req_set_cfg = 1;
schedule_work(&udc->ep0_wq);
}
if (stat & BIT(USBD_EVENT_IRQ_SETINTF)) {
bcm63xx_update_cfg_iface(udc);
udc->ep0_req_set_iface = 1;
schedule_work(&udc->ep0_wq);
}
spin_unlock(&udc->lock);
if (disconnected && udc->driver)
udc->driver->disconnect(&udc->gadget);
return IRQ_HANDLED;
}
static irqreturn_t bcm63xx_udc_data_isr(int irq, void *dev_id)
{
struct iudma_ch *iudma = dev_id;
struct bcm63xx_udc *udc = iudma->udc;
struct bcm63xx_ep *bep;
struct usb_request *req = NULL;
struct bcm63xx_req *breq = NULL;
int rc;
bool is_done = false;
spin_lock(&udc->lock);
usb_dmac_writel(udc, ENETDMAC_IR_BUFDONE_MASK,
ENETDMAC_IR_REG, iudma->ch_idx);
bep = iudma->bep;
rc = iudma_read(udc, iudma);
if (iudma->ch_idx == IUDMA_EP0_RXCHAN ||
iudma->ch_idx == IUDMA_EP0_TXCHAN) {
req = udc->ep0_request;
breq = our_req(req);
if (rc >= 0) {
req->actual += rc;
if (req->actual >= req->length || breq->bd_bytes > rc) {
udc->ep0_req_completed = 1;
is_done = true;
schedule_work(&udc->ep0_wq);
req->actual = min(req->actual, req->length);
} else {
iudma_write(udc, iudma, breq);
}
}
} else if (!list_empty(&bep->queue)) {
breq = list_first_entry(&bep->queue, struct bcm63xx_req, queue);
req = &breq->req;
if (rc >= 0) {
req->actual += rc;
if (req->actual >= req->length || breq->bd_bytes > rc) {
is_done = true;
list_del(&breq->queue);
req->actual = min(req->actual, req->length);
if (!list_empty(&bep->queue)) {
struct bcm63xx_req *next;
next = list_first_entry(&bep->queue,
struct bcm63xx_req, queue);
iudma_write(udc, iudma, next);
}
} else {
iudma_write(udc, iudma, breq);
}
}
}
spin_unlock(&udc->lock);
if (is_done) {
usb_gadget_unmap_request(&udc->gadget, req, iudma->is_tx);
if (req->complete)
req->complete(&bep->ep, req);
}
return IRQ_HANDLED;
}
static int bcm63xx_usbd_dbg_show(struct seq_file *s, void *p)
{
struct bcm63xx_udc *udc = s->private;
if (!udc->driver)
return -ENODEV;
seq_printf(s, "ep0 state: %s\n",
bcm63xx_ep0_state_names[udc->ep0state]);
seq_printf(s, " pending requests: %s%s%s%s%s%s%s\n",
udc->ep0_req_reset ? "reset " : "",
udc->ep0_req_set_cfg ? "set_cfg " : "",
udc->ep0_req_set_iface ? "set_iface " : "",
udc->ep0_req_shutdown ? "shutdown " : "",
udc->ep0_request ? "pending " : "",
udc->ep0_req_completed ? "completed " : "",
udc->ep0_reply ? "reply " : "");
seq_printf(s, "cfg: %d; iface: %d; alt_iface: %d\n",
udc->cfg, udc->iface, udc->alt_iface);
seq_printf(s, "regs:\n");
seq_printf(s, " control: %08x; straps: %08x; status: %08x\n",
usbd_readl(udc, USBD_CONTROL_REG),
usbd_readl(udc, USBD_STRAPS_REG),
usbd_readl(udc, USBD_STATUS_REG));
seq_printf(s, " events: %08x; stall: %08x\n",
usbd_readl(udc, USBD_EVENTS_REG),
usbd_readl(udc, USBD_STALL_REG));
return 0;
}
static int bcm63xx_iudma_dbg_show(struct seq_file *s, void *p)
{
struct bcm63xx_udc *udc = s->private;
int ch_idx, i;
u32 sram2, sram3;
if (!udc->driver)
return -ENODEV;
for (ch_idx = 0; ch_idx < BCM63XX_NUM_IUDMA; ch_idx++) {
struct iudma_ch *iudma = &udc->iudma[ch_idx];
struct list_head *pos;
seq_printf(s, "IUDMA channel %d -- ", ch_idx);
switch (iudma_defaults[ch_idx].ep_type) {
case BCMEP_CTRL:
seq_printf(s, "control");
break;
case BCMEP_BULK:
seq_printf(s, "bulk");
break;
case BCMEP_INTR:
seq_printf(s, "interrupt");
break;
}
seq_printf(s, ch_idx & 0x01 ? " tx" : " rx");
seq_printf(s, " [ep%d]:\n",
max_t(int, iudma_defaults[ch_idx].ep_num, 0));
seq_printf(s, " cfg: %08x; irqstat: %08x; irqmask: %08x; maxburst: %08x\n",
usb_dmac_readl(udc, ENETDMAC_CHANCFG_REG, ch_idx),
usb_dmac_readl(udc, ENETDMAC_IR_REG, ch_idx),
usb_dmac_readl(udc, ENETDMAC_IRMASK_REG, ch_idx),
usb_dmac_readl(udc, ENETDMAC_MAXBURST_REG, ch_idx));
sram2 = usb_dmas_readl(udc, ENETDMAS_SRAM2_REG, ch_idx);
sram3 = usb_dmas_readl(udc, ENETDMAS_SRAM3_REG, ch_idx);
seq_printf(s, " base: %08x; index: %04x_%04x; desc: %04x_%04x %08x\n",
usb_dmas_readl(udc, ENETDMAS_RSTART_REG, ch_idx),
sram2 >> 16, sram2 & 0xffff,
sram3 >> 16, sram3 & 0xffff,
usb_dmas_readl(udc, ENETDMAS_SRAM4_REG, ch_idx));
seq_printf(s, " desc: %d/%d used", iudma->n_bds_used,
iudma->n_bds);
if (iudma->bep) {
i = 0;
list_for_each(pos, &iudma->bep->queue)
i++;
seq_printf(s, "; %d queued\n", i);
} else {
seq_printf(s, "\n");
}
for (i = 0; i < iudma->n_bds; i++) {
struct bcm_enet_desc *d = &iudma->bd_ring[i];
seq_printf(s, " %03x (%02x): len_stat: %04x_%04x; pa %08x",
i * sizeof(*d), i,
d->len_stat >> 16, d->len_stat & 0xffff,
d->address);
if (d == iudma->read_bd)
seq_printf(s, " <<RD");
if (d == iudma->write_bd)
seq_printf(s, " <<WR");
seq_printf(s, "\n");
}
seq_printf(s, "\n");
}
return 0;
}
static int bcm63xx_usbd_dbg_open(struct inode *inode, struct file *file)
{
return single_open(file, bcm63xx_usbd_dbg_show, inode->i_private);
}
static int bcm63xx_iudma_dbg_open(struct inode *inode, struct file *file)
{
return single_open(file, bcm63xx_iudma_dbg_show, inode->i_private);
}
static void bcm63xx_udc_init_debugfs(struct bcm63xx_udc *udc)
{
struct dentry *root, *usbd, *iudma;
if (!IS_ENABLED(CONFIG_USB_GADGET_DEBUG_FS))
return;
root = debugfs_create_dir(udc->gadget.name, NULL);
if (IS_ERR(root) || !root)
goto err_root;
usbd = debugfs_create_file("usbd", 0400, root, udc,
&usbd_dbg_fops);
if (!usbd)
goto err_usbd;
iudma = debugfs_create_file("iudma", 0400, root, udc,
&iudma_dbg_fops);
if (!iudma)
goto err_iudma;
udc->debugfs_root = root;
udc->debugfs_usbd = usbd;
udc->debugfs_iudma = iudma;
return;
err_iudma:
debugfs_remove(usbd);
err_usbd:
debugfs_remove(root);
err_root:
dev_err(udc->dev, "debugfs is not available\n");
}
static void bcm63xx_udc_cleanup_debugfs(struct bcm63xx_udc *udc)
{
debugfs_remove(udc->debugfs_iudma);
debugfs_remove(udc->debugfs_usbd);
debugfs_remove(udc->debugfs_root);
udc->debugfs_iudma = NULL;
udc->debugfs_usbd = NULL;
udc->debugfs_root = NULL;
}
static int bcm63xx_udc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct bcm63xx_usbd_platform_data *pd = dev_get_platdata(dev);
struct bcm63xx_udc *udc;
struct resource *res;
int rc = -ENOMEM, i, irq;
udc = devm_kzalloc(dev, sizeof(*udc), GFP_KERNEL);
if (!udc) {
dev_err(dev, "cannot allocate memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, udc);
udc->dev = dev;
udc->pd = pd;
if (!pd) {
dev_err(dev, "missing platform data\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
udc->usbd_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(udc->usbd_regs))
return PTR_ERR(udc->usbd_regs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
udc->iudma_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(udc->iudma_regs))
return PTR_ERR(udc->iudma_regs);
spin_lock_init(&udc->lock);
INIT_WORK(&udc->ep0_wq, bcm63xx_ep0_process);
udc->gadget.ops = &bcm63xx_udc_ops;
udc->gadget.name = dev_name(dev);
if (!pd->use_fullspeed && !use_fullspeed)
udc->gadget.max_speed = USB_SPEED_HIGH;
else
udc->gadget.max_speed = USB_SPEED_FULL;
rc = bcm63xx_init_udc_hw(udc);
if (rc)
return rc;
rc = -ENXIO;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "missing IRQ resource #0\n");
goto out_uninit;
}
if (devm_request_irq(dev, irq, &bcm63xx_udc_ctrl_isr, 0,
dev_name(dev), udc) < 0) {
dev_err(dev, "error requesting IRQ #%d\n", irq);
goto out_uninit;
}
for (i = 0; i < BCM63XX_NUM_IUDMA; i++) {
irq = platform_get_irq(pdev, i + 1);
if (irq < 0) {
dev_err(dev, "missing IRQ resource #%d\n", i + 1);
goto out_uninit;
}
if (devm_request_irq(dev, irq, &bcm63xx_udc_data_isr, 0,
dev_name(dev), &udc->iudma[i]) < 0) {
dev_err(dev, "error requesting IRQ #%d\n", irq);
goto out_uninit;
}
}
bcm63xx_udc_init_debugfs(udc);
rc = usb_add_gadget_udc(dev, &udc->gadget);
if (!rc)
return 0;
bcm63xx_udc_cleanup_debugfs(udc);
out_uninit:
bcm63xx_uninit_udc_hw(udc);
return rc;
}
static int bcm63xx_udc_remove(struct platform_device *pdev)
{
struct bcm63xx_udc *udc = platform_get_drvdata(pdev);
bcm63xx_udc_cleanup_debugfs(udc);
usb_del_gadget_udc(&udc->gadget);
BUG_ON(udc->driver);
bcm63xx_uninit_udc_hw(udc);
return 0;
}
