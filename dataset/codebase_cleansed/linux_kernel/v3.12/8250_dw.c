static inline int dw8250_modify_msr(struct uart_port *p, int offset, int value)
{
struct dw8250_data *d = p->private_data;
if (offset == UART_MSR && d->last_mcr & UART_MCR_AFE) {
value |= UART_MSR_CTS;
value &= ~UART_MSR_DCTS;
}
return value;
}
static void dw8250_serial_out(struct uart_port *p, int offset, int value)
{
struct dw8250_data *d = p->private_data;
if (offset == UART_LCR)
d->last_lcr = value;
if (offset == UART_MCR)
d->last_mcr = value;
writeb(value, p->membase + (offset << p->regshift));
}
static unsigned int dw8250_serial_in(struct uart_port *p, int offset)
{
unsigned int value = readb(p->membase + (offset << p->regshift));
return dw8250_modify_msr(p, offset, value);
}
static void dw8250_serial_out_rb(struct uart_port *p, int offset, int value)
{
dw8250_serial_out(p, offset, value);
dw8250_serial_in(p, UART_LCR);
}
static void dw8250_serial_out32(struct uart_port *p, int offset, int value)
{
struct dw8250_data *d = p->private_data;
if (offset == UART_LCR)
d->last_lcr = value;
if (offset == UART_MCR)
d->last_mcr = value;
writel(value, p->membase + (offset << p->regshift));
}
static unsigned int dw8250_serial_in32(struct uart_port *p, int offset)
{
unsigned int value = readl(p->membase + (offset << p->regshift));
return dw8250_modify_msr(p, offset, value);
}
static int dw8250_handle_irq(struct uart_port *p)
{
struct dw8250_data *d = p->private_data;
unsigned int iir = p->serial_in(p, UART_IIR);
if (serial8250_handle_irq(p, iir)) {
return 1;
} else if ((iir & UART_IIR_BUSY) == UART_IIR_BUSY) {
(void)p->serial_in(p, d->usr_reg);
p->serial_out(p, UART_LCR, d->last_lcr);
return 1;
}
return 0;
}
static void
dw8250_do_pm(struct uart_port *port, unsigned int state, unsigned int old)
{
if (!state)
pm_runtime_get_sync(port->dev);
serial8250_do_pm(port, state, old);
if (state)
pm_runtime_put_sync_suspend(port->dev);
}
static void dw8250_setup_port(struct uart_8250_port *up)
{
struct uart_port *p = &up->port;
u32 reg = readl(p->membase + DW_UART_UCV);
if (!reg)
return;
dev_dbg_ratelimited(p->dev, "Designware UART version %c.%c%c\n",
(reg >> 24) & 0xff, (reg >> 16) & 0xff, (reg >> 8) & 0xff);
reg = readl(p->membase + DW_UART_CPR);
if (!reg)
return;
if (reg & DW_UART_CPR_FIFO_MODE) {
p->type = PORT_16550A;
p->flags |= UPF_FIXED_TYPE;
p->fifosize = DW_UART_CPR_FIFO_SIZE(reg);
up->tx_loadsz = p->fifosize;
up->capabilities = UART_CAP_FIFO;
}
if (reg & DW_UART_CPR_AFCE_MODE)
up->capabilities |= UART_CAP_AFE;
}
static int dw8250_probe_of(struct uart_port *p,
struct dw8250_data *data)
{
struct device_node *np = p->dev->of_node;
u32 val;
bool has_ucv = true;
if (of_device_is_compatible(np, "cavium,octeon-3860-uart")) {
#ifdef __BIG_ENDIAN
p->membase += 7;
#endif
p->serial_out = dw8250_serial_out_rb;
p->flags = ASYNC_SKIP_TEST | UPF_SHARE_IRQ | UPF_FIXED_TYPE;
p->type = PORT_OCTEON;
data->usr_reg = 0x27;
has_ucv = false;
} else if (!of_property_read_u32(np, "reg-io-width", &val)) {
switch (val) {
case 1:
break;
case 4:
p->iotype = UPIO_MEM32;
p->serial_in = dw8250_serial_in32;
p->serial_out = dw8250_serial_out32;
break;
default:
dev_err(p->dev, "unsupported reg-io-width (%u)\n", val);
return -EINVAL;
}
}
if (has_ucv)
dw8250_setup_port(container_of(p, struct uart_8250_port, port));
if (!of_property_read_u32(np, "reg-shift", &val))
p->regshift = val;
if (p->uartclk)
return 0;
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(p->dev, "clk or clock-frequency not defined\n");
return -EINVAL;
}
p->uartclk = val;
return 0;
}
static int dw8250_probe_acpi(struct uart_8250_port *up)
{
const struct acpi_device_id *id;
struct uart_port *p = &up->port;
dw8250_setup_port(up);
id = acpi_match_device(p->dev->driver->acpi_match_table, p->dev);
if (!id)
return -ENODEV;
p->iotype = UPIO_MEM32;
p->serial_in = dw8250_serial_in32;
p->serial_out = dw8250_serial_out32;
p->regshift = 2;
if (!p->uartclk)
p->uartclk = (unsigned int)id->driver_data;
up->dma = devm_kzalloc(p->dev, sizeof(*up->dma), GFP_KERNEL);
if (!up->dma)
return -ENOMEM;
up->dma->rxconf.src_maxburst = p->fifosize / 4;
up->dma->txconf.dst_maxburst = p->fifosize / 4;
return 0;
}
static inline int dw8250_probe_acpi(struct uart_8250_port *up)
{
return -ENODEV;
}
static int dw8250_probe(struct platform_device *pdev)
{
struct uart_8250_port uart = {};
struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
struct dw8250_data *data;
int err;
if (!regs || !irq) {
dev_err(&pdev->dev, "no registers/irq defined\n");
return -EINVAL;
}
spin_lock_init(&uart.port.lock);
uart.port.mapbase = regs->start;
uart.port.irq = irq->start;
uart.port.handle_irq = dw8250_handle_irq;
uart.port.pm = dw8250_do_pm;
uart.port.type = PORT_8250;
uart.port.flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_FIXED_PORT;
uart.port.dev = &pdev->dev;
uart.port.membase = devm_ioremap(&pdev->dev, regs->start,
resource_size(regs));
if (!uart.port.membase)
return -ENOMEM;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->usr_reg = DW_UART_USR;
data->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(data->clk)) {
clk_prepare_enable(data->clk);
uart.port.uartclk = clk_get_rate(data->clk);
}
uart.port.iotype = UPIO_MEM;
uart.port.serial_in = dw8250_serial_in;
uart.port.serial_out = dw8250_serial_out;
uart.port.private_data = data;
if (pdev->dev.of_node) {
err = dw8250_probe_of(&uart.port, data);
if (err)
return err;
} else if (ACPI_HANDLE(&pdev->dev)) {
err = dw8250_probe_acpi(&uart);
if (err)
return err;
} else {
return -ENODEV;
}
data->line = serial8250_register_8250_port(&uart);
if (data->line < 0)
return data->line;
platform_set_drvdata(pdev, data);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int dw8250_remove(struct platform_device *pdev)
{
struct dw8250_data *data = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
serial8250_unregister_port(data->line);
if (!IS_ERR(data->clk))
clk_disable_unprepare(data->clk);
pm_runtime_disable(&pdev->dev);
pm_runtime_put_noidle(&pdev->dev);
return 0;
}
static int dw8250_suspend(struct device *dev)
{
struct dw8250_data *data = dev_get_drvdata(dev);
serial8250_suspend_port(data->line);
return 0;
}
static int dw8250_resume(struct device *dev)
{
struct dw8250_data *data = dev_get_drvdata(dev);
serial8250_resume_port(data->line);
return 0;
}
static int dw8250_runtime_suspend(struct device *dev)
{
struct dw8250_data *data = dev_get_drvdata(dev);
if (!IS_ERR(data->clk))
clk_disable_unprepare(data->clk);
return 0;
}
static int dw8250_runtime_resume(struct device *dev)
{
struct dw8250_data *data = dev_get_drvdata(dev);
if (!IS_ERR(data->clk))
clk_prepare_enable(data->clk);
return 0;
}
