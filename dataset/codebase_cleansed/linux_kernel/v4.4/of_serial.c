void tegra_serial_handle_break(struct uart_port *p)
{
unsigned int status, tmout = 10000;
do {
status = p->serial_in(p, UART_LSR);
if (status & (UART_LSR_FIFOE | UART_LSR_BRK_ERROR_BITS))
status = p->serial_in(p, UART_RX);
else
break;
if (--tmout == 0)
break;
udelay(1);
} while (1);
}
static inline void tegra_serial_handle_break(struct uart_port *port)
{
}
static int of_platform_serial_setup(struct platform_device *ofdev,
int type, struct uart_port *port,
struct of_serial_info *info)
{
struct resource resource;
struct device_node *np = ofdev->dev.of_node;
u32 clk, spd, prop;
int ret;
memset(port, 0, sizeof *port);
if (of_property_read_u32(np, "clock-frequency", &clk)) {
info->clk = devm_clk_get(&ofdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_warn(&ofdev->dev,
"clk or clock-frequency not defined\n");
return PTR_ERR(info->clk);
}
ret = clk_prepare_enable(info->clk);
if (ret < 0)
return ret;
clk = clk_get_rate(info->clk);
}
if (of_property_read_u32(np, "current-speed", &spd) == 0)
port->custom_divisor = clk / (16 * spd);
ret = of_address_to_resource(np, 0, &resource);
if (ret) {
dev_warn(&ofdev->dev, "invalid address\n");
goto out;
}
spin_lock_init(&port->lock);
port->mapbase = resource.start;
port->mapsize = resource_size(&resource);
if (of_property_read_u32(np, "reg-offset", &prop) == 0)
port->mapbase += prop;
if (of_property_read_u32(np, "reg-shift", &prop) == 0)
port->regshift = prop;
if (of_property_read_u32(np, "fifo-size", &prop) == 0)
port->fifosize = prop;
ret = of_alias_get_id(np, "serial");
if (ret >= 0)
port->line = ret;
port->irq = irq_of_parse_and_map(np, 0);
port->iotype = UPIO_MEM;
if (of_property_read_u32(np, "reg-io-width", &prop) == 0) {
switch (prop) {
case 1:
port->iotype = UPIO_MEM;
break;
case 4:
port->iotype = of_device_is_big_endian(np) ?
UPIO_MEM32BE : UPIO_MEM32;
break;
default:
dev_warn(&ofdev->dev, "unsupported reg-io-width (%d)\n",
prop);
ret = -EINVAL;
goto out;
}
}
port->type = type;
port->uartclk = clk;
port->flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_IOREMAP
| UPF_FIXED_PORT | UPF_FIXED_TYPE;
if (of_find_property(np, "no-loopback-test", NULL))
port->flags |= UPF_SKIP_TEST;
port->dev = &ofdev->dev;
switch (type) {
case PORT_TEGRA:
port->handle_break = tegra_serial_handle_break;
break;
case PORT_RT2880:
port->iotype = UPIO_AU;
break;
}
if (IS_ENABLED(CONFIG_SERIAL_8250_FSL) &&
(of_device_is_compatible(np, "fsl,ns16550") ||
of_device_is_compatible(np, "fsl,16550-FIFO64")))
port->handle_irq = fsl8250_handle_irq;
return 0;
out:
if (info->clk)
clk_disable_unprepare(info->clk);
return ret;
}
static int of_platform_serial_probe(struct platform_device *ofdev)
{
const struct of_device_id *match;
struct of_serial_info *info;
struct uart_port port;
int port_type;
int ret;
match = of_match_device(of_platform_serial_table, &ofdev->dev);
if (!match)
return -EINVAL;
if (of_find_property(ofdev->dev.of_node, "used-by-rtas", NULL))
return -EBUSY;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info == NULL)
return -ENOMEM;
port_type = (unsigned long)match->data;
ret = of_platform_serial_setup(ofdev, port_type, &port, info);
if (ret)
goto out;
switch (port_type) {
#ifdef CONFIG_SERIAL_8250
case PORT_8250 ... PORT_MAX_8250:
{
struct uart_8250_port port8250;
memset(&port8250, 0, sizeof(port8250));
port8250.port = port;
if (port.fifosize)
port8250.capabilities = UART_CAP_FIFO;
if (of_property_read_bool(ofdev->dev.of_node,
"auto-flow-control"))
port8250.capabilities |= UART_CAP_AFE;
ret = serial8250_register_8250_port(&port8250);
break;
}
#endif
#ifdef CONFIG_SERIAL_OF_PLATFORM_NWPSERIAL
case PORT_NWPSERIAL:
ret = nwpserial_register_port(&port);
break;
#endif
default:
case PORT_UNKNOWN:
dev_info(&ofdev->dev, "Unknown serial port found, ignored\n");
ret = -ENODEV;
break;
}
if (ret < 0)
goto out;
info->type = port_type;
info->line = ret;
platform_set_drvdata(ofdev, info);
return 0;
out:
kfree(info);
irq_dispose_mapping(port.irq);
return ret;
}
static int of_platform_serial_remove(struct platform_device *ofdev)
{
struct of_serial_info *info = platform_get_drvdata(ofdev);
switch (info->type) {
#ifdef CONFIG_SERIAL_8250
case PORT_8250 ... PORT_MAX_8250:
serial8250_unregister_port(info->line);
break;
#endif
#ifdef CONFIG_SERIAL_OF_PLATFORM_NWPSERIAL
case PORT_NWPSERIAL:
nwpserial_unregister_port(info->line);
break;
#endif
default:
break;
}
if (info->clk)
clk_disable_unprepare(info->clk);
kfree(info);
return 0;
}
static void of_serial_suspend_8250(struct of_serial_info *info)
{
struct uart_8250_port *port8250 = serial8250_get_port(info->line);
struct uart_port *port = &port8250->port;
serial8250_suspend_port(info->line);
if (info->clk && (!uart_console(port) || console_suspend_enabled))
clk_disable_unprepare(info->clk);
}
static void of_serial_resume_8250(struct of_serial_info *info)
{
struct uart_8250_port *port8250 = serial8250_get_port(info->line);
struct uart_port *port = &port8250->port;
if (info->clk && (!uart_console(port) || console_suspend_enabled))
clk_prepare_enable(info->clk);
serial8250_resume_port(info->line);
}
static inline void of_serial_suspend_8250(struct of_serial_info *info)
{
}
static inline void of_serial_resume_8250(struct of_serial_info *info)
{
}
static int of_serial_suspend(struct device *dev)
{
struct of_serial_info *info = dev_get_drvdata(dev);
switch (info->type) {
case PORT_8250 ... PORT_MAX_8250:
of_serial_suspend_8250(info);
break;
default:
break;
}
return 0;
}
static int of_serial_resume(struct device *dev)
{
struct of_serial_info *info = dev_get_drvdata(dev);
switch (info->type) {
case PORT_8250 ... PORT_MAX_8250:
of_serial_resume_8250(info);
break;
default:
break;
}
return 0;
}
