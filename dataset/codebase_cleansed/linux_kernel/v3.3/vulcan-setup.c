static void __init vulcan_init(void)
{
ixp4xx_sys_init();
vulcan_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
vulcan_flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + SZ_32M - 1;
*IXP4XX_EXP_CS0 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_STROBE_T(3) |
IXP4XX_EXP_BUS_SIZE(0xF) |
IXP4XX_EXP_BUS_BYTE_RD16 |
IXP4XX_EXP_BUS_WR_EN;
*IXP4XX_EXP_CS1 = *IXP4XX_EXP_CS0;
vulcan_sram_resource.start = IXP4XX_EXP_BUS_BASE(2);
vulcan_sram_resource.end = IXP4XX_EXP_BUS_BASE(2) + SZ_256K - 1;
*IXP4XX_EXP_CS2 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_STROBE_T(1) |
IXP4XX_EXP_BUS_HOLD_T(2) |
IXP4XX_EXP_BUS_SIZE(9) |
IXP4XX_EXP_BUS_SPLT_EN |
IXP4XX_EXP_BUS_WR_EN |
IXP4XX_EXP_BUS_BYTE_EN;
vulcan_uart_resources[2].start = IXP4XX_EXP_BUS_BASE(3);
vulcan_uart_resources[2].end = IXP4XX_EXP_BUS_BASE(3) + 16 - 1;
vulcan_uart_data[2].mapbase = vulcan_uart_resources[2].start;
vulcan_uart_data[3].mapbase = vulcan_uart_data[2].mapbase + 8;
*IXP4XX_EXP_CS3 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_STROBE_T(3) |
IXP4XX_EXP_BUS_CYCLES(IXP4XX_EXP_BUS_CYCLES_MOTOROLA)|
IXP4XX_EXP_BUS_WR_EN |
IXP4XX_EXP_BUS_BYTE_EN;
*IXP4XX_EXP_CS4 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_WR_EN |
IXP4XX_EXP_BUS_BYTE_EN;
vulcan_max6369_resource.start = IXP4XX_EXP_BUS_BASE(5);
vulcan_max6369_resource.end = IXP4XX_EXP_BUS_BASE(5);
*IXP4XX_EXP_CS5 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_WR_EN |
IXP4XX_EXP_BUS_BYTE_EN;
platform_add_devices(vulcan_devices, ARRAY_SIZE(vulcan_devices));
}
