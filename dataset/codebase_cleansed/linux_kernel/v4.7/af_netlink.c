static inline int netlink_is_kernel(struct sock *sk)
{
return nlk_sk(sk)->flags & NETLINK_F_KERNEL_SOCKET;
}
static inline u32 netlink_group_mask(u32 group)
{
return group ? 1 << (group - 1) : 0;
}
static struct sk_buff *netlink_to_full_skb(const struct sk_buff *skb,
gfp_t gfp_mask)
{
unsigned int len = skb_end_offset(skb);
struct sk_buff *new;
new = alloc_skb(len, gfp_mask);
if (new == NULL)
return NULL;
NETLINK_CB(new).portid = NETLINK_CB(skb).portid;
NETLINK_CB(new).dst_group = NETLINK_CB(skb).dst_group;
NETLINK_CB(new).creds = NETLINK_CB(skb).creds;
memcpy(skb_put(new, len), skb->data, len);
return new;
}
int netlink_add_tap(struct netlink_tap *nt)
{
if (unlikely(nt->dev->type != ARPHRD_NETLINK))
return -EINVAL;
spin_lock(&netlink_tap_lock);
list_add_rcu(&nt->list, &netlink_tap_all);
spin_unlock(&netlink_tap_lock);
__module_get(nt->module);
return 0;
}
static int __netlink_remove_tap(struct netlink_tap *nt)
{
bool found = false;
struct netlink_tap *tmp;
spin_lock(&netlink_tap_lock);
list_for_each_entry(tmp, &netlink_tap_all, list) {
if (nt == tmp) {
list_del_rcu(&nt->list);
found = true;
goto out;
}
}
pr_warn("__netlink_remove_tap: %p not found\n", nt);
out:
spin_unlock(&netlink_tap_lock);
if (found)
module_put(nt->module);
return found ? 0 : -ENODEV;
}
int netlink_remove_tap(struct netlink_tap *nt)
{
int ret;
ret = __netlink_remove_tap(nt);
synchronize_net();
return ret;
}
static bool netlink_filter_tap(const struct sk_buff *skb)
{
struct sock *sk = skb->sk;
switch (sk->sk_protocol) {
case NETLINK_ROUTE:
case NETLINK_USERSOCK:
case NETLINK_SOCK_DIAG:
case NETLINK_NFLOG:
case NETLINK_XFRM:
case NETLINK_FIB_LOOKUP:
case NETLINK_NETFILTER:
case NETLINK_GENERIC:
return true;
}
return false;
}
static int __netlink_deliver_tap_skb(struct sk_buff *skb,
struct net_device *dev)
{
struct sk_buff *nskb;
struct sock *sk = skb->sk;
int ret = -ENOMEM;
dev_hold(dev);
if (is_vmalloc_addr(skb->head))
nskb = netlink_to_full_skb(skb, GFP_ATOMIC);
else
nskb = skb_clone(skb, GFP_ATOMIC);
if (nskb) {
nskb->dev = dev;
nskb->protocol = htons((u16) sk->sk_protocol);
nskb->pkt_type = netlink_is_kernel(sk) ?
PACKET_KERNEL : PACKET_USER;
skb_reset_network_header(nskb);
ret = dev_queue_xmit(nskb);
if (unlikely(ret > 0))
ret = net_xmit_errno(ret);
}
dev_put(dev);
return ret;
}
static void __netlink_deliver_tap(struct sk_buff *skb)
{
int ret;
struct netlink_tap *tmp;
if (!netlink_filter_tap(skb))
return;
list_for_each_entry_rcu(tmp, &netlink_tap_all, list) {
ret = __netlink_deliver_tap_skb(skb, tmp->dev);
if (unlikely(ret))
break;
}
}
static void netlink_deliver_tap(struct sk_buff *skb)
{
rcu_read_lock();
if (unlikely(!list_empty(&netlink_tap_all)))
__netlink_deliver_tap(skb);
rcu_read_unlock();
}
static void netlink_deliver_tap_kernel(struct sock *dst, struct sock *src,
struct sk_buff *skb)
{
if (!(netlink_is_kernel(dst) && netlink_is_kernel(src)))
netlink_deliver_tap(skb);
}
static void netlink_overrun(struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
if (!(nlk->flags & NETLINK_F_RECV_NO_ENOBUFS)) {
if (!test_and_set_bit(NETLINK_S_CONGESTED,
&nlk_sk(sk)->state)) {
sk->sk_err = ENOBUFS;
sk->sk_error_report(sk);
}
}
atomic_inc(&sk->sk_drops);
}
static void netlink_rcv_wake(struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
if (skb_queue_empty(&sk->sk_receive_queue))
clear_bit(NETLINK_S_CONGESTED, &nlk->state);
if (!test_bit(NETLINK_S_CONGESTED, &nlk->state))
wake_up_interruptible(&nlk->wait);
}
static void netlink_skb_destructor(struct sk_buff *skb)
{
if (is_vmalloc_addr(skb->head)) {
if (!skb->cloned ||
!atomic_dec_return(&(skb_shinfo(skb)->dataref)))
vfree(skb->head);
skb->head = NULL;
}
if (skb->sk != NULL)
sock_rfree(skb);
}
static void netlink_skb_set_owner_r(struct sk_buff *skb, struct sock *sk)
{
WARN_ON(skb->sk != NULL);
skb->sk = sk;
skb->destructor = netlink_skb_destructor;
atomic_add(skb->truesize, &sk->sk_rmem_alloc);
sk_mem_charge(sk, skb->truesize);
}
static void netlink_sock_destruct(struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
if (nlk->cb_running) {
if (nlk->cb.done)
nlk->cb.done(&nlk->cb);
module_put(nlk->cb.module);
kfree_skb(nlk->cb.skb);
}
skb_queue_purge(&sk->sk_receive_queue);
if (!sock_flag(sk, SOCK_DEAD)) {
printk(KERN_ERR "Freeing alive netlink socket %p\n", sk);
return;
}
WARN_ON(atomic_read(&sk->sk_rmem_alloc));
WARN_ON(atomic_read(&sk->sk_wmem_alloc));
WARN_ON(nlk_sk(sk)->groups);
}
void netlink_table_grab(void)
__acquires(nl_table_lock)
{
might_sleep();
write_lock_irq(&nl_table_lock);
if (atomic_read(&nl_table_users)) {
DECLARE_WAITQUEUE(wait, current);
add_wait_queue_exclusive(&nl_table_wait, &wait);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (atomic_read(&nl_table_users) == 0)
break;
write_unlock_irq(&nl_table_lock);
schedule();
write_lock_irq(&nl_table_lock);
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(&nl_table_wait, &wait);
}
}
void netlink_table_ungrab(void)
__releases(nl_table_lock)
{
write_unlock_irq(&nl_table_lock);
wake_up(&nl_table_wait);
}
static inline void
netlink_lock_table(void)
{
read_lock(&nl_table_lock);
atomic_inc(&nl_table_users);
read_unlock(&nl_table_lock);
}
static inline void
netlink_unlock_table(void)
{
if (atomic_dec_and_test(&nl_table_users))
wake_up(&nl_table_wait);
}
static inline int netlink_compare(struct rhashtable_compare_arg *arg,
const void *ptr)
{
const struct netlink_compare_arg *x = arg->key;
const struct netlink_sock *nlk = ptr;
return nlk->portid != x->portid ||
!net_eq(sock_net(&nlk->sk), read_pnet(&x->pnet));
}
static void netlink_compare_arg_init(struct netlink_compare_arg *arg,
struct net *net, u32 portid)
{
memset(arg, 0, sizeof(*arg));
write_pnet(&arg->pnet, net);
arg->portid = portid;
}
static struct sock *__netlink_lookup(struct netlink_table *table, u32 portid,
struct net *net)
{
struct netlink_compare_arg arg;
netlink_compare_arg_init(&arg, net, portid);
return rhashtable_lookup_fast(&table->hash, &arg,
netlink_rhashtable_params);
}
static int __netlink_insert(struct netlink_table *table, struct sock *sk)
{
struct netlink_compare_arg arg;
netlink_compare_arg_init(&arg, sock_net(sk), nlk_sk(sk)->portid);
return rhashtable_lookup_insert_key(&table->hash, &arg,
&nlk_sk(sk)->node,
netlink_rhashtable_params);
}
static struct sock *netlink_lookup(struct net *net, int protocol, u32 portid)
{
struct netlink_table *table = &nl_table[protocol];
struct sock *sk;
rcu_read_lock();
sk = __netlink_lookup(table, portid, net);
if (sk)
sock_hold(sk);
rcu_read_unlock();
return sk;
}
static void
netlink_update_listeners(struct sock *sk)
{
struct netlink_table *tbl = &nl_table[sk->sk_protocol];
unsigned long mask;
unsigned int i;
struct listeners *listeners;
listeners = nl_deref_protected(tbl->listeners);
if (!listeners)
return;
for (i = 0; i < NLGRPLONGS(tbl->groups); i++) {
mask = 0;
sk_for_each_bound(sk, &tbl->mc_list) {
if (i < NLGRPLONGS(nlk_sk(sk)->ngroups))
mask |= nlk_sk(sk)->groups[i];
}
listeners->masks[i] = mask;
}
}
static int netlink_insert(struct sock *sk, u32 portid)
{
struct netlink_table *table = &nl_table[sk->sk_protocol];
int err;
lock_sock(sk);
err = nlk_sk(sk)->portid == portid ? 0 : -EBUSY;
if (nlk_sk(sk)->bound)
goto err;
err = -ENOMEM;
if (BITS_PER_LONG > 32 &&
unlikely(atomic_read(&table->hash.nelems) >= UINT_MAX))
goto err;
nlk_sk(sk)->portid = portid;
sock_hold(sk);
err = __netlink_insert(table, sk);
if (err) {
if (unlikely(err == -EBUSY))
err = -EOVERFLOW;
if (err == -EEXIST)
err = -EADDRINUSE;
sock_put(sk);
goto err;
}
smp_wmb();
nlk_sk(sk)->bound = portid;
err:
release_sock(sk);
return err;
}
static void netlink_remove(struct sock *sk)
{
struct netlink_table *table;
table = &nl_table[sk->sk_protocol];
if (!rhashtable_remove_fast(&table->hash, &nlk_sk(sk)->node,
netlink_rhashtable_params)) {
WARN_ON(atomic_read(&sk->sk_refcnt) == 1);
__sock_put(sk);
}
netlink_table_grab();
if (nlk_sk(sk)->subscriptions) {
__sk_del_bind_node(sk);
netlink_update_listeners(sk);
}
if (sk->sk_protocol == NETLINK_GENERIC)
atomic_inc(&genl_sk_destructing_cnt);
netlink_table_ungrab();
}
static int __netlink_create(struct net *net, struct socket *sock,
struct mutex *cb_mutex, int protocol,
int kern)
{
struct sock *sk;
struct netlink_sock *nlk;
sock->ops = &netlink_ops;
sk = sk_alloc(net, PF_NETLINK, GFP_KERNEL, &netlink_proto, kern);
if (!sk)
return -ENOMEM;
sock_init_data(sock, sk);
nlk = nlk_sk(sk);
if (cb_mutex) {
nlk->cb_mutex = cb_mutex;
} else {
nlk->cb_mutex = &nlk->cb_def_mutex;
mutex_init(nlk->cb_mutex);
}
init_waitqueue_head(&nlk->wait);
sk->sk_destruct = netlink_sock_destruct;
sk->sk_protocol = protocol;
return 0;
}
static int netlink_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct module *module = NULL;
struct mutex *cb_mutex;
struct netlink_sock *nlk;
int (*bind)(struct net *net, int group);
void (*unbind)(struct net *net, int group);
int err = 0;
sock->state = SS_UNCONNECTED;
if (sock->type != SOCK_RAW && sock->type != SOCK_DGRAM)
return -ESOCKTNOSUPPORT;
if (protocol < 0 || protocol >= MAX_LINKS)
return -EPROTONOSUPPORT;
netlink_lock_table();
#ifdef CONFIG_MODULES
if (!nl_table[protocol].registered) {
netlink_unlock_table();
request_module("net-pf-%d-proto-%d", PF_NETLINK, protocol);
netlink_lock_table();
}
#endif
if (nl_table[protocol].registered &&
try_module_get(nl_table[protocol].module))
module = nl_table[protocol].module;
else
err = -EPROTONOSUPPORT;
cb_mutex = nl_table[protocol].cb_mutex;
bind = nl_table[protocol].bind;
unbind = nl_table[protocol].unbind;
netlink_unlock_table();
if (err < 0)
goto out;
err = __netlink_create(net, sock, cb_mutex, protocol, kern);
if (err < 0)
goto out_module;
local_bh_disable();
sock_prot_inuse_add(net, &netlink_proto, 1);
local_bh_enable();
nlk = nlk_sk(sock->sk);
nlk->module = module;
nlk->netlink_bind = bind;
nlk->netlink_unbind = unbind;
out:
return err;
out_module:
module_put(module);
goto out;
}
static void deferred_put_nlk_sk(struct rcu_head *head)
{
struct netlink_sock *nlk = container_of(head, struct netlink_sock, rcu);
sock_put(&nlk->sk);
}
static int netlink_release(struct socket *sock)
{
struct sock *sk = sock->sk;
struct netlink_sock *nlk;
if (!sk)
return 0;
netlink_remove(sk);
sock_orphan(sk);
nlk = nlk_sk(sk);
if (nlk->netlink_unbind) {
int i;
for (i = 0; i < nlk->ngroups; i++)
if (test_bit(i, nlk->groups))
nlk->netlink_unbind(sock_net(sk), i + 1);
}
if (sk->sk_protocol == NETLINK_GENERIC &&
atomic_dec_return(&genl_sk_destructing_cnt) == 0)
wake_up(&genl_sk_destructing_waitq);
sock->sk = NULL;
wake_up_interruptible_all(&nlk->wait);
skb_queue_purge(&sk->sk_write_queue);
if (nlk->portid && nlk->bound) {
struct netlink_notify n = {
.net = sock_net(sk),
.protocol = sk->sk_protocol,
.portid = nlk->portid,
};
atomic_notifier_call_chain(&netlink_chain,
NETLINK_URELEASE, &n);
}
module_put(nlk->module);
if (netlink_is_kernel(sk)) {
netlink_table_grab();
BUG_ON(nl_table[sk->sk_protocol].registered == 0);
if (--nl_table[sk->sk_protocol].registered == 0) {
struct listeners *old;
old = nl_deref_protected(nl_table[sk->sk_protocol].listeners);
RCU_INIT_POINTER(nl_table[sk->sk_protocol].listeners, NULL);
kfree_rcu(old, rcu);
nl_table[sk->sk_protocol].module = NULL;
nl_table[sk->sk_protocol].bind = NULL;
nl_table[sk->sk_protocol].unbind = NULL;
nl_table[sk->sk_protocol].flags = 0;
nl_table[sk->sk_protocol].registered = 0;
}
netlink_table_ungrab();
}
kfree(nlk->groups);
nlk->groups = NULL;
local_bh_disable();
sock_prot_inuse_add(sock_net(sk), &netlink_proto, -1);
local_bh_enable();
call_rcu(&nlk->rcu, deferred_put_nlk_sk);
return 0;
}
static int netlink_autobind(struct socket *sock)
{
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct netlink_table *table = &nl_table[sk->sk_protocol];
s32 portid = task_tgid_vnr(current);
int err;
s32 rover = -4096;
bool ok;
retry:
cond_resched();
rcu_read_lock();
ok = !__netlink_lookup(table, portid, net);
rcu_read_unlock();
if (!ok) {
if (rover == -4096)
rover = S32_MIN + prandom_u32_max(-4096 - S32_MIN);
else if (rover >= -4096)
rover = -4097;
portid = rover--;
goto retry;
}
err = netlink_insert(sk, portid);
if (err == -EADDRINUSE)
goto retry;
if (err == -EBUSY)
err = 0;
return err;
}
bool __netlink_ns_capable(const struct netlink_skb_parms *nsp,
struct user_namespace *user_ns, int cap)
{
return ((nsp->flags & NETLINK_SKB_DST) ||
file_ns_capable(nsp->sk->sk_socket->file, user_ns, cap)) &&
ns_capable(user_ns, cap);
}
bool netlink_ns_capable(const struct sk_buff *skb,
struct user_namespace *user_ns, int cap)
{
return __netlink_ns_capable(&NETLINK_CB(skb), user_ns, cap);
}
bool netlink_capable(const struct sk_buff *skb, int cap)
{
return netlink_ns_capable(skb, &init_user_ns, cap);
}
bool netlink_net_capable(const struct sk_buff *skb, int cap)
{
return netlink_ns_capable(skb, sock_net(skb->sk)->user_ns, cap);
}
static inline int netlink_allowed(const struct socket *sock, unsigned int flag)
{
return (nl_table[sock->sk->sk_protocol].flags & flag) ||
ns_capable(sock_net(sock->sk)->user_ns, CAP_NET_ADMIN);
}
static void
netlink_update_subscriptions(struct sock *sk, unsigned int subscriptions)
{
struct netlink_sock *nlk = nlk_sk(sk);
if (nlk->subscriptions && !subscriptions)
__sk_del_bind_node(sk);
else if (!nlk->subscriptions && subscriptions)
sk_add_bind_node(sk, &nl_table[sk->sk_protocol].mc_list);
nlk->subscriptions = subscriptions;
}
static int netlink_realloc_groups(struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
unsigned int groups;
unsigned long *new_groups;
int err = 0;
netlink_table_grab();
groups = nl_table[sk->sk_protocol].groups;
if (!nl_table[sk->sk_protocol].registered) {
err = -ENOENT;
goto out_unlock;
}
if (nlk->ngroups >= groups)
goto out_unlock;
new_groups = krealloc(nlk->groups, NLGRPSZ(groups), GFP_ATOMIC);
if (new_groups == NULL) {
err = -ENOMEM;
goto out_unlock;
}
memset((char *)new_groups + NLGRPSZ(nlk->ngroups), 0,
NLGRPSZ(groups) - NLGRPSZ(nlk->ngroups));
nlk->groups = new_groups;
nlk->ngroups = groups;
out_unlock:
netlink_table_ungrab();
return err;
}
static void netlink_undo_bind(int group, long unsigned int groups,
struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
int undo;
if (!nlk->netlink_unbind)
return;
for (undo = 0; undo < group; undo++)
if (test_bit(undo, &groups))
nlk->netlink_unbind(sock_net(sk), undo + 1);
}
static int netlink_bind(struct socket *sock, struct sockaddr *addr,
int addr_len)
{
struct sock *sk = sock->sk;
struct net *net = sock_net(sk);
struct netlink_sock *nlk = nlk_sk(sk);
struct sockaddr_nl *nladdr = (struct sockaddr_nl *)addr;
int err;
long unsigned int groups = nladdr->nl_groups;
bool bound;
if (addr_len < sizeof(struct sockaddr_nl))
return -EINVAL;
if (nladdr->nl_family != AF_NETLINK)
return -EINVAL;
if (groups) {
if (!netlink_allowed(sock, NL_CFG_F_NONROOT_RECV))
return -EPERM;
err = netlink_realloc_groups(sk);
if (err)
return err;
}
bound = nlk->bound;
if (bound) {
smp_rmb();
if (nladdr->nl_pid != nlk->portid)
return -EINVAL;
}
if (nlk->netlink_bind && groups) {
int group;
for (group = 0; group < nlk->ngroups; group++) {
if (!test_bit(group, &groups))
continue;
err = nlk->netlink_bind(net, group + 1);
if (!err)
continue;
netlink_undo_bind(group, groups, sk);
return err;
}
}
if (!bound) {
err = nladdr->nl_pid ?
netlink_insert(sk, nladdr->nl_pid) :
netlink_autobind(sock);
if (err) {
netlink_undo_bind(nlk->ngroups, groups, sk);
return err;
}
}
if (!groups && (nlk->groups == NULL || !(u32)nlk->groups[0]))
return 0;
netlink_table_grab();
netlink_update_subscriptions(sk, nlk->subscriptions +
hweight32(groups) -
hweight32(nlk->groups[0]));
nlk->groups[0] = (nlk->groups[0] & ~0xffffffffUL) | groups;
netlink_update_listeners(sk);
netlink_table_ungrab();
return 0;
}
static int netlink_connect(struct socket *sock, struct sockaddr *addr,
int alen, int flags)
{
int err = 0;
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
struct sockaddr_nl *nladdr = (struct sockaddr_nl *)addr;
if (alen < sizeof(addr->sa_family))
return -EINVAL;
if (addr->sa_family == AF_UNSPEC) {
sk->sk_state = NETLINK_UNCONNECTED;
nlk->dst_portid = 0;
nlk->dst_group = 0;
return 0;
}
if (addr->sa_family != AF_NETLINK)
return -EINVAL;
if ((nladdr->nl_groups || nladdr->nl_pid) &&
!netlink_allowed(sock, NL_CFG_F_NONROOT_SEND))
return -EPERM;
if (!nlk->bound)
err = netlink_autobind(sock);
if (err == 0) {
sk->sk_state = NETLINK_CONNECTED;
nlk->dst_portid = nladdr->nl_pid;
nlk->dst_group = ffs(nladdr->nl_groups);
}
return err;
}
static int netlink_getname(struct socket *sock, struct sockaddr *addr,
int *addr_len, int peer)
{
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_nl *, nladdr, addr);
nladdr->nl_family = AF_NETLINK;
nladdr->nl_pad = 0;
*addr_len = sizeof(*nladdr);
if (peer) {
nladdr->nl_pid = nlk->dst_portid;
nladdr->nl_groups = netlink_group_mask(nlk->dst_group);
} else {
nladdr->nl_pid = nlk->portid;
nladdr->nl_groups = nlk->groups ? nlk->groups[0] : 0;
}
return 0;
}
static int netlink_ioctl(struct socket *sock, unsigned int cmd,
unsigned long arg)
{
return -ENOIOCTLCMD;
}
static struct sock *netlink_getsockbyportid(struct sock *ssk, u32 portid)
{
struct sock *sock;
struct netlink_sock *nlk;
sock = netlink_lookup(sock_net(ssk), ssk->sk_protocol, portid);
if (!sock)
return ERR_PTR(-ECONNREFUSED);
nlk = nlk_sk(sock);
if (sock->sk_state == NETLINK_CONNECTED &&
nlk->dst_portid != nlk_sk(ssk)->portid) {
sock_put(sock);
return ERR_PTR(-ECONNREFUSED);
}
return sock;
}
struct sock *netlink_getsockbyfilp(struct file *filp)
{
struct inode *inode = file_inode(filp);
struct sock *sock;
if (!S_ISSOCK(inode->i_mode))
return ERR_PTR(-ENOTSOCK);
sock = SOCKET_I(inode)->sk;
if (sock->sk_family != AF_NETLINK)
return ERR_PTR(-EINVAL);
sock_hold(sock);
return sock;
}
static struct sk_buff *netlink_alloc_large_skb(unsigned int size,
int broadcast)
{
struct sk_buff *skb;
void *data;
if (size <= NLMSG_GOODSIZE || broadcast)
return alloc_skb(size, GFP_KERNEL);
size = SKB_DATA_ALIGN(size) +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
data = vmalloc(size);
if (data == NULL)
return NULL;
skb = __build_skb(data, size);
if (skb == NULL)
vfree(data);
else
skb->destructor = netlink_skb_destructor;
return skb;
}
int netlink_attachskb(struct sock *sk, struct sk_buff *skb,
long *timeo, struct sock *ssk)
{
struct netlink_sock *nlk;
nlk = nlk_sk(sk);
if ((atomic_read(&sk->sk_rmem_alloc) > sk->sk_rcvbuf ||
test_bit(NETLINK_S_CONGESTED, &nlk->state))) {
DECLARE_WAITQUEUE(wait, current);
if (!*timeo) {
if (!ssk || netlink_is_kernel(ssk))
netlink_overrun(sk);
sock_put(sk);
kfree_skb(skb);
return -EAGAIN;
}
__set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&nlk->wait, &wait);
if ((atomic_read(&sk->sk_rmem_alloc) > sk->sk_rcvbuf ||
test_bit(NETLINK_S_CONGESTED, &nlk->state)) &&
!sock_flag(sk, SOCK_DEAD))
*timeo = schedule_timeout(*timeo);
__set_current_state(TASK_RUNNING);
remove_wait_queue(&nlk->wait, &wait);
sock_put(sk);
if (signal_pending(current)) {
kfree_skb(skb);
return sock_intr_errno(*timeo);
}
return 1;
}
netlink_skb_set_owner_r(skb, sk);
return 0;
}
static int __netlink_sendskb(struct sock *sk, struct sk_buff *skb)
{
int len = skb->len;
netlink_deliver_tap(skb);
skb_queue_tail(&sk->sk_receive_queue, skb);
sk->sk_data_ready(sk);
return len;
}
int netlink_sendskb(struct sock *sk, struct sk_buff *skb)
{
int len = __netlink_sendskb(sk, skb);
sock_put(sk);
return len;
}
void netlink_detachskb(struct sock *sk, struct sk_buff *skb)
{
kfree_skb(skb);
sock_put(sk);
}
static struct sk_buff *netlink_trim(struct sk_buff *skb, gfp_t allocation)
{
int delta;
WARN_ON(skb->sk != NULL);
delta = skb->end - skb->tail;
if (is_vmalloc_addr(skb->head) || delta * 2 < skb->truesize)
return skb;
if (skb_shared(skb)) {
struct sk_buff *nskb = skb_clone(skb, allocation);
if (!nskb)
return skb;
consume_skb(skb);
skb = nskb;
}
if (!pskb_expand_head(skb, 0, -delta, allocation))
skb->truesize -= delta;
return skb;
}
static int netlink_unicast_kernel(struct sock *sk, struct sk_buff *skb,
struct sock *ssk)
{
int ret;
struct netlink_sock *nlk = nlk_sk(sk);
ret = -ECONNREFUSED;
if (nlk->netlink_rcv != NULL) {
ret = skb->len;
netlink_skb_set_owner_r(skb, sk);
NETLINK_CB(skb).sk = ssk;
netlink_deliver_tap_kernel(sk, ssk, skb);
nlk->netlink_rcv(skb);
consume_skb(skb);
} else {
kfree_skb(skb);
}
sock_put(sk);
return ret;
}
int netlink_unicast(struct sock *ssk, struct sk_buff *skb,
u32 portid, int nonblock)
{
struct sock *sk;
int err;
long timeo;
skb = netlink_trim(skb, gfp_any());
timeo = sock_sndtimeo(ssk, nonblock);
retry:
sk = netlink_getsockbyportid(ssk, portid);
if (IS_ERR(sk)) {
kfree_skb(skb);
return PTR_ERR(sk);
}
if (netlink_is_kernel(sk))
return netlink_unicast_kernel(sk, skb, ssk);
if (sk_filter(sk, skb)) {
err = skb->len;
kfree_skb(skb);
sock_put(sk);
return err;
}
err = netlink_attachskb(sk, skb, &timeo, ssk);
if (err == 1)
goto retry;
if (err)
return err;
return netlink_sendskb(sk, skb);
}
int netlink_has_listeners(struct sock *sk, unsigned int group)
{
int res = 0;
struct listeners *listeners;
BUG_ON(!netlink_is_kernel(sk));
rcu_read_lock();
listeners = rcu_dereference(nl_table[sk->sk_protocol].listeners);
if (listeners && group - 1 < nl_table[sk->sk_protocol].groups)
res = test_bit(group - 1, listeners->masks);
rcu_read_unlock();
return res;
}
static int netlink_broadcast_deliver(struct sock *sk, struct sk_buff *skb)
{
struct netlink_sock *nlk = nlk_sk(sk);
if (atomic_read(&sk->sk_rmem_alloc) <= sk->sk_rcvbuf &&
!test_bit(NETLINK_S_CONGESTED, &nlk->state)) {
netlink_skb_set_owner_r(skb, sk);
__netlink_sendskb(sk, skb);
return atomic_read(&sk->sk_rmem_alloc) > (sk->sk_rcvbuf >> 1);
}
return -1;
}
static void do_one_broadcast(struct sock *sk,
struct netlink_broadcast_data *p)
{
struct netlink_sock *nlk = nlk_sk(sk);
int val;
if (p->exclude_sk == sk)
return;
if (nlk->portid == p->portid || p->group - 1 >= nlk->ngroups ||
!test_bit(p->group - 1, nlk->groups))
return;
if (!net_eq(sock_net(sk), p->net)) {
if (!(nlk->flags & NETLINK_F_LISTEN_ALL_NSID))
return;
if (!peernet_has_id(sock_net(sk), p->net))
return;
if (!file_ns_capable(sk->sk_socket->file, p->net->user_ns,
CAP_NET_BROADCAST))
return;
}
if (p->failure) {
netlink_overrun(sk);
return;
}
sock_hold(sk);
if (p->skb2 == NULL) {
if (skb_shared(p->skb)) {
p->skb2 = skb_clone(p->skb, p->allocation);
} else {
p->skb2 = skb_get(p->skb);
skb_orphan(p->skb2);
}
}
if (p->skb2 == NULL) {
netlink_overrun(sk);
p->failure = 1;
if (nlk->flags & NETLINK_F_BROADCAST_SEND_ERROR)
p->delivery_failure = 1;
goto out;
}
if (p->tx_filter && p->tx_filter(sk, p->skb2, p->tx_data)) {
kfree_skb(p->skb2);
p->skb2 = NULL;
goto out;
}
if (sk_filter(sk, p->skb2)) {
kfree_skb(p->skb2);
p->skb2 = NULL;
goto out;
}
NETLINK_CB(p->skb2).nsid = peernet2id(sock_net(sk), p->net);
NETLINK_CB(p->skb2).nsid_is_set = true;
val = netlink_broadcast_deliver(sk, p->skb2);
if (val < 0) {
netlink_overrun(sk);
if (nlk->flags & NETLINK_F_BROADCAST_SEND_ERROR)
p->delivery_failure = 1;
} else {
p->congested |= val;
p->delivered = 1;
p->skb2 = NULL;
}
out:
sock_put(sk);
}
int netlink_broadcast_filtered(struct sock *ssk, struct sk_buff *skb, u32 portid,
u32 group, gfp_t allocation,
int (*filter)(struct sock *dsk, struct sk_buff *skb, void *data),
void *filter_data)
{
struct net *net = sock_net(ssk);
struct netlink_broadcast_data info;
struct sock *sk;
skb = netlink_trim(skb, allocation);
info.exclude_sk = ssk;
info.net = net;
info.portid = portid;
info.group = group;
info.failure = 0;
info.delivery_failure = 0;
info.congested = 0;
info.delivered = 0;
info.allocation = allocation;
info.skb = skb;
info.skb2 = NULL;
info.tx_filter = filter;
info.tx_data = filter_data;
netlink_lock_table();
sk_for_each_bound(sk, &nl_table[ssk->sk_protocol].mc_list)
do_one_broadcast(sk, &info);
consume_skb(skb);
netlink_unlock_table();
if (info.delivery_failure) {
kfree_skb(info.skb2);
return -ENOBUFS;
}
consume_skb(info.skb2);
if (info.delivered) {
if (info.congested && gfpflags_allow_blocking(allocation))
yield();
return 0;
}
return -ESRCH;
}
int netlink_broadcast(struct sock *ssk, struct sk_buff *skb, u32 portid,
u32 group, gfp_t allocation)
{
return netlink_broadcast_filtered(ssk, skb, portid, group, allocation,
NULL, NULL);
}
static int do_one_set_err(struct sock *sk, struct netlink_set_err_data *p)
{
struct netlink_sock *nlk = nlk_sk(sk);
int ret = 0;
if (sk == p->exclude_sk)
goto out;
if (!net_eq(sock_net(sk), sock_net(p->exclude_sk)))
goto out;
if (nlk->portid == p->portid || p->group - 1 >= nlk->ngroups ||
!test_bit(p->group - 1, nlk->groups))
goto out;
if (p->code == ENOBUFS && nlk->flags & NETLINK_F_RECV_NO_ENOBUFS) {
ret = 1;
goto out;
}
sk->sk_err = p->code;
sk->sk_error_report(sk);
out:
return ret;
}
int netlink_set_err(struct sock *ssk, u32 portid, u32 group, int code)
{
struct netlink_set_err_data info;
struct sock *sk;
int ret = 0;
info.exclude_sk = ssk;
info.portid = portid;
info.group = group;
info.code = -code;
read_lock(&nl_table_lock);
sk_for_each_bound(sk, &nl_table[ssk->sk_protocol].mc_list)
ret += do_one_set_err(sk, &info);
read_unlock(&nl_table_lock);
return ret;
}
static void netlink_update_socket_mc(struct netlink_sock *nlk,
unsigned int group,
int is_new)
{
int old, new = !!is_new, subscriptions;
old = test_bit(group - 1, nlk->groups);
subscriptions = nlk->subscriptions - old + new;
if (new)
__set_bit(group - 1, nlk->groups);
else
__clear_bit(group - 1, nlk->groups);
netlink_update_subscriptions(&nlk->sk, subscriptions);
netlink_update_listeners(&nlk->sk);
}
static int netlink_setsockopt(struct socket *sock, int level, int optname,
char __user *optval, unsigned int optlen)
{
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
unsigned int val = 0;
int err;
if (level != SOL_NETLINK)
return -ENOPROTOOPT;
if (optlen >= sizeof(int) &&
get_user(val, (unsigned int __user *)optval))
return -EFAULT;
switch (optname) {
case NETLINK_PKTINFO:
if (val)
nlk->flags |= NETLINK_F_RECV_PKTINFO;
else
nlk->flags &= ~NETLINK_F_RECV_PKTINFO;
err = 0;
break;
case NETLINK_ADD_MEMBERSHIP:
case NETLINK_DROP_MEMBERSHIP: {
if (!netlink_allowed(sock, NL_CFG_F_NONROOT_RECV))
return -EPERM;
err = netlink_realloc_groups(sk);
if (err)
return err;
if (!val || val - 1 >= nlk->ngroups)
return -EINVAL;
if (optname == NETLINK_ADD_MEMBERSHIP && nlk->netlink_bind) {
err = nlk->netlink_bind(sock_net(sk), val);
if (err)
return err;
}
netlink_table_grab();
netlink_update_socket_mc(nlk, val,
optname == NETLINK_ADD_MEMBERSHIP);
netlink_table_ungrab();
if (optname == NETLINK_DROP_MEMBERSHIP && nlk->netlink_unbind)
nlk->netlink_unbind(sock_net(sk), val);
err = 0;
break;
}
case NETLINK_BROADCAST_ERROR:
if (val)
nlk->flags |= NETLINK_F_BROADCAST_SEND_ERROR;
else
nlk->flags &= ~NETLINK_F_BROADCAST_SEND_ERROR;
err = 0;
break;
case NETLINK_NO_ENOBUFS:
if (val) {
nlk->flags |= NETLINK_F_RECV_NO_ENOBUFS;
clear_bit(NETLINK_S_CONGESTED, &nlk->state);
wake_up_interruptible(&nlk->wait);
} else {
nlk->flags &= ~NETLINK_F_RECV_NO_ENOBUFS;
}
err = 0;
break;
case NETLINK_LISTEN_ALL_NSID:
if (!ns_capable(sock_net(sk)->user_ns, CAP_NET_BROADCAST))
return -EPERM;
if (val)
nlk->flags |= NETLINK_F_LISTEN_ALL_NSID;
else
nlk->flags &= ~NETLINK_F_LISTEN_ALL_NSID;
err = 0;
break;
case NETLINK_CAP_ACK:
if (val)
nlk->flags |= NETLINK_F_CAP_ACK;
else
nlk->flags &= ~NETLINK_F_CAP_ACK;
err = 0;
break;
default:
err = -ENOPROTOOPT;
}
return err;
}
static int netlink_getsockopt(struct socket *sock, int level, int optname,
char __user *optval, int __user *optlen)
{
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
int len, val, err;
if (level != SOL_NETLINK)
return -ENOPROTOOPT;
if (get_user(len, optlen))
return -EFAULT;
if (len < 0)
return -EINVAL;
switch (optname) {
case NETLINK_PKTINFO:
if (len < sizeof(int))
return -EINVAL;
len = sizeof(int);
val = nlk->flags & NETLINK_F_RECV_PKTINFO ? 1 : 0;
if (put_user(len, optlen) ||
put_user(val, optval))
return -EFAULT;
err = 0;
break;
case NETLINK_BROADCAST_ERROR:
if (len < sizeof(int))
return -EINVAL;
len = sizeof(int);
val = nlk->flags & NETLINK_F_BROADCAST_SEND_ERROR ? 1 : 0;
if (put_user(len, optlen) ||
put_user(val, optval))
return -EFAULT;
err = 0;
break;
case NETLINK_NO_ENOBUFS:
if (len < sizeof(int))
return -EINVAL;
len = sizeof(int);
val = nlk->flags & NETLINK_F_RECV_NO_ENOBUFS ? 1 : 0;
if (put_user(len, optlen) ||
put_user(val, optval))
return -EFAULT;
err = 0;
break;
case NETLINK_LIST_MEMBERSHIPS: {
int pos, idx, shift;
err = 0;
netlink_lock_table();
for (pos = 0; pos * 8 < nlk->ngroups; pos += sizeof(u32)) {
if (len - pos < sizeof(u32))
break;
idx = pos / sizeof(unsigned long);
shift = (pos % sizeof(unsigned long)) * 8;
if (put_user((u32)(nlk->groups[idx] >> shift),
(u32 __user *)(optval + pos))) {
err = -EFAULT;
break;
}
}
if (put_user(ALIGN(nlk->ngroups / 8, sizeof(u32)), optlen))
err = -EFAULT;
netlink_unlock_table();
break;
}
case NETLINK_CAP_ACK:
if (len < sizeof(int))
return -EINVAL;
len = sizeof(int);
val = nlk->flags & NETLINK_F_CAP_ACK ? 1 : 0;
if (put_user(len, optlen) ||
put_user(val, optval))
return -EFAULT;
err = 0;
break;
default:
err = -ENOPROTOOPT;
}
return err;
}
static void netlink_cmsg_recv_pktinfo(struct msghdr *msg, struct sk_buff *skb)
{
struct nl_pktinfo info;
info.group = NETLINK_CB(skb).dst_group;
put_cmsg(msg, SOL_NETLINK, NETLINK_PKTINFO, sizeof(info), &info);
}
static void netlink_cmsg_listen_all_nsid(struct sock *sk, struct msghdr *msg,
struct sk_buff *skb)
{
if (!NETLINK_CB(skb).nsid_is_set)
return;
put_cmsg(msg, SOL_NETLINK, NETLINK_LISTEN_ALL_NSID, sizeof(int),
&NETLINK_CB(skb).nsid);
}
static int netlink_sendmsg(struct socket *sock, struct msghdr *msg, size_t len)
{
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
DECLARE_SOCKADDR(struct sockaddr_nl *, addr, msg->msg_name);
u32 dst_portid;
u32 dst_group;
struct sk_buff *skb;
int err;
struct scm_cookie scm;
u32 netlink_skb_flags = 0;
if (msg->msg_flags&MSG_OOB)
return -EOPNOTSUPP;
err = scm_send(sock, msg, &scm, true);
if (err < 0)
return err;
if (msg->msg_namelen) {
err = -EINVAL;
if (addr->nl_family != AF_NETLINK)
goto out;
dst_portid = addr->nl_pid;
dst_group = ffs(addr->nl_groups);
err = -EPERM;
if ((dst_group || dst_portid) &&
!netlink_allowed(sock, NL_CFG_F_NONROOT_SEND))
goto out;
netlink_skb_flags |= NETLINK_SKB_DST;
} else {
dst_portid = nlk->dst_portid;
dst_group = nlk->dst_group;
}
if (!nlk->bound) {
err = netlink_autobind(sock);
if (err)
goto out;
} else {
smp_rmb();
}
err = -EMSGSIZE;
if (len > sk->sk_sndbuf - 32)
goto out;
err = -ENOBUFS;
skb = netlink_alloc_large_skb(len, dst_group);
if (skb == NULL)
goto out;
NETLINK_CB(skb).portid = nlk->portid;
NETLINK_CB(skb).dst_group = dst_group;
NETLINK_CB(skb).creds = scm.creds;
NETLINK_CB(skb).flags = netlink_skb_flags;
err = -EFAULT;
if (memcpy_from_msg(skb_put(skb, len), msg, len)) {
kfree_skb(skb);
goto out;
}
err = security_netlink_send(sk, skb);
if (err) {
kfree_skb(skb);
goto out;
}
if (dst_group) {
atomic_inc(&skb->users);
netlink_broadcast(sk, skb, dst_portid, dst_group, GFP_KERNEL);
}
err = netlink_unicast(sk, skb, dst_portid, msg->msg_flags&MSG_DONTWAIT);
out:
scm_destroy(&scm);
return err;
}
static int netlink_recvmsg(struct socket *sock, struct msghdr *msg, size_t len,
int flags)
{
struct scm_cookie scm;
struct sock *sk = sock->sk;
struct netlink_sock *nlk = nlk_sk(sk);
int noblock = flags&MSG_DONTWAIT;
size_t copied;
struct sk_buff *skb, *data_skb;
int err, ret;
if (flags&MSG_OOB)
return -EOPNOTSUPP;
copied = 0;
skb = skb_recv_datagram(sk, flags, noblock, &err);
if (skb == NULL)
goto out;
data_skb = skb;
#ifdef CONFIG_COMPAT_NETLINK_MESSAGES
if (unlikely(skb_shinfo(skb)->frag_list)) {
if (flags & MSG_CMSG_COMPAT)
data_skb = skb_shinfo(skb)->frag_list;
}
#endif
nlk->max_recvmsg_len = max(nlk->max_recvmsg_len, len);
nlk->max_recvmsg_len = min_t(size_t, nlk->max_recvmsg_len,
16384);
copied = data_skb->len;
if (len < copied) {
msg->msg_flags |= MSG_TRUNC;
copied = len;
}
skb_reset_transport_header(data_skb);
err = skb_copy_datagram_msg(data_skb, 0, msg, copied);
if (msg->msg_name) {
DECLARE_SOCKADDR(struct sockaddr_nl *, addr, msg->msg_name);
addr->nl_family = AF_NETLINK;
addr->nl_pad = 0;
addr->nl_pid = NETLINK_CB(skb).portid;
addr->nl_groups = netlink_group_mask(NETLINK_CB(skb).dst_group);
msg->msg_namelen = sizeof(*addr);
}
if (nlk->flags & NETLINK_F_RECV_PKTINFO)
netlink_cmsg_recv_pktinfo(msg, skb);
if (nlk->flags & NETLINK_F_LISTEN_ALL_NSID)
netlink_cmsg_listen_all_nsid(sk, msg, skb);
memset(&scm, 0, sizeof(scm));
scm.creds = *NETLINK_CREDS(skb);
if (flags & MSG_TRUNC)
copied = data_skb->len;
skb_free_datagram(sk, skb);
if (nlk->cb_running &&
atomic_read(&sk->sk_rmem_alloc) <= sk->sk_rcvbuf / 2) {
ret = netlink_dump(sk);
if (ret) {
sk->sk_err = -ret;
sk->sk_error_report(sk);
}
}
scm_recv(sock, msg, &scm, flags);
out:
netlink_rcv_wake(sk);
return err ? : copied;
}
static void netlink_data_ready(struct sock *sk)
{
BUG();
}
struct sock *
__netlink_kernel_create(struct net *net, int unit, struct module *module,
struct netlink_kernel_cfg *cfg)
{
struct socket *sock;
struct sock *sk;
struct netlink_sock *nlk;
struct listeners *listeners = NULL;
struct mutex *cb_mutex = cfg ? cfg->cb_mutex : NULL;
unsigned int groups;
BUG_ON(!nl_table);
if (unit < 0 || unit >= MAX_LINKS)
return NULL;
if (sock_create_lite(PF_NETLINK, SOCK_DGRAM, unit, &sock))
return NULL;
if (__netlink_create(net, sock, cb_mutex, unit, 1) < 0)
goto out_sock_release_nosk;
sk = sock->sk;
if (!cfg || cfg->groups < 32)
groups = 32;
else
groups = cfg->groups;
listeners = kzalloc(sizeof(*listeners) + NLGRPSZ(groups), GFP_KERNEL);
if (!listeners)
goto out_sock_release;
sk->sk_data_ready = netlink_data_ready;
if (cfg && cfg->input)
nlk_sk(sk)->netlink_rcv = cfg->input;
if (netlink_insert(sk, 0))
goto out_sock_release;
nlk = nlk_sk(sk);
nlk->flags |= NETLINK_F_KERNEL_SOCKET;
netlink_table_grab();
if (!nl_table[unit].registered) {
nl_table[unit].groups = groups;
rcu_assign_pointer(nl_table[unit].listeners, listeners);
nl_table[unit].cb_mutex = cb_mutex;
nl_table[unit].module = module;
if (cfg) {
nl_table[unit].bind = cfg->bind;
nl_table[unit].unbind = cfg->unbind;
nl_table[unit].flags = cfg->flags;
if (cfg->compare)
nl_table[unit].compare = cfg->compare;
}
nl_table[unit].registered = 1;
} else {
kfree(listeners);
nl_table[unit].registered++;
}
netlink_table_ungrab();
return sk;
out_sock_release:
kfree(listeners);
netlink_kernel_release(sk);
return NULL;
out_sock_release_nosk:
sock_release(sock);
return NULL;
}
void
netlink_kernel_release(struct sock *sk)
{
if (sk == NULL || sk->sk_socket == NULL)
return;
sock_release(sk->sk_socket);
}
int __netlink_change_ngroups(struct sock *sk, unsigned int groups)
{
struct listeners *new, *old;
struct netlink_table *tbl = &nl_table[sk->sk_protocol];
if (groups < 32)
groups = 32;
if (NLGRPSZ(tbl->groups) < NLGRPSZ(groups)) {
new = kzalloc(sizeof(*new) + NLGRPSZ(groups), GFP_ATOMIC);
if (!new)
return -ENOMEM;
old = nl_deref_protected(tbl->listeners);
memcpy(new->masks, old->masks, NLGRPSZ(tbl->groups));
rcu_assign_pointer(tbl->listeners, new);
kfree_rcu(old, rcu);
}
tbl->groups = groups;
return 0;
}
int netlink_change_ngroups(struct sock *sk, unsigned int groups)
{
int err;
netlink_table_grab();
err = __netlink_change_ngroups(sk, groups);
netlink_table_ungrab();
return err;
}
void __netlink_clear_multicast_users(struct sock *ksk, unsigned int group)
{
struct sock *sk;
struct netlink_table *tbl = &nl_table[ksk->sk_protocol];
sk_for_each_bound(sk, &tbl->mc_list)
netlink_update_socket_mc(nlk_sk(sk), group, 0);
}
struct nlmsghdr *
__nlmsg_put(struct sk_buff *skb, u32 portid, u32 seq, int type, int len, int flags)
{
struct nlmsghdr *nlh;
int size = nlmsg_msg_size(len);
nlh = (struct nlmsghdr *)skb_put(skb, NLMSG_ALIGN(size));
nlh->nlmsg_type = type;
nlh->nlmsg_len = size;
nlh->nlmsg_flags = flags;
nlh->nlmsg_pid = portid;
nlh->nlmsg_seq = seq;
if (!__builtin_constant_p(size) || NLMSG_ALIGN(size) - size != 0)
memset(nlmsg_data(nlh) + len, 0, NLMSG_ALIGN(size) - size);
return nlh;
}
static int netlink_dump(struct sock *sk)
{
struct netlink_sock *nlk = nlk_sk(sk);
struct netlink_callback *cb;
struct sk_buff *skb = NULL;
struct nlmsghdr *nlh;
struct module *module;
int len, err = -ENOBUFS;
int alloc_min_size;
int alloc_size;
mutex_lock(nlk->cb_mutex);
if (!nlk->cb_running) {
err = -EINVAL;
goto errout_skb;
}
if (atomic_read(&sk->sk_rmem_alloc) >= sk->sk_rcvbuf)
goto errout_skb;
cb = &nlk->cb;
alloc_min_size = max_t(int, cb->min_dump_alloc, NLMSG_GOODSIZE);
if (alloc_min_size < nlk->max_recvmsg_len) {
alloc_size = nlk->max_recvmsg_len;
skb = alloc_skb(alloc_size, GFP_KERNEL |
__GFP_NOWARN | __GFP_NORETRY);
}
if (!skb) {
alloc_size = alloc_min_size;
skb = alloc_skb(alloc_size, GFP_KERNEL);
}
if (!skb)
goto errout_skb;
skb_reserve(skb, skb_tailroom(skb) - alloc_size);
netlink_skb_set_owner_r(skb, sk);
len = cb->dump(skb, cb);
if (len > 0) {
mutex_unlock(nlk->cb_mutex);
if (sk_filter(sk, skb))
kfree_skb(skb);
else
__netlink_sendskb(sk, skb);
return 0;
}
nlh = nlmsg_put_answer(skb, cb, NLMSG_DONE, sizeof(len), NLM_F_MULTI);
if (!nlh)
goto errout_skb;
nl_dump_check_consistent(cb, nlh);
memcpy(nlmsg_data(nlh), &len, sizeof(len));
if (sk_filter(sk, skb))
kfree_skb(skb);
else
__netlink_sendskb(sk, skb);
if (cb->done)
cb->done(cb);
nlk->cb_running = false;
module = cb->module;
skb = cb->skb;
mutex_unlock(nlk->cb_mutex);
module_put(module);
consume_skb(skb);
return 0;
errout_skb:
mutex_unlock(nlk->cb_mutex);
kfree_skb(skb);
return err;
}
int __netlink_dump_start(struct sock *ssk, struct sk_buff *skb,
const struct nlmsghdr *nlh,
struct netlink_dump_control *control)
{
struct netlink_callback *cb;
struct sock *sk;
struct netlink_sock *nlk;
int ret;
atomic_inc(&skb->users);
sk = netlink_lookup(sock_net(ssk), ssk->sk_protocol, NETLINK_CB(skb).portid);
if (sk == NULL) {
ret = -ECONNREFUSED;
goto error_free;
}
nlk = nlk_sk(sk);
mutex_lock(nlk->cb_mutex);
if (nlk->cb_running) {
ret = -EBUSY;
goto error_unlock;
}
if (!try_module_get(control->module)) {
ret = -EPROTONOSUPPORT;
goto error_unlock;
}
cb = &nlk->cb;
memset(cb, 0, sizeof(*cb));
cb->start = control->start;
cb->dump = control->dump;
cb->done = control->done;
cb->nlh = nlh;
cb->data = control->data;
cb->module = control->module;
cb->min_dump_alloc = control->min_dump_alloc;
cb->skb = skb;
nlk->cb_running = true;
mutex_unlock(nlk->cb_mutex);
if (cb->start)
cb->start(cb);
ret = netlink_dump(sk);
sock_put(sk);
if (ret)
return ret;
return -EINTR;
error_unlock:
sock_put(sk);
mutex_unlock(nlk->cb_mutex);
error_free:
kfree_skb(skb);
return ret;
}
void netlink_ack(struct sk_buff *in_skb, struct nlmsghdr *nlh, int err)
{
struct sk_buff *skb;
struct nlmsghdr *rep;
struct nlmsgerr *errmsg;
size_t payload = sizeof(*errmsg);
struct netlink_sock *nlk = nlk_sk(NETLINK_CB(in_skb).sk);
if (!(nlk->flags & NETLINK_F_CAP_ACK) && err)
payload += nlmsg_len(nlh);
skb = nlmsg_new(payload, GFP_KERNEL);
if (!skb) {
struct sock *sk;
sk = netlink_lookup(sock_net(in_skb->sk),
in_skb->sk->sk_protocol,
NETLINK_CB(in_skb).portid);
if (sk) {
sk->sk_err = ENOBUFS;
sk->sk_error_report(sk);
sock_put(sk);
}
return;
}
rep = __nlmsg_put(skb, NETLINK_CB(in_skb).portid, nlh->nlmsg_seq,
NLMSG_ERROR, payload, 0);
errmsg = nlmsg_data(rep);
errmsg->error = err;
memcpy(&errmsg->msg, nlh, payload > sizeof(*errmsg) ? nlh->nlmsg_len : sizeof(*nlh));
netlink_unicast(in_skb->sk, skb, NETLINK_CB(in_skb).portid, MSG_DONTWAIT);
}
int netlink_rcv_skb(struct sk_buff *skb, int (*cb)(struct sk_buff *,
struct nlmsghdr *))
{
struct nlmsghdr *nlh;
int err;
while (skb->len >= nlmsg_total_size(0)) {
int msglen;
nlh = nlmsg_hdr(skb);
err = 0;
if (nlh->nlmsg_len < NLMSG_HDRLEN || skb->len < nlh->nlmsg_len)
return 0;
if (!(nlh->nlmsg_flags & NLM_F_REQUEST))
goto ack;
if (nlh->nlmsg_type < NLMSG_MIN_TYPE)
goto ack;
err = cb(skb, nlh);
if (err == -EINTR)
goto skip;
ack:
if (nlh->nlmsg_flags & NLM_F_ACK || err)
netlink_ack(skb, nlh, err);
skip:
msglen = NLMSG_ALIGN(nlh->nlmsg_len);
if (msglen > skb->len)
msglen = skb->len;
skb_pull(skb, msglen);
}
return 0;
}
int nlmsg_notify(struct sock *sk, struct sk_buff *skb, u32 portid,
unsigned int group, int report, gfp_t flags)
{
int err = 0;
if (group) {
int exclude_portid = 0;
if (report) {
atomic_inc(&skb->users);
exclude_portid = portid;
}
err = nlmsg_multicast(sk, skb, exclude_portid, group, flags);
}
if (report) {
int err2;
err2 = nlmsg_unicast(sk, skb, portid);
if (!err || err == -ESRCH)
err = err2;
}
return err;
}
static int netlink_walk_start(struct nl_seq_iter *iter)
{
int err;
err = rhashtable_walk_init(&nl_table[iter->link].hash, &iter->hti,
GFP_KERNEL);
if (err) {
iter->link = MAX_LINKS;
return err;
}
err = rhashtable_walk_start(&iter->hti);
return err == -EAGAIN ? 0 : err;
}
static void netlink_walk_stop(struct nl_seq_iter *iter)
{
rhashtable_walk_stop(&iter->hti);
rhashtable_walk_exit(&iter->hti);
}
static void *__netlink_seq_next(struct seq_file *seq)
{
struct nl_seq_iter *iter = seq->private;
struct netlink_sock *nlk;
do {
for (;;) {
int err;
nlk = rhashtable_walk_next(&iter->hti);
if (IS_ERR(nlk)) {
if (PTR_ERR(nlk) == -EAGAIN)
continue;
return nlk;
}
if (nlk)
break;
netlink_walk_stop(iter);
if (++iter->link >= MAX_LINKS)
return NULL;
err = netlink_walk_start(iter);
if (err)
return ERR_PTR(err);
}
} while (sock_net(&nlk->sk) != seq_file_net(seq));
return nlk;
}
static void *netlink_seq_start(struct seq_file *seq, loff_t *posp)
{
struct nl_seq_iter *iter = seq->private;
void *obj = SEQ_START_TOKEN;
loff_t pos;
int err;
iter->link = 0;
err = netlink_walk_start(iter);
if (err)
return ERR_PTR(err);
for (pos = *posp; pos && obj && !IS_ERR(obj); pos--)
obj = __netlink_seq_next(seq);
return obj;
}
static void *netlink_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return __netlink_seq_next(seq);
}
static void netlink_seq_stop(struct seq_file *seq, void *v)
{
struct nl_seq_iter *iter = seq->private;
if (iter->link >= MAX_LINKS)
return;
netlink_walk_stop(iter);
}
static int netlink_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN) {
seq_puts(seq,
"sk Eth Pid Groups "
"Rmem Wmem Dump Locks Drops Inode\n");
} else {
struct sock *s = v;
struct netlink_sock *nlk = nlk_sk(s);
seq_printf(seq, "%pK %-3d %-6u %08x %-8d %-8d %d %-8d %-8d %-8lu\n",
s,
s->sk_protocol,
nlk->portid,
nlk->groups ? (u32)nlk->groups[0] : 0,
sk_rmem_alloc_get(s),
sk_wmem_alloc_get(s),
nlk->cb_running,
atomic_read(&s->sk_refcnt),
atomic_read(&s->sk_drops),
sock_i_ino(s)
);
}
return 0;
}
static int netlink_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &netlink_seq_ops,
sizeof(struct nl_seq_iter));
}
int netlink_register_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&netlink_chain, nb);
}
int netlink_unregister_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&netlink_chain, nb);
}
static int __net_init netlink_net_init(struct net *net)
{
#ifdef CONFIG_PROC_FS
if (!proc_create("netlink", 0, net->proc_net, &netlink_seq_fops))
return -ENOMEM;
#endif
return 0;
}
static void __net_exit netlink_net_exit(struct net *net)
{
#ifdef CONFIG_PROC_FS
remove_proc_entry("netlink", net->proc_net);
#endif
}
static void __init netlink_add_usersock_entry(void)
{
struct listeners *listeners;
int groups = 32;
listeners = kzalloc(sizeof(*listeners) + NLGRPSZ(groups), GFP_KERNEL);
if (!listeners)
panic("netlink_add_usersock_entry: Cannot allocate listeners\n");
netlink_table_grab();
nl_table[NETLINK_USERSOCK].groups = groups;
rcu_assign_pointer(nl_table[NETLINK_USERSOCK].listeners, listeners);
nl_table[NETLINK_USERSOCK].module = THIS_MODULE;
nl_table[NETLINK_USERSOCK].registered = 1;
nl_table[NETLINK_USERSOCK].flags = NL_CFG_F_NONROOT_SEND;
netlink_table_ungrab();
}
static inline u32 netlink_hash(const void *data, u32 len, u32 seed)
{
const struct netlink_sock *nlk = data;
struct netlink_compare_arg arg;
netlink_compare_arg_init(&arg, sock_net(&nlk->sk), nlk->portid);
return jhash2((u32 *)&arg, netlink_compare_arg_len / sizeof(u32), seed);
}
static int __init netlink_proto_init(void)
{
int i;
int err = proto_register(&netlink_proto, 0);
if (err != 0)
goto out;
BUILD_BUG_ON(sizeof(struct netlink_skb_parms) > FIELD_SIZEOF(struct sk_buff, cb));
nl_table = kcalloc(MAX_LINKS, sizeof(*nl_table), GFP_KERNEL);
if (!nl_table)
goto panic;
for (i = 0; i < MAX_LINKS; i++) {
if (rhashtable_init(&nl_table[i].hash,
&netlink_rhashtable_params) < 0) {
while (--i > 0)
rhashtable_destroy(&nl_table[i].hash);
kfree(nl_table);
goto panic;
}
}
INIT_LIST_HEAD(&netlink_tap_all);
netlink_add_usersock_entry();
sock_register(&netlink_family_ops);
register_pernet_subsys(&netlink_net_ops);
rtnetlink_init();
out:
return err;
panic:
panic("netlink_init: Cannot allocate nl_table\n");
}
