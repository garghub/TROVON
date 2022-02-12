void __init dm365_init_spi0(unsigned chipselect_mask,
struct spi_board_info *info, unsigned len)
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
static int __init dm365_init_devices(void)
{
if (!cpu_is_davinci_dm365())
return 0;
davinci_cfg_reg(DM365_INT_EDMA_CC);
platform_device_register(&dm365_edma_device);
platform_device_register(&dm365_mdio_device);
platform_device_register(&dm365_emac_device);
clk_add_alias(NULL, dev_name(&dm365_mdio_device.dev),
NULL, &dm365_emac_device.dev);
clk_add_alias("master", dm365_isif_dev.name, "vpss_master", NULL);
platform_device_register(&dm365_vpss_device);
platform_device_register(&dm365_isif_dev);
platform_device_register(&vpfe_capture_dev);
return 0;
}
void dm365_set_vpfe_config(struct vpfe_config *cfg)
{
vpfe_capture_dev.dev.platform_data = cfg;
}
