static uint8_t early_in(struct uart_port *port, int offset)
{
return readl(port->membase + (offset << 2));
}
static void early_out(struct uart_port *port, int offset, uint8_t value)
{
writel(value, port->membase + (offset << 2));
}
static void ingenic_early_console_putc(struct uart_port *port, int c)
{
uint8_t lsr;
do {
lsr = early_in(port, UART_LSR);
} while ((lsr & UART_LSR_TEMT) == 0);
early_out(port, UART_TX, c);
}
static void ingenic_early_console_write(struct console *console,
const char *s, unsigned int count)
{
uart_console_write(&early_device->port, s, count,
ingenic_early_console_putc);
}
static void __init ingenic_early_console_setup_clock(struct earlycon_device *dev)
{
void *fdt = initial_boot_params;
const __be32 *prop;
int offset;
offset = fdt_path_offset(fdt, "/ext");
if (offset < 0)
return;
prop = fdt_getprop(fdt, offset, "clock-frequency", NULL);
if (!prop)
return;
dev->port.uartclk = be32_to_cpup(prop);
}
static int __init ingenic_early_console_setup(struct earlycon_device *dev,
const char *opt)
{
struct uart_port *port = &dev->port;
unsigned int baud, divisor;
if (!dev->port.membase)
return -ENODEV;
ingenic_early_console_setup_clock(dev);
baud = dev->baud ?: 115200;
divisor = DIV_ROUND_CLOSEST(port->uartclk, 16 * baud);
early_out(port, UART_IER, 0);
early_out(port, UART_LCR, UART_LCR_DLAB | UART_LCR_WLEN8);
early_out(port, UART_DLL, 0);
early_out(port, UART_DLM, 0);
early_out(port, UART_LCR, UART_LCR_WLEN8);
early_out(port, UART_FCR, UART_FCR_UME | UART_FCR_CLEAR_XMIT |
UART_FCR_CLEAR_RCVR | UART_FCR_ENABLE_FIFO);
early_out(port, UART_MCR, UART_MCR_RTS | UART_MCR_DTR);
early_out(port, UART_LCR, UART_LCR_DLAB | UART_LCR_WLEN8);
early_out(port, UART_DLL, divisor & 0xff);
early_out(port, UART_DLM, (divisor >> 8) & 0xff);
early_out(port, UART_LCR, UART_LCR_WLEN8);
early_device = dev;
dev->con->write = ingenic_early_console_write;
return 0;
}
static void ingenic_uart_serial_out(struct uart_port *p, int offset, int value)
{
int ier;
switch (offset) {
case UART_FCR:
value |= UART_FCR_UME;
break;
case UART_IER:
value |= (value & 0x4) << 2;
break;
case UART_MCR:
ier = p->serial_in(p, UART_IER);
if (ier & UART_IER_MSI)
value |= UART_MCR_MDCE | UART_MCR_FCM;
else
value &= ~(UART_MCR_MDCE | UART_MCR_FCM);
break;
default:
break;
}
writeb(value, p->membase + (offset << p->regshift));
}
static unsigned int ingenic_uart_serial_in(struct uart_port *p, int offset)
{
unsigned int value;
value = readb(p->membase + (offset << p->regshift));
switch (offset) {
case UART_FCR:
value &= ~UART_FCR_UME;
break;
case UART_MCR:
value &= ~(UART_MCR_MDCE | UART_MCR_FCM);
break;
default:
break;
}
return value;
}
static int ingenic_uart_probe(struct platform_device *pdev)
{
struct uart_8250_port uart = {};
struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
struct ingenic_uart_data *data;
const struct ingenic_uart_config *cdata;
const struct of_device_id *match;
int err, line;
match = of_match_device(of_match, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Error: No device match found\n");
return -ENODEV;
}
cdata = match->data;
if (!regs || !irq) {
dev_err(&pdev->dev, "no registers/irq defined\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&uart.port.lock);
uart.port.type = PORT_16550A;
uart.port.flags = UPF_SKIP_TEST | UPF_IOREMAP | UPF_FIXED_TYPE;
uart.port.iotype = UPIO_MEM;
uart.port.mapbase = regs->start;
uart.port.regshift = 2;
uart.port.serial_out = ingenic_uart_serial_out;
uart.port.serial_in = ingenic_uart_serial_in;
uart.port.irq = irq->start;
uart.port.dev = &pdev->dev;
uart.port.fifosize = cdata->fifosize;
uart.tx_loadsz = cdata->tx_loadsz;
uart.capabilities = UART_CAP_FIFO | UART_CAP_RTOIE;
line = of_alias_get_id(pdev->dev.of_node, "serial");
if (line >= 0)
uart.port.line = line;
uart.port.membase = devm_ioremap(&pdev->dev, regs->start,
resource_size(regs));
if (!uart.port.membase)
return -ENOMEM;
data->clk_module = devm_clk_get(&pdev->dev, "module");
if (IS_ERR(data->clk_module)) {
err = PTR_ERR(data->clk_module);
if (err != -EPROBE_DEFER)
dev_err(&pdev->dev,
"unable to get module clock: %d\n", err);
return err;
}
data->clk_baud = devm_clk_get(&pdev->dev, "baud");
if (IS_ERR(data->clk_baud)) {
err = PTR_ERR(data->clk_baud);
if (err != -EPROBE_DEFER)
dev_err(&pdev->dev,
"unable to get baud clock: %d\n", err);
return err;
}
err = clk_prepare_enable(data->clk_module);
if (err) {
dev_err(&pdev->dev, "could not enable module clock: %d\n", err);
goto out;
}
err = clk_prepare_enable(data->clk_baud);
if (err) {
dev_err(&pdev->dev, "could not enable baud clock: %d\n", err);
goto out_disable_moduleclk;
}
uart.port.uartclk = clk_get_rate(data->clk_baud);
data->line = serial8250_register_8250_port(&uart);
if (data->line < 0) {
err = data->line;
goto out_disable_baudclk;
}
platform_set_drvdata(pdev, data);
return 0;
out_disable_baudclk:
clk_disable_unprepare(data->clk_baud);
out_disable_moduleclk:
clk_disable_unprepare(data->clk_module);
out:
return err;
}
static int ingenic_uart_remove(struct platform_device *pdev)
{
struct ingenic_uart_data *data = platform_get_drvdata(pdev);
serial8250_unregister_port(data->line);
clk_disable_unprepare(data->clk_module);
clk_disable_unprepare(data->clk_baud);
return 0;
}
