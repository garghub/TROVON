static int sh7372_a4r_pd_suspend(void)
{
sh7372_intcs_suspend();
__raw_writel(0x300fffff, WUPRMSK);
return 0;
}
static int sh7372_a4s_pd_suspend(void)
{
a4s_suspend_ready = true;
return -EBUSY;
}
static void sh7372_a4s_pd_resume(void)
{
a4s_suspend_ready = false;
}
static int sh7372_a3sp_pd_suspend(void)
{
return console_suspend_enabled ? 0 : -EBUSY;
}
void __init sh7372_init_pm_domains(void)
{
rmobile_init_domains(sh7372_pm_domains, ARRAY_SIZE(sh7372_pm_domains));
pm_genpd_add_subdomain_names("A4LC", "A3RV");
pm_genpd_add_subdomain_names("A4R", "A4LC");
pm_genpd_add_subdomain_names("A4S", "A3SG");
pm_genpd_add_subdomain_names("A4S", "A3SP");
}
static void sh7372_set_reset_vector(unsigned long address)
{
__raw_writel(address, SBAR);
__raw_writel(0, APARMBAREA);
}
static void sh7372_enter_sysc(int pllc0_on, unsigned long sleep_mode)
{
if (pllc0_on)
__raw_writel(0, PLLC01STPCR);
else
__raw_writel(1 << 28, PLLC01STPCR);
__raw_readl(WUPSFAC);
cpu_suspend(sleep_mode, sh7372_do_idle_sysc);
__raw_readl(WUPSFAC);
__raw_writel(0, SBAR);
}
static int sh7372_sysc_valid(unsigned long *mskp, unsigned long *msk2p)
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
static void sh7372_setup_sysc(unsigned long msk, unsigned long msk2)
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
static void sh7372_enter_a3sm_common(int pllc0_on)
{
sh7372_setup_sysc(1 << 0, 0);
sh7372_set_reset_vector(__pa(sh7372_resume_core_standby_sysc));
sh7372_enter_sysc(pllc0_on, 1 << 12);
}
static void sh7372_enter_a4s_common(int pllc0_on)
{
sh7372_intca_suspend();
sh7372_set_reset_vector(SMFRAM);
sh7372_enter_sysc(pllc0_on, 1 << 10);
sh7372_intca_resume();
}
static void sh7372_pm_setup_smfram(void)
{
memcpy((void *)SMFRAM, sh7372_resume_core_standby_sysc, 0x100);
}
static inline void sh7372_pm_setup_smfram(void) {}
static int sh7372_do_idle_core_standby(unsigned long unused)
{
cpu_do_idle();
return 0;
}
static int sh7372_enter_core_standby(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
sh7372_set_reset_vector(__pa(sh7372_resume_core_standby_sysc));
__raw_writel(0x10, SYSTBCR);
cpu_suspend(0, sh7372_do_idle_core_standby);
__raw_writel(0, SYSTBCR);
__raw_writel(0, SBAR);
return 1;
}
static int sh7372_enter_a3sm_pll_on(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
sh7372_enter_a3sm_common(1);
return 2;
}
static int sh7372_enter_a3sm_pll_off(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
sh7372_enter_a3sm_common(0);
return 3;
}
static int sh7372_enter_a4s(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
unsigned long msk, msk2;
if (!sh7372_sysc_valid(&msk, &msk2))
return sh7372_enter_a3sm_pll_off(dev, drv, index);
sh7372_setup_sysc(msk, msk2);
sh7372_enter_a4s_common(0);
return 4;
}
static void __init sh7372_cpuidle_init(void)
{
shmobile_cpuidle_set_driver(&sh7372_cpuidle_driver);
}
static void __init sh7372_cpuidle_init(void) {}
static int sh7372_enter_suspend(suspend_state_t suspend_state)
{
unsigned long msk, msk2;
if (sh7372_sysc_valid(&msk, &msk2) && a4s_suspend_ready) {
sh7372_setup_sysc(msk, msk2);
pr_debug("entering A4S\n");
sh7372_enter_a4s_common(0);
return 0;
}
pr_debug("entering A3SM\n");
sh7372_enter_a3sm_common(0);
return 0;
}
static int sh7372_pm_notifier_fn(struct notifier_block *notifier,
unsigned long pm_event, void *unused)
{
switch (pm_event) {
case PM_SUSPEND_PREPARE:
pm_genpd_name_poweron("A4R");
break;
case PM_POST_SUSPEND:
pm_genpd_poweroff_unused();
break;
}
return NOTIFY_DONE;
}
static void sh7372_suspend_init(void)
{
shmobile_suspend_ops.enter = sh7372_enter_suspend;
pm_notifier(sh7372_pm_notifier_fn, 0);
}
static void sh7372_suspend_init(void) {}
void __init sh7372_pm_init(void)
{
__raw_writel(0x0000a500, DBGREG9);
__raw_writel(0x0000a501, DBGREG9);
__raw_writel(0x00000000, DBGREG1);
__raw_writel(0, PDNSEL);
sh7372_pm_setup_smfram();
sh7372_suspend_init();
sh7372_cpuidle_init();
}
void __init sh7372_pm_init_late(void)
{
shmobile_init_late();
pm_genpd_name_attach_cpuidle("A4S", 4);
}
