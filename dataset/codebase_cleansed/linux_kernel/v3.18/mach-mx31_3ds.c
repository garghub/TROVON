static int __init mx31_3ds_init_camera(void)
{
int dma, ret = -ENOMEM;
struct platform_device *pdev =
imx31_alloc_mx3_camera(&mx31_3ds_camera_pdata);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
if (!mx3_camera_base)
goto err;
dma = dma_declare_coherent_memory(&pdev->dev,
mx3_camera_base, mx3_camera_base,
MX31_3DS_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
goto err;
ret = platform_device_add(pdev);
if (ret)
err:
platform_device_put(pdev);
return ret;
}
static int mx31_3ds_camera_power(struct device *dev, int on)
{
pr_debug("%s: %s the camera\n", __func__, on ? "ENABLE" : "DISABLE");
gpio_set_value(MX31_3DS_GPIO_CAMERA_PW, on ? 0 : 1);
if (!on)
goto out;
gpio_set_value(MX31_3DS_GPIO_CAMERA_RST, 0);
msleep(20);
gpio_set_value(MX31_3DS_GPIO_CAMERA_RST, 1);
msleep(100);
out:
return 0;
}
static int mx31_3ds_sdhc1_init(struct device *dev,
irq_handler_t detect_irq,
void *data)
{
int ret;
ret = gpio_request_array(mx31_3ds_sdhc1_gpios,
ARRAY_SIZE(mx31_3ds_sdhc1_gpios));
if (ret) {
pr_warn("Unable to request the SD/MMC GPIOs.\n");
return ret;
}
ret = request_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1)),
detect_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"sdhc1-detect", data);
if (ret) {
pr_warn("Unable to request the SD/MMC card-detect IRQ.\n");
goto gpio_free;
}
return 0;
gpio_free:
gpio_free_array(mx31_3ds_sdhc1_gpios,
ARRAY_SIZE(mx31_3ds_sdhc1_gpios));
return ret;
}
static void mx31_3ds_sdhc1_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO3_1)), data);
gpio_free_array(mx31_3ds_sdhc1_gpios,
ARRAY_SIZE(mx31_3ds_sdhc1_gpios));
}
static void mx31_3ds_sdhc1_setpower(struct device *dev, unsigned int vdd)
{
if (vdd > 7)
gpio_set_value(MX31_3DS_GPIO_SDHC1_BE, 1);
else
gpio_set_value(MX31_3DS_GPIO_SDHC1_BE, 0);
}
static int mx31_3ds_usbotg_init(void)
{
int err;
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA3, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA4, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA5, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA6, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA7, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_CLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DIR, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_NXT, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_STP, USB_PAD_CFG);
err = gpio_request(USBOTG_RST_B, "otgusb-reset");
if (err) {
pr_err("Failed to request the USB OTG reset gpio\n");
return err;
}
err = gpio_direction_output(USBOTG_RST_B, 0);
if (err) {
pr_err("Failed to drive the USB OTG reset gpio\n");
goto usbotg_free_reset;
}
mdelay(1);
gpio_set_value(USBOTG_RST_B, 1);
return 0;
usbotg_free_reset:
gpio_free(USBOTG_RST_B);
return err;
}
static int mx31_3ds_otg_init(struct platform_device *pdev)
{
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static int mx31_3ds_host2_init(struct platform_device *pdev)
{
int err;
mxc_iomux_set_pad(MX31_PIN_USBH2_CLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DIR, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_NXT, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_STP, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_PC_VS2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_PC_BVD1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_PC_BVD2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_PC_RST, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_IOIS16, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_PC_RW_B, USB_PAD_CFG);
err = gpio_request(USBH2_RST_B, "usbh2-reset");
if (err) {
pr_err("Failed to request the USB Host 2 reset gpio\n");
return err;
}
err = gpio_direction_output(USBH2_RST_B, 0);
if (err) {
pr_err("Failed to drive the USB Host 2 reset gpio\n");
goto usbotg_free_reset;
}
mdelay(1);
gpio_set_value(USBH2_RST_B, 1);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
usbotg_free_reset:
gpio_free(USBH2_RST_B);
return err;
}
static int __init mx31_3ds_otg_mode(char *options)
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
static void __init mx31_3ds_init(void)
{
int ret;
imx31_soc_init();
mxc_iomux_set_gpr(MUX_PGP_CSPI_BB, true);
mxc_iomux_setup_multiple_pins(mx31_3ds_pins, ARRAY_SIZE(mx31_3ds_pins),
"mx31_3ds");
imx31_add_imx_uart0(&uart_pdata);
imx31_add_mxc_nand(&mx31_3ds_nand_board_info);
imx31_add_spi_imx1(&spi1_pdata);
mx31_3ds_spi_devs[0].irq = gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_3));
spi_register_board_info(mx31_3ds_spi_devs,
ARRAY_SIZE(mx31_3ds_spi_devs));
platform_add_devices(devices, ARRAY_SIZE(devices));
imx31_add_imx_keypad(&mx31_3ds_keymap_data);
mx31_3ds_usbotg_init();
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
imx31_add_fsl_usb2_udc(&usbotg_pdata);
if (mxc_expio_init(MX31_CS5_BASE_ADDR, IOMUX_TO_GPIO(MX31_PIN_GPIO1_1)))
printk(KERN_WARNING "Init of the debug board failed, all "
"devices on the debug board are unusable.\n");
imx31_add_imx2_wdt();
imx31_add_imx_i2c0(&mx31_3ds_i2c0_data);
imx31_add_mxc_mmc(0, &sdhc1_pdata);
imx31_add_spi_imx0(&spi0_pdata);
imx31_add_ipu_core();
imx31_add_mx3_sdc_fb(&mx3fb_pdata);
ret = gpio_request_array(mx31_3ds_camera_gpios,
ARRAY_SIZE(mx31_3ds_camera_gpios));
if (ret) {
pr_err("Failed to request camera gpios");
iclink_ov2640.power = NULL;
}
mx31_3ds_init_camera();
imx31_add_imx_ssi(0, &mx31_3ds_ssi_pdata);
imx_add_platform_device("imx_mc13783", 0, NULL, 0, NULL, 0);
}
static void __init mx31_3ds_timer_init(void)
{
mx31_clocks_init(26000000);
}
static void __init mx31_3ds_reserve(void)
{
mx3_camera_base = arm_memblock_steal(MX31_3DS_CAMERA_BUF_SIZE,
MX31_3DS_CAMERA_BUF_SIZE);
}
