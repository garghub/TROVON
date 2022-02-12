static ssize_t lpc_address_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct aspeed_vuart *vuart = dev_get_drvdata(dev);
u16 addr;
addr = (readb(vuart->regs + ASPEED_VUART_ADDRH) << 8) |
(readb(vuart->regs + ASPEED_VUART_ADDRL));
return snprintf(buf, PAGE_SIZE - 1, "0x%x\n", addr);
}
static ssize_t lpc_address_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct aspeed_vuart *vuart = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 0, &val);
if (err)
return err;
writeb(val >> 8, vuart->regs + ASPEED_VUART_ADDRH);
writeb(val >> 0, vuart->regs + ASPEED_VUART_ADDRL);
return count;
}
static ssize_t sirq_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct aspeed_vuart *vuart = dev_get_drvdata(dev);
u8 reg;
reg = readb(vuart->regs + ASPEED_VUART_GCRB);
reg &= ASPEED_VUART_GCRB_HOST_SIRQ_MASK;
reg >>= ASPEED_VUART_GCRB_HOST_SIRQ_SHIFT;
return snprintf(buf, PAGE_SIZE - 1, "%u\n", reg);
}
static ssize_t sirq_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct aspeed_vuart *vuart = dev_get_drvdata(dev);
unsigned long val;
int err;
u8 reg;
err = kstrtoul(buf, 0, &val);
if (err)
return err;
val <<= ASPEED_VUART_GCRB_HOST_SIRQ_SHIFT;
val &= ASPEED_VUART_GCRB_HOST_SIRQ_MASK;
reg = readb(vuart->regs + ASPEED_VUART_GCRB);
reg &= ~ASPEED_VUART_GCRB_HOST_SIRQ_MASK;
reg |= val;
writeb(reg, vuart->regs + ASPEED_VUART_GCRB);
return count;
}
static void aspeed_vuart_set_enabled(struct aspeed_vuart *vuart, bool enabled)
{
u8 reg = readb(vuart->regs + ASPEED_VUART_GCRA);
if (enabled)
reg |= ASPEED_VUART_GCRA_VUART_EN;
else
reg &= ~ASPEED_VUART_GCRA_VUART_EN;
writeb(reg, vuart->regs + ASPEED_VUART_GCRA);
}
static void aspeed_vuart_set_host_tx_discard(struct aspeed_vuart *vuart,
bool discard)
{
u8 reg;
reg = readb(vuart->regs + ASPEED_VUART_GCRA);
if (!discard)
reg |= ASPEED_VUART_GCRA_DISABLE_HOST_TX_DISCARD;
else
reg &= ~ASPEED_VUART_GCRA_DISABLE_HOST_TX_DISCARD;
writeb(reg, vuart->regs + ASPEED_VUART_GCRA);
}
static int aspeed_vuart_startup(struct uart_port *uart_port)
{
struct uart_8250_port *uart_8250_port = up_to_u8250p(uart_port);
struct aspeed_vuart *vuart = uart_8250_port->port.private_data;
int rc;
rc = serial8250_do_startup(uart_port);
if (rc)
return rc;
aspeed_vuart_set_host_tx_discard(vuart, false);
return 0;
}
static void aspeed_vuart_shutdown(struct uart_port *uart_port)
{
struct uart_8250_port *uart_8250_port = up_to_u8250p(uart_port);
struct aspeed_vuart *vuart = uart_8250_port->port.private_data;
aspeed_vuart_set_host_tx_discard(vuart, true);
serial8250_do_shutdown(uart_port);
}
static int aspeed_vuart_probe(struct platform_device *pdev)
{
struct uart_8250_port port;
struct aspeed_vuart *vuart;
struct device_node *np;
struct resource *res;
u32 clk, prop;
int rc;
np = pdev->dev.of_node;
vuart = devm_kzalloc(&pdev->dev, sizeof(*vuart), GFP_KERNEL);
if (!vuart)
return -ENOMEM;
vuart->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
vuart->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(vuart->regs))
return PTR_ERR(vuart->regs);
memset(&port, 0, sizeof(port));
port.port.private_data = vuart;
port.port.membase = vuart->regs;
port.port.mapbase = res->start;
port.port.mapsize = resource_size(res);
port.port.startup = aspeed_vuart_startup;
port.port.shutdown = aspeed_vuart_shutdown;
port.port.dev = &pdev->dev;
rc = sysfs_create_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
if (rc < 0)
return rc;
if (of_property_read_u32(np, "clock-frequency", &clk)) {
vuart->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(vuart->clk)) {
dev_warn(&pdev->dev,
"clk or clock-frequency not defined\n");
rc = PTR_ERR(vuart->clk);
goto err_sysfs_remove;
}
rc = clk_prepare_enable(vuart->clk);
if (rc < 0)
goto err_sysfs_remove;
clk = clk_get_rate(vuart->clk);
}
if (of_property_read_u32(np, "current-speed", &prop) == 0)
port.port.custom_divisor = clk / (16 * prop);
if (of_property_read_u32(np, "reg-offset", &prop) == 0)
port.port.mapbase += prop;
if (of_property_read_u32(np, "reg-shift", &prop) == 0)
port.port.regshift = prop;
if (of_property_read_u32(np, "fifo-size", &prop) == 0)
port.port.fifosize = prop;
rc = of_alias_get_id(np, "serial");
if (rc >= 0)
port.port.line = rc;
port.port.irq = irq_of_parse_and_map(np, 0);
port.port.irqflags = IRQF_SHARED;
port.port.iotype = UPIO_MEM;
port.port.type = PORT_16550A;
port.port.uartclk = clk;
port.port.flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF
| UPF_FIXED_PORT | UPF_FIXED_TYPE | UPF_NO_THRE_TEST;
if (of_property_read_bool(np, "no-loopback-test"))
port.port.flags |= UPF_SKIP_TEST;
if (port.port.fifosize)
port.capabilities = UART_CAP_FIFO;
if (of_property_read_bool(np, "auto-flow-control"))
port.capabilities |= UART_CAP_AFE;
rc = serial8250_register_8250_port(&port);
if (rc < 0)
goto err_clk_disable;
vuart->line = rc;
aspeed_vuart_set_enabled(vuart, true);
aspeed_vuart_set_host_tx_discard(vuart, true);
platform_set_drvdata(pdev, vuart);
return 0;
err_clk_disable:
clk_disable_unprepare(vuart->clk);
irq_dispose_mapping(port.port.irq);
err_sysfs_remove:
sysfs_remove_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
return rc;
}
static int aspeed_vuart_remove(struct platform_device *pdev)
{
struct aspeed_vuart *vuart = platform_get_drvdata(pdev);
aspeed_vuart_set_enabled(vuart, false);
serial8250_unregister_port(vuart->line);
sysfs_remove_group(&vuart->dev->kobj, &aspeed_vuart_attr_group);
clk_disable_unprepare(vuart->clk);
return 0;
}
