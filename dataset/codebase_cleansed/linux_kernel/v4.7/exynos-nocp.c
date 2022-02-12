static int exynos_nocp_set_event(struct devfreq_event_dev *edev)
{
struct exynos_nocp *nocp = devfreq_event_get_drvdata(edev);
int ret;
ret = regmap_update_bits(nocp->regmap, NOCP_MAIN_CTL,
NOCP_MAIN_CTL_STATEN_MASK, 0);
if (ret < 0) {
dev_err(nocp->dev, "failed to disable the NoC probe device\n");
return ret;
}
ret = regmap_write(nocp->regmap, NOCP_STAT_PERIOD, 0x0);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_0_SRC,
NOCP_CNT_SRC_INTEVENT_MASK,
NOCP_CNT_SRC_INTEVENT_BYTE_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_1_SRC,
NOCP_CNT_SRC_INTEVENT_MASK,
NOCP_CNT_SRC_INTEVENT_CHAIN_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_2_SRC,
NOCP_CNT_SRC_INTEVENT_MASK,
NOCP_CNT_SRC_INTEVENT_CYCLE_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_3_SRC,
NOCP_CNT_SRC_INTEVENT_MASK,
NOCP_CNT_SRC_INTEVENT_CHAIN_MASK);
if (ret < 0)
goto out;
ret = regmap_write(nocp->regmap, NOCP_STAT_ALARM_MIN, 0x0);
if (ret < 0)
goto out;
ret = regmap_write(nocp->regmap, NOCP_STAT_ALARM_MAX, 0x0);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_0_ALARM_MODE,
NOCP_CNT_ALARM_MODE_MASK,
NOCP_CNT_ALARM_MODE_MIN_MAX_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_1_ALARM_MODE,
NOCP_CNT_ALARM_MODE_MASK,
NOCP_CNT_ALARM_MODE_MIN_MAX_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_2_ALARM_MODE,
NOCP_CNT_ALARM_MODE_MASK,
NOCP_CNT_ALARM_MODE_MIN_MAX_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_COUNTERS_3_ALARM_MODE,
NOCP_CNT_ALARM_MODE_MASK,
NOCP_CNT_ALARM_MODE_MIN_MAX_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_MAIN_CTL,
NOCP_MAIN_CTL_STATEN_MASK | NOCP_MAIN_CTL_ALARMEN_MASK,
NOCP_MAIN_CTL_STATEN_MASK | NOCP_MAIN_CTL_ALARMEN_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_CFG_CTL,
NOCP_CFG_CTL_GLOBALEN_MASK,
NOCP_CFG_CTL_GLOBALEN_MASK);
if (ret < 0)
goto out;
ret = regmap_update_bits(nocp->regmap, NOCP_MAIN_CTL,
NOCP_MAIN_CTL_STATEN_MASK,
NOCP_MAIN_CTL_STATEN_MASK);
if (ret < 0)
goto out;
return 0;
out:
if (regmap_update_bits(nocp->regmap, NOCP_MAIN_CTL,
NOCP_MAIN_CTL_STATEN_MASK, 0)) {
dev_err(nocp->dev, "Failed to reset NoC probe device\n");
}
return ret;
}
static int exynos_nocp_get_event(struct devfreq_event_dev *edev,
struct devfreq_event_data *edata)
{
struct exynos_nocp *nocp = devfreq_event_get_drvdata(edev);
unsigned int counter[4];
int ret;
ret = regmap_read(nocp->regmap, NOCP_COUNTERS_0_VAL, &counter[0]);
if (ret < 0)
goto out;
ret = regmap_read(nocp->regmap, NOCP_COUNTERS_1_VAL, &counter[1]);
if (ret < 0)
goto out;
ret = regmap_read(nocp->regmap, NOCP_COUNTERS_2_VAL, &counter[2]);
if (ret < 0)
goto out;
ret = regmap_read(nocp->regmap, NOCP_COUNTERS_3_VAL, &counter[3]);
if (ret < 0)
goto out;
edata->load_count = ((counter[1] << 16) | counter[0]);
edata->total_count = ((counter[3] << 16) | counter[2]);
dev_dbg(&edev->dev, "%s (event: %ld/%ld)\n", edev->desc->name,
edata->load_count, edata->total_count);
return 0;
out:
edata->load_count = 0;
edata->total_count = 0;
dev_err(nocp->dev, "Failed to read the counter of NoC probe device\n");
return ret;
}
static int exynos_nocp_parse_dt(struct platform_device *pdev,
struct exynos_nocp *nocp)
{
struct device *dev = nocp->dev;
struct device_node *np = dev->of_node;
struct resource *res;
void __iomem *base;
if (!np) {
dev_err(dev, "failed to find devicetree node\n");
return -EINVAL;
}
nocp->clk = devm_clk_get(dev, "nocp");
if (IS_ERR(nocp->clk))
nocp->clk = NULL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
exynos_nocp_regmap_config.max_register = resource_size(res) - 4;
nocp->regmap = devm_regmap_init_mmio(dev, base,
&exynos_nocp_regmap_config);
if (IS_ERR(nocp->regmap)) {
dev_err(dev, "failed to initialize regmap\n");
return PTR_ERR(nocp->regmap);
}
return 0;
}
static int exynos_nocp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct exynos_nocp *nocp;
int ret;
nocp = devm_kzalloc(&pdev->dev, sizeof(*nocp), GFP_KERNEL);
if (!nocp)
return -ENOMEM;
nocp->dev = &pdev->dev;
ret = exynos_nocp_parse_dt(pdev, nocp);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to parse devicetree for resource\n");
return ret;
}
nocp->desc.ops = &exynos_nocp_ops;
nocp->desc.driver_data = nocp;
nocp->desc.name = np->full_name;
nocp->edev = devm_devfreq_event_add_edev(&pdev->dev, &nocp->desc);
if (IS_ERR(nocp->edev)) {
dev_err(&pdev->dev,
"failed to add devfreq-event device\n");
return PTR_ERR(nocp->edev);
}
platform_set_drvdata(pdev, nocp);
clk_prepare_enable(nocp->clk);
pr_info("exynos-nocp: new NoC Probe device registered: %s\n",
dev_name(dev));
return 0;
}
static int exynos_nocp_remove(struct platform_device *pdev)
{
struct exynos_nocp *nocp = platform_get_drvdata(pdev);
clk_disable_unprepare(nocp->clk);
return 0;
}
