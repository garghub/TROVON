static void __init coyote_init(void)
{
ixp4xx_sys_init();
coyote_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
coyote_flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + SZ_32M - 1;
*IXP4XX_EXP_CS0 |= IXP4XX_FLASH_WRITABLE;
*IXP4XX_EXP_CS1 = *IXP4XX_EXP_CS0;
if (machine_is_ixdpg425()) {
coyote_uart_data[0].membase =
(char*)(IXP4XX_UART1_BASE_VIRT + REG_OFFSET);
coyote_uart_data[0].mapbase = IXP4XX_UART1_BASE_PHYS;
coyote_uart_data[0].irq = IRQ_IXP4XX_UART1;
}
platform_add_devices(coyote_devices, ARRAY_SIZE(coyote_devices));
}
