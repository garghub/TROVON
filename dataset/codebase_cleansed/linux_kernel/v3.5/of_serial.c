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
static int __devinit of_platform_serial_setup(struct platform_device *ofdev,
int type, struct uart_port *port)
{
struct resource resource;
struct device_node *np = ofdev->dev.of_node;
u32 clk, spd, prop;
int ret;
memset(port, 0, sizeof *port);
if (of_property_read_u32(np, "clock-frequency", &clk)) {
dev_warn(&ofdev->dev, "no clock-frequency property set\n");
return -ENODEV;
}
if (of_property_read_u32(np, "current-speed", &spd) == 0)
port->custom_divisor = clk / (16 * spd);
ret = of_address_to_resource(np, 0, &resource);
if (ret) {
dev_warn(&ofdev->dev, "invalid address\n");
return ret;
}
spin_lock_init(&port->lock);
port->mapbase = resource.start;
if (of_property_read_u32(np, "reg-offset", &prop) == 0)
port->mapbase += prop;
if (of_property_read_u32(np, "reg-shift", &prop) == 0)
port->regshift = prop;
port->irq = irq_of_parse_and_map(np, 0);
port->iotype = UPIO_MEM;
if (of_property_read_u32(np, "reg-io-width", &prop) == 0) {
switch (prop) {
case 1:
port->iotype = UPIO_MEM;
break;
case 4:
port->iotype = UPIO_MEM32;
break;
default:
dev_warn(&ofdev->dev, "unsupported reg-io-width (%d)\n",
prop);
return -EINVAL;
}
}
port->type = type;
port->uartclk = clk;
port->flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_IOREMAP
| UPF_FIXED_PORT | UPF_FIXED_TYPE;
port->dev = &ofdev->dev;
if (type == PORT_TEGRA)
port->handle_break = tegra_serial_handle_break;
return 0;
}
static int __devinit of_platform_serial_probe(struct platform_device *ofdev)
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
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (info == NULL)
return -ENOMEM;
port_type = (unsigned long)match->data;
ret = of_platform_serial_setup(ofdev, port_type, &port);
if (ret)
goto out;
switch (port_type) {
#ifdef CONFIG_SERIAL_8250
case PORT_8250 ... PORT_MAX_8250:
ret = serial8250_register_port(&port);
break;
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
dev_set_drvdata(&ofdev->dev, info);
return 0;
out:
kfree(info);
irq_dispose_mapping(port.irq);
return ret;
}
static int of_platform_serial_remove(struct platform_device *ofdev)
{
struct of_serial_info *info = dev_get_drvdata(&ofdev->dev);
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
kfree(info);
return 0;
}
