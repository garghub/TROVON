static inline void neo_pci_posting_flush(struct dgnc_board *bd)
{
readb(bd->re_map_membase + 0x8D);
}
static inline void neo_set_cts_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Setting CTSFLOW\n"));
#if 1
ier |= (UART_17158_IER_CTSDSR);
#else
ier &= ~(UART_17158_IER_CTSDSR);
#endif
efr |= (UART_17158_EFR_ECB | UART_17158_EFR_CTSDSR);
efr &= ~(UART_17158_EFR_IXON);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_4DELAY), &ch->ch_neo_uart->fctr);
writeb(8, &ch->ch_neo_uart->tfifo);
ch->ch_t_tlevel = 8;
writeb(ier, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_rts_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Setting RTSFLOW\n"));
#if 1
ier |= (UART_17158_IER_RTSDTR);
#else
ier &= ~(UART_17158_IER_RTSDTR);
#endif
efr |= (UART_17158_EFR_ECB | UART_17158_EFR_RTSDTR);
ier &= ~(UART_17158_IER_XOFF);
efr &= ~(UART_17158_EFR_IXOFF);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_4DELAY), &ch->ch_neo_uart->fctr);
ch->ch_r_watermark = 4;
writeb(32, &ch->ch_neo_uart->rfifo);
ch->ch_r_tlevel = 32;
writeb(ier, &ch->ch_neo_uart->ier);
ch->ch_mostat |= (UART_MCR_RTS);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_ixon_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Setting IXON FLOW\n"));
ier &= ~(UART_17158_IER_CTSDSR);
efr &= ~(UART_17158_EFR_CTSDSR);
efr |= (UART_17158_EFR_ECB | UART_17158_EFR_IXON);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_8DELAY), &ch->ch_neo_uart->fctr);
ch->ch_r_watermark = 4;
writeb(32, &ch->ch_neo_uart->rfifo);
ch->ch_r_tlevel = 32;
writeb(ch->ch_startc, &ch->ch_neo_uart->xonchar1);
writeb(0, &ch->ch_neo_uart->xonchar2);
writeb(ch->ch_stopc, &ch->ch_neo_uart->xoffchar1);
writeb(0, &ch->ch_neo_uart->xoffchar2);
writeb(ier, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_ixoff_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Setting IXOFF FLOW\n"));
ier &= ~(UART_17158_IER_RTSDTR);
efr &= ~(UART_17158_EFR_RTSDTR);
ier |= (UART_17158_IER_XOFF);
efr |= (UART_17158_EFR_ECB | UART_17158_EFR_IXOFF);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_8DELAY), &ch->ch_neo_uart->fctr);
writeb(8, &ch->ch_neo_uart->tfifo);
ch->ch_t_tlevel = 8;
writeb(ch->ch_startc, &ch->ch_neo_uart->xonchar1);
writeb(0, &ch->ch_neo_uart->xonchar2);
writeb(ch->ch_stopc, &ch->ch_neo_uart->xoffchar1);
writeb(0, &ch->ch_neo_uart->xoffchar2);
writeb(ier, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_no_input_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Unsetting Input FLOW\n"));
ier &= ~(UART_17158_IER_RTSDTR);
efr &= ~(UART_17158_EFR_RTSDTR);
ier &= ~(UART_17158_IER_XOFF);
if (ch->ch_c_iflag & IXON)
efr &= ~(UART_17158_EFR_IXOFF);
else
efr &= ~(UART_17158_EFR_ECB | UART_17158_EFR_IXOFF);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_8DELAY), &ch->ch_neo_uart->fctr);
ch->ch_r_watermark = 0;
writeb(16, &ch->ch_neo_uart->tfifo);
ch->ch_t_tlevel = 16;
writeb(16, &ch->ch_neo_uart->rfifo);
ch->ch_r_tlevel = 16;
writeb(ier, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_no_output_flow_control(struct channel_t *ch)
{
uchar ier = readb(&ch->ch_neo_uart->ier);
uchar efr = readb(&ch->ch_neo_uart->efr);
DPR_PARAM(("Unsetting Output FLOW\n"));
ier &= ~(UART_17158_IER_CTSDSR);
efr &= ~(UART_17158_EFR_CTSDSR);
if (ch->ch_c_iflag & IXOFF)
efr &= ~(UART_17158_EFR_IXON);
else
efr &= ~(UART_17158_EFR_ECB | UART_17158_EFR_IXON);
writeb(0, &ch->ch_neo_uart->efr);
writeb(efr, &ch->ch_neo_uart->efr);
writeb((UART_17158_FCTR_TRGD | UART_17158_FCTR_RTS_8DELAY), &ch->ch_neo_uart->fctr);
ch->ch_r_watermark = 0;
writeb(16, &ch->ch_neo_uart->tfifo);
ch->ch_t_tlevel = 16;
writeb(16, &ch->ch_neo_uart->rfifo);
ch->ch_r_tlevel = 16;
writeb(ier, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_set_new_start_stop_chars(struct channel_t *ch)
{
if (ch->ch_digi.digi_flags & (CTSPACE | RTSPACE) || ch->ch_c_cflag & CRTSCTS)
return;
DPR_PARAM(("In new start stop chars\n"));
writeb(ch->ch_startc, &ch->ch_neo_uart->xonchar1);
writeb(0, &ch->ch_neo_uart->xonchar2);
writeb(ch->ch_stopc, &ch->ch_neo_uart->xoffchar1);
writeb(0, &ch->ch_neo_uart->xoffchar2);
neo_pci_posting_flush(ch->ch_bd);
}
static inline void neo_clear_break(struct channel_t *ch, int force)
{
ulong lock_flags;
DGNC_LOCK(ch->ch_lock, lock_flags);
if (!ch->ch_stop_sending_break) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if (ch->ch_flags & CH_BREAK_SENDING) {
if (time_after_eq(jiffies, ch->ch_stop_sending_break)
|| force) {
uchar temp = readb(&ch->ch_neo_uart->lcr);
writeb((temp & ~UART_LCR_SBC), &ch->ch_neo_uart->lcr);
neo_pci_posting_flush(ch->ch_bd);
ch->ch_flags &= ~(CH_BREAK_SENDING);
ch->ch_stop_sending_break = 0;
DPR_IOCTL(("Finishing UART_LCR_SBC! finished: %lx\n", jiffies));
}
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
static inline void neo_parse_isr(struct dgnc_board *brd, uint port)
{
struct channel_t *ch;
uchar isr;
uchar cause;
ulong lock_flags;
if (!brd || brd->magic != DGNC_BOARD_MAGIC)
return;
if (port > brd->maxports)
return;
ch = brd->channels[port];
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
while (1) {
isr = readb(&ch->ch_neo_uart->isr_fcr);
if (isr & UART_IIR_NO_INT)
break;
isr &= ~(UART_17158_IIR_FIFO_ENABLED);
DPR_INTR(("%s:%d isr: %x\n", __FILE__, __LINE__, isr));
if (isr & (UART_17158_IIR_RDI_TIMEOUT | UART_IIR_RDI)) {
brd->intr_rx++;
ch->ch_intr_rx++;
neo_copy_data_from_uart_to_queue(ch);
DGNC_LOCK(ch->ch_lock, lock_flags);
dgnc_check_queue_flow_control(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
if (isr & UART_IIR_THRI) {
brd->intr_tx++;
ch->ch_intr_tx++;
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
neo_copy_data_from_queue_to_uart(ch);
}
if (isr & UART_17158_IIR_XONXOFF) {
cause = readb(&ch->ch_neo_uart->xoffchar1);
DPR_INTR(("Port %d. Got ISR_XONXOFF: cause:%x\n", port, cause));
if (cause == UART_17158_XON_DETECT) {
if (brd->channels[port]->ch_flags & CH_STOP) {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags &= ~(CH_STOP);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
DPR_INTR(("Port %d. XON detected in incoming data\n", port));
} else if (cause == UART_17158_XOFF_DETECT) {
if (!(brd->channels[port]->ch_flags & CH_STOP)) {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= CH_STOP;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_INTR(("Setting CH_STOP\n"));
}
DPR_INTR(("Port: %d. XOFF detected in incoming data\n", port));
}
}
if (isr & UART_17158_IIR_HWFLOW_STATE_CHANGE) {
brd->intr_modem++;
ch->ch_intr_modem++;
cause = readb(&ch->ch_neo_uart->mcr);
if ((cause & 0x4) == 0) {
if (cause & UART_MCR_RTS) {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_mostat |= UART_MCR_RTS;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
} else {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_mostat &= ~(UART_MCR_RTS);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
} else {
if (cause & UART_MCR_DTR) {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_mostat |= UART_MCR_DTR;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
} else {
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_mostat &= ~(UART_MCR_DTR);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
}
}
DPR_INTR(("MOD_STAT: sending to parse_modem_sigs\n"));
neo_parse_modem(ch, readb(&ch->ch_neo_uart->msr));
}
}
static inline void neo_parse_lsr(struct dgnc_board *brd, uint port)
{
struct channel_t *ch;
int linestatus;
ulong lock_flags;
if (!brd)
return;
if (brd->magic != DGNC_BOARD_MAGIC)
return;
if (port > brd->maxports)
return;
ch = brd->channels[port];
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
linestatus = readb(&ch->ch_neo_uart->lsr);
DPR_INTR(("%s:%d port: %d linestatus: %x\n", __FILE__, __LINE__, port, linestatus));
ch->ch_cached_lsr |= linestatus;
if (ch->ch_cached_lsr & UART_LSR_DR) {
brd->intr_rx++;
ch->ch_intr_rx++;
neo_copy_data_from_uart_to_queue(ch);
DGNC_LOCK(ch->ch_lock, lock_flags);
dgnc_check_queue_flow_control(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
if (linestatus & UART_17158_RX_FIFO_DATA_ERROR) {
DPR_INTR(("%s:%d Port: %d Got an RX error, need to parse LSR\n",
__FILE__, __LINE__, port));
}
if (linestatus & UART_LSR_PE) {
ch->ch_err_parity++;
DPR_INTR(("%s:%d Port: %d. PAR ERR!\n", __FILE__, __LINE__, port));
}
if (linestatus & UART_LSR_FE) {
ch->ch_err_frame++;
DPR_INTR(("%s:%d Port: %d. FRM ERR!\n", __FILE__, __LINE__, port));
}
if (linestatus & UART_LSR_BI) {
ch->ch_err_break++;
DPR_INTR(("%s:%d Port: %d. BRK INTR!\n", __FILE__, __LINE__, port));
}
if (linestatus & UART_LSR_OE) {
ch->ch_err_overrun++;
DPR_INTR(("%s:%d Port: %d. Rx Overrun!\n", __FILE__, __LINE__, port));
}
if (linestatus & UART_LSR_THRE) {
brd->intr_tx++;
ch->ch_intr_tx++;
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
neo_copy_data_from_queue_to_uart(ch);
} else if (linestatus & UART_17158_TX_AND_FIFO_CLR) {
brd->intr_tx++;
ch->ch_intr_tx++;
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
neo_copy_data_from_queue_to_uart(ch);
}
}
static void neo_param(struct tty_struct *tty)
{
uchar lcr = 0;
uchar uart_lcr = 0;
uchar ier = 0;
uchar uart_ier = 0;
uint baud = 9600;
int quot = 0;
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = (struct un_t *) tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DPR_PARAM(("param start: tdev: %x cflags: %x oflags: %x iflags: %x\n",
ch->ch_tun.un_dev, ch->ch_c_cflag, ch->ch_c_oflag, ch->ch_c_iflag));
if ((ch->ch_c_cflag & (CBAUD)) == 0) {
ch->ch_r_head = ch->ch_r_tail = 0;
ch->ch_e_head = ch->ch_e_tail = 0;
ch->ch_w_head = ch->ch_w_tail = 0;
neo_flush_uart_write(ch);
neo_flush_uart_read(ch);
ch->ch_flags |= (CH_BAUD0);
ch->ch_mostat &= ~(UART_MCR_RTS | UART_MCR_DTR);
neo_assert_modem_signals(ch);
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
if (!(ch->ch_tun.un_flags & UN_ISOPEN) && (un->un_type == DGNC_PRINT))
baud = C_BAUD(ch->ch_pun.un_tty) & 0xff;
else
baud = C_BAUD(ch->ch_tun.un_tty) & 0xff;
if (ch->ch_c_cflag & CBAUDEX)
iindex = 1;
if (ch->ch_digi.digi_flags & DIGI_FAST)
iindex += 2;
jindex = baud;
if ((iindex >= 0) && (iindex < 4) && (jindex >= 0) && (jindex < 16)) {
baud = bauds[iindex][jindex];
} else {
DPR_IOCTL(("baud indices were out of range (%d)(%d)",
iindex, jindex));
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
ier = uart_ier = readb(&ch->ch_neo_uart->ier);
uart_lcr = readb(&ch->ch_neo_uart->lcr);
if (baud == 0)
baud = 9600;
quot = ch->ch_bd->bd_dividend / baud;
if (quot != 0 && ch->ch_old_baud != baud) {
ch->ch_old_baud = baud;
writeb(UART_LCR_DLAB, &ch->ch_neo_uart->lcr);
writeb((quot & 0xff), &ch->ch_neo_uart->txrx);
writeb((quot >> 8), &ch->ch_neo_uart->ier);
writeb(lcr, &ch->ch_neo_uart->lcr);
}
if (uart_lcr != lcr)
writeb(lcr, &ch->ch_neo_uart->lcr);
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
writeb(ier, &ch->ch_neo_uart->ier);
neo_set_new_start_stop_chars(ch);
if (ch->ch_digi.digi_flags & CTSPACE || ch->ch_c_cflag & CRTSCTS) {
neo_set_cts_flow_control(ch);
} else if (ch->ch_c_iflag & IXON) {
if ((ch->ch_startc == _POSIX_VDISABLE) || (ch->ch_stopc == _POSIX_VDISABLE))
neo_set_no_output_flow_control(ch);
else
neo_set_ixon_flow_control(ch);
} else {
neo_set_no_output_flow_control(ch);
}
if (ch->ch_digi.digi_flags & RTSPACE || ch->ch_c_cflag & CRTSCTS) {
neo_set_rts_flow_control(ch);
} else if (ch->ch_c_iflag & IXOFF) {
if ((ch->ch_startc == _POSIX_VDISABLE) || (ch->ch_stopc == _POSIX_VDISABLE))
neo_set_no_input_flow_control(ch);
else
neo_set_ixoff_flow_control(ch);
} else {
neo_set_no_input_flow_control(ch);
}
if (baud < 9600) {
writeb(1, &ch->ch_neo_uart->rfifo);
ch->ch_r_tlevel = 1;
}
neo_assert_modem_signals(ch);
neo_parse_modem(ch, readb(&ch->ch_neo_uart->msr));
}
static void neo_tasklet(unsigned long data)
{
struct dgnc_board *bd = (struct dgnc_board *) data;
struct channel_t *ch;
ulong lock_flags;
int i;
int state = 0;
int ports = 0;
if (!bd || bd->magic != DGNC_BOARD_MAGIC) {
APR(("poll_tasklet() - NULL or bad bd.\n"));
return;
}
DGNC_LOCK(bd->bd_lock, lock_flags);
state = bd->state;
ports = bd->nasync;
DGNC_UNLOCK(bd->bd_lock, lock_flags);
DGNC_LOCK(bd->bd_intr_lock, lock_flags);
if ((state == BOARD_READY) && (ports > 0)) {
for (i = 0; i < ports; i++) {
ch = bd->channels[i];
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
continue;
dgnc_input(ch);
neo_copy_data_from_queue_to_uart(ch);
dgnc_wakeup_writes(ch);
dgnc_carrier(ch);
if (ch->ch_stop_sending_break)
neo_clear_break(ch, 0);
}
}
DGNC_UNLOCK(bd->bd_intr_lock, lock_flags);
}
static irqreturn_t neo_intr(int irq, void *voidbrd)
{
struct dgnc_board *brd = (struct dgnc_board *) voidbrd;
struct channel_t *ch;
int port = 0;
int type = 0;
int current_port;
u32 tmp;
u32 uart_poll;
unsigned long lock_flags;
unsigned long lock_flags2;
if (!brd) {
APR(("Received interrupt (%d) with null board associated\n", irq));
return IRQ_NONE;
}
if (brd->magic != DGNC_BOARD_MAGIC) {
APR(("Received interrupt (%d) with a board pointer that wasn't ours!\n", irq));
return IRQ_NONE;
}
brd->intr_count++;
DGNC_LOCK(brd->bd_intr_lock, lock_flags);
uart_poll = readl(brd->re_map_membase + UART_17158_POLL_ADDR_OFFSET);
DPR_INTR(("%s:%d uart_poll: %x\n", __FILE__, __LINE__, uart_poll));
if (!uart_poll) {
DPR_INTR(("Kernel interrupted to me, but no pending interrupts...\n"));
DGNC_UNLOCK(brd->bd_intr_lock, lock_flags);
return IRQ_NONE;
}
current_port = 0;
while ((uart_poll & 0xff) != 0) {
tmp = uart_poll;
if ((tmp & dgnc_offset_table[current_port]) != 0) {
port = current_port;
type = tmp >> (8 + (port * 3));
type &= 0x7;
} else {
current_port++;
continue;
}
DPR_INTR(("%s:%d port: %x type: %x\n", __FILE__, __LINE__, port, type));
uart_poll &= ~(dgnc_offset_table[port]);
if (!type) {
DPR_INTR(("Interrupt with no type! port: %d\n", port));
continue;
}
switch (type) {
case UART_17158_RXRDY_TIMEOUT:
if (port > brd->nasync)
continue;
ch = brd->channels[port];
neo_copy_data_from_uart_to_queue(ch);
DGNC_LOCK(ch->ch_lock, lock_flags2);
dgnc_check_queue_flow_control(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags2);
continue;
case UART_17158_RX_LINE_STATUS:
neo_parse_lsr(brd, port);
continue;
case UART_17158_TXRDY:
neo_parse_isr(brd, port);
continue;
case UART_17158_MSR:
neo_parse_isr(brd, port);
continue;
default:
DPR_INTR(("%s:%d Unknown Interrupt type: %x\n", __FILE__, __LINE__, type));
continue;
}
}
tasklet_schedule(&brd->helper_tasklet);
DGNC_UNLOCK(brd->bd_intr_lock, lock_flags);
DPR_INTR(("dgnc_intr finish.\n"));
return IRQ_HANDLED;
}
static void neo_disable_receiver(struct channel_t *ch)
{
uchar tmp = readb(&ch->ch_neo_uart->ier);
tmp &= ~(UART_IER_RDI);
writeb(tmp, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static void neo_enable_receiver(struct channel_t *ch)
{
uchar tmp = readb(&ch->ch_neo_uart->ier);
tmp |= (UART_IER_RDI);
writeb(tmp, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static void neo_copy_data_from_uart_to_queue(struct channel_t *ch)
{
int qleft = 0;
uchar linestatus = 0;
uchar error_mask = 0;
int n = 0;
int total = 0;
ushort head;
ushort tail;
ulong lock_flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DGNC_LOCK(ch->ch_lock, lock_flags);
head = ch->ch_r_head & RQUEUEMASK;
tail = ch->ch_r_tail & RQUEUEMASK;
linestatus = ch->ch_cached_lsr;
ch->ch_cached_lsr = 0;
qleft = tail - head - 1;
if (qleft < 0)
qleft += RQUEUEMASK + 1;
if (!(ch->ch_flags & CH_FIFO_ENABLED))
total = 0;
else {
total = readb(&ch->ch_neo_uart->rfifo);
if ((ch->ch_bd->dvid & 0xf0) >= UART_XR17E158_DVID)
total -= 1;
else
total -= 3;
}
total = min(total, qleft);
while (total > 0) {
linestatus = readb(&ch->ch_neo_uart->lsr);
if (linestatus & UART_17158_RX_FIFO_DATA_ERROR)
break;
n = min(((uint) total), (RQUEUESIZE - (uint) head));
n = min((uint) n, (uint) 12);
if (linestatus & (UART_LSR_THRE | UART_17158_TX_AND_FIFO_CLR))
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
linestatus = 0;
memcpy_fromio(ch->ch_rqueue + head, &ch->ch_neo_uart->txrxburst, n);
dgnc_sniff_nowait_nolock(ch, "UART READ", ch->ch_rqueue + head, n);
memset(ch->ch_equeue + head, 0, n);
head = (head + n) & RQUEUEMASK;
total -= n;
qleft -= n;
ch->ch_rxcount += n;
}
if (ch->ch_c_iflag & IGNBRK)
error_mask |= UART_LSR_BI;
while (1) {
linestatus |= readb(&ch->ch_neo_uart->lsr);
if (!(linestatus & UART_LSR_DR)) {
ch->ch_cached_lsr = linestatus;
break;
}
linestatus &= ~UART_LSR_DR;
if (linestatus & (UART_LSR_THRE | UART_17158_TX_AND_FIFO_CLR)) {
linestatus &= ~(UART_LSR_THRE | UART_17158_TX_AND_FIFO_CLR);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
}
if (linestatus & error_mask) {
uchar discard;
linestatus = 0;
memcpy_fromio(&discard, &ch->ch_neo_uart->txrxburst, 1);
continue;
}
while (qleft < 1) {
DPR_READ(("Queue full, dropping DATA:%x LSR:%x\n",
ch->ch_rqueue[tail], ch->ch_equeue[tail]));
ch->ch_r_tail = tail = (tail + 1) & RQUEUEMASK;
ch->ch_err_overrun++;
qleft++;
}
memcpy_fromio(ch->ch_rqueue + head, &ch->ch_neo_uart->txrxburst, 1);
ch->ch_equeue[head] = (uchar) linestatus;
dgnc_sniff_nowait_nolock(ch, "UART READ", ch->ch_rqueue + head, 1);
DPR_READ(("DATA/LSR pair: %x %x\n", ch->ch_rqueue[head], ch->ch_equeue[head]));
linestatus = 0;
head = (head + 1) & RQUEUEMASK;
qleft--;
ch->ch_rxcount++;
}
ch->ch_r_head = head & RQUEUEMASK;
ch->ch_e_head = head & EQUEUEMASK;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
static int neo_drain(struct tty_struct *tty, uint seconds)
{
ulong lock_flags;
struct channel_t *ch;
struct un_t *un;
int rc = 0;
if (!tty || tty->magic != TTY_MAGIC)
return -ENXIO;
un = (struct un_t *) tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -ENXIO;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
DPR_IOCTL(("%d Drain wait started.\n", __LINE__));
DGNC_LOCK(ch->ch_lock, lock_flags);
un->un_flags |= UN_EMPTY;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = wait_event_interruptible(un->un_flags_wait, ((un->un_flags & UN_EMPTY) == 0));
if (rc)
DPR_IOCTL(("%d Drain - User ctrl c'ed\n", __LINE__));
else
DPR_IOCTL(("%d Drain wait finished.\n", __LINE__));
return rc;
}
static void neo_flush_uart_write(struct channel_t *ch)
{
uchar tmp = 0;
int i = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
writeb((UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_XMIT), &ch->ch_neo_uart->isr_fcr);
neo_pci_posting_flush(ch->ch_bd);
for (i = 0; i < 10; i++) {
tmp = readb(&ch->ch_neo_uart->isr_fcr);
if (tmp & 4) {
DPR_IOCTL(("Still flushing TX UART... i: %d\n", i));
udelay(10);
} else
break;
}
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
}
static void neo_flush_uart_read(struct channel_t *ch)
{
uchar tmp = 0;
int i = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
writeb((UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR), &ch->ch_neo_uart->isr_fcr);
neo_pci_posting_flush(ch->ch_bd);
for (i = 0; i < 10; i++) {
tmp = readb(&ch->ch_neo_uart->isr_fcr);
if (tmp & 2) {
DPR_IOCTL(("Still flushing RX UART... i: %d\n", i));
udelay(10);
} else
break;
}
}
static void neo_copy_data_from_queue_to_uart(struct channel_t *ch)
{
ushort head;
ushort tail;
int n;
int s;
int qlen;
uint len_written = 0;
ulong lock_flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DGNC_LOCK(ch->ch_lock, lock_flags);
if (ch->ch_w_tail == ch->ch_w_head) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if ((ch->ch_flags & CH_FORCED_STOP) || (ch->ch_flags & CH_BREAK_SENDING)) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if (!(ch->ch_flags & CH_FIFO_ENABLED)) {
uchar lsrbits = readb(&ch->ch_neo_uart->lsr);
ch->ch_cached_lsr |= lsrbits;
if (ch->ch_cached_lsr & UART_LSR_THRE) {
ch->ch_cached_lsr &= ~(UART_LSR_THRE);
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_RTS)) {
ch->ch_mostat |= (UART_MCR_RTS);
neo_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_DTR)) {
ch->ch_mostat |= (UART_MCR_DTR);
neo_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
writeb(ch->ch_wqueue[ch->ch_w_tail], &ch->ch_neo_uart->txrx);
DPR_WRITE(("Tx data: %x\n", ch->ch_wqueue[ch->ch_w_head]));
ch->ch_w_tail++;
ch->ch_w_tail &= WQUEUEMASK;
ch->ch_txcount++;
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if ((ch->ch_bd->dvid & 0xf0) < UART_XR17E158_DVID) {
if (!(ch->ch_flags & (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM))) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
len_written = 0;
n = readb(&ch->ch_neo_uart->tfifo);
if ((unsigned int) n > ch->ch_t_tlevel) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
n = UART_17158_TX_FIFOSIZE - ch->ch_t_tlevel;
} else {
n = UART_17158_TX_FIFOSIZE - readb(&ch->ch_neo_uart->tfifo);
}
head = ch->ch_w_head & WQUEUEMASK;
tail = ch->ch_w_tail & WQUEUEMASK;
qlen = (head - tail) & WQUEUEMASK;
n = min(n, qlen);
while (n > 0) {
s = ((head >= tail) ? head : WQUEUESIZE) - tail;
s = min(s, n);
if (s <= 0)
break;
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_RTS)) {
ch->ch_mostat |= (UART_MCR_RTS);
neo_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) {
if (!(ch->ch_mostat & UART_MCR_DTR)) {
ch->ch_mostat |= (UART_MCR_DTR);
neo_assert_modem_signals(ch);
}
ch->ch_tun.un_flags |= (UN_EMPTY);
}
memcpy_toio(&ch->ch_neo_uart->txrxburst, ch->ch_wqueue + tail, s);
dgnc_sniff_nowait_nolock(ch, "UART WRITE", ch->ch_wqueue + tail, s);
tail = (tail + s) & WQUEUEMASK;
n -= s;
ch->ch_txcount += s;
len_written += s;
}
ch->ch_w_tail = tail & WQUEUEMASK;
if (len_written > 0) {
neo_pci_posting_flush(ch->ch_bd);
ch->ch_flags &= ~(CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
static void neo_parse_modem(struct channel_t *ch, uchar signals)
{
volatile uchar msignals = signals;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DPR_MSIGS(("neo_parse_modem: port: %d msignals: %x\n", ch->ch_portnum, msignals));
if (ch->ch_digi.digi_flags & DIGI_ALTPIN) {
uchar mswap = msignals;
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
msignals &= 0xf0;
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
DPR_MSIGS(("Port: %d DTR: %d RTS: %d CTS: %d DSR: %d " "RI: %d CD: %d\n",
ch->ch_portnum,
!!((ch->ch_mistat | ch->ch_mostat) & UART_MCR_DTR),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MCR_RTS),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_CTS),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_DSR),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_RI),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_DCD)));
}
static void neo_assert_modem_signals(struct channel_t *ch)
{
uchar out;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
out = ch->ch_mostat;
if (ch->ch_flags & CH_LOOPBACK)
out |= UART_MCR_LOOP;
writeb(out, &ch->ch_neo_uart->mcr);
neo_pci_posting_flush(ch->ch_bd);
udelay(10);
}
static void neo_send_start_character(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
if (ch->ch_startc != _POSIX_VDISABLE) {
ch->ch_xon_sends++;
writeb(ch->ch_startc, &ch->ch_neo_uart->txrx);
neo_pci_posting_flush(ch->ch_bd);
udelay(10);
}
}
static void neo_send_stop_character(struct channel_t *ch)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
if (ch->ch_stopc != _POSIX_VDISABLE) {
ch->ch_xoff_sends++;
writeb(ch->ch_stopc, &ch->ch_neo_uart->txrx);
neo_pci_posting_flush(ch->ch_bd);
udelay(10);
}
}
static void neo_uart_init(struct channel_t *ch)
{
writeb(0, &ch->ch_neo_uart->ier);
writeb(0, &ch->ch_neo_uart->efr);
writeb(UART_EFR_ECB, &ch->ch_neo_uart->efr);
readb(&ch->ch_neo_uart->txrx);
writeb((UART_FCR_ENABLE_FIFO|UART_FCR_CLEAR_RCVR|UART_FCR_CLEAR_XMIT), &ch->ch_neo_uart->isr_fcr);
readb(&ch->ch_neo_uart->lsr);
readb(&ch->ch_neo_uart->msr);
ch->ch_flags |= CH_FIFO_ENABLED;
writeb(ch->ch_mostat, &ch->ch_neo_uart->mcr);
neo_pci_posting_flush(ch->ch_bd);
}
static void neo_uart_off(struct channel_t *ch)
{
writeb(0, &ch->ch_neo_uart->efr);
writeb(0, &ch->ch_neo_uart->ier);
neo_pci_posting_flush(ch->ch_bd);
}
static uint neo_get_uart_bytes_left(struct channel_t *ch)
{
uchar left = 0;
uchar lsr = readb(&ch->ch_neo_uart->lsr);
ch->ch_cached_lsr |= lsr;
if (!(lsr & UART_LSR_TEMT)) {
if (ch->ch_flags & CH_TX_FIFO_EMPTY) {
tasklet_schedule(&ch->ch_bd->helper_tasklet);
}
left = 1;
} else {
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
left = 0;
}
return left;
}
static void neo_send_break(struct channel_t *ch, int msecs)
{
if (msecs == 0) {
if (ch->ch_flags & CH_BREAK_SENDING) {
uchar temp = readb(&ch->ch_neo_uart->lcr);
writeb((temp & ~UART_LCR_SBC), &ch->ch_neo_uart->lcr);
neo_pci_posting_flush(ch->ch_bd);
ch->ch_flags &= ~(CH_BREAK_SENDING);
ch->ch_stop_sending_break = 0;
DPR_IOCTL(("Finishing UART_LCR_SBC! finished: %lx\n", jiffies));
}
return;
}
ch->ch_stop_sending_break = jiffies + dgnc_jiffies_from_ms(msecs);
if (!(ch->ch_flags & CH_BREAK_SENDING)) {
uchar temp = readb(&ch->ch_neo_uart->lcr);
writeb((temp | UART_LCR_SBC), &ch->ch_neo_uart->lcr);
neo_pci_posting_flush(ch->ch_bd);
ch->ch_flags |= (CH_BREAK_SENDING);
DPR_IOCTL(("Port %d. Starting UART_LCR_SBC! start: %lx should end: %lx\n",
ch->ch_portnum, jiffies, ch->ch_stop_sending_break));
}
}
static void neo_send_immediate_char(struct channel_t *ch, unsigned char c)
{
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
writeb(c, &ch->ch_neo_uart->txrx);
neo_pci_posting_flush(ch->ch_bd);
}
static unsigned int neo_read_eeprom(unsigned char __iomem *base, unsigned int address)
{
unsigned int enable;
unsigned int bits;
unsigned int databit;
unsigned int val;
writeb(NEO_EECS, base + NEO_EEREG);
enable = (address | 0x180);
for (bits = 9; bits--; ) {
databit = (enable & (1 << bits)) ? NEO_EEDI : 0;
writeb(databit | NEO_EECS, base + NEO_EEREG);
writeb(databit | NEO_EECS | NEO_EECK, base + NEO_EEREG);
}
val = 0;
for (bits = 17; bits--; ) {
writeb(NEO_EECS, base + NEO_EEREG);
writeb(NEO_EECS | NEO_EECK, base + NEO_EEREG);
val <<= 1;
if (readb(base + NEO_EEREG) & NEO_EEDO)
val |= 1;
}
writeb(NEO_EECS, base + NEO_EEREG);
writeb(0x00, base + NEO_EEREG);
return val;
}
static void neo_vpd(struct dgnc_board *brd)
{
unsigned int i = 0;
unsigned int a;
if (!brd || brd->magic != DGNC_BOARD_MAGIC)
return;
if (!brd->re_map_membase)
return;
for (i = 0; i < NEO_VPD_IMAGESIZE; i++) {
a = neo_read_eeprom(brd->re_map_membase, i);
brd->vpd[i*2] = a & 0xff;
brd->vpd[(i*2)+1] = (a >> 8) & 0xff;
}
if (((brd->vpd[0x08] != 0x82)
&& (brd->vpd[0x10] != 0x82))
|| (brd->vpd[0x7F] != 0x78))
{
memset(brd->vpd, '\0', NEO_VPD_IMAGESIZE);
} else {
for (i = 0; i < NEO_VPD_IMAGEBYTES - 3; i++)
if (brd->vpd[i] == 'S' && brd->vpd[i + 1] == 'N')
strncpy(brd->serial_num, &(brd->vpd[i + 3]), 9);
}
}
