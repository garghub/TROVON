static size_t logger_offset(struct logger_log *log, size_t n)
{
return n & (log->size - 1);
}
static inline struct logger_log *file_get_log(struct file *file)
{
if (file->f_mode & FMODE_READ) {
struct logger_reader *reader = file->private_data;
return reader->log;
} else
return file->private_data;
}
static struct logger_entry *get_entry_header(struct logger_log *log,
size_t off, struct logger_entry *scratch)
{
size_t len = min(sizeof(struct logger_entry), log->size - off);
if (len != sizeof(struct logger_entry)) {
memcpy(((void *) scratch), log->buffer + off, len);
memcpy(((void *) scratch) + len, log->buffer,
sizeof(struct logger_entry) - len);
return scratch;
}
return (struct logger_entry *) (log->buffer + off);
}
static __u32 get_entry_msg_len(struct logger_log *log, size_t off)
{
struct logger_entry scratch;
struct logger_entry *entry;
entry = get_entry_header(log, off, &scratch);
return entry->len;
}
static size_t get_user_hdr_len(int ver)
{
if (ver < 2)
return sizeof(struct user_logger_entry_compat);
else
return sizeof(struct logger_entry);
}
static ssize_t copy_header_to_user(int ver, struct logger_entry *entry,
char __user *buf)
{
void *hdr;
size_t hdr_len;
struct user_logger_entry_compat v1;
if (ver < 2) {
v1.len = entry->len;
v1.__pad = 0;
v1.pid = entry->pid;
v1.tid = entry->tid;
v1.sec = entry->sec;
v1.nsec = entry->nsec;
hdr = &v1;
hdr_len = sizeof(struct user_logger_entry_compat);
} else {
hdr = entry;
hdr_len = sizeof(struct logger_entry);
}
return copy_to_user(buf, hdr, hdr_len);
}
static ssize_t do_read_log_to_user(struct logger_log *log,
struct logger_reader *reader,
char __user *buf,
size_t count)
{
struct logger_entry scratch;
struct logger_entry *entry;
size_t len;
size_t msg_start;
entry = get_entry_header(log, reader->r_off, &scratch);
if (copy_header_to_user(reader->r_ver, entry, buf))
return -EFAULT;
count -= get_user_hdr_len(reader->r_ver);
buf += get_user_hdr_len(reader->r_ver);
msg_start = logger_offset(log,
reader->r_off + sizeof(struct logger_entry));
len = min(count, log->size - msg_start);
if (copy_to_user(buf, log->buffer + msg_start, len))
return -EFAULT;
if (count != len)
if (copy_to_user(buf + len, log->buffer, count - len))
return -EFAULT;
reader->r_off = logger_offset(log, reader->r_off +
sizeof(struct logger_entry) + count);
return count + get_user_hdr_len(reader->r_ver);
}
static size_t get_next_entry_by_uid(struct logger_log *log,
size_t off, kuid_t euid)
{
while (off != log->w_off) {
struct logger_entry *entry;
struct logger_entry scratch;
size_t next_len;
entry = get_entry_header(log, off, &scratch);
if (uid_eq(entry->euid, euid))
return off;
next_len = sizeof(struct logger_entry) + entry->len;
off = logger_offset(log, off + next_len);
}
return off;
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
mutex_lock(&log->mutex);
prepare_to_wait(&log->wq, &wait, TASK_INTERRUPTIBLE);
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
if (!reader->r_all)
reader->r_off = get_next_entry_by_uid(log,
reader->r_off, current_euid());
if (unlikely(log->w_off == reader->r_off)) {
mutex_unlock(&log->mutex);
goto start;
}
ret = get_user_hdr_len(reader->r_ver) +
get_entry_msg_len(log, reader->r_off);
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
size_t nr = sizeof(struct logger_entry) +
get_entry_msg_len(log, off);
off = logger_offset(log, off + nr);
count += nr;
} while (count < len);
return off;
}
static inline int is_between(size_t a, size_t b, size_t c)
{
if (a < b) {
if (a < c && c <= b)
return 1;
} else {
if (c <= b || a < c)
return 1;
}
return 0;
}
static void fix_up_readers(struct logger_log *log, size_t len)
{
size_t old = log->w_off;
size_t new = logger_offset(log, old + len);
struct logger_reader *reader;
if (is_between(old, new, log->head))
log->head = get_next_entry(log, log->head, len);
list_for_each_entry(reader, &log->readers, list)
if (is_between(old, new, reader->r_off))
reader->r_off = get_next_entry(log, reader->r_off, len);
}
static void do_write_log(struct logger_log *log, const void *buf, size_t count)
{
size_t len;
len = min(count, log->size - log->w_off);
memcpy(log->buffer + log->w_off, buf, len);
if (count != len)
memcpy(log->buffer, buf + len, count - len);
log->w_off = logger_offset(log, log->w_off + count);
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
log->w_off = logger_offset(log, log->w_off + count);
return count;
}
static ssize_t logger_aio_write(struct kiocb *iocb, const struct iovec *iov,
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
header.euid = current_euid();
header.len = min_t(size_t, iocb->ki_left, LOGGER_ENTRY_MAX_PAYLOAD);
header.hdr_size = sizeof(struct logger_entry);
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
static struct logger_log *get_log_from_minor(int minor)
{
struct logger_log *log;
list_for_each_entry(log, &log_list, logs)
if (log->misc.minor == minor)
return log;
return NULL;
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
reader->r_ver = 1;
reader->r_all = in_egroup_p(inode->i_gid) ||
capable(CAP_SYSLOG);
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
struct logger_log *log = reader->log;
mutex_lock(&log->mutex);
list_del(&reader->list);
mutex_unlock(&log->mutex);
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
if (!reader->r_all)
reader->r_off = get_next_entry_by_uid(log,
reader->r_off, current_euid());
if (log->w_off != reader->r_off)
ret |= POLLIN | POLLRDNORM;
mutex_unlock(&log->mutex);
return ret;
}
static long logger_set_version(struct logger_reader *reader, void __user *arg)
{
int version;
if (copy_from_user(&version, arg, sizeof(int)))
return -EFAULT;
if ((version < 1) || (version > 2))
return -EINVAL;
reader->r_ver = version;
return 0;
}
static long logger_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct logger_log *log = file_get_log(file);
struct logger_reader *reader;
long ret = -EINVAL;
void __user *argp = (void __user *) arg;
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
if (!reader->r_all)
reader->r_off = get_next_entry_by_uid(log,
reader->r_off, current_euid());
if (log->w_off != reader->r_off)
ret = get_user_hdr_len(reader->r_ver) +
get_entry_msg_len(log, reader->r_off);
else
ret = 0;
break;
case LOGGER_FLUSH_LOG:
if (!(file->f_mode & FMODE_WRITE)) {
ret = -EBADF;
break;
}
if (!(in_egroup_p(file->f_dentry->d_inode->i_gid) ||
capable(CAP_SYSLOG))) {
ret = -EPERM;
break;
}
list_for_each_entry(reader, &log->readers, list)
reader->r_off = log->w_off;
log->head = log->w_off;
ret = 0;
break;
case LOGGER_GET_VERSION:
if (!(file->f_mode & FMODE_READ)) {
ret = -EBADF;
break;
}
reader = file->private_data;
ret = reader->r_ver;
break;
case LOGGER_SET_VERSION:
if (!(file->f_mode & FMODE_READ)) {
ret = -EBADF;
break;
}
reader = file->private_data;
ret = logger_set_version(reader, argp);
break;
}
mutex_unlock(&log->mutex);
return ret;
}
static int __init create_log(char *log_name, int size)
{
int ret = 0;
struct logger_log *log;
unsigned char *buffer;
buffer = vmalloc(size);
if (buffer == NULL)
return -ENOMEM;
log = kzalloc(sizeof(struct logger_log), GFP_KERNEL);
if (log == NULL) {
ret = -ENOMEM;
goto out_free_buffer;
}
log->buffer = buffer;
log->misc.minor = MISC_DYNAMIC_MINOR;
log->misc.name = kstrdup(log_name, GFP_KERNEL);
if (log->misc.name == NULL) {
ret = -ENOMEM;
goto out_free_log;
}
log->misc.fops = &logger_fops;
log->misc.parent = NULL;
init_waitqueue_head(&log->wq);
INIT_LIST_HEAD(&log->readers);
mutex_init(&log->mutex);
log->w_off = 0;
log->head = 0;
log->size = size;
INIT_LIST_HEAD(&log->logs);
list_add_tail(&log->logs, &log_list);
ret = misc_register(&log->misc);
if (unlikely(ret)) {
pr_err("failed to register misc device for log '%s'!\n",
log->misc.name);
goto out_free_log;
}
pr_info("created %luK log '%s'\n",
(unsigned long) log->size >> 10, log->misc.name);
return 0;
out_free_log:
kfree(log);
out_free_buffer:
vfree(buffer);
return ret;
}
static int __init logger_init(void)
{
int ret;
ret = create_log(LOGGER_LOG_MAIN, 256*1024);
if (unlikely(ret))
goto out;
ret = create_log(LOGGER_LOG_EVENTS, 256*1024);
if (unlikely(ret))
goto out;
ret = create_log(LOGGER_LOG_RADIO, 256*1024);
if (unlikely(ret))
goto out;
ret = create_log(LOGGER_LOG_SYSTEM, 256*1024);
if (unlikely(ret))
goto out;
out:
return ret;
}
static void __exit logger_exit(void)
{
struct logger_log *current_log, *next_log;
list_for_each_entry_safe(current_log, next_log, &log_list, logs) {
misc_deregister(&current_log->misc);
vfree(current_log->buffer);
kfree(current_log->misc.name);
list_del(&current_log->logs);
kfree(current_log);
}
}
