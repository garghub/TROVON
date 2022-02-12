static int moxa8250_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct uart_8250_port uart;
struct moxa8250_board *brd;
void __iomem *ioaddr;
resource_size_t baseaddr;
unsigned int i, nr_ports;
unsigned int offset;
int ret;
brd = &moxa8250_boards[id->driver_data];
nr_ports = brd->num_ports;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
brd = devm_kzalloc(&pdev->dev, sizeof(struct moxa8250_board) +
sizeof(unsigned int) * nr_ports, GFP_KERNEL);
if (!brd)
return -ENOMEM;
memset(&uart, 0, sizeof(struct uart_8250_port));
uart.port.dev = &pdev->dev;
uart.port.irq = pdev->irq;
uart.port.uartclk = MOXA_BASE_BAUD * 16;
uart.port.flags = UPF_SKIP_TEST | UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ;
baseaddr = pci_resource_start(pdev, MOXA_BASE_BAR);
ioaddr = pcim_iomap(pdev, MOXA_BASE_BAR, 0);
if (!ioaddr)
return -ENOMEM;
for (i = 0; i < nr_ports; i++) {
if (nr_ports == 4 && i == 3)
offset = 7 * MOXA_UART_OFFSET;
else
offset = i * MOXA_UART_OFFSET;
uart.port.iotype = UPIO_MEM;
uart.port.iobase = 0;
uart.port.mapbase = baseaddr + offset;
uart.port.membase = ioaddr + offset;
uart.port.regshift = 0;
dev_dbg(&pdev->dev, "Setup PCI port: port %lx, irq %d, type %d\n",
uart.port.iobase, uart.port.irq, uart.port.iotype);
brd->line[i] = serial8250_register_8250_port(&uart);
if (brd->line[i] < 0) {
dev_err(&pdev->dev,
"Couldn't register serial port %lx, irq %d, type %d, error %d\n",
uart.port.iobase, uart.port.irq,
uart.port.iotype, brd->line[i]);
break;
}
}
pci_set_drvdata(pdev, brd);
return 0;
}
static void moxa8250_remove(struct pci_dev *pdev)
{
struct moxa8250_board *brd = pci_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < brd->num_ports; i++)
serial8250_unregister_port(brd->line[i]);
}
