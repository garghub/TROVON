static int visstrim_camera_power(struct device *dev, int on)
{
gpio_set_value(TVP5150_PWDN, on);
return 0;
}
static int visstrim_camera_reset(struct device *dev)
{
gpio_set_value(TVP5150_RSTN, 0);
ndelay(500);
gpio_set_value(TVP5150_RSTN, 1);
return 0;
}
static void __init visstrim_analog_camera_init(void)
{
struct platform_device *pdev;
int dma;
gpio_set_value(TVP5150_PWDN, 1);
ndelay(1);
gpio_set_value(TVP5150_RSTN, 0);
ndelay(500);
gpio_set_value(TVP5150_RSTN, 1);
ndelay(200000);
pdev = imx27_add_mx2_camera(&visstrim_camera);
if (IS_ERR(pdev))
return;
dma = dma_declare_coherent_memory(&pdev->dev,
mx2_camera_base, mx2_camera_base,
MX2_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
return;
}
static void __init visstrim_reserve(void)
{
mx2_camera_base = arm_memblock_steal(3 * MX2_CAMERA_BUF_SIZE,
MX2_CAMERA_BUF_SIZE);
}
static int visstrim_m10_sdhc1_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
int ret;
ret = request_irq(gpio_to_irq(SDHC1_IRQ_GPIO), detect_irq,
IRQF_TRIGGER_FALLING, "mmc-detect", data);
return ret;
}
static void visstrim_m10_sdhc1_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(SDHC1_IRQ_GPIO), data);
}
static int otg_phy_init(struct platform_device *pdev)
{
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static void __init visstrim_coda_init(void)
{
struct platform_device *pdev;
int dma;
pdev = imx27_add_coda();
dma = dma_declare_coherent_memory(&pdev->dev,
mx2_camera_base + MX2_CAMERA_BUF_SIZE,
mx2_camera_base + MX2_CAMERA_BUF_SIZE,
MX2_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
return;
}
static void __init visstrim_deinterlace_init(void)
{
int ret = -ENOMEM;
struct platform_device *pdev = &visstrim_deinterlace;
int dma;
ret = platform_device_register(pdev);
dma = dma_declare_coherent_memory(&pdev->dev,
mx2_camera_base + 2 * MX2_CAMERA_BUF_SIZE,
mx2_camera_base + 2 * MX2_CAMERA_BUF_SIZE,
MX2_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
return;
}
static void __init visstrim_emmaprp_init(void)
{
struct platform_device *pdev;
int dma;
pdev = imx27_add_mx2_emmaprp();
if (IS_ERR(pdev))
return;
dma = dma_declare_coherent_memory(&pdev->dev,
mx2_camera_base, mx2_camera_base,
MX2_CAMERA_BUF_SIZE,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE);
if (!(dma & DMA_MEMORY_MAP))
pr_err("Failed to declare memory for emmaprp\n");
}
static void __init visstrim_m10_revision(void)
{
int exp_version = 0;
int mo_version = 0;
int ret;
ret = gpio_request_array(visstrim_m10_version_gpios,
ARRAY_SIZE(visstrim_m10_version_gpios));
if (ret) {
pr_err("Failed to request version gpios");
return;
}
exp_version |= !gpio_get_value(EXPBOARD_BIT2) << 2;
exp_version |= !gpio_get_value(EXPBOARD_BIT1) << 1;
exp_version |= !gpio_get_value(EXPBOARD_BIT0);
mo_version |= !gpio_get_value(MOTHERBOARD_BIT2) << 2;
mo_version |= !gpio_get_value(MOTHERBOARD_BIT1) << 1;
mo_version |= !gpio_get_value(MOTHERBOARD_BIT0);
system_rev = 0x27000;
system_rev |= (mo_version << MOTHERBOARD_SHIFT);
system_rev |= (exp_version << EXPBOARD_SHIFT);
}
static void __init visstrim_m10_board_init(void)
{
int ret;
int mo_version;
imx27_soc_init();
visstrim_m10_revision();
ret = mxc_gpio_setup_multiple_pins(visstrim_m10_pins,
ARRAY_SIZE(visstrim_m10_pins), "VISSTRIM_M10");
if (ret)
pr_err("Failed to setup pins (%d)\n", ret);
ret = gpio_request_array(visstrim_m10_gpios,
ARRAY_SIZE(visstrim_m10_gpios));
if (ret)
pr_err("Failed to request gpios (%d)\n", ret);
imx27_add_imx_ssi(0, &visstrim_m10_ssi_pdata);
imx27_add_imx_uart0(&uart_pdata);
imx27_add_imx_i2c(0, &visstrim_m10_i2c_data);
imx27_add_imx_i2c(1, &visstrim_m10_i2c_data);
i2c_register_board_info(0, visstrim_m10_i2c_devices,
ARRAY_SIZE(visstrim_m10_i2c_devices));
imx27_add_mxc_mmc(0, &visstrim_m10_sdhc_pdata);
imx27_add_mxc_ehci_otg(&visstrim_m10_usbotg_pdata);
imx27_add_fec(NULL);
imx_add_gpio_keys(&visstrim_gpio_keys_platform_data);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
imx_add_platform_device("mx27vis", 0, NULL, 0, &snd_mx27vis_pdata,
sizeof(snd_mx27vis_pdata));
platform_device_register_resndata(NULL, "soc-camera-pdrv", 0, NULL, 0,
&iclink_tvp5150, sizeof(iclink_tvp5150));
gpio_led_register_device(0, &visstrim_m10_led_data);
mo_version = (system_rev >> MOTHERBOARD_SHIFT) & VERSION_MASK;
if (mo_version & 0x1) {
visstrim_emmaprp_init();
gpio_set_value(TVP5150_PWDN, 1);
ndelay(1);
gpio_set_value(TVP5150_RSTN, 0);
} else {
visstrim_deinterlace_init();
visstrim_analog_camera_init();
}
visstrim_coda_init();
}
static void __init visstrim_m10_timer_init(void)
{
mx27_clocks_init((unsigned long)25000000);
}
