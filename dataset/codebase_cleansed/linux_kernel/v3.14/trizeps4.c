void board_pcmcia_power(int power)
{
if (power) {
trizeps_conxs_bcr |= power;
trizeps_conxs_bcr |= ConXS_BCR_CF_RESET;
trizeps_conxs_bcr &= ~ConXS_BCR_CF_BUF_EN;
BCR_writew(trizeps_conxs_bcr);
udelay(2000);
trizeps_conxs_bcr &= ~ConXS_BCR_CF_RESET;
BCR_writew(trizeps_conxs_bcr);
udelay(2000);
} else {
trizeps_conxs_bcr |= ConXS_BCR_CF_RESET;
BCR_writew(trizeps_conxs_bcr);
udelay(1000);
trizeps_conxs_bcr &= ~0xf;
BCR_writew(trizeps_conxs_bcr);
}
pr_debug("%s: o%s 0x%x\n", __func__, power ? "n" : "ff",
trizeps_conxs_bcr);
}
static void board_backlight_power(int on)
{
if (on)
trizeps_conxs_bcr |= ConXS_BCR_L_DISP;
else
trizeps_conxs_bcr &= ~ConXS_BCR_L_DISP;
pr_debug("%s: o%s 0x%x\n", __func__, on ? "n" : "ff",
trizeps_conxs_bcr);
BCR_writew(trizeps_conxs_bcr);
}
static int trizeps4_mci_init(struct device *dev, irq_handler_t mci_detect_int,
void *data)
{
int err;
err = request_irq(TRIZEPS4_MMC_IRQ, mci_detect_int,
IRQF_TRIGGER_RISING, "MMC card detect", data);
if (err) {
printk(KERN_ERR "trizeps4_mci_init: MMC/SD: can't request"
"MMC card detect IRQ\n");
return -1;
}
return 0;
}
static void trizeps4_mci_exit(struct device *dev, void *data)
{
free_irq(TRIZEPS4_MMC_IRQ, data);
}
static int trizeps4_irda_startup(struct device *dev)
{
trizeps_conxs_ircr &= ~ConXS_IRCR_SD;
IRCR_writew(trizeps_conxs_ircr);
return 0;
}
static void trizeps4_irda_shutdown(struct device *dev)
{
trizeps_conxs_ircr |= ConXS_IRCR_SD;
IRCR_writew(trizeps_conxs_ircr);
}
static void trizeps4_irda_transceiver_mode(struct device *dev, int mode)
{
unsigned long flags;
local_irq_save(flags);
if (mode & IR_SIRMODE)
trizeps_conxs_ircr &= ~ConXS_IRCR_MODE;
else if (mode & IR_FIRMODE)
trizeps_conxs_ircr |= ConXS_IRCR_MODE;
if (mode & IR_OFF)
trizeps_conxs_ircr |= ConXS_IRCR_SD;
else
trizeps_conxs_ircr &= ~ConXS_IRCR_SD;
IRCR_writew(trizeps_conxs_ircr);
local_irq_restore(flags);
pxa2xx_transceiver_mode(dev, mode);
}
static void __init trizeps4_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(trizeps4_pin_config));
if (machine_is_trizeps4wl()) {
pxa2xx_mfp_config(ARRAY_AND_SIZE(trizeps4wl_pin_config));
platform_add_devices(trizeps4wl_devices,
ARRAY_SIZE(trizeps4wl_devices));
} else {
platform_add_devices(trizeps4_devices,
ARRAY_SIZE(trizeps4_devices));
}
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
if (0)
pxa_set_fb_info(NULL, &sharp_lcd);
else
pxa_set_fb_info(NULL, &toshiba_lcd);
pxa_set_mci_info(&trizeps4_mci_platform_data);
#ifndef STATUS_LEDS_ON_STUART_PINS
pxa_set_ficp_info(&trizeps4_ficp_platform_data);
#endif
pxa_set_ohci_info(&trizeps4_ohci_platform_data);
pxa_set_ac97_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, trizeps4_i2c_devices,
ARRAY_SIZE(trizeps4_i2c_devices));
trizeps_conxs_bcr = 0x00A0;
BCR_writew(trizeps_conxs_bcr);
board_backlight_power(1);
}
static void __init trizeps4_map_io(void)
{
pxa27x_map_io();
iotable_init(trizeps4_io_desc, ARRAY_SIZE(trizeps4_io_desc));
if ((__raw_readl(MSC0) & 0x8) && (__raw_readl(BOOT_DEF) & 0x1)) {
__machine_arch_type = MACH_TYPE_TRIZEPS4WL;
trizeps4_flash_data[0].width = 2;
} else {
__machine_arch_type = MACH_TYPE_TRIZEPS4;
trizeps4_flash_data[0].width = 4;
}
}
