static void omap3430es2_clk_ssi_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_SSI_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
static void omap3430es2_clk_dss_usbhost_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_DSS_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
static void omap3430es2_clk_hsotgusb_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = OMAP3430ES2_ST_HSOTGUSB_IDLE_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
static void am35xx_clk_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
*idlest_reg = (__force void __iomem *)(clk->enable_reg);
*idlest_bit = clk->enable_bit + AM35XX_IPSS_ICK_EN_ACK_OFFSET;
*idlest_val = AM35XX_IPSS_CLK_IDLEST_VAL;
}
static void am35xx_clk_find_companion(struct clk_hw_omap *clk,
void __iomem **other_reg,
u8 *other_bit)
{
*other_reg = (__force void __iomem *)(clk->enable_reg);
if (clk->enable_bit & AM35XX_IPSS_ICK_MASK)
*other_bit = clk->enable_bit + AM35XX_IPSS_ICK_FCK_OFFSET;
else
*other_bit = clk->enable_bit - AM35XX_IPSS_ICK_FCK_OFFSET;
}
static void am35xx_clk_ipss_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg,
u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = AM35XX_ST_IPSS_SHIFT;
*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}
void __init omap3_clk_lock_dpll5(void)
{
struct clk *dpll5_clk;
struct clk *dpll5_m2_clk;
dpll5_clk = clk_get(NULL, "dpll5_ck");
clk_set_rate(dpll5_clk, OMAP3_DPLL5_FREQ_FOR_USBHOST * 8);
clk_prepare_enable(dpll5_clk);
dpll5_m2_clk = clk_get(NULL, "dpll5_m2_ck");
clk_prepare_enable(dpll5_m2_clk);
clk_set_rate(dpll5_m2_clk, OMAP3_DPLL5_FREQ_FOR_USBHOST);
clk_disable_unprepare(dpll5_m2_clk);
clk_disable_unprepare(dpll5_clk);
}
static int __init omap3xxx_dt_clk_init(int soc_type)
{
if (soc_type == OMAP3_SOC_AM35XX || soc_type == OMAP3_SOC_OMAP3630 ||
soc_type == OMAP3_SOC_OMAP3430_ES1 ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS)
ti_dt_clocks_register(omap3xxx_clks);
if (soc_type == OMAP3_SOC_AM35XX)
ti_dt_clocks_register(am35xx_clks);
if (soc_type == OMAP3_SOC_OMAP3630 || soc_type == OMAP3_SOC_AM35XX ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS)
ti_dt_clocks_register(omap36xx_am35xx_omap3430es2plus_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES1)
ti_dt_clocks_register(omap3430es1_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS ||
soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap36xx_omap3430es2plus_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES1 ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS ||
soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap34xx_omap36xx_clks);
if (soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap36xx_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/Core/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(clk_get_sys(NULL, "osc_sys_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "osc_sys_ck")) / 100000) % 10,
(clk_get_rate(clk_get_sys(NULL, "core_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "arm_fck")) / 1000000));
if (soc_type != OMAP3_SOC_OMAP3430_ES1)
omap3_clk_lock_dpll5();
return 0;
}
int __init omap3430_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_OMAP3430_ES2_PLUS);
}
int __init omap3630_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_OMAP3630);
}
int __init am35xx_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_AM35XX);
}
