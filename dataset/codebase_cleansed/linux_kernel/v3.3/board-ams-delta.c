void ams_delta_latch1_write(u8 mask, u8 value)
{
ams_delta_latch1_reg &= ~mask;
ams_delta_latch1_reg |= value;
*(volatile __u8 *) AMS_DELTA_LATCH1_VIRT = ams_delta_latch1_reg;
}
void ams_delta_latch2_write(u16 mask, u16 value)
{
ams_delta_latch2_reg &= ~mask;
ams_delta_latch2_reg |= value;
*(volatile __u16 *) AMS_DELTA_LATCH2_VIRT = ams_delta_latch2_reg;
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
omap_board_config = ams_delta_config;
omap_board_config_size = ARRAY_SIZE(ams_delta_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
ams_delta_latch2_write(~0, 0);
omap1_usb_init(&ams_delta_usb_config);
omap1_set_camera_info(&ams_delta_camera_platform_data);
#ifdef CONFIG_LEDS_TRIGGERS
led_trigger_register_simple("ams_delta_camera",
&ams_delta_camera_led_trigger);
#endif
platform_add_devices(ams_delta_devices, ARRAY_SIZE(ams_delta_devices));
ams_delta_init_fiq();
omap_writew(omap_readw(ARM_RSTCT1) | 0x0004, ARM_RSTCT1);
}
static int __init ams_delta_modem_init(void)
{
int err;
if (!machine_is_ams_delta())
return -ENODEV;
omap_cfg_reg(M14_1510_GPIO2);
ams_delta_modem_ports[0].irq =
gpio_to_irq(AMS_DELTA_GPIO_PIN_MODEM_IRQ);
err = gpio_request(AMS_DELTA_GPIO_PIN_MODEM_IRQ, "modem");
if (err) {
pr_err("Couldn't request gpio pin for modem\n");
return err;
}
gpio_direction_input(AMS_DELTA_GPIO_PIN_MODEM_IRQ);
ams_delta_latch2_write(
AMS_DELTA_LATCH2_MODEM_NRESET | AMS_DELTA_LATCH2_MODEM_CODEC,
AMS_DELTA_LATCH2_MODEM_NRESET | AMS_DELTA_LATCH2_MODEM_CODEC);
return platform_device_register(&ams_delta_modem_device);
}
static void __init ams_delta_map_io(void)
{
omap15xx_map_io();
iotable_init(ams_delta_io_desc, ARRAY_SIZE(ams_delta_io_desc));
}
