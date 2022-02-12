static int n_tracerouter_open(struct tty_struct *tty)
{
int retval = -EEXIST;
mutex_lock(&routelock);
if (tr_data->opencalled == 0) {
tr_data->kref_tty = tty_kref_get(tty);
if (tr_data->kref_tty == NULL) {
retval = -EFAULT;
} else {
tr_data->opencalled = 1;
tty->disc_data = tr_data;
tty->receive_room = RECEIVE_ROOM;
tty_driver_flush_buffer(tty);
retval = 0;
}
}
mutex_unlock(&routelock);
return retval;
}
static void n_tracerouter_close(struct tty_struct *tty)
{
struct tracerouter_data *tptr = tty->disc_data;
mutex_lock(&routelock);
WARN_ON(tptr->kref_tty != tr_data->kref_tty);
tty_driver_flush_buffer(tty);
tty_kref_put(tr_data->kref_tty);
tr_data->kref_tty = NULL;
tr_data->opencalled = 0;
tty->disc_data = NULL;
mutex_unlock(&routelock);
}
static ssize_t n_tracerouter_read(struct tty_struct *tty, struct file *file,
unsigned char __user *buf, size_t nr) {
return -EINVAL;
}
static ssize_t n_tracerouter_write(struct tty_struct *tty, struct file *file,
const unsigned char *buf, size_t nr) {
return -EINVAL;
}
static void n_tracerouter_receivebuf(struct tty_struct *tty,
const unsigned char *cp,
char *fp, int count)
{
mutex_lock(&routelock);
n_tracesink_datadrain((u8 *) cp, count);
mutex_unlock(&routelock);
}
static int __init n_tracerouter_init(void)
{
int retval;
tr_data = kzalloc(sizeof(struct tracerouter_data), GFP_KERNEL);
if (tr_data == NULL)
return -ENOMEM;
retval = tty_register_ldisc(N_TRACEROUTER, &tty_ptirouter_ldisc);
if (retval < 0) {
pr_err("%s: Registration failed: %d\n", __func__, retval);
kfree(tr_data);
}
return retval;
}
static void __exit n_tracerouter_exit(void)
{
int retval = tty_unregister_ldisc(N_TRACEROUTER);
if (retval < 0)
pr_err("%s: Unregistration failed: %d\n", __func__, retval);
else
kfree(tr_data);
}
