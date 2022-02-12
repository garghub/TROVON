void __init eseries_fixup(struct machine_desc *desc,
struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->nr_banks=1;
mi->bank[0].start = 0xa0000000;
if (machine_is_e800())
mi->bank[0].size = (128*1024*1024);
else
mi->bank[0].size = (64*1024*1024);
}
int eseries_tmio_enable(struct platform_device *dev)
{
gpio_set_value(GPIO_ESERIES_TMIO_SUSPEND, 0);
gpio_set_value(GPIO_ESERIES_TMIO_PCLR, 0);
msleep(1);
gpio_set_value(GPIO_ESERIES_TMIO_SUSPEND, 1);
msleep(1);
gpio_set_value(GPIO_ESERIES_TMIO_PCLR, 1);
msleep(1);
return 0;
}
int eseries_tmio_disable(struct platform_device *dev)
{
gpio_set_value(GPIO_ESERIES_TMIO_SUSPEND, 0);
gpio_set_value(GPIO_ESERIES_TMIO_PCLR, 0);
return 0;
}
int eseries_tmio_suspend(struct platform_device *dev)
{
gpio_set_value(GPIO_ESERIES_TMIO_SUSPEND, 0);
return 0;
}
int eseries_tmio_resume(struct platform_device *dev)
{
gpio_set_value(GPIO_ESERIES_TMIO_SUSPEND, 1);
msleep(1);
return 0;
}
void eseries_get_tmio_gpios(void)
{
gpio_request(GPIO_ESERIES_TMIO_SUSPEND, NULL);
gpio_request(GPIO_ESERIES_TMIO_PCLR, NULL);
gpio_direction_output(GPIO_ESERIES_TMIO_SUSPEND, 0);
gpio_direction_output(GPIO_ESERIES_TMIO_PCLR, 0);
}
static void clk_32k_dummy(struct clk *clk)
{
}
void eseries_register_clks(void)
{
clkdev_add_table(eseries_clkregs, ARRAY_SIZE(eseries_clkregs));
}
static void __init e330_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
eseries_register_clks();
eseries_get_tmio_gpios();
platform_add_devices(ARRAY_AND_SIZE(e330_devices));
}
static void __init e350_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
eseries_register_clks();
eseries_get_tmio_gpios();
platform_add_devices(ARRAY_AND_SIZE(e350_devices));
}
static void __init e400_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(e400_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
eseries_register_clks();
eseries_get_tmio_gpios();
pxa_set_fb_info(NULL, &e400_pxafb_mach_info);
platform_add_devices(ARRAY_AND_SIZE(e400_devices));
}
static void __init e740_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(e740_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
eseries_register_clks();
clk_add_alias("CLK_CK48M", e740_t7l66xb_device.name,
"UDCCLK", &pxa25x_device_udc.dev),
eseries_get_tmio_gpios();
platform_add_devices(ARRAY_AND_SIZE(e740_devices));
pxa_set_ac97_info(NULL);
pxa_set_ficp_info(&e7xx_ficp_platform_data);
}
static void __init e750_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(e750_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
clk_add_alias("CLK_CK3P6MI", e750_tc6393xb_device.name,
"GPIO11_CLK", NULL),
eseries_get_tmio_gpios();
platform_add_devices(ARRAY_AND_SIZE(e750_devices));
pxa_set_ac97_info(NULL);
pxa_set_ficp_info(&e7xx_ficp_platform_data);
}
static void e800_tg_change(struct w100fb_par *par)
{
unsigned long tmp;
tmp = w100fb_gpio_read(W100_GPIO_PORT_A);
if (par->mode->xres == 480)
tmp |= 0x100;
else
tmp &= ~0x100;
w100fb_gpio_write(W100_GPIO_PORT_A, tmp);
}
static void __init e800_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(e800_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
clk_add_alias("CLK_CK3P6MI", e800_tc6393xb_device.name,
"GPIO11_CLK", NULL),
eseries_get_tmio_gpios();
platform_add_devices(ARRAY_AND_SIZE(e800_devices));
pxa_set_ac97_info(NULL);
}
