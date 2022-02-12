static int dm644x_venc_setup_clock(enum vpbe_enc_timings_type type,
unsigned int mode)
{
int ret = 0;
u32 v = DM644X_VPSS_VENCLKEN;
switch (type) {
case VPBE_ENC_STD:
v |= DM644X_VPSS_DACCLKEN;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
break;
case VPBE_ENC_DV_PRESET:
switch (mode) {
case V4L2_DV_480P59_94:
case V4L2_DV_576P50:
v |= DM644X_VPSS_MUXSEL_PLL2_MODE |
DM644X_VPSS_DACCLKEN;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
break;
case V4L2_DV_720P60:
case V4L2_DV_1080I60:
case V4L2_DV_1080P30:
v |= DM644X_VPSS_MUXSEL_VPBECLK_MODE;
writel(v, DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL));
break;
default:
ret = -EINVAL;
break;
}
break;
default:
ret = -EINVAL;
}
return ret;
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
clk_add_alias("master", dm644x_ccdc_dev.name,
"vpss_master", NULL);
clk_add_alias("slave", dm644x_ccdc_dev.name,
"vpss_slave", NULL);
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
if (!cpu_is_davinci_dm644x())
return 0;
platform_device_register(&dm644x_edma_device);
platform_device_register(&dm644x_mdio_device);
platform_device_register(&dm644x_emac_device);
clk_add_alias(NULL, dev_name(&dm644x_mdio_device.dev),
NULL, &dm644x_emac_device.dev);
return 0;
}
