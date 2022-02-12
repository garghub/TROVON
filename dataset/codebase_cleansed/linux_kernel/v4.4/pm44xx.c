static int omap4_pm_suspend(void)
{
struct power_state *pwrst;
int state, ret = 0;
u32 cpu_id = smp_processor_id();
list_for_each_entry(pwrst, &pwrst_list, node) {
pwrst->saved_state = pwrdm_read_next_pwrst(pwrst->pwrdm);
pwrst->saved_logic_state = pwrdm_read_logic_retst(pwrst->pwrdm);
}
list_for_each_entry(pwrst, &pwrst_list, node) {
omap_set_pwrdm_state(pwrst->pwrdm, pwrst->next_state);
pwrdm_set_logic_retst(pwrst->pwrdm, pwrst->next_logic_state);
}
omap4_enter_lowpower(cpu_id, cpu_suspend_state);
list_for_each_entry(pwrst, &pwrst_list, node) {
state = pwrdm_read_prev_pwrst(pwrst->pwrdm);
if (state > pwrst->next_state) {
pr_info("Powerdomain (%s) didn't enter target state %d\n",
pwrst->pwrdm->name, pwrst->next_state);
ret = -1;
}
omap_set_pwrdm_state(pwrst->pwrdm, pwrst->saved_state);
pwrdm_set_logic_retst(pwrst->pwrdm, pwrst->saved_logic_state);
}
if (ret) {
pr_crit("Could not enter target state in pm_suspend\n");
pr_warn("A possible cause could be an old bootloader - try u-boot >= v2012.07\n");
} else {
pr_info("Successfully put all powerdomains to target state\n");
}
return 0;
}
static int __init pwrdms_setup(struct powerdomain *pwrdm, void *unused)
{
struct power_state *pwrst;
if (!pwrdm->pwrsts)
return 0;
if (!strncmp(pwrdm->name, "cpu", 3)) {
if (IS_PM44XX_ERRATUM(PM_OMAP4_CPU_OSWR_DISABLE))
cpu_suspend_state = PWRDM_POWER_RET;
return 0;
}
pwrst = kmalloc(sizeof(struct power_state), GFP_ATOMIC);
if (!pwrst)
return -ENOMEM;
pwrst->pwrdm = pwrdm;
pwrst->next_state = pwrdm_get_valid_lp_state(pwrdm, false,
PWRDM_POWER_RET);
pwrst->next_logic_state = pwrdm_get_valid_lp_state(pwrdm, true,
PWRDM_POWER_OFF);
list_add(&pwrst->node, &pwrst_list);
return omap_set_pwrdm_state(pwrst->pwrdm, pwrst->next_state);
}
static void omap_default_idle(void)
{
omap_do_wfi();
}
static inline int omap4plus_init_static_deps(const struct static_dep_map *map)
{
int ret;
struct clockdomain *from, *to;
if (!map)
return 0;
while (map->from) {
from = clkdm_lookup(map->from);
to = clkdm_lookup(map->to);
if (!from || !to) {
pr_err("Failed lookup %s or %s for wakeup dependency\n",
map->from, map->to);
return -EINVAL;
}
ret = clkdm_add_wkdep(from, to);
if (ret) {
pr_err("Failed to add %s -> %s wakeup dependency(%d)\n",
map->from, map->to, ret);
return ret;
}
map++;
}
return 0;
}
int __init omap4_pm_init_early(void)
{
if (cpu_is_omap446x())
pm44xx_errata |= PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD;
if (soc_is_omap54xx() || soc_is_dra7xx())
pm44xx_errata |= PM_OMAP4_CPU_OSWR_DISABLE;
return 0;
}
int __init omap4_pm_init(void)
{
int ret = 0;
if (omap_rev() == OMAP4430_REV_ES1_0) {
WARN(1, "Power Management not supported on OMAP4430 ES1.0\n");
return -ENODEV;
}
pr_info("Power Management for TI OMAP4+ devices.\n");
if (cpu_is_omap44xx())
pr_warn("OMAP4 PM: u-boot >= v2012.07 is required for full PM support\n");
ret = pwrdm_for_each(pwrdms_setup, NULL);
if (ret) {
pr_err("Failed to setup powerdomains.\n");
goto err2;
}
if (cpu_is_omap44xx())
ret = omap4plus_init_static_deps(omap4_static_dep_map);
else if (soc_is_omap54xx() || soc_is_dra7xx())
ret = omap4plus_init_static_deps(omap5_dra7_static_dep_map);
if (ret) {
pr_err("Failed to initialise static dependencies.\n");
goto err2;
}
ret = omap4_mpuss_init();
if (ret) {
pr_err("Failed to initialise OMAP4 MPUSS\n");
goto err2;
}
(void) clkdm_for_each(omap_pm_clkdms_setup, NULL);
omap_common_suspend_init(omap4_pm_suspend);
arm_pm_idle = omap_default_idle;
if (cpu_is_omap44xx())
omap4_idle_init();
err2:
return ret;
}
