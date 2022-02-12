static int innovator_get_pendown_state(void)
{
return !(__raw_readb(OMAP1510_FPGA_TOUCHSCREEN) & (1 << 5));
}
static void __init innovator_init_smc91x(void)
{
if (cpu_is_omap1510()) {
__raw_writeb(__raw_readb(OMAP1510_FPGA_RST) & ~1,
OMAP1510_FPGA_RST);
udelay(750);
} else {
if (gpio_request(0, "SMC91x irq") < 0) {
printk("Error requesting gpio 0 for smc91x irq\n");
return;
}
}
}
static int mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
if (power_on)
__raw_writeb(__raw_readb(OMAP1510_FPGA_POWER) | (1 << 3),
OMAP1510_FPGA_POWER);
else
__raw_writeb(__raw_readb(OMAP1510_FPGA_POWER) & ~(1 << 3),
OMAP1510_FPGA_POWER);
return 0;
}
static void __init innovator_mmc_init(void)
{
mmc_data[0] = &mmc1_data;
omap1_init_mmc(mmc_data, OMAP15XX_NR_MMC);
}
static inline void innovator_mmc_init(void)
{
}
static void __init innovator_init(void)
{
if (cpu_is_omap1510())
omap1510_fpga_init_irq();
innovator_init_smc91x();
#ifdef CONFIG_ARCH_OMAP15XX
if (cpu_is_omap1510()) {
unsigned char reg;
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
reg = __raw_readb(OMAP1510_FPGA_POWER);
reg |= OMAP1510_FPGA_PCR_COM1_EN;
__raw_writeb(reg, OMAP1510_FPGA_POWER);
udelay(10);
reg = __raw_readb(OMAP1510_FPGA_POWER);
reg |= OMAP1510_FPGA_PCR_COM2_EN;
__raw_writeb(reg, OMAP1510_FPGA_POWER);
udelay(10);
platform_add_devices(innovator1510_devices, ARRAY_SIZE(innovator1510_devices));
spi_register_board_info(innovator1510_boardinfo,
ARRAY_SIZE(innovator1510_boardinfo));
}
#endif
#ifdef CONFIG_ARCH_OMAP16XX
if (!cpu_is_omap1510()) {
innovator1610_smc91x_resources[1].start = gpio_to_irq(0);
innovator1610_smc91x_resources[1].end = gpio_to_irq(0);
platform_add_devices(innovator1610_devices, ARRAY_SIZE(innovator1610_devices));
}
#endif
#ifdef CONFIG_ARCH_OMAP15XX
if (cpu_is_omap1510()) {
omap1_usb_init(&innovator1510_usb_config);
omapfb_set_lcd_config(&innovator1510_lcd_config);
}
#endif
#ifdef CONFIG_ARCH_OMAP16XX
if (cpu_is_omap1610()) {
omap1_usb_init(&h2_usb_config);
omapfb_set_lcd_config(&innovator1610_lcd_config);
}
#endif
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
innovator_mmc_init();
}
static void __init innovator_map_io(void)
{
#ifdef CONFIG_ARCH_OMAP15XX
omap15xx_map_io();
iotable_init(innovator1510_io_desc, ARRAY_SIZE(innovator1510_io_desc));
udelay(10);
pr_debug("Innovator FPGA Rev %d.%d Board Rev %d\n",
__raw_readb(OMAP1510_FPGA_REV_HIGH),
__raw_readb(OMAP1510_FPGA_REV_LOW),
__raw_readb(OMAP1510_FPGA_BOARD_REV));
#endif
}
