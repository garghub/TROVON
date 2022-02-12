void ams_delta_latch_write(int base, int ngpio, u16 mask, u16 value)
{
int bit = 0;
u16 bitpos = 1 << bit;
for (; bit < ngpio; bit++, bitpos = bitpos << 1) {
if (!(mask & bitpos))
continue;
else
gpio_set_value(base + bit, (value & bitpos) != 0);
}
}
static int ams_delta_camera_power(struct device *dev, int power)
{
if (power)
led_trigger_event(ams_delta_camera_led_trigger, LED_FULL);
else
led_trigger_event(ams_delta_camera_led_trigger, LED_OFF);
return 0;
}
static void __init ams_delta_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(H19_1610_CAM_EXCLK);
omap_cfg_reg(J15_1610_CAM_LCLK);
omap_cfg_reg(L18_1610_CAM_VS);
omap_cfg_reg(L15_1610_CAM_HS);
omap_cfg_reg(L19_1610_CAM_D0);
omap_cfg_reg(K14_1610_CAM_D1);
omap_cfg_reg(K15_1610_CAM_D2);
omap_cfg_reg(K19_1610_CAM_D3);
omap_cfg_reg(K18_1610_CAM_D4);
omap_cfg_reg(J14_1610_CAM_D5);
omap_cfg_reg(J19_1610_CAM_D6);
omap_cfg_reg(J18_1610_CAM_D7);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
omap1_usb_init(&ams_delta_usb_config);
omap1_set_camera_info(&ams_delta_camera_platform_data);
#ifdef CONFIG_LEDS_TRIGGERS
led_trigger_register_simple("ams_delta_camera",
&ams_delta_camera_led_trigger);
#endif
gpio_led_register_device(-1, &leds_pdata);
platform_add_devices(ams_delta_devices, ARRAY_SIZE(ams_delta_devices));
ams_delta_init_fiq();
omap_writew(omap_readw(ARM_RSTCT1) | 0x0004, ARM_RSTCT1);
omapfb_set_lcd_config(&ams_delta_lcd_config);
}
static void modem_pm(struct uart_port *port, unsigned int state, unsigned old)
{
struct modem_private_data *priv = port->private_data;
int ret;
if (IS_ERR(priv->regulator))
return;
if (state == old)
return;
if (state == 0)
ret = regulator_enable(priv->regulator);
else if (old == 0)
ret = regulator_disable(priv->regulator);
else
ret = 0;
if (ret)
dev_warn(port->dev,
"ams_delta modem_pm: failed to %sable regulator: %d\n",
state ? "dis" : "en", ret);
}
static int __init late_init(void)
{
int err;
if (!machine_is_ams_delta())
return -ENODEV;
err = gpio_request_array(latch_gpios, ARRAY_SIZE(latch_gpios));
if (err) {
pr_err("Couldn't take over latch1/latch2 GPIO pins\n");
return err;
}
platform_add_devices(late_devices, ARRAY_SIZE(late_devices));
err = platform_device_register(&modem_nreset_device);
if (err) {
pr_err("Couldn't register the modem regulator device\n");
return err;
}
omap_cfg_reg(M14_1510_GPIO2);
ams_delta_modem_ports[0].irq =
gpio_to_irq(AMS_DELTA_GPIO_PIN_MODEM_IRQ);
err = gpio_request(AMS_DELTA_GPIO_PIN_MODEM_IRQ, "modem");
if (err) {
pr_err("Couldn't request gpio pin for modem\n");
return err;
}
gpio_direction_input(AMS_DELTA_GPIO_PIN_MODEM_IRQ);
modem_priv.regulator = ERR_PTR(-ENODEV);
ams_delta_latch2_write(AMS_DELTA_LATCH2_MODEM_CODEC,
AMS_DELTA_LATCH2_MODEM_CODEC);
err = platform_device_register(&ams_delta_modem_device);
if (err)
goto gpio_free;
modem_priv.regulator = regulator_get(&ams_delta_modem_device.dev,
"RESET#");
if (IS_ERR(modem_priv.regulator)) {
err = PTR_ERR(modem_priv.regulator);
goto unregister;
}
return 0;
unregister:
platform_device_unregister(&ams_delta_modem_device);
gpio_free:
gpio_free(AMS_DELTA_GPIO_PIN_MODEM_IRQ);
return err;
}
static void __init ams_delta_init_late(void)
{
omap1_init_late();
late_init();
}
static void __init ams_delta_map_io(void)
{
omap15xx_map_io();
iotable_init(ams_delta_io_desc, ARRAY_SIZE(ams_delta_io_desc));
}
