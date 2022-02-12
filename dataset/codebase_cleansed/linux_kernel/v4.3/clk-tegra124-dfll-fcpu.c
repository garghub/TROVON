static int tegra124_dfll_fcpu_probe(struct platform_device *pdev)
{
int process_id, speedo_id, speedo_value;
struct tegra_dfll_soc_data *soc;
const struct cvb_table *cvb;
process_id = tegra_sku_info.cpu_process_id;
speedo_id = tegra_sku_info.cpu_speedo_id;
speedo_value = tegra_sku_info.cpu_speedo_value;
if (speedo_id >= ARRAY_SIZE(cpu_max_freq_table)) {
dev_err(&pdev->dev, "unknown max CPU freq for speedo_id=%d\n",
speedo_id);
return -ENODEV;
}
soc = devm_kzalloc(&pdev->dev, sizeof(*soc), GFP_KERNEL);
if (!soc)
return -ENOMEM;
soc->dev = get_cpu_device(0);
if (!soc->dev) {
dev_err(&pdev->dev, "no CPU0 device\n");
return -ENODEV;
}
cvb = tegra_cvb_build_opp_table(tegra124_cpu_cvb_tables,
ARRAY_SIZE(tegra124_cpu_cvb_tables),
process_id, speedo_id, speedo_value,
cpu_max_freq_table[speedo_id],
soc->dev);
if (IS_ERR(cvb)) {
dev_err(&pdev->dev, "couldn't build OPP table: %ld\n",
PTR_ERR(cvb));
return PTR_ERR(cvb);
}
soc->min_millivolts = cvb->min_millivolts;
soc->tune0_low = cvb->cpu_dfll_data.tune0_low;
soc->tune0_high = cvb->cpu_dfll_data.tune0_high;
soc->tune1 = cvb->cpu_dfll_data.tune1;
return tegra_dfll_register(pdev, soc);
}
static int __init tegra124_dfll_fcpu_init(void)
{
return platform_driver_register(&tegra124_dfll_fcpu_driver);
}
static void __exit tegra124_dfll_fcpu_exit(void)
{
platform_driver_unregister(&tegra124_dfll_fcpu_driver);
}
