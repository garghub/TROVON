void pmu_raw_writel(u32 val, u32 offset)
{
writel_relaxed(val, pmu_base_addr + offset);
}
u32 pmu_raw_readl(u32 offset)
{
return readl_relaxed(pmu_base_addr + offset);
}
void exynos_sys_powerdown_conf(enum sys_powerdown mode)
{
unsigned int i;
const struct exynos_pmu_data *pmu_data;
if (!pmu_context || !pmu_context->pmu_data)
return;
pmu_data = pmu_context->pmu_data;
if (pmu_data->powerdown_conf)
pmu_data->powerdown_conf(mode);
if (pmu_data->pmu_config) {
for (i = 0; (pmu_data->pmu_config[i].offset != PMU_TABLE_END); i++)
pmu_raw_writel(pmu_data->pmu_config[i].val[mode],
pmu_data->pmu_config[i].offset);
}
if (pmu_data->powerdown_conf_extra)
pmu_data->powerdown_conf_extra(mode);
if (pmu_data->pmu_config_extra) {
for (i = 0; pmu_data->pmu_config_extra[i].offset != PMU_TABLE_END; i++)
pmu_raw_writel(pmu_data->pmu_config_extra[i].val[mode],
pmu_data->pmu_config_extra[i].offset);
}
}
struct regmap *exynos_get_pmu_regmap(void)
{
struct device_node *np = of_find_matching_node(NULL,
exynos_pmu_of_device_ids);
if (np)
return syscon_node_to_regmap(np);
return ERR_PTR(-ENODEV);
}
static int exynos_pmu_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pmu_base_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(pmu_base_addr))
return PTR_ERR(pmu_base_addr);
pmu_context = devm_kzalloc(&pdev->dev,
sizeof(struct exynos_pmu_context),
GFP_KERNEL);
if (!pmu_context)
return -ENOMEM;
pmu_context->dev = dev;
pmu_context->pmu_data = of_device_get_match_data(dev);
if (pmu_context->pmu_data && pmu_context->pmu_data->pmu_init)
pmu_context->pmu_data->pmu_init();
platform_set_drvdata(pdev, pmu_context);
dev_dbg(dev, "Exynos PMU Driver probe done\n");
return 0;
}
static int __init exynos_pmu_init(void)
{
return platform_driver_register(&exynos_pmu_driver);
}
