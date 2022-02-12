static int moboard_uart0_init(struct platform_device *pdev)
{
int ret = gpio_request(IOMUX_TO_GPIO(MX31_PIN_CTS1), "uart0-cts-hack");
if (ret)
return ret;
ret = gpio_direction_output(IOMUX_TO_GPIO(MX31_PIN_CTS1), 0);
if (ret)
gpio_free(IOMUX_TO_GPIO(MX31_PIN_CTS1));
return ret;
}
static void moboard_uart0_exit(struct platform_device *pdev)
{
gpio_free(IOMUX_TO_GPIO(MX31_PIN_CTS1));
}
static int moboard_sdhc1_get_ro(struct device *dev)
{
return !gpio_get_value(SDHC1_WP);
}
static int moboard_sdhc1_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
int ret;
ret = gpio_request(SDHC1_CD, "sdhc-detect");
if (ret)
return ret;
gpio_direction_input(SDHC1_CD);
ret = gpio_request(SDHC1_WP, "sdhc-wp");
if (ret)
goto err_gpio_free;
gpio_direction_input(SDHC1_WP);
ret = request_irq(gpio_to_irq(SDHC1_CD), detect_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"sdhc1-card-detect", data);
if (ret)
goto err_gpio_free_2;
return 0;
err_gpio_free_2:
gpio_free(SDHC1_WP);
err_gpio_free:
gpio_free(SDHC1_CD);
return ret;
}
static void moboard_sdhc1_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(SDHC1_CD), data);
gpio_free(SDHC1_WP);
gpio_free(SDHC1_CD);
}
static void usb_xcvr_reset(void)
{
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA0, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA1, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA2, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA3, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA4, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA5, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA6, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA7, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBOTG_CLK, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DIR, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBOTG_NXT, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBOTG_STP, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_gpr(MUX_PGP_UH2, true);
mxc_iomux_set_pad(MX31_PIN_USBH2_CLK, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBH2_DIR, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBH2_NXT, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBH2_STP, USB_PAD_CFG | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA0, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA1, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_SRXD6, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_STXD6, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_SFS3, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_SCK3, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_SRXD3, USB_PAD_CFG | PAD_CTL_100K_PD);
mxc_iomux_set_pad(MX31_PIN_STXD3, USB_PAD_CFG | PAD_CTL_100K_PD);
gpio_request(OTG_EN_B, "usb-udc-en");
gpio_direction_output(OTG_EN_B, 0);
gpio_request(USBH2_EN_B, "usbh2-en");
gpio_direction_output(USBH2_EN_B, 0);
gpio_request(USB_RESET_B, "usb-reset");
gpio_direction_output(USB_RESET_B, 0);
mdelay(1);
gpio_set_value(USB_RESET_B, 1);
mdelay(1);
}
static int moboard_usbh2_init_hw(struct platform_device *pdev)
{
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static int __init moboard_usbh2_init(void)
{
struct platform_device *pdev;
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (!usbh2_pdata.otg)
return -ENODEV;
pdev = imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
return 0;
}
static int __init mx31moboard_init_cam(void)
{
int dma, ret = -ENOMEM;
struct platform_device *pdev;
imx31_add_ipu_core(&mx3_ipu_data);
pdev = imx31_alloc_mx3_camera(&camera_pdata);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
dma = dma_declare_coherent_memory(&pdev->dev,
mx3_camera_base, mx3_camera_base,
MX3_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
goto err;
ret = platform_device_add(pdev);
if (ret)
err:
platform_device_put(pdev);
return ret;
}
static void mx31moboard_poweroff(void)
{
struct clk *clk = clk_get_sys("imx2-wdt.0", NULL);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
mxc_iomux_mode(MX31_PIN_WATCHDOG_RST__WATCHDOG_RST);
__raw_writew(1 << 6 | 1 << 2, MX31_IO_ADDRESS(MX31_WDOG_BASE_ADDR));
}
static void __init mx31moboard_init(void)
{
imx31_soc_init();
mxc_iomux_setup_multiple_pins(moboard_pins, ARRAY_SIZE(moboard_pins),
"moboard");
platform_add_devices(devices, ARRAY_SIZE(devices));
gpio_led_register_device(-1, &mx31moboard_led_pdata);
imx31_add_imx2_wdt(NULL);
imx31_add_imx_uart0(&uart0_pdata);
imx31_add_imx_uart4(&uart4_pdata);
imx31_add_imx_i2c0(&moboard_i2c0_data);
imx31_add_imx_i2c1(&moboard_i2c1_data);
imx31_add_spi_imx1(&moboard_spi1_pdata);
imx31_add_spi_imx2(&moboard_spi2_pdata);
gpio_request(IOMUX_TO_GPIO(MX31_PIN_GPIO1_3), "pmic-irq");
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_GPIO1_3));
spi_register_board_info(moboard_spi_board_info,
ARRAY_SIZE(moboard_spi_board_info));
imx31_add_mxc_mmc(0, &sdhc1_pdata);
mx31moboard_init_cam();
usb_xcvr_reset();
moboard_usbh2_init();
imx31_add_imx_ssi(0, &moboard_ssi_pdata);
imx_add_platform_device("imx_mc13783", 0, NULL, 0, NULL, 0);
pm_power_off = mx31moboard_poweroff;
switch (mx31moboard_baseboard) {
case MX31NOBOARD:
break;
case MX31DEVBOARD:
mx31moboard_devboard_init();
break;
case MX31MARXBOT:
mx31moboard_marxbot_init();
break;
case MX31SMARTBOT:
case MX31EYEBOT:
mx31moboard_smartbot_init(mx31moboard_baseboard);
break;
default:
printk(KERN_ERR "Illegal mx31moboard_baseboard type %d\n",
mx31moboard_baseboard);
}
}
static void __init mx31moboard_timer_init(void)
{
mx31_clocks_init(26000000);
}
static void __init mx31moboard_reserve(void)
{
mx3_camera_base = arm_memblock_steal(MX3_CAMERA_BUF_SIZE,
MX3_CAMERA_BUF_SIZE);
}
