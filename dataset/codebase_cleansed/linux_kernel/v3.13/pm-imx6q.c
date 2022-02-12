void imx6q_set_chicken_bit(void)
{
u32 val = readl_relaxed(ccm_base + CGPR);
val |= BM_CGPR_CHICKEN_BIT;
writel_relaxed(val, ccm_base + CGPR);
}
static void imx6q_enable_rbc(bool enable)
{
u32 val;
imx_gpc_mask_all();
val = readl_relaxed(ccm_base + CCR);
val &= ~BM_CCR_RBC_EN;
val |= enable ? BM_CCR_RBC_EN : 0;
writel_relaxed(val, ccm_base + CCR);
val = readl_relaxed(ccm_base + CCR);
val &= ~BM_CCR_RBC_BYPASS_COUNT;
val |= enable ? BM_CCR_RBC_BYPASS_COUNT : 0;
writel(val, ccm_base + CCR);
udelay(65);
imx_gpc_restore_all();
}
static void imx6q_enable_wb(bool enable)
{
u32 val;
val = readl_relaxed(ccm_base + CLPCR);
val &= ~BM_CLPCR_WB_PER_AT_LPM;
val |= enable ? BM_CLPCR_WB_PER_AT_LPM : 0;
writel_relaxed(val, ccm_base + CLPCR);
val = readl_relaxed(ccm_base + CCR);
val &= ~BM_CCR_WB_COUNT;
val |= enable ? BM_CCR_WB_COUNT : 0;
writel_relaxed(val, ccm_base + CCR);
}
int imx6q_set_lpm(enum mxc_cpu_pwr_mode mode)
{
struct irq_desc *iomuxc_irq_desc;
u32 val = readl_relaxed(ccm_base + CLPCR);
val &= ~BM_CLPCR_LPM;
switch (mode) {
case WAIT_CLOCKED:
break;
case WAIT_UNCLOCKED:
val |= 0x1 << BP_CLPCR_LPM;
val |= BM_CLPCR_ARM_CLK_DIS_ON_LPM;
break;
case STOP_POWER_ON:
val |= 0x2 << BP_CLPCR_LPM;
break;
case WAIT_UNCLOCKED_POWER_OFF:
val |= 0x1 << BP_CLPCR_LPM;
val &= ~BM_CLPCR_VSTBY;
val &= ~BM_CLPCR_SBYOS;
break;
case STOP_POWER_OFF:
val |= 0x2 << BP_CLPCR_LPM;
val |= 0x3 << BP_CLPCR_STBY_COUNT;
val |= BM_CLPCR_VSTBY;
val |= BM_CLPCR_SBYOS;
if (cpu_is_imx6sl()) {
val |= BM_CLPCR_BYPASS_PMIC_READY;
val |= BM_CLPCR_BYP_MMDC_CH0_LPM_HS;
} else {
val |= BM_CLPCR_BYP_MMDC_CH1_LPM_HS;
}
break;
default:
return -EINVAL;
}
iomuxc_irq_desc = irq_to_desc(32);
imx_gpc_irq_unmask(&iomuxc_irq_desc->irq_data);
writel_relaxed(val, ccm_base + CLPCR);
imx_gpc_irq_mask(&iomuxc_irq_desc->irq_data);
return 0;
}
static int imx6q_suspend_finish(unsigned long val)
{
cpu_do_idle();
return 0;
}
static int imx6q_pm_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_MEM:
imx6q_set_lpm(STOP_POWER_OFF);
imx6q_enable_wb(true);
imx6q_enable_rbc(true);
imx_gpc_pre_suspend();
imx_anatop_pre_suspend();
imx_set_cpu_jump(0, v7_cpu_resume);
cpu_suspend(0, imx6q_suspend_finish);
if (cpu_is_imx6q() || cpu_is_imx6dl())
imx_smp_prepare();
imx_anatop_post_resume();
imx_gpc_post_resume();
imx6q_enable_rbc(false);
imx6q_enable_wb(false);
imx6q_set_lpm(WAIT_CLOCKED);
break;
default:
return -EINVAL;
}
return 0;
}
void __init imx6q_pm_set_ccm_base(void __iomem *base)
{
ccm_base = base;
}
void __init imx6q_pm_init(void)
{
struct regmap *gpr;
WARN_ON(!ccm_base);
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, IOMUXC_GPR1, IMX6Q_GPR1_GINT,
IMX6Q_GPR1_GINT);
imx6q_set_lpm(WAIT_CLOCKED);
suspend_set_ops(&imx6q_pm_ops);
}
