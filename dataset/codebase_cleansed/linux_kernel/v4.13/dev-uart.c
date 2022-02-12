int __init bcm63xx_uart_register(unsigned int id)
{
if (id >= ARRAY_SIZE(bcm63xx_uart_devices))
return -ENODEV;
if (id == 1 && (!BCMCPU_IS_3368() && !BCMCPU_IS_6358() &&
!BCMCPU_IS_6368()))
return -ENODEV;
if (id == 0) {
uart0_resources[0].start = bcm63xx_regset_address(RSET_UART0);
uart0_resources[0].end = uart0_resources[0].start +
RSET_UART_SIZE - 1;
uart0_resources[1].start = bcm63xx_get_irq_number(IRQ_UART0);
}
if (id == 1) {
uart1_resources[0].start = bcm63xx_regset_address(RSET_UART1);
uart1_resources[0].end = uart1_resources[0].start +
RSET_UART_SIZE - 1;
uart1_resources[1].start = bcm63xx_get_irq_number(IRQ_UART1);
}
return platform_device_register(&bcm63xx_uart_devices[id]);
}
