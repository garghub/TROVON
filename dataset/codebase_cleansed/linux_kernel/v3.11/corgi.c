static void corgi_wait_for_hsync(void)
{
while (gpio_get_value(CORGI_GPIO_HSYNC))
cpu_relax();
while (!gpio_get_value(CORGI_GPIO_HSYNC))
cpu_relax();
}
static void corgi_bl_kick_battery(void)
{
void (*kick_batt)(void);
kick_batt = symbol_get(sharpsl_battery_kick);
if (kick_batt) {
kick_batt();
symbol_put(sharpsl_battery_kick);
}
}
static void __init corgi_init_spi(void)
{
pxa2xx_set_spi_info(1, &corgi_spi_info);
spi_register_board_info(ARRAY_AND_SIZE(corgi_spi_devices));
}
static inline void corgi_init_spi(void) {}
static void corgi_poweroff(void)
{
if (!machine_is_corgi())
gpio_set_value(CORGI_GPIO_LED_GREEN, 0);
pxa_restart(REBOOT_HARD, NULL);
}
static void corgi_restart(enum reboot_mode mode, const char *cmd)
{
if (!machine_is_corgi())
gpio_set_value(CORGI_GPIO_LED_GREEN, 1);
pxa_restart(REBOOT_HARD, cmd);
}
static void __init corgi_init(void)
{
pm_power_off = corgi_poweroff;
PCFR |= PCFR_OPDE;
pxa2xx_mfp_config(ARRAY_AND_SIZE(corgi_pin_config));
gpio_set_wake(CORGI_GPIO_KEY_INT, 1);
gpio_set_wake(CORGI_GPIO_WAKEUP, 1);
gpio_set_wake(CORGI_GPIO_AC_IN, 1);
gpio_set_wake(CORGI_GPIO_CHRG_FULL, 1);
if (!machine_is_corgi())
gpio_set_wake(CORGI_GPIO_MAIN_BAT_LOW, 1);
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
corgi_init_spi();
pxa_set_udc_info(&udc_info);
pxa_set_mci_info(&corgi_mci_platform_data);
pxa_set_ficp_info(&corgi_ficp_platform_data);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(corgi_i2c_devices));
platform_scoop_config = &corgi_pcmcia_config;
if (machine_is_husky())
sharpsl_nand_partitions[1].size = 53 * 1024 * 1024;
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init fixup_corgi(struct tag *tags, char **cmdline,
struct meminfo *mi)
{
sharpsl_save_param();
mi->nr_banks=1;
mi->bank[0].start = 0xa0000000;
if (machine_is_corgi())
mi->bank[0].size = (32*1024*1024);
else
mi->bank[0].size = (64*1024*1024);
}
