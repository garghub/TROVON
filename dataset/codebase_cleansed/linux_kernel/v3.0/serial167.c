void my_udelay(long us)
{
u_char x;
volatile u_char *p = &x;
int i;
while (us--)
for (i = 100; i; i--)
x |= *p;
}
static inline int serial_paranoia_check(struct cyclades_port *info, char *name,
const char *routine)
{
#ifdef SERIAL_PARANOIA_CHECK
if (!info) {
printk("Warning: null cyclades_port for (%s) in %s\n", name,
routine);
return 1;
}
if (info < &cy_port[0] || info >= &cy_port[NR_PORTS]) {
printk("Warning: cyclades_port out of range for (%s) in %s\n",
name, routine);
return 1;
}
if (info->magic != CYCLADES_MAGIC) {
printk("Warning: bad magic number for serial struct (%s) in "
"%s\n", name, routine);
return 1;
}
#endif
return 0;
}
u_short write_cy_cmd(volatile u_char * base_addr, u_char cmd)
{
unsigned long flags;
volatile int i;
local_irq_save(flags);
for (i = 0; i < 100; i++) {
if (base_addr[CyCCR] == 0) {
break;
}
my_udelay(10L);
}
if (i == 10) {
local_irq_restore(flags);
return (-1);
}
base_addr[CyCCR] = cmd;
local_irq_restore(flags);
return (0);
}
static void cy_stop(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
unsigned long flags;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_stop %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_stop"))
return;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) (channel);
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
local_irq_restore(flags);
}
static void cy_start(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
unsigned long flags;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_start %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_start"))
return;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) (channel);
base_addr[CyIER] |= CyTxMpty;
local_irq_restore(flags);
}
static irqreturn_t cd2401_rxerr_interrupt(int irq, void *dev_id)
{
struct tty_struct *tty;
struct cyclades_port *info;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
unsigned char err, rfoc;
int channel;
char data;
channel = (u_short) (base_addr[CyLICR] >> 2);
info = &cy_port[channel];
info->last_active = jiffies;
if ((err = base_addr[CyRISR]) & CyTIMEOUT) {
base_addr[CyREOIR] = CyNOTRANS;
return IRQ_HANDLED;
}
if ((rfoc = base_addr[CyRFOC]) != 0)
data = base_addr[CyRDR];
else
data = 0;
if (info->tty == 0) {
base_addr[CyREOIR] = rfoc ? 0 : CyNOTRANS;
return IRQ_HANDLED;
} else {
tty = info->tty;
if (err & info->ignore_status_mask) {
base_addr[CyREOIR] = rfoc ? 0 : CyNOTRANS;
return IRQ_HANDLED;
}
if (tty_buffer_request_room(tty, 1) != 0) {
if (err & info->read_status_mask) {
if (err & CyBREAK) {
tty_insert_flip_char(tty, data,
TTY_BREAK);
if (info->flags & ASYNC_SAK) {
do_SAK(tty);
}
} else if (err & CyFRAME) {
tty_insert_flip_char(tty, data,
TTY_FRAME);
} else if (err & CyPARITY) {
tty_insert_flip_char(tty, data,
TTY_PARITY);
} else if (err & CyOVERRUN) {
tty_insert_flip_char(tty, 0,
TTY_OVERRUN);
if (tty_buffer_request_room(tty, 1) !=
0) {
tty_insert_flip_char(tty, data,
TTY_FRAME);
}
} else {
tty_insert_flip_char(tty, 0,
TTY_NORMAL);
}
} else {
tty_insert_flip_char(tty, data, TTY_NORMAL);
}
} else {
}
}
tty_schedule_flip(tty);
base_addr[CyREOIR] = rfoc ? 0 : CyNOTRANS;
return IRQ_HANDLED;
}
static irqreturn_t cd2401_modem_interrupt(int irq, void *dev_id)
{
struct cyclades_port *info;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
int mdm_change;
int mdm_status;
channel = (u_short) (base_addr[CyLICR] >> 2);
info = &cy_port[channel];
info->last_active = jiffies;
mdm_change = base_addr[CyMISR];
mdm_status = base_addr[CyMSVR1];
if (info->tty == 0) {
;
} else {
if ((mdm_change & CyDCD)
&& (info->flags & ASYNC_CHECK_CD)) {
if (mdm_status & CyDCD) {
wake_up_interruptible(&info->open_wait);
} else {
tty_hangup(info->tty);
wake_up_interruptible(&info->open_wait);
info->flags &= ~ASYNC_NORMAL_ACTIVE;
}
}
if ((mdm_change & CyCTS)
&& (info->flags & ASYNC_CTS_FLOW)) {
if (info->tty->stopped) {
if (mdm_status & CyCTS) {
info->tty->stopped = 0;
base_addr[CyIER] |= CyTxMpty;
tty_wakeup(info->tty);
}
} else {
if (!(mdm_status & CyCTS)) {
info->tty->stopped = 1;
base_addr[CyIER] &=
~(CyTxMpty | CyTxRdy);
}
}
}
if (mdm_status & CyDSR) {
}
}
base_addr[CyMEOIR] = 0;
return IRQ_HANDLED;
}
static irqreturn_t cd2401_tx_interrupt(int irq, void *dev_id)
{
struct cyclades_port *info;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
int char_count, saved_cnt;
int outch;
channel = (u_short) (base_addr[CyLICR] >> 2);
if ((channel < 0) || (NR_PORTS <= channel)) {
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
base_addr[CyTEOIR] = CyNOTRANS;
return IRQ_HANDLED;
}
info = &cy_port[channel];
info->last_active = jiffies;
if (info->tty == 0) {
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
base_addr[CyTEOIR] = CyNOTRANS;
return IRQ_HANDLED;
}
saved_cnt = char_count = base_addr[CyTFTC];
if (info->x_char) {
outch = info->x_char;
base_addr[CyTDR] = outch;
char_count--;
info->x_char = 0;
}
if (info->x_break) {
base_addr[CyTDR] = 0;
base_addr[CyTDR] = 0x81;
base_addr[CyTDR] = 0;
base_addr[CyTDR] = 0x82;
base_addr[CyTDR] = info->x_break * 200 / HZ;
base_addr[CyTDR] = 0;
base_addr[CyTDR] = 0x83;
char_count -= 7;
info->x_break = 0;
}
while (char_count > 0) {
if (!info->xmit_cnt) {
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
break;
}
if (info->xmit_buf == 0) {
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
break;
}
if (info->tty->stopped || info->tty->hw_stopped) {
base_addr[CyIER] &= ~(CyTxMpty | CyTxRdy);
break;
}
outch = info->xmit_buf[info->xmit_tail];
if (outch) {
info->xmit_cnt--;
info->xmit_tail = (info->xmit_tail + 1)
& (PAGE_SIZE - 1);
base_addr[CyTDR] = outch;
char_count--;
} else {
if (char_count > 1) {
info->xmit_cnt--;
info->xmit_tail = (info->xmit_tail + 1)
& (PAGE_SIZE - 1);
base_addr[CyTDR] = outch;
base_addr[CyTDR] = 0;
char_count--;
char_count--;
} else {
break;
}
}
}
if (info->xmit_cnt < WAKEUP_CHARS)
tty_wakeup(info->tty);
base_addr[CyTEOIR] = (char_count != saved_cnt) ? 0 : CyNOTRANS;
return IRQ_HANDLED;
}
static irqreturn_t cd2401_rx_interrupt(int irq, void *dev_id)
{
struct tty_struct *tty;
struct cyclades_port *info;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
char data;
int char_count;
int save_cnt;
channel = (u_short) (base_addr[CyLICR] >> 2);
info = &cy_port[channel];
info->last_active = jiffies;
save_cnt = char_count = base_addr[CyRFOC];
if (info->tty == 0) {
while (char_count--) {
data = base_addr[CyRDR];
}
} else {
tty = info->tty;
#ifdef CYCLOM_ENABLE_MONITORING
++info->mon.int_count;
info->mon.char_count += char_count;
if (char_count > info->mon.char_max)
info->mon.char_max = char_count;
info->mon.char_last = char_count;
#endif
while (char_count--) {
data = base_addr[CyRDR];
tty_insert_flip_char(tty, data, TTY_NORMAL);
#ifdef CYCLOM_16Y_HACK
udelay(10L);
#endif
}
tty_schedule_flip(tty);
}
base_addr[CyREOIR] = save_cnt ? 0 : CyNOTRANS;
return IRQ_HANDLED;
}
static int startup(struct cyclades_port *info)
{
unsigned long flags;
volatile unsigned char *base_addr = (unsigned char *)BASE_ADDR;
int channel;
if (info->flags & ASYNC_INITIALIZED) {
return 0;
}
if (!info->type) {
if (info->tty) {
set_bit(TTY_IO_ERROR, &info->tty->flags);
}
return 0;
}
if (!info->xmit_buf) {
info->xmit_buf = (unsigned char *)get_zeroed_page(GFP_KERNEL);
if (!info->xmit_buf) {
return -ENOMEM;
}
}
config_setup(info);
channel = info->line;
#ifdef SERIAL_DEBUG_OPEN
printk("startup channel %d\n", channel);
#endif
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
write_cy_cmd(base_addr, CyENB_RCVR | CyENB_XMTR);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = CyRTS;
base_addr[CyMSVR2] = CyDTR;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: raising DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
base_addr[CyIER] |= CyRxData;
info->flags |= ASYNC_INITIALIZED;
if (info->tty) {
clear_bit(TTY_IO_ERROR, &info->tty->flags);
}
info->xmit_cnt = info->xmit_head = info->xmit_tail = 0;
local_irq_restore(flags);
#ifdef SERIAL_DEBUG_OPEN
printk(" done\n");
#endif
return 0;
}
void start_xmit(struct cyclades_port *info)
{
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = channel;
base_addr[CyIER] |= CyTxMpty;
local_irq_restore(flags);
}
static void shutdown(struct cyclades_port *info)
{
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
if (!(info->flags & ASYNC_INITIALIZED)) {
return;
}
channel = info->line;
#ifdef SERIAL_DEBUG_OPEN
printk("shutdown channel %d\n", channel);
#endif
local_irq_save(flags);
if (info->xmit_buf) {
free_page((unsigned long)info->xmit_buf);
info->xmit_buf = NULL;
}
base_addr[CyCAR] = (u_char) channel;
if (!info->tty || (info->tty->termios->c_cflag & HUPCL)) {
base_addr[CyMSVR1] = 0;
base_addr[CyMSVR2] = 0;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: dropping DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
}
write_cy_cmd(base_addr, CyDIS_RCVR);
if (info->tty) {
set_bit(TTY_IO_ERROR, &info->tty->flags);
}
info->flags &= ~ASYNC_INITIALIZED;
local_irq_restore(flags);
#ifdef SERIAL_DEBUG_OPEN
printk(" done\n");
#endif
}
static void config_setup(struct cyclades_port *info)
{
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
unsigned cflag;
int i;
unsigned char ti, need_init_chan = 0;
if (!info->tty || !info->tty->termios) {
return;
}
if (info->line == -1) {
return;
}
cflag = info->tty->termios->c_cflag;
i = cflag & CBAUD;
#ifdef CBAUDEX
if (i & CBAUDEX) {
if (i == B57600)
i = 16;
else if (i == B115200)
i = 18;
#ifdef B78600
else if (i == B78600)
i = 17;
#endif
else
info->tty->termios->c_cflag &= ~CBAUDEX;
}
#endif
if (i == 15) {
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
i += 1;
if ((info->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
i += 3;
}
if (info != serial_console_info) {
info->tbpr = baud_bpr[i];
info->tco = baud_co[i];
info->rbpr = baud_bpr[i];
info->rco = baud_co[i] >> 5;
if (baud_table[i] == 134) {
info->timeout =
(info->xmit_fifo_size * HZ * 30 / 269) + 2;
} else if (baud_table[i]) {
info->timeout =
(info->xmit_fifo_size * HZ * 15 / baud_table[i]) +
2;
} else {
info->timeout = 0;
}
}
info->cor7 = 0;
info->cor6 = 0;
info->cor5 = 0;
info->cor4 = (info->default_threshold ? info->default_threshold : baud_cor4[i]);
channel = info->line;
base_addr[CyCAR] = (u_char) channel;
if (C_CLOCAL(info->tty)) {
if (base_addr[CyIER] & CyMdmCh)
base_addr[CyIER] &= ~CyMdmCh;
if (base_addr[CyCOR4] & (CyDSR | CyCTS | CyDCD))
base_addr[CyCOR4] &= ~(CyDSR | CyCTS | CyDCD);
if (base_addr[CyCOR5] & (CyDSR | CyCTS | CyDCD))
base_addr[CyCOR5] &= ~(CyDSR | CyCTS | CyDCD);
} else {
if ((base_addr[CyIER] & CyMdmCh) != CyMdmCh)
base_addr[CyIER] |= CyMdmCh;
if ((base_addr[CyCOR4] & (CyDSR | CyCTS | CyDCD)) !=
(CyDSR | CyCTS | CyDCD))
base_addr[CyCOR4] |= CyDSR | CyCTS | CyDCD;
if ((base_addr[CyCOR5] & (CyDSR | CyCTS | CyDCD)) !=
(CyDSR | CyCTS | CyDCD))
base_addr[CyCOR5] |= CyDSR | CyCTS | CyDCD;
}
info->cor3 = (cflag & CSTOPB) ? Cy_2_STOP : Cy_1_STOP;
info->cor2 = CyETC;
switch (cflag & CSIZE) {
case CS5:
info->cor1 = Cy_5_BITS;
break;
case CS6:
info->cor1 = Cy_6_BITS;
break;
case CS7:
info->cor1 = Cy_7_BITS;
break;
case CS8:
info->cor1 = Cy_8_BITS;
break;
}
if (cflag & PARENB) {
if (cflag & PARODD) {
info->cor1 |= CyPARITY_O;
} else {
info->cor1 |= CyPARITY_E;
}
} else {
info->cor1 |= CyPARITY_NONE;
}
#if 0
if (cflag & CRTSCTS) {
info->flags |= ASYNC_CTS_FLOW;
info->cor2 |= CyCtsAE;
} else {
info->flags &= ~ASYNC_CTS_FLOW;
info->cor2 &= ~CyCtsAE;
}
#endif
if (cflag & CLOCAL)
info->flags &= ~ASYNC_CHECK_CD;
else
info->flags |= ASYNC_CHECK_CD;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
if (base_addr[CyLICR] != channel << 2)
base_addr[CyLICR] = channel << 2;
if (base_addr[CyLIVR] != 0x5c)
base_addr[CyLIVR] = 0x5c;
if (base_addr[CyCOR1] != info->cor1)
need_init_chan = 1;
if (base_addr[CyTCOR] != info->tco)
base_addr[CyTCOR] = info->tco;
if (base_addr[CyTBPR] != info->tbpr)
base_addr[CyTBPR] = info->tbpr;
if (base_addr[CyRCOR] != info->rco)
base_addr[CyRCOR] = info->rco;
if (base_addr[CyRBPR] != info->rbpr)
base_addr[CyRBPR] = info->rbpr;
if (base_addr[CySCHR1] != START_CHAR(info->tty))
base_addr[CySCHR1] = START_CHAR(info->tty);
if (base_addr[CySCHR2] != STOP_CHAR(info->tty))
base_addr[CySCHR2] = STOP_CHAR(info->tty);
if (base_addr[CySCRL] != START_CHAR(info->tty))
base_addr[CySCRL] = START_CHAR(info->tty);
if (base_addr[CySCRH] != START_CHAR(info->tty))
base_addr[CySCRH] = START_CHAR(info->tty);
if (base_addr[CyCOR1] != info->cor1)
base_addr[CyCOR1] = info->cor1;
if (base_addr[CyCOR2] != info->cor2)
base_addr[CyCOR2] = info->cor2;
if (base_addr[CyCOR3] != info->cor3)
base_addr[CyCOR3] = info->cor3;
if (base_addr[CyCOR4] != info->cor4)
base_addr[CyCOR4] = info->cor4;
if (base_addr[CyCOR5] != info->cor5)
base_addr[CyCOR5] = info->cor5;
if (base_addr[CyCOR6] != info->cor6)
base_addr[CyCOR6] = info->cor6;
if (base_addr[CyCOR7] != info->cor7)
base_addr[CyCOR7] = info->cor7;
if (need_init_chan)
write_cy_cmd(base_addr, CyINIT_CHAN);
base_addr[CyCAR] = (u_char) channel;
ti = info->default_timeout ? info->default_timeout : 0x02;
if (base_addr[CyRTPRL] != ti)
base_addr[CyRTPRL] = ti;
if (base_addr[CyRTPRH] != 0)
base_addr[CyRTPRH] = 0;
if (i == 0) {
if ((base_addr[CyMSVR2] & CyDTR) == CyDTR)
base_addr[CyMSVR2] = 0;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: dropping DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
} else {
if ((base_addr[CyMSVR2] & CyDTR) != CyDTR)
base_addr[CyMSVR2] = CyDTR;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: raising DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
}
if (info->tty) {
clear_bit(TTY_IO_ERROR, &info->tty->flags);
}
local_irq_restore(flags);
}
static int cy_put_char(struct tty_struct *tty, unsigned char ch)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
#ifdef SERIAL_DEBUG_IO
printk("cy_put_char %s(0x%02x)\n", tty->name, ch);
#endif
if (serial_paranoia_check(info, tty->name, "cy_put_char"))
return 0;
if (!info->xmit_buf)
return 0;
local_irq_save(flags);
if (info->xmit_cnt >= PAGE_SIZE - 1) {
local_irq_restore(flags);
return 0;
}
info->xmit_buf[info->xmit_head++] = ch;
info->xmit_head &= PAGE_SIZE - 1;
info->xmit_cnt++;
local_irq_restore(flags);
return 1;
}
static void cy_flush_chars(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
#ifdef SERIAL_DEBUG_IO
printk("cy_flush_chars %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_flush_chars"))
return;
if (info->xmit_cnt <= 0 || tty->stopped
|| tty->hw_stopped || !info->xmit_buf)
return;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = channel;
base_addr[CyIER] |= CyTxMpty;
local_irq_restore(flags);
}
static int cy_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
int c, total = 0;
#ifdef SERIAL_DEBUG_IO
printk("cy_write %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_write")) {
return 0;
}
if (!info->xmit_buf) {
return 0;
}
while (1) {
local_irq_save(flags);
c = min_t(int, count, min(SERIAL_XMIT_SIZE - info->xmit_cnt - 1,
SERIAL_XMIT_SIZE - info->xmit_head));
if (c <= 0) {
local_irq_restore(flags);
break;
}
memcpy(info->xmit_buf + info->xmit_head, buf, c);
info->xmit_head =
(info->xmit_head + c) & (SERIAL_XMIT_SIZE - 1);
info->xmit_cnt += c;
local_irq_restore(flags);
buf += c;
count -= c;
total += c;
}
if (info->xmit_cnt && !tty->stopped && !tty->hw_stopped) {
start_xmit(info);
}
return total;
}
static int cy_write_room(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
int ret;
#ifdef SERIAL_DEBUG_IO
printk("cy_write_room %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_write_room"))
return 0;
ret = PAGE_SIZE - info->xmit_cnt - 1;
if (ret < 0)
ret = 0;
return ret;
}
static int cy_chars_in_buffer(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
#ifdef SERIAL_DEBUG_IO
printk("cy_chars_in_buffer %s %d\n", tty->name, info->xmit_cnt);
#endif
if (serial_paranoia_check(info, tty->name, "cy_chars_in_buffer"))
return 0;
return info->xmit_cnt;
}
static void cy_flush_buffer(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
#ifdef SERIAL_DEBUG_IO
printk("cy_flush_buffer %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_flush_buffer"))
return;
local_irq_save(flags);
info->xmit_cnt = info->xmit_head = info->xmit_tail = 0;
local_irq_restore(flags);
tty_wakeup(tty);
}
static void cy_throttle(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
#ifdef SERIAL_DEBUG_THROTTLE
char buf[64];
printk("throttle %s: %d....\n", tty_name(tty, buf),
tty->ldisc.chars_in_buffer(tty));
printk("cy_throttle %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_nthrottle")) {
return;
}
if (I_IXOFF(tty)) {
info->x_char = STOP_CHAR(tty);
}
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = 0;
local_irq_restore(flags);
}
static void cy_unthrottle(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
unsigned long flags;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
#ifdef SERIAL_DEBUG_THROTTLE
char buf[64];
printk("throttle %s: %d....\n", tty_name(tty, buf),
tty->ldisc.chars_in_buffer(tty));
printk("cy_unthrottle %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_nthrottle")) {
return;
}
if (I_IXOFF(tty)) {
info->x_char = START_CHAR(tty);
}
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = CyRTS;
local_irq_restore(flags);
}
static int
get_serial_info(struct cyclades_port *info,
struct serial_struct __user * retinfo)
{
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tmp.type = info->type;
tmp.line = info->line;
tmp.port = info->line;
tmp.irq = 0;
tmp.flags = info->flags;
tmp.baud_base = 0;
tmp.close_delay = info->close_delay;
tmp.custom_divisor = 0;
tmp.hub6 = 0;
return copy_to_user(retinfo, &tmp, sizeof(*retinfo)) ? -EFAULT : 0;
}
static int
set_serial_info(struct cyclades_port *info,
struct serial_struct __user * new_info)
{
struct serial_struct new_serial;
struct cyclades_port old_info;
if (!new_info)
return -EFAULT;
if (copy_from_user(&new_serial, new_info, sizeof(new_serial)))
return -EFAULT;
old_info = *info;
if (!capable(CAP_SYS_ADMIN)) {
if ((new_serial.close_delay != info->close_delay) ||
((new_serial.flags & ASYNC_FLAGS & ~ASYNC_USR_MASK) !=
(info->flags & ASYNC_FLAGS & ~ASYNC_USR_MASK)))
return -EPERM;
info->flags = ((info->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
goto check_and_exit;
}
info->flags = ((info->flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
info->close_delay = new_serial.close_delay;
check_and_exit:
if (info->flags & ASYNC_INITIALIZED) {
config_setup(info);
return 0;
}
return startup(info);
}
static int cy_tiocmget(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
int channel;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
unsigned long flags;
unsigned char status;
channel = info->line;
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
status = base_addr[CyMSVR1] | base_addr[CyMSVR2];
local_irq_restore(flags);
return ((status & CyRTS) ? TIOCM_RTS : 0)
| ((status & CyDTR) ? TIOCM_DTR : 0)
| ((status & CyDCD) ? TIOCM_CAR : 0)
| ((status & CyDSR) ? TIOCM_DSR : 0)
| ((status & CyCTS) ? TIOCM_CTS : 0);
}
static int
cy_tiocmset(struct tty_struct *tty, unsigned int set, unsigned int clear)
{
struct cyclades_port *info = tty->driver_data;
int channel;
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
unsigned long flags;
channel = info->line;
if (set & TIOCM_RTS) {
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = CyRTS;
local_irq_restore(flags);
}
if (set & TIOCM_DTR) {
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR2] = CyDTR;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: raising DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
local_irq_restore(flags);
}
if (clear & TIOCM_RTS) {
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = 0;
local_irq_restore(flags);
}
if (clear & TIOCM_DTR) {
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR2] = 0;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: dropping DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
local_irq_restore(flags);
}
return 0;
}
static void send_break(struct cyclades_port *info, int duration)
{
info->x_break = duration;
if (!info->xmit_cnt) {
start_xmit(info);
}
}
static int
get_mon_info(struct cyclades_port *info, struct cyclades_monitor __user * mon)
{
if (copy_to_user(mon, &info->mon, sizeof(struct cyclades_monitor)))
return -EFAULT;
info->mon.int_count = 0;
info->mon.char_count = 0;
info->mon.char_max = 0;
info->mon.char_last = 0;
return 0;
}
static int set_threshold(struct cyclades_port *info, unsigned long __user * arg)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
unsigned long value;
int channel;
if (get_user(value, arg))
return -EFAULT;
channel = info->line;
info->cor4 &= ~CyREC_FIFO;
info->cor4 |= value & CyREC_FIFO;
base_addr[CyCOR4] = info->cor4;
return 0;
}
static int
get_threshold(struct cyclades_port *info, unsigned long __user * value)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
unsigned long tmp;
channel = info->line;
tmp = base_addr[CyCOR4] & CyREC_FIFO;
return put_user(tmp, value);
}
static int
set_default_threshold(struct cyclades_port *info, unsigned long __user * arg)
{
unsigned long value;
if (get_user(value, arg))
return -EFAULT;
info->default_threshold = value & 0x0f;
return 0;
}
static int
get_default_threshold(struct cyclades_port *info, unsigned long __user * value)
{
return put_user(info->default_threshold, value);
}
static int set_timeout(struct cyclades_port *info, unsigned long __user * arg)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
unsigned long value;
if (get_user(value, arg))
return -EFAULT;
channel = info->line;
base_addr[CyRTPRL] = value & 0xff;
base_addr[CyRTPRH] = (value >> 8) & 0xff;
return 0;
}
static int get_timeout(struct cyclades_port *info, unsigned long __user * value)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
unsigned long tmp;
channel = info->line;
tmp = base_addr[CyRTPRL];
return put_user(tmp, value);
}
static int set_default_timeout(struct cyclades_port *info, unsigned long value)
{
info->default_timeout = value & 0xff;
return 0;
}
static int
get_default_timeout(struct cyclades_port *info, unsigned long __user * value)
{
return put_user(info->default_timeout, value);
}
static int
cy_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct cyclades_port *info = tty->driver_data;
int ret_val = 0;
void __user *argp = (void __user *)arg;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_ioctl %s, cmd = %x arg = %lx\n", tty->name, cmd, arg);
#endif
tty_lock();
switch (cmd) {
case CYGETMON:
ret_val = get_mon_info(info, argp);
break;
case CYGETTHRESH:
ret_val = get_threshold(info, argp);
break;
case CYSETTHRESH:
ret_val = set_threshold(info, argp);
break;
case CYGETDEFTHRESH:
ret_val = get_default_threshold(info, argp);
break;
case CYSETDEFTHRESH:
ret_val = set_default_threshold(info, argp);
break;
case CYGETTIMEOUT:
ret_val = get_timeout(info, argp);
break;
case CYSETTIMEOUT:
ret_val = set_timeout(info, argp);
break;
case CYGETDEFTIMEOUT:
ret_val = get_default_timeout(info, argp);
break;
case CYSETDEFTIMEOUT:
ret_val = set_default_timeout(info, (unsigned long)arg);
break;
case TCSBRK:
ret_val = tty_check_change(tty);
if (ret_val)
break;
tty_wait_until_sent(tty, 0);
if (!arg)
send_break(info, HZ / 4);
break;
case TCSBRKP:
ret_val = tty_check_change(tty);
if (ret_val)
break;
tty_wait_until_sent(tty, 0);
send_break(info, arg ? arg * (HZ / 10) : HZ / 4);
break;
case TIOCGSERIAL:
ret_val = get_serial_info(info, argp);
break;
case TIOCSSERIAL:
ret_val = set_serial_info(info, argp);
break;
default:
ret_val = -ENOIOCTLCMD;
}
tty_unlock();
#ifdef SERIAL_DEBUG_OTHER
printk("cy_ioctl done\n");
#endif
return ret_val;
}
static void cy_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct cyclades_port *info = tty->driver_data;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_set_termios %s\n", tty->name);
#endif
if (tty->termios->c_cflag == old_termios->c_cflag)
return;
config_setup(info);
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios->c_cflag & CRTSCTS)) {
tty->stopped = 0;
cy_start(tty);
}
#ifdef tytso_patch_94Nov25_1726
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios->c_cflag & CLOCAL))
wake_up_interruptible(&info->open_wait);
#endif
}
static void cy_close(struct tty_struct *tty, struct file *filp)
{
struct cyclades_port *info = tty->driver_data;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_close %s\n", tty->name);
#endif
if (!info || serial_paranoia_check(info, tty->name, "cy_close")) {
return;
}
#ifdef SERIAL_DEBUG_OPEN
printk("cy_close %s, count = %d\n", tty->name, info->count);
#endif
if ((tty->count == 1) && (info->count != 1)) {
printk("cy_close: bad serial port count; tty->count is 1, "
"info->count is %d\n", info->count);
info->count = 1;
}
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: decrementing count to %d\n", __LINE__,
info->count - 1);
#endif
if (--info->count < 0) {
printk("cy_close: bad serial port count for ttys%d: %d\n",
info->line, info->count);
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: setting count to 0\n", __LINE__);
#endif
info->count = 0;
}
if (info->count)
return;
info->flags |= ASYNC_CLOSING;
if (info->flags & ASYNC_INITIALIZED)
tty_wait_until_sent(tty, 3000);
shutdown(info);
cy_flush_buffer(tty);
tty_ldisc_flush(tty);
info->tty = NULL;
if (info->blocked_open) {
if (info->close_delay) {
msleep_interruptible(jiffies_to_msecs
(info->close_delay));
}
wake_up_interruptible(&info->open_wait);
}
info->flags &= ~(ASYNC_NORMAL_ACTIVE | ASYNC_CLOSING);
wake_up_interruptible(&info->close_wait);
#ifdef SERIAL_DEBUG_OTHER
printk("cy_close done\n");
#endif
}
void cy_hangup(struct tty_struct *tty)
{
struct cyclades_port *info = tty->driver_data;
#ifdef SERIAL_DEBUG_OTHER
printk("cy_hangup %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_hangup"))
return;
shutdown(info);
#if 0
info->event = 0;
info->count = 0;
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: setting count to 0\n", __LINE__);
#endif
info->tty = 0;
#endif
info->flags &= ~ASYNC_NORMAL_ACTIVE;
wake_up_interruptible(&info->open_wait);
}
static int
block_til_ready(struct tty_struct *tty, struct file *filp,
struct cyclades_port *info)
{
DECLARE_WAITQUEUE(wait, current);
unsigned long flags;
int channel;
int retval;
volatile u_char *base_addr = (u_char *) BASE_ADDR;
if (info->flags & ASYNC_CLOSING) {
interruptible_sleep_on(&info->close_wait);
if (info->flags & ASYNC_HUP_NOTIFY) {
return -EAGAIN;
} else {
return -ERESTARTSYS;
}
}
if (filp->f_flags & O_NONBLOCK) {
info->flags |= ASYNC_NORMAL_ACTIVE;
return 0;
}
retval = 0;
add_wait_queue(&info->open_wait, &wait);
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready before block: %s, count = %d\n",
tty->name, info->count);
#endif
info->count--;
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: decrementing count to %d\n", __LINE__, info->count);
#endif
info->blocked_open++;
channel = info->line;
while (1) {
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
base_addr[CyMSVR1] = CyRTS;
base_addr[CyMSVR2] = CyDTR;
#ifdef SERIAL_DEBUG_DTR
printk("cyc: %d: raising DTR\n", __LINE__);
printk(" status: 0x%x, 0x%x\n", base_addr[CyMSVR1],
base_addr[CyMSVR2]);
#endif
local_irq_restore(flags);
set_current_state(TASK_INTERRUPTIBLE);
if (tty_hung_up_p(filp)
|| !(info->flags & ASYNC_INITIALIZED)) {
if (info->flags & ASYNC_HUP_NOTIFY) {
retval = -EAGAIN;
} else {
retval = -ERESTARTSYS;
}
break;
}
local_irq_save(flags);
base_addr[CyCAR] = (u_char) channel;
if (!(info->flags & ASYNC_CLOSING)
&& (C_CLOCAL(tty)
|| (base_addr[CyMSVR1] & CyDCD))) {
local_irq_restore(flags);
break;
}
local_irq_restore(flags);
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready blocking: %s, count = %d\n",
tty->name, info->count);
#endif
tty_unlock();
schedule();
tty_lock();
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(&info->open_wait, &wait);
if (!tty_hung_up_p(filp)) {
info->count++;
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: incrementing count to %d\n", __LINE__,
info->count);
#endif
}
info->blocked_open--;
#ifdef SERIAL_DEBUG_OPEN
printk("block_til_ready after blocking: %s, count = %d\n",
tty->name, info->count);
#endif
if (retval)
return retval;
info->flags |= ASYNC_NORMAL_ACTIVE;
return 0;
}
int cy_open(struct tty_struct *tty, struct file *filp)
{
struct cyclades_port *info;
int retval, line;
line = tty->index;
if ((line < 0) || (NR_PORTS <= line)) {
return -ENODEV;
}
info = &cy_port[line];
if (info->line < 0) {
return -ENODEV;
}
#ifdef SERIAL_DEBUG_OTHER
printk("cy_open %s\n", tty->name);
#endif
if (serial_paranoia_check(info, tty->name, "cy_open")) {
return -ENODEV;
}
#ifdef SERIAL_DEBUG_OPEN
printk("cy_open %s, count = %d\n", tty->name, info->count);
#endif
info->count++;
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: incrementing count to %d\n", __LINE__, info->count);
#endif
tty->driver_data = info;
info->tty = tty;
retval = startup(info);
if (retval) {
return retval;
}
retval = block_til_ready(tty, filp, info);
if (retval) {
#ifdef SERIAL_DEBUG_OPEN
printk("cy_open returning after block_til_ready with %d\n",
retval);
#endif
return retval;
}
#ifdef SERIAL_DEBUG_OPEN
printk("cy_open done\n");
#endif
return 0;
}
static void show_version(void)
{
printk("MVME166/167 cd2401 driver\n");
}
void mvme167_serial_console_setup(int cflag)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int ch;
u_char spd;
u_char rcor, rbpr, badspeed = 0;
unsigned long flags;
local_irq_save(flags);
base_addr[CyCAR] = 0;
rcor = base_addr[CyRCOR] << 5;
rbpr = base_addr[CyRBPR];
for (spd = 0; spd < sizeof(baud_bpr); spd++)
if (rbpr == baud_bpr[spd] && rcor == baud_co[spd])
break;
if (spd >= sizeof(baud_bpr)) {
spd = 14;
badspeed = 1;
}
initial_console_speed = spd;
my_udelay(20000L);
if (base_addr[CyCCR] != 0x00) {
local_irq_restore(flags);
return;
}
base_addr[CyCCR] = CyCHIP_RESET;
my_udelay(1000L);
if (base_addr[CyGFRCR] == 0x00) {
local_irq_restore(flags);
return;
}
base_addr[CyTPR] = 10;
base_addr[CyPILR1] = 0x01;
base_addr[CyPILR2] = 0x02;
base_addr[CyPILR3] = 0x03;
for (ch = 3; ch >= 0; ch--) {
base_addr[CyCAR] = (u_char) ch;
base_addr[CyIER] = 0;
base_addr[CyCMR] = CyASYNC;
base_addr[CyLICR] = (u_char) ch << 2;
base_addr[CyLIVR] = 0x5c;
base_addr[CyTCOR] = baud_co[spd];
base_addr[CyTBPR] = baud_bpr[spd];
base_addr[CyRCOR] = baud_co[spd] >> 5;
base_addr[CyRBPR] = baud_bpr[spd];
base_addr[CySCHR1] = 'Q' & 0x1f;
base_addr[CySCHR2] = 'X' & 0x1f;
base_addr[CySCRL] = 0;
base_addr[CySCRH] = 0;
base_addr[CyCOR1] = Cy_8_BITS | CyPARITY_NONE;
base_addr[CyCOR2] = 0;
base_addr[CyCOR3] = Cy_1_STOP;
base_addr[CyCOR4] = baud_cor4[spd];
base_addr[CyCOR5] = 0;
base_addr[CyCOR6] = 0;
base_addr[CyCOR7] = 0;
base_addr[CyRTPRL] = 2;
base_addr[CyRTPRH] = 0;
base_addr[CyMSVR1] = 0;
base_addr[CyMSVR2] = 0;
write_cy_cmd(base_addr, CyINIT_CHAN | CyDIS_RCVR | CyDIS_XMTR);
}
base_addr[CyMSVR1] = CyRTS;
base_addr[CyMSVR2] = CyDTR;
base_addr[CyIER] = CyRxData;
write_cy_cmd(base_addr, CyENB_RCVR | CyENB_XMTR);
local_irq_restore(flags);
my_udelay(20000L);
printk("CD2401 initialised, chip is rev 0x%02x\n", base_addr[CyGFRCR]);
if (badspeed)
printk
(" WARNING: Failed to identify line speed, rcor=%02x,rbpr=%02x\n",
rcor >> 5, rbpr);
}
static int __init serial167_init(void)
{
struct cyclades_port *info;
int ret = 0;
int good_ports = 0;
int port_num = 0;
int index;
int DefSpeed;
#ifdef notyet
struct sigaction sa;
#endif
if (!(mvme16x_config & MVME16x_CONFIG_GOT_CD2401))
return 0;
cy_serial_driver = alloc_tty_driver(NR_PORTS);
if (!cy_serial_driver)
return -ENOMEM;
#if 0
scrn[1] = '\0';
#endif
show_version();
if (serial_console_cflag)
DefSpeed = serial_console_cflag & 0017;
else {
DefSpeed = initial_console_speed;
serial_console_info = &cy_port[0];
serial_console_cflag = DefSpeed | CS8;
#if 0
serial_console = 64;
#endif
}
cy_serial_driver->owner = THIS_MODULE;
cy_serial_driver->name = "ttyS";
cy_serial_driver->major = TTY_MAJOR;
cy_serial_driver->minor_start = 64;
cy_serial_driver->type = TTY_DRIVER_TYPE_SERIAL;
cy_serial_driver->subtype = SERIAL_TYPE_NORMAL;
cy_serial_driver->init_termios = tty_std_termios;
cy_serial_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
cy_serial_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(cy_serial_driver, &cy_ops);
ret = tty_register_driver(cy_serial_driver);
if (ret) {
printk(KERN_ERR "Couldn't register MVME166/7 serial driver\n");
put_tty_driver(cy_serial_driver);
return ret;
}
port_num = 0;
info = cy_port;
for (index = 0; index < 1; index++) {
good_ports = 4;
if (port_num < NR_PORTS) {
while (good_ports-- && port_num < NR_PORTS) {
info->magic = CYCLADES_MAGIC;
info->type = PORT_CIRRUS;
info->card = index;
info->line = port_num;
info->flags = STD_COM_FLAGS;
info->tty = NULL;
info->xmit_fifo_size = 12;
info->cor1 = CyPARITY_NONE | Cy_8_BITS;
info->cor2 = CyETC;
info->cor3 = Cy_1_STOP;
info->cor4 = 0x08;
info->cor5 = 0;
info->cor6 = 0;
info->cor7 = 0;
info->tbpr = baud_bpr[DefSpeed];
info->tco = baud_co[DefSpeed];
info->rbpr = baud_bpr[DefSpeed];
info->rco = baud_co[DefSpeed] >> 5;
info->close_delay = 0;
info->x_char = 0;
info->count = 0;
#ifdef SERIAL_DEBUG_COUNT
printk("cyc: %d: setting count to 0\n",
__LINE__);
#endif
info->blocked_open = 0;
info->default_threshold = 0;
info->default_timeout = 0;
init_waitqueue_head(&info->open_wait);
init_waitqueue_head(&info->close_wait);
info->read_status_mask =
CyTIMEOUT | CySPECHAR | CyBREAK | CyPARITY |
CyFRAME | CyOVERRUN;
printk("ttyS%d ", info->line);
port_num++;
info++;
if (!(port_num & 7)) {
printk("\n ");
}
}
}
printk("\n");
}
while (port_num < NR_PORTS) {
info->line = -1;
port_num++;
info++;
}
ret = request_irq(MVME167_IRQ_SER_ERR, cd2401_rxerr_interrupt, 0,
"cd2401_errors", cd2401_rxerr_interrupt);
if (ret) {
printk(KERN_ERR "Could't get cd2401_errors IRQ");
goto cleanup_serial_driver;
}
ret = request_irq(MVME167_IRQ_SER_MODEM, cd2401_modem_interrupt, 0,
"cd2401_modem", cd2401_modem_interrupt);
if (ret) {
printk(KERN_ERR "Could't get cd2401_modem IRQ");
goto cleanup_irq_cd2401_errors;
}
ret = request_irq(MVME167_IRQ_SER_TX, cd2401_tx_interrupt, 0,
"cd2401_txints", cd2401_tx_interrupt);
if (ret) {
printk(KERN_ERR "Could't get cd2401_txints IRQ");
goto cleanup_irq_cd2401_modem;
}
ret = request_irq(MVME167_IRQ_SER_RX, cd2401_rx_interrupt, 0,
"cd2401_rxints", cd2401_rx_interrupt);
if (ret) {
printk(KERN_ERR "Could't get cd2401_rxints IRQ");
goto cleanup_irq_cd2401_txints;
}
pcc2chip[PccSCCMICR] = 0x15;
pcc2chip[PccSCCTICR] = 0x15;
pcc2chip[PccSCCRICR] = 0x15;
pcc2chip[PccIMLR] = 3;
return 0;
cleanup_irq_cd2401_txints:
free_irq(MVME167_IRQ_SER_TX, cd2401_tx_interrupt);
cleanup_irq_cd2401_modem:
free_irq(MVME167_IRQ_SER_MODEM, cd2401_modem_interrupt);
cleanup_irq_cd2401_errors:
free_irq(MVME167_IRQ_SER_ERR, cd2401_rxerr_interrupt);
cleanup_serial_driver:
if (tty_unregister_driver(cy_serial_driver))
printk(KERN_ERR
"Couldn't unregister MVME166/7 serial driver\n");
put_tty_driver(cy_serial_driver);
return ret;
}
static void show_status(int line_num)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
int channel;
struct cyclades_port *info;
unsigned long flags;
info = &cy_port[line_num];
channel = info->line;
printk(" channel %d\n", channel);
printk(" cy_port\n");
printk(" card line flags = %d %d %x\n",
info->card, info->line, info->flags);
printk
(" *tty read_status_mask timeout xmit_fifo_size = %lx %x %x %x\n",
(long)info->tty, info->read_status_mask, info->timeout,
info->xmit_fifo_size);
printk(" cor1,cor2,cor3,cor4,cor5,cor6,cor7 = %x %x %x %x %x %x %x\n",
info->cor1, info->cor2, info->cor3, info->cor4, info->cor5,
info->cor6, info->cor7);
printk(" tbpr,tco,rbpr,rco = %d %d %d %d\n", info->tbpr, info->tco,
info->rbpr, info->rco);
printk(" close_delay event count = %d %d %d\n", info->close_delay,
info->event, info->count);
printk(" x_char blocked_open = %x %x\n", info->x_char,
info->blocked_open);
printk(" open_wait = %lx %lx %lx\n", (long)info->open_wait);
local_irq_save(flags);
printk(" CyGFRCR %x\n", base_addr[CyGFRCR]);
printk(" CyCAR %x\n", base_addr[CyCAR]);
printk(" CyRISR %x\n", base_addr[CyRISR]);
printk(" CyTISR %x\n", base_addr[CyTISR]);
printk(" CyMISR %x\n", base_addr[CyMISR]);
printk(" CyRIR %x\n", base_addr[CyRIR]);
printk(" CyTIR %x\n", base_addr[CyTIR]);
printk(" CyMIR %x\n", base_addr[CyMIR]);
printk(" CyTPR %x\n", base_addr[CyTPR]);
base_addr[CyCAR] = (u_char) channel;
#if 0
printk(" CyRIVR %x\n", base_addr[CyRIVR]);
printk(" CyTIVR %x\n", base_addr[CyTIVR]);
printk(" CyMIVR %x\n", base_addr[CyMIVR]);
printk(" CyMISR %x\n", base_addr[CyMISR]);
#endif
printk(" CyCCR %x\n", base_addr[CyCCR]);
printk(" CyIER %x\n", base_addr[CyIER]);
printk(" CyCOR1 %x\n", base_addr[CyCOR1]);
printk(" CyCOR2 %x\n", base_addr[CyCOR2]);
printk(" CyCOR3 %x\n", base_addr[CyCOR3]);
printk(" CyCOR4 %x\n", base_addr[CyCOR4]);
printk(" CyCOR5 %x\n", base_addr[CyCOR5]);
#if 0
printk(" CyCCSR %x\n", base_addr[CyCCSR]);
printk(" CyRDCR %x\n", base_addr[CyRDCR]);
#endif
printk(" CySCHR1 %x\n", base_addr[CySCHR1]);
printk(" CySCHR2 %x\n", base_addr[CySCHR2]);
#if 0
printk(" CySCHR3 %x\n", base_addr[CySCHR3]);
printk(" CySCHR4 %x\n", base_addr[CySCHR4]);
printk(" CySCRL %x\n", base_addr[CySCRL]);
printk(" CySCRH %x\n", base_addr[CySCRH]);
printk(" CyLNC %x\n", base_addr[CyLNC]);
printk(" CyMCOR1 %x\n", base_addr[CyMCOR1]);
printk(" CyMCOR2 %x\n", base_addr[CyMCOR2]);
#endif
printk(" CyRTPRL %x\n", base_addr[CyRTPRL]);
printk(" CyRTPRH %x\n", base_addr[CyRTPRH]);
printk(" CyMSVR1 %x\n", base_addr[CyMSVR1]);
printk(" CyMSVR2 %x\n", base_addr[CyMSVR2]);
printk(" CyRBPR %x\n", base_addr[CyRBPR]);
printk(" CyRCOR %x\n", base_addr[CyRCOR]);
printk(" CyTBPR %x\n", base_addr[CyTBPR]);
printk(" CyTCOR %x\n", base_addr[CyTCOR]);
local_irq_restore(flags);
}
void serial167_console_write(struct console *co, const char *str,
unsigned count)
{
volatile unsigned char *base_addr = (u_char *) BASE_ADDR;
unsigned long flags;
volatile u_char sink;
u_char ier;
int port;
u_char do_lf = 0;
int i = 0;
local_irq_save(flags);
port = 0;
base_addr[CyCAR] = (u_char) port;
while (base_addr[CyCCR])
;
base_addr[CyCCR] = CyENB_XMTR;
ier = base_addr[CyIER];
base_addr[CyIER] = CyTxMpty;
while (1) {
if (pcc2chip[PccSCCTICR] & 0x20) {
sink = pcc2chip[PccTPIACKR];
if ((base_addr[CyLICR] >> 2) == port) {
if (i == count) {
base_addr[CyTEOIR] = CyNOTRANS;
break;
}
if (do_lf) {
base_addr[CyTDR] = '\n';
str++;
i++;
do_lf = 0;
} else if (*str == '\n') {
base_addr[CyTDR] = '\r';
do_lf = 1;
} else {
base_addr[CyTDR] = *str++;
i++;
}
base_addr[CyTEOIR] = 0;
} else
base_addr[CyTEOIR] = CyNOTRANS;
}
}
base_addr[CyIER] = ier;
local_irq_restore(flags);
}
static struct tty_driver *serial167_console_device(struct console *c,
int *index)
{
*index = c->index;
return cy_serial_driver;
}
static int __init serial167_console_init(void)
{
if (vme_brdtype == VME_TYPE_MVME166 ||
vme_brdtype == VME_TYPE_MVME167 ||
vme_brdtype == VME_TYPE_MVME177) {
mvme167_serial_console_setup(0);
register_console(&sercons);
}
return 0;
}
