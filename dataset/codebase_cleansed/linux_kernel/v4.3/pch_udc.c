static inline u32 pch_udc_readl(struct pch_udc_dev *dev, unsigned long reg)
{
return ioread32(dev->base_addr + reg);
}
static inline void pch_udc_writel(struct pch_udc_dev *dev,
unsigned long val, unsigned long reg)
{
iowrite32(val, dev->base_addr + reg);
}
static inline void pch_udc_bit_set(struct pch_udc_dev *dev,
unsigned long reg,
unsigned long bitmask)
{
pch_udc_writel(dev, pch_udc_readl(dev, reg) | bitmask, reg);
}
static inline void pch_udc_bit_clr(struct pch_udc_dev *dev,
unsigned long reg,
unsigned long bitmask)
{
pch_udc_writel(dev, pch_udc_readl(dev, reg) & ~(bitmask), reg);
}
static inline u32 pch_udc_ep_readl(struct pch_udc_ep *ep, unsigned long reg)
{
return ioread32(ep->dev->base_addr + ep->offset_addr + reg);
}
static inline void pch_udc_ep_writel(struct pch_udc_ep *ep,
unsigned long val, unsigned long reg)
{
iowrite32(val, ep->dev->base_addr + ep->offset_addr + reg);
}
static inline void pch_udc_ep_bit_set(struct pch_udc_ep *ep,
unsigned long reg,
unsigned long bitmask)
{
pch_udc_ep_writel(ep, pch_udc_ep_readl(ep, reg) | bitmask, reg);
}
static inline void pch_udc_ep_bit_clr(struct pch_udc_ep *ep,
unsigned long reg,
unsigned long bitmask)
{
pch_udc_ep_writel(ep, pch_udc_ep_readl(ep, reg) & ~(bitmask), reg);
}
static void pch_udc_csr_busy(struct pch_udc_dev *dev)
{
unsigned int count = 200;
while ((pch_udc_readl(dev, UDC_CSR_BUSY_ADDR) & UDC_CSR_BUSY)
&& --count)
cpu_relax();
if (!count)
dev_err(&dev->pdev->dev, "%s: wait error\n", __func__);
}
static void pch_udc_write_csr(struct pch_udc_dev *dev, unsigned long val,
unsigned int ep)
{
unsigned long reg = PCH_UDC_CSR(ep);
pch_udc_csr_busy(dev);
pch_udc_writel(dev, val, reg);
pch_udc_csr_busy(dev);
}
static u32 pch_udc_read_csr(struct pch_udc_dev *dev, unsigned int ep)
{
unsigned long reg = PCH_UDC_CSR(ep);
pch_udc_csr_busy(dev);
pch_udc_readl(dev, reg);
pch_udc_csr_busy(dev);
return pch_udc_readl(dev, reg);
}
static inline void pch_udc_rmt_wakeup(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
mdelay(1);
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
}
static inline int pch_udc_get_frame(struct pch_udc_dev *dev)
{
u32 frame = pch_udc_readl(dev, UDC_DEVSTS_ADDR);
return (frame & UDC_DEVSTS_TS_MASK) >> UDC_DEVSTS_TS_SHIFT;
}
static inline void pch_udc_clear_selfpowered(struct pch_udc_dev *dev)
{
pch_udc_bit_clr(dev, UDC_DEVCFG_ADDR, UDC_DEVCFG_SP);
}
static inline void pch_udc_set_selfpowered(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVCFG_ADDR, UDC_DEVCFG_SP);
}
static inline void pch_udc_set_disconnect(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_SD);
}
static void pch_udc_clear_disconnect(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_SD);
mdelay(1);
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
}
static void pch_udc_reconnect(struct pch_udc_dev *dev)
{
pch_udc_init(dev);
pch_udc_bit_clr(dev, UDC_DEVIRQMSK_ADDR,
UDC_DEVINT_UR | UDC_DEVINT_ENUM);
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_SD);
mdelay(1);
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RES);
}
static inline void pch_udc_vbus_session(struct pch_udc_dev *dev,
int is_active)
{
if (is_active) {
pch_udc_reconnect(dev);
dev->vbus_session = 1;
} else {
if (dev->driver && dev->driver->disconnect) {
spin_lock(&dev->lock);
dev->driver->disconnect(&dev->gadget);
spin_unlock(&dev->lock);
}
pch_udc_set_disconnect(dev);
dev->vbus_session = 0;
}
}
static void pch_udc_ep_set_stall(struct pch_udc_ep *ep)
{
if (ep->in) {
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_F);
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_S);
} else {
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_S);
}
}
static inline void pch_udc_ep_clear_stall(struct pch_udc_ep *ep)
{
pch_udc_ep_bit_clr(ep, UDC_EPCTL_ADDR, UDC_EPCTL_S);
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_CNAK);
}
static inline void pch_udc_ep_set_trfr_type(struct pch_udc_ep *ep,
u8 type)
{
pch_udc_ep_writel(ep, ((type << UDC_EPCTL_ET_SHIFT) &
UDC_EPCTL_ET_MASK), UDC_EPCTL_ADDR);
}
static void pch_udc_ep_set_bufsz(struct pch_udc_ep *ep,
u32 buf_size, u32 ep_in)
{
u32 data;
if (ep_in) {
data = pch_udc_ep_readl(ep, UDC_BUFIN_FRAMENUM_ADDR);
data = (data & 0xffff0000) | (buf_size & 0xffff);
pch_udc_ep_writel(ep, data, UDC_BUFIN_FRAMENUM_ADDR);
} else {
data = pch_udc_ep_readl(ep, UDC_BUFOUT_MAXPKT_ADDR);
data = (buf_size << 16) | (data & 0xffff);
pch_udc_ep_writel(ep, data, UDC_BUFOUT_MAXPKT_ADDR);
}
}
static void pch_udc_ep_set_maxpkt(struct pch_udc_ep *ep, u32 pkt_size)
{
u32 data = pch_udc_ep_readl(ep, UDC_BUFOUT_MAXPKT_ADDR);
data = (data & 0xffff0000) | (pkt_size & 0xffff);
pch_udc_ep_writel(ep, data, UDC_BUFOUT_MAXPKT_ADDR);
}
static inline void pch_udc_ep_set_subptr(struct pch_udc_ep *ep, u32 addr)
{
pch_udc_ep_writel(ep, addr, UDC_SUBPTR_ADDR);
}
static inline void pch_udc_ep_set_ddptr(struct pch_udc_ep *ep, u32 addr)
{
pch_udc_ep_writel(ep, addr, UDC_DESPTR_ADDR);
}
static inline void pch_udc_ep_set_pd(struct pch_udc_ep *ep)
{
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_P);
}
static inline void pch_udc_ep_set_rrdy(struct pch_udc_ep *ep)
{
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_RRDY);
}
static inline void pch_udc_ep_clear_rrdy(struct pch_udc_ep *ep)
{
pch_udc_ep_bit_clr(ep, UDC_EPCTL_ADDR, UDC_EPCTL_RRDY);
}
static inline void pch_udc_set_dma(struct pch_udc_dev *dev, int dir)
{
if (dir == DMA_DIR_RX)
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RDE);
else if (dir == DMA_DIR_TX)
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_TDE);
}
static inline void pch_udc_clear_dma(struct pch_udc_dev *dev, int dir)
{
if (dir == DMA_DIR_RX)
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_RDE);
else if (dir == DMA_DIR_TX)
pch_udc_bit_clr(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_TDE);
}
static inline void pch_udc_set_csr_done(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR, UDC_DEVCTL_CSR_DONE);
}
static inline void pch_udc_disable_interrupts(struct pch_udc_dev *dev,
u32 mask)
{
pch_udc_bit_set(dev, UDC_DEVIRQMSK_ADDR, mask);
}
static inline void pch_udc_enable_interrupts(struct pch_udc_dev *dev,
u32 mask)
{
pch_udc_bit_clr(dev, UDC_DEVIRQMSK_ADDR, mask);
}
static inline void pch_udc_disable_ep_interrupts(struct pch_udc_dev *dev,
u32 mask)
{
pch_udc_bit_set(dev, UDC_EPIRQMSK_ADDR, mask);
}
static inline void pch_udc_enable_ep_interrupts(struct pch_udc_dev *dev,
u32 mask)
{
pch_udc_bit_clr(dev, UDC_EPIRQMSK_ADDR, mask);
}
static inline u32 pch_udc_read_device_interrupts(struct pch_udc_dev *dev)
{
return pch_udc_readl(dev, UDC_DEVIRQSTS_ADDR);
}
static inline void pch_udc_write_device_interrupts(struct pch_udc_dev *dev,
u32 val)
{
pch_udc_writel(dev, val, UDC_DEVIRQSTS_ADDR);
}
static inline u32 pch_udc_read_ep_interrupts(struct pch_udc_dev *dev)
{
return pch_udc_readl(dev, UDC_EPIRQSTS_ADDR);
}
static inline void pch_udc_write_ep_interrupts(struct pch_udc_dev *dev,
u32 val)
{
pch_udc_writel(dev, val, UDC_EPIRQSTS_ADDR);
}
static inline u32 pch_udc_read_device_status(struct pch_udc_dev *dev)
{
return pch_udc_readl(dev, UDC_DEVSTS_ADDR);
}
static inline u32 pch_udc_read_ep_control(struct pch_udc_ep *ep)
{
return pch_udc_ep_readl(ep, UDC_EPCTL_ADDR);
}
static inline void pch_udc_clear_ep_control(struct pch_udc_ep *ep)
{
return pch_udc_ep_writel(ep, 0, UDC_EPCTL_ADDR);
}
static inline u32 pch_udc_read_ep_status(struct pch_udc_ep *ep)
{
return pch_udc_ep_readl(ep, UDC_EPSTS_ADDR);
}
static inline void pch_udc_clear_ep_status(struct pch_udc_ep *ep,
u32 stat)
{
return pch_udc_ep_writel(ep, stat, UDC_EPSTS_ADDR);
}
static inline void pch_udc_ep_set_nak(struct pch_udc_ep *ep)
{
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_SNAK);
}
static void pch_udc_ep_clear_nak(struct pch_udc_ep *ep)
{
unsigned int loopcnt = 0;
struct pch_udc_dev *dev = ep->dev;
if (!(pch_udc_ep_readl(ep, UDC_EPCTL_ADDR) & UDC_EPCTL_NAK))
return;
if (!ep->in) {
loopcnt = 10000;
while (!(pch_udc_read_ep_status(ep) & UDC_EPSTS_MRXFIFO_EMP) &&
--loopcnt)
udelay(5);
if (!loopcnt)
dev_err(&dev->pdev->dev, "%s: RxFIFO not Empty\n",
__func__);
}
loopcnt = 10000;
while ((pch_udc_read_ep_control(ep) & UDC_EPCTL_NAK) && --loopcnt) {
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_CNAK);
udelay(5);
}
if (!loopcnt)
dev_err(&dev->pdev->dev, "%s: Clear NAK not set for ep%d%s\n",
__func__, ep->num, (ep->in ? "in" : "out"));
}
static void pch_udc_ep_fifo_flush(struct pch_udc_ep *ep, int dir)
{
if (dir) {
pch_udc_ep_bit_set(ep, UDC_EPCTL_ADDR, UDC_EPCTL_F);
return;
}
}
static void pch_udc_ep_enable(struct pch_udc_ep *ep,
struct pch_udc_cfg_data *cfg,
const struct usb_endpoint_descriptor *desc)
{
u32 val = 0;
u32 buff_size = 0;
pch_udc_ep_set_trfr_type(ep, desc->bmAttributes);
if (ep->in)
buff_size = UDC_EPIN_BUFF_SIZE;
else
buff_size = UDC_EPOUT_BUFF_SIZE;
pch_udc_ep_set_bufsz(ep, buff_size, ep->in);
pch_udc_ep_set_maxpkt(ep, usb_endpoint_maxp(desc));
pch_udc_ep_set_nak(ep);
pch_udc_ep_fifo_flush(ep, ep->in);
val = ep->num << UDC_CSR_NE_NUM_SHIFT | ep->in << UDC_CSR_NE_DIR_SHIFT |
((desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) <<
UDC_CSR_NE_TYPE_SHIFT) |
(cfg->cur_cfg << UDC_CSR_NE_CFG_SHIFT) |
(cfg->cur_intf << UDC_CSR_NE_INTF_SHIFT) |
(cfg->cur_alt << UDC_CSR_NE_ALT_SHIFT) |
usb_endpoint_maxp(desc) << UDC_CSR_NE_MAX_PKT_SHIFT;
if (ep->in)
pch_udc_write_csr(ep->dev, val, UDC_EPIN_IDX(ep->num));
else
pch_udc_write_csr(ep->dev, val, UDC_EPOUT_IDX(ep->num));
}
static void pch_udc_ep_disable(struct pch_udc_ep *ep)
{
if (ep->in) {
pch_udc_ep_writel(ep, UDC_EPCTL_F, UDC_EPCTL_ADDR);
pch_udc_ep_writel(ep, UDC_EPCTL_SNAK, UDC_EPCTL_ADDR);
pch_udc_ep_bit_set(ep, UDC_EPSTS_ADDR, UDC_EPSTS_IN);
} else {
pch_udc_ep_writel(ep, UDC_EPCTL_SNAK, UDC_EPCTL_ADDR);
}
pch_udc_ep_writel(ep, 0, UDC_DESPTR_ADDR);
}
static void pch_udc_wait_ep_stall(struct pch_udc_ep *ep)
{
unsigned int count = 10000;
while ((pch_udc_read_ep_control(ep) & UDC_EPCTL_S) && --count)
udelay(5);
if (!count)
dev_err(&ep->dev->pdev->dev, "%s: wait error\n", __func__);
}
static void pch_udc_init(struct pch_udc_dev *dev)
{
if (NULL == dev) {
pr_err("%s: Invalid address\n", __func__);
return;
}
pch_udc_writel(dev, UDC_SRST, UDC_SRST_ADDR);
pch_udc_writel(dev, UDC_SRST | UDC_PSRST, UDC_SRST_ADDR);
mdelay(1);
pch_udc_writel(dev, UDC_SRST, UDC_SRST_ADDR);
pch_udc_writel(dev, 0x00, UDC_SRST_ADDR);
mdelay(1);
pch_udc_bit_set(dev, UDC_DEVIRQMSK_ADDR, UDC_DEVINT_MSK);
pch_udc_bit_set(dev, UDC_DEVIRQSTS_ADDR, UDC_DEVINT_MSK);
pch_udc_bit_set(dev, UDC_EPIRQMSK_ADDR, UDC_EPINT_MSK_DISABLE_ALL);
pch_udc_bit_set(dev, UDC_EPIRQSTS_ADDR, UDC_EPINT_MSK_DISABLE_ALL);
if (speed_fs)
pch_udc_bit_set(dev, UDC_DEVCFG_ADDR, UDC_DEVCFG_CSR_PRG |
UDC_DEVCFG_SP | UDC_DEVCFG_SPD_FS);
else
pch_udc_bit_set(dev, UDC_DEVCFG_ADDR, UDC_DEVCFG_CSR_PRG |
UDC_DEVCFG_SP | UDC_DEVCFG_SPD_HS);
pch_udc_bit_set(dev, UDC_DEVCTL_ADDR,
(PCH_UDC_THLEN << UDC_DEVCTL_THLEN_SHIFT) |
(PCH_UDC_BRLEN << UDC_DEVCTL_BRLEN_SHIFT) |
UDC_DEVCTL_MODE | UDC_DEVCTL_BREN |
UDC_DEVCTL_THE);
}
static void pch_udc_exit(struct pch_udc_dev *dev)
{
pch_udc_bit_set(dev, UDC_DEVIRQMSK_ADDR, UDC_DEVINT_MSK);
pch_udc_bit_set(dev, UDC_EPIRQMSK_ADDR, UDC_EPINT_MSK_DISABLE_ALL);
pch_udc_set_disconnect(dev);
}
static int pch_udc_pcd_get_frame(struct usb_gadget *gadget)
{
struct pch_udc_dev *dev;
if (!gadget)
return -EINVAL;
dev = container_of(gadget, struct pch_udc_dev, gadget);
return pch_udc_get_frame(dev);
}
static int pch_udc_pcd_wakeup(struct usb_gadget *gadget)
{
struct pch_udc_dev *dev;
unsigned long flags;
if (!gadget)
return -EINVAL;
dev = container_of(gadget, struct pch_udc_dev, gadget);
spin_lock_irqsave(&dev->lock, flags);
pch_udc_rmt_wakeup(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int pch_udc_pcd_selfpowered(struct usb_gadget *gadget, int value)
{
struct pch_udc_dev *dev;
if (!gadget)
return -EINVAL;
gadget->is_selfpowered = (value != 0);
dev = container_of(gadget, struct pch_udc_dev, gadget);
if (value)
pch_udc_set_selfpowered(dev);
else
pch_udc_clear_selfpowered(dev);
return 0;
}
static int pch_udc_pcd_pullup(struct usb_gadget *gadget, int is_on)
{
struct pch_udc_dev *dev;
if (!gadget)
return -EINVAL;
dev = container_of(gadget, struct pch_udc_dev, gadget);
if (is_on) {
pch_udc_reconnect(dev);
} else {
if (dev->driver && dev->driver->disconnect) {
spin_lock(&dev->lock);
dev->driver->disconnect(&dev->gadget);
spin_unlock(&dev->lock);
}
pch_udc_set_disconnect(dev);
}
return 0;
}
static int pch_udc_pcd_vbus_session(struct usb_gadget *gadget, int is_active)
{
struct pch_udc_dev *dev;
if (!gadget)
return -EINVAL;
dev = container_of(gadget, struct pch_udc_dev, gadget);
pch_udc_vbus_session(dev, is_active);
return 0;
}
static int pch_udc_pcd_vbus_draw(struct usb_gadget *gadget, unsigned int mA)
{
return -EOPNOTSUPP;
}
static int pch_vbus_gpio_get_value(struct pch_udc_dev *dev)
{
int vbus = 0;
if (dev->vbus_gpio.port)
vbus = gpio_get_value(dev->vbus_gpio.port) ? 1 : 0;
else
vbus = -1;
return vbus;
}
static void pch_vbus_gpio_work_fall(struct work_struct *irq_work)
{
struct pch_vbus_gpio_data *vbus_gpio = container_of(irq_work,
struct pch_vbus_gpio_data, irq_work_fall);
struct pch_udc_dev *dev =
container_of(vbus_gpio, struct pch_udc_dev, vbus_gpio);
int vbus_saved = -1;
int vbus;
int count;
if (!dev->vbus_gpio.port)
return;
for (count = 0; count < (PCH_VBUS_PERIOD / PCH_VBUS_INTERVAL);
count++) {
vbus = pch_vbus_gpio_get_value(dev);
if ((vbus_saved == vbus) && (vbus == 0)) {
dev_dbg(&dev->pdev->dev, "VBUS fell");
if (dev->driver
&& dev->driver->disconnect) {
dev->driver->disconnect(
&dev->gadget);
}
if (dev->vbus_gpio.intr)
pch_udc_init(dev);
else
pch_udc_reconnect(dev);
return;
}
vbus_saved = vbus;
mdelay(PCH_VBUS_INTERVAL);
}
}
static void pch_vbus_gpio_work_rise(struct work_struct *irq_work)
{
struct pch_vbus_gpio_data *vbus_gpio = container_of(irq_work,
struct pch_vbus_gpio_data, irq_work_rise);
struct pch_udc_dev *dev =
container_of(vbus_gpio, struct pch_udc_dev, vbus_gpio);
int vbus;
if (!dev->vbus_gpio.port)
return;
mdelay(PCH_VBUS_INTERVAL);
vbus = pch_vbus_gpio_get_value(dev);
if (vbus == 1) {
dev_dbg(&dev->pdev->dev, "VBUS rose");
pch_udc_reconnect(dev);
return;
}
}
static irqreturn_t pch_vbus_gpio_irq(int irq, void *data)
{
struct pch_udc_dev *dev = (struct pch_udc_dev *)data;
if (!dev->vbus_gpio.port || !dev->vbus_gpio.intr)
return IRQ_NONE;
if (pch_vbus_gpio_get_value(dev))
schedule_work(&dev->vbus_gpio.irq_work_rise);
else
schedule_work(&dev->vbus_gpio.irq_work_fall);
return IRQ_HANDLED;
}
static int pch_vbus_gpio_init(struct pch_udc_dev *dev, int vbus_gpio_port)
{
int err;
int irq_num = 0;
dev->vbus_gpio.port = 0;
dev->vbus_gpio.intr = 0;
if (vbus_gpio_port <= -1)
return -EINVAL;
err = gpio_is_valid(vbus_gpio_port);
if (!err) {
pr_err("%s: gpio port %d is invalid\n",
__func__, vbus_gpio_port);
return -EINVAL;
}
err = gpio_request(vbus_gpio_port, "pch_vbus");
if (err) {
pr_err("%s: can't request gpio port %d, err: %d\n",
__func__, vbus_gpio_port, err);
return -EINVAL;
}
dev->vbus_gpio.port = vbus_gpio_port;
gpio_direction_input(vbus_gpio_port);
INIT_WORK(&dev->vbus_gpio.irq_work_fall, pch_vbus_gpio_work_fall);
irq_num = gpio_to_irq(vbus_gpio_port);
if (irq_num > 0) {
irq_set_irq_type(irq_num, IRQ_TYPE_EDGE_BOTH);
err = request_irq(irq_num, pch_vbus_gpio_irq, 0,
"vbus_detect", dev);
if (!err) {
dev->vbus_gpio.intr = irq_num;
INIT_WORK(&dev->vbus_gpio.irq_work_rise,
pch_vbus_gpio_work_rise);
} else {
pr_err("%s: can't request irq %d, err: %d\n",
__func__, irq_num, err);
}
}
return 0;
}
static void pch_vbus_gpio_free(struct pch_udc_dev *dev)
{
if (dev->vbus_gpio.intr)
free_irq(dev->vbus_gpio.intr, dev);
if (dev->vbus_gpio.port)
gpio_free(dev->vbus_gpio.port);
}
static void complete_req(struct pch_udc_ep *ep, struct pch_udc_request *req,
int status)
__releases(&dev->lock
static void empty_req_queue(struct pch_udc_ep *ep)
{
struct pch_udc_request *req;
ep->halted = 1;
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
complete_req(ep, req, -ESHUTDOWN);
}
}
static void pch_udc_free_dma_chain(struct pch_udc_dev *dev,
struct pch_udc_request *req)
{
struct pch_udc_data_dma_desc *td = req->td_data;
unsigned i = req->chain_len;
dma_addr_t addr2;
dma_addr_t addr = (dma_addr_t)td->next;
td->next = 0x00;
for (; i > 1; --i) {
td = phys_to_virt(addr);
addr2 = (dma_addr_t)td->next;
pci_pool_free(dev->data_requests, td, addr);
td->next = 0x00;
addr = addr2;
}
req->chain_len = 1;
}
static int pch_udc_create_dma_chain(struct pch_udc_ep *ep,
struct pch_udc_request *req,
unsigned long buf_len,
gfp_t gfp_flags)
{
struct pch_udc_data_dma_desc *td = req->td_data, *last;
unsigned long bytes = req->req.length, i = 0;
dma_addr_t dma_addr;
unsigned len = 1;
if (req->chain_len > 1)
pch_udc_free_dma_chain(ep->dev, req);
if (req->dma == DMA_ADDR_INVALID)
td->dataptr = req->req.dma;
else
td->dataptr = req->dma;
td->status = PCH_UDC_BS_HST_BSY;
for (; ; bytes -= buf_len, ++len) {
td->status = PCH_UDC_BS_HST_BSY | min(buf_len, bytes);
if (bytes <= buf_len)
break;
last = td;
td = pci_pool_alloc(ep->dev->data_requests, gfp_flags,
&dma_addr);
if (!td)
goto nomem;
i += buf_len;
td->dataptr = req->td_data->dataptr + i;
last->next = dma_addr;
}
req->td_data_last = td;
td->status |= PCH_UDC_DMA_LAST;
td->next = req->td_data_phys;
req->chain_len = len;
return 0;
nomem:
if (len > 1) {
req->chain_len = len;
pch_udc_free_dma_chain(ep->dev, req);
}
req->chain_len = 1;
return -ENOMEM;
}
static int prepare_dma(struct pch_udc_ep *ep, struct pch_udc_request *req,
gfp_t gfp)
{
int retval;
retval = pch_udc_create_dma_chain(ep, req, ep->ep.maxpacket, gfp);
if (retval) {
pr_err("%s: could not create DMA chain:%d\n", __func__, retval);
return retval;
}
if (ep->in)
req->td_data->status = (req->td_data->status &
~PCH_UDC_BUFF_STS) | PCH_UDC_BS_HST_RDY;
return 0;
}
static void process_zlp(struct pch_udc_ep *ep, struct pch_udc_request *req)
{
struct pch_udc_dev *dev = ep->dev;
complete_req(ep, req, 0);
if (dev->set_cfg_not_acked) {
pch_udc_set_csr_done(dev);
dev->set_cfg_not_acked = 0;
}
if (!dev->stall && dev->waiting_zlp_ack) {
pch_udc_ep_clear_nak(&(dev->ep[UDC_EP0IN_IDX]));
dev->waiting_zlp_ack = 0;
}
}
static void pch_udc_start_rxrequest(struct pch_udc_ep *ep,
struct pch_udc_request *req)
{
struct pch_udc_data_dma_desc *td_data;
pch_udc_clear_dma(ep->dev, DMA_DIR_RX);
td_data = req->td_data;
while (1) {
td_data->status = (td_data->status & ~PCH_UDC_BUFF_STS) |
PCH_UDC_BS_HST_RDY;
if ((td_data->status & PCH_UDC_DMA_LAST) == PCH_UDC_DMA_LAST)
break;
td_data = phys_to_virt(td_data->next);
}
pch_udc_ep_set_ddptr(ep, req->td_data_phys);
req->dma_going = 1;
pch_udc_enable_ep_interrupts(ep->dev, UDC_EPINT_OUT_EP0 << ep->num);
pch_udc_set_dma(ep->dev, DMA_DIR_RX);
pch_udc_ep_clear_nak(ep);
pch_udc_ep_set_rrdy(ep);
}
static int pch_udc_pcd_ep_enable(struct usb_ep *usbep,
const struct usb_endpoint_descriptor *desc)
{
struct pch_udc_ep *ep;
struct pch_udc_dev *dev;
unsigned long iflags;
if (!usbep || (usbep->name == ep0_string) || !desc ||
(desc->bDescriptorType != USB_DT_ENDPOINT) || !desc->wMaxPacketSize)
return -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if (!dev->driver || (dev->gadget.speed == USB_SPEED_UNKNOWN))
return -ESHUTDOWN;
spin_lock_irqsave(&dev->lock, iflags);
ep->ep.desc = desc;
ep->halted = 0;
pch_udc_ep_enable(ep, &ep->dev->cfg_data, desc);
ep->ep.maxpacket = usb_endpoint_maxp(desc);
pch_udc_enable_ep_interrupts(ep->dev, PCH_UDC_EPINT(ep->in, ep->num));
spin_unlock_irqrestore(&dev->lock, iflags);
return 0;
}
static int pch_udc_pcd_ep_disable(struct usb_ep *usbep)
{
struct pch_udc_ep *ep;
struct pch_udc_dev *dev;
unsigned long iflags;
if (!usbep)
return -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if ((usbep->name == ep0_string) || !ep->ep.desc)
return -EINVAL;
spin_lock_irqsave(&ep->dev->lock, iflags);
empty_req_queue(ep);
ep->halted = 1;
pch_udc_ep_disable(ep);
pch_udc_disable_ep_interrupts(ep->dev, PCH_UDC_EPINT(ep->in, ep->num));
ep->ep.desc = NULL;
INIT_LIST_HEAD(&ep->queue);
spin_unlock_irqrestore(&ep->dev->lock, iflags);
return 0;
}
static struct usb_request *pch_udc_alloc_request(struct usb_ep *usbep,
gfp_t gfp)
{
struct pch_udc_request *req;
struct pch_udc_ep *ep;
struct pch_udc_data_dma_desc *dma_desc;
struct pch_udc_dev *dev;
if (!usbep)
return NULL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
req = kzalloc(sizeof *req, gfp);
if (!req)
return NULL;
req->req.dma = DMA_ADDR_INVALID;
req->dma = DMA_ADDR_INVALID;
INIT_LIST_HEAD(&req->queue);
if (!ep->dev->dma_addr)
return &req->req;
dma_desc = pci_pool_alloc(ep->dev->data_requests, gfp,
&req->td_data_phys);
if (NULL == dma_desc) {
kfree(req);
return NULL;
}
dma_desc->status |= PCH_UDC_BS_HST_BSY;
dma_desc->dataptr = cpu_to_le32(DMA_ADDR_INVALID);
req->td_data = dma_desc;
req->td_data_last = dma_desc;
req->chain_len = 1;
return &req->req;
}
static void pch_udc_free_request(struct usb_ep *usbep,
struct usb_request *usbreq)
{
struct pch_udc_ep *ep;
struct pch_udc_request *req;
struct pch_udc_dev *dev;
if (!usbep || !usbreq)
return;
ep = container_of(usbep, struct pch_udc_ep, ep);
req = container_of(usbreq, struct pch_udc_request, req);
dev = ep->dev;
if (!list_empty(&req->queue))
dev_err(&dev->pdev->dev, "%s: %s req=0x%p queue not empty\n",
__func__, usbep->name, req);
if (req->td_data != NULL) {
if (req->chain_len > 1)
pch_udc_free_dma_chain(ep->dev, req);
pci_pool_free(ep->dev->data_requests, req->td_data,
req->td_data_phys);
}
kfree(req);
}
static int pch_udc_pcd_queue(struct usb_ep *usbep, struct usb_request *usbreq,
gfp_t gfp)
{
int retval = 0;
struct pch_udc_ep *ep;
struct pch_udc_dev *dev;
struct pch_udc_request *req;
unsigned long iflags;
if (!usbep || !usbreq || !usbreq->complete || !usbreq->buf)
return -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if (!ep->ep.desc && ep->num)
return -EINVAL;
req = container_of(usbreq, struct pch_udc_request, req);
if (!list_empty(&req->queue))
return -EINVAL;
if (!dev->driver || (dev->gadget.speed == USB_SPEED_UNKNOWN))
return -ESHUTDOWN;
spin_lock_irqsave(&dev->lock, iflags);
if (usbreq->length &&
((usbreq->dma == DMA_ADDR_INVALID) || !usbreq->dma)) {
if (!((unsigned long)(usbreq->buf) & 0x03)) {
if (ep->in)
usbreq->dma = dma_map_single(&dev->pdev->dev,
usbreq->buf,
usbreq->length,
DMA_TO_DEVICE);
else
usbreq->dma = dma_map_single(&dev->pdev->dev,
usbreq->buf,
usbreq->length,
DMA_FROM_DEVICE);
} else {
req->buf = kzalloc(usbreq->length, GFP_ATOMIC);
if (!req->buf) {
retval = -ENOMEM;
goto probe_end;
}
if (ep->in) {
memcpy(req->buf, usbreq->buf, usbreq->length);
req->dma = dma_map_single(&dev->pdev->dev,
req->buf,
usbreq->length,
DMA_TO_DEVICE);
} else
req->dma = dma_map_single(&dev->pdev->dev,
req->buf,
usbreq->length,
DMA_FROM_DEVICE);
}
req->dma_mapped = 1;
}
if (usbreq->length > 0) {
retval = prepare_dma(ep, req, GFP_ATOMIC);
if (retval)
goto probe_end;
}
usbreq->actual = 0;
usbreq->status = -EINPROGRESS;
req->dma_done = 0;
if (list_empty(&ep->queue) && !ep->halted) {
if (!usbreq->length) {
process_zlp(ep, req);
retval = 0;
goto probe_end;
}
if (!ep->in) {
pch_udc_start_rxrequest(ep, req);
} else {
pch_udc_wait_ep_stall(ep);
pch_udc_ep_clear_nak(ep);
pch_udc_enable_ep_interrupts(ep->dev, (1 << ep->num));
}
}
if (req != NULL)
list_add_tail(&req->queue, &ep->queue);
probe_end:
spin_unlock_irqrestore(&dev->lock, iflags);
return retval;
}
static int pch_udc_pcd_dequeue(struct usb_ep *usbep,
struct usb_request *usbreq)
{
struct pch_udc_ep *ep;
struct pch_udc_request *req;
struct pch_udc_dev *dev;
unsigned long flags;
int ret = -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if (!usbep || !usbreq || (!ep->ep.desc && ep->num))
return ret;
req = container_of(usbreq, struct pch_udc_request, req);
spin_lock_irqsave(&ep->dev->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (&req->req == usbreq) {
pch_udc_ep_set_nak(ep);
if (!list_empty(&req->queue))
complete_req(ep, req, -ECONNRESET);
ret = 0;
break;
}
}
spin_unlock_irqrestore(&ep->dev->lock, flags);
return ret;
}
static int pch_udc_pcd_set_halt(struct usb_ep *usbep, int halt)
{
struct pch_udc_ep *ep;
struct pch_udc_dev *dev;
unsigned long iflags;
int ret;
if (!usbep)
return -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if (!ep->ep.desc && !ep->num)
return -EINVAL;
if (!ep->dev->driver || (ep->dev->gadget.speed == USB_SPEED_UNKNOWN))
return -ESHUTDOWN;
spin_lock_irqsave(&udc_stall_spinlock, iflags);
if (list_empty(&ep->queue)) {
if (halt) {
if (ep->num == PCH_UDC_EP0)
ep->dev->stall = 1;
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in,
ep->num));
} else {
pch_udc_ep_clear_stall(ep);
}
ret = 0;
} else {
ret = -EAGAIN;
}
spin_unlock_irqrestore(&udc_stall_spinlock, iflags);
return ret;
}
static int pch_udc_pcd_set_wedge(struct usb_ep *usbep)
{
struct pch_udc_ep *ep;
struct pch_udc_dev *dev;
unsigned long iflags;
int ret;
if (!usbep)
return -EINVAL;
ep = container_of(usbep, struct pch_udc_ep, ep);
dev = ep->dev;
if (!ep->ep.desc && !ep->num)
return -EINVAL;
if (!ep->dev->driver || (ep->dev->gadget.speed == USB_SPEED_UNKNOWN))
return -ESHUTDOWN;
spin_lock_irqsave(&udc_stall_spinlock, iflags);
if (!list_empty(&ep->queue)) {
ret = -EAGAIN;
} else {
if (ep->num == PCH_UDC_EP0)
ep->dev->stall = 1;
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
ep->dev->prot_stall = 1;
ret = 0;
}
spin_unlock_irqrestore(&udc_stall_spinlock, iflags);
return ret;
}
static void pch_udc_pcd_fifo_flush(struct usb_ep *usbep)
{
struct pch_udc_ep *ep;
if (!usbep)
return;
ep = container_of(usbep, struct pch_udc_ep, ep);
if (ep->ep.desc || !ep->num)
pch_udc_ep_fifo_flush(ep, ep->in);
}
static void pch_udc_init_setup_buff(struct pch_udc_stp_dma_desc *td_stp)
{
static u32 pky_marker;
if (!td_stp)
return;
td_stp->reserved = ++pky_marker;
memset(&td_stp->request, 0xFF, sizeof td_stp->request);
td_stp->status = PCH_UDC_BS_HST_RDY;
}
static void pch_udc_start_next_txrequest(struct pch_udc_ep *ep)
{
struct pch_udc_request *req;
struct pch_udc_data_dma_desc *td_data;
if (pch_udc_read_ep_control(ep) & UDC_EPCTL_P)
return;
if (list_empty(&ep->queue))
return;
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
if (req->dma_going)
return;
if (!req->td_data)
return;
pch_udc_wait_ep_stall(ep);
req->dma_going = 1;
pch_udc_ep_set_ddptr(ep, 0);
td_data = req->td_data;
while (1) {
td_data->status = (td_data->status & ~PCH_UDC_BUFF_STS) |
PCH_UDC_BS_HST_RDY;
if ((td_data->status & PCH_UDC_DMA_LAST) == PCH_UDC_DMA_LAST)
break;
td_data = phys_to_virt(td_data->next);
}
pch_udc_ep_set_ddptr(ep, req->td_data_phys);
pch_udc_set_dma(ep->dev, DMA_DIR_TX);
pch_udc_ep_set_pd(ep);
pch_udc_enable_ep_interrupts(ep->dev, PCH_UDC_EPINT(ep->in, ep->num));
pch_udc_ep_clear_nak(ep);
}
static void pch_udc_complete_transfer(struct pch_udc_ep *ep)
{
struct pch_udc_request *req;
struct pch_udc_dev *dev = ep->dev;
if (list_empty(&ep->queue))
return;
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
if ((req->td_data_last->status & PCH_UDC_BUFF_STS) !=
PCH_UDC_BS_DMA_DONE)
return;
if ((req->td_data_last->status & PCH_UDC_RXTX_STS) !=
PCH_UDC_RTS_SUCC) {
dev_err(&dev->pdev->dev, "Invalid RXTX status (0x%08x) "
"epstatus=0x%08x\n",
(req->td_data_last->status & PCH_UDC_RXTX_STS),
(int)(ep->epsts));
return;
}
req->req.actual = req->req.length;
req->td_data_last->status = PCH_UDC_BS_HST_BSY | PCH_UDC_DMA_LAST;
req->td_data->status = PCH_UDC_BS_HST_BSY | PCH_UDC_DMA_LAST;
complete_req(ep, req, 0);
req->dma_going = 0;
if (!list_empty(&ep->queue)) {
pch_udc_wait_ep_stall(ep);
pch_udc_ep_clear_nak(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
} else {
pch_udc_disable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
}
}
static void pch_udc_complete_receiver(struct pch_udc_ep *ep)
{
struct pch_udc_request *req;
struct pch_udc_dev *dev = ep->dev;
unsigned int count;
struct pch_udc_data_dma_desc *td;
dma_addr_t addr;
if (list_empty(&ep->queue))
return;
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
pch_udc_clear_dma(ep->dev, DMA_DIR_RX);
pch_udc_ep_set_ddptr(ep, 0);
if ((req->td_data_last->status & PCH_UDC_BUFF_STS) ==
PCH_UDC_BS_DMA_DONE)
td = req->td_data_last;
else
td = req->td_data;
while (1) {
if ((td->status & PCH_UDC_RXTX_STS) != PCH_UDC_RTS_SUCC) {
dev_err(&dev->pdev->dev, "Invalid RXTX status=0x%08x "
"epstatus=0x%08x\n",
(req->td_data->status & PCH_UDC_RXTX_STS),
(int)(ep->epsts));
return;
}
if ((td->status & PCH_UDC_BUFF_STS) == PCH_UDC_BS_DMA_DONE)
if (td->status & PCH_UDC_DMA_LAST) {
count = td->status & PCH_UDC_RXTX_BYTES;
break;
}
if (td == req->td_data_last) {
dev_err(&dev->pdev->dev, "Not complete RX descriptor");
return;
}
addr = (dma_addr_t)td->next;
td = phys_to_virt(addr);
}
if (!count && (req->req.length == UDC_DMA_MAXPACKET))
count = UDC_DMA_MAXPACKET;
req->td_data->status |= PCH_UDC_DMA_LAST;
td->status |= PCH_UDC_BS_HST_BSY;
req->dma_going = 0;
req->req.actual = count;
complete_req(ep, req, 0);
if (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
pch_udc_start_rxrequest(ep, req);
}
}
static void pch_udc_svc_data_in(struct pch_udc_dev *dev, int ep_num)
{
u32 epsts;
struct pch_udc_ep *ep;
ep = &dev->ep[UDC_EPIN_IDX(ep_num)];
epsts = ep->epsts;
ep->epsts = 0;
if (!(epsts & (UDC_EPSTS_IN | UDC_EPSTS_BNA | UDC_EPSTS_HE |
UDC_EPSTS_TDC | UDC_EPSTS_RCS | UDC_EPSTS_TXEMPTY |
UDC_EPSTS_RSS | UDC_EPSTS_XFERDONE)))
return;
if ((epsts & UDC_EPSTS_BNA))
return;
if (epsts & UDC_EPSTS_HE)
return;
if (epsts & UDC_EPSTS_RSS) {
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
}
if (epsts & UDC_EPSTS_RCS) {
if (!dev->prot_stall) {
pch_udc_ep_clear_stall(ep);
} else {
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
}
}
if (epsts & UDC_EPSTS_TDC)
pch_udc_complete_transfer(ep);
if ((epsts & UDC_EPSTS_IN) && !(epsts & UDC_EPSTS_RSS) &&
!(epsts & UDC_EPSTS_TDC) && !(epsts & UDC_EPSTS_TXEMPTY))
pch_udc_start_next_txrequest(ep);
}
static void pch_udc_svc_data_out(struct pch_udc_dev *dev, int ep_num)
{
u32 epsts;
struct pch_udc_ep *ep;
struct pch_udc_request *req = NULL;
ep = &dev->ep[UDC_EPOUT_IDX(ep_num)];
epsts = ep->epsts;
ep->epsts = 0;
if ((epsts & UDC_EPSTS_BNA) && (!list_empty(&ep->queue))) {
req = list_entry(ep->queue.next, struct pch_udc_request,
queue);
if ((req->td_data_last->status & PCH_UDC_BUFF_STS) !=
PCH_UDC_BS_DMA_DONE) {
if (!req->dma_going)
pch_udc_start_rxrequest(ep, req);
return;
}
}
if (epsts & UDC_EPSTS_HE)
return;
if (epsts & UDC_EPSTS_RSS) {
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
}
if (epsts & UDC_EPSTS_RCS) {
if (!dev->prot_stall) {
pch_udc_ep_clear_stall(ep);
} else {
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
}
}
if (((epsts & UDC_EPSTS_OUT_MASK) >> UDC_EPSTS_OUT_SHIFT) ==
UDC_EPSTS_OUT_DATA) {
if (ep->dev->prot_stall == 1) {
pch_udc_ep_set_stall(ep);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
} else {
pch_udc_complete_receiver(ep);
}
}
if (list_empty(&ep->queue))
pch_udc_set_dma(dev, DMA_DIR_RX);
}
static void pch_udc_svc_control_in(struct pch_udc_dev *dev)
{
u32 epsts;
struct pch_udc_ep *ep;
struct pch_udc_ep *ep_out;
ep = &dev->ep[UDC_EP0IN_IDX];
ep_out = &dev->ep[UDC_EP0OUT_IDX];
epsts = ep->epsts;
ep->epsts = 0;
if (!(epsts & (UDC_EPSTS_IN | UDC_EPSTS_BNA | UDC_EPSTS_HE |
UDC_EPSTS_TDC | UDC_EPSTS_RCS | UDC_EPSTS_TXEMPTY |
UDC_EPSTS_XFERDONE)))
return;
if ((epsts & UDC_EPSTS_BNA))
return;
if (epsts & UDC_EPSTS_HE)
return;
if ((epsts & UDC_EPSTS_TDC) && (!dev->stall)) {
pch_udc_complete_transfer(ep);
pch_udc_clear_dma(dev, DMA_DIR_RX);
ep_out->td_data->status = (ep_out->td_data->status &
~PCH_UDC_BUFF_STS) |
PCH_UDC_BS_HST_RDY;
pch_udc_ep_clear_nak(ep_out);
pch_udc_set_dma(dev, DMA_DIR_RX);
pch_udc_ep_set_rrdy(ep_out);
}
if ((epsts & UDC_EPSTS_IN) && !(epsts & UDC_EPSTS_TDC) &&
!(epsts & UDC_EPSTS_TXEMPTY))
pch_udc_start_next_txrequest(ep);
}
static void pch_udc_svc_control_out(struct pch_udc_dev *dev)
__releases(&dev->lock
static void pch_udc_postsvc_epinters(struct pch_udc_dev *dev, int ep_num)
{
struct pch_udc_ep *ep;
struct pch_udc_request *req;
ep = &dev->ep[UDC_EPIN_IDX(ep_num)];
if (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct pch_udc_request, queue);
pch_udc_enable_ep_interrupts(ep->dev,
PCH_UDC_EPINT(ep->in, ep->num));
pch_udc_ep_clear_nak(ep);
}
}
static void pch_udc_read_all_epstatus(struct pch_udc_dev *dev, u32 ep_intr)
{
int i;
struct pch_udc_ep *ep;
for (i = 0; i < PCH_UDC_USED_EP_NUM; i++) {
if (ep_intr & (0x1 << i)) {
ep = &dev->ep[UDC_EPIN_IDX(i)];
ep->epsts = pch_udc_read_ep_status(ep);
pch_udc_clear_ep_status(ep, ep->epsts);
}
if (ep_intr & (0x10000 << i)) {
ep = &dev->ep[UDC_EPOUT_IDX(i)];
ep->epsts = pch_udc_read_ep_status(ep);
pch_udc_clear_ep_status(ep, ep->epsts);
}
}
}
static void pch_udc_activate_control_ep(struct pch_udc_dev *dev)
{
struct pch_udc_ep *ep;
u32 val;
ep = &dev->ep[UDC_EP0IN_IDX];
pch_udc_clear_ep_control(ep);
pch_udc_ep_fifo_flush(ep, ep->in);
pch_udc_ep_set_bufsz(ep, UDC_EP0IN_BUFF_SIZE, ep->in);
pch_udc_ep_set_maxpkt(ep, UDC_EP0IN_MAX_PKT_SIZE);
ep->td_data = NULL;
ep->td_stp = NULL;
ep->td_data_phys = 0;
ep->td_stp_phys = 0;
ep = &dev->ep[UDC_EP0OUT_IDX];
pch_udc_clear_ep_control(ep);
pch_udc_ep_fifo_flush(ep, ep->in);
pch_udc_ep_set_bufsz(ep, UDC_EP0OUT_BUFF_SIZE, ep->in);
pch_udc_ep_set_maxpkt(ep, UDC_EP0OUT_MAX_PKT_SIZE);
val = UDC_EP0OUT_MAX_PKT_SIZE << UDC_CSR_NE_MAX_PKT_SHIFT;
pch_udc_write_csr(ep->dev, val, UDC_EP0OUT_IDX);
pch_udc_init_setup_buff(ep->td_stp);
pch_udc_ep_set_subptr(ep, ep->td_stp_phys);
pch_udc_ep_set_ddptr(ep, ep->td_data_phys);
ep->td_data->status = PCH_UDC_DMA_LAST;
ep->td_data->dataptr = dev->dma_addr;
ep->td_data->next = ep->td_data_phys;
pch_udc_ep_clear_nak(ep);
}
static void pch_udc_svc_ur_interrupt(struct pch_udc_dev *dev)
{
struct pch_udc_ep *ep;
int i;
pch_udc_clear_dma(dev, DMA_DIR_TX);
pch_udc_clear_dma(dev, DMA_DIR_RX);
pch_udc_disable_ep_interrupts(dev, UDC_EPINT_MSK_DISABLE_ALL);
pch_udc_write_ep_interrupts(dev, UDC_EPINT_MSK_DISABLE_ALL);
for (i = 0; i < PCH_UDC_EP_NUM; i++) {
ep = &dev->ep[i];
pch_udc_clear_ep_status(ep, UDC_EPSTS_ALL_CLR_MASK);
pch_udc_clear_ep_control(ep);
pch_udc_ep_set_ddptr(ep, 0);
pch_udc_write_csr(ep->dev, 0x00, i);
}
dev->stall = 0;
dev->prot_stall = 0;
dev->waiting_zlp_ack = 0;
dev->set_cfg_not_acked = 0;
for (i = 0; i < (PCH_UDC_USED_EP_NUM*2); i++) {
ep = &dev->ep[i];
pch_udc_ep_set_nak(ep);
pch_udc_ep_fifo_flush(ep, ep->in);
empty_req_queue(ep);
}
if (dev->driver) {
spin_lock(&dev->lock);
usb_gadget_udc_reset(&dev->gadget, dev->driver);
spin_unlock(&dev->lock);
}
}
static void pch_udc_svc_enum_interrupt(struct pch_udc_dev *dev)
{
u32 dev_stat, dev_speed;
u32 speed = USB_SPEED_FULL;
dev_stat = pch_udc_read_device_status(dev);
dev_speed = (dev_stat & UDC_DEVSTS_ENUM_SPEED_MASK) >>
UDC_DEVSTS_ENUM_SPEED_SHIFT;
switch (dev_speed) {
case UDC_DEVSTS_ENUM_SPEED_HIGH:
speed = USB_SPEED_HIGH;
break;
case UDC_DEVSTS_ENUM_SPEED_FULL:
speed = USB_SPEED_FULL;
break;
case UDC_DEVSTS_ENUM_SPEED_LOW:
speed = USB_SPEED_LOW;
break;
default:
BUG();
}
dev->gadget.speed = speed;
pch_udc_activate_control_ep(dev);
pch_udc_enable_ep_interrupts(dev, UDC_EPINT_IN_EP0 | UDC_EPINT_OUT_EP0);
pch_udc_set_dma(dev, DMA_DIR_TX);
pch_udc_set_dma(dev, DMA_DIR_RX);
pch_udc_ep_set_rrdy(&(dev->ep[UDC_EP0OUT_IDX]));
pch_udc_enable_interrupts(dev, UDC_DEVINT_UR | UDC_DEVINT_US |
UDC_DEVINT_ES | UDC_DEVINT_ENUM |
UDC_DEVINT_SI | UDC_DEVINT_SC);
}
static void pch_udc_svc_intf_interrupt(struct pch_udc_dev *dev)
{
u32 reg, dev_stat = 0;
int i, ret;
dev_stat = pch_udc_read_device_status(dev);
dev->cfg_data.cur_intf = (dev_stat & UDC_DEVSTS_INTF_MASK) >>
UDC_DEVSTS_INTF_SHIFT;
dev->cfg_data.cur_alt = (dev_stat & UDC_DEVSTS_ALT_MASK) >>
UDC_DEVSTS_ALT_SHIFT;
dev->set_cfg_not_acked = 1;
memset(&dev->setup_data, 0 , sizeof dev->setup_data);
dev->setup_data.bRequest = USB_REQ_SET_INTERFACE;
dev->setup_data.bRequestType = USB_RECIP_INTERFACE;
dev->setup_data.wValue = cpu_to_le16(dev->cfg_data.cur_alt);
dev->setup_data.wIndex = cpu_to_le16(dev->cfg_data.cur_intf);
reg = pch_udc_read_csr(dev, UDC_EP0OUT_IDX);
reg = (reg & ~UDC_CSR_NE_INTF_MASK) |
(dev->cfg_data.cur_intf << UDC_CSR_NE_INTF_SHIFT);
reg = (reg & ~UDC_CSR_NE_ALT_MASK) |
(dev->cfg_data.cur_alt << UDC_CSR_NE_ALT_SHIFT);
pch_udc_write_csr(dev, reg, UDC_EP0OUT_IDX);
for (i = 0; i < PCH_UDC_USED_EP_NUM * 2; i++) {
pch_udc_ep_clear_stall(&(dev->ep[i]));
dev->ep[i].halted = 0;
}
dev->stall = 0;
spin_lock(&dev->lock);
ret = dev->driver->setup(&dev->gadget, &dev->setup_data);
spin_unlock(&dev->lock);
}
static void pch_udc_svc_cfg_interrupt(struct pch_udc_dev *dev)
{
int i, ret;
u32 reg, dev_stat = 0;
dev_stat = pch_udc_read_device_status(dev);
dev->set_cfg_not_acked = 1;
dev->cfg_data.cur_cfg = (dev_stat & UDC_DEVSTS_CFG_MASK) >>
UDC_DEVSTS_CFG_SHIFT;
memset(&dev->setup_data, 0 , sizeof dev->setup_data);
dev->setup_data.bRequest = USB_REQ_SET_CONFIGURATION;
dev->setup_data.wValue = cpu_to_le16(dev->cfg_data.cur_cfg);
reg = pch_udc_read_csr(dev, UDC_EP0OUT_IDX);
reg = (reg & ~UDC_CSR_NE_CFG_MASK) |
(dev->cfg_data.cur_cfg << UDC_CSR_NE_CFG_SHIFT);
pch_udc_write_csr(dev, reg, UDC_EP0OUT_IDX);
for (i = 0; i < PCH_UDC_USED_EP_NUM * 2; i++) {
pch_udc_ep_clear_stall(&(dev->ep[i]));
dev->ep[i].halted = 0;
}
dev->stall = 0;
spin_lock(&dev->lock);
ret = dev->driver->setup(&dev->gadget, &dev->setup_data);
spin_unlock(&dev->lock);
}
static void pch_udc_dev_isr(struct pch_udc_dev *dev, u32 dev_intr)
{
int vbus;
if (dev_intr & UDC_DEVINT_UR) {
pch_udc_svc_ur_interrupt(dev);
dev_dbg(&dev->pdev->dev, "USB_RESET\n");
}
if (dev_intr & UDC_DEVINT_ENUM) {
pch_udc_svc_enum_interrupt(dev);
dev_dbg(&dev->pdev->dev, "USB_ENUM\n");
}
if (dev_intr & UDC_DEVINT_SI)
pch_udc_svc_intf_interrupt(dev);
if (dev_intr & UDC_DEVINT_SC)
pch_udc_svc_cfg_interrupt(dev);
if (dev_intr & UDC_DEVINT_US) {
if (dev->driver
&& dev->driver->suspend) {
spin_lock(&dev->lock);
dev->driver->suspend(&dev->gadget);
spin_unlock(&dev->lock);
}
vbus = pch_vbus_gpio_get_value(dev);
if ((dev->vbus_session == 0)
&& (vbus != 1)) {
if (dev->driver && dev->driver->disconnect) {
spin_lock(&dev->lock);
dev->driver->disconnect(&dev->gadget);
spin_unlock(&dev->lock);
}
pch_udc_reconnect(dev);
} else if ((dev->vbus_session == 0)
&& (vbus == 1)
&& !dev->vbus_gpio.intr)
schedule_work(&dev->vbus_gpio.irq_work_fall);
dev_dbg(&dev->pdev->dev, "USB_SUSPEND\n");
}
if (dev_intr & UDC_DEVINT_SOF)
dev_dbg(&dev->pdev->dev, "SOF\n");
if (dev_intr & UDC_DEVINT_ES)
dev_dbg(&dev->pdev->dev, "ES\n");
if (dev_intr & UDC_DEVINT_RWKP)
dev_dbg(&dev->pdev->dev, "RWKP\n");
}
static irqreturn_t pch_udc_isr(int irq, void *pdev)
{
struct pch_udc_dev *dev = (struct pch_udc_dev *) pdev;
u32 dev_intr, ep_intr;
int i;
dev_intr = pch_udc_read_device_interrupts(dev);
ep_intr = pch_udc_read_ep_interrupts(dev);
if (dev_intr == ep_intr)
if (dev_intr == pch_udc_readl(dev, UDC_DEVCFG_ADDR)) {
dev_dbg(&dev->pdev->dev, "UDC: Hung up\n");
pch_udc_writel(dev, UDC_SRST, UDC_SRST_ADDR);
return IRQ_HANDLED;
}
if (dev_intr)
pch_udc_write_device_interrupts(dev, dev_intr);
if (ep_intr)
pch_udc_write_ep_interrupts(dev, ep_intr);
if (!dev_intr && !ep_intr)
return IRQ_NONE;
spin_lock(&dev->lock);
if (dev_intr)
pch_udc_dev_isr(dev, dev_intr);
if (ep_intr) {
pch_udc_read_all_epstatus(dev, ep_intr);
if (ep_intr & UDC_EPINT_IN_EP0) {
pch_udc_svc_control_in(dev);
pch_udc_postsvc_epinters(dev, 0);
}
if (ep_intr & UDC_EPINT_OUT_EP0)
pch_udc_svc_control_out(dev);
for (i = 1; i < PCH_UDC_USED_EP_NUM; i++) {
if (ep_intr & (1 << i)) {
pch_udc_svc_data_in(dev, i);
pch_udc_postsvc_epinters(dev, i);
}
}
for (i = UDC_EPINT_OUT_SHIFT + 1; i < (UDC_EPINT_OUT_SHIFT +
PCH_UDC_USED_EP_NUM); i++)
if (ep_intr & (1 << i))
pch_udc_svc_data_out(dev, i -
UDC_EPINT_OUT_SHIFT);
}
spin_unlock(&dev->lock);
return IRQ_HANDLED;
}
static void pch_udc_setup_ep0(struct pch_udc_dev *dev)
{
pch_udc_enable_ep_interrupts(dev, UDC_EPINT_IN_EP0 |
UDC_EPINT_OUT_EP0);
pch_udc_enable_interrupts(dev, UDC_DEVINT_UR | UDC_DEVINT_US |
UDC_DEVINT_ES | UDC_DEVINT_ENUM |
UDC_DEVINT_SI | UDC_DEVINT_SC);
}
static void gadget_release(struct device *pdev)
{
struct pch_udc_dev *dev = dev_get_drvdata(pdev);
kfree(dev);
}
static void pch_udc_pcd_reinit(struct pch_udc_dev *dev)
{
const char *const ep_string[] = {
ep0_string, "ep0out", "ep1in", "ep1out", "ep2in", "ep2out",
"ep3in", "ep3out", "ep4in", "ep4out", "ep5in", "ep5out",
"ep6in", "ep6out", "ep7in", "ep7out", "ep8in", "ep8out",
"ep9in", "ep9out", "ep10in", "ep10out", "ep11in", "ep11out",
"ep12in", "ep12out", "ep13in", "ep13out", "ep14in", "ep14out",
"ep15in", "ep15out",
};
int i;
dev->gadget.speed = USB_SPEED_UNKNOWN;
INIT_LIST_HEAD(&dev->gadget.ep_list);
memset(dev->ep, 0, sizeof dev->ep);
for (i = 0; i < PCH_UDC_EP_NUM; i++) {
struct pch_udc_ep *ep = &dev->ep[i];
ep->dev = dev;
ep->halted = 1;
ep->num = i / 2;
ep->in = ~i & 1;
ep->ep.name = ep_string[i];
ep->ep.ops = &pch_udc_ep_ops;
if (ep->in) {
ep->offset_addr = ep->num * UDC_EP_REG_SHIFT;
ep->ep.caps.dir_in = true;
} else {
ep->offset_addr = (UDC_EPINT_OUT_SHIFT + ep->num) *
UDC_EP_REG_SHIFT;
ep->ep.caps.dir_out = true;
}
if (i == UDC_EP0IN_IDX || i == UDC_EP0OUT_IDX) {
ep->ep.caps.type_control = true;
} else {
ep->ep.caps.type_iso = true;
ep->ep.caps.type_bulk = true;
ep->ep.caps.type_int = true;
}
usb_ep_set_maxpacket_limit(&ep->ep, UDC_BULK_MAX_PKT_SIZE);
list_add_tail(&ep->ep.ep_list, &dev->gadget.ep_list);
INIT_LIST_HEAD(&ep->queue);
}
usb_ep_set_maxpacket_limit(&dev->ep[UDC_EP0IN_IDX].ep, UDC_EP0IN_MAX_PKT_SIZE);
usb_ep_set_maxpacket_limit(&dev->ep[UDC_EP0OUT_IDX].ep, UDC_EP0OUT_MAX_PKT_SIZE);
list_del_init(&dev->ep[UDC_EP0IN_IDX].ep.ep_list);
list_del_init(&dev->ep[UDC_EP0OUT_IDX].ep.ep_list);
dev->gadget.ep0 = &dev->ep[UDC_EP0IN_IDX].ep;
INIT_LIST_HEAD(&dev->gadget.ep0->ep_list);
}
static int pch_udc_pcd_init(struct pch_udc_dev *dev)
{
pch_udc_init(dev);
pch_udc_pcd_reinit(dev);
pch_vbus_gpio_init(dev, vbus_gpio_port);
return 0;
}
static int init_dma_pools(struct pch_udc_dev *dev)
{
struct pch_udc_stp_dma_desc *td_stp;
struct pch_udc_data_dma_desc *td_data;
dev->data_requests = pci_pool_create("data_requests", dev->pdev,
sizeof(struct pch_udc_data_dma_desc), 0, 0);
if (!dev->data_requests) {
dev_err(&dev->pdev->dev, "%s: can't get request data pool\n",
__func__);
return -ENOMEM;
}
dev->stp_requests = pci_pool_create("setup requests", dev->pdev,
sizeof(struct pch_udc_stp_dma_desc), 0, 0);
if (!dev->stp_requests) {
dev_err(&dev->pdev->dev, "%s: can't get setup request pool\n",
__func__);
return -ENOMEM;
}
td_stp = pci_pool_alloc(dev->stp_requests, GFP_KERNEL,
&dev->ep[UDC_EP0OUT_IDX].td_stp_phys);
if (!td_stp) {
dev_err(&dev->pdev->dev,
"%s: can't allocate setup dma descriptor\n", __func__);
return -ENOMEM;
}
dev->ep[UDC_EP0OUT_IDX].td_stp = td_stp;
td_data = pci_pool_alloc(dev->data_requests, GFP_KERNEL,
&dev->ep[UDC_EP0OUT_IDX].td_data_phys);
if (!td_data) {
dev_err(&dev->pdev->dev,
"%s: can't allocate data dma descriptor\n", __func__);
return -ENOMEM;
}
dev->ep[UDC_EP0OUT_IDX].td_data = td_data;
dev->ep[UDC_EP0IN_IDX].td_stp = NULL;
dev->ep[UDC_EP0IN_IDX].td_stp_phys = 0;
dev->ep[UDC_EP0IN_IDX].td_data = NULL;
dev->ep[UDC_EP0IN_IDX].td_data_phys = 0;
dev->ep0out_buf = kzalloc(UDC_EP0OUT_BUFF_SIZE * 4, GFP_KERNEL);
if (!dev->ep0out_buf)
return -ENOMEM;
dev->dma_addr = dma_map_single(&dev->pdev->dev, dev->ep0out_buf,
UDC_EP0OUT_BUFF_SIZE * 4,
DMA_FROM_DEVICE);
return 0;
}
static int pch_udc_start(struct usb_gadget *g,
struct usb_gadget_driver *driver)
{
struct pch_udc_dev *dev = to_pch_udc(g);
driver->driver.bus = NULL;
dev->driver = driver;
pch_udc_setup_ep0(dev);
if ((pch_vbus_gpio_get_value(dev) != 0) || !dev->vbus_gpio.intr)
pch_udc_clear_disconnect(dev);
dev->connected = 1;
return 0;
}
static int pch_udc_stop(struct usb_gadget *g)
{
struct pch_udc_dev *dev = to_pch_udc(g);
pch_udc_disable_interrupts(dev, UDC_DEVINT_MSK);
dev->driver = NULL;
dev->connected = 0;
pch_udc_set_disconnect(dev);
return 0;
}
static void pch_udc_shutdown(struct pci_dev *pdev)
{
struct pch_udc_dev *dev = pci_get_drvdata(pdev);
pch_udc_disable_interrupts(dev, UDC_DEVINT_MSK);
pch_udc_disable_ep_interrupts(dev, UDC_EPINT_MSK_DISABLE_ALL);
pch_udc_set_disconnect(dev);
}
static void pch_udc_remove(struct pci_dev *pdev)
{
struct pch_udc_dev *dev = pci_get_drvdata(pdev);
usb_del_gadget_udc(&dev->gadget);
if (dev->driver)
dev_err(&pdev->dev,
"%s: gadget driver still bound!!!\n", __func__);
if (dev->data_requests)
pci_pool_destroy(dev->data_requests);
if (dev->stp_requests) {
if (dev->ep[UDC_EP0OUT_IDX].td_stp) {
pci_pool_free(dev->stp_requests,
dev->ep[UDC_EP0OUT_IDX].td_stp,
dev->ep[UDC_EP0OUT_IDX].td_stp_phys);
}
if (dev->ep[UDC_EP0OUT_IDX].td_data) {
pci_pool_free(dev->stp_requests,
dev->ep[UDC_EP0OUT_IDX].td_data,
dev->ep[UDC_EP0OUT_IDX].td_data_phys);
}
pci_pool_destroy(dev->stp_requests);
}
if (dev->dma_addr)
dma_unmap_single(&dev->pdev->dev, dev->dma_addr,
UDC_EP0OUT_BUFF_SIZE * 4, DMA_FROM_DEVICE);
kfree(dev->ep0out_buf);
pch_vbus_gpio_free(dev);
pch_udc_exit(dev);
if (dev->irq_registered)
free_irq(pdev->irq, dev);
if (dev->base_addr)
iounmap(dev->base_addr);
if (dev->mem_region)
release_mem_region(dev->phys_addr,
pci_resource_len(pdev, dev->bar));
if (dev->active)
pci_disable_device(pdev);
kfree(dev);
}
static int pch_udc_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct pch_udc_dev *dev = pci_get_drvdata(pdev);
pch_udc_disable_interrupts(dev, UDC_DEVINT_MSK);
pch_udc_disable_ep_interrupts(dev, UDC_EPINT_MSK_DISABLE_ALL);
pci_disable_device(pdev);
pci_enable_wake(pdev, PCI_D3hot, 0);
if (pci_save_state(pdev)) {
dev_err(&pdev->dev,
"%s: could not save PCI config state\n", __func__);
return -ENOMEM;
}
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int pch_udc_resume(struct pci_dev *pdev)
{
int ret;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "%s: pci_enable_device failed\n", __func__);
return ret;
}
pci_enable_wake(pdev, PCI_D3hot, 0);
return 0;
}
static int pch_udc_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned long resource;
unsigned long len;
int retval;
struct pch_udc_dev *dev;
dev = kzalloc(sizeof *dev, GFP_KERNEL);
if (!dev) {
pr_err("%s: no memory for device structure\n", __func__);
return -ENOMEM;
}
if (pci_enable_device(pdev) < 0) {
kfree(dev);
pr_err("%s: pci_enable_device failed\n", __func__);
return -ENODEV;
}
dev->active = 1;
pci_set_drvdata(pdev, dev);
if (id->device == PCI_DEVICE_ID_INTEL_QUARK_X1000_UDC)
dev->bar = PCH_UDC_PCI_BAR_QUARK_X1000;
else
dev->bar = PCH_UDC_PCI_BAR;
resource = pci_resource_start(pdev, dev->bar);
len = pci_resource_len(pdev, dev->bar);
if (!request_mem_region(resource, len, KBUILD_MODNAME)) {
dev_err(&pdev->dev, "%s: pci device used already\n", __func__);
retval = -EBUSY;
goto finished;
}
dev->phys_addr = resource;
dev->mem_region = 1;
dev->base_addr = ioremap_nocache(resource, len);
if (!dev->base_addr) {
pr_err("%s: device memory cannot be mapped\n", __func__);
retval = -ENOMEM;
goto finished;
}
if (!pdev->irq) {
dev_err(&pdev->dev, "%s: irq not set\n", __func__);
retval = -ENODEV;
goto finished;
}
if (pch_udc_pcd_init(dev)) {
retval = -ENODEV;
goto finished;
}
if (request_irq(pdev->irq, pch_udc_isr, IRQF_SHARED, KBUILD_MODNAME,
dev)) {
dev_err(&pdev->dev, "%s: request_irq(%d) fail\n", __func__,
pdev->irq);
retval = -ENODEV;
goto finished;
}
dev->irq = pdev->irq;
dev->irq_registered = 1;
pci_set_master(pdev);
pci_try_set_mwi(pdev);
spin_lock_init(&dev->lock);
dev->pdev = pdev;
dev->gadget.ops = &pch_udc_ops;
retval = init_dma_pools(dev);
if (retval)
goto finished;
dev->gadget.name = KBUILD_MODNAME;
dev->gadget.max_speed = USB_SPEED_HIGH;
pch_udc_set_disconnect(dev);
retval = usb_add_gadget_udc_release(&pdev->dev, &dev->gadget,
gadget_release);
if (retval)
goto finished;
return 0;
finished:
pch_udc_remove(pdev);
return retval;
}
