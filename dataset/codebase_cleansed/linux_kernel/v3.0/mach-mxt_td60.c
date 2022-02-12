static int mxt_td60_pca9557_setup(struct i2c_client *client,
unsigned gpio_base, unsigned ngpio,
void *context)
{
static int mxt_td60_gpio_value[] = {
-1, -1, -1, -1, -1, -1, -1, 1
};
int n;
for (n = 0; n < ARRAY_SIZE(mxt_td60_gpio_value); ++n) {
gpio_request(gpio_base + n, "MXT_TD60 GPIO Exp");
if (mxt_td60_gpio_value[n] < 0)
gpio_direction_input(gpio_base + n);
else
gpio_direction_output(gpio_base + n,
mxt_td60_gpio_value[n]);
gpio_export(gpio_base + n, 0);
}
return 0;
}
static int mxt_td60_sdhc1_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
return request_irq(IRQ_GPIOF(8), detect_irq, IRQF_TRIGGER_FALLING,
"sdhc1-card-detect", data);
}
static void mxt_td60_sdhc1_exit(struct device *dev, void *data)
{
free_irq(IRQ_GPIOF(8), data);
}
static void __init mxt_td60_board_init(void)
{
mxc_gpio_setup_multiple_pins(mxt_td60_pins, ARRAY_SIZE(mxt_td60_pins),
"MXT_TD60");
imx27_add_imx_uart0(&uart_pdata);
imx27_add_imx_uart1(&uart_pdata);
imx27_add_imx_uart2(&uart_pdata);
imx27_add_mxc_nand(&mxt_td60_nand_board_info);
i2c_register_board_info(0, mxt_td60_i2c_devices,
ARRAY_SIZE(mxt_td60_i2c_devices));
i2c_register_board_info(1, mxt_td60_i2c2_devices,
ARRAY_SIZE(mxt_td60_i2c2_devices));
imx27_add_imx_i2c(0, &mxt_td60_i2c0_data);
imx27_add_imx_i2c(1, &mxt_td60_i2c1_data);
imx27_add_imx_fb(&mxt_td60_fb_data);
imx27_add_mxc_mmc(0, &sdhc1_pdata);
imx27_add_fec(NULL);
}
static void __init mxt_td60_timer_init(void)
{
mx27_clocks_init(26000000);
}
