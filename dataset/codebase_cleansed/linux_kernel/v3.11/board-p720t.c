static void __init p720t_mmgpio_init(void __iomem *addrbase, int gpiobase)
{
p720t_mmgpio_resource[0].start = (unsigned long)addrbase;
p720t_mmgpio_pdata.base = gpiobase;
platform_device_register(&p720t_mmgpio);
}
static void p720t_lcd_power_set(struct plat_lcd_data *pd, unsigned int power)
{
if (power) {
gpio_set_value(PLD_LCDEN_EN, 1);
gpio_set_value(PLD_S1_ON, 1);
gpio_set_value(PLD_S2_ON, 1);
gpio_set_value(PLD_S4_ON, 1);
} else {
gpio_set_value(PLD_S1_ON, 0);
gpio_set_value(PLD_S2_ON, 0);
gpio_set_value(PLD_S4_ON, 0);
gpio_set_value(PLD_LCDEN_EN, 0);
}
}
static void p720t_lcd_backlight_set_intensity(int intensity)
{
gpio_set_value(PLD_S3_ON, intensity);
}
static void __init
fixup_p720t(struct tag *tag, char **cmdline, struct meminfo *mi)
{
if (tag->hdr.tag != ATAG_CORE) {
tag->hdr.tag = ATAG_CORE;
tag->hdr.size = tag_size(tag_core);
tag->u.core.flags = 0;
tag->u.core.pagesize = PAGE_SIZE;
tag->u.core.rootdev = 0x0100;
tag = tag_next(tag);
tag->hdr.tag = ATAG_MEM;
tag->hdr.size = tag_size(tag_mem32);
tag->u.mem.size = 4096;
tag->u.mem.start = PHYS_OFFSET;
tag = tag_next(tag);
tag->hdr.tag = ATAG_NONE;
tag->hdr.size = 0;
}
}
static void __init p720t_init(void)
{
int i;
clps711x_devices_init();
for (i = 0; i < ARRAY_SIZE(mmgpios); i++)
p720t_mmgpio_init(mmgpios[i].addrbase, mmgpios[i].gpiobase);
platform_device_register(&p720t_nand_pdev);
}
static void __init p720t_init_late(void)
{
WARN_ON(gpio_request_array(p720t_gpios, ARRAY_SIZE(p720t_gpios)));
platform_device_register_data(&platform_bus, "platform-lcd", 0,
&p720t_lcd_power_pdata,
sizeof(p720t_lcd_power_pdata));
platform_device_register_data(&platform_bus, "generic-bl", 0,
&p720t_lcd_backlight_pdata,
sizeof(p720t_lcd_backlight_pdata));
platform_device_register_simple("video-clps711x", 0, NULL, 0);
platform_device_register_data(&platform_bus, "leds-gpio", 0,
&p720t_gpio_led_pdata,
sizeof(p720t_gpio_led_pdata));
}
