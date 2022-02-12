static void emit_log_char(struct debug_log *debug_log, char c)
{
LOG_BUFF(debug_log->log_end) = c;
debug_log->log_end++;
if (debug_log->log_end - debug_log->log_start > log_buff_len)
debug_log->log_start = debug_log->log_end - log_buff_len;
}
static int fdebug_log(struct debug_log *debug_log, char *fmt, ...)
{
va_list args;
static char debug_log_buf[256];
char *p;
if (!debug_log)
return 0;
spin_lock_bh(&debug_log->lock);
va_start(args, fmt);
vscnprintf(debug_log_buf, sizeof(debug_log_buf), fmt, args);
va_end(args);
for (p = debug_log_buf; *p != 0; p++)
emit_log_char(debug_log, *p);
spin_unlock_bh(&debug_log->lock);
wake_up(&debug_log->queue_wait);
return 0;
}
int debug_log(struct bat_priv *bat_priv, char *fmt, ...)
{
va_list args;
char tmp_log_buf[256];
va_start(args, fmt);
vscnprintf(tmp_log_buf, sizeof(tmp_log_buf), fmt, args);
fdebug_log(bat_priv->debug_log, "[%10u] %s",
(jiffies / HZ), tmp_log_buf);
va_end(args);
return 0;
}
static int log_open(struct inode *inode, struct file *file)
{
nonseekable_open(inode, file);
file->private_data = inode->i_private;
inc_module_count();
return 0;
}
static int log_release(struct inode *inode, struct file *file)
{
dec_module_count();
return 0;
}
static ssize_t log_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct bat_priv *bat_priv = file->private_data;
struct debug_log *debug_log = bat_priv->debug_log;
int error, i = 0;
char c;
if ((file->f_flags & O_NONBLOCK) &&
!(debug_log->log_end - debug_log->log_start))
return -EAGAIN;
if ((!buf) || (count < 0))
return -EINVAL;
if (count == 0)
return 0;
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
error = wait_event_interruptible(debug_log->queue_wait,
(debug_log->log_start - debug_log->log_end));
if (error)
return error;
spin_lock_bh(&debug_log->lock);
while ((!error) && (i < count) &&
(debug_log->log_start != debug_log->log_end)) {
c = LOG_BUFF(debug_log->log_start);
debug_log->log_start++;
spin_unlock_bh(&debug_log->lock);
error = __put_user(c, buf);
spin_lock_bh(&debug_log->lock);
buf++;
i++;
}
spin_unlock_bh(&debug_log->lock);
if (!error)
return i;
return error;
}
static unsigned int log_poll(struct file *file, poll_table *wait)
{
struct bat_priv *bat_priv = file->private_data;
struct debug_log *debug_log = bat_priv->debug_log;
poll_wait(file, &debug_log->queue_wait, wait);
if (debug_log->log_end - debug_log->log_start)
return POLLIN | POLLRDNORM;
return 0;
}
static int debug_log_setup(struct bat_priv *bat_priv)
{
struct dentry *d;
if (!bat_priv->debug_dir)
goto err;
bat_priv->debug_log = kzalloc(sizeof(struct debug_log), GFP_ATOMIC);
if (!bat_priv->debug_log)
goto err;
spin_lock_init(&bat_priv->debug_log->lock);
init_waitqueue_head(&bat_priv->debug_log->queue_wait);
d = debugfs_create_file("log", S_IFREG | S_IRUSR,
bat_priv->debug_dir, bat_priv, &log_fops);
if (d)
goto err;
return 0;
err:
return 1;
}
static void debug_log_cleanup(struct bat_priv *bat_priv)
{
kfree(bat_priv->debug_log);
bat_priv->debug_log = NULL;
}
static int debug_log_setup(struct bat_priv *bat_priv)
{
bat_priv->debug_log = NULL;
return 0;
}
static void debug_log_cleanup(struct bat_priv *bat_priv)
{
return;
}
static int originators_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, orig_seq_print_text, net_dev);
}
static int gateways_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, gw_client_seq_print_text, net_dev);
}
static int softif_neigh_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, softif_neigh_seq_print_text, net_dev);
}
static int transtable_global_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, tt_global_seq_print_text, net_dev);
}
static int transtable_local_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, tt_local_seq_print_text, net_dev);
}
static int vis_data_open(struct inode *inode, struct file *file)
{
struct net_device *net_dev = (struct net_device *)inode->i_private;
return single_open(file, vis_seq_print_text, net_dev);
}
void debugfs_init(void)
{
bat_debugfs = debugfs_create_dir(DEBUGFS_BAT_SUBDIR, NULL);
if (bat_debugfs == ERR_PTR(-ENODEV))
bat_debugfs = NULL;
}
void debugfs_destroy(void)
{
if (bat_debugfs) {
debugfs_remove_recursive(bat_debugfs);
bat_debugfs = NULL;
}
}
int debugfs_add_meshif(struct net_device *dev)
{
struct bat_priv *bat_priv = netdev_priv(dev);
struct bat_debuginfo **bat_debug;
struct dentry *file;
if (!bat_debugfs)
goto out;
bat_priv->debug_dir = debugfs_create_dir(dev->name, bat_debugfs);
if (!bat_priv->debug_dir)
goto out;
bat_socket_setup(bat_priv);
debug_log_setup(bat_priv);
for (bat_debug = mesh_debuginfos; *bat_debug; ++bat_debug) {
file = debugfs_create_file(((*bat_debug)->attr).name,
S_IFREG | ((*bat_debug)->attr).mode,
bat_priv->debug_dir,
dev, &(*bat_debug)->fops);
if (!file) {
bat_err(dev, "Can't add debugfs file: %s/%s\n",
dev->name, ((*bat_debug)->attr).name);
goto rem_attr;
}
}
return 0;
rem_attr:
debugfs_remove_recursive(bat_priv->debug_dir);
bat_priv->debug_dir = NULL;
out:
#ifdef CONFIG_DEBUG_FS
return -ENOMEM;
#else
return 0;
#endif
}
void debugfs_del_meshif(struct net_device *dev)
{
struct bat_priv *bat_priv = netdev_priv(dev);
debug_log_cleanup(bat_priv);
if (bat_debugfs) {
debugfs_remove_recursive(bat_priv->debug_dir);
bat_priv->debug_dir = NULL;
}
}
