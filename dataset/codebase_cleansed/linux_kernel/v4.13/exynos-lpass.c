static void exynos_lpass_core_sw_reset(struct exynos_lpass *lpass, int mask)
{
unsigned int val = 0;
regmap_read(lpass->top, SFR_LPASS_CORE_SW_RESET, &val);
val &= ~mask;
regmap_write(lpass->top, SFR_LPASS_CORE_SW_RESET, val);
usleep_range(100, 150);
val |= mask;
regmap_write(lpass->top, SFR_LPASS_CORE_SW_RESET, val);
}
static void exynos_lpass_enable(struct exynos_lpass *lpass)
{
clk_prepare_enable(lpass->sfr0_clk);
regmap_write(lpass->top, SFR_LPASS_INTR_CA5_MASK,
LPASS_INTR_SFR | LPASS_INTR_DMA | LPASS_INTR_I2S);
regmap_write(lpass->top, SFR_LPASS_INTR_CPU_MASK,
LPASS_INTR_SFR | LPASS_INTR_DMA | LPASS_INTR_I2S);
exynos_lpass_core_sw_reset(lpass, LPASS_I2S_SW_RESET);
exynos_lpass_core_sw_reset(lpass, LPASS_DMA_SW_RESET);
exynos_lpass_core_sw_reset(lpass, LPASS_MEM_SW_RESET);
}
static void exynos_lpass_disable(struct exynos_lpass *lpass)
{
regmap_write(lpass->top, SFR_LPASS_INTR_CPU_MASK, 0);
regmap_write(lpass->top, SFR_LPASS_INTR_CA5_MASK, 0);
clk_disable_unprepare(lpass->sfr0_clk);
}
static int exynos_lpass_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct exynos_lpass *lpass;
void __iomem *base_top;
struct resource *res;
lpass = devm_kzalloc(dev, sizeof(*lpass), GFP_KERNEL);
if (!lpass)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base_top = devm_ioremap_resource(dev, res);
if (IS_ERR(base_top))
return PTR_ERR(base_top);
lpass->sfr0_clk = devm_clk_get(dev, "sfr0_ctrl");
if (IS_ERR(lpass->sfr0_clk))
return PTR_ERR(lpass->sfr0_clk);
lpass->top = regmap_init_mmio(dev, base_top,
&exynos_lpass_reg_conf);
if (IS_ERR(lpass->top)) {
dev_err(dev, "LPASS top regmap initialization failed\n");
return PTR_ERR(lpass->top);
}
platform_set_drvdata(pdev, lpass);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
exynos_lpass_enable(lpass);
return devm_of_platform_populate(dev);
}
static int exynos_lpass_remove(struct platform_device *pdev)
{
struct exynos_lpass *lpass = platform_get_drvdata(pdev);
exynos_lpass_disable(lpass);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
exynos_lpass_disable(lpass);
regmap_exit(lpass->top);
return 0;
}
static int __maybe_unused exynos_lpass_suspend(struct device *dev)
{
struct exynos_lpass *lpass = dev_get_drvdata(dev);
exynos_lpass_disable(lpass);
return 0;
}
static int __maybe_unused exynos_lpass_resume(struct device *dev)
{
struct exynos_lpass *lpass = dev_get_drvdata(dev);
exynos_lpass_enable(lpass);
return 0;
}
