void __init dm355_init_spi0(unsigned chipselect_mask,
const struct spi_board_info *info, unsigned len)
{
davinci_cfg_reg(DM355_SPI0_SDI);
if (chipselect_mask & BIT(0))
davinci_cfg_reg(DM355_SPI0_SDENA0);
if (chipselect_mask & BIT(1))
davinci_cfg_reg(DM355_SPI0_SDENA1);
spi_register_board_info(info, len);
platform_device_register(&dm355_spi0_device);
}
static void dm355_ccdc_setup_pinmux(void)
{
davinci_cfg_reg(DM355_VIN_PCLK);
davinci_cfg_reg(DM355_VIN_CAM_WEN);
davinci_cfg_reg(DM355_VIN_CAM_VD);
davinci_cfg_reg(DM355_VIN_CAM_HD);
davinci_cfg_reg(DM355_VIN_YIN_EN);
davinci_cfg_reg(DM355_VIN_CINL_EN);
davinci_cfg_reg(DM355_VIN_CINH_EN);
}
void dm355_set_vpfe_config(struct vpfe_config *cfg)
{
vpfe_capture_dev.dev.platform_data = cfg;
}
void __init dm355_init_asp1(u32 evt_enable, struct snd_platform_data *pdata)
{
if (evt_enable & ASP1_TX_EVT_EN)
davinci_cfg_reg(DM355_EVT8_ASP1_TX);
if (evt_enable & ASP1_RX_EVT_EN)
davinci_cfg_reg(DM355_EVT9_ASP1_RX);
dm355_asp1_device.dev.platform_data = pdata;
platform_device_register(&dm355_asp1_device);
}
void __init dm355_init(void)
{
davinci_common_init(&davinci_soc_info_dm355);
davinci_map_sysmod();
}
static int __init dm355_init_devices(void)
{
if (!cpu_is_davinci_dm355())
return 0;
clk_add_alias("master", dm355_ccdc_dev.name, "vpss_master", NULL);
clk_add_alias("slave", dm355_ccdc_dev.name, "vpss_master", NULL);
davinci_cfg_reg(DM355_INT_EDMA_CC);
platform_device_register(&dm355_edma_device);
platform_device_register(&dm355_vpss_device);
platform_device_register(&dm355_ccdc_dev);
platform_device_register(&vpfe_capture_dev);
return 0;
}
