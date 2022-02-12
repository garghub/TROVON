static int osk_tps_setup(struct i2c_client *client, void *context)
{
gpio_request(OSK_TPS_GPIO_USB_PWR_EN, "n_vbus_en");
gpio_direction_output(OSK_TPS_GPIO_USB_PWR_EN, 1);
tps65010_set_gpio_out_value(GPIO2, HIGH);
gpio_request(OSK_TPS_GPIO_LAN_RESET, "smc_reset");
gpio_direction_output(OSK_TPS_GPIO_LAN_RESET, 0);
gpio_request(OSK_TPS_GPIO_DSP_PWR_EN, "dsp_power");
gpio_direction_output(OSK_TPS_GPIO_DSP_PWR_EN, 1);
tps65010_set_led(LED1, BLINK);
tps65010_set_led(LED2, OFF);
tps65010_set_low_pwr(ON);
tps65010_config_vregs1(TPS_LDO2_ENABLE | TPS_VLDO2_3_0V
| TPS_LDO1_ENABLE);
osk5912_tps_leds.dev.parent = &client->dev;
platform_device_register(&osk5912_tps_leds);
return 0;
}
static void __init osk_init_smc91x(void)
{
u32 l;
if ((gpio_request(0, "smc_irq")) < 0) {
printk("Error requesting gpio 0 for smc91x irq\n");
return;
}
l = omap_readl(EMIFS_CCS(1));
l |= 0x3;
omap_writel(l, EMIFS_CCS(1));
}
static void __init osk_init_cf(void)
{
omap_cfg_reg(M7_1610_GPIO62);
if ((gpio_request(62, "cf_irq")) < 0) {
printk("Error requesting gpio 62 for CF irq\n");
return;
}
irq_set_irq_type(gpio_to_irq(62), IRQ_TYPE_EDGE_FALLING);
}
static int mistral_get_pendown_state(void)
{
return !gpio_get_value(4);
}
static irqreturn_t
osk_mistral_wake_interrupt(int irq, void *ignored)
{
return IRQ_HANDLED;
}
static void __init osk_mistral_init(void)
{
omap_cfg_reg(J15_1610_CAM_LCLK);
omap_cfg_reg(J18_1610_CAM_D7);
omap_cfg_reg(J19_1610_CAM_D6);
omap_cfg_reg(J14_1610_CAM_D5);
omap_cfg_reg(K18_1610_CAM_D4);
omap_cfg_reg(K19_1610_CAM_D3);
omap_cfg_reg(K15_1610_CAM_D2);
omap_cfg_reg(K14_1610_CAM_D1);
omap_cfg_reg(L19_1610_CAM_D0);
omap_cfg_reg(L18_1610_CAM_VS);
omap_cfg_reg(L15_1610_CAM_HS);
omap_cfg_reg(M19_1610_CAM_RSTZ);
omap_cfg_reg(Y15_1610_CAM_OUTCLK);
omap_cfg_reg(H19_1610_CAM_EXCLK);
omap_cfg_reg(W13_1610_CCP_CLKM);
omap_cfg_reg(Y12_1610_CCP_CLKP);
omap_cfg_reg(W14_1610_CCP_DATAP);
if (gpio_request(11, "cam_pwdn") == 0) {
omap_cfg_reg(N20_1610_GPIO11);
gpio_direction_output(11, 0);
} else
pr_debug("OSK+Mistral: CAM_PWDN is awol\n");
gpio_request(6, "ts_busy");
gpio_direction_input(6);
omap_cfg_reg(P20_1610_GPIO4);
gpio_request(4, "ts_int");
gpio_direction_input(4);
irq_set_irq_type(gpio_to_irq(4), IRQ_TYPE_EDGE_FALLING);
mistral_boardinfo[0].irq = gpio_to_irq(4);
spi_register_board_info(mistral_boardinfo,
ARRAY_SIZE(mistral_boardinfo));
omap_cfg_reg(N15_1610_MPUIO2);
if (gpio_request(OMAP_MPUIO(2), "wakeup") == 0) {
int ret = 0;
int irq = gpio_to_irq(OMAP_MPUIO(2));
gpio_direction_input(OMAP_MPUIO(2));
irq_set_irq_type(irq, IRQ_TYPE_EDGE_RISING);
#ifdef CONFIG_PM
ret = request_irq(irq,
&osk_mistral_wake_interrupt,
IRQF_SHARED, "mistral_wakeup",
&osk_mistral_wake_interrupt);
if (ret != 0) {
gpio_free(OMAP_MPUIO(2));
printk(KERN_ERR "OSK+Mistral: no wakeup irq, %d?\n",
ret);
} else
enable_irq_wake(irq);
#endif
} else
printk(KERN_ERR "OSK+Mistral: wakeup button is awol\n");
omap_cfg_reg(PWL);
if (gpio_request(2, "lcd_pwr") == 0)
gpio_direction_output(2, 1);
i2c_register_board_info(1, mistral_i2c_board_info,
ARRAY_SIZE(mistral_i2c_board_info));
platform_add_devices(mistral_devices, ARRAY_SIZE(mistral_devices));
}
static void __init osk_mistral_init(void) { }
static void __init osk_init(void)
{
u32 l;
osk_init_smc91x();
osk_init_cf();
l = omap_readl(EMIFS_CCS(3));
if (l != EMIFS_CS3_VAL)
omap_writel(EMIFS_CS3_VAL, EMIFS_CCS(3));
osk_flash_resource.end = osk_flash_resource.start = omap_cs3_phys();
osk_flash_resource.end += SZ_32M - 1;
osk5912_smc91x_resources[1].start = gpio_to_irq(0);
osk5912_smc91x_resources[1].end = gpio_to_irq(0);
osk5912_cf_resources[0].start = gpio_to_irq(62);
osk5912_cf_resources[0].end = gpio_to_irq(62);
platform_add_devices(osk5912_devices, ARRAY_SIZE(osk5912_devices));
l = omap_readl(USB_TRANSCEIVER_CTRL);
l |= (3 << 1);
omap_writel(l, USB_TRANSCEIVER_CTRL);
omap1_usb_init(&osk_usb_config);
if (gpio_request(OMAP_MPUIO(1), "tps65010") == 0)
gpio_direction_input(OMAP_MPUIO(1));
omap_serial_init();
osk_i2c_board_info[0].irq = gpio_to_irq(OMAP_MPUIO(1));
omap_register_i2c_bus(1, 400, osk_i2c_board_info,
ARRAY_SIZE(osk_i2c_board_info));
osk_mistral_init();
#ifdef CONFIG_OMAP_OSK_MISTRAL
omapfb_set_lcd_config(&osk_lcd_config);
#endif
}
