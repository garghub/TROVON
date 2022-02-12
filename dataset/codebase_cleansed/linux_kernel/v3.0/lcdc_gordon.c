static void serigo(uint16 reg, uint8 data)
{
unsigned int tx_val = ((0x00FF & reg) << 8) | data;
unsigned char i, val = 0;
gpio_set_value(spi_cs, 1);
udelay(33);
val = (unsigned char)((tx_val & 0xFF00) >> 8);
for (i = 0; i < 8; i++) {
if (val & bit_shift[i])
gpio_set_value(spi_sdi, 1);
else
gpio_set_value(spi_sdi, 0);
udelay(33);
gpio_set_value(spi_sclk, 1);
udelay(33);
gpio_set_value(spi_sclk, 0);
}
gpio_set_value(spi_sdi, 0);
val = (uint8) (tx_val & 0x00FF);
for (i = 0; i < 8; i++) {
if (val & bit_shift[i])
gpio_set_value(spi_sdi, 1);
else
gpio_set_value(spi_sdi, 0);
udelay(33);
gpio_set_value(spi_sclk, 1);
udelay(33);
gpio_set_value(spi_sclk, 0);
}
gpio_set_value(spi_sdi, 0);
udelay(33);
gpio_set_value(spi_cs, 0);
}
static void spi_init(void)
{
spi_sclk = *(lcdc_gordon_pdata->gpio_num);
spi_cs = *(lcdc_gordon_pdata->gpio_num + 1);
spi_sdi = *(lcdc_gordon_pdata->gpio_num + 2);
spi_sdo = *(lcdc_gordon_pdata->gpio_num + 3);
gpio_set_value(spi_sclk, 0);
gpio_set_value(spi_sdi, 0);
gpio_set_value(spi_cs, 0);
}
static void gordon_disp_powerup(void)
{
if (!gordon_state.disp_powered_up && !gordon_state.display_on) {
gordon_state.disp_powered_up = TRUE;
}
}
static void gordon_init(void)
{
serigo(GORDON_REG_IMGCTL2, 0x00);
serigo(GORDON_REG_IMGSET1, 0x00);
serigo(GORDON_REG_IMGSET2, 0x12);
serigo(GORDON_REG_LCDIFSET1, 0x00);
serigo(GORDON_REG_PCCTL, 0x09);
serigo(GORDON_REG_LCDIFCTL2, 0x7B);
mdelay(1);
}
static void gordon_disp_on(void)
{
if (gordon_state.disp_powered_up && !gordon_state.display_on) {
gordon_init();
mdelay(20);
serigo(GORDON_REG_TPARAM1, 0x30);
serigo(GORDON_REG_TLCDIF1, 0x00);
serigo(GORDON_REG_TSSPB_ST1, 0x8B);
serigo(GORDON_REG_TSSPB_ED1, 0x93);
serigo(GORDON_REG_TSCK_ST1, 0x88);
serigo(GORDON_REG_TSCK_WD1, 0x00);
serigo(GORDON_REG_TGSPB_VST1, 0x01);
serigo(GORDON_REG_TGSPB_VED1, 0x02);
serigo(GORDON_REG_TGSPB_CH1, 0x5E);
serigo(GORDON_REG_TGCK_ST1, 0x80);
serigo(GORDON_REG_TGCK_ED1, 0x3C);
serigo(GORDON_REG_TPCTL_ST1, 0x50);
serigo(GORDON_REG_TPCTL_ED1, 0x74);
serigo(GORDON_REG_TPCHG_ED1, 0x78);
serigo(GORDON_REG_TCOM_CH1, 0x50);
serigo(GORDON_REG_THBP1, 0x84);
serigo(GORDON_REG_TPHCTL1, 0x00);
serigo(GORDON_REG_EVPH1, 0x70);
serigo(GORDON_REG_EVPL1, 0x64);
serigo(GORDON_REG_EVNH1, 0x56);
serigo(GORDON_REG_EVNL1, 0x48);
serigo(GORDON_REG_TBIAS1, 0x88);
serigo(GORDON_REG_TPARAM2, 0x28);
serigo(GORDON_REG_TLCDIF2, 0x14);
serigo(GORDON_REG_TSSPB_ST2, 0x49);
serigo(GORDON_REG_TSSPB_ED2, 0x4B);
serigo(GORDON_REG_TSCK_ST2, 0x4A);
serigo(GORDON_REG_TSCK_WD2, 0x02);
serigo(GORDON_REG_TGSPB_VST2, 0x02);
serigo(GORDON_REG_TGSPB_VED2, 0x03);
serigo(GORDON_REG_TGSPB_CH2, 0x2F);
serigo(GORDON_REG_TGCK_ST2, 0x40);
serigo(GORDON_REG_TGCK_ED2, 0x1E);
serigo(GORDON_REG_TPCTL_ST2, 0x2C);
serigo(GORDON_REG_TPCTL_ED2, 0x3A);
serigo(GORDON_REG_TPCHG_ED2, 0x3C);
serigo(GORDON_REG_TCOM_CH2, 0x28);
serigo(GORDON_REG_THBP2, 0x4D);
serigo(GORDON_REG_TPHCTL2, 0x1A);
serigo(GORDON_REG_IVBP1, 0x02);
serigo(GORDON_REG_IHBP1, 0x90);
serigo(GORDON_REG_IVNUM1, 0xA0);
serigo(GORDON_REG_IHNUM1, 0x78);
serigo(GORDON_REG_IVBP2, 0x02);
serigo(GORDON_REG_IHBP2, 0x48);
serigo(GORDON_REG_IVNUM2, 0x50);
serigo(GORDON_REG_IHNUM2, 0x3C);
serigo(GORDON_REG_POWCTL, 0x03);
mdelay(15);
serigo(GORDON_REG_POWCTL, 0x07);
mdelay(15);
serigo(GORDON_REG_POWCTL, 0x0F);
mdelay(15);
serigo(GORDON_REG_AVCTL, 0x03);
mdelay(15);
serigo(GORDON_REG_POWCTL, 0x1F);
mdelay(15);
serigo(GORDON_REG_POWCTL, 0x5F);
mdelay(15);
serigo(GORDON_REG_POWCTL, 0x7F);
mdelay(15);
serigo(GORDON_REG_LCDIFCTL1, 0x02);
mdelay(15);
serigo(GORDON_REG_IMGCTL1, 0x00);
mdelay(15);
serigo(GORDON_REG_LCDIFCTL3, 0x00);
mdelay(15);
serigo(GORDON_REG_VALTRAN, 0x01);
mdelay(15);
serigo(GORDON_REG_LCDIFCTL1, 0x03);
mdelay(1);
gordon_state.display_on = TRUE;
}
}
static int lcdc_gordon_panel_on(struct platform_device *pdev)
{
if (!gordon_state.disp_initialized) {
lcdc_gordon_pdata->panel_config_gpio(1);
spi_dac = *(lcdc_gordon_pdata->gpio_num + 4);
gpio_set_value(spi_dac, 0);
udelay(15);
gpio_set_value(spi_dac, 1);
spi_init();
gordon_disp_powerup();
gordon_disp_on();
gordon_state.disp_initialized = TRUE;
}
return 0;
}
static int lcdc_gordon_panel_off(struct platform_device *pdev)
{
if (gordon_state.disp_powered_up && gordon_state.display_on) {
serigo(GORDON_REG_LCDIFCTL2, 0x7B);
serigo(GORDON_REG_VALTRAN, 0x01);
serigo(GORDON_REG_LCDIFCTL1, 0x02);
serigo(GORDON_REG_LCDIFCTL3, 0x01);
mdelay(20);
serigo(GORDON_REG_VALTRAN, 0x01);
serigo(GORDON_REG_IMGCTL1, 0x01);
serigo(GORDON_REG_LCDIFCTL1, 0x00);
mdelay(20);
serigo(GORDON_REG_POWCTL, 0x1F);
mdelay(40);
serigo(GORDON_REG_POWCTL, 0x07);
mdelay(40);
serigo(GORDON_REG_POWCTL, 0x03);
mdelay(40);
serigo(GORDON_REG_POWCTL, 0x00);
mdelay(40);
lcdc_gordon_pdata->panel_config_gpio(0);
gordon_state.display_on = FALSE;
gordon_state.disp_initialized = FALSE;
}
return 0;
}
static void lcdc_gordon_set_backlight(struct msm_fb_data_type *mfd)
{
int bl_level = mfd->bl_level;
if (bl_level <= 1) {
serigo(GORDON_REG_LCDIFCTL2, 0x0B);
udelay(15);
serigo(GORDON_REG_VALTRAN, 0x01);
} else {
serigo(GORDON_REG_LCDIFCTL2, 0x7B);
udelay(15);
serigo(GORDON_REG_VALTRAN, 0x01);
}
}
static int __init gordon_probe(struct platform_device *pdev)
{
if (pdev->id == 0) {
lcdc_gordon_pdata = pdev->dev.platform_data;
return 0;
}
msm_fb_add_device(pdev);
return 0;
}
static int __init lcdc_gordon_panel_init(void)
{
int ret;
struct msm_panel_info *pinfo;
#ifdef CONFIG_FB_MSM_TRY_MDDI_CATCH_LCDC_PRISM
if (msm_fb_detect_client("lcdc_gordon_vga"))
return 0;
#endif
ret = platform_driver_register(&this_driver);
if (ret)
return ret;
pinfo = &gordon_panel_data.panel_info;
pinfo->xres = 480;
pinfo->yres = 640;
pinfo->type = LCDC_PANEL;
pinfo->pdest = DISPLAY_1;
pinfo->wait_cycle = 0;
pinfo->bpp = 24;
pinfo->fb_num = 2;
pinfo->clk_rate = 24500000;
pinfo->bl_max = 4;
pinfo->bl_min = 1;
pinfo->lcdc.h_back_porch = 84;
pinfo->lcdc.h_front_porch = 33;
pinfo->lcdc.h_pulse_width = 60;
pinfo->lcdc.v_back_porch = 0;
pinfo->lcdc.v_front_porch = 2;
pinfo->lcdc.v_pulse_width = 2;
pinfo->lcdc.border_clr = 0;
pinfo->lcdc.underflow_clr = 0xff;
pinfo->lcdc.hsync_skew = 0;
ret = platform_device_register(&this_device);
if (ret)
platform_driver_unregister(&this_driver);
return ret;
}
