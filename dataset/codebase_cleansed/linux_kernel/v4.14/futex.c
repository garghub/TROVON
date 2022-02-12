static int __init setup_fail_futex(char *str)
{
return setup_fault_attr(&fail_futex.attr, str);
}
static bool should_fail_futex(bool fshared)
{
if (fail_futex.ignore_private && !fshared)
return false;
return should_fail(&fail_futex.attr, 1);
}
static int __init fail_futex_debugfs(void)
{
umode_t mode = S_IFREG | S_IRUSR | S_IWUSR;
struct dentry *dir;
dir = fault_create_debugfs_attr("fail_futex", NULL,
&fail_futex.attr);
if (IS_ERR(dir))
return PTR_ERR(dir);
if (!debugfs_create_bool("ignore-private", mode, dir,
&fail_futex.ignore_private)) {
debugfs_remove_recursive(dir);
return -ENOMEM;
}
return 0;
}
static inline bool should_fail_futex(bool fshared)
{
return false;
}
static inline void futex_get_mm(union futex_key *key)
{
mmgrab(key->private.mm);
smp_mb__after_atomic();
}
static inline void hb_waiters_inc(struct futex_hash_bucket *hb)
{
#ifdef CONFIG_SMP
atomic_inc(&hb->waiters);
smp_mb__after_atomic();
#endif
}
static inline void hb_waiters_dec(struct futex_hash_bucket *hb)
{
#ifdef CONFIG_SMP
atomic_dec(&hb->waiters);
#endif
}
static inline int hb_waiters_pending(struct futex_hash_bucket *hb)
{
#ifdef CONFIG_SMP
return atomic_read(&hb->waiters);
#else
return 1;
#endif
}
static struct futex_hash_bucket *hash_futex(union futex_key *key)
{
u32 hash = jhash2((u32*)&key->both.word,
(sizeof(key->both.word)+sizeof(key->both.ptr))/4,
key->both.offset);
return &futex_queues[hash & (futex_hashsize - 1)];
}
static inline int match_futex(union futex_key *key1, union futex_key *key2)
{
return (key1 && key2
&& key1->both.word == key2->both.word
&& key1->both.ptr == key2->both.ptr
&& key1->both.offset == key2->both.offset);
}
static void get_futex_key_refs(union futex_key *key)
{
if (!key->both.ptr)
return;
if (!IS_ENABLED(CONFIG_MMU)) {
smp_mb();
return;
}
switch (key->both.offset & (FUT_OFF_INODE|FUT_OFF_MMSHARED)) {
case FUT_OFF_INODE:
ihold(key->shared.inode);
break;
case FUT_OFF_MMSHARED:
futex_get_mm(key);
break;
default:
smp_mb();
}
}
static void drop_futex_key_refs(union futex_key *key)
{
if (!key->both.ptr) {
WARN_ON_ONCE(1);
return;
}
if (!IS_ENABLED(CONFIG_MMU))
return;
switch (key->both.offset & (FUT_OFF_INODE|FUT_OFF_MMSHARED)) {
case FUT_OFF_INODE:
iput(key->shared.inode);
break;
case FUT_OFF_MMSHARED:
mmdrop(key->private.mm);
break;
}
}
static int
get_futex_key(u32 __user *uaddr, int fshared, union futex_key *key, int rw)
{
unsigned long address = (unsigned long)uaddr;
struct mm_struct *mm = current->mm;
struct page *page, *tail;
struct address_space *mapping;
int err, ro = 0;
key->both.offset = address % PAGE_SIZE;
if (unlikely((address % sizeof(u32)) != 0))
return -EINVAL;
address -= key->both.offset;
if (unlikely(!access_ok(rw, uaddr, sizeof(u32))))
return -EFAULT;
if (unlikely(should_fail_futex(fshared)))
return -EFAULT;
if (!fshared) {
key->private.mm = mm;
key->private.address = address;
get_futex_key_refs(key);
return 0;
}
again:
if (unlikely(should_fail_futex(fshared)))
return -EFAULT;
err = get_user_pages_fast(address, 1, 1, &page);
if (err == -EFAULT && rw == VERIFY_READ) {
err = get_user_pages_fast(address, 1, 0, &page);
ro = 1;
}
if (err < 0)
return err;
else
err = 0;
tail = page;
page = compound_head(page);
mapping = READ_ONCE(page->mapping);
if (unlikely(!mapping)) {
int shmem_swizzled;
lock_page(page);
shmem_swizzled = PageSwapCache(page) || page->mapping;
unlock_page(page);
put_page(page);
if (shmem_swizzled)
goto again;
return -EFAULT;
}
if (PageAnon(page)) {
if (unlikely(should_fail_futex(fshared)) || ro) {
err = -EFAULT;
goto out;
}
key->both.offset |= FUT_OFF_MMSHARED;
key->private.mm = mm;
key->private.address = address;
get_futex_key_refs(key);
} else {
struct inode *inode;
rcu_read_lock();
if (READ_ONCE(page->mapping) != mapping) {
rcu_read_unlock();
put_page(page);
goto again;
}
inode = READ_ONCE(mapping->host);
if (!inode) {
rcu_read_unlock();
put_page(page);
goto again;
}
if (!atomic_inc_not_zero(&inode->i_count)) {
rcu_read_unlock();
put_page(page);
goto again;
}
if (WARN_ON_ONCE(inode->i_mapping != mapping)) {
err = -EFAULT;
rcu_read_unlock();
iput(inode);
goto out;
}
key->both.offset |= FUT_OFF_INODE;
key->shared.inode = inode;
key->shared.pgoff = basepage_index(tail);
rcu_read_unlock();
}
out:
put_page(page);
return err;
}
static inline void put_futex_key(union futex_key *key)
{
drop_futex_key_refs(key);
}
static int fault_in_user_writeable(u32 __user *uaddr)
{
struct mm_struct *mm = current->mm;
int ret;
down_read(&mm->mmap_sem);
ret = fixup_user_fault(current, mm, (unsigned long)uaddr,
FAULT_FLAG_WRITE, NULL);
up_read(&mm->mmap_sem);
return ret < 0 ? ret : 0;
}
static struct futex_q *futex_top_waiter(struct futex_hash_bucket *hb,
union futex_key *key)
{
struct futex_q *this;
plist_for_each_entry(this, &hb->chain, list) {
if (match_futex(&this->key, key))
return this;
}
return NULL;
}
static int cmpxchg_futex_value_locked(u32 *curval, u32 __user *uaddr,
u32 uval, u32 newval)
{
int ret;
pagefault_disable();
ret = futex_atomic_cmpxchg_inatomic(curval, uaddr, uval, newval);
pagefault_enable();
return ret;
}
static int get_futex_value_locked(u32 *dest, u32 __user *from)
{
int ret;
pagefault_disable();
ret = __get_user(*dest, from);
pagefault_enable();
return ret ? -EFAULT : 0;
}
static int refill_pi_state_cache(void)
{
struct futex_pi_state *pi_state;
if (likely(current->pi_state_cache))
return 0;
pi_state = kzalloc(sizeof(*pi_state), GFP_KERNEL);
if (!pi_state)
return -ENOMEM;
INIT_LIST_HEAD(&pi_state->list);
pi_state->owner = NULL;
atomic_set(&pi_state->refcount, 1);
pi_state->key = FUTEX_KEY_INIT;
current->pi_state_cache = pi_state;
return 0;
}
static struct futex_pi_state *alloc_pi_state(void)
{
struct futex_pi_state *pi_state = current->pi_state_cache;
WARN_ON(!pi_state);
current->pi_state_cache = NULL;
return pi_state;
}
static void get_pi_state(struct futex_pi_state *pi_state)
{
WARN_ON_ONCE(!atomic_inc_not_zero(&pi_state->refcount));
}
static void put_pi_state(struct futex_pi_state *pi_state)
{
if (!pi_state)
return;
if (!atomic_dec_and_test(&pi_state->refcount))
return;
if (pi_state->owner) {
struct task_struct *owner;
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
owner = pi_state->owner;
if (owner) {
raw_spin_lock(&owner->pi_lock);
list_del_init(&pi_state->list);
raw_spin_unlock(&owner->pi_lock);
}
rt_mutex_proxy_unlock(&pi_state->pi_mutex, owner);
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
}
if (current->pi_state_cache) {
kfree(pi_state);
} else {
pi_state->owner = NULL;
atomic_set(&pi_state->refcount, 1);
current->pi_state_cache = pi_state;
}
}
static struct task_struct *futex_find_get_task(pid_t pid)
{
struct task_struct *p;
rcu_read_lock();
p = find_task_by_vpid(pid);
if (p)
get_task_struct(p);
rcu_read_unlock();
return p;
}
void exit_pi_state_list(struct task_struct *curr)
{
struct list_head *next, *head = &curr->pi_state_list;
struct futex_pi_state *pi_state;
struct futex_hash_bucket *hb;
union futex_key key = FUTEX_KEY_INIT;
if (!futex_cmpxchg_enabled)
return;
raw_spin_lock_irq(&curr->pi_lock);
while (!list_empty(head)) {
next = head->next;
pi_state = list_entry(next, struct futex_pi_state, list);
key = pi_state->key;
hb = hash_futex(&key);
if (!atomic_inc_not_zero(&pi_state->refcount)) {
raw_spin_unlock_irq(&curr->pi_lock);
cpu_relax();
raw_spin_lock_irq(&curr->pi_lock);
continue;
}
raw_spin_unlock_irq(&curr->pi_lock);
spin_lock(&hb->lock);
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
raw_spin_lock(&curr->pi_lock);
if (head->next != next) {
raw_spin_unlock(&pi_state->pi_mutex.wait_lock);
spin_unlock(&hb->lock);
put_pi_state(pi_state);
continue;
}
WARN_ON(pi_state->owner != curr);
WARN_ON(list_empty(&pi_state->list));
list_del_init(&pi_state->list);
pi_state->owner = NULL;
raw_spin_unlock(&curr->pi_lock);
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
spin_unlock(&hb->lock);
rt_mutex_futex_unlock(&pi_state->pi_mutex);
put_pi_state(pi_state);
raw_spin_lock_irq(&curr->pi_lock);
}
raw_spin_unlock_irq(&curr->pi_lock);
}
static int attach_to_pi_state(u32 __user *uaddr, u32 uval,
struct futex_pi_state *pi_state,
struct futex_pi_state **ps)
{
pid_t pid = uval & FUTEX_TID_MASK;
u32 uval2;
int ret;
if (unlikely(!pi_state))
return -EINVAL;
WARN_ON(!atomic_read(&pi_state->refcount));
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
if (get_futex_value_locked(&uval2, uaddr))
goto out_efault;
if (uval != uval2)
goto out_eagain;
if (uval & FUTEX_OWNER_DIED) {
if (!pi_state->owner) {
if (pid)
goto out_einval;
goto out_attach;
}
if (!pid)
goto out_attach;
} else {
if (!pi_state->owner)
goto out_einval;
}
if (pid != task_pid_vnr(pi_state->owner))
goto out_einval;
out_attach:
get_pi_state(pi_state);
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
*ps = pi_state;
return 0;
out_einval:
ret = -EINVAL;
goto out_error;
out_eagain:
ret = -EAGAIN;
goto out_error;
out_efault:
ret = -EFAULT;
goto out_error;
out_error:
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
return ret;
}
static int attach_to_pi_owner(u32 uval, union futex_key *key,
struct futex_pi_state **ps)
{
pid_t pid = uval & FUTEX_TID_MASK;
struct futex_pi_state *pi_state;
struct task_struct *p;
if (!pid)
return -ESRCH;
p = futex_find_get_task(pid);
if (!p)
return -ESRCH;
if (unlikely(p->flags & PF_KTHREAD)) {
put_task_struct(p);
return -EPERM;
}
raw_spin_lock_irq(&p->pi_lock);
if (unlikely(p->flags & PF_EXITING)) {
int ret = (p->flags & PF_EXITPIDONE) ? -ESRCH : -EAGAIN;
raw_spin_unlock_irq(&p->pi_lock);
put_task_struct(p);
return ret;
}
pi_state = alloc_pi_state();
rt_mutex_init_proxy_locked(&pi_state->pi_mutex, p);
pi_state->key = *key;
WARN_ON(!list_empty(&pi_state->list));
list_add(&pi_state->list, &p->pi_state_list);
pi_state->owner = p;
raw_spin_unlock_irq(&p->pi_lock);
put_task_struct(p);
*ps = pi_state;
return 0;
}
static int lookup_pi_state(u32 __user *uaddr, u32 uval,
struct futex_hash_bucket *hb,
union futex_key *key, struct futex_pi_state **ps)
{
struct futex_q *top_waiter = futex_top_waiter(hb, key);
if (top_waiter)
return attach_to_pi_state(uaddr, uval, top_waiter->pi_state, ps);
return attach_to_pi_owner(uval, key, ps);
}
static int lock_pi_update_atomic(u32 __user *uaddr, u32 uval, u32 newval)
{
u32 uninitialized_var(curval);
if (unlikely(should_fail_futex(true)))
return -EFAULT;
if (unlikely(cmpxchg_futex_value_locked(&curval, uaddr, uval, newval)))
return -EFAULT;
return curval != uval ? -EAGAIN : 0;
}
static int futex_lock_pi_atomic(u32 __user *uaddr, struct futex_hash_bucket *hb,
union futex_key *key,
struct futex_pi_state **ps,
struct task_struct *task, int set_waiters)
{
u32 uval, newval, vpid = task_pid_vnr(task);
struct futex_q *top_waiter;
int ret;
if (get_futex_value_locked(&uval, uaddr))
return -EFAULT;
if (unlikely(should_fail_futex(true)))
return -EFAULT;
if ((unlikely((uval & FUTEX_TID_MASK) == vpid)))
return -EDEADLK;
if ((unlikely(should_fail_futex(true))))
return -EDEADLK;
top_waiter = futex_top_waiter(hb, key);
if (top_waiter)
return attach_to_pi_state(uaddr, uval, top_waiter->pi_state, ps);
if (!(uval & FUTEX_TID_MASK)) {
newval = uval & FUTEX_OWNER_DIED;
newval |= vpid;
if (set_waiters)
newval |= FUTEX_WAITERS;
ret = lock_pi_update_atomic(uaddr, uval, newval);
return ret < 0 ? ret : 1;
}
newval = uval | FUTEX_WAITERS;
ret = lock_pi_update_atomic(uaddr, uval, newval);
if (ret)
return ret;
return attach_to_pi_owner(uval, key, ps);
}
static void __unqueue_futex(struct futex_q *q)
{
struct futex_hash_bucket *hb;
if (WARN_ON_SMP(!q->lock_ptr || !spin_is_locked(q->lock_ptr))
|| WARN_ON(plist_node_empty(&q->list)))
return;
hb = container_of(q->lock_ptr, struct futex_hash_bucket, lock);
plist_del(&q->list, &hb->chain);
hb_waiters_dec(hb);
}
static void mark_wake_futex(struct wake_q_head *wake_q, struct futex_q *q)
{
struct task_struct *p = q->task;
if (WARN(q->pi_state || q->rt_waiter, "refusing to wake PI futex\n"))
return;
wake_q_add(wake_q, p);
__unqueue_futex(q);
smp_store_release(&q->lock_ptr, NULL);
}
static int wake_futex_pi(u32 __user *uaddr, u32 uval, struct futex_pi_state *pi_state)
{
u32 uninitialized_var(curval), newval;
struct task_struct *new_owner;
bool postunlock = false;
DEFINE_WAKE_Q(wake_q);
int ret = 0;
new_owner = rt_mutex_next_owner(&pi_state->pi_mutex);
if (WARN_ON_ONCE(!new_owner)) {
ret = -EAGAIN;
goto out_unlock;
}
newval = FUTEX_WAITERS | task_pid_vnr(new_owner);
if (unlikely(should_fail_futex(true)))
ret = -EFAULT;
if (cmpxchg_futex_value_locked(&curval, uaddr, uval, newval)) {
ret = -EFAULT;
} else if (curval != uval) {
if ((FUTEX_TID_MASK & curval) == uval)
ret = -EAGAIN;
else
ret = -EINVAL;
}
if (ret)
goto out_unlock;
raw_spin_lock(&pi_state->owner->pi_lock);
WARN_ON(list_empty(&pi_state->list));
list_del_init(&pi_state->list);
raw_spin_unlock(&pi_state->owner->pi_lock);
raw_spin_lock(&new_owner->pi_lock);
WARN_ON(!list_empty(&pi_state->list));
list_add(&pi_state->list, &new_owner->pi_state_list);
pi_state->owner = new_owner;
raw_spin_unlock(&new_owner->pi_lock);
postunlock = __rt_mutex_futex_unlock(&pi_state->pi_mutex, &wake_q);
out_unlock:
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
if (postunlock)
rt_mutex_postunlock(&wake_q);
return ret;
}
static inline void
double_lock_hb(struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2)
{
if (hb1 <= hb2) {
spin_lock(&hb1->lock);
if (hb1 < hb2)
spin_lock_nested(&hb2->lock, SINGLE_DEPTH_NESTING);
} else {
spin_lock(&hb2->lock);
spin_lock_nested(&hb1->lock, SINGLE_DEPTH_NESTING);
}
}
static inline void
double_unlock_hb(struct futex_hash_bucket *hb1, struct futex_hash_bucket *hb2)
{
spin_unlock(&hb1->lock);
if (hb1 != hb2)
spin_unlock(&hb2->lock);
}
static int
futex_wake(u32 __user *uaddr, unsigned int flags, int nr_wake, u32 bitset)
{
struct futex_hash_bucket *hb;
struct futex_q *this, *next;
union futex_key key = FUTEX_KEY_INIT;
int ret;
DEFINE_WAKE_Q(wake_q);
if (!bitset)
return -EINVAL;
ret = get_futex_key(uaddr, flags & FLAGS_SHARED, &key, VERIFY_READ);
if (unlikely(ret != 0))
goto out;
hb = hash_futex(&key);
if (!hb_waiters_pending(hb))
goto out_put_key;
spin_lock(&hb->lock);
plist_for_each_entry_safe(this, next, &hb->chain, list) {
if (match_futex (&this->key, &key)) {
if (this->pi_state || this->rt_waiter) {
ret = -EINVAL;
break;
}
if (!(this->bitset & bitset))
continue;
mark_wake_futex(&wake_q, this);
if (++ret >= nr_wake)
break;
}
}
spin_unlock(&hb->lock);
wake_up_q(&wake_q);
out_put_key:
put_futex_key(&key);
out:
return ret;
}
static int futex_atomic_op_inuser(unsigned int encoded_op, u32 __user *uaddr)
{
unsigned int op = (encoded_op & 0x70000000) >> 28;
unsigned int cmp = (encoded_op & 0x0f000000) >> 24;
int oparg = sign_extend32((encoded_op & 0x00fff000) >> 12, 12);
int cmparg = sign_extend32(encoded_op & 0x00000fff, 12);
int oldval, ret;
if (encoded_op & (FUTEX_OP_OPARG_SHIFT << 28)) {
if (oparg < 0 || oparg > 31) {
char comm[sizeof(current->comm)];
pr_info_ratelimited("futex_wake_op: %s tries to shift op by %d; fix this program\n",
get_task_comm(comm, current), oparg);
oparg &= 31;
}
oparg = 1 << oparg;
}
if (!access_ok(VERIFY_WRITE, uaddr, sizeof(u32)))
return -EFAULT;
ret = arch_futex_atomic_op_inuser(op, oparg, &oldval, uaddr);
if (ret)
return ret;
switch (cmp) {
case FUTEX_OP_CMP_EQ:
return oldval == cmparg;
case FUTEX_OP_CMP_NE:
return oldval != cmparg;
case FUTEX_OP_CMP_LT:
return oldval < cmparg;
case FUTEX_OP_CMP_GE:
return oldval >= cmparg;
case FUTEX_OP_CMP_LE:
return oldval <= cmparg;
case FUTEX_OP_CMP_GT:
return oldval > cmparg;
default:
return -ENOSYS;
}
}
static int
futex_wake_op(u32 __user *uaddr1, unsigned int flags, u32 __user *uaddr2,
int nr_wake, int nr_wake2, int op)
{
union futex_key key1 = FUTEX_KEY_INIT, key2 = FUTEX_KEY_INIT;
struct futex_hash_bucket *hb1, *hb2;
struct futex_q *this, *next;
int ret, op_ret;
DEFINE_WAKE_Q(wake_q);
retry:
ret = get_futex_key(uaddr1, flags & FLAGS_SHARED, &key1, VERIFY_READ);
if (unlikely(ret != 0))
goto out;
ret = get_futex_key(uaddr2, flags & FLAGS_SHARED, &key2, VERIFY_WRITE);
if (unlikely(ret != 0))
goto out_put_key1;
hb1 = hash_futex(&key1);
hb2 = hash_futex(&key2);
retry_private:
double_lock_hb(hb1, hb2);
op_ret = futex_atomic_op_inuser(op, uaddr2);
if (unlikely(op_ret < 0)) {
double_unlock_hb(hb1, hb2);
#ifndef CONFIG_MMU
ret = op_ret;
goto out_put_keys;
#endif
if (unlikely(op_ret != -EFAULT)) {
ret = op_ret;
goto out_put_keys;
}
ret = fault_in_user_writeable(uaddr2);
if (ret)
goto out_put_keys;
if (!(flags & FLAGS_SHARED))
goto retry_private;
put_futex_key(&key2);
put_futex_key(&key1);
goto retry;
}
plist_for_each_entry_safe(this, next, &hb1->chain, list) {
if (match_futex (&this->key, &key1)) {
if (this->pi_state || this->rt_waiter) {
ret = -EINVAL;
goto out_unlock;
}
mark_wake_futex(&wake_q, this);
if (++ret >= nr_wake)
break;
}
}
if (op_ret > 0) {
op_ret = 0;
plist_for_each_entry_safe(this, next, &hb2->chain, list) {
if (match_futex (&this->key, &key2)) {
if (this->pi_state || this->rt_waiter) {
ret = -EINVAL;
goto out_unlock;
}
mark_wake_futex(&wake_q, this);
if (++op_ret >= nr_wake2)
break;
}
}
ret += op_ret;
}
out_unlock:
double_unlock_hb(hb1, hb2);
wake_up_q(&wake_q);
out_put_keys:
put_futex_key(&key2);
out_put_key1:
put_futex_key(&key1);
out:
return ret;
}
static inline
void requeue_futex(struct futex_q *q, struct futex_hash_bucket *hb1,
struct futex_hash_bucket *hb2, union futex_key *key2)
{
if (likely(&hb1->chain != &hb2->chain)) {
plist_del(&q->list, &hb1->chain);
hb_waiters_dec(hb1);
hb_waiters_inc(hb2);
plist_add(&q->list, &hb2->chain);
q->lock_ptr = &hb2->lock;
}
get_futex_key_refs(key2);
q->key = *key2;
}
static inline
void requeue_pi_wake_futex(struct futex_q *q, union futex_key *key,
struct futex_hash_bucket *hb)
{
get_futex_key_refs(key);
q->key = *key;
__unqueue_futex(q);
WARN_ON(!q->rt_waiter);
q->rt_waiter = NULL;
q->lock_ptr = &hb->lock;
wake_up_state(q->task, TASK_NORMAL);
}
static int futex_proxy_trylock_atomic(u32 __user *pifutex,
struct futex_hash_bucket *hb1,
struct futex_hash_bucket *hb2,
union futex_key *key1, union futex_key *key2,
struct futex_pi_state **ps, int set_waiters)
{
struct futex_q *top_waiter = NULL;
u32 curval;
int ret, vpid;
if (get_futex_value_locked(&curval, pifutex))
return -EFAULT;
if (unlikely(should_fail_futex(true)))
return -EFAULT;
top_waiter = futex_top_waiter(hb1, key1);
if (!top_waiter)
return 0;
if (!match_futex(top_waiter->requeue_pi_key, key2))
return -EINVAL;
vpid = task_pid_vnr(top_waiter->task);
ret = futex_lock_pi_atomic(pifutex, hb2, key2, ps, top_waiter->task,
set_waiters);
if (ret == 1) {
requeue_pi_wake_futex(top_waiter, key2, hb2);
return vpid;
}
return ret;
}
static int futex_requeue(u32 __user *uaddr1, unsigned int flags,
u32 __user *uaddr2, int nr_wake, int nr_requeue,
u32 *cmpval, int requeue_pi)
{
union futex_key key1 = FUTEX_KEY_INIT, key2 = FUTEX_KEY_INIT;
int drop_count = 0, task_count = 0, ret;
struct futex_pi_state *pi_state = NULL;
struct futex_hash_bucket *hb1, *hb2;
struct futex_q *this, *next;
DEFINE_WAKE_Q(wake_q);
if (!IS_ENABLED(CONFIG_FUTEX_PI) && requeue_pi)
return -ENOSYS;
if (requeue_pi) {
if (uaddr1 == uaddr2)
return -EINVAL;
if (refill_pi_state_cache())
return -ENOMEM;
if (nr_wake != 1)
return -EINVAL;
}
retry:
ret = get_futex_key(uaddr1, flags & FLAGS_SHARED, &key1, VERIFY_READ);
if (unlikely(ret != 0))
goto out;
ret = get_futex_key(uaddr2, flags & FLAGS_SHARED, &key2,
requeue_pi ? VERIFY_WRITE : VERIFY_READ);
if (unlikely(ret != 0))
goto out_put_key1;
if (requeue_pi && match_futex(&key1, &key2)) {
ret = -EINVAL;
goto out_put_keys;
}
hb1 = hash_futex(&key1);
hb2 = hash_futex(&key2);
retry_private:
hb_waiters_inc(hb2);
double_lock_hb(hb1, hb2);
if (likely(cmpval != NULL)) {
u32 curval;
ret = get_futex_value_locked(&curval, uaddr1);
if (unlikely(ret)) {
double_unlock_hb(hb1, hb2);
hb_waiters_dec(hb2);
ret = get_user(curval, uaddr1);
if (ret)
goto out_put_keys;
if (!(flags & FLAGS_SHARED))
goto retry_private;
put_futex_key(&key2);
put_futex_key(&key1);
goto retry;
}
if (curval != *cmpval) {
ret = -EAGAIN;
goto out_unlock;
}
}
if (requeue_pi && (task_count - nr_wake < nr_requeue)) {
ret = futex_proxy_trylock_atomic(uaddr2, hb1, hb2, &key1,
&key2, &pi_state, nr_requeue);
if (ret > 0) {
WARN_ON(pi_state);
drop_count++;
task_count++;
ret = lookup_pi_state(uaddr2, ret, hb2, &key2, &pi_state);
}
switch (ret) {
case 0:
break;
case -EFAULT:
double_unlock_hb(hb1, hb2);
hb_waiters_dec(hb2);
put_futex_key(&key2);
put_futex_key(&key1);
ret = fault_in_user_writeable(uaddr2);
if (!ret)
goto retry;
goto out;
case -EAGAIN:
double_unlock_hb(hb1, hb2);
hb_waiters_dec(hb2);
put_futex_key(&key2);
put_futex_key(&key1);
cond_resched();
goto retry;
default:
goto out_unlock;
}
}
plist_for_each_entry_safe(this, next, &hb1->chain, list) {
if (task_count - nr_wake >= nr_requeue)
break;
if (!match_futex(&this->key, &key1))
continue;
if ((requeue_pi && !this->rt_waiter) ||
(!requeue_pi && this->rt_waiter) ||
this->pi_state) {
ret = -EINVAL;
break;
}
if (++task_count <= nr_wake && !requeue_pi) {
mark_wake_futex(&wake_q, this);
continue;
}
if (requeue_pi && !match_futex(this->requeue_pi_key, &key2)) {
ret = -EINVAL;
break;
}
if (requeue_pi) {
get_pi_state(pi_state);
this->pi_state = pi_state;
ret = rt_mutex_start_proxy_lock(&pi_state->pi_mutex,
this->rt_waiter,
this->task);
if (ret == 1) {
requeue_pi_wake_futex(this, &key2, hb2);
drop_count++;
continue;
} else if (ret) {
this->pi_state = NULL;
put_pi_state(pi_state);
break;
}
}
requeue_futex(this, hb1, hb2, &key2);
drop_count++;
}
put_pi_state(pi_state);
out_unlock:
double_unlock_hb(hb1, hb2);
wake_up_q(&wake_q);
hb_waiters_dec(hb2);
while (--drop_count >= 0)
drop_futex_key_refs(&key1);
out_put_keys:
put_futex_key(&key2);
out_put_key1:
put_futex_key(&key1);
out:
return ret ? ret : task_count;
}
static inline struct futex_hash_bucket *queue_lock(struct futex_q *q)
__acquires(&hb->lock
static inline void
queue_unlock(struct futex_hash_bucket *hb)
__releases(&hb->lock
static inline void __queue_me(struct futex_q *q, struct futex_hash_bucket *hb)
{
int prio;
prio = min(current->normal_prio, MAX_RT_PRIO);
plist_node_init(&q->list, prio);
plist_add(&q->list, &hb->chain);
q->task = current;
}
static inline void queue_me(struct futex_q *q, struct futex_hash_bucket *hb)
__releases(&hb->lock
static int unqueue_me(struct futex_q *q)
{
spinlock_t *lock_ptr;
int ret = 0;
retry:
lock_ptr = READ_ONCE(q->lock_ptr);
if (lock_ptr != NULL) {
spin_lock(lock_ptr);
if (unlikely(lock_ptr != q->lock_ptr)) {
spin_unlock(lock_ptr);
goto retry;
}
__unqueue_futex(q);
BUG_ON(q->pi_state);
spin_unlock(lock_ptr);
ret = 1;
}
drop_futex_key_refs(&q->key);
return ret;
}
static void unqueue_me_pi(struct futex_q *q)
__releases(q->lock_ptr)
{
__unqueue_futex(q);
BUG_ON(!q->pi_state);
put_pi_state(q->pi_state);
q->pi_state = NULL;
spin_unlock(q->lock_ptr);
}
static int fixup_pi_state_owner(u32 __user *uaddr, struct futex_q *q,
struct task_struct *newowner)
{
u32 newtid = task_pid_vnr(newowner) | FUTEX_WAITERS;
struct futex_pi_state *pi_state = q->pi_state;
u32 uval, uninitialized_var(curval), newval;
struct task_struct *oldowner;
int ret;
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
oldowner = pi_state->owner;
if (!pi_state->owner)
newtid |= FUTEX_OWNER_DIED;
retry:
if (get_futex_value_locked(&uval, uaddr))
goto handle_fault;
for (;;) {
newval = (uval & FUTEX_OWNER_DIED) | newtid;
if (cmpxchg_futex_value_locked(&curval, uaddr, uval, newval))
goto handle_fault;
if (curval == uval)
break;
uval = curval;
}
if (pi_state->owner != NULL) {
raw_spin_lock(&pi_state->owner->pi_lock);
WARN_ON(list_empty(&pi_state->list));
list_del_init(&pi_state->list);
raw_spin_unlock(&pi_state->owner->pi_lock);
}
pi_state->owner = newowner;
raw_spin_lock(&newowner->pi_lock);
WARN_ON(!list_empty(&pi_state->list));
list_add(&pi_state->list, &newowner->pi_state_list);
raw_spin_unlock(&newowner->pi_lock);
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
return 0;
handle_fault:
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
spin_unlock(q->lock_ptr);
ret = fault_in_user_writeable(uaddr);
spin_lock(q->lock_ptr);
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
if (pi_state->owner != oldowner) {
ret = 0;
goto out_unlock;
}
if (ret)
goto out_unlock;
goto retry;
out_unlock:
raw_spin_unlock_irq(&pi_state->pi_mutex.wait_lock);
return ret;
}
static int fixup_owner(u32 __user *uaddr, struct futex_q *q, int locked)
{
int ret = 0;
if (locked) {
if (q->pi_state->owner != current)
ret = fixup_pi_state_owner(uaddr, q, current);
goto out;
}
if (rt_mutex_owner(&q->pi_state->pi_mutex) == current) {
printk(KERN_ERR "fixup_owner: ret = %d pi-mutex: %p "
"pi-state %p\n", ret,
q->pi_state->pi_mutex.owner,
q->pi_state->owner);
}
out:
return ret ? ret : locked;
}
static void futex_wait_queue_me(struct futex_hash_bucket *hb, struct futex_q *q,
struct hrtimer_sleeper *timeout)
{
set_current_state(TASK_INTERRUPTIBLE);
queue_me(q, hb);
if (timeout)
hrtimer_start_expires(&timeout->timer, HRTIMER_MODE_ABS);
if (likely(!plist_node_empty(&q->list))) {
if (!timeout || timeout->task)
freezable_schedule();
}
__set_current_state(TASK_RUNNING);
}
static int futex_wait_setup(u32 __user *uaddr, u32 val, unsigned int flags,
struct futex_q *q, struct futex_hash_bucket **hb)
{
u32 uval;
int ret;
retry:
ret = get_futex_key(uaddr, flags & FLAGS_SHARED, &q->key, VERIFY_READ);
if (unlikely(ret != 0))
return ret;
retry_private:
*hb = queue_lock(q);
ret = get_futex_value_locked(&uval, uaddr);
if (ret) {
queue_unlock(*hb);
ret = get_user(uval, uaddr);
if (ret)
goto out;
if (!(flags & FLAGS_SHARED))
goto retry_private;
put_futex_key(&q->key);
goto retry;
}
if (uval != val) {
queue_unlock(*hb);
ret = -EWOULDBLOCK;
}
out:
if (ret)
put_futex_key(&q->key);
return ret;
}
static int futex_wait(u32 __user *uaddr, unsigned int flags, u32 val,
ktime_t *abs_time, u32 bitset)
{
struct hrtimer_sleeper timeout, *to = NULL;
struct restart_block *restart;
struct futex_hash_bucket *hb;
struct futex_q q = futex_q_init;
int ret;
if (!bitset)
return -EINVAL;
q.bitset = bitset;
if (abs_time) {
to = &timeout;
hrtimer_init_on_stack(&to->timer, (flags & FLAGS_CLOCKRT) ?
CLOCK_REALTIME : CLOCK_MONOTONIC,
HRTIMER_MODE_ABS);
hrtimer_init_sleeper(to, current);
hrtimer_set_expires_range_ns(&to->timer, *abs_time,
current->timer_slack_ns);
}
retry:
ret = futex_wait_setup(uaddr, val, flags, &q, &hb);
if (ret)
goto out;
futex_wait_queue_me(hb, &q, to);
ret = 0;
if (!unqueue_me(&q))
goto out;
ret = -ETIMEDOUT;
if (to && !to->task)
goto out;
if (!signal_pending(current))
goto retry;
ret = -ERESTARTSYS;
if (!abs_time)
goto out;
restart = &current->restart_block;
restart->fn = futex_wait_restart;
restart->futex.uaddr = uaddr;
restart->futex.val = val;
restart->futex.time = *abs_time;
restart->futex.bitset = bitset;
restart->futex.flags = flags | FLAGS_HAS_TIMEOUT;
ret = -ERESTART_RESTARTBLOCK;
out:
if (to) {
hrtimer_cancel(&to->timer);
destroy_hrtimer_on_stack(&to->timer);
}
return ret;
}
static long futex_wait_restart(struct restart_block *restart)
{
u32 __user *uaddr = restart->futex.uaddr;
ktime_t t, *tp = NULL;
if (restart->futex.flags & FLAGS_HAS_TIMEOUT) {
t = restart->futex.time;
tp = &t;
}
restart->fn = do_no_restart_syscall;
return (long)futex_wait(uaddr, restart->futex.flags,
restart->futex.val, tp, restart->futex.bitset);
}
static int futex_lock_pi(u32 __user *uaddr, unsigned int flags,
ktime_t *time, int trylock)
{
struct hrtimer_sleeper timeout, *to = NULL;
struct futex_pi_state *pi_state = NULL;
struct rt_mutex_waiter rt_waiter;
struct futex_hash_bucket *hb;
struct futex_q q = futex_q_init;
int res, ret;
if (!IS_ENABLED(CONFIG_FUTEX_PI))
return -ENOSYS;
if (refill_pi_state_cache())
return -ENOMEM;
if (time) {
to = &timeout;
hrtimer_init_on_stack(&to->timer, CLOCK_REALTIME,
HRTIMER_MODE_ABS);
hrtimer_init_sleeper(to, current);
hrtimer_set_expires(&to->timer, *time);
}
retry:
ret = get_futex_key(uaddr, flags & FLAGS_SHARED, &q.key, VERIFY_WRITE);
if (unlikely(ret != 0))
goto out;
retry_private:
hb = queue_lock(&q);
ret = futex_lock_pi_atomic(uaddr, hb, &q.key, &q.pi_state, current, 0);
if (unlikely(ret)) {
switch (ret) {
case 1:
ret = 0;
goto out_unlock_put_key;
case -EFAULT:
goto uaddr_faulted;
case -EAGAIN:
queue_unlock(hb);
put_futex_key(&q.key);
cond_resched();
goto retry;
default:
goto out_unlock_put_key;
}
}
WARN_ON(!q.pi_state);
__queue_me(&q, hb);
if (trylock) {
ret = rt_mutex_futex_trylock(&q.pi_state->pi_mutex);
ret = ret ? 0 : -EWOULDBLOCK;
goto no_block;
}
rt_mutex_init_waiter(&rt_waiter);
raw_spin_lock_irq(&q.pi_state->pi_mutex.wait_lock);
spin_unlock(q.lock_ptr);
ret = __rt_mutex_start_proxy_lock(&q.pi_state->pi_mutex, &rt_waiter, current);
raw_spin_unlock_irq(&q.pi_state->pi_mutex.wait_lock);
if (ret) {
if (ret == 1)
ret = 0;
spin_lock(q.lock_ptr);
goto no_block;
}
if (unlikely(to))
hrtimer_start_expires(&to->timer, HRTIMER_MODE_ABS);
ret = rt_mutex_wait_proxy_lock(&q.pi_state->pi_mutex, to, &rt_waiter);
spin_lock(q.lock_ptr);
if (ret && !rt_mutex_cleanup_proxy_lock(&q.pi_state->pi_mutex, &rt_waiter))
ret = 0;
no_block:
res = fixup_owner(uaddr, &q, !ret);
if (res)
ret = (res < 0) ? res : 0;
if (ret && (rt_mutex_owner(&q.pi_state->pi_mutex) == current)) {
pi_state = q.pi_state;
get_pi_state(pi_state);
}
unqueue_me_pi(&q);
if (pi_state) {
rt_mutex_futex_unlock(&pi_state->pi_mutex);
put_pi_state(pi_state);
}
goto out_put_key;
out_unlock_put_key:
queue_unlock(hb);
out_put_key:
put_futex_key(&q.key);
out:
if (to) {
hrtimer_cancel(&to->timer);
destroy_hrtimer_on_stack(&to->timer);
}
return ret != -EINTR ? ret : -ERESTARTNOINTR;
uaddr_faulted:
queue_unlock(hb);
ret = fault_in_user_writeable(uaddr);
if (ret)
goto out_put_key;
if (!(flags & FLAGS_SHARED))
goto retry_private;
put_futex_key(&q.key);
goto retry;
}
static int futex_unlock_pi(u32 __user *uaddr, unsigned int flags)
{
u32 uninitialized_var(curval), uval, vpid = task_pid_vnr(current);
union futex_key key = FUTEX_KEY_INIT;
struct futex_hash_bucket *hb;
struct futex_q *top_waiter;
int ret;
if (!IS_ENABLED(CONFIG_FUTEX_PI))
return -ENOSYS;
retry:
if (get_user(uval, uaddr))
return -EFAULT;
if ((uval & FUTEX_TID_MASK) != vpid)
return -EPERM;
ret = get_futex_key(uaddr, flags & FLAGS_SHARED, &key, VERIFY_WRITE);
if (ret)
return ret;
hb = hash_futex(&key);
spin_lock(&hb->lock);
top_waiter = futex_top_waiter(hb, &key);
if (top_waiter) {
struct futex_pi_state *pi_state = top_waiter->pi_state;
ret = -EINVAL;
if (!pi_state)
goto out_unlock;
if (pi_state->owner != current)
goto out_unlock;
get_pi_state(pi_state);
raw_spin_lock_irq(&pi_state->pi_mutex.wait_lock);
spin_unlock(&hb->lock);
ret = wake_futex_pi(uaddr, uval, pi_state);
put_pi_state(pi_state);
if (!ret)
goto out_putkey;
if (ret == -EFAULT)
goto pi_faulted;
if (ret == -EAGAIN) {
put_futex_key(&key);
goto retry;
}
goto out_putkey;
}
if (cmpxchg_futex_value_locked(&curval, uaddr, uval, 0)) {
spin_unlock(&hb->lock);
goto pi_faulted;
}
ret = (curval == uval) ? 0 : -EAGAIN;
out_unlock:
spin_unlock(&hb->lock);
out_putkey:
put_futex_key(&key);
return ret;
pi_faulted:
put_futex_key(&key);
ret = fault_in_user_writeable(uaddr);
if (!ret)
goto retry;
return ret;
}
static inline
int handle_early_requeue_pi_wakeup(struct futex_hash_bucket *hb,
struct futex_q *q, union futex_key *key2,
struct hrtimer_sleeper *timeout)
{
int ret = 0;
if (!match_futex(&q->key, key2)) {
WARN_ON(q->lock_ptr && (&hb->lock != q->lock_ptr));
plist_del(&q->list, &hb->chain);
hb_waiters_dec(hb);
ret = -EWOULDBLOCK;
if (timeout && !timeout->task)
ret = -ETIMEDOUT;
else if (signal_pending(current))
ret = -ERESTARTNOINTR;
}
return ret;
}
static int futex_wait_requeue_pi(u32 __user *uaddr, unsigned int flags,
u32 val, ktime_t *abs_time, u32 bitset,
u32 __user *uaddr2)
{
struct hrtimer_sleeper timeout, *to = NULL;
struct futex_pi_state *pi_state = NULL;
struct rt_mutex_waiter rt_waiter;
struct futex_hash_bucket *hb;
union futex_key key2 = FUTEX_KEY_INIT;
struct futex_q q = futex_q_init;
int res, ret;
if (!IS_ENABLED(CONFIG_FUTEX_PI))
return -ENOSYS;
if (uaddr == uaddr2)
return -EINVAL;
if (!bitset)
return -EINVAL;
if (abs_time) {
to = &timeout;
hrtimer_init_on_stack(&to->timer, (flags & FLAGS_CLOCKRT) ?
CLOCK_REALTIME : CLOCK_MONOTONIC,
HRTIMER_MODE_ABS);
hrtimer_init_sleeper(to, current);
hrtimer_set_expires_range_ns(&to->timer, *abs_time,
current->timer_slack_ns);
}
rt_mutex_init_waiter(&rt_waiter);
ret = get_futex_key(uaddr2, flags & FLAGS_SHARED, &key2, VERIFY_WRITE);
if (unlikely(ret != 0))
goto out;
q.bitset = bitset;
q.rt_waiter = &rt_waiter;
q.requeue_pi_key = &key2;
ret = futex_wait_setup(uaddr, val, flags, &q, &hb);
if (ret)
goto out_key2;
if (match_futex(&q.key, &key2)) {
queue_unlock(hb);
ret = -EINVAL;
goto out_put_keys;
}
futex_wait_queue_me(hb, &q, to);
spin_lock(&hb->lock);
ret = handle_early_requeue_pi_wakeup(hb, &q, &key2, to);
spin_unlock(&hb->lock);
if (ret)
goto out_put_keys;
if (!q.rt_waiter) {
if (q.pi_state && (q.pi_state->owner != current)) {
spin_lock(q.lock_ptr);
ret = fixup_pi_state_owner(uaddr2, &q, current);
if (ret && rt_mutex_owner(&q.pi_state->pi_mutex) == current) {
pi_state = q.pi_state;
get_pi_state(pi_state);
}
put_pi_state(q.pi_state);
spin_unlock(q.lock_ptr);
}
} else {
struct rt_mutex *pi_mutex;
WARN_ON(!q.pi_state);
pi_mutex = &q.pi_state->pi_mutex;
ret = rt_mutex_wait_proxy_lock(pi_mutex, to, &rt_waiter);
spin_lock(q.lock_ptr);
if (ret && !rt_mutex_cleanup_proxy_lock(pi_mutex, &rt_waiter))
ret = 0;
debug_rt_mutex_free_waiter(&rt_waiter);
res = fixup_owner(uaddr2, &q, !ret);
if (res)
ret = (res < 0) ? res : 0;
if (ret && rt_mutex_owner(&q.pi_state->pi_mutex) == current) {
pi_state = q.pi_state;
get_pi_state(pi_state);
}
unqueue_me_pi(&q);
}
if (pi_state) {
rt_mutex_futex_unlock(&pi_state->pi_mutex);
put_pi_state(pi_state);
}
if (ret == -EINTR) {
ret = -EWOULDBLOCK;
}
out_put_keys:
put_futex_key(&q.key);
out_key2:
put_futex_key(&key2);
out:
if (to) {
hrtimer_cancel(&to->timer);
destroy_hrtimer_on_stack(&to->timer);
}
return ret;
}
int handle_futex_death(u32 __user *uaddr, struct task_struct *curr, int pi)
{
u32 uval, uninitialized_var(nval), mval;
retry:
if (get_user(uval, uaddr))
return -1;
if ((uval & FUTEX_TID_MASK) == task_pid_vnr(curr)) {
mval = (uval & FUTEX_WAITERS) | FUTEX_OWNER_DIED;
if (cmpxchg_futex_value_locked(&nval, uaddr, uval, mval)) {
if (fault_in_user_writeable(uaddr))
return -1;
goto retry;
}
if (nval != uval)
goto retry;
if (!pi && (uval & FUTEX_WAITERS))
futex_wake(uaddr, 1, 1, FUTEX_BITSET_MATCH_ANY);
}
return 0;
}
static inline int fetch_robust_entry(struct robust_list __user **entry,
struct robust_list __user * __user *head,
unsigned int *pi)
{
unsigned long uentry;
if (get_user(uentry, (unsigned long __user *)head))
return -EFAULT;
*entry = (void __user *)(uentry & ~1UL);
*pi = uentry & 1;
return 0;
}
void exit_robust_list(struct task_struct *curr)
{
struct robust_list_head __user *head = curr->robust_list;
struct robust_list __user *entry, *next_entry, *pending;
unsigned int limit = ROBUST_LIST_LIMIT, pi, pip;
unsigned int uninitialized_var(next_pi);
unsigned long futex_offset;
int rc;
if (!futex_cmpxchg_enabled)
return;
if (fetch_robust_entry(&entry, &head->list.next, &pi))
return;
if (get_user(futex_offset, &head->futex_offset))
return;
if (fetch_robust_entry(&pending, &head->list_op_pending, &pip))
return;
next_entry = NULL;
while (entry != &head->list) {
rc = fetch_robust_entry(&next_entry, &entry->next, &next_pi);
if (entry != pending)
if (handle_futex_death((void __user *)entry + futex_offset,
curr, pi))
return;
if (rc)
return;
entry = next_entry;
pi = next_pi;
if (!--limit)
break;
cond_resched();
}
if (pending)
handle_futex_death((void __user *)pending + futex_offset,
curr, pip);
}
long do_futex(u32 __user *uaddr, int op, u32 val, ktime_t *timeout,
u32 __user *uaddr2, u32 val2, u32 val3)
{
int cmd = op & FUTEX_CMD_MASK;
unsigned int flags = 0;
if (!(op & FUTEX_PRIVATE_FLAG))
flags |= FLAGS_SHARED;
if (op & FUTEX_CLOCK_REALTIME) {
flags |= FLAGS_CLOCKRT;
if (cmd != FUTEX_WAIT && cmd != FUTEX_WAIT_BITSET && \
cmd != FUTEX_WAIT_REQUEUE_PI)
return -ENOSYS;
}
switch (cmd) {
case FUTEX_LOCK_PI:
case FUTEX_UNLOCK_PI:
case FUTEX_TRYLOCK_PI:
case FUTEX_WAIT_REQUEUE_PI:
case FUTEX_CMP_REQUEUE_PI:
if (!futex_cmpxchg_enabled)
return -ENOSYS;
}
switch (cmd) {
case FUTEX_WAIT:
val3 = FUTEX_BITSET_MATCH_ANY;
case FUTEX_WAIT_BITSET:
return futex_wait(uaddr, flags, val, timeout, val3);
case FUTEX_WAKE:
val3 = FUTEX_BITSET_MATCH_ANY;
case FUTEX_WAKE_BITSET:
return futex_wake(uaddr, flags, val, val3);
case FUTEX_REQUEUE:
return futex_requeue(uaddr, flags, uaddr2, val, val2, NULL, 0);
case FUTEX_CMP_REQUEUE:
return futex_requeue(uaddr, flags, uaddr2, val, val2, &val3, 0);
case FUTEX_WAKE_OP:
return futex_wake_op(uaddr, flags, uaddr2, val, val2, val3);
case FUTEX_LOCK_PI:
return futex_lock_pi(uaddr, flags, timeout, 0);
case FUTEX_UNLOCK_PI:
return futex_unlock_pi(uaddr, flags);
case FUTEX_TRYLOCK_PI:
return futex_lock_pi(uaddr, flags, NULL, 1);
case FUTEX_WAIT_REQUEUE_PI:
val3 = FUTEX_BITSET_MATCH_ANY;
return futex_wait_requeue_pi(uaddr, flags, val, timeout, val3,
uaddr2);
case FUTEX_CMP_REQUEUE_PI:
return futex_requeue(uaddr, flags, uaddr2, val, val2, &val3, 1);
}
return -ENOSYS;
}
static void __init futex_detect_cmpxchg(void)
{
#ifndef CONFIG_HAVE_FUTEX_CMPXCHG
u32 curval;
if (cmpxchg_futex_value_locked(&curval, NULL, 0, 0) == -EFAULT)
futex_cmpxchg_enabled = 1;
#endif
}
static int __init futex_init(void)
{
unsigned int futex_shift;
unsigned long i;
#if CONFIG_BASE_SMALL
futex_hashsize = 16;
#else
futex_hashsize = roundup_pow_of_two(256 * num_possible_cpus());
#endif
futex_queues = alloc_large_system_hash("futex", sizeof(*futex_queues),
futex_hashsize, 0,
futex_hashsize < 256 ? HASH_SMALL : 0,
&futex_shift, NULL,
futex_hashsize, futex_hashsize);
futex_hashsize = 1UL << futex_shift;
futex_detect_cmpxchg();
for (i = 0; i < futex_hashsize; i++) {
atomic_set(&futex_queues[i].waiters, 0);
plist_head_init(&futex_queues[i].chain);
spin_lock_init(&futex_queues[i].lock);
}
return 0;
}
