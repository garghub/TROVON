static bool lease_breaking(struct file_lock *fl)
{
return fl->fl_flags & (FL_UNLOCK_PENDING | FL_DOWNGRADE_PENDING);
}
static int target_leasetype(struct file_lock *fl)
{
if (fl->fl_flags & FL_UNLOCK_PENDING)
return F_UNLCK;
if (fl->fl_flags & FL_DOWNGRADE_PENDING)
return F_RDLCK;
return fl->fl_type;
}
static void locks_init_lock_heads(struct file_lock *fl)
{
INIT_HLIST_NODE(&fl->fl_link);
INIT_LIST_HEAD(&fl->fl_block);
init_waitqueue_head(&fl->fl_wait);
}
struct file_lock *locks_alloc_lock(void)
{
struct file_lock *fl = kmem_cache_zalloc(filelock_cache, GFP_KERNEL);
if (fl)
locks_init_lock_heads(fl);
return fl;
}
void locks_release_private(struct file_lock *fl)
{
if (fl->fl_ops) {
if (fl->fl_ops->fl_release_private)
fl->fl_ops->fl_release_private(fl);
fl->fl_ops = NULL;
}
if (fl->fl_lmops) {
if (fl->fl_lmops->lm_put_owner)
fl->fl_lmops->lm_put_owner(fl);
fl->fl_lmops = NULL;
}
}
void locks_free_lock(struct file_lock *fl)
{
BUG_ON(waitqueue_active(&fl->fl_wait));
BUG_ON(!list_empty(&fl->fl_block));
BUG_ON(!hlist_unhashed(&fl->fl_link));
locks_release_private(fl);
kmem_cache_free(filelock_cache, fl);
}
static void
locks_dispose_list(struct list_head *dispose)
{
struct file_lock *fl;
while (!list_empty(dispose)) {
fl = list_first_entry(dispose, struct file_lock, fl_block);
list_del_init(&fl->fl_block);
locks_free_lock(fl);
}
}
void locks_init_lock(struct file_lock *fl)
{
memset(fl, 0, sizeof(struct file_lock));
locks_init_lock_heads(fl);
}
void locks_copy_conflock(struct file_lock *new, struct file_lock *fl)
{
new->fl_owner = fl->fl_owner;
new->fl_pid = fl->fl_pid;
new->fl_file = NULL;
new->fl_flags = fl->fl_flags;
new->fl_type = fl->fl_type;
new->fl_start = fl->fl_start;
new->fl_end = fl->fl_end;
new->fl_lmops = fl->fl_lmops;
new->fl_ops = NULL;
if (fl->fl_lmops) {
if (fl->fl_lmops->lm_get_owner)
fl->fl_lmops->lm_get_owner(new, fl);
}
}
void locks_copy_lock(struct file_lock *new, struct file_lock *fl)
{
WARN_ON_ONCE(new->fl_ops);
locks_copy_conflock(new, fl);
new->fl_file = fl->fl_file;
new->fl_ops = fl->fl_ops;
if (fl->fl_ops) {
if (fl->fl_ops->fl_copy_lock)
fl->fl_ops->fl_copy_lock(new, fl);
}
}
static inline int flock_translate_cmd(int cmd) {
if (cmd & LOCK_MAND)
return cmd & (LOCK_MAND | LOCK_RW);
switch (cmd) {
case LOCK_SH:
return F_RDLCK;
case LOCK_EX:
return F_WRLCK;
case LOCK_UN:
return F_UNLCK;
}
return -EINVAL;
}
static struct file_lock *
flock_make_lock(struct file *filp, unsigned int cmd)
{
struct file_lock *fl;
int type = flock_translate_cmd(cmd);
if (type < 0)
return ERR_PTR(type);
fl = locks_alloc_lock();
if (fl == NULL)
return ERR_PTR(-ENOMEM);
fl->fl_file = filp;
fl->fl_owner = filp;
fl->fl_pid = current->tgid;
fl->fl_flags = FL_FLOCK;
fl->fl_type = type;
fl->fl_end = OFFSET_MAX;
return fl;
}
static int assign_type(struct file_lock *fl, long type)
{
switch (type) {
case F_RDLCK:
case F_WRLCK:
case F_UNLCK:
fl->fl_type = type;
break;
default:
return -EINVAL;
}
return 0;
}
static int flock64_to_posix_lock(struct file *filp, struct file_lock *fl,
struct flock64 *l)
{
switch (l->l_whence) {
case SEEK_SET:
fl->fl_start = 0;
break;
case SEEK_CUR:
fl->fl_start = filp->f_pos;
break;
case SEEK_END:
fl->fl_start = i_size_read(file_inode(filp));
break;
default:
return -EINVAL;
}
if (l->l_start > OFFSET_MAX - fl->fl_start)
return -EOVERFLOW;
fl->fl_start += l->l_start;
if (fl->fl_start < 0)
return -EINVAL;
if (l->l_len > 0) {
if (l->l_len - 1 > OFFSET_MAX - fl->fl_start)
return -EOVERFLOW;
fl->fl_end = fl->fl_start + l->l_len - 1;
} else if (l->l_len < 0) {
if (fl->fl_start + l->l_len < 0)
return -EINVAL;
fl->fl_end = fl->fl_start - 1;
fl->fl_start += l->l_len;
} else
fl->fl_end = OFFSET_MAX;
fl->fl_owner = current->files;
fl->fl_pid = current->tgid;
fl->fl_file = filp;
fl->fl_flags = FL_POSIX;
fl->fl_ops = NULL;
fl->fl_lmops = NULL;
return assign_type(fl, l->l_type);
}
static int flock_to_posix_lock(struct file *filp, struct file_lock *fl,
struct flock *l)
{
struct flock64 ll = {
.l_type = l->l_type,
.l_whence = l->l_whence,
.l_start = l->l_start,
.l_len = l->l_len,
};
return flock64_to_posix_lock(filp, fl, &ll);
}
static bool
lease_break_callback(struct file_lock *fl)
{
kill_fasync(&fl->fl_fasync, SIGIO, POLL_MSG);
return false;
}
static void
lease_setup(struct file_lock *fl, void **priv)
{
struct file *filp = fl->fl_file;
struct fasync_struct *fa = *priv;
if (!fasync_insert_entry(fa->fa_fd, filp, &fl->fl_fasync, fa))
*priv = NULL;
__f_setown(filp, task_pid(current), PIDTYPE_PID, 0);
}
static int lease_init(struct file *filp, long type, struct file_lock *fl)
{
if (assign_type(fl, type) != 0)
return -EINVAL;
fl->fl_owner = filp;
fl->fl_pid = current->tgid;
fl->fl_file = filp;
fl->fl_flags = FL_LEASE;
fl->fl_start = 0;
fl->fl_end = OFFSET_MAX;
fl->fl_ops = NULL;
fl->fl_lmops = &lease_manager_ops;
return 0;
}
static struct file_lock *lease_alloc(struct file *filp, long type)
{
struct file_lock *fl = locks_alloc_lock();
int error = -ENOMEM;
if (fl == NULL)
return ERR_PTR(error);
error = lease_init(filp, type, fl);
if (error) {
locks_free_lock(fl);
return ERR_PTR(error);
}
return fl;
}
static inline int locks_overlap(struct file_lock *fl1, struct file_lock *fl2)
{
return ((fl1->fl_end >= fl2->fl_start) &&
(fl2->fl_end >= fl1->fl_start));
}
static int posix_same_owner(struct file_lock *fl1, struct file_lock *fl2)
{
if (fl1->fl_lmops && fl1->fl_lmops->lm_compare_owner)
return fl2->fl_lmops == fl1->fl_lmops &&
fl1->fl_lmops->lm_compare_owner(fl1, fl2);
return fl1->fl_owner == fl2->fl_owner;
}
static void locks_insert_global_locks(struct file_lock *fl)
{
lg_local_lock(&file_lock_lglock);
fl->fl_link_cpu = smp_processor_id();
hlist_add_head(&fl->fl_link, this_cpu_ptr(&file_lock_list));
lg_local_unlock(&file_lock_lglock);
}
static void locks_delete_global_locks(struct file_lock *fl)
{
if (hlist_unhashed(&fl->fl_link))
return;
lg_local_lock_cpu(&file_lock_lglock, fl->fl_link_cpu);
hlist_del_init(&fl->fl_link);
lg_local_unlock_cpu(&file_lock_lglock, fl->fl_link_cpu);
}
static unsigned long
posix_owner_key(struct file_lock *fl)
{
if (fl->fl_lmops && fl->fl_lmops->lm_owner_key)
return fl->fl_lmops->lm_owner_key(fl);
return (unsigned long)fl->fl_owner;
}
static void locks_insert_global_blocked(struct file_lock *waiter)
{
hash_add(blocked_hash, &waiter->fl_link, posix_owner_key(waiter));
}
static void locks_delete_global_blocked(struct file_lock *waiter)
{
hash_del(&waiter->fl_link);
}
static void __locks_delete_block(struct file_lock *waiter)
{
locks_delete_global_blocked(waiter);
list_del_init(&waiter->fl_block);
waiter->fl_next = NULL;
}
static void locks_delete_block(struct file_lock *waiter)
{
spin_lock(&blocked_lock_lock);
__locks_delete_block(waiter);
spin_unlock(&blocked_lock_lock);
}
static void __locks_insert_block(struct file_lock *blocker,
struct file_lock *waiter)
{
BUG_ON(!list_empty(&waiter->fl_block));
waiter->fl_next = blocker;
list_add_tail(&waiter->fl_block, &blocker->fl_block);
if (IS_POSIX(blocker) && !IS_OFDLCK(blocker))
locks_insert_global_blocked(waiter);
}
static void locks_insert_block(struct file_lock *blocker,
struct file_lock *waiter)
{
spin_lock(&blocked_lock_lock);
__locks_insert_block(blocker, waiter);
spin_unlock(&blocked_lock_lock);
}
static void locks_wake_up_blocks(struct file_lock *blocker)
{
if (list_empty(&blocker->fl_block))
return;
spin_lock(&blocked_lock_lock);
while (!list_empty(&blocker->fl_block)) {
struct file_lock *waiter;
waiter = list_first_entry(&blocker->fl_block,
struct file_lock, fl_block);
__locks_delete_block(waiter);
if (waiter->fl_lmops && waiter->fl_lmops->lm_notify)
waiter->fl_lmops->lm_notify(waiter);
else
wake_up(&waiter->fl_wait);
}
spin_unlock(&blocked_lock_lock);
}
static void locks_insert_lock(struct file_lock **pos, struct file_lock *fl)
{
fl->fl_nspid = get_pid(task_tgid(current));
fl->fl_next = *pos;
*pos = fl;
locks_insert_global_locks(fl);
}
static void locks_unlink_lock(struct file_lock **thisfl_p)
{
struct file_lock *fl = *thisfl_p;
locks_delete_global_locks(fl);
*thisfl_p = fl->fl_next;
fl->fl_next = NULL;
if (fl->fl_nspid) {
put_pid(fl->fl_nspid);
fl->fl_nspid = NULL;
}
locks_wake_up_blocks(fl);
}
static void locks_delete_lock(struct file_lock **thisfl_p,
struct list_head *dispose)
{
struct file_lock *fl = *thisfl_p;
locks_unlink_lock(thisfl_p);
if (dispose)
list_add(&fl->fl_block, dispose);
else
locks_free_lock(fl);
}
static int locks_conflict(struct file_lock *caller_fl, struct file_lock *sys_fl)
{
if (sys_fl->fl_type == F_WRLCK)
return 1;
if (caller_fl->fl_type == F_WRLCK)
return 1;
return 0;
}
static int posix_locks_conflict(struct file_lock *caller_fl, struct file_lock *sys_fl)
{
if (!IS_POSIX(sys_fl) || posix_same_owner(caller_fl, sys_fl))
return (0);
if (!locks_overlap(caller_fl, sys_fl))
return 0;
return (locks_conflict(caller_fl, sys_fl));
}
static int flock_locks_conflict(struct file_lock *caller_fl, struct file_lock *sys_fl)
{
if (!IS_FLOCK(sys_fl) || (caller_fl->fl_file == sys_fl->fl_file))
return (0);
if ((caller_fl->fl_type & LOCK_MAND) || (sys_fl->fl_type & LOCK_MAND))
return 0;
return (locks_conflict(caller_fl, sys_fl));
}
void
posix_test_lock(struct file *filp, struct file_lock *fl)
{
struct file_lock *cfl;
struct inode *inode = file_inode(filp);
spin_lock(&inode->i_lock);
for (cfl = file_inode(filp)->i_flock; cfl; cfl = cfl->fl_next) {
if (!IS_POSIX(cfl))
continue;
if (posix_locks_conflict(fl, cfl))
break;
}
if (cfl) {
locks_copy_conflock(fl, cfl);
if (cfl->fl_nspid)
fl->fl_pid = pid_vnr(cfl->fl_nspid);
} else
fl->fl_type = F_UNLCK;
spin_unlock(&inode->i_lock);
return;
}
static struct file_lock *what_owner_is_waiting_for(struct file_lock *block_fl)
{
struct file_lock *fl;
hash_for_each_possible(blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if (posix_same_owner(fl, block_fl))
return fl->fl_next;
}
return NULL;
}
static int posix_locks_deadlock(struct file_lock *caller_fl,
struct file_lock *block_fl)
{
int i = 0;
if (IS_OFDLCK(caller_fl))
return 0;
while ((block_fl = what_owner_is_waiting_for(block_fl))) {
if (i++ > MAX_DEADLK_ITERATIONS)
return 0;
if (posix_same_owner(caller_fl, block_fl))
return 1;
}
return 0;
}
static int flock_lock_file(struct file *filp, struct file_lock *request)
{
struct file_lock *new_fl = NULL;
struct file_lock **before;
struct inode * inode = file_inode(filp);
int error = 0;
int found = 0;
LIST_HEAD(dispose);
if (!(request->fl_flags & FL_ACCESS) && (request->fl_type != F_UNLCK)) {
new_fl = locks_alloc_lock();
if (!new_fl)
return -ENOMEM;
}
spin_lock(&inode->i_lock);
if (request->fl_flags & FL_ACCESS)
goto find_conflict;
for_each_lock(inode, before) {
struct file_lock *fl = *before;
if (IS_POSIX(fl))
break;
if (IS_LEASE(fl))
continue;
if (filp != fl->fl_file)
continue;
if (request->fl_type == fl->fl_type)
goto out;
found = 1;
locks_delete_lock(before, &dispose);
break;
}
if (request->fl_type == F_UNLCK) {
if ((request->fl_flags & FL_EXISTS) && !found)
error = -ENOENT;
goto out;
}
if (found) {
spin_unlock(&inode->i_lock);
cond_resched();
spin_lock(&inode->i_lock);
}
find_conflict:
for_each_lock(inode, before) {
struct file_lock *fl = *before;
if (IS_POSIX(fl))
break;
if (IS_LEASE(fl))
continue;
if (!flock_locks_conflict(request, fl))
continue;
error = -EAGAIN;
if (!(request->fl_flags & FL_SLEEP))
goto out;
error = FILE_LOCK_DEFERRED;
locks_insert_block(fl, request);
goto out;
}
if (request->fl_flags & FL_ACCESS)
goto out;
locks_copy_lock(new_fl, request);
locks_insert_lock(before, new_fl);
new_fl = NULL;
error = 0;
out:
spin_unlock(&inode->i_lock);
if (new_fl)
locks_free_lock(new_fl);
locks_dispose_list(&dispose);
return error;
}
static int __posix_lock_file(struct inode *inode, struct file_lock *request, struct file_lock *conflock)
{
struct file_lock *fl;
struct file_lock *new_fl = NULL;
struct file_lock *new_fl2 = NULL;
struct file_lock *left = NULL;
struct file_lock *right = NULL;
struct file_lock **before;
int error;
bool added = false;
LIST_HEAD(dispose);
if (!(request->fl_flags & FL_ACCESS) &&
(request->fl_type != F_UNLCK ||
request->fl_start != 0 || request->fl_end != OFFSET_MAX)) {
new_fl = locks_alloc_lock();
new_fl2 = locks_alloc_lock();
}
spin_lock(&inode->i_lock);
if (request->fl_type != F_UNLCK) {
for_each_lock(inode, before) {
fl = *before;
if (!IS_POSIX(fl))
continue;
if (!posix_locks_conflict(request, fl))
continue;
if (conflock)
locks_copy_conflock(conflock, fl);
error = -EAGAIN;
if (!(request->fl_flags & FL_SLEEP))
goto out;
error = -EDEADLK;
spin_lock(&blocked_lock_lock);
if (likely(!posix_locks_deadlock(request, fl))) {
error = FILE_LOCK_DEFERRED;
__locks_insert_block(fl, request);
}
spin_unlock(&blocked_lock_lock);
goto out;
}
}
error = 0;
if (request->fl_flags & FL_ACCESS)
goto out;
before = &inode->i_flock;
while ((fl = *before) && (!IS_POSIX(fl) ||
!posix_same_owner(request, fl))) {
before = &fl->fl_next;
}
while ((fl = *before) && posix_same_owner(request, fl)) {
if (request->fl_type == fl->fl_type) {
if (fl->fl_end < request->fl_start - 1)
goto next_lock;
if (fl->fl_start - 1 > request->fl_end)
break;
if (fl->fl_start > request->fl_start)
fl->fl_start = request->fl_start;
else
request->fl_start = fl->fl_start;
if (fl->fl_end < request->fl_end)
fl->fl_end = request->fl_end;
else
request->fl_end = fl->fl_end;
if (added) {
locks_delete_lock(before, &dispose);
continue;
}
request = fl;
added = true;
}
else {
if (fl->fl_end < request->fl_start)
goto next_lock;
if (fl->fl_start > request->fl_end)
break;
if (request->fl_type == F_UNLCK)
added = true;
if (fl->fl_start < request->fl_start)
left = fl;
if (fl->fl_end > request->fl_end) {
right = fl;
break;
}
if (fl->fl_start >= request->fl_start) {
if (added) {
locks_delete_lock(before, &dispose);
continue;
}
error = -ENOLCK;
if (!new_fl)
goto out;
locks_copy_lock(new_fl, request);
request = new_fl;
new_fl = NULL;
locks_delete_lock(before, &dispose);
locks_insert_lock(before, request);
added = true;
}
}
next_lock:
before = &fl->fl_next;
}
error = -ENOLCK;
if (right && left == right && !new_fl2)
goto out;
error = 0;
if (!added) {
if (request->fl_type == F_UNLCK) {
if (request->fl_flags & FL_EXISTS)
error = -ENOENT;
goto out;
}
if (!new_fl) {
error = -ENOLCK;
goto out;
}
locks_copy_lock(new_fl, request);
locks_insert_lock(before, new_fl);
new_fl = NULL;
}
if (right) {
if (left == right) {
left = new_fl2;
new_fl2 = NULL;
locks_copy_lock(left, right);
locks_insert_lock(before, left);
}
right->fl_start = request->fl_end + 1;
locks_wake_up_blocks(right);
}
if (left) {
left->fl_end = request->fl_start - 1;
locks_wake_up_blocks(left);
}
out:
spin_unlock(&inode->i_lock);
if (new_fl)
locks_free_lock(new_fl);
if (new_fl2)
locks_free_lock(new_fl2);
locks_dispose_list(&dispose);
return error;
}
int posix_lock_file(struct file *filp, struct file_lock *fl,
struct file_lock *conflock)
{
return __posix_lock_file(file_inode(filp), fl, conflock);
}
int posix_lock_file_wait(struct file *filp, struct file_lock *fl)
{
int error;
might_sleep ();
for (;;) {
error = posix_lock_file(filp, fl, NULL);
if (error != FILE_LOCK_DEFERRED)
break;
error = wait_event_interruptible(fl->fl_wait, !fl->fl_next);
if (!error)
continue;
locks_delete_block(fl);
break;
}
return error;
}
int locks_mandatory_locked(struct file *file)
{
struct inode *inode = file_inode(file);
struct file_lock *fl;
spin_lock(&inode->i_lock);
for (fl = inode->i_flock; fl != NULL; fl = fl->fl_next) {
if (!IS_POSIX(fl))
continue;
if (fl->fl_owner != current->files &&
fl->fl_owner != file)
break;
}
spin_unlock(&inode->i_lock);
return fl ? -EAGAIN : 0;
}
int locks_mandatory_area(int read_write, struct inode *inode,
struct file *filp, loff_t offset,
size_t count)
{
struct file_lock fl;
int error;
bool sleep = false;
locks_init_lock(&fl);
fl.fl_pid = current->tgid;
fl.fl_file = filp;
fl.fl_flags = FL_POSIX | FL_ACCESS;
if (filp && !(filp->f_flags & O_NONBLOCK))
sleep = true;
fl.fl_type = (read_write == FLOCK_VERIFY_WRITE) ? F_WRLCK : F_RDLCK;
fl.fl_start = offset;
fl.fl_end = offset + count - 1;
for (;;) {
if (filp) {
fl.fl_owner = filp;
fl.fl_flags &= ~FL_SLEEP;
error = __posix_lock_file(inode, &fl, NULL);
if (!error)
break;
}
if (sleep)
fl.fl_flags |= FL_SLEEP;
fl.fl_owner = current->files;
error = __posix_lock_file(inode, &fl, NULL);
if (error != FILE_LOCK_DEFERRED)
break;
error = wait_event_interruptible(fl.fl_wait, !fl.fl_next);
if (!error) {
if (__mandatory_lock(inode))
continue;
}
locks_delete_block(&fl);
break;
}
return error;
}
static void lease_clear_pending(struct file_lock *fl, int arg)
{
switch (arg) {
case F_UNLCK:
fl->fl_flags &= ~FL_UNLOCK_PENDING;
case F_RDLCK:
fl->fl_flags &= ~FL_DOWNGRADE_PENDING;
}
}
int lease_modify(struct file_lock **before, int arg, struct list_head *dispose)
{
struct file_lock *fl = *before;
int error = assign_type(fl, arg);
if (error)
return error;
lease_clear_pending(fl, arg);
locks_wake_up_blocks(fl);
if (arg == F_UNLCK) {
struct file *filp = fl->fl_file;
f_delown(filp);
filp->f_owner.signum = 0;
fasync_helper(0, fl->fl_file, 0, &fl->fl_fasync);
if (fl->fl_fasync != NULL) {
printk(KERN_ERR "locks_delete_lock: fasync == %p\n", fl->fl_fasync);
fl->fl_fasync = NULL;
}
locks_delete_lock(before, dispose);
}
return 0;
}
static bool past_time(unsigned long then)
{
if (!then)
return false;
return time_after(jiffies, then);
}
static void time_out_leases(struct inode *inode, struct list_head *dispose)
{
struct file_lock **before;
struct file_lock *fl;
lockdep_assert_held(&inode->i_lock);
before = &inode->i_flock;
while ((fl = *before) && IS_LEASE(fl) && lease_breaking(fl)) {
trace_time_out_leases(inode, fl);
if (past_time(fl->fl_downgrade_time))
lease_modify(before, F_RDLCK, dispose);
if (past_time(fl->fl_break_time))
lease_modify(before, F_UNLCK, dispose);
if (fl == *before)
before = &fl->fl_next;
}
}
static bool leases_conflict(struct file_lock *lease, struct file_lock *breaker)
{
if ((breaker->fl_flags & FL_DELEG) && (lease->fl_flags & FL_LEASE))
return false;
return locks_conflict(breaker, lease);
}
static bool
any_leases_conflict(struct inode *inode, struct file_lock *breaker)
{
struct file_lock *fl;
lockdep_assert_held(&inode->i_lock);
for (fl = inode->i_flock ; fl && IS_LEASE(fl); fl = fl->fl_next) {
if (leases_conflict(fl, breaker))
return true;
}
return false;
}
int __break_lease(struct inode *inode, unsigned int mode, unsigned int type)
{
int error = 0;
struct file_lock *new_fl;
struct file_lock *fl, **before;
unsigned long break_time;
int want_write = (mode & O_ACCMODE) != O_RDONLY;
LIST_HEAD(dispose);
new_fl = lease_alloc(NULL, want_write ? F_WRLCK : F_RDLCK);
if (IS_ERR(new_fl))
return PTR_ERR(new_fl);
new_fl->fl_flags = type;
spin_lock(&inode->i_lock);
time_out_leases(inode, &dispose);
if (!any_leases_conflict(inode, new_fl))
goto out;
break_time = 0;
if (lease_break_time > 0) {
break_time = jiffies + lease_break_time * HZ;
if (break_time == 0)
break_time++;
}
for (before = &inode->i_flock;
((fl = *before) != NULL) && IS_LEASE(fl);
before = &fl->fl_next) {
if (!leases_conflict(fl, new_fl))
continue;
if (want_write) {
if (fl->fl_flags & FL_UNLOCK_PENDING)
continue;
fl->fl_flags |= FL_UNLOCK_PENDING;
fl->fl_break_time = break_time;
} else {
if (lease_breaking(inode->i_flock))
continue;
fl->fl_flags |= FL_DOWNGRADE_PENDING;
fl->fl_downgrade_time = break_time;
}
if (fl->fl_lmops->lm_break(fl))
locks_delete_lock(before, &dispose);
}
fl = inode->i_flock;
if (!fl || !IS_LEASE(fl))
goto out;
if (mode & O_NONBLOCK) {
trace_break_lease_noblock(inode, new_fl);
error = -EWOULDBLOCK;
goto out;
}
restart:
break_time = inode->i_flock->fl_break_time;
if (break_time != 0)
break_time -= jiffies;
if (break_time == 0)
break_time++;
locks_insert_block(inode->i_flock, new_fl);
trace_break_lease_block(inode, new_fl);
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
error = wait_event_interruptible_timeout(new_fl->fl_wait,
!new_fl->fl_next, break_time);
spin_lock(&inode->i_lock);
trace_break_lease_unblock(inode, new_fl);
locks_delete_block(new_fl);
if (error >= 0) {
if (error == 0)
time_out_leases(inode, &dispose);
if (any_leases_conflict(inode, new_fl))
goto restart;
error = 0;
}
out:
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
locks_free_lock(new_fl);
return error;
}
void lease_get_mtime(struct inode *inode, struct timespec *time)
{
bool has_lease = false;
struct file_lock *flock;
if (inode->i_flock) {
spin_lock(&inode->i_lock);
flock = inode->i_flock;
if (flock && IS_LEASE(flock) && (flock->fl_type == F_WRLCK))
has_lease = true;
spin_unlock(&inode->i_lock);
}
if (has_lease)
*time = current_fs_time(inode->i_sb);
else
*time = inode->i_mtime;
}
int fcntl_getlease(struct file *filp)
{
struct file_lock *fl;
struct inode *inode = file_inode(filp);
int type = F_UNLCK;
LIST_HEAD(dispose);
spin_lock(&inode->i_lock);
time_out_leases(file_inode(filp), &dispose);
for (fl = file_inode(filp)->i_flock; fl && IS_LEASE(fl);
fl = fl->fl_next) {
if (fl->fl_file == filp) {
type = target_leasetype(fl);
break;
}
}
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
return type;
}
static int
check_conflicting_open(const struct dentry *dentry, const long arg)
{
int ret = 0;
struct inode *inode = dentry->d_inode;
if ((arg == F_RDLCK) && (atomic_read(&inode->i_writecount) > 0))
return -EAGAIN;
if ((arg == F_WRLCK) && ((d_count(dentry) > 1) ||
(atomic_read(&inode->i_count) > 1)))
ret = -EAGAIN;
return ret;
}
static int
generic_add_lease(struct file *filp, long arg, struct file_lock **flp, void **priv)
{
struct file_lock *fl, **before, **my_before = NULL, *lease;
struct dentry *dentry = filp->f_path.dentry;
struct inode *inode = dentry->d_inode;
bool is_deleg = (*flp)->fl_flags & FL_DELEG;
int error;
LIST_HEAD(dispose);
lease = *flp;
trace_generic_add_lease(inode, lease);
if (is_deleg && !mutex_trylock(&inode->i_mutex))
return -EAGAIN;
if (is_deleg && arg == F_WRLCK) {
mutex_unlock(&inode->i_mutex);
WARN_ON_ONCE(1);
return -EINVAL;
}
spin_lock(&inode->i_lock);
time_out_leases(inode, &dispose);
error = check_conflicting_open(dentry, arg);
if (error)
goto out;
error = -EAGAIN;
for (before = &inode->i_flock;
((fl = *before) != NULL) && IS_LEASE(fl);
before = &fl->fl_next) {
if (fl->fl_file == filp) {
my_before = before;
continue;
}
if (arg == F_WRLCK)
goto out;
if (fl->fl_flags & FL_UNLOCK_PENDING)
goto out;
}
if (my_before != NULL) {
lease = *my_before;
error = lease->fl_lmops->lm_change(my_before, arg, &dispose);
if (error)
goto out;
goto out_setup;
}
error = -EINVAL;
if (!leases_enable)
goto out;
locks_insert_lock(before, lease);
smp_mb();
error = check_conflicting_open(dentry, arg);
if (error)
goto out_unlink;
out_setup:
if (lease->fl_lmops->lm_setup)
lease->fl_lmops->lm_setup(lease, priv);
out:
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
if (is_deleg)
mutex_unlock(&inode->i_mutex);
if (!error && !my_before)
*flp = NULL;
return error;
out_unlink:
locks_unlink_lock(before);
goto out;
}
static int generic_delete_lease(struct file *filp)
{
int error = -EAGAIN;
struct file_lock *fl, **before;
struct dentry *dentry = filp->f_path.dentry;
struct inode *inode = dentry->d_inode;
LIST_HEAD(dispose);
spin_lock(&inode->i_lock);
time_out_leases(inode, &dispose);
for (before = &inode->i_flock;
((fl = *before) != NULL) && IS_LEASE(fl);
before = &fl->fl_next) {
if (fl->fl_file == filp)
break;
}
trace_generic_delete_lease(inode, fl);
if (fl && IS_LEASE(fl))
error = fl->fl_lmops->lm_change(before, F_UNLCK, &dispose);
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
return error;
}
int generic_setlease(struct file *filp, long arg, struct file_lock **flp,
void **priv)
{
struct dentry *dentry = filp->f_path.dentry;
struct inode *inode = dentry->d_inode;
int error;
if ((!uid_eq(current_fsuid(), inode->i_uid)) && !capable(CAP_LEASE))
return -EACCES;
if (!S_ISREG(inode->i_mode))
return -EINVAL;
error = security_file_lock(filp, arg);
if (error)
return error;
switch (arg) {
case F_UNLCK:
return generic_delete_lease(filp);
case F_RDLCK:
case F_WRLCK:
if (!(*flp)->fl_lmops->lm_break) {
WARN_ON_ONCE(1);
return -ENOLCK;
}
return generic_add_lease(filp, arg, flp, priv);
default:
return -EINVAL;
}
}
int
vfs_setlease(struct file *filp, long arg, struct file_lock **lease, void **priv)
{
if (filp->f_op->setlease)
return filp->f_op->setlease(filp, arg, lease, priv);
else
return generic_setlease(filp, arg, lease, priv);
}
static int do_fcntl_add_lease(unsigned int fd, struct file *filp, long arg)
{
struct file_lock *fl;
struct fasync_struct *new;
int error;
fl = lease_alloc(filp, arg);
if (IS_ERR(fl))
return PTR_ERR(fl);
new = fasync_alloc();
if (!new) {
locks_free_lock(fl);
return -ENOMEM;
}
new->fa_fd = fd;
error = vfs_setlease(filp, arg, &fl, (void **)&new);
if (fl)
locks_free_lock(fl);
if (new)
fasync_free(new);
return error;
}
int fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
if (arg == F_UNLCK)
return vfs_setlease(filp, F_UNLCK, NULL, NULL);
return do_fcntl_add_lease(fd, filp, arg);
}
int flock_lock_file_wait(struct file *filp, struct file_lock *fl)
{
int error;
might_sleep();
for (;;) {
error = flock_lock_file(filp, fl);
if (error != FILE_LOCK_DEFERRED)
break;
error = wait_event_interruptible(fl->fl_wait, !fl->fl_next);
if (!error)
continue;
locks_delete_block(fl);
break;
}
return error;
}
int vfs_test_lock(struct file *filp, struct file_lock *fl)
{
if (filp->f_op->lock)
return filp->f_op->lock(filp, F_GETLK, fl);
posix_test_lock(filp, fl);
return 0;
}
static int posix_lock_to_flock(struct flock *flock, struct file_lock *fl)
{
flock->l_pid = IS_OFDLCK(fl) ? -1 : fl->fl_pid;
#if BITS_PER_LONG == 32
if (fl->fl_start > OFFT_OFFSET_MAX)
return -EOVERFLOW;
if (fl->fl_end != OFFSET_MAX && fl->fl_end > OFFT_OFFSET_MAX)
return -EOVERFLOW;
#endif
flock->l_start = fl->fl_start;
flock->l_len = fl->fl_end == OFFSET_MAX ? 0 :
fl->fl_end - fl->fl_start + 1;
flock->l_whence = 0;
flock->l_type = fl->fl_type;
return 0;
}
static void posix_lock_to_flock64(struct flock64 *flock, struct file_lock *fl)
{
flock->l_pid = IS_OFDLCK(fl) ? -1 : fl->fl_pid;
flock->l_start = fl->fl_start;
flock->l_len = fl->fl_end == OFFSET_MAX ? 0 :
fl->fl_end - fl->fl_start + 1;
flock->l_whence = 0;
flock->l_type = fl->fl_type;
}
int fcntl_getlk(struct file *filp, unsigned int cmd, struct flock __user *l)
{
struct file_lock file_lock;
struct flock flock;
int error;
error = -EFAULT;
if (copy_from_user(&flock, l, sizeof(flock)))
goto out;
error = -EINVAL;
if ((flock.l_type != F_RDLCK) && (flock.l_type != F_WRLCK))
goto out;
error = flock_to_posix_lock(filp, &file_lock, &flock);
if (error)
goto out;
if (cmd == F_OFD_GETLK) {
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_GETLK;
file_lock.fl_flags |= FL_OFDLCK;
file_lock.fl_owner = filp;
}
error = vfs_test_lock(filp, &file_lock);
if (error)
goto out;
flock.l_type = file_lock.fl_type;
if (file_lock.fl_type != F_UNLCK) {
error = posix_lock_to_flock(&flock, &file_lock);
if (error)
goto rel_priv;
}
error = -EFAULT;
if (!copy_to_user(l, &flock, sizeof(flock)))
error = 0;
rel_priv:
locks_release_private(&file_lock);
out:
return error;
}
int vfs_lock_file(struct file *filp, unsigned int cmd, struct file_lock *fl, struct file_lock *conf)
{
if (filp->f_op->lock)
return filp->f_op->lock(filp, cmd, fl);
else
return posix_lock_file(filp, fl, conf);
}
static int do_lock_file_wait(struct file *filp, unsigned int cmd,
struct file_lock *fl)
{
int error;
error = security_file_lock(filp, fl->fl_type);
if (error)
return error;
for (;;) {
error = vfs_lock_file(filp, cmd, fl, NULL);
if (error != FILE_LOCK_DEFERRED)
break;
error = wait_event_interruptible(fl->fl_wait, !fl->fl_next);
if (!error)
continue;
locks_delete_block(fl);
break;
}
return error;
}
static int
check_fmode_for_setlk(struct file_lock *fl)
{
switch (fl->fl_type) {
case F_RDLCK:
if (!(fl->fl_file->f_mode & FMODE_READ))
return -EBADF;
break;
case F_WRLCK:
if (!(fl->fl_file->f_mode & FMODE_WRITE))
return -EBADF;
}
return 0;
}
int fcntl_setlk(unsigned int fd, struct file *filp, unsigned int cmd,
struct flock __user *l)
{
struct file_lock *file_lock = locks_alloc_lock();
struct flock flock;
struct inode *inode;
struct file *f;
int error;
if (file_lock == NULL)
return -ENOLCK;
error = -EFAULT;
if (copy_from_user(&flock, l, sizeof(flock)))
goto out;
inode = file_inode(filp);
if (mandatory_lock(inode) && mapping_writably_mapped(filp->f_mapping)) {
error = -EAGAIN;
goto out;
}
again:
error = flock_to_posix_lock(filp, file_lock, &flock);
if (error)
goto out;
error = check_fmode_for_setlk(file_lock);
if (error)
goto out;
switch (cmd) {
case F_OFD_SETLK:
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_SETLK;
file_lock->fl_flags |= FL_OFDLCK;
file_lock->fl_owner = filp;
break;
case F_OFD_SETLKW:
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_SETLKW;
file_lock->fl_flags |= FL_OFDLCK;
file_lock->fl_owner = filp;
case F_SETLKW:
file_lock->fl_flags |= FL_SLEEP;
}
error = do_lock_file_wait(filp, cmd, file_lock);
spin_lock(&current->files->file_lock);
f = fcheck(fd);
spin_unlock(&current->files->file_lock);
if (!error && f != filp && flock.l_type != F_UNLCK) {
flock.l_type = F_UNLCK;
goto again;
}
out:
locks_free_lock(file_lock);
return error;
}
int fcntl_getlk64(struct file *filp, unsigned int cmd, struct flock64 __user *l)
{
struct file_lock file_lock;
struct flock64 flock;
int error;
error = -EFAULT;
if (copy_from_user(&flock, l, sizeof(flock)))
goto out;
error = -EINVAL;
if ((flock.l_type != F_RDLCK) && (flock.l_type != F_WRLCK))
goto out;
error = flock64_to_posix_lock(filp, &file_lock, &flock);
if (error)
goto out;
if (cmd == F_OFD_GETLK) {
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_GETLK64;
file_lock.fl_flags |= FL_OFDLCK;
file_lock.fl_owner = filp;
}
error = vfs_test_lock(filp, &file_lock);
if (error)
goto out;
flock.l_type = file_lock.fl_type;
if (file_lock.fl_type != F_UNLCK)
posix_lock_to_flock64(&flock, &file_lock);
error = -EFAULT;
if (!copy_to_user(l, &flock, sizeof(flock)))
error = 0;
locks_release_private(&file_lock);
out:
return error;
}
int fcntl_setlk64(unsigned int fd, struct file *filp, unsigned int cmd,
struct flock64 __user *l)
{
struct file_lock *file_lock = locks_alloc_lock();
struct flock64 flock;
struct inode *inode;
struct file *f;
int error;
if (file_lock == NULL)
return -ENOLCK;
error = -EFAULT;
if (copy_from_user(&flock, l, sizeof(flock)))
goto out;
inode = file_inode(filp);
if (mandatory_lock(inode) && mapping_writably_mapped(filp->f_mapping)) {
error = -EAGAIN;
goto out;
}
again:
error = flock64_to_posix_lock(filp, file_lock, &flock);
if (error)
goto out;
error = check_fmode_for_setlk(file_lock);
if (error)
goto out;
switch (cmd) {
case F_OFD_SETLK:
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_SETLK64;
file_lock->fl_flags |= FL_OFDLCK;
file_lock->fl_owner = filp;
break;
case F_OFD_SETLKW:
error = -EINVAL;
if (flock.l_pid != 0)
goto out;
cmd = F_SETLKW64;
file_lock->fl_flags |= FL_OFDLCK;
file_lock->fl_owner = filp;
case F_SETLKW64:
file_lock->fl_flags |= FL_SLEEP;
}
error = do_lock_file_wait(filp, cmd, file_lock);
spin_lock(&current->files->file_lock);
f = fcheck(fd);
spin_unlock(&current->files->file_lock);
if (!error && f != filp && flock.l_type != F_UNLCK) {
flock.l_type = F_UNLCK;
goto again;
}
out:
locks_free_lock(file_lock);
return error;
}
void locks_remove_posix(struct file *filp, fl_owner_t owner)
{
struct file_lock lock;
if (!file_inode(filp)->i_flock)
return;
lock.fl_type = F_UNLCK;
lock.fl_flags = FL_POSIX | FL_CLOSE;
lock.fl_start = 0;
lock.fl_end = OFFSET_MAX;
lock.fl_owner = owner;
lock.fl_pid = current->tgid;
lock.fl_file = filp;
lock.fl_ops = NULL;
lock.fl_lmops = NULL;
vfs_lock_file(filp, F_SETLK, &lock, NULL);
if (lock.fl_ops && lock.fl_ops->fl_release_private)
lock.fl_ops->fl_release_private(&lock);
}
void locks_remove_file(struct file *filp)
{
struct inode * inode = file_inode(filp);
struct file_lock *fl;
struct file_lock **before;
LIST_HEAD(dispose);
if (!inode->i_flock)
return;
locks_remove_posix(filp, filp);
if (filp->f_op->flock) {
struct file_lock fl = {
.fl_owner = filp,
.fl_pid = current->tgid,
.fl_file = filp,
.fl_flags = FL_FLOCK,
.fl_type = F_UNLCK,
.fl_end = OFFSET_MAX,
};
filp->f_op->flock(filp, F_SETLKW, &fl);
if (fl.fl_ops && fl.fl_ops->fl_release_private)
fl.fl_ops->fl_release_private(&fl);
}
spin_lock(&inode->i_lock);
before = &inode->i_flock;
while ((fl = *before) != NULL) {
if (fl->fl_file == filp) {
if (IS_LEASE(fl)) {
lease_modify(before, F_UNLCK, &dispose);
continue;
}
WARN(!IS_FLOCK(fl),
"leftover lock: dev=%u:%u ino=%lu type=%hhd flags=0x%x start=%lld end=%lld\n",
MAJOR(inode->i_sb->s_dev),
MINOR(inode->i_sb->s_dev), inode->i_ino,
fl->fl_type, fl->fl_flags,
fl->fl_start, fl->fl_end);
locks_delete_lock(before, &dispose);
continue;
}
before = &fl->fl_next;
}
spin_unlock(&inode->i_lock);
locks_dispose_list(&dispose);
}
int
posix_unblock_lock(struct file_lock *waiter)
{
int status = 0;
spin_lock(&blocked_lock_lock);
if (waiter->fl_next)
__locks_delete_block(waiter);
else
status = -ENOENT;
spin_unlock(&blocked_lock_lock);
return status;
}
int vfs_cancel_lock(struct file *filp, struct file_lock *fl)
{
if (filp->f_op->lock)
return filp->f_op->lock(filp, F_CANCELLK, fl);
return 0;
}
static void lock_get_status(struct seq_file *f, struct file_lock *fl,
loff_t id, char *pfx)
{
struct inode *inode = NULL;
unsigned int fl_pid;
if (fl->fl_nspid)
fl_pid = pid_vnr(fl->fl_nspid);
else
fl_pid = fl->fl_pid;
if (fl->fl_file != NULL)
inode = file_inode(fl->fl_file);
seq_printf(f, "%lld:%s ", id, pfx);
if (IS_POSIX(fl)) {
if (fl->fl_flags & FL_ACCESS)
seq_puts(f, "ACCESS");
else if (IS_OFDLCK(fl))
seq_puts(f, "OFDLCK");
else
seq_puts(f, "POSIX ");
seq_printf(f, " %s ",
(inode == NULL) ? "*NOINODE*" :
mandatory_lock(inode) ? "MANDATORY" : "ADVISORY ");
} else if (IS_FLOCK(fl)) {
if (fl->fl_type & LOCK_MAND) {
seq_puts(f, "FLOCK MSNFS ");
} else {
seq_puts(f, "FLOCK ADVISORY ");
}
} else if (IS_LEASE(fl)) {
if (fl->fl_flags & FL_DELEG)
seq_puts(f, "DELEG ");
else
seq_puts(f, "LEASE ");
if (lease_breaking(fl))
seq_puts(f, "BREAKING ");
else if (fl->fl_file)
seq_puts(f, "ACTIVE ");
else
seq_puts(f, "BREAKER ");
} else {
seq_puts(f, "UNKNOWN UNKNOWN ");
}
if (fl->fl_type & LOCK_MAND) {
seq_printf(f, "%s ",
(fl->fl_type & LOCK_READ)
? (fl->fl_type & LOCK_WRITE) ? "RW " : "READ "
: (fl->fl_type & LOCK_WRITE) ? "WRITE" : "NONE ");
} else {
seq_printf(f, "%s ",
(lease_breaking(fl))
? (fl->fl_type == F_UNLCK) ? "UNLCK" : "READ "
: (fl->fl_type == F_WRLCK) ? "WRITE" : "READ ");
}
if (inode) {
#ifdef WE_CAN_BREAK_LSLK_NOW
seq_printf(f, "%d %s:%ld ", fl_pid,
inode->i_sb->s_id, inode->i_ino);
#else
seq_printf(f, "%d %02x:%02x:%ld ", fl_pid,
MAJOR(inode->i_sb->s_dev),
MINOR(inode->i_sb->s_dev), inode->i_ino);
#endif
} else {
seq_printf(f, "%d <none>:0 ", fl_pid);
}
if (IS_POSIX(fl)) {
if (fl->fl_end == OFFSET_MAX)
seq_printf(f, "%Ld EOF\n", fl->fl_start);
else
seq_printf(f, "%Ld %Ld\n", fl->fl_start, fl->fl_end);
} else {
seq_puts(f, "0 EOF\n");
}
}
static int locks_show(struct seq_file *f, void *v)
{
struct locks_iterator *iter = f->private;
struct file_lock *fl, *bfl;
fl = hlist_entry(v, struct file_lock, fl_link);
lock_get_status(f, fl, iter->li_pos, "");
list_for_each_entry(bfl, &fl->fl_block, fl_block)
lock_get_status(f, bfl, iter->li_pos, " ->");
return 0;
}
static void *locks_start(struct seq_file *f, loff_t *pos)
__acquires(&blocked_lock_lock
static void *locks_next(struct seq_file *f, void *v, loff_t *pos)
{
struct locks_iterator *iter = f->private;
++iter->li_pos;
return seq_hlist_next_percpu(v, &file_lock_list, &iter->li_cpu, pos);
}
static void locks_stop(struct seq_file *f, void *v)
__releases(&blocked_lock_lock
static int locks_open(struct inode *inode, struct file *filp)
{
return seq_open_private(filp, &locks_seq_operations,
sizeof(struct locks_iterator));
}
static int __init proc_locks_init(void)
{
proc_create("locks", 0, NULL, &proc_locks_operations);
return 0;
}
static int __init filelock_init(void)
{
int i;
filelock_cache = kmem_cache_create("file_lock_cache",
sizeof(struct file_lock), 0, SLAB_PANIC, NULL);
lg_lock_init(&file_lock_lglock, "file_lock_lglock");
for_each_possible_cpu(i)
INIT_HLIST_HEAD(per_cpu_ptr(&file_lock_list, i));
return 0;
}
