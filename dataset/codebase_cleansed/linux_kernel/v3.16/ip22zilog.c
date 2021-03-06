static unsigned char read_zsreg(struct zilog_channel *channel,
unsigned char reg)
{
unsigned char retval;
writeb(reg, &channel->control);
ZSDELAY();
retval = readb(&channel->control);
ZSDELAY();
return retval;
}
static void write_zsreg(struct zilog_channel *channel,
unsigned char reg, unsigned char value)
{
writeb(reg, &channel->control);
ZSDELAY();
writeb(value, &channel->control);
ZSDELAY();
}
static void ip22zilog_clear_fifo(struct zilog_channel *channel)
{
int i;
for (i = 0; i < 32; i++) {
unsigned char regval;
regval = readb(&channel->control);
ZSDELAY();
if (regval & Rx_CH_AV)
break;
regval = read_zsreg(channel, R1);
readb(&channel->data);
ZSDELAY();
if (regval & (PAR_ERR | Rx_OVR | CRC_ERR)) {
writeb(ERR_RES, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
}
}
}
static void __load_zsregs(struct zilog_channel *channel, unsigned char *regs)
{
int i;
for (i = 0; i < 1000; i++) {
unsigned char stat = read_zsreg(channel, R1);
if (stat & ALL_SNT)
break;
udelay(100);
}
writeb(ERR_RES, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
ip22zilog_clear_fifo(channel);
write_zsreg(channel, R1,
regs[R1] & ~(RxINT_MASK | TxINT_ENAB | EXT_INT_ENAB));
write_zsreg(channel, R4, regs[R4]);
write_zsreg(channel, R10, regs[R10]);
write_zsreg(channel, R3, regs[R3] & ~RxENAB);
write_zsreg(channel, R5, regs[R5] & ~TxENAB);
write_zsreg(channel, R6, regs[R6]);
write_zsreg(channel, R7, regs[R7]);
write_zsreg(channel, R14, regs[R14] & ~BRENAB);
write_zsreg(channel, R11, regs[R11]);
write_zsreg(channel, R12, regs[R12]);
write_zsreg(channel, R13, regs[R13]);
write_zsreg(channel, R14, regs[R14]);
write_zsreg(channel, R15, regs[R15]);
write_zsreg(channel, R0, RES_EXT_INT);
write_zsreg(channel, R0, RES_EXT_INT);
write_zsreg(channel, R3, regs[R3]);
write_zsreg(channel, R5, regs[R5]);
write_zsreg(channel, R1, regs[R1]);
}
static void ip22zilog_maybe_update_regs(struct uart_ip22zilog_port *up,
struct zilog_channel *channel)
{
if (!ZS_REGS_HELD(up)) {
if (ZS_TX_ACTIVE(up)) {
up->flags |= IP22ZILOG_FLAG_REGS_HELD;
} else {
__load_zsregs(channel, up->curregs);
}
}
}
static bool ip22zilog_receive_chars(struct uart_ip22zilog_port *up,
struct zilog_channel *channel)
{
unsigned char ch, flag;
unsigned int r1;
bool push = up->port.state != NULL;
for (;;) {
ch = readb(&channel->control);
ZSDELAY();
if (!(ch & Rx_CH_AV))
break;
r1 = read_zsreg(channel, R1);
if (r1 & (PAR_ERR | Rx_OVR | CRC_ERR)) {
writeb(ERR_RES, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
}
ch = readb(&channel->data);
ZSDELAY();
ch &= up->parity_mask;
if (!ch)
r1 |= up->tty_break;
flag = TTY_NORMAL;
up->port.icount.rx++;
if (r1 & (PAR_ERR | Rx_OVR | CRC_ERR | Rx_SYS | Rx_BRK)) {
up->tty_break = 0;
if (r1 & (Rx_SYS | Rx_BRK)) {
up->port.icount.brk++;
if (r1 & Rx_SYS)
continue;
r1 &= ~(PAR_ERR | CRC_ERR);
}
else if (r1 & PAR_ERR)
up->port.icount.parity++;
else if (r1 & CRC_ERR)
up->port.icount.frame++;
if (r1 & Rx_OVR)
up->port.icount.overrun++;
r1 &= up->port.read_status_mask;
if (r1 & Rx_BRK)
flag = TTY_BREAK;
else if (r1 & PAR_ERR)
flag = TTY_PARITY;
else if (r1 & CRC_ERR)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
continue;
if (push)
uart_insert_char(&up->port, r1, Rx_OVR, ch, flag);
}
return push;
}
static void ip22zilog_status_handle(struct uart_ip22zilog_port *up,
struct zilog_channel *channel)
{
unsigned char status;
status = readb(&channel->control);
ZSDELAY();
writeb(RES_EXT_INT, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
if (up->curregs[R15] & BRKIE) {
if ((status & BRK_ABRT) && !(up->prev_status & BRK_ABRT)) {
if (uart_handle_break(&up->port))
up->tty_break = Rx_SYS;
else
up->tty_break = Rx_BRK;
}
}
if (ZS_WANTS_MODEM_STATUS(up)) {
if (status & SYNC)
up->port.icount.dsr++;
if ((status ^ up->prev_status) ^ DCD)
uart_handle_dcd_change(&up->port,
(status & DCD));
if ((status ^ up->prev_status) ^ CTS)
uart_handle_cts_change(&up->port,
(status & CTS));
wake_up_interruptible(&up->port.state->port.delta_msr_wait);
}
up->prev_status = status;
}
static void ip22zilog_transmit_chars(struct uart_ip22zilog_port *up,
struct zilog_channel *channel)
{
struct circ_buf *xmit;
if (ZS_IS_CONS(up)) {
unsigned char status = readb(&channel->control);
ZSDELAY();
if (!(status & Tx_BUF_EMP))
return;
}
up->flags &= ~IP22ZILOG_FLAG_TX_ACTIVE;
if (ZS_REGS_HELD(up)) {
__load_zsregs(channel, up->curregs);
up->flags &= ~IP22ZILOG_FLAG_REGS_HELD;
}
if (ZS_TX_STOPPED(up)) {
up->flags &= ~IP22ZILOG_FLAG_TX_STOPPED;
goto ack_tx_int;
}
if (up->port.x_char) {
up->flags |= IP22ZILOG_FLAG_TX_ACTIVE;
writeb(up->port.x_char, &channel->data);
ZSDELAY();
ZS_WSYNC(channel);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (up->port.state == NULL)
goto ack_tx_int;
xmit = &up->port.state->xmit;
if (uart_circ_empty(xmit))
goto ack_tx_int;
if (uart_tx_stopped(&up->port))
goto ack_tx_int;
up->flags |= IP22ZILOG_FLAG_TX_ACTIVE;
writeb(xmit->buf[xmit->tail], &channel->data);
ZSDELAY();
ZS_WSYNC(channel);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
return;
ack_tx_int:
writeb(RES_Tx_P, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
}
static irqreturn_t ip22zilog_interrupt(int irq, void *dev_id)
{
struct uart_ip22zilog_port *up = dev_id;
while (up) {
struct zilog_channel *channel
= ZILOG_CHANNEL_FROM_PORT(&up->port);
unsigned char r3;
bool push = false;
spin_lock(&up->port.lock);
r3 = read_zsreg(channel, R3);
if (r3 & (CHAEXT | CHATxIP | CHARxIP)) {
writeb(RES_H_IUS, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
if (r3 & CHARxIP)
push = ip22zilog_receive_chars(up, channel);
if (r3 & CHAEXT)
ip22zilog_status_handle(up, channel);
if (r3 & CHATxIP)
ip22zilog_transmit_chars(up, channel);
}
spin_unlock(&up->port.lock);
if (push)
tty_flip_buffer_push(&up->port.state->port);
up = up->next;
channel = ZILOG_CHANNEL_FROM_PORT(&up->port);
push = false;
spin_lock(&up->port.lock);
if (r3 & (CHBEXT | CHBTxIP | CHBRxIP)) {
writeb(RES_H_IUS, &channel->control);
ZSDELAY();
ZS_WSYNC(channel);
if (r3 & CHBRxIP)
push = ip22zilog_receive_chars(up, channel);
if (r3 & CHBEXT)
ip22zilog_status_handle(up, channel);
if (r3 & CHBTxIP)
ip22zilog_transmit_chars(up, channel);
}
spin_unlock(&up->port.lock);
if (push)
tty_flip_buffer_push(&up->port.state->port);
up = up->next;
}
return IRQ_HANDLED;
}
static __inline__ unsigned char ip22zilog_read_channel_status(struct uart_port *port)
{
struct zilog_channel *channel;
unsigned char status;
channel = ZILOG_CHANNEL_FROM_PORT(port);
status = readb(&channel->control);
ZSDELAY();
return status;
}
static unsigned int ip22zilog_tx_empty(struct uart_port *port)
{
unsigned long flags;
unsigned char status;
unsigned int ret;
spin_lock_irqsave(&port->lock, flags);
status = ip22zilog_read_channel_status(port);
spin_unlock_irqrestore(&port->lock, flags);
if (status & Tx_BUF_EMP)
ret = TIOCSER_TEMT;
else
ret = 0;
return ret;
}
static unsigned int ip22zilog_get_mctrl(struct uart_port *port)
{
unsigned char status;
unsigned int ret;
status = ip22zilog_read_channel_status(port);
ret = 0;
if (status & DCD)
ret |= TIOCM_CAR;
if (status & SYNC)
ret |= TIOCM_DSR;
if (status & CTS)
ret |= TIOCM_CTS;
return ret;
}
static void ip22zilog_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
struct zilog_channel *channel = ZILOG_CHANNEL_FROM_PORT(port);
unsigned char set_bits, clear_bits;
set_bits = clear_bits = 0;
if (mctrl & TIOCM_RTS)
set_bits |= RTS;
else
clear_bits |= RTS;
if (mctrl & TIOCM_DTR)
set_bits |= DTR;
else
clear_bits |= DTR;
up->curregs[R5] |= set_bits;
up->curregs[R5] &= ~clear_bits;
write_zsreg(channel, R5, up->curregs[R5]);
}
static void ip22zilog_stop_tx(struct uart_port *port)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
up->flags |= IP22ZILOG_FLAG_TX_STOPPED;
}
static void ip22zilog_start_tx(struct uart_port *port)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
struct zilog_channel *channel = ZILOG_CHANNEL_FROM_PORT(port);
unsigned char status;
up->flags |= IP22ZILOG_FLAG_TX_ACTIVE;
up->flags &= ~IP22ZILOG_FLAG_TX_STOPPED;
status = readb(&channel->control);
ZSDELAY();
if (!(status & Tx_BUF_EMP))
return;
if (port->x_char) {
writeb(port->x_char, &channel->data);
ZSDELAY();
ZS_WSYNC(channel);
port->icount.tx++;
port->x_char = 0;
} else {
struct circ_buf *xmit = &port->state->xmit;
if (uart_circ_empty(xmit))
return;
writeb(xmit->buf[xmit->tail], &channel->data);
ZSDELAY();
ZS_WSYNC(channel);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
}
}
static void ip22zilog_stop_rx(struct uart_port *port)
{
struct uart_ip22zilog_port *up = UART_ZILOG(port);
struct zilog_channel *channel;
if (ZS_IS_CONS(up))
return;
channel = ZILOG_CHANNEL_FROM_PORT(port);
up->curregs[R1] &= ~RxINT_MASK;
ip22zilog_maybe_update_regs(up, channel);
}
static void ip22zilog_enable_ms(struct uart_port *port)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
struct zilog_channel *channel = ZILOG_CHANNEL_FROM_PORT(port);
unsigned char new_reg;
new_reg = up->curregs[R15] | (DCDIE | SYNCIE | CTSIE);
if (new_reg != up->curregs[R15]) {
up->curregs[R15] = new_reg;
write_zsreg(channel, R15, up->curregs[R15]);
}
}
static void ip22zilog_break_ctl(struct uart_port *port, int break_state)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
struct zilog_channel *channel = ZILOG_CHANNEL_FROM_PORT(port);
unsigned char set_bits, clear_bits, new_reg;
unsigned long flags;
set_bits = clear_bits = 0;
if (break_state)
set_bits |= SND_BRK;
else
clear_bits |= SND_BRK;
spin_lock_irqsave(&port->lock, flags);
new_reg = (up->curregs[R5] | set_bits) & ~clear_bits;
if (new_reg != up->curregs[R5]) {
up->curregs[R5] = new_reg;
write_zsreg(channel, R5, up->curregs[R5]);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static void __ip22zilog_reset(struct uart_ip22zilog_port *up)
{
struct zilog_channel *channel;
int i;
if (up->flags & IP22ZILOG_FLAG_RESET_DONE)
return;
channel = ZILOG_CHANNEL_FROM_PORT(&up->port);
for (i = 0; i < 1000; i++) {
unsigned char stat = read_zsreg(channel, R1);
if (stat & ALL_SNT)
break;
udelay(100);
}
if (!ZS_IS_CHANNEL_A(up)) {
up++;
channel = ZILOG_CHANNEL_FROM_PORT(&up->port);
}
write_zsreg(channel, R9, FHWRES);
ZSDELAY_LONG();
(void) read_zsreg(channel, R0);
up->flags |= IP22ZILOG_FLAG_RESET_DONE;
up->next->flags |= IP22ZILOG_FLAG_RESET_DONE;
}
static void __ip22zilog_startup(struct uart_ip22zilog_port *up)
{
struct zilog_channel *channel;
channel = ZILOG_CHANNEL_FROM_PORT(&up->port);
__ip22zilog_reset(up);
__load_zsregs(channel, up->curregs);
write_zsreg(channel, R9, up->curregs[R9]);
up->prev_status = readb(&channel->control);
up->curregs[R3] |= RxENAB;
up->curregs[R5] |= TxENAB;
up->curregs[R1] |= EXT_INT_ENAB | INT_ALL_Rx | TxINT_ENAB;
ip22zilog_maybe_update_regs(up, channel);
}
static int ip22zilog_startup(struct uart_port *port)
{
struct uart_ip22zilog_port *up = UART_ZILOG(port);
unsigned long flags;
if (ZS_IS_CONS(up))
return 0;
spin_lock_irqsave(&port->lock, flags);
__ip22zilog_startup(up);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static void ip22zilog_shutdown(struct uart_port *port)
{
struct uart_ip22zilog_port *up = UART_ZILOG(port);
struct zilog_channel *channel;
unsigned long flags;
if (ZS_IS_CONS(up))
return;
spin_lock_irqsave(&port->lock, flags);
channel = ZILOG_CHANNEL_FROM_PORT(port);
up->curregs[R3] &= ~RxENAB;
up->curregs[R5] &= ~TxENAB;
up->curregs[R1] &= ~(EXT_INT_ENAB | TxINT_ENAB | RxINT_MASK);
up->curregs[R5] &= ~SND_BRK;
ip22zilog_maybe_update_regs(up, channel);
spin_unlock_irqrestore(&port->lock, flags);
}
static void
ip22zilog_convert_to_zs(struct uart_ip22zilog_port *up, unsigned int cflag,
unsigned int iflag, int brg)
{
up->curregs[R10] = NRZ;
up->curregs[R11] = TCBR | RCBR;
up->curregs[R4] &= ~XCLK_MASK;
up->curregs[R4] |= X16CLK;
up->curregs[R12] = brg & 0xff;
up->curregs[R13] = (brg >> 8) & 0xff;
up->curregs[R14] = BRENAB;
up->curregs[3] &= ~RxN_MASK;
up->curregs[5] &= ~TxN_MASK;
switch (cflag & CSIZE) {
case CS5:
up->curregs[3] |= Rx5;
up->curregs[5] |= Tx5;
up->parity_mask = 0x1f;
break;
case CS6:
up->curregs[3] |= Rx6;
up->curregs[5] |= Tx6;
up->parity_mask = 0x3f;
break;
case CS7:
up->curregs[3] |= Rx7;
up->curregs[5] |= Tx7;
up->parity_mask = 0x7f;
break;
case CS8:
default:
up->curregs[3] |= Rx8;
up->curregs[5] |= Tx8;
up->parity_mask = 0xff;
break;
}
up->curregs[4] &= ~0x0c;
if (cflag & CSTOPB)
up->curregs[4] |= SB2;
else
up->curregs[4] |= SB1;
if (cflag & PARENB)
up->curregs[4] |= PAR_ENAB;
else
up->curregs[4] &= ~PAR_ENAB;
if (!(cflag & PARODD))
up->curregs[4] |= PAR_EVEN;
else
up->curregs[4] &= ~PAR_EVEN;
up->port.read_status_mask = Rx_OVR;
if (iflag & INPCK)
up->port.read_status_mask |= CRC_ERR | PAR_ERR;
if (iflag & (IGNBRK | BRKINT | PARMRK))
up->port.read_status_mask |= BRK_ABRT;
up->port.ignore_status_mask = 0;
if (iflag & IGNPAR)
up->port.ignore_status_mask |= CRC_ERR | PAR_ERR;
if (iflag & IGNBRK) {
up->port.ignore_status_mask |= BRK_ABRT;
if (iflag & IGNPAR)
up->port.ignore_status_mask |= Rx_OVR;
}
if ((cflag & CREAD) == 0)
up->port.ignore_status_mask = 0xff;
}
static void
ip22zilog_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_ip22zilog_port *up = (struct uart_ip22zilog_port *) port;
unsigned long flags;
int baud, brg;
baud = uart_get_baud_rate(port, termios, old, 1200, 76800);
spin_lock_irqsave(&up->port.lock, flags);
brg = BPS_TO_BRG(baud, ZS_CLOCK / ZS_CLOCK_DIVISOR);
ip22zilog_convert_to_zs(up, termios->c_cflag, termios->c_iflag, brg);
if (UART_ENABLE_MS(&up->port, termios->c_cflag))
up->flags |= IP22ZILOG_FLAG_MODEM_STATUS;
else
up->flags &= ~IP22ZILOG_FLAG_MODEM_STATUS;
ip22zilog_maybe_update_regs(up, ZILOG_CHANNEL_FROM_PORT(port));
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static const char *ip22zilog_type(struct uart_port *port)
{
return "IP22-Zilog";
}
static void ip22zilog_release_port(struct uart_port *port)
{
}
static int ip22zilog_request_port(struct uart_port *port)
{
return 0;
}
static void ip22zilog_config_port(struct uart_port *port, int flags)
{
}
static int ip22zilog_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static void * __init alloc_one_table(unsigned long size)
{
return kzalloc(size, GFP_KERNEL);
}
static void __init ip22zilog_alloc_tables(void)
{
ip22zilog_port_table = (struct uart_ip22zilog_port *)
alloc_one_table(NUM_CHANNELS * sizeof(struct uart_ip22zilog_port));
ip22zilog_chip_regs = (struct zilog_layout **)
alloc_one_table(NUM_IP22ZILOG * sizeof(struct zilog_layout *));
if (ip22zilog_port_table == NULL || ip22zilog_chip_regs == NULL) {
panic("IP22-Zilog: Cannot allocate IP22-Zilog tables.");
}
}
static struct zilog_layout * __init get_zs(int chip)
{
unsigned long base;
if (chip < 0 || chip >= NUM_IP22ZILOG) {
panic("IP22-Zilog: Illegal chip number %d in get_zs.", chip);
}
base = (unsigned long) &sgioc->uart;
zilog_irq = SGI_SERIAL_IRQ;
request_mem_region(base, 8, "IP22-Zilog");
return (struct zilog_layout *) base;
}
static void ip22zilog_put_char(struct uart_port *port, int ch)
{
struct zilog_channel *channel = ZILOG_CHANNEL_FROM_PORT(port);
int loops = ZS_PUT_CHAR_MAX_DELAY;
do {
unsigned char val = readb(&channel->control);
if (val & Tx_BUF_EMP) {
ZSDELAY();
break;
}
udelay(5);
} while (--loops);
writeb(ch, &channel->data);
ZSDELAY();
ZS_WSYNC(channel);
}
static void
ip22zilog_console_write(struct console *con, const char *s, unsigned int count)
{
struct uart_ip22zilog_port *up = &ip22zilog_port_table[con->index];
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
uart_console_write(&up->port, s, count, ip22zilog_put_char);
udelay(2);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int __init ip22zilog_console_setup(struct console *con, char *options)
{
struct uart_ip22zilog_port *up = &ip22zilog_port_table[con->index];
unsigned long flags;
int baud = 9600, bits = 8;
int parity = 'n';
int flow = 'n';
up->flags |= IP22ZILOG_FLAG_IS_CONS;
printk(KERN_INFO "Console: ttyS%d (IP22-Zilog)\n", con->index);
spin_lock_irqsave(&up->port.lock, flags);
up->curregs[R15] |= BRKIE;
__ip22zilog_startup(up);
spin_unlock_irqrestore(&up->port.lock, flags);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&up->port, con, baud, parity, bits, flow);
}
static void __init ip22zilog_prepare(void)
{
struct uart_ip22zilog_port *up;
struct zilog_layout *rp;
int channel, chip;
for (channel = 0; channel < NUM_CHANNELS; channel++)
spin_lock_init(&ip22zilog_port_table[channel].port.lock);
ip22zilog_irq_chain = &ip22zilog_port_table[NUM_CHANNELS - 1];
up = &ip22zilog_port_table[0];
for (channel = NUM_CHANNELS - 1 ; channel > 0; channel--)
up[channel].next = &up[channel - 1];
up[channel].next = NULL;
for (chip = 0; chip < NUM_IP22ZILOG; chip++) {
if (!ip22zilog_chip_regs[chip]) {
ip22zilog_chip_regs[chip] = rp = get_zs(chip);
up[(chip * 2) + 0].port.membase = (char *) &rp->channelB;
up[(chip * 2) + 1].port.membase = (char *) &rp->channelA;
up[(chip * 2) + 0].port.mapbase =
(unsigned long) ioremap((unsigned long) &rp->channelB, 8);
up[(chip * 2) + 1].port.mapbase =
(unsigned long) ioremap((unsigned long) &rp->channelA, 8);
}
up[(chip * 2) + 0].port.iotype = UPIO_MEM;
up[(chip * 2) + 0].port.irq = zilog_irq;
up[(chip * 2) + 0].port.uartclk = ZS_CLOCK;
up[(chip * 2) + 0].port.fifosize = 1;
up[(chip * 2) + 0].port.ops = &ip22zilog_pops;
up[(chip * 2) + 0].port.type = PORT_IP22ZILOG;
up[(chip * 2) + 0].port.flags = 0;
up[(chip * 2) + 0].port.line = (chip * 2) + 0;
up[(chip * 2) + 0].flags = 0;
up[(chip * 2) + 1].port.iotype = UPIO_MEM;
up[(chip * 2) + 1].port.irq = zilog_irq;
up[(chip * 2) + 1].port.uartclk = ZS_CLOCK;
up[(chip * 2) + 1].port.fifosize = 1;
up[(chip * 2) + 1].port.ops = &ip22zilog_pops;
up[(chip * 2) + 1].port.type = PORT_IP22ZILOG;
up[(chip * 2) + 1].port.line = (chip * 2) + 1;
up[(chip * 2) + 1].flags |= IP22ZILOG_FLAG_IS_CHANNEL_A;
}
for (channel = 0; channel < NUM_CHANNELS; channel++) {
struct uart_ip22zilog_port *up = &ip22zilog_port_table[channel];
int brg;
up->parity_mask = 0xff;
up->curregs[R1] = EXT_INT_ENAB | INT_ALL_Rx | TxINT_ENAB;
up->curregs[R4] = PAR_EVEN | X16CLK | SB1;
up->curregs[R3] = RxENAB | Rx8;
up->curregs[R5] = TxENAB | Tx8;
up->curregs[R9] = NV | MIE;
up->curregs[R10] = NRZ;
up->curregs[R11] = TCBR | RCBR;
brg = BPS_TO_BRG(9600, ZS_CLOCK / ZS_CLOCK_DIVISOR);
up->curregs[R12] = (brg & 0xff);
up->curregs[R13] = (brg >> 8) & 0xff;
up->curregs[R14] = BRENAB;
}
}
static int __init ip22zilog_ports_init(void)
{
int ret;
printk(KERN_INFO "Serial: IP22 Zilog driver (%d chips).\n", NUM_IP22ZILOG);
ip22zilog_prepare();
if (request_irq(zilog_irq, ip22zilog_interrupt, 0,
"IP22-Zilog", ip22zilog_irq_chain)) {
panic("IP22-Zilog: Unable to register zs interrupt handler.\n");
}
ret = uart_register_driver(&ip22zilog_reg);
if (ret == 0) {
int i;
for (i = 0; i < NUM_CHANNELS; i++) {
struct uart_ip22zilog_port *up = &ip22zilog_port_table[i];
uart_add_one_port(&ip22zilog_reg, &up->port);
}
}
return ret;
}
static int __init ip22zilog_init(void)
{
ip22zilog_alloc_tables();
ip22zilog_ports_init();
return 0;
}
static void __exit ip22zilog_exit(void)
{
int i;
struct uart_ip22zilog_port *up;
for (i = 0; i < NUM_CHANNELS; i++) {
up = &ip22zilog_port_table[i];
uart_remove_one_port(&ip22zilog_reg, &up->port);
}
up = &ip22zilog_port_table[0];
for (i = 0; i < NUM_IP22ZILOG; i++) {
if (up[(i * 2) + 0].port.mapbase) {
iounmap((void*)up[(i * 2) + 0].port.mapbase);
up[(i * 2) + 0].port.mapbase = 0;
}
if (up[(i * 2) + 1].port.mapbase) {
iounmap((void*)up[(i * 2) + 1].port.mapbase);
up[(i * 2) + 1].port.mapbase = 0;
}
}
uart_unregister_driver(&ip22zilog_reg);
}
