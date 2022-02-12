static void w1_enable_external_pullup(int enable)
{
gpio_set_value(GPIO_W1_PULLUP_ENABLE, enable);
msleep(100);
}
static void __init raumfeld_w1_init(void)
{
int ret = gpio_request(GPIO_W1_PULLUP_ENABLE,
"W1 external pullup enable");
if (ret < 0)
pr_warn("Unable to request GPIO_W1_PULLUP_ENABLE\n");
else
gpio_direction_output(GPIO_W1_PULLUP_ENABLE, 0);
platform_device_register(&raumfeld_w1_gpio_device);
}
static void __init raumfeld_lcd_init(void)
{
int ret;
ret = gpio_request(GPIO_TFT_VA_EN, "display VA enable");
if (ret < 0)
pr_warn("Unable to request GPIO_TFT_VA_EN\n");
else
gpio_direction_output(GPIO_TFT_VA_EN, 1);
msleep(100);
ret = gpio_request(GPIO_DISPLAY_ENABLE, "display enable");
if (ret < 0)
pr_warn("Unable to request GPIO_DISPLAY_ENABLE\n");
else
gpio_direction_output(GPIO_DISPLAY_ENABLE, 1);
if ((system_rev & 0xff) == 2) {
platform_device_register(&raumfeld_lt3593_device);
} else {
mfp_cfg_t raumfeld_pwm_pin_config = GPIO17_PWM0_OUT;
pxa3xx_mfp_config(&raumfeld_pwm_pin_config, 1);
pwm_add_table(raumfeld_pwm_lookup,
ARRAY_SIZE(raumfeld_pwm_lookup));
platform_device_register(&raumfeld_pwm_backlight_device);
}
pxa_set_fb_info(NULL, &raumfeld_sharp_lcd_info);
platform_device_register(&pxa3xx_device_gcu);
}
static int raumfeld_mci_init(struct device *dev, irq_handler_t isr, void *data)
{
gpio_set_value(GPIO_W2W_RESET, 1);
gpio_set_value(GPIO_W2W_PDN, 1);
return 0;
}
static void raumfeld_mci_exit(struct device *dev, void *data)
{
gpio_set_value(GPIO_W2W_RESET, 0);
gpio_set_value(GPIO_W2W_PDN, 0);
}
static int power_supply_init(struct device *dev)
{
return 0;
}
static void power_supply_exit(struct device *dev)
{
}
static int raumfeld_is_ac_online(void)
{
return !gpio_get_value(GPIO_CHARGE_DC_OK);
}
static int raumfeld_is_usb_online(void)
{
return 0;
}
static void raumfeld_power_signal_charged(void)
{
struct power_supply *psy =
power_supply_get_by_name(raumfeld_power_supplicants[0]);
if (psy) {
power_supply_set_battery_charged(psy);
power_supply_put(psy);
}
}
static int raumfeld_power_resume(void)
{
if (!gpio_get_value(GPIO_CHARGE_DONE))
raumfeld_power_signal_charged();
return 0;
}
static irqreturn_t charge_done_irq(int irq, void *dev_id)
{
raumfeld_power_signal_charged();
return IRQ_HANDLED;
}
static void __init raumfeld_power_init(void)
{
int ret;
ret = gpio_request(GPIO_CHRG_PEN2, "CHRG_PEN2");
if (ret < 0)
pr_warn("Unable to request GPIO_CHRG_PEN2\n");
else
gpio_direction_output(GPIO_CHRG_PEN2, 1);
ret = gpio_request(GPIO_CHARGE_DC_OK, "CABLE_DC_OK");
if (ret < 0)
pr_warn("Unable to request GPIO_CHARGE_DC_OK\n");
ret = gpio_request(GPIO_CHARGE_USB_SUSP, "CHARGE_USB_SUSP");
if (ret < 0)
pr_warn("Unable to request GPIO_CHARGE_USB_SUSP\n");
else
gpio_direction_output(GPIO_CHARGE_USB_SUSP, 0);
power_supply_resources[0].start = gpio_to_irq(GPIO_CHARGE_DC_OK);
power_supply_resources[0].end = gpio_to_irq(GPIO_CHARGE_DC_OK);
ret = request_irq(gpio_to_irq(GPIO_CHARGE_DONE),
&charge_done_irq, IORESOURCE_IRQ_LOWEDGE,
"charge_done", NULL);
if (ret < 0)
printk(KERN_ERR "%s: unable to register irq %d\n", __func__,
GPIO_CHARGE_DONE);
else
platform_device_register(&raumfeld_power_supply);
}
static void __init raumfeld_audio_init(void)
{
int ret;
ret = gpio_request(GPIO_CODEC_RESET, "cs4270 reset");
if (ret < 0)
pr_warn("unable to request GPIO_CODEC_RESET\n");
else
gpio_direction_output(GPIO_CODEC_RESET, 1);
ret = gpio_request(GPIO_SPDIF_RESET, "ak4104 s/pdif reset");
if (ret < 0)
pr_warn("unable to request GPIO_SPDIF_RESET\n");
else
gpio_direction_output(GPIO_SPDIF_RESET, 1);
ret = gpio_request(GPIO_MCLK_RESET, "MCLK reset");
if (ret < 0)
pr_warn("unable to request GPIO_MCLK_RESET\n");
else
gpio_direction_output(GPIO_MCLK_RESET, 1);
platform_add_devices(ARRAY_AND_SIZE(audio_regulator_devices));
}
static void __init raumfeld_common_init(void)
{
int ret;
if ((system_rev & 0xff) > 1) {
int i;
for (i = 0; i < ARRAY_SIZE(gpio_keys_button); i++)
if (!strcmp(gpio_keys_button[i].desc, "on_off button"))
gpio_keys_button[i].active_low = 1;
}
enable_irq_wake(IRQ_WAKEUP0);
pxa3xx_set_nand_info(&raumfeld_nand_info);
pxa3xx_set_i2c_power_info(NULL);
pxa_set_ohci_info(&raumfeld_ohci_info);
pxa_set_mci_info(&raumfeld_mci_platform_data);
pxa_set_i2c_info(NULL);
pxa_set_ffuart_info(NULL);
ret = gpio_request(GPIO_W2W_RESET, "Wi2Wi reset");
if (ret < 0)
pr_warn("Unable to request GPIO_W2W_RESET\n");
else
gpio_direction_output(GPIO_W2W_RESET, 0);
ret = gpio_request(GPIO_W2W_PDN, "Wi2Wi powerup");
if (ret < 0)
pr_warn("Unable to request GPIO_W2W_PDN\n");
else
gpio_direction_output(GPIO_W2W_PDN, 0);
ret = gpio_request(GPIO_SHUTDOWN_SUPPLY, "supply shutdown");
if (ret < 0)
pr_warn("Unable to request GPIO_SHUTDOWN_SUPPLY\n");
else
gpio_direction_output(GPIO_SHUTDOWN_SUPPLY, 0);
platform_add_devices(ARRAY_AND_SIZE(raumfeld_common_devices));
i2c_register_board_info(1, &raumfeld_pwri2c_board_info, 1);
}
static void __init __maybe_unused raumfeld_controller_init(void)
{
int ret;
pxa3xx_mfp_config(ARRAY_AND_SIZE(raumfeld_controller_pin_config));
gpiod_add_lookup_table(&raumfeld_rotary_gpios_table);
device_add_properties(&rotary_encoder_device.dev,
raumfeld_rotary_properties);
platform_device_register(&rotary_encoder_device);
spi_register_board_info(ARRAY_AND_SIZE(controller_spi_devices));
i2c_register_board_info(0, &raumfeld_controller_i2c_board_info, 1);
ret = gpio_request(GPIO_SHUTDOWN_BATT, "battery shutdown");
if (ret < 0)
pr_warn("Unable to request GPIO_SHUTDOWN_BATT\n");
else
gpio_direction_output(GPIO_SHUTDOWN_BATT, 0);
raumfeld_common_init();
raumfeld_power_init();
raumfeld_lcd_init();
raumfeld_w1_init();
}
static void __init __maybe_unused raumfeld_connector_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(raumfeld_connector_pin_config));
spi_register_board_info(ARRAY_AND_SIZE(connector_spi_devices));
i2c_register_board_info(0, &raumfeld_connector_i2c_board_info, 1);
platform_device_register(&smc91x_device);
raumfeld_audio_init();
raumfeld_common_init();
}
static void __init __maybe_unused raumfeld_speaker_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(raumfeld_speaker_pin_config));
spi_register_board_info(ARRAY_AND_SIZE(speaker_spi_devices));
i2c_register_board_info(0, &raumfeld_connector_i2c_board_info, 1);
platform_device_register(&smc91x_device);
gpiod_add_lookup_table(&raumfeld_rotary_gpios_table);
device_add_properties(&rotary_encoder_device.dev,
raumfeld_rotary_properties);
platform_device_register(&rotary_encoder_device);
raumfeld_audio_init();
raumfeld_common_init();
}
