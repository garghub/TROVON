static int sx_paranoia_check(struct specialix_port const *port,
char *name, const char *routine)
{
#ifdef SPECIALIX_PARANOIA_CHECK
static const char *badmagic = KERN_ERR
"sx: Warning: bad specialix port magic number for device %s in %s\n";
static const char *badinfo = KERN_ERR
"sx: Warning: null specialix port for device %s in %s\n";
if (!port) {
printk(badinfo, name, routine);
return 1;
}
if (port->magic != SPECIALIX_MAGIC) {
printk(badmagic, name, routine);
return 1;
}
#endif
return 0;
}
static inline int board_No(struct specialix_board *bp)
{
return bp - sx_board;
}
static inline int port_No(struct specialix_port const *port)
{
return SX_PORT(port - sx_port);
}
static inline struct specialix_board *port_Board(
struct specialix_port const *port)
{
return &sx_board[SX_BOARD(port - sx_port)];
}
static inline unsigned char sx_in(struct specialix_board *bp,
unsigned short reg)
{
bp->reg = reg | 0x80;
outb(reg | 0x80, bp->base + SX_ADDR_REG);
return inb(bp->base + SX_DATA_REG);
}
static inline void sx_out(struct specialix_board *bp, unsigned short reg,
unsigned char val)
{
bp->reg = reg | 0x80;
outb(reg | 0x80, bp->base + SX_ADDR_REG);
outb(val, bp->base + SX_DATA_REG);
}
static inline unsigned char sx_in_off(struct specialix_board *bp,
unsigned short reg)
{
bp->reg = reg;
outb(reg, bp->base + SX_ADDR_REG);
return inb(bp->base + SX_DATA_REG);
}
static inline void sx_out_off(struct specialix_board *bp,
unsigned short reg, unsigned char val)
{
bp->reg = reg;
outb(reg, bp->base + SX_ADDR_REG);
outb(val, bp->base + SX_DATA_REG);
}
static void sx_wait_CCR(struct specialix_board *bp)
{
unsigned long delay, flags;
unsigned char ccr;
for (delay = SX_CCR_TIMEOUT; delay; delay--) {
spin_lock_irqsave(&bp->lock, flags);
ccr = sx_in(bp, CD186x_CCR);
spin_unlock_irqrestore(&bp->lock, flags);
if (!ccr)
return;
udelay(1);
}
printk(KERN_ERR "sx%d: Timeout waiting for CCR.\n", board_No(bp));
}
static void sx_wait_CCR_off(struct specialix_board *bp)
{
unsigned long delay;
unsigned char crr;
unsigned long flags;
for (delay = SX_CCR_TIMEOUT; delay; delay--) {
spin_lock_irqsave(&bp->lock, flags);
crr = sx_in_off(bp, CD186x_CCR);
spin_unlock_irqrestore(&bp->lock, flags);
if (!crr)
return;
udelay(1);
}
printk(KERN_ERR "sx%d: Timeout waiting for CCR.\n", board_No(bp));
}
static int sx_request_io_range(struct specialix_board *bp)
{
return request_region(bp->base,
bp->flags & SX_BOARD_IS_PCI ? SX_PCI_IO_SPACE : SX_IO_SPACE,
"specialix IO8+") == NULL;
}
static void sx_release_io_range(struct specialix_board *bp)
{
release_region(bp->base, bp->flags & SX_BOARD_IS_PCI ?
SX_PCI_IO_SPACE : SX_IO_SPACE);
}
static int sx_set_irq(struct specialix_board *bp)
{
int virq;
int i;
unsigned long flags;
if (bp->flags & SX_BOARD_IS_PCI)
return 1;
switch (bp->irq) {
case 15:
virq = 0;
break;
case 12:
virq = 1;
break;
case 11:
virq = 2;
break;
case 9:
virq = 3;
break;
default:printk(KERN_ERR
"Speclialix: cannot set irq to %d.\n", bp->irq);
return 0;
}
spin_lock_irqsave(&bp->lock, flags);
for (i = 0; i < 2; i++) {
sx_out(bp, CD186x_CAR, i);
sx_out(bp, CD186x_MSVRTS, ((virq >> i) & 0x1)? MSVR_RTS:0);
}
spin_unlock_irqrestore(&bp->lock, flags);
return 1;
}
static int sx_init_CD186x(struct specialix_board *bp)
{
unsigned long flags;
int scaler;
int rv = 1;
func_enter();
sx_wait_CCR_off(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out_off(bp, CD186x_CCR, CCR_HARDRESET);
spin_unlock_irqrestore(&bp->lock, flags);
msleep(50);
spin_lock_irqsave(&bp->lock, flags);
sx_out_off(bp, CD186x_GIVR, SX_ID);
sx_out_off(bp, CD186x_GICR, 0);
sx_out_off(bp, CD186x_PILR1, SX_ACK_MINT);
sx_out_off(bp, CD186x_PILR2, SX_ACK_TINT);
sx_out_off(bp, CD186x_PILR3, SX_ACK_RINT);
sx_out_off(bp, CD186x_SRCR, sx_in(bp, CD186x_SRCR) | SRCR_REGACKEN);
scaler = SX_OSCFREQ/SPECIALIX_TPS;
sx_out_off(bp, CD186x_PPRH, scaler >> 8);
sx_out_off(bp, CD186x_PPRL, scaler & 0xff);
spin_unlock_irqrestore(&bp->lock, flags);
if (!sx_set_irq(bp)) {
printk(KERN_ERR "Cannot set irq to %d.\n", bp->irq);
rv = 0;
}
func_exit();
return rv;
}
static int read_cross_byte(struct specialix_board *bp, int reg, int bit)
{
int i;
int t;
unsigned long flags;
spin_lock_irqsave(&bp->lock, flags);
for (i = 0, t = 0; i < 8; i++) {
sx_out_off(bp, CD186x_CAR, i);
if (sx_in_off(bp, reg) & bit)
t |= 1 << i;
}
spin_unlock_irqrestore(&bp->lock, flags);
return t;
}
static int sx_probe(struct specialix_board *bp)
{
unsigned char val1, val2;
int rev;
int chip;
func_enter();
if (sx_request_io_range(bp)) {
func_exit();
return 1;
}
sx_out_off(bp, CD186x_PPRL, 0x5a);
udelay(1);
val1 = sx_in_off(bp, CD186x_PPRL);
sx_out_off(bp, CD186x_PPRL, 0xa5);
udelay(1);
val2 = sx_in_off(bp, CD186x_PPRL);
if (val1 != 0x5a || val2 != 0xa5) {
printk(KERN_INFO
"sx%d: specialix IO8+ Board at 0x%03x not found.\n",
board_No(bp), bp->base);
sx_release_io_range(bp);
func_exit();
return 1;
}
val1 = read_cross_byte(bp, CD186x_MSVR, MSVR_DSR);
val2 = read_cross_byte(bp, CD186x_MSVR, MSVR_RTS);
dprintk(SX_DEBUG_INIT,
"sx%d: DSR lines are: %02x, rts lines are: %02x\n",
board_No(bp), val1, val2);
val2 = (bp->flags & SX_BOARD_IS_PCI)?0x4d : 0xb2;
if (val1 != val2) {
printk(KERN_INFO
"sx%d: specialix IO8+ ID %02x at 0x%03x not found (%02x).\n",
board_No(bp), val2, bp->base, val1);
sx_release_io_range(bp);
func_exit();
return 1;
}
if (!sx_init_CD186x(bp)) {
sx_release_io_range(bp);
func_exit();
return 1;
}
sx_request_io_range(bp);
bp->flags |= SX_BOARD_PRESENT;
switch (sx_in_off(bp, CD186x_GFRCR)) {
case 0x82:
chip = 1864;
rev = 'A';
break;
case 0x83:
chip = 1865;
rev = 'A';
break;
case 0x84:
chip = 1865;
rev = 'B';
break;
case 0x85:
chip = 1865;
rev = 'C';
break;
default:
chip = -1;
rev = 'x';
}
dprintk(SX_DEBUG_INIT, " GFCR = 0x%02x\n", sx_in_off(bp, CD186x_GFRCR));
printk(KERN_INFO
"sx%d: specialix IO8+ board detected at 0x%03x, IRQ %d, CD%d Rev. %c.\n",
board_No(bp), bp->base, bp->irq, chip, rev);
func_exit();
return 0;
}
static struct specialix_port *sx_get_port(struct specialix_board *bp,
unsigned char const *what)
{
unsigned char channel;
struct specialix_port *port = NULL;
channel = sx_in(bp, CD186x_GICR) >> GICR_CHAN_OFF;
dprintk(SX_DEBUG_CHAN, "channel: %d\n", channel);
if (channel < CD186x_NCH) {
port = &sx_port[board_No(bp) * SX_NPORT + channel];
dprintk(SX_DEBUG_CHAN, "port: %d %p flags: 0x%lx\n",
board_No(bp) * SX_NPORT + channel, port,
port->port.flags & ASYNC_INITIALIZED);
if (port->port.flags & ASYNC_INITIALIZED) {
dprintk(SX_DEBUG_CHAN, "port: %d %p\n", channel, port);
func_exit();
return port;
}
}
printk(KERN_INFO "sx%d: %s interrupt from invalid port %d\n",
board_No(bp), what, channel);
return NULL;
}
static void sx_receive_exc(struct specialix_board *bp)
{
struct specialix_port *port;
struct tty_struct *tty;
unsigned char status;
unsigned char ch, flag;
func_enter();
port = sx_get_port(bp, "Receive");
if (!port) {
dprintk(SX_DEBUG_RX, "Hmm, couldn't find port.\n");
func_exit();
return;
}
tty = port->port.tty;
status = sx_in(bp, CD186x_RCSR);
dprintk(SX_DEBUG_RX, "status: 0x%x\n", status);
if (status & RCSR_OE) {
port->overrun++;
dprintk(SX_DEBUG_FIFO,
"sx%d: port %d: Overrun. Total %ld overruns.\n",
board_No(bp), port_No(port), port->overrun);
}
status &= port->mark_mask;
if (tty_buffer_request_room(tty, 1) == 0) {
dprintk(SX_DEBUG_FIFO,
"sx%d: port %d: Working around flip buffer overflow.\n",
board_No(bp), port_No(port));
func_exit();
return;
}
ch = sx_in(bp, CD186x_RDR);
if (!status) {
func_exit();
return;
}
if (status & RCSR_TOUT) {
printk(KERN_INFO
"sx%d: port %d: Receiver timeout. Hardware problems ?\n",
board_No(bp), port_No(port));
func_exit();
return;
} else if (status & RCSR_BREAK) {
dprintk(SX_DEBUG_RX, "sx%d: port %d: Handling break...\n",
board_No(bp), port_No(port));
flag = TTY_BREAK;
if (port->port.flags & ASYNC_SAK)
do_SAK(tty);
} else if (status & RCSR_PE)
flag = TTY_PARITY;
else if (status & RCSR_FE)
flag = TTY_FRAME;
else if (status & RCSR_OE)
flag = TTY_OVERRUN;
else
flag = TTY_NORMAL;
if (tty_insert_flip_char(tty, ch, flag))
tty_flip_buffer_push(tty);
func_exit();
}
static void sx_receive(struct specialix_board *bp)
{
struct specialix_port *port;
struct tty_struct *tty;
unsigned char count;
func_enter();
port = sx_get_port(bp, "Receive");
if (port == NULL) {
dprintk(SX_DEBUG_RX, "Hmm, couldn't find port.\n");
func_exit();
return;
}
tty = port->port.tty;
count = sx_in(bp, CD186x_RDCR);
dprintk(SX_DEBUG_RX, "port: %p: count: %d\n", port, count);
port->hits[count > 8 ? 9 : count]++;
while (count--)
tty_insert_flip_char(tty, sx_in(bp, CD186x_RDR), TTY_NORMAL);
tty_flip_buffer_push(tty);
func_exit();
}
static void sx_transmit(struct specialix_board *bp)
{
struct specialix_port *port;
struct tty_struct *tty;
unsigned char count;
func_enter();
port = sx_get_port(bp, "Transmit");
if (port == NULL) {
func_exit();
return;
}
dprintk(SX_DEBUG_TX, "port: %p\n", port);
tty = port->port.tty;
if (port->IER & IER_TXEMPTY) {
sx_out(bp, CD186x_CAR, port_No(port));
port->IER &= ~IER_TXEMPTY;
sx_out(bp, CD186x_IER, port->IER);
func_exit();
return;
}
if ((port->xmit_cnt <= 0 && !port->break_length)
|| tty->stopped || tty->hw_stopped) {
sx_out(bp, CD186x_CAR, port_No(port));
port->IER &= ~IER_TXRDY;
sx_out(bp, CD186x_IER, port->IER);
func_exit();
return;
}
if (port->break_length) {
if (port->break_length > 0) {
if (port->COR2 & COR2_ETC) {
sx_out(bp, CD186x_TDR, CD186x_C_ESC);
sx_out(bp, CD186x_TDR, CD186x_C_SBRK);
port->COR2 &= ~COR2_ETC;
}
count = min_t(int, port->break_length, 0xff);
sx_out(bp, CD186x_TDR, CD186x_C_ESC);
sx_out(bp, CD186x_TDR, CD186x_C_DELAY);
sx_out(bp, CD186x_TDR, count);
port->break_length -= count;
if (port->break_length == 0)
port->break_length--;
} else {
sx_out(bp, CD186x_TDR, CD186x_C_ESC);
sx_out(bp, CD186x_TDR, CD186x_C_EBRK);
sx_out(bp, CD186x_COR2, port->COR2);
sx_wait_CCR(bp);
sx_out(bp, CD186x_CCR, CCR_CORCHG2);
port->break_length = 0;
}
func_exit();
return;
}
count = CD186x_NFIFO;
do {
sx_out(bp, CD186x_TDR, port->xmit_buf[port->xmit_tail++]);
port->xmit_tail = port->xmit_tail & (SERIAL_XMIT_SIZE-1);
if (--port->xmit_cnt <= 0)
break;
} while (--count > 0);
if (port->xmit_cnt <= 0) {
sx_out(bp, CD186x_CAR, port_No(port));
port->IER &= ~IER_TXRDY;
sx_out(bp, CD186x_IER, port->IER);
}
if (port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
func_exit();
}
static void sx_check_modem(struct specialix_board *bp)
{
struct specialix_port *port;
struct tty_struct *tty;
unsigned char mcr;
int msvr_cd;
dprintk(SX_DEBUG_SIGNALS, "Modem intr. ");
port = sx_get_port(bp, "Modem");
if (port == NULL)
return;
tty = port->port.tty;
mcr = sx_in(bp, CD186x_MCR);
if ((mcr & MCR_CDCHG)) {
dprintk(SX_DEBUG_SIGNALS, "CD just changed... ");
msvr_cd = sx_in(bp, CD186x_MSVR) & MSVR_CD;
if (msvr_cd) {
dprintk(SX_DEBUG_SIGNALS, "Waking up guys in open.\n");
wake_up_interruptible(&port->port.open_wait);
} else {
dprintk(SX_DEBUG_SIGNALS, "Sending HUP.\n");
tty_hangup(tty);
}
}
#ifdef SPECIALIX_BRAIN_DAMAGED_CTS
if (mcr & MCR_CTSCHG) {
if (sx_in(bp, CD186x_MSVR) & MSVR_CTS) {
tty->hw_stopped = 0;
port->IER |= IER_TXRDY;
if (port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
} else {
tty->hw_stopped = 1;
port->IER &= ~IER_TXRDY;
}
sx_out(bp, CD186x_IER, port->IER);
}
if (mcr & MCR_DSSXHG) {
if (sx_in(bp, CD186x_MSVR) & MSVR_DSR) {
tty->hw_stopped = 0;
port->IER |= IER_TXRDY;
if (port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
} else {
tty->hw_stopped = 1;
port->IER &= ~IER_TXRDY;
}
sx_out(bp, CD186x_IER, port->IER);
}
#endif
sx_out(bp, CD186x_MCR, 0);
}
static irqreturn_t sx_interrupt(int dummy, void *dev_id)
{
unsigned char status;
unsigned char ack;
struct specialix_board *bp = dev_id;
unsigned long loop = 0;
int saved_reg;
unsigned long flags;
func_enter();
spin_lock_irqsave(&bp->lock, flags);
dprintk(SX_DEBUG_FLOW, "enter %s port %d room: %ld\n", __func__,
port_No(sx_get_port(bp, "INT")),
SERIAL_XMIT_SIZE - sx_get_port(bp, "ITN")->xmit_cnt - 1);
if (!(bp->flags & SX_BOARD_ACTIVE)) {
dprintk(SX_DEBUG_IRQ, "sx: False interrupt. irq %d.\n",
bp->irq);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
return IRQ_NONE;
}
saved_reg = bp->reg;
while (++loop < 16) {
status = sx_in(bp, CD186x_SRSR) &
(SRSR_RREQint | SRSR_TREQint | SRSR_MREQint);
if (status == 0)
break;
if (status & SRSR_RREQint) {
ack = sx_in(bp, CD186x_RRAR);
if (ack == (SX_ID | GIVR_IT_RCV))
sx_receive(bp);
else if (ack == (SX_ID | GIVR_IT_REXC))
sx_receive_exc(bp);
else
printk(KERN_ERR
"sx%d: status: 0x%x Bad receive ack 0x%02x.\n",
board_No(bp), status, ack);
} else if (status & SRSR_TREQint) {
ack = sx_in(bp, CD186x_TRAR);
if (ack == (SX_ID | GIVR_IT_TX))
sx_transmit(bp);
else
printk(KERN_ERR "sx%d: status: 0x%x Bad transmit ack 0x%02x. port: %d\n",
board_No(bp), status, ack,
port_No(sx_get_port(bp, "Int")));
} else if (status & SRSR_MREQint) {
ack = sx_in(bp, CD186x_MRAR);
if (ack == (SX_ID | GIVR_IT_MODEM))
sx_check_modem(bp);
else
printk(KERN_ERR
"sx%d: status: 0x%x Bad modem ack 0x%02x.\n",
board_No(bp), status, ack);
}
sx_out(bp, CD186x_EOIR, 0);
}
bp->reg = saved_reg;
outb(bp->reg, bp->base + SX_ADDR_REG);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
return IRQ_HANDLED;
}
static void turn_ints_off(struct specialix_board *bp)
{
unsigned long flags;
func_enter();
spin_lock_irqsave(&bp->lock, flags);
(void) sx_in_off(bp, 0);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
}
static void turn_ints_on(struct specialix_board *bp)
{
unsigned long flags;
func_enter();
spin_lock_irqsave(&bp->lock, flags);
(void) sx_in(bp, 0);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
}
static int sx_setup_board(struct specialix_board *bp)
{
int error;
if (bp->flags & SX_BOARD_ACTIVE)
return 0;
if (bp->flags & SX_BOARD_IS_PCI)
error = request_irq(bp->irq, sx_interrupt,
IRQF_DISABLED | IRQF_SHARED, "specialix IO8+", bp);
else
error = request_irq(bp->irq, sx_interrupt,
IRQF_DISABLED, "specialix IO8+", bp);
if (error)
return error;
turn_ints_on(bp);
bp->flags |= SX_BOARD_ACTIVE;
return 0;
}
static void sx_shutdown_board(struct specialix_board *bp)
{
func_enter();
if (!(bp->flags & SX_BOARD_ACTIVE)) {
func_exit();
return;
}
bp->flags &= ~SX_BOARD_ACTIVE;
dprintk(SX_DEBUG_IRQ, "Freeing IRQ%d for board %d.\n",
bp->irq, board_No(bp));
free_irq(bp->irq, bp);
turn_ints_off(bp);
func_exit();
}
static unsigned int sx_crtscts(struct tty_struct *tty)
{
if (sx_rtscts)
return C_CRTSCTS(tty);
return 1;
}
static void sx_change_speed(struct specialix_board *bp,
struct specialix_port *port)
{
struct tty_struct *tty;
unsigned long baud;
long tmp;
unsigned char cor1 = 0, cor3 = 0;
unsigned char mcor1 = 0, mcor2 = 0;
static unsigned long again;
unsigned long flags;
func_enter();
tty = port->port.tty;
if (!tty || !tty->termios) {
func_exit();
return;
}
port->IER = 0;
port->COR2 = 0;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
if (sx_crtscts(tty))
port->MSVR = MSVR_DTR | (sx_in(bp, CD186x_MSVR) & MSVR_RTS);
else
port->MSVR = (sx_in(bp, CD186x_MSVR) & MSVR_RTS);
spin_unlock_irqrestore(&bp->lock, flags);
dprintk(SX_DEBUG_TERMIOS, "sx: got MSVR=%02x.\n", port->MSVR);
baud = tty_get_baud_rate(tty);
if (baud == 38400) {
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
baud = 57600;
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
baud = 115200;
}
if (!baud) {
dprintk(SX_DEBUG_TERMIOS, "Dropping DTR... Hmm....\n");
if (!sx_crtscts(tty)) {
port->MSVR &= ~MSVR_DTR;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_MSVR, port->MSVR);
spin_unlock_irqrestore(&bp->lock, flags);
} else
dprintk(SX_DEBUG_TERMIOS, "Can't drop DTR: no DTR.\n");
return;
} else {
if (!sx_crtscts(tty))
port->MSVR |= MSVR_DTR;
}
tmp = port->custom_divisor ;
if (tmp)
printk(KERN_INFO
"sx%d: Using custom baud rate divisor %ld. \n"
"This is an untested option, please be careful.\n",
port_No(port), tmp);
else
tmp = (((SX_OSCFREQ + baud/2) / baud + CD186x_TPC/2) /
CD186x_TPC);
if (tmp < 0x10 && time_before(again, jiffies)) {
again = jiffies + HZ * 60;
if (tmp >= 12) {
printk(KERN_INFO "sx%d: Baud rate divisor is %ld. \n"
"Performance degradation is possible.\n"
"Read specialix.txt for more info.\n",
port_No(port), tmp);
} else {
printk(KERN_INFO "sx%d: Baud rate divisor is %ld. \n"
"Warning: overstressing Cirrus chip. This might not work.\n"
"Read specialix.txt for more info.\n", port_No(port), tmp);
}
}
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_RBPRH, (tmp >> 8) & 0xff);
sx_out(bp, CD186x_TBPRH, (tmp >> 8) & 0xff);
sx_out(bp, CD186x_RBPRL, tmp & 0xff);
sx_out(bp, CD186x_TBPRL, tmp & 0xff);
spin_unlock_irqrestore(&bp->lock, flags);
if (port->custom_divisor)
baud = (SX_OSCFREQ + port->custom_divisor/2) /
port->custom_divisor;
baud = (baud + 5) / 10;
tmp = ((baud + HZ/2) / HZ) * 2 - CD186x_NFIFO;
port->wakeup_chars = (tmp < 0) ? 0 : ((tmp >= SERIAL_XMIT_SIZE) ?
SERIAL_XMIT_SIZE - 1 : tmp);
tmp = (SPECIALIX_TPS + SPECIALIX_TPS/2 + baud/2) / baud;
tmp = (tmp > 0xff) ? 0xff : tmp;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_RTPR, tmp);
spin_unlock_irqrestore(&bp->lock, flags);
switch (C_CSIZE(tty)) {
case CS5:
cor1 |= COR1_5BITS;
break;
case CS6:
cor1 |= COR1_6BITS;
break;
case CS7:
cor1 |= COR1_7BITS;
break;
case CS8:
cor1 |= COR1_8BITS;
break;
}
if (C_CSTOPB(tty))
cor1 |= COR1_2SB;
cor1 |= COR1_IGNORE;
if (C_PARENB(tty)) {
cor1 |= COR1_NORMPAR;
if (C_PARODD(tty))
cor1 |= COR1_ODDP;
if (I_INPCK(tty))
cor1 &= ~COR1_IGNORE;
}
port->mark_mask = RCSR_OE | RCSR_TOUT;
if (I_INPCK(tty))
port->mark_mask |= RCSR_FE | RCSR_PE;
if (I_BRKINT(tty) || I_PARMRK(tty))
port->mark_mask |= RCSR_BREAK;
if (I_IGNPAR(tty))
port->mark_mask &= ~(RCSR_FE | RCSR_PE);
if (I_IGNBRK(tty)) {
port->mark_mask &= ~RCSR_BREAK;
if (I_IGNPAR(tty))
port->mark_mask &= ~RCSR_OE;
}
if (C_CRTSCTS(tty)) {
#ifdef SPECIALIX_BRAIN_DAMAGED_CTS
port->IER |= IER_DSR | IER_CTS;
mcor1 |= MCOR1_DSRZD | MCOR1_CTSZD;
mcor2 |= MCOR2_DSROD | MCOR2_CTSOD;
spin_lock_irqsave(&bp->lock, flags);
tty->hw_stopped = !(sx_in(bp, CD186x_MSVR) &
(MSVR_CTS|MSVR_DSR));
spin_unlock_irqrestore(&bp->lock, flags);
#else
port->COR2 |= COR2_CTSAE;
#endif
}
if (I_IXON(tty)) {
port->COR2 |= COR2_TXIBE;
cor3 |= (COR3_FCT | COR3_SCDE);
if (I_IXANY(tty))
port->COR2 |= COR2_IXM;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_SCHR1, START_CHAR(tty));
sx_out(bp, CD186x_SCHR2, STOP_CHAR(tty));
sx_out(bp, CD186x_SCHR3, START_CHAR(tty));
sx_out(bp, CD186x_SCHR4, STOP_CHAR(tty));
spin_unlock_irqrestore(&bp->lock, flags);
}
if (!C_CLOCAL(tty)) {
port->IER |= IER_CD;
mcor1 |= MCOR1_CDZD;
mcor2 |= MCOR2_CDOD;
}
if (C_CREAD(tty))
port->IER |= IER_RXD;
cor3 |= sx_rxfifo;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_COR1, cor1);
sx_out(bp, CD186x_COR2, port->COR2);
sx_out(bp, CD186x_COR3, cor3);
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_CORCHG1 | CCR_CORCHG2 | CCR_CORCHG3);
dprintk(SX_DEBUG_TERMIOS, "Mcor1 = %02x, mcor2 = %02x.\n",
mcor1, mcor2);
sx_out(bp, CD186x_MCOR1, mcor1);
sx_out(bp, CD186x_MCOR2, mcor2);
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_TXEN | CCR_RXEN);
sx_out(bp, CD186x_IER, port->IER);
sx_out(bp, CD186x_MSVR, port->MSVR);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
}
static int sx_setup_port(struct specialix_board *bp,
struct specialix_port *port)
{
unsigned long flags;
func_enter();
if (port->port.flags & ASYNC_INITIALIZED) {
func_exit();
return 0;
}
if (!port->xmit_buf) {
unsigned long tmp;
tmp = get_zeroed_page(GFP_KERNEL);
if (tmp == 0L) {
func_exit();
return -ENOMEM;
}
if (port->xmit_buf) {
free_page(tmp);
func_exit();
return -ERESTARTSYS;
}
port->xmit_buf = (unsigned char *) tmp;
}
spin_lock_irqsave(&port->lock, flags);
if (port->port.tty)
clear_bit(TTY_IO_ERROR, &port->port.tty->flags);
port->xmit_cnt = port->xmit_head = port->xmit_tail = 0;
sx_change_speed(bp, port);
port->port.flags |= ASYNC_INITIALIZED;
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
return 0;
}
static void sx_shutdown_port(struct specialix_board *bp,
struct specialix_port *port)
{
struct tty_struct *tty;
int i;
unsigned long flags;
func_enter();
if (!(port->port.flags & ASYNC_INITIALIZED)) {
func_exit();
return;
}
if (sx_debug & SX_DEBUG_FIFO) {
dprintk(SX_DEBUG_FIFO,
"sx%d: port %d: %ld overruns, FIFO hits [ ",
board_No(bp), port_No(port), port->overrun);
for (i = 0; i < 10; i++)
dprintk(SX_DEBUG_FIFO, "%ld ", port->hits[i]);
dprintk(SX_DEBUG_FIFO, "].\n");
}
if (port->xmit_buf) {
free_page((unsigned long) port->xmit_buf);
port->xmit_buf = NULL;
}
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
tty = port->port.tty;
if (tty == NULL || C_HUPCL(tty)) {
sx_out(bp, CD186x_MSVDTR, 0);
}
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_SOFTRESET);
port->IER = 0;
sx_out(bp, CD186x_IER, port->IER);
spin_unlock_irqrestore(&bp->lock, flags);
if (tty)
set_bit(TTY_IO_ERROR, &tty->flags);
port->port.flags &= ~ASYNC_INITIALIZED;
if (!bp->count)
sx_shutdown_board(bp);
func_exit();
}
static int block_til_ready(struct tty_struct *tty, struct file *filp,
struct specialix_port *port)
{
DECLARE_WAITQUEUE(wait, current);
struct specialix_board *bp = port_Board(port);
int retval;
int do_clocal = 0;
int CD;
unsigned long flags;
func_enter();
if (tty_hung_up_p(filp) || port->port.flags & ASYNC_CLOSING) {
interruptible_sleep_on(&port->port.close_wait);
if (port->port.flags & ASYNC_HUP_NOTIFY) {
func_exit();
return -EAGAIN;
} else {
func_exit();
return -ERESTARTSYS;
}
}
if ((filp->f_flags & O_NONBLOCK) ||
(tty->flags & (1 << TTY_IO_ERROR))) {
port->port.flags |= ASYNC_NORMAL_ACTIVE;
func_exit();
return 0;
}
if (C_CLOCAL(tty))
do_clocal = 1;
retval = 0;
add_wait_queue(&port->port.open_wait, &wait);
spin_lock_irqsave(&port->lock, flags);
if (!tty_hung_up_p(filp))
port->port.count--;
spin_unlock_irqrestore(&port->lock, flags);
port->port.blocked_open++;
while (1) {
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
CD = sx_in(bp, CD186x_MSVR) & MSVR_CD;
if (sx_crtscts(tty)) {
port->MSVR |= MSVR_DTR;
sx_out(bp, CD186x_MSVR, port->MSVR);
} else {
port->MSVR |= MSVR_DTR;
sx_out(bp, CD186x_MSVR, port->MSVR);
}
spin_unlock_irqrestore(&bp->lock, flags);
set_current_state(TASK_INTERRUPTIBLE);
if (tty_hung_up_p(filp) ||
!(port->port.flags & ASYNC_INITIALIZED)) {
if (port->port.flags & ASYNC_HUP_NOTIFY)
retval = -EAGAIN;
else
retval = -ERESTARTSYS;
break;
}
if (!(port->port.flags & ASYNC_CLOSING) &&
(do_clocal || CD))
break;
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
tty_unlock();
schedule();
tty_lock();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&port->port.open_wait, &wait);
spin_lock_irqsave(&port->lock, flags);
if (!tty_hung_up_p(filp))
port->port.count++;
port->port.blocked_open--;
spin_unlock_irqrestore(&port->lock, flags);
if (retval) {
func_exit();
return retval;
}
port->port.flags |= ASYNC_NORMAL_ACTIVE;
func_exit();
return 0;
}
static int sx_open(struct tty_struct *tty, struct file *filp)
{
int board;
int error;
struct specialix_port *port;
struct specialix_board *bp;
int i;
unsigned long flags;
func_enter();
board = SX_BOARD(tty->index);
if (board >= SX_NBOARD || !(sx_board[board].flags & SX_BOARD_PRESENT)) {
func_exit();
return -ENODEV;
}
bp = &sx_board[board];
port = sx_port + board * SX_NPORT + SX_PORT(tty->index);
port->overrun = 0;
for (i = 0; i < 10; i++)
port->hits[i] = 0;
dprintk(SX_DEBUG_OPEN,
"Board = %d, bp = %p, port = %p, portno = %d.\n",
board, bp, port, SX_PORT(tty->index));
if (sx_paranoia_check(port, tty->name, "sx_open")) {
func_exit();
return -ENODEV;
}
error = sx_setup_board(bp);
if (error) {
func_exit();
return error;
}
spin_lock_irqsave(&bp->lock, flags);
port->port.count++;
bp->count++;
tty->driver_data = port;
port->port.tty = tty;
spin_unlock_irqrestore(&bp->lock, flags);
error = sx_setup_port(bp, port);
if (error) {
func_exit();
return error;
}
error = block_til_ready(tty, filp, port);
if (error) {
func_exit();
return error;
}
func_exit();
return 0;
}
static void sx_flush_buffer(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
unsigned long flags;
struct specialix_board *bp;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_flush_buffer")) {
func_exit();
return;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
port->xmit_cnt = port->xmit_head = port->xmit_tail = 0;
spin_unlock_irqrestore(&port->lock, flags);
tty_wakeup(tty);
func_exit();
}
static void sx_close(struct tty_struct *tty, struct file *filp)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
unsigned long timeout;
func_enter();
if (!port || sx_paranoia_check(port, tty->name, "close")) {
func_exit();
return;
}
spin_lock_irqsave(&port->lock, flags);
if (tty_hung_up_p(filp)) {
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
return;
}
bp = port_Board(port);
if (tty->count == 1 && port->port.count != 1) {
printk(KERN_ERR "sx%d: sx_close: bad port count;"
" tty->count is 1, port count is %d\n",
board_No(bp), port->port.count);
port->port.count = 1;
}
if (port->port.count > 1) {
port->port.count--;
bp->count--;
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
return;
}
port->port.flags |= ASYNC_CLOSING;
tty->closing = 1;
spin_unlock_irqrestore(&port->lock, flags);
dprintk(SX_DEBUG_OPEN, "Closing\n");
if (port->port.closing_wait != ASYNC_CLOSING_WAIT_NONE)
tty_wait_until_sent(tty, port->port.closing_wait);
dprintk(SX_DEBUG_OPEN, "Closed\n");
port->IER &= ~IER_RXD;
if (port->port.flags & ASYNC_INITIALIZED) {
port->IER &= ~IER_TXRDY;
port->IER |= IER_TXEMPTY;
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_IER, port->IER);
spin_unlock_irqrestore(&bp->lock, flags);
timeout = jiffies+HZ;
while (port->IER & IER_TXEMPTY) {
set_current_state(TASK_INTERRUPTIBLE);
msleep_interruptible(jiffies_to_msecs(port->timeout));
if (time_after(jiffies, timeout)) {
printk(KERN_INFO "Timeout waiting for close\n");
break;
}
}
}
if (--bp->count < 0) {
printk(KERN_ERR
"sx%d: sx_shutdown_port: bad board count: %d port: %d\n",
board_No(bp), bp->count, tty->index);
bp->count = 0;
}
if (--port->port.count < 0) {
printk(KERN_ERR
"sx%d: sx_close: bad port count for tty%d: %d\n",
board_No(bp), port_No(port), port->port.count);
port->port.count = 0;
}
sx_shutdown_port(bp, port);
sx_flush_buffer(tty);
tty_ldisc_flush(tty);
spin_lock_irqsave(&port->lock, flags);
tty->closing = 0;
port->port.tty = NULL;
spin_unlock_irqrestore(&port->lock, flags);
if (port->port.blocked_open) {
if (port->port.close_delay)
msleep_interruptible(
jiffies_to_msecs(port->port.close_delay));
wake_up_interruptible(&port->port.open_wait);
}
port->port.flags &= ~(ASYNC_NORMAL_ACTIVE|ASYNC_CLOSING);
wake_up_interruptible(&port->port.close_wait);
func_exit();
}
static int sx_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
int c, total = 0;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_write")) {
func_exit();
return 0;
}
bp = port_Board(port);
if (!port->xmit_buf) {
func_exit();
return 0;
}
while (1) {
spin_lock_irqsave(&port->lock, flags);
c = min_t(int, count, min(SERIAL_XMIT_SIZE - port->xmit_cnt - 1,
SERIAL_XMIT_SIZE - port->xmit_head));
if (c <= 0) {
spin_unlock_irqrestore(&port->lock, flags);
break;
}
memcpy(port->xmit_buf + port->xmit_head, buf, c);
port->xmit_head = (port->xmit_head + c) & (SERIAL_XMIT_SIZE-1);
port->xmit_cnt += c;
spin_unlock_irqrestore(&port->lock, flags);
buf += c;
count -= c;
total += c;
}
spin_lock_irqsave(&bp->lock, flags);
if (port->xmit_cnt && !tty->stopped && !tty->hw_stopped &&
!(port->IER & IER_TXRDY)) {
port->IER |= IER_TXRDY;
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_IER, port->IER);
}
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
return total;
}
static int sx_put_char(struct tty_struct *tty, unsigned char ch)
{
struct specialix_port *port = tty->driver_data;
unsigned long flags;
struct specialix_board *bp;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_put_char")) {
func_exit();
return 0;
}
dprintk(SX_DEBUG_TX, "check tty: %p %p\n", tty, port->xmit_buf);
if (!port->xmit_buf) {
func_exit();
return 0;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
dprintk(SX_DEBUG_TX, "xmit_cnt: %d xmit_buf: %p\n",
port->xmit_cnt, port->xmit_buf);
if (port->xmit_cnt >= SERIAL_XMIT_SIZE - 1 || !port->xmit_buf) {
spin_unlock_irqrestore(&port->lock, flags);
dprintk(SX_DEBUG_TX, "Exit size\n");
func_exit();
return 0;
}
dprintk(SX_DEBUG_TX, "Handle xmit: %p %p\n", port, port->xmit_buf);
port->xmit_buf[port->xmit_head++] = ch;
port->xmit_head &= SERIAL_XMIT_SIZE - 1;
port->xmit_cnt++;
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
return 1;
}
static void sx_flush_chars(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
unsigned long flags;
struct specialix_board *bp = port_Board(port);
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_flush_chars")) {
func_exit();
return;
}
if (port->xmit_cnt <= 0 || tty->stopped || tty->hw_stopped ||
!port->xmit_buf) {
func_exit();
return;
}
spin_lock_irqsave(&bp->lock, flags);
port->IER |= IER_TXRDY;
sx_out(port_Board(port), CD186x_CAR, port_No(port));
sx_out(port_Board(port), CD186x_IER, port->IER);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
}
static int sx_write_room(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
int ret;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_write_room")) {
func_exit();
return 0;
}
ret = SERIAL_XMIT_SIZE - port->xmit_cnt - 1;
if (ret < 0)
ret = 0;
func_exit();
return ret;
}
static int sx_chars_in_buffer(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_chars_in_buffer")) {
func_exit();
return 0;
}
func_exit();
return port->xmit_cnt;
}
static int sx_tiocmget(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned char status;
unsigned int result;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, __func__)) {
func_exit();
return -ENODEV;
}
bp = port_Board(port);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
status = sx_in(bp, CD186x_MSVR);
spin_unlock_irqrestore(&bp->lock, flags);
dprintk(SX_DEBUG_INIT, "Got msvr[%d] = %02x, car = %d.\n",
port_No(port), status, sx_in(bp, CD186x_CAR));
dprintk(SX_DEBUG_INIT, "sx_port = %p, port = %p\n", sx_port, port);
if (sx_crtscts(port->port.tty)) {
result = TIOCM_DTR | TIOCM_DSR
| ((status & MSVR_DTR) ? TIOCM_RTS : 0)
| ((status & MSVR_CD) ? TIOCM_CAR : 0)
| ((status & MSVR_CTS) ? TIOCM_CTS : 0);
} else {
result = TIOCM_RTS | TIOCM_DSR
| ((status & MSVR_DTR) ? TIOCM_DTR : 0)
| ((status & MSVR_CD) ? TIOCM_CAR : 0)
| ((status & MSVR_CTS) ? TIOCM_CTS : 0);
}
func_exit();
return result;
}
static int sx_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct specialix_port *port = tty->driver_data;
unsigned long flags;
struct specialix_board *bp;
func_enter();
if (sx_paranoia_check(port, tty->name, __func__)) {
func_exit();
return -ENODEV;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
if (sx_crtscts(port->port.tty)) {
if (set & TIOCM_RTS)
port->MSVR |= MSVR_DTR;
} else {
if (set & TIOCM_DTR)
port->MSVR |= MSVR_DTR;
}
if (sx_crtscts(port->port.tty)) {
if (clear & TIOCM_RTS)
port->MSVR &= ~MSVR_DTR;
} else {
if (clear & TIOCM_DTR)
port->MSVR &= ~MSVR_DTR;
}
spin_lock(&bp->lock);
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_MSVR, port->MSVR);
spin_unlock(&bp->lock);
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
return 0;
}
static int sx_send_break(struct tty_struct *tty, int length)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp = port_Board(port);
unsigned long flags;
func_enter();
if (length == 0 || length == -1)
return -EOPNOTSUPP;
spin_lock_irqsave(&port->lock, flags);
port->break_length = SPECIALIX_TPS / HZ * length;
port->COR2 |= COR2_ETC;
port->IER |= IER_TXRDY;
spin_lock(&bp->lock);
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_COR2, port->COR2);
sx_out(bp, CD186x_IER, port->IER);
spin_unlock(&bp->lock);
spin_unlock_irqrestore(&port->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_CORCHG2);
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
func_exit();
return 0;
}
static int sx_set_serial_info(struct specialix_port *port,
struct serial_struct __user *newinfo)
{
struct serial_struct tmp;
struct specialix_board *bp = port_Board(port);
int change_speed;
func_enter();
if (copy_from_user(&tmp, newinfo, sizeof(tmp))) {
func_exit();
return -EFAULT;
}
mutex_lock(&port->port.mutex);
change_speed = ((port->port.flags & ASYNC_SPD_MASK) !=
(tmp.flags & ASYNC_SPD_MASK));
change_speed |= (tmp.custom_divisor != port->custom_divisor);
if (!capable(CAP_SYS_ADMIN)) {
if ((tmp.close_delay != port->port.close_delay) ||
(tmp.closing_wait != port->port.closing_wait) ||
((tmp.flags & ~ASYNC_USR_MASK) !=
(port->port.flags & ~ASYNC_USR_MASK))) {
func_exit();
mutex_unlock(&port->port.mutex);
return -EPERM;
}
port->port.flags = ((port->port.flags & ~ASYNC_USR_MASK) |
(tmp.flags & ASYNC_USR_MASK));
port->custom_divisor = tmp.custom_divisor;
} else {
port->port.flags = ((port->port.flags & ~ASYNC_FLAGS) |
(tmp.flags & ASYNC_FLAGS));
port->port.close_delay = tmp.close_delay;
port->port.closing_wait = tmp.closing_wait;
port->custom_divisor = tmp.custom_divisor;
}
if (change_speed)
sx_change_speed(bp, port);
func_exit();
mutex_unlock(&port->port.mutex);
return 0;
}
static int sx_get_serial_info(struct specialix_port *port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
struct specialix_board *bp = port_Board(port);
func_enter();
memset(&tmp, 0, sizeof(tmp));
mutex_lock(&port->port.mutex);
tmp.type = PORT_CIRRUS;
tmp.line = port - sx_port;
tmp.port = bp->base;
tmp.irq = bp->irq;
tmp.flags = port->port.flags;
tmp.baud_base = (SX_OSCFREQ + CD186x_TPC/2) / CD186x_TPC;
tmp.close_delay = port->port.close_delay * HZ/100;
tmp.closing_wait = port->port.closing_wait * HZ/100;
tmp.custom_divisor = port->custom_divisor;
tmp.xmit_fifo_size = CD186x_NFIFO;
mutex_unlock(&port->port.mutex);
if (copy_to_user(retinfo, &tmp, sizeof(tmp))) {
func_exit();
return -EFAULT;
}
func_exit();
return 0;
}
static int sx_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct specialix_port *port = tty->driver_data;
void __user *argp = (void __user *)arg;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_ioctl")) {
func_exit();
return -ENODEV;
}
switch (cmd) {
case TIOCGSERIAL:
func_exit();
return sx_get_serial_info(port, argp);
case TIOCSSERIAL:
func_exit();
return sx_set_serial_info(port, argp);
default:
func_exit();
return -ENOIOCTLCMD;
}
func_exit();
return 0;
}
static void sx_throttle(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_throttle")) {
func_exit();
return;
}
bp = port_Board(port);
if (sx_crtscts(tty))
port->MSVR &= ~MSVR_DTR;
else {
printk(KERN_ERR
"sx%d: Need to throttle, but can't (hardware hs is off)\n",
port_No(port));
}
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CAR, port_No(port));
spin_unlock_irqrestore(&bp->lock, flags);
if (I_IXOFF(tty)) {
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_SSCH2);
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
}
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_MSVR, port->MSVR);
spin_unlock_irqrestore(&bp->lock, flags);
func_exit();
}
static void sx_unthrottle(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_unthrottle")) {
func_exit();
return;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
if (sx_crtscts(tty))
port->MSVR |= MSVR_DTR;
spin_lock(&bp->lock);
sx_out(bp, CD186x_CAR, port_No(port));
spin_unlock(&bp->lock);
if (I_IXOFF(tty)) {
spin_unlock_irqrestore(&port->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&bp->lock, flags);
sx_out(bp, CD186x_CCR, CCR_SSCH1);
spin_unlock_irqrestore(&bp->lock, flags);
sx_wait_CCR(bp);
spin_lock_irqsave(&port->lock, flags);
}
spin_lock(&bp->lock);
sx_out(bp, CD186x_MSVR, port->MSVR);
spin_unlock(&bp->lock);
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
}
static void sx_stop(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_stop")) {
func_exit();
return;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
port->IER &= ~IER_TXRDY;
spin_lock(&bp->lock);
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_IER, port->IER);
spin_unlock(&bp->lock);
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
}
static void sx_start(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_start")) {
func_exit();
return;
}
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
if (port->xmit_cnt && port->xmit_buf && !(port->IER & IER_TXRDY)) {
port->IER |= IER_TXRDY;
spin_lock(&bp->lock);
sx_out(bp, CD186x_CAR, port_No(port));
sx_out(bp, CD186x_IER, port->IER);
spin_unlock(&bp->lock);
}
spin_unlock_irqrestore(&port->lock, flags);
func_exit();
}
static void sx_hangup(struct tty_struct *tty)
{
struct specialix_port *port = tty->driver_data;
struct specialix_board *bp;
unsigned long flags;
func_enter();
if (sx_paranoia_check(port, tty->name, "sx_hangup")) {
func_exit();
return;
}
bp = port_Board(port);
sx_shutdown_port(bp, port);
spin_lock_irqsave(&port->lock, flags);
bp->count -= port->port.count;
if (bp->count < 0) {
printk(KERN_ERR
"sx%d: sx_hangup: bad board count: %d port: %d\n",
board_No(bp), bp->count, tty->index);
bp->count = 0;
}
port->port.count = 0;
port->port.flags &= ~ASYNC_NORMAL_ACTIVE;
port->port.tty = NULL;
spin_unlock_irqrestore(&port->lock, flags);
wake_up_interruptible(&port->port.open_wait);
func_exit();
}
static void sx_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct specialix_port *port = tty->driver_data;
unsigned long flags;
struct specialix_board *bp;
if (sx_paranoia_check(port, tty->name, "sx_set_termios"))
return;
bp = port_Board(port);
spin_lock_irqsave(&port->lock, flags);
sx_change_speed(port_Board(port), port);
spin_unlock_irqrestore(&port->lock, flags);
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios->c_cflag & CRTSCTS)) {
tty->hw_stopped = 0;
sx_start(tty);
}
}
static int sx_init_drivers(void)
{
int error;
int i;
func_enter();
specialix_driver = alloc_tty_driver(SX_NBOARD * SX_NPORT);
if (!specialix_driver) {
printk(KERN_ERR "sx: Couldn't allocate tty_driver.\n");
func_exit();
return 1;
}
specialix_driver->owner = THIS_MODULE;
specialix_driver->name = "ttyW";
specialix_driver->major = SPECIALIX_NORMAL_MAJOR;
specialix_driver->type = TTY_DRIVER_TYPE_SERIAL;
specialix_driver->subtype = SERIAL_TYPE_NORMAL;
specialix_driver->init_termios = tty_std_termios;
specialix_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
specialix_driver->init_termios.c_ispeed = 9600;
specialix_driver->init_termios.c_ospeed = 9600;
specialix_driver->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_HARDWARE_BREAK;
tty_set_operations(specialix_driver, &sx_ops);
error = tty_register_driver(specialix_driver);
if (error) {
put_tty_driver(specialix_driver);
printk(KERN_ERR
"sx: Couldn't register specialix IO8+ driver, error = %d\n",
error);
func_exit();
return 1;
}
memset(sx_port, 0, sizeof(sx_port));
for (i = 0; i < SX_NPORT * SX_NBOARD; i++) {
sx_port[i].magic = SPECIALIX_MAGIC;
tty_port_init(&sx_port[i].port);
spin_lock_init(&sx_port[i].lock);
}
func_exit();
return 0;
}
static void sx_release_drivers(void)
{
func_enter();
tty_unregister_driver(specialix_driver);
put_tty_driver(specialix_driver);
func_exit();
}
static int __init specialix_init(void)
{
int i;
int found = 0;
func_enter();
printk(KERN_INFO "sx: Specialix IO8+ driver v" VERSION ", (c) R.E.Wolff 1997/1998.\n");
printk(KERN_INFO "sx: derived from work (c) D.Gorodchanin 1994-1996.\n");
if (sx_rtscts)
printk(KERN_INFO
"sx: DTR/RTS pin is RTS when CRTSCTS is on.\n");
else
printk(KERN_INFO "sx: DTR/RTS pin is always RTS.\n");
for (i = 0; i < SX_NBOARD; i++)
spin_lock_init(&sx_board[i].lock);
if (sx_init_drivers()) {
func_exit();
return -EIO;
}
for (i = 0; i < SX_NBOARD; i++)
if (sx_board[i].base && !sx_probe(&sx_board[i]))
found++;
#ifdef CONFIG_PCI
{
struct pci_dev *pdev = NULL;
i = 0;
while (i < SX_NBOARD) {
if (sx_board[i].flags & SX_BOARD_PRESENT) {
i++;
continue;
}
pdev = pci_get_device(PCI_VENDOR_ID_SPECIALIX,
PCI_DEVICE_ID_SPECIALIX_IO8, pdev);
if (!pdev)
break;
if (pci_enable_device(pdev))
continue;
sx_board[i].irq = pdev->irq;
sx_board[i].base = pci_resource_start(pdev, 2);
sx_board[i].flags |= SX_BOARD_IS_PCI;
if (!sx_probe(&sx_board[i]))
found++;
}
if (pdev != NULL)
pci_dev_put(pdev);
}
#endif
if (!found) {
sx_release_drivers();
printk(KERN_INFO "sx: No specialix IO8+ boards detected.\n");
func_exit();
return -EIO;
}
func_exit();
return 0;
}
static int __init specialix_init_module(void)
{
int i;
func_enter();
if (iobase[0] || iobase[1] || iobase[2] || iobase[3]) {
for (i = 0; i < SX_NBOARD; i++) {
sx_board[i].base = iobase[i];
sx_board[i].irq = irq[i];
sx_board[i].count = 0;
}
}
func_exit();
return specialix_init();
}
static void __exit specialix_exit_module(void)
{
int i;
func_enter();
sx_release_drivers();
for (i = 0; i < SX_NBOARD; i++)
if (sx_board[i].flags & SX_BOARD_PRESENT)
sx_release_io_range(&sx_board[i]);
func_exit();
}
