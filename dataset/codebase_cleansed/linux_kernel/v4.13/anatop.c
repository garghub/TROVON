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
static inline void imx_anatop_enable_2p5_pulldown(bool enable)
{
regmap_write(anatop, ANADIG_REG_2P5 + (enable ? REG_SET : REG_CLR),
BM_ANADIG_REG_2P5_ENABLE_PULLDOWN);
}
static inline void imx_anatop_disconnect_high_snvs(bool enable)
{
regmap_write(anatop, ANADIG_ANA_MISC0 + (enable ? REG_SET : REG_CLR),
BM_ANADIG_ANA_MISC0_DISCON_HIGH_SNVS);
}
void imx_anatop_pre_suspend(void)
{
if (imx_mmdc_get_ddr_type() == IMX_DDR_TYPE_LPDDR2)
imx_anatop_enable_2p5_pulldown(true);
else
imx_anatop_enable_weak2p5(true);
imx_anatop_enable_fet_odrive(true);
if (cpu_is_imx6sl())
imx_anatop_disconnect_high_snvs(true);
}
void imx_anatop_post_resume(void)
{
if (imx_mmdc_get_ddr_type() == IMX_DDR_TYPE_LPDDR2)
imx_anatop_enable_2p5_pulldown(false);
else
imx_anatop_enable_weak2p5(false);
imx_anatop_enable_fet_odrive(false);
if (cpu_is_imx6sl())
imx_anatop_disconnect_high_snvs(false);
}
static void imx_anatop_usb_chrg_detect_disable(void)
{
regmap_write(anatop, ANADIG_USB1_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B
| BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
regmap_write(anatop, ANADIG_USB2_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B |
BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
}
void __init imx_init_revision_from_anatop(void)
{
struct device_node *np;
void __iomem *anatop_base;
unsigned int revision;
u32 digprog;
u16 offset = ANADIG_DIGPROG;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-anatop");
anatop_base = of_iomap(np, 0);
WARN_ON(!anatop_base);
if (of_device_is_compatible(np, "fsl,imx6sl-anatop"))
offset = ANADIG_DIGPROG_IMX6SL;
if (of_device_is_compatible(np, "fsl,imx7d-anatop"))
offset = ANADIG_DIGPROG_IMX7D;
digprog = readl_relaxed(anatop_base + offset);
iounmap(anatop_base);
switch (digprog & 0xff) {
case 0:
if (digprog >> 8 & 0x01)
revision = IMX_CHIP_REVISION_2_0;
else
revision = IMX_CHIP_REVISION_1_0;
break;
case 1:
revision = IMX_CHIP_REVISION_1_1;
break;
case 2:
revision = IMX_CHIP_REVISION_1_2;
break;
case 3:
revision = IMX_CHIP_REVISION_1_3;
break;
case 4:
revision = IMX_CHIP_REVISION_1_4;
break;
case 5:
revision = IMX_CHIP_REVISION_1_5;
break;
default:
revision = digprog & 0xff;
}
mxc_set_cpu_type(digprog >> 16 & 0xff);
imx_set_soc_revision(revision);
}
void __init imx_anatop_init(void)
{
anatop = syscon_regmap_lookup_by_compatible("fsl,imx6q-anatop");
if (IS_ERR(anatop)) {
pr_err("%s: failed to find imx6q-anatop regmap!\n", __func__);
return;
}
imx_anatop_usb_chrg_detect_disable();
}
