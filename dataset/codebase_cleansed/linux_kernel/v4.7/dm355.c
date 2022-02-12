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
static int dm355_vpbe_setup_pinmux(u32 if_type, int field)
{
switch (if_type) {
case MEDIA_BUS_FMT_SGRBG8_1X8:
davinci_cfg_reg(DM355_VOUT_FIELD_G70);
break;
case MEDIA_BUS_FMT_YUYV10_1X20:
if (field)
davinci_cfg_reg(DM355_VOUT_FIELD);
else
davinci_cfg_reg(DM355_VOUT_FIELD_G70);
break;
default:
return -EINVAL;
}
davinci_cfg_reg(DM355_VOUT_COUTL_EN);
davinci_cfg_reg(DM355_VOUT_COUTH_EN);
return 0;
}
static int dm355_venc_setup_clock(enum vpbe_enc_timings_type type,
unsigned int pclock)
{
void __iomem *vpss_clk_ctrl_reg;
vpss_clk_ctrl_reg = DAVINCI_SYSMOD_VIRT(SYSMOD_VPSS_CLKCTL);
switch (type) {
case VPBE_ENC_STD:
writel(VPSS_DACCLKEN_ENABLE | VPSS_VENCCLKEN_ENABLE,
vpss_clk_ctrl_reg);
break;
case VPBE_ENC_DV_TIMINGS:
if (pclock > 27000000)
writel(VPSS_MUXSEL_EXTCLK_ENABLE, vpss_clk_ctrl_reg);
break;
default:
return -EINVAL;
}
return 0;
}
int __init dm355_gpio_register(void)
{
return davinci_gpio_register(dm355_gpio_resources,
ARRAY_SIZE(dm355_gpio_resources),
&dm355_gpio_platform_data);
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
davinci_clk_init(davinci_soc_info_dm355.cpu_clks);
}
int __init dm355_init_video(struct vpfe_config *vpfe_cfg,
struct vpbe_config *vpbe_cfg)
{
if (vpfe_cfg || vpbe_cfg)
platform_device_register(&dm355_vpss_device);
if (vpfe_cfg) {
vpfe_capture_dev.dev.platform_data = vpfe_cfg;
platform_device_register(&dm355_ccdc_dev);
platform_device_register(&vpfe_capture_dev);
}
if (vpbe_cfg) {
dm355_vpbe_dev.dev.platform_data = vpbe_cfg;
platform_device_register(&dm355_osd_dev);
platform_device_register(&dm355_venc_dev);
platform_device_register(&dm355_vpbe_dev);
platform_device_register(&dm355_vpbe_display);
}
return 0;
}
static int __init dm355_init_devices(void)
{
struct platform_device *edma_pdev;
int ret = 0;
if (!cpu_is_davinci_dm355())
return 0;
davinci_cfg_reg(DM355_INT_EDMA_CC);
edma_pdev = platform_device_register_full(&dm355_edma_device);
if (IS_ERR(edma_pdev)) {
pr_warn("%s: Failed to register eDMA\n", __func__);
return PTR_ERR(edma_pdev);
}
ret = davinci_init_wdt();
if (ret)
pr_warn("%s: watchdog init failed: %d\n", __func__, ret);
return ret;
}
