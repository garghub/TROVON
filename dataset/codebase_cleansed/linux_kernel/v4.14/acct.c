static int check_free_space(struct bsd_acct_struct *acct)
{
struct kstatfs sbuf;
if (time_is_before_jiffies(acct->needcheck))
goto out;
if (vfs_statfs(&acct->file->f_path, &sbuf))
goto out;
if (acct->active) {
u64 suspend = sbuf.f_blocks * SUSPEND;
do_div(suspend, 100);
if (sbuf.f_bavail <= suspend) {
acct->active = 0;
pr_info("Process accounting paused\n");
}
} else {
u64 resume = sbuf.f_blocks * RESUME;
do_div(resume, 100);
if (sbuf.f_bavail >= resume) {
acct->active = 1;
pr_info("Process accounting resumed\n");
}
}
acct->needcheck = jiffies + ACCT_TIMEOUT*HZ;
out:
return acct->active;
}
static void acct_put(struct bsd_acct_struct *p)
{
if (atomic_long_dec_and_test(&p->count))
kfree_rcu(p, rcu);
}
static inline struct bsd_acct_struct *to_acct(struct fs_pin *p)
{
return p ? container_of(p, struct bsd_acct_struct, pin) : NULL;
}
static struct bsd_acct_struct *acct_get(struct pid_namespace *ns)
{
struct bsd_acct_struct *res;
again:
smp_rmb();
rcu_read_lock();
res = to_acct(ACCESS_ONCE(ns->bacct));
if (!res) {
rcu_read_unlock();
return NULL;
}
if (!atomic_long_inc_not_zero(&res->count)) {
rcu_read_unlock();
cpu_relax();
goto again;
}
rcu_read_unlock();
mutex_lock(&res->lock);
if (res != to_acct(ACCESS_ONCE(ns->bacct))) {
mutex_unlock(&res->lock);
acct_put(res);
goto again;
}
return res;
}
static void acct_pin_kill(struct fs_pin *pin)
{
struct bsd_acct_struct *acct = to_acct(pin);
mutex_lock(&acct->lock);
do_acct_process(acct);
schedule_work(&acct->work);
wait_for_completion(&acct->done);
cmpxchg(&acct->ns->bacct, pin, NULL);
mutex_unlock(&acct->lock);
pin_remove(pin);
acct_put(acct);
}
static void close_work(struct work_struct *work)
{
struct bsd_acct_struct *acct = container_of(work, struct bsd_acct_struct, work);
struct file *file = acct->file;
if (file->f_op->flush)
file->f_op->flush(file, NULL);
__fput_sync(file);
complete(&acct->done);
}
static int acct_on(struct filename *pathname)
{
struct file *file;
struct vfsmount *mnt, *internal;
struct pid_namespace *ns = task_active_pid_ns(current);
struct bsd_acct_struct *acct;
struct fs_pin *old;
int err;
acct = kzalloc(sizeof(struct bsd_acct_struct), GFP_KERNEL);
if (!acct)
return -ENOMEM;
file = file_open_name(pathname, O_WRONLY|O_APPEND|O_LARGEFILE, 0);
if (IS_ERR(file)) {
kfree(acct);
return PTR_ERR(file);
}
if (!S_ISREG(file_inode(file)->i_mode)) {
kfree(acct);
filp_close(file, NULL);
return -EACCES;
}
if (!(file->f_mode & FMODE_CAN_WRITE)) {
kfree(acct);
filp_close(file, NULL);
return -EIO;
}
internal = mnt_clone_internal(&file->f_path);
if (IS_ERR(internal)) {
kfree(acct);
filp_close(file, NULL);
return PTR_ERR(internal);
}
err = mnt_want_write(internal);
if (err) {
mntput(internal);
kfree(acct);
filp_close(file, NULL);
return err;
}
mnt = file->f_path.mnt;
file->f_path.mnt = internal;
atomic_long_set(&acct->count, 1);
init_fs_pin(&acct->pin, acct_pin_kill);
acct->file = file;
acct->needcheck = jiffies;
acct->ns = ns;
mutex_init(&acct->lock);
INIT_WORK(&acct->work, close_work);
init_completion(&acct->done);
mutex_lock_nested(&acct->lock, 1);
pin_insert(&acct->pin, mnt);
rcu_read_lock();
old = xchg(&ns->bacct, &acct->pin);
mutex_unlock(&acct->lock);
pin_kill(old);
mnt_drop_write(mnt);
mntput(mnt);
return 0;
}
void acct_exit_ns(struct pid_namespace *ns)
{
rcu_read_lock();
pin_kill(ns->bacct);
}
static comp_t encode_comp_t(unsigned long value)
{
int exp, rnd;
exp = rnd = 0;
while (value > MAXFRACT) {
rnd = value & (1 << (EXPSIZE - 1));
value >>= EXPSIZE;
exp++;
}
if (rnd && (++value > MAXFRACT)) {
value >>= EXPSIZE;
exp++;
}
exp <<= MANTSIZE;
exp += value;
return exp;
}
static comp2_t encode_comp2_t(u64 value)
{
int exp, rnd;
exp = (value > (MAXFRACT2>>1));
rnd = 0;
while (value > MAXFRACT2) {
rnd = value & 1;
value >>= 1;
exp++;
}
if (rnd && (++value > MAXFRACT2)) {
value >>= 1;
exp++;
}
if (exp > MAXEXP2) {
return (1ul << (MANTSIZE2+EXPSIZE2-1)) - 1;
} else {
return (value & (MAXFRACT2>>1)) | (exp << (MANTSIZE2-1));
}
}
static u32 encode_float(u64 value)
{
unsigned exp = 190;
unsigned u;
if (value == 0)
return 0;
while ((s64)value > 0) {
value <<= 1;
exp--;
}
u = (u32)(value >> 40) & 0x7fffffu;
return u | (exp << 23);
}
static void fill_ac(acct_t *ac)
{
struct pacct_struct *pacct = &current->signal->pacct;
u64 elapsed, run_time;
struct tty_struct *tty;
memset(ac, 0, sizeof(acct_t));
ac->ac_version = ACCT_VERSION | ACCT_BYTEORDER;
strlcpy(ac->ac_comm, current->comm, sizeof(ac->ac_comm));
run_time = ktime_get_ns();
run_time -= current->group_leader->start_time;
elapsed = nsec_to_AHZ(run_time);
#if ACCT_VERSION == 3
ac->ac_etime = encode_float(elapsed);
#else
ac->ac_etime = encode_comp_t(elapsed < (unsigned long) -1l ?
(unsigned long) elapsed : (unsigned long) -1l);
#endif
#if ACCT_VERSION == 1 || ACCT_VERSION == 2
{
comp2_t etime = encode_comp2_t(elapsed);
ac->ac_etime_hi = etime >> 16;
ac->ac_etime_lo = (u16) etime;
}
#endif
do_div(elapsed, AHZ);
ac->ac_btime = get_seconds() - elapsed;
#if ACCT_VERSION==2
ac->ac_ahz = AHZ;
#endif
spin_lock_irq(&current->sighand->siglock);
tty = current->signal->tty;
ac->ac_tty = tty ? old_encode_dev(tty_devnum(tty)) : 0;
ac->ac_utime = encode_comp_t(nsec_to_AHZ(pacct->ac_utime));
ac->ac_stime = encode_comp_t(nsec_to_AHZ(pacct->ac_stime));
ac->ac_flag = pacct->ac_flag;
ac->ac_mem = encode_comp_t(pacct->ac_mem);
ac->ac_minflt = encode_comp_t(pacct->ac_minflt);
ac->ac_majflt = encode_comp_t(pacct->ac_majflt);
ac->ac_exitcode = pacct->ac_exitcode;
spin_unlock_irq(&current->sighand->siglock);
}
static void do_acct_process(struct bsd_acct_struct *acct)
{
acct_t ac;
unsigned long flim;
const struct cred *orig_cred;
struct file *file = acct->file;
flim = current->signal->rlim[RLIMIT_FSIZE].rlim_cur;
current->signal->rlim[RLIMIT_FSIZE].rlim_cur = RLIM_INFINITY;
orig_cred = override_creds(file->f_cred);
if (!check_free_space(acct))
goto out;
fill_ac(&ac);
ac.ac_uid = from_kuid_munged(file->f_cred->user_ns, orig_cred->uid);
ac.ac_gid = from_kgid_munged(file->f_cred->user_ns, orig_cred->gid);
#if ACCT_VERSION == 1 || ACCT_VERSION == 2
ac.ac_uid16 = ac.ac_uid;
ac.ac_gid16 = ac.ac_gid;
#endif
#if ACCT_VERSION == 3
{
struct pid_namespace *ns = acct->ns;
ac.ac_pid = task_tgid_nr_ns(current, ns);
rcu_read_lock();
ac.ac_ppid = task_tgid_nr_ns(rcu_dereference(current->real_parent),
ns);
rcu_read_unlock();
}
#endif
if (file_start_write_trylock(file)) {
loff_t pos = 0;
__kernel_write(file, &ac, sizeof(acct_t), &pos);
file_end_write(file);
}
out:
current->signal->rlim[RLIMIT_FSIZE].rlim_cur = flim;
revert_creds(orig_cred);
}
void acct_collect(long exitcode, int group_dead)
{
struct pacct_struct *pacct = &current->signal->pacct;
u64 utime, stime;
unsigned long vsize = 0;
if (group_dead && current->mm) {
struct vm_area_struct *vma;
down_read(&current->mm->mmap_sem);
vma = current->mm->mmap;
while (vma) {
vsize += vma->vm_end - vma->vm_start;
vma = vma->vm_next;
}
up_read(&current->mm->mmap_sem);
}
spin_lock_irq(&current->sighand->siglock);
if (group_dead)
pacct->ac_mem = vsize / 1024;
if (thread_group_leader(current)) {
pacct->ac_exitcode = exitcode;
if (current->flags & PF_FORKNOEXEC)
pacct->ac_flag |= AFORK;
}
if (current->flags & PF_SUPERPRIV)
pacct->ac_flag |= ASU;
if (current->flags & PF_DUMPCORE)
pacct->ac_flag |= ACORE;
if (current->flags & PF_SIGNALED)
pacct->ac_flag |= AXSIG;
task_cputime(current, &utime, &stime);
pacct->ac_utime += utime;
pacct->ac_stime += stime;
pacct->ac_minflt += current->min_flt;
pacct->ac_majflt += current->maj_flt;
spin_unlock_irq(&current->sighand->siglock);
}
static void slow_acct_process(struct pid_namespace *ns)
{
for ( ; ns; ns = ns->parent) {
struct bsd_acct_struct *acct = acct_get(ns);
if (acct) {
do_acct_process(acct);
mutex_unlock(&acct->lock);
acct_put(acct);
}
}
}
void acct_process(void)
{
struct pid_namespace *ns;
for (ns = task_active_pid_ns(current); ns != NULL; ns = ns->parent) {
if (ns->bacct)
break;
}
if (unlikely(ns))
slow_acct_process(ns);
}
