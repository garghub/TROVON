static void
cris_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_cris_port *up;
int i;
reg_ser_r_stat_din stat;
reg_ser_rw_tr_dma_en tr_dma_en, old;
up = etraxfs_uart_ports[co->index];
if (!up)
return;
tr_dma_en = old = REG_RD(ser, up->regi_ser, rw_tr_dma_en);
if (tr_dma_en.en == regk_ser_yes) {
tr_dma_en.en = regk_ser_no;
REG_WR(ser, up->regi_ser, rw_tr_dma_en, tr_dma_en);
}
for (i = 0; i < count; i++) {
if (s[i] == '\n') {
do {
stat = REG_RD(ser, up->regi_ser, r_stat_din);
} while (!stat.tr_rdy);
REG_WR_INT(ser, up->regi_ser, rw_dout, '\r');
}
do {
stat = REG_RD(ser, up->regi_ser, r_stat_din);
} while (!stat.tr_rdy);
REG_WR_INT(ser, up->regi_ser, rw_dout, s[i]);
}
if (tr_dma_en.en != old.en)
REG_WR(ser, up->regi_ser, rw_tr_dma_en, old);
}
static int __init
cris_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= UART_NR)
co->index = 0;
port = &etraxfs_uart_ports[co->index]->port;
console_port = port;
co->flags |= CON_CONSDEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
console_baud = baud;
cris_serial_port_init(port, co->index);
uart_set_options(port, co, baud, parity, bits, flow);
return 0;
}
static inline int crisv32_serial_get_rts(struct uart_cris_port *up)
{
void __iomem *regi_ser = up->regi_ser;
reg_ser_r_stat_din rstat = REG_RD(ser, regi_ser, r_stat_din);
return !(rstat.rts_n == regk_ser_active);
}
static inline void crisv32_serial_set_rts(struct uart_cris_port *up,
int set, int force)
{
void __iomem *regi_ser = up->regi_ser;
unsigned long flags;
reg_ser_rw_rec_ctrl rec_ctrl;
local_irq_save(flags);
rec_ctrl = REG_RD(ser, regi_ser, rw_rec_ctrl);
if (set)
rec_ctrl.rts_n = regk_ser_active;
else
rec_ctrl.rts_n = regk_ser_inactive;
REG_WR(ser, regi_ser, rw_rec_ctrl, rec_ctrl);
local_irq_restore(flags);
}
static inline int crisv32_serial_get_cts(struct uart_cris_port *up)
{
void __iomem *regi_ser = up->regi_ser;
reg_ser_r_stat_din rstat = REG_RD(ser, regi_ser, r_stat_din);
return (rstat.cts_n == regk_ser_active);
}
static void etraxfs_uart_send_xchar(struct uart_port *port, char ch)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
reg_ser_rw_dout dout = { .data = ch };
reg_ser_rw_ack_intr ack_intr = { .tr_rdy = regk_ser_yes };
reg_ser_r_stat_din rstat;
reg_ser_rw_tr_ctrl prev_tr_ctrl, tr_ctrl;
void __iomem *regi_ser = up->regi_ser;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
do {
spin_unlock_irqrestore(&port->lock, flags);
spin_lock_irqsave(&port->lock, flags);
prev_tr_ctrl = tr_ctrl = REG_RD(ser, regi_ser, rw_tr_ctrl);
rstat = REG_RD(ser, regi_ser, r_stat_din);
} while (!rstat.tr_rdy);
REG_WR(ser, regi_ser, rw_ack_intr, ack_intr);
tr_ctrl.stop = 0;
REG_WR(ser, regi_ser, rw_tr_ctrl, tr_ctrl);
REG_WR(ser, regi_ser, rw_dout, dout);
up->port.icount.tx++;
rstat = REG_RD(ser, up->regi_ser, r_stat_din);
if (rstat.xoff_detect) {
reg_ser_rw_xoff_clr xoff_clr = { .clr = 1 };
reg_ser_rw_tr_dma_en tr_dma_en;
REG_WR(ser, regi_ser, rw_xoff_clr, xoff_clr);
tr_dma_en = REG_RD(ser, regi_ser, rw_tr_dma_en);
prev_tr_ctrl.stop = 1;
tr_dma_en.en = 0;
REG_WR(ser, regi_ser, rw_tr_dma_en, tr_dma_en);
}
REG_WR(ser, regi_ser, rw_tr_ctrl, prev_tr_ctrl);
spin_unlock_irqrestore(&port->lock, flags);
}
static void etraxfs_uart_start_tx(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
if (up->write_ongoing)
return;
up->write_ongoing = 1;
etraxfs_uart_start_tx_bottom(port);
}
static inline void etraxfs_uart_start_tx_bottom(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
void __iomem *regi_ser = up->regi_ser;
reg_ser_rw_tr_ctrl tr_ctrl;
reg_ser_rw_intr_mask intr_mask;
tr_ctrl = REG_RD(ser, regi_ser, rw_tr_ctrl);
tr_ctrl.stop = regk_ser_no;
REG_WR(ser, regi_ser, rw_tr_ctrl, tr_ctrl);
intr_mask = REG_RD(ser, regi_ser, rw_intr_mask);
intr_mask.tr_rdy = regk_ser_yes;
REG_WR(ser, regi_ser, rw_intr_mask, intr_mask);
}
static void etraxfs_uart_stop_tx(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
void __iomem *regi_ser = up->regi_ser;
reg_ser_rw_tr_ctrl tr_ctrl;
reg_ser_rw_intr_mask intr_mask;
reg_ser_rw_tr_dma_en tr_dma_en = {0};
reg_ser_rw_xoff_clr xoff_clr = {0};
intr_mask = REG_RD(ser, regi_ser, rw_intr_mask);
intr_mask.tr_rdy = regk_ser_no;
REG_WR(ser, regi_ser, rw_intr_mask, intr_mask);
tr_ctrl = REG_RD(ser, regi_ser, rw_tr_ctrl);
tr_ctrl.stop = 1;
REG_WR(ser, regi_ser, rw_tr_ctrl, tr_ctrl);
xoff_clr.clr = 1;
REG_WR(ser, regi_ser, rw_xoff_clr, xoff_clr);
tr_dma_en.en = 0;
REG_WR(ser, regi_ser, rw_tr_dma_en, tr_dma_en);
up->write_ongoing = 0;
}
static void etraxfs_uart_stop_rx(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
void __iomem *regi_ser = up->regi_ser;
reg_ser_rw_rec_ctrl rec_ctrl = REG_RD(ser, regi_ser, rw_rec_ctrl);
rec_ctrl.en = regk_ser_no;
REG_WR(ser, regi_ser, rw_rec_ctrl, rec_ctrl);
}
static unsigned int etraxfs_uart_tx_empty(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned long flags;
unsigned int ret;
reg_ser_r_stat_din rstat = {0};
spin_lock_irqsave(&up->port.lock, flags);
rstat = REG_RD(ser, up->regi_ser, r_stat_din);
ret = rstat.tr_empty ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int etraxfs_uart_get_mctrl(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned int ret;
ret = 0;
if (crisv32_serial_get_rts(up))
ret |= TIOCM_RTS;
if (crisv32_serial_get_cts(up))
ret |= TIOCM_CTS;
return mctrl_gpio_get(up->gpios, &ret);
}
static void etraxfs_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
crisv32_serial_set_rts(up, mctrl & TIOCM_RTS ? 1 : 0, 0);
mctrl_gpio_set(up->gpios, mctrl);
}
static void etraxfs_uart_break_ctl(struct uart_port *port, int break_state)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned long flags;
reg_ser_rw_tr_ctrl tr_ctrl;
reg_ser_rw_tr_dma_en tr_dma_en;
reg_ser_rw_intr_mask intr_mask;
spin_lock_irqsave(&up->port.lock, flags);
tr_ctrl = REG_RD(ser, up->regi_ser, rw_tr_ctrl);
tr_dma_en = REG_RD(ser, up->regi_ser, rw_tr_dma_en);
intr_mask = REG_RD(ser, up->regi_ser, rw_intr_mask);
if (break_state != 0) {
intr_mask.tr_rdy = regk_ser_no;
tr_dma_en.en = 0;
tr_ctrl.stop = 1;
tr_ctrl.txd = 0;
} else {
intr_mask.tr_rdy = regk_ser_yes;
tr_ctrl.stop = 0;
tr_ctrl.txd = 1;
}
REG_WR(ser, up->regi_ser, rw_tr_ctrl, tr_ctrl);
REG_WR(ser, up->regi_ser, rw_tr_dma_en, tr_dma_en);
REG_WR(ser, up->regi_ser, rw_intr_mask, intr_mask);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
transmit_chars_no_dma(struct uart_cris_port *up)
{
int max_count;
struct circ_buf *xmit = &up->port.state->xmit;
void __iomem *regi_ser = up->regi_ser;
reg_ser_r_stat_din rstat;
reg_ser_rw_ack_intr ack_intr = { .tr_rdy = regk_ser_yes };
if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
reg_ser_rw_intr_mask intr_mask;
intr_mask = REG_RD(ser, regi_ser, rw_intr_mask);
intr_mask.tr_rdy = 0;
intr_mask.tr_empty = 0;
REG_WR(ser, regi_ser, rw_intr_mask, intr_mask);
up->write_ongoing = 0;
return;
}
max_count = 64;
do {
reg_ser_rw_dout dout = { .data = xmit->buf[xmit->tail] };
REG_WR(ser, regi_ser, rw_dout, dout);
REG_WR(ser, regi_ser, rw_ack_intr, ack_intr);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE-1);
up->port.icount.tx++;
if (xmit->head == xmit->tail)
break;
rstat = REG_RD(ser, regi_ser, r_stat_din);
} while ((--max_count > 0) && rstat.tr_rdy);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
}
static void receive_chars_no_dma(struct uart_cris_port *up)
{
reg_ser_rs_stat_din stat_din;
reg_ser_r_stat_din rstat;
struct tty_port *port;
struct uart_icount *icount;
int max_count = 16;
char flag;
reg_ser_rw_ack_intr ack_intr = { 0 };
rstat = REG_RD(ser, up->regi_ser, r_stat_din);
icount = &up->port.icount;
port = &up->port.state->port;
do {
stat_din = REG_RD(ser, up->regi_ser, rs_stat_din);
flag = TTY_NORMAL;
ack_intr.dav = 1;
REG_WR(ser, up->regi_ser, rw_ack_intr, ack_intr);
icount->rx++;
if (stat_din.framing_err | stat_din.par_err | stat_din.orun) {
if (stat_din.data == 0x00 &&
stat_din.framing_err) {
flag = TTY_BREAK;
icount->brk++;
} else if (stat_din.par_err) {
flag = TTY_PARITY;
icount->parity++;
} else if (stat_din.orun) {
flag = TTY_OVERRUN;
icount->overrun++;
} else if (stat_din.framing_err) {
flag = TTY_FRAME;
icount->frame++;
}
}
if (!tty_insert_flip_char(port, stat_din.data, flag))
panic("%s: No tty buffer space", __func__);
rstat = REG_RD(ser, up->regi_ser, r_stat_din);
} while (rstat.dav && (max_count-- > 0));
spin_unlock(&up->port.lock);
tty_flip_buffer_push(port);
spin_lock(&up->port.lock);
}
static irqreturn_t
ser_interrupt(int irq, void *dev_id)
{
struct uart_cris_port *up = (struct uart_cris_port *)dev_id;
void __iomem *regi_ser;
int handled = 0;
spin_lock(&up->port.lock);
regi_ser = up->regi_ser;
if (regi_ser) {
reg_ser_r_masked_intr masked_intr;
masked_intr = REG_RD(ser, regi_ser, r_masked_intr);
if (masked_intr.dav) {
receive_chars_no_dma(up);
handled = 1;
}
if (masked_intr.tr_rdy) {
transmit_chars_no_dma(up);
handled = 1;
}
}
spin_unlock(&up->port.lock);
return IRQ_RETVAL(handled);
}
static int etraxfs_uart_get_poll_char(struct uart_port *port)
{
reg_ser_rs_stat_din stat;
reg_ser_rw_ack_intr ack_intr = { 0 };
struct uart_cris_port *up = (struct uart_cris_port *)port;
do {
stat = REG_RD(ser, up->regi_ser, rs_stat_din);
} while (!stat.dav);
ack_intr.dav = 1;
REG_WR(ser, up->regi_ser, rw_ack_intr, ack_intr);
return stat.data;
}
static void etraxfs_uart_put_poll_char(struct uart_port *port,
unsigned char c)
{
reg_ser_r_stat_din stat;
struct uart_cris_port *up = (struct uart_cris_port *)port;
do {
stat = REG_RD(ser, up->regi_ser, r_stat_din);
} while (!stat.tr_rdy);
REG_WR_INT(ser, up->regi_ser, rw_dout, c);
}
static int etraxfs_uart_startup(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned long flags;
reg_ser_rw_intr_mask ser_intr_mask = {0};
ser_intr_mask.dav = regk_ser_yes;
if (request_irq(etraxfs_uart_ports[port->line]->irq, ser_interrupt,
0, DRV_NAME, etraxfs_uart_ports[port->line]))
panic("irq ser%d", port->line);
spin_lock_irqsave(&up->port.lock, flags);
REG_WR(ser, up->regi_ser, rw_intr_mask, ser_intr_mask);
etraxfs_uart_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
return 0;
}
static void etraxfs_uart_shutdown(struct uart_port *port)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
etraxfs_uart_stop_tx(port);
etraxfs_uart_stop_rx(port);
free_irq(etraxfs_uart_ports[port->line]->irq,
etraxfs_uart_ports[port->line]);
etraxfs_uart_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
etraxfs_uart_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
unsigned long flags;
reg_ser_rw_xoff xoff;
reg_ser_rw_xoff_clr xoff_clr = {0};
reg_ser_rw_tr_ctrl tx_ctrl = {0};
reg_ser_rw_tr_dma_en tx_dma_en = {0};
reg_ser_rw_rec_ctrl rx_ctrl = {0};
reg_ser_rw_tr_baud_div tx_baud_div = {0};
reg_ser_rw_rec_baud_div rx_baud_div = {0};
int baud;
if (old &&
termios->c_cflag == old->c_cflag &&
termios->c_iflag == old->c_iflag)
return;
tx_ctrl.base_freq = regk_ser_f29_493;
tx_ctrl.en = 0;
tx_ctrl.stop = 0;
tx_ctrl.auto_rts = regk_ser_no;
tx_ctrl.txd = 1;
tx_ctrl.auto_cts = 0;
rx_ctrl.dma_err = regk_ser_stop;
rx_ctrl.sampling = regk_ser_majority;
rx_ctrl.timeout = 1;
rx_ctrl.rts_n = regk_ser_inactive;
tx_ctrl.data_bits = regk_ser_bits8;
rx_ctrl.data_bits = regk_ser_bits8;
tx_ctrl.par = regk_ser_even;
rx_ctrl.par = regk_ser_even;
tx_ctrl.par_en = regk_ser_no;
rx_ctrl.par_en = regk_ser_no;
tx_ctrl.stop_bits = regk_ser_bits1;
if ((port != console_port) || old)
baud = uart_get_baud_rate(port, termios, old, 0,
port->uartclk / 8);
else
baud = console_baud;
tx_baud_div.div = 29493000 / (8 * baud);
rx_baud_div.div = tx_baud_div.div;
rx_ctrl.base_freq = tx_ctrl.base_freq;
if ((termios->c_cflag & CSIZE) == CS7) {
tx_ctrl.data_bits = regk_ser_bits7;
rx_ctrl.data_bits = regk_ser_bits7;
}
if (termios->c_cflag & CSTOPB) {
tx_ctrl.stop_bits = regk_ser_bits2;
}
if (termios->c_cflag & PARENB) {
tx_ctrl.par_en = regk_ser_yes;
rx_ctrl.par_en = regk_ser_yes;
}
if (termios->c_cflag & CMSPAR) {
if (termios->c_cflag & PARODD) {
tx_ctrl.par = regk_ser_mark;
rx_ctrl.par = regk_ser_mark;
} else {
tx_ctrl.par = regk_ser_space;
rx_ctrl.par = regk_ser_space;
}
} else {
if (termios->c_cflag & PARODD) {
tx_ctrl.par = regk_ser_odd;
rx_ctrl.par = regk_ser_odd;
}
}
if (termios->c_cflag & CRTSCTS) {
tx_ctrl.auto_cts = regk_ser_yes;
}
tx_ctrl.en = regk_ser_yes;
rx_ctrl.en = regk_ser_yes;
spin_lock_irqsave(&port->lock, flags);
tx_dma_en.en = 0;
REG_WR(ser, up->regi_ser, rw_tr_dma_en, tx_dma_en);
uart_update_timeout(port, termios->c_cflag, port->uartclk/8);
MODIFY_REG(up->regi_ser, rw_rec_baud_div, rx_baud_div);
MODIFY_REG(up->regi_ser, rw_rec_ctrl, rx_ctrl);
MODIFY_REG(up->regi_ser, rw_tr_baud_div, tx_baud_div);
MODIFY_REG(up->regi_ser, rw_tr_ctrl, tx_ctrl);
tx_dma_en.en = 0;
REG_WR(ser, up->regi_ser, rw_tr_dma_en, tx_dma_en);
xoff = REG_RD(ser, up->regi_ser, rw_xoff);
if (up->port.state && up->port.state->port.tty &&
(up->port.state->port.tty->termios.c_iflag & IXON)) {
xoff.chr = STOP_CHAR(up->port.state->port.tty);
xoff.automatic = regk_ser_yes;
} else
xoff.automatic = regk_ser_no;
MODIFY_REG(up->regi_ser, rw_xoff, xoff);
xoff_clr.clr = 1;
REG_WR(ser, up->regi_ser, rw_xoff_clr, xoff_clr);
etraxfs_uart_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static const char *
etraxfs_uart_type(struct uart_port *port)
{
return "CRISv32";
}
static void etraxfs_uart_release_port(struct uart_port *port)
{
}
static int etraxfs_uart_request_port(struct uart_port *port)
{
return 0;
}
static void etraxfs_uart_config_port(struct uart_port *port, int flags)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
up->port.type = PORT_CRIS;
}
static void cris_serial_port_init(struct uart_port *port, int line)
{
struct uart_cris_port *up = (struct uart_cris_port *)port;
if (up->initialized)
return;
up->initialized = 1;
port->line = line;
spin_lock_init(&port->lock);
port->ops = &etraxfs_uart_pops;
port->irq = up->irq;
port->iobase = (unsigned long) up->regi_ser;
port->uartclk = 29493000;
port->fifosize = 255;
port->flags = UPF_BOOT_AUTOCONF;
}
static int etraxfs_uart_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct uart_cris_port *up;
int dev_id;
if (!np)
return -ENODEV;
dev_id = of_alias_get_id(np, "serial");
if (dev_id < 0)
dev_id = 0;
if (dev_id >= UART_NR)
return -EINVAL;
if (etraxfs_uart_ports[dev_id])
return -EBUSY;
up = devm_kzalloc(&pdev->dev, sizeof(struct uart_cris_port),
GFP_KERNEL);
if (!up)
return -ENOMEM;
up->irq = irq_of_parse_and_map(np, 0);
up->regi_ser = of_iomap(np, 0);
up->port.dev = &pdev->dev;
up->gpios = mctrl_gpio_init(&pdev->dev, 0);
if (IS_ERR(up->gpios))
return PTR_ERR(up->gpios);
cris_serial_port_init(&up->port, dev_id);
etraxfs_uart_ports[dev_id] = up;
platform_set_drvdata(pdev, &up->port);
uart_add_one_port(&etraxfs_uart_driver, &up->port);
return 0;
}
static int etraxfs_uart_remove(struct platform_device *pdev)
{
struct uart_port *port;
port = platform_get_drvdata(pdev);
uart_remove_one_port(&etraxfs_uart_driver, port);
etraxfs_uart_ports[port->line] = NULL;
return 0;
}
static int __init etraxfs_uart_init(void)
{
int ret;
ret = uart_register_driver(&etraxfs_uart_driver);
if (ret)
return ret;
ret = platform_driver_register(&etraxfs_uart_platform_driver);
if (ret)
uart_unregister_driver(&etraxfs_uart_driver);
return ret;
}
static void __exit etraxfs_uart_exit(void)
{
platform_driver_unregister(&etraxfs_uart_platform_driver);
uart_unregister_driver(&etraxfs_uart_driver);
}
