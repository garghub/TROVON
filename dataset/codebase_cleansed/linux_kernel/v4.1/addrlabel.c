static inline
struct net *ip6addrlbl_net(const struct ip6addrlbl_entry *lbl)
{
return read_pnet(&lbl->lbl_net);
}
static inline void ip6addrlbl_free(struct ip6addrlbl_entry *p)
{
kfree(p);
}
static void ip6addrlbl_free_rcu(struct rcu_head *h)
{
ip6addrlbl_free(container_of(h, struct ip6addrlbl_entry, rcu));
}
static bool ip6addrlbl_hold(struct ip6addrlbl_entry *p)
{
return atomic_inc_not_zero(&p->refcnt);
}
static inline void ip6addrlbl_put(struct ip6addrlbl_entry *p)
{
if (atomic_dec_and_test(&p->refcnt))
call_rcu(&p->rcu, ip6addrlbl_free_rcu);
}
static bool __ip6addrlbl_match(struct net *net,
const struct ip6addrlbl_entry *p,
const struct in6_addr *addr,
int addrtype, int ifindex)
{
if (!net_eq(ip6addrlbl_net(p), net))
return false;
if (p->ifindex && p->ifindex != ifindex)
return false;
if (p->addrtype && p->addrtype != addrtype)
return false;
if (!ipv6_prefix_equal(addr, &p->prefix, p->prefixlen))
return false;
return true;
}
static struct ip6addrlbl_entry *__ipv6_addr_label(struct net *net,
const struct in6_addr *addr,
int type, int ifindex)
{
struct ip6addrlbl_entry *p;
hlist_for_each_entry_rcu(p, &ip6addrlbl_table.head, list) {
if (__ip6addrlbl_match(net, p, addr, type, ifindex))
return p;
}
return NULL;
}
u32 ipv6_addr_label(struct net *net,
const struct in6_addr *addr, int type, int ifindex)
{
u32 label;
struct ip6addrlbl_entry *p;
type &= IPV6_ADDR_MAPPED | IPV6_ADDR_COMPATv4 | IPV6_ADDR_LOOPBACK;
rcu_read_lock();
p = __ipv6_addr_label(net, addr, type, ifindex);
label = p ? p->label : IPV6_ADDR_LABEL_DEFAULT;
rcu_read_unlock();
ADDRLABEL(KERN_DEBUG "%s(addr=%pI6, type=%d, ifindex=%d) => %08x\n",
__func__, addr, type, ifindex, label);
return label;
}
static struct ip6addrlbl_entry *ip6addrlbl_alloc(struct net *net,
const struct in6_addr *prefix,
int prefixlen, int ifindex,
u32 label)
{
struct ip6addrlbl_entry *newp;
int addrtype;
ADDRLABEL(KERN_DEBUG "%s(prefix=%pI6, prefixlen=%d, ifindex=%d, label=%u)\n",
__func__, prefix, prefixlen, ifindex, (unsigned int)label);
addrtype = ipv6_addr_type(prefix) & (IPV6_ADDR_MAPPED | IPV6_ADDR_COMPATv4 | IPV6_ADDR_LOOPBACK);
switch (addrtype) {
case IPV6_ADDR_MAPPED:
if (prefixlen > 96)
return ERR_PTR(-EINVAL);
if (prefixlen < 96)
addrtype = 0;
break;
case IPV6_ADDR_COMPATv4:
if (prefixlen != 96)
addrtype = 0;
break;
case IPV6_ADDR_LOOPBACK:
if (prefixlen != 128)
addrtype = 0;
break;
}
newp = kmalloc(sizeof(*newp), GFP_KERNEL);
if (!newp)
return ERR_PTR(-ENOMEM);
ipv6_addr_prefix(&newp->prefix, prefix, prefixlen);
newp->prefixlen = prefixlen;
newp->ifindex = ifindex;
newp->addrtype = addrtype;
newp->label = label;
INIT_HLIST_NODE(&newp->list);
write_pnet(&newp->lbl_net, net);
atomic_set(&newp->refcnt, 1);
return newp;
}
static int __ip6addrlbl_add(struct ip6addrlbl_entry *newp, int replace)
{
struct hlist_node *n;
struct ip6addrlbl_entry *last = NULL, *p = NULL;
int ret = 0;
ADDRLABEL(KERN_DEBUG "%s(newp=%p, replace=%d)\n", __func__, newp,
replace);
hlist_for_each_entry_safe(p, n, &ip6addrlbl_table.head, list) {
if (p->prefixlen == newp->prefixlen &&
net_eq(ip6addrlbl_net(p), ip6addrlbl_net(newp)) &&
p->ifindex == newp->ifindex &&
ipv6_addr_equal(&p->prefix, &newp->prefix)) {
if (!replace) {
ret = -EEXIST;
goto out;
}
hlist_replace_rcu(&p->list, &newp->list);
ip6addrlbl_put(p);
goto out;
} else if ((p->prefixlen == newp->prefixlen && !p->ifindex) ||
(p->prefixlen < newp->prefixlen)) {
hlist_add_before_rcu(&newp->list, &p->list);
goto out;
}
last = p;
}
if (last)
hlist_add_behind_rcu(&newp->list, &last->list);
else
hlist_add_head_rcu(&newp->list, &ip6addrlbl_table.head);
out:
if (!ret)
ip6addrlbl_table.seq++;
return ret;
}
static int ip6addrlbl_add(struct net *net,
const struct in6_addr *prefix, int prefixlen,
int ifindex, u32 label, int replace)
{
struct ip6addrlbl_entry *newp;
int ret = 0;
ADDRLABEL(KERN_DEBUG "%s(prefix=%pI6, prefixlen=%d, ifindex=%d, label=%u, replace=%d)\n",
__func__, prefix, prefixlen, ifindex, (unsigned int)label,
replace);
newp = ip6addrlbl_alloc(net, prefix, prefixlen, ifindex, label);
if (IS_ERR(newp))
return PTR_ERR(newp);
spin_lock(&ip6addrlbl_table.lock);
ret = __ip6addrlbl_add(newp, replace);
spin_unlock(&ip6addrlbl_table.lock);
if (ret)
ip6addrlbl_free(newp);
return ret;
}
static int __ip6addrlbl_del(struct net *net,
const struct in6_addr *prefix, int prefixlen,
int ifindex)
{
struct ip6addrlbl_entry *p = NULL;
struct hlist_node *n;
int ret = -ESRCH;
ADDRLABEL(KERN_DEBUG "%s(prefix=%pI6, prefixlen=%d, ifindex=%d)\n",
__func__, prefix, prefixlen, ifindex);
hlist_for_each_entry_safe(p, n, &ip6addrlbl_table.head, list) {
if (p->prefixlen == prefixlen &&
net_eq(ip6addrlbl_net(p), net) &&
p->ifindex == ifindex &&
ipv6_addr_equal(&p->prefix, prefix)) {
hlist_del_rcu(&p->list);
ip6addrlbl_put(p);
ret = 0;
break;
}
}
return ret;
}
static int ip6addrlbl_del(struct net *net,
const struct in6_addr *prefix, int prefixlen,
int ifindex)
{
struct in6_addr prefix_buf;
int ret;
ADDRLABEL(KERN_DEBUG "%s(prefix=%pI6, prefixlen=%d, ifindex=%d)\n",
__func__, prefix, prefixlen, ifindex);
ipv6_addr_prefix(&prefix_buf, prefix, prefixlen);
spin_lock(&ip6addrlbl_table.lock);
ret = __ip6addrlbl_del(net, &prefix_buf, prefixlen, ifindex);
spin_unlock(&ip6addrlbl_table.lock);
return ret;
}
static int __net_init ip6addrlbl_net_init(struct net *net)
{
int err = 0;
int i;
ADDRLABEL(KERN_DEBUG "%s\n", __func__);
for (i = 0; i < ARRAY_SIZE(ip6addrlbl_init_table); i++) {
int ret = ip6addrlbl_add(net,
ip6addrlbl_init_table[i].prefix,
ip6addrlbl_init_table[i].prefixlen,
0,
ip6addrlbl_init_table[i].label, 0);
if (ret && (!err || err != -ENOMEM))
err = ret;
}
return err;
}
static void __net_exit ip6addrlbl_net_exit(struct net *net)
{
struct ip6addrlbl_entry *p = NULL;
struct hlist_node *n;
spin_lock(&ip6addrlbl_table.lock);
hlist_for_each_entry_safe(p, n, &ip6addrlbl_table.head, list) {
if (net_eq(ip6addrlbl_net(p), net)) {
hlist_del_rcu(&p->list);
ip6addrlbl_put(p);
}
}
spin_unlock(&ip6addrlbl_table.lock);
}
int __init ipv6_addr_label_init(void)
{
spin_lock_init(&ip6addrlbl_table.lock);
return register_pernet_subsys(&ipv6_addr_label_ops);
}
void ipv6_addr_label_cleanup(void)
{
unregister_pernet_subsys(&ipv6_addr_label_ops);
}
static int ip6addrlbl_newdel(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(skb->sk);
struct ifaddrlblmsg *ifal;
struct nlattr *tb[IFAL_MAX+1];
struct in6_addr *pfx;
u32 label;
int err = 0;
err = nlmsg_parse(nlh, sizeof(*ifal), tb, IFAL_MAX, ifal_policy);
if (err < 0)
return err;
ifal = nlmsg_data(nlh);
if (ifal->ifal_family != AF_INET6 ||
ifal->ifal_prefixlen > 128)
return -EINVAL;
if (!tb[IFAL_ADDRESS])
return -EINVAL;
pfx = nla_data(tb[IFAL_ADDRESS]);
if (!tb[IFAL_LABEL])
return -EINVAL;
label = nla_get_u32(tb[IFAL_LABEL]);
if (label == IPV6_ADDR_LABEL_DEFAULT)
return -EINVAL;
switch (nlh->nlmsg_type) {
case RTM_NEWADDRLABEL:
if (ifal->ifal_index &&
!__dev_get_by_index(net, ifal->ifal_index))
return -EINVAL;
err = ip6addrlbl_add(net, pfx, ifal->ifal_prefixlen,
ifal->ifal_index, label,
nlh->nlmsg_flags & NLM_F_REPLACE);
break;
case RTM_DELADDRLABEL:
err = ip6addrlbl_del(net, pfx, ifal->ifal_prefixlen,
ifal->ifal_index);
break;
default:
err = -EOPNOTSUPP;
}
return err;
}
static void ip6addrlbl_putmsg(struct nlmsghdr *nlh,
int prefixlen, int ifindex, u32 lseq)
{
struct ifaddrlblmsg *ifal = nlmsg_data(nlh);
ifal->ifal_family = AF_INET6;
ifal->ifal_prefixlen = prefixlen;
ifal->ifal_flags = 0;
ifal->ifal_index = ifindex;
ifal->ifal_seq = lseq;
}
static int ip6addrlbl_fill(struct sk_buff *skb,
struct ip6addrlbl_entry *p,
u32 lseq,
u32 portid, u32 seq, int event,
unsigned int flags)
{
struct nlmsghdr *nlh = nlmsg_put(skb, portid, seq, event,
sizeof(struct ifaddrlblmsg), flags);
if (!nlh)
return -EMSGSIZE;
ip6addrlbl_putmsg(nlh, p->prefixlen, p->ifindex, lseq);
if (nla_put_in6_addr(skb, IFAL_ADDRESS, &p->prefix) < 0 ||
nla_put_u32(skb, IFAL_LABEL, p->label) < 0) {
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
nlmsg_end(skb, nlh);
return 0;
}
static int ip6addrlbl_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
struct ip6addrlbl_entry *p;
int idx = 0, s_idx = cb->args[0];
int err;
rcu_read_lock();
hlist_for_each_entry_rcu(p, &ip6addrlbl_table.head, list) {
if (idx >= s_idx &&
net_eq(ip6addrlbl_net(p), net)) {
err = ip6addrlbl_fill(skb, p,
ip6addrlbl_table.seq,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWADDRLABEL,
NLM_F_MULTI);
if (err < 0)
break;
}
idx++;
}
rcu_read_unlock();
cb->args[0] = idx;
return skb->len;
}
static inline int ip6addrlbl_msgsize(void)
{
return NLMSG_ALIGN(sizeof(struct ifaddrlblmsg))
+ nla_total_size(16)
+ nla_total_size(4);
}
static int ip6addrlbl_get(struct sk_buff *in_skb, struct nlmsghdr *nlh)
{
struct net *net = sock_net(in_skb->sk);
struct ifaddrlblmsg *ifal;
struct nlattr *tb[IFAL_MAX+1];
struct in6_addr *addr;
u32 lseq;
int err = 0;
struct ip6addrlbl_entry *p;
struct sk_buff *skb;
err = nlmsg_parse(nlh, sizeof(*ifal), tb, IFAL_MAX, ifal_policy);
if (err < 0)
return err;
ifal = nlmsg_data(nlh);
if (ifal->ifal_family != AF_INET6 ||
ifal->ifal_prefixlen != 128)
return -EINVAL;
if (ifal->ifal_index &&
!__dev_get_by_index(net, ifal->ifal_index))
return -EINVAL;
if (!tb[IFAL_ADDRESS])
return -EINVAL;
addr = nla_data(tb[IFAL_ADDRESS]);
rcu_read_lock();
p = __ipv6_addr_label(net, addr, ipv6_addr_type(addr), ifal->ifal_index);
if (p && ip6addrlbl_hold(p))
p = NULL;
lseq = ip6addrlbl_table.seq;
rcu_read_unlock();
if (!p) {
err = -ESRCH;
goto out;
}
skb = nlmsg_new(ip6addrlbl_msgsize(), GFP_KERNEL);
if (!skb) {
ip6addrlbl_put(p);
return -ENOBUFS;
}
err = ip6addrlbl_fill(skb, p, lseq,
NETLINK_CB(in_skb).portid, nlh->nlmsg_seq,
RTM_NEWADDRLABEL, 0);
ip6addrlbl_put(p);
if (err < 0) {
WARN_ON(err == -EMSGSIZE);
kfree_skb(skb);
goto out;
}
err = rtnl_unicast(skb, net, NETLINK_CB(in_skb).portid);
out:
return err;
}
void __init ipv6_addr_label_rtnl_register(void)
{
__rtnl_register(PF_INET6, RTM_NEWADDRLABEL, ip6addrlbl_newdel,
NULL, NULL);
__rtnl_register(PF_INET6, RTM_DELADDRLABEL, ip6addrlbl_newdel,
NULL, NULL);
__rtnl_register(PF_INET6, RTM_GETADDRLABEL, ip6addrlbl_get,
ip6addrlbl_dump, NULL);
}
