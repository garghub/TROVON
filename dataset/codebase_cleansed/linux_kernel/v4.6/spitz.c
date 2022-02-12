static void __init spitz_scoop_init(void)
{
platform_device_register(&spitz_scoop_1_device);
if (!machine_is_akita())
platform_device_register(&spitz_scoop_2_device);
}
static void __maybe_unused spitz_card_pwr_ctrl(uint8_t enable, uint8_t new_cpr)
{
unsigned short cpr;
unsigned long flags;
if (new_cpr & 0x7) {
gpio_set_value(SPITZ_GPIO_CF_POWER, 1);
mdelay(5);
}
local_irq_save(flags);
cpr = read_scoop_reg(&spitz_scoop_1_device.dev, SCOOP_CPR);
if (enable & new_cpr)
cpr |= new_cpr;
else
cpr &= ~enable;
write_scoop_reg(&spitz_scoop_1_device.dev, SCOOP_CPR, cpr);
local_irq_restore(flags);
if (!(cpr & 0x7)) {
mdelay(1);
gpio_set_value(SPITZ_GPIO_CF_POWER, 0);
}
}
static inline void spitz_scoop_init(void) {}
static inline void spitz_card_pwr_ctrl(uint8_t enable, uint8_t new_cpr) {}
static void spitz_pcmcia_pwr(struct device *scoop, uint16_t cpr, int nr)
{
if (nr == 0)
spitz_card_pwr_ctrl(
cpr & (SCOOP_CPR_CF_3V | SCOOP_CPR_CF_XV), cpr);
else
write_scoop_reg(scoop, SCOOP_CPR, cpr);
}
static void __init spitz_pcmcia_init(void)
{
if (machine_is_akita())
spitz_pcmcia_config.num_devs = 1;
platform_scoop_config = &spitz_pcmcia_config;
}
static inline void spitz_pcmcia_init(void) {}
static void __init spitz_mkp_init(void)
{
platform_device_register(&spitz_mkp_device);
}
static inline void spitz_mkp_init(void) {}
static void __init spitz_keys_init(void)
{
platform_device_register(&spitz_gpio_keys_device);
}
static inline void spitz_keys_init(void) {}
static void __init spitz_leds_init(void)
{
platform_device_register(&spitz_led_device);
}
static inline void spitz_leds_init(void) {}
static void spitz_ads7846_wait_for_hsync(void)
{
while (gpio_get_value(SPITZ_GPIO_HSYNC))
cpu_relax();
while (!gpio_get_value(SPITZ_GPIO_HSYNC))
cpu_relax();
}
static void spitz_bl_kick_battery(void)
{
void (*kick_batt)(void);
kick_batt = symbol_get(sharpsl_battery_kick);
if (kick_batt) {
kick_batt();
symbol_put(sharpsl_battery_kick);
}
}
static void __init spitz_spi_init(void)
{
struct corgi_lcd_platform_data *lcd_data = &spitz_lcdcon_info;
if (machine_is_akita()) {
lcd_data->gpio_backlight_cont = AKITA_GPIO_BACKLIGHT_CONT;
lcd_data->gpio_backlight_on = AKITA_GPIO_BACKLIGHT_ON;
}
pxa2xx_set_spi_info(2, &spitz_spi_info);
spi_register_board_info(ARRAY_AND_SIZE(spitz_spi_devices));
}
static inline void spitz_spi_init(void) {}
static int spitz_mci_setpower(struct device *dev, unsigned int vdd)
{
struct pxamci_platform_data* p_d = dev->platform_data;
if ((1 << vdd) & p_d->ocr_mask)
spitz_card_pwr_ctrl(SCOOP_CPR_SD_3V, SCOOP_CPR_SD_3V);
else
spitz_card_pwr_ctrl(SCOOP_CPR_SD_3V, 0x0);
return 0;
}
static void __init spitz_mmc_init(void)
{
pxa_set_mci_info(&spitz_mci_platform_data);
}
static inline void spitz_mmc_init(void) {}
static int spitz_ohci_init(struct device *dev)
{
int err;
err = gpio_request(SPITZ_GPIO_USB_HOST, "USB_HOST");
if (err)
return err;
UP2OCR = UP2OCR_HXS | UP2OCR_HXOE | UP2OCR_DPPDE | UP2OCR_DMPDE;
return gpio_direction_output(SPITZ_GPIO_USB_HOST, 1);
}
static void spitz_ohci_exit(struct device *dev)
{
gpio_free(SPITZ_GPIO_USB_HOST);
}
static void __init spitz_uhc_init(void)
{
pxa_set_ohci_info(&spitz_ohci_platform_data);
}
static inline void spitz_uhc_init(void) {}
static void __init spitz_irda_init(void)
{
if (machine_is_akita())
spitz_ficp_platform_data.gpio_pwdown = AKITA_GPIO_IR_ON;
else
spitz_ficp_platform_data.gpio_pwdown = SPITZ_GPIO_IR_ON;
pxa_set_ficp_info(&spitz_ficp_platform_data);
}
static inline void spitz_irda_init(void) {}
static void __init spitz_lcd_init(void)
{
pxa_set_fb_info(NULL, &spitz_pxafb_info);
}
static inline void spitz_lcd_init(void) {}
static void __init spitz_nand_init(void)
{
if (machine_is_spitz()) {
spitz_nand_partitions[1].size = 5 * 1024 * 1024;
} else if (machine_is_akita()) {
spitz_nand_partitions[1].size = 58 * 1024 * 1024;
spitz_nand_bbt.len = 1;
spitz_nand_pdata.ecc_layout = &akita_oobinfo;
} else if (machine_is_borzoi()) {
spitz_nand_partitions[1].size = 32 * 1024 * 1024;
spitz_nand_bbt.len = 1;
spitz_nand_pdata.ecc_layout = &akita_oobinfo;
}
platform_device_register(&spitz_nand_device);
}
static inline void spitz_nand_init(void) {}
static void __init spitz_nor_init(void)
{
platform_device_register(&spitz_rom_device);
}
static inline void spitz_nor_init(void) {}
static void __init spitz_i2c_init(void)
{
int size = ARRAY_SIZE(spitz_i2c_devs);
if (!machine_is_akita())
size--;
pxa_set_i2c_info(NULL);
pxa27x_set_i2c_power_info(NULL);
i2c_register_board_info(0, spitz_i2c_devs, size);
i2c_register_board_info(1, ARRAY_AND_SIZE(spitz_pi2c_devs));
}
static inline void spitz_i2c_init(void) {}
static inline void spitz_audio_init(void)
{
platform_device_register_simple("spitz-audio", -1, NULL, 0);
}
static void spitz_poweroff(void)
{
pxa_restart(REBOOT_GPIO, NULL);
}
static void spitz_restart(enum reboot_mode mode, const char *cmd)
{
uint32_t msc0 = __raw_readl(MSC0);
if ((msc0 & 0xffff0000) == 0x7ff00000)
__raw_writel((msc0 & 0xffff) | 0x7ee00000, MSC0);
spitz_poweroff();
}
static void __init spitz_init(void)
{
init_gpio_reset(SPITZ_GPIO_ON_RESET, 1, 0);
pm_power_off = spitz_poweroff;
PMCR = 0x00;
PCFR |= PCFR_OPDE;
pxa2xx_mfp_config(ARRAY_AND_SIZE(spitz_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
spitz_spi_init();
spitz_scoop_init();
spitz_mkp_init();
spitz_keys_init();
spitz_leds_init();
spitz_mmc_init();
spitz_pcmcia_init();
spitz_irda_init();
spitz_uhc_init();
spitz_lcd_init();
spitz_nor_init();
spitz_nand_init();
spitz_i2c_init();
spitz_audio_init();
regulator_has_full_constraints();
}
static void __init spitz_fixup(struct tag *tags, char **cmdline)
{
sharpsl_save_param();
memblock_add(0xa0000000, SZ_64M);
}
