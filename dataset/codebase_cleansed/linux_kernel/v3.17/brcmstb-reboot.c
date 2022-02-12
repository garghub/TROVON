static void brcmstb_reboot(enum reboot_mode mode, const char *cmd)
{
int rc;
u32 tmp;
rc = regmap_write(regmap, rst_src_en, 1);
if (rc) {
pr_err("failed to write rst_src_en (%d)\n", rc);
return;
}
rc = regmap_read(regmap, rst_src_en, &tmp);
if (rc) {
pr_err("failed to read rst_src_en (%d)\n", rc);
return;
}
rc = regmap_write(regmap, sw_mstr_rst, 1);
if (rc) {
pr_err("failed to write sw_mstr_rst (%d)\n", rc);
return;
}
rc = regmap_read(regmap, sw_mstr_rst, &tmp);
if (rc) {
pr_err("failed to read sw_mstr_rst (%d)\n", rc);
return;
}
while (1)
;
}
static int brcmstb_reboot_probe(struct platform_device *pdev)
{
int rc;
struct device_node *np = pdev->dev.of_node;
regmap = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(regmap)) {
pr_err("failed to get syscon phandle\n");
return -EINVAL;
}
rc = of_property_read_u32_index(np, "syscon", RESET_SOURCE_ENABLE_REG,
&rst_src_en);
if (rc) {
pr_err("can't get rst_src_en offset (%d)\n", rc);
return -EINVAL;
}
rc = of_property_read_u32_index(np, "syscon", SW_MASTER_RESET_REG,
&sw_mstr_rst);
if (rc) {
pr_err("can't get sw_mstr_rst offset (%d)\n", rc);
return -EINVAL;
}
arm_pm_restart = brcmstb_reboot;
return 0;
}
static int __init brcmstb_reboot_init(void)
{
return platform_driver_probe(&brcmstb_reboot_driver,
brcmstb_reboot_probe);
}
