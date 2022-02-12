static void imx_anatop_enable_weak2p5(bool enable)
{
u32 reg, val;
regmap_read(anatop, ANADIG_ANA_MISC0, &val);
reg = ANADIG_REG_2P5;
reg += (enable && (val & BM_ANADIG_ANA_MISC0_STOP_MODE_CONFIG) == 0) ?
REG_SET : REG_CLR;
regmap_write(anatop, reg, BM_ANADIG_REG_2P5_ENABLE_WEAK_LINREG);
}
static void imx_anatop_enable_fet_odrive(bool enable)
{
regmap_write(anatop, ANADIG_REG_CORE + (enable ? REG_SET : REG_CLR),
BM_ANADIG_REG_CORE_FET_ODRIVE);
}
void imx_anatop_pre_suspend(void)
{
imx_anatop_enable_weak2p5(true);
imx_anatop_enable_fet_odrive(true);
}
void imx_anatop_post_resume(void)
{
imx_anatop_enable_fet_odrive(false);
imx_anatop_enable_weak2p5(false);
}
void imx_anatop_usb_chrg_detect_disable(void)
{
regmap_write(anatop, ANADIG_USB1_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B
| BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
regmap_write(anatop, ANADIG_USB2_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B |
BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
}
u32 imx_anatop_get_digprog(void)
{
struct device_node *np;
void __iomem *anatop_base;
static u32 digprog;
if (digprog)
return digprog;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-anatop");
anatop_base = of_iomap(np, 0);
WARN_ON(!anatop_base);
digprog = readl_relaxed(anatop_base + ANADIG_DIGPROG);
return digprog;
}
void __init imx_anatop_init(void)
{
anatop = syscon_regmap_lookup_by_compatible("fsl,imx6q-anatop");
if (IS_ERR(anatop)) {
pr_err("%s: failed to find imx6q-anatop regmap!\n", __func__);
return;
}
}
