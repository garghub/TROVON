static int innovator_get_pendown_state(void)
{
return !(fpga_read(OMAP1510_FPGA_TOUCHSCREEN) & (1 << 5));
}
static void __init innovator_init_smc91x(void)
{
if (cpu_is_omap1510()) {
fpga_write(fpga_read(OMAP1510_FPGA_RST) & ~1,
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
fpga_write(fpga_read(OMAP1510_FPGA_POWER) | (1 << 3),
OMAP1510_FPGA_POWER);
else
fpga_write(fpga_read(OMAP1510_FPGA_POWER) & ~(1 << 3),
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
reg = fpga_read(OMAP1510_FPGA_POWER);
reg |= OMAP1510_FPGA_PCR_COM1_EN;
fpga_write(reg, OMAP1510_FPGA_POWER);
udelay(10);
reg = fpga_read(OMAP1510_FPGA_POWER);
reg |= OMAP1510_FPGA_PCR_COM2_EN;
fpga_write(reg, OMAP1510_FPGA_POWER);
udelay(10);
platform_add_devices(innovator1510_devices, ARRAY_SIZE(innovator1510_devices));
spi_register_board_info(innovator1510_boardinfo,
ARRAY_SIZE(innovator1510_boardinfo));
}
#endif
#ifdef CONFIG_ARCH_OMAP16XX
if (!cpu_is_omap1510()) {
platform_add_devices(innovator1610_devices, ARRAY_SIZE(innovator1610_devices));
}
#endif
#ifdef CONFIG_ARCH_OMAP15XX
if (cpu_is_omap1510()) {
omap1_usb_init(&innovator1510_usb_config);
innovator_config[0].data = &innovator1510_lcd_config;
}
#endif
#ifdef CONFIG_ARCH_OMAP16XX
if (cpu_is_omap1610()) {
omap1_usb_init(&h2_usb_config);
innovator_config[0].data = &innovator1610_lcd_config;
}
#endif
omap_board_config = innovator_config;
omap_board_config_size = ARRAY_SIZE(innovator_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
innovator_mmc_init();
}
static void __init innovator_map_io(void)
{
omap15xx_map_io();
iotable_init(innovator1510_io_desc, ARRAY_SIZE(innovator1510_io_desc));
udelay(10);
pr_debug("Innovator FPGA Rev %d.%d Board Rev %d\n",
fpga_read(OMAP1510_FPGA_REV_HIGH),
fpga_read(OMAP1510_FPGA_REV_LOW),
fpga_read(OMAP1510_FPGA_BOARD_REV));
}
