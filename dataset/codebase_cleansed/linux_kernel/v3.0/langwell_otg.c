static inline struct langwell_otg_timer *otg_timer_initializer
(void (*function)(unsigned long), unsigned long expires, unsigned long data)
{
struct langwell_otg_timer *timer;
timer = kmalloc(sizeof(struct langwell_otg_timer), GFP_KERNEL);
if (timer == NULL)
return timer;
timer->function = function;
timer->expires = expires;
timer->data = data;
return timer;
}
void langwell_update_transceiver(void)
{
struct langwell_otg *lnw = the_transceiver;
dev_dbg(lnw->dev, "transceiver is updated\n");
if (!lnw->qwork)
return ;
queue_work(lnw->qwork, &lnw->work);
}
static int langwell_otg_set_host(struct otg_transceiver *otg,
struct usb_bus *host)
{
otg->host = host;
return 0;
}
static int langwell_otg_set_peripheral(struct otg_transceiver *otg,
struct usb_gadget *gadget)
{
otg->gadget = gadget;
return 0;
}
static int langwell_otg_set_power(struct otg_transceiver *otg,
unsigned mA)
{
return 0;
}
static int langwell_otg_set_vbus(struct otg_transceiver *otg, bool enabled)
{
struct langwell_otg *lnw = the_transceiver;
u8 sub_id;
dev_dbg(lnw->dev, "%s <--- %s\n", __func__, enabled ? "on" : "off");
if (enabled)
sub_id = 0x8;
else
sub_id = 0x9;
if (intel_scu_ipc_simple_command(0xef, sub_id)) {
dev_dbg(lnw->dev, "Failed to set Vbus via IPC commands\n");
return -EBUSY;
}
dev_dbg(lnw->dev, "%s --->\n", __func__);
return 0;
}
static void langwell_otg_chrg_vbus(int on)
{
struct langwell_otg *lnw = the_transceiver;
u32 val;
val = readl(lnw->iotg.base + CI_OTGSC);
if (on)
writel((val & ~OTGSC_INTSTS_MASK) | OTGSC_VC,
lnw->iotg.base + CI_OTGSC);
else
writel((val & ~OTGSC_INTSTS_MASK) | OTGSC_VD,
lnw->iotg.base + CI_OTGSC);
}
static int langwell_otg_start_srp(struct otg_transceiver *otg)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val;
dev_dbg(lnw->dev, "%s --->\n", __func__);
val = readl(iotg->base + CI_OTGSC);
writel((val & ~OTGSC_INTSTS_MASK) | OTGSC_HADP,
iotg->base + CI_OTGSC);
msleep(8);
val = readl(iotg->base + CI_OTGSC);
if (val & (OTGSC_HADP | OTGSC_DP))
dev_dbg(lnw->dev, "DataLine SRP Error\n");
val = readl(iotg->base + CI_OTGSC);
val &= (~(OTGSC_BSVIE | OTGSC_BSEIE));
writel(val, iotg->base + CI_OTGSC);
iotg->otg.set_vbus(&iotg->otg, true);
msleep(15);
iotg->otg.set_vbus(&iotg->otg, false);
val = readl(iotg->base + CI_OTGSC);
dev_dbg(lnw->dev, "after VBUS pulse otgsc = %x\n", val);
val |= (OTGSC_BSVIE | OTGSC_BSEIE);
writel(val, iotg->base + CI_OTGSC);
if (val & OTGSC_BSV) {
dev_dbg(lnw->dev, "no b_sess_vld interrupt\n");
lnw->iotg.hsm.b_sess_vld = 1;
langwell_update_transceiver();
}
dev_dbg(lnw->dev, "%s <---\n", __func__);
return 0;
}
static void langwell_otg_loc_sof(int on)
{
struct langwell_otg *lnw = the_transceiver;
struct usb_hcd *hcd;
int err;
dev_dbg(lnw->dev, "%s ---> %s\n", __func__, on ? "suspend" : "resume");
hcd = bus_to_hcd(lnw->iotg.otg.host);
if (on)
err = hcd->driver->bus_resume(hcd);
else
err = hcd->driver->bus_suspend(hcd);
if (err)
dev_dbg(lnw->dev, "Fail to resume/suspend USB bus - %d\n", err);
dev_dbg(lnw->dev, "%s <---\n", __func__);
}
static int langwell_otg_check_otgsc(void)
{
struct langwell_otg *lnw = the_transceiver;
u32 otgsc, usbcfg;
dev_dbg(lnw->dev, "check sync OTGSC and USBCFG registers\n");
otgsc = readl(lnw->iotg.base + CI_OTGSC);
usbcfg = readl(lnw->usbcfg);
dev_dbg(lnw->dev, "OTGSC = %08x, USBCFG = %08x\n",
otgsc, usbcfg);
dev_dbg(lnw->dev, "OTGSC_AVV = %d\n", !!(otgsc & OTGSC_AVV));
dev_dbg(lnw->dev, "USBCFG.VBUSVAL = %d\n",
!!(usbcfg & USBCFG_VBUSVAL));
dev_dbg(lnw->dev, "OTGSC_ASV = %d\n", !!(otgsc & OTGSC_ASV));
dev_dbg(lnw->dev, "USBCFG.AVALID = %d\n",
!!(usbcfg & USBCFG_AVALID));
dev_dbg(lnw->dev, "OTGSC_BSV = %d\n", !!(otgsc & OTGSC_BSV));
dev_dbg(lnw->dev, "USBCFG.BVALID = %d\n",
!!(usbcfg & USBCFG_BVALID));
dev_dbg(lnw->dev, "OTGSC_BSE = %d\n", !!(otgsc & OTGSC_BSE));
dev_dbg(lnw->dev, "USBCFG.SESEND = %d\n",
!!(usbcfg & USBCFG_SESEND));
if (!!(otgsc & OTGSC_AVV) ^ !!(usbcfg & USBCFG_VBUSVAL)) {
dev_dbg(lnw->dev, "OTGSC.AVV != USBCFG.VBUSVAL\n");
goto err;
}
if (!!(otgsc & OTGSC_ASV) ^ !!(usbcfg & USBCFG_AVALID)) {
dev_dbg(lnw->dev, "OTGSC.ASV != USBCFG.AVALID\n");
goto err;
}
if (!!(otgsc & OTGSC_BSV) ^ !!(usbcfg & USBCFG_BVALID)) {
dev_dbg(lnw->dev, "OTGSC.BSV != USBCFG.BVALID\n");
goto err;
}
if (!!(otgsc & OTGSC_BSE) ^ !!(usbcfg & USBCFG_SESEND)) {
dev_dbg(lnw->dev, "OTGSC.BSE != USBCFG.SESSEN\n");
goto err;
}
dev_dbg(lnw->dev, "OTGSC and USBCFG are synced\n");
return 0;
err:
dev_warn(lnw->dev, "OTGSC isn't equal to USBCFG\n");
return -EPIPE;
}
static void langwell_otg_phy_low_power(int on)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u8 val, phcd;
int retval;
dev_dbg(lnw->dev, "%s ---> %s mode\n",
__func__, on ? "Low power" : "Normal");
phcd = 0x40;
val = readb(iotg->base + CI_HOSTPC1 + 2);
if (on) {
retval = langwell_otg_check_otgsc();
if (retval) {
dev_dbg(lnw->dev, "Skip PHCD programming..\n");
return ;
}
writeb(val | phcd, iotg->base + CI_HOSTPC1 + 2);
} else
writeb(val & ~phcd, iotg->base + CI_HOSTPC1 + 2);
dev_dbg(lnw->dev, "%s <--- done\n", __func__);
}
static void langwell_otg_phy_low_power_wait(int on)
{
struct langwell_otg *lnw = the_transceiver;
dev_dbg(lnw->dev, "add 5ms delay before programing PHCD\n");
mdelay(5);
langwell_otg_phy_low_power(on);
}
static void langwell_otg_intr(int on)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val;
dev_dbg(lnw->dev, "%s ---> %s\n", __func__, on ? "on" : "off");
val = readl(iotg->base + CI_OTGSC);
if (on) {
val = val | (OTGSC_INT_MASK);
writel(val, iotg->base + CI_OTGSC);
} else {
val = val & ~(OTGSC_INT_MASK);
writel(val, iotg->base + CI_OTGSC);
}
dev_dbg(lnw->dev, "%s <---\n", __func__);
}
static void langwell_otg_HAAR(int on)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val;
dev_dbg(lnw->dev, "%s ---> %s\n", __func__, on ? "on" : "off");
val = readl(iotg->base + CI_OTGSC);
if (on)
writel((val & ~OTGSC_INTSTS_MASK) | OTGSC_HAAR,
iotg->base + CI_OTGSC);
else
writel((val & ~OTGSC_INTSTS_MASK) & ~OTGSC_HAAR,
iotg->base + CI_OTGSC);
dev_dbg(lnw->dev, "%s <---\n", __func__);
}
static void langwell_otg_HABA(int on)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val;
dev_dbg(lnw->dev, "%s ---> %s\n", __func__, on ? "on" : "off");
val = readl(iotg->base + CI_OTGSC);
if (on)
writel((val & ~OTGSC_INTSTS_MASK) | OTGSC_HABA,
iotg->base + CI_OTGSC);
else
writel((val & ~OTGSC_INTSTS_MASK) & ~OTGSC_HABA,
iotg->base + CI_OTGSC);
dev_dbg(lnw->dev, "%s <---\n", __func__);
}
static int langwell_otg_check_se0_srp(int on)
{
struct langwell_otg *lnw = the_transceiver;
int delay_time = TB_SE0_SRP * 10;
u32 val;
dev_dbg(lnw->dev, "%s --->\n", __func__);
do {
udelay(100);
if (!delay_time--)
break;
val = readl(lnw->iotg.base + CI_PORTSC1);
val &= PORTSC_LS;
} while (!val);
dev_dbg(lnw->dev, "%s <---\n", __func__);
return val;
}
static void set_tmout(unsigned long indicator)
{
*(int *)indicator = 1;
}
void langwell_otg_nsf_msg(unsigned long indicator)
{
struct langwell_otg *lnw = the_transceiver;
switch (indicator) {
case 2:
case 4:
case 6:
case 7:
dev_warn(lnw->dev,
"OTG:NSF-%lu - deivce not responding\n", indicator);
break;
case 3:
dev_warn(lnw->dev,
"OTG:NSF-%lu - deivce not supported\n", indicator);
break;
default:
dev_warn(lnw->dev, "Do not have this kind of NSF\n");
break;
}
}
static int langwell_otg_init_timers(struct otg_hsm *hsm)
{
a_wait_vrise_tmr = otg_timer_initializer(&set_tmout, TA_WAIT_VRISE,
(unsigned long)&hsm->a_wait_vrise_tmout);
if (a_wait_vrise_tmr == NULL)
return -ENOMEM;
a_aidl_bdis_tmr = otg_timer_initializer(&set_tmout, TA_AIDL_BDIS,
(unsigned long)&hsm->a_aidl_bdis_tmout);
if (a_aidl_bdis_tmr == NULL)
return -ENOMEM;
b_se0_srp_tmr = otg_timer_initializer(&set_tmout, TB_SE0_SRP,
(unsigned long)&hsm->b_se0_srp);
if (b_se0_srp_tmr == NULL)
return -ENOMEM;
b_srp_init_tmr = otg_timer_initializer(&set_tmout, TB_SRP_INIT,
(unsigned long)&hsm->b_srp_init_tmout);
if (b_srp_init_tmr == NULL)
return -ENOMEM;
return 0;
}
static void langwell_otg_free_timers(void)
{
kfree(a_wait_vrise_tmr);
kfree(a_aidl_bdis_tmr);
kfree(b_se0_srp_tmr);
kfree(b_srp_init_tmr);
}
static void langwell_otg_timer_fn(unsigned long indicator)
{
struct langwell_otg *lnw = the_transceiver;
*(int *)indicator = 1;
dev_dbg(lnw->dev, "kernel timer - timeout\n");
langwell_update_transceiver();
}
static void langwell_otg_add_ktimer(enum langwell_otg_timer_type timers)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
unsigned long j = jiffies;
unsigned long data, time;
switch (timers) {
case TA_WAIT_VRISE_TMR:
iotg->hsm.a_wait_vrise_tmout = 0;
data = (unsigned long)&iotg->hsm.a_wait_vrise_tmout;
time = TA_WAIT_VRISE;
break;
case TA_WAIT_BCON_TMR:
iotg->hsm.a_wait_bcon_tmout = 0;
data = (unsigned long)&iotg->hsm.a_wait_bcon_tmout;
time = TA_WAIT_BCON;
break;
case TA_AIDL_BDIS_TMR:
iotg->hsm.a_aidl_bdis_tmout = 0;
data = (unsigned long)&iotg->hsm.a_aidl_bdis_tmout;
time = TA_AIDL_BDIS;
break;
case TB_ASE0_BRST_TMR:
iotg->hsm.b_ase0_brst_tmout = 0;
data = (unsigned long)&iotg->hsm.b_ase0_brst_tmout;
time = TB_ASE0_BRST;
break;
case TB_SRP_INIT_TMR:
iotg->hsm.b_srp_init_tmout = 0;
data = (unsigned long)&iotg->hsm.b_srp_init_tmout;
time = TB_SRP_INIT;
break;
case TB_SRP_FAIL_TMR:
iotg->hsm.b_srp_fail_tmout = 0;
data = (unsigned long)&iotg->hsm.b_srp_fail_tmout;
time = TB_SRP_FAIL;
break;
case TB_BUS_SUSPEND_TMR:
iotg->hsm.b_bus_suspend_tmout = 0;
data = (unsigned long)&iotg->hsm.b_bus_suspend_tmout;
time = TB_BUS_SUSPEND;
break;
default:
dev_dbg(lnw->dev, "unknown timer, cannot enable it\n");
return;
}
lnw->hsm_timer.data = data;
lnw->hsm_timer.function = langwell_otg_timer_fn;
lnw->hsm_timer.expires = j + time * HZ / 1000;
add_timer(&lnw->hsm_timer);
dev_dbg(lnw->dev, "add timer successfully\n");
}
static void langwell_otg_add_timer(void *gtimer)
{
struct langwell_otg_timer *timer = (struct langwell_otg_timer *)gtimer;
struct langwell_otg_timer *tmp_timer;
struct intel_mid_otg_xceiv *iotg = &the_transceiver->iotg;
u32 val32;
list_for_each_entry(tmp_timer, &active_timers, list)
if (tmp_timer == timer) {
timer->count = timer->expires;
return;
}
timer->count = timer->expires;
if (list_empty(&active_timers)) {
val32 = readl(iotg->base + CI_OTGSC);
writel(val32 | OTGSC_1MSE, iotg->base + CI_OTGSC);
}
list_add_tail(&timer->list, &active_timers);
}
static void langwell_otg_del_timer(void *gtimer)
{
struct langwell_otg *lnw = the_transceiver;
struct langwell_otg_timer *timer = (struct langwell_otg_timer *)gtimer;
struct langwell_otg_timer *tmp_timer, *del_tmp;
u32 val32;
list_for_each_entry_safe(tmp_timer, del_tmp, &active_timers, list)
if (tmp_timer == timer)
list_del(&timer->list);
if (list_empty(&active_timers)) {
val32 = readl(lnw->iotg.base + CI_OTGSC);
writel(val32 & ~OTGSC_1MSE, lnw->iotg.base + CI_OTGSC);
}
}
static int langwell_otg_tick_timer(u32 *int_sts)
{
struct langwell_otg *lnw = the_transceiver;
struct langwell_otg_timer *tmp_timer, *del_tmp;
int expired = 0;
list_for_each_entry_safe(tmp_timer, del_tmp, &active_timers, list) {
tmp_timer->count--;
if (!tmp_timer->count) {
list_del(&tmp_timer->list);
tmp_timer->function(tmp_timer->data);
expired = 1;
}
}
if (list_empty(&active_timers)) {
dev_dbg(lnw->dev, "tick timer: disable 1ms int\n");
*int_sts = *int_sts & ~OTGSC_1MSE;
}
return expired;
}
static void reset_otg(void)
{
struct langwell_otg *lnw = the_transceiver;
int delay_time = 1000;
u32 val;
dev_dbg(lnw->dev, "reseting OTG controller ...\n");
val = readl(lnw->iotg.base + CI_USBCMD);
writel(val | USBCMD_RST, lnw->iotg.base + CI_USBCMD);
do {
udelay(100);
if (!delay_time--)
dev_dbg(lnw->dev, "reset timeout\n");
val = readl(lnw->iotg.base + CI_USBCMD);
val &= USBCMD_RST;
} while (val != 0);
dev_dbg(lnw->dev, "reset done.\n");
}
static void set_host_mode(void)
{
struct langwell_otg *lnw = the_transceiver;
u32 val;
reset_otg();
val = readl(lnw->iotg.base + CI_USBMODE);
val = (val & (~USBMODE_CM)) | USBMODE_HOST;
writel(val, lnw->iotg.base + CI_USBMODE);
}
static void set_client_mode(void)
{
struct langwell_otg *lnw = the_transceiver;
u32 val;
reset_otg();
val = readl(lnw->iotg.base + CI_USBMODE);
val = (val & (~USBMODE_CM)) | USBMODE_DEVICE;
writel(val, lnw->iotg.base + CI_USBMODE);
}
static void init_hsm(void)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val32;
val32 = readl(lnw->iotg.base + CI_OTGSC);
dev_dbg(lnw->dev, "%s: OTGSC init value = 0x%x\n", __func__, val32);
if (val32 & OTGSC_ID) {
iotg->hsm.id = 1;
iotg->otg.default_a = 0;
set_client_mode();
iotg->otg.state = OTG_STATE_B_IDLE;
} else {
iotg->hsm.id = 0;
iotg->otg.default_a = 1;
set_host_mode();
iotg->otg.state = OTG_STATE_A_IDLE;
}
if (val32 & OTGSC_BSE)
iotg->hsm.b_sess_end = 1;
if (val32 & OTGSC_BSV)
iotg->hsm.b_sess_vld = 1;
if (val32 & OTGSC_ASV)
iotg->hsm.a_sess_vld = 1;
if (val32 & OTGSC_AVV)
iotg->hsm.a_vbus_vld = 1;
iotg->hsm.a_bus_req = 1;
iotg->hsm.a_bus_drop = 0;
iotg->hsm.b_bus_req = 0;
iotg->hsm.a_clr_err = 0;
langwell_otg_phy_low_power_wait(1);
}
static void update_hsm(void)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 val32;
val32 = readl(lnw->iotg.base + CI_OTGSC);
dev_dbg(lnw->dev, "%s: OTGSC value = 0x%x\n", __func__, val32);
iotg->hsm.id = !!(val32 & OTGSC_ID);
iotg->hsm.b_sess_end = !!(val32 & OTGSC_BSE);
iotg->hsm.b_sess_vld = !!(val32 & OTGSC_BSV);
iotg->hsm.a_sess_vld = !!(val32 & OTGSC_ASV);
iotg->hsm.a_vbus_vld = !!(val32 & OTGSC_AVV);
}
static irqreturn_t otg_dummy_irq(int irq, void *_dev)
{
struct langwell_otg *lnw = the_transceiver;
void __iomem *reg_base = _dev;
u32 val;
u32 int_mask = 0;
val = readl(reg_base + CI_USBMODE);
if ((val & USBMODE_CM) != USBMODE_DEVICE)
return IRQ_NONE;
val = readl(reg_base + CI_USBSTS);
int_mask = val & INTR_DUMMY_MASK;
if (int_mask == 0)
return IRQ_NONE;
if (lnw->iotg.hsm.b_conn) {
lnw->iotg.hsm.b_conn = 0;
if (spin_trylock(&lnw->wq_lock)) {
langwell_update_transceiver();
spin_unlock(&lnw->wq_lock);
}
}
writel(int_mask, reg_base + CI_USBSTS);
return IRQ_HANDLED;
}
static irqreturn_t otg_irq(int irq, void *_dev)
{
struct langwell_otg *lnw = _dev;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
u32 int_sts, int_en;
u32 int_mask = 0;
int flag = 0;
int_sts = readl(lnw->iotg.base + CI_OTGSC);
int_en = (int_sts & OTGSC_INTEN_MASK) >> 8;
int_mask = int_sts & int_en;
if (int_mask == 0)
return IRQ_NONE;
if (int_mask & OTGSC_IDIS) {
dev_dbg(lnw->dev, "%s: id change int\n", __func__);
iotg->hsm.id = (int_sts & OTGSC_ID) ? 1 : 0;
dev_dbg(lnw->dev, "id = %d\n", iotg->hsm.id);
flag = 1;
}
if (int_mask & OTGSC_DPIS) {
dev_dbg(lnw->dev, "%s: data pulse int\n", __func__);
iotg->hsm.a_srp_det = (int_sts & OTGSC_DPS) ? 1 : 0;
dev_dbg(lnw->dev, "data pulse = %d\n", iotg->hsm.a_srp_det);
flag = 1;
}
if (int_mask & OTGSC_BSEIS) {
dev_dbg(lnw->dev, "%s: b session end int\n", __func__);
iotg->hsm.b_sess_end = (int_sts & OTGSC_BSE) ? 1 : 0;
dev_dbg(lnw->dev, "b_sess_end = %d\n", iotg->hsm.b_sess_end);
flag = 1;
}
if (int_mask & OTGSC_BSVIS) {
dev_dbg(lnw->dev, "%s: b session valid int\n", __func__);
iotg->hsm.b_sess_vld = (int_sts & OTGSC_BSV) ? 1 : 0;
dev_dbg(lnw->dev, "b_sess_vld = %d\n", iotg->hsm.b_sess_end);
flag = 1;
}
if (int_mask & OTGSC_ASVIS) {
dev_dbg(lnw->dev, "%s: a session valid int\n", __func__);
iotg->hsm.a_sess_vld = (int_sts & OTGSC_ASV) ? 1 : 0;
dev_dbg(lnw->dev, "a_sess_vld = %d\n", iotg->hsm.a_sess_vld);
flag = 1;
}
if (int_mask & OTGSC_AVVIS) {
dev_dbg(lnw->dev, "%s: a vbus valid int\n", __func__);
iotg->hsm.a_vbus_vld = (int_sts & OTGSC_AVV) ? 1 : 0;
dev_dbg(lnw->dev, "a_vbus_vld = %d\n", iotg->hsm.a_vbus_vld);
flag = 1;
}
if (int_mask & OTGSC_1MSS) {
if (langwell_otg_tick_timer(&int_sts))
flag = 1;
}
writel((int_sts & ~OTGSC_INTSTS_MASK) | int_mask,
lnw->iotg.base + CI_OTGSC);
if (flag)
langwell_update_transceiver();
return IRQ_HANDLED;
}
static int langwell_otg_iotg_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = data;
int flag = 0;
if (iotg == NULL)
return NOTIFY_BAD;
if (lnw == NULL)
return NOTIFY_BAD;
switch (action) {
case MID_OTG_NOTIFY_CONNECT:
dev_dbg(lnw->dev, "Lnw OTG Notify Connect Event\n");
if (iotg->otg.default_a == 1)
iotg->hsm.b_conn = 1;
else
iotg->hsm.a_conn = 1;
flag = 1;
break;
case MID_OTG_NOTIFY_DISCONN:
dev_dbg(lnw->dev, "Lnw OTG Notify Disconnect Event\n");
if (iotg->otg.default_a == 1)
iotg->hsm.b_conn = 0;
else
iotg->hsm.a_conn = 0;
flag = 1;
break;
case MID_OTG_NOTIFY_HSUSPEND:
dev_dbg(lnw->dev, "Lnw OTG Notify Host Bus suspend Event\n");
if (iotg->otg.default_a == 1)
iotg->hsm.a_suspend_req = 1;
else
iotg->hsm.b_bus_req = 0;
flag = 1;
break;
case MID_OTG_NOTIFY_HRESUME:
dev_dbg(lnw->dev, "Lnw OTG Notify Host Bus resume Event\n");
if (iotg->otg.default_a == 1)
iotg->hsm.b_bus_resume = 1;
flag = 1;
break;
case MID_OTG_NOTIFY_CSUSPEND:
dev_dbg(lnw->dev, "Lnw OTG Notify Client Bus suspend Event\n");
if (iotg->otg.default_a == 1) {
if (iotg->hsm.b_bus_suspend_vld == 2) {
iotg->hsm.b_bus_suspend = 1;
iotg->hsm.b_bus_suspend_vld = 0;
flag = 1;
} else {
iotg->hsm.b_bus_suspend_vld++;
flag = 0;
}
} else {
if (iotg->hsm.a_bus_suspend == 0) {
iotg->hsm.a_bus_suspend = 1;
flag = 1;
}
}
break;
case MID_OTG_NOTIFY_CRESUME:
dev_dbg(lnw->dev, "Lnw OTG Notify Client Bus resume Event\n");
if (iotg->otg.default_a == 0)
iotg->hsm.a_bus_suspend = 0;
flag = 0;
break;
case MID_OTG_NOTIFY_HOSTADD:
dev_dbg(lnw->dev, "Lnw OTG Nofity Host Driver Add\n");
flag = 1;
break;
case MID_OTG_NOTIFY_HOSTREMOVE:
dev_dbg(lnw->dev, "Lnw OTG Nofity Host Driver remove\n");
flag = 1;
break;
case MID_OTG_NOTIFY_CLIENTADD:
dev_dbg(lnw->dev, "Lnw OTG Nofity Client Driver Add\n");
flag = 1;
break;
case MID_OTG_NOTIFY_CLIENTREMOVE:
dev_dbg(lnw->dev, "Lnw OTG Nofity Client Driver remove\n");
flag = 1;
break;
default:
dev_dbg(lnw->dev, "Lnw OTG Nofity unknown notify message\n");
return NOTIFY_DONE;
}
if (flag)
langwell_update_transceiver();
return NOTIFY_OK;
}
static void langwell_otg_work(struct work_struct *work)
{
struct langwell_otg *lnw;
struct intel_mid_otg_xceiv *iotg;
int retval;
struct pci_dev *pdev;
lnw = container_of(work, struct langwell_otg, work);
iotg = &lnw->iotg;
pdev = to_pci_dev(lnw->dev);
dev_dbg(lnw->dev, "%s: old state = %s\n", __func__,
otg_state_string(iotg->otg.state));
switch (iotg->otg.state) {
case OTG_STATE_UNDEFINED:
case OTG_STATE_B_IDLE:
if (!iotg->hsm.id) {
langwell_otg_del_timer(b_srp_init_tmr);
del_timer_sync(&lnw->hsm_timer);
iotg->otg.default_a = 1;
iotg->hsm.a_srp_det = 0;
langwell_otg_chrg_vbus(0);
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.b_sess_vld) {
langwell_otg_del_timer(b_srp_init_tmr);
del_timer_sync(&lnw->hsm_timer);
iotg->hsm.b_sess_end = 0;
iotg->hsm.a_bus_suspend = 0;
langwell_otg_chrg_vbus(0);
if (lnw->iotg.start_peripheral) {
lnw->iotg.start_peripheral(&lnw->iotg);
iotg->otg.state = OTG_STATE_B_PERIPHERAL;
} else
dev_dbg(lnw->dev, "client driver not loaded\n");
} else if (iotg->hsm.b_srp_init_tmout) {
iotg->hsm.b_srp_init_tmout = 0;
dev_warn(lnw->dev, "SRP init timeout\n");
} else if (iotg->hsm.b_srp_fail_tmout) {
iotg->hsm.b_srp_fail_tmout = 0;
iotg->hsm.b_bus_req = 0;
langwell_otg_nsf_msg(6);
} else if (iotg->hsm.b_bus_req && iotg->hsm.b_sess_end) {
del_timer_sync(&lnw->hsm_timer);
retval = langwell_otg_check_se0_srp(0);
if (retval) {
iotg->hsm.b_bus_req = 0;
dev_dbg(lnw->dev, "LS isn't SE0, try later\n");
} else {
langwell_otg_phy_low_power(0);
langwell_otg_add_timer(b_srp_init_tmr);
iotg->otg.start_srp(&iotg->otg);
langwell_otg_del_timer(b_srp_init_tmr);
langwell_otg_add_ktimer(TB_SRP_FAIL_TMR);
langwell_otg_phy_low_power_wait(1);
}
}
break;
case OTG_STATE_B_SRP_INIT:
if (!iotg->hsm.id) {
iotg->otg.default_a = 1;
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_chrg_vbus(0);
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.b_sess_vld) {
langwell_otg_chrg_vbus(0);
if (lnw->iotg.start_peripheral) {
lnw->iotg.start_peripheral(&lnw->iotg);
iotg->otg.state = OTG_STATE_B_PERIPHERAL;
} else
dev_dbg(lnw->dev, "client driver not loaded\n");
}
break;
case OTG_STATE_B_PERIPHERAL:
if (!iotg->hsm.id) {
iotg->otg.default_a = 1;
iotg->hsm.a_srp_det = 0;
langwell_otg_chrg_vbus(0);
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.b_sess_vld) {
iotg->hsm.b_hnp_enable = 0;
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
iotg->otg.state = OTG_STATE_B_IDLE;
} else if (iotg->hsm.b_bus_req && iotg->otg.gadget &&
iotg->otg.gadget->b_hnp_enable &&
iotg->hsm.a_bus_suspend) {
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
langwell_otg_HAAR(1);
iotg->hsm.a_conn = 0;
if (lnw->iotg.start_host) {
lnw->iotg.start_host(&lnw->iotg);
iotg->otg.state = OTG_STATE_B_WAIT_ACON;
} else
dev_dbg(lnw->dev,
"host driver not loaded.\n");
iotg->hsm.a_bus_resume = 0;
langwell_otg_add_ktimer(TB_ASE0_BRST_TMR);
}
break;
case OTG_STATE_B_WAIT_ACON:
if (!iotg->hsm.id) {
del_timer_sync(&lnw->hsm_timer);
iotg->otg.default_a = 1;
iotg->hsm.a_srp_det = 0;
langwell_otg_chrg_vbus(0);
langwell_otg_HAAR(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.b_sess_vld) {
del_timer_sync(&lnw->hsm_timer);
iotg->hsm.b_hnp_enable = 0;
iotg->hsm.b_bus_req = 0;
langwell_otg_chrg_vbus(0);
langwell_otg_HAAR(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
} else if (iotg->hsm.a_conn) {
del_timer_sync(&lnw->hsm_timer);
langwell_otg_HAAR(0);
iotg->otg.state = OTG_STATE_B_HOST;
langwell_update_transceiver();
} else if (iotg->hsm.a_bus_resume ||
iotg->hsm.b_ase0_brst_tmout) {
del_timer_sync(&lnw->hsm_timer);
langwell_otg_HAAR(0);
langwell_otg_nsf_msg(7);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->hsm.a_bus_suspend = 0;
iotg->hsm.b_bus_req = 0;
if (lnw->iotg.start_peripheral)
lnw->iotg.start_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver not loaded.\n");
iotg->otg.state = OTG_STATE_B_PERIPHERAL;
}
break;
case OTG_STATE_B_HOST:
if (!iotg->hsm.id) {
iotg->otg.default_a = 1;
iotg->hsm.a_srp_det = 0;
langwell_otg_chrg_vbus(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.b_sess_vld) {
iotg->hsm.b_hnp_enable = 0;
iotg->hsm.b_bus_req = 0;
langwell_otg_chrg_vbus(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
} else if ((!iotg->hsm.b_bus_req) ||
(!iotg->hsm.a_conn)) {
iotg->hsm.b_bus_req = 0;
langwell_otg_loc_sof(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->hsm.a_bus_suspend = 0;
if (lnw->iotg.start_peripheral)
lnw->iotg.start_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver not loaded.\n");
iotg->otg.state = OTG_STATE_B_PERIPHERAL;
}
break;
case OTG_STATE_A_IDLE:
iotg->otg.default_a = 1;
if (iotg->hsm.id) {
iotg->otg.default_a = 0;
iotg->hsm.b_bus_req = 0;
iotg->hsm.vbus_srp_up = 0;
langwell_otg_chrg_vbus(0);
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.a_bus_drop &&
(iotg->hsm.a_srp_det || iotg->hsm.a_bus_req)) {
langwell_otg_phy_low_power(0);
iotg->otg.set_vbus(&iotg->otg, true);
iotg->hsm.vbus_srp_up = 0;
iotg->hsm.a_wait_vrise_tmout = 0;
langwell_otg_add_timer(a_wait_vrise_tmr);
iotg->otg.state = OTG_STATE_A_WAIT_VRISE;
langwell_update_transceiver();
} else if (!iotg->hsm.a_bus_drop && iotg->hsm.a_sess_vld) {
iotg->hsm.vbus_srp_up = 1;
} else if (!iotg->hsm.a_sess_vld && iotg->hsm.vbus_srp_up) {
msleep(10);
langwell_otg_phy_low_power(0);
iotg->otg.set_vbus(&iotg->otg, true);
iotg->hsm.a_srp_det = 1;
iotg->hsm.vbus_srp_up = 0;
iotg->hsm.a_wait_vrise_tmout = 0;
langwell_otg_add_timer(a_wait_vrise_tmr);
iotg->otg.state = OTG_STATE_A_WAIT_VRISE;
langwell_update_transceiver();
} else if (!iotg->hsm.a_sess_vld &&
!iotg->hsm.vbus_srp_up) {
langwell_otg_phy_low_power(1);
}
break;
case OTG_STATE_A_WAIT_VRISE:
if (iotg->hsm.id) {
langwell_otg_del_timer(a_wait_vrise_tmr);
iotg->hsm.b_bus_req = 0;
iotg->otg.default_a = 0;
iotg->otg.set_vbus(&iotg->otg, false);
set_client_mode();
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_B_IDLE;
} else if (iotg->hsm.a_vbus_vld) {
langwell_otg_del_timer(a_wait_vrise_tmr);
iotg->hsm.b_conn = 0;
if (lnw->iotg.start_host)
lnw->iotg.start_host(&lnw->iotg);
else {
dev_dbg(lnw->dev, "host driver not loaded.\n");
break;
}
langwell_otg_add_ktimer(TA_WAIT_BCON_TMR);
iotg->otg.state = OTG_STATE_A_WAIT_BCON;
} else if (iotg->hsm.a_wait_vrise_tmout) {
iotg->hsm.b_conn = 0;
if (iotg->hsm.a_vbus_vld) {
if (lnw->iotg.start_host)
lnw->iotg.start_host(&lnw->iotg);
else {
dev_dbg(lnw->dev,
"host driver not loaded.\n");
break;
}
langwell_otg_add_ktimer(TA_WAIT_BCON_TMR);
iotg->otg.state = OTG_STATE_A_WAIT_BCON;
} else {
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_A_VBUS_ERR;
}
}
break;
case OTG_STATE_A_WAIT_BCON:
if (iotg->hsm.id) {
del_timer_sync(&lnw->hsm_timer);
iotg->otg.default_a = 0;
iotg->hsm.b_bus_req = 0;
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
set_client_mode();
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.a_vbus_vld) {
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_A_VBUS_ERR;
} else if (iotg->hsm.a_bus_drop ||
(iotg->hsm.a_wait_bcon_tmout &&
!iotg->hsm.a_bus_req)) {
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_WAIT_VFALL;
} else if (iotg->hsm.b_conn) {
del_timer_sync(&lnw->hsm_timer);
iotg->hsm.a_suspend_req = 0;
iotg->otg.state = OTG_STATE_A_HOST;
if (iotg->hsm.a_srp_det && iotg->otg.host &&
!iotg->otg.host->b_hnp_enable) {
iotg->hsm.a_bus_req = 1;
iotg->hsm.a_srp_det = 0;
} else if (!iotg->hsm.a_bus_req && iotg->otg.host &&
iotg->otg.host->b_hnp_enable) {
msleep(10000);
if (iotg->hsm.a_bus_req)
break;
if (request_irq(pdev->irq,
otg_dummy_irq, IRQF_SHARED,
driver_name, iotg->base) != 0) {
dev_dbg(lnw->dev,
"request interrupt %d fail\n",
pdev->irq);
}
langwell_otg_HABA(1);
iotg->hsm.b_bus_resume = 0;
iotg->hsm.a_aidl_bdis_tmout = 0;
langwell_otg_loc_sof(0);
langwell_otg_phy_low_power(0);
langwell_otg_add_timer(a_aidl_bdis_tmr);
iotg->otg.state = OTG_STATE_A_SUSPEND;
} else if (!iotg->hsm.a_bus_req && iotg->otg.host &&
!iotg->otg.host->b_hnp_enable) {
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_WAIT_VFALL;
}
}
break;
case OTG_STATE_A_HOST:
if (iotg->hsm.id) {
iotg->otg.default_a = 0;
iotg->hsm.b_bus_req = 0;
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
set_client_mode();
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.a_bus_drop ||
(iotg->otg.host &&
!iotg->otg.host->b_hnp_enable &&
!iotg->hsm.a_bus_req)) {
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_WAIT_VFALL;
} else if (!iotg->hsm.a_vbus_vld) {
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_A_VBUS_ERR;
} else if (iotg->otg.host &&
iotg->otg.host->b_hnp_enable &&
!iotg->hsm.a_bus_req) {
if (request_irq(pdev->irq, otg_dummy_irq, IRQF_SHARED,
driver_name, iotg->base) != 0) {
dev_dbg(lnw->dev,
"request interrupt %d failed\n",
pdev->irq);
}
langwell_otg_HABA(1);
iotg->hsm.b_bus_resume = 0;
iotg->hsm.a_aidl_bdis_tmout = 0;
langwell_otg_loc_sof(0);
langwell_otg_phy_low_power(0);
langwell_otg_add_timer(a_aidl_bdis_tmr);
iotg->otg.state = OTG_STATE_A_SUSPEND;
} else if (!iotg->hsm.b_conn || !iotg->hsm.a_bus_req) {
langwell_otg_add_ktimer(TA_WAIT_BCON_TMR);
iotg->otg.state = OTG_STATE_A_WAIT_BCON;
}
break;
case OTG_STATE_A_SUSPEND:
if (iotg->hsm.id) {
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
free_irq(pdev->irq, iotg->base);
iotg->otg.default_a = 0;
iotg->hsm.b_bus_req = 0;
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.a_bus_req ||
iotg->hsm.b_bus_resume) {
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
free_irq(pdev->irq, iotg->base);
iotg->hsm.a_suspend_req = 0;
langwell_otg_loc_sof(1);
iotg->otg.state = OTG_STATE_A_HOST;
} else if (iotg->hsm.a_aidl_bdis_tmout ||
iotg->hsm.a_bus_drop) {
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
free_irq(pdev->irq, iotg->base);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_WAIT_VFALL;
} else if (!iotg->hsm.b_conn && iotg->otg.host &&
iotg->otg.host->b_hnp_enable) {
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
free_irq(pdev->irq, iotg->base);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->hsm.b_bus_suspend = 0;
iotg->hsm.b_bus_suspend_vld = 0;
if (lnw->iotg.start_peripheral)
lnw->iotg.start_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver not loaded.\n");
langwell_otg_add_ktimer(TB_BUS_SUSPEND_TMR);
iotg->otg.state = OTG_STATE_A_PERIPHERAL;
break;
} else if (!iotg->hsm.a_vbus_vld) {
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
free_irq(pdev->irq, iotg->base);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_A_VBUS_ERR;
}
break;
case OTG_STATE_A_PERIPHERAL:
if (iotg->hsm.id) {
del_timer_sync(&lnw->hsm_timer);
iotg->otg.default_a = 0;
iotg->hsm.b_bus_req = 0;
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
set_client_mode();
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (!iotg->hsm.a_vbus_vld) {
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
langwell_otg_phy_low_power_wait(1);
iotg->otg.state = OTG_STATE_A_VBUS_ERR;
} else if (iotg->hsm.a_bus_drop) {
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_WAIT_VFALL;
} else if (iotg->hsm.b_bus_suspend) {
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
if (lnw->iotg.start_host)
lnw->iotg.start_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver not loaded.\n");
langwell_otg_add_ktimer(TA_WAIT_BCON_TMR);
iotg->otg.state = OTG_STATE_A_WAIT_BCON;
} else if (iotg->hsm.b_bus_suspend_tmout) {
u32 val;
val = readl(lnw->iotg.base + CI_PORTSC1);
if (!(val & PORTSC_SUSP))
break;
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(lnw->dev,
"client driver has been removed.\n");
if (lnw->iotg.start_host)
lnw->iotg.start_host(&lnw->iotg);
else
dev_dbg(lnw->dev,
"host driver not loaded.\n");
langwell_otg_add_ktimer(TA_WAIT_BCON_TMR);
iotg->otg.state = OTG_STATE_A_WAIT_BCON;
}
break;
case OTG_STATE_A_VBUS_ERR:
if (iotg->hsm.id) {
iotg->otg.default_a = 0;
iotg->hsm.a_clr_err = 0;
iotg->hsm.a_srp_det = 0;
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.a_clr_err) {
iotg->hsm.a_clr_err = 0;
iotg->hsm.a_srp_det = 0;
reset_otg();
init_hsm();
if (iotg->otg.state == OTG_STATE_A_IDLE)
langwell_update_transceiver();
} else {
langwell_otg_phy_low_power(1);
}
break;
case OTG_STATE_A_WAIT_VFALL:
if (iotg->hsm.id) {
iotg->otg.default_a = 0;
set_client_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_B_IDLE;
langwell_update_transceiver();
} else if (iotg->hsm.a_bus_req) {
iotg->otg.set_vbus(&iotg->otg, true);
iotg->hsm.a_wait_vrise_tmout = 0;
langwell_otg_add_timer(a_wait_vrise_tmr);
iotg->otg.state = OTG_STATE_A_WAIT_VRISE;
} else if (!iotg->hsm.a_sess_vld) {
iotg->hsm.a_srp_det = 0;
set_host_mode();
langwell_otg_phy_low_power(1);
iotg->otg.state = OTG_STATE_A_IDLE;
}
break;
default:
;
}
dev_dbg(lnw->dev, "%s: new state = %s\n", __func__,
otg_state_string(iotg->otg.state));
}
static ssize_t
show_registers(struct device *_dev, struct device_attribute *attr, char *buf)
{
struct langwell_otg *lnw = the_transceiver;
char *next;
unsigned size, t;
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size,
"\n"
"USBCMD = 0x%08x\n"
"USBSTS = 0x%08x\n"
"USBINTR = 0x%08x\n"
"ASYNCLISTADDR = 0x%08x\n"
"PORTSC1 = 0x%08x\n"
"HOSTPC1 = 0x%08x\n"
"OTGSC = 0x%08x\n"
"USBMODE = 0x%08x\n",
readl(lnw->iotg.base + 0x30),
readl(lnw->iotg.base + 0x34),
readl(lnw->iotg.base + 0x38),
readl(lnw->iotg.base + 0x48),
readl(lnw->iotg.base + 0x74),
readl(lnw->iotg.base + 0xb4),
readl(lnw->iotg.base + 0xf4),
readl(lnw->iotg.base + 0xf8)
);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
show_hsm(struct device *_dev, struct device_attribute *attr, char *buf)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
char *next;
unsigned size, t;
next = buf;
size = PAGE_SIZE;
if (iotg->otg.host)
iotg->hsm.a_set_b_hnp_en = iotg->otg.host->b_hnp_enable;
if (iotg->otg.gadget)
iotg->hsm.b_hnp_enable = iotg->otg.gadget->b_hnp_enable;
t = scnprintf(next, size,
"\n"
"current state = %s\n"
"a_bus_resume = \t%d\n"
"a_bus_suspend = \t%d\n"
"a_conn = \t%d\n"
"a_sess_vld = \t%d\n"
"a_srp_det = \t%d\n"
"a_vbus_vld = \t%d\n"
"b_bus_resume = \t%d\n"
"b_bus_suspend = \t%d\n"
"b_conn = \t%d\n"
"b_se0_srp = \t%d\n"
"b_sess_end = \t%d\n"
"b_sess_vld = \t%d\n"
"id = \t%d\n"
"a_set_b_hnp_en = \t%d\n"
"b_srp_done = \t%d\n"
"b_hnp_enable = \t%d\n"
"a_wait_vrise_tmout = \t%d\n"
"a_wait_bcon_tmout = \t%d\n"
"a_aidl_bdis_tmout = \t%d\n"
"b_ase0_brst_tmout = \t%d\n"
"a_bus_drop = \t%d\n"
"a_bus_req = \t%d\n"
"a_clr_err = \t%d\n"
"a_suspend_req = \t%d\n"
"b_bus_req = \t%d\n"
"b_bus_suspend_tmout = \t%d\n"
"b_bus_suspend_vld = \t%d\n",
otg_state_string(iotg->otg.state),
iotg->hsm.a_bus_resume,
iotg->hsm.a_bus_suspend,
iotg->hsm.a_conn,
iotg->hsm.a_sess_vld,
iotg->hsm.a_srp_det,
iotg->hsm.a_vbus_vld,
iotg->hsm.b_bus_resume,
iotg->hsm.b_bus_suspend,
iotg->hsm.b_conn,
iotg->hsm.b_se0_srp,
iotg->hsm.b_sess_end,
iotg->hsm.b_sess_vld,
iotg->hsm.id,
iotg->hsm.a_set_b_hnp_en,
iotg->hsm.b_srp_done,
iotg->hsm.b_hnp_enable,
iotg->hsm.a_wait_vrise_tmout,
iotg->hsm.a_wait_bcon_tmout,
iotg->hsm.a_aidl_bdis_tmout,
iotg->hsm.b_ase0_brst_tmout,
iotg->hsm.a_bus_drop,
iotg->hsm.a_bus_req,
iotg->hsm.a_clr_err,
iotg->hsm.a_suspend_req,
iotg->hsm.b_bus_req,
iotg->hsm.b_bus_suspend_tmout,
iotg->hsm.b_bus_suspend_vld
);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
get_a_bus_req(struct device *dev, struct device_attribute *attr, char *buf)
{
struct langwell_otg *lnw = the_transceiver;
char *next;
unsigned size, t;
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d", lnw->iotg.hsm.a_bus_req);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_a_bus_req(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
if (!iotg->otg.default_a)
return -1;
if (count > 2)
return -1;
if (buf[0] == '0') {
iotg->hsm.a_bus_req = 0;
dev_dbg(lnw->dev, "User request: a_bus_req = 0\n");
} else if (buf[0] == '1') {
if (iotg->hsm.a_bus_drop)
return -1;
iotg->hsm.a_bus_req = 1;
dev_dbg(lnw->dev, "User request: a_bus_req = 1\n");
}
if (spin_trylock(&lnw->wq_lock)) {
langwell_update_transceiver();
spin_unlock(&lnw->wq_lock);
}
return count;
}
static ssize_t
get_a_bus_drop(struct device *dev, struct device_attribute *attr, char *buf)
{
struct langwell_otg *lnw = the_transceiver;
char *next;
unsigned size, t;
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d", lnw->iotg.hsm.a_bus_drop);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_a_bus_drop(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
if (!iotg->otg.default_a)
return -1;
if (count > 2)
return -1;
if (buf[0] == '0') {
iotg->hsm.a_bus_drop = 0;
dev_dbg(lnw->dev, "User request: a_bus_drop = 0\n");
} else if (buf[0] == '1') {
iotg->hsm.a_bus_drop = 1;
iotg->hsm.a_bus_req = 0;
dev_dbg(lnw->dev, "User request: a_bus_drop = 1\n");
dev_dbg(lnw->dev, "User request: and a_bus_req = 0\n");
}
if (spin_trylock(&lnw->wq_lock)) {
langwell_update_transceiver();
spin_unlock(&lnw->wq_lock);
}
return count;
}
static ssize_t
get_b_bus_req(struct device *dev, struct device_attribute *attr, char *buf)
{
struct langwell_otg *lnw = the_transceiver;
char *next;
unsigned size, t;
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d", lnw->iotg.hsm.b_bus_req);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_b_bus_req(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
if (iotg->otg.default_a)
return -1;
if (count > 2)
return -1;
if (buf[0] == '0') {
iotg->hsm.b_bus_req = 0;
dev_dbg(lnw->dev, "User request: b_bus_req = 0\n");
} else if (buf[0] == '1') {
iotg->hsm.b_bus_req = 1;
dev_dbg(lnw->dev, "User request: b_bus_req = 1\n");
}
if (spin_trylock(&lnw->wq_lock)) {
langwell_update_transceiver();
spin_unlock(&lnw->wq_lock);
}
return count;
}
static ssize_t
set_a_clr_err(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
if (!iotg->otg.default_a)
return -1;
if (count > 2)
return -1;
if (buf[0] == '1') {
iotg->hsm.a_clr_err = 1;
dev_dbg(lnw->dev, "User request: a_clr_err = 1\n");
}
if (spin_trylock(&lnw->wq_lock)) {
langwell_update_transceiver();
spin_unlock(&lnw->wq_lock);
}
return count;
}
static int langwell_otg_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned long resource, len;
void __iomem *base = NULL;
int retval;
u32 val32;
struct langwell_otg *lnw;
char qname[] = "langwell_otg_queue";
retval = 0;
dev_dbg(&pdev->dev, "\notg controller is detected.\n");
if (pci_enable_device(pdev) < 0) {
retval = -ENODEV;
goto done;
}
lnw = kzalloc(sizeof *lnw, GFP_KERNEL);
if (lnw == NULL) {
retval = -ENOMEM;
goto done;
}
the_transceiver = lnw;
resource = pci_resource_start(pdev, 0);
len = pci_resource_len(pdev, 0);
if (!request_mem_region(resource, len, driver_name)) {
retval = -EBUSY;
goto err;
}
lnw->region = 1;
base = ioremap_nocache(resource, len);
if (base == NULL) {
retval = -EFAULT;
goto err;
}
lnw->iotg.base = base;
if (!request_mem_region(USBCFG_ADDR, USBCFG_LEN, driver_name)) {
retval = -EBUSY;
goto err;
}
lnw->cfg_region = 1;
base = ioremap_nocache(USBCFG_ADDR, USBCFG_LEN);
if (base == NULL) {
retval = -EFAULT;
goto err;
}
lnw->usbcfg = base;
if (!pdev->irq) {
dev_dbg(&pdev->dev, "No IRQ.\n");
retval = -ENODEV;
goto err;
}
lnw->qwork = create_singlethread_workqueue(qname);
if (!lnw->qwork) {
dev_dbg(&pdev->dev, "cannot create workqueue %s\n", qname);
retval = -ENOMEM;
goto err;
}
INIT_WORK(&lnw->work, langwell_otg_work);
lnw->dev = &pdev->dev;
lnw->iotg.otg.dev = lnw->dev;
lnw->iotg.otg.label = driver_name;
lnw->iotg.otg.set_host = langwell_otg_set_host;
lnw->iotg.otg.set_peripheral = langwell_otg_set_peripheral;
lnw->iotg.otg.set_power = langwell_otg_set_power;
lnw->iotg.otg.set_vbus = langwell_otg_set_vbus;
lnw->iotg.otg.start_srp = langwell_otg_start_srp;
lnw->iotg.otg.state = OTG_STATE_UNDEFINED;
if (otg_set_transceiver(&lnw->iotg.otg)) {
dev_dbg(lnw->dev, "can't set transceiver\n");
retval = -EBUSY;
goto err;
}
reset_otg();
init_hsm();
spin_lock_init(&lnw->lock);
spin_lock_init(&lnw->wq_lock);
INIT_LIST_HEAD(&active_timers);
retval = langwell_otg_init_timers(&lnw->iotg.hsm);
if (retval) {
dev_dbg(&pdev->dev, "Failed to init timers\n");
goto err;
}
init_timer(&lnw->hsm_timer);
ATOMIC_INIT_NOTIFIER_HEAD(&lnw->iotg.iotg_notifier);
lnw->iotg_notifier.notifier_call = langwell_otg_iotg_notify;
retval = intel_mid_otg_register_notifier(&lnw->iotg,
&lnw->iotg_notifier);
if (retval) {
dev_dbg(lnw->dev, "Failed to register notifier\n");
goto err;
}
if (request_irq(pdev->irq, otg_irq, IRQF_SHARED,
driver_name, lnw) != 0) {
dev_dbg(lnw->dev, "request interrupt %d failed\n", pdev->irq);
retval = -EBUSY;
goto err;
}
val32 = OTGSC_DPIE | OTGSC_BSEIE | OTGSC_BSVIE |
OTGSC_ASVIE | OTGSC_AVVIE | OTGSC_IDIE | OTGSC_IDPU;
writel(val32, lnw->iotg.base + CI_OTGSC);
retval = device_create_file(&pdev->dev, &dev_attr_registers);
if (retval < 0) {
dev_dbg(lnw->dev,
"Can't register sysfs attribute: %d\n", retval);
goto err;
}
retval = device_create_file(&pdev->dev, &dev_attr_hsm);
if (retval < 0) {
dev_dbg(lnw->dev, "Can't hsm sysfs attribute: %d\n", retval);
goto err;
}
retval = sysfs_create_group(&pdev->dev.kobj, &debug_dev_attr_group);
if (retval < 0) {
dev_dbg(lnw->dev,
"Can't register sysfs attr group: %d\n", retval);
goto err;
}
if (lnw->iotg.otg.state == OTG_STATE_A_IDLE)
langwell_update_transceiver();
return 0;
err:
if (the_transceiver)
langwell_otg_remove(pdev);
done:
return retval;
}
static void langwell_otg_remove(struct pci_dev *pdev)
{
struct langwell_otg *lnw = the_transceiver;
if (lnw->qwork) {
flush_workqueue(lnw->qwork);
destroy_workqueue(lnw->qwork);
}
intel_mid_otg_unregister_notifier(&lnw->iotg, &lnw->iotg_notifier);
langwell_otg_free_timers();
writel(0, lnw->iotg.base + CI_OTGSC);
if (pdev->irq)
free_irq(pdev->irq, lnw);
if (lnw->usbcfg)
iounmap(lnw->usbcfg);
if (lnw->cfg_region)
release_mem_region(USBCFG_ADDR, USBCFG_LEN);
if (lnw->iotg.base)
iounmap(lnw->iotg.base);
if (lnw->region)
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
otg_set_transceiver(NULL);
pci_disable_device(pdev);
sysfs_remove_group(&pdev->dev.kobj, &debug_dev_attr_group);
device_remove_file(&pdev->dev, &dev_attr_hsm);
device_remove_file(&pdev->dev, &dev_attr_registers);
kfree(lnw);
lnw = NULL;
}
static void transceiver_suspend(struct pci_dev *pdev)
{
pci_save_state(pdev);
pci_set_power_state(pdev, PCI_D3hot);
langwell_otg_phy_low_power(1);
}
static int langwell_otg_suspend(struct pci_dev *pdev, pm_message_t message)
{
struct langwell_otg *lnw = the_transceiver;
struct intel_mid_otg_xceiv *iotg = &lnw->iotg;
int ret = 0;
langwell_otg_intr(0);
if (pdev->irq)
free_irq(pdev->irq, lnw);
flush_workqueue(lnw->qwork);
destroy_workqueue(lnw->qwork);
lnw->qwork = NULL;
switch (iotg->otg.state) {
case OTG_STATE_A_WAIT_VFALL:
iotg->otg.state = OTG_STATE_A_IDLE;
case OTG_STATE_A_IDLE:
case OTG_STATE_B_IDLE:
case OTG_STATE_A_VBUS_ERR:
transceiver_suspend(pdev);
break;
case OTG_STATE_A_WAIT_VRISE:
langwell_otg_del_timer(a_wait_vrise_tmr);
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_A_WAIT_BCON:
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(&pdev->dev, "host driver has been removed.\n");
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_A_HOST:
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(&pdev->dev, "host driver has been removed.\n");
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_A_SUSPEND:
langwell_otg_del_timer(a_aidl_bdis_tmr);
langwell_otg_HABA(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(lnw->dev, "host driver has been removed.\n");
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_A_PERIPHERAL:
del_timer_sync(&lnw->hsm_timer);
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(&pdev->dev,
"client driver has been removed.\n");
iotg->hsm.a_srp_det = 0;
iotg->otg.set_vbus(&iotg->otg, false);
iotg->otg.state = OTG_STATE_A_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_B_HOST:
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(&pdev->dev, "host driver has been removed.\n");
iotg->hsm.b_bus_req = 0;
iotg->otg.state = OTG_STATE_B_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_B_PERIPHERAL:
if (lnw->iotg.stop_peripheral)
lnw->iotg.stop_peripheral(&lnw->iotg);
else
dev_dbg(&pdev->dev,
"client driver has been removed.\n");
iotg->otg.state = OTG_STATE_B_IDLE;
transceiver_suspend(pdev);
break;
case OTG_STATE_B_WAIT_ACON:
del_timer_sync(&lnw->hsm_timer);
langwell_otg_HAAR(0);
if (lnw->iotg.stop_host)
lnw->iotg.stop_host(&lnw->iotg);
else
dev_dbg(&pdev->dev, "host driver has been removed.\n");
iotg->hsm.b_bus_req = 0;
iotg->otg.state = OTG_STATE_B_IDLE;
transceiver_suspend(pdev);
break;
default:
dev_dbg(lnw->dev, "error state before suspend\n");
break;
}
return ret;
}
static void transceiver_resume(struct pci_dev *pdev)
{
pci_restore_state(pdev);
pci_set_power_state(pdev, PCI_D0);
}
static int langwell_otg_resume(struct pci_dev *pdev)
{
struct langwell_otg *lnw = the_transceiver;
int ret = 0;
transceiver_resume(pdev);
lnw->qwork = create_singlethread_workqueue("langwell_otg_queue");
if (!lnw->qwork) {
dev_dbg(&pdev->dev, "cannot create langwell otg workqueuen");
ret = -ENOMEM;
goto error;
}
if (request_irq(pdev->irq, otg_irq, IRQF_SHARED,
driver_name, lnw) != 0) {
dev_dbg(&pdev->dev, "request interrupt %d failed\n", pdev->irq);
ret = -EBUSY;
goto error;
}
langwell_otg_intr(1);
update_hsm();
langwell_update_transceiver();
return ret;
error:
langwell_otg_intr(0);
transceiver_suspend(pdev);
return ret;
}
static int __init langwell_otg_init(void)
{
return pci_register_driver(&otg_pci_driver);
}
static void __exit langwell_otg_cleanup(void)
{
pci_unregister_driver(&otg_pci_driver);
}
