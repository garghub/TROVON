void imx6q_set_int_mem_clk_lpm(bool enable)
{
u32 val = readl_relaxed(ccm_base + CGPR);
val &= ~BM_CGPR_INT_MEM_CLK_LPM;
if (enable)
val |= BM_CGPR_INT_MEM_CLK_LPM;
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
val &= ~BM_CLPCR_VSTBY;
val &= ~BM_CLPCR_SBYOS;
if (cpu_is_imx6sl())
val |= BM_CLPCR_BYPASS_PMIC_READY;
if (cpu_is_imx6sl() || cpu_is_imx6sx())
val |= BM_CLPCR_BYP_MMDC_CH0_LPM_HS;
else
val |= BM_CLPCR_BYP_MMDC_CH1_LPM_HS;
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
if (cpu_is_imx6sl())
val |= BM_CLPCR_BYPASS_PMIC_READY;
if (cpu_is_imx6sl() || cpu_is_imx6sx())
val |= BM_CLPCR_BYP_MMDC_CH0_LPM_HS;
else
val |= BM_CLPCR_BYP_MMDC_CH1_LPM_HS;
break;
default:
return -EINVAL;
}
imx_gpc_hwirq_unmask(32);
writel_relaxed(val, ccm_base + CLPCR);
imx_gpc_hwirq_mask(32);
return 0;
}
static int imx6q_suspend_finish(unsigned long val)
{
if (!imx6_suspend_in_ocram_fn) {
cpu_do_idle();
} else {
local_flush_tlb_all();
imx6_suspend_in_ocram_fn(suspend_ocram_base);
}
return 0;
}
static int imx6q_pm_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_STANDBY:
imx6q_set_lpm(STOP_POWER_ON);
imx6q_set_int_mem_clk_lpm(true);
imx_gpc_pre_suspend(false);
if (cpu_is_imx6sl())
imx6sl_set_wait_clk(true);
cpu_do_idle();
if (cpu_is_imx6sl())
imx6sl_set_wait_clk(false);
imx_gpc_post_resume();
imx6q_set_lpm(WAIT_CLOCKED);
break;
case PM_SUSPEND_MEM:
imx6q_set_lpm(STOP_POWER_OFF);
imx6q_set_int_mem_clk_lpm(false);
imx6q_enable_wb(true);
if (!imx6_suspend_in_ocram_fn)
imx6q_enable_rbc(true);
imx_gpc_pre_suspend(true);
imx_anatop_pre_suspend();
imx_set_cpu_jump(0, v7_cpu_resume);
cpu_suspend(0, imx6q_suspend_finish);
if (cpu_is_imx6q() || cpu_is_imx6dl())
imx_smp_prepare();
imx_anatop_post_resume();
imx_gpc_post_resume();
imx6q_enable_rbc(false);
imx6q_enable_wb(false);
imx6q_set_int_mem_clk_lpm(true);
imx6q_set_lpm(WAIT_CLOCKED);
break;
default:
return -EINVAL;
}
return 0;
}
static int imx6q_pm_valid(suspend_state_t state)
{
return (state == PM_SUSPEND_STANDBY || state == PM_SUSPEND_MEM);
}
void __init imx6q_pm_set_ccm_base(void __iomem *base)
{
ccm_base = base;
}
static int __init imx6_pm_get_base(struct imx6_pm_base *base,
const char *compat)
{
struct device_node *node;
struct resource res;
int ret = 0;
node = of_find_compatible_node(NULL, NULL, compat);
if (!node) {
ret = -ENODEV;
goto out;
}
ret = of_address_to_resource(node, 0, &res);
if (ret)
goto put_node;
base->pbase = res.start;
base->vbase = ioremap(res.start, resource_size(&res));
if (!base->vbase)
ret = -ENOMEM;
put_node:
of_node_put(node);
out:
return ret;
}
static int __init imx6q_suspend_init(const struct imx6_pm_socdata *socdata)
{
phys_addr_t ocram_pbase;
struct device_node *node;
struct platform_device *pdev;
struct imx6_cpu_pm_info *pm_info;
struct gen_pool *ocram_pool;
unsigned long ocram_base;
int i, ret = 0;
const u32 *mmdc_offset_array;
suspend_set_ops(&imx6q_pm_ops);
if (!socdata) {
pr_warn("%s: invalid argument!\n", __func__);
return -EINVAL;
}
node = of_find_compatible_node(NULL, NULL, "mmio-sram");
if (!node) {
pr_warn("%s: failed to find ocram node!\n", __func__);
return -ENODEV;
}
pdev = of_find_device_by_node(node);
if (!pdev) {
pr_warn("%s: failed to find ocram device!\n", __func__);
ret = -ENODEV;
goto put_node;
}
ocram_pool = dev_get_gen_pool(&pdev->dev);
if (!ocram_pool) {
pr_warn("%s: ocram pool unavailable!\n", __func__);
ret = -ENODEV;
goto put_node;
}
ocram_base = gen_pool_alloc(ocram_pool, MX6Q_SUSPEND_OCRAM_SIZE);
if (!ocram_base) {
pr_warn("%s: unable to alloc ocram!\n", __func__);
ret = -ENOMEM;
goto put_node;
}
ocram_pbase = gen_pool_virt_to_phys(ocram_pool, ocram_base);
suspend_ocram_base = __arm_ioremap_exec(ocram_pbase,
MX6Q_SUSPEND_OCRAM_SIZE, false);
pm_info = suspend_ocram_base;
pm_info->pbase = ocram_pbase;
pm_info->resume_addr = virt_to_phys(v7_cpu_resume);
pm_info->pm_info_size = sizeof(*pm_info);
pm_info->ccm_base.vbase = ccm_base;
ret = imx6_pm_get_base(&pm_info->mmdc_base, socdata->mmdc_compat);
if (ret) {
pr_warn("%s: failed to get mmdc base %d!\n", __func__, ret);
goto put_node;
}
ret = imx6_pm_get_base(&pm_info->src_base, socdata->src_compat);
if (ret) {
pr_warn("%s: failed to get src base %d!\n", __func__, ret);
goto src_map_failed;
}
ret = imx6_pm_get_base(&pm_info->iomuxc_base, socdata->iomuxc_compat);
if (ret) {
pr_warn("%s: failed to get iomuxc base %d!\n", __func__, ret);
goto iomuxc_map_failed;
}
ret = imx6_pm_get_base(&pm_info->gpc_base, socdata->gpc_compat);
if (ret) {
pr_warn("%s: failed to get gpc base %d!\n", __func__, ret);
goto gpc_map_failed;
}
ret = imx6_pm_get_base(&pm_info->l2_base, "arm,pl310-cache");
if (ret) {
pr_warn("%s: failed to get pl310-cache base %d!\n",
__func__, ret);
goto pl310_cache_map_failed;
}
pm_info->ddr_type = imx_mmdc_get_ddr_type();
pm_info->mmdc_io_num = socdata->mmdc_io_num;
mmdc_offset_array = socdata->mmdc_io_offset;
for (i = 0; i < pm_info->mmdc_io_num; i++) {
pm_info->mmdc_io_val[i][0] =
mmdc_offset_array[i];
pm_info->mmdc_io_val[i][1] =
readl_relaxed(pm_info->iomuxc_base.vbase +
mmdc_offset_array[i]);
}
imx6_suspend_in_ocram_fn = fncpy(
suspend_ocram_base + sizeof(*pm_info),
&imx6_suspend,
MX6Q_SUSPEND_OCRAM_SIZE - sizeof(*pm_info));
goto put_node;
pl310_cache_map_failed:
iounmap(&pm_info->gpc_base.vbase);
gpc_map_failed:
iounmap(&pm_info->iomuxc_base.vbase);
iomuxc_map_failed:
iounmap(&pm_info->src_base.vbase);
src_map_failed:
iounmap(&pm_info->mmdc_base.vbase);
put_node:
of_node_put(node);
return ret;
}
static void __init imx6_pm_common_init(const struct imx6_pm_socdata
*socdata)
{
struct regmap *gpr;
int ret;
WARN_ON(!ccm_base);
if (IS_ENABLED(CONFIG_SUSPEND)) {
ret = imx6q_suspend_init(socdata);
if (ret)
pr_warn("%s: No DDR LPM support with suspend %d!\n",
__func__, ret);
}
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, IOMUXC_GPR1, IMX6Q_GPR1_GINT,
IMX6Q_GPR1_GINT);
}
void __init imx6q_pm_init(void)
{
imx6_pm_common_init(&imx6q_pm_data);
}
void __init imx6dl_pm_init(void)
{
imx6_pm_common_init(&imx6dl_pm_data);
}
void __init imx6sl_pm_init(void)
{
imx6_pm_common_init(&imx6sl_pm_data);
}
void __init imx6sx_pm_init(void)
{
imx6_pm_common_init(&imx6sx_pm_data);
}
