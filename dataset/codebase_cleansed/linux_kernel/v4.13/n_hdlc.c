static void flush_rx_queue(struct tty_struct *tty)
{
struct n_hdlc *n_hdlc = tty2n_hdlc(tty);
struct n_hdlc_buf *buf;
while ((buf = n_hdlc_buf_get(&n_hdlc->rx_buf_list)))
n_hdlc_buf_put(&n_hdlc->rx_free_buf_list, buf);
}
static void flush_tx_queue(struct tty_struct *tty)
{
struct n_hdlc *n_hdlc = tty2n_hdlc(tty);
struct n_hdlc_buf *buf;
while ((buf = n_hdlc_buf_get(&n_hdlc->tx_buf_list)))
n_hdlc_buf_put(&n_hdlc->tx_free_buf_list, buf);
}
static void n_hdlc_release(struct n_hdlc *n_hdlc)
{
struct tty_struct *tty = n_hdlc2tty (n_hdlc);
struct n_hdlc_buf *buf;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_release() called\n",__FILE__,__LINE__);
wake_up_interruptible (&tty->read_wait);
wake_up_interruptible (&tty->write_wait);
if (tty->disc_data == n_hdlc)
tty->disc_data = NULL;
for(;;) {
buf = n_hdlc_buf_get(&n_hdlc->rx_free_buf_list);
if (buf) {
kfree(buf);
} else
break;
}
for(;;) {
buf = n_hdlc_buf_get(&n_hdlc->tx_free_buf_list);
if (buf) {
kfree(buf);
} else
break;
}
for(;;) {
buf = n_hdlc_buf_get(&n_hdlc->rx_buf_list);
if (buf) {
kfree(buf);
} else
break;
}
for(;;) {
buf = n_hdlc_buf_get(&n_hdlc->tx_buf_list);
if (buf) {
kfree(buf);
} else
break;
}
kfree(n_hdlc);
}
static void n_hdlc_tty_close(struct tty_struct *tty)
{
struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_close() called\n",__FILE__,__LINE__);
if (n_hdlc != NULL) {
if (n_hdlc->magic != HDLC_MAGIC) {
printk (KERN_WARNING"n_hdlc: trying to close unopened tty!\n");
return;
}
#if defined(TTY_NO_WRITE_SPLIT)
clear_bit(TTY_NO_WRITE_SPLIT,&tty->flags);
#endif
tty->disc_data = NULL;
if (tty == n_hdlc->backup_tty)
n_hdlc->backup_tty = NULL;
if (tty != n_hdlc->tty)
return;
if (n_hdlc->backup_tty) {
n_hdlc->tty = n_hdlc->backup_tty;
} else {
n_hdlc_release (n_hdlc);
}
}
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_close() success\n",__FILE__,__LINE__);
}
static int n_hdlc_tty_open (struct tty_struct *tty)
{
struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_open() called (device=%s)\n",
__FILE__,__LINE__,
tty->name);
if (n_hdlc) {
printk (KERN_ERR"n_hdlc_tty_open:tty already associated!\n" );
return -EEXIST;
}
n_hdlc = n_hdlc_alloc();
if (!n_hdlc) {
printk (KERN_ERR "n_hdlc_alloc failed\n");
return -ENFILE;
}
tty->disc_data = n_hdlc;
n_hdlc->tty = tty;
tty->receive_room = 65536;
#if defined(TTY_NO_WRITE_SPLIT)
set_bit(TTY_NO_WRITE_SPLIT,&tty->flags);
#endif
tty_driver_flush_buffer(tty);
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_open() success\n",__FILE__,__LINE__);
return 0;
}
static void n_hdlc_send_frames(struct n_hdlc *n_hdlc, struct tty_struct *tty)
{
register int actual;
unsigned long flags;
struct n_hdlc_buf *tbuf;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_send_frames() called\n",__FILE__,__LINE__);
check_again:
spin_lock_irqsave(&n_hdlc->tx_buf_list.spinlock, flags);
if (n_hdlc->tbusy) {
n_hdlc->woke_up = 1;
spin_unlock_irqrestore(&n_hdlc->tx_buf_list.spinlock, flags);
return;
}
n_hdlc->tbusy = 1;
n_hdlc->woke_up = 0;
spin_unlock_irqrestore(&n_hdlc->tx_buf_list.spinlock, flags);
tbuf = n_hdlc_buf_get(&n_hdlc->tx_buf_list);
while (tbuf) {
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)sending frame %p, count=%d\n",
__FILE__,__LINE__,tbuf,tbuf->count);
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
actual = tty->ops->write(tty, tbuf->buf, tbuf->count);
if (actual == -ERESTARTSYS) {
n_hdlc_buf_return(&n_hdlc->tx_buf_list, tbuf);
break;
}
if (actual < 0)
actual = tbuf->count;
if (actual == tbuf->count) {
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)frame %p completed\n",
__FILE__,__LINE__,tbuf);
n_hdlc_buf_put(&n_hdlc->tx_free_buf_list, tbuf);
wake_up_interruptible(&tty->write_wait);
tbuf = n_hdlc_buf_get(&n_hdlc->tx_buf_list);
} else {
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)frame %p pending\n",
__FILE__,__LINE__,tbuf);
n_hdlc_buf_return(&n_hdlc->tx_buf_list, tbuf);
break;
}
}
if (!tbuf)
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
spin_lock_irqsave(&n_hdlc->tx_buf_list.spinlock, flags);
n_hdlc->tbusy = 0;
spin_unlock_irqrestore(&n_hdlc->tx_buf_list.spinlock, flags);
if (n_hdlc->woke_up)
goto check_again;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_send_frames() exit\n",__FILE__,__LINE__);
}
static void n_hdlc_tty_wakeup(struct tty_struct *tty)
{
struct n_hdlc *n_hdlc = tty2n_hdlc(tty);
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_wakeup() called\n",__FILE__,__LINE__);
if (!n_hdlc)
return;
if (tty != n_hdlc->tty) {
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
return;
}
n_hdlc_send_frames (n_hdlc, tty);
}
static void n_hdlc_tty_receive(struct tty_struct *tty, const __u8 *data,
char *flags, int count)
{
register struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
register struct n_hdlc_buf *buf;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_receive() called count=%d\n",
__FILE__,__LINE__, count);
if (!n_hdlc || tty != n_hdlc->tty)
return;
if (n_hdlc->magic != HDLC_MAGIC) {
printk("%s(%d) line not using HDLC discipline\n",
__FILE__,__LINE__);
return;
}
if ( count>maxframe ) {
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d) rx count>maxframesize, data discarded\n",
__FILE__,__LINE__);
return;
}
buf = n_hdlc_buf_get(&n_hdlc->rx_free_buf_list);
if (!buf) {
if (n_hdlc->rx_buf_list.count < MAX_RX_BUF_COUNT)
buf = kmalloc(N_HDLC_BUF_SIZE, GFP_ATOMIC);
}
if (!buf) {
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d) no more rx buffers, data discarded\n",
__FILE__,__LINE__);
return;
}
memcpy(buf->buf,data,count);
buf->count=count;
n_hdlc_buf_put(&n_hdlc->rx_buf_list, buf);
wake_up_interruptible (&tty->read_wait);
if (n_hdlc->tty->fasync != NULL)
kill_fasync (&n_hdlc->tty->fasync, SIGIO, POLL_IN);
}
static ssize_t n_hdlc_tty_read(struct tty_struct *tty, struct file *file,
__u8 __user *buf, size_t nr)
{
struct n_hdlc *n_hdlc = tty2n_hdlc(tty);
int ret = 0;
struct n_hdlc_buf *rbuf;
DECLARE_WAITQUEUE(wait, current);
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_read() called\n",__FILE__,__LINE__);
if (!n_hdlc)
return -EIO;
if (!access_ok(VERIFY_WRITE, buf, nr)) {
printk(KERN_WARNING "%s(%d) n_hdlc_tty_read() can't verify user "
"buffer\n", __FILE__, __LINE__);
return -EFAULT;
}
add_wait_queue(&tty->read_wait, &wait);
for (;;) {
if (test_bit(TTY_OTHER_CLOSED, &tty->flags)) {
ret = -EIO;
break;
}
if (tty_hung_up_p(file))
break;
set_current_state(TASK_INTERRUPTIBLE);
rbuf = n_hdlc_buf_get(&n_hdlc->rx_buf_list);
if (rbuf) {
if (rbuf->count > nr) {
ret = -EOVERFLOW;
} else {
if (copy_to_user(buf, rbuf->buf, rbuf->count))
ret = -EFAULT;
else
ret = rbuf->count;
}
if (n_hdlc->rx_free_buf_list.count >
DEFAULT_RX_BUF_COUNT)
kfree(rbuf);
else
n_hdlc_buf_put(&n_hdlc->rx_free_buf_list, rbuf);
break;
}
if (file->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
break;
}
schedule();
if (signal_pending(current)) {
ret = -EINTR;
break;
}
}
remove_wait_queue(&tty->read_wait, &wait);
__set_current_state(TASK_RUNNING);
return ret;
}
static ssize_t n_hdlc_tty_write(struct tty_struct *tty, struct file *file,
const unsigned char *data, size_t count)
{
struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
int error = 0;
DECLARE_WAITQUEUE(wait, current);
struct n_hdlc_buf *tbuf;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_write() called count=%zd\n",
__FILE__,__LINE__,count);
if (!n_hdlc)
return -EIO;
if (n_hdlc->magic != HDLC_MAGIC)
return -EIO;
if (count > maxframe ) {
if (debuglevel & DEBUG_LEVEL_INFO)
printk (KERN_WARNING
"n_hdlc_tty_write: truncating user packet "
"from %lu to %d\n", (unsigned long) count,
maxframe );
count = maxframe;
}
add_wait_queue(&tty->write_wait, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
tbuf = n_hdlc_buf_get(&n_hdlc->tx_free_buf_list);
if (tbuf)
break;
if (file->f_flags & O_NONBLOCK) {
error = -EAGAIN;
break;
}
schedule();
n_hdlc = tty2n_hdlc (tty);
if (!n_hdlc || n_hdlc->magic != HDLC_MAGIC ||
tty != n_hdlc->tty) {
printk("n_hdlc_tty_write: %p invalid after wait!\n", n_hdlc);
error = -EIO;
break;
}
if (signal_pending(current)) {
error = -EINTR;
break;
}
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(&tty->write_wait, &wait);
if (!error) {
memcpy(tbuf->buf, data, count);
tbuf->count = error = count;
n_hdlc_buf_put(&n_hdlc->tx_buf_list,tbuf);
n_hdlc_send_frames(n_hdlc,tty);
}
return error;
}
static int n_hdlc_tty_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
int error = 0;
int count;
unsigned long flags;
struct n_hdlc_buf *buf = NULL;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_ioctl() called %d\n",
__FILE__,__LINE__,cmd);
if (!n_hdlc || n_hdlc->magic != HDLC_MAGIC)
return -EBADF;
switch (cmd) {
case FIONREAD:
spin_lock_irqsave(&n_hdlc->rx_buf_list.spinlock,flags);
buf = list_first_entry_or_null(&n_hdlc->rx_buf_list.list,
struct n_hdlc_buf, list_item);
if (buf)
count = buf->count;
else
count = 0;
spin_unlock_irqrestore(&n_hdlc->rx_buf_list.spinlock,flags);
error = put_user(count, (int __user *)arg);
break;
case TIOCOUTQ:
count = tty_chars_in_buffer(tty);
spin_lock_irqsave(&n_hdlc->tx_buf_list.spinlock,flags);
buf = list_first_entry_or_null(&n_hdlc->tx_buf_list.list,
struct n_hdlc_buf, list_item);
if (buf)
count += buf->count;
spin_unlock_irqrestore(&n_hdlc->tx_buf_list.spinlock,flags);
error = put_user(count, (int __user *)arg);
break;
case TCFLSH:
switch (arg) {
case TCIOFLUSH:
case TCOFLUSH:
flush_tx_queue(tty);
}
default:
error = n_tty_ioctl_helper(tty, file, cmd, arg);
break;
}
return error;
}
static unsigned int n_hdlc_tty_poll(struct tty_struct *tty, struct file *filp,
poll_table *wait)
{
struct n_hdlc *n_hdlc = tty2n_hdlc (tty);
unsigned int mask = 0;
if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_tty_poll() called\n",__FILE__,__LINE__);
if (n_hdlc && n_hdlc->magic == HDLC_MAGIC && tty == n_hdlc->tty) {
poll_wait(filp, &tty->read_wait, wait);
poll_wait(filp, &tty->write_wait, wait);
if (!list_empty(&n_hdlc->rx_buf_list.list))
mask |= POLLIN | POLLRDNORM;
if (test_bit(TTY_OTHER_CLOSED, &tty->flags))
mask |= POLLHUP;
if (tty_hung_up_p(filp))
mask |= POLLHUP;
if (!tty_is_writelocked(tty) &&
!list_empty(&n_hdlc->tx_free_buf_list.list))
mask |= POLLOUT | POLLWRNORM;
}
return mask;
}
static struct n_hdlc *n_hdlc_alloc(void)
{
struct n_hdlc_buf *buf;
int i;
struct n_hdlc *n_hdlc = kzalloc(sizeof(*n_hdlc), GFP_KERNEL);
if (!n_hdlc)
return NULL;
spin_lock_init(&n_hdlc->rx_free_buf_list.spinlock);
spin_lock_init(&n_hdlc->tx_free_buf_list.spinlock);
spin_lock_init(&n_hdlc->rx_buf_list.spinlock);
spin_lock_init(&n_hdlc->tx_buf_list.spinlock);
INIT_LIST_HEAD(&n_hdlc->rx_free_buf_list.list);
INIT_LIST_HEAD(&n_hdlc->tx_free_buf_list.list);
INIT_LIST_HEAD(&n_hdlc->rx_buf_list.list);
INIT_LIST_HEAD(&n_hdlc->tx_buf_list.list);
for(i=0;i<DEFAULT_RX_BUF_COUNT;i++) {
buf = kmalloc(N_HDLC_BUF_SIZE, GFP_KERNEL);
if (buf)
n_hdlc_buf_put(&n_hdlc->rx_free_buf_list,buf);
else if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_alloc(), kalloc() failed for rx buffer %d\n",__FILE__,__LINE__, i);
}
for(i=0;i<DEFAULT_TX_BUF_COUNT;i++) {
buf = kmalloc(N_HDLC_BUF_SIZE, GFP_KERNEL);
if (buf)
n_hdlc_buf_put(&n_hdlc->tx_free_buf_list,buf);
else if (debuglevel >= DEBUG_LEVEL_INFO)
printk("%s(%d)n_hdlc_alloc(), kalloc() failed for tx buffer %d\n",__FILE__,__LINE__, i);
}
n_hdlc->magic = HDLC_MAGIC;
n_hdlc->flags = 0;
return n_hdlc;
}
static void n_hdlc_buf_return(struct n_hdlc_buf_list *buf_list,
struct n_hdlc_buf *buf)
{
unsigned long flags;
spin_lock_irqsave(&buf_list->spinlock, flags);
list_add(&buf->list_item, &buf_list->list);
buf_list->count++;
spin_unlock_irqrestore(&buf_list->spinlock, flags);
}
static void n_hdlc_buf_put(struct n_hdlc_buf_list *buf_list,
struct n_hdlc_buf *buf)
{
unsigned long flags;
spin_lock_irqsave(&buf_list->spinlock, flags);
list_add_tail(&buf->list_item, &buf_list->list);
buf_list->count++;
spin_unlock_irqrestore(&buf_list->spinlock, flags);
}
static struct n_hdlc_buf *n_hdlc_buf_get(struct n_hdlc_buf_list *buf_list)
{
unsigned long flags;
struct n_hdlc_buf *buf;
spin_lock_irqsave(&buf_list->spinlock, flags);
buf = list_first_entry_or_null(&buf_list->list,
struct n_hdlc_buf, list_item);
if (buf) {
list_del(&buf->list_item);
buf_list->count--;
}
spin_unlock_irqrestore(&buf_list->spinlock, flags);
return buf;
}
static int __init n_hdlc_init(void)
{
int status;
if (maxframe < 4096)
maxframe = 4096;
else if (maxframe > 65535)
maxframe = 65535;
printk(hdlc_banner, maxframe);
status = tty_register_ldisc(N_HDLC, &n_hdlc_ldisc);
if (!status)
printk(hdlc_register_ok);
else
printk(hdlc_register_fail, status);
return status;
}
static void __exit n_hdlc_exit(void)
{
int status = tty_unregister_ldisc(N_HDLC);
if (status)
printk(hdlc_unregister_fail, status);
else
printk(hdlc_unregister_ok);
}
