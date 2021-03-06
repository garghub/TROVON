static struct net_generic *net_alloc_generic(void)
{
struct net_generic *ng;
size_t generic_size = offsetof(struct net_generic, ptr[max_gen_ptrs]);
ng = kzalloc(generic_size, GFP_KERNEL);
if (ng)
ng->len = max_gen_ptrs;
return ng;
}
static int net_assign_generic(struct net *net, int id, void *data)
{
struct net_generic *ng, *old_ng;
BUG_ON(!mutex_is_locked(&net_mutex));
BUG_ON(id == 0);
old_ng = rcu_dereference_protected(net->gen,
lockdep_is_held(&net_mutex));
ng = old_ng;
if (old_ng->len >= id)
goto assign;
ng = net_alloc_generic();
if (ng == NULL)
return -ENOMEM;
memcpy(&ng->ptr, &old_ng->ptr, old_ng->len * sizeof(void*));
rcu_assign_pointer(net->gen, ng);
kfree_rcu(old_ng, rcu);
assign:
ng->ptr[id - 1] = data;
return 0;
}
static int ops_init(const struct pernet_operations *ops, struct net *net)
{
int err = -ENOMEM;
void *data = NULL;
if (ops->id && ops->size) {
data = kzalloc(ops->size, GFP_KERNEL);
if (!data)
goto out;
err = net_assign_generic(net, *ops->id, data);
if (err)
goto cleanup;
}
err = 0;
if (ops->init)
err = ops->init(net);
if (!err)
return 0;
cleanup:
kfree(data);
out:
return err;
}
static void ops_free(const struct pernet_operations *ops, struct net *net)
{
if (ops->id && ops->size) {
int id = *ops->id;
kfree(net_generic(net, id));
}
}
static void ops_exit_list(const struct pernet_operations *ops,
struct list_head *net_exit_list)
{
struct net *net;
if (ops->exit) {
list_for_each_entry(net, net_exit_list, exit_list)
ops->exit(net);
}
if (ops->exit_batch)
ops->exit_batch(net_exit_list);
}
static void ops_free_list(const struct pernet_operations *ops,
struct list_head *net_exit_list)
{
struct net *net;
if (ops->size && ops->id) {
list_for_each_entry(net, net_exit_list, exit_list)
ops_free(ops, net);
}
}
static __net_init int setup_net(struct net *net, struct user_namespace *user_ns)
{
const struct pernet_operations *ops, *saved_ops;
int error = 0;
LIST_HEAD(net_exit_list);
atomic_set(&net->count, 1);
atomic_set(&net->passive, 1);
net->dev_base_seq = 1;
net->user_ns = user_ns;
#ifdef NETNS_REFCNT_DEBUG
atomic_set(&net->use_count, 0);
#endif
list_for_each_entry(ops, &pernet_list, list) {
error = ops_init(ops, net);
if (error < 0)
goto out_undo;
}
out:
return error;
out_undo:
list_add(&net->exit_list, &net_exit_list);
saved_ops = ops;
list_for_each_entry_continue_reverse(ops, &pernet_list, list)
ops_exit_list(ops, &net_exit_list);
ops = saved_ops;
list_for_each_entry_continue_reverse(ops, &pernet_list, list)
ops_free_list(ops, &net_exit_list);
rcu_barrier();
goto out;
}
static struct net *net_alloc(void)
{
struct net *net = NULL;
struct net_generic *ng;
ng = net_alloc_generic();
if (!ng)
goto out;
net = kmem_cache_zalloc(net_cachep, GFP_KERNEL);
if (!net)
goto out_free;
rcu_assign_pointer(net->gen, ng);
out:
return net;
out_free:
kfree(ng);
goto out;
}
static void net_free(struct net *net)
{
#ifdef NETNS_REFCNT_DEBUG
if (unlikely(atomic_read(&net->use_count) != 0)) {
pr_emerg("network namespace not free! Usage: %d\n",
atomic_read(&net->use_count));
return;
}
#endif
kfree(rcu_access_pointer(net->gen));
kmem_cache_free(net_cachep, net);
}
void net_drop_ns(void *p)
{
struct net *ns = p;
if (ns && atomic_dec_and_test(&ns->passive))
net_free(ns);
}
struct net *copy_net_ns(unsigned long flags,
struct user_namespace *user_ns, struct net *old_net)
{
struct net *net;
int rv;
if (!(flags & CLONE_NEWNET))
return get_net(old_net);
net = net_alloc();
if (!net)
return ERR_PTR(-ENOMEM);
get_user_ns(user_ns);
mutex_lock(&net_mutex);
rv = setup_net(net, user_ns);
if (rv == 0) {
rtnl_lock();
list_add_tail_rcu(&net->list, &net_namespace_list);
rtnl_unlock();
}
mutex_unlock(&net_mutex);
if (rv < 0) {
put_user_ns(user_ns);
net_drop_ns(net);
return ERR_PTR(rv);
}
return net;
}
static void cleanup_net(struct work_struct *work)
{
const struct pernet_operations *ops;
struct net *net, *tmp;
struct list_head net_kill_list;
LIST_HEAD(net_exit_list);
spin_lock_irq(&cleanup_list_lock);
list_replace_init(&cleanup_list, &net_kill_list);
spin_unlock_irq(&cleanup_list_lock);
mutex_lock(&net_mutex);
rtnl_lock();
list_for_each_entry(net, &net_kill_list, cleanup_list) {
list_del_rcu(&net->list);
list_add_tail(&net->exit_list, &net_exit_list);
}
rtnl_unlock();
synchronize_rcu();
list_for_each_entry_reverse(ops, &pernet_list, list)
ops_exit_list(ops, &net_exit_list);
list_for_each_entry_reverse(ops, &pernet_list, list)
ops_free_list(ops, &net_exit_list);
mutex_unlock(&net_mutex);
rcu_barrier();
list_for_each_entry_safe(net, tmp, &net_exit_list, exit_list) {
list_del_init(&net->exit_list);
put_user_ns(net->user_ns);
net_drop_ns(net);
}
}
void __put_net(struct net *net)
{
unsigned long flags;
spin_lock_irqsave(&cleanup_list_lock, flags);
list_add(&net->cleanup_list, &cleanup_list);
spin_unlock_irqrestore(&cleanup_list_lock, flags);
queue_work(netns_wq, &net_cleanup_work);
}
struct net *get_net_ns_by_fd(int fd)
{
struct proc_ns *ei;
struct file *file;
struct net *net;
file = proc_ns_fget(fd);
if (IS_ERR(file))
return ERR_CAST(file);
ei = get_proc_ns(file_inode(file));
if (ei->ns_ops == &netns_operations)
net = get_net(ei->ns);
else
net = ERR_PTR(-EINVAL);
fput(file);
return net;
}
struct net *get_net_ns_by_fd(int fd)
{
return ERR_PTR(-EINVAL);
}
struct net *get_net_ns_by_pid(pid_t pid)
{
struct task_struct *tsk;
struct net *net;
net = ERR_PTR(-ESRCH);
rcu_read_lock();
tsk = find_task_by_vpid(pid);
if (tsk) {
struct nsproxy *nsproxy;
task_lock(tsk);
nsproxy = tsk->nsproxy;
if (nsproxy)
net = get_net(nsproxy->net_ns);
task_unlock(tsk);
}
rcu_read_unlock();
return net;
}
static __net_init int net_ns_net_init(struct net *net)
{
return proc_alloc_inum(&net->proc_inum);
}
static __net_exit void net_ns_net_exit(struct net *net)
{
proc_free_inum(net->proc_inum);
}
static int __init net_ns_init(void)
{
struct net_generic *ng;
#ifdef CONFIG_NET_NS
net_cachep = kmem_cache_create("net_namespace", sizeof(struct net),
SMP_CACHE_BYTES,
SLAB_PANIC, NULL);
netns_wq = create_singlethread_workqueue("netns");
if (!netns_wq)
panic("Could not create netns workq");
#endif
ng = net_alloc_generic();
if (!ng)
panic("Could not allocate generic netns");
rcu_assign_pointer(init_net.gen, ng);
mutex_lock(&net_mutex);
if (setup_net(&init_net, &init_user_ns))
panic("Could not setup the initial network namespace");
rtnl_lock();
list_add_tail_rcu(&init_net.list, &net_namespace_list);
rtnl_unlock();
mutex_unlock(&net_mutex);
register_pernet_subsys(&net_ns_ops);
return 0;
}
static int __register_pernet_operations(struct list_head *list,
struct pernet_operations *ops)
{
struct net *net;
int error;
LIST_HEAD(net_exit_list);
list_add_tail(&ops->list, list);
if (ops->init || (ops->id && ops->size)) {
for_each_net(net) {
error = ops_init(ops, net);
if (error)
goto out_undo;
list_add_tail(&net->exit_list, &net_exit_list);
}
}
return 0;
out_undo:
list_del(&ops->list);
ops_exit_list(ops, &net_exit_list);
ops_free_list(ops, &net_exit_list);
return error;
}
static void __unregister_pernet_operations(struct pernet_operations *ops)
{
struct net *net;
LIST_HEAD(net_exit_list);
list_del(&ops->list);
for_each_net(net)
list_add_tail(&net->exit_list, &net_exit_list);
ops_exit_list(ops, &net_exit_list);
ops_free_list(ops, &net_exit_list);
}
static int __register_pernet_operations(struct list_head *list,
struct pernet_operations *ops)
{
return ops_init(ops, &init_net);
}
static void __unregister_pernet_operations(struct pernet_operations *ops)
{
LIST_HEAD(net_exit_list);
list_add(&init_net.exit_list, &net_exit_list);
ops_exit_list(ops, &net_exit_list);
ops_free_list(ops, &net_exit_list);
}
static int register_pernet_operations(struct list_head *list,
struct pernet_operations *ops)
{
int error;
if (ops->id) {
again:
error = ida_get_new_above(&net_generic_ids, 1, ops->id);
if (error < 0) {
if (error == -EAGAIN) {
ida_pre_get(&net_generic_ids, GFP_KERNEL);
goto again;
}
return error;
}
max_gen_ptrs = max_t(unsigned int, max_gen_ptrs, *ops->id);
}
error = __register_pernet_operations(list, ops);
if (error) {
rcu_barrier();
if (ops->id)
ida_remove(&net_generic_ids, *ops->id);
}
return error;
}
static void unregister_pernet_operations(struct pernet_operations *ops)
{
__unregister_pernet_operations(ops);
rcu_barrier();
if (ops->id)
ida_remove(&net_generic_ids, *ops->id);
}
int register_pernet_subsys(struct pernet_operations *ops)
{
int error;
mutex_lock(&net_mutex);
error = register_pernet_operations(first_device, ops);
mutex_unlock(&net_mutex);
return error;
}
void unregister_pernet_subsys(struct pernet_operations *ops)
{
mutex_lock(&net_mutex);
unregister_pernet_operations(ops);
mutex_unlock(&net_mutex);
}
int register_pernet_device(struct pernet_operations *ops)
{
int error;
mutex_lock(&net_mutex);
error = register_pernet_operations(&pernet_list, ops);
if (!error && (first_device == &pernet_list))
first_device = &ops->list;
mutex_unlock(&net_mutex);
return error;
}
void unregister_pernet_device(struct pernet_operations *ops)
{
mutex_lock(&net_mutex);
if (&ops->list == first_device)
first_device = first_device->next;
unregister_pernet_operations(ops);
mutex_unlock(&net_mutex);
}
static void *netns_get(struct task_struct *task)
{
struct net *net = NULL;
struct nsproxy *nsproxy;
task_lock(task);
nsproxy = task->nsproxy;
if (nsproxy)
net = get_net(nsproxy->net_ns);
task_unlock(task);
return net;
}
static void netns_put(void *ns)
{
put_net(ns);
}
static int netns_install(struct nsproxy *nsproxy, void *ns)
{
struct net *net = ns;
if (!ns_capable(net->user_ns, CAP_SYS_ADMIN) ||
!ns_capable(current_user_ns(), CAP_SYS_ADMIN))
return -EPERM;
put_net(nsproxy->net_ns);
nsproxy->net_ns = get_net(net);
return 0;
}
static unsigned int netns_inum(void *ns)
{
struct net *net = ns;
return net->proc_inum;
}
