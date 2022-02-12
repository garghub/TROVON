static inline unsigned int inet_addr_hash(struct net *net, __be32 addr)
{
u32 val = (__force u32) addr ^ hash_ptr(net, 8);
return ((val ^ (val >> 8) ^ (val >> 16) ^ (val >> 24)) &
(IN4_ADDR_HSIZE - 1));
}
static void inet_hash_insert(struct net *net, struct in_ifaddr *ifa)
{
unsigned int hash = inet_addr_hash(net, ifa->ifa_local);
spin_lock(&inet_addr_hash_lock);
hlist_add_head_rcu(&ifa->hash, &inet_addr_lst[hash]);
spin_unlock(&inet_addr_hash_lock);
}
static void inet_hash_remove(struct in_ifaddr *ifa)
{
spin_lock(&inet_addr_hash_lock);
hlist_del_init_rcu(&ifa->hash);
spin_unlock(&inet_addr_hash_lock);
}
struct net_device *__ip_dev_find(struct net *net, __be32 addr, bool devref)
{
unsigned int hash = inet_addr_hash(net, addr);
struct net_device *result = NULL;
struct in_ifaddr *ifa;
struct hlist_node *node;
rcu_read_lock();
hlist_for_each_entry_rcu(ifa, node, &inet_addr_lst[hash], hash) {
struct net_device *dev = ifa->ifa_dev->dev;
if (!net_eq(dev_net(dev), net))
continue;
if (ifa->ifa_local == addr) {
result = dev;
break;
}
}
if (!result) {
struct flowi4 fl4 = { .daddr = addr };
struct fib_result res = { 0 };
struct fib_table *local;
local = fib_get_table(net, RT_TABLE_LOCAL);
if (local &&
!fib_table_lookup(local, &fl4, &res, FIB_LOOKUP_NOREF) &&
res.type == RTN_LOCAL)
result = FIB_RES_DEV(res);
}
if (result && devref)
dev_hold(result);
rcu_read_unlock();
return result;
}
static inline void devinet_sysctl_register(struct in_device *idev)
{
}
static inline void devinet_sysctl_unregister(struct in_device *idev)
{
}
static struct in_ifaddr *inet_alloc_ifa(void)
{
return kzalloc(sizeof(struct in_ifaddr), GFP_KERNEL);
}
static void inet_rcu_free_ifa(struct rcu_head *head)
{
struct in_ifaddr *ifa = container_of(head, struct in_ifaddr, rcu_head);
if (ifa->ifa_dev)
in_dev_put(ifa->ifa_dev);
kfree(ifa);
}
static inline void inet_free_ifa(struct in_ifaddr *ifa)
{
call_rcu(&ifa->rcu_head, inet_rcu_free_ifa);
}
void in_dev_finish_destroy(struct in_device *idev)
{
struct net_device *dev = idev->dev;
WARN_ON(idev->ifa_list);
WARN_ON(idev->mc_list);
#ifdef NET_REFCNT_DEBUG
pr_debug("%s: %p=%s\n", __func__, idev, dev ? dev->name : "NIL");
#endif
dev_put(dev);
if (!idev->dead)
pr_err("Freeing alive in_device %p\n", idev);
else
kfree(idev);
}
static struct in_device *inetdev_init(struct net_device *dev)
{
struct in_device *in_dev;
ASSERT_RTNL();
in_dev = kzalloc(sizeof(*in_dev), GFP_KERNEL);
if (!in_dev)
goto out;
memcpy(&in_dev->cnf, dev_net(dev)->ipv4.devconf_dflt,
sizeof(in_dev->cnf));
in_dev->cnf.sysctl = NULL;
in_dev->dev = dev;
in_dev->arp_parms = neigh_parms_alloc(dev, &arp_tbl);
if (!in_dev->arp_parms)
goto out_kfree;
if (IPV4_DEVCONF(in_dev->cnf, FORWARDING))
dev_disable_lro(dev);
dev_hold(dev);
in_dev_hold(in_dev);
devinet_sysctl_register(in_dev);
ip_mc_init_dev(in_dev);
if (dev->flags & IFF_UP)
ip_mc_up(in_dev);
rcu_assign_pointer(dev->ip_ptr, in_dev);
out:
return in_dev;
out_kfree:
kfree(in_dev);
in_dev = NULL;
goto out;
}
static void in_dev_rcu_put(struct rcu_head *head)
{
struct in_device *idev = container_of(head, struct in_device, rcu_head);
in_dev_put(idev);
}
static void inetdev_destroy(struct in_device *in_dev)
{
struct in_ifaddr *ifa;
struct net_device *dev;
ASSERT_RTNL();
dev = in_dev->dev;
in_dev->dead = 1;
ip_mc_destroy_dev(in_dev);
while ((ifa = in_dev->ifa_list) != NULL) {
inet_del_ifa(in_dev, &in_dev->ifa_list, 0);
inet_free_ifa(ifa);
}
RCU_INIT_POINTER(dev->ip_ptr, NULL);
devinet_sysctl_unregister(in_dev);
neigh_parms_release(&arp_tbl, in_dev->arp_parms);
arp_ifdown(dev);
call_rcu(&in_dev->rcu_head, in_dev_rcu_put);
}
int inet_addr_onlink(struct in_device *in_dev, __be32 a, __be32 b)
{
rcu_read_lock();
for_primary_ifa(in_dev) {
if (inet_ifa_match(a, ifa)) {
if (!b || inet_ifa_match(b, ifa)) {
rcu_read_unlock();
return 1;
}
}
} endfor_ifa(in_dev);
rcu_read_unlock();
return 0;
}
static void __inet_del_ifa(struct in_device *in_dev, struct in_ifaddr **ifap,
int destroy, struct nlmsghdr *nlh, u32 pid)
{
struct in_ifaddr *promote = NULL;
struct in_ifaddr *ifa, *ifa1 = *ifap;
struct in_ifaddr *last_prim = in_dev->ifa_list;
struct in_ifaddr *prev_prom = NULL;
int do_promote = IN_DEV_PROMOTE_SECONDARIES(in_dev);
ASSERT_RTNL();
if (!(ifa1->ifa_flags & IFA_F_SECONDARY)) {
struct in_ifaddr **ifap1 = &ifa1->ifa_next;
while ((ifa = *ifap1) != NULL) {
if (!(ifa->ifa_flags & IFA_F_SECONDARY) &&
ifa1->ifa_scope <= ifa->ifa_scope)
last_prim = ifa;
if (!(ifa->ifa_flags & IFA_F_SECONDARY) ||
ifa1->ifa_mask != ifa->ifa_mask ||
!inet_ifa_match(ifa1->ifa_address, ifa)) {
ifap1 = &ifa->ifa_next;
prev_prom = ifa;
continue;
}
if (!do_promote) {
inet_hash_remove(ifa);
*ifap1 = ifa->ifa_next;
rtmsg_ifa(RTM_DELADDR, ifa, nlh, pid);
blocking_notifier_call_chain(&inetaddr_chain,
NETDEV_DOWN, ifa);
inet_free_ifa(ifa);
} else {
promote = ifa;
break;
}
}
}
for (ifa = promote; ifa; ifa = ifa->ifa_next) {
if (ifa1->ifa_mask == ifa->ifa_mask &&
inet_ifa_match(ifa1->ifa_address, ifa))
fib_del_ifaddr(ifa, ifa1);
}
*ifap = ifa1->ifa_next;
inet_hash_remove(ifa1);
rtmsg_ifa(RTM_DELADDR, ifa1, nlh, pid);
blocking_notifier_call_chain(&inetaddr_chain, NETDEV_DOWN, ifa1);
if (promote) {
struct in_ifaddr *next_sec = promote->ifa_next;
if (prev_prom) {
prev_prom->ifa_next = promote->ifa_next;
promote->ifa_next = last_prim->ifa_next;
last_prim->ifa_next = promote;
}
promote->ifa_flags &= ~IFA_F_SECONDARY;
rtmsg_ifa(RTM_NEWADDR, promote, nlh, pid);
blocking_notifier_call_chain(&inetaddr_chain,
NETDEV_UP, promote);
for (ifa = next_sec; ifa; ifa = ifa->ifa_next) {
if (ifa1->ifa_mask != ifa->ifa_mask ||
!inet_ifa_match(ifa1->ifa_address, ifa))
continue;
fib_add_ifaddr(ifa);
}
}
if (destroy)
inet_free_ifa(ifa1);
}
static void inet_del_ifa(struct in_device *in_dev, struct in_ifaddr **ifap,
int destroy)
{
__inet_del_ifa(in_dev, ifap, destroy, NULL, 0);
}
static int __inet_insert_ifa(struct in_ifaddr *ifa, struct nlmsghdr *nlh,
u32 pid)
{
struct in_device *in_dev = ifa->ifa_dev;
struct in_ifaddr *ifa1, **ifap, **last_primary;
ASSERT_RTNL();
if (!ifa->ifa_local) {
inet_free_ifa(ifa);
return 0;
}
ifa->ifa_flags &= ~IFA_F_SECONDARY;
last_primary = &in_dev->ifa_list;
for (ifap = &in_dev->ifa_list; (ifa1 = *ifap) != NULL;
ifap = &ifa1->ifa_next) {
if (!(ifa1->ifa_flags & IFA_F_SECONDARY) &&
ifa->ifa_scope <= ifa1->ifa_scope)
last_primary = &ifa1->ifa_next;
if (ifa1->ifa_mask == ifa->ifa_mask &&
inet_ifa_match(ifa1->ifa_address, ifa)) {
if (ifa1->ifa_local == ifa->ifa_local) {
inet_free_ifa(ifa);
return -EEXIST;
}
if (ifa1->ifa_scope != ifa->ifa_scope) {
inet_free_ifa(ifa);
return -EINVAL;
}
ifa->ifa_flags |= IFA_F_SECONDARY;
}
}
if (!(ifa->ifa_flags & IFA_F_SECONDARY)) {
net_srandom(ifa->ifa_local);
ifap = last_primary;
}
ifa->ifa_next = *ifap;
*ifap = ifa;
inet_hash_insert(dev_net(in_dev->dev), ifa);
rtmsg_ifa(RTM_NEWADDR, ifa, nlh, pid);
blocking_notifier_call_chain(&inetaddr_chain, NETDEV_UP, ifa);
return 0;
}
static int inet_insert_ifa(struct in_ifaddr *ifa)
{
return __inet_insert_ifa(ifa, NULL, 0);
}
static int inet_set_ifa(struct net_device *dev, struct in_ifaddr *ifa)
{
struct in_device *in_dev = __in_dev_get_rtnl(dev);
ASSERT_RTNL();
if (!in_dev) {
inet_free_ifa(ifa);
return -ENOBUFS;
}
ipv4_devconf_setall(in_dev);
if (ifa->ifa_dev != in_dev) {
WARN_ON(ifa->ifa_dev);
in_dev_hold(in_dev);
ifa->ifa_dev = in_dev;
}
if (ipv4_is_loopback(ifa->ifa_local))
ifa->ifa_scope = RT_SCOPE_HOST;
return inet_insert_ifa(ifa);
}
struct in_device *inetdev_by_index(struct net *net, int ifindex)
{
struct net_device *dev;
struct in_device *in_dev = NULL;
rcu_read_lock();
dev = dev_get_by_index_rcu(net, ifindex);
if (dev)
in_dev = rcu_dereference_rtnl(dev->ip_ptr);
rcu_read_unlock();
return in_dev;
}
struct in_ifaddr *inet_ifa_byprefix(struct in_device *in_dev, __be32 prefix,
__be32 mask)
{
ASSERT_RTNL();
for_primary_ifa(in_dev) {
if (ifa->ifa_mask == mask && inet_ifa_match(prefix, ifa))
return ifa;
} endfor_ifa(in_dev);
return NULL;
}
static int inet_rtm_deladdr(struct sk_buff *skb, struct nlmsghdr *nlh, void *arg)
{
struct net *net = sock_net(skb->sk);
struct nlattr *tb[IFA_MAX+1];
struct in_device *in_dev;
struct ifaddrmsg *ifm;
struct in_ifaddr *ifa, **ifap;
int err = -EINVAL;
ASSERT_RTNL();
err = nlmsg_parse(nlh, sizeof(*ifm), tb, IFA_MAX, ifa_ipv4_policy);
if (err < 0)
goto errout;
ifm = nlmsg_data(nlh);
in_dev = inetdev_by_index(net, ifm->ifa_index);
if (in_dev == NULL) {
err = -ENODEV;
goto errout;
}
for (ifap = &in_dev->ifa_list; (ifa = *ifap) != NULL;
ifap = &ifa->ifa_next) {
if (tb[IFA_LOCAL] &&
ifa->ifa_local != nla_get_be32(tb[IFA_LOCAL]))
continue;
if (tb[IFA_LABEL] && nla_strcmp(tb[IFA_LABEL], ifa->ifa_label))
continue;
if (tb[IFA_ADDRESS] &&
(ifm->ifa_prefixlen != ifa->ifa_prefixlen ||
!inet_ifa_match(nla_get_be32(tb[IFA_ADDRESS]), ifa)))
continue;
__inet_del_ifa(in_dev, ifap, 1, nlh, NETLINK_CB(skb).pid);
return 0;
}
err = -EADDRNOTAVAIL;
errout:
return err;
}
static struct in_ifaddr *rtm_to_ifaddr(struct net *net, struct nlmsghdr *nlh)
{
struct nlattr *tb[IFA_MAX+1];
struct in_ifaddr *ifa;
struct ifaddrmsg *ifm;
struct net_device *dev;
struct in_device *in_dev;
int err;
err = nlmsg_parse(nlh, sizeof(*ifm), tb, IFA_MAX, ifa_ipv4_policy);
if (err < 0)
goto errout;
ifm = nlmsg_data(nlh);
err = -EINVAL;
if (ifm->ifa_prefixlen > 32 || tb[IFA_LOCAL] == NULL)
goto errout;
dev = __dev_get_by_index(net, ifm->ifa_index);
err = -ENODEV;
if (dev == NULL)
goto errout;
in_dev = __in_dev_get_rtnl(dev);
err = -ENOBUFS;
if (in_dev == NULL)
goto errout;
ifa = inet_alloc_ifa();
if (ifa == NULL)
goto errout;
ipv4_devconf_setall(in_dev);
in_dev_hold(in_dev);
if (tb[IFA_ADDRESS] == NULL)
tb[IFA_ADDRESS] = tb[IFA_LOCAL];
INIT_HLIST_NODE(&ifa->hash);
ifa->ifa_prefixlen = ifm->ifa_prefixlen;
ifa->ifa_mask = inet_make_mask(ifm->ifa_prefixlen);
ifa->ifa_flags = ifm->ifa_flags;
ifa->ifa_scope = ifm->ifa_scope;
ifa->ifa_dev = in_dev;
ifa->ifa_local = nla_get_be32(tb[IFA_LOCAL]);
ifa->ifa_address = nla_get_be32(tb[IFA_ADDRESS]);
if (tb[IFA_BROADCAST])
ifa->ifa_broadcast = nla_get_be32(tb[IFA_BROADCAST]);
if (tb[IFA_LABEL])
nla_strlcpy(ifa->ifa_label, tb[IFA_LABEL], IFNAMSIZ);
else
memcpy(ifa->ifa_label, dev->name, IFNAMSIZ);
return ifa;
errout:
return ERR_PTR(err);
}
static int inet_rtm_newaddr(struct sk_buff *skb, struct nlmsghdr *nlh, void *arg)
{
struct net *net = sock_net(skb->sk);
struct in_ifaddr *ifa;
ASSERT_RTNL();
ifa = rtm_to_ifaddr(net, nlh);
if (IS_ERR(ifa))
return PTR_ERR(ifa);
return __inet_insert_ifa(ifa, nlh, NETLINK_CB(skb).pid);
}
static inline int inet_abc_len(__be32 addr)
{
int rc = -1;
if (ipv4_is_zeronet(addr))
rc = 0;
else {
__u32 haddr = ntohl(addr);
if (IN_CLASSA(haddr))
rc = 8;
else if (IN_CLASSB(haddr))
rc = 16;
else if (IN_CLASSC(haddr))
rc = 24;
}
return rc;
}
int devinet_ioctl(struct net *net, unsigned int cmd, void __user *arg)
{
struct ifreq ifr;
struct sockaddr_in sin_orig;
struct sockaddr_in *sin = (struct sockaddr_in *)&ifr.ifr_addr;
struct in_device *in_dev;
struct in_ifaddr **ifap = NULL;
struct in_ifaddr *ifa = NULL;
struct net_device *dev;
char *colon;
int ret = -EFAULT;
int tryaddrmatch = 0;
if (copy_from_user(&ifr, arg, sizeof(struct ifreq)))
goto out;
ifr.ifr_name[IFNAMSIZ - 1] = 0;
memcpy(&sin_orig, sin, sizeof(*sin));
colon = strchr(ifr.ifr_name, ':');
if (colon)
*colon = 0;
dev_load(net, ifr.ifr_name);
switch (cmd) {
case SIOCGIFADDR:
case SIOCGIFBRDADDR:
case SIOCGIFDSTADDR:
case SIOCGIFNETMASK:
tryaddrmatch = (sin_orig.sin_family == AF_INET);
memset(sin, 0, sizeof(*sin));
sin->sin_family = AF_INET;
break;
case SIOCSIFFLAGS:
ret = -EPERM;
if (!capable(CAP_NET_ADMIN))
goto out;
break;
case SIOCSIFADDR:
case SIOCSIFBRDADDR:
case SIOCSIFDSTADDR:
case SIOCSIFNETMASK:
ret = -EPERM;
if (!capable(CAP_NET_ADMIN))
goto out;
ret = -EINVAL;
if (sin->sin_family != AF_INET)
goto out;
break;
default:
ret = -EINVAL;
goto out;
}
rtnl_lock();
ret = -ENODEV;
dev = __dev_get_by_name(net, ifr.ifr_name);
if (!dev)
goto done;
if (colon)
*colon = ':';
in_dev = __in_dev_get_rtnl(dev);
if (in_dev) {
if (tryaddrmatch) {
for (ifap = &in_dev->ifa_list; (ifa = *ifap) != NULL;
ifap = &ifa->ifa_next) {
if (!strcmp(ifr.ifr_name, ifa->ifa_label) &&
sin_orig.sin_addr.s_addr ==
ifa->ifa_local) {
break;
}
}
}
if (!ifa) {
for (ifap = &in_dev->ifa_list; (ifa = *ifap) != NULL;
ifap = &ifa->ifa_next)
if (!strcmp(ifr.ifr_name, ifa->ifa_label))
break;
}
}
ret = -EADDRNOTAVAIL;
if (!ifa && cmd != SIOCSIFADDR && cmd != SIOCSIFFLAGS)
goto done;
switch (cmd) {
case SIOCGIFADDR:
sin->sin_addr.s_addr = ifa->ifa_local;
goto rarok;
case SIOCGIFBRDADDR:
sin->sin_addr.s_addr = ifa->ifa_broadcast;
goto rarok;
case SIOCGIFDSTADDR:
sin->sin_addr.s_addr = ifa->ifa_address;
goto rarok;
case SIOCGIFNETMASK:
sin->sin_addr.s_addr = ifa->ifa_mask;
goto rarok;
case SIOCSIFFLAGS:
if (colon) {
ret = -EADDRNOTAVAIL;
if (!ifa)
break;
ret = 0;
if (!(ifr.ifr_flags & IFF_UP))
inet_del_ifa(in_dev, ifap, 1);
break;
}
ret = dev_change_flags(dev, ifr.ifr_flags);
break;
case SIOCSIFADDR:
ret = -EINVAL;
if (inet_abc_len(sin->sin_addr.s_addr) < 0)
break;
if (!ifa) {
ret = -ENOBUFS;
ifa = inet_alloc_ifa();
INIT_HLIST_NODE(&ifa->hash);
if (!ifa)
break;
if (colon)
memcpy(ifa->ifa_label, ifr.ifr_name, IFNAMSIZ);
else
memcpy(ifa->ifa_label, dev->name, IFNAMSIZ);
} else {
ret = 0;
if (ifa->ifa_local == sin->sin_addr.s_addr)
break;
inet_del_ifa(in_dev, ifap, 0);
ifa->ifa_broadcast = 0;
ifa->ifa_scope = 0;
}
ifa->ifa_address = ifa->ifa_local = sin->sin_addr.s_addr;
if (!(dev->flags & IFF_POINTOPOINT)) {
ifa->ifa_prefixlen = inet_abc_len(ifa->ifa_address);
ifa->ifa_mask = inet_make_mask(ifa->ifa_prefixlen);
if ((dev->flags & IFF_BROADCAST) &&
ifa->ifa_prefixlen < 31)
ifa->ifa_broadcast = ifa->ifa_address |
~ifa->ifa_mask;
} else {
ifa->ifa_prefixlen = 32;
ifa->ifa_mask = inet_make_mask(32);
}
ret = inet_set_ifa(dev, ifa);
break;
case SIOCSIFBRDADDR:
ret = 0;
if (ifa->ifa_broadcast != sin->sin_addr.s_addr) {
inet_del_ifa(in_dev, ifap, 0);
ifa->ifa_broadcast = sin->sin_addr.s_addr;
inet_insert_ifa(ifa);
}
break;
case SIOCSIFDSTADDR:
ret = 0;
if (ifa->ifa_address == sin->sin_addr.s_addr)
break;
ret = -EINVAL;
if (inet_abc_len(sin->sin_addr.s_addr) < 0)
break;
ret = 0;
inet_del_ifa(in_dev, ifap, 0);
ifa->ifa_address = sin->sin_addr.s_addr;
inet_insert_ifa(ifa);
break;
case SIOCSIFNETMASK:
ret = -EINVAL;
if (bad_mask(sin->sin_addr.s_addr, 0))
break;
ret = 0;
if (ifa->ifa_mask != sin->sin_addr.s_addr) {
__be32 old_mask = ifa->ifa_mask;
inet_del_ifa(in_dev, ifap, 0);
ifa->ifa_mask = sin->sin_addr.s_addr;
ifa->ifa_prefixlen = inet_mask_len(ifa->ifa_mask);
if ((dev->flags & IFF_BROADCAST) &&
(ifa->ifa_prefixlen < 31) &&
(ifa->ifa_broadcast ==
(ifa->ifa_local|~old_mask))) {
ifa->ifa_broadcast = (ifa->ifa_local |
~sin->sin_addr.s_addr);
}
inet_insert_ifa(ifa);
}
break;
}
done:
rtnl_unlock();
out:
return ret;
rarok:
rtnl_unlock();
ret = copy_to_user(arg, &ifr, sizeof(struct ifreq)) ? -EFAULT : 0;
goto out;
}
static int inet_gifconf(struct net_device *dev, char __user *buf, int len)
{
struct in_device *in_dev = __in_dev_get_rtnl(dev);
struct in_ifaddr *ifa;
struct ifreq ifr;
int done = 0;
if (!in_dev)
goto out;
for (ifa = in_dev->ifa_list; ifa; ifa = ifa->ifa_next) {
if (!buf) {
done += sizeof(ifr);
continue;
}
if (len < (int) sizeof(ifr))
break;
memset(&ifr, 0, sizeof(struct ifreq));
if (ifa->ifa_label)
strcpy(ifr.ifr_name, ifa->ifa_label);
else
strcpy(ifr.ifr_name, dev->name);
(*(struct sockaddr_in *)&ifr.ifr_addr).sin_family = AF_INET;
(*(struct sockaddr_in *)&ifr.ifr_addr).sin_addr.s_addr =
ifa->ifa_local;
if (copy_to_user(buf, &ifr, sizeof(struct ifreq))) {
done = -EFAULT;
break;
}
buf += sizeof(struct ifreq);
len -= sizeof(struct ifreq);
done += sizeof(struct ifreq);
}
out:
return done;
}
__be32 inet_select_addr(const struct net_device *dev, __be32 dst, int scope)
{
__be32 addr = 0;
struct in_device *in_dev;
struct net *net = dev_net(dev);
rcu_read_lock();
in_dev = __in_dev_get_rcu(dev);
if (!in_dev)
goto no_in_dev;
for_primary_ifa(in_dev) {
if (ifa->ifa_scope > scope)
continue;
if (!dst || inet_ifa_match(dst, ifa)) {
addr = ifa->ifa_local;
break;
}
if (!addr)
addr = ifa->ifa_local;
} endfor_ifa(in_dev);
if (addr)
goto out_unlock;
no_in_dev:
for_each_netdev_rcu(net, dev) {
in_dev = __in_dev_get_rcu(dev);
if (!in_dev)
continue;
for_primary_ifa(in_dev) {
if (ifa->ifa_scope != RT_SCOPE_LINK &&
ifa->ifa_scope <= scope) {
addr = ifa->ifa_local;
goto out_unlock;
}
} endfor_ifa(in_dev);
}
out_unlock:
rcu_read_unlock();
return addr;
}
static __be32 confirm_addr_indev(struct in_device *in_dev, __be32 dst,
__be32 local, int scope)
{
int same = 0;
__be32 addr = 0;
for_ifa(in_dev) {
if (!addr &&
(local == ifa->ifa_local || !local) &&
ifa->ifa_scope <= scope) {
addr = ifa->ifa_local;
if (same)
break;
}
if (!same) {
same = (!local || inet_ifa_match(local, ifa)) &&
(!dst || inet_ifa_match(dst, ifa));
if (same && addr) {
if (local || !dst)
break;
if (inet_ifa_match(addr, ifa))
break;
if (ifa->ifa_scope <= scope) {
addr = ifa->ifa_local;
break;
}
same = 0;
}
}
} endfor_ifa(in_dev);
return same ? addr : 0;
}
__be32 inet_confirm_addr(struct in_device *in_dev,
__be32 dst, __be32 local, int scope)
{
__be32 addr = 0;
struct net_device *dev;
struct net *net;
if (scope != RT_SCOPE_LINK)
return confirm_addr_indev(in_dev, dst, local, scope);
net = dev_net(in_dev->dev);
rcu_read_lock();
for_each_netdev_rcu(net, dev) {
in_dev = __in_dev_get_rcu(dev);
if (in_dev) {
addr = confirm_addr_indev(in_dev, dst, local, scope);
if (addr)
break;
}
}
rcu_read_unlock();
return addr;
}
int register_inetaddr_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&inetaddr_chain, nb);
}
int unregister_inetaddr_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&inetaddr_chain, nb);
}
static void inetdev_changename(struct net_device *dev, struct in_device *in_dev)
{
struct in_ifaddr *ifa;
int named = 0;
for (ifa = in_dev->ifa_list; ifa; ifa = ifa->ifa_next) {
char old[IFNAMSIZ], *dot;
memcpy(old, ifa->ifa_label, IFNAMSIZ);
memcpy(ifa->ifa_label, dev->name, IFNAMSIZ);
if (named++ == 0)
goto skip;
dot = strchr(old, ':');
if (dot == NULL) {
sprintf(old, ":%d", named);
dot = old;
}
if (strlen(dot) + strlen(dev->name) < IFNAMSIZ)
strcat(ifa->ifa_label, dot);
else
strcpy(ifa->ifa_label + (IFNAMSIZ - strlen(dot) - 1), dot);
skip:
rtmsg_ifa(RTM_NEWADDR, ifa, NULL, 0);
}
}
static inline bool inetdev_valid_mtu(unsigned int mtu)
{
return mtu >= 68;
}
static void inetdev_send_gratuitous_arp(struct net_device *dev,
struct in_device *in_dev)
{
struct in_ifaddr *ifa;
for (ifa = in_dev->ifa_list; ifa;
ifa = ifa->ifa_next) {
arp_send(ARPOP_REQUEST, ETH_P_ARP,
ifa->ifa_local, dev,
ifa->ifa_local, NULL,
dev->dev_addr, NULL);
}
}
static int inetdev_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = ptr;
struct in_device *in_dev = __in_dev_get_rtnl(dev);
ASSERT_RTNL();
if (!in_dev) {
if (event == NETDEV_REGISTER) {
in_dev = inetdev_init(dev);
if (!in_dev)
return notifier_from_errno(-ENOMEM);
if (dev->flags & IFF_LOOPBACK) {
IN_DEV_CONF_SET(in_dev, NOXFRM, 1);
IN_DEV_CONF_SET(in_dev, NOPOLICY, 1);
}
} else if (event == NETDEV_CHANGEMTU) {
if (inetdev_valid_mtu(dev->mtu))
in_dev = inetdev_init(dev);
}
goto out;
}
switch (event) {
case NETDEV_REGISTER:
pr_debug("%s: bug\n", __func__);
RCU_INIT_POINTER(dev->ip_ptr, NULL);
break;
case NETDEV_UP:
if (!inetdev_valid_mtu(dev->mtu))
break;
if (dev->flags & IFF_LOOPBACK) {
struct in_ifaddr *ifa = inet_alloc_ifa();
if (ifa) {
INIT_HLIST_NODE(&ifa->hash);
ifa->ifa_local =
ifa->ifa_address = htonl(INADDR_LOOPBACK);
ifa->ifa_prefixlen = 8;
ifa->ifa_mask = inet_make_mask(8);
in_dev_hold(in_dev);
ifa->ifa_dev = in_dev;
ifa->ifa_scope = RT_SCOPE_HOST;
memcpy(ifa->ifa_label, dev->name, IFNAMSIZ);
inet_insert_ifa(ifa);
}
}
ip_mc_up(in_dev);
case NETDEV_CHANGEADDR:
if (!IN_DEV_ARP_NOTIFY(in_dev))
break;
case NETDEV_NOTIFY_PEERS:
inetdev_send_gratuitous_arp(dev, in_dev);
break;
case NETDEV_DOWN:
ip_mc_down(in_dev);
break;
case NETDEV_PRE_TYPE_CHANGE:
ip_mc_unmap(in_dev);
break;
case NETDEV_POST_TYPE_CHANGE:
ip_mc_remap(in_dev);
break;
case NETDEV_CHANGEMTU:
if (inetdev_valid_mtu(dev->mtu))
break;
case NETDEV_UNREGISTER:
inetdev_destroy(in_dev);
break;
case NETDEV_CHANGENAME:
inetdev_changename(dev, in_dev);
devinet_sysctl_unregister(in_dev);
devinet_sysctl_register(in_dev);
break;
}
out:
return NOTIFY_DONE;
}
static inline size_t inet_nlmsg_size(void)
{
return NLMSG_ALIGN(sizeof(struct ifaddrmsg))
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(IFNAMSIZ);
}
static int inet_fill_ifaddr(struct sk_buff *skb, struct in_ifaddr *ifa,
u32 pid, u32 seq, int event, unsigned int flags)
{
struct ifaddrmsg *ifm;
struct nlmsghdr *nlh;
nlh = nlmsg_put(skb, pid, seq, event, sizeof(*ifm), flags);
if (nlh == NULL)
return -EMSGSIZE;
ifm = nlmsg_data(nlh);
ifm->ifa_family = AF_INET;
ifm->ifa_prefixlen = ifa->ifa_prefixlen;
ifm->ifa_flags = ifa->ifa_flags|IFA_F_PERMANENT;
ifm->ifa_scope = ifa->ifa_scope;
ifm->ifa_index = ifa->ifa_dev->dev->ifindex;
if ((ifa->ifa_address &&
nla_put_be32(skb, IFA_ADDRESS, ifa->ifa_address)) ||
(ifa->ifa_local &&
nla_put_be32(skb, IFA_LOCAL, ifa->ifa_local)) ||
(ifa->ifa_broadcast &&
nla_put_be32(skb, IFA_BROADCAST, ifa->ifa_broadcast)) ||
(ifa->ifa_label[0] &&
nla_put_string(skb, IFA_LABEL, ifa->ifa_label)))
goto nla_put_failure;
return nlmsg_end(skb, nlh);
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static int inet_dump_ifaddr(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
int h, s_h;
int idx, s_idx;
int ip_idx, s_ip_idx;
struct net_device *dev;
struct in_device *in_dev;
struct in_ifaddr *ifa;
struct hlist_head *head;
struct hlist_node *node;
s_h = cb->args[0];
s_idx = idx = cb->args[1];
s_ip_idx = ip_idx = cb->args[2];
for (h = s_h; h < NETDEV_HASHENTRIES; h++, s_idx = 0) {
idx = 0;
head = &net->dev_index_head[h];
rcu_read_lock();
hlist_for_each_entry_rcu(dev, node, head, index_hlist) {
if (idx < s_idx)
goto cont;
if (h > s_h || idx > s_idx)
s_ip_idx = 0;
in_dev = __in_dev_get_rcu(dev);
if (!in_dev)
goto cont;
for (ifa = in_dev->ifa_list, ip_idx = 0; ifa;
ifa = ifa->ifa_next, ip_idx++) {
if (ip_idx < s_ip_idx)
continue;
if (inet_fill_ifaddr(skb, ifa,
NETLINK_CB(cb->skb).pid,
cb->nlh->nlmsg_seq,
RTM_NEWADDR, NLM_F_MULTI) <= 0) {
rcu_read_unlock();
goto done;
}
}
cont:
idx++;
}
rcu_read_unlock();
}
done:
cb->args[0] = h;
cb->args[1] = idx;
cb->args[2] = ip_idx;
return skb->len;
}
static void rtmsg_ifa(int event, struct in_ifaddr *ifa, struct nlmsghdr *nlh,
u32 pid)
{
struct sk_buff *skb;
u32 seq = nlh ? nlh->nlmsg_seq : 0;
int err = -ENOBUFS;
struct net *net;
net = dev_net(ifa->ifa_dev->dev);
skb = nlmsg_new(inet_nlmsg_size(), GFP_KERNEL);
if (skb == NULL)
goto errout;
err = inet_fill_ifaddr(skb, ifa, pid, seq, event, 0);
if (err < 0) {
WARN_ON(err == -EMSGSIZE);
kfree_skb(skb);
goto errout;
}
rtnl_notify(skb, net, pid, RTNLGRP_IPV4_IFADDR, nlh, GFP_KERNEL);
return;
errout:
if (err < 0)
rtnl_set_sk_err(net, RTNLGRP_IPV4_IFADDR, err);
}
static size_t inet_get_link_af_size(const struct net_device *dev)
{
struct in_device *in_dev = rcu_dereference_rtnl(dev->ip_ptr);
if (!in_dev)
return 0;
return nla_total_size(IPV4_DEVCONF_MAX * 4);
}
static int inet_fill_link_af(struct sk_buff *skb, const struct net_device *dev)
{
struct in_device *in_dev = rcu_dereference_rtnl(dev->ip_ptr);
struct nlattr *nla;
int i;
if (!in_dev)
return -ENODATA;
nla = nla_reserve(skb, IFLA_INET_CONF, IPV4_DEVCONF_MAX * 4);
if (nla == NULL)
return -EMSGSIZE;
for (i = 0; i < IPV4_DEVCONF_MAX; i++)
((u32 *) nla_data(nla))[i] = in_dev->cnf.data[i];
return 0;
}
static int inet_validate_link_af(const struct net_device *dev,
const struct nlattr *nla)
{
struct nlattr *a, *tb[IFLA_INET_MAX+1];
int err, rem;
if (dev && !__in_dev_get_rtnl(dev))
return -EAFNOSUPPORT;
err = nla_parse_nested(tb, IFLA_INET_MAX, nla, inet_af_policy);
if (err < 0)
return err;
if (tb[IFLA_INET_CONF]) {
nla_for_each_nested(a, tb[IFLA_INET_CONF], rem) {
int cfgid = nla_type(a);
if (nla_len(a) < 4)
return -EINVAL;
if (cfgid <= 0 || cfgid > IPV4_DEVCONF_MAX)
return -EINVAL;
}
}
return 0;
}
static int inet_set_link_af(struct net_device *dev, const struct nlattr *nla)
{
struct in_device *in_dev = __in_dev_get_rtnl(dev);
struct nlattr *a, *tb[IFLA_INET_MAX+1];
int rem;
if (!in_dev)
return -EAFNOSUPPORT;
if (nla_parse_nested(tb, IFLA_INET_MAX, nla, NULL) < 0)
BUG();
if (tb[IFLA_INET_CONF]) {
nla_for_each_nested(a, tb[IFLA_INET_CONF], rem)
ipv4_devconf_set(in_dev, nla_type(a), nla_get_u32(a));
}
return 0;
}
static void devinet_copy_dflt_conf(struct net *net, int i)
{
struct net_device *dev;
rcu_read_lock();
for_each_netdev_rcu(net, dev) {
struct in_device *in_dev;
in_dev = __in_dev_get_rcu(dev);
if (in_dev && !test_bit(i, in_dev->cnf.state))
in_dev->cnf.data[i] = net->ipv4.devconf_dflt->data[i];
}
rcu_read_unlock();
}
static void inet_forward_change(struct net *net)
{
struct net_device *dev;
int on = IPV4_DEVCONF_ALL(net, FORWARDING);
IPV4_DEVCONF_ALL(net, ACCEPT_REDIRECTS) = !on;
IPV4_DEVCONF_DFLT(net, FORWARDING) = on;
for_each_netdev(net, dev) {
struct in_device *in_dev;
if (on)
dev_disable_lro(dev);
rcu_read_lock();
in_dev = __in_dev_get_rcu(dev);
if (in_dev)
IN_DEV_CONF_SET(in_dev, FORWARDING, on);
rcu_read_unlock();
}
}
static int devinet_conf_proc(ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int old_value = *(int *)ctl->data;
int ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
int new_value = *(int *)ctl->data;
if (write) {
struct ipv4_devconf *cnf = ctl->extra1;
struct net *net = ctl->extra2;
int i = (int *)ctl->data - cnf->data;
set_bit(i, cnf->state);
if (cnf == net->ipv4.devconf_dflt)
devinet_copy_dflt_conf(net, i);
if (i == IPV4_DEVCONF_ACCEPT_LOCAL - 1 ||
i == IPV4_DEVCONF_ROUTE_LOCALNET - 1)
if ((new_value == 0) && (old_value != 0))
rt_cache_flush(net);
}
return ret;
}
static int devinet_sysctl_forward(ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int *valp = ctl->data;
int val = *valp;
loff_t pos = *ppos;
int ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
if (write && *valp != val) {
struct net *net = ctl->extra2;
if (valp != &IPV4_DEVCONF_DFLT(net, FORWARDING)) {
if (!rtnl_trylock()) {
*valp = val;
*ppos = pos;
return restart_syscall();
}
if (valp == &IPV4_DEVCONF_ALL(net, FORWARDING)) {
inet_forward_change(net);
} else if (*valp) {
struct ipv4_devconf *cnf = ctl->extra1;
struct in_device *idev =
container_of(cnf, struct in_device, cnf);
dev_disable_lro(idev->dev);
}
rtnl_unlock();
rt_cache_flush(net);
}
}
return ret;
}
static int ipv4_doint_and_flush(ctl_table *ctl, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int *valp = ctl->data;
int val = *valp;
int ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
struct net *net = ctl->extra2;
if (write && *valp != val)
rt_cache_flush(net);
return ret;
}
static int __devinet_sysctl_register(struct net *net, char *dev_name,
struct ipv4_devconf *p)
{
int i;
struct devinet_sysctl_table *t;
char path[sizeof("net/ipv4/conf/") + IFNAMSIZ];
t = kmemdup(&devinet_sysctl, sizeof(*t), GFP_KERNEL);
if (!t)
goto out;
for (i = 0; i < ARRAY_SIZE(t->devinet_vars) - 1; i++) {
t->devinet_vars[i].data += (char *)p - (char *)&ipv4_devconf;
t->devinet_vars[i].extra1 = p;
t->devinet_vars[i].extra2 = net;
}
snprintf(path, sizeof(path), "net/ipv4/conf/%s", dev_name);
t->sysctl_header = register_net_sysctl(net, path, t->devinet_vars);
if (!t->sysctl_header)
goto free;
p->sysctl = t;
return 0;
free:
kfree(t);
out:
return -ENOBUFS;
}
static void __devinet_sysctl_unregister(struct ipv4_devconf *cnf)
{
struct devinet_sysctl_table *t = cnf->sysctl;
if (t == NULL)
return;
cnf->sysctl = NULL;
unregister_net_sysctl_table(t->sysctl_header);
kfree(t);
}
static void devinet_sysctl_register(struct in_device *idev)
{
neigh_sysctl_register(idev->dev, idev->arp_parms, "ipv4", NULL);
__devinet_sysctl_register(dev_net(idev->dev), idev->dev->name,
&idev->cnf);
}
static void devinet_sysctl_unregister(struct in_device *idev)
{
__devinet_sysctl_unregister(&idev->cnf);
neigh_sysctl_unregister(idev->arp_parms);
}
static __net_init int devinet_init_net(struct net *net)
{
int err;
struct ipv4_devconf *all, *dflt;
#ifdef CONFIG_SYSCTL
struct ctl_table *tbl = ctl_forward_entry;
struct ctl_table_header *forw_hdr;
#endif
err = -ENOMEM;
all = &ipv4_devconf;
dflt = &ipv4_devconf_dflt;
if (!net_eq(net, &init_net)) {
all = kmemdup(all, sizeof(ipv4_devconf), GFP_KERNEL);
if (all == NULL)
goto err_alloc_all;
dflt = kmemdup(dflt, sizeof(ipv4_devconf_dflt), GFP_KERNEL);
if (dflt == NULL)
goto err_alloc_dflt;
#ifdef CONFIG_SYSCTL
tbl = kmemdup(tbl, sizeof(ctl_forward_entry), GFP_KERNEL);
if (tbl == NULL)
goto err_alloc_ctl;
tbl[0].data = &all->data[IPV4_DEVCONF_FORWARDING - 1];
tbl[0].extra1 = all;
tbl[0].extra2 = net;
#endif
}
#ifdef CONFIG_SYSCTL
err = __devinet_sysctl_register(net, "all", all);
if (err < 0)
goto err_reg_all;
err = __devinet_sysctl_register(net, "default", dflt);
if (err < 0)
goto err_reg_dflt;
err = -ENOMEM;
forw_hdr = register_net_sysctl(net, "net/ipv4", tbl);
if (forw_hdr == NULL)
goto err_reg_ctl;
net->ipv4.forw_hdr = forw_hdr;
#endif
net->ipv4.devconf_all = all;
net->ipv4.devconf_dflt = dflt;
return 0;
#ifdef CONFIG_SYSCTL
err_reg_ctl:
__devinet_sysctl_unregister(dflt);
err_reg_dflt:
__devinet_sysctl_unregister(all);
err_reg_all:
if (tbl != ctl_forward_entry)
kfree(tbl);
err_alloc_ctl:
#endif
if (dflt != &ipv4_devconf_dflt)
kfree(dflt);
err_alloc_dflt:
if (all != &ipv4_devconf)
kfree(all);
err_alloc_all:
return err;
}
static __net_exit void devinet_exit_net(struct net *net)
{
#ifdef CONFIG_SYSCTL
struct ctl_table *tbl;
tbl = net->ipv4.forw_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->ipv4.forw_hdr);
__devinet_sysctl_unregister(net->ipv4.devconf_dflt);
__devinet_sysctl_unregister(net->ipv4.devconf_all);
kfree(tbl);
#endif
kfree(net->ipv4.devconf_dflt);
kfree(net->ipv4.devconf_all);
}
void __init devinet_init(void)
{
int i;
for (i = 0; i < IN4_ADDR_HSIZE; i++)
INIT_HLIST_HEAD(&inet_addr_lst[i]);
register_pernet_subsys(&devinet_ops);
register_gifconf(PF_INET, inet_gifconf);
register_netdevice_notifier(&ip_netdev_notifier);
rtnl_af_register(&inet_af_ops);
rtnl_register(PF_INET, RTM_NEWADDR, inet_rtm_newaddr, NULL, NULL);
rtnl_register(PF_INET, RTM_DELADDR, inet_rtm_deladdr, NULL, NULL);
rtnl_register(PF_INET, RTM_GETADDR, NULL, inet_dump_ifaddr, NULL);
}
