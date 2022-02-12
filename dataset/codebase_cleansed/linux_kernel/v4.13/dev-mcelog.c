static int dev_mce_log(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
unsigned int next, entry;
wmb();
for (;;) {
entry = mce_log_get_idx_check(mcelog.next);
for (;;) {
if (entry >= MCE_LOG_LEN) {
set_bit(MCE_OVERFLOW,
(unsigned long *)&mcelog.flags);
return NOTIFY_OK;
}
if (mcelog.entry[entry].finished) {
entry++;
continue;
}
break;
}
smp_rmb();
next = entry + 1;
if (cmpxchg(&mcelog.next, entry, next) == entry)
break;
}
memcpy(mcelog.entry + entry, mce, sizeof(struct mce));
wmb();
mcelog.entry[entry].finished = 1;
wmb();
wake_up_interruptible(&mce_chrdev_wait);
return NOTIFY_OK;
}
static void mce_do_trigger(struct work_struct *work)
{
call_usermodehelper(mce_helper, mce_helper_argv, NULL, UMH_NO_WAIT);
}
void mce_work_trigger(void)
{
if (mce_helper[0])
schedule_work(&mce_trigger_work);
}
static ssize_t
show_trigger(struct device *s, struct device_attribute *attr, char *buf)
{
strcpy(buf, mce_helper);
strcat(buf, "\n");
return strlen(mce_helper) + 1;
}
static ssize_t set_trigger(struct device *s, struct device_attribute *attr,
const char *buf, size_t siz)
{
char *p;
strncpy(mce_helper, buf, sizeof(mce_helper));
mce_helper[sizeof(mce_helper)-1] = 0;
p = strchr(mce_helper, '\n');
if (p)
*p = 0;
return strlen(mce_helper) + !!p;
}
static int mce_chrdev_open(struct inode *inode, struct file *file)
{
spin_lock(&mce_chrdev_state_lock);
if (mce_chrdev_open_exclu ||
(mce_chrdev_open_count && (file->f_flags & O_EXCL))) {
spin_unlock(&mce_chrdev_state_lock);
return -EBUSY;
}
if (file->f_flags & O_EXCL)
mce_chrdev_open_exclu = 1;
mce_chrdev_open_count++;
spin_unlock(&mce_chrdev_state_lock);
return nonseekable_open(inode, file);
}
static int mce_chrdev_release(struct inode *inode, struct file *file)
{
spin_lock(&mce_chrdev_state_lock);
mce_chrdev_open_count--;
mce_chrdev_open_exclu = 0;
spin_unlock(&mce_chrdev_state_lock);
return 0;
}
static void collect_tscs(void *data)
{
unsigned long *cpu_tsc = (unsigned long *)data;
cpu_tsc[smp_processor_id()] = rdtsc();
}
static int __mce_read_apei(char __user **ubuf, size_t usize)
{
int rc;
u64 record_id;
struct mce m;
if (usize < sizeof(struct mce))
return -EINVAL;
rc = apei_read_mce(&m, &record_id);
if (rc <= 0) {
mce_apei_read_done = 1;
if (rc == -ENODEV)
return 0;
return rc;
}
rc = -EFAULT;
if (copy_to_user(*ubuf, &m, sizeof(struct mce)))
return rc;
rc = apei_clear_mce(record_id);
if (rc) {
mce_apei_read_done = 1;
return rc;
}
*ubuf += sizeof(struct mce);
return 0;
}
static ssize_t mce_chrdev_read(struct file *filp, char __user *ubuf,
size_t usize, loff_t *off)
{
char __user *buf = ubuf;
unsigned long *cpu_tsc;
unsigned prev, next;
int i, err;
cpu_tsc = kmalloc(nr_cpu_ids * sizeof(long), GFP_KERNEL);
if (!cpu_tsc)
return -ENOMEM;
mutex_lock(&mce_chrdev_read_mutex);
if (!mce_apei_read_done) {
err = __mce_read_apei(&buf, usize);
if (err || buf != ubuf)
goto out;
}
next = mce_log_get_idx_check(mcelog.next);
err = -EINVAL;
if (*off != 0 || usize < MCE_LOG_LEN*sizeof(struct mce))
goto out;
err = 0;
prev = 0;
do {
for (i = prev; i < next; i++) {
unsigned long start = jiffies;
struct mce *m = &mcelog.entry[i];
while (!m->finished) {
if (time_after_eq(jiffies, start + 2)) {
memset(m, 0, sizeof(*m));
goto timeout;
}
cpu_relax();
}
smp_rmb();
err |= copy_to_user(buf, m, sizeof(*m));
buf += sizeof(*m);
timeout:
;
}
memset(mcelog.entry + prev, 0,
(next - prev) * sizeof(struct mce));
prev = next;
next = cmpxchg(&mcelog.next, prev, 0);
} while (next != prev);
synchronize_sched();
on_each_cpu(collect_tscs, cpu_tsc, 1);
for (i = next; i < MCE_LOG_LEN; i++) {
struct mce *m = &mcelog.entry[i];
if (m->finished && m->tsc < cpu_tsc[m->cpu]) {
err |= copy_to_user(buf, m, sizeof(*m));
smp_rmb();
buf += sizeof(*m);
memset(m, 0, sizeof(*m));
}
}
if (err)
err = -EFAULT;
out:
mutex_unlock(&mce_chrdev_read_mutex);
kfree(cpu_tsc);
return err ? err : buf - ubuf;
}
static unsigned int mce_chrdev_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &mce_chrdev_wait, wait);
if (READ_ONCE(mcelog.next))
return POLLIN | POLLRDNORM;
if (!mce_apei_read_done && apei_check_mce())
return POLLIN | POLLRDNORM;
return 0;
}
static long mce_chrdev_ioctl(struct file *f, unsigned int cmd,
unsigned long arg)
{
int __user *p = (int __user *)arg;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
switch (cmd) {
case MCE_GET_RECORD_LEN:
return put_user(sizeof(struct mce), p);
case MCE_GET_LOG_LEN:
return put_user(MCE_LOG_LEN, p);
case MCE_GETCLEAR_FLAGS: {
unsigned flags;
do {
flags = mcelog.flags;
} while (cmpxchg(&mcelog.flags, flags, 0) != flags);
return put_user(flags, p);
}
default:
return -ENOTTY;
}
}
void mce_register_injector_chain(struct notifier_block *nb)
{
blocking_notifier_chain_register(&mce_injector_chain, nb);
}
void mce_unregister_injector_chain(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&mce_injector_chain, nb);
}
static ssize_t mce_chrdev_write(struct file *filp, const char __user *ubuf,
size_t usize, loff_t *off)
{
struct mce m;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!boot_cpu_has(X86_FEATURE_MCE) || !boot_cpu_has(X86_FEATURE_MCA))
return -EIO;
if ((unsigned long)usize > sizeof(struct mce))
usize = sizeof(struct mce);
if (copy_from_user(&m, ubuf, usize))
return -EFAULT;
if (m.extcpu >= num_possible_cpus() || !cpu_online(m.extcpu))
return -EINVAL;
schedule_timeout(2);
blocking_notifier_call_chain(&mce_injector_chain, 0, &m);
return usize;
}
static __init int dev_mcelog_init_device(void)
{
int err;
err = misc_register(&mce_chrdev_device);
if (err) {
if (err == -EBUSY)
pr_info("Unable to init device /dev/mcelog, already registered");
else
pr_err("Unable to init device /dev/mcelog (rc: %d)\n", err);
return err;
}
mce_register_decode_chain(&dev_mcelog_nb);
return 0;
}
