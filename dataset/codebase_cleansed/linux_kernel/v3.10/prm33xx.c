u32 am33xx_prm_read_reg(s16 inst, u16 idx)
{
return __raw_readl(prm_base + inst + idx);
}
void am33xx_prm_write_reg(u32 val, s16 inst, u16 idx)
{
__raw_writel(val, prm_base + inst + idx);
}
u32 am33xx_prm_rmw_reg_bits(u32 mask, u32 bits, s16 inst, s16 idx)
{
u32 v;
v = am33xx_prm_read_reg(inst, idx);
v &= ~mask;
v |= bits;
am33xx_prm_write_reg(v, inst, idx);
return v;
}
int am33xx_prm_is_hardreset_asserted(u8 shift, s16 inst, u16 rstctrl_offs)
{
u32 v;
v = am33xx_prm_read_reg(inst, rstctrl_offs);
v &= 1 << shift;
v >>= shift;
return v;
}
int am33xx_prm_assert_hardreset(u8 shift, s16 inst, u16 rstctrl_offs)
{
u32 mask = 1 << shift;
am33xx_prm_rmw_reg_bits(mask, mask, inst, rstctrl_offs);
return 0;
}
int am33xx_prm_deassert_hardreset(u8 shift, u8 st_shift, s16 inst,
u16 rstctrl_offs, u16 rstst_offs)
{
int c;
u32 mask = 1 << st_shift;
if (am33xx_prm_is_hardreset_asserted(shift, inst, rstctrl_offs) == 0)
return -EEXIST;
am33xx_prm_rmw_reg_bits(0xffffffff, mask, inst, rstst_offs);
mask = 1 << shift;
am33xx_prm_rmw_reg_bits(mask, 0, inst, rstctrl_offs);
omap_test_timeout(am33xx_prm_is_hardreset_asserted(st_shift, inst,
rstst_offs),
MAX_MODULE_HARDRESET_WAIT, c);
return (c == MAX_MODULE_HARDRESET_WAIT) ? -EBUSY : 0;
}
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
