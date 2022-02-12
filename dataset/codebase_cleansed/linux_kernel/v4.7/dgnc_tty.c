int dgnc_tty_preinit(void)
{
dgnc_TmpWriteBuf = kmalloc(WRITEBUFLEN, GFP_KERNEL);
if (!dgnc_TmpWriteBuf)
return -ENOMEM;
return 0;
}
int dgnc_tty_register(struct dgnc_board *brd)
{
int rc;
brd->serial_driver = tty_alloc_driver(brd->maxports,
TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
if (IS_ERR(brd->serial_driver))
return PTR_ERR(brd->serial_driver);
snprintf(brd->serial_name, MAXTTYNAMELEN, "tty_dgnc_%d_", brd->boardnum);
brd->serial_driver->name = brd->serial_name;
brd->serial_driver->name_base = 0;
brd->serial_driver->major = 0;
brd->serial_driver->minor_start = 0;
brd->serial_driver->type = TTY_DRIVER_TYPE_SERIAL;
brd->serial_driver->subtype = SERIAL_TYPE_NORMAL;
brd->serial_driver->init_termios = DgncDefaultTermios;
brd->serial_driver->driver_name = DRVSTR;
tty_set_operations(brd->serial_driver, &dgnc_tty_ops);
if (!brd->dgnc_major_serial_registered) {
rc = tty_register_driver(brd->serial_driver);
if (rc < 0) {
dev_dbg(&brd->pdev->dev,
"Can't register tty device (%d)\n", rc);
goto free_serial_driver;
}
brd->dgnc_major_serial_registered = true;
}
brd->print_driver = tty_alloc_driver(brd->maxports,
TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
if (IS_ERR(brd->print_driver)) {
rc = PTR_ERR(brd->print_driver);
goto unregister_serial_driver;
}
snprintf(brd->print_name, MAXTTYNAMELEN, "pr_dgnc_%d_", brd->boardnum);
brd->print_driver->name = brd->print_name;
brd->print_driver->name_base = 0;
brd->print_driver->major = brd->serial_driver->major;
brd->print_driver->minor_start = 0x80;
brd->print_driver->type = TTY_DRIVER_TYPE_SERIAL;
brd->print_driver->subtype = SERIAL_TYPE_NORMAL;
brd->print_driver->init_termios = DgncDefaultTermios;
brd->print_driver->driver_name = DRVSTR;
tty_set_operations(brd->print_driver, &dgnc_tty_ops);
if (!brd->dgnc_major_transparent_print_registered) {
rc = tty_register_driver(brd->print_driver);
if (rc < 0) {
dev_dbg(&brd->pdev->dev,
"Can't register Transparent Print device(%d)\n",
rc);
goto free_print_driver;
}
brd->dgnc_major_transparent_print_registered = true;
}
dgnc_BoardsByMajor[brd->serial_driver->major] = brd;
return 0;
free_print_driver:
put_tty_driver(brd->print_driver);
unregister_serial_driver:
tty_unregister_driver(brd->serial_driver);
free_serial_driver:
put_tty_driver(brd->serial_driver);
return rc;
}
int dgnc_tty_init(struct dgnc_board *brd)
{
int i;
void __iomem *vaddr;
struct channel_t *ch;
if (!brd)
return -ENXIO;
vaddr = brd->re_map_membase;
brd->nasync = brd->maxports;
for (i = 0; i < brd->nasync; i++) {
brd->channels[i] = kzalloc(sizeof(*brd->channels[i]),
GFP_KERNEL);
if (!brd->channels[i])
goto err_free_channels;
}
ch = brd->channels[0];
vaddr = brd->re_map_membase;
for (i = 0; i < brd->nasync; i++, ch = brd->channels[i]) {
spin_lock_init(&ch->ch_lock);
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
{
struct device *classp;
classp = tty_register_device(brd->serial_driver, i,
&ch->ch_bd->pdev->dev);
ch->ch_tun.un_sysfs = classp;
dgnc_create_tty_sysfs(&ch->ch_tun, classp);
classp = tty_register_device(brd->print_driver, i,
&ch->ch_bd->pdev->dev);
ch->ch_pun.un_sysfs = classp;
dgnc_create_tty_sysfs(&ch->ch_pun, classp);
}
}
return 0;
err_free_channels:
for (i = i - 1; i >= 0; --i) {
kfree(brd->channels[i]);
brd->channels[i] = NULL;
}
return -ENOMEM;
}
void dgnc_tty_post_uninit(void)
{
kfree(dgnc_TmpWriteBuf);
dgnc_TmpWriteBuf = NULL;
}
void dgnc_tty_uninit(struct dgnc_board *brd)
{
int i = 0;
if (brd->dgnc_major_serial_registered) {
dgnc_BoardsByMajor[brd->serial_driver->major] = NULL;
for (i = 0; i < brd->nasync; i++) {
if (brd->channels[i])
dgnc_remove_tty_sysfs(brd->channels[i]->
ch_tun.un_sysfs);
tty_unregister_device(brd->serial_driver, i);
}
tty_unregister_driver(brd->serial_driver);
brd->dgnc_major_serial_registered = false;
}
if (brd->dgnc_major_transparent_print_registered) {
dgnc_BoardsByMajor[brd->print_driver->major] = NULL;
for (i = 0; i < brd->nasync; i++) {
if (brd->channels[i])
dgnc_remove_tty_sysfs(brd->channels[i]->
ch_pun.un_sysfs);
tty_unregister_device(brd->print_driver, i);
}
tty_unregister_driver(brd->print_driver);
brd->dgnc_major_transparent_print_registered = false;
}
put_tty_driver(brd->serial_driver);
put_tty_driver(brd->print_driver);
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
struct tty_ldisc *ld = NULL;
uint rmask;
ushort head;
ushort tail;
int data_len;
unsigned long flags;
int flip_len;
int len = 0;
int n = 0;
int s = 0;
int i = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
tp = ch->ch_tun.un_tty;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
rmask = RQUEUEMASK;
head = ch->ch_r_head & rmask;
tail = ch->ch_r_tail & rmask;
data_len = (head - tail) & rmask;
if (data_len == 0)
goto exit_unlock;
if (!tp || (tp->magic != TTY_MAGIC) ||
!(ch->ch_tun.un_flags & UN_ISOPEN) ||
!C_CREAD(tp) ||
(ch->ch_tun.un_flags & UN_CLOSING)) {
ch->ch_r_head = tail;
dgnc_check_queue_flow_control(ch);
goto exit_unlock;
}
if (ch->ch_flags & CH_FORCED_STOPI)
goto exit_unlock;
flip_len = TTY_FLIPBUF_SIZE;
len = min(data_len, flip_len);
len = min(len, (N_TTY_BUF_SIZE - 1));
ld = tty_ldisc_ref(tp);
if (!ld) {
len = 0;
} else {
if (!ld->ops->receive_buf) {
ch->ch_r_head = ch->ch_r_tail;
len = 0;
}
}
if (len <= 0)
goto exit_unlock;
len = tty_buffer_request_room(tp->port, len);
n = len;
while (n) {
unsigned char *ch_pos = ch->ch_equeue + tail;
s = ((head >= tail) ? head : RQUEUESIZE) - tail;
s = min(s, n);
if (s <= 0)
break;
if (I_PARMRK(tp) || I_BRKINT(tp) || I_INPCK(tp)) {
for (i = 0; i < s; i++) {
unsigned char ch = *(ch_pos + i);
char flag = TTY_NORMAL;
if (ch & UART_LSR_BI)
flag = TTY_BREAK;
else if (ch & UART_LSR_PE)
flag = TTY_PARITY;
else if (ch & UART_LSR_FE)
flag = TTY_FRAME;
tty_insert_flip_char(tp->port, ch, flag);
}
} else {
tty_insert_flip_string(tp->port, ch_pos, s);
}
tail += s;
n -= s;
tail &= rmask;
}
ch->ch_r_tail = tail & rmask;
ch->ch_e_tail = tail & rmask;
dgnc_check_queue_flow_control(ch);
spin_unlock_irqrestore(&ch->ch_lock, flags);
tty_flip_buffer_push(tp->port);
if (ld)
tty_ldisc_deref(ld);
return;
exit_unlock:
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (ld)
tty_ldisc_deref(ld);
}
void dgnc_carrier(struct channel_t *ch)
{
struct dgnc_board *bd;
int virt_carrier = 0;
int phys_carrier = 0;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return;
if (ch->ch_mistat & UART_MSR_DCD)
phys_carrier = 1;
if (ch->ch_digi.digi_flags & DIGI_FORCEDCD)
virt_carrier = 1;
if (ch->ch_c_cflag & CLOCAL)
virt_carrier = 1;
if (((ch->ch_flags & CH_FCAR) == 0) && (virt_carrier == 1)) {
if (waitqueue_active(&ch->ch_flags_wait))
wake_up_interruptible(&ch->ch_flags_wait);
}
if (((ch->ch_flags & CH_CD) == 0) && (phys_carrier == 1)) {
if (waitqueue_active(&ch->ch_flags_wait))
wake_up_interruptible(&ch->ch_flags_wait);
}
if ((virt_carrier == 0) && ((ch->ch_flags & CH_CD) != 0) &&
(phys_carrier == 0)) {
if (waitqueue_active(&ch->ch_flags_wait))
wake_up_interruptible(&ch->ch_flags_wait);
if (ch->ch_tun.un_open_count > 0)
tty_hangup(ch->ch_tun.un_tty);
if (ch->ch_pun.un_open_count > 0)
tty_hangup(ch->ch_pun.un_tty);
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
newrate = (ch->ch_bd->bd_dividend / 0xFFFF) + 1;
if (newrate && newrate > ch->ch_bd->bd_dividend)
newrate = ch->ch_bd->bd_dividend;
if (newrate > 0) {
testdiv = ch->ch_bd->bd_dividend / newrate;
testrate_high = ch->ch_bd->bd_dividend / testdiv;
testrate_low = ch->ch_bd->bd_dividend / (testdiv + 1);
if (testrate_high != newrate) {
deltahigh = testrate_high - newrate;
deltalow = newrate - testrate_low;
if (deltahigh < deltalow)
newrate = testrate_high;
else
newrate = testrate_low;
}
}
ch->ch_custom_speed = newrate;
}
void dgnc_check_queue_flow_control(struct channel_t *ch)
{
int qleft;
qleft = ch->ch_r_tail - ch->ch_r_head - 1;
if (qleft < 0)
qleft += RQUEUEMASK + 1;
if (qleft < 256) {
if (ch->ch_digi.digi_flags & CTSPACE ||
ch->ch_c_cflag & CRTSCTS) {
if (!(ch->ch_flags & CH_RECEIVER_OFF)) {
ch->ch_bd->bd_ops->disable_receiver(ch);
ch->ch_flags |= (CH_RECEIVER_OFF);
}
}
else if (ch->ch_c_iflag & IXOFF) {
if (ch->ch_stops_sent <= MAX_STOPS_SENT) {
ch->ch_bd->bd_ops->send_stop_character(ch);
ch->ch_stops_sent++;
}
}
}
if (qleft > (RQUEUESIZE / 2)) {
if (ch->ch_digi.digi_flags & RTSPACE ||
ch->ch_c_cflag & CRTSCTS) {
if (ch->ch_flags & CH_RECEIVER_OFF) {
ch->ch_bd->bd_ops->enable_receiver(ch);
ch->ch_flags &= ~(CH_RECEIVER_OFF);
}
}
else if (ch->ch_c_iflag & IXOFF && ch->ch_stops_sent) {
ch->ch_stops_sent = 0;
ch->ch_bd->bd_ops->send_start_character(ch);
}
}
}
void dgnc_wakeup_writes(struct channel_t *ch)
{
int qlen = 0;
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
qlen = ch->ch_w_head - ch->ch_w_tail;
if (qlen < 0)
qlen += WQUEUESIZE;
if (qlen >= (WQUEUESIZE - 256)) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return;
}
if (ch->ch_tun.un_flags & UN_ISOPEN) {
tty_wakeup(ch->ch_tun.un_tty);
if (ch->ch_tun.un_flags & UN_EMPTY) {
if ((qlen == 0) &&
(ch->ch_bd->bd_ops->get_uart_bytes_left(ch) == 0)) {
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
tty_wakeup(ch->ch_pun.un_tty);
if (ch->ch_pun.un_flags & UN_EMPTY) {
if ((qlen == 0) &&
(ch->ch_bd->bd_ops->get_uart_bytes_left(ch) == 0))
ch->ch_pun.un_flags &= ~(UN_EMPTY);
}
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static int dgnc_tty_open(struct tty_struct *tty, struct file *file)
{
struct dgnc_board *brd;
struct channel_t *ch;
struct un_t *un;
uint major = 0;
uint minor = 0;
int rc = 0;
unsigned long flags;
rc = 0;
major = MAJOR(tty_devnum(tty));
minor = MINOR(tty_devnum(tty));
if (major > 255)
return -ENXIO;
brd = dgnc_BoardsByMajor[major];
if (!brd)
return -ENXIO;
rc = wait_event_interruptible(brd->state_wait,
(brd->state & BOARD_READY));
if (rc)
return rc;
spin_lock_irqsave(&brd->bd_lock, flags);
if (PORT_NUM(minor) >= brd->nasync) {
spin_unlock_irqrestore(&brd->bd_lock, flags);
return -ENXIO;
}
ch = brd->channels[PORT_NUM(minor)];
if (!ch) {
spin_unlock_irqrestore(&brd->bd_lock, flags);
return -ENXIO;
}
spin_unlock_irqrestore(&brd->bd_lock, flags);
spin_lock_irqsave(&ch->ch_lock, flags);
if (!IS_PRINT(minor)) {
un = &brd->channels[PORT_NUM(minor)]->ch_tun;
un->un_type = DGNC_SERIAL;
} else if (IS_PRINT(minor)) {
un = &brd->channels[PORT_NUM(minor)]->ch_pun;
un->un_type = DGNC_PRINT;
} else {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return -ENXIO;
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = wait_event_interruptible(ch->ch_flags_wait,
((ch->ch_flags & CH_OPENING) == 0));
if (rc)
return -EINTR;
rc = wait_event_interruptible(ch->ch_flags_wait,
(((ch->ch_tun.un_flags | ch->ch_pun.un_flags) &
UN_CLOSING) == 0));
if (rc)
return -EINTR;
spin_lock_irqsave(&ch->ch_lock, flags);
tty->driver_data = un;
if (!(un->un_flags & UN_ISOPEN)) {
un->un_tty = tty;
}
ch->ch_flags |= (CH_OPENING);
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (!ch->ch_rqueue)
ch->ch_rqueue = kzalloc(RQUEUESIZE, GFP_KERNEL);
if (!ch->ch_equeue)
ch->ch_equeue = kzalloc(EQUEUESIZE, GFP_KERNEL);
if (!ch->ch_wqueue)
ch->ch_wqueue = kzalloc(WQUEUESIZE, GFP_KERNEL);
if (!ch->ch_rqueue || !ch->ch_equeue || !ch->ch_wqueue) {
kfree(ch->ch_rqueue);
kfree(ch->ch_equeue);
kfree(ch->ch_wqueue);
return -ENOMEM;
}
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags &= ~(CH_OPENING);
wake_up_interruptible(&ch->ch_flags_wait);
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_ISOPEN)) {
ch->ch_r_head = 0;
ch->ch_r_tail = 0;
ch->ch_e_head = 0;
ch->ch_e_tail = 0;
ch->ch_w_head = 0;
ch->ch_w_tail = 0;
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
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = dgnc_block_til_ready(tty, file, ch);
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_open_count++;
un->un_open_count++;
un->un_flags |= (UN_ISOPEN);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return rc;
}
static int dgnc_block_til_ready(struct tty_struct *tty,
struct file *file,
struct channel_t *ch)
{
int retval = 0;
struct un_t *un = NULL;
unsigned long flags;
uint old_flags = 0;
int sleep_on_un_flags = 0;
if (!tty || tty->magic != TTY_MAGIC || !file || !ch ||
ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return -ENXIO;
spin_lock_irqsave(&ch->ch_lock, flags);
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
if (!((ch->ch_tun.un_flags |
ch->ch_pun.un_flags) &
UN_CLOSING)) {
if (file->f_flags & O_NONBLOCK)
break;
if (tty_io_error(tty)) {
retval = -EIO;
break;
}
if (ch->ch_flags & CH_CD)
break;
if (ch->ch_flags & CH_FCAR)
break;
} else {
sleep_on_un_flags = 1;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
if (sleep_on_un_flags)
old_flags = ch->ch_tun.un_flags | ch->ch_pun.un_flags;
else
old_flags = ch->ch_flags;
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (sleep_on_un_flags)
retval = wait_event_interruptible(un->un_flags_wait,
(old_flags != (ch->ch_tun.un_flags |
ch->ch_pun.un_flags)));
else
retval = wait_event_interruptible(ch->ch_flags_wait,
(old_flags != ch->ch_flags));
spin_lock_irqsave(&ch->ch_lock, flags);
}
ch->ch_wopen--;
spin_unlock_irqrestore(&ch->ch_lock, flags);
return retval;
}
static void dgnc_tty_hangup(struct tty_struct *tty)
{
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
dgnc_tty_flush_buffer(tty);
}
static void dgnc_tty_close(struct tty_struct *tty, struct file *file)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
if ((tty->count == 1) && (un->un_open_count != 1)) {
dev_dbg(tty->dev,
"tty->count is 1, un open count is %d\n",
un->un_open_count);
un->un_open_count = 1;
}
if (un->un_open_count)
un->un_open_count--;
else
dev_dbg(tty->dev,
"bad serial port open count of %d\n",
un->un_open_count);
ch->ch_open_count--;
if (ch->ch_open_count && un->un_open_count) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return;
}
un->un_flags |= UN_CLOSING;
tty->closing = 1;
if ((ch->ch_open_count == 0) &&
!(ch->ch_digi.digi_flags & DIGI_PRINTER)) {
ch->ch_flags &= ~(CH_STOPI | CH_FORCED_STOPI);
if ((un->un_type == DGNC_PRINT) && (ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int)ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
bd->bd_ops->drain(tty, 0);
dgnc_tty_flush_buffer(tty);
tty_ldisc_flush(tty);
spin_lock_irqsave(&ch->ch_lock, flags);
tty->closing = 0;
if (ch->ch_c_cflag & HUPCL) {
ch->ch_mostat &= ~(UART_MCR_DTR | UART_MCR_RTS);
bd->bd_ops->assert_modem_signals(ch);
if (ch->ch_close_delay) {
spin_unlock_irqrestore(&ch->ch_lock,
flags);
dgnc_ms_sleep(ch->ch_close_delay);
spin_lock_irqsave(&ch->ch_lock, flags);
}
}
ch->ch_old_baud = 0;
ch->ch_bd->bd_ops->uart_off(ch);
} else {
if ((un->un_type == DGNC_PRINT) && (ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int)ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
}
un->un_tty = NULL;
un->un_flags &= ~(UN_ISOPEN | UN_CLOSING);
wake_up_interruptible(&ch->ch_flags_wait);
wake_up_interruptible(&un->un_flags_wait);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static int dgnc_tty_chars_in_buffer(struct tty_struct *tty)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
ushort thead;
ushort ttail;
uint tmask;
uint chars = 0;
unsigned long flags;
if (!tty)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
spin_lock_irqsave(&ch->ch_lock, flags);
tmask = WQUEUEMASK;
thead = ch->ch_w_head & tmask;
ttail = ch->ch_w_tail & tmask;
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (ttail == thead) {
chars = 0;
} else {
if (thead >= ttail)
chars = thead - ttail;
else
chars = thead - ttail + WQUEUESIZE;
}
return chars;
}
static int dgnc_maxcps_room(struct tty_struct *tty, int bytes_available)
{
struct un_t *un = tty->driver_data;
struct channel_t *ch = un->un_ch;
if (un->un_type != DGNC_PRINT)
return bytes_available;
if (ch->ch_digi.digi_maxcps > 0 && ch->ch_digi.digi_bufsize > 0) {
int cps_limit = 0;
unsigned long current_time = jiffies;
unsigned long buffer_time = current_time +
(HZ * ch->ch_digi.digi_bufsize) /
ch->ch_digi.digi_maxcps;
if (ch->ch_cpstime < current_time) {
ch->ch_cpstime = current_time;
cps_limit = ch->ch_digi.digi_bufsize;
} else if (ch->ch_cpstime < buffer_time) {
cps_limit = ((buffer_time - ch->ch_cpstime) *
ch->ch_digi.digi_maxcps) / HZ;
} else {
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
unsigned long flags;
if (!tty || !dgnc_TmpWriteBuf)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
spin_lock_irqsave(&ch->ch_lock, flags);
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
} else {
if (ch->ch_flags & CH_PRON)
ret -= ch->ch_digi.digi_offlen;
}
if (ret < 0)
ret = 0;
spin_unlock_irqrestore(&ch->ch_lock, flags);
return ret;
}
static int dgnc_tty_put_char(struct tty_struct *tty, unsigned char c)
{
dgnc_tty_write(tty, &c, 1);
return 1;
}
static int dgnc_tty_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
int bufcount = 0, n = 0;
unsigned long flags;
ushort head;
ushort tail;
ushort tmask;
uint remain;
if (!tty || !dgnc_TmpWriteBuf)
return 0;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
if (!count)
return 0;
spin_lock_irqsave(&ch->ch_lock, flags);
tmask = WQUEUEMASK;
head = (ch->ch_w_head) & tmask;
tail = (ch->ch_w_tail) & tmask;
bufcount = tail - head - 1;
if (bufcount < 0)
bufcount += WQUEUESIZE;
bufcount = dgnc_maxcps_room(tty, bufcount);
count = min(count, bufcount);
if (count <= 0)
goto exit_retry;
if ((un->un_type == DGNC_PRINT) && !(ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_onstr,
(int)ch->ch_digi.digi_onlen);
head = (ch->ch_w_head) & tmask;
ch->ch_flags |= CH_PRON;
}
if ((un->un_type != DGNC_PRINT) && (ch->ch_flags & CH_PRON)) {
dgnc_wmove(ch, ch->ch_digi.digi_offstr,
(int)ch->ch_digi.digi_offlen);
head = (ch->ch_w_head) & tmask;
ch->ch_flags &= ~CH_PRON;
}
n = count;
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
if (count) {
head &= tmask;
ch->ch_w_head = head;
}
if ((un->un_type == DGNC_PRINT) && (ch->ch_digi.digi_maxcps > 0) &&
(ch->ch_digi.digi_bufsize > 0)) {
ch->ch_cpstime += (HZ * count) / ch->ch_digi.digi_maxcps;
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (count) {
ch->ch_bd->bd_ops->copy_data_from_queue_to_uart(ch);
}
return count;
exit_retry:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
static int dgnc_tty_tiocmget(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
int result = -EIO;
unsigned char mstat = 0;
unsigned long flags;
if (!tty || tty->magic != TTY_MAGIC)
return result;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return result;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return result;
spin_lock_irqsave(&ch->ch_lock, flags);
mstat = ch->ch_mostat | ch->ch_mistat;
spin_unlock_irqrestore(&ch->ch_lock, flags);
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
return result;
}
static int dgnc_tty_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -EIO;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
if (set & TIOCM_RTS)
ch->ch_mostat |= UART_MCR_RTS;
if (set & TIOCM_DTR)
ch->ch_mostat |= UART_MCR_DTR;
if (clear & TIOCM_RTS)
ch->ch_mostat &= ~(UART_MCR_RTS);
if (clear & TIOCM_DTR)
ch->ch_mostat &= ~(UART_MCR_DTR);
ch->ch_bd->bd_ops->assert_modem_signals(ch);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
static int dgnc_tty_send_break(struct tty_struct *tty, int msec)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -EIO;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_bd->bd_ops->send_break(ch, msec);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
static void dgnc_tty_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
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
bd->bd_ops->drain(tty, 0);
}
static void dgnc_tty_send_xchar(struct tty_struct *tty, char c)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
dev_dbg(tty->dev, "dgnc_tty_send_xchar start\n");
spin_lock_irqsave(&ch->ch_lock, flags);
bd->bd_ops->send_immediate_char(ch, c);
spin_unlock_irqrestore(&ch->ch_lock, flags);
dev_dbg(tty->dev, "dgnc_tty_send_xchar finish\n");
}
static inline int dgnc_get_mstat(struct channel_t *ch)
{
unsigned char mstat;
int result = -EIO;
unsigned long flags;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENXIO;
spin_lock_irqsave(&ch->ch_lock, flags);
mstat = ch->ch_mostat | ch->ch_mistat;
spin_unlock_irqrestore(&ch->ch_lock, flags);
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
return result;
}
static int dgnc_get_modem_info(struct channel_t *ch,
unsigned int __user *value)
{
return put_user(dgnc_get_mstat(ch), value);
}
static int dgnc_set_modem_info(struct tty_struct *tty,
unsigned int command,
unsigned int __user *value)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -ENXIO;
unsigned int arg = 0;
unsigned long flags;
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
ret = get_user(arg, value);
if (ret)
return ret;
switch (command) {
case TIOCMBIS:
if (arg & TIOCM_RTS)
ch->ch_mostat |= UART_MCR_RTS;
if (arg & TIOCM_DTR)
ch->ch_mostat |= UART_MCR_DTR;
break;
case TIOCMBIC:
if (arg & TIOCM_RTS)
ch->ch_mostat &= ~(UART_MCR_RTS);
if (arg & TIOCM_DTR)
ch->ch_mostat &= ~(UART_MCR_DTR);
break;
case TIOCMSET:
if (arg & TIOCM_RTS)
ch->ch_mostat |= UART_MCR_RTS;
else
ch->ch_mostat &= ~(UART_MCR_RTS);
if (arg & TIOCM_DTR)
ch->ch_mostat |= UART_MCR_DTR;
else
ch->ch_mostat &= ~(UART_MCR_DTR);
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_bd->bd_ops->assert_modem_signals(ch);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
static int dgnc_tty_digigeta(struct tty_struct *tty,
struct digi_t __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
struct digi_t tmp;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
memcpy(&tmp, &ch->ch_digi, sizeof(tmp));
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgnc_tty_digiseta(struct tty_struct *tty,
struct digi_t __user *new_info)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
struct digi_t new_digi;
unsigned long flags;
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
if (copy_from_user(&new_digi, new_info, sizeof(new_digi)))
return -EFAULT;
spin_lock_irqsave(&ch->ch_lock, flags);
if (!(ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) &&
(new_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat &= ~(UART_MCR_RTS);
if ((ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE) &&
!(new_digi.digi_flags & DIGI_RTS_TOGGLE))
ch->ch_mostat |= (UART_MCR_RTS);
if (!(ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) &&
(new_digi.digi_flags & DIGI_DTR_TOGGLE))
ch->ch_mostat &= ~(UART_MCR_DTR);
if ((ch->ch_digi.digi_flags & DIGI_DTR_TOGGLE) &&
!(new_digi.digi_flags & DIGI_DTR_TOGGLE))
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
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
static void dgnc_tty_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
ch->ch_bd->bd_ops->param(tty);
dgnc_carrier(ch);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_throttle(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags |= (CH_FORCED_STOPI);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_unthrottle(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags &= ~(CH_FORCED_STOPI);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_start(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags &= ~(CH_FORCED_STOP);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_stop(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags |= (CH_FORCED_STOP);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_flush_chars(struct tty_struct *tty)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
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
spin_lock_irqsave(&ch->ch_lock, flags);
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static void dgnc_tty_flush_buffer(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
unsigned long flags;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGNC_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return;
spin_lock_irqsave(&ch->ch_lock, flags);
ch->ch_flags &= ~CH_STOP;
ch->ch_w_head = ch->ch_w_tail;
ch->ch_bd->bd_ops->flush_uart_write(ch);
if (ch->ch_tun.un_flags & (UN_LOW | UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW | UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW | UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW | UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
}
static int dgnc_tty_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct dgnc_board *bd;
struct board_ops *ch_bd_ops;
struct channel_t *ch;
struct un_t *un;
int rc;
unsigned long flags;
void __user *uarg = (void __user *)arg;
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
ch_bd_ops = bd->bd_ops;
spin_lock_irqsave(&ch->ch_lock, flags);
if (un->un_open_count <= 0) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return -EIO;
}
switch (cmd) {
case TCSBRK:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (rc)
return rc;
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
spin_lock_irqsave(&ch->ch_lock, flags);
if (((cmd == TCSBRK) && (!arg)) || (cmd == TCSBRKP))
ch_bd_ops->send_break(ch, 250);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
case TCSBRKP:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (rc)
return rc;
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
spin_lock_irqsave(&ch->ch_lock, flags);
ch_bd_ops->send_break(ch, 250);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
case TIOCSBRK:
rc = tty_check_change(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (rc)
return rc;
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
spin_lock_irqsave(&ch->ch_lock, flags);
ch_bd_ops->send_break(ch, 250);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
case TIOCCBRK:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
case TIOCGSOFTCAR:
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = put_user(C_CLOCAL(tty) ? 1 : 0,
(unsigned long __user *)arg);
return rc;
case TIOCSSOFTCAR:
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = get_user(arg, (unsigned long __user *)arg);
if (rc)
return rc;
spin_lock_irqsave(&ch->ch_lock, flags);
tty->termios.c_cflag = ((tty->termios.c_cflag & ~CLOCAL) |
(arg ? CLOCAL : 0));
ch_bd_ops->param(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
case TIOCMGET:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return dgnc_get_modem_info(ch, uarg);
case TIOCMBIS:
case TIOCMBIC:
case TIOCMSET:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return dgnc_set_modem_info(tty, cmd, uarg);
case TCFLSH:
rc = tty_check_change(tty);
if (rc) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
return rc;
}
if ((arg == TCIFLUSH) || (arg == TCIOFLUSH)) {
ch->ch_r_head = ch->ch_r_tail;
ch_bd_ops->flush_uart_read(ch);
dgnc_check_queue_flow_control(ch);
}
if ((arg == TCOFLUSH) || (arg == TCIOFLUSH)) {
if (!(un->un_type == DGNC_PRINT)) {
ch->ch_w_head = ch->ch_w_tail;
ch_bd_ops->flush_uart_write(ch);
if (ch->ch_tun.un_flags & (UN_LOW | UN_EMPTY)) {
ch->ch_tun.un_flags &=
~(UN_LOW | UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &=
~(UN_LOW | UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
}
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
return -ENOIOCTLCMD;
case TCSETSF:
case TCSETSW:
if (cmd == TCSETSF) {
ch->ch_flags &= ~CH_STOP;
ch->ch_r_head = ch->ch_r_tail;
ch_bd_ops->flush_uart_read(ch);
dgnc_check_queue_flow_control(ch);
}
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
return -ENOIOCTLCMD;
case TCSETAW:
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
return -ENOIOCTLCMD;
case TCXONC:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return -ENOIOCTLCMD;
case DIGI_GETA:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return dgnc_tty_digigeta(tty, uarg);
case DIGI_SETAW:
case DIGI_SETAF:
if (cmd == (DIGI_SETAW)) {
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = ch_bd_ops->drain(tty, 0);
if (rc)
return -EINTR;
spin_lock_irqsave(&ch->ch_lock, flags);
} else {
tty_ldisc_flush(tty);
}
case DIGI_SETA:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return dgnc_tty_digiseta(tty, uarg);
case DIGI_LOOPBACK:
{
uint loopback = 0;
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = get_user(loopback, (unsigned int __user *)arg);
if (rc)
return rc;
spin_lock_irqsave(&ch->ch_lock, flags);
if (loopback)
ch->ch_flags |= CH_LOOPBACK;
else
ch->ch_flags &= ~(CH_LOOPBACK);
ch_bd_ops->param(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
case DIGI_GETCUSTOMBAUD:
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = put_user(ch->ch_custom_speed, (unsigned int __user *)arg);
return rc;
case DIGI_SETCUSTOMBAUD:
{
int new_rate;
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = get_user(new_rate, (int __user *)arg);
if (rc)
return rc;
spin_lock_irqsave(&ch->ch_lock, flags);
dgnc_set_custom_speed(ch, new_rate);
ch_bd_ops->param(tty);
spin_unlock_irqrestore(&ch->ch_lock, flags);
return 0;
}
case DIGI_REALPORT_SENDIMMEDIATE:
{
unsigned char c;
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = get_user(c, (unsigned char __user *)arg);
if (rc)
return rc;
spin_lock_irqsave(&ch->ch_lock, flags);
ch_bd_ops->send_immediate_char(ch, c);
spin_unlock_irqrestore(&ch->ch_lock, flags);
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
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (copy_to_user(uarg, &buf, sizeof(buf)))
return -EFAULT;
return 0;
}
case DIGI_REALPORT_GETEVENTS:
{
unsigned int events = 0;
if (ch->ch_flags & CH_BREAK_SENDING)
events |= EV_TXB;
if ((ch->ch_flags & CH_STOP) ||
(ch->ch_flags & CH_FORCED_STOP))
events |= (EV_OPU | EV_OPS);
if ((ch->ch_flags & CH_STOPI) ||
(ch->ch_flags & CH_FORCED_STOPI))
events |= (EV_IPU | EV_IPS);
spin_unlock_irqrestore(&ch->ch_lock, flags);
rc = put_user(events, (unsigned int __user *)arg);
return rc;
}
case DIGI_REALPORT_GETBUFFERS:
{
struct digi_getbuffer buf;
int tdist;
int count;
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (copy_from_user(&buf, uarg, sizeof(buf)))
return -EFAULT;
spin_lock_irqsave(&ch->ch_lock, flags);
buf.rxbuf = (ch->ch_r_head - ch->ch_r_tail) & RQUEUEMASK;
buf.txbuf = (ch->ch_w_head - ch->ch_w_tail) & WQUEUEMASK;
count = buf.txbuf + ch_bd_ops->get_uart_bytes_left(ch);
tdist = (buf.tx_in - buf.tx_out) & 0xffff;
if (buf.txbuf > tdist)
buf.txbuf = tdist;
if (count)
buf.txdone = 0;
else
buf.txdone = 1;
spin_unlock_irqrestore(&ch->ch_lock, flags);
if (copy_to_user(uarg, &buf, sizeof(buf)))
return -EFAULT;
return 0;
}
default:
spin_unlock_irqrestore(&ch->ch_lock, flags);
return -ENOIOCTLCMD;
}
}
