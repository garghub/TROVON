void ibmasm_register_uart(struct service_processor *sp)
{
struct uart_port uport;
void __iomem *iomem_base;
iomem_base = sp->base_address + SCOUT_COM_B_BASE;
if (0 == readl(iomem_base + UART_SCR)) {
dev_info(sp->dev, "IBM SP UART not registered, owned by service processor\n");
sp->serial_line = -1;
return;
}
memset(&uport, 0, sizeof(struct uart_port));
uport.irq = sp->irq;
uport.uartclk = 3686400;
uport.flags = UPF_SHARE_IRQ;
uport.iotype = UPIO_MEM;
uport.membase = iomem_base;
sp->serial_line = serial8250_register_port(&uport);
if (sp->serial_line < 0) {
dev_err(sp->dev, "Failed to register serial port\n");
return;
}
enable_uart_interrupts(sp->base_address);
}
void ibmasm_unregister_uart(struct service_processor *sp)
{
if (sp->serial_line < 0)
return;
disable_uart_interrupts(sp->base_address);
serial8250_unregister_port(sp->serial_line);
}
