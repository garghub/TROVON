static inline void rp2_decode_cap(const struct pci_device_id *id,
int *ports, int *smpte)
{
*ports = id->driver_data >> 8;
*smpte = id->driver_data & 0xff;
}
static int rp2_alloc_ports(int n_ports)
{
int ret = -ENOSPC;
spin_lock(&rp2_minor_lock);
if (rp2_minor_next + n_ports <= CONFIG_SERIAL_RP2_NR_UARTS) {
ret = rp2_minor_next;
rp2_minor_next += n_ports;
}
spin_unlock(&rp2_minor_lock);
return ret;
}
static inline struct rp2_uart_port *port_to_up(struct uart_port *port)
{
return container_of(port, struct rp2_uart_port, port);
}
static void rp2_rmw(struct rp2_uart_port *up, int reg,
u32 clr_bits, u32 set_bits)
{
u32 tmp = readl(up->base + reg);
tmp &= ~clr_bits;
tmp |= set_bits;
writel(tmp, up->base + reg);
}
static void rp2_rmw_clr(struct rp2_uart_port *up, int reg, u32 val)
{
rp2_rmw(up, reg, val, 0);
}
static void rp2_rmw_set(struct rp2_uart_port *up, int reg, u32 val)
{
rp2_rmw(up, reg, 0, val);
}
static void rp2_mask_ch_irq(struct rp2_uart_port *up, int ch_num,
int is_enabled)
{
unsigned long flags, irq_mask;
spin_lock_irqsave(&up->card->card_lock, flags);
irq_mask = readl(up->asic_base + RP2_CH_IRQ_MASK);
if (is_enabled)
irq_mask &= ~BIT(ch_num);
else
irq_mask |= BIT(ch_num);
writel(irq_mask, up->asic_base + RP2_CH_IRQ_MASK);
spin_unlock_irqrestore(&up->card->card_lock, flags);
}
static unsigned int rp2_uart_tx_empty(struct uart_port *port)
{
struct rp2_uart_port *up = port_to_up(port);
unsigned long tx_fifo_bytes, flags;
spin_lock_irqsave(&up->port.lock, flags);
tx_fifo_bytes = readw(up->base + RP2_TX_FIFO_COUNT);
spin_unlock_irqrestore(&up->port.lock, flags);
return tx_fifo_bytes ? 0 : TIOCSER_TEMT;
}
static unsigned int rp2_uart_get_mctrl(struct uart_port *port)
{
struct rp2_uart_port *up = port_to_up(port);
u32 status;
status = readl(up->base + RP2_CHAN_STAT);
return ((status & RP2_CHAN_STAT_DCD_m) ? TIOCM_CAR : 0) |
((status & RP2_CHAN_STAT_DSR_m) ? TIOCM_DSR : 0) |
((status & RP2_CHAN_STAT_CTS_m) ? TIOCM_CTS : 0) |
((status & RP2_CHAN_STAT_RI_m) ? TIOCM_RI : 0);
}
static void rp2_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
rp2_rmw(port_to_up(port), RP2_TXRX_CTL,
RP2_TXRX_CTL_DTR_m | RP2_TXRX_CTL_RTS_m | RP2_TXRX_CTL_LOOP_m,
((mctrl & TIOCM_DTR) ? RP2_TXRX_CTL_DTR_m : 0) |
((mctrl & TIOCM_RTS) ? RP2_TXRX_CTL_RTS_m : 0) |
((mctrl & TIOCM_LOOP) ? RP2_TXRX_CTL_LOOP_m : 0));
}
static void rp2_uart_start_tx(struct uart_port *port)
{
rp2_rmw_set(port_to_up(port), RP2_TXRX_CTL, RP2_TXRX_CTL_TXIRQ_m);
}
static void rp2_uart_stop_tx(struct uart_port *port)
{
rp2_rmw_clr(port_to_up(port), RP2_TXRX_CTL, RP2_TXRX_CTL_TXIRQ_m);
}
static void rp2_uart_stop_rx(struct uart_port *port)
{
rp2_rmw_clr(port_to_up(port), RP2_TXRX_CTL, RP2_TXRX_CTL_RXIRQ_m);
}
static void rp2_uart_break_ctl(struct uart_port *port, int break_state)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
rp2_rmw(port_to_up(port), RP2_TXRX_CTL, RP2_TXRX_CTL_BREAK_m,
break_state ? RP2_TXRX_CTL_BREAK_m : 0);
spin_unlock_irqrestore(&port->lock, flags);
}
static void rp2_uart_enable_ms(struct uart_port *port)
{
rp2_rmw_set(port_to_up(port), RP2_TXRX_CTL, RP2_TXRX_CTL_MSRIRQ_m);
}
static void __rp2_uart_set_termios(struct rp2_uart_port *up,
unsigned long cfl,
unsigned long ifl,
unsigned int baud_div)
{
writew(baud_div - 1, up->base + RP2_BAUD);
rp2_rmw(up, RP2_UART_CTL,
RP2_UART_CTL_STOPBITS_m | RP2_UART_CTL_DATABITS_m,
((cfl & CSTOPB) ? RP2_UART_CTL_STOPBITS_m : 0) |
(((cfl & CSIZE) == CS8) ? RP2_UART_CTL_DATABITS_8 : 0) |
(((cfl & CSIZE) == CS7) ? RP2_UART_CTL_DATABITS_7 : 0) |
(((cfl & CSIZE) == CS6) ? RP2_UART_CTL_DATABITS_6 : 0) |
(((cfl & CSIZE) == CS5) ? RP2_UART_CTL_DATABITS_5 : 0));
rp2_rmw(up, RP2_TXRX_CTL,
RP2_TXRX_CTL_PARENB_m | RP2_TXRX_CTL_nPARODD_m |
RP2_TXRX_CTL_CMSPAR_m | RP2_TXRX_CTL_DTRFLOW_m |
RP2_TXRX_CTL_DSRFLOW_m | RP2_TXRX_CTL_RTSFLOW_m |
RP2_TXRX_CTL_CTSFLOW_m,
((cfl & PARENB) ? RP2_TXRX_CTL_PARENB_m : 0) |
((cfl & PARODD) ? 0 : RP2_TXRX_CTL_nPARODD_m) |
((cfl & CMSPAR) ? RP2_TXRX_CTL_CMSPAR_m : 0) |
((cfl & CRTSCTS) ? (RP2_TXRX_CTL_RTSFLOW_m |
RP2_TXRX_CTL_CTSFLOW_m) : 0));
writeb((ifl & IXON) ? RP2_TX_SWFLOW_ena : RP2_TX_SWFLOW_dis,
up->ucode + RP2_TX_SWFLOW);
writeb((ifl & IXOFF) ? RP2_RX_SWFLOW_ena : RP2_RX_SWFLOW_dis,
up->ucode + RP2_RX_SWFLOW);
}
static void rp2_uart_set_termios(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
struct rp2_uart_port *up = port_to_up(port);
unsigned long flags;
unsigned int baud, baud_div;
baud = uart_get_baud_rate(port, new, old, 0, port->uartclk / 16);
baud_div = uart_get_divisor(port, baud);
if (tty_termios_baud_rate(new))
tty_termios_encode_baud_rate(new, baud, baud);
spin_lock_irqsave(&port->lock, flags);
port->ignore_status_mask = (new->c_cflag & CREAD) ? 0 : RP2_DUMMY_READ;
__rp2_uart_set_termios(up, new->c_cflag, new->c_iflag, baud_div);
uart_update_timeout(port, new->c_cflag, baud);
spin_unlock_irqrestore(&port->lock, flags);
}
static void rp2_rx_chars(struct rp2_uart_port *up)
{
u16 bytes = readw(up->base + RP2_RX_FIFO_COUNT);
struct tty_port *port = &up->port.state->port;
for (; bytes != 0; bytes--) {
u32 byte = readw(up->base + RP2_DATA_BYTE) | RP2_DUMMY_READ;
char ch = byte & 0xff;
if (likely(!(byte & RP2_DATA_BYTE_EXCEPTION_MASK))) {
if (!uart_handle_sysrq_char(&up->port, ch))
uart_insert_char(&up->port, byte, 0, ch,
TTY_NORMAL);
} else {
char flag = TTY_NORMAL;
if (byte & RP2_DATA_BYTE_BREAK_m)
flag = TTY_BREAK;
else if (byte & RP2_DATA_BYTE_ERR_FRAMING_m)
flag = TTY_FRAME;
else if (byte & RP2_DATA_BYTE_ERR_PARITY_m)
flag = TTY_PARITY;
uart_insert_char(&up->port, byte,
RP2_DATA_BYTE_ERR_OVERRUN_m, ch, flag);
}
up->port.icount.rx++;
}
tty_flip_buffer_push(port);
}
static void rp2_tx_chars(struct rp2_uart_port *up)
{
u16 max_tx = FIFO_SIZE - readw(up->base + RP2_TX_FIFO_COUNT);
struct circ_buf *xmit = &up->port.state->xmit;
if (uart_tx_stopped(&up->port)) {
rp2_uart_stop_tx(&up->port);
return;
}
for (; max_tx != 0; max_tx--) {
if (up->port.x_char) {
writeb(up->port.x_char, up->base + RP2_DATA_BYTE);
up->port.x_char = 0;
up->port.icount.tx++;
continue;
}
if (uart_circ_empty(xmit)) {
rp2_uart_stop_tx(&up->port);
break;
}
writeb(xmit->buf[xmit->tail], up->base + RP2_DATA_BYTE);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
}
static void rp2_ch_interrupt(struct rp2_uart_port *up)
{
u32 status;
spin_lock(&up->port.lock);
status = readl(up->base + RP2_CHAN_STAT);
writel(status, up->base + RP2_CHAN_STAT);
if (status & RP2_CHAN_STAT_RXDATA_m)
rp2_rx_chars(up);
if (status & RP2_CHAN_STAT_TXEMPTY_m)
rp2_tx_chars(up);
if (status & RP2_CHAN_STAT_MS_CHANGED_MASK)
wake_up_interruptible(&up->port.state->port.delta_msr_wait);
spin_unlock(&up->port.lock);
}
static int rp2_asic_interrupt(struct rp2_card *card, unsigned int asic_id)
{
void __iomem *base = card->bar1 + RP2_ASIC_OFFSET(asic_id);
int ch, handled = 0;
unsigned long status = readl(base + RP2_CH_IRQ_STAT) &
~readl(base + RP2_CH_IRQ_MASK);
for_each_set_bit(ch, &status, PORTS_PER_ASIC) {
rp2_ch_interrupt(&card->ports[ch]);
handled++;
}
return handled;
}
static irqreturn_t rp2_uart_interrupt(int irq, void *dev_id)
{
struct rp2_card *card = dev_id;
int handled;
handled = rp2_asic_interrupt(card, 0);
if (card->n_ports >= PORTS_PER_ASIC)
handled += rp2_asic_interrupt(card, 1);
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static inline void rp2_flush_fifos(struct rp2_uart_port *up)
{
rp2_rmw_set(up, RP2_UART_CTL,
RP2_UART_CTL_FLUSH_RX_m | RP2_UART_CTL_FLUSH_TX_m);
readl(up->base + RP2_UART_CTL);
udelay(10);
rp2_rmw_clr(up, RP2_UART_CTL,
RP2_UART_CTL_FLUSH_RX_m | RP2_UART_CTL_FLUSH_TX_m);
}
static int rp2_uart_startup(struct uart_port *port)
{
struct rp2_uart_port *up = port_to_up(port);
rp2_flush_fifos(up);
rp2_rmw(up, RP2_TXRX_CTL, RP2_TXRX_CTL_MSRIRQ_m, RP2_TXRX_CTL_RXIRQ_m);
rp2_rmw(up, RP2_TXRX_CTL, RP2_TXRX_CTL_RX_TRIG_m,
RP2_TXRX_CTL_RX_TRIG_1);
rp2_rmw(up, RP2_CHAN_STAT, 0, 0);
rp2_mask_ch_irq(up, up->idx, 1);
return 0;
}
static void rp2_uart_shutdown(struct uart_port *port)
{
struct rp2_uart_port *up = port_to_up(port);
unsigned long flags;
rp2_uart_break_ctl(port, 0);
spin_lock_irqsave(&port->lock, flags);
rp2_mask_ch_irq(up, up->idx, 0);
rp2_rmw(up, RP2_CHAN_STAT, 0, 0);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *rp2_uart_type(struct uart_port *port)
{
return (port->type == PORT_RP2) ? "RocketPort 2 UART" : NULL;
}
static void rp2_uart_release_port(struct uart_port *port)
{
}
static int rp2_uart_request_port(struct uart_port *port)
{
return 0;
}
static void rp2_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_RP2;
}
static int rp2_uart_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
if (ser->type != PORT_UNKNOWN && ser->type != PORT_RP2)
return -EINVAL;
return 0;
}
static void rp2_reset_asic(struct rp2_card *card, unsigned int asic_id)
{
void __iomem *base = card->bar1 + RP2_ASIC_OFFSET(asic_id);
u32 clk_cfg;
writew(1, base + RP2_GLOBAL_CMD);
readw(base + RP2_GLOBAL_CMD);
msleep(100);
writel(0, base + RP2_CLK_PRESCALER);
clk_cfg = readw(base + RP2_ASIC_CFG);
clk_cfg = (clk_cfg & ~BIT(8)) | BIT(9);
writew(clk_cfg, base + RP2_ASIC_CFG);
writel(ALL_PORTS_MASK, base + RP2_CH_IRQ_MASK);
writel(RP2_ASIC_IRQ_EN_m, base + RP2_ASIC_IRQ);
}
static void rp2_init_card(struct rp2_card *card)
{
writel(4, card->bar0 + RP2_FPGA_CTL0);
writel(0, card->bar0 + RP2_FPGA_CTL1);
rp2_reset_asic(card, 0);
if (card->n_ports >= PORTS_PER_ASIC)
rp2_reset_asic(card, 1);
writel(RP2_IRQ_MASK_EN_m, card->bar0 + RP2_IRQ_MASK);
}
static void rp2_init_port(struct rp2_uart_port *up, const struct firmware *fw)
{
int i;
writel(RP2_UART_CTL_RESET_CH_m, up->base + RP2_UART_CTL);
readl(up->base + RP2_UART_CTL);
udelay(1);
writel(0, up->base + RP2_TXRX_CTL);
writel(0, up->base + RP2_UART_CTL);
readl(up->base + RP2_UART_CTL);
udelay(1);
rp2_flush_fifos(up);
for (i = 0; i < min_t(int, fw->size, RP2_UCODE_BYTES); i++)
writeb(fw->data[i], up->ucode + i);
__rp2_uart_set_termios(up, CS8 | CREAD | CLOCAL, 0, DEFAULT_BAUD_DIV);
rp2_uart_set_mctrl(&up->port, 0);
writeb(RP2_RX_FIFO_ena, up->ucode + RP2_RX_FIFO);
rp2_rmw(up, RP2_UART_CTL, RP2_UART_CTL_MODE_m,
RP2_UART_CTL_XMIT_EN_m | RP2_UART_CTL_MODE_rs232);
rp2_rmw_set(up, RP2_TXRX_CTL,
RP2_TXRX_CTL_TX_EN_m | RP2_TXRX_CTL_RX_EN_m);
}
static void rp2_remove_ports(struct rp2_card *card)
{
int i;
for (i = 0; i < card->initialized_ports; i++)
uart_remove_one_port(&rp2_uart_driver, &card->ports[i].port);
card->initialized_ports = 0;
}
static void rp2_fw_cb(const struct firmware *fw, void *context)
{
struct rp2_card *card = context;
resource_size_t phys_base;
int i, rc = -ENOENT;
if (!fw) {
dev_err(&card->pdev->dev, "cannot find '%s' firmware image\n",
RP2_FW_NAME);
goto no_fw;
}
phys_base = pci_resource_start(card->pdev, 1);
for (i = 0; i < card->n_ports; i++) {
struct rp2_uart_port *rp = &card->ports[i];
struct uart_port *p;
int j = (unsigned)i % PORTS_PER_ASIC;
rp->asic_base = card->bar1;
rp->base = card->bar1 + RP2_PORT_BASE + j*RP2_PORT_SPACING;
rp->ucode = card->bar1 + RP2_UCODE_BASE + j*RP2_UCODE_SPACING;
rp->card = card;
rp->idx = j;
p = &rp->port;
p->line = card->minor_start + i;
p->dev = &card->pdev->dev;
p->type = PORT_RP2;
p->iotype = UPIO_MEM32;
p->uartclk = UART_CLOCK;
p->regshift = 2;
p->fifosize = FIFO_SIZE;
p->ops = &rp2_uart_ops;
p->irq = card->pdev->irq;
p->membase = rp->base;
p->mapbase = phys_base + RP2_PORT_BASE + j*RP2_PORT_SPACING;
if (i >= PORTS_PER_ASIC) {
rp->asic_base += RP2_ASIC_SPACING;
rp->base += RP2_ASIC_SPACING;
rp->ucode += RP2_ASIC_SPACING;
p->mapbase += RP2_ASIC_SPACING;
}
rp2_init_port(rp, fw);
rc = uart_add_one_port(&rp2_uart_driver, p);
if (rc) {
dev_err(&card->pdev->dev,
"error registering port %d: %d\n", i, rc);
rp2_remove_ports(card);
break;
}
card->initialized_ports++;
}
release_firmware(fw);
no_fw:
if (rc)
dev_warn(&card->pdev->dev, "driver initialization failed\n");
complete(&card->fw_loaded);
}
static int rp2_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct rp2_card *card;
struct rp2_uart_port *ports;
void __iomem * const *bars;
int rc;
card = devm_kzalloc(&pdev->dev, sizeof(*card), GFP_KERNEL);
if (!card)
return -ENOMEM;
pci_set_drvdata(pdev, card);
spin_lock_init(&card->card_lock);
init_completion(&card->fw_loaded);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions_request_all(pdev, 0x03, DRV_NAME);
if (rc)
return rc;
bars = pcim_iomap_table(pdev);
card->bar0 = bars[0];
card->bar1 = bars[1];
card->pdev = pdev;
rp2_decode_cap(id, &card->n_ports, &card->smpte);
dev_info(&pdev->dev, "found new card with %d ports\n", card->n_ports);
card->minor_start = rp2_alloc_ports(card->n_ports);
if (card->minor_start < 0) {
dev_err(&pdev->dev,
"too many ports (try increasing CONFIG_SERIAL_RP2_NR_UARTS)\n");
return -EINVAL;
}
rp2_init_card(card);
ports = devm_kzalloc(&pdev->dev, sizeof(*ports) * card->n_ports,
GFP_KERNEL);
if (!ports)
return -ENOMEM;
card->ports = ports;
rc = devm_request_irq(&pdev->dev, pdev->irq, rp2_uart_interrupt,
IRQF_SHARED, DRV_NAME, card);
if (rc)
return rc;
rc = request_firmware_nowait(THIS_MODULE, 1, RP2_FW_NAME, &pdev->dev,
GFP_KERNEL, card, rp2_fw_cb);
if (rc)
return rc;
dev_dbg(&pdev->dev, "waiting for firmware blob...\n");
return 0;
}
static void rp2_remove(struct pci_dev *pdev)
{
struct rp2_card *card = pci_get_drvdata(pdev);
wait_for_completion(&card->fw_loaded);
rp2_remove_ports(card);
}
static int __init rp2_uart_init(void)
{
int rc;
rc = uart_register_driver(&rp2_uart_driver);
if (rc)
return rc;
rc = pci_register_driver(&rp2_pci_driver);
if (rc) {
uart_unregister_driver(&rp2_uart_driver);
return rc;
}
return 0;
}
static void __exit rp2_uart_exit(void)
{
pci_unregister_driver(&rp2_pci_driver);
uart_unregister_driver(&rp2_uart_driver);
}
