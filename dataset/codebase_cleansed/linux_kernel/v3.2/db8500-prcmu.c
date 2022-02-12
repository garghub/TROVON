int db8500_prcmu_enable_dsipll(void)
{
int i;
unsigned int plldsifreq;
writel(PRCMU_RESET_DSIPLL, PRCM_APE_RESETN_CLR);
writel(PRCMU_UNCLAMP_DSIPLL, PRCM_MMIP_LS_CLAMP_CLR);
if (prcmu_is_u8400())
plldsifreq = PRCMU_PLLDSI_FREQ_SETTING_U8400;
else
plldsifreq = PRCMU_PLLDSI_FREQ_SETTING;
writel(plldsifreq, PRCM_PLLDSI_FREQ);
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
unsigned int dsiclk;
if (prcmu_is_u8400())
dsiclk = PRCMU_DSI_CLOCK_SETTING_U8400;
else
dsiclk = PRCMU_DSI_CLOCK_SETTING;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
writel(dsiclk, PRCM_HDMICLK_MGT);
writel(PRCMU_DSI_LP_CLOCK_SETTING, PRCM_TVCLK_MGT);
writel(PRCMU_DPI_CLOCK_SETTING, PRCM_LCDCLK_MGT);
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
return 0;
}
void prcmu_enable_spi2(void)
{
u32 reg;
unsigned long flags;
spin_lock_irqsave(&gpiocr_lock, flags);
reg = readl(PRCM_GPIOCR);
writel(reg | PRCM_GPIOCR_SPI2_SELECT, PRCM_GPIOCR);
spin_unlock_irqrestore(&gpiocr_lock, flags);
}
void prcmu_disable_spi2(void)
{
u32 reg;
unsigned long flags;
spin_lock_irqsave(&gpiocr_lock, flags);
reg = readl(PRCM_GPIOCR);
writel(reg & ~PRCM_GPIOCR_SPI2_SELECT, PRCM_GPIOCR);
spin_unlock_irqrestore(&gpiocr_lock, flags);
}
bool prcmu_has_arm_maxopp(void)
{
return (readb(tcdm_base + PRCM_AVS_VARM_MAX_OPP) &
PRCM_AVS_ISMODEENABLE_MASK) == PRCM_AVS_ISMODEENABLE_MASK;
}
bool prcmu_is_u8400(void)
{
return prcmu_version.project_number == PRCMU_PROJECT_ID_8400V2_0;
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
int prcmu_get_ddr_opp(void)
{
return readb(PRCM_DDR_SUBSYS_APE_MINBW);
}
int prcmu_set_ddr_opp(u8 opp)
{
if (opp < DDR_100_OPP || opp > DDR_25_OPP)
return -EINVAL;
if (cpu_is_u8500v20_or_later() && !cpu_is_u8500v20())
writeb(opp, PRCM_DDR_SUBSYS_APE_MINBW);
return 0;
}
int prcmu_set_ape_opp(u8 opp)
{
int r = 0;
mutex_lock(&mb1_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(1))
cpu_relax();
writeb(MB1H_ARM_APE_OPP, (tcdm_base + PRCM_MBOX_HEADER_REQ_MB1));
writeb(ARM_NO_CHANGE, (tcdm_base + PRCM_REQ_MB1_ARM_OPP));
writeb(opp, (tcdm_base + PRCM_REQ_MB1_APE_OPP));
writel(MBOX_BIT(1), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb1_transfer.work);
if ((mb1_transfer.ack.header != MB1H_ARM_APE_OPP) ||
(mb1_transfer.ack.ape_opp != opp))
r = -EIO;
mutex_unlock(&mb1_transfer.lock);
return r;
}
int prcmu_get_ape_opp(void)
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
if (clock == PRCMU_PLLSOC1)
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
int prcmu_set_hwacc(u16 hwacc_dev, u8 state)
{
int r = 0;
bool ram_retention = false;
bool enable, enable_ret;
BUG_ON(hwacc_dev >= NUM_HW_ACC);
enable = hwacc_enabled[hwacc_dev];
enable_ret = hwacc_ret_enabled[hwacc_dev];
switch (hwacc_dev) {
case HW_ACC_SVAMMDSP:
case HW_ACC_SIAMMDSP:
case HW_ACC_ESRAM1:
case HW_ACC_ESRAM2:
case HW_ACC_ESRAM3:
case HW_ACC_ESRAM4:
ram_retention = true;
break;
}
BUG_ON(state > HW_ON);
BUG_ON(state == HW_OFF_RAMRET && !ram_retention);
switch (state) {
case HW_OFF:
enable_ret = false;
enable = false;
break;
case HW_ON:
enable = true;
break;
case HW_OFF_RAMRET:
enable_ret = true;
enable = false;
break;
}
if (hwacc_regulator[hwacc_dev] == NULL) {
hwacc_regulator[hwacc_dev] = regulator_get(NULL,
hwacc_regulator_name[hwacc_dev]);
if (IS_ERR(hwacc_regulator[hwacc_dev])) {
pr_err("prcmu: failed to get supply %s\n",
hwacc_regulator_name[hwacc_dev]);
r = PTR_ERR(hwacc_regulator[hwacc_dev]);
goto out;
}
}
if (ram_retention) {
if (hwacc_ret_regulator[hwacc_dev] == NULL) {
hwacc_ret_regulator[hwacc_dev] = regulator_get(NULL,
hwacc_ret_regulator_name[hwacc_dev]);
if (IS_ERR(hwacc_ret_regulator[hwacc_dev])) {
pr_err("prcmu: failed to get supply %s\n",
hwacc_ret_regulator_name[hwacc_dev]);
r = PTR_ERR(hwacc_ret_regulator[hwacc_dev]);
goto out;
}
}
}
if (ram_retention) {
if (enable_ret && !hwacc_ret_enabled[hwacc_dev]) {
r = regulator_enable(hwacc_ret_regulator[hwacc_dev]);
if (r < 0) {
pr_err("prcmu_set_hwacc: ret enable failed\n");
goto out;
}
hwacc_ret_enabled[hwacc_dev] = true;
}
}
if (enable && !hwacc_enabled[hwacc_dev]) {
r = regulator_enable(hwacc_regulator[hwacc_dev]);
if (r < 0) {
pr_err("prcmu_set_hwacc: enable failed\n");
goto out;
}
hwacc_enabled[hwacc_dev] = true;
}
if (!enable && hwacc_enabled[hwacc_dev]) {
r = regulator_disable(hwacc_regulator[hwacc_dev]);
if (r < 0) {
pr_err("prcmu_set_hwacc: disable failed\n");
goto out;
}
hwacc_enabled[hwacc_dev] = false;
}
if (ram_retention) {
if (!enable_ret && hwacc_ret_enabled[hwacc_dev]) {
r = regulator_disable(hwacc_ret_regulator[hwacc_dev]);
if (r < 0) {
pr_err("prcmu_set_hwacc: ret disable failed\n");
goto out;
}
hwacc_ret_enabled[hwacc_dev] = false;
}
}
out:
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
static int request_reg_clock(u8 clock, bool enable)
{
u32 val;
unsigned long flags;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
val = readl(_PRCMU_BASE + clk_mgt[clock].offset);
if (enable) {
val |= (PRCM_CLK_MGT_CLKEN | clk_mgt[clock].pllsw);
} else {
clk_mgt[clock].pllsw = (val & PRCM_CLK_MGT_CLKPLLSW_MASK);
val &= ~(PRCM_CLK_MGT_CLKEN | PRCM_CLK_MGT_CLKPLLSW_MASK);
}
writel(val, (_PRCMU_BASE + clk_mgt[clock].offset));
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
ret = request_reg_clock(clock, enable);
if (!ret && !enable) {
val = readl(PRCM_CGATING_BYPASS);
writel(val & ~PRCM_CGATING_BYPASS_ICN2, PRCM_CGATING_BYPASS);
}
return ret;
}
int db8500_prcmu_request_clock(u8 clock, bool enable)
{
switch(clock) {
case PRCMU_SGACLK:
return request_sga_clock(clock, enable);
case PRCMU_TIMCLK:
return request_timclk(enable);
case PRCMU_SYSCLK:
return request_sysclk(enable);
case PRCMU_PLLSOC1:
return request_pll(clock, enable);
default:
break;
}
if (clock < PRCMU_NUM_REG_CLOCKS)
return request_reg_clock(clock, enable);
return -EINVAL;
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
int prcmu_config_hotdog(u8 threshold)
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
int prcmu_config_hotmon(u8 low, u8 high)
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
int prcmu_start_temp_sense(u16 cycles32k)
{
if (cycles32k == 0xFFFF)
return -EINVAL;
return config_hot_period(cycles32k);
}
int prcmu_stop_temp_sense(void)
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
int prcmu_config_a9wdog(u8 num, bool sleep_auto_off)
{
BUG_ON(num == 0 || num > 0xf);
return prcmu_a9wdog(MB4H_A9WDOG_CONF, num, 0, 0,
sleep_auto_off ? A9WDOG_AUTO_OFF_EN :
A9WDOG_AUTO_OFF_DIS);
}
int prcmu_enable_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_EN, id, 0, 0, 0);
}
int prcmu_disable_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_DIS, id, 0, 0, 0);
}
int prcmu_kick_a9wdog(u8 id)
{
return prcmu_a9wdog(MB4H_A9WDOG_KICK, id, 0, 0, 0);
}
int prcmu_load_a9wdog(u8 id, u32 timeout)
{
if (timeout > MAX_WATCHDOG_TIMEOUT)
return -EINVAL;
return prcmu_a9wdog(MB4H_A9WDOG_LOAD,
(id & A9WDOG_ID_MASK) |
(u8)((timeout << 4) & 0xf0),
(u8)((timeout >> 4) & 0xff),
(u8)((timeout >> 12) & 0xff),
(u8)((timeout >> 20) & 0xff));
}
int prcmu_set_clock_divider(u8 clock, u8 divider)
{
u32 val;
unsigned long flags;
if ((clock >= PRCMU_NUM_REG_CLOCKS) || (divider < 1) || (31 < divider))
return -EINVAL;
spin_lock_irqsave(&clk_mgt_lock, flags);
while ((readl(PRCM_SEM) & PRCM_SEM_PRCM_SEM) != 0)
cpu_relax();
val = readl(_PRCMU_BASE + clk_mgt[clock].offset);
val &= ~(PRCM_CLK_MGT_CLKPLLDIV_MASK);
val |= (u32)divider;
writel(val, (_PRCMU_BASE + clk_mgt[clock].offset));
writel(0, PRCM_SEM);
spin_unlock_irqrestore(&clk_mgt_lock, flags);
return 0;
}
int prcmu_abb_read(u8 slave, u8 reg, u8 *value, u8 size)
{
int r;
if (size != 1)
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
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
int prcmu_abb_write(u8 slave, u8 reg, u8 *value, u8 size)
{
int r;
if (size != 1)
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
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
void prcmu_modem_reset(void)
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
void __init db8500_prcmu_early_init(void)
{
unsigned int i;
if (cpu_is_u8500v1()) {
tcdm_base = __io_address(U8500_PRCMU_TCDM_BASE_V1);
} else if (cpu_is_u8500v2()) {
void *tcpm_base = ioremap_nocache(U8500_PRCMU_TCPM_BASE, SZ_4K);
if (tcpm_base != NULL) {
int version;
version = readl(tcpm_base + PRCMU_FW_VERSION_OFFSET);
prcmu_version.project_number = version & 0xFF;
prcmu_version.api_version = (version >> 8) & 0xFF;
prcmu_version.func_version = (version >> 16) & 0xFF;
prcmu_version.errata = (version >> 24) & 0xFF;
pr_info("PRCMU firmware version %d.%d.%d\n",
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
static void __init db8500_prcmu_init_clkforce(void)
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
db8500_prcmu_init_clkforce();
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
