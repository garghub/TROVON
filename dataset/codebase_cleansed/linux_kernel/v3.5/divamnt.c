static char *getrev(const char *revision)
{
char *rev;
char *p;
if ((p = strchr(revision, ':'))) {
rev = p + 2;
p = strchr(rev, '$');
*--p = 0;
} else
rev = "1.0";
return rev;
}
int diva_os_copy_to_user(void *os_handle, void __user *dst, const void *src,
int length)
{
return (copy_to_user(dst, src, length));
}
int diva_os_copy_from_user(void *os_handle, void *dst, const void __user *src,
int length)
{
return (copy_from_user(dst, src, length));
}
void diva_os_get_time(dword *sec, dword *usec)
{
struct timeval tv;
do_gettimeofday(&tv);
if (tv.tv_sec > start_time.tv_sec) {
if (start_time.tv_usec > tv.tv_usec) {
tv.tv_sec--;
tv.tv_usec += 1000000;
}
*sec = (dword) (tv.tv_sec - start_time.tv_sec);
*usec = (dword) (tv.tv_usec - start_time.tv_usec);
} else if (tv.tv_sec == start_time.tv_sec) {
*sec = 0;
if (start_time.tv_usec < tv.tv_usec) {
*usec = (dword) (tv.tv_usec - start_time.tv_usec);
} else {
*usec = 0;
}
} else {
*sec = (dword) tv.tv_sec;
*usec = (dword) tv.tv_usec;
}
}
static unsigned int maint_poll(struct file *file, poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &msgwaitq, wait);
mask = POLLOUT | POLLWRNORM;
if (file->private_data || diva_dbg_q_length()) {
mask |= POLLIN | POLLRDNORM;
}
return (mask);
}
static int maint_open(struct inode *ino, struct file *filep)
{
int ret;
mutex_lock(&maint_mutex);
if (test_and_set_bit(0, &opened))
ret = -EBUSY;
else {
filep->private_data = NULL;
ret = nonseekable_open(ino, filep);
}
mutex_unlock(&maint_mutex);
return ret;
}
static int maint_close(struct inode *ino, struct file *filep)
{
if (filep->private_data) {
diva_os_free(0, filep->private_data);
filep->private_data = NULL;
}
clear_bit(0, &opened);
return (0);
}
static ssize_t divas_maint_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return (maint_read_write((char __user *) buf, (int) count));
}
static ssize_t divas_maint_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
return (maint_read_write(buf, (int) count));
}
static void divas_maint_unregister_chrdev(void)
{
unregister_chrdev(major, DEVNAME);
}
static int __init divas_maint_register_chrdev(void)
{
if ((major = register_chrdev(0, DEVNAME, &divas_maint_fops)) < 0)
{
printk(KERN_ERR "%s: failed to create /dev entry.\n",
DRIVERLNAME);
return (0);
}
return (1);
}
void diva_maint_wakeup_read(void)
{
wake_up_interruptible(&msgwaitq);
}
static int __init maint_init(void)
{
char tmprev[50];
int ret = 0;
void *buffer = NULL;
do_gettimeofday(&start_time);
init_waitqueue_head(&msgwaitq);
printk(KERN_INFO "%s\n", DRIVERNAME);
printk(KERN_INFO "%s: Rel:%s Rev:", DRIVERLNAME, DRIVERRELEASE_MNT);
strcpy(tmprev, main_revision);
printk("%s Build: %s \n", getrev(tmprev), DIVA_BUILD);
if (!divas_maint_register_chrdev()) {
ret = -EIO;
goto out;
}
if (!(mntfunc_init(&buffer_length, &buffer, diva_dbg_mem))) {
printk(KERN_ERR "%s: failed to connect to DIDD.\n",
DRIVERLNAME);
divas_maint_unregister_chrdev();
ret = -EIO;
goto out;
}
printk(KERN_INFO "%s: trace buffer = %p - %d kBytes, %s (Major: %d)\n",
DRIVERLNAME, buffer, (buffer_length / 1024),
(diva_dbg_mem == 0) ? "internal" : "external", major);
out:
return (ret);
}
static void __exit maint_exit(void)
{
divas_maint_unregister_chrdev();
mntfunc_finit();
printk(KERN_INFO "%s: module unloaded.\n", DRIVERLNAME);
}
