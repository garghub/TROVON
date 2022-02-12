static int rng_dev_open (struct inode *inode, struct file *filp)
{
if ((filp->f_mode & FMODE_READ) == 0)
return -EINVAL;
if ((filp->f_mode & FMODE_WRITE) != 0)
return -EINVAL;
return 0;
}
static ssize_t rng_dev_read (struct file *filp, char __user *buf, size_t size,
loff_t *offp)
{
u32 data;
int n, ret = 0, have_data;
while (size) {
n = os_read_file(random_fd, &data, sizeof(data));
if (n > 0) {
have_data = n;
while (have_data && size) {
if (put_user((u8) data, buf++)) {
ret = ret ? : -EFAULT;
break;
}
size--;
ret++;
have_data--;
data >>= 8;
}
}
else if (n == -EAGAIN) {
DECLARE_WAITQUEUE(wait, current);
if (filp->f_flags & O_NONBLOCK)
return ret ? : -EAGAIN;
atomic_inc(&host_sleep_count);
reactivate_fd(random_fd, RANDOM_IRQ);
add_sigio_fd(random_fd);
add_wait_queue(&host_read_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
schedule();
remove_wait_queue(&host_read_wait, &wait);
if (atomic_dec_and_test(&host_sleep_count)) {
ignore_sigio_fd(random_fd);
deactivate_fd(random_fd, RANDOM_IRQ);
}
}
else
return n;
if (signal_pending (current))
return ret ? : -ERESTARTSYS;
}
return ret;
}
static irqreturn_t random_interrupt(int irq, void *data)
{
wake_up(&host_read_wait);
return IRQ_HANDLED;
}
static int __init rng_init (void)
{
int err;
err = os_open_file("/dev/random", of_read(OPENFLAGS()), 0);
if (err < 0)
goto out;
random_fd = err;
err = um_request_irq(RANDOM_IRQ, random_fd, IRQ_READ, random_interrupt,
0, "random", NULL);
if (err)
goto err_out_cleanup_hw;
sigio_broken(random_fd, 1);
err = misc_register (&rng_miscdev);
if (err) {
printk (KERN_ERR RNG_MODULE_NAME ": misc device register "
"failed\n");
goto err_out_cleanup_hw;
}
out:
return err;
err_out_cleanup_hw:
os_close_file(random_fd);
random_fd = -1;
goto out;
}
static void __exit rng_cleanup (void)
{
os_close_file(random_fd);
misc_deregister (&rng_miscdev);
}
