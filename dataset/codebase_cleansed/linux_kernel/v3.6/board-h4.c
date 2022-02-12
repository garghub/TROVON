static void __init board_mkp_init(void)
{
omap_mux_init_gpio(88, OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_gpio(89, OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_gpio(124, OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_signal("mcbsp2_dr.gpio_11", OMAP_PULL_ENA | OMAP_PULL_UP);
if (omap_has_menelaus()) {
omap_mux_init_signal("sdrc_a14.gpio0",
OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_signal("vlynq_rx0.gpio_15", 0);
omap_mux_init_signal("gpio_98", 0);
board_keypad_row_gpios[5] = 0;
board_keypad_col_gpios[2] = 15;
board_keypad_col_gpios[6] = 18;
} else {
omap_mux_init_signal("gpio_96", OMAP_PULL_ENA | OMAP_PULL_UP);
omap_mux_init_signal("gpio_100", 0);
omap_mux_init_signal("gpio_98", 0);
}
omap_mux_init_signal("gpio_90", 0);
omap_mux_init_signal("gpio_91", 0);
omap_mux_init_signal("gpio_36", 0);
omap_mux_init_signal("mcbsp2_clkx.gpio_12", 0);
omap_mux_init_signal("gpio_97", 0);
platform_device_register(&board_keyboard);
}
static inline void board_mkp_init(void)
{
}
static u32 get_sysboot_value(void)
{
return (omap_ctrl_readl(OMAP24XX_CONTROL_STATUS) &
(OMAP2_SYSBOOT_5_MASK | OMAP2_SYSBOOT_4_MASK |
OMAP2_SYSBOOT_3_MASK | OMAP2_SYSBOOT_2_MASK |
OMAP2_SYSBOOT_1_MASK | OMAP2_SYSBOOT_0_MASK));
}
static u32 is_gpmc_muxed(void)
{
u32 mux;
mux = get_sysboot_value();
if ((mux & 0xF) == 0xd)
return 1;
if (mux & 0x2)
return 1;
else
return 0;
}
static inline void __init h4_init_debug(void)
{
int eth_cs;
unsigned long cs_mem_base;
unsigned int muxed, rate;
struct clk *gpmc_fck;
eth_cs = H4_SMC91X_CS;
gpmc_fck = clk_get(NULL, "gpmc_fck");
if (IS_ERR(gpmc_fck)) {
WARN_ON(1);
return;
}
clk_enable(gpmc_fck);
rate = clk_get_rate(gpmc_fck);
clk_disable(gpmc_fck);
clk_put(gpmc_fck);
if (is_gpmc_muxed())
muxed = 0x200;
else
muxed = 0;
gpmc_cs_write_reg(eth_cs, GPMC_CS_CONFIG1,
0x00011000 | muxed);
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
if (gpmc_cs_request(eth_cs, SZ_16M, &cs_mem_base) < 0) {
printk(KERN_ERR "Failed to request GPMC mem for smc91x\n");
goto out;
}
udelay(100);
omap_mux_init_gpio(92, 0);
if (debug_card_init(cs_mem_base, H4_ETHR_GPIO_IRQ) < 0)
gpmc_cs_free(eth_cs);
out:
clk_disable(gpmc_fck);
clk_put(gpmc_fck);
}
static void __init h4_init_flash(void)
{
unsigned long base;
if (gpmc_cs_request(H4_FLASH_CS, SZ_64M, &base) < 0) {
printk("Can't request GPMC CS for flash\n");
return;
}
h4_flash_resource.start = base;
h4_flash_resource.end = base + SZ_64M - 1;
}
static void __init omap_h4_init(void)
{
omap2420_mux_init(board_mux, OMAP_PACKAGE_ZAF);
board_mkp_init();
h4_i2c_board_info[0].irq = gpio_to_irq(125);
i2c_register_board_info(1, h4_i2c_board_info,
ARRAY_SIZE(h4_i2c_board_info));
platform_add_devices(h4_devices, ARRAY_SIZE(h4_devices));
omap_serial_init();
omap_sdrc_init(NULL, NULL);
h4_init_flash();
omap_display_init(&h4_dss_data);
}
