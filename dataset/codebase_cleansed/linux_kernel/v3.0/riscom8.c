static int rc_paranoia_check(struct riscom_port const *port,
char *name, const char *routine)
{
#ifdef RISCOM_PARANOIA_CHECK
static const char badmagic[] = KERN_INFO
"rc: Warning: bad riscom port magic number for device %s in %s\n";
static const char badinfo[] = KERN_INFO
"rc: Warning: null riscom port for device %s in %s\n";
if (!port) {
printk(badinfo, name, routine);
return 1;
}
if (port->magic != RISCOM8_MAGIC) {
printk(badmagic, name, routine);
return 1;
}
#endif
return 0;
}
static inline int board_No(struct riscom_board const *bp)
{
return bp - rc_board;
}
static inline int port_No(struct riscom_port const *port)
{
return RC_PORT(port - rc_port);
}
static inline struct riscom_board *port_Board(struct riscom_port const *port)
{
return &rc_board[RC_BOARD(port - rc_port)];
}
static inline unsigned char rc_in(struct riscom_board const *bp,
unsigned short reg)
{
return inb(bp->base + RC_TO_ISA(reg));
}
static inline void rc_out(struct riscom_board const *bp, unsigned short reg,
unsigned char val)
{
outb(val, bp->base + RC_TO_ISA(reg));
}
static void rc_wait_CCR(struct riscom_board const *bp)
{
unsigned long delay;
for (delay = 100000; delay; delay--)
if (!rc_in(bp, CD180_CCR))
return;
printk(KERN_INFO "rc%d: Timeout waiting for CCR.\n", board_No(bp));
}
static int rc_request_io_range(struct riscom_board * const bp)
{
int i;
for (i = 0; i < RC_NIOPORT; i++)
if (!request_region(RC_TO_ISA(rc_ioport[i]) + bp->base, 1,
"RISCom/8")) {
goto out_release;
}
return 0;
out_release:
printk(KERN_INFO "rc%d: Skipping probe at 0x%03x. IO address in use.\n",
board_No(bp), bp->base);
while (--i >= 0)
release_region(RC_TO_ISA(rc_ioport[i]) + bp->base, 1);
return 1;
}
static void rc_release_io_range(struct riscom_board * const bp)
{
int i;
for (i = 0; i < RC_NIOPORT; i++)
release_region(RC_TO_ISA(rc_ioport[i]) + bp->base, 1);
}
static void __init rc_init_CD180(struct riscom_board const *bp)
{
unsigned long flags;
spin_lock_irqsave(&riscom_lock, flags);
rc_out(bp, RC_CTOUT, 0);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_HARDRESET);
spin_unlock_irqrestore(&riscom_lock, flags);
msleep(50);
spin_lock_irqsave(&riscom_lock, flags);
rc_out(bp, CD180_GIVR, RC_ID);
rc_out(bp, CD180_GICR, 0);
rc_out(bp, CD180_PILR1, RC_ACK_MINT);
rc_out(bp, CD180_PILR2, RC_ACK_TINT);
rc_out(bp, CD180_PILR3, RC_ACK_RINT);
rc_out(bp, CD180_PPRH, (RC_OSCFREQ/(1000000/RISCOM_TPS)) >> 8);
rc_out(bp, CD180_PPRL, (RC_OSCFREQ/(1000000/RISCOM_TPS)) & 0xff);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static int __init rc_probe(struct riscom_board *bp)
{
unsigned char val1, val2;
int irqs = 0;
int retries;
bp->irq = 0;
if (rc_request_io_range(bp))
return 1;
rc_out(bp, CD180_PPRL, 0x5a);
outb(0xff, 0x80);
val1 = rc_in(bp, CD180_PPRL);
rc_out(bp, CD180_PPRL, 0xa5);
outb(0x00, 0x80);
val2 = rc_in(bp, CD180_PPRL);
if ((val1 != 0x5a) || (val2 != 0xa5)) {
printk(KERN_ERR "rc%d: RISCom/8 Board at 0x%03x not found.\n",
board_No(bp), bp->base);
goto out_release;
}
for (retries = 0; retries < 5 && irqs <= 0; retries++) {
irqs = probe_irq_on();
rc_init_CD180(bp);
rc_out(bp, CD180_CAR, 2);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_TXEN);
rc_out(bp, CD180_IER, IER_TXRDY);
msleep(50);
irqs = probe_irq_off(irqs);
val1 = rc_in(bp, RC_BSR);
val2 = rc_in(bp, RC_ACK_TINT);
rc_init_CD180(bp);
if ((val1 & RC_BSR_TINT) || (val2 != (RC_ID | GIVR_IT_TX))) {
printk(KERN_ERR "rc%d: RISCom/8 Board at 0x%03x not "
"found.\n", board_No(bp), bp->base);
goto out_release;
}
}
if (irqs <= 0) {
printk(KERN_ERR "rc%d: Can't find IRQ for RISCom/8 board "
"at 0x%03x.\n", board_No(bp), bp->base);
goto out_release;
}
bp->irq = irqs;
bp->flags |= RC_BOARD_PRESENT;
printk(KERN_INFO "rc%d: RISCom/8 Rev. %c board detected at "
"0x%03x, IRQ %d.\n",
board_No(bp),
(rc_in(bp, CD180_GFRCR) & 0x0f) + 'A',
bp->base, bp->irq);
return 0;
out_release:
rc_release_io_range(bp);
return 1;
}
static struct riscom_port *rc_get_port(struct riscom_board const *bp,
unsigned char const *what)
{
unsigned char channel;
struct riscom_port *port;
channel = rc_in(bp, CD180_GICR) >> GICR_CHAN_OFF;
if (channel < CD180_NCH) {
port = &rc_port[board_No(bp) * RC_NPORT + channel];
if (port->port.flags & ASYNC_INITIALIZED)
return port;
}
printk(KERN_ERR "rc%d: %s interrupt from invalid port %d\n",
board_No(bp), what, channel);
return NULL;
}
static void rc_receive_exc(struct riscom_board const *bp)
{
struct riscom_port *port;
struct tty_struct *tty;
unsigned char status;
unsigned char ch, flag;
port = rc_get_port(bp, "Receive");
if (port == NULL)
return;
tty = tty_port_tty_get(&port->port);
#ifdef RC_REPORT_OVERRUN
status = rc_in(bp, CD180_RCSR);
if (status & RCSR_OE)
port->overrun++;
status &= port->mark_mask;
#else
status = rc_in(bp, CD180_RCSR) & port->mark_mask;
#endif
ch = rc_in(bp, CD180_RDR);
if (!status)
goto out;
if (status & RCSR_TOUT) {
printk(KERN_WARNING "rc%d: port %d: Receiver timeout. "
"Hardware problems ?\n",
board_No(bp), port_No(port));
goto out;
} else if (status & RCSR_BREAK) {
printk(KERN_INFO "rc%d: port %d: Handling break...\n",
board_No(bp), port_No(port));
flag = TTY_BREAK;
if (tty && (port->port.flags & ASYNC_SAK))
do_SAK(tty);
} else if (status & RCSR_PE)
flag = TTY_PARITY;
else if (status & RCSR_FE)
flag = TTY_FRAME;
else if (status & RCSR_OE)
flag = TTY_OVERRUN;
else
flag = TTY_NORMAL;
if (tty) {
tty_insert_flip_char(tty, ch, flag);
tty_flip_buffer_push(tty);
}
out:
tty_kref_put(tty);
}
static void rc_receive(struct riscom_board const *bp)
{
struct riscom_port *port;
struct tty_struct *tty;
unsigned char count;
port = rc_get_port(bp, "Receive");
if (port == NULL)
return;
tty = tty_port_tty_get(&port->port);
count = rc_in(bp, CD180_RDCR);
#ifdef RC_REPORT_FIFO
port->hits[count > 8 ? 9 : count]++;
#endif
while (count--) {
u8 ch = rc_in(bp, CD180_RDR);
if (tty)
tty_insert_flip_char(tty, ch, TTY_NORMAL);
}
if (tty) {
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
}
static void rc_transmit(struct riscom_board const *bp)
{
struct riscom_port *port;
struct tty_struct *tty;
unsigned char count;
port = rc_get_port(bp, "Transmit");
if (port == NULL)
return;
tty = tty_port_tty_get(&port->port);
if (port->IER & IER_TXEMPTY) {
rc_out(bp, CD180_CAR, port_No(port));
port->IER &= ~IER_TXEMPTY;
rc_out(bp, CD180_IER, port->IER);
goto out;
}
if ((port->xmit_cnt <= 0 && !port->break_length)
|| (tty && (tty->stopped || tty->hw_stopped))) {
rc_out(bp, CD180_CAR, port_No(port));
port->IER &= ~IER_TXRDY;
rc_out(bp, CD180_IER, port->IER);
goto out;
}
if (port->break_length) {
if (port->break_length > 0) {
if (port->COR2 & COR2_ETC) {
rc_out(bp, CD180_TDR, CD180_C_ESC);
rc_out(bp, CD180_TDR, CD180_C_SBRK);
port->COR2 &= ~COR2_ETC;
}
count = min_t(int, port->break_length, 0xff);
rc_out(bp, CD180_TDR, CD180_C_ESC);
rc_out(bp, CD180_TDR, CD180_C_DELAY);
rc_out(bp, CD180_TDR, count);
port->break_length -= count;
if (port->break_length == 0)
port->break_length--;
} else {
rc_out(bp, CD180_TDR, CD180_C_ESC);
rc_out(bp, CD180_TDR, CD180_C_EBRK);
rc_out(bp, CD180_COR2, port->COR2);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_CORCHG2);
port->break_length = 0;
}
goto out;
}
count = CD180_NFIFO;
do {
rc_out(bp, CD180_TDR, port->port.xmit_buf[port->xmit_tail++]);
port->xmit_tail = port->xmit_tail & (SERIAL_XMIT_SIZE-1);
if (--port->xmit_cnt <= 0)
break;
} while (--count > 0);
if (port->xmit_cnt <= 0) {
rc_out(bp, CD180_CAR, port_No(port));
port->IER &= ~IER_TXRDY;
rc_out(bp, CD180_IER, port->IER);
}
if (tty && port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
out:
tty_kref_put(tty);
}
static void rc_check_modem(struct riscom_board const *bp)
{
struct riscom_port *port;
struct tty_struct *tty;
unsigned char mcr;
port = rc_get_port(bp, "Modem");
if (port == NULL)
return;
tty = tty_port_tty_get(&port->port);
mcr = rc_in(bp, CD180_MCR);
if (mcr & MCR_CDCHG) {
if (rc_in(bp, CD180_MSVR) & MSVR_CD)
wake_up_interruptible(&port->port.open_wait);
else if (tty)
tty_hangup(tty);
}
#ifdef RISCOM_BRAIN_DAMAGED_CTS
if (mcr & MCR_CTSCHG) {
if (rc_in(bp, CD180_MSVR) & MSVR_CTS) {
port->IER |= IER_TXRDY;
if (tty) {
tty->hw_stopped = 0;
if (port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
}
} else {
if (tty)
tty->hw_stopped = 1;
port->IER &= ~IER_TXRDY;
}
rc_out(bp, CD180_IER, port->IER);
}
if (mcr & MCR_DSRCHG) {
if (rc_in(bp, CD180_MSVR) & MSVR_DSR) {
port->IER |= IER_TXRDY;
if (tty) {
tty->hw_stopped = 0;
if (port->xmit_cnt <= port->wakeup_chars)
tty_wakeup(tty);
}
} else {
if (tty)
tty->hw_stopped = 1;
port->IER &= ~IER_TXRDY;
}
rc_out(bp, CD180_IER, port->IER);
}
#endif
rc_out(bp, CD180_MCR, 0);
tty_kref_put(tty);
}
static irqreturn_t rc_interrupt(int dummy, void *dev_id)
{
unsigned char status;
unsigned char ack;
struct riscom_board *bp = dev_id;
unsigned long loop = 0;
int handled = 0;
if (!(bp->flags & RC_BOARD_ACTIVE))
return IRQ_NONE;
while ((++loop < 16) && ((status = ~(rc_in(bp, RC_BSR))) &
(RC_BSR_TOUT | RC_BSR_TINT |
RC_BSR_MINT | RC_BSR_RINT))) {
handled = 1;
if (status & RC_BSR_TOUT)
printk(KERN_WARNING "rc%d: Got timeout. Hardware "
"error?\n", board_No(bp));
else if (status & RC_BSR_RINT) {
ack = rc_in(bp, RC_ACK_RINT);
if (ack == (RC_ID | GIVR_IT_RCV))
rc_receive(bp);
else if (ack == (RC_ID | GIVR_IT_REXC))
rc_receive_exc(bp);
else
printk(KERN_WARNING "rc%d: Bad receive ack "
"0x%02x.\n",
board_No(bp), ack);
} else if (status & RC_BSR_TINT) {
ack = rc_in(bp, RC_ACK_TINT);
if (ack == (RC_ID | GIVR_IT_TX))
rc_transmit(bp);
else
printk(KERN_WARNING "rc%d: Bad transmit ack "
"0x%02x.\n",
board_No(bp), ack);
} else {
ack = rc_in(bp, RC_ACK_MINT);
if (ack == (RC_ID | GIVR_IT_MODEM))
rc_check_modem(bp);
else
printk(KERN_WARNING "rc%d: Bad modem ack "
"0x%02x.\n",
board_No(bp), ack);
}
rc_out(bp, CD180_EOIR, 0);
rc_out(bp, RC_CTOUT, 0);
}
return IRQ_RETVAL(handled);
}
static int rc_setup_board(struct riscom_board *bp)
{
int error;
if (bp->flags & RC_BOARD_ACTIVE)
return 0;
error = request_irq(bp->irq, rc_interrupt, IRQF_DISABLED,
"RISCom/8", bp);
if (error)
return error;
rc_out(bp, RC_CTOUT, 0);
bp->DTR = ~0;
rc_out(bp, RC_DTR, bp->DTR);
bp->flags |= RC_BOARD_ACTIVE;
return 0;
}
static void rc_shutdown_board(struct riscom_board *bp)
{
if (!(bp->flags & RC_BOARD_ACTIVE))
return;
bp->flags &= ~RC_BOARD_ACTIVE;
free_irq(bp->irq, NULL);
bp->DTR = ~0;
rc_out(bp, RC_DTR, bp->DTR);
}
static void rc_change_speed(struct tty_struct *tty, struct riscom_board *bp,
struct riscom_port *port)
{
unsigned long baud;
long tmp;
unsigned char cor1 = 0, cor3 = 0;
unsigned char mcor1 = 0, mcor2 = 0;
port->IER = 0;
port->COR2 = 0;
port->MSVR = MSVR_RTS;
baud = tty_get_baud_rate(tty);
rc_out(bp, CD180_CAR, port_No(port));
if (!baud) {
bp->DTR |= (1u << port_No(port));
rc_out(bp, RC_DTR, bp->DTR);
return;
} else {
bp->DTR &= ~(1u << port_No(port));
rc_out(bp, RC_DTR, bp->DTR);
}
tmp = (((RC_OSCFREQ + baud/2) / baud +
CD180_TPC/2) / CD180_TPC);
rc_out(bp, CD180_RBPRH, (tmp >> 8) & 0xff);
rc_out(bp, CD180_TBPRH, (tmp >> 8) & 0xff);
rc_out(bp, CD180_RBPRL, tmp & 0xff);
rc_out(bp, CD180_TBPRL, tmp & 0xff);
baud = (baud + 5) / 10;
tmp = ((baud + HZ/2) / HZ) * 2 - CD180_NFIFO;
port->wakeup_chars = (tmp < 0) ? 0 : ((tmp >= SERIAL_XMIT_SIZE) ?
SERIAL_XMIT_SIZE - 1 : tmp);
tmp = (RISCOM_TPS + RISCOM_TPS/2 + baud/2) / baud;
tmp = (tmp > 0xff) ? 0xff : tmp;
rc_out(bp, CD180_RTPR, tmp);
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
#ifdef RISCOM_BRAIN_DAMAGED_CTS
port->IER |= IER_DSR | IER_CTS;
mcor1 |= MCOR1_DSRZD | MCOR1_CTSZD;
mcor2 |= MCOR2_DSROD | MCOR2_CTSOD;
tty->hw_stopped = !(rc_in(bp, CD180_MSVR) &
(MSVR_CTS|MSVR_DSR));
#else
port->COR2 |= COR2_CTSAE;
#endif
}
if (I_IXON(tty)) {
port->COR2 |= COR2_TXIBE;
cor3 |= (COR3_FCT | COR3_SCDE);
if (I_IXANY(tty))
port->COR2 |= COR2_IXM;
rc_out(bp, CD180_SCHR1, START_CHAR(tty));
rc_out(bp, CD180_SCHR2, STOP_CHAR(tty));
rc_out(bp, CD180_SCHR3, START_CHAR(tty));
rc_out(bp, CD180_SCHR4, STOP_CHAR(tty));
}
if (!C_CLOCAL(tty)) {
port->IER |= IER_CD;
mcor1 |= MCOR1_CDZD;
mcor2 |= MCOR2_CDOD;
}
if (C_CREAD(tty))
port->IER |= IER_RXD;
cor3 |= RISCOM_RXFIFO;
rc_out(bp, CD180_COR1, cor1);
rc_out(bp, CD180_COR2, port->COR2);
rc_out(bp, CD180_COR3, cor3);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_CORCHG1 | CCR_CORCHG2 | CCR_CORCHG3);
rc_out(bp, CD180_MCOR1, mcor1);
rc_out(bp, CD180_MCOR2, mcor2);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_TXEN | CCR_RXEN);
rc_out(bp, CD180_IER, port->IER);
rc_out(bp, CD180_MSVR, port->MSVR);
}
static int rc_activate_port(struct tty_port *port, struct tty_struct *tty)
{
struct riscom_port *rp = container_of(port, struct riscom_port, port);
struct riscom_board *bp = port_Board(rp);
unsigned long flags;
if (tty_port_alloc_xmit_buf(port) < 0)
return -ENOMEM;
spin_lock_irqsave(&riscom_lock, flags);
clear_bit(TTY_IO_ERROR, &tty->flags);
bp->count++;
rp->xmit_cnt = rp->xmit_head = rp->xmit_tail = 0;
rc_change_speed(tty, bp, rp);
spin_unlock_irqrestore(&riscom_lock, flags);
return 0;
}
static void rc_shutdown_port(struct tty_struct *tty,
struct riscom_board *bp, struct riscom_port *port)
{
#ifdef RC_REPORT_OVERRUN
printk(KERN_INFO "rc%d: port %d: Total %ld overruns were detected.\n",
board_No(bp), port_No(port), port->overrun);
#endif
#ifdef RC_REPORT_FIFO
{
int i;
printk(KERN_INFO "rc%d: port %d: FIFO hits [ ",
board_No(bp), port_No(port));
for (i = 0; i < 10; i++)
printk("%ld ", port->hits[i]);
printk("].\n");
}
#endif
tty_port_free_xmit_buf(&port->port);
rc_out(bp, CD180_CAR, port_No(port));
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_SOFTRESET);
port->IER = 0;
rc_out(bp, CD180_IER, port->IER);
set_bit(TTY_IO_ERROR, &tty->flags);
if (--bp->count < 0) {
printk(KERN_INFO "rc%d: rc_shutdown_port: "
"bad board count: %d\n",
board_No(bp), bp->count);
bp->count = 0;
}
if (!bp->count)
rc_shutdown_board(bp);
}
static int carrier_raised(struct tty_port *port)
{
struct riscom_port *p = container_of(port, struct riscom_port, port);
struct riscom_board *bp = port_Board(p);
unsigned long flags;
int CD;
spin_lock_irqsave(&riscom_lock, flags);
rc_out(bp, CD180_CAR, port_No(p));
CD = rc_in(bp, CD180_MSVR) & MSVR_CD;
rc_out(bp, CD180_MSVR, MSVR_RTS);
bp->DTR &= ~(1u << port_No(p));
rc_out(bp, RC_DTR, bp->DTR);
spin_unlock_irqrestore(&riscom_lock, flags);
return CD;
}
static void dtr_rts(struct tty_port *port, int onoff)
{
struct riscom_port *p = container_of(port, struct riscom_port, port);
struct riscom_board *bp = port_Board(p);
unsigned long flags;
spin_lock_irqsave(&riscom_lock, flags);
bp->DTR &= ~(1u << port_No(p));
if (onoff == 0)
bp->DTR |= (1u << port_No(p));
rc_out(bp, RC_DTR, bp->DTR);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static int rc_open(struct tty_struct *tty, struct file *filp)
{
int board;
int error;
struct riscom_port *port;
struct riscom_board *bp;
board = RC_BOARD(tty->index);
if (board >= RC_NBOARD || !(rc_board[board].flags & RC_BOARD_PRESENT))
return -ENODEV;
bp = &rc_board[board];
port = rc_port + board * RC_NPORT + RC_PORT(tty->index);
if (rc_paranoia_check(port, tty->name, "rc_open"))
return -ENODEV;
error = rc_setup_board(bp);
if (error)
return error;
tty->driver_data = port;
return tty_port_open(&port->port, tty, filp);
}
static void rc_flush_buffer(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_flush_buffer"))
return;
spin_lock_irqsave(&riscom_lock, flags);
port->xmit_cnt = port->xmit_head = port->xmit_tail = 0;
spin_unlock_irqrestore(&riscom_lock, flags);
tty_wakeup(tty);
}
static void rc_close_port(struct tty_port *port)
{
unsigned long flags;
struct riscom_port *rp = container_of(port, struct riscom_port, port);
struct riscom_board *bp = port_Board(rp);
unsigned long timeout;
spin_lock_irqsave(&riscom_lock, flags);
rp->IER &= ~IER_RXD;
rp->IER &= ~IER_TXRDY;
rp->IER |= IER_TXEMPTY;
rc_out(bp, CD180_CAR, port_No(rp));
rc_out(bp, CD180_IER, rp->IER);
timeout = jiffies + HZ;
while (rp->IER & IER_TXEMPTY) {
spin_unlock_irqrestore(&riscom_lock, flags);
msleep_interruptible(jiffies_to_msecs(rp->timeout));
spin_lock_irqsave(&riscom_lock, flags);
if (time_after(jiffies, timeout))
break;
}
rc_shutdown_port(port->tty, bp, rp);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static void rc_close(struct tty_struct *tty, struct file *filp)
{
struct riscom_port *port = tty->driver_data;
if (!port || rc_paranoia_check(port, tty->name, "close"))
return;
tty_port_close(&port->port, tty, filp);
}
static int rc_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
int c, total = 0;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_write"))
return 0;
bp = port_Board(port);
while (1) {
spin_lock_irqsave(&riscom_lock, flags);
c = min_t(int, count, min(SERIAL_XMIT_SIZE - port->xmit_cnt - 1,
SERIAL_XMIT_SIZE - port->xmit_head));
if (c <= 0)
break;
memcpy(port->port.xmit_buf + port->xmit_head, buf, c);
port->xmit_head = (port->xmit_head + c) & (SERIAL_XMIT_SIZE-1);
port->xmit_cnt += c;
spin_unlock_irqrestore(&riscom_lock, flags);
buf += c;
count -= c;
total += c;
}
if (port->xmit_cnt && !tty->stopped && !tty->hw_stopped &&
!(port->IER & IER_TXRDY)) {
port->IER |= IER_TXRDY;
rc_out(bp, CD180_CAR, port_No(port));
rc_out(bp, CD180_IER, port->IER);
}
spin_unlock_irqrestore(&riscom_lock, flags);
return total;
}
static int rc_put_char(struct tty_struct *tty, unsigned char ch)
{
struct riscom_port *port = tty->driver_data;
unsigned long flags;
int ret = 0;
if (rc_paranoia_check(port, tty->name, "rc_put_char"))
return 0;
spin_lock_irqsave(&riscom_lock, flags);
if (port->xmit_cnt >= SERIAL_XMIT_SIZE - 1)
goto out;
port->port.xmit_buf[port->xmit_head++] = ch;
port->xmit_head &= SERIAL_XMIT_SIZE - 1;
port->xmit_cnt++;
ret = 1;
out:
spin_unlock_irqrestore(&riscom_lock, flags);
return ret;
}
static void rc_flush_chars(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_flush_chars"))
return;
if (port->xmit_cnt <= 0 || tty->stopped || tty->hw_stopped)
return;
spin_lock_irqsave(&riscom_lock, flags);
port->IER |= IER_TXRDY;
rc_out(port_Board(port), CD180_CAR, port_No(port));
rc_out(port_Board(port), CD180_IER, port->IER);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static int rc_write_room(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
int ret;
if (rc_paranoia_check(port, tty->name, "rc_write_room"))
return 0;
ret = SERIAL_XMIT_SIZE - port->xmit_cnt - 1;
if (ret < 0)
ret = 0;
return ret;
}
static int rc_chars_in_buffer(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
if (rc_paranoia_check(port, tty->name, "rc_chars_in_buffer"))
return 0;
return port->xmit_cnt;
}
static int rc_tiocmget(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
unsigned char status;
unsigned int result;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, __func__))
return -ENODEV;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
rc_out(bp, CD180_CAR, port_No(port));
status = rc_in(bp, CD180_MSVR);
result = rc_in(bp, RC_RI) & (1u << port_No(port)) ? 0 : TIOCM_RNG;
spin_unlock_irqrestore(&riscom_lock, flags);
result |= ((status & MSVR_RTS) ? TIOCM_RTS : 0)
| ((status & MSVR_DTR) ? TIOCM_DTR : 0)
| ((status & MSVR_CD) ? TIOCM_CAR : 0)
| ((status & MSVR_DSR) ? TIOCM_DSR : 0)
| ((status & MSVR_CTS) ? TIOCM_CTS : 0);
return result;
}
static int rc_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct riscom_port *port = tty->driver_data;
unsigned long flags;
struct riscom_board *bp;
if (rc_paranoia_check(port, tty->name, __func__))
return -ENODEV;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
if (set & TIOCM_RTS)
port->MSVR |= MSVR_RTS;
if (set & TIOCM_DTR)
bp->DTR &= ~(1u << port_No(port));
if (clear & TIOCM_RTS)
port->MSVR &= ~MSVR_RTS;
if (clear & TIOCM_DTR)
bp->DTR |= (1u << port_No(port));
rc_out(bp, CD180_CAR, port_No(port));
rc_out(bp, CD180_MSVR, port->MSVR);
rc_out(bp, RC_DTR, bp->DTR);
spin_unlock_irqrestore(&riscom_lock, flags);
return 0;
}
static int rc_send_break(struct tty_struct *tty, int length)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp = port_Board(port);
unsigned long flags;
if (length == 0 || length == -1)
return -EOPNOTSUPP;
spin_lock_irqsave(&riscom_lock, flags);
port->break_length = RISCOM_TPS / HZ * length;
port->COR2 |= COR2_ETC;
port->IER |= IER_TXRDY;
rc_out(bp, CD180_CAR, port_No(port));
rc_out(bp, CD180_COR2, port->COR2);
rc_out(bp, CD180_IER, port->IER);
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_CORCHG2);
rc_wait_CCR(bp);
spin_unlock_irqrestore(&riscom_lock, flags);
return 0;
}
static int rc_set_serial_info(struct tty_struct *tty, struct riscom_port *port,
struct serial_struct __user *newinfo)
{
struct serial_struct tmp;
struct riscom_board *bp = port_Board(port);
int change_speed;
if (copy_from_user(&tmp, newinfo, sizeof(tmp)))
return -EFAULT;
mutex_lock(&port->port.mutex);
change_speed = ((port->port.flags & ASYNC_SPD_MASK) !=
(tmp.flags & ASYNC_SPD_MASK));
if (!capable(CAP_SYS_ADMIN)) {
if ((tmp.close_delay != port->port.close_delay) ||
(tmp.closing_wait != port->port.closing_wait) ||
((tmp.flags & ~ASYNC_USR_MASK) !=
(port->port.flags & ~ASYNC_USR_MASK))) {
mutex_unlock(&port->port.mutex);
return -EPERM;
}
port->port.flags = ((port->port.flags & ~ASYNC_USR_MASK) |
(tmp.flags & ASYNC_USR_MASK));
} else {
port->port.flags = ((port->port.flags & ~ASYNC_FLAGS) |
(tmp.flags & ASYNC_FLAGS));
port->port.close_delay = tmp.close_delay;
port->port.closing_wait = tmp.closing_wait;
}
if (change_speed) {
unsigned long flags;
spin_lock_irqsave(&riscom_lock, flags);
rc_change_speed(tty, bp, port);
spin_unlock_irqrestore(&riscom_lock, flags);
}
mutex_unlock(&port->port.mutex);
return 0;
}
static int rc_get_serial_info(struct riscom_port *port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
struct riscom_board *bp = port_Board(port);
memset(&tmp, 0, sizeof(tmp));
tmp.type = PORT_CIRRUS;
tmp.line = port - rc_port;
mutex_lock(&port->port.mutex);
tmp.port = bp->base;
tmp.irq = bp->irq;
tmp.flags = port->port.flags;
tmp.baud_base = (RC_OSCFREQ + CD180_TPC/2) / CD180_TPC;
tmp.close_delay = port->port.close_delay * HZ/100;
tmp.closing_wait = port->port.closing_wait * HZ/100;
mutex_unlock(&port->port.mutex);
tmp.xmit_fifo_size = CD180_NFIFO;
return copy_to_user(retinfo, &tmp, sizeof(tmp)) ? -EFAULT : 0;
}
static int rc_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct riscom_port *port = tty->driver_data;
void __user *argp = (void __user *)arg;
int retval;
if (rc_paranoia_check(port, tty->name, "rc_ioctl"))
return -ENODEV;
switch (cmd) {
case TIOCGSERIAL:
retval = rc_get_serial_info(port, argp);
break;
case TIOCSSERIAL:
retval = rc_set_serial_info(tty, port, argp);
break;
default:
retval = -ENOIOCTLCMD;
}
return retval;
}
static void rc_throttle(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_throttle"))
return;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
port->MSVR &= ~MSVR_RTS;
rc_out(bp, CD180_CAR, port_No(port));
if (I_IXOFF(tty)) {
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_SSCH2);
rc_wait_CCR(bp);
}
rc_out(bp, CD180_MSVR, port->MSVR);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static void rc_unthrottle(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_unthrottle"))
return;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
port->MSVR |= MSVR_RTS;
rc_out(bp, CD180_CAR, port_No(port));
if (I_IXOFF(tty)) {
rc_wait_CCR(bp);
rc_out(bp, CD180_CCR, CCR_SSCH1);
rc_wait_CCR(bp);
}
rc_out(bp, CD180_MSVR, port->MSVR);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static void rc_stop(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_stop"))
return;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
port->IER &= ~IER_TXRDY;
rc_out(bp, CD180_CAR, port_No(port));
rc_out(bp, CD180_IER, port->IER);
spin_unlock_irqrestore(&riscom_lock, flags);
}
static void rc_start(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
struct riscom_board *bp;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_start"))
return;
bp = port_Board(port);
spin_lock_irqsave(&riscom_lock, flags);
if (port->xmit_cnt && port->port.xmit_buf && !(port->IER & IER_TXRDY)) {
port->IER |= IER_TXRDY;
rc_out(bp, CD180_CAR, port_No(port));
rc_out(bp, CD180_IER, port->IER);
}
spin_unlock_irqrestore(&riscom_lock, flags);
}
static void rc_hangup(struct tty_struct *tty)
{
struct riscom_port *port = tty->driver_data;
if (rc_paranoia_check(port, tty->name, "rc_hangup"))
return;
tty_port_hangup(&port->port);
}
static void rc_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct riscom_port *port = tty->driver_data;
unsigned long flags;
if (rc_paranoia_check(port, tty->name, "rc_set_termios"))
return;
spin_lock_irqsave(&riscom_lock, flags);
rc_change_speed(tty, port_Board(port), port);
spin_unlock_irqrestore(&riscom_lock, flags);
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios->c_cflag & CRTSCTS)) {
tty->hw_stopped = 0;
rc_start(tty);
}
}
static int __init rc_init_drivers(void)
{
int error;
int i;
riscom_driver = alloc_tty_driver(RC_NBOARD * RC_NPORT);
if (!riscom_driver)
return -ENOMEM;
riscom_driver->owner = THIS_MODULE;
riscom_driver->name = "ttyL";
riscom_driver->major = RISCOM8_NORMAL_MAJOR;
riscom_driver->type = TTY_DRIVER_TYPE_SERIAL;
riscom_driver->subtype = SERIAL_TYPE_NORMAL;
riscom_driver->init_termios = tty_std_termios;
riscom_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
riscom_driver->init_termios.c_ispeed = 9600;
riscom_driver->init_termios.c_ospeed = 9600;
riscom_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_HARDWARE_BREAK;
tty_set_operations(riscom_driver, &riscom_ops);
error = tty_register_driver(riscom_driver);
if (error != 0) {
put_tty_driver(riscom_driver);
printk(KERN_ERR "rc: Couldn't register RISCom/8 driver, "
"error = %d\n", error);
return 1;
}
memset(rc_port, 0, sizeof(rc_port));
for (i = 0; i < RC_NPORT * RC_NBOARD; i++) {
tty_port_init(&rc_port[i].port);
rc_port[i].port.ops = &riscom_port_ops;
rc_port[i].magic = RISCOM8_MAGIC;
}
return 0;
}
static void rc_release_drivers(void)
{
tty_unregister_driver(riscom_driver);
put_tty_driver(riscom_driver);
}
static int __init riscom8_setup(char *str)
{
int ints[RC_NBOARD];
int i;
str = get_options(str, ARRAY_SIZE(ints), ints);
for (i = 0; i < RC_NBOARD; i++) {
if (i < ints[0])
rc_board[i].base = ints[i+1];
else
rc_board[i].base = 0;
}
return 1;
}
static int __init riscom8_init(void)
{
int i;
int found = 0;
printk(banner);
if (rc_init_drivers())
return -EIO;
for (i = 0; i < RC_NBOARD; i++)
if (rc_board[i].base && !rc_probe(&rc_board[i]))
found++;
if (!found) {
rc_release_drivers();
printk(no_boards_msg);
return -EIO;
}
return 0;
}
static int __init riscom8_init_module(void)
{
#ifdef MODULE
int i;
if (iobase || iobase1 || iobase2 || iobase3) {
for (i = 0; i < RC_NBOARD; i++)
rc_board[i].base = 0;
}
if (iobase)
rc_board[0].base = iobase;
if (iobase1)
rc_board[1].base = iobase1;
if (iobase2)
rc_board[2].base = iobase2;
if (iobase3)
rc_board[3].base = iobase3;
#endif
return riscom8_init();
}
static void __exit riscom8_exit_module(void)
{
int i;
rc_release_drivers();
for (i = 0; i < RC_NBOARD; i++)
if (rc_board[i].flags & RC_BOARD_PRESENT)
rc_release_io_range(&rc_board[i]);
}
