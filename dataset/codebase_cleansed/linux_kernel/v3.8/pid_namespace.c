static struct kmem_cache *create_pid_cachep(int nr_ids)
{
struct pid_cache *pcache;
struct kmem_cache *cachep;
mutex_lock(&pid_caches_mutex);
list_for_each_entry(pcache, &pid_caches_lh, list)
if (pcache->nr_ids == nr_ids)
goto out;
pcache = kmalloc(sizeof(struct pid_cache), GFP_KERNEL);
if (pcache == NULL)
goto err_alloc;
snprintf(pcache->name, sizeof(pcache->name), "pid_%d", nr_ids);
cachep = kmem_cache_create(pcache->name,
sizeof(struct pid) + (nr_ids - 1) * sizeof(struct upid),
0, SLAB_HWCACHE_ALIGN, NULL);
if (cachep == NULL)
goto err_cachep;
pcache->nr_ids = nr_ids;
pcache->cachep = cachep;
list_add(&pcache->list, &pid_caches_lh);
out:
mutex_unlock(&pid_caches_mutex);
return pcache->cachep;
err_cachep:
kfree(pcache);
err_alloc:
mutex_unlock(&pid_caches_mutex);
return NULL;
}
static void proc_cleanup_work(struct work_struct *work)
{
struct pid_namespace *ns = container_of(work, struct pid_namespace, proc_work);
pid_ns_release_proc(ns);
}
static struct pid_namespace *create_pid_namespace(struct user_namespace *user_ns,
struct pid_namespace *parent_pid_ns)
{
struct pid_namespace *ns;
unsigned int level = parent_pid_ns->level + 1;
int i;
int err;
if (level > MAX_PID_NS_LEVEL) {
err = -EINVAL;
goto out;
}
err = -ENOMEM;
ns = kmem_cache_zalloc(pid_ns_cachep, GFP_KERNEL);
if (ns == NULL)
goto out;
ns->pidmap[0].page = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!ns->pidmap[0].page)
goto out_free;
ns->pid_cachep = create_pid_cachep(level + 1);
if (ns->pid_cachep == NULL)
goto out_free_map;
err = proc_alloc_inum(&ns->proc_inum);
if (err)
goto out_free_map;
kref_init(&ns->kref);
ns->level = level;
ns->parent = get_pid_ns(parent_pid_ns);
ns->user_ns = get_user_ns(user_ns);
ns->nr_hashed = PIDNS_HASH_ADDING;
INIT_WORK(&ns->proc_work, proc_cleanup_work);
set_bit(0, ns->pidmap[0].page);
atomic_set(&ns->pidmap[0].nr_free, BITS_PER_PAGE - 1);
for (i = 1; i < PIDMAP_ENTRIES; i++)
atomic_set(&ns->pidmap[i].nr_free, BITS_PER_PAGE);
return ns;
out_free_map:
kfree(ns->pidmap[0].page);
out_free:
kmem_cache_free(pid_ns_cachep, ns);
out:
return ERR_PTR(err);
}
static void destroy_pid_namespace(struct pid_namespace *ns)
{
int i;
proc_free_inum(ns->proc_inum);
for (i = 0; i < PIDMAP_ENTRIES; i++)
kfree(ns->pidmap[i].page);
put_user_ns(ns->user_ns);
kmem_cache_free(pid_ns_cachep, ns);
}
struct pid_namespace *copy_pid_ns(unsigned long flags,
struct user_namespace *user_ns, struct pid_namespace *old_ns)
{
if (!(flags & CLONE_NEWPID))
return get_pid_ns(old_ns);
if (task_active_pid_ns(current) != old_ns)
return ERR_PTR(-EINVAL);
return create_pid_namespace(user_ns, old_ns);
}
static void free_pid_ns(struct kref *kref)
{
struct pid_namespace *ns;
ns = container_of(kref, struct pid_namespace, kref);
destroy_pid_namespace(ns);
}
void put_pid_ns(struct pid_namespace *ns)
{
struct pid_namespace *parent;
while (ns != &init_pid_ns) {
parent = ns->parent;
if (!kref_put(&ns->kref, free_pid_ns))
break;
ns = parent;
}
}
void zap_pid_ns_processes(struct pid_namespace *pid_ns)
{
int nr;
int rc;
struct task_struct *task, *me = current;
disable_pid_allocation(pid_ns);
spin_lock_irq(&me->sighand->siglock);
me->sighand->action[SIGCHLD - 1].sa.sa_handler = SIG_IGN;
spin_unlock_irq(&me->sighand->siglock);
read_lock(&tasklist_lock);
nr = next_pidmap(pid_ns, 1);
while (nr > 0) {
rcu_read_lock();
task = pid_task(find_vpid(nr), PIDTYPE_PID);
if (task && !__fatal_signal_pending(task))
send_sig_info(SIGKILL, SEND_SIG_FORCED, task);
rcu_read_unlock();
nr = next_pidmap(pid_ns, nr);
}
read_unlock(&tasklist_lock);
do {
clear_thread_flag(TIF_SIGPENDING);
rc = sys_wait4(-1, NULL, __WALL, NULL);
} while (rc != -ECHILD);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (pid_ns->nr_hashed == 1)
break;
schedule();
}
__set_current_state(TASK_RUNNING);
if (pid_ns->reboot)
current->signal->group_exit_code = pid_ns->reboot;
acct_exit_ns(pid_ns);
return;
}
static int pid_ns_ctl_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct pid_namespace *pid_ns = task_active_pid_ns(current);
struct ctl_table tmp = *table;
if (write && !ns_capable(pid_ns->user_ns, CAP_SYS_ADMIN))
return -EPERM;
tmp.data = &pid_ns->last_pid;
return proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
}
int reboot_pid_ns(struct pid_namespace *pid_ns, int cmd)
{
if (pid_ns == &init_pid_ns)
return 0;
switch (cmd) {
case LINUX_REBOOT_CMD_RESTART2:
case LINUX_REBOOT_CMD_RESTART:
pid_ns->reboot = SIGHUP;
break;
case LINUX_REBOOT_CMD_POWER_OFF:
case LINUX_REBOOT_CMD_HALT:
pid_ns->reboot = SIGINT;
break;
default:
return -EINVAL;
}
read_lock(&tasklist_lock);
force_sig(SIGKILL, pid_ns->child_reaper);
read_unlock(&tasklist_lock);
do_exit(0);
return 0;
}
static void *pidns_get(struct task_struct *task)
{
struct pid_namespace *ns;
rcu_read_lock();
ns = get_pid_ns(task_active_pid_ns(task));
rcu_read_unlock();
return ns;
}
static void pidns_put(void *ns)
{
put_pid_ns(ns);
}
static int pidns_install(struct nsproxy *nsproxy, void *ns)
{
struct pid_namespace *active = task_active_pid_ns(current);
struct pid_namespace *ancestor, *new = ns;
if (!ns_capable(new->user_ns, CAP_SYS_ADMIN) ||
!nsown_capable(CAP_SYS_ADMIN))
return -EPERM;
if (new->level < active->level)
return -EINVAL;
ancestor = new;
while (ancestor->level > active->level)
ancestor = ancestor->parent;
if (ancestor != active)
return -EINVAL;
put_pid_ns(nsproxy->pid_ns);
nsproxy->pid_ns = get_pid_ns(new);
return 0;
}
static unsigned int pidns_inum(void *ns)
{
struct pid_namespace *pid_ns = ns;
return pid_ns->proc_inum;
}
static __init int pid_namespaces_init(void)
{
pid_ns_cachep = KMEM_CACHE(pid_namespace, SLAB_PANIC);
#ifdef CONFIG_CHECKPOINT_RESTORE
register_sysctl_paths(kern_path, pid_ns_ctl_table);
#endif
return 0;
}
