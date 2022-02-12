void __init dm365_init_spi0(unsigned chipselect_mask,
const struct spi_board_info *info, unsigned len)
{
davinci_cfg_reg(DM365_SPI0_SCLK);
davinci_cfg_reg(DM365_SPI0_SDI);
davinci_cfg_reg(DM365_SPI0_SDO);
if (chipselect_mask & BIT(0))
davinci_cfg_reg(DM365_SPI0_SDENA0);
if (chipselect_mask & BIT(1))
davinci_cfg_reg(DM365_SPI0_SDENA1);
spi_register_board_info(info, len);
platform_device_register(&dm365_spi0_device);
}
int __init dm365_gpio_register(void)
{
return davinci_gpio_register(dm365_gpio_resources,
ARRAY_SIZE(dm365_gpio_resources),
&dm365_gpio_platform_data);
}
void __init dm365_init_asp(struct snd_platform_data *pdata)
{
davinci_cfg_reg(DM365_MCBSP0_BDX);
davinci_cfg_reg(DM365_MCBSP0_X);
davinci_cfg_reg(DM365_MCBSP0_BFSX);
davinci_cfg_reg(DM365_MCBSP0_BDR);
davinci_cfg_reg(DM365_MCBSP0_R);
davinci_cfg_reg(DM365_MCBSP0_BFSR);
davinci_cfg_reg(DM365_EVT2_ASP_TX);
davinci_cfg_reg(DM365_EVT3_ASP_RX);
dm365_asp_device.dev.platform_data = pdata;
platform_device_register(&dm365_asp_device);
}
void __init dm365_init_vc(struct snd_platform_data *pdata)
{
davinci_cfg_reg(DM365_EVT2_VC_TX);
davinci_cfg_reg(DM365_EVT3_VC_RX);
dm365_vc_device.dev.platform_data = pdata;
platform_device_register(&dm365_vc_device);
}
void __init dm365_init_ks(struct davinci_ks_platform_data *pdata)
{
dm365_ks_device.dev.platform_data = pdata;
platform_device_register(&dm365_ks_device);
}
void __init dm365_init_rtc(void)
{
davinci_cfg_reg(DM365_INT_PRTCSS);
platform_device_register(&dm365_rtc_device);
}
void __init dm365_init(void)
{
davinci_common_init(&davinci_soc_info_dm365);
davinci_map_sysmod();
}
static void dm365_isif_setup_pinmux(void)
{
davinci_cfg_reg(DM365_VIN_CAM_WEN);
davinci_cfg_reg(DM365_VIN_CAM_VD);
davinci_cfg_reg(DM365_VIN_CAM_HD);
davinci_cfg_reg(DM365_VIN_YIN4_7_EN);
davinci_cfg_reg(DM365_VIN_YIN0_3_EN);
}
static int dm365_vpbe_setup_pinmux(u32 if_type, int field)
{
switch (if_type) {
case MEDIA_BUS_FMT_SGRBG8_1X8:
davinci_cfg_reg(DM365_VOUT_FIELD_G81);
davinci_cfg_reg(DM365_VOUT_COUTL_EN);
davinci_cfg_reg(DM365_VOUT_COUTH_EN);
break;
case MEDIA_BUS_FMT_YUYV10_1X20:
if (field)
davinci_cfg_reg(DM365_VOUT_FIELD);
else
davinci_cfg_reg(DM365_VOUT_FIELD_G81);
davinci_cfg_reg(DM365_VOUT_COUTL_EN);
davinci_cfg_reg(DM365_VOUT_COUTH_EN);
break;
default:
return -EINVAL;
}
return 0;
}
static int dm365_venc_setup_clock(enum vpbe_enc_timings_type type,
unsigned int pclock)
{
void __iomem *vpss_clkctl_reg;
u32 val;
vpss_clkctl_reg = DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL);
switch (type) {
case VPBE_ENC_STD:
val = VPSS_VENCCLKEN_ENABLE | VPSS_DACCLKEN_ENABLE;
break;
case VPBE_ENC_DV_TIMINGS:
if (pclock <= 27000000) {
val = VPSS_VENCCLKEN_ENABLE | VPSS_DACCLKEN_ENABLE;
} else {
val = VPSS_PLLC2SYSCLK5_ENABLE | VPSS_DACCLKEN_ENABLE |
VPSS_VENCCLKEN_ENABLE;
}
break;
default:
return -EINVAL;
}
writel(val, vpss_clkctl_reg);
return 0;
}
int __init dm365_init_video(struct vpfe_config *vpfe_cfg,
struct vpbe_config *vpbe_cfg)
{
if (vpfe_cfg || vpbe_cfg)
platform_device_register(&dm365_vpss_device);
if (vpfe_cfg) {
vpfe_capture_dev.dev.platform_data = vpfe_cfg;
platform_device_register(&dm365_isif_dev);
platform_device_register(&vpfe_capture_dev);
}
if (vpbe_cfg) {
dm365_vpbe_dev.dev.platform_data = vpbe_cfg;
platform_device_register(&dm365_osd_dev);
platform_device_register(&dm365_venc_dev);
platform_device_register(&dm365_vpbe_dev);
platform_device_register(&dm365_vpbe_display);
}
return 0;
}
static int __init dm365_init_devices(void)
{
int ret = 0;
if (!cpu_is_davinci_dm365())
return 0;
davinci_cfg_reg(DM365_INT_EDMA_CC);
platform_device_register(&dm365_edma_device);
platform_device_register(&dm365_mdio_device);
platform_device_register(&dm365_emac_device);
ret = davinci_init_wdt();
if (ret)
pr_warn("%s: watchdog init failed: %d\n", __func__, ret);
return ret;
}
