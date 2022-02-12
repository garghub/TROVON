static inline u32 tegra_pmc_readl(u32 reg)
{
return readl(tegra_pmc_base + reg);
}
static inline void tegra_pmc_writel(u32 val, u32 reg)
{
writel(val, tegra_pmc_base + reg);
}
static int tegra_pmc_get_cpu_powerdomain_id(int cpuid)
{
if (cpuid <= 0 || cpuid >= num_possible_cpus())
return -EINVAL;
return tegra_cpu_domains[cpuid];
}
static bool tegra_pmc_powergate_is_powered(int id)
{
return (tegra_pmc_readl(PMC_PWRGATE_STATUS) >> id) & 1;
}
static int tegra_pmc_powergate_set(int id, bool new_state)
{
bool old_state;
unsigned long flags;
spin_lock_irqsave(&tegra_powergate_lock, flags);
old_state = tegra_pmc_powergate_is_powered(id);
WARN_ON(old_state == new_state);
tegra_pmc_writel(PMC_PWRGATE_TOGGLE_START | id, PMC_PWRGATE_TOGGLE);
spin_unlock_irqrestore(&tegra_powergate_lock, flags);
return 0;
}
static int tegra_pmc_powergate_remove_clamping(int id)
{
u32 mask;
if (id == TEGRA_POWERGATE_VDEC)
mask = (1 << TEGRA_POWERGATE_PCIE);
else if (id == TEGRA_POWERGATE_PCIE)
mask = (1 << TEGRA_POWERGATE_VDEC);
else
mask = (1 << id);
tegra_pmc_writel(mask, PMC_REMOVE_CLAMPING);
return 0;
}
bool tegra_pmc_cpu_is_powered(int cpuid)
{
int id;
id = tegra_pmc_get_cpu_powerdomain_id(cpuid);
if (id < 0)
return false;
return tegra_pmc_powergate_is_powered(id);
}
int tegra_pmc_cpu_power_on(int cpuid)
{
int id;
id = tegra_pmc_get_cpu_powerdomain_id(cpuid);
if (id < 0)
return id;
return tegra_pmc_powergate_set(id, true);
}
int tegra_pmc_cpu_remove_clamping(int cpuid)
{
int id;
id = tegra_pmc_get_cpu_powerdomain_id(cpuid);
if (id < 0)
return id;
return tegra_pmc_powergate_remove_clamping(id);
}
static void set_power_timers(u32 us_on, u32 us_off, unsigned long rate)
{
unsigned long long ticks;
unsigned long long pclk;
static unsigned long tegra_last_pclk;
if (WARN_ON_ONCE(rate <= 0))
pclk = 100000000;
else
pclk = rate;
if ((rate != tegra_last_pclk)) {
ticks = (us_on * pclk) + 999999ull;
do_div(ticks, 1000000);
tegra_pmc_writel((unsigned long)ticks, PMC_CPUPWRGOOD_TIMER);
ticks = (us_off * pclk) + 999999ull;
do_div(ticks, 1000000);
tegra_pmc_writel((unsigned long)ticks, PMC_CPUPWROFF_TIMER);
wmb();
}
tegra_last_pclk = pclk;
}
enum tegra_suspend_mode tegra_pmc_get_suspend_mode(void)
{
return pmc_pm_data.suspend_mode;
}
void tegra_pmc_pm_set(enum tegra_suspend_mode mode)
{
u32 reg;
unsigned long rate = 0;
reg = tegra_pmc_readl(PMC_CTRL);
reg |= TEGRA_POWER_CPU_PWRREQ_OE;
reg &= ~TEGRA_POWER_EFFECT_LP0;
switch (mode) {
case TEGRA_SUSPEND_LP2:
rate = clk_get_rate(tegra_pclk);
break;
default:
break;
}
set_power_timers(pmc_pm_data.cpu_good_time, pmc_pm_data.cpu_off_time,
rate);
tegra_pmc_writel(reg, PMC_CTRL);
}
void tegra_pmc_suspend_init(void)
{
u32 reg;
reg = tegra_pmc_readl(PMC_CTRL);
reg |= TEGRA_POWER_CPU_PWRREQ_OE;
tegra_pmc_writel(reg, PMC_CTRL);
}
static void __init tegra_pmc_parse_dt(void)
{
struct device_node *np;
u32 prop;
enum tegra_suspend_mode suspend_mode;
u32 core_good_time[2] = {0, 0};
u32 lp0_vec[2] = {0, 0};
np = of_find_matching_node(NULL, matches);
BUG_ON(!np);
tegra_pmc_base = of_iomap(np, 0);
tegra_pmc_invert_interrupt = of_property_read_bool(np,
"nvidia,invert-interrupt");
tegra_pclk = of_clk_get_by_name(np, "pclk");
WARN_ON(IS_ERR(tegra_pclk));
if (of_property_read_u32(np, "nvidia,suspend-mode", &prop)) {
suspend_mode = TEGRA_SUSPEND_NONE;
} else {
switch (prop) {
case 0:
suspend_mode = TEGRA_SUSPEND_LP0;
break;
case 1:
suspend_mode = TEGRA_SUSPEND_LP1;
break;
case 2:
suspend_mode = TEGRA_SUSPEND_LP2;
break;
default:
suspend_mode = TEGRA_SUSPEND_NONE;
break;
}
}
suspend_mode = tegra_pm_validate_suspend_mode(suspend_mode);
if (of_property_read_u32(np, "nvidia,cpu-pwr-good-time", &prop))
suspend_mode = TEGRA_SUSPEND_NONE;
pmc_pm_data.cpu_good_time = prop;
if (of_property_read_u32(np, "nvidia,cpu-pwr-off-time", &prop))
suspend_mode = TEGRA_SUSPEND_NONE;
pmc_pm_data.cpu_off_time = prop;
if (of_property_read_u32_array(np, "nvidia,core-pwr-good-time",
core_good_time, ARRAY_SIZE(core_good_time)))
suspend_mode = TEGRA_SUSPEND_NONE;
pmc_pm_data.core_osc_time = core_good_time[0];
pmc_pm_data.core_pmu_time = core_good_time[1];
if (of_property_read_u32(np, "nvidia,core-pwr-off-time",
&prop))
suspend_mode = TEGRA_SUSPEND_NONE;
pmc_pm_data.core_off_time = prop;
pmc_pm_data.corereq_high = of_property_read_bool(np,
"nvidia,core-power-req-active-high");
pmc_pm_data.sysclkreq_high = of_property_read_bool(np,
"nvidia,sys-clock-req-active-high");
pmc_pm_data.combined_req = of_property_read_bool(np,
"nvidia,combined-power-req");
pmc_pm_data.cpu_pwr_good_en = of_property_read_bool(np,
"nvidia,cpu-pwr-good-en");
if (of_property_read_u32_array(np, "nvidia,lp0-vec", lp0_vec,
ARRAY_SIZE(lp0_vec)))
if (suspend_mode == TEGRA_SUSPEND_LP0)
suspend_mode = TEGRA_SUSPEND_LP1;
pmc_pm_data.lp0_vec_phy_addr = lp0_vec[0];
pmc_pm_data.lp0_vec_size = lp0_vec[1];
pmc_pm_data.suspend_mode = suspend_mode;
}
void __init tegra_pmc_init(void)
{
u32 val;
tegra_pmc_parse_dt();
val = tegra_pmc_readl(PMC_CTRL);
if (tegra_pmc_invert_interrupt)
val |= PMC_CTRL_INTR_LOW;
else
val &= ~PMC_CTRL_INTR_LOW;
tegra_pmc_writel(val, PMC_CTRL);
}
