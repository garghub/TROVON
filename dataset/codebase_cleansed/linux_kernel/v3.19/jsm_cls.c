static void cls_set_cts_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_set_ixon_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_set_no_output_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_set_rts_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_set_ixoff_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_set_no_input_flow_control(struct jsm_channel *ch)
{
u8 lcrb = readb(&ch->ch_cls_uart->lcr);
u8 ier = readb(&ch->ch_cls_uart->ier);
u8 isr_fcr = 0;
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
static void cls_clear_break(struct jsm_channel *ch)
{
unsigned long lock_flags;
spin_lock_irqsave(&ch->ch_lock, lock_flags);
if (ch->ch_flags & CH_BREAK_SENDING) {
u8 temp = readb(&ch->ch_cls_uart->lcr);
writeb((temp & ~UART_LCR_SBC), &ch->ch_cls_uart->lcr);
ch->ch_flags &= ~(CH_BREAK_SENDING);
jsm_dbg(IOCTL, &ch->ch_bd->pci_dev,
"clear break Finishing UART_LCR_SBC! finished: %lx\n",
jiffies);
}
spin_unlock_irqrestore(&ch->ch_lock, lock_flags);
}
static void cls_disable_receiver(struct jsm_channel *ch)
{
u8 tmp = readb(&ch->ch_cls_uart->ier);
tmp &= ~(UART_IER_RDI);
writeb(tmp, &ch->ch_cls_uart->ier);
}
static void cls_enable_receiver(struct jsm_channel *ch)
{
u8 tmp = readb(&ch->ch_cls_uart->ier);
tmp |= (UART_IER_RDI);
writeb(tmp, &ch->ch_cls_uart->ier);
}
static void cls_assert_modem_signals(struct jsm_channel *ch)
{
if (!ch)
return;
writeb(ch->ch_mostat, &ch->ch_cls_uart->mcr);
}
static void cls_copy_data_from_uart_to_queue(struct jsm_channel *ch)
{
int qleft = 0;
u8 linestatus = 0;
u8 error_mask = 0;
u16 head;
u16 tail;
unsigned long flags;
if (!ch)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
head = ch->ch_r_head & RQUEUEMASK;
tail = ch->ch_r_tail & RQUEUEMASK;
linestatus = ch->ch_cached_lsr;
ch->ch_cached_lsr = 0;
qleft = tail - head - 1;
if (qleft < 0)
qleft += RQUEUEMASK + 1;
if (ch->ch_c_iflag & IGNBRK)
error_mask |= UART_LSR_BI;
while (1) {
linestatus = readb(&ch->ch_cls_uart->lsr);
if (!(linestatus & UART_LSR_DR))
break;
if (linestatus & error_mask) {
u8 discard;
linestatus = 0;
discard = readb(&ch->ch_cls_uart->txrx);
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
static void cls_copy_data_from_queue_to_uart(struct jsm_channel *ch)
{
u16 tail;
int n;
int qlen;
u32 len_written = 0;
struct circ_buf *circ;
if (!ch)
return;
circ = &ch->uart_port.state->xmit;
if (uart_circ_empty(circ))
return;
if ((ch->ch_flags & CH_STOP) || (ch->ch_flags & CH_BREAK_SENDING))
return;
if (!(ch->ch_flags & (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM)))
return;
n = 32;
tail = circ->tail & (UART_XMIT_SIZE - 1);
qlen = uart_circ_chars_pending(circ);
n = min(n, qlen);
while (n > 0) {
writeb(circ->buf[tail], &ch->ch_cls_uart->txrx);
tail = (tail + 1) & (UART_XMIT_SIZE - 1);
n--;
ch->ch_txcount++;
len_written++;
}
circ->tail = tail & (UART_XMIT_SIZE - 1);
if (len_written > ch->ch_t_tlevel)
ch->ch_flags &= ~(CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
if (uart_circ_empty(circ))
uart_write_wakeup(&ch->uart_port);
}
static void cls_parse_modem(struct jsm_channel *ch, u8 signals)
{
u8 msignals = signals;
jsm_dbg(MSIGS, &ch->ch_bd->pci_dev,
"neo_parse_modem: port: %d msignals: %x\n",
ch->ch_portnum, msignals);
msignals &= 0xf8;
if (msignals & UART_MSR_DDCD)
uart_handle_dcd_change(&ch->uart_port, msignals & UART_MSR_DCD);
if (msignals & UART_MSR_DDSR)
uart_handle_dcd_change(&ch->uart_port, msignals & UART_MSR_CTS);
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
jsm_dbg(MSIGS, &ch->ch_bd->pci_dev,
"Port: %d DTR: %d RTS: %d CTS: %d DSR: %d " "RI: %d CD: %d\n",
ch->ch_portnum,
!!((ch->ch_mistat | ch->ch_mostat) & UART_MCR_DTR),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MCR_RTS),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_CTS),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_DSR),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_RI),
!!((ch->ch_mistat | ch->ch_mostat) & UART_MSR_DCD));
}
static inline void cls_parse_isr(struct jsm_board *brd, uint port)
{
struct jsm_channel *ch;
u8 isr = 0;
unsigned long flags;
if (port > brd->nasync)
return;
ch = brd->channels[port];
if (!ch)
return;
while (1) {
isr = readb(&ch->ch_cls_uart->isr_fcr);
if (isr & UART_IIR_NO_INT)
break;
if (isr & (UART_IIR_RDI | UART_IIR_RDI_TIMEOUT)) {
cls_copy_data_from_uart_to_queue(ch);
jsm_check_queue_flow_control(ch);
}
if (isr & UART_IIR_THRI) {
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
spin_unlock_irqrestore(&ch->ch_lock, flags);
cls_copy_data_from_queue_to_uart(ch);
}
cls_parse_modem(ch, readb(&ch->ch_cls_uart->msr));
}
}
static void cls_flush_uart_write(struct jsm_channel *ch)
{
u8 tmp = 0;
u8 i = 0;
if (!ch)
return;
writeb((UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_XMIT),
&ch->ch_cls_uart->isr_fcr);
for (i = 0; i < 10; i++) {
tmp = readb(&ch->ch_cls_uart->isr_fcr);
if (tmp & UART_FCR_CLEAR_XMIT) {
jsm_dbg(IOCTL, &ch->ch_bd->pci_dev,
"Still flushing TX UART... i: %d\n", i);
udelay(10);
} else
break;
}
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
}
static void cls_flush_uart_read(struct jsm_channel *ch)
{
if (!ch)
return;
udelay(10);
}
static void cls_send_start_character(struct jsm_channel *ch)
{
if (!ch)
return;
if (ch->ch_startc != __DISABLED_CHAR) {
ch->ch_xon_sends++;
writeb(ch->ch_startc, &ch->ch_cls_uart->txrx);
}
}
static void cls_send_stop_character(struct jsm_channel *ch)
{
if (!ch)
return;
if (ch->ch_stopc != __DISABLED_CHAR) {
ch->ch_xoff_sends++;
writeb(ch->ch_stopc, &ch->ch_cls_uart->txrx);
}
}
static void cls_param(struct jsm_channel *ch)
{
u8 lcr = 0;
u8 uart_lcr = 0;
u8 ier = 0;
u32 baud = 9600;
int quot = 0;
struct jsm_board *bd;
int i;
unsigned int cflag;
bd = ch->ch_bd;
if (!bd)
return;
if ((ch->ch_c_cflag & (CBAUD)) == 0) {
ch->ch_r_head = 0;
ch->ch_r_tail = 0;
ch->ch_e_head = 0;
ch->ch_e_tail = 0;
cls_flush_uart_write(ch);
cls_flush_uart_read(ch);
ch->ch_flags |= (CH_BAUD0);
ch->ch_mostat &= ~(UART_MCR_RTS | UART_MCR_DTR);
cls_assert_modem_signals(ch);
return;
}
cflag = C_BAUD(ch->uart_port.state->port.tty);
baud = 9600;
for (i = 0; i < ARRAY_SIZE(baud_rates); i++) {
if (baud_rates[i].cflag == cflag) {
baud = baud_rates[i].rate;
break;
}
}
if (ch->ch_flags & CH_BAUD0)
ch->ch_flags &= ~(CH_BAUD0);
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
ier = readb(&ch->ch_cls_uart->ier);
uart_lcr = readb(&ch->ch_cls_uart->lcr);
quot = ch->ch_bd->bd_dividend / baud;
if (quot != 0) {
writeb(UART_LCR_DLAB, &ch->ch_cls_uart->lcr);
writeb((quot & 0xff), &ch->ch_cls_uart->txrx);
writeb((quot >> 8), &ch->ch_cls_uart->ier);
writeb(lcr, &ch->ch_cls_uart->lcr);
}
if (uart_lcr != lcr)
writeb(lcr, &ch->ch_cls_uart->lcr);
if (ch->ch_c_cflag & CREAD)
ier |= (UART_IER_RDI | UART_IER_RLSI);
ier |= (UART_IER_THRI | UART_IER_MSI);
writeb(ier, &ch->ch_cls_uart->ier);
if (ch->ch_c_cflag & CRTSCTS)
cls_set_cts_flow_control(ch);
else if (ch->ch_c_iflag & IXON) {
if ((ch->ch_startc == __DISABLED_CHAR) ||
(ch->ch_stopc == __DISABLED_CHAR))
cls_set_no_output_flow_control(ch);
else
cls_set_ixon_flow_control(ch);
} else
cls_set_no_output_flow_control(ch);
if (ch->ch_c_cflag & CRTSCTS)
cls_set_rts_flow_control(ch);
else if (ch->ch_c_iflag & IXOFF) {
if ((ch->ch_startc == __DISABLED_CHAR) ||
(ch->ch_stopc == __DISABLED_CHAR))
cls_set_no_input_flow_control(ch);
else
cls_set_ixoff_flow_control(ch);
} else
cls_set_no_input_flow_control(ch);
cls_assert_modem_signals(ch);
cls_parse_modem(ch, readb(&ch->ch_cls_uart->msr));
}
static irqreturn_t cls_intr(int irq, void *voidbrd)
{
struct jsm_board *brd = voidbrd;
unsigned long lock_flags;
unsigned char uart_poll;
uint i = 0;
spin_lock_irqsave(&brd->bd_intr_lock, lock_flags);
uart_poll = readb(brd->re_map_membase + UART_CLASSIC_POLL_ADDR_OFFSET);
jsm_dbg(INTR, &brd->pci_dev, "%s:%d uart_poll: %x\n",
__FILE__, __LINE__, uart_poll);
if (!uart_poll) {
jsm_dbg(INTR, &brd->pci_dev,
"Kernel interrupted to me, but no pending interrupts...\n");
spin_unlock_irqrestore(&brd->bd_intr_lock, lock_flags);
return IRQ_NONE;
}
for (i = 0; i < brd->nasync; i++)
cls_parse_isr(brd, i);
spin_unlock_irqrestore(&brd->bd_intr_lock, lock_flags);
return IRQ_HANDLED;
}
static void cls_uart_init(struct jsm_channel *ch)
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
static void cls_uart_off(struct jsm_channel *ch)
{
writeb(0, &ch->ch_cls_uart->ier);
}
static u32 cls_get_uart_bytes_left(struct jsm_channel *ch)
{
u8 left = 0;
u8 lsr = readb(&ch->ch_cls_uart->lsr);
if (!(lsr & UART_LSR_TEMT))
left = 1;
else {
ch->ch_flags |= (CH_TX_FIFO_EMPTY | CH_TX_FIFO_LWM);
left = 0;
}
return left;
}
static void cls_send_break(struct jsm_channel *ch)
{
if (!(ch->ch_flags & CH_BREAK_SENDING)) {
u8 temp = readb(&ch->ch_cls_uart->lcr);
writeb((temp | UART_LCR_SBC), &ch->ch_cls_uart->lcr);
ch->ch_flags |= (CH_BREAK_SENDING);
}
}
static void cls_send_immediate_char(struct jsm_channel *ch, unsigned char c)
{
writeb(c, &ch->ch_cls_uart->txrx);
}
