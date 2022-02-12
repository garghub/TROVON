void __init omap4_panda_display_init(void)
{
omap_display_init(&omap4_panda_dss_data);
if (cpu_is_omap446x() || omap_rev() > OMAP4430_REV_ES2_2)
omap_hdmi_init(OMAP_HDMI_SDA_SCL_EXTERNAL_PULLUP);
else
omap_hdmi_init(0);
omap_mux_init_gpio(HDMI_GPIO_LS_OE, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_CT_CP_HPD, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_HPD, OMAP_PIN_INPUT_PULLDOWN);
}
void __init omap4_panda_display_init_of(void)
{
omap_display_init(&omap4_panda_dss_data);
}
static void sdp4430_picodlp_init(void)
{
int r;
const struct gpio picodlp_gpios[] = {
{DLP_POWER_ON_GPIO, GPIOF_OUT_INIT_LOW,
"DLP POWER ON"},
{sdp4430_picodlp_pdata.emu_done_gpio, GPIOF_IN,
"DLP EMU DONE"},
{sdp4430_picodlp_pdata.pwrgood_gpio, GPIOF_OUT_INIT_LOW,
"DLP PWRGOOD"},
};
r = gpio_request_array(picodlp_gpios, ARRAY_SIZE(picodlp_gpios));
if (r)
pr_err("Cannot request PicoDLP GPIOs, error %d\n", r);
}
static int sdp4430_panel_enable_picodlp(struct omap_dss_device *dssdev)
{
gpio_set_value(DISPLAY_SEL_GPIO, 0);
gpio_set_value(DLP_POWER_ON_GPIO, 1);
return 0;
}
static void sdp4430_panel_disable_picodlp(struct omap_dss_device *dssdev)
{
gpio_set_value(DLP_POWER_ON_GPIO, 0);
gpio_set_value(DISPLAY_SEL_GPIO, 1);
}
void __init omap_4430sdp_display_init(void)
{
int r;
r = gpio_request_one(DISPLAY_SEL_GPIO, GPIOF_OUT_INIT_HIGH,
"display_sel");
if (r)
pr_err("%s: Could not get display_sel GPIO\n", __func__);
sdp4430_picodlp_init();
omap_display_init(&sdp4430_dss_data);
if (cpu_is_omap446x() || omap_rev() > OMAP4430_REV_ES2_2)
omap_hdmi_init(OMAP_HDMI_SDA_SCL_EXTERNAL_PULLUP);
else
omap_hdmi_init(0);
omap_mux_init_gpio(HDMI_GPIO_LS_OE, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_CT_CP_HPD, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(HDMI_GPIO_HPD, OMAP_PIN_INPUT_PULLDOWN);
}
void __init omap_4430sdp_display_init_of(void)
{
int r;
r = gpio_request_one(DISPLAY_SEL_GPIO, GPIOF_OUT_INIT_HIGH,
"display_sel");
if (r)
pr_err("%s: Could not get display_sel GPIO\n", __func__);
sdp4430_picodlp_init();
omap_display_init(&sdp4430_dss_data);
}
