static int vmcp_open(struct inode *inode, struct file *file)
{
struct vmcp_session *session;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
session = kmalloc(sizeof(*session), GFP_KERNEL);
if (!session)
return -ENOMEM;
session->bufsize = PAGE_SIZE;
session->response = NULL;
session->resp_size = 0;
mutex_init(&session->mutex);
file->private_data = session;
return nonseekable_open(inode, file);
}
static int vmcp_release(struct inode *inode, struct file *file)
{
struct vmcp_session *session;
session = file->private_data;
file->private_data = NULL;
free_pages((unsigned long)session->response, get_order(session->bufsize));
kfree(session);
return 0;
}
static ssize_t
vmcp_read(struct file *file, char __user *buff, size_t count, loff_t *ppos)
{
ssize_t ret;
size_t size;
struct vmcp_session *session;
session = file->private_data;
if (mutex_lock_interruptible(&session->mutex))
return -ERESTARTSYS;
if (!session->response) {
mutex_unlock(&session->mutex);
return 0;
}
size = min_t(size_t, session->resp_size, session->bufsize);
ret = simple_read_from_buffer(buff, count, ppos,
session->response, size);
mutex_unlock(&session->mutex);
return ret;
}
static ssize_t
vmcp_write(struct file *file, const char __user *buff, size_t count,
loff_t *ppos)
{
char *cmd;
struct vmcp_session *session;
if (count > 240)
return -EINVAL;
cmd = memdup_user_nul(buff, count);
if (IS_ERR(cmd))
return PTR_ERR(cmd);
session = file->private_data;
if (mutex_lock_interruptible(&session->mutex)) {
kfree(cmd);
return -ERESTARTSYS;
}
if (!session->response)
session->response = (char *)__get_free_pages(GFP_KERNEL
| __GFP_RETRY_MAYFAIL | GFP_DMA,
get_order(session->bufsize));
if (!session->response) {
mutex_unlock(&session->mutex);
kfree(cmd);
return -ENOMEM;
}
debug_text_event(vmcp_debug, 1, cmd);
session->resp_size = cpcmd(cmd, session->response, session->bufsize,
&session->resp_code);
mutex_unlock(&session->mutex);
kfree(cmd);
*ppos = 0;
return count;
}
static long vmcp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct vmcp_session *session;
int __user *argp;
int temp;
session = file->private_data;
if (is_compat_task())
argp = compat_ptr(arg);
else
argp = (int __user *)arg;
if (mutex_lock_interruptible(&session->mutex))
return -ERESTARTSYS;
switch (cmd) {
case VMCP_GETCODE:
temp = session->resp_code;
mutex_unlock(&session->mutex);
return put_user(temp, argp);
case VMCP_SETBUF:
free_pages((unsigned long)session->response,
get_order(session->bufsize));
session->response=NULL;
temp = get_user(session->bufsize, argp);
if (get_order(session->bufsize) > 8) {
session->bufsize = PAGE_SIZE;
temp = -EINVAL;
}
mutex_unlock(&session->mutex);
return temp;
case VMCP_GETSIZE:
temp = session->resp_size;
mutex_unlock(&session->mutex);
return put_user(temp, argp);
default:
mutex_unlock(&session->mutex);
return -ENOIOCTLCMD;
}
}
static int __init vmcp_init(void)
{
int ret;
if (!MACHINE_IS_VM)
return 0;
vmcp_debug = debug_register("vmcp", 1, 1, 240);
if (!vmcp_debug)
return -ENOMEM;
ret = debug_register_view(vmcp_debug, &debug_hex_ascii_view);
if (ret) {
debug_unregister(vmcp_debug);
return ret;
}
ret = misc_register(&vmcp_dev);
if (ret)
debug_unregister(vmcp_debug);
return ret;
}
