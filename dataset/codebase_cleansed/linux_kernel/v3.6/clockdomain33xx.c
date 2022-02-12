static int am33xx_clkdm_sleep(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_force_sleep(clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static int am33xx_clkdm_wakeup(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_force_wakeup(clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static void am33xx_clkdm_allow_idle(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_enable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}
static void am33xx_clkdm_deny_idle(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_disable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}
static int am33xx_clkdm_clk_enable(struct clockdomain *clkdm)
{
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
return am33xx_clkdm_wakeup(clkdm);
return 0;
}
static int am33xx_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
hwsup = am33xx_cm_is_clkdm_in_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
if (!hwsup && (clkdm->flags & CLKDM_CAN_FORCE_SLEEP))
am33xx_clkdm_sleep(clkdm);
return 0;
}
