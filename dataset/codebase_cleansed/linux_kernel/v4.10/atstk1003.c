static void __init atstk1003_setup_extdac(void)
{
struct clk *gclk;
struct clk *pll;
gclk = clk_get(NULL, "gclk0");
if (IS_ERR(gclk))
goto err_gclk;
pll = clk_get(NULL, "pll0");
if (IS_ERR(pll))
goto err_pll;
if (clk_set_parent(gclk, pll)) {
pr_debug("STK1000: failed to set pll0 as parent for DAC clock\n");
goto err_set_clk;
}
at32_select_periph(GPIO_PIOA_BASE, (1 << 30), GPIO_PERIPH_A, 0);
at73c213_data.dac_clk = gclk;
err_set_clk:
clk_put(pll);
err_pll:
clk_put(gclk);
err_gclk:
return;
}
static void __init atstk1003_setup_extdac(void)
{
}
void __init setup_board(void)
{
#ifdef CONFIG_BOARD_ATSTK100X_SW2_CUSTOM
at32_map_usart(0, 1, 0);
#else
at32_map_usart(1, 0, 0);
#endif
at32_map_usart(3, 2, 0);
at32_setup_serial_console(0);
}
static int __init atstk1003_init(void)
{
at32_reserve_pin(GPIO_PIOE_BASE, ATMEL_EBI_PE_DATA_ALL);
#ifdef CONFIG_BOARD_ATSTK100X_SW2_CUSTOM
at32_add_device_usart(1);
#else
at32_add_device_usart(0);
#endif
at32_add_device_usart(2);
#ifndef CONFIG_BOARD_ATSTK100X_SW1_CUSTOM
at32_add_device_spi(0, spi0_board_info, ARRAY_SIZE(spi0_board_info));
#endif
#ifdef CONFIG_BOARD_ATSTK100X_SPI1
at32_add_device_spi(1, spi1_board_info, ARRAY_SIZE(spi1_board_info));
#endif
#ifndef CONFIG_BOARD_ATSTK100X_SW2_CUSTOM
at32_add_device_mci(0, &mci0_data);
#endif
at32_add_device_usba(0, NULL);
#ifndef CONFIG_BOARD_ATSTK100X_SW3_CUSTOM
at32_add_device_ssc(0, ATMEL_SSC_TX);
#endif
atstk1000_setup_j2_leds();
atstk1003_setup_extdac();
return 0;
}
