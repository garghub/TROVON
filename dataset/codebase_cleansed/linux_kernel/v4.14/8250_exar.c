static int default_setup(struct exar8250 *priv, struct pci_dev *pcidev,
int idx, unsigned int offset,
struct uart_8250_port *port)
{
const struct exar8250_board *board = priv->board;
unsigned int bar = 0;
if (!pcim_iomap_table(pcidev)[bar] && !pcim_iomap(pcidev, bar, 0))
return -ENOMEM;
port->port.iotype = UPIO_MEM;
port->port.mapbase = pci_resource_start(pcidev, bar) + offset;
port->port.membase = pcim_iomap_table(pcidev)[bar] + offset;
port->port.regshift = board->reg_shift;
return 0;
}
static int
pci_fastcom335_setup(struct exar8250 *priv, struct pci_dev *pcidev,
struct uart_8250_port *port, int idx)
{
unsigned int offset = idx * 0x200;
unsigned int baud = 1843200;
u8 __iomem *p;
int err;
port->port.uartclk = baud * 16;
err = default_setup(priv, pcidev, idx, offset, port);
if (err)
return err;
p = port->port.membase;
writeb(0x00, p + UART_EXAR_8XMODE);
writeb(UART_FCTR_EXAR_TRGD, p + UART_EXAR_FCTR);
writeb(32, p + UART_EXAR_TXTRG);
writeb(32, p + UART_EXAR_RXTRG);
if (idx == 0) {
switch (pcidev->device) {
case PCI_DEVICE_ID_COMMTECH_4222PCI335:
case PCI_DEVICE_ID_COMMTECH_4224PCI335:
writeb(0x78, p + UART_EXAR_MPIOLVL_7_0);
writeb(0x00, p + UART_EXAR_MPIOINV_7_0);
writeb(0x00, p + UART_EXAR_MPIOSEL_7_0);
break;
case PCI_DEVICE_ID_COMMTECH_2324PCI335:
case PCI_DEVICE_ID_COMMTECH_2328PCI335:
writeb(0x00, p + UART_EXAR_MPIOLVL_7_0);
writeb(0xc0, p + UART_EXAR_MPIOINV_7_0);
writeb(0xc0, p + UART_EXAR_MPIOSEL_7_0);
break;
}
writeb(0x00, p + UART_EXAR_MPIOINT_7_0);
writeb(0x00, p + UART_EXAR_MPIO3T_7_0);
writeb(0x00, p + UART_EXAR_MPIOOD_7_0);
}
return 0;
}
static int
pci_connect_tech_setup(struct exar8250 *priv, struct pci_dev *pcidev,
struct uart_8250_port *port, int idx)
{
unsigned int offset = idx * 0x200;
unsigned int baud = 1843200;
port->port.uartclk = baud * 16;
return default_setup(priv, pcidev, idx, offset, port);
}
static int
pci_xr17c154_setup(struct exar8250 *priv, struct pci_dev *pcidev,
struct uart_8250_port *port, int idx)
{
unsigned int offset = idx * 0x200;
unsigned int baud = 921600;
port->port.uartclk = baud * 16;
return default_setup(priv, pcidev, idx, offset, port);
}
static void setup_gpio(struct pci_dev *pcidev, u8 __iomem *p)
{
u8 dir = pcidev->vendor == PCI_VENDOR_ID_EXAR ? 0xff : 0x00;
writeb(0x00, p + UART_EXAR_MPIOINT_7_0);
writeb(0x00, p + UART_EXAR_MPIOLVL_7_0);
writeb(0x00, p + UART_EXAR_MPIO3T_7_0);
writeb(0x00, p + UART_EXAR_MPIOINV_7_0);
writeb(dir, p + UART_EXAR_MPIOSEL_7_0);
writeb(0x00, p + UART_EXAR_MPIOOD_7_0);
writeb(0x00, p + UART_EXAR_MPIOINT_15_8);
writeb(0x00, p + UART_EXAR_MPIOLVL_15_8);
writeb(0x00, p + UART_EXAR_MPIO3T_15_8);
writeb(0x00, p + UART_EXAR_MPIOINV_15_8);
writeb(dir, p + UART_EXAR_MPIOSEL_15_8);
writeb(0x00, p + UART_EXAR_MPIOOD_15_8);
}
static void *
__xr17v35x_register_gpio(struct pci_dev *pcidev,
const struct property_entry *properties)
{
struct platform_device *pdev;
pdev = platform_device_alloc("gpio_exar", PLATFORM_DEVID_AUTO);
if (!pdev)
return NULL;
pdev->dev.parent = &pcidev->dev;
ACPI_COMPANION_SET(&pdev->dev, ACPI_COMPANION(&pcidev->dev));
if (platform_device_add_properties(pdev, properties) < 0 ||
platform_device_add(pdev) < 0) {
platform_device_put(pdev);
return NULL;
}
return pdev;
}
static int xr17v35x_register_gpio(struct pci_dev *pcidev,
struct uart_8250_port *port)
{
if (pcidev->vendor == PCI_VENDOR_ID_EXAR)
port->port.private_data =
__xr17v35x_register_gpio(pcidev, exar_gpio_properties);
return 0;
}
static int iot2040_rs485_config(struct uart_port *port,
struct serial_rs485 *rs485)
{
bool is_rs485 = !!(rs485->flags & SER_RS485_ENABLED);
u8 __iomem *p = port->membase;
u8 mask = IOT2040_UART1_MASK;
u8 mode, value;
if (is_rs485) {
if (rs485->flags & SER_RS485_RX_DURING_TX)
mode = IOT2040_UART_MODE_RS422;
else
mode = IOT2040_UART_MODE_RS485;
if (rs485->flags & SER_RS485_TERMINATE_BUS)
mode |= IOT2040_UART_TERMINATE_BUS;
} else {
mode = IOT2040_UART_MODE_RS232;
}
if (port->line == 3) {
mask <<= IOT2040_UART2_SHIFT;
mode <<= IOT2040_UART2_SHIFT;
}
value = readb(p + UART_EXAR_MPIOLVL_7_0);
value &= ~mask;
value |= mode;
writeb(value, p + UART_EXAR_MPIOLVL_7_0);
value = readb(p + UART_EXAR_FCTR);
if (is_rs485)
value |= UART_FCTR_EXAR_485;
else
value &= ~UART_FCTR_EXAR_485;
writeb(value, p + UART_EXAR_FCTR);
if (is_rs485)
writeb(UART_EXAR_RS485_DLY(4), p + UART_MSR);
port->rs485 = *rs485;
return 0;
}
static int iot2040_register_gpio(struct pci_dev *pcidev,
struct uart_8250_port *port)
{
u8 __iomem *p = port->port.membase;
writeb(IOT2040_UARTS_DEFAULT_MODE, p + UART_EXAR_MPIOLVL_7_0);
writeb(IOT2040_UARTS_GPIO_LO_MODE, p + UART_EXAR_MPIOSEL_7_0);
writeb(IOT2040_UARTS_ENABLE, p + UART_EXAR_MPIOLVL_15_8);
writeb(IOT2040_UARTS_GPIO_HI_MODE, p + UART_EXAR_MPIOSEL_15_8);
port->port.private_data =
__xr17v35x_register_gpio(pcidev, iot2040_gpio_properties);
return 0;
}
static int
pci_xr17v35x_setup(struct exar8250 *priv, struct pci_dev *pcidev,
struct uart_8250_port *port, int idx)
{
const struct exar8250_board *board = priv->board;
const struct exar8250_platform *platform;
const struct dmi_system_id *dmi_match;
unsigned int offset = idx * 0x400;
unsigned int baud = 7812500;
u8 __iomem *p;
int ret;
dmi_match = dmi_first_match(exar_platforms);
if (dmi_match)
platform = dmi_match->driver_data;
else
platform = &exar8250_default_platform;
port->port.uartclk = baud * 16;
port->port.rs485_config = platform->rs485_config;
if (board->has_slave && idx >= 8)
port->port.uartclk /= 2;
ret = default_setup(priv, pcidev, idx, offset, port);
if (ret)
return ret;
p = port->port.membase;
writeb(0x00, p + UART_EXAR_8XMODE);
writeb(UART_FCTR_EXAR_TRGD, p + UART_EXAR_FCTR);
writeb(128, p + UART_EXAR_TXTRG);
writeb(128, p + UART_EXAR_RXTRG);
if (idx == 0) {
setup_gpio(pcidev, p);
ret = platform->register_gpio(pcidev, port);
}
return ret;
}
static void pci_xr17v35x_exit(struct pci_dev *pcidev)
{
struct exar8250 *priv = pci_get_drvdata(pcidev);
struct uart_8250_port *port = serial8250_get_port(priv->line[0]);
struct platform_device *pdev = port->port.private_data;
platform_device_unregister(pdev);
port->port.private_data = NULL;
}
static int
exar_pci_probe(struct pci_dev *pcidev, const struct pci_device_id *ent)
{
unsigned int nr_ports, i, bar = 0, maxnr;
struct exar8250_board *board;
struct uart_8250_port uart;
struct exar8250 *priv;
int rc;
board = (struct exar8250_board *)ent->driver_data;
if (!board)
return -EINVAL;
rc = pcim_enable_device(pcidev);
if (rc)
return rc;
maxnr = pci_resource_len(pcidev, bar) >> (board->reg_shift + 3);
nr_ports = board->num_ports ? board->num_ports : pcidev->device & 0x0f;
priv = devm_kzalloc(&pcidev->dev, sizeof(*priv) +
sizeof(unsigned int) * nr_ports,
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->board = board;
pci_set_master(pcidev);
rc = pci_alloc_irq_vectors(pcidev, 1, 1, PCI_IRQ_ALL_TYPES);
if (rc < 0)
return rc;
memset(&uart, 0, sizeof(uart));
uart.port.flags = UPF_SKIP_TEST | UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ
| UPF_EXAR_EFR;
uart.port.irq = pci_irq_vector(pcidev, 0);
uart.port.dev = &pcidev->dev;
for (i = 0; i < nr_ports && i < maxnr; i++) {
rc = board->setup(priv, pcidev, &uart, i);
if (rc) {
dev_err(&pcidev->dev, "Failed to setup port %u\n", i);
break;
}
dev_dbg(&pcidev->dev, "Setup PCI port: port %lx, irq %d, type %d\n",
uart.port.iobase, uart.port.irq, uart.port.iotype);
priv->line[i] = serial8250_register_8250_port(&uart);
if (priv->line[i] < 0) {
dev_err(&pcidev->dev,
"Couldn't register serial port %lx, irq %d, type %d, error %d\n",
uart.port.iobase, uart.port.irq,
uart.port.iotype, priv->line[i]);
break;
}
}
priv->nr = i;
pci_set_drvdata(pcidev, priv);
return 0;
}
static void exar_pci_remove(struct pci_dev *pcidev)
{
struct exar8250 *priv = pci_get_drvdata(pcidev);
unsigned int i;
for (i = 0; i < priv->nr; i++)
serial8250_unregister_port(priv->line[i]);
if (priv->board->exit)
priv->board->exit(pcidev);
}
static int __maybe_unused exar_suspend(struct device *dev)
{
struct pci_dev *pcidev = to_pci_dev(dev);
struct exar8250 *priv = pci_get_drvdata(pcidev);
unsigned int i;
for (i = 0; i < priv->nr; i++)
if (priv->line[i] >= 0)
serial8250_suspend_port(priv->line[i]);
if (priv->board->exit)
priv->board->exit(pcidev);
return 0;
}
static int __maybe_unused exar_resume(struct device *dev)
{
struct pci_dev *pcidev = to_pci_dev(dev);
struct exar8250 *priv = pci_get_drvdata(pcidev);
unsigned int i;
for (i = 0; i < priv->nr; i++)
if (priv->line[i] >= 0)
serial8250_resume_port(priv->line[i]);
return 0;
}
