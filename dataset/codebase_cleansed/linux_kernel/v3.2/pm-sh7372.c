static int pd_power_down(struct generic_pm_domain *genpd)
{
struct sh7372_pm_domain *sh7372_pd = to_sh7372_pd(genpd);
unsigned int mask = 1 << sh7372_pd->bit_shift;
if (sh7372_pd->suspend)
sh7372_pd->suspend();
if (sh7372_pd->stay_on)
return 0;
if (__raw_readl(PSTR) & mask) {
unsigned int retry_count;
__raw_writel(mask, SPDCR);
for (retry_count = PSTR_RETRIES; retry_count; retry_count--) {
if (!(__raw_readl(SPDCR) & mask))
break;
cpu_relax();
}
}
if (!sh7372_pd->no_debug)
pr_debug("sh7372 power domain down 0x%08x -> PSTR = 0x%08x\n",
mask, __raw_readl(PSTR));
return 0;
}
static int __pd_power_up(struct sh7372_pm_domain *sh7372_pd, bool do_resume)
{
unsigned int mask = 1 << sh7372_pd->bit_shift;
unsigned int retry_count;
int ret = 0;
if (sh7372_pd->stay_on)
goto out;
if (__raw_readl(PSTR) & mask)
goto out;
__raw_writel(mask, SWUCR);
for (retry_count = 2 * PSTR_RETRIES; retry_count; retry_count--) {
if (!(__raw_readl(SWUCR) & mask))
break;
if (retry_count > PSTR_RETRIES)
udelay(PSTR_DELAY_US);
else
cpu_relax();
}
if (!retry_count)
ret = -EIO;
if (!sh7372_pd->no_debug)
pr_debug("sh7372 power domain up 0x%08x -> PSTR = 0x%08x\n",
mask, __raw_readl(PSTR));
out:
if (ret == 0 && sh7372_pd->resume && do_resume)
sh7372_pd->resume();
return ret;
}
static int pd_power_up(struct generic_pm_domain *genpd)
{
return __pd_power_up(to_sh7372_pd(genpd), true);
}
static void sh7372_a4r_suspend(void)
{
sh7372_intcs_suspend();
__raw_writel(0x300fffff, WUPRMSK);
}
static bool pd_active_wakeup(struct device *dev)
{
return true;
}
static bool sh7372_power_down_forbidden(struct dev_pm_domain *domain)
{
return false;
}
void sh7372_init_pm_domain(struct sh7372_pm_domain *sh7372_pd)
{
struct generic_pm_domain *genpd = &sh7372_pd->genpd;
pm_genpd_init(genpd, sh7372_pd->gov, false);
genpd->stop_device = pm_clk_suspend;
genpd->start_device = pm_clk_resume;
genpd->dev_irq_safe = true;
genpd->active_wakeup = pd_active_wakeup;
genpd->power_off = pd_power_down;
genpd->power_on = pd_power_up;
__pd_power_up(sh7372_pd, false);
}
void sh7372_add_device_to_domain(struct sh7372_pm_domain *sh7372_pd,
struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
pm_genpd_add_device(&sh7372_pd->genpd, dev);
if (pm_clk_no_clocks(dev))
pm_clk_add(dev, NULL);
}
void sh7372_pm_add_subdomain(struct sh7372_pm_domain *sh7372_pd,
struct sh7372_pm_domain *sh7372_sd)
{
pm_genpd_add_subdomain(&sh7372_pd->genpd, &sh7372_sd->genpd);
}
static void sh7372_a3sp_init(void)
{
sh7372_a3sp.stay_on = !console_suspend_enabled;
}
static inline void sh7372_a3sp_init(void) {}
static int sh7372_do_idle_core_standby(unsigned long unused)
{
cpu_do_idle();
return 0;
}
static void sh7372_enter_core_standby(void)
{
__raw_writel(__pa(sh7372_resume_core_standby_a3sm), SBAR);
__raw_writel(0, APARMBAREA);
__raw_writel(0x10, SYSTBCR);
cpu_suspend(0, sh7372_do_idle_core_standby);
__raw_writel(0, SYSTBCR);
__raw_writel(0, SBAR);
}
static void sh7372_enter_a3sm_common(int pllc0_on)
{
__raw_writel(__pa(sh7372_resume_core_standby_a3sm), SBAR);
__raw_writel(0, APARMBAREA);
if (pllc0_on)
__raw_writel(0, PLLC01STPCR);
else
__raw_writel(1 << 28, PLLC01STPCR);
__raw_writel(0, PDNSEL);
__raw_readl(WUPSFAC);
cpu_suspend(0, sh7372_do_idle_a3sm);
__raw_readl(WUPSFAC);
__raw_writel(0, SBAR);
}
static int sh7372_a3sm_valid(unsigned long *mskp, unsigned long *msk2p)
{
unsigned long mstpsr0, mstpsr1, mstpsr2, mstpsr3, mstpsr4;
unsigned long msk, msk2;
mstpsr0 = __raw_readl(MSTPSR0);
if ((mstpsr0 & 0x00000003) != 0x00000003) {
pr_debug("sh7372 mstpsr0 0x%08lx\n", mstpsr0);
return 0;
}
mstpsr1 = __raw_readl(MSTPSR1);
if ((mstpsr1 & 0xff079b7f) != 0xff079b7f) {
pr_debug("sh7372 mstpsr1 0x%08lx\n", mstpsr1);
return 0;
}
mstpsr2 = __raw_readl(MSTPSR2);
if ((mstpsr2 & 0x000741ff) != 0x000741ff) {
pr_debug("sh7372 mstpsr2 0x%08lx\n", mstpsr2);
return 0;
}
mstpsr3 = __raw_readl(MSTPSR3);
if ((mstpsr3 & 0x1a60f010) != 0x1a60f010) {
pr_debug("sh7372 mstpsr3 0x%08lx\n", mstpsr3);
return 0;
}
mstpsr4 = __raw_readl(MSTPSR4);
if ((mstpsr4 & 0x00008cf0) != 0x00008cf0) {
pr_debug("sh7372 mstpsr4 0x%08lx\n", mstpsr4);
return 0;
}
msk = 0;
msk2 = 0;
if ((mstpsr2 & (1 << 23)) == 0)
msk |= 1 << 31;
if ((mstpsr2 & (1 << 12)) == 0)
msk |= 1 << 21;
if ((mstpsr4 & (1 << 3)) == 0)
msk |= 1 << 2;
if ((mstpsr1 & (1 << 24)) == 0)
msk |= 1 << 1;
if ((mstpsr3 & (1 << 29)) == 0)
msk |= 1 << 1;
if ((mstpsr4 & (1 << 0)) == 0)
msk |= 1 << 1;
if ((mstpsr2 & (1 << 13)) == 0)
msk2 |= 1 << 17;
*mskp = msk;
*msk2p = msk2;
return 1;
}
static void sh7372_icr_to_irqcr(unsigned long icr, u16 *irqcr1p, u16 *irqcr2p)
{
u16 tmp, irqcr1, irqcr2;
int k;
irqcr1 = 0;
irqcr2 = 0;
for (k = 0; k <= 7; k++) {
tmp = (icr >> ((7 - k) * 4)) & 0xf;
irqcr1 |= (tmp & 0x03) << (k * 2);
irqcr2 |= (tmp >> 2) << (k * 2);
}
*irqcr1p = irqcr1;
*irqcr2p = irqcr2;
}
static void sh7372_setup_a3sm(unsigned long msk, unsigned long msk2)
{
u16 irqcrx_low, irqcrx_high, irqcry_low, irqcry_high;
unsigned long tmp;
tmp = bitrev8(__raw_readb(INTMSK00A));
tmp |= bitrev8(__raw_readb(INTMSK10A)) << 8;
msk = (~msk & 0xc030000f) | (tmp << 4);
__raw_writel(msk, WUPSMSK);
sh7372_icr_to_irqcr(__raw_readl(ICR1A), &irqcrx_low, &irqcry_low);
sh7372_icr_to_irqcr(__raw_readl(ICR2A), &irqcrx_high, &irqcry_high);
__raw_writel((irqcrx_high << 16) | irqcrx_low, IRQCR);
__raw_writel((irqcry_high << 16) | irqcry_low, IRQCR2);
tmp = bitrev8(__raw_readb(INTMSK20A));
tmp |= bitrev8(__raw_readb(INTMSK30A)) << 8;
msk2 = (~msk2 & 0x00030000) | tmp;
__raw_writel(msk2, WUPSMSK2);
sh7372_icr_to_irqcr(__raw_readl(ICR3A), &irqcrx_low, &irqcry_low);
sh7372_icr_to_irqcr(__raw_readl(ICR4A), &irqcrx_high, &irqcry_high);
__raw_writel((irqcrx_high << 16) | irqcrx_low, IRQCR3);
__raw_writel((irqcry_high << 16) | irqcry_low, IRQCR4);
}
static void sh7372_cpuidle_setup(struct cpuidle_driver *drv)
{
struct cpuidle_state *state = &drv->states[drv->state_count];
snprintf(state->name, CPUIDLE_NAME_LEN, "C2");
strncpy(state->desc, "Core Standby Mode", CPUIDLE_DESC_LEN);
state->exit_latency = 10;
state->target_residency = 20 + 10;
state->flags = CPUIDLE_FLAG_TIME_VALID;
shmobile_cpuidle_modes[drv->state_count] = sh7372_enter_core_standby;
drv->state_count++;
}
static void sh7372_cpuidle_init(void)
{
shmobile_cpuidle_setup = sh7372_cpuidle_setup;
}
static void sh7372_cpuidle_init(void) {}
static int sh7372_enter_suspend(suspend_state_t suspend_state)
{
unsigned long msk, msk2;
if (sh7372_a3sm_valid(&msk, &msk2)) {
sh7372_setup_a3sm(msk, msk2);
pr_debug("entering A3SM\n");
sh7372_enter_a3sm_common(0);
} else {
pr_debug("entering Core Standby\n");
sh7372_enter_core_standby();
}
return 0;
}
static void sh7372_suspend_init(void)
{
shmobile_suspend_ops.enter = sh7372_enter_suspend;
}
static void sh7372_suspend_init(void) {}
void __init sh7372_pm_init(void)
{
__raw_writel(0x0000a500, DBGREG9);
__raw_writel(0x0000a501, DBGREG9);
__raw_writel(0x00000000, DBGREG1);
__raw_writel(0, PDNSEL);
sh7372_a3sp_init();
sh7372_suspend_init();
sh7372_cpuidle_init();
}
