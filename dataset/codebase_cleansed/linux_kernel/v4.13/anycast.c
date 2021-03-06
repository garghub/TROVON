int ipv6_sock_ac_join(struct sock *sk, int ifindex, const struct in6_addr *addr)
{
struct ipv6_pinfo *np = inet6_sk(sk);
struct net_device *dev = NULL;
struct inet6_dev *idev;
struct ipv6_ac_socklist *pac;
struct net *net = sock_net(sk);
int ishost = !net->ipv6.devconf_all->forwarding;
int err = 0;
ASSERT_RTNL();
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
if (ipv6_addr_is_multicast(addr))
return -EINVAL;
if (ipv6_chk_addr(net, addr, NULL, 0))
return -EINVAL;
pac = sock_kmalloc(sk, sizeof(struct ipv6_ac_socklist), GFP_KERNEL);
if (!pac)
return -ENOMEM;
pac->acl_next = NULL;
pac->acl_addr = *addr;
if (ifindex == 0) {
struct rt6_info *rt;
rt = rt6_lookup(net, addr, NULL, 0, 0);
if (rt) {
dev = rt->dst.dev;
ip6_rt_put(rt);
} else if (ishost) {
err = -EADDRNOTAVAIL;
goto error;
} else {
dev = __dev_get_by_flags(net, IFF_UP,
IFF_UP | IFF_LOOPBACK);
}
} else
dev = __dev_get_by_index(net, ifindex);
if (!dev) {
err = -ENODEV;
goto error;
}
idev = __in6_dev_get(dev);
if (!idev) {
if (ifindex)
err = -ENODEV;
else
err = -EADDRNOTAVAIL;
goto error;
}
ishost = !idev->cnf.forwarding;
pac->acl_ifindex = dev->ifindex;
if (!ipv6_chk_prefix(addr, dev)) {
if (ishost)
err = -EADDRNOTAVAIL;
if (err)
goto error;
}
err = __ipv6_dev_ac_inc(idev, addr);
if (!err) {
pac->acl_next = np->ipv6_ac_list;
np->ipv6_ac_list = pac;
pac = NULL;
}
error:
if (pac)
sock_kfree_s(sk, pac, sizeof(*pac));
return err;
}
int ipv6_sock_ac_drop(struct sock *sk, int ifindex, const struct in6_addr *addr)
{
struct ipv6_pinfo *np = inet6_sk(sk);
struct net_device *dev;
struct ipv6_ac_socklist *pac, *prev_pac;
struct net *net = sock_net(sk);
ASSERT_RTNL();
prev_pac = NULL;
for (pac = np->ipv6_ac_list; pac; pac = pac->acl_next) {
if ((ifindex == 0 || pac->acl_ifindex == ifindex) &&
ipv6_addr_equal(&pac->acl_addr, addr))
break;
prev_pac = pac;
}
if (!pac)
return -ENOENT;
if (prev_pac)
prev_pac->acl_next = pac->acl_next;
else
np->ipv6_ac_list = pac->acl_next;
dev = __dev_get_by_index(net, pac->acl_ifindex);
if (dev)
ipv6_dev_ac_dec(dev, &pac->acl_addr);
sock_kfree_s(sk, pac, sizeof(*pac));
return 0;
}
void ipv6_sock_ac_close(struct sock *sk)
{
struct ipv6_pinfo *np = inet6_sk(sk);
struct net_device *dev = NULL;
struct ipv6_ac_socklist *pac;
struct net *net = sock_net(sk);
int prev_index;
if (!np->ipv6_ac_list)
return;
rtnl_lock();
pac = np->ipv6_ac_list;
np->ipv6_ac_list = NULL;
prev_index = 0;
while (pac) {
struct ipv6_ac_socklist *next = pac->acl_next;
if (pac->acl_ifindex != prev_index) {
dev = __dev_get_by_index(net, pac->acl_ifindex);
prev_index = pac->acl_ifindex;
}
if (dev)
ipv6_dev_ac_dec(dev, &pac->acl_addr);
sock_kfree_s(sk, pac, sizeof(*pac));
pac = next;
}
rtnl_unlock();
}
static void aca_get(struct ifacaddr6 *aca)
{
refcount_inc(&aca->aca_refcnt);
}
static void aca_put(struct ifacaddr6 *ac)
{
if (refcount_dec_and_test(&ac->aca_refcnt)) {
in6_dev_put(ac->aca_idev);
dst_release(&ac->aca_rt->dst);
kfree(ac);
}
}
static struct ifacaddr6 *aca_alloc(struct rt6_info *rt,
const struct in6_addr *addr)
{
struct inet6_dev *idev = rt->rt6i_idev;
struct ifacaddr6 *aca;
aca = kzalloc(sizeof(*aca), GFP_ATOMIC);
if (!aca)
return NULL;
aca->aca_addr = *addr;
in6_dev_hold(idev);
aca->aca_idev = idev;
aca->aca_rt = rt;
aca->aca_users = 1;
aca->aca_cstamp = aca->aca_tstamp = jiffies;
refcount_set(&aca->aca_refcnt, 1);
return aca;
}
int __ipv6_dev_ac_inc(struct inet6_dev *idev, const struct in6_addr *addr)
{
struct ifacaddr6 *aca;
struct rt6_info *rt;
int err;
ASSERT_RTNL();
write_lock_bh(&idev->lock);
if (idev->dead) {
err = -ENODEV;
goto out;
}
for (aca = idev->ac_list; aca; aca = aca->aca_next) {
if (ipv6_addr_equal(&aca->aca_addr, addr)) {
aca->aca_users++;
err = 0;
goto out;
}
}
rt = addrconf_dst_alloc(idev, addr, true);
if (IS_ERR(rt)) {
err = PTR_ERR(rt);
goto out;
}
aca = aca_alloc(rt, addr);
if (!aca) {
ip6_rt_put(rt);
err = -ENOMEM;
goto out;
}
aca->aca_next = idev->ac_list;
idev->ac_list = aca;
aca_get(aca);
write_unlock_bh(&idev->lock);
ip6_ins_rt(rt);
addrconf_join_solict(idev->dev, &aca->aca_addr);
aca_put(aca);
return 0;
out:
write_unlock_bh(&idev->lock);
return err;
}
int __ipv6_dev_ac_dec(struct inet6_dev *idev, const struct in6_addr *addr)
{
struct ifacaddr6 *aca, *prev_aca;
ASSERT_RTNL();
write_lock_bh(&idev->lock);
prev_aca = NULL;
for (aca = idev->ac_list; aca; aca = aca->aca_next) {
if (ipv6_addr_equal(&aca->aca_addr, addr))
break;
prev_aca = aca;
}
if (!aca) {
write_unlock_bh(&idev->lock);
return -ENOENT;
}
if (--aca->aca_users > 0) {
write_unlock_bh(&idev->lock);
return 0;
}
if (prev_aca)
prev_aca->aca_next = aca->aca_next;
else
idev->ac_list = aca->aca_next;
write_unlock_bh(&idev->lock);
addrconf_leave_solict(idev, &aca->aca_addr);
dst_hold(&aca->aca_rt->dst);
ip6_del_rt(aca->aca_rt);
aca_put(aca);
return 0;
}
static int ipv6_dev_ac_dec(struct net_device *dev, const struct in6_addr *addr)
{
struct inet6_dev *idev = __in6_dev_get(dev);
if (!idev)
return -ENODEV;
return __ipv6_dev_ac_dec(idev, addr);
}
void ipv6_ac_destroy_dev(struct inet6_dev *idev)
{
struct ifacaddr6 *aca;
write_lock_bh(&idev->lock);
while ((aca = idev->ac_list) != NULL) {
idev->ac_list = aca->aca_next;
write_unlock_bh(&idev->lock);
addrconf_leave_solict(idev, &aca->aca_addr);
dst_hold(&aca->aca_rt->dst);
ip6_del_rt(aca->aca_rt);
aca_put(aca);
write_lock_bh(&idev->lock);
}
write_unlock_bh(&idev->lock);
}
static bool ipv6_chk_acast_dev(struct net_device *dev, const struct in6_addr *addr)
{
struct inet6_dev *idev;
struct ifacaddr6 *aca;
idev = __in6_dev_get(dev);
if (idev) {
read_lock_bh(&idev->lock);
for (aca = idev->ac_list; aca; aca = aca->aca_next)
if (ipv6_addr_equal(&aca->aca_addr, addr))
break;
read_unlock_bh(&idev->lock);
return aca != NULL;
}
return false;
}
bool ipv6_chk_acast_addr(struct net *net, struct net_device *dev,
const struct in6_addr *addr)
{
bool found = false;
rcu_read_lock();
if (dev)
found = ipv6_chk_acast_dev(dev, addr);
else
for_each_netdev_rcu(net, dev)
if (ipv6_chk_acast_dev(dev, addr)) {
found = true;
break;
}
rcu_read_unlock();
return found;
}
bool ipv6_chk_acast_addr_src(struct net *net, struct net_device *dev,
const struct in6_addr *addr)
{
return ipv6_chk_acast_addr(net,
(ipv6_addr_type(addr) & IPV6_ADDR_LINKLOCAL ?
dev : NULL),
addr);
}
static inline struct ifacaddr6 *ac6_get_first(struct seq_file *seq)
{
struct ifacaddr6 *im = NULL;
struct ac6_iter_state *state = ac6_seq_private(seq);
struct net *net = seq_file_net(seq);
state->idev = NULL;
for_each_netdev_rcu(net, state->dev) {
struct inet6_dev *idev;
idev = __in6_dev_get(state->dev);
if (!idev)
continue;
read_lock_bh(&idev->lock);
im = idev->ac_list;
if (im) {
state->idev = idev;
break;
}
read_unlock_bh(&idev->lock);
}
return im;
}
static struct ifacaddr6 *ac6_get_next(struct seq_file *seq, struct ifacaddr6 *im)
{
struct ac6_iter_state *state = ac6_seq_private(seq);
im = im->aca_next;
while (!im) {
if (likely(state->idev != NULL))
read_unlock_bh(&state->idev->lock);
state->dev = next_net_device_rcu(state->dev);
if (!state->dev) {
state->idev = NULL;
break;
}
state->idev = __in6_dev_get(state->dev);
if (!state->idev)
continue;
read_lock_bh(&state->idev->lock);
im = state->idev->ac_list;
}
return im;
}
static struct ifacaddr6 *ac6_get_idx(struct seq_file *seq, loff_t pos)
{
struct ifacaddr6 *im = ac6_get_first(seq);
if (im)
while (pos && (im = ac6_get_next(seq, im)) != NULL)
--pos;
return pos ? NULL : im;
}
static void *ac6_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(RCU)
{
rcu_read_lock();
return ac6_get_idx(seq, *pos);
}
static void *ac6_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ifacaddr6 *im = ac6_get_next(seq, v);
++*pos;
return im;
}
static void ac6_seq_stop(struct seq_file *seq, void *v)
__releases(RCU)
{
struct ac6_iter_state *state = ac6_seq_private(seq);
if (likely(state->idev != NULL)) {
read_unlock_bh(&state->idev->lock);
state->idev = NULL;
}
rcu_read_unlock();
}
static int ac6_seq_show(struct seq_file *seq, void *v)
{
struct ifacaddr6 *im = (struct ifacaddr6 *)v;
struct ac6_iter_state *state = ac6_seq_private(seq);
seq_printf(seq, "%-4d %-15s %pi6 %5d\n",
state->dev->ifindex, state->dev->name,
&im->aca_addr, im->aca_users);
return 0;
}
static int ac6_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &ac6_seq_ops,
sizeof(struct ac6_iter_state));
}
int __net_init ac6_proc_init(struct net *net)
{
if (!proc_create("anycast6", S_IRUGO, net->proc_net, &ac6_seq_fops))
return -ENOMEM;
return 0;
}
void ac6_proc_exit(struct net *net)
{
remove_proc_entry("anycast6", net->proc_net);
}
