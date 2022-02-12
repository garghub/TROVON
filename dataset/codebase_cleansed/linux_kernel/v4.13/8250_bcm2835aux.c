static int bcm2835aux_serial_probe(struct platform_device *pdev)
{
struct bcm2835aux_data *data;
struct resource *res;
int ret;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&data->uart.port.lock);
data->uart.capabilities = UART_CAP_FIFO | UART_CAP_MINI;
data->uart.port.dev = &pdev->dev;
data->uart.port.regshift = 2;
data->uart.port.type = PORT_16550;
data->uart.port.iotype = UPIO_MEM;
data->uart.port.fifosize = 8;
data->uart.port.flags = UPF_SHARE_IRQ |
UPF_FIXED_PORT |
UPF_FIXED_TYPE |
UPF_SKIP_TEST;
data->clk = devm_clk_get(&pdev->dev, NULL);
ret = PTR_ERR_OR_ZERO(data->clk);
if (ret) {
dev_err(&pdev->dev, "could not get clk: %d\n", ret);
return ret;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "irq not found - %i", ret);
return ret;
}
data->uart.port.irq = ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "memory resource not found");
return -EINVAL;
}
data->uart.port.membase = devm_ioremap_resource(&pdev->dev, res);
ret = PTR_ERR_OR_ZERO(data->uart.port.membase);
if (ret)
return ret;
ret = of_alias_get_id(pdev->dev.of_node, "serial");
if (ret >= 0)
data->uart.port.line = ret;
ret = clk_prepare_enable(data->clk);
if (ret) {
dev_err(&pdev->dev, "unable to enable uart clock - %d\n",
ret);
return ret;
}
data->uart.port.uartclk = clk_get_rate(data->clk) * 2;
ret = serial8250_register_8250_port(&data->uart);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register 8250 port - %d\n",
ret);
goto dis_clk;
}
data->line = ret;
platform_set_drvdata(pdev, data);
return 0;
dis_clk:
clk_disable_unprepare(data->clk);
return ret;
}
static int bcm2835aux_serial_remove(struct platform_device *pdev)
{
struct bcm2835aux_data *data = platform_get_drvdata(pdev);
serial8250_unregister_port(data->uart.port.line);
clk_disable_unprepare(data->clk);
return 0;
}
