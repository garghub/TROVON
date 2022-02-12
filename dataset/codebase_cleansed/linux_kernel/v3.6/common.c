void __init dove_map_io(void)
{
iotable_init(dove_io_desc, ARRAY_SIZE(dove_io_desc));
}
static void __init clk_init(void)
{
tclk = clk_register_fixed_rate(NULL, "tclk", NULL, CLK_IS_ROOT,
get_tclk());
orion_clkdev_init(tclk);
}
void __init dove_ehci0_init(void)
{
orion_ehci_init(DOVE_USB0_PHYS_BASE, IRQ_DOVE_USB0, EHCI_PHY_NA);
}
void __init dove_ehci1_init(void)
{
orion_ehci_1_init(DOVE_USB1_PHYS_BASE, IRQ_DOVE_USB1);
}
void __init dove_ge00_init(struct mv643xx_eth_platform_data *eth_data)
{
orion_ge00_init(eth_data, DOVE_GE00_PHYS_BASE,
IRQ_DOVE_GE00_SUM, IRQ_DOVE_GE00_ERR,
1600);
}
void __init dove_rtc_init(void)
{
orion_rtc_init(DOVE_RTC_PHYS_BASE, IRQ_DOVE_RTC);
}
void __init dove_sata_init(struct mv_sata_platform_data *sata_data)
{
orion_sata_init(sata_data, DOVE_SATA_PHYS_BASE, IRQ_DOVE_SATA);
}
void __init dove_uart0_init(void)
{
orion_uart0_init(DOVE_UART0_VIRT_BASE, DOVE_UART0_PHYS_BASE,
IRQ_DOVE_UART_0, tclk);
}
void __init dove_uart1_init(void)
{
orion_uart1_init(DOVE_UART1_VIRT_BASE, DOVE_UART1_PHYS_BASE,
IRQ_DOVE_UART_1, tclk);
}
void __init dove_uart2_init(void)
{
orion_uart2_init(DOVE_UART2_VIRT_BASE, DOVE_UART2_PHYS_BASE,
IRQ_DOVE_UART_2, tclk);
}
void __init dove_uart3_init(void)
{
orion_uart3_init(DOVE_UART3_VIRT_BASE, DOVE_UART3_PHYS_BASE,
IRQ_DOVE_UART_3, tclk);
}
void __init dove_spi0_init(void)
{
orion_spi_init(DOVE_SPI0_PHYS_BASE);
}
void __init dove_spi1_init(void)
{
orion_spi_1_init(DOVE_SPI1_PHYS_BASE);
}
void __init dove_i2c_init(void)
{
orion_i2c_init(DOVE_I2C_PHYS_BASE, IRQ_DOVE_I2C, 10);
}
void __init dove_init_early(void)
{
orion_time_set_base(TIMER_VIRT_BASE);
}
static int get_tclk(void)
{
return 166666667;
}
static void __init dove_timer_init(void)
{
orion_time_init(BRIDGE_VIRT_BASE, BRIDGE_INT_TIMER1_CLR,
IRQ_DOVE_BRIDGE, get_tclk());
}
void __init dove_xor0_init(void)
{
orion_xor0_init(DOVE_XOR0_PHYS_BASE, DOVE_XOR0_HIGH_PHYS_BASE,
IRQ_DOVE_XOR_00, IRQ_DOVE_XOR_01);
}
void __init dove_xor1_init(void)
{
orion_xor1_init(DOVE_XOR1_PHYS_BASE, DOVE_XOR1_HIGH_PHYS_BASE,
IRQ_DOVE_XOR_10, IRQ_DOVE_XOR_11);
}
void __init dove_sdio0_init(void)
{
platform_device_register(&dove_sdio0);
}
void __init dove_sdio1_init(void)
{
platform_device_register(&dove_sdio1);
}
void __init dove_init(void)
{
printk(KERN_INFO "Dove 88AP510 SoC, ");
printk(KERN_INFO "TCLK = %dMHz\n", (get_tclk() + 499999) / 1000000);
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init();
#endif
dove_setup_cpu_mbus();
clk_init();
dove_rtc_init();
dove_xor0_init();
dove_xor1_init();
}
void dove_restart(char mode, const char *cmd)
{
writel(SOFT_RESET_OUT_EN, RSTOUTn_MASK);
writel(SOFT_RESET, SYSTEM_SOFT_RESET);
while (1)
;
}
