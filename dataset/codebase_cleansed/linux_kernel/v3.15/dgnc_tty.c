int dgnc_tty_preinit(void)
{
dgnc_TmpWriteBuf = kmalloc(WRITEBUFLEN, GFP_KERNEL);
if (!dgnc_TmpWriteBuf) {
DPR_INIT(("unable to allocate tmp write buf"));
return -ENOMEM;
}
return 0;
}
int dgnc_tty_register(struct dgnc_board *brd)
{
int rc = 0;
DPR_INIT(("tty_register start\n"));
memset(&brd->SerialDriver, 0, sizeof(brd->SerialDriver));
memset(&brd->PrintDriver, 0, sizeof(brd->PrintDriver));
brd->SerialDriver.magic = TTY_DRIVER_MAGIC;
snprintf(brd->SerialName, MAXTTYNAMELEN, "tty_dgnc_%d_", brd->boardnum);
brd->SerialDriver.name = brd->SerialName;
brd->SerialDriver.name_base = 0;
brd->SerialDriver.major = 0;
brd->SerialDriver.minor_start = 0;
brd->SerialDriver.num = brd->maxports;
brd->SerialDriver.type = TTY_DRIVER_TYPE_SERIAL;
brd->SerialDriver.subtype = SERIAL_TYPE_NORMAL;
brd->SerialDriver.init_termios = DgncDefaultTermios;
brd->SerialDriver.driver_name = DRVSTR;
brd->SerialDriver.flags = (TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV | TTY_DRIVER_HARDWARE_BREAK);
brd->SerialDriver.ttys = kzalloc(brd->maxports * sizeof(*brd->SerialDriver.ttys), GFP_KERNEL);
if (!brd->SerialDriver.ttys)
return -ENOMEM;
kref_init(&brd->SerialDriver.kref);
brd->SerialDriver.termios = kzalloc(brd->maxports * sizeof(*brd->SerialDriver.termios), GFP_KERNEL);
if (!brd->SerialDriver.termios)
return -ENOMEM;
tty_set_operations(&brd->SerialDriver, &dgnc_tty_ops);
if (!brd->dgnc_Major_Serial_Registered) {
rc = tty_register_driver(&brd->SerialDriver);
if (rc < 0) {
APR(("Can't register tty device (%d)\n", rc));
return rc;
}
brd->dgnc_Major_Serial_Registered = TRUE;
}
brd->PrintDriver.magic = TTY_DRIVER_MAGIC;
snprintf(brd->PrintName, MAXTTYNAMELEN, "pr_dgnc_%d_", brd->boardnum);
brd->PrintDriver.name = brd->PrintName;
brd->PrintDriver.name_base = 0;
brd->PrintDriver.major = brd->SerialDriver.major;
brd->PrintDriver.minor_start = 0x80;
brd->PrintDriver.num = brd->maxports;
brd->PrintDriver.type = TTY_DRIVER_TYPE_SERIAL;
brd->PrintDriver.subtype = SERIAL_TYPE_NORMAL;
brd->PrintDriver.init_termios = DgncDefaultTermios;
brd->PrintDriver.driver_name = DRVSTR;
brd->PrintDriver.flags = (TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV | TTY_DRIVER_HARDWARE_BREAK);
brd->PrintDriver.ttys = kzalloc(brd->maxports * sizeof(*brd->PrintDriver.ttys), GFP_KERNEL);
if (!brd->PrintDriver.ttys)
return -ENOMEM;
kref_init(&brd->PrintDriver.kref);
brd->PrintDriver.termios = kzalloc(brd->maxports * sizeof(*brd->PrintDriver.termios), GFP_KERNEL);
if (!brd->PrintDriver.termios)
return -ENOMEM;
tty_set_operations(&brd->PrintDriver, &dgnc_tty_ops);
if (!brd->dgnc_Major_TransparentPrint_Registered) {
rc = tty_register_driver(&brd->PrintDriver);
if (rc < 0) {
APR(("Can't register Transparent Print device (%d)\n", rc));
return rc;
}
brd->dgnc_Major_TransparentPrint_Registered = TRUE;
}
dgnc_BoardsByMajor[brd->SerialDriver.major] = brd;
brd->dgnc_Serial_Major = brd->SerialDriver.major;
brd->dgnc_TransparentPrint_Major = brd->PrintDriver.major;
DPR_INIT(("DGNC REGISTER TTY: MAJOR: %d\n", brd->SerialDriver.major));
return rc;
}
int dgnc_tty_init(struct dgnc_board *brd)
{
int i;
void __iomem *vaddr;
struct channel_t *ch;
if (!brd)
return -ENXIO;
DPR_INIT(("dgnc_tty_init start\n"));
vaddr = brd->re_map_membase;
brd->nasync = brd->maxports;
for (i = 0; i < brd->nasync; i++) {
if (!brd->channels[i]) {
brd->channels[i] = kzalloc(sizeof(*brd->channels[i]), GFP_KERNEL);
if (!brd->channels[i]) {
DPR_CORE(("%s:%d Unable to allocate memory for channel struct\n",
__FILE__, __LINE__));
}
}
}
ch = brd->channels[0];
vaddr = brd->re_map_membase;
for (i = 0; i < brd->nasync; i++, ch = brd->channels[i]) {
if (!brd->channels[i])
continue;
DGNC_SPINLOCK_INIT(ch->ch_lock);
ch->magic = DGNC_CHANNEL_MAGIC;
ch->ch_tun.magic = DGNC_UNIT_MAGIC;
ch->ch_tun.un_ch = ch;
ch->ch_tun.un_type = DGNC_SERIAL;
ch->ch_tun.un_dev = i;
ch->ch_pun.magic = DGNC_UNIT_MAGIC;
ch->ch_pun.un_ch = ch;
ch->ch_pun.un_type = DGNC_PRINT;
ch->ch_pun.un_dev = i + 128;
if (brd->bd_uart_offset == 0x200)
ch->ch_neo_uart = vaddr + (brd->bd_uart_offset * i);
else
ch->ch_cls_uart = vaddr + (brd->bd_uart_offset * i);
ch->ch_bd = brd;
ch->ch_portnum = i;
ch->ch_digi = dgnc_digi_init;
ch->ch_close_delay = 250;
init_waitqueue_head(&ch->ch_flags_wait);
init_waitqueue_head(&ch->ch_tun.un_flags_wait);
init_waitqueue_head(&ch->ch_pun.un_flags_wait);
init_waitqueue_head(&ch->ch_sniff_wait);
{
struct device *classp;
classp = tty_register_device(&brd->SerialDriver, i,
&(ch->ch_bd->pdev->dev));
ch->ch_tun.un_sysfs = classp;
dgnc_create_tty_sysfs(&ch->ch_tun, classp);
classp = tty_register_device(&brd->PrintDriver, i,
&(ch->ch_bd->pdev->dev));
ch->ch_pun.un_sysfs = classp;
dgnc_create_tty_sysfs(&ch->ch_pun, classp);
}
}
DPR_INIT(("dgnc_tty_init finish\n"));
return 0;
}
void dgnc_tty_post_uninit(void)
{
if (dgnc_TmpWriteBuf) {
kfree(dgnc_TmpWriteBuf);
dgnc_TmpWriteBuf = NULL;
}
}
void dgnc_tty_uninit(struct dgnc_board *brd)
{
int i = 0;
if (brd->dgnc_Major_Serial_Registered) {
dgnc_BoardsByMajor[brd->SerialDriver.major] = NULL;
brd->dgnc_Serial_Major = 0;
for (i = 0; i < brd->nasync; i++) {
dgnc_remove_tty_sysfs(brd->channels[i]->ch_tun.un_sysfs);
tty_unregister_device(&brd->SerialDriver, i);
}
tty_unregister_driver(&brd->SerialDriver);
brd->dgnc_Major_Serial_Registered = FALSE;
}
if (brd->dgnc_Major_TransparentPrint_Registered) {
dgnc_BoardsByMajor[brd->PrintDriver.major] = NULL;
brd->dgnc_TransparentPrint_Major = 0;
for (i = 0; i < brd->nasync; i++) {
dgnc_remove_tty_sysfs(brd->channels[i]->ch_pun.un_sysfs);
tty_unregister_device(&brd->PrintDriver, i);
}
tty_unregister_driver(&brd->PrintDriver);
brd->dgnc_Major_TransparentPrint_Registered = FALSE;
}
if (brd->SerialDriver.ttys) {
kfree(brd->SerialDriver.ttys);
brd->SerialDriver.ttys = NULL;
}
if (brd->PrintDriver.ttys) {
kfree(brd->PrintDriver.ttys);
brd->PrintDriver.ttys = NULL;
}
}
void dgnc_sniff_nowait_nolock(struct channel_t *ch, uchar *text, uchar *buf, int len)
{
struct timeval tv;
int n;
int r;
int nbuf;
int i;
int tmpbuflen;
char tmpbuf[TMPBUFLEN];
char *p = tmpbuf;
int too_much_data;
if (!(ch->ch_sniff_flags & SNIFF_OPEN))
return;
do_gettimeofday(&tv);
p += sprintf(p, "<%ld %ld><%s><", tv.tv_sec, tv.tv_usec, text);
tmpbuflen = p - tmpbuf;
do {
too_much_data = 0;
for (i = 0; i < len && tmpbuflen < (TMPBUFLEN - 4); i++) {
p += sprintf(p, "%02x ", *buf);
buf++;
tmpbuflen = p - tmpbuf;
}
if (tmpbuflen < (TMPBUFLEN - 4)) {
if (i > 0)
p += sprintf(p - 1, "%s\n", ">");
else
p += sprintf(p, "%s\n", ">");
} else {
too_much_data = 1;
len -= i;
}
nbuf = strlen(tmpbuf);
p = tmpbuf;
while (nbuf > 0 && ch->ch_sniff_buf) {
n = (ch->ch_sniff_out - ch->ch_sniff_in - 1) & SNIFF_MASK;
if (n == 0) {
return;
}
if (n > nbuf)
n = nbuf;
r = SNIFF_MAX - ch->ch_sniff_in;
if (r <= n) {
memcpy(ch->ch_sniff_buf + ch->ch_sniff_in, p, r);
n -= r;
ch->ch_sniff_in = 0;
p += r;
nbuf -= r;
}
memcpy(ch->ch_sniff_buf + ch->ch_sniff_in, p, n);
ch->ch_sniff_in += n;
p += n;
nbuf -= n;
if (ch->ch_sniff_flags & SNIFF_WAIT_DATA) {
ch->ch_sniff_flags &= ~SNIFF_WAIT_DATA;
wake_up_interruptible(&ch->ch_sniff_wait);
}
}
if (too_much_data) {
p = tmpbuf;
tmpbuflen = 0;
}
} while (too_much_data);
}
static void dgnc_wmove(struct channel_t *ch, char *buf, uint n)
{
int remain;
uint head;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
head = ch->ch_w_head & WQUEUEMASK;
remain = WQUEUESIZE - head;
if (n >= remain) {
n -= remain;
memcpy(ch->ch_wqueue + head, buf, remain);
head = 0;
buf += remain;
}
if (n > 0) {
remain = n;
memcpy(ch->ch_wqueue + head, buf, remain);
head += remain;
}
head &= WQUEUEMASK;
ch->ch_w_head = head;
}
void dgnc_input(struct channel_t *ch)
{
struct dgnc_board *bd;
struct tty_struct *tp;
struct tty_ldisc *ld;
uint rmask;
ushort head;
ushort tail;
int data_len;
ulong lock_flags;
int flip_len;
int len = 0;
int n = 0;
int s = 0;
int i = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
tp = ch->ch_tun.un_tty;
bd = ch->ch_bd;
if(!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DGNC_LOCK(ch->ch_lock, lock_flags);
rmask = RQUEUEMASK;
head = ch->ch_r_head & rmask;
tail = ch->ch_r_tail & rmask;
data_len = (head - tail) & rmask;
if (data_len == 0) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
DPR_READ(("dgnc_input start\n"));
if (!tp || (tp->magic != TTY_MAGIC) || !(ch->ch_tun.un_flags & UN_ISOPEN) ||
!(tp->termios.c_cflag & CREAD) || (ch->ch_tun.un_flags & UN_CLOSING)) {
DPR_READ(("input. dropping %d bytes on port %d...\n", data_len, ch->ch_portnum));
DPR_READ(("input. tp: %p tp->magic: %x MAGIC:%x ch flags: %x\n",
tp, tp ? tp->magic : 0, TTY_MAGIC, ch->ch_tun.un_flags));
ch->ch_r_head = tail;
dgnc_check_queue_flow_control(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if (ch->ch_flags & CH_FORCED_STOPI) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_READ(("Port %d throttled, not reading any data. head: %x tail: %x\n",
ch->ch_portnum, head, tail));
return;
}
DPR_READ(("dgnc_input start 2\n"));
flip_len = TTY_FLIPBUF_SIZE;
len = min(data_len, flip_len);
len = min(len, (N_TTY_BUF_SIZE - 1));
ld = tty_ldisc_ref(tp);
#ifdef TTY_DONT_FLIP
if (test_bit(TTY_DONT_FLIP, &tp->flags))
len = 0;
#endif
if (!ld) {
len = 0;
} else {
if (!ld->ops->receive_buf) {
ch->ch_r_head = ch->ch_r_tail;
len = 0;
}
}
if (len <= 0) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (ld)
tty_ldisc_deref(ld);
return;
}
len = tty_buffer_request_room(tp->port, len);
n = len;
while (n) {
s = ((head >= tail) ? head : RQUEUESIZE) - tail;
s = min(s, n);
if (s <= 0)
break;
if (I_PARMRK(tp) || I_BRKINT(tp) || I_INPCK(tp)) {
for (i = 0; i < s; i++) {
if (*(ch->ch_equeue + tail + i) & UART_LSR_BI)
tty_insert_flip_char(tp->port, *(ch->ch_rqueue + tail + i), TTY_BREAK);
else if (*(ch->ch_equeue + tail + i) & UART_LSR_PE)
tty_insert_flip_char(tp->port, *(ch->ch_rqueue + tail + i), TTY_PARITY);
else if (*(ch->ch_equeue + tail + i) & UART_LSR_FE)
tty_insert_flip_char(tp->port, *(ch->ch_rqueue + tail + i), TTY_FRAME);
else
tty_insert_flip_char(tp->port, *(ch->ch_rqueue + tail + i), TTY_NORMAL);
}
}
else {
tty_insert_flip_string(tp->port, ch->ch_rqueue + tail, s);
}
dgnc_sniff_nowait_nolock(ch, "USER READ", ch->ch_rqueue + tail, s);
tail += s;
n -= s;
tail &= rmask;
}
ch->ch_r_tail = tail & rmask;
ch->ch_e_tail = tail & rmask;
dgnc_check_queue_flow_control(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
tty_flip_buffer_push(tp->port);
if (ld)
tty_ldisc_deref(ld);
DPR_READ(("dgnc_input - finish\n"));
}
void dgnc_carrier(struct channel_t *ch)
{
struct dgnc_board *bd;
int virt_carrier = 0;
int phys_carrier = 0;
DPR_CARR(("dgnc_carrier called...\n"));
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
if (ch->ch_mistat & UART_MSR_DCD) {
DPR_CARR(("mistat: %x D_CD: %x\n", ch->ch_mistat, ch->ch_mistat & UART_MSR_DCD));
phys_carrier = 1;
}
if (ch->ch_digi.digi_flags & DIGI_FORCEDCD) {
virt_carrier = 1;
}
if (ch->ch_c_cflag & CLOCAL) {
virt_carrier = 1;
}
DPR_CARR(("DCD: physical: %d virt: %d\n", phys_carrier, virt_carrier));
if (((ch->ch_flags & CH_FCAR) == 0) && (virt_carrier == 1)) {
DPR_CARR(("carrier: virt DCD rose\n"));
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if (((ch->ch_flags & CH_CD) == 0) && (phys_carrier == 1)) {
DPR_CARR(("carrier: physical DCD rose\n"));
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if ((virt_carrier == 0) && ((ch->ch_flags & CH_CD) != 0) &&
(phys_carrier == 0))
{
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
if (ch->ch_tun.un_open_count > 0) {
DPR_CARR(("Sending tty hangup\n"));
tty_hangup(ch->ch_tun.un_tty);
}
if (ch->ch_pun.un_open_count > 0) {
DPR_CARR(("Sending pr hangup\n"));
tty_hangup(ch->ch_pun.un_tty);
}
}
if (virt_carrier == 1)
ch->ch_flags |= CH_FCAR;
else
ch->ch_flags &= ~CH_FCAR;
if (phys_carrier == 1)
ch->ch_flags |= CH_CD;
else
ch->ch_flags &= ~CH_CD;
}
static void dgnc_set_custom_speed(struct channel_t *ch, uint newrate)
{
int testdiv;
int testrate_high;
int testrate_low;
int deltahigh;
int deltalow;
if (newrate <= 0) {
ch->ch_custom_speed = 0;
return;
}
if (newrate && newrate < ((ch->ch_bd->bd_dividend / 0xFFFF) + 1))
newrate = ((ch->ch_bd->bd_dividend / 0xFFFF) + 1);
if (newrate && newrate > ch->ch_bd->bd_dividend)
newrate = ch->ch_bd->bd_dividend;
if (newrate > 0) {
testdiv = ch->ch_bd->bd_dividend / newrate;
testrate_high = ch->ch_bd->bd_dividend / testdiv;
testrate_low = ch->ch_bd->bd_dividend / (testdiv + 1);
if (testrate_high != newrate) {
deltahigh = testrate_high - newrate;
deltalow = newrate - testrate_low;
if (deltahigh < deltalow) {
newrate = testrate_high;
} else {
newrate = testrate_low;
}
}
}
ch->ch_custom_speed = newrate;
}
void dgnc_check_queue_flow_control(struct channel_t *ch)
{
int qleft = 0;
qleft = ch->ch_r_tail - ch->ch_r_head - 1;
if (qleft < 0)
qleft += RQUEUEMASK + 1;
if (qleft < 256) {
if (ch->ch_digi.digi_flags & CTSPACE || ch->ch_c_cflag & CRTSCTS) {
if(!(ch->ch_flags & CH_RECEIVER_OFF)) {
ch->ch_bd->bd_ops->disable_receiver(ch);
ch->ch_flags |= (CH_RECEIVER_OFF);
DPR_READ(("Internal queue hit hilevel mark (%d)! Turning off interrupts.\n",
qleft));
}
}
else if (ch->ch_c_iflag & IXOFF) {
if (ch->ch_stops_sent <= MAX_STOPS_SENT) {
ch->ch_bd->bd_ops->send_stop_character(ch);
ch->ch_stops_sent++;
DPR_READ(("Sending stop char! Times sent: %x\n", ch->ch_stops_sent));
}
}
else {
}
}
if (qleft > (RQUEUESIZE / 2)) {
if (ch->ch_digi.digi_flags & RTSPACE || ch->ch_c_cflag & CRTSCTS) {
if (ch->ch_flags & CH_RECEIVER_OFF) {
ch->ch_bd->bd_ops->enable_receiver(ch);
ch->ch_flags &= ~(CH_RECEIVER_OFF);
DPR_READ(("Internal queue hit lowlevel mark (%d)! Turning on interrupts.\n",
qleft));
}
}
else if (ch->ch_c_iflag & IXOFF && ch->ch_stops_sent) {
ch->ch_stops_sent = 0;
ch->ch_bd->bd_ops->send_start_character(ch);
DPR_READ(("Sending start char!\n"));
}
else {
}
}
}
void dgnc_wakeup_writes(struct channel_t *ch)
{
int qlen = 0;
ulong lock_flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DGNC_LOCK(ch->ch_lock, lock_flags);
qlen = ch->ch_w_head - ch->ch_w_tail;
if (qlen < 0)
qlen += WQUEUESIZE;
if (qlen >= (WQUEUESIZE - 256)) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
if (ch->ch_tun.un_flags & UN_ISOPEN) {
if ((ch->ch_tun.un_tty->flags & (1 << TTY_DO_WRITE_WAKEUP)) &&
ch->ch_tun.un_tty->ldisc->ops->write_wakeup)
{
DGNC_UNLOCK(ch->ch_lock, lock_flags);
(ch->ch_tun.un_tty->ldisc->ops->write_wakeup)(ch->ch_tun.un_tty);
DGNC_LOCK(ch->ch_lock, lock_flags);
}
wake_up_interruptible(&ch->ch_tun.un_tty->write_wait);
if (ch->ch_tun.un_flags & UN_EMPTY) {
if ((qlen == 0) && (ch->ch_bd->bd_ops->get_uart_bytes_left(ch) == 0)) {
ch->ch_tun.un_flags &= ~(UN_EMPTY);
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) {
ch->ch_mostat &= ~(UART_MCR_RTS);
ch->ch_bd->bd_ops->assert_modem_signals(ch);
}
if (ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) {
ch->ch_mostat &= ~(UART_MCR_DTR);
ch->ch_bd->bd_ops->assert_modem_signals(ch);
}
}
}
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & UN_ISOPEN) {
if ((ch->ch_pun.un_tty->flags & (1 << TTY_DO_WRITE_WAKEUP)) &&
ch->ch_pun.un_tty->ldisc->ops->write_wakeup)
{
DGNC_UNLOCK(ch->ch_lock, lock_flags);
(ch->ch_pun.un_tty->ldisc->ops->write_wakeup)(ch->ch_pun.un_tty);
DGNC_LOCK(ch->ch_lock, lock_flags);
}
wake_up_interruptible(&ch->ch_pun.un_tty->write_wait);
if (ch->ch_pun.un_flags & UN_EMPTY) {
if ((qlen == 0) && (ch->ch_bd->bd_ops->get_uart_bytes_left(ch) == 0)) {
ch->ch_pun.un_flags &= ~(UN_EMPTY);
}
}
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
static int dgnc_tty_open(struct tty_struct *tty, struct file *file)
{
struct dgnc_board *brd;
struct channel_t *ch;
struct un_t *un;
uint major = 0;
uint minor = 0;
int rc = 0;
ulong lock_flags;
rc = 0;
major = MAJOR(tty_devnum(tty));
minor = MINOR(tty_devnum(tty));
if (major > 255) {
return -ENXIO;
}
brd = dgnc_BoardsByMajor[major];
if (!brd) {
return -ENXIO;
}
rc = wait_event_interruptible(brd->state_wait,
(brd->state & BOARD_READY));
if (rc) {
return rc;
}
DGNC_LOCK(brd->bd_lock, lock_flags);
if (PORT_NUM(minor) > brd->nasync) {
DGNC_UNLOCK(brd->bd_lock, lock_flags);
return -ENXIO;
}
ch = brd->channels[PORT_NUM(minor)];
if (!ch) {
DGNC_UNLOCK(brd->bd_lock, lock_flags);
return -ENXIO;
}
DGNC_UNLOCK(brd->bd_lock, lock_flags);
DGNC_LOCK(ch->ch_lock, lock_flags);
if (!IS_PRINT(minor)) {
un = &brd->channels[PORT_NUM(minor)]->ch_tun;
un->un_type = DGNC_SERIAL;
}
else if (IS_PRINT(minor)) {
un = &brd->channels[PORT_NUM(minor)]->ch_pun;
un->un_type = DGNC_PRINT;
}
else {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("%d Unknown TYPE!\n", __LINE__));
return -ENXIO;
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = wait_event_interruptible(ch->ch_flags_wait, ((ch->ch_flags & CH_OPENING) == 0));
if (rc) {
DPR_OPEN(("%d User ctrl c'ed\n", __LINE__));
return -EINTR;
}
rc = wait_event_interruptible(ch->ch_flags_wait,
(((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_CLOSING) == 0));
if (rc) {
DPR_OPEN(("%d User ctrl c'ed\n", __LINE__));
return -EINTR;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
tty->driver_data = un;
DPR_OPEN(("Open called. MAJOR: %d MINOR:%d PORT_NUM: %x unit: %p NAME: %s\n",
MAJOR(tty_devnum(tty)), MINOR(tty_devnum(tty)), PORT_NUM(minor), un, brd->name));
DPR_OPEN(("%d: tflag=%x pflag=%x\n", __LINE__, ch->ch_tun.un_flags, ch->ch_pun.un_flags));
if (!(un->un_flags & UN_ISOPEN)) {
un->un_tty = tty;
}
ch->ch_flags |= (CH_OPENING);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (!ch->ch_rqueue)
ch->ch_rqueue = kzalloc(RQUEUESIZE, GFP_KERNEL);
if (!ch->ch_equeue)
ch->ch_equeue = kzalloc(EQUEUESIZE, GFP_KERNEL);
if (!ch->ch_wqueue)
ch->ch_wqueue = kzalloc(WQUEUESIZE, GFP_KERNEL);
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags &= ~(CH_OPENING);
wake_up_interruptible(&ch->ch_flags_wait);
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_ISOPEN)) {
DPR_OPEN(("dgnc_open: initializing channel in open...\n"));
ch->ch_r_head = ch->ch_r_tail = 0;
ch->ch_e_head = ch->ch_e_tail = 0;
ch->ch_w_head = ch->ch_w_tail = 0;
brd->bd_ops->flush_uart_write(ch);
brd->bd_ops->flush_uart_read(ch);
ch->ch_flags = 0;
ch->ch_cached_lsr = 0;
ch->ch_stop_sending_break = 0;
ch->ch_stops_sent = 0;
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
if (!(ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat |= (UART_MCR_RTS);
if (!(ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat |= (UART_MCR_DTR);
brd->bd_ops->uart_init(ch);
}
brd->bd_ops->param(tty);
dgnc_carrier(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = dgnc_block_til_ready(tty, file, ch);
if (rc) {
DPR_OPEN(("dgnc_tty_open returning after dgnc_block_til_ready "
"with %d\n", rc));
}
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_open_count++;
un->un_open_count++;
un->un_flags |= (UN_ISOPEN);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("dgnc_tty_open finished\n"));
return rc;
}
static int dgnc_block_til_ready(struct tty_struct *tty, struct file *file, struct channel_t *ch)
{
int retval = 0;
struct un_t *un = NULL;
ulong lock_flags;
uint old_flags = 0;
int sleep_on_un_flags = 0;
if (!tty || tty->magic != TTY_MAGIC || !file || !ch || ch->magic != DGNC_CHANNEL_MAGIC) {
return -ENXIO;
}
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC) {
return -ENXIO;
}
DPR_OPEN(("dgnc_block_til_ready - before block.\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_wopen++;
while (1) {
sleep_on_un_flags = 0;
if (ch->ch_bd->state == BOARD_FAILED) {
retval = -ENXIO;
break;
}
if (tty_hung_up_p(file)) {
retval = -EAGAIN;
break;
}
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_CLOSING)) {
if (file->f_flags & O_NONBLOCK) {
break;
}
if (tty->flags & (1 << TTY_IO_ERROR)) {
retval = -EIO;
break;
}
if (ch->ch_flags & CH_CD) {
DPR_OPEN(("%d: ch_flags: %x\n", __LINE__, ch->ch_flags));
break;
}
if (ch->ch_flags & CH_FCAR) {
DPR_OPEN(("%d: ch_flags: %x\n", __LINE__, ch->ch_flags));
break;
}
}
else {
sleep_on_un_flags = 1;
}
if (signal_pending(current)) {
DPR_OPEN(("%d: signal pending...\n", __LINE__));
retval = -ERESTARTSYS;
break;
}
DPR_OPEN(("dgnc_block_til_ready - blocking.\n"));
if (sleep_on_un_flags)
old_flags = ch->ch_tun.un_flags | ch->ch_pun.un_flags;
else
old_flags = ch->ch_flags;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("Going to sleep on %s flags...\n",
(sleep_on_un_flags ? "un" : "ch")));
if (sleep_on_un_flags) {
retval = wait_event_interruptible(un->un_flags_wait,
(old_flags != (ch->ch_tun.un_flags | ch->ch_pun.un_flags)));
}
else {
retval = wait_event_interruptible(ch->ch_flags_wait,
(old_flags != ch->ch_flags));
}
DPR_OPEN(("After sleep... retval: %x\n", retval));
DGNC_LOCK(ch->ch_lock, lock_flags);
}
ch->ch_wopen--;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("dgnc_block_til_ready - after blocking.\n"));
if (retval) {
DPR_OPEN(("dgnc_block_til_ready - done. error. retval: %x\n", retval));
return retval;
}
DPR_OPEN(("dgnc_block_til_ready - done no error. jiffies: %lu\n", jiffies));
return 0;
}
static void dgnc_tty_hangup(struct tty_struct *tty)
{
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
DPR_CLOSE(("dgnc_hangup called. ch->ch_open_count: %d un->un_open_count: %d\n",
un->un_ch->ch_open_count, un->un_open_count));
dgnc_tty_flush_buffer(tty);
DPR_CLOSE(("dgnc_hangup finished. ch->ch_open_count: %d un->un_open_count: %d\n",
un->un_ch->ch_open_count, un->un_open_count));
}
static void dgnc_tty_close(struct tty_struct *tty, struct file *file)
{
struct ktermios *ts;
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
int rc = 0;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
ts = &tty->termios;
DPR_CLOSE(("Close called\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
if ((tty->count == 1) && (un->un_open_count != 1)) {
APR(("tty->count is 1, un open count is %d\n", un->un_open_count));
un->un_open_count = 1;
}
if (--un->un_open_count < 0) {
APR(("bad serial port open count of %d\n", un->un_open_count));
un->un_open_count = 0;
}
ch->ch_open_count--;
if (ch->ch_open_count && un->un_open_count) {
DPR_CLOSE(("dgnc_tty_close: not last close ch: %d un:%d\n",
ch->ch_open_count, un->un_open_count));
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return;
}
DPR_CLOSE(("dgnc_tty_close - last close on unit procedures\n"));
un->un_flags |= UN_CLOSING;
tty->closing = 1;
if ((ch->ch_open_count == 0) && !(ch->ch_digi.digi_flags & DIGI_PRINTER)) {
ch->ch_flags &= ~(CH_STOPI | CH_FORCED_STOPI);
if ((un->un_type == DGNC_PRINT) && (ch->ch_flags & CH_PRON) ) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_CLOSE(("Calling wait_for_drain\n"));
rc = bd->bd_ops->drain(tty, 0);
DPR_CLOSE(("After calling wait_for_drain\n"));
if (rc) {
DPR_BASIC(("dgnc_tty_close - bad return: %d ", rc));
}
dgnc_tty_flush_buffer(tty);
tty_ldisc_flush(tty);
DGNC_LOCK(ch->ch_lock, lock_flags);
tty->closing = 0;
if (ch->ch_c_cflag & HUPCL) {
DPR_CLOSE(("Close. HUPCL set, dropping DTR/RTS\n"));
ch->ch_mostat &= ~(UART_MCR_DTR | UART_MCR_RTS);
bd->bd_ops->assert_modem_signals(ch);
if (ch->ch_close_delay) {
DPR_CLOSE(("Close. Sleeping for RTS/DTR drop\n"));
DGNC_UNLOCK(ch->ch_lock, lock_flags);
dgnc_ms_sleep(ch->ch_close_delay);
DGNC_LOCK(ch->ch_lock, lock_flags);
DPR_CLOSE(("Close. After sleeping for RTS/DTR drop\n"));
}
}
ch->ch_old_baud = 0;
ch->ch_bd->bd_ops->uart_off(ch);
}
else {
if ((un->un_type == DGNC_PRINT) && (ch->ch_flags & CH_PRON) ) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
}
un->un_tty = NULL;
un->un_flags &= ~(UN_ISOPEN | UN_CLOSING);
DPR_CLOSE(("Close. Doing wakeups\n"));
wake_up_interruptible(&ch->ch_flags_wait);
wake_up_interruptible(&un->un_flags_wait);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_BASIC(("dgnc_tty_close - complete\n"));
}
static int dgnc_tty_chars_in_buffer(struct tty_struct *tty)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
ushort thead;
ushort ttail;
uint tmask;
uint chars = 0;
ulong lock_flags = 0;
if (tty == NULL)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
DGNC_LOCK(ch->ch_lock, lock_flags);
tmask = WQUEUEMASK;
thead = ch->ch_w_head & tmask;
ttail = ch->ch_w_tail & tmask;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (ttail == thead) {
chars = 0;
} else {
if (thead >= ttail)
chars = thead - ttail;
else
chars = thead - ttail + WQUEUESIZE;
}
DPR_WRITE(("dgnc_tty_chars_in_buffer. Port: %x - %d (head: %d tail: %d)\n",
ch->ch_portnum, chars, thead, ttail));
return chars;
}
static int dgnc_maxcps_room(struct tty_struct *tty, int bytes_available)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
if (!tty)
return bytes_available;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return bytes_available;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return bytes_available;
if (un->un_type != DGNC_PRINT)
return bytes_available;
if (ch->ch_digi.digi_maxcps > 0 && ch->ch_digi.digi_bufsize > 0 ) {
int cps_limit = 0;
unsigned long current_time = jiffies;
unsigned long buffer_time = current_time +
(HZ * ch->ch_digi.digi_bufsize) / ch->ch_digi.digi_maxcps;
if (ch->ch_cpstime < current_time) {
ch->ch_cpstime = current_time;
cps_limit = ch->ch_digi.digi_bufsize;
}
else if (ch->ch_cpstime < buffer_time) {
cps_limit = ((buffer_time - ch->ch_cpstime) * ch->ch_digi.digi_maxcps) / HZ;
}
else {
cps_limit = 0;
}
bytes_available = min(cps_limit, bytes_available);
}
return bytes_available;
}
static int dgnc_tty_write_room(struct tty_struct *tty)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
ushort head;
ushort tail;
ushort tmask;
int ret = 0;
ulong lock_flags = 0;
if (tty == NULL || dgnc_TmpWriteBuf == NULL)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
DGNC_LOCK(ch->ch_lock, lock_flags);
tmask = WQUEUEMASK;
head = (ch->ch_w_head) & tmask;
tail = (ch->ch_w_tail) & tmask;
ret = tail - head - 1;
if (ret < 0)
ret += WQUEUESIZE;
ret = dgnc_maxcps_room(tty, ret);
if (un->un_type == DGNC_PRINT) {
if (!(ch->ch_flags & CH_PRON))
ret -= ch->ch_digi.digi_onlen;
ret -= ch->ch_digi.digi_offlen;
}
else {
if (ch->ch_flags & CH_PRON)
ret -= ch->ch_digi.digi_offlen;
}
if (ret < 0)
ret = 0;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_WRITE(("dgnc_tty_write_room - %d tail: %d head: %d\n", ret, tail, head));
return ret;
}
static int dgnc_tty_put_char(struct tty_struct *tty, unsigned char c)
{
DPR_WRITE(("dgnc_tty_put_char called\n"));
dgnc_tty_write(tty, &c, 1);
return 1;
}
static int dgnc_tty_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
int bufcount = 0, n = 0;
int orig_count = 0;
ulong lock_flags;
ushort head;
ushort tail;
ushort tmask;
uint remain;
int from_user = 0;
if (tty == NULL || dgnc_TmpWriteBuf == NULL)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
if (!count)
return 0;
DPR_WRITE(("dgnc_tty_write: Port: %x tty=%p user=%d len=%d\n",
ch->ch_portnum, tty, from_user, count));
orig_count = count;
DGNC_LOCK(ch->ch_lock, lock_flags);
tmask = WQUEUEMASK;
head = (ch->ch_w_head) & tmask;
tail = (ch->ch_w_tail) & tmask;
bufcount = tail - head - 1;
if (bufcount < 0)
bufcount += WQUEUESIZE;
DPR_WRITE(("%d: bufcount: %x count: %x tail: %x head: %x tmask: %x\n",
__LINE__, bufcount, count, tail, head, tmask));
bufcount = dgnc_maxcps_room(tty, bufcount);
count = min(count, bufcount);
if (count <= 0) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
}
if ((un->un_type == DGNC_PRINT) && !(ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_onstr,
(int) ch->ch_digi.digi_onlen);
head = (ch->ch_w_head) & tmask;
ch->ch_flags |= CH_PRON;
}
if ((un->un_type != DGNC_PRINT) && (ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = (ch->ch_w_head) & tmask;
ch->ch_flags &= ~CH_PRON;
}
if (count <= 0) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
}
if (from_user) {
count = min(count, WRITEBUFLEN);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (down_interruptible(&dgnc_TmpWriteSem)) {
return -EINTR;
}
count -= copy_from_user(dgnc_TmpWriteBuf, (const uchar __user *) buf, count);
if (!count) {
up(&dgnc_TmpWriteSem);
return -EFAULT;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
buf = dgnc_TmpWriteBuf;
}
n = count;
remain = WQUEUESIZE - head;
if (n >= remain) {
n -= remain;
memcpy(ch->ch_wqueue + head, buf, remain);
dgnc_sniff_nowait_nolock(ch, "USER WRITE", ch->ch_wqueue + head, remain);
head = 0;
buf += remain;
}
if (n > 0) {
remain = n;
memcpy(ch->ch_wqueue + head, buf, remain);
dgnc_sniff_nowait_nolock(ch, "USER WRITE", ch->ch_wqueue + head, remain);
head += remain;
}
if (count) {
head &= tmask;
ch->ch_w_head = head;
}
#if 0
if (count == orig_count) {
if ((un->un_type == DGNC_PRINT) && (ch->ch_flags & CH_PRON)) {
head &= tmask;
ch->ch_w_head = head;
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = (ch->ch_w_head) & tmask;
ch->ch_flags &= ~CH_PRON;
}
}
#endif
if ((un->un_type == DGNC_PRINT) && (ch->ch_digi.digi_maxcps > 0)
&& (ch->ch_digi.digi_bufsize > 0)) {
ch->ch_cpstime += (HZ * count) / ch->ch_digi.digi_maxcps;
}
if (from_user) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
up(&dgnc_TmpWriteSem);
} else {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
DPR_WRITE(("Write finished - Write %d bytes of %d.\n", count, orig_count));
if (count) {
ch->ch_bd->bd_ops->copy_data_from_queue_to_uart(ch);
}
return count;
}
static int dgnc_tty_tiocmget(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
int result = -EIO;
uchar mstat = 0;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return result;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return result;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return result;
DPR_IOCTL(("dgnc_tty_tiocmget start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
mstat = (ch->ch_mostat | ch->ch_mistat);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
result = 0;
if (mstat & UART_MCR_DTR)
result |= TIOCM_DTR;
if (mstat & UART_MCR_RTS)
result |= TIOCM_RTS;
if (mstat & UART_MSR_CTS)
result |= TIOCM_CTS;
if (mstat & UART_MSR_DSR)
result |= TIOCM_DSR;
if (mstat & UART_MSR_RI)
result |= TIOCM_RI;
if (mstat & UART_MSR_DCD)
result |= TIOCM_CD;
DPR_IOCTL(("dgnc_tty_tiocmget finish\n"));
return result;
}
static int dgnc_tty_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -EIO;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return ret;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return ret;
DPR_IOCTL(("dgnc_tty_tiocmset start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
if (set & TIOCM_RTS) {
ch->ch_mostat |= UART_MCR_RTS;
}
if (set & TIOCM_DTR) {
ch->ch_mostat |= UART_MCR_DTR;
}
if (clear & TIOCM_RTS) {
ch->ch_mostat &= ~(UART_MCR_RTS);
}
if (clear & TIOCM_DTR) {
ch->ch_mostat &= ~(UART_MCR_DTR);
}
ch->ch_bd->bd_ops->assert_modem_signals(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_tiocmset finish\n"));
return 0;
}
static int dgnc_tty_send_break(struct tty_struct *tty, int msec)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -EIO;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return ret;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return ret;
switch (msec) {
case -1:
msec = 0xFFFF;
break;
case 0:
msec = 0;
break;
default:
break;
}
DPR_IOCTL(("dgnc_tty_send_break start 1. %lx\n", jiffies));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_bd->bd_ops->send_break(ch, msec);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_send_break finish\n"));
return 0;
}
static void dgnc_tty_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int rc;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
rc = bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return;
}
return;
}
static void dgnc_tty_send_xchar(struct tty_struct *tty, char c)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_send_xchar start\n"));
printk("dgnc_tty_send_xchar start\n");
DGNC_LOCK(ch->ch_lock, lock_flags);
bd->bd_ops->send_immediate_char(ch, c);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_send_xchar finish\n"));
printk("dgnc_tty_send_xchar finish\n");
return;
}
static inline int dgnc_get_mstat(struct channel_t *ch)
{
unsigned char mstat;
int result = -EIO;
ulong lock_flags;
DPR_IOCTL(("dgnc_getmstat start\n"));
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
DGNC_LOCK(ch->ch_lock, lock_flags);
mstat = (ch->ch_mostat | ch->ch_mistat);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
result = 0;
if (mstat & UART_MCR_DTR)
result |= TIOCM_DTR;
if (mstat & UART_MCR_RTS)
result |= TIOCM_RTS;
if (mstat & UART_MSR_CTS)
result |= TIOCM_CTS;
if (mstat & UART_MSR_DSR)
result |= TIOCM_DSR;
if (mstat & UART_MSR_RI)
result |= TIOCM_RI;
if (mstat & UART_MSR_DCD)
result |= TIOCM_CD;
DPR_IOCTL(("dgnc_getmstat finish\n"));
return result;
}
static int dgnc_get_modem_info(struct channel_t *ch, unsigned int __user *value)
{
int result;
int rc;
DPR_IOCTL(("dgnc_get_modem_info start\n"));
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
result = dgnc_get_mstat(ch);
if (result < 0)
return -ENXIO;
rc = put_user(result, value);
DPR_IOCTL(("dgnc_get_modem_info finish\n"));
return rc;
}
static int dgnc_set_modem_info(struct tty_struct *tty, unsigned int command, unsigned int __user *value)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -ENXIO;
unsigned int arg = 0;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return ret;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return ret;
ret = 0;
DPR_IOCTL(("dgnc_set_modem_info() start\n"));
ret = get_user(arg, value);
if (ret)
return ret;
switch (command) {
case TIOCMBIS:
if (arg & TIOCM_RTS) {
ch->ch_mostat |= UART_MCR_RTS;
}
if (arg & TIOCM_DTR) {
ch->ch_mostat |= UART_MCR_DTR;
}
break;
case TIOCMBIC:
if (arg & TIOCM_RTS) {
ch->ch_mostat &= ~(UART_MCR_RTS);
}
if (arg & TIOCM_DTR) {
ch->ch_mostat &= ~(UART_MCR_DTR);
}
break;
case TIOCMSET:
if (arg & TIOCM_RTS) {
ch->ch_mostat |= UART_MCR_RTS;
}
else {
ch->ch_mostat &= ~(UART_MCR_RTS);
}
if (arg & TIOCM_DTR) {
ch->ch_mostat |= UART_MCR_DTR;
}
else {
ch->ch_mostat &= ~(UART_MCR_DTR);
}
break;
default:
return -EINVAL;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_bd->bd_ops->assert_modem_signals(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_set_modem_info finish\n"));
return 0;
}
static int dgnc_tty_digigeta(struct tty_struct *tty, struct digi_t __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
struct digi_t tmp;
ulong lock_flags;
if (!retinfo)
return -EFAULT;
if (!tty || tty->magic != TTY_MAGIC)
return -EFAULT;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -EFAULT;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
DGNC_LOCK(ch->ch_lock, lock_flags);
memcpy(&tmp, &ch->ch_digi, sizeof(tmp));
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgnc_tty_digiseta(struct tty_struct *tty, struct digi_t __user *new_info)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
struct digi_t new_digi;
ulong lock_flags;
DPR_IOCTL(("DIGI_SETA start\n"));
if (!tty || tty->magic != TTY_MAGIC)
return -EFAULT;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -EFAULT;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -EFAULT;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return -EFAULT;
if (copy_from_user(&new_digi, new_info, sizeof(new_digi))) {
DPR_IOCTL(("DIGI_SETA failed copy_from_user\n"));
return -EFAULT;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
if (!(ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) && (new_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat &= ~(UART_MCR_RTS);
if ((ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) && !(new_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat |= (UART_MCR_RTS);
if (!(ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) && (new_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat &= ~(UART_MCR_DTR);
if ((ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) && !(new_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat |= (UART_MCR_DTR);
memcpy(&ch->ch_digi, &new_digi, sizeof(new_digi));
if (ch->ch_digi.digi_maxcps < 1)
ch->ch_digi.digi_maxcps = 1;
if (ch->ch_digi.digi_maxcps > 10000)
ch->ch_digi.digi_maxcps = 10000;
if (ch->ch_digi.digi_bufsize < 10)
ch->ch_digi.digi_bufsize = 10;
if (ch->ch_digi.digi_maxchar < 1)
ch->ch_digi.digi_maxchar = 1;
if (ch->ch_digi.digi_maxchar > ch->ch_digi.digi_bufsize)
ch->ch_digi.digi_maxchar = ch->ch_digi.digi_bufsize;
if (ch->ch_digi.digi_onlen > DIGI_PLEN)
ch->ch_digi.digi_onlen = DIGI_PLEN;
if (ch->ch_digi.digi_offlen > DIGI_PLEN)
ch->ch_digi.digi_offlen = DIGI_PLEN;
ch->ch_bd->bd_ops->param(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("DIGI_SETA finish\n"));
return 0;
}
static void dgnc_tty_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
ch->ch_bd->bd_ops->param(tty);
dgnc_carrier(ch);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
}
static void dgnc_tty_throttle(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
ulong lock_flags = 0;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_throttle start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= (CH_FORCED_STOPI);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_throttle finish\n"));
}
static void dgnc_tty_unthrottle(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_unthrottle start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags &= ~(CH_FORCED_STOPI);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_unthrottle finish\n"));
}
static void dgnc_tty_start(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DPR_IOCTL(("dgcn_tty_start start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags &= ~(CH_FORCED_STOP);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_start finish\n"));
}
static void dgnc_tty_stop(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_stop start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags |= (CH_FORCED_STOP);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_stop finish\n"));
}
static void dgnc_tty_flush_chars(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_flush_chars start\n"));
DGNC_LOCK(ch->ch_lock, lock_flags);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_flush_chars finish\n"));
}
static void dgnc_tty_flush_buffer(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
DPR_IOCTL(("dgnc_tty_flush_buffer on port: %d start\n", ch->ch_portnum));
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_flags &= ~CH_STOP;
ch->ch_w_head = ch->ch_w_tail;
ch->ch_bd->bd_ops->flush_uart_write(ch);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_flush_buffer finish\n"));
}
static int dgnc_tty_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int rc;
ulong lock_flags;
void __user *uarg = (void __user *) arg;
if (!tty || tty->magic != TTY_MAGIC)
return -ENODEV;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -ENODEV;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENODEV;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return -ENODEV;
DPR_IOCTL(("dgnc_tty_ioctl start on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgnc_ioctl_name(cmd), cmd, arg));
DGNC_LOCK(ch->ch_lock, lock_flags);
if (un->un_open_count <= 0) {
DPR_BASIC(("dgnc_tty_ioctl - unit not open.\n"));
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return -EIO;
}
switch (cmd) {
case TCSBRK:
rc = tty_check_change(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (rc) {
return rc;
}
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return -EINTR;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
if(((cmd == TCSBRK) && (!arg)) || (cmd == TCSBRKP)) {
ch->ch_bd->bd_ops->send_break(ch, 250);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgnc_ioctl_name(cmd), cmd, arg));
return 0;
case TCSBRKP:
rc = tty_check_change(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (rc) {
return rc;
}
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return -EINTR;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_bd->bd_ops->send_break(ch, 250);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgnc_ioctl_name(cmd), cmd, arg));
return 0;
case TIOCSBRK:
rc = tty_check_change(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (rc) {
return rc;
}
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return -EINTR;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_bd->bd_ops->send_break(ch, 250);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgnc_ioctl_name(cmd), cmd, arg));
return 0;
case TIOCCBRK:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
case TIOCGSOFTCAR:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = put_user(C_CLOCAL(tty) ? 1 : 0, (unsigned long __user *) arg);
return rc;
case TIOCSSOFTCAR:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = get_user(arg, (unsigned long __user *) arg);
if (rc)
return rc;
DGNC_LOCK(ch->ch_lock, lock_flags);
tty->termios.c_cflag = ((tty->termios.c_cflag & ~CLOCAL) | (arg ? CLOCAL : 0));
ch->ch_bd->bd_ops->param(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
case TIOCMGET:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return dgnc_get_modem_info(ch, uarg);
case TIOCMBIS:
case TIOCMBIC:
case TIOCMSET:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return dgnc_set_modem_info(tty, cmd, uarg);
case TCFLSH:
rc = tty_check_change(tty);
if (rc) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return rc;
}
if ((arg == TCIFLUSH) || (arg == TCIOFLUSH)) {
ch->ch_r_head = ch->ch_r_tail;
ch->ch_bd->bd_ops->flush_uart_read(ch);
dgnc_check_queue_flow_control(ch);
}
if ((arg == TCOFLUSH) || (arg == TCIOFLUSH)) {
if (!(un->un_type == DGNC_PRINT)) {
ch->ch_w_head = ch->ch_w_tail;
ch->ch_bd->bd_ops->flush_uart_write(ch);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
}
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return -ENOIOCTLCMD;
case TCSETSF:
case TCSETSW:
if (cmd == TCSETSF) {
ch->ch_flags &= ~CH_STOP;
ch->ch_r_head = ch->ch_r_tail;
ch->ch_bd->bd_ops->flush_uart_read(ch);
dgnc_check_queue_flow_control(ch);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d\n", rc));
return -EINTR;
}
DPR_IOCTL(("dgnc_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgnc_ioctl_name(cmd), cmd, arg));
return -ENOIOCTLCMD;
case TCSETAW:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return -EINTR;
}
return -ENOIOCTLCMD;
case TCXONC:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return -ENOIOCTLCMD;
case DIGI_GETA:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return dgnc_tty_digigeta(tty, uarg);
case DIGI_SETAW:
case DIGI_SETAF:
if (cmd == (DIGI_SETAW)) {
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = ch->ch_bd->bd_ops->drain(tty, 0);
if (rc) {
DPR_IOCTL(("dgnc_tty_ioctl - bad return: %d ", rc));
return -EINTR;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
}
else {
tty_ldisc_flush(tty);
}
case DIGI_SETA:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return dgnc_tty_digiseta(tty, uarg);
case DIGI_LOOPBACK:
{
uint loopback = 0;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = get_user(loopback, (unsigned int __user *) arg);
if (rc)
return rc;
DGNC_LOCK(ch->ch_lock, lock_flags);
if (loopback)
ch->ch_flags |= CH_LOOPBACK;
else
ch->ch_flags &= ~(CH_LOOPBACK);
ch->ch_bd->bd_ops->param(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
}
case DIGI_GETCUSTOMBAUD:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = put_user(ch->ch_custom_speed, (unsigned int __user *) arg);
return rc;
case DIGI_SETCUSTOMBAUD:
{
int new_rate;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = get_user(new_rate, (int __user *) arg);
if (rc)
return rc;
DGNC_LOCK(ch->ch_lock, lock_flags);
dgnc_set_custom_speed(ch, new_rate);
ch->ch_bd->bd_ops->param(tty);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
}
case DIGI_REALPORT_SENDIMMEDIATE:
{
unsigned char c;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = get_user(c, (unsigned char __user *) arg);
if (rc)
return rc;
DGNC_LOCK(ch->ch_lock, lock_flags);
ch->ch_bd->bd_ops->send_immediate_char(ch, c);
DGNC_UNLOCK(ch->ch_lock, lock_flags);
return 0;
}
case DIGI_REALPORT_GETCOUNTERS:
{
struct digi_getcounter buf;
buf.norun = ch->ch_err_overrun;
buf.noflow = 0;
buf.nframe = ch->ch_err_frame;
buf.nparity = ch->ch_err_parity;
buf.nbreak = ch->ch_err_break;
buf.rbytes = ch->ch_rxcount;
buf.tbytes = ch->ch_txcount;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(uarg, &buf, sizeof(buf))) {
return -EFAULT;
}
return 0;
}
case DIGI_REALPORT_GETEVENTS:
{
unsigned int events = 0;
if (ch->ch_flags & CH_BREAK_SENDING)
events |= EV_TXB;
if ((ch->ch_flags & CH_STOP) || (ch->ch_flags & CH_FORCED_STOP)) {
events |= (EV_OPU | EV_OPS);
}
if ((ch->ch_flags & CH_STOPI) || (ch->ch_flags & CH_FORCED_STOPI)) {
events |= (EV_IPU | EV_IPS);
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
rc = put_user(events, (unsigned int __user *) arg);
return rc;
}
case DIGI_REALPORT_GETBUFFERS:
{
struct digi_getbuffer buf;
int tdist;
int count;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (copy_from_user(&buf, uarg, sizeof(buf))) {
return -EFAULT;
}
DGNC_LOCK(ch->ch_lock, lock_flags);
buf.rxbuf = (ch->ch_r_head - ch->ch_r_tail) & RQUEUEMASK;
buf.txbuf = (ch->ch_w_head - ch->ch_w_tail) & WQUEUEMASK;
count = buf.txbuf + ch->ch_bd->bd_ops->get_uart_bytes_left(ch);
tdist = (buf.tIn - buf.tOut) & 0xffff;
if (buf.txbuf > tdist) {
buf.txbuf = tdist;
}
if (count) {
buf.txdone = 0;
} else {
buf.txdone = 1;
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(uarg, &buf, sizeof(buf))) {
return -EFAULT;
}
return 0;
}
default:
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_ioctl - in default\n"));
DPR_IOCTL(("dgnc_tty_ioctl end - cmd %s (%x), arg %lx\n",
dgnc_ioctl_name(cmd), cmd, arg));
return -ENOIOCTLCMD;
}
DGNC_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("dgnc_tty_ioctl end - cmd %s (%x), arg %lx\n",
dgnc_ioctl_name(cmd), cmd, arg));
return 0;
}
