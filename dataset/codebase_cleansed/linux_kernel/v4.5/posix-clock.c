static struct posix_clock *get_posix_clock(struct file *fp)
{
struct posix_clock *clk = fp->private_data;
down_read(&clk->rwsem);
if (!clk->zombie)
return clk;
up_read(&clk->rwsem);
return NULL;
}
static void put_posix_clock(struct posix_clock *clk)
{
up_read(&clk->rwsem);
}
static ssize_t posix_clock_read(struct file *fp, char __user *buf,
size_t count, loff_t *ppos)
{
struct posix_clock *clk = get_posix_clock(fp);
int err = -EINVAL;
if (!clk)
return -ENODEV;
if (clk->ops.read)
err = clk->ops.read(clk, fp->f_flags, buf, count);
put_posix_clock(clk);
return err;
}
static unsigned int posix_clock_poll(struct file *fp, poll_table *wait)
{
struct posix_clock *clk = get_posix_clock(fp);
unsigned int result = 0;
if (!clk)
return POLLERR;
if (clk->ops.poll)
result = clk->ops.poll(clk, fp, wait);
put_posix_clock(clk);
return result;
}
static int posix_clock_fasync(int fd, struct file *fp, int on)
{
struct posix_clock *clk = get_posix_clock(fp);
int err = 0;
if (!clk)
return -ENODEV;
if (clk->ops.fasync)
err = clk->ops.fasync(clk, fd, fp, on);
put_posix_clock(clk);
return err;
}
static int posix_clock_mmap(struct file *fp, struct vm_area_struct *vma)
{
struct posix_clock *clk = get_posix_clock(fp);
int err = -ENODEV;
if (!clk)
return -ENODEV;
if (clk->ops.mmap)
err = clk->ops.mmap(clk, vma);
put_posix_clock(clk);
return err;
}
static long posix_clock_ioctl(struct file *fp,
unsigned int cmd, unsigned long arg)
{
struct posix_clock *clk = get_posix_clock(fp);
int err = -ENOTTY;
if (!clk)
return -ENODEV;
if (clk->ops.ioctl)
err = clk->ops.ioctl(clk, cmd, arg);
put_posix_clock(clk);
return err;
}
static long posix_clock_compat_ioctl(struct file *fp,
unsigned int cmd, unsigned long arg)
{
struct posix_clock *clk = get_posix_clock(fp);
int err = -ENOTTY;
if (!clk)
return -ENODEV;
if (clk->ops.ioctl)
err = clk->ops.ioctl(clk, cmd, arg);
put_posix_clock(clk);
return err;
}
static int posix_clock_open(struct inode *inode, struct file *fp)
{
int err;
struct posix_clock *clk =
container_of(inode->i_cdev, struct posix_clock, cdev);
down_read(&clk->rwsem);
if (clk->zombie) {
err = -ENODEV;
goto out;
}
if (clk->ops.open)
err = clk->ops.open(clk, fp->f_mode);
else
err = 0;
if (!err) {
kref_get(&clk->kref);
fp->private_data = clk;
}
out:
up_read(&clk->rwsem);
return err;
}
static int posix_clock_release(struct inode *inode, struct file *fp)
{
struct posix_clock *clk = fp->private_data;
int err = 0;
if (clk->ops.release)
err = clk->ops.release(clk);
kref_put(&clk->kref, delete_clock);
fp->private_data = NULL;
return err;
}
int posix_clock_register(struct posix_clock *clk, dev_t devid)
{
int err;
kref_init(&clk->kref);
init_rwsem(&clk->rwsem);
cdev_init(&clk->cdev, &posix_clock_file_operations);
clk->cdev.owner = clk->ops.owner;
err = cdev_add(&clk->cdev, devid, 1);
return err;
}
static void delete_clock(struct kref *kref)
{
struct posix_clock *clk = container_of(kref, struct posix_clock, kref);
if (clk->release)
clk->release(clk);
}
void posix_clock_unregister(struct posix_clock *clk)
{
cdev_del(&clk->cdev);
down_write(&clk->rwsem);
clk->zombie = true;
up_write(&clk->rwsem);
kref_put(&clk->kref, delete_clock);
}
static int get_clock_desc(const clockid_t id, struct posix_clock_desc *cd)
{
struct file *fp = fget(CLOCKID_TO_FD(id));
int err = -EINVAL;
if (!fp)
return err;
if (fp->f_op->open != posix_clock_open || !fp->private_data)
goto out;
cd->fp = fp;
cd->clk = get_posix_clock(fp);
err = cd->clk ? 0 : -ENODEV;
out:
if (err)
fput(fp);
return err;
}
static void put_clock_desc(struct posix_clock_desc *cd)
{
put_posix_clock(cd->clk);
fput(cd->fp);
}
static int pc_clock_adjtime(clockid_t id, struct timex *tx)
{
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if ((cd.fp->f_mode & FMODE_WRITE) == 0) {
err = -EACCES;
goto out;
}
if (cd.clk->ops.clock_adjtime)
err = cd.clk->ops.clock_adjtime(cd.clk, tx);
else
err = -EOPNOTSUPP;
out:
put_clock_desc(&cd);
return err;
}
static int pc_clock_gettime(clockid_t id, struct timespec *ts)
{
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if (cd.clk->ops.clock_gettime)
err = cd.clk->ops.clock_gettime(cd.clk, ts);
else
err = -EOPNOTSUPP;
put_clock_desc(&cd);
return err;
}
static int pc_clock_getres(clockid_t id, struct timespec *ts)
{
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if (cd.clk->ops.clock_getres)
err = cd.clk->ops.clock_getres(cd.clk, ts);
else
err = -EOPNOTSUPP;
put_clock_desc(&cd);
return err;
}
static int pc_clock_settime(clockid_t id, const struct timespec *ts)
{
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if ((cd.fp->f_mode & FMODE_WRITE) == 0) {
err = -EACCES;
goto out;
}
if (cd.clk->ops.clock_settime)
err = cd.clk->ops.clock_settime(cd.clk, ts);
else
err = -EOPNOTSUPP;
out:
put_clock_desc(&cd);
return err;
}
static int pc_timer_create(struct k_itimer *kit)
{
clockid_t id = kit->it_clock;
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if (cd.clk->ops.timer_create)
err = cd.clk->ops.timer_create(cd.clk, kit);
else
err = -EOPNOTSUPP;
put_clock_desc(&cd);
return err;
}
static int pc_timer_delete(struct k_itimer *kit)
{
clockid_t id = kit->it_clock;
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if (cd.clk->ops.timer_delete)
err = cd.clk->ops.timer_delete(cd.clk, kit);
else
err = -EOPNOTSUPP;
put_clock_desc(&cd);
return err;
}
static void pc_timer_gettime(struct k_itimer *kit, struct itimerspec *ts)
{
clockid_t id = kit->it_clock;
struct posix_clock_desc cd;
if (get_clock_desc(id, &cd))
return;
if (cd.clk->ops.timer_gettime)
cd.clk->ops.timer_gettime(cd.clk, kit, ts);
put_clock_desc(&cd);
}
static int pc_timer_settime(struct k_itimer *kit, int flags,
struct itimerspec *ts, struct itimerspec *old)
{
clockid_t id = kit->it_clock;
struct posix_clock_desc cd;
int err;
err = get_clock_desc(id, &cd);
if (err)
return err;
if (cd.clk->ops.timer_settime)
err = cd.clk->ops.timer_settime(cd.clk, kit, flags, ts, old);
else
err = -EOPNOTSUPP;
put_clock_desc(&cd);
return err;
}
