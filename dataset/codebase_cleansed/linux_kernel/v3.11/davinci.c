static inline void phy_on(void)
{
u32 phy_ctrl = __raw_readl(USB_PHY_CTRL);
phy_ctrl &= ~(USBPHY_OSCPDWN | USBPHY_OTGPDWN | USBPHY_PHYPDWN);
phy_ctrl |= USBPHY_SESNDEN | USBPHY_VBDTCTEN | USBPHY_PHYPLLON;
__raw_writel(phy_ctrl, USB_PHY_CTRL);
while ((__raw_readl(USB_PHY_CTRL) & USBPHY_PHYCLKGD) == 0)
cpu_relax();
}
static inline void phy_off(void)
{
u32 phy_ctrl = __raw_readl(USB_PHY_CTRL);
phy_ctrl &= ~(USBPHY_SESNDEN | USBPHY_VBDTCTEN | USBPHY_PHYPLLON);
phy_ctrl |= USBPHY_OSCPDWN | USBPHY_OTGPDWN | USBPHY_PHYPDWN;
__raw_writel(phy_ctrl, USB_PHY_CTRL);
}
static void davinci_musb_enable(struct musb *musb)
{
u32 tmp, old, val;
tmp = (musb->epmask & DAVINCI_USB_TX_ENDPTS_MASK)
<< DAVINCI_USB_TXINT_SHIFT;
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_MASK_SET_REG, tmp);
old = tmp;
tmp = (musb->epmask & (0xfffe & DAVINCI_USB_RX_ENDPTS_MASK))
<< DAVINCI_USB_RXINT_SHIFT;
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_MASK_SET_REG, tmp);
tmp |= old;
val = ~MUSB_INTR_SOF;
tmp |= ((val & 0x01ff) << DAVINCI_USB_USBINT_SHIFT);
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_MASK_SET_REG, tmp);
if (is_dma_capable() && !dma_off)
printk(KERN_WARNING "%s %s: dma not reactivated\n",
__FILE__, __func__);
else
dma_off = 0;
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_SET_REG,
DAVINCI_INTR_DRVVBUS << DAVINCI_USB_USBINT_SHIFT);
}
static void davinci_musb_disable(struct musb *musb)
{
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_MASK_CLR_REG,
DAVINCI_USB_USBINT_MASK
| DAVINCI_USB_TXINT_MASK
| DAVINCI_USB_RXINT_MASK);
musb_writeb(musb->mregs, MUSB_DEVCTL, 0);
musb_writel(musb->ctrl_base, DAVINCI_USB_EOI_REG, 0);
if (is_dma_capable() && !dma_off)
WARNING("dma still active\n");
}
static void evm_deferred_drvvbus(struct work_struct *ignored)
{
gpio_set_value_cansleep(GPIO_nVBUS_DRV, vbus_state);
vbus_state = !vbus_state;
}
static void davinci_musb_source_power(struct musb *musb, int is_on, int immediate)
{
#ifdef CONFIG_MACH_DAVINCI_EVM
if (is_on)
is_on = 1;
if (vbus_state == is_on)
return;
vbus_state = !is_on;
if (machine_is_davinci_evm()) {
static DECLARE_WORK(evm_vbus_work, evm_deferred_drvvbus);
if (immediate)
gpio_set_value_cansleep(GPIO_nVBUS_DRV, vbus_state);
else
schedule_work(&evm_vbus_work);
}
if (immediate)
vbus_state = is_on;
#endif
}
static void davinci_musb_set_vbus(struct musb *musb, int is_on)
{
WARN_ON(is_on && is_peripheral_active(musb));
davinci_musb_source_power(musb, is_on, 0);
}
static void otg_timer(unsigned long _musb)
{
struct musb *musb = (void *)_musb;
void __iomem *mregs = musb->mregs;
u8 devctl;
unsigned long flags;
devctl = musb_readb(mregs, MUSB_DEVCTL);
dev_dbg(musb->controller, "poll devctl %02x (%s)\n", devctl,
usb_otg_state_string(musb->xceiv->state));
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->state) {
case OTG_STATE_A_WAIT_VFALL:
if (devctl & MUSB_DEVCTL_VBUS) {
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
break;
}
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
musb_writel(musb->ctrl_base, DAVINCI_USB_INT_SET_REG,
MUSB_INTR_VBUSERROR << DAVINCI_USB_USBINT_SHIFT);
break;
case OTG_STATE_B_IDLE:
musb_writeb(mregs, MUSB_DEVCTL,
devctl | MUSB_DEVCTL_SESSION);
devctl = musb_readb(mregs, MUSB_DEVCTL);
if (devctl & MUSB_DEVCTL_BDEVICE)
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
else
musb->xceiv->state = OTG_STATE_A_IDLE;
break;
default:
break;
}
spin_unlock_irqrestore(&musb->lock, flags);
}
static irqreturn_t davinci_musb_interrupt(int irq, void *__hci)
{
unsigned long flags;
irqreturn_t retval = IRQ_NONE;
struct musb *musb = __hci;
struct usb_otg *otg = musb->xceiv->otg;
void __iomem *tibase = musb->ctrl_base;
struct cppi *cppi;
u32 tmp;
spin_lock_irqsave(&musb->lock, flags);
cppi = container_of(musb->dma_controller, struct cppi, controller);
if (is_cppi_enabled() && musb->dma_controller && !cppi->irq)
retval = cppi_interrupt(irq, __hci);
tmp = musb_readl(tibase, DAVINCI_USB_INT_SRC_MASKED_REG);
musb_writel(tibase, DAVINCI_USB_INT_SRC_CLR_REG, tmp);
dev_dbg(musb->controller, "IRQ %08x\n", tmp);
musb->int_rx = (tmp & DAVINCI_USB_RXINT_MASK)
>> DAVINCI_USB_RXINT_SHIFT;
musb->int_tx = (tmp & DAVINCI_USB_TXINT_MASK)
>> DAVINCI_USB_TXINT_SHIFT;
musb->int_usb = (tmp & DAVINCI_USB_USBINT_MASK)
>> DAVINCI_USB_USBINT_SHIFT;
if (tmp & (DAVINCI_INTR_DRVVBUS << DAVINCI_USB_USBINT_SHIFT)) {
int drvvbus = musb_readl(tibase, DAVINCI_USB_STAT_REG);
void __iomem *mregs = musb->mregs;
u8 devctl = musb_readb(mregs, MUSB_DEVCTL);
int err = musb->int_usb & MUSB_INTR_VBUSERROR;
err = musb->int_usb & MUSB_INTR_VBUSERROR;
if (err) {
musb->int_usb &= ~MUSB_INTR_VBUSERROR;
musb->xceiv->state = OTG_STATE_A_WAIT_VFALL;
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
WARNING("VBUS error workaround (delay coming)\n");
} else if (drvvbus) {
MUSB_HST_MODE(musb);
otg->default_a = 1;
musb->xceiv->state = OTG_STATE_A_WAIT_VRISE;
portstate(musb->port1_status |= USB_PORT_STAT_POWER);
del_timer(&otg_workaround);
} else {
musb->is_active = 0;
MUSB_DEV_MODE(musb);
otg->default_a = 0;
musb->xceiv->state = OTG_STATE_B_IDLE;
portstate(musb->port1_status &= ~USB_PORT_STAT_POWER);
}
davinci_musb_source_power(musb, drvvbus, 0);
dev_dbg(musb->controller, "VBUS %s (%s)%s, devctl %02x\n",
drvvbus ? "on" : "off",
usb_otg_state_string(musb->xceiv->state),
err ? " ERROR" : "",
devctl);
retval = IRQ_HANDLED;
}
if (musb->int_tx || musb->int_rx || musb->int_usb)
retval |= musb_interrupt(musb);
musb_writel(tibase, DAVINCI_USB_EOI_REG, 0);
if (musb->xceiv->state == OTG_STATE_B_IDLE)
mod_timer(&otg_workaround, jiffies + POLL_SECONDS * HZ);
spin_unlock_irqrestore(&musb->lock, flags);
return retval;
}
static int davinci_musb_set_mode(struct musb *musb, u8 mode)
{
return -EIO;
}
static int davinci_musb_init(struct musb *musb)
{
void __iomem *tibase = musb->ctrl_base;
u32 revision;
int ret = -ENODEV;
usb_nop_xceiv_register();
musb->xceiv = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR_OR_NULL(musb->xceiv)) {
ret = -EPROBE_DEFER;
goto unregister;
}
musb->mregs += DAVINCI_BASE_OFFSET;
revision = musb_readl(tibase, DAVINCI_USB_VERSION_REG);
if (revision == 0)
goto fail;
setup_timer(&otg_workaround, otg_timer, (unsigned long) musb);
davinci_musb_source_power(musb, 0, 1);
if (machine_is_davinci_dm355_evm()) {
u32 phy_ctrl = __raw_readl(USB_PHY_CTRL);
phy_ctrl &= ~(3 << 9);
phy_ctrl |= USBPHY_DATAPOL;
__raw_writel(phy_ctrl, USB_PHY_CTRL);
}
if (cpu_is_davinci_dm355()) {
u32 deepsleep = __raw_readl(DM355_DEEPSLEEP);
deepsleep &= ~DRVVBUS_FORCE;
__raw_writel(deepsleep, DM355_DEEPSLEEP);
}
musb_writel(tibase, DAVINCI_USB_CTRL_REG, 0x1);
phy_on();
msleep(5);
pr_debug("DaVinci OTG revision %08x phy %03x control %02x\n",
revision, __raw_readl(USB_PHY_CTRL),
musb_readb(tibase, DAVINCI_USB_CTRL_REG));
musb->isr = davinci_musb_interrupt;
return 0;
fail:
usb_put_phy(musb->xceiv);
unregister:
usb_nop_xceiv_unregister();
return ret;
}
static int davinci_musb_exit(struct musb *musb)
{
del_timer_sync(&otg_workaround);
if (cpu_is_davinci_dm355()) {
u32 deepsleep = __raw_readl(DM355_DEEPSLEEP);
deepsleep &= ~DRVVBUS_FORCE;
deepsleep |= DRVVBUS_OVERRIDE;
__raw_writel(deepsleep, DM355_DEEPSLEEP);
}
davinci_musb_source_power(musb, 0 , 1);
if (musb->xceiv->otg->default_a) {
int maxdelay = 30;
u8 devctl, warn = 0;
do {
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if (!(devctl & MUSB_DEVCTL_VBUS))
break;
if ((devctl & MUSB_DEVCTL_VBUS) != warn) {
warn = devctl & MUSB_DEVCTL_VBUS;
dev_dbg(musb->controller, "VBUS %d\n",
warn >> MUSB_DEVCTL_VBUS_SHIFT);
}
msleep(1000);
maxdelay--;
} while (maxdelay > 0);
if (devctl & MUSB_DEVCTL_VBUS)
dev_dbg(musb->controller, "VBUS off timeout (devctl %02x)\n", devctl);
}
phy_off();
usb_put_phy(musb->xceiv);
usb_nop_xceiv_unregister();
return 0;
}
static int davinci_probe(struct platform_device *pdev)
{
struct resource musb_resources[2];
struct musb_hdrc_platform_data *pdata = pdev->dev.platform_data;
struct platform_device *musb;
struct davinci_glue *glue;
struct clk *clk;
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
clk = clk_get(&pdev->dev, "usb");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
ret = PTR_ERR(clk);
goto err3;
}
ret = clk_enable(clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
goto err4;
}
musb->dev.parent = &pdev->dev;
musb->dev.dma_mask = &davinci_dmamask;
musb->dev.coherent_dma_mask = davinci_dmamask;
glue->dev = &pdev->dev;
glue->musb = musb;
glue->clk = clk;
pdata->platform_ops = &davinci_ops;
platform_set_drvdata(pdev, glue);
memset(musb_resources, 0x00, sizeof(*musb_resources) *
ARRAY_SIZE(musb_resources));
musb_resources[0].name = pdev->resource[0].name;
musb_resources[0].start = pdev->resource[0].start;
musb_resources[0].end = pdev->resource[0].end;
musb_resources[0].flags = pdev->resource[0].flags;
musb_resources[1].name = pdev->resource[1].name;
musb_resources[1].start = pdev->resource[1].start;
musb_resources[1].end = pdev->resource[1].end;
musb_resources[1].flags = pdev->resource[1].flags;
ret = platform_device_add_resources(musb, musb_resources,
ARRAY_SIZE(musb_resources));
if (ret) {
dev_err(&pdev->dev, "failed to add resources\n");
goto err5;
}
ret = platform_device_add_data(musb, pdata, sizeof(*pdata));
if (ret) {
dev_err(&pdev->dev, "failed to add platform_data\n");
goto err5;
}
ret = platform_device_add(musb);
if (ret) {
dev_err(&pdev->dev, "failed to register musb device\n");
goto err5;
}
return 0;
err5:
clk_disable(clk);
err4:
clk_put(clk);
err3:
platform_device_put(musb);
err1:
kfree(glue);
err0:
return ret;
}
static int davinci_remove(struct platform_device *pdev)
{
struct davinci_glue *glue = platform_get_drvdata(pdev);
platform_device_unregister(glue->musb);
clk_disable(glue->clk);
clk_put(glue->clk);
kfree(glue);
return 0;
}
