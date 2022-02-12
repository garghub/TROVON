static int debugfs_log_show(struct seq_file *f, void *offset)
{
int *levp = f->private;
char *log_value = NULL;
switch (*levp) {
case VCHIQ_LOG_ERROR:
log_value = VCHIQ_LOG_ERROR_STR;
break;
case VCHIQ_LOG_WARNING:
log_value = VCHIQ_LOG_WARNING_STR;
break;
case VCHIQ_LOG_INFO:
log_value = VCHIQ_LOG_INFO_STR;
break;
case VCHIQ_LOG_TRACE:
log_value = VCHIQ_LOG_TRACE_STR;
break;
default:
break;
}
seq_printf(f, "%s\n", log_value ? log_value : "(null)");
return 0;
}
static int debugfs_log_open(struct inode *inode, struct file *file)
{
return single_open(file, debugfs_log_show, inode->i_private);
}
static int debugfs_log_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *ppos)
{
struct seq_file *f = (struct seq_file *)file->private_data;
int *levp = f->private;
char kbuf[DEBUGFS_WRITE_BUF_SIZE + 1];
memset(kbuf, 0, DEBUGFS_WRITE_BUF_SIZE + 1);
if (count >= DEBUGFS_WRITE_BUF_SIZE)
count = DEBUGFS_WRITE_BUF_SIZE;
if (copy_from_user(kbuf, buffer, count) != 0)
return -EFAULT;
kbuf[count - 1] = 0;
if (strncmp("error", kbuf, strlen("error")) == 0)
*levp = VCHIQ_LOG_ERROR;
else if (strncmp("warning", kbuf, strlen("warning")) == 0)
*levp = VCHIQ_LOG_WARNING;
else if (strncmp("info", kbuf, strlen("info")) == 0)
*levp = VCHIQ_LOG_INFO;
else if (strncmp("trace", kbuf, strlen("trace")) == 0)
*levp = VCHIQ_LOG_TRACE;
else
*levp = VCHIQ_LOG_DEFAULT;
*ppos += count;
return count;
}
static int vchiq_debugfs_create_log_entries(struct dentry *top)
{
struct dentry *dir;
size_t i;
int ret = 0;
dir = debugfs_create_dir("log", vchiq_debugfs_top());
if (!dir)
return -ENOMEM;
debugfs_info.log_categories = dir;
for (i = 0; i < n_log_entries; i++) {
void *levp = (void *)vchiq_debugfs_log_entries[i].plevel;
dir = debugfs_create_file(vchiq_debugfs_log_entries[i].name,
0644,
debugfs_info.log_categories,
levp,
&debugfs_log_fops);
if (!dir) {
ret = -ENOMEM;
break;
}
vchiq_debugfs_log_entries[i].dir = dir;
}
return ret;
}
static int debugfs_usecount_show(struct seq_file *f, void *offset)
{
VCHIQ_INSTANCE_T instance = f->private;
int use_count;
use_count = vchiq_instance_get_use_count(instance);
seq_printf(f, "%d\n", use_count);
return 0;
}
static int debugfs_usecount_open(struct inode *inode, struct file *file)
{
return single_open(file, debugfs_usecount_show, inode->i_private);
}
static int debugfs_trace_show(struct seq_file *f, void *offset)
{
VCHIQ_INSTANCE_T instance = f->private;
int trace;
trace = vchiq_instance_get_trace(instance);
seq_printf(f, "%s\n", trace ? "Y" : "N");
return 0;
}
static int debugfs_trace_open(struct inode *inode, struct file *file)
{
return single_open(file, debugfs_trace_show, inode->i_private);
}
static int debugfs_trace_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *ppos)
{
struct seq_file *f = (struct seq_file *)file->private_data;
VCHIQ_INSTANCE_T instance = f->private;
char firstchar;
if (copy_from_user(&firstchar, buffer, 1) != 0)
return -EFAULT;
switch (firstchar) {
case 'Y':
case 'y':
case '1':
vchiq_instance_set_trace(instance, 1);
break;
case 'N':
case 'n':
case '0':
vchiq_instance_set_trace(instance, 0);
break;
default:
break;
}
*ppos += count;
return count;
}
int vchiq_debugfs_add_instance(VCHIQ_INSTANCE_T instance)
{
char pidstr[16];
struct dentry *top, *use_count, *trace;
struct dentry *clients = vchiq_clients_top();
snprintf(pidstr, sizeof(pidstr), "%d",
vchiq_instance_get_pid(instance));
top = debugfs_create_dir(pidstr, clients);
if (!top)
goto fail_top;
use_count = debugfs_create_file("use_count",
0444, top,
instance,
&debugfs_usecount_fops);
if (!use_count)
goto fail_use_count;
trace = debugfs_create_file("trace",
0644, top,
instance,
&debugfs_trace_fops);
if (!trace)
goto fail_trace;
vchiq_instance_get_debugfs_node(instance)->dentry = top;
return 0;
fail_trace:
debugfs_remove(use_count);
fail_use_count:
debugfs_remove(top);
fail_top:
return -ENOMEM;
}
void vchiq_debugfs_remove_instance(VCHIQ_INSTANCE_T instance)
{
VCHIQ_DEBUGFS_NODE_T *node = vchiq_instance_get_debugfs_node(instance);
debugfs_remove_recursive(node->dentry);
}
int vchiq_debugfs_init(void)
{
BUG_ON(debugfs_info.vchiq_cfg_dir != NULL);
debugfs_info.vchiq_cfg_dir = debugfs_create_dir("vchiq", NULL);
if (debugfs_info.vchiq_cfg_dir == NULL)
goto fail;
debugfs_info.clients = debugfs_create_dir("clients",
vchiq_debugfs_top());
if (!debugfs_info.clients)
goto fail;
if (vchiq_debugfs_create_log_entries(vchiq_debugfs_top()) != 0)
goto fail;
return 0;
fail:
vchiq_debugfs_deinit();
vchiq_log_error(vchiq_arm_log_level,
"%s: failed to create debugfs directory",
__func__);
return -ENOMEM;
}
void vchiq_debugfs_deinit(void)
{
debugfs_remove_recursive(vchiq_debugfs_top());
}
static struct dentry *vchiq_clients_top(void)
{
return debugfs_info.clients;
}
static struct dentry *vchiq_debugfs_top(void)
{
BUG_ON(debugfs_info.vchiq_cfg_dir == NULL);
return debugfs_info.vchiq_cfg_dir;
}
int vchiq_debugfs_init(void)
{
return 0;
}
void vchiq_debugfs_deinit(void)
{
}
int vchiq_debugfs_add_instance(VCHIQ_INSTANCE_T instance)
{
return 0;
}
void vchiq_debugfs_remove_instance(VCHIQ_INSTANCE_T instance)
{
}
