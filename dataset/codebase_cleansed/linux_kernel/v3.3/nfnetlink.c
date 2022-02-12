void nfnl_lock(void)
{
mutex_lock(&nfnl_mutex);
}
void nfnl_unlock(void)
{
mutex_unlock(&nfnl_mutex);
}
int nfnetlink_subsys_register(const struct nfnetlink_subsystem *n)
{
nfnl_lock();
if (subsys_table[n->subsys_id]) {
nfnl_unlock();
return -EBUSY;
}
rcu_assign_pointer(subsys_table[n->subsys_id], n);
nfnl_unlock();
return 0;
}
int nfnetlink_subsys_unregister(const struct nfnetlink_subsystem *n)
{
nfnl_lock();
subsys_table[n->subsys_id] = NULL;
nfnl_unlock();
synchronize_rcu();
return 0;
}
static inline const struct nfnetlink_subsystem *nfnetlink_get_subsys(u_int16_t type)
{
u_int8_t subsys_id = NFNL_SUBSYS_ID(type);
if (subsys_id >= NFNL_SUBSYS_COUNT)
return NULL;
return rcu_dereference(subsys_table[subsys_id]);
}
static inline const struct nfnl_callback *
nfnetlink_find_client(u_int16_t type, const struct nfnetlink_subsystem *ss)
{
u_int8_t cb_id = NFNL_MSG_TYPE(type);
if (cb_id >= ss->cb_count)
return NULL;
return &ss->cb[cb_id];
}
int nfnetlink_has_listeners(struct net *net, unsigned int group)
{
return netlink_has_listeners(net->nfnl, group);
}
int nfnetlink_send(struct sk_buff *skb, struct net *net, u32 pid,
unsigned group, int echo, gfp_t flags)
{
return nlmsg_notify(net->nfnl, skb, pid, group, echo, flags);
}
int nfnetlink_set_err(struct net *net, u32 pid, u32 group, int error)
{
return netlink_set_err(net->nfnl, pid, group, error);
}
int nfnetlink_unicast(struct sk_buff *skb, struct net *net, u_int32_t pid, int flags)
{
return netlink_unicast(net->nfnl, skb, pid, flags);
}
static int nfnetlink_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(skb->sk);
const struct nfnl_callback *nc;
const struct nfnetlink_subsystem *ss;
int type, err;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (nlh->nlmsg_len < NLMSG_LENGTH(sizeof(struct nfgenmsg)))
return 0;
type = nlh->nlmsg_type;
replay:
rcu_read_lock();
ss = nfnetlink_get_subsys(type);
if (!ss) {
#ifdef CONFIG_MODULES
rcu_read_unlock();
request_module("nfnetlink-subsys-%d", NFNL_SUBSYS_ID(type));
rcu_read_lock();
ss = nfnetlink_get_subsys(type);
if (!ss)
#endif
{
rcu_read_unlock();
return -EINVAL;
}
}
nc = nfnetlink_find_client(type, ss);
if (!nc) {
rcu_read_unlock();
return -EINVAL;
}
{
int min_len = NLMSG_SPACE(sizeof(struct nfgenmsg));
u_int8_t cb_id = NFNL_MSG_TYPE(nlh->nlmsg_type);
struct nlattr *cda[ss->cb[cb_id].attr_count + 1];
struct nlattr *attr = (void *)nlh + min_len;
int attrlen = nlh->nlmsg_len - min_len;
err = nla_parse(cda, ss->cb[cb_id].attr_count,
attr, attrlen, ss->cb[cb_id].policy);
if (err < 0)
return err;
if (nc->call_rcu) {
err = nc->call_rcu(net->nfnl, skb, nlh,
(const struct nlattr **)cda);
rcu_read_unlock();
} else {
rcu_read_unlock();
nfnl_lock();
if (rcu_dereference_protected(
subsys_table[NFNL_SUBSYS_ID(type)],
lockdep_is_held(&nfnl_mutex)) != ss ||
nfnetlink_find_client(type, ss) != nc)
err = -EAGAIN;
else
err = nc->call(net->nfnl, skb, nlh,
(const struct nlattr **)cda);
nfnl_unlock();
}
if (err == -EAGAIN)
goto replay;
return err;
}
}
static void nfnetlink_rcv(struct sk_buff *skb)
{
netlink_rcv_skb(skb, &nfnetlink_rcv_msg);
}
static int __net_init nfnetlink_net_init(struct net *net)
{
struct sock *nfnl;
nfnl = netlink_kernel_create(net, NETLINK_NETFILTER, NFNLGRP_MAX,
nfnetlink_rcv, NULL, THIS_MODULE);
if (!nfnl)
return -ENOMEM;
net->nfnl_stash = nfnl;
rcu_assign_pointer(net->nfnl, nfnl);
return 0;
}
static void __net_exit nfnetlink_net_exit_batch(struct list_head *net_exit_list)
{
struct net *net;
list_for_each_entry(net, net_exit_list, exit_list)
RCU_INIT_POINTER(net->nfnl, NULL);
synchronize_net();
list_for_each_entry(net, net_exit_list, exit_list)
netlink_kernel_release(net->nfnl_stash);
}
static int __init nfnetlink_init(void)
{
pr_info("Netfilter messages via NETLINK v%s.\n", nfversion);
return register_pernet_subsys(&nfnetlink_net_ops);
}
static void __exit nfnetlink_exit(void)
{
pr_info("Removing netfilter NETLINK layer.\n");
unregister_pernet_subsys(&nfnetlink_net_ops);
}
