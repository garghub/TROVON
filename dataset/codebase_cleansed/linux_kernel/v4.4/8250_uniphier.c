static unsigned int uniphier_serial_in(struct uart_port *p, int offset)
{
unsigned int valshift = 0;
switch (offset) {
case UART_LCR:
valshift = UNIPHIER_UART_LCR_SHIFT;
case UART_MCR:
offset = UNIPHIER_UART_LCR_MCR;
break;
default:
break;
}
offset <<= p->regshift;
return (readl(p->membase + offset) >> valshift) & 0xff;
}
static void uniphier_serial_out(struct uart_port *p, int offset, int value)
{
unsigned int valshift = 0;
bool normal = false;
switch (offset) {
case UART_FCR:
offset = UNIPHIER_UART_CHAR_FCR;
break;
case UART_LCR:
valshift = UNIPHIER_UART_LCR_SHIFT;
value &= ~(UART_LCR_DLAB << valshift);
case UART_MCR:
offset = UNIPHIER_UART_LCR_MCR;
break;
default:
normal = true;
break;
}
offset <<= p->regshift;
if (normal) {
writel(value, p->membase + offset);
} else {
struct uniphier8250_priv *priv = p->private_data;
unsigned long flags;
u32 tmp;
spin_lock_irqsave(&priv->atomic_write_lock, flags);
tmp = readl(p->membase + offset);
tmp &= ~(0xff << valshift);
tmp |= value << valshift;
writel(tmp, p->membase + offset);
spin_unlock_irqrestore(&priv->atomic_write_lock, flags);
}
}
static int uniphier_serial_dl_read(struct uart_8250_port *up)
{
int offset = UNIPHIER_UART_DLR << up->port.regshift;
return readl(up->port.membase + offset);
}
static void uniphier_serial_dl_write(struct uart_8250_port *up, int value)
{
int offset = UNIPHIER_UART_DLR << up->port.regshift;
writel(value, up->port.membase + offset);
}
static int uniphier_of_serial_setup(struct device *dev, struct uart_port *port,
struct uniphier8250_priv *priv)
{
int ret;
u32 prop;
struct device_node *np = dev->of_node;
ret = of_alias_get_id(np, "serial");
if (ret < 0) {
dev_err(dev, "failed to get alias id\n");
return ret;
}
port->line = priv->line = ret;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret < 0)
return ret;
port->uartclk = clk_get_rate(priv->clk);
if (of_property_read_u32(np, "fifo-size", &prop) == 0)
port->fifosize = prop;
else
port->fifosize = UNIPHIER_UART_DEFAULT_FIFO_SIZE;
return 0;
}
static int uniphier_uart_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct uart_8250_port up;
struct uniphier8250_priv *priv;
struct resource *regs;
void __iomem *membase;
int irq;
int ret;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_err(dev, "failed to get memory resource");
return -EINVAL;
}
membase = devm_ioremap(dev, regs->start, resource_size(regs));
if (!membase)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to get IRQ number");
return irq;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
memset(&up, 0, sizeof(up));
ret = uniphier_of_serial_setup(dev, &up.port, priv);
if (ret < 0)
return ret;
spin_lock_init(&priv->atomic_write_lock);
up.port.dev = dev;
up.port.private_data = priv;
up.port.mapbase = regs->start;
up.port.mapsize = resource_size(regs);
up.port.membase = membase;
up.port.irq = irq;
up.port.type = PORT_16550A;
up.port.iotype = UPIO_MEM32;
up.port.regshift = 2;
up.port.flags = UPF_FIXED_PORT | UPF_FIXED_TYPE;
up.capabilities = UART_CAP_FIFO;
up.port.serial_in = uniphier_serial_in;
up.port.serial_out = uniphier_serial_out;
up.dl_read = uniphier_serial_dl_read;
up.dl_write = uniphier_serial_dl_write;
ret = serial8250_register_8250_port(&up);
if (ret < 0) {
dev_err(dev, "failed to register 8250 port\n");
clk_disable_unprepare(priv->clk);
return ret;
}
platform_set_drvdata(pdev, priv);
return 0;
}
static int uniphier_uart_remove(struct platform_device *pdev)
{
struct uniphier8250_priv *priv = platform_get_drvdata(pdev);
serial8250_unregister_port(priv->line);
clk_disable_unprepare(priv->clk);
return 0;
}
