int ipv6_sock_ac_join(struct sock *sk, int ifindex, const struct in6_addr *addr)
{
struct ipv6_pinfo *np = inet6_sk(sk);
struct net_device *dev = NULL;
struct inet6_dev *idev;
struct ipv6_ac_socklist *pac;
struct net *net = sock_net(sk);
int ishost = !net->ipv6.devconf_all->forwarding;
int err = 0;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (ipv6_addr_is_multicast(addr))
return -EINVAL;
if (ipv6_chk_addr(net, addr, NULL, 0))
return -EINVAL;
pac = sock_kmalloc(sk, sizeof(struct ipv6_ac_socklist), GFP_KERNEL);
if (pac == NULL)
return -ENOMEM;
pac->acl_next = NULL;
pac->acl_addr = *addr;
rcu_read_lock();
if (ifindex == 0) {
struct rt6_info *rt;
rt = rt6_lookup(net, addr, NULL, 0, 0);
if (rt) {
dev = rt->dst.dev;
dst_release(&rt->dst);
} else if (ishost) {
err = -EADDRNOTAVAIL;
goto error;
} else {
dev = dev_get_by_flags_rcu(net, IFF_UP,
IFF_UP | IFF_LOOPBACK);
}
} else
dev = dev_get_by_index_rcu(net, ifindex);
if (dev == NULL) {
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
err = ipv6_dev_ac_inc(dev, addr);
if (!err) {
write_lock_bh(&ipv6_sk_ac_lock);
pac->acl_next = np->ipv6_ac_list;
np->ipv6_ac_list = pac;
write_unlock_bh(&ipv6_sk_ac_lock);
pac = NULL;
}
error:
rcu_read_unlock();
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
write_lock_bh(&ipv6_sk_ac_lock);
prev_pac = NULL;
for (pac = np->ipv6_ac_list; pac; pac = pac->acl_next) {
if ((ifindex == 0 || pac->acl_ifindex == ifindex) &&
ipv6_addr_equal(&pac->acl_addr, addr))
break;
prev_pac = pac;
}
if (!pac) {
write_unlock_bh(&ipv6_sk_ac_lock);
return -ENOENT;
}
if (prev_pac)
prev_pac->acl_next = pac->acl_next;
else
np->ipv6_ac_list = pac->acl_next;
write_unlock_bh(&ipv6_sk_ac_lock);
rcu_read_lock();
dev = dev_get_by_index_rcu(net, pac->acl_ifindex);
if (dev)
ipv6_dev_ac_dec(dev, &pac->acl_addr);
rcu_read_unlock();
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
write_lock_bh(&ipv6_sk_ac_lock);
pac = np->ipv6_ac_list;
np->ipv6_ac_list = NULL;
write_unlock_bh(&ipv6_sk_ac_lock);
prev_index = 0;
rcu_read_lock();
while (pac) {
struct ipv6_ac_socklist *next = pac->acl_next;
if (pac->acl_ifindex != prev_index) {
dev = dev_get_by_index_rcu(net, pac->acl_ifindex);
prev_index = pac->acl_ifindex;
}
if (dev)
ipv6_dev_ac_dec(dev, &pac->acl_addr);
sock_kfree_s(sk, pac, sizeof(*pac));
pac = next;
}
rcu_read_unlock();
}
static void aca_put(struct ifacaddr6 *ac)
{
if (atomic_dec_and_test(&ac->aca_refcnt)) {
in6_dev_put(ac->aca_idev);
dst_release(&ac->aca_rt->dst);
kfree(ac);
}
}
int ipv6_dev_ac_inc(struct net_device *dev, const struct in6_addr *addr)
{
struct ifacaddr6 *aca;
struct inet6_dev *idev;
struct rt6_info *rt;
int err;
idev = in6_dev_get(dev);
if (idev == NULL)
return -EINVAL;
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
aca = kzalloc(sizeof(struct ifacaddr6), GFP_ATOMIC);
if (aca == NULL) {
err = -ENOMEM;
goto out;
}
rt = addrconf_dst_alloc(idev, addr, true);
if (IS_ERR(rt)) {
kfree(aca);
err = PTR_ERR(rt);
goto out;
}
aca->aca_addr = *addr;
aca->aca_idev = idev;
aca->aca_rt = rt;
aca->aca_users = 1;
aca->aca_cstamp = aca->aca_tstamp = jiffies;
atomic_set(&aca->aca_refcnt, 2);
spin_lock_init(&aca->aca_lock);
aca->aca_next = idev->ac_list;
idev->ac_list = aca;
write_unlock_bh(&idev->lock);
ip6_ins_rt(rt);
addrconf_join_solict(dev, &aca->aca_addr);
aca_put(aca);
return 0;
out:
write_unlock_bh(&idev->lock);
in6_dev_put(idev);
return err;
}
int __ipv6_dev_ac_dec(struct inet6_dev *idev, const struct in6_addr *addr)
{
struct ifacaddr6 *aca, *prev_aca;
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
if (idev == NULL)
return -ENODEV;
return __ipv6_dev_ac_dec(idev, addr);
}
static int ipv6_chk_acast_dev(struct net_device *dev, const struct in6_addr *addr)
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
return 0;
}
int ipv6_chk_acast_addr(struct net *net, struct net_device *dev,
const struct in6_addr *addr)
{
int found = 0;
rcu_read_lock();
if (dev)
found = ipv6_chk_acast_dev(dev, addr);
else
for_each_netdev_rcu(net, dev)
if (ipv6_chk_acast_dev(dev, addr)) {
found = 1;
break;
}
rcu_read_unlock();
return found;
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
if (!proc_net_fops_create(net, "anycast6", S_IRUGO, &ac6_seq_fops))
return -ENOMEM;
return 0;
}
void ac6_proc_exit(struct net *net)
{
proc_net_remove(net, "anycast6");
}
