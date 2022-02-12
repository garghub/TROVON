static void st_restart(enum reboot_mode reboot_mode, const char *cmd)
{
regmap_update_bits(st_restart_syscfg->regmap,
st_restart_syscfg->offset_rst,
st_restart_syscfg->mask_rst,
0);
regmap_update_bits(st_restart_syscfg->regmap,
st_restart_syscfg->offset_rst_msk,
st_restart_syscfg->mask_rst_msk,
0);
}
static int st_reset_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct device *dev = &pdev->dev;
match = of_match_device(st_reset_of_match, dev);
if (!match)
return -ENODEV;
st_restart_syscfg = (struct reset_syscfg *)match->data;
st_restart_syscfg->regmap =
syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(st_restart_syscfg->regmap)) {
dev_err(dev, "No syscfg phandle specified\n");
return PTR_ERR(st_restart_syscfg->regmap);
}
arm_pm_restart = st_restart;
return 0;
}
static int __init st_reset_init(void)
{
return platform_driver_register(&st_reset_driver);
}
