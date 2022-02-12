void lcd_power(int on)
{
if (on)
__raw_writew(PBC_BCTRL1_LCDON, PBC_BCTRL1_SET_REG);
else
__raw_writew(PBC_BCTRL1_LCDON, PBC_BCTRL1_CLEAR_REG);
}
static int mx27ads_sdhc1_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
return request_irq(IRQ_GPIOE(21), detect_irq, IRQF_TRIGGER_RISING,
"sdhc1-card-detect", data);
}
static int mx27ads_sdhc2_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
return request_irq(IRQ_GPIOB(7), detect_irq, IRQF_TRIGGER_RISING,
"sdhc2-card-detect", data);
}
static void mx27ads_sdhc1_exit(struct device *dev, void *data)
{
free_irq(IRQ_GPIOE(21), data);
}
static void mx27ads_sdhc2_exit(struct device *dev, void *data)
{
free_irq(IRQ_GPIOB(7), data);
}
static void __init mx27ads_board_init(void)
{
imx27_soc_init();
mxc_gpio_setup_multiple_pins(mx27ads_pins, ARRAY_SIZE(mx27ads_pins),
"mx27ads");
imx27_add_imx_uart0(&uart_pdata);
imx27_add_imx_uart1(&uart_pdata);
imx27_add_imx_uart2(&uart_pdata);
imx27_add_imx_uart3(&uart_pdata);
imx27_add_imx_uart4(&uart_pdata);
imx27_add_imx_uart5(&uart_pdata);
imx27_add_mxc_nand(&mx27ads_nand_board_info);
i2c_register_board_info(1, mx27ads_i2c_devices,
ARRAY_SIZE(mx27ads_i2c_devices));
imx27_add_imx_i2c(1, &mx27ads_i2c1_data);
imx27_add_imx_fb(&mx27ads_fb_data);
imx27_add_mxc_mmc(0, &sdhc1_pdata);
imx27_add_mxc_mmc(1, &sdhc2_pdata);
imx27_add_fec(NULL);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
imx27_add_mxc_w1(NULL);
}
static void __init mx27ads_timer_init(void)
{
unsigned long fref = 26000000;
if ((__raw_readw(PBC_VERSION_REG) & CKIH_27MHZ_BIT_SET) == 0)
fref = 27000000;
mx27_clocks_init(fref);
}
static void __init mx27ads_map_io(void)
{
mx27_map_io();
iotable_init(mx27ads_io_desc, ARRAY_SIZE(mx27ads_io_desc));
}
