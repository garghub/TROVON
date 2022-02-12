static inline struct logger_log *file_get_log(struct file *file)
{
if (file->f_mode & FMODE_READ) {
struct logger_reader *reader = file->private_data;
return reader->log;
} else
return file->private_data;
}
static __u32 get_entry_len(struct logger_log *log, size_t off)
{
__u16 val;
switch (log->size - off) {
case 1:
memcpy(&val, log->buffer + off, 1);
memcpy(((char *) &val) + 1, log->buffer, 1);
break;
default:
memcpy(&val, log->buffer + off, 2);
}
return sizeof(struct logger_entry) + val;
}
static ssize_t do_read_log_to_user(struct logger_log *log,
struct logger_reader *reader,
char __user *buf,
size_t count)
{
size_t len;
len = min(count, log->size - reader->r_off);
if (copy_to_user(buf, log->buffer + reader->r_off, len))
return -EFAULT;
if (count != len)
if (copy_to_user(buf + len, log->buffer, count - len))
return -EFAULT;
reader->r_off = logger_offset(reader->r_off + count);
return count;
}
static ssize_t logger_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
struct logger_reader *reader = file->private_data;
struct logger_log *log = reader->log;
ssize_t ret;
DEFINE_WAIT(wait);
start:
while (1) {
prepare_to_wait(&log->wq, &wait, TASK_INTERRUPTIBLE);
mutex_lock(&log->mutex);
ret = (log->w_off == reader->r_off);
mutex_unlock(&log->mutex);
if (!ret)
break;
if (file->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -EINTR;
break;
}
schedule();
}
finish_wait(&log->wq, &wait);
if (ret)
return ret;
mutex_lock(&log->mutex);
if (unlikely(log->w_off == reader->r_off)) {
mutex_unlock(&log->mutex);
goto start;
}
ret = get_entry_len(log, reader->r_off);
if (count < ret) {
ret = -EINVAL;
goto out;
}
ret = do_read_log_to_user(log, reader, buf, ret);
out:
mutex_unlock(&log->mutex);
return ret;
}
static size_t get_next_entry(struct logger_log *log, size_t off, size_t len)
{
size_t count = 0;
do {
size_t nr = get_entry_len(log, off);
off = logger_offset(off + nr);
count += nr;
} while (count < len);
return off;
}
static inline int clock_interval(size_t a, size_t b, size_t c)
{
if (b < a) {
if (a < c || b >= c)
return 1;
} else {
if (a < c && b >= c)
return 1;
}
return 0;
}
static void fix_up_readers(struct logger_log *log, size_t len)
{
size_t old = log->w_off;
size_t new = logger_offset(old + len);
struct logger_reader *reader;
if (clock_interval(old, new, log->head))
log->head = get_next_entry(log, log->head, len);
list_for_each_entry(reader, &log->readers, list)
if (clock_interval(old, new, reader->r_off))
reader->r_off = get_next_entry(log, reader->r_off, len);
}
static void do_write_log(struct logger_log *log, const void *buf, size_t count)
{
size_t len;
len = min(count, log->size - log->w_off);
memcpy(log->buffer + log->w_off, buf, len);
if (count != len)
memcpy(log->buffer, buf + len, count - len);
log->w_off = logger_offset(log->w_off + count);
}
static ssize_t do_write_log_from_user(struct logger_log *log,
const void __user *buf, size_t count)
{
size_t len;
len = min(count, log->size - log->w_off);
if (len && copy_from_user(log->buffer + log->w_off, buf, len))
return -EFAULT;
if (count != len)
if (copy_from_user(log->buffer, buf + len, count - len))
return -EFAULT;
log->w_off = logger_offset(log->w_off + count);
return count;
}
ssize_t logger_aio_write(struct kiocb *iocb, const struct iovec *iov,
unsigned long nr_segs, loff_t ppos)
{
struct logger_log *log = file_get_log(iocb->ki_filp);
size_t orig = log->w_off;
struct logger_entry header;
struct timespec now;
ssize_t ret = 0;
now = current_kernel_time();
header.pid = current->tgid;
header.tid = current->pid;
header.sec = now.tv_sec;
header.nsec = now.tv_nsec;
header.len = min_t(size_t, iocb->ki_left, LOGGER_ENTRY_MAX_PAYLOAD);
if (unlikely(!header.len))
return 0;
mutex_lock(&log->mutex);
fix_up_readers(log, sizeof(struct logger_entry) + header.len);
do_write_log(log, &header, sizeof(struct logger_entry));
while (nr_segs-- > 0) {
size_t len;
ssize_t nr;
len = min_t(size_t, iov->iov_len, header.len - ret);
nr = do_write_log_from_user(log, iov->iov_base, len);
if (unlikely(nr < 0)) {
log->w_off = orig;
mutex_unlock(&log->mutex);
return nr;
}
iov++;
ret += nr;
}
mutex_unlock(&log->mutex);
wake_up_interruptible(&log->wq);
return ret;
}
static int logger_open(struct inode *inode, struct file *file)
{
struct logger_log *log;
int ret;
ret = nonseekable_open(inode, file);
if (ret)
return ret;
log = get_log_from_minor(MINOR(inode->i_rdev));
if (!log)
return -ENODEV;
if (file->f_mode & FMODE_READ) {
struct logger_reader *reader;
reader = kmalloc(sizeof(struct logger_reader), GFP_KERNEL);
if (!reader)
return -ENOMEM;
reader->log = log;
INIT_LIST_HEAD(&reader->list);
mutex_lock(&log->mutex);
reader->r_off = log->head;
list_add_tail(&reader->list, &log->readers);
mutex_unlock(&log->mutex);
file->private_data = reader;
} else
file->private_data = log;
return 0;
}
static int logger_release(struct inode *ignored, struct file *file)
{
if (file->f_mode & FMODE_READ) {
struct logger_reader *reader = file->private_data;
list_del(&reader->list);
kfree(reader);
}
return 0;
}
static unsigned int logger_poll(struct file *file, poll_table *wait)
{
struct logger_reader *reader;
struct logger_log *log;
unsigned int ret = POLLOUT | POLLWRNORM;
if (!(file->f_mode & FMODE_READ))
return ret;
reader = file->private_data;
log = reader->log;
poll_wait(file, &log->wq, wait);
mutex_lock(&log->mutex);
if (log->w_off != reader->r_off)
ret |= POLLIN | POLLRDNORM;
mutex_unlock(&log->mutex);
return ret;
}
static long logger_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct logger_log *log = file_get_log(file);
struct logger_reader *reader;
long ret = -ENOTTY;
mutex_lock(&log->mutex);
switch (cmd) {
case LOGGER_GET_LOG_BUF_SIZE:
ret = log->size;
break;
case LOGGER_GET_LOG_LEN:
if (!(file->f_mode & FMODE_READ)) {
ret = -EBADF;
break;
}
reader = file->private_data;
if (log->w_off >= reader->r_off)
ret = log->w_off - reader->r_off;
else
ret = (log->size - reader->r_off) + log->w_off;
break;
case LOGGER_GET_NEXT_ENTRY_LEN:
if (!(file->f_mode & FMODE_READ)) {
ret = -EBADF;
break;
}
reader = file->private_data;
if (log->w_off != reader->r_off)
ret = get_entry_len(log, reader->r_off);
else
ret = 0;
break;
case LOGGER_FLUSH_LOG:
if (!(file->f_mode & FMODE_WRITE)) {
ret = -EBADF;
break;
}
list_for_each_entry(reader, &log->readers, list)
reader->r_off = log->w_off;
log->head = log->w_off;
ret = 0;
break;
}
mutex_unlock(&log->mutex);
return ret;
}
static struct logger_log *get_log_from_minor(int minor)
{
if (log_main.misc.minor == minor)
return &log_main;
if (log_events.misc.minor == minor)
return &log_events;
if (log_radio.misc.minor == minor)
return &log_radio;
if (log_system.misc.minor == minor)
return &log_system;
return NULL;
}
static int __init init_log(struct logger_log *log)
{
int ret;
ret = misc_register(&log->misc);
if (unlikely(ret)) {
printk(KERN_ERR "logger: failed to register misc "
"device for log '%s'!\n", log->misc.name);
return ret;
}
printk(KERN_INFO "logger: created %luK log '%s'\n",
(unsigned long) log->size >> 10, log->misc.name);
return 0;
}
static int __init logger_init(void)
{
int ret;
ret = init_log(&log_main);
if (unlikely(ret))
goto out;
ret = init_log(&log_events);
if (unlikely(ret))
goto out;
ret = init_log(&log_radio);
if (unlikely(ret))
goto out;
ret = init_log(&log_system);
if (unlikely(ret))
goto out;
out:
return ret;
}
