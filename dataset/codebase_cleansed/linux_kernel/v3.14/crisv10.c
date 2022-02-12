void debug_log_func(int line, const char *string, int value)
{
if (debug_log_pos < DEBUG_LOG_SIZE) {
debug_log[debug_log_pos].time = jiffies;
debug_log[debug_log_pos].timer_data = *R_TIMER_DATA;
debug_log[debug_log_pos].string = string;
debug_log[debug_log_pos].value = value;
debug_log_pos++;
}
}
static void update_char_time(struct e100_serial * info)
{
tcflag_t cflags = info->port.tty->termios.c_cflag;
int bits;
if ((cflags & CSIZE) == CS7)
bits = 9;
else
bits = 10;
if (cflags & CSTOPB)
bits++;
if (cflags & PARENB)
bits++;
info->char_time_usec = ((bits * 1000000) / info->baud) + 1;
info->flush_time_usec = 4*info->char_time_usec;
if (info->flush_time_usec < MIN_FLUSH_TIME_USEC)
info->flush_time_usec = MIN_FLUSH_TIME_USEC;
}
static int
cflag_to_baud(unsigned int cflag)
{
static int baud_table[] = {
0, 50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 };
static int ext_baud_table[] = {
0, 57600, 115200, 230400, 460800, 921600, 1843200, 6250000,
0, 0, 0, 0, 0, 0, 0, 0 };
if (cflag & CBAUDEX)
return ext_baud_table[(cflag & CBAUD) & ~CBAUDEX];
else
return baud_table[cflag & CBAUD];
}
static unsigned char
cflag_to_etrax_baud(unsigned int cflag)
{
char retval;
static char baud_table[] = {
-1, -1, -1, -1, -1, -1, -1, 0, 1, 2, -1, 3, 4, 5, 6, 7 };
static char ext_baud_table[] = {
-1, 8, 9, 10, 11, 12, 13, 14, -1, -1, -1, -1, -1, -1, -1, -1 };
if (cflag & CBAUDEX)
retval = ext_baud_table[(cflag & CBAUD) & ~CBAUDEX];
else
retval = baud_table[cflag & CBAUD];
if (retval < 0) {
printk(KERN_WARNING "serdriver tried setting invalid baud rate, flags %x.\n", cflag);
retval = 5;
}
return retval | (retval << 4);
}
static inline void
e100_dtr(struct e100_serial *info, int set)
{
#ifndef CONFIG_SVINTO_SIM
unsigned char mask = e100_modem_pins[info->line].dtr_mask;
#ifdef SERIAL_DEBUG_IO
printk("ser%i dtr %i mask: 0x%02X\n", info->line, set, mask);
printk("ser%i shadow before 0x%02X get: %i\n",
info->line, *e100_modem_pins[info->line].dtr_shadow,
E100_DTR_GET(info));
#endif
{
unsigned long flags;
local_irq_save(flags);
*e100_modem_pins[info->line].dtr_shadow &= ~mask;
*e100_modem_pins[info->line].dtr_shadow |= (set ? 0 : mask);
*e100_modem_pins[info->line].dtr_port = *e100_modem_pins[info->line].dtr_shadow;
local_irq_restore(flags);
}
#ifdef SERIAL_DEBUG_IO
printk("ser%i shadow after 0x%02X get: %i\n",
info->line, *e100_modem_pins[info->line].dtr_shadow,
E100_DTR_GET(info));
#endif
#endif
}
static inline void
e100_rts(struct e100_serial *info, int set)
{
#ifndef CONFIG_SVINTO_SIM
unsigned long flags;
local_irq_save(flags);
info->rx_ctrl &= ~E100_RTS_MASK;
info->rx_ctrl |= (set ? 0 : E100_RTS_MASK);
info->ioport[REG_REC_CTRL] = info->rx_ctrl;
local_irq_restore(flags);
#ifdef SERIAL_DEBUG_IO
printk("ser%i rts %i\n", info->line, set);
#endif
#endif
}
static inline void
e100_ri_out(struct e100_serial *info, int set)
{
#ifndef CONFIG_SVINTO_SIM
{
unsigned char mask = e100_modem_pins[info->line].ri_mask;
unsigned long flags;
local_irq_save(flags);
*e100_modem_pins[info->line].ri_shadow &= ~mask;
*e100_modem_pins[info->line].ri_shadow |= (set ? 0 : mask);
*e100_modem_pins[info->line].ri_port = *e100_modem_pins[info->line].ri_shadow;
local_irq_restore(flags);
}
#endif
}
static inline void
e100_cd_out(struct e100_serial *info, int set)
{
#ifndef CONFIG_SVINTO_SIM
{
unsigned char mask = e100_modem_pins[info->line].cd_mask;
unsigned long flags;
local_irq_save(flags);
*e100_modem_pins[info->line].cd_shadow &= ~mask;
*e100_modem_pins[info->line].cd_shadow |= (set ? 0 : mask);
*e100_modem_pins[info->line].cd_port = *e100_modem_pins[info->line].cd_shadow;
local_irq_restore(flags);
}
#endif
}
static inline void
e100_disable_rx(struct e100_serial *info)
{
#ifndef CONFIG_SVINTO_SIM
info->ioport[REG_REC_CTRL] =
(info->rx_ctrl &= ~IO_MASK(R_SERIAL0_REC_CTRL, rec_enable));
#endif
}
static inline void
e100_enable_rx(struct e100_serial *info)
{
#ifndef CONFIG_SVINTO_SIM
info->ioport[REG_REC_CTRL] =
(info->rx_ctrl |= IO_MASK(R_SERIAL0_REC_CTRL, rec_enable));
#endif
}
static inline void
e100_disable_rxdma_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("rxdma_irq(%d): 0\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ disable_rxdma_irq %i\n", info->line));
*R_IRQ_MASK2_CLR = (info->irq << 2) | (info->irq << 3);
}
static inline void
e100_enable_rxdma_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("rxdma_irq(%d): 1\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ enable_rxdma_irq %i\n", info->line));
*R_IRQ_MASK2_SET = (info->irq << 2) | (info->irq << 3);
}
static void e100_disable_txdma_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("txdma_irq(%d): 0\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ disable_txdma_irq %i\n", info->line));
*R_IRQ_MASK2_CLR = info->irq;
}
static void e100_enable_txdma_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("txdma_irq(%d): 1\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ enable_txdma_irq %i\n", info->line));
*R_IRQ_MASK2_SET = info->irq;
}
static void e100_disable_txdma_channel(struct e100_serial *info)
{
unsigned long flags;
local_irq_save(flags);
DFLOW(DEBUG_LOG(info->line, "disable_txdma_channel %i\n", info->line));
if (info->line == 0) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma6)) ==
IO_STATE(R_GEN_CONFIG, dma6, serial0)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma6);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma6, unused);
}
} else if (info->line == 1) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma8)) ==
IO_STATE(R_GEN_CONFIG, dma8, serial1)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma8);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma8, usb);
}
} else if (info->line == 2) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma2)) ==
IO_STATE(R_GEN_CONFIG, dma2, serial2)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma2);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma2, par0);
}
} else if (info->line == 3) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma4)) ==
IO_STATE(R_GEN_CONFIG, dma4, serial3)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma4);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma4, par1);
}
}
*R_GEN_CONFIG = genconfig_shadow;
local_irq_restore(flags);
}
static void e100_enable_txdma_channel(struct e100_serial *info)
{
unsigned long flags;
local_irq_save(flags);
DFLOW(DEBUG_LOG(info->line, "enable_txdma_channel %i\n", info->line));
if (info->line == 0) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma6);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma6, serial0);
} else if (info->line == 1) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma8);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma8, serial1);
} else if (info->line == 2) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma2);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma2, serial2);
} else if (info->line == 3) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma4);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma4, serial3);
}
*R_GEN_CONFIG = genconfig_shadow;
local_irq_restore(flags);
}
static void e100_disable_rxdma_channel(struct e100_serial *info)
{
unsigned long flags;
local_irq_save(flags);
if (info->line == 0) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma7)) ==
IO_STATE(R_GEN_CONFIG, dma7, serial0)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma7);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma7, unused);
}
} else if (info->line == 1) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma9)) ==
IO_STATE(R_GEN_CONFIG, dma9, serial1)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma9);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma9, usb);
}
} else if (info->line == 2) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma3)) ==
IO_STATE(R_GEN_CONFIG, dma3, serial2)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma3);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma3, par0);
}
} else if (info->line == 3) {
if ((genconfig_shadow & IO_MASK(R_GEN_CONFIG, dma5)) ==
IO_STATE(R_GEN_CONFIG, dma5, serial3)) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma5);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma5, par1);
}
}
*R_GEN_CONFIG = genconfig_shadow;
local_irq_restore(flags);
}
static void e100_enable_rxdma_channel(struct e100_serial *info)
{
unsigned long flags;
local_irq_save(flags);
if (info->line == 0) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma7);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma7, serial0);
} else if (info->line == 1) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma9);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma9, serial1);
} else if (info->line == 2) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma3);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma3, serial2);
} else if (info->line == 3) {
genconfig_shadow &= ~IO_MASK(R_GEN_CONFIG, dma5);
genconfig_shadow |= IO_STATE(R_GEN_CONFIG, dma5, serial3);
}
*R_GEN_CONFIG = genconfig_shadow;
local_irq_restore(flags);
}
static inline void
e100_disable_serial_data_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("ser_irq(%d): 0\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ disable data_irq %i\n", info->line));
*R_IRQ_MASK1_CLR = (1U << (8+2*info->line));
}
static inline void
e100_enable_serial_data_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("ser_irq(%d): 1\n",info->line);
printk("**** %d = %d\n",
(8+2*info->line),
(1U << (8+2*info->line)));
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ enable data_irq %i\n", info->line));
*R_IRQ_MASK1_SET = (1U << (8+2*info->line));
}
static inline void
e100_disable_serial_tx_ready_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("ser_tx_irq(%d): 0\n",info->line);
#endif
DINTR1(DEBUG_LOG(info->line,"IRQ disable ready_irq %i\n", info->line));
*R_IRQ_MASK1_CLR = (1U << (8+1+2*info->line));
}
static inline void
e100_enable_serial_tx_ready_irq(struct e100_serial *info)
{
#ifdef SERIAL_DEBUG_INTR
printk("ser_tx_irq(%d): 1\n",info->line);
printk("**** %d = %d\n",
(8+1+2*info->line),
(1U << (8+1+2*info->line)));
#endif
DINTR2(DEBUG_LOG(info->line,"IRQ enable ready_irq %i\n", info->line));
*R_IRQ_MASK1_SET = (1U << (8+1+2*info->line));
}
static inline void e100_enable_rx_irq(struct e100_serial *info)
{
if (info->uses_dma_in)
e100_enable_rxdma_irq(info);
else
e100_enable_serial_data_irq(info);
}
static inline void e100_disable_rx_irq(struct e100_serial *info)
{
if (info->uses_dma_in)
e100_disable_rxdma_irq(info);
else
e100_disable_serial_data_irq(info);
}
static int
e100_enable_rs485(struct tty_struct *tty, struct serial_rs485 *r)
{
struct e100_serial * info = (struct e100_serial *)tty->driver_data;
#if defined(CONFIG_ETRAX_RS485_ON_PA)
*R_PORT_PA_DATA = port_pa_data_shadow |= (1 << rs485_pa_bit);
#endif
#if defined(CONFIG_ETRAX_RS485_ON_PORT_G)
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
rs485_port_g_bit, 1);
#endif
#if defined(CONFIG_ETRAX_RS485_LTC1387)
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
CONFIG_ETRAX_RS485_LTC1387_DXEN_PORT_G_BIT, 1);
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
CONFIG_ETRAX_RS485_LTC1387_RXEN_PORT_G_BIT, 1);
#endif
info->rs485 = *r;
if (info->rs485.delay_rts_before_send >= 1000)
info->rs485.delay_rts_before_send = 1000;
return 0;
}
static int
e100_write_rs485(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct e100_serial * info = (struct e100_serial *)tty->driver_data;
int old_value = (info->rs485.flags) & SER_RS485_ENABLED;
info->rs485.flags |= SER_RS485_ENABLED;
count = rs_write(tty, buf, count);
if (!old_value)
info->rs485.flags &= ~(SER_RS485_ENABLED);
return count;
}
static void rs485_toggle_rts_timer_function(unsigned long data)
{
struct e100_serial *info = (struct e100_serial *)data;
fast_timers_rs485[info->line].function = NULL;
e100_rts(info, (info->rs485.flags & SER_RS485_RTS_AFTER_SEND));
#if defined(CONFIG_ETRAX_RS485_DISABLE_RECEIVER)
e100_enable_rx(info);
e100_enable_rx_irq(info);
#endif
}
static void
rs_stop(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
if (info) {
unsigned long flags;
unsigned long xoff;
local_irq_save(flags);
DFLOW(DEBUG_LOG(info->line, "XOFF rs_stop xmit %i\n",
CIRC_CNT(info->xmit.head,
info->xmit.tail,SERIAL_XMIT_SIZE)));
xoff = IO_FIELD(R_SERIAL0_XOFF, xoff_char,
STOP_CHAR(info->port.tty));
xoff |= IO_STATE(R_SERIAL0_XOFF, tx_stop, stop);
if (tty->termios.c_iflag & IXON ) {
xoff |= IO_STATE(R_SERIAL0_XOFF, auto_xoff, enable);
}
*((unsigned long *)&info->ioport[REG_XOFF]) = xoff;
local_irq_restore(flags);
}
}
static void
rs_start(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
if (info) {
unsigned long flags;
unsigned long xoff;
local_irq_save(flags);
DFLOW(DEBUG_LOG(info->line, "XOFF rs_start xmit %i\n",
CIRC_CNT(info->xmit.head,
info->xmit.tail,SERIAL_XMIT_SIZE)));
xoff = IO_FIELD(R_SERIAL0_XOFF, xoff_char, STOP_CHAR(tty));
xoff |= IO_STATE(R_SERIAL0_XOFF, tx_stop, enable);
if (tty->termios.c_iflag & IXON ) {
xoff |= IO_STATE(R_SERIAL0_XOFF, auto_xoff, enable);
}
*((unsigned long *)&info->ioport[REG_XOFF]) = xoff;
if (!info->uses_dma_out &&
info->xmit.head != info->xmit.tail && info->xmit.buf)
e100_enable_serial_tx_ready_irq(info);
local_irq_restore(flags);
}
}
static void rs_sched_event(struct e100_serial *info, int event)
{
if (info->event & (1 << event))
return;
info->event |= 1 << event;
schedule_work(&info->work);
}
static void
transmit_chars_dma(struct e100_serial *info)
{
unsigned int c, sentl;
struct etrax_dma_descr *descr;
#ifdef CONFIG_SVINTO_SIM
if (info->xmit.tail)
printk("Error in serial.c:transmit_chars-dma(), tail!=0\n");
if (info->xmit.head != info->xmit.tail) {
SIMCOUT(info->xmit.buf + info->xmit.tail,
CIRC_CNT(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE));
info->xmit.head = info->xmit.tail;
info->tr_running = 0;
}
return;
#endif
*info->oclrintradr =
IO_STATE(R_DMA_CH6_CLR_INTR, clr_descr, do) |
IO_STATE(R_DMA_CH6_CLR_INTR, clr_eop, do);
#ifdef SERIAL_DEBUG_INTR
if (info->line == SERIAL_DEBUG_LINE)
printk("tc\n");
#endif
if (!info->tr_running) {
printk(KERN_WARNING "Achtung: transmit_chars_dma with !tr_running\n");
return;
}
descr = &info->tr_descr;
if (!(descr->status & d_stop)) {
sentl = descr->sw_len;
} else
sentl = descr->hw_len;
DFLOW(DEBUG_LOG(info->line, "TX %i done\n", sentl));
info->icount.tx += sentl;
info->xmit.tail = (info->xmit.tail + sentl) & (SERIAL_XMIT_SIZE - 1);
if (CIRC_CNT(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE) < WAKEUP_CHARS)
rs_sched_event(info, RS_EVENT_WRITE_WAKEUP);
c = CIRC_CNT_TO_END(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
if (c >= 4*WAKEUP_CHARS)
c = c/2;
if (c <= 0) {
info->tr_running = 0;
#if defined(CONFIG_ETRAX_RS485) && defined(CONFIG_ETRAX_FAST_TIMER)
if (info->rs485.flags & SER_RS485_ENABLED) {
start_one_shot_timer(&fast_timers_rs485[info->line],
rs485_toggle_rts_timer_function,
(unsigned long)info,
info->char_time_usec*2,
"RS-485");
}
#endif
return;
}
DFLOW(DEBUG_LOG(info->line, "TX %i\n", c));
descr->ctrl = d_int | d_eol | d_wait;
descr->sw_len = c;
descr->buf = virt_to_phys(info->xmit.buf + info->xmit.tail);
descr->status = 0;
*info->ofirstadr = virt_to_phys(descr);
*info->ocmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, start);
}
static void
start_transmit(struct e100_serial *info)
{
#if 0
if (info->line == SERIAL_DEBUG_LINE)
printk("x\n");
#endif
info->tr_descr.sw_len = 0;
info->tr_descr.hw_len = 0;
info->tr_descr.status = 0;
info->tr_running = 1;
if (info->uses_dma_out)
transmit_chars_dma(info);
else
e100_enable_serial_tx_ready_irq(info);
}
static struct etrax_recv_buffer *
alloc_recv_buffer(unsigned int size)
{
struct etrax_recv_buffer *buffer;
if (!(buffer = kmalloc(sizeof *buffer + size, GFP_ATOMIC)))
return NULL;
buffer->next = NULL;
buffer->length = 0;
buffer->error = TTY_NORMAL;
return buffer;
}
static void
append_recv_buffer(struct e100_serial *info, struct etrax_recv_buffer *buffer)
{
unsigned long flags;
local_irq_save(flags);
if (!info->first_recv_buffer)
info->first_recv_buffer = buffer;
else
info->last_recv_buffer->next = buffer;
info->last_recv_buffer = buffer;
info->recv_cnt += buffer->length;
if (info->recv_cnt > info->max_recv_cnt)
info->max_recv_cnt = info->recv_cnt;
local_irq_restore(flags);
}
static int
add_char_and_flag(struct e100_serial *info, unsigned char data, unsigned char flag)
{
struct etrax_recv_buffer *buffer;
if (info->uses_dma_in) {
if (!(buffer = alloc_recv_buffer(4)))
return 0;
buffer->length = 1;
buffer->error = flag;
buffer->buffer[0] = data;
append_recv_buffer(info, buffer);
info->icount.rx++;
} else {
tty_insert_flip_char(&info->port, data, flag);
info->icount.rx++;
}
return 1;
}
static unsigned int handle_descr_data(struct e100_serial *info,
struct etrax_dma_descr *descr,
unsigned int recvl)
{
struct etrax_recv_buffer *buffer = phys_to_virt(descr->buf) - sizeof *buffer;
if (info->recv_cnt + recvl > 65536) {
printk(KERN_WARNING
"%s: Too much pending incoming serial data! Dropping %u bytes.\n", __func__, recvl);
return 0;
}
buffer->length = recvl;
if (info->errorcode == ERRCODE_SET_BREAK)
buffer->error = TTY_BREAK;
info->errorcode = 0;
append_recv_buffer(info, buffer);
if (!(buffer = alloc_recv_buffer(SERIAL_DESCR_BUF_SIZE)))
panic("%s: Failed to allocate memory for receive buffer!\n", __func__);
descr->buf = virt_to_phys(buffer->buffer);
return recvl;
}
static unsigned int handle_all_descr_data(struct e100_serial *info)
{
struct etrax_dma_descr *descr;
unsigned int recvl;
unsigned int ret = 0;
while (1)
{
descr = &info->rec_descr[info->cur_rec_descr];
if (descr == phys_to_virt(*info->idescradr))
break;
if (++info->cur_rec_descr == SERIAL_RECV_DESCRIPTORS)
info->cur_rec_descr = 0;
if (!(descr->status & d_eop)) {
recvl = descr->sw_len;
} else {
recvl = descr->hw_len;
}
descr->status = 0;
DFLOW( DEBUG_LOG(info->line, "RX %lu\n", recvl);
if (info->port.tty->stopped) {
unsigned char *buf = phys_to_virt(descr->buf);
DEBUG_LOG(info->line, "rx 0x%02X\n", buf[0]);
DEBUG_LOG(info->line, "rx 0x%02X\n", buf[1]);
DEBUG_LOG(info->line, "rx 0x%02X\n", buf[2]);
}
);
info->icount.rx += recvl;
ret += handle_descr_data(info, descr, recvl);
}
return ret;
}
static void receive_chars_dma(struct e100_serial *info)
{
struct tty_struct *tty;
unsigned char rstat;
#ifdef CONFIG_SVINTO_SIM
return;
#endif
*info->iclrintradr =
IO_STATE(R_DMA_CH6_CLR_INTR, clr_descr, do) |
IO_STATE(R_DMA_CH6_CLR_INTR, clr_eop, do);
tty = info->port.tty;
if (!tty)
return;
#ifdef SERIAL_HANDLE_EARLY_ERRORS
if (info->uses_dma_in)
e100_enable_serial_data_irq(info);
#endif
if (info->errorcode == ERRCODE_INSERT_BREAK)
add_char_and_flag(info, '\0', TTY_BREAK);
handle_all_descr_data(info);
rstat = info->ioport[REG_STATUS];
if (rstat & IO_MASK(R_SERIAL0_STATUS, xoff_detect) ) {
DFLOW(DEBUG_LOG(info->line, "XOFF detect stat %x\n", rstat));
}
if (rstat & SER_ERROR_MASK) {
unsigned char data = info->ioport[REG_DATA];
PROCSTAT(ser_stat[info->line].errors_cnt++);
DEBUG_LOG(info->line, "#dERR: s d 0x%04X\n",
((rstat & SER_ERROR_MASK) << 8) | data);
if (rstat & SER_PAR_ERR_MASK)
add_char_and_flag(info, data, TTY_PARITY);
else if (rstat & SER_OVERRUN_MASK)
add_char_and_flag(info, data, TTY_OVERRUN);
else if (rstat & SER_FRAMING_ERR_MASK)
add_char_and_flag(info, data, TTY_FRAME);
}
START_FLUSH_FAST_TIMER(info, "receive_chars");
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, restart);
}
static int start_recv_dma(struct e100_serial *info)
{
struct etrax_dma_descr *descr = info->rec_descr;
struct etrax_recv_buffer *buffer;
int i;
for (i = 0; i < SERIAL_RECV_DESCRIPTORS; i++) {
if (!(buffer = alloc_recv_buffer(SERIAL_DESCR_BUF_SIZE)))
panic("%s: Failed to allocate memory for receive buffer!\n", __func__);
descr[i].ctrl = d_int;
descr[i].buf = virt_to_phys(buffer->buffer);
descr[i].sw_len = SERIAL_DESCR_BUF_SIZE;
descr[i].hw_len = 0;
descr[i].status = 0;
descr[i].next = virt_to_phys(&descr[i+1]);
}
descr[i-1].next = virt_to_phys(&descr[0]);
info->cur_rec_descr = 0;
*info->ifirstadr = virt_to_phys(&descr[info->cur_rec_descr]);
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, start);
return 1;
}
static void
start_receive(struct e100_serial *info)
{
#ifdef CONFIG_SVINTO_SIM
return;
#endif
if (info->uses_dma_in) {
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, reset);
while (IO_EXTRACT(R_DMA_CH6_CMD, cmd, *info->icmdadr) ==
IO_STATE_VALUE(R_DMA_CH6_CMD, cmd, reset));
start_recv_dma(info);
}
}
static irqreturn_t
tr_interrupt(int irq, void *dev_id)
{
struct e100_serial *info;
unsigned long ireg;
int i;
int handled = 0;
#ifdef CONFIG_SVINTO_SIM
{
const char *s = "What? tr_interrupt in simulator??\n";
SIMCOUT(s,strlen(s));
}
return IRQ_HANDLED;
#endif
ireg = *R_IRQ_MASK2_RD;
for (i = 0; i < NR_PORTS; i++) {
info = rs_table + i;
if (!info->enabled || !info->uses_dma_out)
continue;
if (ireg & info->irq) {
handled = 1;
DINTR2(DEBUG_LOG(info->line, "tr_interrupt %i\n", i));
PROCSTAT(ser_stat[info->line].tx_dma_ints++);
info->last_tx_active_usec = GET_JIFFIES_USEC();
info->last_tx_active = jiffies;
transmit_chars_dma(info);
}
}
return IRQ_RETVAL(handled);
}
static irqreturn_t
rec_interrupt(int irq, void *dev_id)
{
struct e100_serial *info;
unsigned long ireg;
int i;
int handled = 0;
#ifdef CONFIG_SVINTO_SIM
{
const char *s = "What? rec_interrupt in simulator??\n";
SIMCOUT(s,strlen(s));
}
return IRQ_HANDLED;
#endif
ireg = *R_IRQ_MASK2_RD;
for (i = 0; i < NR_PORTS; i++) {
info = rs_table + i;
if (!info->enabled || !info->uses_dma_in)
continue;
if (ireg & ((info->irq << 2) | (info->irq << 3))) {
handled = 1;
receive_chars_dma(info);
}
}
return IRQ_RETVAL(handled);
}
static int force_eop_if_needed(struct e100_serial *info)
{
unsigned char rstat = info->ioport[REG_STATUS];
if (rstat & SER_ERROR_MASK) {
DEBUG_LOG(info->line, "timeout err: rstat 0x%03X\n",
rstat | (info->line << 8));
return 0;
}
if (rstat & SER_DATA_AVAIL_MASK) {
TIMERD(DEBUG_LOG(info->line, "timeout: rstat 0x%03X\n",
rstat | (info->line << 8)));
(void)info->ioport[REG_DATA];
info->forced_eop = 0;
START_FLUSH_FAST_TIMER(info, "magic");
return 0;
}
if (!info->forced_eop) {
info->forced_eop = 1;
PROCSTAT(ser_stat[info->line].timeout_flush_cnt++);
TIMERD(DEBUG_LOG(info->line, "timeout EOP %i\n", info->line));
FORCE_EOP(info);
}
return 1;
}
static void flush_to_flip_buffer(struct e100_serial *info)
{
struct etrax_recv_buffer *buffer;
unsigned long flags;
local_irq_save(flags);
while ((buffer = info->first_recv_buffer) != NULL) {
unsigned int count = buffer->length;
tty_insert_flip_string(&info->port, buffer->buffer, count);
info->recv_cnt -= count;
if (count == buffer->length) {
info->first_recv_buffer = buffer->next;
kfree(buffer);
} else {
buffer->length -= count;
memmove(buffer->buffer, buffer->buffer + count, buffer->length);
buffer->error = TTY_NORMAL;
}
}
if (!info->first_recv_buffer)
info->last_recv_buffer = NULL;
local_irq_restore(flags);
tty_flip_buffer_push(&info->port);
}
static void check_flush_timeout(struct e100_serial *info)
{
flush_to_flip_buffer(info);
if (info->first_recv_buffer)
START_FLUSH_FAST_TIMER_TIME(info, "flip", 2000);
force_eop_if_needed(info);
}
static void flush_timeout_function(unsigned long data)
{
struct e100_serial *info = (struct e100_serial *)data;
fast_timers[info->line].function = NULL;
serial_fast_timer_expired++;
TIMERD(DEBUG_LOG(info->line, "flush_timeout %i ", info->line));
TIMERD(DEBUG_LOG(info->line, "num expired: %i\n", serial_fast_timer_expired));
check_flush_timeout(info);
}
static void
timed_flush_handler(unsigned long ptr)
{
struct e100_serial *info;
int i;
#ifdef CONFIG_SVINTO_SIM
return;
#endif
for (i = 0; i < NR_PORTS; i++) {
info = rs_table + i;
if (info->uses_dma_in)
check_flush_timeout(info);
}
mod_timer(&flush_timer, jiffies + CONFIG_ETRAX_SERIAL_RX_TIMEOUT_TICKS);
}
static void handle_ser_rx_interrupt_no_dma(struct e100_serial *info)
{
unsigned long data_read;
data_read = *((unsigned long *)&info->ioport[REG_DATA_STATUS32]);
more_data:
if (data_read & IO_MASK(R_SERIAL0_READ, xoff_detect) ) {
DFLOW(DEBUG_LOG(info->line, "XOFF detect\n", 0));
}
DINTR2(DEBUG_LOG(info->line, "ser_rx %c\n", IO_EXTRACT(R_SERIAL0_READ, data_in, data_read)));
if (data_read & ( IO_MASK(R_SERIAL0_READ, framing_err) |
IO_MASK(R_SERIAL0_READ, par_err) |
IO_MASK(R_SERIAL0_READ, overrun) )) {
info->last_rx_active_usec = GET_JIFFIES_USEC();
info->last_rx_active = jiffies;
DINTR1(DEBUG_LOG(info->line, "ser_rx err stat_data %04X\n", data_read));
DLOG_INT_TRIG(
if (!log_int_trig1_pos) {
log_int_trig1_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
);
if ( ((data_read & IO_MASK(R_SERIAL0_READ, data_in)) == 0) &&
(data_read & IO_MASK(R_SERIAL0_READ, framing_err)) ) {
if (!info->break_detected_cnt) {
DEBUG_LOG(info->line, "#BRK start\n", 0);
}
if (data_read & IO_MASK(R_SERIAL0_READ, rxd)) {
DEBUG_LOG(info->line, "# BL BRK\n", 0);
info->errorcode = ERRCODE_INSERT_BREAK;
}
info->break_detected_cnt++;
} else {
if (info->break_detected_cnt) {
DEBUG_LOG(info->line, "EBRK %i\n", info->break_detected_cnt);
info->errorcode = ERRCODE_INSERT_BREAK;
} else {
unsigned char data = IO_EXTRACT(R_SERIAL0_READ,
data_in, data_read);
char flag = TTY_NORMAL;
if (info->errorcode == ERRCODE_INSERT_BREAK) {
tty_insert_flip_char(&info->port, 0, flag);
info->icount.rx++;
}
if (data_read & IO_MASK(R_SERIAL0_READ, par_err)) {
info->icount.parity++;
flag = TTY_PARITY;
} else if (data_read & IO_MASK(R_SERIAL0_READ, overrun)) {
info->icount.overrun++;
flag = TTY_OVERRUN;
} else if (data_read & IO_MASK(R_SERIAL0_READ, framing_err)) {
info->icount.frame++;
flag = TTY_FRAME;
}
tty_insert_flip_char(&info->port, data, flag);
info->errorcode = 0;
}
info->break_detected_cnt = 0;
}
} else if (data_read & IO_MASK(R_SERIAL0_READ, data_avail)) {
DLOG_INT_TRIG(
if (!log_int_trig1_pos) {
if (log_int_pos >= log_int_size) {
log_int_pos = 0;
}
log_int_trig0_pos = log_int_pos;
log_int(rdpc(), 0, 0);
}
);
tty_insert_flip_char(&info->port,
IO_EXTRACT(R_SERIAL0_READ, data_in, data_read),
TTY_NORMAL);
} else {
DEBUG_LOG(info->line, "ser_rx int but no data_avail %08lX\n", data_read);
}
info->icount.rx++;
data_read = *((unsigned long *)&info->ioport[REG_DATA_STATUS32]);
if (data_read & IO_MASK(R_SERIAL0_READ, data_avail)) {
DEBUG_LOG(info->line, "ser_rx %c in loop\n", IO_EXTRACT(R_SERIAL0_READ, data_in, data_read));
goto more_data;
}
tty_flip_buffer_push(&info->port);
}
static void handle_ser_rx_interrupt(struct e100_serial *info)
{
unsigned char rstat;
#ifdef SERIAL_DEBUG_INTR
printk("Interrupt from serport %d\n", i);
#endif
if (!info->uses_dma_in) {
handle_ser_rx_interrupt_no_dma(info);
return;
}
rstat = info->ioport[REG_STATUS];
if (rstat & IO_MASK(R_SERIAL0_STATUS, xoff_detect) ) {
DFLOW(DEBUG_LOG(info->line, "XOFF detect\n", 0));
}
if (rstat & SER_ERROR_MASK) {
unsigned char data;
info->last_rx_active_usec = GET_JIFFIES_USEC();
info->last_rx_active = jiffies;
data = info->ioport[REG_DATA];
DINTR1(DEBUG_LOG(info->line, "ser_rx! %c\n", data));
DINTR1(DEBUG_LOG(info->line, "ser_rx err stat %02X\n", rstat));
if (!data && (rstat & SER_FRAMING_ERR_MASK)) {
if (!info->break_detected_cnt) {
DEBUG_LOG(info->line, "#BRK start\n", 0);
}
if (rstat & SER_RXD_MASK) {
DEBUG_LOG(info->line, "# BL BRK\n", 0);
info->errorcode = ERRCODE_INSERT_BREAK;
}
info->break_detected_cnt++;
} else {
if (info->break_detected_cnt) {
DEBUG_LOG(info->line, "EBRK %i\n", info->break_detected_cnt);
info->errorcode = ERRCODE_INSERT_BREAK;
} else {
if (info->errorcode == ERRCODE_INSERT_BREAK) {
info->icount.brk++;
add_char_and_flag(info, '\0', TTY_BREAK);
}
if (rstat & SER_PAR_ERR_MASK) {
info->icount.parity++;
add_char_and_flag(info, data, TTY_PARITY);
} else if (rstat & SER_OVERRUN_MASK) {
info->icount.overrun++;
add_char_and_flag(info, data, TTY_OVERRUN);
} else if (rstat & SER_FRAMING_ERR_MASK) {
info->icount.frame++;
add_char_and_flag(info, data, TTY_FRAME);
}
info->errorcode = 0;
}
info->break_detected_cnt = 0;
DEBUG_LOG(info->line, "#iERR s d %04X\n",
((rstat & SER_ERROR_MASK) << 8) | data);
}
PROCSTAT(ser_stat[info->line].early_errors_cnt++);
} else {
unsigned long curr_time_u = GET_JIFFIES_USEC();
unsigned long curr_time = jiffies;
if (info->break_detected_cnt) {
long elapsed_usec =
(curr_time - info->last_rx_active) * (1000000/HZ) +
curr_time_u - info->last_rx_active_usec;
if (elapsed_usec < 2*info->char_time_usec) {
DEBUG_LOG(info->line, "FBRK %i\n", info->line);
info->errorcode = ERRCODE_SET_BREAK;
} else {
DEBUG_LOG(info->line, "Not end of BRK (V)%i\n", info->line);
}
DEBUG_LOG(info->line, "num brk %i\n", info->break_detected_cnt);
}
#ifdef SERIAL_DEBUG_INTR
printk("** OK, disabling ser_interrupts\n");
#endif
e100_disable_serial_data_irq(info);
DINTR2(DEBUG_LOG(info->line, "ser_rx OK %d\n", info->line));
info->break_detected_cnt = 0;
PROCSTAT(ser_stat[info->line].ser_ints_ok_cnt++);
}
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, restart);
START_FLUSH_FAST_TIMER(info, "ser_int");
}
static void handle_ser_tx_interrupt(struct e100_serial *info)
{
unsigned long flags;
if (info->x_char) {
unsigned char rstat;
DFLOW(DEBUG_LOG(info->line, "tx_int: xchar 0x%02X\n", info->x_char));
local_irq_save(flags);
rstat = info->ioport[REG_STATUS];
DFLOW(DEBUG_LOG(info->line, "stat %x\n", rstat));
info->ioport[REG_TR_DATA] = info->x_char;
info->icount.tx++;
info->x_char = 0;
e100_enable_serial_tx_ready_irq(info);
local_irq_restore(flags);
return;
}
if (info->uses_dma_out) {
unsigned char rstat;
int i;
DFLOW(DEBUG_LOG(info->line, "tx_int: xchar sent\n", 0));
local_irq_save(flags);
rstat = info->ioport[REG_STATUS];
DFLOW(DEBUG_LOG(info->line, "stat %x\n", rstat));
e100_disable_serial_tx_ready_irq(info);
if (info->port.tty->stopped)
rs_stop(info->port.tty);
e100_enable_txdma_channel(info);
for(i = 6; i > 0; i--)
nop();
*info->ocmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, continue);
local_irq_restore(flags);
return;
}
if (info->xmit.head == info->xmit.tail
|| info->port.tty->stopped) {
DFLOW(DEBUG_LOG(info->line, "tx_int: stopped %i\n",
info->port.tty->stopped));
e100_disable_serial_tx_ready_irq(info);
info->tr_running = 0;
return;
}
DINTR2(DEBUG_LOG(info->line, "tx_int %c\n", info->xmit.buf[info->xmit.tail]));
local_irq_save(flags);
info->ioport[REG_TR_DATA] = info->xmit.buf[info->xmit.tail];
info->xmit.tail = (info->xmit.tail + 1) & (SERIAL_XMIT_SIZE-1);
info->icount.tx++;
if (info->xmit.head == info->xmit.tail) {
#if defined(CONFIG_ETRAX_RS485) && defined(CONFIG_ETRAX_FAST_TIMER)
if (info->rs485.flags & SER_RS485_ENABLED) {
start_one_shot_timer(&fast_timers_rs485[info->line],
rs485_toggle_rts_timer_function,
(unsigned long)info,
info->char_time_usec*2,
"RS-485");
}
#endif
info->last_tx_active_usec = GET_JIFFIES_USEC();
info->last_tx_active = jiffies;
e100_disable_serial_tx_ready_irq(info);
info->tr_running = 0;
DFLOW(DEBUG_LOG(info->line, "tx_int: stop2\n", 0));
} else {
e100_enable_serial_tx_ready_irq(info);
}
local_irq_restore(flags);
if (CIRC_CNT(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE) < WAKEUP_CHARS)
rs_sched_event(info, RS_EVENT_WRITE_WAKEUP);
}
static irqreturn_t
ser_interrupt(int irq, void *dev_id)
{
static volatile int tx_started = 0;
struct e100_serial *info;
int i;
unsigned long flags;
unsigned long irq_mask1_rd;
unsigned long data_mask = (1 << (8+2*0));
int handled = 0;
static volatile unsigned long reentered_ready_mask = 0;
local_irq_save(flags);
irq_mask1_rd = *R_IRQ_MASK1_RD;
info = rs_table;
irq_mask1_rd &= e100_ser_int_mask;
for (i = 0; i < NR_PORTS; i++) {
if (irq_mask1_rd & data_mask) {
handled = 1;
handle_ser_rx_interrupt(info);
}
info += 1;
data_mask <<= 2;
}
if (!tx_started) {
unsigned long ready_mask;
unsigned long
tx_started = 1;
irq_mask1_rd &= (IO_MASK(R_IRQ_MASK1_RD, ser0_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser1_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser2_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser3_ready));
while (irq_mask1_rd) {
*R_IRQ_MASK1_CLR = irq_mask1_rd;
*R_VECT_MASK_SET = IO_STATE(R_VECT_MASK_SET, serial, set);
local_irq_enable();
ready_mask = (1 << (8+1+2*0));
info = rs_table;
for (i = 0; i < NR_PORTS; i++) {
if (irq_mask1_rd & ready_mask) {
handled = 1;
handle_ser_tx_interrupt(info);
}
info += 1;
ready_mask <<= 2;
}
local_irq_disable();
irq_mask1_rd = reentered_ready_mask;
}
local_irq_disable();
tx_started = 0;
} else {
unsigned long ready_mask;
ready_mask = irq_mask1_rd & (IO_MASK(R_IRQ_MASK1_RD, ser0_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser1_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser2_ready) |
IO_MASK(R_IRQ_MASK1_RD, ser3_ready));
if (ready_mask) {
reentered_ready_mask |= ready_mask;
*R_IRQ_MASK1_CLR = ready_mask;
DFLOW(DEBUG_LOG(SERIAL_DEBUG_LINE, "ser_int reentered with TX %X\n", ready_mask));
}
}
local_irq_restore(flags);
return IRQ_RETVAL(handled);
}
static void
do_softint(struct work_struct *work)
{
struct e100_serial *info;
struct tty_struct *tty;
info = container_of(work, struct e100_serial, work);
tty = info->port.tty;
if (!tty)
return;
if (test_and_clear_bit(RS_EVENT_WRITE_WAKEUP, &info->event))
tty_wakeup(tty);
}
static int
startup(struct e100_serial * info)
{
unsigned long flags;
unsigned long xmit_page;
int i;
xmit_page = get_zeroed_page(GFP_KERNEL);
if (!xmit_page)
return -ENOMEM;
local_irq_save(flags);
if (info->port.flags & ASYNC_INITIALIZED) {
local_irq_restore(flags);
free_page(xmit_page);
return 0;
}
if (info->xmit.buf)
free_page(xmit_page);
else
info->xmit.buf = (unsigned char *) xmit_page;
#ifdef SERIAL_DEBUG_OPEN
printk("starting up ttyS%d (xmit_buf 0x%p)...\n", info->line, info->xmit.buf);
#endif
#ifdef CONFIG_SVINTO_SIM
if (info->port.tty)
clear_bit(TTY_IO_ERROR, &info->port.tty->flags);
info->xmit.head = info->xmit.tail = 0;
info->first_recv_buffer = info->last_recv_buffer = NULL;
info->recv_cnt = info->max_recv_cnt = 0;
for (i = 0; i < SERIAL_RECV_DESCRIPTORS; i++)
info->rec_descr[i].buf = NULL;
change_speed(info);
#else
if (info->dma_in_enabled) {
info->uses_dma_in = 1;
e100_enable_rxdma_channel(info);
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, reset);
while (IO_EXTRACT(R_DMA_CH6_CMD, cmd, *info->icmdadr) ==
IO_STATE_VALUE(R_DMA_CH6_CMD, cmd, reset));
*info->iclrintradr =
IO_STATE(R_DMA_CH6_CLR_INTR, clr_descr, do) |
IO_STATE(R_DMA_CH6_CLR_INTR, clr_eop, do);
} else {
e100_disable_rxdma_channel(info);
}
if (info->dma_out_enabled) {
info->uses_dma_out = 1;
e100_enable_txdma_channel(info);
*info->ocmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, reset);
while (IO_EXTRACT(R_DMA_CH6_CMD, cmd, *info->ocmdadr) ==
IO_STATE_VALUE(R_DMA_CH6_CMD, cmd, reset));
*info->oclrintradr =
IO_STATE(R_DMA_CH6_CLR_INTR, clr_descr, do) |
IO_STATE(R_DMA_CH6_CLR_INTR, clr_eop, do);
} else {
e100_disable_txdma_channel(info);
}
if (info->port.tty)
clear_bit(TTY_IO_ERROR, &info->port.tty->flags);
info->xmit.head = info->xmit.tail = 0;
info->first_recv_buffer = info->last_recv_buffer = NULL;
info->recv_cnt = info->max_recv_cnt = 0;
for (i = 0; i < SERIAL_RECV_DESCRIPTORS; i++)
info->rec_descr[i].buf = 0;
#ifdef SERIAL_HANDLE_EARLY_ERRORS
e100_enable_serial_data_irq(info);
#endif
change_speed(info);
(void)info->ioport[REG_DATA];
if (info->uses_dma_out)
e100_enable_txdma_irq(info);
e100_enable_rx_irq(info);
info->tr_running = 0;
start_receive(info);
info->tr_descr.sw_len = 0;
info->tr_descr.hw_len = 0;
info->tr_descr.status = 0;
e100_rts(info, 1);
e100_dtr(info, 1);
#endif
info->port.flags |= ASYNC_INITIALIZED;
local_irq_restore(flags);
return 0;
}
static void
shutdown(struct e100_serial * info)
{
unsigned long flags;
struct etrax_dma_descr *descr = info->rec_descr;
struct etrax_recv_buffer *buffer;
int i;
#ifndef CONFIG_SVINTO_SIM
DFLOW(DEBUG_LOG(info->line, "shutdown %i\n", info->line));
e100_disable_rx(info);
info->ioport[REG_TR_CTRL] = (info->tx_ctrl &= ~0x40);
if (info->uses_dma_in) {
e100_disable_rxdma_irq(info);
*info->icmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, reset);
info->uses_dma_in = 0;
} else {
e100_disable_serial_data_irq(info);
}
if (info->uses_dma_out) {
e100_disable_txdma_irq(info);
info->tr_running = 0;
*info->ocmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, reset);
info->uses_dma_out = 0;
} else {
e100_disable_serial_tx_ready_irq(info);
info->tr_running = 0;
}
#endif
if (!(info->port.flags & ASYNC_INITIALIZED))
return;
#ifdef SERIAL_DEBUG_OPEN
printk("Shutting down serial port %d (irq %d)....\n", info->line,
info->irq);
#endif
local_irq_save(flags);
if (info->xmit.buf) {
free_page((unsigned long)info->xmit.buf);
info->xmit.buf = NULL;
}
for (i = 0; i < SERIAL_RECV_DESCRIPTORS; i++)
if (descr[i].buf) {
buffer = phys_to_virt(descr[i].buf) - sizeof *buffer;
kfree(buffer);
descr[i].buf = 0;
}
if (!info->port.tty || (info->port.tty->termios.c_cflag & HUPCL)) {
e100_dtr(info, 0);
e100_rts(info, 0);
}
if (info->port.tty)
set_bit(TTY_IO_ERROR, &info->port.tty->flags);
info->port.flags &= ~ASYNC_INITIALIZED;
local_irq_restore(flags);
}
static void
change_speed(struct e100_serial *info)
{
unsigned int cflag;
unsigned long xoff;
unsigned long flags;
if (!info->port.tty)
return;
if (!info->ioport)
return;
cflag = info->port.tty->termios.c_cflag;
if ((info->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST) {
u32 mask = 0xFF << (info->line*8);
unsigned long alt_source =
IO_STATE(R_ALT_SER_BAUDRATE, ser0_rec, normal) |
IO_STATE(R_ALT_SER_BAUDRATE, ser0_tr, normal);
DBAUD(printk("Custom baudrate: baud_base/divisor %lu/%i\n",
(unsigned long)info->baud_base, info->custom_divisor));
if (info->baud_base == SERIAL_PRESCALE_BASE) {
u16 divisor = info->custom_divisor;
alt_source =
IO_STATE(R_ALT_SER_BAUDRATE, ser0_rec, prescale) |
IO_STATE(R_ALT_SER_BAUDRATE, ser0_tr, prescale);
alt_source = 0x11;
DBAUD(printk("Writing SERIAL_PRESCALE: divisor %i\n", divisor));
*R_SERIAL_PRESCALE = divisor;
info->baud = SERIAL_PRESCALE_BASE/divisor;
}
#ifdef CONFIG_ETRAX_EXTERN_PB6CLK_ENABLED
else if ((info->baud_base==CONFIG_ETRAX_EXTERN_PB6CLK_FREQ/8 &&
info->custom_divisor == 1) ||
(info->baud_base==CONFIG_ETRAX_EXTERN_PB6CLK_FREQ &&
info->custom_divisor == 8)) {
alt_source =
IO_STATE(R_ALT_SER_BAUDRATE, ser0_rec, extern) |
IO_STATE(R_ALT_SER_BAUDRATE, ser0_tr, extern);
DBAUD(printk("using external baudrate: %lu\n", CONFIG_ETRAX_EXTERN_PB6CLK_FREQ/8));
info->baud = CONFIG_ETRAX_EXTERN_PB6CLK_FREQ/8;
}
#endif
else
{
printk(KERN_WARNING "Bad baud_base/custom_divisor: %lu/%i\n",
(unsigned long)info->baud_base, info->custom_divisor);
}
r_alt_ser_baudrate_shadow &= ~mask;
r_alt_ser_baudrate_shadow |= (alt_source << (info->line*8));
*R_ALT_SER_BAUDRATE = r_alt_ser_baudrate_shadow;
} else {
u32 mask = 0xFF << (info->line*8);
unsigned long alt_source =
IO_STATE(R_ALT_SER_BAUDRATE, ser0_rec, normal) |
IO_STATE(R_ALT_SER_BAUDRATE, ser0_tr, normal);
r_alt_ser_baudrate_shadow &= ~mask;
r_alt_ser_baudrate_shadow |= (alt_source << (info->line*8));
#ifndef CONFIG_SVINTO_SIM
*R_ALT_SER_BAUDRATE = r_alt_ser_baudrate_shadow;
#endif
info->baud = cflag_to_baud(cflag);
#ifndef CONFIG_SVINTO_SIM
info->ioport[REG_BAUD] = cflag_to_etrax_baud(cflag);
#endif
}
#ifndef CONFIG_SVINTO_SIM
local_irq_save(flags);
info->rx_ctrl &= ~(IO_MASK(R_SERIAL0_REC_CTRL, rec_bitnr) |
IO_MASK(R_SERIAL0_REC_CTRL, rec_par_en) |
IO_MASK(R_SERIAL0_REC_CTRL, rec_par));
info->tx_ctrl &= ~(IO_MASK(R_SERIAL0_TR_CTRL, tr_bitnr) |
IO_MASK(R_SERIAL0_TR_CTRL, tr_par_en) |
IO_MASK(R_SERIAL0_TR_CTRL, tr_par) |
IO_MASK(R_SERIAL0_TR_CTRL, stop_bits) |
IO_MASK(R_SERIAL0_TR_CTRL, auto_cts));
if ((cflag & CSIZE) == CS7) {
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_bitnr, tr_7bit);
info->rx_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_bitnr, rec_7bit);
}
if (cflag & CSTOPB) {
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, stop_bits, two_bits);
}
if (cflag & PARENB) {
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_par_en, enable);
info->rx_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_par_en, enable);
}
if (cflag & CMSPAR) {
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_stick_par, stick);
info->rx_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_stick_par, stick);
}
if (cflag & PARODD) {
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_par, odd);
info->rx_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_par, odd);
}
if (cflag & CRTSCTS) {
DFLOW(DEBUG_LOG(info->line, "FLOW auto_cts enabled\n", 0));
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, auto_cts, active);
}
info->tx_ctrl |= IO_STATE(R_SERIAL0_TR_CTRL, tr_enable, enable);
info->rx_ctrl |= IO_STATE(R_SERIAL0_REC_CTRL, rec_enable, enable);
info->ioport[REG_TR_CTRL] = info->tx_ctrl;
info->ioport[REG_REC_CTRL] = info->rx_ctrl;
xoff = IO_FIELD(R_SERIAL0_XOFF, xoff_char, STOP_CHAR(info->port.tty));
xoff |= IO_STATE(R_SERIAL0_XOFF, tx_stop, enable);
if (info->port.tty->termios.c_iflag & IXON ) {
DFLOW(DEBUG_LOG(info->line, "FLOW XOFF enabled 0x%02X\n",
STOP_CHAR(info->port.tty)));
xoff |= IO_STATE(R_SERIAL0_XOFF, auto_xoff, enable);
}
*((unsigned long *)&info->ioport[REG_XOFF]) = xoff;
local_irq_restore(flags);
#endif
update_char_time(info);
}
static void
rs_flush_chars(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
if (info->tr_running ||
info->xmit.head == info->xmit.tail ||
tty->stopped ||
!info->xmit.buf)
return;
#ifdef SERIAL_DEBUG_FLOW
printk("rs_flush_chars\n");
#endif
local_irq_save(flags);
start_transmit(info);
local_irq_restore(flags);
}
static int rs_raw_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
int c, ret = 0;
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
if (!info->xmit.buf)
return 0;
#ifdef SERIAL_DEBUG_DATA
if (info->line == SERIAL_DEBUG_LINE)
printk("rs_raw_write (%d), status %d\n",
count, info->ioport[REG_STATUS]);
#endif
#ifdef CONFIG_SVINTO_SIM
SIMCOUT(buf, count);
return count;
#endif
local_save_flags(flags);
DFLOW(DEBUG_LOG(info->line, "write count %i ", count));
DFLOW(DEBUG_LOG(info->line, "ldisc %i\n", tty->ldisc.chars_in_buffer(tty)));
local_irq_disable();
while (count) {
c = CIRC_SPACE_TO_END(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE);
if (count < c)
c = count;
if (c <= 0)
break;
memcpy(info->xmit.buf + info->xmit.head, buf, c);
info->xmit.head = (info->xmit.head + c) &
(SERIAL_XMIT_SIZE-1);
buf += c;
count -= c;
ret += c;
}
local_irq_restore(flags);
DFLOW(DEBUG_LOG(info->line, "write ret %i\n", ret));
if (info->xmit.head != info->xmit.tail &&
!tty->stopped &&
!info->tr_running) {
start_transmit(info);
}
return ret;
}
static int
rs_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
#if defined(CONFIG_ETRAX_RS485)
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
if (info->rs485.flags & SER_RS485_ENABLED)
{
#ifdef CONFIG_ETRAX_FAST_TIMER
fast_timers_rs485[info->line].function = NULL;
del_fast_timer(&fast_timers_rs485[info->line]);
#endif
e100_rts(info, (info->rs485.flags & SER_RS485_RTS_ON_SEND));
#if defined(CONFIG_ETRAX_RS485_DISABLE_RECEIVER)
e100_disable_rx(info);
e100_enable_rx_irq(info);
#endif
if (info->rs485.delay_rts_before_send > 0)
msleep(info->rs485.delay_rts_before_send);
}
#endif
count = rs_raw_write(tty, buf, count);
#if defined(CONFIG_ETRAX_RS485)
if (info->rs485.flags & SER_RS485_ENABLED)
{
unsigned int val;
tty_wait_until_sent(tty, 0);
#ifdef CONFIG_ETRAX_FAST_TIMER
schedule_usleep(info->char_time_usec * 2);
#endif
do{
get_lsr_info(info, &val);
}while (!(val & TIOCSER_TEMT));
e100_rts(info, (info->rs485.flags & SER_RS485_RTS_AFTER_SEND));
#if defined(CONFIG_ETRAX_RS485_DISABLE_RECEIVER)
e100_enable_rx(info);
e100_enable_rxdma_irq(info);
#endif
}
#endif
return count;
}
static int
rs_write_room(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
return CIRC_SPACE(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static int
rs_chars_in_buffer(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
return CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static void
rs_flush_buffer(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
local_irq_save(flags);
info->xmit.head = info->xmit.tail = 0;
local_irq_restore(flags);
tty_wakeup(tty);
}
static void rs_send_xchar(struct tty_struct *tty, char ch)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
local_irq_save(flags);
if (info->uses_dma_out) {
*info->ocmdadr = IO_STATE(R_DMA_CH6_CMD, cmd, hold);
while (IO_EXTRACT(R_DMA_CH6_CMD, cmd, *info->ocmdadr) !=
IO_STATE_VALUE(R_DMA_CH6_CMD, cmd, hold));
e100_disable_txdma_channel(info);
}
if (tty->stopped)
rs_start(tty);
DFLOW(DEBUG_LOG(info->line, "rs_send_xchar 0x%02X\n", ch));
info->x_char = ch;
e100_enable_serial_tx_ready_irq(info);
local_irq_restore(flags);
}
static void
rs_throttle(struct tty_struct * tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
#ifdef SERIAL_DEBUG_THROTTLE
char buf[64];
printk("throttle %s: %lu....\n", tty_name(tty, buf),
(unsigned long)tty->ldisc.chars_in_buffer(tty));
#endif
DFLOW(DEBUG_LOG(info->line,"rs_throttle %lu\n", tty->ldisc.chars_in_buffer(tty)));
if (tty->termios.c_cflag & CRTSCTS) {
e100_rts(info, 0);
}
if (I_IXOFF(tty))
rs_send_xchar(tty, STOP_CHAR(tty));
}
static void
rs_unthrottle(struct tty_struct * tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
#ifdef SERIAL_DEBUG_THROTTLE
char buf[64];
printk("unthrottle %s: %lu....\n", tty_name(tty, buf),
(unsigned long)tty->ldisc.chars_in_buffer(tty));
#endif
DFLOW(DEBUG_LOG(info->line,"rs_unthrottle ldisc %d\n", tty->ldisc.chars_in_buffer(tty)));
DFLOW(DEBUG_LOG(info->line,"rs_unthrottle flip.count: %i\n", tty->flip.count));
if (tty->termios.c_cflag & CRTSCTS) {
e100_rts(info, 1);
}
if (I_IXOFF(tty)) {
if (info->x_char)
info->x_char = 0;
else
rs_send_xchar(tty, START_CHAR(tty));
}
}
static int
get_serial_info(struct e100_serial * info,
struct serial_struct * retinfo)
{
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tmp.type = info->type;
tmp.line = info->line;
tmp.port = (int)info->ioport;
tmp.irq = info->irq;
tmp.flags = info->port.flags;
tmp.baud_base = info->baud_base;
tmp.close_delay = info->port.close_delay;
tmp.closing_wait = info->port.closing_wait;
tmp.custom_divisor = info->custom_divisor;
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int
set_serial_info(struct e100_serial *info,
struct serial_struct *new_info)
{
struct serial_struct new_serial;
struct e100_serial old_info;
int retval = 0;
if (copy_from_user(&new_serial, new_info, sizeof(new_serial)))
return -EFAULT;
old_info = *info;
if (!capable(CAP_SYS_ADMIN)) {
if ((new_serial.type != info->type) ||
(new_serial.close_delay != info->port.close_delay) ||
((new_serial.flags & ~ASYNC_USR_MASK) !=
(info->port.flags & ~ASYNC_USR_MASK)))
return -EPERM;
info->port.flags = ((info->port.flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
goto check_and_exit;
}
if (info->port.count > 1)
return -EBUSY;
info->baud_base = new_serial.baud_base;
info->port.flags = ((info->port.flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
info->custom_divisor = new_serial.custom_divisor;
info->type = new_serial.type;
info->port.close_delay = new_serial.close_delay;
info->port.closing_wait = new_serial.closing_wait;
info->port.low_latency = (info->port.flags & ASYNC_LOW_LATENCY) ? 1 : 0;
check_and_exit:
if (info->port.flags & ASYNC_INITIALIZED) {
change_speed(info);
} else
retval = startup(info);
return retval;
}
static int
get_lsr_info(struct e100_serial * info, unsigned int *value)
{
unsigned int result = TIOCSER_TEMT;
#ifndef CONFIG_SVINTO_SIM
unsigned long curr_time = jiffies;
unsigned long curr_time_usec = GET_JIFFIES_USEC();
unsigned long elapsed_usec =
(curr_time - info->last_tx_active) * 1000000/HZ +
curr_time_usec - info->last_tx_active_usec;
if (info->xmit.head != info->xmit.tail ||
elapsed_usec < 2*info->char_time_usec) {
result = 0;
}
#endif
if (copy_to_user(value, &result, sizeof(int)))
return -EFAULT;
return 0;
}
char *get_control_state_str(int MLines, char *s)
{
int i = 0;
s[0]='\0';
while (control_state_str[i].str != NULL) {
if (MLines & control_state_str[i].state) {
if (s[0] != '\0') {
strcat(s, ", ");
}
strcat(s, control_state_str[i].str);
}
i++;
}
return s;
}
static int
rs_break(struct tty_struct *tty, int break_state)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
if (!info->ioport)
return -EIO;
local_irq_save(flags);
if (break_state == -1) {
info->tx_ctrl &= 0x3F;
} else {
info->tx_ctrl |= (0x80 | 0x40);
}
info->ioport[REG_TR_CTRL] = info->tx_ctrl;
local_irq_restore(flags);
return 0;
}
static int
rs_tiocmset(struct tty_struct *tty, unsigned int set, unsigned int clear)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
local_irq_save(flags);
if (clear & TIOCM_RTS)
e100_rts(info, 0);
if (clear & TIOCM_DTR)
e100_dtr(info, 0);
if (clear & TIOCM_RI)
e100_ri_out(info, 0);
if (clear & TIOCM_CD)
e100_cd_out(info, 0);
if (set & TIOCM_RTS)
e100_rts(info, 1);
if (set & TIOCM_DTR)
e100_dtr(info, 1);
if (set & TIOCM_RI)
e100_ri_out(info, 1);
if (set & TIOCM_CD)
e100_cd_out(info, 1);
local_irq_restore(flags);
return 0;
}
static int
rs_tiocmget(struct tty_struct *tty)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned int result;
unsigned long flags;
local_irq_save(flags);
result =
(!E100_RTS_GET(info) ? TIOCM_RTS : 0)
| (!E100_DTR_GET(info) ? TIOCM_DTR : 0)
| (!E100_RI_GET(info) ? TIOCM_RNG : 0)
| (!E100_DSR_GET(info) ? TIOCM_DSR : 0)
| (!E100_CD_GET(info) ? TIOCM_CAR : 0)
| (!E100_CTS_GET(info) ? TIOCM_CTS : 0);
local_irq_restore(flags);
#ifdef SERIAL_DEBUG_IO
printk(KERN_DEBUG "ser%i: modem state: %i 0x%08X\n",
info->line, result, result);
{
char s[100];
get_control_state_str(result, s);
printk(KERN_DEBUG "state: %s\n", s);
}
#endif
return result;
}
static int
rs_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct e100_serial * info = (struct e100_serial *)tty->driver_data;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGWILD) &&
(cmd != TIOCSERSWILD) && (cmd != TIOCSERGSTRUCT)) {
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
}
switch (cmd) {
case TIOCGSERIAL:
return get_serial_info(info,
(struct serial_struct *) arg);
case TIOCSSERIAL:
return set_serial_info(info,
(struct serial_struct *) arg);
case TIOCSERGETLSR:
return get_lsr_info(info, (unsigned int *) arg);
case TIOCSERGSTRUCT:
if (copy_to_user((struct e100_serial *) arg,
info, sizeof(struct e100_serial)))
return -EFAULT;
return 0;
#if defined(CONFIG_ETRAX_RS485)
case TIOCSERSETRS485:
{
struct rs485_control rs485ctrl;
struct serial_rs485 rs485data;
printk(KERN_DEBUG "The use of this ioctl is deprecated. Use TIOCSRS485 instead\n");
if (copy_from_user(&rs485ctrl, (struct rs485_control *)arg,
sizeof(rs485ctrl)))
return -EFAULT;
rs485data.delay_rts_before_send = rs485ctrl.delay_rts_before_send;
rs485data.flags = 0;
if (rs485ctrl.enabled)
rs485data.flags |= SER_RS485_ENABLED;
else
rs485data.flags &= ~(SER_RS485_ENABLED);
if (rs485ctrl.rts_on_send)
rs485data.flags |= SER_RS485_RTS_ON_SEND;
else
rs485data.flags &= ~(SER_RS485_RTS_ON_SEND);
if (rs485ctrl.rts_after_sent)
rs485data.flags |= SER_RS485_RTS_AFTER_SEND;
else
rs485data.flags &= ~(SER_RS485_RTS_AFTER_SEND);
return e100_enable_rs485(tty, &rs485data);
}
case TIOCSRS485:
{
struct serial_rs485 rs485data;
if (copy_from_user(&rs485data, (struct rs485_control *)arg,
sizeof(rs485data)))
return -EFAULT;
return e100_enable_rs485(tty, &rs485data);
}
case TIOCGRS485:
{
struct serial_rs485 *rs485data =
&(((struct e100_serial *)tty->driver_data)->rs485);
if (copy_to_user((struct serial_rs485 *) arg,
rs485data,
sizeof(struct serial_rs485)))
return -EFAULT;
break;
}
case TIOCSERWRRS485:
{
struct rs485_write rs485wr;
if (copy_from_user(&rs485wr, (struct rs485_write *)arg,
sizeof(rs485wr)))
return -EFAULT;
return e100_write_rs485(tty, rs485wr.outc, rs485wr.outc_size);
}
#endif
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void
rs_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
change_speed(info);
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios.c_cflag & CRTSCTS))
rs_start(tty);
}
static void
rs_close(struct tty_struct *tty, struct file * filp)
{
struct e100_serial * info = (struct e100_serial *)tty->driver_data;
unsigned long flags;
if (!info)
return;
local_irq_save(flags);
if (tty_hung_up_p(filp)) {
local_irq_restore(flags);
return;
}
#ifdef SERIAL_DEBUG_OPEN
printk("[%d] rs_close ttyS%d, count = %d\n", current->pid,
info->line, info->count);
#endif
if ((tty->count == 1) && (info->port.count != 1)) {
printk(KERN_ERR
"rs_close: bad serial port count; tty->count is 1, "
"info->count is %d\n", info->port.count);
info->port.count = 1;
}
if (--info->port.count < 0) {
printk(KERN_ERR "rs_close: bad serial port count for ttyS%d: %d\n",
info->line, info->port.count);
info->port.count = 0;
}
if (info->port.count) {
local_irq_restore(flags);
return;
}
info->port.flags |= ASYNC_CLOSING;
if (info->port.flags & ASYNC_NORMAL_ACTIVE)
info->normal_termios = tty->termios;
tty->closing = 1;
if (info->port.closing_wait != ASYNC_CLOSING_WAIT_NONE)
tty_wait_until_sent(tty, info->port.closing_wait);
#ifdef SERIAL_HANDLE_EARLY_ERRORS
e100_disable_serial_data_irq(info);
#endif
#ifndef CONFIG_SVINTO_SIM
e100_disable_rx(info);
e100_disable_rx_irq(info);
if (info->port.flags & ASYNC_INITIALIZED) {
rs_wait_until_sent(tty, HZ);
}
#endif
shutdown(info);
rs_flush_buffer(tty);
tty_ldisc_flush(tty);
tty->closing = 0;
info->event = 0;
info->port.tty = NULL;
if (info->port.blocked_open) {
if (info->port.close_delay)
schedule_timeout_interruptible(info->port.close_delay);
wake_up_interruptible(&info->port.open_wait);
}
info->port.flags &= ~(ASYNC_NORMAL_ACTIVE|ASYNC_CLOSING);
wake_up_interruptible(&info->port.close_wait);
local_irq_restore(flags);
#if defined(CONFIG_ETRAX_RS485)
if (info->rs485.flags & SER_RS485_ENABLED) {
info->rs485.flags &= ~(SER_RS485_ENABLED);
#if defined(CONFIG_ETRAX_RS485_ON_PA)
*R_PORT_PA_DATA = port_pa_data_shadow &= ~(1 << rs485_pa_bit);
#endif
#if defined(CONFIG_ETRAX_RS485_ON_PORT_G)
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
rs485_port_g_bit, 0);
#endif
#if defined(CONFIG_ETRAX_RS485_LTC1387)
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
CONFIG_ETRAX_RS485_LTC1387_DXEN_PORT_G_BIT, 0);
REG_SHADOW_SET(R_PORT_G_DATA, port_g_data_shadow,
CONFIG_ETRAX_RS485_LTC1387_RXEN_PORT_G_BIT, 0);
#endif
}
#endif
if (info->dma_in_enabled) {
free_irq(info->dma_in_irq_nbr, info);
cris_free_dma(info->dma_in_nbr, info->dma_in_irq_description);
info->uses_dma_in = 0;
#ifdef SERIAL_DEBUG_OPEN
printk(KERN_DEBUG "DMA irq '%s' freed\n",
info->dma_in_irq_description);
#endif
}
if (info->dma_out_enabled) {
free_irq(info->dma_out_irq_nbr, info);
cris_free_dma(info->dma_out_nbr, info->dma_out_irq_description);
info->uses_dma_out = 0;
#ifdef SERIAL_DEBUG_OPEN
printk(KERN_DEBUG "DMA irq '%s' freed\n",
info->dma_out_irq_description);
#endif
}
}
static void rs_wait_until_sent(struct tty_struct *tty, int timeout)
{
unsigned long orig_jiffies;
struct e100_serial *info = (struct e100_serial *)tty->driver_data;
unsigned long curr_time = jiffies;
unsigned long curr_time_usec = GET_JIFFIES_USEC();
long elapsed_usec =
(curr_time - info->last_tx_active) * (1000000/HZ) +
curr_time_usec - info->last_tx_active_usec;
orig_jiffies = jiffies;
while (info->xmit.head != info->xmit.tail ||
(*info->ostatusadr & 0x007f) ||
(elapsed_usec < 2*info->char_time_usec)) {
schedule_timeout_interruptible(1);
if (signal_pending(current))
break;
if (timeout && time_after(jiffies, orig_jiffies + timeout))
break;
curr_time = jiffies;
curr_time_usec = GET_JIFFIES_USEC();
elapsed_usec =
(curr_time - info->last_tx_active) * (1000000/HZ) +
curr_time_usec - info->last_tx_active_usec;
}
set_current_state(TASK_RUNNING);
}
void
rs_hangup(struct tty_struct *tty)
{
struct e100_serial * info = (struct e100_serial *)tty->driver_data;
rs_flush_buffer(tty);
shutdown(info);
info->event = 0;
info->port.count = 0;
info->port.flags &= ~ASYNC_NORMAL_ACTIVE;
info->port.tty = NULL;
wake_up_interruptible(&info->port.open_wait);
}
static int
block_til_ready(struct tty_struct *tty, struct file * filp,
struct e100_serial *info)
{
DECLARE_WAITQUEUE(wait, current);
unsigned long flags;
int retval;
int do_clocal = 0, extra_count = 0;
if (tty_hung_up_p(filp) ||
(info->port.flags & ASYNC_CLOSING)) {
wait_event_interruptible_tty(tty, info->port.close_wait,
!(info->port.flags & ASYNC_CLOSING));
#ifdef SERIAL_DO_RESTART
if (info->port.flags & ASYNC_HUP_NOTIFY)
return -EAGAIN;
else
return -ERESTARTSYS;
#else
return -EAGAIN;
#endif
}
if ((filp->f_flags & O_NONBLOCK) ||
(tty->flags & (1 << TTY_IO_ERROR))) {
info->port.flags |= ASYNC_NORMAL_ACTIVE;
return 0;
}
if (tty->termios.c_cflag & CLOCAL) {
do_clocal = 1;
}
retval = 0;
add_wait_queue(&info->port.open_wait, &wait);
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready before block: ttyS%d, count = %d\n",
info->line, info->port.count);
#endif
local_irq_save(flags);
if (!tty_hung_up_p(filp)) {
extra_count++;
info->port.count--;
}
local_irq_restore(flags);
info->port.blocked_open++;
while (1) {
local_irq_save(flags);
e100_rts(info, 1);
e100_dtr(info, 1);
local_irq_restore(flags);
set_current_state(TASK_INTERRUPTIBLE);
if (tty_hung_up_p(filp) ||
!(info->port.flags & ASYNC_INITIALIZED)) {
#ifdef SERIAL_DO_RESTART
if (info->port.flags & ASYNC_HUP_NOTIFY)
retval = -EAGAIN;
else
retval = -ERESTARTSYS;
#else
retval = -EAGAIN;
#endif
break;
}
if (!(info->port.flags & ASYNC_CLOSING) && do_clocal)
break;
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready blocking: ttyS%d, count = %d\n",
info->line, info->port.count);
#endif
tty_unlock(tty);
schedule();
tty_lock(tty);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&info->port.open_wait, &wait);
if (extra_count)
info->port.count++;
info->port.blocked_open--;
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready after blocking: ttyS%d, count = %d\n",
info->line, info->port.count);
#endif
if (retval)
return retval;
info->port.flags |= ASYNC_NORMAL_ACTIVE;
return 0;
}
static void
deinit_port(struct e100_serial *info)
{
if (info->dma_out_enabled) {
cris_free_dma(info->dma_out_nbr, info->dma_out_irq_description);
free_irq(info->dma_out_irq_nbr, info);
}
if (info->dma_in_enabled) {
cris_free_dma(info->dma_in_nbr, info->dma_in_irq_description);
free_irq(info->dma_in_irq_nbr, info);
}
}
static int
rs_open(struct tty_struct *tty, struct file * filp)
{
struct e100_serial *info;
int retval;
int allocated_resources = 0;
info = rs_table + tty->index;
if (!info->enabled)
return -ENODEV;
#ifdef SERIAL_DEBUG_OPEN
printk("[%d] rs_open %s, count = %d\n", current->pid, tty->name,
info->port.count);
#endif
info->port.count++;
tty->driver_data = info;
info->port.tty = tty;
info->port.low_latency = !!(info->port.flags & ASYNC_LOW_LATENCY);
if (tty_hung_up_p(filp) ||
(info->port.flags & ASYNC_CLOSING)) {
wait_event_interruptible_tty(tty, info->port.close_wait,
!(info->port.flags & ASYNC_CLOSING));
#ifdef SERIAL_DO_RESTART
return ((info->port.flags & ASYNC_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS);
#else
return -EAGAIN;
#endif
}
if (info->port.count == 1) {
allocated_resources = 1;
if (info->dma_in_enabled) {
if (request_irq(info->dma_in_irq_nbr,
rec_interrupt,
info->dma_in_irq_flags,
info->dma_in_irq_description,
info)) {
printk(KERN_WARNING "DMA irq '%s' busy; "
"falling back to non-DMA mode\n",
info->dma_in_irq_description);
info->dma_in_enabled = 0;
} else if (cris_request_dma(info->dma_in_nbr,
info->dma_in_irq_description,
DMA_VERBOSE_ON_ERROR,
info->dma_owner)) {
free_irq(info->dma_in_irq_nbr, info);
printk(KERN_WARNING "DMA '%s' busy; "
"falling back to non-DMA mode\n",
info->dma_in_irq_description);
info->dma_in_enabled = 0;
}
#ifdef SERIAL_DEBUG_OPEN
else
printk(KERN_DEBUG "DMA irq '%s' allocated\n",
info->dma_in_irq_description);
#endif
}
if (info->dma_out_enabled) {
if (request_irq(info->dma_out_irq_nbr,
tr_interrupt,
info->dma_out_irq_flags,
info->dma_out_irq_description,
info)) {
printk(KERN_WARNING "DMA irq '%s' busy; "
"falling back to non-DMA mode\n",
info->dma_out_irq_description);
info->dma_out_enabled = 0;
} else if (cris_request_dma(info->dma_out_nbr,
info->dma_out_irq_description,
DMA_VERBOSE_ON_ERROR,
info->dma_owner)) {
free_irq(info->dma_out_irq_nbr, info);
printk(KERN_WARNING "DMA '%s' busy; "
"falling back to non-DMA mode\n",
info->dma_out_irq_description);
info->dma_out_enabled = 0;
}
#ifdef SERIAL_DEBUG_OPEN
else
printk(KERN_DEBUG "DMA irq '%s' allocated\n",
info->dma_out_irq_description);
#endif
}
}
retval = startup(info);
if (retval) {
if (allocated_resources)
deinit_port(info);
return retval;
}
retval = block_til_ready(tty, filp, info);
if (retval) {
#ifdef SERIAL_DEBUG_OPEN
printk("rs_open returning after block_til_ready with %d\n",
retval);
#endif
if (allocated_resources)
deinit_port(info);
return retval;
}
if ((info->port.count == 1) && (info->port.flags & ASYNC_SPLIT_TERMIOS)) {
tty->termios = info->normal_termios;
change_speed(info);
}
#ifdef SERIAL_DEBUG_OPEN
printk("rs_open ttyS%d successful...\n", info->line);
#endif
DLOG_INT_TRIG( log_int_pos = 0);
DFLIP( if (info->line == SERIAL_DEBUG_LINE) {
info->icount.rx = 0;
} );
return 0;
}
static void seq_line_info(struct seq_file *m, struct e100_serial *info)
{
unsigned long tmp;
seq_printf(m, "%d: uart:E100 port:%lX irq:%d",
info->line, (unsigned long)info->ioport, info->irq);
if (!info->ioport || (info->type == PORT_UNKNOWN)) {
seq_printf(m, "\n");
return;
}
seq_printf(m, " baud:%d", info->baud);
seq_printf(m, " tx:%lu rx:%lu",
(unsigned long)info->icount.tx,
(unsigned long)info->icount.rx);
tmp = CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
if (tmp)
seq_printf(m, " tx_pend:%lu/%lu",
(unsigned long)tmp,
(unsigned long)SERIAL_XMIT_SIZE);
seq_printf(m, " rx_pend:%lu/%lu",
(unsigned long)info->recv_cnt,
(unsigned long)info->max_recv_cnt);
#if 1
if (info->port.tty) {
if (info->port.tty->stopped)
seq_printf(m, " stopped:%i",
(int)info->port.tty->stopped);
}
{
unsigned char rstat = info->ioport[REG_STATUS];
if (rstat & IO_MASK(R_SERIAL0_STATUS, xoff_detect))
seq_printf(m, " xoff_detect:1");
}
#endif
if (info->icount.frame)
seq_printf(m, " fe:%lu", (unsigned long)info->icount.frame);
if (info->icount.parity)
seq_printf(m, " pe:%lu", (unsigned long)info->icount.parity);
if (info->icount.brk)
seq_printf(m, " brk:%lu", (unsigned long)info->icount.brk);
if (info->icount.overrun)
seq_printf(m, " oe:%lu", (unsigned long)info->icount.overrun);
if (!E100_RTS_GET(info))
seq_puts(m, "|RTS");
if (!E100_CTS_GET(info))
seq_puts(m, "|CTS");
if (!E100_DTR_GET(info))
seq_puts(m, "|DTR");
if (!E100_DSR_GET(info))
seq_puts(m, "|DSR");
if (!E100_CD_GET(info))
seq_puts(m, "|CD");
if (!E100_RI_GET(info))
seq_puts(m, "|RI");
seq_puts(m, "\n");
}
static int crisv10_proc_show(struct seq_file *m, void *v)
{
int i;
seq_printf(m, "serinfo:1.0 driver:%s\n", serial_version);
for (i = 0; i < NR_PORTS; i++) {
if (!rs_table[i].enabled)
continue;
seq_line_info(m, &rs_table[i]);
}
#ifdef DEBUG_LOG_INCLUDED
for (i = 0; i < debug_log_pos; i++) {
seq_printf(m, "%-4i %lu.%lu ",
i, debug_log[i].time,
timer_data_to_ns(debug_log[i].timer_data));
seq_printf(m, debug_log[i].string, debug_log[i].value);
}
seq_printf(m, "debug_log %i/%i\n", i, DEBUG_LOG_SIZE);
debug_log_pos = 0;
#endif
return 0;
}
static int crisv10_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, crisv10_proc_show, NULL);
}
static void show_serial_version(void)
{
printk(KERN_INFO
"ETRAX 100LX serial-driver %s, "
"(c) 2000-2004 Axis Communications AB\r\n",
&serial_version[11]);
}
static int __init rs_init(void)
{
int i;
struct e100_serial *info;
struct tty_driver *driver = alloc_tty_driver(NR_PORTS);
if (!driver)
return -ENOMEM;
show_serial_version();
#if !defined(CONFIG_ETRAX_SERIAL_FAST_TIMER)
setup_timer(&flush_timer, timed_flush_handler, 0);
mod_timer(&flush_timer, jiffies + 5);
#endif
#if defined(CONFIG_ETRAX_RS485)
#if defined(CONFIG_ETRAX_RS485_ON_PA)
if (cris_io_interface_allocate_pins(if_serial_0, 'a', rs485_pa_bit,
rs485_pa_bit)) {
printk(KERN_ERR "ETRAX100LX serial: Could not allocate "
"RS485 pin\n");
put_tty_driver(driver);
return -EBUSY;
}
#endif
#if defined(CONFIG_ETRAX_RS485_ON_PORT_G)
if (cris_io_interface_allocate_pins(if_serial_0, 'g', rs485_pa_bit,
rs485_port_g_bit)) {
printk(KERN_ERR "ETRAX100LX serial: Could not allocate "
"RS485 pin\n");
put_tty_driver(driver);
return -EBUSY;
}
#endif
#endif
driver->driver_name = "serial";
driver->name = "ttyS";
driver->major = TTY_MAJOR;
driver->minor_start = 64;
driver->type = TTY_DRIVER_TYPE_SERIAL;
driver->subtype = SERIAL_TYPE_NORMAL;
driver->init_termios = tty_std_termios;
driver->init_termios.c_cflag =
B115200 | CS8 | CREAD | HUPCL | CLOCAL;
driver->init_termios.c_ispeed = 115200;
driver->init_termios.c_ospeed = 115200;
driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(driver, &rs_ops);
serial_driver = driver;
for (i = 0, info = rs_table; i < NR_PORTS; i++,info++) {
if (info->enabled) {
if (cris_request_io_interface(info->io_if,
info->io_if_description)) {
printk(KERN_ERR "ETRAX100LX async serial: "
"Could not allocate IO pins for "
"%s, port %d\n",
info->io_if_description, i);
info->enabled = 0;
}
}
tty_port_init(&info->port);
info->uses_dma_in = 0;
info->uses_dma_out = 0;
info->line = i;
info->port.tty = NULL;
info->type = PORT_ETRAX;
info->tr_running = 0;
info->forced_eop = 0;
info->baud_base = DEF_BAUD_BASE;
info->custom_divisor = 0;
info->x_char = 0;
info->event = 0;
info->normal_termios = driver->init_termios;
info->xmit.buf = NULL;
info->xmit.tail = info->xmit.head = 0;
info->first_recv_buffer = info->last_recv_buffer = NULL;
info->recv_cnt = info->max_recv_cnt = 0;
info->last_tx_active_usec = 0;
info->last_tx_active = 0;
#if defined(CONFIG_ETRAX_RS485)
info->rs485.flags &= ~(SER_RS485_RTS_ON_SEND);
info->rs485.flags |= SER_RS485_RTS_AFTER_SEND;
info->rs485.delay_rts_before_send = 0;
info->rs485.flags &= ~(SER_RS485_ENABLED);
#endif
INIT_WORK(&info->work, do_softint);
if (info->enabled) {
printk(KERN_INFO "%s%d at %p is a builtin UART with DMA\n",
serial_driver->name, info->line, info->ioport);
}
tty_port_link_device(&info->port, driver, i);
}
if (tty_register_driver(driver))
panic("Couldn't register serial driver\n");
#ifdef CONFIG_ETRAX_FAST_TIMER
#ifdef CONFIG_ETRAX_SERIAL_FAST_TIMER
memset(fast_timers, 0, sizeof(fast_timers));
#endif
#ifdef CONFIG_ETRAX_RS485
memset(fast_timers_rs485, 0, sizeof(fast_timers_rs485));
#endif
fast_timer_init();
#endif
#ifndef CONFIG_SVINTO_SIM
#ifndef CONFIG_ETRAX_KGDB
if (request_irq(SERIAL_IRQ_NBR, ser_interrupt,
IRQF_SHARED, "serial ", driver))
panic("%s: Failed to request irq8", __func__);
#endif
#endif
return 0;
}
