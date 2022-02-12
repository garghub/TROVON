static inline int tps65010_set_vbus_draw(unsigned mA)
{
pr_debug("tps65010: draw %d mA (STUB)\n", mA);
return 0;
}
static void enable_vbus_draw(struct isp1301 *isp, unsigned mA)
{
int status = tps65010_set_vbus_draw(mA);
if (status < 0)
pr_debug(" VBUS %d mA error %d\n", mA, status);
}
static void enable_vbus_draw(struct isp1301 *isp, unsigned mA)
{
}
static void enable_vbus_source(struct isp1301 *isp)
{
}
static inline void notresponding(struct isp1301 *isp)
{
printk(KERN_NOTICE "OTG device not responding.\n");
}
static inline u8
isp1301_get_u8(struct isp1301 *isp, u8 reg)
{
return i2c_smbus_read_byte_data(isp->client, reg + 0);
}
static inline int
isp1301_get_u16(struct isp1301 *isp, u8 reg)
{
return i2c_smbus_read_word_data(isp->client, reg);
}
static inline int
isp1301_set_bits(struct isp1301 *isp, u8 reg, u8 bits)
{
return i2c_smbus_write_byte_data(isp->client, reg + 0, bits);
}
static inline int
isp1301_clear_bits(struct isp1301 *isp, u8 reg, u8 bits)
{
return i2c_smbus_write_byte_data(isp->client, reg + 1, bits);
}
static inline const char *state_name(struct isp1301 *isp)
{
return usb_otg_state_string(isp->phy.state);
}
static void power_down(struct isp1301 *isp)
{
isp->phy.state = OTG_STATE_UNDEFINED;
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1, MC1_SUSPEND);
isp1301_clear_bits(isp, ISP1301_OTG_CONTROL_1, OTG1_ID_PULLDOWN);
isp1301_clear_bits(isp, ISP1301_MODE_CONTROL_1, MC1_DAT_SE0);
}
static void power_up(struct isp1301 *isp)
{
isp1301_clear_bits(isp, ISP1301_MODE_CONTROL_1, MC1_SUSPEND);
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1, MC1_DAT_SE0);
}
static int host_suspend(struct isp1301 *isp)
{
#ifdef NO_HOST_SUSPEND
return 0;
#else
struct device *dev;
if (!isp->phy.otg->host)
return -ENODEV;
dev = isp->phy.otg->host->controller;
return dev->driver->suspend(dev, 3, 0);
#endif
}
static int host_resume(struct isp1301 *isp)
{
#ifdef NO_HOST_SUSPEND
return 0;
#else
struct device *dev;
if (!isp->phy.otg->host)
return -ENODEV;
dev = isp->phy.otg->host->controller;
return dev->driver->resume(dev, 0);
#endif
}
static int gadget_suspend(struct isp1301 *isp)
{
isp->phy.otg->gadget->b_hnp_enable = 0;
isp->phy.otg->gadget->a_hnp_support = 0;
isp->phy.otg->gadget->a_alt_hnp_support = 0;
return usb_gadget_vbus_disconnect(isp->phy.otg->gadget);
}
static void isp1301_defer_work(struct isp1301 *isp, int work)
{
int status;
if (isp && !test_and_set_bit(work, &isp->todo)) {
(void) get_device(&isp->client->dev);
status = schedule_work(&isp->work);
if (!status && !isp->working)
dev_vdbg(&isp->client->dev,
"work item %d may be lost\n", work);
}
}
static void a_idle(struct isp1301 *isp, const char *tag)
{
u32 l;
if (isp->phy.state == OTG_STATE_A_IDLE)
return;
isp->phy.otg->default_a = 1;
if (isp->phy.otg->host) {
isp->phy.otg->host->is_b_host = 0;
host_suspend(isp);
}
if (isp->phy.otg->gadget) {
isp->phy.otg->gadget->is_a_peripheral = 1;
gadget_suspend(isp);
}
isp->phy.state = OTG_STATE_A_IDLE;
l = omap_readl(OTG_CTRL) & OTG_XCEIV_OUTPUTS;
omap_writel(l, OTG_CTRL);
isp->last_otg_ctrl = l;
pr_debug(" --> %s/%s\n", state_name(isp), tag);
}
static void b_idle(struct isp1301 *isp, const char *tag)
{
u32 l;
if (isp->phy.state == OTG_STATE_B_IDLE)
return;
isp->phy.otg->default_a = 0;
if (isp->phy.otg->host) {
isp->phy.otg->host->is_b_host = 1;
host_suspend(isp);
}
if (isp->phy.otg->gadget) {
isp->phy.otg->gadget->is_a_peripheral = 0;
gadget_suspend(isp);
}
isp->phy.state = OTG_STATE_B_IDLE;
l = omap_readl(OTG_CTRL) & OTG_XCEIV_OUTPUTS;
omap_writel(l, OTG_CTRL);
isp->last_otg_ctrl = l;
pr_debug(" --> %s/%s\n", state_name(isp), tag);
}
static void
dump_regs(struct isp1301 *isp, const char *label)
{
u8 ctrl = isp1301_get_u8(isp, ISP1301_OTG_CONTROL_1);
u8 status = isp1301_get_u8(isp, ISP1301_OTG_STATUS);
u8 src = isp1301_get_u8(isp, ISP1301_INTERRUPT_SOURCE);
pr_debug("otg: %06x, %s %s, otg/%02x stat/%02x.%02x\n",
omap_readl(OTG_CTRL), label, state_name(isp),
ctrl, status, src);
}
static void check_state(struct isp1301 *isp, const char *tag)
{
enum usb_otg_state state = OTG_STATE_UNDEFINED;
u8 fsm = omap_readw(OTG_TEST) & 0x0ff;
unsigned extra = 0;
switch (fsm) {
case 0x0:
state = OTG_STATE_B_IDLE;
break;
case 0x3:
case 0x7:
extra = 1;
case 0x1:
state = OTG_STATE_B_PERIPHERAL;
break;
case 0x11:
state = OTG_STATE_B_SRP_INIT;
break;
case 0x12:
case 0x13:
case 0x16:
extra = 1;
case 0x17:
state = OTG_STATE_B_WAIT_ACON;
break;
case 0x34:
state = OTG_STATE_B_HOST;
break;
case 0x36:
state = OTG_STATE_A_IDLE;
break;
case 0x3c:
state = OTG_STATE_A_WAIT_VFALL;
break;
case 0x7d:
state = OTG_STATE_A_VBUS_ERR;
break;
case 0x9e:
case 0x9f:
extra = 1;
case 0x89:
state = OTG_STATE_A_PERIPHERAL;
break;
case 0xb7:
state = OTG_STATE_A_WAIT_VRISE;
break;
case 0xb8:
state = OTG_STATE_A_WAIT_BCON;
break;
case 0xb9:
state = OTG_STATE_A_HOST;
break;
case 0xba:
state = OTG_STATE_A_SUSPEND;
break;
default:
break;
}
if (isp->phy.state == state && !extra)
return;
pr_debug("otg: %s FSM %s/%02x, %s, %06x\n", tag,
usb_otg_state_string(state), fsm, state_name(isp),
omap_readl(OTG_CTRL));
}
static inline void check_state(struct isp1301 *isp, const char *tag) { }
static void update_otg1(struct isp1301 *isp, u8 int_src)
{
u32 otg_ctrl;
otg_ctrl = omap_readl(OTG_CTRL) & OTG_CTRL_MASK;
otg_ctrl &= ~OTG_XCEIV_INPUTS;
otg_ctrl &= ~(OTG_ID|OTG_ASESSVLD|OTG_VBUSVLD);
if (int_src & INTR_SESS_VLD)
otg_ctrl |= OTG_ASESSVLD;
else if (isp->phy.state == OTG_STATE_A_WAIT_VFALL) {
a_idle(isp, "vfall");
otg_ctrl &= ~OTG_CTRL_BITS;
}
if (int_src & INTR_VBUS_VLD)
otg_ctrl |= OTG_VBUSVLD;
if (int_src & INTR_ID_GND) {
if (isp->phy.state == OTG_STATE_B_IDLE
|| isp->phy.state
== OTG_STATE_UNDEFINED) {
a_idle(isp, "init");
return;
}
} else {
otg_ctrl |= OTG_ID;
if (isp->phy.state == OTG_STATE_A_IDLE
|| isp->phy.state == OTG_STATE_UNDEFINED) {
b_idle(isp, "init");
return;
}
}
omap_writel(otg_ctrl, OTG_CTRL);
}
static void update_otg2(struct isp1301 *isp, u8 otg_status)
{
u32 otg_ctrl;
otg_ctrl = omap_readl(OTG_CTRL) & OTG_CTRL_MASK;
otg_ctrl &= ~OTG_XCEIV_INPUTS;
otg_ctrl &= ~(OTG_BSESSVLD | OTG_BSESSEND);
if (otg_status & OTG_B_SESS_VLD)
otg_ctrl |= OTG_BSESSVLD;
else if (otg_status & OTG_B_SESS_END)
otg_ctrl |= OTG_BSESSEND;
omap_writel(otg_ctrl, OTG_CTRL);
}
static void otg_update_isp(struct isp1301 *isp)
{
u32 otg_ctrl, otg_change;
u8 set = OTG1_DM_PULLDOWN, clr = OTG1_DM_PULLUP;
otg_ctrl = omap_readl(OTG_CTRL);
otg_change = otg_ctrl ^ isp->last_otg_ctrl;
isp->last_otg_ctrl = otg_ctrl;
otg_ctrl = otg_ctrl & OTG_XCEIV_INPUTS;
switch (isp->phy.state) {
case OTG_STATE_B_IDLE:
case OTG_STATE_B_PERIPHERAL:
case OTG_STATE_B_SRP_INIT:
if (!(otg_ctrl & OTG_PULLUP)) {
if (isp->phy.otg->gadget->b_hnp_enable) {
isp->phy.state = OTG_STATE_B_WAIT_ACON;
pr_debug(" --> b_wait_acon\n");
}
goto pulldown;
}
pullup:
set |= OTG1_DP_PULLUP;
clr |= OTG1_DP_PULLDOWN;
break;
case OTG_STATE_A_SUSPEND:
case OTG_STATE_A_PERIPHERAL:
if (otg_ctrl & OTG_PULLUP)
goto pullup;
default:
pulldown:
set |= OTG1_DP_PULLDOWN;
clr |= OTG1_DP_PULLUP;
break;
}
# define toggle(OTG,ISP) do { \
if (otg_ctrl & OTG) set |= ISP; \
else clr |= ISP; \
} while (0)
if (!(isp->phy.otg->host))
otg_ctrl &= ~OTG_DRV_VBUS;
switch (isp->phy.state) {
case OTG_STATE_A_SUSPEND:
if (otg_ctrl & OTG_DRV_VBUS) {
set |= OTG1_VBUS_DRV;
break;
}
notresponding(isp);
case OTG_STATE_A_VBUS_ERR:
isp->phy.state = OTG_STATE_A_WAIT_VFALL;
pr_debug(" --> a_wait_vfall\n");
case OTG_STATE_A_WAIT_VFALL:
clr |= OTG1_VBUS_DRV;
break;
case OTG_STATE_A_IDLE:
if (otg_ctrl & OTG_DRV_VBUS) {
isp->phy.state = OTG_STATE_A_WAIT_VRISE;
pr_debug(" --> a_wait_vrise\n");
}
default:
toggle(OTG_DRV_VBUS, OTG1_VBUS_DRV);
}
toggle(OTG_PU_VBUS, OTG1_VBUS_CHRG);
toggle(OTG_PD_VBUS, OTG1_VBUS_DISCHRG);
# undef toggle
isp1301_set_bits(isp, ISP1301_OTG_CONTROL_1, set);
isp1301_clear_bits(isp, ISP1301_OTG_CONTROL_1, clr);
if (otg_change & OTG_PULLUP) {
u32 l;
switch (isp->phy.state) {
case OTG_STATE_B_IDLE:
if (clr & OTG1_DP_PULLUP)
break;
isp->phy.state = OTG_STATE_B_PERIPHERAL;
pr_debug(" --> b_peripheral\n");
break;
case OTG_STATE_A_SUSPEND:
if (clr & OTG1_DP_PULLUP)
break;
isp->phy.state = OTG_STATE_A_PERIPHERAL;
pr_debug(" --> a_peripheral\n");
break;
default:
break;
}
l = omap_readl(OTG_CTRL);
l |= OTG_PULLUP;
omap_writel(l, OTG_CTRL);
}
check_state(isp, __func__);
dump_regs(isp, "otg->isp1301");
}
static irqreturn_t omap_otg_irq(int irq, void *_isp)
{
u16 otg_irq = omap_readw(OTG_IRQ_SRC);
u32 otg_ctrl;
int ret = IRQ_NONE;
struct isp1301 *isp = _isp;
struct usb_otg *otg = isp->phy.otg;
if (otg_irq & OPRT_CHG) {
omap_writew(OPRT_CHG, OTG_IRQ_SRC);
isp1301_defer_work(isp, WORK_UPDATE_ISP);
ret = IRQ_HANDLED;
} else if (otg_irq & B_SRP_TMROUT) {
pr_debug("otg: B_SRP_TIMEOUT, %06x\n", omap_readl(OTG_CTRL));
notresponding(isp);
if (isp->phy.state == OTG_STATE_B_SRP_INIT)
b_idle(isp, "srp_timeout");
omap_writew(B_SRP_TMROUT, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
} else if (otg_irq & B_HNP_FAIL) {
pr_debug("otg: %s B_HNP_FAIL, %06x\n",
state_name(isp), omap_readl(OTG_CTRL));
notresponding(isp);
otg_ctrl = omap_readl(OTG_CTRL);
otg_ctrl |= OTG_BUSDROP;
otg_ctrl &= OTG_CTRL_MASK & ~OTG_XCEIV_INPUTS;
omap_writel(otg_ctrl, OTG_CTRL);
isp->phy.state = OTG_STATE_B_PERIPHERAL;
pr_debug(" --> b_peripheral\n");
omap_writew(B_HNP_FAIL, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
} else if (otg_irq & A_SRP_DETECT) {
pr_debug("otg: %s SRP_DETECT, %06x\n",
state_name(isp), omap_readl(OTG_CTRL));
isp1301_defer_work(isp, WORK_UPDATE_OTG);
switch (isp->phy.state) {
case OTG_STATE_A_IDLE:
if (!otg->host)
break;
isp1301_defer_work(isp, WORK_HOST_RESUME);
otg_ctrl = omap_readl(OTG_CTRL);
otg_ctrl |= OTG_A_BUSREQ;
otg_ctrl &= ~(OTG_BUSDROP|OTG_B_BUSREQ)
& ~OTG_XCEIV_INPUTS
& OTG_CTRL_MASK;
omap_writel(otg_ctrl, OTG_CTRL);
break;
default:
break;
}
omap_writew(A_SRP_DETECT, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
} else if (otg_irq & A_REQ_TMROUT) {
otg_ctrl = omap_readl(OTG_CTRL);
pr_info("otg: BCON_TMOUT from %s, %06x\n",
state_name(isp), otg_ctrl);
notresponding(isp);
otg_ctrl |= OTG_BUSDROP;
otg_ctrl &= ~OTG_A_BUSREQ & OTG_CTRL_MASK & ~OTG_XCEIV_INPUTS;
omap_writel(otg_ctrl, OTG_CTRL);
isp->phy.state = OTG_STATE_A_WAIT_VFALL;
omap_writew(A_REQ_TMROUT, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
} else if (otg_irq & A_VBUS_ERR) {
otg_ctrl = omap_readl(OTG_CTRL);
printk(KERN_ERR "otg: %s, VBUS_ERR %04x ctrl %06x\n",
state_name(isp), otg_irq, otg_ctrl);
otg_ctrl |= OTG_BUSDROP;
otg_ctrl &= ~OTG_A_BUSREQ & OTG_CTRL_MASK & ~OTG_XCEIV_INPUTS;
omap_writel(otg_ctrl, OTG_CTRL);
isp->phy.state = OTG_STATE_A_VBUS_ERR;
omap_writew(A_VBUS_ERR, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
} else if (otg_irq & DRIVER_SWITCH) {
int kick = 0;
otg_ctrl = omap_readl(OTG_CTRL);
printk(KERN_NOTICE "otg: %s, SWITCH to %s, ctrl %06x\n",
state_name(isp),
(otg_ctrl & OTG_DRIVER_SEL)
? "gadget" : "host",
otg_ctrl);
isp1301_defer_work(isp, WORK_UPDATE_ISP);
if (otg_ctrl & OTG_DRIVER_SEL) {
switch (isp->phy.state) {
case OTG_STATE_A_IDLE:
b_idle(isp, __func__);
break;
default:
break;
}
isp1301_defer_work(isp, WORK_UPDATE_ISP);
} else {
if (!(otg_ctrl & OTG_ID)) {
otg_ctrl &= OTG_CTRL_MASK & ~OTG_XCEIV_INPUTS;
omap_writel(otg_ctrl | OTG_A_BUSREQ, OTG_CTRL);
}
if (otg->host) {
switch (isp->phy.state) {
case OTG_STATE_B_WAIT_ACON:
isp->phy.state = OTG_STATE_B_HOST;
pr_debug(" --> b_host\n");
kick = 1;
break;
case OTG_STATE_A_WAIT_BCON:
isp->phy.state = OTG_STATE_A_HOST;
pr_debug(" --> a_host\n");
break;
case OTG_STATE_A_PERIPHERAL:
isp->phy.state = OTG_STATE_A_WAIT_BCON;
pr_debug(" --> a_wait_bcon\n");
break;
default:
break;
}
isp1301_defer_work(isp, WORK_HOST_RESUME);
}
}
omap_writew(DRIVER_SWITCH, OTG_IRQ_SRC);
ret = IRQ_HANDLED;
if (kick)
usb_bus_start_enum(otg->host, otg->host->otg_port);
}
check_state(isp, __func__);
return ret;
}
static int isp1301_otg_init(struct isp1301 *isp)
{
u32 l;
if (!otg_dev)
return -ENODEV;
dump_regs(isp, __func__);
l = omap_readl(OTG_SYSCON_2);
l |= OTG_EN
| SRP_GPDATA
| SRP_GPDVBUS
| (0 << 20)
| SRP_DPW
| SRP_DATA | SRP_VBUS
;
omap_writel(l, OTG_SYSCON_2);
update_otg1(isp, isp1301_get_u8(isp, ISP1301_INTERRUPT_SOURCE));
update_otg2(isp, isp1301_get_u8(isp, ISP1301_OTG_STATUS));
check_state(isp, __func__);
pr_debug("otg: %s, %s %06x\n",
state_name(isp), __func__, omap_readl(OTG_CTRL));
omap_writew(DRIVER_SWITCH | OPRT_CHG
| B_SRP_TMROUT | B_HNP_FAIL
| A_VBUS_ERR | A_SRP_DETECT | A_REQ_TMROUT, OTG_IRQ_EN);
l = omap_readl(OTG_SYSCON_2);
l |= OTG_EN;
omap_writel(l, OTG_SYSCON_2);
return 0;
}
static int otg_probe(struct platform_device *dev)
{
otg_dev = dev;
return 0;
}
static int otg_remove(struct platform_device *dev)
{
otg_dev = NULL;
return 0;
}
static int otg_bind(struct isp1301 *isp)
{
int status;
if (otg_dev)
return -EBUSY;
status = platform_driver_register(&omap_otg_driver);
if (status < 0)
return status;
if (otg_dev)
status = request_irq(otg_dev->resource[1].start, omap_otg_irq,
0, DRIVER_NAME, isp);
else
status = -ENODEV;
if (status < 0)
platform_driver_unregister(&omap_otg_driver);
return status;
}
static void otg_unbind(struct isp1301 *isp)
{
if (!otg_dev)
return;
free_irq(otg_dev->resource[1].start, isp);
}
static void b_peripheral(struct isp1301 *isp)
{
u32 l;
l = omap_readl(OTG_CTRL) & OTG_XCEIV_OUTPUTS;
omap_writel(l, OTG_CTRL);
usb_gadget_vbus_connect(isp->phy.otg->gadget);
#ifdef CONFIG_USB_OTG
enable_vbus_draw(isp, 8);
otg_update_isp(isp);
#else
enable_vbus_draw(isp, 100);
isp1301_set_bits(isp, ISP1301_OTG_CONTROL_1, OTG1_DP_PULLUP);
isp1301_clear_bits(isp, ISP1301_OTG_CONTROL_1, OTG1_DP_PULLDOWN);
isp->phy.state = OTG_STATE_B_PERIPHERAL;
pr_debug(" --> b_peripheral\n");
dump_regs(isp, "2periph");
#endif
}
static void isp_update_otg(struct isp1301 *isp, u8 stat)
{
struct usb_otg *otg = isp->phy.otg;
u8 isp_stat, isp_bstat;
enum usb_otg_state state = isp->phy.state;
if (stat & INTR_BDIS_ACON)
pr_debug("OTG: BDIS_ACON, %s\n", state_name(isp));
isp_stat = isp1301_get_u8(isp, ISP1301_INTERRUPT_SOURCE);
if (isp_stat & INTR_ID_GND) {
if (otg->default_a) {
switch (state) {
case OTG_STATE_B_IDLE:
a_idle(isp, "idle");
case OTG_STATE_A_IDLE:
enable_vbus_source(isp);
case OTG_STATE_A_WAIT_VRISE:
if (isp_stat & INTR_VBUS_VLD)
isp->phy.state = OTG_STATE_A_HOST;
break;
case OTG_STATE_A_WAIT_VFALL:
if (!(isp_stat & INTR_SESS_VLD))
a_idle(isp, "vfell");
break;
default:
if (!(isp_stat & INTR_VBUS_VLD))
isp->phy.state = OTG_STATE_A_VBUS_ERR;
break;
}
isp_bstat = isp1301_get_u8(isp, ISP1301_OTG_STATUS);
} else {
switch (state) {
case OTG_STATE_B_PERIPHERAL:
case OTG_STATE_B_HOST:
case OTG_STATE_B_WAIT_ACON:
usb_gadget_vbus_disconnect(otg->gadget);
break;
default:
break;
}
if (state != OTG_STATE_A_IDLE)
a_idle(isp, "id");
if (otg->host && state == OTG_STATE_A_IDLE)
isp1301_defer_work(isp, WORK_HOST_RESUME);
isp_bstat = 0;
}
} else {
u32 l;
if (otg->default_a) {
switch (state) {
default:
isp->phy.state = OTG_STATE_A_WAIT_VFALL;
break;
case OTG_STATE_A_WAIT_VFALL:
state = OTG_STATE_A_IDLE;
break;
case OTG_STATE_A_IDLE:
host_suspend(isp);
isp1301_clear_bits(isp, ISP1301_MODE_CONTROL_1,
MC1_BDIS_ACON_EN);
isp->phy.state = OTG_STATE_B_IDLE;
l = omap_readl(OTG_CTRL) & OTG_CTRL_MASK;
l &= ~OTG_CTRL_BITS;
omap_writel(l, OTG_CTRL);
break;
case OTG_STATE_B_IDLE:
break;
}
}
isp_bstat = isp1301_get_u8(isp, ISP1301_OTG_STATUS);
switch (isp->phy.state) {
case OTG_STATE_B_PERIPHERAL:
case OTG_STATE_B_WAIT_ACON:
case OTG_STATE_B_HOST:
if (likely(isp_bstat & OTG_B_SESS_VLD))
break;
enable_vbus_draw(isp, 0);
#ifndef CONFIG_USB_OTG
isp1301_set_bits(isp, ISP1301_OTG_CONTROL_1,
OTG1_DP_PULLDOWN);
isp1301_clear_bits(isp, ISP1301_OTG_CONTROL_1,
OTG1_DP_PULLUP);
dump_regs(isp, __func__);
#endif
case OTG_STATE_B_SRP_INIT:
b_idle(isp, __func__);
l = omap_readl(OTG_CTRL) & OTG_XCEIV_OUTPUTS;
omap_writel(l, OTG_CTRL);
case OTG_STATE_B_IDLE:
if (otg->gadget && (isp_bstat & OTG_B_SESS_VLD)) {
#ifdef CONFIG_USB_OTG
update_otg1(isp, isp_stat);
update_otg2(isp, isp_bstat);
#endif
b_peripheral(isp);
} else if (!(isp_stat & (INTR_VBUS_VLD|INTR_SESS_VLD)))
isp_bstat |= OTG_B_SESS_END;
break;
case OTG_STATE_A_WAIT_VFALL:
break;
default:
pr_debug("otg: unsupported b-device %s\n",
state_name(isp));
break;
}
}
if (state != isp->phy.state)
pr_debug(" isp, %s -> %s\n",
usb_otg_state_string(state), state_name(isp));
#ifdef CONFIG_USB_OTG
update_otg1(isp, isp_stat);
update_otg2(isp, isp_bstat);
check_state(isp, __func__);
#endif
dump_regs(isp, "isp1301->otg");
}
static u8 isp1301_clear_latch(struct isp1301 *isp)
{
u8 latch = isp1301_get_u8(isp, ISP1301_INTERRUPT_LATCH);
isp1301_clear_bits(isp, ISP1301_INTERRUPT_LATCH, latch);
return latch;
}
static void
isp1301_work(struct work_struct *work)
{
struct isp1301 *isp = container_of(work, struct isp1301, work);
int stop;
isp->working = 1;
do {
stop = test_bit(WORK_STOP, &isp->todo);
#ifdef CONFIG_USB_OTG
if (test_and_clear_bit(WORK_UPDATE_ISP, &isp->todo)) {
otg_update_isp(isp);
put_device(&isp->client->dev);
}
#endif
if (test_and_clear_bit(WORK_UPDATE_OTG, &isp->todo)) {
u8 stat = isp1301_clear_latch(isp);
isp_update_otg(isp, stat);
put_device(&isp->client->dev);
}
if (test_and_clear_bit(WORK_HOST_RESUME, &isp->todo)) {
u32 otg_ctrl;
switch (isp->phy.state) {
case OTG_STATE_A_WAIT_BCON:
case OTG_STATE_A_WAIT_VRISE:
isp->phy.state = OTG_STATE_A_HOST;
pr_debug(" --> a_host\n");
otg_ctrl = omap_readl(OTG_CTRL);
otg_ctrl |= OTG_A_BUSREQ;
otg_ctrl &= ~(OTG_BUSDROP|OTG_B_BUSREQ)
& OTG_CTRL_MASK;
omap_writel(otg_ctrl, OTG_CTRL);
break;
case OTG_STATE_B_WAIT_ACON:
isp->phy.state = OTG_STATE_B_HOST;
pr_debug(" --> b_host (acon)\n");
break;
case OTG_STATE_B_HOST:
case OTG_STATE_B_IDLE:
case OTG_STATE_A_IDLE:
break;
default:
pr_debug(" host resume in %s\n",
state_name(isp));
}
host_resume(isp);
put_device(&isp->client->dev);
}
if (test_and_clear_bit(WORK_TIMER, &isp->todo)) {
#ifdef VERBOSE
dump_regs(isp, "timer");
if (!stop)
mod_timer(&isp->timer, jiffies + TIMER_JIFFIES);
#endif
put_device(&isp->client->dev);
}
if (isp->todo)
dev_vdbg(&isp->client->dev,
"work done, todo = 0x%lx\n",
isp->todo);
if (stop) {
dev_dbg(&isp->client->dev, "stop\n");
break;
}
} while (isp->todo);
isp->working = 0;
}
static irqreturn_t isp1301_irq(int irq, void *isp)
{
isp1301_defer_work(isp, WORK_UPDATE_OTG);
return IRQ_HANDLED;
}
static void isp1301_timer(unsigned long _isp)
{
isp1301_defer_work((void *)_isp, WORK_TIMER);
}
static void isp1301_release(struct device *dev)
{
struct isp1301 *isp;
isp = dev_get_drvdata(dev);
if (isp->i2c_release)
isp->i2c_release(dev);
kfree(isp->phy.otg);
kfree (isp);
}
static int isp1301_remove(struct i2c_client *i2c)
{
struct isp1301 *isp;
isp = i2c_get_clientdata(i2c);
isp1301_clear_bits(isp, ISP1301_INTERRUPT_FALLING, ~0);
isp1301_clear_bits(isp, ISP1301_INTERRUPT_RISING, ~0);
free_irq(i2c->irq, isp);
#ifdef CONFIG_USB_OTG
otg_unbind(isp);
#endif
if (machine_is_omap_h2())
gpio_free(2);
isp->timer.data = 0;
set_bit(WORK_STOP, &isp->todo);
del_timer_sync(&isp->timer);
flush_work(&isp->work);
put_device(&i2c->dev);
the_transceiver = NULL;
return 0;
}
static int isp1301_otg_enable(struct isp1301 *isp)
{
power_up(isp);
isp1301_otg_init(isp);
isp1301_set_bits(isp, ISP1301_INTERRUPT_RISING,
INTR_VBUS_VLD | INTR_SESS_VLD | INTR_ID_GND);
isp1301_set_bits(isp, ISP1301_INTERRUPT_FALLING,
INTR_VBUS_VLD | INTR_SESS_VLD | INTR_ID_GND);
dev_info(&isp->client->dev, "ready for dual-role USB ...\n");
return 0;
}
static int
isp1301_set_host(struct usb_otg *otg, struct usb_bus *host)
{
struct isp1301 *isp = container_of(otg->phy, struct isp1301, phy);
if (!otg || isp != the_transceiver)
return -ENODEV;
if (!host) {
omap_writew(0, OTG_IRQ_EN);
power_down(isp);
otg->host = NULL;
return 0;
}
#ifdef CONFIG_USB_OTG
otg->host = host;
dev_dbg(&isp->client->dev, "registered host\n");
host_suspend(isp);
if (otg->gadget)
return isp1301_otg_enable(isp);
return 0;
#elif !defined(CONFIG_USB_GADGET_OMAP)
otg->host = host;
power_up(isp);
if (machine_is_omap_h2())
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1, MC1_DAT_SE0);
dev_info(&isp->client->dev, "A-Host sessions ok\n");
isp1301_set_bits(isp, ISP1301_INTERRUPT_RISING,
INTR_ID_GND);
isp1301_set_bits(isp, ISP1301_INTERRUPT_FALLING,
INTR_ID_GND);
isp1301_set_bits(isp, ISP1301_OTG_CONTROL_1, OTG1_VBUS_DRV);
dump_regs(isp, __func__);
return 0;
#else
dev_dbg(&isp->client->dev, "host sessions not allowed\n");
return -EINVAL;
#endif
}
static int
isp1301_set_peripheral(struct usb_otg *otg, struct usb_gadget *gadget)
{
struct isp1301 *isp = container_of(otg->phy, struct isp1301, phy);
if (!otg || isp != the_transceiver)
return -ENODEV;
if (!gadget) {
omap_writew(0, OTG_IRQ_EN);
if (!otg->default_a)
enable_vbus_draw(isp, 0);
usb_gadget_vbus_disconnect(otg->gadget);
otg->gadget = NULL;
power_down(isp);
return 0;
}
#ifdef CONFIG_USB_OTG
otg->gadget = gadget;
dev_dbg(&isp->client->dev, "registered gadget\n");
if (otg->host)
return isp1301_otg_enable(isp);
return 0;
#elif !defined(CONFIG_USB_OHCI_HCD) && !defined(CONFIG_USB_OHCI_HCD_MODULE)
otg->gadget = gadget;
{
u32 l;
l = omap_readl(OTG_CTRL) & OTG_CTRL_MASK;
l &= ~(OTG_XCEIV_OUTPUTS|OTG_CTRL_BITS);
l |= OTG_ID;
omap_writel(l, OTG_CTRL);
}
power_up(isp);
isp->phy.state = OTG_STATE_B_IDLE;
if (machine_is_omap_h2() || machine_is_omap_h3())
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1, MC1_DAT_SE0);
isp1301_set_bits(isp, ISP1301_INTERRUPT_RISING,
INTR_SESS_VLD);
isp1301_set_bits(isp, ISP1301_INTERRUPT_FALLING,
INTR_VBUS_VLD);
dev_info(&isp->client->dev, "B-Peripheral sessions ok\n");
dump_regs(isp, __func__);
if (isp1301_get_u8(isp, ISP1301_INTERRUPT_SOURCE) & INTR_VBUS_VLD)
b_peripheral(isp);
return 0;
#else
dev_dbg(&isp->client->dev, "peripheral sessions not allowed\n");
return -EINVAL;
#endif
}
static int
isp1301_set_power(struct usb_phy *dev, unsigned mA)
{
if (!the_transceiver)
return -ENODEV;
if (dev->state == OTG_STATE_B_PERIPHERAL)
enable_vbus_draw(the_transceiver, mA);
return 0;
}
static int
isp1301_start_srp(struct usb_otg *otg)
{
struct isp1301 *isp = container_of(otg->phy, struct isp1301, phy);
u32 otg_ctrl;
if (!otg || isp != the_transceiver
|| isp->phy.state != OTG_STATE_B_IDLE)
return -ENODEV;
otg_ctrl = omap_readl(OTG_CTRL);
if (!(otg_ctrl & OTG_BSESSEND))
return -EINVAL;
otg_ctrl |= OTG_B_BUSREQ;
otg_ctrl &= ~OTG_A_BUSREQ & OTG_CTRL_MASK;
omap_writel(otg_ctrl, OTG_CTRL);
isp->phy.state = OTG_STATE_B_SRP_INIT;
pr_debug("otg: SRP, %s ... %06x\n", state_name(isp),
omap_readl(OTG_CTRL));
#ifdef CONFIG_USB_OTG
check_state(isp, __func__);
#endif
return 0;
}
static int
isp1301_start_hnp(struct usb_otg *otg)
{
#ifdef CONFIG_USB_OTG
struct isp1301 *isp = container_of(otg->phy, struct isp1301, phy);
u32 l;
if (!otg || isp != the_transceiver)
return -ENODEV;
if (otg->default_a && (otg->host == NULL || !otg->host->b_hnp_enable))
return -ENOTCONN;
if (!otg->default_a && (otg->gadget == NULL
|| !otg->gadget->b_hnp_enable))
return -ENOTCONN;
switch (isp->phy.state) {
case OTG_STATE_B_HOST:
isp->phy.state = OTG_STATE_B_PERIPHERAL;
break;
case OTG_STATE_A_HOST:
#if 0
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1,
MC1_BDIS_ACON_EN);
#endif
usb_gadget_vbus_connect(otg->gadget);
l = omap_readl(OTG_CTRL);
l |= OTG_A_SETB_HNPEN;
omap_writel(l, OTG_CTRL);
break;
case OTG_STATE_A_PERIPHERAL:
break;
default:
return -EILSEQ;
}
pr_debug("otg: HNP %s, %06x ...\n",
state_name(isp), omap_readl(OTG_CTRL));
check_state(isp, __func__);
return 0;
#else
return -EINVAL;
#endif
}
static int
isp1301_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
int status;
struct isp1301 *isp;
if (the_transceiver)
return 0;
isp = kzalloc(sizeof *isp, GFP_KERNEL);
if (!isp)
return 0;
isp->phy.otg = kzalloc(sizeof *isp->phy.otg, GFP_KERNEL);
if (!isp->phy.otg) {
kfree(isp);
return 0;
}
INIT_WORK(&isp->work, isp1301_work);
init_timer(&isp->timer);
isp->timer.function = isp1301_timer;
isp->timer.data = (unsigned long) isp;
i2c_set_clientdata(i2c, isp);
isp->client = i2c;
status = isp1301_get_u16(isp, ISP1301_VENDOR_ID);
if (status != I2C_VENDOR_ID_PHILIPS) {
dev_dbg(&i2c->dev, "not philips id: %d\n", status);
goto fail;
}
status = isp1301_get_u16(isp, ISP1301_PRODUCT_ID);
if (status != I2C_PRODUCT_ID_PHILIPS_1301) {
dev_dbg(&i2c->dev, "not isp1301, %d\n", status);
goto fail;
}
isp->i2c_release = i2c->dev.release;
i2c->dev.release = isp1301_release;
status = i2c_smbus_read_word_data(i2c, ISP1301_BCD_DEVICE);
dev_info(&i2c->dev, "chiprev %x.%02x, driver " DRIVER_VERSION "\n",
status >> 8, status & 0xff);
isp1301_clear_bits(isp, ISP1301_MODE_CONTROL_1, MC1_MASK);
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_2, MC2_BI_DI);
isp1301_clear_bits(isp, ISP1301_MODE_CONTROL_2, ~MC2_BI_DI);
isp1301_set_bits(isp, ISP1301_OTG_CONTROL_1,
OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN);
isp1301_clear_bits(isp, ISP1301_OTG_CONTROL_1,
~(OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN));
isp1301_clear_bits(isp, ISP1301_INTERRUPT_LATCH, ~0);
isp1301_clear_bits(isp, ISP1301_INTERRUPT_FALLING, ~0);
isp1301_clear_bits(isp, ISP1301_INTERRUPT_RISING, ~0);
#ifdef CONFIG_USB_OTG
status = otg_bind(isp);
if (status < 0) {
dev_dbg(&i2c->dev, "can't bind OTG\n");
goto fail;
}
#endif
if (machine_is_omap_h2()) {
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_1,
MC1_SPEED);
isp1301_set_bits(isp, ISP1301_MODE_CONTROL_2,
MC2_SPD_SUSP_CTRL);
omap_cfg_reg(M14_1510_GPIO2);
if (gpio_request(2, "isp1301") == 0)
gpio_direction_input(2);
isp->irq_type = IRQF_TRIGGER_FALLING;
}
status = request_irq(i2c->irq, isp1301_irq,
isp->irq_type, DRIVER_NAME, isp);
if (status < 0) {
dev_dbg(&i2c->dev, "can't get IRQ %d, err %d\n",
i2c->irq, status);
goto fail;
}
isp->phy.dev = &i2c->dev;
isp->phy.label = DRIVER_NAME;
isp->phy.set_power = isp1301_set_power,
isp->phy.otg->phy = &isp->phy;
isp->phy.otg->set_host = isp1301_set_host,
isp->phy.otg->set_peripheral = isp1301_set_peripheral,
isp->phy.otg->start_srp = isp1301_start_srp,
isp->phy.otg->start_hnp = isp1301_start_hnp,
enable_vbus_draw(isp, 0);
power_down(isp);
the_transceiver = isp;
#ifdef CONFIG_USB_OTG
update_otg1(isp, isp1301_get_u8(isp, ISP1301_INTERRUPT_SOURCE));
update_otg2(isp, isp1301_get_u8(isp, ISP1301_OTG_STATUS));
#endif
dump_regs(isp, __func__);
#ifdef VERBOSE
mod_timer(&isp->timer, jiffies + TIMER_JIFFIES);
dev_dbg(&i2c->dev, "scheduled timer, %d min\n", TIMER_MINUTES);
#endif
status = usb_add_phy(&isp->phy, USB_PHY_TYPE_USB2);
if (status < 0)
dev_err(&i2c->dev, "can't register transceiver, %d\n",
status);
return 0;
fail:
kfree(isp->phy.otg);
kfree(isp);
return -ENODEV;
}
static int __init isp_init(void)
{
return i2c_add_driver(&isp1301_driver);
}
static void __exit isp_exit(void)
{
if (the_transceiver)
usb_remove_phy(&the_transceiver->phy);
i2c_del_driver(&isp1301_driver);
}
