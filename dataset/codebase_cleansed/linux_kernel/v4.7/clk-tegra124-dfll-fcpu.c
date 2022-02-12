static int tegra124_dfll_fcpu_probe(struct platform_device *pdev)
{
int process_id, speedo_id, speedo_value, err;
struct tegra_dfll_soc_data *soc;
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
soc->max_freq = cpu_max_freq_table[speedo_id];
soc->cvb = tegra_cvb_add_opp_table(soc->dev, tegra124_cpu_cvb_tables,
ARRAY_SIZE(tegra124_cpu_cvb_tables),
process_id, speedo_id, speedo_value,
soc->max_freq);
if (IS_ERR(soc->cvb)) {
dev_err(&pdev->dev, "couldn't add OPP table: %ld\n",
PTR_ERR(soc->cvb));
return PTR_ERR(soc->cvb);
}
err = tegra_dfll_register(pdev, soc);
if (err < 0) {
tegra_cvb_remove_opp_table(soc->dev, soc->cvb, soc->max_freq);
return err;
}
platform_set_drvdata(pdev, soc);
return 0;
}
static int tegra124_dfll_fcpu_remove(struct platform_device *pdev)
{
struct tegra_dfll_soc_data *soc = platform_get_drvdata(pdev);
int err;
err = tegra_dfll_unregister(pdev);
if (err < 0)
dev_err(&pdev->dev, "failed to unregister DFLL: %d\n", err);
tegra_cvb_remove_opp_table(soc->dev, soc->cvb, soc->max_freq);
return 0;
}
static int __init tegra124_dfll_fcpu_init(void)
{
return platform_driver_register(&tegra124_dfll_fcpu_driver);
}
static void __exit tegra124_dfll_fcpu_exit(void)
{
platform_driver_unregister(&tegra124_dfll_fcpu_driver);
}
