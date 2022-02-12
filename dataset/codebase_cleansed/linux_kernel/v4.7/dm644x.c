static int dm644x_venc_setup_clock(enum vpbe_enc_timings_type type,
unsigned int pclock)
{
int ret = 0;
u32 v = DM644X_VPSS_VENCLKEN;
switch (type) {
case VPBE_ENC_STD:
v |= DM644X_VPSS_DACCLKEN;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
break;
case VPBE_ENC_DV_TIMINGS:
if (pclock <= 27000000) {
v |= DM644X_VPSS_DACCLKEN;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
} else {
v |= DM644X_VPSS_MUXSEL_VPBECLK_MODE;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
}
break;
default:
ret = -EINVAL;
}
return ret;
}
int __init dm644x_gpio_register(void)
{
return davinci_gpio_register(dm644_gpio_resources,
ARRAY_SIZE(dm644_gpio_resources),
&dm644_gpio_platform_data);
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
davinci_map_sysmod();
davinci_clk_init(davinci_soc_info_dm644x.cpu_clks);
}
int __init dm644x_init_video(struct vpfe_config *vpfe_cfg,
struct vpbe_config *vpbe_cfg)
{
if (vpfe_cfg || vpbe_cfg)
platform_device_register(&dm644x_vpss_device);
if (vpfe_cfg) {
dm644x_vpfe_dev.dev.platform_data = vpfe_cfg;
platform_device_register(&dm644x_ccdc_dev);
platform_device_register(&dm644x_vpfe_dev);
}
if (vpbe_cfg) {
dm644x_vpbe_dev.dev.platform_data = vpbe_cfg;
platform_device_register(&dm644x_osd_dev);
platform_device_register(&dm644x_venc_dev);
platform_device_register(&dm644x_vpbe_dev);
platform_device_register(&dm644x_vpbe_display);
}
return 0;
}
static int __init dm644x_init_devices(void)
{
struct platform_device *edma_pdev;
int ret = 0;
if (!cpu_is_davinci_dm644x())
return 0;
edma_pdev = platform_device_register_full(&dm644x_edma_device);
if (IS_ERR(edma_pdev)) {
pr_warn("%s: Failed to register eDMA\n", __func__);
return PTR_ERR(edma_pdev);
}
platform_device_register(&dm644x_mdio_device);
platform_device_register(&dm644x_emac_device);
ret = davinci_init_wdt();
if (ret)
pr_warn("%s: watchdog init failed: %d\n", __func__, ret);
return ret;
}
