static inline int sx_paranoia_check(struct sx_port const *port,
char *name, const char *routine)
{
static const char *badmagic = KERN_ERR "sx: Warning: bad sx port magic "
"number for device %s in %s\n";
static const char *badinfo = KERN_ERR "sx: Warning: null sx port for "
"device %s in %s\n";
if (!port) {
printk(badinfo, name, routine);
return 1;
}
if (port->magic != SX_MAGIC) {
printk(badmagic, name, routine);
return 1;
}
return 0;
}
static void my_hd_io(void __iomem *p, int len)
{
int i, j, ch;
unsigned char __iomem *addr = p;
for (i = 0; i < len; i += 16) {
printk("%p ", addr + i);
for (j = 0; j < 16; j++) {
printk("%02x %s", readb(addr + j + i),
(j == 7) ? " " : "");
}
for (j = 0; j < 16; j++) {
ch = readb(addr + j + i);
printk("%c", (ch < 0x20) ? '.' :
((ch > 0x7f) ? '.' : ch));
}
printk("\n");
}
}
static void my_hd(void *p, int len)
{
int i, j, ch;
unsigned char *addr = p;
for (i = 0; i < len; i += 16) {
printk("%p ", addr + i);
for (j = 0; j < 16; j++) {
printk("%02x %s", addr[j + i], (j == 7) ? " " : "");
}
for (j = 0; j < 16; j++) {
ch = addr[j + i];
printk("%c", (ch < 0x20) ? '.' :
((ch > 0x7f) ? '.' : ch));
}
printk("\n");
}
}
static inline void write_sx_byte(struct sx_board *board, int offset, u8 byte)
{
writeb(byte, board->base + offset);
}
static inline u8 read_sx_byte(struct sx_board *board, int offset)
{
return readb(board->base + offset);
}
static inline void write_sx_word(struct sx_board *board, int offset, u16 word)
{
writew(word, board->base + offset);
}
static inline u16 read_sx_word(struct sx_board *board, int offset)
{
return readw(board->base + offset);
}
static int sx_busy_wait_eq(struct sx_board *board,
int offset, int mask, int correctval)
{
int i;
func_enter();
for (i = 0; i < TIMEOUT_1; i++)
if ((read_sx_byte(board, offset) & mask) == correctval) {
func_exit();
return 1;
}
for (i = 0; i < TIMEOUT_2; i++) {
if ((read_sx_byte(board, offset) & mask) == correctval) {
func_exit();
return 1;
}
udelay(1);
}
func_exit();
return 0;
}
static int sx_busy_wait_neq(struct sx_board *board,
int offset, int mask, int badval)
{
int i;
func_enter();
for (i = 0; i < TIMEOUT_1; i++)
if ((read_sx_byte(board, offset) & mask) != badval) {
func_exit();
return 1;
}
for (i = 0; i < TIMEOUT_2; i++) {
if ((read_sx_byte(board, offset) & mask) != badval) {
func_exit();
return 1;
}
udelay(1);
}
func_exit();
return 0;
}
static int sx_reset(struct sx_board *board)
{
func_enter();
if (IS_SX_BOARD(board)) {
write_sx_byte(board, SX_CONFIG, 0);
write_sx_byte(board, SX_RESET, 1);
if (!sx_busy_wait_eq(board, SX_RESET_STATUS, 1, 0)) {
printk(KERN_INFO "sx: Card doesn't respond to "
"reset...\n");
return 0;
}
} else if (IS_EISA_BOARD(board)) {
outb(board->irq << 4, board->eisa_base + 0xc02);
} else if (IS_SI1_BOARD(board)) {
write_sx_byte(board, SI1_ISA_RESET, 0);
} else {
write_sx_byte(board, SI2_ISA_RESET, SI2_ISA_RESET_SET);
write_sx_byte(board, SI2_ISA_IRQ11, SI2_ISA_IRQ11_CLEAR);
write_sx_byte(board, SI2_ISA_IRQ12, SI2_ISA_IRQ12_CLEAR);
write_sx_byte(board, SI2_ISA_IRQ15, SI2_ISA_IRQ15_CLEAR);
write_sx_byte(board, SI2_ISA_INTCLEAR, SI2_ISA_INTCLEAR_CLEAR);
write_sx_byte(board, SI2_ISA_IRQSET, SI2_ISA_IRQSET_CLEAR);
}
func_exit();
return 1;
}
static int sx_start_board(struct sx_board *board)
{
if (IS_SX_BOARD(board)) {
write_sx_byte(board, SX_CONFIG, SX_CONF_BUSEN);
} else if (IS_EISA_BOARD(board)) {
write_sx_byte(board, SI2_EISA_OFF, SI2_EISA_VAL);
outb((board->irq << 4) | 4, board->eisa_base + 0xc02);
} else if (IS_SI1_BOARD(board)) {
write_sx_byte(board, SI1_ISA_RESET_CLEAR, 0);
write_sx_byte(board, SI1_ISA_INTCL, 0);
} else {
write_sx_byte(board, SI2_ISA_RESET, SI2_ISA_RESET_CLEAR);
write_sx_byte(board, SI2_ISA_INTCLEAR, SI2_ISA_INTCLEAR_SET);
}
return 1;
}
static int sx_start_interrupts(struct sx_board *board)
{
if (IS_SX_BOARD(board)) {
write_sx_byte(board, SX_CONFIG, SX_IRQ_REG_VAL(board) |
SX_CONF_BUSEN | SX_CONF_HOSTIRQ);
} else if (IS_EISA_BOARD(board)) {
inb(board->eisa_base + 0xc03);
} else if (IS_SI1_BOARD(board)) {
write_sx_byte(board, SI1_ISA_INTCL, 0);
write_sx_byte(board, SI1_ISA_INTCL_CLEAR, 0);
} else {
switch (board->irq) {
case 11:
write_sx_byte(board, SI2_ISA_IRQ11, SI2_ISA_IRQ11_SET);
break;
case 12:
write_sx_byte(board, SI2_ISA_IRQ12, SI2_ISA_IRQ12_SET);
break;
case 15:
write_sx_byte(board, SI2_ISA_IRQ15, SI2_ISA_IRQ15_SET);
break;
default:
printk(KERN_INFO "sx: SI/XIO card doesn't support "
"interrupt %d.\n", board->irq);
return 0;
}
write_sx_byte(board, SI2_ISA_INTCLEAR, SI2_ISA_INTCLEAR_SET);
}
return 1;
}
static int sx_send_command(struct sx_port *port,
int command, int mask, int newstat)
{
func_enter2();
write_sx_byte(port->board, CHAN_OFFSET(port, hi_hstat), command);
func_exit();
return sx_busy_wait_eq(port->board, CHAN_OFFSET(port, hi_hstat), mask,
newstat);
}
static char *mod_type_s(int module_type)
{
switch (module_type) {
case TA4:
return "TA4";
case TA8:
return "TA8";
case TA4_ASIC:
return "TA4_ASIC";
case TA8_ASIC:
return "TA8_ASIC";
case MTA_CD1400:
return "MTA_CD1400";
case SXDC:
return "SXDC";
default:
return "Unknown/invalid";
}
}
static char *pan_type_s(int pan_type)
{
switch (pan_type) {
case MOD_RS232DB25:
return "MOD_RS232DB25";
case MOD_RS232RJ45:
return "MOD_RS232RJ45";
case MOD_RS422DB25:
return "MOD_RS422DB25";
case MOD_PARALLEL:
return "MOD_PARALLEL";
case MOD_2_RS232DB25:
return "MOD_2_RS232DB25";
case MOD_2_RS232RJ45:
return "MOD_2_RS232RJ45";
case MOD_2_RS422DB25:
return "MOD_2_RS422DB25";
case MOD_RS232DB25MALE:
return "MOD_RS232DB25MALE";
case MOD_2_PARALLEL:
return "MOD_2_PARALLEL";
case MOD_BLANK:
return "empty";
default:
return "invalid";
}
}
static int mod_compat_type(int module_type)
{
return module_type >> 4;
}
static void sx_reconfigure_port(struct sx_port *port)
{
if (sx_read_channel_byte(port, hi_hstat) == HS_IDLE_OPEN) {
if (sx_send_command(port, HS_CONFIG, -1, HS_IDLE_OPEN) != 1) {
printk(KERN_WARNING "sx: Sent reconfigure command, but "
"card didn't react.\n");
}
} else {
sx_dprintk(SX_DEBUG_TERMIOS, "sx: Not sending reconfigure: "
"port isn't open (%02x).\n",
sx_read_channel_byte(port, hi_hstat));
}
}
static void sx_setsignals(struct sx_port *port, int dtr, int rts)
{
int t;
func_enter2();
t = sx_read_channel_byte(port, hi_op);
if (dtr >= 0)
t = dtr ? (t | OP_DTR) : (t & ~OP_DTR);
if (rts >= 0)
t = rts ? (t | OP_RTS) : (t & ~OP_RTS);
sx_write_channel_byte(port, hi_op, t);
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "setsignals: %d/%d\n", dtr, rts);
func_exit();
}
static int sx_getsignals(struct sx_port *port)
{
int i_stat, o_stat;
o_stat = sx_read_channel_byte(port, hi_op);
i_stat = sx_read_channel_byte(port, hi_ip);
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "getsignals: %d/%d (%d/%d) "
"%02x/%02x\n",
(o_stat & OP_DTR) != 0, (o_stat & OP_RTS) != 0,
port->c_dcd, tty_port_carrier_raised(&port->gs.port),
sx_read_channel_byte(port, hi_ip),
sx_read_channel_byte(port, hi_state));
return (((o_stat & OP_DTR) ? TIOCM_DTR : 0) |
((o_stat & OP_RTS) ? TIOCM_RTS : 0) |
((i_stat & IP_CTS) ? TIOCM_CTS : 0) |
((i_stat & IP_DCD) ? TIOCM_CAR : 0) |
((i_stat & IP_DSR) ? TIOCM_DSR : 0) |
((i_stat & IP_RI) ? TIOCM_RNG : 0));
}
static void sx_set_baud(struct sx_port *port)
{
int t;
if (port->board->ta_type == MOD_SXDC) {
switch (port->gs.baud) {
#define e(x) case x: t = BAUD_ ## x; break
e(50);
e(75);
e(110);
e(150);
e(200);
e(300);
e(600);
e(1200);
e(1800);
e(2000);
e(2400);
e(4800);
e(7200);
e(9600);
e(14400);
e(19200);
e(28800);
e(38400);
e(56000);
e(57600);
e(64000);
e(76800);
e(115200);
e(128000);
e(150000);
e(230400);
e(256000);
e(460800);
e(921600);
case 134:
t = BAUD_134_5;
break;
case 0:
t = -1;
break;
default:
t = BAUD_9600;
printk(KERN_INFO "sx: unsupported baud rate: %d.\n",
port->gs.baud);
break;
}
#undef e
if (t > 0) {
sx_setsignals(port, 1, -1);
sx_write_channel_byte(port, hi_csr, 0xff);
sx_write_channel_byte(port, hi_txbaud, t);
sx_write_channel_byte(port, hi_rxbaud, t);
} else {
sx_setsignals(port, 0, -1);
}
} else {
switch (port->gs.baud) {
#define e(x) case x: t = CSR_ ## x; break
e(75);
e(150);
e(300);
e(600);
e(1200);
e(2400);
e(4800);
e(1800);
e(9600);
e(19200);
e(57600);
e(38400);
case 110:
if (port->board->ta_type == MOD_TA) {
t = CSR_110;
break;
} else {
t = CSR_9600;
printk(KERN_INFO "sx: Unsupported baud rate: "
"%d.\n", port->gs.baud);
break;
}
case 115200:
if (port->board->ta_type == MOD_TA) {
t = CSR_9600;
printk(KERN_INFO "sx: Unsupported baud rate: "
"%d.\n", port->gs.baud);
break;
} else {
t = CSR_110;
break;
}
case 0:
t = -1;
break;
default:
t = CSR_9600;
printk(KERN_INFO "sx: Unsupported baud rate: %d.\n",
port->gs.baud);
break;
}
#undef e
if (t >= 0) {
sx_setsignals(port, 1, -1);
sx_write_channel_byte(port, hi_csr, t * 0x11);
} else {
sx_setsignals(port, 0, -1);
}
}
}
static int sx_set_real_termios(void *ptr)
{
struct sx_port *port = ptr;
func_enter2();
if (!port->gs.port.tty)
return 0;
sx_set_baud(port);
#define CFLAG port->gs.port.tty->termios->c_cflag
sx_write_channel_byte(port, hi_mr1,
(C_PARENB(port->gs.port.tty) ? MR1_WITH : MR1_NONE) |
(C_PARODD(port->gs.port.tty) ? MR1_ODD : MR1_EVEN) |
(C_CRTSCTS(port->gs.port.tty) ? MR1_RTS_RXFLOW : 0) |
(((CFLAG & CSIZE) == CS8) ? MR1_8_BITS : 0) |
(((CFLAG & CSIZE) == CS7) ? MR1_7_BITS : 0) |
(((CFLAG & CSIZE) == CS6) ? MR1_6_BITS : 0) |
(((CFLAG & CSIZE) == CS5) ? MR1_5_BITS : 0));
sx_write_channel_byte(port, hi_mr2,
(C_CRTSCTS(port->gs.port.tty) ? MR2_CTS_TXFLOW : 0) |
(C_CSTOPB(port->gs.port.tty) ? MR2_2_STOP :
MR2_1_STOP));
switch (CFLAG & CSIZE) {
case CS8:
sx_write_channel_byte(port, hi_mask, 0xff);
break;
case CS7:
sx_write_channel_byte(port, hi_mask, 0x7f);
break;
case CS6:
sx_write_channel_byte(port, hi_mask, 0x3f);
break;
case CS5:
sx_write_channel_byte(port, hi_mask, 0x1f);
break;
default:
printk(KERN_INFO "sx: Invalid wordsize: %u\n",
(unsigned int)CFLAG & CSIZE);
break;
}
sx_write_channel_byte(port, hi_prtcl,
(I_IXON(port->gs.port.tty) ? SP_TXEN : 0) |
(I_IXOFF(port->gs.port.tty) ? SP_RXEN : 0) |
(I_IXANY(port->gs.port.tty) ? SP_TANY : 0) | SP_DCEN);
sx_write_channel_byte(port, hi_break,
(I_IGNBRK(port->gs.port.tty) ? BR_IGN : 0 |
I_BRKINT(port->gs.port.tty) ? BR_INT : 0));
sx_write_channel_byte(port, hi_txon, START_CHAR(port->gs.port.tty));
sx_write_channel_byte(port, hi_rxon, START_CHAR(port->gs.port.tty));
sx_write_channel_byte(port, hi_txoff, STOP_CHAR(port->gs.port.tty));
sx_write_channel_byte(port, hi_rxoff, STOP_CHAR(port->gs.port.tty));
sx_reconfigure_port(port);
if (I_OTHER(port->gs.port.tty)) {
clear_bit(TTY_HW_COOK_IN, &port->gs.port.tty->flags);
} else {
set_bit(TTY_HW_COOK_IN, &port->gs.port.tty->flags);
}
sx_dprintk(SX_DEBUG_TERMIOS, "iflags: %x(%d) ",
(unsigned int)port->gs.port.tty->termios->c_iflag,
I_OTHER(port->gs.port.tty));
if (O_OPOST(port->gs.port.tty) && !O_OTHER(port->gs.port.tty)) {
set_bit(TTY_HW_COOK_OUT, &port->gs.port.tty->flags);
} else {
clear_bit(TTY_HW_COOK_OUT, &port->gs.port.tty->flags);
}
sx_dprintk(SX_DEBUG_TERMIOS, "oflags: %x(%d)\n",
(unsigned int)port->gs.port.tty->termios->c_oflag,
O_OTHER(port->gs.port.tty));
func_exit();
return 0;
}
static void sx_transmit_chars(struct sx_port *port)
{
int c;
int tx_ip;
int txroom;
func_enter2();
sx_dprintk(SX_DEBUG_TRANSMIT, "Port %p: transmit %d chars\n",
port, port->gs.xmit_cnt);
if (test_and_set_bit(SX_PORT_TRANSMIT_LOCK, &port->locks)) {
return;
}
while (1) {
c = port->gs.xmit_cnt;
sx_dprintk(SX_DEBUG_TRANSMIT, "Copying %d ", c);
tx_ip = sx_read_channel_byte(port, hi_txipos);
txroom = (sx_read_channel_byte(port, hi_txopos) - tx_ip - 1) &
0xff;
if (c > txroom)
c = txroom;
sx_dprintk(SX_DEBUG_TRANSMIT, " %d(%d) ", c, txroom);
if (c > 0x100 - tx_ip)
c = 0x100 - tx_ip;
sx_dprintk(SX_DEBUG_TRANSMIT, " %d(%d) ", c, 0x100 - tx_ip);
if (c > SERIAL_XMIT_SIZE - port->gs.xmit_tail)
c = SERIAL_XMIT_SIZE - port->gs.xmit_tail;
sx_dprintk(SX_DEBUG_TRANSMIT, " %d(%ld) \n",
c, SERIAL_XMIT_SIZE - port->gs.xmit_tail);
if (c == 0)
break;
memcpy_toio(port->board->base + CHAN_OFFSET(port, hi_txbuf) +
tx_ip, port->gs.xmit_buf + port->gs.xmit_tail, c);
sx_write_channel_byte(port, hi_txipos, (tx_ip + c) & 0xff);
port->gs.xmit_tail = (port->gs.xmit_tail + c) &
(SERIAL_XMIT_SIZE - 1);
port->gs.xmit_cnt -= c;
}
if (port->gs.xmit_cnt == 0) {
sx_disable_tx_interrupts(port);
}
if ((port->gs.xmit_cnt <= port->gs.wakeup_chars) && port->gs.port.tty) {
tty_wakeup(port->gs.port.tty);
sx_dprintk(SX_DEBUG_TRANSMIT, "Waking up.... ldisc (%d)....\n",
port->gs.wakeup_chars);
}
clear_bit(SX_PORT_TRANSMIT_LOCK, &port->locks);
func_exit();
}
static inline void sx_receive_chars(struct sx_port *port)
{
int c;
int rx_op;
struct tty_struct *tty;
int copied = 0;
unsigned char *rp;
func_enter2();
tty = port->gs.port.tty;
while (1) {
rx_op = sx_read_channel_byte(port, hi_rxopos);
c = (sx_read_channel_byte(port, hi_rxipos) - rx_op) & 0xff;
sx_dprintk(SX_DEBUG_RECEIVE, "rxop=%d, c = %d.\n", rx_op, c);
if (rx_op + c > 0x100)
c = 0x100 - rx_op;
sx_dprintk(SX_DEBUG_RECEIVE, "c = %d.\n", c);
c = tty_prepare_flip_string(tty, &rp, c);
sx_dprintk(SX_DEBUG_RECEIVE, "c = %d.\n", c);
if (c == 0)
break;
sx_dprintk(SX_DEBUG_RECEIVE, "Copying over %d chars. First is "
"%d at %lx\n", c, read_sx_byte(port->board,
CHAN_OFFSET(port, hi_rxbuf) + rx_op),
CHAN_OFFSET(port, hi_rxbuf));
memcpy_fromio(rp, port->board->base +
CHAN_OFFSET(port, hi_rxbuf) + rx_op, c);
sx_write_channel_byte(port, hi_rxopos, (rx_op + c) & 0xff);
copied += c;
}
if (copied) {
struct timeval tv;
do_gettimeofday(&tv);
sx_dprintk(SX_DEBUG_RECEIVE, "pushing flipq port %d (%3d "
"chars): %d.%06d (%d/%d)\n", port->line,
copied, (int)(tv.tv_sec % 60), (int)tv.tv_usec,
tty->raw, tty->real_raw);
tty_flip_buffer_push(tty);
}
func_exit();
}
static inline void sx_check_modem_signals(struct sx_port *port)
{
int hi_state;
int c_dcd;
hi_state = sx_read_channel_byte(port, hi_state);
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "Checking modem signals (%d/%d)\n",
port->c_dcd, tty_port_carrier_raised(&port->gs.port));
if (hi_state & ST_BREAK) {
hi_state &= ~ST_BREAK;
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "got a break.\n");
sx_write_channel_byte(port, hi_state, hi_state);
gs_got_break(&port->gs);
}
if (hi_state & ST_DCD) {
hi_state &= ~ST_DCD;
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "got a DCD change.\n");
sx_write_channel_byte(port, hi_state, hi_state);
c_dcd = tty_port_carrier_raised(&port->gs.port);
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "DCD is now %d\n", c_dcd);
if (c_dcd != port->c_dcd) {
port->c_dcd = c_dcd;
if (tty_port_carrier_raised(&port->gs.port)) {
if ((sx_read_channel_byte(port, hi_hstat) !=
HS_IDLE_CLOSED) &&
!(port->gs.port.tty->termios->
c_cflag & CLOCAL)) {
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "DCD "
"active, unblocking open\n");
wake_up_interruptible(&port->gs.port.
open_wait);
} else {
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "DCD "
"raised. Ignoring.\n");
}
} else {
if (!(port->gs.port.tty->termios->c_cflag & CLOCAL)){
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "DCD "
"dropped. hanging up....\n");
tty_hangup(port->gs.port.tty);
} else {
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "DCD "
"dropped. ignoring.\n");
}
}
} else {
sx_dprintk(SX_DEBUG_MODEMSIGNALS, "Hmmm. card told us "
"DCD changed, but it didn't.\n");
}
}
}
static irqreturn_t sx_interrupt(int irq, void *ptr)
{
struct sx_board *board = ptr;
struct sx_port *port;
int i;
func_enter();
sx_dprintk(SX_DEBUG_FLOW, "sx: enter sx_interrupt (%d/%d)\n", irq,
board->irq);
#ifdef IRQ_RATE_LIMIT
{
static int lastjif;
static int nintr = 0;
if (lastjif == jiffies) {
if (++nintr > IRQ_RATE_LIMIT) {
free_irq(board->irq, board);
printk(KERN_ERR "sx: Too many interrupts. "
"Turning off interrupt %d.\n",
board->irq);
}
} else {
lastjif = jiffies;
nintr = 0;
}
}
#endif
if (board->irq == irq) {
sx_write_board_word(board, cc_int_pending, 0);
if (IS_SX_BOARD(board)) {
write_sx_byte(board, SX_RESET_IRQ, 1);
} else if (IS_EISA_BOARD(board)) {
inb(board->eisa_base + 0xc03);
write_sx_word(board, 8, 0);
} else {
write_sx_byte(board, SI2_ISA_INTCLEAR,
SI2_ISA_INTCLEAR_CLEAR);
write_sx_byte(board, SI2_ISA_INTCLEAR,
SI2_ISA_INTCLEAR_SET);
}
}
if (!sx_initialized)
return IRQ_HANDLED;
if (!(board->flags & SX_BOARD_INITIALIZED))
return IRQ_HANDLED;
if (test_and_set_bit(SX_BOARD_INTR_LOCK, &board->locks)) {
printk(KERN_ERR "Recursive interrupt! (%d)\n", board->irq);
return IRQ_HANDLED;
}
for (i = 0; i < board->nports; i++) {
port = &board->ports[i];
if (port->gs.port.flags & GS_ACTIVE) {
if (sx_read_channel_byte(port, hi_state)) {
sx_dprintk(SX_DEBUG_INTERRUPTS, "Port %d: "
"modem signal change?... \n",i);
sx_check_modem_signals(port);
}
if (port->gs.xmit_cnt) {
sx_transmit_chars(port);
}
if (!(port->gs.port.flags & SX_RX_THROTTLE)) {
sx_receive_chars(port);
}
}
}
clear_bit(SX_BOARD_INTR_LOCK, &board->locks);
sx_dprintk(SX_DEBUG_FLOW, "sx: exit sx_interrupt (%d/%d)\n", irq,
board->irq);
func_exit();
return IRQ_HANDLED;
}
static void sx_pollfunc(unsigned long data)
{
struct sx_board *board = (struct sx_board *)data;
func_enter();
sx_interrupt(0, board);
mod_timer(&board->timer, jiffies + sx_poll);
func_exit();
}
static void sx_disable_tx_interrupts(void *ptr)
{
struct sx_port *port = ptr;
func_enter2();
port->gs.port.flags &= ~GS_TX_INTEN;
func_exit();
}
static void sx_enable_tx_interrupts(void *ptr)
{
struct sx_port *port = ptr;
int data_in_buffer;
func_enter2();
sx_transmit_chars(port);
data_in_buffer = (sx_read_channel_byte(port, hi_txipos) -
sx_read_channel_byte(port, hi_txopos)) & 0xff;
if (data_in_buffer < LOW_WATER)
port->gs.port.flags &= ~GS_TX_INTEN;
func_exit();
}
static void sx_disable_rx_interrupts(void *ptr)
{
func_enter();
func_exit();
}
static void sx_enable_rx_interrupts(void *ptr)
{
func_enter();
func_exit();
}
static int sx_carrier_raised(struct tty_port *port)
{
struct sx_port *sp = container_of(port, struct sx_port, gs.port);
return ((sx_read_channel_byte(sp, hi_ip) & IP_DCD) != 0);
}
static int sx_chars_in_buffer(void *ptr)
{
struct sx_port *port = ptr;
func_enter2();
func_exit();
return ((sx_read_channel_byte(port, hi_txipos) -
sx_read_channel_byte(port, hi_txopos)) & 0xff);
}
static void sx_shutdown_port(void *ptr)
{
struct sx_port *port = ptr;
func_enter();
port->gs.port.flags &= ~GS_ACTIVE;
if (port->gs.port.tty && (port->gs.port.tty->termios->c_cflag & HUPCL)) {
sx_setsignals(port, 0, 0);
sx_reconfigure_port(port);
}
func_exit();
}
static int sx_open(struct tty_struct *tty, struct file *filp)
{
struct sx_port *port;
int retval, line;
unsigned long flags;
func_enter();
if (!sx_initialized) {
return -EIO;
}
line = tty->index;
sx_dprintk(SX_DEBUG_OPEN, "%d: opening line %d. tty=%p ctty=%p, "
"np=%d)\n", task_pid_nr(current), line, tty,
current->signal->tty, sx_nports);
if ((line < 0) || (line >= SX_NPORTS) || (line >= sx_nports))
return -ENODEV;
port = &sx_ports[line];
port->c_dcd = 0;
sx_dprintk(SX_DEBUG_OPEN, "port = %p c_dcd = %d\n", port, port->c_dcd);
spin_lock_irqsave(&port->gs.driver_lock, flags);
tty->driver_data = port;
port->gs.port.tty = tty;
port->gs.port.count++;
spin_unlock_irqrestore(&port->gs.driver_lock, flags);
sx_dprintk(SX_DEBUG_OPEN, "starting port\n");
retval = gs_init_port(&port->gs);
sx_dprintk(SX_DEBUG_OPEN, "done gs_init\n");
if (retval) {
port->gs.port.count--;
return retval;
}
port->gs.port.flags |= GS_ACTIVE;
if (port->gs.port.count <= 1)
sx_setsignals(port, 1, 1);
#if 0
if (sx_debug & SX_DEBUG_OPEN)
my_hd(port, sizeof(*port));
#else
if (sx_debug & SX_DEBUG_OPEN)
my_hd_io(port->board->base + port->ch_base, sizeof(*port));
#endif
if (port->gs.port.count <= 1) {
if (sx_send_command(port, HS_LOPEN, -1, HS_IDLE_OPEN) != 1) {
printk(KERN_ERR "sx: Card didn't respond to LOPEN "
"command.\n");
spin_lock_irqsave(&port->gs.driver_lock, flags);
port->gs.port.count--;
spin_unlock_irqrestore(&port->gs.driver_lock, flags);
return -EIO;
}
}
retval = gs_block_til_ready(port, filp);
sx_dprintk(SX_DEBUG_OPEN, "Block til ready returned %d. Count=%d\n",
retval, port->gs.port.count);
if (retval) {
return retval;
}
port->c_dcd = sx_carrier_raised(&port->gs.port);
sx_dprintk(SX_DEBUG_OPEN, "at open: cd=%d\n", port->c_dcd);
func_exit();
return 0;
}
static void sx_close(void *ptr)
{
struct sx_port *port = ptr;
int to = 5 * HZ;
func_enter();
sx_setsignals(port, 0, 0);
sx_reconfigure_port(port);
sx_send_command(port, HS_CLOSE, 0, 0);
while (to-- && (sx_read_channel_byte(port, hi_hstat) != HS_IDLE_CLOSED))
if (msleep_interruptible(10))
break;
if (sx_read_channel_byte(port, hi_hstat) != HS_IDLE_CLOSED) {
if (sx_send_command(port, HS_FORCE_CLOSED, -1, HS_IDLE_CLOSED)
!= 1) {
printk(KERN_ERR "sx: sent the force_close command, but "
"card didn't react\n");
} else
sx_dprintk(SX_DEBUG_CLOSE, "sent the force_close "
"command.\n");
}
sx_dprintk(SX_DEBUG_CLOSE, "waited %d jiffies for close. count=%d\n",
5 * HZ - to - 1, port->gs.port.count);
if (port->gs.port.count) {
sx_dprintk(SX_DEBUG_CLOSE, "WARNING port count:%d\n",
port->gs.port.count);
}
func_exit();
}
static int do_memtest(struct sx_board *board, int min, int max)
{
int i;
MARCHUP {
W0;
}
MARCHUP {
R0;
W1;
R1;
W0;
R0;
W1;
}
MARCHUP {
R1;
W0;
W1;
}
MARCHDOWN {
R1;
W0;
W1;
W0;
}
MARCHDOWN {
R0;
W1;
W0;
}
return 0;
}
static long sx_fw_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
long rc = 0;
int __user *descr = (int __user *)arg;
int i;
static struct sx_board *board = NULL;
int nbytes, offset;
unsigned long data;
char *tmp;
func_enter();
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
tty_lock();
sx_dprintk(SX_DEBUG_FIRMWARE, "IOCTL %x: %lx\n", cmd, arg);
if (!board)
board = &boards[0];
if (board->flags & SX_BOARD_PRESENT) {
sx_dprintk(SX_DEBUG_FIRMWARE, "Board present! (%x)\n",
board->flags);
} else {
sx_dprintk(SX_DEBUG_FIRMWARE, "Board not present! (%x) all:",
board->flags);
for (i = 0; i < SX_NBOARDS; i++)
sx_dprintk(SX_DEBUG_FIRMWARE, "<%x> ", boards[i].flags);
sx_dprintk(SX_DEBUG_FIRMWARE, "\n");
rc = -EIO;
goto out;
}
switch (cmd) {
case SXIO_SET_BOARD:
sx_dprintk(SX_DEBUG_FIRMWARE, "set board to %ld\n", arg);
rc = -EIO;
if (arg >= SX_NBOARDS)
break;
sx_dprintk(SX_DEBUG_FIRMWARE, "not out of range\n");
if (!(boards[arg].flags & SX_BOARD_PRESENT))
break;
sx_dprintk(SX_DEBUG_FIRMWARE, ".. and present!\n");
board = &boards[arg];
rc = 0;
break;
case SXIO_GET_TYPE:
rc = -ENOENT;
if (IS_SX_BOARD(board))
rc = SX_TYPE_SX;
if (IS_CF_BOARD(board))
rc = SX_TYPE_CF;
if (IS_SI_BOARD(board))
rc = SX_TYPE_SI;
if (IS_SI1_BOARD(board))
rc = SX_TYPE_SI;
if (IS_EISA_BOARD(board))
rc = SX_TYPE_SI;
sx_dprintk(SX_DEBUG_FIRMWARE, "returning type= %ld\n", rc);
break;
case SXIO_DO_RAMTEST:
if (sx_initialized) {
rc = -EPERM;
break;
}
if (IS_SX_BOARD(board)) {
rc = do_memtest(board, 0, 0x7000);
if (!rc)
rc = do_memtest(board, 0, 0x7000);
} else {
rc = do_memtest(board, 0, 0x7ff8);
}
sx_dprintk(SX_DEBUG_FIRMWARE,
"returning memtest result= %ld\n", rc);
break;
case SXIO_DOWNLOAD:
if (sx_initialized) {
rc = -EEXIST;
break;
}
if (!sx_reset(board)) {
rc = -EIO;
break;
}
sx_dprintk(SX_DEBUG_INIT, "reset the board...\n");
tmp = kmalloc(SX_CHUNK_SIZE, GFP_USER);
if (!tmp) {
rc = -ENOMEM;
break;
}
get_user(nbytes, descr++);
get_user(offset, descr++);
get_user(data, descr++);
while (nbytes && data) {
for (i = 0; i < nbytes; i += SX_CHUNK_SIZE) {
if (copy_from_user(tmp, (char __user *)data + i,
(i + SX_CHUNK_SIZE > nbytes) ?
nbytes - i : SX_CHUNK_SIZE)) {
kfree(tmp);
rc = -EFAULT;
goto out;
}
memcpy_toio(board->base2 + offset + i, tmp,
(i + SX_CHUNK_SIZE > nbytes) ?
nbytes - i : SX_CHUNK_SIZE);
}
get_user(nbytes, descr++);
get_user(offset, descr++);
get_user(data, descr++);
}
kfree(tmp);
sx_nports += sx_init_board(board);
rc = sx_nports;
break;
case SXIO_INIT:
if (sx_initialized) {
rc = -EEXIST;
break;
}
for (i = 0; i < SX_NBOARDS; i++) {
if ((boards[i].flags & SX_BOARD_PRESENT) &&
!(boards[i].flags & SX_BOARD_INITIALIZED)) {
rc = -EIO;
break;
}
}
for (i = 0; i < SX_NBOARDS; i++)
if (!(boards[i].flags & SX_BOARD_PRESENT))
break;
sx_dprintk(SX_DEBUG_FIRMWARE, "initing portstructs, %d boards, "
"%d channels, first board: %d ports\n",
i, sx_nports, boards[0].nports);
rc = sx_init_portstructs(i, sx_nports);
sx_init_drivers();
if (rc >= 0)
sx_initialized++;
break;
case SXIO_SETDEBUG:
sx_debug = arg;
break;
case SXIO_GETDEBUG:
rc = sx_debug;
break;
case SXIO_GETGSDEBUG:
case SXIO_SETGSDEBUG:
rc = -EINVAL;
break;
case SXIO_GETNPORTS:
rc = sx_nports;
break;
default:
rc = -ENOTTY;
break;
}
out:
tty_unlock();
func_exit();
return rc;
}
static int sx_break(struct tty_struct *tty, int flag)
{
struct sx_port *port = tty->driver_data;
int rv;
func_enter();
tty_lock();
if (flag)
rv = sx_send_command(port, HS_START, -1, HS_IDLE_BREAK);
else
rv = sx_send_command(port, HS_STOP, -1, HS_IDLE_OPEN);
if (rv != 1)
printk(KERN_ERR "sx: couldn't send break (%x).\n",
read_sx_byte(port->board, CHAN_OFFSET(port, hi_hstat)));
tty_unlock();
func_exit();
return 0;
}
static int sx_tiocmget(struct tty_struct *tty)
{
struct sx_port *port = tty->driver_data;
return sx_getsignals(port);
}
static int sx_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct sx_port *port = tty->driver_data;
int rts = -1, dtr = -1;
if (set & TIOCM_RTS)
rts = 1;
if (set & TIOCM_DTR)
dtr = 1;
if (clear & TIOCM_RTS)
rts = 0;
if (clear & TIOCM_DTR)
dtr = 0;
sx_setsignals(port, dtr, rts);
sx_reconfigure_port(port);
return 0;
}
static int sx_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
int rc;
struct sx_port *port = tty->driver_data;
void __user *argp = (void __user *)arg;
rc = 0;
tty_lock();
switch (cmd) {
case TIOCGSERIAL:
rc = gs_getserial(&port->gs, argp);
break;
case TIOCSSERIAL:
rc = gs_setserial(&port->gs, argp);
break;
default:
rc = -ENOIOCTLCMD;
break;
}
tty_unlock();
return rc;
}
static void sx_throttle(struct tty_struct *tty)
{
struct sx_port *port = tty->driver_data;
func_enter2();
if ((tty->termios->c_cflag & CRTSCTS) || (I_IXOFF(tty))) {
port->gs.port.flags |= SX_RX_THROTTLE;
}
func_exit();
}
static void sx_unthrottle(struct tty_struct *tty)
{
struct sx_port *port = tty->driver_data;
func_enter2();
port->gs.port.flags &= ~SX_RX_THROTTLE;
func_exit();
return;
}
static int sx_init_board(struct sx_board *board)
{
int addr;
int chans;
int type;
func_enter();
board->flags |= SX_BOARD_INITIALIZED;
if (read_sx_byte(board, 0))
write_sx_byte(board, 0, 0);
if (!sx_reset(board))
return 0;
sx_start_board(board);
udelay(10);
if (!sx_busy_wait_neq(board, 0, 0xff, 0)) {
printk(KERN_ERR "sx: Ooops. Board won't initialize.\n");
return 0;
}
sx_dprintk(SX_DEBUG_INIT, "The sxcard structure:\n");
if (sx_debug & SX_DEBUG_INIT)
my_hd_io(board->base, 0x10);
sx_dprintk(SX_DEBUG_INIT, "the first sx_module structure:\n");
if (sx_debug & SX_DEBUG_INIT)
my_hd_io(board->base + 0x80, 0x30);
sx_dprintk(SX_DEBUG_INIT, "init_status: %x, %dk memory, firmware "
"V%x.%02x,\n",
read_sx_byte(board, 0), read_sx_byte(board, 1),
read_sx_byte(board, 5), read_sx_byte(board, 4));
if (read_sx_byte(board, 0) == 0xff) {
printk(KERN_INFO "sx: No modules found. Sorry.\n");
board->nports = 0;
return 0;
}
chans = 0;
if (IS_SX_BOARD(board)) {
sx_write_board_word(board, cc_int_count, sx_maxints);
} else {
if (sx_maxints)
sx_write_board_word(board, cc_int_count,
SI_PROCESSOR_CLOCK / 8 / sx_maxints);
}
board->ta_type = mod_compat_type(sx_read_module_byte(board, 0x80,
mc_chip));
for (addr = 0x80; addr != 0; addr = read_sx_word(board, addr) & 0x7fff){
type = sx_read_module_byte(board, addr, mc_chip);
sx_dprintk(SX_DEBUG_INIT, "Module at %x: %d channels\n",
addr, read_sx_byte(board, addr + 2));
chans += sx_read_module_byte(board, addr, mc_type);
sx_dprintk(SX_DEBUG_INIT, "module is an %s, which has %s/%s "
"panels\n",
mod_type_s(type),
pan_type_s(sx_read_module_byte(board, addr,
mc_mods) & 0xf),
pan_type_s(sx_read_module_byte(board, addr,
mc_mods) >> 4));
sx_dprintk(SX_DEBUG_INIT, "CD1400 versions: %x/%x, ASIC "
"version: %x\n",
sx_read_module_byte(board, addr, mc_rev1),
sx_read_module_byte(board, addr, mc_rev2),
sx_read_module_byte(board, addr, mc_mtaasic_rev));
if (mod_compat_type(type) != board->ta_type) {
printk(KERN_ERR "sx: This is an invalid "
"configuration.\nDon't mix TA/MTA/SXDC on the "
"same hostadapter.\n");
chans = 0;
break;
}
if ((IS_EISA_BOARD(board) ||
IS_SI_BOARD(board)) &&
(mod_compat_type(type) == 4)) {
printk(KERN_ERR "sx: This is an invalid "
"configuration.\nDon't use SXDCs on an SI/XIO "
"adapter.\n");
chans = 0;
break;
}
#if 0
if (IS_SX_BOARD(board) && (type == TA8)) {
printk(KERN_WARNING
"sx: The SX host doesn't work too well "
"with the TA8 adapters.\nSpecialix is working on it.\n");
}
#endif
}
if (chans) {
if (board->irq > 0) {
if (sx_irqmask & (1 << board->irq)) {
if (request_irq(board->irq, sx_interrupt,
IRQF_SHARED | IRQF_DISABLED,
"sx", board)) {
printk(KERN_ERR "sx: Cannot allocate "
"irq %d.\n", board->irq);
board->irq = 0;
}
} else
board->irq = 0;
} else if (board->irq < 0 && sx_irqmask) {
int irqnr;
int irqmask = sx_irqmask & (IS_SX_BOARD(board) ?
SX_ISA_IRQ_MASK : SI2_ISA_IRQ_MASK);
for (irqnr = 15; irqnr > 0; irqnr--)
if (irqmask & (1 << irqnr))
if (!request_irq(irqnr, sx_interrupt,
IRQF_SHARED | IRQF_DISABLED,
"sx", board))
break;
if (!irqnr)
printk(KERN_ERR "sx: Cannot allocate IRQ.\n");
board->irq = irqnr;
} else
board->irq = 0;
if (board->irq) {
sx_dprintk(SX_DEBUG_INIT, "Using irq %d.\n",
board->irq);
sx_start_interrupts(board);
board->poll = sx_slowpoll;
board->flags |= SX_IRQ_ALLOCATED;
} else {
board->poll = sx_poll;
sx_dprintk(SX_DEBUG_INIT, "Using poll-interval %d.\n",
board->poll);
}
setup_timer(&board->timer, sx_pollfunc, (unsigned long)board);
if (board->poll)
mod_timer(&board->timer, jiffies + board->poll);
} else {
board->irq = 0;
}
board->nports = chans;
sx_dprintk(SX_DEBUG_INIT, "returning %d ports.", board->nports);
func_exit();
return chans;
}
static void __devinit printheader(void)
{
static int header_printed;
if (!header_printed) {
printk(KERN_INFO "Specialix SX driver "
"(C) 1998/1999 R.E.Wolff@BitWizard.nl\n");
printk(KERN_INFO "sx: version " __stringify(SX_VERSION) "\n");
header_printed = 1;
}
}
static int __devinit probe_sx(struct sx_board *board)
{
struct vpd_prom vpdp;
char *p;
int i;
func_enter();
if (!IS_CF_BOARD(board)) {
sx_dprintk(SX_DEBUG_PROBE, "Going to verify vpd prom at %p.\n",
board->base + SX_VPD_ROM);
if (sx_debug & SX_DEBUG_PROBE)
my_hd_io(board->base + SX_VPD_ROM, 0x40);
p = (char *)&vpdp;
for (i = 0; i < sizeof(struct vpd_prom); i++)
*p++ = read_sx_byte(board, SX_VPD_ROM + i * 2);
if (sx_debug & SX_DEBUG_PROBE)
my_hd(&vpdp, 0x20);
sx_dprintk(SX_DEBUG_PROBE, "checking identifier...\n");
if (strncmp(vpdp.identifier, SX_VPD_IDENT_STRING, 16) != 0) {
sx_dprintk(SX_DEBUG_PROBE, "Got non-SX identifier: "
"'%s'\n", vpdp.identifier);
return 0;
}
}
printheader();
if (!IS_CF_BOARD(board)) {
printk(KERN_DEBUG "sx: Found an SX board at %lx\n",
board->hw_base);
printk(KERN_DEBUG "sx: hw_rev: %d, assembly level: %d, "
"uniq ID:%08x, ",
vpdp.hwrev, vpdp.hwass, vpdp.uniqid);
printk("Manufactured: %d/%d\n", 1970 + vpdp.myear, vpdp.mweek);
if ((((vpdp.uniqid >> 24) & SX_UNIQUEID_MASK) !=
SX_PCI_UNIQUEID1) && (((vpdp.uniqid >> 24) &
SX_UNIQUEID_MASK) != SX_ISA_UNIQUEID1)) {
printk(KERN_ERR "sx: Hmm. Not an SX/PCI or SX/ISA "
"card. Sorry: giving up.\n");
return (0);
}
if (((vpdp.uniqid >> 24) & SX_UNIQUEID_MASK) ==
SX_ISA_UNIQUEID1) {
if (((unsigned long)board->hw_base) & 0x8000) {
printk(KERN_WARNING "sx: Warning: There may be "
"hardware problems with the card at "
"%lx.\n", board->hw_base);
printk(KERN_WARNING "sx: Read sx.txt for more "
"info.\n");
}
}
}
board->nports = -1;
if (!sx_reset(board))
return 0;
sx_dprintk(SX_DEBUG_INIT, "reset the board...\n");
func_exit();
return 1;
}
static int __devinit probe_si(struct sx_board *board)
{
int i;
func_enter();
sx_dprintk(SX_DEBUG_PROBE, "Going to verify SI signature hw %lx at "
"%p.\n", board->hw_base, board->base + SI2_ISA_ID_BASE);
if (sx_debug & SX_DEBUG_PROBE)
my_hd_io(board->base + SI2_ISA_ID_BASE, 0x8);
if (!IS_EISA_BOARD(board)) {
if (IS_SI1_BOARD(board)) {
for (i = 0; i < 8; i++) {
write_sx_byte(board, SI2_ISA_ID_BASE + 7 - i,i);
}
}
for (i = 0; i < 8; i++) {
if ((read_sx_byte(board, SI2_ISA_ID_BASE + 7 - i) & 7)
!= i) {
func_exit();
return 0;
}
}
}
write_sx_byte(board, SI2_ISA_ID_BASE, 0x10);
if (IS_SI1_BOARD(board)) {
if (read_sx_byte(board, SI2_ISA_ID_BASE) != 0x10) {
func_exit();
return 0;
}
} else {
if (read_sx_byte(board, SI2_ISA_ID_BASE) == 0x10) {
func_exit();
return 0;
}
}
write_sx_byte(board, SI2_ISA_ID_BASE, 0x10);
if (IS_SI1_BOARD(board)) {
if (read_sx_byte(board, SI2_ISA_ID_BASE) != 0x10) {
func_exit();
return 0;
}
} else {
if (read_sx_byte(board, SI2_ISA_ID_BASE) == 0x10) {
func_exit();
return 0;
}
}
printheader();
printk(KERN_DEBUG "sx: Found an SI board at %lx\n", board->hw_base);
board->nports = -1;
if (!sx_reset(board))
return 0;
sx_dprintk(SX_DEBUG_INIT, "reset the board...\n");
func_exit();
return 1;
}
static int sx_init_drivers(void)
{
int error;
func_enter();
sx_driver = alloc_tty_driver(sx_nports);
if (!sx_driver)
return 1;
sx_driver->owner = THIS_MODULE;
sx_driver->driver_name = "specialix_sx";
sx_driver->name = "ttyX";
sx_driver->major = SX_NORMAL_MAJOR;
sx_driver->type = TTY_DRIVER_TYPE_SERIAL;
sx_driver->subtype = SERIAL_TYPE_NORMAL;
sx_driver->init_termios = tty_std_termios;
sx_driver->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL | CLOCAL;
sx_driver->init_termios.c_ispeed = 9600;
sx_driver->init_termios.c_ospeed = 9600;
sx_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(sx_driver, &sx_ops);
if ((error = tty_register_driver(sx_driver))) {
put_tty_driver(sx_driver);
printk(KERN_ERR "sx: Couldn't register sx driver, error = %d\n",
error);
return 1;
}
func_exit();
return 0;
}
static int sx_init_portstructs(int nboards, int nports)
{
struct sx_board *board;
struct sx_port *port;
int i, j;
int addr, chans;
int portno;
func_enter();
sx_ports = kcalloc(nports, sizeof(struct sx_port), GFP_KERNEL);
if (!sx_ports)
return -ENOMEM;
port = sx_ports;
for (i = 0; i < nboards; i++) {
board = &boards[i];
board->ports = port;
for (j = 0; j < boards[i].nports; j++) {
sx_dprintk(SX_DEBUG_INIT, "initing port %d\n", j);
tty_port_init(&port->gs.port);
port->gs.port.ops = &sx_port_ops;
port->gs.magic = SX_MAGIC;
port->gs.close_delay = HZ / 2;
port->gs.closing_wait = 30 * HZ;
port->board = board;
port->gs.rd = &sx_real_driver;
#ifdef NEW_WRITE_LOCKING
port->gs.port_write_mutex = MUTEX;
#endif
spin_lock_init(&port->gs.driver_lock);
port++;
}
}
port = sx_ports;
portno = 0;
for (i = 0; i < nboards; i++) {
board = &boards[i];
board->port_base = portno;
sx_dprintk(SX_DEBUG_PROBE, "Board has %d channels\n",
board->nports);
if (board->nports <= 0)
continue;
for (addr = 0x80; addr != 0;
addr = read_sx_word(board, addr) & 0x7fff) {
chans = sx_read_module_byte(board, addr, mc_type);
sx_dprintk(SX_DEBUG_PROBE, "Module at %x: %d "
"channels\n", addr, chans);
sx_dprintk(SX_DEBUG_PROBE, "Port at");
for (j = 0; j < chans; j++) {
if (IS_SX_BOARD(board))
port->ch_base = sx_read_module_word(
board, addr + j * 2,
mc_chan_pointer);
else
port->ch_base = addr + 0x100 + 0x300 *j;
sx_dprintk(SX_DEBUG_PROBE, " %x",
port->ch_base);
port->line = portno++;
port++;
}
sx_dprintk(SX_DEBUG_PROBE, "\n");
}
}
func_exit();
return 0;
}
static unsigned int sx_find_free_board(void)
{
unsigned int i;
for (i = 0; i < SX_NBOARDS; i++)
if (!(boards[i].flags & SX_BOARD_PRESENT))
break;
return i;
}
static void __exit sx_release_drivers(void)
{
func_enter();
tty_unregister_driver(sx_driver);
put_tty_driver(sx_driver);
func_exit();
}
static void __devexit sx_remove_card(struct sx_board *board,
struct pci_dev *pdev)
{
if (board->flags & SX_BOARD_INITIALIZED) {
sx_reset(board);
if ((board->irq) && (board->flags & SX_IRQ_ALLOCATED))
free_irq(board->irq, board);
del_timer(&board->timer);
if (pdev) {
#ifdef CONFIG_PCI
iounmap(board->base2);
pci_release_region(pdev, IS_CF_BOARD(board) ? 3 : 2);
#endif
} else {
iounmap(board->base);
release_region(board->hw_base, board->hw_len);
}
board->flags &= ~(SX_BOARD_INITIALIZED | SX_BOARD_PRESENT);
}
}
static int __devinit sx_eisa_probe(struct device *dev)
{
struct eisa_device *edev = to_eisa_device(dev);
struct sx_board *board;
unsigned long eisa_slot = edev->base_addr;
unsigned int i;
int retval = -EIO;
mutex_lock(&sx_boards_lock);
i = sx_find_free_board();
if (i == SX_NBOARDS) {
mutex_unlock(&sx_boards_lock);
goto err;
}
board = &boards[i];
board->flags |= SX_BOARD_PRESENT;
mutex_unlock(&sx_boards_lock);
dev_info(dev, "XIO : Signature found in EISA slot %lu, "
"Product %d Rev %d (REPORT THIS TO LKLM)\n",
eisa_slot >> 12,
inb(eisa_slot + EISA_VENDOR_ID_OFFSET + 2),
inb(eisa_slot + EISA_VENDOR_ID_OFFSET + 3));
board->eisa_base = eisa_slot;
board->flags &= ~SX_BOARD_TYPE;
board->flags |= SI_EISA_BOARD;
board->hw_base = ((inb(eisa_slot + 0xc01) << 8) +
inb(eisa_slot + 0xc00)) << 16;
board->hw_len = SI2_EISA_WINDOW_LEN;
if (!request_region(board->hw_base, board->hw_len, "sx")) {
dev_err(dev, "can't request region\n");
goto err_flag;
}
board->base2 =
board->base = ioremap_nocache(board->hw_base, SI2_EISA_WINDOW_LEN);
if (!board->base) {
dev_err(dev, "can't remap memory\n");
goto err_reg;
}
sx_dprintk(SX_DEBUG_PROBE, "IO hw_base address: %lx\n", board->hw_base);
sx_dprintk(SX_DEBUG_PROBE, "base: %p\n", board->base);
board->irq = inb(eisa_slot + 0xc02) >> 4;
sx_dprintk(SX_DEBUG_PROBE, "IRQ: %d\n", board->irq);
if (!probe_si(board))
goto err_unmap;
dev_set_drvdata(dev, board);
return 0;
err_unmap:
iounmap(board->base);
err_reg:
release_region(board->hw_base, board->hw_len);
err_flag:
board->flags &= ~SX_BOARD_PRESENT;
err:
return retval;
}
static int __devexit sx_eisa_remove(struct device *dev)
{
struct sx_board *board = dev_get_drvdata(dev);
sx_remove_card(board, NULL);
return 0;
}
static void __devinit fix_sx_pci(struct pci_dev *pdev, struct sx_board *board)
{
unsigned int hwbase;
void __iomem *rebase;
unsigned int t;
#define CNTRL_REG_OFFSET 0x50
#define CNTRL_REG_GOODVALUE 0x18260000
pci_read_config_dword(pdev, PCI_BASE_ADDRESS_0, &hwbase);
hwbase &= PCI_BASE_ADDRESS_MEM_MASK;
rebase = ioremap_nocache(hwbase, 0x80);
t = readl(rebase + CNTRL_REG_OFFSET);
if (t != CNTRL_REG_GOODVALUE) {
printk(KERN_DEBUG "sx: performing cntrl reg fix: %08x -> "
"%08x\n", t, CNTRL_REG_GOODVALUE);
writel(CNTRL_REG_GOODVALUE, rebase + CNTRL_REG_OFFSET);
}
iounmap(rebase);
}
static int __devinit sx_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
#ifdef CONFIG_PCI
struct sx_board *board;
unsigned int i, reg;
int retval = -EIO;
mutex_lock(&sx_boards_lock);
i = sx_find_free_board();
if (i == SX_NBOARDS) {
mutex_unlock(&sx_boards_lock);
goto err;
}
board = &boards[i];
board->flags |= SX_BOARD_PRESENT;
mutex_unlock(&sx_boards_lock);
retval = pci_enable_device(pdev);
if (retval)
goto err_flag;
board->flags &= ~SX_BOARD_TYPE;
board->flags |= (pdev->subsystem_vendor == 0x200) ? SX_PCI_BOARD :
SX_CFPCI_BOARD;
reg = IS_CF_BOARD(board) ? 3 : 2;
retval = pci_request_region(pdev, reg, "sx");
if (retval) {
dev_err(&pdev->dev, "can't request region\n");
goto err_flag;
}
board->hw_base = pci_resource_start(pdev, reg);
board->base2 =
board->base = ioremap_nocache(board->hw_base, WINDOW_LEN(board));
if (!board->base) {
dev_err(&pdev->dev, "ioremap failed\n");
goto err_reg;
}
if (IS_CF_BOARD(board))
board->base += 0x18000;
board->irq = pdev->irq;
dev_info(&pdev->dev, "Got a specialix card: %p(%d) %x.\n", board->base,
board->irq, board->flags);
if (!probe_sx(board)) {
retval = -EIO;
goto err_unmap;
}
fix_sx_pci(pdev, board);
pci_set_drvdata(pdev, board);
return 0;
err_unmap:
iounmap(board->base2);
err_reg:
pci_release_region(pdev, reg);
err_flag:
board->flags &= ~SX_BOARD_PRESENT;
err:
return retval;
#else
return -ENODEV;
#endif
}
static void __devexit sx_pci_remove(struct pci_dev *pdev)
{
struct sx_board *board = pci_get_drvdata(pdev);
sx_remove_card(board, pdev);
}
static int __init sx_init(void)
{
#ifdef CONFIG_EISA
int retval1;
#endif
#ifdef CONFIG_ISA
struct sx_board *board;
unsigned int i;
#endif
unsigned int found = 0;
int retval;
func_enter();
sx_dprintk(SX_DEBUG_INIT, "Initing sx module... (sx_debug=%d)\n",
sx_debug);
if (abs((long)(&sx_debug) - sx_debug) < 0x10000) {
printk(KERN_WARNING "sx: sx_debug is an address, instead of a "
"value. Assuming -1.\n(%p)\n", &sx_debug);
sx_debug = -1;
}
if (misc_register(&sx_fw_device) < 0) {
printk(KERN_ERR "SX: Unable to register firmware loader "
"driver.\n");
return -EIO;
}
#ifdef CONFIG_ISA
for (i = 0; i < NR_SX_ADDRS; i++) {
board = &boards[found];
board->hw_base = sx_probe_addrs[i];
board->hw_len = SX_WINDOW_LEN;
if (!request_region(board->hw_base, board->hw_len, "sx"))
continue;
board->base2 =
board->base = ioremap_nocache(board->hw_base, board->hw_len);
if (!board->base)
goto err_sx_reg;
board->flags &= ~SX_BOARD_TYPE;
board->flags |= SX_ISA_BOARD;
board->irq = sx_irqmask ? -1 : 0;
if (probe_sx(board)) {
board->flags |= SX_BOARD_PRESENT;
found++;
} else {
iounmap(board->base);
err_sx_reg:
release_region(board->hw_base, board->hw_len);
}
}
for (i = 0; i < NR_SI_ADDRS; i++) {
board = &boards[found];
board->hw_base = si_probe_addrs[i];
board->hw_len = SI2_ISA_WINDOW_LEN;
if (!request_region(board->hw_base, board->hw_len, "sx"))
continue;
board->base2 =
board->base = ioremap_nocache(board->hw_base, board->hw_len);
if (!board->base)
goto err_si_reg;
board->flags &= ~SX_BOARD_TYPE;
board->flags |= SI_ISA_BOARD;
board->irq = sx_irqmask ? -1 : 0;
if (probe_si(board)) {
board->flags |= SX_BOARD_PRESENT;
found++;
} else {
iounmap(board->base);
err_si_reg:
release_region(board->hw_base, board->hw_len);
}
}
for (i = 0; i < NR_SI1_ADDRS; i++) {
board = &boards[found];
board->hw_base = si1_probe_addrs[i];
board->hw_len = SI1_ISA_WINDOW_LEN;
if (!request_region(board->hw_base, board->hw_len, "sx"))
continue;
board->base2 =
board->base = ioremap_nocache(board->hw_base, board->hw_len);
if (!board->base)
goto err_si1_reg;
board->flags &= ~SX_BOARD_TYPE;
board->flags |= SI1_ISA_BOARD;
board->irq = sx_irqmask ? -1 : 0;
if (probe_si(board)) {
board->flags |= SX_BOARD_PRESENT;
found++;
} else {
iounmap(board->base);
err_si1_reg:
release_region(board->hw_base, board->hw_len);
}
}
#endif
#ifdef CONFIG_EISA
retval1 = eisa_driver_register(&sx_eisadriver);
#endif
retval = pci_register_driver(&sx_pcidriver);
if (found) {
printk(KERN_INFO "sx: total of %d boards detected.\n", found);
retval = 0;
} else if (retval) {
#ifdef CONFIG_EISA
retval = retval1;
if (retval1)
#endif
misc_deregister(&sx_fw_device);
}
func_exit();
return retval;
}
static void __exit sx_exit(void)
{
int i;
func_enter();
#ifdef CONFIG_EISA
eisa_driver_unregister(&sx_eisadriver);
#endif
pci_unregister_driver(&sx_pcidriver);
for (i = 0; i < SX_NBOARDS; i++)
sx_remove_card(&boards[i], NULL);
if (misc_deregister(&sx_fw_device) < 0) {
printk(KERN_INFO "sx: couldn't deregister firmware loader "
"device\n");
}
sx_dprintk(SX_DEBUG_CLEANUP, "Cleaning up drivers (%d)\n",
sx_initialized);
if (sx_initialized)
sx_release_drivers();
kfree(sx_ports);
func_exit();
}
