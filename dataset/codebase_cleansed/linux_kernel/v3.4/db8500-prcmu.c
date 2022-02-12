int db8500_prcmu_enable_dsipll(void)
{
int i;
writel(PRCMU_RESET_DSIPLL, PRCM_APE_RESETN_CLR);
writel(PRCMU_UNCLAMP_DSIPLL, PRCM_MMIP_LS_CLAMP_CLR);
writel(PRCMU_PLLDSI_FREQ_SETTING, PRCM_PLLDSI_FREQ);
writel(PRCMU_DSI_PLLOUT_SEL_SETTING, PRCM_DSI_PLLOUT_SEL);
writel(PRCMU_ENABLE_ESCAPE_CLOCK_DIV, PRCM_DSITVCLK_DIV);
writel(PRCMU_ENABLE_PLLDSI, PRCM_PLLDSI_ENABLE);
writel(PRCMU_DSI_RESET_SW, PRCM_DSI_SW_RESET);
for (i = 0; i < 10; i++) {
if ((readl(PRCM_PLLDSI_LOCKP) & PRCMU_PLLDSI_LOCKP_LOCKED)
== PRCMU_PLLDSI_LOCKP_LOCKED)
break;
udelay(100);
}
writel(PRCMU_RESET_DSIPLL, PRCM_APE_RESETN_SET);
return 0;
}
int db8500_prcmu_disable_dsipll(void)
{
writel(PRCMU_DISABLE_PLLDSI, PRCM_PLLDSI_ENABLE);
writel(PRCMU_DISABLE_ESCAPE_CLOCK_DIV, PRCM_DSITVCLK_DIV);
return 0;
}
int db8500_prcmu_set_display_clocks(void)
{
unsigned long flags;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
writel(PRCMU_DSI_CLOCK_SETTING, PRCM_HDMICLK_MGT);
writel(PRCMU_DSI_LP_CLOCK_SETTING, PRCM_TVCLK_MGT);
writel(PRCMU_DPI_CLOCK_SETTING, PRCM_LCDCLK_MGT);
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
return 0;
}
u32 db8500_prcmu_read(unsigned int reg)
{
return readl(_PRCMU_BASE + reg);
}
void db8500_prcmu_write(unsigned int reg, u32 value)
{
unsigned long flags;
spin_lock_irqsave(&prcmu_lock, flags);
writel(value, (_PRCMU_BASE + reg));
spin_unlock_irqrestore(&prcmu_lock, flags);
}
void db8500_prcmu_write_masked(unsigned int reg, u32 mask, u32 value)
{
u32 val;
unsigned long flags;
spin_lock_irqsave(&prcmu_lock, flags);
val = readl(_PRCMU_BASE + reg);
val = ((val & ~mask) | (value & mask));
writel(val, (_PRCMU_BASE + reg));
spin_unlock_irqrestore(&prcmu_lock, flags);
}
struct prcmu_fw_version *prcmu_get_fw_version(void)
{
return fw_info.valid ? &fw_info.version : NULL;
}
bool prcmu_has_arm_maxopp(void)
{
return (readb(tcdm_base + PRCM_AVS_VARM_MAX_OPP) &
PRCM_AVS_ISMODEENABLE_MASK) == PRCM_AVS_ISMODEENABLE_MASK;
}
int prcmu_get_boot_status(void)
{
return readb(tcdm_base + PRCM_BOOT_STATUS);
}
int prcmu_set_rc_a2p(enum romcode_write val)
{
if (val < RDY_2_DS || val > RDY_2_XP70_RST)
return -EINVAL;
writeb(val, (tcdm_base + PRCM_ROMCODE_A2P));
return 0;
}
enum romcode_read prcmu_get_rc_p2a(void)
{
return readb(tcdm_base + PRCM_ROMCODE_P2A);
}
enum ap_pwrst prcmu_get_xp70_current_state(void)
{
return readb(tcdm_base + PRCM_XP70_CUR_PWR_STATE);
}
int prcmu_config_clkout(u8 clkout, u8 source, u8 div)
{
static int requests[2];
int r = 0;
unsigned long flags;
u32 val;
u32 bits;
u32 mask;
u32 div_mask;
BUG_ON(clkout > 1);
BUG_ON(div > 63);
BUG_ON((clkout == 0) && (source > PRCMU_CLKSRC_CLK009));
if (!div && !requests[clkout])
return -EINVAL;
switch (clkout) {
case 0:
div_mask = PRCM_CLKOCR_CLKODIV0_MASK;
mask = (PRCM_CLKOCR_CLKODIV0_MASK | PRCM_CLKOCR_CLKOSEL0_MASK);
bits = ((source << PRCM_CLKOCR_CLKOSEL0_SHIFT) |
(div << PRCM_CLKOCR_CLKODIV0_SHIFT));
break;
case 1:
div_mask = PRCM_CLKOCR_CLKODIV1_MASK;
mask = (PRCM_CLKOCR_CLKODIV1_MASK | PRCM_CLKOCR_CLKOSEL1_MASK |
PRCM_CLKOCR_CLK1TYPE);
bits = ((source << PRCM_CLKOCR_CLKOSEL1_SHIFT) |
(div << PRCM_CLKOCR_CLKODIV1_SHIFT));
break;
}
bits &= mask;
spin_lock_irqsave(&clkout_lock, flags);
val = readl(PRCM_CLKOCR);
if (val & div_mask) {
if (div) {
if ((val & mask) != bits) {
r = -EBUSY;
goto unlock_and_return;
}
} else {
if ((val & mask & ~div_mask) != bits) {
r = -EINVAL;
goto unlock_and_return;
}
}
}
writel((bits | (val & ~mask)), PRCM_CLKOCR);
requests[clkout] += (div ? 1 : -1);
unlock_and_return:
spin_unlock_irqrestore(&clkout_lock, flags);
return r;
}
int db8500_prcmu_set_power_state(u8 state, bool keep_ulp_clk, bool keep_ap_pll)
{
unsigned long flags;
BUG_ON((state < PRCMU_AP_SLEEP) || (PRCMU_AP_DEEP_IDLE < state));
spin_lock_irqsave(&mb0_transfer.lock, flags);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(0))
cpu_relax();
writeb(MB0H_POWER_STATE_TRANS, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB0));
writeb(state, (tcdm_base + PRCM_REQ_MB0_AP_POWER_STATE));
writeb((keep_ap_pll ? 1 : 0), (tcdm_base + PRCM_REQ_MB0_AP_PLL_STATE));
writeb((keep_ulp_clk ? 1 : 0),
(tcdm_base + PRCM_REQ_MB0_ULP_CLOCK_STATE));
writeb(0, (tcdm_base + PRCM_REQ_MB0_DO_NOT_WFI));
writel(MBOX_BIT(0), PRCM_MBOX_CPU_SET);
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
return 0;
}
u8 db8500_prcmu_get_power_state_result(void)
{
return readb(tcdm_base + PRCM_ACK_MB0_AP_PWRSTTR_STATUS);
}
int db8500_prcmu_gic_decouple(void)
{
u32 val = readl(PRCM_A9_MASK_REQ);
writel(val | PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ,
PRCM_A9_MASK_REQ);
readl(PRCM_A9_MASK_REQ);
udelay(1);
return 0;
}
int db8500_prcmu_gic_recouple(void)
{
u32 val = readl(PRCM_A9_MASK_REQ);
writel(val & ~PRCM_A9_MASK_REQ_PRCM_A9_MASK_REQ, PRCM_A9_MASK_REQ);
return 0;
}
bool db8500_prcmu_gic_pending_irq(void)
{
u32 pr;
u32 er;
void __iomem *dist_base = __io_address(U8500_GIC_DIST_BASE);
int i;
for (i = 0; i < PRCMU_GIC_NUMBER_REGS; i++) {
pr = readl_relaxed(dist_base + GIC_DIST_PENDING_SET + i * 4);
er = readl_relaxed(dist_base + GIC_DIST_ENABLE_SET + i * 4);
if (pr & er)
return true;
}
return false;
}
bool db8500_prcmu_pending_irq(void)
{
u32 it, im;
int i;
for (i = 0; i < PRCMU_GIC_NUMBER_REGS - 1; i++) {
it = readl(PRCM_ARMITVAL31TO0 + i * 4);
im = readl(PRCM_ARMITMSK31TO0 + i * 4);
if (it & im)
return true;
}
return false;
}
bool db8500_prcmu_is_cpu_in_wfi(int cpu)
{
return readl(PRCM_ARM_WFI_STANDBY) & cpu ? PRCM_ARM_WFI_STANDBY_WFI1 :
PRCM_ARM_WFI_STANDBY_WFI0;
}
int db8500_prcmu_copy_gic_settings(void)
{
u32 er;
void __iomem *dist_base = __io_address(U8500_GIC_DIST_BASE);
int i;
for (i = 0; i < PRCMU_GIC_NUMBER_REGS - 1; i++) {
er = readl_relaxed(dist_base +
GIC_DIST_ENABLE_SET + (i + 1) * 4);
writel(er, PRCM_ARMITMSK31TO0 + i * 4);
}
return 0;
}
static void config_wakeups(void)
{
const u8 header[2] = {
MB0H_CONFIG_WAKEUPS_EXE,
MB0H_CONFIG_WAKEUPS_SLEEP
};
static u32 last_dbb_events;
static u32 last_abb_events;
u32 dbb_events;
u32 abb_events;
unsigned int i;
dbb_events = mb0_transfer.req.dbb_irqs | mb0_transfer.req.dbb_wakeups;
dbb_events |= (WAKEUP_BIT_AC_WAKE_ACK | WAKEUP_BIT_AC_SLEEP_ACK);
abb_events = mb0_transfer.req.abb_events;
if ((dbb_events == last_dbb_events) && (abb_events == last_abb_events))
return;
for (i = 0; i < 2; i++) {
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(0))
cpu_relax();
writel(dbb_events, (tcdm_base + PRCM_REQ_MB0_WAKEUP_8500));
writel(abb_events, (tcdm_base + PRCM_REQ_MB0_WAKEUP_4500));
writeb(header[i], (tcdm_base + PRCM_MBOX_HEADER_REQ_MB0));
writel(MBOX_BIT(0), PRCM_MBOX_CPU_SET);
}
last_dbb_events = dbb_events;
last_abb_events = abb_events;
}
void db8500_prcmu_enable_wakeups(u32 wakeups)
{
unsigned long flags;
u32 bits;
int i;
BUG_ON(wakeups != (wakeups & VALID_WAKEUPS));
for (i = 0, bits = 0; i < NUM_PRCMU_WAKEUP_INDICES; i++) {
if (wakeups & BIT(i))
bits |= prcmu_wakeup_bit[i];
}
spin_lock_irqsave(&mb0_transfer.lock, flags);
mb0_transfer.req.dbb_wakeups = bits;
config_wakeups();
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
}
void db8500_prcmu_config_abb_event_readout(u32 abb_events)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.lock, flags);
mb0_transfer.req.abb_events = abb_events;
config_wakeups();
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
}
void db8500_prcmu_get_abb_event_buffer(void __iomem **buf)
{
if (readb(tcdm_base + PRCM_ACK_MB0_READ_POINTER) & 1)
*buf = (tcdm_base + PRCM_ACK_MB0_WAKEUP_1_4500);
else
*buf = (tcdm_base + PRCM_ACK_MB0_WAKEUP_0_4500);
}
int db8500_prcmu_set_arm_opp(u8 opp)
{
int r;
if (opp < ARM_NO_CHANGE || opp > ARM_EXTCLK)
return -EINVAL;
r = 0;
mutex_lock(&mb1_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_ARM_APE_OPP, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writeb(opp, (tcdm_base + PRCM_REQ_MB1_ARM_OPP));
writeb(APE_NO_CHANGE, (tcdm_base + PRCM_REQ_MB1_APE_OPP));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if ((mb1_transfer.ack.header != MB1H_ARM_APE_OPP) ||
(mb1_transfer.ack.arm_opp != opp))
r = -EIO;
mutex_unlock(&mb1_transfer.lock);
return r;
}
int db8500_prcmu_get_arm_opp(void)
{
return readb(tcdm_base + PRCM_ACK_MB1_CURRENT_ARM_OPP);
}
int db8500_prcmu_get_ddr_opp(void)
{
return readb(PRCM_DDR_SUBSYS_APE_MINBW);
}
int db8500_prcmu_set_ddr_opp(u8 opp)
{
if (opp < DDR_100_OPP || opp > DDR_25_OPP)
return -EINVAL;
if (cpu_is_u8500v20_or_later() && !cpu_is_u8500v20())
writeb(opp, PRCM_DDR_SUBSYS_APE_MINBW);
return 0;
}
static void request_even_slower_clocks(bool enable)
{
void __iomem *clock_reg[] = {
PRCM_ACLK_MGT,
PRCM_DMACLK_MGT
};
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
for (i = 0; i < ARRAY_SIZE(clock_reg); i++) {
u32 val;
u32 div;
val = readl(clock_reg[i]);
div = (val & PRCM_CLK_MGT_CLKPLLDIV_MASK);
if (enable) {
if ((div <= 1) || (div > 15)) {
pr_err("prcmu: Bad clock divider %d in %s\n",
div, __func__);
goto unlock_and_return;
}
div <<= 1;
} else {
if (div <= 2)
goto unlock_and_return;
div >>= 1;
}
val = ((val & ~PRCM_CLK_MGT_CLKPLLDIV_MASK) |
(div & PRCM_CLK_MGT_CLKPLLDIV_MASK));
writel(val, clock_reg[i]);
}
unlock_and_return:
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
}
int db8500_prcmu_set_ape_opp(u8 opp)
{
int r = 0;
if (opp == mb1_transfer.ape_opp)
return 0;
mutex_lock(&mb1_transfer.lock);
if (mb1_transfer.ape_opp == APE_50_PARTLY_25_OPP)
request_even_slower_clocks(false);
if ((opp != APE_100_OPP) && (mb1_transfer.ape_opp != APE_100_OPP))
goto skip_message;
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_ARM_APE_OPP, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writeb(ARM_NO_CHANGE, (tcdm_base + PRCM_REQ_MB1_ARM_OPP));
writeb(((opp == APE_50_PARTLY_25_OPP) ? APE_50_OPP : opp),
(tcdm_base + PRCM_REQ_MB1_APE_OPP));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if ((mb1_transfer.ack.header != MB1H_ARM_APE_OPP) ||
(mb1_transfer.ack.ape_opp != opp))
r = -EIO;
skip_message:
if ((!r && (opp == APE_50_PARTLY_25_OPP)) ||
(r && (mb1_transfer.ape_opp == APE_50_PARTLY_25_OPP)))
request_even_slower_clocks(true);
if (!r)
mb1_transfer.ape_opp = opp;
mutex_unlock(&mb1_transfer.lock);
return r;
}
int db8500_prcmu_get_ape_opp(void)
{
return readb(tcdm_base + PRCM_ACK_MB1_CURRENT_APE_OPP);
}
int prcmu_request_ape_opp_100_voltage(bool enable)
{
int r = 0;
u8 header;
static unsigned int requests;
mutex_lock(&mb1_transfer.lock);
if (enable) {
if (0 != requests++)
goto unlock_and_return;
header = MB1H_REQUEST_APE_OPP_100_VOLT;
} else {
if (requests == 0) {
r = -EIO;
goto unlock_and_return;
} else if (1 != requests--) {
goto unlock_and_return;
}
header = MB1H_RELEASE_APE_OPP_100_VOLT;
}
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(header, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if ((mb1_transfer.ack.header != header) ||
((mb1_transfer.ack.ape_voltage_status & BIT(0)) != 0))
r = -EIO;
unlock_and_return:
mutex_unlock(&mb1_transfer.lock);
return r;
}
int prcmu_release_usb_wakeup_state(void)
{
int r = 0;
mutex_lock(&mb1_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_RELEASE_USB_WAKEUP,
(tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if ((mb1_transfer.ack.header != MB1H_RELEASE_USB_WAKEUP) ||
((mb1_transfer.ack.ape_voltage_status & BIT(0)) != 0))
r = -EIO;
mutex_unlock(&mb1_transfer.lock);
return r;
}
static int request_pll(u8 clock, bool enable)
{
int r = 0;
if (clock == PRCMU_PLLSOC0)
clock = (enable ? PLL_SOC0_ON : PLL_SOC0_OFF);
else if (clock == PRCMU_PLLSOC1)
clock = (enable ? PLL_SOC1_ON : PLL_SOC1_OFF);
else
return -EINVAL;
mutex_lock(&mb1_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_PLL_ON_OFF, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writeb(clock, (tcdm_base + PRCM_REQ_MB1_PLL_ON_OFF));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if (mb1_transfer.ack.header != MB1H_PLL_ON_OFF)
r = -EIO;
mutex_unlock(&mb1_transfer.lock);
return r;
}
int db8500_prcmu_set_epod(u16 epod_id, u8 epod_state)
{
int r = 0;
bool ram_retention = false;
int i;
BUG_ON(epod_id >= NUM_EPOD_ID);
switch (epod_id) {
case EPOD_ID_SVAMMDSP:
case EPOD_ID_SIAMMDSP:
case EPOD_ID_ESRAM12:
case EPOD_ID_ESRAM34:
ram_retention = true;
break;
}
BUG_ON(epod_state > EPOD_STATE_ON);
BUG_ON(epod_state == EPOD_STATE_RAMRET && !ram_retention);
mutex_lock(&mb2_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(2))
cpu_relax();
for (i = 0; i < NUM_EPOD_ID; i++)
writeb(EPOD_STATE_NO_CHANGE, (tcdm_base + PRCM_REQ_MB2 + i));
writeb(epod_state, (tcdm_base + PRCM_REQ_MB2 + epod_id));
writeb(MB2H_DPS, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB2));
writel(MBOX_BIT(2), PRCM_MBOX_CPU_SET);
if (!wait_for_completion_timeout(&mb2_transfer.work,
msecs_to_jiffies(20000))) {
pr_err("prcmu: %s timed out (20 s) waiting for a reply.\n",
__func__);
r = -EIO;
goto unlock_and_return;
}
if (mb2_transfer.ack.status != HWACC_PWR_ST_OK)
r = -EIO;
unlock_and_return:
mutex_unlock(&mb2_transfer.lock);
return r;
}
void prcmu_configure_auto_pm(struct prcmu_auto_pm_config *sleep,
struct prcmu_auto_pm_config *idle)
{
u32 sleep_cfg;
u32 idle_cfg;
unsigned long flags;
BUG_ON((sleep == NULL) || (idle == NULL));
sleep_cfg = (sleep->sva_auto_pm_enable & 0xF);
sleep_cfg = ((sleep_cfg << 4) | (sleep->sia_auto_pm_enable & 0xF));
sleep_cfg = ((sleep_cfg << 8) | (sleep->sva_power_on & 0xFF));
sleep_cfg = ((sleep_cfg << 8) | (sleep->sia_power_on & 0xFF));
sleep_cfg = ((sleep_cfg << 4) | (sleep->sva_policy & 0xF));
sleep_cfg = ((sleep_cfg << 4) | (sleep->sia_policy & 0xF));
idle_cfg = (idle->sva_auto_pm_enable & 0xF);
idle_cfg = ((idle_cfg << 4) | (idle->sia_auto_pm_enable & 0xF));
idle_cfg = ((idle_cfg << 8) | (idle->sva_power_on & 0xFF));
idle_cfg = ((idle_cfg << 8) | (idle->sia_power_on & 0xFF));
idle_cfg = ((idle_cfg << 4) | (idle->sva_policy & 0xF));
idle_cfg = ((idle_cfg << 4) | (idle->sia_policy & 0xF));
spin_lock_irqsave(&mb2_transfer.auto_pm_lock, flags);
writel(sleep_cfg, (tcdm_base + PRCM_REQ_MB2_AUTO_PM_SLEEP));
writel(idle_cfg, (tcdm_base + PRCM_REQ_MB2_AUTO_PM_IDLE));
mb2_transfer.auto_pm_enabled =
((sleep->sva_auto_pm_enable == PRCMU_AUTO_PM_ON) ||
(sleep->sia_auto_pm_enable == PRCMU_AUTO_PM_ON) ||
(idle->sva_auto_pm_enable == PRCMU_AUTO_PM_ON) ||
(idle->sia_auto_pm_enable == PRCMU_AUTO_PM_ON));
spin_unlock_irqrestore(&mb2_transfer.auto_pm_lock, flags);
}
bool prcmu_is_auto_pm_enabled(void)
{
return mb2_transfer.auto_pm_enabled;
}
static int request_sysclk(bool enable)
{
int r;
unsigned long flags;
r = 0;
mutex_lock(&mb3_transfer.sysclk_lock);
spin_lock_irqsave(&mb3_transfer.lock, flags);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(3))
cpu_relax();
writeb((enable ? ON : OFF), (tcdm_base + PRCM_REQ_MB3_SYSCLK_MGT));
writeb(MB3H_SYSCLK, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB3));
writel(MBOX_BIT(3), PRCM_MBOX_CPU_SET);
spin_unlock_irqrestore(&mb3_transfer.lock, flags);
if (enable && !wait_for_completion_timeout(&mb3_transfer.sysclk_work,
msecs_to_jiffies(20000))) {
pr_err("prcmu: %s timed out (20 s) waiting for a reply.\n",
__func__);
r = -EIO;
}
mutex_unlock(&mb3_transfer.sysclk_lock);
return r;
}
static int request_timclk(bool enable)
{
u32 val = (PRCM_TCR_DOZE_MODE | PRCM_TCR_TENSEL_MASK);
if (!enable)
val |= PRCM_TCR_STOP_TIMERS;
writel(val, PRCM_TCR);
return 0;
}
static int request_clock(u8 clock, bool enable)
{
u32 val;
unsigned long flags;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
val = readl(clk_mgt[clock].reg);
if (enable) {
val |= (PRCM_CLK_MGT_CLKEN | clk_mgt[clock].pllsw);
} else {
clk_mgt[clock].pllsw = (val & PRCM_CLK_MGT_CLKPLLSW_MASK);
val &= ~(PRCM_CLK_MGT_CLKEN | PRCM_CLK_MGT_CLKPLLSW_MASK);
}
writel(val, clk_mgt[clock].reg);
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
return 0;
}
static int request_sga_clock(u8 clock, bool enable)
{
u32 val;
int ret;
if (enable) {
val = readl(PRCM_CGATING_BYPASS);
writel(val | PRCM_CGATING_BYPASS_ICN2, PRCM_CGATING_BYPASS);
}
ret = request_clock(clock, enable);
if (!ret && !enable) {
val = readl(PRCM_CGATING_BYPASS);
writel(val & ~PRCM_CGATING_BYPASS_ICN2, PRCM_CGATING_BYPASS);
}
return ret;
}
static inline bool plldsi_locked(void)
{
return (readl(PRCM_PLLDSI_LOCKP) &
(PRCM_PLLDSI_LOCKP_PRCM_PLLDSI_LOCKP10 |
PRCM_PLLDSI_LOCKP_PRCM_PLLDSI_LOCKP3)) ==
(PRCM_PLLDSI_LOCKP_PRCM_PLLDSI_LOCKP10 |
PRCM_PLLDSI_LOCKP_PRCM_PLLDSI_LOCKP3);
}
static int request_plldsi(bool enable)
{
int r = 0;
u32 val;
writel((PRCM_MMIP_LS_CLAMP_DSIPLL_CLAMP |
PRCM_MMIP_LS_CLAMP_DSIPLL_CLAMPI), (enable ?
PRCM_MMIP_LS_CLAMP_CLR : PRCM_MMIP_LS_CLAMP_SET));
val = readl(PRCM_PLLDSI_ENABLE);
if (enable)
val |= PRCM_PLLDSI_ENABLE_PRCM_PLLDSI_ENABLE;
else
val &= ~PRCM_PLLDSI_ENABLE_PRCM_PLLDSI_ENABLE;
writel(val, PRCM_PLLDSI_ENABLE);
if (enable) {
unsigned int i;
bool locked = plldsi_locked();
for (i = 10; !locked && (i > 0); --i) {
udelay(100);
locked = plldsi_locked();
}
if (locked) {
writel(PRCM_APE_RESETN_DSIPLL_RESETN,
PRCM_APE_RESETN_SET);
} else {
writel((PRCM_MMIP_LS_CLAMP_DSIPLL_CLAMP |
PRCM_MMIP_LS_CLAMP_DSIPLL_CLAMPI),
PRCM_MMIP_LS_CLAMP_SET);
val &= ~PRCM_PLLDSI_ENABLE_PRCM_PLLDSI_ENABLE;
writel(val, PRCM_PLLDSI_ENABLE);
r = -EAGAIN;
}
} else {
writel(PRCM_APE_RESETN_DSIPLL_RESETN, PRCM_APE_RESETN_CLR);
}
return r;
}
static int request_dsiclk(u8 n, bool enable)
{
u32 val;
val = readl(PRCM_DSI_PLLOUT_SEL);
val &= ~dsiclk[n].divsel_mask;
val |= ((enable ? dsiclk[n].divsel : PRCM_DSI_PLLOUT_SEL_OFF) <<
dsiclk[n].divsel_shift);
writel(val, PRCM_DSI_PLLOUT_SEL);
return 0;
}
static int request_dsiescclk(u8 n, bool enable)
{
u32 val;
val = readl(PRCM_DSITVCLK_DIV);
enable ? (val |= dsiescclk[n].en) : (val &= ~dsiescclk[n].en);
writel(val, PRCM_DSITVCLK_DIV);
return 0;
}
int db8500_prcmu_request_clock(u8 clock, bool enable)
{
if (clock == PRCMU_SGACLK)
return request_sga_clock(clock, enable);
else if (clock < PRCMU_NUM_REG_CLOCKS)
return request_clock(clock, enable);
else if (clock == PRCMU_TIMCLK)
return request_timclk(enable);
else if ((clock == PRCMU_DSI0CLK) || (clock == PRCMU_DSI1CLK))
return request_dsiclk((clock - PRCMU_DSI0CLK), enable);
else if ((PRCMU_DSI0ESCCLK <= clock) && (clock <= PRCMU_DSI2ESCCLK))
return request_dsiescclk((clock - PRCMU_DSI0ESCCLK), enable);
else if (clock == PRCMU_PLLDSI)
return request_plldsi(enable);
else if (clock == PRCMU_SYSCLK)
return request_sysclk(enable);
else if ((clock == PRCMU_PLLSOC0) || (clock == PRCMU_PLLSOC1))
return request_pll(clock, enable);
else
return -EINVAL;
}
static unsigned long pll_rate(void __iomem *reg, unsigned long src_rate,
int branch)
{
u64 rate;
u32 val;
u32 d;
u32 div = 1;
val = readl(reg);
rate = src_rate;
rate *= ((val & PRCM_PLL_FREQ_D_MASK) >> PRCM_PLL_FREQ_D_SHIFT);
d = ((val & PRCM_PLL_FREQ_N_MASK) >> PRCM_PLL_FREQ_N_SHIFT);
if (d > 1)
div *= d;
d = ((val & PRCM_PLL_FREQ_R_MASK) >> PRCM_PLL_FREQ_R_SHIFT);
if (d > 1)
div *= d;
if (val & PRCM_PLL_FREQ_SELDIV2)
div *= 2;
if ((branch == PLL_FIX) || ((branch == PLL_DIV) &&
(val & PRCM_PLL_FREQ_DIV2EN) &&
((reg == PRCM_PLLSOC0_FREQ) ||
(reg == PRCM_PLLDDR_FREQ))))
div *= 2;
(void)do_div(rate, div);
return (unsigned long)rate;
}
static unsigned long clock_rate(u8 clock)
{
u32 val;
u32 pllsw;
unsigned long rate = ROOT_CLOCK_RATE;
val = readl(clk_mgt[clock].reg);
if (val & PRCM_CLK_MGT_CLK38) {
if (clk_mgt[clock].clk38div && (val & PRCM_CLK_MGT_CLK38DIV))
rate /= 2;
return rate;
}
val |= clk_mgt[clock].pllsw;
pllsw = (val & PRCM_CLK_MGT_CLKPLLSW_MASK);
if (pllsw == PRCM_CLK_MGT_CLKPLLSW_SOC0)
rate = pll_rate(PRCM_PLLSOC0_FREQ, rate, clk_mgt[clock].branch);
else if (pllsw == PRCM_CLK_MGT_CLKPLLSW_SOC1)
rate = pll_rate(PRCM_PLLSOC1_FREQ, rate, clk_mgt[clock].branch);
else if (pllsw == PRCM_CLK_MGT_CLKPLLSW_DDR)
rate = pll_rate(PRCM_PLLDDR_FREQ, rate, clk_mgt[clock].branch);
else
return 0;
if ((clock == PRCMU_SGACLK) &&
(val & PRCM_SGACLK_MGT_SGACLKDIV_BY_2_5_EN)) {
u64 r = (rate * 10);
(void)do_div(r, 25);
return (unsigned long)r;
}
val &= PRCM_CLK_MGT_CLKPLLDIV_MASK;
if (val)
return rate / val;
else
return 0;
}
static unsigned long dsiclk_rate(u8 n)
{
u32 divsel;
u32 div = 1;
divsel = readl(PRCM_DSI_PLLOUT_SEL);
divsel = ((divsel & dsiclk[n].divsel_mask) >> dsiclk[n].divsel_shift);
if (divsel == PRCM_DSI_PLLOUT_SEL_OFF)
divsel = dsiclk[n].divsel;
switch (divsel) {
case PRCM_DSI_PLLOUT_SEL_PHI_4:
div *= 2;
case PRCM_DSI_PLLOUT_SEL_PHI_2:
div *= 2;
case PRCM_DSI_PLLOUT_SEL_PHI:
return pll_rate(PRCM_PLLDSI_FREQ, clock_rate(PRCMU_HDMICLK),
PLL_RAW) / div;
default:
return 0;
}
}
static unsigned long dsiescclk_rate(u8 n)
{
u32 div;
div = readl(PRCM_DSITVCLK_DIV);
div = ((div & dsiescclk[n].div_mask) >> (dsiescclk[n].div_shift));
return clock_rate(PRCMU_TVCLK) / max((u32)1, div);
}
unsigned long prcmu_clock_rate(u8 clock)
{
if (clock < PRCMU_NUM_REG_CLOCKS)
return clock_rate(clock);
else if (clock == PRCMU_TIMCLK)
return ROOT_CLOCK_RATE / 16;
else if (clock == PRCMU_SYSCLK)
return ROOT_CLOCK_RATE;
else if (clock == PRCMU_PLLSOC0)
return pll_rate(PRCM_PLLSOC0_FREQ, ROOT_CLOCK_RATE, PLL_RAW);
else if (clock == PRCMU_PLLSOC1)
return pll_rate(PRCM_PLLSOC1_FREQ, ROOT_CLOCK_RATE, PLL_RAW);
else if (clock == PRCMU_PLLDDR)
return pll_rate(PRCM_PLLDDR_FREQ, ROOT_CLOCK_RATE, PLL_RAW);
else if (clock == PRCMU_PLLDSI)
return pll_rate(PRCM_PLLDSI_FREQ, clock_rate(PRCMU_HDMICLK),
PLL_RAW);
else if ((clock == PRCMU_DSI0CLK) || (clock == PRCMU_DSI1CLK))
return dsiclk_rate(clock - PRCMU_DSI0CLK);
else if ((PRCMU_DSI0ESCCLK <= clock) && (clock <= PRCMU_DSI2ESCCLK))
return dsiescclk_rate(clock - PRCMU_DSI0ESCCLK);
else
return 0;
}
static unsigned long clock_source_rate(u32 clk_mgt_val, int branch)
{
if (clk_mgt_val & PRCM_CLK_MGT_CLK38)
return ROOT_CLOCK_RATE;
clk_mgt_val &= PRCM_CLK_MGT_CLKPLLSW_MASK;
if (clk_mgt_val == PRCM_CLK_MGT_CLKPLLSW_SOC0)
return pll_rate(PRCM_PLLSOC0_FREQ, ROOT_CLOCK_RATE, branch);
else if (clk_mgt_val == PRCM_CLK_MGT_CLKPLLSW_SOC1)
return pll_rate(PRCM_PLLSOC1_FREQ, ROOT_CLOCK_RATE, branch);
else if (clk_mgt_val == PRCM_CLK_MGT_CLKPLLSW_DDR)
return pll_rate(PRCM_PLLDDR_FREQ, ROOT_CLOCK_RATE, branch);
else
return 0;
}
static u32 clock_divider(unsigned long src_rate, unsigned long rate)
{
u32 div;
div = (src_rate / rate);
if (div == 0)
return 1;
if (rate < (src_rate / div))
div++;
return div;
}
static long round_clock_rate(u8 clock, unsigned long rate)
{
u32 val;
u32 div;
unsigned long src_rate;
long rounded_rate;
val = readl(clk_mgt[clock].reg);
src_rate = clock_source_rate((val | clk_mgt[clock].pllsw),
clk_mgt[clock].branch);
div = clock_divider(src_rate, rate);
if (val & PRCM_CLK_MGT_CLK38) {
if (clk_mgt[clock].clk38div) {
if (div > 2)
div = 2;
} else {
div = 1;
}
} else if ((clock == PRCMU_SGACLK) && (div == 3)) {
u64 r = (src_rate * 10);
(void)do_div(r, 25);
if (r <= rate)
return (unsigned long)r;
}
rounded_rate = (src_rate / min(div, (u32)31));
return rounded_rate;
}
static long round_plldsi_rate(unsigned long rate)
{
long rounded_rate = 0;
unsigned long src_rate;
unsigned long rem;
u32 r;
src_rate = clock_rate(PRCMU_HDMICLK);
rem = rate;
for (r = 7; (rem > 0) && (r > 0); r--) {
u64 d;
d = (r * rate);
(void)do_div(d, src_rate);
if (d < 6)
d = 6;
else if (d > 255)
d = 255;
d *= src_rate;
if (((2 * d) < (r * MIN_PLL_VCO_RATE)) ||
((r * MAX_PLL_VCO_RATE) < (2 * d)))
continue;
(void)do_div(d, r);
if (rate < d) {
if (rounded_rate == 0)
rounded_rate = (long)d;
break;
}
if ((rate - d) < rem) {
rem = (rate - d);
rounded_rate = (long)d;
}
}
return rounded_rate;
}
static long round_dsiclk_rate(unsigned long rate)
{
u32 div;
unsigned long src_rate;
long rounded_rate;
src_rate = pll_rate(PRCM_PLLDSI_FREQ, clock_rate(PRCMU_HDMICLK),
PLL_RAW);
div = clock_divider(src_rate, rate);
rounded_rate = (src_rate / ((div > 2) ? 4 : div));
return rounded_rate;
}
static long round_dsiescclk_rate(unsigned long rate)
{
u32 div;
unsigned long src_rate;
long rounded_rate;
src_rate = clock_rate(PRCMU_TVCLK);
div = clock_divider(src_rate, rate);
rounded_rate = (src_rate / min(div, (u32)255));
return rounded_rate;
}
long prcmu_round_clock_rate(u8 clock, unsigned long rate)
{
if (clock < PRCMU_NUM_REG_CLOCKS)
return round_clock_rate(clock, rate);
else if (clock == PRCMU_PLLDSI)
return round_plldsi_rate(rate);
else if ((clock == PRCMU_DSI0CLK) || (clock == PRCMU_DSI1CLK))
return round_dsiclk_rate(rate);
else if ((PRCMU_DSI0ESCCLK <= clock) && (clock <= PRCMU_DSI2ESCCLK))
return round_dsiescclk_rate(rate);
else
return (long)prcmu_clock_rate(clock);
}
static void set_clock_rate(u8 clock, unsigned long rate)
{
u32 val;
u32 div;
unsigned long src_rate;
unsigned long flags;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
val = readl(clk_mgt[clock].reg);
src_rate = clock_source_rate((val | clk_mgt[clock].pllsw),
clk_mgt[clock].branch);
div = clock_divider(src_rate, rate);
if (val & PRCM_CLK_MGT_CLK38) {
if (clk_mgt[clock].clk38div) {
if (div > 1)
val |= PRCM_CLK_MGT_CLK38DIV;
else
val &= ~PRCM_CLK_MGT_CLK38DIV;
}
} else if (clock == PRCMU_SGACLK) {
val &= ~(PRCM_CLK_MGT_CLKPLLDIV_MASK |
PRCM_SGACLK_MGT_SGACLKDIV_BY_2_5_EN);
if (div == 3) {
u64 r = (src_rate * 10);
(void)do_div(r, 25);
if (r <= rate) {
val |= PRCM_SGACLK_MGT_SGACLKDIV_BY_2_5_EN;
div = 0;
}
}
val |= min(div, (u32)31);
} else {
val &= ~PRCM_CLK_MGT_CLKPLLDIV_MASK;
val |= min(div, (u32)31);
}
writel(val, clk_mgt[clock].reg);
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
}
static int set_plldsi_rate(unsigned long rate)
{
unsigned long src_rate;
unsigned long rem;
u32 pll_freq = 0;
u32 r;
src_rate = clock_rate(PRCMU_HDMICLK);
rem = rate;
for (r = 7; (rem > 0) && (r > 0); r--) {
u64 d;
u64 hwrate;
d = (r * rate);
(void)do_div(d, src_rate);
if (d < 6)
d = 6;
else if (d > 255)
d = 255;
hwrate = (d * src_rate);
if (((2 * hwrate) < (r * MIN_PLL_VCO_RATE)) ||
((r * MAX_PLL_VCO_RATE) < (2 * hwrate)))
continue;
(void)do_div(hwrate, r);
if (rate < hwrate) {
if (pll_freq == 0)
pll_freq = (((u32)d << PRCM_PLL_FREQ_D_SHIFT) |
(r << PRCM_PLL_FREQ_R_SHIFT));
break;
}
if ((rate - hwrate) < rem) {
rem = (rate - hwrate);
pll_freq = (((u32)d << PRCM_PLL_FREQ_D_SHIFT) |
(r << PRCM_PLL_FREQ_R_SHIFT));
}
}
if (pll_freq == 0)
return -EINVAL;
pll_freq |= (1 << PRCM_PLL_FREQ_N_SHIFT);
writel(pll_freq, PRCM_PLLDSI_FREQ);
return 0;
}
static void set_dsiclk_rate(u8 n, unsigned long rate)
{
u32 val;
u32 div;
div = clock_divider(pll_rate(PRCM_PLLDSI_FREQ,
clock_rate(PRCMU_HDMICLK), PLL_RAW), rate);
dsiclk[n].divsel = (div == 1) ? PRCM_DSI_PLLOUT_SEL_PHI :
(div == 2) ? PRCM_DSI_PLLOUT_SEL_PHI_2 :
PRCM_DSI_PLLOUT_SEL_PHI_4;
val = readl(PRCM_DSI_PLLOUT_SEL);
val &= ~dsiclk[n].divsel_mask;
val |= (dsiclk[n].divsel << dsiclk[n].divsel_shift);
writel(val, PRCM_DSI_PLLOUT_SEL);
}
static void set_dsiescclk_rate(u8 n, unsigned long rate)
{
u32 val;
u32 div;
div = clock_divider(clock_rate(PRCMU_TVCLK), rate);
val = readl(PRCM_DSITVCLK_DIV);
val &= ~dsiescclk[n].div_mask;
val |= (min(div, (u32)255) << dsiescclk[n].div_shift);
writel(val, PRCM_DSITVCLK_DIV);
}
int prcmu_set_clock_rate(u8 clock, unsigned long rate)
{
if (clock < PRCMU_NUM_REG_CLOCKS)
set_clock_rate(clock, rate);
else if (clock == PRCMU_PLLDSI)
return set_plldsi_rate(rate);
else if ((clock == PRCMU_DSI0CLK) || (clock == PRCMU_DSI1CLK))
set_dsiclk_rate((clock - PRCMU_DSI0CLK), rate);
else if ((PRCMU_DSI0ESCCLK <= clock) && (clock <= PRCMU_DSI2ESCCLK))
set_dsiescclk_rate((clock - PRCMU_DSI0ESCCLK), rate);
return 0;
}
int db8500_prcmu_config_esram0_deep_sleep(u8 state)
{
if ((state > ESRAM0_DEEP_SLEEP_STATE_RET) ||
(state < ESRAM0_DEEP_SLEEP_STATE_OFF))
return -EINVAL;
mutex_lock(&mb4_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(4))
cpu_relax();
writeb(MB4H_MEM_ST, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB4));
writeb(((DDR_PWR_STATE_OFFHIGHLAT << 4) | DDR_PWR_STATE_ON),
(tcdm_base + PRCM_REQ_MB4_DDR_ST_AP_SLEEP_IDLE));
writeb(DDR_PWR_STATE_ON,
(tcdm_base + PRCM_REQ_MB4_DDR_ST_AP_DEEP_IDLE));
writeb(state, (tcdm_base + PRCM_REQ_MB4_ESRAM0_ST));
writel(MBOX_BIT(4), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb4_transfer.work);
mutex_unlock(&mb4_transfer.lock);
return 0;
}
int db8500_prcmu_config_hotdog(u8 threshold)
{
mutex_lock(&mb4_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(4))
cpu_relax();
writeb(threshold, (tcdm_base + PRCM_REQ_MB4_HOTDOG_THRESHOLD));
writeb(MB4H_HOTDOG, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB4));
writel(MBOX_BIT(4), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb4_transfer.work);
mutex_unlock(&mb4_transfer.lock);
return 0;
}
int db8500_prcmu_config_hotmon(u8 low, u8 high)
{
mutex_lock(&mb4_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(4))
cpu_relax();
writeb(low, (tcdm_base + PRCM_REQ_MB4_HOTMON_LOW));
writeb(high, (tcdm_base + PRCM_REQ_MB4_HOTMON_HIGH));
writeb((HOTMON_CONFIG_LOW | HOTMON_CONFIG_HIGH),
(tcdm_base + PRCM_REQ_MB4_HOTMON_CONFIG));
writeb(MB4H_HOTMON, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB4));
writel(MBOX_BIT(4), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb4_transfer.work);
mutex_unlock(&mb4_transfer.lock);
return 0;
}
static int config_hot_period(u16 val)
{
mutex_lock(&mb4_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(4))
cpu_relax();
writew(val, (tcdm_base + PRCM_REQ_MB4_HOT_PERIOD));
writeb(MB4H_HOT_PERIOD, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB4));
writel(MBOX_BIT(4), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb4_transfer.work);
mutex_unlock(&mb4_transfer.lock);
return 0;
}
int db8500_prcmu_start_temp_sense(u16 cycles32k)
{
if (cycles32k == 0xFFFF)
return -EINVAL;
return config_hot_period(cycles32k);
}
int db8500_prcmu_stop_temp_sense(void)
{
return config_hot_period(0xFFFF);
}
static int prcmu_a9wdog(u8 cmd, u8 d0, u8 d1, u8 d2, u8 d3)
{
mutex_lock(&mb4_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(4))
cpu_relax();
writeb(d0, (tcdm_base + PRCM_REQ_MB4_A9WDOG_0));
writeb(d1, (tcdm_base + PRCM_REQ_MB4_A9WDOG_1));
writeb(d2, (tcdm_base + PRCM_REQ_MB4_A9WDOG_2));
writeb(d3, (tcdm_base + PRCM_REQ_MB4_A9WDOG_3));
writeb(cmd, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB4));
writel(MBOX_BIT(4), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb4_transfer.work);
mutex_unlock(&mb4_transfer.lock);
return 0;
}
int db8500_prcmu_config_a9wdog(u8 num, bool sleep_auto_off)
{
BUG_ON(num == 0 || num > 0xf);
return prcmu_a9wdog(MB4H_A9WDOG_CONF, num, 0, 0,
sleep_auto_off ? A9WDOG_AUTO_OFF_EN :
A9WDOG_AUTO_OFF_DIS);
}
int db8500_prcmu_enable_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_EN, id, 0, 0, 0);
}
int db8500_prcmu_disable_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_DIS, id, 0, 0, 0);
}
int db8500_prcmu_kick_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_KICK, id, 0, 0, 0);
}
int db8500_prcmu_load_a9wdog(u8 id, u32 timeout)
{
return prcmu_a9wdog(MB4H_A9WDOG_LOAD,
(id & A9WDOG_ID_MASK) |
(u8)((timeout << 4) & 0xf0),
(u8)((timeout >> 4) & 0xff),
(u8)((timeout >> 12) & 0xff),
(u8)((timeout >> 20) & 0xff));
}
int prcmu_abb_read(u8 slave, u8 reg, u8 *value, u8 size)
{
int r;
if (size != 1)
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
writeb(0, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB5));
writeb(PRCMU_I2C_READ(slave), (tcdm_base + PRCM_REQ_MB5_I2C_SLAVE_OP));
writeb(PRCMU_I2C_STOP_EN, (tcdm_base + PRCM_REQ_MB5_I2C_HW_BITS));
writeb(reg, (tcdm_base + PRCM_REQ_MB5_I2C_REG));
writeb(0, (tcdm_base + PRCM_REQ_MB5_I2C_VAL));
writel(MBOX_BIT(5), PRCM_MBOX_CPU_SET);
if (!wait_for_completion_timeout(&mb5_transfer.work,
msecs_to_jiffies(20000))) {
pr_err("prcmu: %s timed out (20 s) waiting for a reply.\n",
__func__);
r = -EIO;
} else {
r = ((mb5_transfer.ack.status == I2C_RD_OK) ? 0 : -EIO);
}
if (!r)
*value = mb5_transfer.ack.value;
mutex_unlock(&mb5_transfer.lock);
return r;
}
int prcmu_abb_write_masked(u8 slave, u8 reg, u8 *value, u8 *mask, u8 size)
{
int r;
if (size != 1)
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
writeb(~*mask, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB5));
writeb(PRCMU_I2C_WRITE(slave), (tcdm_base + PRCM_REQ_MB5_I2C_SLAVE_OP));
writeb(PRCMU_I2C_STOP_EN, (tcdm_base + PRCM_REQ_MB5_I2C_HW_BITS));
writeb(reg, (tcdm_base + PRCM_REQ_MB5_I2C_REG));
writeb(*value, (tcdm_base + PRCM_REQ_MB5_I2C_VAL));
writel(MBOX_BIT(5), PRCM_MBOX_CPU_SET);
if (!wait_for_completion_timeout(&mb5_transfer.work,
msecs_to_jiffies(20000))) {
pr_err("prcmu: %s timed out (20 s) waiting for a reply.\n",
__func__);
r = -EIO;
} else {
r = ((mb5_transfer.ack.status == I2C_WR_OK) ? 0 : -EIO);
}
mutex_unlock(&mb5_transfer.lock);
return r;
}
int prcmu_abb_write(u8 slave, u8 reg, u8 *value, u8 size)
{
u8 mask = ~0;
return prcmu_abb_write_masked(slave, reg, value, &mask, size);
}
void prcmu_ac_wake_req(void)
{
u32 val;
u32 status;
mutex_lock(&mb0_transfer.ac_wake_lock);
val = readl(PRCM_HOSTACCESS_REQ);
if (val & PRCM_HOSTACCESS_REQ_HOSTACCESS_REQ)
goto unlock_and_return;
atomic_set(&ac_wake_req_state, 1);
retry:
writel((val | PRCM_HOSTACCESS_REQ_HOSTACCESS_REQ), PRCM_HOSTACCESS_REQ);
if (!wait_for_completion_timeout(&mb0_transfer.ac_wake_work,
msecs_to_jiffies(5000))) {
pr_crit("prcmu: %s timed out (5 s) waiting for a reply.\n",
__func__);
goto unlock_and_return;
}
udelay(400);
status = (readl(PRCM_MOD_AWAKE_STATUS) & BITS(0, 2));
if (status != (PRCM_MOD_AWAKE_STATUS_PRCM_MOD_AAPD_AWAKE |
PRCM_MOD_AWAKE_STATUS_PRCM_MOD_COREPD_AWAKE)) {
pr_err("prcmu: %s received ack, but modem not awake (0x%X).\n",
__func__, status);
udelay(1200);
writel(val, PRCM_HOSTACCESS_REQ);
if (wait_for_completion_timeout(&mb0_transfer.ac_wake_work,
msecs_to_jiffies(5000)))
goto retry;
pr_crit("prcmu: %s timed out (5 s) waiting for AC_SLEEP_ACK.\n",
__func__);
}
unlock_and_return:
mutex_unlock(&mb0_transfer.ac_wake_lock);
}
void prcmu_ac_sleep_req()
{
u32 val;
mutex_lock(&mb0_transfer.ac_wake_lock);
val = readl(PRCM_HOSTACCESS_REQ);
if (!(val & PRCM_HOSTACCESS_REQ_HOSTACCESS_REQ))
goto unlock_and_return;
writel((val & ~PRCM_HOSTACCESS_REQ_HOSTACCESS_REQ),
PRCM_HOSTACCESS_REQ);
if (!wait_for_completion_timeout(&mb0_transfer.ac_wake_work,
msecs_to_jiffies(5000))) {
pr_crit("prcmu: %s timed out (5 s) waiting for a reply.\n",
__func__);
}
atomic_set(&ac_wake_req_state, 0);
unlock_and_return:
mutex_unlock(&mb0_transfer.ac_wake_lock);
}
bool db8500_prcmu_is_ac_wake_requested(void)
{
return (atomic_read(&ac_wake_req_state) != 0);
}
void db8500_prcmu_system_reset(u16 reset_code)
{
writew(reset_code, (tcdm_base + PRCM_SW_RST_REASON));
writel(1, PRCM_APE_SOFTRST);
}
u16 db8500_prcmu_get_reset_code(void)
{
return readw(tcdm_base + PRCM_SW_RST_REASON);
}
void db8500_prcmu_modem_reset(void)
{
mutex_lock(&mb1_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_RESET_MODEM, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
mutex_unlock(&mb1_transfer.lock);
}
static void ack_dbb_wakeup(void)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.lock, flags);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(0))
cpu_relax();
writeb(MB0H_READ_WAKEUP_ACK, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB0));
writel(MBOX_BIT(0), PRCM_MBOX_CPU_SET);
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
}
static inline void print_unknown_header_warning(u8 n, u8 header)
{
pr_warning("prcmu: Unknown message header (%d) in mailbox %d.\n",
header, n);
}
static bool read_mailbox_0(void)
{
bool r;
u32 ev;
unsigned int n;
u8 header;
header = readb(tcdm_base + PRCM_MBOX_HEADER_ACK_MB0);
switch (header) {
case MB0H_WAKEUP_EXE:
case MB0H_WAKEUP_SLEEP:
if (readb(tcdm_base + PRCM_ACK_MB0_READ_POINTER) & 1)
ev = readl(tcdm_base + PRCM_ACK_MB0_WAKEUP_1_8500);
else
ev = readl(tcdm_base + PRCM_ACK_MB0_WAKEUP_0_8500);
if (ev & (WAKEUP_BIT_AC_WAKE_ACK | WAKEUP_BIT_AC_SLEEP_ACK))
complete(&mb0_transfer.ac_wake_work);
if (ev & WAKEUP_BIT_SYSCLK_OK)
complete(&mb3_transfer.sysclk_work);
ev &= mb0_transfer.req.dbb_irqs;
for (n = 0; n < NUM_PRCMU_WAKEUPS; n++) {
if (ev & prcmu_irq_bit[n])
generic_handle_irq(IRQ_PRCMU_BASE + n);
}
r = true;
break;
default:
print_unknown_header_warning(0, header);
r = false;
break;
}
writel(MBOX_BIT(0), PRCM_ARM_IT1_CLR);
return r;
}
static bool read_mailbox_1(void)
{
mb1_transfer.ack.header = readb(tcdm_base + PRCM_MBOX_HEADER_REQ_MB1);
mb1_transfer.ack.arm_opp = readb(tcdm_base +
PRCM_ACK_MB1_CURRENT_ARM_OPP);
mb1_transfer.ack.ape_opp = readb(tcdm_base +
PRCM_ACK_MB1_CURRENT_APE_OPP);
mb1_transfer.ack.ape_voltage_status = readb(tcdm_base +
PRCM_ACK_MB1_APE_VOLTAGE_STATUS);
writel(MBOX_BIT(1), PRCM_ARM_IT1_CLR);
complete(&mb1_transfer.work);
return false;
}
static bool read_mailbox_2(void)
{
mb2_transfer.ack.status = readb(tcdm_base + PRCM_ACK_MB2_DPS_STATUS);
writel(MBOX_BIT(2), PRCM_ARM_IT1_CLR);
complete(&mb2_transfer.work);
return false;
}
static bool read_mailbox_3(void)
{
writel(MBOX_BIT(3), PRCM_ARM_IT1_CLR);
return false;
}
static bool read_mailbox_4(void)
{
u8 header;
bool do_complete = true;
header = readb(tcdm_base + PRCM_MBOX_HEADER_REQ_MB4);
switch (header) {
case MB4H_MEM_ST:
case MB4H_HOTDOG:
case MB4H_HOTMON:
case MB4H_HOT_PERIOD:
case MB4H_A9WDOG_CONF:
case MB4H_A9WDOG_EN:
case MB4H_A9WDOG_DIS:
case MB4H_A9WDOG_LOAD:
case MB4H_A9WDOG_KICK:
break;
default:
print_unknown_header_warning(4, header);
do_complete = false;
break;
}
writel(MBOX_BIT(4), PRCM_ARM_IT1_CLR);
if (do_complete)
complete(&mb4_transfer.work);
return false;
}
static bool read_mailbox_5(void)
{
mb5_transfer.ack.status = readb(tcdm_base + PRCM_ACK_MB5_I2C_STATUS);
mb5_transfer.ack.value = readb(tcdm_base + PRCM_ACK_MB5_I2C_VAL);
writel(MBOX_BIT(5), PRCM_ARM_IT1_CLR);
complete(&mb5_transfer.work);
return false;
}
static bool read_mailbox_6(void)
{
writel(MBOX_BIT(6), PRCM_ARM_IT1_CLR);
return false;
}
static bool read_mailbox_7(void)
{
writel(MBOX_BIT(7), PRCM_ARM_IT1_CLR);
return false;
}
static irqreturn_t prcmu_irq_handler(int irq, void *data)
{
u32 bits;
u8 n;
irqreturn_t r;
bits = (readl(PRCM_ARM_IT1_VAL) & ALL_MBOX_BITS);
if (unlikely(!bits))
return IRQ_NONE;
r = IRQ_HANDLED;
for (n = 0; bits; n++) {
if (bits & MBOX_BIT(n)) {
bits -= MBOX_BIT(n);
if (read_mailbox[n]())
r = IRQ_WAKE_THREAD;
}
}
return r;
}
static irqreturn_t prcmu_irq_thread_fn(int irq, void *data)
{
ack_dbb_wakeup();
return IRQ_HANDLED;
}
static void prcmu_mask_work(struct work_struct *work)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.lock, flags);
config_wakeups();
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
}
static void prcmu_irq_mask(struct irq_data *d)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.dbb_irqs_lock, flags);
mb0_transfer.req.dbb_irqs &= ~prcmu_irq_bit[d->irq - IRQ_PRCMU_BASE];
spin_unlock_irqrestore(&mb0_transfer.dbb_irqs_lock, flags);
if (d->irq != IRQ_PRCMU_CA_SLEEP)
schedule_work(&mb0_transfer.mask_work);
}
static void prcmu_irq_unmask(struct irq_data *d)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.dbb_irqs_lock, flags);
mb0_transfer.req.dbb_irqs |= prcmu_irq_bit[d->irq - IRQ_PRCMU_BASE];
spin_unlock_irqrestore(&mb0_transfer.dbb_irqs_lock, flags);
if (d->irq != IRQ_PRCMU_CA_SLEEP)
schedule_work(&mb0_transfer.mask_work);
}
static void noop(struct irq_data *d)
{
}
static char *fw_project_name(u8 project)
{
switch (project) {
case PRCMU_FW_PROJECT_U8500:
return "U8500";
case PRCMU_FW_PROJECT_U8500_C2:
return "U8500 C2";
case PRCMU_FW_PROJECT_U9500:
return "U9500";
case PRCMU_FW_PROJECT_U9500_C2:
return "U9500 C2";
case PRCMU_FW_PROJECT_U8520:
return "U8520";
case PRCMU_FW_PROJECT_U8420:
return "U8420";
default:
return "Unknown";
}
}
void __init db8500_prcmu_early_init(void)
{
unsigned int i;
if (cpu_is_u8500v2()) {
void *tcpm_base = ioremap_nocache(U8500_PRCMU_TCPM_BASE, SZ_4K);
if (tcpm_base != NULL) {
u32 version;
version = readl(tcpm_base + PRCMU_FW_VERSION_OFFSET);
fw_info.version.project = version & 0xFF;
fw_info.version.api_version = (version >> 8) & 0xFF;
fw_info.version.func_version = (version >> 16) & 0xFF;
fw_info.version.errata = (version >> 24) & 0xFF;
fw_info.valid = true;
pr_info("PRCMU firmware: %s, version %d.%d.%d\n",
fw_project_name(fw_info.version.project),
(version >> 8) & 0xFF, (version >> 16) & 0xFF,
(version >> 24) & 0xFF);
iounmap(tcpm_base);
}
tcdm_base = __io_address(U8500_PRCMU_TCDM_BASE);
} else {
pr_err("prcmu: Unsupported chip version\n");
BUG();
}
spin_lock_init(&mb0_transfer.lock);
spin_lock_init(&mb0_transfer.dbb_irqs_lock);
mutex_init(&mb0_transfer.ac_wake_lock);
init_completion(&mb0_transfer.ac_wake_work);
mutex_init(&mb1_transfer.lock);
init_completion(&mb1_transfer.work);
mb1_transfer.ape_opp = APE_NO_CHANGE;
mutex_init(&mb2_transfer.lock);
init_completion(&mb2_transfer.work);
spin_lock_init(&mb2_transfer.auto_pm_lock);
spin_lock_init(&mb3_transfer.lock);
mutex_init(&mb3_transfer.sysclk_lock);
init_completion(&mb3_transfer.sysclk_work);
mutex_init(&mb4_transfer.lock);
init_completion(&mb4_transfer.work);
mutex_init(&mb5_transfer.lock);
init_completion(&mb5_transfer.work);
INIT_WORK(&mb0_transfer.mask_work, prcmu_mask_work);
for (i = 0; i < NUM_PRCMU_WAKEUPS; i++) {
unsigned int irq;
irq = IRQ_PRCMU_BASE + i;
irq_set_chip_and_handler(irq, &prcmu_irq_chip,
handle_simple_irq);
set_irq_flags(irq, IRQF_VALID);
}
}
static void __init init_prcm_registers(void)
{
u32 val;
val = readl(PRCM_A9PL_FORCE_CLKEN);
val &= ~(PRCM_A9PL_FORCE_CLKEN_PRCM_A9PL_FORCE_CLKEN |
PRCM_A9PL_FORCE_CLKEN_PRCM_A9AXI_FORCE_CLKEN);
writel(val, (PRCM_A9PL_FORCE_CLKEN));
}
static int __init db8500_prcmu_probe(struct platform_device *pdev)
{
int err = 0;
if (ux500_is_svp())
return -ENODEV;
init_prcm_registers();
writel(ALL_MBOX_BITS, PRCM_ARM_IT1_CLR);
err = request_threaded_irq(IRQ_DB8500_PRCMU1, prcmu_irq_handler,
prcmu_irq_thread_fn, IRQF_NO_SUSPEND, "prcmu", NULL);
if (err < 0) {
pr_err("prcmu: Failed to allocate IRQ_DB8500_PRCMU1.\n");
err = -EBUSY;
goto no_irq_return;
}
if (cpu_is_u8500v20_or_later())
prcmu_config_esram0_deep_sleep(ESRAM0_DEEP_SLEEP_STATE_RET);
err = mfd_add_devices(&pdev->dev, 0, db8500_prcmu_devs,
ARRAY_SIZE(db8500_prcmu_devs), NULL,
0);
if (err)
pr_err("prcmu: Failed to add subdevices\n");
else
pr_info("DB8500 PRCMU initialized\n");
no_irq_return:
return err;
}
static int __init db8500_prcmu_init(void)
{
return platform_driver_probe(&db8500_prcmu_driver, db8500_prcmu_probe);
}
