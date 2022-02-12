int __init omap1_clk_init(void)
{
struct omap_clk *c;
const struct omap_clock_config *info;
int crystal_type = 0;
u32 reg, cpu_mask;
#ifdef CONFIG_DEBUG_LL
omap_writel(0x3 << 29, MOD_CONF_CTRL_0);
#endif
reg = omap_readw(SOFT_REQ_REG) & (1 << 4);
omap_writew(reg, SOFT_REQ_REG);
if (!cpu_is_omap15xx())
omap_writew(0, SOFT_REQ_REG2);
clk_init(&omap1_clk_functions);
arm_idlect1_mask = ~0;
for (c = omap_clks; c < omap_clks + ARRAY_SIZE(omap_clks); c++)
clk_preinit(c->lk.clk);
cpu_mask = 0;
if (cpu_is_omap16xx())
cpu_mask |= CK_16XX;
if (cpu_is_omap1510())
cpu_mask |= CK_1510;
if (cpu_is_omap7xx())
cpu_mask |= CK_7XX;
if (cpu_is_omap310())
cpu_mask |= CK_310;
for (c = omap_clks; c < omap_clks + ARRAY_SIZE(omap_clks); c++)
if (c->cpu & cpu_mask) {
clkdev_add(&c->lk);
clk_register(c->lk.clk);
}
api_ck_p = clk_get(NULL, "api_ck");
ck_dpll1_p = clk_get(NULL, "ck_dpll1");
ck_ref_p = clk_get(NULL, "ck_ref");
info = omap_get_config(OMAP_TAG_CLOCK, struct omap_clock_config);
if (info != NULL) {
if (!cpu_is_omap15xx())
crystal_type = info->system_clock_type;
}
if (cpu_is_omap7xx())
ck_ref.rate = 13000000;
if (cpu_is_omap16xx() && crystal_type == 2)
ck_ref.rate = 19200000;
pr_info("Clocks: ARM_SYSST: 0x%04x DPLL_CTL: 0x%04x ARM_CKCTL: "
"0x%04x\n", omap_readw(ARM_SYSST), omap_readw(DPLL_CTL),
omap_readw(ARM_CKCTL));
omap_writew(0x1000, ARM_SYSST);
#ifdef CONFIG_OMAP_CLOCKS_SET_BY_BOOTLOADER
{
unsigned pll_ctl_val = omap_readw(DPLL_CTL);
ck_dpll1.rate = ck_ref.rate;
if (pll_ctl_val & 0x10) {
if (pll_ctl_val & 0xf80)
ck_dpll1.rate *= (pll_ctl_val & 0xf80) >> 7;
ck_dpll1.rate /= ((pll_ctl_val & 0x60) >> 5) + 1;
} else {
switch (pll_ctl_val & 0xc) {
case 0:
break;
case 0x4:
ck_dpll1.rate /= 2;
break;
default:
ck_dpll1.rate /= 4;
break;
}
}
}
#else
if (omap1_select_table_rate(&virtual_ck_mpu, ~0)) {
printk(KERN_ERR "System frequencies not set. Check your config.\n");
omap_writew(0x2290, DPLL_CTL);
omap_writew(cpu_is_omap7xx() ? 0x3005 : 0x1005, ARM_CKCTL);
ck_dpll1.rate = 60000000;
}
#endif
propagate_rate(&ck_dpll1);
propagate_rate(&ck_ref);
printk(KERN_INFO "Clocking rate (xtal/DPLL1/MPU): "
"%ld.%01ld/%ld.%01ld/%ld.%01ld MHz\n",
ck_ref.rate / 1000000, (ck_ref.rate / 100000) % 10,
ck_dpll1.rate / 1000000, (ck_dpll1.rate / 100000) % 10,
arm_ck.rate / 1000000, (arm_ck.rate / 100000) % 10);
if (machine_is_omap_perseus2() || machine_is_omap_fsample()) {
omap_writew(omap_readw(OMAP7XX_PCC_UPLD_CTRL) & ~0x1,
OMAP7XX_PCC_UPLD_CTRL);
}
if (machine_is_ams_delta())
omap_writel(omap_readl(ULPD_CLOCK_CTRL) |
(1 << SDW_MCLK_INV_BIT),
ULPD_CLOCK_CTRL);
if (cpu_is_omap7xx())
omap_writew(omap_readw(ARM_CKCTL) & 0x2fff, ARM_CKCTL);
else
omap_writew(omap_readw(ARM_CKCTL) & 0x0fff, ARM_CKCTL);
omap_writew(0, ARM_RSTCT1);
omap_writew(1, ARM_RSTCT2);
omap_writew(0x400, ARM_IDLECT1);
omap_writew(0x0000, ARM_IDLECT2);
clk_enable(&armper_ck.clk);
clk_enable(&armxor_ck.clk);
clk_enable(&armtim_ck.clk);
if (cpu_is_omap15xx())
clk_enable(&arm_gpio_ck);
return 0;
}
