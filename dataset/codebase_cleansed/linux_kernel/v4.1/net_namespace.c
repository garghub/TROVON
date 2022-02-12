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
static int alloc_netid(struct net *net, struct net *peer, int reqid)
{
int min = 0, max = 0, id;
ASSERT_RTNL();
if (reqid >= 0) {
min = reqid;
max = reqid + 1;
}
id = idr_alloc(&net->netns_ids, peer, min, max, GFP_KERNEL);
if (id >= 0)
rtnl_net_notifyid(net, peer, RTM_NEWNSID, id);
return id;
}
static int net_eq_idr(int id, void *net, void *peer)
{
if (net_eq(net, peer))
return id ? : NET_ID_ZERO;
return 0;
}
static int __peernet2id(struct net *net, struct net *peer, bool alloc)
{
int id = idr_for_each(&net->netns_ids, net_eq_idr, peer);
ASSERT_RTNL();
if (id == NET_ID_ZERO)
return 0;
if (id > 0)
return id;
if (alloc)
return alloc_netid(net, peer, -1);
return -ENOENT;
}
int peernet2id(struct net *net, struct net *peer)
{
bool alloc = atomic_read(&peer->count) == 0 ? false : true;
int id;
id = __peernet2id(net, peer, alloc);
return id >= 0 ? id : NETNSA_NSID_NOT_ASSIGNED;
}
struct net *get_net_ns_by_id(struct net *net, int id)
{
struct net *peer;
if (id < 0)
return NULL;
rcu_read_lock();
peer = idr_find(&net->netns_ids, id);
if (peer)
get_net(peer);
rcu_read_unlock();
return peer;
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
idr_init(&net->netns_ids);
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
for_each_net(tmp) {
int id = __peernet2id(tmp, net, false);
if (id >= 0) {
rtnl_net_notifyid(tmp, net, RTM_DELNSID, id);
idr_remove(&tmp->netns_ids, id);
}
}
idr_destroy(&net->netns_ids);
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
struct file *file;
struct ns_common *ns;
struct net *net;
file = proc_ns_fget(fd);
if (IS_ERR(file))
return ERR_CAST(file);
ns = get_proc_ns(file_inode(file));
if (ns->ops == &netns_operations)
net = get_net(container_of(ns, struct net, ns));
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
#ifdef CONFIG_NET_NS
net->ns.ops = &netns_operations;
#endif
return ns_alloc_inum(&net->ns);
}
static __net_exit void net_ns_net_exit(struct net *net)
{
ns_free_inum(&net->ns);
}
static int rtnl_net_newid(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(skb->sk);
struct nlattr *tb[NETNSA_MAX + 1];
struct net *peer;
int nsid, err;
err = nlmsg_parse(nlh, sizeof(struct rtgenmsg), tb, NETNSA_MAX,
rtnl_net_policy);
if (err < 0)
return err;
if (!tb[NETNSA_NSID])
return -EINVAL;
nsid = nla_get_s32(tb[NETNSA_NSID]);
if (tb[NETNSA_PID])
peer = get_net_ns_by_pid(nla_get_u32(tb[NETNSA_PID]));
else if (tb[NETNSA_FD])
peer = get_net_ns_by_fd(nla_get_u32(tb[NETNSA_FD]));
else
return -EINVAL;
if (IS_ERR(peer))
return PTR_ERR(peer);
if (__peernet2id(net, peer, false) >= 0) {
err = -EEXIST;
goto out;
}
err = alloc_netid(net, peer, nsid);
if (err > 0)
err = 0;
out:
put_net(peer);
return err;
}
static int rtnl_net_get_size(void)
{
return NLMSG_ALIGN(sizeof(struct rtgenmsg))
+ nla_total_size(sizeof(s32))
;
}
static int rtnl_net_fill(struct sk_buff *skb, u32 portid, u32 seq, int flags,
int cmd, struct net *net, struct net *peer,
int nsid)
{
struct nlmsghdr *nlh;
struct rtgenmsg *rth;
int id;
ASSERT_RTNL();
nlh = nlmsg_put(skb, portid, seq, cmd, sizeof(*rth), flags);
if (!nlh)
return -EMSGSIZE;
rth = nlmsg_data(nlh);
rth->rtgen_family = AF_UNSPEC;
if (nsid >= 0) {
id = nsid;
} else {
id = __peernet2id(net, peer, false);
if (id < 0)
id = NETNSA_NSID_NOT_ASSIGNED;
}
if (nla_put_s32(skb, NETNSA_NSID, id))
goto nla_put_failure;
nlmsg_end(skb, nlh);
return 0;
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int rtnl_net_getid(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(skb->sk);
struct nlattr *tb[NETNSA_MAX + 1];
struct sk_buff *msg;
struct net *peer;
int err;
err = nlmsg_parse(nlh, sizeof(struct rtgenmsg), tb, NETNSA_MAX,
rtnl_net_policy);
if (err < 0)
return err;
if (tb[NETNSA_PID])
peer = get_net_ns_by_pid(nla_get_u32(tb[NETNSA_PID]));
else if (tb[NETNSA_FD])
peer = get_net_ns_by_fd(nla_get_u32(tb[NETNSA_FD]));
else
return -EINVAL;
if (IS_ERR(peer))
return PTR_ERR(peer);
msg = nlmsg_new(rtnl_net_get_size(), GFP_KERNEL);
if (!msg) {
err = -ENOMEM;
goto out;
}
err = rtnl_net_fill(msg, NETLINK_CB(skb).portid, nlh->nlmsg_seq, 0,
RTM_NEWNSID, net, peer, -1);
if (err < 0)
goto err_out;
err = rtnl_unicast(msg, net, NETLINK_CB(skb).portid);
goto out;
err_out:
nlmsg_free(msg);
out:
put_net(peer);
return err;
}
static int rtnl_net_dumpid_one(int id, void *peer, void *data)
{
struct rtnl_net_dump_cb *net_cb = (struct rtnl_net_dump_cb *)data;
int ret;
if (net_cb->idx < net_cb->s_idx)
goto cont;
ret = rtnl_net_fill(net_cb->skb, NETLINK_CB(net_cb->cb->skb).portid,
net_cb->cb->nlh->nlmsg_seq, NLM_F_MULTI,
RTM_NEWNSID, net_cb->net, peer, id);
if (ret < 0)
return ret;
cont:
net_cb->idx++;
return 0;
}
static int rtnl_net_dumpid(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
struct rtnl_net_dump_cb net_cb = {
.net = net,
.skb = skb,
.cb = cb,
.idx = 0,
.s_idx = cb->args[0],
};
ASSERT_RTNL();
idr_for_each(&net->netns_ids, rtnl_net_dumpid_one, &net_cb);
cb->args[0] = net_cb.idx;
return skb->len;
}
static void rtnl_net_notifyid(struct net *net, struct net *peer, int cmd,
int id)
{
struct sk_buff *msg;
int err = -ENOMEM;
msg = nlmsg_new(rtnl_net_get_size(), GFP_KERNEL);
if (!msg)
goto out;
err = rtnl_net_fill(msg, 0, 0, 0, cmd, net, peer, id);
if (err < 0)
goto err_out;
rtnl_notify(msg, net, 0, RTNLGRP_NSID, NULL, 0);
return;
err_out:
nlmsg_free(msg);
out:
rtnl_set_sk_err(net, RTNLGRP_NSID, err);
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
rtnl_register(PF_UNSPEC, RTM_NEWNSID, rtnl_net_newid, NULL, NULL);
rtnl_register(PF_UNSPEC, RTM_GETNSID, rtnl_net_getid, rtnl_net_dumpid,
NULL);
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
static struct ns_common *netns_get(struct task_struct *task)
{
struct net *net = NULL;
struct nsproxy *nsproxy;
task_lock(task);
nsproxy = task->nsproxy;
if (nsproxy)
net = get_net(nsproxy->net_ns);
task_unlock(task);
return net ? &net->ns : NULL;
}
static inline struct net *to_net_ns(struct ns_common *ns)
{
return container_of(ns, struct net, ns);
}
static void netns_put(struct ns_common *ns)
{
put_net(to_net_ns(ns));
}
static int netns_install(struct nsproxy *nsproxy, struct ns_common *ns)
{
struct net *net = to_net_ns(ns);
if (!ns_capable(net->user_ns, CAP_SYS_ADMIN) ||
!ns_capable(current_user_ns(), CAP_SYS_ADMIN))
return -EPERM;
put_net(nsproxy->net_ns);
nsproxy->net_ns = get_net(net);
return 0;
}
