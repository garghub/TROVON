void u300_pm_poweroff(void)
{
sigset_t old, all;
sigfillset(&all);
if (!sigprocmask(SIG_BLOCK, &all, &old)) {
if (main_power_15)
regulator_disable(main_power_15);
else
pr_err("regulator not available to shut down system\n");
(void) sigprocmask(SIG_SETMASK, &old, NULL);
}
return;
}
static int __init __u300_init_boardpower(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *syscon_np;
struct regmap *regmap;
int err;
pr_info("U300: setting up board power\n");
syscon_np = of_parse_phandle(np, "syscon", 0);
if (!syscon_np) {
pr_crit("U300: no syscon node\n");
return -ENODEV;
}
regmap = syscon_node_to_regmap(syscon_np);
if (!regmap) {
pr_crit("U300: could not locate syscon regmap\n");
return -ENODEV;
}
main_power_15 = regulator_get(&pdev->dev, "vana15");
if (IS_ERR(main_power_15)) {
pr_err("could not get vana15");
return PTR_ERR(main_power_15);
}
err = regulator_enable(main_power_15);
if (err) {
pr_err("could not enable vana15\n");
return err;
}
pr_info("U300: disable system controller pull-up\n");
regmap_update_bits(regmap, U300_SYSCON_PMCR,
U300_SYSCON_PMCR_DCON_ENABLE, 0);
pm_power_off = u300_pm_poweroff;
return 0;
}
static int __init s365_board_probe(struct platform_device *pdev)
{
return __u300_init_boardpower(pdev);
}
static int __init u300_init_boardpower(void)
{
return platform_driver_probe(&s365_board_driver,
s365_board_probe);
}
