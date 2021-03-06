static inline int WaitTillCardIsFree(unsigned long base)
{
unsigned int count = 0;
unsigned int a = in_atomic();
while (!(inw(base + 0xe) & 0x1) && count++ < 100)
if (a)
mdelay(1);
else
msleep(1);
return !(inw(base + 0xe) & 0x1);
}
static int lock_card(struct isi_board *card)
{
unsigned long base = card->base;
unsigned int retries, a;
for (retries = 0; retries < 10; retries++) {
spin_lock_irqsave(&card->card_lock, card->flags);
for (a = 0; a < 10; a++) {
if (inw(base + 0xe) & 0x1)
return 1;
udelay(10);
}
spin_unlock_irqrestore(&card->card_lock, card->flags);
msleep(10);
}
pr_warning("Failed to lock Card (0x%lx)\n", card->base);
return 0;
}
static void unlock_card(struct isi_board *card)
{
spin_unlock_irqrestore(&card->card_lock, card->flags);
}
static void raise_dtr(struct isi_port *port)
{
struct isi_board *card = port->card;
unsigned long base = card->base;
u16 channel = port->channel;
if (WaitTillCardIsFree(base))
return;
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0504, base);
InterruptTheCard(base);
port->status |= ISI_DTR;
}
static inline void drop_dtr(struct isi_port *port)
{
struct isi_board *card = port->card;
unsigned long base = card->base;
u16 channel = port->channel;
if (WaitTillCardIsFree(base))
return;
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0404, base);
InterruptTheCard(base);
port->status &= ~ISI_DTR;
}
static inline void raise_rts(struct isi_port *port)
{
struct isi_board *card = port->card;
unsigned long base = card->base;
u16 channel = port->channel;
if (WaitTillCardIsFree(base))
return;
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0a04, base);
InterruptTheCard(base);
port->status |= ISI_RTS;
}
static inline void drop_rts(struct isi_port *port)
{
struct isi_board *card = port->card;
unsigned long base = card->base;
u16 channel = port->channel;
if (WaitTillCardIsFree(base))
return;
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0804, base);
InterruptTheCard(base);
port->status &= ~ISI_RTS;
}
static void isicom_dtr_rts(struct tty_port *port, int on)
{
struct isi_port *ip = container_of(port, struct isi_port, port);
struct isi_board *card = ip->card;
unsigned long base = card->base;
u16 channel = ip->channel;
if (!lock_card(card))
return;
if (on) {
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0f04, base);
InterruptTheCard(base);
ip->status |= (ISI_DTR | ISI_RTS);
} else {
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0C04, base);
InterruptTheCard(base);
ip->status &= ~(ISI_DTR | ISI_RTS);
}
unlock_card(card);
}
static void drop_dtr_rts(struct isi_port *port)
{
struct isi_board *card = port->card;
unsigned long base = card->base;
u16 channel = port->channel;
if (WaitTillCardIsFree(base))
return;
outw(0x8000 | (channel << card->shift_count) | 0x02, base);
outw(0x0c04, base);
InterruptTheCard(base);
port->status &= ~(ISI_RTS | ISI_DTR);
}
static inline int __isicom_paranoia_check(struct isi_port const *port,
char *name, const char *routine)
{
if (!port) {
pr_warning("Warning: bad isicom magic for dev %s in %s.\n",
name, routine);
return 1;
}
if (port->magic != ISICOM_MAGIC) {
pr_warning("Warning: NULL isicom port for dev %s in %s.\n",
name, routine);
return 1;
}
return 0;
}
static void isicom_tx(unsigned long _data)
{
unsigned long flags, base;
unsigned int retries;
short count = (BOARD_COUNT-1), card;
short txcount, wrd, residue, word_count, cnt;
struct isi_port *port;
struct tty_struct *tty;
card = (prev_card + 1) & 0x0003;
while (count-- > 0) {
if (isi_card[card].status & BOARD_ACTIVE)
break;
card = (card + 1) & 0x0003;
}
if (!(isi_card[card].status & BOARD_ACTIVE))
goto sched_again;
prev_card = card;
count = isi_card[card].port_count;
port = isi_card[card].ports;
base = isi_card[card].base;
spin_lock_irqsave(&isi_card[card].card_lock, flags);
for (retries = 0; retries < 100; retries++) {
if (inw(base + 0xe) & 0x1)
break;
udelay(2);
}
if (retries >= 100)
goto unlock;
tty = tty_port_tty_get(&port->port);
if (tty == NULL)
goto put_unlock;
for (; count > 0; count--, port++) {
if (!(port->port.flags & ASYNC_INITIALIZED) ||
!(port->status & ISI_TXOK))
continue;
txcount = min_t(short, TX_SIZE, port->xmit_cnt);
if (txcount <= 0 || tty->stopped || tty->hw_stopped)
continue;
if (!(inw(base + 0x02) & (1 << port->channel)))
continue;
pr_debug("txing %d bytes, port%d.\n",
txcount, port->channel + 1);
outw((port->channel << isi_card[card].shift_count) | txcount,
base);
residue = NO;
wrd = 0;
while (1) {
cnt = min_t(int, txcount, (SERIAL_XMIT_SIZE
- port->xmit_tail));
if (residue == YES) {
residue = NO;
if (cnt > 0) {
wrd |= (port->port.xmit_buf[port->xmit_tail]
<< 8);
port->xmit_tail = (port->xmit_tail + 1)
& (SERIAL_XMIT_SIZE - 1);
port->xmit_cnt--;
txcount--;
cnt--;
outw(wrd, base);
} else {
outw(wrd, base);
break;
}
}
if (cnt <= 0)
break;
word_count = cnt >> 1;
outsw(base, port->port.xmit_buf+port->xmit_tail, word_count);
port->xmit_tail = (port->xmit_tail
+ (word_count << 1)) & (SERIAL_XMIT_SIZE - 1);
txcount -= (word_count << 1);
port->xmit_cnt -= (word_count << 1);
if (cnt & 0x0001) {
residue = YES;
wrd = port->port.xmit_buf[port->xmit_tail];
port->xmit_tail = (port->xmit_tail + 1)
& (SERIAL_XMIT_SIZE - 1);
port->xmit_cnt--;
txcount--;
}
}
InterruptTheCard(base);
if (port->xmit_cnt <= 0)
port->status &= ~ISI_TXOK;
if (port->xmit_cnt <= WAKEUP_CHARS)
tty_wakeup(tty);
}
put_unlock:
tty_kref_put(tty);
unlock:
spin_unlock_irqrestore(&isi_card[card].card_lock, flags);
sched_again:
mod_timer(&tx, jiffies + msecs_to_jiffies(10));
}
static irqreturn_t isicom_interrupt(int irq, void *dev_id)
{
struct isi_board *card = dev_id;
struct isi_port *port;
struct tty_struct *tty;
unsigned long base;
u16 header, word_count, count, channel;
short byte_count;
unsigned char *rp;
if (!card || !(card->status & FIRMWARE_LOADED))
return IRQ_NONE;
base = card->base;
if (!(inw(base + 0x0e) & 0x02))
return IRQ_NONE;
spin_lock(&card->card_lock);
outw(0x8000, base+0x04);
ClearInterrupt(base);
inw(base);
header = inw(base);
channel = (header & 0x7800) >> card->shift_count;
byte_count = header & 0xff;
if (channel + 1 > card->port_count) {
pr_warning("%s(0x%lx): %d(channel) > port_count.\n",
__func__, base, channel+1);
outw(0x0000, base+0x04);
spin_unlock(&card->card_lock);
return IRQ_HANDLED;
}
port = card->ports + channel;
if (!(port->port.flags & ASYNC_INITIALIZED)) {
outw(0x0000, base+0x04);
spin_unlock(&card->card_lock);
return IRQ_HANDLED;
}
tty = tty_port_tty_get(&port->port);
if (tty == NULL) {
word_count = byte_count >> 1;
while (byte_count > 1) {
inw(base);
byte_count -= 2;
}
if (byte_count & 0x01)
inw(base);
outw(0x0000, base+0x04);
spin_unlock(&card->card_lock);
return IRQ_HANDLED;
}
if (header & 0x8000) {
header = inw(base);
switch (header & 0xff) {
case 0:
if (port->port.flags & ASYNC_CHECK_CD) {
if (port->status & ISI_DCD) {
if (!(header & ISI_DCD)) {
pr_debug("%s: DCD->low.\n",
__func__);
port->status &= ~ISI_DCD;
tty_hangup(tty);
}
} else if (header & ISI_DCD) {
pr_debug("%s: DCD->high.\n",
__func__);
port->status |= ISI_DCD;
wake_up_interruptible(&port->port.open_wait);
}
} else {
if (header & ISI_DCD)
port->status |= ISI_DCD;
else
port->status &= ~ISI_DCD;
}
if (tty_port_cts_enabled(&port->port)) {
if (tty->hw_stopped) {
if (header & ISI_CTS) {
port->port.tty->hw_stopped = 0;
port->status |= (ISI_TXOK
| ISI_CTS);
tty_wakeup(tty);
}
} else if (!(header & ISI_CTS)) {
tty->hw_stopped = 1;
port->status &= ~(ISI_TXOK | ISI_CTS);
}
} else {
if (header & ISI_CTS)
port->status |= ISI_CTS;
else
port->status &= ~ISI_CTS;
}
if (header & ISI_DSR)
port->status |= ISI_DSR;
else
port->status &= ~ISI_DSR;
if (header & ISI_RI)
port->status |= ISI_RI;
else
port->status &= ~ISI_RI;
break;
case 1:
tty_insert_flip_char(tty, 0, TTY_BREAK);
if (port->port.flags & ASYNC_SAK)
do_SAK(tty);
tty_flip_buffer_push(tty);
break;
case 2:
pr_debug("%s: stats!!!\n", __func__);
break;
default:
pr_debug("%s: Unknown code in status packet.\n",
__func__);
break;
}
} else {
count = tty_prepare_flip_string(tty, &rp, byte_count & ~1);
pr_debug("%s: Can rx %d of %d bytes.\n",
__func__, count, byte_count);
word_count = count >> 1;
insw(base, rp, word_count);
byte_count -= (word_count << 1);
if (count & 0x0001) {
tty_insert_flip_char(tty, inw(base) & 0xff,
TTY_NORMAL);
byte_count -= 2;
}
if (byte_count > 0) {
pr_debug("%s(0x%lx:%d): Flip buffer overflow! dropping bytes...\n",
__func__, base, channel + 1);
while (byte_count > 0) {
inw(base);
byte_count -= 2;
}
}
tty_flip_buffer_push(tty);
}
outw(0x0000, base+0x04);
spin_unlock(&card->card_lock);
tty_kref_put(tty);
return IRQ_HANDLED;
}
static void isicom_config_port(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
unsigned long baud;
unsigned long base = card->base;
u16 channel_setup, channel = port->channel,
shift_count = card->shift_count;
unsigned char flow_ctrl;
baud = C_BAUD(tty);
if (baud & CBAUDEX) {
baud &= ~CBAUDEX;
if (baud < 1 || baud > 4)
tty->termios.c_cflag &= ~CBAUDEX;
else
baud += 15;
}
if (baud == 15) {
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
baud++;
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
baud += 2;
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
baud += 3;
if ((port->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
baud += 4;
}
if (linuxb_to_isib[baud] == -1) {
drop_dtr(port);
return;
} else
raise_dtr(port);
if (WaitTillCardIsFree(base) == 0) {
outw(0x8000 | (channel << shift_count) | 0x03, base);
outw(linuxb_to_isib[baud] << 8 | 0x03, base);
channel_setup = 0;
switch (C_CSIZE(tty)) {
case CS5:
channel_setup |= ISICOM_CS5;
break;
case CS6:
channel_setup |= ISICOM_CS6;
break;
case CS7:
channel_setup |= ISICOM_CS7;
break;
case CS8:
channel_setup |= ISICOM_CS8;
break;
}
if (C_CSTOPB(tty))
channel_setup |= ISICOM_2SB;
if (C_PARENB(tty)) {
channel_setup |= ISICOM_EVPAR;
if (C_PARODD(tty))
channel_setup |= ISICOM_ODPAR;
}
outw(channel_setup, base);
InterruptTheCard(base);
}
if (C_CLOCAL(tty))
port->port.flags &= ~ASYNC_CHECK_CD;
else
port->port.flags |= ASYNC_CHECK_CD;
flow_ctrl = 0;
port->port.flags &= ~ASYNC_CTS_FLOW;
if (C_CRTSCTS(tty)) {
port->port.flags |= ASYNC_CTS_FLOW;
flow_ctrl |= ISICOM_CTSRTS;
}
if (I_IXON(tty))
flow_ctrl |= ISICOM_RESPOND_XONXOFF;
if (I_IXOFF(tty))
flow_ctrl |= ISICOM_INITIATE_XONXOFF;
if (WaitTillCardIsFree(base) == 0) {
outw(0x8000 | (channel << shift_count) | 0x04, base);
outw(flow_ctrl << 8 | 0x05, base);
outw((STOP_CHAR(tty)) << 8 | (START_CHAR(tty)), base);
InterruptTheCard(base);
}
if (C_CREAD(tty)) {
card->port_status |= (1 << channel);
outw(card->port_status, base + 0x02);
}
}
static inline void isicom_setup_board(struct isi_board *bp)
{
int channel;
struct isi_port *port;
bp->count++;
if (!(bp->status & BOARD_INIT)) {
port = bp->ports;
for (channel = 0; channel < bp->port_count; channel++, port++)
drop_dtr_rts(port);
}
bp->status |= BOARD_ACTIVE | BOARD_INIT;
}
static int isicom_activate(struct tty_port *tport, struct tty_struct *tty)
{
struct isi_port *port = container_of(tport, struct isi_port, port);
struct isi_board *card = port->card;
unsigned long flags;
if (tty_port_alloc_xmit_buf(tport) < 0)
return -ENOMEM;
spin_lock_irqsave(&card->card_lock, flags);
isicom_setup_board(card);
port->xmit_cnt = port->xmit_head = port->xmit_tail = 0;
if (WaitTillCardIsFree(card->base) == 0) {
outw(0x8000 | (port->channel << card->shift_count) | 0x02,
card->base);
outw(((ISICOM_KILLTX | ISICOM_KILLRX) << 8) | 0x06, card->base);
InterruptTheCard(card->base);
}
isicom_config_port(tty);
spin_unlock_irqrestore(&card->card_lock, flags);
return 0;
}
static int isicom_carrier_raised(struct tty_port *port)
{
struct isi_port *ip = container_of(port, struct isi_port, port);
return (ip->status & ISI_DCD)?1 : 0;
}
static struct tty_port *isicom_find_port(struct tty_struct *tty)
{
struct isi_port *port;
struct isi_board *card;
unsigned int board;
int line = tty->index;
board = BOARD(line);
card = &isi_card[board];
if (!(card->status & FIRMWARE_LOADED))
return NULL;
if (line > ((board * 16) + card->port_count - 1))
return NULL;
port = &isi_ports[line];
if (isicom_paranoia_check(port, tty->name, "isicom_open"))
return NULL;
return &port->port;
}
static int isicom_open(struct tty_struct *tty, struct file *filp)
{
struct isi_port *port;
struct tty_port *tport;
tport = isicom_find_port(tty);
if (tport == NULL)
return -ENODEV;
port = container_of(tport, struct isi_port, port);
tty->driver_data = port;
return tty_port_open(tport, tty, filp);
}
static void isicom_shutdown_port(struct isi_port *port)
{
struct isi_board *card = port->card;
if (--card->count < 0) {
pr_debug("%s: bad board(0x%lx) count %d.\n",
__func__, card->base, card->count);
card->count = 0;
}
if (!card->count)
card->status &= BOARD_ACTIVE;
}
static void isicom_flush_buffer(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
unsigned long flags;
if (isicom_paranoia_check(port, tty->name, "isicom_flush_buffer"))
return;
spin_lock_irqsave(&card->card_lock, flags);
port->xmit_cnt = port->xmit_head = port->xmit_tail = 0;
spin_unlock_irqrestore(&card->card_lock, flags);
tty_wakeup(tty);
}
static void isicom_shutdown(struct tty_port *port)
{
struct isi_port *ip = container_of(port, struct isi_port, port);
struct isi_board *card = ip->card;
unsigned long flags;
spin_lock_irqsave(&card->card_lock, flags);
card->port_status &= ~(1 << ip->channel);
outw(card->port_status, card->base + 0x02);
isicom_shutdown_port(ip);
spin_unlock_irqrestore(&card->card_lock, flags);
tty_port_free_xmit_buf(port);
}
static void isicom_close(struct tty_struct *tty, struct file *filp)
{
struct isi_port *ip = tty->driver_data;
struct tty_port *port;
if (ip == NULL)
return;
port = &ip->port;
if (isicom_paranoia_check(ip, tty->name, "isicom_close"))
return;
tty_port_close(port, tty, filp);
}
static int isicom_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
unsigned long flags;
int cnt, total = 0;
if (isicom_paranoia_check(port, tty->name, "isicom_write"))
return 0;
spin_lock_irqsave(&card->card_lock, flags);
while (1) {
cnt = min_t(int, count, min(SERIAL_XMIT_SIZE - port->xmit_cnt
- 1, SERIAL_XMIT_SIZE - port->xmit_head));
if (cnt <= 0)
break;
memcpy(port->port.xmit_buf + port->xmit_head, buf, cnt);
port->xmit_head = (port->xmit_head + cnt) & (SERIAL_XMIT_SIZE
- 1);
port->xmit_cnt += cnt;
buf += cnt;
count -= cnt;
total += cnt;
}
if (port->xmit_cnt && !tty->stopped && !tty->hw_stopped)
port->status |= ISI_TXOK;
spin_unlock_irqrestore(&card->card_lock, flags);
return total;
}
static int isicom_put_char(struct tty_struct *tty, unsigned char ch)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
unsigned long flags;
if (isicom_paranoia_check(port, tty->name, "isicom_put_char"))
return 0;
spin_lock_irqsave(&card->card_lock, flags);
if (port->xmit_cnt >= SERIAL_XMIT_SIZE - 1) {
spin_unlock_irqrestore(&card->card_lock, flags);
return 0;
}
port->port.xmit_buf[port->xmit_head++] = ch;
port->xmit_head &= (SERIAL_XMIT_SIZE - 1);
port->xmit_cnt++;
spin_unlock_irqrestore(&card->card_lock, flags);
return 1;
}
static void isicom_flush_chars(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
if (isicom_paranoia_check(port, tty->name, "isicom_flush_chars"))
return;
if (port->xmit_cnt <= 0 || tty->stopped || tty->hw_stopped ||
!port->port.xmit_buf)
return;
port->status |= ISI_TXOK;
}
static int isicom_write_room(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
int free;
if (isicom_paranoia_check(port, tty->name, "isicom_write_room"))
return 0;
free = SERIAL_XMIT_SIZE - port->xmit_cnt - 1;
if (free < 0)
free = 0;
return free;
}
static int isicom_chars_in_buffer(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
if (isicom_paranoia_check(port, tty->name, "isicom_chars_in_buffer"))
return 0;
return port->xmit_cnt;
}
static int isicom_send_break(struct tty_struct *tty, int length)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
unsigned long base = card->base;
if (length == -1)
return -EOPNOTSUPP;
if (!lock_card(card))
return -EINVAL;
outw(0x8000 | ((port->channel) << (card->shift_count)) | 0x3, base);
outw((length & 0xff) << 8 | 0x00, base);
outw((length & 0xff00), base);
InterruptTheCard(base);
unlock_card(card);
return 0;
}
static int isicom_tiocmget(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
u16 status = port->status;
if (isicom_paranoia_check(port, tty->name, "isicom_ioctl"))
return -ENODEV;
return ((status & ISI_RTS) ? TIOCM_RTS : 0) |
((status & ISI_DTR) ? TIOCM_DTR : 0) |
((status & ISI_DCD) ? TIOCM_CAR : 0) |
((status & ISI_DSR) ? TIOCM_DSR : 0) |
((status & ISI_CTS) ? TIOCM_CTS : 0) |
((status & ISI_RI ) ? TIOCM_RI : 0);
}
static int isicom_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct isi_port *port = tty->driver_data;
unsigned long flags;
if (isicom_paranoia_check(port, tty->name, "isicom_ioctl"))
return -ENODEV;
spin_lock_irqsave(&port->card->card_lock, flags);
if (set & TIOCM_RTS)
raise_rts(port);
if (set & TIOCM_DTR)
raise_dtr(port);
if (clear & TIOCM_RTS)
drop_rts(port);
if (clear & TIOCM_DTR)
drop_dtr(port);
spin_unlock_irqrestore(&port->card->card_lock, flags);
return 0;
}
static int isicom_set_serial_info(struct tty_struct *tty,
struct serial_struct __user *info)
{
struct isi_port *port = tty->driver_data;
struct serial_struct newinfo;
int reconfig_port;
if (copy_from_user(&newinfo, info, sizeof(newinfo)))
return -EFAULT;
mutex_lock(&port->port.mutex);
reconfig_port = ((port->port.flags & ASYNC_SPD_MASK) !=
(newinfo.flags & ASYNC_SPD_MASK));
if (!capable(CAP_SYS_ADMIN)) {
if ((newinfo.close_delay != port->port.close_delay) ||
(newinfo.closing_wait != port->port.closing_wait) ||
((newinfo.flags & ~ASYNC_USR_MASK) !=
(port->port.flags & ~ASYNC_USR_MASK))) {
mutex_unlock(&port->port.mutex);
return -EPERM;
}
port->port.flags = ((port->port.flags & ~ASYNC_USR_MASK) |
(newinfo.flags & ASYNC_USR_MASK));
} else {
port->port.close_delay = newinfo.close_delay;
port->port.closing_wait = newinfo.closing_wait;
port->port.flags = ((port->port.flags & ~ASYNC_FLAGS) |
(newinfo.flags & ASYNC_FLAGS));
}
if (reconfig_port) {
unsigned long flags;
spin_lock_irqsave(&port->card->card_lock, flags);
isicom_config_port(tty);
spin_unlock_irqrestore(&port->card->card_lock, flags);
}
mutex_unlock(&port->port.mutex);
return 0;
}
static int isicom_get_serial_info(struct isi_port *port,
struct serial_struct __user *info)
{
struct serial_struct out_info;
mutex_lock(&port->port.mutex);
memset(&out_info, 0, sizeof(out_info));
out_info.line = port - isi_ports;
out_info.port = port->card->base;
out_info.irq = port->card->irq;
out_info.flags = port->port.flags;
out_info.close_delay = port->port.close_delay;
out_info.closing_wait = port->port.closing_wait;
mutex_unlock(&port->port.mutex);
if (copy_to_user(info, &out_info, sizeof(out_info)))
return -EFAULT;
return 0;
}
static int isicom_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct isi_port *port = tty->driver_data;
void __user *argp = (void __user *)arg;
if (isicom_paranoia_check(port, tty->name, "isicom_ioctl"))
return -ENODEV;
switch (cmd) {
case TIOCGSERIAL:
return isicom_get_serial_info(port, argp);
case TIOCSSERIAL:
return isicom_set_serial_info(tty, argp);
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void isicom_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct isi_port *port = tty->driver_data;
unsigned long flags;
if (isicom_paranoia_check(port, tty->name, "isicom_set_termios"))
return;
if (tty->termios.c_cflag == old_termios->c_cflag &&
tty->termios.c_iflag == old_termios->c_iflag)
return;
spin_lock_irqsave(&port->card->card_lock, flags);
isicom_config_port(tty);
spin_unlock_irqrestore(&port->card->card_lock, flags);
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios.c_cflag & CRTSCTS)) {
tty->hw_stopped = 0;
isicom_start(tty);
}
}
static void isicom_throttle(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
if (isicom_paranoia_check(port, tty->name, "isicom_throttle"))
return;
card->port_status &= ~(1 << port->channel);
outw(card->port_status, card->base + 0x02);
}
static void isicom_unthrottle(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
struct isi_board *card = port->card;
if (isicom_paranoia_check(port, tty->name, "isicom_unthrottle"))
return;
card->port_status |= (1 << port->channel);
outw(card->port_status, card->base + 0x02);
}
static void isicom_stop(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
if (isicom_paranoia_check(port, tty->name, "isicom_stop"))
return;
port->status &= ~ISI_TXOK;
}
static void isicom_start(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
if (isicom_paranoia_check(port, tty->name, "isicom_start"))
return;
port->status |= ISI_TXOK;
}
static void isicom_hangup(struct tty_struct *tty)
{
struct isi_port *port = tty->driver_data;
if (isicom_paranoia_check(port, tty->name, "isicom_hangup"))
return;
tty_port_hangup(&port->port);
}
static int __devinit reset_card(struct pci_dev *pdev,
const unsigned int card, unsigned int *signature)
{
struct isi_board *board = pci_get_drvdata(pdev);
unsigned long base = board->base;
unsigned int sig, portcount = 0;
int retval = 0;
dev_dbg(&pdev->dev, "ISILoad:Resetting Card%d at 0x%lx\n", card + 1,
base);
inw(base + 0x8);
msleep(10);
outw(0, base + 0x8);
msleep(1000);
sig = inw(base + 0x4) & 0xff;
if (sig != 0xa5 && sig != 0xbb && sig != 0xcc && sig != 0xdd &&
sig != 0xee) {
dev_warn(&pdev->dev, "ISILoad:Card%u reset failure (Possible "
"bad I/O Port Address 0x%lx).\n", card + 1, base);
dev_dbg(&pdev->dev, "Sig=0x%x\n", sig);
retval = -EIO;
goto end;
}
msleep(10);
portcount = inw(base + 0x2);
if (!(inw(base + 0xe) & 0x1) || (portcount != 0 && portcount != 4 &&
portcount != 8 && portcount != 16)) {
dev_err(&pdev->dev, "ISILoad:PCI Card%d reset failure.\n",
card + 1);
retval = -EIO;
goto end;
}
switch (sig) {
case 0xa5:
case 0xbb:
case 0xdd:
board->port_count = (portcount == 4) ? 4 : 8;
board->shift_count = 12;
break;
case 0xcc:
case 0xee:
board->port_count = 16;
board->shift_count = 11;
break;
}
dev_info(&pdev->dev, "-Done\n");
*signature = sig;
end:
return retval;
}
static int __devinit load_firmware(struct pci_dev *pdev,
const unsigned int index, const unsigned int signature)
{
struct isi_board *board = pci_get_drvdata(pdev);
const struct firmware *fw;
unsigned long base = board->base;
unsigned int a;
u16 word_count, status;
int retval = -EIO;
char *name;
u8 *data;
struct stframe {
u16 addr;
u16 count;
u8 data[0];
} *frame;
switch (signature) {
case 0xa5:
name = "isi608.bin";
break;
case 0xbb:
name = "isi608em.bin";
break;
case 0xcc:
name = "isi616em.bin";
break;
case 0xdd:
name = "isi4608.bin";
break;
case 0xee:
name = "isi4616.bin";
break;
default:
dev_err(&pdev->dev, "Unknown signature.\n");
goto end;
}
retval = request_firmware(&fw, name, &pdev->dev);
if (retval)
goto end;
retval = -EIO;
for (frame = (struct stframe *)fw->data;
frame < (struct stframe *)(fw->data + fw->size);
frame = (struct stframe *)((u8 *)(frame + 1) +
frame->count)) {
if (WaitTillCardIsFree(base))
goto errrelfw;
outw(0xf0, base);
outw(0x00, base);
outw(frame->addr, base);
word_count = frame->count / 2 + frame->count % 2;
outw(word_count, base);
InterruptTheCard(base);
udelay(100);
if (WaitTillCardIsFree(base))
goto errrelfw;
status = inw(base + 0x4);
if (status != 0) {
dev_warn(&pdev->dev, "Card%d rejected load header:\n"
"Address:0x%x\n"
"Count:0x%x\n"
"Status:0x%x\n",
index + 1, frame->addr, frame->count, status);
goto errrelfw;
}
outsw(base, frame->data, word_count);
InterruptTheCard(base);
udelay(50);
if (WaitTillCardIsFree(base))
goto errrelfw;
status = inw(base + 0x4);
if (status != 0) {
dev_err(&pdev->dev, "Card%d got out of sync.Card "
"Status:0x%x\n", index + 1, status);
goto errrelfw;
}
}
for (frame = (struct stframe *)fw->data;
frame < (struct stframe *)(fw->data + fw->size);
frame = (struct stframe *)((u8 *)(frame + 1) +
frame->count)) {
if (WaitTillCardIsFree(base))
goto errrelfw;
outw(0xf1, base);
outw(0x00, base);
outw(frame->addr, base);
word_count = (frame->count >> 1) + frame->count % 2;
outw(word_count + 1, base);
InterruptTheCard(base);
udelay(50);
if (WaitTillCardIsFree(base))
goto errrelfw;
status = inw(base + 0x4);
if (status != 0) {
dev_warn(&pdev->dev, "Card%d rejected verify header:\n"
"Address:0x%x\n"
"Count:0x%x\n"
"Status: 0x%x\n",
index + 1, frame->addr, frame->count, status);
goto errrelfw;
}
data = kmalloc(word_count * 2, GFP_KERNEL);
if (data == NULL) {
dev_err(&pdev->dev, "Card%d, firmware upload "
"failed, not enough memory\n", index + 1);
goto errrelfw;
}
inw(base);
insw(base, data, word_count);
InterruptTheCard(base);
for (a = 0; a < frame->count; a++)
if (data[a] != frame->data[a]) {
kfree(data);
dev_err(&pdev->dev, "Card%d, firmware upload "
"failed\n", index + 1);
goto errrelfw;
}
kfree(data);
udelay(50);
if (WaitTillCardIsFree(base))
goto errrelfw;
status = inw(base + 0x4);
if (status != 0) {
dev_err(&pdev->dev, "Card%d verify got out of sync. "
"Card Status:0x%x\n", index + 1, status);
goto errrelfw;
}
}
if (WaitTillCardIsFree(base))
goto errrelfw;
outw(0xf2, base);
outw(0x800, base);
outw(0x0, base);
outw(0x0, base);
InterruptTheCard(base);
outw(0x0, base + 0x4);
board->status |= FIRMWARE_LOADED;
retval = 0;
errrelfw:
release_firmware(fw);
end:
return retval;
}
static int __devinit isicom_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned int uninitialized_var(signature), index;
int retval = -EPERM;
struct isi_board *board = NULL;
if (card_count >= BOARD_COUNT)
goto err;
retval = pci_enable_device(pdev);
if (retval) {
dev_err(&pdev->dev, "failed to enable\n");
goto err;
}
dev_info(&pdev->dev, "ISI PCI Card(Device ID 0x%x)\n", ent->device);
for (index = 0; index < BOARD_COUNT; index++) {
if (isi_card[index].base == 0) {
board = &isi_card[index];
break;
}
}
if (index == BOARD_COUNT) {
retval = -ENODEV;
goto err_disable;
}
board->index = index;
board->base = pci_resource_start(pdev, 3);
board->irq = pdev->irq;
card_count++;
pci_set_drvdata(pdev, board);
retval = pci_request_region(pdev, 3, ISICOM_NAME);
if (retval) {
dev_err(&pdev->dev, "I/O Region 0x%lx-0x%lx is busy. Card%d "
"will be disabled.\n", board->base, board->base + 15,
index + 1);
retval = -EBUSY;
goto errdec;
}
retval = request_irq(board->irq, isicom_interrupt,
IRQF_SHARED, ISICOM_NAME, board);
if (retval < 0) {
dev_err(&pdev->dev, "Could not install handler at Irq %d. "
"Card%d will be disabled.\n", board->irq, index + 1);
goto errunrr;
}
retval = reset_card(pdev, index, &signature);
if (retval < 0)
goto errunri;
retval = load_firmware(pdev, index, signature);
if (retval < 0)
goto errunri;
for (index = 0; index < board->port_count; index++)
tty_port_register_device(&board->ports[index].port,
isicom_normal, board->index * 16 + index,
&pdev->dev);
return 0;
errunri:
free_irq(board->irq, board);
errunrr:
pci_release_region(pdev, 3);
errdec:
board->base = 0;
card_count--;
err_disable:
pci_disable_device(pdev);
err:
return retval;
}
static void __devexit isicom_remove(struct pci_dev *pdev)
{
struct isi_board *board = pci_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < board->port_count; i++)
tty_unregister_device(isicom_normal, board->index * 16 + i);
free_irq(board->irq, board);
pci_release_region(pdev, 3);
board->base = 0;
card_count--;
pci_disable_device(pdev);
}
static int __init isicom_init(void)
{
int retval, idx, channel;
struct isi_port *port;
for (idx = 0; idx < BOARD_COUNT; idx++) {
port = &isi_ports[idx * 16];
isi_card[idx].ports = port;
spin_lock_init(&isi_card[idx].card_lock);
for (channel = 0; channel < 16; channel++, port++) {
tty_port_init(&port->port);
port->port.ops = &isicom_port_ops;
port->magic = ISICOM_MAGIC;
port->card = &isi_card[idx];
port->channel = channel;
port->port.close_delay = 50 * HZ/100;
port->port.closing_wait = 3000 * HZ/100;
port->status = 0;
}
isi_card[idx].base = 0;
isi_card[idx].irq = 0;
}
isicom_normal = alloc_tty_driver(PORT_COUNT);
if (!isicom_normal) {
retval = -ENOMEM;
goto error;
}
isicom_normal->name = "ttyM";
isicom_normal->major = ISICOM_NMAJOR;
isicom_normal->minor_start = 0;
isicom_normal->type = TTY_DRIVER_TYPE_SERIAL;
isicom_normal->subtype = SERIAL_TYPE_NORMAL;
isicom_normal->init_termios = tty_std_termios;
isicom_normal->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL |
CLOCAL;
isicom_normal->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV | TTY_DRIVER_HARDWARE_BREAK;
tty_set_operations(isicom_normal, &isicom_ops);
retval = tty_register_driver(isicom_normal);
if (retval) {
pr_debug("Couldn't register the dialin driver\n");
goto err_puttty;
}
retval = pci_register_driver(&isicom_driver);
if (retval < 0) {
pr_err("Unable to register pci driver.\n");
goto err_unrtty;
}
mod_timer(&tx, jiffies + 1);
return 0;
err_unrtty:
tty_unregister_driver(isicom_normal);
err_puttty:
put_tty_driver(isicom_normal);
error:
return retval;
}
static void __exit isicom_exit(void)
{
del_timer_sync(&tx);
pci_unregister_driver(&isicom_driver);
tty_unregister_driver(isicom_normal);
put_tty_driver(isicom_normal);
}
