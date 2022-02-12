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
regmap_write(lpass->top, SFR_LPASS_INTR_CA5_MASK,
LPASS_INTR_SFR | LPASS_INTR_DMA | LPASS_INTR_I2S);
regmap_write(lpass->top, SFR_LPASS_INTR_CPU_MASK,
LPASS_INTR_SFR | LPASS_INTR_DMA | LPASS_INTR_I2S);
regmap_write(lpass->pmu, EXYNOS5433_PAD_RETENTION_AUD_OPTION,
EXYNOS5433_PAD_INITIATE_WAKEUP_FROM_LOWPWR);
exynos_lpass_core_sw_reset(lpass, LPASS_I2S_SW_RESET);
exynos_lpass_core_sw_reset(lpass, LPASS_DMA_SW_RESET);
exynos_lpass_core_sw_reset(lpass, LPASS_MEM_SW_RESET);
}
static void exynos_lpass_disable(struct exynos_lpass *lpass)
{
regmap_write(lpass->top, SFR_LPASS_INTR_CPU_MASK, 0);
regmap_write(lpass->top, SFR_LPASS_INTR_CA5_MASK, 0);
regmap_write(lpass->pmu, EXYNOS5433_PAD_RETENTION_AUD_OPTION, 0);
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
lpass->top = regmap_init_mmio(dev, base_top,
&exynos_lpass_reg_conf);
if (IS_ERR(lpass->top)) {
dev_err(dev, "LPASS top regmap initialization failed\n");
return PTR_ERR(lpass->top);
}
lpass->pmu = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,pmu-syscon");
if (IS_ERR(lpass->pmu)) {
dev_err(dev, "Failed to lookup PMU regmap\n");
return PTR_ERR(lpass->pmu);
}
platform_set_drvdata(pdev, lpass);
exynos_lpass_enable(lpass);
return of_platform_populate(dev->of_node, NULL, NULL, dev);
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
