static void byt_set_termios(struct uart_port *p, struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud = tty_termios_baud_rate(termios);
struct lpss8250 *lpss = p->private_data;
unsigned long fref = lpss->board->freq, fuart = baud * 16;
unsigned long w = BIT(15) - 1;
unsigned long m, n;
u32 reg;
fuart = fuart ? fuart : 9600 * 16;
fuart *= rounddown_pow_of_two(fref / fuart);
rational_best_approximation(fuart, fref, w, w, &m, &n);
p->uartclk = fuart;
reg = (m << BYT_PRV_CLK_M_VAL_SHIFT) | (n << BYT_PRV_CLK_N_VAL_SHIFT);
writel(reg, p->membase + BYT_PRV_CLK);
reg |= BYT_PRV_CLK_EN | BYT_PRV_CLK_UPDATE;
writel(reg, p->membase + BYT_PRV_CLK);
p->status &= ~UPSTAT_AUTOCTS;
if (termios->c_cflag & CRTSCTS)
p->status |= UPSTAT_AUTOCTS;
serial8250_do_set_termios(p, termios, old);
}
static unsigned int byt_get_mctrl(struct uart_port *port)
{
unsigned int ret = serial8250_do_get_mctrl(port);
ret |= TIOCM_CAR | TIOCM_DSR;
return ret;
}
static int byt_serial_setup(struct lpss8250 *lpss, struct uart_port *port)
{
struct dw_dma_slave *param = &lpss->dma_param;
struct uart_8250_port *up = up_to_u8250p(port);
struct pci_dev *pdev = to_pci_dev(port->dev);
unsigned int dma_devfn = PCI_DEVFN(PCI_SLOT(pdev->devfn), 0);
struct pci_dev *dma_dev = pci_get_slot(pdev->bus, dma_devfn);
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_BYT_UART1:
case PCI_DEVICE_ID_INTEL_BSW_UART1:
case PCI_DEVICE_ID_INTEL_BDW_UART1:
param->src_id = 3;
param->dst_id = 2;
break;
case PCI_DEVICE_ID_INTEL_BYT_UART2:
case PCI_DEVICE_ID_INTEL_BSW_UART2:
case PCI_DEVICE_ID_INTEL_BDW_UART2:
param->src_id = 5;
param->dst_id = 4;
break;
default:
return -EINVAL;
}
param->dma_dev = &dma_dev->dev;
param->m_master = 0;
param->p_master = 1;
port->fifosize = 64;
up->tx_loadsz = 64;
lpss->dma_maxburst = 16;
port->set_termios = byt_set_termios;
port->get_mctrl = byt_get_mctrl;
writel(BYT_TX_OVF_INT_MASK, port->membase + BYT_TX_OVF_INT);
return 0;
}
static void qrk_serial_setup_dma(struct lpss8250 *lpss, struct uart_port *port)
{
struct uart_8250_dma *dma = &lpss->dma;
struct dw_dma_chip *chip = &lpss->dma_chip;
struct dw_dma_slave *param = &lpss->dma_param;
struct pci_dev *pdev = to_pci_dev(port->dev);
int ret;
chip->dev = &pdev->dev;
chip->irq = pci_irq_vector(pdev, 0);
chip->regs = pci_ioremap_bar(pdev, 1);
chip->pdata = &qrk_serial_dma_pdata;
ret = dw_dma_probe(chip);
if (ret)
return;
pci_try_set_mwi(pdev);
dma->rx_dma_addr = 0xfffff000;
dma->tx_dma_addr = 0xfffff000;
param->dma_dev = &pdev->dev;
param->src_id = 0;
param->dst_id = 1;
param->hs_polarity = true;
lpss->dma_maxburst = 8;
}
static void qrk_serial_exit_dma(struct lpss8250 *lpss)
{
struct dw_dma_slave *param = &lpss->dma_param;
if (!param->dma_dev)
return;
dw_dma_remove(&lpss->dma_chip);
}
static void qrk_serial_setup_dma(struct lpss8250 *lpss, struct uart_port *port) {}
static void qrk_serial_exit_dma(struct lpss8250 *lpss) {}
static int qrk_serial_setup(struct lpss8250 *lpss, struct uart_port *port)
{
struct pci_dev *pdev = to_pci_dev(port->dev);
int ret;
pci_set_master(pdev);
ret = pci_alloc_irq_vectors(pdev, 1, 1, PCI_IRQ_ALL_TYPES);
if (ret < 0)
return ret;
port->irq = pci_irq_vector(pdev, 0);
qrk_serial_setup_dma(lpss, port);
return 0;
}
static void qrk_serial_exit(struct lpss8250 *lpss)
{
qrk_serial_exit_dma(lpss);
}
static bool lpss8250_dma_filter(struct dma_chan *chan, void *param)
{
struct dw_dma_slave *dws = param;
if (dws->dma_dev != chan->device->dev)
return false;
chan->private = dws;
return true;
}
static int lpss8250_dma_setup(struct lpss8250 *lpss, struct uart_8250_port *port)
{
struct uart_8250_dma *dma = &lpss->dma;
struct dw_dma_slave *rx_param, *tx_param;
struct device *dev = port->port.dev;
if (!lpss->dma_param.dma_dev)
return 0;
rx_param = devm_kzalloc(dev, sizeof(*rx_param), GFP_KERNEL);
if (!rx_param)
return -ENOMEM;
tx_param = devm_kzalloc(dev, sizeof(*tx_param), GFP_KERNEL);
if (!tx_param)
return -ENOMEM;
*rx_param = lpss->dma_param;
dma->rxconf.src_maxburst = lpss->dma_maxburst;
*tx_param = lpss->dma_param;
dma->txconf.dst_maxburst = lpss->dma_maxburst;
dma->fn = lpss8250_dma_filter;
dma->rx_param = rx_param;
dma->tx_param = tx_param;
port->dma = dma;
return 0;
}
static int lpss8250_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct uart_8250_port uart;
struct lpss8250 *lpss;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
lpss = devm_kzalloc(&pdev->dev, sizeof(*lpss), GFP_KERNEL);
if (!lpss)
return -ENOMEM;
lpss->board = (struct lpss8250_board *)id->driver_data;
memset(&uart, 0, sizeof(struct uart_8250_port));
uart.port.dev = &pdev->dev;
uart.port.irq = pdev->irq;
uart.port.private_data = lpss;
uart.port.type = PORT_16550A;
uart.port.iotype = UPIO_MEM;
uart.port.regshift = 2;
uart.port.uartclk = lpss->board->base_baud * 16;
uart.port.flags = UPF_SHARE_IRQ | UPF_FIXED_PORT | UPF_FIXED_TYPE;
uart.capabilities = UART_CAP_FIFO | UART_CAP_AFE;
uart.port.mapbase = pci_resource_start(pdev, 0);
uart.port.membase = pcim_iomap(pdev, 0, 0);
if (!uart.port.membase)
return -ENOMEM;
ret = lpss->board->setup(lpss, &uart.port);
if (ret)
return ret;
ret = lpss8250_dma_setup(lpss, &uart);
if (ret)
goto err_exit;
ret = serial8250_register_8250_port(&uart);
if (ret < 0)
goto err_exit;
lpss->line = ret;
pci_set_drvdata(pdev, lpss);
return 0;
err_exit:
if (lpss->board->exit)
lpss->board->exit(lpss);
return ret;
}
static void lpss8250_remove(struct pci_dev *pdev)
{
struct lpss8250 *lpss = pci_get_drvdata(pdev);
serial8250_unregister_port(lpss->line);
if (lpss->board->exit)
lpss->board->exit(lpss);
}
