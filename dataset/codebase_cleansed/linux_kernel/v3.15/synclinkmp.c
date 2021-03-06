static void* synclinkmp_get_text_ptr(void) {return synclinkmp_get_text_ptr;}
static inline int sanity_check(SLMP_INFO *info,
char *name, const char *routine)
{
#ifdef SANITY_CHECK
static const char *badmagic =
"Warning: bad magic number for synclinkmp_struct (%s) in %s\n";
static const char *badinfo =
"Warning: null synclinkmp_struct for (%s) in %s\n";
if (!info) {
printk(badinfo, name, routine);
return 1;
}
if (info->magic != MGSL_MAGIC) {
printk(badmagic, name, routine);
return 1;
}
#else
if (!info)
return 1;
#endif
return 0;
}
static void ldisc_receive_buf(struct tty_struct *tty,
const __u8 *data, char *flags, int count)
{
struct tty_ldisc *ld;
if (!tty)
return;
ld = tty_ldisc_ref(tty);
if (ld) {
if (ld->ops->receive_buf)
ld->ops->receive_buf(tty, data, flags, count);
tty_ldisc_deref(ld);
}
}
static int install(struct tty_driver *driver, struct tty_struct *tty)
{
SLMP_INFO *info;
int line = tty->index;
if (line >= synclinkmp_device_count) {
printk("%s(%d): open with invalid line #%d.\n",
__FILE__,__LINE__,line);
return -ENODEV;
}
info = synclinkmp_device_list;
while (info && info->line != line)
info = info->next_device;
if (sanity_check(info, tty->name, "open"))
return -ENODEV;
if (info->init_error) {
printk("%s(%d):%s device is not allocated, init error=%d\n",
__FILE__, __LINE__, info->device_name,
info->init_error);
return -ENODEV;
}
tty->driver_data = info;
return tty_port_install(&info->port, driver, tty);
}
static int open(struct tty_struct *tty, struct file *filp)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
int retval;
info->port.tty = tty;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s open(), old ref count = %d\n",
__FILE__,__LINE__,tty->driver->name, info->port.count);
if (tty_hung_up_p(filp) || info->port.flags & ASYNC_CLOSING){
wait_event_interruptible_tty(tty, info->port.close_wait,
!(info->port.flags & ASYNC_CLOSING));
retval = ((info->port.flags & ASYNC_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS);
goto cleanup;
}
info->port.low_latency = (info->port.flags & ASYNC_LOW_LATENCY) ? 1 : 0;
spin_lock_irqsave(&info->netlock, flags);
if (info->netcount) {
retval = -EBUSY;
spin_unlock_irqrestore(&info->netlock, flags);
goto cleanup;
}
info->port.count++;
spin_unlock_irqrestore(&info->netlock, flags);
if (info->port.count == 1) {
retval = startup(info);
if (retval < 0)
goto cleanup;
}
retval = block_til_ready(tty, filp, info);
if (retval) {
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s block_til_ready() returned %d\n",
__FILE__,__LINE__, info->device_name, retval);
goto cleanup;
}
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s open() success\n",
__FILE__,__LINE__, info->device_name);
retval = 0;
cleanup:
if (retval) {
if (tty->count == 1)
info->port.tty = NULL;
if(info->port.count)
info->port.count--;
}
return retval;
}
static void close(struct tty_struct *tty, struct file *filp)
{
SLMP_INFO * info = tty->driver_data;
if (sanity_check(info, tty->name, "close"))
return;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s close() entry, count=%d\n",
__FILE__,__LINE__, info->device_name, info->port.count);
if (tty_port_close_start(&info->port, tty, filp) == 0)
goto cleanup;
mutex_lock(&info->port.mutex);
if (info->port.flags & ASYNC_INITIALIZED)
wait_until_sent(tty, info->timeout);
flush_buffer(tty);
tty_ldisc_flush(tty);
shutdown(info);
mutex_unlock(&info->port.mutex);
tty_port_close_end(&info->port, tty);
info->port.tty = NULL;
cleanup:
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s close() exit, count=%d\n", __FILE__,__LINE__,
tty->driver->name, info->port.count);
}
static void hangup(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s hangup()\n",
__FILE__,__LINE__, info->device_name );
if (sanity_check(info, tty->name, "hangup"))
return;
mutex_lock(&info->port.mutex);
flush_buffer(tty);
shutdown(info);
spin_lock_irqsave(&info->port.lock, flags);
info->port.count = 0;
info->port.flags &= ~ASYNC_NORMAL_ACTIVE;
info->port.tty = NULL;
spin_unlock_irqrestore(&info->port.lock, flags);
mutex_unlock(&info->port.mutex);
wake_up_interruptible(&info->port.open_wait);
}
static void set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s set_termios()\n", __FILE__,__LINE__,
tty->driver->name );
change_params(info);
if (old_termios->c_cflag & CBAUD &&
!(tty->termios.c_cflag & CBAUD)) {
info->serial_signals &= ~(SerialSignal_RTS | SerialSignal_DTR);
spin_lock_irqsave(&info->lock,flags);
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
}
if (!(old_termios->c_cflag & CBAUD) &&
tty->termios.c_cflag & CBAUD) {
info->serial_signals |= SerialSignal_DTR;
if (!(tty->termios.c_cflag & CRTSCTS) ||
!test_bit(TTY_THROTTLED, &tty->flags)) {
info->serial_signals |= SerialSignal_RTS;
}
spin_lock_irqsave(&info->lock,flags);
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
}
if (old_termios->c_cflag & CRTSCTS &&
!(tty->termios.c_cflag & CRTSCTS)) {
tty->hw_stopped = 0;
tx_release(tty);
}
}
static int write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
int c, ret = 0;
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s write() count=%d\n",
__FILE__,__LINE__,info->device_name,count);
if (sanity_check(info, tty->name, "write"))
goto cleanup;
if (!info->tx_buf)
goto cleanup;
if (info->params.mode == MGSL_MODE_HDLC) {
if (count > info->max_frame_size) {
ret = -EIO;
goto cleanup;
}
if (info->tx_active)
goto cleanup;
if (info->tx_count) {
tx_load_dma_buffer(info, info->tx_buf, info->tx_count);
goto start;
}
ret = info->tx_count = count;
tx_load_dma_buffer(info, buf, count);
goto start;
}
for (;;) {
c = min_t(int, count,
min(info->max_frame_size - info->tx_count - 1,
info->max_frame_size - info->tx_put));
if (c <= 0)
break;
memcpy(info->tx_buf + info->tx_put, buf, c);
spin_lock_irqsave(&info->lock,flags);
info->tx_put += c;
if (info->tx_put >= info->max_frame_size)
info->tx_put -= info->max_frame_size;
info->tx_count += c;
spin_unlock_irqrestore(&info->lock,flags);
buf += c;
count -= c;
ret += c;
}
if (info->params.mode == MGSL_MODE_HDLC) {
if (count) {
ret = info->tx_count = 0;
goto cleanup;
}
tx_load_dma_buffer(info, info->tx_buf, info->tx_count);
}
start:
if (info->tx_count && !tty->stopped && !tty->hw_stopped) {
spin_lock_irqsave(&info->lock,flags);
if (!info->tx_active)
tx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
cleanup:
if (debug_level >= DEBUG_LEVEL_INFO)
printk( "%s(%d):%s write() returning=%d\n",
__FILE__,__LINE__,info->device_name,ret);
return ret;
}
static int put_char(struct tty_struct *tty, unsigned char ch)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
int ret = 0;
if ( debug_level >= DEBUG_LEVEL_INFO ) {
printk( "%s(%d):%s put_char(%d)\n",
__FILE__,__LINE__,info->device_name,ch);
}
if (sanity_check(info, tty->name, "put_char"))
return 0;
if (!info->tx_buf)
return 0;
spin_lock_irqsave(&info->lock,flags);
if ( (info->params.mode != MGSL_MODE_HDLC) ||
!info->tx_active ) {
if (info->tx_count < info->max_frame_size - 1) {
info->tx_buf[info->tx_put++] = ch;
if (info->tx_put >= info->max_frame_size)
info->tx_put -= info->max_frame_size;
info->tx_count++;
ret = 1;
}
}
spin_unlock_irqrestore(&info->lock,flags);
return ret;
}
static void send_xchar(struct tty_struct *tty, char ch)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s send_xchar(%d)\n",
__FILE__,__LINE__, info->device_name, ch );
if (sanity_check(info, tty->name, "send_xchar"))
return;
info->x_char = ch;
if (ch) {
spin_lock_irqsave(&info->lock,flags);
if (!info->tx_enabled)
tx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
}
static void wait_until_sent(struct tty_struct *tty, int timeout)
{
SLMP_INFO * info = tty->driver_data;
unsigned long orig_jiffies, char_time;
if (!info )
return;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s wait_until_sent() entry\n",
__FILE__,__LINE__, info->device_name );
if (sanity_check(info, tty->name, "wait_until_sent"))
return;
if (!test_bit(ASYNCB_INITIALIZED, &info->port.flags))
goto exit;
orig_jiffies = jiffies;
if ( info->params.data_rate ) {
char_time = info->timeout/(32 * 5);
if (!char_time)
char_time++;
} else
char_time = 1;
if (timeout)
char_time = min_t(unsigned long, char_time, timeout);
if ( info->params.mode == MGSL_MODE_HDLC ) {
while (info->tx_active) {
msleep_interruptible(jiffies_to_msecs(char_time));
if (signal_pending(current))
break;
if (timeout && time_after(jiffies, orig_jiffies + timeout))
break;
}
} else {
while ( info->tx_active && info->tx_enabled) {
msleep_interruptible(jiffies_to_msecs(char_time));
if (signal_pending(current))
break;
if (timeout && time_after(jiffies, orig_jiffies + timeout))
break;
}
}
exit:
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s wait_until_sent() exit\n",
__FILE__,__LINE__, info->device_name );
}
static int write_room(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
int ret;
if (sanity_check(info, tty->name, "write_room"))
return 0;
if (info->params.mode == MGSL_MODE_HDLC) {
ret = (info->tx_active) ? 0 : HDLC_MAX_FRAME_SIZE;
} else {
ret = info->max_frame_size - info->tx_count - 1;
if (ret < 0)
ret = 0;
}
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s write_room()=%d\n",
__FILE__, __LINE__, info->device_name, ret);
return ret;
}
static void flush_chars(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s flush_chars() entry tx_count=%d\n",
__FILE__,__LINE__,info->device_name,info->tx_count);
if (sanity_check(info, tty->name, "flush_chars"))
return;
if (info->tx_count <= 0 || tty->stopped || tty->hw_stopped ||
!info->tx_buf)
return;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s flush_chars() entry, starting transmitter\n",
__FILE__,__LINE__,info->device_name );
spin_lock_irqsave(&info->lock,flags);
if (!info->tx_active) {
if ( (info->params.mode == MGSL_MODE_HDLC) &&
info->tx_count ) {
tx_load_dma_buffer(info,
info->tx_buf,info->tx_count);
}
tx_start(info);
}
spin_unlock_irqrestore(&info->lock,flags);
}
static void flush_buffer(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s flush_buffer() entry\n",
__FILE__,__LINE__, info->device_name );
if (sanity_check(info, tty->name, "flush_buffer"))
return;
spin_lock_irqsave(&info->lock,flags);
info->tx_count = info->tx_put = info->tx_get = 0;
del_timer(&info->tx_timer);
spin_unlock_irqrestore(&info->lock,flags);
tty_wakeup(tty);
}
static void tx_hold(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (sanity_check(info, tty->name, "tx_hold"))
return;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk("%s(%d):%s tx_hold()\n",
__FILE__,__LINE__,info->device_name);
spin_lock_irqsave(&info->lock,flags);
if (info->tx_enabled)
tx_stop(info);
spin_unlock_irqrestore(&info->lock,flags);
}
static void tx_release(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (sanity_check(info, tty->name, "tx_release"))
return;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk("%s(%d):%s tx_release()\n",
__FILE__,__LINE__,info->device_name);
spin_lock_irqsave(&info->lock,flags);
if (!info->tx_enabled)
tx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
static int ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
SLMP_INFO *info = tty->driver_data;
void __user *argp = (void __user *)arg;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s ioctl() cmd=%08X\n", __FILE__,__LINE__,
info->device_name, cmd );
if (sanity_check(info, tty->name, "ioctl"))
return -ENODEV;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCMIWAIT)) {
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
}
switch (cmd) {
case MGSL_IOCGPARAMS:
return get_params(info, argp);
case MGSL_IOCSPARAMS:
return set_params(info, argp);
case MGSL_IOCGTXIDLE:
return get_txidle(info, argp);
case MGSL_IOCSTXIDLE:
return set_txidle(info, (int)arg);
case MGSL_IOCTXENABLE:
return tx_enable(info, (int)arg);
case MGSL_IOCRXENABLE:
return rx_enable(info, (int)arg);
case MGSL_IOCTXABORT:
return tx_abort(info);
case MGSL_IOCGSTATS:
return get_stats(info, argp);
case MGSL_IOCWAITEVENT:
return wait_mgsl_event(info, argp);
case MGSL_IOCLOOPTXDONE:
return 0;
case TIOCMIWAIT:
return modem_input_wait(info,(int)arg);
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
SLMP_INFO *info = tty->driver_data;
struct mgsl_icount cnow;
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
cnow = info->icount;
spin_unlock_irqrestore(&info->lock,flags);
icount->cts = cnow.cts;
icount->dsr = cnow.dsr;
icount->rng = cnow.rng;
icount->dcd = cnow.dcd;
icount->rx = cnow.rx;
icount->tx = cnow.tx;
icount->frame = cnow.frame;
icount->overrun = cnow.overrun;
icount->parity = cnow.parity;
icount->brk = cnow.brk;
icount->buf_overrun = cnow.buf_overrun;
return 0;
}
static inline void line_info(struct seq_file *m, SLMP_INFO *info)
{
char stat_buf[30];
unsigned long flags;
seq_printf(m, "%s: SCABase=%08x Mem=%08X StatusControl=%08x LCR=%08X\n"
"\tIRQ=%d MaxFrameSize=%u\n",
info->device_name,
info->phys_sca_base,
info->phys_memory_base,
info->phys_statctrl_base,
info->phys_lcr_base,
info->irq_level,
info->max_frame_size );
spin_lock_irqsave(&info->lock,flags);
get_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
stat_buf[0] = 0;
stat_buf[1] = 0;
if (info->serial_signals & SerialSignal_RTS)
strcat(stat_buf, "|RTS");
if (info->serial_signals & SerialSignal_CTS)
strcat(stat_buf, "|CTS");
if (info->serial_signals & SerialSignal_DTR)
strcat(stat_buf, "|DTR");
if (info->serial_signals & SerialSignal_DSR)
strcat(stat_buf, "|DSR");
if (info->serial_signals & SerialSignal_DCD)
strcat(stat_buf, "|CD");
if (info->serial_signals & SerialSignal_RI)
strcat(stat_buf, "|RI");
if (info->params.mode == MGSL_MODE_HDLC) {
seq_printf(m, "\tHDLC txok:%d rxok:%d",
info->icount.txok, info->icount.rxok);
if (info->icount.txunder)
seq_printf(m, " txunder:%d", info->icount.txunder);
if (info->icount.txabort)
seq_printf(m, " txabort:%d", info->icount.txabort);
if (info->icount.rxshort)
seq_printf(m, " rxshort:%d", info->icount.rxshort);
if (info->icount.rxlong)
seq_printf(m, " rxlong:%d", info->icount.rxlong);
if (info->icount.rxover)
seq_printf(m, " rxover:%d", info->icount.rxover);
if (info->icount.rxcrc)
seq_printf(m, " rxlong:%d", info->icount.rxcrc);
} else {
seq_printf(m, "\tASYNC tx:%d rx:%d",
info->icount.tx, info->icount.rx);
if (info->icount.frame)
seq_printf(m, " fe:%d", info->icount.frame);
if (info->icount.parity)
seq_printf(m, " pe:%d", info->icount.parity);
if (info->icount.brk)
seq_printf(m, " brk:%d", info->icount.brk);
if (info->icount.overrun)
seq_printf(m, " oe:%d", info->icount.overrun);
}
seq_printf(m, " %s\n", stat_buf+1);
seq_printf(m, "\ttxactive=%d bh_req=%d bh_run=%d pending_bh=%x\n",
info->tx_active,info->bh_requested,info->bh_running,
info->pending_bh);
}
static int synclinkmp_proc_show(struct seq_file *m, void *v)
{
SLMP_INFO *info;
seq_printf(m, "synclinkmp driver:%s\n", driver_version);
info = synclinkmp_device_list;
while( info ) {
line_info(m, info);
info = info->next_device;
}
return 0;
}
static int synclinkmp_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, synclinkmp_proc_show, NULL);
}
static int chars_in_buffer(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
if (sanity_check(info, tty->name, "chars_in_buffer"))
return 0;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s chars_in_buffer()=%d\n",
__FILE__, __LINE__, info->device_name, info->tx_count);
return info->tx_count;
}
static void throttle(struct tty_struct * tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s throttle() entry\n",
__FILE__,__LINE__, info->device_name );
if (sanity_check(info, tty->name, "throttle"))
return;
if (I_IXOFF(tty))
send_xchar(tty, STOP_CHAR(tty));
if (tty->termios.c_cflag & CRTSCTS) {
spin_lock_irqsave(&info->lock,flags);
info->serial_signals &= ~SerialSignal_RTS;
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
}
}
static void unthrottle(struct tty_struct * tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s unthrottle() entry\n",
__FILE__,__LINE__, info->device_name );
if (sanity_check(info, tty->name, "unthrottle"))
return;
if (I_IXOFF(tty)) {
if (info->x_char)
info->x_char = 0;
else
send_xchar(tty, START_CHAR(tty));
}
if (tty->termios.c_cflag & CRTSCTS) {
spin_lock_irqsave(&info->lock,flags);
info->serial_signals |= SerialSignal_RTS;
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
}
}
static int set_break(struct tty_struct *tty, int break_state)
{
unsigned char RegValue;
SLMP_INFO * info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s set_break(%d)\n",
__FILE__,__LINE__, info->device_name, break_state);
if (sanity_check(info, tty->name, "set_break"))
return -EINVAL;
spin_lock_irqsave(&info->lock,flags);
RegValue = read_reg(info, CTL);
if (break_state == -1)
RegValue |= BIT3;
else
RegValue &= ~BIT3;
write_reg(info, CTL, RegValue);
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int hdlcdev_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
SLMP_INFO *info = dev_to_port(dev);
unsigned char new_encoding;
unsigned short new_crctype;
if (info->port.count)
return -EBUSY;
switch (encoding)
{
case ENCODING_NRZ: new_encoding = HDLC_ENCODING_NRZ; break;
case ENCODING_NRZI: new_encoding = HDLC_ENCODING_NRZI_SPACE; break;
case ENCODING_FM_MARK: new_encoding = HDLC_ENCODING_BIPHASE_MARK; break;
case ENCODING_FM_SPACE: new_encoding = HDLC_ENCODING_BIPHASE_SPACE; break;
case ENCODING_MANCHESTER: new_encoding = HDLC_ENCODING_BIPHASE_LEVEL; break;
default: return -EINVAL;
}
switch (parity)
{
case PARITY_NONE: new_crctype = HDLC_CRC_NONE; break;
case PARITY_CRC16_PR1_CCITT: new_crctype = HDLC_CRC_16_CCITT; break;
case PARITY_CRC32_PR1_CCITT: new_crctype = HDLC_CRC_32_CCITT; break;
default: return -EINVAL;
}
info->params.encoding = new_encoding;
info->params.crc_type = new_crctype;
if (info->netcount)
program_hw(info);
return 0;
}
static netdev_tx_t hdlcdev_xmit(struct sk_buff *skb,
struct net_device *dev)
{
SLMP_INFO *info = dev_to_port(dev);
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk(KERN_INFO "%s:hdlc_xmit(%s)\n",__FILE__,dev->name);
netif_stop_queue(dev);
info->tx_count = skb->len;
tx_load_dma_buffer(info, skb->data, skb->len);
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
dev_kfree_skb(skb);
dev->trans_start = jiffies;
spin_lock_irqsave(&info->lock,flags);
if (!info->tx_active)
tx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
return NETDEV_TX_OK;
}
static int hdlcdev_open(struct net_device *dev)
{
SLMP_INFO *info = dev_to_port(dev);
int rc;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s:hdlcdev_open(%s)\n",__FILE__,dev->name);
if ((rc = hdlc_open(dev)))
return rc;
spin_lock_irqsave(&info->netlock, flags);
if (info->port.count != 0 || info->netcount != 0) {
printk(KERN_WARNING "%s: hdlc_open returning busy\n", dev->name);
spin_unlock_irqrestore(&info->netlock, flags);
return -EBUSY;
}
info->netcount=1;
spin_unlock_irqrestore(&info->netlock, flags);
if ((rc = startup(info)) != 0) {
spin_lock_irqsave(&info->netlock, flags);
info->netcount=0;
spin_unlock_irqrestore(&info->netlock, flags);
return rc;
}
info->serial_signals |= SerialSignal_RTS | SerialSignal_DTR;
program_hw(info);
dev->trans_start = jiffies;
netif_start_queue(dev);
spin_lock_irqsave(&info->lock, flags);
get_signals(info);
spin_unlock_irqrestore(&info->lock, flags);
if (info->serial_signals & SerialSignal_DCD)
netif_carrier_on(dev);
else
netif_carrier_off(dev);
return 0;
}
static int hdlcdev_close(struct net_device *dev)
{
SLMP_INFO *info = dev_to_port(dev);
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s:hdlcdev_close(%s)\n",__FILE__,dev->name);
netif_stop_queue(dev);
shutdown(info);
hdlc_close(dev);
spin_lock_irqsave(&info->netlock, flags);
info->netcount=0;
spin_unlock_irqrestore(&info->netlock, flags);
return 0;
}
static int hdlcdev_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
const size_t size = sizeof(sync_serial_settings);
sync_serial_settings new_line;
sync_serial_settings __user *line = ifr->ifr_settings.ifs_ifsu.sync;
SLMP_INFO *info = dev_to_port(dev);
unsigned int flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s:hdlcdev_ioctl(%s)\n",__FILE__,dev->name);
if (info->port.count)
return -EBUSY;
if (cmd != SIOCWANDEV)
return hdlc_ioctl(dev, ifr, cmd);
switch(ifr->ifr_settings.type) {
case IF_GET_IFACE:
ifr->ifr_settings.type = IF_IFACE_SYNC_SERIAL;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
flags = info->params.flags & (HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_RXC_DPLL |
HDLC_FLAG_RXC_BRG | HDLC_FLAG_RXC_TXCPIN |
HDLC_FLAG_TXC_TXCPIN | HDLC_FLAG_TXC_DPLL |
HDLC_FLAG_TXC_BRG | HDLC_FLAG_TXC_RXCPIN);
memset(&new_line, 0, sizeof(new_line));
switch (flags){
case (HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_TXCPIN): new_line.clock_type = CLOCK_EXT; break;
case (HDLC_FLAG_RXC_BRG | HDLC_FLAG_TXC_BRG): new_line.clock_type = CLOCK_INT; break;
case (HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_BRG): new_line.clock_type = CLOCK_TXINT; break;
case (HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_RXCPIN): new_line.clock_type = CLOCK_TXFROMRX; break;
default: new_line.clock_type = CLOCK_DEFAULT;
}
new_line.clock_rate = info->params.clock_speed;
new_line.loopback = info->params.loopback ? 1:0;
if (copy_to_user(line, &new_line, size))
return -EFAULT;
return 0;
case IF_IFACE_SYNC_SERIAL:
if(!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(&new_line, line, size))
return -EFAULT;
switch (new_line.clock_type)
{
case CLOCK_EXT: flags = HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_TXCPIN; break;
case CLOCK_TXFROMRX: flags = HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_RXCPIN; break;
case CLOCK_INT: flags = HDLC_FLAG_RXC_BRG | HDLC_FLAG_TXC_BRG; break;
case CLOCK_TXINT: flags = HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_TXC_BRG; break;
case CLOCK_DEFAULT: flags = info->params.flags &
(HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_RXC_DPLL |
HDLC_FLAG_RXC_BRG | HDLC_FLAG_RXC_TXCPIN |
HDLC_FLAG_TXC_TXCPIN | HDLC_FLAG_TXC_DPLL |
HDLC_FLAG_TXC_BRG | HDLC_FLAG_TXC_RXCPIN); break;
default: return -EINVAL;
}
if (new_line.loopback != 0 && new_line.loopback != 1)
return -EINVAL;
info->params.flags &= ~(HDLC_FLAG_RXC_RXCPIN | HDLC_FLAG_RXC_DPLL |
HDLC_FLAG_RXC_BRG | HDLC_FLAG_RXC_TXCPIN |
HDLC_FLAG_TXC_TXCPIN | HDLC_FLAG_TXC_DPLL |
HDLC_FLAG_TXC_BRG | HDLC_FLAG_TXC_RXCPIN);
info->params.flags |= flags;
info->params.loopback = new_line.loopback;
if (flags & (HDLC_FLAG_RXC_BRG | HDLC_FLAG_TXC_BRG))
info->params.clock_speed = new_line.clock_rate;
else
info->params.clock_speed = 0;
if (info->netcount)
program_hw(info);
return 0;
default:
return hdlc_ioctl(dev, ifr, cmd);
}
}
static void hdlcdev_tx_timeout(struct net_device *dev)
{
SLMP_INFO *info = dev_to_port(dev);
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("hdlcdev_tx_timeout(%s)\n",dev->name);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
spin_lock_irqsave(&info->lock,flags);
tx_stop(info);
spin_unlock_irqrestore(&info->lock,flags);
netif_wake_queue(dev);
}
static void hdlcdev_tx_done(SLMP_INFO *info)
{
if (netif_queue_stopped(info->netdev))
netif_wake_queue(info->netdev);
}
static void hdlcdev_rx(SLMP_INFO *info, char *buf, int size)
{
struct sk_buff *skb = dev_alloc_skb(size);
struct net_device *dev = info->netdev;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("hdlcdev_rx(%s)\n",dev->name);
if (skb == NULL) {
printk(KERN_NOTICE "%s: can't alloc skb, dropping packet\n",
dev->name);
dev->stats.rx_dropped++;
return;
}
memcpy(skb_put(skb, size), buf, size);
skb->protocol = hdlc_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += size;
netif_rx(skb);
}
static int hdlcdev_init(SLMP_INFO *info)
{
int rc;
struct net_device *dev;
hdlc_device *hdlc;
if (!(dev = alloc_hdlcdev(info))) {
printk(KERN_ERR "%s:hdlc device allocation failure\n",__FILE__);
return -ENOMEM;
}
dev->mem_start = info->phys_sca_base;
dev->mem_end = info->phys_sca_base + SCA_BASE_SIZE - 1;
dev->irq = info->irq_level;
dev->netdev_ops = &hdlcdev_ops;
dev->watchdog_timeo = 10 * HZ;
dev->tx_queue_len = 50;
hdlc = dev_to_hdlc(dev);
hdlc->attach = hdlcdev_attach;
hdlc->xmit = hdlcdev_xmit;
if ((rc = register_hdlc_device(dev))) {
printk(KERN_WARNING "%s:unable to register hdlc device\n",__FILE__);
free_netdev(dev);
return rc;
}
info->netdev = dev;
return 0;
}
static void hdlcdev_exit(SLMP_INFO *info)
{
unregister_hdlc_device(info->netdev);
free_netdev(info->netdev);
info->netdev = NULL;
}
static int bh_action(SLMP_INFO *info)
{
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&info->lock,flags);
if (info->pending_bh & BH_RECEIVE) {
info->pending_bh &= ~BH_RECEIVE;
rc = BH_RECEIVE;
} else if (info->pending_bh & BH_TRANSMIT) {
info->pending_bh &= ~BH_TRANSMIT;
rc = BH_TRANSMIT;
} else if (info->pending_bh & BH_STATUS) {
info->pending_bh &= ~BH_STATUS;
rc = BH_STATUS;
}
if (!rc) {
info->bh_running = false;
info->bh_requested = false;
}
spin_unlock_irqrestore(&info->lock,flags);
return rc;
}
static void bh_handler(struct work_struct *work)
{
SLMP_INFO *info = container_of(work, SLMP_INFO, task);
int action;
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_handler() entry\n",
__FILE__,__LINE__,info->device_name);
info->bh_running = true;
while((action = bh_action(info)) != 0) {
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_handler() work item action=%d\n",
__FILE__,__LINE__,info->device_name, action);
switch (action) {
case BH_RECEIVE:
bh_receive(info);
break;
case BH_TRANSMIT:
bh_transmit(info);
break;
case BH_STATUS:
bh_status(info);
break;
default:
printk("%s(%d):%s Unknown work item ID=%08X!\n",
__FILE__,__LINE__,info->device_name,action);
break;
}
}
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_handler() exit\n",
__FILE__,__LINE__,info->device_name);
}
static void bh_receive(SLMP_INFO *info)
{
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_receive()\n",
__FILE__,__LINE__,info->device_name);
while( rx_get_frame(info) );
}
static void bh_transmit(SLMP_INFO *info)
{
struct tty_struct *tty = info->port.tty;
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_transmit() entry\n",
__FILE__,__LINE__,info->device_name);
if (tty)
tty_wakeup(tty);
}
static void bh_status(SLMP_INFO *info)
{
if ( debug_level >= DEBUG_LEVEL_BH )
printk( "%s(%d):%s bh_status() entry\n",
__FILE__,__LINE__,info->device_name);
info->ri_chkcount = 0;
info->dsr_chkcount = 0;
info->dcd_chkcount = 0;
info->cts_chkcount = 0;
}
static void isr_timer(SLMP_INFO * info)
{
unsigned char timer = (info->port_num & 1) ? TIMER2 : TIMER0;
write_reg(info, IER2, 0);
write_reg(info, (unsigned char)(timer + TMCS), 0);
info->irq_occurred = true;
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_timer()\n",
__FILE__,__LINE__,info->device_name);
}
static void isr_rxint(SLMP_INFO * info)
{
struct tty_struct *tty = info->port.tty;
struct mgsl_icount *icount = &info->icount;
unsigned char status = read_reg(info, SR1) & info->ie1_value & (FLGD + IDLD + CDCD + BRKD);
unsigned char status2 = read_reg(info, SR2) & info->ie2_value & OVRN;
if (status)
write_reg(info, SR1, status);
if (status2)
write_reg(info, SR2, status2);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_rxint status=%02X %02x\n",
__FILE__,__LINE__,info->device_name,status,status2);
if (info->params.mode == MGSL_MODE_ASYNC) {
if (status & BRKD) {
icount->brk++;
if (!(status & info->ignore_status_mask1)) {
if (info->read_status_mask1 & BRKD) {
tty_insert_flip_char(&info->port, 0, TTY_BREAK);
if (tty && (info->port.flags & ASYNC_SAK))
do_SAK(tty);
}
}
}
}
else {
if (status & (FLGD|IDLD)) {
if (status & FLGD)
info->icount.exithunt++;
else if (status & IDLD)
info->icount.rxidle++;
wake_up_interruptible(&info->event_wait_q);
}
}
if (status & CDCD) {
get_signals( info );
isr_io_pin(info,
MISCSTATUS_DCD_LATCHED|(info->serial_signals&SerialSignal_DCD));
}
}
static void isr_rxrdy(SLMP_INFO * info)
{
u16 status;
unsigned char DataByte;
struct mgsl_icount *icount = &info->icount;
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_rxrdy\n",
__FILE__,__LINE__,info->device_name);
while((status = read_reg(info,CST0)) & BIT0)
{
int flag = 0;
bool over = false;
DataByte = read_reg(info,TRB);
icount->rx++;
if ( status & (PE + FRME + OVRN) ) {
printk("%s(%d):%s rxerr=%04X\n",
__FILE__,__LINE__,info->device_name,status);
if (status & PE)
icount->parity++;
else if (status & FRME)
icount->frame++;
else if (status & OVRN)
icount->overrun++;
if (status & info->ignore_status_mask2)
continue;
status &= info->read_status_mask2;
if (status & PE)
flag = TTY_PARITY;
else if (status & FRME)
flag = TTY_FRAME;
if (status & OVRN) {
over = true;
}
}
tty_insert_flip_char(&info->port, DataByte, flag);
if (over)
tty_insert_flip_char(&info->port, 0, TTY_OVERRUN);
}
if ( debug_level >= DEBUG_LEVEL_ISR ) {
printk("%s(%d):%s rx=%d brk=%d parity=%d frame=%d overrun=%d\n",
__FILE__,__LINE__,info->device_name,
icount->rx,icount->brk,icount->parity,
icount->frame,icount->overrun);
}
tty_flip_buffer_push(&info->port);
}
static void isr_txeom(SLMP_INFO * info, unsigned char status)
{
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_txeom status=%02x\n",
__FILE__,__LINE__,info->device_name,status);
write_reg(info, TXDMA + DIR, 0x00);
write_reg(info, TXDMA + DSR, 0xc0);
write_reg(info, TXDMA + DCMD, SWABORT);
if (status & UDRN) {
write_reg(info, CMD, TXRESET);
write_reg(info, CMD, TXENABLE);
} else
write_reg(info, CMD, TXBUFCLR);
info->ie0_value &= ~TXRDYE;
info->ie1_value &= ~(IDLE + UDRN);
write_reg16(info, IE0, (unsigned short)((info->ie1_value << 8) + info->ie0_value));
write_reg(info, SR1, (unsigned char)(UDRN + IDLE));
if ( info->tx_active ) {
if (info->params.mode != MGSL_MODE_ASYNC) {
if (status & UDRN)
info->icount.txunder++;
else if (status & IDLE)
info->icount.txok++;
}
info->tx_active = false;
info->tx_count = info->tx_put = info->tx_get = 0;
del_timer(&info->tx_timer);
if (info->params.mode != MGSL_MODE_ASYNC && info->drop_rts_on_tx_done ) {
info->serial_signals &= ~SerialSignal_RTS;
info->drop_rts_on_tx_done = false;
set_signals(info);
}
#if SYNCLINK_GENERIC_HDLC
if (info->netcount)
hdlcdev_tx_done(info);
else
#endif
{
if (info->port.tty && (info->port.tty->stopped || info->port.tty->hw_stopped)) {
tx_stop(info);
return;
}
info->pending_bh |= BH_TRANSMIT;
}
}
}
static void isr_txint(SLMP_INFO * info)
{
unsigned char status = read_reg(info, SR1) & info->ie1_value & (UDRN + IDLE + CCTS);
write_reg(info, SR1, status);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_txint status=%02x\n",
__FILE__,__LINE__,info->device_name,status);
if (status & (UDRN + IDLE))
isr_txeom(info, status);
if (status & CCTS) {
get_signals( info );
isr_io_pin(info,
MISCSTATUS_CTS_LATCHED|(info->serial_signals&SerialSignal_CTS));
}
}
static void isr_txrdy(SLMP_INFO * info)
{
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_txrdy() tx_count=%d\n",
__FILE__,__LINE__,info->device_name,info->tx_count);
if (info->params.mode != MGSL_MODE_ASYNC) {
info->ie0_value &= ~TXRDYE;
info->ie1_value |= IDLE;
write_reg16(info, IE0, (unsigned short)((info->ie1_value << 8) + info->ie0_value));
return;
}
if (info->port.tty && (info->port.tty->stopped || info->port.tty->hw_stopped)) {
tx_stop(info);
return;
}
if ( info->tx_count )
tx_load_fifo( info );
else {
info->tx_active = false;
info->ie0_value &= ~TXRDYE;
write_reg(info, IE0, info->ie0_value);
}
if (info->tx_count < WAKEUP_CHARS)
info->pending_bh |= BH_TRANSMIT;
}
static void isr_rxdmaok(SLMP_INFO * info)
{
unsigned char status = read_reg(info,RXDMA + DSR) & 0xc0;
write_reg(info, RXDMA + DSR, (unsigned char)(status | 1));
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_rxdmaok(), status=%02x\n",
__FILE__,__LINE__,info->device_name,status);
info->pending_bh |= BH_RECEIVE;
}
static void isr_rxdmaerror(SLMP_INFO * info)
{
unsigned char status = read_reg(info,RXDMA + DSR) & 0x30;
write_reg(info, RXDMA + DSR, (unsigned char)(status | 1));
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_rxdmaerror(), status=%02x\n",
__FILE__,__LINE__,info->device_name,status);
info->rx_overflow = true;
info->pending_bh |= BH_RECEIVE;
}
static void isr_txdmaok(SLMP_INFO * info)
{
unsigned char status_reg1 = read_reg(info, SR1);
write_reg(info, TXDMA + DIR, 0x00);
write_reg(info, TXDMA + DSR, 0xc0);
write_reg(info, TXDMA + DCMD, SWABORT);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_txdmaok(), status=%02x\n",
__FILE__,__LINE__,info->device_name,status_reg1);
write_reg16(info, TRC0, 0);
info->ie0_value |= TXRDYE;
write_reg(info, IE0, info->ie0_value);
}
static void isr_txdmaerror(SLMP_INFO * info)
{
unsigned char status = read_reg(info,TXDMA + DSR) & 0x30;
write_reg(info, TXDMA + DSR, (unsigned char)(status | 1));
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s isr_txdmaerror(), status=%02x\n",
__FILE__,__LINE__,info->device_name,status);
}
static void isr_io_pin( SLMP_INFO *info, u16 status )
{
struct mgsl_icount *icount;
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):isr_io_pin status=%04X\n",
__FILE__,__LINE__,status);
if (status & (MISCSTATUS_CTS_LATCHED | MISCSTATUS_DCD_LATCHED |
MISCSTATUS_DSR_LATCHED | MISCSTATUS_RI_LATCHED) ) {
icount = &info->icount;
if (status & MISCSTATUS_RI_LATCHED) {
icount->rng++;
if ( status & SerialSignal_RI )
info->input_signal_events.ri_up++;
else
info->input_signal_events.ri_down++;
}
if (status & MISCSTATUS_DSR_LATCHED) {
icount->dsr++;
if ( status & SerialSignal_DSR )
info->input_signal_events.dsr_up++;
else
info->input_signal_events.dsr_down++;
}
if (status & MISCSTATUS_DCD_LATCHED) {
if ((info->dcd_chkcount)++ >= IO_PIN_SHUTDOWN_LIMIT) {
info->ie1_value &= ~CDCD;
write_reg(info, IE1, info->ie1_value);
}
icount->dcd++;
if (status & SerialSignal_DCD) {
info->input_signal_events.dcd_up++;
} else
info->input_signal_events.dcd_down++;
#if SYNCLINK_GENERIC_HDLC
if (info->netcount) {
if (status & SerialSignal_DCD)
netif_carrier_on(info->netdev);
else
netif_carrier_off(info->netdev);
}
#endif
}
if (status & MISCSTATUS_CTS_LATCHED)
{
if ((info->cts_chkcount)++ >= IO_PIN_SHUTDOWN_LIMIT) {
info->ie1_value &= ~CCTS;
write_reg(info, IE1, info->ie1_value);
}
icount->cts++;
if ( status & SerialSignal_CTS )
info->input_signal_events.cts_up++;
else
info->input_signal_events.cts_down++;
}
wake_up_interruptible(&info->status_event_wait_q);
wake_up_interruptible(&info->event_wait_q);
if ( (info->port.flags & ASYNC_CHECK_CD) &&
(status & MISCSTATUS_DCD_LATCHED) ) {
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s CD now %s...", info->device_name,
(status & SerialSignal_DCD) ? "on" : "off");
if (status & SerialSignal_DCD)
wake_up_interruptible(&info->port.open_wait);
else {
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("doing serial hangup...");
if (info->port.tty)
tty_hangup(info->port.tty);
}
}
if (tty_port_cts_enabled(&info->port) &&
(status & MISCSTATUS_CTS_LATCHED) ) {
if ( info->port.tty ) {
if (info->port.tty->hw_stopped) {
if (status & SerialSignal_CTS) {
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("CTS tx start...");
info->port.tty->hw_stopped = 0;
tx_start(info);
info->pending_bh |= BH_TRANSMIT;
return;
}
} else {
if (!(status & SerialSignal_CTS)) {
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("CTS tx stop...");
info->port.tty->hw_stopped = 1;
tx_stop(info);
}
}
}
}
}
info->pending_bh |= BH_STATUS;
}
static irqreturn_t synclinkmp_interrupt(int dummy, void *dev_id)
{
SLMP_INFO *info = dev_id;
unsigned char status, status0, status1=0;
unsigned char dmastatus, dmastatus0, dmastatus1=0;
unsigned char timerstatus0, timerstatus1=0;
unsigned char shift;
unsigned int i;
unsigned short tmp;
if ( debug_level >= DEBUG_LEVEL_ISR )
printk(KERN_DEBUG "%s(%d): synclinkmp_interrupt(%d)entry.\n",
__FILE__, __LINE__, info->irq_level);
spin_lock(&info->lock);
for(;;) {
tmp = read_reg16(info, ISR0);
status0 = (unsigned char)tmp;
dmastatus0 = (unsigned char)(tmp>>8);
timerstatus0 = read_reg(info, ISR2);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk(KERN_DEBUG "%s(%d):%s status0=%02x, dmastatus0=%02x, timerstatus0=%02x\n",
__FILE__, __LINE__, info->device_name,
status0, dmastatus0, timerstatus0);
if (info->port_count == 4) {
tmp = read_reg16(info->port_array[2], ISR0);
status1 = (unsigned char)tmp;
dmastatus1 = (unsigned char)(tmp>>8);
timerstatus1 = read_reg(info->port_array[2], ISR2);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s status1=%02x, dmastatus1=%02x, timerstatus1=%02x\n",
__FILE__,__LINE__,info->device_name,
status1,dmastatus1,timerstatus1);
}
if (!status0 && !dmastatus0 && !timerstatus0 &&
!status1 && !dmastatus1 && !timerstatus1)
break;
for(i=0; i < info->port_count ; i++) {
if (info->port_array[i] == NULL)
continue;
if (i < 2) {
status = status0;
dmastatus = dmastatus0;
} else {
status = status1;
dmastatus = dmastatus1;
}
shift = i & 1 ? 4 :0;
if (status & BIT0 << shift)
isr_rxrdy(info->port_array[i]);
if (status & BIT1 << shift)
isr_txrdy(info->port_array[i]);
if (status & BIT2 << shift)
isr_rxint(info->port_array[i]);
if (status & BIT3 << shift)
isr_txint(info->port_array[i]);
if (dmastatus & BIT0 << shift)
isr_rxdmaerror(info->port_array[i]);
if (dmastatus & BIT1 << shift)
isr_rxdmaok(info->port_array[i]);
if (dmastatus & BIT2 << shift)
isr_txdmaerror(info->port_array[i]);
if (dmastatus & BIT3 << shift)
isr_txdmaok(info->port_array[i]);
}
if (timerstatus0 & (BIT5 | BIT4))
isr_timer(info->port_array[0]);
if (timerstatus0 & (BIT7 | BIT6))
isr_timer(info->port_array[1]);
if (timerstatus1 & (BIT5 | BIT4))
isr_timer(info->port_array[2]);
if (timerstatus1 & (BIT7 | BIT6))
isr_timer(info->port_array[3]);
}
for(i=0; i < info->port_count ; i++) {
SLMP_INFO * port = info->port_array[i];
if ( port && (port->port.count || port->netcount) &&
port->pending_bh && !port->bh_running &&
!port->bh_requested ) {
if ( debug_level >= DEBUG_LEVEL_ISR )
printk("%s(%d):%s queueing bh task.\n",
__FILE__,__LINE__,port->device_name);
schedule_work(&port->task);
port->bh_requested = true;
}
}
spin_unlock(&info->lock);
if ( debug_level >= DEBUG_LEVEL_ISR )
printk(KERN_DEBUG "%s(%d):synclinkmp_interrupt(%d)exit.\n",
__FILE__, __LINE__, info->irq_level);
return IRQ_HANDLED;
}
static int startup(SLMP_INFO * info)
{
if ( debug_level >= DEBUG_LEVEL_INFO )
printk("%s(%d):%s tx_releaseup()\n",__FILE__,__LINE__,info->device_name);
if (info->port.flags & ASYNC_INITIALIZED)
return 0;
if (!info->tx_buf) {
info->tx_buf = kmalloc(info->max_frame_size, GFP_KERNEL);
if (!info->tx_buf) {
printk(KERN_ERR"%s(%d):%s can't allocate transmit buffer\n",
__FILE__,__LINE__,info->device_name);
return -ENOMEM;
}
}
info->pending_bh = 0;
memset(&info->icount, 0, sizeof(info->icount));
reset_port(info);
change_params(info);
mod_timer(&info->status_timer, jiffies + msecs_to_jiffies(10));
if (info->port.tty)
clear_bit(TTY_IO_ERROR, &info->port.tty->flags);
info->port.flags |= ASYNC_INITIALIZED;
return 0;
}
static void shutdown(SLMP_INFO * info)
{
unsigned long flags;
if (!(info->port.flags & ASYNC_INITIALIZED))
return;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s synclinkmp_shutdown()\n",
__FILE__,__LINE__, info->device_name );
wake_up_interruptible(&info->status_event_wait_q);
wake_up_interruptible(&info->event_wait_q);
del_timer(&info->tx_timer);
del_timer(&info->status_timer);
kfree(info->tx_buf);
info->tx_buf = NULL;
spin_lock_irqsave(&info->lock,flags);
reset_port(info);
if (!info->port.tty || info->port.tty->termios.c_cflag & HUPCL) {
info->serial_signals &= ~(SerialSignal_RTS | SerialSignal_DTR);
set_signals(info);
}
spin_unlock_irqrestore(&info->lock,flags);
if (info->port.tty)
set_bit(TTY_IO_ERROR, &info->port.tty->flags);
info->port.flags &= ~ASYNC_INITIALIZED;
}
static void program_hw(SLMP_INFO *info)
{
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
rx_stop(info);
tx_stop(info);
info->tx_count = info->tx_put = info->tx_get = 0;
if (info->params.mode == MGSL_MODE_HDLC || info->netcount)
hdlc_mode(info);
else
async_mode(info);
set_signals(info);
info->dcd_chkcount = 0;
info->cts_chkcount = 0;
info->ri_chkcount = 0;
info->dsr_chkcount = 0;
info->ie1_value |= (CDCD|CCTS);
write_reg(info, IE1, info->ie1_value);
get_signals(info);
if (info->netcount || (info->port.tty && info->port.tty->termios.c_cflag & CREAD) )
rx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
static void change_params(SLMP_INFO *info)
{
unsigned cflag;
int bits_per_char;
if (!info->port.tty)
return;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s change_params()\n",
__FILE__,__LINE__, info->device_name );
cflag = info->port.tty->termios.c_cflag;
if (cflag & CBAUD)
info->serial_signals |= SerialSignal_RTS | SerialSignal_DTR;
else
info->serial_signals &= ~(SerialSignal_RTS | SerialSignal_DTR);
switch (cflag & CSIZE) {
case CS5: info->params.data_bits = 5; break;
case CS6: info->params.data_bits = 6; break;
case CS7: info->params.data_bits = 7; break;
case CS8: info->params.data_bits = 8; break;
default: info->params.data_bits = 7; break;
}
if (cflag & CSTOPB)
info->params.stop_bits = 2;
else
info->params.stop_bits = 1;
info->params.parity = ASYNC_PARITY_NONE;
if (cflag & PARENB) {
if (cflag & PARODD)
info->params.parity = ASYNC_PARITY_ODD;
else
info->params.parity = ASYNC_PARITY_EVEN;
#ifdef CMSPAR
if (cflag & CMSPAR)
info->params.parity = ASYNC_PARITY_SPACE;
#endif
}
bits_per_char = info->params.data_bits +
info->params.stop_bits + 1;
if (info->params.data_rate <= 460800) {
info->params.data_rate = tty_get_baud_rate(info->port.tty);
}
if ( info->params.data_rate ) {
info->timeout = (32*HZ*bits_per_char) /
info->params.data_rate;
}
info->timeout += HZ/50;
if (cflag & CRTSCTS)
info->port.flags |= ASYNC_CTS_FLOW;
else
info->port.flags &= ~ASYNC_CTS_FLOW;
if (cflag & CLOCAL)
info->port.flags &= ~ASYNC_CHECK_CD;
else
info->port.flags |= ASYNC_CHECK_CD;
info->read_status_mask2 = OVRN;
if (I_INPCK(info->port.tty))
info->read_status_mask2 |= PE | FRME;
if (I_BRKINT(info->port.tty) || I_PARMRK(info->port.tty))
info->read_status_mask1 |= BRKD;
if (I_IGNPAR(info->port.tty))
info->ignore_status_mask2 |= PE | FRME;
if (I_IGNBRK(info->port.tty)) {
info->ignore_status_mask1 |= BRKD;
if (I_IGNPAR(info->port.tty))
info->ignore_status_mask2 |= OVRN;
}
program_hw(info);
}
static int get_stats(SLMP_INFO * info, struct mgsl_icount __user *user_icount)
{
int err;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s get_params()\n",
__FILE__,__LINE__, info->device_name);
if (!user_icount) {
memset(&info->icount, 0, sizeof(info->icount));
} else {
mutex_lock(&info->port.mutex);
COPY_TO_USER(err, user_icount, &info->icount, sizeof(struct mgsl_icount));
mutex_unlock(&info->port.mutex);
if (err)
return -EFAULT;
}
return 0;
}
static int get_params(SLMP_INFO * info, MGSL_PARAMS __user *user_params)
{
int err;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s get_params()\n",
__FILE__,__LINE__, info->device_name);
mutex_lock(&info->port.mutex);
COPY_TO_USER(err,user_params, &info->params, sizeof(MGSL_PARAMS));
mutex_unlock(&info->port.mutex);
if (err) {
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s get_params() user buffer copy failed\n",
__FILE__,__LINE__,info->device_name);
return -EFAULT;
}
return 0;
}
static int set_params(SLMP_INFO * info, MGSL_PARAMS __user *new_params)
{
unsigned long flags;
MGSL_PARAMS tmp_params;
int err;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s set_params\n",
__FILE__,__LINE__,info->device_name );
COPY_FROM_USER(err,&tmp_params, new_params, sizeof(MGSL_PARAMS));
if (err) {
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s set_params() user buffer copy failed\n",
__FILE__,__LINE__,info->device_name);
return -EFAULT;
}
mutex_lock(&info->port.mutex);
spin_lock_irqsave(&info->lock,flags);
memcpy(&info->params,&tmp_params,sizeof(MGSL_PARAMS));
spin_unlock_irqrestore(&info->lock,flags);
change_params(info);
mutex_unlock(&info->port.mutex);
return 0;
}
static int get_txidle(SLMP_INFO * info, int __user *idle_mode)
{
int err;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s get_txidle()=%d\n",
__FILE__,__LINE__, info->device_name, info->idle_mode);
COPY_TO_USER(err,idle_mode, &info->idle_mode, sizeof(int));
if (err) {
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s get_txidle() user buffer copy failed\n",
__FILE__,__LINE__,info->device_name);
return -EFAULT;
}
return 0;
}
static int set_txidle(SLMP_INFO * info, int idle_mode)
{
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s set_txidle(%d)\n",
__FILE__,__LINE__,info->device_name, idle_mode );
spin_lock_irqsave(&info->lock,flags);
info->idle_mode = idle_mode;
tx_set_idle( info );
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int tx_enable(SLMP_INFO * info, int enable)
{
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s tx_enable(%d)\n",
__FILE__,__LINE__,info->device_name, enable);
spin_lock_irqsave(&info->lock,flags);
if ( enable ) {
if ( !info->tx_enabled ) {
tx_start(info);
}
} else {
if ( info->tx_enabled )
tx_stop(info);
}
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int tx_abort(SLMP_INFO * info)
{
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s tx_abort()\n",
__FILE__,__LINE__,info->device_name);
spin_lock_irqsave(&info->lock,flags);
if ( info->tx_active && info->params.mode == MGSL_MODE_HDLC ) {
info->ie1_value &= ~UDRN;
info->ie1_value |= IDLE;
write_reg(info, IE1, info->ie1_value);
write_reg(info, SR1, (unsigned char)(IDLE + UDRN));
write_reg(info, TXDMA + DSR, 0);
write_reg(info, TXDMA + DCMD, SWABORT);
write_reg(info, CMD, TXABORT);
}
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int rx_enable(SLMP_INFO * info, int enable)
{
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s rx_enable(%d)\n",
__FILE__,__LINE__,info->device_name,enable);
spin_lock_irqsave(&info->lock,flags);
if ( enable ) {
if ( !info->rx_enabled )
rx_start(info);
} else {
if ( info->rx_enabled )
rx_stop(info);
}
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int wait_mgsl_event(SLMP_INFO * info, int __user *mask_ptr)
{
unsigned long flags;
int s;
int rc=0;
struct mgsl_icount cprev, cnow;
int events;
int mask;
struct _input_signal_events oldsigs, newsigs;
DECLARE_WAITQUEUE(wait, current);
COPY_FROM_USER(rc,&mask, mask_ptr, sizeof(int));
if (rc) {
return -EFAULT;
}
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s wait_mgsl_event(%d)\n",
__FILE__,__LINE__,info->device_name,mask);
spin_lock_irqsave(&info->lock,flags);
get_signals(info);
s = info->serial_signals;
events = mask &
( ((s & SerialSignal_DSR) ? MgslEvent_DsrActive:MgslEvent_DsrInactive) +
((s & SerialSignal_DCD) ? MgslEvent_DcdActive:MgslEvent_DcdInactive) +
((s & SerialSignal_CTS) ? MgslEvent_CtsActive:MgslEvent_CtsInactive) +
((s & SerialSignal_RI) ? MgslEvent_RiActive :MgslEvent_RiInactive) );
if (events) {
spin_unlock_irqrestore(&info->lock,flags);
goto exit;
}
cprev = info->icount;
oldsigs = info->input_signal_events;
if (mask & (MgslEvent_ExitHuntMode+MgslEvent_IdleReceived)) {
unsigned char oldval = info->ie1_value;
unsigned char newval = oldval +
(mask & MgslEvent_ExitHuntMode ? FLGD:0) +
(mask & MgslEvent_IdleReceived ? IDLD:0);
if ( oldval != newval ) {
info->ie1_value = newval;
write_reg(info, IE1, info->ie1_value);
}
}
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&info->event_wait_q, &wait);
spin_unlock_irqrestore(&info->lock,flags);
for(;;) {
schedule();
if (signal_pending(current)) {
rc = -ERESTARTSYS;
break;
}
spin_lock_irqsave(&info->lock,flags);
cnow = info->icount;
newsigs = info->input_signal_events;
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&info->lock,flags);
if (newsigs.dsr_up == oldsigs.dsr_up &&
newsigs.dsr_down == oldsigs.dsr_down &&
newsigs.dcd_up == oldsigs.dcd_up &&
newsigs.dcd_down == oldsigs.dcd_down &&
newsigs.cts_up == oldsigs.cts_up &&
newsigs.cts_down == oldsigs.cts_down &&
newsigs.ri_up == oldsigs.ri_up &&
newsigs.ri_down == oldsigs.ri_down &&
cnow.exithunt == cprev.exithunt &&
cnow.rxidle == cprev.rxidle) {
rc = -EIO;
break;
}
events = mask &
( (newsigs.dsr_up != oldsigs.dsr_up ? MgslEvent_DsrActive:0) +
(newsigs.dsr_down != oldsigs.dsr_down ? MgslEvent_DsrInactive:0) +
(newsigs.dcd_up != oldsigs.dcd_up ? MgslEvent_DcdActive:0) +
(newsigs.dcd_down != oldsigs.dcd_down ? MgslEvent_DcdInactive:0) +
(newsigs.cts_up != oldsigs.cts_up ? MgslEvent_CtsActive:0) +
(newsigs.cts_down != oldsigs.cts_down ? MgslEvent_CtsInactive:0) +
(newsigs.ri_up != oldsigs.ri_up ? MgslEvent_RiActive:0) +
(newsigs.ri_down != oldsigs.ri_down ? MgslEvent_RiInactive:0) +
(cnow.exithunt != cprev.exithunt ? MgslEvent_ExitHuntMode:0) +
(cnow.rxidle != cprev.rxidle ? MgslEvent_IdleReceived:0) );
if (events)
break;
cprev = cnow;
oldsigs = newsigs;
}
remove_wait_queue(&info->event_wait_q, &wait);
set_current_state(TASK_RUNNING);
if (mask & (MgslEvent_ExitHuntMode + MgslEvent_IdleReceived)) {
spin_lock_irqsave(&info->lock,flags);
if (!waitqueue_active(&info->event_wait_q)) {
info->ie1_value &= ~(FLGD|IDLD);
write_reg(info, IE1, info->ie1_value);
}
spin_unlock_irqrestore(&info->lock,flags);
}
exit:
if ( rc == 0 )
PUT_USER(rc, events, mask_ptr);
return rc;
}
static int modem_input_wait(SLMP_INFO *info,int arg)
{
unsigned long flags;
int rc;
struct mgsl_icount cprev, cnow;
DECLARE_WAITQUEUE(wait, current);
spin_lock_irqsave(&info->lock,flags);
cprev = info->icount;
add_wait_queue(&info->status_event_wait_q, &wait);
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&info->lock,flags);
for(;;) {
schedule();
if (signal_pending(current)) {
rc = -ERESTARTSYS;
break;
}
spin_lock_irqsave(&info->lock,flags);
cnow = info->icount;
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&info->lock,flags);
if (cnow.rng == cprev.rng && cnow.dsr == cprev.dsr &&
cnow.dcd == cprev.dcd && cnow.cts == cprev.cts) {
rc = -EIO;
break;
}
if ((arg & TIOCM_RNG && cnow.rng != cprev.rng) ||
(arg & TIOCM_DSR && cnow.dsr != cprev.dsr) ||
(arg & TIOCM_CD && cnow.dcd != cprev.dcd) ||
(arg & TIOCM_CTS && cnow.cts != cprev.cts)) {
rc = 0;
break;
}
cprev = cnow;
}
remove_wait_queue(&info->status_event_wait_q, &wait);
set_current_state(TASK_RUNNING);
return rc;
}
static int tiocmget(struct tty_struct *tty)
{
SLMP_INFO *info = tty->driver_data;
unsigned int result;
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
get_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
result = ((info->serial_signals & SerialSignal_RTS) ? TIOCM_RTS : 0) |
((info->serial_signals & SerialSignal_DTR) ? TIOCM_DTR : 0) |
((info->serial_signals & SerialSignal_DCD) ? TIOCM_CAR : 0) |
((info->serial_signals & SerialSignal_RI) ? TIOCM_RNG : 0) |
((info->serial_signals & SerialSignal_DSR) ? TIOCM_DSR : 0) |
((info->serial_signals & SerialSignal_CTS) ? TIOCM_CTS : 0);
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s tiocmget() value=%08X\n",
__FILE__,__LINE__, info->device_name, result );
return result;
}
static int tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
SLMP_INFO *info = tty->driver_data;
unsigned long flags;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s tiocmset(%x,%x)\n",
__FILE__,__LINE__,info->device_name, set, clear);
if (set & TIOCM_RTS)
info->serial_signals |= SerialSignal_RTS;
if (set & TIOCM_DTR)
info->serial_signals |= SerialSignal_DTR;
if (clear & TIOCM_RTS)
info->serial_signals &= ~SerialSignal_RTS;
if (clear & TIOCM_DTR)
info->serial_signals &= ~SerialSignal_DTR;
spin_lock_irqsave(&info->lock,flags);
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
return 0;
}
static int carrier_raised(struct tty_port *port)
{
SLMP_INFO *info = container_of(port, SLMP_INFO, port);
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
get_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
return (info->serial_signals & SerialSignal_DCD) ? 1 : 0;
}
static void dtr_rts(struct tty_port *port, int on)
{
SLMP_INFO *info = container_of(port, SLMP_INFO, port);
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
if (on)
info->serial_signals |= SerialSignal_RTS | SerialSignal_DTR;
else
info->serial_signals &= ~(SerialSignal_RTS | SerialSignal_DTR);
set_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
}
static int block_til_ready(struct tty_struct *tty, struct file *filp,
SLMP_INFO *info)
{
DECLARE_WAITQUEUE(wait, current);
int retval;
bool do_clocal = false;
bool extra_count = false;
unsigned long flags;
int cd;
struct tty_port *port = &info->port;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s block_til_ready()\n",
__FILE__,__LINE__, tty->driver->name );
if (filp->f_flags & O_NONBLOCK || tty->flags & (1 << TTY_IO_ERROR)){
port->flags |= ASYNC_NORMAL_ACTIVE;
return 0;
}
if (tty->termios.c_cflag & CLOCAL)
do_clocal = true;
retval = 0;
add_wait_queue(&port->open_wait, &wait);
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s block_til_ready() before block, count=%d\n",
__FILE__,__LINE__, tty->driver->name, port->count );
spin_lock_irqsave(&info->lock, flags);
if (!tty_hung_up_p(filp)) {
extra_count = true;
port->count--;
}
spin_unlock_irqrestore(&info->lock, flags);
port->blocked_open++;
while (1) {
if (C_BAUD(tty) && test_bit(ASYNCB_INITIALIZED, &port->flags))
tty_port_raise_dtr_rts(port);
set_current_state(TASK_INTERRUPTIBLE);
if (tty_hung_up_p(filp) || !(port->flags & ASYNC_INITIALIZED)){
retval = (port->flags & ASYNC_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS;
break;
}
cd = tty_port_carrier_raised(port);
if (!(port->flags & ASYNC_CLOSING) && (do_clocal || cd))
break;
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s block_til_ready() count=%d\n",
__FILE__,__LINE__, tty->driver->name, port->count );
tty_unlock(tty);
schedule();
tty_lock(tty);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&port->open_wait, &wait);
if (extra_count)
port->count++;
port->blocked_open--;
if (debug_level >= DEBUG_LEVEL_INFO)
printk("%s(%d):%s block_til_ready() after, count=%d\n",
__FILE__,__LINE__, tty->driver->name, port->count );
if (!retval)
port->flags |= ASYNC_NORMAL_ACTIVE;
return retval;
}
static int alloc_dma_bufs(SLMP_INFO *info)
{
unsigned short BuffersPerFrame;
unsigned short BufferCount;
info->port_array[0]->last_mem_alloc = (SCA_MEM_SIZE/4) * info->port_num;
BuffersPerFrame = (unsigned short)(info->max_frame_size/SCABUFSIZE);
if ( info->max_frame_size % SCABUFSIZE )
BuffersPerFrame++;
BufferCount = (SCA_MEM_SIZE/4 - BUFFERLISTSIZE)/SCABUFSIZE;
if (BufferCount > BUFFERLISTSIZE/sizeof(SCADESC))
BufferCount = BUFFERLISTSIZE/sizeof(SCADESC);
info->tx_buf_count = BuffersPerFrame + 1;
if (info->tx_buf_count > (BufferCount/2))
info->tx_buf_count = BufferCount/2;
if (info->tx_buf_count > SCAMAXDESC)
info->tx_buf_count = SCAMAXDESC;
info->rx_buf_count = BufferCount - info->tx_buf_count;
if (info->rx_buf_count > SCAMAXDESC)
info->rx_buf_count = SCAMAXDESC;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk("%s(%d):%s Allocating %d TX and %d RX DMA buffers.\n",
__FILE__,__LINE__, info->device_name,
info->tx_buf_count,info->rx_buf_count);
if ( alloc_buf_list( info ) < 0 ||
alloc_frame_bufs(info,
info->rx_buf_list,
info->rx_buf_list_ex,
info->rx_buf_count) < 0 ||
alloc_frame_bufs(info,
info->tx_buf_list,
info->tx_buf_list_ex,
info->tx_buf_count) < 0 ||
alloc_tmp_rx_buf(info) < 0 ) {
printk("%s(%d):%s Can't allocate DMA buffer memory\n",
__FILE__,__LINE__, info->device_name);
return -ENOMEM;
}
rx_reset_buffers( info );
return 0;
}
static int alloc_buf_list(SLMP_INFO *info)
{
unsigned int i;
info->buffer_list = info->memory_base + info->port_array[0]->last_mem_alloc;
info->buffer_list_phys = info->port_array[0]->last_mem_alloc;
info->port_array[0]->last_mem_alloc += BUFFERLISTSIZE;
memset(info->buffer_list, 0, BUFFERLISTSIZE);
info->rx_buf_list = (SCADESC *)info->buffer_list;
info->tx_buf_list = (SCADESC *)info->buffer_list;
info->tx_buf_list += info->rx_buf_count;
for ( i = 0; i < info->rx_buf_count; i++ ) {
info->rx_buf_list_ex[i].phys_entry =
info->buffer_list_phys + (i * SCABUFSIZE);
info->rx_buf_list[i].next = info->buffer_list_phys;
if ( i < info->rx_buf_count - 1 )
info->rx_buf_list[i].next += (i + 1) * sizeof(SCADESC);
info->rx_buf_list[i].length = SCABUFSIZE;
}
for ( i = 0; i < info->tx_buf_count; i++ ) {
info->tx_buf_list_ex[i].phys_entry = info->buffer_list_phys +
((info->rx_buf_count + i) * sizeof(SCADESC));
info->tx_buf_list[i].next = info->buffer_list_phys +
info->rx_buf_count * sizeof(SCADESC);
if ( i < info->tx_buf_count - 1 )
info->tx_buf_list[i].next += (i + 1) * sizeof(SCADESC);
}
return 0;
}
static int alloc_frame_bufs(SLMP_INFO *info, SCADESC *buf_list,SCADESC_EX *buf_list_ex,int count)
{
int i;
unsigned long phys_addr;
for ( i = 0; i < count; i++ ) {
buf_list_ex[i].virt_addr = info->memory_base + info->port_array[0]->last_mem_alloc;
phys_addr = info->port_array[0]->last_mem_alloc;
info->port_array[0]->last_mem_alloc += SCABUFSIZE;
buf_list[i].buf_ptr = (unsigned short)phys_addr;
buf_list[i].buf_base = (unsigned char)(phys_addr >> 16);
}
return 0;
}
static void free_dma_bufs(SLMP_INFO *info)
{
info->buffer_list = NULL;
info->rx_buf_list = NULL;
info->tx_buf_list = NULL;
}
static int alloc_tmp_rx_buf(SLMP_INFO *info)
{
info->tmp_rx_buf = kmalloc(info->max_frame_size, GFP_KERNEL);
if (info->tmp_rx_buf == NULL)
return -ENOMEM;
info->flag_buf = kzalloc(info->max_frame_size, GFP_KERNEL);
if (!info->flag_buf) {
kfree(info->tmp_rx_buf);
info->tmp_rx_buf = NULL;
return -ENOMEM;
}
return 0;
}
static void free_tmp_rx_buf(SLMP_INFO *info)
{
kfree(info->tmp_rx_buf);
info->tmp_rx_buf = NULL;
kfree(info->flag_buf);
info->flag_buf = NULL;
}
static int claim_resources(SLMP_INFO *info)
{
if (request_mem_region(info->phys_memory_base,SCA_MEM_SIZE,"synclinkmp") == NULL) {
printk( "%s(%d):%s mem addr conflict, Addr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_memory_base);
info->init_error = DiagStatus_AddressConflict;
goto errout;
}
else
info->shared_mem_requested = true;
if (request_mem_region(info->phys_lcr_base + info->lcr_offset,128,"synclinkmp") == NULL) {
printk( "%s(%d):%s lcr mem addr conflict, Addr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_lcr_base);
info->init_error = DiagStatus_AddressConflict;
goto errout;
}
else
info->lcr_mem_requested = true;
if (request_mem_region(info->phys_sca_base + info->sca_offset,SCA_BASE_SIZE,"synclinkmp") == NULL) {
printk( "%s(%d):%s sca mem addr conflict, Addr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_sca_base);
info->init_error = DiagStatus_AddressConflict;
goto errout;
}
else
info->sca_base_requested = true;
if (request_mem_region(info->phys_statctrl_base + info->statctrl_offset,SCA_REG_SIZE,"synclinkmp") == NULL) {
printk( "%s(%d):%s stat/ctrl mem addr conflict, Addr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_statctrl_base);
info->init_error = DiagStatus_AddressConflict;
goto errout;
}
else
info->sca_statctrl_requested = true;
info->memory_base = ioremap_nocache(info->phys_memory_base,
SCA_MEM_SIZE);
if (!info->memory_base) {
printk( "%s(%d):%s Can't map shared memory, MemAddr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_memory_base );
info->init_error = DiagStatus_CantAssignPciResources;
goto errout;
}
info->lcr_base = ioremap_nocache(info->phys_lcr_base, PAGE_SIZE);
if (!info->lcr_base) {
printk( "%s(%d):%s Can't map LCR memory, MemAddr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_lcr_base );
info->init_error = DiagStatus_CantAssignPciResources;
goto errout;
}
info->lcr_base += info->lcr_offset;
info->sca_base = ioremap_nocache(info->phys_sca_base, PAGE_SIZE);
if (!info->sca_base) {
printk( "%s(%d):%s Can't map SCA memory, MemAddr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_sca_base );
info->init_error = DiagStatus_CantAssignPciResources;
goto errout;
}
info->sca_base += info->sca_offset;
info->statctrl_base = ioremap_nocache(info->phys_statctrl_base,
PAGE_SIZE);
if (!info->statctrl_base) {
printk( "%s(%d):%s Can't map SCA Status/Control memory, MemAddr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_statctrl_base );
info->init_error = DiagStatus_CantAssignPciResources;
goto errout;
}
info->statctrl_base += info->statctrl_offset;
if ( !memory_test(info) ) {
printk( "%s(%d):Shared Memory Test failed for device %s MemAddr=%08X\n",
__FILE__,__LINE__,info->device_name, info->phys_memory_base );
info->init_error = DiagStatus_MemoryError;
goto errout;
}
return 0;
errout:
release_resources( info );
return -ENODEV;
}
static void release_resources(SLMP_INFO *info)
{
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s release_resources() entry\n",
__FILE__,__LINE__,info->device_name );
if ( info->irq_requested ) {
free_irq(info->irq_level, info);
info->irq_requested = false;
}
if ( info->shared_mem_requested ) {
release_mem_region(info->phys_memory_base,SCA_MEM_SIZE);
info->shared_mem_requested = false;
}
if ( info->lcr_mem_requested ) {
release_mem_region(info->phys_lcr_base + info->lcr_offset,128);
info->lcr_mem_requested = false;
}
if ( info->sca_base_requested ) {
release_mem_region(info->phys_sca_base + info->sca_offset,SCA_BASE_SIZE);
info->sca_base_requested = false;
}
if ( info->sca_statctrl_requested ) {
release_mem_region(info->phys_statctrl_base + info->statctrl_offset,SCA_REG_SIZE);
info->sca_statctrl_requested = false;
}
if (info->memory_base){
iounmap(info->memory_base);
info->memory_base = NULL;
}
if (info->sca_base) {
iounmap(info->sca_base - info->sca_offset);
info->sca_base=NULL;
}
if (info->statctrl_base) {
iounmap(info->statctrl_base - info->statctrl_offset);
info->statctrl_base=NULL;
}
if (info->lcr_base){
iounmap(info->lcr_base - info->lcr_offset);
info->lcr_base = NULL;
}
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s release_resources() exit\n",
__FILE__,__LINE__,info->device_name );
}
static void add_device(SLMP_INFO *info)
{
info->next_device = NULL;
info->line = synclinkmp_device_count;
sprintf(info->device_name,"ttySLM%dp%d",info->adapter_num,info->port_num);
if (info->line < MAX_DEVICES) {
if (maxframe[info->line])
info->max_frame_size = maxframe[info->line];
}
synclinkmp_device_count++;
if ( !synclinkmp_device_list )
synclinkmp_device_list = info;
else {
SLMP_INFO *current_dev = synclinkmp_device_list;
while( current_dev->next_device )
current_dev = current_dev->next_device;
current_dev->next_device = info;
}
if ( info->max_frame_size < 4096 )
info->max_frame_size = 4096;
else if ( info->max_frame_size > 65535 )
info->max_frame_size = 65535;
printk( "SyncLink MultiPort %s: "
"Mem=(%08x %08X %08x %08X) IRQ=%d MaxFrameSize=%u\n",
info->device_name,
info->phys_sca_base,
info->phys_memory_base,
info->phys_statctrl_base,
info->phys_lcr_base,
info->irq_level,
info->max_frame_size );
#if SYNCLINK_GENERIC_HDLC
hdlcdev_init(info);
#endif
}
static SLMP_INFO *alloc_dev(int adapter_num, int port_num, struct pci_dev *pdev)
{
SLMP_INFO *info;
info = kzalloc(sizeof(SLMP_INFO),
GFP_KERNEL);
if (!info) {
printk("%s(%d) Error can't allocate device instance data for adapter %d, port %d\n",
__FILE__,__LINE__, adapter_num, port_num);
} else {
tty_port_init(&info->port);
info->port.ops = &port_ops;
info->magic = MGSL_MAGIC;
INIT_WORK(&info->task, bh_handler);
info->max_frame_size = 4096;
info->port.close_delay = 5*HZ/10;
info->port.closing_wait = 30*HZ;
init_waitqueue_head(&info->status_event_wait_q);
init_waitqueue_head(&info->event_wait_q);
spin_lock_init(&info->netlock);
memcpy(&info->params,&default_params,sizeof(MGSL_PARAMS));
info->idle_mode = HDLC_TXIDLE_FLAGS;
info->adapter_num = adapter_num;
info->port_num = port_num;
info->irq_level = pdev->irq;
info->phys_lcr_base = pci_resource_start(pdev,0);
info->phys_sca_base = pci_resource_start(pdev,2);
info->phys_memory_base = pci_resource_start(pdev,3);
info->phys_statctrl_base = pci_resource_start(pdev,4);
info->lcr_offset = info->phys_lcr_base & (PAGE_SIZE-1);
info->phys_lcr_base &= ~(PAGE_SIZE-1);
info->sca_offset = info->phys_sca_base & (PAGE_SIZE-1);
info->phys_sca_base &= ~(PAGE_SIZE-1);
info->statctrl_offset = info->phys_statctrl_base & (PAGE_SIZE-1);
info->phys_statctrl_base &= ~(PAGE_SIZE-1);
info->bus_type = MGSL_BUS_TYPE_PCI;
info->irq_flags = IRQF_SHARED;
setup_timer(&info->tx_timer, tx_timeout, (unsigned long)info);
setup_timer(&info->status_timer, status_timeout,
(unsigned long)info);
info->misc_ctrl_value = 0x087e4546;
info->init_error = -1;
}
return info;
}
static void device_init(int adapter_num, struct pci_dev *pdev)
{
SLMP_INFO *port_array[SCA_MAX_PORTS];
int port;
for ( port = 0; port < SCA_MAX_PORTS; ++port ) {
port_array[port] = alloc_dev(adapter_num,port,pdev);
if( port_array[port] == NULL ) {
for (--port; port >= 0; --port) {
tty_port_destroy(&port_array[port]->port);
kfree(port_array[port]);
}
return;
}
}
for ( port = 0; port < SCA_MAX_PORTS; ++port ) {
memcpy(port_array[port]->port_array,port_array,sizeof(port_array));
add_device( port_array[port] );
spin_lock_init(&port_array[port]->lock);
}
if ( !claim_resources(port_array[0]) ) {
alloc_dma_bufs(port_array[0]);
for ( port = 1; port < SCA_MAX_PORTS; ++port ) {
port_array[port]->lock = port_array[0]->lock;
port_array[port]->irq_level = port_array[0]->irq_level;
port_array[port]->memory_base = port_array[0]->memory_base;
port_array[port]->sca_base = port_array[0]->sca_base;
port_array[port]->statctrl_base = port_array[0]->statctrl_base;
port_array[port]->lcr_base = port_array[0]->lcr_base;
alloc_dma_bufs(port_array[port]);
}
if ( request_irq(port_array[0]->irq_level,
synclinkmp_interrupt,
port_array[0]->irq_flags,
port_array[0]->device_name,
port_array[0]) < 0 ) {
printk( "%s(%d):%s Can't request interrupt, IRQ=%d\n",
__FILE__,__LINE__,
port_array[0]->device_name,
port_array[0]->irq_level );
}
else {
port_array[0]->irq_requested = true;
adapter_test(port_array[0]);
}
}
}
static void synclinkmp_cleanup(void)
{
int rc;
SLMP_INFO *info;
SLMP_INFO *tmp;
printk("Unloading %s %s\n", driver_name, driver_version);
if (serial_driver) {
if ((rc = tty_unregister_driver(serial_driver)))
printk("%s(%d) failed to unregister tty driver err=%d\n",
__FILE__,__LINE__,rc);
put_tty_driver(serial_driver);
}
info = synclinkmp_device_list;
while(info) {
reset_port(info);
info = info->next_device;
}
info = synclinkmp_device_list;
while(info) {
#if SYNCLINK_GENERIC_HDLC
hdlcdev_exit(info);
#endif
free_dma_bufs(info);
free_tmp_rx_buf(info);
if ( info->port_num == 0 ) {
if (info->sca_base)
write_reg(info, LPR, 1);
release_resources(info);
}
tmp = info;
info = info->next_device;
tty_port_destroy(&tmp->port);
kfree(tmp);
}
pci_unregister_driver(&synclinkmp_pci_driver);
}
static int __init synclinkmp_init(void)
{
int rc;
if (break_on_load) {
synclinkmp_get_text_ptr();
BREAKPOINT();
}
printk("%s %s\n", driver_name, driver_version);
if ((rc = pci_register_driver(&synclinkmp_pci_driver)) < 0) {
printk("%s:failed to register PCI driver, error=%d\n",__FILE__,rc);
return rc;
}
serial_driver = alloc_tty_driver(128);
if (!serial_driver) {
rc = -ENOMEM;
goto error;
}
serial_driver->driver_name = "synclinkmp";
serial_driver->name = "ttySLM";
serial_driver->major = ttymajor;
serial_driver->minor_start = 64;
serial_driver->type = TTY_DRIVER_TYPE_SERIAL;
serial_driver->subtype = SERIAL_TYPE_NORMAL;
serial_driver->init_termios = tty_std_termios;
serial_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
serial_driver->init_termios.c_ispeed = 9600;
serial_driver->init_termios.c_ospeed = 9600;
serial_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(serial_driver, &ops);
if ((rc = tty_register_driver(serial_driver)) < 0) {
printk("%s(%d):Couldn't register serial driver\n",
__FILE__,__LINE__);
put_tty_driver(serial_driver);
serial_driver = NULL;
goto error;
}
printk("%s %s, tty major#%d\n",
driver_name, driver_version,
serial_driver->major);
return 0;
error:
synclinkmp_cleanup();
return rc;
}
static void __exit synclinkmp_exit(void)
{
synclinkmp_cleanup();
}
static void enable_loopback(SLMP_INFO *info, int enable)
{
if (enable) {
write_reg(info, MD2, (unsigned char)(read_reg(info, MD2) | (BIT1 + BIT0)));
info->port_array[0]->ctrlreg_value |= (BIT0 << (info->port_num * 2));
write_control_reg(info);
write_reg(info, RXS, 0x40);
write_reg(info, TXS, 0x40);
} else {
write_reg(info, MD2, (unsigned char)(read_reg(info, MD2) & ~(BIT1 + BIT0)));
write_reg(info, RXS, 0x00);
write_reg(info, TXS, 0x00);
}
if (info->params.clock_speed)
set_rate(info, info->params.clock_speed);
else
set_rate(info, 3686400);
}
static void set_rate( SLMP_INFO *info, u32 data_rate )
{
u32 TMCValue;
unsigned char BRValue;
u32 Divisor=0;
if (data_rate != 0) {
Divisor = 14745600/data_rate;
if (!Divisor)
Divisor = 1;
TMCValue = Divisor;
BRValue = 0;
if (TMCValue != 1 && TMCValue != 2) {
BRValue = 1;
TMCValue >>= 1;
}
for(; TMCValue > 256 && BRValue < 10; BRValue++)
TMCValue >>= 1;
write_reg(info, TXS,
(unsigned char)((read_reg(info, TXS) & 0xf0) | BRValue));
write_reg(info, RXS,
(unsigned char)((read_reg(info, RXS) & 0xf0) | BRValue));
write_reg(info, TMC, (unsigned char)TMCValue);
}
else {
write_reg(info, TXS,0);
write_reg(info, RXS,0);
write_reg(info, TMC, 0);
}
}
static void rx_stop(SLMP_INFO *info)
{
if (debug_level >= DEBUG_LEVEL_ISR)
printk("%s(%d):%s rx_stop()\n",
__FILE__,__LINE__, info->device_name );
write_reg(info, CMD, RXRESET);
info->ie0_value &= ~RXRDYE;
write_reg(info, IE0, info->ie0_value);
write_reg(info, RXDMA + DSR, 0);
write_reg(info, RXDMA + DCMD, SWABORT);
write_reg(info, RXDMA + DIR, 0);
info->rx_enabled = false;
info->rx_overflow = false;
}
static void rx_start(SLMP_INFO *info)
{
int i;
if (debug_level >= DEBUG_LEVEL_ISR)
printk("%s(%d):%s rx_start()\n",
__FILE__,__LINE__, info->device_name );
write_reg(info, CMD, RXRESET);
if ( info->params.mode == MGSL_MODE_HDLC ) {
info->ie0_value &= ~RXRDYE;
write_reg(info, IE0, info->ie0_value);
write_reg(info, RXDMA + DSR, 0);
write_reg(info, RXDMA + DCMD, SWABORT);
for (i = 0; i < info->rx_buf_count; i++) {
info->rx_buf_list[i].status = 0xff;
if (!(i % 4))
read_status_reg(info);
}
info->current_rx_buf = 0;
write_reg16(info, RXDMA + CDA,
info->rx_buf_list_ex[0].phys_entry);
write_reg16(info, RXDMA + EDA,
info->rx_buf_list_ex[info->rx_buf_count - 1].phys_entry);
write_reg16(info, RXDMA + BFL, SCABUFSIZE);
write_reg(info, RXDMA + DIR, 0x60);
write_reg(info, RXDMA + DSR, 0xf2);
} else {
info->ie0_value |= RXRDYE;
write_reg(info, IE0, info->ie0_value);
}
write_reg(info, CMD, RXENABLE);
info->rx_overflow = false;
info->rx_enabled = true;
}
static void tx_start(SLMP_INFO *info)
{
if (debug_level >= DEBUG_LEVEL_ISR)
printk("%s(%d):%s tx_start() tx_count=%d\n",
__FILE__,__LINE__, info->device_name,info->tx_count );
if (!info->tx_enabled ) {
write_reg(info, CMD, TXRESET);
write_reg(info, CMD, TXENABLE);
info->tx_enabled = true;
}
if ( info->tx_count ) {
info->drop_rts_on_tx_done = false;
if (info->params.mode != MGSL_MODE_ASYNC) {
if ( info->params.flags & HDLC_FLAG_AUTO_RTS ) {
get_signals( info );
if ( !(info->serial_signals & SerialSignal_RTS) ) {
info->serial_signals |= SerialSignal_RTS;
set_signals( info );
info->drop_rts_on_tx_done = true;
}
}
write_reg16(info, TRC0,
(unsigned short)(((tx_negate_fifo_level-1)<<8) + tx_active_fifo_level));
write_reg(info, TXDMA + DSR, 0);
write_reg(info, TXDMA + DCMD, SWABORT);
write_reg16(info, TXDMA + CDA,
info->tx_buf_list_ex[0].phys_entry);
write_reg16(info, TXDMA + EDA,
info->tx_buf_list_ex[info->last_tx_buf].phys_entry);
info->ie1_value &= ~IDLE;
info->ie1_value |= UDRN;
write_reg(info, IE1, info->ie1_value);
write_reg(info, SR1, (unsigned char)(IDLE + UDRN));
write_reg(info, TXDMA + DIR, 0x40);
write_reg(info, TXDMA + DSR, 0xf2);
mod_timer(&info->tx_timer, jiffies +
msecs_to_jiffies(5000));
}
else {
tx_load_fifo(info);
info->ie0_value |= TXRDYE;
write_reg(info, IE0, info->ie0_value);
}
info->tx_active = true;
}
}
static void tx_stop( SLMP_INFO *info )
{
if (debug_level >= DEBUG_LEVEL_ISR)
printk("%s(%d):%s tx_stop()\n",
__FILE__,__LINE__, info->device_name );
del_timer(&info->tx_timer);
write_reg(info, TXDMA + DSR, 0);
write_reg(info, TXDMA + DCMD, SWABORT);
write_reg(info, CMD, TXRESET);
info->ie1_value &= ~(UDRN + IDLE);
write_reg(info, IE1, info->ie1_value);
write_reg(info, SR1, (unsigned char)(IDLE + UDRN));
info->ie0_value &= ~TXRDYE;
write_reg(info, IE0, info->ie0_value);
info->tx_enabled = false;
info->tx_active = false;
}
static void tx_load_fifo(SLMP_INFO *info)
{
u8 TwoBytes[2];
if ( !info->tx_count && !info->x_char )
return;
while( info->tx_count && (read_reg(info,SR0) & BIT1) ) {
if ( (info->tx_count > 1) && !info->x_char ) {
TwoBytes[0] = info->tx_buf[info->tx_get++];
if (info->tx_get >= info->max_frame_size)
info->tx_get -= info->max_frame_size;
TwoBytes[1] = info->tx_buf[info->tx_get++];
if (info->tx_get >= info->max_frame_size)
info->tx_get -= info->max_frame_size;
write_reg16(info, TRB, *((u16 *)TwoBytes));
info->tx_count -= 2;
info->icount.tx += 2;
} else {
if (info->x_char) {
write_reg(info, TRB, info->x_char);
info->x_char = 0;
} else {
write_reg(info, TRB, info->tx_buf[info->tx_get++]);
if (info->tx_get >= info->max_frame_size)
info->tx_get -= info->max_frame_size;
info->tx_count--;
}
info->icount.tx++;
}
}
}
static void reset_port(SLMP_INFO *info)
{
if (info->sca_base) {
tx_stop(info);
rx_stop(info);
info->serial_signals &= ~(SerialSignal_RTS | SerialSignal_DTR);
set_signals(info);
info->ie0_value = 0;
info->ie1_value = 0;
info->ie2_value = 0;
write_reg(info, IE0, info->ie0_value);
write_reg(info, IE1, info->ie1_value);
write_reg(info, IE2, info->ie2_value);
write_reg(info, CMD, CHRESET);
}
}
static void reset_adapter(SLMP_INFO *info)
{
int i;
for ( i=0; i < SCA_MAX_PORTS; ++i) {
if (info->port_array[i])
reset_port(info->port_array[i]);
}
}
static void async_mode(SLMP_INFO *info)
{
unsigned char RegValue;
tx_stop(info);
rx_stop(info);
RegValue = 0x00;
if (info->params.stop_bits != 1)
RegValue |= BIT1;
write_reg(info, MD0, RegValue);
RegValue = 0x40;
switch (info->params.data_bits) {
case 7: RegValue |= BIT4 + BIT2; break;
case 6: RegValue |= BIT5 + BIT3; break;
case 5: RegValue |= BIT5 + BIT4 + BIT3 + BIT2; break;
}
if (info->params.parity != ASYNC_PARITY_NONE) {
RegValue |= BIT1;
if (info->params.parity == ASYNC_PARITY_ODD)
RegValue |= BIT0;
}
write_reg(info, MD1, RegValue);
RegValue = 0x00;
if (info->params.loopback)
RegValue |= (BIT1 + BIT0);
write_reg(info, MD2, RegValue);
RegValue=BIT6;
write_reg(info, RXS, RegValue);
RegValue=BIT6;
write_reg(info, TXS, RegValue);
info->port_array[0]->ctrlreg_value |= (BIT0 << (info->port_num * 2));
write_control_reg(info);
tx_set_idle(info);
write_reg(info, RRC, 0x00);
write_reg(info, TRC0, 0x10);
write_reg(info, TRC1, 0x1e);
RegValue = 0x10;
if (!(info->serial_signals & SerialSignal_RTS))
RegValue |= 0x01;
write_reg(info, CTL, RegValue);
info->ie0_value |= TXINTE + RXINTE;
write_reg(info, IE0, info->ie0_value);
info->ie1_value = BRKD;
write_reg(info, IE1, info->ie1_value);
info->ie2_value = OVRN;
write_reg(info, IE2, info->ie2_value);
set_rate( info, info->params.data_rate * 16 );
}
static void hdlc_mode(SLMP_INFO *info)
{
unsigned char RegValue;
u32 DpllDivisor;
info->params.flags &= ~(HDLC_FLAG_TXC_DPLL + HDLC_FLAG_RXC_DPLL);
write_reg(info, TXDMA + DIR, 0);
write_reg(info, RXDMA + DIR, 0);
RegValue = 0x81;
if (info->params.flags & HDLC_FLAG_AUTO_CTS)
RegValue |= BIT4;
if (info->params.flags & HDLC_FLAG_AUTO_DCD)
RegValue |= BIT4;
if (info->params.crc_type == HDLC_CRC_16_CCITT)
RegValue |= BIT2 + BIT1;
write_reg(info, MD0, RegValue);
RegValue = 0x00;
write_reg(info, MD1, RegValue);
RegValue = 0x00;
switch(info->params.encoding) {
case HDLC_ENCODING_NRZI: RegValue |= BIT5; break;
case HDLC_ENCODING_BIPHASE_MARK: RegValue |= BIT7 + BIT5; break;
case HDLC_ENCODING_BIPHASE_SPACE: RegValue |= BIT7 + BIT6; break;
case HDLC_ENCODING_BIPHASE_LEVEL: RegValue |= BIT7; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( info->params.flags & HDLC_FLAG_DPLL_DIV16 ) {
DpllDivisor = 16;
RegValue |= BIT3;
} else if ( info->params.flags & HDLC_FLAG_DPLL_DIV8 ) {
DpllDivisor = 8;
} else {
DpllDivisor = 32;
RegValue |= BIT4;
}
write_reg(info, MD2, RegValue);
RegValue=0;
if (info->params.flags & HDLC_FLAG_RXC_BRG)
RegValue |= BIT6;
if (info->params.flags & HDLC_FLAG_RXC_DPLL)
RegValue |= BIT6 + BIT5;
write_reg(info, RXS, RegValue);
RegValue=0;
if (info->params.flags & HDLC_FLAG_TXC_BRG)
RegValue |= BIT6;
if (info->params.flags & HDLC_FLAG_TXC_DPLL)
RegValue |= BIT6 + BIT5;
write_reg(info, TXS, RegValue);
if (info->params.flags & HDLC_FLAG_RXC_DPLL)
set_rate(info, info->params.clock_speed * DpllDivisor);
else
set_rate(info, info->params.clock_speed);
if (info->params.flags & HDLC_FLAG_TXC_BRG)
info->port_array[0]->ctrlreg_value |= (BIT0 << (info->port_num * 2));
else
info->port_array[0]->ctrlreg_value &= ~(BIT0 << (info->port_num * 2));
write_control_reg(info);
write_reg(info, RRC, rx_active_fifo_level);
write_reg(info, TRC0, tx_active_fifo_level);
write_reg(info, TRC1, (unsigned char)(tx_negate_fifo_level - 1));
write_reg(info, TXDMA + DMR, 0x14);
write_reg(info, RXDMA + DMR, 0x14);
write_reg(info, RXDMA + CPB,
(unsigned char)(info->buffer_list_phys >> 16));
write_reg(info, TXDMA + CPB,
(unsigned char)(info->buffer_list_phys >> 16));
info->ie0_value |= TXINTE + RXINTE;
write_reg(info, IE0, info->ie0_value);
RegValue = 0x10;
if (!(info->serial_signals & SerialSignal_RTS))
RegValue |= 0x01;
write_reg(info, CTL, RegValue);
tx_set_idle(info);
tx_stop(info);
rx_stop(info);
set_rate(info, info->params.clock_speed);
if (info->params.loopback)
enable_loopback(info,1);
}
static void tx_set_idle(SLMP_INFO *info)
{
unsigned char RegValue = 0xff;
switch(info->idle_mode) {
case HDLC_TXIDLE_FLAGS: RegValue = 0x7e; break;
case HDLC_TXIDLE_ALT_ZEROS_ONES: RegValue = 0xaa; break;
case HDLC_TXIDLE_ZEROS: RegValue = 0x00; break;
case HDLC_TXIDLE_ONES: RegValue = 0xff; break;
case HDLC_TXIDLE_ALT_MARK_SPACE: RegValue = 0xaa; break;
case HDLC_TXIDLE_SPACE: RegValue = 0x00; break;
case HDLC_TXIDLE_MARK: RegValue = 0xff; break;
}
write_reg(info, IDL, RegValue);
}
static void get_signals(SLMP_INFO *info)
{
u16 status = read_reg(info, SR3);
u16 gpstatus = read_status_reg(info);
u16 testbit;
info->serial_signals &= SerialSignal_RTS | SerialSignal_DTR;
if (!(status & BIT3))
info->serial_signals |= SerialSignal_CTS;
if ( !(status & BIT2))
info->serial_signals |= SerialSignal_DCD;
testbit = BIT1 << (info->port_num * 2);
if (!(gpstatus & testbit))
info->serial_signals |= SerialSignal_RI;
testbit = BIT0 << (info->port_num * 2);
if (!(gpstatus & testbit))
info->serial_signals |= SerialSignal_DSR;
}
static void set_signals(SLMP_INFO *info)
{
unsigned char RegValue;
u16 EnableBit;
RegValue = read_reg(info, CTL);
if (info->serial_signals & SerialSignal_RTS)
RegValue &= ~BIT0;
else
RegValue |= BIT0;
write_reg(info, CTL, RegValue);
EnableBit = BIT1 << (info->port_num*2);
if (info->serial_signals & SerialSignal_DTR)
info->port_array[0]->ctrlreg_value &= ~EnableBit;
else
info->port_array[0]->ctrlreg_value |= EnableBit;
write_control_reg(info);
}
static void rx_reset_buffers(SLMP_INFO *info)
{
rx_free_frame_buffers(info, 0, info->rx_buf_count - 1);
}
static void rx_free_frame_buffers(SLMP_INFO *info, unsigned int first, unsigned int last)
{
bool done = false;
while(!done) {
info->rx_buf_list[first].status = 0xff;
if (first == last) {
done = true;
write_reg16(info, RXDMA + EDA, info->rx_buf_list_ex[first].phys_entry);
}
first++;
if (first == info->rx_buf_count)
first = 0;
}
info->current_rx_buf = first;
}
static bool rx_get_frame(SLMP_INFO *info)
{
unsigned int StartIndex, EndIndex;
unsigned short status;
unsigned int framesize = 0;
bool ReturnCode = false;
unsigned long flags;
struct tty_struct *tty = info->port.tty;
unsigned char addr_field = 0xff;
SCADESC *desc;
SCADESC_EX *desc_ex;
CheckAgain:
framesize = 0;
addr_field = 0xff;
StartIndex = EndIndex = info->current_rx_buf;
for ( ;; ) {
desc = &info->rx_buf_list[EndIndex];
desc_ex = &info->rx_buf_list_ex[EndIndex];
if (desc->status == 0xff)
goto Cleanup;
if (framesize == 0 && info->params.addr_filter != 0xff)
addr_field = desc_ex->virt_addr[0];
framesize += desc->length;
if (desc->status)
break;
EndIndex++;
if (EndIndex == info->rx_buf_count)
EndIndex = 0;
if (EndIndex == info->current_rx_buf) {
if ( info->rx_enabled ){
spin_lock_irqsave(&info->lock,flags);
rx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
goto Cleanup;
}
}
status = desc->status;
if (info->params.crc_type == HDLC_CRC_NONE)
status &= ~BIT2;
if (framesize == 0 ||
(addr_field != 0xff && addr_field != info->params.addr_filter)) {
rx_free_frame_buffers(info, StartIndex, EndIndex);
goto CheckAgain;
}
if (framesize < 2)
status |= BIT6;
if (status & (BIT6+BIT5+BIT3+BIT2)) {
if (status & BIT6)
info->icount.rxshort++;
else if (status & BIT5)
info->icount.rxabort++;
else if (status & BIT3)
info->icount.rxover++;
else
info->icount.rxcrc++;
framesize = 0;
#if SYNCLINK_GENERIC_HDLC
{
info->netdev->stats.rx_errors++;
info->netdev->stats.rx_frame_errors++;
}
#endif
}
if ( debug_level >= DEBUG_LEVEL_BH )
printk("%s(%d):%s rx_get_frame() status=%04X size=%d\n",
__FILE__,__LINE__,info->device_name,status,framesize);
if ( debug_level >= DEBUG_LEVEL_DATA )
trace_block(info,info->rx_buf_list_ex[StartIndex].virt_addr,
min_t(unsigned int, framesize, SCABUFSIZE), 0);
if (framesize) {
if (framesize > info->max_frame_size)
info->icount.rxlong++;
else {
int copy_count = framesize;
int index = StartIndex;
unsigned char *ptmp = info->tmp_rx_buf;
info->tmp_rx_buf_count = framesize;
info->icount.rxok++;
while(copy_count) {
int partial_count = min(copy_count,SCABUFSIZE);
memcpy( ptmp,
info->rx_buf_list_ex[index].virt_addr,
partial_count );
ptmp += partial_count;
copy_count -= partial_count;
if ( ++index == info->rx_buf_count )
index = 0;
}
#if SYNCLINK_GENERIC_HDLC
if (info->netcount)
hdlcdev_rx(info,info->tmp_rx_buf,framesize);
else
#endif
ldisc_receive_buf(tty,info->tmp_rx_buf,
info->flag_buf, framesize);
}
}
rx_free_frame_buffers( info, StartIndex, EndIndex );
ReturnCode = true;
Cleanup:
if ( info->rx_enabled && info->rx_overflow ) {
if (info->rx_buf_list[EndIndex].status == 0xff) {
spin_lock_irqsave(&info->lock,flags);
rx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
}
}
return ReturnCode;
}
static void tx_load_dma_buffer(SLMP_INFO *info, const char *buf, unsigned int count)
{
unsigned short copy_count;
unsigned int i = 0;
SCADESC *desc;
SCADESC_EX *desc_ex;
if ( debug_level >= DEBUG_LEVEL_DATA )
trace_block(info, buf, min_t(unsigned int, count, SCABUFSIZE), 1);
for(i=0;;)
{
copy_count = min_t(unsigned int, count, SCABUFSIZE);
desc = &info->tx_buf_list[i];
desc_ex = &info->tx_buf_list_ex[i];
load_pci_memory(info, desc_ex->virt_addr,buf,copy_count);
desc->length = copy_count;
desc->status = 0;
buf += copy_count;
count -= copy_count;
if (!count)
break;
i++;
if (i >= info->tx_buf_count)
i = 0;
}
info->tx_buf_list[i].status = 0x81;
info->last_tx_buf = ++i;
}
static bool register_test(SLMP_INFO *info)
{
static unsigned char testval[] = {0x00, 0xff, 0xaa, 0x55, 0x69, 0x96};
static unsigned int count = ARRAY_SIZE(testval);
unsigned int i;
bool rc = true;
unsigned long flags;
spin_lock_irqsave(&info->lock,flags);
reset_port(info);
info->init_error = DiagStatus_AddressFailure;
for (i = 0 ; i < count ; i++) {
write_reg(info, TMC, testval[i]);
write_reg(info, IDL, testval[(i+1)%count]);
write_reg(info, SA0, testval[(i+2)%count]);
write_reg(info, SA1, testval[(i+3)%count]);
if ( (read_reg(info, TMC) != testval[i]) ||
(read_reg(info, IDL) != testval[(i+1)%count]) ||
(read_reg(info, SA0) != testval[(i+2)%count]) ||
(read_reg(info, SA1) != testval[(i+3)%count]) )
{
rc = false;
break;
}
}
reset_port(info);
spin_unlock_irqrestore(&info->lock,flags);
return rc;
}
static bool irq_test(SLMP_INFO *info)
{
unsigned long timeout;
unsigned long flags;
unsigned char timer = (info->port_num & 1) ? TIMER2 : TIMER0;
spin_lock_irqsave(&info->lock,flags);
reset_port(info);
info->init_error = DiagStatus_IrqFailure;
info->irq_occurred = false;
write_reg(info, IER2, (unsigned char)((info->port_num & 1) ? BIT6 : BIT4));
write_reg(info, (unsigned char)(timer + TEPR), 0);
write_reg16(info, (unsigned char)(timer + TCONR), 1);
write_reg(info, (unsigned char)(timer + TMCS), 0x50);
spin_unlock_irqrestore(&info->lock,flags);
timeout=100;
while( timeout-- && !info->irq_occurred ) {
msleep_interruptible(10);
}
spin_lock_irqsave(&info->lock,flags);
reset_port(info);
spin_unlock_irqrestore(&info->lock,flags);
return info->irq_occurred;
}
static bool sca_init(SLMP_INFO *info)
{
write_reg(info, PABR0, 0);
write_reg(info, PABR1, 0);
write_reg(info, WCRL, 0);
write_reg(info, WCRM, 0);
write_reg(info, WCRH, 0);
write_reg(info, DPCR, dma_priority);
write_reg(info, DMER, 0x80);
write_reg(info, IER0, 0xff);
write_reg(info, IER1, 0xff);
write_reg(info, IER2, 0xf0);
write_reg(info, ITCR, 0);
return true;
}
static bool init_adapter(SLMP_INFO *info)
{
int i;
volatile u32 *MiscCtrl = (u32 *)(info->lcr_base + 0x50);
u32 readval;
info->misc_ctrl_value |= BIT30;
*MiscCtrl = info->misc_ctrl_value;
for(i=0;i<10;i++)
readval = *MiscCtrl;
info->misc_ctrl_value &= ~BIT30;
*MiscCtrl = info->misc_ctrl_value;
info->ctrlreg_value = 0xaa;
write_control_reg(info);
{
volatile u32 *LCR1BRDR = (u32 *)(info->lcr_base + 0x2c);
lcr1_brdr_value &= ~(BIT5 + BIT4 + BIT3);
switch(read_ahead_count)
{
case 16:
lcr1_brdr_value |= BIT5 + BIT4 + BIT3;
break;
case 8:
lcr1_brdr_value |= BIT5 + BIT4;
break;
case 4:
lcr1_brdr_value |= BIT5 + BIT3;
break;
case 0:
lcr1_brdr_value |= BIT5;
break;
}
*LCR1BRDR = lcr1_brdr_value;
*MiscCtrl = misc_ctrl_value;
}
sca_init(info->port_array[0]);
sca_init(info->port_array[2]);
return true;
}
static bool loopback_test(SLMP_INFO *info)
{
#define TESTFRAMESIZE 20
unsigned long timeout;
u16 count = TESTFRAMESIZE;
unsigned char buf[TESTFRAMESIZE];
bool rc = false;
unsigned long flags;
struct tty_struct *oldtty = info->port.tty;
u32 speed = info->params.clock_speed;
info->params.clock_speed = 3686400;
info->port.tty = NULL;
info->init_error = DiagStatus_DmaFailure;
for (count = 0; count < TESTFRAMESIZE;++count)
buf[count] = (unsigned char)count;
memset(info->tmp_rx_buf,0,TESTFRAMESIZE);
spin_lock_irqsave(&info->lock,flags);
hdlc_mode(info);
enable_loopback(info,1);
rx_start(info);
info->tx_count = count;
tx_load_dma_buffer(info,buf,count);
tx_start(info);
spin_unlock_irqrestore(&info->lock,flags);
for ( timeout = 100; timeout; --timeout ) {
msleep_interruptible(10);
if (rx_get_frame(info)) {
rc = true;
break;
}
}
if (rc &&
( info->tmp_rx_buf_count != count ||
memcmp(buf, info->tmp_rx_buf,count))) {
rc = false;
}
spin_lock_irqsave(&info->lock,flags);
reset_adapter(info);
spin_unlock_irqrestore(&info->lock,flags);
info->params.clock_speed = speed;
info->port.tty = oldtty;
return rc;
}
static int adapter_test( SLMP_INFO *info )
{
unsigned long flags;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):Testing device %s\n",
__FILE__,__LINE__,info->device_name );
spin_lock_irqsave(&info->lock,flags);
init_adapter(info);
spin_unlock_irqrestore(&info->lock,flags);
info->port_array[0]->port_count = 0;
if ( register_test(info->port_array[0]) &&
register_test(info->port_array[1])) {
info->port_array[0]->port_count = 2;
if ( register_test(info->port_array[2]) &&
register_test(info->port_array[3]) )
info->port_array[0]->port_count += 2;
}
else {
printk( "%s(%d):Register test failure for device %s Addr=%08lX\n",
__FILE__,__LINE__,info->device_name, (unsigned long)(info->phys_sca_base));
return -ENODEV;
}
if ( !irq_test(info->port_array[0]) ||
!irq_test(info->port_array[1]) ||
(info->port_count == 4 && !irq_test(info->port_array[2])) ||
(info->port_count == 4 && !irq_test(info->port_array[3]))) {
printk( "%s(%d):Interrupt test failure for device %s IRQ=%d\n",
__FILE__,__LINE__,info->device_name, (unsigned short)(info->irq_level) );
return -ENODEV;
}
if (!loopback_test(info->port_array[0]) ||
!loopback_test(info->port_array[1]) ||
(info->port_count == 4 && !loopback_test(info->port_array[2])) ||
(info->port_count == 4 && !loopback_test(info->port_array[3]))) {
printk( "%s(%d):DMA test failure for device %s\n",
__FILE__,__LINE__,info->device_name);
return -ENODEV;
}
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):device %s passed diagnostics\n",
__FILE__,__LINE__,info->device_name );
info->port_array[0]->init_error = 0;
info->port_array[1]->init_error = 0;
if ( info->port_count > 2 ) {
info->port_array[2]->init_error = 0;
info->port_array[3]->init_error = 0;
}
return 0;
}
static bool memory_test(SLMP_INFO *info)
{
static unsigned long testval[] = { 0x0, 0x55555555, 0xaaaaaaaa,
0x66666666, 0x99999999, 0xffffffff, 0x12345678 };
unsigned long count = ARRAY_SIZE(testval);
unsigned long i;
unsigned long limit = SCA_MEM_SIZE/sizeof(unsigned long);
unsigned long * addr = (unsigned long *)info->memory_base;
for ( i = 0 ; i < count ; i++ ) {
*addr = testval[i];
if ( *addr != testval[i] )
return false;
}
for ( i = 0 ; i < limit ; i++ ) {
*addr = i * 4;
addr++;
}
addr = (unsigned long *)info->memory_base;
for ( i = 0 ; i < limit ; i++ ) {
if ( *addr != i * 4 )
return false;
addr++;
}
memset( info->memory_base, 0, SCA_MEM_SIZE );
return true;
}
static void load_pci_memory(SLMP_INFO *info, char* dest, const char* src, unsigned short count)
{
unsigned short interval = count / sca_pci_load_interval;
unsigned short i;
for ( i = 0 ; i < interval ; i++ )
{
memcpy(dest, src, sca_pci_load_interval);
read_status_reg(info);
dest += sca_pci_load_interval;
src += sca_pci_load_interval;
}
memcpy(dest, src, count % sca_pci_load_interval);
}
static void trace_block(SLMP_INFO *info,const char* data, int count, int xmit)
{
int i;
int linecount;
if (xmit)
printk("%s tx data:\n",info->device_name);
else
printk("%s rx data:\n",info->device_name);
while(count) {
if (count > 16)
linecount = 16;
else
linecount = count;
for(i=0;i<linecount;i++)
printk("%02X ",(unsigned char)data[i]);
for(;i<17;i++)
printk(" ");
for(i=0;i<linecount;i++) {
if (data[i]>=040 && data[i]<=0176)
printk("%c",data[i]);
else
printk(".");
}
printk("\n");
data += linecount;
count -= linecount;
}
}
static void tx_timeout(unsigned long context)
{
SLMP_INFO *info = (SLMP_INFO*)context;
unsigned long flags;
if ( debug_level >= DEBUG_LEVEL_INFO )
printk( "%s(%d):%s tx_timeout()\n",
__FILE__,__LINE__,info->device_name);
if(info->tx_active && info->params.mode == MGSL_MODE_HDLC) {
info->icount.txtimeout++;
}
spin_lock_irqsave(&info->lock,flags);
info->tx_active = false;
info->tx_count = info->tx_put = info->tx_get = 0;
spin_unlock_irqrestore(&info->lock,flags);
#if SYNCLINK_GENERIC_HDLC
if (info->netcount)
hdlcdev_tx_done(info);
else
#endif
bh_transmit(info);
}
static void status_timeout(unsigned long context)
{
u16 status = 0;
SLMP_INFO *info = (SLMP_INFO*)context;
unsigned long flags;
unsigned char delta;
spin_lock_irqsave(&info->lock,flags);
get_signals(info);
spin_unlock_irqrestore(&info->lock,flags);
delta = info->old_signals ^ info->serial_signals;
info->old_signals = info->serial_signals;
if (delta & SerialSignal_DSR)
status |= MISCSTATUS_DSR_LATCHED|(info->serial_signals&SerialSignal_DSR);
if (delta & SerialSignal_RI)
status |= MISCSTATUS_RI_LATCHED|(info->serial_signals&SerialSignal_RI);
if (delta & SerialSignal_DCD)
status |= MISCSTATUS_DCD_LATCHED|(info->serial_signals&SerialSignal_DCD);
if (delta & SerialSignal_CTS)
status |= MISCSTATUS_CTS_LATCHED|(info->serial_signals&SerialSignal_CTS);
if (status)
isr_io_pin(info,status);
mod_timer(&info->status_timer, jiffies + msecs_to_jiffies(10));
}
static unsigned char read_reg(SLMP_INFO * info, unsigned char Addr)
{
CALC_REGADDR();
return *RegAddr;
}
static void write_reg(SLMP_INFO * info, unsigned char Addr, unsigned char Value)
{
CALC_REGADDR();
*RegAddr = Value;
}
static u16 read_reg16(SLMP_INFO * info, unsigned char Addr)
{
CALC_REGADDR();
return *((u16 *)RegAddr);
}
static void write_reg16(SLMP_INFO * info, unsigned char Addr, u16 Value)
{
CALC_REGADDR();
*((u16 *)RegAddr) = Value;
}
static unsigned char read_status_reg(SLMP_INFO * info)
{
unsigned char *RegAddr = (unsigned char *)info->statctrl_base;
return *RegAddr;
}
static void write_control_reg(SLMP_INFO * info)
{
unsigned char *RegAddr = (unsigned char *)info->statctrl_base;
*RegAddr = info->port_array[0]->ctrlreg_value;
}
static int synclinkmp_init_one (struct pci_dev *dev,
const struct pci_device_id *ent)
{
if (pci_enable_device(dev)) {
printk("error enabling pci device %p\n", dev);
return -EIO;
}
device_init( ++synclinkmp_adapter_count, dev );
return 0;
}
static void synclinkmp_remove_one (struct pci_dev *dev)
{
}
