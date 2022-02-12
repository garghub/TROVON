static inline struct musb *dev_to_musb(struct device *dev)
{
return dev_get_drvdata(dev);
}
static int musb_ulpi_read(struct usb_phy *phy, u32 reg)
{
void __iomem *addr = phy->io_priv;
int i = 0;
u8 r;
u8 power;
int ret;
pm_runtime_get_sync(phy->io_dev);
power = musb_readb(addr, MUSB_POWER);
power &= ~MUSB_POWER_SUSPENDM;
musb_writeb(addr, MUSB_POWER, power);
musb_writeb(addr, MUSB_ULPI_REG_ADDR, (u8)reg);
musb_writeb(addr, MUSB_ULPI_REG_CONTROL,
MUSB_ULPI_REG_REQ | MUSB_ULPI_RDN_WR);
while (!(musb_readb(addr, MUSB_ULPI_REG_CONTROL)
& MUSB_ULPI_REG_CMPLT)) {
i++;
if (i == 10000) {
ret = -ETIMEDOUT;
goto out;
}
}
r = musb_readb(addr, MUSB_ULPI_REG_CONTROL);
r &= ~MUSB_ULPI_REG_CMPLT;
musb_writeb(addr, MUSB_ULPI_REG_CONTROL, r);
ret = musb_readb(addr, MUSB_ULPI_REG_DATA);
out:
pm_runtime_put(phy->io_dev);
return ret;
}
static int musb_ulpi_write(struct usb_phy *phy, u32 val, u32 reg)
{
void __iomem *addr = phy->io_priv;
int i = 0;
u8 r = 0;
u8 power;
int ret = 0;
pm_runtime_get_sync(phy->io_dev);
power = musb_readb(addr, MUSB_POWER);
power &= ~MUSB_POWER_SUSPENDM;
musb_writeb(addr, MUSB_POWER, power);
musb_writeb(addr, MUSB_ULPI_REG_ADDR, (u8)reg);
musb_writeb(addr, MUSB_ULPI_REG_DATA, (u8)val);
musb_writeb(addr, MUSB_ULPI_REG_CONTROL, MUSB_ULPI_REG_REQ);
while (!(musb_readb(addr, MUSB_ULPI_REG_CONTROL)
& MUSB_ULPI_REG_CMPLT)) {
i++;
if (i == 10000) {
ret = -ETIMEDOUT;
goto out;
}
}
r = musb_readb(addr, MUSB_ULPI_REG_CONTROL);
r &= ~MUSB_ULPI_REG_CMPLT;
musb_writeb(addr, MUSB_ULPI_REG_CONTROL, r);
out:
pm_runtime_put(phy->io_dev);
return ret;
}
static u32 musb_default_fifo_offset(u8 epnum)
{
return 0x20 + (epnum * 4);
}
static void musb_flat_ep_select(void __iomem *mbase, u8 epnum)
{
}
static u32 musb_flat_ep_offset(u8 epnum, u16 offset)
{
return 0x100 + (0x10 * epnum) + offset;
}
static void musb_indexed_ep_select(void __iomem *mbase, u8 epnum)
{
musb_writeb(mbase, MUSB_INDEX, epnum);
}
static u32 musb_indexed_ep_offset(u8 epnum, u16 offset)
{
return 0x10 + offset;
}
static u32 musb_default_busctl_offset(u8 epnum, u16 offset)
{
return 0x80 + (0x08 * epnum) + offset;
}
static u8 musb_default_readb(const void __iomem *addr, unsigned offset)
{
u8 data = __raw_readb(addr + offset);
trace_musb_readb(__builtin_return_address(0), addr, offset, data);
return data;
}
static void musb_default_writeb(void __iomem *addr, unsigned offset, u8 data)
{
trace_musb_writeb(__builtin_return_address(0), addr, offset, data);
__raw_writeb(data, addr + offset);
}
static u16 musb_default_readw(const void __iomem *addr, unsigned offset)
{
u16 data = __raw_readw(addr + offset);
trace_musb_readw(__builtin_return_address(0), addr, offset, data);
return data;
}
static void musb_default_writew(void __iomem *addr, unsigned offset, u16 data)
{
trace_musb_writew(__builtin_return_address(0), addr, offset, data);
__raw_writew(data, addr + offset);
}
static u32 musb_default_readl(const void __iomem *addr, unsigned offset)
{
u32 data = __raw_readl(addr + offset);
trace_musb_readl(__builtin_return_address(0), addr, offset, data);
return data;
}
static void musb_default_writel(void __iomem *addr, unsigned offset, u32 data)
{
trace_musb_writel(__builtin_return_address(0), addr, offset, data);
__raw_writel(data, addr + offset);
}
static void musb_default_write_fifo(struct musb_hw_ep *hw_ep, u16 len,
const u8 *src)
{
struct musb *musb = hw_ep->musb;
void __iomem *fifo = hw_ep->fifo;
if (unlikely(len == 0))
return;
prefetch((u8 *)src);
dev_dbg(musb->controller, "%cX ep%d fifo %p count %d buf %p\n",
'T', hw_ep->epnum, fifo, len, src);
if (likely((0x01 & (unsigned long) src) == 0)) {
u16 index = 0;
if ((0x02 & (unsigned long) src) == 0) {
if (len >= 4) {
iowrite32_rep(fifo, src + index, len >> 2);
index += len & ~0x03;
}
if (len & 0x02) {
__raw_writew(*(u16 *)&src[index], fifo);
index += 2;
}
} else {
if (len >= 2) {
iowrite16_rep(fifo, src + index, len >> 1);
index += len & ~0x01;
}
}
if (len & 0x01)
__raw_writeb(src[index], fifo);
} else {
iowrite8_rep(fifo, src, len);
}
}
static void musb_default_read_fifo(struct musb_hw_ep *hw_ep, u16 len, u8 *dst)
{
struct musb *musb = hw_ep->musb;
void __iomem *fifo = hw_ep->fifo;
if (unlikely(len == 0))
return;
dev_dbg(musb->controller, "%cX ep%d fifo %p count %d buf %p\n",
'R', hw_ep->epnum, fifo, len, dst);
if (likely((0x01 & (unsigned long) dst) == 0)) {
u16 index = 0;
if ((0x02 & (unsigned long) dst) == 0) {
if (len >= 4) {
ioread32_rep(fifo, dst, len >> 2);
index = len & ~0x03;
}
if (len & 0x02) {
*(u16 *)&dst[index] = __raw_readw(fifo);
index += 2;
}
} else {
if (len >= 2) {
ioread16_rep(fifo, dst, len >> 1);
index = len & ~0x01;
}
}
if (len & 0x01)
dst[index] = __raw_readb(fifo);
} else {
ioread8_rep(fifo, dst, len);
}
}
void musb_read_fifo(struct musb_hw_ep *hw_ep, u16 len, u8 *dst)
{
return hw_ep->musb->io.read_fifo(hw_ep, len, dst);
}
void musb_write_fifo(struct musb_hw_ep *hw_ep, u16 len, const u8 *src)
{
return hw_ep->musb->io.write_fifo(hw_ep, len, src);
}
void musb_load_testpacket(struct musb *musb)
{
void __iomem *regs = musb->endpoints[0].regs;
musb_ep_select(musb->mregs, 0);
musb_write_fifo(musb->control_ep,
sizeof(musb_test_packet), musb_test_packet);
musb_writew(regs, MUSB_CSR0, MUSB_CSR0_TXPKTRDY);
}
static void musb_otg_timer_func(unsigned long data)
{
struct musb *musb = (struct musb *)data;
unsigned long flags;
spin_lock_irqsave(&musb->lock, flags);
switch (musb->xceiv->otg->state) {
case OTG_STATE_B_WAIT_ACON:
musb_dbg(musb,
"HNP: b_wait_acon timeout; back to b_peripheral");
musb_g_disconnect(musb);
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
musb->is_active = 0;
break;
case OTG_STATE_A_SUSPEND:
case OTG_STATE_A_WAIT_BCON:
musb_dbg(musb, "HNP: %s timeout",
usb_otg_state_string(musb->xceiv->otg->state));
musb_platform_set_vbus(musb, 0);
musb->xceiv->otg->state = OTG_STATE_A_WAIT_VFALL;
break;
default:
musb_dbg(musb, "HNP: Unhandled mode %s",
usb_otg_state_string(musb->xceiv->otg->state));
}
spin_unlock_irqrestore(&musb->lock, flags);
}
void musb_hnp_stop(struct musb *musb)
{
struct usb_hcd *hcd = musb->hcd;
void __iomem *mbase = musb->mregs;
u8 reg;
musb_dbg(musb, "HNP: stop from %s",
usb_otg_state_string(musb->xceiv->otg->state));
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_PERIPHERAL:
musb_g_disconnect(musb);
musb_dbg(musb, "HNP: back to %s",
usb_otg_state_string(musb->xceiv->otg->state));
break;
case OTG_STATE_B_HOST:
musb_dbg(musb, "HNP: Disabling HR");
if (hcd)
hcd->self.is_b_host = 0;
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
MUSB_DEV_MODE(musb);
reg = musb_readb(mbase, MUSB_POWER);
reg |= MUSB_POWER_SUSPENDM;
musb_writeb(mbase, MUSB_POWER, reg);
break;
default:
musb_dbg(musb, "HNP: Stopping in unknown state %s",
usb_otg_state_string(musb->xceiv->otg->state));
}
musb->port1_status &= ~(USB_PORT_STAT_C_CONNECTION << 16);
}
static irqreturn_t musb_stage0_irq(struct musb *musb, u8 int_usb,
u8 devctl)
{
irqreturn_t handled = IRQ_NONE;
musb_dbg(musb, "<== DevCtl=%02x, int_usb=0x%x", devctl, int_usb);
if (int_usb & MUSB_INTR_RESUME) {
handled = IRQ_HANDLED;
musb_dbg(musb, "RESUME (%s)",
usb_otg_state_string(musb->xceiv->otg->state));
if (devctl & MUSB_DEVCTL_HM) {
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_SUSPEND:
musb->port1_status |=
(USB_PORT_STAT_C_SUSPEND << 16)
| MUSB_PORT_STAT_RESUME;
musb->rh_timer = jiffies
+ msecs_to_jiffies(USB_RESUME_TIMEOUT);
musb->need_finish_resume = 1;
musb->xceiv->otg->state = OTG_STATE_A_HOST;
musb->is_active = 1;
musb_host_resume_root_hub(musb);
break;
case OTG_STATE_B_WAIT_ACON:
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
musb->is_active = 1;
MUSB_DEV_MODE(musb);
break;
default:
WARNING("bogus %s RESUME (%s)\n",
"host",
usb_otg_state_string(musb->xceiv->otg->state));
}
} else {
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_SUSPEND:
musb->xceiv->otg->state = OTG_STATE_A_HOST;
musb_host_resume_root_hub(musb);
break;
case OTG_STATE_B_WAIT_ACON:
case OTG_STATE_B_PERIPHERAL:
if ((devctl & MUSB_DEVCTL_VBUS)
!= (3 << MUSB_DEVCTL_VBUS_SHIFT)
) {
musb->int_usb |= MUSB_INTR_DISCONNECT;
musb->int_usb &= ~MUSB_INTR_SUSPEND;
break;
}
musb_g_resume(musb);
break;
case OTG_STATE_B_IDLE:
musb->int_usb &= ~MUSB_INTR_SUSPEND;
break;
default:
WARNING("bogus %s RESUME (%s)\n",
"peripheral",
usb_otg_state_string(musb->xceiv->otg->state));
}
}
}
if (int_usb & MUSB_INTR_SESSREQ) {
void __iomem *mbase = musb->mregs;
if ((devctl & MUSB_DEVCTL_VBUS) == MUSB_DEVCTL_VBUS
&& (devctl & MUSB_DEVCTL_BDEVICE)) {
musb_dbg(musb, "SessReq while on B state");
return IRQ_HANDLED;
}
musb_dbg(musb, "SESSION_REQUEST (%s)",
usb_otg_state_string(musb->xceiv->otg->state));
musb_writeb(mbase, MUSB_DEVCTL, MUSB_DEVCTL_SESSION);
musb->ep0_stage = MUSB_EP0_START;
musb->xceiv->otg->state = OTG_STATE_A_IDLE;
MUSB_HST_MODE(musb);
musb_platform_set_vbus(musb, 1);
handled = IRQ_HANDLED;
}
if (int_usb & MUSB_INTR_VBUSERROR) {
int ignore = 0;
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_HOST:
case OTG_STATE_A_WAIT_BCON:
case OTG_STATE_A_WAIT_VRISE:
if (musb->vbuserr_retry) {
void __iomem *mbase = musb->mregs;
musb->vbuserr_retry--;
ignore = 1;
devctl |= MUSB_DEVCTL_SESSION;
musb_writeb(mbase, MUSB_DEVCTL, devctl);
} else {
musb->port1_status |=
USB_PORT_STAT_OVERCURRENT
| (USB_PORT_STAT_C_OVERCURRENT << 16);
}
break;
default:
break;
}
dev_printk(ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
"VBUS_ERROR in %s (%02x, %s), retry #%d, port1 %08x\n",
usb_otg_state_string(musb->xceiv->otg->state),
devctl,
({ char *s;
switch (devctl & MUSB_DEVCTL_VBUS) {
case 0 << MUSB_DEVCTL_VBUS_SHIFT:
s = "<SessEnd"; break;
case 1 << MUSB_DEVCTL_VBUS_SHIFT:
s = "<AValid"; break;
case 2 << MUSB_DEVCTL_VBUS_SHIFT:
s = "<VBusValid"; break;
default:
s = "VALID"; break;
} s; }),
VBUSERR_RETRY_COUNT - musb->vbuserr_retry,
musb->port1_status);
if (!ignore)
musb_platform_set_vbus(musb, 0);
handled = IRQ_HANDLED;
}
if (int_usb & MUSB_INTR_SUSPEND) {
musb_dbg(musb, "SUSPEND (%s) devctl %02x",
usb_otg_state_string(musb->xceiv->otg->state), devctl);
handled = IRQ_HANDLED;
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_PERIPHERAL:
musb_hnp_stop(musb);
musb_host_resume_root_hub(musb);
musb_root_disconnect(musb);
musb_platform_try_idle(musb, jiffies
+ msecs_to_jiffies(musb->a_wait_bcon
? : OTG_TIME_A_WAIT_BCON));
break;
case OTG_STATE_B_IDLE:
if (!musb->is_active)
break;
case OTG_STATE_B_PERIPHERAL:
musb_g_suspend(musb);
musb->is_active = musb->g.b_hnp_enable;
if (musb->is_active) {
musb->xceiv->otg->state = OTG_STATE_B_WAIT_ACON;
musb_dbg(musb, "HNP: Setting timer for b_ase0_brst");
mod_timer(&musb->otg_timer, jiffies
+ msecs_to_jiffies(
OTG_TIME_B_ASE0_BRST));
}
break;
case OTG_STATE_A_WAIT_BCON:
if (musb->a_wait_bcon != 0)
musb_platform_try_idle(musb, jiffies
+ msecs_to_jiffies(musb->a_wait_bcon));
break;
case OTG_STATE_A_HOST:
musb->xceiv->otg->state = OTG_STATE_A_SUSPEND;
musb->is_active = musb->hcd->self.b_hnp_enable;
break;
case OTG_STATE_B_HOST:
musb_dbg(musb, "REVISIT: SUSPEND as B_HOST");
break;
default:
musb->is_active = 0;
break;
}
}
if (int_usb & MUSB_INTR_CONNECT) {
struct usb_hcd *hcd = musb->hcd;
handled = IRQ_HANDLED;
musb->is_active = 1;
musb->ep0_stage = MUSB_EP0_START;
musb->intrtxe = musb->epmask;
musb_writew(musb->mregs, MUSB_INTRTXE, musb->intrtxe);
musb->intrrxe = musb->epmask & 0xfffe;
musb_writew(musb->mregs, MUSB_INTRRXE, musb->intrrxe);
musb_writeb(musb->mregs, MUSB_INTRUSBE, 0xf7);
musb->port1_status &= ~(USB_PORT_STAT_LOW_SPEED
|USB_PORT_STAT_HIGH_SPEED
|USB_PORT_STAT_ENABLE
);
musb->port1_status |= USB_PORT_STAT_CONNECTION
|(USB_PORT_STAT_C_CONNECTION << 16);
if (devctl & MUSB_DEVCTL_LSDEV)
musb->port1_status |= USB_PORT_STAT_LOW_SPEED;
switch (musb->xceiv->otg->state) {
case OTG_STATE_B_PERIPHERAL:
if (int_usb & MUSB_INTR_SUSPEND) {
musb_dbg(musb, "HNP: SUSPEND+CONNECT, now b_host");
int_usb &= ~MUSB_INTR_SUSPEND;
goto b_host;
} else
musb_dbg(musb, "CONNECT as b_peripheral???");
break;
case OTG_STATE_B_WAIT_ACON:
musb_dbg(musb, "HNP: CONNECT, now b_host");
b_host:
musb->xceiv->otg->state = OTG_STATE_B_HOST;
if (musb->hcd)
musb->hcd->self.is_b_host = 1;
del_timer(&musb->otg_timer);
break;
default:
if ((devctl & MUSB_DEVCTL_VBUS)
== (3 << MUSB_DEVCTL_VBUS_SHIFT)) {
musb->xceiv->otg->state = OTG_STATE_A_HOST;
if (hcd)
hcd->self.is_b_host = 0;
}
break;
}
musb_host_poke_root_hub(musb);
musb_dbg(musb, "CONNECT (%s) devctl %02x",
usb_otg_state_string(musb->xceiv->otg->state), devctl);
}
if (int_usb & MUSB_INTR_DISCONNECT) {
musb_dbg(musb, "DISCONNECT (%s) as %s, devctl %02x",
usb_otg_state_string(musb->xceiv->otg->state),
MUSB_MODE(musb), devctl);
handled = IRQ_HANDLED;
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_HOST:
case OTG_STATE_A_SUSPEND:
musb_host_resume_root_hub(musb);
musb_root_disconnect(musb);
if (musb->a_wait_bcon != 0)
musb_platform_try_idle(musb, jiffies
+ msecs_to_jiffies(musb->a_wait_bcon));
break;
case OTG_STATE_B_HOST:
musb_root_disconnect(musb);
if (musb->hcd)
musb->hcd->self.is_b_host = 0;
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
MUSB_DEV_MODE(musb);
musb_g_disconnect(musb);
break;
case OTG_STATE_A_PERIPHERAL:
musb_hnp_stop(musb);
musb_root_disconnect(musb);
case OTG_STATE_B_WAIT_ACON:
case OTG_STATE_B_PERIPHERAL:
case OTG_STATE_B_IDLE:
musb_g_disconnect(musb);
break;
default:
WARNING("unhandled DISCONNECT transition (%s)\n",
usb_otg_state_string(musb->xceiv->otg->state));
break;
}
}
if (int_usb & MUSB_INTR_RESET) {
handled = IRQ_HANDLED;
if (devctl & MUSB_DEVCTL_HM) {
dev_err(musb->controller, "Babble\n");
if (is_host_active(musb))
musb_recover_from_babble(musb);
} else {
musb_dbg(musb, "BUS RESET as %s",
usb_otg_state_string(musb->xceiv->otg->state));
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_SUSPEND:
musb_g_reset(musb);
case OTG_STATE_A_WAIT_BCON:
musb_dbg(musb, "HNP: in %s, %d msec timeout",
usb_otg_state_string(musb->xceiv->otg->state),
TA_WAIT_BCON(musb));
mod_timer(&musb->otg_timer, jiffies
+ msecs_to_jiffies(TA_WAIT_BCON(musb)));
break;
case OTG_STATE_A_PERIPHERAL:
del_timer(&musb->otg_timer);
musb_g_reset(musb);
break;
case OTG_STATE_B_WAIT_ACON:
musb_dbg(musb, "HNP: RESET (%s), to b_peripheral",
usb_otg_state_string(musb->xceiv->otg->state));
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
musb_g_reset(musb);
break;
case OTG_STATE_B_IDLE:
musb->xceiv->otg->state = OTG_STATE_B_PERIPHERAL;
case OTG_STATE_B_PERIPHERAL:
musb_g_reset(musb);
break;
default:
musb_dbg(musb, "Unhandled BUS RESET as %s",
usb_otg_state_string(musb->xceiv->otg->state));
}
}
}
#if 0
if (int_usb & MUSB_INTR_SOF) {
void __iomem *mbase = musb->mregs;
struct musb_hw_ep *ep;
u8 epnum;
u16 frame;
dev_dbg(musb->controller, "START_OF_FRAME\n");
handled = IRQ_HANDLED;
frame = musb_readw(mbase, MUSB_FRAME);
ep = musb->endpoints;
for (epnum = 1; (epnum < musb->nr_endpoints)
&& (musb->epmask >= (1 << epnum));
epnum++, ep++) {
if (ep->dwWaitFrame >= frame) {
ep->dwWaitFrame = 0;
pr_debug("SOF --> periodic TX%s on %d\n",
ep->tx_channel ? " DMA" : "",
epnum);
if (!ep->tx_channel)
musb_h_tx_start(musb, epnum);
else
cppi_hostdma_start(musb, epnum);
}
}
}
#endif
schedule_delayed_work(&musb->irq_work, 0);
return handled;
}
static void musb_disable_interrupts(struct musb *musb)
{
void __iomem *mbase = musb->mregs;
u16 temp;
musb_writeb(mbase, MUSB_INTRUSBE, 0);
musb->intrtxe = 0;
musb_writew(mbase, MUSB_INTRTXE, 0);
musb->intrrxe = 0;
musb_writew(mbase, MUSB_INTRRXE, 0);
temp = musb_readb(mbase, MUSB_INTRUSB);
temp = musb_readw(mbase, MUSB_INTRTX);
temp = musb_readw(mbase, MUSB_INTRRX);
}
static void musb_enable_interrupts(struct musb *musb)
{
void __iomem *regs = musb->mregs;
musb->intrtxe = musb->epmask;
musb_writew(regs, MUSB_INTRTXE, musb->intrtxe);
musb->intrrxe = musb->epmask & 0xfffe;
musb_writew(regs, MUSB_INTRRXE, musb->intrrxe);
musb_writeb(regs, MUSB_INTRUSBE, 0xf7);
}
static void musb_generic_disable(struct musb *musb)
{
void __iomem *mbase = musb->mregs;
musb_disable_interrupts(musb);
musb_writeb(mbase, MUSB_DEVCTL, 0);
}
void musb_start(struct musb *musb)
{
void __iomem *regs = musb->mregs;
u8 devctl = musb_readb(regs, MUSB_DEVCTL);
u8 power;
musb_dbg(musb, "<== devctl %02x", devctl);
musb_enable_interrupts(musb);
musb_writeb(regs, MUSB_TESTMODE, 0);
power = MUSB_POWER_ISOUPDATE;
if (musb->config->maximum_speed == USB_SPEED_HIGH ||
musb->config->maximum_speed == USB_SPEED_UNKNOWN)
power |= MUSB_POWER_HSENAB;
musb_writeb(regs, MUSB_POWER, power);
musb->is_active = 0;
devctl = musb_readb(regs, MUSB_DEVCTL);
devctl &= ~MUSB_DEVCTL_SESSION;
if (musb->port_mode != MUSB_PORT_MODE_HOST &&
musb->xceiv->otg->state != OTG_STATE_A_WAIT_BCON &&
(devctl & MUSB_DEVCTL_VBUS) == MUSB_DEVCTL_VBUS) {
musb->is_active = 1;
} else {
devctl |= MUSB_DEVCTL_SESSION;
}
musb_platform_enable(musb);
musb_writeb(regs, MUSB_DEVCTL, devctl);
}
void musb_stop(struct musb *musb)
{
musb_platform_disable(musb);
musb_generic_disable(musb);
musb_dbg(musb, "HDRC disabled");
musb_platform_try_idle(musb, 0);
}
static int
fifo_setup(struct musb *musb, struct musb_hw_ep *hw_ep,
const struct musb_fifo_cfg *cfg, u16 offset)
{
void __iomem *mbase = musb->mregs;
int size = 0;
u16 maxpacket = cfg->maxpacket;
u16 c_off = offset >> 3;
u8 c_size;
size = ffs(max(maxpacket, (u16) 8)) - 1;
maxpacket = 1 << size;
c_size = size - 3;
if (cfg->mode == BUF_DOUBLE) {
if ((offset + (maxpacket << 1)) >
(1 << (musb->config->ram_bits + 2)))
return -EMSGSIZE;
c_size |= MUSB_FIFOSZ_DPB;
} else {
if ((offset + maxpacket) > (1 << (musb->config->ram_bits + 2)))
return -EMSGSIZE;
}
musb_writeb(mbase, MUSB_INDEX, hw_ep->epnum);
if (hw_ep->epnum == 1)
musb->bulk_ep = hw_ep;
switch (cfg->style) {
case FIFO_TX:
musb_write_txfifosz(mbase, c_size);
musb_write_txfifoadd(mbase, c_off);
hw_ep->tx_double_buffered = !!(c_size & MUSB_FIFOSZ_DPB);
hw_ep->max_packet_sz_tx = maxpacket;
break;
case FIFO_RX:
musb_write_rxfifosz(mbase, c_size);
musb_write_rxfifoadd(mbase, c_off);
hw_ep->rx_double_buffered = !!(c_size & MUSB_FIFOSZ_DPB);
hw_ep->max_packet_sz_rx = maxpacket;
break;
case FIFO_RXTX:
musb_write_txfifosz(mbase, c_size);
musb_write_txfifoadd(mbase, c_off);
hw_ep->rx_double_buffered = !!(c_size & MUSB_FIFOSZ_DPB);
hw_ep->max_packet_sz_rx = maxpacket;
musb_write_rxfifosz(mbase, c_size);
musb_write_rxfifoadd(mbase, c_off);
hw_ep->tx_double_buffered = hw_ep->rx_double_buffered;
hw_ep->max_packet_sz_tx = maxpacket;
hw_ep->is_shared_fifo = true;
break;
}
musb->epmask |= (1 << hw_ep->epnum);
return offset + (maxpacket << ((c_size & MUSB_FIFOSZ_DPB) ? 1 : 0));
}
static int ep_config_from_table(struct musb *musb)
{
const struct musb_fifo_cfg *cfg;
unsigned i, n;
int offset;
struct musb_hw_ep *hw_ep = musb->endpoints;
if (musb->config->fifo_cfg) {
cfg = musb->config->fifo_cfg;
n = musb->config->fifo_cfg_size;
goto done;
}
switch (fifo_mode) {
default:
fifo_mode = 0;
case 0:
cfg = mode_0_cfg;
n = ARRAY_SIZE(mode_0_cfg);
break;
case 1:
cfg = mode_1_cfg;
n = ARRAY_SIZE(mode_1_cfg);
break;
case 2:
cfg = mode_2_cfg;
n = ARRAY_SIZE(mode_2_cfg);
break;
case 3:
cfg = mode_3_cfg;
n = ARRAY_SIZE(mode_3_cfg);
break;
case 4:
cfg = mode_4_cfg;
n = ARRAY_SIZE(mode_4_cfg);
break;
case 5:
cfg = mode_5_cfg;
n = ARRAY_SIZE(mode_5_cfg);
break;
}
pr_debug("%s: setup fifo_mode %d\n", musb_driver_name, fifo_mode);
done:
offset = fifo_setup(musb, hw_ep, &ep0_cfg, 0);
for (i = 0; i < n; i++) {
u8 epn = cfg->hw_ep_num;
if (epn >= musb->config->num_eps) {
pr_debug("%s: invalid ep %d\n",
musb_driver_name, epn);
return -EINVAL;
}
offset = fifo_setup(musb, hw_ep + epn, cfg++, offset);
if (offset < 0) {
pr_debug("%s: mem overrun, ep %d\n",
musb_driver_name, epn);
return offset;
}
epn++;
musb->nr_endpoints = max(epn, musb->nr_endpoints);
}
pr_debug("%s: %d/%d max ep, %d/%d memory\n",
musb_driver_name,
n + 1, musb->config->num_eps * 2 - 1,
offset, (1 << (musb->config->ram_bits + 2)));
if (!musb->bulk_ep) {
pr_debug("%s: missing bulk\n", musb_driver_name);
return -EINVAL;
}
return 0;
}
static int ep_config_from_hw(struct musb *musb)
{
u8 epnum = 0;
struct musb_hw_ep *hw_ep;
void __iomem *mbase = musb->mregs;
int ret = 0;
musb_dbg(musb, "<== static silicon ep config");
for (epnum = 1; epnum < musb->config->num_eps; epnum++) {
musb_ep_select(mbase, epnum);
hw_ep = musb->endpoints + epnum;
ret = musb_read_fifosize(musb, hw_ep, epnum);
if (ret < 0)
break;
if (hw_ep->max_packet_sz_tx < 512
|| hw_ep->max_packet_sz_rx < 512)
continue;
if (musb->bulk_ep)
continue;
musb->bulk_ep = hw_ep;
}
if (!musb->bulk_ep) {
pr_debug("%s: missing bulk\n", musb_driver_name);
return -EINVAL;
}
return 0;
}
static int musb_core_init(u16 musb_type, struct musb *musb)
{
u8 reg;
char *type;
char aInfo[90];
void __iomem *mbase = musb->mregs;
int status = 0;
int i;
reg = musb_read_configdata(mbase);
strcpy(aInfo, (reg & MUSB_CONFIGDATA_UTMIDW) ? "UTMI-16" : "UTMI-8");
if (reg & MUSB_CONFIGDATA_DYNFIFO) {
strcat(aInfo, ", dyn FIFOs");
musb->dyn_fifo = true;
}
if (reg & MUSB_CONFIGDATA_MPRXE) {
strcat(aInfo, ", bulk combine");
musb->bulk_combine = true;
}
if (reg & MUSB_CONFIGDATA_MPTXE) {
strcat(aInfo, ", bulk split");
musb->bulk_split = true;
}
if (reg & MUSB_CONFIGDATA_HBRXE) {
strcat(aInfo, ", HB-ISO Rx");
musb->hb_iso_rx = true;
}
if (reg & MUSB_CONFIGDATA_HBTXE) {
strcat(aInfo, ", HB-ISO Tx");
musb->hb_iso_tx = true;
}
if (reg & MUSB_CONFIGDATA_SOFTCONE)
strcat(aInfo, ", SoftConn");
pr_debug("%s: ConfigData=0x%02x (%s)\n", musb_driver_name, reg, aInfo);
if (MUSB_CONTROLLER_MHDRC == musb_type) {
musb->is_multipoint = 1;
type = "M";
} else {
musb->is_multipoint = 0;
type = "";
#ifndef CONFIG_USB_OTG_BLACKLIST_HUB
pr_err("%s: kernel must blacklist external hubs\n",
musb_driver_name);
#endif
}
musb->hwvers = musb_read_hwvers(mbase);
pr_debug("%s: %sHDRC RTL version %d.%d%s\n",
musb_driver_name, type, MUSB_HWVERS_MAJOR(musb->hwvers),
MUSB_HWVERS_MINOR(musb->hwvers),
(musb->hwvers & MUSB_HWVERS_RC) ? "RC" : "");
musb_configure_ep0(musb);
musb->nr_endpoints = 1;
musb->epmask = 1;
if (musb->dyn_fifo)
status = ep_config_from_table(musb);
else
status = ep_config_from_hw(musb);
if (status < 0)
return status;
for (i = 0; i < musb->nr_endpoints; i++) {
struct musb_hw_ep *hw_ep = musb->endpoints + i;
hw_ep->fifo = musb->io.fifo_offset(i) + mbase;
#if IS_ENABLED(CONFIG_USB_MUSB_TUSB6010)
if (musb->io.quirks & MUSB_IN_TUSB) {
hw_ep->fifo_async = musb->async + 0x400 +
musb->io.fifo_offset(i);
hw_ep->fifo_sync = musb->sync + 0x400 +
musb->io.fifo_offset(i);
hw_ep->fifo_sync_va =
musb->sync_va + 0x400 + musb->io.fifo_offset(i);
if (i == 0)
hw_ep->conf = mbase - 0x400 + TUSB_EP0_CONF;
else
hw_ep->conf = mbase + 0x400 +
(((i - 1) & 0xf) << 2);
}
#endif
hw_ep->regs = musb->io.ep_offset(i, 0) + mbase;
hw_ep->rx_reinit = 1;
hw_ep->tx_reinit = 1;
if (hw_ep->max_packet_sz_tx) {
musb_dbg(musb, "%s: hw_ep %d%s, %smax %d",
musb_driver_name, i,
hw_ep->is_shared_fifo ? "shared" : "tx",
hw_ep->tx_double_buffered
? "doublebuffer, " : "",
hw_ep->max_packet_sz_tx);
}
if (hw_ep->max_packet_sz_rx && !hw_ep->is_shared_fifo) {
musb_dbg(musb, "%s: hw_ep %d%s, %smax %d",
musb_driver_name, i,
"rx",
hw_ep->rx_double_buffered
? "doublebuffer, " : "",
hw_ep->max_packet_sz_rx);
}
if (!(hw_ep->max_packet_sz_tx || hw_ep->max_packet_sz_rx))
musb_dbg(musb, "hw_ep %d not configured", i);
}
return 0;
}
irqreturn_t musb_interrupt(struct musb *musb)
{
irqreturn_t retval = IRQ_NONE;
unsigned long status;
unsigned long epnum;
u8 devctl;
if (!musb->int_usb && !musb->int_tx && !musb->int_rx)
return IRQ_NONE;
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
trace_musb_isr(musb);
if (musb->int_usb)
retval |= musb_stage0_irq(musb, musb->int_usb, devctl);
if (musb->int_tx & 1) {
if (is_host_active(musb))
retval |= musb_h_ep0_irq(musb);
else
retval |= musb_g_ep0_irq(musb);
musb->int_tx &= ~BIT(0);
}
status = musb->int_tx;
for_each_set_bit(epnum, &status, 16) {
retval = IRQ_HANDLED;
if (is_host_active(musb))
musb_host_tx(musb, epnum);
else
musb_g_tx(musb, epnum);
}
status = musb->int_rx;
for_each_set_bit(epnum, &status, 16) {
retval = IRQ_HANDLED;
if (is_host_active(musb))
musb_host_rx(musb, epnum);
else
musb_g_rx(musb, epnum);
}
return retval;
}
void musb_dma_completion(struct musb *musb, u8 epnum, u8 transmit)
{
if (!epnum) {
if (!is_cppi_enabled(musb)) {
if (is_host_active(musb))
musb_h_ep0_irq(musb);
else
musb_g_ep0_irq(musb);
}
} else {
if (transmit) {
if (is_host_active(musb))
musb_host_tx(musb, epnum);
else
musb_g_tx(musb, epnum);
} else {
if (is_host_active(musb))
musb_host_rx(musb, epnum);
else
musb_g_rx(musb, epnum);
}
}
}
int musb_mailbox(enum musb_vbus_id_status status)
{
if (musb_phy_callback)
return musb_phy_callback(status);
return -ENODEV;
}
static ssize_t
musb_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
int ret = -EINVAL;
spin_lock_irqsave(&musb->lock, flags);
ret = sprintf(buf, "%s\n", usb_otg_state_string(musb->xceiv->otg->state));
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static ssize_t
musb_mode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
int status;
spin_lock_irqsave(&musb->lock, flags);
if (sysfs_streq(buf, "host"))
status = musb_platform_set_mode(musb, MUSB_HOST);
else if (sysfs_streq(buf, "peripheral"))
status = musb_platform_set_mode(musb, MUSB_PERIPHERAL);
else if (sysfs_streq(buf, "otg"))
status = musb_platform_set_mode(musb, MUSB_OTG);
else
status = -EINVAL;
spin_unlock_irqrestore(&musb->lock, flags);
return (status == 0) ? n : status;
}
static ssize_t
musb_vbus_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
unsigned long val;
if (sscanf(buf, "%lu", &val) < 1) {
dev_err(dev, "Invalid VBUS timeout ms value\n");
return -EINVAL;
}
spin_lock_irqsave(&musb->lock, flags);
musb->a_wait_bcon = val ? max_t(int, val, OTG_TIME_A_WAIT_BCON) : 0 ;
if (musb->xceiv->otg->state == OTG_STATE_A_WAIT_BCON)
musb->is_active = 0;
musb_platform_try_idle(musb, jiffies + msecs_to_jiffies(val));
spin_unlock_irqrestore(&musb->lock, flags);
return n;
}
static ssize_t
musb_vbus_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
unsigned long val;
int vbus;
u8 devctl;
spin_lock_irqsave(&musb->lock, flags);
val = musb->a_wait_bcon;
vbus = musb_platform_get_vbus_status(musb);
if (vbus < 0) {
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if ((devctl & MUSB_DEVCTL_VBUS)
== (3 << MUSB_DEVCTL_VBUS_SHIFT))
vbus = 1;
else
vbus = 0;
}
spin_unlock_irqrestore(&musb->lock, flags);
return sprintf(buf, "Vbus %s, timeout %lu msec\n",
vbus ? "on" : "off", val);
}
static ssize_t
musb_srp_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t n)
{
struct musb *musb = dev_to_musb(dev);
unsigned short srp;
if (sscanf(buf, "%hu", &srp) != 1
|| (srp != 1)) {
dev_err(dev, "SRP: Value must be 1\n");
return -EINVAL;
}
if (srp == 1)
musb_g_wakeup(musb);
return n;
}
static void musb_pm_runtime_check_session(struct musb *musb)
{
u8 devctl, s;
int error;
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
s = MUSB_DEVCTL_FSDEV | MUSB_DEVCTL_LSDEV |
MUSB_DEVCTL_HR;
switch (devctl & ~s) {
case MUSB_QUIRK_B_INVALID_VBUS_91:
if (musb->quirk_retries--) {
musb_dbg(musb,
"Poll devctl on invalid vbus, assume no session");
schedule_delayed_work(&musb->irq_work,
msecs_to_jiffies(1000));
return;
}
case MUSB_QUIRK_A_DISCONNECT_19:
if (musb->quirk_retries--) {
musb_dbg(musb,
"Poll devctl on possible host mode disconnect");
schedule_delayed_work(&musb->irq_work,
msecs_to_jiffies(1000));
return;
}
if (!musb->session)
break;
musb_dbg(musb, "Allow PM on possible host mode disconnect");
pm_runtime_mark_last_busy(musb->controller);
pm_runtime_put_autosuspend(musb->controller);
musb->session = false;
return;
default:
break;
}
s = devctl & MUSB_DEVCTL_SESSION;
if (s == musb->session)
return;
if (s) {
musb_dbg(musb, "Block PM on active session: %02x", devctl);
error = pm_runtime_get_sync(musb->controller);
if (error < 0)
dev_err(musb->controller, "Could not enable: %i\n",
error);
musb->quirk_retries = 3;
} else {
musb_dbg(musb, "Allow PM with no session: %02x", devctl);
pm_runtime_mark_last_busy(musb->controller);
pm_runtime_put_autosuspend(musb->controller);
}
musb->session = s;
}
static void musb_irq_work(struct work_struct *data)
{
struct musb *musb = container_of(data, struct musb, irq_work.work);
musb_pm_runtime_check_session(musb);
if (musb->xceiv->otg->state != musb->xceiv_old_state) {
musb->xceiv_old_state = musb->xceiv->otg->state;
sysfs_notify(&musb->controller->kobj, NULL, "mode");
}
}
static void musb_recover_from_babble(struct musb *musb)
{
int ret;
u8 devctl;
musb_disable_interrupts(musb);
udelay(10);
ret = musb_platform_recover(musb);
if (ret) {
musb_enable_interrupts(musb);
return;
}
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
devctl &= ~MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, devctl);
musb_root_disconnect(musb);
if (musb->dyn_fifo)
ret = ep_config_from_table(musb);
else
ret = ep_config_from_hw(musb);
if (ret == 0)
musb_start(musb);
}
static struct musb *allocate_instance(struct device *dev,
const struct musb_hdrc_config *config, void __iomem *mbase)
{
struct musb *musb;
struct musb_hw_ep *ep;
int epnum;
int ret;
musb = devm_kzalloc(dev, sizeof(*musb), GFP_KERNEL);
if (!musb)
return NULL;
INIT_LIST_HEAD(&musb->control);
INIT_LIST_HEAD(&musb->in_bulk);
INIT_LIST_HEAD(&musb->out_bulk);
INIT_LIST_HEAD(&musb->pending_list);
musb->vbuserr_retry = VBUSERR_RETRY_COUNT;
musb->a_wait_bcon = OTG_TIME_A_WAIT_BCON;
musb->mregs = mbase;
musb->ctrl_base = mbase;
musb->nIrq = -ENODEV;
musb->config = config;
BUG_ON(musb->config->num_eps > MUSB_C_NUM_EPS);
for (epnum = 0, ep = musb->endpoints;
epnum < musb->config->num_eps;
epnum++, ep++) {
ep->musb = musb;
ep->epnum = epnum;
}
musb->controller = dev;
ret = musb_host_alloc(musb);
if (ret < 0)
goto err_free;
dev_set_drvdata(dev, musb);
return musb;
err_free:
return NULL;
}
static void musb_free(struct musb *musb)
{
#ifdef CONFIG_SYSFS
sysfs_remove_group(&musb->controller->kobj, &musb_attr_group);
#endif
if (musb->nIrq >= 0) {
if (musb->irq_wake)
disable_irq_wake(musb->nIrq);
free_irq(musb->nIrq, musb);
}
musb_host_free(musb);
}
static int musb_run_resume_work(struct musb *musb)
{
struct musb_pending_work *w, *_w;
unsigned long flags;
int error = 0;
spin_lock_irqsave(&musb->list_lock, flags);
list_for_each_entry_safe(w, _w, &musb->pending_list, node) {
if (w->callback) {
error = w->callback(musb, w->data);
if (error < 0) {
dev_err(musb->controller,
"resume callback %p failed: %i\n",
w->callback, error);
}
}
list_del(&w->node);
devm_kfree(musb->controller, w);
}
spin_unlock_irqrestore(&musb->list_lock, flags);
return error;
}
int musb_queue_resume_work(struct musb *musb,
int (*callback)(struct musb *musb, void *data),
void *data)
{
struct musb_pending_work *w;
unsigned long flags;
int error;
if (WARN_ON(!callback))
return -EINVAL;
if (pm_runtime_active(musb->controller))
return callback(musb, data);
w = devm_kzalloc(musb->controller, sizeof(*w), GFP_ATOMIC);
if (!w)
return -ENOMEM;
w->callback = callback;
w->data = data;
spin_lock_irqsave(&musb->list_lock, flags);
if (musb->is_runtime_suspended) {
list_add_tail(&w->node, &musb->pending_list);
error = 0;
} else {
dev_err(musb->controller, "could not add resume work %p\n",
callback);
devm_kfree(musb->controller, w);
error = -EINPROGRESS;
}
spin_unlock_irqrestore(&musb->list_lock, flags);
return error;
}
static void musb_deassert_reset(struct work_struct *work)
{
struct musb *musb;
unsigned long flags;
musb = container_of(work, struct musb, deassert_reset_work.work);
spin_lock_irqsave(&musb->lock, flags);
if (musb->port1_status & USB_PORT_STAT_RESET)
musb_port_reset(musb, false);
spin_unlock_irqrestore(&musb->lock, flags);
}
static int
musb_init_controller(struct device *dev, int nIrq, void __iomem *ctrl)
{
int status;
struct musb *musb;
struct musb_hdrc_platform_data *plat = dev_get_platdata(dev);
if (!plat) {
dev_err(dev, "no platform_data?\n");
status = -ENODEV;
goto fail0;
}
musb = allocate_instance(dev, plat->config, ctrl);
if (!musb) {
status = -ENOMEM;
goto fail0;
}
spin_lock_init(&musb->lock);
spin_lock_init(&musb->list_lock);
musb->board_set_power = plat->set_power;
musb->min_power = plat->min_power;
musb->ops = plat->platform_ops;
musb->port_mode = plat->mode;
musb_readb = musb_default_readb;
musb_writeb = musb_default_writeb;
musb_readw = musb_default_readw;
musb_writew = musb_default_writew;
musb_readl = musb_default_readl;
musb_writel = musb_default_writel;
status = musb_platform_init(musb);
if (status < 0)
goto fail1;
if (!musb->isr) {
status = -ENODEV;
goto fail2;
}
if (musb->ops->quirks)
musb->io.quirks = musb->ops->quirks;
if (musb->io.quirks & MUSB_INDEXED_EP) {
musb->io.ep_offset = musb_indexed_ep_offset;
musb->io.ep_select = musb_indexed_ep_select;
} else {
musb->io.ep_offset = musb_flat_ep_offset;
musb->io.ep_select = musb_flat_ep_select;
}
if (musb->ops->ep_offset)
musb->io.ep_offset = musb->ops->ep_offset;
if (musb->ops->ep_select)
musb->io.ep_select = musb->ops->ep_select;
if (musb->ops->fifo_mode)
fifo_mode = musb->ops->fifo_mode;
else
fifo_mode = 4;
if (musb->ops->fifo_offset)
musb->io.fifo_offset = musb->ops->fifo_offset;
else
musb->io.fifo_offset = musb_default_fifo_offset;
if (musb->ops->busctl_offset)
musb->io.busctl_offset = musb->ops->busctl_offset;
else
musb->io.busctl_offset = musb_default_busctl_offset;
if (musb->ops->readb)
musb_readb = musb->ops->readb;
if (musb->ops->writeb)
musb_writeb = musb->ops->writeb;
if (musb->ops->readw)
musb_readw = musb->ops->readw;
if (musb->ops->writew)
musb_writew = musb->ops->writew;
if (musb->ops->readl)
musb_readl = musb->ops->readl;
if (musb->ops->writel)
musb_writel = musb->ops->writel;
#ifndef CONFIG_MUSB_PIO_ONLY
if (!musb->ops->dma_init || !musb->ops->dma_exit) {
dev_err(dev, "DMA controller not set\n");
status = -ENODEV;
goto fail2;
}
musb_dma_controller_create = musb->ops->dma_init;
musb_dma_controller_destroy = musb->ops->dma_exit;
#endif
if (musb->ops->read_fifo)
musb->io.read_fifo = musb->ops->read_fifo;
else
musb->io.read_fifo = musb_default_read_fifo;
if (musb->ops->write_fifo)
musb->io.write_fifo = musb->ops->write_fifo;
else
musb->io.write_fifo = musb_default_write_fifo;
if (!musb->xceiv->io_ops) {
musb->xceiv->io_dev = musb->controller;
musb->xceiv->io_priv = musb->mregs;
musb->xceiv->io_ops = &musb_ulpi_access;
}
if (musb->ops->phy_callback)
musb_phy_callback = musb->ops->phy_callback;
pm_runtime_use_autosuspend(musb->controller);
pm_runtime_set_autosuspend_delay(musb->controller, 500);
pm_runtime_enable(musb->controller);
pm_runtime_get_sync(musb->controller);
status = usb_phy_init(musb->xceiv);
if (status < 0)
goto err_usb_phy_init;
if (use_dma && dev->dma_mask) {
musb->dma_controller =
musb_dma_controller_create(musb, musb->mregs);
if (IS_ERR(musb->dma_controller)) {
status = PTR_ERR(musb->dma_controller);
goto fail2_5;
}
}
musb_platform_disable(musb);
musb_generic_disable(musb);
INIT_DELAYED_WORK(&musb->irq_work, musb_irq_work);
INIT_DELAYED_WORK(&musb->deassert_reset_work, musb_deassert_reset);
INIT_DELAYED_WORK(&musb->finish_resume_work, musb_host_finish_resume);
status = musb_core_init(plat->config->multipoint
? MUSB_CONTROLLER_MHDRC
: MUSB_CONTROLLER_HDRC, musb);
if (status < 0)
goto fail3;
setup_timer(&musb->otg_timer, musb_otg_timer_func, (unsigned long) musb);
if (request_irq(nIrq, musb->isr, 0, dev_name(dev), musb)) {
dev_err(dev, "request_irq %d failed!\n", nIrq);
status = -ENODEV;
goto fail3;
}
musb->nIrq = nIrq;
if (enable_irq_wake(nIrq) == 0) {
musb->irq_wake = 1;
device_init_wakeup(dev, 1);
} else {
musb->irq_wake = 0;
}
if (plat->extvbus) {
u8 busctl = musb_read_ulpi_buscontrol(musb->mregs);
busctl |= MUSB_ULPI_USE_EXTVBUS;
musb_write_ulpi_buscontrol(musb->mregs, busctl);
}
if (musb->xceiv->otg->default_a) {
MUSB_HST_MODE(musb);
musb->xceiv->otg->state = OTG_STATE_A_IDLE;
} else {
MUSB_DEV_MODE(musb);
musb->xceiv->otg->state = OTG_STATE_B_IDLE;
}
switch (musb->port_mode) {
case MUSB_PORT_MODE_HOST:
status = musb_host_setup(musb, plat->power);
if (status < 0)
goto fail3;
status = musb_platform_set_mode(musb, MUSB_HOST);
break;
case MUSB_PORT_MODE_GADGET:
status = musb_gadget_setup(musb);
if (status < 0)
goto fail3;
status = musb_platform_set_mode(musb, MUSB_PERIPHERAL);
break;
case MUSB_PORT_MODE_DUAL_ROLE:
status = musb_host_setup(musb, plat->power);
if (status < 0)
goto fail3;
status = musb_gadget_setup(musb);
if (status) {
musb_host_cleanup(musb);
goto fail3;
}
status = musb_platform_set_mode(musb, MUSB_OTG);
break;
default:
dev_err(dev, "unsupported port mode %d\n", musb->port_mode);
break;
}
if (status < 0)
goto fail3;
status = musb_init_debugfs(musb);
if (status < 0)
goto fail4;
status = sysfs_create_group(&musb->controller->kobj, &musb_attr_group);
if (status)
goto fail5;
musb->is_initialized = 1;
pm_runtime_mark_last_busy(musb->controller);
pm_runtime_put_autosuspend(musb->controller);
return 0;
fail5:
musb_exit_debugfs(musb);
fail4:
musb_gadget_cleanup(musb);
musb_host_cleanup(musb);
fail3:
cancel_delayed_work_sync(&musb->irq_work);
cancel_delayed_work_sync(&musb->finish_resume_work);
cancel_delayed_work_sync(&musb->deassert_reset_work);
if (musb->dma_controller)
musb_dma_controller_destroy(musb->dma_controller);
fail2_5:
usb_phy_shutdown(musb->xceiv);
err_usb_phy_init:
pm_runtime_dont_use_autosuspend(musb->controller);
pm_runtime_put_sync(musb->controller);
pm_runtime_disable(musb->controller);
fail2:
if (musb->irq_wake)
device_init_wakeup(dev, 0);
musb_platform_exit(musb);
fail1:
dev_err(musb->controller,
"musb_init_controller failed with status %d\n", status);
musb_free(musb);
fail0:
return status;
}
static int musb_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int irq = platform_get_irq_byname(pdev, "mc");
struct resource *iomem;
void __iomem *base;
if (irq <= 0)
return -ENODEV;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, iomem);
if (IS_ERR(base))
return PTR_ERR(base);
return musb_init_controller(dev, irq, base);
}
static int musb_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
musb_exit_debugfs(musb);
cancel_delayed_work_sync(&musb->irq_work);
cancel_delayed_work_sync(&musb->finish_resume_work);
cancel_delayed_work_sync(&musb->deassert_reset_work);
pm_runtime_get_sync(musb->controller);
musb_host_cleanup(musb);
musb_gadget_cleanup(musb);
spin_lock_irqsave(&musb->lock, flags);
musb_platform_disable(musb);
musb_generic_disable(musb);
spin_unlock_irqrestore(&musb->lock, flags);
musb_writeb(musb->mregs, MUSB_DEVCTL, 0);
pm_runtime_dont_use_autosuspend(musb->controller);
pm_runtime_put_sync(musb->controller);
pm_runtime_disable(musb->controller);
musb_platform_exit(musb);
musb_phy_callback = NULL;
if (musb->dma_controller)
musb_dma_controller_destroy(musb->dma_controller);
usb_phy_shutdown(musb->xceiv);
musb_free(musb);
device_init_wakeup(dev, 0);
return 0;
}
static void musb_save_context(struct musb *musb)
{
int i;
void __iomem *musb_base = musb->mregs;
void __iomem *epio;
musb->context.frame = musb_readw(musb_base, MUSB_FRAME);
musb->context.testmode = musb_readb(musb_base, MUSB_TESTMODE);
musb->context.busctl = musb_read_ulpi_buscontrol(musb->mregs);
musb->context.power = musb_readb(musb_base, MUSB_POWER);
musb->context.intrusbe = musb_readb(musb_base, MUSB_INTRUSBE);
musb->context.index = musb_readb(musb_base, MUSB_INDEX);
musb->context.devctl = musb_readb(musb_base, MUSB_DEVCTL);
for (i = 0; i < musb->config->num_eps; ++i) {
struct musb_hw_ep *hw_ep;
hw_ep = &musb->endpoints[i];
if (!hw_ep)
continue;
epio = hw_ep->regs;
if (!epio)
continue;
musb_writeb(musb_base, MUSB_INDEX, i);
musb->context.index_regs[i].txmaxp =
musb_readw(epio, MUSB_TXMAXP);
musb->context.index_regs[i].txcsr =
musb_readw(epio, MUSB_TXCSR);
musb->context.index_regs[i].rxmaxp =
musb_readw(epio, MUSB_RXMAXP);
musb->context.index_regs[i].rxcsr =
musb_readw(epio, MUSB_RXCSR);
if (musb->dyn_fifo) {
musb->context.index_regs[i].txfifoadd =
musb_read_txfifoadd(musb_base);
musb->context.index_regs[i].rxfifoadd =
musb_read_rxfifoadd(musb_base);
musb->context.index_regs[i].txfifosz =
musb_read_txfifosz(musb_base);
musb->context.index_regs[i].rxfifosz =
musb_read_rxfifosz(musb_base);
}
musb->context.index_regs[i].txtype =
musb_readb(epio, MUSB_TXTYPE);
musb->context.index_regs[i].txinterval =
musb_readb(epio, MUSB_TXINTERVAL);
musb->context.index_regs[i].rxtype =
musb_readb(epio, MUSB_RXTYPE);
musb->context.index_regs[i].rxinterval =
musb_readb(epio, MUSB_RXINTERVAL);
musb->context.index_regs[i].txfunaddr =
musb_read_txfunaddr(musb, i);
musb->context.index_regs[i].txhubaddr =
musb_read_txhubaddr(musb, i);
musb->context.index_regs[i].txhubport =
musb_read_txhubport(musb, i);
musb->context.index_regs[i].rxfunaddr =
musb_read_rxfunaddr(musb, i);
musb->context.index_regs[i].rxhubaddr =
musb_read_rxhubaddr(musb, i);
musb->context.index_regs[i].rxhubport =
musb_read_rxhubport(musb, i);
}
}
static void musb_restore_context(struct musb *musb)
{
int i;
void __iomem *musb_base = musb->mregs;
void __iomem *epio;
u8 power;
musb_writew(musb_base, MUSB_FRAME, musb->context.frame);
musb_writeb(musb_base, MUSB_TESTMODE, musb->context.testmode);
musb_write_ulpi_buscontrol(musb->mregs, musb->context.busctl);
power = musb_readb(musb_base, MUSB_POWER);
power &= MUSB_POWER_SUSPENDM | MUSB_POWER_RESUME;
musb->context.power &= ~(MUSB_POWER_SUSPENDM | MUSB_POWER_RESUME);
power |= musb->context.power;
musb_writeb(musb_base, MUSB_POWER, power);
musb_writew(musb_base, MUSB_INTRTXE, musb->intrtxe);
musb_writew(musb_base, MUSB_INTRRXE, musb->intrrxe);
musb_writeb(musb_base, MUSB_INTRUSBE, musb->context.intrusbe);
if (musb->context.devctl & MUSB_DEVCTL_SESSION)
musb_writeb(musb_base, MUSB_DEVCTL, musb->context.devctl);
for (i = 0; i < musb->config->num_eps; ++i) {
struct musb_hw_ep *hw_ep;
hw_ep = &musb->endpoints[i];
if (!hw_ep)
continue;
epio = hw_ep->regs;
if (!epio)
continue;
musb_writeb(musb_base, MUSB_INDEX, i);
musb_writew(epio, MUSB_TXMAXP,
musb->context.index_regs[i].txmaxp);
musb_writew(epio, MUSB_TXCSR,
musb->context.index_regs[i].txcsr);
musb_writew(epio, MUSB_RXMAXP,
musb->context.index_regs[i].rxmaxp);
musb_writew(epio, MUSB_RXCSR,
musb->context.index_regs[i].rxcsr);
if (musb->dyn_fifo) {
musb_write_txfifosz(musb_base,
musb->context.index_regs[i].txfifosz);
musb_write_rxfifosz(musb_base,
musb->context.index_regs[i].rxfifosz);
musb_write_txfifoadd(musb_base,
musb->context.index_regs[i].txfifoadd);
musb_write_rxfifoadd(musb_base,
musb->context.index_regs[i].rxfifoadd);
}
musb_writeb(epio, MUSB_TXTYPE,
musb->context.index_regs[i].txtype);
musb_writeb(epio, MUSB_TXINTERVAL,
musb->context.index_regs[i].txinterval);
musb_writeb(epio, MUSB_RXTYPE,
musb->context.index_regs[i].rxtype);
musb_writeb(epio, MUSB_RXINTERVAL,
musb->context.index_regs[i].rxinterval);
musb_write_txfunaddr(musb, i,
musb->context.index_regs[i].txfunaddr);
musb_write_txhubaddr(musb, i,
musb->context.index_regs[i].txhubaddr);
musb_write_txhubport(musb, i,
musb->context.index_regs[i].txhubport);
musb_write_rxfunaddr(musb, i,
musb->context.index_regs[i].rxfunaddr);
musb_write_rxhubaddr(musb, i,
musb->context.index_regs[i].rxhubaddr);
musb_write_rxhubport(musb, i,
musb->context.index_regs[i].rxhubport);
}
musb_writeb(musb_base, MUSB_INDEX, musb->context.index);
}
static int musb_suspend(struct device *dev)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
musb_platform_disable(musb);
musb_generic_disable(musb);
WARN_ON(!list_empty(&musb->pending_list));
spin_lock_irqsave(&musb->lock, flags);
if (is_peripheral_active(musb)) {
} else if (is_host_active(musb)) {
}
musb_save_context(musb);
spin_unlock_irqrestore(&musb->lock, flags);
return 0;
}
static int musb_resume(struct device *dev)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
int error;
u8 devctl;
u8 mask;
musb_restore_context(musb);
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
mask = MUSB_DEVCTL_BDEVICE | MUSB_DEVCTL_FSDEV | MUSB_DEVCTL_LSDEV;
if ((devctl & mask) != (musb->context.devctl & mask))
musb->port1_status = 0;
if (musb->need_finish_resume) {
musb->need_finish_resume = 0;
schedule_delayed_work(&musb->finish_resume_work,
msecs_to_jiffies(USB_RESUME_TIMEOUT));
}
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
musb_start(musb);
spin_lock_irqsave(&musb->lock, flags);
error = musb_run_resume_work(musb);
if (error)
dev_err(musb->controller, "resume work failed with %i\n",
error);
spin_unlock_irqrestore(&musb->lock, flags);
return 0;
}
static int musb_runtime_suspend(struct device *dev)
{
struct musb *musb = dev_to_musb(dev);
musb_save_context(musb);
musb->is_runtime_suspended = 1;
return 0;
}
static int musb_runtime_resume(struct device *dev)
{
struct musb *musb = dev_to_musb(dev);
unsigned long flags;
int error;
if (!musb->is_initialized)
return 0;
musb_restore_context(musb);
if (musb->need_finish_resume) {
musb->need_finish_resume = 0;
schedule_delayed_work(&musb->finish_resume_work,
msecs_to_jiffies(USB_RESUME_TIMEOUT));
}
spin_lock_irqsave(&musb->lock, flags);
error = musb_run_resume_work(musb);
if (error)
dev_err(musb->controller, "resume work failed with %i\n",
error);
musb->is_runtime_suspended = 0;
spin_unlock_irqrestore(&musb->lock, flags);
return 0;
}
