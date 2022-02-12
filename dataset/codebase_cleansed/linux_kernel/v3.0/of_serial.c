static int __devinit of_platform_serial_setup(struct platform_device *ofdev,
int type, struct uart_port *port)
{
struct resource resource;
struct device_node *np = ofdev->dev.of_node;
const __be32 *clk, *spd;
const __be32 *prop;
int ret, prop_size;
memset(port, 0, sizeof *port);
spd = of_get_property(np, "current-speed", NULL);
clk = of_get_property(np, "clock-frequency", NULL);
if (!clk) {
dev_warn(&ofdev->dev, "no clock-frequency property set\n");
return -ENODEV;
}
ret = of_address_to_resource(np, 0, &resource);
if (ret) {
dev_warn(&ofdev->dev, "invalid address\n");
return ret;
}
spin_lock_init(&port->lock);
port->mapbase = resource.start;
prop = of_get_property(np, "reg-offset", &prop_size);
if (prop && (prop_size == sizeof(u32)))
port->mapbase += be32_to_cpup(prop);
prop = of_get_property(np, "reg-shift", &prop_size);
if (prop && (prop_size == sizeof(u32)))
port->regshift = be32_to_cpup(prop);
port->irq = irq_of_parse_and_map(np, 0);
port->iotype = UPIO_MEM;
port->type = type;
port->uartclk = be32_to_cpup(clk);
port->flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_IOREMAP
| UPF_FIXED_PORT | UPF_FIXED_TYPE;
port->dev = &ofdev->dev;
if (spd)
port->custom_divisor = be32_to_cpup(clk) / (16 * (be32_to_cpup(spd)));
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
static int __init of_platform_serial_init(void)
{
return platform_driver_register(&of_platform_serial_driver);
}
static void __exit of_platform_serial_exit(void)
{
return platform_driver_unregister(&of_platform_serial_driver);
}
