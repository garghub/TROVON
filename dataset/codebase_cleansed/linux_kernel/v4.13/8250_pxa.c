static int __maybe_unused serial_pxa_suspend(struct device *dev)
{
struct pxa8250_data *data = dev_get_drvdata(dev);
serial8250_suspend_port(data->line);
return 0;
}
static int __maybe_unused serial_pxa_resume(struct device *dev)
{
struct pxa8250_data *data = dev_get_drvdata(dev);
serial8250_resume_port(data->line);
return 0;
}
static void serial_pxa_dl_write(struct uart_8250_port *up, int value)
{
unsigned int dll;
serial_out(up, UART_DLL, value & 0xff);
dll = serial_in(up, UART_DLL);
WARN_ON(dll != (value & 0xff));
serial_out(up, UART_DLM, value >> 8 & 0xff);
}
static void serial_pxa_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct pxa8250_data *data = port->private_data;
if (!state)
clk_prepare_enable(data->clk);
else
clk_disable_unprepare(data->clk);
}
static int serial_pxa_probe(struct platform_device *pdev)
{
struct uart_8250_port uart = {};
struct pxa8250_data *data;
struct resource *mmres, *irqres;
int ret;
mmres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irqres = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!mmres || !irqres)
return -ENODEV;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->clk))
return PTR_ERR(data->clk);
ret = clk_prepare(data->clk);
if (ret)
return ret;
uart.port.type = PORT_XSCALE;
uart.port.iotype = UPIO_MEM32;
uart.port.mapbase = mmres->start;
uart.port.regshift = 2;
uart.port.irq = irqres->start;
uart.port.fifosize = 64;
uart.port.flags = UPF_IOREMAP | UPF_SKIP_TEST;
uart.port.dev = &pdev->dev;
uart.port.uartclk = clk_get_rate(data->clk);
uart.port.pm = serial_pxa_pm;
uart.port.private_data = data;
uart.dl_write = serial_pxa_dl_write;
ret = serial8250_register_8250_port(&uart);
if (ret < 0)
goto err_clk;
data->line = ret;
platform_set_drvdata(pdev, data);
return 0;
err_clk:
clk_unprepare(data->clk);
return ret;
}
static int serial_pxa_remove(struct platform_device *pdev)
{
struct pxa8250_data *data = platform_get_drvdata(pdev);
serial8250_unregister_port(data->line);
clk_unprepare(data->clk);
return 0;
}
static int __init early_serial_pxa_setup(struct earlycon_device *device,
const char *options)
{
struct uart_port *port = &device->port;
if (!(device->port.membase || device->port.iobase))
return -ENODEV;
port->regshift = 2;
return early_serial8250_setup(device, NULL);
}
