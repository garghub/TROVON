static void __init apollon_flash_init(void)
{
unsigned long base;
if (gpmc_cs_request(APOLLON_FLASH_CS, SZ_128K, &base) < 0) {
printk(KERN_ERR "Cannot request OneNAND GPMC CS\n");
return;
}
apollon_flash_resource[0].start = base;
apollon_flash_resource[0].end = base + SZ_128K - 1;
}
static inline void __init apollon_init_smc91x(void)
{
unsigned long base;
unsigned int rate;
struct clk *gpmc_fck;
int eth_cs;
int err;
gpmc_fck = clk_get(NULL, "gpmc_fck");
if (IS_ERR(gpmc_fck)) {
WARN_ON(1);
return;
}
clk_enable(gpmc_fck);
rate = clk_get_rate(gpmc_fck);
eth_cs = APOLLON_ETH_CS;
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG1, 0x00011200);
if (rate >= 160000000) {
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG2, 0x001f1f01);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG3, 0x00080803);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG4, 0x1c0b1c0a);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG5, 0x041f1F1F);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG6, 0x000004C4);
} else if (rate >= 130000000) {
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG2, 0x001f1f00);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG3, 0x00080802);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG4, 0x1C091C09);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG5, 0x041f1F1F);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG6, 0x000004C4);
} else {
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG2, 0x001f1f00);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG3, 0x00080802);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG4, 0x1C091C09);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG5, 0x031A1F1F);
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG6, 0x000003C2);
}
if (gpmc_cs_request(APOLLON_ETH_CS, SZ_16M, &base) < 0) {
printk(KERN_ERR "Failed to request GPMC CS for smc91x\n");
goto out;
}
apollon_smc91x_resources[0].start = base + 0x300;
apollon_smc91x_resources[0].end = base + 0x30f;
udelay(100);
omap_mux_init_gpio(APOLLON_ETHR_GPIO_IRQ, 0);
err = gpio_request_one(APOLLON_ETHR_GPIO_IRQ, GPIOF_IN, "SMC91x irq");
if (err) {
printk(KERN_ERR "Failed to request GPIO%d for smc91x IRQ\n",
APOLLON_ETHR_GPIO_IRQ);
gpmc_cs_free(APOLLON_ETH_CS);
}
out:
clk_disable(gpmc_fck);
clk_put(gpmc_fck);
}
static void __init omap_apollon_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static void __init apollon_led_init(void)
{
omap_mux_init_signal("vlynq_clk.gpio_13", 0);
omap_mux_init_signal("vlynq_rx1.gpio_14", 0);
omap_mux_init_signal("vlynq_rx0.gpio_15", 0);
gpio_request_array(apollon_gpio_leds, ARRAY_SIZE(apollon_gpio_leds));
}
static void __init apollon_usb_init(void)
{
omap_mux_init_signal("mcbsp2_clkx.gpio_12", 0);
gpio_request_one(12, GPIOF_OUT_INIT_LOW, "USB suspend");
omap2_usbfs_init(&apollon_usb_config);
}
static void __init omap_apollon_init(void)
{
u32 v;
omap2420_mux_init(board_mux, OMAP_PACKAGE_ZAC);
omap_board_config = apollon_config;
omap_board_config_size = ARRAY_SIZE(apollon_config);
apollon_init_smc91x();
apollon_led_init();
apollon_flash_init();
apollon_usb_init();
omap_mux_init_signal("sys_nirq", OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_signal("mcbsp2_dr.gpio_11", OMAP_PULL_ENA | OMAP_PULL_UP);
v = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
v |= (1 << 24);
omap_ctrl_writel(v, OMAP2_CONTROL_DEVCONF0);
platform_add_devices(apollon_devices, ARRAY_SIZE(apollon_devices));
omap_serial_init();
}
static void __init omap_apollon_map_io(void)
{
omap2_set_globals_242x();
omap242x_map_common_io();
}
