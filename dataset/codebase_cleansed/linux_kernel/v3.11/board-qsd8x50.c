static int __init msm_init_smc91x(void)
{
if (machine_is_qsd8x50_surf()) {
smc91x_resources[0].start = qsd8x50_surf_smc91x_base;
smc91x_resources[0].end = qsd8x50_surf_smc91x_base + 0xff;
smc91x_resources[1].start =
gpio_to_irq(qsd8x50_surf_smc91x_gpio);
smc91x_resources[1].end =
gpio_to_irq(qsd8x50_surf_smc91x_gpio);
platform_device_register(&smc91x_device);
}
return 0;
}
static uint32_t msm_sdcc_setup_power(struct device *dv, unsigned int vdd)
{
int rc = 0;
struct platform_device *pdev;
pdev = container_of(dv, struct platform_device, dev);
if (vdd == 0) {
if (!vreg_sts)
return 0;
clear_bit(pdev->id, &vreg_sts);
if (!vreg_sts) {
rc = vreg_disable(vreg_mmc);
if (rc)
pr_err("vreg_mmc disable failed for slot "
"%d: %d\n", pdev->id, rc);
}
return 0;
}
if (!vreg_sts) {
rc = vreg_set_level(vreg_mmc, 2900);
if (rc)
pr_err("vreg_mmc set level failed for slot %d: %d\n",
pdev->id, rc);
rc = vreg_enable(vreg_mmc);
if (rc)
pr_err("vreg_mmc enable failed for slot %d: %d\n",
pdev->id, rc);
}
set_bit(pdev->id, &vreg_sts);
return 0;
}
static void __init qsd8x50_init_mmc(void)
{
vreg_mmc = vreg_get(NULL, "gp5");
if (IS_ERR(vreg_mmc)) {
pr_err("vreg get for vreg_mmc failed (%ld)\n",
PTR_ERR(vreg_mmc));
return;
}
msm_add_sdcc(1, &qsd8x50_sdc1_data, 0, 0);
}
static void __init qsd8x50_map_io(void)
{
msm_map_qsd8x50_io();
}
static void __init qsd8x50_init_irq(void)
{
msm_init_irq();
msm_init_sirc();
}
static void __init qsd8x50_init(void)
{
msm_device_otg.dev.platform_data = &msm_otg_pdata;
msm_device_hsusb.dev.parent = &msm_device_otg.dev;
msm_device_hsusb_host.dev.parent = &msm_device_otg.dev;
platform_add_devices(devices, ARRAY_SIZE(devices));
qsd8x50_init_mmc();
}
static void __init qsd8x50_init_late(void)
{
smd_debugfs_init();
}
