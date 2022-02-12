void dm644x_set_vpfe_config(struct vpfe_config *cfg)
{
vpfe_capture_dev.dev.platform_data = cfg;
}
void __init dm644x_init_asp(struct snd_platform_data *pdata)
{
davinci_cfg_reg(DM644X_MCBSP);
dm644x_asp_device.dev.platform_data = pdata;
platform_device_register(&dm644x_asp_device);
}
void __init dm644x_init(void)
{
davinci_common_init(&davinci_soc_info_dm644x);
}
static int __init dm644x_init_devices(void)
{
if (!cpu_is_davinci_dm644x())
return 0;
clk_add_alias("master", dm644x_ccdc_dev.name, "vpss_master", NULL);
clk_add_alias("slave", dm644x_ccdc_dev.name, "vpss_slave", NULL);
platform_device_register(&dm644x_edma_device);
platform_device_register(&dm644x_mdio_device);
platform_device_register(&dm644x_emac_device);
clk_add_alias(NULL, dev_name(&dm644x_mdio_device.dev),
NULL, &dm644x_emac_device.dev);
platform_device_register(&dm644x_vpss_device);
platform_device_register(&dm644x_ccdc_dev);
platform_device_register(&vpfe_capture_dev);
return 0;
}
