static int axxia_restart_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
regmap_write(syscon, SC_CRIT_WRITE_KEY, 0xab);
regmap_write(syscon, SC_LATCH_ON_RESET, 0x00000040);
regmap_write(syscon, SC_EFUSE_INT_STATUS, EFUSE_READ_DONE);
regmap_update_bits(syscon, SC_RESET_CONTROL,
RSTCTL_RST_CHIP, RSTCTL_RST_CHIP);
return NOTIFY_DONE;
}
static int axxia_reset_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int err;
syscon = syscon_regmap_lookup_by_phandle(dev->of_node, "syscon");
if (IS_ERR(syscon)) {
pr_err("%s: syscon lookup failed\n", dev->of_node->name);
return PTR_ERR(syscon);
}
err = register_restart_handler(&axxia_restart_nb);
if (err)
dev_err(dev, "cannot register restart handler (err=%d)\n", err);
return err;
}
static int __init axxia_reset_init(void)
{
return platform_driver_register(&axxia_reset_driver);
}
