static int mc9s08dz60_gpiochip_match(struct gpio_chip *chip, void *data)
{
return !strcmp(chip->label, data);
}
static void mx35_3ds_lcd_set_power(
struct plat_lcd_data *pd, unsigned int power)
{
struct gpio_chip *chip;
if (!gpio_is_valid(lcd_power_gpio)) {
chip = gpiochip_find(
"mc9s08dz60", mc9s08dz60_gpiochip_match);
if (chip) {
lcd_power_gpio =
chip->base + GPIO_MC9S08DZ60_LCD_ENABLE;
if (gpio_request(lcd_power_gpio, "lcd_power") < 0) {
pr_err("error: gpio already requested!\n");
lcd_power_gpio = -ENXIO;
}
} else {
pr_err("error: didn't find mc9s08dz60 gpio chip\n");
}
}
if (gpio_is_valid(lcd_power_gpio))
gpio_set_value_cansleep(lcd_power_gpio, power);
}
static int __init imx35_3ds_init_camera(void)
{
int dma, ret = -ENOMEM;
struct platform_device *pdev =
imx35_alloc_mx3_camera(&mx35_3ds_camera_pdata);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
if (!mx3_camera_base)
goto err;
dma = dma_declare_coherent_memory(&pdev->dev,
mx3_camera_base, mx3_camera_base,
MX35_3DS_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
goto err;
ret = platform_device_add(pdev);
if (ret)
err:
platform_device_put(pdev);
return ret;
}
static void __init imx35_3ds_init_mc13892(void)
{
int ret = gpio_request_one(GPIO_PMIC_INT, GPIOF_DIR_IN, "pmic irq");
if (ret) {
pr_err("failed to get pmic irq: %d\n", ret);
return;
}
mx35_3ds_i2c_mc13892.irq = gpio_to_irq(GPIO_PMIC_INT);
i2c_register_board_info(0, &mx35_3ds_i2c_mc13892, 1);
}
static int mx35_3ds_otg_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERNAL_PHY);
}
static int mx35_3ds_usbh_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_SINGLE_UNI |
MXC_EHCI_INTERNAL_PHY);
}
static int __init mx35_3ds_otg_mode(char *options)
{
if (!strcmp(options, "host"))
otg_mode_host = true;
else if (!strcmp(options, "device"))
otg_mode_host = false;
else
pr_info("otg_mode neither \"host\" nor \"device\". "
"Defaulting to device\n");
return 1;
}
static void __init mx35_3ds_init(void)
{
struct platform_device *imx35_fb_pdev;
imx35_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx35pdk_pads, ARRAY_SIZE(mx35pdk_pads));
imx35_add_fec(NULL);
imx35_add_imx2_wdt();
imx35_add_mxc_rtc();
platform_add_devices(devices, ARRAY_SIZE(devices));
imx35_add_imx_uart0(&uart_pdata);
if (otg_mode_host)
imx35_add_mxc_ehci_otg(&otg_pdata);
imx35_add_mxc_ehci_hs(&usb_host_pdata);
if (!otg_mode_host)
imx35_add_fsl_usb2_udc(&usb_otg_pdata);
imx35_add_mxc_nand(&mx35pdk_nand_board_info);
imx35_add_sdhci_esdhc_imx(0, NULL);
if (mxc_expio_init(MX35_CS5_BASE_ADDR, IMX_GPIO_NR(1, 1)))
pr_warn("Init of the debugboard failed, all "
"devices on the debugboard are unusable.\n");
imx35_add_imx_i2c0(&mx35_3ds_i2c0_data);
i2c_register_board_info(
0, i2c_devices_3ds, ARRAY_SIZE(i2c_devices_3ds));
imx35_add_ipu_core();
platform_device_register(&mx35_3ds_ov2640);
imx35_3ds_init_camera();
imx35_fb_pdev = imx35_add_mx3_sdc_fb(&mx3fb_pdata);
mx35_3ds_lcd.dev.parent = &imx35_fb_pdev->dev;
platform_device_register(&mx35_3ds_lcd);
imx35_3ds_init_mc13892();
}
static void __init mx35pdk_timer_init(void)
{
mx35_clocks_init();
}
static void __init mx35_3ds_reserve(void)
{
mx3_camera_base = arm_memblock_steal(MX35_3DS_CAMERA_BUF_SIZE,
MX35_3DS_CAMERA_BUF_SIZE);
}
