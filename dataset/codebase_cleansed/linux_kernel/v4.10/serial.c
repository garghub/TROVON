static __init int lasat_uart_add(void)
{
struct platform_device *pdev;
int retval;
pdev = platform_device_alloc("serial8250", -1);
if (!pdev)
return -ENOMEM;
if (!IS_LASAT_200()) {
lasat_serial_res[0].start = KSEG1ADDR(LASAT_UART_REGS_BASE_100);
lasat_serial_res[0].end = lasat_serial_res[0].start + LASAT_UART_REGS_SHIFT_100 * 8 - 1;
lasat_serial_res[0].flags = IORESOURCE_MEM;
lasat_serial_res[1].start = LASATINT_UART_100;
lasat_serial_res[1].end = LASATINT_UART_100;
lasat_serial_res[1].flags = IORESOURCE_IRQ;
lasat_serial8250_port[0].mapbase = LASAT_UART_REGS_BASE_100;
lasat_serial8250_port[0].uartclk = LASAT_BASE_BAUD_100 * 16;
lasat_serial8250_port[0].regshift = LASAT_UART_REGS_SHIFT_100;
lasat_serial8250_port[0].irq = LASATINT_UART_100;
} else {
lasat_serial_res[0].start = KSEG1ADDR(LASAT_UART_REGS_BASE_200);
lasat_serial_res[0].end = lasat_serial_res[0].start + LASAT_UART_REGS_SHIFT_200 * 8 - 1;
lasat_serial_res[0].flags = IORESOURCE_MEM;
lasat_serial_res[1].start = LASATINT_UART_200;
lasat_serial_res[1].end = LASATINT_UART_200;
lasat_serial_res[1].flags = IORESOURCE_IRQ;
lasat_serial8250_port[0].mapbase = LASAT_UART_REGS_BASE_200;
lasat_serial8250_port[0].uartclk = LASAT_BASE_BAUD_200 * 16;
lasat_serial8250_port[0].regshift = LASAT_UART_REGS_SHIFT_200;
lasat_serial8250_port[0].irq = LASATINT_UART_200;
}
pdev->id = PLAT8250_DEV_PLATFORM;
pdev->dev.platform_data = lasat_serial8250_port;
retval = platform_device_add_resources(pdev, lasat_serial_res, ARRAY_SIZE(lasat_serial_res));
if (retval)
goto err_free_device;
retval = platform_device_add(pdev);
if (retval)
goto err_free_device;
return 0;
err_free_device:
platform_device_put(pdev);
return retval;
}
