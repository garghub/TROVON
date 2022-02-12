static inline int mk_pid(struct pid_namespace *pid_ns,
struct pidmap *map, int off)
{
return (map - pid_ns->pidmap)*BITS_PER_PAGE + off;
}
static void free_pidmap(struct upid *upid)
{
int nr = upid->nr;
struct pidmap *map = upid->ns->pidmap + nr / BITS_PER_PAGE;
int offset = nr & BITS_PER_PAGE_MASK;
clear_bit(offset, map->page);
atomic_inc(&map->nr_free);
}
static int pid_before(int base, int a, int b)
{
return (unsigned)(a - base) < (unsigned)(b - base);
}
static void set_last_pid(struct pid_namespace *pid_ns, int base, int pid)
{
int prev;
int last_write = base;
do {
prev = last_write;
last_write = cmpxchg(&pid_ns->last_pid, prev, pid);
} while ((prev != last_write) && (pid_before(base, last_write, pid)));
}
static int alloc_pidmap(struct pid_namespace *pid_ns)
{
int i, offset, max_scan, pid, last = pid_ns->last_pid;
struct pidmap *map;
pid = last + 1;
if (pid >= pid_max)
pid = RESERVED_PIDS;
offset = pid & BITS_PER_PAGE_MASK;
map = &pid_ns->pidmap[pid/BITS_PER_PAGE];
max_scan = DIV_ROUND_UP(pid_max, BITS_PER_PAGE) - !offset;
for (i = 0; i <= max_scan; ++i) {
if (unlikely(!map->page)) {
void *page = kzalloc(PAGE_SIZE, GFP_KERNEL);
spin_lock_irq(&pidmap_lock);
if (!map->page) {
map->page = page;
page = NULL;
}
spin_unlock_irq(&pidmap_lock);
kfree(page);
if (unlikely(!map->page))
break;
}
if (likely(atomic_read(&map->nr_free))) {
do {
if (!test_and_set_bit(offset, map->page)) {
atomic_dec(&map->nr_free);
set_last_pid(pid_ns, last, pid);
return pid;
}
offset = find_next_offset(map, offset);
pid = mk_pid(pid_ns, map, offset);
} while (offset < BITS_PER_PAGE && pid < pid_max);
}
if (map < &pid_ns->pidmap[(pid_max-1)/BITS_PER_PAGE]) {
++map;
offset = 0;
} else {
map = &pid_ns->pidmap[0];
offset = RESERVED_PIDS;
if (unlikely(last == offset))
break;
}
pid = mk_pid(pid_ns, map, offset);
}
return -1;
}
int next_pidmap(struct pid_namespace *pid_ns, unsigned int last)
{
int offset;
struct pidmap *map, *end;
if (last >= PID_MAX_LIMIT)
return -1;
offset = (last + 1) & BITS_PER_PAGE_MASK;
map = &pid_ns->pidmap[(last + 1)/BITS_PER_PAGE];
end = &pid_ns->pidmap[PIDMAP_ENTRIES];
for (; map < end; map++, offset = 0) {
if (unlikely(!map->page))
continue;
offset = find_next_bit((map)->page, BITS_PER_PAGE, offset);
if (offset < BITS_PER_PAGE)
return mk_pid(pid_ns, map, offset);
}
return -1;
}
void put_pid(struct pid *pid)
{
struct pid_namespace *ns;
if (!pid)
return;
ns = pid->numbers[pid->level].ns;
if ((atomic_read(&pid->count) == 1) ||
atomic_dec_and_test(&pid->count)) {
kmem_cache_free(ns->pid_cachep, pid);
put_pid_ns(ns);
}
}
static void delayed_put_pid(struct rcu_head *rhp)
{
struct pid *pid = container_of(rhp, struct pid, rcu);
put_pid(pid);
}
void free_pid(struct pid *pid)
{
int i;
unsigned long flags;
spin_lock_irqsave(&pidmap_lock, flags);
for (i = 0; i <= pid->level; i++) {
struct upid *upid = pid->numbers + i;
struct pid_namespace *ns = upid->ns;
hlist_del_rcu(&upid->pid_chain);
switch(--ns->nr_hashed) {
case 1:
wake_up_process(ns->child_reaper);
break;
case 0:
schedule_work(&ns->proc_work);
break;
}
}
spin_unlock_irqrestore(&pidmap_lock, flags);
for (i = 0; i <= pid->level; i++)
free_pidmap(pid->numbers + i);
call_rcu(&pid->rcu, delayed_put_pid);
}
struct pid *alloc_pid(struct pid_namespace *ns)
{
struct pid *pid;
enum pid_type type;
int i, nr;
struct pid_namespace *tmp;
struct upid *upid;
pid = kmem_cache_alloc(ns->pid_cachep, GFP_KERNEL);
if (!pid)
goto out;
tmp = ns;
pid->level = ns->level;
for (i = ns->level; i >= 0; i--) {
nr = alloc_pidmap(tmp);
if (nr < 0)
goto out_free;
pid->numbers[i].nr = nr;
pid->numbers[i].ns = tmp;
tmp = tmp->parent;
}
if (unlikely(is_child_reaper(pid))) {
if (pid_ns_prepare_proc(ns))
goto out_free;
}
get_pid_ns(ns);
atomic_set(&pid->count, 1);
for (type = 0; type < PIDTYPE_MAX; ++type)
INIT_HLIST_HEAD(&pid->tasks[type]);
upid = pid->numbers + ns->level;
spin_lock_irq(&pidmap_lock);
if (!(ns->nr_hashed & PIDNS_HASH_ADDING))
goto out_unlock;
for ( ; upid >= pid->numbers; --upid) {
hlist_add_head_rcu(&upid->pid_chain,
&pid_hash[pid_hashfn(upid->nr, upid->ns)]);
upid->ns->nr_hashed++;
}
spin_unlock_irq(&pidmap_lock);
out:
return pid;
out_unlock:
spin_unlock_irq(&pidmap_lock);
out_free:
while (++i <= ns->level)
free_pidmap(pid->numbers + i);
kmem_cache_free(ns->pid_cachep, pid);
pid = NULL;
goto out;
}
void disable_pid_allocation(struct pid_namespace *ns)
{
spin_lock_irq(&pidmap_lock);
ns->nr_hashed &= ~PIDNS_HASH_ADDING;
spin_unlock_irq(&pidmap_lock);
}
struct pid *find_pid_ns(int nr, struct pid_namespace *ns)
{
struct upid *pnr;
hlist_for_each_entry_rcu(pnr,
&pid_hash[pid_hashfn(nr, ns)], pid_chain)
if (pnr->nr == nr && pnr->ns == ns)
return container_of(pnr, struct pid,
numbers[ns->level]);
return NULL;
}
struct pid *find_vpid(int nr)
{
return find_pid_ns(nr, task_active_pid_ns(current));
}
void attach_pid(struct task_struct *task, enum pid_type type,
struct pid *pid)
{
struct pid_link *link;
link = &task->pids[type];
link->pid = pid;
hlist_add_head_rcu(&link->node, &pid->tasks[type]);
}
static void __change_pid(struct task_struct *task, enum pid_type type,
struct pid *new)
{
struct pid_link *link;
struct pid *pid;
int tmp;
link = &task->pids[type];
pid = link->pid;
hlist_del_rcu(&link->node);
link->pid = new;
for (tmp = PIDTYPE_MAX; --tmp >= 0; )
if (!hlist_empty(&pid->tasks[tmp]))
return;
free_pid(pid);
}
void detach_pid(struct task_struct *task, enum pid_type type)
{
__change_pid(task, type, NULL);
}
void change_pid(struct task_struct *task, enum pid_type type,
struct pid *pid)
{
__change_pid(task, type, pid);
attach_pid(task, type, pid);
}
void transfer_pid(struct task_struct *old, struct task_struct *new,
enum pid_type type)
{
new->pids[type].pid = old->pids[type].pid;
hlist_replace_rcu(&old->pids[type].node, &new->pids[type].node);
}
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
{
struct task_struct *result = NULL;
if (pid) {
struct hlist_node *first;
first = rcu_dereference_check(hlist_first_rcu(&pid->tasks[type]),
lockdep_tasklist_lock_is_held());
if (first)
result = hlist_entry(first, struct task_struct, pids[(type)].node);
}
return result;
}
struct task_struct *find_task_by_pid_ns(pid_t nr, struct pid_namespace *ns)
{
rcu_lockdep_assert(rcu_read_lock_held(),
"find_task_by_pid_ns() needs rcu_read_lock()"
" protection");
return pid_task(find_pid_ns(nr, ns), PIDTYPE_PID);
}
struct task_struct *find_task_by_vpid(pid_t vnr)
{
return find_task_by_pid_ns(vnr, task_active_pid_ns(current));
}
struct pid *get_task_pid(struct task_struct *task, enum pid_type type)
{
struct pid *pid;
rcu_read_lock();
if (type != PIDTYPE_PID)
task = task->group_leader;
pid = get_pid(task->pids[type].pid);
rcu_read_unlock();
return pid;
}
struct task_struct *get_pid_task(struct pid *pid, enum pid_type type)
{
struct task_struct *result;
rcu_read_lock();
result = pid_task(pid, type);
if (result)
get_task_struct(result);
rcu_read_unlock();
return result;
}
struct pid *find_get_pid(pid_t nr)
{
struct pid *pid;
rcu_read_lock();
pid = get_pid(find_vpid(nr));
rcu_read_unlock();
return pid;
}
pid_t pid_nr_ns(struct pid *pid, struct pid_namespace *ns)
{
struct upid *upid;
pid_t nr = 0;
if (pid && ns->level <= pid->level) {
upid = &pid->numbers[ns->level];
if (upid->ns == ns)
nr = upid->nr;
}
return nr;
}
pid_t pid_vnr(struct pid *pid)
{
return pid_nr_ns(pid, task_active_pid_ns(current));
}
pid_t __task_pid_nr_ns(struct task_struct *task, enum pid_type type,
struct pid_namespace *ns)
{
pid_t nr = 0;
rcu_read_lock();
if (!ns)
ns = task_active_pid_ns(current);
if (likely(pid_alive(task))) {
if (type != PIDTYPE_PID)
task = task->group_leader;
nr = pid_nr_ns(task->pids[type].pid, ns);
}
rcu_read_unlock();
return nr;
}
pid_t task_tgid_nr_ns(struct task_struct *tsk, struct pid_namespace *ns)
{
return pid_nr_ns(task_tgid(tsk), ns);
}
struct pid_namespace *task_active_pid_ns(struct task_struct *tsk)
{
return ns_of_pid(task_pid(tsk));
}
struct pid *find_ge_pid(int nr, struct pid_namespace *ns)
{
struct pid *pid;
do {
pid = find_pid_ns(nr, ns);
if (pid)
break;
nr = next_pidmap(ns, nr);
} while (nr > 0);
return pid;
}
void __init pidhash_init(void)
{
unsigned int i, pidhash_size;
pid_hash = alloc_large_system_hash("PID", sizeof(*pid_hash), 0, 18,
HASH_EARLY | HASH_SMALL,
&pidhash_shift, NULL,
0, 4096);
pidhash_size = 1U << pidhash_shift;
for (i = 0; i < pidhash_size; i++)
INIT_HLIST_HEAD(&pid_hash[i]);
}
void __init pidmap_init(void)
{
BUILD_BUG_ON(PID_MAX_LIMIT >= PIDNS_HASH_ADDING);
pid_max = min(pid_max_max, max_t(int, pid_max,
PIDS_PER_CPU_DEFAULT * num_possible_cpus()));
pid_max_min = max_t(int, pid_max_min,
PIDS_PER_CPU_MIN * num_possible_cpus());
pr_info("pid_max: default: %u minimum: %u\n", pid_max, pid_max_min);
init_pid_ns.pidmap[0].page = kzalloc(PAGE_SIZE, GFP_KERNEL);
set_bit(0, init_pid_ns.pidmap[0].page);
atomic_dec(&init_pid_ns.pidmap[0].nr_free);
init_pid_ns.nr_hashed = PIDNS_HASH_ADDING;
init_pid_ns.pid_cachep = KMEM_CACHE(pid,
SLAB_HWCACHE_ALIGN | SLAB_PANIC);
}
