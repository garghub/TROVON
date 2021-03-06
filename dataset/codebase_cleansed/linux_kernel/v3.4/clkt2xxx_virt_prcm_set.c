unsigned long omap2_table_mpu_recalc(struct clk *clk)
{
return curr_prcm_set->mpu_speed;
}
long omap2_round_to_table_rate(struct clk *clk, unsigned long rate)
{
const struct prcm_config *ptr;
long highest_rate;
highest_rate = -EINVAL;
for (ptr = rate_table; ptr->mpu_speed; ptr++) {
if (!(ptr->flags & cpu_mask))
continue;
if (ptr->xtal_speed != sclk->rate)
continue;
highest_rate = ptr->mpu_speed;
if (ptr->mpu_speed <= rate)
break;
}
return highest_rate;
}
int omap2_select_table_rate(struct clk *clk, unsigned long rate)
{
u32 cur_rate, done_rate, bypass = 0, tmp;
const struct prcm_config *prcm;
unsigned long found_speed = 0;
unsigned long flags;
for (prcm = rate_table; prcm->mpu_speed; prcm++) {
if (!(prcm->flags & cpu_mask))
continue;
if (prcm->xtal_speed != sclk->rate)
continue;
if (prcm->mpu_speed <= rate) {
found_speed = prcm->mpu_speed;
break;
}
}
if (!found_speed) {
printk(KERN_INFO "Could not set MPU rate to %luMHz\n",
rate / 1000000);
return -EINVAL;
}
curr_prcm_set = prcm;
cur_rate = omap2xxx_clk_get_core_rate(dclk);
if (prcm->dpll_speed == cur_rate / 2) {
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL, 1);
} else if (prcm->dpll_speed == cur_rate * 2) {
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);
} else if (prcm->dpll_speed != cur_rate) {
local_irq_save(flags);
if (prcm->dpll_speed == prcm->xtal_speed)
bypass = 1;
if ((prcm->cm_clksel2_pll & OMAP24XX_CORE_CLK_SRC_MASK) ==
CORE_CLK_SRC_DPLL_X2)
done_rate = CORE_CLK_SRC_DPLL_X2;
else
done_rate = CORE_CLK_SRC_DPLL;
omap2_cm_write_mod_reg(prcm->cm_clksel_mpu, MPU_MOD, CM_CLKSEL);
omap2_cm_write_mod_reg(prcm->cm_clksel_dsp,
OMAP24XX_DSP_MOD, CM_CLKSEL);
omap2_cm_write_mod_reg(prcm->cm_clksel_gfx, GFX_MOD, CM_CLKSEL);
tmp = omap2_cm_read_mod_reg(CORE_MOD, CM_CLKSEL1) & OMAP24XX_CLKSEL_DSS2_MASK;
omap2_cm_write_mod_reg(prcm->cm_clksel1_core | tmp, CORE_MOD,
CM_CLKSEL1);
if (cpu_is_omap2430())
omap2_cm_write_mod_reg(prcm->cm_clksel_mdm,
OMAP2430_MDM_MOD, CM_CLKSEL);
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);
omap2_set_prcm(prcm->cm_clksel1_pll, prcm->base_sdrc_rfr,
bypass);
omap2xxx_sdrc_init_params(omap2xxx_sdrc_dll_is_unlocked());
omap2xxx_sdrc_reprogram(done_rate, 0);
local_irq_restore(flags);
}
return 0;
}
