void nfnl_lock(__u8 subsys_id)
{
mutex_lock(&table[subsys_id].mutex);
}
void nfnl_unlock(__u8 subsys_id)
{
mutex_unlock(&table[subsys_id].mutex);
}
int lockdep_nfnl_is_held(u8 subsys_id)
{
return lockdep_is_held(&table[subsys_id].mutex);
}
int nfnetlink_subsys_register(const struct nfnetlink_subsystem *n)
{
nfnl_lock(n->subsys_id);
if (table[n->subsys_id].subsys) {
nfnl_unlock(n->subsys_id);
return -EBUSY;
}
rcu_assign_pointer(table[n->subsys_id].subsys, n);
nfnl_unlock(n->subsys_id);
return 0;
}
int nfnetlink_subsys_unregister(const struct nfnetlink_subsystem *n)
{
nfnl_lock(n->subsys_id);
table[n->subsys_id].subsys = NULL;
nfnl_unlock(n->subsys_id);
synchronize_rcu();
return 0;
}
static inline const struct nfnetlink_subsystem *nfnetlink_get_subsys(u_int16_t type)
{
u_int8_t subsys_id = NFNL_SUBSYS_ID(type);
if (subsys_id >= NFNL_SUBSYS_COUNT)
return NULL;
return rcu_dereference(table[subsys_id].subsys);
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
struct sk_buff *nfnetlink_alloc_skb(struct net *net, unsigned int size,
u32 dst_portid, gfp_t gfp_mask)
{
return netlink_alloc_skb(net->nfnl, size, dst_portid, gfp_mask);
}
int nfnetlink_send(struct sk_buff *skb, struct net *net, u32 portid,
unsigned int group, int echo, gfp_t flags)
{
return nlmsg_notify(net->nfnl, skb, portid, group, echo, flags);
}
int nfnetlink_set_err(struct net *net, u32 portid, u32 group, int error)
{
return netlink_set_err(net->nfnl, portid, group, error);
}
int nfnetlink_unicast(struct sk_buff *skb, struct net *net, u32 portid,
int flags)
{
return netlink_unicast(net->nfnl, skb, portid, flags);
}
static int nfnetlink_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(skb->sk);
const struct nfnl_callback *nc;
const struct nfnetlink_subsystem *ss;
int type, err;
if (nlmsg_len(nlh) < sizeof(struct nfgenmsg))
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
int min_len = nlmsg_total_size(sizeof(struct nfgenmsg));
u_int8_t cb_id = NFNL_MSG_TYPE(nlh->nlmsg_type);
struct nlattr *cda[ss->cb[cb_id].attr_count + 1];
struct nlattr *attr = (void *)nlh + min_len;
int attrlen = nlh->nlmsg_len - min_len;
__u8 subsys_id = NFNL_SUBSYS_ID(type);
err = nla_parse(cda, ss->cb[cb_id].attr_count,
attr, attrlen, ss->cb[cb_id].policy);
if (err < 0) {
rcu_read_unlock();
return err;
}
if (nc->call_rcu) {
err = nc->call_rcu(net->nfnl, skb, nlh,
(const struct nlattr **)cda);
rcu_read_unlock();
} else {
rcu_read_unlock();
nfnl_lock(subsys_id);
if (rcu_dereference_protected(table[subsys_id].subsys,
lockdep_is_held(&table[subsys_id].mutex)) != ss ||
nfnetlink_find_client(type, ss) != nc)
err = -EAGAIN;
else if (nc->call)
err = nc->call(net->nfnl, skb, nlh,
(const struct nlattr **)cda);
else
err = -EINVAL;
nfnl_unlock(subsys_id);
}
if (err == -EAGAIN)
goto replay;
return err;
}
}
static void nfnetlink_rcv_batch(struct sk_buff *skb, struct nlmsghdr *nlh,
u_int16_t subsys_id)
{
struct sk_buff *nskb, *oskb = skb;
struct net *net = sock_net(skb->sk);
const struct nfnetlink_subsystem *ss;
const struct nfnl_callback *nc;
bool success = true, done = false;
int err;
if (subsys_id >= NFNL_SUBSYS_COUNT)
return netlink_ack(skb, nlh, -EINVAL);
replay:
nskb = netlink_skb_clone(oskb, GFP_KERNEL);
if (!nskb)
return netlink_ack(oskb, nlh, -ENOMEM);
nskb->sk = oskb->sk;
skb = nskb;
nfnl_lock(subsys_id);
ss = rcu_dereference_protected(table[subsys_id].subsys,
lockdep_is_held(&table[subsys_id].mutex));
if (!ss) {
#ifdef CONFIG_MODULES
nfnl_unlock(subsys_id);
request_module("nfnetlink-subsys-%d", subsys_id);
nfnl_lock(subsys_id);
ss = rcu_dereference_protected(table[subsys_id].subsys,
lockdep_is_held(&table[subsys_id].mutex));
if (!ss)
#endif
{
nfnl_unlock(subsys_id);
netlink_ack(skb, nlh, -EOPNOTSUPP);
return kfree_skb(nskb);
}
}
if (!ss->commit || !ss->abort) {
nfnl_unlock(subsys_id);
netlink_ack(skb, nlh, -EOPNOTSUPP);
return kfree_skb(skb);
}
while (skb->len >= nlmsg_total_size(0)) {
int msglen, type;
nlh = nlmsg_hdr(skb);
err = 0;
if (nlh->nlmsg_len < NLMSG_HDRLEN) {
err = -EINVAL;
goto ack;
}
if (!(nlh->nlmsg_flags & NLM_F_REQUEST)) {
err = -EINVAL;
goto ack;
}
type = nlh->nlmsg_type;
if (type == NFNL_MSG_BATCH_BEGIN) {
success = false;
goto done;
} else if (type == NFNL_MSG_BATCH_END) {
done = true;
goto done;
} else if (type < NLMSG_MIN_TYPE) {
err = -EINVAL;
goto ack;
}
if (NFNL_SUBSYS_ID(type) != subsys_id) {
err = -EINVAL;
goto ack;
}
nc = nfnetlink_find_client(type, ss);
if (!nc) {
err = -EINVAL;
goto ack;
}
{
int min_len = nlmsg_total_size(sizeof(struct nfgenmsg));
u_int8_t cb_id = NFNL_MSG_TYPE(nlh->nlmsg_type);
struct nlattr *cda[ss->cb[cb_id].attr_count + 1];
struct nlattr *attr = (void *)nlh + min_len;
int attrlen = nlh->nlmsg_len - min_len;
err = nla_parse(cda, ss->cb[cb_id].attr_count,
attr, attrlen, ss->cb[cb_id].policy);
if (err < 0)
goto ack;
if (nc->call_batch) {
err = nc->call_batch(net->nfnl, skb, nlh,
(const struct nlattr **)cda);
}
if (err == -EAGAIN) {
ss->abort(skb);
nfnl_unlock(subsys_id);
kfree_skb(nskb);
goto replay;
}
}
ack:
if (nlh->nlmsg_flags & NLM_F_ACK || err) {
netlink_ack(skb, nlh, err);
if (err)
success = false;
}
msglen = NLMSG_ALIGN(nlh->nlmsg_len);
if (msglen > skb->len)
msglen = skb->len;
skb_pull(skb, msglen);
}
done:
if (success && done)
ss->commit(skb);
else
ss->abort(skb);
nfnl_unlock(subsys_id);
kfree_skb(nskb);
}
static void nfnetlink_rcv(struct sk_buff *skb)
{
struct nlmsghdr *nlh = nlmsg_hdr(skb);
int msglen;
if (nlh->nlmsg_len < NLMSG_HDRLEN ||
skb->len < nlh->nlmsg_len)
return;
if (!netlink_net_capable(skb, CAP_NET_ADMIN)) {
netlink_ack(skb, nlh, -EPERM);
return;
}
if (nlh->nlmsg_type == NFNL_MSG_BATCH_BEGIN) {
struct nfgenmsg *nfgenmsg;
msglen = NLMSG_ALIGN(nlh->nlmsg_len);
if (msglen > skb->len)
msglen = skb->len;
if (nlh->nlmsg_len < NLMSG_HDRLEN ||
skb->len < NLMSG_HDRLEN + sizeof(struct nfgenmsg))
return;
nfgenmsg = nlmsg_data(nlh);
skb_pull(skb, msglen);
nfnetlink_rcv_batch(skb, nlh, nfgenmsg->res_id);
} else {
netlink_rcv_skb(skb, &nfnetlink_rcv_msg);
}
}
static int nfnetlink_bind(int group)
{
const struct nfnetlink_subsystem *ss;
int type = nfnl_group2type[group];
rcu_read_lock();
ss = nfnetlink_get_subsys(type);
rcu_read_unlock();
if (!ss)
request_module("nfnetlink-subsys-%d", type);
return 0;
}
static int __net_init nfnetlink_net_init(struct net *net)
{
struct sock *nfnl;
struct netlink_kernel_cfg cfg = {
.groups = NFNLGRP_MAX,
.input = nfnetlink_rcv,
#ifdef CONFIG_MODULES
.bind = nfnetlink_bind,
#endif
};
nfnl = netlink_kernel_create(net, NETLINK_NETFILTER, &cfg);
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
int i;
for (i=0; i<NFNL_SUBSYS_COUNT; i++)
mutex_init(&table[i].mutex);
pr_info("Netfilter messages via NETLINK v%s.\n", nfversion);
return register_pernet_subsys(&nfnetlink_net_ops);
}
static void __exit nfnetlink_exit(void)
{
pr_info("Removing netfilter NETLINK layer.\n");
unregister_pernet_subsys(&nfnetlink_net_ops);
}
