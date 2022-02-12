static int __init pcm037_variant_setup(char *str)
{
if (!strcmp("eet", str))
pcm037_instance = PCM037_EET;
else if (strcmp("pcm970", str))
pr_warn("Unknown pcm037 baseboard variant %s\n", str);
return 1;
}
enum pcm037_board_variant pcm037_variant(void)
{
return pcm037_instance;
}
static int pcm037_camera_power(struct device *dev, int on)
{
gpio_set_value(IOMUX_TO_GPIO(MX31_PIN_CSI_D5), !on);
return 0;
}
static int pcm970_sdhc1_get_ro(struct device *dev)
{
return gpio_get_value(IOMUX_TO_GPIO(MX31_PIN_SFS6));
}
static int pcm970_sdhc1_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
int ret;
ret = gpio_request(SDHC1_GPIO_DET, "sdhc-detect");
if (ret)
return ret;
gpio_direction_input(SDHC1_GPIO_DET);
#ifdef PCM970_SDHC_RW_SWITCH
ret = gpio_request(SDHC1_GPIO_WP, "sdhc-wp");
if (ret)
goto err_gpio_free;
gpio_direction_input(SDHC1_GPIO_WP);
#endif
ret = request_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_SCK6)), detect_irq,
IRQF_TRIGGER_FALLING, "sdhc-detect", data);
if (ret)
goto err_gpio_free_2;
return 0;
err_gpio_free_2:
#ifdef PCM970_SDHC_RW_SWITCH
gpio_free(SDHC1_GPIO_WP);
err_gpio_free:
#endif
gpio_free(SDHC1_GPIO_DET);
return ret;
}
static void pcm970_sdhc1_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_SCK6)), data);
gpio_free(SDHC1_GPIO_DET);
gpio_free(SDHC1_GPIO_WP);
}
static int __init pcm037_init_camera(void)
{
int dma, ret = -ENOMEM;
struct platform_device *pdev = imx31_alloc_mx3_camera(&camera_pdata);
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
static int pcm037_otg_init(struct platform_device *pdev)
{
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int pcm037_usbh2_init(struct platform_device *pdev)
{
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int __init pcm037_otg_mode(char *options)
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
static void __init pcm037_init(void)
{
int ret;
imx31_soc_init();
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
mxc_iomux_set_gpr(MUX_PGP_UH2, 1);
mxc_iomux_setup_multiple_pins(pcm037_pins, ARRAY_SIZE(pcm037_pins),
"pcm037");
#define H2_PAD_CFG (PAD_CTL_DRV_MAX | PAD_CTL_SRE_FAST | PAD_CTL_HYS_CMOS \
| PAD_CTL_ODE_CMOS | PAD_CTL_100K_PU)
mxc_iomux_set_pad(MX31_PIN_USBH2_CLK, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DIR, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_NXT, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_STP, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA0, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA1, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SRXD6, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_STXD6, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SFS3, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SCK3, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SRXD3, H2_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_STXD3, H2_PAD_CFG);
if (pcm037_variant() == PCM037_EET)
mxc_iomux_setup_multiple_pins(pcm037_uart1_pins,
ARRAY_SIZE(pcm037_uart1_pins), "pcm037_uart1");
else
mxc_iomux_setup_multiple_pins(pcm037_uart1_handshake_pins,
ARRAY_SIZE(pcm037_uart1_handshake_pins),
"pcm037_uart1");
platform_add_devices(devices, ARRAY_SIZE(devices));
imx31_add_imx2_wdt();
imx31_add_imx_uart0(&uart_pdata);
imx31_add_imx_uart1(&uart_pdata);
imx31_add_imx_uart2(&uart_pdata);
imx31_add_mxc_w1();
ret = gpio_request(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1), "lan9217-irq");
if (ret)
pr_warn("could not get LAN irq gpio\n");
else {
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1));
smsc911x_resources[1].start =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1));
smsc911x_resources[1].end =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1));
platform_device_register(&pcm037_eth);
}
i2c_register_board_info(1, pcm037_i2c_devices,
ARRAY_SIZE(pcm037_i2c_devices));
imx31_add_imx_i2c1(&pcm037_i2c1_data);
imx31_add_imx_i2c2(&pcm037_i2c2_data);
imx31_add_mxc_nand(&pcm037_nand_board_info);
imx31_add_mxc_mmc(0, &sdhc_pdata);
imx31_add_ipu_core();
imx31_add_mx3_sdc_fb(&mx3fb_pdata);
ret = gpio_request(IOMUX_TO_GPIO(MX31_PIN_CSI_D5), "mt9t031-power");
if (!ret)
gpio_direction_output(IOMUX_TO_GPIO(MX31_PIN_CSI_D5), 1);
else
iclink_mt9t031.power = NULL;
pcm037_init_camera();
pcm970_sja1000_resources[1].start =
gpio_to_irq(IOMUX_TO_GPIO(IOMUX_PIN(48, 105)));
pcm970_sja1000_resources[1].end =
gpio_to_irq(IOMUX_TO_GPIO(IOMUX_PIN(48, 105)));
platform_device_register(&pcm970_sja1000);
if (otg_mode_host) {
otg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (otg_pdata.otg)
imx31_add_mxc_ehci_otg(&otg_pdata);
}
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
if (!otg_mode_host)
imx31_add_fsl_usb2_udc(&otg_device_pdata);
}
static void __init pcm037_timer_init(void)
{
mx31_clocks_init(26000000);
}
static void __init pcm037_reserve(void)
{
mx3_camera_base = arm_memblock_steal(MX3_CAMERA_BUF_SIZE,
MX3_CAMERA_BUF_SIZE);
}
static void __init pcm037_init_late(void)
{
pcm037_eet_init_devices();
}
