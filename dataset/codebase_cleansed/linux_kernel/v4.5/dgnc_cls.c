static inline void cls_set_cts_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB | UART_EXAR654_EFR_CTSDSR);
isr_fcr &= ~(UART_EXAR654_EFR_IXON);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier |= (UART_EXAR654_IER_CTSDSR);
ier &= ~(UART_EXAR654_IER_XOFF);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_56 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
ch->ch_t_tlevel = 16;
}
static inline void cls_set_ixon_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB | UART_EXAR654_EFR_IXON);
isr_fcr &= ~(UART_EXAR654_EFR_CTSDSR);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(ch->ch_startc, &ch->ch_cls_uart->mcr);
writeb(0, &ch->ch_cls_uart->lsr);
writeb(ch->ch_stopc, &ch->ch_cls_uart->msr);
writeb(0, &ch->ch_cls_uart->spr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier &= ~(UART_EXAR654_IER_CTSDSR);
ier |= (UART_EXAR654_IER_XOFF);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_16 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
}
static inline void cls_set_no_output_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB);
isr_fcr &= ~(UART_EXAR654_EFR_CTSDSR | UART_EXAR654_EFR_IXON);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier &= ~(UART_EXAR654_IER_CTSDSR);
ier &= ~(UART_EXAR654_IER_XOFF);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_16 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
ch->ch_r_watermark = 0;
ch->ch_t_tlevel = 16;
ch->ch_r_tlevel = 16;
}
static inline void cls_set_rts_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB | UART_EXAR654_EFR_RTSDTR);
isr_fcr &= ~(UART_EXAR654_EFR_IXOFF);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier |= (UART_EXAR654_IER_RTSDTR);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_56 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
ch->ch_r_watermark = 4;
ch->ch_r_tlevel = 8;
}
static inline void cls_set_ixoff_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB | UART_EXAR654_EFR_IXOFF);
isr_fcr &= ~(UART_EXAR654_EFR_RTSDTR);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(ch->ch_startc, &ch->ch_cls_uart->mcr);
writeb(0, &ch->ch_cls_uart->lsr);
writeb(ch->ch_stopc, &ch->ch_cls_uart->msr);
writeb(0, &ch->ch_cls_uart->spr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier &= ~(UART_EXAR654_IER_RTSDTR);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_16 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
}
static inline void cls_set_no_input_flow_control(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char ier = readb(&ch->ch_cls_uart->ier);
unsigned char isr_fcr = 0;
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB);
isr_fcr &= ~(UART_EXAR654_EFR_RTSDTR | UART_EXAR654_EFR_IXOFF);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
ier &= ~(UART_EXAR654_IER_RTSDTR);
writeb(ier, &ch->ch_cls_uart->ier);
writeb((UART_FCR_ENABLE_FIFO), &ch->ch_cls_uart->isr_fcr);
writeb((UART_FCR_ENABLE_FIFO | UART_16654_FCR_RXTRIGGER_16 |
UART_16654_FCR_TXTRIGGER_16 | UART_FCR_CLEAR_RCVR),
&ch->ch_cls_uart->isr_fcr);
ch->ch_t_tlevel = 16;
ch->ch_r_tlevel = 16;
}
static inline void cls_clear_break(struct channel_t *ch, int force)
{
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
if (!ch->ch_stop_sending_break) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return;
}
if (ch->ch_flags & CH_BREAK_SENDING) {
if (time_after(jiffies, ch->ch_stop_sending_break) || force) {
unsigned char temp = readb(&ch->ch_cls_uart->lcr);
writeb((temp & ~UART_LCR_SBC), &ch->ch_cls_uart->lcr);
ch->ch_flags &= ~(CH_BREAK_SENDING);
ch->ch_stop_sending_break = 0;
}
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static inline void cls_parse_isr(struct dgnc_board *brd, uint port)
{
struct channel_t *ch;
unsigned char isr = 0;
unsigned long flags;
if (port >= brd->nasync)
return;
ch = brd->channels[port];
if (ch->magic != DGNC_CHANNEL_MAGIC)
return;
while (1) {
isr = readb(&ch->ch_cls_uart->isr_fcr);
if (isr & UART_IIR_NO_INT)
break;
if (isr & (UART_IIR_RDI | UART_IIR_RDI_TIMEOUT)) {
brd->intr_rx++;
ch->ch_intr_rx++;
cls_copy_data_from_uart_to_queue(ch);
dgnc_check_queue_flow_control(ch);
}
if (isr & UART_IIR_THRI) {
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
brd->intr_tx++;
ch->ch_intr_tx++;
spin_unlock_irqrestore(&ch->ch_lock, flags);
cls_copy_data_from_queue_to_uart(ch);
}
if (isr & UART_IIR_CTSRTS) {
brd->intr_modem++;
ch->ch_intr_modem++;
}
cls_parse_modem(ch, readb(&ch->ch_cls_uart->msr));
}
}
static void cls_param(struct tty_struct *tty)
{
unsigned char lcr = 0;
unsigned char uart_lcr = 0;
unsigned char ier = 0;
unsigned char uart_ier = 0;
uint baud = 9600;
int quot = 0;
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = (struct un_t *)tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
if ((ch->ch_c_cflag & (CBAUD)) == 0) {
ch->ch_r_head = 0;
ch->ch_r_tail = 0;
ch->ch_e_head = 0;
ch->ch_e_tail = 0;
ch->ch_w_head = 0;
ch->ch_w_tail = 0;
cls_flush_uart_write(ch);
cls_flush_uart_read(ch);
ch->ch_flags |= (CH_BAUD0);
ch->ch_mostat &= ~(UART_MCR_RTS | UART_MCR_DTR);
cls_assert_modem_signals(ch);
ch->ch_old_baud = 0;
return;
} else if (ch->ch_custom_speed) {
baud = ch->ch_custom_speed;
if (ch->ch_flags & CH_BAUD0) {
ch->ch_flags &= ~(CH_BAUD0);
if (!(ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat |= (UART_MCR_RTS);
if (!(ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat |= (UART_MCR_DTR);
}
} else {
int iindex = 0;
int jindex = 0;
ulong bauds[4][16] = {
{
0, 50, 75, 110,
134, 150, 200, 300,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 115200, 230400,
460800, 150, 200, 921600,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 76800, 115200,
131657, 153600, 230400, 460800,
921600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 115200, 230400,
460800, 150, 200, 921600,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 }
};
if (!(ch->ch_tun.un_flags & UN_ISOPEN) &&
(un->un_type == DGNC_PRINT))
baud = C_BAUD(ch->ch_pun.un_tty) & 0xff;
else
baud = C_BAUD(ch->ch_tun.un_tty) & 0xff;
if (ch->ch_c_cflag & CBAUDEX)
iindex = 1;
if (ch->ch_digi.digi_flags & DIGI_FAST)
iindex += 2;
jindex = baud;
if ((iindex >= 0) && (iindex < 4) && (jindex >= 0) &&
(jindex < 16)) {
baud = bauds[iindex][jindex];
} else {
baud = 0;
}
if (baud == 0)
baud = 9600;
if (ch->ch_flags & CH_BAUD0) {
ch->ch_flags &= ~(CH_BAUD0);
if (!(ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat |= (UART_MCR_RTS);
if (!(ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat |= (UART_MCR_DTR);
}
}
if (ch->ch_c_cflag & PARENB)
lcr |= UART_LCR_PARITY;
if (!(ch->ch_c_cflag & PARODD))
lcr |= UART_LCR_EPAR;
#ifdef CMSPAR
if (ch->ch_c_cflag & CMSPAR)
lcr |= UART_LCR_SPAR;
#endif
if (ch->ch_c_cflag & CSTOPB)
lcr |= UART_LCR_STOP;
switch (ch->ch_c_cflag & CSIZE) {
case CS5:
lcr |= UART_LCR_WLEN5;
break;
case CS6:
lcr |= UART_LCR_WLEN6;
break;
case CS7:
lcr |= UART_LCR_WLEN7;
break;
case CS8:
default:
lcr |= UART_LCR_WLEN8;
break;
}
uart_ier = readb(&ch->ch_cls_uart->ier);
ier = uart_ier;
uart_lcr = readb(&ch->ch_cls_uart->lcr);
if (baud == 0)
baud = 9600;
quot = ch->ch_bd->bd_dividend / baud;
if (quot != 0 && ch->ch_old_baud != baud) {
ch->ch_old_baud = baud;
writeb(UART_LCR_DLAB, &ch->ch_cls_uart->lcr);
writeb((quot & 0xff), &ch->ch_cls_uart->txrx);
writeb((quot >> 8), &ch->ch_cls_uart->ier);
writeb(lcr, &ch->ch_cls_uart->lcr);
}
if (uart_lcr != lcr)
writeb(lcr, &ch->ch_cls_uart->lcr);
if (ch->ch_c_cflag & CREAD)
ier |= (UART_IER_RDI | UART_IER_RLSI);
else
ier &= ~(UART_IER_RDI | UART_IER_RLSI);
if ((ch->ch_digi.digi_flags & CTSPACE) ||
(ch->ch_digi.digi_flags & RTSPACE) ||
(ch->ch_c_cflag & CRTSCTS) ||
!(ch->ch_digi.digi_flags & DIGI_FORCEDCD) ||
!(ch->ch_c_cflag & CLOCAL))
ier |= UART_IER_MSI;
else
ier &= ~UART_IER_MSI;
ier |= UART_IER_THRI;
if (ier != uart_ier)
writeb(ier, &ch->ch_cls_uart->ier);
if (ch->ch_digi.digi_flags & CTSPACE || ch->ch_c_cflag & CRTSCTS) {
cls_set_cts_flow_control(ch);
} else if (ch->ch_c_iflag & IXON) {
if ((ch->ch_startc == _POSIX_VDISABLE) ||
(ch->ch_stopc == _POSIX_VDISABLE))
cls_set_no_output_flow_control(ch);
else
cls_set_ixon_flow_control(ch);
} else {
cls_set_no_output_flow_control(ch);
}
if (ch->ch_digi.digi_flags & RTSPACE || ch->ch_c_cflag & CRTSCTS) {
cls_set_rts_flow_control(ch);
} else if (ch->ch_c_iflag & IXOFF) {
if ((ch->ch_startc == _POSIX_VDISABLE) ||
(ch->ch_stopc == _POSIX_VDISABLE))
cls_set_no_input_flow_control(ch);
else
cls_set_ixoff_flow_control(ch);
} else {
cls_set_no_input_flow_control(ch);
}
cls_assert_modem_signals(ch);
cls_parse_modem(ch, readb(&ch->ch_cls_uart->msr));
}
static void cls_tasklet(unsigned long data)
{
struct dgnc_board *bd = (struct dgnc_board *)data;
struct channel_t *ch;
unsigned long flags;
int i;
int state = 0;
int ports = 0;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
spin_lock_irqsave(&bd->bd_lock, flags);
state = bd->state;
ports = bd->nasync;
spin_unlock_irqrestore(&bd->bd_lock, flags);
spin_lock_irqsave(&bd->bd_intr_lock, flags);
if ((state == BOARD_READY) && (ports > 0)) {
for (i = 0; i < ports; i++) {
ch = bd->channels[i];
dgnc_input(ch);
cls_copy_data_from_queue_to_uart(ch);
dgnc_wakeup_writes(ch);
dgnc_carrier(ch);
if (ch->ch_stop_sending_break)
cls_clear_break(ch, 0);
}
}
spin_unlock_irqrestore(&bd->bd_intr_lock, flags);
}
static irqreturn_t cls_intr(int irq, void *voidbrd)
{
struct dgnc_board *brd = voidbrd;
uint i = 0;
unsigned char poll_reg;
unsigned long flags;
if (!brd || brd->magic != DGNC_BOARD_MAGIC)
return IRQ_NONE;
spin_lock_irqsave(&brd->bd_intr_lock, flags);
brd->intr_count++;
poll_reg = readb(brd->re_map_membase + UART_CLASSIC_POLL_ADDR_OFFSET);
if (!poll_reg) {
spin_unlock_irqrestore(&brd->bd_intr_lock, flags);
return IRQ_NONE;
}
for (i = 0; i < brd->nasync; i++)
cls_parse_isr(brd, i);
tasklet_schedule(&brd->helper_tasklet);
spin_unlock_irqrestore(&brd->bd_intr_lock, flags);
return IRQ_HANDLED;
}
static void cls_disable_receiver(struct channel_t *ch)
{
unsigned char tmp = readb(&ch->ch_cls_uart->ier);
tmp &= ~(UART_IER_RDI);
writeb(tmp, &ch->ch_cls_uart->ier);
}
static void cls_enable_receiver(struct channel_t *ch)
{
unsigned char tmp = readb(&ch->ch_cls_uart->ier);
tmp |= (UART_IER_RDI);
writeb(tmp, &ch->ch_cls_uart->ier);
}
static void cls_copy_data_from_uart_to_queue(struct channel_t *ch)
{
int qleft = 0;
unsigned char linestatus = 0;
unsigned char error_mask = 0;
ushort head;
ushort tail;
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
head = ch->ch_r_head;
tail = ch->ch_r_tail;
qleft = (tail - head - 1);
if (qleft < 0)
qleft += RQUEUEMASK + 1;
if (ch->ch_c_iflag & IGNBRK)
error_mask |= UART_LSR_BI;
while (1) {
linestatus = readb(&ch->ch_cls_uart->lsr);
if (!(linestatus & (UART_LSR_DR)))
break;
if (linestatus & error_mask) {
linestatus = 0;
readb(&ch->ch_cls_uart->txrx);
continue;
}
while (qleft < 1) {
tail = (tail + 1) & RQUEUEMASK;
ch->ch_r_tail = tail;
ch->ch_err_overrun++;
qleft++;
}
ch->ch_equeue[head] = linestatus & (UART_LSR_BI | UART_LSR_PE
| UART_LSR_FE);
ch->ch_rqueue[head] = readb(&ch->ch_cls_uart->txrx);
qleft--;
if (ch->ch_equeue[head] & UART_LSR_PE)
ch->ch_err_parity++;
if (ch->ch_equeue[head] & UART_LSR_BI)
ch->ch_err_break++;
if (ch->ch_equeue[head] & UART_LSR_FE)
ch->ch_err_frame++;
head = (head + 1) & RQUEUEMASK;
ch->ch_rxcount++;
}
ch->ch_r_head = head & RQUEUEMASK;
ch->ch_e_head = head & EQUEUEMASK;
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static int cls_drain(struct tty_struct *tty, uint seconds)
{
unsigned long flags;
struct channel_t *ch;
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return -ENXIO;
un = (struct un_t *)tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -ENXIO;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
spin_lock_irqsave(&ch->ch_lock, flags);
un->un_flags |= UN_EMPTY;
spin_unlock_irqrestore(&ch->ch_lock, flags);
return wait_event_interruptible(un->un_flags_wait,
((un->un_flags & UN_EMPTY) == 0));
}
static void cls_flush_uart_write(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
writeb((UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_XMIT),
&ch->ch_cls_uart->isr_fcr);
usleep_range(10, 20);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
}
static void cls_flush_uart_read(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
udelay(10);
}
static void cls_copy_data_from_queue_to_uart(struct channel_t *ch)
{
ushort head;
ushort tail;
int n;
int qlen;
uint len_written = 0;
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
if (ch->ch_w_tail == ch->ch_w_head)
goto exit_unlock;
if ((ch->ch_flags & CH_FORCED_STOP) ||
(ch->ch_flags & CH_BREAK_SENDING))
goto exit_unlock;
if (!(ch->ch_flags & (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM)))
goto exit_unlock;
n = 32;
head = ch->ch_w_head & WQUEUEMASK;
tail = ch->ch_w_tail & WQUEUEMASK;
qlen = (head - tail) & WQUEUEMASK;
n = min(n, qlen);
while (n > 0) {
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_RTS)) {
ch->ch_mostat |= (UART_MCR_RTS);
cls_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_DTR)) {
ch->ch_mostat |= (UART_MCR_DTR);
cls_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
writeb(ch->ch_wqueue[ch->ch_w_tail], &ch->ch_cls_uart->txrx);
ch->ch_w_tail++;
ch->ch_w_tail &= WQUEUEMASK;
ch->ch_txcount++;
len_written++;
n--;
}
if (len_written > 0)
ch->ch_flags &= ~(CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
exit_unlock:
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void cls_parse_modem(struct channel_t *ch, unsigned char signals)
{
unsigned char msignals = signals;
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
if (ch->ch_digi.digi_flags & DIGI_ALTPIN) {
unsigned char mswap = signals;
if (mswap & UART_MSR_DDCD) {
msignals &= ~UART_MSR_DDCD;
msignals |= UART_MSR_DDSR;
}
if (mswap & UART_MSR_DDSR) {
msignals &= ~UART_MSR_DDSR;
msignals |= UART_MSR_DDCD;
}
if (mswap & UART_MSR_DCD) {
msignals &= ~UART_MSR_DCD;
msignals |= UART_MSR_DSR;
}
if (mswap & UART_MSR_DSR) {
msignals &= ~UART_MSR_DSR;
msignals |= UART_MSR_DCD;
}
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
signals &= 0xf0;
spin_lock_irqsave(&ch->ch_lock, flags);
if (msignals & UART_MSR_DCD)
ch->ch_mistat |= UART_MSR_DCD;
else
ch->ch_mistat &= ~UART_MSR_DCD;
if (msignals & UART_MSR_DSR)
ch->ch_mistat |= UART_MSR_DSR;
else
ch->ch_mistat &= ~UART_MSR_DSR;
if (msignals & UART_MSR_RI)
ch->ch_mistat |= UART_MSR_RI;
else
ch->ch_mistat &= ~UART_MSR_RI;
if (msignals & UART_MSR_CTS)
ch->ch_mistat |= UART_MSR_CTS;
else
ch->ch_mistat &= ~UART_MSR_CTS;
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void cls_assert_modem_signals(struct channel_t *ch)
{
unsigned char out;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
out = ch->ch_mostat;
if (ch->ch_flags & CH_LOOPBACK)
out |= UART_MCR_LOOP;
writeb(out, &ch->ch_cls_uart->mcr);
udelay(10);
}
static void cls_send_start_character(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
if (ch->ch_startc != _POSIX_VDISABLE) {
ch->ch_xon_sends++;
writeb(ch->ch_startc, &ch->ch_cls_uart->txrx);
}
}
static void cls_send_stop_character(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
if (ch->ch_stopc != _POSIX_VDISABLE) {
ch->ch_xoff_sends++;
writeb(ch->ch_stopc, &ch->ch_cls_uart->txrx);
}
}
static void cls_uart_init(struct channel_t *ch)
{
unsigned char lcrb = readb(&ch->ch_cls_uart->lcr);
unsigned char isr_fcr = 0;
writeb(0, &ch->ch_cls_uart->ier);
writeb(UART_EXAR654_ENHANCED_REGISTER_SET, &ch->ch_cls_uart->lcr);
isr_fcr = readb(&ch->ch_cls_uart->isr_fcr);
isr_fcr |= (UART_EXAR654_EFR_ECB);
writeb(isr_fcr, &ch->ch_cls_uart->isr_fcr);
writeb(lcrb, &ch->ch_cls_uart->lcr);
readb(&ch->ch_cls_uart->txrx);
writeb((UART_FCR_ENABLE_FIFO|UART_FCR_CLEAR_RCVR|UART_FCR_CLEAR_XMIT),
&ch->ch_cls_uart->isr_fcr);
udelay(10);
ch->ch_flags |= (CH_FIFO_ENABLED | CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
readb(&ch->ch_cls_uart->lsr);
readb(&ch->ch_cls_uart->msr);
}
static void cls_uart_off(struct channel_t *ch)
{
writeb(0, &ch->ch_cls_uart->ier);
}
static uint cls_get_uart_bytes_left(struct channel_t *ch)
{
unsigned char left = 0;
unsigned char lsr = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
lsr = readb(&ch->ch_cls_uart->lsr);
if (!(lsr & UART_LSR_TEMT)) {
if (ch->ch_flags & CH_TX_FIFO_EMPTY)
tasklet_schedule(&ch->ch_bd->helper_tasklet);
left = 1;
} else {
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
left = 0;
}
return left;
}
static void cls_send_break(struct channel_t *ch, int msecs)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
if (msecs == 0) {
if (ch->ch_flags & CH_BREAK_SENDING) {
unsigned char temp = readb(&ch->ch_cls_uart->lcr);
writeb((temp & ~UART_LCR_SBC), &ch->ch_cls_uart->lcr);
ch->ch_flags &= ~(CH_BREAK_SENDING);
ch->ch_stop_sending_break = 0;
}
return;
}
ch->ch_stop_sending_break = jiffies + dgnc_jiffies_from_ms(msecs);
if (!(ch->ch_flags & CH_BREAK_SENDING)) {
unsigned char temp = readb(&ch->ch_cls_uart->lcr);
writeb((temp | UART_LCR_SBC), &ch->ch_cls_uart->lcr);
ch->ch_flags |= (CH_BREAK_SENDING);
}
}
static void cls_send_immediate_char(struct channel_t *ch, unsigned char c)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
writeb(c, &ch->ch_cls_uart->txrx);
}
static void cls_vpd(struct dgnc_board *brd)
{
ulong vpdbase;
u8 __iomem *re_map_vpdbase;
int i = 0;
vpdbase = pci_resource_start(brd->pdev, 3);
if (!vpdbase)
return;
re_map_vpdbase = ioremap(vpdbase, 0x400);
if (!re_map_vpdbase)
return;
for (i = 0; i < 0x40; i++) {
brd->vpd[i] = readb(re_map_vpdbase + i);
pr_info("%x ", brd->vpd[i]);
}
pr_info("\n");
iounmap(re_map_vpdbase);
}
