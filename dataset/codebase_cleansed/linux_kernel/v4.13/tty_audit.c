static struct tty_audit_buf *tty_audit_buf_ref(void)
{
struct tty_audit_buf *buf;
buf = current->signal->tty_audit_buf;
WARN_ON(buf == ERR_PTR(-ESRCH));
return buf;
}
static struct tty_audit_buf *tty_audit_buf_alloc(void)
{
struct tty_audit_buf *buf;
buf = kmalloc(sizeof(*buf), GFP_KERNEL);
if (!buf)
goto err;
buf->data = kmalloc(N_TTY_BUF_SIZE, GFP_KERNEL);
if (!buf->data)
goto err_buf;
mutex_init(&buf->mutex);
buf->dev = MKDEV(0, 0);
buf->icanon = 0;
buf->valid = 0;
return buf;
err_buf:
kfree(buf);
err:
return NULL;
}
static void tty_audit_buf_free(struct tty_audit_buf *buf)
{
WARN_ON(buf->valid != 0);
kfree(buf->data);
kfree(buf);
}
static void tty_audit_log(const char *description, dev_t dev,
unsigned char *data, size_t size)
{
struct audit_buffer *ab;
struct task_struct *tsk = current;
pid_t pid = task_pid_nr(tsk);
uid_t uid = from_kuid(&init_user_ns, task_uid(tsk));
uid_t loginuid = from_kuid(&init_user_ns, audit_get_loginuid(tsk));
unsigned int sessionid = audit_get_sessionid(tsk);
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_TTY);
if (ab) {
char name[sizeof(tsk->comm)];
audit_log_format(ab, "%s pid=%u uid=%u auid=%u ses=%u major=%d"
" minor=%d comm=", description, pid, uid,
loginuid, sessionid, MAJOR(dev), MINOR(dev));
get_task_comm(name, tsk);
audit_log_untrustedstring(ab, name);
audit_log_format(ab, " data=");
audit_log_n_hex(ab, data, size);
audit_log_end(ab);
}
}
static void tty_audit_buf_push(struct tty_audit_buf *buf)
{
if (buf->valid == 0)
return;
if (audit_enabled == 0) {
buf->valid = 0;
return;
}
tty_audit_log("tty", buf->dev, buf->data, buf->valid);
buf->valid = 0;
}
void tty_audit_exit(void)
{
struct tty_audit_buf *buf;
buf = xchg(&current->signal->tty_audit_buf, ERR_PTR(-ESRCH));
if (!buf)
return;
tty_audit_buf_push(buf);
tty_audit_buf_free(buf);
}
void tty_audit_fork(struct signal_struct *sig)
{
sig->audit_tty = current->signal->audit_tty;
}
void tty_audit_tiocsti(struct tty_struct *tty, char ch)
{
dev_t dev;
dev = MKDEV(tty->driver->major, tty->driver->minor_start) + tty->index;
if (tty_audit_push())
return;
if (audit_enabled)
tty_audit_log("ioctl=TIOCSTI", dev, &ch, 1);
}
int tty_audit_push(void)
{
struct tty_audit_buf *buf;
if (~current->signal->audit_tty & AUDIT_TTY_ENABLE)
return -EPERM;
buf = tty_audit_buf_ref();
if (!IS_ERR_OR_NULL(buf)) {
mutex_lock(&buf->mutex);
tty_audit_buf_push(buf);
mutex_unlock(&buf->mutex);
}
return 0;
}
static struct tty_audit_buf *tty_audit_buf_get(void)
{
struct tty_audit_buf *buf;
buf = tty_audit_buf_ref();
if (buf)
return buf;
buf = tty_audit_buf_alloc();
if (buf == NULL) {
audit_log_lost("out of memory in TTY auditing");
return NULL;
}
if (cmpxchg(&current->signal->tty_audit_buf, NULL, buf) != NULL)
tty_audit_buf_free(buf);
return tty_audit_buf_ref();
}
void tty_audit_add_data(struct tty_struct *tty, const void *data, size_t size)
{
struct tty_audit_buf *buf;
unsigned int icanon = !!L_ICANON(tty);
unsigned int audit_tty;
dev_t dev;
audit_tty = READ_ONCE(current->signal->audit_tty);
if (~audit_tty & AUDIT_TTY_ENABLE)
return;
if (unlikely(size == 0))
return;
if (tty->driver->type == TTY_DRIVER_TYPE_PTY
&& tty->driver->subtype == PTY_TYPE_MASTER)
return;
if ((~audit_tty & AUDIT_TTY_LOG_PASSWD) && icanon && !L_ECHO(tty))
return;
buf = tty_audit_buf_get();
if (IS_ERR_OR_NULL(buf))
return;
mutex_lock(&buf->mutex);
dev = MKDEV(tty->driver->major, tty->driver->minor_start) + tty->index;
if (buf->dev != dev || buf->icanon != icanon) {
tty_audit_buf_push(buf);
buf->dev = dev;
buf->icanon = icanon;
}
do {
size_t run;
run = N_TTY_BUF_SIZE - buf->valid;
if (run > size)
run = size;
memcpy(buf->data + buf->valid, data, run);
buf->valid += run;
data += run;
size -= run;
if (buf->valid == N_TTY_BUF_SIZE)
tty_audit_buf_push(buf);
} while (size != 0);
mutex_unlock(&buf->mutex);
}
