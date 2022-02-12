static void mx5_cpu_lp_set(enum mxc_cpu_pwr_mode mode)
{
u32 plat_lpc, arm_srpgcr, ccm_clpcr;
u32 empgc0, empgc1;
int stop_mode = 0;
plat_lpc = __raw_readl(cortex_base + MXC_CORTEXA8_PLAT_LPC) &
~(MXC_CORTEXA8_PLAT_LPC_DSM);
ccm_clpcr = __raw_readl(ccm_base + MXC_CCM_CLPCR) &
~(MXC_CCM_CLPCR_LPM_MASK);
arm_srpgcr = __raw_readl(gpc_base + MXC_SRPG_ARM_SRPGCR) &
~(MXC_SRPGCR_PCR);
empgc0 = __raw_readl(gpc_base + MXC_SRPG_EMPGC0_SRPGCR) &
~(MXC_SRPGCR_PCR);
empgc1 = __raw_readl(gpc_base + MXC_SRPG_EMPGC1_SRPGCR) &
~(MXC_SRPGCR_PCR);
switch (mode) {
case WAIT_CLOCKED:
break;
case WAIT_UNCLOCKED:
ccm_clpcr |= 0x1 << MXC_CCM_CLPCR_LPM_OFFSET;
break;
case WAIT_UNCLOCKED_POWER_OFF:
case STOP_POWER_OFF:
plat_lpc |= MXC_CORTEXA8_PLAT_LPC_DSM
| MXC_CORTEXA8_PLAT_LPC_DBG_DSM;
if (mode == WAIT_UNCLOCKED_POWER_OFF) {
ccm_clpcr |= 0x1 << MXC_CCM_CLPCR_LPM_OFFSET;
ccm_clpcr &= ~MXC_CCM_CLPCR_VSTBY;
ccm_clpcr &= ~MXC_CCM_CLPCR_SBYOS;
stop_mode = 0;
} else {
ccm_clpcr |= 0x2 << MXC_CCM_CLPCR_LPM_OFFSET;
ccm_clpcr |= 0x3 << MXC_CCM_CLPCR_STBY_COUNT_OFFSET;
ccm_clpcr |= MXC_CCM_CLPCR_VSTBY;
ccm_clpcr |= MXC_CCM_CLPCR_SBYOS;
stop_mode = 1;
}
arm_srpgcr |= MXC_SRPGCR_PCR;
break;
case STOP_POWER_ON:
ccm_clpcr |= 0x2 << MXC_CCM_CLPCR_LPM_OFFSET;
break;
default:
printk(KERN_WARNING "UNKNOWN cpu power mode: %d\n", mode);
return;
}
__raw_writel(plat_lpc, cortex_base + MXC_CORTEXA8_PLAT_LPC);
__raw_writel(ccm_clpcr, ccm_base + MXC_CCM_CLPCR);
__raw_writel(arm_srpgcr, gpc_base + MXC_SRPG_ARM_SRPGCR);
__raw_writel(arm_srpgcr, gpc_base + MXC_SRPG_NEON_SRPGCR);
if (stop_mode) {
empgc0 |= MXC_SRPGCR_PCR;
empgc1 |= MXC_SRPGCR_PCR;
__raw_writel(empgc0, gpc_base + MXC_SRPG_EMPGC0_SRPGCR);
__raw_writel(empgc1, gpc_base + MXC_SRPG_EMPGC1_SRPGCR);
}
}
static int mx5_suspend_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_MEM:
mx5_cpu_lp_set(STOP_POWER_OFF);
break;
case PM_SUSPEND_STANDBY:
break;
default:
return -EINVAL;
}
if (state == PM_SUSPEND_MEM) {
local_flush_tlb_all();
flush_cache_all();
__raw_writel(0, gpc_base + MXC_SRPG_EMPGC0_SRPGCR);
__raw_writel(0, gpc_base + MXC_SRPG_EMPGC1_SRPGCR);
if (imx5_suspend_in_ocram_fn)
imx5_suspend_in_ocram_fn(suspend_ocram_base);
else
cpu_do_idle();
} else {
cpu_do_idle();
}
mx5_cpu_lp_set(IMX5_DEFAULT_CPU_IDLE_STATE);
return 0;
}
static int mx5_pm_valid(suspend_state_t state)
{
return (state > PM_SUSPEND_ON && state <= PM_SUSPEND_MAX);
}
static inline int imx5_cpu_do_idle(void)
{
int ret = tzic_enable_wake();
if (likely(!ret))
cpu_do_idle();
return ret;
}
static void imx5_pm_idle(void)
{
imx5_cpu_do_idle();
}
static int __init imx_suspend_alloc_ocram(
size_t size,
void __iomem **virt_out,
phys_addr_t *phys_out)
{
struct device_node *node;
struct platform_device *pdev;
struct gen_pool *ocram_pool;
unsigned long ocram_base;
void __iomem *virt;
phys_addr_t phys;
int ret = 0;
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
ocram_pool = gen_pool_get(&pdev->dev, NULL);
if (!ocram_pool) {
pr_warn("%s: ocram pool unavailable!\n", __func__);
ret = -ENODEV;
goto put_node;
}
ocram_base = gen_pool_alloc(ocram_pool, size);
if (!ocram_base) {
pr_warn("%s: unable to alloc ocram!\n", __func__);
ret = -ENOMEM;
goto put_node;
}
phys = gen_pool_virt_to_phys(ocram_pool, ocram_base);
virt = __arm_ioremap_exec(phys, size, false);
if (phys_out)
*phys_out = phys;
if (virt_out)
*virt_out = virt;
put_node:
of_node_put(node);
return ret;
}
static int __init imx5_suspend_init(const struct imx5_pm_data *soc_data)
{
struct imx5_cpu_suspend_info *suspend_info;
int ret;
void (*suspend_asm)(void __iomem *) = soc_data->suspend_asm;
if (!suspend_asm)
return 0;
if (!soc_data->suspend_asm_sz || !*soc_data->suspend_asm_sz)
return -EINVAL;
ret = imx_suspend_alloc_ocram(
*soc_data->suspend_asm_sz + sizeof(*suspend_info),
&suspend_ocram_base, NULL);
if (ret)
return ret;
suspend_info = suspend_ocram_base;
suspend_info->io_count = soc_data->suspend_io_count;
memcpy(suspend_info->io_state, soc_data->suspend_io_config,
sizeof(*suspend_info->io_state) * soc_data->suspend_io_count);
suspend_info->m4if_base = ioremap(soc_data->m4if_addr, SZ_16K);
if (!suspend_info->m4if_base) {
ret = -ENOMEM;
goto failed_map_m4if;
}
suspend_info->iomuxc_base = ioremap(soc_data->iomuxc_addr, SZ_16K);
if (!suspend_info->iomuxc_base) {
ret = -ENOMEM;
goto failed_map_iomuxc;
}
imx5_suspend_in_ocram_fn = fncpy(
suspend_ocram_base + sizeof(*suspend_info),
suspend_asm,
*soc_data->suspend_asm_sz);
return 0;
failed_map_iomuxc:
iounmap(suspend_info->m4if_base);
failed_map_m4if:
return ret;
}
static int __init imx5_pm_common_init(const struct imx5_pm_data *data)
{
int ret;
struct clk *gpc_dvfs_clk = clk_get(NULL, "gpc_dvfs");
if (IS_ERR(gpc_dvfs_clk))
return PTR_ERR(gpc_dvfs_clk);
ret = clk_prepare_enable(gpc_dvfs_clk);
if (ret)
return ret;
arm_pm_idle = imx5_pm_idle;
ccm_base = ioremap(data->ccm_addr, SZ_16K);
cortex_base = ioremap(data->cortex_addr, SZ_16K);
gpc_base = ioremap(data->gpc_addr, SZ_16K);
WARN_ON(!ccm_base || !cortex_base || !gpc_base);
mx5_cpu_lp_set(IMX5_DEFAULT_CPU_IDLE_STATE);
ret = imx5_cpuidle_init();
if (ret)
pr_warn("%s: cpuidle init failed %d\n", __func__, ret);
ret = imx5_suspend_init(data);
if (ret)
pr_warn("%s: No DDR LPM support with suspend %d!\n",
__func__, ret);
suspend_set_ops(&mx5_suspend_ops);
return 0;
}
void __init imx51_pm_init(void)
{
if (IS_ENABLED(CONFIG_SOC_IMX51))
imx5_pm_common_init(&imx51_pm_data);
}
void __init imx53_pm_init(void)
{
if (IS_ENABLED(CONFIG_SOC_IMX53))
imx5_pm_common_init(&imx53_pm_data);
}
