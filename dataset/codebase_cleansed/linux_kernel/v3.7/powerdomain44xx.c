static int omap4_pwrdm_set_next_pwrst(struct powerdomain *pwrdm, u8 pwrst)
{
omap4_prminst_rmw_inst_reg_bits(OMAP_POWERSTATE_MASK,
(pwrst << OMAP_POWERSTATE_SHIFT),
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_read_next_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= OMAP_POWERSTATE_MASK;
v >>= OMAP_POWERSTATE_SHIFT;
return v;
}
static int omap4_pwrdm_read_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP_POWERSTATEST_MASK;
v >>= OMAP_POWERSTATEST_SHIFT;
return v;
}
static int omap4_pwrdm_read_prev_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP4430_LASTPOWERSTATEENTERED_MASK;
v >>= OMAP4430_LASTPOWERSTATEENTERED_SHIFT;
return v;
}
static int omap4_pwrdm_set_lowpwrstchange(struct powerdomain *pwrdm)
{
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOWPOWERSTATECHANGE_MASK,
(1 << OMAP4430_LOWPOWERSTATECHANGE_SHIFT),
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_clear_all_prev_pwrst(struct powerdomain *pwrdm)
{
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LASTPOWERSTATEENTERED_MASK,
OMAP4430_LASTPOWERSTATEENTERED_MASK,
pwrdm->prcm_partition,
pwrdm->prcm_offs, OMAP4_PM_PWSTST);
return 0;
}
static int omap4_pwrdm_set_logic_retst(struct powerdomain *pwrdm, u8 pwrst)
{
u32 v;
v = pwrst << __ffs(OMAP4430_LOGICRETSTATE_MASK);
omap4_prminst_rmw_inst_reg_bits(OMAP4430_LOGICRETSTATE_MASK, v,
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_set_mem_onst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_onstate_mask(bank);
omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_set_mem_retst(struct powerdomain *pwrdm, u8 bank,
u8 pwrst)
{
u32 m;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
omap4_prminst_rmw_inst_reg_bits(m, (pwrst << __ffs(m)),
pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
return 0;
}
static int omap4_pwrdm_read_logic_pwrst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= OMAP4430_LOGICSTATEST_MASK;
v >>= OMAP4430_LOGICSTATEST_SHIFT;
return v;
}
static int omap4_pwrdm_read_logic_retst(struct powerdomain *pwrdm)
{
u32 v;
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= OMAP4430_LOGICRETSTATE_MASK;
v >>= OMAP4430_LOGICRETSTATE_SHIFT;
return v;
}
static int omap4_pwrdm_read_prev_logic_pwrst(struct powerdomain *pwrdm)
{
int state;
state = omap4_pwrdm_read_prev_pwrst(pwrdm);
if (state == PWRDM_POWER_OFF)
return PWRDM_POWER_OFF;
if (state != PWRDM_POWER_RET)
return PWRDM_POWER_RET;
return omap4_pwrdm_read_logic_retst(pwrdm);
}
static int omap4_pwrdm_read_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = omap2_pwrdm_get_mem_bank_stst_mask(bank);
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTST);
v &= m;
v >>= __ffs(m);
return v;
}
static int omap4_pwrdm_read_mem_retst(struct powerdomain *pwrdm, u8 bank)
{
u32 m, v;
m = omap2_pwrdm_get_mem_bank_retst_mask(bank);
v = omap4_prminst_read_inst_reg(pwrdm->prcm_partition, pwrdm->prcm_offs,
OMAP4_PM_PWSTCTRL);
v &= m;
v >>= __ffs(m);
return v;
}
static int omap4_pwrdm_read_prev_mem_pwrst(struct powerdomain *pwrdm, u8 bank)
{
int state;
state = omap4_pwrdm_read_prev_pwrst(pwrdm);
if (state == PWRDM_POWER_OFF)
return PWRDM_POWER_OFF;
if (state != PWRDM_POWER_RET)
return PWRDM_POWER_RET;
return omap4_pwrdm_read_mem_retst(pwrdm, bank);
}
static int omap4_pwrdm_wait_transition(struct powerdomain *pwrdm)
{
u32 c = 0;
while ((omap4_prminst_read_inst_reg(pwrdm->prcm_partition,
pwrdm->prcm_offs,
OMAP4_PM_PWSTST) &
OMAP_INTRANSITION_MASK) &&
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
