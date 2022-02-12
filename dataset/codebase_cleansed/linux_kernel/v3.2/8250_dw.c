static void dw8250_serial_out(struct uart_port *p, int offset, int value)
{
struct dw8250_data *d = p->private_data;
if (offset == UART_LCR)
d->last_lcr = value;
offset <<= p->regshift;
writeb(value, p->membase + offset);
}
static unsigned int dw8250_serial_in(struct uart_port *p, int offset)
{
offset <<= p->regshift;
return readb(p->membase + offset);
}
static void dw8250_serial_out32(struct uart_port *p, int offset, int value)
{
struct dw8250_data *d = p->private_data;
if (offset == UART_LCR)
d->last_lcr = value;
offset <<= p->regshift;
writel(value, p->membase + offset);
}
static unsigned int dw8250_serial_in32(struct uart_port *p, int offset)
{
offset <<= p->regshift;
return readl(p->membase + offset);
}
static int dw8250_handle_irq(struct uart_port *p)
{
struct dw8250_data *d = p->private_data;
unsigned int iir = p->serial_in(p, UART_IIR);
if (serial8250_handle_irq(p, iir)) {
return 1;
} else if ((iir & UART_IIR_BUSY) == UART_IIR_BUSY) {
(void)p->serial_in(p, UART_USR);
p->serial_out(p, d->last_lcr, UART_LCR);
return 1;
}
return 0;
}
static int __devinit dw8250_probe(struct platform_device *pdev)
{
struct uart_port port = {};
struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
struct device_node *np = pdev->dev.of_node;
u32 val;
struct dw8250_data *data;
if (!regs || !irq) {
dev_err(&pdev->dev, "no registers/irq defined\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
port.private_data = data;
spin_lock_init(&port.lock);
port.mapbase = regs->start;
port.irq = irq->start;
port.handle_irq = dw8250_handle_irq;
port.type = PORT_8250;
port.flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_IOREMAP |
UPF_FIXED_PORT | UPF_FIXED_TYPE;
port.dev = &pdev->dev;
port.iotype = UPIO_MEM;
port.serial_in = dw8250_serial_in;
port.serial_out = dw8250_serial_out;
if (!of_property_read_u32(np, "reg-io-width", &val)) {
switch (val) {
case 1:
break;
case 4:
port.iotype = UPIO_MEM32;
port.serial_in = dw8250_serial_in32;
port.serial_out = dw8250_serial_out32;
break;
default:
dev_err(&pdev->dev, "unsupported reg-io-width (%u)\n",
val);
return -EINVAL;
}
}
if (!of_property_read_u32(np, "reg-shift", &val))
port.regshift = val;
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(&pdev->dev, "no clock-frequency property set\n");
return -EINVAL;
}
port.uartclk = val;
data->line = serial8250_register_port(&port);
if (data->line < 0)
return data->line;
platform_set_drvdata(pdev, data);
return 0;
}
static int __devexit dw8250_remove(struct platform_device *pdev)
{
struct dw8250_data *data = platform_get_drvdata(pdev);
serial8250_unregister_port(data->line);
return 0;
}
static int __init dw8250_init(void)
{
return platform_driver_register(&dw8250_platform_driver);
}
static void __exit dw8250_exit(void)
{
platform_driver_unregister(&dw8250_platform_driver);
}
