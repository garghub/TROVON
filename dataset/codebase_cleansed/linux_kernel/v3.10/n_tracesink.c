static int n_tracesink_open(struct tty_struct *tty)
{
int retval = -EEXIST;
mutex_lock(&writelock);
if (this_tty == NULL) {
this_tty = tty_kref_get(tty);
if (this_tty == NULL) {
retval = -EFAULT;
} else {
tty->disc_data = this_tty;
tty_driver_flush_buffer(tty);
retval = 0;
}
}
mutex_unlock(&writelock);
return retval;
}
static void n_tracesink_close(struct tty_struct *tty)
{
mutex_lock(&writelock);
tty_driver_flush_buffer(tty);
tty_kref_put(this_tty);
this_tty = NULL;
tty->disc_data = NULL;
mutex_unlock(&writelock);
}
static ssize_t n_tracesink_read(struct tty_struct *tty, struct file *file,
unsigned char __user *buf, size_t nr) {
return -EINVAL;
}
static ssize_t n_tracesink_write(struct tty_struct *tty, struct file *file,
const unsigned char *buf, size_t nr) {
return -EINVAL;
}
void n_tracesink_datadrain(u8 *buf, int count)
{
mutex_lock(&writelock);
if ((buf != NULL) && (count > 0) && (this_tty != NULL))
this_tty->ops->write(this_tty, buf, count);
mutex_unlock(&writelock);
}
static int __init n_tracesink_init(void)
{
int retval = tty_register_ldisc(N_TRACESINK, &tty_n_tracesink);
if (retval < 0)
pr_err("%s: Registration failed: %d\n", __func__, retval);
return retval;
}
static void __exit n_tracesink_exit(void)
{
int retval = tty_unregister_ldisc(N_TRACESINK);
if (retval < 0)
pr_err("%s: Unregistration failed: %d\n", __func__, retval);
}
