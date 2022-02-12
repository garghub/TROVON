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
(void)p->serial_in(p, DW_UART_USR);
p->serial_out(p, UART_LCR, d->last_lcr);
return 1;
}
return 0;
}
static int dw8250_probe_of(struct uart_port *p)
{
struct device_node *np = p->dev->of_node;
u32 val;
if (!of_property_read_u32(np, "reg-io-width", &val)) {
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
if (!of_property_read_u32(np, "reg-shift", &val))
p->regshift = val;
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(p->dev, "no clock-frequency property set\n");
return -EINVAL;
}
p->uartclk = val;
return 0;
}
static bool dw8250_acpi_dma_filter(struct dma_chan *chan, void *parm)
{
return chan->chan_id == *(int *)parm;
}
static acpi_status
dw8250_acpi_walk_resource(struct acpi_resource *res, void *data)
{
struct uart_port *p = data;
struct uart_8250_port *port;
struct uart_8250_dma *dma;
struct acpi_resource_fixed_dma *fixed_dma;
struct dma_slave_config *slave;
port = container_of(p, struct uart_8250_port, port);
switch (res->type) {
case ACPI_RESOURCE_TYPE_FIXED_DMA:
fixed_dma = &res->data.fixed_dma;
if (!port->dma) {
dma = devm_kzalloc(p->dev, sizeof(*dma), GFP_KERNEL);
if (!dma)
return AE_NO_MEMORY;
port->dma = dma;
slave = &dma->txconf;
slave->direction = DMA_MEM_TO_DEV;
slave->dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave->slave_id = fixed_dma->request_lines;
slave->dst_maxburst = port->tx_loadsz / 4;
dma->tx_chan_id = fixed_dma->channels;
dma->tx_param = &dma->tx_chan_id;
dma->fn = dw8250_acpi_dma_filter;
} else {
dma = port->dma;
slave = &dma->rxconf;
slave->direction = DMA_DEV_TO_MEM;
slave->src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave->slave_id = fixed_dma->request_lines;
slave->src_maxburst = p->fifosize / 4;
dma->rx_chan_id = fixed_dma->channels;
dma->rx_param = &dma->rx_chan_id;
}
break;
}
return AE_OK;
}
static int dw8250_probe_acpi(struct uart_port *p)
{
const struct acpi_device_id *id;
acpi_status status;
u32 reg;
id = acpi_match_device(p->dev->driver->acpi_match_table, p->dev);
if (!id)
return -ENODEV;
p->iotype = UPIO_MEM32;
p->serial_in = dw8250_serial_in32;
p->serial_out = dw8250_serial_out32;
p->regshift = 2;
p->uartclk = (unsigned int)id->driver_data;
status = acpi_walk_resources(ACPI_HANDLE(p->dev), METHOD_NAME__CRS,
dw8250_acpi_walk_resource, p);
if (ACPI_FAILURE(status)) {
dev_err_ratelimited(p->dev, "%s failed \"%s\"\n", __func__,
acpi_format_exception(status));
return -ENODEV;
}
if (!strcmp(id->id, "INT33C4") || !strcmp(id->id, "INT33C5")) {
reg = readl(p->membase + LPSS_PRV_CLOCK_PARAMS);
writel(reg | 1, p->membase + LPSS_PRV_CLOCK_PARAMS);
}
return 0;
}
static inline int dw8250_probe_acpi(struct uart_port *p)
{
return -ENODEV;
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
}
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
uart.port.type = PORT_8250;
uart.port.flags = UPF_SHARE_IRQ | UPF_BOOT_AUTOCONF | UPF_FIXED_PORT;
uart.port.dev = &pdev->dev;
uart.port.membase = ioremap(regs->start, resource_size(regs));
if (!uart.port.membase)
return -ENOMEM;
uart.port.iotype = UPIO_MEM;
uart.port.serial_in = dw8250_serial_in;
uart.port.serial_out = dw8250_serial_out;
dw8250_setup_port(&uart);
if (pdev->dev.of_node) {
err = dw8250_probe_of(&uart.port);
if (err)
return err;
} else if (ACPI_HANDLE(&pdev->dev)) {
err = dw8250_probe_acpi(&uart.port);
if (err)
return err;
} else {
return -ENODEV;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
uart.port.private_data = data;
data->line = serial8250_register_8250_port(&uart);
if (data->line < 0)
return data->line;
platform_set_drvdata(pdev, data);
return 0;
}
static int dw8250_remove(struct platform_device *pdev)
{
struct dw8250_data *data = platform_get_drvdata(pdev);
serial8250_unregister_port(data->line);
return 0;
}
static int dw8250_suspend(struct platform_device *pdev, pm_message_t state)
{
struct dw8250_data *data = platform_get_drvdata(pdev);
serial8250_suspend_port(data->line);
return 0;
}
static int dw8250_resume(struct platform_device *pdev)
{
struct dw8250_data *data = platform_get_drvdata(pdev);
serial8250_resume_port(data->line);
return 0;
}
