void __init qnap_tsx1x_register_flash(void)
{
spi_register_board_info(qnap_tsx1x_spi_slave_info,
ARRAY_SIZE(qnap_tsx1x_spi_slave_info));
kirkwood_spi_init();
}
void qnap_tsx1x_power_off(void)
{
const unsigned divisor = ((kirkwood_tclk + (8 * 19200)) / (16 * 19200));
pr_info("%s: triggering power-off...\n", __func__);
writel(0x83, UART1_REG(LCR));
writel(divisor & 0xff, UART1_REG(DLL));
writel((divisor >> 8) & 0xff, UART1_REG(DLM));
writel(0x03, UART1_REG(LCR));
writel(0x00, UART1_REG(IER));
writel(0x00, UART1_REG(FCR));
writel(0x00, UART1_REG(MCR));
writel('A', UART1_REG(TX));
}
