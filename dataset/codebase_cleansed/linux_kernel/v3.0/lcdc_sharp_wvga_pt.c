static void sharp_spi_write_byte(u8 val)
{
int i;
for (i = 0; i < 8; i++) {
if (val & bit_shift[i])
gpio_set_value(spi_mosi, 1);
else
gpio_set_value(spi_mosi, 0);
gpio_set_value(spi_sclk, 1);
gpio_set_value(spi_sclk, 0);
}
}
static void serigo(u8 reg, u8 data)
{
gpio_set_value(spi_cs, 0);
udelay(1);
sharp_spi_write_byte(reg);
gpio_set_value(spi_mosi, 0);
udelay(1);
sharp_spi_write_byte(data);
gpio_set_value(spi_mosi, 0);
gpio_set_value(spi_cs, 1);
}
static void sharp_spi_init(void)
{
spi_sclk = *(lcdc_sharp_pdata->gpio_num);
spi_cs = *(lcdc_sharp_pdata->gpio_num + 1);
spi_mosi = *(lcdc_sharp_pdata->gpio_num + 2);
spi_miso = *(lcdc_sharp_pdata->gpio_num + 3);
gpio_set_value(spi_sclk, 0);
gpio_set_value(spi_mosi, 0);
gpio_set_value(spi_cs, 1);
}
static void sharp_disp_powerup(void)
{
if (!sharp_state.disp_powered_up && !sharp_state.display_on)
sharp_state.disp_powered_up = TRUE;
}
static void sharp_disp_on(void)
{
int i;
if (sharp_state.disp_powered_up && !sharp_state.display_on) {
for (i = 0; i < ARRAY_SIZE(init_sequence); i++) {
serigo(init_sequence[i].addr,
init_sequence[i].data);
}
mdelay(10);
serigo(31, 0xC1);
mdelay(10);
serigo(31, 0xD9);
serigo(31, 0xDF);
sharp_state.display_on = TRUE;
}
}
static int lcdc_sharp_panel_on(struct platform_device *pdev)
{
if (!sharp_state.disp_initialized) {
lcdc_sharp_pdata->panel_config_gpio(1);
sharp_spi_init();
sharp_disp_powerup();
sharp_disp_on();
sharp_state.disp_initialized = TRUE;
}
return 0;
}
static int lcdc_sharp_panel_off(struct platform_device *pdev)
{
if (sharp_state.disp_powered_up && sharp_state.display_on) {
serigo(4, 0x00);
mdelay(40);
serigo(31, 0xC1);
mdelay(40);
serigo(31, 0x00);
mdelay(100);
sharp_state.display_on = FALSE;
sharp_state.disp_initialized = FALSE;
}
return 0;
}
static int __init sharp_probe(struct platform_device *pdev)
{
if (pdev->id == 0) {
lcdc_sharp_pdata = pdev->dev.platform_data;
return 0;
}
msm_fb_add_device(pdev);
return 0;
}
static int __init lcdc_sharp_panel_init(void)
{
int ret;
struct msm_panel_info *pinfo;
#ifdef CONFIG_FB_MSM_MDDI_AUTO_DETECT
if (msm_fb_detect_client("lcdc_sharp_wvga_pt"))
return 0;
#endif
ret = platform_driver_register(&this_driver);
if (ret)
return ret;
pinfo = &sharp_panel_data.panel_info;
pinfo->xres = 480;
pinfo->yres = 800;
pinfo->type = LCDC_PANEL;
pinfo->pdest = DISPLAY_1;
pinfo->wait_cycle = 0;
pinfo->bpp = 18;
pinfo->fb_num = 2;
pinfo->clk_rate = 24500000;
pinfo->bl_max = 4;
pinfo->bl_min = 1;
pinfo->lcdc.h_back_porch = 20;
pinfo->lcdc.h_front_porch = 10;
pinfo->lcdc.h_pulse_width = 10;
pinfo->lcdc.v_back_porch = 2;
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
