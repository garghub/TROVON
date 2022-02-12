static int st_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
regmap_update_bits(st_restart_syscfg->regmap,
st_restart_syscfg->offset_rst,
st_restart_syscfg->mask_rst,
0);
regmap_update_bits(st_restart_syscfg->regmap,
st_restart_syscfg->offset_rst_msk,
st_restart_syscfg->mask_rst_msk,
0);
return NOTIFY_DONE;
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
return register_restart_handler(&st_restart_nb);
}
static int __init st_reset_init(void)
{
return platform_driver_register(&st_reset_driver);
}
