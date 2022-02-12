static inline bool __acpi_aml_running(void)
{
return acpi_aml_io.thread ? true : false;
}
static inline bool __acpi_aml_access_ok(unsigned long flag)
{
if (!(acpi_aml_io.flags & ACPI_AML_OPENED) ||
(acpi_aml_io.flags & ACPI_AML_CLOSED) ||
!__acpi_aml_running())
return false;
if ((flag & ACPI_AML_KERN) &&
current != acpi_aml_io.thread)
return false;
return true;
}
static inline bool __acpi_aml_readable(struct circ_buf *circ, unsigned long flag)
{
if (!(acpi_aml_io.flags & flag) && circ_count(circ))
return true;
return false;
}
static inline bool __acpi_aml_writable(struct circ_buf *circ, unsigned long flag)
{
if (!(acpi_aml_io.flags & flag) && circ_space(circ))
return true;
return false;
}
static inline bool __acpi_aml_busy(void)
{
if (acpi_aml_io.flags & ACPI_AML_BUSY)
return true;
return false;
}
static inline bool __acpi_aml_opened(void)
{
if (acpi_aml_io.flags & ACPI_AML_OPEN)
return true;
return false;
}
static inline bool __acpi_aml_used(void)
{
return acpi_aml_io.usages ? true : false;
}
static inline bool acpi_aml_running(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = __acpi_aml_running();
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_busy(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = __acpi_aml_busy();
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_used(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = __acpi_aml_used();
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_kern_readable(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = !__acpi_aml_access_ok(ACPI_AML_IN_KERN) ||
__acpi_aml_readable(&acpi_aml_io.in_crc, ACPI_AML_IN_KERN);
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_kern_writable(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = !__acpi_aml_access_ok(ACPI_AML_OUT_KERN) ||
__acpi_aml_writable(&acpi_aml_io.out_crc, ACPI_AML_OUT_KERN);
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_user_readable(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = !__acpi_aml_access_ok(ACPI_AML_OUT_USER) ||
__acpi_aml_readable(&acpi_aml_io.out_crc, ACPI_AML_OUT_USER);
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static bool acpi_aml_user_writable(void)
{
bool ret;
mutex_lock(&acpi_aml_io.lock);
ret = !__acpi_aml_access_ok(ACPI_AML_IN_USER) ||
__acpi_aml_writable(&acpi_aml_io.in_crc, ACPI_AML_IN_USER);
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static int acpi_aml_lock_write(struct circ_buf *circ, unsigned long flag)
{
int ret = 0;
mutex_lock(&acpi_aml_io.lock);
if (!__acpi_aml_access_ok(flag)) {
ret = -EFAULT;
goto out;
}
if (!__acpi_aml_writable(circ, flag)) {
ret = -EAGAIN;
goto out;
}
acpi_aml_io.flags |= flag;
out:
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static int acpi_aml_lock_read(struct circ_buf *circ, unsigned long flag)
{
int ret = 0;
mutex_lock(&acpi_aml_io.lock);
if (!__acpi_aml_access_ok(flag)) {
ret = -EFAULT;
goto out;
}
if (!__acpi_aml_readable(circ, flag)) {
ret = -EAGAIN;
goto out;
}
acpi_aml_io.flags |= flag;
out:
mutex_unlock(&acpi_aml_io.lock);
return ret;
}
static void acpi_aml_unlock_fifo(unsigned long flag, bool wakeup)
{
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.flags &= ~flag;
if (wakeup)
wake_up_interruptible(&acpi_aml_io.wait);
mutex_unlock(&acpi_aml_io.lock);
}
static int acpi_aml_write_kern(const char *buf, int len)
{
int ret;
struct circ_buf *crc = &acpi_aml_io.out_crc;
int n;
char *p;
ret = acpi_aml_lock_write(crc, ACPI_AML_OUT_KERN);
if (ret < 0)
return ret;
smp_mb();
p = &crc->buf[crc->head];
n = min(len, circ_space_to_end(crc));
memcpy(p, buf, n);
smp_wmb();
crc->head = (crc->head + n) & (ACPI_AML_BUF_SIZE - 1);
acpi_aml_unlock_fifo(ACPI_AML_OUT_KERN, true);
return n;
}
static int acpi_aml_readb_kern(void)
{
int ret;
struct circ_buf *crc = &acpi_aml_io.in_crc;
char *p;
ret = acpi_aml_lock_read(crc, ACPI_AML_IN_KERN);
if (ret < 0)
return ret;
smp_rmb();
p = &crc->buf[crc->tail];
ret = (int)*p;
smp_mb();
crc->tail = (crc->tail + 1) & (ACPI_AML_BUF_SIZE - 1);
acpi_aml_unlock_fifo(ACPI_AML_IN_KERN, true);
return ret;
}
static ssize_t acpi_aml_write_log(const char *msg)
{
int ret = 0;
int count = 0, size = 0;
if (!acpi_aml_initialized)
return -ENODEV;
if (msg)
count = strlen(msg);
while (count > 0) {
again:
ret = acpi_aml_write_kern(msg + size, count);
if (ret == -EAGAIN) {
ret = wait_event_interruptible(acpi_aml_io.wait,
acpi_aml_kern_writable());
if (ret == 0)
goto again;
break;
}
if (ret < 0)
break;
size += ret;
count -= ret;
}
return size > 0 ? size : ret;
}
static ssize_t acpi_aml_read_cmd(char *msg, size_t count)
{
int ret = 0;
int size = 0;
BUG_ON(!acpi_aml_initialized);
while (count > 0) {
again:
ret = acpi_aml_readb_kern();
if (ret == -EAGAIN) {
ret = wait_event_interruptible(acpi_aml_io.wait,
acpi_aml_kern_readable());
if (ret == 0)
goto again;
}
if (ret < 0)
break;
*(msg + size) = (char)ret;
size++;
count--;
if (ret == '\n') {
*(msg + size - 1) = '\0';
break;
}
}
return size > 0 ? size : ret;
}
static int acpi_aml_thread(void *unsed)
{
acpi_osd_exec_callback function = NULL;
void *context;
mutex_lock(&acpi_aml_io.lock);
if (acpi_aml_io.function) {
acpi_aml_io.usages++;
function = acpi_aml_io.function;
context = acpi_aml_io.context;
}
mutex_unlock(&acpi_aml_io.lock);
if (function)
function(context);
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.usages--;
if (!__acpi_aml_used()) {
acpi_aml_io.thread = NULL;
wake_up(&acpi_aml_io.wait);
}
mutex_unlock(&acpi_aml_io.lock);
return 0;
}
static int acpi_aml_create_thread(acpi_osd_exec_callback function, void *context)
{
struct task_struct *t;
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.function = function;
acpi_aml_io.context = context;
mutex_unlock(&acpi_aml_io.lock);
t = kthread_create(acpi_aml_thread, NULL, "aml");
if (IS_ERR(t)) {
pr_err("Failed to create AML debugger thread.\n");
return PTR_ERR(t);
}
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.thread = t;
acpi_set_debugger_thread_id((acpi_thread_id)(unsigned long)t);
wake_up_process(t);
mutex_unlock(&acpi_aml_io.lock);
return 0;
}
static int acpi_aml_wait_command_ready(bool single_step,
char *buffer, size_t length)
{
acpi_status status;
if (single_step)
acpi_os_printf("\n%1c ", ACPI_DEBUGGER_EXECUTE_PROMPT);
else
acpi_os_printf("\n%1c ", ACPI_DEBUGGER_COMMAND_PROMPT);
status = acpi_os_get_line(buffer, length, NULL);
if (ACPI_FAILURE(status))
return -EINVAL;
return 0;
}
static int acpi_aml_notify_command_complete(void)
{
return 0;
}
static int acpi_aml_open(struct inode *inode, struct file *file)
{
int ret = 0;
acpi_status status;
mutex_lock(&acpi_aml_io.lock);
if (acpi_aml_io.flags & ACPI_AML_CLOSED) {
ret = -EBUSY;
goto err_lock;
}
if ((file->f_flags & O_ACCMODE) != O_WRONLY) {
if (acpi_aml_active_reader) {
ret = -EBUSY;
goto err_lock;
} else {
pr_debug("Opening debugger reader.\n");
acpi_aml_active_reader = file;
}
} else {
if (!(acpi_aml_io.flags & ACPI_AML_OPENED)) {
ret = -ENODEV;
goto err_lock;
}
}
if (acpi_aml_active_reader == file) {
pr_debug("Opening debugger interface.\n");
mutex_unlock(&acpi_aml_io.lock);
pr_debug("Initializing debugger thread.\n");
status = acpi_initialize_debugger();
if (ACPI_FAILURE(status)) {
pr_err("Failed to initialize debugger.\n");
ret = -EINVAL;
goto err_exit;
}
pr_debug("Debugger thread initialized.\n");
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.flags |= ACPI_AML_OPENED;
acpi_aml_io.out_crc.head = acpi_aml_io.out_crc.tail = 0;
acpi_aml_io.in_crc.head = acpi_aml_io.in_crc.tail = 0;
pr_debug("Debugger interface opened.\n");
}
acpi_aml_io.users++;
err_lock:
if (ret < 0) {
if (acpi_aml_active_reader == file)
acpi_aml_active_reader = NULL;
}
mutex_unlock(&acpi_aml_io.lock);
err_exit:
return ret;
}
static int acpi_aml_release(struct inode *inode, struct file *file)
{
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.users--;
if (file == acpi_aml_active_reader) {
pr_debug("Closing debugger reader.\n");
acpi_aml_active_reader = NULL;
pr_debug("Closing debugger interface.\n");
acpi_aml_io.flags |= ACPI_AML_CLOSED;
wake_up_interruptible(&acpi_aml_io.wait);
mutex_unlock(&acpi_aml_io.lock);
wait_event(acpi_aml_io.wait, !acpi_aml_busy());
pr_debug("Terminating debugger thread.\n");
acpi_terminate_debugger();
wait_event(acpi_aml_io.wait, !acpi_aml_used());
pr_debug("Debugger thread terminated.\n");
mutex_lock(&acpi_aml_io.lock);
acpi_aml_io.flags &= ~ACPI_AML_OPENED;
}
if (acpi_aml_io.users == 0) {
pr_debug("Debugger interface closed.\n");
acpi_aml_io.flags &= ~ACPI_AML_CLOSED;
}
mutex_unlock(&acpi_aml_io.lock);
return 0;
}
static int acpi_aml_read_user(char __user *buf, int len)
{
int ret;
struct circ_buf *crc = &acpi_aml_io.out_crc;
int n;
char *p;
ret = acpi_aml_lock_read(crc, ACPI_AML_OUT_USER);
if (ret < 0)
return ret;
smp_rmb();
p = &crc->buf[crc->tail];
n = min(len, circ_count_to_end(crc));
if (copy_to_user(buf, p, n)) {
ret = -EFAULT;
goto out;
}
smp_mb();
crc->tail = (crc->tail + n) & (ACPI_AML_BUF_SIZE - 1);
ret = n;
out:
acpi_aml_unlock_fifo(ACPI_AML_OUT_USER, ret >= 0);
return ret;
}
static ssize_t acpi_aml_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
int ret = 0;
int size = 0;
if (!count)
return 0;
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
while (count > 0) {
again:
ret = acpi_aml_read_user(buf + size, count);
if (ret == -EAGAIN) {
if (file->f_flags & O_NONBLOCK)
break;
else {
ret = wait_event_interruptible(acpi_aml_io.wait,
acpi_aml_user_readable());
if (ret == 0)
goto again;
}
}
if (ret < 0) {
if (!acpi_aml_running())
ret = 0;
break;
}
if (ret) {
size += ret;
count -= ret;
*ppos += ret;
break;
}
}
return size > 0 ? size : ret;
}
static int acpi_aml_write_user(const char __user *buf, int len)
{
int ret;
struct circ_buf *crc = &acpi_aml_io.in_crc;
int n;
char *p;
ret = acpi_aml_lock_write(crc, ACPI_AML_IN_USER);
if (ret < 0)
return ret;
smp_mb();
p = &crc->buf[crc->head];
n = min(len, circ_space_to_end(crc));
if (copy_from_user(p, buf, n)) {
ret = -EFAULT;
goto out;
}
smp_wmb();
crc->head = (crc->head + n) & (ACPI_AML_BUF_SIZE - 1);
ret = n;
out:
acpi_aml_unlock_fifo(ACPI_AML_IN_USER, ret >= 0);
return n;
}
static ssize_t acpi_aml_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
int ret = 0;
int size = 0;
if (!count)
return 0;
if (!access_ok(VERIFY_READ, buf, count))
return -EFAULT;
while (count > 0) {
again:
ret = acpi_aml_write_user(buf + size, count);
if (ret == -EAGAIN) {
if (file->f_flags & O_NONBLOCK)
break;
else {
ret = wait_event_interruptible(acpi_aml_io.wait,
acpi_aml_user_writable());
if (ret == 0)
goto again;
}
}
if (ret < 0) {
if (!acpi_aml_running())
ret = 0;
break;
}
if (ret) {
size += ret;
count -= ret;
*ppos += ret;
}
}
return size > 0 ? size : ret;
}
static unsigned int acpi_aml_poll(struct file *file, poll_table *wait)
{
int masks = 0;
poll_wait(file, &acpi_aml_io.wait, wait);
if (acpi_aml_user_readable())
masks |= POLLIN | POLLRDNORM;
if (acpi_aml_user_writable())
masks |= POLLOUT | POLLWRNORM;
return masks;
}
int __init acpi_aml_init(void)
{
int ret = 0;
if (!acpi_debugfs_dir) {
ret = -ENOENT;
goto err_exit;
}
mutex_init(&acpi_aml_io.lock);
init_waitqueue_head(&acpi_aml_io.wait);
acpi_aml_io.out_crc.buf = acpi_aml_io.out_buf;
acpi_aml_io.in_crc.buf = acpi_aml_io.in_buf;
acpi_aml_dentry = debugfs_create_file("acpidbg",
S_IFREG | S_IRUGO | S_IWUSR,
acpi_debugfs_dir, NULL,
&acpi_aml_operations);
if (acpi_aml_dentry == NULL) {
ret = -ENODEV;
goto err_exit;
}
ret = acpi_register_debugger(THIS_MODULE, &acpi_aml_debugger);
if (ret)
goto err_fs;
acpi_aml_initialized = true;
err_fs:
if (ret) {
debugfs_remove(acpi_aml_dentry);
acpi_aml_dentry = NULL;
}
err_exit:
return ret;
}
void __exit acpi_aml_exit(void)
{
if (acpi_aml_initialized) {
acpi_unregister_debugger(&acpi_aml_debugger);
if (acpi_aml_dentry) {
debugfs_remove(acpi_aml_dentry);
acpi_aml_dentry = NULL;
}
acpi_aml_initialized = false;
}
}
