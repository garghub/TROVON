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
void __init omap_4430sdp_display_init(void)
{
int r;
r = gpio_request_one(DISPLAY_SEL_GPIO, GPIOF_OUT_INIT_HIGH,
"display_sel");
if (r)
pr_err("%s: Could not get display_sel GPIO\n", __func__);
r = gpio_request_one(DLP_POWER_ON_GPIO, GPIOF_OUT_INIT_LOW,
"DLP POWER ON");
if (r)
pr_err("%s: Could not get DLP POWER ON GPIO\n", __func__);
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
r = gpio_request_one(DLP_POWER_ON_GPIO, GPIOF_OUT_INIT_LOW,
"DLP POWER ON");
if (r)
pr_err("%s: Could not get DLP POWER ON GPIO\n", __func__);
omap_display_init(&sdp4430_dss_data);
}
