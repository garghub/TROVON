static int harddog_open(struct inode *inode, struct file *file)
{
int err = -EBUSY;
char *sock = NULL;
mutex_lock(&harddog_mutex);
spin_lock(&lock);
if(timer_alive)
goto err;
#ifdef CONFIG_WATCHDOG_NOWAYOUT
__module_get(THIS_MODULE);
#endif
#ifdef CONFIG_MCONSOLE
sock = mconsole_notify_socket();
#endif
err = start_watchdog(&harddog_in_fd, &harddog_out_fd, sock);
if(err)
goto err;
timer_alive = 1;
spin_unlock(&lock);
mutex_unlock(&harddog_mutex);
return nonseekable_open(inode, file);
err:
spin_unlock(&lock);
mutex_unlock(&harddog_mutex);
return err;
}
static int harddog_release(struct inode *inode, struct file *file)
{
spin_lock(&lock);
stop_watchdog(harddog_in_fd, harddog_out_fd);
harddog_in_fd = -1;
harddog_out_fd = -1;
timer_alive=0;
spin_unlock(&lock);
return 0;
}
static ssize_t harddog_write(struct file *file, const char __user *data, size_t len,
loff_t *ppos)
{
if(len)
return ping_watchdog(harddog_out_fd);
return 0;
}
static int harddog_ioctl_unlocked(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp= (void __user *)arg;
static struct watchdog_info ident = {
WDIOC_SETTIMEOUT,
0,
"UML Hardware Watchdog"
};
switch (cmd) {
default:
return -ENOTTY;
case WDIOC_GETSUPPORT:
if(copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0,(int __user *)argp);
case WDIOC_KEEPALIVE:
return ping_watchdog(harddog_out_fd);
}
}
static long harddog_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
long ret;
mutex_lock(&harddog_mutex);
ret = harddog_ioctl_unlocked(file, cmd, arg);
mutex_unlock(&harddog_mutex);
return ret;
}
static int __init harddog_init(void)
{
int ret;
ret = misc_register(&harddog_miscdev);
if (ret)
return ret;
printk(banner);
return 0;
}
static void __exit harddog_exit(void)
{
misc_deregister(&harddog_miscdev);
}
