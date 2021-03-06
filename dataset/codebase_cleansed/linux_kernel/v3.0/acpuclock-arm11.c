static int pc_pll_request(unsigned id, unsigned on)
{
int res;
on = !!on;
#if PERF_SWITCH_DEBUG
if (on)
printk(KERN_DEBUG "Enabling PLL %d\n", id);
else
printk(KERN_DEBUG "Disabling PLL %d\n", id);
#endif
res = msm_proc_comm(PCOM_CLKCTL_RPC_PLL_REQUEST, &id, &on);
if (res < 0)
return res;
#if PERF_SWITCH_DEBUG
if (on)
printk(KERN_DEBUG "PLL %d enabled\n", id);
else
printk(KERN_DEBUG "PLL %d disabled\n", id);
#endif
return res;
}
unsigned long acpuclk_power_collapse(void) {
int ret = acpuclk_get_rate();
ret *= 1000;
if (ret > drv_state.power_collapse_khz)
acpuclk_set_rate(drv_state.power_collapse_khz, 1);
return ret;
}
unsigned long acpuclk_get_wfi_rate(void)
{
return drv_state.wait_for_irq_khz;
}
unsigned long acpuclk_wait_for_irq(void) {
int ret = acpuclk_get_rate();
ret *= 1000;
if (ret > drv_state.wait_for_irq_khz)
acpuclk_set_rate(drv_state.wait_for_irq_khz, 1);
return ret;
}
static int acpuclk_set_vdd_level(int vdd)
{
uint32_t current_vdd;
current_vdd = readl(A11S_VDD_SVS_PLEVEL_ADDR) & 0x07;
#if PERF_SWITCH_DEBUG
printk(KERN_DEBUG "acpuclock: Switching VDD from %u -> %d\n",
current_vdd, vdd);
#endif
writel((1 << 7) | (vdd << 3), A11S_VDD_SVS_PLEVEL_ADDR);
udelay(drv_state.vdd_switch_time_us);
if ((readl(A11S_VDD_SVS_PLEVEL_ADDR) & 0x7) != vdd) {
#if PERF_SWITCH_DEBUG
printk(KERN_ERR "acpuclock: VDD set failed\n");
#endif
return -EIO;
}
#if PERF_SWITCH_DEBUG
printk(KERN_DEBUG "acpuclock: VDD switched\n");
#endif
return 0;
}
static void acpuclk_set_div(const struct clkctl_acpu_speed *hunt_s) {
uint32_t reg_clkctl, reg_clksel, clk_div;
clk_div = (readl(A11S_CLK_SEL_ADDR) >> 1) & 0x03;
if (hunt_s->ahbclk_div > clk_div) {
reg_clksel = readl(A11S_CLK_SEL_ADDR);
reg_clksel &= ~(0x3 << 1);
reg_clksel |= (hunt_s->ahbclk_div << 1);
writel(reg_clksel, A11S_CLK_SEL_ADDR);
}
if ((readl(A11S_CLK_SEL_ADDR) & 0x01) == 0) {
reg_clkctl = readl(A11S_CLK_CNTL_ADDR);
reg_clkctl &= ~(0x07 << 4);
reg_clkctl |= (hunt_s->a11clk_src_sel << 4);
writel(reg_clkctl, A11S_CLK_CNTL_ADDR);
reg_clkctl = readl(A11S_CLK_CNTL_ADDR);
reg_clkctl &= ~0xf;
reg_clkctl |= hunt_s->a11clk_src_div;
writel(reg_clkctl, A11S_CLK_CNTL_ADDR);
reg_clksel = readl(A11S_CLK_SEL_ADDR);
reg_clksel |= 1;
writel(reg_clksel, A11S_CLK_SEL_ADDR);
} else {
reg_clkctl = readl(A11S_CLK_CNTL_ADDR);
reg_clkctl &= ~(0x07 << 12);
reg_clkctl |= (hunt_s->a11clk_src_sel << 12);
writel(reg_clkctl, A11S_CLK_CNTL_ADDR);
reg_clkctl = readl(A11S_CLK_CNTL_ADDR);
reg_clkctl &= ~(0xf << 8);
reg_clkctl |= (hunt_s->a11clk_src_div << 8);
writel(reg_clkctl, A11S_CLK_CNTL_ADDR);
reg_clksel = readl(A11S_CLK_SEL_ADDR);
reg_clksel &= ~1;
writel(reg_clksel, A11S_CLK_SEL_ADDR);
}
if (hunt_s->ahbclk_div < clk_div) {
reg_clksel = readl(A11S_CLK_SEL_ADDR);
reg_clksel &= ~(0x3 << 1);
reg_clksel |= (hunt_s->ahbclk_div << 1);
writel(reg_clksel, A11S_CLK_SEL_ADDR);
}
}
int acpuclk_set_rate(unsigned long rate, int for_power_collapse)
{
uint32_t reg_clkctl;
struct clkctl_acpu_speed *cur_s, *tgt_s, *strt_s;
int rc = 0;
unsigned int plls_enabled = 0, pll;
strt_s = cur_s = drv_state.current_speed;
WARN_ONCE(cur_s == NULL, "acpuclk_set_rate: not initialized\n");
if (cur_s == NULL)
return -ENOENT;
if (rate == (cur_s->a11clk_khz * 1000))
return 0;
for (tgt_s = acpu_freq_tbl; tgt_s->a11clk_khz != 0; tgt_s++) {
if (tgt_s->a11clk_khz == (rate / 1000))
break;
}
if (tgt_s->a11clk_khz == 0)
return -EINVAL;
if (for_power_collapse && tgt_s->a11clk_khz < cur_s->a11clk_khz) {
while (tgt_s->pll != ACPU_PLL_TCXO && tgt_s->pll != cur_s->pll)
tgt_s--;
}
if (strt_s->pll != ACPU_PLL_TCXO)
plls_enabled |= 1 << strt_s->pll;
if (!for_power_collapse) {
mutex_lock(&drv_state.lock);
if (strt_s->pll != tgt_s->pll && tgt_s->pll != ACPU_PLL_TCXO) {
rc = pc_pll_request(tgt_s->pll, 1);
if (rc < 0) {
pr_err("PLL%d enable failed (%d)\n",
tgt_s->pll, rc);
goto out;
}
plls_enabled |= 1 << tgt_s->pll;
}
if (tgt_s->vdd > cur_s->vdd) {
if ((rc = acpuclk_set_vdd_level(tgt_s->vdd)) < 0) {
printk(KERN_ERR "Unable to switch ACPU vdd\n");
goto out;
}
}
}
reg_clkctl = readl(A11S_CLK_CNTL_ADDR);
reg_clkctl |= (100 << 16);
writel(reg_clkctl, A11S_CLK_CNTL_ADDR);
#if PERF_SWITCH_DEBUG
printk(KERN_INFO "acpuclock: Switching from ACPU rate %u -> %u\n",
strt_s->a11clk_khz * 1000, tgt_s->a11clk_khz * 1000);
#endif
while (cur_s != tgt_s) {
int d = abs((int)(cur_s->a11clk_khz - tgt_s->a11clk_khz));
if (d > drv_state.max_speed_delta_khz) {
int clk_index = tgt_s->a11clk_khz > cur_s->a11clk_khz ?
cur_s->up : cur_s->down;
if (clk_index < 0) {
printk(KERN_ERR "cur:%u target: %u\n",
cur_s->a11clk_khz, tgt_s->a11clk_khz);
rc = -EINVAL;
goto out;
}
cur_s = &acpu_freq_tbl[clk_index];
} else {
cur_s = tgt_s;
}
#if PERF_SWITCH_STEP_DEBUG
printk(KERN_DEBUG "%s: STEP khz = %u, pll = %d\n",
__FUNCTION__, cur_s->a11clk_khz, cur_s->pll);
#endif
if (!for_power_collapse&& cur_s->pll != ACPU_PLL_TCXO
&& !(plls_enabled & (1 << cur_s->pll))) {
rc = pc_pll_request(cur_s->pll, 1);
if (rc < 0) {
pr_err("PLL%d enable failed (%d)\n",
cur_s->pll, rc);
goto out;
}
plls_enabled |= 1 << cur_s->pll;
}
acpuclk_set_div(cur_s);
drv_state.current_speed = cur_s;
loops_per_jiffy = cur_s->lpj;
udelay(drv_state.acpu_switch_time_us);
}
if (for_power_collapse)
return 0;
plls_enabled &= ~(1 << tgt_s->pll);
for (pll = ACPU_PLL_0; pll <= ACPU_PLL_2; pll++)
if (plls_enabled & (1 << pll)) {
rc = pc_pll_request(pll, 0);
if (rc < 0) {
pr_err("PLL%d disable failed (%d)\n", pll, rc);
goto out;
}
}
if (strt_s->axiclk_khz != tgt_s->axiclk_khz) {
rc = clk_set_rate(ebi1_clk, tgt_s->axiclk_khz * 1000);
if (rc < 0)
pr_err("Setting AXI min rate failed!\n");
}
if (tgt_s->vdd < strt_s->vdd) {
if (acpuclk_set_vdd_level(tgt_s->vdd) < 0)
printk(KERN_ERR "acpuclock: Unable to drop ACPU vdd\n");
}
#if PERF_SWITCH_DEBUG
printk(KERN_DEBUG "%s: ACPU speed change complete\n", __FUNCTION__);
#endif
out:
if (!for_power_collapse)
mutex_unlock(&drv_state.lock);
return rc;
}
static void __init acpuclk_init(void)
{
struct clkctl_acpu_speed *speed;
uint32_t div, sel;
int rc;
if (!(readl(A11S_CLK_SEL_ADDR) & 0x01)) {
sel = (readl(A11S_CLK_CNTL_ADDR) >> 12) & 0x7;
div = (readl(A11S_CLK_CNTL_ADDR) >> 8) & 0x0f;
} else {
sel = (readl(A11S_CLK_CNTL_ADDR) >> 4) & 0x07;
div = readl(A11S_CLK_CNTL_ADDR) & 0x0f;
}
for (speed = acpu_freq_tbl; speed->a11clk_khz != 0; speed++) {
if (speed->a11clk_src_sel == sel
&& (speed->a11clk_src_div == div))
break;
}
if (speed->a11clk_khz == 0) {
printk(KERN_WARNING "Warning - ACPU clock reports invalid speed\n");
return;
}
drv_state.current_speed = speed;
rc = clk_set_rate(ebi1_clk, speed->axiclk_khz * 1000);
if (rc < 0)
pr_err("Setting AXI min rate failed!\n");
printk(KERN_INFO "ACPU running at %d KHz\n", speed->a11clk_khz);
}
unsigned long acpuclk_get_rate(void)
{
WARN_ONCE(drv_state.current_speed == NULL,
"acpuclk_get_rate: not initialized\n");
if (drv_state.current_speed)
return drv_state.current_speed->a11clk_khz;
else
return 0;
}
uint32_t acpuclk_get_switch_time(void)
{
return drv_state.acpu_switch_time_us;
}
static void __init lpj_init(void)
{
int i;
const struct clkctl_acpu_speed *base_clk = drv_state.current_speed;
for (i = 0; acpu_freq_tbl[i].a11clk_khz; i++) {
acpu_freq_tbl[i].lpj = cpufreq_scale(loops_per_jiffy,
base_clk->a11clk_khz,
acpu_freq_tbl[i].a11clk_khz);
}
}
void __init msm_acpu_clock_init(struct msm_acpu_clock_platform_data *clkdata)
{
pr_info("acpu_clock_init()\n");
ebi1_clk = clk_get(NULL, "ebi1_clk");
mutex_init(&drv_state.lock);
drv_state.acpu_switch_time_us = clkdata->acpu_switch_time_us;
drv_state.max_speed_delta_khz = clkdata->max_speed_delta_khz;
drv_state.vdd_switch_time_us = clkdata->vdd_switch_time_us;
drv_state.power_collapse_khz = clkdata->power_collapse_khz;
drv_state.wait_for_irq_khz = clkdata->wait_for_irq_khz;
acpuclk_init();
lpj_init();
#ifdef CONFIG_CPU_FREQ_TABLE
cpufreq_frequency_table_get_attr(freq_table, smp_processor_id());
#endif
}
