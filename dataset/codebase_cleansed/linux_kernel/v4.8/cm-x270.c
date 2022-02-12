static void __init cmx270_init_rtc(void)
{
platform_device_register(&cmx270_rtc_device);
}
static inline void cmx270_init_rtc(void) {}
static int cmx270_marathon_probe(struct fb_info *fb)
{
int gpio, err;
for (gpio = 58; gpio <= 77; gpio++) {
err = gpio_request(gpio, "LCD");
if (err)
return err;
gpio_direction_input(gpio);
}
pxa2xx_mfp_config(ARRAY_AND_SIZE(cmx270_marathon_on));
return 0;
}
static int cmx270_marathon_remove(struct fb_info *fb)
{
int gpio;
pxa2xx_mfp_config(ARRAY_AND_SIZE(cmx270_marathon_off));
for (gpio = 58; gpio <= 77; gpio++)
gpio_free(gpio);
return 0;
}
static void __init cmx270_init_2700G(void)
{
platform_device_register(&cmx270_2700G);
}
static inline void cmx270_init_2700G(void) {}
static void __init cmx270_init_ohci(void)
{
pxa_set_ohci_info(&cmx270_ohci_platform_data);
}
static inline void cmx270_init_ohci(void) {}
static void __init cmx270_init_mmc(void)
{
pxa_set_mci_info(&cmx270_mci_platform_data);
}
static inline void cmx270_init_mmc(void) {}
static int cm_x270_libertas_setup(struct spi_device *spi)
{
int err = gpio_request(GPIO19_WLAN_STRAP, "WLAN STRAP");
if (err)
return err;
err = gpio_request(GPIO102_WLAN_RST, "WLAN RST");
if (err)
goto err_free_strap;
err = gpio_direction_output(GPIO102_WLAN_RST, 0);
if (err)
goto err_free_strap;
msleep(100);
err = gpio_direction_output(GPIO19_WLAN_STRAP, 1);
if (err)
goto err_free_strap;
msleep(100);
pxa2xx_mfp_config(ARRAY_AND_SIZE(cm_x270_libertas_pin_config));
gpio_set_value(GPIO102_WLAN_RST, 1);
msleep(100);
spi->bits_per_word = 16;
spi_setup(spi);
return 0;
err_free_strap:
gpio_free(GPIO19_WLAN_STRAP);
return err;
}
static int cm_x270_libertas_teardown(struct spi_device *spi)
{
gpio_set_value(GPIO102_WLAN_RST, 0);
gpio_free(GPIO102_WLAN_RST);
gpio_free(GPIO19_WLAN_STRAP);
return 0;
}
static void __init cmx270_init_spi(void)
{
pxa2xx_set_spi_info(2, &cm_x270_spi_info);
spi_register_board_info(ARRAY_AND_SIZE(cm_x270_spi_devices));
}
static inline void cmx270_init_spi(void) {}
void __init cmx270_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(cmx270_pin_config));
#ifdef CONFIG_PM
pxa27x_set_pwrmode(PWRMODE_DEEPSLEEP);
#endif
cmx270_init_rtc();
cmx270_init_mmc();
cmx270_init_ohci();
cmx270_init_2700G();
cmx270_init_spi();
}
