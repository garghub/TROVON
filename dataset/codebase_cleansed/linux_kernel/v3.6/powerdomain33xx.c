static int am33xx_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
am33xx_prm_rmw_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
return 0;
}
static int am33xx_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
v &= OMAP_POWERSTATE_MASK;
v >>= OMAP_POWERSTATE_SHIFT;
return v;
}
static int am33xx_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
v &= OMAP_POWERSTATEST_MASK;
v >>= OMAP_POWERSTATEST_SHIFT;
return v;
}
static int am33xx_pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
v &= AM33XX_LASTPOWERSTATEENTERED_MASK;
v >>= AM33XX_LASTPOWERSTATEENTERED_SHIFT;
return v;
}
static int am33xx_pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm)
{
am33xx_prm_rmw_reg_bits(AM33XX_LOWPOWERSTATECHANGE_MASK,
(1 << AM33XX_LOWPOWERSTATECHANGE_SHIFT),
pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
return 0;
}
static int am33xx_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
am33xx_prm_rmw_reg_bits(AM33XX_LASTPOWERSTATEENTERED_MASK,
AM33XX_LASTPOWERSTATEENTERED_MASK,
pwrdm->prcm_offs, pwrdm->pwrstst_offs);
return 0;
}
static int am33xx_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
u32 m;
m = pwrdm->logicretstate_mask;
if (!m)
return -EINVAL;
am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
return 0;
}
static int am33xx_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
v &= AM33XX_LOGICSTATEST_MASK;
v >>= AM33XX_LOGICSTATEST_SHIFT;
return v;
}
static int am33xx_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
u32 v, m;
m = pwrdm->logicretstate_mask;
if (!m)
return -EINVAL;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
v &= m;
v >>= __ffs(m);
return v;
}
static int am33xx_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = pwrdm->mem_on_mask[bank];
if (!m)
return -EINVAL;
am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
return 0;
}
static int am33xx_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = pwrdm->mem_ret_mask[bank];
if (!m)
return -EINVAL;
am33xx_prm_rmw_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
return 0;
}
static int am33xx_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = pwrdm->mem_pwrst_mask[bank];
if (!m)
return -EINVAL;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs);
v &= m;
v >>= __ffs(m);
return v;
}
static int am33xx_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = pwrdm->mem_retst_mask[bank];
if (!m)
return -EINVAL;
v = am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstctrl_offs);
v &= m;
v >>= __ffs(m);
return v;
}
static int am33xx_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((am33xx_prm_read_reg(pwrdm->prcm_offs, pwrdm->pwrstst_offs)
& OMAP_INTRANSITION_MASK) &&
(c++ < PWRDM_TRANSITION_BAILOUT))
udelay(1);
if (c > PWRDM_TRANSITION_BAILOUT) {
pr_err("powerdomain: %s: waited too long to complete transition\n",
pwrdm->name);
return -EAGAIN;
}
pr_debug("powerdomain: completed transition in %d loops\n", c);
return 0;
}
