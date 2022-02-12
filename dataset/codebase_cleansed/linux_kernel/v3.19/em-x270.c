static void __init em_x270_init_dm9000(void)
{
em_x270_dm9000_platdata.flags |= dm9000_flags;
platform_device_register(&em_x270_dm9000);
}
static inline void em_x270_init_dm9000(void) {}
static void __init em_x270_init_rtc(void)
{
platform_device_register(&em_x270_rtc);
}
static inline void em_x270_init_rtc(void) {}
static inline void nand_cs_on(void)
{
gpio_set_value(GPIO11_NAND_CS, 0);
}
static void nand_cs_off(void)
{
dsb();
gpio_set_value(GPIO11_NAND_CS, 1);
}
static void em_x270_nand_cmd_ctl(struct mtd_info *mtd, int dat,
unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
unsigned long nandaddr = (unsigned long)this->IO_ADDR_W;
dsb();
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_ALE)
nandaddr |= (1 << 3);
else
nandaddr &= ~(1 << 3);
if (ctrl & NAND_CLE)
nandaddr |= (1 << 2);
else
nandaddr &= ~(1 << 2);
if (ctrl & NAND_NCE)
nand_cs_on();
else
nand_cs_off();
}
dsb();
this->IO_ADDR_W = (void __iomem *)nandaddr;
if (dat != NAND_CMD_NONE)
writel(dat, this->IO_ADDR_W);
dsb();
}
static int em_x270_nand_device_ready(struct mtd_info *mtd)
{
dsb();
return gpio_get_value(nand_rb);
}
static void __init em_x270_init_nand(void)
{
int err;
err = gpio_request(GPIO11_NAND_CS, "NAND CS");
if (err) {
pr_warn("EM-X270: failed to request NAND CS gpio\n");
return;
}
gpio_direction_output(GPIO11_NAND_CS, 1);
err = gpio_request(nand_rb, "NAND R/B");
if (err) {
pr_warn("EM-X270: failed to request NAND R/B gpio\n");
gpio_free(GPIO11_NAND_CS);
return;
}
gpio_direction_input(nand_rb);
platform_device_register(&em_x270_nand);
}
static inline void em_x270_init_nand(void) {}
static void __init em_x270_init_nor(void)
{
platform_device_register(&em_x270_physmap_flash);
}
static inline void em_x270_init_nor(void) {}
static int em_x270_usb_hub_init(void)
{
int err;
em_x270_usb_ldo = regulator_get(NULL, "vcc usb");
if (IS_ERR(em_x270_usb_ldo))
return PTR_ERR(em_x270_usb_ldo);
err = gpio_request(GPIO9_USB_VBUS_EN, "vbus en");
if (err)
goto err_free_usb_ldo;
err = gpio_request(usb_hub_reset, "hub rst");
if (err)
goto err_free_vbus_gpio;
gpio_direction_output(usb_hub_reset, 1);
gpio_direction_output(GPIO9_USB_VBUS_EN, 0);
err = regulator_enable(em_x270_usb_ldo);
if (err)
goto err_free_rst_gpio;
gpio_set_value(usb_hub_reset, 0);
gpio_set_value(usb_hub_reset, 1);
regulator_disable(em_x270_usb_ldo);
err = regulator_enable(em_x270_usb_ldo);
if (err)
goto err_free_rst_gpio;
gpio_set_value(usb_hub_reset, 0);
gpio_set_value(GPIO9_USB_VBUS_EN, 1);
return 0;
err_free_rst_gpio:
gpio_free(usb_hub_reset);
err_free_vbus_gpio:
gpio_free(GPIO9_USB_VBUS_EN);
err_free_usb_ldo:
regulator_put(em_x270_usb_ldo);
return err;
}
static int em_x270_ohci_init(struct device *dev)
{
int err;
err = em_x270_usb_hub_init();
if (err)
pr_err("USB Hub initialization failed: %d\n", err);
UP2OCR = UP2OCR_HXS | UP2OCR_HXOE;
return 0;
}
static void em_x270_ohci_exit(struct device *dev)
{
gpio_free(usb_hub_reset);
gpio_free(GPIO9_USB_VBUS_EN);
if (!IS_ERR(em_x270_usb_ldo)) {
if (regulator_is_enabled(em_x270_usb_ldo))
regulator_disable(em_x270_usb_ldo);
regulator_put(em_x270_usb_ldo);
}
}
static void __init em_x270_init_ohci(void)
{
pxa_set_ohci_info(&em_x270_ohci_platform_data);
}
static inline void em_x270_init_ohci(void) {}
static int em_x270_mci_init(struct device *dev,
irq_handler_t em_x270_detect_int,
void *data)
{
int err;
em_x270_sdio_ldo = regulator_get(dev, "vcc sdio");
if (IS_ERR(em_x270_sdio_ldo)) {
dev_err(dev, "can't request SDIO power supply: %ld\n",
PTR_ERR(em_x270_sdio_ldo));
return PTR_ERR(em_x270_sdio_ldo);
}
err = request_irq(gpio_to_irq(mmc_cd), em_x270_detect_int,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"MMC card detect", data);
if (err) {
dev_err(dev, "can't request MMC card detect IRQ: %d\n", err);
goto err_irq;
}
if (machine_is_em_x270()) {
err = gpio_request(GPIO95_MMC_WP, "MMC WP");
if (err) {
dev_err(dev, "can't request MMC write protect: %d\n",
err);
goto err_gpio_wp;
}
gpio_direction_input(GPIO95_MMC_WP);
} else {
err = gpio_request(GPIO38_SD_PWEN, "sdio power");
if (err) {
dev_err(dev, "can't request MMC power control : %d\n",
err);
goto err_gpio_wp;
}
gpio_direction_output(GPIO38_SD_PWEN, 1);
}
return 0;
err_gpio_wp:
free_irq(gpio_to_irq(mmc_cd), data);
err_irq:
regulator_put(em_x270_sdio_ldo);
return err;
}
static int em_x270_mci_setpower(struct device *dev, unsigned int vdd)
{
struct pxamci_platform_data* p_d = dev->platform_data;
if ((1 << vdd) & p_d->ocr_mask) {
int vdd_uV = (2000 + (vdd - __ffs(MMC_VDD_20_21)) * 100) * 1000;
regulator_set_voltage(em_x270_sdio_ldo, vdd_uV, vdd_uV);
return regulator_enable(em_x270_sdio_ldo);
} else {
regulator_disable(em_x270_sdio_ldo);
}
return 0;
}
static void em_x270_mci_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(mmc_cd), data);
regulator_put(em_x270_sdio_ldo);
if (machine_is_em_x270())
gpio_free(GPIO95_MMC_WP);
else
gpio_free(GPIO38_SD_PWEN);
}
static int em_x270_mci_get_ro(struct device *dev)
{
return gpio_get_value(GPIO95_MMC_WP);
}
static void __init em_x270_init_mmc(void)
{
if (machine_is_em_x270())
em_x270_mci_platform_data.get_ro = em_x270_mci_get_ro;
pxa_set_mci_info(&em_x270_mci_platform_data);
}
static inline void em_x270_init_mmc(void) {}
static void __init em_x270_init_lcd(void)
{
pxa_set_fb_info(NULL, &em_x270_lcd);
}
static inline void em_x270_init_lcd(void) {}
static int em_x270_libertas_setup(struct spi_device *spi)
{
int err = gpio_request(GPIO115_WLAN_PWEN, "WLAN PWEN");
if (err)
return err;
err = gpio_request(GPIO19_WLAN_STRAP, "WLAN STRAP");
if (err)
goto err_free_pwen;
if (machine_is_exeda()) {
err = gpio_request(GPIO37_WLAN_RST, "WLAN RST");
if (err)
goto err_free_strap;
gpio_direction_output(GPIO37_WLAN_RST, 1);
msleep(100);
}
gpio_direction_output(GPIO19_WLAN_STRAP, 1);
msleep(100);
pxa2xx_mfp_config(ARRAY_AND_SIZE(em_x270_libertas_pin_config));
gpio_direction_output(GPIO115_WLAN_PWEN, 0);
msleep(100);
gpio_set_value(GPIO115_WLAN_PWEN, 1);
msleep(100);
spi->bits_per_word = 16;
spi_setup(spi);
return 0;
err_free_strap:
gpio_free(GPIO19_WLAN_STRAP);
err_free_pwen:
gpio_free(GPIO115_WLAN_PWEN);
return err;
}
static int em_x270_libertas_teardown(struct spi_device *spi)
{
gpio_set_value(GPIO115_WLAN_PWEN, 0);
gpio_free(GPIO115_WLAN_PWEN);
gpio_free(GPIO19_WLAN_STRAP);
if (machine_is_exeda()) {
gpio_set_value(GPIO37_WLAN_RST, 0);
gpio_free(GPIO37_WLAN_RST);
}
return 0;
}
static void __init em_x270_init_spi(void)
{
pxa2xx_set_spi_info(1, &em_x270_spi_info);
pxa2xx_set_spi_info(2, &em_x270_spi_2_info);
spi_register_board_info(ARRAY_AND_SIZE(em_x270_spi_devices));
}
static inline void em_x270_init_spi(void) {}
static void __init em_x270_init_ac97(void)
{
pxa_set_ac97_info(&em_x270_ac97_info);
}
static inline void em_x270_init_ac97(void) {}
static void __init em_x270_init_keypad(void)
{
if (machine_is_em_x270())
pxa_set_keypad_info(&em_x270_module_keypad_info);
else
pxa_set_keypad_info(&em_x270_exeda_keypad_info);
}
static inline void em_x270_init_keypad(void) {}
static void __init em_x270_init_gpio_keys(void)
{
platform_device_register(&em_x270_gpio_keys);
}
static inline void em_x270_init_gpio_keys(void) {}
static int em_x270_sensor_init(void)
{
int ret;
ret = gpio_request(cam_reset, "camera reset");
if (ret)
return ret;
gpio_direction_output(cam_reset, 0);
em_x270_camera_ldo = regulator_get(NULL, "vcc cam");
if (em_x270_camera_ldo == NULL) {
gpio_free(cam_reset);
return -ENODEV;
}
ret = regulator_enable(em_x270_camera_ldo);
if (ret) {
regulator_put(em_x270_camera_ldo);
gpio_free(cam_reset);
return ret;
}
gpio_set_value(cam_reset, 1);
return 0;
}
static int em_x270_sensor_power(struct device *dev, int on)
{
int ret;
int is_on = regulator_is_enabled(em_x270_camera_ldo);
if (on == is_on)
return 0;
gpio_set_value(cam_reset, !on);
if (on)
ret = regulator_enable(em_x270_camera_ldo);
else
ret = regulator_disable(em_x270_camera_ldo);
if (ret)
return ret;
gpio_set_value(cam_reset, on);
return 0;
}
static void __init em_x270_init_camera(void)
{
if (em_x270_sensor_init() == 0) {
pxa_set_camera_info(&em_x270_camera_platform_data);
platform_device_register(&em_x270_camera);
}
}
static inline void em_x270_init_camera(void) {}
static void __init em_x270_userspace_consumers_init(void)
{
platform_add_devices(ARRAY_AND_SIZE(em_x270_userspace_consumers));
}
static void em_x270_battery_low(void)
{
#if defined(CONFIG_APM_EMULATION)
apm_queue_event(APM_LOW_BATTERY);
#endif
}
static void em_x270_battery_critical(void)
{
#if defined(CONFIG_APM_EMULATION)
apm_queue_event(APM_CRITICAL_SUSPEND);
#endif
}
static void __init em_x270_init_da9030(void)
{
pxa27x_set_i2c_power_info(&em_x270_pwr_i2c_info);
i2c_register_board_info(1, &em_x270_i2c_pmic_info, 1);
}
static void __init em_x270_init_i2c(void)
{
pxa_set_i2c_info(&em_x270_i2c_info);
if (machine_is_exeda())
i2c_register_board_info(0, ARRAY_AND_SIZE(exeda_i2c_info));
}
static void __init em_x270_module_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(em_x270_pin_config));
mmc_cd = GPIO13_MMC_CD;
nand_rb = GPIO56_NAND_RB;
dm9000_flags = DM9000_PLATF_32BITONLY;
cam_reset = GPIO93_CAM_RESET;
usb_hub_reset = GPIO16_USB_HUB_RESET;
}
static void __init em_x270_exeda_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(exeda_pin_config));
mmc_cd = GPIO114_MMC_CD;
nand_rb = GPIO20_NAND_RB;
dm9000_flags = DM9000_PLATF_16BITONLY;
cam_reset = GPIO130_CAM_RESET;
usb_hub_reset = GPIO10_USB_HUB_RESET;
}
static void __init em_x270_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(common_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
#ifdef CONFIG_PM
pxa27x_set_pwrmode(PWRMODE_DEEPSLEEP);
#endif
if (machine_is_em_x270())
em_x270_module_init();
else if (machine_is_exeda())
em_x270_exeda_init();
else
panic("Unsupported machine: %d\n", machine_arch_type);
em_x270_init_da9030();
em_x270_init_dm9000();
em_x270_init_rtc();
em_x270_init_nand();
em_x270_init_nor();
em_x270_init_lcd();
em_x270_init_mmc();
em_x270_init_ohci();
em_x270_init_keypad();
em_x270_init_gpio_keys();
em_x270_init_ac97();
em_x270_init_spi();
em_x270_init_i2c();
em_x270_init_camera();
em_x270_userspace_consumers_init();
}
