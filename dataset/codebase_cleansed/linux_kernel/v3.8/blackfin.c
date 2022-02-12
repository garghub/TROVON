void musb_write_fifo(struct musb_hw_ep *hw_ep, u16 len, const u8 *src)
{
struct musb *musb = hw_ep->musb;
void __iomem *fifo = hw_ep->fifo;
void __iomem *epio = hw_ep->regs;
u8 epnum = hw_ep->epnum;
prefetch((u8 *)src);
musb_writew(epio, MUSB_TXCOUNT, len);
dev_dbg(musb->controller, "TX ep%d fifo %p count %d buf %p, epio %p\n",
hw_ep->epnum, fifo, len, src, epio);
dump_fifo_data(src, len);
if (!ANOMALY_05000380 && epnum != 0) {
u16 dma_reg;
flush_dcache_range((unsigned long)src,
(unsigned long)(src + len));
dma_reg = (u32)src;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_ADDR_LOW), dma_reg);
SSYNC();
dma_reg = (u32)src >> 16;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_ADDR_HIGH), dma_reg);
SSYNC();
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_COUNT_LOW), len);
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_COUNT_HIGH), 0);
SSYNC();
dma_reg = (epnum << 4) | DMA_ENA | INT_ENA | DIRECTION;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_CTRL), dma_reg);
SSYNC();
while (!(bfin_read_USB_DMA_INTERRUPT() & (1 << epnum)))
cpu_relax();
bfin_write_USB_DMA_INTERRUPT(1 << epnum);
SSYNC();
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_CTRL), 0);
SSYNC();
} else {
SSYNC();
if (unlikely((unsigned long)src & 0x01))
outsw_8((unsigned long)fifo, src, (len + 1) >> 1);
else
outsw((unsigned long)fifo, src, (len + 1) >> 1);
}
}
void musb_read_fifo(struct musb_hw_ep *hw_ep, u16 len, u8 *dst)
{
struct musb *musb = hw_ep->musb;
void __iomem *fifo = hw_ep->fifo;
u8 epnum = hw_ep->epnum;
if (ANOMALY_05000467 && epnum != 0) {
u16 dma_reg;
invalidate_dcache_range((unsigned long)dst,
(unsigned long)(dst + len));
dma_reg = (u32)dst;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_ADDR_LOW), dma_reg);
SSYNC();
dma_reg = (u32)dst >> 16;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_ADDR_HIGH), dma_reg);
SSYNC();
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_COUNT_LOW), len);
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_COUNT_HIGH), 0);
SSYNC();
dma_reg = (epnum << 4) | DMA_ENA | INT_ENA;
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_CTRL), dma_reg);
SSYNC();
while (!(bfin_read_USB_DMA_INTERRUPT() & (1 << epnum)))
cpu_relax();
bfin_write_USB_DMA_INTERRUPT(1 << epnum);
SSYNC();
bfin_write16(USB_DMA_REG(epnum, USB_DMAx_CTRL), 0);
SSYNC();
} else {
SSYNC();
if (len == 1)
*dst = (u8)inw((unsigned long)fifo + 4);
else {
if (unlikely((unsigned long)dst & 0x01))
insw_8((unsigned long)fifo, dst, len >> 1);
else
insw((unsigned long)fifo, dst, len >> 1);
if (len & 0x01)
*(dst + len - 1) = (u8)inw((unsigned long)fifo + 4);
}
}
dev_dbg(musb->controller, "%cX ep%d fifo %p count %d buf %p\n",
'R', hw_ep->epnum, fifo, len, dst);
dump_fifo_data(dst, len);
}
static irqreturn_t blackfin_interrupt(int irq, void *__hci)
{
unsigned long flags;
irqreturn_t retval = IRQ_NONE;
struct musb *musb = __hci;
spin_lock_irqsave(&musb->lock, flags);
musb->int_usb = musb_readb(musb->mregs, MUSB_INTRUSB);
musb->int_tx = musb_readw(musb->mregs, MUSB_INTRTX);
musb->int_rx = musb_readw(musb->mregs, MUSB_INTRRX);
if (musb->int_usb || musb->int_tx || musb->int_rx) {
musb_writeb(musb->mregs, MUSB_INTRUSB, musb->int_usb);
musb_writew(musb->mregs, MUSB_INTRTX, musb->int_tx);
musb_writew(musb->mregs, MUSB_INTRRX, musb->int_rx);
retval = musb_interrupt(musb);
}
if ((musb->xceiv->state == OTG_STATE_B_IDLE
|| musb->xceiv->state == OTG_STATE_A_WAIT_BCON) ||
(musb->int_usb & MUSB_INTR_DISCONNECT && is_host_active(musb))) {
mod_timer(&musb_conn_timer, jiffies + TIMER_DELAY);
musb->a_wait_bcon = TIMER_DELAY;
}
spin_unlock_irqrestore(&musb->lock, flags);
return retval;
}
static void musb_conn_timer_handler(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
unsigned long flags;
u16 val;
static u8 toggle;
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->state) {
case OTG_STATE_A_IDLE:
case OTG_STATE_A_WAIT_BCON:
val = musb_readw(musb->mregs, MUSB_DEVCTL);
val &= ~MUSB_DEVCTL_SESSION;
musb_writew(musb->mregs, MUSB_DEVCTL, val);
val |= MUSB_DEVCTL_SESSION;
musb_writew(musb->mregs, MUSB_DEVCTL, val);
val = musb_readw(musb->mregs, MUSB_DEVCTL);
if (!(val & MUSB_DEVCTL_BDEVICE)) {
gpio_set_value(musb->config->gpio_vrsel, 1);
musb->xceiv->state = OTG_STATE_A_WAIT_BCON;
} else {
gpio_set_value(musb->config->gpio_vrsel, 0);
val = musb_readb(musb->mregs, MUSB_INTRUSBE);
val &= ~MUSB_INTR_VBUSERROR;
musb_writeb(musb->mregs, MUSB_INTRUSBE, val);
val = MUSB_INTR_SUSPEND | MUSB_INTR_VBUSERROR;
musb_writeb(musb->mregs, MUSB_INTRUSB, val);
musb->xceiv->state = OTG_STATE_B_IDLE;
}
mod_timer(&musb_conn_timer, jiffies + TIMER_DELAY);
break;
case OTG_STATE_B_IDLE:
val = musb_readw(musb->mregs, MUSB_DEVCTL);
val |= MUSB_DEVCTL_SESSION;
musb_writew(musb->mregs, MUSB_DEVCTL, val);
val = musb_readw(musb->mregs, MUSB_DEVCTL);
if (!(val & MUSB_DEVCTL_BDEVICE)) {
gpio_set_value(musb->config->gpio_vrsel, 1);
musb->xceiv->state = OTG_STATE_A_WAIT_BCON;
} else {
gpio_set_value(musb->config->gpio_vrsel, 0);
val = musb_readb(musb->mregs, MUSB_INTRUSBE);
val &= ~MUSB_INTR_VBUSERROR;
musb_writeb(musb->mregs, MUSB_INTRUSBE, val);
val = MUSB_INTR_SUSPEND | MUSB_INTR_VBUSERROR;
musb_writeb(musb->mregs, MUSB_INTRUSB, val);
if (toggle) {
val = musb_readb(musb->mregs, MUSB_POWER);
val &= ~MUSB_POWER_SOFTCONN;
musb_writeb(musb->mregs, MUSB_POWER, val);
toggle = 0;
} else {
val = musb_readb(musb->mregs, MUSB_POWER);
val |= MUSB_POWER_SOFTCONN;
musb_writeb(musb->mregs, MUSB_POWER, val);
toggle = 1;
}
mod_timer(&musb_conn_timer, jiffies + TIMER_DELAY / 4);
}
break;
default:
dev_dbg(musb->controller, "%s state not handled\n",
otg_state_string(musb->xceiv->state));
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
dev_dbg(musb->controller, "state is %s\n",
otg_state_string(musb->xceiv->state));
}
static void bfin_musb_enable(struct musb *musb)
{
}
static void bfin_musb_disable(struct musb *musb)
{
}
static void bfin_musb_set_vbus(struct musb *musb, int is_on)
{
int value = musb->config->gpio_vrsel_active;
if (!is_on)
value = !value;
gpio_set_value(musb->config->gpio_vrsel, value);
dev_dbg(musb->controller, "VBUS %s, devctl %02x "
"\n",
otg_state_string(musb->xceiv->state),
musb_readb(musb->mregs, MUSB_DEVCTL));
}
static int bfin_musb_set_power(struct usb_phy *x, unsigned mA)
{
return 0;
}
static int bfin_musb_vbus_status(struct musb *musb)
{
return 0;
}
static int bfin_musb_set_mode(struct musb *musb, u8 musb_mode)
{
return -EIO;
}
static int bfin_musb_adjust_channel_params(struct dma_channel *channel,
u16 packet_sz, u8 *mode,
dma_addr_t *dma_addr, u32 *len)
{
struct musb_dma_channel *musb_channel = channel->private_data;
if (ANOMALY_05000450) {
if (musb_channel->transmit && *mode == 1)
*len = *len - (*len % packet_sz);
}
return 0;
}
static void bfin_musb_reg_init(struct musb *musb)
{
if (ANOMALY_05000346) {
bfin_write_USB_APHY_CALIB(ANOMALY_05000346_value);
SSYNC();
}
if (ANOMALY_05000347) {
bfin_write_USB_APHY_CNTRL(0x0);
SSYNC();
}
bfin_write_USB_PLLOSC_CTRL(0x3080 |
((480/musb->config->clkin) << 1));
SSYNC();
bfin_write_USB_SRP_CLKDIV((get_sclk()/1000) / 32 - 1);
SSYNC();
bfin_write_USB_EP_NI0_RXMAXP(64);
SSYNC();
bfin_write_USB_EP_NI0_TXMAXP(64);
SSYNC();
bfin_write_USB_GLOBINTR(0x7);
SSYNC();
bfin_write_USB_GLOBAL_CTL(GLOBAL_ENA | EP1_TX_ENA | EP2_TX_ENA |
EP3_TX_ENA | EP4_TX_ENA | EP5_TX_ENA |
EP6_TX_ENA | EP7_TX_ENA | EP1_RX_ENA |
EP2_RX_ENA | EP3_RX_ENA | EP4_RX_ENA |
EP5_RX_ENA | EP6_RX_ENA | EP7_RX_ENA);
SSYNC();
}
static int bfin_musb_init(struct musb *musb)
{
if (gpio_request(musb->config->gpio_vrsel, "USB_VRSEL")) {
printk(KERN_ERR "Failed ro request USB_VRSEL GPIO_%d\n",
musb->config->gpio_vrsel);
return -ENODEV;
}
gpio_direction_output(musb->config->gpio_vrsel, 0);
usb_nop_xceiv_register();
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
gpio_free(musb->config->gpio_vrsel);
return -ENODEV;
}
bfin_musb_reg_init(musb);
setup_timer(&musb_conn_timer, musb_conn_timer_handler,
(unsigned long) musb);
musb->xceiv->set_power = bfin_musb_set_power;
musb->isr = blackfin_interrupt;
musb->double_buffer_not_ok = true;
return 0;
}
static int bfin_musb_exit(struct musb *musb)
{
gpio_free(musb->config->gpio_vrsel);
usb_put_phy(musb->xceiv);
usb_nop_xceiv_unregister();
return 0;
}
static int bfin_probe(struct platform_device *pdev)
{
struct musb_hdrc_platform_data *pdata = pdev->dev.platform_data;
struct platform_device *musb;
struct bfin_glue *glue;
int ret = -ENOMEM;
glue = kzalloc(sizeof(*glue), GFP_KERNEL);
if (!glue) {
dev_err(&pdev->dev, "failed to allocate glue context\n");
goto err0;
}
musb = platform_device_alloc("musb-hdrc", PLATFORM_DEVID_AUTO);
if (!musb) {
dev_err(&pdev->dev, "failed to allocate musb device\n");
goto err1;
}
musb->dev.parent = &pdev->dev;
musb->dev.dma_mask = &bfin_dmamask;
musb->dev.coherent_dma_mask = bfin_dmamask;
glue->dev = &pdev->dev;
glue->musb = musb;
pdata->platform_ops = &bfin_ops;
platform_set_drvdata(pdev, glue);
ret = platform_device_add_resources(musb, pdev->resource,
pdev->num_resources);
if (ret) {
dev_err(&pdev->dev, "failed to add resources\n");
goto err3;
}
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(&pdev->dev, "failed to add platform_data\n");
goto err3;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device\n");
goto err3;
}
return 0;
err3:
platform_device_put(musb);
err1:
kfree(glue);
err0:
return ret;
}
static int bfin_remove(struct platform_device *pdev)
{
struct bfin_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
kfree(glue);
return 0;
}
static int bfin_suspend(struct device *dev)
{
struct bfin_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
if (is_host_active(musb))
gpio_set_value(musb->config->gpio_vrsel, 0);
return 0;
}
static int bfin_resume(struct device *dev)
{
struct bfin_glue *glue = dev_get_drvdata(dev);
struct musb *musb = glue_to_musb(glue);
bfin_musb_reg_init(musb);
return 0;
}
