static void do_axxia_restart(enum reboot_mode reboot_mode, const char *cmd)
{
regmap_write(syscon, SC_CRIT_WRITE_KEY, 0xab);
regmap_write(syscon, SC_LATCH_ON_RESET, 0x00000040);
regmap_write(syscon, SC_EFUSE_INT_STATUS, EFUSE_READ_DONE);
regmap_update_bits(syscon, SC_RESET_CONTROL,
RSTCTL_RST_CHIP, RSTCTL_RST_CHIP);
}
static int axxia_reset_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
syscon = syscon_regmap_lookup_by_phandle(dev->of_node, "syscon");
if (IS_ERR(syscon)) {
pr_err("%s: syscon lookup failed\n", dev->of_node->name);
return PTR_ERR(syscon);
}
arm_pm_restart = do_axxia_restart;
return 0;
}
static int __init axxia_reset_init(void)
{
return platform_driver_register(&axxia_reset_driver);
}
